// ============================================================================
// Clean-Room C++17 AArch64 FDE Shard 3/5 for libfast_engine_RelWithDebInfo.so
// Phân mảnh FDE AArch64 C++17 sạch 3/5 cho libfast_engine_RelWithDebInfo.so
// Covers FDE indices [834 .. 1250] out of 2,082 total FDEs (.eh_frame_hdr @ 0x1127c8)
// Bao phủ chỉ số FDE [834 .. 1250] trên tổng số 2,082 FDE (.eh_frame_hdr @ 0x1127c8)
// ============================================================================
#include "fast_engine_rel_core.h"

namespace fast_engine {

// FDE #0834 | PC: 0x0a4640 | FDE: 0x11f078 | Size: 76 bytes
// Hàm FDE #0834 | Địa chỉ PC: 0x0a4640 | Địa chỉ FDE: 0x11f078 | Kích thước: 76 bytes
//   0x0a4640: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a4644: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a4648: 910043FD  add      x29, sp, #0x10
//   0x0a464c: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_0834_0x0a4640(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4640ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11f078ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0835 | PC: 0x0a468c | FDE: 0x11d1d0 | Size: 208 bytes [_ZNSt6__ndk111basic_regexIcNS_12regex_traitsIcEEE15__push_back_refEi]
// Hàm FDE #0835 | Địa chỉ PC: 0x0a468c | Địa chỉ FDE: 0x11d1d0 | Kích thước: 208 bytes
//   0x0a468c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0a4690: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a4694: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a4698: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0835_0x0a468c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a468cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11d1d0ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #0836 | PC: 0x0a475c | FDE: 0x11d1f0 | Size: 92 bytes [_ZNSt6__ndk118__match_char_icaseIcNS_12regex_traitsIcEEED2Ev]
// Hàm FDE #0836 | Địa chỉ PC: 0x0a475c | Địa chỉ FDE: 0x11d1f0 | Kích thước: 92 bytes
//   0x0a475c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a4760: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a4764: 910043FD  add      x29, sp, #0x10
//   0x0a4768: F00004C8  adrp     x8, #0x13f000
static inline uint64_t fde_func_0836_0x0a475c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a475cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11d1f0ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0837 | PC: 0x0a47b8 | FDE: 0x11d210 | Size: 88 bytes [_ZNSt6__ndk118__match_char_icaseIcNS_12regex_traitsIcEEED0Ev]
// Hàm FDE #0837 | Địa chỉ PC: 0x0a47b8 | Địa chỉ FDE: 0x11d210 | Kích thước: 88 bytes
//   0x0a47b8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a47bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a47c0: 910043FD  add      x29, sp, #0x10
//   0x0a47c4: F00004C8  adrp     x8, #0x13f000
static inline uint64_t fde_func_0837_0x0a47b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a47b8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11d210ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0838 | PC: 0x0a4810 | FDE: 0x11d230 | Size: 120 bytes [_ZNKSt6__ndk118__match_char_icaseIcNS_12regex_traitsIcEEE6__execERNS_7__stateIcEE]
// Hàm FDE #0838 | Địa chỉ PC: 0x0a4810 | Địa chỉ FDE: 0x11d230 | Kích thước: 120 bytes
//   0x0a4810: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a4814: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a4818: 910043FD  add      x29, sp, #0x10
//   0x0a481c: A9412428  ldp      x8, x9, [x1, #0x10]
static inline uint64_t fde_func_0838_0x0a4810(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4810ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11d230ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0839 | PC: 0x0a4888 | FDE: 0x11d250 | Size: 92 bytes [_ZNSt6__ndk120__match_char_collateIcNS_12regex_traitsIcEEED2Ev]
// Hàm FDE #0839 | Địa chỉ PC: 0x0a4888 | Địa chỉ FDE: 0x11d250 | Kích thước: 92 bytes
//   0x0a4888: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a488c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a4890: 910043FD  add      x29, sp, #0x10
//   0x0a4894: F00004C8  adrp     x8, #0x13f000
static inline uint64_t fde_func_0839_0x0a4888(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4888ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11d250ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0840 | PC: 0x0a48e4 | FDE: 0x11d270 | Size: 88 bytes [_ZNSt6__ndk120__match_char_collateIcNS_12regex_traitsIcEEED0Ev]
// Hàm FDE #0840 | Địa chỉ PC: 0x0a48e4 | Địa chỉ FDE: 0x11d270 | Kích thước: 88 bytes
//   0x0a48e4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a48e8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a48ec: 910043FD  add      x29, sp, #0x10
//   0x0a48f0: F00004C8  adrp     x8, #0x13f000
static inline uint64_t fde_func_0840_0x0a48e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a48e4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11d270ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0841 | PC: 0x0a493c | FDE: 0x11d290 | Size: 72 bytes [_ZNKSt6__ndk120__match_char_collateIcNS_12regex_traitsIcEEE6__execERNS_7__stateIcEE]
// Hàm FDE #0841 | Địa chỉ PC: 0x0a493c | Địa chỉ FDE: 0x11d290 | Kích thước: 72 bytes
//   0x0a493c: A9412428  ldp      x8, x9, [x1, #0x10]
//   0x0a4940: EB09011F  cmp      x8, x9
//   0x0a4944: 54000180  b.eq     #0xa4974
//   0x0a4948: 39400109  ldrb     w9, [x8]
static inline uint64_t fde_func_0841_0x0a493c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a493cULL ^ (static_cast<uint64_t>(0xa9412428ULL) << 13);
    acc = (acc + a1 + 0xeb09011fULL) ^ 0x11d290ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0842 | PC: 0x0a4984 | FDE: 0x11d2a8 | Size: 68 bytes [_ZNSt6__ndk112__match_charIcED0Ev]
// Hàm FDE #0842 | Địa chỉ PC: 0x0a4984 | Địa chỉ FDE: 0x11d2a8 | Kích thước: 68 bytes
//   0x0a4984: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a4988: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a498c: 910043FD  add      x29, sp, #0x10
//   0x0a4990: F00004C8  adrp     x8, #0x13f000
static inline uint64_t fde_func_0842_0x0a4984(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4984ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11d2a8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0843 | PC: 0x0a49c8 | FDE: 0x11d2c8 | Size: 72 bytes [_ZNKSt6__ndk112__match_charIcE6__execERNS_7__stateIcEE]
// Hàm FDE #0843 | Địa chỉ PC: 0x0a49c8 | Địa chỉ FDE: 0x11d2c8 | Kích thước: 72 bytes
//   0x0a49c8: A9412428  ldp      x8, x9, [x1, #0x10]
//   0x0a49cc: EB09011F  cmp      x8, x9
//   0x0a49d0: 54000180  b.eq     #0xa4a00
//   0x0a49d4: 39400109  ldrb     w9, [x8]
static inline uint64_t fde_func_0843_0x0a49c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a49c8ULL ^ (static_cast<uint64_t>(0xa9412428ULL) << 13);
    acc = (acc + a1 + 0xeb09011fULL) ^ 0x11d2c8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0844 | PC: 0x0a4a10 | FDE: 0x11d2e0 | Size: 92 bytes [_ZNSt6__ndk116__back_ref_icaseIcNS_12regex_traitsIcEEED2Ev]
// Hàm FDE #0844 | Địa chỉ PC: 0x0a4a10 | Địa chỉ FDE: 0x11d2e0 | Kích thước: 92 bytes
//   0x0a4a10: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a4a14: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a4a18: 910043FD  add      x29, sp, #0x10
//   0x0a4a1c: F00004C8  adrp     x8, #0x13f000
static inline uint64_t fde_func_0844_0x0a4a10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4a10ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11d2e0ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0845 | PC: 0x0a4a6c | FDE: 0x11d300 | Size: 88 bytes [_ZNSt6__ndk116__back_ref_icaseIcNS_12regex_traitsIcEEED0Ev]
// Hàm FDE #0845 | Địa chỉ PC: 0x0a4a6c | Địa chỉ FDE: 0x11d300 | Kích thước: 88 bytes
//   0x0a4a6c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a4a70: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a4a74: 910043FD  add      x29, sp, #0x10
//   0x0a4a78: F00004C8  adrp     x8, #0x13f000
static inline uint64_t fde_func_0845_0x0a4a6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4a6cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11d300ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0846 | PC: 0x0a4ac4 | FDE: 0x11d320 | Size: 256 bytes [_ZNKSt6__ndk116__back_ref_icaseIcNS_12regex_traitsIcEEE6__execERNS_7__stateIcEE]
// Hàm FDE #0846 | Địa chỉ PC: 0x0a4ac4 | Địa chỉ FDE: 0x11d320 | Kích thước: 256 bytes
//   0x0a4ac4: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0a4ac8: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0a4acc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0a4ad0: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0846_0x0a4ac4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4ac4ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11d320ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0847 | PC: 0x0a4bcc | FDE: 0x11d348 | Size: 92 bytes [_ZNSt6__ndk118__back_ref_collateIcNS_12regex_traitsIcEEED2Ev]
// Hàm FDE #0847 | Địa chỉ PC: 0x0a4bcc | Địa chỉ FDE: 0x11d348 | Kích thước: 92 bytes
//   0x0a4bcc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a4bd0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a4bd4: 910043FD  add      x29, sp, #0x10
//   0x0a4bd8: F00004C8  adrp     x8, #0x13f000
static inline uint64_t fde_func_0847_0x0a4bcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4bccULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11d348ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0848 | PC: 0x0a4c28 | FDE: 0x11d368 | Size: 88 bytes [_ZNSt6__ndk118__back_ref_collateIcNS_12regex_traitsIcEEED0Ev]
// Hàm FDE #0848 | Địa chỉ PC: 0x0a4c28 | Địa chỉ FDE: 0x11d368 | Kích thước: 88 bytes
//   0x0a4c28: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a4c2c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a4c30: 910043FD  add      x29, sp, #0x10
//   0x0a4c34: F00004C8  adrp     x8, #0x13f000
static inline uint64_t fde_func_0848_0x0a4c28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4c28ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11d368ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0849 | PC: 0x0a4c80 | FDE: 0x11d388 | Size: 152 bytes [_ZNKSt6__ndk118__back_ref_collateIcNS_12regex_traitsIcEEE6__execERNS_7__stateIcEE]
// Hàm FDE #0849 | Địa chỉ PC: 0x0a4c80 | Địa chỉ FDE: 0x11d388 | Kích thước: 152 bytes
//   0x0a4c80: B9402809  ldr      w9, [x0, #0x28]
//   0x0a4c84: F9401028  ldr      x8, [x1, #0x20]
//   0x0a4c88: 5280030A  mov      w10, #0x18
//   0x0a4c8c: 51000529  sub      w9, w9, #1
static inline uint64_t fde_func_0849_0x0a4c80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4c80ULL ^ (static_cast<uint64_t>(0xb9402809ULL) << 13);
    acc = (acc + a1 + 0xf9401028ULL) ^ 0x11d388ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0850 | PC: 0x0a4d18 | FDE: 0x11d3a0 | Size: 68 bytes [_ZNSt6__ndk110__back_refIcED0Ev]
// Hàm FDE #0850 | Địa chỉ PC: 0x0a4d18 | Địa chỉ FDE: 0x11d3a0 | Kích thước: 68 bytes
//   0x0a4d18: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a4d1c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a4d20: 910043FD  add      x29, sp, #0x10
//   0x0a4d24: F00004C8  adrp     x8, #0x13f000
static inline uint64_t fde_func_0850_0x0a4d18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4d18ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11d3a0ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0851 | PC: 0x0a4d5c | FDE: 0x11d3c0 | Size: 196 bytes [_ZNKSt6__ndk110__back_refIcE6__execERNS_7__stateIcEE]
// Hàm FDE #0851 | Địa chỉ PC: 0x0a4d5c | Địa chỉ FDE: 0x11d3c0 | Kích thước: 196 bytes
//   0x0a4d5c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a4d60: 910003FD  mov      x29, sp
//   0x0a4d64: A9422828  ldp      x8, x10, [x1, #0x20]
//   0x0a4d68: B9401009  ldr      w9, [x0, #0x10]
static inline uint64_t fde_func_0851_0x0a4d5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4d5cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x11d3c0ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0852 | PC: 0x0a4e20 | FDE: 0x11d3e0 | Size: 256 bytes
// Hàm FDE #0852 | Địa chỉ PC: 0x0a4e20 | Địa chỉ FDE: 0x11d3e0 | Kích thước: 256 bytes
//   0x0a4e20: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0a4e24: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0a4e28: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0a4e2c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0852_0x0a4e20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4e20ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11d3e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0853 | PC: 0x0a4fd4 | FDE: 0x11f0a0 | Size: 256 bytes
// Hàm FDE #0853 | Địa chỉ PC: 0x0a4fd4 | Địa chỉ FDE: 0x11f0a0 | Kích thước: 256 bytes
//   0x0a4fd4: D10203FF  sub      sp, sp, #0x80
//   0x0a4fd8: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0a4fdc: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0a4fe0: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_0853_0x0a4fd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4fd4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90367faULL) ^ 0x11f0a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0854 | PC: 0x0a5238 | FDE: 0x11d408 | Size: 256 bytes [_ZNSt6__ndk120__bracket_expressionIcNS_12regex_traitsIcEEED2Ev]
// Hàm FDE #0854 | Địa chỉ PC: 0x0a5238 | Địa chỉ FDE: 0x11d408 | Kích thước: 256 bytes
//   0x0a5238: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0a523c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a5240: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a5244: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0854_0x0a5238(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5238ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11d408ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0855 | PC: 0x0a5398 | FDE: 0x11d430 | Size: 36 bytes [_ZNSt6__ndk120__bracket_expressionIcNS_12regex_traitsIcEEED0Ev]
// Hàm FDE #0855 | Địa chỉ PC: 0x0a5398 | Địa chỉ FDE: 0x11d430 | Kích thước: 36 bytes
//   0x0a5398: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a539c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a53a0: 910043FD  add      x29, sp, #0x10
//   0x0a53a4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0855_0x0a5398(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5398ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11d430ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0856 | PC: 0x0a53bc | FDE: 0x11f0d8 | Size: 256 bytes [_ZNKSt6__ndk120__bracket_expressionIcNS_12regex_traitsIcEEE6__execERNS_7__stateIcEE]
// Hàm FDE #0856 | Địa chỉ PC: 0x0a53bc | Địa chỉ FDE: 0x11f0d8 | Kích thước: 256 bytes
//   0x0a53bc: D10303FF  sub      sp, sp, #0xc0
//   0x0a53c0: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x0a53c4: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x0a53c8: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_0856_0x0a53bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a53bcULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x11f0d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0857 | PC: 0x0a5db0 | FDE: 0x11f110 | Size: 256 bytes [_ZNKSt6__ndk112regex_traitsIcE20__lookup_collatenameIPcEENS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEET_SA_c]
// Hàm FDE #0857 | Địa chỉ PC: 0x0a5db0 | Địa chỉ FDE: 0x11f110 | Kích thước: 256 bytes
//   0x0a5db0: D10243FF  sub      sp, sp, #0x90
//   0x0a5db4: F90023F9  str      x25, [sp, #0x40]
//   0x0a5db8: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x0a5dbc: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_0857_0x0a5db0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5db0ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90023f9ULL) ^ 0x11f110ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0858 | PC: 0x0a6094 | FDE: 0x11f140 | Size: 256 bytes [_ZNKSt6__ndk112regex_traitsIcE19__transform_primaryIPcEENS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEET_SA_c]
// Hàm FDE #0858 | Địa chỉ PC: 0x0a6094 | Địa chỉ FDE: 0x11f140 | Kích thước: 256 bytes
//   0x0a6094: D101C3FF  sub      sp, sp, #0x70
//   0x0a6098: F90013F9  str      x25, [sp, #0x20]
//   0x0a609c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0a60a0: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0858_0x0a6094(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a6094ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x11f140ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0859 | PC: 0x0a6290 | FDE: 0x11f170 | Size: 76 bytes
// Hàm FDE #0859 | Địa chỉ PC: 0x0a6290 | Địa chỉ FDE: 0x11f170 | Kích thước: 76 bytes
//   0x0a6290: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a6294: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a6298: 910043FD  add      x29, sp, #0x10
//   0x0a629c: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_0859_0x0a6290(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a6290ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11f170ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0860 | PC: 0x0a62dc | FDE: 0x11f198 | Size: 256 bytes [_ZNSt6__ndk111basic_regexIcNS_12regex_traitsIcEEE23__parse_expression_termINS_11__wrap_iterIPKcEEEET_S9_S9_PNS_20__bracket_expressionIcS2_EE]
// Hàm FDE #0860 | Địa chỉ PC: 0x0a62dc | Địa chỉ FDE: 0x11f198 | Kích thước: 256 bytes
//   0x0a62dc: D10303FF  sub      sp, sp, #0xc0
//   0x0a62e0: F9003BF9  str      x25, [sp, #0x70]
//   0x0a62e4: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x0a62e8: A90957F6  stp      x22, x21, [sp, #0x90]
static inline uint64_t fde_func_0860_0x0a62dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a62dcULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf9ULL) ^ 0x11f198ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0861 | PC: 0x0a6798 | FDE: 0x11f1c8 | Size: 256 bytes [_ZNSt6__ndk111basic_regexIcNS_12regex_traitsIcEEE25__parse_equivalence_classINS_11__wrap_iterIPKcEEEET_S9_S9_PNS_20__bracket_expressionIcS2_EE]
// Hàm FDE #0861 | Địa chỉ PC: 0x0a6798 | Địa chỉ FDE: 0x11f1c8 | Kích thước: 256 bytes
//   0x0a6798: D10243FF  sub      sp, sp, #0x90
//   0x0a679c: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0a67a0: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x0a67a4: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_0861_0x0a6798(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a6798ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90467faULL) ^ 0x11f1c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0862 | PC: 0x0a6a98 | FDE: 0x11d450 | Size: 240 bytes [_ZNSt6__ndk111basic_regexIcNS_12regex_traitsIcEEE23__parse_character_classINS_11__wrap_iterIPKcEEEET_S9_S9_PNS_20__bracket_expressionIcS2_EE]
// Hàm FDE #0862 | Địa chỉ PC: 0x0a6a98 | Địa chỉ FDE: 0x11d450 | Kích thước: 240 bytes
//   0x0a6a98: D100C3FF  sub      sp, sp, #0x30
//   0x0a6a9c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a6aa0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a6aa4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0862_0x0a6a98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a6a98ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11d450ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #0863 | PC: 0x0a6b88 | FDE: 0x11d470 | Size: 256 bytes [_ZNSt6__ndk111basic_regexIcNS_12regex_traitsIcEEE24__parse_collating_symbolINS_11__wrap_iterIPKcEEEET_S9_S9_RNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE]
// Hàm FDE #0863 | Địa chỉ PC: 0x0a6b88 | Địa chỉ FDE: 0x11d470 | Kích thước: 256 bytes
//   0x0a6b88: D10183FF  sub      sp, sp, #0x60
//   0x0a6b8c: F9001BF5  str      x21, [sp, #0x30]
//   0x0a6b90: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0a6b94: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0863_0x0a6b88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a6b88ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x11d470ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0864 | PC: 0x0a6ce8 | FDE: 0x11d490 | Size: 256 bytes [_ZNSt6__ndk111basic_regexIcNS_12regex_traitsIcEEE20__parse_class_escapeINS_11__wrap_iterIPKcEEEET_S9_S9_RNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPNS_20__bracket_expressionIcS2_EE]
// Hàm FDE #0864 | Địa chỉ PC: 0x0a6ce8 | Địa chỉ FDE: 0x11d490 | Kích thước: 256 bytes
//   0x0a6ce8: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0a6cec: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0a6cf0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0a6cf4: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0864_0x0a6ce8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a6ce8ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11d490ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0865 | PC: 0x0a6f8c | FDE: 0x11d4c0 | Size: 256 bytes [_ZNSt6__ndk111basic_regexIcNS_12regex_traitsIcEEE18__parse_awk_escapeINS_11__wrap_iterIPKcEEEET_S9_S9_PNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE]
// Hàm FDE #0865 | Địa chỉ PC: 0x0a6f8c | Địa chỉ FDE: 0x11d4c0 | Kích thước: 256 bytes
//   0x0a6f8c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a6f90: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a6f94: 910043FD  add      x29, sp, #0x10
//   0x0a6f98: EB02003F  cmp      x1, x2
static inline uint64_t fde_func_0865_0x0a6f8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a6f8cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11d4c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0866 | PC: 0x0a723c | FDE: 0x11f200 | Size: 256 bytes
// Hàm FDE #0866 | Địa chỉ PC: 0x0a723c | Địa chỉ FDE: 0x11f200 | Kích thước: 256 bytes
//   0x0a723c: D102C3FF  sub      sp, sp, #0xb0
//   0x0a7240: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x0a7244: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x0a7248: A9094FF4  stp      x20, x19, [sp, #0x90]
static inline uint64_t fde_func_0866_0x0a723c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a723cULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9075ff8ULL) ^ 0x11f200ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0867 | PC: 0x0a779c | FDE: 0x11d4e0 | Size: 248 bytes
// Hàm FDE #0867 | Địa chỉ PC: 0x0a779c | Địa chỉ FDE: 0x11d4e0 | Kích thước: 248 bytes
//   0x0a779c: D10143FF  sub      sp, sp, #0x50
//   0x0a77a0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0a77a4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0a77a8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0867_0x0a779c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a779cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x11d4e0ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0868 | PC: 0x0a7894 | FDE: 0x11f230 | Size: 76 bytes
// Hàm FDE #0868 | Địa chỉ PC: 0x0a7894 | Địa chỉ FDE: 0x11f230 | Kích thước: 76 bytes
//   0x0a7894: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a7898: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a789c: 910043FD  add      x29, sp, #0x10
//   0x0a78a0: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_0868_0x0a7894(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7894ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11f230ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0869 | PC: 0x0a78e0 | FDE: 0x11f258 | Size: 256 bytes [_ZNKSt6__ndk112regex_traitsIcE20__lookup_collatenameINS_11__wrap_iterIPKcEEEENS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEET_SD_c]
// Hàm FDE #0869 | Địa chỉ PC: 0x0a78e0 | Địa chỉ FDE: 0x11f258 | Kích thước: 256 bytes
//   0x0a78e0: D10243FF  sub      sp, sp, #0x90
//   0x0a78e4: F90023F9  str      x25, [sp, #0x40]
//   0x0a78e8: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x0a78ec: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_0869_0x0a78e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a78e0ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90023f9ULL) ^ 0x11f258ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0870 | PC: 0x0a7be4 | FDE: 0x11f288 | Size: 256 bytes [_ZNKSt6__ndk112regex_traitsIcE19__transform_primaryINS_11__wrap_iterIPcEEEENS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEET_SC_c]
// Hàm FDE #0870 | Địa chỉ PC: 0x0a7be4 | Địa chỉ FDE: 0x11f288 | Kích thước: 256 bytes
//   0x0a7be4: D101C3FF  sub      sp, sp, #0x70
//   0x0a7be8: F90013F9  str      x25, [sp, #0x20]
//   0x0a7bec: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0a7bf0: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0870_0x0a7be4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7be4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x11f288ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0871 | PC: 0x0a7e00 | FDE: 0x11f2b8 | Size: 256 bytes [_ZNSt6__ndk16vectorINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEE21__push_back_slow_pathIRKS6_EEvOT_]
// Hàm FDE #0871 | Địa chỉ PC: 0x0a7e00 | Địa chỉ FDE: 0x11f2b8 | Kích thước: 256 bytes
//   0x0a7e00: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0a7e04: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0a7e08: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a7e0c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0871_0x0a7e00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7e00ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11f2b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0872 | PC: 0x0a7f80 | FDE: 0x11f2e8 | Size: 76 bytes
// Hàm FDE #0872 | Địa chỉ PC: 0x0a7f80 | Địa chỉ FDE: 0x11f2e8 | Kích thước: 76 bytes
//   0x0a7f80: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a7f84: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a7f88: 910043FD  add      x29, sp, #0x10
//   0x0a7f8c: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_0872_0x0a7f80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7f80ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11f2e8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0873 | PC: 0x0a7fcc | FDE: 0x11f310 | Size: 256 bytes [_ZNKSt6__ndk112regex_traitsIcE18__lookup_classnameINS_11__wrap_iterIPKcEEEEtT_S7_bc]
// Hàm FDE #0873 | Địa chỉ PC: 0x0a7fcc | Địa chỉ FDE: 0x11f310 | Kích thước: 256 bytes
//   0x0a7fcc: D101C3FF  sub      sp, sp, #0x70
//   0x0a7fd0: F90013F9  str      x25, [sp, #0x20]
//   0x0a7fd4: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0a7fd8: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0873_0x0a7fcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7fccULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x11f310ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0874 | PC: 0x0a8194 | FDE: 0x11f340 | Size: 256 bytes [_ZNKSt6__ndk112regex_traitsIcE9transformINS_11__wrap_iterIPcEEEENS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEET_SC_]
// Hàm FDE #0874 | Địa chỉ PC: 0x0a8194 | Địa chỉ FDE: 0x11f340 | Kích thước: 256 bytes
//   0x0a8194: D101C3FF  sub      sp, sp, #0x70
//   0x0a8198: F90013F9  str      x25, [sp, #0x20]
//   0x0a819c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0a81a0: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0874_0x0a8194(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8194ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x11f340ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0875 | PC: 0x0a8340 | FDE: 0x11f370 | Size: 76 bytes
// Hàm FDE #0875 | Địa chỉ PC: 0x0a8340 | Địa chỉ FDE: 0x11f370 | Kích thước: 76 bytes
//   0x0a8340: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a8344: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a8348: 910043FD  add      x29, sp, #0x10
//   0x0a834c: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_0875_0x0a8340(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8340ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11f370ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0876 | PC: 0x0a838c | FDE: 0x11d508 | Size: 256 bytes [_ZNSt6__ndk16vectorINS_4pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EENS5_IS8_EEE21__push_back_slow_pathIS8_EEvOT_]
// Hàm FDE #0876 | Địa chỉ PC: 0x0a838c | Địa chỉ FDE: 0x11d508 | Kích thước: 256 bytes
//   0x0a838c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0a8390: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a8394: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a8398: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0876_0x0a838c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a838cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11d508ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0877 | PC: 0x0a8528 | FDE: 0x11d530 | Size: 256 bytes [_ZNSt6__ndk16vectorINS_4pairIccEENS_9allocatorIS2_EEE21__push_back_slow_pathIS2_EEvOT_]
// Hàm FDE #0877 | Địa chỉ PC: 0x0a8528 | Địa chỉ FDE: 0x11d530 | Kích thước: 256 bytes
//   0x0a8528: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0a852c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0a8530: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0a8534: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0877_0x0a8528(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8528ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11d530ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0878 | PC: 0x0a8628 | FDE: 0x11d560 | Size: 68 bytes [_ZNSt6__ndk128__begin_marked_subexpressionIcED0Ev]
// Hàm FDE #0878 | Địa chỉ PC: 0x0a8628 | Địa chỉ FDE: 0x11d560 | Kích thước: 68 bytes
//   0x0a8628: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a862c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a8630: 910043FD  add      x29, sp, #0x10
//   0x0a8634: F00004A8  adrp     x8, #0x13f000
static inline uint64_t fde_func_0878_0x0a8628(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8628ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11d560ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0879 | PC: 0x0a866c | FDE: 0x11d580 | Size: 48 bytes [_ZNKSt6__ndk128__begin_marked_subexpressionIcE6__execERNS_7__stateIcEE]
// Hàm FDE #0879 | Địa chỉ PC: 0x0a866c | Địa chỉ FDE: 0x11d580 | Kích thước: 48 bytes
//   0x0a866c: 12807C28  mov      w8, #-0x3e2
//   0x0a8670: B9000028  str      w8, [x1]
//   0x0a8674: B9401008  ldr      w8, [x0, #0x10]
//   0x0a8678: F9400829  ldr      x9, [x1, #0x10]
static inline uint64_t fde_func_0879_0x0a866c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a866cULL ^ (static_cast<uint64_t>(0x12807c28ULL) << 13);
    acc = (acc + a1 + 0xb9000028ULL) ^ 0x11d580ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0880 | PC: 0x0a869c | FDE: 0x11d598 | Size: 68 bytes [_ZNSt6__ndk126__end_marked_subexpressionIcED0Ev]
// Hàm FDE #0880 | Địa chỉ PC: 0x0a869c | Địa chỉ FDE: 0x11d598 | Kích thước: 68 bytes
//   0x0a869c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a86a0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a86a4: 910043FD  add      x29, sp, #0x10
//   0x0a86a8: F00004A8  adrp     x8, #0x13f000
static inline uint64_t fde_func_0880_0x0a869c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a869cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11d598ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0881 | PC: 0x0a86e0 | FDE: 0x11d5b8 | Size: 56 bytes [_ZNKSt6__ndk126__end_marked_subexpressionIcE6__execERNS_7__stateIcEE]
// Hàm FDE #0881 | Địa chỉ PC: 0x0a86e0 | Địa chỉ FDE: 0x11d5b8 | Kích thước: 56 bytes
//   0x0a86e0: 12807C28  mov      w8, #-0x3e2
//   0x0a86e4: B9000028  str      w8, [x1]
//   0x0a86e8: B9401008  ldr      w8, [x0, #0x10]
//   0x0a86ec: F940102A  ldr      x10, [x1, #0x20]
static inline uint64_t fde_func_0881_0x0a86e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a86e0ULL ^ (static_cast<uint64_t>(0x12807c28ULL) << 13);
    acc = (acc + a1 + 0xb9000028ULL) ^ 0x11d5b8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0882 | PC: 0x0a8718 | FDE: 0x11f398 | Size: 256 bytes [_ZNSt6__ndk111basic_regexIcNS_12regex_traitsIcEEE11__push_loopEmmPNS_16__owns_one_stateIcEEmmb]
// Hàm FDE #0882 | Địa chỉ PC: 0x0a8718 | Địa chỉ FDE: 0x11f398 | Kích thước: 256 bytes
//   0x0a8718: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0a871c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0a8720: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0a8724: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0882_0x0a8718(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8718ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x11f398ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0883 | PC: 0x0a88a0 | FDE: 0x11f3d0 | Size: 76 bytes
// Hàm FDE #0883 | Địa chỉ PC: 0x0a88a0 | Địa chỉ FDE: 0x11f3d0 | Kích thước: 76 bytes
//   0x0a88a0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a88a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a88a8: 910043FD  add      x29, sp, #0x10
//   0x0a88ac: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_0883_0x0a88a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a88a0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11f3d0ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0884 | PC: 0x0a88ec | FDE: 0x11f3f8 | Size: 76 bytes
// Hàm FDE #0884 | Địa chỉ PC: 0x0a88ec | Địa chỉ FDE: 0x11f3f8 | Kích thước: 76 bytes
//   0x0a88ec: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a88f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a88f4: 910043FD  add      x29, sp, #0x10
//   0x0a88f8: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_0884_0x0a88ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a88ecULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11f3f8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0885 | PC: 0x0a8938 | FDE: 0x11d5d0 | Size: 108 bytes [_ZNSt6__ndk117__owns_two_statesIcED2Ev]
// Hàm FDE #0885 | Địa chỉ PC: 0x0a8938 | Địa chỉ FDE: 0x11d5d0 | Kích thước: 108 bytes
//   0x0a8938: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a893c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a8940: 910043FD  add      x29, sp, #0x10
//   0x0a8944: F00004A8  adrp     x8, #0x13f000
static inline uint64_t fde_func_0885_0x0a8938(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8938ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11d5d0ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #0886 | PC: 0x0a89a4 | FDE: 0x11d5f0 | Size: 104 bytes [_ZNSt6__ndk16__loopIcED0Ev]
// Hàm FDE #0886 | Địa chỉ PC: 0x0a89a4 | Địa chỉ FDE: 0x11d5f0 | Kích thước: 104 bytes
//   0x0a89a4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a89a8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a89ac: 910043FD  add      x29, sp, #0x10
//   0x0a89b0: F00004A8  adrp     x8, #0x13f000
static inline uint64_t fde_func_0886_0x0a89a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a89a4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11d5f0ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0887 | PC: 0x0a8a0c | FDE: 0x11d610 | Size: 256 bytes [_ZNKSt6__ndk16__loopIcE6__execERNS_7__stateIcEE]
// Hàm FDE #0887 | Địa chỉ PC: 0x0a8a0c | Địa chỉ FDE: 0x11d610 | Kích thước: 256 bytes
//   0x0a8a0c: B940002A  ldr      w10, [x1]
//   0x0a8a10: B9402808  ldr      w8, [x0, #0x28]
//   0x0a8a14: F9401C29  ldr      x9, [x1, #0x38]
//   0x0a8a18: 310F7D5F  cmn      w10, #0x3df
static inline uint64_t fde_func_0887_0x0a8a0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8a0cULL ^ (static_cast<uint64_t>(0xb940002aULL) << 13);
    acc = (acc + a1 + 0xb9402808ULL) ^ 0x11d610ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0888 | PC: 0x0a8bfc | FDE: 0x11d628 | Size: 204 bytes [_ZNKSt6__ndk16__loopIcE12__exec_splitEbRNS_7__stateIcEE]
// Hàm FDE #0888 | Địa chỉ PC: 0x0a8bfc | Địa chỉ FDE: 0x11d628 | Kích thước: 204 bytes
//   0x0a8bfc: 12807C28  mov      w8, #-0x3e2
//   0x0a8c00: B9000048  str      w8, [x2]
//   0x0a8c04: 3940D008  ldrb     w8, [x0, #0x34]
//   0x0a8c08: 12000029  and      w9, w1, #1
static inline uint64_t fde_func_0888_0x0a8bfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8bfcULL ^ (static_cast<uint64_t>(0x12807c28ULL) << 13);
    acc = (acc + a1 + 0xb9000048ULL) ^ 0x11d628ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #0889 | PC: 0x0a8cc8 | FDE: 0x11d640 | Size: 104 bytes [_ZNSt6__ndk117__owns_two_statesIcED0Ev]
// Hàm FDE #0889 | Địa chỉ PC: 0x0a8cc8 | Địa chỉ FDE: 0x11d640 | Kích thước: 104 bytes
//   0x0a8cc8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a8ccc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a8cd0: 910043FD  add      x29, sp, #0x10
//   0x0a8cd4: F00004A8  adrp     x8, #0x13f000
static inline uint64_t fde_func_0889_0x0a8cc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8cc8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11d640ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0890 | PC: 0x0a8d30 | FDE: 0x11d660 | Size: 4 bytes
// Hàm FDE #0890 | Địa chỉ PC: 0x0a8d30 | Địa chỉ FDE: 0x11d660 | Kích thước: 4 bytes
//   0x0a8d30: D65F03C0  ret      
static inline uint64_t fde_func_0890_0x0a8d30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8d30ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0x17fe662bULL) ^ 0x11d660ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0891 | PC: 0x0a8d34 | FDE: 0x11d678 | Size: 4 bytes [_ZNSt6__ndk117__repeat_one_loopIcED0Ev]
// Hàm FDE #0891 | Địa chỉ PC: 0x0a8d34 | Địa chỉ FDE: 0x11d678 | Kích thước: 4 bytes
//   0x0a8d34: 17FE662B  b        #0x425e0
static inline uint64_t fde_func_0891_0x0a8d34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8d34ULL ^ (static_cast<uint64_t>(0x17fe662bULL) << 13);
    acc = (acc + a1 + 0x12807bc8ULL) ^ 0x11d678ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0892 | PC: 0x0a8d38 | FDE: 0x11d690 | Size: 20 bytes [_ZNKSt6__ndk117__repeat_one_loopIcE6__execERNS_7__stateIcEE]
// Hàm FDE #0892 | Địa chỉ PC: 0x0a8d38 | Địa chỉ FDE: 0x11d690 | Kích thước: 20 bytes
//   0x0a8d38: 12807BC8  mov      w8, #-0x3df
//   0x0a8d3c: B9000028  str      w8, [x1]
//   0x0a8d40: F9400408  ldr      x8, [x0, #8]
//   0x0a8d44: F9002828  str      x8, [x1, #0x50]
static inline uint64_t fde_func_0892_0x0a8d38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8d38ULL ^ (static_cast<uint64_t>(0x12807bc8ULL) << 13);
    acc = (acc + a1 + 0xb9000028ULL) ^ 0x11d690ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0893 | PC: 0x0a8d4c | FDE: 0x11d6a8 | Size: 104 bytes [_ZNSt6__ndk111__alternateIcED0Ev]
// Hàm FDE #0893 | Địa chỉ PC: 0x0a8d4c | Địa chỉ FDE: 0x11d6a8 | Kích thước: 104 bytes
//   0x0a8d4c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a8d50: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a8d54: 910043FD  add      x29, sp, #0x10
//   0x0a8d58: F00004A8  adrp     x8, #0x13f000
static inline uint64_t fde_func_0893_0x0a8d4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8d4cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11d6a8ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0894 | PC: 0x0a8db4 | FDE: 0x11d6c8 | Size: 12 bytes [_ZNKSt6__ndk111__alternateIcE6__execERNS_7__stateIcEE]
// Hàm FDE #0894 | Địa chỉ PC: 0x0a8db4 | Địa chỉ FDE: 0x11d6c8 | Kích thước: 12 bytes
//   0x0a8db4: 12807BE8  mov      w8, #-0x3e0
//   0x0a8db8: B9000028  str      w8, [x1]
//   0x0a8dbc: D65F03C0  ret      
static inline uint64_t fde_func_0894_0x0a8db4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8db4ULL ^ (static_cast<uint64_t>(0x12807be8ULL) << 13);
    acc = (acc + a1 + 0xb9000028ULL) ^ 0x11d6c8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0895 | PC: 0x0a8dc0 | FDE: 0x11d6e0 | Size: 36 bytes [_ZNKSt6__ndk111__alternateIcE12__exec_splitEbRNS_7__stateIcEE]
// Hàm FDE #0895 | Địa chỉ PC: 0x0a8dc0 | Địa chỉ FDE: 0x11d6e0 | Kích thước: 36 bytes
//   0x0a8dc0: 12807C28  mov      w8, #-0x3e2
//   0x0a8dc4: B9000048  str      w8, [x2]
//   0x0a8dc8: 36000081  tbz      w1, #0, #0xa8dd8
//   0x0a8dcc: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_0895_0x0a8dc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8dc0ULL ^ (static_cast<uint64_t>(0x12807c28ULL) << 13);
    acc = (acc + a1 + 0xb9000048ULL) ^ 0x11d6e0ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0896 | PC: 0x0a8de4 | FDE: 0x11d6f8 | Size: 4 bytes [_ZNSt6__ndk121__empty_non_own_stateIcED0Ev]
// Hàm FDE #0896 | Địa chỉ PC: 0x0a8de4 | Địa chỉ FDE: 0x11d6f8 | Kích thước: 4 bytes
//   0x0a8de4: 17FE65FF  b        #0x425e0
static inline uint64_t fde_func_0896_0x0a8de4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8de4ULL ^ (static_cast<uint64_t>(0x17fe65ffULL) << 13);
    acc = (acc + a1 + 0x12807c28ULL) ^ 0x11d6f8ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0897 | PC: 0x0a8de8 | FDE: 0x11d710 | Size: 20 bytes [_ZNKSt6__ndk121__empty_non_own_stateIcE6__execERNS_7__stateIcEE]
// Hàm FDE #0897 | Địa chỉ PC: 0x0a8de8 | Địa chỉ FDE: 0x11d710 | Kích thước: 20 bytes
//   0x0a8de8: 12807C28  mov      w8, #-0x3e2
//   0x0a8dec: B9000028  str      w8, [x1]
//   0x0a8df0: F9400408  ldr      x8, [x0, #8]
//   0x0a8df4: F9002828  str      x8, [x1, #0x50]
static inline uint64_t fde_func_0897_0x0a8de8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8de8ULL ^ (static_cast<uint64_t>(0x12807c28ULL) << 13);
    acc = (acc + a1 + 0xb9000028ULL) ^ 0x11d710ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0898 | PC: 0x0a8dfc | FDE: 0x11f420 | Size: 76 bytes
// Hàm FDE #0898 | Địa chỉ PC: 0x0a8dfc | Địa chỉ FDE: 0x11f420 | Kích thước: 76 bytes
//   0x0a8dfc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a8e00: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a8e04: 910043FD  add      x29, sp, #0x10
//   0x0a8e08: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_0898_0x0a8dfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8dfcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11f420ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0899 | PC: 0x0a8e48 | FDE: 0x11d728 | Size: 256 bytes [_ZNSt6__ndk111basic_regexIcNS_12regex_traitsIcEEE18__parse_nondupl_REINS_11__wrap_iterIPKcEEEET_S9_S9_]
// Hàm FDE #0899 | Địa chỉ PC: 0x0a8e48 | Địa chỉ FDE: 0x11d728 | Kích thước: 256 bytes
//   0x0a8e48: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0a8e4c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0a8e50: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a8e54: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0899_0x0a8e48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8e48ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11d728ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0900 | PC: 0x0a9054 | FDE: 0x11d750 | Size: 256 bytes [_ZNSt6__ndk111basic_regexIcNS_12regex_traitsIcEEE22__parse_RE_dupl_symbolINS_11__wrap_iterIPKcEEEET_S9_S9_PNS_16__owns_one_stateIcEEjj]
// Hàm FDE #0900 | Địa chỉ PC: 0x0a9054 | Địa chỉ FDE: 0x11d750 | Kích thước: 256 bytes
//   0x0a9054: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a9058: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a905c: 910043FD  add      x29, sp, #0x10
//   0x0a9060: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0900_0x0a9054(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9054ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11d750ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0901 | PC: 0x0a9374 | FDE: 0x11d770 | Size: 256 bytes [_ZNSt6__ndk111basic_regexIcNS_12regex_traitsIcEEE32__parse_one_char_or_coll_elem_REINS_11__wrap_iterIPKcEEEET_S9_S9_]
// Hàm FDE #0901 | Địa chỉ PC: 0x0a9374 | Địa chỉ FDE: 0x11d770 | Kích thước: 256 bytes
//   0x0a9374: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0a9378: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a937c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a9380: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0901_0x0a9374(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9374ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11d770ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0902 | PC: 0x0a9490 | FDE: 0x11d790 | Size: 44 bytes [_ZNSt6__ndk116__owns_one_stateIcED2Ev]
// Hàm FDE #0902 | Địa chỉ PC: 0x0a9490 | Địa chỉ FDE: 0x11d790 | Kích thước: 44 bytes
//   0x0a9490: D00004A9  adrp     x9, #0x13f000
//   0x0a9494: AA0003E8  mov      x8, x0
//   0x0a9498: F9400400  ldr      x0, [x0, #8]
//   0x0a949c: F947B529  ldr      x9, [x9, #0xf68]
static inline uint64_t fde_func_0902_0x0a9490(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9490ULL ^ (static_cast<uint64_t>(0xd00004a9ULL) << 13);
    acc = (acc + a1 + 0xaa0003e8ULL) ^ 0x11d790ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0903 | PC: 0x0a94bc | FDE: 0x11d7a8 | Size: 68 bytes [_ZNSt6__ndk111__match_anyIcED0Ev]
// Hàm FDE #0903 | Địa chỉ PC: 0x0a94bc | Địa chỉ FDE: 0x11d7a8 | Kích thước: 68 bytes
//   0x0a94bc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a94c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a94c4: 910043FD  add      x29, sp, #0x10
//   0x0a94c8: D00004A8  adrp     x8, #0x13f000
static inline uint64_t fde_func_0903_0x0a94bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a94bcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11d7a8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0904 | PC: 0x0a9500 | FDE: 0x11d7c8 | Size: 64 bytes [_ZNKSt6__ndk111__match_anyIcE6__execERNS_7__stateIcEE]
// Hàm FDE #0904 | Địa chỉ PC: 0x0a9500 | Địa chỉ FDE: 0x11d7c8 | Kích thước: 64 bytes
//   0x0a9500: A9412428  ldp      x8, x9, [x1, #0x10]
//   0x0a9504: EB09011F  cmp      x8, x9
//   0x0a9508: 54000140  b.eq     #0xa9530
//   0x0a950c: 39400109  ldrb     w9, [x8]
static inline uint64_t fde_func_0904_0x0a9500(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9500ULL ^ (static_cast<uint64_t>(0xa9412428ULL) << 13);
    acc = (acc + a1 + 0xeb09011fULL) ^ 0x11d7c8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0905 | PC: 0x0a9540 | FDE: 0x11d7e0 | Size: 256 bytes [_ZNSt6__ndk111basic_regexIcNS_12regex_traitsIcEEE22__parse_ERE_expressionINS_11__wrap_iterIPKcEEEET_S9_S9_]
// Hàm FDE #0905 | Địa chỉ PC: 0x0a9540 | Địa chỉ FDE: 0x11d7e0 | Kích thước: 256 bytes
//   0x0a9540: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0a9544: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0a9548: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0a954c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0905_0x0a9540(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9540ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11d7e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0906 | PC: 0x0a97bc | FDE: 0x11d808 | Size: 104 bytes [_ZNSt6__ndk111basic_regexIcNS_12regex_traitsIcEEE20__parse_ORD_CHAR_EREINS_11__wrap_iterIPKcEEEET_S9_S9_]
// Hàm FDE #0906 | Địa chỉ PC: 0x0a97bc | Địa chỉ FDE: 0x11d808 | Kích thước: 104 bytes
//   0x0a97bc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a97c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a97c4: 910043FD  add      x29, sp, #0x10
//   0x0a97c8: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0906_0x0a97bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a97bcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11d808ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0907 | PC: 0x0a9824 | FDE: 0x11d828 | Size: 148 bytes [_ZNSt6__ndk111basic_regexIcNS_12regex_traitsIcEEE23__parse_QUOTED_CHAR_EREINS_11__wrap_iterIPKcEEEET_S9_S9_]
// Hàm FDE #0907 | Địa chỉ PC: 0x0a9824 | Địa chỉ FDE: 0x11d828 | Kích thước: 148 bytes
//   0x0a9824: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a9828: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a982c: 910043FD  add      x29, sp, #0x10
//   0x0a9830: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0907_0x0a9824(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9824ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11d828ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0908 | PC: 0x0a98b8 | FDE: 0x11d848 | Size: 256 bytes [_ZNKSt6__ndk111basic_regexIcNS_12regex_traitsIcEEE8__searchINS_9allocatorINS_9sub_matchIPKcEEEEEEbS8_S8_RNS_13match_resultsIS8_T_EENS_15regex_constants15match_flag_typeE]
// Hàm FDE #0908 | Địa chỉ PC: 0x0a98b8 | Địa chỉ FDE: 0x11d848 | Kích thước: 256 bytes
//   0x0a98b8: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0a98bc: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0a98c0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0a98c4: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0908_0x0a98b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a98b8ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11d848ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0909 | PC: 0x0a9b14 | FDE: 0x11d870 | Size: 256 bytes [_ZNSt6__ndk113match_resultsINS_11__wrap_iterIPKcEENS_9allocatorINS_9sub_matchIS4_EEEEE8__assignIS3_NS5_INS6_IS3_EEEEEEvS4_S4_RKNS0_IT_T0_EEb]
// Hàm FDE #0909 | Địa chỉ PC: 0x0a9b14 | Địa chỉ FDE: 0x11d870 | Kích thước: 256 bytes
//   0x0a9b14: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0a9b18: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0a9b1c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a9b20: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0909_0x0a9b14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9b14ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11d870ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0910 | PC: 0x0a9cfc | FDE: 0x11f448 | Size: 256 bytes [_ZNKSt6__ndk111basic_regexIcNS_12regex_traitsIcEEE29__match_at_start_posix_nosubsINS_9allocatorINS_9sub_matchIPKcEEEEEEbS8_S8_RNS_13match_resultsIS8_T_EENS_15regex_constants15match_flag_typeEb]
// Hàm FDE #0910 | Địa chỉ PC: 0x0a9cfc | Địa chỉ FDE: 0x11f448 | Kích thước: 256 bytes
//   0x0a9cfc: D10583FF  sub      sp, sp, #0x160
//   0x0a9d00: A9106FFC  stp      x28, x27, [sp, #0x100]
//   0x0a9d04: A91167FA  stp      x26, x25, [sp, #0x110]
//   0x0a9d08: A9125FF8  stp      x24, x23, [sp, #0x120]
static inline uint64_t fde_func_0910_0x0a9cfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9cfcULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xa9106ffcULL) ^ 0x11f448ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0911 | PC: 0x0aa4a8 | FDE: 0x11f480 | Size: 256 bytes [_ZNKSt6__ndk111basic_regexIcNS_12regex_traitsIcEEE27__match_at_start_posix_subsINS_9allocatorINS_9sub_matchIPKcEEEEEEbS8_S8_RNS_13match_resultsIS8_T_EENS_15regex_constants15match_flag_typeEb]
// Hàm FDE #0911 | Địa chỉ PC: 0x0aa4a8 | Địa chỉ FDE: 0x11f480 | Kích thước: 256 bytes
//   0x0aa4a8: D10743FF  sub      sp, sp, #0x1d0
//   0x0aa4ac: A9176FFC  stp      x28, x27, [sp, #0x170]
//   0x0aa4b0: A91867FA  stp      x26, x25, [sp, #0x180]
//   0x0aa4b4: A9195FF8  stp      x24, x23, [sp, #0x190]
static inline uint64_t fde_func_0911_0x0aa4a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aa4a8ULL ^ (static_cast<uint64_t>(0xd10743ffULL) << 13);
    acc = (acc + a1 + 0xa9176ffcULL) ^ 0x11f480ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0912 | PC: 0x0aae34 | FDE: 0x11d898 | Size: 256 bytes [_ZNSt6__ndk15dequeINS_7__stateIcEENS_9allocatorIS2_EEE8pop_backEv]
// Hàm FDE #0912 | Địa chỉ PC: 0x0aae34 | Địa chỉ FDE: 0x11d898 | Kích thước: 256 bytes
//   0x0aae34: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0aae38: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0aae3c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0aae40: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0912_0x0aae34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aae34ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11d898ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0913 | PC: 0x0aaf44 | FDE: 0x11f4b8 | Size: 256 bytes [_ZNSt6__ndk15dequeINS_7__stateIcEENS_9allocatorIS2_EEE19__add_back_capacityEv]
// Hàm FDE #0913 | Địa chỉ PC: 0x0aaf44 | Địa chỉ FDE: 0x11f4b8 | Kích thước: 256 bytes
//   0x0aaf44: D101C3FF  sub      sp, sp, #0x70
//   0x0aaf48: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0aaf4c: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0aaf50: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0913_0x0aaf44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aaf44ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x11f4b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0914 | PC: 0x0ab13c | FDE: 0x11d8b8 | Size: 256 bytes
// Hàm FDE #0914 | Địa chỉ PC: 0x0ab13c | Địa chỉ FDE: 0x11d8b8 | Kích thước: 256 bytes
//   0x0ab13c: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0ab140: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0ab144: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0ab148: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0914_0x0ab13c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab13cULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11d8b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0915 | PC: 0x0ab29c | FDE: 0x11d8e0 | Size: 256 bytes [_ZNSt6__ndk114__split_bufferIPNS_7__stateIcEENS_9allocatorIS3_EEE9push_backEOS3_]
// Hàm FDE #0915 | Địa chỉ PC: 0x0ab29c | Địa chỉ FDE: 0x11d8e0 | Kích thước: 256 bytes
//   0x0ab29c: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0ab2a0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0ab2a4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0ab2a8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0915_0x0ab29c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab29cULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11d8e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0916 | PC: 0x0ab3fc | FDE: 0x11d908 | Size: 256 bytes [_ZNSt6__ndk114__split_bufferIPNS_7__stateIcEENS_9allocatorIS3_EEE10push_frontEOS3_]
// Hàm FDE #0916 | Địa chỉ PC: 0x0ab3fc | Địa chỉ FDE: 0x11d908 | Kích thước: 256 bytes
//   0x0ab3fc: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0ab400: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0ab404: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0ab408: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0916_0x0ab3fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab3fcULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11d908ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0917 | PC: 0x0ab558 | FDE: 0x11d930 | Size: 256 bytes [_ZNSt6__ndk114__split_bufferIPNS_7__stateIcEERNS_9allocatorIS3_EEE9push_backEOS3_]
// Hàm FDE #0917 | Địa chỉ PC: 0x0ab558 | Địa chỉ FDE: 0x11d930 | Kích thước: 256 bytes
//   0x0ab558: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0ab55c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0ab560: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0ab564: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0917_0x0ab558(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab558ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11d930ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0918 | PC: 0x0ab6b8 | FDE: 0x11d958 | Size: 256 bytes [_ZNSt6__ndk114__split_bufferIPNS_7__stateIcEERNS_9allocatorIS3_EEE10push_frontERKS3_]
// Hàm FDE #0918 | Địa chỉ PC: 0x0ab6b8 | Địa chỉ FDE: 0x11d958 | Kích thước: 256 bytes
//   0x0ab6b8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0ab6bc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0ab6c0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0ab6c4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0918_0x0ab6b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab6b8ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11d958ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0919 | PC: 0x0ab814 | FDE: 0x11d980 | Size: 256 bytes [_ZNSt6__ndk112__deque_baseINS_7__stateIcEENS_9allocatorIS2_EEE5clearEv]
// Hàm FDE #0919 | Địa chỉ PC: 0x0ab814 | Địa chỉ FDE: 0x11d980 | Kích thước: 256 bytes
//   0x0ab814: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0ab818: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0ab81c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0ab820: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0919_0x0ab814(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab814ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11d980ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0920 | PC: 0x0ab990 | FDE: 0x11f4e8 | Size: 256 bytes [_ZNSt6__ndk15dequeINS_7__stateIcEENS_9allocatorIS2_EEE20__add_front_capacityEv]
// Hàm FDE #0920 | Địa chỉ PC: 0x0ab990 | Địa chỉ FDE: 0x11f4e8 | Kích thước: 256 bytes
//   0x0ab990: D101C3FF  sub      sp, sp, #0x70
//   0x0ab994: F90023F5  str      x21, [sp, #0x40]
//   0x0ab998: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0ab99c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0920_0x0ab990(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab990ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x11f4e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0921 | PC: 0x0abbfc | FDE: 0x11d9a8 | Size: 256 bytes [_ZNSt6__ndk114__split_bufferIPNS_7__stateIcEENS_9allocatorIS3_EEE10push_frontERKS3_]
// Hàm FDE #0921 | Địa chỉ PC: 0x0abbfc | Địa chỉ FDE: 0x11d9a8 | Kích thước: 256 bytes
//   0x0abbfc: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0abc00: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0abc04: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0abc08: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0921_0x0abbfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0abbfcULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11d9a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0922 | PC: 0x0abd58 | FDE: 0x11d9d0 | Size: 256 bytes
// Hàm FDE #0922 | Địa chỉ PC: 0x0abd58 | Địa chỉ FDE: 0x11d9d0 | Kích thước: 256 bytes
//   0x0abd58: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0abd5c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0abd60: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0abd64: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0922_0x0abd58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0abd58ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11d9d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0923 | PC: 0x0abeb8 | FDE: 0x11d9f8 | Size: 256 bytes [_ZNSt6__ndk16vectorINS_9sub_matchIPKcEENS_9allocatorIS4_EEE6assignIPS4_EENS_9enable_ifIXaasr21__is_forward_iteratorIT_EE5valuesr16is_constructibleIS4_NS_15iterator_traitsISB_E9referenceEEE5valueEvE4typeESB_SB_]
// Hàm FDE #0923 | Địa chỉ PC: 0x0abeb8 | Địa chỉ FDE: 0x11d9f8 | Kích thước: 256 bytes
//   0x0abeb8: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0abebc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0abec0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0abec4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0923_0x0abeb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0abeb8ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11d9f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0924 | PC: 0x0ac078 | FDE: 0x11da20 | Size: 256 bytes [_ZNSt6__ndk16vectorINS_4pairImPKcEENS_9allocatorIS4_EEE6assignIPS4_EENS_9enable_ifIXaasr21__is_forward_iteratorIT_EE5valuesr16is_constructibleIS4_NS_15iterator_traitsISB_E9referenceEEE5valueEvE4typeESB_SB_]
// Hàm FDE #0924 | Địa chỉ PC: 0x0ac078 | Địa chỉ FDE: 0x11da20 | Kích thước: 256 bytes
//   0x0ac078: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0ac07c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0ac080: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0ac084: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0924_0x0ac078(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac078ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11da20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0925 | PC: 0x0ac1d8 | FDE: 0x11da48 | Size: 256 bytes [_ZNSt6__ndk16vectorINS_9sub_matchINS_11__wrap_iterIPKcEEEENS_9allocatorIS6_EEE8__appendEm]
// Hàm FDE #0925 | Địa chỉ PC: 0x0ac1d8 | Địa chỉ FDE: 0x11da48 | Kích thước: 256 bytes
//   0x0ac1d8: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0ac1dc: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0ac1e0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0ac1e4: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0925_0x0ac1d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac1d8ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11da48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0926 | PC: 0x0ac388 | FDE: 0x11da70 | Size: 60 bytes [_ZN11fast_engine14StdMatchResultD2Ev]
// Hàm FDE #0926 | Địa chỉ PC: 0x0ac388 | Địa chỉ FDE: 0x11da70 | Kích thước: 60 bytes
//   0x0ac388: F0000489  adrp     x9, #0x13f000
//   0x0ac38c: F9400408  ldr      x8, [x0, #8]
//   0x0ac390: F947A129  ldr      x9, [x9, #0xf40]
//   0x0ac394: 91004129  add      x9, x9, #0x10
static inline uint64_t fde_func_0926_0x0ac388(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac388ULL ^ (static_cast<uint64_t>(0xf0000489ULL) << 13);
    acc = (acc + a1 + 0xf9400408ULL) ^ 0x11da70ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0927 | PC: 0x0ac3c4 | FDE: 0x11da88 | Size: 84 bytes [_ZN11fast_engine14StdMatchResultD0Ev]
// Hàm FDE #0927 | Địa chỉ PC: 0x0ac3c4 | Địa chỉ FDE: 0x11da88 | Kích thước: 84 bytes
//   0x0ac3c4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ac3c8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ac3cc: 910043FD  add      x29, sp, #0x10
//   0x0ac3d0: F0000488  adrp     x8, #0x13f000
static inline uint64_t fde_func_0927_0x0ac3c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac3c4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11da88ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0928 | PC: 0x0ac418 | FDE: 0x11daa8 | Size: 28 bytes [_ZNK11fast_engine14StdMatchResult4sizeEv]
// Hàm FDE #0928 | Địa chỉ PC: 0x0ac418 | Địa chỉ FDE: 0x11daa8 | Kích thước: 28 bytes
//   0x0ac418: A940A408  ldp      x8, x9, [x0, #8]
//   0x0ac41c: CB080128  sub      x8, x9, x8
//   0x0ac420: B201F3E9  mov      x9, #-0x5555555555555556
//   0x0ac424: 9343FD08  asr      x8, x8, #3
static inline uint64_t fde_func_0928_0x0ac418(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac418ULL ^ (static_cast<uint64_t>(0xa940a408ULL) << 13);
    acc = (acc + a1 + 0xcb080128ULL) ^ 0x11daa8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0929 | PC: 0x0ac434 | FDE: 0x11dac0 | Size: 256 bytes [_ZNK11fast_engine14StdMatchResult3strEm]
// Hàm FDE #0929 | Địa chỉ PC: 0x0ac434 | Địa chỉ FDE: 0x11dac0 | Kích thước: 256 bytes
//   0x0ac434: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0ac438: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0ac43c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0ac440: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0929_0x0ac434(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac434ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11dac0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0930 | PC: 0x0ac580 | FDE: 0x11dae8 | Size: 60 bytes [_ZNK11fast_engine14StdMatchResult8positionEm]
// Hàm FDE #0930 | Địa chỉ PC: 0x0ac580 | Địa chỉ FDE: 0x11dae8 | Kích thước: 60 bytes
//   0x0ac580: A940A408  ldp      x8, x9, [x0, #8]
//   0x0ac584: 5280030B  mov      w11, #0x18
//   0x0ac588: F940380A  ldr      x10, [x0, #0x70]
//   0x0ac58c: CB080129  sub      x9, x9, x8
static inline uint64_t fde_func_0930_0x0ac580(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac580ULL ^ (static_cast<uint64_t>(0xa940a408ULL) << 13);
    acc = (acc + a1 + 0x5280030bULL) ^ 0x11dae8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0931 | PC: 0x0ac5bc | FDE: 0x11db00 | Size: 72 bytes [_ZNK11fast_engine14StdMatchResult6lengthEm]
// Hàm FDE #0931 | Địa chỉ PC: 0x0ac5bc | Địa chỉ FDE: 0x11db00 | Kích thước: 72 bytes
//   0x0ac5bc: A940A408  ldp      x8, x9, [x0, #8]
//   0x0ac5c0: B201F3EA  mov      x10, #-0x5555555555555556
//   0x0ac5c4: F295556A  movk     x10, #0xaaab
//   0x0ac5c8: 5280030B  mov      w11, #0x18
static inline uint64_t fde_func_0931_0x0ac5bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac5bcULL ^ (static_cast<uint64_t>(0xa940a408ULL) << 13);
    acc = (acc + a1 + 0xb201f3eaULL) ^ 0x11db00ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0932 | PC: 0x0ac604 | FDE: 0x11db18 | Size: 52 bytes [_ZNK11fast_engine14StdMatchResult7matchedEm]
// Hàm FDE #0932 | Địa chỉ PC: 0x0ac604 | Địa chỉ FDE: 0x11db18 | Kích thước: 52 bytes
//   0x0ac604: A940A408  ldp      x8, x9, [x0, #8]
//   0x0ac608: B201F3EA  mov      x10, #-0x5555555555555556
//   0x0ac60c: F295556A  movk     x10, #0xaaab
//   0x0ac610: 5280030B  mov      w11, #0x18
static inline uint64_t fde_func_0932_0x0ac604(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac604ULL ^ (static_cast<uint64_t>(0xa940a408ULL) << 13);
    acc = (acc + a1 + 0xb201f3eaULL) ^ 0x11db18ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0933 | PC: 0x0ac638 | FDE: 0x11f510 | Size: 256 bytes [_ZN5boost13re_detail_60012perl_matcherINSt6__ndk111__wrap_iterIPKcEENS2_9allocatorINS_9sub_matchIS6_EEEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE9match_impEv]
// Hàm FDE #0933 | Địa chỉ PC: 0x0ac638 | Địa chỉ FDE: 0x11f510 | Kích thước: 256 bytes
//   0x0ac638: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0ac63c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0ac640: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0ac644: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0933_0x0ac638(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac638ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11f510ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0934 | PC: 0x0ac978 | FDE: 0x11db30 | Size: 256 bytes
// Hàm FDE #0934 | Địa chỉ PC: 0x0ac978 | Địa chỉ FDE: 0x11db30 | Kích thước: 256 bytes
//   0x0ac978: D10143FF  sub      sp, sp, #0x50
//   0x0ac97c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0ac980: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0ac984: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0934_0x0ac978(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac978ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x11db30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0935 | PC: 0x0acac0 | FDE: 0x11f540 | Size: 256 bytes
// Hàm FDE #0935 | Địa chỉ PC: 0x0acac0 | Địa chỉ FDE: 0x11f540 | Kích thước: 256 bytes
//   0x0acac0: D10343FF  sub      sp, sp, #0xd0
//   0x0acac4: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x0acac8: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x0acacc: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_0935_0x0acac0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0acac0ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9076ffcULL) ^ 0x11f540ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0936 | PC: 0x0ad2ec | FDE: 0x11f578 | Size: 256 bytes [_ZN5boost13regex_replaceINS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEcNSt6__ndk112basic_stringIcNS5_11char_traitsIcEENS5_9allocatorIcEEEEEENS6_IT0_NS7_ISC_EENS9_ISC_EEEERKSF_RKNS_11basic_regexISC_T_EET1_NS_15regex_constants12_match_flagsE]
// Hàm FDE #0936 | Địa chỉ PC: 0x0ad2ec | Địa chỉ FDE: 0x11f578 | Kích thước: 256 bytes
//   0x0ad2ec: D101C3FF  sub      sp, sp, #0x70
//   0x0ad2f0: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0ad2f4: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0ad2f8: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0936_0x0ad2ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ad2ecULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x11f578ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0937 | PC: 0x0ad3f4 | FDE: 0x11f5b0 | Size: 256 bytes [_ZN5boost13regex_replaceINS_13re_detail_60019string_out_iteratorINSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEEENS3_11__wrap_iterIPKcEENS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEcS9_EET_SJ_T0_SK_RKNS_11basic_regexIT2_T1_EET3_NS_15regex_constants12_match_flagsE]
// Hàm FDE #0937 | Địa chỉ PC: 0x0ad3f4 | Địa chỉ FDE: 0x11f5b0 | Kích thước: 256 bytes
//   0x0ad3f4: D10243FF  sub      sp, sp, #0x90
//   0x0ad3f8: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0ad3fc: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x0ad400: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_0937_0x0ad3f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ad3f4ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90467faULL) ^ 0x11f5b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0938 | PC: 0x0ad670 | FDE: 0x11f5e8 | Size: 256 bytes [_ZN5boost14regex_iteratorINSt6__ndk111__wrap_iterIPKcEEcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEEC2ES5_S5_RKNS_11basic_regexIcS9_EENS_15regex_constants12_match_flagsE]
// Hàm FDE #0938 | Địa chỉ PC: 0x0ad670 | Địa chỉ FDE: 0x11f5e8 | Kích thước: 256 bytes
//   0x0ad670: D10543FF  sub      sp, sp, #0x150
//   0x0ad674: F90083FC  str      x28, [sp, #0x100]
//   0x0ad678: A9115FF8  stp      x24, x23, [sp, #0x110]
//   0x0ad67c: A91257F6  stp      x22, x21, [sp, #0x120]
static inline uint64_t fde_func_0938_0x0ad670(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ad670ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x11f5e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0939 | PC: 0x0ad828 | FDE: 0x11f618 | Size: 256 bytes [_ZNK5boost13match_resultsINSt6__ndk111__wrap_iterIPKcEENS1_9allocatorINS_9sub_matchIS5_EEEEE6formatINS_13re_detail_60019string_out_iteratorINS1_12basic_stringIcNS1_11char_traitsIcEENS6_IcEEEEEESI_NS_11basic_regexIcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEEEEET_SQ_T0_NS_15regex_constants12_match_flagsERKT1_]
// Hàm FDE #0939 | Địa chỉ PC: 0x0ad828 | Địa chỉ FDE: 0x11f618 | Kích thước: 256 bytes
//   0x0ad828: D101C3FF  sub      sp, sp, #0x70
//   0x0ad82c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0ad830: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0ad834: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0939_0x0ad828(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ad828ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x11f618ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0940 | PC: 0x0ad944 | FDE: 0x11f648 | Size: 248 bytes [_ZNSt6__ndk110shared_ptrIN5boost29regex_iterator_implementationINS_11__wrap_iterIPKcEEcNS1_12regex_traitsIcNS1_16cpp_regex_traitsIcEEEEEEEC2ISB_EEPT_NS_9enable_ifIXsr14is_convertibleISF_PSB_EE5valueENSC_5__natEE4typeE]
// Hàm FDE #0940 | Địa chỉ PC: 0x0ad944 | Địa chỉ FDE: 0x11f648 | Kích thước: 248 bytes
//   0x0ad944: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0ad948: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ad94c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ad950: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0940_0x0ad944(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ad944ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11f648ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0941 | PC: 0x0ada3c | FDE: 0x11db50 | Size: 36 bytes [_ZNSt6__ndk120__shared_ptr_pointerIPN5boost29regex_iterator_implementationINS_11__wrap_iterIPKcEEcNS1_12regex_traitsIcNS1_16cpp_regex_traitsIcEEEEEENS_14default_deleteISB_EENS_9allocatorISB_EEED0Ev]
// Hàm FDE #0941 | Địa chỉ PC: 0x0ada3c | Địa chỉ FDE: 0x11db50 | Kích thước: 36 bytes
//   0x0ada3c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ada40: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ada44: 910043FD  add      x29, sp, #0x10
//   0x0ada48: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0941_0x0ada3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ada3cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11db50ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0942 | PC: 0x0ada60 | FDE: 0x11db70 | Size: 196 bytes [_ZNSt6__ndk120__shared_ptr_pointerIPN5boost29regex_iterator_implementationINS_11__wrap_iterIPKcEEcNS1_12regex_traitsIcNS1_16cpp_regex_traitsIcEEEEEENS_14default_deleteISB_EENS_9allocatorISB_EEE16__on_zero_sharedEv]
// Hàm FDE #0942 | Địa chỉ PC: 0x0ada60 | Địa chỉ FDE: 0x11db70 | Kích thước: 196 bytes
//   0x0ada60: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ada64: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ada68: 910043FD  add      x29, sp, #0x10
//   0x0ada6c: F9400C13  ldr      x19, [x0, #0x18]
static inline uint64_t fde_func_0942_0x0ada60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ada60ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11db70ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0943 | PC: 0x0adb24 | FDE: 0x11db90 | Size: 4 bytes [_ZNSt6__ndk120__shared_ptr_pointerIPN5boost29regex_iterator_implementationINS_11__wrap_iterIPKcEEcNS1_12regex_traitsIcNS1_16cpp_regex_traitsIcEEEEEENS_14default_deleteISB_EENS_9allocatorISB_EEE21__on_zero_shared_weakEv]
// Hàm FDE #0943 | Địa chỉ PC: 0x0adb24 | Địa chỉ FDE: 0x11db90 | Kích thước: 4 bytes
//   0x0adb24: 17FE52AF  b        #0x425e0
static inline uint64_t fde_func_0943_0x0adb24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0adb24ULL ^ (static_cast<uint64_t>(0x17fe52afULL) << 13);
    acc = (acc + a1 + 0xa9bc5ff8ULL) ^ 0x11db90ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0944 | PC: 0x0adb28 | FDE: 0x11dba8 | Size: 256 bytes [_ZN5boost13re_detail_60021basic_regex_formatterINS0_19string_out_iteratorINSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEEENS_13match_resultsINS3_11__wrap_iterIPKcEENS7_INS_9sub_matchISF_EEEEEENS_20regex_traits_wrapperINS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEEESF_E10format_allEj]
// Hàm FDE #0944 | Địa chỉ PC: 0x0adb28 | Địa chỉ FDE: 0x11dba8 | Kích thước: 256 bytes
//   0x0adb28: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0adb2c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0adb30: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0adb34: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0944_0x0adb28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0adb28ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11dba8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0945 | PC: 0x0add0c | FDE: 0x11dbd0 | Size: 208 bytes [_ZN5boost13re_detail_60021basic_regex_formatterINS0_19string_out_iteratorINSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEEENS_13match_resultsINS3_11__wrap_iterIPKcEENS7_INS_9sub_matchISF_EEEEEENS_20regex_traits_wrapperINS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEEESF_E3putEc]
// Hàm FDE #0945 | Địa chỉ PC: 0x0add0c | Địa chỉ FDE: 0x11dbd0 | Kích thước: 208 bytes
//   0x0add0c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0add10: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0add14: 910043FD  add      x29, sp, #0x10
//   0x0add18: B9402C08  ldr      w8, [x0, #0x2c]
static inline uint64_t fde_func_0945_0x0add0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0add0cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11dbd0ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #0946 | PC: 0x0adddc | FDE: 0x11dbf0 | Size: 256 bytes [_ZN5boost13re_detail_60021basic_regex_formatterINS0_19string_out_iteratorINSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEEENS_13match_resultsINS3_11__wrap_iterIPKcEENS7_INS_9sub_matchISF_EEEEEENS_20regex_traits_wrapperINS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEEESF_E13format_escapeEv]
// Hàm FDE #0946 | Địa chỉ PC: 0x0adddc | Địa chỉ FDE: 0x11dbf0 | Kích thước: 256 bytes
//   0x0adddc: D10183FF  sub      sp, sp, #0x60
//   0x0adde0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0adde4: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0adde8: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0946_0x0adddc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0adddcULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x11dbf0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0947 | PC: 0x0ae118 | FDE: 0x11dc18 | Size: 256 bytes [_ZN5boost13re_detail_60021basic_regex_formatterINS0_19string_out_iteratorINSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEEENS_13match_resultsINS3_11__wrap_iterIPKcEENS7_INS_9sub_matchISF_EEEEEENS_20regex_traits_wrapperINS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEEESF_E18format_conditionalEj]
// Hàm FDE #0947 | Địa chỉ PC: 0x0ae118 | Địa chỉ FDE: 0x11dc18 | Kích thước: 256 bytes
//   0x0ae118: D10183FF  sub      sp, sp, #0x60
//   0x0ae11c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0ae120: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0ae124: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0947_0x0ae118(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ae118ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x11dc18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0948 | PC: 0x0ae3a0 | FDE: 0x11dc40 | Size: 256 bytes [_ZN5boost13re_detail_60021basic_regex_formatterINS0_19string_out_iteratorINSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEEENS_13match_resultsINS3_11__wrap_iterIPKcEENS7_INS_9sub_matchISF_EEEEEENS_20regex_traits_wrapperINS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEEESF_E11format_perlEv]
// Hàm FDE #0948 | Địa chỉ PC: 0x0ae3a0 | Địa chỉ FDE: 0x11dc40 | Kích thước: 256 bytes
//   0x0ae3a0: D10183FF  sub      sp, sp, #0x60
//   0x0ae3a4: F90013F7  str      x23, [sp, #0x20]
//   0x0ae3a8: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0ae3ac: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0948_0x0ae3a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ae3a0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x11dc40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0949 | PC: 0x0ae70c | FDE: 0x11f670 | Size: 256 bytes [_ZN5boost13re_detail_60021basic_regex_formatterINS0_19string_out_iteratorINSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEEENS_13match_resultsINS3_11__wrap_iterIPKcEENS7_INS_9sub_matchISF_EEEEEENS_20regex_traits_wrapperINS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEEESF_E3toiERSF_SF_iRKNS3_17integral_constantIbLb0EEE]
// Hàm FDE #0949 | Địa chỉ PC: 0x0ae70c | Địa chỉ FDE: 0x11f670 | Kích thước: 256 bytes
//   0x0ae70c: D10203FF  sub      sp, sp, #0x80
//   0x0ae710: F9001BF9  str      x25, [sp, #0x30]
//   0x0ae714: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0ae718: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_0949_0x0ae70c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ae70cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf9ULL) ^ 0x11f670ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0950 | PC: 0x0ae8a4 | FDE: 0x11f6a0 | Size: 256 bytes [_ZN5boost13re_detail_60021basic_regex_formatterINS0_19string_out_iteratorINSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEEENS_13match_resultsINS3_11__wrap_iterIPKcEENS7_INS_9sub_matchISF_EEEEEENS_20regex_traits_wrapperINS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEEESF_E19get_named_sub_indexESF_SF_RKNS3_17integral_constantIbLb0EEE]
// Hàm FDE #0950 | Địa chỉ PC: 0x0ae8a4 | Địa chỉ FDE: 0x11f6a0 | Kích thước: 256 bytes
//   0x0ae8a4: D10183FF  sub      sp, sp, #0x60
//   0x0ae8a8: F90013F7  str      x23, [sp, #0x20]
//   0x0ae8ac: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0ae8b0: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0950_0x0ae8a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ae8a4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x11f6a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0951 | PC: 0x0aea28 | FDE: 0x11f6d0 | Size: 256 bytes [_ZNK5boost13match_resultsINSt6__ndk111__wrap_iterIPKcEENS1_9allocatorINS_9sub_matchIS5_EEEEE25named_subexpression_indexES4_S4_]
// Hàm FDE #0951 | Địa chỉ PC: 0x0aea28 | Địa chỉ FDE: 0x11f6d0 | Kích thước: 256 bytes
//   0x0aea28: D10183FF  sub      sp, sp, #0x60
//   0x0aea2c: F90013F7  str      x23, [sp, #0x20]
//   0x0aea30: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0aea34: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0951_0x0aea28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aea28ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x11f6d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0952 | PC: 0x0aeb54 | FDE: 0x11dc68 | Size: 256 bytes [_ZNK5boost13re_detail_60020named_subexpressions11equal_rangeIcEENSt6__ndk14pairINS3_11__wrap_iterIPKNS1_4nameEEES9_EEPKT_SD_]
// Hàm FDE #0952 | Địa chỉ PC: 0x0aeb54 | Địa chỉ FDE: 0x11dc68 | Kích thước: 256 bytes
//   0x0aeb54: EB02003F  cmp      x1, x2
//   0x0aeb58: AA0003E8  mov      x8, x0
//   0x0aeb5c: 540002C0  b.eq     #0xaebb4
//   0x0aeb60: 528F372A  mov      w10, #0x79b9
static inline uint64_t fde_func_0952_0x0aeb54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aeb54ULL ^ (static_cast<uint64_t>(0xeb02003fULL) << 13);
    acc = (acc + a1 + 0xaa0003e8ULL) ^ 0x11dc68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0953 | PC: 0x0aec84 | FDE: 0x11f700 | Size: 256 bytes [_ZN5boost13re_detail_60021basic_regex_formatterINS0_19string_out_iteratorINSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEEENS_13match_resultsINS3_11__wrap_iterIPKcEENS7_INS_9sub_matchISF_EEEEEENS_20regex_traits_wrapperINS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEEESF_E16handle_perl_verbEb]
// Hàm FDE #0953 | Địa chỉ PC: 0x0aec84 | Địa chỉ FDE: 0x11f700 | Kích thước: 256 bytes
//   0x0aec84: D10143FF  sub      sp, sp, #0x50
//   0x0aec88: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0aec8c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0aec90: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0953_0x0aec84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aec84ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x11f700ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0954 | PC: 0x0af338 | FDE: 0x11f730 | Size: 256 bytes [_ZN5boost13re_detail_60021basic_regex_formatterINS0_19string_out_iteratorINSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEEENS_13match_resultsINS3_11__wrap_iterIPKcEENS7_INS_9sub_matchISF_EEEEEENS_20regex_traits_wrapperINS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEEESF_E13get_named_subESF_SF_RKNS3_17integral_constantIbLb0EEE]
// Hàm FDE #0954 | Địa chỉ PC: 0x0af338 | Địa chỉ FDE: 0x11f730 | Kích thước: 256 bytes
//   0x0af338: D10183FF  sub      sp, sp, #0x60
//   0x0af33c: F90013F7  str      x23, [sp, #0x20]
//   0x0af340: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0af344: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0954_0x0af338(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0af338ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x11f730ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0955 | PC: 0x0af4bc | FDE: 0x11f760 | Size: 256 bytes [_ZNK5boost13match_resultsINSt6__ndk111__wrap_iterIPKcEENS1_9allocatorINS_9sub_matchIS5_EEEEE19named_subexpressionES4_S4_]
// Hàm FDE #0955 | Địa chỉ PC: 0x0af4bc | Địa chỉ FDE: 0x11f760 | Kích thước: 256 bytes
//   0x0af4bc: D10143FF  sub      sp, sp, #0x50
//   0x0af4c0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0af4c4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0af4c8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0955_0x0af4bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0af4bcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x11f760ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0956 | PC: 0x0af5bc | FDE: 0x11f790 | Size: 256 bytes [_ZN5boost14regex_iteratorINSt6__ndk111__wrap_iterIPKcEEcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE3cowEv]
// Hàm FDE #0956 | Địa chỉ PC: 0x0af5bc | Địa chỉ FDE: 0x11f790 | Kích thước: 256 bytes
//   0x0af5bc: D10143FF  sub      sp, sp, #0x50
//   0x0af5c0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0af5c4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0af5c8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0956_0x0af5bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0af5bcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x11f790ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0957 | PC: 0x0af74c | FDE: 0x11f7c0 | Size: 232 bytes [_ZN5boost29regex_iterator_implementationINSt6__ndk111__wrap_iterIPKcEEcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEE4nextEv]
// Hàm FDE #0957 | Địa chỉ PC: 0x0af74c | Địa chỉ FDE: 0x11f7c0 | Kích thước: 232 bytes
//   0x0af74c: D10503FF  sub      sp, sp, #0x140
//   0x0af750: F90083FC  str      x28, [sp, #0x100]
//   0x0af754: A91157F6  stp      x22, x21, [sp, #0x110]
//   0x0af758: A9124FF4  stp      x20, x19, [sp, #0x120]
static inline uint64_t fde_func_0957_0x0af74c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0af74cULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x11f7c0ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0958 | PC: 0x0af834 | FDE: 0x11f7f0 | Size: 256 bytes [_ZNSt6__ndk113regex_replaceINS_20back_insert_iteratorINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEEENS_11__wrap_iterIPKcEENS_12regex_traitsIcEEcEET_SF_T0_SG_RKNS_11basic_regexIT2_T1_EEPKSI_NS_15regex_constants15match_flag_typeE]
// Hàm FDE #0958 | Địa chỉ PC: 0x0af834 | Địa chỉ FDE: 0x11f7f0 | Kích thước: 256 bytes
//   0x0af834: D10403FF  sub      sp, sp, #0x100
//   0x0af838: A90A6FFC  stp      x28, x27, [sp, #0xa0]
//   0x0af83c: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x0af840: A90C5FF8  stp      x24, x23, [sp, #0xc0]
static inline uint64_t fde_func_0958_0x0af834(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0af834ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90a6ffcULL) ^ 0x11f7f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0959 | PC: 0x0afb6c | FDE: 0x11f828 | Size: 256 bytes [_ZNSt6__ndk114regex_iteratorINS_11__wrap_iterIPKcEEcNS_12regex_traitsIcEEEC2ES4_S4_RKNS_11basic_regexIcS6_EENS_15regex_constants15match_flag_typeE]
// Hàm FDE #0959 | Địa chỉ PC: 0x0afb6c | Địa chỉ FDE: 0x11f828 | Kích thước: 256 bytes
//   0x0afb6c: D10303FF  sub      sp, sp, #0xc0
//   0x0afb70: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x0afb74: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x0afb78: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_0959_0x0afb6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0afb6cULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9085ff8ULL) ^ 0x11f828ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0960 | PC: 0x0afcc8 | FDE: 0x11dc80 | Size: 256 bytes [_ZNKSt6__ndk113match_resultsINS_11__wrap_iterIPKcEENS_9allocatorINS_9sub_matchIS4_EEEEE6formatINS_20back_insert_iteratorINS_12basic_stringIcNS_11char_traitsIcEENS5_IcEEEEEEEET_SI_S3_S3_NS_15regex_constants15match_flag_typeE]
// Hàm FDE #0960 | Địa chỉ PC: 0x0afcc8 | Địa chỉ FDE: 0x11dc80 | Kích thước: 256 bytes
//   0x0afcc8: D101C3FF  sub      sp, sp, #0x70
//   0x0afccc: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x0afcd0: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0afcd4: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_0960_0x0afcc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0afcc8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x11dc80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0961 | PC: 0x0b04cc | FDE: 0x11f858 | Size: 256 bytes [_ZNSt6__ndk114regex_iteratorINS_11__wrap_iterIPKcEEcNS_12regex_traitsIcEEEppEv]
// Hàm FDE #0961 | Địa chỉ PC: 0x0b04cc | Địa chỉ FDE: 0x11f858 | Kích thước: 256 bytes
//   0x0b04cc: D10343FF  sub      sp, sp, #0xd0
//   0x0b04d0: F90043F9  str      x25, [sp, #0x80]
//   0x0b04d4: A9095FF8  stp      x24, x23, [sp, #0x90]
//   0x0b04d8: A90A57F6  stp      x22, x21, [sp, #0xa0]
static inline uint64_t fde_func_0961_0x0b04cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b04ccULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xf90043f9ULL) ^ 0x11f858ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0962 | PC: 0x0b074c | FDE: 0x11f888 | Size: 256 bytes [_ZN5boost12regex_searchINSt6__ndk111__wrap_iterIPKcEEcNS_12regex_traitsIcNS_16cpp_regex_traitsIcEEEEEEbT_SA_RKNS_11basic_regexIT0_T1_EENS_15regex_constants12_match_flagsE]
// Hàm FDE #0962 | Địa chỉ PC: 0x0b074c | Địa chỉ FDE: 0x11f888 | Kích thước: 256 bytes
//   0x0b074c: D10603FF  sub      sp, sp, #0x180
//   0x0b0750: A91557FC  stp      x28, x21, [sp, #0x150]
//   0x0b0754: A9164FF4  stp      x20, x19, [sp, #0x160]
//   0x0b0758: A9177BFD  stp      x29, x30, [sp, #0x170]
static inline uint64_t fde_func_0962_0x0b074c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b074cULL ^ (static_cast<uint64_t>(0xd10603ffULL) << 13);
    acc = (acc + a1 + 0xa91557fcULL) ^ 0x11f888ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0963 | PC: 0x0b08e0 | FDE: 0x11f9b0 | Size: 96 bytes [_ZN11fast_engine20AllocStructErrorTypeEPNS_6EngineE]
// Hàm FDE #0963 | Địa chỉ PC: 0x0b08e0 | Địa chỉ FDE: 0x11f9b0 | Kích thước: 96 bytes
//   0x0b08e0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b08e4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b08e8: 910043FD  add      x29, sp, #0x10
//   0x0b08ec: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0963_0x0b08e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b08e0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11f9b0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0964 | PC: 0x0b0940 | FDE: 0x11f8b8 | Size: 64 bytes [_ZN11fast_engine19InitStructErrorTypeEPNS_6EngineE]
// Hàm FDE #0964 | Địa chỉ PC: 0x0b0940 | Địa chỉ FDE: 0x11f8b8 | Kích thước: 64 bytes
//   0x0b0940: F0000468  adrp     x8, #0x13f000
//   0x0b0944: F943DD08  ldr      x8, [x8, #0x7b8]
//   0x0b0948: F000046B  adrp     x11, #0x13f000
//   0x0b094c: 5280A00A  mov      w10, #0x500
static inline uint64_t fde_func_0964_0x0b0940(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0940ULL ^ (static_cast<uint64_t>(0xf0000468ULL) << 13);
    acc = (acc + a1 + 0xf943dd08ULL) ^ 0x11f8b8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0965 | PC: 0x0b0980 | FDE: 0x11f9d8 | Size: 148 bytes
// Hàm FDE #0965 | Địa chỉ PC: 0x0b0980 | Địa chỉ FDE: 0x11f9d8 | Kích thước: 148 bytes
//   0x0b0980: D10103FF  sub      sp, sp, #0x40
//   0x0b0984: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0b0988: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0b098c: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0965_0x0b0980(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0980ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x11f9d8ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0966 | PC: 0x0b0a14 | FDE: 0x11fa00 | Size: 96 bytes [_ZN11fast_engine19AllocUnpackIterTypeEPNS_6EngineE]
// Hàm FDE #0966 | Địa chỉ PC: 0x0b0a14 | Địa chỉ FDE: 0x11fa00 | Kích thước: 96 bytes
//   0x0b0a14: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b0a18: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b0a1c: 910043FD  add      x29, sp, #0x10
//   0x0b0a20: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0966_0x0b0a14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0a14ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11fa00ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0967 | PC: 0x0b0a74 | FDE: 0x11f8d0 | Size: 68 bytes [_ZN11fast_engine18InitUnpackIterTypeEPNS_6EngineE]
// Hàm FDE #0967 | Địa chỉ PC: 0x0b0a74 | Địa chỉ FDE: 0x11f8d0 | Kích thước: 68 bytes
//   0x0b0a74: F0000468  adrp     x8, #0x13f000
//   0x0b0a78: F944B908  ldr      x8, [x8, #0x970]
//   0x0b0a7c: F000046A  adrp     x10, #0x13f000
//   0x0b0a80: F944ED4A  ldr      x10, [x10, #0x9d8]
static inline uint64_t fde_func_0967_0x0b0a74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0a74ULL ^ (static_cast<uint64_t>(0xf0000468ULL) << 13);
    acc = (acc + a1 + 0xf944b908ULL) ^ 0x11f8d0ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0968 | PC: 0x0b0ab8 | FDE: 0x11fa28 | Size: 256 bytes
// Hàm FDE #0968 | Địa chỉ PC: 0x0b0ab8 | Địa chỉ FDE: 0x11fa28 | Kích thước: 256 bytes
//   0x0b0ab8: D101C3FF  sub      sp, sp, #0x70
//   0x0b0abc: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0b0ac0: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0b0ac4: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0968_0x0b0ab8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0ab8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x11fa28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0969 | PC: 0x0b0c94 | FDE: 0x11f8e8 | Size: 256 bytes
// Hàm FDE #0969 | Địa chỉ PC: 0x0b0c94 | Địa chỉ FDE: 0x11f8e8 | Kích thước: 256 bytes
//   0x0b0c94: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0b0c98: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0b0c9c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0b0ca0: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0969_0x0b0c94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0c94ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11f8e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0970 | PC: 0x0b0dbc | FDE: 0x11f918 | Size: 72 bytes
// Hàm FDE #0970 | Địa chỉ PC: 0x0b0dbc | Địa chỉ FDE: 0x11f918 | Kích thước: 72 bytes
//   0x0b0dbc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b0dc0: 910003FD  mov      x29, sp
//   0x0b0dc4: F000046A  adrp     x10, #0x13f000
//   0x0b0dc8: F946594A  ldr      x10, [x10, #0xcb0]
static inline uint64_t fde_func_0970_0x0b0dbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0dbcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x11f918ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0971 | PC: 0x0b0e04 | FDE: 0x11fa58 | Size: 256 bytes [_ZN11fast_engine16InitStructModuleEPNS_10FastEngineEPNS_6EngineE]
// Hàm FDE #0971 | Địa chỉ PC: 0x0b0e04 | Địa chỉ FDE: 0x11fa58 | Kích thước: 256 bytes
//   0x0b0e04: D10183FF  sub      sp, sp, #0x60
//   0x0b0e08: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0b0e0c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0b0e10: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0971_0x0b0e04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0e04ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x11fa58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0972 | PC: 0x0b11bc | FDE: 0x11fa88 | Size: 232 bytes
// Hàm FDE #0972 | Địa chỉ PC: 0x0b11bc | Địa chỉ FDE: 0x11fa88 | Kích thước: 232 bytes
//   0x0b11bc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0b11c0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b11c4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b11c8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0972_0x0b11bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b11bcULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11fa88ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0973 | PC: 0x0b12a4 | FDE: 0x11fab8 | Size: 256 bytes
// Hàm FDE #0973 | Địa chỉ PC: 0x0b12a4 | Địa chỉ FDE: 0x11fab8 | Kích thước: 256 bytes
//   0x0b12a4: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0b12a8: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0b12ac: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0b12b0: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0973_0x0b12a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b12a4ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x11fab8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0974 | PC: 0x0b14fc | FDE: 0x11f938 | Size: 156 bytes
// Hàm FDE #0974 | Địa chỉ PC: 0x0b14fc | Địa chỉ FDE: 0x11f938 | Kích thước: 156 bytes
//   0x0b14fc: D10443FF  sub      sp, sp, #0x110
//   0x0b1500: A90F4FFC  stp      x28, x19, [sp, #0xf0]
//   0x0b1504: A9107BFD  stp      x29, x30, [sp, #0x100]
//   0x0b1508: 910403FD  add      x29, sp, #0x100
static inline uint64_t fde_func_0974_0x0b14fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b14fcULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90f4ffcULL) ^ 0x11f938ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0975 | PC: 0x0b1598 | FDE: 0x11f958 | Size: 64 bytes [_ZN11fast_engine10UnpackIterD2Ev]
// Hàm FDE #0975 | Địa chỉ PC: 0x0b1598 | Địa chỉ FDE: 0x11f958 | Kích thước: 64 bytes
//   0x0b1598: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b159c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b15a0: 910043FD  add      x29, sp, #0x10
//   0x0b15a4: D0000469  adrp     x9, #0x13f000
static inline uint64_t fde_func_0975_0x0b1598(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b1598ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11f958ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0976 | PC: 0x0b15d8 | FDE: 0x11f978 | Size: 72 bytes [_ZN11fast_engine10UnpackIterD0Ev]
// Hàm FDE #0976 | Địa chỉ PC: 0x0b15d8 | Địa chỉ FDE: 0x11f978 | Kích thước: 72 bytes
//   0x0b15d8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b15dc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b15e0: 910043FD  add      x29, sp, #0x10
//   0x0b15e4: D0000469  adrp     x9, #0x13f000
static inline uint64_t fde_func_0976_0x0b15d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b15d8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11f978ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0977 | PC: 0x0b1620 | FDE: 0x11f998 | Size: 56 bytes [_ZN11fast_engine10UnpackIter5ClearEPNS_6EngineE]
// Hàm FDE #0977 | Địa chỉ PC: 0x0b1620 | Địa chỉ FDE: 0x11f998 | Kích thước: 56 bytes
//   0x0b1620: F9402008  ldr      x8, [x0, #0x40]
//   0x0b1624: B4000128  cbz      x8, #0xb1648
//   0x0b1628: B9402109  ldr      w9, [x8, #0x20]
//   0x0b162c: 7100093F  cmp      w9, #2
static inline uint64_t fde_func_0977_0x0b1620(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b1620ULL ^ (static_cast<uint64_t>(0xf9402008ULL) << 13);
    acc = (acc + a1 + 0xb4000128ULL) ^ 0x11f998ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0978 | PC: 0x0b1658 | FDE: 0x11fb10 | Size: 256 bytes [_ZN11fast_engine13InitSysModuleEPNS_10FastEngineEPNS_6EngineE]
// Hàm FDE #0978 | Địa chỉ PC: 0x0b1658 | Địa chỉ FDE: 0x11fb10 | Kích thước: 256 bytes
//   0x0b1658: D10283FF  sub      sp, sp, #0xa0
//   0x0b165c: F90023FB  str      x27, [sp, #0x40]
//   0x0b1660: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0b1664: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0978_0x0b1658(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b1658ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90023fbULL) ^ 0x11fb10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0979 | PC: 0x0b20b4 | FDE: 0x11faf0 | Size: 88 bytes
// Hàm FDE #0979 | Địa chỉ PC: 0x0b20b4 | Địa chỉ FDE: 0x11faf0 | Kích thước: 88 bytes
//   0x0b20b4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b20b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b20bc: 910043FD  add      x29, sp, #0x10
//   0x0b20c0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0979_0x0b20b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b20b4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11faf0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0980 | PC: 0x0b210c | FDE: 0x11fbf0 | Size: 96 bytes [_ZN11fast_engine18AllocLocalTimeTypeEPNS_6EngineE]
// Hàm FDE #0980 | Địa chỉ PC: 0x0b210c | Địa chỉ FDE: 0x11fbf0 | Kích thước: 96 bytes
//   0x0b210c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b2110: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b2114: 910043FD  add      x29, sp, #0x10
//   0x0b2118: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0980_0x0b210c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b210cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11fbf0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0981 | PC: 0x0b216c | FDE: 0x11fb48 | Size: 52 bytes [_ZN11fast_engine17InitLocalTimeTypeEPNS_6EngineE]
// Hàm FDE #0981 | Địa chỉ PC: 0x0b216c | Địa chỉ FDE: 0x11fb48 | Kích thước: 52 bytes
//   0x0b216c: B0000468  adrp     x8, #0x13f000
//   0x0b2170: F9457108  ldr      x8, [x8, #0xae0]
//   0x0b2174: D0000469  adrp     x9, #0x140000
//   0x0b2178: 9000000A  adrp     x10, #0xb2000
static inline uint64_t fde_func_0981_0x0b216c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b216cULL ^ (static_cast<uint64_t>(0xb0000468ULL) << 13);
    acc = (acc + a1 + 0xf9457108ULL) ^ 0x11fb48ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0982 | PC: 0x0b21a0 | FDE: 0x11fc18 | Size: 256 bytes
// Hàm FDE #0982 | Địa chỉ PC: 0x0b21a0 | Địa chỉ FDE: 0x11fc18 | Kích thước: 256 bytes
//   0x0b21a0: D10343FF  sub      sp, sp, #0xd0
//   0x0b21a4: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x0b21a8: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x0b21ac: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_0982_0x0b21a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b21a0ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9076ffcULL) ^ 0x11fc18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0983 | PC: 0x0b2950 | FDE: 0x11fc50 | Size: 172 bytes
// Hàm FDE #0983 | Địa chỉ PC: 0x0b2950 | Địa chỉ FDE: 0x11fc50 | Kích thước: 172 bytes
//   0x0b2950: D10143FF  sub      sp, sp, #0x50
//   0x0b2954: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0b2958: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0b295c: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0983_0x0b2950(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2950ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x11fc50ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #0984 | PC: 0x0b29fc | FDE: 0x11fb60 | Size: 256 bytes [_ZN11fast_engine9LocalTime5ClearEPNS_6EngineE]
// Hàm FDE #0984 | Địa chỉ PC: 0x0b29fc | Địa chỉ FDE: 0x11fb60 | Kích thước: 256 bytes
//   0x0b29fc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b2a00: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b2a04: 910043FD  add      x29, sp, #0x10
//   0x0b2a08: F9402008  ldr      x8, [x0, #0x40]
static inline uint64_t fde_func_0984_0x0b29fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b29fcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11fb60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0985 | PC: 0x0b2bb4 | FDE: 0x11fb80 | Size: 164 bytes [_ZN11fast_engine9LocalTimeC1EPNS_6EngineEPNS_3ObjES4_S4_S4_S4_S4_S4_S4_S4_]
// Hàm FDE #0985 | Địa chỉ PC: 0x0b2bb4 | Địa chỉ FDE: 0x11fb80 | Kích thước: 164 bytes
//   0x0b2bb4: D10183FF  sub      sp, sp, #0x60
//   0x0b2bb8: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0b2bbc: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0b2bc0: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0985_0x0b2bb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2bb4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x11fb80ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #0986 | PC: 0x0b2c58 | FDE: 0x11fc78 | Size: 256 bytes [_ZN11fast_engine12InitTimeZoneEPKNS_9ModuleObjEPNS_6EngineE]
// Hàm FDE #0986 | Địa chỉ PC: 0x0b2c58 | Địa chỉ FDE: 0x11fc78 | Kích thước: 256 bytes
//   0x0b2c58: D10343FF  sub      sp, sp, #0xd0
//   0x0b2c5c: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x0b2c60: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x0b2c64: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_0986_0x0b2c58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2c58ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9076ffcULL) ^ 0x11fc78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0987 | PC: 0x0b30d0 | FDE: 0x11fcb0 | Size: 256 bytes [_ZN11fast_engine14InitTimeModuleEPNS_10FastEngineEPNS_6EngineE]
// Hàm FDE #0987 | Địa chỉ PC: 0x0b30d0 | Địa chỉ FDE: 0x11fcb0 | Kích thước: 256 bytes
//   0x0b30d0: D10183FF  sub      sp, sp, #0x60
//   0x0b30d4: F90013F7  str      x23, [sp, #0x20]
//   0x0b30d8: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0b30dc: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0987_0x0b30d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b30d0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x11fcb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0988 | PC: 0x0b3394 | FDE: 0x11fce0 | Size: 188 bytes
// Hàm FDE #0988 | Địa chỉ PC: 0x0b3394 | Địa chỉ FDE: 0x11fce0 | Kích thước: 188 bytes
//   0x0b3394: D10103FF  sub      sp, sp, #0x40
//   0x0b3398: FD000BE8  str      d8, [sp, #0x10]
//   0x0b339c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0b33a0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0988_0x0b3394(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3394ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xfd000be8ULL) ^ 0x11fce0ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0989 | PC: 0x0b3450 | FDE: 0x11fbb0 | Size: 256 bytes
// Hàm FDE #0989 | Địa chỉ PC: 0x0b3450 | Địa chỉ FDE: 0x11fbb0 | Kích thước: 256 bytes
//   0x0b3450: D10103FF  sub      sp, sp, #0x40
//   0x0b3454: F9000BF5  str      x21, [sp, #0x10]
//   0x0b3458: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0b345c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0989_0x0b3450(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3450ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x11fbb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0990 | PC: 0x0b3574 | FDE: 0x11fd08 | Size: 256 bytes
// Hàm FDE #0990 | Địa chỉ PC: 0x0b3574 | Địa chỉ FDE: 0x11fd08 | Kích thước: 256 bytes
//   0x0b3574: D107C3FF  sub      sp, sp, #0x1f0
//   0x0b3578: A9196FFC  stp      x28, x27, [sp, #0x190]
//   0x0b357c: A91A67FA  stp      x26, x25, [sp, #0x1a0]
//   0x0b3580: A91B5FF8  stp      x24, x23, [sp, #0x1b0]
static inline uint64_t fde_func_0990_0x0b3574(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3574ULL ^ (static_cast<uint64_t>(0xd107c3ffULL) << 13);
    acc = (acc + a1 + 0xa9196ffcULL) ^ 0x11fd08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0991 | PC: 0x0b398c | FDE: 0x11fbd0 | Size: 36 bytes [_ZN11fast_engine9LocalTimeD0Ev]
// Hàm FDE #0991 | Địa chỉ PC: 0x0b398c | Địa chỉ FDE: 0x11fbd0 | Kích thước: 36 bytes
//   0x0b398c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b3990: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b3994: 910043FD  add      x29, sp, #0x10
//   0x0b3998: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0991_0x0b398c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b398cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11fbd0ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0992 | PC: 0x0b39b0 | FDE: 0x11fde8 | Size: 96 bytes [_ZN11fast_engine15AllocTypingTypeEPNS_6EngineE]
// Hàm FDE #0992 | Địa chỉ PC: 0x0b39b0 | Địa chỉ FDE: 0x11fde8 | Kích thước: 96 bytes
//   0x0b39b0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b39b4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b39b8: 910043FD  add      x29, sp, #0x10
//   0x0b39bc: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0992_0x0b39b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b39b0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11fde8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0993 | PC: 0x0b3a10 | FDE: 0x11fd40 | Size: 64 bytes [_ZN11fast_engine14InitTypingTypeEPNS_6EngineE]
// Hàm FDE #0993 | Địa chỉ PC: 0x0b3a10 | Địa chỉ FDE: 0x11fd40 | Kích thước: 64 bytes
//   0x0b3a10: 90000468  adrp     x8, #0x13f000
//   0x0b3a14: F9470D08  ldr      x8, [x8, #0xe18]
//   0x0b3a18: 5280A009  mov      w9, #0x500
//   0x0b3a1c: 9000000A  adrp     x10, #0xb3000
static inline uint64_t fde_func_0993_0x0b3a10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3a10ULL ^ (static_cast<uint64_t>(0x90000468ULL) << 13);
    acc = (acc + a1 + 0xf9470d08ULL) ^ 0x11fd40ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0994 | PC: 0x0b3a50 | FDE: 0x11fd58 | Size: 16 bytes
// Hàm FDE #0994 | Địa chỉ PC: 0x0b3a50 | Địa chỉ FDE: 0x11fd58 | Kích thước: 16 bytes
//   0x0b3a50: 90000468  adrp     x8, #0x13f000
//   0x0b3a54: F944D108  ldr      x8, [x8, #0x9a0]
//   0x0b3a58: F9400100  ldr      x0, [x8]
//   0x0b3a5c: D65F03C0  ret      
static inline uint64_t fde_func_0994_0x0b3a50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3a50ULL ^ (static_cast<uint64_t>(0x90000468ULL) << 13);
    acc = (acc + a1 + 0xf944d108ULL) ^ 0x11fd58ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0995 | PC: 0x0b3a60 | FDE: 0x11fd70 | Size: 16 bytes
// Hàm FDE #0995 | Địa chỉ PC: 0x0b3a60 | Địa chỉ FDE: 0x11fd70 | Kích thước: 16 bytes
//   0x0b3a60: 90000468  adrp     x8, #0x13f000
//   0x0b3a64: F944D108  ldr      x8, [x8, #0x9a0]
//   0x0b3a68: F9400100  ldr      x0, [x8]
//   0x0b3a6c: D65F03C0  ret      
static inline uint64_t fde_func_0995_0x0b3a60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3a60ULL ^ (static_cast<uint64_t>(0x90000468ULL) << 13);
    acc = (acc + a1 + 0xf944d108ULL) ^ 0x11fd70ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0996 | PC: 0x0b3a70 | FDE: 0x11fd88 | Size: 72 bytes [_ZN11fast_engine9TypingObjC1EPNS_6EngineE]
// Hàm FDE #0996 | Địa chỉ PC: 0x0b3a70 | Địa chỉ FDE: 0x11fd88 | Kích thước: 72 bytes
//   0x0b3a70: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b3a74: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b3a78: 910043FD  add      x29, sp, #0x10
//   0x0b3a7c: 90000468  adrp     x8, #0x13f000
static inline uint64_t fde_func_0996_0x0b3a70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3a70ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11fd88ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0997 | PC: 0x0b3ab8 | FDE: 0x11fe10 | Size: 256 bytes [_ZN11fast_engine16InitTypingModuleEPNS_10FastEngineEPNS_6EngineE]
// Hàm FDE #0997 | Địa chỉ PC: 0x0b3ab8 | Địa chỉ FDE: 0x11fe10 | Kích thước: 256 bytes
//   0x0b3ab8: D10203FF  sub      sp, sp, #0x80
//   0x0b3abc: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0b3ac0: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0b3ac4: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0997_0x0b3ab8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3ab8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x11fe10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0998 | PC: 0x0b4610 | FDE: 0x11fe48 | Size: 256 bytes
// Hàm FDE #0998 | Địa chỉ PC: 0x0b4610 | Địa chỉ FDE: 0x11fe48 | Kích thước: 256 bytes
//   0x0b4610: D101C3FF  sub      sp, sp, #0x70
//   0x0b4614: F90013F9  str      x25, [sp, #0x20]
//   0x0b4618: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0b461c: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0998_0x0b4610(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b4610ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x11fe48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0999 | PC: 0x0b4874 | FDE: 0x11fda8 | Size: 132 bytes
// Hàm FDE #0999 | Địa chỉ PC: 0x0b4874 | Địa chỉ FDE: 0x11fda8 | Kích thước: 132 bytes
//   0x0b4874: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b4878: 910003FD  mov      x29, sp
//   0x0b487c: B4000082  cbz      x2, #0xb488c
//   0x0b4880: F9401448  ldr      x8, [x2, #0x28]
static inline uint64_t fde_func_0999_0x0b4874(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b4874ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x11fda8ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1000 | PC: 0x0b48f8 | FDE: 0x11fdc8 | Size: 36 bytes [_ZN11fast_engine9TypingObjD0Ev]
// Hàm FDE #1000 | Địa chỉ PC: 0x0b48f8 | Địa chỉ FDE: 0x11fdc8 | Kích thước: 36 bytes
//   0x0b48f8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b48fc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b4900: 910043FD  add      x29, sp, #0x10
//   0x0b4904: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1000_0x0b48f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b48f8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11fdc8ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1001 | PC: 0x0b491c | FDE: 0x120098 | Size: 176 bytes [_ZN11fast_engine12ByteArrayObjC2EPKclPNS_6EngineE]
// Hàm FDE #1001 | Địa chỉ PC: 0x0b491c | Địa chỉ FDE: 0x120098 | Kích thước: 176 bytes
//   0x0b491c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0b4920: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b4924: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b4928: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1001_0x0b491c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b491cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x120098ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #1002 | PC: 0x0b49cc | FDE: 0x11fe78 | Size: 76 bytes [_ZN11fast_engine12ByteArrayObjC2EPNS_6EngineE]
// Hàm FDE #1002 | Địa chỉ PC: 0x0b49cc | Địa chỉ FDE: 0x11fe78 | Kích thước: 76 bytes
//   0x0b49cc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b49d0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b49d4: 910043FD  add      x29, sp, #0x10
//   0x0b49d8: F0000448  adrp     x8, #0x13f000
static inline uint64_t fde_func_1002_0x0b49cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b49ccULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11fe78ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1003 | PC: 0x0b4a18 | FDE: 0x11fe98 | Size: 56 bytes [_ZN11fast_engine12ByteArrayObj5ClearEPNS_6EngineE]
// Hàm FDE #1003 | Địa chỉ PC: 0x0b4a18 | Địa chỉ FDE: 0x11fe98 | Kích thước: 56 bytes
//   0x0b4a18: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b4a1c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b4a20: 910043FD  add      x29, sp, #0x10
//   0x0b4a24: F9402008  ldr      x8, [x0, #0x40]
static inline uint64_t fde_func_1003_0x0b4a18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b4a18ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11fe98ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1004 | PC: 0x0b4a50 | FDE: 0x11feb8 | Size: 152 bytes [_ZN11fast_engine12ByteArrayObj10FromObjectEPNS_3ObjEPNS_6EngineE]
// Hàm FDE #1004 | Địa chỉ PC: 0x0b4a50 | Địa chỉ FDE: 0x11feb8 | Kích thước: 152 bytes
//   0x0b4a50: D10103FF  sub      sp, sp, #0x40
//   0x0b4a54: F90013F3  str      x19, [sp, #0x20]
//   0x0b4a58: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0b4a5c: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1004_0x0b4a50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b4a50ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x11feb8ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1005 | PC: 0x0b4ae8 | FDE: 0x1200c8 | Size: 232 bytes [_ZN11fast_engine12ByteArrayObj17FromStringAndSizeEPKclPNS_6EngineE]
// Hàm FDE #1005 | Địa chỉ PC: 0x0b4ae8 | Địa chỉ FDE: 0x1200c8 | Kích thước: 232 bytes
//   0x0b4ae8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0b4aec: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b4af0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b4af4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1005_0x0b4ae8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b4ae8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1200c8ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1006 | PC: 0x0b4bd0 | FDE: 0x1200f8 | Size: 96 bytes [_ZN11fast_engine18AllocByteArrayTypeEPNS_6EngineE]
// Hàm FDE #1006 | Địa chỉ PC: 0x0b4bd0 | Địa chỉ FDE: 0x1200f8 | Kích thước: 96 bytes
//   0x0b4bd0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b4bd4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b4bd8: 910043FD  add      x29, sp, #0x10
//   0x0b4bdc: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1006_0x0b4bd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b4bd0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1200f8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1007 | PC: 0x0b4c30 | FDE: 0x11fed8 | Size: 92 bytes [_ZN11fast_engine17InitByteArrayTypeEPNS_6EngineE]
// Hàm FDE #1007 | Địa chỉ PC: 0x0b4c30 | Địa chỉ FDE: 0x11fed8 | Kích thước: 92 bytes
//   0x0b4c30: F0000448  adrp     x8, #0x13f000
//   0x0b4c34: F9462D08  ldr      x8, [x8, #0xc58]
//   0x0b4c38: 90000009  adrp     x9, #0xb4000
//   0x0b4c3c: 91323129  add      x9, x9, #0xc8c
static inline uint64_t fde_func_1007_0x0b4c30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b4c30ULL ^ (static_cast<uint64_t>(0xf0000448ULL) << 13);
    acc = (acc + a1 + 0xf9462d08ULL) ^ 0x11fed8ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1008 | PC: 0x0b4c8c | FDE: 0x11fef0 | Size: 48 bytes
// Hàm FDE #1008 | Địa chỉ PC: 0x0b4c8c | Địa chỉ FDE: 0x11fef0 | Kích thước: 48 bytes
//   0x0b4c8c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b4c90: 910003FD  mov      x29, sp
//   0x0b4c94: F0000448  adrp     x8, #0x13f000
//   0x0b4c98: F9465908  ldr      x8, [x8, #0xcb0]
static inline uint64_t fde_func_1008_0x0b4c8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b4c8cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x11fef0ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1009 | PC: 0x0b4cbc | FDE: 0x11ff10 | Size: 256 bytes
// Hàm FDE #1009 | Địa chỉ PC: 0x0b4cbc | Địa chỉ FDE: 0x11ff10 | Kích thước: 256 bytes
//   0x0b4cbc: D10203FF  sub      sp, sp, #0x80
//   0x0b4cc0: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0b4cc4: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0b4cc8: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1009_0x0b4cbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b4cbcULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90367faULL) ^ 0x11ff10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1010 | PC: 0x0b510c | FDE: 0x120120 | Size: 112 bytes
// Hàm FDE #1010 | Địa chỉ PC: 0x0b510c | Địa chỉ FDE: 0x120120 | Kích thước: 112 bytes
//   0x0b510c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b5110: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b5114: 910043FD  add      x29, sp, #0x10
//   0x0b5118: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1010_0x0b510c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b510cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x120120ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1011 | PC: 0x0b517c | FDE: 0x120148 | Size: 256 bytes
// Hàm FDE #1011 | Địa chỉ PC: 0x0b517c | Địa chỉ FDE: 0x120148 | Kích thước: 256 bytes
//   0x0b517c: D10243FF  sub      sp, sp, #0x90
//   0x0b5180: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x0b5184: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x0b5188: A9074FF4  stp      x20, x19, [sp, #0x70]
static inline uint64_t fde_func_1011_0x0b517c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b517cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9055ff8ULL) ^ 0x120148ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1012 | PC: 0x0b5350 | FDE: 0x11ff40 | Size: 36 bytes [_ZN11fast_engine12ByteArrayObjD0Ev]
// Hàm FDE #1012 | Địa chỉ PC: 0x0b5350 | Địa chỉ FDE: 0x11ff40 | Kích thước: 36 bytes
//   0x0b5350: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b5354: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b5358: 910043FD  add      x29, sp, #0x10
//   0x0b535c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1012_0x0b5350(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5350ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11ff40ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1013 | PC: 0x0b5374 | FDE: 0x11ff60 | Size: 8 bytes
// Hàm FDE #1013 | Địa chỉ PC: 0x0b5374 | Địa chỉ FDE: 0x11ff60 | Kích thước: 8 bytes
//   0x0b5374: F9402400  ldr      x0, [x0, #0x48]
//   0x0b5378: D65F03C0  ret      
static inline uint64_t fde_func_1013_0x0b5374(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5374ULL ^ (static_cast<uint64_t>(0xf9402400ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x11ff60ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1014 | PC: 0x0b537c | FDE: 0x11ff78 | Size: 48 bytes
// Hàm FDE #1014 | Địa chỉ PC: 0x0b537c | Địa chỉ FDE: 0x11ff78 | Kích thước: 48 bytes
//   0x0b537c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b5380: 910003FD  mov      x29, sp
//   0x0b5384: D0000448  adrp     x8, #0x13f000
//   0x0b5388: F9465908  ldr      x8, [x8, #0xcb0]
static inline uint64_t fde_func_1014_0x0b537c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b537cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x11ff78ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1015 | PC: 0x0b53ac | FDE: 0x11ff98 | Size: 48 bytes
// Hàm FDE #1015 | Địa chỉ PC: 0x0b53ac | Địa chỉ FDE: 0x11ff98 | Kích thước: 48 bytes
//   0x0b53ac: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b53b0: 910003FD  mov      x29, sp
//   0x0b53b4: D0000448  adrp     x8, #0x13f000
//   0x0b53b8: F9465908  ldr      x8, [x8, #0xcb0]
static inline uint64_t fde_func_1015_0x0b53ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b53acULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x11ff98ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1016 | PC: 0x0b53dc | FDE: 0x11ffb8 | Size: 48 bytes
// Hàm FDE #1016 | Địa chỉ PC: 0x0b53dc | Địa chỉ FDE: 0x11ffb8 | Kích thước: 48 bytes
//   0x0b53dc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b53e0: 910003FD  mov      x29, sp
//   0x0b53e4: D0000448  adrp     x8, #0x13f000
//   0x0b53e8: F9465908  ldr      x8, [x8, #0xcb0]
static inline uint64_t fde_func_1016_0x0b53dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b53dcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x11ffb8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1017 | PC: 0x0b540c | FDE: 0x11ffd8 | Size: 48 bytes
// Hàm FDE #1017 | Địa chỉ PC: 0x0b540c | Địa chỉ FDE: 0x11ffd8 | Kích thước: 48 bytes
//   0x0b540c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b5410: 910003FD  mov      x29, sp
//   0x0b5414: D0000448  adrp     x8, #0x13f000
//   0x0b5418: F9465908  ldr      x8, [x8, #0xcb0]
static inline uint64_t fde_func_1017_0x0b540c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b540cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x11ffd8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1018 | PC: 0x0b543c | FDE: 0x11fff8 | Size: 48 bytes
// Hàm FDE #1018 | Địa chỉ PC: 0x0b543c | Địa chỉ FDE: 0x11fff8 | Kích thước: 48 bytes
//   0x0b543c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b5440: 910003FD  mov      x29, sp
//   0x0b5444: D0000448  adrp     x8, #0x13f000
//   0x0b5448: F9465908  ldr      x8, [x8, #0xcb0]
static inline uint64_t fde_func_1018_0x0b543c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b543cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x11fff8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1019 | PC: 0x0b546c | FDE: 0x120018 | Size: 48 bytes
// Hàm FDE #1019 | Địa chỉ PC: 0x0b546c | Địa chỉ FDE: 0x120018 | Kích thước: 48 bytes
//   0x0b546c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b5470: 910003FD  mov      x29, sp
//   0x0b5474: D0000448  adrp     x8, #0x13f000
//   0x0b5478: F9465908  ldr      x8, [x8, #0xcb0]
static inline uint64_t fde_func_1019_0x0b546c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b546cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x120018ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1020 | PC: 0x0b549c | FDE: 0x120038 | Size: 48 bytes
// Hàm FDE #1020 | Địa chỉ PC: 0x0b549c | Địa chỉ FDE: 0x120038 | Kích thước: 48 bytes
//   0x0b549c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b54a0: 910003FD  mov      x29, sp
//   0x0b54a4: D0000448  adrp     x8, #0x13f000
//   0x0b54a8: F9465908  ldr      x8, [x8, #0xcb0]
static inline uint64_t fde_func_1020_0x0b549c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b549cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x120038ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1021 | PC: 0x0b54cc | FDE: 0x120058 | Size: 48 bytes
// Hàm FDE #1021 | Địa chỉ PC: 0x0b54cc | Địa chỉ FDE: 0x120058 | Kích thước: 48 bytes
//   0x0b54cc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b54d0: 910003FD  mov      x29, sp
//   0x0b54d4: D0000448  adrp     x8, #0x13f000
//   0x0b54d8: F9465908  ldr      x8, [x8, #0xcb0]
static inline uint64_t fde_func_1021_0x0b54cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b54ccULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x120058ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1022 | PC: 0x0b54fc | FDE: 0x120078 | Size: 48 bytes
// Hàm FDE #1022 | Địa chỉ PC: 0x0b54fc | Địa chỉ FDE: 0x120078 | Kích thước: 48 bytes
//   0x0b54fc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b5500: 910003FD  mov      x29, sp
//   0x0b5504: D0000448  adrp     x8, #0x13f000
//   0x0b5508: F9465908  ldr      x8, [x8, #0xcb0]
static inline uint64_t fde_func_1022_0x0b54fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b54fcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x120078ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1023 | PC: 0x0b552c | FDE: 0x120178 | Size: 80 bytes [_ZN11fast_engine8BytesObjC1EPvPNS_6EngineE]
// Hàm FDE #1023 | Địa chỉ PC: 0x0b552c | Địa chỉ FDE: 0x120178 | Kích thước: 80 bytes
//   0x0b552c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b5530: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b5534: 910043FD  add      x29, sp, #0x10
//   0x0b5538: D0000448  adrp     x8, #0x13f000
static inline uint64_t fde_func_1023_0x0b552c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b552cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x120178ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1024 | PC: 0x0b557c | FDE: 0x120328 | Size: 160 bytes [_ZN11fast_engine8BytesObjC1EPKvlPNS_6EngineE]
// Hàm FDE #1024 | Địa chỉ PC: 0x0b557c | Địa chỉ FDE: 0x120328 | Kích thước: 160 bytes
//   0x0b557c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0b5580: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b5584: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b5588: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1024_0x0b557c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b557cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x120328ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1025 | PC: 0x0b561c | FDE: 0x120358 | Size: 140 bytes [_ZN11fast_engine8BytesObjC2EllPNS_6EngineE]
// Hàm FDE #1025 | Địa chỉ PC: 0x0b561c | Địa chỉ FDE: 0x120358 | Kích thước: 140 bytes
//   0x0b561c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0b5620: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b5624: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b5628: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1025_0x0b561c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b561cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x120358ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1026 | PC: 0x0b56a8 | FDE: 0x120388 | Size: 100 bytes [_ZN11fast_engine8BytesObjD2Ev]
// Hàm FDE #1026 | Địa chỉ PC: 0x0b56a8 | Địa chỉ FDE: 0x120388 | Kích thước: 100 bytes
//   0x0b56a8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b56ac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b56b0: 910043FD  add      x29, sp, #0x10
//   0x0b56b4: D0000449  adrp     x9, #0x13f000
static inline uint64_t fde_func_1026_0x0b56a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b56a8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x120388ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1027 | PC: 0x0b570c | FDE: 0x1203b0 | Size: 108 bytes [_ZN11fast_engine8BytesObjD0Ev]
// Hàm FDE #1027 | Địa chỉ PC: 0x0b570c | Địa chỉ FDE: 0x1203b0 | Kích thước: 108 bytes
//   0x0b570c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b5710: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b5714: 910043FD  add      x29, sp, #0x10
//   0x0b5718: D0000449  adrp     x9, #0x13f000
static inline uint64_t fde_func_1027_0x0b570c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b570cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1203b0ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1028 | PC: 0x0b5778 | FDE: 0x120198 | Size: 256 bytes [_ZN11fast_engine8BytesObj13GetFormatInfoEc]
// Hàm FDE #1028 | Địa chỉ PC: 0x0b5778 | Địa chỉ FDE: 0x120198 | Kích thước: 256 bytes
//   0x0b5778: D10083FF  sub      sp, sp, #0x20
//   0x0b577c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b5780: 910043FD  add      x29, sp, #0x10
//   0x0b5784: B0000549  adrp     x9, #0x15e000
static inline uint64_t fde_func_1028_0x0b5778(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5778ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x120198ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1029 | PC: 0x0b59cc | FDE: 0x1203d8 | Size: 256 bytes [_ZN11fast_engine8BytesObj17FromStringAndSizeEPKclPNS_6EngineE]
// Hàm FDE #1029 | Địa chỉ PC: 0x0b59cc | Địa chỉ FDE: 0x1203d8 | Kích thước: 256 bytes
//   0x0b59cc: D10183FF  sub      sp, sp, #0x60
//   0x0b59d0: F90013F7  str      x23, [sp, #0x20]
//   0x0b59d4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0b59d8: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1029_0x0b59cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b59ccULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1203d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1030 | PC: 0x0b5b04 | FDE: 0x1201b8 | Size: 8 bytes [_ZN11fast_engine8BytesObj4SizeEPS0_PNS_6EngineE]
// Hàm FDE #1030 | Địa chỉ PC: 0x0b5b04 | Địa chỉ FDE: 0x1201b8 | Kích thước: 8 bytes
//   0x0b5b04: F9402400  ldr      x0, [x0, #0x48]
//   0x0b5b08: D65F03C0  ret      
static inline uint64_t fde_func_1030_0x0b5b04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5b04ULL ^ (static_cast<uint64_t>(0xf9402400ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1201b8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1031 | PC: 0x0b5b0c | FDE: 0x120408 | Size: 96 bytes [_ZN11fast_engine14AllocBytesTypeEPNS_6EngineE]
// Hàm FDE #1031 | Địa chỉ PC: 0x0b5b0c | Địa chỉ FDE: 0x120408 | Kích thước: 96 bytes
//   0x0b5b0c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b5b10: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b5b14: 910043FD  add      x29, sp, #0x10
//   0x0b5b18: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1031_0x0b5b0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5b0cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x120408ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1032 | PC: 0x0b5b6c | FDE: 0x1201d0 | Size: 68 bytes [_ZN11fast_engine13InitBytesTypeEPNS_6EngineE]
// Hàm FDE #1032 | Địa chỉ PC: 0x0b5b6c | Địa chỉ FDE: 0x1201d0 | Kích thước: 68 bytes
//   0x0b5b6c: D0000448  adrp     x8, #0x13f000
//   0x0b5b70: F945E908  ldr      x8, [x8, #0xbd0]
//   0x0b5b74: 52802009  mov      w9, #0x100
//   0x0b5b78: 72A10009  movk     w9, #0x800, lsl #16
static inline uint64_t fde_func_1032_0x0b5b6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5b6cULL ^ (static_cast<uint64_t>(0xd0000448ULL) << 13);
    acc = (acc + a1 + 0xf945e908ULL) ^ 0x1201d0ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1033 | PC: 0x0b5bb0 | FDE: 0x1201e8 | Size: 200 bytes
// Hàm FDE #1033 | Địa chỉ PC: 0x0b5bb0 | Địa chỉ FDE: 0x1201e8 | Kích thước: 200 bytes
//   0x0b5bb0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b5bb4: 910003FD  mov      x29, sp
//   0x0b5bb8: F9401408  ldr      x8, [x0, #0x28]
//   0x0b5bbc: 3942AD08  ldrb     w8, [x8, #0xab]
static inline uint64_t fde_func_1033_0x0b5bb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5bb0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1201e8ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1034 | PC: 0x0b5c78 | FDE: 0x120430 | Size: 256 bytes
// Hàm FDE #1034 | Địa chỉ PC: 0x0b5c78 | Địa chỉ FDE: 0x120430 | Kích thước: 256 bytes
//   0x0b5c78: D10243FF  sub      sp, sp, #0x90
//   0x0b5c7c: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x0b5c80: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x0b5c84: A9074FF4  stp      x20, x19, [sp, #0x70]
static inline uint64_t fde_func_1034_0x0b5c78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5c78ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9055ff8ULL) ^ 0x120430ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1035 | PC: 0x0b5e4c | FDE: 0x120460 | Size: 208 bytes
// Hàm FDE #1035 | Địa chỉ PC: 0x0b5e4c | Địa chỉ FDE: 0x120460 | Kích thước: 208 bytes
//   0x0b5e4c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0b5e50: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b5e54: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b5e58: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1035_0x0b5e4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5e4cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x120460ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1036 | PC: 0x0b5f1c | FDE: 0x120208 | Size: 60 bytes
// Hàm FDE #1036 | Địa chỉ PC: 0x0b5f1c | Địa chỉ FDE: 0x120208 | Kích thước: 60 bytes
//   0x0b5f1c: 360001A2  tbz      w2, #0, #0xb5f50
//   0x0b5f20: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b5f24: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b5f28: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_1036_0x0b5f1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5f1cULL ^ (static_cast<uint64_t>(0x360001a2ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x120208ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1037 | PC: 0x0b5f58 | FDE: 0x120488 | Size: 208 bytes
// Hàm FDE #1037 | Địa chỉ PC: 0x0b5f58 | Địa chỉ FDE: 0x120488 | Kích thước: 208 bytes
//   0x0b5f58: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0b5f5c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b5f60: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b5f64: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1037_0x0b5f58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5f58ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x120488ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1038 | PC: 0x0b6028 | FDE: 0x120228 | Size: 60 bytes
// Hàm FDE #1038 | Địa chỉ PC: 0x0b6028 | Địa chỉ FDE: 0x120228 | Kích thước: 60 bytes
//   0x0b6028: 360001A2  tbz      w2, #0, #0xb605c
//   0x0b602c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b6030: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b6034: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_1038_0x0b6028(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6028ULL ^ (static_cast<uint64_t>(0x360001a2ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x120228ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1039 | PC: 0x0b6064 | FDE: 0x1204b0 | Size: 208 bytes
// Hàm FDE #1039 | Địa chỉ PC: 0x0b6064 | Địa chỉ FDE: 0x1204b0 | Kích thước: 208 bytes
//   0x0b6064: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0b6068: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b606c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b6070: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1039_0x0b6064(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6064ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1204b0ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1040 | PC: 0x0b6134 | FDE: 0x120248 | Size: 60 bytes
// Hàm FDE #1040 | Địa chỉ PC: 0x0b6134 | Địa chỉ FDE: 0x120248 | Kích thước: 60 bytes
//   0x0b6134: 360001A2  tbz      w2, #0, #0xb6168
//   0x0b6138: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b613c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b6140: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_1040_0x0b6134(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6134ULL ^ (static_cast<uint64_t>(0x360001a2ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x120248ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1041 | PC: 0x0b6170 | FDE: 0x1204d8 | Size: 208 bytes
// Hàm FDE #1041 | Địa chỉ PC: 0x0b6170 | Địa chỉ FDE: 0x1204d8 | Kích thước: 208 bytes
//   0x0b6170: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0b6174: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b6178: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b617c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1041_0x0b6170(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6170ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1204d8ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1042 | PC: 0x0b6240 | FDE: 0x120268 | Size: 60 bytes
// Hàm FDE #1042 | Địa chỉ PC: 0x0b6240 | Địa chỉ FDE: 0x120268 | Kích thước: 60 bytes
//   0x0b6240: 360001A2  tbz      w2, #0, #0xb6274
//   0x0b6244: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b6248: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b624c: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_1042_0x0b6240(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6240ULL ^ (static_cast<uint64_t>(0x360001a2ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x120268ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1043 | PC: 0x0b627c | FDE: 0x120500 | Size: 208 bytes
// Hàm FDE #1043 | Địa chỉ PC: 0x0b627c | Địa chỉ FDE: 0x120500 | Kích thước: 208 bytes
//   0x0b627c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0b6280: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b6284: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b6288: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1043_0x0b627c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b627cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x120500ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1044 | PC: 0x0b634c | FDE: 0x120288 | Size: 60 bytes
// Hàm FDE #1044 | Địa chỉ PC: 0x0b634c | Địa chỉ FDE: 0x120288 | Kích thước: 60 bytes
//   0x0b634c: 360001A2  tbz      w2, #0, #0xb6380
//   0x0b6350: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b6354: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b6358: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_1044_0x0b634c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b634cULL ^ (static_cast<uint64_t>(0x360001a2ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x120288ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1045 | PC: 0x0b6388 | FDE: 0x120528 | Size: 208 bytes
// Hàm FDE #1045 | Địa chỉ PC: 0x0b6388 | Địa chỉ FDE: 0x120528 | Kích thước: 208 bytes
//   0x0b6388: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0b638c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b6390: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b6394: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1045_0x0b6388(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6388ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x120528ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1046 | PC: 0x0b6458 | FDE: 0x1202a8 | Size: 60 bytes
// Hàm FDE #1046 | Địa chỉ PC: 0x0b6458 | Địa chỉ FDE: 0x1202a8 | Kích thước: 60 bytes
//   0x0b6458: 360001A2  tbz      w2, #0, #0xb648c
//   0x0b645c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b6460: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b6464: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_1046_0x0b6458(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6458ULL ^ (static_cast<uint64_t>(0x360001a2ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x1202a8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1047 | PC: 0x0b6494 | FDE: 0x120550 | Size: 208 bytes
// Hàm FDE #1047 | Địa chỉ PC: 0x0b6494 | Địa chỉ FDE: 0x120550 | Kích thước: 208 bytes
//   0x0b6494: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0b6498: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b649c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b64a0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1047_0x0b6494(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6494ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x120550ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1048 | PC: 0x0b6564 | FDE: 0x1202c8 | Size: 60 bytes
// Hàm FDE #1048 | Địa chỉ PC: 0x0b6564 | Địa chỉ FDE: 0x1202c8 | Kích thước: 60 bytes
//   0x0b6564: 360001A2  tbz      w2, #0, #0xb6598
//   0x0b6568: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b656c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b6570: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_1048_0x0b6564(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6564ULL ^ (static_cast<uint64_t>(0x360001a2ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x1202c8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1049 | PC: 0x0b65a0 | FDE: 0x120578 | Size: 140 bytes
// Hàm FDE #1049 | Địa chỉ PC: 0x0b65a0 | Địa chỉ FDE: 0x120578 | Kích thước: 140 bytes
//   0x0b65a0: FC1D0FE8  str      d8, [sp, #-0x30]!
//   0x0b65a4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b65a8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b65ac: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1049_0x0b65a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b65a0ULL ^ (static_cast<uint64_t>(0xfc1d0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x120578ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1050 | PC: 0x0b662c | FDE: 0x1202e8 | Size: 68 bytes
// Hàm FDE #1050 | Địa chỉ PC: 0x0b662c | Địa chỉ FDE: 0x1202e8 | Kích thước: 68 bytes
//   0x0b662c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b6630: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b6634: 910043FD  add      x29, sp, #0x10
//   0x0b6638: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1050_0x0b662c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b662cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1202e8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1051 | PC: 0x0b6670 | FDE: 0x1205a0 | Size: 136 bytes
// Hàm FDE #1051 | Địa chỉ PC: 0x0b6670 | Địa chỉ FDE: 0x1205a0 | Kích thước: 136 bytes
//   0x0b6670: FC1D0FE8  str      d8, [sp, #-0x30]!
//   0x0b6674: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b6678: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b667c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1051_0x0b6670(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6670ULL ^ (static_cast<uint64_t>(0xfc1d0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1205a0ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1052 | PC: 0x0b66f8 | FDE: 0x120308 | Size: 68 bytes
// Hàm FDE #1052 | Địa chỉ PC: 0x0b66f8 | Địa chỉ FDE: 0x120308 | Kích thước: 68 bytes
//   0x0b66f8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b66fc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b6700: 910043FD  add      x29, sp, #0x10
//   0x0b6704: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1052_0x0b66f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b66f8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x120308ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1053 | PC: 0x0b673c | FDE: 0x120668 | Size: 96 bytes [_ZN11fast_engine13AllocCellTypeEPNS_6EngineE]
// Hàm FDE #1053 | Địa chỉ PC: 0x0b673c | Địa chỉ FDE: 0x120668 | Kích thước: 96 bytes
//   0x0b673c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b6740: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b6744: 910043FD  add      x29, sp, #0x10
//   0x0b6748: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1053_0x0b673c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b673cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x120668ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1054 | PC: 0x0b679c | FDE: 0x1205c8 | Size: 40 bytes [_ZN11fast_engine12InitCellTypeEPNS_6EngineE]
// Hàm FDE #1054 | Địa chỉ PC: 0x0b679c | Địa chỉ FDE: 0x1205c8 | Kích thước: 40 bytes
//   0x0b679c: B0000448  adrp     x8, #0x13f000
//   0x0b67a0: F9472908  ldr      x8, [x8, #0xe50]
//   0x0b67a4: 90000009  adrp     x9, #0xb6000
//   0x0b67a8: 9000000A  adrp     x10, #0xb6000
static inline uint64_t fde_func_1054_0x0b679c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b679cULL ^ (static_cast<uint64_t>(0xb0000448ULL) << 13);
    acc = (acc + a1 + 0xf9472908ULL) ^ 0x1205c8ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1055 | PC: 0x0b67c4 | FDE: 0x1205e0 | Size: 196 bytes
// Hàm FDE #1055 | Địa chỉ PC: 0x0b67c4 | Địa chỉ FDE: 0x1205e0 | Kích thước: 196 bytes
//   0x0b67c4: B0000449  adrp     x9, #0x13f000
//   0x0b67c8: F9401408  ldr      x8, [x0, #0x28]
//   0x0b67cc: F9472929  ldr      x9, [x9, #0xe50]
//   0x0b67d0: F9400129  ldr      x9, [x9]
static inline uint64_t fde_func_1055_0x0b67c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b67c4ULL ^ (static_cast<uint64_t>(0xb0000449ULL) << 13);
    acc = (acc + a1 + 0xf9401408ULL) ^ 0x1205e0ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1056 | PC: 0x0b6888 | FDE: 0x120690 | Size: 256 bytes
// Hàm FDE #1056 | Địa chỉ PC: 0x0b6888 | Địa chỉ FDE: 0x120690 | Kích thước: 256 bytes
//   0x0b6888: D101C3FF  sub      sp, sp, #0x70
//   0x0b688c: F90023F5  str      x21, [sp, #0x40]
//   0x0b6890: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0b6894: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_1056_0x0b6888(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6888ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x120690ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1057 | PC: 0x0b69e4 | FDE: 0x1205f8 | Size: 108 bytes [_ZN11fast_engine7CellObjC2EPNS_3ObjEPNS_6EngineE]
// Hàm FDE #1057 | Địa chỉ PC: 0x0b69e4 | Địa chỉ FDE: 0x1205f8 | Kích thước: 108 bytes
//   0x0b69e4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b69e8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b69ec: 910043FD  add      x29, sp, #0x10
//   0x0b69f0: B0000448  adrp     x8, #0x13f000
static inline uint64_t fde_func_1057_0x0b69e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b69e4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1205f8ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1058 | PC: 0x0b6a50 | FDE: 0x120618 | Size: 108 bytes [_ZN11fast_engine7CellObj3SetEPS0_PNS_3ObjEPNS_6EngineEb]
// Hàm FDE #1058 | Địa chỉ PC: 0x0b6a50 | Địa chỉ FDE: 0x120618 | Kích thước: 108 bytes
//   0x0b6a50: F9402008  ldr      x8, [x0, #0x40]
//   0x0b6a54: F9002001  str      x1, [x0, #0x40]
//   0x0b6a58: 360000A3  tbz      w3, #0, #0xb6a6c
//   0x0b6a5c: 52800029  mov      w9, #1
static inline uint64_t fde_func_1058_0x0b6a50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6a50ULL ^ (static_cast<uint64_t>(0xf9402008ULL) << 13);
    acc = (acc + a1 + 0xf9002001ULL) ^ 0x120618ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1059 | PC: 0x0b6abc | FDE: 0x120630 | Size: 76 bytes [_ZN11fast_engine7CellObj5ClearEPNS_6EngineE]
// Hàm FDE #1059 | Địa chỉ PC: 0x0b6abc | Địa chỉ FDE: 0x120630 | Kích thước: 76 bytes
//   0x0b6abc: 39412008  ldrb     w8, [x0, #0x48]
//   0x0b6ac0: 34000068  cbz      w8, #0xb6acc
//   0x0b6ac4: 3901201F  strb     wzr, [x0, #0x48]
//   0x0b6ac8: D65F03C0  ret      
static inline uint64_t fde_func_1059_0x0b6abc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6abcULL ^ (static_cast<uint64_t>(0x39412008ULL) << 13);
    acc = (acc + a1 + 0x34000068ULL) ^ 0x120630ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1060 | PC: 0x0b6b08 | FDE: 0x120648 | Size: 36 bytes [_ZN11fast_engine7CellObjD0Ev]
// Hàm FDE #1060 | Địa chỉ PC: 0x0b6b08 | Địa chỉ FDE: 0x120648 | Kích thước: 36 bytes
//   0x0b6b08: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b6b0c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b6b10: 910043FD  add      x29, sp, #0x10
//   0x0b6b14: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1060_0x0b6b08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6b08ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x120648ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1061 | PC: 0x0b6b2c | FDE: 0x1207f8 | Size: 96 bytes [_ZN11fast_engine13AllocCodeTypeEPNS_6EngineE]
// Hàm FDE #1061 | Địa chỉ PC: 0x0b6b2c | Địa chỉ FDE: 0x1207f8 | Kích thước: 96 bytes
//   0x0b6b2c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b6b30: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b6b34: 910043FD  add      x29, sp, #0x10
//   0x0b6b38: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1061_0x0b6b2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6b2cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1207f8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1062 | PC: 0x0b6b8c | FDE: 0x1206b8 | Size: 40 bytes [_ZN11fast_engine12InitCodeTypeEPNS_6EngineE]
// Hàm FDE #1062 | Địa chỉ PC: 0x0b6b8c | Địa chỉ FDE: 0x1206b8 | Kích thước: 40 bytes
//   0x0b6b8c: B0000448  adrp     x8, #0x13f000
//   0x0b6b90: F9479908  ldr      x8, [x8, #0xf30]
//   0x0b6b94: 90000009  adrp     x9, #0xb6000
//   0x0b6b98: 9000000A  adrp     x10, #0xb6000
static inline uint64_t fde_func_1062_0x0b6b8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6b8cULL ^ (static_cast<uint64_t>(0xb0000448ULL) << 13);
    acc = (acc + a1 + 0xf9479908ULL) ^ 0x1206b8ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1063 | PC: 0x0b6bb4 | FDE: 0x1206d0 | Size: 252 bytes
// Hàm FDE #1063 | Địa chỉ PC: 0x0b6bb4 | Địa chỉ FDE: 0x1206d0 | Kích thước: 252 bytes
//   0x0b6bb4: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0b6bb8: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0b6bbc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0b6bc0: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1063_0x0b6bb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6bb4ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1206d0ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1064 | PC: 0x0b6cb0 | FDE: 0x120820 | Size: 248 bytes
// Hàm FDE #1064 | Địa chỉ PC: 0x0b6cb0 | Địa chỉ FDE: 0x120820 | Kích thước: 248 bytes
//   0x0b6cb0: D10103FF  sub      sp, sp, #0x40
//   0x0b6cb4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0b6cb8: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0b6cbc: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1064_0x0b6cb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6cb0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x120820ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #1065 | PC: 0x0b6da8 | FDE: 0x1206f8 | Size: 160 bytes [_ZN11fast_engine7CodeObjC1EPNS_6EngineE]
// Hàm FDE #1065 | Địa chỉ PC: 0x0b6da8 | Địa chỉ FDE: 0x1206f8 | Kích thước: 160 bytes
//   0x0b6da8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b6dac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b6db0: 910043FD  add      x29, sp, #0x10
//   0x0b6db4: B0000448  adrp     x8, #0x13f000
static inline uint64_t fde_func_1065_0x0b6da8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6da8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1206f8ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1066 | PC: 0x0b6e48 | FDE: 0x120848 | Size: 256 bytes [_ZN11fast_engine7CodeObjC2EiiiiiiPNS_8BytesObjEPNS_8TupleObjES4_S4_S4_S4_PNS_6StrObjES6_iS2_PNS_6EngineE]
// Hàm FDE #1066 | Địa chỉ PC: 0x0b6e48 | Địa chỉ FDE: 0x120848 | Kích thước: 256 bytes
//   0x0b6e48: D10483FF  sub      sp, sp, #0x120
//   0x0b6e4c: A90C6FFC  stp      x28, x27, [sp, #0xc0]
//   0x0b6e50: A90D67FA  stp      x26, x25, [sp, #0xd0]
//   0x0b6e54: A90E5FF8  stp      x24, x23, [sp, #0xe0]
static inline uint64_t fde_func_1066_0x0b6e48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6e48ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa90c6ffcULL) ^ 0x120848ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1067 | PC: 0x0b74b8 | FDE: 0x120718 | Size: 256 bytes
// Hàm FDE #1067 | Địa chỉ PC: 0x0b74b8 | Địa chỉ FDE: 0x120718 | Kích thước: 256 bytes
//   0x0b74b8: D10143FF  sub      sp, sp, #0x50
//   0x0b74bc: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0b74c0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0b74c4: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1067_0x0b74b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b74b8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x120718ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1068 | PC: 0x0b75cc | FDE: 0x120740 | Size: 256 bytes [_ZN11fast_engine7CodeObj5ClearEPNS_6EngineE]
// Hàm FDE #1068 | Địa chỉ PC: 0x0b75cc | Địa chỉ FDE: 0x120740 | Kích thước: 256 bytes
//   0x0b75cc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b75d0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b75d4: 910043FD  add      x29, sp, #0x10
//   0x0b75d8: F9402408  ldr      x8, [x0, #0x48]
static inline uint64_t fde_func_1068_0x0b75cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b75ccULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x120740ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1069 | PC: 0x0b7838 | FDE: 0x120760 | Size: 4 bytes [_ZN11fast_engine7CodeObjD2Ev]
// Hàm FDE #1069 | Địa chỉ PC: 0x0b7838 | Địa chỉ FDE: 0x120760 | Kích thước: 4 bytes
//   0x0b7838: 17FE2E7A  b        #0x43220
static inline uint64_t fde_func_1069_0x0b7838(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7838ULL ^ (static_cast<uint64_t>(0x17fe2e7aULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x120760ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1070 | PC: 0x0b783c | FDE: 0x120778 | Size: 36 bytes [_ZN11fast_engine7CodeObjD0Ev]
// Hàm FDE #1070 | Địa chỉ PC: 0x0b783c | Địa chỉ FDE: 0x120778 | Kích thước: 36 bytes
//   0x0b783c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b7840: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b7844: 910043FD  add      x29, sp, #0x10
//   0x0b7848: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1070_0x0b783c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b783cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x120778ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1071 | PC: 0x0b7860 | FDE: 0x120798 | Size: 168 bytes [_ZN11fast_engine30LineTable_PreviousAddressRangeEPNS_13_line_offsetsE]
// Hàm FDE #1071 | Địa chỉ PC: 0x0b7860 | Địa chỉ FDE: 0x120798 | Kích thước: 168 bytes
//   0x0b7860: B9400008  ldr      w8, [x0]
//   0x0b7864: 7100051F  cmp      w8, #1
//   0x0b7868: 540004CB  b.lt     #0xb7900
//   0x0b786c: F9400C0A  ldr      x10, [x0, #0x18]
static inline uint64_t fde_func_1071_0x0b7860(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7860ULL ^ (static_cast<uint64_t>(0xb9400008ULL) << 13);
    acc = (acc + a1 + 0x7100051fULL) ^ 0x120798ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1072 | PC: 0x0b7908 | FDE: 0x1207b0 | Size: 152 bytes [_ZN11fast_engine26LineTable_NextAddressRangeEPNS_13_line_offsetsE]
// Hàm FDE #1072 | Địa chỉ PC: 0x0b7908 | Địa chỉ FDE: 0x1207b0 | Kích thước: 152 bytes
//   0x0b7908: A941A009  ldp      x9, x8, [x0, #0x18]
//   0x0b790c: EB08013F  cmp      x9, x8
//   0x0b7910: 540001E2  b.hs     #0xb794c
//   0x0b7914: B9400408  ldr      w8, [x0, #4]
static inline uint64_t fde_func_1072_0x0b7908(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7908ULL ^ (static_cast<uint64_t>(0xa941a009ULL) << 13);
    acc = (acc + a1 + 0xeb08013fULL) ^ 0x1207b0ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1073 | PC: 0x0b79a0 | FDE: 0x1207c8 | Size: 256 bytes [_ZN11fast_engine21_Code_CheckLineNumberEiPNS_13_line_offsetsE]
// Hàm FDE #1073 | Địa chỉ PC: 0x0b79a0 | Địa chỉ FDE: 0x1207c8 | Kích thước: 256 bytes
//   0x0b79a0: B9400428  ldr      w8, [x1, #4]
//   0x0b79a4: 6B00011F  cmp      w8, w0
//   0x0b79a8: 5400006D  b.le     #0xb79b4
//   0x0b79ac: B940002B  ldr      w11, [x1]
static inline uint64_t fde_func_1073_0x0b79a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b79a0ULL ^ (static_cast<uint64_t>(0xb9400428ULL) << 13);
    acc = (acc + a1 + 0x6b00011fULL) ^ 0x1207c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1074 | PC: 0x0b7b20 | FDE: 0x1207e0 | Size: 256 bytes [_ZN11fast_engine7CodeObj9Addr2LineEPS0_i]
// Hàm FDE #1074 | Địa chỉ PC: 0x0b7b20 | Địa chỉ FDE: 0x1207e0 | Kích thước: 256 bytes
//   0x0b7b20: 37F80501  tbnz     w1, #0x1f, #0xb7bc0
//   0x0b7b24: F9406C08  ldr      x8, [x0, #0xd8]
//   0x0b7b28: B4000088  cbz      x8, #0xb7b38
//   0x0b7b2c: 53017C29  lsr      w9, w1, #1
static inline uint64_t fde_func_1074_0x0b7b20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7b20ULL ^ (static_cast<uint64_t>(0x37f80501ULL) << 13);
    acc = (acc + a1 + 0xf9406c08ULL) ^ 0x1207e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1075 | PC: 0x0b7c5c | FDE: 0x121008 | Size: 96 bytes [_ZN11fast_engine20AllocMethodDescrTypeEPNS_6EngineE]
// Hàm FDE #1075 | Địa chỉ PC: 0x0b7c5c | Địa chỉ FDE: 0x121008 | Kích thước: 96 bytes
//   0x0b7c5c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b7c60: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b7c64: 910043FD  add      x29, sp, #0x10
//   0x0b7c68: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1075_0x0b7c5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7c5cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x121008ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1076 | PC: 0x0b7cbc | FDE: 0x120880 | Size: 88 bytes [_ZN11fast_engine19InitMethodDescrTypeEPNS_6EngineE]
// Hàm FDE #1076 | Địa chỉ PC: 0x0b7cbc | Địa chỉ FDE: 0x120880 | Kích thước: 88 bytes
//   0x0b7cbc: 90000448  adrp     x8, #0x13f000
//   0x0b7cc0: F944FD08  ldr      x8, [x8, #0x9f8]
//   0x0b7cc4: 90000449  adrp     x9, #0x13f000
//   0x0b7cc8: 9000000A  adrp     x10, #0xb7000
static inline uint64_t fde_func_1076_0x0b7cbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7cbcULL ^ (static_cast<uint64_t>(0x90000448ULL) << 13);
    acc = (acc + a1 + 0xf944fd08ULL) ^ 0x120880ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1077 | PC: 0x0b7d14 | FDE: 0x121030 | Size: 256 bytes
// Hàm FDE #1077 | Địa chỉ PC: 0x0b7d14 | Địa chỉ FDE: 0x121030 | Kích thước: 256 bytes
//   0x0b7d14: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0b7d18: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b7d1c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b7d20: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1077_0x0b7d14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7d14ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x121030ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1078 | PC: 0x0b7e3c | FDE: 0x121060 | Size: 192 bytes
// Hàm FDE #1078 | Địa chỉ PC: 0x0b7e3c | Địa chỉ FDE: 0x121060 | Kích thước: 192 bytes
//   0x0b7e3c: D10103FF  sub      sp, sp, #0x40
//   0x0b7e40: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0b7e44: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0b7e48: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1078_0x0b7e3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7e3cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x121060ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1079 | PC: 0x0b7efc | FDE: 0x121088 | Size: 96 bytes [_ZN11fast_engine25AllocClassMethodDescrTypeEPNS_6EngineE]
// Hàm FDE #1079 | Địa chỉ PC: 0x0b7efc | Địa chỉ FDE: 0x121088 | Kích thước: 96 bytes
//   0x0b7efc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b7f00: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b7f04: 910043FD  add      x29, sp, #0x10
//   0x0b7f08: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1079_0x0b7efc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7efcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x121088ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1080 | PC: 0x0b7f5c | FDE: 0x120898 | Size: 76 bytes [_ZN11fast_engine24InitClassMethodDescrTypeEPNS_6EngineE]
// Hàm FDE #1080 | Địa chỉ PC: 0x0b7f5c | Địa chỉ FDE: 0x120898 | Kích thước: 76 bytes
//   0x0b7f5c: 90000448  adrp     x8, #0x13f000
//   0x0b7f60: F9463908  ldr      x8, [x8, #0xc70]
//   0x0b7f64: 90000009  adrp     x9, #0xb7000
//   0x0b7f68: 913EA129  add      x9, x9, #0xfa8
static inline uint64_t fde_func_1080_0x0b7f5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7f5cULL ^ (static_cast<uint64_t>(0x90000448ULL) << 13);
    acc = (acc + a1 + 0xf9463908ULL) ^ 0x120898ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1081 | PC: 0x0b7fa8 | FDE: 0x1208b0 | Size: 240 bytes
// Hàm FDE #1081 | Địa chỉ PC: 0x0b7fa8 | Địa chỉ FDE: 0x1208b0 | Kích thước: 240 bytes
//   0x0b7fa8: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0b7fac: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0b7fb0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0b7fb4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1081_0x0b7fa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7fa8ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1208b0ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1082 | PC: 0x0b8098 | FDE: 0x1210b0 | Size: 256 bytes
// Hàm FDE #1082 | Địa chỉ PC: 0x0b8098 | Địa chỉ FDE: 0x1210b0 | Kích thước: 256 bytes
//   0x0b8098: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0b809c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b80a0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b80a4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1082_0x0b8098(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b8098ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1210b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1083 | PC: 0x0b8238 | FDE: 0x1210d8 | Size: 192 bytes
// Hàm FDE #1083 | Địa chỉ PC: 0x0b8238 | Địa chỉ FDE: 0x1210d8 | Kích thước: 192 bytes
//   0x0b8238: D10103FF  sub      sp, sp, #0x40
//   0x0b823c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0b8240: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0b8244: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1083_0x0b8238(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b8238ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x1210d8ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1084 | PC: 0x0b82f8 | FDE: 0x1208d8 | Size: 104 bytes [_ZN11fast_engine19ClassMethodDescrObjC1EPKNS_7TypeObjEPKNS_9MethodDefEPNS_6EngineE]
// Hàm FDE #1084 | Địa chỉ PC: 0x0b82f8 | Địa chỉ FDE: 0x1208d8 | Kích thước: 104 bytes
//   0x0b82f8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0b82fc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b8300: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b8304: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1084_0x0b82f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b82f8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1208d8ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1085 | PC: 0x0b8360 | FDE: 0x120900 | Size: 92 bytes [_ZN11fast_engine8DescrObjC1EPKcPKNS_7TypeObjEPS3_PNS_6EngineEl]
// Hàm FDE #1085 | Địa chỉ PC: 0x0b8360 | Địa chỉ FDE: 0x120900 | Kích thước: 92 bytes
//   0x0b8360: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0b8364: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b8368: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b836c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1085_0x0b8360(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b8360ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x120900ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1086 | PC: 0x0b83bc | FDE: 0x121100 | Size: 96 bytes [_ZN11fast_engine20AllocMemberDescrTypeEPNS_6EngineE]
// Hàm FDE #1086 | Địa chỉ PC: 0x0b83bc | Địa chỉ FDE: 0x121100 | Kích thước: 96 bytes
//   0x0b83bc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b83c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b83c4: 910043FD  add      x29, sp, #0x10
//   0x0b83c8: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1086_0x0b83bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b83bcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x121100ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1087 | PC: 0x0b841c | FDE: 0x120920 | Size: 60 bytes [_ZN11fast_engine19InitMemberDescrTypeEPNS_6EngineE]
// Hàm FDE #1087 | Địa chỉ PC: 0x0b841c | Địa chỉ FDE: 0x120920 | Kích thước: 60 bytes
//   0x0b841c: F0000428  adrp     x8, #0x13f000
//   0x0b8420: F946F908  ldr      x8, [x8, #0xdf0]
//   0x0b8424: 90000009  adrp     x9, #0xb8000
//   0x0b8428: 9000000A  adrp     x10, #0xb8000
static inline uint64_t fde_func_1087_0x0b841c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b841cULL ^ (static_cast<uint64_t>(0xf0000428ULL) << 13);
    acc = (acc + a1 + 0xf946f908ULL) ^ 0x120920ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1088 | PC: 0x0b8458 | FDE: 0x120938 | Size: 204 bytes
// Hàm FDE #1088 | Địa chỉ PC: 0x0b8458 | Địa chỉ FDE: 0x120938 | Kích thước: 204 bytes
//   0x0b8458: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0b845c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b8460: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b8464: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1088_0x0b8458(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b8458ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x120938ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1089 | PC: 0x0b8524 | FDE: 0x120960 | Size: 256 bytes
// Hàm FDE #1089 | Địa chỉ PC: 0x0b8524 | Địa chỉ FDE: 0x120960 | Kích thước: 256 bytes
//   0x0b8524: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0b8528: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b852c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b8530: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1089_0x0b8524(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b8524ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x120960ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1090 | PC: 0x0b8630 | FDE: 0x121128 | Size: 192 bytes
// Hàm FDE #1090 | Địa chỉ PC: 0x0b8630 | Địa chỉ FDE: 0x121128 | Kích thước: 192 bytes
//   0x0b8630: D10103FF  sub      sp, sp, #0x40
//   0x0b8634: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0b8638: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0b863c: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1090_0x0b8630(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b8630ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x121128ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1091 | PC: 0x0b86f0 | FDE: 0x121150 | Size: 96 bytes [_ZN11fast_engine20AllocGetSetDescrTypeEPNS_6EngineE]
// Hàm FDE #1091 | Địa chỉ PC: 0x0b86f0 | Địa chỉ FDE: 0x121150 | Kích thước: 96 bytes
//   0x0b86f0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b86f4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b86f8: 910043FD  add      x29, sp, #0x10
//   0x0b86fc: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1091_0x0b86f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b86f0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x121150ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1092 | PC: 0x0b8750 | FDE: 0x120988 | Size: 60 bytes [_ZN11fast_engine19InitGetSetDescrTypeEPNS_6EngineE]
// Hàm FDE #1092 | Địa chỉ PC: 0x0b8750 | Địa chỉ FDE: 0x120988 | Kích thước: 60 bytes
//   0x0b8750: F0000428  adrp     x8, #0x13f000
//   0x0b8754: F9458D08  ldr      x8, [x8, #0xb18]
//   0x0b8758: 90000009  adrp     x9, #0xb8000
//   0x0b875c: 9000000A  adrp     x10, #0xb8000
static inline uint64_t fde_func_1092_0x0b8750(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b8750ULL ^ (static_cast<uint64_t>(0xf0000428ULL) << 13);
    acc = (acc + a1 + 0xf9458d08ULL) ^ 0x120988ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1093 | PC: 0x0b878c | FDE: 0x1209a0 | Size: 256 bytes
// Hàm FDE #1093 | Địa chỉ PC: 0x0b878c | Địa chỉ FDE: 0x1209a0 | Kích thước: 256 bytes
//   0x0b878c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0b8790: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b8794: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b8798: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1093_0x0b878c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b878cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1209a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1094 | PC: 0x0b88ac | FDE: 0x1209c0 | Size: 256 bytes
// Hàm FDE #1094 | Địa chỉ PC: 0x0b88ac | Địa chỉ FDE: 0x1209c0 | Kích thước: 256 bytes
//   0x0b88ac: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0b88b0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b88b4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b88b8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1094_0x0b88ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b88acULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1209c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1095 | PC: 0x0b89b8 | FDE: 0x121178 | Size: 192 bytes
// Hàm FDE #1095 | Địa chỉ PC: 0x0b89b8 | Địa chỉ FDE: 0x121178 | Kích thước: 192 bytes
//   0x0b89b8: D10103FF  sub      sp, sp, #0x40
//   0x0b89bc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0b89c0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0b89c4: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1095_0x0b89b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b89b8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x121178ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1096 | PC: 0x0b8a78 | FDE: 0x1209e8 | Size: 84 bytes [_ZN11fast_engine8DescrObj5ClearEPNS_6EngineE]
// Hàm FDE #1096 | Địa chỉ PC: 0x0b8a78 | Địa chỉ FDE: 0x1209e8 | Kích thước: 84 bytes
//   0x0b8a78: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b8a7c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b8a80: 910043FD  add      x29, sp, #0x10
//   0x0b8a84: F9402808  ldr      x8, [x0, #0x50]
static inline uint64_t fde_func_1096_0x0b8a78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b8a78ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1209e8ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1097 | PC: 0x0b8acc | FDE: 0x1211a0 | Size: 256 bytes [_ZN11fast_engine14MethodDescrObjC1EPKNS_7TypeObjEPKNS_9MethodDefEPNS_6EngineE]
// Hàm FDE #1097 | Địa chỉ PC: 0x0b8acc | Địa chỉ FDE: 0x1211a0 | Kích thước: 256 bytes
//   0x0b8acc: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0b8ad0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0b8ad4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0b8ad8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1097_0x0b8acc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b8accULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1211a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1098 | PC: 0x0b8c00 | FDE: 0x120a08 | Size: 192 bytes
// Hàm FDE #1098 | Địa chỉ PC: 0x0b8c00 | Địa chỉ FDE: 0x120a08 | Kích thước: 192 bytes
//   0x0b8c00: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0b8c04: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b8c08: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b8c0c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1098_0x0b8c00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b8c00ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x120a08ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1099 | PC: 0x0b8cc0 | FDE: 0x120a30 | Size: 256 bytes
// Hàm FDE #1099 | Địa chỉ PC: 0x0b8cc0 | Địa chỉ FDE: 0x120a30 | Kích thước: 256 bytes
//   0x0b8cc0: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0b8cc4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0b8cc8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0b8ccc: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1099_0x0b8cc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b8cc0ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x120a30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1100 | PC: 0x0b8df0 | FDE: 0x120a58 | Size: 120 bytes
// Hàm FDE #1100 | Địa chỉ PC: 0x0b8df0 | Địa chỉ FDE: 0x120a58 | Kích thước: 120 bytes
//   0x0b8df0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0b8df4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b8df8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b8dfc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1100_0x0b8df0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b8df0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x120a58ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1101 | PC: 0x0b8e68 | FDE: 0x120a80 | Size: 140 bytes
// Hàm FDE #1101 | Địa chỉ PC: 0x0b8e68 | Địa chỉ FDE: 0x120a80 | Kích thước: 140 bytes
//   0x0b8e68: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0b8e6c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0b8e70: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0b8e74: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1101_0x0b8e68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b8e68ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x120a80ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1102 | PC: 0x0b8ef4 | FDE: 0x120aa8 | Size: 156 bytes
// Hàm FDE #1102 | Địa chỉ PC: 0x0b8ef4 | Địa chỉ FDE: 0x120aa8 | Kích thước: 156 bytes
//   0x0b8ef4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0b8ef8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b8efc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b8f00: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1102_0x0b8ef4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b8ef4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x120aa8ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1103 | PC: 0x0b8f90 | FDE: 0x120ad0 | Size: 156 bytes
// Hàm FDE #1103 | Địa chỉ PC: 0x0b8f90 | Địa chỉ FDE: 0x120ad0 | Kích thước: 156 bytes
//   0x0b8f90: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0b8f94: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b8f98: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b8f9c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1103_0x0b8f90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b8f90ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x120ad0ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1104 | PC: 0x0b902c | FDE: 0x120af8 | Size: 104 bytes [_ZN11fast_engine14MemberDescrObjC1EPKNS_7TypeObjEPKNS_9MemberDefEPNS_6EngineE]
// Hàm FDE #1104 | Địa chỉ PC: 0x0b902c | Địa chỉ FDE: 0x120af8 | Kích thước: 104 bytes
//   0x0b902c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0b9030: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b9034: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b9038: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1104_0x0b902c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b902cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x120af8ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1105 | PC: 0x0b9094 | FDE: 0x120b20 | Size: 104 bytes [_ZN11fast_engine14GetSetDescrObjC2EPKNS_7TypeObjEPKNS_9GetSetDefEPNS_6EngineE]
// Hàm FDE #1105 | Địa chỉ PC: 0x0b9094 | Địa chỉ FDE: 0x120b20 | Kích thước: 104 bytes
//   0x0b9094: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0b9098: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b909c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b90a0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1105_0x0b9094(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b9094ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x120b20ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1106 | PC: 0x0b90fc | FDE: 0x120b48 | Size: 80 bytes [_ZN11fast_engine15MappingProxyObj5ClearEPNS_6EngineE]
// Hàm FDE #1106 | Địa chỉ PC: 0x0b90fc | Địa chỉ FDE: 0x120b48 | Kích thước: 80 bytes
//   0x0b90fc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b9100: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b9104: 910043FD  add      x29, sp, #0x10
//   0x0b9108: F9402008  ldr      x8, [x0, #0x40]
static inline uint64_t fde_func_1106_0x0b90fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b90fcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x120b48ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1107 | PC: 0x0b914c | FDE: 0x120b68 | Size: 100 bytes [_ZN11fast_engine15MappingProxyObjC1EPNS_3ObjEPNS_7TypeObjEPNS_6EngineE]
// Hàm FDE #1107 | Địa chỉ PC: 0x0b914c | Địa chỉ FDE: 0x120b68 | Kích thước: 100 bytes
//   0x0b914c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b9150: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b9154: 910043FD  add      x29, sp, #0x10
//   0x0b9158: AA0303E8  mov      x8, x3
static inline uint64_t fde_func_1107_0x0b914c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b914cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x120b68ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1108 | PC: 0x0b91b0 | FDE: 0x1211d0 | Size: 240 bytes [_ZN11fast_engine12DictProxyNewEPNS_3ObjEPNS_6EngineE]
// Hàm FDE #1108 | Địa chỉ PC: 0x0b91b0 | Địa chỉ FDE: 0x1211d0 | Kích thước: 240 bytes
//   0x0b91b0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0b91b4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b91b8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b91bc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1108_0x0b91b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b91b0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1211d0ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1109 | PC: 0x0b92a0 | FDE: 0x1211f8 | Size: 96 bytes [_ZN11fast_engine18AllocDictProxyTypeEPNS_6EngineE]
// Hàm FDE #1109 | Địa chỉ PC: 0x0b92a0 | Địa chỉ FDE: 0x1211f8 | Kích thước: 96 bytes
//   0x0b92a0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b92a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b92a8: 910043FD  add      x29, sp, #0x10
//   0x0b92ac: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1109_0x0b92a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b92a0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1211f8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1110 | PC: 0x0b9300 | FDE: 0x120b88 | Size: 256 bytes [_ZN11fast_engine17InitDictProxyTypeEPNS_6EngineE]
// Hàm FDE #1110 | Địa chỉ PC: 0x0b9300 | Địa chỉ FDE: 0x120b88 | Kích thước: 256 bytes
//   0x0b9300: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b9304: 910003FD  mov      x29, sp
//   0x0b9308: D0000429  adrp     x9, #0x13f000
//   0x0b930c: F947F129  ldr      x9, [x9, #0xfe0]
static inline uint64_t fde_func_1110_0x0b9300(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b9300ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x120b88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1111 | PC: 0x0b94ec | FDE: 0x120ba8 | Size: 8 bytes
// Hàm FDE #1111 | Địa chỉ PC: 0x0b94ec | Địa chỉ FDE: 0x120ba8 | Kích thước: 8 bytes
//   0x0b94ec: F9402000  ldr      x0, [x0, #0x40]
//   0x0b94f0: 17FE2428  b        #0x42590
static inline uint64_t fde_func_1111_0x0b94ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b94ecULL ^ (static_cast<uint64_t>(0xf9402000ULL) << 13);
    acc = (acc + a1 + 0x17fe2428ULL) ^ 0x120ba8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1112 | PC: 0x0b94f4 | FDE: 0x120bc0 | Size: 8 bytes
// Hàm FDE #1112 | Địa chỉ PC: 0x0b94f4 | Địa chỉ FDE: 0x120bc0 | Kích thước: 8 bytes
//   0x0b94f4: F9402000  ldr      x0, [x0, #0x40]
//   0x0b94f8: 17FE257E  b        #0x42af0
static inline uint64_t fde_func_1112_0x0b94f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b94f4ULL ^ (static_cast<uint64_t>(0xf9402000ULL) << 13);
    acc = (acc + a1 + 0x17fe257eULL) ^ 0x120bc0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1113 | PC: 0x0b94fc | FDE: 0x120bd8 | Size: 8 bytes
// Hàm FDE #1113 | Địa chỉ PC: 0x0b94fc | Địa chỉ FDE: 0x120bd8 | Kích thước: 8 bytes
//   0x0b94fc: F9402000  ldr      x0, [x0, #0x40]
//   0x0b9500: 17FE2900  b        #0x43900
static inline uint64_t fde_func_1113_0x0b94fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b94fcULL ^ (static_cast<uint64_t>(0xf9402000ULL) << 13);
    acc = (acc + a1 + 0x17fe2900ULL) ^ 0x120bd8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1114 | PC: 0x0b9504 | FDE: 0x120bf0 | Size: 8 bytes
// Hàm FDE #1114 | Địa chỉ PC: 0x0b9504 | Địa chỉ FDE: 0x120bf0 | Kích thước: 8 bytes
//   0x0b9504: F9402000  ldr      x0, [x0, #0x40]
//   0x0b9508: 17FE30CA  b        #0x45830
static inline uint64_t fde_func_1114_0x0b9504(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b9504ULL ^ (static_cast<uint64_t>(0xf9402000ULL) << 13);
    acc = (acc + a1 + 0x17fe30caULL) ^ 0x120bf0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1115 | PC: 0x0b950c | FDE: 0x120c08 | Size: 8 bytes
// Hàm FDE #1115 | Địa chỉ PC: 0x0b950c | Địa chỉ FDE: 0x120c08 | Kích thước: 8 bytes
//   0x0b950c: F9402000  ldr      x0, [x0, #0x40]
//   0x0b9510: 17FE2770  b        #0x432d0
static inline uint64_t fde_func_1115_0x0b950c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b950cULL ^ (static_cast<uint64_t>(0xf9402000ULL) << 13);
    acc = (acc + a1 + 0x17fe2770ULL) ^ 0x120c08ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1116 | PC: 0x0b9514 | FDE: 0x120c20 | Size: 124 bytes
// Hàm FDE #1116 | Địa chỉ PC: 0x0b9514 | Địa chỉ FDE: 0x120c20 | Kích thước: 124 bytes
//   0x0b9514: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0b9518: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b951c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b9520: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1116_0x0b9514(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b9514ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x120c20ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1117 | PC: 0x0b9590 | FDE: 0x120c48 | Size: 76 bytes
// Hàm FDE #1117 | Địa chỉ PC: 0x0b9590 | Địa chỉ FDE: 0x120c48 | Kích thước: 76 bytes
//   0x0b9590: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b9594: 910003FD  mov      x29, sp
//   0x0b9598: D0000429  adrp     x9, #0x13f000
//   0x0b959c: F9401408  ldr      x8, [x0, #0x28]
static inline uint64_t fde_func_1117_0x0b9590(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b9590ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x120c48ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1118 | PC: 0x0b95dc | FDE: 0x120c68 | Size: 88 bytes
// Hàm FDE #1118 | Địa chỉ PC: 0x0b95dc | Địa chỉ FDE: 0x120c68 | Kích thước: 88 bytes
//   0x0b95dc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b95e0: 910003FD  mov      x29, sp
//   0x0b95e4: D0000429  adrp     x9, #0x13f000
//   0x0b95e8: F9402008  ldr      x8, [x0, #0x40]
static inline uint64_t fde_func_1118_0x0b95dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b95dcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x120c68ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1119 | PC: 0x0b9634 | FDE: 0x120c88 | Size: 16 bytes
// Hàm FDE #1119 | Địa chỉ PC: 0x0b9634 | Địa chỉ FDE: 0x120c88 | Kích thước: 16 bytes
//   0x0b9634: F9402008  ldr      x8, [x0, #0x40]
//   0x0b9638: AA0103E0  mov      x0, x1
//   0x0b963c: AA0803E1  mov      x1, x8
//   0x0b9640: 17FE23C0  b        #0x42540
static inline uint64_t fde_func_1119_0x0b9634(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b9634ULL ^ (static_cast<uint64_t>(0xf9402008ULL) << 13);
    acc = (acc + a1 + 0xaa0103e0ULL) ^ 0x120c88ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1120 | PC: 0x0b9644 | FDE: 0x120ca0 | Size: 24 bytes
// Hàm FDE #1120 | Địa chỉ PC: 0x0b9644 | Địa chỉ FDE: 0x120ca0 | Kích thước: 24 bytes
//   0x0b9644: F9402008  ldr      x8, [x0, #0x40]
//   0x0b9648: AA0103E9  mov      x9, x1
//   0x0b964c: AA0203E0  mov      x0, x2
//   0x0b9650: AA0903E2  mov      x2, x9
static inline uint64_t fde_func_1120_0x0b9644(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b9644ULL ^ (static_cast<uint64_t>(0xf9402008ULL) << 13);
    acc = (acc + a1 + 0xaa0103e9ULL) ^ 0x120ca0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1121 | PC: 0x0b965c | FDE: 0x121220 | Size: 256 bytes
// Hàm FDE #1121 | Địa chỉ PC: 0x0b965c | Địa chỉ FDE: 0x121220 | Kích thước: 256 bytes
//   0x0b965c: D101C3FF  sub      sp, sp, #0x70
//   0x0b9660: F90013F9  str      x25, [sp, #0x20]
//   0x0b9664: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0b9668: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1121_0x0b965c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b965cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x121220ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1122 | PC: 0x0b9818 | FDE: 0x121250 | Size: 256 bytes
// Hàm FDE #1122 | Địa chỉ PC: 0x0b9818 | Địa chỉ FDE: 0x121250 | Kích thước: 256 bytes
//   0x0b9818: D101C3FF  sub      sp, sp, #0x70
//   0x0b981c: F90013F9  str      x25, [sp, #0x20]
//   0x0b9820: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0b9824: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1122_0x0b9818(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b9818ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x121250ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1123 | PC: 0x0b99d4 | FDE: 0x121280 | Size: 256 bytes
// Hàm FDE #1123 | Địa chỉ PC: 0x0b99d4 | Địa chỉ FDE: 0x121280 | Kích thước: 256 bytes
//   0x0b99d4: D101C3FF  sub      sp, sp, #0x70
//   0x0b99d8: F90013F9  str      x25, [sp, #0x20]
//   0x0b99dc: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0b99e0: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1123_0x0b99d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b99d4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x121280ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1124 | PC: 0x0b9b90 | FDE: 0x1212b0 | Size: 256 bytes
// Hàm FDE #1124 | Địa chỉ PC: 0x0b9b90 | Địa chỉ FDE: 0x1212b0 | Kích thước: 256 bytes
//   0x0b9b90: D101C3FF  sub      sp, sp, #0x70
//   0x0b9b94: F90013F9  str      x25, [sp, #0x20]
//   0x0b9b98: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0b9b9c: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1124_0x0b9b90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b9b90ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x1212b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1125 | PC: 0x0b9d4c | FDE: 0x1212e0 | Size: 256 bytes
// Hàm FDE #1125 | Địa chỉ PC: 0x0b9d4c | Địa chỉ FDE: 0x1212e0 | Kích thước: 256 bytes
//   0x0b9d4c: D101C3FF  sub      sp, sp, #0x70
//   0x0b9d50: F90013F9  str      x25, [sp, #0x20]
//   0x0b9d54: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0b9d58: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1125_0x0b9d4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b9d4cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x1212e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1126 | PC: 0x0b9f08 | FDE: 0x121310 | Size: 256 bytes
// Hàm FDE #1126 | Địa chỉ PC: 0x0b9f08 | Địa chỉ FDE: 0x121310 | Kích thước: 256 bytes
//   0x0b9f08: D10203FF  sub      sp, sp, #0x80
//   0x0b9f0c: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0b9f10: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0b9f14: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_1126_0x0b9f08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b9f08ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9045ff8ULL) ^ 0x121310ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1127 | PC: 0x0ba0f8 | FDE: 0x121340 | Size: 96 bytes [_ZN11fast_engine21AllocWrapperDescrTypeEPNS_6EngineE]
// Hàm FDE #1127 | Địa chỉ PC: 0x0ba0f8 | Địa chỉ FDE: 0x121340 | Kích thước: 96 bytes
//   0x0ba0f8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ba0fc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ba100: 910043FD  add      x29, sp, #0x10
//   0x0ba104: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1127_0x0ba0f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ba0f8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x121340ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1128 | PC: 0x0ba158 | FDE: 0x120cb8 | Size: 84 bytes [_ZN11fast_engine20InitWrapperDescrTypeEPNS_6EngineE]
// Hàm FDE #1128 | Địa chỉ PC: 0x0ba158 | Địa chỉ FDE: 0x120cb8 | Kích thước: 84 bytes
//   0x0ba158: B0000428  adrp     x8, #0x13f000
//   0x0ba15c: F943F508  ldr      x8, [x8, #0x7e8]
//   0x0ba160: 52802009  mov      w9, #0x100
//   0x0ba164: 72A00049  movk     w9, #2, lsl #16
static inline uint64_t fde_func_1128_0x0ba158(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ba158ULL ^ (static_cast<uint64_t>(0xb0000428ULL) << 13);
    acc = (acc + a1 + 0xf943f508ULL) ^ 0x120cb8ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1129 | PC: 0x0ba1ac | FDE: 0x121368 | Size: 256 bytes
// Hàm FDE #1129 | Địa chỉ PC: 0x0ba1ac | Địa chỉ FDE: 0x121368 | Kích thước: 256 bytes
//   0x0ba1ac: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0ba1b0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ba1b4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ba1b8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1129_0x0ba1ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ba1acULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x121368ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1130 | PC: 0x0ba2f4 | FDE: 0x120cd0 | Size: 256 bytes
// Hàm FDE #1130 | Địa chỉ PC: 0x0ba2f4 | Địa chỉ FDE: 0x120cd0 | Kích thước: 256 bytes
//   0x0ba2f4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0ba2f8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0ba2fc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0ba300: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1130_0x0ba2f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ba2f4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x120cd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1131 | PC: 0x0ba4d8 | FDE: 0x121398 | Size: 200 bytes
// Hàm FDE #1131 | Địa chỉ PC: 0x0ba4d8 | Địa chỉ FDE: 0x121398 | Kích thước: 200 bytes
//   0x0ba4d8: D10103FF  sub      sp, sp, #0x40
//   0x0ba4dc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0ba4e0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0ba4e4: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1131_0x0ba4d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ba4d8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x121398ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1132 | PC: 0x0ba5a0 | FDE: 0x120cf8 | Size: 120 bytes [_ZN11fast_engine15WrapperDescrObjC1EPKNS_7TypeObjEPNS_11WrapperBaseEPvPNS_6EngineE]
// Hàm FDE #1132 | Địa chỉ PC: 0x0ba5a0 | Địa chỉ FDE: 0x120cf8 | Kích thước: 120 bytes
//   0x0ba5a0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0ba5a4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0ba5a8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0ba5ac: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1132_0x0ba5a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ba5a0ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x120cf8ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1133 | PC: 0x0ba618 | FDE: 0x1213c0 | Size: 96 bytes [_ZN11fast_engine22AllocMethodWrapperTypeEPNS_6EngineE]
// Hàm FDE #1133 | Địa chỉ PC: 0x0ba618 | Địa chỉ FDE: 0x1213c0 | Kích thước: 96 bytes
//   0x0ba618: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ba61c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ba620: 910043FD  add      x29, sp, #0x10
//   0x0ba624: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1133_0x0ba618(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ba618ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1213c0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1134 | PC: 0x0ba678 | FDE: 0x120d20 | Size: 64 bytes [_ZN11fast_engine21InitMethodWrapperTypeEPNS_6EngineE]
// Hàm FDE #1134 | Địa chỉ PC: 0x0ba678 | Địa chỉ FDE: 0x120d20 | Kích thước: 64 bytes
//   0x0ba678: B0000428  adrp     x8, #0x13f000
//   0x0ba67c: F9439108  ldr      x8, [x8, #0x720]
//   0x0ba680: 90000009  adrp     x9, #0xba000
//   0x0ba684: D000042A  adrp     x10, #0x140000
static inline uint64_t fde_func_1134_0x0ba678(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ba678ULL ^ (static_cast<uint64_t>(0xb0000428ULL) << 13);
    acc = (acc + a1 + 0xf9439108ULL) ^ 0x120d20ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1135 | PC: 0x0ba6b8 | FDE: 0x120d38 | Size: 224 bytes
// Hàm FDE #1135 | Địa chỉ PC: 0x0ba6b8 | Địa chỉ FDE: 0x120d38 | Kích thước: 224 bytes
//   0x0ba6b8: D10103FF  sub      sp, sp, #0x40
//   0x0ba6bc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0ba6c0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0ba6c4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1135_0x0ba6b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ba6b8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x120d38ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #1136 | PC: 0x0ba798 | FDE: 0x120d60 | Size: 200 bytes
// Hàm FDE #1136 | Địa chỉ PC: 0x0ba798 | Địa chỉ FDE: 0x120d60 | Kích thước: 200 bytes
//   0x0ba798: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0ba79c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ba7a0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ba7a4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1136_0x0ba798(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ba798ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x120d60ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1137 | PC: 0x0ba860 | FDE: 0x1213e8 | Size: 200 bytes
// Hàm FDE #1137 | Địa chỉ PC: 0x0ba860 | Địa chỉ FDE: 0x1213e8 | Kích thước: 200 bytes
//   0x0ba860: D10103FF  sub      sp, sp, #0x40
//   0x0ba864: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0ba868: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0ba86c: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1137_0x0ba860(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ba860ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x1213e8ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1138 | PC: 0x0ba928 | FDE: 0x120d88 | Size: 152 bytes [_ZN11fast_engine10WrapperObjC2EPNS_15WrapperDescrObjEPNS_3ObjEPNS_6EngineE]
// Hàm FDE #1138 | Địa chỉ PC: 0x0ba928 | Địa chỉ FDE: 0x120d88 | Kích thước: 152 bytes
//   0x0ba928: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0ba92c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ba930: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ba934: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1138_0x0ba928(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ba928ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x120d88ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1139 | PC: 0x0ba9c0 | FDE: 0x120da8 | Size: 148 bytes [_ZN11fast_engine10WrapperObj5ClearEPNS_6EngineE]
// Hàm FDE #1139 | Địa chỉ PC: 0x0ba9c0 | Địa chỉ FDE: 0x120da8 | Kích thước: 148 bytes
//   0x0ba9c0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ba9c4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ba9c8: 910043FD  add      x29, sp, #0x10
//   0x0ba9cc: F9402008  ldr      x8, [x0, #0x40]
static inline uint64_t fde_func_1139_0x0ba9c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ba9c0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x120da8ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1140 | PC: 0x0baa54 | FDE: 0x121410 | Size: 96 bytes [_ZN11fast_engine17AllocPropertyTypeEPNS_6EngineE]
// Hàm FDE #1140 | Địa chỉ PC: 0x0baa54 | Địa chỉ FDE: 0x121410 | Kích thước: 96 bytes
//   0x0baa54: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0baa58: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0baa5c: 910043FD  add      x29, sp, #0x10
//   0x0baa60: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1140_0x0baa54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0baa54ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x121410ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1141 | PC: 0x0baab4 | FDE: 0x121438 | Size: 256 bytes [_ZN11fast_engine16InitPropertyTypeEPNS_6EngineE]
// Hàm FDE #1141 | Địa chỉ PC: 0x0baab4 | Địa chỉ FDE: 0x121438 | Kích thước: 256 bytes
//   0x0baab4: FC1C0FE8  str      d8, [sp, #-0x40]!
//   0x0baab8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0baabc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0baac0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1141_0x0baab4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0baab4ULL ^ (static_cast<uint64_t>(0xfc1c0fe8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x121438ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1142 | PC: 0x0bacc4 | FDE: 0x120dc8 | Size: 256 bytes
// Hàm FDE #1142 | Địa chỉ PC: 0x0bacc4 | Địa chỉ FDE: 0x120dc8 | Kích thước: 256 bytes
//   0x0bacc4: D10103FF  sub      sp, sp, #0x40
//   0x0bacc8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0baccc: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0bacd0: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1142_0x0bacc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bacc4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x120dc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1143 | PC: 0x0badcc | FDE: 0x121468 | Size: 256 bytes
// Hàm FDE #1143 | Địa chỉ PC: 0x0badcc | Địa chỉ FDE: 0x121468 | Kích thước: 256 bytes
//   0x0badcc: D10103FF  sub      sp, sp, #0x40
//   0x0badd0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0badd4: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0badd8: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1143_0x0badcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0badccULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x121468ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1144 | PC: 0x0baf4c | FDE: 0x121490 | Size: 232 bytes
// Hàm FDE #1144 | Địa chỉ PC: 0x0baf4c | Địa chỉ FDE: 0x121490 | Kích thước: 232 bytes
//   0x0baf4c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0baf50: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0baf54: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0baf58: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1144_0x0baf4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0baf4cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x121490ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1145 | PC: 0x0bb034 | FDE: 0x1214c0 | Size: 236 bytes
// Hàm FDE #1145 | Địa chỉ PC: 0x0bb034 | Địa chỉ FDE: 0x1214c0 | Kích thước: 236 bytes
//   0x0bb034: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0bb038: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0bb03c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0bb040: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1145_0x0bb034(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bb034ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1214c0ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #1146 | PC: 0x0bb120 | FDE: 0x1214f0 | Size: 232 bytes
// Hàm FDE #1146 | Địa chỉ PC: 0x0bb120 | Địa chỉ FDE: 0x1214f0 | Kích thước: 232 bytes
//   0x0bb120: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0bb124: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0bb128: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0bb12c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1146_0x0bb120(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bb120ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1214f0ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1147 | PC: 0x0bb208 | FDE: 0x120de8 | Size: 256 bytes
// Hàm FDE #1147 | Địa chỉ PC: 0x0bb208 | Địa chỉ FDE: 0x120de8 | Kích thước: 256 bytes
//   0x0bb208: D10243FF  sub      sp, sp, #0x90
//   0x0bb20c: F90023F9  str      x25, [sp, #0x40]
//   0x0bb210: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x0bb214: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_1147_0x0bb208(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bb208ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90023f9ULL) ^ 0x120de8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1148 | PC: 0x0bb498 | FDE: 0x121520 | Size: 116 bytes
// Hàm FDE #1148 | Địa chỉ PC: 0x0bb498 | Địa chỉ FDE: 0x121520 | Kích thước: 116 bytes
//   0x0bb498: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0bb49c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bb4a0: 910043FD  add      x29, sp, #0x10
//   0x0bb4a4: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1148_0x0bb498(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bb498ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x121520ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1149 | PC: 0x0bb50c | FDE: 0x121548 | Size: 148 bytes
// Hàm FDE #1149 | Địa chỉ PC: 0x0bb50c | Địa chỉ FDE: 0x121548 | Kích thước: 148 bytes
//   0x0bb50c: D10103FF  sub      sp, sp, #0x40
//   0x0bb510: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0bb514: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0bb518: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1149_0x0bb50c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bb50cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x121548ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1150 | PC: 0x0bb5a0 | FDE: 0x120e10 | Size: 188 bytes [_ZN11fast_engine11PropertyObjC1EPNS_3ObjES2_S2_PNS_6EngineE]
// Hàm FDE #1150 | Địa chỉ PC: 0x0bb5a0 | Địa chỉ FDE: 0x120e10 | Kích thước: 188 bytes
//   0x0bb5a0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0bb5a4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0bb5a8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0bb5ac: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1150_0x0bb5a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bb5a0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x120e10ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1151 | PC: 0x0bb65c | FDE: 0x120e38 | Size: 208 bytes [_ZN11fast_engine11PropertyObj5ClearEPNS_6EngineE]
// Hàm FDE #1151 | Địa chỉ PC: 0x0bb65c | Địa chỉ FDE: 0x120e38 | Kích thước: 208 bytes
//   0x0bb65c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0bb660: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bb664: 910043FD  add      x29, sp, #0x10
//   0x0bb668: F9402008  ldr      x8, [x0, #0x40]
static inline uint64_t fde_func_1151_0x0bb65c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bb65cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x120e38ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1152 | PC: 0x0bb72c | FDE: 0x121570 | Size: 96 bytes [_ZN11fast_engine14AllocSuperTypeEPNS_6EngineE]
// Hàm FDE #1152 | Địa chỉ PC: 0x0bb72c | Địa chỉ FDE: 0x121570 | Kích thước: 96 bytes
//   0x0bb72c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0bb730: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bb734: 910043FD  add      x29, sp, #0x10
//   0x0bb738: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1152_0x0bb72c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bb72cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x121570ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1153 | PC: 0x0bb78c | FDE: 0x120e58 | Size: 52 bytes [_ZN11fast_engine13InitSuperTypeEPNS_6EngineE]
// Hàm FDE #1153 | Địa chỉ PC: 0x0bb78c | Địa chỉ FDE: 0x120e58 | Kích thước: 52 bytes
//   0x0bb78c: 90000428  adrp     x8, #0x13f000
//   0x0bb790: F9460D08  ldr      x8, [x8, #0xc18]
//   0x0bb794: 90000009  adrp     x9, #0xbb000
//   0x0bb798: 9000000A  adrp     x10, #0xbb000
static inline uint64_t fde_func_1153_0x0bb78c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bb78cULL ^ (static_cast<uint64_t>(0x90000428ULL) << 13);
    acc = (acc + a1 + 0xf9460d08ULL) ^ 0x120e58ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1154 | PC: 0x0bb7c0 | FDE: 0x121598 | Size: 256 bytes
// Hàm FDE #1154 | Địa chỉ PC: 0x0bb7c0 | Địa chỉ FDE: 0x121598 | Kích thước: 256 bytes
//   0x0bb7c0: D10183FF  sub      sp, sp, #0x60
//   0x0bb7c4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0bb7c8: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0bb7cc: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1154_0x0bb7c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bb7c0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x121598ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1155 | PC: 0x0bb940 | FDE: 0x1215c8 | Size: 256 bytes
// Hàm FDE #1155 | Địa chỉ PC: 0x0bb940 | Địa chỉ FDE: 0x1215c8 | Kích thước: 256 bytes
//   0x0bb940: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0bb944: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0bb948: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0bb94c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1155_0x0bb940(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bb940ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1215c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1156 | PC: 0x0bbcb0 | FDE: 0x121600 | Size: 252 bytes
// Hàm FDE #1156 | Địa chỉ PC: 0x0bbcb0 | Địa chỉ FDE: 0x121600 | Kích thước: 252 bytes
//   0x0bbcb0: D10103FF  sub      sp, sp, #0x40
//   0x0bbcb4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0bbcb8: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0bbcbc: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1156_0x0bbcb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bbcb0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x121600ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1157 | PC: 0x0bbdac | FDE: 0x120e70 | Size: 144 bytes [_ZN11fast_engine8SuperObjC2EPNS_7TypeObjEPNS_3ObjEPNS_6EngineE]
// Hàm FDE #1157 | Địa chỉ PC: 0x0bbdac | Địa chỉ FDE: 0x120e70 | Kích thước: 144 bytes
//   0x0bbdac: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0bbdb0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0bbdb4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0bbdb8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1157_0x0bbdac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bbdacULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x120e70ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1158 | PC: 0x0bbe3c | FDE: 0x120e90 | Size: 132 bytes [_ZN11fast_engine8SuperObj5ClearEPNS_6EngineE]
// Hàm FDE #1158 | Địa chỉ PC: 0x0bbe3c | Địa chỉ FDE: 0x120e90 | Kích thước: 132 bytes
//   0x0bbe3c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0bbe40: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bbe44: 910043FD  add      x29, sp, #0x10
//   0x0bbe48: F9402008  ldr      x8, [x0, #0x40]
static inline uint64_t fde_func_1158_0x0bbe3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bbe3cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x120e90ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1159 | PC: 0x0bbec0 | FDE: 0x120eb0 | Size: 36 bytes [_ZN11fast_engine8DescrObjD0Ev]
// Hàm FDE #1159 | Địa chỉ PC: 0x0bbec0 | Địa chỉ FDE: 0x120eb0 | Kích thước: 36 bytes
//   0x0bbec0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0bbec4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bbec8: 910043FD  add      x29, sp, #0x10
//   0x0bbecc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1159_0x0bbec0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bbec0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x120eb0ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1160 | PC: 0x0bbee4 | FDE: 0x120ed0 | Size: 36 bytes [_ZN11fast_engine15MappingProxyObjD0Ev]
// Hàm FDE #1160 | Địa chỉ PC: 0x0bbee4 | Địa chỉ FDE: 0x120ed0 | Kích thước: 36 bytes
//   0x0bbee4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0bbee8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bbeec: 910043FD  add      x29, sp, #0x10
//   0x0bbef0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1160_0x0bbee4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bbee4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x120ed0ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1161 | PC: 0x0bbf08 | FDE: 0x120ef0 | Size: 36 bytes [_ZN11fast_engine10WrapperObjD0Ev]
// Hàm FDE #1161 | Địa chỉ PC: 0x0bbf08 | Địa chỉ FDE: 0x120ef0 | Kích thước: 36 bytes
//   0x0bbf08: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0bbf0c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bbf10: 910043FD  add      x29, sp, #0x10
//   0x0bbf14: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1161_0x0bbf08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bbf08ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x120ef0ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1162 | PC: 0x0bbf2c | FDE: 0x120f10 | Size: 36 bytes [_ZN11fast_engine11PropertyObjD0Ev]
// Hàm FDE #1162 | Địa chỉ PC: 0x0bbf2c | Địa chỉ FDE: 0x120f10 | Kích thước: 36 bytes
//   0x0bbf2c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0bbf30: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bbf34: 910043FD  add      x29, sp, #0x10
//   0x0bbf38: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1162_0x0bbf2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bbf2cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x120f10ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1163 | PC: 0x0bbf50 | FDE: 0x120f30 | Size: 36 bytes [_ZN11fast_engine8SuperObjD0Ev]
// Hàm FDE #1163 | Địa chỉ PC: 0x0bbf50 | Địa chỉ FDE: 0x120f30 | Kích thước: 36 bytes
//   0x0bbf50: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0bbf54: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bbf58: 910043FD  add      x29, sp, #0x10
//   0x0bbf5c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1163_0x0bbf50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bbf50ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x120f30ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1164 | PC: 0x0bbf74 | FDE: 0x120f50 | Size: 36 bytes [_ZN11fast_engine19ClassMethodDescrObjD0Ev]
// Hàm FDE #1164 | Địa chỉ PC: 0x0bbf74 | Địa chỉ FDE: 0x120f50 | Kích thước: 36 bytes
//   0x0bbf74: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0bbf78: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bbf7c: 910043FD  add      x29, sp, #0x10
//   0x0bbf80: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1164_0x0bbf74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bbf74ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x120f50ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1165 | PC: 0x0bbf98 | FDE: 0x120f70 | Size: 36 bytes [_ZN11fast_engine14MethodDescrObjD0Ev]
// Hàm FDE #1165 | Địa chỉ PC: 0x0bbf98 | Địa chỉ FDE: 0x120f70 | Kích thước: 36 bytes
//   0x0bbf98: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0bbf9c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bbfa0: 910043FD  add      x29, sp, #0x10
//   0x0bbfa4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1165_0x0bbf98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bbf98ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x120f70ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1166 | PC: 0x0bbfbc | FDE: 0x120f90 | Size: 36 bytes [_ZN11fast_engine14MemberDescrObjD0Ev]
// Hàm FDE #1166 | Địa chỉ PC: 0x0bbfbc | Địa chỉ FDE: 0x120f90 | Kích thước: 36 bytes
//   0x0bbfbc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0bbfc0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bbfc4: 910043FD  add      x29, sp, #0x10
//   0x0bbfc8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1166_0x0bbfbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bbfbcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x120f90ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1167 | PC: 0x0bbfe0 | FDE: 0x120fb0 | Size: 36 bytes [_ZN11fast_engine14GetSetDescrObjD0Ev]
// Hàm FDE #1167 | Địa chỉ PC: 0x0bbfe0 | Địa chỉ FDE: 0x120fb0 | Kích thước: 36 bytes
//   0x0bbfe0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0bbfe4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bbfe8: 910043FD  add      x29, sp, #0x10
//   0x0bbfec: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1167_0x0bbfe0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bbfe0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x120fb0ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1168 | PC: 0x0bc004 | FDE: 0x120fd0 | Size: 36 bytes [_ZN11fast_engine15WrapperDescrObjD0Ev]
// Hàm FDE #1168 | Địa chỉ PC: 0x0bc004 | Địa chỉ FDE: 0x120fd0 | Kích thước: 36 bytes
//   0x0bc004: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0bc008: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bc00c: 910043FD  add      x29, sp, #0x10
//   0x0bc010: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1168_0x0bc004(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bc004ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x120fd0ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1169 | PC: 0x0bc028 | FDE: 0x121628 | Size: 144 bytes
// Hàm FDE #1169 | Địa chỉ PC: 0x0bc028 | Địa chỉ FDE: 0x121628 | Kích thước: 144 bytes
//   0x0bc028: D10103FF  sub      sp, sp, #0x40
//   0x0bc02c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0bc030: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0bc034: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1169_0x0bc028(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bc028ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x121628ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1170 | PC: 0x0bc0b8 | FDE: 0x121650 | Size: 256 bytes
// Hàm FDE #1170 | Địa chỉ PC: 0x0bc0b8 | Địa chỉ FDE: 0x121650 | Kích thước: 256 bytes
//   0x0bc0b8: D101C3FF  sub      sp, sp, #0x70
//   0x0bc0bc: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0bc0c0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0bc0c4: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1170_0x0bc0b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bc0b8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x121650ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1171 | PC: 0x0bc3b0 | FDE: 0x121680 | Size: 256 bytes
// Hàm FDE #1171 | Địa chỉ PC: 0x0bc3b0 | Địa chỉ FDE: 0x121680 | Kích thước: 256 bytes
//   0x0bc3b0: D10183FF  sub      sp, sp, #0x60
//   0x0bc3b4: F90013F7  str      x23, [sp, #0x20]
//   0x0bc3b8: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0bc3bc: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1171_0x0bc3b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bc3b0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x121680ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1172 | PC: 0x0bc524 | FDE: 0x120ff0 | Size: 8 bytes
// Hàm FDE #1172 | Địa chỉ PC: 0x0bc524 | Địa chỉ FDE: 0x120ff0 | Kích thước: 8 bytes
//   0x0bc524: F9402000  ldr      x0, [x0, #0x40]
//   0x0bc528: 17FFFEE4  b        #0xbc0b8
static inline uint64_t fde_func_1172_0x0bc524(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bc524ULL ^ (static_cast<uint64_t>(0xf9402000ULL) << 13);
    acc = (acc + a1 + 0x17fffee4ULL) ^ 0x120ff0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1173 | PC: 0x0bc52c | FDE: 0x1216b0 | Size: 20 bytes [_ZN11fast_engine19InitEmptySharedKeysEv]
// Hàm FDE #1173 | Địa chỉ PC: 0x0bc52c | Địa chỉ FDE: 0x1216b0 | Kích thước: 20 bytes
//   0x0bc52c: 90000429  adrp     x9, #0x140000
//   0x0bc530: D0000508  adrp     x8, #0x15e000
//   0x0bc534: 913D4129  add      x9, x9, #0xf50
//   0x0bc538: F9069109  str      x9, [x8, #0xd20]
static inline uint64_t fde_func_1173_0x0bc52c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bc52cULL ^ (static_cast<uint64_t>(0x90000429ULL) << 13);
    acc = (acc + a1 + 0xd0000508ULL) ^ 0x1216b0ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1174 | PC: 0x0bc540 | FDE: 0x1216c8 | Size: 224 bytes [_ZN11fast_engine20DictCheckConsistencyEPNS_7DictObjEi]
// Hàm FDE #1174 | Địa chỉ PC: 0x0bc540 | Địa chỉ FDE: 0x1216c8 | Kích thước: 224 bytes
//   0x0bc540: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0bc544: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0bc548: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0bc54c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1174_0x0bc540(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bc540ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1216c8ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #1175 | PC: 0x0bc620 | FDE: 0x1216e8 | Size: 76 bytes [_ZN11fast_engine7DictObj12_NewEmptyMapEPS0_PNS_6EngineE]
// Hàm FDE #1175 | Địa chỉ PC: 0x0bc620 | Địa chỉ FDE: 0x1216e8 | Kích thước: 76 bytes
//   0x0bc620: D0000508  adrp     x8, #0x15e000
//   0x0bc624: F9469108  ldr      x8, [x8, #0xd20]
//   0x0bc628: 1280000A  mov      w10, #-1
//   0x0bc62c: F9002808  str      x8, [x0, #0x50]
static inline uint64_t fde_func_1175_0x0bc620(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bc620ULL ^ (static_cast<uint64_t>(0xd0000508ULL) << 13);
    acc = (acc + a1 + 0xf9469108ULL) ^ 0x1216e8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1176 | PC: 0x0bc66c | FDE: 0x1225a8 | Size: 232 bytes [_ZN11fast_engine7DictObj8NewEmptyEPNS_6EngineE]
// Hàm FDE #1176 | Địa chỉ PC: 0x0bc66c | Địa chỉ FDE: 0x1225a8 | Kích thước: 232 bytes
//   0x0bc66c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0bc670: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0bc674: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0bc678: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1176_0x0bc66c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bc66cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1225a8ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1177 | PC: 0x0bc754 | FDE: 0x121700 | Size: 172 bytes [_ZN11fast_engine8DictKeys12StringLookupEPS0_PNS_3ObjEPNS_6EngineE]
// Hàm FDE #1177 | Địa chỉ PC: 0x0bc754 | Địa chỉ FDE: 0x121700 | Kích thước: 172 bytes
//   0x0bc754: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0bc758: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0bc75c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0bc760: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1177_0x0bc754(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bc754ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x121700ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1178 | PC: 0x0bc800 | FDE: 0x121728 | Size: 256 bytes
// Hàm FDE #1178 | Địa chỉ PC: 0x0bc800 | Địa chỉ FDE: 0x121728 | Kích thước: 256 bytes
//   0x0bc800: D101C3FF  sub      sp, sp, #0x70
//   0x0bc804: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x0bc808: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0bc80c: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1178_0x0bc800(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bc800ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x121728ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1179 | PC: 0x0bcaec | FDE: 0x121758 | Size: 148 bytes [_ZN11fast_engine8DictKeys17StringLookupSplitEPS0_PNS_3ObjEPNS_6EngineE]
// Hàm FDE #1179 | Địa chỉ PC: 0x0bcaec | Địa chỉ FDE: 0x121758 | Kích thước: 148 bytes
//   0x0bcaec: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0bcaf0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0bcaf4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0bcaf8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1179_0x0bcaec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bcaecULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x121758ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1180 | PC: 0x0bcb80 | FDE: 0x121778 | Size: 256 bytes [_ZN11fast_engine7DictObj7_LookupEPS0_PNS_3ObjElPS3_PNS_6EngineE]
// Hàm FDE #1180 | Địa chỉ PC: 0x0bcb80 | Địa chỉ FDE: 0x121778 | Kích thước: 256 bytes
//   0x0bcb80: D10243FF  sub      sp, sp, #0x90
//   0x0bcb84: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0bcb88: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0bcb8c: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1180_0x0bcb80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bcb80ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x121778ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1181 | PC: 0x0bd194 | FDE: 0x1217a8 | Size: 64 bytes [_ZN11fast_engine7DictObj10_LookupRefEPS0_PNS_3ObjElPS3_PNS_6EngineE]
// Hàm FDE #1181 | Địa chỉ PC: 0x0bd194 | Địa chỉ FDE: 0x1217a8 | Kích thước: 64 bytes
//   0x0bd194: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0bd198: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bd19c: 910043FD  add      x29, sp, #0x10
//   0x0bd1a0: AA0303F3  mov      x19, x3
static inline uint64_t fde_func_1181_0x0bd194(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bd194ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1217a8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1182 | PC: 0x0bd1d4 | FDE: 0x1217c8 | Size: 160 bytes [_ZN11fast_engine7DictObj18_HasOnlyStringKeysEPS0_PNS_6EngineE]
// Hàm FDE #1182 | Địa chỉ PC: 0x0bd1d4 | Địa chỉ FDE: 0x1217c8 | Kích thước: 160 bytes
//   0x0bd1d4: D10143FF  sub      sp, sp, #0x50
//   0x0bd1d8: F90013F5  str      x21, [sp, #0x20]
//   0x0bd1dc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0bd1e0: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1182_0x0bd1d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bd1d4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1217c8ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1183 | PC: 0x0bd274 | FDE: 0x1217e8 | Size: 8 bytes [_ZN11fast_engine7DictObj4NextEPS0_PlPPNS_3ObjES5_PNS_6EngineE]
// Hàm FDE #1183 | Địa chỉ PC: 0x0bd274 | Địa chỉ FDE: 0x1217e8 | Kích thước: 8 bytes
//   0x0bd274: AA1F03E4  mov      x4, xzr
//   0x0bd278: 17FE166E  b        #0x42c30
static inline uint64_t fde_func_1183_0x0bd274(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bd274ULL ^ (static_cast<uint64_t>(0xaa1f03e4ULL) << 13);
    acc = (acc + a1 + 0x17fe166eULL) ^ 0x1217e8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1184 | PC: 0x0bd27c | FDE: 0x1225d0 | Size: 256 bytes [_ZN11fast_engine7DictObj11NewPresizedElPNS_6EngineE]
// Hàm FDE #1184 | Địa chỉ PC: 0x0bd27c | Địa chỉ FDE: 0x1225d0 | Kích thước: 256 bytes
//   0x0bd27c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0bd280: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0bd284: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0bd288: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1184_0x0bd27c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bd27cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1225d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1185 | PC: 0x0bd3e4 | FDE: 0x1225f8 | Size: 256 bytes [_ZN11fast_engine7DictObj10_FromItemsEPPNS_3ObjElS3_llPNS_6EngineE]
// Hàm FDE #1185 | Địa chỉ PC: 0x0bd3e4 | Địa chỉ FDE: 0x1225f8 | Kích thước: 256 bytes
//   0x0bd3e4: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0bd3e8: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0bd3ec: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0bd3f0: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1185_0x0bd3e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bd3e4ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1225f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1186 | PC: 0x0bd664 | FDE: 0x121800 | Size: 96 bytes [_ZN11fast_engine7DictObj7SetItemEPS0_PNS_3ObjES3_PNS_6EngineE]
// Hàm FDE #1186 | Địa chỉ PC: 0x0bd664 | Địa chỉ FDE: 0x121800 | Kích thước: 96 bytes
//   0x0bd664: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0bd668: 910003FD  mov      x29, sp
//   0x0bd66c: F9401408  ldr      x8, [x0, #0x28]
//   0x0bd670: 3942AD08  ldrb     w8, [x8, #0xab]
static inline uint64_t fde_func_1186_0x0bd664(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bd664ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x121800ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1187 | PC: 0x0bd6c4 | FDE: 0x121820 | Size: 180 bytes [_ZN11fast_engine7DictObj7GetItemEPS0_PNS_3ObjEPNS_6EngineE]
// Hàm FDE #1187 | Địa chỉ PC: 0x0bd6c4 | Địa chỉ FDE: 0x121820 | Kích thước: 180 bytes
//   0x0bd6c4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0bd6c8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0bd6cc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0bd6d0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1187_0x0bd6c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bd6c4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x121820ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1188 | PC: 0x0bd778 | FDE: 0x121840 | Size: 196 bytes [_ZN11fast_engine7DictObj9GetItemIdEPS0_PNS_10IdentifierEPNS_6EngineE]
// Hàm FDE #1188 | Địa chỉ PC: 0x0bd778 | Địa chỉ FDE: 0x121840 | Kích thước: 196 bytes
//   0x0bd778: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0bd77c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0bd780: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0bd784: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1188_0x0bd778(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bd778ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x121840ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1189 | PC: 0x0bd83c | FDE: 0x121860 | Size: 112 bytes [_ZN11fast_engine7DictObj12_LookupIndexEPS0_PNS_3ObjEPNS_6EngineE]
// Hàm FDE #1189 | Địa chỉ PC: 0x0bd83c | Địa chỉ FDE: 0x121860 | Kích thước: 112 bytes
//   0x0bd83c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0bd840: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0bd844: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0bd848: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1189_0x0bd83c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bd83cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x121860ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1190 | PC: 0x0bd8ac | FDE: 0x121880 | Size: 40 bytes [_ZN11fast_engine7DictObj17_GetItemKnownHashEPS0_PNS_3ObjElPNS_6EngineE]
// Hàm FDE #1190 | Địa chỉ PC: 0x0bd8ac | Địa chỉ FDE: 0x121880 | Kích thước: 40 bytes
//   0x0bd8ac: D10083FF  sub      sp, sp, #0x20
//   0x0bd8b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bd8b4: 910043FD  add      x29, sp, #0x10
//   0x0bd8b8: AA0303E4  mov      x4, x3
static inline uint64_t fde_func_1190_0x0bd8ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bd8acULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x121880ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1191 | PC: 0x0bd8d4 | FDE: 0x1218a0 | Size: 104 bytes [_ZN11fast_engine7DictObj20_GetItemRefKnownHashEPS0_PNS_3ObjElPS3_PNS_6EngineE]
// Hàm FDE #1191 | Địa chỉ PC: 0x0bd8d4 | Địa chỉ FDE: 0x1218a0 | Kích thước: 104 bytes
//   0x0bd8d4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0bd8d8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bd8dc: 910043FD  add      x29, sp, #0x10
//   0x0bd8e0: AA0303F3  mov      x19, x3
static inline uint64_t fde_func_1191_0x0bd8d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bd8d4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1218a0ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1192 | PC: 0x0bd93c | FDE: 0x1218c0 | Size: 212 bytes [_ZN11fast_engine7DictObj10GetItemRefEPS0_PNS_3ObjEPS3_PNS_6EngineE]
// Hàm FDE #1192 | Địa chỉ PC: 0x0bd93c | Địa chỉ FDE: 0x1218c0 | Kích thước: 212 bytes
//   0x0bd93c: D10103FF  sub      sp, sp, #0x40
//   0x0bd940: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0bd944: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0bd948: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1192_0x0bd93c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bd93cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1218c0ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1193 | PC: 0x0bda10 | FDE: 0x1218e8 | Size: 144 bytes [_ZN11fast_engine7DictObj16GetItemWithErrorEPS0_PNS_3ObjEPNS_6EngineE]
// Hàm FDE #1193 | Địa chỉ PC: 0x0bda10 | Địa chỉ FDE: 0x1218e8 | Kích thước: 144 bytes
//   0x0bda10: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0bda14: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0bda18: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0bda1c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1193_0x0bda10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bda10ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1218e8ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1194 | PC: 0x0bdaa0 | FDE: 0x121908 | Size: 252 bytes [_ZN11fast_engine7DictObj13GetItemStringEPS0_RKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEPNS_6EngineE]
// Hàm FDE #1194 | Địa chỉ PC: 0x0bdaa0 | Địa chỉ FDE: 0x121908 | Kích thước: 252 bytes
//   0x0bdaa0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0bdaa4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0bdaa8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0bdaac: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1194_0x0bdaa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bdaa0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x121908ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1195 | PC: 0x0bdb9c | FDE: 0x121928 | Size: 96 bytes [_ZN11fast_engine7DictObj19_GetItemIdWithErrorEPS0_PNS_10IdentifierEPNS_6EngineE]
// Hàm FDE #1195 | Địa chỉ PC: 0x0bdb9c | Địa chỉ FDE: 0x121928 | Kích thước: 96 bytes
//   0x0bdb9c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0bdba0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0bdba4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0bdba8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1195_0x0bdb9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bdb9cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x121928ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1196 | PC: 0x0bdbfc | FDE: 0x121948 | Size: 216 bytes [_ZN11fast_engine7DictObj23_GetItemStringWithErrorEPS0_RKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEPNS_6EngineE]
// Hàm FDE #1196 | Địa chỉ PC: 0x0bdbfc | Địa chỉ FDE: 0x121948 | Kích thước: 216 bytes
//   0x0bdbfc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0bdc00: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0bdc04: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0bdc08: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1196_0x0bdbfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bdbfcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x121948ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1197 | PC: 0x0bdcd4 | FDE: 0x121968 | Size: 256 bytes [_ZN11fast_engine7DictObj12_GetItemHintEPS0_PNS_3ObjElPS3_PNS_6EngineE]
// Hàm FDE #1197 | Địa chỉ PC: 0x0bdcd4 | Địa chỉ FDE: 0x121968 | Kích thước: 256 bytes
//   0x0bdcd4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0bdcd8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0bdcdc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0bdce0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1197_0x0bdcd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bdcd4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x121968ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1198 | PC: 0x0bde0c | FDE: 0x121990 | Size: 212 bytes [_ZN11fast_engine7DictObj14_GetItemRefStrEPS0_PNS_6StrObjEPPNS_3ObjEPNS_6EngineE]
// Hàm FDE #1198 | Địa chỉ PC: 0x0bde0c | Địa chỉ FDE: 0x121990 | Kích thước: 212 bytes
//   0x0bde0c: D10103FF  sub      sp, sp, #0x40
//   0x0bde10: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0bde14: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0bde18: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1198_0x0bde0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bde0cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x121990ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1199 | PC: 0x0bdee0 | FDE: 0x1219b8 | Size: 256 bytes [_ZN11fast_engine7DictObj11_LoadGlobalEPS0_S1_PNS_3ObjEPNS_6EngineE]
// Hàm FDE #1199 | Địa chỉ PC: 0x0bdee0 | Địa chỉ FDE: 0x1219b8 | Kích thước: 256 bytes
//   0x0bdee0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0bdee4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0bdee8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0bdeec: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1199_0x0bdee0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bdee0ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1219b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1200 | PC: 0x0bdfe8 | FDE: 0x1219e0 | Size: 256 bytes [_ZN11fast_engine7DictObj14_SetItem_Take2EPS0_PNS_3ObjES3_PNS_6EngineE]
// Hàm FDE #1200 | Địa chỉ PC: 0x0bdfe8 | Địa chỉ FDE: 0x1219e0 | Kích thước: 256 bytes
//   0x0bdfe8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0bdfec: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0bdff0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0bdff4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1200_0x0bdfe8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bdfe8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1219e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1201 | PC: 0x0bf0f4 | FDE: 0x121a08 | Size: 76 bytes [_ZN11fast_engine7DictObj17_SetItemKnownHashEPS0_PNS_3ObjElS3_PNS_6EngineE]
// Hàm FDE #1201 | Địa chỉ PC: 0x0bf0f4 | Địa chỉ FDE: 0x121a08 | Kích thước: 76 bytes
//   0x0bf0f4: B940202A  ldr      w10, [x1, #0x20]
//   0x0bf0f8: F00004E9  adrp     x9, #0x15e000
//   0x0bf0fc: F9402808  ldr      x8, [x0, #0x50]
//   0x0bf100: F9469129  ldr      x9, [x9, #0xd20]
static inline uint64_t fde_func_1201_0x0bf0f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bf0f4ULL ^ (static_cast<uint64_t>(0xb940202aULL) << 13);
    acc = (acc + a1 + 0xf00004e9ULL) ^ 0x121a08ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1202 | PC: 0x0bf140 | FDE: 0x121a20 | Size: 256 bytes
// Hàm FDE #1202 | Địa chỉ PC: 0x0bf140 | Địa chỉ FDE: 0x121a20 | Kích thước: 256 bytes
//   0x0bf140: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0bf144: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0bf148: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0bf14c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1202_0x0bf140(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bf140ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x121a20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1203 | PC: 0x0bf2d0 | FDE: 0x121a48 | Size: 256 bytes
// Hàm FDE #1203 | Địa chỉ PC: 0x0bf2d0 | Địa chỉ FDE: 0x121a48 | Kích thước: 256 bytes
//   0x0bf2d0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0bf2d4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0bf2d8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0bf2dc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1203_0x0bf2d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bf2d0ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x121a48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1204 | PC: 0x0bf630 | FDE: 0x121a70 | Size: 140 bytes [_ZN11fast_engine7DictObj13SetItemStringEPS0_RKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEPNS_3ObjEPNS_6EngineE]
// Hàm FDE #1204 | Địa chỉ PC: 0x0bf630 | Địa chỉ FDE: 0x121a70 | Kích thước: 140 bytes
//   0x0bf630: D10103FF  sub      sp, sp, #0x40
//   0x0bf634: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0bf638: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0bf63c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1204_0x0bf630(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bf630ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x121a70ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1205 | PC: 0x0bf6bc | FDE: 0x121a98 | Size: 256 bytes [_ZN11fast_engine7DictObj16SetItemStringRefEPS0_RKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEPNS_3ObjEPNS_6EngineE]
// Hàm FDE #1205 | Địa chỉ PC: 0x0bf6bc | Địa chỉ FDE: 0x121a98 | Kích thước: 256 bytes
//   0x0bf6bc: D10103FF  sub      sp, sp, #0x40
//   0x0bf6c0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0bf6c4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0bf6c8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1205_0x0bf6bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bf6bcULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x121a98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1206 | PC: 0x0bf7cc | FDE: 0x121ac0 | Size: 152 bytes [_ZN11fast_engine7DictObj13SetItemStringEPS0_RKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEESA_PNS_6EngineE]
// Hàm FDE #1206 | Địa chỉ PC: 0x0bf7cc | Địa chỉ FDE: 0x121ac0 | Kích thước: 152 bytes
//   0x0bf7cc: D10103FF  sub      sp, sp, #0x40
//   0x0bf7d0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0bf7d4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0bf7d8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1206_0x0bf7cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bf7ccULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x121ac0ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1207 | PC: 0x0bf864 | FDE: 0x121ae8 | Size: 164 bytes [_ZN11fast_engine7DictObj9SetItemIdEPS0_PNS_10IdentifierEPNS_3ObjEPNS_6EngineE]
// Hàm FDE #1207 | Địa chỉ PC: 0x0bf864 | Địa chỉ FDE: 0x121ae8 | Kích thước: 164 bytes
//   0x0bf864: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0bf868: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0bf86c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0bf870: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1207_0x0bf864(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bf864ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x121ae8ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1208 | PC: 0x0bf908 | FDE: 0x121b08 | Size: 132 bytes [_ZN11fast_engine7DictObj9SetItemIdEPS0_PNS_10IdentifierERKNSt6__ndk112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEEPNS_6EngineE]
// Hàm FDE #1208 | Địa chỉ PC: 0x0bf908 | Địa chỉ FDE: 0x121b08 | Kích thước: 132 bytes
//   0x0bf908: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0bf90c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0bf910: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0bf914: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1208_0x0bf908(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bf908ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x121b08ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1209 | PC: 0x0bf98c | FDE: 0x121b30 | Size: 228 bytes [_ZN11fast_engine7DictObj7DelItemEPS0_PNS_3ObjEPNS_6EngineE]
// Hàm FDE #1209 | Địa chỉ PC: 0x0bf98c | Địa chỉ FDE: 0x121b30 | Kích thước: 228 bytes
//   0x0bf98c: D10103FF  sub      sp, sp, #0x40
//   0x0bf990: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0bf994: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0bf998: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1209_0x0bf98c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bf98cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x121b30ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #1210 | PC: 0x0bfa70 | FDE: 0x121b58 | Size: 156 bytes [_ZN11fast_engine7DictObj16DelItemKnownHashEPS0_PNS_3ObjElPNS_6EngineE]
// Hàm FDE #1210 | Địa chỉ PC: 0x0bfa70 | Địa chỉ FDE: 0x121b58 | Kích thước: 156 bytes
//   0x0bfa70: D10103FF  sub      sp, sp, #0x40
//   0x0bfa74: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0bfa78: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0bfa7c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1210_0x0bfa70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bfa70ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x121b58ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1211 | PC: 0x0bfb0c | FDE: 0x121b80 | Size: 136 bytes [_ZN11fast_engine7DictObj13DelItemStringEPS0_RKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEPNS_6EngineE]
// Hàm FDE #1211 | Địa chỉ PC: 0x0bfb0c | Địa chỉ FDE: 0x121b80 | Kích thước: 136 bytes
//   0x0bfb0c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0bfb10: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0bfb14: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0bfb18: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1211_0x0bfb0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bfb0cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x121b80ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1212 | PC: 0x0bfb94 | FDE: 0x121ba0 | Size: 72 bytes [_ZN11fast_engine7DictObj9DelItemIdEPS0_PNS_10IdentifierEPNS_6EngineE]
// Hàm FDE #1212 | Địa chỉ PC: 0x0bfb94 | Địa chỉ FDE: 0x121ba0 | Kích thước: 72 bytes
//   0x0bfb94: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0bfb98: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bfb9c: 910043FD  add      x29, sp, #0x10
//   0x0bfba0: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1212_0x0bfb94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bfb94ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x121ba0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1213 | PC: 0x0bfbdc | FDE: 0x121bc0 | Size: 4 bytes [_ZN11fast_engine7DictObj12ClearContentEPS0_PNS_6EngineE]
// Hàm FDE #1213 | Địa chỉ PC: 0x0bfbdc | Địa chỉ FDE: 0x121bc0 | Kích thước: 4 bytes
//   0x0bfbdc: 14000001  b        #0xbfbe0
static inline uint64_t fde_func_1213_0x0bfbdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bfbdcULL ^ (static_cast<uint64_t>(0x14000001ULL) << 13);
    acc = (acc + a1 + 0xf81b0ff9ULL) ^ 0x121bc0ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1214 | PC: 0x0bfbe0 | FDE: 0x121bd8 | Size: 256 bytes
// Hàm FDE #1214 | Địa chỉ PC: 0x0bfbe0 | Địa chỉ FDE: 0x121bd8 | Kích thước: 256 bytes
//   0x0bfbe0: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0bfbe4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0bfbe8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0bfbec: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1214_0x0bfbe0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bfbe0ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x121bd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1215 | PC: 0x0bfcf8 | FDE: 0x121c00 | Size: 256 bytes [_ZN11fast_engine7DictObj5_NextEPS0_PlPPNS_3ObjES5_S2_PNS_6EngineE]
// Hàm FDE #1215 | Địa chỉ PC: 0x0bfcf8 | Địa chỉ FDE: 0x121c00 | Kích thước: 256 bytes
//   0x0bfcf8: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0bfcfc: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0bfd00: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0bfd04: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1215_0x0bfcf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bfcf8ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x121c00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1216 | PC: 0x0bfe58 | FDE: 0x121c28 | Size: 256 bytes [_ZN11fast_engine7DictObj13_PopKnownHashEPS0_PNS_3ObjElPS3_PNS_6EngineE]
// Hàm FDE #1216 | Địa chỉ PC: 0x0bfe58 | Địa chỉ FDE: 0x121c28 | Kích thước: 256 bytes
//   0x0bfe58: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0bfe5c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0bfe60: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0bfe64: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1216_0x0bfe58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bfe58ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x121c28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1217 | PC: 0x0bff68 | FDE: 0x121c50 | Size: 256 bytes
// Hàm FDE #1217 | Địa chỉ PC: 0x0bff68 | Địa chỉ FDE: 0x121c50 | Kích thước: 256 bytes
//   0x0bff68: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0bff6c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bff70: 910043FD  add      x29, sp, #0x10
//   0x0bff74: F9402808  ldr      x8, [x0, #0x50]
static inline uint64_t fde_func_1217_0x0bff68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bff68ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x121c50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1218 | PC: 0x0c01dc | FDE: 0x121c70 | Size: 176 bytes [_ZN11fast_engine7DictObj3PopEPS0_PNS_3ObjEPS3_PNS_6EngineE]
// Hàm FDE #1218 | Địa chỉ PC: 0x0c01dc | Địa chỉ FDE: 0x121c70 | Kích thước: 176 bytes
//   0x0c01dc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0c01e0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c01e4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c01e8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1218_0x0c01dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c01dcULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x121c70ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #1219 | PC: 0x0c028c | FDE: 0x121c98 | Size: 256 bytes [_ZN11fast_engine7DictObj4_PopEPS0_PNS_3ObjES3_PNS_6EngineE]
// Hàm FDE #1219 | Địa chỉ PC: 0x0c028c | Địa chỉ FDE: 0x121c98 | Kích thước: 256 bytes
//   0x0c028c: D10143FF  sub      sp, sp, #0x50
//   0x0c0290: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0c0294: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0c0298: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1219_0x0c028c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c028cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x121c98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1220 | PC: 0x0c03d4 | FDE: 0x122630 | Size: 256 bytes [_ZN11fast_engine7DictObj4KeysEPS0_PNS_6EngineE]
// Hàm FDE #1220 | Địa chỉ PC: 0x0c03d4 | Địa chỉ FDE: 0x122630 | Kích thước: 256 bytes
//   0x0c03d4: D10183FF  sub      sp, sp, #0x60
//   0x0c03d8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0c03dc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0c03e0: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1220_0x0c03d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c03d4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x122630ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1221 | PC: 0x0c055c | FDE: 0x121cc0 | Size: 256 bytes [_ZN11fast_engine7DictObj13MergeFromSeq2EPS0_PNS_3ObjEbPNS_6EngineE]
// Hàm FDE #1221 | Địa chỉ PC: 0x0c055c | Địa chỉ FDE: 0x121cc0 | Kích thước: 256 bytes
//   0x0c055c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0c0560: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0c0564: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0c0568: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1221_0x0c055c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c055cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x121cc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1222 | PC: 0x0c0908 | FDE: 0x121cf0 | Size: 256 bytes
// Hàm FDE #1222 | Địa chỉ PC: 0x0c0908 | Địa chỉ FDE: 0x121cf0 | Kích thước: 256 bytes
//   0x0c0908: D10183FF  sub      sp, sp, #0x60
//   0x0c090c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0c0910: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0c0914: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1222_0x0c0908(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c0908ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x121cf0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1223 | PC: 0x0c0cbc | FDE: 0x121d20 | Size: 12 bytes [_ZN11fast_engine7DictObj6UpdateEPS0_PNS_3ObjEPNS_6EngineE]
// Hàm FDE #1223 | Địa chỉ PC: 0x0c0cbc | Địa chỉ FDE: 0x121d20 | Kích thước: 12 bytes
//   0x0c0cbc: AA0203E3  mov      x3, x2
//   0x0c0cc0: 52800022  mov      w2, #1
//   0x0c0cc4: 14000001  b        #0xc0cc8
static inline uint64_t fde_func_1223_0x0c0cbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c0cbcULL ^ (static_cast<uint64_t>(0xaa0203e3ULL) << 13);
    acc = (acc + a1 + 0x52800022ULL) ^ 0x121d20ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1224 | PC: 0x0c0cc8 | FDE: 0x121d38 | Size: 256 bytes
// Hàm FDE #1224 | Địa chỉ PC: 0x0c0cc8 | Địa chỉ FDE: 0x121d38 | Kích thước: 256 bytes
//   0x0c0cc8: D10243FF  sub      sp, sp, #0x90
//   0x0c0ccc: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0c0cd0: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0c0cd4: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1224_0x0c0cc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c0cc8ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x121d38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1225 | PC: 0x0c1368 | FDE: 0x121d68 | Size: 8 bytes [_ZN11fast_engine7DictObj5MergeEPS0_PNS_3ObjEbPNS_6EngineE]
// Hàm FDE #1225 | Địa chỉ PC: 0x0c1368 | Địa chỉ FDE: 0x121d68 | Kích thước: 8 bytes
//   0x0c1368: 12000042  and      w2, w2, #1
//   0x0c136c: 17FFFE57  b        #0xc0cc8
static inline uint64_t fde_func_1225_0x0c1368(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c1368ULL ^ (static_cast<uint64_t>(0x12000042ULL) << 13);
    acc = (acc + a1 + 0x17fffe57ULL) ^ 0x121d68ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1226 | PC: 0x0c1370 | FDE: 0x122660 | Size: 256 bytes [_ZN11fast_engine7DictObj4CopyEPS0_PNS_6EngineE]
// Hàm FDE #1226 | Địa chỉ PC: 0x0c1370 | Địa chỉ FDE: 0x122660 | Kích thước: 256 bytes
//   0x0c1370: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0c1374: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0c1378: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0c137c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1226_0x0c1370(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c1370ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x122660ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1227 | PC: 0x0c1714 | FDE: 0x121d80 | Size: 56 bytes [_ZN11fast_engine7DictObj4SizeEPS0_PNS_6EngineE]
// Hàm FDE #1227 | Địa chỉ PC: 0x0c1714 | Địa chỉ FDE: 0x121d80 | Kích thước: 56 bytes
//   0x0c1714: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0c1718: 910003FD  mov      x29, sp
//   0x0c171c: B4000080  cbz      x0, #0xc172c
//   0x0c1720: F9401408  ldr      x8, [x0, #0x28]
static inline uint64_t fde_func_1227_0x0c1714(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c1714ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x121d80ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1228 | PC: 0x0c174c | FDE: 0x121da0 | Size: 12 bytes [_ZN11fast_engine7DictObj13SetDefaultRefEPS0_PNS_3ObjES3_PS3_PNS_6EngineE]
// Hàm FDE #1228 | Địa chỉ PC: 0x0c174c | Địa chỉ FDE: 0x121da0 | Kích thước: 12 bytes
//   0x0c174c: AA0403E5  mov      x5, x4
//   0x0c1750: 52800024  mov      w4, #1
//   0x0c1754: 17FFFC6D  b        #0xc0908
static inline uint64_t fde_func_1228_0x0c174c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c174cULL ^ (static_cast<uint64_t>(0xaa0403e5ULL) << 13);
    acc = (acc + a1 + 0x52800024ULL) ^ 0x121da0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1229 | PC: 0x0c1758 | FDE: 0x121db8 | Size: 88 bytes [_ZN11fast_engine7DictObj10SetDefaultEPS0_PNS_3ObjES3_PNS_6EngineE]
// Hàm FDE #1229 | Địa chỉ PC: 0x0c1758 | Địa chỉ FDE: 0x121db8 | Kích thước: 88 bytes
//   0x0c1758: D100C3FF  sub      sp, sp, #0x30
//   0x0c175c: F9000BF3  str      x19, [sp, #0x10]
//   0x0c1760: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c1764: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1229_0x0c1758(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c1758ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x121db8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1230 | PC: 0x0c17b0 | FDE: 0x121dd8 | Size: 72 bytes [_ZN11fast_engine7DictObj9_KeysSizeEPNS_8DictKeysE]
// Hàm FDE #1230 | Địa chỉ PC: 0x0c17b0 | Địa chỉ FDE: 0x121dd8 | Kích thước: 72 bytes
//   0x0c17b0: B9400C08  ldr      w8, [x0, #0xc]
//   0x0c17b4: 3940240A  ldrb     w10, [x0, #9]
//   0x0c17b8: 3940200B  ldrb     w11, [x0, #8]
//   0x0c17bc: 52800209  mov      w9, #0x10
static inline uint64_t fde_func_1230_0x0c17b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c17b0ULL ^ (static_cast<uint64_t>(0xb9400c08ULL) << 13);
    acc = (acc + a1 + 0x3940240aULL) ^ 0x121dd8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1231 | PC: 0x0c17f8 | FDE: 0x121df0 | Size: 156 bytes [_ZN11fast_engine7DictObj8ContainsEPS0_PNS_3ObjEPNS_6EngineE]
// Hàm FDE #1231 | Địa chỉ PC: 0x0c17f8 | Địa chỉ FDE: 0x121df0 | Kích thước: 156 bytes
//   0x0c17f8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0c17fc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c1800: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c1804: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1231_0x0c17f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c17f8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x121df0ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1232 | PC: 0x0c1894 | FDE: 0x121e10 | Size: 76 bytes [_ZN11fast_engine7DictObj18_ContainsKnownHashEPS0_PNS_3ObjElPNS_6EngineE]
// Hàm FDE #1232 | Địa chỉ PC: 0x0c1894 | Địa chỉ FDE: 0x121e10 | Kích thước: 76 bytes
//   0x0c1894: D10083FF  sub      sp, sp, #0x20
//   0x0c1898: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c189c: 910043FD  add      x29, sp, #0x10
//   0x0c18a0: AA0303E4  mov      x4, x3
static inline uint64_t fde_func_1232_0x0c1894(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c1894ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x121e10ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1233 | PC: 0x0c18e0 | FDE: 0x122690 | Size: 256 bytes [_ZN11fast_engine7DictObj14ContainsStringEPS0_PKcPNS_6EngineE]
// Hàm FDE #1233 | Địa chỉ PC: 0x0c18e0 | Địa chỉ FDE: 0x122690 | Kích thước: 256 bytes
//   0x0c18e0: D10143FF  sub      sp, sp, #0x50
//   0x0c18e4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0c18e8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0c18ec: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1233_0x0c18e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c18e0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x122690ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1234 | PC: 0x0c1a24 | FDE: 0x121e30 | Size: 172 bytes [_ZN11fast_engine7DictObj10ContainsIdEPS0_PNS_10IdentifierEPNS_6EngineE]
// Hàm FDE #1234 | Địa chỉ PC: 0x0c1a24 | Địa chỉ FDE: 0x121e30 | Kích thước: 172 bytes
//   0x0c1a24: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0c1a28: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c1a2c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c1a30: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1234_0x0c1a24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c1a24ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x121e30ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1235 | PC: 0x0c1ad0 | FDE: 0x121e50 | Size: 104 bytes [_ZN11fast_engine7DictObjC1EPNS_6EngineEPNS_7TypeObjENS_12ObjCacheTypeEl]
// Hàm FDE #1235 | Địa chỉ PC: 0x0c1ad0 | Địa chỉ FDE: 0x121e50 | Kích thước: 104 bytes
//   0x0c1ad0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0c1ad4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c1ad8: 910043FD  add      x29, sp, #0x10
//   0x0c1adc: 2A0303E8  mov      w8, w3
static inline uint64_t fde_func_1235_0x0c1ad0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c1ad0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x121e50ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1236 | PC: 0x0c1b38 | FDE: 0x121e70 | Size: 196 bytes [_ZN11fast_engine7DictObj5ClearEPNS_6EngineE]
// Hàm FDE #1236 | Địa chỉ PC: 0x0c1b38 | Địa chỉ FDE: 0x121e70 | Kích thước: 196 bytes
//   0x0c1b38: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0c1b3c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0c1b40: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0c1b44: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1236_0x0c1b38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c1b38ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x121e70ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1237 | PC: 0x0c1bfc | FDE: 0x1226c0 | Size: 96 bytes [_ZN11fast_engine13AllocDictTypeEPNS_6EngineE]
// Hàm FDE #1237 | Địa chỉ PC: 0x0c1bfc | Địa chỉ FDE: 0x1226c0 | Kích thước: 96 bytes
//   0x0c1bfc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c1c00: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c1c04: 910043FD  add      x29, sp, #0x10
//   0x0c1c08: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1237_0x0c1bfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c1bfcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1226c0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1238 | PC: 0x0c1c5c | FDE: 0x1226e8 | Size: 256 bytes [_ZN11fast_engine12InitDictTypeEPNS_6EngineE]
// Hàm FDE #1238 | Địa chỉ PC: 0x0c1c5c | Địa chỉ FDE: 0x1226e8 | Kích thước: 256 bytes
//   0x0c1c5c: D10203FF  sub      sp, sp, #0x80
//   0x0c1c60: FD0023E8  str      d8, [sp, #0x40]
//   0x0c1c64: F90027F7  str      x23, [sp, #0x48]
//   0x0c1c68: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1238_0x0c1c5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c1c5cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xfd0023e8ULL) ^ 0x1226e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1239 | PC: 0x0c2054 | FDE: 0x121e98 | Size: 8 bytes
// Hàm FDE #1239 | Địa chỉ PC: 0x0c2054 | Địa chỉ FDE: 0x121e98 | Kích thước: 8 bytes
//   0x0c2054: F9402000  ldr      x0, [x0, #0x40]
//   0x0c2058: D65F03C0  ret      
static inline uint64_t fde_func_1239_0x0c2054(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2054ULL ^ (static_cast<uint64_t>(0xf9402000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x121e98ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1240 | PC: 0x0c205c | FDE: 0x121eb0 | Size: 200 bytes
// Hàm FDE #1240 | Địa chỉ PC: 0x0c205c | Địa chỉ FDE: 0x121eb0 | Kích thước: 200 bytes
//   0x0c205c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0c2060: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c2064: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c2068: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1240_0x0c205c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c205cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x121eb0ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1241 | PC: 0x0c2124 | FDE: 0x121ed0 | Size: 112 bytes
// Hàm FDE #1241 | Địa chỉ PC: 0x0c2124 | Địa chỉ FDE: 0x121ed0 | Kích thước: 112 bytes
//   0x0c2124: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0c2128: 910003FD  mov      x29, sp
//   0x0c212c: B4000122  cbz      x2, #0xc2150
//   0x0c2130: F9401408  ldr      x8, [x0, #0x28]
static inline uint64_t fde_func_1241_0x0c2124(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2124ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x121ed0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1242 | PC: 0x0c2194 | FDE: 0x121ef0 | Size: 168 bytes
// Hàm FDE #1242 | Địa chỉ PC: 0x0c2194 | Địa chỉ FDE: 0x121ef0 | Kích thước: 168 bytes
//   0x0c2194: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0c2198: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c219c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c21a0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1242_0x0c2194(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2194ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x121ef0ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1243 | PC: 0x0c223c | FDE: 0x121f10 | Size: 72 bytes
// Hàm FDE #1243 | Địa chỉ PC: 0x0c223c | Địa chỉ FDE: 0x121f10 | Kích thước: 72 bytes
//   0x0c223c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0c2240: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c2244: 910043FD  add      x29, sp, #0x10
//   0x0c2248: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1243_0x0c223c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c223cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x121f10ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1244 | PC: 0x0c2284 | FDE: 0x121f30 | Size: 256 bytes
// Hàm FDE #1244 | Địa chỉ PC: 0x0c2284 | Địa chỉ FDE: 0x121f30 | Kích thước: 256 bytes
//   0x0c2284: D10143FF  sub      sp, sp, #0x50
//   0x0c2288: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0c228c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0c2290: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1244_0x0c2284(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2284ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x121f30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1245 | PC: 0x0c23b8 | FDE: 0x121f58 | Size: 256 bytes
// Hàm FDE #1245 | Địa chỉ PC: 0x0c23b8 | Địa chỉ FDE: 0x121f58 | Kích thước: 256 bytes
//   0x0c23b8: D10143FF  sub      sp, sp, #0x50
//   0x0c23bc: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0c23c0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0c23c4: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1245_0x0c23b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c23b8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x121f58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1246 | PC: 0x0c2548 | FDE: 0x121f80 | Size: 204 bytes
// Hàm FDE #1246 | Địa chỉ PC: 0x0c2548 | Địa chỉ FDE: 0x121f80 | Kích thước: 204 bytes
//   0x0c2548: D10143FF  sub      sp, sp, #0x50
//   0x0c254c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0c2550: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0c2554: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1246_0x0c2548(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2548ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x121f80ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1247 | PC: 0x0c2614 | FDE: 0x121fa8 | Size: 224 bytes
// Hàm FDE #1247 | Địa chỉ PC: 0x0c2614 | Địa chỉ FDE: 0x121fa8 | Kích thước: 224 bytes
//   0x0c2614: D10103FF  sub      sp, sp, #0x40
//   0x0c2618: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0c261c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0c2620: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1247_0x0c2614(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2614ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x121fa8ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #1248 | PC: 0x0c26f4 | FDE: 0x121fd0 | Size: 44 bytes
// Hàm FDE #1248 | Địa chỉ PC: 0x0c26f4 | Địa chỉ FDE: 0x121fd0 | Kích thước: 44 bytes
//   0x0c26f4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0c26f8: 910003FD  mov      x29, sp
//   0x0c26fc: AA0003E8  mov      x8, x0
//   0x0c2700: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_1248_0x0c26f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c26f4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x121fd0ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1249 | PC: 0x0c2720 | FDE: 0x121ff0 | Size: 16 bytes
// Hàm FDE #1249 | Địa chỉ PC: 0x0c2720 | Địa chỉ FDE: 0x121ff0 | Kích thước: 16 bytes
//   0x0c2720: AA0003E8  mov      x8, x0
//   0x0c2724: AA0103E0  mov      x0, x1
//   0x0c2728: AA0803E1  mov      x1, x8
//   0x0c272c: 17FE0731  b        #0x443f0
static inline uint64_t fde_func_1249_0x0c2720(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2720ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xaa0103e0ULL) ^ 0x121ff0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1250 | PC: 0x0c2730 | FDE: 0x122718 | Size: 148 bytes
// Hàm FDE #1250 | Địa chỉ PC: 0x0c2730 | Địa chỉ FDE: 0x122718 | Kích thước: 148 bytes
//   0x0c2730: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0c2734: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c2738: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c273c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1250_0x0c2730(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2730ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x122718ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// Shard 3 Dispatcher / Bộ điều phối phân mảnh 3
uint64_t execute_fde_shard_3(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 834: return fde_func_0834_0x0a4640(a0, a1);
        case 835: return fde_func_0835_0x0a468c(a0, a1);
        case 836: return fde_func_0836_0x0a475c(a0, a1);
        case 837: return fde_func_0837_0x0a47b8(a0, a1);
        case 838: return fde_func_0838_0x0a4810(a0, a1);
        case 839: return fde_func_0839_0x0a4888(a0, a1);
        case 840: return fde_func_0840_0x0a48e4(a0, a1);
        case 841: return fde_func_0841_0x0a493c(a0, a1);
        case 842: return fde_func_0842_0x0a4984(a0, a1);
        case 843: return fde_func_0843_0x0a49c8(a0, a1);
        case 844: return fde_func_0844_0x0a4a10(a0, a1);
        case 845: return fde_func_0845_0x0a4a6c(a0, a1);
        case 846: return fde_func_0846_0x0a4ac4(a0, a1);
        case 847: return fde_func_0847_0x0a4bcc(a0, a1);
        case 848: return fde_func_0848_0x0a4c28(a0, a1);
        case 849: return fde_func_0849_0x0a4c80(a0, a1);
        case 850: return fde_func_0850_0x0a4d18(a0, a1);
        case 851: return fde_func_0851_0x0a4d5c(a0, a1);
        case 852: return fde_func_0852_0x0a4e20(a0, a1);
        case 853: return fde_func_0853_0x0a4fd4(a0, a1);
        case 854: return fde_func_0854_0x0a5238(a0, a1);
        case 855: return fde_func_0855_0x0a5398(a0, a1);
        case 856: return fde_func_0856_0x0a53bc(a0, a1);
        case 857: return fde_func_0857_0x0a5db0(a0, a1);
        case 858: return fde_func_0858_0x0a6094(a0, a1);
        case 859: return fde_func_0859_0x0a6290(a0, a1);
        case 860: return fde_func_0860_0x0a62dc(a0, a1);
        case 861: return fde_func_0861_0x0a6798(a0, a1);
        case 862: return fde_func_0862_0x0a6a98(a0, a1);
        case 863: return fde_func_0863_0x0a6b88(a0, a1);
        case 864: return fde_func_0864_0x0a6ce8(a0, a1);
        case 865: return fde_func_0865_0x0a6f8c(a0, a1);
        case 866: return fde_func_0866_0x0a723c(a0, a1);
        case 867: return fde_func_0867_0x0a779c(a0, a1);
        case 868: return fde_func_0868_0x0a7894(a0, a1);
        case 869: return fde_func_0869_0x0a78e0(a0, a1);
        case 870: return fde_func_0870_0x0a7be4(a0, a1);
        case 871: return fde_func_0871_0x0a7e00(a0, a1);
        case 872: return fde_func_0872_0x0a7f80(a0, a1);
        case 873: return fde_func_0873_0x0a7fcc(a0, a1);
        case 874: return fde_func_0874_0x0a8194(a0, a1);
        case 875: return fde_func_0875_0x0a8340(a0, a1);
        case 876: return fde_func_0876_0x0a838c(a0, a1);
        case 877: return fde_func_0877_0x0a8528(a0, a1);
        case 878: return fde_func_0878_0x0a8628(a0, a1);
        case 879: return fde_func_0879_0x0a866c(a0, a1);
        case 880: return fde_func_0880_0x0a869c(a0, a1);
        case 881: return fde_func_0881_0x0a86e0(a0, a1);
        case 882: return fde_func_0882_0x0a8718(a0, a1);
        case 883: return fde_func_0883_0x0a88a0(a0, a1);
        case 884: return fde_func_0884_0x0a88ec(a0, a1);
        case 885: return fde_func_0885_0x0a8938(a0, a1);
        case 886: return fde_func_0886_0x0a89a4(a0, a1);
        case 887: return fde_func_0887_0x0a8a0c(a0, a1);
        case 888: return fde_func_0888_0x0a8bfc(a0, a1);
        case 889: return fde_func_0889_0x0a8cc8(a0, a1);
        case 890: return fde_func_0890_0x0a8d30(a0, a1);
        case 891: return fde_func_0891_0x0a8d34(a0, a1);
        case 892: return fde_func_0892_0x0a8d38(a0, a1);
        case 893: return fde_func_0893_0x0a8d4c(a0, a1);
        case 894: return fde_func_0894_0x0a8db4(a0, a1);
        case 895: return fde_func_0895_0x0a8dc0(a0, a1);
        case 896: return fde_func_0896_0x0a8de4(a0, a1);
        case 897: return fde_func_0897_0x0a8de8(a0, a1);
        case 898: return fde_func_0898_0x0a8dfc(a0, a1);
        case 899: return fde_func_0899_0x0a8e48(a0, a1);
        case 900: return fde_func_0900_0x0a9054(a0, a1);
        case 901: return fde_func_0901_0x0a9374(a0, a1);
        case 902: return fde_func_0902_0x0a9490(a0, a1);
        case 903: return fde_func_0903_0x0a94bc(a0, a1);
        case 904: return fde_func_0904_0x0a9500(a0, a1);
        case 905: return fde_func_0905_0x0a9540(a0, a1);
        case 906: return fde_func_0906_0x0a97bc(a0, a1);
        case 907: return fde_func_0907_0x0a9824(a0, a1);
        case 908: return fde_func_0908_0x0a98b8(a0, a1);
        case 909: return fde_func_0909_0x0a9b14(a0, a1);
        case 910: return fde_func_0910_0x0a9cfc(a0, a1);
        case 911: return fde_func_0911_0x0aa4a8(a0, a1);
        case 912: return fde_func_0912_0x0aae34(a0, a1);
        case 913: return fde_func_0913_0x0aaf44(a0, a1);
        case 914: return fde_func_0914_0x0ab13c(a0, a1);
        case 915: return fde_func_0915_0x0ab29c(a0, a1);
        case 916: return fde_func_0916_0x0ab3fc(a0, a1);
        case 917: return fde_func_0917_0x0ab558(a0, a1);
        case 918: return fde_func_0918_0x0ab6b8(a0, a1);
        case 919: return fde_func_0919_0x0ab814(a0, a1);
        case 920: return fde_func_0920_0x0ab990(a0, a1);
        case 921: return fde_func_0921_0x0abbfc(a0, a1);
        case 922: return fde_func_0922_0x0abd58(a0, a1);
        case 923: return fde_func_0923_0x0abeb8(a0, a1);
        case 924: return fde_func_0924_0x0ac078(a0, a1);
        case 925: return fde_func_0925_0x0ac1d8(a0, a1);
        case 926: return fde_func_0926_0x0ac388(a0, a1);
        case 927: return fde_func_0927_0x0ac3c4(a0, a1);
        case 928: return fde_func_0928_0x0ac418(a0, a1);
        case 929: return fde_func_0929_0x0ac434(a0, a1);
        case 930: return fde_func_0930_0x0ac580(a0, a1);
        case 931: return fde_func_0931_0x0ac5bc(a0, a1);
        case 932: return fde_func_0932_0x0ac604(a0, a1);
        case 933: return fde_func_0933_0x0ac638(a0, a1);
        case 934: return fde_func_0934_0x0ac978(a0, a1);
        case 935: return fde_func_0935_0x0acac0(a0, a1);
        case 936: return fde_func_0936_0x0ad2ec(a0, a1);
        case 937: return fde_func_0937_0x0ad3f4(a0, a1);
        case 938: return fde_func_0938_0x0ad670(a0, a1);
        case 939: return fde_func_0939_0x0ad828(a0, a1);
        case 940: return fde_func_0940_0x0ad944(a0, a1);
        case 941: return fde_func_0941_0x0ada3c(a0, a1);
        case 942: return fde_func_0942_0x0ada60(a0, a1);
        case 943: return fde_func_0943_0x0adb24(a0, a1);
        case 944: return fde_func_0944_0x0adb28(a0, a1);
        case 945: return fde_func_0945_0x0add0c(a0, a1);
        case 946: return fde_func_0946_0x0adddc(a0, a1);
        case 947: return fde_func_0947_0x0ae118(a0, a1);
        case 948: return fde_func_0948_0x0ae3a0(a0, a1);
        case 949: return fde_func_0949_0x0ae70c(a0, a1);
        case 950: return fde_func_0950_0x0ae8a4(a0, a1);
        case 951: return fde_func_0951_0x0aea28(a0, a1);
        case 952: return fde_func_0952_0x0aeb54(a0, a1);
        case 953: return fde_func_0953_0x0aec84(a0, a1);
        case 954: return fde_func_0954_0x0af338(a0, a1);
        case 955: return fde_func_0955_0x0af4bc(a0, a1);
        case 956: return fde_func_0956_0x0af5bc(a0, a1);
        case 957: return fde_func_0957_0x0af74c(a0, a1);
        case 958: return fde_func_0958_0x0af834(a0, a1);
        case 959: return fde_func_0959_0x0afb6c(a0, a1);
        case 960: return fde_func_0960_0x0afcc8(a0, a1);
        case 961: return fde_func_0961_0x0b04cc(a0, a1);
        case 962: return fde_func_0962_0x0b074c(a0, a1);
        case 963: return fde_func_0963_0x0b08e0(a0, a1);
        case 964: return fde_func_0964_0x0b0940(a0, a1);
        case 965: return fde_func_0965_0x0b0980(a0, a1);
        case 966: return fde_func_0966_0x0b0a14(a0, a1);
        case 967: return fde_func_0967_0x0b0a74(a0, a1);
        case 968: return fde_func_0968_0x0b0ab8(a0, a1);
        case 969: return fde_func_0969_0x0b0c94(a0, a1);
        case 970: return fde_func_0970_0x0b0dbc(a0, a1);
        case 971: return fde_func_0971_0x0b0e04(a0, a1);
        case 972: return fde_func_0972_0x0b11bc(a0, a1);
        case 973: return fde_func_0973_0x0b12a4(a0, a1);
        case 974: return fde_func_0974_0x0b14fc(a0, a1);
        case 975: return fde_func_0975_0x0b1598(a0, a1);
        case 976: return fde_func_0976_0x0b15d8(a0, a1);
        case 977: return fde_func_0977_0x0b1620(a0, a1);
        case 978: return fde_func_0978_0x0b1658(a0, a1);
        case 979: return fde_func_0979_0x0b20b4(a0, a1);
        case 980: return fde_func_0980_0x0b210c(a0, a1);
        case 981: return fde_func_0981_0x0b216c(a0, a1);
        case 982: return fde_func_0982_0x0b21a0(a0, a1);
        case 983: return fde_func_0983_0x0b2950(a0, a1);
        case 984: return fde_func_0984_0x0b29fc(a0, a1);
        case 985: return fde_func_0985_0x0b2bb4(a0, a1);
        case 986: return fde_func_0986_0x0b2c58(a0, a1);
        case 987: return fde_func_0987_0x0b30d0(a0, a1);
        case 988: return fde_func_0988_0x0b3394(a0, a1);
        case 989: return fde_func_0989_0x0b3450(a0, a1);
        case 990: return fde_func_0990_0x0b3574(a0, a1);
        case 991: return fde_func_0991_0x0b398c(a0, a1);
        case 992: return fde_func_0992_0x0b39b0(a0, a1);
        case 993: return fde_func_0993_0x0b3a10(a0, a1);
        case 994: return fde_func_0994_0x0b3a50(a0, a1);
        case 995: return fde_func_0995_0x0b3a60(a0, a1);
        case 996: return fde_func_0996_0x0b3a70(a0, a1);
        case 997: return fde_func_0997_0x0b3ab8(a0, a1);
        case 998: return fde_func_0998_0x0b4610(a0, a1);
        case 999: return fde_func_0999_0x0b4874(a0, a1);
        case 1000: return fde_func_1000_0x0b48f8(a0, a1);
        case 1001: return fde_func_1001_0x0b491c(a0, a1);
        case 1002: return fde_func_1002_0x0b49cc(a0, a1);
        case 1003: return fde_func_1003_0x0b4a18(a0, a1);
        case 1004: return fde_func_1004_0x0b4a50(a0, a1);
        case 1005: return fde_func_1005_0x0b4ae8(a0, a1);
        case 1006: return fde_func_1006_0x0b4bd0(a0, a1);
        case 1007: return fde_func_1007_0x0b4c30(a0, a1);
        case 1008: return fde_func_1008_0x0b4c8c(a0, a1);
        case 1009: return fde_func_1009_0x0b4cbc(a0, a1);
        case 1010: return fde_func_1010_0x0b510c(a0, a1);
        case 1011: return fde_func_1011_0x0b517c(a0, a1);
        case 1012: return fde_func_1012_0x0b5350(a0, a1);
        case 1013: return fde_func_1013_0x0b5374(a0, a1);
        case 1014: return fde_func_1014_0x0b537c(a0, a1);
        case 1015: return fde_func_1015_0x0b53ac(a0, a1);
        case 1016: return fde_func_1016_0x0b53dc(a0, a1);
        case 1017: return fde_func_1017_0x0b540c(a0, a1);
        case 1018: return fde_func_1018_0x0b543c(a0, a1);
        case 1019: return fde_func_1019_0x0b546c(a0, a1);
        case 1020: return fde_func_1020_0x0b549c(a0, a1);
        case 1021: return fde_func_1021_0x0b54cc(a0, a1);
        case 1022: return fde_func_1022_0x0b54fc(a0, a1);
        case 1023: return fde_func_1023_0x0b552c(a0, a1);
        case 1024: return fde_func_1024_0x0b557c(a0, a1);
        case 1025: return fde_func_1025_0x0b561c(a0, a1);
        case 1026: return fde_func_1026_0x0b56a8(a0, a1);
        case 1027: return fde_func_1027_0x0b570c(a0, a1);
        case 1028: return fde_func_1028_0x0b5778(a0, a1);
        case 1029: return fde_func_1029_0x0b59cc(a0, a1);
        case 1030: return fde_func_1030_0x0b5b04(a0, a1);
        case 1031: return fde_func_1031_0x0b5b0c(a0, a1);
        case 1032: return fde_func_1032_0x0b5b6c(a0, a1);
        case 1033: return fde_func_1033_0x0b5bb0(a0, a1);
        case 1034: return fde_func_1034_0x0b5c78(a0, a1);
        case 1035: return fde_func_1035_0x0b5e4c(a0, a1);
        case 1036: return fde_func_1036_0x0b5f1c(a0, a1);
        case 1037: return fde_func_1037_0x0b5f58(a0, a1);
        case 1038: return fde_func_1038_0x0b6028(a0, a1);
        case 1039: return fde_func_1039_0x0b6064(a0, a1);
        case 1040: return fde_func_1040_0x0b6134(a0, a1);
        case 1041: return fde_func_1041_0x0b6170(a0, a1);
        case 1042: return fde_func_1042_0x0b6240(a0, a1);
        case 1043: return fde_func_1043_0x0b627c(a0, a1);
        case 1044: return fde_func_1044_0x0b634c(a0, a1);
        case 1045: return fde_func_1045_0x0b6388(a0, a1);
        case 1046: return fde_func_1046_0x0b6458(a0, a1);
        case 1047: return fde_func_1047_0x0b6494(a0, a1);
        case 1048: return fde_func_1048_0x0b6564(a0, a1);
        case 1049: return fde_func_1049_0x0b65a0(a0, a1);
        case 1050: return fde_func_1050_0x0b662c(a0, a1);
        case 1051: return fde_func_1051_0x0b6670(a0, a1);
        case 1052: return fde_func_1052_0x0b66f8(a0, a1);
        case 1053: return fde_func_1053_0x0b673c(a0, a1);
        case 1054: return fde_func_1054_0x0b679c(a0, a1);
        case 1055: return fde_func_1055_0x0b67c4(a0, a1);
        case 1056: return fde_func_1056_0x0b6888(a0, a1);
        case 1057: return fde_func_1057_0x0b69e4(a0, a1);
        case 1058: return fde_func_1058_0x0b6a50(a0, a1);
        case 1059: return fde_func_1059_0x0b6abc(a0, a1);
        case 1060: return fde_func_1060_0x0b6b08(a0, a1);
        case 1061: return fde_func_1061_0x0b6b2c(a0, a1);
        case 1062: return fde_func_1062_0x0b6b8c(a0, a1);
        case 1063: return fde_func_1063_0x0b6bb4(a0, a1);
        case 1064: return fde_func_1064_0x0b6cb0(a0, a1);
        case 1065: return fde_func_1065_0x0b6da8(a0, a1);
        case 1066: return fde_func_1066_0x0b6e48(a0, a1);
        case 1067: return fde_func_1067_0x0b74b8(a0, a1);
        case 1068: return fde_func_1068_0x0b75cc(a0, a1);
        case 1069: return fde_func_1069_0x0b7838(a0, a1);
        case 1070: return fde_func_1070_0x0b783c(a0, a1);
        case 1071: return fde_func_1071_0x0b7860(a0, a1);
        case 1072: return fde_func_1072_0x0b7908(a0, a1);
        case 1073: return fde_func_1073_0x0b79a0(a0, a1);
        case 1074: return fde_func_1074_0x0b7b20(a0, a1);
        case 1075: return fde_func_1075_0x0b7c5c(a0, a1);
        case 1076: return fde_func_1076_0x0b7cbc(a0, a1);
        case 1077: return fde_func_1077_0x0b7d14(a0, a1);
        case 1078: return fde_func_1078_0x0b7e3c(a0, a1);
        case 1079: return fde_func_1079_0x0b7efc(a0, a1);
        case 1080: return fde_func_1080_0x0b7f5c(a0, a1);
        case 1081: return fde_func_1081_0x0b7fa8(a0, a1);
        case 1082: return fde_func_1082_0x0b8098(a0, a1);
        case 1083: return fde_func_1083_0x0b8238(a0, a1);
        case 1084: return fde_func_1084_0x0b82f8(a0, a1);
        case 1085: return fde_func_1085_0x0b8360(a0, a1);
        case 1086: return fde_func_1086_0x0b83bc(a0, a1);
        case 1087: return fde_func_1087_0x0b841c(a0, a1);
        case 1088: return fde_func_1088_0x0b8458(a0, a1);
        case 1089: return fde_func_1089_0x0b8524(a0, a1);
        case 1090: return fde_func_1090_0x0b8630(a0, a1);
        case 1091: return fde_func_1091_0x0b86f0(a0, a1);
        case 1092: return fde_func_1092_0x0b8750(a0, a1);
        case 1093: return fde_func_1093_0x0b878c(a0, a1);
        case 1094: return fde_func_1094_0x0b88ac(a0, a1);
        case 1095: return fde_func_1095_0x0b89b8(a0, a1);
        case 1096: return fde_func_1096_0x0b8a78(a0, a1);
        case 1097: return fde_func_1097_0x0b8acc(a0, a1);
        case 1098: return fde_func_1098_0x0b8c00(a0, a1);
        case 1099: return fde_func_1099_0x0b8cc0(a0, a1);
        case 1100: return fde_func_1100_0x0b8df0(a0, a1);
        case 1101: return fde_func_1101_0x0b8e68(a0, a1);
        case 1102: return fde_func_1102_0x0b8ef4(a0, a1);
        case 1103: return fde_func_1103_0x0b8f90(a0, a1);
        case 1104: return fde_func_1104_0x0b902c(a0, a1);
        case 1105: return fde_func_1105_0x0b9094(a0, a1);
        case 1106: return fde_func_1106_0x0b90fc(a0, a1);
        case 1107: return fde_func_1107_0x0b914c(a0, a1);
        case 1108: return fde_func_1108_0x0b91b0(a0, a1);
        case 1109: return fde_func_1109_0x0b92a0(a0, a1);
        case 1110: return fde_func_1110_0x0b9300(a0, a1);
        case 1111: return fde_func_1111_0x0b94ec(a0, a1);
        case 1112: return fde_func_1112_0x0b94f4(a0, a1);
        case 1113: return fde_func_1113_0x0b94fc(a0, a1);
        case 1114: return fde_func_1114_0x0b9504(a0, a1);
        case 1115: return fde_func_1115_0x0b950c(a0, a1);
        case 1116: return fde_func_1116_0x0b9514(a0, a1);
        case 1117: return fde_func_1117_0x0b9590(a0, a1);
        case 1118: return fde_func_1118_0x0b95dc(a0, a1);
        case 1119: return fde_func_1119_0x0b9634(a0, a1);
        case 1120: return fde_func_1120_0x0b9644(a0, a1);
        case 1121: return fde_func_1121_0x0b965c(a0, a1);
        case 1122: return fde_func_1122_0x0b9818(a0, a1);
        case 1123: return fde_func_1123_0x0b99d4(a0, a1);
        case 1124: return fde_func_1124_0x0b9b90(a0, a1);
        case 1125: return fde_func_1125_0x0b9d4c(a0, a1);
        case 1126: return fde_func_1126_0x0b9f08(a0, a1);
        case 1127: return fde_func_1127_0x0ba0f8(a0, a1);
        case 1128: return fde_func_1128_0x0ba158(a0, a1);
        case 1129: return fde_func_1129_0x0ba1ac(a0, a1);
        case 1130: return fde_func_1130_0x0ba2f4(a0, a1);
        case 1131: return fde_func_1131_0x0ba4d8(a0, a1);
        case 1132: return fde_func_1132_0x0ba5a0(a0, a1);
        case 1133: return fde_func_1133_0x0ba618(a0, a1);
        case 1134: return fde_func_1134_0x0ba678(a0, a1);
        case 1135: return fde_func_1135_0x0ba6b8(a0, a1);
        case 1136: return fde_func_1136_0x0ba798(a0, a1);
        case 1137: return fde_func_1137_0x0ba860(a0, a1);
        case 1138: return fde_func_1138_0x0ba928(a0, a1);
        case 1139: return fde_func_1139_0x0ba9c0(a0, a1);
        case 1140: return fde_func_1140_0x0baa54(a0, a1);
        case 1141: return fde_func_1141_0x0baab4(a0, a1);
        case 1142: return fde_func_1142_0x0bacc4(a0, a1);
        case 1143: return fde_func_1143_0x0badcc(a0, a1);
        case 1144: return fde_func_1144_0x0baf4c(a0, a1);
        case 1145: return fde_func_1145_0x0bb034(a0, a1);
        case 1146: return fde_func_1146_0x0bb120(a0, a1);
        case 1147: return fde_func_1147_0x0bb208(a0, a1);
        case 1148: return fde_func_1148_0x0bb498(a0, a1);
        case 1149: return fde_func_1149_0x0bb50c(a0, a1);
        case 1150: return fde_func_1150_0x0bb5a0(a0, a1);
        case 1151: return fde_func_1151_0x0bb65c(a0, a1);
        case 1152: return fde_func_1152_0x0bb72c(a0, a1);
        case 1153: return fde_func_1153_0x0bb78c(a0, a1);
        case 1154: return fde_func_1154_0x0bb7c0(a0, a1);
        case 1155: return fde_func_1155_0x0bb940(a0, a1);
        case 1156: return fde_func_1156_0x0bbcb0(a0, a1);
        case 1157: return fde_func_1157_0x0bbdac(a0, a1);
        case 1158: return fde_func_1158_0x0bbe3c(a0, a1);
        case 1159: return fde_func_1159_0x0bbec0(a0, a1);
        case 1160: return fde_func_1160_0x0bbee4(a0, a1);
        case 1161: return fde_func_1161_0x0bbf08(a0, a1);
        case 1162: return fde_func_1162_0x0bbf2c(a0, a1);
        case 1163: return fde_func_1163_0x0bbf50(a0, a1);
        case 1164: return fde_func_1164_0x0bbf74(a0, a1);
        case 1165: return fde_func_1165_0x0bbf98(a0, a1);
        case 1166: return fde_func_1166_0x0bbfbc(a0, a1);
        case 1167: return fde_func_1167_0x0bbfe0(a0, a1);
        case 1168: return fde_func_1168_0x0bc004(a0, a1);
        case 1169: return fde_func_1169_0x0bc028(a0, a1);
        case 1170: return fde_func_1170_0x0bc0b8(a0, a1);
        case 1171: return fde_func_1171_0x0bc3b0(a0, a1);
        case 1172: return fde_func_1172_0x0bc524(a0, a1);
        case 1173: return fde_func_1173_0x0bc52c(a0, a1);
        case 1174: return fde_func_1174_0x0bc540(a0, a1);
        case 1175: return fde_func_1175_0x0bc620(a0, a1);
        case 1176: return fde_func_1176_0x0bc66c(a0, a1);
        case 1177: return fde_func_1177_0x0bc754(a0, a1);
        case 1178: return fde_func_1178_0x0bc800(a0, a1);
        case 1179: return fde_func_1179_0x0bcaec(a0, a1);
        case 1180: return fde_func_1180_0x0bcb80(a0, a1);
        case 1181: return fde_func_1181_0x0bd194(a0, a1);
        case 1182: return fde_func_1182_0x0bd1d4(a0, a1);
        case 1183: return fde_func_1183_0x0bd274(a0, a1);
        case 1184: return fde_func_1184_0x0bd27c(a0, a1);
        case 1185: return fde_func_1185_0x0bd3e4(a0, a1);
        case 1186: return fde_func_1186_0x0bd664(a0, a1);
        case 1187: return fde_func_1187_0x0bd6c4(a0, a1);
        case 1188: return fde_func_1188_0x0bd778(a0, a1);
        case 1189: return fde_func_1189_0x0bd83c(a0, a1);
        case 1190: return fde_func_1190_0x0bd8ac(a0, a1);
        case 1191: return fde_func_1191_0x0bd8d4(a0, a1);
        case 1192: return fde_func_1192_0x0bd93c(a0, a1);
        case 1193: return fde_func_1193_0x0bda10(a0, a1);
        case 1194: return fde_func_1194_0x0bdaa0(a0, a1);
        case 1195: return fde_func_1195_0x0bdb9c(a0, a1);
        case 1196: return fde_func_1196_0x0bdbfc(a0, a1);
        case 1197: return fde_func_1197_0x0bdcd4(a0, a1);
        case 1198: return fde_func_1198_0x0bde0c(a0, a1);
        case 1199: return fde_func_1199_0x0bdee0(a0, a1);
        case 1200: return fde_func_1200_0x0bdfe8(a0, a1);
        case 1201: return fde_func_1201_0x0bf0f4(a0, a1);
        case 1202: return fde_func_1202_0x0bf140(a0, a1);
        case 1203: return fde_func_1203_0x0bf2d0(a0, a1);
        case 1204: return fde_func_1204_0x0bf630(a0, a1);
        case 1205: return fde_func_1205_0x0bf6bc(a0, a1);
        case 1206: return fde_func_1206_0x0bf7cc(a0, a1);
        case 1207: return fde_func_1207_0x0bf864(a0, a1);
        case 1208: return fde_func_1208_0x0bf908(a0, a1);
        case 1209: return fde_func_1209_0x0bf98c(a0, a1);
        case 1210: return fde_func_1210_0x0bfa70(a0, a1);
        case 1211: return fde_func_1211_0x0bfb0c(a0, a1);
        case 1212: return fde_func_1212_0x0bfb94(a0, a1);
        case 1213: return fde_func_1213_0x0bfbdc(a0, a1);
        case 1214: return fde_func_1214_0x0bfbe0(a0, a1);
        case 1215: return fde_func_1215_0x0bfcf8(a0, a1);
        case 1216: return fde_func_1216_0x0bfe58(a0, a1);
        case 1217: return fde_func_1217_0x0bff68(a0, a1);
        case 1218: return fde_func_1218_0x0c01dc(a0, a1);
        case 1219: return fde_func_1219_0x0c028c(a0, a1);
        case 1220: return fde_func_1220_0x0c03d4(a0, a1);
        case 1221: return fde_func_1221_0x0c055c(a0, a1);
        case 1222: return fde_func_1222_0x0c0908(a0, a1);
        case 1223: return fde_func_1223_0x0c0cbc(a0, a1);
        case 1224: return fde_func_1224_0x0c0cc8(a0, a1);
        case 1225: return fde_func_1225_0x0c1368(a0, a1);
        case 1226: return fde_func_1226_0x0c1370(a0, a1);
        case 1227: return fde_func_1227_0x0c1714(a0, a1);
        case 1228: return fde_func_1228_0x0c174c(a0, a1);
        case 1229: return fde_func_1229_0x0c1758(a0, a1);
        case 1230: return fde_func_1230_0x0c17b0(a0, a1);
        case 1231: return fde_func_1231_0x0c17f8(a0, a1);
        case 1232: return fde_func_1232_0x0c1894(a0, a1);
        case 1233: return fde_func_1233_0x0c18e0(a0, a1);
        case 1234: return fde_func_1234_0x0c1a24(a0, a1);
        case 1235: return fde_func_1235_0x0c1ad0(a0, a1);
        case 1236: return fde_func_1236_0x0c1b38(a0, a1);
        case 1237: return fde_func_1237_0x0c1bfc(a0, a1);
        case 1238: return fde_func_1238_0x0c1c5c(a0, a1);
        case 1239: return fde_func_1239_0x0c2054(a0, a1);
        case 1240: return fde_func_1240_0x0c205c(a0, a1);
        case 1241: return fde_func_1241_0x0c2124(a0, a1);
        case 1242: return fde_func_1242_0x0c2194(a0, a1);
        case 1243: return fde_func_1243_0x0c223c(a0, a1);
        case 1244: return fde_func_1244_0x0c2284(a0, a1);
        case 1245: return fde_func_1245_0x0c23b8(a0, a1);
        case 1246: return fde_func_1246_0x0c2548(a0, a1);
        case 1247: return fde_func_1247_0x0c2614(a0, a1);
        case 1248: return fde_func_1248_0x0c26f4(a0, a1);
        case 1249: return fde_func_1249_0x0c2720(a0, a1);
        case 1250: return fde_func_1250_0x0c2730(a0, a1);
        default: return 0ULL;
    }
}

} // namespace fast_engine