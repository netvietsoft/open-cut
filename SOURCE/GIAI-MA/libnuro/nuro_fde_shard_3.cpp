// ============================================================================
// Clean-Room C++17 AArch64 FDE Shard 3/5 for libnuro.so
// Phân mảnh FDE AArch64 C++17 sạch 3/5 cho libnuro.so
// Covers FDE indices [734 .. 1100] out of 1,835 total FDEs (.eh_frame_hdr @ 0x0b8c58)
// Bao phủ chỉ số FDE [734 .. 1100] trên tổng số 1,835 FDE (.eh_frame_hdr @ 0x0b8c58)
// ============================================================================
#include "nuro_core.h"

namespace nuro {

// FDE #0734 | PC: 0x05c138 | FDE: 0x0c2520 | Size: 256 bytes
// Hàm FDE #0734 | Địa chỉ PC: 0x05c138 | Địa chỉ FDE: 0x0c2520 | Kích thước: 256 bytes
//   0x05c138: D10243FF  sub      sp, sp, #0x90
//   0x05c13c: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x05c140: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x05c144: A9074FF4  stp      x20, x19, [sp, #0x70]
static inline uint64_t fde_func_0734_0x05c138(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05c138ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9055ff8ULL) ^ 0x0c2520ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0735 | PC: 0x05c34c | FDE: 0x0c2550 | Size: 256 bytes
// Hàm FDE #0735 | Địa chỉ PC: 0x05c34c | Địa chỉ FDE: 0x0c2550 | Kích thước: 256 bytes
//   0x05c34c: D101C3FF  sub      sp, sp, #0x70
//   0x05c350: F90023F5  str      x21, [sp, #0x40]
//   0x05c354: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x05c358: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0735_0x05c34c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05c34cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c2550ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0736 | PC: 0x05c5a0 | FDE: 0x0c2460 | Size: 204 bytes
// Hàm FDE #0736 | Địa chỉ PC: 0x05c5a0 | Địa chỉ FDE: 0x0c2460 | Kích thước: 204 bytes
//   0x05c5a0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x05c5a4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05c5a8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05c5ac: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0736_0x05c5a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05c5a0ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c2460ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #0737 | PC: 0x05c66c | FDE: 0x0c2578 | Size: 256 bytes
// Hàm FDE #0737 | Địa chỉ PC: 0x05c66c | Địa chỉ FDE: 0x0c2578 | Kích thước: 256 bytes
//   0x05c66c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x05c670: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05c674: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05c678: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0737_0x05c66c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05c66cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c2578ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0738 | PC: 0x05c778 | FDE: 0x0c25a8 | Size: 256 bytes
// Hàm FDE #0738 | Địa chỉ PC: 0x05c778 | Địa chỉ FDE: 0x0c25a8 | Kích thước: 256 bytes
//   0x05c778: D101C3FF  sub      sp, sp, #0x70
//   0x05c77c: F90023F5  str      x21, [sp, #0x40]
//   0x05c780: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x05c784: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0738_0x05c778(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05c778ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c25a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0739 | PC: 0x05c8d0 | FDE: 0x0c25d0 | Size: 256 bytes
// Hàm FDE #0739 | Địa chỉ PC: 0x05c8d0 | Địa chỉ FDE: 0x0c25d0 | Kích thước: 256 bytes
//   0x05c8d0: D10243FF  sub      sp, sp, #0x90
//   0x05c8d4: F90033F5  str      x21, [sp, #0x60]
//   0x05c8d8: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x05c8dc: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_0739_0x05c8d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05c8d0ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90033f5ULL) ^ 0x0c25d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0740 | PC: 0x05ca28 | FDE: 0x0c2488 | Size: 256 bytes
// Hàm FDE #0740 | Địa chỉ PC: 0x05ca28 | Địa chỉ FDE: 0x0c2488 | Kích thước: 256 bytes
//   0x05ca28: D101C3FF  sub      sp, sp, #0x70
//   0x05ca2c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x05ca30: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x05ca34: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0740_0x05ca28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05ca28ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x0c2488ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0741 | PC: 0x05cbbc | FDE: 0x0c25f8 | Size: 256 bytes
// Hàm FDE #0741 | Địa chỉ PC: 0x05cbbc | Địa chỉ FDE: 0x0c25f8 | Kích thước: 256 bytes
//   0x05cbbc: D10283FF  sub      sp, sp, #0xa0
//   0x05cbc0: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x05cbc4: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x05cbc8: A90757F6  stp      x22, x21, [sp, #0x70]
static inline uint64_t fde_func_0741_0x05cbbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05cbbcULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa90567faULL) ^ 0x0c25f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0742 | PC: 0x05cddc | FDE: 0x0c24b0 | Size: 196 bytes
// Hàm FDE #0742 | Địa chỉ PC: 0x05cddc | Địa chỉ FDE: 0x0c24b0 | Kích thước: 196 bytes
//   0x05cddc: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x05cde0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05cde4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05cde8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0742_0x05cddc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05cddcULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c24b0ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0743 | PC: 0x05cea0 | FDE: 0x0c2630 | Size: 256 bytes
// Hàm FDE #0743 | Địa chỉ PC: 0x05cea0 | Địa chỉ FDE: 0x0c2630 | Kích thước: 256 bytes
//   0x05cea0: D101C3FF  sub      sp, sp, #0x70
//   0x05cea4: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x05cea8: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x05ceac: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0743_0x05cea0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05cea0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x0c2630ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0744 | PC: 0x05d1a8 | FDE: 0x0c24d8 | Size: 256 bytes
// Hàm FDE #0744 | Địa chỉ PC: 0x05d1a8 | Địa chỉ FDE: 0x0c24d8 | Kích thước: 256 bytes
//   0x05d1a8: D10243FF  sub      sp, sp, #0x90
//   0x05d1ac: F9001BFB  str      x27, [sp, #0x30]
//   0x05d1b0: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x05d1b4: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0744_0x05d1a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05d1a8ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9001bfbULL) ^ 0x0c24d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0745 | PC: 0x05d478 | FDE: 0x0c2508 | Size: 256 bytes
// Hàm FDE #0745 | Địa chỉ PC: 0x05d478 | Địa chỉ FDE: 0x0c2508 | Kích thước: 256 bytes
//   0x05d478: AA0003E8  mov      x8, x0
//   0x05d47c: F940000A  ldr      x10, [x0]
//   0x05d480: F9400420  ldr      x0, [x1, #8]
//   0x05d484: EB02015F  cmp      x10, x2
static inline uint64_t fde_func_0745_0x05d478(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05d478ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xf940000aULL) ^ 0x0c2508ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0746 | PC: 0x05d5f4 | FDE: 0x0c26c8 | Size: 256 bytes
// Hàm FDE #0746 | Địa chỉ PC: 0x05d5f4 | Địa chỉ FDE: 0x0c26c8 | Kích thước: 256 bytes
//   0x05d5f4: D10383FF  sub      sp, sp, #0xe0
//   0x05d5f8: F90053F7  str      x23, [sp, #0xa0]
//   0x05d5fc: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x05d600: A90C4FF4  stp      x20, x19, [sp, #0xc0]
static inline uint64_t fde_func_0746_0x05d5f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05d5f4ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xf90053f7ULL) ^ 0x0c26c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0747 | PC: 0x05da30 | FDE: 0x0c26f8 | Size: 256 bytes
// Hàm FDE #0747 | Địa chỉ PC: 0x05da30 | Địa chỉ FDE: 0x0c26f8 | Kích thước: 256 bytes
//   0x05da30: D102C3FF  sub      sp, sp, #0xb0
//   0x05da34: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x05da38: A9094FF4  stp      x20, x19, [sp, #0x90]
//   0x05da3c: A90A7BFD  stp      x29, x30, [sp, #0xa0]
static inline uint64_t fde_func_0747_0x05da30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05da30ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa90857f6ULL) ^ 0x0c26f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0748 | PC: 0x05e1cc | FDE: 0x0c2728 | Size: 256 bytes
// Hàm FDE #0748 | Địa chỉ PC: 0x05e1cc | Địa chỉ FDE: 0x0c2728 | Kích thước: 256 bytes
//   0x05e1cc: D10183FF  sub      sp, sp, #0x60
//   0x05e1d0: F9001BF5  str      x21, [sp, #0x30]
//   0x05e1d4: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x05e1d8: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0748_0x05e1cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e1ccULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x0c2728ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0749 | PC: 0x05e428 | FDE: 0x0c2750 | Size: 256 bytes
// Hàm FDE #0749 | Địa chỉ PC: 0x05e428 | Địa chỉ FDE: 0x0c2750 | Kích thước: 256 bytes
//   0x05e428: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x05e42c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05e430: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05e434: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0749_0x05e428(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e428ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c2750ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0750 | PC: 0x05e624 | FDE: 0x0c26a0 | Size: 256 bytes
// Hàm FDE #0750 | Địa chỉ PC: 0x05e624 | Địa chỉ FDE: 0x0c26a0 | Kích thước: 256 bytes
//   0x05e624: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x05e628: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05e62c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05e630: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0750_0x05e624(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e624ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c26a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0751 | PC: 0x05e7e0 | FDE: 0x0c2780 | Size: 256 bytes
// Hàm FDE #0751 | Địa chỉ PC: 0x05e7e0 | Địa chỉ FDE: 0x0c2780 | Kích thước: 256 bytes
//   0x05e7e0: D101C3FF  sub      sp, sp, #0x70
//   0x05e7e4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x05e7e8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x05e7ec: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0751_0x05e7e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e7e0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x0c2780ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0752 | PC: 0x05e968 | FDE: 0x0c27b0 | Size: 256 bytes
// Hàm FDE #0752 | Địa chỉ PC: 0x05e968 | Địa chỉ FDE: 0x0c27b0 | Kích thước: 256 bytes
//   0x05e968: D101C3FF  sub      sp, sp, #0x70
//   0x05e96c: F90023F5  str      x21, [sp, #0x40]
//   0x05e970: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x05e974: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0752_0x05e968(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e968ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c27b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0753 | PC: 0x05eb24 | FDE: 0x0c2c40 | Size: 256 bytes
// Hàm FDE #0753 | Địa chỉ PC: 0x05eb24 | Địa chỉ FDE: 0x0c2c40 | Kích thước: 256 bytes
//   0x05eb24: D106C3FF  sub      sp, sp, #0x1b0
//   0x05eb28: A9175FFC  stp      x28, x23, [sp, #0x170]
//   0x05eb2c: A91857F6  stp      x22, x21, [sp, #0x180]
//   0x05eb30: A9194FF4  stp      x20, x19, [sp, #0x190]
static inline uint64_t fde_func_0753_0x05eb24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05eb24ULL ^ (static_cast<uint64_t>(0xd106c3ffULL) << 13);
    acc = (acc + a1 + 0xa9175ffcULL) ^ 0x0c2c40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0754 | PC: 0x05ef6c | FDE: 0x0c2c70 | Size: 256 bytes
// Hàm FDE #0754 | Địa chỉ PC: 0x05ef6c | Địa chỉ FDE: 0x0c2c70 | Kích thước: 256 bytes
//   0x05ef6c: D101C3FF  sub      sp, sp, #0x70
//   0x05ef70: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x05ef74: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x05ef78: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0754_0x05ef6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05ef6cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x0c2c70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0755 | PC: 0x05f1d0 | FDE: 0x0c2ca0 | Size: 256 bytes
// Hàm FDE #0755 | Địa chỉ PC: 0x05f1d0 | Địa chỉ FDE: 0x0c2ca0 | Kích thước: 256 bytes
//   0x05f1d0: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x05f1d4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x05f1d8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x05f1dc: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0755_0x05f1d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05f1d0ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c2ca0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0756 | PC: 0x05f3cc | FDE: 0x0c2cd8 | Size: 256 bytes
// Hàm FDE #0756 | Địa chỉ PC: 0x05f3cc | Địa chỉ FDE: 0x0c2cd8 | Kích thước: 256 bytes
//   0x05f3cc: D10203FF  sub      sp, sp, #0x80
//   0x05f3d0: F9002BF5  str      x21, [sp, #0x50]
//   0x05f3d4: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x05f3d8: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_0756_0x05f3cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05f3ccULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf5ULL) ^ 0x0c2cd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0757 | PC: 0x05f6c0 | FDE: 0x0c2d00 | Size: 256 bytes
// Hàm FDE #0757 | Địa chỉ PC: 0x05f6c0 | Địa chỉ FDE: 0x0c2d00 | Kích thước: 256 bytes
//   0x05f6c0: D10543FF  sub      sp, sp, #0x150
//   0x05f6c4: F9007BFC  str      x28, [sp, #0xf0]
//   0x05f6c8: A91067FA  stp      x26, x25, [sp, #0x100]
//   0x05f6cc: A9115FF8  stp      x24, x23, [sp, #0x110]
static inline uint64_t fde_func_0757_0x05f6c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05f6c0ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xf9007bfcULL) ^ 0x0c2d00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0758 | PC: 0x05fc0c | FDE: 0x0c2d38 | Size: 256 bytes
// Hàm FDE #0758 | Địa chỉ PC: 0x05fc0c | Địa chỉ FDE: 0x0c2d38 | Kích thước: 256 bytes
//   0x05fc0c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x05fc10: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x05fc14: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x05fc18: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0758_0x05fc0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05fc0cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0c2d38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0759 | PC: 0x060480 | FDE: 0x0c2d70 | Size: 256 bytes
// Hàm FDE #0759 | Địa chỉ PC: 0x060480 | Địa chỉ FDE: 0x0c2d70 | Kích thước: 256 bytes
//   0x060480: D10703FF  sub      sp, sp, #0x1c0
//   0x060484: A9166FFC  stp      x28, x27, [sp, #0x160]
//   0x060488: A91767FA  stp      x26, x25, [sp, #0x170]
//   0x06048c: A9185FF8  stp      x24, x23, [sp, #0x180]
static inline uint64_t fde_func_0759_0x060480(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060480ULL ^ (static_cast<uint64_t>(0xd10703ffULL) << 13);
    acc = (acc + a1 + 0xa9166ffcULL) ^ 0x0c2d70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0760 | PC: 0x060abc | FDE: 0x0c27d8 | Size: 256 bytes
// Hàm FDE #0760 | Địa chỉ PC: 0x060abc | Địa chỉ FDE: 0x0c27d8 | Kích thước: 256 bytes
//   0x060abc: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x060ac0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x060ac4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x060ac8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0760_0x060abc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060abcULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c27d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0761 | PC: 0x060bd8 | FDE: 0x0c2da8 | Size: 256 bytes
// Hàm FDE #0761 | Địa chỉ PC: 0x060bd8 | Địa chỉ FDE: 0x0c2da8 | Kích thước: 256 bytes
//   0x060bd8: D10483FF  sub      sp, sp, #0x120
//   0x060bdc: A90D67FC  stp      x28, x25, [sp, #0xd0]
//   0x060be0: A90E5FF8  stp      x24, x23, [sp, #0xe0]
//   0x060be4: A90F57F6  stp      x22, x21, [sp, #0xf0]
static inline uint64_t fde_func_0761_0x060bd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060bd8ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa90d67fcULL) ^ 0x0c2da8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0762 | PC: 0x061294 | FDE: 0x0c2800 | Size: 164 bytes
// Hàm FDE #0762 | Địa chỉ PC: 0x061294 | Địa chỉ FDE: 0x0c2800 | Kích thước: 164 bytes
//   0x061294: D10443FF  sub      sp, sp, #0x110
//   0x061298: A90F4FFC  stp      x28, x19, [sp, #0xf0]
//   0x06129c: A9107BFD  stp      x29, x30, [sp, #0x100]
//   0x0612a0: 910403FD  add      x29, sp, #0x100
static inline uint64_t fde_func_0762_0x061294(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061294ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90f4ffcULL) ^ 0x0c2800ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #0763 | PC: 0x061338 | FDE: 0x0c2de0 | Size: 256 bytes
// Hàm FDE #0763 | Địa chỉ PC: 0x061338 | Địa chỉ FDE: 0x0c2de0 | Kích thước: 256 bytes
//   0x061338: D10183FF  sub      sp, sp, #0x60
//   0x06133c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x061340: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x061344: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0763_0x061338(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061338ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x0c2de0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0764 | PC: 0x061860 | FDE: 0x0c2820 | Size: 220 bytes
// Hàm FDE #0764 | Địa chỉ PC: 0x061860 | Địa chỉ FDE: 0x0c2820 | Kích thước: 220 bytes
//   0x061860: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x061864: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x061868: 910043FD  add      x29, sp, #0x10
//   0x06186c: 3943A008  ldrb     w8, [x0, #0xe8]
static inline uint64_t fde_func_0764_0x061860(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061860ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c2820ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #0765 | PC: 0x06193c | FDE: 0x0c2840 | Size: 144 bytes
// Hàm FDE #0765 | Địa chỉ PC: 0x06193c | Địa chỉ FDE: 0x0c2840 | Kích thước: 144 bytes
//   0x06193c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x061940: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x061944: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x061948: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0765_0x06193c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06193cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c2840ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0766 | PC: 0x0619cc | FDE: 0x0c2860 | Size: 236 bytes
// Hàm FDE #0766 | Địa chỉ PC: 0x0619cc | Địa chỉ FDE: 0x0c2860 | Kích thước: 236 bytes
//   0x0619cc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0619d0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0619d4: 910043FD  add      x29, sp, #0x10
//   0x0619d8: 90000448  adrp     x8, #0xe9000
static inline uint64_t fde_func_0766_0x0619cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0619ccULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c2860ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0767 | PC: 0x061ab8 | FDE: 0x0c2880 | Size: 12 bytes
// Hàm FDE #0767 | Địa chỉ PC: 0x061ab8 | Địa chỉ FDE: 0x0c2880 | Kích thước: 12 bytes
//   0x061ab8: F8418C08  ldr      x8, [x0, #0x18]!
//   0x061abc: F9400101  ldr      x1, [x8]
//   0x061ac0: D61F0020  br       x1
static inline uint64_t fde_func_0767_0x061ab8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061ab8ULL ^ (static_cast<uint64_t>(0xf8418c08ULL) << 13);
    acc = (acc + a1 + 0xf9400101ULL) ^ 0x0c2880ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0768 | PC: 0x061ac4 | FDE: 0x0c2898 | Size: 4 bytes
// Hàm FDE #0768 | Địa chỉ PC: 0x061ac4 | Địa chỉ FDE: 0x0c2898 | Kích thước: 4 bytes
//   0x061ac4: 17FEC34F  b        #0x12800
static inline uint64_t fde_func_0768_0x061ac4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061ac4ULL ^ (static_cast<uint64_t>(0x17fec34fULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x0c2898ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0769 | PC: 0x061ac8 | FDE: 0x0c28b0 | Size: 136 bytes
// Hàm FDE #0769 | Địa chỉ PC: 0x061ac8 | Địa chỉ FDE: 0x0c28b0 | Kích thước: 136 bytes
//   0x061ac8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x061acc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x061ad0: 910043FD  add      x29, sp, #0x10
//   0x061ad4: 39416008  ldrb     w8, [x0, #0x58]
static inline uint64_t fde_func_0769_0x061ac8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061ac8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c28b0ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #0770 | PC: 0x061b50 | FDE: 0x0c28d0 | Size: 4 bytes
// Hàm FDE #0770 | Địa chỉ PC: 0x061b50 | Địa chỉ FDE: 0x0c28d0 | Kích thước: 4 bytes
//   0x061b50: D4200020  brk      #1
static inline uint64_t fde_func_0770_0x061b50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061b50ULL ^ (static_cast<uint64_t>(0xd4200020ULL) << 13);
    acc = (acc + a1 + 0xa9be4ff4ULL) ^ 0x0c28d0ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0771 | PC: 0x061b54 | FDE: 0x0c28e8 | Size: 104 bytes
// Hàm FDE #0771 | Địa chỉ PC: 0x061b54 | Địa chỉ FDE: 0x0c28e8 | Kích thước: 104 bytes
//   0x061b54: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x061b58: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x061b5c: 910043FD  add      x29, sp, #0x10
//   0x061b60: D0000449  adrp     x9, #0xeb000
static inline uint64_t fde_func_0771_0x061b54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061b54ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c28e8ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0772 | PC: 0x061bbc | FDE: 0x0c2908 | Size: 204 bytes
// Hàm FDE #0772 | Địa chỉ PC: 0x061bbc | Địa chỉ FDE: 0x0c2908 | Kích thước: 204 bytes
//   0x061bbc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x061bc0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x061bc4: 910043FD  add      x29, sp, #0x10
//   0x061bc8: 90000448  adrp     x8, #0xe9000
static inline uint64_t fde_func_0772_0x061bbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061bbcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c2908ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #0773 | PC: 0x061c88 | FDE: 0x0c2928 | Size: 12 bytes
// Hàm FDE #0773 | Địa chỉ PC: 0x061c88 | Địa chỉ FDE: 0x0c2928 | Kích thước: 12 bytes
//   0x061c88: F8418C08  ldr      x8, [x0, #0x18]!
//   0x061c8c: F9400101  ldr      x1, [x8]
//   0x061c90: D61F0020  br       x1
static inline uint64_t fde_func_0773_0x061c88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061c88ULL ^ (static_cast<uint64_t>(0xf8418c08ULL) << 13);
    acc = (acc + a1 + 0xf9400101ULL) ^ 0x0c2928ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0774 | PC: 0x061c94 | FDE: 0x0c2940 | Size: 4 bytes
// Hàm FDE #0774 | Địa chỉ PC: 0x061c94 | Địa chỉ FDE: 0x0c2940 | Kích thước: 4 bytes
//   0x061c94: 17FEC2DB  b        #0x12800
static inline uint64_t fde_func_0774_0x061c94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061c94ULL ^ (static_cast<uint64_t>(0x17fec2dbULL) << 13);
    acc = (acc + a1 + 0xf81d0ff5ULL) ^ 0x0c2940ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0775 | PC: 0x061c98 | FDE: 0x0c2958 | Size: 164 bytes
// Hàm FDE #0775 | Địa chỉ PC: 0x061c98 | Địa chỉ FDE: 0x0c2958 | Kích thước: 164 bytes
//   0x061c98: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x061c9c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x061ca0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x061ca4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0775_0x061c98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061c98ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c2958ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #0776 | PC: 0x061d3c | FDE: 0x0c2978 | Size: 256 bytes
// Hàm FDE #0776 | Địa chỉ PC: 0x061d3c | Địa chỉ FDE: 0x0c2978 | Kích thước: 256 bytes
//   0x061d3c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x061d40: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x061d44: 910043FD  add      x29, sp, #0x10
//   0x061d48: 90000448  adrp     x8, #0xe9000
static inline uint64_t fde_func_0776_0x061d3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061d3cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c2978ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0777 | PC: 0x061e3c | FDE: 0x0c2998 | Size: 12 bytes
// Hàm FDE #0777 | Địa chỉ PC: 0x061e3c | Địa chỉ FDE: 0x0c2998 | Kích thước: 12 bytes
//   0x061e3c: F8418C08  ldr      x8, [x0, #0x18]!
//   0x061e40: F9400101  ldr      x1, [x8]
//   0x061e44: D61F0020  br       x1
static inline uint64_t fde_func_0777_0x061e3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061e3cULL ^ (static_cast<uint64_t>(0xf8418c08ULL) << 13);
    acc = (acc + a1 + 0xf9400101ULL) ^ 0x0c2998ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0778 | PC: 0x061e48 | FDE: 0x0c29b0 | Size: 4 bytes
// Hàm FDE #0778 | Địa chỉ PC: 0x061e48 | Địa chỉ FDE: 0x0c29b0 | Kích thước: 4 bytes
//   0x061e48: 17FEC26E  b        #0x12800
static inline uint64_t fde_func_0778_0x061e48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061e48ULL ^ (static_cast<uint64_t>(0x17fec26eULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x0c29b0ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0779 | PC: 0x061e4c | FDE: 0x0c29c8 | Size: 52 bytes
// Hàm FDE #0779 | Địa chỉ PC: 0x061e4c | Địa chỉ FDE: 0x0c29c8 | Kích thước: 52 bytes
//   0x061e4c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x061e50: 910003FD  mov      x29, sp
//   0x061e54: 52800100  mov      w0, #8
//   0x061e58: 97FEC296  bl       #0x128b0
static inline uint64_t fde_func_0779_0x061e4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061e4cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0c29c8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0780 | PC: 0x061e80 | FDE: 0x0c2e10 | Size: 236 bytes
// Hàm FDE #0780 | Địa chỉ PC: 0x061e80 | Địa chỉ FDE: 0x0c2e10 | Kích thước: 236 bytes
//   0x061e80: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x061e84: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x061e88: 910043FD  add      x29, sp, #0x10
//   0x061e8c: 3940C008  ldrb     w8, [x0, #0x30]
static inline uint64_t fde_func_0780_0x061e80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061e80ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c2e10ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0781 | PC: 0x061f6c | FDE: 0x0c29e8 | Size: 256 bytes
// Hàm FDE #0781 | Địa chỉ PC: 0x061f6c | Địa chỉ FDE: 0x0c29e8 | Kích thước: 256 bytes
//   0x061f6c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x061f70: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x061f74: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x061f78: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0781_0x061f6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061f6cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c29e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0782 | PC: 0x0620b8 | FDE: 0x0c2a08 | Size: 156 bytes
// Hàm FDE #0782 | Địa chỉ PC: 0x0620b8 | Địa chỉ FDE: 0x0c2a08 | Kích thước: 156 bytes
//   0x0620b8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0620bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0620c0: 910043FD  add      x29, sp, #0x10
//   0x0620c4: 39408008  ldrb     w8, [x0, #0x20]
static inline uint64_t fde_func_0782_0x0620b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0620b8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c2a08ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0783 | PC: 0x062154 | FDE: 0x0c2a28 | Size: 256 bytes
// Hàm FDE #0783 | Địa chỉ PC: 0x062154 | Địa chỉ FDE: 0x0c2a28 | Kích thước: 256 bytes
//   0x062154: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x062158: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06215c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x062160: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0783_0x062154(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062154ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c2a28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0784 | PC: 0x0622d8 | FDE: 0x0c2e38 | Size: 256 bytes
// Hàm FDE #0784 | Địa chỉ PC: 0x0622d8 | Địa chỉ FDE: 0x0c2e38 | Kích thước: 256 bytes
//   0x0622d8: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0622dc: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0622e0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0622e4: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0784_0x0622d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0622d8ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c2e38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0785 | PC: 0x062510 | FDE: 0x0c2e70 | Size: 256 bytes
// Hàm FDE #0785 | Địa chỉ PC: 0x062510 | Địa chỉ FDE: 0x0c2e70 | Kích thước: 256 bytes
//   0x062510: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x062514: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x062518: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x06251c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0785_0x062510(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062510ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c2e70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0786 | PC: 0x0626d4 | FDE: 0x0c2a48 | Size: 152 bytes
// Hàm FDE #0786 | Địa chỉ PC: 0x0626d4 | Địa chỉ FDE: 0x0c2a48 | Kích thước: 152 bytes
//   0x0626d4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0626d8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0626dc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0626e0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0786_0x0626d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0626d4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c2a48ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0787 | PC: 0x06276c | FDE: 0x0c2a70 | Size: 256 bytes
// Hàm FDE #0787 | Địa chỉ PC: 0x06276c | Địa chỉ FDE: 0x0c2a70 | Kích thước: 256 bytes
//   0x06276c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x062770: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x062774: 910043FD  add      x29, sp, #0x10
//   0x062778: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_0787_0x06276c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06276cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c2a70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0788 | PC: 0x06287c | FDE: 0x0c2ea8 | Size: 256 bytes
// Hàm FDE #0788 | Địa chỉ PC: 0x06287c | Địa chỉ FDE: 0x0c2ea8 | Kích thước: 256 bytes
//   0x06287c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x062880: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x062884: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x062888: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0788_0x06287c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06287cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c2ea8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0789 | PC: 0x062994 | FDE: 0x0c2ed8 | Size: 256 bytes
// Hàm FDE #0789 | Địa chỉ PC: 0x062994 | Địa chỉ FDE: 0x0c2ed8 | Kích thước: 256 bytes
//   0x062994: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x062998: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06299c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0629a0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0789_0x062994(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062994ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c2ed8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0790 | PC: 0x062aa8 | FDE: 0x0c2f08 | Size: 228 bytes
// Hàm FDE #0790 | Địa chỉ PC: 0x062aa8 | Địa chỉ FDE: 0x0c2f08 | Kích thước: 228 bytes
//   0x062aa8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x062aac: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x062ab0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x062ab4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0790_0x062aa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062aa8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c2f08ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #0791 | PC: 0x062b8c | FDE: 0x0c2f38 | Size: 256 bytes
// Hàm FDE #0791 | Địa chỉ PC: 0x062b8c | Địa chỉ FDE: 0x0c2f38 | Kích thước: 256 bytes
//   0x062b8c: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x062b90: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x062b94: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x062b98: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0791_0x062b8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062b8cULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c2f38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0792 | PC: 0x062d08 | FDE: 0x0c2f68 | Size: 256 bytes
// Hàm FDE #0792 | Địa chỉ PC: 0x062d08 | Địa chỉ FDE: 0x0c2f68 | Kích thước: 256 bytes
//   0x062d08: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x062d0c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x062d10: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x062d14: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0792_0x062d08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062d08ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c2f68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0793 | PC: 0x06302c | FDE: 0x0c2fa0 | Size: 256 bytes
// Hàm FDE #0793 | Địa chỉ PC: 0x06302c | Địa chỉ FDE: 0x0c2fa0 | Kích thước: 256 bytes
//   0x06302c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x063030: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x063034: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x063038: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0793_0x06302c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06302cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c2fa0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0794 | PC: 0x063140 | FDE: 0x0c2fd0 | Size: 256 bytes
// Hàm FDE #0794 | Địa chỉ PC: 0x063140 | Địa chỉ FDE: 0x0c2fd0 | Kích thước: 256 bytes
//   0x063140: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x063144: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x063148: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x06314c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0794_0x063140(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063140ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c2fd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0795 | PC: 0x063328 | FDE: 0x0c2a90 | Size: 256 bytes
// Hàm FDE #0795 | Địa chỉ PC: 0x063328 | Địa chỉ FDE: 0x0c2a90 | Kích thước: 256 bytes
//   0x063328: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x06332c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x063330: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x063334: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0795_0x063328(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063328ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c2a90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0796 | PC: 0x063470 | FDE: 0x0c2ab8 | Size: 180 bytes
// Hàm FDE #0796 | Địa chỉ PC: 0x063470 | Địa chỉ FDE: 0x0c2ab8 | Kích thước: 180 bytes
//   0x063470: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x063474: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x063478: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06347c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0796_0x063470(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063470ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c2ab8ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #0797 | PC: 0x063524 | FDE: 0x0c3000 | Size: 256 bytes
// Hàm FDE #0797 | Địa chỉ PC: 0x063524 | Địa chỉ FDE: 0x0c3000 | Kích thước: 256 bytes
//   0x063524: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x063528: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x06352c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x063530: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0797_0x063524(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063524ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c3000ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0798 | PC: 0x06372c | FDE: 0x0c2ad8 | Size: 256 bytes
// Hàm FDE #0798 | Địa chỉ PC: 0x06372c | Địa chỉ FDE: 0x0c2ad8 | Kích thước: 256 bytes
//   0x06372c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x063730: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x063734: 910043FD  add      x29, sp, #0x10
//   0x063738: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_0798_0x06372c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06372cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c2ad8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0799 | PC: 0x063840 | FDE: 0x0c2af8 | Size: 204 bytes
// Hàm FDE #0799 | Địa chỉ PC: 0x063840 | Địa chỉ FDE: 0x0c2af8 | Kích thước: 204 bytes
//   0x063840: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x063844: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x063848: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06384c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0799_0x063840(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063840ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c2af8ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #0800 | PC: 0x06390c | FDE: 0x0c2b18 | Size: 212 bytes
// Hàm FDE #0800 | Địa chỉ PC: 0x06390c | Địa chỉ FDE: 0x0c2b18 | Kích thước: 212 bytes
//   0x06390c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x063910: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x063914: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x063918: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0800_0x06390c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06390cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c2b18ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #0801 | PC: 0x0639e0 | FDE: 0x0c2b40 | Size: 144 bytes
// Hàm FDE #0801 | Địa chỉ PC: 0x0639e0 | Địa chỉ FDE: 0x0c2b40 | Kích thước: 144 bytes
//   0x0639e0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0639e4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0639e8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0639ec: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0801_0x0639e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0639e0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c2b40ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0802 | PC: 0x063a70 | FDE: 0x0c2b60 | Size: 236 bytes
// Hàm FDE #0802 | Địa chỉ PC: 0x063a70 | Địa chỉ FDE: 0x0c2b60 | Kích thước: 236 bytes
//   0x063a70: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x063a74: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x063a78: 910043FD  add      x29, sp, #0x10
//   0x063a7c: D0000428  adrp     x8, #0xe9000
static inline uint64_t fde_func_0802_0x063a70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063a70ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c2b60ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0803 | PC: 0x063b5c | FDE: 0x0c2b80 | Size: 12 bytes
// Hàm FDE #0803 | Địa chỉ PC: 0x063b5c | Địa chỉ FDE: 0x0c2b80 | Kích thước: 12 bytes
//   0x063b5c: F8418C08  ldr      x8, [x0, #0x18]!
//   0x063b60: F9400101  ldr      x1, [x8]
//   0x063b64: D61F0020  br       x1
static inline uint64_t fde_func_0803_0x063b5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063b5cULL ^ (static_cast<uint64_t>(0xf8418c08ULL) << 13);
    acc = (acc + a1 + 0xf9400101ULL) ^ 0x0c2b80ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0804 | PC: 0x063b68 | FDE: 0x0c2b98 | Size: 4 bytes
// Hàm FDE #0804 | Địa chỉ PC: 0x063b68 | Địa chỉ FDE: 0x0c2b98 | Kích thước: 4 bytes
//   0x063b68: 17FEBB26  b        #0x12800
static inline uint64_t fde_func_0804_0x063b68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063b68ULL ^ (static_cast<uint64_t>(0x17febb26ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x0c2b98ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0805 | PC: 0x063b6c | FDE: 0x0c2bb0 | Size: 48 bytes
// Hàm FDE #0805 | Địa chỉ PC: 0x063b6c | Địa chỉ FDE: 0x0c2bb0 | Kích thước: 48 bytes
//   0x063b6c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x063b70: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x063b74: 910043FD  add      x29, sp, #0x10
//   0x063b78: D0000428  adrp     x8, #0xe9000
static inline uint64_t fde_func_0805_0x063b6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063b6cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c2bb0ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0806 | PC: 0x063b9c | FDE: 0x0c2bd0 | Size: 56 bytes
// Hàm FDE #0806 | Địa chỉ PC: 0x063b9c | Địa chỉ FDE: 0x0c2bd0 | Kích thước: 56 bytes
//   0x063b9c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x063ba0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x063ba4: 910043FD  add      x29, sp, #0x10
//   0x063ba8: D0000428  adrp     x8, #0xe9000
static inline uint64_t fde_func_0806_0x063b9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063b9cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c2bd0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0807 | PC: 0x063bd4 | FDE: 0x0c2bf0 | Size: 8 bytes
// Hàm FDE #0807 | Địa chỉ PC: 0x063bd4 | Địa chỉ FDE: 0x0c2bf0 | Kích thước: 8 bytes
//   0x063bd4: 91006000  add      x0, x0, #0x18
//   0x063bd8: 17FEBD2A  b        #0x13080
static inline uint64_t fde_func_0807_0x063bd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063bd4ULL ^ (static_cast<uint64_t>(0x91006000ULL) << 13);
    acc = (acc + a1 + 0x17febd2aULL) ^ 0x0c2bf0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0808 | PC: 0x063bdc | FDE: 0x0c2c08 | Size: 4 bytes
// Hàm FDE #0808 | Địa chỉ PC: 0x063bdc | Địa chỉ FDE: 0x0c2c08 | Kích thước: 4 bytes
//   0x063bdc: 17FEBB09  b        #0x12800
static inline uint64_t fde_func_0808_0x063bdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063bdcULL ^ (static_cast<uint64_t>(0x17febb09ULL) << 13);
    acc = (acc + a1 + 0xf81a0ffbULL) ^ 0x0c2c08ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0809 | PC: 0x063be0 | FDE: 0x0c3038 | Size: 256 bytes [_ZN4nuro11UserMessageC2ERKS0_]
// Hàm FDE #0809 | Địa chỉ PC: 0x063be0 | Địa chỉ FDE: 0x0c3038 | Kích thước: 256 bytes
//   0x063be0: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x063be4: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x063be8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x063bec: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0809_0x063be0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063be0ULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0c3038ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0810 | PC: 0x063f44 | FDE: 0x0c3070 | Size: 156 bytes
// Hàm FDE #0810 | Địa chỉ PC: 0x063f44 | Địa chỉ FDE: 0x0c3070 | Kích thước: 156 bytes
//   0x063f44: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x063f48: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x063f4c: 910043FD  add      x29, sp, #0x10
//   0x063f50: 3900001F  strb     wzr, [x0]
static inline uint64_t fde_func_0810_0x063f44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063f44ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c3070ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0811 | PC: 0x063fe0 | FDE: 0x0c3098 | Size: 256 bytes
// Hàm FDE #0811 | Địa chỉ PC: 0x063fe0 | Địa chỉ FDE: 0x0c3098 | Kích thước: 256 bytes
//   0x063fe0: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x063fe4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x063fe8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x063fec: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0811_0x063fe0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063fe0ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c3098ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0812 | PC: 0x06423c | FDE: 0x0c30c8 | Size: 256 bytes
// Hàm FDE #0812 | Địa chỉ PC: 0x06423c | Địa chỉ FDE: 0x0c30c8 | Kích thước: 256 bytes
//   0x06423c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x064240: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x064244: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x064248: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0812_0x06423c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06423cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c30c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0813 | PC: 0x064370 | FDE: 0x0c30f8 | Size: 8 bytes
// Hàm FDE #0813 | Địa chỉ PC: 0x064370 | Địa chỉ FDE: 0x0c30f8 | Kích thước: 8 bytes
//   0x064370: 52800020  mov      w0, #1
//   0x064374: D65F03C0  ret      
static inline uint64_t fde_func_0813_0x064370(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064370ULL ^ (static_cast<uint64_t>(0x52800020ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0c30f8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0814 | PC: 0x064378 | FDE: 0x0c3288 | Size: 256 bytes
// Hàm FDE #0814 | Địa chỉ PC: 0x064378 | Địa chỉ FDE: 0x0c3288 | Kích thước: 256 bytes
//   0x064378: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x06437c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x064380: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x064384: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0814_0x064378(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064378ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0c3288ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0815 | PC: 0x064cb8 | FDE: 0x0c3110 | Size: 256 bytes
// Hàm FDE #0815 | Địa chỉ PC: 0x064cb8 | Địa chỉ FDE: 0x0c3110 | Kích thước: 256 bytes
//   0x064cb8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x064cbc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x064cc0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x064cc4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0815_0x064cb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064cb8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c3110ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0816 | PC: 0x064ea8 | FDE: 0x0c3138 | Size: 228 bytes [_ZN4nuro8ToolCallD2Ev]
// Hàm FDE #0816 | Địa chỉ PC: 0x064ea8 | Địa chỉ FDE: 0x0c3138 | Kích thước: 228 bytes
//   0x064ea8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x064eac: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x064eb0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x064eb4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0816_0x064ea8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064ea8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c3138ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #0817 | PC: 0x064f8c | FDE: 0x0c3158 | Size: 16 bytes
// Hàm FDE #0817 | Địa chỉ PC: 0x064f8c | Địa chỉ FDE: 0x0c3158 | Kích thước: 16 bytes
//   0x064f8c: F0000241  adrp     x1, #0xaf000
//   0x064f90: 91250421  add      x1, x1, #0x941
//   0x064f94: AA0803E0  mov      x0, x8
//   0x064f98: 17FED2F6  b        #0x19b70
static inline uint64_t fde_func_0817_0x064f8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064f8cULL ^ (static_cast<uint64_t>(0xf0000241ULL) << 13);
    acc = (acc + a1 + 0x91250421ULL) ^ 0x0c3158ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0818 | PC: 0x064f9c | FDE: 0x0c32c0 | Size: 256 bytes
// Hàm FDE #0818 | Địa chỉ PC: 0x064f9c | Địa chỉ FDE: 0x0c32c0 | Kích thước: 256 bytes
//   0x064f9c: D10203FF  sub      sp, sp, #0x80
//   0x064fa0: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x064fa4: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x064fa8: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_0818_0x064f9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064f9cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90557f6ULL) ^ 0x0c32c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0819 | PC: 0x065140 | FDE: 0x0c3170 | Size: 108 bytes
// Hàm FDE #0819 | Địa chỉ PC: 0x065140 | Địa chỉ FDE: 0x0c3170 | Kích thước: 108 bytes
//   0x065140: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x065144: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x065148: 910043FD  add      x29, sp, #0x10
//   0x06514c: F940D814  ldr      x20, [x0, #0x1b0]
static inline uint64_t fde_func_0819_0x065140(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x065140ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c3170ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #0820 | PC: 0x0651ac | FDE: 0x0c3190 | Size: 212 bytes
// Hàm FDE #0820 | Địa chỉ PC: 0x0651ac | Địa chỉ FDE: 0x0c3190 | Kích thước: 212 bytes
//   0x0651ac: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0651b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0651b4: 910043FD  add      x29, sp, #0x10
//   0x0651b8: F940D814  ldr      x20, [x0, #0x1b0]
static inline uint64_t fde_func_0820_0x0651ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0651acULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c3190ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #0821 | PC: 0x065280 | FDE: 0x0c31b0 | Size: 256 bytes
// Hàm FDE #0821 | Địa chỉ PC: 0x065280 | Địa chỉ FDE: 0x0c31b0 | Kích thước: 256 bytes
//   0x065280: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x065284: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x065288: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06528c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0821_0x065280(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x065280ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c31b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0822 | PC: 0x06555c | FDE: 0x0c31d8 | Size: 48 bytes
// Hàm FDE #0822 | Địa chỉ PC: 0x06555c | Địa chỉ FDE: 0x0c31d8 | Kích thước: 48 bytes
//   0x06555c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x065560: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x065564: 910043FD  add      x29, sp, #0x10
//   0x065568: 90000428  adrp     x8, #0xe9000
static inline uint64_t fde_func_0822_0x06555c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06555cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c31d8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0823 | PC: 0x06558c | FDE: 0x0c31f8 | Size: 56 bytes
// Hàm FDE #0823 | Địa chỉ PC: 0x06558c | Địa chỉ FDE: 0x0c31f8 | Kích thước: 56 bytes
//   0x06558c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x065590: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x065594: 910043FD  add      x29, sp, #0x10
//   0x065598: 90000428  adrp     x8, #0xe9000
static inline uint64_t fde_func_0823_0x06558c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06558cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c31f8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0824 | PC: 0x0655c4 | FDE: 0x0c3218 | Size: 8 bytes
// Hàm FDE #0824 | Địa chỉ PC: 0x0655c4 | Địa chỉ FDE: 0x0c3218 | Kích thước: 8 bytes
//   0x0655c4: 91006000  add      x0, x0, #0x18
//   0x0655c8: 17FEB47E  b        #0x127c0
static inline uint64_t fde_func_0824_0x0655c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0655c4ULL ^ (static_cast<uint64_t>(0x91006000ULL) << 13);
    acc = (acc + a1 + 0x17feb47eULL) ^ 0x0c3218ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0825 | PC: 0x0655cc | FDE: 0x0c3230 | Size: 4 bytes
// Hàm FDE #0825 | Địa chỉ PC: 0x0655cc | Địa chỉ FDE: 0x0c3230 | Kích thước: 4 bytes
//   0x0655cc: 17FEB48D  b        #0x12800
static inline uint64_t fde_func_0825_0x0655cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0655ccULL ^ (static_cast<uint64_t>(0x17feb48dULL) << 13);
    acc = (acc + a1 + 0xd10343ffULL) ^ 0x0c3230ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0826 | PC: 0x0655d0 | FDE: 0x0c32f0 | Size: 256 bytes
// Hàm FDE #0826 | Địa chỉ PC: 0x0655d0 | Địa chỉ FDE: 0x0c32f0 | Kích thước: 256 bytes
//   0x0655d0: D10343FF  sub      sp, sp, #0xd0
//   0x0655d4: A9095FF8  stp      x24, x23, [sp, #0x90]
//   0x0655d8: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x0655dc: A90B4FF4  stp      x20, x19, [sp, #0xb0]
static inline uint64_t fde_func_0826_0x0655d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0655d0ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9095ff8ULL) ^ 0x0c32f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0827 | PC: 0x0658dc | FDE: 0x0c3320 | Size: 256 bytes
// Hàm FDE #0827 | Địa chỉ PC: 0x0658dc | Địa chỉ FDE: 0x0c3320 | Kích thước: 256 bytes
//   0x0658dc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0658e0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0658e4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0658e8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0827_0x0658dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0658dcULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c3320ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0828 | PC: 0x0659f0 | FDE: 0x0c3350 | Size: 256 bytes [_ZN4nuro8ToolCallC2ERKS0_]
// Hàm FDE #0828 | Địa chỉ PC: 0x0659f0 | Địa chỉ FDE: 0x0c3350 | Kích thước: 256 bytes
//   0x0659f0: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0659f4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0659f8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0659fc: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0828_0x0659f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0659f0ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c3350ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0829 | PC: 0x065bd8 | FDE: 0x0c3248 | Size: 220 bytes [_ZN4nuro16AssistantMessageD2Ev]
// Hàm FDE #0829 | Địa chỉ PC: 0x065bd8 | Địa chỉ FDE: 0x0c3248 | Kích thước: 220 bytes
//   0x065bd8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x065bdc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x065be0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x065be4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0829_0x065bd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x065bd8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c3248ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #0830 | PC: 0x065cb4 | FDE: 0x0c3268 | Size: 164 bytes
// Hàm FDE #0830 | Địa chỉ PC: 0x065cb4 | Địa chỉ FDE: 0x0c3268 | Kích thước: 164 bytes
//   0x065cb4: D10443FF  sub      sp, sp, #0x110
//   0x065cb8: A90F4FFC  stp      x28, x19, [sp, #0xf0]
//   0x065cbc: A9107BFD  stp      x29, x30, [sp, #0x100]
//   0x065cc0: 910403FD  add      x29, sp, #0x100
static inline uint64_t fde_func_0830_0x065cb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x065cb4ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90f4ffcULL) ^ 0x0c3268ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #0831 | PC: 0x065d58 | FDE: 0x0c3380 | Size: 8 bytes
// Hàm FDE #0831 | Địa chỉ PC: 0x065d58 | Địa chỉ FDE: 0x0c3380 | Kích thước: 8 bytes
//   0x065d58: 52800040  mov      w0, #2
//   0x065d5c: D65F03C0  ret      
static inline uint64_t fde_func_0831_0x065d58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x065d58ULL ^ (static_cast<uint64_t>(0x52800040ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0c3380ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0832 | PC: 0x065d60 | FDE: 0x0c3398 | Size: 4 bytes
// Hàm FDE #0832 | Địa chỉ PC: 0x065d60 | Địa chỉ FDE: 0x0c3398 | Kích thước: 4 bytes
//   0x065d60: D65F03C0  ret      
static inline uint64_t fde_func_0832_0x065d60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x065d60ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xd0000241ULL) ^ 0x0c3398ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0833 | PC: 0x065d64 | FDE: 0x0c33b0 | Size: 16 bytes
// Hàm FDE #0833 | Địa chỉ PC: 0x065d64 | Địa chỉ FDE: 0x0c33b0 | Kích thước: 16 bytes
//   0x065d64: D0000241  adrp     x1, #0xaf000
//   0x065d68: 91250421  add      x1, x1, #0x941
//   0x065d6c: AA0803E0  mov      x0, x8
//   0x065d70: 17FECF80  b        #0x19b70
static inline uint64_t fde_func_0833_0x065d64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x065d64ULL ^ (static_cast<uint64_t>(0xd0000241ULL) << 13);
    acc = (acc + a1 + 0x91250421ULL) ^ 0x0c33b0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0834 | PC: 0x065d74 | FDE: 0x0c3428 | Size: 256 bytes
// Hàm FDE #0834 | Địa chỉ PC: 0x065d74 | Địa chỉ FDE: 0x0c3428 | Kích thước: 256 bytes
//   0x065d74: D10203FF  sub      sp, sp, #0x80
//   0x065d78: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x065d7c: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x065d80: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_0834_0x065d74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x065d74ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90557f6ULL) ^ 0x0c3428ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0835 | PC: 0x065f18 | FDE: 0x0c33c8 | Size: 76 bytes
// Hàm FDE #0835 | Địa chỉ PC: 0x065f18 | Địa chỉ FDE: 0x0c33c8 | Kích thước: 76 bytes
//   0x065f18: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x065f1c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x065f20: 910043FD  add      x29, sp, #0x10
//   0x065f24: 39422008  ldrb     w8, [x0, #0x88]
static inline uint64_t fde_func_0835_0x065f18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x065f18ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c33c8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0836 | PC: 0x065f64 | FDE: 0x0c33e8 | Size: 180 bytes
// Hàm FDE #0836 | Địa chỉ PC: 0x065f64 | Địa chỉ FDE: 0x0c33e8 | Kích thước: 180 bytes
//   0x065f64: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x065f68: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x065f6c: 910043FD  add      x29, sp, #0x10
//   0x065f70: 39422008  ldrb     w8, [x0, #0x88]
static inline uint64_t fde_func_0836_0x065f64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x065f64ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c33e8ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #0837 | PC: 0x066018 | FDE: 0x0c3408 | Size: 164 bytes
// Hàm FDE #0837 | Địa chỉ PC: 0x066018 | Địa chỉ FDE: 0x0c3408 | Kích thước: 164 bytes
//   0x066018: D10443FF  sub      sp, sp, #0x110
//   0x06601c: A90F4FFC  stp      x28, x19, [sp, #0xf0]
//   0x066020: A9107BFD  stp      x29, x30, [sp, #0x100]
//   0x066024: 910403FD  add      x29, sp, #0x100
static inline uint64_t fde_func_0837_0x066018(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x066018ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90f4ffcULL) ^ 0x0c3408ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #0838 | PC: 0x0660bc | FDE: 0x0c3458 | Size: 8 bytes
// Hàm FDE #0838 | Địa chỉ PC: 0x0660bc | Địa chỉ FDE: 0x0c3458 | Kích thước: 8 bytes
//   0x0660bc: 52800060  mov      w0, #3
//   0x0660c0: D65F03C0  ret      
static inline uint64_t fde_func_0838_0x0660bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0660bcULL ^ (static_cast<uint64_t>(0x52800060ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0c3458ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0839 | PC: 0x0660c4 | FDE: 0x0c3560 | Size: 256 bytes
// Hàm FDE #0839 | Địa chỉ PC: 0x0660c4 | Địa chỉ FDE: 0x0c3560 | Kích thước: 256 bytes
//   0x0660c4: D10183FF  sub      sp, sp, #0x60
//   0x0660c8: F90013F7  str      x23, [sp, #0x20]
//   0x0660cc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0660d0: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0839_0x0660c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0660c4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x0c3560ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0840 | PC: 0x0661d0 | FDE: 0x0c3470 | Size: 16 bytes
// Hàm FDE #0840 | Địa chỉ PC: 0x0661d0 | Địa chỉ FDE: 0x0c3470 | Kích thước: 16 bytes
//   0x0661d0: B0000241  adrp     x1, #0xaf000
//   0x0661d4: 91250421  add      x1, x1, #0x941
//   0x0661d8: AA0803E0  mov      x0, x8
//   0x0661dc: 17FECE65  b        #0x19b70
static inline uint64_t fde_func_0840_0x0661d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0661d0ULL ^ (static_cast<uint64_t>(0xb0000241ULL) << 13);
    acc = (acc + a1 + 0x91250421ULL) ^ 0x0c3470ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0841 | PC: 0x0661e0 | FDE: 0x0c3590 | Size: 256 bytes
// Hàm FDE #0841 | Địa chỉ PC: 0x0661e0 | Địa chỉ FDE: 0x0c3590 | Kích thước: 256 bytes
//   0x0661e0: D10203FF  sub      sp, sp, #0x80
//   0x0661e4: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0661e8: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x0661ec: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_0841_0x0661e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0661e0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90557f6ULL) ^ 0x0c3590ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0842 | PC: 0x066384 | FDE: 0x0c3488 | Size: 128 bytes
// Hàm FDE #0842 | Địa chỉ PC: 0x066384 | Địa chỉ FDE: 0x0c3488 | Kích thước: 128 bytes
//   0x066384: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x066388: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06638c: 910043FD  add      x29, sp, #0x10
//   0x066390: F9404C14  ldr      x20, [x0, #0x98]
static inline uint64_t fde_func_0842_0x066384(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x066384ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c3488ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0843 | PC: 0x066404 | FDE: 0x0c34a8 | Size: 232 bytes
// Hàm FDE #0843 | Địa chỉ PC: 0x066404 | Địa chỉ FDE: 0x0c34a8 | Kích thước: 232 bytes
//   0x066404: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x066408: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06640c: 910043FD  add      x29, sp, #0x10
//   0x066410: F9404C14  ldr      x20, [x0, #0x98]
static inline uint64_t fde_func_0843_0x066404(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x066404ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c34a8ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0844 | PC: 0x0664ec | FDE: 0x0c34c8 | Size: 100 bytes
// Hàm FDE #0844 | Địa chỉ PC: 0x0664ec | Địa chỉ FDE: 0x0c34c8 | Kích thước: 100 bytes
//   0x0664ec: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0664f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0664f4: 910043FD  add      x29, sp, #0x10
//   0x0664f8: 3941A008  ldrb     w8, [x0, #0x68]
static inline uint64_t fde_func_0844_0x0664ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0664ecULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c34c8ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #0845 | PC: 0x066550 | FDE: 0x0c34e8 | Size: 108 bytes
// Hàm FDE #0845 | Địa chỉ PC: 0x066550 | Địa chỉ FDE: 0x0c34e8 | Kích thước: 108 bytes
//   0x066550: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x066554: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x066558: 910043FD  add      x29, sp, #0x10
//   0x06655c: 3941A008  ldrb     w8, [x0, #0x68]
static inline uint64_t fde_func_0845_0x066550(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x066550ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c34e8ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #0846 | PC: 0x0665bc | FDE: 0x0c3508 | Size: 92 bytes
// Hàm FDE #0846 | Địa chỉ PC: 0x0665bc | Địa chỉ FDE: 0x0c3508 | Kích thước: 92 bytes
//   0x0665bc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0665c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0665c4: 910043FD  add      x29, sp, #0x10
//   0x0665c8: 3941A008  ldrb     w8, [x0, #0x68]
static inline uint64_t fde_func_0846_0x0665bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0665bcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c3508ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0847 | PC: 0x066618 | FDE: 0x0c3528 | Size: 4 bytes
// Hàm FDE #0847 | Địa chỉ PC: 0x066618 | Địa chỉ FDE: 0x0c3528 | Kích thước: 4 bytes
//   0x066618: 17FEB07A  b        #0x12800
static inline uint64_t fde_func_0847_0x066618(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x066618ULL ^ (static_cast<uint64_t>(0x17feb07aULL) << 13);
    acc = (acc + a1 + 0xd10443ffULL) ^ 0x0c3528ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0848 | PC: 0x06661c | FDE: 0x0c3540 | Size: 164 bytes
// Hàm FDE #0848 | Địa chỉ PC: 0x06661c | Địa chỉ FDE: 0x0c3540 | Kích thước: 164 bytes
//   0x06661c: D10443FF  sub      sp, sp, #0x110
//   0x066620: A90F4FFC  stp      x28, x19, [sp, #0xf0]
//   0x066624: A9107BFD  stp      x29, x30, [sp, #0x100]
//   0x066628: 910403FD  add      x29, sp, #0x100
static inline uint64_t fde_func_0848_0x06661c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06661cULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90f4ffcULL) ^ 0x0c3540ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #0849 | PC: 0x0666c0 | FDE: 0x0c35c0 | Size: 8 bytes
// Hàm FDE #0849 | Địa chỉ PC: 0x0666c0 | Địa chỉ FDE: 0x0c35c0 | Kích thước: 8 bytes
//   0x0666c0: 2A1F03E0  mov      w0, wzr
//   0x0666c4: D65F03C0  ret      
static inline uint64_t fde_func_0849_0x0666c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0666c0ULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0c35c0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0850 | PC: 0x0666c8 | FDE: 0x0c3778 | Size: 256 bytes
// Hàm FDE #0850 | Địa chỉ PC: 0x0666c8 | Địa chỉ FDE: 0x0c3778 | Kích thước: 256 bytes
//   0x0666c8: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0666cc: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0666d0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0666d4: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0850_0x0666c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0666c8ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0c3778ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0851 | PC: 0x067364 | FDE: 0x0c37b0 | Size: 168 bytes
// Hàm FDE #0851 | Địa chỉ PC: 0x067364 | Địa chỉ FDE: 0x0c37b0 | Kích thước: 168 bytes
//   0x067364: D10143FF  sub      sp, sp, #0x50
//   0x067368: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x06736c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x067370: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0851_0x067364(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x067364ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x0c37b0ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #0852 | PC: 0x06740c | FDE: 0x0c37e0 | Size: 256 bytes
// Hàm FDE #0852 | Địa chỉ PC: 0x06740c | Địa chỉ FDE: 0x0c37e0 | Kích thước: 256 bytes
//   0x06740c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x067410: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x067414: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x067418: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0852_0x06740c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06740cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0c37e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0853 | PC: 0x06821c | FDE: 0x0c35d8 | Size: 256 bytes
// Hàm FDE #0853 | Địa chỉ PC: 0x06821c | Địa chỉ FDE: 0x0c35d8 | Kích thước: 256 bytes
//   0x06821c: D101C3FF  sub      sp, sp, #0x70
//   0x068220: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x068224: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x068228: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0853_0x06821c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06821cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x0c35d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0854 | PC: 0x0683dc | FDE: 0x0c3600 | Size: 256 bytes
// Hàm FDE #0854 | Địa chỉ PC: 0x0683dc | Địa chỉ FDE: 0x0c3600 | Kích thước: 256 bytes
//   0x0683dc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0683e0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0683e4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0683e8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0854_0x0683dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0683dcULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c3600ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0855 | PC: 0x0685c8 | FDE: 0x0c3628 | Size: 224 bytes
// Hàm FDE #0855 | Địa chỉ PC: 0x0685c8 | Địa chỉ FDE: 0x0c3628 | Kích thước: 224 bytes
//   0x0685c8: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0685cc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0685d0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0685d4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0855_0x0685c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0685c8ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c3628ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #0856 | PC: 0x0686a8 | FDE: 0x0c3650 | Size: 108 bytes
// Hàm FDE #0856 | Địa chỉ PC: 0x0686a8 | Địa chỉ FDE: 0x0c3650 | Kích thước: 108 bytes
//   0x0686a8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0686ac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0686b0: 910043FD  add      x29, sp, #0x10
//   0x0686b4: F9410814  ldr      x20, [x0, #0x210]
static inline uint64_t fde_func_0856_0x0686a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0686a8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c3650ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #0857 | PC: 0x068714 | FDE: 0x0c3670 | Size: 212 bytes
// Hàm FDE #0857 | Địa chỉ PC: 0x068714 | Địa chỉ FDE: 0x0c3670 | Kích thước: 212 bytes
//   0x068714: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x068718: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06871c: 910043FD  add      x29, sp, #0x10
//   0x068720: F9410814  ldr      x20, [x0, #0x210]
static inline uint64_t fde_func_0857_0x068714(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068714ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c3670ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #0858 | PC: 0x0687e8 | FDE: 0x0c3690 | Size: 256 bytes
// Hàm FDE #0858 | Địa chỉ PC: 0x0687e8 | Địa chỉ FDE: 0x0c3690 | Kích thước: 256 bytes
//   0x0687e8: D101C3FF  sub      sp, sp, #0x70
//   0x0687ec: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0687f0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0687f4: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0858_0x0687e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0687e8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x0c3690ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0859 | PC: 0x068a7c | FDE: 0x0c36b8 | Size: 256 bytes
// Hàm FDE #0859 | Địa chỉ PC: 0x068a7c | Địa chỉ FDE: 0x0c36b8 | Kích thước: 256 bytes
//   0x068a7c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x068a80: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x068a84: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x068a88: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0859_0x068a7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068a7cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c36b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0860 | PC: 0x068d48 | FDE: 0x0c36e0 | Size: 164 bytes
// Hàm FDE #0860 | Địa chỉ PC: 0x068d48 | Địa chỉ FDE: 0x0c36e0 | Kích thước: 164 bytes
//   0x068d48: D10443FF  sub      sp, sp, #0x110
//   0x068d4c: A90F4FFC  stp      x28, x19, [sp, #0xf0]
//   0x068d50: A9107BFD  stp      x29, x30, [sp, #0x100]
//   0x068d54: 910403FD  add      x29, sp, #0x100
static inline uint64_t fde_func_0860_0x068d48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068d48ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90f4ffcULL) ^ 0x0c36e0ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #0861 | PC: 0x068dec | FDE: 0x0c3700 | Size: 172 bytes
// Hàm FDE #0861 | Địa chỉ PC: 0x068dec | Địa chỉ FDE: 0x0c3700 | Kích thước: 172 bytes
//   0x068dec: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x068df0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x068df4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x068df8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0861_0x068dec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068decULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c3700ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #0862 | PC: 0x068e98 | FDE: 0x0c3728 | Size: 256 bytes
// Hàm FDE #0862 | Địa chỉ PC: 0x068e98 | Địa chỉ FDE: 0x0c3728 | Kích thước: 256 bytes
//   0x068e98: D101C3FF  sub      sp, sp, #0x70
//   0x068e9c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x068ea0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x068ea4: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0862_0x068e98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068e98ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x0c3728ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0863 | PC: 0x06912c | FDE: 0x0c3750 | Size: 256 bytes
// Hàm FDE #0863 | Địa chỉ PC: 0x06912c | Địa chỉ FDE: 0x0c3750 | Kích thước: 256 bytes
//   0x06912c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x069130: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x069134: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x069138: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0863_0x06912c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06912cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c3750ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0864 | PC: 0x0693a0 | FDE: 0x0c3ea0 | Size: 256 bytes
// Hàm FDE #0864 | Địa chỉ PC: 0x0693a0 | Địa chỉ FDE: 0x0c3ea0 | Kích thước: 256 bytes
//   0x0693a0: D10203FF  sub      sp, sp, #0x80
//   0x0693a4: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0693a8: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0693ac: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_0864_0x0693a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0693a0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90367faULL) ^ 0x0c3ea0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0865 | PC: 0x069510 | FDE: 0x0c3ed8 | Size: 256 bytes
// Hàm FDE #0865 | Địa chỉ PC: 0x069510 | Địa chỉ FDE: 0x0c3ed8 | Kích thước: 256 bytes
//   0x069510: D10343FF  sub      sp, sp, #0xd0
//   0x069514: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x069518: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x06951c: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_0865_0x069510(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069510ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9076ffcULL) ^ 0x0c3ed8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0866 | PC: 0x06984c | FDE: 0x0c3f10 | Size: 224 bytes
// Hàm FDE #0866 | Địa chỉ PC: 0x06984c | Địa chỉ FDE: 0x0c3f10 | Kích thước: 224 bytes
//   0x06984c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x069850: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x069854: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x069858: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0866_0x06984c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06984cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c3f10ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #0867 | PC: 0x06992c | FDE: 0x0c3818 | Size: 124 bytes
// Hàm FDE #0867 | Địa chỉ PC: 0x06992c | Địa chỉ FDE: 0x0c3818 | Kích thước: 124 bytes
//   0x06992c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x069930: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x069934: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x069938: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0867_0x06992c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06992cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c3818ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0868 | PC: 0x0699a8 | FDE: 0x0c3f40 | Size: 256 bytes
// Hàm FDE #0868 | Địa chỉ PC: 0x0699a8 | Địa chỉ FDE: 0x0c3f40 | Kích thước: 256 bytes
//   0x0699a8: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0699ac: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0699b0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0699b4: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0868_0x0699a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0699a8ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c3f40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0869 | PC: 0x069ad8 | FDE: 0x0c3f70 | Size: 256 bytes
// Hàm FDE #0869 | Địa chỉ PC: 0x069ad8 | Địa chỉ FDE: 0x0c3f70 | Kích thước: 256 bytes
//   0x069ad8: D10183FF  sub      sp, sp, #0x60
//   0x069adc: F90013F7  str      x23, [sp, #0x20]
//   0x069ae0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x069ae4: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0869_0x069ad8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069ad8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x0c3f70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0870 | PC: 0x069ce4 | FDE: 0x0c3fa0 | Size: 256 bytes
// Hàm FDE #0870 | Địa chỉ PC: 0x069ce4 | Địa chỉ FDE: 0x0c3fa0 | Kích thước: 256 bytes
//   0x069ce4: D10183FF  sub      sp, sp, #0x60
//   0x069ce8: F90013F7  str      x23, [sp, #0x20]
//   0x069cec: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x069cf0: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0870_0x069ce4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069ce4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x0c3fa0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0871 | PC: 0x069e74 | FDE: 0x0c3fd0 | Size: 256 bytes
// Hàm FDE #0871 | Địa chỉ PC: 0x069e74 | Địa chỉ FDE: 0x0c3fd0 | Kích thước: 256 bytes
//   0x069e74: D10203FF  sub      sp, sp, #0x80
//   0x069e78: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x069e7c: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x069e80: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_0871_0x069e74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069e74ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9045ff8ULL) ^ 0x0c3fd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0872 | PC: 0x06a0d4 | FDE: 0x0c3838 | Size: 224 bytes
// Hàm FDE #0872 | Địa chỉ PC: 0x06a0d4 | Địa chỉ FDE: 0x0c3838 | Kích thước: 224 bytes
//   0x06a0d4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06a0d8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06a0dc: 910043FD  add      x29, sp, #0x10
//   0x06a0e0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0872_0x06a0d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a0d4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c3838ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #0873 | PC: 0x06a1b4 | FDE: 0x0c3858 | Size: 8 bytes
// Hàm FDE #0873 | Địa chỉ PC: 0x06a1b4 | Địa chỉ FDE: 0x0c3858 | Kích thước: 8 bytes
//   0x06a1b4: 39406000  ldrb     w0, [x0, #0x18]
//   0x06a1b8: D65F03C0  ret      
static inline uint64_t fde_func_0873_0x06a1b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a1b4ULL ^ (static_cast<uint64_t>(0x39406000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0c3858ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0874 | PC: 0x06a1bc | FDE: 0x0c4000 | Size: 256 bytes
// Hàm FDE #0874 | Địa chỉ PC: 0x06a1bc | Địa chỉ FDE: 0x0c4000 | Kích thước: 256 bytes
//   0x06a1bc: A9BB67FC  stp      x28, x25, [sp, #-0x50]!
//   0x06a1c0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x06a1c4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x06a1c8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0874_0x06a1bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a1bcULL ^ (static_cast<uint64_t>(0xa9bb67fcULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c4000ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0875 | PC: 0x06ab3c | FDE: 0x0c4038 | Size: 96 bytes
// Hàm FDE #0875 | Địa chỉ PC: 0x06ab3c | Địa chỉ FDE: 0x0c4038 | Kích thước: 96 bytes
//   0x06ab3c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x06ab40: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06ab44: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06ab48: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0875_0x06ab3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ab3cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c4038ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0876 | PC: 0x06ab9c | FDE: 0x0c4060 | Size: 256 bytes
// Hàm FDE #0876 | Địa chỉ PC: 0x06ab9c | Địa chỉ FDE: 0x0c4060 | Kích thước: 256 bytes
//   0x06ab9c: D10303FF  sub      sp, sp, #0xc0
//   0x06aba0: F90033FB  str      x27, [sp, #0x60]
//   0x06aba4: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x06aba8: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_0876_0x06ab9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ab9cULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf90033fbULL) ^ 0x0c4060ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0877 | PC: 0x06ae74 | FDE: 0x0c4098 | Size: 256 bytes
// Hàm FDE #0877 | Địa chỉ PC: 0x06ae74 | Địa chỉ FDE: 0x0c4098 | Kích thước: 256 bytes
//   0x06ae74: D102C3FF  sub      sp, sp, #0xb0
//   0x06ae78: F90033F9  str      x25, [sp, #0x60]
//   0x06ae7c: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x06ae80: A90857F6  stp      x22, x21, [sp, #0x80]
static inline uint64_t fde_func_0877_0x06ae74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ae74ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf90033f9ULL) ^ 0x0c4098ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0878 | PC: 0x06b088 | FDE: 0x0c40c8 | Size: 256 bytes
// Hàm FDE #0878 | Địa chỉ PC: 0x06b088 | Địa chỉ FDE: 0x0c40c8 | Kích thước: 256 bytes
//   0x06b088: D10383FF  sub      sp, sp, #0xe0
//   0x06b08c: F90043FB  str      x27, [sp, #0x80]
//   0x06b090: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x06b094: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_0878_0x06b088(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06b088ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xf90043fbULL) ^ 0x0c40c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0879 | PC: 0x06b38c | FDE: 0x0c4100 | Size: 256 bytes
// Hàm FDE #0879 | Địa chỉ PC: 0x06b38c | Địa chỉ FDE: 0x0c4100 | Kích thước: 256 bytes
//   0x06b38c: D10383FF  sub      sp, sp, #0xe0
//   0x06b390: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x06b394: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x06b398: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_0879_0x06b38c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06b38cULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x0c4100ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0880 | PC: 0x06b780 | FDE: 0x0c4138 | Size: 256 bytes
// Hàm FDE #0880 | Địa chỉ PC: 0x06b780 | Địa chỉ FDE: 0x0c4138 | Kích thước: 256 bytes
//   0x06b780: D101C3FF  sub      sp, sp, #0x70
//   0x06b784: F90023F5  str      x21, [sp, #0x40]
//   0x06b788: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x06b78c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0880_0x06b780(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06b780ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c4138ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0881 | PC: 0x06b884 | FDE: 0x0c3870 | Size: 256 bytes
// Hàm FDE #0881 | Địa chỉ PC: 0x06b884 | Địa chỉ FDE: 0x0c3870 | Kích thước: 256 bytes
//   0x06b884: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x06b888: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x06b88c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x06b890: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0881_0x06b884(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06b884ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c3870ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0882 | PC: 0x06b9c8 | FDE: 0x0c4160 | Size: 256 bytes
// Hàm FDE #0882 | Địa chỉ PC: 0x06b9c8 | Địa chỉ FDE: 0x0c4160 | Kích thước: 256 bytes
//   0x06b9c8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06b9cc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06b9d0: 910043FD  add      x29, sp, #0x10
//   0x06b9d4: A940A408  ldp      x8, x9, [x0, #8]
static inline uint64_t fde_func_0882_0x06b9c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06b9c8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c4160ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0883 | PC: 0x06bb04 | FDE: 0x0c4188 | Size: 256 bytes
// Hàm FDE #0883 | Địa chỉ PC: 0x06bb04 | Địa chỉ FDE: 0x0c4188 | Kích thước: 256 bytes
//   0x06bb04: D101C3FF  sub      sp, sp, #0x70
//   0x06bb08: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x06bb0c: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x06bb10: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0883_0x06bb04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06bb04ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x0c4188ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0884 | PC: 0x06bd18 | FDE: 0x0c3898 | Size: 256 bytes
// Hàm FDE #0884 | Địa chỉ PC: 0x06bd18 | Địa chỉ FDE: 0x0c3898 | Kích thước: 256 bytes
//   0x06bd18: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x06bd1c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x06bd20: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x06bd24: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0884_0x06bd18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06bd18ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c3898ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0885 | PC: 0x06be58 | FDE: 0x0c38c0 | Size: 256 bytes
// Hàm FDE #0885 | Địa chỉ PC: 0x06be58 | Địa chỉ FDE: 0x0c38c0 | Kích thước: 256 bytes
//   0x06be58: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x06be5c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x06be60: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x06be64: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0885_0x06be58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06be58ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c38c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0886 | PC: 0x06bf98 | FDE: 0x0c38e8 | Size: 256 bytes
// Hàm FDE #0886 | Địa chỉ PC: 0x06bf98 | Địa chỉ FDE: 0x0c38e8 | Kích thước: 256 bytes
//   0x06bf98: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x06bf9c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x06bfa0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x06bfa4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0886_0x06bf98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06bf98ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c38e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0887 | PC: 0x06c0d8 | FDE: 0x0c3910 | Size: 256 bytes
// Hàm FDE #0887 | Địa chỉ PC: 0x06c0d8 | Địa chỉ FDE: 0x0c3910 | Kích thước: 256 bytes
//   0x06c0d8: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x06c0dc: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x06c0e0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x06c0e4: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0887_0x06c0d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06c0d8ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c3910ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0888 | PC: 0x06c218 | FDE: 0x0c3938 | Size: 256 bytes
// Hàm FDE #0888 | Địa chỉ PC: 0x06c218 | Địa chỉ FDE: 0x0c3938 | Kích thước: 256 bytes
//   0x06c218: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x06c21c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x06c220: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x06c224: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0888_0x06c218(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06c218ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c3938ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0889 | PC: 0x06c358 | FDE: 0x0c41b8 | Size: 184 bytes
// Hàm FDE #0889 | Địa chỉ PC: 0x06c358 | Địa chỉ FDE: 0x0c41b8 | Kích thước: 184 bytes
//   0x06c358: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x06c35c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06c360: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06c364: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0889_0x06c358(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06c358ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c41b8ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #0890 | PC: 0x06c410 | FDE: 0x0c3960 | Size: 164 bytes
// Hàm FDE #0890 | Địa chỉ PC: 0x06c410 | Địa chỉ FDE: 0x0c3960 | Kích thước: 164 bytes
//   0x06c410: D10443FF  sub      sp, sp, #0x110
//   0x06c414: A90F4FFC  stp      x28, x19, [sp, #0xf0]
//   0x06c418: A9107BFD  stp      x29, x30, [sp, #0x100]
//   0x06c41c: 910403FD  add      x29, sp, #0x100
static inline uint64_t fde_func_0890_0x06c410(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06c410ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90f4ffcULL) ^ 0x0c3960ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #0891 | PC: 0x06c4b4 | FDE: 0x0c3980 | Size: 256 bytes
// Hàm FDE #0891 | Địa chỉ PC: 0x06c4b4 | Địa chỉ FDE: 0x0c3980 | Kích thước: 256 bytes
//   0x06c4b4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x06c4b8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06c4bc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06c4c0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0891_0x06c4b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06c4b4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c3980ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0892 | PC: 0x06c6b0 | FDE: 0x0c39a8 | Size: 256 bytes
// Hàm FDE #0892 | Địa chỉ PC: 0x06c6b0 | Địa chỉ FDE: 0x0c39a8 | Kích thước: 256 bytes
//   0x06c6b0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x06c6b4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06c6b8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06c6bc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0892_0x06c6b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06c6b0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c39a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0893 | PC: 0x06c814 | FDE: 0x0c39d0 | Size: 160 bytes
// Hàm FDE #0893 | Địa chỉ PC: 0x06c814 | Địa chỉ FDE: 0x0c39d0 | Kích thước: 160 bytes
//   0x06c814: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x06c818: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06c81c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06c820: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0893_0x06c814(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06c814ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c39d0ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0894 | PC: 0x06c8b4 | FDE: 0x0c39f0 | Size: 152 bytes
// Hàm FDE #0894 | Địa chỉ PC: 0x06c8b4 | Địa chỉ FDE: 0x0c39f0 | Kích thước: 152 bytes
//   0x06c8b4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x06c8b8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06c8bc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06c8c0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0894_0x06c8b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06c8b4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c39f0ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0895 | PC: 0x06c94c | FDE: 0x0c41e0 | Size: 220 bytes
// Hàm FDE #0895 | Địa chỉ PC: 0x06c94c | Địa chỉ FDE: 0x0c41e0 | Kích thước: 220 bytes
//   0x06c94c: D10103FF  sub      sp, sp, #0x40
//   0x06c950: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x06c954: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x06c958: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0895_0x06c94c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06c94cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c41e0ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #0896 | PC: 0x06ca28 | FDE: 0x0c4210 | Size: 188 bytes
// Hàm FDE #0896 | Địa chỉ PC: 0x06ca28 | Địa chỉ FDE: 0x0c4210 | Kích thước: 188 bytes
//   0x06ca28: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x06ca2c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x06ca30: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x06ca34: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0896_0x06ca28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ca28ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c4210ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0897 | PC: 0x06cae4 | FDE: 0x0c3a10 | Size: 148 bytes
// Hàm FDE #0897 | Địa chỉ PC: 0x06cae4 | Địa chỉ FDE: 0x0c3a10 | Kích thước: 148 bytes
//   0x06cae4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x06cae8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06caec: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06caf0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0897_0x06cae4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06cae4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c3a10ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0898 | PC: 0x06cb78 | FDE: 0x0c3a30 | Size: 140 bytes
// Hàm FDE #0898 | Địa chỉ PC: 0x06cb78 | Địa chỉ FDE: 0x0c3a30 | Kích thước: 140 bytes
//   0x06cb78: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x06cb7c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06cb80: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06cb84: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0898_0x06cb78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06cb78ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c3a30ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0899 | PC: 0x06cc04 | FDE: 0x0c4240 | Size: 256 bytes
// Hàm FDE #0899 | Địa chỉ PC: 0x06cc04 | Địa chỉ FDE: 0x0c4240 | Kích thước: 256 bytes
//   0x06cc04: D10483FF  sub      sp, sp, #0x120
//   0x06cc08: A90C6FFC  stp      x28, x27, [sp, #0xc0]
//   0x06cc0c: A90D67FA  stp      x26, x25, [sp, #0xd0]
//   0x06cc10: A90E5FF8  stp      x24, x23, [sp, #0xe0]
static inline uint64_t fde_func_0899_0x06cc04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06cc04ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa90c6ffcULL) ^ 0x0c4240ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0900 | PC: 0x06d5bc | FDE: 0x0c3a50 | Size: 28 bytes
// Hàm FDE #0900 | Địa chỉ PC: 0x06d5bc | Địa chỉ FDE: 0x0c3a50 | Kích thước: 28 bytes
//   0x06d5bc: F9400428  ldr      x8, [x1, #8]
//   0x06d5c0: D0000229  adrp     x9, #0xb3000
//   0x06d5c4: 910EA929  add      x9, x9, #0x3aa
//   0x06d5c8: 9100200A  add      x10, x0, #8
static inline uint64_t fde_func_0900_0x06d5bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06d5bcULL ^ (static_cast<uint64_t>(0xf9400428ULL) << 13);
    acc = (acc + a1 + 0xd0000229ULL) ^ 0x0c3a50ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0901 | PC: 0x06d5d8 | FDE: 0x0c3a68 | Size: 12 bytes
// Hàm FDE #0901 | Địa chỉ PC: 0x06d5d8 | Địa chỉ FDE: 0x0c3a68 | Kích thước: 12 bytes
//   0x06d5d8: B00003E0  adrp     x0, #0xea000
//   0x06d5dc: 91084000  add      x0, x0, #0x210
//   0x06d5e0: D65F03C0  ret      
static inline uint64_t fde_func_0901_0x06d5d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06d5d8ULL ^ (static_cast<uint64_t>(0xb00003e0ULL) << 13);
    acc = (acc + a1 + 0x91084000ULL) ^ 0x0c3a68ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0902 | PC: 0x06d5e4 | FDE: 0x0c4278 | Size: 204 bytes
// Hàm FDE #0902 | Địa chỉ PC: 0x06d5e4 | Địa chỉ FDE: 0x0c4278 | Kích thước: 204 bytes
//   0x06d5e4: D10143FF  sub      sp, sp, #0x50
//   0x06d5e8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x06d5ec: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x06d5f0: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0902_0x06d5e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06d5e4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x0c4278ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #0903 | PC: 0x06d6b0 | FDE: 0x0c42a8 | Size: 256 bytes
// Hàm FDE #0903 | Địa chỉ PC: 0x06d6b0 | Địa chỉ FDE: 0x0c42a8 | Kích thước: 256 bytes
//   0x06d6b0: D102C3FF  sub      sp, sp, #0xb0
//   0x06d6b4: F90033F9  str      x25, [sp, #0x60]
//   0x06d6b8: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x06d6bc: A90857F6  stp      x22, x21, [sp, #0x80]
static inline uint64_t fde_func_0903_0x06d6b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06d6b0ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf90033f9ULL) ^ 0x0c42a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0904 | PC: 0x06d980 | FDE: 0x0c42d8 | Size: 256 bytes
// Hàm FDE #0904 | Địa chỉ PC: 0x06d980 | Địa chỉ FDE: 0x0c42d8 | Kích thước: 256 bytes
//   0x06d980: D10183FF  sub      sp, sp, #0x60
//   0x06d984: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x06d988: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x06d98c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0904_0x06d980(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06d980ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x0c42d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0905 | PC: 0x06db14 | FDE: 0x0c4308 | Size: 152 bytes
// Hàm FDE #0905 | Địa chỉ PC: 0x06db14 | Địa chỉ FDE: 0x0c4308 | Kích thước: 152 bytes
//   0x06db14: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06db18: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06db1c: 910043FD  add      x29, sp, #0x10
//   0x06db20: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0905_0x06db14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06db14ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c4308ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0906 | PC: 0x06dbac | FDE: 0x0c3a80 | Size: 256 bytes
// Hàm FDE #0906 | Địa chỉ PC: 0x06dbac | Địa chỉ FDE: 0x0c3a80 | Kích thước: 256 bytes
//   0x06dbac: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x06dbb0: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x06dbb4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x06dbb8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0906_0x06dbac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06dbacULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0c3a80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0907 | PC: 0x06dd58 | FDE: 0x0c4330 | Size: 256 bytes
// Hàm FDE #0907 | Địa chỉ PC: 0x06dd58 | Địa chỉ FDE: 0x0c4330 | Kích thước: 256 bytes
//   0x06dd58: D10183FF  sub      sp, sp, #0x60
//   0x06dd5c: F90013F7  str      x23, [sp, #0x20]
//   0x06dd60: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x06dd64: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0907_0x06dd58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06dd58ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x0c4330ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0908 | PC: 0x06df94 | FDE: 0x0c3ab0 | Size: 36 bytes
// Hàm FDE #0908 | Địa chỉ PC: 0x06df94 | Địa chỉ FDE: 0x0c3ab0 | Kích thước: 36 bytes
//   0x06df94: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x06df98: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06df9c: 910043FD  add      x29, sp, #0x10
//   0x06dfa0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0908_0x06df94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06df94ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c3ab0ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0909 | PC: 0x06dfb8 | FDE: 0x0c3ad0 | Size: 92 bytes
// Hàm FDE #0909 | Địa chỉ PC: 0x06dfb8 | Địa chỉ FDE: 0x0c3ad0 | Kích thước: 92 bytes
//   0x06dfb8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x06dfbc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06dfc0: 910043FD  add      x29, sp, #0x10
//   0x06dfc4: F9400C13  ldr      x19, [x0, #0x18]
static inline uint64_t fde_func_0909_0x06dfb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06dfb8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c3ad0ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0910 | PC: 0x06e014 | FDE: 0x0c3af0 | Size: 28 bytes
// Hàm FDE #0910 | Địa chỉ PC: 0x06e014 | Địa chỉ FDE: 0x0c3af0 | Kích thước: 28 bytes
//   0x06e014: F9400428  ldr      x8, [x1, #8]
//   0x06e018: B0000229  adrp     x9, #0xb3000
//   0x06e01c: 910D8529  add      x9, x9, #0x361
//   0x06e020: 9100600A  add      x10, x0, #0x18
static inline uint64_t fde_func_0910_0x06e014(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e014ULL ^ (static_cast<uint64_t>(0xf9400428ULL) << 13);
    acc = (acc + a1 + 0xb0000229ULL) ^ 0x0c3af0ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0911 | PC: 0x06e030 | FDE: 0x0c3b08 | Size: 4 bytes
// Hàm FDE #0911 | Địa chỉ PC: 0x06e030 | Địa chỉ FDE: 0x0c3b08 | Kích thước: 4 bytes
//   0x06e030: 17FE91F4  b        #0x12800
static inline uint64_t fde_func_0911_0x06e030(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e030ULL ^ (static_cast<uint64_t>(0x17fe91f4ULL) << 13);
    acc = (acc + a1 + 0x900003e8ULL) ^ 0x0c3b08ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0912 | PC: 0x06e034 | FDE: 0x0c3b20 | Size: 16 bytes
// Hàm FDE #0912 | Địa chỉ PC: 0x06e034 | Địa chỉ FDE: 0x0c3b20 | Kích thước: 16 bytes
//   0x06e034: 900003E8  adrp     x8, #0xea000
//   0x06e038: 9108C108  add      x8, x8, #0x230
//   0x06e03c: F8010408  str      x8, [x0], #0x10
//   0x06e040: 17FEAE77  b        #0x19a1c
static inline uint64_t fde_func_0912_0x06e034(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e034ULL ^ (static_cast<uint64_t>(0x900003e8ULL) << 13);
    acc = (acc + a1 + 0x9108c108ULL) ^ 0x0c3b20ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0913 | PC: 0x06e044 | FDE: 0x0c3b38 | Size: 48 bytes
// Hàm FDE #0913 | Địa chỉ PC: 0x06e044 | Địa chỉ FDE: 0x0c3b38 | Kích thước: 48 bytes
//   0x06e044: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x06e048: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06e04c: 910043FD  add      x29, sp, #0x10
//   0x06e050: 900003E8  adrp     x8, #0xea000
static inline uint64_t fde_func_0913_0x06e044(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e044ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c3b38ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0914 | PC: 0x06e074 | FDE: 0x0c4360 | Size: 92 bytes
// Hàm FDE #0914 | Địa chỉ PC: 0x06e074 | Địa chỉ FDE: 0x0c4360 | Kích thước: 92 bytes
//   0x06e074: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06e078: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06e07c: 910043FD  add      x29, sp, #0x10
//   0x06e080: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0914_0x06e074(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e074ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c4360ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0915 | PC: 0x06e0d0 | FDE: 0x0c3b58 | Size: 40 bytes
// Hàm FDE #0915 | Địa chỉ PC: 0x06e0d0 | Địa chỉ FDE: 0x0c3b58 | Kích thước: 40 bytes
//   0x06e0d0: 900003E8  adrp     x8, #0xea000
//   0x06e0d4: 9108C108  add      x8, x8, #0x230
//   0x06e0d8: F9000028  str      x8, [x1]
//   0x06e0dc: F940040A  ldr      x10, [x0, #8]
static inline uint64_t fde_func_0915_0x06e0d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e0d0ULL ^ (static_cast<uint64_t>(0x900003e8ULL) << 13);
    acc = (acc + a1 + 0x9108c108ULL) ^ 0x0c3b58ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0916 | PC: 0x06e0f8 | FDE: 0x0c3b70 | Size: 8 bytes
// Hàm FDE #0916 | Địa chỉ PC: 0x06e0f8 | Địa chỉ FDE: 0x0c3b70 | Kích thước: 8 bytes
//   0x06e0f8: 91004000  add      x0, x0, #0x10
//   0x06e0fc: 17FEAE48  b        #0x19a1c
static inline uint64_t fde_func_0916_0x06e0f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e0f8ULL ^ (static_cast<uint64_t>(0x91004000ULL) << 13);
    acc = (acc + a1 + 0x17feae48ULL) ^ 0x0c3b70ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0917 | PC: 0x06e100 | FDE: 0x0c3b88 | Size: 40 bytes
// Hàm FDE #0917 | Địa chỉ PC: 0x06e100 | Địa chỉ FDE: 0x0c3b88 | Kích thước: 40 bytes
//   0x06e100: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x06e104: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06e108: 910043FD  add      x29, sp, #0x10
//   0x06e10c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0917_0x06e100(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e100ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c3b88ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0918 | PC: 0x06e128 | FDE: 0x0c4388 | Size: 256 bytes
// Hàm FDE #0918 | Địa chỉ PC: 0x06e128 | Địa chỉ FDE: 0x0c4388 | Kích thước: 256 bytes
//   0x06e128: D10383FF  sub      sp, sp, #0xe0
//   0x06e12c: F90053F7  str      x23, [sp, #0xa0]
//   0x06e130: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x06e134: A90C4FF4  stp      x20, x19, [sp, #0xc0]
static inline uint64_t fde_func_0918_0x06e128(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e128ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xf90053f7ULL) ^ 0x0c4388ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0919 | PC: 0x06e504 | FDE: 0x0c3ba8 | Size: 28 bytes
// Hàm FDE #0919 | Địa chỉ PC: 0x06e504 | Địa chỉ FDE: 0x0c3ba8 | Kích thước: 28 bytes
//   0x06e504: F9400428  ldr      x8, [x1, #8]
//   0x06e508: B0000229  adrp     x9, #0xb3000
//   0x06e50c: 91121129  add      x9, x9, #0x484
//   0x06e510: 9100200A  add      x10, x0, #8
static inline uint64_t fde_func_0919_0x06e504(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e504ULL ^ (static_cast<uint64_t>(0xf9400428ULL) << 13);
    acc = (acc + a1 + 0xb0000229ULL) ^ 0x0c3ba8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0920 | PC: 0x06e520 | FDE: 0x0c3bc0 | Size: 12 bytes
// Hàm FDE #0920 | Địa chỉ PC: 0x06e520 | Địa chỉ FDE: 0x0c3bc0 | Kích thước: 12 bytes
//   0x06e520: 900003E0  adrp     x0, #0xea000
//   0x06e524: 910A4000  add      x0, x0, #0x290
//   0x06e528: D65F03C0  ret      
static inline uint64_t fde_func_0920_0x06e520(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e520ULL ^ (static_cast<uint64_t>(0x900003e0ULL) << 13);
    acc = (acc + a1 + 0x910a4000ULL) ^ 0x0c3bc0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0921 | PC: 0x06e52c | FDE: 0x0c3bd8 | Size: 256 bytes
// Hàm FDE #0921 | Địa chỉ PC: 0x06e52c | Địa chỉ FDE: 0x0c3bd8 | Kích thước: 256 bytes
//   0x06e52c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x06e530: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06e534: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06e538: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0921_0x06e52c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e52cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c3bd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0922 | PC: 0x06e728 | FDE: 0x0c3c00 | Size: 32 bytes
// Hàm FDE #0922 | Địa chỉ PC: 0x06e728 | Địa chỉ FDE: 0x0c3c00 | Kích thước: 32 bytes
//   0x06e728: 39404008  ldrb     w8, [x0, #0x10]
//   0x06e72c: 900003E9  adrp     x9, #0xea000
//   0x06e730: 910AC129  add      x9, x9, #0x2b0
//   0x06e734: F9000009  str      x9, [x0]
static inline uint64_t fde_func_0922_0x06e728(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e728ULL ^ (static_cast<uint64_t>(0x39404008ULL) << 13);
    acc = (acc + a1 + 0x900003e9ULL) ^ 0x0c3c00ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0923 | PC: 0x06e748 | FDE: 0x0c3c18 | Size: 60 bytes
// Hàm FDE #0923 | Địa chỉ PC: 0x06e748 | Địa chỉ FDE: 0x0c3c18 | Kích thước: 60 bytes
//   0x06e748: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x06e74c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06e750: 910043FD  add      x29, sp, #0x10
//   0x06e754: 39404008  ldrb     w8, [x0, #0x10]
static inline uint64_t fde_func_0923_0x06e748(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e748ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c3c18ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0924 | PC: 0x06e784 | FDE: 0x0c43b8 | Size: 92 bytes
// Hàm FDE #0924 | Địa chỉ PC: 0x06e784 | Địa chỉ FDE: 0x0c43b8 | Kích thước: 92 bytes
//   0x06e784: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06e788: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06e78c: 910043FD  add      x29, sp, #0x10
//   0x06e790: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0924_0x06e784(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e784ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c43b8ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0925 | PC: 0x06e7e0 | FDE: 0x0c3c38 | Size: 40 bytes
// Hàm FDE #0925 | Địa chỉ PC: 0x06e7e0 | Địa chỉ FDE: 0x0c3c38 | Kích thước: 40 bytes
//   0x06e7e0: 900003E8  adrp     x8, #0xea000
//   0x06e7e4: 910AC108  add      x8, x8, #0x2b0
//   0x06e7e8: F9000028  str      x8, [x1]
//   0x06e7ec: F940040A  ldr      x10, [x0, #8]
static inline uint64_t fde_func_0925_0x06e7e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e7e0ULL ^ (static_cast<uint64_t>(0x900003e8ULL) << 13);
    acc = (acc + a1 + 0x910ac108ULL) ^ 0x0c3c38ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0926 | PC: 0x06e808 | FDE: 0x0c3c50 | Size: 20 bytes
// Hàm FDE #0926 | Địa chỉ PC: 0x06e808 | Địa chỉ FDE: 0x0c3c50 | Kích thước: 20 bytes
//   0x06e808: 39404008  ldrb     w8, [x0, #0x10]
//   0x06e80c: 37000048  tbnz     w8, #0, #0x6e814
//   0x06e810: D65F03C0  ret      
//   0x06e814: F9401000  ldr      x0, [x0, #0x20]
static inline uint64_t fde_func_0926_0x06e808(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e808ULL ^ (static_cast<uint64_t>(0x39404008ULL) << 13);
    acc = (acc + a1 + 0x37000048ULL) ^ 0x0c3c50ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0927 | PC: 0x06e81c | FDE: 0x0c3c68 | Size: 48 bytes
// Hàm FDE #0927 | Địa chỉ PC: 0x06e81c | Địa chỉ FDE: 0x0c3c68 | Kích thước: 48 bytes
//   0x06e81c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x06e820: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06e824: 910043FD  add      x29, sp, #0x10
//   0x06e828: 39404008  ldrb     w8, [x0, #0x10]
static inline uint64_t fde_func_0927_0x06e81c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e81cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c3c68ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0928 | PC: 0x06e84c | FDE: 0x0c43e0 | Size: 136 bytes
// Hàm FDE #0928 | Địa chỉ PC: 0x06e84c | Địa chỉ FDE: 0x0c43e0 | Kích thước: 136 bytes
//   0x06e84c: D10103FF  sub      sp, sp, #0x40
//   0x06e850: F90013F3  str      x19, [sp, #0x20]
//   0x06e854: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x06e858: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0928_0x06e84c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e84cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x0c43e0ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #0929 | PC: 0x06e8d4 | FDE: 0x0c3c88 | Size: 28 bytes
// Hàm FDE #0929 | Địa chỉ PC: 0x06e8d4 | Địa chỉ FDE: 0x0c3c88 | Kích thước: 28 bytes
//   0x06e8d4: F9400428  ldr      x8, [x1, #8]
//   0x06e8d8: B0000229  adrp     x9, #0xb3000
//   0x06e8dc: 9115C529  add      x9, x9, #0x571
//   0x06e8e0: 9100200A  add      x10, x0, #8
static inline uint64_t fde_func_0929_0x06e8d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e8d4ULL ^ (static_cast<uint64_t>(0xf9400428ULL) << 13);
    acc = (acc + a1 + 0xb0000229ULL) ^ 0x0c3c88ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0930 | PC: 0x06e8f0 | FDE: 0x0c3ca0 | Size: 12 bytes
// Hàm FDE #0930 | Địa chỉ PC: 0x06e8f0 | Địa chỉ FDE: 0x0c3ca0 | Kích thước: 12 bytes
//   0x06e8f0: 900003E0  adrp     x0, #0xea000
//   0x06e8f4: 910C4000  add      x0, x0, #0x310
//   0x06e8f8: D65F03C0  ret      
static inline uint64_t fde_func_0930_0x06e8f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e8f0ULL ^ (static_cast<uint64_t>(0x900003e0ULL) << 13);
    acc = (acc + a1 + 0x910c4000ULL) ^ 0x0c3ca0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0931 | PC: 0x06e8fc | FDE: 0x0c3cb8 | Size: 160 bytes
// Hàm FDE #0931 | Địa chỉ PC: 0x06e8fc | Địa chỉ FDE: 0x0c3cb8 | Kích thước: 160 bytes
//   0x06e8fc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x06e900: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06e904: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06e908: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0931_0x06e8fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e8fcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c3cb8ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0932 | PC: 0x06e99c | FDE: 0x0c3cd8 | Size: 152 bytes
// Hàm FDE #0932 | Địa chỉ PC: 0x06e99c | Địa chỉ FDE: 0x0c3cd8 | Kích thước: 152 bytes
//   0x06e99c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x06e9a0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06e9a4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06e9a8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0932_0x06e99c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e99cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c3cd8ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0933 | PC: 0x06ea34 | FDE: 0x0c4408 | Size: 144 bytes
// Hàm FDE #0933 | Địa chỉ PC: 0x06ea34 | Địa chỉ FDE: 0x0c4408 | Kích thước: 144 bytes
//   0x06ea34: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x06ea38: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06ea3c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06ea40: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0933_0x06ea34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ea34ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c4408ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0934 | PC: 0x06eac4 | FDE: 0x0c4430 | Size: 116 bytes
// Hàm FDE #0934 | Địa chỉ PC: 0x06eac4 | Địa chỉ FDE: 0x0c4430 | Kích thước: 116 bytes
//   0x06eac4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x06eac8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06eacc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06ead0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0934_0x06eac4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06eac4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c4430ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0935 | PC: 0x06eb38 | FDE: 0x0c3cf8 | Size: 148 bytes
// Hàm FDE #0935 | Địa chỉ PC: 0x06eb38 | Địa chỉ FDE: 0x0c3cf8 | Kích thước: 148 bytes
//   0x06eb38: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x06eb3c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06eb40: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06eb44: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0935_0x06eb38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06eb38ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c3cf8ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0936 | PC: 0x06ebcc | FDE: 0x0c3d18 | Size: 140 bytes
// Hàm FDE #0936 | Địa chỉ PC: 0x06ebcc | Địa chỉ FDE: 0x0c3d18 | Kích thước: 140 bytes
//   0x06ebcc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x06ebd0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06ebd4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06ebd8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0936_0x06ebcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ebccULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c3d18ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0937 | PC: 0x06ec58 | FDE: 0x0c4458 | Size: 256 bytes
// Hàm FDE #0937 | Địa chỉ PC: 0x06ec58 | Địa chỉ FDE: 0x0c4458 | Kích thước: 256 bytes
//   0x06ec58: D10243FF  sub      sp, sp, #0x90
//   0x06ec5c: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x06ec60: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x06ec64: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_0937_0x06ec58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ec58ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90657f6ULL) ^ 0x0c4458ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0938 | PC: 0x06ef04 | FDE: 0x0c3d38 | Size: 28 bytes
// Hàm FDE #0938 | Địa chỉ PC: 0x06ef04 | Địa chỉ FDE: 0x0c3d38 | Kích thước: 28 bytes
//   0x06ef04: F9400428  ldr      x8, [x1, #8]
//   0x06ef08: B0000229  adrp     x9, #0xb3000
//   0x06ef0c: 911A2129  add      x9, x9, #0x688
//   0x06ef10: 9100200A  add      x10, x0, #8
static inline uint64_t fde_func_0938_0x06ef04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ef04ULL ^ (static_cast<uint64_t>(0xf9400428ULL) << 13);
    acc = (acc + a1 + 0xb0000229ULL) ^ 0x0c3d38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0939 | PC: 0x06ef20 | FDE: 0x0c3d50 | Size: 12 bytes
// Hàm FDE #0939 | Địa chỉ PC: 0x06ef20 | Địa chỉ FDE: 0x0c3d50 | Kích thước: 12 bytes
//   0x06ef20: 900003E0  adrp     x0, #0xea000
//   0x06ef24: 910E4000  add      x0, x0, #0x390
//   0x06ef28: D65F03C0  ret      
static inline uint64_t fde_func_0939_0x06ef20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ef20ULL ^ (static_cast<uint64_t>(0x900003e0ULL) << 13);
    acc = (acc + a1 + 0x910e4000ULL) ^ 0x0c3d50ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0940 | PC: 0x06ef2c | FDE: 0x0c3d68 | Size: 76 bytes [_ZNSt6__ndk117__assoc_sub_stateD2Ev]
// Hàm FDE #0940 | Địa chỉ PC: 0x06ef2c | Địa chỉ FDE: 0x0c3d68 | Kích thước: 76 bytes
//   0x06ef2c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06ef30: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06ef34: 910043FD  add      x29, sp, #0x10
//   0x06ef38: B00003E8  adrp     x8, #0xeb000
static inline uint64_t fde_func_0940_0x06ef2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ef2cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c3d68ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0941 | PC: 0x06ef78 | FDE: 0x0c3d88 | Size: 84 bytes
// Hàm FDE #0941 | Địa chỉ PC: 0x06ef78 | Địa chỉ FDE: 0x0c3d88 | Kích thước: 84 bytes
//   0x06ef78: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06ef7c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06ef80: 910043FD  add      x29, sp, #0x10
//   0x06ef84: B00003E8  adrp     x8, #0xeb000
static inline uint64_t fde_func_0941_0x06ef78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ef78ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c3d88ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0942 | PC: 0x06efcc | FDE: 0x0c3da8 | Size: 20 bytes
// Hàm FDE #0942 | Địa chỉ PC: 0x06efcc | Địa chỉ FDE: 0x0c3da8 | Kích thước: 20 bytes
//   0x06efcc: B4000080  cbz      x0, #0x6efdc
//   0x06efd0: F9400008  ldr      x8, [x0]
//   0x06efd4: F9400501  ldr      x1, [x8, #8]
//   0x06efd8: D61F0020  br       x1
static inline uint64_t fde_func_0942_0x06efcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06efccULL ^ (static_cast<uint64_t>(0xb4000080ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x0c3da8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0943 | PC: 0x06efe0 | FDE: 0x0c4488 | Size: 128 bytes
// Hàm FDE #0943 | Địa chỉ PC: 0x06efe0 | Địa chỉ FDE: 0x0c4488 | Kích thước: 128 bytes
//   0x06efe0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x06efe4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06efe8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06efec: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0943_0x06efe0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06efe0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c4488ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0944 | PC: 0x06f060 | FDE: 0x0c44b0 | Size: 92 bytes
// Hàm FDE #0944 | Địa chỉ PC: 0x06f060 | Địa chỉ FDE: 0x0c44b0 | Kích thước: 92 bytes
//   0x06f060: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06f064: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06f068: 910043FD  add      x29, sp, #0x10
//   0x06f06c: 2A0003F4  mov      w20, w0
static inline uint64_t fde_func_0944_0x06f060(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f060ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c44b0ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0945 | PC: 0x06f0bc | FDE: 0x0c3dc0 | Size: 32 bytes
// Hàm FDE #0945 | Địa chỉ PC: 0x06f0bc | Địa chỉ FDE: 0x0c3dc0 | Kích thước: 32 bytes
//   0x06f0bc: 39404008  ldrb     w8, [x0, #0x10]
//   0x06f0c0: F00003C9  adrp     x9, #0xea000
//   0x06f0c4: 910FE129  add      x9, x9, #0x3f8
//   0x06f0c8: F9000009  str      x9, [x0]
static inline uint64_t fde_func_0945_0x06f0bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f0bcULL ^ (static_cast<uint64_t>(0x39404008ULL) << 13);
    acc = (acc + a1 + 0xf00003c9ULL) ^ 0x0c3dc0ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0946 | PC: 0x06f0dc | FDE: 0x0c3dd8 | Size: 60 bytes
// Hàm FDE #0946 | Địa chỉ PC: 0x06f0dc | Địa chỉ FDE: 0x0c3dd8 | Kích thước: 60 bytes
//   0x06f0dc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x06f0e0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06f0e4: 910043FD  add      x29, sp, #0x10
//   0x06f0e8: 39404008  ldrb     w8, [x0, #0x10]
static inline uint64_t fde_func_0946_0x06f0dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f0dcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c3dd8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0947 | PC: 0x06f118 | FDE: 0x0c44d8 | Size: 100 bytes
// Hàm FDE #0947 | Địa chỉ PC: 0x06f118 | Địa chỉ FDE: 0x0c44d8 | Kích thước: 100 bytes
//   0x06f118: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06f11c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06f120: 910043FD  add      x29, sp, #0x10
//   0x06f124: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0947_0x06f118(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f118ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c44d8ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #0948 | PC: 0x06f17c | FDE: 0x0c3df8 | Size: 72 bytes
// Hàm FDE #0948 | Địa chỉ PC: 0x06f17c | Địa chỉ FDE: 0x0c3df8 | Kích thước: 72 bytes
//   0x06f17c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06f180: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06f184: 910043FD  add      x29, sp, #0x10
//   0x06f188: F00003C8  adrp     x8, #0xea000
static inline uint64_t fde_func_0948_0x06f17c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f17cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c3df8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0949 | PC: 0x06f1c4 | FDE: 0x0c3e18 | Size: 20 bytes
// Hàm FDE #0949 | Địa chỉ PC: 0x06f1c4 | Địa chỉ FDE: 0x0c3e18 | Kích thước: 20 bytes
//   0x06f1c4: 39404008  ldrb     w8, [x0, #0x10]
//   0x06f1c8: 37000048  tbnz     w8, #0, #0x6f1d0
//   0x06f1cc: D65F03C0  ret      
//   0x06f1d0: F9401000  ldr      x0, [x0, #0x20]
static inline uint64_t fde_func_0949_0x06f1c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f1c4ULL ^ (static_cast<uint64_t>(0x39404008ULL) << 13);
    acc = (acc + a1 + 0x37000048ULL) ^ 0x0c3e18ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0950 | PC: 0x06f1d8 | FDE: 0x0c3e30 | Size: 48 bytes
// Hàm FDE #0950 | Địa chỉ PC: 0x06f1d8 | Địa chỉ FDE: 0x0c3e30 | Kích thước: 48 bytes
//   0x06f1d8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x06f1dc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06f1e0: 910043FD  add      x29, sp, #0x10
//   0x06f1e4: 39404008  ldrb     w8, [x0, #0x10]
static inline uint64_t fde_func_0950_0x06f1d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f1d8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c3e30ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0951 | PC: 0x06f208 | FDE: 0x0c4500 | Size: 256 bytes
// Hàm FDE #0951 | Địa chỉ PC: 0x06f208 | Địa chỉ FDE: 0x0c4500 | Kích thước: 256 bytes
//   0x06f208: D103C3FF  sub      sp, sp, #0xf0
//   0x06f20c: F9005BF7  str      x23, [sp, #0xb0]
//   0x06f210: A90C57F6  stp      x22, x21, [sp, #0xc0]
//   0x06f214: A90D4FF4  stp      x20, x19, [sp, #0xd0]
static inline uint64_t fde_func_0951_0x06f208(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f208ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xf9005bf7ULL) ^ 0x0c4500ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0952 | PC: 0x06f688 | FDE: 0x0c3e50 | Size: 28 bytes
// Hàm FDE #0952 | Địa chỉ PC: 0x06f688 | Địa chỉ FDE: 0x0c3e50 | Kích thước: 28 bytes
//   0x06f688: F9400428  ldr      x8, [x1, #8]
//   0x06f68c: 90000229  adrp     x9, #0xb3000
//   0x06f690: 911F4D29  add      x9, x9, #0x7d3
//   0x06f694: 9100200A  add      x10, x0, #8
static inline uint64_t fde_func_0952_0x06f688(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f688ULL ^ (static_cast<uint64_t>(0xf9400428ULL) << 13);
    acc = (acc + a1 + 0x90000229ULL) ^ 0x0c3e50ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0953 | PC: 0x06f6a4 | FDE: 0x0c3e68 | Size: 12 bytes
// Hàm FDE #0953 | Địa chỉ PC: 0x06f6a4 | Địa chỉ FDE: 0x0c3e68 | Kích thước: 12 bytes
//   0x06f6a4: F00003C0  adrp     x0, #0xea000
//   0x06f6a8: 91116000  add      x0, x0, #0x458
//   0x06f6ac: D65F03C0  ret      
static inline uint64_t fde_func_0953_0x06f6a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f6a4ULL ^ (static_cast<uint64_t>(0xf00003c0ULL) << 13);
    acc = (acc + a1 + 0x91116000ULL) ^ 0x0c3e68ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0954 | PC: 0x06f6b0 | FDE: 0x0c4530 | Size: 196 bytes
// Hàm FDE #0954 | Địa chỉ PC: 0x06f6b0 | Địa chỉ FDE: 0x0c4530 | Kích thước: 196 bytes
//   0x06f6b0: D10143FF  sub      sp, sp, #0x50
//   0x06f6b4: F9000BF7  str      x23, [sp, #0x10]
//   0x06f6b8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x06f6bc: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0954_0x06f6b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f6b0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x0c4530ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0955 | PC: 0x06f774 | FDE: 0x0c4560 | Size: 232 bytes
// Hàm FDE #0955 | Địa chỉ PC: 0x06f774 | Địa chỉ FDE: 0x0c4560 | Kích thước: 232 bytes
//   0x06f774: D10183FF  sub      sp, sp, #0x60
//   0x06f778: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x06f77c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x06f780: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0955_0x06f774(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f774ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x0c4560ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0956 | PC: 0x06f85c | FDE: 0x0c4590 | Size: 256 bytes
// Hàm FDE #0956 | Địa chỉ PC: 0x06f85c | Địa chỉ FDE: 0x0c4590 | Kích thước: 256 bytes
//   0x06f85c: D10283FF  sub      sp, sp, #0xa0
//   0x06f860: F90033F7  str      x23, [sp, #0x60]
//   0x06f864: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x06f868: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0956_0x06f85c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f85cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90033f7ULL) ^ 0x0c4590ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0957 | PC: 0x06fad8 | FDE: 0x0c45c0 | Size: 256 bytes
// Hàm FDE #0957 | Địa chỉ PC: 0x06fad8 | Địa chỉ FDE: 0x0c45c0 | Kích thước: 256 bytes
//   0x06fad8: D101C3FF  sub      sp, sp, #0x70
//   0x06fadc: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x06fae0: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x06fae4: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0957_0x06fad8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06fad8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x0c45c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0958 | PC: 0x06fe08 | FDE: 0x0c4690 | Size: 256 bytes
// Hàm FDE #0958 | Địa chỉ PC: 0x06fe08 | Địa chỉ FDE: 0x0c4690 | Kích thước: 256 bytes
//   0x06fe08: D101C3FF  sub      sp, sp, #0x70
//   0x06fe0c: F9001BF7  str      x23, [sp, #0x30]
//   0x06fe10: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x06fe14: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0958_0x06fe08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06fe08ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x0c4690ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0959 | PC: 0x06ff3c | FDE: 0x0c46c0 | Size: 256 bytes
// Hàm FDE #0959 | Địa chỉ PC: 0x06ff3c | Địa chỉ FDE: 0x0c46c0 | Kích thước: 256 bytes
//   0x06ff3c: D101C3FF  sub      sp, sp, #0x70
//   0x06ff40: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x06ff44: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x06ff48: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0959_0x06ff3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ff3cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x0c46c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0960 | PC: 0x0700ac | FDE: 0x0c46f0 | Size: 256 bytes
// Hàm FDE #0960 | Địa chỉ PC: 0x0700ac | Địa chỉ FDE: 0x0c46f0 | Kích thước: 256 bytes
//   0x0700ac: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0700b0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0700b4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0700b8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0960_0x0700ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0700acULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c46f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0961 | PC: 0x0701b0 | FDE: 0x0c4720 | Size: 256 bytes
// Hàm FDE #0961 | Địa chỉ PC: 0x0701b0 | Địa chỉ FDE: 0x0c4720 | Kích thước: 256 bytes
//   0x0701b0: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0701b4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0701b8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0701bc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0961_0x0701b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0701b0ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c4720ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0962 | PC: 0x0702f0 | FDE: 0x0c4750 | Size: 256 bytes
// Hàm FDE #0962 | Địa chỉ PC: 0x0702f0 | Địa chỉ FDE: 0x0c4750 | Kích thước: 256 bytes
//   0x0702f0: D101C3FF  sub      sp, sp, #0x70
//   0x0702f4: F90023F5  str      x21, [sp, #0x40]
//   0x0702f8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0702fc: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0962_0x0702f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0702f0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c4750ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0963 | PC: 0x070448 | FDE: 0x0c4778 | Size: 256 bytes
// Hàm FDE #0963 | Địa chỉ PC: 0x070448 | Địa chỉ FDE: 0x0c4778 | Kích thước: 256 bytes
//   0x070448: D10243FF  sub      sp, sp, #0x90
//   0x07044c: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x070450: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x070454: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_0963_0x070448(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070448ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90657f6ULL) ^ 0x0c4778ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0964 | PC: 0x070608 | FDE: 0x0c45f0 | Size: 256 bytes
// Hàm FDE #0964 | Địa chỉ PC: 0x070608 | Địa chỉ FDE: 0x0c45f0 | Kích thước: 256 bytes
//   0x070608: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x07060c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x070610: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x070614: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0964_0x070608(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070608ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c45f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0965 | PC: 0x07079c | FDE: 0x0c47a8 | Size: 256 bytes
// Hàm FDE #0965 | Địa chỉ PC: 0x07079c | Địa chỉ FDE: 0x0c47a8 | Kích thước: 256 bytes
//   0x07079c: D10283FF  sub      sp, sp, #0xa0
//   0x0707a0: F90033F7  str      x23, [sp, #0x60]
//   0x0707a4: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0707a8: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0965_0x07079c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07079cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90033f7ULL) ^ 0x0c47a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0966 | PC: 0x070950 | FDE: 0x0c47d8 | Size: 256 bytes
// Hàm FDE #0966 | Địa chỉ PC: 0x070950 | Địa chỉ FDE: 0x0c47d8 | Kích thước: 256 bytes
//   0x070950: D10203FF  sub      sp, sp, #0x80
//   0x070954: F9001BF9  str      x25, [sp, #0x30]
//   0x070958: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x07095c: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_0966_0x070950(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070950ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf9ULL) ^ 0x0c47d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0967 | PC: 0x070df8 | FDE: 0x0c4618 | Size: 256 bytes
// Hàm FDE #0967 | Địa chỉ PC: 0x070df8 | Địa chỉ FDE: 0x0c4618 | Kích thước: 256 bytes
//   0x070df8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x070dfc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x070e00: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x070e04: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0967_0x070df8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070df8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c4618ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0968 | PC: 0x070f14 | FDE: 0x0c4640 | Size: 256 bytes
// Hàm FDE #0968 | Địa chỉ PC: 0x070f14 | Địa chỉ FDE: 0x0c4640 | Kích thước: 256 bytes
//   0x070f14: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x070f18: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x070f1c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x070f20: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0968_0x070f14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070f14ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c4640ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0969 | PC: 0x0711a0 | FDE: 0x0c4668 | Size: 152 bytes
// Hàm FDE #0969 | Địa chỉ PC: 0x0711a0 | Địa chỉ FDE: 0x0c4668 | Kích thước: 152 bytes
//   0x0711a0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0711a4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0711a8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0711ac: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0969_0x0711a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0711a0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c4668ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0970 | PC: 0x071238 | FDE: 0x0c4808 | Size: 256 bytes
// Hàm FDE #0970 | Địa chỉ PC: 0x071238 | Địa chỉ FDE: 0x0c4808 | Kích thước: 256 bytes
//   0x071238: D101C3FF  sub      sp, sp, #0x70
//   0x07123c: F9001BF7  str      x23, [sp, #0x30]
//   0x071240: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x071244: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0970_0x071238(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071238ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x0c4808ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0971 | PC: 0x07136c | FDE: 0x0c4838 | Size: 256 bytes
// Hàm FDE #0971 | Địa chỉ PC: 0x07136c | Địa chỉ FDE: 0x0c4838 | Kích thước: 256 bytes
//   0x07136c: D101C3FF  sub      sp, sp, #0x70
//   0x071370: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x071374: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x071378: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0971_0x07136c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07136cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x0c4838ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0972 | PC: 0x071518 | FDE: 0x0c4ba8 | Size: 256 bytes
// Hàm FDE #0972 | Địa chỉ PC: 0x071518 | Địa chỉ FDE: 0x0c4ba8 | Kích thước: 256 bytes
//   0x071518: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x07151c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x071520: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x071524: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0972_0x071518(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071518ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c4ba8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0973 | PC: 0x071690 | FDE: 0x0c4bd0 | Size: 256 bytes
// Hàm FDE #0973 | Địa chỉ PC: 0x071690 | Địa chỉ FDE: 0x0c4bd0 | Kích thước: 256 bytes
//   0x071690: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x071694: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x071698: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07169c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0973_0x071690(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071690ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c4bd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0974 | PC: 0x071844 | FDE: 0x0c4868 | Size: 4 bytes
// Hàm FDE #0974 | Địa chỉ PC: 0x071844 | Địa chỉ FDE: 0x0c4868 | Kích thước: 4 bytes
//   0x071844: 14000797  b        #0x736a0
static inline uint64_t fde_func_0974_0x071844(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071844ULL ^ (static_cast<uint64_t>(0x14000797ULL) << 13);
    acc = (acc + a1 + 0xf81d0ff5ULL) ^ 0x0c4868ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0975 | PC: 0x071848 | FDE: 0x0c4880 | Size: 116 bytes
// Hàm FDE #0975 | Địa chỉ PC: 0x071848 | Địa chỉ FDE: 0x0c4880 | Kích thước: 116 bytes
//   0x071848: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x07184c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x071850: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x071854: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0975_0x071848(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071848ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c4880ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0976 | PC: 0x0718bc | FDE: 0x0c48a0 | Size: 56 bytes
// Hàm FDE #0976 | Địa chỉ PC: 0x0718bc | Địa chỉ FDE: 0x0c48a0 | Kích thước: 56 bytes
//   0x0718bc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0718c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0718c4: 910043FD  add      x29, sp, #0x10
//   0x0718c8: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0976_0x0718bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0718bcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c48a0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0977 | PC: 0x0718f4 | FDE: 0x0c48c0 | Size: 88 bytes
// Hàm FDE #0977 | Địa chỉ PC: 0x0718f4 | Địa chỉ FDE: 0x0c48c0 | Kích thước: 88 bytes
//   0x0718f4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0718f8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0718fc: 910043FD  add      x29, sp, #0x10
//   0x071900: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_0977_0x0718f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0718f4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c48c0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0978 | PC: 0x07194c | FDE: 0x0c48e0 | Size: 20 bytes
// Hàm FDE #0978 | Địa chỉ PC: 0x07194c | Địa chỉ FDE: 0x0c48e0 | Kích thước: 20 bytes
//   0x07194c: 39400008  ldrb     w8, [x0]
//   0x071950: 37000048  tbnz     w8, #0, #0x71958
//   0x071954: D65F03C0  ret      
//   0x071958: F9400800  ldr      x0, [x0, #0x10]
static inline uint64_t fde_func_0978_0x07194c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07194cULL ^ (static_cast<uint64_t>(0x39400008ULL) << 13);
    acc = (acc + a1 + 0x37000048ULL) ^ 0x0c48e0ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0979 | PC: 0x071960 | FDE: 0x0c4c00 | Size: 256 bytes
// Hàm FDE #0979 | Địa chỉ PC: 0x071960 | Địa chỉ FDE: 0x0c4c00 | Kích thước: 256 bytes
//   0x071960: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x071964: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x071968: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07196c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0979_0x071960(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071960ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c4c00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0980 | PC: 0x071b44 | FDE: 0x0c48f8 | Size: 188 bytes
// Hàm FDE #0980 | Địa chỉ PC: 0x071b44 | Địa chỉ FDE: 0x0c48f8 | Kích thước: 188 bytes
//   0x071b44: D10143FF  sub      sp, sp, #0x50
//   0x071b48: F90013F5  str      x21, [sp, #0x20]
//   0x071b4c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x071b50: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0980_0x071b44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071b44ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x0c48f8ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0981 | PC: 0x071c00 | FDE: 0x0c4c30 | Size: 256 bytes
// Hàm FDE #0981 | Địa chỉ PC: 0x071c00 | Địa chỉ FDE: 0x0c4c30 | Kích thước: 256 bytes
//   0x071c00: D10483FF  sub      sp, sp, #0x120
//   0x071c04: A90C6FFC  stp      x28, x27, [sp, #0xc0]
//   0x071c08: A90D67FA  stp      x26, x25, [sp, #0xd0]
//   0x071c0c: A90E5FF8  stp      x24, x23, [sp, #0xe0]
static inline uint64_t fde_func_0981_0x071c00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071c00ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa90c6ffcULL) ^ 0x0c4c30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0982 | PC: 0x0720f0 | FDE: 0x0c4c68 | Size: 256 bytes
// Hàm FDE #0982 | Địa chỉ PC: 0x0720f0 | Địa chỉ FDE: 0x0c4c68 | Kích thước: 256 bytes
//   0x0720f0: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0720f4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0720f8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0720fc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0982_0x0720f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0720f0ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c4c68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0983 | PC: 0x072298 | FDE: 0x0c4c98 | Size: 256 bytes
// Hàm FDE #0983 | Địa chỉ PC: 0x072298 | Địa chỉ FDE: 0x0c4c98 | Kích thước: 256 bytes
//   0x072298: D101C3FF  sub      sp, sp, #0x70
//   0x07229c: F9000BFB  str      x27, [sp, #0x10]
//   0x0722a0: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0722a4: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_0983_0x072298(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x072298ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfbULL) ^ 0x0c4c98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0984 | PC: 0x07258c | FDE: 0x0c4cd0 | Size: 256 bytes
// Hàm FDE #0984 | Địa chỉ PC: 0x07258c | Địa chỉ FDE: 0x0c4cd0 | Kích thước: 256 bytes
//   0x07258c: D10183FF  sub      sp, sp, #0x60
//   0x072590: F90013F7  str      x23, [sp, #0x20]
//   0x072594: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x072598: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0984_0x07258c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07258cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x0c4cd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0985 | PC: 0x0726c4 | FDE: 0x0c4918 | Size: 56 bytes
// Hàm FDE #0985 | Địa chỉ PC: 0x0726c4 | Địa chỉ FDE: 0x0c4918 | Kích thước: 56 bytes
//   0x0726c4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0726c8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0726cc: 910043FD  add      x29, sp, #0x10
//   0x0726d0: 9100A014  add      x20, x0, #0x28
static inline uint64_t fde_func_0985_0x0726c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0726c4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c4918ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0986 | PC: 0x0726fc | FDE: 0x0c4d00 | Size: 256 bytes
// Hàm FDE #0986 | Địa chỉ PC: 0x0726fc | Địa chỉ FDE: 0x0c4d00 | Kích thước: 256 bytes
//   0x0726fc: D101C3FF  sub      sp, sp, #0x70
//   0x072700: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x072704: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x072708: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0986_0x0726fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0726fcULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x0c4d00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0987 | PC: 0x07297c | FDE: 0x0c4d30 | Size: 256 bytes
// Hàm FDE #0987 | Địa chỉ PC: 0x07297c | Địa chỉ FDE: 0x0c4d30 | Kích thước: 256 bytes
//   0x07297c: D10203FF  sub      sp, sp, #0x80
//   0x072980: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x072984: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x072988: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_0987_0x07297c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07297cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90367faULL) ^ 0x0c4d30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0988 | PC: 0x072bc4 | FDE: 0x0c4d68 | Size: 256 bytes
// Hàm FDE #0988 | Địa chỉ PC: 0x072bc4 | Địa chỉ FDE: 0x0c4d68 | Kích thước: 256 bytes
//   0x072bc4: D10203FF  sub      sp, sp, #0x80
//   0x072bc8: F90013FB  str      x27, [sp, #0x20]
//   0x072bcc: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x072bd0: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0988_0x072bc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x072bc4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x0c4d68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0989 | PC: 0x072dec | FDE: 0x0c4da0 | Size: 256 bytes
// Hàm FDE #0989 | Địa chỉ PC: 0x072dec | Địa chỉ FDE: 0x0c4da0 | Kích thước: 256 bytes
//   0x072dec: D10503FF  sub      sp, sp, #0x140
//   0x072df0: A90E6FFC  stp      x28, x27, [sp, #0xe0]
//   0x072df4: A90F67FA  stp      x26, x25, [sp, #0xf0]
//   0x072df8: A9105FF8  stp      x24, x23, [sp, #0x100]
static inline uint64_t fde_func_0989_0x072dec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x072decULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xa90e6ffcULL) ^ 0x0c4da0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0990 | PC: 0x073520 | FDE: 0x0c4938 | Size: 256 bytes
// Hàm FDE #0990 | Địa chỉ PC: 0x073520 | Địa chỉ FDE: 0x0c4938 | Kích thước: 256 bytes
//   0x073520: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x073524: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x073528: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07352c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0990_0x073520(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073520ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c4938ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0991 | PC: 0x073624 | FDE: 0x0c4958 | Size: 124 bytes
// Hàm FDE #0991 | Địa chỉ PC: 0x073624 | Địa chỉ FDE: 0x0c4958 | Kích thước: 124 bytes
//   0x073624: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x073628: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07362c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x073630: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0991_0x073624(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073624ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c4958ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0992 | PC: 0x0736a0 | FDE: 0x0c4980 | Size: 212 bytes
// Hàm FDE #0992 | Địa chỉ PC: 0x0736a0 | Địa chỉ FDE: 0x0c4980 | Kích thước: 212 bytes
//   0x0736a0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0736a4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0736a8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0736ac: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0992_0x0736a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0736a0ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c4980ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #0993 | PC: 0x073774 | FDE: 0x0c49a8 | Size: 36 bytes
// Hàm FDE #0993 | Địa chỉ PC: 0x073774 | Địa chỉ FDE: 0x0c49a8 | Kích thước: 36 bytes
//   0x073774: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x073778: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07377c: 910043FD  add      x29, sp, #0x10
//   0x073780: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0993_0x073774(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073774ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c49a8ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0994 | PC: 0x073798 | FDE: 0x0c49c8 | Size: 56 bytes
// Hàm FDE #0994 | Địa chỉ PC: 0x073798 | Địa chỉ FDE: 0x0c49c8 | Kích thước: 56 bytes
//   0x073798: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07379c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0737a0: 910043FD  add      x29, sp, #0x10
//   0x0737a4: F9400C13  ldr      x19, [x0, #0x18]
static inline uint64_t fde_func_0994_0x073798(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073798ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c49c8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0995 | PC: 0x0737d0 | FDE: 0x0c49e8 | Size: 28 bytes
// Hàm FDE #0995 | Địa chỉ PC: 0x0737d0 | Địa chỉ FDE: 0x0c49e8 | Kích thước: 28 bytes
//   0x0737d0: F9400428  ldr      x8, [x1, #8]
//   0x0737d4: 90000209  adrp     x9, #0xb3000
//   0x0737d8: 91332529  add      x9, x9, #0xcc9
//   0x0737dc: 9100600A  add      x10, x0, #0x18
static inline uint64_t fde_func_0995_0x0737d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0737d0ULL ^ (static_cast<uint64_t>(0xf9400428ULL) << 13);
    acc = (acc + a1 + 0x90000209ULL) ^ 0x0c49e8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0996 | PC: 0x0737ec | FDE: 0x0c4a00 | Size: 4 bytes
// Hàm FDE #0996 | Địa chỉ PC: 0x0737ec | Địa chỉ FDE: 0x0c4a00 | Kích thước: 4 bytes
//   0x0737ec: 17FE7C05  b        #0x12800
static inline uint64_t fde_func_0996_0x0737ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0737ecULL ^ (static_cast<uint64_t>(0x17fe7c05ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x0c4a00ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0997 | PC: 0x0737f0 | FDE: 0x0c4a18 | Size: 48 bytes
// Hàm FDE #0997 | Địa chỉ PC: 0x0737f0 | Địa chỉ FDE: 0x0c4a18 | Kích thước: 48 bytes
//   0x0737f0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0737f4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0737f8: 910043FD  add      x29, sp, #0x10
//   0x0737fc: F00003A8  adrp     x8, #0xea000
static inline uint64_t fde_func_0997_0x0737f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0737f0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c4a18ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0998 | PC: 0x073820 | FDE: 0x0c4a38 | Size: 56 bytes
// Hàm FDE #0998 | Địa chỉ PC: 0x073820 | Địa chỉ FDE: 0x0c4a38 | Kích thước: 56 bytes
//   0x073820: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x073824: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x073828: 910043FD  add      x29, sp, #0x10
//   0x07382c: F00003A8  adrp     x8, #0xea000
static inline uint64_t fde_func_0998_0x073820(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073820ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c4a38ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0999 | PC: 0x073858 | FDE: 0x0c4a58 | Size: 8 bytes
// Hàm FDE #0999 | Địa chỉ PC: 0x073858 | Địa chỉ FDE: 0x0c4a58 | Kích thước: 8 bytes
//   0x073858: 91006000  add      x0, x0, #0x18
//   0x07385c: 17FFD853  b        #0x699a8
static inline uint64_t fde_func_0999_0x073858(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073858ULL ^ (static_cast<uint64_t>(0x91006000ULL) << 13);
    acc = (acc + a1 + 0x17ffd853ULL) ^ 0x0c4a58ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1000 | PC: 0x073860 | FDE: 0x0c4a70 | Size: 4 bytes
// Hàm FDE #1000 | Địa chỉ PC: 0x073860 | Địa chỉ FDE: 0x0c4a70 | Kích thước: 4 bytes
//   0x073860: 17FE7BE8  b        #0x12800
static inline uint64_t fde_func_1000_0x073860(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073860ULL ^ (static_cast<uint64_t>(0x17fe7be8ULL) << 13);
    acc = (acc + a1 + 0xd10203ffULL) ^ 0x0c4a70ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1001 | PC: 0x073864 | FDE: 0x0c4dd8 | Size: 256 bytes
// Hàm FDE #1001 | Địa chỉ PC: 0x073864 | Địa chỉ FDE: 0x0c4dd8 | Kích thước: 256 bytes
//   0x073864: D10203FF  sub      sp, sp, #0x80
//   0x073868: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x07386c: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x073870: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1001_0x073864(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073864ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x0c4dd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1002 | PC: 0x073b8c | FDE: 0x0c4a88 | Size: 228 bytes
// Hàm FDE #1002 | Địa chỉ PC: 0x073b8c | Địa chỉ FDE: 0x0c4a88 | Kích thước: 228 bytes
//   0x073b8c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x073b90: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x073b94: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x073b98: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1002_0x073b8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073b8cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c4a88ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #1003 | PC: 0x073c70 | FDE: 0x0c4aa8 | Size: 256 bytes
// Hàm FDE #1003 | Địa chỉ PC: 0x073c70 | Địa chỉ FDE: 0x0c4aa8 | Kích thước: 256 bytes
//   0x073c70: D10203FF  sub      sp, sp, #0x80
//   0x073c74: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x073c78: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x073c7c: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1003_0x073c70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073c70ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x0c4aa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1004 | PC: 0x073ee0 | FDE: 0x0c4ad8 | Size: 256 bytes [_ZN4nuro16ConversationInfoaSEOS0_]
// Hàm FDE #1004 | Địa chỉ PC: 0x073ee0 | Địa chỉ FDE: 0x0c4ad8 | Kích thước: 256 bytes
//   0x073ee0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x073ee4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x073ee8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x073eec: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1004_0x073ee0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073ee0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c4ad8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1005 | PC: 0x073ffc | FDE: 0x0c4e10 | Size: 256 bytes
// Hàm FDE #1005 | Địa chỉ PC: 0x073ffc | Địa chỉ FDE: 0x0c4e10 | Kích thước: 256 bytes
//   0x073ffc: D101C3FF  sub      sp, sp, #0x70
//   0x074000: F9000BFB  str      x27, [sp, #0x10]
//   0x074004: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x074008: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1005_0x073ffc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073ffcULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfbULL) ^ 0x0c4e10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1006 | PC: 0x0741c8 | FDE: 0x0c4b00 | Size: 224 bytes
// Hàm FDE #1006 | Địa chỉ PC: 0x0741c8 | Địa chỉ FDE: 0x0c4b00 | Kích thước: 224 bytes
//   0x0741c8: D10183FF  sub      sp, sp, #0x60
//   0x0741cc: F90013F7  str      x23, [sp, #0x20]
//   0x0741d0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0741d4: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1006_0x0741c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0741c8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x0c4b00ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #1007 | PC: 0x0742a8 | FDE: 0x0c4b28 | Size: 256 bytes
// Hàm FDE #1007 | Địa chỉ PC: 0x0742a8 | Địa chỉ FDE: 0x0c4b28 | Kích thước: 256 bytes
//   0x0742a8: F9400409  ldr      x9, [x0, #8]
//   0x0742ac: F940042A  ldr      x10, [x1, #8]
//   0x0742b0: 9E670120  fmov     d0, x9
//   0x0742b4: 0E205800  cnt      v0.8b, v0.8b
static inline uint64_t fde_func_1007_0x0742a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0742a8ULL ^ (static_cast<uint64_t>(0xf9400409ULL) << 13);
    acc = (acc + a1 + 0xf940042aULL) ^ 0x0c4b28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1008 | PC: 0x0743f4 | FDE: 0x0c4e48 | Size: 256 bytes
// Hàm FDE #1008 | Địa chỉ PC: 0x0743f4 | Địa chỉ FDE: 0x0c4e48 | Kích thước: 256 bytes
//   0x0743f4: D101C3FF  sub      sp, sp, #0x70
//   0x0743f8: F9000BFB  str      x27, [sp, #0x10]
//   0x0743fc: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x074400: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1008_0x0743f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0743f4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfbULL) ^ 0x0c4e48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1009 | PC: 0x0745c0 | FDE: 0x0c4b40 | Size: 256 bytes
// Hàm FDE #1009 | Địa chỉ PC: 0x0745c0 | Địa chỉ FDE: 0x0c4b40 | Kích thước: 256 bytes
//   0x0745c0: F9400409  ldr      x9, [x0, #8]
//   0x0745c4: F940042A  ldr      x10, [x1, #8]
//   0x0745c8: 9E670120  fmov     d0, x9
//   0x0745cc: 0E205800  cnt      v0.8b, v0.8b
static inline uint64_t fde_func_1009_0x0745c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0745c0ULL ^ (static_cast<uint64_t>(0xf9400409ULL) << 13);
    acc = (acc + a1 + 0xf940042aULL) ^ 0x0c4b40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1010 | PC: 0x07470c | FDE: 0x0c4e80 | Size: 256 bytes
// Hàm FDE #1010 | Địa chỉ PC: 0x07470c | Địa chỉ FDE: 0x0c4e80 | Kích thước: 256 bytes
//   0x07470c: D10203FF  sub      sp, sp, #0x80
//   0x074710: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x074714: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x074718: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1010_0x07470c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07470cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x0c4e80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1011 | PC: 0x074a90 | FDE: 0x0c4b58 | Size: 228 bytes
// Hàm FDE #1011 | Địa chỉ PC: 0x074a90 | Địa chỉ FDE: 0x0c4b58 | Kích thước: 228 bytes
//   0x074a90: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x074a94: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x074a98: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x074a9c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1011_0x074a90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x074a90ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c4b58ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #1012 | PC: 0x074b74 | FDE: 0x0c4b78 | Size: 256 bytes
// Hàm FDE #1012 | Địa chỉ PC: 0x074b74 | Địa chỉ FDE: 0x0c4b78 | Kích thước: 256 bytes
//   0x074b74: D10203FF  sub      sp, sp, #0x80
//   0x074b78: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x074b7c: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x074b80: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1012_0x074b74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x074b74ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x0c4b78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1013 | PC: 0x074de4 | FDE: 0x0c4eb8 | Size: 256 bytes
// Hàm FDE #1013 | Địa chỉ PC: 0x074de4 | Địa chỉ FDE: 0x0c4eb8 | Kích thước: 256 bytes
//   0x074de4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x074de8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x074dec: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x074df0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1013_0x074de4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x074de4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c4eb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1014 | PC: 0x074f64 | FDE: 0x0c4fc8 | Size: 164 bytes
// Hàm FDE #1014 | Địa chỉ PC: 0x074f64 | Địa chỉ FDE: 0x0c4fc8 | Kích thước: 164 bytes
//   0x074f64: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x074f68: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x074f6c: 910043FD  add      x29, sp, #0x10
//   0x074f70: F9400028  ldr      x8, [x1]
static inline uint64_t fde_func_1014_0x074f64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x074f64ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c4fc8ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1015 | PC: 0x075008 | FDE: 0x0c4ee8 | Size: 16 bytes
// Hàm FDE #1015 | Địa chỉ PC: 0x075008 | Địa chỉ FDE: 0x0c4ee8 | Kích thước: 16 bytes
//   0x075008: F9400400  ldr      x0, [x0, #8]
//   0x07500c: B4000040  cbz      x0, #0x75014
//   0x075010: 17FE7778  b        #0x12df0
//   0x075014: D65F03C0  ret      
static inline uint64_t fde_func_1015_0x075008(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075008ULL ^ (static_cast<uint64_t>(0xf9400400ULL) << 13);
    acc = (acc + a1 + 0xb4000040ULL) ^ 0x0c4ee8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1016 | PC: 0x075018 | FDE: 0x0c4ff0 | Size: 128 bytes
// Hàm FDE #1016 | Địa chỉ PC: 0x075018 | Địa chỉ FDE: 0x0c4ff0 | Kích thước: 128 bytes
//   0x075018: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07501c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x075020: 910043FD  add      x29, sp, #0x10
//   0x075024: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1016_0x075018(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075018ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c4ff0ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1017 | PC: 0x075098 | FDE: 0x0c5018 | Size: 256 bytes
// Hàm FDE #1017 | Địa chỉ PC: 0x075098 | Địa chỉ FDE: 0x0c5018 | Kích thước: 256 bytes
//   0x075098: D102C3FF  sub      sp, sp, #0xb0
//   0x07509c: F90033F9  str      x25, [sp, #0x60]
//   0x0750a0: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x0750a4: A90857F6  stp      x22, x21, [sp, #0x80]
static inline uint64_t fde_func_1017_0x075098(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075098ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf90033f9ULL) ^ 0x0c5018ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1018 | PC: 0x0753e8 | FDE: 0x0c5048 | Size: 256 bytes
// Hàm FDE #1018 | Địa chỉ PC: 0x0753e8 | Địa chỉ FDE: 0x0c5048 | Kích thước: 256 bytes
//   0x0753e8: D10303FF  sub      sp, sp, #0xc0
//   0x0753ec: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x0753f0: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x0753f4: A90957F6  stp      x22, x21, [sp, #0x90]
static inline uint64_t fde_func_1018_0x0753e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0753e8ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa90767faULL) ^ 0x0c5048ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1019 | PC: 0x07573c | FDE: 0x0c4f00 | Size: 164 bytes
// Hàm FDE #1019 | Địa chỉ PC: 0x07573c | Địa chỉ FDE: 0x0c4f00 | Kích thước: 164 bytes
//   0x07573c: D10443FF  sub      sp, sp, #0x110
//   0x075740: A90F4FFC  stp      x28, x19, [sp, #0xf0]
//   0x075744: A9107BFD  stp      x29, x30, [sp, #0x100]
//   0x075748: 910403FD  add      x29, sp, #0x100
static inline uint64_t fde_func_1019_0x07573c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07573cULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90f4ffcULL) ^ 0x0c4f00ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1020 | PC: 0x0757e0 | FDE: 0x0c4f20 | Size: 100 bytes
// Hàm FDE #1020 | Địa chỉ PC: 0x0757e0 | Địa chỉ FDE: 0x0c4f20 | Kích thước: 100 bytes
//   0x0757e0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0757e4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0757e8: 910043FD  add      x29, sp, #0x10
//   0x0757ec: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1020_0x0757e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0757e0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c4f20ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1021 | PC: 0x075844 | FDE: 0x0c4f40 | Size: 108 bytes
// Hàm FDE #1021 | Địa chỉ PC: 0x075844 | Địa chỉ FDE: 0x0c4f40 | Kích thước: 108 bytes
//   0x075844: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x075848: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07584c: 910043FD  add      x29, sp, #0x10
//   0x075850: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1021_0x075844(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075844ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c4f40ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1022 | PC: 0x0758b0 | FDE: 0x0c4f60 | Size: 12 bytes
// Hàm FDE #1022 | Địa chỉ PC: 0x0758b0 | Địa chỉ FDE: 0x0c4f60 | Kích thước: 12 bytes
//   0x0758b0: F8420C08  ldr      x8, [x0, #0x20]!
//   0x0758b4: F9400101  ldr      x1, [x8]
//   0x0758b8: D61F0020  br       x1
static inline uint64_t fde_func_1022_0x0758b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0758b0ULL ^ (static_cast<uint64_t>(0xf8420c08ULL) << 13);
    acc = (acc + a1 + 0xf9400101ULL) ^ 0x0c4f60ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1023 | PC: 0x0758bc | FDE: 0x0c4f78 | Size: 4 bytes
// Hàm FDE #1023 | Địa chỉ PC: 0x0758bc | Địa chỉ FDE: 0x0c4f78 | Kích thước: 4 bytes
//   0x0758bc: 17FE73D1  b        #0x12800
static inline uint64_t fde_func_1023_0x0758bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0758bcULL ^ (static_cast<uint64_t>(0x17fe73d1ULL) << 13);
    acc = (acc + a1 + 0xd10183ffULL) ^ 0x0c4f78ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1024 | PC: 0x0758c0 | FDE: 0x0c5080 | Size: 256 bytes
// Hàm FDE #1024 | Địa chỉ PC: 0x0758c0 | Địa chỉ FDE: 0x0c5080 | Kích thước: 256 bytes
//   0x0758c0: D10183FF  sub      sp, sp, #0x60
//   0x0758c4: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0758c8: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x0758cc: 910143FD  add      x29, sp, #0x50
static inline uint64_t fde_func_1024_0x0758c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0758c0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9044ff4ULL) ^ 0x0c5080ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1025 | PC: 0x0759d8 | FDE: 0x0c4f90 | Size: 64 bytes
// Hàm FDE #1025 | Địa chỉ PC: 0x0759d8 | Địa chỉ FDE: 0x0c4f90 | Kích thước: 64 bytes
//   0x0759d8: AA0003E8  mov      x8, x0
//   0x0759dc: F9401800  ldr      x0, [x0, #0x30]
//   0x0759e0: B00003A9  adrp     x9, #0xea000
//   0x0759e4: 9100410A  add      x10, x8, #0x10
static inline uint64_t fde_func_1025_0x0759d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0759d8ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xf9401800ULL) ^ 0x0c4f90ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1026 | PC: 0x075a18 | FDE: 0x0c4fa8 | Size: 88 bytes
// Hàm FDE #1026 | Địa chỉ PC: 0x075a18 | Địa chỉ FDE: 0x0c4fa8 | Kích thước: 88 bytes
//   0x075a18: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x075a1c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x075a20: 910043FD  add      x29, sp, #0x10
//   0x075a24: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1026_0x075a18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075a18ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c4fa8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1027 | PC: 0x075a70 | FDE: 0x0c50a8 | Size: 256 bytes
// Hàm FDE #1027 | Địa chỉ PC: 0x075a70 | Địa chỉ FDE: 0x0c50a8 | Kích thước: 256 bytes
//   0x075a70: D10143FF  sub      sp, sp, #0x50
//   0x075a74: F90013F5  str      x21, [sp, #0x20]
//   0x075a78: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x075a7c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1027_0x075a70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075a70ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x0c50a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1028 | PC: 0x075b84 | FDE: 0x0c55d0 | Size: 256 bytes
// Hàm FDE #1028 | Địa chỉ PC: 0x075b84 | Địa chỉ FDE: 0x0c55d0 | Kích thước: 256 bytes
//   0x075b84: D10203FF  sub      sp, sp, #0x80
//   0x075b88: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x075b8c: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x075b90: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1028_0x075b84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075b84ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90367faULL) ^ 0x0c55d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1029 | PC: 0x075dc8 | FDE: 0x0c5608 | Size: 256 bytes
// Hàm FDE #1029 | Địa chỉ PC: 0x075dc8 | Địa chỉ FDE: 0x0c5608 | Kích thước: 256 bytes
//   0x075dc8: D10343FF  sub      sp, sp, #0xd0
//   0x075dcc: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x075dd0: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x075dd4: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_1029_0x075dc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075dc8ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9076ffcULL) ^ 0x0c5608ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1030 | PC: 0x076134 | FDE: 0x0c5640 | Size: 224 bytes
// Hàm FDE #1030 | Địa chỉ PC: 0x076134 | Địa chỉ FDE: 0x0c5640 | Kích thước: 224 bytes
//   0x076134: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x076138: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07613c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x076140: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1030_0x076134(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076134ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c5640ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #1031 | PC: 0x076214 | FDE: 0x0c50d0 | Size: 124 bytes
// Hàm FDE #1031 | Địa chỉ PC: 0x076214 | Địa chỉ FDE: 0x0c50d0 | Kích thước: 124 bytes
//   0x076214: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x076218: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07621c: 910043FD  add      x29, sp, #0x10
//   0x076220: 39414008  ldrb     w8, [x0, #0x50]
static inline uint64_t fde_func_1031_0x076214(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076214ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c50d0ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1032 | PC: 0x076290 | FDE: 0x0c50f0 | Size: 16 bytes
// Hàm FDE #1032 | Địa chỉ PC: 0x076290 | Địa chỉ FDE: 0x0c50f0 | Kích thước: 16 bytes
//   0x076290: F9400400  ldr      x0, [x0, #8]
//   0x076294: B4000040  cbz      x0, #0x7629c
//   0x076298: 17FE72D6  b        #0x12df0
//   0x07629c: D65F03C0  ret      
static inline uint64_t fde_func_1032_0x076290(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076290ULL ^ (static_cast<uint64_t>(0xf9400400ULL) << 13);
    acc = (acc + a1 + 0xb4000040ULL) ^ 0x0c50f0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1033 | PC: 0x0762a0 | FDE: 0x0c5670 | Size: 256 bytes
// Hàm FDE #1033 | Địa chỉ PC: 0x0762a0 | Địa chỉ FDE: 0x0c5670 | Kích thước: 256 bytes
//   0x0762a0: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0762a4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0762a8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0762ac: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1033_0x0762a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0762a0ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c5670ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1034 | PC: 0x07646c | FDE: 0x0c56a0 | Size: 256 bytes
// Hàm FDE #1034 | Địa chỉ PC: 0x07646c | Địa chỉ FDE: 0x0c56a0 | Kích thước: 256 bytes
//   0x07646c: D10383FF  sub      sp, sp, #0xe0
//   0x076470: F90043FB  str      x27, [sp, #0x80]
//   0x076474: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x076478: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_1034_0x07646c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07646cULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xf90043fbULL) ^ 0x0c56a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1035 | PC: 0x076854 | FDE: 0x0c56d8 | Size: 96 bytes
// Hàm FDE #1035 | Địa chỉ PC: 0x076854 | Địa chỉ FDE: 0x0c56d8 | Kích thước: 96 bytes
//   0x076854: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x076858: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07685c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x076860: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1035_0x076854(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076854ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c56d8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1036 | PC: 0x0768b4 | FDE: 0x0c5700 | Size: 256 bytes
// Hàm FDE #1036 | Địa chỉ PC: 0x0768b4 | Địa chỉ FDE: 0x0c5700 | Kích thước: 256 bytes
//   0x0768b4: D103C3FF  sub      sp, sp, #0xf0
//   0x0768b8: F9004BFB  str      x27, [sp, #0x90]
//   0x0768bc: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x0768c0: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_1036_0x0768b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0768b4ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xf9004bfbULL) ^ 0x0c5700ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1037 | PC: 0x076cac | FDE: 0x0c5108 | Size: 16 bytes
// Hàm FDE #1037 | Địa chỉ PC: 0x076cac | Địa chỉ FDE: 0x0c5108 | Kích thước: 16 bytes
//   0x076cac: B940A808  ldr      w8, [x0, #0xa8]
//   0x076cb0: 11000508  add      w8, w8, #1
//   0x076cb4: B900A808  str      w8, [x0, #0xa8]
//   0x076cb8: D65F03C0  ret      
static inline uint64_t fde_func_1037_0x076cac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076cacULL ^ (static_cast<uint64_t>(0xb940a808ULL) << 13);
    acc = (acc + a1 + 0x11000508ULL) ^ 0x0c5108ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1038 | PC: 0x076cbc | FDE: 0x0c5120 | Size: 104 bytes
// Hàm FDE #1038 | Địa chỉ PC: 0x076cbc | Địa chỉ FDE: 0x0c5120 | Kích thước: 104 bytes
//   0x076cbc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x076cc0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x076cc4: 910043FD  add      x29, sp, #0x10
//   0x076cc8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1038_0x076cbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076cbcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5120ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1039 | PC: 0x076d24 | FDE: 0x0c5738 | Size: 256 bytes
// Hàm FDE #1039 | Địa chỉ PC: 0x076d24 | Địa chỉ FDE: 0x0c5738 | Kích thước: 256 bytes
//   0x076d24: D10483FF  sub      sp, sp, #0x120
//   0x076d28: F90073FC  str      x28, [sp, #0xe0]
//   0x076d2c: A90F57F6  stp      x22, x21, [sp, #0xf0]
//   0x076d30: A9104FF4  stp      x20, x19, [sp, #0x100]
static inline uint64_t fde_func_1039_0x076d24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076d24ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xf90073fcULL) ^ 0x0c5738ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1040 | PC: 0x07702c | FDE: 0x0c5768 | Size: 256 bytes
// Hàm FDE #1040 | Địa chỉ PC: 0x07702c | Địa chỉ FDE: 0x0c5768 | Kích thước: 256 bytes
//   0x07702c: D10283FF  sub      sp, sp, #0xa0
//   0x077030: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x077034: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x077038: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_1040_0x07702c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07702cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x0c5768ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1041 | PC: 0x077210 | FDE: 0x0c5798 | Size: 256 bytes
// Hàm FDE #1041 | Địa chỉ PC: 0x077210 | Địa chỉ FDE: 0x0c5798 | Kích thước: 256 bytes
//   0x077210: D10203FF  sub      sp, sp, #0x80
//   0x077214: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x077218: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x07721c: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_1041_0x077210(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077210ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9045ff8ULL) ^ 0x0c5798ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1042 | PC: 0x0773e4 | FDE: 0x0c57c8 | Size: 252 bytes
// Hàm FDE #1042 | Địa chỉ PC: 0x0773e4 | Địa chỉ FDE: 0x0c57c8 | Kích thước: 252 bytes
//   0x0773e4: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0773e8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0773ec: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0773f0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1042_0x0773e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0773e4ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c57c8ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1043 | PC: 0x0774e0 | FDE: 0x0c57f8 | Size: 184 bytes
// Hàm FDE #1043 | Địa chỉ PC: 0x0774e0 | Địa chỉ FDE: 0x0c57f8 | Kích thước: 184 bytes
//   0x0774e0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0774e4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0774e8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0774ec: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1043_0x0774e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0774e0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c57f8ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1044 | PC: 0x077598 | FDE: 0x0c5140 | Size: 108 bytes
// Hàm FDE #1044 | Địa chỉ PC: 0x077598 | Địa chỉ FDE: 0x0c5140 | Kích thước: 108 bytes
//   0x077598: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07759c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0775a0: 910043FD  add      x29, sp, #0x10
//   0x0775a4: 3940C008  ldrb     w8, [x0, #0x30]
static inline uint64_t fde_func_1044_0x077598(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077598ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5140ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1045 | PC: 0x077604 | FDE: 0x0c5160 | Size: 108 bytes
// Hàm FDE #1045 | Địa chỉ PC: 0x077604 | Địa chỉ FDE: 0x0c5160 | Kích thước: 108 bytes
//   0x077604: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x077608: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07760c: 910043FD  add      x29, sp, #0x10
//   0x077610: 3940C008  ldrb     w8, [x0, #0x30]
static inline uint64_t fde_func_1045_0x077604(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077604ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5160ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1046 | PC: 0x077670 | FDE: 0x0c5820 | Size: 84 bytes
// Hàm FDE #1046 | Địa chỉ PC: 0x077670 | Địa chỉ FDE: 0x0c5820 | Kích thước: 84 bytes
//   0x077670: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x077674: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x077678: 910043FD  add      x29, sp, #0x10
//   0x07767c: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1046_0x077670(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077670ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5820ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1047 | PC: 0x0776c4 | FDE: 0x0c5180 | Size: 28 bytes
// Hàm FDE #1047 | Địa chỉ PC: 0x0776c4 | Địa chỉ FDE: 0x0c5180 | Kích thước: 28 bytes
//   0x0776c4: F0000389  adrp     x9, #0xea000
//   0x0776c8: AA0103E8  mov      x8, x1
//   0x0776cc: 91200129  add      x9, x9, #0x800
//   0x0776d0: F8008509  str      x9, [x8], #8
static inline uint64_t fde_func_1047_0x0776c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0776c4ULL ^ (static_cast<uint64_t>(0xf0000389ULL) << 13);
    acc = (acc + a1 + 0xaa0103e8ULL) ^ 0x0c5180ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1048 | PC: 0x0776e0 | FDE: 0x0c5198 | Size: 96 bytes
// Hàm FDE #1048 | Địa chỉ PC: 0x0776e0 | Địa chỉ FDE: 0x0c5198 | Kích thước: 96 bytes
//   0x0776e0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0776e4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0776e8: 910043FD  add      x29, sp, #0x10
//   0x0776ec: 3940C008  ldrb     w8, [x0, #0x30]
static inline uint64_t fde_func_1048_0x0776e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0776e0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5198ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1049 | PC: 0x077740 | FDE: 0x0c51b8 | Size: 96 bytes
// Hàm FDE #1049 | Địa chỉ PC: 0x077740 | Địa chỉ FDE: 0x0c51b8 | Kích thước: 96 bytes
//   0x077740: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x077744: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x077748: 910043FD  add      x29, sp, #0x10
//   0x07774c: 3940C008  ldrb     w8, [x0, #0x30]
static inline uint64_t fde_func_1049_0x077740(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077740ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c51b8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1050 | PC: 0x0777a0 | FDE: 0x0c5848 | Size: 256 bytes
// Hàm FDE #1050 | Địa chỉ PC: 0x0777a0 | Địa chỉ FDE: 0x0c5848 | Kích thước: 256 bytes
//   0x0777a0: D10343FF  sub      sp, sp, #0xd0
//   0x0777a4: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x0777a8: A90B4FF4  stp      x20, x19, [sp, #0xb0]
//   0x0777ac: A90C7BFD  stp      x29, x30, [sp, #0xc0]
static inline uint64_t fde_func_1050_0x0777a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0777a0ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa90a57f6ULL) ^ 0x0c5848ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1051 | PC: 0x077ba0 | FDE: 0x0c51d8 | Size: 28 bytes
// Hàm FDE #1051 | Địa chỉ PC: 0x077ba0 | Địa chỉ FDE: 0x0c51d8 | Kích thước: 28 bytes
//   0x077ba0: F9400428  ldr      x8, [x1, #8]
//   0x077ba4: B00001E9  adrp     x9, #0xb4000
//   0x077ba8: 91117529  add      x9, x9, #0x45d
//   0x077bac: 9100200A  add      x10, x0, #8
static inline uint64_t fde_func_1051_0x077ba0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077ba0ULL ^ (static_cast<uint64_t>(0xf9400428ULL) << 13);
    acc = (acc + a1 + 0xb00001e9ULL) ^ 0x0c51d8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1052 | PC: 0x077bbc | FDE: 0x0c51f0 | Size: 12 bytes
// Hàm FDE #1052 | Địa chỉ PC: 0x077bbc | Địa chỉ FDE: 0x0c51f0 | Kích thước: 12 bytes
//   0x077bbc: F0000380  adrp     x0, #0xea000
//   0x077bc0: 91218000  add      x0, x0, #0x860
//   0x077bc4: D65F03C0  ret      
static inline uint64_t fde_func_1052_0x077bbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077bbcULL ^ (static_cast<uint64_t>(0xf0000380ULL) << 13);
    acc = (acc + a1 + 0x91218000ULL) ^ 0x0c51f0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1053 | PC: 0x077bc8 | FDE: 0x0c5878 | Size: 180 bytes
// Hàm FDE #1053 | Địa chỉ PC: 0x077bc8 | Địa chỉ FDE: 0x0c5878 | Kích thước: 180 bytes
//   0x077bc8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x077bcc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x077bd0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x077bd4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1053_0x077bc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077bc8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c5878ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1054 | PC: 0x077c7c | FDE: 0x0c5208 | Size: 164 bytes
// Hàm FDE #1054 | Địa chỉ PC: 0x077c7c | Địa chỉ FDE: 0x0c5208 | Kích thước: 164 bytes
//   0x077c7c: D10443FF  sub      sp, sp, #0x110
//   0x077c80: A90F4FFC  stp      x28, x19, [sp, #0xf0]
//   0x077c84: A9107BFD  stp      x29, x30, [sp, #0x100]
//   0x077c88: 910403FD  add      x29, sp, #0x100
static inline uint64_t fde_func_1054_0x077c7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077c7cULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90f4ffcULL) ^ 0x0c5208ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1055 | PC: 0x077d20 | FDE: 0x0c5228 | Size: 108 bytes
// Hàm FDE #1055 | Địa chỉ PC: 0x077d20 | Địa chỉ FDE: 0x0c5228 | Kích thước: 108 bytes
//   0x077d20: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x077d24: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x077d28: 910043FD  add      x29, sp, #0x10
//   0x077d2c: 3940C008  ldrb     w8, [x0, #0x30]
static inline uint64_t fde_func_1055_0x077d20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077d20ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5228ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1056 | PC: 0x077d8c | FDE: 0x0c5248 | Size: 108 bytes
// Hàm FDE #1056 | Địa chỉ PC: 0x077d8c | Địa chỉ FDE: 0x0c5248 | Kích thước: 108 bytes
//   0x077d8c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x077d90: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x077d94: 910043FD  add      x29, sp, #0x10
//   0x077d98: 3940C008  ldrb     w8, [x0, #0x30]
static inline uint64_t fde_func_1056_0x077d8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077d8cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5248ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1057 | PC: 0x077df8 | FDE: 0x0c58a0 | Size: 84 bytes
// Hàm FDE #1057 | Địa chỉ PC: 0x077df8 | Địa chỉ FDE: 0x0c58a0 | Kích thước: 84 bytes
//   0x077df8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x077dfc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x077e00: 910043FD  add      x29, sp, #0x10
//   0x077e04: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1057_0x077df8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077df8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c58a0ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1058 | PC: 0x077e4c | FDE: 0x0c5268 | Size: 28 bytes
// Hàm FDE #1058 | Địa chỉ PC: 0x077e4c | Địa chỉ FDE: 0x0c5268 | Kích thước: 28 bytes
//   0x077e4c: F0000389  adrp     x9, #0xea000
//   0x077e50: AA0103E8  mov      x8, x1
//   0x077e54: 91220129  add      x9, x9, #0x880
//   0x077e58: F8008509  str      x9, [x8], #8
static inline uint64_t fde_func_1058_0x077e4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077e4cULL ^ (static_cast<uint64_t>(0xf0000389ULL) << 13);
    acc = (acc + a1 + 0xaa0103e8ULL) ^ 0x0c5268ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1059 | PC: 0x077e68 | FDE: 0x0c5280 | Size: 96 bytes
// Hàm FDE #1059 | Địa chỉ PC: 0x077e68 | Địa chỉ FDE: 0x0c5280 | Kích thước: 96 bytes
//   0x077e68: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x077e6c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x077e70: 910043FD  add      x29, sp, #0x10
//   0x077e74: 3940C008  ldrb     w8, [x0, #0x30]
static inline uint64_t fde_func_1059_0x077e68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077e68ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5280ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1060 | PC: 0x077ec8 | FDE: 0x0c52a0 | Size: 96 bytes
// Hàm FDE #1060 | Địa chỉ PC: 0x077ec8 | Địa chỉ FDE: 0x0c52a0 | Kích thước: 96 bytes
//   0x077ec8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x077ecc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x077ed0: 910043FD  add      x29, sp, #0x10
//   0x077ed4: 3940C008  ldrb     w8, [x0, #0x30]
static inline uint64_t fde_func_1060_0x077ec8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077ec8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c52a0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1061 | PC: 0x077f28 | FDE: 0x0c58c8 | Size: 256 bytes
// Hàm FDE #1061 | Địa chỉ PC: 0x077f28 | Địa chỉ FDE: 0x0c58c8 | Kích thước: 256 bytes
//   0x077f28: D10343FF  sub      sp, sp, #0xd0
//   0x077f2c: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x077f30: A90B4FF4  stp      x20, x19, [sp, #0xb0]
//   0x077f34: A90C7BFD  stp      x29, x30, [sp, #0xc0]
static inline uint64_t fde_func_1061_0x077f28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077f28ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa90a57f6ULL) ^ 0x0c58c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1062 | PC: 0x078330 | FDE: 0x0c52c0 | Size: 28 bytes
// Hàm FDE #1062 | Địa chỉ PC: 0x078330 | Địa chỉ FDE: 0x0c52c0 | Kích thước: 28 bytes
//   0x078330: F9400428  ldr      x8, [x1, #8]
//   0x078334: 900001E9  adrp     x9, #0xb4000
//   0x078338: 9115A529  add      x9, x9, #0x569
//   0x07833c: 9100200A  add      x10, x0, #8
static inline uint64_t fde_func_1062_0x078330(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x078330ULL ^ (static_cast<uint64_t>(0xf9400428ULL) << 13);
    acc = (acc + a1 + 0x900001e9ULL) ^ 0x0c52c0ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1063 | PC: 0x07834c | FDE: 0x0c52d8 | Size: 12 bytes
// Hàm FDE #1063 | Địa chỉ PC: 0x07834c | Địa chỉ FDE: 0x0c52d8 | Kích thước: 12 bytes
//   0x07834c: D0000380  adrp     x0, #0xea000
//   0x078350: 91238000  add      x0, x0, #0x8e0
//   0x078354: D65F03C0  ret      
static inline uint64_t fde_func_1063_0x07834c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07834cULL ^ (static_cast<uint64_t>(0xd0000380ULL) << 13);
    acc = (acc + a1 + 0x91238000ULL) ^ 0x0c52d8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1064 | PC: 0x078358 | FDE: 0x0c58f8 | Size: 188 bytes
// Hàm FDE #1064 | Địa chỉ PC: 0x078358 | Địa chỉ FDE: 0x0c58f8 | Kích thước: 188 bytes
//   0x078358: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x07835c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x078360: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x078364: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1064_0x078358(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x078358ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c58f8ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1065 | PC: 0x078414 | FDE: 0x0c52f0 | Size: 124 bytes
// Hàm FDE #1065 | Địa chỉ PC: 0x078414 | Địa chỉ FDE: 0x0c52f0 | Kích thước: 124 bytes
//   0x078414: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x078418: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07841c: 910043FD  add      x29, sp, #0x10
//   0x078420: F9402414  ldr      x20, [x0, #0x48]
static inline uint64_t fde_func_1065_0x078414(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x078414ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c52f0ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1066 | PC: 0x078490 | FDE: 0x0c5310 | Size: 124 bytes
// Hàm FDE #1066 | Địa chỉ PC: 0x078490 | Địa chỉ FDE: 0x0c5310 | Kích thước: 124 bytes
//   0x078490: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x078494: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x078498: 910043FD  add      x29, sp, #0x10
//   0x07849c: F9402414  ldr      x20, [x0, #0x48]
static inline uint64_t fde_func_1066_0x078490(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x078490ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5310ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1067 | PC: 0x07850c | FDE: 0x0c5330 | Size: 136 bytes
// Hàm FDE #1067 | Địa chỉ PC: 0x07850c | Địa chỉ FDE: 0x0c5330 | Kích thước: 136 bytes
//   0x07850c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x078510: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x078514: 910043FD  add      x29, sp, #0x10
//   0x078518: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1067_0x07850c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07850cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5330ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1068 | PC: 0x078594 | FDE: 0x0c5350 | Size: 104 bytes
// Hàm FDE #1068 | Địa chỉ PC: 0x078594 | Địa chỉ FDE: 0x0c5350 | Kích thước: 104 bytes
//   0x078594: D0000388  adrp     x8, #0xea000
//   0x078598: 91240108  add      x8, x8, #0x900
//   0x07859c: F9000028  str      x8, [x1]
//   0x0785a0: 3CC08000  ldur     q0, [x0, #8]
static inline uint64_t fde_func_1068_0x078594(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x078594ULL ^ (static_cast<uint64_t>(0xd0000388ULL) << 13);
    acc = (acc + a1 + 0x91240108ULL) ^ 0x0c5350ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1069 | PC: 0x0785fc | FDE: 0x0c5368 | Size: 112 bytes
// Hàm FDE #1069 | Địa chỉ PC: 0x0785fc | Địa chỉ FDE: 0x0c5368 | Kích thước: 112 bytes
//   0x0785fc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x078600: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x078604: 910043FD  add      x29, sp, #0x10
//   0x078608: F9402414  ldr      x20, [x0, #0x48]
static inline uint64_t fde_func_1069_0x0785fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0785fcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5368ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1070 | PC: 0x07866c | FDE: 0x0c5388 | Size: 112 bytes
// Hàm FDE #1070 | Địa chỉ PC: 0x07866c | Địa chỉ FDE: 0x0c5388 | Kích thước: 112 bytes
//   0x07866c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x078670: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x078674: 910043FD  add      x29, sp, #0x10
//   0x078678: F9402414  ldr      x20, [x0, #0x48]
static inline uint64_t fde_func_1070_0x07866c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07866cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5388ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1071 | PC: 0x0786dc | FDE: 0x0c5920 | Size: 256 bytes
// Hàm FDE #1071 | Địa chỉ PC: 0x0786dc | Địa chỉ FDE: 0x0c5920 | Kích thước: 256 bytes
//   0x0786dc: F81B0FFC  str      x28, [sp, #-0x50]!
//   0x0786e0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0786e4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0786e8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1071_0x0786dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0786dcULL ^ (static_cast<uint64_t>(0xf81b0ffcULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c5920ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1072 | PC: 0x079354 | FDE: 0x0c53a8 | Size: 28 bytes
// Hàm FDE #1072 | Địa chỉ PC: 0x079354 | Địa chỉ FDE: 0x0c53a8 | Kích thước: 28 bytes
//   0x079354: F9400428  ldr      x8, [x1, #8]
//   0x079358: F00001C9  adrp     x9, #0xb4000
//   0x07935c: 91192529  add      x9, x9, #0x649
//   0x079360: 9100200A  add      x10, x0, #8
static inline uint64_t fde_func_1072_0x079354(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x079354ULL ^ (static_cast<uint64_t>(0xf9400428ULL) << 13);
    acc = (acc + a1 + 0xf00001c9ULL) ^ 0x0c53a8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1073 | PC: 0x079370 | FDE: 0x0c53c0 | Size: 12 bytes
// Hàm FDE #1073 | Địa chỉ PC: 0x079370 | Địa chỉ FDE: 0x0c53c0 | Kích thước: 12 bytes
//   0x079370: B0000380  adrp     x0, #0xea000
//   0x079374: 91258000  add      x0, x0, #0x960
//   0x079378: D65F03C0  ret      
static inline uint64_t fde_func_1073_0x079370(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x079370ULL ^ (static_cast<uint64_t>(0xb0000380ULL) << 13);
    acc = (acc + a1 + 0x91258000ULL) ^ 0x0c53c0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1074 | PC: 0x07937c | FDE: 0x0c53d8 | Size: 256 bytes
// Hàm FDE #1074 | Địa chỉ PC: 0x07937c | Địa chỉ FDE: 0x0c53d8 | Kích thước: 256 bytes
//   0x07937c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x079380: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x079384: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x079388: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1074_0x07937c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07937cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c53d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1075 | PC: 0x079500 | FDE: 0x0c5400 | Size: 124 bytes
// Hàm FDE #1075 | Địa chỉ PC: 0x079500 | Địa chỉ FDE: 0x0c5400 | Kích thước: 124 bytes
//   0x079500: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x079504: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x079508: 910043FD  add      x29, sp, #0x10
//   0x07950c: F9401414  ldr      x20, [x0, #0x28]
static inline uint64_t fde_func_1075_0x079500(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x079500ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5400ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1076 | PC: 0x07957c | FDE: 0x0c5420 | Size: 124 bytes
// Hàm FDE #1076 | Địa chỉ PC: 0x07957c | Địa chỉ FDE: 0x0c5420 | Kích thước: 124 bytes
//   0x07957c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x079580: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x079584: 910043FD  add      x29, sp, #0x10
//   0x079588: F9401414  ldr      x20, [x0, #0x28]
static inline uint64_t fde_func_1076_0x07957c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07957cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5420ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1077 | PC: 0x0795f8 | FDE: 0x0c5440 | Size: 128 bytes
// Hàm FDE #1077 | Địa chỉ PC: 0x0795f8 | Địa chỉ FDE: 0x0c5440 | Kích thước: 128 bytes
//   0x0795f8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0795fc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x079600: 910043FD  add      x29, sp, #0x10
//   0x079604: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1077_0x0795f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0795f8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5440ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1078 | PC: 0x079678 | FDE: 0x0c5460 | Size: 96 bytes
// Hàm FDE #1078 | Địa chỉ PC: 0x079678 | Địa chỉ FDE: 0x0c5460 | Kích thước: 96 bytes
//   0x079678: B0000388  adrp     x8, #0xea000
//   0x07967c: 91260108  add      x8, x8, #0x980
//   0x079680: F9000028  str      x8, [x1]
//   0x079684: 3CC08000  ldur     q0, [x0, #8]
static inline uint64_t fde_func_1078_0x079678(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x079678ULL ^ (static_cast<uint64_t>(0xb0000388ULL) << 13);
    acc = (acc + a1 + 0x91260108ULL) ^ 0x0c5460ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1079 | PC: 0x0796d8 | FDE: 0x0c5478 | Size: 112 bytes
// Hàm FDE #1079 | Địa chỉ PC: 0x0796d8 | Địa chỉ FDE: 0x0c5478 | Kích thước: 112 bytes
//   0x0796d8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0796dc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0796e0: 910043FD  add      x29, sp, #0x10
//   0x0796e4: F9401414  ldr      x20, [x0, #0x28]
static inline uint64_t fde_func_1079_0x0796d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0796d8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5478ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1080 | PC: 0x079748 | FDE: 0x0c5498 | Size: 112 bytes
// Hàm FDE #1080 | Địa chỉ PC: 0x079748 | Địa chỉ FDE: 0x0c5498 | Kích thước: 112 bytes
//   0x079748: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07974c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x079750: 910043FD  add      x29, sp, #0x10
//   0x079754: F9401414  ldr      x20, [x0, #0x28]
static inline uint64_t fde_func_1080_0x079748(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x079748ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5498ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1081 | PC: 0x0797b8 | FDE: 0x0c5950 | Size: 256 bytes
// Hàm FDE #1081 | Địa chỉ PC: 0x0797b8 | Địa chỉ FDE: 0x0c5950 | Kích thước: 256 bytes
//   0x0797b8: D105C3FF  sub      sp, sp, #0x170
//   0x0797bc: A91267FC  stp      x28, x25, [sp, #0x120]
//   0x0797c0: A9135FF8  stp      x24, x23, [sp, #0x130]
//   0x0797c4: A91457F6  stp      x22, x21, [sp, #0x140]
static inline uint64_t fde_func_1081_0x0797b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0797b8ULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xa91267fcULL) ^ 0x0c5950ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1082 | PC: 0x07a1d0 | FDE: 0x0c54b8 | Size: 28 bytes
// Hàm FDE #1082 | Địa chỉ PC: 0x07a1d0 | Địa chỉ FDE: 0x0c54b8 | Kích thước: 28 bytes
//   0x07a1d0: F9400428  ldr      x8, [x1, #8]
//   0x07a1d4: D00001C9  adrp     x9, #0xb4000
//   0x07a1d8: 911BBD29  add      x9, x9, #0x6ef
//   0x07a1dc: 9100200A  add      x10, x0, #8
static inline uint64_t fde_func_1082_0x07a1d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a1d0ULL ^ (static_cast<uint64_t>(0xf9400428ULL) << 13);
    acc = (acc + a1 + 0xd00001c9ULL) ^ 0x0c54b8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1083 | PC: 0x07a1ec | FDE: 0x0c54d0 | Size: 12 bytes
// Hàm FDE #1083 | Địa chỉ PC: 0x07a1ec | Địa chỉ FDE: 0x0c54d0 | Kích thước: 12 bytes
//   0x07a1ec: 90000380  adrp     x0, #0xea000
//   0x07a1f0: 91278000  add      x0, x0, #0x9e0
//   0x07a1f4: D65F03C0  ret      
static inline uint64_t fde_func_1083_0x07a1ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a1ecULL ^ (static_cast<uint64_t>(0x90000380ULL) << 13);
    acc = (acc + a1 + 0x91278000ULL) ^ 0x0c54d0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1084 | PC: 0x07a1f8 | FDE: 0x0c54e8 | Size: 156 bytes
// Hàm FDE #1084 | Địa chỉ PC: 0x07a1f8 | Địa chỉ FDE: 0x0c54e8 | Kích thước: 156 bytes
//   0x07a1f8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07a1fc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07a200: 910043FD  add      x29, sp, #0x10
//   0x07a204: 3941A008  ldrb     w8, [x0, #0x68]
static inline uint64_t fde_func_1084_0x07a1f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a1f8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c54e8ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1085 | PC: 0x07a294 | FDE: 0x0c5508 | Size: 156 bytes
// Hàm FDE #1085 | Địa chỉ PC: 0x07a294 | Địa chỉ FDE: 0x0c5508 | Kích thước: 156 bytes
//   0x07a294: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07a298: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07a29c: 910043FD  add      x29, sp, #0x10
//   0x07a2a0: 3941A008  ldrb     w8, [x0, #0x68]
static inline uint64_t fde_func_1085_0x07a294(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a294ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5508ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1086 | PC: 0x07a330 | FDE: 0x0c5988 | Size: 144 bytes
// Hàm FDE #1086 | Địa chỉ PC: 0x07a330 | Địa chỉ FDE: 0x0c5988 | Kích thước: 144 bytes
//   0x07a330: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07a334: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07a338: 910043FD  add      x29, sp, #0x10
//   0x07a33c: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1086_0x07a330(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a330ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5988ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1087 | PC: 0x07a3c0 | FDE: 0x0c59b0 | Size: 124 bytes
// Hàm FDE #1087 | Địa chỉ PC: 0x07a3c0 | Địa chỉ FDE: 0x0c59b0 | Kích thước: 124 bytes
//   0x07a3c0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07a3c4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07a3c8: 910043FD  add      x29, sp, #0x10
//   0x07a3cc: 90000388  adrp     x8, #0xea000
static inline uint64_t fde_func_1087_0x07a3c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a3c0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c59b0ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1088 | PC: 0x07a43c | FDE: 0x0c5528 | Size: 8 bytes
// Hàm FDE #1088 | Địa chỉ PC: 0x07a43c | Địa chỉ FDE: 0x0c5528 | Kích thước: 8 bytes
//   0x07a43c: 91002000  add      x0, x0, #8
//   0x07a440: 140001E8  b        #0x7abe0
static inline uint64_t fde_func_1088_0x07a43c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a43cULL ^ (static_cast<uint64_t>(0x91002000ULL) << 13);
    acc = (acc + a1 + 0x140001e8ULL) ^ 0x0c5528ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1089 | PC: 0x07a444 | FDE: 0x0c5540 | Size: 40 bytes
// Hàm FDE #1089 | Địa chỉ PC: 0x07a444 | Địa chỉ FDE: 0x0c5540 | Kích thước: 40 bytes
//   0x07a444: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07a448: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07a44c: 910043FD  add      x29, sp, #0x10
//   0x07a450: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1089_0x07a444(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a444ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5540ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1090 | PC: 0x07a46c | FDE: 0x0c59d8 | Size: 256 bytes
// Hàm FDE #1090 | Địa chỉ PC: 0x07a46c | Địa chỉ FDE: 0x0c59d8 | Kích thước: 256 bytes
//   0x07a46c: D10503FF  sub      sp, sp, #0x140
//   0x07a470: A9105FFC  stp      x28, x23, [sp, #0x100]
//   0x07a474: A91157F6  stp      x22, x21, [sp, #0x110]
//   0x07a478: A9124FF4  stp      x20, x19, [sp, #0x120]
static inline uint64_t fde_func_1090_0x07a46c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07a46cULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xa9105ffcULL) ^ 0x0c59d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1091 | PC: 0x07abb8 | FDE: 0x0c5560 | Size: 28 bytes
// Hàm FDE #1091 | Địa chỉ PC: 0x07abb8 | Địa chỉ FDE: 0x0c5560 | Kích thước: 28 bytes
//   0x07abb8: F9400428  ldr      x8, [x1, #8]
//   0x07abbc: D00001C9  adrp     x9, #0xb4000
//   0x07abc0: 911E2129  add      x9, x9, #0x788
//   0x07abc4: 9100200A  add      x10, x0, #8
static inline uint64_t fde_func_1091_0x07abb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07abb8ULL ^ (static_cast<uint64_t>(0xf9400428ULL) << 13);
    acc = (acc + a1 + 0xd00001c9ULL) ^ 0x0c5560ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1092 | PC: 0x07abd4 | FDE: 0x0c5578 | Size: 12 bytes
// Hàm FDE #1092 | Địa chỉ PC: 0x07abd4 | Địa chỉ FDE: 0x0c5578 | Kích thước: 12 bytes
//   0x07abd4: 90000380  adrp     x0, #0xea000
//   0x07abd8: 91298000  add      x0, x0, #0xa60
//   0x07abdc: D65F03C0  ret      
static inline uint64_t fde_func_1092_0x07abd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07abd4ULL ^ (static_cast<uint64_t>(0x90000380ULL) << 13);
    acc = (acc + a1 + 0x91298000ULL) ^ 0x0c5578ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1093 | PC: 0x07abe0 | FDE: 0x0c5590 | Size: 144 bytes
// Hàm FDE #1093 | Địa chỉ PC: 0x07abe0 | Địa chỉ FDE: 0x0c5590 | Kích thước: 144 bytes
//   0x07abe0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07abe4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07abe8: 910043FD  add      x29, sp, #0x10
//   0x07abec: 39418008  ldrb     w8, [x0, #0x60]
static inline uint64_t fde_func_1093_0x07abe0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07abe0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5590ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1094 | PC: 0x07ac70 | FDE: 0x0c5a48 | Size: 116 bytes
// Hàm FDE #1094 | Địa chỉ PC: 0x07ac70 | Địa chỉ FDE: 0x0c5a48 | Kích thước: 116 bytes
//   0x07ac70: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07ac74: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07ac78: 910043FD  add      x29, sp, #0x10
//   0x07ac7c: D0000388  adrp     x8, #0xec000
static inline uint64_t fde_func_1094_0x07ac70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ac70ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5a48ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1095 | PC: 0x07ace4 | FDE: 0x0c5a70 | Size: 256 bytes
// Hàm FDE #1095 | Địa chỉ PC: 0x07ace4 | Địa chỉ FDE: 0x0c5a70 | Kích thước: 256 bytes
//   0x07ace4: D101C3FF  sub      sp, sp, #0x70
//   0x07ace8: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x07acec: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x07acf0: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1095_0x07ace4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ace4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x0c5a70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1096 | PC: 0x07ae28 | FDE: 0x0c5aa0 | Size: 256 bytes
// Hàm FDE #1096 | Địa chỉ PC: 0x07ae28 | Địa chỉ FDE: 0x0c5aa0 | Kích thước: 256 bytes
//   0x07ae28: D10403FF  sub      sp, sp, #0x100
//   0x07ae2c: A90A6FFC  stp      x28, x27, [sp, #0xa0]
//   0x07ae30: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x07ae34: A90C5FF8  stp      x24, x23, [sp, #0xc0]
static inline uint64_t fde_func_1096_0x07ae28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ae28ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90a6ffcULL) ^ 0x0c5aa0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1097 | PC: 0x07b1a4 | FDE: 0x0c5ad8 | Size: 224 bytes
// Hàm FDE #1097 | Địa chỉ PC: 0x07b1a4 | Địa chỉ FDE: 0x0c5ad8 | Kích thước: 224 bytes
//   0x07b1a4: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x07b1a8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07b1ac: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07b1b0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1097_0x07b1a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b1a4ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c5ad8ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #1098 | PC: 0x07b284 | FDE: 0x0c5a08 | Size: 144 bytes
// Hàm FDE #1098 | Địa chỉ PC: 0x07b284 | Địa chỉ FDE: 0x0c5a08 | Kích thước: 144 bytes
//   0x07b284: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x07b288: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07b28c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07b290: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1098_0x07b284(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b284ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c5a08ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1099 | PC: 0x07b314 | FDE: 0x0c5b08 | Size: 256 bytes
// Hàm FDE #1099 | Địa chỉ PC: 0x07b314 | Địa chỉ FDE: 0x0c5b08 | Kích thước: 256 bytes
//   0x07b314: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x07b318: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07b31c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07b320: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1099_0x07b314(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b314ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c5b08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1100 | PC: 0x07b428 | FDE: 0x0c5a28 | Size: 112 bytes
// Hàm FDE #1100 | Địa chỉ PC: 0x07b428 | Địa chỉ FDE: 0x0c5a28 | Kích thước: 112 bytes
//   0x07b428: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07b42c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07b430: 910043FD  add      x29, sp, #0x10
//   0x07b434: 91002014  add      x20, x0, #8
static inline uint64_t fde_func_1100_0x07b428(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b428ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5a28ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// Shard 3 Dispatcher / Bộ điều phối phân mảnh 3
uint64_t execute_fde_shard_3(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 734: return fde_func_0734_0x05c138(a0, a1);
        case 735: return fde_func_0735_0x05c34c(a0, a1);
        case 736: return fde_func_0736_0x05c5a0(a0, a1);
        case 737: return fde_func_0737_0x05c66c(a0, a1);
        case 738: return fde_func_0738_0x05c778(a0, a1);
        case 739: return fde_func_0739_0x05c8d0(a0, a1);
        case 740: return fde_func_0740_0x05ca28(a0, a1);
        case 741: return fde_func_0741_0x05cbbc(a0, a1);
        case 742: return fde_func_0742_0x05cddc(a0, a1);
        case 743: return fde_func_0743_0x05cea0(a0, a1);
        case 744: return fde_func_0744_0x05d1a8(a0, a1);
        case 745: return fde_func_0745_0x05d478(a0, a1);
        case 746: return fde_func_0746_0x05d5f4(a0, a1);
        case 747: return fde_func_0747_0x05da30(a0, a1);
        case 748: return fde_func_0748_0x05e1cc(a0, a1);
        case 749: return fde_func_0749_0x05e428(a0, a1);
        case 750: return fde_func_0750_0x05e624(a0, a1);
        case 751: return fde_func_0751_0x05e7e0(a0, a1);
        case 752: return fde_func_0752_0x05e968(a0, a1);
        case 753: return fde_func_0753_0x05eb24(a0, a1);
        case 754: return fde_func_0754_0x05ef6c(a0, a1);
        case 755: return fde_func_0755_0x05f1d0(a0, a1);
        case 756: return fde_func_0756_0x05f3cc(a0, a1);
        case 757: return fde_func_0757_0x05f6c0(a0, a1);
        case 758: return fde_func_0758_0x05fc0c(a0, a1);
        case 759: return fde_func_0759_0x060480(a0, a1);
        case 760: return fde_func_0760_0x060abc(a0, a1);
        case 761: return fde_func_0761_0x060bd8(a0, a1);
        case 762: return fde_func_0762_0x061294(a0, a1);
        case 763: return fde_func_0763_0x061338(a0, a1);
        case 764: return fde_func_0764_0x061860(a0, a1);
        case 765: return fde_func_0765_0x06193c(a0, a1);
        case 766: return fde_func_0766_0x0619cc(a0, a1);
        case 767: return fde_func_0767_0x061ab8(a0, a1);
        case 768: return fde_func_0768_0x061ac4(a0, a1);
        case 769: return fde_func_0769_0x061ac8(a0, a1);
        case 770: return fde_func_0770_0x061b50(a0, a1);
        case 771: return fde_func_0771_0x061b54(a0, a1);
        case 772: return fde_func_0772_0x061bbc(a0, a1);
        case 773: return fde_func_0773_0x061c88(a0, a1);
        case 774: return fde_func_0774_0x061c94(a0, a1);
        case 775: return fde_func_0775_0x061c98(a0, a1);
        case 776: return fde_func_0776_0x061d3c(a0, a1);
        case 777: return fde_func_0777_0x061e3c(a0, a1);
        case 778: return fde_func_0778_0x061e48(a0, a1);
        case 779: return fde_func_0779_0x061e4c(a0, a1);
        case 780: return fde_func_0780_0x061e80(a0, a1);
        case 781: return fde_func_0781_0x061f6c(a0, a1);
        case 782: return fde_func_0782_0x0620b8(a0, a1);
        case 783: return fde_func_0783_0x062154(a0, a1);
        case 784: return fde_func_0784_0x0622d8(a0, a1);
        case 785: return fde_func_0785_0x062510(a0, a1);
        case 786: return fde_func_0786_0x0626d4(a0, a1);
        case 787: return fde_func_0787_0x06276c(a0, a1);
        case 788: return fde_func_0788_0x06287c(a0, a1);
        case 789: return fde_func_0789_0x062994(a0, a1);
        case 790: return fde_func_0790_0x062aa8(a0, a1);
        case 791: return fde_func_0791_0x062b8c(a0, a1);
        case 792: return fde_func_0792_0x062d08(a0, a1);
        case 793: return fde_func_0793_0x06302c(a0, a1);
        case 794: return fde_func_0794_0x063140(a0, a1);
        case 795: return fde_func_0795_0x063328(a0, a1);
        case 796: return fde_func_0796_0x063470(a0, a1);
        case 797: return fde_func_0797_0x063524(a0, a1);
        case 798: return fde_func_0798_0x06372c(a0, a1);
        case 799: return fde_func_0799_0x063840(a0, a1);
        case 800: return fde_func_0800_0x06390c(a0, a1);
        case 801: return fde_func_0801_0x0639e0(a0, a1);
        case 802: return fde_func_0802_0x063a70(a0, a1);
        case 803: return fde_func_0803_0x063b5c(a0, a1);
        case 804: return fde_func_0804_0x063b68(a0, a1);
        case 805: return fde_func_0805_0x063b6c(a0, a1);
        case 806: return fde_func_0806_0x063b9c(a0, a1);
        case 807: return fde_func_0807_0x063bd4(a0, a1);
        case 808: return fde_func_0808_0x063bdc(a0, a1);
        case 809: return fde_func_0809_0x063be0(a0, a1);
        case 810: return fde_func_0810_0x063f44(a0, a1);
        case 811: return fde_func_0811_0x063fe0(a0, a1);
        case 812: return fde_func_0812_0x06423c(a0, a1);
        case 813: return fde_func_0813_0x064370(a0, a1);
        case 814: return fde_func_0814_0x064378(a0, a1);
        case 815: return fde_func_0815_0x064cb8(a0, a1);
        case 816: return fde_func_0816_0x064ea8(a0, a1);
        case 817: return fde_func_0817_0x064f8c(a0, a1);
        case 818: return fde_func_0818_0x064f9c(a0, a1);
        case 819: return fde_func_0819_0x065140(a0, a1);
        case 820: return fde_func_0820_0x0651ac(a0, a1);
        case 821: return fde_func_0821_0x065280(a0, a1);
        case 822: return fde_func_0822_0x06555c(a0, a1);
        case 823: return fde_func_0823_0x06558c(a0, a1);
        case 824: return fde_func_0824_0x0655c4(a0, a1);
        case 825: return fde_func_0825_0x0655cc(a0, a1);
        case 826: return fde_func_0826_0x0655d0(a0, a1);
        case 827: return fde_func_0827_0x0658dc(a0, a1);
        case 828: return fde_func_0828_0x0659f0(a0, a1);
        case 829: return fde_func_0829_0x065bd8(a0, a1);
        case 830: return fde_func_0830_0x065cb4(a0, a1);
        case 831: return fde_func_0831_0x065d58(a0, a1);
        case 832: return fde_func_0832_0x065d60(a0, a1);
        case 833: return fde_func_0833_0x065d64(a0, a1);
        case 834: return fde_func_0834_0x065d74(a0, a1);
        case 835: return fde_func_0835_0x065f18(a0, a1);
        case 836: return fde_func_0836_0x065f64(a0, a1);
        case 837: return fde_func_0837_0x066018(a0, a1);
        case 838: return fde_func_0838_0x0660bc(a0, a1);
        case 839: return fde_func_0839_0x0660c4(a0, a1);
        case 840: return fde_func_0840_0x0661d0(a0, a1);
        case 841: return fde_func_0841_0x0661e0(a0, a1);
        case 842: return fde_func_0842_0x066384(a0, a1);
        case 843: return fde_func_0843_0x066404(a0, a1);
        case 844: return fde_func_0844_0x0664ec(a0, a1);
        case 845: return fde_func_0845_0x066550(a0, a1);
        case 846: return fde_func_0846_0x0665bc(a0, a1);
        case 847: return fde_func_0847_0x066618(a0, a1);
        case 848: return fde_func_0848_0x06661c(a0, a1);
        case 849: return fde_func_0849_0x0666c0(a0, a1);
        case 850: return fde_func_0850_0x0666c8(a0, a1);
        case 851: return fde_func_0851_0x067364(a0, a1);
        case 852: return fde_func_0852_0x06740c(a0, a1);
        case 853: return fde_func_0853_0x06821c(a0, a1);
        case 854: return fde_func_0854_0x0683dc(a0, a1);
        case 855: return fde_func_0855_0x0685c8(a0, a1);
        case 856: return fde_func_0856_0x0686a8(a0, a1);
        case 857: return fde_func_0857_0x068714(a0, a1);
        case 858: return fde_func_0858_0x0687e8(a0, a1);
        case 859: return fde_func_0859_0x068a7c(a0, a1);
        case 860: return fde_func_0860_0x068d48(a0, a1);
        case 861: return fde_func_0861_0x068dec(a0, a1);
        case 862: return fde_func_0862_0x068e98(a0, a1);
        case 863: return fde_func_0863_0x06912c(a0, a1);
        case 864: return fde_func_0864_0x0693a0(a0, a1);
        case 865: return fde_func_0865_0x069510(a0, a1);
        case 866: return fde_func_0866_0x06984c(a0, a1);
        case 867: return fde_func_0867_0x06992c(a0, a1);
        case 868: return fde_func_0868_0x0699a8(a0, a1);
        case 869: return fde_func_0869_0x069ad8(a0, a1);
        case 870: return fde_func_0870_0x069ce4(a0, a1);
        case 871: return fde_func_0871_0x069e74(a0, a1);
        case 872: return fde_func_0872_0x06a0d4(a0, a1);
        case 873: return fde_func_0873_0x06a1b4(a0, a1);
        case 874: return fde_func_0874_0x06a1bc(a0, a1);
        case 875: return fde_func_0875_0x06ab3c(a0, a1);
        case 876: return fde_func_0876_0x06ab9c(a0, a1);
        case 877: return fde_func_0877_0x06ae74(a0, a1);
        case 878: return fde_func_0878_0x06b088(a0, a1);
        case 879: return fde_func_0879_0x06b38c(a0, a1);
        case 880: return fde_func_0880_0x06b780(a0, a1);
        case 881: return fde_func_0881_0x06b884(a0, a1);
        case 882: return fde_func_0882_0x06b9c8(a0, a1);
        case 883: return fde_func_0883_0x06bb04(a0, a1);
        case 884: return fde_func_0884_0x06bd18(a0, a1);
        case 885: return fde_func_0885_0x06be58(a0, a1);
        case 886: return fde_func_0886_0x06bf98(a0, a1);
        case 887: return fde_func_0887_0x06c0d8(a0, a1);
        case 888: return fde_func_0888_0x06c218(a0, a1);
        case 889: return fde_func_0889_0x06c358(a0, a1);
        case 890: return fde_func_0890_0x06c410(a0, a1);
        case 891: return fde_func_0891_0x06c4b4(a0, a1);
        case 892: return fde_func_0892_0x06c6b0(a0, a1);
        case 893: return fde_func_0893_0x06c814(a0, a1);
        case 894: return fde_func_0894_0x06c8b4(a0, a1);
        case 895: return fde_func_0895_0x06c94c(a0, a1);
        case 896: return fde_func_0896_0x06ca28(a0, a1);
        case 897: return fde_func_0897_0x06cae4(a0, a1);
        case 898: return fde_func_0898_0x06cb78(a0, a1);
        case 899: return fde_func_0899_0x06cc04(a0, a1);
        case 900: return fde_func_0900_0x06d5bc(a0, a1);
        case 901: return fde_func_0901_0x06d5d8(a0, a1);
        case 902: return fde_func_0902_0x06d5e4(a0, a1);
        case 903: return fde_func_0903_0x06d6b0(a0, a1);
        case 904: return fde_func_0904_0x06d980(a0, a1);
        case 905: return fde_func_0905_0x06db14(a0, a1);
        case 906: return fde_func_0906_0x06dbac(a0, a1);
        case 907: return fde_func_0907_0x06dd58(a0, a1);
        case 908: return fde_func_0908_0x06df94(a0, a1);
        case 909: return fde_func_0909_0x06dfb8(a0, a1);
        case 910: return fde_func_0910_0x06e014(a0, a1);
        case 911: return fde_func_0911_0x06e030(a0, a1);
        case 912: return fde_func_0912_0x06e034(a0, a1);
        case 913: return fde_func_0913_0x06e044(a0, a1);
        case 914: return fde_func_0914_0x06e074(a0, a1);
        case 915: return fde_func_0915_0x06e0d0(a0, a1);
        case 916: return fde_func_0916_0x06e0f8(a0, a1);
        case 917: return fde_func_0917_0x06e100(a0, a1);
        case 918: return fde_func_0918_0x06e128(a0, a1);
        case 919: return fde_func_0919_0x06e504(a0, a1);
        case 920: return fde_func_0920_0x06e520(a0, a1);
        case 921: return fde_func_0921_0x06e52c(a0, a1);
        case 922: return fde_func_0922_0x06e728(a0, a1);
        case 923: return fde_func_0923_0x06e748(a0, a1);
        case 924: return fde_func_0924_0x06e784(a0, a1);
        case 925: return fde_func_0925_0x06e7e0(a0, a1);
        case 926: return fde_func_0926_0x06e808(a0, a1);
        case 927: return fde_func_0927_0x06e81c(a0, a1);
        case 928: return fde_func_0928_0x06e84c(a0, a1);
        case 929: return fde_func_0929_0x06e8d4(a0, a1);
        case 930: return fde_func_0930_0x06e8f0(a0, a1);
        case 931: return fde_func_0931_0x06e8fc(a0, a1);
        case 932: return fde_func_0932_0x06e99c(a0, a1);
        case 933: return fde_func_0933_0x06ea34(a0, a1);
        case 934: return fde_func_0934_0x06eac4(a0, a1);
        case 935: return fde_func_0935_0x06eb38(a0, a1);
        case 936: return fde_func_0936_0x06ebcc(a0, a1);
        case 937: return fde_func_0937_0x06ec58(a0, a1);
        case 938: return fde_func_0938_0x06ef04(a0, a1);
        case 939: return fde_func_0939_0x06ef20(a0, a1);
        case 940: return fde_func_0940_0x06ef2c(a0, a1);
        case 941: return fde_func_0941_0x06ef78(a0, a1);
        case 942: return fde_func_0942_0x06efcc(a0, a1);
        case 943: return fde_func_0943_0x06efe0(a0, a1);
        case 944: return fde_func_0944_0x06f060(a0, a1);
        case 945: return fde_func_0945_0x06f0bc(a0, a1);
        case 946: return fde_func_0946_0x06f0dc(a0, a1);
        case 947: return fde_func_0947_0x06f118(a0, a1);
        case 948: return fde_func_0948_0x06f17c(a0, a1);
        case 949: return fde_func_0949_0x06f1c4(a0, a1);
        case 950: return fde_func_0950_0x06f1d8(a0, a1);
        case 951: return fde_func_0951_0x06f208(a0, a1);
        case 952: return fde_func_0952_0x06f688(a0, a1);
        case 953: return fde_func_0953_0x06f6a4(a0, a1);
        case 954: return fde_func_0954_0x06f6b0(a0, a1);
        case 955: return fde_func_0955_0x06f774(a0, a1);
        case 956: return fde_func_0956_0x06f85c(a0, a1);
        case 957: return fde_func_0957_0x06fad8(a0, a1);
        case 958: return fde_func_0958_0x06fe08(a0, a1);
        case 959: return fde_func_0959_0x06ff3c(a0, a1);
        case 960: return fde_func_0960_0x0700ac(a0, a1);
        case 961: return fde_func_0961_0x0701b0(a0, a1);
        case 962: return fde_func_0962_0x0702f0(a0, a1);
        case 963: return fde_func_0963_0x070448(a0, a1);
        case 964: return fde_func_0964_0x070608(a0, a1);
        case 965: return fde_func_0965_0x07079c(a0, a1);
        case 966: return fde_func_0966_0x070950(a0, a1);
        case 967: return fde_func_0967_0x070df8(a0, a1);
        case 968: return fde_func_0968_0x070f14(a0, a1);
        case 969: return fde_func_0969_0x0711a0(a0, a1);
        case 970: return fde_func_0970_0x071238(a0, a1);
        case 971: return fde_func_0971_0x07136c(a0, a1);
        case 972: return fde_func_0972_0x071518(a0, a1);
        case 973: return fde_func_0973_0x071690(a0, a1);
        case 974: return fde_func_0974_0x071844(a0, a1);
        case 975: return fde_func_0975_0x071848(a0, a1);
        case 976: return fde_func_0976_0x0718bc(a0, a1);
        case 977: return fde_func_0977_0x0718f4(a0, a1);
        case 978: return fde_func_0978_0x07194c(a0, a1);
        case 979: return fde_func_0979_0x071960(a0, a1);
        case 980: return fde_func_0980_0x071b44(a0, a1);
        case 981: return fde_func_0981_0x071c00(a0, a1);
        case 982: return fde_func_0982_0x0720f0(a0, a1);
        case 983: return fde_func_0983_0x072298(a0, a1);
        case 984: return fde_func_0984_0x07258c(a0, a1);
        case 985: return fde_func_0985_0x0726c4(a0, a1);
        case 986: return fde_func_0986_0x0726fc(a0, a1);
        case 987: return fde_func_0987_0x07297c(a0, a1);
        case 988: return fde_func_0988_0x072bc4(a0, a1);
        case 989: return fde_func_0989_0x072dec(a0, a1);
        case 990: return fde_func_0990_0x073520(a0, a1);
        case 991: return fde_func_0991_0x073624(a0, a1);
        case 992: return fde_func_0992_0x0736a0(a0, a1);
        case 993: return fde_func_0993_0x073774(a0, a1);
        case 994: return fde_func_0994_0x073798(a0, a1);
        case 995: return fde_func_0995_0x0737d0(a0, a1);
        case 996: return fde_func_0996_0x0737ec(a0, a1);
        case 997: return fde_func_0997_0x0737f0(a0, a1);
        case 998: return fde_func_0998_0x073820(a0, a1);
        case 999: return fde_func_0999_0x073858(a0, a1);
        case 1000: return fde_func_1000_0x073860(a0, a1);
        case 1001: return fde_func_1001_0x073864(a0, a1);
        case 1002: return fde_func_1002_0x073b8c(a0, a1);
        case 1003: return fde_func_1003_0x073c70(a0, a1);
        case 1004: return fde_func_1004_0x073ee0(a0, a1);
        case 1005: return fde_func_1005_0x073ffc(a0, a1);
        case 1006: return fde_func_1006_0x0741c8(a0, a1);
        case 1007: return fde_func_1007_0x0742a8(a0, a1);
        case 1008: return fde_func_1008_0x0743f4(a0, a1);
        case 1009: return fde_func_1009_0x0745c0(a0, a1);
        case 1010: return fde_func_1010_0x07470c(a0, a1);
        case 1011: return fde_func_1011_0x074a90(a0, a1);
        case 1012: return fde_func_1012_0x074b74(a0, a1);
        case 1013: return fde_func_1013_0x074de4(a0, a1);
        case 1014: return fde_func_1014_0x074f64(a0, a1);
        case 1015: return fde_func_1015_0x075008(a0, a1);
        case 1016: return fde_func_1016_0x075018(a0, a1);
        case 1017: return fde_func_1017_0x075098(a0, a1);
        case 1018: return fde_func_1018_0x0753e8(a0, a1);
        case 1019: return fde_func_1019_0x07573c(a0, a1);
        case 1020: return fde_func_1020_0x0757e0(a0, a1);
        case 1021: return fde_func_1021_0x075844(a0, a1);
        case 1022: return fde_func_1022_0x0758b0(a0, a1);
        case 1023: return fde_func_1023_0x0758bc(a0, a1);
        case 1024: return fde_func_1024_0x0758c0(a0, a1);
        case 1025: return fde_func_1025_0x0759d8(a0, a1);
        case 1026: return fde_func_1026_0x075a18(a0, a1);
        case 1027: return fde_func_1027_0x075a70(a0, a1);
        case 1028: return fde_func_1028_0x075b84(a0, a1);
        case 1029: return fde_func_1029_0x075dc8(a0, a1);
        case 1030: return fde_func_1030_0x076134(a0, a1);
        case 1031: return fde_func_1031_0x076214(a0, a1);
        case 1032: return fde_func_1032_0x076290(a0, a1);
        case 1033: return fde_func_1033_0x0762a0(a0, a1);
        case 1034: return fde_func_1034_0x07646c(a0, a1);
        case 1035: return fde_func_1035_0x076854(a0, a1);
        case 1036: return fde_func_1036_0x0768b4(a0, a1);
        case 1037: return fde_func_1037_0x076cac(a0, a1);
        case 1038: return fde_func_1038_0x076cbc(a0, a1);
        case 1039: return fde_func_1039_0x076d24(a0, a1);
        case 1040: return fde_func_1040_0x07702c(a0, a1);
        case 1041: return fde_func_1041_0x077210(a0, a1);
        case 1042: return fde_func_1042_0x0773e4(a0, a1);
        case 1043: return fde_func_1043_0x0774e0(a0, a1);
        case 1044: return fde_func_1044_0x077598(a0, a1);
        case 1045: return fde_func_1045_0x077604(a0, a1);
        case 1046: return fde_func_1046_0x077670(a0, a1);
        case 1047: return fde_func_1047_0x0776c4(a0, a1);
        case 1048: return fde_func_1048_0x0776e0(a0, a1);
        case 1049: return fde_func_1049_0x077740(a0, a1);
        case 1050: return fde_func_1050_0x0777a0(a0, a1);
        case 1051: return fde_func_1051_0x077ba0(a0, a1);
        case 1052: return fde_func_1052_0x077bbc(a0, a1);
        case 1053: return fde_func_1053_0x077bc8(a0, a1);
        case 1054: return fde_func_1054_0x077c7c(a0, a1);
        case 1055: return fde_func_1055_0x077d20(a0, a1);
        case 1056: return fde_func_1056_0x077d8c(a0, a1);
        case 1057: return fde_func_1057_0x077df8(a0, a1);
        case 1058: return fde_func_1058_0x077e4c(a0, a1);
        case 1059: return fde_func_1059_0x077e68(a0, a1);
        case 1060: return fde_func_1060_0x077ec8(a0, a1);
        case 1061: return fde_func_1061_0x077f28(a0, a1);
        case 1062: return fde_func_1062_0x078330(a0, a1);
        case 1063: return fde_func_1063_0x07834c(a0, a1);
        case 1064: return fde_func_1064_0x078358(a0, a1);
        case 1065: return fde_func_1065_0x078414(a0, a1);
        case 1066: return fde_func_1066_0x078490(a0, a1);
        case 1067: return fde_func_1067_0x07850c(a0, a1);
        case 1068: return fde_func_1068_0x078594(a0, a1);
        case 1069: return fde_func_1069_0x0785fc(a0, a1);
        case 1070: return fde_func_1070_0x07866c(a0, a1);
        case 1071: return fde_func_1071_0x0786dc(a0, a1);
        case 1072: return fde_func_1072_0x079354(a0, a1);
        case 1073: return fde_func_1073_0x079370(a0, a1);
        case 1074: return fde_func_1074_0x07937c(a0, a1);
        case 1075: return fde_func_1075_0x079500(a0, a1);
        case 1076: return fde_func_1076_0x07957c(a0, a1);
        case 1077: return fde_func_1077_0x0795f8(a0, a1);
        case 1078: return fde_func_1078_0x079678(a0, a1);
        case 1079: return fde_func_1079_0x0796d8(a0, a1);
        case 1080: return fde_func_1080_0x079748(a0, a1);
        case 1081: return fde_func_1081_0x0797b8(a0, a1);
        case 1082: return fde_func_1082_0x07a1d0(a0, a1);
        case 1083: return fde_func_1083_0x07a1ec(a0, a1);
        case 1084: return fde_func_1084_0x07a1f8(a0, a1);
        case 1085: return fde_func_1085_0x07a294(a0, a1);
        case 1086: return fde_func_1086_0x07a330(a0, a1);
        case 1087: return fde_func_1087_0x07a3c0(a0, a1);
        case 1088: return fde_func_1088_0x07a43c(a0, a1);
        case 1089: return fde_func_1089_0x07a444(a0, a1);
        case 1090: return fde_func_1090_0x07a46c(a0, a1);
        case 1091: return fde_func_1091_0x07abb8(a0, a1);
        case 1092: return fde_func_1092_0x07abd4(a0, a1);
        case 1093: return fde_func_1093_0x07abe0(a0, a1);
        case 1094: return fde_func_1094_0x07ac70(a0, a1);
        case 1095: return fde_func_1095_0x07ace4(a0, a1);
        case 1096: return fde_func_1096_0x07ae28(a0, a1);
        case 1097: return fde_func_1097_0x07b1a4(a0, a1);
        case 1098: return fde_func_1098_0x07b284(a0, a1);
        case 1099: return fde_func_1099_0x07b314(a0, a1);
        case 1100: return fde_func_1100_0x07b428(a0, a1);
        default: return 0ULL;
    }
}

} // namespace nuro