// ============================================================================
// Clean-Room C++17 AArch64 FDE Shard 1/5 for libnuro.so
// Phân mảnh FDE AArch64 C++17 sạch 1/5 cho libnuro.so
// Covers FDE indices [0 .. 366] out of 1,835 total FDEs (.eh_frame_hdr @ 0x0b8c58)
// Bao phủ chỉ số FDE [0 .. 366] trên tổng số 1,835 FDE (.eh_frame_hdr @ 0x0b8c58)
// ============================================================================
#include "nuro_core.h"

namespace nuro {

// FDE #0000 | PC: 0x0131b0 | FDE: 0x0bd5a0 | Size: 164 bytes
// Hàm FDE #0000 | Địa chỉ PC: 0x0131b0 | Địa chỉ FDE: 0x0bd5a0 | Kích thước: 164 bytes
//   0x0131b0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0131b4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0131b8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0131bc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0000_0x0131b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0131b0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bd5a0ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #0001 | PC: 0x013254 | FDE: 0x0bdf88 | Size: 68 bytes
// Hàm FDE #0001 | Địa chỉ PC: 0x013254 | Địa chỉ FDE: 0x0bdf88 | Kích thước: 68 bytes
//   0x013254: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x013258: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01325c: 910043FD  add      x29, sp, #0x10
//   0x013260: B00006D3  adrp     x19, #0xec000
static inline uint64_t fde_func_0001_0x013254(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x013254ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bdf88ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0002 | PC: 0x013298 | FDE: 0x0beed8 | Size: 256 bytes
// Hàm FDE #0002 | Địa chỉ PC: 0x013298 | Địa chỉ FDE: 0x0beed8 | Kích thước: 256 bytes
//   0x013298: D10303FF  sub      sp, sp, #0xc0
//   0x01329c: F9004BF5  str      x21, [sp, #0x90]
//   0x0132a0: A90A4FF4  stp      x20, x19, [sp, #0xa0]
//   0x0132a4: A90B7BFD  stp      x29, x30, [sp, #0xb0]
static inline uint64_t fde_func_0002_0x013298(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x013298ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf9004bf5ULL) ^ 0x0beed8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0003 | PC: 0x013490 | FDE: 0x0bfef8 | Size: 164 bytes
// Hàm FDE #0003 | Địa chỉ PC: 0x013490 | Địa chỉ FDE: 0x0bfef8 | Kích thước: 164 bytes
//   0x013490: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x013494: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x013498: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x01349c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0003_0x013490(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x013490ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bfef8ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #0004 | PC: 0x013534 | FDE: 0x0c0fb8 | Size: 52 bytes
// Hàm FDE #0004 | Địa chỉ PC: 0x013534 | Địa chỉ FDE: 0x0c0fb8 | Kích thước: 52 bytes
//   0x013534: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x013538: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01353c: 910043FD  add      x29, sp, #0x10
//   0x013540: B00006D3  adrp     x19, #0xec000
static inline uint64_t fde_func_0004_0x013534(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x013534ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c0fb8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0005 | PC: 0x013568 | FDE: 0x0c0fd8 | Size: 52 bytes
// Hàm FDE #0005 | Địa chỉ PC: 0x013568 | Địa chỉ FDE: 0x0c0fd8 | Kích thước: 52 bytes
//   0x013568: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01356c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x013570: 910043FD  add      x29, sp, #0x10
//   0x013574: B00006D3  adrp     x19, #0xec000
static inline uint64_t fde_func_0005_0x013568(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x013568ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c0fd8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0006 | PC: 0x01359c | FDE: 0x0c1328 | Size: 64 bytes
// Hàm FDE #0006 | Địa chỉ PC: 0x01359c | Địa chỉ FDE: 0x0c1328 | Kích thước: 64 bytes
//   0x01359c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0135a0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0135a4: 910043FD  add      x29, sp, #0x10
//   0x0135a8: B00006D3  adrp     x19, #0xec000
static inline uint64_t fde_func_0006_0x01359c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01359cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c1328ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0007 | PC: 0x0135dc | FDE: 0x0c1348 | Size: 64 bytes
// Hàm FDE #0007 | Địa chỉ PC: 0x0135dc | Địa chỉ FDE: 0x0c1348 | Kích thước: 64 bytes
//   0x0135dc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0135e0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0135e4: 910043FD  add      x29, sp, #0x10
//   0x0135e8: B00006D3  adrp     x19, #0xec000
static inline uint64_t fde_func_0007_0x0135dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0135dcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c1348ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0008 | PC: 0x01361c | FDE: 0x0c1560 | Size: 64 bytes
// Hàm FDE #0008 | Địa chỉ PC: 0x01361c | Địa chỉ FDE: 0x0c1560 | Kích thước: 64 bytes
//   0x01361c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x013620: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x013624: 910043FD  add      x29, sp, #0x10
//   0x013628: B00006D3  adrp     x19, #0xec000
static inline uint64_t fde_func_0008_0x01361c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01361cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c1560ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0009 | PC: 0x01365c | FDE: 0x0c1580 | Size: 64 bytes
// Hàm FDE #0009 | Địa chỉ PC: 0x01365c | Địa chỉ FDE: 0x0c1580 | Kích thước: 64 bytes
//   0x01365c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x013660: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x013664: 910043FD  add      x29, sp, #0x10
//   0x013668: B00006D3  adrp     x19, #0xec000
static inline uint64_t fde_func_0009_0x01365c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01365cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c1580ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0010 | PC: 0x01369c | FDE: 0x0c1658 | Size: 64 bytes
// Hàm FDE #0010 | Địa chỉ PC: 0x01369c | Địa chỉ FDE: 0x0c1658 | Kích thước: 64 bytes
//   0x01369c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0136a0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0136a4: 910043FD  add      x29, sp, #0x10
//   0x0136a8: B00006D3  adrp     x19, #0xec000
static inline uint64_t fde_func_0010_0x01369c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01369cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c1658ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0011 | PC: 0x0136dc | FDE: 0x0c1738 | Size: 64 bytes
// Hàm FDE #0011 | Địa chỉ PC: 0x0136dc | Địa chỉ FDE: 0x0c1738 | Kích thước: 64 bytes
//   0x0136dc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0136e0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0136e4: 910043FD  add      x29, sp, #0x10
//   0x0136e8: B00006D3  adrp     x19, #0xec000
static inline uint64_t fde_func_0011_0x0136dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0136dcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c1738ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0012 | PC: 0x01371c | FDE: 0x0c22d8 | Size: 52 bytes
// Hàm FDE #0012 | Địa chỉ PC: 0x01371c | Địa chỉ FDE: 0x0c22d8 | Kích thước: 52 bytes
//   0x01371c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x013720: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x013724: 910043FD  add      x29, sp, #0x10
//   0x013728: B00006D3  adrp     x19, #0xec000
static inline uint64_t fde_func_0012_0x01371c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01371cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c22d8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0013 | PC: 0x013750 | FDE: 0x0c22f8 | Size: 52 bytes
// Hàm FDE #0013 | Địa chỉ PC: 0x013750 | Địa chỉ FDE: 0x0c22f8 | Kích thước: 52 bytes
//   0x013750: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x013754: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x013758: 910043FD  add      x29, sp, #0x10
//   0x01375c: B00006D3  adrp     x19, #0xec000
static inline uint64_t fde_func_0013_0x013750(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x013750ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c22f8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0014 | PC: 0x013784 | FDE: 0x0c2660 | Size: 64 bytes
// Hàm FDE #0014 | Địa chỉ PC: 0x013784 | Địa chỉ FDE: 0x0c2660 | Kích thước: 64 bytes
//   0x013784: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x013788: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01378c: 910043FD  add      x29, sp, #0x10
//   0x013790: B00006D3  adrp     x19, #0xec000
static inline uint64_t fde_func_0014_0x013784(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x013784ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c2660ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0015 | PC: 0x0137c4 | FDE: 0x0c2680 | Size: 64 bytes
// Hàm FDE #0015 | Địa chỉ PC: 0x0137c4 | Địa chỉ FDE: 0x0c2680 | Kích thước: 64 bytes
//   0x0137c4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0137c8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0137cc: 910043FD  add      x29, sp, #0x10
//   0x0137d0: B00006D3  adrp     x19, #0xec000
static inline uint64_t fde_func_0015_0x0137c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0137c4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c2680ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0016 | PC: 0x013804 | FDE: 0x0c2c20 | Size: 164 bytes
// Hàm FDE #0016 | Địa chỉ PC: 0x013804 | Địa chỉ FDE: 0x0c2c20 | Kích thước: 164 bytes
//   0x013804: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x013808: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x01380c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x013810: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0016_0x013804(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x013804ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c2c20ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #0017 | PC: 0x0138a8 | FDE: 0x0c3e80 | Size: 68 bytes
// Hàm FDE #0017 | Địa chỉ PC: 0x0138a8 | Địa chỉ FDE: 0x0c3e80 | Kích thước: 68 bytes
//   0x0138a8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0138ac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0138b0: 910043FD  add      x29, sp, #0x10
//   0x0138b4: B00006D3  adrp     x19, #0xec000
static inline uint64_t fde_func_0017_0x0138a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0138a8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c3e80ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0018 | PC: 0x0138ec | FDE: 0x0c55b0 | Size: 68 bytes
// Hàm FDE #0018 | Địa chỉ PC: 0x0138ec | Địa chỉ FDE: 0x0c55b0 | Kích thước: 68 bytes
//   0x0138ec: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0138f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0138f4: 910043FD  add      x29, sp, #0x10
//   0x0138f8: B00006D3  adrp     x19, #0xec000
static inline uint64_t fde_func_0018_0x0138ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0138ecULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c55b0ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0019 | PC: 0x013930 | FDE: 0x0c73e8 | Size: 232 bytes
// Hàm FDE #0019 | Địa chỉ PC: 0x013930 | Địa chỉ FDE: 0x0c73e8 | Kích thước: 232 bytes
//   0x013930: D101C3FF  sub      sp, sp, #0x70
//   0x013934: F90023F5  str      x21, [sp, #0x40]
//   0x013938: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x01393c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0019_0x013930(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x013930ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c73e8ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0020 | PC: 0x013a18 | FDE: 0x0c70a8 | Size: 72 bytes
// Hàm FDE #0020 | Địa chỉ PC: 0x013a18 | Địa chỉ FDE: 0x0c70a8 | Kích thước: 72 bytes
//   0x013a18: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x013a1c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x013a20: 910043FD  add      x29, sp, #0x10
//   0x013a24: B00006D3  adrp     x19, #0xec000
static inline uint64_t fde_func_0020_0x013a18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x013a18ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c70a8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0021 | PC: 0x013a60 | FDE: 0x0c7438 | Size: 232 bytes
// Hàm FDE #0021 | Địa chỉ PC: 0x013a60 | Địa chỉ FDE: 0x0c7438 | Kích thước: 232 bytes
//   0x013a60: D101C3FF  sub      sp, sp, #0x70
//   0x013a64: F90023F5  str      x21, [sp, #0x40]
//   0x013a68: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x013a6c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0021_0x013a60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x013a60ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c7438ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0022 | PC: 0x013b48 | FDE: 0x0c70e8 | Size: 72 bytes
// Hàm FDE #0022 | Địa chỉ PC: 0x013b48 | Địa chỉ FDE: 0x0c70e8 | Kích thước: 72 bytes
//   0x013b48: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x013b4c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x013b50: 910043FD  add      x29, sp, #0x10
//   0x013b54: B00006D3  adrp     x19, #0xec000
static inline uint64_t fde_func_0022_0x013b48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x013b48ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c70e8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0023 | PC: 0x013b90 | FDE: 0x0c7488 | Size: 232 bytes
// Hàm FDE #0023 | Địa chỉ PC: 0x013b90 | Địa chỉ FDE: 0x0c7488 | Kích thước: 232 bytes
//   0x013b90: D101C3FF  sub      sp, sp, #0x70
//   0x013b94: F90023F5  str      x21, [sp, #0x40]
//   0x013b98: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x013b9c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0023_0x013b90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x013b90ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c7488ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0024 | PC: 0x013c78 | FDE: 0x0c7128 | Size: 72 bytes
// Hàm FDE #0024 | Địa chỉ PC: 0x013c78 | Địa chỉ FDE: 0x0c7128 | Kích thước: 72 bytes
//   0x013c78: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x013c7c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x013c80: 910043FD  add      x29, sp, #0x10
//   0x013c84: B00006D3  adrp     x19, #0xec000
static inline uint64_t fde_func_0024_0x013c78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x013c78ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7128ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0025 | PC: 0x013cc0 | FDE: 0x0c74d8 | Size: 232 bytes
// Hàm FDE #0025 | Địa chỉ PC: 0x013cc0 | Địa chỉ FDE: 0x0c74d8 | Kích thước: 232 bytes
//   0x013cc0: D101C3FF  sub      sp, sp, #0x70
//   0x013cc4: F90023F5  str      x21, [sp, #0x40]
//   0x013cc8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x013ccc: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0025_0x013cc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x013cc0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c74d8ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0026 | PC: 0x013da8 | FDE: 0x0c7168 | Size: 72 bytes
// Hàm FDE #0026 | Địa chỉ PC: 0x013da8 | Địa chỉ FDE: 0x0c7168 | Kích thước: 72 bytes
//   0x013da8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x013dac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x013db0: 910043FD  add      x29, sp, #0x10
//   0x013db4: B00006D3  adrp     x19, #0xec000
static inline uint64_t fde_func_0026_0x013da8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x013da8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7168ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0027 | PC: 0x013df0 | FDE: 0x0c7528 | Size: 232 bytes
// Hàm FDE #0027 | Địa chỉ PC: 0x013df0 | Địa chỉ FDE: 0x0c7528 | Kích thước: 232 bytes
//   0x013df0: D101C3FF  sub      sp, sp, #0x70
//   0x013df4: F90023F5  str      x21, [sp, #0x40]
//   0x013df8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x013dfc: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0027_0x013df0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x013df0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c7528ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0028 | PC: 0x013ed8 | FDE: 0x0c71a8 | Size: 72 bytes
// Hàm FDE #0028 | Địa chỉ PC: 0x013ed8 | Địa chỉ FDE: 0x0c71a8 | Kích thước: 72 bytes
//   0x013ed8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x013edc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x013ee0: 910043FD  add      x29, sp, #0x10
//   0x013ee4: B00006D3  adrp     x19, #0xec000
static inline uint64_t fde_func_0028_0x013ed8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x013ed8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c71a8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0029 | PC: 0x013f20 | FDE: 0x0c76c0 | Size: 232 bytes
// Hàm FDE #0029 | Địa chỉ PC: 0x013f20 | Địa chỉ FDE: 0x0c76c0 | Kích thước: 232 bytes
//   0x013f20: D101C3FF  sub      sp, sp, #0x70
//   0x013f24: F90023F5  str      x21, [sp, #0x40]
//   0x013f28: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x013f2c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0029_0x013f20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x013f20ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c76c0ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0030 | PC: 0x014008 | FDE: 0x0c75f8 | Size: 72 bytes
// Hàm FDE #0030 | Địa chỉ PC: 0x014008 | Địa chỉ FDE: 0x0c75f8 | Kích thước: 72 bytes
//   0x014008: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01400c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x014010: 910043FD  add      x29, sp, #0x10
//   0x014014: 900006D3  adrp     x19, #0xec000
static inline uint64_t fde_func_0030_0x014008(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x014008ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c75f8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0031 | PC: 0x014050 | FDE: 0x0c7828 | Size: 232 bytes
// Hàm FDE #0031 | Địa chỉ PC: 0x014050 | Địa chỉ FDE: 0x0c7828 | Kích thước: 232 bytes
//   0x014050: D101C3FF  sub      sp, sp, #0x70
//   0x014054: F90023F5  str      x21, [sp, #0x40]
//   0x014058: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x01405c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0031_0x014050(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x014050ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c7828ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0032 | PC: 0x014138 | FDE: 0x0c7728 | Size: 72 bytes
// Hàm FDE #0032 | Địa chỉ PC: 0x014138 | Địa chỉ FDE: 0x0c7728 | Kích thước: 72 bytes
//   0x014138: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01413c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x014140: 910043FD  add      x29, sp, #0x10
//   0x014144: 900006D3  adrp     x19, #0xec000
static inline uint64_t fde_func_0032_0x014138(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x014138ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7728ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0033 | PC: 0x014180 | FDE: 0x0c7f70 | Size: 232 bytes
// Hàm FDE #0033 | Địa chỉ PC: 0x014180 | Địa chỉ FDE: 0x0c7f70 | Kích thước: 232 bytes
//   0x014180: D101C3FF  sub      sp, sp, #0x70
//   0x014184: F90023F5  str      x21, [sp, #0x40]
//   0x014188: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x01418c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0033_0x014180(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x014180ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c7f70ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0034 | PC: 0x014268 | FDE: 0x0c79d0 | Size: 72 bytes
// Hàm FDE #0034 | Địa chỉ PC: 0x014268 | Địa chỉ FDE: 0x0c79d0 | Kích thước: 72 bytes
//   0x014268: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01426c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x014270: 910043FD  add      x29, sp, #0x10
//   0x014274: 900006D3  adrp     x19, #0xec000
static inline uint64_t fde_func_0034_0x014268(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x014268ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c79d0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0035 | PC: 0x0142b0 | FDE: 0x0c7fc0 | Size: 232 bytes
// Hàm FDE #0035 | Địa chỉ PC: 0x0142b0 | Địa chỉ FDE: 0x0c7fc0 | Kích thước: 232 bytes
//   0x0142b0: D101C3FF  sub      sp, sp, #0x70
//   0x0142b4: F90023F5  str      x21, [sp, #0x40]
//   0x0142b8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0142bc: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0035_0x0142b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0142b0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c7fc0ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0036 | PC: 0x014398 | FDE: 0x0c7a10 | Size: 72 bytes
// Hàm FDE #0036 | Địa chỉ PC: 0x014398 | Địa chỉ FDE: 0x0c7a10 | Kích thước: 72 bytes
//   0x014398: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01439c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0143a0: 910043FD  add      x29, sp, #0x10
//   0x0143a4: 900006D3  adrp     x19, #0xec000
static inline uint64_t fde_func_0036_0x014398(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x014398ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7a10ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0037 | PC: 0x0143e0 | FDE: 0x0c8010 | Size: 232 bytes
// Hàm FDE #0037 | Địa chỉ PC: 0x0143e0 | Địa chỉ FDE: 0x0c8010 | Kích thước: 232 bytes
//   0x0143e0: D101C3FF  sub      sp, sp, #0x70
//   0x0143e4: F90023F5  str      x21, [sp, #0x40]
//   0x0143e8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0143ec: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0037_0x0143e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0143e0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c8010ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0038 | PC: 0x0144c8 | FDE: 0x0c7a50 | Size: 72 bytes
// Hàm FDE #0038 | Địa chỉ PC: 0x0144c8 | Địa chỉ FDE: 0x0c7a50 | Kích thước: 72 bytes
//   0x0144c8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0144cc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0144d0: 910043FD  add      x29, sp, #0x10
//   0x0144d4: 900006D3  adrp     x19, #0xec000
static inline uint64_t fde_func_0038_0x0144c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0144c8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7a50ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0039 | PC: 0x014510 | FDE: 0x0c8060 | Size: 232 bytes
// Hàm FDE #0039 | Địa chỉ PC: 0x014510 | Địa chỉ FDE: 0x0c8060 | Kích thước: 232 bytes
//   0x014510: D101C3FF  sub      sp, sp, #0x70
//   0x014514: F90023F5  str      x21, [sp, #0x40]
//   0x014518: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x01451c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0039_0x014510(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x014510ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c8060ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0040 | PC: 0x0145f8 | FDE: 0x0c7a90 | Size: 72 bytes
// Hàm FDE #0040 | Địa chỉ PC: 0x0145f8 | Địa chỉ FDE: 0x0c7a90 | Kích thước: 72 bytes
//   0x0145f8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0145fc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x014600: 910043FD  add      x29, sp, #0x10
//   0x014604: 900006D3  adrp     x19, #0xec000
static inline uint64_t fde_func_0040_0x0145f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0145f8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7a90ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0041 | PC: 0x014640 | FDE: 0x0c80b0 | Size: 232 bytes
// Hàm FDE #0041 | Địa chỉ PC: 0x014640 | Địa chỉ FDE: 0x0c80b0 | Kích thước: 232 bytes
//   0x014640: D101C3FF  sub      sp, sp, #0x70
//   0x014644: F90023F5  str      x21, [sp, #0x40]
//   0x014648: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x01464c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0041_0x014640(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x014640ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c80b0ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0042 | PC: 0x014728 | FDE: 0x0c7ad0 | Size: 72 bytes
// Hàm FDE #0042 | Địa chỉ PC: 0x014728 | Địa chỉ FDE: 0x0c7ad0 | Kích thước: 72 bytes
//   0x014728: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01472c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x014730: 910043FD  add      x29, sp, #0x10
//   0x014734: 900006D3  adrp     x19, #0xec000
static inline uint64_t fde_func_0042_0x014728(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x014728ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7ad0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0043 | PC: 0x014770 | FDE: 0x0c8100 | Size: 232 bytes
// Hàm FDE #0043 | Địa chỉ PC: 0x014770 | Địa chỉ FDE: 0x0c8100 | Kích thước: 232 bytes
//   0x014770: D101C3FF  sub      sp, sp, #0x70
//   0x014774: F90023F5  str      x21, [sp, #0x40]
//   0x014778: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x01477c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0043_0x014770(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x014770ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c8100ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0044 | PC: 0x014858 | FDE: 0x0c7b10 | Size: 72 bytes
// Hàm FDE #0044 | Địa chỉ PC: 0x014858 | Địa chỉ FDE: 0x0c7b10 | Kích thước: 72 bytes
//   0x014858: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01485c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x014860: 910043FD  add      x29, sp, #0x10
//   0x014864: 900006D3  adrp     x19, #0xec000
static inline uint64_t fde_func_0044_0x014858(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x014858ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7b10ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0045 | PC: 0x0148a0 | FDE: 0x0c8318 | Size: 232 bytes
// Hàm FDE #0045 | Địa chỉ PC: 0x0148a0 | Địa chỉ FDE: 0x0c8318 | Kích thước: 232 bytes
//   0x0148a0: D101C3FF  sub      sp, sp, #0x70
//   0x0148a4: F90023F5  str      x21, [sp, #0x40]
//   0x0148a8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0148ac: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0045_0x0148a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0148a0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c8318ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0046 | PC: 0x014988 | FDE: 0x0c8248 | Size: 72 bytes
// Hàm FDE #0046 | Địa chỉ PC: 0x014988 | Địa chỉ FDE: 0x0c8248 | Kích thước: 72 bytes
//   0x014988: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01498c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x014990: 910043FD  add      x29, sp, #0x10
//   0x014994: 900006D3  adrp     x19, #0xec000
static inline uint64_t fde_func_0046_0x014988(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x014988ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c8248ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0047 | PC: 0x0149d0 | FDE: 0x0c8590 | Size: 232 bytes
// Hàm FDE #0047 | Địa chỉ PC: 0x0149d0 | Địa chỉ FDE: 0x0c8590 | Kích thước: 232 bytes
//   0x0149d0: D101C3FF  sub      sp, sp, #0x70
//   0x0149d4: F90023F5  str      x21, [sp, #0x40]
//   0x0149d8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0149dc: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0047_0x0149d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0149d0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c8590ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0048 | PC: 0x014ab8 | FDE: 0x0c83d8 | Size: 72 bytes
// Hàm FDE #0048 | Địa chỉ PC: 0x014ab8 | Địa chỉ FDE: 0x0c83d8 | Kích thước: 72 bytes
//   0x014ab8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x014abc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x014ac0: 910043FD  add      x29, sp, #0x10
//   0x014ac4: 900006D3  adrp     x19, #0xec000
static inline uint64_t fde_func_0048_0x014ab8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x014ab8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c83d8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0049 | PC: 0x014b00 | FDE: 0x0c8778 | Size: 232 bytes
// Hàm FDE #0049 | Địa chỉ PC: 0x014b00 | Địa chỉ FDE: 0x0c8778 | Kích thước: 232 bytes
//   0x014b00: D101C3FF  sub      sp, sp, #0x70
//   0x014b04: F90023F5  str      x21, [sp, #0x40]
//   0x014b08: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x014b0c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0049_0x014b00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x014b00ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c8778ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0050 | PC: 0x014be8 | FDE: 0x0c86a8 | Size: 72 bytes
// Hàm FDE #0050 | Địa chỉ PC: 0x014be8 | Địa chỉ FDE: 0x0c86a8 | Kích thước: 72 bytes
//   0x014be8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x014bec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x014bf0: 910043FD  add      x29, sp, #0x10
//   0x014bf4: 900006D3  adrp     x19, #0xec000
static inline uint64_t fde_func_0050_0x014be8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x014be8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c86a8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0051 | PC: 0x014c30 | FDE: 0x0c8c98 | Size: 232 bytes
// Hàm FDE #0051 | Địa chỉ PC: 0x014c30 | Địa chỉ FDE: 0x0c8c98 | Kích thước: 232 bytes
//   0x014c30: D101C3FF  sub      sp, sp, #0x70
//   0x014c34: F90023F5  str      x21, [sp, #0x40]
//   0x014c38: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x014c3c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0051_0x014c30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x014c30ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c8c98ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0052 | PC: 0x014d18 | FDE: 0x0c8860 | Size: 72 bytes
// Hàm FDE #0052 | Địa chỉ PC: 0x014d18 | Địa chỉ FDE: 0x0c8860 | Kích thước: 72 bytes
//   0x014d18: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x014d1c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x014d20: 910043FD  add      x29, sp, #0x10
//   0x014d24: 900006D3  adrp     x19, #0xec000
static inline uint64_t fde_func_0052_0x014d18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x014d18ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c8860ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0053 | PC: 0x014d60 | FDE: 0x0c8ce8 | Size: 232 bytes
// Hàm FDE #0053 | Địa chỉ PC: 0x014d60 | Địa chỉ FDE: 0x0c8ce8 | Kích thước: 232 bytes
//   0x014d60: D101C3FF  sub      sp, sp, #0x70
//   0x014d64: F90023F5  str      x21, [sp, #0x40]
//   0x014d68: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x014d6c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0053_0x014d60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x014d60ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c8ce8ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0054 | PC: 0x014e48 | FDE: 0x0c88a0 | Size: 72 bytes
// Hàm FDE #0054 | Địa chỉ PC: 0x014e48 | Địa chỉ FDE: 0x0c88a0 | Kích thước: 72 bytes
//   0x014e48: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x014e4c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x014e50: 910043FD  add      x29, sp, #0x10
//   0x014e54: 900006D3  adrp     x19, #0xec000
static inline uint64_t fde_func_0054_0x014e48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x014e48ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c88a0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0055 | PC: 0x014e90 | FDE: 0x0c8d38 | Size: 232 bytes
// Hàm FDE #0055 | Địa chỉ PC: 0x014e90 | Địa chỉ FDE: 0x0c8d38 | Kích thước: 232 bytes
//   0x014e90: D101C3FF  sub      sp, sp, #0x70
//   0x014e94: F90023F5  str      x21, [sp, #0x40]
//   0x014e98: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x014e9c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0055_0x014e90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x014e90ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c8d38ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0056 | PC: 0x014f78 | FDE: 0x0c88e0 | Size: 72 bytes
// Hàm FDE #0056 | Địa chỉ PC: 0x014f78 | Địa chỉ FDE: 0x0c88e0 | Kích thước: 72 bytes
//   0x014f78: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x014f7c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x014f80: 910043FD  add      x29, sp, #0x10
//   0x014f84: 900006D3  adrp     x19, #0xec000
static inline uint64_t fde_func_0056_0x014f78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x014f78ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c88e0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0057 | PC: 0x014fc0 | FDE: 0x0c8ed8 | Size: 232 bytes
// Hàm FDE #0057 | Địa chỉ PC: 0x014fc0 | Địa chỉ FDE: 0x0c8ed8 | Kích thước: 232 bytes
//   0x014fc0: D101C3FF  sub      sp, sp, #0x70
//   0x014fc4: F90023F5  str      x21, [sp, #0x40]
//   0x014fc8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x014fcc: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0057_0x014fc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x014fc0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c8ed8ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0058 | PC: 0x0150a8 | FDE: 0x0c8da0 | Size: 72 bytes
// Hàm FDE #0058 | Địa chỉ PC: 0x0150a8 | Địa chỉ FDE: 0x0c8da0 | Kích thước: 72 bytes
//   0x0150a8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0150ac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0150b0: 910043FD  add      x29, sp, #0x10
//   0x0150b4: F00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0058_0x0150a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0150a8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c8da0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0059 | PC: 0x0150f0 | FDE: 0x0c8f28 | Size: 232 bytes
// Hàm FDE #0059 | Địa chỉ PC: 0x0150f0 | Địa chỉ FDE: 0x0c8f28 | Kích thước: 232 bytes
//   0x0150f0: D101C3FF  sub      sp, sp, #0x70
//   0x0150f4: F90023F5  str      x21, [sp, #0x40]
//   0x0150f8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0150fc: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0059_0x0150f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0150f0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c8f28ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0060 | PC: 0x0151d8 | FDE: 0x0c8de0 | Size: 72 bytes
// Hàm FDE #0060 | Địa chỉ PC: 0x0151d8 | Địa chỉ FDE: 0x0c8de0 | Kích thước: 72 bytes
//   0x0151d8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0151dc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0151e0: 910043FD  add      x29, sp, #0x10
//   0x0151e4: F00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0060_0x0151d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0151d8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c8de0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0061 | PC: 0x015220 | FDE: 0x0c90d8 | Size: 232 bytes
// Hàm FDE #0061 | Địa chỉ PC: 0x015220 | Địa chỉ FDE: 0x0c90d8 | Kích thước: 232 bytes
//   0x015220: D101C3FF  sub      sp, sp, #0x70
//   0x015224: F90023F5  str      x21, [sp, #0x40]
//   0x015228: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x01522c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0061_0x015220(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x015220ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c90d8ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0062 | PC: 0x015308 | FDE: 0x0c8fc8 | Size: 72 bytes
// Hàm FDE #0062 | Địa chỉ PC: 0x015308 | Địa chỉ FDE: 0x0c8fc8 | Kích thước: 72 bytes
//   0x015308: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01530c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x015310: 910043FD  add      x29, sp, #0x10
//   0x015314: F00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0062_0x015308(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x015308ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c8fc8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0063 | PC: 0x015350 | FDE: 0x0c9128 | Size: 232 bytes
// Hàm FDE #0063 | Địa chỉ PC: 0x015350 | Địa chỉ FDE: 0x0c9128 | Kích thước: 232 bytes
//   0x015350: D101C3FF  sub      sp, sp, #0x70
//   0x015354: F90023F5  str      x21, [sp, #0x40]
//   0x015358: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x01535c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0063_0x015350(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x015350ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c9128ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0064 | PC: 0x015438 | FDE: 0x0c9008 | Size: 72 bytes
// Hàm FDE #0064 | Địa chỉ PC: 0x015438 | Địa chỉ FDE: 0x0c9008 | Kích thước: 72 bytes
//   0x015438: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01543c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x015440: 910043FD  add      x29, sp, #0x10
//   0x015444: F00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0064_0x015438(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x015438ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9008ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0065 | PC: 0x015480 | FDE: 0x0c9300 | Size: 232 bytes
// Hàm FDE #0065 | Địa chỉ PC: 0x015480 | Địa chỉ FDE: 0x0c9300 | Kích thước: 232 bytes
//   0x015480: D101C3FF  sub      sp, sp, #0x70
//   0x015484: F90023F5  str      x21, [sp, #0x40]
//   0x015488: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x01548c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0065_0x015480(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x015480ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c9300ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0066 | PC: 0x015568 | FDE: 0x0c91c8 | Size: 72 bytes
// Hàm FDE #0066 | Địa chỉ PC: 0x015568 | Địa chỉ FDE: 0x0c91c8 | Kích thước: 72 bytes
//   0x015568: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01556c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x015570: 910043FD  add      x29, sp, #0x10
//   0x015574: F00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0066_0x015568(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x015568ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c91c8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0067 | PC: 0x0155b0 | FDE: 0x0c9458 | Size: 232 bytes
// Hàm FDE #0067 | Địa chỉ PC: 0x0155b0 | Địa chỉ FDE: 0x0c9458 | Kích thước: 232 bytes
//   0x0155b0: D101C3FF  sub      sp, sp, #0x70
//   0x0155b4: F90023F5  str      x21, [sp, #0x40]
//   0x0155b8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0155bc: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0067_0x0155b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0155b0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c9458ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0068 | PC: 0x015698 | FDE: 0x0c93a0 | Size: 72 bytes
// Hàm FDE #0068 | Địa chỉ PC: 0x015698 | Địa chỉ FDE: 0x0c93a0 | Kích thước: 72 bytes
//   0x015698: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01569c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0156a0: 910043FD  add      x29, sp, #0x10
//   0x0156a4: F00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0068_0x015698(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x015698ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c93a0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0069 | PC: 0x0156e0 | FDE: 0x0c9610 | Size: 232 bytes
// Hàm FDE #0069 | Địa chỉ PC: 0x0156e0 | Địa chỉ FDE: 0x0c9610 | Kích thước: 232 bytes
//   0x0156e0: D101C3FF  sub      sp, sp, #0x70
//   0x0156e4: F90023F5  str      x21, [sp, #0x40]
//   0x0156e8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0156ec: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0069_0x0156e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0156e0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c9610ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0070 | PC: 0x0157c8 | FDE: 0x0c94c0 | Size: 72 bytes
// Hàm FDE #0070 | Địa chỉ PC: 0x0157c8 | Địa chỉ FDE: 0x0c94c0 | Kích thước: 72 bytes
//   0x0157c8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0157cc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0157d0: 910043FD  add      x29, sp, #0x10
//   0x0157d4: F00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0070_0x0157c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0157c8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c94c0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0071 | PC: 0x015810 | FDE: 0x0c9660 | Size: 232 bytes
// Hàm FDE #0071 | Địa chỉ PC: 0x015810 | Địa chỉ FDE: 0x0c9660 | Kích thước: 232 bytes
//   0x015810: D101C3FF  sub      sp, sp, #0x70
//   0x015814: F90023F5  str      x21, [sp, #0x40]
//   0x015818: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x01581c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0071_0x015810(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x015810ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c9660ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0072 | PC: 0x0158f8 | FDE: 0x0c9500 | Size: 72 bytes
// Hàm FDE #0072 | Địa chỉ PC: 0x0158f8 | Địa chỉ FDE: 0x0c9500 | Kích thước: 72 bytes
//   0x0158f8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0158fc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x015900: 910043FD  add      x29, sp, #0x10
//   0x015904: F00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0072_0x0158f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0158f8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9500ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0073 | PC: 0x015940 | FDE: 0x0c96b0 | Size: 232 bytes
// Hàm FDE #0073 | Địa chỉ PC: 0x015940 | Địa chỉ FDE: 0x0c96b0 | Kích thước: 232 bytes
//   0x015940: D101C3FF  sub      sp, sp, #0x70
//   0x015944: F90023F5  str      x21, [sp, #0x40]
//   0x015948: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x01594c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0073_0x015940(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x015940ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c96b0ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0074 | PC: 0x015a28 | FDE: 0x0c9540 | Size: 72 bytes
// Hàm FDE #0074 | Địa chỉ PC: 0x015a28 | Địa chỉ FDE: 0x0c9540 | Kích thước: 72 bytes
//   0x015a28: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x015a2c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x015a30: 910043FD  add      x29, sp, #0x10
//   0x015a34: F00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0074_0x015a28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x015a28ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9540ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0075 | PC: 0x015a70 | FDE: 0x0c97e0 | Size: 232 bytes
// Hàm FDE #0075 | Địa chỉ PC: 0x015a70 | Địa chỉ FDE: 0x0c97e0 | Kích thước: 232 bytes
//   0x015a70: D101C3FF  sub      sp, sp, #0x70
//   0x015a74: F90023F5  str      x21, [sp, #0x40]
//   0x015a78: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x015a7c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0075_0x015a70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x015a70ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c97e0ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0076 | PC: 0x015b58 | FDE: 0x0c9718 | Size: 72 bytes
// Hàm FDE #0076 | Địa chỉ PC: 0x015b58 | Địa chỉ FDE: 0x0c9718 | Kích thước: 72 bytes
//   0x015b58: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x015b5c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x015b60: 910043FD  add      x29, sp, #0x10
//   0x015b64: F00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0076_0x015b58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x015b58ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9718ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0077 | PC: 0x015ba0 | FDE: 0x0c9970 | Size: 232 bytes
// Hàm FDE #0077 | Địa chỉ PC: 0x015ba0 | Địa chỉ FDE: 0x0c9970 | Kích thước: 232 bytes
//   0x015ba0: D101C3FF  sub      sp, sp, #0x70
//   0x015ba4: F90023F5  str      x21, [sp, #0x40]
//   0x015ba8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x015bac: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0077_0x015ba0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x015ba0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c9970ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0078 | PC: 0x015c88 | FDE: 0x0c9888 | Size: 72 bytes
// Hàm FDE #0078 | Địa chỉ PC: 0x015c88 | Địa chỉ FDE: 0x0c9888 | Kích thước: 72 bytes
//   0x015c88: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x015c8c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x015c90: 910043FD  add      x29, sp, #0x10
//   0x015c94: F00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0078_0x015c88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x015c88ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9888ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0079 | PC: 0x015cd0 | FDE: 0x0c9c30 | Size: 232 bytes
// Hàm FDE #0079 | Địa chỉ PC: 0x015cd0 | Địa chỉ FDE: 0x0c9c30 | Kích thước: 232 bytes
//   0x015cd0: D101C3FF  sub      sp, sp, #0x70
//   0x015cd4: F90023F5  str      x21, [sp, #0x40]
//   0x015cd8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x015cdc: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0079_0x015cd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x015cd0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c9c30ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0080 | PC: 0x015db8 | FDE: 0x0c9a90 | Size: 72 bytes
// Hàm FDE #0080 | Địa chỉ PC: 0x015db8 | Địa chỉ FDE: 0x0c9a90 | Kích thước: 72 bytes
//   0x015db8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x015dbc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x015dc0: 910043FD  add      x29, sp, #0x10
//   0x015dc4: F00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0080_0x015db8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x015db8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9a90ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0081 | PC: 0x015e00 | FDE: 0x0c9c80 | Size: 232 bytes
// Hàm FDE #0081 | Địa chỉ PC: 0x015e00 | Địa chỉ FDE: 0x0c9c80 | Kích thước: 232 bytes
//   0x015e00: D101C3FF  sub      sp, sp, #0x70
//   0x015e04: F90023F5  str      x21, [sp, #0x40]
//   0x015e08: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x015e0c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0081_0x015e00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x015e00ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c9c80ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0082 | PC: 0x015ee8 | FDE: 0x0c9ad0 | Size: 72 bytes
// Hàm FDE #0082 | Địa chỉ PC: 0x015ee8 | Địa chỉ FDE: 0x0c9ad0 | Kích thước: 72 bytes
//   0x015ee8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x015eec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x015ef0: 910043FD  add      x29, sp, #0x10
//   0x015ef4: F00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0082_0x015ee8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x015ee8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9ad0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0083 | PC: 0x015f30 | FDE: 0x0c9e98 | Size: 232 bytes
// Hàm FDE #0083 | Địa chỉ PC: 0x015f30 | Địa chỉ FDE: 0x0c9e98 | Kích thước: 232 bytes
//   0x015f30: D101C3FF  sub      sp, sp, #0x70
//   0x015f34: F90023F5  str      x21, [sp, #0x40]
//   0x015f38: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x015f3c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0083_0x015f30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x015f30ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c9e98ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0084 | PC: 0x016018 | FDE: 0x0c9d20 | Size: 72 bytes
// Hàm FDE #0084 | Địa chỉ PC: 0x016018 | Địa chỉ FDE: 0x0c9d20 | Kích thước: 72 bytes
//   0x016018: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01601c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x016020: 910043FD  add      x29, sp, #0x10
//   0x016024: D00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0084_0x016018(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x016018ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9d20ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0085 | PC: 0x016060 | FDE: 0x0ca2d0 | Size: 232 bytes
// Hàm FDE #0085 | Địa chỉ PC: 0x016060 | Địa chỉ FDE: 0x0ca2d0 | Kích thước: 232 bytes
//   0x016060: D101C3FF  sub      sp, sp, #0x70
//   0x016064: F90023F5  str      x21, [sp, #0x40]
//   0x016068: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x01606c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0085_0x016060(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x016060ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0ca2d0ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0086 | PC: 0x016148 | FDE: 0x0ca1f8 | Size: 72 bytes
// Hàm FDE #0086 | Địa chỉ PC: 0x016148 | Địa chỉ FDE: 0x0ca1f8 | Kích thước: 72 bytes
//   0x016148: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01614c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x016150: 910043FD  add      x29, sp, #0x10
//   0x016154: D00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0086_0x016148(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x016148ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0ca1f8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0087 | PC: 0x016190 | FDE: 0x0ca400 | Size: 232 bytes
// Hàm FDE #0087 | Địa chỉ PC: 0x016190 | Địa chỉ FDE: 0x0ca400 | Kích thước: 232 bytes
//   0x016190: D101C3FF  sub      sp, sp, #0x70
//   0x016194: F90023F5  str      x21, [sp, #0x40]
//   0x016198: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x01619c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0087_0x016190(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x016190ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0ca400ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0088 | PC: 0x016278 | FDE: 0x0ca338 | Size: 72 bytes
// Hàm FDE #0088 | Địa chỉ PC: 0x016278 | Địa chỉ FDE: 0x0ca338 | Kích thước: 72 bytes
//   0x016278: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01627c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x016280: 910043FD  add      x29, sp, #0x10
//   0x016284: D00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0088_0x016278(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x016278ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0ca338ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0089 | PC: 0x0162c0 | FDE: 0x0ca558 | Size: 232 bytes
// Hàm FDE #0089 | Địa chỉ PC: 0x0162c0 | Địa chỉ FDE: 0x0ca558 | Kích thước: 232 bytes
//   0x0162c0: D101C3FF  sub      sp, sp, #0x70
//   0x0162c4: F90023F5  str      x21, [sp, #0x40]
//   0x0162c8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0162cc: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0089_0x0162c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0162c0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0ca558ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0090 | PC: 0x0163a8 | FDE: 0x0ca4a0 | Size: 72 bytes
// Hàm FDE #0090 | Địa chỉ PC: 0x0163a8 | Địa chỉ FDE: 0x0ca4a0 | Kích thước: 72 bytes
//   0x0163a8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0163ac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0163b0: 910043FD  add      x29, sp, #0x10
//   0x0163b4: D00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0090_0x0163a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0163a8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0ca4a0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0091 | PC: 0x0163f0 | FDE: 0x0ca688 | Size: 232 bytes
// Hàm FDE #0091 | Địa chỉ PC: 0x0163f0 | Địa chỉ FDE: 0x0ca688 | Kích thước: 232 bytes
//   0x0163f0: D101C3FF  sub      sp, sp, #0x70
//   0x0163f4: F90023F5  str      x21, [sp, #0x40]
//   0x0163f8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0163fc: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0091_0x0163f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0163f0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0ca688ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0092 | PC: 0x0164d8 | FDE: 0x0ca5c0 | Size: 72 bytes
// Hàm FDE #0092 | Địa chỉ PC: 0x0164d8 | Địa chỉ FDE: 0x0ca5c0 | Kích thước: 72 bytes
//   0x0164d8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0164dc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0164e0: 910043FD  add      x29, sp, #0x10
//   0x0164e4: D00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0092_0x0164d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0164d8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0ca5c0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0093 | PC: 0x016520 | FDE: 0x0ca7b8 | Size: 232 bytes
// Hàm FDE #0093 | Địa chỉ PC: 0x016520 | Địa chỉ FDE: 0x0ca7b8 | Kích thước: 232 bytes
//   0x016520: D101C3FF  sub      sp, sp, #0x70
//   0x016524: F90023F5  str      x21, [sp, #0x40]
//   0x016528: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x01652c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0093_0x016520(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x016520ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0ca7b8ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0094 | PC: 0x016608 | FDE: 0x0ca6f0 | Size: 72 bytes
// Hàm FDE #0094 | Địa chỉ PC: 0x016608 | Địa chỉ FDE: 0x0ca6f0 | Kích thước: 72 bytes
//   0x016608: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01660c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x016610: 910043FD  add      x29, sp, #0x10
//   0x016614: D00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0094_0x016608(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x016608ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0ca6f0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0095 | PC: 0x016650 | FDE: 0x0caa08 | Size: 232 bytes
// Hàm FDE #0095 | Địa chỉ PC: 0x016650 | Địa chỉ FDE: 0x0caa08 | Kích thước: 232 bytes
//   0x016650: D101C3FF  sub      sp, sp, #0x70
//   0x016654: F90023F5  str      x21, [sp, #0x40]
//   0x016658: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x01665c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0095_0x016650(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x016650ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0caa08ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0096 | PC: 0x016738 | FDE: 0x0ca820 | Size: 72 bytes
// Hàm FDE #0096 | Địa chỉ PC: 0x016738 | Địa chỉ FDE: 0x0ca820 | Kích thước: 72 bytes
//   0x016738: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01673c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x016740: 910043FD  add      x29, sp, #0x10
//   0x016744: D00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0096_0x016738(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x016738ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0ca820ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0097 | PC: 0x016780 | FDE: 0x0caa58 | Size: 232 bytes
// Hàm FDE #0097 | Địa chỉ PC: 0x016780 | Địa chỉ FDE: 0x0caa58 | Kích thước: 232 bytes
//   0x016780: D101C3FF  sub      sp, sp, #0x70
//   0x016784: F90023F5  str      x21, [sp, #0x40]
//   0x016788: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x01678c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0097_0x016780(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x016780ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0caa58ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0098 | PC: 0x016868 | FDE: 0x0ca860 | Size: 72 bytes
// Hàm FDE #0098 | Địa chỉ PC: 0x016868 | Địa chỉ FDE: 0x0ca860 | Kích thước: 72 bytes
//   0x016868: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01686c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x016870: 910043FD  add      x29, sp, #0x10
//   0x016874: D00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0098_0x016868(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x016868ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0ca860ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0099 | PC: 0x0168b0 | FDE: 0x0cac18 | Size: 232 bytes
// Hàm FDE #0099 | Địa chỉ PC: 0x0168b0 | Địa chỉ FDE: 0x0cac18 | Kích thước: 232 bytes
//   0x0168b0: D101C3FF  sub      sp, sp, #0x70
//   0x0168b4: F90023F5  str      x21, [sp, #0x40]
//   0x0168b8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0168bc: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0099_0x0168b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0168b0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0cac18ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0100 | PC: 0x016998 | FDE: 0x0caac0 | Size: 72 bytes
// Hàm FDE #0100 | Địa chỉ PC: 0x016998 | Địa chỉ FDE: 0x0caac0 | Kích thước: 72 bytes
//   0x016998: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01699c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0169a0: 910043FD  add      x29, sp, #0x10
//   0x0169a4: D00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0100_0x016998(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x016998ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0caac0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0101 | PC: 0x0169e0 | FDE: 0x0cafc8 | Size: 232 bytes
// Hàm FDE #0101 | Địa chỉ PC: 0x0169e0 | Địa chỉ FDE: 0x0cafc8 | Kích thước: 232 bytes
//   0x0169e0: D101C3FF  sub      sp, sp, #0x70
//   0x0169e4: F90023F5  str      x21, [sp, #0x40]
//   0x0169e8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0169ec: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0101_0x0169e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0169e0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0cafc8ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0102 | PC: 0x016ac8 | FDE: 0x0cacd8 | Size: 72 bytes
// Hàm FDE #0102 | Địa chỉ PC: 0x016ac8 | Địa chỉ FDE: 0x0cacd8 | Kích thước: 72 bytes
//   0x016ac8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x016acc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x016ad0: 910043FD  add      x29, sp, #0x10
//   0x016ad4: D00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0102_0x016ac8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x016ac8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cacd8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0103 | PC: 0x016b10 | FDE: 0x0cb018 | Size: 232 bytes
// Hàm FDE #0103 | Địa chỉ PC: 0x016b10 | Địa chỉ FDE: 0x0cb018 | Kích thước: 232 bytes
//   0x016b10: D101C3FF  sub      sp, sp, #0x70
//   0x016b14: F90023F5  str      x21, [sp, #0x40]
//   0x016b18: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x016b1c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0103_0x016b10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x016b10ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0cb018ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0104 | PC: 0x016bf8 | FDE: 0x0cad18 | Size: 72 bytes
// Hàm FDE #0104 | Địa chỉ PC: 0x016bf8 | Địa chỉ FDE: 0x0cad18 | Kích thước: 72 bytes
//   0x016bf8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x016bfc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x016c00: 910043FD  add      x29, sp, #0x10
//   0x016c04: D00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0104_0x016bf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x016bf8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cad18ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0105 | PC: 0x016c40 | FDE: 0x0cb508 | Size: 232 bytes
// Hàm FDE #0105 | Địa chỉ PC: 0x016c40 | Địa chỉ FDE: 0x0cb508 | Kích thước: 232 bytes
//   0x016c40: D101C3FF  sub      sp, sp, #0x70
//   0x016c44: F90023F5  str      x21, [sp, #0x40]
//   0x016c48: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x016c4c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0105_0x016c40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x016c40ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0cb508ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0106 | PC: 0x016d28 | FDE: 0x0cb430 | Size: 72 bytes
// Hàm FDE #0106 | Địa chỉ PC: 0x016d28 | Địa chỉ FDE: 0x0cb430 | Kích thước: 72 bytes
//   0x016d28: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x016d2c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x016d30: 910043FD  add      x29, sp, #0x10
//   0x016d34: D00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0106_0x016d28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x016d28ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cb430ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0107 | PC: 0x016d70 | FDE: 0x0cb688 | Size: 232 bytes
// Hàm FDE #0107 | Địa chỉ PC: 0x016d70 | Địa chỉ FDE: 0x0cb688 | Kích thước: 232 bytes
//   0x016d70: D101C3FF  sub      sp, sp, #0x70
//   0x016d74: F90023F5  str      x21, [sp, #0x40]
//   0x016d78: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x016d7c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0107_0x016d70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x016d70ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0cb688ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0108 | PC: 0x016e58 | FDE: 0x0cb570 | Size: 72 bytes
// Hàm FDE #0108 | Địa chỉ PC: 0x016e58 | Địa chỉ FDE: 0x0cb570 | Kích thước: 72 bytes
//   0x016e58: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x016e5c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x016e60: 910043FD  add      x29, sp, #0x10
//   0x016e64: D00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0108_0x016e58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x016e58ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cb570ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0109 | PC: 0x016ea0 | FDE: 0x0cb6d8 | Size: 232 bytes
// Hàm FDE #0109 | Địa chỉ PC: 0x016ea0 | Địa chỉ FDE: 0x0cb6d8 | Kích thước: 232 bytes
//   0x016ea0: D101C3FF  sub      sp, sp, #0x70
//   0x016ea4: F90023F5  str      x21, [sp, #0x40]
//   0x016ea8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x016eac: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0109_0x016ea0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x016ea0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0cb6d8ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0110 | PC: 0x016f88 | FDE: 0x0cb5b0 | Size: 72 bytes
// Hàm FDE #0110 | Địa chỉ PC: 0x016f88 | Địa chỉ FDE: 0x0cb5b0 | Kích thước: 72 bytes
//   0x016f88: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x016f8c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x016f90: 910043FD  add      x29, sp, #0x10
//   0x016f94: D00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0110_0x016f88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x016f88ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cb5b0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0111 | PC: 0x016fd0 | FDE: 0x0cb818 | Size: 232 bytes
// Hàm FDE #0111 | Địa chỉ PC: 0x016fd0 | Địa chỉ FDE: 0x0cb818 | Kích thước: 232 bytes
//   0x016fd0: D101C3FF  sub      sp, sp, #0x70
//   0x016fd4: F90023F5  str      x21, [sp, #0x40]
//   0x016fd8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x016fdc: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0111_0x016fd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x016fd0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0cb818ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0112 | PC: 0x0170b8 | FDE: 0x0cb740 | Size: 72 bytes
// Hàm FDE #0112 | Địa chỉ PC: 0x0170b8 | Địa chỉ FDE: 0x0cb740 | Kích thước: 72 bytes
//   0x0170b8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0170bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0170c0: 910043FD  add      x29, sp, #0x10
//   0x0170c4: B00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0112_0x0170b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0170b8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cb740ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0113 | PC: 0x017100 | FDE: 0x0cb998 | Size: 232 bytes
// Hàm FDE #0113 | Địa chỉ PC: 0x017100 | Địa chỉ FDE: 0x0cb998 | Kích thước: 232 bytes
//   0x017100: D101C3FF  sub      sp, sp, #0x70
//   0x017104: F90023F5  str      x21, [sp, #0x40]
//   0x017108: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x01710c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0113_0x017100(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x017100ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0cb998ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0114 | PC: 0x0171e8 | FDE: 0x0cb880 | Size: 72 bytes
// Hàm FDE #0114 | Địa chỉ PC: 0x0171e8 | Địa chỉ FDE: 0x0cb880 | Kích thước: 72 bytes
//   0x0171e8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0171ec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0171f0: 910043FD  add      x29, sp, #0x10
//   0x0171f4: B00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0114_0x0171e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0171e8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cb880ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0115 | PC: 0x017230 | FDE: 0x0cb9e8 | Size: 232 bytes
// Hàm FDE #0115 | Địa chỉ PC: 0x017230 | Địa chỉ FDE: 0x0cb9e8 | Kích thước: 232 bytes
//   0x017230: D101C3FF  sub      sp, sp, #0x70
//   0x017234: F90023F5  str      x21, [sp, #0x40]
//   0x017238: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x01723c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0115_0x017230(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x017230ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0cb9e8ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0116 | PC: 0x017318 | FDE: 0x0cb8c0 | Size: 72 bytes
// Hàm FDE #0116 | Địa chỉ PC: 0x017318 | Địa chỉ FDE: 0x0cb8c0 | Kích thước: 72 bytes
//   0x017318: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01731c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x017320: 910043FD  add      x29, sp, #0x10
//   0x017324: B00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0116_0x017318(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x017318ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cb8c0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0117 | PC: 0x017360 | FDE: 0x0cbb68 | Size: 232 bytes
// Hàm FDE #0117 | Địa chỉ PC: 0x017360 | Địa chỉ FDE: 0x0cbb68 | Kích thước: 232 bytes
//   0x017360: D101C3FF  sub      sp, sp, #0x70
//   0x017364: F90023F5  str      x21, [sp, #0x40]
//   0x017368: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x01736c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0117_0x017360(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x017360ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0cbb68ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0118 | PC: 0x017448 | FDE: 0x0cba50 | Size: 72 bytes
// Hàm FDE #0118 | Địa chỉ PC: 0x017448 | Địa chỉ FDE: 0x0cba50 | Kích thước: 72 bytes
//   0x017448: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01744c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x017450: 910043FD  add      x29, sp, #0x10
//   0x017454: B00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0118_0x017448(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x017448ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cba50ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0119 | PC: 0x017490 | FDE: 0x0cbbb8 | Size: 232 bytes
// Hàm FDE #0119 | Địa chỉ PC: 0x017490 | Địa chỉ FDE: 0x0cbbb8 | Kích thước: 232 bytes
//   0x017490: D101C3FF  sub      sp, sp, #0x70
//   0x017494: F90023F5  str      x21, [sp, #0x40]
//   0x017498: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x01749c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0119_0x017490(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x017490ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0cbbb8ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0120 | PC: 0x017578 | FDE: 0x0cba90 | Size: 72 bytes
// Hàm FDE #0120 | Địa chỉ PC: 0x017578 | Địa chỉ FDE: 0x0cba90 | Kích thước: 72 bytes
//   0x017578: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01757c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x017580: 910043FD  add      x29, sp, #0x10
//   0x017584: B00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0120_0x017578(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x017578ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cba90ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0121 | PC: 0x0175c0 | FDE: 0x0cbd88 | Size: 232 bytes
// Hàm FDE #0121 | Địa chỉ PC: 0x0175c0 | Địa chỉ FDE: 0x0cbd88 | Kích thước: 232 bytes
//   0x0175c0: D101C3FF  sub      sp, sp, #0x70
//   0x0175c4: F90023F5  str      x21, [sp, #0x40]
//   0x0175c8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0175cc: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0121_0x0175c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0175c0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0cbd88ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0122 | PC: 0x0176a8 | FDE: 0x0cbc20 | Size: 72 bytes
// Hàm FDE #0122 | Địa chỉ PC: 0x0176a8 | Địa chỉ FDE: 0x0cbc20 | Kích thước: 72 bytes
//   0x0176a8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0176ac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0176b0: 910043FD  add      x29, sp, #0x10
//   0x0176b4: B00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0122_0x0176a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0176a8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cbc20ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0123 | PC: 0x0176f0 | FDE: 0x0cbee0 | Size: 232 bytes
// Hàm FDE #0123 | Địa chỉ PC: 0x0176f0 | Địa chỉ FDE: 0x0cbee0 | Kích thước: 232 bytes
//   0x0176f0: D101C3FF  sub      sp, sp, #0x70
//   0x0176f4: F90023F5  str      x21, [sp, #0x40]
//   0x0176f8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0176fc: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0123_0x0176f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0176f0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0cbee0ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0124 | PC: 0x0177d8 | FDE: 0x0cbe08 | Size: 72 bytes
// Hàm FDE #0124 | Địa chỉ PC: 0x0177d8 | Địa chỉ FDE: 0x0cbe08 | Kích thước: 72 bytes
//   0x0177d8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0177dc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0177e0: 910043FD  add      x29, sp, #0x10
//   0x0177e4: B00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0124_0x0177d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0177d8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cbe08ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0125 | PC: 0x017820 | FDE: 0x0ccc60 | Size: 196 bytes
// Hàm FDE #0125 | Địa chỉ PC: 0x017820 | Địa chỉ FDE: 0x0ccc60 | Kích thước: 196 bytes
//   0x017820: D10183FF  sub      sp, sp, #0x60
//   0x017824: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x017828: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x01782c: 910143FD  add      x29, sp, #0x50
static inline uint64_t fde_func_0125_0x017820(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x017820ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9044ff4ULL) ^ 0x0ccc60ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0126 | PC: 0x0178e4 | FDE: 0x0cc150 | Size: 28 bytes
// Hàm FDE #0126 | Địa chỉ PC: 0x0178e4 | Địa chỉ FDE: 0x0cc150 | Kích thước: 28 bytes
//   0x0178e4: D0000460  adrp     x0, #0xa5000
//   0x0178e8: B00006A1  adrp     x1, #0xec000
//   0x0178ec: B0000682  adrp     x2, #0xe8000
//   0x0178f0: 912BE000  add      x0, x0, #0xaf8
static inline uint64_t fde_func_0126_0x0178e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0178e4ULL ^ (static_cast<uint64_t>(0xd0000460ULL) << 13);
    acc = (acc + a1 + 0xb00006a1ULL) ^ 0x0cc150ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0127 | PC: 0x017900 | FDE: 0x0cccb0 | Size: 224 bytes
// Hàm FDE #0127 | Địa chỉ PC: 0x017900 | Địa chỉ FDE: 0x0cccb0 | Kích thước: 224 bytes
//   0x017900: D101C3FF  sub      sp, sp, #0x70
//   0x017904: F90023F5  str      x21, [sp, #0x40]
//   0x017908: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x01790c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0127_0x017900(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x017900ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0cccb0ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #0128 | PC: 0x0179e0 | FDE: 0x0cc180 | Size: 132 bytes
// Hàm FDE #0128 | Địa chỉ PC: 0x0179e0 | Địa chỉ FDE: 0x0cc180 | Kích thước: 132 bytes
//   0x0179e0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0179e4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0179e8: 910043FD  add      x29, sp, #0x10
//   0x0179ec: B00006B3  adrp     x19, #0xec000
static inline uint64_t fde_func_0128_0x0179e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0179e0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cc180ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0129 | PC: 0x017a64 | FDE: 0x0bc8c8 | Size: 228 bytes [_ZN4nuro15ConversationHub8instanceEv]
// Hàm FDE #0129 | Địa chỉ PC: 0x017a64 | Địa chỉ FDE: 0x0bc8c8 | Kích thước: 228 bytes
//   0x017a64: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x017a68: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x017a6c: 910043FD  add      x29, sp, #0x10
//   0x017a70: AA0803F3  mov      x19, x8
static inline uint64_t fde_func_0129_0x017a64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x017a64ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bc8c8ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #0130 | PC: 0x017b48 | FDE: 0x0bc8f0 | Size: 80 bytes
// Hàm FDE #0130 | Địa chỉ PC: 0x017b48 | Địa chỉ FDE: 0x0bc8f0 | Kích thước: 80 bytes
//   0x017b48: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x017b4c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x017b50: 910043FD  add      x29, sp, #0x10
//   0x017b54: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0130_0x017b48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x017b48ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bc8f0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0131 | PC: 0x017b98 | FDE: 0x0bc5d8 | Size: 48 bytes
// Hàm FDE #0131 | Địa chỉ PC: 0x017b98 | Địa chỉ FDE: 0x0bc5d8 | Kích thước: 48 bytes
//   0x017b98: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x017b9c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x017ba0: 910043FD  add      x29, sp, #0x10
//   0x017ba4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0131_0x017b98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x017b98ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bc5d8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0132 | PC: 0x017bc8 | FDE: 0x0bc5f8 | Size: 12 bytes
// Hàm FDE #0132 | Địa chỉ PC: 0x017bc8 | Địa chỉ FDE: 0x0bc5f8 | Kích thước: 12 bytes
//   0x017bc8: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x017bcc: 97FFEC91  bl       #0x12e10
//   0x017bd0: 97FFED38  bl       #0x130b0
static inline uint64_t fde_func_0132_0x017bc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x017bc8ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x97ffec91ULL) ^ 0x0bc5f8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0133 | PC: 0x017bd4 | FDE: 0x0bc610 | Size: 48 bytes
// Hàm FDE #0133 | Địa chỉ PC: 0x017bd4 | Địa chỉ FDE: 0x0bc610 | Kích thước: 48 bytes
//   0x017bd4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x017bd8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x017bdc: 910043FD  add      x29, sp, #0x10
//   0x017be0: B0000688  adrp     x8, #0xe8000
static inline uint64_t fde_func_0133_0x017bd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x017bd4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bc610ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0134 | PC: 0x017c04 | FDE: 0x0bc630 | Size: 56 bytes
// Hàm FDE #0134 | Địa chỉ PC: 0x017c04 | Địa chỉ FDE: 0x0bc630 | Kích thước: 56 bytes
//   0x017c04: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x017c08: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x017c0c: 910043FD  add      x29, sp, #0x10
//   0x017c10: B0000688  adrp     x8, #0xe8000
static inline uint64_t fde_func_0134_0x017c04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x017c04ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bc630ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0135 | PC: 0x017c3c | FDE: 0x0bc650 | Size: 12 bytes
// Hàm FDE #0135 | Địa chỉ PC: 0x017c3c | Địa chỉ FDE: 0x0bc650 | Kích thước: 12 bytes
//   0x017c3c: F8418C08  ldr      x8, [x0, #0x18]!
//   0x017c40: F9400101  ldr      x1, [x8]
//   0x017c44: D61F0020  br       x1
static inline uint64_t fde_func_0135_0x017c3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x017c3cULL ^ (static_cast<uint64_t>(0xf8418c08ULL) << 13);
    acc = (acc + a1 + 0xf9400101ULL) ^ 0x0bc650ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0136 | PC: 0x017c48 | FDE: 0x0bc668 | Size: 4 bytes
// Hàm FDE #0136 | Địa chỉ PC: 0x017c48 | Địa chỉ FDE: 0x0bc668 | Kích thước: 4 bytes
//   0x017c48: 17FFEAEE  b        #0x12800
static inline uint64_t fde_func_0136_0x017c48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x017c48ULL ^ (static_cast<uint64_t>(0x17ffeaeeULL) << 13);
    acc = (acc + a1 + 0xf81d0ff5ULL) ^ 0x0bc668ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0137 | PC: 0x017c4c | FDE: 0x0bc680 | Size: 164 bytes
// Hàm FDE #0137 | Địa chỉ PC: 0x017c4c | Địa chỉ FDE: 0x0bc680 | Kích thước: 164 bytes
//   0x017c4c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x017c50: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x017c54: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x017c58: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0137_0x017c4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x017c4cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bc680ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #0138 | PC: 0x017cf0 | FDE: 0x0bc6a0 | Size: 36 bytes
// Hàm FDE #0138 | Địa chỉ PC: 0x017cf0 | Địa chỉ FDE: 0x0bc6a0 | Kích thước: 36 bytes
//   0x017cf0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x017cf4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x017cf8: 910043FD  add      x29, sp, #0x10
//   0x017cfc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0138_0x017cf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x017cf0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bc6a0ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0139 | PC: 0x017d14 | FDE: 0x0bc918 | Size: 256 bytes
// Hàm FDE #0139 | Địa chỉ PC: 0x017d14 | Địa chỉ FDE: 0x0bc918 | Kích thước: 256 bytes
//   0x017d14: D10183FF  sub      sp, sp, #0x60
//   0x017d18: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x017d1c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x017d20: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0139_0x017d14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x017d14ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x0bc918ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0140 | PC: 0x017f3c | FDE: 0x0bc948 | Size: 256 bytes
// Hàm FDE #0140 | Địa chỉ PC: 0x017f3c | Địa chỉ FDE: 0x0bc948 | Kích thước: 256 bytes
//   0x017f3c: D10243FF  sub      sp, sp, #0x90
//   0x017f40: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x017f44: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x017f48: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_0140_0x017f3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x017f3cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90467faULL) ^ 0x0bc948ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0141 | PC: 0x0181b4 | FDE: 0x0bc980 | Size: 256 bytes
// Hàm FDE #0141 | Địa chỉ PC: 0x0181b4 | Địa chỉ FDE: 0x0bc980 | Kích thước: 256 bytes
//   0x0181b4: D10143FF  sub      sp, sp, #0x50
//   0x0181b8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0181bc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0181c0: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0141_0x0181b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0181b4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x0bc980ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0142 | PC: 0x0182d0 | FDE: 0x0bc9b0 | Size: 256 bytes
// Hàm FDE #0142 | Địa chỉ PC: 0x0182d0 | Địa chỉ FDE: 0x0bc9b0 | Kích thước: 256 bytes
//   0x0182d0: D10183FF  sub      sp, sp, #0x60
//   0x0182d4: F90013F7  str      x23, [sp, #0x20]
//   0x0182d8: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0182dc: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0142_0x0182d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0182d0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x0bc9b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0143 | PC: 0x018400 | FDE: 0x0bc9e0 | Size: 256 bytes
// Hàm FDE #0143 | Địa chỉ PC: 0x018400 | Địa chỉ FDE: 0x0bc9e0 | Kích thước: 256 bytes
//   0x018400: D10103FF  sub      sp, sp, #0x40
//   0x018404: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x018408: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x01840c: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0143_0x018400(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x018400ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x0bc9e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0144 | PC: 0x018530 | FDE: 0x0bc6c0 | Size: 172 bytes
// Hàm FDE #0144 | Địa chỉ PC: 0x018530 | Địa chỉ FDE: 0x0bc6c0 | Kích thước: 172 bytes
//   0x018530: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x018534: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x018538: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x01853c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0144_0x018530(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x018530ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bc6c0ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #0145 | PC: 0x0185dc | FDE: 0x0bc6e8 | Size: 200 bytes
// Hàm FDE #0145 | Địa chỉ PC: 0x0185dc | Địa chỉ FDE: 0x0bc6e8 | Kích thước: 200 bytes
//   0x0185dc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0185e0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0185e4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0185e8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0145_0x0185dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0185dcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bc6e8ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0146 | PC: 0x0186a4 | FDE: 0x0bc708 | Size: 256 bytes
// Hàm FDE #0146 | Địa chỉ PC: 0x0186a4 | Địa chỉ FDE: 0x0bc708 | Kích thước: 256 bytes
//   0x0186a4: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0186a8: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0186ac: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0186b0: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0146_0x0186a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0186a4ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0bc708ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0147 | PC: 0x0187dc | FDE: 0x0bc738 | Size: 20 bytes
// Hàm FDE #0147 | Địa chỉ PC: 0x0187dc | Địa chỉ FDE: 0x0bc738 | Kích thước: 20 bytes
//   0x0187dc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0187e0: 910003FD  mov      x29, sp
//   0x0187e4: 900004A0  adrp     x0, #0xac000
//   0x0187e8: 913A5000  add      x0, x0, #0xe94
static inline uint64_t fde_func_0147_0x0187dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0187dcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0bc738ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0148 | PC: 0x0187f0 | FDE: 0x0bca08 | Size: 256 bytes
// Hàm FDE #0148 | Địa chỉ PC: 0x0187f0 | Địa chỉ FDE: 0x0bca08 | Kích thước: 256 bytes
//   0x0187f0: D10183FF  sub      sp, sp, #0x60
//   0x0187f4: F90013F7  str      x23, [sp, #0x20]
//   0x0187f8: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0187fc: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0148_0x0187f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0187f0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x0bca08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0149 | PC: 0x018988 | FDE: 0x0bca38 | Size: 256 bytes
// Hàm FDE #0149 | Địa chỉ PC: 0x018988 | Địa chỉ FDE: 0x0bca38 | Kích thước: 256 bytes
//   0x018988: D101C3FF  sub      sp, sp, #0x70
//   0x01898c: F9000BFB  str      x27, [sp, #0x10]
//   0x018990: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x018994: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_0149_0x018988(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x018988ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfbULL) ^ 0x0bca38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0150 | PC: 0x018b54 | FDE: 0x0bc758 | Size: 256 bytes
// Hàm FDE #0150 | Địa chỉ PC: 0x018b54 | Địa chỉ FDE: 0x0bc758 | Kích thước: 256 bytes
//   0x018b54: F100805F  cmp      x2, #0x20
//   0x018b58: 540000C8  b.hi     #0x18b70
//   0x018b5c: F100405F  cmp      x2, #0x10
//   0x018b60: 540006C8  b.hi     #0x18c38
static inline uint64_t fde_func_0150_0x018b54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x018b54ULL ^ (static_cast<uint64_t>(0xf100805fULL) << 13);
    acc = (acc + a1 + 0x540000c8ULL) ^ 0x0bc758ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0151 | PC: 0x018ed4 | FDE: 0x0bc770 | Size: 256 bytes
// Hàm FDE #0151 | Địa chỉ PC: 0x018ed4 | Địa chỉ FDE: 0x0bc770 | Kích thước: 256 bytes
//   0x018ed4: F100243F  cmp      x1, #9
//   0x018ed8: AA0003E8  mov      x8, x0
//   0x018edc: 540002C3  b.lo     #0x18f34
//   0x018ee0: 8B010109  add      x9, x8, x1
static inline uint64_t fde_func_0151_0x018ed4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x018ed4ULL ^ (static_cast<uint64_t>(0xf100243fULL) << 13);
    acc = (acc + a1 + 0xaa0003e8ULL) ^ 0x0bc770ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0152 | PC: 0x018fd8 | FDE: 0x0bc788 | Size: 256 bytes
// Hàm FDE #0152 | Địa chỉ PC: 0x018fd8 | Địa chỉ FDE: 0x0bc788 | Kích thước: 256 bytes
//   0x018fd8: F9400409  ldr      x9, [x0, #8]
//   0x018fdc: F940042A  ldr      x10, [x1, #8]
//   0x018fe0: 9E670120  fmov     d0, x9
//   0x018fe4: 0E205800  cnt      v0.8b, v0.8b
static inline uint64_t fde_func_0152_0x018fd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x018fd8ULL ^ (static_cast<uint64_t>(0xf9400409ULL) << 13);
    acc = (acc + a1 + 0xf940042aULL) ^ 0x0bc788ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0153 | PC: 0x019124 | FDE: 0x0bca70 | Size: 256 bytes
// Hàm FDE #0153 | Địa chỉ PC: 0x019124 | Địa chỉ FDE: 0x0bca70 | Kích thước: 256 bytes
//   0x019124: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x019128: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x01912c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x019130: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0153_0x019124(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x019124ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0bca70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0154 | PC: 0x01923c | FDE: 0x0bc7a0 | Size: 48 bytes
// Hàm FDE #0154 | Địa chỉ PC: 0x01923c | Địa chỉ FDE: 0x0bc7a0 | Kích thước: 48 bytes
//   0x01923c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x019240: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x019244: 910043FD  add      x29, sp, #0x10
//   0x019248: F0000668  adrp     x8, #0xe8000
static inline uint64_t fde_func_0154_0x01923c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01923cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bc7a0ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0155 | PC: 0x01926c | FDE: 0x0bc7c0 | Size: 56 bytes
// Hàm FDE #0155 | Địa chỉ PC: 0x01926c | Địa chỉ FDE: 0x0bc7c0 | Kích thước: 56 bytes
//   0x01926c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x019270: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x019274: 910043FD  add      x29, sp, #0x10
//   0x019278: F0000668  adrp     x8, #0xe8000
static inline uint64_t fde_func_0155_0x01926c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01926cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bc7c0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0156 | PC: 0x0192a4 | FDE: 0x0bc7e0 | Size: 12 bytes
// Hàm FDE #0156 | Địa chỉ PC: 0x0192a4 | Địa chỉ FDE: 0x0bc7e0 | Kích thước: 12 bytes
//   0x0192a4: F8418C08  ldr      x8, [x0, #0x18]!
//   0x0192a8: F9400101  ldr      x1, [x8]
//   0x0192ac: D61F0020  br       x1
static inline uint64_t fde_func_0156_0x0192a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0192a4ULL ^ (static_cast<uint64_t>(0xf8418c08ULL) << 13);
    acc = (acc + a1 + 0xf9400101ULL) ^ 0x0bc7e0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0157 | PC: 0x0192b0 | FDE: 0x0bc7f8 | Size: 4 bytes
// Hàm FDE #0157 | Địa chỉ PC: 0x0192b0 | Địa chỉ FDE: 0x0bc7f8 | Kích thước: 4 bytes
//   0x0192b0: 17FFE554  b        #0x12800
static inline uint64_t fde_func_0157_0x0192b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0192b0ULL ^ (static_cast<uint64_t>(0x17ffe554ULL) << 13);
    acc = (acc + a1 + 0xd10203ffULL) ^ 0x0bc7f8ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0158 | PC: 0x0192b4 | FDE: 0x0bcaa0 | Size: 256 bytes
// Hàm FDE #0158 | Địa chỉ PC: 0x0192b4 | Địa chỉ FDE: 0x0bcaa0 | Kích thước: 256 bytes
//   0x0192b4: D10203FF  sub      sp, sp, #0x80
//   0x0192b8: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0192bc: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0192c0: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0158_0x0192b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0192b4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x0bcaa0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0159 | PC: 0x0195ec | FDE: 0x0bc810 | Size: 228 bytes
// Hàm FDE #0159 | Địa chỉ PC: 0x0195ec | Địa chỉ FDE: 0x0bc810 | Kích thước: 228 bytes
//   0x0195ec: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0195f0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0195f4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0195f8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0159_0x0195ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0195ecULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bc810ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #0160 | PC: 0x0196d0 | FDE: 0x0bc830 | Size: 256 bytes
// Hàm FDE #0160 | Địa chỉ PC: 0x0196d0 | Địa chỉ FDE: 0x0bc830 | Kích thước: 256 bytes
//   0x0196d0: D10203FF  sub      sp, sp, #0x80
//   0x0196d4: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0196d8: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0196dc: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0160_0x0196d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0196d0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x0bc830ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0161 | PC: 0x019940 | FDE: 0x0bcad8 | Size: 220 bytes
// Hàm FDE #0161 | Địa chỉ PC: 0x019940 | Địa chỉ FDE: 0x0bcad8 | Kích thước: 220 bytes
//   0x019940: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x019944: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x019948: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x01994c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0161_0x019940(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x019940ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0bcad8ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #0162 | PC: 0x019a1c | FDE: 0x0bc860 | Size: 156 bytes
// Hàm FDE #0162 | Địa chỉ PC: 0x019a1c | Địa chỉ FDE: 0x0bc860 | Kích thước: 156 bytes
//   0x019a1c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x019a20: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x019a24: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x019a28: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0162_0x019a1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x019a1cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bc860ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0163 | PC: 0x019ab8 | FDE: 0x0bc888 | Size: 20 bytes
// Hàm FDE #0163 | Địa chỉ PC: 0x019ab8 | Địa chỉ FDE: 0x0bc888 | Kích thước: 20 bytes
//   0x019ab8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x019abc: 910003FD  mov      x29, sp
//   0x019ac0: 900004A0  adrp     x0, #0xad000
//   0x019ac4: 9100AC00  add      x0, x0, #0x2b
static inline uint64_t fde_func_0163_0x019ab8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x019ab8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0bc888ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0164 | PC: 0x019acc | FDE: 0x0bcb08 | Size: 164 bytes
// Hàm FDE #0164 | Địa chỉ PC: 0x019acc | Địa chỉ FDE: 0x0bcb08 | Kích thước: 164 bytes
//   0x019acc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x019ad0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x019ad4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x019ad8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0164_0x019acc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x019accULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bcb08ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #0165 | PC: 0x019b70 | FDE: 0x0bcb30 | Size: 152 bytes
// Hàm FDE #0165 | Địa chỉ PC: 0x019b70 | Địa chỉ FDE: 0x0bcb30 | Kích thước: 152 bytes
//   0x019b70: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x019b74: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x019b78: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x019b7c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0165_0x019b70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x019b70ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bcb30ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0166 | PC: 0x019c08 | FDE: 0x0bcb58 | Size: 20 bytes
// Hàm FDE #0166 | Địa chỉ PC: 0x019c08 | Địa chỉ FDE: 0x0bcb58 | Kích thước: 20 bytes
//   0x019c08: 39400008  ldrb     w8, [x0]
//   0x019c0c: 37000048  tbnz     w8, #0, #0x19c14
//   0x019c10: D65F03C0  ret      
//   0x019c14: F9400800  ldr      x0, [x0, #0x10]
static inline uint64_t fde_func_0166_0x019c08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x019c08ULL ^ (static_cast<uint64_t>(0x39400008ULL) << 13);
    acc = (acc + a1 + 0x37000048ULL) ^ 0x0bcb58ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0167 | PC: 0x019c1c | FDE: 0x0bd5c0 | Size: 256 bytes
// Hàm FDE #0167 | Địa chỉ PC: 0x019c1c | Địa chỉ FDE: 0x0bd5c0 | Kích thước: 256 bytes
//   0x019c1c: D10343FF  sub      sp, sp, #0xd0
//   0x019c20: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x019c24: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x019c28: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_0167_0x019c1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x019c1cULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9076ffcULL) ^ 0x0bd5c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0168 | PC: 0x01a478 | FDE: 0x0bcb70 | Size: 88 bytes
// Hàm FDE #0168 | Địa chỉ PC: 0x01a478 | Địa chỉ FDE: 0x0bcb70 | Kích thước: 88 bytes
//   0x01a478: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01a47c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01a480: 910043FD  add      x29, sp, #0x10
//   0x01a484: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_0168_0x01a478(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01a478ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bcb70ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0169 | PC: 0x01a4d0 | FDE: 0x0bcb90 | Size: 60 bytes
// Hàm FDE #0169 | Địa chỉ PC: 0x01a4d0 | Địa chỉ FDE: 0x0bcb90 | Kích thước: 60 bytes
//   0x01a4d0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01a4d4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01a4d8: 910043FD  add      x29, sp, #0x10
//   0x01a4dc: F9400801  ldr      x1, [x0, #0x10]
static inline uint64_t fde_func_0169_0x01a4d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01a4d0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bcb90ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0170 | PC: 0x01a50c | FDE: 0x0bcbb0 | Size: 88 bytes
// Hàm FDE #0170 | Địa chỉ PC: 0x01a50c | Địa chỉ FDE: 0x0bcbb0 | Kích thước: 88 bytes
//   0x01a50c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01a510: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01a514: 910043FD  add      x29, sp, #0x10
//   0x01a518: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_0170_0x01a50c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01a50cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bcbb0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0171 | PC: 0x01a564 | FDE: 0x0bcbd0 | Size: 88 bytes
// Hàm FDE #0171 | Địa chỉ PC: 0x01a564 | Địa chỉ FDE: 0x0bcbd0 | Kích thước: 88 bytes
//   0x01a564: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01a568: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01a56c: 910043FD  add      x29, sp, #0x10
//   0x01a570: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_0171_0x01a564(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01a564ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bcbd0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0172 | PC: 0x01a5bc | FDE: 0x0bcbf0 | Size: 88 bytes
// Hàm FDE #0172 | Địa chỉ PC: 0x01a5bc | Địa chỉ FDE: 0x0bcbf0 | Kích thước: 88 bytes
//   0x01a5bc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01a5c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01a5c4: 910043FD  add      x29, sp, #0x10
//   0x01a5c8: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_0172_0x01a5bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01a5bcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bcbf0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0173 | PC: 0x01a614 | FDE: 0x0bcc10 | Size: 88 bytes
// Hàm FDE #0173 | Địa chỉ PC: 0x01a614 | Địa chỉ FDE: 0x0bcc10 | Kích thước: 88 bytes
//   0x01a614: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01a618: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01a61c: 910043FD  add      x29, sp, #0x10
//   0x01a620: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_0173_0x01a614(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01a614ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bcc10ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0174 | PC: 0x01a66c | FDE: 0x0bcc30 | Size: 16 bytes
// Hàm FDE #0174 | Địa chỉ PC: 0x01a66c | Địa chỉ FDE: 0x0bcc30 | Kích thước: 16 bytes
//   0x01a66c: F9400400  ldr      x0, [x0, #8]
//   0x01a670: B4000040  cbz      x0, #0x1a678
//   0x01a674: 17FFE1DF  b        #0x12df0
//   0x01a678: D65F03C0  ret      
static inline uint64_t fde_func_0174_0x01a66c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01a66cULL ^ (static_cast<uint64_t>(0xf9400400ULL) << 13);
    acc = (acc + a1 + 0xb4000040ULL) ^ 0x0bcc30ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0175 | PC: 0x01a67c | FDE: 0x0bd5f8 | Size: 256 bytes
// Hàm FDE #0175 | Địa chỉ PC: 0x01a67c | Địa chỉ FDE: 0x0bd5f8 | Kích thước: 256 bytes
//   0x01a67c: D10183FF  sub      sp, sp, #0x60
//   0x01a680: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x01a684: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x01a688: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0175_0x01a67c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01a67cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x0bd5f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0176 | PC: 0x01aa88 | FDE: 0x0bcc48 | Size: 8 bytes
// Hàm FDE #0176 | Địa chỉ PC: 0x01aa88 | Địa chỉ FDE: 0x0bcc48 | Kích thước: 8 bytes
//   0x01aa88: D1002000  sub      x0, x0, #8
//   0x01aa8c: 17FFFEFC  b        #0x1a67c
static inline uint64_t fde_func_0176_0x01aa88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01aa88ULL ^ (static_cast<uint64_t>(0xd1002000ULL) << 13);
    acc = (acc + a1 + 0x17fffefcULL) ^ 0x0bcc48ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0177 | PC: 0x01aa90 | FDE: 0x0bcc60 | Size: 36 bytes
// Hàm FDE #0177 | Địa chỉ PC: 0x01aa90 | Địa chỉ FDE: 0x0bcc60 | Kích thước: 36 bytes
//   0x01aa90: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01aa94: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01aa98: 910043FD  add      x29, sp, #0x10
//   0x01aa9c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0177_0x01aa90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01aa90ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bcc60ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0178 | PC: 0x01aab4 | FDE: 0x0bcc80 | Size: 40 bytes
// Hàm FDE #0178 | Địa chỉ PC: 0x01aab4 | Địa chỉ FDE: 0x0bcc80 | Kích thước: 40 bytes
//   0x01aab4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01aab8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01aabc: 910043FD  add      x29, sp, #0x10
//   0x01aac0: D1002013  sub      x19, x0, #8
static inline uint64_t fde_func_0178_0x01aab4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01aab4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bcc80ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0179 | PC: 0x01aadc | FDE: 0x0bcca0 | Size: 20 bytes
// Hàm FDE #0179 | Địa chỉ PC: 0x01aadc | Địa chỉ FDE: 0x0bcca0 | Kích thước: 20 bytes
//   0x01aadc: 91018008  add      x8, x0, #0x60
//   0x01aae0: 91012009  add      x9, x0, #0x48
//   0x01aae4: 7200003F  tst      w1, #1
//   0x01aae8: 9A891100  csel     x0, x8, x9, ne
static inline uint64_t fde_func_0179_0x01aadc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01aadcULL ^ (static_cast<uint64_t>(0x91018008ULL) << 13);
    acc = (acc + a1 + 0x91012009ULL) ^ 0x0bcca0ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0180 | PC: 0x01aaf0 | FDE: 0x0bd628 | Size: 256 bytes
// Hàm FDE #0180 | Địa chỉ PC: 0x01aaf0 | Địa chỉ FDE: 0x0bd628 | Kích thước: 256 bytes
//   0x01aaf0: D10103FF  sub      sp, sp, #0x40
//   0x01aaf4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x01aaf8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x01aafc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0180_0x01aaf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01aaf0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0bd628ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0181 | PC: 0x01ad8c | FDE: 0x0bd658 | Size: 256 bytes
// Hàm FDE #0181 | Địa chỉ PC: 0x01ad8c | Địa chỉ FDE: 0x0bd658 | Kích thước: 256 bytes
//   0x01ad8c: D101C3FF  sub      sp, sp, #0x70
//   0x01ad90: F90013F9  str      x25, [sp, #0x20]
//   0x01ad94: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x01ad98: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0181_0x01ad8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01ad8cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x0bd658ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0182 | PC: 0x01b064 | FDE: 0x0bd688 | Size: 256 bytes
// Hàm FDE #0182 | Địa chỉ PC: 0x01b064 | Địa chỉ FDE: 0x0bd688 | Kích thước: 256 bytes
//   0x01b064: F81C0FFC  str      x28, [sp, #-0x40]!
//   0x01b068: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x01b06c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x01b070: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0182_0x01b064(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01b064ULL ^ (static_cast<uint64_t>(0xf81c0ffcULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0bd688ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0183 | PC: 0x01b6b0 | FDE: 0x0bd6b8 | Size: 256 bytes
// Hàm FDE #0183 | Địa chỉ PC: 0x01b6b0 | Địa chỉ FDE: 0x0bd6b8 | Kích thước: 256 bytes
//   0x01b6b0: D10603FF  sub      sp, sp, #0x180
//   0x01b6b4: A9126FFC  stp      x28, x27, [sp, #0x120]
//   0x01b6b8: A91367FA  stp      x26, x25, [sp, #0x130]
//   0x01b6bc: A9145FF8  stp      x24, x23, [sp, #0x140]
static inline uint64_t fde_func_0183_0x01b6b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01b6b0ULL ^ (static_cast<uint64_t>(0xd10603ffULL) << 13);
    acc = (acc + a1 + 0xa9126ffcULL) ^ 0x0bd6b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0184 | PC: 0x01c1d0 | FDE: 0x0bccb8 | Size: 256 bytes [_ZN4nuro11UserMessageD2Ev]
// Hàm FDE #0184 | Địa chỉ PC: 0x01c1d0 | Địa chỉ FDE: 0x0bccb8 | Kích thước: 256 bytes
//   0x01c1d0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x01c1d4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x01c1d8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x01c1dc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0184_0x01c1d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01c1d0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bccb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0185 | PC: 0x01c330 | FDE: 0x0bd6f0 | Size: 256 bytes
// Hàm FDE #0185 | Địa chỉ PC: 0x01c330 | Địa chỉ FDE: 0x0bd6f0 | Kích thước: 256 bytes
//   0x01c330: F81C0FFC  str      x28, [sp, #-0x40]!
//   0x01c334: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x01c338: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x01c33c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0185_0x01c330(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01c330ULL ^ (static_cast<uint64_t>(0xf81c0ffcULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0bd6f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0186 | PC: 0x01cb3c | FDE: 0x0bccd8 | Size: 120 bytes
// Hàm FDE #0186 | Địa chỉ PC: 0x01cb3c | Địa chỉ FDE: 0x0bccd8 | Kích thước: 120 bytes
//   0x01cb3c: D10103FF  sub      sp, sp, #0x40
//   0x01cb40: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x01cb44: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x01cb48: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0186_0x01cb3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01cb3cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x0bccd8ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0187 | PC: 0x01cbb4 | FDE: 0x0bd720 | Size: 256 bytes
// Hàm FDE #0187 | Địa chỉ PC: 0x01cbb4 | Địa chỉ FDE: 0x0bd720 | Kích thước: 256 bytes
//   0x01cbb4: F81C0FFC  str      x28, [sp, #-0x40]!
//   0x01cbb8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x01cbbc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x01cbc0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0187_0x01cbb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01cbb4ULL ^ (static_cast<uint64_t>(0xf81c0ffcULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0bd720ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0188 | PC: 0x01d3c0 | FDE: 0x0bd750 | Size: 256 bytes
// Hàm FDE #0188 | Địa chỉ PC: 0x01d3c0 | Địa chỉ FDE: 0x0bd750 | Kích thước: 256 bytes
//   0x01d3c0: F81C0FFC  str      x28, [sp, #-0x40]!
//   0x01d3c4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x01d3c8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x01d3cc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0188_0x01d3c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01d3c0ULL ^ (static_cast<uint64_t>(0xf81c0ffcULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0bd750ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0189 | PC: 0x01d988 | FDE: 0x0bd780 | Size: 256 bytes
// Hàm FDE #0189 | Địa chỉ PC: 0x01d988 | Địa chỉ FDE: 0x0bd780 | Kích thước: 256 bytes
//   0x01d988: D104C3FF  sub      sp, sp, #0x130
//   0x01d98c: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x01d990: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x01d994: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0189_0x01d988(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01d988ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x0bd780ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0190 | PC: 0x01e098 | FDE: 0x0bccf8 | Size: 132 bytes
// Hàm FDE #0190 | Địa chỉ PC: 0x01e098 | Địa chỉ FDE: 0x0bccf8 | Kích thước: 132 bytes
//   0x01e098: D10103FF  sub      sp, sp, #0x40
//   0x01e09c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x01e0a0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x01e0a4: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0190_0x01e098(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01e098ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x0bccf8ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0191 | PC: 0x01e11c | FDE: 0x0bd7b8 | Size: 256 bytes
// Hàm FDE #0191 | Địa chỉ PC: 0x01e11c | Địa chỉ FDE: 0x0bd7b8 | Kích thước: 256 bytes
//   0x01e11c: D10303FF  sub      sp, sp, #0xc0
//   0x01e120: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x01e124: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x01e128: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_0191_0x01e11c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01e11cULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x0bd7b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0192 | PC: 0x01e780 | FDE: 0x0bd7f0 | Size: 256 bytes
// Hàm FDE #0192 | Địa chỉ PC: 0x01e780 | Địa chỉ FDE: 0x0bd7f0 | Kích thước: 256 bytes
//   0x01e780: D10483FF  sub      sp, sp, #0x120
//   0x01e784: F90063FC  str      x28, [sp, #0xc0]
//   0x01e788: A90D67FA  stp      x26, x25, [sp, #0xd0]
//   0x01e78c: A90E5FF8  stp      x24, x23, [sp, #0xe0]
static inline uint64_t fde_func_0192_0x01e780(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01e780ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xf90063fcULL) ^ 0x0bd7f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0193 | PC: 0x01eef0 | FDE: 0x0bcd18 | Size: 124 bytes
// Hàm FDE #0193 | Địa chỉ PC: 0x01eef0 | Địa chỉ FDE: 0x0bcd18 | Kích thước: 124 bytes
//   0x01eef0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01eef4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01eef8: 910043FD  add      x29, sp, #0x10
//   0x01eefc: 9100B008  add      x8, x0, #0x2c
static inline uint64_t fde_func_0193_0x01eef0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01eef0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bcd18ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0194 | PC: 0x01ef6c | FDE: 0x0bd828 | Size: 256 bytes
// Hàm FDE #0194 | Địa chỉ PC: 0x01ef6c | Địa chỉ FDE: 0x0bd828 | Kích thước: 256 bytes
//   0x01ef6c: D10443FF  sub      sp, sp, #0x110
//   0x01ef70: A90B6FFC  stp      x28, x27, [sp, #0xb0]
//   0x01ef74: A90C67FA  stp      x26, x25, [sp, #0xc0]
//   0x01ef78: A90D5FF8  stp      x24, x23, [sp, #0xd0]
static inline uint64_t fde_func_0194_0x01ef6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01ef6cULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90b6ffcULL) ^ 0x0bd828ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0195 | PC: 0x01f4a4 | FDE: 0x0bcd38 | Size: 124 bytes
// Hàm FDE #0195 | Địa chỉ PC: 0x01f4a4 | Địa chỉ FDE: 0x0bcd38 | Kích thước: 124 bytes
//   0x01f4a4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x01f4a8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x01f4ac: 910043FD  add      x29, sp, #0x10
//   0x01f4b0: 9100B008  add      x8, x0, #0x2c
static inline uint64_t fde_func_0195_0x01f4a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01f4a4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bcd38ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0196 | PC: 0x01f520 | FDE: 0x0bd860 | Size: 256 bytes
// Hàm FDE #0196 | Địa chỉ PC: 0x01f520 | Địa chỉ FDE: 0x0bd860 | Kích thước: 256 bytes
//   0x01f520: D10283FF  sub      sp, sp, #0xa0
//   0x01f524: F9003BF5  str      x21, [sp, #0x70]
//   0x01f528: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x01f52c: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_0196_0x01f520(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01f520ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf5ULL) ^ 0x0bd860ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0197 | PC: 0x01f65c | FDE: 0x0bd888 | Size: 256 bytes
// Hàm FDE #0197 | Địa chỉ PC: 0x01f65c | Địa chỉ FDE: 0x0bd888 | Kích thước: 256 bytes
//   0x01f65c: D101C3FF  sub      sp, sp, #0x70
//   0x01f660: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x01f664: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x01f668: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0197_0x01f65c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01f65cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x0bd888ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0198 | PC: 0x01f924 | FDE: 0x0bd8b8 | Size: 256 bytes
// Hàm FDE #0198 | Địa chỉ PC: 0x01f924 | Địa chỉ FDE: 0x0bd8b8 | Kích thước: 256 bytes
//   0x01f924: D10683FF  sub      sp, sp, #0x1a0
//   0x01f928: A9146FFC  stp      x28, x27, [sp, #0x140]
//   0x01f92c: A91567FA  stp      x26, x25, [sp, #0x150]
//   0x01f930: A9165FF8  stp      x24, x23, [sp, #0x160]
static inline uint64_t fde_func_0198_0x01f924(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x01f924ULL ^ (static_cast<uint64_t>(0xd10683ffULL) << 13);
    acc = (acc + a1 + 0xa9146ffcULL) ^ 0x0bd8b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0199 | PC: 0x020f40 | FDE: 0x0bcd58 | Size: 8 bytes
// Hàm FDE #0199 | Địa chỉ PC: 0x020f40 | Địa chỉ FDE: 0x0bcd58 | Kích thước: 8 bytes
//   0x020f40: D1002000  sub      x0, x0, #8
//   0x020f44: 17FFF9C6  b        #0x1f65c
static inline uint64_t fde_func_0199_0x020f40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x020f40ULL ^ (static_cast<uint64_t>(0xd1002000ULL) << 13);
    acc = (acc + a1 + 0x17fff9c6ULL) ^ 0x0bcd58ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0200 | PC: 0x020f48 | FDE: 0x0bcd70 | Size: 16 bytes
// Hàm FDE #0200 | Địa chỉ PC: 0x020f48 | Địa chỉ FDE: 0x0bcd70 | Kích thước: 16 bytes
//   0x020f48: F9405800  ldr      x0, [x0, #0xb0]
//   0x020f4c: B4000040  cbz      x0, #0x20f54
//   0x020f50: 140065E2  b        #0x3a6d8
//   0x020f54: D65F03C0  ret      
static inline uint64_t fde_func_0200_0x020f48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x020f48ULL ^ (static_cast<uint64_t>(0xf9405800ULL) << 13);
    acc = (acc + a1 + 0xb4000040ULL) ^ 0x0bcd70ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0201 | PC: 0x020f58 | FDE: 0x0bcd88 | Size: 140 bytes
// Hàm FDE #0201 | Địa chỉ PC: 0x020f58 | Địa chỉ FDE: 0x0bcd88 | Kích thước: 140 bytes
//   0x020f58: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x020f5c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x020f60: 910043FD  add      x29, sp, #0x10
//   0x020f64: 2A0103F3  mov      w19, w1
static inline uint64_t fde_func_0201_0x020f58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x020f58ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bcd88ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0202 | PC: 0x020fe4 | FDE: 0x0bd8f0 | Size: 256 bytes
// Hàm FDE #0202 | Địa chỉ PC: 0x020fe4 | Địa chỉ FDE: 0x0bd8f0 | Kích thước: 256 bytes
//   0x020fe4: D10243FF  sub      sp, sp, #0x90
//   0x020fe8: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x020fec: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x020ff0: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0202_0x020fe4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x020fe4ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x0bd8f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0203 | PC: 0x0213e8 | FDE: 0x0bd928 | Size: 256 bytes
// Hàm FDE #0203 | Địa chỉ PC: 0x0213e8 | Địa chỉ FDE: 0x0bd928 | Kích thước: 256 bytes
//   0x0213e8: D103C3FF  sub      sp, sp, #0xf0
//   0x0213ec: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x0213f0: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x0213f4: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_0203_0x0213e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0213e8ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa9096ffcULL) ^ 0x0bd928ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0204 | PC: 0x021aa8 | FDE: 0x0bcda8 | Size: 256 bytes
// Hàm FDE #0204 | Địa chỉ PC: 0x021aa8 | Địa chỉ FDE: 0x0bcda8 | Kích thước: 256 bytes
//   0x021aa8: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x021aac: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x021ab0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x021ab4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0204_0x021aa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x021aa8ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0bcda8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0205 | PC: 0x021bf0 | FDE: 0x0bd960 | Size: 256 bytes
// Hàm FDE #0205 | Địa chỉ PC: 0x021bf0 | Địa chỉ FDE: 0x0bd960 | Kích thước: 256 bytes
//   0x021bf0: D10243FF  sub      sp, sp, #0x90
//   0x021bf4: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x021bf8: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x021bfc: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0205_0x021bf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x021bf0ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x0bd960ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0206 | PC: 0x021e6c | FDE: 0x0bd998 | Size: 256 bytes
// Hàm FDE #0206 | Địa chỉ PC: 0x021e6c | Địa chỉ FDE: 0x0bd998 | Kích thước: 256 bytes
//   0x021e6c: D10303FF  sub      sp, sp, #0xc0
//   0x021e70: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x021e74: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x021e78: A90957F6  stp      x22, x21, [sp, #0x90]
static inline uint64_t fde_func_0206_0x021e6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x021e6cULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa90767faULL) ^ 0x0bd998ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0207 | PC: 0x0220d0 | FDE: 0x0bd9d0 | Size: 188 bytes
// Hàm FDE #0207 | Địa chỉ PC: 0x0220d0 | Địa chỉ FDE: 0x0bd9d0 | Kích thước: 188 bytes
//   0x0220d0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0220d4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0220d8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0220dc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0207_0x0220d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0220d0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bd9d0ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0208 | PC: 0x02218c | FDE: 0x0bd9f8 | Size: 256 bytes [_ZN4nuro7ContextC2ERKS0_]
// Hàm FDE #0208 | Địa chỉ PC: 0x02218c | Địa chỉ FDE: 0x0bd9f8 | Kích thước: 256 bytes
//   0x02218c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x022190: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x022194: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x022198: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0208_0x02218c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02218cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0bd9f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0209 | PC: 0x0223fc | FDE: 0x0bda28 | Size: 256 bytes
// Hàm FDE #0209 | Địa chỉ PC: 0x0223fc | Địa chỉ FDE: 0x0bda28 | Kích thước: 256 bytes
//   0x0223fc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x022400: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x022404: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x022408: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0209_0x0223fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0223fcULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bda28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0210 | PC: 0x022520 | FDE: 0x0bda58 | Size: 240 bytes
// Hàm FDE #0210 | Địa chỉ PC: 0x022520 | Địa chỉ FDE: 0x0bda58 | Kích thước: 240 bytes
//   0x022520: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x022524: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x022528: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x02252c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0210_0x022520(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x022520ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bda58ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #0211 | PC: 0x022610 | FDE: 0x0bda88 | Size: 236 bytes [_ZN4nuro8FileInfoC2ERKS0_]
// Hàm FDE #0211 | Địa chỉ PC: 0x022610 | Địa chỉ FDE: 0x0bda88 | Kích thước: 236 bytes
//   0x022610: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x022614: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x022618: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x02261c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0211_0x022610(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x022610ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0bda88ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0212 | PC: 0x0226fc | FDE: 0x0bcdd0 | Size: 160 bytes
// Hàm FDE #0212 | Địa chỉ PC: 0x0226fc | Địa chỉ FDE: 0x0bcdd0 | Kích thước: 160 bytes
//   0x0226fc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x022700: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x022704: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x022708: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0212_0x0226fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0226fcULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bcdd0ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0213 | PC: 0x02279c | FDE: 0x0bcdf8 | Size: 256 bytes [_ZN4nuro7ContextD2Ev]
// Hàm FDE #0213 | Địa chỉ PC: 0x02279c | Địa chỉ FDE: 0x0bcdf8 | Kích thước: 256 bytes
//   0x02279c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0227a0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0227a4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0227a8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0213_0x02279c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02279cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bcdf8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0214 | PC: 0x0228c0 | FDE: 0x0bdab8 | Size: 256 bytes [_ZN4nuro10ToolResultC2ERKS0_]
// Hàm FDE #0214 | Địa chỉ PC: 0x0228c0 | Địa chỉ FDE: 0x0bdab8 | Kích thước: 256 bytes
//   0x0228c0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0228c4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0228c8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0228cc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0214_0x0228c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0228c0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bdab8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0215 | PC: 0x0229d4 | FDE: 0x0bdae8 | Size: 228 bytes
// Hàm FDE #0215 | Địa chỉ PC: 0x0229d4 | Địa chỉ FDE: 0x0bdae8 | Kích thước: 228 bytes
//   0x0229d4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0229d8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0229dc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0229e0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0215_0x0229d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0229d4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bdae8ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #0216 | PC: 0x022ab8 | FDE: 0x0bdb18 | Size: 256 bytes [_ZN4nuro14ToolCallResultC2ERKS0_]
// Hàm FDE #0216 | Địa chỉ PC: 0x022ab8 | Địa chỉ FDE: 0x0bdb18 | Kích thước: 256 bytes
//   0x022ab8: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x022abc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x022ac0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x022ac4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0216_0x022ab8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x022ab8ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0bdb18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0217 | PC: 0x022bd0 | FDE: 0x0bce18 | Size: 148 bytes
// Hàm FDE #0217 | Địa chỉ PC: 0x022bd0 | Địa chỉ FDE: 0x0bce18 | Kích thước: 148 bytes
//   0x022bd0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x022bd4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x022bd8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x022bdc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0217_0x022bd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x022bd0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bce18ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0218 | PC: 0x022c64 | FDE: 0x0bce40 | Size: 152 bytes
// Hàm FDE #0218 | Địa chỉ PC: 0x022c64 | Địa chỉ FDE: 0x0bce40 | Kích thước: 152 bytes
//   0x022c64: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x022c68: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x022c6c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x022c70: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0218_0x022c64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x022c64ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bce40ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0219 | PC: 0x022cfc | FDE: 0x0bce60 | Size: 48 bytes
// Hàm FDE #0219 | Địa chỉ PC: 0x022cfc | Địa chỉ FDE: 0x0bce60 | Kích thước: 48 bytes
//   0x022cfc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x022d00: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x022d04: 910043FD  add      x29, sp, #0x10
//   0x022d08: D0000628  adrp     x8, #0xe8000
static inline uint64_t fde_func_0219_0x022cfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x022cfcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bce60ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0220 | PC: 0x022d2c | FDE: 0x0bce80 | Size: 56 bytes
// Hàm FDE #0220 | Địa chỉ PC: 0x022d2c | Địa chỉ FDE: 0x0bce80 | Kích thước: 56 bytes
//   0x022d2c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x022d30: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x022d34: 910043FD  add      x29, sp, #0x10
//   0x022d38: D0000628  adrp     x8, #0xe8000
static inline uint64_t fde_func_0220_0x022d2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x022d2cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bce80ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0221 | PC: 0x022d64 | FDE: 0x0bcea0 | Size: 8 bytes
// Hàm FDE #0221 | Địa chỉ PC: 0x022d64 | Địa chỉ FDE: 0x0bcea0 | Kích thước: 8 bytes
//   0x022d64: 91006000  add      x0, x0, #0x18
//   0x022d68: 1400453E  b        #0x34260
static inline uint64_t fde_func_0221_0x022d64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x022d64ULL ^ (static_cast<uint64_t>(0x91006000ULL) << 13);
    acc = (acc + a1 + 0x1400453eULL) ^ 0x0bcea0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0222 | PC: 0x022d6c | FDE: 0x0bceb8 | Size: 4 bytes
// Hàm FDE #0222 | Địa chỉ PC: 0x022d6c | Địa chỉ FDE: 0x0bceb8 | Kích thước: 4 bytes
//   0x022d6c: 17FFBEA5  b        #0x12800
static inline uint64_t fde_func_0222_0x022d6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x022d6cULL ^ (static_cast<uint64_t>(0x17ffbea5ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x0bceb8ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0223 | PC: 0x022d70 | FDE: 0x0bced0 | Size: 48 bytes
// Hàm FDE #0223 | Địa chỉ PC: 0x022d70 | Địa chỉ FDE: 0x0bced0 | Kích thước: 48 bytes
//   0x022d70: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x022d74: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x022d78: 910043FD  add      x29, sp, #0x10
//   0x022d7c: D0000628  adrp     x8, #0xe8000
static inline uint64_t fde_func_0223_0x022d70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x022d70ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bced0ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0224 | PC: 0x022da0 | FDE: 0x0bcef0 | Size: 56 bytes
// Hàm FDE #0224 | Địa chỉ PC: 0x022da0 | Địa chỉ FDE: 0x0bcef0 | Kích thước: 56 bytes
//   0x022da0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x022da4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x022da8: 910043FD  add      x29, sp, #0x10
//   0x022dac: D0000628  adrp     x8, #0xe8000
static inline uint64_t fde_func_0224_0x022da0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x022da0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bcef0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0225 | PC: 0x022dd8 | FDE: 0x0bcf10 | Size: 8 bytes
// Hàm FDE #0225 | Địa chỉ PC: 0x022dd8 | Địa chỉ FDE: 0x0bcf10 | Kích thước: 8 bytes
//   0x022dd8: 91006000  add      x0, x0, #0x18
//   0x022ddc: 14014D31  b        #0x762a0
static inline uint64_t fde_func_0225_0x022dd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x022dd8ULL ^ (static_cast<uint64_t>(0x91006000ULL) << 13);
    acc = (acc + a1 + 0x14014d31ULL) ^ 0x0bcf10ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0226 | PC: 0x022de0 | FDE: 0x0bcf28 | Size: 4 bytes
// Hàm FDE #0226 | Địa chỉ PC: 0x022de0 | Địa chỉ FDE: 0x0bcf28 | Kích thước: 4 bytes
//   0x022de0: 17FFBE88  b        #0x12800
static inline uint64_t fde_func_0226_0x022de0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x022de0ULL ^ (static_cast<uint64_t>(0x17ffbe88ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x0bcf28ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0227 | PC: 0x022de4 | FDE: 0x0bcf40 | Size: 48 bytes
// Hàm FDE #0227 | Địa chỉ PC: 0x022de4 | Địa chỉ FDE: 0x0bcf40 | Kích thước: 48 bytes
//   0x022de4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x022de8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x022dec: 910043FD  add      x29, sp, #0x10
//   0x022df0: D0000628  adrp     x8, #0xe8000
static inline uint64_t fde_func_0227_0x022de4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x022de4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bcf40ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0228 | PC: 0x022e14 | FDE: 0x0bcf60 | Size: 56 bytes
// Hàm FDE #0228 | Địa chỉ PC: 0x022e14 | Địa chỉ FDE: 0x0bcf60 | Kích thước: 56 bytes
//   0x022e14: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x022e18: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x022e1c: 910043FD  add      x29, sp, #0x10
//   0x022e20: D0000628  adrp     x8, #0xe8000
static inline uint64_t fde_func_0228_0x022e14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x022e14ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bcf60ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0229 | PC: 0x022e4c | FDE: 0x0bcf80 | Size: 12 bytes
// Hàm FDE #0229 | Địa chỉ PC: 0x022e4c | Địa chỉ FDE: 0x0bcf80 | Kích thước: 12 bytes
//   0x022e4c: F8418C08  ldr      x8, [x0, #0x18]!
//   0x022e50: F9400101  ldr      x1, [x8]
//   0x022e54: D61F0020  br       x1
static inline uint64_t fde_func_0229_0x022e4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x022e4cULL ^ (static_cast<uint64_t>(0xf8418c08ULL) << 13);
    acc = (acc + a1 + 0xf9400101ULL) ^ 0x0bcf80ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0230 | PC: 0x022e58 | FDE: 0x0bcf98 | Size: 4 bytes
// Hàm FDE #0230 | Địa chỉ PC: 0x022e58 | Địa chỉ FDE: 0x0bcf98 | Kích thước: 4 bytes
//   0x022e58: 17FFBE6A  b        #0x12800
static inline uint64_t fde_func_0230_0x022e58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x022e58ULL ^ (static_cast<uint64_t>(0x17ffbe6aULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x0bcf98ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0231 | PC: 0x022e5c | FDE: 0x0bcfb0 | Size: 52 bytes
// Hàm FDE #0231 | Địa chỉ PC: 0x022e5c | Địa chỉ FDE: 0x0bcfb0 | Kích thước: 52 bytes
//   0x022e5c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x022e60: 910003FD  mov      x29, sp
//   0x022e64: 52800100  mov      w0, #8
//   0x022e68: 97FFBE92  bl       #0x128b0
static inline uint64_t fde_func_0231_0x022e5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x022e5cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0bcfb0ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0232 | PC: 0x022e90 | FDE: 0x0bdb48 | Size: 256 bytes
// Hàm FDE #0232 | Địa chỉ PC: 0x022e90 | Địa chỉ FDE: 0x0bdb48 | Kích thước: 256 bytes
//   0x022e90: D10183FF  sub      sp, sp, #0x60
//   0x022e94: F90013F7  str      x23, [sp, #0x20]
//   0x022e98: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x022e9c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0232_0x022e90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x022e90ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x0bdb48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0233 | PC: 0x022fcc | FDE: 0x0bcfd0 | Size: 48 bytes
// Hàm FDE #0233 | Địa chỉ PC: 0x022fcc | Địa chỉ FDE: 0x0bcfd0 | Kích thước: 48 bytes
//   0x022fcc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x022fd0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x022fd4: 910043FD  add      x29, sp, #0x10
//   0x022fd8: D0000628  adrp     x8, #0xe8000
static inline uint64_t fde_func_0233_0x022fcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x022fccULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bcfd0ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0234 | PC: 0x022ffc | FDE: 0x0bcff0 | Size: 56 bytes
// Hàm FDE #0234 | Địa chỉ PC: 0x022ffc | Địa chỉ FDE: 0x0bcff0 | Kích thước: 56 bytes
//   0x022ffc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x023000: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x023004: 910043FD  add      x29, sp, #0x10
//   0x023008: B0000628  adrp     x8, #0xe8000
static inline uint64_t fde_func_0234_0x022ffc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x022ffcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bcff0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0235 | PC: 0x023034 | FDE: 0x0bd010 | Size: 8 bytes
// Hàm FDE #0235 | Địa chỉ PC: 0x023034 | Địa chỉ FDE: 0x0bd010 | Kích thước: 8 bytes
//   0x023034: 91006000  add      x0, x0, #0x18
//   0x023038: 140147F8  b        #0x75018
static inline uint64_t fde_func_0235_0x023034(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x023034ULL ^ (static_cast<uint64_t>(0x91006000ULL) << 13);
    acc = (acc + a1 + 0x140147f8ULL) ^ 0x0bd010ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0236 | PC: 0x02303c | FDE: 0x0bd028 | Size: 4 bytes
// Hàm FDE #0236 | Địa chỉ PC: 0x02303c | Địa chỉ FDE: 0x0bd028 | Kích thước: 4 bytes
//   0x02303c: 17FFBDF1  b        #0x12800
static inline uint64_t fde_func_0236_0x02303c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02303cULL ^ (static_cast<uint64_t>(0x17ffbdf1ULL) << 13);
    acc = (acc + a1 + 0x17ffbdf0ULL) ^ 0x0bd028ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0237 | PC: 0x023040 | FDE: 0x0bd040 | Size: 4 bytes
// Hàm FDE #0237 | Địa chỉ PC: 0x023040 | Địa chỉ FDE: 0x0bd040 | Kích thước: 4 bytes
//   0x023040: 17FFBDF0  b        #0x12800
static inline uint64_t fde_func_0237_0x023040(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x023040ULL ^ (static_cast<uint64_t>(0x17ffbdf0ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x0bd040ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0238 | PC: 0x023044 | FDE: 0x0bd058 | Size: 56 bytes
// Hàm FDE #0238 | Địa chỉ PC: 0x023044 | Địa chỉ FDE: 0x0bd058 | Kích thước: 56 bytes
//   0x023044: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x023048: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02304c: 910043FD  add      x29, sp, #0x10
//   0x023050: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0238_0x023044(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x023044ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bd058ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0239 | PC: 0x02307c | FDE: 0x0bd078 | Size: 24 bytes
// Hàm FDE #0239 | Địa chỉ PC: 0x02307c | Địa chỉ FDE: 0x0bd078 | Kích thước: 24 bytes
//   0x02307c: B0000628  adrp     x8, #0xe8000
//   0x023080: 910EE108  add      x8, x8, #0x3b8
//   0x023084: F9000028  str      x8, [x1]
//   0x023088: 3CC08000  ldur     q0, [x0, #8]
static inline uint64_t fde_func_0239_0x02307c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02307cULL ^ (static_cast<uint64_t>(0xb0000628ULL) << 13);
    acc = (acc + a1 + 0x910ee108ULL) ^ 0x0bd078ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0240 | PC: 0x023094 | FDE: 0x0bd090 | Size: 4 bytes
// Hàm FDE #0240 | Địa chỉ PC: 0x023094 | Địa chỉ FDE: 0x0bd090 | Kích thước: 4 bytes
//   0x023094: D65F03C0  ret      
static inline uint64_t fde_func_0240_0x023094(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x023094ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0x17ffbddaULL) ^ 0x0bd090ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0241 | PC: 0x023098 | FDE: 0x0bd0a8 | Size: 4 bytes
// Hàm FDE #0241 | Địa chỉ PC: 0x023098 | Địa chỉ FDE: 0x0bd0a8 | Kích thước: 4 bytes
//   0x023098: 17FFBDDA  b        #0x12800
static inline uint64_t fde_func_0241_0x023098(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x023098ULL ^ (static_cast<uint64_t>(0x17ffbddaULL) << 13);
    acc = (acc + a1 + 0xd10703ffULL) ^ 0x0bd0a8ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0242 | PC: 0x02309c | FDE: 0x0bdb78 | Size: 256 bytes
// Hàm FDE #0242 | Địa chỉ PC: 0x02309c | Địa chỉ FDE: 0x0bdb78 | Kích thước: 256 bytes
//   0x02309c: D10703FF  sub      sp, sp, #0x1c0
//   0x0230a0: A9166FFC  stp      x28, x27, [sp, #0x160]
//   0x0230a4: A91767FA  stp      x26, x25, [sp, #0x170]
//   0x0230a8: A9185FF8  stp      x24, x23, [sp, #0x180]
static inline uint64_t fde_func_0242_0x02309c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02309cULL ^ (static_cast<uint64_t>(0xd10703ffULL) << 13);
    acc = (acc + a1 + 0xa9166ffcULL) ^ 0x0bdb78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0243 | PC: 0x023b64 | FDE: 0x0bd0c0 | Size: 28 bytes
// Hàm FDE #0243 | Địa chỉ PC: 0x023b64 | Địa chỉ FDE: 0x0bd0c0 | Kích thước: 28 bytes
//   0x023b64: F9400428  ldr      x8, [x1, #8]
//   0x023b68: F0000449  adrp     x9, #0xae000
//   0x023b6c: 912E3929  add      x9, x9, #0xb8e
//   0x023b70: 9100200A  add      x10, x0, #8
static inline uint64_t fde_func_0243_0x023b64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x023b64ULL ^ (static_cast<uint64_t>(0xf9400428ULL) << 13);
    acc = (acc + a1 + 0xf0000449ULL) ^ 0x0bd0c0ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0244 | PC: 0x023b80 | FDE: 0x0bd0d8 | Size: 12 bytes
// Hàm FDE #0244 | Địa chỉ PC: 0x023b80 | Địa chỉ FDE: 0x0bd0d8 | Kích thước: 12 bytes
//   0x023b80: B0000620  adrp     x0, #0xe8000
//   0x023b84: 9113E000  add      x0, x0, #0x4f8
//   0x023b88: D65F03C0  ret      
static inline uint64_t fde_func_0244_0x023b80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x023b80ULL ^ (static_cast<uint64_t>(0xb0000620ULL) << 13);
    acc = (acc + a1 + 0x9113e000ULL) ^ 0x0bd0d8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0245 | PC: 0x023b8c | FDE: 0x0bd0f0 | Size: 4 bytes
// Hàm FDE #0245 | Địa chỉ PC: 0x023b8c | Địa chỉ FDE: 0x0bd0f0 | Kích thước: 4 bytes
//   0x023b8c: D65F03C0  ret      
static inline uint64_t fde_func_0245_0x023b8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x023b8cULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0x17ffbb1cULL) ^ 0x0bd0f0ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0246 | PC: 0x023b90 | FDE: 0x0bd108 | Size: 4 bytes
// Hàm FDE #0246 | Địa chỉ PC: 0x023b90 | Địa chỉ FDE: 0x0bd108 | Kích thước: 4 bytes
//   0x023b90: 17FFBB1C  b        #0x12800
static inline uint64_t fde_func_0246_0x023b90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x023b90ULL ^ (static_cast<uint64_t>(0x17ffbb1cULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x0bd108ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0247 | PC: 0x023b94 | FDE: 0x0bd120 | Size: 56 bytes
// Hàm FDE #0247 | Địa chỉ PC: 0x023b94 | Địa chỉ FDE: 0x0bd120 | Kích thước: 56 bytes
//   0x023b94: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x023b98: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x023b9c: 910043FD  add      x29, sp, #0x10
//   0x023ba0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0247_0x023b94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x023b94ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bd120ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0248 | PC: 0x023bcc | FDE: 0x0bd140 | Size: 24 bytes
// Hàm FDE #0248 | Địa chỉ PC: 0x023bcc | Địa chỉ FDE: 0x0bd140 | Kích thước: 24 bytes
//   0x023bcc: B0000628  adrp     x8, #0xe8000
//   0x023bd0: 9110E108  add      x8, x8, #0x438
//   0x023bd4: F9000028  str      x8, [x1]
//   0x023bd8: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0248_0x023bcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x023bccULL ^ (static_cast<uint64_t>(0xb0000628ULL) << 13);
    acc = (acc + a1 + 0x9110e108ULL) ^ 0x0bd140ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0249 | PC: 0x023be4 | FDE: 0x0bd158 | Size: 4 bytes
// Hàm FDE #0249 | Địa chỉ PC: 0x023be4 | Địa chỉ FDE: 0x0bd158 | Kích thước: 4 bytes
//   0x023be4: D65F03C0  ret      
static inline uint64_t fde_func_0249_0x023be4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x023be4ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0x17ffbb06ULL) ^ 0x0bd158ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0250 | PC: 0x023be8 | FDE: 0x0bd170 | Size: 4 bytes
// Hàm FDE #0250 | Địa chỉ PC: 0x023be8 | Địa chỉ FDE: 0x0bd170 | Kích thước: 4 bytes
//   0x023be8: 17FFBB06  b        #0x12800
static inline uint64_t fde_func_0250_0x023be8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x023be8ULL ^ (static_cast<uint64_t>(0x17ffbb06ULL) << 13);
    acc = (acc + a1 + 0xf9400400ULL) ^ 0x0bd170ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0251 | PC: 0x023bec | FDE: 0x0bd188 | Size: 8 bytes
// Hàm FDE #0251 | Địa chỉ PC: 0x023bec | Địa chỉ FDE: 0x0bd188 | Kích thước: 8 bytes
//   0x023bec: F9400400  ldr      x0, [x0, #8]
//   0x023bf0: 17FFF800  b        #0x21bf0
static inline uint64_t fde_func_0251_0x023bec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x023becULL ^ (static_cast<uint64_t>(0xf9400400ULL) << 13);
    acc = (acc + a1 + 0x17fff800ULL) ^ 0x0bd188ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0252 | PC: 0x023bf4 | FDE: 0x0bd1a0 | Size: 28 bytes
// Hàm FDE #0252 | Địa chỉ PC: 0x023bf4 | Địa chỉ FDE: 0x0bd1a0 | Kích thước: 28 bytes
//   0x023bf4: F9400428  ldr      x8, [x1, #8]
//   0x023bf8: F0000449  adrp     x9, #0xae000
//   0x023bfc: 912B9929  add      x9, x9, #0xae6
//   0x023c00: 9100200A  add      x10, x0, #8
static inline uint64_t fde_func_0252_0x023bf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x023bf4ULL ^ (static_cast<uint64_t>(0xf9400428ULL) << 13);
    acc = (acc + a1 + 0xf0000449ULL) ^ 0x0bd1a0ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0253 | PC: 0x023c10 | FDE: 0x0bd1b8 | Size: 12 bytes
// Hàm FDE #0253 | Địa chỉ PC: 0x023c10 | Địa chỉ FDE: 0x0bd1b8 | Kích thước: 12 bytes
//   0x023c10: B0000620  adrp     x0, #0xe8000
//   0x023c14: 9112A000  add      x0, x0, #0x4a8
//   0x023c18: D65F03C0  ret      
static inline uint64_t fde_func_0253_0x023c10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x023c10ULL ^ (static_cast<uint64_t>(0xb0000620ULL) << 13);
    acc = (acc + a1 + 0x9112a000ULL) ^ 0x0bd1b8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0254 | PC: 0x023c1c | FDE: 0x0bd1d0 | Size: 52 bytes
// Hàm FDE #0254 | Địa chỉ PC: 0x023c1c | Địa chỉ FDE: 0x0bd1d0 | Kích thước: 52 bytes
//   0x023c1c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x023c20: 910003FD  mov      x29, sp
//   0x023c24: 52800100  mov      w0, #8
//   0x023c28: 97FFBB22  bl       #0x128b0
static inline uint64_t fde_func_0254_0x023c1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x023c1cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0bd1d0ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0255 | PC: 0x023c50 | FDE: 0x0bd1f0 | Size: 36 bytes [_ZNSt6__ndk117bad_function_callD0Ev]
// Hàm FDE #0255 | Địa chỉ PC: 0x023c50 | Địa chỉ FDE: 0x0bd1f0 | Kích thước: 36 bytes
//   0x023c50: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x023c54: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x023c58: 910043FD  add      x29, sp, #0x10
//   0x023c5c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0255_0x023c50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x023c50ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bd1f0ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0256 | PC: 0x023c74 | FDE: 0x0bd210 | Size: 32 bytes
// Hàm FDE #0256 | Địa chỉ PC: 0x023c74 | Địa chỉ FDE: 0x0bd210 | Kích thước: 32 bytes
//   0x023c74: 39404008  ldrb     w8, [x0, #0x10]
//   0x023c78: B0000629  adrp     x9, #0xe8000
//   0x023c7c: 91146129  add      x9, x9, #0x518
//   0x023c80: F9000009  str      x9, [x0]
static inline uint64_t fde_func_0256_0x023c74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x023c74ULL ^ (static_cast<uint64_t>(0x39404008ULL) << 13);
    acc = (acc + a1 + 0xb0000629ULL) ^ 0x0bd210ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0257 | PC: 0x023c94 | FDE: 0x0bd228 | Size: 60 bytes
// Hàm FDE #0257 | Địa chỉ PC: 0x023c94 | Địa chỉ FDE: 0x0bd228 | Kích thước: 60 bytes
//   0x023c94: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x023c98: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x023c9c: 910043FD  add      x29, sp, #0x10
//   0x023ca0: 39404008  ldrb     w8, [x0, #0x10]
static inline uint64_t fde_func_0257_0x023c94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x023c94ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bd228ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0258 | PC: 0x023cd0 | FDE: 0x0bdbb0 | Size: 100 bytes
// Hàm FDE #0258 | Địa chỉ PC: 0x023cd0 | Địa chỉ FDE: 0x0bdbb0 | Kích thước: 100 bytes
//   0x023cd0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x023cd4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x023cd8: 910043FD  add      x29, sp, #0x10
//   0x023cdc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0258_0x023cd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x023cd0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bdbb0ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #0259 | PC: 0x023d34 | FDE: 0x0bd248 | Size: 72 bytes
// Hàm FDE #0259 | Địa chỉ PC: 0x023d34 | Địa chỉ FDE: 0x0bd248 | Kích thước: 72 bytes
//   0x023d34: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x023d38: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x023d3c: 910043FD  add      x29, sp, #0x10
//   0x023d40: B0000628  adrp     x8, #0xe8000
static inline uint64_t fde_func_0259_0x023d34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x023d34ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bd248ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0260 | PC: 0x023d7c | FDE: 0x0bd268 | Size: 20 bytes
// Hàm FDE #0260 | Địa chỉ PC: 0x023d7c | Địa chỉ FDE: 0x0bd268 | Kích thước: 20 bytes
//   0x023d7c: 39404008  ldrb     w8, [x0, #0x10]
//   0x023d80: 37000048  tbnz     w8, #0, #0x23d88
//   0x023d84: D65F03C0  ret      
//   0x023d88: F9401000  ldr      x0, [x0, #0x20]
static inline uint64_t fde_func_0260_0x023d7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x023d7cULL ^ (static_cast<uint64_t>(0x39404008ULL) << 13);
    acc = (acc + a1 + 0x37000048ULL) ^ 0x0bd268ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0261 | PC: 0x023d90 | FDE: 0x0bd280 | Size: 48 bytes
// Hàm FDE #0261 | Địa chỉ PC: 0x023d90 | Địa chỉ FDE: 0x0bd280 | Kích thước: 48 bytes
//   0x023d90: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x023d94: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x023d98: 910043FD  add      x29, sp, #0x10
//   0x023d9c: 39404008  ldrb     w8, [x0, #0x10]
static inline uint64_t fde_func_0261_0x023d90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x023d90ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bd280ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0262 | PC: 0x023dc0 | FDE: 0x0bdbd8 | Size: 256 bytes
// Hàm FDE #0262 | Địa chỉ PC: 0x023dc0 | Địa chỉ FDE: 0x0bdbd8 | Kích thước: 256 bytes
//   0x023dc0: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x023dc4: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x023dc8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x023dcc: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0262_0x023dc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x023dc0ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0bdbd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0263 | PC: 0x0249f0 | FDE: 0x0bd2a0 | Size: 28 bytes
// Hàm FDE #0263 | Địa chỉ PC: 0x0249f0 | Địa chỉ FDE: 0x0bd2a0 | Kích thước: 28 bytes
//   0x0249f0: F9400428  ldr      x8, [x1, #8]
//   0x0249f4: D0000449  adrp     x9, #0xae000
//   0x0249f8: 9136A929  add      x9, x9, #0xdaa
//   0x0249fc: 9100200A  add      x10, x0, #8
static inline uint64_t fde_func_0263_0x0249f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0249f0ULL ^ (static_cast<uint64_t>(0xf9400428ULL) << 13);
    acc = (acc + a1 + 0xd0000449ULL) ^ 0x0bd2a0ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0264 | PC: 0x024a0c | FDE: 0x0bd2b8 | Size: 12 bytes
// Hàm FDE #0264 | Địa chỉ PC: 0x024a0c | Địa chỉ FDE: 0x0bd2b8 | Kích thước: 12 bytes
//   0x024a0c: 90000620  adrp     x0, #0xe8000
//   0x024a10: 9117E000  add      x0, x0, #0x5f8
//   0x024a14: D65F03C0  ret      
static inline uint64_t fde_func_0264_0x024a0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x024a0cULL ^ (static_cast<uint64_t>(0x90000620ULL) << 13);
    acc = (acc + a1 + 0x9117e000ULL) ^ 0x0bd2b8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0265 | PC: 0x024a18 | FDE: 0x0bd2d0 | Size: 4 bytes
// Hàm FDE #0265 | Địa chỉ PC: 0x024a18 | Địa chỉ FDE: 0x0bd2d0 | Kích thước: 4 bytes
//   0x024a18: D65F03C0  ret      
static inline uint64_t fde_func_0265_0x024a18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x024a18ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0x17ffb779ULL) ^ 0x0bd2d0ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0266 | PC: 0x024a1c | FDE: 0x0bd2e8 | Size: 4 bytes
// Hàm FDE #0266 | Địa chỉ PC: 0x024a1c | Địa chỉ FDE: 0x0bd2e8 | Kích thước: 4 bytes
//   0x024a1c: 17FFB779  b        #0x12800
static inline uint64_t fde_func_0266_0x024a1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x024a1cULL ^ (static_cast<uint64_t>(0x17ffb779ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x0bd2e8ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0267 | PC: 0x024a20 | FDE: 0x0bd300 | Size: 56 bytes
// Hàm FDE #0267 | Địa chỉ PC: 0x024a20 | Địa chỉ FDE: 0x0bd300 | Kích thước: 56 bytes
//   0x024a20: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x024a24: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x024a28: 910043FD  add      x29, sp, #0x10
//   0x024a2c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0267_0x024a20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x024a20ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bd300ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0268 | PC: 0x024a58 | FDE: 0x0bd320 | Size: 24 bytes
// Hàm FDE #0268 | Địa chỉ PC: 0x024a58 | Địa chỉ FDE: 0x0bd320 | Kích thước: 24 bytes
//   0x024a58: 90000628  adrp     x8, #0xe8000
//   0x024a5c: 91162108  add      x8, x8, #0x588
//   0x024a60: F9000028  str      x8, [x1]
//   0x024a64: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0268_0x024a58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x024a58ULL ^ (static_cast<uint64_t>(0x90000628ULL) << 13);
    acc = (acc + a1 + 0x91162108ULL) ^ 0x0bd320ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0269 | PC: 0x024a70 | FDE: 0x0bd338 | Size: 4 bytes
// Hàm FDE #0269 | Địa chỉ PC: 0x024a70 | Địa chỉ FDE: 0x0bd338 | Kích thước: 4 bytes
//   0x024a70: D65F03C0  ret      
static inline uint64_t fde_func_0269_0x024a70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x024a70ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0x17ffb763ULL) ^ 0x0bd338ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0270 | PC: 0x024a74 | FDE: 0x0bd350 | Size: 4 bytes
// Hàm FDE #0270 | Địa chỉ PC: 0x024a74 | Địa chỉ FDE: 0x0bd350 | Kích thước: 4 bytes
//   0x024a74: 17FFB763  b        #0x12800
static inline uint64_t fde_func_0270_0x024a74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x024a74ULL ^ (static_cast<uint64_t>(0x17ffb763ULL) << 13);
    acc = (acc + a1 + 0xf9400400ULL) ^ 0x0bd350ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0271 | PC: 0x024a78 | FDE: 0x0bd368 | Size: 8 bytes
// Hàm FDE #0271 | Địa chỉ PC: 0x024a78 | Địa chỉ FDE: 0x0bd368 | Kích thước: 8 bytes
//   0x024a78: F9400400  ldr      x0, [x0, #8]
//   0x024a7c: 17FFF45D  b        #0x21bf0
static inline uint64_t fde_func_0271_0x024a78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x024a78ULL ^ (static_cast<uint64_t>(0xf9400400ULL) << 13);
    acc = (acc + a1 + 0x17fff45dULL) ^ 0x0bd368ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0272 | PC: 0x024a80 | FDE: 0x0bd380 | Size: 28 bytes
// Hàm FDE #0272 | Địa chỉ PC: 0x024a80 | Địa chỉ FDE: 0x0bd380 | Kích thước: 28 bytes
//   0x024a80: F9400428  ldr      x8, [x1, #8]
//   0x024a84: D0000449  adrp     x9, #0xae000
//   0x024a88: 91347529  add      x9, x9, #0xd1d
//   0x024a8c: 9100200A  add      x10, x0, #8
static inline uint64_t fde_func_0272_0x024a80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x024a80ULL ^ (static_cast<uint64_t>(0xf9400428ULL) << 13);
    acc = (acc + a1 + 0xd0000449ULL) ^ 0x0bd380ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0273 | PC: 0x024a9c | FDE: 0x0bd398 | Size: 12 bytes
// Hàm FDE #0273 | Địa chỉ PC: 0x024a9c | Địa chỉ FDE: 0x0bd398 | Kích thước: 12 bytes
//   0x024a9c: 90000620  adrp     x0, #0xe8000
//   0x024aa0: 9117A000  add      x0, x0, #0x5e8
//   0x024aa4: D65F03C0  ret      
static inline uint64_t fde_func_0273_0x024a9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x024a9cULL ^ (static_cast<uint64_t>(0x90000620ULL) << 13);
    acc = (acc + a1 + 0x9117a000ULL) ^ 0x0bd398ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0274 | PC: 0x024aa8 | FDE: 0x0bdc10 | Size: 256 bytes
// Hàm FDE #0274 | Địa chỉ PC: 0x024aa8 | Địa chỉ FDE: 0x0bdc10 | Kích thước: 256 bytes
//   0x024aa8: D101C3FF  sub      sp, sp, #0x70
//   0x024aac: F9000BFB  str      x27, [sp, #0x10]
//   0x024ab0: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x024ab4: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_0274_0x024aa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x024aa8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfbULL) ^ 0x0bdc10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0275 | PC: 0x024c74 | FDE: 0x0bd3b0 | Size: 188 bytes
// Hàm FDE #0275 | Địa chỉ PC: 0x024c74 | Địa chỉ FDE: 0x0bd3b0 | Kích thước: 188 bytes
//   0x024c74: D10143FF  sub      sp, sp, #0x50
//   0x024c78: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x024c7c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x024c80: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0275_0x024c74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x024c74ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x0bd3b0ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0276 | PC: 0x024d30 | FDE: 0x0bd3d8 | Size: 256 bytes
// Hàm FDE #0276 | Địa chỉ PC: 0x024d30 | Địa chỉ FDE: 0x0bd3d8 | Kích thước: 256 bytes
//   0x024d30: F9400409  ldr      x9, [x0, #8]
//   0x024d34: F940042A  ldr      x10, [x1, #8]
//   0x024d38: 9E670120  fmov     d0, x9
//   0x024d3c: 0E205800  cnt      v0.8b, v0.8b
static inline uint64_t fde_func_0276_0x024d30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x024d30ULL ^ (static_cast<uint64_t>(0xf9400409ULL) << 13);
    acc = (acc + a1 + 0xf940042aULL) ^ 0x0bd3d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0277 | PC: 0x024e7c | FDE: 0x0bd3f0 | Size: 140 bytes
// Hàm FDE #0277 | Địa chỉ PC: 0x024e7c | Địa chỉ FDE: 0x0bd3f0 | Kích thước: 140 bytes
//   0x024e7c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x024e80: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x024e84: 910043FD  add      x29, sp, #0x10
//   0x024e88: 3940A008  ldrb     w8, [x0, #0x28]
static inline uint64_t fde_func_0277_0x024e7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x024e7cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bd3f0ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0278 | PC: 0x024f08 | FDE: 0x0bd410 | Size: 140 bytes
// Hàm FDE #0278 | Địa chỉ PC: 0x024f08 | Địa chỉ FDE: 0x0bd410 | Kích thước: 140 bytes
//   0x024f08: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x024f0c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x024f10: 910043FD  add      x29, sp, #0x10
//   0x024f14: 3940A008  ldrb     w8, [x0, #0x28]
static inline uint64_t fde_func_0278_0x024f08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x024f08ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bd410ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0279 | PC: 0x024f94 | FDE: 0x0bdc48 | Size: 244 bytes
// Hàm FDE #0279 | Địa chỉ PC: 0x024f94 | Địa chỉ FDE: 0x0bdc48 | Kích thước: 244 bytes
//   0x024f94: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x024f98: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x024f9c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x024fa0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0279_0x024f94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x024f94ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bdc48ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #0280 | PC: 0x025088 | FDE: 0x0bdc70 | Size: 224 bytes
// Hàm FDE #0280 | Địa chỉ PC: 0x025088 | Địa chỉ FDE: 0x0bdc70 | Kích thước: 224 bytes
//   0x025088: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x02508c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x025090: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x025094: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0280_0x025088(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x025088ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bdc70ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #0281 | PC: 0x025168 | FDE: 0x0bd430 | Size: 128 bytes
// Hàm FDE #0281 | Địa chỉ PC: 0x025168 | Địa chỉ FDE: 0x0bd430 | Kích thước: 128 bytes
//   0x025168: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x02516c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x025170: 910043FD  add      x29, sp, #0x10
//   0x025174: 3940A008  ldrb     w8, [x0, #0x28]
static inline uint64_t fde_func_0281_0x025168(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x025168ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bd430ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0282 | PC: 0x0251e8 | FDE: 0x0bd450 | Size: 128 bytes
// Hàm FDE #0282 | Địa chỉ PC: 0x0251e8 | Địa chỉ FDE: 0x0bd450 | Kích thước: 128 bytes
//   0x0251e8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0251ec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0251f0: 910043FD  add      x29, sp, #0x10
//   0x0251f4: 3940A008  ldrb     w8, [x0, #0x28]
static inline uint64_t fde_func_0282_0x0251e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0251e8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bd450ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0283 | PC: 0x025268 | FDE: 0x0bdc98 | Size: 256 bytes
// Hàm FDE #0283 | Địa chỉ PC: 0x025268 | Địa chỉ FDE: 0x0bdc98 | Kích thước: 256 bytes
//   0x025268: D10143FF  sub      sp, sp, #0x50
//   0x02526c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x025270: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x025274: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0283_0x025268(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x025268ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x0bdc98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0284 | PC: 0x0253e0 | FDE: 0x0bd470 | Size: 28 bytes
// Hàm FDE #0284 | Địa chỉ PC: 0x0253e0 | Địa chỉ FDE: 0x0bd470 | Kích thước: 28 bytes
//   0x0253e0: F9400428  ldr      x8, [x1, #8]
//   0x0253e4: B0000449  adrp     x9, #0xae000
//   0x0253e8: 913C0129  add      x9, x9, #0xf00
//   0x0253ec: 9100200A  add      x10, x0, #8
static inline uint64_t fde_func_0284_0x0253e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0253e0ULL ^ (static_cast<uint64_t>(0xf9400428ULL) << 13);
    acc = (acc + a1 + 0xb0000449ULL) ^ 0x0bd470ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0285 | PC: 0x0253fc | FDE: 0x0bd488 | Size: 12 bytes
// Hàm FDE #0285 | Địa chỉ PC: 0x0253fc | Địa chỉ FDE: 0x0bd488 | Kích thước: 12 bytes
//   0x0253fc: F0000600  adrp     x0, #0xe8000
//   0x025400: 911A6000  add      x0, x0, #0x698
//   0x025404: D65F03C0  ret      
static inline uint64_t fde_func_0285_0x0253fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0253fcULL ^ (static_cast<uint64_t>(0xf0000600ULL) << 13);
    acc = (acc + a1 + 0x911a6000ULL) ^ 0x0bd488ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0286 | PC: 0x025408 | FDE: 0x0bdcc8 | Size: 256 bytes
// Hàm FDE #0286 | Địa chỉ PC: 0x025408 | Địa chỉ FDE: 0x0bdcc8 | Kích thước: 256 bytes
//   0x025408: D10203FF  sub      sp, sp, #0x80
//   0x02540c: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x025410: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x025414: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0286_0x025408(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x025408ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x0bdcc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0287 | PC: 0x02576c | FDE: 0x0bd4a0 | Size: 228 bytes
// Hàm FDE #0287 | Địa chỉ PC: 0x02576c | Địa chỉ FDE: 0x0bd4a0 | Kích thước: 228 bytes
//   0x02576c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x025770: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x025774: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x025778: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0287_0x02576c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02576cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bd4a0ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #0288 | PC: 0x025850 | FDE: 0x0bd4c0 | Size: 256 bytes
// Hàm FDE #0288 | Địa chỉ PC: 0x025850 | Địa chỉ FDE: 0x0bd4c0 | Kích thước: 256 bytes
//   0x025850: D10203FF  sub      sp, sp, #0x80
//   0x025854: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x025858: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x02585c: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0288_0x025850(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x025850ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x0bd4c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0289 | PC: 0x025ac0 | FDE: 0x0bd4f0 | Size: 76 bytes
// Hàm FDE #0289 | Địa chỉ PC: 0x025ac0 | Địa chỉ FDE: 0x0bd4f0 | Kích thước: 76 bytes
//   0x025ac0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x025ac4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x025ac8: 910043FD  add      x29, sp, #0x10
//   0x025acc: 39406008  ldrb     w8, [x0, #0x18]
static inline uint64_t fde_func_0289_0x025ac0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x025ac0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bd4f0ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0290 | PC: 0x025b0c | FDE: 0x0bd510 | Size: 72 bytes
// Hàm FDE #0290 | Địa chỉ PC: 0x025b0c | Địa chỉ FDE: 0x0bd510 | Kích thước: 72 bytes
//   0x025b0c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x025b10: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x025b14: 910043FD  add      x29, sp, #0x10
//   0x025b18: 39406008  ldrb     w8, [x0, #0x18]
static inline uint64_t fde_func_0290_0x025b0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x025b0cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bd510ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0291 | PC: 0x025b54 | FDE: 0x0bdd00 | Size: 144 bytes
// Hàm FDE #0291 | Địa chỉ PC: 0x025b54 | Địa chỉ FDE: 0x0bdd00 | Kích thước: 144 bytes
//   0x025b54: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x025b58: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x025b5c: 910043FD  add      x29, sp, #0x10
//   0x025b60: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0291_0x025b54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x025b54ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bdd00ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0292 | PC: 0x025be4 | FDE: 0x0bdd28 | Size: 124 bytes
// Hàm FDE #0292 | Địa chỉ PC: 0x025be4 | Địa chỉ FDE: 0x0bdd28 | Kích thước: 124 bytes
//   0x025be4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x025be8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x025bec: 910043FD  add      x29, sp, #0x10
//   0x025bf0: F0000608  adrp     x8, #0xe8000
static inline uint64_t fde_func_0292_0x025be4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x025be4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bdd28ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0293 | PC: 0x025c60 | FDE: 0x0bd530 | Size: 64 bytes
// Hàm FDE #0293 | Địa chỉ PC: 0x025c60 | Địa chỉ FDE: 0x0bd530 | Kích thước: 64 bytes
//   0x025c60: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x025c64: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x025c68: 910043FD  add      x29, sp, #0x10
//   0x025c6c: 39406008  ldrb     w8, [x0, #0x18]
static inline uint64_t fde_func_0293_0x025c60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x025c60ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bd530ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0294 | PC: 0x025ca0 | FDE: 0x0bd550 | Size: 60 bytes
// Hàm FDE #0294 | Địa chỉ PC: 0x025ca0 | Địa chỉ FDE: 0x0bd550 | Kích thước: 60 bytes
//   0x025ca0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x025ca4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x025ca8: 910043FD  add      x29, sp, #0x10
//   0x025cac: 39406008  ldrb     w8, [x0, #0x18]
static inline uint64_t fde_func_0294_0x025ca0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x025ca0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bd550ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0295 | PC: 0x025cdc | FDE: 0x0bdd50 | Size: 256 bytes
// Hàm FDE #0295 | Địa chỉ PC: 0x025cdc | Địa chỉ FDE: 0x0bdd50 | Kích thước: 256 bytes
//   0x025cdc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x025ce0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x025ce4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x025ce8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0295_0x025cdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x025cdcULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bdd50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0296 | PC: 0x025e18 | FDE: 0x0bd570 | Size: 28 bytes
// Hàm FDE #0296 | Địa chỉ PC: 0x025e18 | Địa chỉ FDE: 0x0bd570 | Kích thước: 28 bytes
//   0x025e18: F9400428  ldr      x8, [x1, #8]
//   0x025e1c: D0000449  adrp     x9, #0xaf000
//   0x025e20: 91004D29  add      x9, x9, #0x13
//   0x025e24: 9100200A  add      x10, x0, #8
static inline uint64_t fde_func_0296_0x025e18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x025e18ULL ^ (static_cast<uint64_t>(0xf9400428ULL) << 13);
    acc = (acc + a1 + 0xd0000449ULL) ^ 0x0bd570ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0297 | PC: 0x025e34 | FDE: 0x0bd588 | Size: 12 bytes
// Hàm FDE #0297 | Địa chỉ PC: 0x025e34 | Địa chỉ FDE: 0x0bd588 | Kích thước: 12 bytes
//   0x025e34: F0000600  adrp     x0, #0xe8000
//   0x025e38: 911C6000  add      x0, x0, #0x718
//   0x025e3c: D65F03C0  ret      
static inline uint64_t fde_func_0297_0x025e34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x025e34ULL ^ (static_cast<uint64_t>(0xf0000600ULL) << 13);
    acc = (acc + a1 + 0x911c6000ULL) ^ 0x0bd588ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0298 | PC: 0x025e40 | FDE: 0x0bdd80 | Size: 256 bytes
// Hàm FDE #0298 | Địa chỉ PC: 0x025e40 | Địa chỉ FDE: 0x0bdd80 | Kích thước: 256 bytes
//   0x025e40: D101C3FF  sub      sp, sp, #0x70
//   0x025e44: F9000BFB  str      x27, [sp, #0x10]
//   0x025e48: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x025e4c: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_0298_0x025e40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x025e40ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfbULL) ^ 0x0bdd80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0299 | PC: 0x02600c | FDE: 0x0bdee0 | Size: 208 bytes
// Hàm FDE #0299 | Địa chỉ PC: 0x02600c | Địa chỉ FDE: 0x0bdee0 | Kích thước: 208 bytes
//   0x02600c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x026010: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x026014: 910043FD  add      x29, sp, #0x10
//   0x026018: D0000608  adrp     x8, #0xe8000
static inline uint64_t fde_func_0299_0x02600c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02600cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bdee0ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #0300 | PC: 0x0260dc | FDE: 0x0bddb8 | Size: 16 bytes
// Hàm FDE #0300 | Địa chỉ PC: 0x0260dc | Địa chỉ FDE: 0x0bddb8 | Kích thước: 16 bytes
//   0x0260dc: F9400400  ldr      x0, [x0, #8]
//   0x0260e0: B4000040  cbz      x0, #0x260e8
//   0x0260e4: 17FFB343  b        #0x12df0
//   0x0260e8: D65F03C0  ret      
static inline uint64_t fde_func_0300_0x0260dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0260dcULL ^ (static_cast<uint64_t>(0xf9400400ULL) << 13);
    acc = (acc + a1 + 0xb4000040ULL) ^ 0x0bddb8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0301 | PC: 0x0260ec | FDE: 0x0bddd0 | Size: 88 bytes
// Hàm FDE #0301 | Địa chỉ PC: 0x0260ec | Địa chỉ FDE: 0x0bddd0 | Kích thước: 88 bytes
//   0x0260ec: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0260f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0260f4: 910043FD  add      x29, sp, #0x10
//   0x0260f8: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_0301_0x0260ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0260ecULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bddd0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0302 | PC: 0x026144 | FDE: 0x0bdf08 | Size: 212 bytes
// Hàm FDE #0302 | Địa chỉ PC: 0x026144 | Địa chỉ FDE: 0x0bdf08 | Kích thước: 212 bytes
//   0x026144: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x026148: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02614c: 910043FD  add      x29, sp, #0x10
//   0x026150: D0000608  adrp     x8, #0xe8000
static inline uint64_t fde_func_0302_0x026144(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x026144ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bdf08ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #0303 | PC: 0x026218 | FDE: 0x0bddf0 | Size: 8 bytes
// Hàm FDE #0303 | Địa chỉ PC: 0x026218 | Địa chỉ FDE: 0x0bddf0 | Kích thước: 8 bytes
//   0x026218: D1004000  sub      x0, x0, #0x10
//   0x02621c: 17FFFFCA  b        #0x26144
static inline uint64_t fde_func_0303_0x026218(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x026218ULL ^ (static_cast<uint64_t>(0xd1004000ULL) << 13);
    acc = (acc + a1 + 0x17ffffcaULL) ^ 0x0bddf0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0304 | PC: 0x026220 | FDE: 0x0bde08 | Size: 36 bytes
// Hàm FDE #0304 | Địa chỉ PC: 0x026220 | Địa chỉ FDE: 0x0bde08 | Kích thước: 36 bytes
//   0x026220: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x026224: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x026228: 910043FD  add      x29, sp, #0x10
//   0x02622c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0304_0x026220(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x026220ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bde08ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0305 | PC: 0x026244 | FDE: 0x0bde28 | Size: 40 bytes
// Hàm FDE #0305 | Địa chỉ PC: 0x026244 | Địa chỉ FDE: 0x0bde28 | Kích thước: 40 bytes
//   0x026244: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x026248: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02624c: 910043FD  add      x29, sp, #0x10
//   0x026250: D1004013  sub      x19, x0, #0x10
static inline uint64_t fde_func_0305_0x026244(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x026244ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bde28ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0306 | PC: 0x02626c | FDE: 0x0bde48 | Size: 256 bytes
// Hàm FDE #0306 | Địa chỉ PC: 0x02626c | Địa chỉ FDE: 0x0bde48 | Kích thước: 256 bytes
//   0x02626c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x026270: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x026274: 910043FD  add      x29, sp, #0x10
//   0x026278: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_0306_0x02626c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02626cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bde48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0307 | PC: 0x0263ec | FDE: 0x0bde68 | Size: 236 bytes
// Hàm FDE #0307 | Địa chỉ PC: 0x0263ec | Địa chỉ FDE: 0x0bde68 | Kích thước: 236 bytes
//   0x0263ec: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0263f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0263f4: 910043FD  add      x29, sp, #0x10
//   0x0263f8: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_0307_0x0263ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0263ecULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bde68ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0308 | PC: 0x0264d8 | FDE: 0x0bde88 | Size: 208 bytes
// Hàm FDE #0308 | Địa chỉ PC: 0x0264d8 | Địa chỉ FDE: 0x0bde88 | Kích thước: 208 bytes
//   0x0264d8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0264dc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0264e0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0264e4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0308_0x0264d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0264d8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bde88ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #0309 | PC: 0x0265a8 | FDE: 0x0bdea8 | Size: 100 bytes
// Hàm FDE #0309 | Địa chỉ PC: 0x0265a8 | Địa chỉ FDE: 0x0bdea8 | Kích thước: 100 bytes
//   0x0265a8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0265ac: 910003FD  mov      x29, sp
//   0x0265b0: F9400C00  ldr      x0, [x0, #0x18]
//   0x0265b4: B40000A0  cbz      x0, #0x265c8
static inline uint64_t fde_func_0309_0x0265a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0265a8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0bdea8ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #0310 | PC: 0x02660c | FDE: 0x0bdf30 | Size: 256 bytes
// Hàm FDE #0310 | Địa chỉ PC: 0x02660c | Địa chỉ FDE: 0x0bdf30 | Kích thước: 256 bytes
//   0x02660c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x026610: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x026614: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x026618: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0310_0x02660c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02660cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bdf30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0311 | PC: 0x02675c | FDE: 0x0bdec8 | Size: 8 bytes
// Hàm FDE #0311 | Địa chỉ PC: 0x02675c | Địa chỉ FDE: 0x0bdec8 | Kích thước: 8 bytes
//   0x02675c: D1004000  sub      x0, x0, #0x10
//   0x026760: 17FFFFAB  b        #0x2660c
static inline uint64_t fde_func_0311_0x02675c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02675cULL ^ (static_cast<uint64_t>(0xd1004000ULL) << 13);
    acc = (acc + a1 + 0x17ffffabULL) ^ 0x0bdec8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0312 | PC: 0x026764 | FDE: 0x0bdfa8 | Size: 256 bytes
// Hàm FDE #0312 | Địa chỉ PC: 0x026764 | Địa chỉ FDE: 0x0bdfa8 | Kích thước: 256 bytes
//   0x026764: D10143FF  sub      sp, sp, #0x50
//   0x026768: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x02676c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x026770: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0312_0x026764(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x026764ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x0bdfa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0313 | PC: 0x0268a4 | FDE: 0x0bdfd8 | Size: 256 bytes
// Hàm FDE #0313 | Địa chỉ PC: 0x0268a4 | Địa chỉ FDE: 0x0bdfd8 | Kích thước: 256 bytes
//   0x0268a4: D10203FF  sub      sp, sp, #0x80
//   0x0268a8: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0268ac: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0268b0: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0313_0x0268a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0268a4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x0bdfd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0314 | PC: 0x026c4c | FDE: 0x0be010 | Size: 256 bytes
// Hàm FDE #0314 | Địa chỉ PC: 0x026c4c | Địa chỉ FDE: 0x0be010 | Kích thước: 256 bytes
//   0x026c4c: D10243FF  sub      sp, sp, #0x90
//   0x026c50: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x026c54: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x026c58: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0314_0x026c4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x026c4cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x0be010ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0315 | PC: 0x0271d4 | FDE: 0x0bdf58 | Size: 256 bytes
// Hàm FDE #0315 | Địa chỉ PC: 0x0271d4 | Địa chỉ FDE: 0x0bdf58 | Kích thước: 256 bytes
//   0x0271d4: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x0271d8: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0271dc: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0271e0: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0315_0x0271d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0271d4ULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0bdf58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0316 | PC: 0x0272ec | FDE: 0x0be048 | Size: 48 bytes
// Hàm FDE #0316 | Địa chỉ PC: 0x0272ec | Địa chỉ FDE: 0x0be048 | Kích thước: 48 bytes
//   0x0272ec: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0272f0: 910003FD  mov      x29, sp
//   0x0272f4: 39400008  ldrb     w8, [x0]
//   0x0272f8: F9400809  ldr      x9, [x0, #0x10]
static inline uint64_t fde_func_0316_0x0272ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0272ecULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0be048ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0317 | PC: 0x02731c | FDE: 0x0be068 | Size: 248 bytes
// Hàm FDE #0317 | Địa chỉ PC: 0x02731c | Địa chỉ FDE: 0x0be068 | Kích thước: 248 bytes
//   0x02731c: D10103FF  sub      sp, sp, #0x40
//   0x027320: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x027324: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x027328: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0317_0x02731c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02731cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0be068ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0318 | PC: 0x027414 | FDE: 0x0be8c8 | Size: 256 bytes
// Hàm FDE #0318 | Địa chỉ PC: 0x027414 | Địa chỉ FDE: 0x0be8c8 | Kích thước: 256 bytes
//   0x027414: D106C3FF  sub      sp, sp, #0x1b0
//   0x027418: F900ABFC  str      x28, [sp, #0x150]
//   0x02741c: A91667FA  stp      x26, x25, [sp, #0x160]
//   0x027420: A9175FF8  stp      x24, x23, [sp, #0x170]
static inline uint64_t fde_func_0318_0x027414(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x027414ULL ^ (static_cast<uint64_t>(0xd106c3ffULL) << 13);
    acc = (acc + a1 + 0xf900abfcULL) ^ 0x0be8c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0319 | PC: 0x0276f4 | FDE: 0x0be090 | Size: 60 bytes
// Hàm FDE #0319 | Địa chỉ PC: 0x0276f4 | Địa chỉ FDE: 0x0be090 | Kích thước: 60 bytes
//   0x0276f4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0276f8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0276fc: 910043FD  add      x29, sp, #0x10
//   0x027700: 90000628  adrp     x8, #0xeb000
static inline uint64_t fde_func_0319_0x0276f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0276f4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0be090ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0320 | PC: 0x027730 | FDE: 0x0be900 | Size: 256 bytes
// Hàm FDE #0320 | Địa chỉ PC: 0x027730 | Địa chỉ FDE: 0x0be900 | Kích thước: 256 bytes
//   0x027730: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x027734: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x027738: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x02773c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0320_0x027730(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x027730ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0be900ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0321 | PC: 0x027bfc | FDE: 0x0be938 | Size: 256 bytes
// Hàm FDE #0321 | Địa chỉ PC: 0x027bfc | Địa chỉ FDE: 0x0be938 | Kích thước: 256 bytes
//   0x027bfc: D10183FF  sub      sp, sp, #0x60
//   0x027c00: F90013F7  str      x23, [sp, #0x20]
//   0x027c04: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x027c08: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0321_0x027bfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x027bfcULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x0be938ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0322 | PC: 0x027e04 | FDE: 0x0be0b0 | Size: 116 bytes
// Hàm FDE #0322 | Địa chỉ PC: 0x027e04 | Địa chỉ FDE: 0x0be0b0 | Kích thước: 116 bytes
//   0x027e04: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x027e08: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x027e0c: 910043FD  add      x29, sp, #0x10
//   0x027e10: 90000628  adrp     x8, #0xeb000
static inline uint64_t fde_func_0322_0x027e04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x027e04ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0be0b0ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0323 | PC: 0x027e78 | FDE: 0x0be0d0 | Size: 60 bytes
// Hàm FDE #0323 | Địa chỉ PC: 0x027e78 | Địa chỉ FDE: 0x0be0d0 | Kích thước: 60 bytes
//   0x027e78: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x027e7c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x027e80: 910043FD  add      x29, sp, #0x10
//   0x027e84: 90000628  adrp     x8, #0xeb000
static inline uint64_t fde_func_0323_0x027e78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x027e78ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0be0d0ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0324 | PC: 0x027eb4 | FDE: 0x0be968 | Size: 256 bytes
// Hàm FDE #0324 | Địa chỉ PC: 0x027eb4 | Địa chỉ FDE: 0x0be968 | Kích thước: 256 bytes
//   0x027eb4: D101C3FF  sub      sp, sp, #0x70
//   0x027eb8: F9001BF7  str      x23, [sp, #0x30]
//   0x027ebc: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x027ec0: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0324_0x027eb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x027eb4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x0be968ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0325 | PC: 0x028130 | FDE: 0x0be998 | Size: 256 bytes
// Hàm FDE #0325 | Địa chỉ PC: 0x028130 | Địa chỉ FDE: 0x0be998 | Kích thước: 256 bytes
//   0x028130: D10603FF  sub      sp, sp, #0x180
//   0x028134: A9126FFC  stp      x28, x27, [sp, #0x120]
//   0x028138: A91367FA  stp      x26, x25, [sp, #0x130]
//   0x02813c: A9145FF8  stp      x24, x23, [sp, #0x140]
static inline uint64_t fde_func_0325_0x028130(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x028130ULL ^ (static_cast<uint64_t>(0xd10603ffULL) << 13);
    acc = (acc + a1 + 0xa9126ffcULL) ^ 0x0be998ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0326 | PC: 0x0289e0 | FDE: 0x0be0f0 | Size: 20 bytes
// Hàm FDE #0326 | Địa chỉ PC: 0x0289e0 | Địa chỉ FDE: 0x0be0f0 | Kích thước: 20 bytes
//   0x0289e0: 39400008  ldrb     w8, [x0]
//   0x0289e4: 37000048  tbnz     w8, #0, #0x289ec
//   0x0289e8: D65F03C0  ret      
//   0x0289ec: F9400800  ldr      x0, [x0, #0x10]
static inline uint64_t fde_func_0326_0x0289e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0289e0ULL ^ (static_cast<uint64_t>(0x39400008ULL) << 13);
    acc = (acc + a1 + 0x37000048ULL) ^ 0x0be0f0ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0327 | PC: 0x0289f4 | FDE: 0x0be108 | Size: 72 bytes
// Hàm FDE #0327 | Địa chỉ PC: 0x0289f4 | Địa chỉ FDE: 0x0be108 | Kích thước: 72 bytes
//   0x0289f4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0289f8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0289fc: 910043FD  add      x29, sp, #0x10
//   0x028a00: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0327_0x0289f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0289f4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0be108ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0328 | PC: 0x028a3c | FDE: 0x0be128 | Size: 8 bytes
// Hàm FDE #0328 | Địa chỉ PC: 0x028a3c | Địa chỉ FDE: 0x0be128 | Kích thước: 8 bytes
//   0x028a3c: 91002000  add      x0, x0, #8
//   0x028a40: 17FFA788  b        #0x12860
static inline uint64_t fde_func_0328_0x028a3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x028a3cULL ^ (static_cast<uint64_t>(0x91002000ULL) << 13);
    acc = (acc + a1 + 0x17ffa788ULL) ^ 0x0be128ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0329 | PC: 0x028a44 | FDE: 0x0be140 | Size: 40 bytes
// Hàm FDE #0329 | Địa chỉ PC: 0x028a44 | Địa chỉ FDE: 0x0be140 | Kích thước: 40 bytes
//   0x028a44: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x028a48: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x028a4c: 910043FD  add      x29, sp, #0x10
//   0x028a50: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0329_0x028a44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x028a44ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0be140ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0330 | PC: 0x028a6c | FDE: 0x0be160 | Size: 20 bytes
// Hàm FDE #0330 | Địa chỉ PC: 0x028a6c | Địa chỉ FDE: 0x0be160 | Kích thước: 20 bytes
//   0x028a6c: F9400008  ldr      x8, [x0]
//   0x028a70: F85E8108  ldur     x8, [x8, #-0x18]
//   0x028a74: 8B080008  add      x8, x0, x8
//   0x028a78: 91002100  add      x0, x8, #8
static inline uint64_t fde_func_0330_0x028a6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x028a6cULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf85e8108ULL) ^ 0x0be160ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0331 | PC: 0x028a80 | FDE: 0x0be178 | Size: 48 bytes
// Hàm FDE #0331 | Địa chỉ PC: 0x028a80 | Địa chỉ FDE: 0x0be178 | Kích thước: 48 bytes
//   0x028a80: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x028a84: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x028a88: 910043FD  add      x29, sp, #0x10
//   0x028a8c: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0331_0x028a80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x028a80ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0be178ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0332 | PC: 0x028ab0 | FDE: 0x0be198 | Size: 72 bytes
// Hàm FDE #0332 | Địa chỉ PC: 0x028ab0 | Địa chỉ FDE: 0x0be198 | Kích thước: 72 bytes
//   0x028ab0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x028ab4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x028ab8: 910043FD  add      x29, sp, #0x10
//   0x028abc: F0000608  adrp     x8, #0xeb000
static inline uint64_t fde_func_0332_0x028ab0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x028ab0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0be198ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0333 | PC: 0x028af8 | FDE: 0x0be1b8 | Size: 84 bytes
// Hàm FDE #0333 | Địa chỉ PC: 0x028af8 | Địa chỉ FDE: 0x0be1b8 | Kích thước: 84 bytes
//   0x028af8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x028afc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x028b00: 910043FD  add      x29, sp, #0x10
//   0x028b04: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0333_0x028af8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x028af8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0be1b8ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0334 | PC: 0x028b4c | FDE: 0x0be9d0 | Size: 220 bytes
// Hàm FDE #0334 | Địa chỉ PC: 0x028b4c | Địa chỉ FDE: 0x0be9d0 | Kích thước: 220 bytes
//   0x028b4c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x028b50: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x028b54: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x028b58: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0334_0x028b4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x028b4cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0be9d0ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #0335 | PC: 0x028c28 | FDE: 0x0be1d8 | Size: 36 bytes
// Hàm FDE #0335 | Địa chỉ PC: 0x028c28 | Địa chỉ FDE: 0x0be1d8 | Kích thước: 36 bytes
//   0x028c28: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x028c2c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x028c30: 910043FD  add      x29, sp, #0x10
//   0x028c34: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0335_0x028c28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x028c28ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0be1d8ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0336 | PC: 0x028c4c | FDE: 0x0be1f8 | Size: 240 bytes
// Hàm FDE #0336 | Địa chỉ PC: 0x028c4c | Địa chỉ FDE: 0x0be1f8 | Kích thước: 240 bytes
//   0x028c4c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x028c50: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x028c54: 910043FD  add      x29, sp, #0x10
//   0x028c58: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0336_0x028c4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x028c4cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0be1f8ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #0337 | PC: 0x028d3c | FDE: 0x0be218 | Size: 248 bytes
// Hàm FDE #0337 | Địa chỉ PC: 0x028d3c | Địa chỉ FDE: 0x0be218 | Kích thước: 248 bytes
//   0x028d3c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x028d40: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x028d44: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x028d48: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0337_0x028d3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x028d3cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0be218ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0338 | PC: 0x028e34 | FDE: 0x0be240 | Size: 192 bytes
// Hàm FDE #0338 | Địa chỉ PC: 0x028e34 | Địa chỉ FDE: 0x0be240 | Kích thước: 192 bytes
//   0x028e34: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x028e38: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x028e3c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x028e40: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0338_0x028e34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x028e34ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0be240ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #0339 | PC: 0x028ef4 | FDE: 0x0be268 | Size: 112 bytes
// Hàm FDE #0339 | Địa chỉ PC: 0x028ef4 | Địa chỉ FDE: 0x0be268 | Kích thước: 112 bytes
//   0x028ef4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x028ef8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x028efc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x028f00: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0339_0x028ef4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x028ef4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0be268ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0340 | PC: 0x028f64 | FDE: 0x0be288 | Size: 256 bytes
// Hàm FDE #0340 | Địa chỉ PC: 0x028f64 | Địa chỉ FDE: 0x0be288 | Kích thước: 256 bytes
//   0x028f64: D10143FF  sub      sp, sp, #0x50
//   0x028f68: F9000BF7  str      x23, [sp, #0x10]
//   0x028f6c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x028f70: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0340_0x028f64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x028f64ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x0be288ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0341 | PC: 0x029154 | FDE: 0x0be2b0 | Size: 8 bytes
// Hàm FDE #0341 | Địa chỉ PC: 0x029154 | Địa chỉ FDE: 0x0be2b0 | Kích thước: 8 bytes
//   0x029154: AA1F03E0  mov      x0, xzr
//   0x029158: D65F03C0  ret      
static inline uint64_t fde_func_0341_0x029154(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x029154ULL ^ (static_cast<uint64_t>(0xaa1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0be2b0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0342 | PC: 0x02915c | FDE: 0x0be2c8 | Size: 200 bytes
// Hàm FDE #0342 | Địa chỉ PC: 0x02915c | Địa chỉ FDE: 0x0be2c8 | Kích thước: 200 bytes
//   0x02915c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x029160: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x029164: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x029168: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0342_0x02915c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02915cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0be2c8ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0343 | PC: 0x029224 | FDE: 0x0be2f0 | Size: 256 bytes
// Hàm FDE #0343 | Địa chỉ PC: 0x029224 | Địa chỉ FDE: 0x0be2f0 | Kích thước: 256 bytes
//   0x029224: D10183FF  sub      sp, sp, #0x60
//   0x029228: F90013F7  str      x23, [sp, #0x20]
//   0x02922c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x029230: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0343_0x029224(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x029224ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x0be2f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0344 | PC: 0x0294a0 | FDE: 0x0be318 | Size: 64 bytes
// Hàm FDE #0344 | Địa chỉ PC: 0x0294a0 | Địa chỉ FDE: 0x0be318 | Kích thước: 64 bytes
//   0x0294a0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0294a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0294a8: 910043FD  add      x29, sp, #0x10
//   0x0294ac: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0344_0x0294a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0294a0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0be318ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0345 | PC: 0x0294e0 | FDE: 0x0be338 | Size: 96 bytes
// Hàm FDE #0345 | Địa chỉ PC: 0x0294e0 | Địa chỉ FDE: 0x0be338 | Kích thước: 96 bytes
//   0x0294e0: F9403C09  ldr      x9, [x0, #0x78]
//   0x0294e4: B4000229  cbz      x9, #0x29528
//   0x0294e8: A941240A  ldp      x10, x9, [x0, #0x10]
//   0x0294ec: AA0003E8  mov      x8, x0
static inline uint64_t fde_func_0345_0x0294e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0294e0ULL ^ (static_cast<uint64_t>(0xf9403c09ULL) << 13);
    acc = (acc + a1 + 0xb4000229ULL) ^ 0x0be338ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0346 | PC: 0x029540 | FDE: 0x0be350 | Size: 200 bytes
// Hàm FDE #0346 | Địa chỉ PC: 0x029540 | Địa chỉ FDE: 0x0be350 | Kích thước: 200 bytes
//   0x029540: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x029544: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x029548: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x02954c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0346_0x029540(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x029540ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0be350ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0347 | PC: 0x029608 | FDE: 0x0be378 | Size: 256 bytes
// Hàm FDE #0347 | Địa chỉ PC: 0x029608 | Địa chỉ FDE: 0x0be378 | Kích thước: 256 bytes
//   0x029608: D101C3FF  sub      sp, sp, #0x70
//   0x02960c: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x029610: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x029614: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0347_0x029608(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x029608ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x0be378ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0348 | PC: 0x029840 | FDE: 0x0be3a8 | Size: 20 bytes
// Hàm FDE #0348 | Địa chỉ PC: 0x029840 | Địa chỉ FDE: 0x0be3a8 | Kích thước: 20 bytes
//   0x029840: D0000608  adrp     x8, #0xeb000
//   0x029844: F9473108  ldr      x8, [x8, #0xe60]
//   0x029848: 91004108  add      x8, x8, #0x10
//   0x02984c: F8008408  str      x8, [x0], #8
static inline uint64_t fde_func_0348_0x029840(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x029840ULL ^ (static_cast<uint64_t>(0xd0000608ULL) << 13);
    acc = (acc + a1 + 0xf9473108ULL) ^ 0x0be3a8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0349 | PC: 0x029854 | FDE: 0x0be3c0 | Size: 52 bytes
// Hàm FDE #0349 | Địa chỉ PC: 0x029854 | Địa chỉ FDE: 0x0be3c0 | Kích thước: 52 bytes
//   0x029854: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x029858: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02985c: 910043FD  add      x29, sp, #0x10
//   0x029860: D0000608  adrp     x8, #0xeb000
static inline uint64_t fde_func_0349_0x029854(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x029854ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0be3c0ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0350 | PC: 0x029888 | FDE: 0x0be3e0 | Size: 4 bytes
// Hàm FDE #0350 | Địa chỉ PC: 0x029888 | Địa chỉ FDE: 0x0be3e0 | Kích thước: 4 bytes
//   0x029888: D65F03C0  ret      
static inline uint64_t fde_func_0350_0x029888(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x029888ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0be3e0ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0351 | PC: 0x02988c | FDE: 0x0be3f8 | Size: 4 bytes
// Hàm FDE #0351 | Địa chỉ PC: 0x02988c | Địa chỉ FDE: 0x0be3f8 | Kích thước: 4 bytes
//   0x02988c: D65F03C0  ret      
static inline uint64_t fde_func_0351_0x02988c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02988cULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0x92800001ULL) ^ 0x0be3f8ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0352 | PC: 0x029890 | FDE: 0x0be410 | Size: 12 bytes
// Hàm FDE #0352 | Địa chỉ PC: 0x029890 | Địa chỉ FDE: 0x0be410 | Kích thước: 12 bytes
//   0x029890: 92800001  mov      x1, #-1
//   0x029894: AA1F03E0  mov      x0, xzr
//   0x029898: D65F03C0  ret      
static inline uint64_t fde_func_0352_0x029890(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x029890ULL ^ (static_cast<uint64_t>(0x92800001ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e0ULL) ^ 0x0be410ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0353 | PC: 0x02989c | FDE: 0x0be428 | Size: 12 bytes
// Hàm FDE #0353 | Địa chỉ PC: 0x02989c | Địa chỉ FDE: 0x0be428 | Kích thước: 12 bytes
//   0x02989c: 92800001  mov      x1, #-1
//   0x0298a0: AA1F03E0  mov      x0, xzr
//   0x0298a4: D65F03C0  ret      
static inline uint64_t fde_func_0353_0x02989c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02989cULL ^ (static_cast<uint64_t>(0x92800001ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e0ULL) ^ 0x0be428ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0354 | PC: 0x0298a8 | FDE: 0x0be440 | Size: 8 bytes
// Hàm FDE #0354 | Địa chỉ PC: 0x0298a8 | Địa chỉ FDE: 0x0be440 | Kích thước: 8 bytes
//   0x0298a8: 2A1F03E0  mov      w0, wzr
//   0x0298ac: D65F03C0  ret      
static inline uint64_t fde_func_0354_0x0298a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0298a8ULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0be440ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0355 | PC: 0x0298b0 | FDE: 0x0be458 | Size: 8 bytes
// Hàm FDE #0355 | Địa chỉ PC: 0x0298b0 | Địa chỉ FDE: 0x0be458 | Kích thước: 8 bytes
//   0x0298b0: 12800000  mov      w0, #-1
//   0x0298b4: D65F03C0  ret      
static inline uint64_t fde_func_0355_0x0298b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0298b0ULL ^ (static_cast<uint64_t>(0x12800000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0be458ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0356 | PC: 0x0298b8 | FDE: 0x0be470 | Size: 8 bytes
// Hàm FDE #0356 | Địa chỉ PC: 0x0298b8 | Địa chỉ FDE: 0x0be470 | Kích thước: 8 bytes
//   0x0298b8: 12800000  mov      w0, #-1
//   0x0298bc: D65F03C0  ret      
static inline uint64_t fde_func_0356_0x0298b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0298b8ULL ^ (static_cast<uint64_t>(0x12800000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0be470ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0357 | PC: 0x0298c0 | FDE: 0x0be488 | Size: 8 bytes
// Hàm FDE #0357 | Địa chỉ PC: 0x0298c0 | Địa chỉ FDE: 0x0be488 | Kích thước: 8 bytes
//   0x0298c0: 12800000  mov      w0, #-1
//   0x0298c4: D65F03C0  ret      
static inline uint64_t fde_func_0357_0x0298c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0298c0ULL ^ (static_cast<uint64_t>(0x12800000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0be488ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0358 | PC: 0x0298c8 | FDE: 0x0be4a0 | Size: 52 bytes
// Hàm FDE #0358 | Địa chỉ PC: 0x0298c8 | Địa chỉ FDE: 0x0be4a0 | Kích thước: 52 bytes
//   0x0298c8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0298cc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0298d0: 910043FD  add      x29, sp, #0x10
//   0x0298d4: 52800100  mov      w0, #8
static inline uint64_t fde_func_0358_0x0298c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0298c8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0be4a0ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0359 | PC: 0x0298fc | FDE: 0x0be4c0 | Size: 120 bytes
// Hàm FDE #0359 | Địa chỉ PC: 0x0298fc | Địa chỉ FDE: 0x0be4c0 | Kích thước: 120 bytes
//   0x0298fc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x029900: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x029904: 910043FD  add      x29, sp, #0x10
//   0x029908: D0000608  adrp     x8, #0xeb000
static inline uint64_t fde_func_0359_0x0298fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0298fcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0be4c0ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0360 | PC: 0x029974 | FDE: 0x0be4e0 | Size: 128 bytes
// Hàm FDE #0360 | Địa chỉ PC: 0x029974 | Địa chỉ FDE: 0x0be4e0 | Kích thước: 128 bytes
//   0x029974: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x029978: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02997c: 910043FD  add      x29, sp, #0x10
//   0x029980: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0360_0x029974(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x029974ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0be4e0ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0361 | PC: 0x0299f4 | FDE: 0x0be500 | Size: 8 bytes
// Hàm FDE #0361 | Địa chỉ PC: 0x0299f4 | Địa chỉ FDE: 0x0be500 | Kích thước: 8 bytes
//   0x0299f4: 91004000  add      x0, x0, #0x10
//   0x0299f8: 17FFA39A  b        #0x12860
static inline uint64_t fde_func_0361_0x0299f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0299f4ULL ^ (static_cast<uint64_t>(0x91004000ULL) << 13);
    acc = (acc + a1 + 0x17ffa39aULL) ^ 0x0be500ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0362 | PC: 0x0299fc | FDE: 0x0be518 | Size: 40 bytes
// Hàm FDE #0362 | Địa chỉ PC: 0x0299fc | Địa chỉ FDE: 0x0be518 | Kích thước: 40 bytes
//   0x0299fc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x029a00: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x029a04: 910043FD  add      x29, sp, #0x10
//   0x029a08: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0362_0x0299fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0299fcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0be518ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0363 | PC: 0x029a24 | FDE: 0x0be538 | Size: 20 bytes
// Hàm FDE #0363 | Địa chỉ PC: 0x029a24 | Địa chỉ FDE: 0x0be538 | Kích thước: 20 bytes
//   0x029a24: F9400008  ldr      x8, [x0]
//   0x029a28: F85E8108  ldur     x8, [x8, #-0x18]
//   0x029a2c: 8B080008  add      x8, x0, x8
//   0x029a30: 91004100  add      x0, x8, #0x10
static inline uint64_t fde_func_0363_0x029a24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x029a24ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf85e8108ULL) ^ 0x0be538ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0364 | PC: 0x029a38 | FDE: 0x0be550 | Size: 48 bytes
// Hàm FDE #0364 | Địa chỉ PC: 0x029a38 | Địa chỉ FDE: 0x0be550 | Kích thước: 48 bytes
//   0x029a38: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x029a3c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x029a40: 910043FD  add      x29, sp, #0x10
//   0x029a44: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0364_0x029a38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x029a38ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0be550ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0365 | PC: 0x029a68 | FDE: 0x0be570 | Size: 124 bytes
// Hàm FDE #0365 | Địa chỉ PC: 0x029a68 | Địa chỉ FDE: 0x0be570 | Kích thước: 124 bytes
//   0x029a68: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x029a6c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x029a70: 910043FD  add      x29, sp, #0x10
//   0x029a74: D0000608  adrp     x8, #0xeb000
static inline uint64_t fde_func_0365_0x029a68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x029a68ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0be570ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0366 | PC: 0x029ae4 | FDE: 0x0be590 | Size: 128 bytes
// Hàm FDE #0366 | Địa chỉ PC: 0x029ae4 | Địa chỉ FDE: 0x0be590 | Kích thước: 128 bytes
//   0x029ae4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x029ae8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x029aec: 910043FD  add      x29, sp, #0x10
//   0x029af0: D0000608  adrp     x8, #0xeb000
static inline uint64_t fde_func_0366_0x029ae4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x029ae4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0be590ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// Shard 1 Dispatcher / Bộ điều phối phân mảnh 1
uint64_t execute_fde_shard_1(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 0: return fde_func_0000_0x0131b0(a0, a1);
        case 1: return fde_func_0001_0x013254(a0, a1);
        case 2: return fde_func_0002_0x013298(a0, a1);
        case 3: return fde_func_0003_0x013490(a0, a1);
        case 4: return fde_func_0004_0x013534(a0, a1);
        case 5: return fde_func_0005_0x013568(a0, a1);
        case 6: return fde_func_0006_0x01359c(a0, a1);
        case 7: return fde_func_0007_0x0135dc(a0, a1);
        case 8: return fde_func_0008_0x01361c(a0, a1);
        case 9: return fde_func_0009_0x01365c(a0, a1);
        case 10: return fde_func_0010_0x01369c(a0, a1);
        case 11: return fde_func_0011_0x0136dc(a0, a1);
        case 12: return fde_func_0012_0x01371c(a0, a1);
        case 13: return fde_func_0013_0x013750(a0, a1);
        case 14: return fde_func_0014_0x013784(a0, a1);
        case 15: return fde_func_0015_0x0137c4(a0, a1);
        case 16: return fde_func_0016_0x013804(a0, a1);
        case 17: return fde_func_0017_0x0138a8(a0, a1);
        case 18: return fde_func_0018_0x0138ec(a0, a1);
        case 19: return fde_func_0019_0x013930(a0, a1);
        case 20: return fde_func_0020_0x013a18(a0, a1);
        case 21: return fde_func_0021_0x013a60(a0, a1);
        case 22: return fde_func_0022_0x013b48(a0, a1);
        case 23: return fde_func_0023_0x013b90(a0, a1);
        case 24: return fde_func_0024_0x013c78(a0, a1);
        case 25: return fde_func_0025_0x013cc0(a0, a1);
        case 26: return fde_func_0026_0x013da8(a0, a1);
        case 27: return fde_func_0027_0x013df0(a0, a1);
        case 28: return fde_func_0028_0x013ed8(a0, a1);
        case 29: return fde_func_0029_0x013f20(a0, a1);
        case 30: return fde_func_0030_0x014008(a0, a1);
        case 31: return fde_func_0031_0x014050(a0, a1);
        case 32: return fde_func_0032_0x014138(a0, a1);
        case 33: return fde_func_0033_0x014180(a0, a1);
        case 34: return fde_func_0034_0x014268(a0, a1);
        case 35: return fde_func_0035_0x0142b0(a0, a1);
        case 36: return fde_func_0036_0x014398(a0, a1);
        case 37: return fde_func_0037_0x0143e0(a0, a1);
        case 38: return fde_func_0038_0x0144c8(a0, a1);
        case 39: return fde_func_0039_0x014510(a0, a1);
        case 40: return fde_func_0040_0x0145f8(a0, a1);
        case 41: return fde_func_0041_0x014640(a0, a1);
        case 42: return fde_func_0042_0x014728(a0, a1);
        case 43: return fde_func_0043_0x014770(a0, a1);
        case 44: return fde_func_0044_0x014858(a0, a1);
        case 45: return fde_func_0045_0x0148a0(a0, a1);
        case 46: return fde_func_0046_0x014988(a0, a1);
        case 47: return fde_func_0047_0x0149d0(a0, a1);
        case 48: return fde_func_0048_0x014ab8(a0, a1);
        case 49: return fde_func_0049_0x014b00(a0, a1);
        case 50: return fde_func_0050_0x014be8(a0, a1);
        case 51: return fde_func_0051_0x014c30(a0, a1);
        case 52: return fde_func_0052_0x014d18(a0, a1);
        case 53: return fde_func_0053_0x014d60(a0, a1);
        case 54: return fde_func_0054_0x014e48(a0, a1);
        case 55: return fde_func_0055_0x014e90(a0, a1);
        case 56: return fde_func_0056_0x014f78(a0, a1);
        case 57: return fde_func_0057_0x014fc0(a0, a1);
        case 58: return fde_func_0058_0x0150a8(a0, a1);
        case 59: return fde_func_0059_0x0150f0(a0, a1);
        case 60: return fde_func_0060_0x0151d8(a0, a1);
        case 61: return fde_func_0061_0x015220(a0, a1);
        case 62: return fde_func_0062_0x015308(a0, a1);
        case 63: return fde_func_0063_0x015350(a0, a1);
        case 64: return fde_func_0064_0x015438(a0, a1);
        case 65: return fde_func_0065_0x015480(a0, a1);
        case 66: return fde_func_0066_0x015568(a0, a1);
        case 67: return fde_func_0067_0x0155b0(a0, a1);
        case 68: return fde_func_0068_0x015698(a0, a1);
        case 69: return fde_func_0069_0x0156e0(a0, a1);
        case 70: return fde_func_0070_0x0157c8(a0, a1);
        case 71: return fde_func_0071_0x015810(a0, a1);
        case 72: return fde_func_0072_0x0158f8(a0, a1);
        case 73: return fde_func_0073_0x015940(a0, a1);
        case 74: return fde_func_0074_0x015a28(a0, a1);
        case 75: return fde_func_0075_0x015a70(a0, a1);
        case 76: return fde_func_0076_0x015b58(a0, a1);
        case 77: return fde_func_0077_0x015ba0(a0, a1);
        case 78: return fde_func_0078_0x015c88(a0, a1);
        case 79: return fde_func_0079_0x015cd0(a0, a1);
        case 80: return fde_func_0080_0x015db8(a0, a1);
        case 81: return fde_func_0081_0x015e00(a0, a1);
        case 82: return fde_func_0082_0x015ee8(a0, a1);
        case 83: return fde_func_0083_0x015f30(a0, a1);
        case 84: return fde_func_0084_0x016018(a0, a1);
        case 85: return fde_func_0085_0x016060(a0, a1);
        case 86: return fde_func_0086_0x016148(a0, a1);
        case 87: return fde_func_0087_0x016190(a0, a1);
        case 88: return fde_func_0088_0x016278(a0, a1);
        case 89: return fde_func_0089_0x0162c0(a0, a1);
        case 90: return fde_func_0090_0x0163a8(a0, a1);
        case 91: return fde_func_0091_0x0163f0(a0, a1);
        case 92: return fde_func_0092_0x0164d8(a0, a1);
        case 93: return fde_func_0093_0x016520(a0, a1);
        case 94: return fde_func_0094_0x016608(a0, a1);
        case 95: return fde_func_0095_0x016650(a0, a1);
        case 96: return fde_func_0096_0x016738(a0, a1);
        case 97: return fde_func_0097_0x016780(a0, a1);
        case 98: return fde_func_0098_0x016868(a0, a1);
        case 99: return fde_func_0099_0x0168b0(a0, a1);
        case 100: return fde_func_0100_0x016998(a0, a1);
        case 101: return fde_func_0101_0x0169e0(a0, a1);
        case 102: return fde_func_0102_0x016ac8(a0, a1);
        case 103: return fde_func_0103_0x016b10(a0, a1);
        case 104: return fde_func_0104_0x016bf8(a0, a1);
        case 105: return fde_func_0105_0x016c40(a0, a1);
        case 106: return fde_func_0106_0x016d28(a0, a1);
        case 107: return fde_func_0107_0x016d70(a0, a1);
        case 108: return fde_func_0108_0x016e58(a0, a1);
        case 109: return fde_func_0109_0x016ea0(a0, a1);
        case 110: return fde_func_0110_0x016f88(a0, a1);
        case 111: return fde_func_0111_0x016fd0(a0, a1);
        case 112: return fde_func_0112_0x0170b8(a0, a1);
        case 113: return fde_func_0113_0x017100(a0, a1);
        case 114: return fde_func_0114_0x0171e8(a0, a1);
        case 115: return fde_func_0115_0x017230(a0, a1);
        case 116: return fde_func_0116_0x017318(a0, a1);
        case 117: return fde_func_0117_0x017360(a0, a1);
        case 118: return fde_func_0118_0x017448(a0, a1);
        case 119: return fde_func_0119_0x017490(a0, a1);
        case 120: return fde_func_0120_0x017578(a0, a1);
        case 121: return fde_func_0121_0x0175c0(a0, a1);
        case 122: return fde_func_0122_0x0176a8(a0, a1);
        case 123: return fde_func_0123_0x0176f0(a0, a1);
        case 124: return fde_func_0124_0x0177d8(a0, a1);
        case 125: return fde_func_0125_0x017820(a0, a1);
        case 126: return fde_func_0126_0x0178e4(a0, a1);
        case 127: return fde_func_0127_0x017900(a0, a1);
        case 128: return fde_func_0128_0x0179e0(a0, a1);
        case 129: return fde_func_0129_0x017a64(a0, a1);
        case 130: return fde_func_0130_0x017b48(a0, a1);
        case 131: return fde_func_0131_0x017b98(a0, a1);
        case 132: return fde_func_0132_0x017bc8(a0, a1);
        case 133: return fde_func_0133_0x017bd4(a0, a1);
        case 134: return fde_func_0134_0x017c04(a0, a1);
        case 135: return fde_func_0135_0x017c3c(a0, a1);
        case 136: return fde_func_0136_0x017c48(a0, a1);
        case 137: return fde_func_0137_0x017c4c(a0, a1);
        case 138: return fde_func_0138_0x017cf0(a0, a1);
        case 139: return fde_func_0139_0x017d14(a0, a1);
        case 140: return fde_func_0140_0x017f3c(a0, a1);
        case 141: return fde_func_0141_0x0181b4(a0, a1);
        case 142: return fde_func_0142_0x0182d0(a0, a1);
        case 143: return fde_func_0143_0x018400(a0, a1);
        case 144: return fde_func_0144_0x018530(a0, a1);
        case 145: return fde_func_0145_0x0185dc(a0, a1);
        case 146: return fde_func_0146_0x0186a4(a0, a1);
        case 147: return fde_func_0147_0x0187dc(a0, a1);
        case 148: return fde_func_0148_0x0187f0(a0, a1);
        case 149: return fde_func_0149_0x018988(a0, a1);
        case 150: return fde_func_0150_0x018b54(a0, a1);
        case 151: return fde_func_0151_0x018ed4(a0, a1);
        case 152: return fde_func_0152_0x018fd8(a0, a1);
        case 153: return fde_func_0153_0x019124(a0, a1);
        case 154: return fde_func_0154_0x01923c(a0, a1);
        case 155: return fde_func_0155_0x01926c(a0, a1);
        case 156: return fde_func_0156_0x0192a4(a0, a1);
        case 157: return fde_func_0157_0x0192b0(a0, a1);
        case 158: return fde_func_0158_0x0192b4(a0, a1);
        case 159: return fde_func_0159_0x0195ec(a0, a1);
        case 160: return fde_func_0160_0x0196d0(a0, a1);
        case 161: return fde_func_0161_0x019940(a0, a1);
        case 162: return fde_func_0162_0x019a1c(a0, a1);
        case 163: return fde_func_0163_0x019ab8(a0, a1);
        case 164: return fde_func_0164_0x019acc(a0, a1);
        case 165: return fde_func_0165_0x019b70(a0, a1);
        case 166: return fde_func_0166_0x019c08(a0, a1);
        case 167: return fde_func_0167_0x019c1c(a0, a1);
        case 168: return fde_func_0168_0x01a478(a0, a1);
        case 169: return fde_func_0169_0x01a4d0(a0, a1);
        case 170: return fde_func_0170_0x01a50c(a0, a1);
        case 171: return fde_func_0171_0x01a564(a0, a1);
        case 172: return fde_func_0172_0x01a5bc(a0, a1);
        case 173: return fde_func_0173_0x01a614(a0, a1);
        case 174: return fde_func_0174_0x01a66c(a0, a1);
        case 175: return fde_func_0175_0x01a67c(a0, a1);
        case 176: return fde_func_0176_0x01aa88(a0, a1);
        case 177: return fde_func_0177_0x01aa90(a0, a1);
        case 178: return fde_func_0178_0x01aab4(a0, a1);
        case 179: return fde_func_0179_0x01aadc(a0, a1);
        case 180: return fde_func_0180_0x01aaf0(a0, a1);
        case 181: return fde_func_0181_0x01ad8c(a0, a1);
        case 182: return fde_func_0182_0x01b064(a0, a1);
        case 183: return fde_func_0183_0x01b6b0(a0, a1);
        case 184: return fde_func_0184_0x01c1d0(a0, a1);
        case 185: return fde_func_0185_0x01c330(a0, a1);
        case 186: return fde_func_0186_0x01cb3c(a0, a1);
        case 187: return fde_func_0187_0x01cbb4(a0, a1);
        case 188: return fde_func_0188_0x01d3c0(a0, a1);
        case 189: return fde_func_0189_0x01d988(a0, a1);
        case 190: return fde_func_0190_0x01e098(a0, a1);
        case 191: return fde_func_0191_0x01e11c(a0, a1);
        case 192: return fde_func_0192_0x01e780(a0, a1);
        case 193: return fde_func_0193_0x01eef0(a0, a1);
        case 194: return fde_func_0194_0x01ef6c(a0, a1);
        case 195: return fde_func_0195_0x01f4a4(a0, a1);
        case 196: return fde_func_0196_0x01f520(a0, a1);
        case 197: return fde_func_0197_0x01f65c(a0, a1);
        case 198: return fde_func_0198_0x01f924(a0, a1);
        case 199: return fde_func_0199_0x020f40(a0, a1);
        case 200: return fde_func_0200_0x020f48(a0, a1);
        case 201: return fde_func_0201_0x020f58(a0, a1);
        case 202: return fde_func_0202_0x020fe4(a0, a1);
        case 203: return fde_func_0203_0x0213e8(a0, a1);
        case 204: return fde_func_0204_0x021aa8(a0, a1);
        case 205: return fde_func_0205_0x021bf0(a0, a1);
        case 206: return fde_func_0206_0x021e6c(a0, a1);
        case 207: return fde_func_0207_0x0220d0(a0, a1);
        case 208: return fde_func_0208_0x02218c(a0, a1);
        case 209: return fde_func_0209_0x0223fc(a0, a1);
        case 210: return fde_func_0210_0x022520(a0, a1);
        case 211: return fde_func_0211_0x022610(a0, a1);
        case 212: return fde_func_0212_0x0226fc(a0, a1);
        case 213: return fde_func_0213_0x02279c(a0, a1);
        case 214: return fde_func_0214_0x0228c0(a0, a1);
        case 215: return fde_func_0215_0x0229d4(a0, a1);
        case 216: return fde_func_0216_0x022ab8(a0, a1);
        case 217: return fde_func_0217_0x022bd0(a0, a1);
        case 218: return fde_func_0218_0x022c64(a0, a1);
        case 219: return fde_func_0219_0x022cfc(a0, a1);
        case 220: return fde_func_0220_0x022d2c(a0, a1);
        case 221: return fde_func_0221_0x022d64(a0, a1);
        case 222: return fde_func_0222_0x022d6c(a0, a1);
        case 223: return fde_func_0223_0x022d70(a0, a1);
        case 224: return fde_func_0224_0x022da0(a0, a1);
        case 225: return fde_func_0225_0x022dd8(a0, a1);
        case 226: return fde_func_0226_0x022de0(a0, a1);
        case 227: return fde_func_0227_0x022de4(a0, a1);
        case 228: return fde_func_0228_0x022e14(a0, a1);
        case 229: return fde_func_0229_0x022e4c(a0, a1);
        case 230: return fde_func_0230_0x022e58(a0, a1);
        case 231: return fde_func_0231_0x022e5c(a0, a1);
        case 232: return fde_func_0232_0x022e90(a0, a1);
        case 233: return fde_func_0233_0x022fcc(a0, a1);
        case 234: return fde_func_0234_0x022ffc(a0, a1);
        case 235: return fde_func_0235_0x023034(a0, a1);
        case 236: return fde_func_0236_0x02303c(a0, a1);
        case 237: return fde_func_0237_0x023040(a0, a1);
        case 238: return fde_func_0238_0x023044(a0, a1);
        case 239: return fde_func_0239_0x02307c(a0, a1);
        case 240: return fde_func_0240_0x023094(a0, a1);
        case 241: return fde_func_0241_0x023098(a0, a1);
        case 242: return fde_func_0242_0x02309c(a0, a1);
        case 243: return fde_func_0243_0x023b64(a0, a1);
        case 244: return fde_func_0244_0x023b80(a0, a1);
        case 245: return fde_func_0245_0x023b8c(a0, a1);
        case 246: return fde_func_0246_0x023b90(a0, a1);
        case 247: return fde_func_0247_0x023b94(a0, a1);
        case 248: return fde_func_0248_0x023bcc(a0, a1);
        case 249: return fde_func_0249_0x023be4(a0, a1);
        case 250: return fde_func_0250_0x023be8(a0, a1);
        case 251: return fde_func_0251_0x023bec(a0, a1);
        case 252: return fde_func_0252_0x023bf4(a0, a1);
        case 253: return fde_func_0253_0x023c10(a0, a1);
        case 254: return fde_func_0254_0x023c1c(a0, a1);
        case 255: return fde_func_0255_0x023c50(a0, a1);
        case 256: return fde_func_0256_0x023c74(a0, a1);
        case 257: return fde_func_0257_0x023c94(a0, a1);
        case 258: return fde_func_0258_0x023cd0(a0, a1);
        case 259: return fde_func_0259_0x023d34(a0, a1);
        case 260: return fde_func_0260_0x023d7c(a0, a1);
        case 261: return fde_func_0261_0x023d90(a0, a1);
        case 262: return fde_func_0262_0x023dc0(a0, a1);
        case 263: return fde_func_0263_0x0249f0(a0, a1);
        case 264: return fde_func_0264_0x024a0c(a0, a1);
        case 265: return fde_func_0265_0x024a18(a0, a1);
        case 266: return fde_func_0266_0x024a1c(a0, a1);
        case 267: return fde_func_0267_0x024a20(a0, a1);
        case 268: return fde_func_0268_0x024a58(a0, a1);
        case 269: return fde_func_0269_0x024a70(a0, a1);
        case 270: return fde_func_0270_0x024a74(a0, a1);
        case 271: return fde_func_0271_0x024a78(a0, a1);
        case 272: return fde_func_0272_0x024a80(a0, a1);
        case 273: return fde_func_0273_0x024a9c(a0, a1);
        case 274: return fde_func_0274_0x024aa8(a0, a1);
        case 275: return fde_func_0275_0x024c74(a0, a1);
        case 276: return fde_func_0276_0x024d30(a0, a1);
        case 277: return fde_func_0277_0x024e7c(a0, a1);
        case 278: return fde_func_0278_0x024f08(a0, a1);
        case 279: return fde_func_0279_0x024f94(a0, a1);
        case 280: return fde_func_0280_0x025088(a0, a1);
        case 281: return fde_func_0281_0x025168(a0, a1);
        case 282: return fde_func_0282_0x0251e8(a0, a1);
        case 283: return fde_func_0283_0x025268(a0, a1);
        case 284: return fde_func_0284_0x0253e0(a0, a1);
        case 285: return fde_func_0285_0x0253fc(a0, a1);
        case 286: return fde_func_0286_0x025408(a0, a1);
        case 287: return fde_func_0287_0x02576c(a0, a1);
        case 288: return fde_func_0288_0x025850(a0, a1);
        case 289: return fde_func_0289_0x025ac0(a0, a1);
        case 290: return fde_func_0290_0x025b0c(a0, a1);
        case 291: return fde_func_0291_0x025b54(a0, a1);
        case 292: return fde_func_0292_0x025be4(a0, a1);
        case 293: return fde_func_0293_0x025c60(a0, a1);
        case 294: return fde_func_0294_0x025ca0(a0, a1);
        case 295: return fde_func_0295_0x025cdc(a0, a1);
        case 296: return fde_func_0296_0x025e18(a0, a1);
        case 297: return fde_func_0297_0x025e34(a0, a1);
        case 298: return fde_func_0298_0x025e40(a0, a1);
        case 299: return fde_func_0299_0x02600c(a0, a1);
        case 300: return fde_func_0300_0x0260dc(a0, a1);
        case 301: return fde_func_0301_0x0260ec(a0, a1);
        case 302: return fde_func_0302_0x026144(a0, a1);
        case 303: return fde_func_0303_0x026218(a0, a1);
        case 304: return fde_func_0304_0x026220(a0, a1);
        case 305: return fde_func_0305_0x026244(a0, a1);
        case 306: return fde_func_0306_0x02626c(a0, a1);
        case 307: return fde_func_0307_0x0263ec(a0, a1);
        case 308: return fde_func_0308_0x0264d8(a0, a1);
        case 309: return fde_func_0309_0x0265a8(a0, a1);
        case 310: return fde_func_0310_0x02660c(a0, a1);
        case 311: return fde_func_0311_0x02675c(a0, a1);
        case 312: return fde_func_0312_0x026764(a0, a1);
        case 313: return fde_func_0313_0x0268a4(a0, a1);
        case 314: return fde_func_0314_0x026c4c(a0, a1);
        case 315: return fde_func_0315_0x0271d4(a0, a1);
        case 316: return fde_func_0316_0x0272ec(a0, a1);
        case 317: return fde_func_0317_0x02731c(a0, a1);
        case 318: return fde_func_0318_0x027414(a0, a1);
        case 319: return fde_func_0319_0x0276f4(a0, a1);
        case 320: return fde_func_0320_0x027730(a0, a1);
        case 321: return fde_func_0321_0x027bfc(a0, a1);
        case 322: return fde_func_0322_0x027e04(a0, a1);
        case 323: return fde_func_0323_0x027e78(a0, a1);
        case 324: return fde_func_0324_0x027eb4(a0, a1);
        case 325: return fde_func_0325_0x028130(a0, a1);
        case 326: return fde_func_0326_0x0289e0(a0, a1);
        case 327: return fde_func_0327_0x0289f4(a0, a1);
        case 328: return fde_func_0328_0x028a3c(a0, a1);
        case 329: return fde_func_0329_0x028a44(a0, a1);
        case 330: return fde_func_0330_0x028a6c(a0, a1);
        case 331: return fde_func_0331_0x028a80(a0, a1);
        case 332: return fde_func_0332_0x028ab0(a0, a1);
        case 333: return fde_func_0333_0x028af8(a0, a1);
        case 334: return fde_func_0334_0x028b4c(a0, a1);
        case 335: return fde_func_0335_0x028c28(a0, a1);
        case 336: return fde_func_0336_0x028c4c(a0, a1);
        case 337: return fde_func_0337_0x028d3c(a0, a1);
        case 338: return fde_func_0338_0x028e34(a0, a1);
        case 339: return fde_func_0339_0x028ef4(a0, a1);
        case 340: return fde_func_0340_0x028f64(a0, a1);
        case 341: return fde_func_0341_0x029154(a0, a1);
        case 342: return fde_func_0342_0x02915c(a0, a1);
        case 343: return fde_func_0343_0x029224(a0, a1);
        case 344: return fde_func_0344_0x0294a0(a0, a1);
        case 345: return fde_func_0345_0x0294e0(a0, a1);
        case 346: return fde_func_0346_0x029540(a0, a1);
        case 347: return fde_func_0347_0x029608(a0, a1);
        case 348: return fde_func_0348_0x029840(a0, a1);
        case 349: return fde_func_0349_0x029854(a0, a1);
        case 350: return fde_func_0350_0x029888(a0, a1);
        case 351: return fde_func_0351_0x02988c(a0, a1);
        case 352: return fde_func_0352_0x029890(a0, a1);
        case 353: return fde_func_0353_0x02989c(a0, a1);
        case 354: return fde_func_0354_0x0298a8(a0, a1);
        case 355: return fde_func_0355_0x0298b0(a0, a1);
        case 356: return fde_func_0356_0x0298b8(a0, a1);
        case 357: return fde_func_0357_0x0298c0(a0, a1);
        case 358: return fde_func_0358_0x0298c8(a0, a1);
        case 359: return fde_func_0359_0x0298fc(a0, a1);
        case 360: return fde_func_0360_0x029974(a0, a1);
        case 361: return fde_func_0361_0x0299f4(a0, a1);
        case 362: return fde_func_0362_0x0299fc(a0, a1);
        case 363: return fde_func_0363_0x029a24(a0, a1);
        case 364: return fde_func_0364_0x029a38(a0, a1);
        case 365: return fde_func_0365_0x029a68(a0, a1);
        case 366: return fde_func_0366_0x029ae4(a0, a1);
        default: return 0ULL;
    }
}

} // namespace nuro