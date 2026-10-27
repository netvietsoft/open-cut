// ============================================================================
// Clean-Room C++17 AArch64 FDE Shard 2/5 for libnuro.so
// Phân mảnh FDE AArch64 C++17 sạch 2/5 cho libnuro.so
// Covers FDE indices [367 .. 733] out of 1,835 total FDEs (.eh_frame_hdr @ 0x0b8c58)
// Bao phủ chỉ số FDE [367 .. 733] trên tổng số 1,835 FDE (.eh_frame_hdr @ 0x0b8c58)
// ============================================================================
#include "nuro_core.h"

namespace nuro {

// FDE #0367 | PC: 0x029b64 | FDE: 0x0be5b0 | Size: 136 bytes
// Hàm FDE #0367 | Địa chỉ PC: 0x029b64 | Địa chỉ FDE: 0x0be5b0 | Kích thước: 136 bytes
//   0x029b64: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x029b68: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x029b6c: 910043FD  add      x29, sp, #0x10
//   0x029b70: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0367_0x029b64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x029b64ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0be5b0ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #0368 | PC: 0x029bec | FDE: 0x0be5d0 | Size: 80 bytes
// Hàm FDE #0368 | Địa chỉ PC: 0x029bec | Địa chỉ FDE: 0x0be5d0 | Kích thước: 80 bytes
//   0x029bec: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x029bf0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x029bf4: 910043FD  add      x29, sp, #0x10
//   0x029bf8: D0000609  adrp     x9, #0xeb000
static inline uint64_t fde_func_0368_0x029bec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x029becULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0be5d0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0369 | PC: 0x029c3c | FDE: 0x0be5f0 | Size: 88 bytes
// Hàm FDE #0369 | Địa chỉ PC: 0x029c3c | Địa chỉ FDE: 0x0be5f0 | Kích thước: 88 bytes
//   0x029c3c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x029c40: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x029c44: 910043FD  add      x29, sp, #0x10
//   0x029c48: D0000609  adrp     x9, #0xeb000
static inline uint64_t fde_func_0369_0x029c3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x029c3cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0be5f0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0370 | PC: 0x029c94 | FDE: 0x0be610 | Size: 256 bytes
// Hàm FDE #0370 | Địa chỉ PC: 0x029c94 | Địa chỉ FDE: 0x0be610 | Kích thước: 256 bytes
//   0x029c94: F9402C08  ldr      x8, [x0, #0x58]
//   0x029c98: F9401809  ldr      x9, [x0, #0x30]
//   0x029c9c: EB09011F  cmp      x8, x9
//   0x029ca0: 54000062  b.hs     #0x29cac
static inline uint64_t fde_func_0370_0x029c94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x029c94ULL ^ (static_cast<uint64_t>(0xf9402c08ULL) << 13);
    acc = (acc + a1 + 0xf9401809ULL) ^ 0x0be610ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0371 | PC: 0x029d94 | FDE: 0x0be628 | Size: 20 bytes
// Hàm FDE #0371 | Địa chỉ PC: 0x029d94 | Địa chỉ FDE: 0x0be628 | Kích thước: 20 bytes
//   0x029d94: F9400008  ldr      x8, [x0]
//   0x029d98: AA0203E1  mov      x1, x2
//   0x029d9c: 2A1F03E2  mov      w2, wzr
//   0x029da0: F9401104  ldr      x4, [x8, #0x20]
static inline uint64_t fde_func_0371_0x029d94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x029d94ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xaa0203e1ULL) ^ 0x0be628ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0372 | PC: 0x029da8 | FDE: 0x0be640 | Size: 80 bytes
// Hàm FDE #0372 | Địa chỉ PC: 0x029da8 | Địa chỉ FDE: 0x0be640 | Kích thước: 80 bytes
//   0x029da8: F9402C08  ldr      x8, [x0, #0x58]
//   0x029dac: F9401809  ldr      x9, [x0, #0x30]
//   0x029db0: EB09011F  cmp      x8, x9
//   0x029db4: 54000062  b.hs     #0x29dc0
static inline uint64_t fde_func_0372_0x029da8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x029da8ULL ^ (static_cast<uint64_t>(0xf9402c08ULL) << 13);
    acc = (acc + a1 + 0xf9401809ULL) ^ 0x0be640ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0373 | PC: 0x029df8 | FDE: 0x0be658 | Size: 112 bytes
// Hàm FDE #0373 | Địa chỉ PC: 0x029df8 | Địa chỉ FDE: 0x0be658 | Kích thước: 112 bytes
//   0x029df8: F9402C09  ldr      x9, [x0, #0x58]
//   0x029dfc: F940180A  ldr      x10, [x0, #0x30]
//   0x029e00: AA0003E8  mov      x8, x0
//   0x029e04: 2A0103E0  mov      w0, w1
static inline uint64_t fde_func_0373_0x029df8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x029df8ULL ^ (static_cast<uint64_t>(0xf9402c09ULL) << 13);
    acc = (acc + a1 + 0xf940180aULL) ^ 0x0be658ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0374 | PC: 0x029e68 | FDE: 0x0be9f8 | Size: 256 bytes
// Hàm FDE #0374 | Địa chỉ PC: 0x029e68 | Địa chỉ FDE: 0x0be9f8 | Kích thước: 256 bytes
//   0x029e68: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x029e6c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x029e70: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x029e74: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0374_0x029e68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x029e68ULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0be9f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0375 | PC: 0x02a09c | FDE: 0x0be670 | Size: 204 bytes
// Hàm FDE #0375 | Địa chỉ PC: 0x02a09c | Địa chỉ FDE: 0x0be670 | Kích thước: 204 bytes
//   0x02a09c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x02a0a0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x02a0a4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x02a0a8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0375_0x02a09c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02a09cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0be670ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #0376 | PC: 0x02a168 | FDE: 0x0be698 | Size: 72 bytes
// Hàm FDE #0376 | Địa chỉ PC: 0x02a168 | Địa chỉ FDE: 0x0be698 | Kích thước: 72 bytes
//   0x02a168: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x02a16c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02a170: 910043FD  add      x29, sp, #0x10
//   0x02a174: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0376_0x02a168(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02a168ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0be698ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0377 | PC: 0x02a1b0 | FDE: 0x0be6b8 | Size: 72 bytes
// Hàm FDE #0377 | Địa chỉ PC: 0x02a1b0 | Địa chỉ FDE: 0x0be6b8 | Kích thước: 72 bytes
//   0x02a1b0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x02a1b4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02a1b8: 910043FD  add      x29, sp, #0x10
//   0x02a1bc: B0000608  adrp     x8, #0xeb000
static inline uint64_t fde_func_0377_0x02a1b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02a1b0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0be6b8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0378 | PC: 0x02a1f8 | FDE: 0x0be6d8 | Size: 84 bytes
// Hàm FDE #0378 | Địa chỉ PC: 0x02a1f8 | Địa chỉ FDE: 0x0be6d8 | Kích thước: 84 bytes
//   0x02a1f8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x02a1fc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02a200: 910043FD  add      x29, sp, #0x10
//   0x02a204: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0378_0x02a1f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02a1f8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0be6d8ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0379 | PC: 0x02a24c | FDE: 0x0be6f8 | Size: 256 bytes
// Hàm FDE #0379 | Địa chỉ PC: 0x02a24c | Địa chỉ FDE: 0x0be6f8 | Kích thước: 256 bytes
//   0x02a24c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x02a250: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x02a254: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x02a258: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0379_0x02a24c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02a24cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0be6f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0380 | PC: 0x02a39c | FDE: 0x0be718 | Size: 20 bytes
// Hàm FDE #0380 | Địa chỉ PC: 0x02a39c | Địa chỉ FDE: 0x0be718 | Kích thước: 20 bytes
//   0x02a39c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x02a3a0: 910003FD  mov      x29, sp
//   0x02a3a4: D0000400  adrp     x0, #0xac000
//   0x02a3a8: 913A5000  add      x0, x0, #0xe94
static inline uint64_t fde_func_0380_0x02a39c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02a39cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0be718ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0381 | PC: 0x02a3b0 | FDE: 0x0bea30 | Size: 80 bytes
// Hàm FDE #0381 | Địa chỉ PC: 0x02a3b0 | Địa chỉ FDE: 0x0bea30 | Kích thước: 80 bytes
//   0x02a3b0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x02a3b4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02a3b8: 910043FD  add      x29, sp, #0x10
//   0x02a3bc: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0381_0x02a3b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02a3b0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bea30ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0382 | PC: 0x02a400 | FDE: 0x0be738 | Size: 48 bytes
// Hàm FDE #0382 | Địa chỉ PC: 0x02a400 | Địa chỉ FDE: 0x0be738 | Kích thước: 48 bytes
//   0x02a400: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x02a404: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02a408: 910043FD  add      x29, sp, #0x10
//   0x02a40c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0382_0x02a400(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02a400ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0be738ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0383 | PC: 0x02a430 | FDE: 0x0be758 | Size: 256 bytes
// Hàm FDE #0383 | Địa chỉ PC: 0x02a430 | Địa chỉ FDE: 0x0be758 | Kích thước: 256 bytes
//   0x02a430: D10183FF  sub      sp, sp, #0x60
//   0x02a434: F90013F7  str      x23, [sp, #0x20]
//   0x02a438: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x02a43c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0383_0x02a430(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02a430ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x0be758ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0384 | PC: 0x02a5c0 | FDE: 0x0be780 | Size: 256 bytes
// Hàm FDE #0384 | Địa chỉ PC: 0x02a5c0 | Địa chỉ FDE: 0x0be780 | Kích thước: 256 bytes
//   0x02a5c0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x02a5c4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x02a5c8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x02a5cc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0384_0x02a5c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02a5c0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0be780ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0385 | PC: 0x02a814 | FDE: 0x0bea58 | Size: 256 bytes
// Hàm FDE #0385 | Địa chỉ PC: 0x02a814 | Địa chỉ FDE: 0x0bea58 | Kích thước: 256 bytes
//   0x02a814: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x02a818: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x02a81c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x02a820: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0385_0x02a814(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02a814ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0bea58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0386 | PC: 0x02a97c | FDE: 0x0be7a8 | Size: 256 bytes
// Hàm FDE #0386 | Địa chỉ PC: 0x02a97c | Địa chỉ FDE: 0x0be7a8 | Kích thước: 256 bytes
//   0x02a97c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x02a980: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x02a984: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x02a988: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0386_0x02a97c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02a97cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0be7a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0387 | PC: 0x02ac18 | FDE: 0x0bea90 | Size: 256 bytes
// Hàm FDE #0387 | Địa chỉ PC: 0x02ac18 | Địa chỉ FDE: 0x0bea90 | Kích thước: 256 bytes
//   0x02ac18: D10483FF  sub      sp, sp, #0x120
//   0x02ac1c: A90C6FFC  stp      x28, x27, [sp, #0xc0]
//   0x02ac20: A90D67FA  stp      x26, x25, [sp, #0xd0]
//   0x02ac24: A90E5FF8  stp      x24, x23, [sp, #0xe0]
static inline uint64_t fde_func_0387_0x02ac18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02ac18ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa90c6ffcULL) ^ 0x0bea90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0388 | PC: 0x02b6bc | FDE: 0x0beac8 | Size: 256 bytes
// Hàm FDE #0388 | Địa chỉ PC: 0x02b6bc | Địa chỉ FDE: 0x0beac8 | Kích thước: 256 bytes
//   0x02b6bc: D10183FF  sub      sp, sp, #0x60
//   0x02b6c0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x02b6c4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x02b6c8: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0388_0x02b6bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02b6bcULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x0beac8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0389 | PC: 0x02b8fc | FDE: 0x0be7d0 | Size: 256 bytes
// Hàm FDE #0389 | Địa chỉ PC: 0x02b8fc | Địa chỉ FDE: 0x0be7d0 | Kích thước: 256 bytes
//   0x02b8fc: D101C3FF  sub      sp, sp, #0x70
//   0x02b900: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x02b904: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x02b908: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_0389_0x02b8fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02b8fcULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x0be7d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0390 | PC: 0x02bc50 | FDE: 0x0be800 | Size: 256 bytes
// Hàm FDE #0390 | Địa chỉ PC: 0x02bc50 | Địa chỉ FDE: 0x0be800 | Kích thước: 256 bytes
//   0x02bc50: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x02bc54: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x02bc58: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x02bc5c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0390_0x02bc50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02bc50ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0be800ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0391 | PC: 0x02bd90 | FDE: 0x0beaf8 | Size: 256 bytes
// Hàm FDE #0391 | Địa chỉ PC: 0x02bd90 | Địa chỉ FDE: 0x0beaf8 | Kích thước: 256 bytes
//   0x02bd90: D10243FF  sub      sp, sp, #0x90
//   0x02bd94: F9002BF7  str      x23, [sp, #0x50]
//   0x02bd98: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x02bd9c: A9074FF4  stp      x20, x19, [sp, #0x70]
static inline uint64_t fde_func_0391_0x02bd90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02bd90ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf7ULL) ^ 0x0beaf8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0392 | PC: 0x02bf90 | FDE: 0x0be820 | Size: 196 bytes
// Hàm FDE #0392 | Địa chỉ PC: 0x02bf90 | Địa chỉ FDE: 0x0be820 | Kích thước: 196 bytes
//   0x02bf90: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x02bf94: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x02bf98: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x02bf9c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0392_0x02bf90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02bf90ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0be820ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0393 | PC: 0x02c054 | FDE: 0x0be848 | Size: 256 bytes
// Hàm FDE #0393 | Địa chỉ PC: 0x02c054 | Địa chỉ FDE: 0x0be848 | Kích thước: 256 bytes
//   0x02c054: D10343FF  sub      sp, sp, #0xd0
//   0x02c058: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x02c05c: A9095FF8  stp      x24, x23, [sp, #0x90]
//   0x02c060: A90A57F6  stp      x22, x21, [sp, #0xa0]
static inline uint64_t fde_func_0393_0x02c054(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02c054ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa90867faULL) ^ 0x0be848ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0394 | PC: 0x02c1d8 | FDE: 0x0be878 | Size: 256 bytes
// Hàm FDE #0394 | Địa chỉ PC: 0x02c1d8 | Địa chỉ FDE: 0x0be878 | Kích thước: 256 bytes
//   0x02c1d8: D10343FF  sub      sp, sp, #0xd0
//   0x02c1dc: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x02c1e0: A90B4FF4  stp      x20, x19, [sp, #0xb0]
//   0x02c1e4: A90C7BFD  stp      x29, x30, [sp, #0xc0]
static inline uint64_t fde_func_0394_0x02c1d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02c1d8ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa90a57f6ULL) ^ 0x0be878ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0395 | PC: 0x02c2ec | FDE: 0x0beb28 | Size: 256 bytes
// Hàm FDE #0395 | Địa chỉ PC: 0x02c2ec | Địa chỉ FDE: 0x0beb28 | Kích thước: 256 bytes
//   0x02c2ec: D10143FF  sub      sp, sp, #0x50
//   0x02c2f0: F9000BF7  str      x23, [sp, #0x10]
//   0x02c2f4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x02c2f8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0395_0x02c2ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02c2ecULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x0beb28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0396 | PC: 0x02c440 | FDE: 0x0beb58 | Size: 256 bytes
// Hàm FDE #0396 | Địa chỉ PC: 0x02c440 | Địa chỉ FDE: 0x0beb58 | Kích thước: 256 bytes
//   0x02c440: D101C3FF  sub      sp, sp, #0x70
//   0x02c444: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x02c448: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x02c44c: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0396_0x02c440(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02c440ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x0beb58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0397 | PC: 0x02c5e0 | FDE: 0x0beb90 | Size: 256 bytes
// Hàm FDE #0397 | Địa chỉ PC: 0x02c5e0 | Địa chỉ FDE: 0x0beb90 | Kích thước: 256 bytes
//   0x02c5e0: D10203FF  sub      sp, sp, #0x80
//   0x02c5e4: F90013FB  str      x27, [sp, #0x20]
//   0x02c5e8: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x02c5ec: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0397_0x02c5e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02c5e0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x0beb90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0398 | PC: 0x02c790 | FDE: 0x0bebc8 | Size: 160 bytes
// Hàm FDE #0398 | Địa chỉ PC: 0x02c790 | Địa chỉ FDE: 0x0bebc8 | Kích thước: 160 bytes
//   0x02c790: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x02c794: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02c798: 910043FD  add      x29, sp, #0x10
//   0x02c79c: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0398_0x02c790(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02c790ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bebc8ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0399 | PC: 0x02c830 | FDE: 0x0bebf0 | Size: 256 bytes
// Hàm FDE #0399 | Địa chỉ PC: 0x02c830 | Địa chỉ FDE: 0x0bebf0 | Kích thước: 256 bytes
//   0x02c830: D10143FF  sub      sp, sp, #0x50
//   0x02c834: F90013F5  str      x21, [sp, #0x20]
//   0x02c838: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x02c83c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0399_0x02c830(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02c830ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x0bebf0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0400 | PC: 0x02c94c | FDE: 0x0be8a0 | Size: 256 bytes
// Hàm FDE #0400 | Địa chỉ PC: 0x02c94c | Địa chỉ FDE: 0x0be8a0 | Kích thước: 256 bytes
//   0x02c94c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x02c950: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x02c954: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x02c958: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0400_0x02c94c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02c94cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0be8a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0401 | PC: 0x02cb5c | FDE: 0x0bec18 | Size: 256 bytes
// Hàm FDE #0401 | Địa chỉ PC: 0x02cb5c | Địa chỉ FDE: 0x0bec18 | Kích thước: 256 bytes
//   0x02cb5c: D10543FF  sub      sp, sp, #0x150
//   0x02cb60: F90083FC  str      x28, [sp, #0x100]
//   0x02cb64: A9115FF8  stp      x24, x23, [sp, #0x110]
//   0x02cb68: A91257F6  stp      x22, x21, [sp, #0x120]
static inline uint64_t fde_func_0401_0x02cb5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02cb5cULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x0bec18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0402 | PC: 0x02cf8c | FDE: 0x0bec48 | Size: 256 bytes
// Hàm FDE #0402 | Địa chỉ PC: 0x02cf8c | Địa chỉ FDE: 0x0bec48 | Kích thước: 256 bytes
//   0x02cf8c: D10443FF  sub      sp, sp, #0x110
//   0x02cf90: F90063F9  str      x25, [sp, #0xc0]
//   0x02cf94: A90D5FF8  stp      x24, x23, [sp, #0xd0]
//   0x02cf98: A90E57F6  stp      x22, x21, [sp, #0xe0]
static inline uint64_t fde_func_0402_0x02cf8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02cf8cULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xf90063f9ULL) ^ 0x0bec48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0403 | PC: 0x02d31c | FDE: 0x0bede8 | Size: 172 bytes
// Hàm FDE #0403 | Địa chỉ PC: 0x02d31c | Địa chỉ FDE: 0x0bede8 | Kích thước: 172 bytes
//   0x02d31c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x02d320: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x02d324: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x02d328: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0403_0x02d31c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02d31cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bede8ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #0404 | PC: 0x02d3c8 | FDE: 0x0bec78 | Size: 116 bytes
// Hàm FDE #0404 | Địa chỉ PC: 0x02d3c8 | Địa chỉ FDE: 0x0bec78 | Kích thước: 116 bytes
//   0x02d3c8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x02d3cc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x02d3d0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x02d3d4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0404_0x02d3c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02d3c8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bec78ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0405 | PC: 0x02d43c | FDE: 0x0bec98 | Size: 112 bytes [_ZN4nuro7ILogger15registerHandlerERKNSt6__ndk110shared_ptrINS_11ILogHandlerEEE]
// Hàm FDE #0405 | Địa chỉ PC: 0x02d43c | Địa chỉ FDE: 0x0bec98 | Kích thước: 112 bytes
//   0x02d43c: D10083FF  sub      sp, sp, #0x20
//   0x02d440: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02d444: 910043FD  add      x29, sp, #0x10
//   0x02d448: F00005E8  adrp     x8, #0xec000
static inline uint64_t fde_func_0405_0x02d43c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02d43cULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bec98ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0406 | PC: 0x02d4ac | FDE: 0x0becb8 | Size: 88 bytes
// Hàm FDE #0406 | Địa chỉ PC: 0x02d4ac | Địa chỉ FDE: 0x0becb8 | Kích thước: 88 bytes
//   0x02d4ac: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x02d4b0: 910003FD  mov      x29, sp
//   0x02d4b4: F00005E8  adrp     x8, #0xec000
//   0x02d4b8: 910CE108  add      x8, x8, #0x338
static inline uint64_t fde_func_0406_0x02d4ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02d4acULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0becb8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0407 | PC: 0x02d504 | FDE: 0x0becd8 | Size: 256 bytes
// Hàm FDE #0407 | Địa chỉ PC: 0x02d504 | Địa chỉ FDE: 0x0becd8 | Kích thước: 256 bytes
//   0x02d504: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x02d508: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02d50c: 910043FD  add      x29, sp, #0x10
//   0x02d510: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0407_0x02d504(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02d504ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0becd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0408 | PC: 0x02d658 | FDE: 0x0becf8 | Size: 112 bytes [_ZN4nuro7ILogger11setLogLevelENS_8LogLevelE]
// Hàm FDE #0408 | Địa chỉ PC: 0x02d658 | Địa chỉ FDE: 0x0becf8 | Kích thước: 112 bytes
//   0x02d658: D10083FF  sub      sp, sp, #0x20
//   0x02d65c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02d660: 910043FD  add      x29, sp, #0x10
//   0x02d664: F00005E8  adrp     x8, #0xec000
static inline uint64_t fde_func_0408_0x02d658(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02d658ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0becf8ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0409 | PC: 0x02d6c8 | FDE: 0x0bed18 | Size: 256 bytes
// Hàm FDE #0409 | Địa chỉ PC: 0x02d6c8 | Địa chỉ FDE: 0x0bed18 | Kích thước: 256 bytes
//   0x02d6c8: D10083FF  sub      sp, sp, #0x20
//   0x02d6cc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02d6d0: 910043FD  add      x29, sp, #0x10
//   0x02d6d4: F00005E9  adrp     x9, #0xec000
static inline uint64_t fde_func_0409_0x02d6c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02d6c8ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bed18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0410 | PC: 0x02d7cc | FDE: 0x0bed38 | Size: 16 bytes
// Hàm FDE #0410 | Địa chỉ PC: 0x02d7cc | Địa chỉ FDE: 0x0bed38 | Kích thước: 16 bytes
//   0x02d7cc: B9400008  ldr      w8, [x0]
//   0x02d7d0: 6B01011F  cmp      w8, w1
//   0x02d7d4: 1A9FC7E0  cset     w0, le
//   0x02d7d8: D65F03C0  ret      
static inline uint64_t fde_func_0410_0x02d7cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02d7ccULL ^ (static_cast<uint64_t>(0xb9400008ULL) << 13);
    acc = (acc + a1 + 0x6b01011fULL) ^ 0x0bed38ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0411 | PC: 0x02d7dc | FDE: 0x0bee18 | Size: 256 bytes
// Hàm FDE #0411 | Địa chỉ PC: 0x02d7dc | Địa chỉ FDE: 0x0bee18 | Kích thước: 256 bytes
//   0x02d7dc: F81A0FFC  str      x28, [sp, #-0x60]!
//   0x02d7e0: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x02d7e4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x02d7e8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0411_0x02d7dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02d7dcULL ^ (static_cast<uint64_t>(0xf81a0ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0bee18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0412 | PC: 0x02da6c | FDE: 0x0bed50 | Size: 12 bytes
// Hàm FDE #0412 | Địa chỉ PC: 0x02da6c | Địa chỉ FDE: 0x0bed50 | Kích thước: 12 bytes
//   0x02da6c: B900001F  str      wzr, [x0]
//   0x02da70: A900FC1F  stp      xzr, xzr, [x0, #8]
//   0x02da74: D65F03C0  ret      
static inline uint64_t fde_func_0412_0x02da6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02da6cULL ^ (static_cast<uint64_t>(0xb900001fULL) << 13);
    acc = (acc + a1 + 0xa900fc1fULL) ^ 0x0bed50ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0413 | PC: 0x02da78 | FDE: 0x0bed68 | Size: 88 bytes
// Hàm FDE #0413 | Địa chỉ PC: 0x02da78 | Địa chỉ FDE: 0x0bed68 | Kích thước: 88 bytes
//   0x02da78: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x02da7c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02da80: 910043FD  add      x29, sp, #0x10
//   0x02da84: F9400813  ldr      x19, [x0, #0x10]
static inline uint64_t fde_func_0413_0x02da78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02da78ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bed68ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0414 | PC: 0x02dad0 | FDE: 0x0bed88 | Size: 156 bytes
// Hàm FDE #0414 | Địa chỉ PC: 0x02dad0 | Địa chỉ FDE: 0x0bed88 | Kích thước: 156 bytes
//   0x02dad0: D10443FF  sub      sp, sp, #0x110
//   0x02dad4: A90F4FFC  stp      x28, x19, [sp, #0xf0]
//   0x02dad8: A9107BFD  stp      x29, x30, [sp, #0x100]
//   0x02dadc: 910403FD  add      x29, sp, #0x100
static inline uint64_t fde_func_0414_0x02dad0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02dad0ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90f4ffcULL) ^ 0x0bed88ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0415 | PC: 0x02db6c | FDE: 0x0bee50 | Size: 256 bytes
// Hàm FDE #0415 | Địa chỉ PC: 0x02db6c | Địa chỉ FDE: 0x0bee50 | Kích thước: 256 bytes
//   0x02db6c: D10143FF  sub      sp, sp, #0x50
//   0x02db70: F90013F5  str      x21, [sp, #0x20]
//   0x02db74: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x02db78: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0415_0x02db6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02db6cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x0bee50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0416 | PC: 0x02dca0 | FDE: 0x0bee78 | Size: 256 bytes
// Hàm FDE #0416 | Địa chỉ PC: 0x02dca0 | Địa chỉ FDE: 0x0bee78 | Kích thước: 256 bytes
//   0x02dca0: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x02dca4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x02dca8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x02dcac: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0416_0x02dca0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02dca0ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0bee78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0417 | PC: 0x02dee8 | FDE: 0x0beda8 | Size: 228 bytes
// Hàm FDE #0417 | Địa chỉ PC: 0x02dee8 | Địa chỉ FDE: 0x0beda8 | Kích thước: 228 bytes
//   0x02dee8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x02deec: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x02def0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x02def4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0417_0x02dee8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02dee8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0beda8ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #0418 | PC: 0x02dfcc | FDE: 0x0bedc8 | Size: 256 bytes
// Hàm FDE #0418 | Địa chỉ PC: 0x02dfcc | Địa chỉ FDE: 0x0bedc8 | Kích thước: 256 bytes
//   0x02dfcc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x02dfd0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02dfd4: 910043FD  add      x29, sp, #0x10
//   0x02dfd8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0418_0x02dfcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02dfccULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bedc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0419 | PC: 0x02e154 | FDE: 0x0beea8 | Size: 256 bytes
// Hàm FDE #0419 | Địa chỉ PC: 0x02e154 | Địa chỉ FDE: 0x0beea8 | Kích thước: 256 bytes
//   0x02e154: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x02e158: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x02e15c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x02e160: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0419_0x02e154(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02e154ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0beea8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0420 | PC: 0x02e38c | FDE: 0x0bf2e8 | Size: 256 bytes [_ZN4nuro12MessageUtils20toolCalls2JsonStringERKNSt6__ndk16vectorINS_8ToolCallENS1_9allocatorIS3_EEEE]
// Hàm FDE #0420 | Địa chỉ PC: 0x02e38c | Địa chỉ FDE: 0x0bf2e8 | Kích thước: 256 bytes
//   0x02e38c: D104C3FF  sub      sp, sp, #0x130
//   0x02e390: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x02e394: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x02e398: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0420_0x02e38c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02e38cULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x0bf2e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0421 | PC: 0x02e99c | FDE: 0x0bef00 | Size: 256 bytes
// Hàm FDE #0421 | Địa chỉ PC: 0x02e99c | Địa chỉ FDE: 0x0bef00 | Kích thước: 256 bytes
//   0x02e99c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x02e9a0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x02e9a4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x02e9a8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0421_0x02e99c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02e99cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bef00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0422 | PC: 0x02eb8c | FDE: 0x0bef28 | Size: 228 bytes
// Hàm FDE #0422 | Địa chỉ PC: 0x02eb8c | Địa chỉ FDE: 0x0bef28 | Kích thước: 228 bytes
//   0x02eb8c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x02eb90: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x02eb94: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x02eb98: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0422_0x02eb8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02eb8cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bef28ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #0423 | PC: 0x02ec70 | FDE: 0x0bf320 | Size: 256 bytes
// Hàm FDE #0423 | Địa chỉ PC: 0x02ec70 | Địa chỉ FDE: 0x0bf320 | Kích thước: 256 bytes
//   0x02ec70: D101C3FF  sub      sp, sp, #0x70
//   0x02ec74: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x02ec78: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x02ec7c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0423_0x02ec70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02ec70ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x0bf320ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0424 | PC: 0x02eec8 | FDE: 0x0bf350 | Size: 256 bytes
// Hàm FDE #0424 | Địa chỉ PC: 0x02eec8 | Địa chỉ FDE: 0x0bf350 | Kích thước: 256 bytes
//   0x02eec8: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x02eecc: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x02eed0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x02eed4: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0424_0x02eec8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02eec8ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0bf350ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0425 | PC: 0x02f228 | FDE: 0x0bf388 | Size: 256 bytes
// Hàm FDE #0425 | Địa chỉ PC: 0x02f228 | Địa chỉ FDE: 0x0bf388 | Kích thước: 256 bytes
//   0x02f228: D10203FF  sub      sp, sp, #0x80
//   0x02f22c: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x02f230: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x02f234: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_0425_0x02f228(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02f228ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90367faULL) ^ 0x0bf388ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0426 | PC: 0x02f6d4 | FDE: 0x0bef48 | Size: 252 bytes
// Hàm FDE #0426 | Địa chỉ PC: 0x02f6d4 | Địa chỉ FDE: 0x0bef48 | Kích thước: 252 bytes
//   0x02f6d4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x02f6d8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x02f6dc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x02f6e0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0426_0x02f6d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02f6d4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bef48ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #0427 | PC: 0x02f7d0 | FDE: 0x0bef70 | Size: 104 bytes
// Hàm FDE #0427 | Địa chỉ PC: 0x02f7d0 | Địa chỉ FDE: 0x0bef70 | Kích thước: 104 bytes
//   0x02f7d0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x02f7d4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x02f7d8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x02f7dc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0427_0x02f7d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02f7d0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bef70ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0428 | PC: 0x02f838 | FDE: 0x0bef90 | Size: 256 bytes
// Hàm FDE #0428 | Địa chỉ PC: 0x02f838 | Địa chỉ FDE: 0x0bef90 | Kích thước: 256 bytes
//   0x02f838: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x02f83c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x02f840: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x02f844: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0428_0x02f838(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02f838ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bef90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0429 | PC: 0x02f980 | FDE: 0x0befb8 | Size: 92 bytes
// Hàm FDE #0429 | Địa chỉ PC: 0x02f980 | Địa chỉ FDE: 0x0befb8 | Kích thước: 92 bytes
//   0x02f980: B40002C1  cbz      x1, #0x2f9d8
//   0x02f984: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x02f988: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02f98c: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_0429_0x02f980(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02f980ULL ^ (static_cast<uint64_t>(0xb40002c1ULL) << 13);
    acc = (acc + a1 + 0xa9be4ff4ULL) ^ 0x0befb8ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0430 | PC: 0x02f9dc | FDE: 0x0befd8 | Size: 256 bytes
// Hàm FDE #0430 | Địa chỉ PC: 0x02f9dc | Địa chỉ FDE: 0x0befd8 | Kích thước: 256 bytes
//   0x02f9dc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x02f9e0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x02f9e4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x02f9e8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0430_0x02f9dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02f9dcULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0befd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0431 | PC: 0x02fcb8 | FDE: 0x0bf3c0 | Size: 256 bytes
// Hàm FDE #0431 | Địa chỉ PC: 0x02fcb8 | Địa chỉ FDE: 0x0bf3c0 | Kích thước: 256 bytes
//   0x02fcb8: D10203FF  sub      sp, sp, #0x80
//   0x02fcbc: F90013FB  str      x27, [sp, #0x20]
//   0x02fcc0: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x02fcc4: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0431_0x02fcb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02fcb8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x0bf3c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0432 | PC: 0x02fec4 | FDE: 0x0bf3f8 | Size: 256 bytes
// Hàm FDE #0432 | Địa chỉ PC: 0x02fec4 | Địa chỉ FDE: 0x0bf3f8 | Kích thước: 256 bytes
//   0x02fec4: D10203FF  sub      sp, sp, #0x80
//   0x02fec8: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x02fecc: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x02fed0: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_0432_0x02fec4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02fec4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90557f6ULL) ^ 0x0bf3f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0433 | PC: 0x030034 | FDE: 0x0bf000 | Size: 48 bytes
// Hàm FDE #0433 | Địa chỉ PC: 0x030034 | Địa chỉ FDE: 0x0bf000 | Kích thước: 48 bytes
//   0x030034: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x030038: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03003c: 910043FD  add      x29, sp, #0x10
//   0x030040: 900005C8  adrp     x8, #0xe8000
static inline uint64_t fde_func_0433_0x030034(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x030034ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bf000ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0434 | PC: 0x030064 | FDE: 0x0bf428 | Size: 256 bytes
// Hàm FDE #0434 | Địa chỉ PC: 0x030064 | Địa chỉ FDE: 0x0bf428 | Kích thước: 256 bytes
//   0x030064: D101C3FF  sub      sp, sp, #0x70
//   0x030068: F90023F5  str      x21, [sp, #0x40]
//   0x03006c: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x030070: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0434_0x030064(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x030064ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0bf428ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0435 | PC: 0x0301bc | FDE: 0x0bf020 | Size: 256 bytes
// Hàm FDE #0435 | Địa chỉ PC: 0x0301bc | Địa chỉ FDE: 0x0bf020 | Kích thước: 256 bytes
//   0x0301bc: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0301c0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0301c4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0301c8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0435_0x0301bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0301bcULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0bf020ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0436 | PC: 0x0302e0 | FDE: 0x0bf450 | Size: 256 bytes
// Hàm FDE #0436 | Địa chỉ PC: 0x0302e0 | Địa chỉ FDE: 0x0bf450 | Kích thước: 256 bytes
//   0x0302e0: D10283FF  sub      sp, sp, #0xa0
//   0x0302e4: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0302e8: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x0302ec: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_0436_0x0302e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0302e0ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa90757f6ULL) ^ 0x0bf450ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0437 | PC: 0x0304e0 | FDE: 0x0bf480 | Size: 256 bytes
// Hàm FDE #0437 | Địa chỉ PC: 0x0304e0 | Địa chỉ FDE: 0x0bf480 | Kích thước: 256 bytes
//   0x0304e0: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0304e4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0304e8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0304ec: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0437_0x0304e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0304e0ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0bf480ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0438 | PC: 0x0305e4 | FDE: 0x0bf048 | Size: 56 bytes
// Hàm FDE #0438 | Địa chỉ PC: 0x0305e4 | Địa chỉ FDE: 0x0bf048 | Kích thước: 56 bytes
//   0x0305e4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0305e8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0305ec: 910043FD  add      x29, sp, #0x10
//   0x0305f0: 900005C8  adrp     x8, #0xe8000
static inline uint64_t fde_func_0438_0x0305e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0305e4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bf048ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0439 | PC: 0x03061c | FDE: 0x0bf068 | Size: 8 bytes
// Hàm FDE #0439 | Địa chỉ PC: 0x03061c | Địa chỉ FDE: 0x0bf068 | Kích thước: 8 bytes
//   0x03061c: 91004000  add      x0, x0, #0x10
//   0x030620: 17FF89D4  b        #0x12d70
static inline uint64_t fde_func_0439_0x03061c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03061cULL ^ (static_cast<uint64_t>(0x91004000ULL) << 13);
    acc = (acc + a1 + 0x17ff89d4ULL) ^ 0x0bf068ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0440 | PC: 0x030624 | FDE: 0x0bf080 | Size: 56 bytes
// Hàm FDE #0440 | Địa chỉ PC: 0x030624 | Địa chỉ FDE: 0x0bf080 | Kích thước: 56 bytes
//   0x030624: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x030628: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03062c: 910043FD  add      x29, sp, #0x10
//   0x030630: 900005C8  adrp     x8, #0xe8000
static inline uint64_t fde_func_0440_0x030624(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x030624ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bf080ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0441 | PC: 0x03065c | FDE: 0x0bf4b8 | Size: 256 bytes
// Hàm FDE #0441 | Địa chỉ PC: 0x03065c | Địa chỉ FDE: 0x0bf4b8 | Kích thước: 256 bytes
//   0x03065c: D10183FF  sub      sp, sp, #0x60
//   0x030660: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x030664: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x030668: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0441_0x03065c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03065cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x0bf4b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0442 | PC: 0x0307ac | FDE: 0x0bf4e8 | Size: 236 bytes
// Hàm FDE #0442 | Địa chỉ PC: 0x0307ac | Địa chỉ FDE: 0x0bf4e8 | Kích thước: 236 bytes
//   0x0307ac: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0307b0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0307b4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0307b8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0442_0x0307ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0307acULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bf4e8ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0443 | PC: 0x030898 | FDE: 0x0bf510 | Size: 220 bytes
// Hàm FDE #0443 | Địa chỉ PC: 0x030898 | Địa chỉ FDE: 0x0bf510 | Kích thước: 220 bytes
//   0x030898: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x03089c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0308a0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0308a4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0443_0x030898(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x030898ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bf510ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #0444 | PC: 0x030974 | FDE: 0x0bf540 | Size: 256 bytes
// Hàm FDE #0444 | Địa chỉ PC: 0x030974 | Địa chỉ FDE: 0x0bf540 | Kích thước: 256 bytes
//   0x030974: D10183FF  sub      sp, sp, #0x60
//   0x030978: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x03097c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x030980: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0444_0x030974(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x030974ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x0bf540ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0445 | PC: 0x030a80 | FDE: 0x0bf0a0 | Size: 256 bytes
// Hàm FDE #0445 | Địa chỉ PC: 0x030a80 | Địa chỉ FDE: 0x0bf0a0 | Kích thước: 256 bytes
//   0x030a80: D10203FF  sub      sp, sp, #0x80
//   0x030a84: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x030a88: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x030a8c: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0445_0x030a80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x030a80ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x0bf0a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0446 | PC: 0x030d5c | FDE: 0x0bf0d0 | Size: 256 bytes
// Hàm FDE #0446 | Địa chỉ PC: 0x030d5c | Địa chỉ FDE: 0x0bf0d0 | Kích thước: 256 bytes
//   0x030d5c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x030d60: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x030d64: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x030d68: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0446_0x030d5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x030d5cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0bf0d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0447 | PC: 0x030e7c | FDE: 0x0bf100 | Size: 256 bytes
// Hàm FDE #0447 | Địa chỉ PC: 0x030e7c | Địa chỉ FDE: 0x0bf100 | Kích thước: 256 bytes
//   0x030e7c: EB00003F  cmp      x1, x0
//   0x030e80: 1A9F17E8  cset     w8, eq
//   0x030e84: 39006028  strb     w8, [x1, #0x18]
//   0x030e88: 54000580  b.eq     #0x30f38
static inline uint64_t fde_func_0447_0x030e7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x030e7cULL ^ (static_cast<uint64_t>(0xeb00003fULL) << 13);
    acc = (acc + a1 + 0x1a9f17e8ULL) ^ 0x0bf100ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0448 | PC: 0x03101c | FDE: 0x0bf570 | Size: 232 bytes
// Hàm FDE #0448 | Địa chỉ PC: 0x03101c | Địa chỉ FDE: 0x0bf570 | Kích thước: 232 bytes
//   0x03101c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x031020: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x031024: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x031028: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0448_0x03101c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03101cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bf570ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0449 | PC: 0x031104 | FDE: 0x0bf5a0 | Size: 164 bytes
// Hàm FDE #0449 | Địa chỉ PC: 0x031104 | Địa chỉ FDE: 0x0bf5a0 | Kích thước: 164 bytes
//   0x031104: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x031108: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x03110c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x031110: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0449_0x031104(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x031104ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bf5a0ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #0450 | PC: 0x0311a8 | FDE: 0x0bf5d0 | Size: 256 bytes
// Hàm FDE #0450 | Địa chỉ PC: 0x0311a8 | Địa chỉ FDE: 0x0bf5d0 | Kích thước: 256 bytes
//   0x0311a8: D10183FF  sub      sp, sp, #0x60
//   0x0311ac: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0311b0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0311b4: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0450_0x0311a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0311a8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x0bf5d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0451 | PC: 0x031314 | FDE: 0x0bf600 | Size: 256 bytes
// Hàm FDE #0451 | Địa chỉ PC: 0x031314 | Địa chỉ FDE: 0x0bf600 | Kích thước: 256 bytes
//   0x031314: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x031318: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x03131c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x031320: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0451_0x031314(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x031314ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0bf600ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0452 | PC: 0x031420 | FDE: 0x0bf118 | Size: 256 bytes
// Hàm FDE #0452 | Địa chỉ PC: 0x031420 | Địa chỉ FDE: 0x0bf118 | Kích thước: 256 bytes
//   0x031420: D10243FF  sub      sp, sp, #0x90
//   0x031424: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x031428: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x03142c: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0452_0x031420(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x031420ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x0bf118ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0453 | PC: 0x031f00 | FDE: 0x0bf148 | Size: 4 bytes
// Hàm FDE #0453 | Địa chỉ PC: 0x031f00 | Địa chỉ FDE: 0x0bf148 | Kích thước: 4 bytes
//   0x031f00: 17FF82AC  b        #0x129b0
static inline uint64_t fde_func_0453_0x031f00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x031f00ULL ^ (static_cast<uint64_t>(0x17ff82acULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x0bf148ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0454 | PC: 0x031f04 | FDE: 0x0bf160 | Size: 36 bytes
// Hàm FDE #0454 | Địa chỉ PC: 0x031f04 | Địa chỉ FDE: 0x0bf160 | Kích thước: 36 bytes
//   0x031f04: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x031f08: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x031f0c: 910043FD  add      x29, sp, #0x10
//   0x031f10: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0454_0x031f04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x031f04ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bf160ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0455 | PC: 0x031f28 | FDE: 0x0bf180 | Size: 12 bytes
// Hàm FDE #0455 | Địa chỉ PC: 0x031f28 | Địa chỉ FDE: 0x0bf180 | Kích thước: 12 bytes
//   0x031f28: F8418C08  ldr      x8, [x0, #0x18]!
//   0x031f2c: F9400901  ldr      x1, [x8, #0x10]
//   0x031f30: D61F0020  br       x1
static inline uint64_t fde_func_0455_0x031f28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x031f28ULL ^ (static_cast<uint64_t>(0xf8418c08ULL) << 13);
    acc = (acc + a1 + 0xf9400901ULL) ^ 0x0bf180ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0456 | PC: 0x031f34 | FDE: 0x0bf198 | Size: 4 bytes
// Hàm FDE #0456 | Địa chỉ PC: 0x031f34 | Địa chỉ FDE: 0x0bf198 | Kích thước: 4 bytes
//   0x031f34: 17FF8233  b        #0x12800
static inline uint64_t fde_func_0456_0x031f34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x031f34ULL ^ (static_cast<uint64_t>(0x17ff8233ULL) << 13);
    acc = (acc + a1 + 0xf81d0ff5ULL) ^ 0x0bf198ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0457 | PC: 0x031f38 | FDE: 0x0bf1b0 | Size: 168 bytes
// Hàm FDE #0457 | Địa chỉ PC: 0x031f38 | Địa chỉ FDE: 0x0bf1b0 | Kích thước: 168 bytes
//   0x031f38: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x031f3c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x031f40: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x031f44: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0457_0x031f38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x031f38ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bf1b0ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #0458 | PC: 0x031fe0 | FDE: 0x0bf1d0 | Size: 8 bytes
// Hàm FDE #0458 | Địa chỉ PC: 0x031fe0 | Địa chỉ FDE: 0x0bf1d0 | Kích thước: 8 bytes
//   0x031fe0: F9400400  ldr      x0, [x0, #8]
//   0x031fe4: 17FFE7EB  b        #0x2bf90
static inline uint64_t fde_func_0458_0x031fe0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x031fe0ULL ^ (static_cast<uint64_t>(0xf9400400ULL) << 13);
    acc = (acc + a1 + 0x17ffe7ebULL) ^ 0x0bf1d0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0459 | PC: 0x031fe8 | FDE: 0x0bf1e8 | Size: 4 bytes
// Hàm FDE #0459 | Địa chỉ PC: 0x031fe8 | Địa chỉ FDE: 0x0bf1e8 | Kích thước: 4 bytes
//   0x031fe8: D65F03C0  ret      
static inline uint64_t fde_func_0459_0x031fe8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x031fe8ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0x17ff8205ULL) ^ 0x0bf1e8ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0460 | PC: 0x031fec | FDE: 0x0bf200 | Size: 4 bytes
// Hàm FDE #0460 | Địa chỉ PC: 0x031fec | Địa chỉ FDE: 0x0bf200 | Kích thước: 4 bytes
//   0x031fec: 17FF8205  b        #0x12800
static inline uint64_t fde_func_0460_0x031fec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x031fecULL ^ (static_cast<uint64_t>(0x17ff8205ULL) << 13);
    acc = (acc + a1 + 0xd10403ffULL) ^ 0x0bf200ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0461 | PC: 0x031ff0 | FDE: 0x0bf630 | Size: 256 bytes
// Hàm FDE #0461 | Địa chỉ PC: 0x031ff0 | Địa chỉ FDE: 0x0bf630 | Kích thước: 256 bytes
//   0x031ff0: D10403FF  sub      sp, sp, #0x100
//   0x031ff4: A90A6FFC  stp      x28, x27, [sp, #0xa0]
//   0x031ff8: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x031ffc: A90C5FF8  stp      x24, x23, [sp, #0xc0]
static inline uint64_t fde_func_0461_0x031ff0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x031ff0ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90a6ffcULL) ^ 0x0bf630ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0462 | PC: 0x032678 | FDE: 0x0bf218 | Size: 256 bytes
// Hàm FDE #0462 | Địa chỉ PC: 0x032678 | Địa chỉ FDE: 0x0bf218 | Kích thước: 256 bytes
//   0x032678: 72001C3F  tst      w1, #0xff
//   0x03267c: 540001C0  b.eq     #0x326b4
//   0x032680: 2A0103E8  mov      w8, w1
//   0x032684: 12001D0A  and      w10, w8, #0xff
static inline uint64_t fde_func_0462_0x032678(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x032678ULL ^ (static_cast<uint64_t>(0x72001c3fULL) << 13);
    acc = (acc + a1 + 0x540001c0ULL) ^ 0x0bf218ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0463 | PC: 0x0327bc | FDE: 0x0bf230 | Size: 256 bytes
// Hàm FDE #0463 | Địa chỉ PC: 0x0327bc | Địa chỉ FDE: 0x0bf230 | Kích thước: 256 bytes
//   0x0327bc: B4000121  cbz      x1, #0x327e0
//   0x0327c0: AA0103E8  mov      x8, x1
//   0x0327c4: 91004001  add      x1, x0, #0x10
//   0x0327c8: B7F80168  tbnz     x8, #0x3f, #0x327f4
static inline uint64_t fde_func_0463_0x0327bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0327bcULL ^ (static_cast<uint64_t>(0xb4000121ULL) << 13);
    acc = (acc + a1 + 0xaa0103e8ULL) ^ 0x0bf230ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0464 | PC: 0x032984 | FDE: 0x0bf248 | Size: 256 bytes
// Hàm FDE #0464 | Địa chỉ PC: 0x032984 | Địa chỉ FDE: 0x0bf248 | Kích thước: 256 bytes
//   0x032984: B4000101  cbz      x1, #0x329a4
//   0x032988: AA0103E8  mov      x8, x1
//   0x03298c: F100283F  cmp      x1, #0xa
//   0x032990: 91004001  add      x1, x0, #0x10
static inline uint64_t fde_func_0464_0x032984(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x032984ULL ^ (static_cast<uint64_t>(0xb4000101ULL) << 13);
    acc = (acc + a1 + 0xaa0103e8ULL) ^ 0x0bf248ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0465 | PC: 0x032ac0 | FDE: 0x0bf260 | Size: 164 bytes
// Hàm FDE #0465 | Địa chỉ PC: 0x032ac0 | Địa chỉ FDE: 0x0bf260 | Kích thước: 164 bytes
//   0x032ac0: D10443FF  sub      sp, sp, #0x110
//   0x032ac4: A90F4FFC  stp      x28, x19, [sp, #0xf0]
//   0x032ac8: A9107BFD  stp      x29, x30, [sp, #0x100]
//   0x032acc: 910403FD  add      x29, sp, #0x100
static inline uint64_t fde_func_0465_0x032ac0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x032ac0ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90f4ffcULL) ^ 0x0bf260ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #0466 | PC: 0x032b64 | FDE: 0x0bf280 | Size: 256 bytes
// Hàm FDE #0466 | Địa chỉ PC: 0x032b64 | Địa chỉ FDE: 0x0bf280 | Kích thước: 256 bytes
//   0x032b64: 9E66000C  fmov     x12, d0
//   0x032b68: D374FD89  lsr      x9, x12, #0x34
//   0x032b6c: 1280864E  mov      w14, #-0x433
//   0x032b70: D2E0020A  mov      x10, #0x10000000000000
static inline uint64_t fde_func_0466_0x032b64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x032b64ULL ^ (static_cast<uint64_t>(0x9e66000cULL) << 13);
    acc = (acc + a1 + 0xd374fd89ULL) ^ 0x0bf280ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0467 | PC: 0x032d48 | FDE: 0x0bf2a0 | Size: 256 bytes
// Hàm FDE #0467 | Địa chỉ PC: 0x032d48 | Địa chỉ FDE: 0x0bf2a0 | Kích thước: 256 bytes
//   0x032d48: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x032d4c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x032d50: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x032d54: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0467_0x032d48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x032d48ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bf2a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0468 | PC: 0x032f4c | FDE: 0x0bf2c8 | Size: 256 bytes
// Hàm FDE #0468 | Địa chỉ PC: 0x032f4c | Địa chỉ FDE: 0x0bf2c8 | Kích thước: 256 bytes
//   0x032f4c: A9BE57F6  stp      x22, x21, [sp, #-0x20]!
//   0x032f50: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x032f54: B9402BE9  ldr      w9, [sp, #0x28]
//   0x032f58: F94013EA  ldr      x10, [sp, #0x20]
static inline uint64_t fde_func_0468_0x032f4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x032f4cULL ^ (static_cast<uint64_t>(0xa9be57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bf2c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0469 | PC: 0x03321c | FDE: 0x0bf668 | Size: 48 bytes
// Hàm FDE #0469 | Địa chỉ PC: 0x03321c | Địa chỉ FDE: 0x0bf668 | Kích thước: 48 bytes
//   0x03321c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x033220: 910003FD  mov      x29, sp
//   0x033224: 97FF7F4B  bl       #0x12f50
//   0x033228: D29EF9E8  mov      x8, #0xf7cf
static inline uint64_t fde_func_0469_0x03321c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03321cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0bf668ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0470 | PC: 0x03324c | FDE: 0x0bf688 | Size: 44 bytes
// Hàm FDE #0470 | Địa chỉ PC: 0x03324c | Địa chỉ FDE: 0x0bf688 | Kích thước: 44 bytes
//   0x03324c: 2A0003E9  mov      w9, w0
//   0x033250: 7100081F  cmp      w0, #2
//   0x033254: AA0803E0  mov      x0, x8
//   0x033258: 540000A8  b.hi     #0x3326c
static inline uint64_t fde_func_0470_0x03324c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03324cULL ^ (static_cast<uint64_t>(0x2a0003e9ULL) << 13);
    acc = (acc + a1 + 0x7100081fULL) ^ 0x0bf688ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0471 | PC: 0x033278 | FDE: 0x0bf6a0 | Size: 224 bytes
// Hàm FDE #0471 | Địa chỉ PC: 0x033278 | Địa chỉ FDE: 0x0bf6a0 | Kích thước: 224 bytes
//   0x033278: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x03327c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x033280: 910043FD  add      x29, sp, #0x10
//   0x033284: 39400008  ldrb     w8, [x0]
static inline uint64_t fde_func_0471_0x033278(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x033278ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bf6a0ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #0472 | PC: 0x033358 | FDE: 0x0bf6c0 | Size: 24 bytes
// Hàm FDE #0472 | Địa chỉ PC: 0x033358 | Địa chỉ FDE: 0x0bf6c0 | Kích thước: 24 bytes
//   0x033358: B9400008  ldr      w8, [x0]
//   0x03335c: 7100051F  cmp      w8, #1
//   0x033360: 1A9F17E9  cset     w9, eq
//   0x033364: 7100091F  cmp      w8, #2
static inline uint64_t fde_func_0472_0x033358(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x033358ULL ^ (static_cast<uint64_t>(0xb9400008ULL) << 13);
    acc = (acc + a1 + 0x7100051fULL) ^ 0x0bf6c0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0473 | PC: 0x033370 | FDE: 0x0bf6d8 | Size: 24 bytes
// Hàm FDE #0473 | Địa chỉ PC: 0x033370 | Địa chỉ FDE: 0x0bf6d8 | Kích thước: 24 bytes
//   0x033370: B9400008  ldr      w8, [x0]
//   0x033374: 7100051F  cmp      w8, #1
//   0x033378: 1A9F17E9  cset     w9, eq
//   0x03337c: 7100091F  cmp      w8, #2
static inline uint64_t fde_func_0473_0x033370(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x033370ULL ^ (static_cast<uint64_t>(0xb9400008ULL) << 13);
    acc = (acc + a1 + 0x7100051fULL) ^ 0x0bf6d8ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0474 | PC: 0x033388 | FDE: 0x0bf6f0 | Size: 12 bytes
// Hàm FDE #0474 | Địa chỉ PC: 0x033388 | Địa chỉ FDE: 0x0bf6f0 | Kích thước: 12 bytes
//   0x033388: 71000C1F  cmp      w0, #3
//   0x03338c: 1A9F3400  csinc    w0, w0, wzr, lo
//   0x033390: D65F03C0  ret      
static inline uint64_t fde_func_0474_0x033388(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x033388ULL ^ (static_cast<uint64_t>(0x71000c1fULL) << 13);
    acc = (acc + a1 + 0x1a9f3400ULL) ^ 0x0bf6f0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0475 | PC: 0x033394 | FDE: 0x0bf720 | Size: 256 bytes
// Hàm FDE #0475 | Địa chỉ PC: 0x033394 | Địa chỉ FDE: 0x0bf720 | Kích thước: 256 bytes
//   0x033394: D10683FF  sub      sp, sp, #0x1a0
//   0x033398: A9146FFC  stp      x28, x27, [sp, #0x140]
//   0x03339c: A91567FA  stp      x26, x25, [sp, #0x150]
//   0x0333a0: A9165FF8  stp      x24, x23, [sp, #0x160]
static inline uint64_t fde_func_0475_0x033394(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x033394ULL ^ (static_cast<uint64_t>(0xd10683ffULL) << 13);
    acc = (acc + a1 + 0xa9146ffcULL) ^ 0x0bf720ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0476 | PC: 0x033820 | FDE: 0x0bf758 | Size: 256 bytes
// Hàm FDE #0476 | Địa chỉ PC: 0x033820 | Địa chỉ FDE: 0x0bf758 | Kích thước: 256 bytes
//   0x033820: D101C3FF  sub      sp, sp, #0x70
//   0x033824: F90013F9  str      x25, [sp, #0x20]
//   0x033828: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x03382c: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0476_0x033820(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x033820ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x0bf758ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0477 | PC: 0x0339e8 | FDE: 0x0bf708 | Size: 256 bytes
// Hàm FDE #0477 | Địa chỉ PC: 0x0339e8 | Địa chỉ FDE: 0x0bf708 | Kích thước: 256 bytes
//   0x0339e8: A9402040  ldp      x0, x8, [x2]
//   0x0339ec: EB000108  subs     x8, x8, x0
//   0x0339f0: 54000980  b.eq     #0x33b20
//   0x0339f4: D2833D2B  mov      x11, #0x19e9
static inline uint64_t fde_func_0477_0x0339e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0339e8ULL ^ (static_cast<uint64_t>(0xa9402040ULL) << 13);
    acc = (acc + a1 + 0xeb000108ULL) ^ 0x0bf708ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0478 | PC: 0x033bc4 | FDE: 0x0bff18 | Size: 256 bytes
// Hàm FDE #0478 | Địa chỉ PC: 0x033bc4 | Địa chỉ FDE: 0x0bff18 | Kích thước: 256 bytes
//   0x033bc4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x033bc8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x033bcc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x033bd0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0478_0x033bc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x033bc4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bff18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0479 | PC: 0x033dc8 | FDE: 0x0bff40 | Size: 256 bytes
// Hàm FDE #0479 | Địa chỉ PC: 0x033dc8 | Địa chỉ FDE: 0x0bff40 | Kích thước: 256 bytes
//   0x033dc8: D10203FF  sub      sp, sp, #0x80
//   0x033dcc: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x033dd0: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x033dd4: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0479_0x033dc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x033dc8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x0bff40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0480 | PC: 0x03417c | FDE: 0x0bf788 | Size: 168 bytes
// Hàm FDE #0480 | Địa chỉ PC: 0x03417c | Địa chỉ FDE: 0x0bf788 | Kích thước: 168 bytes
//   0x03417c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x034180: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x034184: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x034188: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0480_0x03417c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03417cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bf788ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #0481 | PC: 0x034224 | FDE: 0x0bf7b0 | Size: 60 bytes
// Hàm FDE #0481 | Địa chỉ PC: 0x034224 | Địa chỉ FDE: 0x0bf7b0 | Kích thước: 60 bytes
//   0x034224: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x034228: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03422c: 910043FD  add      x29, sp, #0x10
//   0x034230: F9400801  ldr      x1, [x0, #0x10]
static inline uint64_t fde_func_0481_0x034224(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x034224ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bf7b0ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0482 | PC: 0x034260 | FDE: 0x0bff78 | Size: 256 bytes
// Hàm FDE #0482 | Địa chỉ PC: 0x034260 | Địa chỉ FDE: 0x0bff78 | Kích thước: 256 bytes
//   0x034260: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x034264: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x034268: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x03426c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0482_0x034260(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x034260ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0bff78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0483 | PC: 0x0345cc | FDE: 0x0bffa8 | Size: 256 bytes
// Hàm FDE #0483 | Địa chỉ PC: 0x0345cc | Địa chỉ FDE: 0x0bffa8 | Kích thước: 256 bytes
//   0x0345cc: D10583FF  sub      sp, sp, #0x160
//   0x0345d0: A9106FFC  stp      x28, x27, [sp, #0x100]
//   0x0345d4: A91167FA  stp      x26, x25, [sp, #0x110]
//   0x0345d8: A9125FF8  stp      x24, x23, [sp, #0x120]
static inline uint64_t fde_func_0483_0x0345cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0345ccULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xa9106ffcULL) ^ 0x0bffa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0484 | PC: 0x035e60 | FDE: 0x0bffe0 | Size: 256 bytes
// Hàm FDE #0484 | Địa chỉ PC: 0x035e60 | Địa chỉ FDE: 0x0bffe0 | Kích thước: 256 bytes
//   0x035e60: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x035e64: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x035e68: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x035e6c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0484_0x035e60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x035e60ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0bffe0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0485 | PC: 0x037258 | FDE: 0x0bf7d0 | Size: 88 bytes
// Hàm FDE #0485 | Địa chỉ PC: 0x037258 | Địa chỉ FDE: 0x0bf7d0 | Kích thước: 88 bytes
//   0x037258: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x03725c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x037260: 910043FD  add      x29, sp, #0x10
//   0x037264: 91030000  add      x0, x0, #0xc0
static inline uint64_t fde_func_0485_0x037258(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x037258ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bf7d0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0486 | PC: 0x0372b0 | FDE: 0x0c0018 | Size: 256 bytes
// Hàm FDE #0486 | Địa chỉ PC: 0x0372b0 | Địa chỉ FDE: 0x0c0018 | Kích thước: 256 bytes
//   0x0372b0: D10403FF  sub      sp, sp, #0x100
//   0x0372b4: A90A6FFC  stp      x28, x27, [sp, #0xa0]
//   0x0372b8: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x0372bc: A90C5FF8  stp      x24, x23, [sp, #0xc0]
static inline uint64_t fde_func_0486_0x0372b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0372b0ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90a6ffcULL) ^ 0x0c0018ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0487 | PC: 0x037b68 | FDE: 0x0c0050 | Size: 256 bytes
// Hàm FDE #0487 | Địa chỉ PC: 0x037b68 | Địa chỉ FDE: 0x0c0050 | Kích thước: 256 bytes
//   0x037b68: D101C3FF  sub      sp, sp, #0x70
//   0x037b6c: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x037b70: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x037b74: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_0487_0x037b68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x037b68ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x0c0050ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0488 | PC: 0x037ee0 | FDE: 0x0c0088 | Size: 256 bytes
// Hàm FDE #0488 | Địa chỉ PC: 0x037ee0 | Địa chỉ FDE: 0x0c0088 | Kích thước: 256 bytes
//   0x037ee0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x037ee4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x037ee8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x037eec: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0488_0x037ee0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x037ee0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c0088ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0489 | PC: 0x037fec | FDE: 0x0bf7f0 | Size: 208 bytes
// Hàm FDE #0489 | Địa chỉ PC: 0x037fec | Địa chỉ FDE: 0x0bf7f0 | Kích thước: 208 bytes
//   0x037fec: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x037ff0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x037ff4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x037ff8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0489_0x037fec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x037fecULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0bf7f0ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #0490 | PC: 0x0380bc | FDE: 0x0c00b0 | Size: 256 bytes
// Hàm FDE #0490 | Địa chỉ PC: 0x0380bc | Địa chỉ FDE: 0x0c00b0 | Kích thước: 256 bytes
//   0x0380bc: D10243FF  sub      sp, sp, #0x90
//   0x0380c0: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0380c4: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0380c8: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0490_0x0380bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0380bcULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x0c00b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0491 | PC: 0x0388a0 | FDE: 0x0bf818 | Size: 256 bytes
// Hàm FDE #0491 | Địa chỉ PC: 0x0388a0 | Địa chỉ FDE: 0x0bf818 | Kích thước: 256 bytes
//   0x0388a0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0388a4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0388a8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0388ac: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0491_0x0388a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0388a0ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0bf818ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0492 | PC: 0x038a04 | FDE: 0x0c00e8 | Size: 256 bytes
// Hàm FDE #0492 | Địa chỉ PC: 0x038a04 | Địa chỉ FDE: 0x0c00e8 | Kích thước: 256 bytes
//   0x038a04: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x038a08: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x038a0c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x038a10: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0492_0x038a04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x038a04ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c00e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0493 | PC: 0x038b8c | FDE: 0x0c0118 | Size: 256 bytes
// Hàm FDE #0493 | Địa chỉ PC: 0x038b8c | Địa chỉ FDE: 0x0c0118 | Kích thước: 256 bytes
//   0x038b8c: D10583FF  sub      sp, sp, #0x160
//   0x038b90: F9008BFC  str      x28, [sp, #0x110]
//   0x038b94: A9125FF8  stp      x24, x23, [sp, #0x120]
//   0x038b98: A91357F6  stp      x22, x21, [sp, #0x130]
static inline uint64_t fde_func_0493_0x038b8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x038b8cULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9008bfcULL) ^ 0x0c0118ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0494 | PC: 0x038d9c | FDE: 0x0c0148 | Size: 256 bytes
// Hàm FDE #0494 | Địa chỉ PC: 0x038d9c | Địa chỉ FDE: 0x0c0148 | Kích thước: 256 bytes
//   0x038d9c: D10583FF  sub      sp, sp, #0x160
//   0x038da0: F9008BFC  str      x28, [sp, #0x110]
//   0x038da4: A9125FF8  stp      x24, x23, [sp, #0x120]
//   0x038da8: A91357F6  stp      x22, x21, [sp, #0x130]
static inline uint64_t fde_func_0494_0x038d9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x038d9cULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9008bfcULL) ^ 0x0c0148ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0495 | PC: 0x038fac | FDE: 0x0c0178 | Size: 256 bytes
// Hàm FDE #0495 | Địa chỉ PC: 0x038fac | Địa chỉ FDE: 0x0c0178 | Kích thước: 256 bytes
//   0x038fac: D10143FF  sub      sp, sp, #0x50
//   0x038fb0: F90013F5  str      x21, [sp, #0x20]
//   0x038fb4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x038fb8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0495_0x038fac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x038facULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x0c0178ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0496 | PC: 0x03910c | FDE: 0x0c01a0 | Size: 256 bytes
// Hàm FDE #0496 | Địa chỉ PC: 0x03910c | Địa chỉ FDE: 0x0c01a0 | Kích thước: 256 bytes
//   0x03910c: D10203FF  sub      sp, sp, #0x80
//   0x039110: F9002BF5  str      x21, [sp, #0x50]
//   0x039114: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x039118: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_0496_0x03910c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03910cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf5ULL) ^ 0x0c01a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0497 | PC: 0x03937c | FDE: 0x0c01c8 | Size: 256 bytes
// Hàm FDE #0497 | Địa chỉ PC: 0x03937c | Địa chỉ FDE: 0x0c01c8 | Kích thước: 256 bytes
//   0x03937c: D10243FF  sub      sp, sp, #0x90
//   0x039380: F90023F9  str      x25, [sp, #0x40]
//   0x039384: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x039388: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_0497_0x03937c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03937cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90023f9ULL) ^ 0x0c01c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0498 | PC: 0x0396e8 | FDE: 0x0c01f8 | Size: 256 bytes
// Hàm FDE #0498 | Địa chỉ PC: 0x0396e8 | Địa chỉ FDE: 0x0c01f8 | Kích thước: 256 bytes
//   0x0396e8: D10703FF  sub      sp, sp, #0x1c0
//   0x0396ec: A9166FFC  stp      x28, x27, [sp, #0x160]
//   0x0396f0: A91767FA  stp      x26, x25, [sp, #0x170]
//   0x0396f4: A9185FF8  stp      x24, x23, [sp, #0x180]
static inline uint64_t fde_func_0498_0x0396e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0396e8ULL ^ (static_cast<uint64_t>(0xd10703ffULL) << 13);
    acc = (acc + a1 + 0xa9166ffcULL) ^ 0x0c01f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0499 | PC: 0x03a3d4 | FDE: 0x0bf840 | Size: 64 bytes
// Hàm FDE #0499 | Địa chỉ PC: 0x03a3d4 | Địa chỉ FDE: 0x0bf840 | Kích thước: 64 bytes
//   0x03a3d4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x03a3d8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03a3dc: 910043FD  add      x29, sp, #0x10
//   0x03a3e0: 9101A014  add      x20, x0, #0x68
static inline uint64_t fde_func_0499_0x03a3d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03a3d4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bf840ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0500 | PC: 0x03a414 | FDE: 0x0bf860 | Size: 56 bytes
// Hàm FDE #0500 | Địa chỉ PC: 0x03a414 | Địa chỉ FDE: 0x0bf860 | Kích thước: 56 bytes
//   0x03a414: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x03a418: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03a41c: 910043FD  add      x29, sp, #0x10
//   0x03a420: 9101A014  add      x20, x0, #0x68
static inline uint64_t fde_func_0500_0x03a414(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03a414ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bf860ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0501 | PC: 0x03a44c | FDE: 0x0bf880 | Size: 256 bytes
// Hàm FDE #0501 | Địa chỉ PC: 0x03a44c | Địa chỉ FDE: 0x0bf880 | Kích thước: 256 bytes
//   0x03a44c: D10103FF  sub      sp, sp, #0x40
//   0x03a450: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x03a454: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x03a458: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0501_0x03a44c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03a44cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0bf880ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0502 | PC: 0x03a6d0 | FDE: 0x0bf8a8 | Size: 8 bytes
// Hàm FDE #0502 | Địa chỉ PC: 0x03a6d0 | Địa chỉ FDE: 0x0bf8a8 | Kích thước: 8 bytes
//   0x03a6d0: B9004801  str      w1, [x0, #0x48]
//   0x03a6d4: D65F03C0  ret      
static inline uint64_t fde_func_0502_0x03a6d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03a6d0ULL ^ (static_cast<uint64_t>(0xb9004801ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0bf8a8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0503 | PC: 0x03a6d8 | FDE: 0x0bf8c0 | Size: 180 bytes
// Hàm FDE #0503 | Địa chỉ PC: 0x03a6d8 | Địa chỉ FDE: 0x0bf8c0 | Kích thước: 180 bytes
//   0x03a6d8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x03a6dc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03a6e0: 910043FD  add      x29, sp, #0x10
//   0x03a6e4: 91014014  add      x20, x0, #0x50
static inline uint64_t fde_func_0503_0x03a6d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03a6d8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bf8c0ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #0504 | PC: 0x03a78c | FDE: 0x0c0230 | Size: 256 bytes
// Hàm FDE #0504 | Địa chỉ PC: 0x03a78c | Địa chỉ FDE: 0x0c0230 | Kích thước: 256 bytes
//   0x03a78c: D10283FF  sub      sp, sp, #0xa0
//   0x03a790: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x03a794: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x03a798: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0504_0x03a78c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03a78cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x0c0230ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0505 | PC: 0x03acc0 | FDE: 0x0c0268 | Size: 256 bytes
// Hàm FDE #0505 | Địa chỉ PC: 0x03acc0 | Địa chỉ FDE: 0x0c0268 | Kích thước: 256 bytes
//   0x03acc0: D10503FF  sub      sp, sp, #0x140
//   0x03acc4: A90F67FC  stp      x28, x25, [sp, #0xf0]
//   0x03acc8: A9105FF8  stp      x24, x23, [sp, #0x100]
//   0x03accc: A91157F6  stp      x22, x21, [sp, #0x110]
static inline uint64_t fde_func_0505_0x03acc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03acc0ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xa90f67fcULL) ^ 0x0c0268ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0506 | PC: 0x03b094 | FDE: 0x0c02a0 | Size: 256 bytes
// Hàm FDE #0506 | Địa chỉ PC: 0x03b094 | Địa chỉ FDE: 0x0c02a0 | Kích thước: 256 bytes
//   0x03b094: D10183FF  sub      sp, sp, #0x60
//   0x03b098: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x03b09c: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x03b0a0: 910143FD  add      x29, sp, #0x50
static inline uint64_t fde_func_0506_0x03b094(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03b094ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9044ff4ULL) ^ 0x0c02a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0507 | PC: 0x03b1cc | FDE: 0x0bf8e0 | Size: 56 bytes
// Hàm FDE #0507 | Địa chỉ PC: 0x03b1cc | Địa chỉ FDE: 0x0bf8e0 | Kích thước: 56 bytes
//   0x03b1cc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x03b1d0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03b1d4: 910043FD  add      x29, sp, #0x10
//   0x03b1d8: B0000568  adrp     x8, #0xe8000
static inline uint64_t fde_func_0507_0x03b1cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03b1ccULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bf8e0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0508 | PC: 0x03b204 | FDE: 0x0bf900 | Size: 256 bytes
// Hàm FDE #0508 | Địa chỉ PC: 0x03b204 | Địa chỉ FDE: 0x0bf900 | Kích thước: 256 bytes
//   0x03b204: D10243FF  sub      sp, sp, #0x90
//   0x03b208: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x03b20c: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x03b210: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0508_0x03b204(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03b204ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x0bf900ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0509 | PC: 0x03b420 | FDE: 0x0bf930 | Size: 256 bytes
// Hàm FDE #0509 | Địa chỉ PC: 0x03b420 | Địa chỉ FDE: 0x0bf930 | Kích thước: 256 bytes
//   0x03b420: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x03b424: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x03b428: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x03b42c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0509_0x03b420(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03b420ULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0bf930ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0510 | PC: 0x03b5ec | FDE: 0x0c02c8 | Size: 256 bytes
// Hàm FDE #0510 | Địa chỉ PC: 0x03b5ec | Địa chỉ FDE: 0x0c02c8 | Kích thước: 256 bytes
//   0x03b5ec: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x03b5f0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x03b5f4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x03b5f8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0510_0x03b5ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03b5ecULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c02c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0511 | PC: 0x03b76c | FDE: 0x0bf960 | Size: 152 bytes
// Hàm FDE #0511 | Địa chỉ PC: 0x03b76c | Địa chỉ FDE: 0x0bf960 | Kích thước: 152 bytes
//   0x03b76c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x03b770: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x03b774: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x03b778: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0511_0x03b76c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03b76cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bf960ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0512 | PC: 0x03b804 | FDE: 0x0c02f8 | Size: 256 bytes
// Hàm FDE #0512 | Địa chỉ PC: 0x03b804 | Địa chỉ FDE: 0x0c02f8 | Kích thước: 256 bytes
//   0x03b804: D10203FF  sub      sp, sp, #0x80
//   0x03b808: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x03b80c: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x03b810: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0512_0x03b804(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03b804ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x0c02f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0513 | PC: 0x03bb64 | FDE: 0x0bf980 | Size: 228 bytes
// Hàm FDE #0513 | Địa chỉ PC: 0x03bb64 | Địa chỉ FDE: 0x0bf980 | Kích thước: 228 bytes
//   0x03bb64: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x03bb68: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x03bb6c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x03bb70: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0513_0x03bb64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03bb64ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bf980ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #0514 | PC: 0x03bc48 | FDE: 0x0bf9a0 | Size: 256 bytes
// Hàm FDE #0514 | Địa chỉ PC: 0x03bc48 | Địa chỉ FDE: 0x0bf9a0 | Kích thước: 256 bytes
//   0x03bc48: D10203FF  sub      sp, sp, #0x80
//   0x03bc4c: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x03bc50: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x03bc54: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0514_0x03bc48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03bc48ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x0bf9a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0515 | PC: 0x03beb8 | FDE: 0x0c0330 | Size: 256 bytes
// Hàm FDE #0515 | Địa chỉ PC: 0x03beb8 | Địa chỉ FDE: 0x0c0330 | Kích thước: 256 bytes
//   0x03beb8: D101C3FF  sub      sp, sp, #0x70
//   0x03bebc: F9000BFB  str      x27, [sp, #0x10]
//   0x03bec0: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x03bec4: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_0515_0x03beb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03beb8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfbULL) ^ 0x0c0330ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0516 | PC: 0x03c084 | FDE: 0x0c0368 | Size: 256 bytes
// Hàm FDE #0516 | Địa chỉ PC: 0x03c084 | Địa chỉ FDE: 0x0c0368 | Kích thước: 256 bytes
//   0x03c084: D10203FF  sub      sp, sp, #0x80
//   0x03c088: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x03c08c: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x03c090: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_0516_0x03c084(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03c084ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90557f6ULL) ^ 0x0c0368ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0517 | PC: 0x03c198 | FDE: 0x0c0398 | Size: 256 bytes
// Hàm FDE #0517 | Địa chỉ PC: 0x03c198 | Địa chỉ FDE: 0x0c0398 | Kích thước: 256 bytes
//   0x03c198: D107C3FF  sub      sp, sp, #0x1f0
//   0x03c19c: A91B5FFC  stp      x28, x23, [sp, #0x1b0]
//   0x03c1a0: A91C57F6  stp      x22, x21, [sp, #0x1c0]
//   0x03c1a4: A91D4FF4  stp      x20, x19, [sp, #0x1d0]
static inline uint64_t fde_func_0517_0x03c198(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03c198ULL ^ (static_cast<uint64_t>(0xd107c3ffULL) << 13);
    acc = (acc + a1 + 0xa91b5ffcULL) ^ 0x0c0398ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0518 | PC: 0x03c76c | FDE: 0x0c03c8 | Size: 216 bytes
// Hàm FDE #0518 | Địa chỉ PC: 0x03c76c | Địa chỉ FDE: 0x0c03c8 | Kích thước: 216 bytes
//   0x03c76c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x03c770: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03c774: 910043FD  add      x29, sp, #0x10
//   0x03c778: 12001C28  and      w8, w1, #0xff
static inline uint64_t fde_func_0518_0x03c76c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03c76cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c03c8ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #0519 | PC: 0x03c844 | FDE: 0x0c03f0 | Size: 256 bytes
// Hàm FDE #0519 | Địa chỉ PC: 0x03c844 | Địa chỉ FDE: 0x0c03f0 | Kích thước: 256 bytes
//   0x03c844: D10203FF  sub      sp, sp, #0x80
//   0x03c848: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x03c84c: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x03c850: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_0519_0x03c844(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03c844ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90557f6ULL) ^ 0x0c03f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0520 | PC: 0x03c9b4 | FDE: 0x0bf9d0 | Size: 56 bytes
// Hàm FDE #0520 | Địa chỉ PC: 0x03c9b4 | Địa chỉ FDE: 0x0bf9d0 | Kích thước: 56 bytes
//   0x03c9b4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x03c9b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03c9bc: 910043FD  add      x29, sp, #0x10
//   0x03c9c0: 90000568  adrp     x8, #0xe8000
static inline uint64_t fde_func_0520_0x03c9b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03c9b4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bf9d0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0521 | PC: 0x03c9ec | FDE: 0x0c0420 | Size: 256 bytes
// Hàm FDE #0521 | Địa chỉ PC: 0x03c9ec | Địa chỉ FDE: 0x0c0420 | Kích thước: 256 bytes
//   0x03c9ec: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x03c9f0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x03c9f4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x03c9f8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0521_0x03c9ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03c9ecULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c0420ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0522 | PC: 0x03cb34 | FDE: 0x0bf9f0 | Size: 256 bytes
// Hàm FDE #0522 | Địa chỉ PC: 0x03cb34 | Địa chỉ FDE: 0x0bf9f0 | Kích thước: 256 bytes
//   0x03cb34: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x03cb38: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x03cb3c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x03cb40: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0522_0x03cb34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03cb34ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bf9f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0523 | PC: 0x03cde0 | FDE: 0x0bfa10 | Size: 256 bytes
// Hàm FDE #0523 | Địa chỉ PC: 0x03cde0 | Địa chỉ FDE: 0x0bfa10 | Kích thước: 256 bytes
//   0x03cde0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x03cde4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x03cde8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x03cdec: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0523_0x03cde0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03cde0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bfa10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0524 | PC: 0x03cee4 | FDE: 0x0bfa38 | Size: 256 bytes
// Hàm FDE #0524 | Địa chỉ PC: 0x03cee4 | Địa chỉ FDE: 0x0bfa38 | Kích thước: 256 bytes
//   0x03cee4: D101C3FF  sub      sp, sp, #0x70
//   0x03cee8: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x03ceec: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x03cef0: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0524_0x03cee4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03cee4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x0bfa38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0525 | PC: 0x03d9b4 | FDE: 0x0bfa68 | Size: 256 bytes
// Hàm FDE #0525 | Địa chỉ PC: 0x03d9b4 | Địa chỉ FDE: 0x0bfa68 | Kích thước: 256 bytes
//   0x03d9b4: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x03d9b8: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x03d9bc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x03d9c0: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0525_0x03d9b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03d9b4ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0bfa68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0526 | PC: 0x03e50c | FDE: 0x0bfa90 | Size: 256 bytes
// Hàm FDE #0526 | Địa chỉ PC: 0x03e50c | Địa chỉ FDE: 0x0bfa90 | Kích thước: 256 bytes
//   0x03e50c: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x03e510: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x03e514: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x03e518: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0526_0x03e50c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03e50cULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0bfa90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0527 | PC: 0x03e654 | FDE: 0x0c0450 | Size: 188 bytes
// Hàm FDE #0527 | Địa chỉ PC: 0x03e654 | Địa chỉ FDE: 0x0c0450 | Kích thước: 188 bytes
//   0x03e654: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x03e658: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x03e65c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x03e660: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0527_0x03e654(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03e654ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c0450ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0528 | PC: 0x03e710 | FDE: 0x0bfab8 | Size: 256 bytes
// Hàm FDE #0528 | Địa chỉ PC: 0x03e710 | Địa chỉ FDE: 0x0bfab8 | Kích thước: 256 bytes
//   0x03e710: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x03e714: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x03e718: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x03e71c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0528_0x03e710(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03e710ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bfab8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0529 | PC: 0x03e838 | FDE: 0x0bfae0 | Size: 256 bytes
// Hàm FDE #0529 | Địa chỉ PC: 0x03e838 | Địa chỉ FDE: 0x0bfae0 | Kích thước: 256 bytes
//   0x03e838: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x03e83c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x03e840: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x03e844: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0529_0x03e838(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03e838ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0bfae0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0530 | PC: 0x03e9d4 | FDE: 0x0c0480 | Size: 256 bytes
// Hàm FDE #0530 | Địa chỉ PC: 0x03e9d4 | Địa chỉ FDE: 0x0c0480 | Kích thước: 256 bytes
//   0x03e9d4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x03e9d8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x03e9dc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x03e9e0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0530_0x03e9d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03e9d4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c0480ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0531 | PC: 0x03eb9c | FDE: 0x0c04b0 | Size: 256 bytes
// Hàm FDE #0531 | Địa chỉ PC: 0x03eb9c | Địa chỉ FDE: 0x0c04b0 | Kích thước: 256 bytes
//   0x03eb9c: D10483FF  sub      sp, sp, #0x120
//   0x03eba0: A90C6FFC  stp      x28, x27, [sp, #0xc0]
//   0x03eba4: A90D67FA  stp      x26, x25, [sp, #0xd0]
//   0x03eba8: A90E5FF8  stp      x24, x23, [sp, #0xe0]
static inline uint64_t fde_func_0531_0x03eb9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03eb9cULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa90c6ffcULL) ^ 0x0c04b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0532 | PC: 0x03f8dc | FDE: 0x0c04e8 | Size: 256 bytes
// Hàm FDE #0532 | Địa chỉ PC: 0x03f8dc | Địa chỉ FDE: 0x0c04e8 | Kích thước: 256 bytes
//   0x03f8dc: D101C3FF  sub      sp, sp, #0x70
//   0x03f8e0: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x03f8e4: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x03f8e8: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0532_0x03f8dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03f8dcULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x0c04e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0533 | PC: 0x03fa50 | FDE: 0x0c0520 | Size: 256 bytes
// Hàm FDE #0533 | Địa chỉ PC: 0x03fa50 | Địa chỉ FDE: 0x0c0520 | Kích thước: 256 bytes
//   0x03fa50: D10483FF  sub      sp, sp, #0x120
//   0x03fa54: F9006BFC  str      x28, [sp, #0xd0]
//   0x03fa58: A90E5FF8  stp      x24, x23, [sp, #0xe0]
//   0x03fa5c: A90F57F6  stp      x22, x21, [sp, #0xf0]
static inline uint64_t fde_func_0533_0x03fa50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03fa50ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xf9006bfcULL) ^ 0x0c0520ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0534 | PC: 0x03fd9c | FDE: 0x0c0550 | Size: 256 bytes
// Hàm FDE #0534 | Địa chỉ PC: 0x03fd9c | Địa chỉ FDE: 0x0c0550 | Kích thước: 256 bytes
//   0x03fd9c: D10343FF  sub      sp, sp, #0xd0
//   0x03fda0: F9004BF7  str      x23, [sp, #0x90]
//   0x03fda4: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x03fda8: A90B4FF4  stp      x20, x19, [sp, #0xb0]
static inline uint64_t fde_func_0534_0x03fd9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03fd9cULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xf9004bf7ULL) ^ 0x0c0550ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0535 | PC: 0x0402a4 | FDE: 0x0bfb08 | Size: 132 bytes
// Hàm FDE #0535 | Địa chỉ PC: 0x0402a4 | Địa chỉ FDE: 0x0bfb08 | Kích thước: 132 bytes
//   0x0402a4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0402a8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0402ac: 910043FD  add      x29, sp, #0x10
//   0x0402b0: 39426001  ldrb     w1, [x0, #0x98]
static inline uint64_t fde_func_0535_0x0402a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0402a4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bfb08ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0536 | PC: 0x040328 | FDE: 0x0c0580 | Size: 256 bytes
// Hàm FDE #0536 | Địa chỉ PC: 0x040328 | Địa chỉ FDE: 0x0c0580 | Kích thước: 256 bytes
//   0x040328: D10483FF  sub      sp, sp, #0x120
//   0x04032c: A90C6FFC  stp      x28, x27, [sp, #0xc0]
//   0x040330: A90D67FA  stp      x26, x25, [sp, #0xd0]
//   0x040334: A90E5FF8  stp      x24, x23, [sp, #0xe0]
static inline uint64_t fde_func_0536_0x040328(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x040328ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa90c6ffcULL) ^ 0x0c0580ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0537 | PC: 0x0410e4 | FDE: 0x0c05b8 | Size: 256 bytes
// Hàm FDE #0537 | Địa chỉ PC: 0x0410e4 | Địa chỉ FDE: 0x0c05b8 | Kích thước: 256 bytes
//   0x0410e4: D101C3FF  sub      sp, sp, #0x70
//   0x0410e8: F90023F5  str      x21, [sp, #0x40]
//   0x0410ec: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0410f0: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0537_0x0410e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0410e4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c05b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0538 | PC: 0x0411e4 | FDE: 0x0bfb28 | Size: 256 bytes
// Hàm FDE #0538 | Địa chỉ PC: 0x0411e4 | Địa chỉ FDE: 0x0bfb28 | Kích thước: 256 bytes
//   0x0411e4: D101C3FF  sub      sp, sp, #0x70
//   0x0411e8: F9002BF3  str      x19, [sp, #0x50]
//   0x0411ec: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x0411f0: 910183FD  add      x29, sp, #0x60
static inline uint64_t fde_func_0538_0x0411e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0411e4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf3ULL) ^ 0x0bfb28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0539 | PC: 0x041304 | FDE: 0x0bfb48 | Size: 256 bytes
// Hàm FDE #0539 | Địa chỉ PC: 0x041304 | Địa chỉ FDE: 0x0bfb48 | Kích thước: 256 bytes
//   0x041304: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x041308: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04130c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x041310: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0539_0x041304(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x041304ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0bfb48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0540 | PC: 0x041464 | FDE: 0x0bfb70 | Size: 256 bytes
// Hàm FDE #0540 | Địa chỉ PC: 0x041464 | Địa chỉ FDE: 0x0bfb70 | Kích thước: 256 bytes
//   0x041464: F9400029  ldr      x9, [x1]
//   0x041468: F940000B  ldr      x11, [x0]
//   0x04146c: B940082C  ldr      w12, [x1, #8]
//   0x041470: B940080A  ldr      w10, [x0, #8]
static inline uint64_t fde_func_0540_0x041464(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x041464ULL ^ (static_cast<uint64_t>(0xf9400029ULL) << 13);
    acc = (acc + a1 + 0xf940000bULL) ^ 0x0bfb70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0541 | PC: 0x04169c | FDE: 0x0c05e0 | Size: 256 bytes
// Hàm FDE #0541 | Địa chỉ PC: 0x04169c | Địa chỉ FDE: 0x0c05e0 | Kích thước: 256 bytes
//   0x04169c: D10243FF  sub      sp, sp, #0x90
//   0x0416a0: F9002BF7  str      x23, [sp, #0x50]
//   0x0416a4: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x0416a8: A9074FF4  stp      x20, x19, [sp, #0x70]
static inline uint64_t fde_func_0541_0x04169c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04169cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf7ULL) ^ 0x0c05e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0542 | PC: 0x041920 | FDE: 0x0bfb88 | Size: 256 bytes
// Hàm FDE #0542 | Địa chỉ PC: 0x041920 | Địa chỉ FDE: 0x0bfb88 | Kích thước: 256 bytes
//   0x041920: D10303FF  sub      sp, sp, #0xc0
//   0x041924: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x041928: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x04192c: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_0542_0x041920(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x041920ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9085ff8ULL) ^ 0x0bfb88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0543 | PC: 0x041bc4 | FDE: 0x0c0610 | Size: 256 bytes
// Hàm FDE #0543 | Địa chỉ PC: 0x041bc4 | Địa chỉ FDE: 0x0c0610 | Kích thước: 256 bytes
//   0x041bc4: D10203FF  sub      sp, sp, #0x80
//   0x041bc8: F90023F7  str      x23, [sp, #0x40]
//   0x041bcc: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x041bd0: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_0543_0x041bc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x041bc4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x0c0610ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0544 | PC: 0x041dd8 | FDE: 0x0c0640 | Size: 256 bytes
// Hàm FDE #0544 | Địa chỉ PC: 0x041dd8 | Địa chỉ FDE: 0x0c0640 | Kích thước: 256 bytes
//   0x041dd8: D10243FF  sub      sp, sp, #0x90
//   0x041ddc: F9002BF7  str      x23, [sp, #0x50]
//   0x041de0: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x041de4: A9074FF4  stp      x20, x19, [sp, #0x70]
static inline uint64_t fde_func_0544_0x041dd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x041dd8ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf7ULL) ^ 0x0c0640ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0545 | PC: 0x042060 | FDE: 0x0bfbb0 | Size: 256 bytes
// Hàm FDE #0545 | Địa chỉ PC: 0x042060 | Địa chỉ FDE: 0x0bfbb0 | Kích thước: 256 bytes
//   0x042060: D10143FF  sub      sp, sp, #0x50
//   0x042064: F90013F5  str      x21, [sp, #0x20]
//   0x042068: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x04206c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0545_0x042060(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x042060ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x0bfbb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0546 | PC: 0x0421b8 | FDE: 0x0c0670 | Size: 256 bytes
// Hàm FDE #0546 | Địa chỉ PC: 0x0421b8 | Địa chỉ FDE: 0x0c0670 | Kích thước: 256 bytes
//   0x0421b8: D10203FF  sub      sp, sp, #0x80
//   0x0421bc: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0421c0: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x0421c4: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_0546_0x0421b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0421b8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90557f6ULL) ^ 0x0c0670ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0547 | PC: 0x042328 | FDE: 0x0c06a0 | Size: 256 bytes
// Hàm FDE #0547 | Địa chỉ PC: 0x042328 | Địa chỉ FDE: 0x0c06a0 | Kích thước: 256 bytes
//   0x042328: D101C3FF  sub      sp, sp, #0x70
//   0x04232c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x042330: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x042334: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0547_0x042328(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x042328ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x0c06a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0548 | PC: 0x042570 | FDE: 0x0bfbd0 | Size: 248 bytes
// Hàm FDE #0548 | Địa chỉ PC: 0x042570 | Địa chỉ FDE: 0x0bfbd0 | Kích thước: 248 bytes
//   0x042570: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x042574: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x042578: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x04257c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0548_0x042570(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x042570ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0bfbd0ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0549 | PC: 0x042668 | FDE: 0x0c06d0 | Size: 256 bytes
// Hàm FDE #0549 | Địa chỉ PC: 0x042668 | Địa chỉ FDE: 0x0c06d0 | Kích thước: 256 bytes
//   0x042668: D10143FF  sub      sp, sp, #0x50
//   0x04266c: F90013F5  str      x21, [sp, #0x20]
//   0x042670: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x042674: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0549_0x042668(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x042668ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x0c06d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0550 | PC: 0x042770 | FDE: 0x0c06f8 | Size: 256 bytes
// Hàm FDE #0550 | Địa chỉ PC: 0x042770 | Địa chỉ FDE: 0x0c06f8 | Kích thước: 256 bytes
//   0x042770: D10203FF  sub      sp, sp, #0x80
//   0x042774: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x042778: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x04277c: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_0550_0x042770(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x042770ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90557f6ULL) ^ 0x0c06f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0551 | PC: 0x0428e0 | FDE: 0x0bfbf8 | Size: 56 bytes
// Hàm FDE #0551 | Địa chỉ PC: 0x0428e0 | Địa chỉ FDE: 0x0bfbf8 | Kích thước: 56 bytes
//   0x0428e0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0428e4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0428e8: 910043FD  add      x29, sp, #0x10
//   0x0428ec: D0000528  adrp     x8, #0xe8000
static inline uint64_t fde_func_0551_0x0428e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0428e0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bfbf8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0552 | PC: 0x042918 | FDE: 0x0c0728 | Size: 244 bytes
// Hàm FDE #0552 | Địa chỉ PC: 0x042918 | Địa chỉ FDE: 0x0c0728 | Kích thước: 244 bytes
//   0x042918: D10143FF  sub      sp, sp, #0x50
//   0x04291c: F9000BF7  str      x23, [sp, #0x10]
//   0x042920: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x042924: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0552_0x042918(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x042918ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x0c0728ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #0553 | PC: 0x042a0c | FDE: 0x0bfc18 | Size: 56 bytes
// Hàm FDE #0553 | Địa chỉ PC: 0x042a0c | Địa chỉ FDE: 0x0bfc18 | Kích thước: 56 bytes
//   0x042a0c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x042a10: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x042a14: 910043FD  add      x29, sp, #0x10
//   0x042a18: D0000528  adrp     x8, #0xe8000
static inline uint64_t fde_func_0553_0x042a0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x042a0cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bfc18ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0554 | PC: 0x042a44 | FDE: 0x0c0758 | Size: 256 bytes
// Hàm FDE #0554 | Địa chỉ PC: 0x042a44 | Địa chỉ FDE: 0x0c0758 | Kích thước: 256 bytes
//   0x042a44: D101C3FF  sub      sp, sp, #0x70
//   0x042a48: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x042a4c: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x042a50: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0554_0x042a44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x042a44ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x0c0758ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0555 | PC: 0x042c88 | FDE: 0x0c0788 | Size: 256 bytes
// Hàm FDE #0555 | Địa chỉ PC: 0x042c88 | Địa chỉ FDE: 0x0c0788 | Kích thước: 256 bytes
//   0x042c88: D101C3FF  sub      sp, sp, #0x70
//   0x042c8c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x042c90: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x042c94: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0555_0x042c88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x042c88ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x0c0788ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0556 | PC: 0x042ecc | FDE: 0x0c07b8 | Size: 256 bytes
// Hàm FDE #0556 | Địa chỉ PC: 0x042ecc | Địa chỉ FDE: 0x0c07b8 | Kích thước: 256 bytes
//   0x042ecc: D101C3FF  sub      sp, sp, #0x70
//   0x042ed0: F90023F5  str      x21, [sp, #0x40]
//   0x042ed4: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x042ed8: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0556_0x042ecc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x042eccULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c07b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0557 | PC: 0x043108 | FDE: 0x0c07e0 | Size: 256 bytes
// Hàm FDE #0557 | Địa chỉ PC: 0x043108 | Địa chỉ FDE: 0x0c07e0 | Kích thước: 256 bytes
//   0x043108: D101C3FF  sub      sp, sp, #0x70
//   0x04310c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x043110: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x043114: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0557_0x043108(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x043108ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x0c07e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0558 | PC: 0x043348 | FDE: 0x0c0810 | Size: 256 bytes
// Hàm FDE #0558 | Địa chỉ PC: 0x043348 | Địa chỉ FDE: 0x0c0810 | Kích thước: 256 bytes
//   0x043348: D10203FF  sub      sp, sp, #0x80
//   0x04334c: F90023F7  str      x23, [sp, #0x40]
//   0x043350: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x043354: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_0558_0x043348(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x043348ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x0c0810ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0559 | PC: 0x0435c4 | FDE: 0x0c0840 | Size: 256 bytes
// Hàm FDE #0559 | Địa chỉ PC: 0x0435c4 | Địa chỉ FDE: 0x0c0840 | Kích thước: 256 bytes
//   0x0435c4: D101C3FF  sub      sp, sp, #0x70
//   0x0435c8: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0435cc: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0435d0: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0559_0x0435c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0435c4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x0c0840ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0560 | PC: 0x043808 | FDE: 0x0bfc38 | Size: 164 bytes
// Hàm FDE #0560 | Địa chỉ PC: 0x043808 | Địa chỉ FDE: 0x0bfc38 | Kích thước: 164 bytes
//   0x043808: D10443FF  sub      sp, sp, #0x110
//   0x04380c: A90F4FFC  stp      x28, x19, [sp, #0xf0]
//   0x043810: A9107BFD  stp      x29, x30, [sp, #0x100]
//   0x043814: 910403FD  add      x29, sp, #0x100
static inline uint64_t fde_func_0560_0x043808(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x043808ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90f4ffcULL) ^ 0x0bfc38ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #0561 | PC: 0x0438ac | FDE: 0x0c0870 | Size: 256 bytes
// Hàm FDE #0561 | Địa chỉ PC: 0x0438ac | Địa chỉ FDE: 0x0c0870 | Kích thước: 256 bytes
//   0x0438ac: D10283FF  sub      sp, sp, #0xa0
//   0x0438b0: F9003BF5  str      x21, [sp, #0x70]
//   0x0438b4: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x0438b8: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_0561_0x0438ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0438acULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf5ULL) ^ 0x0c0870ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0562 | PC: 0x043aac | FDE: 0x0c0898 | Size: 256 bytes
// Hàm FDE #0562 | Địa chỉ PC: 0x043aac | Địa chỉ FDE: 0x0c0898 | Kích thước: 256 bytes
//   0x043aac: D10183FF  sub      sp, sp, #0x60
//   0x043ab0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x043ab4: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x043ab8: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0562_0x043aac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x043aacULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x0c0898ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0563 | PC: 0x043bfc | FDE: 0x0bfc58 | Size: 248 bytes
// Hàm FDE #0563 | Địa chỉ PC: 0x043bfc | Địa chỉ FDE: 0x0bfc58 | Kích thước: 248 bytes
//   0x043bfc: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x043c00: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x043c04: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x043c08: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0563_0x043bfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x043bfcULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0bfc58ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0564 | PC: 0x043cf4 | FDE: 0x0c08c8 | Size: 256 bytes
// Hàm FDE #0564 | Địa chỉ PC: 0x043cf4 | Địa chỉ FDE: 0x0c08c8 | Kích thước: 256 bytes
//   0x043cf4: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x043cf8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x043cfc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x043d00: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0564_0x043cf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x043cf4ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c08c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0565 | PC: 0x043e5c | FDE: 0x0bfc80 | Size: 256 bytes
// Hàm FDE #0565 | Địa chỉ PC: 0x043e5c | Địa chỉ FDE: 0x0bfc80 | Kích thước: 256 bytes
//   0x043e5c: D10143FF  sub      sp, sp, #0x50
//   0x043e60: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x043e64: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x043e68: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0565_0x043e5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x043e5cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x0bfc80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0566 | PC: 0x043f8c | FDE: 0x0bfca0 | Size: 256 bytes
// Hàm FDE #0566 | Địa chỉ PC: 0x043f8c | Địa chỉ FDE: 0x0bfca0 | Kích thước: 256 bytes
//   0x043f8c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x043f90: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x043f94: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x043f98: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0566_0x043f8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x043f8cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0bfca0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0567 | PC: 0x0440d4 | FDE: 0x0bfcc8 | Size: 256 bytes
// Hàm FDE #0567 | Địa chỉ PC: 0x0440d4 | Địa chỉ FDE: 0x0bfcc8 | Kích thước: 256 bytes
//   0x0440d4: D10143FF  sub      sp, sp, #0x50
//   0x0440d8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0440dc: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0440e0: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0567_0x0440d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0440d4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x0bfcc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0568 | PC: 0x044204 | FDE: 0x0bfce8 | Size: 256 bytes
// Hàm FDE #0568 | Địa chỉ PC: 0x044204 | Địa chỉ FDE: 0x0bfce8 | Kích thước: 256 bytes
//   0x044204: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x044208: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04420c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x044210: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0568_0x044204(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x044204ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0bfce8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0569 | PC: 0x04434c | FDE: 0x0bfd10 | Size: 256 bytes
// Hàm FDE #0569 | Địa chỉ PC: 0x04434c | Địa chỉ FDE: 0x0bfd10 | Kích thước: 256 bytes
//   0x04434c: D10143FF  sub      sp, sp, #0x50
//   0x044350: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x044354: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x044358: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0569_0x04434c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04434cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x0bfd10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0570 | PC: 0x044460 | FDE: 0x0bfd30 | Size: 256 bytes
// Hàm FDE #0570 | Địa chỉ PC: 0x044460 | Địa chỉ FDE: 0x0bfd30 | Kích thước: 256 bytes
//   0x044460: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x044464: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x044468: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04446c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0570_0x044460(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x044460ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0bfd30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0571 | PC: 0x04459c | FDE: 0x0bfd58 | Size: 256 bytes
// Hàm FDE #0571 | Địa chỉ PC: 0x04459c | Địa chỉ FDE: 0x0bfd58 | Kích thước: 256 bytes
//   0x04459c: D10143FF  sub      sp, sp, #0x50
//   0x0445a0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0445a4: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0445a8: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0571_0x04459c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04459cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x0bfd58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0572 | PC: 0x0446cc | FDE: 0x0bfd78 | Size: 256 bytes
// Hàm FDE #0572 | Địa chỉ PC: 0x0446cc | Địa chỉ FDE: 0x0bfd78 | Kích thước: 256 bytes
//   0x0446cc: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0446d0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0446d4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0446d8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0572_0x0446cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0446ccULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0bfd78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0573 | PC: 0x044814 | FDE: 0x0c08f8 | Size: 256 bytes
// Hàm FDE #0573 | Địa chỉ PC: 0x044814 | Địa chỉ FDE: 0x0c08f8 | Kích thước: 256 bytes
//   0x044814: D101C3FF  sub      sp, sp, #0x70
//   0x044818: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x04481c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x044820: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0573_0x044814(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x044814ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x0c08f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0574 | PC: 0x0449d0 | FDE: 0x0c0928 | Size: 256 bytes
// Hàm FDE #0574 | Địa chỉ PC: 0x0449d0 | Địa chỉ FDE: 0x0c0928 | Kích thước: 256 bytes
//   0x0449d0: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0449d4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0449d8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0449dc: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0574_0x0449d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0449d0ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c0928ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0575 | PC: 0x044b70 | FDE: 0x0bfda0 | Size: 256 bytes
// Hàm FDE #0575 | Địa chỉ PC: 0x044b70 | Địa chỉ FDE: 0x0bfda0 | Kích thước: 256 bytes
//   0x044b70: D10143FF  sub      sp, sp, #0x50
//   0x044b74: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x044b78: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x044b7c: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0575_0x044b70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x044b70ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x0bfda0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0576 | PC: 0x044ca0 | FDE: 0x0bfdc0 | Size: 256 bytes
// Hàm FDE #0576 | Địa chỉ PC: 0x044ca0 | Địa chỉ FDE: 0x0bfdc0 | Kích thước: 256 bytes
//   0x044ca0: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x044ca4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x044ca8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x044cac: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0576_0x044ca0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x044ca0ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0bfdc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0577 | PC: 0x044de8 | FDE: 0x0c0958 | Size: 256 bytes
// Hàm FDE #0577 | Địa chỉ PC: 0x044de8 | Địa chỉ FDE: 0x0c0958 | Kích thước: 256 bytes
//   0x044de8: D10143FF  sub      sp, sp, #0x50
//   0x044dec: F90013F5  str      x21, [sp, #0x20]
//   0x044df0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x044df4: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0577_0x044de8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x044de8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x0c0958ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0578 | PC: 0x044f04 | FDE: 0x0c0980 | Size: 256 bytes
// Hàm FDE #0578 | Địa chỉ PC: 0x044f04 | Địa chỉ FDE: 0x0c0980 | Kích thước: 256 bytes
//   0x044f04: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x044f08: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x044f0c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x044f10: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0578_0x044f04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x044f04ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c0980ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0579 | PC: 0x045044 | FDE: 0x0c09b0 | Size: 256 bytes
// Hàm FDE #0579 | Địa chỉ PC: 0x045044 | Địa chỉ FDE: 0x0c09b0 | Kích thước: 256 bytes
//   0x045044: D101C3FF  sub      sp, sp, #0x70
//   0x045048: F90023F5  str      x21, [sp, #0x40]
//   0x04504c: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x045050: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0579_0x045044(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x045044ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c09b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0580 | PC: 0x0451c4 | FDE: 0x0c09d8 | Size: 256 bytes
// Hàm FDE #0580 | Địa chỉ PC: 0x0451c4 | Địa chỉ FDE: 0x0c09d8 | Kích thước: 256 bytes
//   0x0451c4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0451c8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0451cc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0451d0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0580_0x0451c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0451c4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c09d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0581 | PC: 0x045304 | FDE: 0x0c0a08 | Size: 256 bytes
// Hàm FDE #0581 | Địa chỉ PC: 0x045304 | Địa chỉ FDE: 0x0c0a08 | Kích thước: 256 bytes
//   0x045304: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x045308: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04530c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x045310: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0581_0x045304(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x045304ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c0a08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0582 | PC: 0x045444 | FDE: 0x0bfde8 | Size: 256 bytes
// Hàm FDE #0582 | Địa chỉ PC: 0x045444 | Địa chỉ FDE: 0x0bfde8 | Kích thước: 256 bytes
//   0x045444: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x045448: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x04544c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x045450: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0582_0x045444(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x045444ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bfde8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0583 | PC: 0x045628 | FDE: 0x0c0a38 | Size: 256 bytes
// Hàm FDE #0583 | Địa chỉ PC: 0x045628 | Địa chỉ FDE: 0x0c0a38 | Kích thước: 256 bytes
//   0x045628: D101C3FF  sub      sp, sp, #0x70
//   0x04562c: F90023F5  str      x21, [sp, #0x40]
//   0x045630: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x045634: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0583_0x045628(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x045628ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c0a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0584 | PC: 0x045780 | FDE: 0x0c0a60 | Size: 256 bytes
// Hàm FDE #0584 | Địa chỉ PC: 0x045780 | Địa chỉ FDE: 0x0c0a60 | Kích thước: 256 bytes
//   0x045780: D101C3FF  sub      sp, sp, #0x70
//   0x045784: F90023F5  str      x21, [sp, #0x40]
//   0x045788: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x04578c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0584_0x045780(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x045780ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c0a60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0585 | PC: 0x045bd8 | FDE: 0x0bfe08 | Size: 256 bytes
// Hàm FDE #0585 | Địa chỉ PC: 0x045bd8 | Địa chỉ FDE: 0x0bfe08 | Kích thước: 256 bytes
//   0x045bd8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x045bdc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x045be0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x045be4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0585_0x045bd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x045bd8ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0bfe08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0586 | PC: 0x045cec | FDE: 0x0c0a88 | Size: 256 bytes
// Hàm FDE #0586 | Địa chỉ PC: 0x045cec | Địa chỉ FDE: 0x0c0a88 | Kích thước: 256 bytes
//   0x045cec: D10243FF  sub      sp, sp, #0x90
//   0x045cf0: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x045cf4: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x045cf8: A9074FF4  stp      x20, x19, [sp, #0x70]
static inline uint64_t fde_func_0586_0x045cec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x045cecULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9055ff8ULL) ^ 0x0c0a88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0587 | PC: 0x045f88 | FDE: 0x0c0ab8 | Size: 256 bytes
// Hàm FDE #0587 | Địa chỉ PC: 0x045f88 | Địa chỉ FDE: 0x0c0ab8 | Kích thước: 256 bytes
//   0x045f88: D101C3FF  sub      sp, sp, #0x70
//   0x045f8c: F90023F5  str      x21, [sp, #0x40]
//   0x045f90: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x045f94: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0587_0x045f88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x045f88ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c0ab8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0588 | PC: 0x046128 | FDE: 0x0c0ae0 | Size: 256 bytes
// Hàm FDE #0588 | Địa chỉ PC: 0x046128 | Địa chỉ FDE: 0x0c0ae0 | Kích thước: 256 bytes
//   0x046128: D101C3FF  sub      sp, sp, #0x70
//   0x04612c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x046130: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x046134: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0588_0x046128(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x046128ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x0c0ae0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0589 | PC: 0x046300 | FDE: 0x0c0b10 | Size: 256 bytes
// Hàm FDE #0589 | Địa chỉ PC: 0x046300 | Địa chỉ FDE: 0x0c0b10 | Kích thước: 256 bytes
//   0x046300: D10243FF  sub      sp, sp, #0x90
//   0x046304: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x046308: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x04630c: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0589_0x046300(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x046300ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x0c0b10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0590 | PC: 0x0466d0 | FDE: 0x0bfe30 | Size: 176 bytes
// Hàm FDE #0590 | Địa chỉ PC: 0x0466d0 | Địa chỉ FDE: 0x0bfe30 | Kích thước: 176 bytes
//   0x0466d0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0466d4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0466d8: 910043FD  add      x29, sp, #0x10
//   0x0466dc: F9400428  ldr      x8, [x1, #8]
static inline uint64_t fde_func_0590_0x0466d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0466d0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bfe30ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #0591 | PC: 0x046780 | FDE: 0x0bfe50 | Size: 256 bytes
// Hàm FDE #0591 | Địa chỉ PC: 0x046780 | Địa chỉ FDE: 0x0bfe50 | Kích thước: 256 bytes
//   0x046780: F9400029  ldr      x9, [x1]
//   0x046784: AA0103EA  mov      x10, x1
//   0x046788: B40000C9  cbz      x9, #0x467a0
//   0x04678c: F9400428  ldr      x8, [x1, #8]
static inline uint64_t fde_func_0591_0x046780(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x046780ULL ^ (static_cast<uint64_t>(0xf9400029ULL) << 13);
    acc = (acc + a1 + 0xaa0103eaULL) ^ 0x0bfe50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0592 | PC: 0x046b30 | FDE: 0x0c0b48 | Size: 256 bytes
// Hàm FDE #0592 | Địa chỉ PC: 0x046b30 | Địa chỉ FDE: 0x0c0b48 | Kích thước: 256 bytes
//   0x046b30: D10143FF  sub      sp, sp, #0x50
//   0x046b34: F90013F5  str      x21, [sp, #0x20]
//   0x046b38: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x046b3c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0592_0x046b30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x046b30ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x0c0b48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0593 | PC: 0x046c90 | FDE: 0x0c0b70 | Size: 256 bytes
// Hàm FDE #0593 | Địa chỉ PC: 0x046c90 | Địa chỉ FDE: 0x0c0b70 | Kích thước: 256 bytes
//   0x046c90: D10303FF  sub      sp, sp, #0xc0
//   0x046c94: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x046c98: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x046c9c: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_0593_0x046c90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x046c90ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9085ff8ULL) ^ 0x0c0b70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0594 | PC: 0x047010 | FDE: 0x0bfe68 | Size: 256 bytes
// Hàm FDE #0594 | Địa chỉ PC: 0x047010 | Địa chỉ FDE: 0x0bfe68 | Kích thước: 256 bytes
//   0x047010: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x047014: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x047018: 910043FD  add      x29, sp, #0x10
//   0x04701c: 39400028  ldrb     w8, [x1]
static inline uint64_t fde_func_0594_0x047010(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x047010ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0bfe68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0595 | PC: 0x047148 | FDE: 0x0c0ba0 | Size: 256 bytes
// Hàm FDE #0595 | Địa chỉ PC: 0x047148 | Địa chỉ FDE: 0x0c0ba0 | Kích thước: 256 bytes
//   0x047148: D10483FF  sub      sp, sp, #0x120
//   0x04714c: A90D67FC  stp      x28, x25, [sp, #0xd0]
//   0x047150: A90E5FF8  stp      x24, x23, [sp, #0xe0]
//   0x047154: A90F57F6  stp      x22, x21, [sp, #0xf0]
static inline uint64_t fde_func_0595_0x047148(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x047148ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa90d67fcULL) ^ 0x0c0ba0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0596 | PC: 0x047710 | FDE: 0x0c0bd8 | Size: 256 bytes
// Hàm FDE #0596 | Địa chỉ PC: 0x047710 | Địa chỉ FDE: 0x0c0bd8 | Kích thước: 256 bytes
//   0x047710: D10343FF  sub      sp, sp, #0xd0
//   0x047714: F90053F5  str      x21, [sp, #0xa0]
//   0x047718: A90B4FF4  stp      x20, x19, [sp, #0xb0]
//   0x04771c: A90C7BFD  stp      x29, x30, [sp, #0xc0]
static inline uint64_t fde_func_0596_0x047710(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x047710ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xf90053f5ULL) ^ 0x0c0bd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0597 | PC: 0x047978 | FDE: 0x0bfe88 | Size: 256 bytes
// Hàm FDE #0597 | Địa chỉ PC: 0x047978 | Địa chỉ FDE: 0x0bfe88 | Kích thước: 256 bytes
//   0x047978: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x04797c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x047980: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x047984: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0597_0x047978(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x047978ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0bfe88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0598 | PC: 0x047d70 | FDE: 0x0c0c00 | Size: 256 bytes
// Hàm FDE #0598 | Địa chỉ PC: 0x047d70 | Địa chỉ FDE: 0x0c0c00 | Kích thước: 256 bytes
//   0x047d70: D10143FF  sub      sp, sp, #0x50
//   0x047d74: F90013F5  str      x21, [sp, #0x20]
//   0x047d78: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x047d7c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0598_0x047d70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x047d70ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x0c0c00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0599 | PC: 0x047e8c | FDE: 0x0c0c28 | Size: 256 bytes
// Hàm FDE #0599 | Địa chỉ PC: 0x047e8c | Địa chỉ FDE: 0x0c0c28 | Kích thước: 256 bytes
//   0x047e8c: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x047e90: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x047e94: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x047e98: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0599_0x047e8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x047e8cULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c0c28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0600 | PC: 0x047f98 | FDE: 0x0c0c58 | Size: 256 bytes
// Hàm FDE #0600 | Địa chỉ PC: 0x047f98 | Địa chỉ FDE: 0x0c0c58 | Kích thước: 256 bytes
//   0x047f98: D10143FF  sub      sp, sp, #0x50
//   0x047f9c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x047fa0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x047fa4: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0600_0x047f98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x047f98ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x0c0c58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0601 | PC: 0x048134 | FDE: 0x0c0c88 | Size: 224 bytes
// Hàm FDE #0601 | Địa chỉ PC: 0x048134 | Địa chỉ FDE: 0x0c0c88 | Kích thước: 224 bytes
//   0x048134: D10143FF  sub      sp, sp, #0x50
//   0x048138: F90013F5  str      x21, [sp, #0x20]
//   0x04813c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x048140: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0601_0x048134(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x048134ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x0c0c88ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #0602 | PC: 0x048214 | FDE: 0x0c0cb0 | Size: 248 bytes
// Hàm FDE #0602 | Địa chỉ PC: 0x048214 | Địa chỉ FDE: 0x0c0cb0 | Kích thước: 248 bytes
//   0x048214: D10143FF  sub      sp, sp, #0x50
//   0x048218: F90013F5  str      x21, [sp, #0x20]
//   0x04821c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x048220: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0602_0x048214(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x048214ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x0c0cb0ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0603 | PC: 0x04830c | FDE: 0x0c0cd8 | Size: 256 bytes
// Hàm FDE #0603 | Địa chỉ PC: 0x04830c | Địa chỉ FDE: 0x0c0cd8 | Kích thước: 256 bytes
//   0x04830c: D101C3FF  sub      sp, sp, #0x70
//   0x048310: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x048314: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x048318: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0603_0x04830c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04830cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x0c0cd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0604 | PC: 0x0484cc | FDE: 0x0c0d08 | Size: 256 bytes
// Hàm FDE #0604 | Địa chỉ PC: 0x0484cc | Địa chỉ FDE: 0x0c0d08 | Kích thước: 256 bytes
//   0x0484cc: D101C3FF  sub      sp, sp, #0x70
//   0x0484d0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0484d4: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0484d8: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0604_0x0484cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0484ccULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x0c0d08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0605 | PC: 0x0486cc | FDE: 0x0c0d38 | Size: 256 bytes
// Hàm FDE #0605 | Địa chỉ PC: 0x0486cc | Địa chỉ FDE: 0x0c0d38 | Kích thước: 256 bytes
//   0x0486cc: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0486d0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0486d4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0486d8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0605_0x0486cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0486ccULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c0d38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0606 | PC: 0x048904 | FDE: 0x0c0d70 | Size: 256 bytes
// Hàm FDE #0606 | Địa chỉ PC: 0x048904 | Địa chỉ FDE: 0x0c0d70 | Kích thước: 256 bytes
//   0x048904: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x048908: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04890c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x048910: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0606_0x048904(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x048904ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c0d70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0607 | PC: 0x048a68 | FDE: 0x0c0da0 | Size: 256 bytes
// Hàm FDE #0607 | Địa chỉ PC: 0x048a68 | Địa chỉ FDE: 0x0c0da0 | Kích thước: 256 bytes
//   0x048a68: D10283FF  sub      sp, sp, #0xa0
//   0x048a6c: F90023FB  str      x27, [sp, #0x40]
//   0x048a70: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x048a74: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0607_0x048a68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x048a68ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90023fbULL) ^ 0x0c0da0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0608 | PC: 0x048e08 | FDE: 0x0bfea8 | Size: 256 bytes
// Hàm FDE #0608 | Địa chỉ PC: 0x048e08 | Địa chỉ FDE: 0x0bfea8 | Kích thước: 256 bytes
//   0x048e08: D101C3FF  sub      sp, sp, #0x70
//   0x048e0c: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x048e10: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x048e14: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0608_0x048e08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x048e08ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x0bfea8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0609 | PC: 0x048fd8 | FDE: 0x0c0dd8 | Size: 256 bytes
// Hàm FDE #0609 | Địa chỉ PC: 0x048fd8 | Địa chỉ FDE: 0x0c0dd8 | Kích thước: 256 bytes
//   0x048fd8: D10143FF  sub      sp, sp, #0x50
//   0x048fdc: F90013F5  str      x21, [sp, #0x20]
//   0x048fe0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x048fe4: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0609_0x048fd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x048fd8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x0c0dd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0610 | PC: 0x0490dc | FDE: 0x0c0e00 | Size: 256 bytes
// Hàm FDE #0610 | Địa chỉ PC: 0x0490dc | Địa chỉ FDE: 0x0c0e00 | Kích thước: 256 bytes
//   0x0490dc: D10283FF  sub      sp, sp, #0xa0
//   0x0490e0: F90033F7  str      x23, [sp, #0x60]
//   0x0490e4: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0490e8: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0610_0x0490dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0490dcULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90033f7ULL) ^ 0x0c0e00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0611 | PC: 0x0493ec | FDE: 0x0c0e30 | Size: 256 bytes
// Hàm FDE #0611 | Địa chỉ PC: 0x0493ec | Địa chỉ FDE: 0x0c0e30 | Kích thước: 256 bytes
//   0x0493ec: D10243FF  sub      sp, sp, #0x90
//   0x0493f0: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x0493f4: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x0493f8: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_0611_0x0493ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0493ecULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90657f6ULL) ^ 0x0c0e30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0612 | PC: 0x0496dc | FDE: 0x0c0e60 | Size: 256 bytes
// Hàm FDE #0612 | Địa chỉ PC: 0x0496dc | Địa chỉ FDE: 0x0c0e60 | Kích thước: 256 bytes
//   0x0496dc: D10243FF  sub      sp, sp, #0x90
//   0x0496e0: F90033F5  str      x21, [sp, #0x60]
//   0x0496e4: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x0496e8: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_0612_0x0496dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0496dcULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90033f5ULL) ^ 0x0c0e60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0613 | PC: 0x049998 | FDE: 0x0bfed8 | Size: 20 bytes
// Hàm FDE #0613 | Địa chỉ PC: 0x049998 | Địa chỉ FDE: 0x0bfed8 | Kích thước: 20 bytes
//   0x049998: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x04999c: 910003FD  mov      x29, sp
//   0x0499a0: 90000320  adrp     x0, #0xad000
//   0x0499a4: 9100AC00  add      x0, x0, #0x2b
static inline uint64_t fde_func_0613_0x049998(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x049998ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0bfed8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0614 | PC: 0x0499ac | FDE: 0x0c0e88 | Size: 256 bytes
// Hàm FDE #0614 | Địa chỉ PC: 0x0499ac | Địa chỉ FDE: 0x0c0e88 | Kích thước: 256 bytes
//   0x0499ac: D10203FF  sub      sp, sp, #0x80
//   0x0499b0: F90023F7  str      x23, [sp, #0x40]
//   0x0499b4: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0499b8: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_0614_0x0499ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0499acULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x0c0e88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0615 | PC: 0x049b38 | FDE: 0x0c0eb8 | Size: 256 bytes
// Hàm FDE #0615 | Địa chỉ PC: 0x049b38 | Địa chỉ FDE: 0x0c0eb8 | Kích thước: 256 bytes
//   0x049b38: D101C3FF  sub      sp, sp, #0x70
//   0x049b3c: F90023F5  str      x21, [sp, #0x40]
//   0x049b40: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x049b44: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0615_0x049b38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x049b38ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c0eb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0616 | PC: 0x049cf0 | FDE: 0x0c0ee0 | Size: 256 bytes
// Hàm FDE #0616 | Địa chỉ PC: 0x049cf0 | Địa chỉ FDE: 0x0c0ee0 | Kích thước: 256 bytes
//   0x049cf0: D10203FF  sub      sp, sp, #0x80
//   0x049cf4: F9002BF5  str      x21, [sp, #0x50]
//   0x049cf8: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x049cfc: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_0616_0x049cf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x049cf0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf5ULL) ^ 0x0c0ee0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0617 | PC: 0x049f60 | FDE: 0x0c0f08 | Size: 256 bytes
// Hàm FDE #0617 | Địa chỉ PC: 0x049f60 | Địa chỉ FDE: 0x0c0f08 | Kích thước: 256 bytes
//   0x049f60: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x049f64: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x049f68: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x049f6c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0617_0x049f60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x049f60ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c0f08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0618 | PC: 0x04a0a0 | FDE: 0x0c0f38 | Size: 256 bytes
// Hàm FDE #0618 | Địa chỉ PC: 0x04a0a0 | Địa chỉ FDE: 0x0c0f38 | Kích thước: 256 bytes
//   0x04a0a0: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x04a0a4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04a0a8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04a0ac: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0618_0x04a0a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04a0a0ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c0f38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0619 | PC: 0x04a1e0 | FDE: 0x0c0f68 | Size: 256 bytes
// Hàm FDE #0619 | Địa chỉ PC: 0x04a1e0 | Địa chỉ FDE: 0x0c0f68 | Kích thước: 256 bytes
//   0x04a1e0: D101C3FF  sub      sp, sp, #0x70
//   0x04a1e4: F90023F5  str      x21, [sp, #0x40]
//   0x04a1e8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x04a1ec: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0619_0x04a1e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04a1e0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c0f68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0620 | PC: 0x04a368 | FDE: 0x0c10b0 | Size: 256 bytes
// Hàm FDE #0620 | Địa chỉ PC: 0x04a368 | Địa chỉ FDE: 0x0c10b0 | Kích thước: 256 bytes
//   0x04a368: D10483FF  sub      sp, sp, #0x120
//   0x04a36c: F9006BFC  str      x28, [sp, #0xd0]
//   0x04a370: A90E5FF8  stp      x24, x23, [sp, #0xe0]
//   0x04a374: A90F57F6  stp      x22, x21, [sp, #0xf0]
static inline uint64_t fde_func_0620_0x04a368(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04a368ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xf9006bfcULL) ^ 0x0c10b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0621 | PC: 0x04a8cc | FDE: 0x0c10e0 | Size: 256 bytes
// Hàm FDE #0621 | Địa chỉ PC: 0x04a8cc | Địa chỉ FDE: 0x0c10e0 | Kích thước: 256 bytes
//   0x04a8cc: D10343FF  sub      sp, sp, #0xd0
//   0x04a8d0: A9095FF8  stp      x24, x23, [sp, #0x90]
//   0x04a8d4: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x04a8d8: A90B4FF4  stp      x20, x19, [sp, #0xb0]
static inline uint64_t fde_func_0621_0x04a8cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04a8ccULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9095ff8ULL) ^ 0x0c10e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0622 | PC: 0x04b4a4 | FDE: 0x0c0f90 | Size: 148 bytes
// Hàm FDE #0622 | Địa chỉ PC: 0x04b4a4 | Địa chỉ FDE: 0x0c0f90 | Kích thước: 148 bytes
//   0x04b4a4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x04b4a8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x04b4ac: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x04b4b0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0622_0x04b4a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04b4a4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c0f90ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0623 | PC: 0x04b538 | FDE: 0x0c1110 | Size: 256 bytes
// Hàm FDE #0623 | Địa chỉ PC: 0x04b538 | Địa chỉ FDE: 0x0c1110 | Kích thước: 256 bytes
//   0x04b538: D10183FF  sub      sp, sp, #0x60
//   0x04b53c: F9001BF5  str      x21, [sp, #0x30]
//   0x04b540: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x04b544: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0623_0x04b538(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04b538ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x0c1110ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0624 | PC: 0x04b704 | FDE: 0x0c1138 | Size: 256 bytes
// Hàm FDE #0624 | Địa chỉ PC: 0x04b704 | Địa chỉ FDE: 0x0c1138 | Kích thước: 256 bytes
//   0x04b704: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x04b708: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04b70c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04b710: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0624_0x04b704(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04b704ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c1138ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0625 | PC: 0x04b844 | FDE: 0x0c1168 | Size: 256 bytes
// Hàm FDE #0625 | Địa chỉ PC: 0x04b844 | Địa chỉ FDE: 0x0c1168 | Kích thước: 256 bytes
//   0x04b844: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x04b848: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04b84c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04b850: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0625_0x04b844(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04b844ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c1168ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0626 | PC: 0x04b984 | FDE: 0x0c1198 | Size: 256 bytes
// Hàm FDE #0626 | Địa chỉ PC: 0x04b984 | Địa chỉ FDE: 0x0c1198 | Kích thước: 256 bytes
//   0x04b984: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x04b988: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x04b98c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x04b990: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0626_0x04b984(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04b984ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c1198ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0627 | PC: 0x04baec | FDE: 0x0c11c0 | Size: 256 bytes
// Hàm FDE #0627 | Địa chỉ PC: 0x04baec | Địa chỉ FDE: 0x0c11c0 | Kích thước: 256 bytes
//   0x04baec: D101C3FF  sub      sp, sp, #0x70
//   0x04baf0: F90023F5  str      x21, [sp, #0x40]
//   0x04baf4: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x04baf8: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0627_0x04baec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04baecULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c11c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0628 | PC: 0x04bc44 | FDE: 0x0c11e8 | Size: 256 bytes
// Hàm FDE #0628 | Địa chỉ PC: 0x04bc44 | Địa chỉ FDE: 0x0c11e8 | Kích thước: 256 bytes
//   0x04bc44: D10243FF  sub      sp, sp, #0x90
//   0x04bc48: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x04bc4c: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x04bc50: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_0628_0x04bc44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04bc44ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90657f6ULL) ^ 0x0c11e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0629 | PC: 0x04be10 | FDE: 0x0c1218 | Size: 256 bytes
// Hàm FDE #0629 | Địa chỉ PC: 0x04be10 | Địa chỉ FDE: 0x0c1218 | Kích thước: 256 bytes
//   0x04be10: D103C3FF  sub      sp, sp, #0xf0
//   0x04be14: F90053F9  str      x25, [sp, #0xa0]
//   0x04be18: A90B5FF8  stp      x24, x23, [sp, #0xb0]
//   0x04be1c: A90C57F6  stp      x22, x21, [sp, #0xc0]
static inline uint64_t fde_func_0629_0x04be10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04be10ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xf90053f9ULL) ^ 0x0c1218ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0630 | PC: 0x04c124 | FDE: 0x0c1248 | Size: 256 bytes
// Hàm FDE #0630 | Địa chỉ PC: 0x04c124 | Địa chỉ FDE: 0x0c1248 | Kích thước: 256 bytes
//   0x04c124: D101C3FF  sub      sp, sp, #0x70
//   0x04c128: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x04c12c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x04c130: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0630_0x04c124(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04c124ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x0c1248ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0631 | PC: 0x04c538 | FDE: 0x0c0ff8 | Size: 256 bytes
// Hàm FDE #0631 | Địa chỉ PC: 0x04c538 | Địa chỉ FDE: 0x0c0ff8 | Kích thước: 256 bytes
//   0x04c538: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x04c53c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x04c540: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x04c544: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0631_0x04c538(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04c538ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c0ff8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0632 | PC: 0x04c704 | FDE: 0x0c1020 | Size: 256 bytes
// Hàm FDE #0632 | Địa chỉ PC: 0x04c704 | Địa chỉ FDE: 0x0c1020 | Kích thước: 256 bytes
//   0x04c704: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x04c708: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x04c70c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x04c710: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0632_0x04c704(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04c704ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c1020ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0633 | PC: 0x04ca70 | FDE: 0x0c1048 | Size: 256 bytes
// Hàm FDE #0633 | Địa chỉ PC: 0x04ca70 | Địa chỉ FDE: 0x0c1048 | Kích thước: 256 bytes
//   0x04ca70: AA0003E8  mov      x8, x0
//   0x04ca74: F9400009  ldr      x9, [x0]
//   0x04ca78: F9400420  ldr      x0, [x1, #8]
//   0x04ca7c: EB02012A  subs     x10, x9, x2
static inline uint64_t fde_func_0633_0x04ca70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04ca70ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xf9400009ULL) ^ 0x0c1048ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0634 | PC: 0x04cca8 | FDE: 0x0c1060 | Size: 256 bytes
// Hàm FDE #0634 | Địa chỉ PC: 0x04cca8 | Địa chỉ FDE: 0x0c1060 | Kích thước: 256 bytes
//   0x04cca8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x04ccac: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x04ccb0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x04ccb4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0634_0x04cca8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04cca8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c1060ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0635 | PC: 0x04cde4 | FDE: 0x0c1278 | Size: 256 bytes
// Hàm FDE #0635 | Địa chỉ PC: 0x04cde4 | Địa chỉ FDE: 0x0c1278 | Kích thước: 256 bytes
//   0x04cde4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x04cde8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04cdec: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04cdf0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0635_0x04cde4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04cde4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c1278ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0636 | PC: 0x04cf24 | FDE: 0x0c1088 | Size: 256 bytes
// Hàm FDE #0636 | Địa chỉ PC: 0x04cf24 | Địa chỉ FDE: 0x0c1088 | Kích thước: 256 bytes
//   0x04cf24: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x04cf28: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x04cf2c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x04cf30: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0636_0x04cf24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04cf24ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c1088ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0637 | PC: 0x04d0b8 | FDE: 0x0c12a8 | Size: 256 bytes
// Hàm FDE #0637 | Địa chỉ PC: 0x04d0b8 | Địa chỉ FDE: 0x0c12a8 | Kích thước: 256 bytes
//   0x04d0b8: D101C3FF  sub      sp, sp, #0x70
//   0x04d0bc: F90023F5  str      x21, [sp, #0x40]
//   0x04d0c0: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x04d0c4: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0637_0x04d0b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04d0b8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c12a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0638 | PC: 0x04d22c | FDE: 0x0c12d0 | Size: 256 bytes
// Hàm FDE #0638 | Địa chỉ PC: 0x04d22c | Địa chỉ FDE: 0x0c12d0 | Kích thước: 256 bytes
//   0x04d22c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x04d230: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04d234: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04d238: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0638_0x04d22c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04d22cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c12d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0639 | PC: 0x04d36c | FDE: 0x0c1300 | Size: 256 bytes
// Hàm FDE #0639 | Địa chỉ PC: 0x04d36c | Địa chỉ FDE: 0x0c1300 | Kích thước: 256 bytes
//   0x04d36c: D101C3FF  sub      sp, sp, #0x70
//   0x04d370: F90023F5  str      x21, [sp, #0x40]
//   0x04d374: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x04d378: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0639_0x04d36c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04d36cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c1300ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0640 | PC: 0x04d4c4 | FDE: 0x0c13b8 | Size: 256 bytes
// Hàm FDE #0640 | Địa chỉ PC: 0x04d4c4 | Địa chỉ FDE: 0x0c13b8 | Kích thước: 256 bytes
//   0x04d4c4: D10303FF  sub      sp, sp, #0xc0
//   0x04d4c8: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x04d4cc: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x04d4d0: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_0640_0x04d4c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04d4c4ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9085ff8ULL) ^ 0x0c13b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0641 | PC: 0x04d850 | FDE: 0x0c13e8 | Size: 256 bytes
// Hàm FDE #0641 | Địa chỉ PC: 0x04d850 | Địa chỉ FDE: 0x0c13e8 | Kích thước: 256 bytes
//   0x04d850: D10203FF  sub      sp, sp, #0x80
//   0x04d854: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x04d858: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x04d85c: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_0641_0x04d850(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04d850ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9045ff8ULL) ^ 0x0c13e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0642 | PC: 0x04dedc | FDE: 0x0c1418 | Size: 256 bytes
// Hàm FDE #0642 | Địa chỉ PC: 0x04dedc | Địa chỉ FDE: 0x0c1418 | Kích thước: 256 bytes
//   0x04dedc: D10183FF  sub      sp, sp, #0x60
//   0x04dee0: F9001BF5  str      x21, [sp, #0x30]
//   0x04dee4: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x04dee8: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0642_0x04dedc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04dedcULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x0c1418ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0643 | PC: 0x04e138 | FDE: 0x0c1440 | Size: 256 bytes
// Hàm FDE #0643 | Địa chỉ PC: 0x04e138 | Địa chỉ FDE: 0x0c1440 | Kích thước: 256 bytes
//   0x04e138: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x04e13c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04e140: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04e144: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0643_0x04e138(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04e138ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c1440ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0644 | PC: 0x04e25c | FDE: 0x0c1470 | Size: 256 bytes
// Hàm FDE #0644 | Địa chỉ PC: 0x04e25c | Địa chỉ FDE: 0x0c1470 | Kích thước: 256 bytes
//   0x04e25c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x04e260: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x04e264: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x04e268: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0644_0x04e25c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04e25cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c1470ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0645 | PC: 0x04e458 | FDE: 0x0c14a0 | Size: 256 bytes
// Hàm FDE #0645 | Địa chỉ PC: 0x04e458 | Địa chỉ FDE: 0x0c14a0 | Kích thước: 256 bytes
//   0x04e458: D101C3FF  sub      sp, sp, #0x70
//   0x04e45c: F90023F5  str      x21, [sp, #0x40]
//   0x04e460: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x04e464: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0645_0x04e458(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04e458ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c14a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0646 | PC: 0x04e5b0 | FDE: 0x0c14c8 | Size: 256 bytes
// Hàm FDE #0646 | Địa chỉ PC: 0x04e5b0 | Địa chỉ FDE: 0x0c14c8 | Kích thước: 256 bytes
//   0x04e5b0: D10243FF  sub      sp, sp, #0x90
//   0x04e5b4: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x04e5b8: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x04e5bc: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_0646_0x04e5b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04e5b0ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90657f6ULL) ^ 0x0c14c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0647 | PC: 0x04e7ac | FDE: 0x0c1368 | Size: 256 bytes
// Hàm FDE #0647 | Địa chỉ PC: 0x04e7ac | Địa chỉ FDE: 0x0c1368 | Kích thước: 256 bytes
//   0x04e7ac: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x04e7b0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x04e7b4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x04e7b8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0647_0x04e7ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04e7acULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c1368ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0648 | PC: 0x04e8c4 | FDE: 0x0c14f8 | Size: 256 bytes
// Hàm FDE #0648 | Địa chỉ PC: 0x04e8c4 | Địa chỉ FDE: 0x0c14f8 | Kích thước: 256 bytes
//   0x04e8c4: D10183FF  sub      sp, sp, #0x60
//   0x04e8c8: F90013F7  str      x23, [sp, #0x20]
//   0x04e8cc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x04e8d0: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0648_0x04e8c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04e8c4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x0c14f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0649 | PC: 0x04ea14 | FDE: 0x0c1528 | Size: 256 bytes
// Hàm FDE #0649 | Địa chỉ PC: 0x04ea14 | Địa chỉ FDE: 0x0c1528 | Kích thước: 256 bytes
//   0x04ea14: D10203FF  sub      sp, sp, #0x80
//   0x04ea18: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x04ea1c: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x04ea20: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_0649_0x04ea14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04ea14ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90367faULL) ^ 0x0c1528ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0650 | PC: 0x04edf0 | FDE: 0x0c1390 | Size: 256 bytes
// Hàm FDE #0650 | Địa chỉ PC: 0x04edf0 | Địa chỉ FDE: 0x0c1390 | Kích thước: 256 bytes
//   0x04edf0: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x04edf4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x04edf8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x04edfc: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0650_0x04edf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04edf0ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c1390ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0651 | PC: 0x04f030 | FDE: 0x0c15a0 | Size: 256 bytes
// Hàm FDE #0651 | Địa chỉ PC: 0x04f030 | Địa chỉ FDE: 0x0c15a0 | Kích thước: 256 bytes
//   0x04f030: D10303FF  sub      sp, sp, #0xc0
//   0x04f034: F90043F7  str      x23, [sp, #0x80]
//   0x04f038: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x04f03c: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_0651_0x04f030(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f030ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf90043f7ULL) ^ 0x0c15a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0652 | PC: 0x04f38c | FDE: 0x0c15d0 | Size: 256 bytes
// Hàm FDE #0652 | Địa chỉ PC: 0x04f38c | Địa chỉ FDE: 0x0c15d0 | Kích thước: 256 bytes
//   0x04f38c: D101C3FF  sub      sp, sp, #0x70
//   0x04f390: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x04f394: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x04f398: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0652_0x04f38c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f38cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x0c15d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0653 | PC: 0x04f870 | FDE: 0x0c1600 | Size: 256 bytes
// Hàm FDE #0653 | Địa chỉ PC: 0x04f870 | Địa chỉ FDE: 0x0c1600 | Kích thước: 256 bytes
//   0x04f870: D10183FF  sub      sp, sp, #0x60
//   0x04f874: F9001BF5  str      x21, [sp, #0x30]
//   0x04f878: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x04f87c: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0653_0x04f870(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f870ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x0c1600ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0654 | PC: 0x04facc | FDE: 0x0c1628 | Size: 256 bytes
// Hàm FDE #0654 | Địa chỉ PC: 0x04facc | Địa chỉ FDE: 0x0c1628 | Kích thước: 256 bytes
//   0x04facc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x04fad0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x04fad4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x04fad8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0654_0x04facc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04faccULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c1628ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0655 | PC: 0x04fcc8 | FDE: 0x0c1758 | Size: 256 bytes
// Hàm FDE #0655 | Địa chỉ PC: 0x04fcc8 | Địa chỉ FDE: 0x0c1758 | Kích thước: 256 bytes
//   0x04fcc8: D102C3FF  sub      sp, sp, #0xb0
//   0x04fccc: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x04fcd0: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x04fcd4: A9094FF4  stp      x20, x19, [sp, #0x90]
static inline uint64_t fde_func_0655_0x04fcc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04fcc8ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9075ff8ULL) ^ 0x0c1758ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0656 | PC: 0x04ffb8 | FDE: 0x0c1788 | Size: 256 bytes
// Hàm FDE #0656 | Địa chỉ PC: 0x04ffb8 | Địa chỉ FDE: 0x0c1788 | Kích thước: 256 bytes
//   0x04ffb8: D10203FF  sub      sp, sp, #0x80
//   0x04ffbc: F90023F7  str      x23, [sp, #0x40]
//   0x04ffc0: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x04ffc4: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_0656_0x04ffb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04ffb8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x0c1788ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0657 | PC: 0x050470 | FDE: 0x0c17b8 | Size: 256 bytes
// Hàm FDE #0657 | Địa chỉ PC: 0x050470 | Địa chỉ FDE: 0x0c17b8 | Kích thước: 256 bytes
//   0x050470: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x050474: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x050478: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05047c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0657_0x050470(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x050470ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c17b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0658 | PC: 0x050574 | FDE: 0x0c17e8 | Size: 256 bytes
// Hàm FDE #0658 | Địa chỉ PC: 0x050574 | Địa chỉ FDE: 0x0c17e8 | Kích thước: 256 bytes
//   0x050574: D101C3FF  sub      sp, sp, #0x70
//   0x050578: F90023F5  str      x21, [sp, #0x40]
//   0x05057c: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x050580: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0658_0x050574(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x050574ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c17e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0659 | PC: 0x0506cc | FDE: 0x0c1810 | Size: 256 bytes
// Hàm FDE #0659 | Địa chỉ PC: 0x0506cc | Địa chỉ FDE: 0x0c1810 | Kích thước: 256 bytes
//   0x0506cc: D10243FF  sub      sp, sp, #0x90
//   0x0506d0: F90033F5  str      x21, [sp, #0x60]
//   0x0506d4: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x0506d8: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_0659_0x0506cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0506ccULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90033f5ULL) ^ 0x0c1810ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0660 | PC: 0x050850 | FDE: 0x0c1678 | Size: 256 bytes
// Hàm FDE #0660 | Địa chỉ PC: 0x050850 | Địa chỉ FDE: 0x0c1678 | Kích thước: 256 bytes
//   0x050850: D101C3FF  sub      sp, sp, #0x70
//   0x050854: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x050858: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x05085c: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0660_0x050850(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x050850ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x0c1678ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0661 | PC: 0x050a10 | FDE: 0x0c1838 | Size: 256 bytes
// Hàm FDE #0661 | Địa chỉ PC: 0x050a10 | Địa chỉ FDE: 0x0c1838 | Kích thước: 256 bytes
//   0x050a10: D10303FF  sub      sp, sp, #0xc0
//   0x050a14: F90043F7  str      x23, [sp, #0x80]
//   0x050a18: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x050a1c: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_0661_0x050a10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x050a10ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf90043f7ULL) ^ 0x0c1838ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0662 | PC: 0x050bfc | FDE: 0x0c16a0 | Size: 172 bytes
// Hàm FDE #0662 | Địa chỉ PC: 0x050bfc | Địa chỉ FDE: 0x0c16a0 | Kích thước: 172 bytes
//   0x050bfc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x050c00: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x050c04: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x050c08: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0662_0x050bfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x050bfcULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c16a0ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #0663 | PC: 0x050ca8 | FDE: 0x0c1868 | Size: 256 bytes
// Hàm FDE #0663 | Địa chỉ PC: 0x050ca8 | Địa chỉ FDE: 0x0c1868 | Kích thước: 256 bytes
//   0x050ca8: D101C3FF  sub      sp, sp, #0x70
//   0x050cac: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x050cb0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x050cb4: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0663_0x050ca8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x050ca8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x0c1868ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0664 | PC: 0x050ff0 | FDE: 0x0c16c8 | Size: 256 bytes
// Hàm FDE #0664 | Địa chỉ PC: 0x050ff0 | Địa chỉ FDE: 0x0c16c8 | Kích thước: 256 bytes
//   0x050ff0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x050ff4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x050ff8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x050ffc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0664_0x050ff0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x050ff0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c16c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0665 | PC: 0x0511b8 | FDE: 0x0c16f0 | Size: 256 bytes
// Hàm FDE #0665 | Địa chỉ PC: 0x0511b8 | Địa chỉ FDE: 0x0c16f0 | Kích thước: 256 bytes
//   0x0511b8: D10243FF  sub      sp, sp, #0x90
//   0x0511bc: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0511c0: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0511c4: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0665_0x0511b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0511b8ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x0c16f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0666 | PC: 0x0514d4 | FDE: 0x0c1720 | Size: 256 bytes
// Hàm FDE #0666 | Địa chỉ PC: 0x0514d4 | Địa chỉ FDE: 0x0c1720 | Kích thước: 256 bytes
//   0x0514d4: AA0003E8  mov      x8, x0
//   0x0514d8: F940000A  ldr      x10, [x0]
//   0x0514dc: F9400420  ldr      x0, [x1, #8]
//   0x0514e0: EB02015F  cmp      x10, x2
static inline uint64_t fde_func_0666_0x0514d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0514d4ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xf940000aULL) ^ 0x0c1720ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0667 | PC: 0x0516a8 | FDE: 0x0c1898 | Size: 256 bytes
// Hàm FDE #0667 | Địa chỉ PC: 0x0516a8 | Địa chỉ FDE: 0x0c1898 | Kích thước: 256 bytes
//   0x0516a8: D10243FF  sub      sp, sp, #0x90
//   0x0516ac: F9002BF7  str      x23, [sp, #0x50]
//   0x0516b0: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x0516b4: A9074FF4  stp      x20, x19, [sp, #0x70]
static inline uint64_t fde_func_0667_0x0516a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0516a8ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf7ULL) ^ 0x0c1898ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0668 | PC: 0x0518e0 | FDE: 0x0c18c8 | Size: 256 bytes
// Hàm FDE #0668 | Địa chỉ PC: 0x0518e0 | Địa chỉ FDE: 0x0c18c8 | Kích thước: 256 bytes
//   0x0518e0: D101C3FF  sub      sp, sp, #0x70
//   0x0518e4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0518e8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0518ec: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0668_0x0518e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0518e0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x0c18c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0669 | PC: 0x051cbc | FDE: 0x0c18f8 | Size: 256 bytes
// Hàm FDE #0669 | Địa chỉ PC: 0x051cbc | Địa chỉ FDE: 0x0c18f8 | Kích thước: 256 bytes
//   0x051cbc: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x051cc0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x051cc4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x051cc8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0669_0x051cbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051cbcULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c18f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0670 | PC: 0x051dfc | FDE: 0x0c1928 | Size: 256 bytes
// Hàm FDE #0670 | Địa chỉ PC: 0x051dfc | Địa chỉ FDE: 0x0c1928 | Kích thước: 256 bytes
//   0x051dfc: D10203FF  sub      sp, sp, #0x80
//   0x051e00: F90023F7  str      x23, [sp, #0x40]
//   0x051e04: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x051e08: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_0670_0x051dfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051dfcULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x0c1928ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0671 | PC: 0x051fac | FDE: 0x0c1958 | Size: 256 bytes
// Hàm FDE #0671 | Địa chỉ PC: 0x051fac | Địa chỉ FDE: 0x0c1958 | Kích thước: 256 bytes
//   0x051fac: D101C3FF  sub      sp, sp, #0x70
//   0x051fb0: F90023F5  str      x21, [sp, #0x40]
//   0x051fb4: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x051fb8: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0671_0x051fac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051facULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c1958ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0672 | PC: 0x0521b4 | FDE: 0x0c1980 | Size: 256 bytes
// Hàm FDE #0672 | Địa chỉ PC: 0x0521b4 | Địa chỉ FDE: 0x0c1980 | Kích thước: 256 bytes
//   0x0521b4: D10303FF  sub      sp, sp, #0xc0
//   0x0521b8: F90043F7  str      x23, [sp, #0x80]
//   0x0521bc: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x0521c0: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_0672_0x0521b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0521b4ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf90043f7ULL) ^ 0x0c1980ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0673 | PC: 0x052538 | FDE: 0x0c19b0 | Size: 256 bytes
// Hàm FDE #0673 | Địa chỉ PC: 0x052538 | Địa chỉ FDE: 0x0c19b0 | Kích thước: 256 bytes
//   0x052538: D101C3FF  sub      sp, sp, #0x70
//   0x05253c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x052540: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x052544: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0673_0x052538(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x052538ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x0c19b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0674 | PC: 0x052af8 | FDE: 0x0c19e0 | Size: 256 bytes
// Hàm FDE #0674 | Địa chỉ PC: 0x052af8 | Địa chỉ FDE: 0x0c19e0 | Kích thước: 256 bytes
//   0x052af8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x052afc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x052b00: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x052b04: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0674_0x052af8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x052af8ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c19e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0675 | PC: 0x052c38 | FDE: 0x0c1ba0 | Size: 256 bytes
// Hàm FDE #0675 | Địa chỉ PC: 0x052c38 | Địa chỉ FDE: 0x0c1ba0 | Kích thước: 256 bytes
//   0x052c38: D10403FF  sub      sp, sp, #0x100
//   0x052c3c: A90C5FF8  stp      x24, x23, [sp, #0xc0]
//   0x052c40: A90D57F6  stp      x22, x21, [sp, #0xd0]
//   0x052c44: A90E4FF4  stp      x20, x19, [sp, #0xe0]
static inline uint64_t fde_func_0675_0x052c38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x052c38ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90c5ff8ULL) ^ 0x0c1ba0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0676 | PC: 0x05318c | FDE: 0x0c1bd0 | Size: 256 bytes
// Hàm FDE #0676 | Địa chỉ PC: 0x05318c | Địa chỉ FDE: 0x0c1bd0 | Kích thước: 256 bytes
//   0x05318c: D103C3FF  sub      sp, sp, #0xf0
//   0x053190: A90B5FF8  stp      x24, x23, [sp, #0xb0]
//   0x053194: A90C57F6  stp      x22, x21, [sp, #0xc0]
//   0x053198: A90D4FF4  stp      x20, x19, [sp, #0xd0]
static inline uint64_t fde_func_0676_0x05318c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05318cULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa90b5ff8ULL) ^ 0x0c1bd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0677 | PC: 0x053c08 | FDE: 0x0c1c00 | Size: 248 bytes
// Hàm FDE #0677 | Địa chỉ PC: 0x053c08 | Địa chỉ FDE: 0x0c1c00 | Kích thước: 248 bytes
//   0x053c08: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x053c0c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x053c10: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x053c14: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0677_0x053c08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x053c08ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c1c00ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0678 | PC: 0x053d00 | FDE: 0x0c1a10 | Size: 256 bytes
// Hàm FDE #0678 | Địa chỉ PC: 0x053d00 | Địa chỉ FDE: 0x0c1a10 | Kích thước: 256 bytes
//   0x053d00: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x053d04: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x053d08: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x053d0c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0678_0x053d00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x053d00ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c1a10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0679 | PC: 0x053e4c | FDE: 0x0c1a38 | Size: 256 bytes
// Hàm FDE #0679 | Địa chỉ PC: 0x053e4c | Địa chỉ FDE: 0x0c1a38 | Kích thước: 256 bytes
//   0x053e4c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x053e50: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x053e54: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x053e58: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0679_0x053e4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x053e4cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c1a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0680 | PC: 0x053f70 | FDE: 0x0c1a60 | Size: 148 bytes
// Hàm FDE #0680 | Địa chỉ PC: 0x053f70 | Địa chỉ FDE: 0x0c1a60 | Kích thước: 148 bytes
//   0x053f70: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x053f74: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x053f78: 910043FD  add      x29, sp, #0x10
//   0x053f7c: 39422028  ldrb     w8, [x1, #0x88]
static inline uint64_t fde_func_0680_0x053f70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x053f70ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c1a60ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0681 | PC: 0x054004 | FDE: 0x0c1c30 | Size: 256 bytes
// Hàm FDE #0681 | Địa chỉ PC: 0x054004 | Địa chỉ FDE: 0x0c1c30 | Kích thước: 256 bytes
//   0x054004: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x054008: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05400c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x054010: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0681_0x054004(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x054004ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c1c30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0682 | PC: 0x054110 | FDE: 0x0c1c60 | Size: 256 bytes
// Hàm FDE #0682 | Địa chỉ PC: 0x054110 | Địa chỉ FDE: 0x0c1c60 | Kích thước: 256 bytes
//   0x054110: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x054114: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x054118: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05411c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0682_0x054110(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x054110ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c1c60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0683 | PC: 0x054250 | FDE: 0x0c1c90 | Size: 256 bytes
// Hàm FDE #0683 | Địa chỉ PC: 0x054250 | Địa chỉ FDE: 0x0c1c90 | Kích thước: 256 bytes
//   0x054250: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x054254: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x054258: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05425c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0683_0x054250(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x054250ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c1c90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0684 | PC: 0x054390 | FDE: 0x0c1cc0 | Size: 256 bytes
// Hàm FDE #0684 | Địa chỉ PC: 0x054390 | Địa chỉ FDE: 0x0c1cc0 | Kích thước: 256 bytes
//   0x054390: D101C3FF  sub      sp, sp, #0x70
//   0x054394: F90023F5  str      x21, [sp, #0x40]
//   0x054398: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x05439c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0684_0x054390(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x054390ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c1cc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0685 | PC: 0x0544e8 | FDE: 0x0c1ce8 | Size: 256 bytes
// Hàm FDE #0685 | Địa chỉ PC: 0x0544e8 | Địa chỉ FDE: 0x0c1ce8 | Kích thước: 256 bytes
//   0x0544e8: D10243FF  sub      sp, sp, #0x90
//   0x0544ec: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x0544f0: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x0544f4: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_0685_0x0544e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0544e8ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90657f6ULL) ^ 0x0c1ce8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0686 | PC: 0x0546b4 | FDE: 0x0c1a80 | Size: 256 bytes
// Hàm FDE #0686 | Địa chỉ PC: 0x0546b4 | Địa chỉ FDE: 0x0c1a80 | Kích thước: 256 bytes
//   0x0546b4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0546b8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0546bc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0546c0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0686_0x0546b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0546b4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c1a80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0687 | PC: 0x0547b8 | FDE: 0x0c1d18 | Size: 256 bytes
// Hàm FDE #0687 | Địa chỉ PC: 0x0547b8 | Địa chỉ FDE: 0x0c1d18 | Kích thước: 256 bytes
//   0x0547b8: D105C3FF  sub      sp, sp, #0x170
//   0x0547bc: A9135FFC  stp      x28, x23, [sp, #0x130]
//   0x0547c0: A91457F6  stp      x22, x21, [sp, #0x140]
//   0x0547c4: A9154FF4  stp      x20, x19, [sp, #0x150]
static inline uint64_t fde_func_0687_0x0547b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0547b8ULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xa9135ffcULL) ^ 0x0c1d18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0688 | PC: 0x054924 | FDE: 0x0c1aa8 | Size: 256 bytes
// Hàm FDE #0688 | Địa chỉ PC: 0x054924 | Địa chỉ FDE: 0x0c1aa8 | Kích thước: 256 bytes
//   0x054924: F9400829  ldr      x9, [x1, #0x10]
//   0x054928: 3DC00020  ldr      q0, [x1]
//   0x05492c: AA0003E8  mov      x8, x0
//   0x054930: F9000809  str      x9, [x0, #0x10]
static inline uint64_t fde_func_0688_0x054924(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x054924ULL ^ (static_cast<uint64_t>(0xf9400829ULL) << 13);
    acc = (acc + a1 + 0x3dc00020ULL) ^ 0x0c1aa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0689 | PC: 0x054ac8 | FDE: 0x0c1ac0 | Size: 256 bytes
// Hàm FDE #0689 | Địa chỉ PC: 0x054ac8 | Địa chỉ FDE: 0x0c1ac0 | Kích thước: 256 bytes
//   0x054ac8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x054acc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x054ad0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x054ad4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0689_0x054ac8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x054ac8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c1ac0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0690 | PC: 0x054c1c | FDE: 0x0c1d48 | Size: 256 bytes
// Hàm FDE #0690 | Địa chỉ PC: 0x054c1c | Địa chỉ FDE: 0x0c1d48 | Kích thước: 256 bytes
//   0x054c1c: D10283FF  sub      sp, sp, #0xa0
//   0x054c20: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x054c24: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x054c28: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0690_0x054c1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x054c1cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x0c1d48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0691 | PC: 0x054f48 | FDE: 0x0c1ae0 | Size: 256 bytes
// Hàm FDE #0691 | Địa chỉ PC: 0x054f48 | Địa chỉ FDE: 0x0c1ae0 | Kích thước: 256 bytes
//   0x054f48: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x054f4c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x054f50: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x054f54: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0691_0x054f48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x054f48ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c1ae0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0692 | PC: 0x055190 | FDE: 0x0c1b08 | Size: 256 bytes
// Hàm FDE #0692 | Địa chỉ PC: 0x055190 | Địa chỉ FDE: 0x0c1b08 | Kích thước: 256 bytes
//   0x055190: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x055194: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x055198: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x05519c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0692_0x055190(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x055190ULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0c1b08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0693 | PC: 0x055374 | FDE: 0x0c1b38 | Size: 256 bytes
// Hàm FDE #0693 | Địa chỉ PC: 0x055374 | Địa chỉ FDE: 0x0c1b38 | Kích thước: 256 bytes
//   0x055374: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x055378: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05537c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x055380: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0693_0x055374(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x055374ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c1b38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0694 | PC: 0x055480 | FDE: 0x0c1b60 | Size: 256 bytes
// Hàm FDE #0694 | Địa chỉ PC: 0x055480 | Địa chỉ FDE: 0x0c1b60 | Kích thước: 256 bytes
//   0x055480: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x055484: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x055488: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05548c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0694_0x055480(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x055480ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c1b60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0695 | PC: 0x0555e4 | FDE: 0x0c1b80 | Size: 256 bytes
// Hàm FDE #0695 | Địa chỉ PC: 0x0555e4 | Địa chỉ FDE: 0x0c1b80 | Kích thước: 256 bytes
//   0x0555e4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0555e8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0555ec: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0555f0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0695_0x0555e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0555e4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c1b80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0696 | PC: 0x055750 | FDE: 0x0c1e18 | Size: 256 bytes
// Hàm FDE #0696 | Địa chỉ PC: 0x055750 | Địa chỉ FDE: 0x0c1e18 | Kích thước: 256 bytes
//   0x055750: D10283FF  sub      sp, sp, #0xa0
//   0x055754: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x055758: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x05575c: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0696_0x055750(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x055750ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x0c1e18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0697 | PC: 0x055a20 | FDE: 0x0c1e48 | Size: 256 bytes
// Hàm FDE #0697 | Địa chỉ PC: 0x055a20 | Địa chỉ FDE: 0x0c1e48 | Kích thước: 256 bytes
//   0x055a20: D10203FF  sub      sp, sp, #0x80
//   0x055a24: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x055a28: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x055a2c: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_0697_0x055a20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x055a20ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9045ff8ULL) ^ 0x0c1e48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0698 | PC: 0x0561e4 | FDE: 0x0c1e78 | Size: 256 bytes
// Hàm FDE #0698 | Địa chỉ PC: 0x0561e4 | Địa chỉ FDE: 0x0c1e78 | Kích thước: 256 bytes
//   0x0561e4: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0561e8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0561ec: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0561f0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0698_0x0561e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0561e4ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c1e78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0699 | PC: 0x0562f0 | FDE: 0x0c1ea8 | Size: 256 bytes
// Hàm FDE #0699 | Địa chỉ PC: 0x0562f0 | Địa chỉ FDE: 0x0c1ea8 | Kích thước: 256 bytes
//   0x0562f0: D101C3FF  sub      sp, sp, #0x70
//   0x0562f4: F90023F5  str      x21, [sp, #0x40]
//   0x0562f8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0562fc: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0699_0x0562f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0562f0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c1ea8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0700 | PC: 0x056448 | FDE: 0x0c1ed0 | Size: 256 bytes
// Hàm FDE #0700 | Địa chỉ PC: 0x056448 | Địa chỉ FDE: 0x0c1ed0 | Kích thước: 256 bytes
//   0x056448: D10283FF  sub      sp, sp, #0xa0
//   0x05644c: F90033F7  str      x23, [sp, #0x60]
//   0x056450: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x056454: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0700_0x056448(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x056448ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90033f7ULL) ^ 0x0c1ed0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0701 | PC: 0x056630 | FDE: 0x0c1d80 | Size: 256 bytes
// Hàm FDE #0701 | Địa chỉ PC: 0x056630 | Địa chỉ FDE: 0x0c1d80 | Kích thước: 256 bytes
//   0x056630: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x056634: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x056638: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05663c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0701_0x056630(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x056630ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c1d80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0702 | PC: 0x056820 | FDE: 0x0c1f00 | Size: 256 bytes
// Hàm FDE #0702 | Địa chỉ PC: 0x056820 | Địa chỉ FDE: 0x0c1f00 | Kích thước: 256 bytes
//   0x056820: D10383FF  sub      sp, sp, #0xe0
//   0x056824: A90A5FF8  stp      x24, x23, [sp, #0xa0]
//   0x056828: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x05682c: A90C4FF4  stp      x20, x19, [sp, #0xc0]
static inline uint64_t fde_func_0702_0x056820(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x056820ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa90a5ff8ULL) ^ 0x0c1f00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0703 | PC: 0x056a50 | FDE: 0x0c1f30 | Size: 256 bytes
// Hàm FDE #0703 | Địa chỉ PC: 0x056a50 | Địa chỉ FDE: 0x0c1f30 | Kích thước: 256 bytes
//   0x056a50: D101C3FF  sub      sp, sp, #0x70
//   0x056a54: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x056a58: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x056a5c: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0703_0x056a50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x056a50ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x0c1f30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0704 | PC: 0x056e50 | FDE: 0x0c1da8 | Size: 256 bytes
// Hàm FDE #0704 | Địa chỉ PC: 0x056e50 | Địa chỉ FDE: 0x0c1da8 | Kích thước: 256 bytes
//   0x056e50: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x056e54: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x056e58: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x056e5c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0704_0x056e50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x056e50ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c1da8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0705 | PC: 0x0570bc | FDE: 0x0c1dd0 | Size: 256 bytes
// Hàm FDE #0705 | Địa chỉ PC: 0x0570bc | Địa chỉ FDE: 0x0c1dd0 | Kích thước: 256 bytes
//   0x0570bc: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0570c0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0570c4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0570c8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0705_0x0570bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0570bcULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c1dd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0706 | PC: 0x057424 | FDE: 0x0c1e00 | Size: 256 bytes
// Hàm FDE #0706 | Địa chỉ PC: 0x057424 | Địa chỉ FDE: 0x0c1e00 | Kích thước: 256 bytes
//   0x057424: AA0003E8  mov      x8, x0
//   0x057428: F940000A  ldr      x10, [x0]
//   0x05742c: F9400420  ldr      x0, [x1, #8]
//   0x057430: EB02015F  cmp      x10, x2
static inline uint64_t fde_func_0706_0x057424(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x057424ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xf940000aULL) ^ 0x0c1e00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0707 | PC: 0x057648 | FDE: 0x0c1f60 | Size: 256 bytes
// Hàm FDE #0707 | Địa chỉ PC: 0x057648 | Địa chỉ FDE: 0x0c1f60 | Kích thước: 256 bytes
//   0x057648: D10203FF  sub      sp, sp, #0x80
//   0x05764c: F90023F7  str      x23, [sp, #0x40]
//   0x057650: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x057654: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_0707_0x057648(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x057648ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x0c1f60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0708 | PC: 0x057808 | FDE: 0x0c1f90 | Size: 256 bytes
// Hàm FDE #0708 | Địa chỉ PC: 0x057808 | Địa chỉ FDE: 0x0c1f90 | Kích thước: 256 bytes
//   0x057808: D101C3FF  sub      sp, sp, #0x70
//   0x05780c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x057810: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x057814: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0708_0x057808(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x057808ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x0c1f90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0709 | PC: 0x057b28 | FDE: 0x0c1fc0 | Size: 256 bytes
// Hàm FDE #0709 | Địa chỉ PC: 0x057b28 | Địa chỉ FDE: 0x0c1fc0 | Kích thước: 256 bytes
//   0x057b28: D10203FF  sub      sp, sp, #0x80
//   0x057b2c: F90023F7  str      x23, [sp, #0x40]
//   0x057b30: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x057b34: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_0709_0x057b28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x057b28ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x0c1fc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0710 | PC: 0x057cd8 | FDE: 0x0c1ff0 | Size: 256 bytes
// Hàm FDE #0710 | Địa chỉ PC: 0x057cd8 | Địa chỉ FDE: 0x0c1ff0 | Kích thước: 256 bytes
//   0x057cd8: D101C3FF  sub      sp, sp, #0x70
//   0x057cdc: F90023F5  str      x21, [sp, #0x40]
//   0x057ce0: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x057ce4: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0710_0x057cd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x057cd8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c1ff0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0711 | PC: 0x057ee0 | FDE: 0x0c2060 | Size: 256 bytes
// Hàm FDE #0711 | Địa chỉ PC: 0x057ee0 | Địa chỉ FDE: 0x0c2060 | Kích thước: 256 bytes
//   0x057ee0: D10283FF  sub      sp, sp, #0xa0
//   0x057ee4: F90033F7  str      x23, [sp, #0x60]
//   0x057ee8: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x057eec: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0711_0x057ee0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x057ee0ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90033f7ULL) ^ 0x0c2060ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0712 | PC: 0x058160 | FDE: 0x0c2090 | Size: 256 bytes
// Hàm FDE #0712 | Địa chỉ PC: 0x058160 | Địa chỉ FDE: 0x0c2090 | Kích thước: 256 bytes
//   0x058160: D10283FF  sub      sp, sp, #0xa0
//   0x058164: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x058168: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x05816c: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_0712_0x058160(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x058160ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa90757f6ULL) ^ 0x0c2090ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0713 | PC: 0x058540 | FDE: 0x0c2018 | Size: 256 bytes
// Hàm FDE #0713 | Địa chỉ PC: 0x058540 | Địa chỉ FDE: 0x0c2018 | Kích thước: 256 bytes
//   0x058540: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x058544: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x058548: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05854c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0713_0x058540(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x058540ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c2018ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0714 | PC: 0x058694 | FDE: 0x0c2040 | Size: 256 bytes
// Hàm FDE #0714 | Địa chỉ PC: 0x058694 | Địa chỉ FDE: 0x0c2040 | Kích thước: 256 bytes
//   0x058694: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x058698: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05869c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0586a0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0714_0x058694(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x058694ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c2040ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0715 | PC: 0x058848 | FDE: 0x0c20c0 | Size: 256 bytes
// Hàm FDE #0715 | Địa chỉ PC: 0x058848 | Địa chỉ FDE: 0x0c20c0 | Kích thước: 256 bytes
//   0x058848: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x05884c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x058850: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x058854: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0715_0x058848(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x058848ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c20c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0716 | PC: 0x058988 | FDE: 0x0c2188 | Size: 256 bytes
// Hàm FDE #0716 | Địa chỉ PC: 0x058988 | Địa chỉ FDE: 0x0c2188 | Kích thước: 256 bytes
//   0x058988: D10243FF  sub      sp, sp, #0x90
//   0x05898c: F9002BF7  str      x23, [sp, #0x50]
//   0x058990: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x058994: A9074FF4  stp      x20, x19, [sp, #0x70]
static inline uint64_t fde_func_0716_0x058988(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x058988ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf7ULL) ^ 0x0c2188ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0717 | PC: 0x058b84 | FDE: 0x0c21b8 | Size: 256 bytes
// Hàm FDE #0717 | Địa chỉ PC: 0x058b84 | Địa chỉ FDE: 0x0c21b8 | Kích thước: 256 bytes
//   0x058b84: D10243FF  sub      sp, sp, #0x90
//   0x058b88: F9002BF7  str      x23, [sp, #0x50]
//   0x058b8c: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x058b90: A9074FF4  stp      x20, x19, [sp, #0x70]
static inline uint64_t fde_func_0717_0x058b84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x058b84ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf7ULL) ^ 0x0c21b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0718 | PC: 0x058ef8 | FDE: 0x0c21e8 | Size: 256 bytes
// Hàm FDE #0718 | Địa chỉ PC: 0x058ef8 | Địa chỉ FDE: 0x0c21e8 | Kích thước: 256 bytes
//   0x058ef8: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x058efc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x058f00: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x058f04: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0718_0x058ef8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x058ef8ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c21e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0719 | PC: 0x058ffc | FDE: 0x0c2218 | Size: 256 bytes
// Hàm FDE #0719 | Địa chỉ PC: 0x058ffc | Địa chỉ FDE: 0x0c2218 | Kích thước: 256 bytes
//   0x058ffc: D101C3FF  sub      sp, sp, #0x70
//   0x059000: F90023F5  str      x21, [sp, #0x40]
//   0x059004: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x059008: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0719_0x058ffc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x058ffcULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c2218ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0720 | PC: 0x059154 | FDE: 0x0c2240 | Size: 256 bytes
// Hàm FDE #0720 | Địa chỉ PC: 0x059154 | Địa chỉ FDE: 0x0c2240 | Kích thước: 256 bytes
//   0x059154: D10243FF  sub      sp, sp, #0x90
//   0x059158: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x05915c: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x059160: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_0720_0x059154(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x059154ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90657f6ULL) ^ 0x0c2240ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0721 | PC: 0x059320 | FDE: 0x0c20f0 | Size: 248 bytes
// Hàm FDE #0721 | Địa chỉ PC: 0x059320 | Địa chỉ FDE: 0x0c20f0 | Kích thước: 248 bytes
//   0x059320: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x059324: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x059328: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05932c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0721_0x059320(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x059320ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c20f0ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0722 | PC: 0x059418 | FDE: 0x0c2270 | Size: 256 bytes
// Hàm FDE #0722 | Địa chỉ PC: 0x059418 | Địa chỉ FDE: 0x0c2270 | Kích thước: 256 bytes
//   0x059418: D10783FF  sub      sp, sp, #0x1e0
//   0x05941c: F900CBFC  str      x28, [sp, #0x190]
//   0x059420: A91A5FF8  stp      x24, x23, [sp, #0x1a0]
//   0x059424: A91B57F6  stp      x22, x21, [sp, #0x1b0]
static inline uint64_t fde_func_0722_0x059418(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x059418ULL ^ (static_cast<uint64_t>(0xd10783ffULL) << 13);
    acc = (acc + a1 + 0xf900cbfcULL) ^ 0x0c2270ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0723 | PC: 0x0595a8 | FDE: 0x0c2118 | Size: 256 bytes
// Hàm FDE #0723 | Địa chỉ PC: 0x0595a8 | Địa chỉ FDE: 0x0c2118 | Kích thước: 256 bytes
//   0x0595a8: F9400829  ldr      x9, [x1, #0x10]
//   0x0595ac: 3DC00020  ldr      q0, [x1]
//   0x0595b0: AA0003E8  mov      x8, x0
//   0x0595b4: F9000809  str      x9, [x0, #0x10]
static inline uint64_t fde_func_0723_0x0595a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0595a8ULL ^ (static_cast<uint64_t>(0xf9400829ULL) << 13);
    acc = (acc + a1 + 0x3dc00020ULL) ^ 0x0c2118ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0724 | PC: 0x0597b8 | FDE: 0x0c22a0 | Size: 256 bytes
// Hàm FDE #0724 | Địa chỉ PC: 0x0597b8 | Địa chỉ FDE: 0x0c22a0 | Kích thước: 256 bytes
//   0x0597b8: D10283FF  sub      sp, sp, #0xa0
//   0x0597bc: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x0597c0: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0597c4: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0724_0x0597b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0597b8ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x0c22a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0725 | PC: 0x059ac0 | FDE: 0x0c2130 | Size: 256 bytes
// Hàm FDE #0725 | Địa chỉ PC: 0x059ac0 | Địa chỉ FDE: 0x0c2130 | Kích thước: 256 bytes
//   0x059ac0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x059ac4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x059ac8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x059acc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0725_0x059ac0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x059ac0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c2130ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0726 | PC: 0x059e48 | FDE: 0x0c2158 | Size: 256 bytes
// Hàm FDE #0726 | Địa chỉ PC: 0x059e48 | Địa chỉ FDE: 0x0c2158 | Kích thước: 256 bytes
//   0x059e48: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x059e4c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x059e50: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x059e54: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0726_0x059e48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x059e48ULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0c2158ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0727 | PC: 0x05a014 | FDE: 0x0c2318 | Size: 256 bytes
// Hàm FDE #0727 | Địa chỉ PC: 0x05a014 | Địa chỉ FDE: 0x0c2318 | Kích thước: 256 bytes
//   0x05a014: D10503FF  sub      sp, sp, #0x140
//   0x05a018: F9007BFC  str      x28, [sp, #0xf0]
//   0x05a01c: A9105FF8  stp      x24, x23, [sp, #0x100]
//   0x05a020: A91157F6  stp      x22, x21, [sp, #0x110]
static inline uint64_t fde_func_0727_0x05a014(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05a014ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xf9007bfcULL) ^ 0x0c2318ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0728 | PC: 0x05a6a0 | FDE: 0x0c2348 | Size: 256 bytes
// Hàm FDE #0728 | Địa chỉ PC: 0x05a6a0 | Địa chỉ FDE: 0x0c2348 | Kích thước: 256 bytes
//   0x05a6a0: D10343FF  sub      sp, sp, #0xd0
//   0x05a6a4: A9095FF8  stp      x24, x23, [sp, #0x90]
//   0x05a6a8: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x05a6ac: A90B4FF4  stp      x20, x19, [sp, #0xb0]
static inline uint64_t fde_func_0728_0x05a6a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05a6a0ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9095ff8ULL) ^ 0x0c2348ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0729 | PC: 0x05b494 | FDE: 0x0c2378 | Size: 256 bytes
// Hàm FDE #0729 | Địa chỉ PC: 0x05b494 | Địa chỉ FDE: 0x0c2378 | Kích thước: 256 bytes
//   0x05b494: D10243FF  sub      sp, sp, #0x90
//   0x05b498: F9002BF7  str      x23, [sp, #0x50]
//   0x05b49c: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x05b4a0: A9074FF4  stp      x20, x19, [sp, #0x70]
static inline uint64_t fde_func_0729_0x05b494(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05b494ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf7ULL) ^ 0x0c2378ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0730 | PC: 0x05b698 | FDE: 0x0c23a8 | Size: 256 bytes
// Hàm FDE #0730 | Địa chỉ PC: 0x05b698 | Địa chỉ FDE: 0x0c23a8 | Kích thước: 256 bytes
//   0x05b698: D101C3FF  sub      sp, sp, #0x70
//   0x05b69c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x05b6a0: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x05b6a4: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0730_0x05b698(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05b698ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x0c23a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0731 | PC: 0x05b90c | FDE: 0x0c2400 | Size: 256 bytes
// Hàm FDE #0731 | Địa chỉ PC: 0x05b90c | Địa chỉ FDE: 0x0c2400 | Kích thước: 256 bytes
//   0x05b90c: D10283FF  sub      sp, sp, #0xa0
//   0x05b910: F90033F7  str      x23, [sp, #0x60]
//   0x05b914: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x05b918: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0731_0x05b90c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05b90cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90033f7ULL) ^ 0x0c2400ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0732 | PC: 0x05bb8c | FDE: 0x0c2430 | Size: 256 bytes
// Hàm FDE #0732 | Địa chỉ PC: 0x05bb8c | Địa chỉ FDE: 0x0c2430 | Kích thước: 256 bytes
//   0x05bb8c: D10283FF  sub      sp, sp, #0xa0
//   0x05bb90: F90033F7  str      x23, [sp, #0x60]
//   0x05bb94: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x05bb98: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0732_0x05bb8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05bb8cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90033f7ULL) ^ 0x0c2430ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0733 | PC: 0x05c058 | FDE: 0x0c23d8 | Size: 224 bytes
// Hàm FDE #0733 | Địa chỉ PC: 0x05c058 | Địa chỉ FDE: 0x0c23d8 | Kích thước: 224 bytes
//   0x05c058: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x05c05c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05c060: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05c064: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0733_0x05c058(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05c058ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c23d8ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// Shard 2 Dispatcher / Bộ điều phối phân mảnh 2
uint64_t execute_fde_shard_2(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 367: return fde_func_0367_0x029b64(a0, a1);
        case 368: return fde_func_0368_0x029bec(a0, a1);
        case 369: return fde_func_0369_0x029c3c(a0, a1);
        case 370: return fde_func_0370_0x029c94(a0, a1);
        case 371: return fde_func_0371_0x029d94(a0, a1);
        case 372: return fde_func_0372_0x029da8(a0, a1);
        case 373: return fde_func_0373_0x029df8(a0, a1);
        case 374: return fde_func_0374_0x029e68(a0, a1);
        case 375: return fde_func_0375_0x02a09c(a0, a1);
        case 376: return fde_func_0376_0x02a168(a0, a1);
        case 377: return fde_func_0377_0x02a1b0(a0, a1);
        case 378: return fde_func_0378_0x02a1f8(a0, a1);
        case 379: return fde_func_0379_0x02a24c(a0, a1);
        case 380: return fde_func_0380_0x02a39c(a0, a1);
        case 381: return fde_func_0381_0x02a3b0(a0, a1);
        case 382: return fde_func_0382_0x02a400(a0, a1);
        case 383: return fde_func_0383_0x02a430(a0, a1);
        case 384: return fde_func_0384_0x02a5c0(a0, a1);
        case 385: return fde_func_0385_0x02a814(a0, a1);
        case 386: return fde_func_0386_0x02a97c(a0, a1);
        case 387: return fde_func_0387_0x02ac18(a0, a1);
        case 388: return fde_func_0388_0x02b6bc(a0, a1);
        case 389: return fde_func_0389_0x02b8fc(a0, a1);
        case 390: return fde_func_0390_0x02bc50(a0, a1);
        case 391: return fde_func_0391_0x02bd90(a0, a1);
        case 392: return fde_func_0392_0x02bf90(a0, a1);
        case 393: return fde_func_0393_0x02c054(a0, a1);
        case 394: return fde_func_0394_0x02c1d8(a0, a1);
        case 395: return fde_func_0395_0x02c2ec(a0, a1);
        case 396: return fde_func_0396_0x02c440(a0, a1);
        case 397: return fde_func_0397_0x02c5e0(a0, a1);
        case 398: return fde_func_0398_0x02c790(a0, a1);
        case 399: return fde_func_0399_0x02c830(a0, a1);
        case 400: return fde_func_0400_0x02c94c(a0, a1);
        case 401: return fde_func_0401_0x02cb5c(a0, a1);
        case 402: return fde_func_0402_0x02cf8c(a0, a1);
        case 403: return fde_func_0403_0x02d31c(a0, a1);
        case 404: return fde_func_0404_0x02d3c8(a0, a1);
        case 405: return fde_func_0405_0x02d43c(a0, a1);
        case 406: return fde_func_0406_0x02d4ac(a0, a1);
        case 407: return fde_func_0407_0x02d504(a0, a1);
        case 408: return fde_func_0408_0x02d658(a0, a1);
        case 409: return fde_func_0409_0x02d6c8(a0, a1);
        case 410: return fde_func_0410_0x02d7cc(a0, a1);
        case 411: return fde_func_0411_0x02d7dc(a0, a1);
        case 412: return fde_func_0412_0x02da6c(a0, a1);
        case 413: return fde_func_0413_0x02da78(a0, a1);
        case 414: return fde_func_0414_0x02dad0(a0, a1);
        case 415: return fde_func_0415_0x02db6c(a0, a1);
        case 416: return fde_func_0416_0x02dca0(a0, a1);
        case 417: return fde_func_0417_0x02dee8(a0, a1);
        case 418: return fde_func_0418_0x02dfcc(a0, a1);
        case 419: return fde_func_0419_0x02e154(a0, a1);
        case 420: return fde_func_0420_0x02e38c(a0, a1);
        case 421: return fde_func_0421_0x02e99c(a0, a1);
        case 422: return fde_func_0422_0x02eb8c(a0, a1);
        case 423: return fde_func_0423_0x02ec70(a0, a1);
        case 424: return fde_func_0424_0x02eec8(a0, a1);
        case 425: return fde_func_0425_0x02f228(a0, a1);
        case 426: return fde_func_0426_0x02f6d4(a0, a1);
        case 427: return fde_func_0427_0x02f7d0(a0, a1);
        case 428: return fde_func_0428_0x02f838(a0, a1);
        case 429: return fde_func_0429_0x02f980(a0, a1);
        case 430: return fde_func_0430_0x02f9dc(a0, a1);
        case 431: return fde_func_0431_0x02fcb8(a0, a1);
        case 432: return fde_func_0432_0x02fec4(a0, a1);
        case 433: return fde_func_0433_0x030034(a0, a1);
        case 434: return fde_func_0434_0x030064(a0, a1);
        case 435: return fde_func_0435_0x0301bc(a0, a1);
        case 436: return fde_func_0436_0x0302e0(a0, a1);
        case 437: return fde_func_0437_0x0304e0(a0, a1);
        case 438: return fde_func_0438_0x0305e4(a0, a1);
        case 439: return fde_func_0439_0x03061c(a0, a1);
        case 440: return fde_func_0440_0x030624(a0, a1);
        case 441: return fde_func_0441_0x03065c(a0, a1);
        case 442: return fde_func_0442_0x0307ac(a0, a1);
        case 443: return fde_func_0443_0x030898(a0, a1);
        case 444: return fde_func_0444_0x030974(a0, a1);
        case 445: return fde_func_0445_0x030a80(a0, a1);
        case 446: return fde_func_0446_0x030d5c(a0, a1);
        case 447: return fde_func_0447_0x030e7c(a0, a1);
        case 448: return fde_func_0448_0x03101c(a0, a1);
        case 449: return fde_func_0449_0x031104(a0, a1);
        case 450: return fde_func_0450_0x0311a8(a0, a1);
        case 451: return fde_func_0451_0x031314(a0, a1);
        case 452: return fde_func_0452_0x031420(a0, a1);
        case 453: return fde_func_0453_0x031f00(a0, a1);
        case 454: return fde_func_0454_0x031f04(a0, a1);
        case 455: return fde_func_0455_0x031f28(a0, a1);
        case 456: return fde_func_0456_0x031f34(a0, a1);
        case 457: return fde_func_0457_0x031f38(a0, a1);
        case 458: return fde_func_0458_0x031fe0(a0, a1);
        case 459: return fde_func_0459_0x031fe8(a0, a1);
        case 460: return fde_func_0460_0x031fec(a0, a1);
        case 461: return fde_func_0461_0x031ff0(a0, a1);
        case 462: return fde_func_0462_0x032678(a0, a1);
        case 463: return fde_func_0463_0x0327bc(a0, a1);
        case 464: return fde_func_0464_0x032984(a0, a1);
        case 465: return fde_func_0465_0x032ac0(a0, a1);
        case 466: return fde_func_0466_0x032b64(a0, a1);
        case 467: return fde_func_0467_0x032d48(a0, a1);
        case 468: return fde_func_0468_0x032f4c(a0, a1);
        case 469: return fde_func_0469_0x03321c(a0, a1);
        case 470: return fde_func_0470_0x03324c(a0, a1);
        case 471: return fde_func_0471_0x033278(a0, a1);
        case 472: return fde_func_0472_0x033358(a0, a1);
        case 473: return fde_func_0473_0x033370(a0, a1);
        case 474: return fde_func_0474_0x033388(a0, a1);
        case 475: return fde_func_0475_0x033394(a0, a1);
        case 476: return fde_func_0476_0x033820(a0, a1);
        case 477: return fde_func_0477_0x0339e8(a0, a1);
        case 478: return fde_func_0478_0x033bc4(a0, a1);
        case 479: return fde_func_0479_0x033dc8(a0, a1);
        case 480: return fde_func_0480_0x03417c(a0, a1);
        case 481: return fde_func_0481_0x034224(a0, a1);
        case 482: return fde_func_0482_0x034260(a0, a1);
        case 483: return fde_func_0483_0x0345cc(a0, a1);
        case 484: return fde_func_0484_0x035e60(a0, a1);
        case 485: return fde_func_0485_0x037258(a0, a1);
        case 486: return fde_func_0486_0x0372b0(a0, a1);
        case 487: return fde_func_0487_0x037b68(a0, a1);
        case 488: return fde_func_0488_0x037ee0(a0, a1);
        case 489: return fde_func_0489_0x037fec(a0, a1);
        case 490: return fde_func_0490_0x0380bc(a0, a1);
        case 491: return fde_func_0491_0x0388a0(a0, a1);
        case 492: return fde_func_0492_0x038a04(a0, a1);
        case 493: return fde_func_0493_0x038b8c(a0, a1);
        case 494: return fde_func_0494_0x038d9c(a0, a1);
        case 495: return fde_func_0495_0x038fac(a0, a1);
        case 496: return fde_func_0496_0x03910c(a0, a1);
        case 497: return fde_func_0497_0x03937c(a0, a1);
        case 498: return fde_func_0498_0x0396e8(a0, a1);
        case 499: return fde_func_0499_0x03a3d4(a0, a1);
        case 500: return fde_func_0500_0x03a414(a0, a1);
        case 501: return fde_func_0501_0x03a44c(a0, a1);
        case 502: return fde_func_0502_0x03a6d0(a0, a1);
        case 503: return fde_func_0503_0x03a6d8(a0, a1);
        case 504: return fde_func_0504_0x03a78c(a0, a1);
        case 505: return fde_func_0505_0x03acc0(a0, a1);
        case 506: return fde_func_0506_0x03b094(a0, a1);
        case 507: return fde_func_0507_0x03b1cc(a0, a1);
        case 508: return fde_func_0508_0x03b204(a0, a1);
        case 509: return fde_func_0509_0x03b420(a0, a1);
        case 510: return fde_func_0510_0x03b5ec(a0, a1);
        case 511: return fde_func_0511_0x03b76c(a0, a1);
        case 512: return fde_func_0512_0x03b804(a0, a1);
        case 513: return fde_func_0513_0x03bb64(a0, a1);
        case 514: return fde_func_0514_0x03bc48(a0, a1);
        case 515: return fde_func_0515_0x03beb8(a0, a1);
        case 516: return fde_func_0516_0x03c084(a0, a1);
        case 517: return fde_func_0517_0x03c198(a0, a1);
        case 518: return fde_func_0518_0x03c76c(a0, a1);
        case 519: return fde_func_0519_0x03c844(a0, a1);
        case 520: return fde_func_0520_0x03c9b4(a0, a1);
        case 521: return fde_func_0521_0x03c9ec(a0, a1);
        case 522: return fde_func_0522_0x03cb34(a0, a1);
        case 523: return fde_func_0523_0x03cde0(a0, a1);
        case 524: return fde_func_0524_0x03cee4(a0, a1);
        case 525: return fde_func_0525_0x03d9b4(a0, a1);
        case 526: return fde_func_0526_0x03e50c(a0, a1);
        case 527: return fde_func_0527_0x03e654(a0, a1);
        case 528: return fde_func_0528_0x03e710(a0, a1);
        case 529: return fde_func_0529_0x03e838(a0, a1);
        case 530: return fde_func_0530_0x03e9d4(a0, a1);
        case 531: return fde_func_0531_0x03eb9c(a0, a1);
        case 532: return fde_func_0532_0x03f8dc(a0, a1);
        case 533: return fde_func_0533_0x03fa50(a0, a1);
        case 534: return fde_func_0534_0x03fd9c(a0, a1);
        case 535: return fde_func_0535_0x0402a4(a0, a1);
        case 536: return fde_func_0536_0x040328(a0, a1);
        case 537: return fde_func_0537_0x0410e4(a0, a1);
        case 538: return fde_func_0538_0x0411e4(a0, a1);
        case 539: return fde_func_0539_0x041304(a0, a1);
        case 540: return fde_func_0540_0x041464(a0, a1);
        case 541: return fde_func_0541_0x04169c(a0, a1);
        case 542: return fde_func_0542_0x041920(a0, a1);
        case 543: return fde_func_0543_0x041bc4(a0, a1);
        case 544: return fde_func_0544_0x041dd8(a0, a1);
        case 545: return fde_func_0545_0x042060(a0, a1);
        case 546: return fde_func_0546_0x0421b8(a0, a1);
        case 547: return fde_func_0547_0x042328(a0, a1);
        case 548: return fde_func_0548_0x042570(a0, a1);
        case 549: return fde_func_0549_0x042668(a0, a1);
        case 550: return fde_func_0550_0x042770(a0, a1);
        case 551: return fde_func_0551_0x0428e0(a0, a1);
        case 552: return fde_func_0552_0x042918(a0, a1);
        case 553: return fde_func_0553_0x042a0c(a0, a1);
        case 554: return fde_func_0554_0x042a44(a0, a1);
        case 555: return fde_func_0555_0x042c88(a0, a1);
        case 556: return fde_func_0556_0x042ecc(a0, a1);
        case 557: return fde_func_0557_0x043108(a0, a1);
        case 558: return fde_func_0558_0x043348(a0, a1);
        case 559: return fde_func_0559_0x0435c4(a0, a1);
        case 560: return fde_func_0560_0x043808(a0, a1);
        case 561: return fde_func_0561_0x0438ac(a0, a1);
        case 562: return fde_func_0562_0x043aac(a0, a1);
        case 563: return fde_func_0563_0x043bfc(a0, a1);
        case 564: return fde_func_0564_0x043cf4(a0, a1);
        case 565: return fde_func_0565_0x043e5c(a0, a1);
        case 566: return fde_func_0566_0x043f8c(a0, a1);
        case 567: return fde_func_0567_0x0440d4(a0, a1);
        case 568: return fde_func_0568_0x044204(a0, a1);
        case 569: return fde_func_0569_0x04434c(a0, a1);
        case 570: return fde_func_0570_0x044460(a0, a1);
        case 571: return fde_func_0571_0x04459c(a0, a1);
        case 572: return fde_func_0572_0x0446cc(a0, a1);
        case 573: return fde_func_0573_0x044814(a0, a1);
        case 574: return fde_func_0574_0x0449d0(a0, a1);
        case 575: return fde_func_0575_0x044b70(a0, a1);
        case 576: return fde_func_0576_0x044ca0(a0, a1);
        case 577: return fde_func_0577_0x044de8(a0, a1);
        case 578: return fde_func_0578_0x044f04(a0, a1);
        case 579: return fde_func_0579_0x045044(a0, a1);
        case 580: return fde_func_0580_0x0451c4(a0, a1);
        case 581: return fde_func_0581_0x045304(a0, a1);
        case 582: return fde_func_0582_0x045444(a0, a1);
        case 583: return fde_func_0583_0x045628(a0, a1);
        case 584: return fde_func_0584_0x045780(a0, a1);
        case 585: return fde_func_0585_0x045bd8(a0, a1);
        case 586: return fde_func_0586_0x045cec(a0, a1);
        case 587: return fde_func_0587_0x045f88(a0, a1);
        case 588: return fde_func_0588_0x046128(a0, a1);
        case 589: return fde_func_0589_0x046300(a0, a1);
        case 590: return fde_func_0590_0x0466d0(a0, a1);
        case 591: return fde_func_0591_0x046780(a0, a1);
        case 592: return fde_func_0592_0x046b30(a0, a1);
        case 593: return fde_func_0593_0x046c90(a0, a1);
        case 594: return fde_func_0594_0x047010(a0, a1);
        case 595: return fde_func_0595_0x047148(a0, a1);
        case 596: return fde_func_0596_0x047710(a0, a1);
        case 597: return fde_func_0597_0x047978(a0, a1);
        case 598: return fde_func_0598_0x047d70(a0, a1);
        case 599: return fde_func_0599_0x047e8c(a0, a1);
        case 600: return fde_func_0600_0x047f98(a0, a1);
        case 601: return fde_func_0601_0x048134(a0, a1);
        case 602: return fde_func_0602_0x048214(a0, a1);
        case 603: return fde_func_0603_0x04830c(a0, a1);
        case 604: return fde_func_0604_0x0484cc(a0, a1);
        case 605: return fde_func_0605_0x0486cc(a0, a1);
        case 606: return fde_func_0606_0x048904(a0, a1);
        case 607: return fde_func_0607_0x048a68(a0, a1);
        case 608: return fde_func_0608_0x048e08(a0, a1);
        case 609: return fde_func_0609_0x048fd8(a0, a1);
        case 610: return fde_func_0610_0x0490dc(a0, a1);
        case 611: return fde_func_0611_0x0493ec(a0, a1);
        case 612: return fde_func_0612_0x0496dc(a0, a1);
        case 613: return fde_func_0613_0x049998(a0, a1);
        case 614: return fde_func_0614_0x0499ac(a0, a1);
        case 615: return fde_func_0615_0x049b38(a0, a1);
        case 616: return fde_func_0616_0x049cf0(a0, a1);
        case 617: return fde_func_0617_0x049f60(a0, a1);
        case 618: return fde_func_0618_0x04a0a0(a0, a1);
        case 619: return fde_func_0619_0x04a1e0(a0, a1);
        case 620: return fde_func_0620_0x04a368(a0, a1);
        case 621: return fde_func_0621_0x04a8cc(a0, a1);
        case 622: return fde_func_0622_0x04b4a4(a0, a1);
        case 623: return fde_func_0623_0x04b538(a0, a1);
        case 624: return fde_func_0624_0x04b704(a0, a1);
        case 625: return fde_func_0625_0x04b844(a0, a1);
        case 626: return fde_func_0626_0x04b984(a0, a1);
        case 627: return fde_func_0627_0x04baec(a0, a1);
        case 628: return fde_func_0628_0x04bc44(a0, a1);
        case 629: return fde_func_0629_0x04be10(a0, a1);
        case 630: return fde_func_0630_0x04c124(a0, a1);
        case 631: return fde_func_0631_0x04c538(a0, a1);
        case 632: return fde_func_0632_0x04c704(a0, a1);
        case 633: return fde_func_0633_0x04ca70(a0, a1);
        case 634: return fde_func_0634_0x04cca8(a0, a1);
        case 635: return fde_func_0635_0x04cde4(a0, a1);
        case 636: return fde_func_0636_0x04cf24(a0, a1);
        case 637: return fde_func_0637_0x04d0b8(a0, a1);
        case 638: return fde_func_0638_0x04d22c(a0, a1);
        case 639: return fde_func_0639_0x04d36c(a0, a1);
        case 640: return fde_func_0640_0x04d4c4(a0, a1);
        case 641: return fde_func_0641_0x04d850(a0, a1);
        case 642: return fde_func_0642_0x04dedc(a0, a1);
        case 643: return fde_func_0643_0x04e138(a0, a1);
        case 644: return fde_func_0644_0x04e25c(a0, a1);
        case 645: return fde_func_0645_0x04e458(a0, a1);
        case 646: return fde_func_0646_0x04e5b0(a0, a1);
        case 647: return fde_func_0647_0x04e7ac(a0, a1);
        case 648: return fde_func_0648_0x04e8c4(a0, a1);
        case 649: return fde_func_0649_0x04ea14(a0, a1);
        case 650: return fde_func_0650_0x04edf0(a0, a1);
        case 651: return fde_func_0651_0x04f030(a0, a1);
        case 652: return fde_func_0652_0x04f38c(a0, a1);
        case 653: return fde_func_0653_0x04f870(a0, a1);
        case 654: return fde_func_0654_0x04facc(a0, a1);
        case 655: return fde_func_0655_0x04fcc8(a0, a1);
        case 656: return fde_func_0656_0x04ffb8(a0, a1);
        case 657: return fde_func_0657_0x050470(a0, a1);
        case 658: return fde_func_0658_0x050574(a0, a1);
        case 659: return fde_func_0659_0x0506cc(a0, a1);
        case 660: return fde_func_0660_0x050850(a0, a1);
        case 661: return fde_func_0661_0x050a10(a0, a1);
        case 662: return fde_func_0662_0x050bfc(a0, a1);
        case 663: return fde_func_0663_0x050ca8(a0, a1);
        case 664: return fde_func_0664_0x050ff0(a0, a1);
        case 665: return fde_func_0665_0x0511b8(a0, a1);
        case 666: return fde_func_0666_0x0514d4(a0, a1);
        case 667: return fde_func_0667_0x0516a8(a0, a1);
        case 668: return fde_func_0668_0x0518e0(a0, a1);
        case 669: return fde_func_0669_0x051cbc(a0, a1);
        case 670: return fde_func_0670_0x051dfc(a0, a1);
        case 671: return fde_func_0671_0x051fac(a0, a1);
        case 672: return fde_func_0672_0x0521b4(a0, a1);
        case 673: return fde_func_0673_0x052538(a0, a1);
        case 674: return fde_func_0674_0x052af8(a0, a1);
        case 675: return fde_func_0675_0x052c38(a0, a1);
        case 676: return fde_func_0676_0x05318c(a0, a1);
        case 677: return fde_func_0677_0x053c08(a0, a1);
        case 678: return fde_func_0678_0x053d00(a0, a1);
        case 679: return fde_func_0679_0x053e4c(a0, a1);
        case 680: return fde_func_0680_0x053f70(a0, a1);
        case 681: return fde_func_0681_0x054004(a0, a1);
        case 682: return fde_func_0682_0x054110(a0, a1);
        case 683: return fde_func_0683_0x054250(a0, a1);
        case 684: return fde_func_0684_0x054390(a0, a1);
        case 685: return fde_func_0685_0x0544e8(a0, a1);
        case 686: return fde_func_0686_0x0546b4(a0, a1);
        case 687: return fde_func_0687_0x0547b8(a0, a1);
        case 688: return fde_func_0688_0x054924(a0, a1);
        case 689: return fde_func_0689_0x054ac8(a0, a1);
        case 690: return fde_func_0690_0x054c1c(a0, a1);
        case 691: return fde_func_0691_0x054f48(a0, a1);
        case 692: return fde_func_0692_0x055190(a0, a1);
        case 693: return fde_func_0693_0x055374(a0, a1);
        case 694: return fde_func_0694_0x055480(a0, a1);
        case 695: return fde_func_0695_0x0555e4(a0, a1);
        case 696: return fde_func_0696_0x055750(a0, a1);
        case 697: return fde_func_0697_0x055a20(a0, a1);
        case 698: return fde_func_0698_0x0561e4(a0, a1);
        case 699: return fde_func_0699_0x0562f0(a0, a1);
        case 700: return fde_func_0700_0x056448(a0, a1);
        case 701: return fde_func_0701_0x056630(a0, a1);
        case 702: return fde_func_0702_0x056820(a0, a1);
        case 703: return fde_func_0703_0x056a50(a0, a1);
        case 704: return fde_func_0704_0x056e50(a0, a1);
        case 705: return fde_func_0705_0x0570bc(a0, a1);
        case 706: return fde_func_0706_0x057424(a0, a1);
        case 707: return fde_func_0707_0x057648(a0, a1);
        case 708: return fde_func_0708_0x057808(a0, a1);
        case 709: return fde_func_0709_0x057b28(a0, a1);
        case 710: return fde_func_0710_0x057cd8(a0, a1);
        case 711: return fde_func_0711_0x057ee0(a0, a1);
        case 712: return fde_func_0712_0x058160(a0, a1);
        case 713: return fde_func_0713_0x058540(a0, a1);
        case 714: return fde_func_0714_0x058694(a0, a1);
        case 715: return fde_func_0715_0x058848(a0, a1);
        case 716: return fde_func_0716_0x058988(a0, a1);
        case 717: return fde_func_0717_0x058b84(a0, a1);
        case 718: return fde_func_0718_0x058ef8(a0, a1);
        case 719: return fde_func_0719_0x058ffc(a0, a1);
        case 720: return fde_func_0720_0x059154(a0, a1);
        case 721: return fde_func_0721_0x059320(a0, a1);
        case 722: return fde_func_0722_0x059418(a0, a1);
        case 723: return fde_func_0723_0x0595a8(a0, a1);
        case 724: return fde_func_0724_0x0597b8(a0, a1);
        case 725: return fde_func_0725_0x059ac0(a0, a1);
        case 726: return fde_func_0726_0x059e48(a0, a1);
        case 727: return fde_func_0727_0x05a014(a0, a1);
        case 728: return fde_func_0728_0x05a6a0(a0, a1);
        case 729: return fde_func_0729_0x05b494(a0, a1);
        case 730: return fde_func_0730_0x05b698(a0, a1);
        case 731: return fde_func_0731_0x05b90c(a0, a1);
        case 732: return fde_func_0732_0x05bb8c(a0, a1);
        case 733: return fde_func_0733_0x05c058(a0, a1);
        default: return 0ULL;
    }
}

} // namespace nuro