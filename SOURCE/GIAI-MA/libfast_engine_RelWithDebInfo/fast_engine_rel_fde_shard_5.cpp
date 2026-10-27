// ============================================================================
// Clean-Room C++17 AArch64 FDE Shard 5/5 for libfast_engine_RelWithDebInfo.so
// Phân mảnh FDE AArch64 C++17 sạch 5/5 cho libfast_engine_RelWithDebInfo.so
// Covers FDE indices [1668 .. 2081] out of 2,082 total FDEs (.eh_frame_hdr @ 0x1127c8)
// Bao phủ chỉ số FDE [1668 .. 2081] trên tổng số 2,082 FDE (.eh_frame_hdr @ 0x1127c8)
// ============================================================================
#include "fast_engine_rel_core.h"

namespace fast_engine {

// FDE #1668 | PC: 0x0e1648 | FDE: 0x125e00 | Size: 248 bytes [_ZN11fast_engine8TupleObj4PackElPNS_6EngineEz]
// Hàm FDE #1668 | Địa chỉ PC: 0x0e1648 | Địa chỉ FDE: 0x125e00 | Kích thước: 248 bytes
//   0x0e1648: D10403FF  sub      sp, sp, #0x100
//   0x0e164c: A90E4FF4  stp      x20, x19, [sp, #0xe0]
//   0x0e1650: A90F7BFD  stp      x29, x30, [sp, #0xf0]
//   0x0e1654: 9103C3FD  add      x29, sp, #0xf0
static inline uint64_t fde_func_1668_0x0e1648(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1648ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90e4ff4ULL) ^ 0x125e00ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #1669 | PC: 0x0e1740 | FDE: 0x125e20 | Size: 132 bytes [_ZN11fast_engine8TupleObj9FromArrayEPKPNS_3ObjElPNS_6EngineE]
// Hàm FDE #1669 | Địa chỉ PC: 0x0e1740 | Địa chỉ FDE: 0x125e20 | Kích thước: 132 bytes
//   0x0e1740: B40003C1  cbz      x1, #0xe17b8
//   0x0e1744: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0e1748: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e174c: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_1669_0x0e1740(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1740ULL ^ (static_cast<uint64_t>(0xb40003c1ULL) << 13);
    acc = (acc + a1 + 0xa9be4ff4ULL) ^ 0x125e20ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1670 | PC: 0x0e17c4 | FDE: 0x125e40 | Size: 256 bytes [_ZN11fast_engine8TupleObj12FromSequenceEPNS_3ObjEPNS_6EngineE]
// Hàm FDE #1670 | Địa chỉ PC: 0x0e17c4 | Địa chỉ FDE: 0x125e40 | Kích thước: 256 bytes
//   0x0e17c4: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0e17c8: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0e17cc: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0e17d0: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1670_0x0e17c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e17c4ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x125e40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1671 | PC: 0x0e1a78 | FDE: 0x125e70 | Size: 52 bytes [_ZN11fast_engine8TupleObj8DeepCopyEPNS_6EngineE]
// Hàm FDE #1671 | Địa chỉ PC: 0x0e1a78 | Địa chỉ FDE: 0x125e70 | Kích thước: 52 bytes
//   0x0e1a78: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0e1a7c: 910003FD  mov      x29, sp
//   0x0e1a80: D00002E8  adrp     x8, #0x13f000
//   0x0e1a84: F9445D08  ldr      x8, [x8, #0x8b8]
static inline uint64_t fde_func_1671_0x0e1a78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1a78ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x125e70ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1672 | PC: 0x0e1aac | FDE: 0x126520 | Size: 96 bytes [_ZN11fast_engine14AllocTupleTypeEPNS_6EngineE]
// Hàm FDE #1672 | Địa chỉ PC: 0x0e1aac | Địa chỉ FDE: 0x126520 | Kích thước: 96 bytes
//   0x0e1aac: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0e1ab0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e1ab4: 910043FD  add      x29, sp, #0x10
//   0x0e1ab8: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1672_0x0e1aac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1aacULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x126520ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1673 | PC: 0x0e1b0c | FDE: 0x125e90 | Size: 256 bytes [_ZN11fast_engine13InitTupleTypeEPNS_6EngineE]
// Hàm FDE #1673 | Địa chỉ PC: 0x0e1b0c | Địa chỉ FDE: 0x125e90 | Kích thước: 256 bytes
//   0x0e1b0c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0e1b10: 910003FD  mov      x29, sp
//   0x0e1b14: D00002E9  adrp     x9, #0x13f000
//   0x0e1b18: F9468529  ldr      x9, [x9, #0xd08]
static inline uint64_t fde_func_1673_0x0e1b0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1b0cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x125e90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1674 | PC: 0x0e1c70 | FDE: 0x126548 | Size: 256 bytes
// Hàm FDE #1674 | Địa chỉ PC: 0x0e1c70 | Địa chỉ FDE: 0x126548 | Kích thước: 256 bytes
//   0x0e1c70: D10183FF  sub      sp, sp, #0x60
//   0x0e1c74: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0e1c78: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0e1c7c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1674_0x0e1c70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1c70ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x126548ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1675 | PC: 0x0e1dfc | FDE: 0x126578 | Size: 256 bytes
// Hàm FDE #1675 | Địa chỉ PC: 0x0e1dfc | Địa chỉ FDE: 0x126578 | Kích thước: 256 bytes
//   0x0e1dfc: D10183FF  sub      sp, sp, #0x60
//   0x0e1e00: F90013F7  str      x23, [sp, #0x20]
//   0x0e1e04: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0e1e08: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1675_0x0e1dfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1dfcULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x126578ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1676 | PC: 0x0e1f0c | FDE: 0x1265a8 | Size: 152 bytes
// Hàm FDE #1676 | Địa chỉ PC: 0x0e1f0c | Địa chỉ FDE: 0x1265a8 | Kích thước: 152 bytes
//   0x0e1f0c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0e1f10: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e1f14: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e1f18: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1676_0x0e1f0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1f0cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1265a8ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1677 | PC: 0x0e1fa4 | FDE: 0x1265d0 | Size: 256 bytes
// Hàm FDE #1677 | Địa chỉ PC: 0x0e1fa4 | Địa chỉ FDE: 0x1265d0 | Kích thước: 256 bytes
//   0x0e1fa4: D101C3FF  sub      sp, sp, #0x70
//   0x0e1fa8: F90013F9  str      x25, [sp, #0x20]
//   0x0e1fac: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0e1fb0: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1677_0x0e1fa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1fa4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x1265d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1678 | PC: 0x0e21e0 | FDE: 0x126600 | Size: 256 bytes
// Hàm FDE #1678 | Địa chỉ PC: 0x0e21e0 | Địa chỉ FDE: 0x126600 | Kích thước: 256 bytes
//   0x0e21e0: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0e21e4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0e21e8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e21ec: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1678_0x0e21e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e21e0ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x126600ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1679 | PC: 0x0e2324 | FDE: 0x125eb0 | Size: 204 bytes
// Hàm FDE #1679 | Địa chỉ PC: 0x0e2324 | Địa chỉ FDE: 0x125eb0 | Kích thước: 204 bytes
//   0x0e2324: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0e2328: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0e232c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0e2330: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1679_0x0e2324(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e2324ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x125eb0ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1680 | PC: 0x0e23f0 | FDE: 0x125ed8 | Size: 256 bytes
// Hàm FDE #1680 | Địa chỉ PC: 0x0e23f0 | Địa chỉ FDE: 0x125ed8 | Kích thước: 256 bytes
//   0x0e23f0: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0e23f4: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0e23f8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0e23fc: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1680_0x0e23f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e23f0ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x125ed8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1681 | PC: 0x0e2694 | FDE: 0x126630 | Size: 256 bytes
// Hàm FDE #1681 | Địa chỉ PC: 0x0e2694 | Địa chỉ FDE: 0x126630 | Kích thước: 256 bytes
//   0x0e2694: D101C3FF  sub      sp, sp, #0x70
//   0x0e2698: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0e269c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0e26a0: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1681_0x0e2694(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e2694ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x126630ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1682 | PC: 0x0e2898 | FDE: 0x125f08 | Size: 8 bytes
// Hàm FDE #1682 | Địa chỉ PC: 0x0e2898 | Địa chỉ FDE: 0x125f08 | Kích thước: 8 bytes
//   0x0e2898: F9402400  ldr      x0, [x0, #0x48]
//   0x0e289c: D65F03C0  ret      
static inline uint64_t fde_func_1682_0x0e2898(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e2898ULL ^ (static_cast<uint64_t>(0xf9402400ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x125f08ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1683 | PC: 0x0e28a0 | FDE: 0x125f20 | Size: 256 bytes
// Hàm FDE #1683 | Địa chỉ PC: 0x0e28a0 | Địa chỉ FDE: 0x125f20 | Kích thước: 256 bytes
//   0x0e28a0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0e28a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e28a8: 910043FD  add      x29, sp, #0x10
//   0x0e28ac: F9401408  ldr      x8, [x0, #0x28]
static inline uint64_t fde_func_1683_0x0e28a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e28a0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x125f20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1684 | PC: 0x0e2a40 | FDE: 0x125f40 | Size: 256 bytes
// Hàm FDE #1684 | Địa chỉ PC: 0x0e2a40 | Địa chỉ FDE: 0x125f40 | Kích thước: 256 bytes
//   0x0e2a40: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0e2a44: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e2a48: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e2a4c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1684_0x0e2a40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e2a40ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x125f40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1685 | PC: 0x0e2b9c | FDE: 0x125f60 | Size: 104 bytes
// Hàm FDE #1685 | Địa chỉ PC: 0x0e2b9c | Địa chỉ FDE: 0x125f60 | Kích thước: 104 bytes
//   0x0e2b9c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0e2ba0: 910003FD  mov      x29, sp
//   0x0e2ba4: F9402408  ldr      x8, [x0, #0x48]
//   0x0e2ba8: EB01011F  cmp      x8, x1
static inline uint64_t fde_func_1685_0x0e2b9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e2b9cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x125f60ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1686 | PC: 0x0e2c04 | FDE: 0x126668 | Size: 256 bytes
// Hàm FDE #1686 | Địa chỉ PC: 0x0e2c04 | Địa chỉ FDE: 0x126668 | Kích thước: 256 bytes
//   0x0e2c04: D10183FF  sub      sp, sp, #0x60
//   0x0e2c08: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0e2c0c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0e2c10: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1686_0x0e2c04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e2c04ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x126668ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1687 | PC: 0x0e2fd0 | FDE: 0x126698 | Size: 256 bytes
// Hàm FDE #1687 | Địa chỉ PC: 0x0e2fd0 | Địa chỉ FDE: 0x126698 | Kích thước: 256 bytes
//   0x0e2fd0: D10203FF  sub      sp, sp, #0x80
//   0x0e2fd4: F90013FB  str      x27, [sp, #0x20]
//   0x0e2fd8: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0e2fdc: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1687_0x0e2fd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e2fd0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x126698ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1688 | PC: 0x0e3260 | FDE: 0x1266d0 | Size: 204 bytes [_ZN11fast_engine7ListObjC1ElPNS_6EngineE]
// Hàm FDE #1688 | Địa chỉ PC: 0x0e3260 | Địa chỉ FDE: 0x1266d0 | Kích thước: 204 bytes
//   0x0e3260: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0e3264: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e3268: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e326c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1688_0x0e3260(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3260ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1266d0ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1689 | PC: 0x0e332c | FDE: 0x1266f8 | Size: 256 bytes [_ZN11fast_engine7ListObj8GetSliceEPS0_llPNS_6EngineE]
// Hàm FDE #1689 | Địa chỉ PC: 0x0e332c | Địa chỉ FDE: 0x1266f8 | Kích thước: 256 bytes
//   0x0e332c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0e3330: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0e3334: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e3338: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1689_0x0e332c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e332cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1266f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1690 | PC: 0x0e3450 | FDE: 0x125f80 | Size: 4 bytes [_ZN11fast_engine7ListObj8SetSliceEPS0_llPNS_3ObjEPNS_6EngineE]
// Hàm FDE #1690 | Địa chỉ PC: 0x0e3450 | Địa chỉ FDE: 0x125f80 | Kích thước: 4 bytes
//   0x0e3450: 14000001  b        #0xe3454
static inline uint64_t fde_func_1690_0x0e3450(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3450ULL ^ (static_cast<uint64_t>(0x14000001ULL) << 13);
    acc = (acc + a1 + 0xd10383ffULL) ^ 0x125f80ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1691 | PC: 0x0e3454 | FDE: 0x126728 | Size: 256 bytes
// Hàm FDE #1691 | Địa chỉ PC: 0x0e3454 | Địa chỉ FDE: 0x126728 | Kích thước: 256 bytes
//   0x0e3454: D10383FF  sub      sp, sp, #0xe0
//   0x0e3458: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x0e345c: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x0e3460: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_1691_0x0e3454(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3454ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x126728ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1692 | PC: 0x0e3a60 | FDE: 0x125f98 | Size: 228 bytes [_ZN11fast_engine7ListObj6AppendEPS0_PNS_3ObjEPNS_6EngineE]
// Hàm FDE #1692 | Địa chỉ PC: 0x0e3a60 | Địa chỉ FDE: 0x125f98 | Kích thước: 228 bytes
//   0x0e3a60: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0e3a64: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0e3a68: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e3a6c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1692_0x0e3a60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3a60ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x125f98ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #1693 | PC: 0x0e3b44 | FDE: 0x125fc0 | Size: 196 bytes [_ZN11fast_engine7ListObj11AppendClearEPS0_PNS_3ObjEPNS_6EngineE]
// Hàm FDE #1693 | Địa chỉ PC: 0x0e3b44 | Địa chỉ FDE: 0x125fc0 | Kích thước: 196 bytes
//   0x0e3b44: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0e3b48: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0e3b4c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e3b50: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1693_0x0e3b44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3b44ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x125fc0ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1694 | PC: 0x0e3c08 | FDE: 0x125fe8 | Size: 256 bytes [_ZN11fast_engine7ListObj6InsertEPS0_lPNS_3ObjEPNS_6EngineE]
// Hàm FDE #1694 | Địa chỉ PC: 0x0e3c08 | Địa chỉ FDE: 0x125fe8 | Kích thước: 256 bytes
//   0x0e3c08: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0e3c0c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0e3c10: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0e3c14: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1694_0x0e3c08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3c08ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x125fe8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1695 | PC: 0x0e3d28 | FDE: 0x126010 | Size: 68 bytes [_ZN11fast_engine7ListObj7ReverseEPS0_]
// Hàm FDE #1695 | Địa chỉ PC: 0x0e3d28 | Địa chỉ FDE: 0x126010 | Kích thước: 68 bytes
//   0x0e3d28: F9402408  ldr      x8, [x0, #0x48]
//   0x0e3d2c: D37DF108  lsl      x8, x8, #3
//   0x0e3d30: B40001C8  cbz      x8, #0xe3d68
//   0x0e3d34: F9402009  ldr      x9, [x0, #0x40]
static inline uint64_t fde_func_1695_0x0e3d28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3d28ULL ^ (static_cast<uint64_t>(0xf9402408ULL) << 13);
    acc = (acc + a1 + 0xd37df108ULL) ^ 0x126010ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1696 | PC: 0x0e3d6c | FDE: 0x126028 | Size: 128 bytes [_ZN11fast_engine7ListObj4CopyEPNS_6EngineE]
// Hàm FDE #1696 | Địa chỉ PC: 0x0e3d6c | Địa chỉ FDE: 0x126028 | Kích thước: 128 bytes
//   0x0e3d6c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0e3d70: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e3d74: 910043FD  add      x29, sp, #0x10
//   0x0e3d78: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1696_0x0e3d6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3d6cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x126028ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1697 | PC: 0x0e3dec | FDE: 0x126760 | Size: 256 bytes [_ZN11fast_engine7ListObj8DeepCopyEPNS_6EngineE]
// Hàm FDE #1697 | Địa chỉ PC: 0x0e3dec | Địa chỉ FDE: 0x126760 | Kích thước: 256 bytes
//   0x0e3dec: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x0e3df0: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0e3df4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0e3df8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1697_0x0e3dec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3decULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x126760ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1698 | PC: 0x0e3ffc | FDE: 0x126048 | Size: 256 bytes [_ZN11fast_engine7ListObj3PopEPS0_lPNS_6EngineE]
// Hàm FDE #1698 | Địa chỉ PC: 0x0e3ffc | Địa chỉ FDE: 0x126048 | Kích thước: 256 bytes
//   0x0e3ffc: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0e4000: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0e4004: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e4008: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1698_0x0e3ffc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3ffcULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x126048ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1699 | PC: 0x0e4184 | FDE: 0x126798 | Size: 96 bytes [_ZN11fast_engine13AllocListTypeEPNS_6EngineE]
// Hàm FDE #1699 | Địa chỉ PC: 0x0e4184 | Địa chỉ FDE: 0x126798 | Kích thước: 96 bytes
//   0x0e4184: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0e4188: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e418c: 910043FD  add      x29, sp, #0x10
//   0x0e4190: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1699_0x0e4184(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4184ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x126798ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1700 | PC: 0x0e41e4 | FDE: 0x126070 | Size: 256 bytes [_ZN11fast_engine12InitListTypeEPNS_6EngineE]
// Hàm FDE #1700 | Địa chỉ PC: 0x0e41e4 | Địa chỉ FDE: 0x126070 | Kích thước: 256 bytes
//   0x0e41e4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0e41e8: 910003FD  mov      x29, sp
//   0x0e41ec: F00002C9  adrp     x9, #0x13f000
//   0x0e41f0: F9462929  ldr      x9, [x9, #0xc50]
static inline uint64_t fde_func_1700_0x0e41e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e41e4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x126070ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1701 | PC: 0x0e44b4 | FDE: 0x1267c0 | Size: 256 bytes
// Hàm FDE #1701 | Địa chỉ PC: 0x0e44b4 | Địa chỉ FDE: 0x1267c0 | Kích thước: 256 bytes
//   0x0e44b4: D10183FF  sub      sp, sp, #0x60
//   0x0e44b8: F90013F7  str      x23, [sp, #0x20]
//   0x0e44bc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0e44c0: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1701_0x0e44b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e44b4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1267c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1702 | PC: 0x0e45fc | FDE: 0x1267f0 | Size: 256 bytes
// Hàm FDE #1702 | Địa chỉ PC: 0x0e45fc | Địa chỉ FDE: 0x1267f0 | Kích thước: 256 bytes
//   0x0e45fc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0e4600: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e4604: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e4608: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1702_0x0e45fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e45fcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1267f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1703 | PC: 0x0e4714 | FDE: 0x126818 | Size: 256 bytes
// Hàm FDE #1703 | Địa chỉ PC: 0x0e4714 | Địa chỉ FDE: 0x126818 | Kích thước: 256 bytes
//   0x0e4714: D10183FF  sub      sp, sp, #0x60
//   0x0e4718: F90013F7  str      x23, [sp, #0x20]
//   0x0e471c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0e4720: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1703_0x0e4714(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4714ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x126818ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1704 | PC: 0x0e489c | FDE: 0x126848 | Size: 256 bytes
// Hàm FDE #1704 | Địa chỉ PC: 0x0e489c | Địa chỉ FDE: 0x126848 | Kích thước: 256 bytes
//   0x0e489c: D101C3FF  sub      sp, sp, #0x70
//   0x0e48a0: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0e48a4: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0e48a8: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1704_0x0e489c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e489cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x126848ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1705 | PC: 0x0e4aa0 | FDE: 0x126090 | Size: 48 bytes
// Hàm FDE #1705 | Địa chỉ PC: 0x0e4aa0 | Địa chỉ FDE: 0x126090 | Kích thước: 48 bytes
//   0x0e4aa0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0e4aa4: 910003FD  mov      x29, sp
//   0x0e4aa8: AA0003E8  mov      x8, x0
//   0x0e4aac: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_1705_0x0e4aa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4aa0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x126090ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1706 | PC: 0x0e4ad0 | FDE: 0x1260b0 | Size: 48 bytes
// Hàm FDE #1706 | Địa chỉ PC: 0x0e4ad0 | Địa chỉ FDE: 0x1260b0 | Kích thước: 48 bytes
//   0x0e4ad0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0e4ad4: 910003FD  mov      x29, sp
//   0x0e4ad8: AA0003E8  mov      x8, x0
//   0x0e4adc: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_1706_0x0e4ad0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4ad0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1260b0ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1707 | PC: 0x0e4b00 | FDE: 0x1260d0 | Size: 256 bytes
// Hàm FDE #1707 | Địa chỉ PC: 0x0e4b00 | Địa chỉ FDE: 0x1260d0 | Kích thước: 256 bytes
//   0x0e4b00: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0e4b04: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0e4b08: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e4b0c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1707_0x0e4b00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4b00ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1260d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1708 | PC: 0x0e4c04 | FDE: 0x1260f8 | Size: 232 bytes
// Hàm FDE #1708 | Địa chỉ PC: 0x0e4c04 | Địa chỉ FDE: 0x1260f8 | Kích thước: 232 bytes
//   0x0e4c04: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0e4c08: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0e4c0c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e4c10: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1708_0x0e4c04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4c04ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1260f8ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1709 | PC: 0x0e4cec | FDE: 0x126120 | Size: 80 bytes
// Hàm FDE #1709 | Địa chỉ PC: 0x0e4cec | Địa chỉ FDE: 0x126120 | Kích thước: 80 bytes
//   0x0e4cec: F9402428  ldr      x8, [x1, #0x48]
//   0x0e4cf0: D37DF108  lsl      x8, x8, #3
//   0x0e4cf4: B40001C8  cbz      x8, #0xe4d2c
//   0x0e4cf8: F9402029  ldr      x9, [x1, #0x40]
static inline uint64_t fde_func_1709_0x0e4cec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4cecULL ^ (static_cast<uint64_t>(0xf9402428ULL) << 13);
    acc = (acc + a1 + 0xd37df108ULL) ^ 0x126120ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1710 | PC: 0x0e4d3c | FDE: 0x126138 | Size: 256 bytes
// Hàm FDE #1710 | Địa chỉ PC: 0x0e4d3c | Địa chỉ FDE: 0x126138 | Kích thước: 256 bytes
//   0x0e4d3c: D101C3FF  sub      sp, sp, #0x70
//   0x0e4d40: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0e4d44: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0e4d48: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1710_0x0e4d3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4d3cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x126138ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1711 | PC: 0x0e4e88 | FDE: 0x126160 | Size: 52 bytes
// Hàm FDE #1711 | Địa chỉ PC: 0x0e4e88 | Địa chỉ FDE: 0x126160 | Kích thước: 52 bytes
//   0x0e4e88: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0e4e8c: 910003FD  mov      x29, sp
//   0x0e4e90: F9400028  ldr      x8, [x1]
//   0x0e4e94: F9400909  ldr      x9, [x8, #0x10]
static inline uint64_t fde_func_1711_0x0e4e88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4e88ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x126160ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1712 | PC: 0x0e4ebc | FDE: 0x126180 | Size: 24 bytes
// Hàm FDE #1712 | Địa chỉ PC: 0x0e4ebc | Địa chỉ FDE: 0x126180 | Kích thước: 24 bytes
//   0x0e4ebc: F9400028  ldr      x8, [x1]
//   0x0e4ec0: F9401102  ldr      x2, [x8, #0x20]
//   0x0e4ec4: AA0003E8  mov      x8, x0
//   0x0e4ec8: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_1712_0x0e4ebc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4ebcULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0xf9401102ULL) ^ 0x126180ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1713 | PC: 0x0e4ed4 | FDE: 0x126198 | Size: 252 bytes
// Hàm FDE #1713 | Địa chỉ PC: 0x0e4ed4 | Địa chỉ FDE: 0x126198 | Kích thước: 252 bytes
//   0x0e4ed4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0e4ed8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e4edc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e4ee0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1713_0x0e4ed4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4ed4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x126198ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1714 | PC: 0x0e4fd0 | FDE: 0x126880 | Size: 256 bytes
// Hàm FDE #1714 | Địa chỉ PC: 0x0e4fd0 | Địa chỉ FDE: 0x126880 | Kích thước: 256 bytes
//   0x0e4fd0: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0e4fd4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0e4fd8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e4fdc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1714_0x0e4fd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4fd0ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x126880ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1715 | PC: 0x0e517c | FDE: 0x1261c0 | Size: 188 bytes
// Hàm FDE #1715 | Địa chỉ PC: 0x0e517c | Địa chỉ FDE: 0x1261c0 | Kích thước: 188 bytes
//   0x0e517c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0e5180: 910003FD  mov      x29, sp
//   0x0e5184: F9402408  ldr      x8, [x0, #0x48]
//   0x0e5188: AA0303E4  mov      x4, x3
static inline uint64_t fde_func_1715_0x0e517c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e517cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1261c0ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1716 | PC: 0x0e5238 | FDE: 0x1261e0 | Size: 84 bytes
// Hàm FDE #1716 | Địa chỉ PC: 0x0e5238 | Địa chỉ FDE: 0x1261e0 | Kích thước: 84 bytes
//   0x0e5238: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0e523c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e5240: 910043FD  add      x29, sp, #0x10
//   0x0e5244: AA0203F4  mov      x20, x2
static inline uint64_t fde_func_1716_0x0e5238(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5238ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1261e0ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1717 | PC: 0x0e528c | FDE: 0x126200 | Size: 256 bytes
// Hàm FDE #1717 | Địa chỉ PC: 0x0e528c | Địa chỉ FDE: 0x126200 | Kích thước: 256 bytes
//   0x0e528c: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0e5290: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0e5294: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0e5298: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1717_0x0e528c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e528cULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x126200ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1718 | PC: 0x0e5438 | FDE: 0x1268b0 | Size: 256 bytes
// Hàm FDE #1718 | Địa chỉ PC: 0x0e5438 | Địa chỉ FDE: 0x1268b0 | Kích thước: 256 bytes
//   0x0e5438: D101C3FF  sub      sp, sp, #0x70
//   0x0e543c: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0e5440: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0e5444: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1718_0x0e5438(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5438ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x1268b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1719 | PC: 0x0e5af4 | FDE: 0x1268e8 | Size: 96 bytes [_ZN11fast_engine22AllocListTupleIterTypeEPNS_6EngineE]
// Hàm FDE #1719 | Địa chỉ PC: 0x0e5af4 | Địa chỉ FDE: 0x1268e8 | Kích thước: 96 bytes
//   0x0e5af4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0e5af8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e5afc: 910043FD  add      x29, sp, #0x10
//   0x0e5b00: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1719_0x0e5af4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5af4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1268e8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1720 | PC: 0x0e5b54 | FDE: 0x126228 | Size: 44 bytes [_ZN11fast_engine21InitListTupleIterTypeEPNS_6EngineE]
// Hàm FDE #1720 | Địa chỉ PC: 0x0e5b54 | Địa chỉ FDE: 0x126228 | Kích thước: 44 bytes
//   0x0e5b54: D00002C8  adrp     x8, #0x13f000
//   0x0e5b58: F946A908  ldr      x8, [x8, #0xd50]
//   0x0e5b5c: D00002C9  adrp     x9, #0x13f000
//   0x0e5b60: F9400108  ldr      x8, [x8]
static inline uint64_t fde_func_1720_0x0e5b54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5b54ULL ^ (static_cast<uint64_t>(0xd00002c8ULL) << 13);
    acc = (acc + a1 + 0xf946a908ULL) ^ 0x126228ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1721 | PC: 0x0e5b80 | FDE: 0x126240 | Size: 164 bytes
// Hàm FDE #1721 | Địa chỉ PC: 0x0e5b80 | Địa chỉ FDE: 0x126240 | Kích thước: 164 bytes
//   0x0e5b80: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0e5b84: 910003FD  mov      x29, sp
//   0x0e5b88: F9402008  ldr      x8, [x0, #0x40]
//   0x0e5b8c: B4000248  cbz      x8, #0xe5bd4
static inline uint64_t fde_func_1721_0x0e5b80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5b80ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x126240ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1722 | PC: 0x0e5c24 | FDE: 0x126910 | Size: 88 bytes [_ZN11fast_engine11SequenceObjD2Ev]
// Hàm FDE #1722 | Địa chỉ PC: 0x0e5c24 | Địa chỉ FDE: 0x126910 | Kích thước: 88 bytes
//   0x0e5c24: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0e5c28: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e5c2c: 910043FD  add      x29, sp, #0x10
//   0x0e5c30: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1722_0x0e5c24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5c24ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x126910ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1723 | PC: 0x0e5c7c | FDE: 0x126938 | Size: 96 bytes [_ZN11fast_engine8TupleObjD0Ev]
// Hàm FDE #1723 | Địa chỉ PC: 0x0e5c7c | Địa chỉ FDE: 0x126938 | Kích thước: 96 bytes
//   0x0e5c7c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0e5c80: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e5c84: 910043FD  add      x29, sp, #0x10
//   0x0e5c88: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1723_0x0e5c7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5c7cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x126938ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1724 | PC: 0x0e5cdc | FDE: 0x126960 | Size: 96 bytes [_ZN11fast_engine7ListObjD0Ev]
// Hàm FDE #1724 | Địa chỉ PC: 0x0e5cdc | Địa chỉ FDE: 0x126960 | Kích thước: 96 bytes
//   0x0e5cdc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0e5ce0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e5ce4: 910043FD  add      x29, sp, #0x10
//   0x0e5ce8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1724_0x0e5cdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5cdcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x126960ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1725 | PC: 0x0e5d3c | FDE: 0x126260 | Size: 256 bytes
// Hàm FDE #1725 | Địa chỉ PC: 0x0e5d3c | Địa chỉ FDE: 0x126260 | Kích thước: 256 bytes
//   0x0e5d3c: D10183FF  sub      sp, sp, #0x60
//   0x0e5d40: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0e5d44: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0e5d48: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1725_0x0e5d3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5d3cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x126260ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1726 | PC: 0x0e5e74 | FDE: 0x126288 | Size: 36 bytes [_ZN11fast_engine16ListTupleIterObjD0Ev]
// Hàm FDE #1726 | Địa chỉ PC: 0x0e5e74 | Địa chỉ FDE: 0x126288 | Kích thước: 36 bytes
//   0x0e5e74: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0e5e78: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e5e7c: 910043FD  add      x29, sp, #0x10
//   0x0e5e80: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1726_0x0e5e74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5e74ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x126288ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1727 | PC: 0x0e5e98 | FDE: 0x1262a8 | Size: 56 bytes [_ZN11fast_engine16ListTupleIterObj5ClearEPNS_6EngineE]
// Hàm FDE #1727 | Địa chỉ PC: 0x0e5e98 | Địa chỉ FDE: 0x1262a8 | Kích thước: 56 bytes
//   0x0e5e98: F9402008  ldr      x8, [x0, #0x40]
//   0x0e5e9c: B4000128  cbz      x8, #0xe5ec0
//   0x0e5ea0: B9402109  ldr      w9, [x8, #0x20]
//   0x0e5ea4: 7100093F  cmp      w9, #2
static inline uint64_t fde_func_1727_0x0e5e98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5e98ULL ^ (static_cast<uint64_t>(0xf9402008ULL) << 13);
    acc = (acc + a1 + 0xb4000128ULL) ^ 0x1262a8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1728 | PC: 0x0e5ed0 | FDE: 0x1262c0 | Size: 256 bytes
// Hàm FDE #1728 | Địa chỉ PC: 0x0e5ed0 | Địa chỉ FDE: 0x1262c0 | Kích thước: 256 bytes
//   0x0e5ed0: D101C3FF  sub      sp, sp, #0x70
//   0x0e5ed4: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x0e5ed8: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0e5edc: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1728_0x0e5ed0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5ed0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x1262c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1729 | PC: 0x0e63e0 | FDE: 0x1262f0 | Size: 256 bytes
// Hàm FDE #1729 | Địa chỉ PC: 0x0e63e0 | Địa chỉ FDE: 0x1262f0 | Kích thước: 256 bytes
//   0x0e63e0: D10143FF  sub      sp, sp, #0x50
//   0x0e63e4: F9000BF7  str      x23, [sp, #0x10]
//   0x0e63e8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0e63ec: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1729_0x0e63e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e63e0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x1262f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1730 | PC: 0x0e6530 | FDE: 0x126318 | Size: 256 bytes
// Hàm FDE #1730 | Địa chỉ PC: 0x0e6530 | Địa chỉ FDE: 0x126318 | Kích thước: 256 bytes
//   0x0e6530: D10143FF  sub      sp, sp, #0x50
//   0x0e6534: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0e6538: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0e653c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1730_0x0e6530(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6530ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x126318ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1731 | PC: 0x0e6634 | FDE: 0x126340 | Size: 256 bytes
// Hàm FDE #1731 | Địa chỉ PC: 0x0e6634 | Địa chỉ FDE: 0x126340 | Kích thước: 256 bytes
//   0x0e6634: D10183FF  sub      sp, sp, #0x60
//   0x0e6638: F9000BF9  str      x25, [sp, #0x10]
//   0x0e663c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0e6640: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1731_0x0e6634(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6634ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf9ULL) ^ 0x126340ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1732 | PC: 0x0e6780 | FDE: 0x126368 | Size: 256 bytes
// Hàm FDE #1732 | Địa chỉ PC: 0x0e6780 | Địa chỉ FDE: 0x126368 | Kích thước: 256 bytes
//   0x0e6780: D101C3FF  sub      sp, sp, #0x70
//   0x0e6784: F9000BFB  str      x27, [sp, #0x10]
//   0x0e6788: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0e678c: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1732_0x0e6780(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6780ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfbULL) ^ 0x126368ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1733 | PC: 0x0e695c | FDE: 0x126398 | Size: 256 bytes
// Hàm FDE #1733 | Địa chỉ PC: 0x0e695c | Địa chỉ FDE: 0x126398 | Kích thước: 256 bytes
//   0x0e695c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0e6960: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0e6964: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0e6968: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1733_0x0e695c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e695cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x126398ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1734 | PC: 0x0e6e24 | FDE: 0x1263c8 | Size: 256 bytes
// Hàm FDE #1734 | Địa chỉ PC: 0x0e6e24 | Địa chỉ FDE: 0x1263c8 | Kích thước: 256 bytes
//   0x0e6e24: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0e6e28: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0e6e2c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e6e30: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1734_0x0e6e24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6e24ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1263c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1735 | PC: 0x0e6f3c | FDE: 0x1263f0 | Size: 228 bytes
// Hàm FDE #1735 | Địa chỉ PC: 0x0e6f3c | Địa chỉ FDE: 0x1263f0 | Kích thước: 228 bytes
//   0x0e6f3c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0e6f40: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0e6f44: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e6f48: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1735_0x0e6f3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6f3cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1263f0ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #1736 | PC: 0x0e7020 | FDE: 0x126418 | Size: 256 bytes
// Hàm FDE #1736 | Địa chỉ PC: 0x0e7020 | Địa chỉ FDE: 0x126418 | Kích thước: 256 bytes
//   0x0e7020: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0e7024: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0e7028: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0e702c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1736_0x0e7020(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7020ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x126418ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1737 | PC: 0x0e7144 | FDE: 0x126440 | Size: 256 bytes
// Hàm FDE #1737 | Địa chỉ PC: 0x0e7144 | Địa chỉ FDE: 0x126440 | Kích thước: 256 bytes
//   0x0e7144: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0e7148: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0e714c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0e7150: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1737_0x0e7144(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7144ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x126440ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1738 | PC: 0x0e7308 | FDE: 0x126988 | Size: 88 bytes [_ZN11fast_engine6SetObjC1EPNS_6EngineE]
// Hàm FDE #1738 | Địa chỉ PC: 0x0e7308 | Địa chỉ FDE: 0x126988 | Kích thước: 88 bytes
//   0x0e7308: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0e730c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e7310: 910043FD  add      x29, sp, #0x10
//   0x0e7314: 900002C8  adrp     x8, #0x13f000
static inline uint64_t fde_func_1738_0x0e7308(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7308ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x126988ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1739 | PC: 0x0e7360 | FDE: 0x126e38 | Size: 232 bytes [_ZN11fast_engine6SetObj4CopyEPNS_6EngineE]
// Hàm FDE #1739 | Địa chỉ PC: 0x0e7360 | Địa chỉ FDE: 0x126e38 | Kích thước: 232 bytes
//   0x0e7360: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0e7364: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e7368: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e736c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1739_0x0e7360(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7360ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x126e38ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1740 | PC: 0x0e7448 | FDE: 0x1269a8 | Size: 256 bytes [_ZN11fast_engine6SetObj6UpdateEPS0_PNS_3ObjEPNS_6EngineE]
// Hàm FDE #1740 | Địa chỉ PC: 0x0e7448 | Địa chỉ FDE: 0x1269a8 | Kích thước: 256 bytes
//   0x0e7448: D10203FF  sub      sp, sp, #0x80
//   0x0e744c: F9001BF9  str      x25, [sp, #0x30]
//   0x0e7450: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0e7454: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1740_0x0e7448(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7448ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf9ULL) ^ 0x1269a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1741 | PC: 0x0e7704 | FDE: 0x126e60 | Size: 256 bytes [_ZN11fast_engine6SetObj8DeepCopyEPNS_6EngineE]
// Hàm FDE #1741 | Địa chỉ PC: 0x0e7704 | Địa chỉ FDE: 0x126e60 | Kích thước: 256 bytes
//   0x0e7704: D10183FF  sub      sp, sp, #0x60
//   0x0e7708: F9000BF9  str      x25, [sp, #0x10]
//   0x0e770c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0e7710: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1741_0x0e7704(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7704ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf9ULL) ^ 0x126e60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1742 | PC: 0x0e7894 | FDE: 0x1269d0 | Size: 88 bytes [_ZN11fast_engine6SetObj14AddObjectClearEPS0_PNS_3ObjE]
// Hàm FDE #1742 | Địa chỉ PC: 0x0e7894 | Địa chỉ FDE: 0x1269d0 | Kích thước: 88 bytes
//   0x0e7894: D100C3FF  sub      sp, sp, #0x30
//   0x0e7898: F9000BF3  str      x19, [sp, #0x10]
//   0x0e789c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e78a0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1742_0x0e7894(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7894ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x1269d0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1743 | PC: 0x0e78ec | FDE: 0x1269f0 | Size: 8 bytes [_ZN11fast_engine6SetObj4SizeEPS0_PNS_6EngineE]
// Hàm FDE #1743 | Địa chỉ PC: 0x0e78ec | Địa chỉ FDE: 0x1269f0 | Kích thước: 8 bytes
//   0x0e78ec: F9402C00  ldr      x0, [x0, #0x58]
//   0x0e78f0: D65F03C0  ret      
static inline uint64_t fde_func_1743_0x0e78ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e78ecULL ^ (static_cast<uint64_t>(0xf9402c00ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1269f0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1744 | PC: 0x0e78f4 | FDE: 0x126a08 | Size: 8 bytes
// Hàm FDE #1744 | Địa chỉ PC: 0x0e78f4 | Địa chỉ FDE: 0x126a08 | Kích thước: 8 bytes
//   0x0e78f4: F9402C00  ldr      x0, [x0, #0x58]
//   0x0e78f8: D65F03C0  ret      
static inline uint64_t fde_func_1744_0x0e78f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e78f4ULL ^ (static_cast<uint64_t>(0xf9402c00ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x126a08ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1745 | PC: 0x0e78fc | FDE: 0x126a20 | Size: 256 bytes [_ZN11fast_engine6SetObj8ContainsEPS0_PNS_3ObjEPNS_6EngineE]
// Hàm FDE #1745 | Địa chỉ PC: 0x0e78fc | Địa chỉ FDE: 0x126a20 | Kích thước: 256 bytes
//   0x0e78fc: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0e7900: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0e7904: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0e7908: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1745_0x0e78fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e78fcULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x126a20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1746 | PC: 0x0e7a04 | FDE: 0x126a50 | Size: 256 bytes
// Hàm FDE #1746 | Địa chỉ PC: 0x0e7a04 | Địa chỉ FDE: 0x126a50 | Kích thước: 256 bytes
//   0x0e7a04: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0e7a08: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0e7a0c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0e7a10: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1746_0x0e7a04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7a04ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x126a50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1747 | PC: 0x0e7b0c | FDE: 0x126a80 | Size: 204 bytes [_ZN11fast_engine6SetObj5ClearEPNS_6EngineE]
// Hàm FDE #1747 | Địa chỉ PC: 0x0e7b0c | Địa chỉ FDE: 0x126a80 | Kích thước: 204 bytes
//   0x0e7b0c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0e7b10: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e7b14: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e7b18: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1747_0x0e7b0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7b0cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x126a80ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1748 | PC: 0x0e7bd8 | FDE: 0x126aa0 | Size: 128 bytes [_ZN11fast_engine6SetObj9AddObjectEPS0_PNS_3ObjEPNS_6EngineE]
// Hàm FDE #1748 | Địa chỉ PC: 0x0e7bd8 | Địa chỉ FDE: 0x126aa0 | Kích thước: 128 bytes
//   0x0e7bd8: D100C3FF  sub      sp, sp, #0x30
//   0x0e7bdc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e7be0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e7be4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1748_0x0e7bd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7bd8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x126aa0ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1749 | PC: 0x0e7c58 | FDE: 0x126ac0 | Size: 256 bytes [_ZN11fast_engine6SetObj7DiscardEPS0_PNS_3ObjEPNS_6EngineE]
// Hàm FDE #1749 | Địa chỉ PC: 0x0e7c58 | Địa chỉ FDE: 0x126ac0 | Kích thước: 256 bytes
//   0x0e7c58: D10243FF  sub      sp, sp, #0x90
//   0x0e7c5c: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0e7c60: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0e7c64: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1749_0x0e7c58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7c58ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x126ac0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1750 | PC: 0x0e7de4 | FDE: 0x126af0 | Size: 256 bytes [_ZN11fast_engine6SetObj6RemoveEPS0_PNS_3ObjEPNS_6EngineE]
// Hàm FDE #1750 | Địa chỉ PC: 0x0e7de4 | Địa chỉ FDE: 0x126af0 | Kích thước: 256 bytes
//   0x0e7de4: D10243FF  sub      sp, sp, #0x90
//   0x0e7de8: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0e7dec: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0e7df0: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1750_0x0e7de4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7de4ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x126af0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1751 | PC: 0x0e7fac | FDE: 0x126b20 | Size: 152 bytes [_ZN11fast_engine6SetObj3PopEPS0_PNS_6EngineE]
// Hàm FDE #1751 | Địa chỉ PC: 0x0e7fac | Địa chỉ FDE: 0x126b20 | Kích thước: 152 bytes
//   0x0e7fac: D10103FF  sub      sp, sp, #0x40
//   0x0e7fb0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e7fb4: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0e7fb8: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1751_0x0e7fac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7facULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x126b20ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1752 | PC: 0x0e8044 | FDE: 0x126b40 | Size: 204 bytes [_ZN11fast_engine6SetObj5MergeEPS0_S1_PNS_6EngineE]
// Hàm FDE #1752 | Địa chỉ PC: 0x0e8044 | Địa chỉ FDE: 0x126b40 | Kích thước: 204 bytes
//   0x0e8044: D10103FF  sub      sp, sp, #0x40
//   0x0e8048: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0e804c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e8050: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1752_0x0e8044(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8044ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x126b40ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1753 | PC: 0x0e8110 | FDE: 0x126e90 | Size: 256 bytes [_ZN11fast_engine6SetObj10DifferenceEPS0_S1_PNS_6EngineE]
// Hàm FDE #1753 | Địa chỉ PC: 0x0e8110 | Địa chỉ FDE: 0x126e90 | Kích thước: 256 bytes
//   0x0e8110: D10243FF  sub      sp, sp, #0x90
//   0x0e8114: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0e8118: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0e811c: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1753_0x0e8110(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8110ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x126e90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1754 | PC: 0x0e8344 | FDE: 0x126ec8 | Size: 256 bytes [_ZN11fast_engine6SetObj12IntersectionEPS0_S1_PNS_6EngineE]
// Hàm FDE #1754 | Địa chỉ PC: 0x0e8344 | Địa chỉ FDE: 0x126ec8 | Kích thước: 256 bytes
//   0x0e8344: D10243FF  sub      sp, sp, #0x90
//   0x0e8348: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0e834c: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0e8350: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1754_0x0e8344(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8344ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x126ec8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1755 | PC: 0x0e8594 | FDE: 0x126f00 | Size: 256 bytes [_ZN11fast_engine6SetObj19SymmetricDifferenceEPS0_S1_PNS_6EngineE]
// Hàm FDE #1755 | Địa chỉ PC: 0x0e8594 | Địa chỉ FDE: 0x126f00 | Kích thước: 256 bytes
//   0x0e8594: D10283FF  sub      sp, sp, #0xa0
//   0x0e8598: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x0e859c: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0e85a0: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1755_0x0e8594(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8594ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x126f00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1756 | PC: 0x0e88e8 | FDE: 0x126f38 | Size: 96 bytes [_ZN11fast_engine12AllocSetTypeEPNS_6EngineE]
// Hàm FDE #1756 | Địa chỉ PC: 0x0e88e8 | Địa chỉ FDE: 0x126f38 | Kích thước: 96 bytes
//   0x0e88e8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0e88ec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e88f0: 910043FD  add      x29, sp, #0x10
//   0x0e88f4: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1756_0x0e88e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e88e8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x126f38ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1757 | PC: 0x0e8948 | FDE: 0x126b68 | Size: 256 bytes [_ZN11fast_engine11InitSetTypeEPNS_6EngineE]
// Hàm FDE #1757 | Địa chỉ PC: 0x0e8948 | Địa chỉ FDE: 0x126b68 | Kích thước: 256 bytes
//   0x0e8948: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0e894c: 910003FD  mov      x29, sp
//   0x0e8950: F00002A9  adrp     x9, #0x13f000
//   0x0e8954: F9470929  ldr      x9, [x9, #0xe10]
static inline uint64_t fde_func_1757_0x0e8948(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8948ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x126b68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1758 | PC: 0x0e8bb0 | FDE: 0x126f60 | Size: 256 bytes
// Hàm FDE #1758 | Địa chỉ PC: 0x0e8bb0 | Địa chỉ FDE: 0x126f60 | Kích thước: 256 bytes
//   0x0e8bb0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0e8bb4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e8bb8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e8bbc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1758_0x0e8bb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8bb0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x126f60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1759 | PC: 0x0e8cd8 | FDE: 0x126f90 | Size: 256 bytes
// Hàm FDE #1759 | Địa chỉ PC: 0x0e8cd8 | Địa chỉ FDE: 0x126f90 | Kích thước: 256 bytes
//   0x0e8cd8: D10183FF  sub      sp, sp, #0x60
//   0x0e8cdc: F90013F7  str      x23, [sp, #0x20]
//   0x0e8ce0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0e8ce4: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1759_0x0e8cd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8cd8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x126f90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1760 | PC: 0x0e8e10 | FDE: 0x126b88 | Size: 128 bytes
// Hàm FDE #1760 | Địa chỉ PC: 0x0e8e10 | Địa chỉ FDE: 0x126b88 | Kích thước: 128 bytes
//   0x0e8e10: D100C3FF  sub      sp, sp, #0x30
//   0x0e8e14: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e8e18: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e8e1c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1760_0x0e8e10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8e10ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x126b88ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1761 | PC: 0x0e8e90 | FDE: 0x126ba8 | Size: 52 bytes
// Hàm FDE #1761 | Địa chỉ PC: 0x0e8e90 | Địa chỉ FDE: 0x126ba8 | Kích thước: 52 bytes
//   0x0e8e90: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0e8e94: 910003FD  mov      x29, sp
//   0x0e8e98: F9400028  ldr      x8, [x1]
//   0x0e8e9c: F9400909  ldr      x9, [x8, #0x10]
static inline uint64_t fde_func_1761_0x0e8e90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8e90ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x126ba8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1762 | PC: 0x0e8ec4 | FDE: 0x126bc8 | Size: 20 bytes
// Hàm FDE #1762 | Địa chỉ PC: 0x0e8ec4 | Địa chỉ FDE: 0x126bc8 | Kích thước: 20 bytes
//   0x0e8ec4: AA0003E8  mov      x8, x0
//   0x0e8ec8: AA0103E0  mov      x0, x1
//   0x0e8ecc: AA0203E1  mov      x1, x2
//   0x0e8ed0: AA0803E2  mov      x2, x8
static inline uint64_t fde_func_1762_0x0e8ec4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8ec4ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xaa0103e0ULL) ^ 0x126bc8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1763 | PC: 0x0e8ed8 | FDE: 0x126be0 | Size: 20 bytes
// Hàm FDE #1763 | Địa chỉ PC: 0x0e8ed8 | Địa chỉ FDE: 0x126be0 | Kích thước: 20 bytes
//   0x0e8ed8: AA0003E8  mov      x8, x0
//   0x0e8edc: AA0103E0  mov      x0, x1
//   0x0e8ee0: AA0203E1  mov      x1, x2
//   0x0e8ee4: AA0803E2  mov      x2, x8
static inline uint64_t fde_func_1763_0x0e8ed8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8ed8ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xaa0103e0ULL) ^ 0x126be0ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1764 | PC: 0x0e8eec | FDE: 0x126bf8 | Size: 148 bytes
// Hàm FDE #1764 | Địa chỉ PC: 0x0e8eec | Địa chỉ FDE: 0x126bf8 | Kích thước: 148 bytes
//   0x0e8eec: D10103FF  sub      sp, sp, #0x40
//   0x0e8ef0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e8ef4: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0e8ef8: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1764_0x0e8eec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8eecULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x126bf8ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1765 | PC: 0x0e8f80 | FDE: 0x126fc0 | Size: 256 bytes
// Hàm FDE #1765 | Địa chỉ PC: 0x0e8f80 | Địa chỉ FDE: 0x126fc0 | Kích thước: 256 bytes
//   0x0e8f80: D10183FF  sub      sp, sp, #0x60
//   0x0e8f84: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0e8f88: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0e8f8c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1765_0x0e8f80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8f80ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x126fc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1766 | PC: 0x0e927c | FDE: 0x126c18 | Size: 224 bytes
// Hàm FDE #1766 | Địa chỉ PC: 0x0e927c | Địa chỉ FDE: 0x126c18 | Kích thước: 224 bytes
//   0x0e927c: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0e9280: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0e9284: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0e9288: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1766_0x0e927c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e927cULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x126c18ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #1767 | PC: 0x0e935c | FDE: 0x126c40 | Size: 140 bytes
// Hàm FDE #1767 | Địa chỉ PC: 0x0e935c | Địa chỉ FDE: 0x126c40 | Kích thước: 140 bytes
//   0x0e935c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0e9360: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0e9364: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e9368: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1767_0x0e935c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e935cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x126c40ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1768 | PC: 0x0e93e8 | FDE: 0x126c68 | Size: 24 bytes
// Hàm FDE #1768 | Địa chỉ PC: 0x0e93e8 | Địa chỉ FDE: 0x126c68 | Kích thước: 24 bytes
//   0x0e93e8: F9400028  ldr      x8, [x1]
//   0x0e93ec: F9401102  ldr      x2, [x8, #0x20]
//   0x0e93f0: AA0003E8  mov      x8, x0
//   0x0e93f4: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_1768_0x0e93e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e93e8ULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0xf9401102ULL) ^ 0x126c68ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1769 | PC: 0x0e9400 | FDE: 0x126ff8 | Size: 256 bytes
// Hàm FDE #1769 | Địa chỉ PC: 0x0e9400 | Địa chỉ FDE: 0x126ff8 | Kích thước: 256 bytes
//   0x0e9400: D10183FF  sub      sp, sp, #0x60
//   0x0e9404: F90013F7  str      x23, [sp, #0x20]
//   0x0e9408: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0e940c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1769_0x0e9400(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9400ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x126ff8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1770 | PC: 0x0e95d0 | FDE: 0x126c80 | Size: 256 bytes
// Hàm FDE #1770 | Địa chỉ PC: 0x0e95d0 | Địa chỉ FDE: 0x126c80 | Kích thước: 256 bytes
//   0x0e95d0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0e95d4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0e95d8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e95dc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1770_0x0e95d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e95d0ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x126c80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1771 | PC: 0x0e9768 | FDE: 0x127028 | Size: 256 bytes
// Hàm FDE #1771 | Địa chỉ PC: 0x0e9768 | Địa chỉ FDE: 0x127028 | Kích thước: 256 bytes
//   0x0e9768: D101C3FF  sub      sp, sp, #0x70
//   0x0e976c: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0e9770: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0e9774: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1771_0x0e9768(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9768ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x127028ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1772 | PC: 0x0e9978 | FDE: 0x127060 | Size: 160 bytes
// Hàm FDE #1772 | Địa chỉ PC: 0x0e9978 | Địa chỉ FDE: 0x127060 | Kích thước: 160 bytes
//   0x0e9978: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0e997c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e9980: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e9984: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1772_0x0e9978(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9978ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x127060ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1773 | PC: 0x0e9a18 | FDE: 0x127088 | Size: 96 bytes [_ZN11fast_engine16AllocSetIterTypeEPNS_6EngineE]
// Hàm FDE #1773 | Địa chỉ PC: 0x0e9a18 | Địa chỉ FDE: 0x127088 | Kích thước: 96 bytes
//   0x0e9a18: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0e9a1c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e9a20: 910043FD  add      x29, sp, #0x10
//   0x0e9a24: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1773_0x0e9a18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9a18ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x127088ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1774 | PC: 0x0e9a78 | FDE: 0x126ca8 | Size: 40 bytes [_ZN11fast_engine15InitSetIterTypeEPNS_6EngineE]
// Hàm FDE #1774 | Địa chỉ PC: 0x0e9a78 | Địa chỉ FDE: 0x126ca8 | Kích thước: 40 bytes
//   0x0e9a78: D00002A8  adrp     x8, #0x13f000
//   0x0e9a7c: F944D508  ldr      x8, [x8, #0x9a8]
//   0x0e9a80: 90000009  adrp     x9, #0xe9000
//   0x0e9a84: 9000000A  adrp     x10, #0xe9000
static inline uint64_t fde_func_1774_0x0e9a78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9a78ULL ^ (static_cast<uint64_t>(0xd00002a8ULL) << 13);
    acc = (acc + a1 + 0xf944d508ULL) ^ 0x126ca8ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1775 | PC: 0x0e9aa0 | FDE: 0x126cc0 | Size: 76 bytes
// Hàm FDE #1775 | Địa chỉ PC: 0x0e9aa0 | Địa chỉ FDE: 0x126cc0 | Kích thước: 76 bytes
//   0x0e9aa0: A944A009  ldp      x9, x8, [x0, #0x48]
//   0x0e9aa4: EB08013F  cmp      x9, x8
//   0x0e9aa8: 54000180  b.eq     #0xe9ad8
//   0x0e9aac: F9400928  ldr      x8, [x9, #0x10]
static inline uint64_t fde_func_1775_0x0e9aa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9aa0ULL ^ (static_cast<uint64_t>(0xa944a009ULL) << 13);
    acc = (acc + a1 + 0xeb08013fULL) ^ 0x126cc0ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1776 | PC: 0x0e9aec | FDE: 0x1270b0 | Size: 256 bytes
// Hàm FDE #1776 | Địa chỉ PC: 0x0e9aec | Địa chỉ FDE: 0x1270b0 | Kích thước: 256 bytes
//   0x0e9aec: D101C3FF  sub      sp, sp, #0x70
//   0x0e9af0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0e9af4: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0e9af8: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_1776_0x0e9aec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9aecULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x1270b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1777 | PC: 0x0e9cf0 | FDE: 0x126cd8 | Size: 88 bytes [_ZN11fast_engine6SetObjD2Ev]
// Hàm FDE #1777 | Địa chỉ PC: 0x0e9cf0 | Địa chỉ FDE: 0x126cd8 | Kích thước: 88 bytes
//   0x0e9cf0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0e9cf4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e9cf8: 910043FD  add      x29, sp, #0x10
//   0x0e9cfc: D00002A8  adrp     x8, #0x13f000
static inline uint64_t fde_func_1777_0x0e9cf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9cf0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x126cd8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1778 | PC: 0x0e9d48 | FDE: 0x126cf8 | Size: 96 bytes [_ZN11fast_engine6SetObjD0Ev]
// Hàm FDE #1778 | Địa chỉ PC: 0x0e9d48 | Địa chỉ FDE: 0x126cf8 | Kích thước: 96 bytes
//   0x0e9d48: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0e9d4c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e9d50: 910043FD  add      x29, sp, #0x10
//   0x0e9d54: D00002A8  adrp     x8, #0x13f000
static inline uint64_t fde_func_1778_0x0e9d48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9d48ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x126cf8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1779 | PC: 0x0e9da8 | FDE: 0x126d18 | Size: 256 bytes
// Hàm FDE #1779 | Địa chỉ PC: 0x0e9da8 | Địa chỉ FDE: 0x126d18 | Kích thước: 256 bytes
//   0x0e9da8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0e9dac: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0e9db0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e9db4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1779_0x0e9da8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9da8ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x126d18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1780 | PC: 0x0e9f3c | FDE: 0x1270e0 | Size: 256 bytes
// Hàm FDE #1780 | Địa chỉ PC: 0x0e9f3c | Địa chỉ FDE: 0x1270e0 | Kích thước: 256 bytes
//   0x0e9f3c: D101C3FF  sub      sp, sp, #0x70
//   0x0e9f40: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x0e9f44: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0e9f48: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1780_0x0e9f3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9f3cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x1270e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1781 | PC: 0x0ea1f0 | FDE: 0x127118 | Size: 256 bytes
// Hàm FDE #1781 | Địa chỉ PC: 0x0ea1f0 | Địa chỉ FDE: 0x127118 | Kích thước: 256 bytes
//   0x0ea1f0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0ea1f4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0ea1f8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0ea1fc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1781_0x0ea1f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea1f0ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x127118ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1782 | PC: 0x0ea394 | FDE: 0x126d40 | Size: 120 bytes
// Hàm FDE #1782 | Địa chỉ PC: 0x0ea394 | Địa chỉ FDE: 0x126d40 | Kích thước: 120 bytes
//   0x0ea394: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0ea398: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ea39c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ea3a0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1782_0x0ea394(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea394ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x126d40ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1783 | PC: 0x0ea40c | FDE: 0x126d60 | Size: 120 bytes
// Hàm FDE #1783 | Địa chỉ PC: 0x0ea40c | Địa chỉ FDE: 0x126d60 | Kích thước: 120 bytes
//   0x0ea40c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0ea410: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ea414: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ea418: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1783_0x0ea40c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea40cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x126d60ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1784 | PC: 0x0ea484 | FDE: 0x126d80 | Size: 120 bytes
// Hàm FDE #1784 | Địa chỉ PC: 0x0ea484 | Địa chỉ FDE: 0x126d80 | Kích thước: 120 bytes
//   0x0ea484: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0ea488: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ea48c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ea490: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1784_0x0ea484(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea484ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x126d80ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1785 | PC: 0x0ea4fc | FDE: 0x126da0 | Size: 156 bytes
// Hàm FDE #1785 | Địa chỉ PC: 0x0ea4fc | Địa chỉ FDE: 0x126da0 | Kích thước: 156 bytes
//   0x0ea4fc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0ea500: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ea504: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ea508: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1785_0x0ea4fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea4fcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x126da0ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1786 | PC: 0x0ea598 | FDE: 0x126dc0 | Size: 36 bytes [_ZN11fast_engine7SetIterD0Ev]
// Hàm FDE #1786 | Địa chỉ PC: 0x0ea598 | Địa chỉ FDE: 0x126dc0 | Kích thước: 36 bytes
//   0x0ea598: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ea59c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ea5a0: 910043FD  add      x29, sp, #0x10
//   0x0ea5a4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1786_0x0ea598(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea598ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x126dc0ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1787 | PC: 0x0ea5bc | FDE: 0x126de0 | Size: 80 bytes [_ZN11fast_engine7SetIter5ClearEPNS_6EngineE]
// Hàm FDE #1787 | Địa chỉ PC: 0x0ea5bc | Địa chỉ FDE: 0x126de0 | Kích thước: 80 bytes
//   0x0ea5bc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ea5c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ea5c4: 910043FD  add      x29, sp, #0x10
//   0x0ea5c8: F9402008  ldr      x8, [x0, #0x40]
static inline uint64_t fde_func_1787_0x0ea5bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea5bcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x126de0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1788 | PC: 0x0ea60c | FDE: 0x126e00 | Size: 156 bytes
// Hàm FDE #1788 | Địa chỉ PC: 0x0ea60c | Địa chỉ FDE: 0x126e00 | Kích thước: 156 bytes
//   0x0ea60c: D10443FF  sub      sp, sp, #0x110
//   0x0ea610: A90F4FFC  stp      x28, x19, [sp, #0xf0]
//   0x0ea614: A9107BFD  stp      x29, x30, [sp, #0x100]
//   0x0ea618: 910403FD  add      x29, sp, #0x100
static inline uint64_t fde_func_1788_0x0ea60c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea60cULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90f4ffcULL) ^ 0x126e00ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1789 | PC: 0x0ea6a8 | FDE: 0x127148 | Size: 256 bytes [_ZNSt6__ndk112__hash_tableIPN11fast_engine3ObjENS1_11ObjHashFuncENS1_9EqualFuncENS_9allocatorIS3_EEE25__emplace_unique_key_argsIS3_JRKS3_EEENS_4pairINS_15__hash_iteratorIPNS_11__hash_nodeIS3_PvEEEEbEERKT_DpOT0_]
// Hàm FDE #1789 | Địa chỉ PC: 0x0ea6a8 | Địa chỉ FDE: 0x127148 | Kích thước: 256 bytes
//   0x0ea6a8: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0ea6ac: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0ea6b0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0ea6b4: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1789_0x0ea6a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea6a8ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x127148ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1790 | PC: 0x0ea8ec | FDE: 0x126e20 | Size: 256 bytes [_ZNSt6__ndk112__hash_tableIPN11fast_engine3ObjENS1_11ObjHashFuncENS1_9EqualFuncENS_9allocatorIS3_EEE6removeENS_21__hash_const_iteratorIPNS_11__hash_nodeIS3_PvEEEE]
// Hàm FDE #1790 | Địa chỉ PC: 0x0ea8ec | Địa chỉ FDE: 0x126e20 | Kích thước: 256 bytes
//   0x0ea8ec: F9400409  ldr      x9, [x0, #8]
//   0x0ea8f0: F940042A  ldr      x10, [x1, #8]
//   0x0ea8f4: 9E670120  fmov     d0, x9
//   0x0ea8f8: 0E205800  cnt      v0.8b, v0.8b
static inline uint64_t fde_func_1790_0x0ea8ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea8ecULL ^ (static_cast<uint64_t>(0xf9400409ULL) << 13);
    acc = (acc + a1 + 0xf940042aULL) ^ 0x126e20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1791 | PC: 0x0eaa38 | FDE: 0x127280 | Size: 96 bytes [_ZN11fast_engine14AllocSliceTypeEPNS_6EngineE]
// Hàm FDE #1791 | Địa chỉ PC: 0x0eaa38 | Địa chỉ FDE: 0x127280 | Kích thước: 96 bytes
//   0x0eaa38: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0eaa3c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0eaa40: 910043FD  add      x29, sp, #0x10
//   0x0eaa44: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1791_0x0eaa38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eaa38ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x127280ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1792 | PC: 0x0eaa98 | FDE: 0x127180 | Size: 52 bytes [_ZN11fast_engine13InitSliceTypeEPNS_6EngineE]
// Hàm FDE #1792 | Địa chỉ PC: 0x0eaa98 | Địa chỉ FDE: 0x127180 | Kích thước: 52 bytes
//   0x0eaa98: B00002A8  adrp     x8, #0x13f000
//   0x0eaa9c: F9473908  ldr      x8, [x8, #0xe70]
//   0x0eaaa0: B00002AA  adrp     x10, #0x13f000
//   0x0eaaa4: 90000009  adrp     x9, #0xea000
static inline uint64_t fde_func_1792_0x0eaa98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eaa98ULL ^ (static_cast<uint64_t>(0xb00002a8ULL) << 13);
    acc = (acc + a1 + 0xf9473908ULL) ^ 0x127180ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1793 | PC: 0x0eaacc | FDE: 0x1272a8 | Size: 256 bytes
// Hàm FDE #1793 | Địa chỉ PC: 0x0eaacc | Địa chỉ FDE: 0x1272a8 | Kích thước: 256 bytes
//   0x0eaacc: D101C3FF  sub      sp, sp, #0x70
//   0x0eaad0: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0eaad4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0eaad8: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1793_0x0eaacc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eaaccULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x1272a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1794 | PC: 0x0eacc8 | FDE: 0x127198 | Size: 256 bytes
// Hàm FDE #1794 | Địa chỉ PC: 0x0eacc8 | Địa chỉ FDE: 0x127198 | Kích thước: 256 bytes
//   0x0eacc8: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0eaccc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0eacd0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0eacd4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1794_0x0eacc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eacc8ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x127198ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1795 | PC: 0x0eae20 | FDE: 0x1271c0 | Size: 256 bytes [_ZN11fast_engine8SliceObjC1EPNS_3ObjES2_S2_PNS_6EngineE]
// Hàm FDE #1795 | Địa chỉ PC: 0x0eae20 | Địa chỉ FDE: 0x1271c0 | Kích thước: 256 bytes
//   0x0eae20: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0eae24: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0eae28: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0eae2c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1795_0x0eae20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eae20ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1271c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1796 | PC: 0x0eaf24 | FDE: 0x1271e8 | Size: 176 bytes [_ZN11fast_engine8SliceObj5ClearEPNS_6EngineE]
// Hàm FDE #1796 | Địa chỉ PC: 0x0eaf24 | Địa chỉ FDE: 0x1271e8 | Kích thước: 176 bytes
//   0x0eaf24: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0eaf28: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0eaf2c: 910043FD  add      x29, sp, #0x10
//   0x0eaf30: F9402008  ldr      x8, [x0, #0x40]
static inline uint64_t fde_func_1796_0x0eaf24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eaf24ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1271e8ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #1797 | PC: 0x0eafd4 | FDE: 0x127208 | Size: 152 bytes [_ZN11fast_engine8SliceObj6_IndexEPNS_3ObjEPlPNS_6EngineE]
// Hàm FDE #1797 | Địa chỉ PC: 0x0eafd4 | Địa chỉ FDE: 0x127208 | Kích thước: 152 bytes
//   0x0eafd4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0eafd8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0eafdc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0eafe0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1797_0x0eafd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eafd4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x127208ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1798 | PC: 0x0eb06c | FDE: 0x127228 | Size: 132 bytes [_ZN11fast_engine8SliceObj13_IndexNotNoneEPNS_3ObjEPlPNS_6EngineE]
// Hàm FDE #1798 | Địa chỉ PC: 0x0eb06c | Địa chỉ FDE: 0x127228 | Kích thước: 132 bytes
//   0x0eb06c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0eb070: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0eb074: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0eb078: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1798_0x0eb06c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eb06cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x127228ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1799 | PC: 0x0eb0f0 | FDE: 0x1272d8 | Size: 256 bytes [_ZN11fast_engine8SliceObj6UnpackEPS0_PlS2_S2_PNS_6EngineE]
// Hàm FDE #1799 | Địa chỉ PC: 0x0eb0f0 | Địa chỉ FDE: 0x1272d8 | Kích thước: 256 bytes
//   0x0eb0f0: D101C3FF  sub      sp, sp, #0x70
//   0x0eb0f4: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0eb0f8: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0eb0fc: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1799_0x0eb0f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eb0f0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x1272d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1800 | PC: 0x0eb2e0 | FDE: 0x127248 | Size: 204 bytes [_ZN11fast_engine8SliceObj13AdjustIndicesElPlS1_l]
// Hàm FDE #1800 | Địa chỉ PC: 0x0eb2e0 | Địa chỉ FDE: 0x127248 | Kích thước: 204 bytes
//   0x0eb2e0: F9400028  ldr      x8, [x1]
//   0x0eb2e4: 937FFC69  asr      x9, x3, #0x3f
//   0x0eb2e8: B7F801E8  tbnz     x8, #0x3f, #0xeb324
//   0x0eb2ec: EB00011F  cmp      x8, x0
static inline uint64_t fde_func_1800_0x0eb2e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eb2e0ULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0x937ffc69ULL) ^ 0x127248ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1801 | PC: 0x0eb3ac | FDE: 0x127260 | Size: 36 bytes [_ZN11fast_engine8SliceObjD0Ev]
// Hàm FDE #1801 | Địa chỉ PC: 0x0eb3ac | Địa chỉ FDE: 0x127260 | Kích thước: 36 bytes
//   0x0eb3ac: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0eb3b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0eb3b4: 910043FD  add      x29, sp, #0x10
//   0x0eb3b8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1801_0x0eb3ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eb3acULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x127260ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1802 | PC: 0x0eb3d0 | FDE: 0x127310 | Size: 232 bytes [_ZN11fast_engine21ParseStartEndPositionEiPKPNS_3ObjElRxS4_PNS_6EngineE]
// Hàm FDE #1802 | Địa chỉ PC: 0x0eb3d0 | Địa chỉ FDE: 0x127310 | Kích thước: 232 bytes
//   0x0eb3d0: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0eb3d4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0eb3d8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0eb3dc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1802_0x0eb3d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eb3d0ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x127310ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1803 | PC: 0x0eb4b8 | FDE: 0x127760 | Size: 248 bytes [_ZN11fast_engine6StrObj13GetLatin1CharEhPNS_6EngineE]
// Hàm FDE #1803 | Địa chỉ PC: 0x0eb4b8 | Địa chỉ FDE: 0x127760 | Kích thước: 248 bytes
//   0x0eb4b8: D10143FF  sub      sp, sp, #0x50
//   0x0eb4bc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0eb4c0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0eb4c4: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1803_0x0eb4b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eb4b8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x127760ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #1804 | PC: 0x0eb5b0 | FDE: 0x127338 | Size: 148 bytes [_ZN11fast_engine6StrObj14FormatWithReprEPNS_6EngineEPKcz]
// Hàm FDE #1804 | Địa chỉ PC: 0x0eb5b0 | Địa chỉ FDE: 0x127338 | Kích thước: 148 bytes
//   0x0eb5b0: D10483FF  sub      sp, sp, #0x120
//   0x0eb5b4: A9104FFC  stp      x28, x19, [sp, #0x100]
//   0x0eb5b8: A9117BFD  stp      x29, x30, [sp, #0x110]
//   0x0eb5bc: 910443FD  add      x29, sp, #0x110
static inline uint64_t fde_func_1804_0x0eb5b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eb5b0ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa9104ffcULL) ^ 0x127338ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1805 | PC: 0x0eb644 | FDE: 0x127790 | Size: 256 bytes [_ZN11fast_engine6StrObj15FormatWithReprVEPNS_6EngineEPKcSt9__va_list]
// Hàm FDE #1805 | Địa chỉ PC: 0x0eb644 | Địa chỉ FDE: 0x127790 | Kích thước: 256 bytes
//   0x0eb644: D10403FF  sub      sp, sp, #0x100
//   0x0eb648: A90A6FFC  stp      x28, x27, [sp, #0xa0]
//   0x0eb64c: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x0eb650: A90C5FF8  stp      x24, x23, [sp, #0xc0]
static inline uint64_t fde_func_1805_0x0eb644(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eb644ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90a6ffcULL) ^ 0x127790ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1806 | PC: 0x0ebef0 | FDE: 0x127358 | Size: 164 bytes
// Hàm FDE #1806 | Địa chỉ PC: 0x0ebef0 | Địa chỉ FDE: 0x127358 | Kích thước: 164 bytes
//   0x0ebef0: D10443FF  sub      sp, sp, #0x110
//   0x0ebef4: A90F4FFC  stp      x28, x19, [sp, #0xf0]
//   0x0ebef8: A9107BFD  stp      x29, x30, [sp, #0x100]
//   0x0ebefc: 910403FD  add      x29, sp, #0x100
static inline uint64_t fde_func_1806_0x0ebef0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ebef0ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90f4ffcULL) ^ 0x127358ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1807 | PC: 0x0ebf94 | FDE: 0x1277c8 | Size: 256 bytes [_ZN11fast_engine14StrReplaceImplERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEES8_S8_i]
// Hàm FDE #1807 | Địa chỉ PC: 0x0ebf94 | Địa chỉ FDE: 0x1277c8 | Kích thước: 256 bytes
//   0x0ebf94: D10203FF  sub      sp, sp, #0x80
//   0x0ebf98: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0ebf9c: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0ebfa0: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1807_0x0ebf94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ebf94ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1277c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1808 | PC: 0x0ec1dc | FDE: 0x127378 | Size: 256 bytes [_ZN11fast_engine5StripERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEES8_bb]
// Hàm FDE #1808 | Địa chỉ PC: 0x0ec1dc | Địa chỉ FDE: 0x127378 | Kích thước: 256 bytes
//   0x0ec1dc: D101C3FF  sub      sp, sp, #0x70
//   0x0ec1e0: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x0ec1e4: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0ec1e8: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1808_0x0ec1dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ec1dcULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x127378ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1809 | PC: 0x0ec410 | FDE: 0x1273a8 | Size: 152 bytes [_ZN11fast_engine6StrObj4JoinEPS0_PNS_3ObjElPNS_6EngineE]
// Hàm FDE #1809 | Địa chỉ PC: 0x0ec410 | Địa chỉ FDE: 0x1273a8 | Kích thước: 152 bytes
//   0x0ec410: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0ec414: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ec418: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ec41c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1809_0x0ec410(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ec410ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1273a8ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1810 | PC: 0x0ec4a8 | FDE: 0x127800 | Size: 256 bytes [_ZN11fast_engine6StrObj9JoinArrayEPS0_PPNS_3ObjElPNS_6EngineE]
// Hàm FDE #1810 | Địa chỉ PC: 0x0ec4a8 | Địa chỉ FDE: 0x127800 | Kích thước: 256 bytes
//   0x0ec4a8: D102C3FF  sub      sp, sp, #0xb0
//   0x0ec4ac: F9002BFB  str      x27, [sp, #0x50]
//   0x0ec4b0: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x0ec4b4: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_1810_0x0ec4a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ec4a8ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bfbULL) ^ 0x127800ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1811 | PC: 0x0ec75c | FDE: 0x127838 | Size: 256 bytes [_ZN11fast_engine6StrObjC2EPKcPNS_6EngineE]
// Hàm FDE #1811 | Địa chỉ PC: 0x0ec75c | Địa chỉ FDE: 0x127838 | Kích thước: 256 bytes
//   0x0ec75c: D10183FF  sub      sp, sp, #0x60
//   0x0ec760: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0ec764: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0ec768: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1811_0x0ec75c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ec75cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x127838ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1812 | PC: 0x0ec8cc | FDE: 0x127868 | Size: 116 bytes [_ZN11fast_engine6StrObjC1ERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEPNS_6EngineE]
// Hàm FDE #1812 | Địa chỉ PC: 0x0ec8cc | Địa chỉ FDE: 0x127868 | Kích thước: 116 bytes
//   0x0ec8cc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ec8d0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ec8d4: 910043FD  add      x29, sp, #0x10
//   0x0ec8d8: F0000288  adrp     x8, #0x13f000
static inline uint64_t fde_func_1812_0x0ec8cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ec8ccULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x127868ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1813 | PC: 0x0ec940 | FDE: 0x1273c8 | Size: 116 bytes [_ZN11fast_engine6StrObj4HashEPS0_PNS_6EngineE]
// Hàm FDE #1813 | Địa chỉ PC: 0x0ec940 | Địa chỉ FDE: 0x1273c8 | Kích thước: 116 bytes
//   0x0ec940: F9403008  ldr      x8, [x0, #0x60]
//   0x0ec944: B100051F  cmn      x8, #1
//   0x0ec948: 54000060  b.eq     #0xec954
//   0x0ec94c: AA0803E0  mov      x0, x8
static inline uint64_t fde_func_1813_0x0ec940(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ec940ULL ^ (static_cast<uint64_t>(0xf9403008ULL) << 13);
    acc = (acc + a1 + 0xb100051fULL) ^ 0x1273c8ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1814 | PC: 0x0ec9b4 | FDE: 0x1273e0 | Size: 256 bytes [_ZN11fast_engine6StrObj13InternInPlaceEPPNS_3ObjEPNS_6EngineE]
// Hàm FDE #1814 | Địa chỉ PC: 0x0ec9b4 | Địa chỉ FDE: 0x1273e0 | Kích thước: 256 bytes
//   0x0ec9b4: D10103FF  sub      sp, sp, #0x40
//   0x0ec9b8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0ec9bc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0ec9c0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1814_0x0ec9b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ec9b4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1273e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1815 | PC: 0x0ecae0 | FDE: 0x127408 | Size: 56 bytes [_ZN11fast_engine6StrObj16InternFromStringERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEPNS_6EngineE]
// Hàm FDE #1815 | Địa chỉ PC: 0x0ecae0 | Địa chỉ FDE: 0x127408 | Kích thước: 56 bytes
//   0x0ecae0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ecae4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ecae8: 910043FD  add      x29, sp, #0x10
//   0x0ecaec: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1815_0x0ecae0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ecae0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x127408ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1816 | PC: 0x0ecb18 | FDE: 0x127428 | Size: 256 bytes [_ZN11fast_engine6StrObj6FromIdEPNS_10IdentifierEPNS_6EngineE]
// Hàm FDE #1816 | Địa chỉ PC: 0x0ecb18 | Địa chỉ FDE: 0x127428 | Kích thước: 256 bytes
//   0x0ecb18: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0ecb1c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0ecb20: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0ecb24: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1816_0x0ecb18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ecb18ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x127428ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1817 | PC: 0x0ecc20 | FDE: 0x127890 | Size: 256 bytes [_ZN11fast_engine6StrObj6ConcatEPNS_3ObjES2_PNS_6EngineE]
// Hàm FDE #1817 | Địa chỉ PC: 0x0ecc20 | Địa chỉ FDE: 0x127890 | Kích thước: 256 bytes
//   0x0ecc20: D10183FF  sub      sp, sp, #0x60
//   0x0ecc24: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0ecc28: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0ecc2c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1817_0x0ecc20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ecc20ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x127890ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1818 | PC: 0x0ecddc | FDE: 0x127450 | Size: 104 bytes [_ZN11fast_engine6StrObj5ClearEPNS_6EngineE]
// Hàm FDE #1818 | Địa chỉ PC: 0x0ecddc | Địa chỉ FDE: 0x127450 | Kích thước: 104 bytes
//   0x0ecddc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ecde0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ecde4: 910043FD  add      x29, sp, #0x10
//   0x0ecde8: 39416008  ldrb     w8, [x0, #0x58]
static inline uint64_t fde_func_1818_0x0ecddc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ecddcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x127450ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1819 | PC: 0x0ece44 | FDE: 0x127470 | Size: 256 bytes [_ZN11fast_engine6StrObj8ContainsEPNS_3ObjES2_PNS_6EngineE]
// Hàm FDE #1819 | Địa chỉ PC: 0x0ece44 | Địa chỉ FDE: 0x127470 | Kích thước: 256 bytes
//   0x0ece44: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0ece48: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0ece4c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0ece50: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1819_0x0ece44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ece44ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x127470ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1820 | PC: 0x0ecfac | FDE: 0x127498 | Size: 152 bytes [_ZN11fast_engine6StrObj17GetCharByteOffsetERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEl]
// Hàm FDE #1820 | Địa chỉ PC: 0x0ecfac | Địa chỉ FDE: 0x127498 | Kích thước: 152 bytes
//   0x0ecfac: 39400008  ldrb     w8, [x0]
//   0x0ecfb0: A940A40A  ldp      x10, x9, [x0, #8]
//   0x0ecfb4: D341FD0B  lsr      x11, x8, #1
//   0x0ecfb8: 7200011F  tst      w8, #1
static inline uint64_t fde_func_1820_0x0ecfac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ecfacULL ^ (static_cast<uint64_t>(0x39400008ULL) << 13);
    acc = (acc + a1 + 0xa940a40aULL) ^ 0x127498ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1821 | PC: 0x0ed044 | FDE: 0x1274b0 | Size: 256 bytes [_ZN11fast_engine6StrObj12GetCodePointERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEl]
// Hàm FDE #1821 | Địa chỉ PC: 0x0ed044 | Địa chỉ FDE: 0x1274b0 | Kích thước: 256 bytes
//   0x0ed044: 39400008  ldrb     w8, [x0]
//   0x0ed048: A940A40A  ldp      x10, x9, [x0, #8]
//   0x0ed04c: D341FD0B  lsr      x11, x8, #1
//   0x0ed050: 7200011F  tst      w8, #1
static inline uint64_t fde_func_1821_0x0ed044(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ed044ULL ^ (static_cast<uint64_t>(0x39400008ULL) << 13);
    acc = (acc + a1 + 0xa940a40aULL) ^ 0x1274b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1822 | PC: 0x0ed180 | FDE: 0x1278c0 | Size: 256 bytes [_ZN11fast_engine6StrObj12GetCharacterEPNS_3ObjElPNS_6EngineE]
// Hàm FDE #1822 | Địa chỉ PC: 0x0ed180 | Địa chỉ FDE: 0x1278c0 | Kích thước: 256 bytes
//   0x0ed180: D10143FF  sub      sp, sp, #0x50
//   0x0ed184: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0ed188: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0ed18c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1822_0x0ed180(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ed180ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1278c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1823 | PC: 0x0ed35c | FDE: 0x1274c8 | Size: 132 bytes [_ZN11fast_engine6StrObj4SizeEPNS_3ObjEPNS_6EngineE]
// Hàm FDE #1823 | Địa chỉ PC: 0x0ed35c | Địa chỉ FDE: 0x1274c8 | Kích thước: 132 bytes
//   0x0ed35c: AA0003E8  mov      x8, x0
//   0x0ed360: 38440D09  ldrb     w9, [x8, #0x40]!
//   0x0ed364: 37000089  tbnz     w9, #0, #0xed374
//   0x0ed368: 91000508  add      x8, x8, #1
static inline uint64_t fde_func_1823_0x0ed35c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ed35cULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0x38440d09ULL) ^ 0x1274c8ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1824 | PC: 0x0ed3e0 | FDE: 0x1274e0 | Size: 28 bytes [_ZNK11fast_engine6StrObj4CStrEv]
// Hàm FDE #1824 | Địa chỉ PC: 0x0ed3e0 | Địa chỉ FDE: 0x1274e0 | Kích thước: 28 bytes
//   0x0ed3e0: AA0003E8  mov      x8, x0
//   0x0ed3e4: 38440D09  ldrb     w9, [x8, #0x40]!
//   0x0ed3e8: 37000069  tbnz     w9, #0, #0xed3f4
//   0x0ed3ec: 91000500  add      x0, x8, #1
static inline uint64_t fde_func_1824_0x0ed3e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ed3e0ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0x38440d09ULL) ^ 0x1274e0ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1825 | PC: 0x0ed3fc | FDE: 0x1278f0 | Size: 96 bytes [_ZN11fast_engine12AllocStrTypeEPNS_6EngineE]
// Hàm FDE #1825 | Địa chỉ PC: 0x0ed3fc | Địa chỉ FDE: 0x1278f0 | Kích thước: 96 bytes
//   0x0ed3fc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ed400: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ed404: 910043FD  add      x29, sp, #0x10
//   0x0ed408: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1825_0x0ed3fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ed3fcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1278f0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1826 | PC: 0x0ed45c | FDE: 0x127918 | Size: 256 bytes [_ZN11fast_engine11InitStrTypeEPNS_6EngineE]
// Hàm FDE #1826 | Địa chỉ PC: 0x0ed45c | Địa chỉ FDE: 0x127918 | Kích thước: 256 bytes
//   0x0ed45c: D10203FF  sub      sp, sp, #0x80
//   0x0ed460: FD001BE8  str      d8, [sp, #0x30]
//   0x0ed464: F9001FF9  str      x25, [sp, #0x38]
//   0x0ed468: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1826_0x0ed45c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ed45cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xfd001be8ULL) ^ 0x127918ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1827 | PC: 0x0ed9e4 | FDE: 0x127950 | Size: 256 bytes
// Hàm FDE #1827 | Địa chỉ PC: 0x0ed9e4 | Địa chỉ FDE: 0x127950 | Kích thước: 256 bytes
//   0x0ed9e4: D106C3FF  sub      sp, sp, #0x1b0
//   0x0ed9e8: A9156FFC  stp      x28, x27, [sp, #0x150]
//   0x0ed9ec: A91667FA  stp      x26, x25, [sp, #0x160]
//   0x0ed9f0: A9175FF8  stp      x24, x23, [sp, #0x170]
static inline uint64_t fde_func_1827_0x0ed9e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ed9e4ULL ^ (static_cast<uint64_t>(0xd106c3ffULL) << 13);
    acc = (acc + a1 + 0xa9156ffcULL) ^ 0x127950ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1828 | PC: 0x0eeb0c | FDE: 0x127988 | Size: 256 bytes
// Hàm FDE #1828 | Địa chỉ PC: 0x0eeb0c | Địa chỉ FDE: 0x127988 | Kích thước: 256 bytes
//   0x0eeb0c: D10243FF  sub      sp, sp, #0x90
//   0x0eeb10: F90023F9  str      x25, [sp, #0x40]
//   0x0eeb14: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x0eeb18: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_1828_0x0eeb0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eeb0cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90023f9ULL) ^ 0x127988ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1829 | PC: 0x0ef198 | FDE: 0x1279b8 | Size: 256 bytes
// Hàm FDE #1829 | Địa chỉ PC: 0x0ef198 | Địa chỉ FDE: 0x1279b8 | Kích thước: 256 bytes
//   0x0ef198: D101C3FF  sub      sp, sp, #0x70
//   0x0ef19c: F90013F9  str      x25, [sp, #0x20]
//   0x0ef1a0: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0ef1a4: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1829_0x0ef198(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef198ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x1279b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1830 | PC: 0x0ef38c | FDE: 0x1279e8 | Size: 256 bytes
// Hàm FDE #1830 | Địa chỉ PC: 0x0ef38c | Địa chỉ FDE: 0x1279e8 | Kích thước: 256 bytes
//   0x0ef38c: D10203FF  sub      sp, sp, #0x80
//   0x0ef390: F90013FB  str      x27, [sp, #0x20]
//   0x0ef394: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0ef398: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1830_0x0ef38c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef38cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x1279e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1831 | PC: 0x0ef6a0 | FDE: 0x127a20 | Size: 256 bytes
// Hàm FDE #1831 | Địa chỉ PC: 0x0ef6a0 | Địa chỉ FDE: 0x127a20 | Kích thước: 256 bytes
//   0x0ef6a0: D10203FF  sub      sp, sp, #0x80
//   0x0ef6a4: F90013FB  str      x27, [sp, #0x20]
//   0x0ef6a8: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0ef6ac: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1831_0x0ef6a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef6a0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x127a20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1832 | PC: 0x0ef9ec | FDE: 0x127a58 | Size: 256 bytes
// Hàm FDE #1832 | Địa chỉ PC: 0x0ef9ec | Địa chỉ FDE: 0x127a58 | Kích thước: 256 bytes
//   0x0ef9ec: D10303FF  sub      sp, sp, #0xc0
//   0x0ef9f0: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x0ef9f4: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x0ef9f8: A90957F6  stp      x22, x21, [sp, #0x90]
static inline uint64_t fde_func_1832_0x0ef9ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef9ecULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa90767faULL) ^ 0x127a58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1833 | PC: 0x0efe84 | FDE: 0x127a90 | Size: 256 bytes
// Hàm FDE #1833 | Địa chỉ PC: 0x0efe84 | Địa chỉ FDE: 0x127a90 | Kích thước: 256 bytes
//   0x0efe84: D10203FF  sub      sp, sp, #0x80
//   0x0efe88: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0efe8c: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0efe90: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1833_0x0efe84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0efe84ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x127a90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1834 | PC: 0x0f04f8 | FDE: 0x127ac8 | Size: 256 bytes
// Hàm FDE #1834 | Địa chỉ PC: 0x0f04f8 | Địa chỉ FDE: 0x127ac8 | Kích thước: 256 bytes
//   0x0f04f8: D10203FF  sub      sp, sp, #0x80
//   0x0f04fc: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0f0500: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0f0504: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1834_0x0f04f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f04f8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x127ac8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1835 | PC: 0x0f09b0 | FDE: 0x127b00 | Size: 256 bytes
// Hàm FDE #1835 | Địa chỉ PC: 0x0f09b0 | Địa chỉ FDE: 0x127b00 | Kích thước: 256 bytes
//   0x0f09b0: D10203FF  sub      sp, sp, #0x80
//   0x0f09b4: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0f09b8: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0f09bc: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_1835_0x0f09b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f09b0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9045ff8ULL) ^ 0x127b00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1836 | PC: 0x0f0b10 | FDE: 0x127b30 | Size: 256 bytes
// Hàm FDE #1836 | Địa chỉ PC: 0x0f0b10 | Địa chỉ FDE: 0x127b30 | Kích thước: 256 bytes
//   0x0f0b10: D10203FF  sub      sp, sp, #0x80
//   0x0f0b14: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0f0b18: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0f0b1c: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_1836_0x0f0b10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f0b10ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9045ff8ULL) ^ 0x127b30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1837 | PC: 0x0f0c70 | FDE: 0x127b60 | Size: 256 bytes
// Hàm FDE #1837 | Địa chỉ PC: 0x0f0c70 | Địa chỉ FDE: 0x127b60 | Kích thước: 256 bytes
//   0x0f0c70: D10203FF  sub      sp, sp, #0x80
//   0x0f0c74: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0f0c78: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0f0c7c: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_1837_0x0f0c70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f0c70ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9045ff8ULL) ^ 0x127b60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1838 | PC: 0x0f0dd0 | FDE: 0x127b90 | Size: 256 bytes
// Hàm FDE #1838 | Địa chỉ PC: 0x0f0dd0 | Địa chỉ FDE: 0x127b90 | Kích thước: 256 bytes
//   0x0f0dd0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0f0dd4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f0dd8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f0ddc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1838_0x0f0dd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f0dd0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x127b90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1839 | PC: 0x0f0ed4 | FDE: 0x1274f8 | Size: 112 bytes
// Hàm FDE #1839 | Địa chỉ PC: 0x0f0ed4 | Địa chỉ FDE: 0x1274f8 | Kích thước: 112 bytes
//   0x0f0ed4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0f0ed8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f0edc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f0ee0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1839_0x0f0ed4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f0ed4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1274f8ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1840 | PC: 0x0f0f44 | FDE: 0x127518 | Size: 112 bytes
// Hàm FDE #1840 | Địa chỉ PC: 0x0f0f44 | Địa chỉ FDE: 0x127518 | Kích thước: 112 bytes
//   0x0f0f44: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0f0f48: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f0f4c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f0f50: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1840_0x0f0f44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f0f44ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x127518ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1841 | PC: 0x0f0fb4 | FDE: 0x127538 | Size: 256 bytes
// Hàm FDE #1841 | Địa chỉ PC: 0x0f0fb4 | Địa chỉ FDE: 0x127538 | Kích thước: 256 bytes
//   0x0f0fb4: AA0103E8  mov      x8, x1
//   0x0f0fb8: 38440D09  ldrb     w9, [x8, #0x40]!
//   0x0f0fbc: 370001C9  tbnz     w9, #0, #0xf0ff4
//   0x0f0fc0: 91000508  add      x8, x8, #1
static inline uint64_t fde_func_1841_0x0f0fb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f0fb4ULL ^ (static_cast<uint64_t>(0xaa0103e8ULL) << 13);
    acc = (acc + a1 + 0x38440d09ULL) ^ 0x127538ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1842 | PC: 0x0f2018 | FDE: 0x127550 | Size: 156 bytes
// Hàm FDE #1842 | Địa chỉ PC: 0x0f2018 | Địa chỉ FDE: 0x127550 | Kích thước: 156 bytes
//   0x0f2018: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0f201c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f2020: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f2024: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1842_0x0f2018(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f2018ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x127550ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1843 | PC: 0x0f20b4 | FDE: 0x127578 | Size: 144 bytes
// Hàm FDE #1843 | Địa chỉ PC: 0x0f20b4 | Địa chỉ FDE: 0x127578 | Kích thước: 144 bytes
//   0x0f20b4: AA0103E8  mov      x8, x1
//   0x0f20b8: 38440D09  ldrb     w9, [x8, #0x40]!
//   0x0f20bc: 37000269  tbnz     w9, #0, #0xf2108
//   0x0f20c0: D341FD2A  lsr      x10, x9, #1
static inline uint64_t fde_func_1843_0x0f20b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f20b4ULL ^ (static_cast<uint64_t>(0xaa0103e8ULL) << 13);
    acc = (acc + a1 + 0x38440d09ULL) ^ 0x127578ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1844 | PC: 0x0f2144 | FDE: 0x127590 | Size: 196 bytes
// Hàm FDE #1844 | Địa chỉ PC: 0x0f2144 | Địa chỉ FDE: 0x127590 | Kích thước: 196 bytes
//   0x0f2144: AA0103E8  mov      x8, x1
//   0x0f2148: 38440D09  ldrb     w9, [x8, #0x40]!
//   0x0f214c: 37000409  tbnz     w9, #0, #0xf21cc
//   0x0f2150: D341FD2A  lsr      x10, x9, #1
static inline uint64_t fde_func_1844_0x0f2144(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f2144ULL ^ (static_cast<uint64_t>(0xaa0103e8ULL) << 13);
    acc = (acc + a1 + 0x38440d09ULL) ^ 0x127590ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1845 | PC: 0x0f2208 | FDE: 0x1275a8 | Size: 156 bytes
// Hàm FDE #1845 | Địa chỉ PC: 0x0f2208 | Địa chỉ FDE: 0x1275a8 | Kích thước: 156 bytes
//   0x0f2208: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0f220c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f2210: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f2214: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1845_0x0f2208(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f2208ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1275a8ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1846 | PC: 0x0f22a4 | FDE: 0x1275d0 | Size: 156 bytes
// Hàm FDE #1846 | Địa chỉ PC: 0x0f22a4 | Địa chỉ FDE: 0x1275d0 | Kích thước: 156 bytes
//   0x0f22a4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0f22a8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f22ac: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f22b0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1846_0x0f22a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f22a4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1275d0ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1847 | PC: 0x0f2340 | FDE: 0x127bc0 | Size: 256 bytes
// Hàm FDE #1847 | Địa chỉ PC: 0x0f2340 | Địa chỉ FDE: 0x127bc0 | Kích thước: 256 bytes
//   0x0f2340: D101C3FF  sub      sp, sp, #0x70
//   0x0f2344: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0f2348: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0f234c: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1847_0x0f2340(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f2340ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x127bc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1848 | PC: 0x0f2534 | FDE: 0x1275f8 | Size: 116 bytes
// Hàm FDE #1848 | Địa chỉ PC: 0x0f2534 | Địa chỉ FDE: 0x1275f8 | Kích thước: 116 bytes
//   0x0f2534: F9403008  ldr      x8, [x0, #0x60]
//   0x0f2538: B100051F  cmn      x8, #1
//   0x0f253c: 54000060  b.eq     #0xf2548
//   0x0f2540: AA0803E0  mov      x0, x8
static inline uint64_t fde_func_1848_0x0f2534(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f2534ULL ^ (static_cast<uint64_t>(0xf9403008ULL) << 13);
    acc = (acc + a1 + 0xb100051fULL) ^ 0x1275f8ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1849 | PC: 0x0f25a8 | FDE: 0x127610 | Size: 256 bytes
// Hàm FDE #1849 | Địa chỉ PC: 0x0f25a8 | Địa chỉ FDE: 0x127610 | Kích thước: 256 bytes
//   0x0f25a8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0f25ac: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f25b0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f25b4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1849_0x0f25a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f25a8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x127610ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1850 | PC: 0x0f2714 | FDE: 0x127bf0 | Size: 172 bytes
// Hàm FDE #1850 | Địa chỉ PC: 0x0f2714 | Địa chỉ FDE: 0x127bf0 | Kích thước: 172 bytes
//   0x0f2714: D10103FF  sub      sp, sp, #0x40
//   0x0f2718: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f271c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0f2720: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1850_0x0f2714(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f2714ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x127bf0ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1851 | PC: 0x0f27c0 | FDE: 0x127630 | Size: 60 bytes
// Hàm FDE #1851 | Địa chỉ PC: 0x0f27c0 | Địa chỉ FDE: 0x127630 | Kích thước: 60 bytes
//   0x0f27c0: B0000269  adrp     x9, #0x13f000
//   0x0f27c4: F9401408  ldr      x8, [x0, #0x28]
//   0x0f27c8: F9440529  ldr      x9, [x9, #0x808]
//   0x0f27cc: F9400129  ldr      x9, [x9]
static inline uint64_t fde_func_1851_0x0f27c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f27c0ULL ^ (static_cast<uint64_t>(0xb0000269ULL) << 13);
    acc = (acc + a1 + 0xf9401408ULL) ^ 0x127630ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1852 | PC: 0x0f27fc | FDE: 0x127c18 | Size: 256 bytes
// Hàm FDE #1852 | Địa chỉ PC: 0x0f27fc | Địa chỉ FDE: 0x127c18 | Kích thước: 256 bytes
//   0x0f27fc: D10183FF  sub      sp, sp, #0x60
//   0x0f2800: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0f2804: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0f2808: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1852_0x0f27fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f27fcULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x127c18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1853 | PC: 0x0f2984 | FDE: 0x127c48 | Size: 256 bytes
// Hàm FDE #1853 | Địa chỉ PC: 0x0f2984 | Địa chỉ FDE: 0x127c48 | Kích thước: 256 bytes
//   0x0f2984: D10203FF  sub      sp, sp, #0x80
//   0x0f2988: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0f298c: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0f2990: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_1853_0x0f2984(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f2984ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9045ff8ULL) ^ 0x127c48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1854 | PC: 0x0f2f50 | FDE: 0x127c78 | Size: 208 bytes
// Hàm FDE #1854 | Địa chỉ PC: 0x0f2f50 | Địa chỉ FDE: 0x127c78 | Kích thước: 208 bytes
//   0x0f2f50: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0f2f54: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f2f58: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f2f5c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1854_0x0f2f50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f2f50ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x127c78ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1855 | PC: 0x0f3020 | FDE: 0x127ca0 | Size: 96 bytes [_ZN11fast_engine16AllocStrIterTypeEPNS_6EngineE]
// Hàm FDE #1855 | Địa chỉ PC: 0x0f3020 | Địa chỉ FDE: 0x127ca0 | Kích thước: 96 bytes
//   0x0f3020: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f3024: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f3028: 910043FD  add      x29, sp, #0x10
//   0x0f302c: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1855_0x0f3020(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f3020ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x127ca0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1856 | PC: 0x0f3080 | FDE: 0x127648 | Size: 56 bytes [_ZN11fast_engine15InitStrIterTypeEPNS_6EngineE]
// Hàm FDE #1856 | Địa chỉ PC: 0x0f3080 | Địa chỉ FDE: 0x127648 | Kích thước: 56 bytes
//   0x0f3080: 90000268  adrp     x8, #0x13f000
//   0x0f3084: F9448108  ldr      x8, [x8, #0x900]
//   0x0f3088: 90000269  adrp     x9, #0x13f000
//   0x0f308c: F944ED29  ldr      x9, [x9, #0x9d8]
static inline uint64_t fde_func_1856_0x0f3080(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f3080ULL ^ (static_cast<uint64_t>(0x90000268ULL) << 13);
    acc = (acc + a1 + 0xf9448108ULL) ^ 0x127648ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1857 | PC: 0x0f30b8 | FDE: 0x127cc8 | Size: 256 bytes
// Hàm FDE #1857 | Địa chỉ PC: 0x0f30b8 | Địa chỉ FDE: 0x127cc8 | Kích thước: 256 bytes
//   0x0f30b8: D101C3FF  sub      sp, sp, #0x70
//   0x0f30bc: F90013F9  str      x25, [sp, #0x20]
//   0x0f30c0: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0f30c4: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1857_0x0f30b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f30b8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x127cc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1858 | PC: 0x0f324c | FDE: 0x127cf8 | Size: 256 bytes
// Hàm FDE #1858 | Địa chỉ PC: 0x0f324c | Địa chỉ FDE: 0x127cf8 | Kích thước: 256 bytes
//   0x0f324c: D101C3FF  sub      sp, sp, #0x70
//   0x0f3250: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0f3254: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0f3258: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_1858_0x0f324c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f324cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x127cf8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1859 | PC: 0x0f3448 | FDE: 0x127660 | Size: 64 bytes [_ZN11fast_engine6StrObjD2Ev]
// Hàm FDE #1859 | Địa chỉ PC: 0x0f3448 | Địa chỉ FDE: 0x127660 | Kích thước: 64 bytes
//   0x0f3448: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f344c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f3450: 910043FD  add      x29, sp, #0x10
//   0x0f3454: 90000269  adrp     x9, #0x13f000
static inline uint64_t fde_func_1859_0x0f3448(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f3448ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x127660ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1860 | PC: 0x0f3488 | FDE: 0x127680 | Size: 72 bytes [_ZN11fast_engine6StrObjD0Ev]
// Hàm FDE #1860 | Địa chỉ PC: 0x0f3488 | Địa chỉ FDE: 0x127680 | Kích thước: 72 bytes
//   0x0f3488: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f348c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f3490: 910043FD  add      x29, sp, #0x10
//   0x0f3494: 90000269  adrp     x9, #0x13f000
static inline uint64_t fde_func_1860_0x0f3488(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f3488ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x127680ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1861 | PC: 0x0f34d0 | FDE: 0x127d28 | Size: 256 bytes
// Hàm FDE #1861 | Địa chỉ PC: 0x0f34d0 | Địa chỉ FDE: 0x127d28 | Kích thước: 256 bytes
//   0x0f34d0: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0f34d4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0f34d8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0f34dc: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1861_0x0f34d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f34d0ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x127d28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1862 | PC: 0x0f3728 | FDE: 0x127d60 | Size: 256 bytes
// Hàm FDE #1862 | Địa chỉ PC: 0x0f3728 | Địa chỉ FDE: 0x127d60 | Kích thước: 256 bytes
//   0x0f3728: D10243FF  sub      sp, sp, #0x90
//   0x0f372c: F90023F9  str      x25, [sp, #0x40]
//   0x0f3730: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x0f3734: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_1862_0x0f3728(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f3728ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90023f9ULL) ^ 0x127d60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1863 | PC: 0x0f3db8 | FDE: 0x127d90 | Size: 256 bytes
// Hàm FDE #1863 | Địa chỉ PC: 0x0f3db8 | Địa chỉ FDE: 0x127d90 | Kích thước: 256 bytes
//   0x0f3db8: D10743FF  sub      sp, sp, #0x1d0
//   0x0f3dbc: A9176FFC  stp      x28, x27, [sp, #0x170]
//   0x0f3dc0: A91867FA  stp      x26, x25, [sp, #0x180]
//   0x0f3dc4: A9195FF8  stp      x24, x23, [sp, #0x190]
static inline uint64_t fde_func_1863_0x0f3db8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f3db8ULL ^ (static_cast<uint64_t>(0xd10743ffULL) << 13);
    acc = (acc + a1 + 0xa9176ffcULL) ^ 0x127d90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1864 | PC: 0x0f4fa4 | FDE: 0x1276a0 | Size: 256 bytes [_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmmc]
// Hàm FDE #1864 | Địa chỉ PC: 0x0f4fa4 | Địa chỉ FDE: 0x1276a0 | Kích thước: 256 bytes
//   0x0f4fa4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0f4fa8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0f4fac: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f4fb0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1864_0x0f4fa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4fa4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1276a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1865 | PC: 0x0f50b8 | FDE: 0x1276c8 | Size: 36 bytes [_ZN11fast_engine7StrIterD0Ev]
// Hàm FDE #1865 | Địa chỉ PC: 0x0f50b8 | Địa chỉ FDE: 0x1276c8 | Kích thước: 36 bytes
//   0x0f50b8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f50bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f50c0: 910043FD  add      x29, sp, #0x10
//   0x0f50c4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1865_0x0f50b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f50b8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1276c8ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1866 | PC: 0x0f50dc | FDE: 0x1276e8 | Size: 80 bytes [_ZN11fast_engine7StrIter5ClearEPNS_6EngineE]
// Hàm FDE #1866 | Địa chỉ PC: 0x0f50dc | Địa chỉ FDE: 0x1276e8 | Kích thước: 80 bytes
//   0x0f50dc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f50e0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f50e4: 910043FD  add      x29, sp, #0x10
//   0x0f50e8: F9402008  ldr      x8, [x0, #0x40]
static inline uint64_t fde_func_1866_0x0f50dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f50dcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1276e8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1867 | PC: 0x0f512c | FDE: 0x127708 | Size: 256 bytes [_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKcm]
// Hàm FDE #1867 | Địa chỉ PC: 0x0f512c | Địa chỉ FDE: 0x127708 | Kích thước: 256 bytes
//   0x0f512c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0f5130: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0f5134: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f5138: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1867_0x0f512c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f512cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x127708ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1868 | PC: 0x0f5250 | FDE: 0x127730 | Size: 256 bytes [_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7replaceEmmPKcm]
// Hàm FDE #1868 | Địa chỉ PC: 0x0f5250 | Địa chỉ FDE: 0x127730 | Kích thước: 256 bytes
//   0x0f5250: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x0f5254: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0f5258: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0f525c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1868_0x0f5250(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5250ULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x127730ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1869 | PC: 0x0f541c | FDE: 0x1286f0 | Size: 256 bytes [_ZN11fast_engine18BuiltinsIdentifierEv]
// Hàm FDE #1869 | Địa chỉ PC: 0x0f541c | Địa chỉ FDE: 0x1286f0 | Kích thước: 256 bytes
//   0x0f541c: D10183FF  sub      sp, sp, #0x60
//   0x0f5420: F90013F7  str      x23, [sp, #0x20]
//   0x0f5424: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0f5428: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1869_0x0f541c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f541cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1286f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1870 | PC: 0x0f5590 | FDE: 0x128720 | Size: 256 bytes [_ZN11fast_engine13NewIdentifierEv]
// Hàm FDE #1870 | Địa chỉ PC: 0x0f5590 | Địa chỉ FDE: 0x128720 | Kích thước: 256 bytes
//   0x0f5590: D10183FF  sub      sp, sp, #0x60
//   0x0f5594: F90013F7  str      x23, [sp, #0x20]
//   0x0f5598: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0f559c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1870_0x0f5590(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5590ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x128720ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1871 | PC: 0x0f5704 | FDE: 0x128750 | Size: 256 bytes [_ZN11fast_engine14HashIdentifierEv]
// Hàm FDE #1871 | Địa chỉ PC: 0x0f5704 | Địa chỉ FDE: 0x128750 | Kích thước: 256 bytes
//   0x0f5704: D10183FF  sub      sp, sp, #0x60
//   0x0f5708: F90013F7  str      x23, [sp, #0x20]
//   0x0f570c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0f5710: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1871_0x0f5704(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5704ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x128750ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1872 | PC: 0x0f5878 | FDE: 0x128780 | Size: 256 bytes [_ZN11fast_engine22GetAttributeIdentifierEv]
// Hàm FDE #1872 | Địa chỉ PC: 0x0f5878 | Địa chỉ FDE: 0x128780 | Kích thước: 256 bytes
//   0x0f5878: D10183FF  sub      sp, sp, #0x60
//   0x0f587c: F90013F7  str      x23, [sp, #0x20]
//   0x0f5880: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0f5884: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1872_0x0f5878(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5878ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x128780ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1873 | PC: 0x0f59ec | FDE: 0x1287b0 | Size: 256 bytes [_ZN11fast_engine17GetItemIdentifierEv]
// Hàm FDE #1873 | Địa chỉ PC: 0x0f59ec | Địa chỉ FDE: 0x1287b0 | Kích thước: 256 bytes
//   0x0f59ec: D10183FF  sub      sp, sp, #0x60
//   0x0f59f0: F90013F7  str      x23, [sp, #0x20]
//   0x0f59f4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0f59f8: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1873_0x0f59ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f59ecULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1287b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1874 | PC: 0x0f5b60 | FDE: 0x1287e0 | Size: 256 bytes [_ZN11fast_engine17SetItemIdentifierEv]
// Hàm FDE #1874 | Địa chỉ PC: 0x0f5b60 | Địa chỉ FDE: 0x1287e0 | Kích thước: 256 bytes
//   0x0f5b60: D10183FF  sub      sp, sp, #0x60
//   0x0f5b64: F90013F7  str      x23, [sp, #0x20]
//   0x0f5b68: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0f5b6c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1874_0x0f5b60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5b60ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1287e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1875 | PC: 0x0f5cd4 | FDE: 0x128810 | Size: 256 bytes [_ZN11fast_engine17DelItemIdentifierEv]
// Hàm FDE #1875 | Địa chỉ PC: 0x0f5cd4 | Địa chỉ FDE: 0x128810 | Kích thước: 256 bytes
//   0x0f5cd4: D10183FF  sub      sp, sp, #0x60
//   0x0f5cd8: F90013F7  str      x23, [sp, #0x20]
//   0x0f5cdc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0f5ce0: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1875_0x0f5cd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5cd4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x128810ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1876 | PC: 0x0f5e48 | FDE: 0x128840 | Size: 256 bytes [_ZN11fast_engine13LenIdentifierEv]
// Hàm FDE #1876 | Địa chỉ PC: 0x0f5e48 | Địa chỉ FDE: 0x128840 | Kích thước: 256 bytes
//   0x0f5e48: D10183FF  sub      sp, sp, #0x60
//   0x0f5e4c: F90013F7  str      x23, [sp, #0x20]
//   0x0f5e50: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0f5e54: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1876_0x0f5e48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5e48ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x128840ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1877 | PC: 0x0f5fbc | FDE: 0x127dc8 | Size: 200 bytes [_ZN11fast_engine7TypeObj18CalculateMetaclassEPS0_PNS_3ObjEPNS_6EngineE]
// Hàm FDE #1877 | Địa chỉ PC: 0x0f5fbc | Địa chỉ FDE: 0x127dc8 | Kích thước: 200 bytes
//   0x0f5fbc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0f5fc0: 910003FD  mov      x29, sp
//   0x0f5fc4: F9402428  ldr      x8, [x1, #0x48]
//   0x0f5fc8: F100051F  cmp      x8, #1
static inline uint64_t fde_func_1877_0x0f5fbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5fbcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x127dc8ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1878 | PC: 0x0f6084 | FDE: 0x127de8 | Size: 80 bytes [_ZN11fast_engine7TypeObj9IsSubtypeEPKS0_]
// Hàm FDE #1878 | Địa chỉ PC: 0x0f6084 | Địa chỉ FDE: 0x127de8 | Kích thước: 80 bytes
//   0x0f6084: B0000248  adrp     x8, #0x13f000
//   0x0f6088: F9440D08  ldr      x8, [x8, #0x818]
//   0x0f608c: F9400109  ldr      x9, [x8]
//   0x0f6090: EB01013F  cmp      x9, x1
static inline uint64_t fde_func_1878_0x0f6084(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f6084ULL ^ (static_cast<uint64_t>(0xb0000248ULL) << 13);
    acc = (acc + a1 + 0xf9440d08ULL) ^ 0x127de8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1879 | PC: 0x0f60d4 | FDE: 0x127e00 | Size: 256 bytes [_ZN11fast_engine7TypeObj11GetAttrImplEPNS_3ObjEPNS_6StrObjEPNS_6EngineEPb]
// Hàm FDE #1879 | Địa chỉ PC: 0x0f60d4 | Địa chỉ FDE: 0x127e00 | Kích thước: 256 bytes
//   0x0f60d4: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0f60d8: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0f60dc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0f60e0: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1879_0x0f60d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f60d4ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x127e00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1880 | PC: 0x0f6344 | FDE: 0x128870 | Size: 256 bytes [_ZN11fast_engine7TypeObj8TypeInitEPS0_PNS_6EngineEb]
// Hàm FDE #1880 | Địa chỉ PC: 0x0f6344 | Địa chỉ FDE: 0x128870 | Kích thước: 256 bytes
//   0x0f6344: D10243FF  sub      sp, sp, #0x90
//   0x0f6348: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0f634c: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0f6350: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1880_0x0f6344(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f6344ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x128870ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1881 | PC: 0x0f76c4 | FDE: 0x127e30 | Size: 256 bytes [_ZN11fast_engine7TypeObj7_LookupEPS0_PNS_6StrObjEPNS_6EngineE]
// Hàm FDE #1881 | Địa chỉ PC: 0x0f76c4 | Địa chỉ FDE: 0x127e30 | Kích thước: 256 bytes
//   0x0f76c4: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0f76c8: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0f76cc: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0f76d0: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1881_0x0f76c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f76c4ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x127e30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1882 | PC: 0x0f7894 | FDE: 0x127e60 | Size: 8 bytes [_ZN11fast_engine7TypeObj7GetAttrEPNS_3ObjEPNS_6StrObjEPNS_6EngineE]
// Hàm FDE #1882 | Địa chỉ PC: 0x0f7894 | Địa chỉ FDE: 0x127e60 | Kích thước: 8 bytes
//   0x0f7894: AA1F03E3  mov      x3, xzr
//   0x0f7898: 17FD32AA  b        #0x44340
static inline uint64_t fde_func_1882_0x0f7894(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f7894ULL ^ (static_cast<uint64_t>(0xaa1f03e3ULL) << 13);
    acc = (acc + a1 + 0x17fd32aaULL) ^ 0x127e60ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1883 | PC: 0x0f789c | FDE: 0x1288a8 | Size: 208 bytes [_ZN11fast_engine13AllocTypeTypeEPNS_6EngineE]
// Hàm FDE #1883 | Địa chỉ PC: 0x0f789c | Địa chỉ FDE: 0x1288a8 | Kích thước: 208 bytes
//   0x0f789c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0f78a0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f78a4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f78a8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1883_0x0f789c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f789cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1288a8ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1884 | PC: 0x0f796c | FDE: 0x127e78 | Size: 256 bytes [_ZN11fast_engine12InitTypeTypeEPNS_6EngineE]
// Hàm FDE #1884 | Địa chỉ PC: 0x0f796c | Địa chỉ FDE: 0x127e78 | Kích thước: 256 bytes
//   0x0f796c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0f7970: 910003FD  mov      x29, sp
//   0x0f7974: 90000248  adrp     x8, #0x13f000
//   0x0f7978: F945AD08  ldr      x8, [x8, #0xb58]
static inline uint64_t fde_func_1884_0x0f796c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f796cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x127e78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1885 | PC: 0x0f7aac | FDE: 0x127e98 | Size: 256 bytes
// Hàm FDE #1885 | Địa chỉ PC: 0x0f7aac | Địa chỉ FDE: 0x127e98 | Kích thước: 256 bytes
//   0x0f7aac: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0f7ab0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0f7ab4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f7ab8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1885_0x0f7aac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f7aacULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x127e98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1886 | PC: 0x0f7c9c | FDE: 0x1288d0 | Size: 256 bytes
// Hàm FDE #1886 | Địa chỉ PC: 0x0f7c9c | Địa chỉ FDE: 0x1288d0 | Kích thước: 256 bytes
//   0x0f7c9c: D10143FF  sub      sp, sp, #0x50
//   0x0f7ca0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0f7ca4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0f7ca8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1886_0x0f7c9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f7c9cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1288d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1887 | PC: 0x0f7da0 | FDE: 0x128900 | Size: 256 bytes
// Hàm FDE #1887 | Địa chỉ PC: 0x0f7da0 | Địa chỉ FDE: 0x128900 | Kích thước: 256 bytes
//   0x0f7da0: D10383FF  sub      sp, sp, #0xe0
//   0x0f7da4: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x0f7da8: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x0f7dac: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_1887_0x0f7da0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f7da0ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x128900ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1888 | PC: 0x0f8b38 | FDE: 0x127ec0 | Size: 8 bytes
// Hàm FDE #1888 | Địa chỉ PC: 0x0f8b38 | Địa chỉ FDE: 0x127ec0 | Kích thước: 8 bytes
//   0x0f8b38: 52800020  mov      w0, #1
//   0x0f8b3c: D65F03C0  ret      
static inline uint64_t fde_func_1888_0x0f8b38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8b38ULL ^ (static_cast<uint64_t>(0x52800020ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x127ec0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1889 | PC: 0x0f8b40 | FDE: 0x128938 | Size: 256 bytes
// Hàm FDE #1889 | Địa chỉ PC: 0x0f8b40 | Địa chỉ FDE: 0x128938 | Kích thước: 256 bytes
//   0x0f8b40: D10183FF  sub      sp, sp, #0x60
//   0x0f8b44: F90013F7  str      x23, [sp, #0x20]
//   0x0f8b48: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0f8b4c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1889_0x0f8b40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8b40ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x128938ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1890 | PC: 0x0f8e18 | FDE: 0x127ed8 | Size: 256 bytes
// Hàm FDE #1890 | Địa chỉ PC: 0x0f8e18 | Địa chỉ FDE: 0x127ed8 | Kích thước: 256 bytes
//   0x0f8e18: D10183FF  sub      sp, sp, #0x60
//   0x0f8e1c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0f8e20: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0f8e24: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1890_0x0f8e18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8e18ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x127ed8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1891 | PC: 0x0f9098 | FDE: 0x127f00 | Size: 56 bytes
// Hàm FDE #1891 | Địa chỉ PC: 0x0f9098 | Địa chỉ FDE: 0x127f00 | Kích thước: 56 bytes
//   0x0f9098: AA0003E8  mov      x8, x0
//   0x0f909c: 3942A409  ldrb     w9, [x0, #0xa9]
//   0x0f90a0: F9409C00  ldr      x0, [x0, #0x138]
//   0x0f90a4: 37080049  tbnz     w9, #1, #0xf90ac
static inline uint64_t fde_func_1891_0x0f9098(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9098ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0x3942a409ULL) ^ 0x127f00ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1892 | PC: 0x0f90d0 | FDE: 0x127f18 | Size: 8 bytes
// Hàm FDE #1892 | Địa chỉ PC: 0x0f90d0 | Địa chỉ FDE: 0x127f18 | Kích thước: 8 bytes
//   0x0f90d0: 91010000  add      x0, x0, #0x40
//   0x0f90d4: 17FD2BAF  b        #0x43f90
static inline uint64_t fde_func_1892_0x0f90d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f90d0ULL ^ (static_cast<uint64_t>(0x91010000ULL) << 13);
    acc = (acc + a1 + 0x17fd2bafULL) ^ 0x127f18ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1893 | PC: 0x0f90d8 | FDE: 0x127f30 | Size: 200 bytes
// Hàm FDE #1893 | Địa chỉ PC: 0x0f90d8 | Địa chỉ FDE: 0x127f30 | Kích thước: 200 bytes
//   0x0f90d8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f90dc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f90e0: 910043FD  add      x29, sp, #0x10
//   0x0f90e4: F9401428  ldr      x8, [x1, #0x28]
static inline uint64_t fde_func_1893_0x0f90d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f90d8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x127f30ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1894 | PC: 0x0f91a0 | FDE: 0x127f50 | Size: 28 bytes
// Hàm FDE #1894 | Địa chỉ PC: 0x0f91a0 | Địa chỉ FDE: 0x127f50 | Kích thước: 28 bytes
//   0x0f91a0: F9407400  ldr      x0, [x0, #0xe8]
//   0x0f91a4: B4000040  cbz      x0, #0xf91ac
//   0x0f91a8: 17FD257E  b        #0x427a0
//   0x0f91ac: D0000228  adrp     x8, #0x13f000
static inline uint64_t fde_func_1894_0x0f91a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f91a0ULL ^ (static_cast<uint64_t>(0xf9407400ULL) << 13);
    acc = (acc + a1 + 0xb4000040ULL) ^ 0x127f50ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1895 | PC: 0x0f91bc | FDE: 0x127f68 | Size: 4 bytes
// Hàm FDE #1895 | Địa chỉ PC: 0x0f91bc | Địa chỉ FDE: 0x127f68 | Kích thước: 4 bytes
//   0x0f91bc: 17FD26CD  b        #0x42cf0
static inline uint64_t fde_func_1895_0x0f91bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f91bcULL ^ (static_cast<uint64_t>(0x17fd26cdULL) << 13);
    acc = (acc + a1 + 0xd10203ffULL) ^ 0x127f68ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1896 | PC: 0x0f91c0 | FDE: 0x128968 | Size: 256 bytes
// Hàm FDE #1896 | Địa chỉ PC: 0x0f91c0 | Địa chỉ FDE: 0x128968 | Kích thước: 256 bytes
//   0x0f91c0: D10203FF  sub      sp, sp, #0x80
//   0x0f91c4: F90013FB  str      x27, [sp, #0x20]
//   0x0f91c8: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0f91cc: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1896_0x0f91c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f91c0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x128968ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1897 | PC: 0x0f93f0 | FDE: 0x1289a0 | Size: 208 bytes [_ZN11fast_engine15AllocObjectTypeEPNS_6EngineE]
// Hàm FDE #1897 | Địa chỉ PC: 0x0f93f0 | Địa chỉ FDE: 0x1289a0 | Kích thước: 208 bytes
//   0x0f93f0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f93f4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f93f8: 910043FD  add      x29, sp, #0x10
//   0x0f93fc: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1897_0x0f93f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f93f0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1289a0ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1898 | PC: 0x0f94c0 | FDE: 0x127f80 | Size: 132 bytes [_ZN11fast_engine14InitObjectTypeEPNS_6EngineE]
// Hàm FDE #1898 | Địa chỉ PC: 0x0f94c0 | Địa chỉ FDE: 0x127f80 | Kích thước: 132 bytes
//   0x0f94c0: D0000228  adrp     x8, #0x13f000
//   0x0f94c4: F9440D08  ldr      x8, [x8, #0x818]
//   0x0f94c8: D0000229  adrp     x9, #0x13f000
//   0x0f94cc: F944E529  ldr      x9, [x9, #0x9c8]
static inline uint64_t fde_func_1898_0x0f94c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f94c0ULL ^ (static_cast<uint64_t>(0xd0000228ULL) << 13);
    acc = (acc + a1 + 0xf9440d08ULL) ^ 0x127f80ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1899 | PC: 0x0f9544 | FDE: 0x1289c8 | Size: 168 bytes
// Hàm FDE #1899 | Địa chỉ PC: 0x0f9544 | Địa chỉ FDE: 0x1289c8 | Kích thước: 168 bytes
//   0x0f9544: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0f9548: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f954c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f9550: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1899_0x0f9544(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9544ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1289c8ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1900 | PC: 0x0f95ec | FDE: 0x127f98 | Size: 8 bytes
// Hàm FDE #1900 | Địa chỉ PC: 0x0f95ec | Địa chỉ FDE: 0x127f98 | Kích thước: 8 bytes
//   0x0f95ec: 52800020  mov      w0, #1
//   0x0f95f0: D65F03C0  ret      
static inline uint64_t fde_func_1900_0x0f95ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f95ecULL ^ (static_cast<uint64_t>(0x52800020ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x127f98ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1901 | PC: 0x0f95f4 | FDE: 0x127fb0 | Size: 192 bytes
// Hàm FDE #1901 | Địa chỉ PC: 0x0f95f4 | Địa chỉ FDE: 0x127fb0 | Kích thước: 192 bytes
//   0x0f95f4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f95f8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f95fc: 910043FD  add      x29, sp, #0x10
//   0x0f9600: 71000C5F  cmp      w2, #3
static inline uint64_t fde_func_1901_0x0f95f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f95f4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x127fb0ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1902 | PC: 0x0f96b4 | FDE: 0x127fd0 | Size: 32 bytes
// Hàm FDE #1902 | Địa chỉ PC: 0x0f96b4 | Địa chỉ FDE: 0x127fd0 | Kích thước: 32 bytes
//   0x0f96b4: F9401400  ldr      x0, [x0, #0x28]
//   0x0f96b8: B9402008  ldr      w8, [x0, #0x20]
//   0x0f96bc: 7100091F  cmp      w8, #2
//   0x0f96c0: 54000080  b.eq     #0xf96d0
static inline uint64_t fde_func_1902_0x0f96b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f96b4ULL ^ (static_cast<uint64_t>(0xf9401400ULL) << 13);
    acc = (acc + a1 + 0xb9402008ULL) ^ 0x127fd0ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1903 | PC: 0x0f96d4 | FDE: 0x127fe8 | Size: 48 bytes
// Hàm FDE #1903 | Địa chỉ PC: 0x0f96d4 | Địa chỉ FDE: 0x127fe8 | Kích thước: 48 bytes
//   0x0f96d4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0f96d8: 910003FD  mov      x29, sp
//   0x0f96dc: D0000228  adrp     x8, #0x13f000
//   0x0f96e0: F9470508  ldr      x8, [x8, #0xe08]
static inline uint64_t fde_func_1903_0x0f96d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f96d4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x127fe8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1904 | PC: 0x0f9704 | FDE: 0x1289f0 | Size: 256 bytes
// Hàm FDE #1904 | Địa chỉ PC: 0x0f9704 | Địa chỉ FDE: 0x1289f0 | Kích thước: 256 bytes
//   0x0f9704: D10183FF  sub      sp, sp, #0x60
//   0x0f9708: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0f970c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0f9710: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1904_0x0f9704(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9704ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x1289f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1905 | PC: 0x0f99c8 | FDE: 0x128008 | Size: 28 bytes
// Hàm FDE #1905 | Địa chỉ PC: 0x0f99c8 | Địa chỉ FDE: 0x128008 | Kích thước: 28 bytes
//   0x0f99c8: F9401408  ldr      x8, [x0, #0x28]
//   0x0f99cc: 90000009  adrp     x9, #0xf9000
//   0x0f99d0: 911C1129  add      x9, x9, #0x704
//   0x0f99d4: F9403108  ldr      x8, [x8, #0x60]
static inline uint64_t fde_func_1905_0x0f99c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f99c8ULL ^ (static_cast<uint64_t>(0xf9401408ULL) << 13);
    acc = (acc + a1 + 0x90000009ULL) ^ 0x128008ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1906 | PC: 0x0f99e4 | FDE: 0x128a20 | Size: 208 bytes [_ZN11fast_engine13AllocNoneTypeEPNS_6EngineE]
// Hàm FDE #1906 | Địa chỉ PC: 0x0f99e4 | Địa chỉ FDE: 0x128a20 | Kích thước: 208 bytes
//   0x0f99e4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f99e8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f99ec: 910043FD  add      x29, sp, #0x10
//   0x0f99f0: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1906_0x0f99e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f99e4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x128a20ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1907 | PC: 0x0f9ab4 | FDE: 0x128a48 | Size: 100 bytes [_ZN11fast_engine12InitNoneTypeEPNS_6EngineE]
// Hàm FDE #1907 | Địa chỉ PC: 0x0f9ab4 | Địa chỉ FDE: 0x128a48 | Kích thước: 100 bytes
//   0x0f9ab4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f9ab8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f9abc: 910043FD  add      x29, sp, #0x10
//   0x0f9ac0: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1907_0x0f9ab4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9ab4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x128a48ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1908 | PC: 0x0f9b18 | FDE: 0x128a70 | Size: 208 bytes [_ZN11fast_engine13AllocNullTypeEPNS_6EngineE]
// Hàm FDE #1908 | Địa chỉ PC: 0x0f9b18 | Địa chỉ FDE: 0x128a70 | Kích thước: 208 bytes
//   0x0f9b18: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f9b1c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f9b20: 910043FD  add      x29, sp, #0x10
//   0x0f9b24: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1908_0x0f9b18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9b18ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x128a70ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1909 | PC: 0x0f9be8 | FDE: 0x128a98 | Size: 100 bytes [_ZN11fast_engine12InitNullTypeEPNS_6EngineE]
// Hàm FDE #1909 | Địa chỉ PC: 0x0f9be8 | Địa chỉ FDE: 0x128a98 | Kích thước: 100 bytes
//   0x0f9be8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f9bec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f9bf0: 910043FD  add      x29, sp, #0x10
//   0x0f9bf4: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1909_0x0f9be8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9be8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x128a98ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1910 | PC: 0x0f9c4c | FDE: 0x128ac0 | Size: 208 bytes [_ZN11fast_engine23AllocNotImplementedTypeEPNS_6EngineE]
// Hàm FDE #1910 | Địa chỉ PC: 0x0f9c4c | Địa chỉ FDE: 0x128ac0 | Kích thước: 208 bytes
//   0x0f9c4c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f9c50: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f9c54: 910043FD  add      x29, sp, #0x10
//   0x0f9c58: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1910_0x0f9c4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9c4cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x128ac0ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1911 | PC: 0x0f9d1c | FDE: 0x128ae8 | Size: 100 bytes [_ZN11fast_engine22InitNotImplementedTypeEPNS_6EngineE]
// Hàm FDE #1911 | Địa chỉ PC: 0x0f9d1c | Địa chỉ FDE: 0x128ae8 | Kích thước: 100 bytes
//   0x0f9d1c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f9d20: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f9d24: 910043FD  add      x29, sp, #0x10
//   0x0f9d28: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1911_0x0f9d1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9d1cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x128ae8ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1912 | PC: 0x0f9d80 | FDE: 0x128b10 | Size: 160 bytes [_ZN11fast_engine7TypeObjC2Ev]
// Hàm FDE #1912 | Địa chỉ PC: 0x0f9d80 | Địa chỉ FDE: 0x128b10 | Kích thước: 160 bytes
//   0x0f9d80: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f9d84: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f9d88: 910043FD  add      x29, sp, #0x10
//   0x0f9d8c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1912_0x0f9d80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9d80ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x128b10ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1913 | PC: 0x0f9e20 | FDE: 0x128b38 | Size: 152 bytes [_ZN11fast_engine7TypeObjC2EPKcPNS_6EngineEl]
// Hàm FDE #1913 | Địa chỉ PC: 0x0f9e20 | Địa chỉ FDE: 0x128b38 | Kích thước: 152 bytes
//   0x0f9e20: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f9e24: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f9e28: 910043FD  add      x29, sp, #0x10
//   0x0f9e2c: D0000228  adrp     x8, #0x13f000
static inline uint64_t fde_func_1913_0x0f9e20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9e20ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x128b38ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1914 | PC: 0x0f9eb8 | FDE: 0x128b60 | Size: 256 bytes [_ZN11fast_engine11HeapTypeObjC2EPKcPNS_7TypeObjEPNS_6EngineE]
// Hàm FDE #1914 | Địa chỉ PC: 0x0f9eb8 | Địa chỉ FDE: 0x128b60 | Kích thước: 256 bytes
//   0x0f9eb8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0f9ebc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f9ec0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f9ec4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1914_0x0f9eb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9eb8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x128b60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1915 | PC: 0x0f9fd4 | FDE: 0x128020 | Size: 72 bytes [_ZN11fast_engine7TypeObjD0Ev]
// Hàm FDE #1915 | Địa chỉ PC: 0x0f9fd4 | Địa chỉ FDE: 0x128020 | Kích thước: 72 bytes
//   0x0f9fd4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f9fd8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f9fdc: 910043FD  add      x29, sp, #0x10
//   0x0f9fe0: D0000229  adrp     x9, #0x13f000
static inline uint64_t fde_func_1915_0x0f9fd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9fd4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x128020ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1916 | PC: 0x0fa01c | FDE: 0x128040 | Size: 64 bytes [_ZN11fast_engine7TypeObj14LookupBaseTypeEv]
// Hàm FDE #1916 | Địa chỉ PC: 0x0fa01c | Địa chỉ FDE: 0x128040 | Kích thước: 64 bytes
//   0x0fa01c: B40001A0  cbz      x0, #0xfa050
//   0x0fa020: B0000229  adrp     x9, #0x13f000
//   0x0fa024: F9440D29  ldr      x9, [x9, #0x818]
//   0x0fa028: AA0003E8  mov      x8, x0
static inline uint64_t fde_func_1916_0x0fa01c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fa01cULL ^ (static_cast<uint64_t>(0xb40001a0ULL) << 13);
    acc = (acc + a1 + 0xb0000229ULL) ^ 0x128040ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1917 | PC: 0x0fa05c | FDE: 0x128058 | Size: 60 bytes [_ZN11fast_engine7TypeObj9InitCacheEPNS_6EngineE]
// Hàm FDE #1917 | Địa chỉ PC: 0x0fa05c | Địa chỉ FDE: 0x128058 | Kích thước: 60 bytes
//   0x0fa05c: B0000228  adrp     x8, #0x13f000
//   0x0fa060: F944D108  ldr      x8, [x8, #0x9a0]
//   0x0fa064: AA1F03E9  mov      x9, xzr
//   0x0fa068: F9400108  ldr      x8, [x8]
static inline uint64_t fde_func_1917_0x0fa05c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fa05cULL ^ (static_cast<uint64_t>(0xb0000228ULL) << 13);
    acc = (acc + a1 + 0xf944d108ULL) ^ 0x128058ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1918 | PC: 0x0fa098 | FDE: 0x128070 | Size: 160 bytes [_ZN11fast_engine7TypeObj10ClearCacheEPNS_6EngineE]
// Hàm FDE #1918 | Địa chỉ PC: 0x0fa098 | Địa chỉ FDE: 0x128070 | Kích thước: 160 bytes
//   0x0fa098: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0fa09c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0fa0a0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0fa0a4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1918_0x0fa098(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fa098ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x128070ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1919 | PC: 0x0fa138 | FDE: 0x128098 | Size: 188 bytes
// Hàm FDE #1919 | Địa chỉ PC: 0x0fa138 | Địa chỉ FDE: 0x128098 | Kích thước: 188 bytes
//   0x0fa138: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0fa13c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0fa140: 910043FD  add      x29, sp, #0x10
//   0x0fa144: B40003C1  cbz      x1, #0xfa1bc
static inline uint64_t fde_func_1919_0x0fa138(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fa138ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x128098ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1920 | PC: 0x0fa1f4 | FDE: 0x1280b8 | Size: 56 bytes [_ZN11fast_engine7TypeObj9_LookupIdEPS0_PNS_10IdentifierEPNS_6EngineE]
// Hàm FDE #1920 | Địa chỉ PC: 0x0fa1f4 | Địa chỉ FDE: 0x1280b8 | Kích thước: 56 bytes
//   0x0fa1f4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0fa1f8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0fa1fc: 910043FD  add      x29, sp, #0x10
//   0x0fa200: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1920_0x0fa1f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fa1f4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1280b8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1921 | PC: 0x0fa22c | FDE: 0x1280d8 | Size: 48 bytes [_ZN11fast_engine7TypeObj10_LookupRefEPS0_PNS_6StrObjEPNS_6EngineE]
// Hàm FDE #1921 | Địa chỉ PC: 0x0fa22c | Địa chỉ FDE: 0x1280d8 | Kích thước: 48 bytes
//   0x0fa22c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0fa230: 910003FD  mov      x29, sp
//   0x0fa234: 97FD2113  bl       #0x42680
//   0x0fa238: B40000E0  cbz      x0, #0xfa254
static inline uint64_t fde_func_1921_0x0fa22c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fa22cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1280d8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1922 | PC: 0x0fa25c | FDE: 0x1280f8 | Size: 208 bytes [_ZN11fast_engine7TypeObj5ClearEPNS_6EngineE]
// Hàm FDE #1922 | Địa chỉ PC: 0x0fa25c | Địa chỉ FDE: 0x1280f8 | Kích thước: 208 bytes
//   0x0fa25c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0fa260: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0fa264: 910043FD  add      x29, sp, #0x10
//   0x0fa268: F9407408  ldr      x8, [x0, #0xe8]
static inline uint64_t fde_func_1922_0x0fa25c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fa25cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1280f8ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1923 | PC: 0x0fa32c | FDE: 0x128118 | Size: 116 bytes [_ZN11fast_engine11HeapTypeObj5ClearEPNS_6EngineE]
// Hàm FDE #1923 | Địa chỉ PC: 0x0fa32c | Địa chỉ FDE: 0x128118 | Kích thước: 116 bytes
//   0x0fa32c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0fa330: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0fa334: 910043FD  add      x29, sp, #0x10
//   0x0fa338: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1923_0x0fa32c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fa32cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x128118ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1924 | PC: 0x0fa3a0 | FDE: 0x128138 | Size: 256 bytes
// Hàm FDE #1924 | Địa chỉ PC: 0x0fa3a0 | Địa chỉ FDE: 0x128138 | Kích thước: 256 bytes
//   0x0fa3a0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0fa3a4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0fa3a8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0fa3ac: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1924_0x0fa3a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fa3a0ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x128138ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1925 | PC: 0x0fa668 | FDE: 0x128b88 | Size: 232 bytes [_ZN11fast_engine7TypeObj13_InitSlotDefsEPNS_6EngineE]
// Hàm FDE #1925 | Địa chỉ PC: 0x0fa668 | Địa chỉ FDE: 0x128b88 | Kích thước: 232 bytes
//   0x0fa668: D10183FF  sub      sp, sp, #0x60
//   0x0fa66c: F90013F7  str      x23, [sp, #0x20]
//   0x0fa670: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0fa674: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1925_0x0fa668(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fa668ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x128b88ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1926 | PC: 0x0fa750 | FDE: 0x128160 | Size: 176 bytes [_ZN11fast_engine15TypeNewHeapTypeEPNS_7TypeObjEPNS_6EngineE]
// Hàm FDE #1926 | Địa chỉ PC: 0x0fa750 | Địa chỉ FDE: 0x128160 | Kích thước: 176 bytes
//   0x0fa750: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0fa754: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0fa758: 910043FD  add      x29, sp, #0x10
//   0x0fa75c: F9403408  ldr      x8, [x0, #0x68]
static inline uint64_t fde_func_1926_0x0fa750(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fa750ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x128160ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #1927 | PC: 0x0fa800 | FDE: 0x128180 | Size: 80 bytes [_ZN11fast_engine7TypeObj13BuildTypeInitEPS0_PNS_6EngineE]
// Hàm FDE #1927 | Địa chỉ PC: 0x0fa800 | Địa chỉ FDE: 0x128180 | Kích thước: 80 bytes
//   0x0fa800: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0fa804: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0fa808: 910043FD  add      x29, sp, #0x10
//   0x0fa80c: F9405408  ldr      x8, [x0, #0xa8]
static inline uint64_t fde_func_1927_0x0fa800(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fa800ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x128180ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1928 | PC: 0x0fa850 | FDE: 0x1281a0 | Size: 64 bytes [_ZN11fast_engine7TypeObjD2Ev]
// Hàm FDE #1928 | Địa chỉ PC: 0x0fa850 | Địa chỉ FDE: 0x1281a0 | Kích thước: 64 bytes
//   0x0fa850: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0fa854: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0fa858: 910043FD  add      x29, sp, #0x10
//   0x0fa85c: B0000229  adrp     x9, #0x13f000
static inline uint64_t fde_func_1928_0x0fa850(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fa850ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1281a0ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1929 | PC: 0x0fa890 | FDE: 0x1281c0 | Size: 72 bytes [_ZN11fast_engine11HeapTypeObjD0Ev]
// Hàm FDE #1929 | Địa chỉ PC: 0x0fa890 | Địa chỉ FDE: 0x1281c0 | Kích thước: 72 bytes
//   0x0fa890: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0fa894: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0fa898: 910043FD  add      x29, sp, #0x10
//   0x0fa89c: B0000229  adrp     x9, #0x13f000
static inline uint64_t fde_func_1929_0x0fa890(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fa890ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1281c0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1930 | PC: 0x0fa8d8 | FDE: 0x128bb8 | Size: 256 bytes
// Hàm FDE #1930 | Địa chỉ PC: 0x0fa8d8 | Địa chỉ FDE: 0x128bb8 | Kích thước: 256 bytes
//   0x0fa8d8: D101C3FF  sub      sp, sp, #0x70
//   0x0fa8dc: F90013F9  str      x25, [sp, #0x20]
//   0x0fa8e0: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0fa8e4: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1930_0x0fa8d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fa8d8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x128bb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1931 | PC: 0x0faaf4 | FDE: 0x1281e0 | Size: 256 bytes
// Hàm FDE #1931 | Địa chỉ PC: 0x0faaf4 | Địa chỉ FDE: 0x1281e0 | Kích thước: 256 bytes
//   0x0faaf4: D10183FF  sub      sp, sp, #0x60
//   0x0faaf8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0faafc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0fab00: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1931_0x0faaf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0faaf4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x1281e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1932 | PC: 0x0fac2c | FDE: 0x128208 | Size: 172 bytes
// Hàm FDE #1932 | Địa chỉ PC: 0x0fac2c | Địa chỉ FDE: 0x128208 | Kích thước: 172 bytes
//   0x0fac2c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0fac30: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0fac34: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0fac38: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1932_0x0fac2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fac2cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x128208ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1933 | PC: 0x0facd8 | FDE: 0x128be8 | Size: 256 bytes
// Hàm FDE #1933 | Địa chỉ PC: 0x0facd8 | Địa chỉ FDE: 0x128be8 | Kích thước: 256 bytes
//   0x0facd8: D101C3FF  sub      sp, sp, #0x70
//   0x0facdc: F90013F9  str      x25, [sp, #0x20]
//   0x0face0: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0face4: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1933_0x0facd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0facd8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x128be8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1934 | PC: 0x0fafb8 | FDE: 0x128230 | Size: 144 bytes
// Hàm FDE #1934 | Địa chỉ PC: 0x0fafb8 | Địa chỉ FDE: 0x128230 | Kích thước: 144 bytes
//   0x0fafb8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0fafbc: 910003FD  mov      x29, sp
//   0x0fafc0: B0000229  adrp     x9, #0x13f000
//   0x0fafc4: F9401448  ldr      x8, [x2, #0x28]
static inline uint64_t fde_func_1934_0x0fafb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fafb8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x128230ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1935 | PC: 0x0fb048 | FDE: 0x128250 | Size: 256 bytes
// Hàm FDE #1935 | Địa chỉ PC: 0x0fb048 | Địa chỉ FDE: 0x128250 | Kích thước: 256 bytes
//   0x0fb048: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0fb04c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0fb050: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0fb054: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1935_0x0fb048(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb048ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x128250ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1936 | PC: 0x0fb23c | FDE: 0x128c18 | Size: 256 bytes
// Hàm FDE #1936 | Địa chỉ PC: 0x0fb23c | Địa chỉ FDE: 0x128c18 | Kích thước: 256 bytes
//   0x0fb23c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0fb240: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0fb244: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0fb248: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1936_0x0fb23c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb23cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x128c18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1937 | PC: 0x0fb3a0 | FDE: 0x128c40 | Size: 256 bytes
// Hàm FDE #1937 | Địa chỉ PC: 0x0fb3a0 | Địa chỉ FDE: 0x128c40 | Kích thước: 256 bytes
//   0x0fb3a0: D10203FF  sub      sp, sp, #0x80
//   0x0fb3a4: F90013FB  str      x27, [sp, #0x20]
//   0x0fb3a8: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0fb3ac: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1937_0x0fb3a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb3a0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x128c40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1938 | PC: 0x0fb678 | FDE: 0x128270 | Size: 12 bytes
// Hàm FDE #1938 | Địa chỉ PC: 0x0fb678 | Địa chỉ FDE: 0x128270 | Kích thước: 12 bytes
//   0x0fb678: AA0303E5  mov      x5, x3
//   0x0fb67c: AA0403E3  mov      x3, x4
//   0x0fb680: D61F00A0  br       x5
static inline uint64_t fde_func_1938_0x0fb678(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb678ULL ^ (static_cast<uint64_t>(0xaa0303e5ULL) << 13);
    acc = (acc + a1 + 0xaa0403e3ULL) ^ 0x128270ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1939 | PC: 0x0fb684 | FDE: 0x128c78 | Size: 256 bytes
// Hàm FDE #1939 | Địa chỉ PC: 0x0fb684 | Địa chỉ FDE: 0x128c78 | Kích thước: 256 bytes
//   0x0fb684: D101C3FF  sub      sp, sp, #0x70
//   0x0fb688: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0fb68c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0fb690: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1939_0x0fb684(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb684ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x128c78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1940 | PC: 0x0fb810 | FDE: 0x128ca8 | Size: 256 bytes
// Hàm FDE #1940 | Địa chỉ PC: 0x0fb810 | Địa chỉ FDE: 0x128ca8 | Kích thước: 256 bytes
//   0x0fb810: D10203FF  sub      sp, sp, #0x80
//   0x0fb814: F90013FB  str      x27, [sp, #0x20]
//   0x0fb818: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0fb81c: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1940_0x0fb810(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb810ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x128ca8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1941 | PC: 0x0fbb90 | FDE: 0x128288 | Size: 160 bytes
// Hàm FDE #1941 | Địa chỉ PC: 0x0fbb90 | Địa chỉ FDE: 0x128288 | Kích thước: 160 bytes
//   0x0fbb90: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0fbb94: 910003FD  mov      x29, sp
//   0x0fbb98: 90000229  adrp     x9, #0x13f000
//   0x0fbb9c: F9401448  ldr      x8, [x2, #0x28]
static inline uint64_t fde_func_1941_0x0fbb90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fbb90ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x128288ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1942 | PC: 0x0fbc30 | FDE: 0x128ce0 | Size: 256 bytes
// Hàm FDE #1942 | Địa chỉ PC: 0x0fbc30 | Địa chỉ FDE: 0x128ce0 | Kích thước: 256 bytes
//   0x0fbc30: D10283FF  sub      sp, sp, #0xa0
//   0x0fbc34: F90023FB  str      x27, [sp, #0x40]
//   0x0fbc38: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0fbc3c: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1942_0x0fbc30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fbc30ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90023fbULL) ^ 0x128ce0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1943 | PC: 0x0fbf50 | FDE: 0x1282a8 | Size: 168 bytes
// Hàm FDE #1943 | Địa chỉ PC: 0x0fbf50 | Địa chỉ FDE: 0x1282a8 | Kích thước: 168 bytes
//   0x0fbf50: D10143FF  sub      sp, sp, #0x50
//   0x0fbf54: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0fbf58: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0fbf5c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1943_0x0fbf50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fbf50ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1282a8ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1944 | PC: 0x0fbff8 | FDE: 0x1282d0 | Size: 192 bytes
// Hàm FDE #1944 | Địa chỉ PC: 0x0fbff8 | Địa chỉ FDE: 0x1282d0 | Kích thước: 192 bytes
//   0x0fbff8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0fbffc: 910003FD  mov      x29, sp
//   0x0fc000: F000020A  adrp     x10, #0x13f000
//   0x0fc004: F9401448  ldr      x8, [x2, #0x28]
static inline uint64_t fde_func_1944_0x0fbff8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fbff8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1282d0ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1945 | PC: 0x0fc0b8 | FDE: 0x128d18 | Size: 256 bytes
// Hàm FDE #1945 | Địa chỉ PC: 0x0fc0b8 | Địa chỉ FDE: 0x128d18 | Kích thước: 256 bytes
//   0x0fc0b8: D10203FF  sub      sp, sp, #0x80
//   0x0fc0bc: F90013FB  str      x27, [sp, #0x20]
//   0x0fc0c0: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0fc0c4: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1945_0x0fc0b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fc0b8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x128d18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1946 | PC: 0x0fc91c | FDE: 0x1282f0 | Size: 168 bytes
// Hàm FDE #1946 | Địa chỉ PC: 0x0fc91c | Địa chỉ FDE: 0x1282f0 | Kích thước: 168 bytes
//   0x0fc91c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0fc920: 910003FD  mov      x29, sp
//   0x0fc924: F0000209  adrp     x9, #0x13f000
//   0x0fc928: F9401448  ldr      x8, [x2, #0x28]
static inline uint64_t fde_func_1946_0x0fc91c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fc91cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1282f0ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1947 | PC: 0x0fc9c4 | FDE: 0x128310 | Size: 168 bytes
// Hàm FDE #1947 | Địa chỉ PC: 0x0fc9c4 | Địa chỉ FDE: 0x128310 | Kích thước: 168 bytes
//   0x0fc9c4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0fc9c8: 910003FD  mov      x29, sp
//   0x0fc9cc: F0000209  adrp     x9, #0x13f000
//   0x0fc9d0: F9401448  ldr      x8, [x2, #0x28]
static inline uint64_t fde_func_1947_0x0fc9c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fc9c4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x128310ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1948 | PC: 0x0fca6c | FDE: 0x128330 | Size: 168 bytes
// Hàm FDE #1948 | Địa chỉ PC: 0x0fca6c | Địa chỉ FDE: 0x128330 | Kích thước: 168 bytes
//   0x0fca6c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0fca70: 910003FD  mov      x29, sp
//   0x0fca74: F0000209  adrp     x9, #0x13f000
//   0x0fca78: F9401448  ldr      x8, [x2, #0x28]
static inline uint64_t fde_func_1948_0x0fca6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fca6cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x128330ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1949 | PC: 0x0fcb14 | FDE: 0x128350 | Size: 168 bytes
// Hàm FDE #1949 | Địa chỉ PC: 0x0fcb14 | Địa chỉ FDE: 0x128350 | Kích thước: 168 bytes
//   0x0fcb14: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0fcb18: 910003FD  mov      x29, sp
//   0x0fcb1c: F0000209  adrp     x9, #0x13f000
//   0x0fcb20: F9401448  ldr      x8, [x2, #0x28]
static inline uint64_t fde_func_1949_0x0fcb14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fcb14ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x128350ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1950 | PC: 0x0fcbbc | FDE: 0x128370 | Size: 168 bytes
// Hàm FDE #1950 | Địa chỉ PC: 0x0fcbbc | Địa chỉ FDE: 0x128370 | Kích thước: 168 bytes
//   0x0fcbbc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0fcbc0: 910003FD  mov      x29, sp
//   0x0fcbc4: F0000209  adrp     x9, #0x13f000
//   0x0fcbc8: F9401448  ldr      x8, [x2, #0x28]
static inline uint64_t fde_func_1950_0x0fcbbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fcbbcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x128370ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1951 | PC: 0x0fcc64 | FDE: 0x128390 | Size: 168 bytes
// Hàm FDE #1951 | Địa chỉ PC: 0x0fcc64 | Địa chỉ FDE: 0x128390 | Kích thước: 168 bytes
//   0x0fcc64: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0fcc68: 910003FD  mov      x29, sp
//   0x0fcc6c: F0000209  adrp     x9, #0x13f000
//   0x0fcc70: F9401448  ldr      x8, [x2, #0x28]
static inline uint64_t fde_func_1951_0x0fcc64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fcc64ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x128390ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1952 | PC: 0x0fcd0c | FDE: 0x128d50 | Size: 256 bytes
// Hàm FDE #1952 | Địa chỉ PC: 0x0fcd0c | Địa chỉ FDE: 0x128d50 | Kích thước: 256 bytes
//   0x0fcd0c: D101C3FF  sub      sp, sp, #0x70
//   0x0fcd10: F90013F9  str      x25, [sp, #0x20]
//   0x0fcd14: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0fcd18: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1952_0x0fcd0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fcd0cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x128d50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1953 | PC: 0x0fd0a0 | FDE: 0x128d80 | Size: 256 bytes
// Hàm FDE #1953 | Địa chỉ PC: 0x0fd0a0 | Địa chỉ FDE: 0x128d80 | Kích thước: 256 bytes
//   0x0fd0a0: D101C3FF  sub      sp, sp, #0x70
//   0x0fd0a4: F90013F9  str      x25, [sp, #0x20]
//   0x0fd0a8: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0fd0ac: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1953_0x0fd0a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fd0a0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x128d80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1954 | PC: 0x0fd238 | FDE: 0x1283b0 | Size: 216 bytes
// Hàm FDE #1954 | Địa chỉ PC: 0x0fd238 | Địa chỉ FDE: 0x1283b0 | Kích thước: 216 bytes
//   0x0fd238: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0fd23c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0fd240: 910043FD  add      x29, sp, #0x10
//   0x0fd244: D0000209  adrp     x9, #0x13f000
static inline uint64_t fde_func_1954_0x0fd238(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fd238ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1283b0ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1955 | PC: 0x0fd310 | FDE: 0x128db0 | Size: 256 bytes
// Hàm FDE #1955 | Địa chỉ PC: 0x0fd310 | Địa chỉ FDE: 0x128db0 | Kích thước: 256 bytes
//   0x0fd310: D10203FF  sub      sp, sp, #0x80
//   0x0fd314: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0fd318: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0fd31c: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1955_0x0fd310(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fd310ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x128db0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1956 | PC: 0x0fd530 | FDE: 0x1283d0 | Size: 252 bytes
// Hàm FDE #1956 | Địa chỉ PC: 0x0fd530 | Địa chỉ FDE: 0x1283d0 | Kích thước: 252 bytes
//   0x0fd530: D10143FF  sub      sp, sp, #0x50
//   0x0fd534: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0fd538: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0fd53c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1956_0x0fd530(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fd530ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1283d0ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1957 | PC: 0x0fd62c | FDE: 0x128de8 | Size: 256 bytes
// Hàm FDE #1957 | Địa chỉ PC: 0x0fd62c | Địa chỉ FDE: 0x128de8 | Kích thước: 256 bytes
//   0x0fd62c: D10283FF  sub      sp, sp, #0xa0
//   0x0fd630: F90023FB  str      x27, [sp, #0x40]
//   0x0fd634: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0fd638: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1957_0x0fd62c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fd62cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90023fbULL) ^ 0x128de8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1958 | PC: 0x0fd94c | FDE: 0x1283f8 | Size: 168 bytes
// Hàm FDE #1958 | Địa chỉ PC: 0x0fd94c | Địa chỉ FDE: 0x1283f8 | Kích thước: 168 bytes
//   0x0fd94c: D10143FF  sub      sp, sp, #0x50
//   0x0fd950: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0fd954: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0fd958: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1958_0x0fd94c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fd94cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1283f8ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1959 | PC: 0x0fd9f4 | FDE: 0x128420 | Size: 192 bytes
// Hàm FDE #1959 | Địa chỉ PC: 0x0fd9f4 | Địa chỉ FDE: 0x128420 | Kích thước: 192 bytes
//   0x0fd9f4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0fd9f8: 910003FD  mov      x29, sp
//   0x0fd9fc: D000020A  adrp     x10, #0x13f000
//   0x0fda00: F9401448  ldr      x8, [x2, #0x28]
static inline uint64_t fde_func_1959_0x0fd9f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fd9f4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x128420ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1960 | PC: 0x0fdab4 | FDE: 0x128e20 | Size: 256 bytes
// Hàm FDE #1960 | Địa chỉ PC: 0x0fdab4 | Địa chỉ FDE: 0x128e20 | Kích thước: 256 bytes
//   0x0fdab4: D10203FF  sub      sp, sp, #0x80
//   0x0fdab8: F90013FB  str      x27, [sp, #0x20]
//   0x0fdabc: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0fdac0: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1960_0x0fdab4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fdab4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x128e20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1961 | PC: 0x0fde14 | FDE: 0x128440 | Size: 48 bytes
// Hàm FDE #1961 | Địa chỉ PC: 0x0fde14 | Địa chỉ FDE: 0x128440 | Kích thước: 48 bytes
//   0x0fde14: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0fde18: 910003FD  mov      x29, sp
//   0x0fde1c: AA0303E8  mov      x8, x3
//   0x0fde20: AA0403E3  mov      x3, x4
static inline uint64_t fde_func_1961_0x0fde14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fde14ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x128440ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1962 | PC: 0x0fde44 | FDE: 0x128e58 | Size: 256 bytes
// Hàm FDE #1962 | Địa chỉ PC: 0x0fde44 | Địa chỉ FDE: 0x128e58 | Kích thước: 256 bytes
//   0x0fde44: D10203FF  sub      sp, sp, #0x80
//   0x0fde48: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0fde4c: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0fde50: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1962_0x0fde44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fde44ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90367faULL) ^ 0x128e58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1963 | PC: 0x0fe310 | FDE: 0x128460 | Size: 160 bytes
// Hàm FDE #1963 | Địa chỉ PC: 0x0fe310 | Địa chỉ FDE: 0x128460 | Kích thước: 160 bytes
//   0x0fe310: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0fe314: 910003FD  mov      x29, sp
//   0x0fe318: B0000209  adrp     x9, #0x13f000
//   0x0fe31c: F9401448  ldr      x8, [x2, #0x28]
static inline uint64_t fde_func_1963_0x0fe310(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fe310ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x128460ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1964 | PC: 0x0fe3b0 | FDE: 0x128480 | Size: 152 bytes
// Hàm FDE #1964 | Địa chỉ PC: 0x0fe3b0 | Địa chỉ FDE: 0x128480 | Kích thước: 152 bytes
//   0x0fe3b0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0fe3b4: 910003FD  mov      x29, sp
//   0x0fe3b8: B0000209  adrp     x9, #0x13f000
//   0x0fe3bc: F9401448  ldr      x8, [x2, #0x28]
static inline uint64_t fde_func_1964_0x0fe3b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fe3b0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x128480ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1965 | PC: 0x0fe448 | FDE: 0x128e90 | Size: 256 bytes
// Hàm FDE #1965 | Địa chỉ PC: 0x0fe448 | Địa chỉ FDE: 0x128e90 | Kích thước: 256 bytes
//   0x0fe448: D10203FF  sub      sp, sp, #0x80
//   0x0fe44c: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0fe450: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0fe454: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1965_0x0fe448(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fe448ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90367faULL) ^ 0x128e90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1966 | PC: 0x0fe914 | FDE: 0x128ec8 | Size: 256 bytes
// Hàm FDE #1966 | Địa chỉ PC: 0x0fe914 | Địa chỉ FDE: 0x128ec8 | Kích thước: 256 bytes
//   0x0fe914: D10203FF  sub      sp, sp, #0x80
//   0x0fe918: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0fe91c: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0fe920: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1966_0x0fe914(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fe914ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90367faULL) ^ 0x128ec8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1967 | PC: 0x0fede0 | FDE: 0x128f00 | Size: 256 bytes
// Hàm FDE #1967 | Địa chỉ PC: 0x0fede0 | Địa chỉ FDE: 0x128f00 | Kích thước: 256 bytes
//   0x0fede0: D10203FF  sub      sp, sp, #0x80
//   0x0fede4: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0fede8: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0fedec: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1967_0x0fede0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fede0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90367faULL) ^ 0x128f00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1968 | PC: 0x0ff2ac | FDE: 0x128f38 | Size: 256 bytes
// Hàm FDE #1968 | Địa chỉ PC: 0x0ff2ac | Địa chỉ FDE: 0x128f38 | Kích thước: 256 bytes
//   0x0ff2ac: D10203FF  sub      sp, sp, #0x80
//   0x0ff2b0: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0ff2b4: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0ff2b8: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1968_0x0ff2ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ff2acULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90367faULL) ^ 0x128f38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1969 | PC: 0x0ff778 | FDE: 0x128f70 | Size: 256 bytes
// Hàm FDE #1969 | Địa chỉ PC: 0x0ff778 | Địa chỉ FDE: 0x128f70 | Kích thước: 256 bytes
//   0x0ff778: D10203FF  sub      sp, sp, #0x80
//   0x0ff77c: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0ff780: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0ff784: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1969_0x0ff778(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ff778ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90367faULL) ^ 0x128f70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1970 | PC: 0x0ffc44 | FDE: 0x128fa8 | Size: 256 bytes
// Hàm FDE #1970 | Địa chỉ PC: 0x0ffc44 | Địa chỉ FDE: 0x128fa8 | Kích thước: 256 bytes
//   0x0ffc44: D101C3FF  sub      sp, sp, #0x70
//   0x0ffc48: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0ffc4c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0ffc50: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1970_0x0ffc44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ffc44ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x128fa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1971 | PC: 0x0ffdd0 | FDE: 0x128fd8 | Size: 256 bytes
// Hàm FDE #1971 | Địa chỉ PC: 0x0ffdd0 | Địa chỉ FDE: 0x128fd8 | Kích thước: 256 bytes
//   0x0ffdd0: D101C3FF  sub      sp, sp, #0x70
//   0x0ffdd4: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0ffdd8: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0ffddc: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1971_0x0ffdd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ffdd0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x128fd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1972 | PC: 0x0fff5c | FDE: 0x129008 | Size: 256 bytes
// Hàm FDE #1972 | Địa chỉ PC: 0x0fff5c | Địa chỉ FDE: 0x129008 | Kích thước: 256 bytes
//   0x0fff5c: D101C3FF  sub      sp, sp, #0x70
//   0x0fff60: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0fff64: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0fff68: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1972_0x0fff5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fff5cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x129008ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1973 | PC: 0x1000e8 | FDE: 0x129038 | Size: 256 bytes
// Hàm FDE #1973 | Địa chỉ PC: 0x1000e8 | Địa chỉ FDE: 0x129038 | Kích thước: 256 bytes
//   0x1000e8: D101C3FF  sub      sp, sp, #0x70
//   0x1000ec: F90013F9  str      x25, [sp, #0x20]
//   0x1000f0: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x1000f4: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1973_0x1000e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1000e8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x129038ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1974 | PC: 0x1004f8 | FDE: 0x1284a0 | Size: 176 bytes
// Hàm FDE #1974 | Địa chỉ PC: 0x1004f8 | Địa chỉ FDE: 0x1284a0 | Kích thước: 176 bytes
//   0x1004f8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1004fc: 910003FD  mov      x29, sp
//   0x100500: F00001E9  adrp     x9, #0x13f000
//   0x100504: F9401448  ldr      x8, [x2, #0x28]
static inline uint64_t fde_func_1974_0x1004f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1004f8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1284a0ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #1975 | PC: 0x1005a8 | FDE: 0x129068 | Size: 256 bytes
// Hàm FDE #1975 | Địa chỉ PC: 0x1005a8 | Địa chỉ FDE: 0x129068 | Kích thước: 256 bytes
//   0x1005a8: D101C3FF  sub      sp, sp, #0x70
//   0x1005ac: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x1005b0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x1005b4: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1975_0x1005a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1005a8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x129068ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1976 | PC: 0x100734 | FDE: 0x129098 | Size: 256 bytes
// Hàm FDE #1976 | Địa chỉ PC: 0x100734 | Địa chỉ FDE: 0x129098 | Kích thước: 256 bytes
//   0x100734: D10203FF  sub      sp, sp, #0x80
//   0x100738: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x10073c: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x100740: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1976_0x100734(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x100734ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90367faULL) ^ 0x129098ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1977 | PC: 0x100c00 | FDE: 0x1290d0 | Size: 256 bytes
// Hàm FDE #1977 | Địa chỉ PC: 0x100c00 | Địa chỉ FDE: 0x1290d0 | Kích thước: 256 bytes
//   0x100c00: D10203FF  sub      sp, sp, #0x80
//   0x100c04: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x100c08: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x100c0c: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1977_0x100c00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x100c00ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90367faULL) ^ 0x1290d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1978 | PC: 0x1010cc | FDE: 0x129108 | Size: 256 bytes
// Hàm FDE #1978 | Địa chỉ PC: 0x1010cc | Địa chỉ FDE: 0x129108 | Kích thước: 256 bytes
//   0x1010cc: D10203FF  sub      sp, sp, #0x80
//   0x1010d0: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x1010d4: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x1010d8: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1978_0x1010cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1010ccULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90367faULL) ^ 0x129108ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1979 | PC: 0x101598 | FDE: 0x129140 | Size: 256 bytes
// Hàm FDE #1979 | Địa chỉ PC: 0x101598 | Địa chỉ FDE: 0x129140 | Kích thước: 256 bytes
//   0x101598: D10203FF  sub      sp, sp, #0x80
//   0x10159c: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x1015a0: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x1015a4: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1979_0x101598(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x101598ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90367faULL) ^ 0x129140ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1980 | PC: 0x101a64 | FDE: 0x129178 | Size: 256 bytes
// Hàm FDE #1980 | Địa chỉ PC: 0x101a64 | Địa chỉ FDE: 0x129178 | Kích thước: 256 bytes
//   0x101a64: D10203FF  sub      sp, sp, #0x80
//   0x101a68: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x101a6c: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x101a70: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1980_0x101a64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x101a64ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90367faULL) ^ 0x129178ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1981 | PC: 0x101f30 | FDE: 0x1291b0 | Size: 256 bytes
// Hàm FDE #1981 | Địa chỉ PC: 0x101f30 | Địa chỉ FDE: 0x1291b0 | Kích thước: 256 bytes
//   0x101f30: D101C3FF  sub      sp, sp, #0x70
//   0x101f34: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x101f38: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x101f3c: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1981_0x101f30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x101f30ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x1291b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1982 | PC: 0x1020bc | FDE: 0x1291e0 | Size: 256 bytes
// Hàm FDE #1982 | Địa chỉ PC: 0x1020bc | Địa chỉ FDE: 0x1291e0 | Kích thước: 256 bytes
//   0x1020bc: D101C3FF  sub      sp, sp, #0x70
//   0x1020c0: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x1020c4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x1020c8: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1982_0x1020bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1020bcULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x1291e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1983 | PC: 0x102248 | FDE: 0x129210 | Size: 256 bytes
// Hàm FDE #1983 | Địa chỉ PC: 0x102248 | Địa chỉ FDE: 0x129210 | Kích thước: 256 bytes
//   0x102248: D101C3FF  sub      sp, sp, #0x70
//   0x10224c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x102250: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x102254: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1983_0x102248(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x102248ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x129210ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1984 | PC: 0x1023d4 | FDE: 0x129240 | Size: 256 bytes
// Hàm FDE #1984 | Địa chỉ PC: 0x1023d4 | Địa chỉ FDE: 0x129240 | Kích thước: 256 bytes
//   0x1023d4: D101C3FF  sub      sp, sp, #0x70
//   0x1023d8: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x1023dc: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x1023e0: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1984_0x1023d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1023d4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x129240ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1985 | PC: 0x102560 | FDE: 0x129270 | Size: 256 bytes
// Hàm FDE #1985 | Địa chỉ PC: 0x102560 | Địa chỉ FDE: 0x129270 | Kích thước: 256 bytes
//   0x102560: D101C3FF  sub      sp, sp, #0x70
//   0x102564: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x102568: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x10256c: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1985_0x102560(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x102560ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x129270ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1986 | PC: 0x1026ec | FDE: 0x1292a0 | Size: 256 bytes
// Hàm FDE #1986 | Địa chỉ PC: 0x1026ec | Địa chỉ FDE: 0x1292a0 | Kích thước: 256 bytes
//   0x1026ec: D101C3FF  sub      sp, sp, #0x70
//   0x1026f0: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x1026f4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x1026f8: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1986_0x1026ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1026ecULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x1292a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1987 | PC: 0x102878 | FDE: 0x1292d0 | Size: 256 bytes
// Hàm FDE #1987 | Địa chỉ PC: 0x102878 | Địa chỉ FDE: 0x1292d0 | Kích thước: 256 bytes
//   0x102878: D101C3FF  sub      sp, sp, #0x70
//   0x10287c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x102880: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x102884: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1987_0x102878(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x102878ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x1292d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1988 | PC: 0x102a04 | FDE: 0x129300 | Size: 256 bytes
// Hàm FDE #1988 | Địa chỉ PC: 0x102a04 | Địa chỉ FDE: 0x129300 | Kích thước: 256 bytes
//   0x102a04: D101C3FF  sub      sp, sp, #0x70
//   0x102a08: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x102a0c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x102a10: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1988_0x102a04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x102a04ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x129300ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1989 | PC: 0x102b90 | FDE: 0x129330 | Size: 256 bytes
// Hàm FDE #1989 | Địa chỉ PC: 0x102b90 | Địa chỉ FDE: 0x129330 | Kích thước: 256 bytes
//   0x102b90: D101C3FF  sub      sp, sp, #0x70
//   0x102b94: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x102b98: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x102b9c: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1989_0x102b90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x102b90ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x129330ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1990 | PC: 0x102d1c | FDE: 0x129360 | Size: 256 bytes
// Hàm FDE #1990 | Địa chỉ PC: 0x102d1c | Địa chỉ FDE: 0x129360 | Kích thước: 256 bytes
//   0x102d1c: D101C3FF  sub      sp, sp, #0x70
//   0x102d20: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x102d24: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x102d28: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1990_0x102d1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x102d1cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x129360ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1991 | PC: 0x102ea8 | FDE: 0x129390 | Size: 256 bytes
// Hàm FDE #1991 | Địa chỉ PC: 0x102ea8 | Địa chỉ FDE: 0x129390 | Kích thước: 256 bytes
//   0x102ea8: D101C3FF  sub      sp, sp, #0x70
//   0x102eac: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x102eb0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x102eb4: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1991_0x102ea8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x102ea8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x129390ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1992 | PC: 0x103034 | FDE: 0x1293c0 | Size: 256 bytes
// Hàm FDE #1992 | Địa chỉ PC: 0x103034 | Địa chỉ FDE: 0x1293c0 | Kích thước: 256 bytes
//   0x103034: D101C3FF  sub      sp, sp, #0x70
//   0x103038: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x10303c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x103040: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1992_0x103034(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x103034ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x1293c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1993 | PC: 0x1031c0 | FDE: 0x1293f0 | Size: 256 bytes
// Hàm FDE #1993 | Địa chỉ PC: 0x1031c0 | Địa chỉ FDE: 0x1293f0 | Kích thước: 256 bytes
//   0x1031c0: D10203FF  sub      sp, sp, #0x80
//   0x1031c4: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x1031c8: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x1031cc: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1993_0x1031c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1031c0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90367faULL) ^ 0x1293f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1994 | PC: 0x10368c | FDE: 0x129428 | Size: 256 bytes
// Hàm FDE #1994 | Địa chỉ PC: 0x10368c | Địa chỉ FDE: 0x129428 | Kích thước: 256 bytes
//   0x10368c: D10203FF  sub      sp, sp, #0x80
//   0x103690: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x103694: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x103698: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1994_0x10368c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10368cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90367faULL) ^ 0x129428ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1995 | PC: 0x103b58 | FDE: 0x129460 | Size: 256 bytes
// Hàm FDE #1995 | Địa chỉ PC: 0x103b58 | Địa chỉ FDE: 0x129460 | Kích thước: 256 bytes
//   0x103b58: D101C3FF  sub      sp, sp, #0x70
//   0x103b5c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x103b60: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x103b64: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1995_0x103b58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x103b58ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x129460ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1996 | PC: 0x103ce4 | FDE: 0x129490 | Size: 256 bytes
// Hàm FDE #1996 | Địa chỉ PC: 0x103ce4 | Địa chỉ FDE: 0x129490 | Kích thước: 256 bytes
//   0x103ce4: D10203FF  sub      sp, sp, #0x80
//   0x103ce8: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x103cec: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x103cf0: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1996_0x103ce4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x103ce4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90367faULL) ^ 0x129490ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1997 | PC: 0x1041b0 | FDE: 0x1294c8 | Size: 256 bytes
// Hàm FDE #1997 | Địa chỉ PC: 0x1041b0 | Địa chỉ FDE: 0x1294c8 | Kích thước: 256 bytes
//   0x1041b0: D101C3FF  sub      sp, sp, #0x70
//   0x1041b4: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x1041b8: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x1041bc: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1997_0x1041b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1041b0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x1294c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1998 | PC: 0x10433c | FDE: 0x1284c0 | Size: 256 bytes
// Hàm FDE #1998 | Địa chỉ PC: 0x10433c | Địa chỉ FDE: 0x1284c0 | Kích thước: 256 bytes
//   0x10433c: D10103FF  sub      sp, sp, #0x40
//   0x104340: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x104344: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x104348: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1998_0x10433c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10433cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1284c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1999 | PC: 0x10449c | FDE: 0x1294f8 | Size: 256 bytes
// Hàm FDE #1999 | Địa chỉ PC: 0x10449c | Địa chỉ FDE: 0x1294f8 | Kích thước: 256 bytes
//   0x10449c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1044a0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1044a4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1044a8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1999_0x10449c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10449cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1294f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2000 | PC: 0x104600 | FDE: 0x129520 | Size: 256 bytes
// Hàm FDE #2000 | Địa chỉ PC: 0x104600 | Địa chỉ FDE: 0x129520 | Kích thước: 256 bytes
//   0x104600: D101C3FF  sub      sp, sp, #0x70
//   0x104604: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x104608: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x10460c: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_2000_0x104600(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x104600ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x129520ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2001 | PC: 0x10478c | FDE: 0x1284e8 | Size: 192 bytes
// Hàm FDE #2001 | Địa chỉ PC: 0x10478c | Địa chỉ FDE: 0x1284e8 | Kích thước: 192 bytes
//   0x10478c: D10103FF  sub      sp, sp, #0x40
//   0x104790: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x104794: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x104798: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_2001_0x10478c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10478cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x1284e8ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #2002 | PC: 0x10484c | FDE: 0x128508 | Size: 188 bytes
// Hàm FDE #2002 | Địa chỉ PC: 0x10484c | Địa chỉ FDE: 0x128508 | Kích thước: 188 bytes
//   0x10484c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x104850: 910003FD  mov      x29, sp
//   0x104854: F00001CA  adrp     x10, #0x13f000
//   0x104858: F9401448  ldr      x8, [x2, #0x28]
static inline uint64_t fde_func_2002_0x10484c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10484cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x128508ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #2003 | PC: 0x104908 | FDE: 0x128528 | Size: 184 bytes
// Hàm FDE #2003 | Địa chỉ PC: 0x104908 | Địa chỉ FDE: 0x128528 | Kích thước: 184 bytes
//   0x104908: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x10490c: 910003FD  mov      x29, sp
//   0x104910: F00001CA  adrp     x10, #0x13f000
//   0x104914: F9401448  ldr      x8, [x2, #0x28]
static inline uint64_t fde_func_2003_0x104908(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x104908ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x128528ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #2004 | PC: 0x1049c0 | FDE: 0x128548 | Size: 236 bytes
// Hàm FDE #2004 | Địa chỉ PC: 0x1049c0 | Địa chỉ FDE: 0x128548 | Kích thước: 236 bytes
//   0x1049c0: D100C3FF  sub      sp, sp, #0x30
//   0x1049c4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1049c8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1049cc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2004_0x1049c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1049c0ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x128548ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #2005 | PC: 0x104aac | FDE: 0x129550 | Size: 256 bytes
// Hàm FDE #2005 | Địa chỉ PC: 0x104aac | Địa chỉ FDE: 0x129550 | Kích thước: 256 bytes
//   0x104aac: D10183FF  sub      sp, sp, #0x60
//   0x104ab0: F90013F7  str      x23, [sp, #0x20]
//   0x104ab4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x104ab8: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_2005_0x104aac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x104aacULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x129550ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2006 | PC: 0x104c04 | FDE: 0x128568 | Size: 256 bytes
// Hàm FDE #2006 | Địa chỉ PC: 0x104c04 | Địa chỉ FDE: 0x128568 | Kích thước: 256 bytes
//   0x104c04: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x104c08: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x104c0c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x104c10: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2006_0x104c04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x104c04ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x128568ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2007 | PC: 0x104d40 | FDE: 0x129580 | Size: 256 bytes
// Hàm FDE #2007 | Địa chỉ PC: 0x104d40 | Địa chỉ FDE: 0x129580 | Kích thước: 256 bytes
//   0x104d40: D10183FF  sub      sp, sp, #0x60
//   0x104d44: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x104d48: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x104d4c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_2007_0x104d40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x104d40ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x129580ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2008 | PC: 0x104ef8 | FDE: 0x128588 | Size: 256 bytes
// Hàm FDE #2008 | Địa chỉ PC: 0x104ef8 | Địa chỉ FDE: 0x128588 | Kích thước: 256 bytes
//   0x104ef8: D10183FF  sub      sp, sp, #0x60
//   0x104efc: F90013F7  str      x23, [sp, #0x20]
//   0x104f00: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x104f04: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_2008_0x104ef8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x104ef8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x128588ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2009 | PC: 0x105020 | FDE: 0x1285b0 | Size: 256 bytes
// Hàm FDE #2009 | Địa chỉ PC: 0x105020 | Địa chỉ FDE: 0x1285b0 | Kích thước: 256 bytes
//   0x105020: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x105024: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x105028: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x10502c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2009_0x105020(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x105020ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1285b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2010 | PC: 0x10516c | FDE: 0x1295b0 | Size: 256 bytes
// Hàm FDE #2010 | Địa chỉ PC: 0x10516c | Địa chỉ FDE: 0x1295b0 | Kích thước: 256 bytes
//   0x10516c: D101C3FF  sub      sp, sp, #0x70
//   0x105170: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x105174: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x105178: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_2010_0x10516c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10516cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x1295b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2011 | PC: 0x1054fc | FDE: 0x1285d8 | Size: 192 bytes
// Hàm FDE #2011 | Địa chỉ PC: 0x1054fc | Địa chỉ FDE: 0x1285d8 | Kích thước: 192 bytes
//   0x1054fc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x105500: 910003FD  mov      x29, sp
//   0x105504: D00001C9  adrp     x9, #0x13f000
//   0x105508: F9401448  ldr      x8, [x2, #0x28]
static inline uint64_t fde_func_2011_0x1054fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1054fcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1285d8ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #2012 | PC: 0x1055bc | FDE: 0x1285f8 | Size: 200 bytes
// Hàm FDE #2012 | Địa chỉ PC: 0x1055bc | Địa chỉ FDE: 0x1285f8 | Kích thước: 200 bytes
//   0x1055bc: D10103FF  sub      sp, sp, #0x40
//   0x1055c0: F90013F3  str      x19, [sp, #0x20]
//   0x1055c4: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x1055c8: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_2012_0x1055bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1055bcULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x1285f8ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #2013 | PC: 0x105684 | FDE: 0x128618 | Size: 256 bytes
// Hàm FDE #2013 | Địa chỉ PC: 0x105684 | Địa chỉ FDE: 0x128618 | Kích thước: 256 bytes
//   0x105684: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x105688: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x10568c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x105690: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2013_0x105684(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x105684ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x128618ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2014 | PC: 0x10580c | FDE: 0x128640 | Size: 100 bytes
// Hàm FDE #2014 | Địa chỉ PC: 0x10580c | Địa chỉ FDE: 0x128640 | Kích thước: 100 bytes
//   0x10580c: D10103FF  sub      sp, sp, #0x40
//   0x105810: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x105814: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x105818: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_2014_0x10580c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10580cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x128640ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #2015 | PC: 0x105870 | FDE: 0x128660 | Size: 256 bytes
// Hàm FDE #2015 | Địa chỉ PC: 0x105870 | Địa chỉ FDE: 0x128660 | Kích thước: 256 bytes
//   0x105870: D10143FF  sub      sp, sp, #0x50
//   0x105874: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x105878: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x10587c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_2015_0x105870(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x105870ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x128660ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2016 | PC: 0x105988 | FDE: 0x128688 | Size: 256 bytes
// Hàm FDE #2016 | Địa chỉ PC: 0x105988 | Địa chỉ FDE: 0x128688 | Kích thước: 256 bytes
//   0x105988: D10143FF  sub      sp, sp, #0x50
//   0x10598c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x105990: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x105994: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_2016_0x105988(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x105988ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x128688ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2017 | PC: 0x105afc | FDE: 0x1286b0 | Size: 208 bytes
// Hàm FDE #2017 | Địa chỉ PC: 0x105afc | Địa chỉ FDE: 0x1286b0 | Kích thước: 208 bytes
//   0x105afc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x105b00: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x105b04: 910043FD  add      x29, sp, #0x10
//   0x105b08: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_2017_0x105afc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x105afcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1286b0ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #2018 | PC: 0x105bcc | FDE: 0x1286d0 | Size: 256 bytes
// Hàm FDE #2018 | Địa chỉ PC: 0x105bcc | Địa chỉ FDE: 0x1286d0 | Kích thước: 256 bytes
//   0x105bcc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x105bd0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x105bd4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x105bd8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2018_0x105bcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x105bccULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1286d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2019 | PC: 0x105d94 | FDE: 0x1295e8 | Size: 256 bytes
// Hàm FDE #2019 | Địa chỉ PC: 0x105d94 | Địa chỉ FDE: 0x1295e8 | Kích thước: 256 bytes
//   0x105d94: D101C3FF  sub      sp, sp, #0x70
//   0x105d98: F90013F9  str      x25, [sp, #0x20]
//   0x105d9c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x105da0: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_2019_0x105d94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x105d94ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x1295e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2020 | PC: 0x1062e0 | FDE: 0x129630 | Size: 40 bytes
// Hàm FDE #2020 | Địa chỉ PC: 0x1062e0 | Địa chỉ FDE: 0x129630 | Kích thước: 40 bytes
//   0x1062e0: D2800002  mov      x2, #0
//   0x1062e4: 52800003  mov      w3, #0
//   0x1062e8: 38401405  ldrb     w5, [x0], #1
//   0x1062ec: 924018A4  and      x4, x5, #0x7f
static inline uint64_t fde_func_2020_0x1062e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1062e0ULL ^ (static_cast<uint64_t>(0xd2800002ULL) << 13);
    acc = (acc + a1 + 0x52800003ULL) ^ 0x129630ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #2021 | PC: 0x106308 | FDE: 0x129648 | Size: 64 bytes
// Hàm FDE #2021 | Địa chỉ PC: 0x106308 | Địa chỉ FDE: 0x129648 | Kích thước: 64 bytes
//   0x106308: D2800002  mov      x2, #0
//   0x10630c: 52800003  mov      w3, #0
//   0x106310: 38401404  ldrb     w4, [x0], #1
//   0x106314: 92401885  and      x5, x4, #0x7f
static inline uint64_t fde_func_2021_0x106308(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x106308ULL ^ (static_cast<uint64_t>(0xd2800002ULL) << 13);
    acc = (acc + a1 + 0x52800003ULL) ^ 0x129648ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #2022 | PC: 0x106348 | FDE: 0x129660 | Size: 240 bytes
// Hàm FDE #2022 | Địa chỉ PC: 0x106348 | Địa chỉ FDE: 0x129660 | Kích thước: 240 bytes
//   0x106348: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x10634c: 910003FD  mov      x29, sp
//   0x106350: A90153F3  stp      x19, x20, [sp, #0x10]
//   0x106354: 53001C14  uxtb     w20, w0
static inline uint64_t fde_func_2022_0x106348(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x106348ULL ^ (static_cast<uint64_t>(0xa9bc7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x129660ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #2023 | PC: 0x106438 | FDE: 0x129698 | Size: 256 bytes
// Hàm FDE #2023 | Địa chỉ PC: 0x106438 | Địa chỉ FDE: 0x129698 | Kích thước: 256 bytes
//   0x106438: F00002C2  adrp     x2, #0x161000
//   0x10643c: 52800100  mov      w0, #8
//   0x106440: 9104C041  add      x1, x2, #0x130
//   0x106444: 3904C040  strb     w0, [x2, #0x130]
static inline uint64_t fde_func_2023_0x106438(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x106438ULL ^ (static_cast<uint64_t>(0xf00002c2ULL) << 13);
    acc = (acc + a1 + 0x52800100ULL) ^ 0x129698ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2024 | PC: 0x10654c | FDE: 0x1296b0 | Size: 60 bytes
// Hàm FDE #2024 | Địa chỉ PC: 0x10654c | Địa chỉ FDE: 0x1296b0 | Kích thước: 60 bytes
//   0x10654c: F00002C3  adrp     x3, #0x161000
//   0x106550: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x106554: 910003FD  mov      x29, sp
//   0x106558: 39453C63  ldrb     w3, [x3, #0x14f]
static inline uint64_t fde_func_2024_0x10654c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10654cULL ^ (static_cast<uint64_t>(0xf00002c3ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x1296b0ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #2025 | PC: 0x106588 | FDE: 0x1296d8 | Size: 88 bytes
// Hàm FDE #2025 | Địa chỉ PC: 0x106588 | Địa chỉ FDE: 0x1296d8 | Kích thước: 88 bytes
//   0x106588: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x10658c: 7101843F  cmp      w1, #0x61
//   0x106590: 910003FD  mov      x29, sp
//   0x106594: 5400004D  b.le     #0x10659c
static inline uint64_t fde_func_2025_0x106588(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x106588ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x7101843fULL) ^ 0x1296d8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #2026 | PC: 0x1065e0 | FDE: 0x129700 | Size: 256 bytes
// Hàm FDE #2026 | Địa chỉ PC: 0x1065e0 | Địa chỉ FDE: 0x129700 | Kích thước: 256 bytes
//   0x1065e0: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x1065e4: 910003FD  mov      x29, sp
//   0x1065e8: A9025BF5  stp      x21, x22, [sp, #0x20]
//   0x1065ec: AA0003F5  mov      x21, x0
static inline uint64_t fde_func_2026_0x1065e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1065e0ULL ^ (static_cast<uint64_t>(0xa9bc7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x129700ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2027 | PC: 0x1066ec | FDE: 0x129738 | Size: 8 bytes
// Hàm FDE #2027 | Địa chỉ PC: 0x1066ec | Địa chỉ FDE: 0x129738 | Kích thước: 8 bytes
//   0x1066ec: F9418800  ldr      x0, [x0, #0x310]
//   0x1066f0: D65F03C0  ret      
static inline uint64_t fde_func_2027_0x1066ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1066ecULL ^ (static_cast<uint64_t>(0xf9418800ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x129738ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2028 | PC: 0x1066f4 | FDE: 0x129750 | Size: 88 bytes
// Hàm FDE #2028 | Địa chỉ PC: 0x1066f4 | Địa chỉ FDE: 0x129750 | Kích thước: 88 bytes
//   0x1066f4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1066f8: 7101843F  cmp      w1, #0x61
//   0x1066fc: 910003FD  mov      x29, sp
//   0x106700: 5400004D  b.le     #0x106708
static inline uint64_t fde_func_2028_0x1066f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1066f4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x7101843fULL) ^ 0x129750ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #2029 | PC: 0x10674c | FDE: 0x129778 | Size: 8 bytes
// Hàm FDE #2029 | Địa chỉ PC: 0x10674c | Địa chỉ FDE: 0x129778 | Kích thước: 8 bytes
//   0x10674c: F9418C00  ldr      x0, [x0, #0x318]
//   0x106750: D65F03C0  ret      
static inline uint64_t fde_func_2029_0x10674c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10674cULL ^ (static_cast<uint64_t>(0xf9418c00ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x129778ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2030 | PC: 0x106754 | FDE: 0x129790 | Size: 20 bytes
// Hàm FDE #2030 | Địa chỉ PC: 0x106754 | Địa chỉ FDE: 0x129790 | Kích thước: 20 bytes
//   0x106754: F941A002  ldr      x2, [x0, #0x340]
//   0x106758: F9418C00  ldr      x0, [x0, #0x318]
//   0x10675c: D37FFC42  lsr      x2, x2, #0x3f
//   0x106760: B9000022  str      w2, [x1]
static inline uint64_t fde_func_2030_0x106754(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x106754ULL ^ (static_cast<uint64_t>(0xf941a002ULL) << 13);
    acc = (acc + a1 + 0xf9418c00ULL) ^ 0x129790ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #2031 | PC: 0x106768 | FDE: 0x1297a8 | Size: 8 bytes
// Hàm FDE #2031 | Địa chỉ PC: 0x106768 | Địa chỉ FDE: 0x1297a8 | Kích thước: 8 bytes
//   0x106768: F9018C01  str      x1, [x0, #0x318]
//   0x10676c: D65F03C0  ret      
static inline uint64_t fde_func_2031_0x106768(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x106768ULL ^ (static_cast<uint64_t>(0xf9018c01ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1297a8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2032 | PC: 0x106770 | FDE: 0x1297c0 | Size: 8 bytes
// Hàm FDE #2032 | Địa chỉ PC: 0x106770 | Địa chỉ FDE: 0x1297c0 | Kích thước: 8 bytes
//   0x106770: F9419000  ldr      x0, [x0, #0x320]
//   0x106774: D65F03C0  ret      
static inline uint64_t fde_func_2032_0x106770(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x106770ULL ^ (static_cast<uint64_t>(0xf9419000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1297c0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2033 | PC: 0x106778 | FDE: 0x1297d8 | Size: 8 bytes
// Hàm FDE #2033 | Địa chỉ PC: 0x106778 | Địa chỉ FDE: 0x1297d8 | Kích thước: 8 bytes
//   0x106778: F9419C00  ldr      x0, [x0, #0x338]
//   0x10677c: D65F03C0  ret      
static inline uint64_t fde_func_2033_0x106778(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x106778ULL ^ (static_cast<uint64_t>(0xf9419c00ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1297d8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2034 | PC: 0x106780 | FDE: 0x1297f0 | Size: 40 bytes
// Hàm FDE #2034 | Địa chỉ PC: 0x106780 | Địa chỉ FDE: 0x1297f0 | Kích thước: 40 bytes
//   0x106780: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x106784: D1000400  sub      x0, x0, #1
//   0x106788: 910003FD  mov      x29, sp
//   0x10678c: 910063A1  add      x1, x29, #0x18
static inline uint64_t fde_func_2034_0x106780(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x106780ULL ^ (static_cast<uint64_t>(0xa9bd7bfdULL) << 13);
    acc = (acc + a1 + 0xd1000400ULL) ^ 0x1297f0ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #2035 | PC: 0x1067a8 | FDE: 0x129818 | Size: 8 bytes
// Hàm FDE #2035 | Địa chỉ PC: 0x1067a8 | Địa chỉ FDE: 0x129818 | Kích thước: 8 bytes
//   0x1067a8: F9419800  ldr      x0, [x0, #0x330]
//   0x1067ac: D65F03C0  ret      
static inline uint64_t fde_func_2035_0x1067a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1067a8ULL ^ (static_cast<uint64_t>(0xf9419800ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x129818ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2036 | PC: 0x1067b0 | FDE: 0x129830 | Size: 8 bytes
// Hàm FDE #2036 | Địa chỉ PC: 0x1067b0 | Địa chỉ FDE: 0x129830 | Kích thước: 8 bytes
//   0x1067b0: F9419400  ldr      x0, [x0, #0x328]
//   0x1067b4: D65F03C0  ret      
static inline uint64_t fde_func_2036_0x1067b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1067b0ULL ^ (static_cast<uint64_t>(0xf9419400ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x129830ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2037 | PC: 0x1067b8 | FDE: 0x129848 | Size: 120 bytes
// Hàm FDE #2037 | Địa chỉ PC: 0x1067b8 | Địa chỉ FDE: 0x129848 | Kích thước: 120 bytes
//   0x1067b8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1067bc: 53001C02  uxtb     w2, w0
//   0x1067c0: AA0103E0  mov      x0, x1
//   0x1067c4: 7103FC5F  cmp      w2, #0xff
static inline uint64_t fde_func_2037_0x1067b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1067b8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x53001c02ULL) ^ 0x129848ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #2038 | PC: 0x106830 | FDE: 0x129888 | Size: 256 bytes
// Hàm FDE #2038 | Địa chỉ PC: 0x106830 | Địa chỉ FDE: 0x129888 | Kích thước: 256 bytes
//   0x106830: A9B77BFD  stp      x29, x30, [sp, #-0x90]!
//   0x106834: 910003FD  mov      x29, sp
//   0x106838: A9025BF5  stp      x21, x22, [sp, #0x20]
//   0x10683c: A90363F7  stp      x23, x24, [sp, #0x30]
static inline uint64_t fde_func_2038_0x106830(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x106830ULL ^ (static_cast<uint64_t>(0xa9b77bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x129888ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2039 | PC: 0x106d28 | FDE: 0x1298d8 | Size: 256 bytes
// Hàm FDE #2039 | Địa chỉ PC: 0x106d28 | Địa chỉ FDE: 0x1298d8 | Kích thước: 256 bytes
//   0x106d28: A9B77BFD  stp      x29, x30, [sp, #-0x90]!
//   0x106d2c: D280D002  mov      x2, #0x680
//   0x106d30: 910003FD  mov      x29, sp
//   0x106d34: A90153F3  stp      x19, x20, [sp, #0x10]
static inline uint64_t fde_func_2039_0x106d28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x106d28ULL ^ (static_cast<uint64_t>(0xa9b77bfdULL) << 13);
    acc = (acc + a1 + 0xd280d002ULL) ^ 0x1298d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2040 | PC: 0x10714c | FDE: 0x129920 | Size: 256 bytes
// Hàm FDE #2040 | Địa chỉ PC: 0x10714c | Địa chỉ FDE: 0x129920 | Kích thước: 256 bytes
//   0x10714c: D108C3FF  sub      sp, sp, #0x230
//   0x107150: AA0003E4  mov      x4, x0
//   0x107154: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x107158: 910003FD  mov      x29, sp
static inline uint64_t fde_func_2040_0x10714c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10714cULL ^ (static_cast<uint64_t>(0xd108c3ffULL) << 13);
    acc = (acc + a1 + 0xaa0003e4ULL) ^ 0x129920ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2041 | PC: 0x107700 | FDE: 0x129978 | Size: 256 bytes
// Hàm FDE #2041 | Địa chỉ PC: 0x107700 | Địa chỉ FDE: 0x129978 | Kích thước: 256 bytes
//   0x107700: D10F83FF  sub      sp, sp, #0x3e0
//   0x107704: D2807802  mov      x2, #0x3c0
//   0x107708: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x10770c: 910003FD  mov      x29, sp
static inline uint64_t fde_func_2041_0x107700(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x107700ULL ^ (static_cast<uint64_t>(0xd10f83ffULL) << 13);
    acc = (acc + a1 + 0xd2807802ULL) ^ 0x129978ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2042 | PC: 0x10790c | FDE: 0x1299d8 | Size: 220 bytes
// Hàm FDE #2042 | Địa chỉ PC: 0x10790c | Địa chỉ FDE: 0x1299d8 | Kích thước: 220 bytes
//   0x10790c: D11A43FF  sub      sp, sp, #0x690
//   0x107910: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x107914: 910003FD  mov      x29, sp
//   0x107918: A90153F3  stp      x19, x20, [sp, #0x10]
static inline uint64_t fde_func_2042_0x10790c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10790cULL ^ (static_cast<uint64_t>(0xd11a43ffULL) << 13);
    acc = (acc + a1 + 0xa9bc7bfdULL) ^ 0x1299d8ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #2043 | PC: 0x1079e8 | FDE: 0x129a20 | Size: 76 bytes
// Hàm FDE #2043 | Địa chỉ PC: 0x1079e8 | Địa chỉ FDE: 0x129a20 | Kích thước: 76 bytes
//   0x1079e8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x1079ec: 910003FD  mov      x29, sp
//   0x1079f0: A90153F3  stp      x19, x20, [sp, #0x10]
//   0x1079f4: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_2043_0x1079e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1079e8ULL ^ (static_cast<uint64_t>(0xa9be7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x129a20ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #2044 | PC: 0x107a34 | FDE: 0x129a50 | Size: 192 bytes
// Hàm FDE #2044 | Địa chỉ PC: 0x107a34 | Địa chỉ FDE: 0x129a50 | Kích thước: 192 bytes
//   0x107a34: D11A03FF  sub      sp, sp, #0x680
//   0x107a38: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x107a3c: 910003FD  mov      x29, sp
//   0x107a40: A90153F3  stp      x19, x20, [sp, #0x10]
static inline uint64_t fde_func_2044_0x107a34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x107a34ULL ^ (static_cast<uint64_t>(0xd11a03ffULL) << 13);
    acc = (acc + a1 + 0xa9bc7bfdULL) ^ 0x129a50ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #2045 | PC: 0x107af4 | FDE: 0x129aa0 | Size: 236 bytes
// Hàm FDE #2045 | Địa chỉ PC: 0x107af4 | Địa chỉ FDE: 0x129aa0 | Kích thước: 236 bytes
//   0x107af4: D11A03FF  sub      sp, sp, #0x680
//   0x107af8: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x107afc: 910003FD  mov      x29, sp
//   0x107b00: A90363F7  stp      x23, x24, [sp, #0x30]
static inline uint64_t fde_func_2045_0x107af4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x107af4ULL ^ (static_cast<uint64_t>(0xd11a03ffULL) << 13);
    acc = (acc + a1 + 0xa9bb7bfdULL) ^ 0x129aa0ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #2046 | PC: 0x107be0 | FDE: 0x129af8 | Size: 244 bytes
// Hàm FDE #2046 | Địa chỉ PC: 0x107be0 | Địa chỉ FDE: 0x129af8 | Kích thước: 244 bytes
//   0x107be0: D12903FF  sub      sp, sp, #0xa40
//   0x107be4: D2807802  mov      x2, #0x3c0
//   0x107be8: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x107bec: 910003FD  mov      x29, sp
static inline uint64_t fde_func_2046_0x107be0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x107be0ULL ^ (static_cast<uint64_t>(0xd12903ffULL) << 13);
    acc = (acc + a1 + 0xd2807802ULL) ^ 0x129af8ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #2047 | PC: 0x107cd4 | FDE: 0x129b38 | Size: 4 bytes
// Hàm FDE #2047 | Địa chỉ PC: 0x107cd4 | Địa chỉ FDE: 0x129b38 | Kích thước: 4 bytes
//   0x107cd4: D65F03C0  ret      
static inline uint64_t fde_func_2047_0x107cd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x107cd4ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xd13843ffULL) ^ 0x129b38ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #2048 | PC: 0x107cd8 | FDE: 0x129b50 | Size: 256 bytes
// Hàm FDE #2048 | Địa chỉ PC: 0x107cd8 | Địa chỉ FDE: 0x129b50 | Kích thước: 256 bytes
//   0x107cd8: D13843FF  sub      sp, sp, #0xe10
//   0x107cdc: A9B47BFD  stp      x29, x30, [sp, #-0xc0]!
//   0x107ce0: 910003FD  mov      x29, sp
//   0x107ce4: A9045BF5  stp      x21, x22, [sp, #0x40]
static inline uint64_t fde_func_2048_0x107cd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x107cd8ULL ^ (static_cast<uint64_t>(0xd13843ffULL) << 13);
    acc = (acc + a1 + 0xa9b47bfdULL) ^ 0x129b50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2049 | PC: 0x107e50 | FDE: 0x129bf8 | Size: 244 bytes
// Hàm FDE #2049 | Địa chỉ PC: 0x107e50 | Địa chỉ FDE: 0x129bf8 | Kích thước: 244 bytes
//   0x107e50: D11E43FF  sub      sp, sp, #0x790
//   0x107e54: A9B47BFD  stp      x29, x30, [sp, #-0xc0]!
//   0x107e58: 910003FD  mov      x29, sp
//   0x107e5c: A90353F3  stp      x19, x20, [sp, #0x30]
static inline uint64_t fde_func_2049_0x107e50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x107e50ULL ^ (static_cast<uint64_t>(0xd11e43ffULL) << 13);
    acc = (acc + a1 + 0xa9b47bfdULL) ^ 0x129bf8ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #2050 | PC: 0x107f44 | FDE: 0x129ca0 | Size: 252 bytes
// Hàm FDE #2050 | Địa chỉ PC: 0x107f44 | Địa chỉ FDE: 0x129ca0 | Kích thước: 252 bytes
//   0x107f44: D11E43FF  sub      sp, sp, #0x790
//   0x107f48: A9B47BFD  stp      x29, x30, [sp, #-0xc0]!
//   0x107f4c: 910003FD  mov      x29, sp
//   0x107f50: A90353F3  stp      x19, x20, [sp, #0x30]
static inline uint64_t fde_func_2050_0x107f44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x107f44ULL ^ (static_cast<uint64_t>(0xd11e43ffULL) << 13);
    acc = (acc + a1 + 0xa9b47bfdULL) ^ 0x129ca0ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #2051 | PC: 0x108040 | FDE: 0x129d48 | Size: 248 bytes
// Hàm FDE #2051 | Địa chỉ PC: 0x108040 | Địa chỉ FDE: 0x129d48 | Kích thước: 248 bytes
//   0x108040: D11E43FF  sub      sp, sp, #0x790
//   0x108044: A9B47BFD  stp      x29, x30, [sp, #-0xc0]!
//   0x108048: 910003FD  mov      x29, sp
//   0x10804c: 6D0827E8  stp      d8, d9, [sp, #0x80]
static inline uint64_t fde_func_2051_0x108040(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x108040ULL ^ (static_cast<uint64_t>(0xd11e43ffULL) << 13);
    acc = (acc + a1 + 0xa9b47bfdULL) ^ 0x129d48ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #2052 | PC: 0x108138 | FDE: 0x129df0 | Size: 36 bytes
// Hàm FDE #2052 | Địa chỉ PC: 0x108138 | Địa chỉ FDE: 0x129df0 | Kích thước: 36 bytes
//   0x108138: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x10813c: 910003FD  mov      x29, sp
//   0x108140: F9400402  ldr      x2, [x0, #8]
//   0x108144: B4000082  cbz      x2, #0x108154
static inline uint64_t fde_func_2052_0x108138(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x108138ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x129df0ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #2053 | PC: 0x10815c | FDE: 0x129e18 | Size: 208 bytes
// Hàm FDE #2053 | Địa chỉ PC: 0x10815c | Địa chỉ FDE: 0x129e18 | Kích thước: 208 bytes
//   0x10815c: D12903FF  sub      sp, sp, #0xa40
//   0x108160: AA1E03E2  mov      x2, x30
//   0x108164: A9B67BFD  stp      x29, x30, [sp, #-0xa0]!
//   0x108168: 910003FD  mov      x29, sp
static inline uint64_t fde_func_2053_0x10815c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10815cULL ^ (static_cast<uint64_t>(0xd12903ffULL) << 13);
    acc = (acc + a1 + 0xaa1e03e2ULL) ^ 0x129e18ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #2054 | PC: 0x10822c | FDE: 0x129eb0 | Size: 40 bytes
// Hàm FDE #2054 | Địa chỉ PC: 0x10822c | Địa chỉ FDE: 0x129eb0 | Kích thước: 40 bytes
//   0x10822c: D2800002  mov      x2, #0
//   0x108230: 52800003  mov      w3, #0
//   0x108234: 38401405  ldrb     w5, [x0], #1
//   0x108238: 924018A4  and      x4, x5, #0x7f
static inline uint64_t fde_func_2054_0x10822c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10822cULL ^ (static_cast<uint64_t>(0xd2800002ULL) << 13);
    acc = (acc + a1 + 0x52800003ULL) ^ 0x129eb0ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #2055 | PC: 0x108254 | FDE: 0x129ec8 | Size: 64 bytes
// Hàm FDE #2055 | Địa chỉ PC: 0x108254 | Địa chỉ FDE: 0x129ec8 | Kích thước: 64 bytes
//   0x108254: D2800002  mov      x2, #0
//   0x108258: 52800003  mov      w3, #0
//   0x10825c: 38401404  ldrb     w4, [x0], #1
//   0x108260: 92401885  and      x5, x4, #0x7f
static inline uint64_t fde_func_2055_0x108254(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x108254ULL ^ (static_cast<uint64_t>(0xd2800002ULL) << 13);
    acc = (acc + a1 + 0x52800003ULL) ^ 0x129ec8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #2056 | PC: 0x108294 | FDE: 0x129ee0 | Size: 28 bytes
// Hàm FDE #2056 | Địa chỉ PC: 0x108294 | Địa chỉ FDE: 0x129ee0 | Kích thước: 28 bytes
//   0x108294: F9400423  ldr      x3, [x1, #8]
//   0x108298: F9400441  ldr      x1, [x2, #8]
//   0x10829c: EB01007F  cmp      x3, x1
//   0x1082a0: 5A9F23E0  csetm    w0, lo
static inline uint64_t fde_func_2056_0x108294(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x108294ULL ^ (static_cast<uint64_t>(0xf9400423ULL) << 13);
    acc = (acc + a1 + 0xf9400441ULL) ^ 0x129ee0ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #2057 | PC: 0x1082b0 | FDE: 0x129ef8 | Size: 192 bytes
// Hàm FDE #2057 | Địa chỉ PC: 0x1082b0 | Địa chỉ FDE: 0x129ef8 | Kích thước: 192 bytes
//   0x1082b0: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x1082b4: 910003FD  mov      x29, sp
//   0x1082b8: A90153F3  stp      x19, x20, [sp, #0x10]
//   0x1082bc: 531F7873  lsl      w19, w3, #1
static inline uint64_t fde_func_2057_0x1082b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1082b0ULL ^ (static_cast<uint64_t>(0xa9ba7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x129ef8ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #2058 | PC: 0x108370 | FDE: 0x129f38 | Size: 180 bytes
// Hàm FDE #2058 | Địa chỉ PC: 0x108370 | Địa chỉ FDE: 0x129f38 | Kích thước: 180 bytes
//   0x108370: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x108374: 910003FD  mov      x29, sp
//   0x108378: A90153F3  stp      x19, x20, [sp, #0x10]
//   0x10837c: F9400453  ldr      x19, [x2, #8]
static inline uint64_t fde_func_2058_0x108370(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x108370ULL ^ (static_cast<uint64_t>(0xa9bb7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x129f38ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #2059 | PC: 0x108424 | FDE: 0x129f78 | Size: 96 bytes
// Hàm FDE #2059 | Địa chỉ PC: 0x108424 | Địa chỉ FDE: 0x129f78 | Kích thước: 96 bytes
//   0x108424: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x108428: 53001C00  uxtb     w0, w0
//   0x10842c: 7103FC1F  cmp      w0, #0xff
//   0x108430: 910003FD  mov      x29, sp
static inline uint64_t fde_func_2059_0x108424(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x108424ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x53001c00ULL) ^ 0x129f78ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #2060 | PC: 0x108484 | FDE: 0x129fa0 | Size: 96 bytes
// Hàm FDE #2060 | Địa chỉ PC: 0x108484 | Địa chỉ FDE: 0x129fa0 | Kích thước: 96 bytes
//   0x108484: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x108488: 53001C00  uxtb     w0, w0
//   0x10848c: 7103FC1F  cmp      w0, #0xff
//   0x108490: 910003FD  mov      x29, sp
static inline uint64_t fde_func_2060_0x108484(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x108484ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x53001c00ULL) ^ 0x129fa0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #2061 | PC: 0x1084e4 | FDE: 0x129fc8 | Size: 96 bytes
// Hàm FDE #2061 | Địa chỉ PC: 0x1084e4 | Địa chỉ FDE: 0x129fc8 | Kích thước: 96 bytes
//   0x1084e4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1084e8: 53001C00  uxtb     w0, w0
//   0x1084ec: 7103FC1F  cmp      w0, #0xff
//   0x1084f0: 910003FD  mov      x29, sp
static inline uint64_t fde_func_2061_0x1084e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1084e4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x53001c00ULL) ^ 0x129fc8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #2062 | PC: 0x108544 | FDE: 0x129ff0 | Size: 240 bytes
// Hàm FDE #2062 | Địa chỉ PC: 0x108544 | Địa chỉ FDE: 0x129ff0 | Kích thước: 240 bytes
//   0x108544: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x108548: 910003FD  mov      x29, sp
//   0x10854c: A90153F3  stp      x19, x20, [sp, #0x10]
//   0x108550: 53001C14  uxtb     w20, w0
static inline uint64_t fde_func_2062_0x108544(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x108544ULL ^ (static_cast<uint64_t>(0xa9bc7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x129ff0ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #2063 | PC: 0x108634 | FDE: 0x12a028 | Size: 144 bytes
// Hàm FDE #2063 | Địa chỉ PC: 0x108634 | Địa chỉ FDE: 0x12a028 | Kích thước: 144 bytes
//   0x108634: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x108638: 910003FD  mov      x29, sp
//   0x10863c: A90153F3  stp      x19, x20, [sp, #0x10]
//   0x108640: 79404013  ldrh     w19, [x0, #0x20]
static inline uint64_t fde_func_2063_0x108634(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x108634ULL ^ (static_cast<uint64_t>(0xa9bb7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x12a028ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #2064 | PC: 0x1086c4 | FDE: 0x12a060 | Size: 252 bytes
// Hàm FDE #2064 | Địa chỉ PC: 0x1086c4 | Địa chỉ FDE: 0x12a060 | Kích thước: 252 bytes
//   0x1086c4: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x1086c8: 910003FD  mov      x29, sp
//   0x1086cc: A90153F3  stp      x19, x20, [sp, #0x10]
//   0x1086d0: 91002414  add      x20, x0, #9
static inline uint64_t fde_func_2064_0x1086c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1086c4ULL ^ (static_cast<uint64_t>(0xa9bc7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x12a060ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #2065 | PC: 0x1087c0 | FDE: 0x12a090 | Size: 256 bytes
// Hàm FDE #2065 | Địa chỉ PC: 0x1087c0 | Địa chỉ FDE: 0x12a090 | Kích thước: 256 bytes
//   0x1087c0: A9B97BFD  stp      x29, x30, [sp, #-0x70]!
//   0x1087c4: 910003FD  mov      x29, sp
//   0x1087c8: A9025BF5  stp      x21, x22, [sp, #0x20]
//   0x1087cc: AA0003F6  mov      x22, x0
static inline uint64_t fde_func_2065_0x1087c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1087c0ULL ^ (static_cast<uint64_t>(0xa9b97bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x12a090ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2066 | PC: 0x108920 | FDE: 0x12a0d8 | Size: 16 bytes
// Hàm FDE #2066 | Địa chỉ PC: 0x108920 | Địa chỉ FDE: 0x12a0d8 | Kích thước: 16 bytes
//   0x108920: 91001001  add      x1, x0, #4
//   0x108924: B9800400  ldrsw    x0, [x0, #4]
//   0x108928: CB000020  sub      x0, x1, x0
//   0x10892c: 17FFFF66  b        #0x1086c4
static inline uint64_t fde_func_2066_0x108920(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x108920ULL ^ (static_cast<uint64_t>(0x91001001ULL) << 13);
    acc = (acc + a1 + 0xb9800400ULL) ^ 0x12a0d8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #2067 | PC: 0x108930 | FDE: 0x12a0f0 | Size: 256 bytes
// Hàm FDE #2067 | Địa chỉ PC: 0x108930 | Địa chỉ FDE: 0x12a0f0 | Kích thước: 256 bytes
//   0x108930: A9B77BFD  stp      x29, x30, [sp, #-0x90]!
//   0x108934: F100BC3F  cmp      x1, #0x2f
//   0x108938: 910003FD  mov      x29, sp
//   0x10893c: A90153F3  stp      x19, x20, [sp, #0x10]
static inline uint64_t fde_func_2067_0x108930(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x108930ULL ^ (static_cast<uint64_t>(0xa9b77bfdULL) << 13);
    acc = (acc + a1 + 0xf100bc3fULL) ^ 0x12a0f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2068 | PC: 0x108d4c | FDE: 0x12a130 | Size: 156 bytes
// Hàm FDE #2068 | Địa chỉ PC: 0x108d4c | Địa chỉ FDE: 0x12a130 | Kích thước: 156 bytes
//   0x108d4c: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x108d50: 910003FD  mov      x29, sp
//   0x108d54: A9025BF5  stp      x21, x22, [sp, #0x20]
//   0x108d58: AA0003F5  mov      x21, x0
static inline uint64_t fde_func_2068_0x108d4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x108d4cULL ^ (static_cast<uint64_t>(0xa9bc7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x12a130ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #2069 | PC: 0x108de8 | FDE: 0x12a168 | Size: 256 bytes
// Hàm FDE #2069 | Địa chỉ PC: 0x108de8 | Địa chỉ FDE: 0x12a168 | Kích thước: 256 bytes
//   0x108de8: A9B97BFD  stp      x29, x30, [sp, #-0x70]!
//   0x108dec: 910003FD  mov      x29, sp
//   0x108df0: A90153F3  stp      x19, x20, [sp, #0x10]
//   0x108df4: A90363F7  stp      x23, x24, [sp, #0x30]
static inline uint64_t fde_func_2069_0x108de8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x108de8ULL ^ (static_cast<uint64_t>(0xa9b97bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x12a168ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2070 | PC: 0x108f48 | FDE: 0x12a1b0 | Size: 256 bytes
// Hàm FDE #2070 | Địa chỉ PC: 0x108f48 | Địa chỉ FDE: 0x12a1b0 | Kích thước: 256 bytes
//   0x108f48: A9B97BFD  stp      x29, x30, [sp, #-0x70]!
//   0x108f4c: 910003FD  mov      x29, sp
//   0x108f50: A9025BF5  stp      x21, x22, [sp, #0x20]
//   0x108f54: AA0003F6  mov      x22, x0
static inline uint64_t fde_func_2070_0x108f48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x108f48ULL ^ (static_cast<uint64_t>(0xa9b97bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x12a1b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2071 | PC: 0x10907c | FDE: 0x12a1f8 | Size: 256 bytes
// Hàm FDE #2071 | Địa chỉ PC: 0x10907c | Địa chỉ FDE: 0x12a1f8 | Kích thước: 256 bytes
//   0x10907c: A9B77BFD  stp      x29, x30, [sp, #-0x90]!
//   0x109080: 910003FD  mov      x29, sp
//   0x109084: A9025BF5  stp      x21, x22, [sp, #0x20]
//   0x109088: AA0103F6  mov      x22, x1
static inline uint64_t fde_func_2071_0x10907c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10907cULL ^ (static_cast<uint64_t>(0xa9b77bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x12a1f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2072 | PC: 0x1095ec | FDE: 0x12a248 | Size: 156 bytes
// Hàm FDE #2072 | Địa chỉ PC: 0x1095ec | Địa chỉ FDE: 0x12a248 | Kích thước: 156 bytes
//   0x1095ec: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x1095f0: 910003FD  mov      x29, sp
//   0x1095f4: A90153F3  stp      x19, x20, [sp, #0x10]
//   0x1095f8: F90013F5  str      x21, [sp, #0x20]
static inline uint64_t fde_func_2072_0x1095ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1095ecULL ^ (static_cast<uint64_t>(0xa9bd7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x12a248ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #2073 | PC: 0x109688 | FDE: 0x12a288 | Size: 12 bytes
// Hàm FDE #2073 | Địa chỉ PC: 0x109688 | Địa chỉ FDE: 0x12a288 | Kích thước: 12 bytes
//   0x109688: D2800002  mov      x2, #0
//   0x10968c: D2800003  mov      x3, #0
//   0x109690: 17FFFFD7  b        #0x1095ec
static inline uint64_t fde_func_2073_0x109688(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109688ULL ^ (static_cast<uint64_t>(0xd2800002ULL) << 13);
    acc = (acc + a1 + 0xd2800003ULL) ^ 0x12a288ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #2074 | PC: 0x109694 | FDE: 0x12a2a0 | Size: 64 bytes
// Hàm FDE #2074 | Địa chỉ PC: 0x109694 | Địa chỉ FDE: 0x12a2a0 | Kích thước: 64 bytes
//   0x109694: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x109698: 910003FD  mov      x29, sp
//   0x10969c: B9400001  ldr      w1, [x0]
//   0x1096a0: F9000BF3  str      x19, [sp, #0x10]
static inline uint64_t fde_func_2074_0x109694(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109694ULL ^ (static_cast<uint64_t>(0xa9be7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x12a2a0ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #2075 | PC: 0x1096d4 | FDE: 0x12a2d8 | Size: 148 bytes
// Hàm FDE #2075 | Địa chỉ PC: 0x1096d4 | Địa chỉ FDE: 0x12a2d8 | Kích thước: 148 bytes
//   0x1096d4: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x1096d8: 92800004  mov      x4, #-1
//   0x1096dc: 910003FD  mov      x29, sp
//   0x1096e0: A90153F3  stp      x19, x20, [sp, #0x10]
static inline uint64_t fde_func_2075_0x1096d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1096d4ULL ^ (static_cast<uint64_t>(0xa9bd7bfdULL) << 13);
    acc = (acc + a1 + 0x92800004ULL) ^ 0x12a2d8ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #2076 | PC: 0x109768 | FDE: 0x12a310 | Size: 12 bytes
// Hàm FDE #2076 | Địa chỉ PC: 0x109768 | Địa chỉ FDE: 0x12a310 | Kích thước: 12 bytes
//   0x109768: D2800002  mov      x2, #0
//   0x10976c: D2800003  mov      x3, #0
//   0x109770: 17FFFFD9  b        #0x1096d4
static inline uint64_t fde_func_2076_0x109768(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109768ULL ^ (static_cast<uint64_t>(0xd2800002ULL) << 13);
    acc = (acc + a1 + 0xd2800003ULL) ^ 0x12a310ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #2077 | PC: 0x109774 | FDE: 0x12a328 | Size: 44 bytes
// Hàm FDE #2077 | Địa chỉ PC: 0x109774 | Địa chỉ FDE: 0x12a328 | Kích thước: 44 bytes
//   0x109774: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x109778: 910003FD  mov      x29, sp
//   0x10977c: F9000BF3  str      x19, [sp, #0x10]
//   0x109780: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_2077_0x109774(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109774ULL ^ (static_cast<uint64_t>(0xa9be7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x12a328ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #2078 | PC: 0x1097a0 | FDE: 0x12a350 | Size: 256 bytes
// Hàm FDE #2078 | Địa chỉ PC: 0x1097a0 | Địa chỉ FDE: 0x12a350 | Kích thước: 256 bytes
//   0x1097a0: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x1097a4: 910003FD  mov      x29, sp
//   0x1097a8: A90153F3  stp      x19, x20, [sp, #0x10]
//   0x1097ac: A9025BF5  stp      x21, x22, [sp, #0x20]
static inline uint64_t fde_func_2078_0x1097a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1097a0ULL ^ (static_cast<uint64_t>(0xa9bd7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x12a350ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2079 | PC: 0x1098a0 | FDE: 0x12a380 | Size: 4 bytes
// Hàm FDE #2079 | Địa chỉ PC: 0x1098a0 | Địa chỉ FDE: 0x12a380 | Kích thước: 4 bytes
//   0x1098a0: 17FFFFC0  b        #0x1097a0
static inline uint64_t fde_func_2079_0x1098a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1098a0ULL ^ (static_cast<uint64_t>(0x17ffffc0ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x12a380ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #2080 | PC: 0x1098a4 | FDE: 0x12a398 | Size: 36 bytes
// Hàm FDE #2080 | Địa chỉ PC: 0x1098a4 | Địa chỉ FDE: 0x12a398 | Kích thước: 36 bytes
//   0x1098a4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1098a8: 910003FD  mov      x29, sp
//   0x1098ac: B9400001  ldr      w1, [x0]
//   0x1098b0: 34000081  cbz      w1, #0x1098c0
static inline uint64_t fde_func_2080_0x1098a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1098a4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x12a398ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #2081 | PC: 0x1098c8 | FDE: 0x12a3c8 | Size: 256 bytes
// Hàm FDE #2081 | Địa chỉ PC: 0x1098c8 | Địa chỉ FDE: 0x12a3c8 | Kích thước: 256 bytes
//   0x1098c8: A9B87BFD  stp      x29, x30, [sp, #-0x80]!
//   0x1098cc: 910003FD  mov      x29, sp
//   0x1098d0: A9025BF5  stp      x21, x22, [sp, #0x20]
//   0x1098d4: D00001B5  adrp     x21, #0x13f000
static inline uint64_t fde_func_2081_0x1098c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1098c8ULL ^ (static_cast<uint64_t>(0xa9b87bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x12a3c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Shard 5 Dispatcher / Bộ điều phối phân mảnh 5
uint64_t execute_fde_shard_5(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 1668: return fde_func_1668_0x0e1648(a0, a1);
        case 1669: return fde_func_1669_0x0e1740(a0, a1);
        case 1670: return fde_func_1670_0x0e17c4(a0, a1);
        case 1671: return fde_func_1671_0x0e1a78(a0, a1);
        case 1672: return fde_func_1672_0x0e1aac(a0, a1);
        case 1673: return fde_func_1673_0x0e1b0c(a0, a1);
        case 1674: return fde_func_1674_0x0e1c70(a0, a1);
        case 1675: return fde_func_1675_0x0e1dfc(a0, a1);
        case 1676: return fde_func_1676_0x0e1f0c(a0, a1);
        case 1677: return fde_func_1677_0x0e1fa4(a0, a1);
        case 1678: return fde_func_1678_0x0e21e0(a0, a1);
        case 1679: return fde_func_1679_0x0e2324(a0, a1);
        case 1680: return fde_func_1680_0x0e23f0(a0, a1);
        case 1681: return fde_func_1681_0x0e2694(a0, a1);
        case 1682: return fde_func_1682_0x0e2898(a0, a1);
        case 1683: return fde_func_1683_0x0e28a0(a0, a1);
        case 1684: return fde_func_1684_0x0e2a40(a0, a1);
        case 1685: return fde_func_1685_0x0e2b9c(a0, a1);
        case 1686: return fde_func_1686_0x0e2c04(a0, a1);
        case 1687: return fde_func_1687_0x0e2fd0(a0, a1);
        case 1688: return fde_func_1688_0x0e3260(a0, a1);
        case 1689: return fde_func_1689_0x0e332c(a0, a1);
        case 1690: return fde_func_1690_0x0e3450(a0, a1);
        case 1691: return fde_func_1691_0x0e3454(a0, a1);
        case 1692: return fde_func_1692_0x0e3a60(a0, a1);
        case 1693: return fde_func_1693_0x0e3b44(a0, a1);
        case 1694: return fde_func_1694_0x0e3c08(a0, a1);
        case 1695: return fde_func_1695_0x0e3d28(a0, a1);
        case 1696: return fde_func_1696_0x0e3d6c(a0, a1);
        case 1697: return fde_func_1697_0x0e3dec(a0, a1);
        case 1698: return fde_func_1698_0x0e3ffc(a0, a1);
        case 1699: return fde_func_1699_0x0e4184(a0, a1);
        case 1700: return fde_func_1700_0x0e41e4(a0, a1);
        case 1701: return fde_func_1701_0x0e44b4(a0, a1);
        case 1702: return fde_func_1702_0x0e45fc(a0, a1);
        case 1703: return fde_func_1703_0x0e4714(a0, a1);
        case 1704: return fde_func_1704_0x0e489c(a0, a1);
        case 1705: return fde_func_1705_0x0e4aa0(a0, a1);
        case 1706: return fde_func_1706_0x0e4ad0(a0, a1);
        case 1707: return fde_func_1707_0x0e4b00(a0, a1);
        case 1708: return fde_func_1708_0x0e4c04(a0, a1);
        case 1709: return fde_func_1709_0x0e4cec(a0, a1);
        case 1710: return fde_func_1710_0x0e4d3c(a0, a1);
        case 1711: return fde_func_1711_0x0e4e88(a0, a1);
        case 1712: return fde_func_1712_0x0e4ebc(a0, a1);
        case 1713: return fde_func_1713_0x0e4ed4(a0, a1);
        case 1714: return fde_func_1714_0x0e4fd0(a0, a1);
        case 1715: return fde_func_1715_0x0e517c(a0, a1);
        case 1716: return fde_func_1716_0x0e5238(a0, a1);
        case 1717: return fde_func_1717_0x0e528c(a0, a1);
        case 1718: return fde_func_1718_0x0e5438(a0, a1);
        case 1719: return fde_func_1719_0x0e5af4(a0, a1);
        case 1720: return fde_func_1720_0x0e5b54(a0, a1);
        case 1721: return fde_func_1721_0x0e5b80(a0, a1);
        case 1722: return fde_func_1722_0x0e5c24(a0, a1);
        case 1723: return fde_func_1723_0x0e5c7c(a0, a1);
        case 1724: return fde_func_1724_0x0e5cdc(a0, a1);
        case 1725: return fde_func_1725_0x0e5d3c(a0, a1);
        case 1726: return fde_func_1726_0x0e5e74(a0, a1);
        case 1727: return fde_func_1727_0x0e5e98(a0, a1);
        case 1728: return fde_func_1728_0x0e5ed0(a0, a1);
        case 1729: return fde_func_1729_0x0e63e0(a0, a1);
        case 1730: return fde_func_1730_0x0e6530(a0, a1);
        case 1731: return fde_func_1731_0x0e6634(a0, a1);
        case 1732: return fde_func_1732_0x0e6780(a0, a1);
        case 1733: return fde_func_1733_0x0e695c(a0, a1);
        case 1734: return fde_func_1734_0x0e6e24(a0, a1);
        case 1735: return fde_func_1735_0x0e6f3c(a0, a1);
        case 1736: return fde_func_1736_0x0e7020(a0, a1);
        case 1737: return fde_func_1737_0x0e7144(a0, a1);
        case 1738: return fde_func_1738_0x0e7308(a0, a1);
        case 1739: return fde_func_1739_0x0e7360(a0, a1);
        case 1740: return fde_func_1740_0x0e7448(a0, a1);
        case 1741: return fde_func_1741_0x0e7704(a0, a1);
        case 1742: return fde_func_1742_0x0e7894(a0, a1);
        case 1743: return fde_func_1743_0x0e78ec(a0, a1);
        case 1744: return fde_func_1744_0x0e78f4(a0, a1);
        case 1745: return fde_func_1745_0x0e78fc(a0, a1);
        case 1746: return fde_func_1746_0x0e7a04(a0, a1);
        case 1747: return fde_func_1747_0x0e7b0c(a0, a1);
        case 1748: return fde_func_1748_0x0e7bd8(a0, a1);
        case 1749: return fde_func_1749_0x0e7c58(a0, a1);
        case 1750: return fde_func_1750_0x0e7de4(a0, a1);
        case 1751: return fde_func_1751_0x0e7fac(a0, a1);
        case 1752: return fde_func_1752_0x0e8044(a0, a1);
        case 1753: return fde_func_1753_0x0e8110(a0, a1);
        case 1754: return fde_func_1754_0x0e8344(a0, a1);
        case 1755: return fde_func_1755_0x0e8594(a0, a1);
        case 1756: return fde_func_1756_0x0e88e8(a0, a1);
        case 1757: return fde_func_1757_0x0e8948(a0, a1);
        case 1758: return fde_func_1758_0x0e8bb0(a0, a1);
        case 1759: return fde_func_1759_0x0e8cd8(a0, a1);
        case 1760: return fde_func_1760_0x0e8e10(a0, a1);
        case 1761: return fde_func_1761_0x0e8e90(a0, a1);
        case 1762: return fde_func_1762_0x0e8ec4(a0, a1);
        case 1763: return fde_func_1763_0x0e8ed8(a0, a1);
        case 1764: return fde_func_1764_0x0e8eec(a0, a1);
        case 1765: return fde_func_1765_0x0e8f80(a0, a1);
        case 1766: return fde_func_1766_0x0e927c(a0, a1);
        case 1767: return fde_func_1767_0x0e935c(a0, a1);
        case 1768: return fde_func_1768_0x0e93e8(a0, a1);
        case 1769: return fde_func_1769_0x0e9400(a0, a1);
        case 1770: return fde_func_1770_0x0e95d0(a0, a1);
        case 1771: return fde_func_1771_0x0e9768(a0, a1);
        case 1772: return fde_func_1772_0x0e9978(a0, a1);
        case 1773: return fde_func_1773_0x0e9a18(a0, a1);
        case 1774: return fde_func_1774_0x0e9a78(a0, a1);
        case 1775: return fde_func_1775_0x0e9aa0(a0, a1);
        case 1776: return fde_func_1776_0x0e9aec(a0, a1);
        case 1777: return fde_func_1777_0x0e9cf0(a0, a1);
        case 1778: return fde_func_1778_0x0e9d48(a0, a1);
        case 1779: return fde_func_1779_0x0e9da8(a0, a1);
        case 1780: return fde_func_1780_0x0e9f3c(a0, a1);
        case 1781: return fde_func_1781_0x0ea1f0(a0, a1);
        case 1782: return fde_func_1782_0x0ea394(a0, a1);
        case 1783: return fde_func_1783_0x0ea40c(a0, a1);
        case 1784: return fde_func_1784_0x0ea484(a0, a1);
        case 1785: return fde_func_1785_0x0ea4fc(a0, a1);
        case 1786: return fde_func_1786_0x0ea598(a0, a1);
        case 1787: return fde_func_1787_0x0ea5bc(a0, a1);
        case 1788: return fde_func_1788_0x0ea60c(a0, a1);
        case 1789: return fde_func_1789_0x0ea6a8(a0, a1);
        case 1790: return fde_func_1790_0x0ea8ec(a0, a1);
        case 1791: return fde_func_1791_0x0eaa38(a0, a1);
        case 1792: return fde_func_1792_0x0eaa98(a0, a1);
        case 1793: return fde_func_1793_0x0eaacc(a0, a1);
        case 1794: return fde_func_1794_0x0eacc8(a0, a1);
        case 1795: return fde_func_1795_0x0eae20(a0, a1);
        case 1796: return fde_func_1796_0x0eaf24(a0, a1);
        case 1797: return fde_func_1797_0x0eafd4(a0, a1);
        case 1798: return fde_func_1798_0x0eb06c(a0, a1);
        case 1799: return fde_func_1799_0x0eb0f0(a0, a1);
        case 1800: return fde_func_1800_0x0eb2e0(a0, a1);
        case 1801: return fde_func_1801_0x0eb3ac(a0, a1);
        case 1802: return fde_func_1802_0x0eb3d0(a0, a1);
        case 1803: return fde_func_1803_0x0eb4b8(a0, a1);
        case 1804: return fde_func_1804_0x0eb5b0(a0, a1);
        case 1805: return fde_func_1805_0x0eb644(a0, a1);
        case 1806: return fde_func_1806_0x0ebef0(a0, a1);
        case 1807: return fde_func_1807_0x0ebf94(a0, a1);
        case 1808: return fde_func_1808_0x0ec1dc(a0, a1);
        case 1809: return fde_func_1809_0x0ec410(a0, a1);
        case 1810: return fde_func_1810_0x0ec4a8(a0, a1);
        case 1811: return fde_func_1811_0x0ec75c(a0, a1);
        case 1812: return fde_func_1812_0x0ec8cc(a0, a1);
        case 1813: return fde_func_1813_0x0ec940(a0, a1);
        case 1814: return fde_func_1814_0x0ec9b4(a0, a1);
        case 1815: return fde_func_1815_0x0ecae0(a0, a1);
        case 1816: return fde_func_1816_0x0ecb18(a0, a1);
        case 1817: return fde_func_1817_0x0ecc20(a0, a1);
        case 1818: return fde_func_1818_0x0ecddc(a0, a1);
        case 1819: return fde_func_1819_0x0ece44(a0, a1);
        case 1820: return fde_func_1820_0x0ecfac(a0, a1);
        case 1821: return fde_func_1821_0x0ed044(a0, a1);
        case 1822: return fde_func_1822_0x0ed180(a0, a1);
        case 1823: return fde_func_1823_0x0ed35c(a0, a1);
        case 1824: return fde_func_1824_0x0ed3e0(a0, a1);
        case 1825: return fde_func_1825_0x0ed3fc(a0, a1);
        case 1826: return fde_func_1826_0x0ed45c(a0, a1);
        case 1827: return fde_func_1827_0x0ed9e4(a0, a1);
        case 1828: return fde_func_1828_0x0eeb0c(a0, a1);
        case 1829: return fde_func_1829_0x0ef198(a0, a1);
        case 1830: return fde_func_1830_0x0ef38c(a0, a1);
        case 1831: return fde_func_1831_0x0ef6a0(a0, a1);
        case 1832: return fde_func_1832_0x0ef9ec(a0, a1);
        case 1833: return fde_func_1833_0x0efe84(a0, a1);
        case 1834: return fde_func_1834_0x0f04f8(a0, a1);
        case 1835: return fde_func_1835_0x0f09b0(a0, a1);
        case 1836: return fde_func_1836_0x0f0b10(a0, a1);
        case 1837: return fde_func_1837_0x0f0c70(a0, a1);
        case 1838: return fde_func_1838_0x0f0dd0(a0, a1);
        case 1839: return fde_func_1839_0x0f0ed4(a0, a1);
        case 1840: return fde_func_1840_0x0f0f44(a0, a1);
        case 1841: return fde_func_1841_0x0f0fb4(a0, a1);
        case 1842: return fde_func_1842_0x0f2018(a0, a1);
        case 1843: return fde_func_1843_0x0f20b4(a0, a1);
        case 1844: return fde_func_1844_0x0f2144(a0, a1);
        case 1845: return fde_func_1845_0x0f2208(a0, a1);
        case 1846: return fde_func_1846_0x0f22a4(a0, a1);
        case 1847: return fde_func_1847_0x0f2340(a0, a1);
        case 1848: return fde_func_1848_0x0f2534(a0, a1);
        case 1849: return fde_func_1849_0x0f25a8(a0, a1);
        case 1850: return fde_func_1850_0x0f2714(a0, a1);
        case 1851: return fde_func_1851_0x0f27c0(a0, a1);
        case 1852: return fde_func_1852_0x0f27fc(a0, a1);
        case 1853: return fde_func_1853_0x0f2984(a0, a1);
        case 1854: return fde_func_1854_0x0f2f50(a0, a1);
        case 1855: return fde_func_1855_0x0f3020(a0, a1);
        case 1856: return fde_func_1856_0x0f3080(a0, a1);
        case 1857: return fde_func_1857_0x0f30b8(a0, a1);
        case 1858: return fde_func_1858_0x0f324c(a0, a1);
        case 1859: return fde_func_1859_0x0f3448(a0, a1);
        case 1860: return fde_func_1860_0x0f3488(a0, a1);
        case 1861: return fde_func_1861_0x0f34d0(a0, a1);
        case 1862: return fde_func_1862_0x0f3728(a0, a1);
        case 1863: return fde_func_1863_0x0f3db8(a0, a1);
        case 1864: return fde_func_1864_0x0f4fa4(a0, a1);
        case 1865: return fde_func_1865_0x0f50b8(a0, a1);
        case 1866: return fde_func_1866_0x0f50dc(a0, a1);
        case 1867: return fde_func_1867_0x0f512c(a0, a1);
        case 1868: return fde_func_1868_0x0f5250(a0, a1);
        case 1869: return fde_func_1869_0x0f541c(a0, a1);
        case 1870: return fde_func_1870_0x0f5590(a0, a1);
        case 1871: return fde_func_1871_0x0f5704(a0, a1);
        case 1872: return fde_func_1872_0x0f5878(a0, a1);
        case 1873: return fde_func_1873_0x0f59ec(a0, a1);
        case 1874: return fde_func_1874_0x0f5b60(a0, a1);
        case 1875: return fde_func_1875_0x0f5cd4(a0, a1);
        case 1876: return fde_func_1876_0x0f5e48(a0, a1);
        case 1877: return fde_func_1877_0x0f5fbc(a0, a1);
        case 1878: return fde_func_1878_0x0f6084(a0, a1);
        case 1879: return fde_func_1879_0x0f60d4(a0, a1);
        case 1880: return fde_func_1880_0x0f6344(a0, a1);
        case 1881: return fde_func_1881_0x0f76c4(a0, a1);
        case 1882: return fde_func_1882_0x0f7894(a0, a1);
        case 1883: return fde_func_1883_0x0f789c(a0, a1);
        case 1884: return fde_func_1884_0x0f796c(a0, a1);
        case 1885: return fde_func_1885_0x0f7aac(a0, a1);
        case 1886: return fde_func_1886_0x0f7c9c(a0, a1);
        case 1887: return fde_func_1887_0x0f7da0(a0, a1);
        case 1888: return fde_func_1888_0x0f8b38(a0, a1);
        case 1889: return fde_func_1889_0x0f8b40(a0, a1);
        case 1890: return fde_func_1890_0x0f8e18(a0, a1);
        case 1891: return fde_func_1891_0x0f9098(a0, a1);
        case 1892: return fde_func_1892_0x0f90d0(a0, a1);
        case 1893: return fde_func_1893_0x0f90d8(a0, a1);
        case 1894: return fde_func_1894_0x0f91a0(a0, a1);
        case 1895: return fde_func_1895_0x0f91bc(a0, a1);
        case 1896: return fde_func_1896_0x0f91c0(a0, a1);
        case 1897: return fde_func_1897_0x0f93f0(a0, a1);
        case 1898: return fde_func_1898_0x0f94c0(a0, a1);
        case 1899: return fde_func_1899_0x0f9544(a0, a1);
        case 1900: return fde_func_1900_0x0f95ec(a0, a1);
        case 1901: return fde_func_1901_0x0f95f4(a0, a1);
        case 1902: return fde_func_1902_0x0f96b4(a0, a1);
        case 1903: return fde_func_1903_0x0f96d4(a0, a1);
        case 1904: return fde_func_1904_0x0f9704(a0, a1);
        case 1905: return fde_func_1905_0x0f99c8(a0, a1);
        case 1906: return fde_func_1906_0x0f99e4(a0, a1);
        case 1907: return fde_func_1907_0x0f9ab4(a0, a1);
        case 1908: return fde_func_1908_0x0f9b18(a0, a1);
        case 1909: return fde_func_1909_0x0f9be8(a0, a1);
        case 1910: return fde_func_1910_0x0f9c4c(a0, a1);
        case 1911: return fde_func_1911_0x0f9d1c(a0, a1);
        case 1912: return fde_func_1912_0x0f9d80(a0, a1);
        case 1913: return fde_func_1913_0x0f9e20(a0, a1);
        case 1914: return fde_func_1914_0x0f9eb8(a0, a1);
        case 1915: return fde_func_1915_0x0f9fd4(a0, a1);
        case 1916: return fde_func_1916_0x0fa01c(a0, a1);
        case 1917: return fde_func_1917_0x0fa05c(a0, a1);
        case 1918: return fde_func_1918_0x0fa098(a0, a1);
        case 1919: return fde_func_1919_0x0fa138(a0, a1);
        case 1920: return fde_func_1920_0x0fa1f4(a0, a1);
        case 1921: return fde_func_1921_0x0fa22c(a0, a1);
        case 1922: return fde_func_1922_0x0fa25c(a0, a1);
        case 1923: return fde_func_1923_0x0fa32c(a0, a1);
        case 1924: return fde_func_1924_0x0fa3a0(a0, a1);
        case 1925: return fde_func_1925_0x0fa668(a0, a1);
        case 1926: return fde_func_1926_0x0fa750(a0, a1);
        case 1927: return fde_func_1927_0x0fa800(a0, a1);
        case 1928: return fde_func_1928_0x0fa850(a0, a1);
        case 1929: return fde_func_1929_0x0fa890(a0, a1);
        case 1930: return fde_func_1930_0x0fa8d8(a0, a1);
        case 1931: return fde_func_1931_0x0faaf4(a0, a1);
        case 1932: return fde_func_1932_0x0fac2c(a0, a1);
        case 1933: return fde_func_1933_0x0facd8(a0, a1);
        case 1934: return fde_func_1934_0x0fafb8(a0, a1);
        case 1935: return fde_func_1935_0x0fb048(a0, a1);
        case 1936: return fde_func_1936_0x0fb23c(a0, a1);
        case 1937: return fde_func_1937_0x0fb3a0(a0, a1);
        case 1938: return fde_func_1938_0x0fb678(a0, a1);
        case 1939: return fde_func_1939_0x0fb684(a0, a1);
        case 1940: return fde_func_1940_0x0fb810(a0, a1);
        case 1941: return fde_func_1941_0x0fbb90(a0, a1);
        case 1942: return fde_func_1942_0x0fbc30(a0, a1);
        case 1943: return fde_func_1943_0x0fbf50(a0, a1);
        case 1944: return fde_func_1944_0x0fbff8(a0, a1);
        case 1945: return fde_func_1945_0x0fc0b8(a0, a1);
        case 1946: return fde_func_1946_0x0fc91c(a0, a1);
        case 1947: return fde_func_1947_0x0fc9c4(a0, a1);
        case 1948: return fde_func_1948_0x0fca6c(a0, a1);
        case 1949: return fde_func_1949_0x0fcb14(a0, a1);
        case 1950: return fde_func_1950_0x0fcbbc(a0, a1);
        case 1951: return fde_func_1951_0x0fcc64(a0, a1);
        case 1952: return fde_func_1952_0x0fcd0c(a0, a1);
        case 1953: return fde_func_1953_0x0fd0a0(a0, a1);
        case 1954: return fde_func_1954_0x0fd238(a0, a1);
        case 1955: return fde_func_1955_0x0fd310(a0, a1);
        case 1956: return fde_func_1956_0x0fd530(a0, a1);
        case 1957: return fde_func_1957_0x0fd62c(a0, a1);
        case 1958: return fde_func_1958_0x0fd94c(a0, a1);
        case 1959: return fde_func_1959_0x0fd9f4(a0, a1);
        case 1960: return fde_func_1960_0x0fdab4(a0, a1);
        case 1961: return fde_func_1961_0x0fde14(a0, a1);
        case 1962: return fde_func_1962_0x0fde44(a0, a1);
        case 1963: return fde_func_1963_0x0fe310(a0, a1);
        case 1964: return fde_func_1964_0x0fe3b0(a0, a1);
        case 1965: return fde_func_1965_0x0fe448(a0, a1);
        case 1966: return fde_func_1966_0x0fe914(a0, a1);
        case 1967: return fde_func_1967_0x0fede0(a0, a1);
        case 1968: return fde_func_1968_0x0ff2ac(a0, a1);
        case 1969: return fde_func_1969_0x0ff778(a0, a1);
        case 1970: return fde_func_1970_0x0ffc44(a0, a1);
        case 1971: return fde_func_1971_0x0ffdd0(a0, a1);
        case 1972: return fde_func_1972_0x0fff5c(a0, a1);
        case 1973: return fde_func_1973_0x1000e8(a0, a1);
        case 1974: return fde_func_1974_0x1004f8(a0, a1);
        case 1975: return fde_func_1975_0x1005a8(a0, a1);
        case 1976: return fde_func_1976_0x100734(a0, a1);
        case 1977: return fde_func_1977_0x100c00(a0, a1);
        case 1978: return fde_func_1978_0x1010cc(a0, a1);
        case 1979: return fde_func_1979_0x101598(a0, a1);
        case 1980: return fde_func_1980_0x101a64(a0, a1);
        case 1981: return fde_func_1981_0x101f30(a0, a1);
        case 1982: return fde_func_1982_0x1020bc(a0, a1);
        case 1983: return fde_func_1983_0x102248(a0, a1);
        case 1984: return fde_func_1984_0x1023d4(a0, a1);
        case 1985: return fde_func_1985_0x102560(a0, a1);
        case 1986: return fde_func_1986_0x1026ec(a0, a1);
        case 1987: return fde_func_1987_0x102878(a0, a1);
        case 1988: return fde_func_1988_0x102a04(a0, a1);
        case 1989: return fde_func_1989_0x102b90(a0, a1);
        case 1990: return fde_func_1990_0x102d1c(a0, a1);
        case 1991: return fde_func_1991_0x102ea8(a0, a1);
        case 1992: return fde_func_1992_0x103034(a0, a1);
        case 1993: return fde_func_1993_0x1031c0(a0, a1);
        case 1994: return fde_func_1994_0x10368c(a0, a1);
        case 1995: return fde_func_1995_0x103b58(a0, a1);
        case 1996: return fde_func_1996_0x103ce4(a0, a1);
        case 1997: return fde_func_1997_0x1041b0(a0, a1);
        case 1998: return fde_func_1998_0x10433c(a0, a1);
        case 1999: return fde_func_1999_0x10449c(a0, a1);
        case 2000: return fde_func_2000_0x104600(a0, a1);
        case 2001: return fde_func_2001_0x10478c(a0, a1);
        case 2002: return fde_func_2002_0x10484c(a0, a1);
        case 2003: return fde_func_2003_0x104908(a0, a1);
        case 2004: return fde_func_2004_0x1049c0(a0, a1);
        case 2005: return fde_func_2005_0x104aac(a0, a1);
        case 2006: return fde_func_2006_0x104c04(a0, a1);
        case 2007: return fde_func_2007_0x104d40(a0, a1);
        case 2008: return fde_func_2008_0x104ef8(a0, a1);
        case 2009: return fde_func_2009_0x105020(a0, a1);
        case 2010: return fde_func_2010_0x10516c(a0, a1);
        case 2011: return fde_func_2011_0x1054fc(a0, a1);
        case 2012: return fde_func_2012_0x1055bc(a0, a1);
        case 2013: return fde_func_2013_0x105684(a0, a1);
        case 2014: return fde_func_2014_0x10580c(a0, a1);
        case 2015: return fde_func_2015_0x105870(a0, a1);
        case 2016: return fde_func_2016_0x105988(a0, a1);
        case 2017: return fde_func_2017_0x105afc(a0, a1);
        case 2018: return fde_func_2018_0x105bcc(a0, a1);
        case 2019: return fde_func_2019_0x105d94(a0, a1);
        case 2020: return fde_func_2020_0x1062e0(a0, a1);
        case 2021: return fde_func_2021_0x106308(a0, a1);
        case 2022: return fde_func_2022_0x106348(a0, a1);
        case 2023: return fde_func_2023_0x106438(a0, a1);
        case 2024: return fde_func_2024_0x10654c(a0, a1);
        case 2025: return fde_func_2025_0x106588(a0, a1);
        case 2026: return fde_func_2026_0x1065e0(a0, a1);
        case 2027: return fde_func_2027_0x1066ec(a0, a1);
        case 2028: return fde_func_2028_0x1066f4(a0, a1);
        case 2029: return fde_func_2029_0x10674c(a0, a1);
        case 2030: return fde_func_2030_0x106754(a0, a1);
        case 2031: return fde_func_2031_0x106768(a0, a1);
        case 2032: return fde_func_2032_0x106770(a0, a1);
        case 2033: return fde_func_2033_0x106778(a0, a1);
        case 2034: return fde_func_2034_0x106780(a0, a1);
        case 2035: return fde_func_2035_0x1067a8(a0, a1);
        case 2036: return fde_func_2036_0x1067b0(a0, a1);
        case 2037: return fde_func_2037_0x1067b8(a0, a1);
        case 2038: return fde_func_2038_0x106830(a0, a1);
        case 2039: return fde_func_2039_0x106d28(a0, a1);
        case 2040: return fde_func_2040_0x10714c(a0, a1);
        case 2041: return fde_func_2041_0x107700(a0, a1);
        case 2042: return fde_func_2042_0x10790c(a0, a1);
        case 2043: return fde_func_2043_0x1079e8(a0, a1);
        case 2044: return fde_func_2044_0x107a34(a0, a1);
        case 2045: return fde_func_2045_0x107af4(a0, a1);
        case 2046: return fde_func_2046_0x107be0(a0, a1);
        case 2047: return fde_func_2047_0x107cd4(a0, a1);
        case 2048: return fde_func_2048_0x107cd8(a0, a1);
        case 2049: return fde_func_2049_0x107e50(a0, a1);
        case 2050: return fde_func_2050_0x107f44(a0, a1);
        case 2051: return fde_func_2051_0x108040(a0, a1);
        case 2052: return fde_func_2052_0x108138(a0, a1);
        case 2053: return fde_func_2053_0x10815c(a0, a1);
        case 2054: return fde_func_2054_0x10822c(a0, a1);
        case 2055: return fde_func_2055_0x108254(a0, a1);
        case 2056: return fde_func_2056_0x108294(a0, a1);
        case 2057: return fde_func_2057_0x1082b0(a0, a1);
        case 2058: return fde_func_2058_0x108370(a0, a1);
        case 2059: return fde_func_2059_0x108424(a0, a1);
        case 2060: return fde_func_2060_0x108484(a0, a1);
        case 2061: return fde_func_2061_0x1084e4(a0, a1);
        case 2062: return fde_func_2062_0x108544(a0, a1);
        case 2063: return fde_func_2063_0x108634(a0, a1);
        case 2064: return fde_func_2064_0x1086c4(a0, a1);
        case 2065: return fde_func_2065_0x1087c0(a0, a1);
        case 2066: return fde_func_2066_0x108920(a0, a1);
        case 2067: return fde_func_2067_0x108930(a0, a1);
        case 2068: return fde_func_2068_0x108d4c(a0, a1);
        case 2069: return fde_func_2069_0x108de8(a0, a1);
        case 2070: return fde_func_2070_0x108f48(a0, a1);
        case 2071: return fde_func_2071_0x10907c(a0, a1);
        case 2072: return fde_func_2072_0x1095ec(a0, a1);
        case 2073: return fde_func_2073_0x109688(a0, a1);
        case 2074: return fde_func_2074_0x109694(a0, a1);
        case 2075: return fde_func_2075_0x1096d4(a0, a1);
        case 2076: return fde_func_2076_0x109768(a0, a1);
        case 2077: return fde_func_2077_0x109774(a0, a1);
        case 2078: return fde_func_2078_0x1097a0(a0, a1);
        case 2079: return fde_func_2079_0x1098a0(a0, a1);
        case 2080: return fde_func_2080_0x1098a4(a0, a1);
        case 2081: return fde_func_2081_0x1098c8(a0, a1);
        default: return 0ULL;
    }
}

} // namespace fast_engine