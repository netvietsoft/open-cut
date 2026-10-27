// ============================================================================
// Clean-Room C++17 AArch64 Complementary FDE Shard 5/5 for libpythonA_RelWithDebInfo.so
// Phân mảnh Khung Tháo Gỡ (FDE) Bổ Sung AArch64 C++17 sạch 5/5 cho libpythonA_RelWithDebInfo.so
// Covers FDE indices [3856 .. 4319] out of 4,320 total FDEs
// Bao phủ chỉ số FDE [3856 .. 4319] trên tổng số 4.320 FDE
// ============================================================================
#include "pythonA_rel_core.h"

// FDE #3856 | PC: 0x179850 | FDE: 0x1f1400 | Size: 84 bytes
// Khung tháo gỡ #3856 | Địa chỉ PC: 0x179850 | Địa chỉ FDE: 0x1f1400 | Kích thước: 84 bytes
//   0x179850: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x179854: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x179858: 910043FD  add      x29, sp, #0x10
//   0x17985c: B0000568  adrp     x8, #0x226000
static inline uint64_t fde_func_3856_0x179850(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179850ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1400ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #3857 | PC: 0x1798a4 | FDE: 0x1f1420 | Size: 256 bytes
// Khung tháo gỡ #3857 | Địa chỉ PC: 0x1798a4 | Địa chỉ FDE: 0x1f1420 | Kích thước: 256 bytes
//   0x1798a4: D10203FF  sub      sp, sp, #0x80
//   0x1798a8: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x1798ac: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x1798b0: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_3857_0x1798a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1798a4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9045ff8ULL) ^ 0x1f1420ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3858 | PC: 0x179b78 | FDE: 0x1f1448 | Size: 68 bytes
// Khung tháo gỡ #3858 | Địa chỉ PC: 0x179b78 | Địa chỉ FDE: 0x1f1448 | Kích thước: 68 bytes
//   0x179b78: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x179b7c: 910003FD  mov      x29, sp
//   0x179b80: B0000568  adrp     x8, #0x226000
//   0x179b84: 39586108  ldrb     w8, [x8, #0x618]
static inline uint64_t fde_func_3858_0x179b78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179b78ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f1448ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #3859 | PC: 0x179bbc | FDE: 0x1f1468 | Size: 12 bytes
// Khung tháo gỡ #3859 | Địa chỉ PC: 0x179bbc | Địa chỉ FDE: 0x1f1468 | Kích thước: 12 bytes
//   0x179bbc: B0000568  adrp     x8, #0x226000
//   0x179bc0: 39586100  ldrb     w0, [x8, #0x618]
//   0x179bc4: 17FB8397  b        #0x5aa20
static inline uint64_t fde_func_3859_0x179bbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179bbcULL ^ (static_cast<uint64_t>(0xb0000568ULL) << 13);
    acc = (acc + a1 + 0x39586100ULL) ^ 0x1f1468ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #3860 | PC: 0x179bc8 | FDE: 0x1f1480 | Size: 256 bytes
// Khung tháo gỡ #3860 | Địa chỉ PC: 0x179bc8 | Địa chỉ FDE: 0x1f1480 | Kích thước: 256 bytes
//   0x179bc8: D10103FF  sub      sp, sp, #0x40
//   0x179bcc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x179bd0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x179bd4: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_3860_0x179bc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179bc8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x1f1480ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3861 | PC: 0x179cd4 | FDE: 0x1f14a0 | Size: 256 bytes
// Khung tháo gỡ #3861 | Địa chỉ PC: 0x179cd4 | Địa chỉ FDE: 0x1f14a0 | Kích thước: 256 bytes
//   0x179cd4: D10143FF  sub      sp, sp, #0x50
//   0x179cd8: F9000BF7  str      x23, [sp, #0x10]
//   0x179cdc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x179ce0: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_3861_0x179cd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179cd4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x1f14a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3862 | PC: 0x179ec4 | FDE: 0x1f14c8 | Size: 256 bytes
// Khung tháo gỡ #3862 | Địa chỉ PC: 0x179ec4 | Địa chỉ FDE: 0x1f14c8 | Kích thước: 256 bytes
//   0x179ec4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x179ec8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x179ecc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x179ed0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3862_0x179ec4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179ec4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f14c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3863 | PC: 0x17a034 | FDE: 0x1f14f0 | Size: 8 bytes
// Khung tháo gỡ #3863 | Địa chỉ PC: 0x17a034 | Địa chỉ FDE: 0x1f14f0 | Kích thước: 8 bytes
//   0x17a034: 2A1F03E0  mov      w0, wzr
//   0x17a038: D65F03C0  ret      
static inline uint64_t fde_func_3863_0x17a034(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a034ULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1f14f0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3864 | PC: 0x17a03c | FDE: 0x1f1508 | Size: 172 bytes [_PyGC_InitState]
// Khung tháo gỡ #3864 | Địa chỉ PC: 0x17a03c | Địa chỉ FDE: 0x1f1508 | Kích thước: 172 bytes
//   0x17a03c: D10183FF  sub      sp, sp, #0x60
//   0x17a040: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x17a044: 910143FD  add      x29, sp, #0x50
//   0x17a048: D53BD048  mrs      x8, tpidr_el0
static inline uint64_t fde_func_3864_0x17a03c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a03cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9057bfdULL) ^ 0x1f1508ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #3865 | PC: 0x17a0e8 | FDE: 0x1f1528 | Size: 116 bytes [_PyGC_Init]
// Khung tháo gỡ #3865 | Địa chỉ PC: 0x17a0e8 | Địa chỉ FDE: 0x1f1528 | Kích thước: 116 bytes
//   0x17a0e8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x17a0ec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17a0f0: 910043FD  add      x29, sp, #0x10
//   0x17a0f4: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_3865_0x17a0e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a0e8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1528ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #3866 | PC: 0x17a15c | FDE: 0x1f1548 | Size: 12 bytes [PyInit_gc]
// Khung tháo gỡ #3866 | Địa chỉ PC: 0x17a15c | Địa chỉ FDE: 0x1f1548 | Kích thước: 12 bytes
//   0x17a15c: D0000520  adrp     x0, #0x220000
//   0x17a160: 9117A000  add      x0, x0, #0x5e8
//   0x17a164: 17FB7A2F  b        #0x58a20
static inline uint64_t fde_func_3866_0x17a15c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a15cULL ^ (static_cast<uint64_t>(0xd0000520ULL) << 13);
    acc = (acc + a1 + 0x9117a000ULL) ^ 0x1f1548ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #3867 | PC: 0x17a168 | FDE: 0x1f1560 | Size: 48 bytes [PyGC_Enable]
// Khung tháo gỡ #3867 | Địa chỉ PC: 0x17a168 | Địa chỉ FDE: 0x1f1560 | Kích thước: 48 bytes
//   0x17a168: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x17a16c: 910003FD  mov      x29, sp
//   0x17a170: B0000428  adrp     x8, #0x1ff000
//   0x17a174: F943B908  ldr      x8, [x8, #0x770]
static inline uint64_t fde_func_3867_0x17a168(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a168ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f1560ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #3868 | PC: 0x17a198 | FDE: 0x1f1580 | Size: 44 bytes [PyGC_Disable]
// Khung tháo gỡ #3868 | Địa chỉ PC: 0x17a198 | Địa chỉ FDE: 0x1f1580 | Kích thước: 44 bytes
//   0x17a198: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x17a19c: 910003FD  mov      x29, sp
//   0x17a1a0: B0000428  adrp     x8, #0x1ff000
//   0x17a1a4: F943B908  ldr      x8, [x8, #0x770]
static inline uint64_t fde_func_3868_0x17a198(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a198ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f1580ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #3869 | PC: 0x17a1c4 | FDE: 0x1f15a0 | Size: 40 bytes [PyGC_IsEnabled]
// Khung tháo gỡ #3869 | Địa chỉ PC: 0x17a1c4 | Địa chỉ FDE: 0x1f15a0 | Kích thước: 40 bytes
//   0x17a1c4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x17a1c8: 910003FD  mov      x29, sp
//   0x17a1cc: B0000428  adrp     x8, #0x1ff000
//   0x17a1d0: F943B908  ldr      x8, [x8, #0x770]
static inline uint64_t fde_func_3869_0x17a1c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a1c4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f15a0ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #3870 | PC: 0x17a1ec | FDE: 0x1f15c0 | Size: 236 bytes [PyGC_Collect]
// Khung tháo gỡ #3870 | Địa chỉ PC: 0x17a1ec | Địa chỉ FDE: 0x1f15c0 | Kích thước: 236 bytes
//   0x17a1ec: D10183FF  sub      sp, sp, #0x60
//   0x17a1f0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x17a1f4: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x17a1f8: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_3870_0x17a1ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a1ecULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x1f15c0ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #3871 | PC: 0x17a2d8 | FDE: 0x1f15e8 | Size: 76 bytes [_PyGC_CollectNoFail]
// Khung tháo gỡ #3871 | Địa chỉ PC: 0x17a2d8 | Địa chỉ FDE: 0x1f15e8 | Kích thước: 76 bytes
//   0x17a2d8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x17a2dc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17a2e0: 910043FD  add      x29, sp, #0x10
//   0x17a2e4: F9400813  ldr      x19, [x0, #0x10]
static inline uint64_t fde_func_3871_0x17a2d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a2d8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f15e8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #3872 | PC: 0x17a324 | FDE: 0x1f1608 | Size: 256 bytes
// Khung tháo gỡ #3872 | Địa chỉ PC: 0x17a324 | Địa chỉ FDE: 0x1f1608 | Kích thước: 256 bytes
//   0x17a324: D10543FF  sub      sp, sp, #0x150
//   0x17a328: A90F6FFC  stp      x28, x27, [sp, #0xf0]
//   0x17a32c: A91067FA  stp      x26, x25, [sp, #0x100]
//   0x17a330: A9115FF8  stp      x24, x23, [sp, #0x110]
static inline uint64_t fde_func_3872_0x17a324(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a324ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa90f6ffcULL) ^ 0x1f1608ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3873 | PC: 0x17b054 | FDE: 0x1f1638 | Size: 256 bytes [_PyGC_DumpShutdownStats]
// Khung tháo gỡ #3873 | Địa chỉ PC: 0x17b054 | Địa chỉ FDE: 0x1f1638 | Kích thước: 256 bytes
//   0x17b054: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x17b058: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x17b05c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x17b060: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3873_0x17b054(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b054ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f1638ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3874 | PC: 0x17b170 | FDE: 0x1f1658 | Size: 108 bytes [_PyGC_Fini]
// Khung tháo gỡ #3874 | Địa chỉ PC: 0x17b170 | Địa chỉ FDE: 0x1f1658 | Kích thước: 108 bytes
//   0x17b170: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x17b174: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17b178: 910043FD  add      x29, sp, #0x10
//   0x17b17c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3874_0x17b170(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b170ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1658ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #3875 | PC: 0x17b1dc | FDE: 0x1f1678 | Size: 8 bytes [_PyGC_Dump]
// Khung tháo gỡ #3875 | Địa chỉ PC: 0x17b1dc | Địa chỉ FDE: 0x1f1678 | Kích thước: 8 bytes
//   0x17b1dc: 91004000  add      x0, x0, #0x10
//   0x17b1e0: 17FB7FCC  b        #0x5b110
static inline uint64_t fde_func_3875_0x17b1dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b1dcULL ^ (static_cast<uint64_t>(0x91004000ULL) << 13);
    acc = (acc + a1 + 0x17fb7fccULL) ^ 0x1f1678ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3876 | PC: 0x17b1e4 | FDE: 0x1f1690 | Size: 60 bytes [PyObject_GC_Track]
// Khung tháo gỡ #3876 | Địa chỉ PC: 0x17b1e4 | Địa chỉ FDE: 0x1f1690 | Kích thước: 60 bytes
//   0x17b1e4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x17b1e8: 910003FD  mov      x29, sp
//   0x17b1ec: F85F0008  ldur     x8, [x0, #-0x10]
//   0x17b1f0: B5000068  cbnz     x8, #0x17b1fc
static inline uint64_t fde_func_3876_0x17b1e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b1e4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f1690ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #3877 | PC: 0x17b220 | FDE: 0x1f16b0 | Size: 4 bytes [PyObject_GC_UnTrack]
// Khung tháo gỡ #3877 | Địa chỉ PC: 0x17b220 | Địa chỉ FDE: 0x1f16b0 | Kích thước: 4 bytes
//   0x17b220: D65F03C0  ret      
static inline uint64_t fde_func_3877_0x17b220(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b220ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x1f16b0ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #3878 | PC: 0x17b224 | FDE: 0x1f16c8 | Size: 72 bytes [PyObject_IS_GC]
// Khung tháo gỡ #3878 | Địa chỉ PC: 0x17b224 | Địa chỉ FDE: 0x1f16c8 | Kích thước: 72 bytes
//   0x17b224: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x17b228: 910003FD  mov      x29, sp
//   0x17b22c: F9400408  ldr      x8, [x0, #8]
//   0x17b230: 3942A509  ldrb     w9, [x8, #0xa9]
static inline uint64_t fde_func_3878_0x17b224(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b224ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f16c8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #3879 | PC: 0x17b26c | FDE: 0x1f16e8 | Size: 88 bytes [_PyObject_GC_Malloc]
// Khung tháo gỡ #3879 | Địa chỉ PC: 0x17b26c | Địa chỉ FDE: 0x1f16e8 | Kích thước: 88 bytes
//   0x17b26c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x17b270: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17b274: 910043FD  add      x29, sp, #0x10
//   0x17b278: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_3879_0x17b26c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b26cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f16e8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3880 | PC: 0x17b2c4 | FDE: 0x1f1708 | Size: 92 bytes [_PyObject_GC_Calloc]
// Khung tháo gỡ #3880 | Địa chỉ PC: 0x17b2c4 | Địa chỉ FDE: 0x1f1708 | Kích thước: 92 bytes
//   0x17b2c4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x17b2c8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17b2cc: 910043FD  add      x29, sp, #0x10
//   0x17b2d0: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_3880_0x17b2c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b2c4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1708ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #3881 | PC: 0x17b320 | FDE: 0x1f1728 | Size: 140 bytes [_PyObject_GC_New]
// Khung tháo gỡ #3881 | Địa chỉ PC: 0x17b320 | Địa chỉ FDE: 0x1f1728 | Kích thước: 140 bytes
//   0x17b320: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x17b324: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x17b328: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x17b32c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3881_0x17b320(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b320ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f1728ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #3882 | PC: 0x17b3ac | FDE: 0x1f1748 | Size: 184 bytes [_PyObject_GC_NewVar]
// Khung tháo gỡ #3882 | Địa chỉ PC: 0x17b3ac | Địa chỉ FDE: 0x1f1748 | Kích thước: 184 bytes
//   0x17b3ac: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x17b3b0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x17b3b4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x17b3b8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3882_0x17b3ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b3acULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f1748ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #3883 | PC: 0x17b464 | FDE: 0x1f1770 | Size: 104 bytes [_PyObject_GC_Resize]
// Khung tháo gỡ #3883 | Địa chỉ PC: 0x17b464 | Địa chỉ FDE: 0x1f1770 | Kích thước: 104 bytes
//   0x17b464: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x17b468: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17b46c: 910043FD  add      x29, sp, #0x10
//   0x17b470: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_3883_0x17b464(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b464ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1770ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #3884 | PC: 0x17b4cc | FDE: 0x1f1790 | Size: 112 bytes [PyObject_GC_Del]
// Khung tháo gỡ #3884 | Địa chỉ PC: 0x17b4cc | Địa chỉ FDE: 0x1f1790 | Kích thước: 112 bytes
//   0x17b4cc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x17b4d0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17b4d4: 910043FD  add      x29, sp, #0x10
//   0x17b4d8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_3884_0x17b4cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b4ccULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1790ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #3885 | PC: 0x17b53c | FDE: 0x1f17b0 | Size: 80 bytes [PyObject_GC_IsTracked]
// Khung tháo gỡ #3885 | Địa chỉ PC: 0x17b53c | Địa chỉ FDE: 0x1f17b0 | Kích thước: 80 bytes
//   0x17b53c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x17b540: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17b544: 910043FD  add      x29, sp, #0x10
//   0x17b548: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_3885_0x17b53c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b53cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f17b0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #3886 | PC: 0x17b58c | FDE: 0x1f17d0 | Size: 80 bytes [PyObject_GC_IsFinalized]
// Khung tháo gỡ #3886 | Địa chỉ PC: 0x17b58c | Địa chỉ FDE: 0x1f17d0 | Kích thước: 80 bytes
//   0x17b58c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x17b590: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17b594: 910043FD  add      x29, sp, #0x10
//   0x17b598: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_3886_0x17b58c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b58cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f17d0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #3887 | PC: 0x17b5dc | FDE: 0x1f17f0 | Size: 256 bytes
// Khung tháo gỡ #3887 | Địa chỉ PC: 0x17b5dc | Địa chỉ FDE: 0x1f17f0 | Kích thước: 256 bytes
//   0x17b5dc: D101C3FF  sub      sp, sp, #0x70
//   0x17b5e0: F9001BF7  str      x23, [sp, #0x30]
//   0x17b5e4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x17b5e8: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_3887_0x17b5dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b5dcULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x1f17f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3888 | PC: 0x17b784 | FDE: 0x1f1818 | Size: 228 bytes
// Khung tháo gỡ #3888 | Địa chỉ PC: 0x17b784 | Địa chỉ FDE: 0x1f1818 | Kích thước: 228 bytes
//   0x17b784: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x17b788: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17b78c: 910043FD  add      x29, sp, #0x10
//   0x17b790: 90000428  adrp     x8, #0x1ff000
static inline uint64_t fde_func_3888_0x17b784(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b784ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1818ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #3889 | PC: 0x17b868 | FDE: 0x1f1838 | Size: 256 bytes
// Khung tháo gỡ #3889 | Địa chỉ PC: 0x17b868 | Địa chỉ FDE: 0x1f1838 | Kích thước: 256 bytes
//   0x17b868: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x17b86c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x17b870: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x17b874: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3889_0x17b868(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b868ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f1838ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3890 | PC: 0x17b9c4 | FDE: 0x1f1860 | Size: 80 bytes
// Khung tháo gỡ #3890 | Địa chỉ PC: 0x17b9c4 | Địa chỉ FDE: 0x1f1860 | Kích thước: 80 bytes
//   0x17b9c4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x17b9c8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17b9cc: 910043FD  add      x29, sp, #0x10
//   0x17b9d0: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_3890_0x17b9c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b9c4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1860ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #3891 | PC: 0x17ba14 | FDE: 0x1f1880 | Size: 172 bytes
// Khung tháo gỡ #3891 | Địa chỉ PC: 0x17ba14 | Địa chỉ FDE: 0x1f1880 | Kích thước: 172 bytes
//   0x17ba14: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x17ba18: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17ba1c: 910043FD  add      x29, sp, #0x10
//   0x17ba20: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_3891_0x17ba14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ba14ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1880ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #3892 | PC: 0x17bac0 | FDE: 0x1f18a0 | Size: 144 bytes
// Khung tháo gỡ #3892 | Địa chỉ PC: 0x17bac0 | Địa chỉ FDE: 0x1f18a0 | Kích thước: 144 bytes
//   0x17bac0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x17bac4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17bac8: 910043FD  add      x29, sp, #0x10
//   0x17bacc: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_3892_0x17bac0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17bac0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f18a0ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #3893 | PC: 0x17bb50 | FDE: 0x1f18c0 | Size: 92 bytes [Py_GetBuildInfo]
// Khung tháo gỡ #3893 | Địa chỉ PC: 0x17bb50 | Địa chỉ FDE: 0x1f18c0 | Kích thước: 92 bytes
//   0x17bb50: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x17bb54: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17bb58: 910043FD  add      x29, sp, #0x10
//   0x17bb5c: F0000553  adrp     x19, #0x226000
static inline uint64_t fde_func_3893_0x17bb50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17bb50ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f18c0ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #3894 | PC: 0x17bbac | FDE: 0x1f18e0 | Size: 12 bytes [_Py_gitversion]
// Khung tháo gỡ #3894 | Địa chỉ PC: 0x17bbac | Địa chỉ FDE: 0x1f18e0 | Kích thước: 12 bytes
//   0x17bbac: B0000220  adrp     x0, #0x1c0000
//   0x17bbb0: 91042C00  add      x0, x0, #0x10b
//   0x17bbb4: D65F03C0  ret      
static inline uint64_t fde_func_3894_0x17bbac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17bbacULL ^ (static_cast<uint64_t>(0xb0000220ULL) << 13);
    acc = (acc + a1 + 0x91042c00ULL) ^ 0x1f18e0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #3895 | PC: 0x17bbb8 | FDE: 0x1f18f8 | Size: 12 bytes [_Py_gitidentifier]
// Khung tháo gỡ #3895 | Địa chỉ PC: 0x17bbb8 | Địa chỉ FDE: 0x1f18f8 | Kích thước: 12 bytes
//   0x17bbb8: B0000220  adrp     x0, #0x1c0000
//   0x17bbbc: 91042C00  add      x0, x0, #0x10b
//   0x17bbc0: D65F03C0  ret      
static inline uint64_t fde_func_3895_0x17bbb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17bbb8ULL ^ (static_cast<uint64_t>(0xb0000220ULL) << 13);
    acc = (acc + a1 + 0x91042c00ULL) ^ 0x1f18f8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #3896 | PC: 0x17bbc4 | FDE: 0x1f1910 | Size: 256 bytes [_PyPathConfig_Calculate]
// Khung tháo gỡ #3896 | Địa chỉ PC: 0x17bbc4 | Địa chỉ FDE: 0x1f1910 | Kích thước: 256 bytes
//   0x17bbc4: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x17bbc8: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x17bbcc: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x17bbd0: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_3896_0x17bbc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17bbc4ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1f1910ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3897 | PC: 0x17d640 | FDE: 0x1f1940 | Size: 192 bytes
// Khung tháo gỡ #3897 | Địa chỉ PC: 0x17d640 | Địa chỉ FDE: 0x1f1940 | Kích thước: 192 bytes
//   0x17d640: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x17d644: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x17d648: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x17d64c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3897_0x17d640(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d640ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f1940ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #3898 | PC: 0x17d700 | FDE: 0x1f1968 | Size: 256 bytes
// Khung tháo gỡ #3898 | Địa chỉ PC: 0x17d700 | Địa chỉ FDE: 0x1f1968 | Kích thước: 256 bytes
//   0x17d700: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x17d704: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x17d708: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x17d70c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3898_0x17d700(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d700ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f1968ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3899 | PC: 0x17d870 | FDE: 0x1f1990 | Size: 256 bytes
// Khung tháo gỡ #3899 | Địa chỉ PC: 0x17d870 | Địa chỉ FDE: 0x1f1990 | Kích thước: 256 bytes
//   0x17d870: D10303FF  sub      sp, sp, #0xc0
//   0x17d874: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x17d878: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x17d87c: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_3899_0x17d870(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d870ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9085ff8ULL) ^ 0x1f1990ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3900 | PC: 0x17d9f4 | FDE: 0x1f19b8 | Size: 12 bytes [PyInit_math]
// Khung tháo gỡ #3900 | Địa chỉ PC: 0x17d9f4 | Địa chỉ FDE: 0x1f19b8 | Kích thước: 12 bytes
//   0x17d9f4: F0000500  adrp     x0, #0x220000
//   0x17d9f8: 911BC000  add      x0, x0, #0x6f0
//   0x17d9fc: 17FB6C09  b        #0x58a20
static inline uint64_t fde_func_3900_0x17d9f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d9f4ULL ^ (static_cast<uint64_t>(0xf0000500ULL) << 13);
    acc = (acc + a1 + 0x911bc000ULL) ^ 0x1f19b8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #3901 | PC: 0x17da00 | FDE: 0x1f19d0 | Size: 176 bytes
// Khung tháo gỡ #3901 | Địa chỉ PC: 0x17da00 | Địa chỉ FDE: 0x1f19d0 | Kích thước: 176 bytes
//   0x17da00: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x17da04: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17da08: 910043FD  add      x29, sp, #0x10
//   0x17da0c: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_3901_0x17da00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17da00ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f19d0ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #3902 | PC: 0x17dab0 | FDE: 0x1f19f0 | Size: 176 bytes
// Khung tháo gỡ #3902 | Địa chỉ PC: 0x17dab0 | Địa chỉ FDE: 0x1f19f0 | Kích thước: 176 bytes
//   0x17dab0: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x17dab4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17dab8: 910043FD  add      x29, sp, #0x10
//   0x17dabc: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_3902_0x17dab0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17dab0ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f19f0ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #3903 | PC: 0x17db60 | FDE: 0x1f1a10 | Size: 176 bytes
// Khung tháo gỡ #3903 | Địa chỉ PC: 0x17db60 | Địa chỉ FDE: 0x1f1a10 | Kích thước: 176 bytes
//   0x17db60: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x17db64: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17db68: 910043FD  add      x29, sp, #0x10
//   0x17db6c: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_3903_0x17db60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17db60ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1a10ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #3904 | PC: 0x17dc10 | FDE: 0x1f1a30 | Size: 176 bytes
// Khung tháo gỡ #3904 | Địa chỉ PC: 0x17dc10 | Địa chỉ FDE: 0x1f1a30 | Kích thước: 176 bytes
//   0x17dc10: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x17dc14: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17dc18: 910043FD  add      x29, sp, #0x10
//   0x17dc1c: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_3904_0x17dc10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17dc10ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1a30ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #3905 | PC: 0x17dcc0 | FDE: 0x1f1a50 | Size: 176 bytes
// Khung tháo gỡ #3905 | Địa chỉ PC: 0x17dcc0 | Địa chỉ FDE: 0x1f1a50 | Kích thước: 176 bytes
//   0x17dcc0: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x17dcc4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17dcc8: 910043FD  add      x29, sp, #0x10
//   0x17dccc: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_3905_0x17dcc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17dcc0ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1a50ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #3906 | PC: 0x17dd70 | FDE: 0x1f1a70 | Size: 32 bytes
// Khung tháo gỡ #3906 | Địa chỉ PC: 0x17dd70 | Địa chỉ FDE: 0x1f1a70 | Kích thước: 32 bytes
//   0x17dd70: AA0203E8  mov      x8, x2
//   0x17dd74: B0000022  adrp     x2, #0x182000
//   0x17dd78: B0000243  adrp     x3, #0x1c6000
//   0x17dd7c: 9128D042  add      x2, x2, #0xa34
static inline uint64_t fde_func_3906_0x17dd70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17dd70ULL ^ (static_cast<uint64_t>(0xaa0203e8ULL) << 13);
    acc = (acc + a1 + 0xb0000022ULL) ^ 0x1f1a70ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #3907 | PC: 0x17dd90 | FDE: 0x1f1a88 | Size: 176 bytes
// Khung tháo gỡ #3907 | Địa chỉ PC: 0x17dd90 | Địa chỉ FDE: 0x1f1a88 | Kích thước: 176 bytes
//   0x17dd90: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x17dd94: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17dd98: 910043FD  add      x29, sp, #0x10
//   0x17dd9c: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_3907_0x17dd90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17dd90ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1a88ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #3908 | PC: 0x17de40 | FDE: 0x1f1aa8 | Size: 256 bytes
// Khung tháo gỡ #3908 | Địa chỉ PC: 0x17de40 | Địa chỉ FDE: 0x1f1aa8 | Kích thước: 256 bytes
//   0x17de40: FC1D0FE8  str      d8, [sp, #-0x30]!
//   0x17de44: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x17de48: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x17de4c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3908_0x17de40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17de40ULL ^ (static_cast<uint64_t>(0xfc1d0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f1aa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3909 | PC: 0x17df58 | FDE: 0x1f1ac8 | Size: 256 bytes
// Khung tháo gỡ #3909 | Địa chỉ PC: 0x17df58 | Địa chỉ FDE: 0x1f1ac8 | Kích thước: 256 bytes
//   0x17df58: D10103FF  sub      sp, sp, #0x40
//   0x17df5c: FD0013E8  str      d8, [sp, #0x20]
//   0x17df60: F90017F3  str      x19, [sp, #0x28]
//   0x17df64: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3909_0x17df58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17df58ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xfd0013e8ULL) ^ 0x1f1ac8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3910 | PC: 0x17e0b8 | FDE: 0x1f1ae8 | Size: 176 bytes
// Khung tháo gỡ #3910 | Địa chỉ PC: 0x17e0b8 | Địa chỉ FDE: 0x1f1ae8 | Kích thước: 176 bytes
//   0x17e0b8: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x17e0bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17e0c0: 910043FD  add      x29, sp, #0x10
//   0x17e0c4: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_3910_0x17e0b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e0b8ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1ae8ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #3911 | PC: 0x17e168 | FDE: 0x1f1b08 | Size: 196 bytes
// Khung tháo gỡ #3911 | Địa chỉ PC: 0x17e168 | Địa chỉ FDE: 0x1f1b08 | Kích thước: 196 bytes
//   0x17e168: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x17e16c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17e170: 910043FD  add      x29, sp, #0x10
//   0x17e174: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_3911_0x17e168(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e168ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1b08ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #3912 | PC: 0x17e22c | FDE: 0x1f1b28 | Size: 112 bytes
// Khung tháo gỡ #3912 | Địa chỉ PC: 0x17e22c | Địa chỉ FDE: 0x1f1b28 | Kích thước: 112 bytes
//   0x17e22c: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x17e230: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17e234: 910043FD  add      x29, sp, #0x10
//   0x17e238: B0000409  adrp     x9, #0x1ff000
static inline uint64_t fde_func_3912_0x17e22c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e22cULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1b28ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #3913 | PC: 0x17e29c | FDE: 0x1f1b48 | Size: 256 bytes
// Khung tháo gỡ #3913 | Địa chỉ PC: 0x17e29c | Địa chỉ FDE: 0x1f1b48 | Kích thước: 256 bytes
//   0x17e29c: D10483FF  sub      sp, sp, #0x120
//   0x17e2a0: FD0053EA  str      d10, [sp, #0xa0]
//   0x17e2a4: 6D0B23E9  stp      d9, d8, [sp, #0xb0]
//   0x17e2a8: A90C6FFC  stp      x28, x27, [sp, #0xc0]
static inline uint64_t fde_func_3913_0x17e29c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e29cULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xfd0053eaULL) ^ 0x1f1b48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3914 | PC: 0x17e5c0 | FDE: 0x1f1b80 | Size: 88 bytes
// Khung tháo gỡ #3914 | Địa chỉ PC: 0x17e5c0 | Địa chỉ FDE: 0x1f1b80 | Kích thước: 88 bytes
//   0x17e5c0: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x17e5c4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17e5c8: 910043FD  add      x29, sp, #0x10
//   0x17e5cc: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_3914_0x17e5c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e5c0ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1b80ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3915 | PC: 0x17e618 | FDE: 0x1f1ba0 | Size: 88 bytes
// Khung tháo gỡ #3915 | Địa chỉ PC: 0x17e618 | Địa chỉ FDE: 0x1f1ba0 | Kích thước: 88 bytes
//   0x17e618: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x17e61c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17e620: 910043FD  add      x29, sp, #0x10
//   0x17e624: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_3915_0x17e618(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e618ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1ba0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #3916 | PC: 0x17e670 | FDE: 0x1f1bc0 | Size: 192 bytes
// Khung tháo gỡ #3916 | Địa chỉ PC: 0x17e670 | Địa chỉ FDE: 0x1f1bc0 | Kích thước: 192 bytes
//   0x17e670: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x17e674: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17e678: 910043FD  add      x29, sp, #0x10
//   0x17e67c: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_3916_0x17e670(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e670ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1bc0ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #3917 | PC: 0x17e730 | FDE: 0x1f1be0 | Size: 196 bytes
// Khung tháo gỡ #3917 | Địa chỉ PC: 0x17e730 | Địa chỉ FDE: 0x1f1be0 | Kích thước: 196 bytes
//   0x17e730: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x17e734: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17e738: 910043FD  add      x29, sp, #0x10
//   0x17e73c: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_3917_0x17e730(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e730ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1be0ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #3918 | PC: 0x17e7f4 | FDE: 0x1f1c00 | Size: 84 bytes
// Khung tháo gỡ #3918 | Địa chỉ PC: 0x17e7f4 | Địa chỉ FDE: 0x1f1c00 | Kích thước: 84 bytes
//   0x17e7f4: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x17e7f8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17e7fc: 910043FD  add      x29, sp, #0x10
//   0x17e800: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_3918_0x17e7f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e7f4ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1c00ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #3919 | PC: 0x17e848 | FDE: 0x1f1c20 | Size: 256 bytes
// Khung tháo gỡ #3919 | Địa chỉ PC: 0x17e848 | Địa chỉ FDE: 0x1f1c20 | Kích thước: 256 bytes
//   0x17e848: D101C3FF  sub      sp, sp, #0x70
//   0x17e84c: F9000BFB  str      x27, [sp, #0x10]
//   0x17e850: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x17e854: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_3919_0x17e848(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e848ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfbULL) ^ 0x1f1c20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3920 | PC: 0x17eacc | FDE: 0x1f1c50 | Size: 256 bytes
// Khung tháo gỡ #3920 | Địa chỉ PC: 0x17eacc | Địa chỉ FDE: 0x1f1c50 | Kích thước: 256 bytes
//   0x17eacc: FC1D0FE8  str      d8, [sp, #-0x30]!
//   0x17ead0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x17ead4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x17ead8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3920_0x17eacc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17eaccULL ^ (static_cast<uint64_t>(0xfc1d0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f1c50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3921 | PC: 0x17ebf0 | FDE: 0x1f1c70 | Size: 256 bytes
// Khung tháo gỡ #3921 | Địa chỉ PC: 0x17ebf0 | Địa chỉ FDE: 0x1f1c70 | Kích thước: 256 bytes
//   0x17ebf0: 6DBD23E9  stp      d9, d8, [sp, #-0x30]!
//   0x17ebf4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x17ebf8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x17ebfc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3921_0x17ebf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ebf0ULL ^ (static_cast<uint64_t>(0x6dbd23e9ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f1c70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3922 | PC: 0x17ed50 | FDE: 0x1f1c98 | Size: 180 bytes
// Khung tháo gỡ #3922 | Địa chỉ PC: 0x17ed50 | Địa chỉ FDE: 0x1f1c98 | Kích thước: 180 bytes
//   0x17ed50: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x17ed54: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17ed58: 910043FD  add      x29, sp, #0x10
//   0x17ed5c: B0000409  adrp     x9, #0x1ff000
static inline uint64_t fde_func_3922_0x17ed50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ed50ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1c98ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #3923 | PC: 0x17ee04 | FDE: 0x1f1cb8 | Size: 256 bytes
// Khung tháo gỡ #3923 | Địa chỉ PC: 0x17ee04 | Địa chỉ FDE: 0x1f1cb8 | Kích thước: 256 bytes
//   0x17ee04: D10703FF  sub      sp, sp, #0x1c0
//   0x17ee08: FD009BEC  str      d12, [sp, #0x130]
//   0x17ee0c: 6D142BEB  stp      d11, d10, [sp, #0x140]
//   0x17ee10: 6D1523E9  stp      d9, d8, [sp, #0x150]
static inline uint64_t fde_func_3923_0x17ee04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ee04ULL ^ (static_cast<uint64_t>(0xd10703ffULL) << 13);
    acc = (acc + a1 + 0xfd009becULL) ^ 0x1f1cb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3924 | PC: 0x17f244 | FDE: 0x1f1cf8 | Size: 256 bytes
// Khung tháo gỡ #3924 | Địa chỉ PC: 0x17f244 | Địa chỉ FDE: 0x1f1cf8 | Kích thước: 256 bytes
//   0x17f244: D10143FF  sub      sp, sp, #0x50
//   0x17f248: FD0013EA  str      d10, [sp, #0x20]
//   0x17f24c: 6D02A3E9  stp      d9, d8, [sp, #0x28]
//   0x17f250: F9001FF3  str      x19, [sp, #0x38]
static inline uint64_t fde_func_3924_0x17f244(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f244ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xfd0013eaULL) ^ 0x1f1cf8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3925 | PC: 0x17fa7c | FDE: 0x1f1d20 | Size: 256 bytes
// Khung tháo gỡ #3925 | Địa chỉ PC: 0x17fa7c | Địa chỉ FDE: 0x1f1d20 | Kích thước: 256 bytes
//   0x17fa7c: B4000302  cbz      x2, #0x17fadc
//   0x17fa80: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x17fa84: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x17fa88: A9024FF4  stp      x20, x19, [sp, #0x20]
static inline uint64_t fde_func_3925_0x17fa7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17fa7cULL ^ (static_cast<uint64_t>(0xb4000302ULL) << 13);
    acc = (acc + a1 + 0xa9bc5ff8ULL) ^ 0x1f1d20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3926 | PC: 0x17fbdc | FDE: 0x1f1d48 | Size: 256 bytes
// Khung tháo gỡ #3926 | Địa chỉ PC: 0x17fbdc | Địa chỉ FDE: 0x1f1d48 | Kích thước: 256 bytes
//   0x17fbdc: D103C3FF  sub      sp, sp, #0xf0
//   0x17fbe0: 6D0923E9  stp      d9, d8, [sp, #0x90]
//   0x17fbe4: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x17fbe8: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_3926_0x17fbdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17fbdcULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0x6d0923e9ULL) ^ 0x1f1d48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3927 | PC: 0x17fd6c | FDE: 0x1f1d78 | Size: 256 bytes
// Khung tháo gỡ #3927 | Địa chỉ PC: 0x17fd6c | Địa chỉ FDE: 0x1f1d78 | Kích thước: 256 bytes
//   0x17fd6c: D10203FF  sub      sp, sp, #0x80
//   0x17fd70: 6D032BEB  stp      d11, d10, [sp, #0x30]
//   0x17fd74: 6D0423E9  stp      d9, d8, [sp, #0x40]
//   0x17fd78: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_3927_0x17fd6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17fd6cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0x6d032bebULL) ^ 0x1f1d78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3928 | PC: 0x17ffe8 | FDE: 0x1f1da8 | Size: 124 bytes
// Khung tháo gỡ #3928 | Địa chỉ PC: 0x17ffe8 | Địa chỉ FDE: 0x1f1da8 | Kích thước: 124 bytes
//   0x17ffe8: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x17ffec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17fff0: 910043FD  add      x29, sp, #0x10
//   0x17fff4: 90000409  adrp     x9, #0x1ff000
static inline uint64_t fde_func_3928_0x17ffe8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ffe8ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1da8ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #3929 | PC: 0x180064 | FDE: 0x1f1dc8 | Size: 120 bytes
// Khung tháo gỡ #3929 | Địa chỉ PC: 0x180064 | Địa chỉ FDE: 0x1f1dc8 | Kích thước: 120 bytes
//   0x180064: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x180068: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18006c: 910043FD  add      x29, sp, #0x10
//   0x180070: F00003E9  adrp     x9, #0x1ff000
static inline uint64_t fde_func_3929_0x180064(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x180064ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1dc8ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #3930 | PC: 0x1800dc | FDE: 0x1f1de8 | Size: 108 bytes
// Khung tháo gỡ #3930 | Địa chỉ PC: 0x1800dc | Địa chỉ FDE: 0x1f1de8 | Kích thước: 108 bytes
//   0x1800dc: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x1800e0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1800e4: 910043FD  add      x29, sp, #0x10
//   0x1800e8: F00003E9  adrp     x9, #0x1ff000
static inline uint64_t fde_func_3930_0x1800dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1800dcULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1de8ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #3931 | PC: 0x180148 | FDE: 0x1f1e08 | Size: 256 bytes
// Khung tháo gỡ #3931 | Địa chỉ PC: 0x180148 | Địa chỉ FDE: 0x1f1e08 | Kích thước: 256 bytes
//   0x180148: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x18014c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x180150: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x180154: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_3931_0x180148(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x180148ULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1f1e08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3932 | PC: 0x180560 | FDE: 0x1f1e38 | Size: 256 bytes
// Khung tháo gỡ #3932 | Địa chỉ PC: 0x180560 | Địa chỉ FDE: 0x1f1e38 | Kích thước: 256 bytes
//   0x180560: B4000322  cbz      x2, #0x1805c4
//   0x180564: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x180568: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x18056c: A90257F6  stp      x22, x21, [sp, #0x20]
static inline uint64_t fde_func_3932_0x180560(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x180560ULL ^ (static_cast<uint64_t>(0xb4000322ULL) << 13);
    acc = (acc + a1 + 0xf81b0ff9ULL) ^ 0x1f1e38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3933 | PC: 0x180770 | FDE: 0x1f1e60 | Size: 256 bytes
// Khung tháo gỡ #3933 | Địa chỉ PC: 0x180770 | Địa chỉ FDE: 0x1f1e60 | Kích thước: 256 bytes
//   0x180770: D10183FF  sub      sp, sp, #0x60
//   0x180774: F9001BF5  str      x21, [sp, #0x30]
//   0x180778: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x18077c: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_3933_0x180770(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x180770ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x1f1e60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3934 | PC: 0x180988 | FDE: 0x1f1e80 | Size: 256 bytes
// Khung tháo gỡ #3934 | Địa chỉ PC: 0x180988 | Địa chỉ FDE: 0x1f1e80 | Kích thước: 256 bytes
//   0x180988: D10143FF  sub      sp, sp, #0x50
//   0x18098c: FD000BEC  str      d12, [sp, #0x10]
//   0x180990: 6D01ABEB  stp      d11, d10, [sp, #0x18]
//   0x180994: 6D02A3E9  stp      d9, d8, [sp, #0x28]
static inline uint64_t fde_func_3934_0x180988(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x180988ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xfd000becULL) ^ 0x1f1e80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3935 | PC: 0x180df4 | FDE: 0x1f1eb0 | Size: 256 bytes
// Khung tháo gỡ #3935 | Địa chỉ PC: 0x180df4 | Địa chỉ FDE: 0x1f1eb0 | Kích thước: 256 bytes
//   0x180df4: D10143FF  sub      sp, sp, #0x50
//   0x180df8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x180dfc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x180e00: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_3935_0x180df4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x180df4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1f1eb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3936 | PC: 0x180f50 | FDE: 0x1f1ed8 | Size: 256 bytes
// Khung tháo gỡ #3936 | Địa chỉ PC: 0x180f50 | Địa chỉ FDE: 0x1f1ed8 | Kích thước: 256 bytes
//   0x180f50: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x180f54: F90007F3  str      x19, [sp, #8]
//   0x180f58: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x180f5c: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_3936_0x180f50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x180f50ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xf90007f3ULL) ^ 0x1f1ed8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3937 | PC: 0x181074 | FDE: 0x1f1ef8 | Size: 20 bytes
// Khung tháo gỡ #3937 | Địa chỉ PC: 0x181074 | Địa chỉ FDE: 0x1f1ef8 | Kích thước: 20 bytes
//   0x181074: B0000008  adrp     x8, #0x182000
//   0x181078: 913ED108  add      x8, x8, #0xfb4
//   0x18107c: AA0103E0  mov      x0, x1
//   0x181080: AA0803E1  mov      x1, x8
static inline uint64_t fde_func_3937_0x181074(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x181074ULL ^ (static_cast<uint64_t>(0xb0000008ULL) << 13);
    acc = (acc + a1 + 0x913ed108ULL) ^ 0x1f1ef8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #3938 | PC: 0x181088 | FDE: 0x1f1f10 | Size: 20 bytes
// Khung tháo gỡ #3938 | Địa chỉ PC: 0x181088 | Địa chỉ FDE: 0x1f1f10 | Kích thước: 20 bytes
//   0x181088: D0000008  adrp     x8, #0x183000
//   0x18108c: 91013108  add      x8, x8, #0x4c
//   0x181090: AA0103E0  mov      x0, x1
//   0x181094: AA0803E1  mov      x1, x8
static inline uint64_t fde_func_3938_0x181088(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x181088ULL ^ (static_cast<uint64_t>(0xd0000008ULL) << 13);
    acc = (acc + a1 + 0x91013108ULL) ^ 0x1f1f10ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #3939 | PC: 0x18109c | FDE: 0x1f1f28 | Size: 232 bytes
// Khung tháo gỡ #3939 | Địa chỉ PC: 0x18109c | Địa chỉ FDE: 0x1f1f28 | Kích thước: 232 bytes
//   0x18109c: D100C3FF  sub      sp, sp, #0x30
//   0x1810a0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1810a4: 910083FD  add      x29, sp, #0x20
//   0x1810a8: D00003E9  adrp     x9, #0x1ff000
static inline uint64_t fde_func_3939_0x18109c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18109cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9027bfdULL) ^ 0x1f1f28ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #3940 | PC: 0x181184 | FDE: 0x1f1f48 | Size: 256 bytes
// Khung tháo gỡ #3940 | Địa chỉ PC: 0x181184 | Địa chỉ FDE: 0x1f1f48 | Kích thước: 256 bytes
//   0x181184: D10143FF  sub      sp, sp, #0x50
//   0x181188: FD000BEA  str      d10, [sp, #0x10]
//   0x18118c: 6D0223E9  stp      d9, d8, [sp, #0x20]
//   0x181190: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_3940_0x181184(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x181184ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xfd000beaULL) ^ 0x1f1f48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3941 | PC: 0x181470 | FDE: 0x1f1f70 | Size: 112 bytes
// Khung tháo gỡ #3941 | Địa chỉ PC: 0x181470 | Địa chỉ FDE: 0x1f1f70 | Kích thước: 112 bytes
//   0x181470: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x181474: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x181478: 910043FD  add      x29, sp, #0x10
//   0x18147c: D00003E9  adrp     x9, #0x1ff000
static inline uint64_t fde_func_3941_0x181470(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x181470ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1f70ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #3942 | PC: 0x1814e0 | FDE: 0x1f1f90 | Size: 32 bytes
// Khung tháo gỡ #3942 | Địa chỉ PC: 0x1814e0 | Địa chỉ FDE: 0x1f1f90 | Kích thước: 32 bytes
//   0x1814e0: AA0203E8  mov      x8, x2
//   0x1814e4: D0000002  adrp     x2, #0x183000
//   0x1814e8: B0000223  adrp     x3, #0x1c6000
//   0x1814ec: 91039042  add      x2, x2, #0xe4
static inline uint64_t fde_func_3942_0x1814e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1814e0ULL ^ (static_cast<uint64_t>(0xaa0203e8ULL) << 13);
    acc = (acc + a1 + 0xd0000002ULL) ^ 0x1f1f90ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #3943 | PC: 0x181500 | FDE: 0x1f1fa8 | Size: 176 bytes
// Khung tháo gỡ #3943 | Địa chỉ PC: 0x181500 | Địa chỉ FDE: 0x1f1fa8 | Kích thước: 176 bytes
//   0x181500: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x181504: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x181508: 910043FD  add      x29, sp, #0x10
//   0x18150c: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_3943_0x181500(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x181500ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1fa8ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #3944 | PC: 0x1815b0 | FDE: 0x1f1fc8 | Size: 196 bytes
// Khung tháo gỡ #3944 | Địa chỉ PC: 0x1815b0 | Địa chỉ FDE: 0x1f1fc8 | Kích thước: 196 bytes
//   0x1815b0: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x1815b4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1815b8: 910043FD  add      x29, sp, #0x10
//   0x1815bc: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_3944_0x1815b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1815b0ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1fc8ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #3945 | PC: 0x181674 | FDE: 0x1f1fe8 | Size: 172 bytes
// Khung tháo gỡ #3945 | Địa chỉ PC: 0x181674 | Địa chỉ FDE: 0x1f1fe8 | Kích thước: 172 bytes
//   0x181674: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x181678: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18167c: 910043FD  add      x29, sp, #0x10
//   0x181680: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_3945_0x181674(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x181674ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f1fe8ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #3946 | PC: 0x181720 | FDE: 0x1f2008 | Size: 176 bytes
// Khung tháo gỡ #3946 | Địa chỉ PC: 0x181720 | Địa chỉ FDE: 0x1f2008 | Kích thước: 176 bytes
//   0x181720: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x181724: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x181728: 910043FD  add      x29, sp, #0x10
//   0x18172c: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_3946_0x181720(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x181720ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f2008ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #3947 | PC: 0x1817d0 | FDE: 0x1f2028 | Size: 176 bytes
// Khung tháo gỡ #3947 | Địa chỉ PC: 0x1817d0 | Địa chỉ FDE: 0x1f2028 | Kích thước: 176 bytes
//   0x1817d0: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x1817d4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1817d8: 910043FD  add      x29, sp, #0x10
//   0x1817dc: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_3947_0x1817d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1817d0ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f2028ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #3948 | PC: 0x181880 | FDE: 0x1f2048 | Size: 256 bytes
// Khung tháo gỡ #3948 | Địa chỉ PC: 0x181880 | Địa chỉ FDE: 0x1f2048 | Kích thước: 256 bytes
//   0x181880: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x181884: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x181888: 910043FD  add      x29, sp, #0x10
//   0x18188c: D00003E8  adrp     x8, #0x1ff000
static inline uint64_t fde_func_3948_0x181880(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x181880ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f2048ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3949 | PC: 0x1819a4 | FDE: 0x1f2068 | Size: 256 bytes
// Khung tháo gỡ #3949 | Địa chỉ PC: 0x1819a4 | Địa chỉ FDE: 0x1f2068 | Kích thước: 256 bytes
//   0x1819a4: D10243FF  sub      sp, sp, #0x90
//   0x1819a8: 6D0323E9  stp      d9, d8, [sp, #0x30]
//   0x1819ac: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x1819b0: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_3949_0x1819a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1819a4ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0x6d0323e9ULL) ^ 0x1f2068ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3950 | PC: 0x181e74 | FDE: 0x1f2098 | Size: 256 bytes
// Khung tháo gỡ #3950 | Địa chỉ PC: 0x181e74 | Địa chỉ FDE: 0x1f2098 | Kích thước: 256 bytes
//   0x181e74: D101C3FF  sub      sp, sp, #0x70
//   0x181e78: F9000BFB  str      x27, [sp, #0x10]
//   0x181e7c: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x181e80: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_3950_0x181e74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x181e74ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfbULL) ^ 0x1f2098ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3951 | PC: 0x182198 | FDE: 0x1f20c8 | Size: 256 bytes
// Khung tháo gỡ #3951 | Địa chỉ PC: 0x182198 | Địa chỉ FDE: 0x1f20c8 | Kích thước: 256 bytes
//   0x182198: D101C3FF  sub      sp, sp, #0x70
//   0x18219c: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x1821a0: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x1821a4: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_3951_0x182198(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x182198ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x1f20c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3952 | PC: 0x18255c | FDE: 0x1f20f8 | Size: 224 bytes
// Khung tháo gỡ #3952 | Địa chỉ PC: 0x18255c | Địa chỉ FDE: 0x1f20f8 | Kích thước: 224 bytes
//   0x18255c: 6DBD23E9  stp      d9, d8, [sp, #-0x30]!
//   0x182560: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x182564: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x182568: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3952_0x18255c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18255cULL ^ (static_cast<uint64_t>(0x6dbd23e9ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f20f8ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #3953 | PC: 0x18263c | FDE: 0x1f2120 | Size: 228 bytes
// Khung tháo gỡ #3953 | Địa chỉ PC: 0x18263c | Địa chỉ FDE: 0x1f2120 | Kích thước: 228 bytes
//   0x18263c: 6DBE23E9  stp      d9, d8, [sp, #-0x20]!
//   0x182640: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x182644: 910043FD  add      x29, sp, #0x10
//   0x182648: B00003E9  adrp     x9, #0x1ff000
static inline uint64_t fde_func_3953_0x18263c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18263cULL ^ (static_cast<uint64_t>(0x6dbe23e9ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f2120ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #3954 | PC: 0x182720 | FDE: 0x1f2140 | Size: 256 bytes
// Khung tháo gỡ #3954 | Địa chỉ PC: 0x182720 | Địa chỉ FDE: 0x1f2140 | Kích thước: 256 bytes
//   0x182720: FC1D0FE8  str      d8, [sp, #-0x30]!
//   0x182724: F90007F5  str      x21, [sp, #8]
//   0x182728: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x18272c: A9027BFD  stp      x29, x30, [sp, #0x20]
static inline uint64_t fde_func_3954_0x182720(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x182720ULL ^ (static_cast<uint64_t>(0xfc1d0fe8ULL) << 13);
    acc = (acc + a1 + 0xf90007f5ULL) ^ 0x1f2140ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3955 | PC: 0x182858 | FDE: 0x1f2168 | Size: 144 bytes
// Khung tháo gỡ #3955 | Địa chỉ PC: 0x182858 | Địa chỉ FDE: 0x1f2168 | Kích thước: 144 bytes
//   0x182858: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x18285c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x182860: 910043FD  add      x29, sp, #0x10
//   0x182864: 4EA01C08  mov      v8.16b, v0.16b
static inline uint64_t fde_func_3955_0x182858(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x182858ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f2168ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #3956 | PC: 0x1828e8 | FDE: 0x1f2188 | Size: 256 bytes
// Khung tháo gỡ #3956 | Địa chỉ PC: 0x1828e8 | Địa chỉ FDE: 0x1f2188 | Kích thước: 256 bytes
//   0x1828e8: FC1C0FEA  str      d10, [sp, #-0x40]!
//   0x1828ec: 6D0123E9  stp      d9, d8, [sp, #0x10]
//   0x1828f0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1828f4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3956_0x1828e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1828e8ULL ^ (static_cast<uint64_t>(0xfc1c0feaULL) << 13);
    acc = (acc + a1 + 0x6d0123e9ULL) ^ 0x1f2188ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3957 | PC: 0x182a34 | FDE: 0x1f21b0 | Size: 216 bytes
// Khung tháo gỡ #3957 | Địa chỉ PC: 0x182a34 | Địa chỉ FDE: 0x1f21b0 | Kích thước: 216 bytes
//   0x182a34: 1E602020  fcmp     d1, d0
//   0x182a38: 540002A6  b.vs     #0x182a8c
//   0x182a3c: D2EFFE08  mov      x8, #0x7ff0000000000000
//   0x182a40: 1E60C002  fabs     d2, d0
static inline uint64_t fde_func_3957_0x182a34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x182a34ULL ^ (static_cast<uint64_t>(0x1e602020ULL) << 13);
    acc = (acc + a1 + 0x540002a6ULL) ^ 0x1f21b0ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #3958 | PC: 0x182b0c | FDE: 0x1f21c8 | Size: 256 bytes
// Khung tháo gỡ #3958 | Địa chỉ PC: 0x182b0c | Địa chỉ FDE: 0x1f21c8 | Kích thước: 256 bytes
//   0x182b0c: FC1D0FE8  str      d8, [sp, #-0x30]!
//   0x182b10: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x182b14: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x182b18: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3958_0x182b0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x182b0cULL ^ (static_cast<uint64_t>(0xfc1d0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f21c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3959 | PC: 0x182ce4 | FDE: 0x1f21e8 | Size: 256 bytes
// Khung tháo gỡ #3959 | Địa chỉ PC: 0x182ce4 | Địa chỉ FDE: 0x1f21e8 | Kích thước: 256 bytes
//   0x182ce4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x182ce8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x182cec: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x182cf0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3959_0x182ce4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x182ce4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f21e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3960 | PC: 0x182dec | FDE: 0x1f2210 | Size: 256 bytes
// Khung tháo gỡ #3960 | Địa chỉ PC: 0x182dec | Địa chỉ FDE: 0x1f2210 | Kích thước: 256 bytes
//   0x182dec: D10143FF  sub      sp, sp, #0x50
//   0x182df0: 6D0123E9  stp      d9, d8, [sp, #0x10]
//   0x182df4: F90013F5  str      x21, [sp, #0x20]
//   0x182df8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_3960_0x182dec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x182decULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0x6d0123e9ULL) ^ 0x1f2210ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3961 | PC: 0x182f1c | FDE: 0x1f2238 | Size: 152 bytes
// Khung tháo gỡ #3961 | Địa chỉ PC: 0x182f1c | Địa chỉ FDE: 0x1f2238 | Kích thước: 152 bytes
//   0x182f1c: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x182f20: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x182f24: 910043FD  add      x29, sp, #0x10
//   0x182f28: D2EFFE08  mov      x8, #0x7ff0000000000000
static inline uint64_t fde_func_3961_0x182f1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x182f1cULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f2238ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #3962 | PC: 0x182fb4 | FDE: 0x1f2258 | Size: 152 bytes
// Khung tháo gỡ #3962 | Địa chỉ PC: 0x182fb4 | Địa chỉ FDE: 0x1f2258 | Kích thước: 152 bytes
//   0x182fb4: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x182fb8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x182fbc: 910043FD  add      x29, sp, #0x10
//   0x182fc0: D2EFFE08  mov      x8, #0x7ff0000000000000
static inline uint64_t fde_func_3962_0x182fb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x182fb4ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f2258ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #3963 | PC: 0x18304c | FDE: 0x1f2278 | Size: 152 bytes
// Khung tháo gỡ #3963 | Địa chỉ PC: 0x18304c | Địa chỉ FDE: 0x1f2278 | Kích thước: 152 bytes
//   0x18304c: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x183050: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x183054: 910043FD  add      x29, sp, #0x10
//   0x183058: D2EFFE08  mov      x8, #0x7ff0000000000000
static inline uint64_t fde_func_3963_0x18304c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18304cULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f2278ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #3964 | PC: 0x1830e4 | FDE: 0x1f2298 | Size: 256 bytes
// Khung tháo gỡ #3964 | Địa chỉ PC: 0x1830e4 | Địa chỉ FDE: 0x1f2298 | Kích thước: 256 bytes
//   0x1830e4: D10103FF  sub      sp, sp, #0x40
//   0x1830e8: FD000BEA  str      d10, [sp, #0x10]
//   0x1830ec: 6D0223E9  stp      d9, d8, [sp, #0x20]
//   0x1830f0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3964_0x1830e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1830e4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xfd000beaULL) ^ 0x1f2298ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3965 | PC: 0x1831f4 | FDE: 0x1f22c0 | Size: 216 bytes
// Khung tháo gỡ #3965 | Địa chỉ PC: 0x1831f4 | Địa chỉ FDE: 0x1f22c0 | Kích thước: 216 bytes
//   0x1831f4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1831f8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1831fc: 910043FD  add      x29, sp, #0x10
//   0x183200: F0000208  adrp     x8, #0x1c6000
static inline uint64_t fde_func_3965_0x1831f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1831f4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f22c0ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #3966 | PC: 0x1832cc | FDE: 0x1f22e0 | Size: 48 bytes [PyOS_BeforeFork]
// Khung tháo gỡ #3966 | Địa chỉ PC: 0x1832cc | Địa chỉ FDE: 0x1f22e0 | Kích thước: 48 bytes
//   0x1832cc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1832d0: 910003FD  mov      x29, sp
//   0x1832d4: 900003E8  adrp     x8, #0x1ff000
//   0x1832d8: F943B908  ldr      x8, [x8, #0x770]
static inline uint64_t fde_func_3966_0x1832cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1832ccULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f22e0ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #3967 | PC: 0x1832fc | FDE: 0x1f2300 | Size: 256 bytes
// Khung tháo gỡ #3967 | Địa chỉ PC: 0x1832fc | Địa chỉ FDE: 0x1f2300 | Kích thước: 256 bytes
//   0x1832fc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x183300: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x183304: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x183308: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3967_0x1832fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1832fcULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f2300ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3968 | PC: 0x183438 | FDE: 0x1f2328 | Size: 76 bytes [PyOS_AfterFork_Parent]
// Khung tháo gỡ #3968 | Địa chỉ PC: 0x183438 | Địa chỉ FDE: 0x1f2328 | Kích thước: 76 bytes
//   0x183438: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x18343c: 910003FD  mov      x29, sp
//   0x183440: 97FB59A4  bl       #0x59ad0
//   0x183444: 7100001F  cmp      w0, #0
static inline uint64_t fde_func_3968_0x183438(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x183438ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f2328ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #3969 | PC: 0x183484 | FDE: 0x1f2348 | Size: 256 bytes [PyOS_AfterFork_Child]
// Khung tháo gỡ #3969 | Địa chỉ PC: 0x183484 | Địa chỉ FDE: 0x1f2348 | Kích thước: 256 bytes
//   0x183484: D10243FF  sub      sp, sp, #0x90
//   0x183488: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x18348c: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x183490: 910203FD  add      x29, sp, #0x80
static inline uint64_t fde_func_3969_0x183484(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x183484ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9074ff4ULL) ^ 0x1f2348ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3970 | PC: 0x1835c4 | FDE: 0x1f2368 | Size: 4 bytes [PyOS_AfterFork]
// Khung tháo gỡ #3970 | Địa chỉ PC: 0x1835c4 | Địa chỉ FDE: 0x1f2368 | Kích thước: 4 bytes
//   0x1835c4: 17FB60B7  b        #0x5b8a0
static inline uint64_t fde_func_3970_0x1835c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1835c4ULL ^ (static_cast<uint64_t>(0x17fb60b7ULL) << 13);
    acc = (acc + a1 + 0x3100041fULL) ^ 0x1f2368ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #3971 | PC: 0x1835c8 | FDE: 0x1f2380 | Size: 24 bytes [_PyLong_FromUid]
// Khung tháo gỡ #3971 | Địa chỉ PC: 0x1835c8 | Địa chỉ FDE: 0x1f2380 | Kích thước: 24 bytes
//   0x1835c8: 3100041F  cmn      w0, #1
//   0x1835cc: 54000060  b.eq     #0x1835d8
//   0x1835d0: 2A0003E0  mov      w0, w0
//   0x1835d4: 17FB62CF  b        #0x5c110
static inline uint64_t fde_func_3971_0x1835c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1835c8ULL ^ (static_cast<uint64_t>(0x3100041fULL) << 13);
    acc = (acc + a1 + 0x54000060ULL) ^ 0x1f2380ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #3972 | PC: 0x1835e0 | FDE: 0x1f2398 | Size: 24 bytes [_PyLong_FromGid]
// Khung tháo gỡ #3972 | Địa chỉ PC: 0x1835e0 | Địa chỉ FDE: 0x1f2398 | Kích thước: 24 bytes
//   0x1835e0: 3100041F  cmn      w0, #1
//   0x1835e4: 54000060  b.eq     #0x1835f0
//   0x1835e8: 2A0003E0  mov      w0, w0
//   0x1835ec: 17FB62C9  b        #0x5c110
static inline uint64_t fde_func_3972_0x1835e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1835e0ULL ^ (static_cast<uint64_t>(0x3100041fULL) << 13);
    acc = (acc + a1 + 0x54000060ULL) ^ 0x1f2398ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #3973 | PC: 0x1835f8 | FDE: 0x1f23b0 | Size: 256 bytes [_Py_Uid_Converter]
// Khung tháo gỡ #3973 | Địa chỉ PC: 0x1835f8 | Địa chỉ FDE: 0x1f23b0 | Kích thước: 256 bytes
//   0x1835f8: D10143FF  sub      sp, sp, #0x50
//   0x1835fc: F9000BF7  str      x23, [sp, #0x10]
//   0x183600: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x183604: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_3973_0x1835f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1835f8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x1f23b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3974 | PC: 0x183764 | FDE: 0x1f23d8 | Size: 256 bytes [_Py_Gid_Converter]
// Khung tháo gỡ #3974 | Địa chỉ PC: 0x183764 | Địa chỉ FDE: 0x1f23d8 | Kích thước: 256 bytes
//   0x183764: D10143FF  sub      sp, sp, #0x50
//   0x183768: F9000BF7  str      x23, [sp, #0x10]
//   0x18376c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x183770: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_3974_0x183764(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x183764ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x1f23d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3975 | PC: 0x1838d0 | FDE: 0x1f2400 | Size: 256 bytes [_Py_Sigset_Converter]
// Khung tháo gỡ #3975 | Địa chỉ PC: 0x1838d0 | Địa chỉ FDE: 0x1f2400 | Kích thước: 256 bytes
//   0x1838d0: D10283FF  sub      sp, sp, #0xa0
//   0x1838d4: F9002BF9  str      x25, [sp, #0x50]
//   0x1838d8: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x1838dc: A90757F6  stp      x22, x21, [sp, #0x70]
static inline uint64_t fde_func_3975_0x1838d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1838d0ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf9ULL) ^ 0x1f2400ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3976 | PC: 0x183aa4 | FDE: 0x1f2428 | Size: 256 bytes [PyOS_FSPath]
// Khung tháo gỡ #3976 | Địa chỉ PC: 0x183aa4 | Địa chỉ FDE: 0x1f2428 | Kích thước: 256 bytes
//   0x183aa4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x183aa8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x183aac: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x183ab0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3976_0x183aa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x183aa4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f2428ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3977 | PC: 0x183c34 | FDE: 0x1f2448 | Size: 12 bytes [PyInit_posix]
// Khung tháo gỡ #3977 | Địa chỉ PC: 0x183c34 | Địa chỉ FDE: 0x1f2448 | Kích thước: 12 bytes
//   0x183c34: B00004E0  adrp     x0, #0x220000
//   0x183c38: 913BE000  add      x0, x0, #0xef8
//   0x183c3c: 17FB5379  b        #0x58a20
static inline uint64_t fde_func_3977_0x183c34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x183c34ULL ^ (static_cast<uint64_t>(0xb00004e0ULL) << 13);
    acc = (acc + a1 + 0x913be000ULL) ^ 0x1f2448ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #3978 | PC: 0x183c40 | FDE: 0x1f2460 | Size: 256 bytes
// Khung tháo gỡ #3978 | Địa chỉ PC: 0x183c40 | Địa chỉ FDE: 0x1f2460 | Kích thước: 256 bytes
//   0x183c40: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x183c44: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x183c48: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x183c4c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_3978_0x183c40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x183c40ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f2460ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3979 | PC: 0x183d60 | FDE: 0x1f2480 | Size: 256 bytes
// Khung tháo gỡ #3979 | Địa chỉ PC: 0x183d60 | Địa chỉ FDE: 0x1f2480 | Kích thước: 256 bytes
//   0x183d60: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x183d64: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x183d68: 910043FD  add      x29, sp, #0x10
//   0x183d6c: F9401013  ldr      x19, [x0, #0x20]
static inline uint64_t fde_func_3979_0x183d60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x183d60ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f2480ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3980 | PC: 0x183f70 | FDE: 0x1f24a0 | Size: 4 bytes
// Khung tháo gỡ #3980 | Địa chỉ PC: 0x183f70 | Địa chỉ FDE: 0x1f24a0 | Kích thước: 4 bytes
//   0x183f70: 17FFFF7C  b        #0x183d60
static inline uint64_t fde_func_3980_0x183f70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x183f70ULL ^ (static_cast<uint64_t>(0x17ffff7cULL) << 13);
    acc = (acc + a1 + 0xd10303ffULL) ^ 0x1f24a0ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #3981 | PC: 0x183f74 | FDE: 0x1f24b8 | Size: 256 bytes
// Khung tháo gỡ #3981 | Địa chỉ PC: 0x183f74 | Địa chỉ FDE: 0x1f24b8 | Kích thước: 256 bytes
//   0x183f74: D10303FF  sub      sp, sp, #0xc0
//   0x183f78: F90043F7  str      x23, [sp, #0x80]
//   0x183f7c: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x183f80: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_3981_0x183f74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x183f74ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf90043f7ULL) ^ 0x1f24b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3982 | PC: 0x184170 | FDE: 0x1f24e0 | Size: 8 bytes
// Khung tháo gỡ #3982 | Địa chỉ PC: 0x184170 | Địa chỉ FDE: 0x1f24e0 | Kích thước: 8 bytes
//   0x184170: 2A1F03E0  mov      w0, wzr
//   0x184174: 14000B57  b        #0x186ed0
static inline uint64_t fde_func_3982_0x184170(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x184170ULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0x14000b57ULL) ^ 0x1f24e0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3983 | PC: 0x184178 | FDE: 0x1f24f8 | Size: 8 bytes
// Khung tháo gỡ #3983 | Địa chỉ PC: 0x184178 | Địa chỉ FDE: 0x1f24f8 | Kích thước: 8 bytes
//   0x184178: 52800020  mov      w0, #1
//   0x18417c: 14000B55  b        #0x186ed0
static inline uint64_t fde_func_3983_0x184178(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x184178ULL ^ (static_cast<uint64_t>(0x52800020ULL) << 13);
    acc = (acc + a1 + 0x14000b55ULL) ^ 0x1f24f8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #3984 | PC: 0x184180 | FDE: 0x1f2510 | Size: 256 bytes
// Khung tháo gỡ #3984 | Địa chỉ PC: 0x184180 | Địa chỉ FDE: 0x1f2510 | Kích thước: 256 bytes
//   0x184180: D10303FF  sub      sp, sp, #0xc0
//   0x184184: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x184188: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x18418c: A90957F6  stp      x22, x21, [sp, #0x90]
static inline uint64_t fde_func_3984_0x184180(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x184180ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa90767faULL) ^ 0x1f2510ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3985 | PC: 0x184518 | FDE: 0x1f2540 | Size: 256 bytes
// Khung tháo gỡ #3985 | Địa chỉ PC: 0x184518 | Địa chỉ FDE: 0x1f2540 | Kích thước: 256 bytes
//   0x184518: D10283FF  sub      sp, sp, #0xa0
//   0x18451c: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x184520: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x184524: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_3985_0x184518(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x184518ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa90757f6ULL) ^ 0x1f2540ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3986 | PC: 0x184788 | FDE: 0x1f2568 | Size: 136 bytes
// Khung tháo gỡ #3986 | Địa chỉ PC: 0x184788 | Địa chỉ FDE: 0x1f2568 | Kích thước: 136 bytes
//   0x184788: D10103FF  sub      sp, sp, #0x40
//   0x18478c: F90013F3  str      x19, [sp, #0x20]
//   0x184790: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x184794: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_3986_0x184788(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x184788ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x1f2568ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #3987 | PC: 0x184810 | FDE: 0x1f2588 | Size: 256 bytes
// Khung tháo gỡ #3987 | Địa chỉ PC: 0x184810 | Địa chỉ FDE: 0x1f2588 | Kích thước: 256 bytes
//   0x184810: D10143FF  sub      sp, sp, #0x50
//   0x184814: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x184818: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x18481c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_3987_0x184810(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x184810ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1f2588ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3988 | PC: 0x18498c | FDE: 0x1f25b0 | Size: 256 bytes
// Khung tháo gỡ #3988 | Địa chỉ PC: 0x18498c | Địa chỉ FDE: 0x1f25b0 | Kích thước: 256 bytes
//   0x18498c: D102C3FF  sub      sp, sp, #0xb0
//   0x184990: F9003BF7  str      x23, [sp, #0x70]
//   0x184994: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x184998: A9094FF4  stp      x20, x19, [sp, #0x90]
static inline uint64_t fde_func_3988_0x18498c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18498cULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf7ULL) ^ 0x1f25b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3989 | PC: 0x184b68 | FDE: 0x1f25d8 | Size: 256 bytes
// Khung tháo gỡ #3989 | Địa chỉ PC: 0x184b68 | Địa chỉ FDE: 0x1f25d8 | Kích thước: 256 bytes
//   0x184b68: D10303FF  sub      sp, sp, #0xc0
//   0x184b6c: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x184b70: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x184b74: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_3989_0x184b68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x184b68ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9085ff8ULL) ^ 0x1f25d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3990 | PC: 0x184e7c | FDE: 0x1f2600 | Size: 256 bytes
// Khung tháo gỡ #3990 | Địa chỉ PC: 0x184e7c | Địa chỉ FDE: 0x1f2600 | Kích thước: 256 bytes
//   0x184e7c: D10303FF  sub      sp, sp, #0xc0
//   0x184e80: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x184e84: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x184e88: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_3990_0x184e7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x184e7cULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9085ff8ULL) ^ 0x1f2600ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3991 | PC: 0x1851c8 | FDE: 0x1f2628 | Size: 256 bytes
// Khung tháo gỡ #3991 | Địa chỉ PC: 0x1851c8 | Địa chỉ FDE: 0x1f2628 | Kích thước: 256 bytes
//   0x1851c8: D10283FF  sub      sp, sp, #0xa0
//   0x1851cc: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x1851d0: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x1851d4: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_3991_0x1851c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1851c8ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa90757f6ULL) ^ 0x1f2628ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3992 | PC: 0x185414 | FDE: 0x1f2650 | Size: 256 bytes
// Khung tháo gỡ #3992 | Địa chỉ PC: 0x185414 | Địa chỉ FDE: 0x1f2650 | Kích thước: 256 bytes
//   0x185414: D10303FF  sub      sp, sp, #0xc0
//   0x185418: F90043F7  str      x23, [sp, #0x80]
//   0x18541c: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x185420: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_3992_0x185414(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x185414ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf90043f7ULL) ^ 0x1f2650ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3993 | PC: 0x1856ac | FDE: 0x1f2678 | Size: 256 bytes
// Khung tháo gỡ #3993 | Địa chỉ PC: 0x1856ac | Địa chỉ FDE: 0x1f2678 | Kích thước: 256 bytes
//   0x1856ac: D10283FF  sub      sp, sp, #0xa0
//   0x1856b0: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x1856b4: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x1856b8: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_3993_0x1856ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1856acULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa90757f6ULL) ^ 0x1f2678ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3994 | PC: 0x1858f8 | FDE: 0x1f26a0 | Size: 256 bytes
// Khung tháo gỡ #3994 | Địa chỉ PC: 0x1858f8 | Địa chỉ FDE: 0x1f26a0 | Kích thước: 256 bytes
//   0x1858f8: D10443FF  sub      sp, sp, #0x110
//   0x1858fc: A90D5FFC  stp      x28, x23, [sp, #0xd0]
//   0x185900: A90E57F6  stp      x22, x21, [sp, #0xe0]
//   0x185904: A90F4FF4  stp      x20, x19, [sp, #0xf0]
static inline uint64_t fde_func_3994_0x1858f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1858f8ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90d5ffcULL) ^ 0x1f26a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3995 | PC: 0x185bac | FDE: 0x1f26c8 | Size: 256 bytes
// Khung tháo gỡ #3995 | Địa chỉ PC: 0x185bac | Địa chỉ FDE: 0x1f26c8 | Kích thước: 256 bytes
//   0x185bac: D10443FF  sub      sp, sp, #0x110
//   0x185bb0: A90D5FFC  stp      x28, x23, [sp, #0xd0]
//   0x185bb4: A90E57F6  stp      x22, x21, [sp, #0xe0]
//   0x185bb8: A90F4FF4  stp      x20, x19, [sp, #0xf0]
static inline uint64_t fde_func_3995_0x185bac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x185bacULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90d5ffcULL) ^ 0x1f26c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3996 | PC: 0x185e60 | FDE: 0x1f26f0 | Size: 256 bytes
// Khung tháo gỡ #3996 | Địa chỉ PC: 0x185e60 | Địa chỉ FDE: 0x1f26f0 | Kích thước: 256 bytes
//   0x185e60: D10583FF  sub      sp, sp, #0x160
//   0x185e64: A9106FFC  stp      x28, x27, [sp, #0x100]
//   0x185e68: A91167FA  stp      x26, x25, [sp, #0x110]
//   0x185e6c: A9125FF8  stp      x24, x23, [sp, #0x120]
static inline uint64_t fde_func_3996_0x185e60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x185e60ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xa9106ffcULL) ^ 0x1f26f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3997 | PC: 0x18638c | FDE: 0x1f2720 | Size: 208 bytes
// Khung tháo gỡ #3997 | Địa chỉ PC: 0x18638c | Địa chỉ FDE: 0x1f2720 | Kích thước: 208 bytes
//   0x18638c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x186390: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x186394: 910043FD  add      x29, sp, #0x10
//   0x186398: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_3997_0x18638c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18638cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f2720ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #3998 | PC: 0x18645c | FDE: 0x1f2740 | Size: 256 bytes
// Khung tháo gỡ #3998 | Địa chỉ PC: 0x18645c | Địa chỉ FDE: 0x1f2740 | Kích thước: 256 bytes
//   0x18645c: D101C3FF  sub      sp, sp, #0x70
//   0x186460: F9000BFB  str      x27, [sp, #0x10]
//   0x186464: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x186468: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_3998_0x18645c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18645cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfbULL) ^ 0x1f2740ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #3999 | PC: 0x18698c | FDE: 0x1f2770 | Size: 224 bytes
// Khung tháo gỡ #3999 | Địa chỉ PC: 0x18698c | Địa chỉ FDE: 0x1f2770 | Kích thước: 224 bytes
//   0x18698c: D10103FF  sub      sp, sp, #0x40
//   0x186990: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x186994: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x186998: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_3999_0x18698c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18698cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f2770ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #4000 | PC: 0x186a6c | FDE: 0x1f2798 | Size: 256 bytes
// Khung tháo gỡ #4000 | Địa chỉ PC: 0x186a6c | Địa chỉ FDE: 0x1f2798 | Kích thước: 256 bytes
//   0x186a6c: D10343FF  sub      sp, sp, #0xd0
//   0x186a70: A9095FF8  stp      x24, x23, [sp, #0x90]
//   0x186a74: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x186a78: A90B4FF4  stp      x20, x19, [sp, #0xb0]
static inline uint64_t fde_func_4000_0x186a6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x186a6cULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9095ff8ULL) ^ 0x1f2798ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4001 | PC: 0x186c04 | FDE: 0x1f27c0 | Size: 256 bytes
// Khung tháo gỡ #4001 | Địa chỉ PC: 0x186c04 | Địa chỉ FDE: 0x1f27c0 | Kích thước: 256 bytes
//   0x186c04: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x186c08: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x186c0c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x186c10: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_4001_0x186c04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x186c04ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f27c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4002 | PC: 0x186d5c | FDE: 0x1f27e8 | Size: 256 bytes
// Khung tháo gỡ #4002 | Địa chỉ PC: 0x186d5c | Địa chỉ FDE: 0x1f27e8 | Kích thước: 256 bytes
//   0x186d5c: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x186d60: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x186d64: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x186d68: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_4002_0x186d5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x186d5cULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1f27e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4003 | PC: 0x186ed0 | FDE: 0x1f2818 | Size: 256 bytes
// Khung tháo gỡ #4003 | Địa chỉ PC: 0x186ed0 | Địa chỉ FDE: 0x1f2818 | Kích thước: 256 bytes
//   0x186ed0: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x186ed4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x186ed8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x186edc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_4003_0x186ed0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x186ed0ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f2818ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4004 | PC: 0x186fdc | FDE: 0x1f2840 | Size: 256 bytes
// Khung tháo gỡ #4004 | Địa chỉ PC: 0x186fdc | Địa chỉ FDE: 0x1f2840 | Kích thước: 256 bytes
//   0x186fdc: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x186fe0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x186fe4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x186fe8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_4004_0x186fdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x186fdcULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1f2840ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4005 | PC: 0x187134 | FDE: 0x1f2868 | Size: 256 bytes
// Khung tháo gỡ #4005 | Địa chỉ PC: 0x187134 | Địa chỉ FDE: 0x1f2868 | Kích thước: 256 bytes
//   0x187134: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x187138: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x18713c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x187140: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_4005_0x187134(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x187134ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f2868ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4006 | PC: 0x187240 | FDE: 0x1f2890 | Size: 256 bytes
// Khung tháo gỡ #4006 | Địa chỉ PC: 0x187240 | Địa chỉ FDE: 0x1f2890 | Kích thước: 256 bytes
//   0x187240: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x187244: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x187248: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x18724c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_4006_0x187240(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x187240ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f2890ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4007 | PC: 0x188040 | FDE: 0x1f28b8 | Size: 236 bytes
// Khung tháo gỡ #4007 | Địa chỉ PC: 0x188040 | Địa chỉ FDE: 0x1f28b8 | Kích thước: 236 bytes
//   0x188040: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x188044: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x188048: 910043FD  add      x29, sp, #0x10
//   0x18804c: D00004E8  adrp     x8, #0x226000
static inline uint64_t fde_func_4007_0x188040(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x188040ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f28b8ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #4008 | PC: 0x18812c | FDE: 0x1f28d8 | Size: 172 bytes
// Khung tháo gỡ #4008 | Địa chỉ PC: 0x18812c | Địa chỉ FDE: 0x1f28d8 | Kích thước: 172 bytes
//   0x18812c: D10143FF  sub      sp, sp, #0x50
//   0x188130: F90013F5  str      x21, [sp, #0x20]
//   0x188134: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x188138: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_4008_0x18812c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18812cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1f28d8ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #4009 | PC: 0x1881d8 | FDE: 0x1f28f8 | Size: 12 bytes
// Khung tháo gỡ #4009 | Địa chỉ PC: 0x1881d8 | Địa chỉ FDE: 0x1f28f8 | Kích thước: 12 bytes
//   0x1881d8: F9400000  ldr      x0, [x0]
//   0x1881dc: F9400021  ldr      x1, [x1]
//   0x1881e0: 17FB4564  b        #0x59770
static inline uint64_t fde_func_4009_0x1881d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1881d8ULL ^ (static_cast<uint64_t>(0xf9400000ULL) << 13);
    acc = (acc + a1 + 0xf9400021ULL) ^ 0x1f28f8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #4010 | PC: 0x1881e4 | FDE: 0x1f2910 | Size: 96 bytes
// Khung tháo gỡ #4010 | Địa chỉ PC: 0x1881e4 | Địa chỉ FDE: 0x1f2910 | Kích thước: 96 bytes
//   0x1881e4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1881e8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1881ec: 910043FD  add      x29, sp, #0x10
//   0x1881f0: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_4010_0x1881e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1881e4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f2910ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #4011 | PC: 0x188244 | FDE: 0x1f2930 | Size: 256 bytes
// Khung tháo gỡ #4011 | Địa chỉ PC: 0x188244 | Địa chỉ FDE: 0x1f2930 | Kích thước: 256 bytes
//   0x188244: D10143FF  sub      sp, sp, #0x50
//   0x188248: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x18824c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x188250: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_4011_0x188244(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x188244ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1f2930ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4012 | PC: 0x18835c | FDE: 0x1f2958 | Size: 256 bytes
// Khung tháo gỡ #4012 | Địa chỉ PC: 0x18835c | Địa chỉ FDE: 0x1f2958 | Kích thước: 256 bytes
//   0x18835c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x188360: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x188364: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x188368: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_4012_0x18835c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18835cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1f2958ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4013 | PC: 0x188614 | FDE: 0x1f2988 | Size: 16 bytes
// Khung tháo gỡ #4013 | Địa chỉ PC: 0x188614 | Địa chỉ FDE: 0x1f2988 | Kích thước: 16 bytes
//   0x188614: F9400008  ldr      x8, [x0]
//   0x188618: 91000508  add      x8, x8, #1
//   0x18861c: F9000008  str      x8, [x0]
//   0x188620: D65F03C0  ret      
static inline uint64_t fde_func_4013_0x188614(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x188614ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0x91000508ULL) ^ 0x1f2988ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #4014 | PC: 0x188624 | FDE: 0x1f29a0 | Size: 104 bytes
// Khung tháo gỡ #4014 | Địa chỉ PC: 0x188624 | Địa chỉ FDE: 0x1f29a0 | Kích thước: 104 bytes
//   0x188624: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x188628: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18862c: 910043FD  add      x29, sp, #0x10
//   0x188630: F9402C13  ldr      x19, [x0, #0x58]
static inline uint64_t fde_func_4014_0x188624(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x188624ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f29a0ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #4015 | PC: 0x18868c | FDE: 0x1f29c0 | Size: 104 bytes
// Khung tháo gỡ #4015 | Địa chỉ PC: 0x18868c | Địa chỉ FDE: 0x1f29c0 | Kích thước: 104 bytes
//   0x18868c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x188690: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x188694: 910043FD  add      x29, sp, #0x10
//   0x188698: F9402C13  ldr      x19, [x0, #0x58]
static inline uint64_t fde_func_4015_0x18868c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18868cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f29c0ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #4016 | PC: 0x1886f4 | FDE: 0x1f29e0 | Size: 232 bytes
// Khung tháo gỡ #4016 | Địa chỉ PC: 0x1886f4 | Địa chỉ FDE: 0x1f29e0 | Kích thước: 232 bytes
//   0x1886f4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1886f8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1886fc: 910043FD  add      x29, sp, #0x10
//   0x188700: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_4016_0x1886f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1886f4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f29e0ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #4017 | PC: 0x1887dc | FDE: 0x1f2a00 | Size: 16 bytes
// Khung tháo gỡ #4017 | Địa chỉ PC: 0x1887dc | Địa chỉ FDE: 0x1f2a00 | Kích thước: 16 bytes
//   0x1887dc: F9400801  ldr      x1, [x0, #0x10]
//   0x1887e0: F00001E0  adrp     x0, #0x1c7000
//   0x1887e4: 912DE800  add      x0, x0, #0xb7a
//   0x1887e8: 17FB3EB2  b        #0x582b0
static inline uint64_t fde_func_4017_0x1887dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1887dcULL ^ (static_cast<uint64_t>(0xf9400801ULL) << 13);
    acc = (acc + a1 + 0xf00001e0ULL) ^ 0x1f2a00ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #4018 | PC: 0x1887ec | FDE: 0x1f2a18 | Size: 184 bytes
// Khung tháo gỡ #4018 | Địa chỉ PC: 0x1887ec | Địa chỉ FDE: 0x1f2a18 | Kích thước: 184 bytes
//   0x1887ec: D10103FF  sub      sp, sp, #0x40
//   0x1887f0: F9000BF5  str      x21, [sp, #0x10]
//   0x1887f4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1887f8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_4018_0x1887ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1887ecULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1f2a18ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #4019 | PC: 0x1888a4 | FDE: 0x1f2a38 | Size: 184 bytes
// Khung tháo gỡ #4019 | Địa chỉ PC: 0x1888a4 | Địa chỉ FDE: 0x1f2a38 | Kích thước: 184 bytes
//   0x1888a4: D10103FF  sub      sp, sp, #0x40
//   0x1888a8: F9000BF5  str      x21, [sp, #0x10]
//   0x1888ac: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1888b0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_4019_0x1888a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1888a4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1f2a38ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #4020 | PC: 0x18895c | FDE: 0x1f2a58 | Size: 148 bytes
// Khung tháo gỡ #4020 | Địa chỉ PC: 0x18895c | Địa chỉ FDE: 0x1f2a58 | Kích thước: 148 bytes
//   0x18895c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x188960: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x188964: 910043FD  add      x29, sp, #0x10
//   0x188968: AA0303E8  mov      x8, x3
static inline uint64_t fde_func_4020_0x18895c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18895cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f2a58ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #4021 | PC: 0x1889f0 | FDE: 0x1f2a78 | Size: 152 bytes
// Khung tháo gỡ #4021 | Địa chỉ PC: 0x1889f0 | Địa chỉ FDE: 0x1f2a78 | Kích thước: 152 bytes
//   0x1889f0: D10103FF  sub      sp, sp, #0x40
//   0x1889f4: F9000BF5  str      x21, [sp, #0x10]
//   0x1889f8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1889fc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_4021_0x1889f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1889f0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1f2a78ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #4022 | PC: 0x188a88 | FDE: 0x1f2a98 | Size: 8 bytes
// Khung tháo gỡ #4022 | Địa chỉ PC: 0x188a88 | Địa chỉ FDE: 0x1f2a98 | Kích thước: 8 bytes
//   0x188a88: F9401C00  ldr      x0, [x0, #0x38]
//   0x188a8c: 17FB40B1  b        #0x58d50
static inline uint64_t fde_func_4022_0x188a88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x188a88ULL ^ (static_cast<uint64_t>(0xf9401c00ULL) << 13);
    acc = (acc + a1 + 0x17fb40b1ULL) ^ 0x1f2a98ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #4023 | PC: 0x188a90 | FDE: 0x1f2ab0 | Size: 20 bytes
// Khung tháo gỡ #4023 | Địa chỉ PC: 0x188a90 | Địa chỉ FDE: 0x1f2ab0 | Kích thước: 20 bytes
//   0x188a90: F9400C00  ldr      x0, [x0, #0x18]
//   0x188a94: F9400008  ldr      x8, [x0]
//   0x188a98: 91000508  add      x8, x8, #1
//   0x188a9c: F9000008  str      x8, [x0]
static inline uint64_t fde_func_4023_0x188a90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x188a90ULL ^ (static_cast<uint64_t>(0xf9400c00ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x1f2ab0ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #4024 | PC: 0x188aa4 | FDE: 0x1f2ac8 | Size: 256 bytes
// Khung tháo gỡ #4024 | Địa chỉ PC: 0x188aa4 | Địa chỉ FDE: 0x1f2ac8 | Kích thước: 256 bytes
//   0x188aa4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x188aa8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x188aac: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x188ab0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_4024_0x188aa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x188aa4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f2ac8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4025 | PC: 0x188c00 | FDE: 0x1f2af0 | Size: 252 bytes
// Khung tháo gỡ #4025 | Địa chỉ PC: 0x188c00 | Địa chỉ FDE: 0x1f2af0 | Kích thước: 252 bytes
//   0x188c00: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x188c04: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x188c08: 910043FD  add      x29, sp, #0x10
//   0x188c0c: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_4025_0x188c00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x188c00ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f2af0ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #4026 | PC: 0x188cfc | FDE: 0x1f2b10 | Size: 256 bytes
// Khung tháo gỡ #4026 | Địa chỉ PC: 0x188cfc | Địa chỉ FDE: 0x1f2b10 | Kích thước: 256 bytes
//   0x188cfc: D10303FF  sub      sp, sp, #0xc0
//   0x188d00: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x188d04: A90A4FF4  stp      x20, x19, [sp, #0xa0]
//   0x188d08: A90B7BFD  stp      x29, x30, [sp, #0xb0]
static inline uint64_t fde_func_4026_0x188cfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x188cfcULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa90957f6ULL) ^ 0x1f2b10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4027 | PC: 0x188dfc | FDE: 0x1f2b38 | Size: 8 bytes
// Khung tháo gỡ #4027 | Địa chỉ PC: 0x188dfc | Địa chỉ FDE: 0x1f2b38 | Kích thước: 8 bytes
//   0x188dfc: 52800020  mov      w0, #1
//   0x188e00: D65F03C0  ret      
static inline uint64_t fde_func_4027_0x188dfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x188dfcULL ^ (static_cast<uint64_t>(0x52800020ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1f2b38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #4028 | PC: 0x188e04 | FDE: 0x1f2b50 | Size: 8 bytes
// Khung tháo gỡ #4028 | Địa chỉ PC: 0x188e04 | Địa chỉ FDE: 0x1f2b50 | Kích thước: 8 bytes
//   0x188e04: 52800020  mov      w0, #1
//   0x188e08: D65F03C0  ret      
static inline uint64_t fde_func_4028_0x188e04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x188e04ULL ^ (static_cast<uint64_t>(0x52800020ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1f2b50ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #4029 | PC: 0x188e0c | FDE: 0x1f2b68 | Size: 8 bytes
// Khung tháo gỡ #4029 | Địa chỉ PC: 0x188e0c | Địa chỉ FDE: 0x1f2b68 | Kích thước: 8 bytes
//   0x188e0c: 52800020  mov      w0, #1
//   0x188e10: D65F03C0  ret      
static inline uint64_t fde_func_4029_0x188e0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x188e0cULL ^ (static_cast<uint64_t>(0x52800020ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1f2b68ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #4030 | PC: 0x188e14 | FDE: 0x1f2b80 | Size: 8 bytes
// Khung tháo gỡ #4030 | Địa chỉ PC: 0x188e14 | Địa chỉ FDE: 0x1f2b80 | Kích thước: 8 bytes
//   0x188e14: 52800020  mov      w0, #1
//   0x188e18: D65F03C0  ret      
static inline uint64_t fde_func_4030_0x188e14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x188e14ULL ^ (static_cast<uint64_t>(0x52800020ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1f2b80ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #4031 | PC: 0x188e1c | FDE: 0x1f2b98 | Size: 8 bytes
// Khung tháo gỡ #4031 | Địa chỉ PC: 0x188e1c | Địa chỉ FDE: 0x1f2b98 | Kích thước: 8 bytes
//   0x188e1c: 52800020  mov      w0, #1
//   0x188e20: D65F03C0  ret      
static inline uint64_t fde_func_4031_0x188e1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x188e1cULL ^ (static_cast<uint64_t>(0x52800020ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1f2b98ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #4032 | PC: 0x188e24 | FDE: 0x1f2bb0 | Size: 8 bytes
// Khung tháo gỡ #4032 | Địa chỉ PC: 0x188e24 | Địa chỉ FDE: 0x1f2bb0 | Kích thước: 8 bytes
//   0x188e24: 52800020  mov      w0, #1
//   0x188e28: D65F03C0  ret      
static inline uint64_t fde_func_4032_0x188e24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x188e24ULL ^ (static_cast<uint64_t>(0x52800020ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1f2bb0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #4033 | PC: 0x188e2c | FDE: 0x1f2bc8 | Size: 8 bytes
// Khung tháo gỡ #4033 | Địa chỉ PC: 0x188e2c | Địa chỉ FDE: 0x1f2bc8 | Kích thước: 8 bytes
//   0x188e2c: 52800020  mov      w0, #1
//   0x188e30: D65F03C0  ret      
static inline uint64_t fde_func_4033_0x188e2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x188e2cULL ^ (static_cast<uint64_t>(0x52800020ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1f2bc8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #4034 | PC: 0x188e34 | FDE: 0x1f2be0 | Size: 8 bytes
// Khung tháo gỡ #4034 | Địa chỉ PC: 0x188e34 | Địa chỉ FDE: 0x1f2be0 | Kích thước: 8 bytes
//   0x188e34: 52800020  mov      w0, #1
//   0x188e38: D65F03C0  ret      
static inline uint64_t fde_func_4034_0x188e34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x188e34ULL ^ (static_cast<uint64_t>(0x52800020ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1f2be0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #4035 | PC: 0x188e3c | FDE: 0x1f2bf8 | Size: 8 bytes
// Khung tháo gỡ #4035 | Địa chỉ PC: 0x188e3c | Địa chỉ FDE: 0x1f2bf8 | Kích thước: 8 bytes
//   0x188e3c: 52800020  mov      w0, #1
//   0x188e40: D65F03C0  ret      
static inline uint64_t fde_func_4035_0x188e3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x188e3cULL ^ (static_cast<uint64_t>(0x52800020ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1f2bf8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #4036 | PC: 0x188e44 | FDE: 0x1f2c10 | Size: 64 bytes [RotatingTree_Add]
// Khung tháo gỡ #4036 | Địa chỉ PC: 0x188e44 | Địa chỉ FDE: 0x1f2c10 | Kích thước: 64 bytes
//   0x188e44: F9400008  ldr      x8, [x0]
//   0x188e48: B4000188  cbz      x8, #0x188e78
//   0x188e4c: F9400029  ldr      x9, [x1]
//   0x188e50: 5280020A  mov      w10, #0x10
static inline uint64_t fde_func_4036_0x188e44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x188e44ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xb4000188ULL) ^ 0x1f2c10ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #4037 | PC: 0x188e84 | FDE: 0x1f2c28 | Size: 256 bytes [RotatingTree_Get]
// Khung tháo gỡ #4037 | Địa chỉ PC: 0x188e84 | Địa chỉ FDE: 0x1f2c28 | Kích thước: 256 bytes
//   0x188e84: D00004E9  adrp     x9, #0x226000
//   0x188e88: B946792C  ldr      w12, [x9, #0x678]
//   0x188e8c: AA0003E8  mov      x8, x0
//   0x188e90: B00004CA  adrp     x10, #0x221000
static inline uint64_t fde_func_4037_0x188e84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x188e84ULL ^ (static_cast<uint64_t>(0xd00004e9ULL) << 13);
    acc = (acc + a1 + 0xb946792cULL) ^ 0x1f2c28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4038 | PC: 0x188f94 | FDE: 0x1f2c40 | Size: 100 bytes [RotatingTree_Enum]
// Khung tháo gỡ #4038 | Địa chỉ PC: 0x188f94 | Địa chỉ FDE: 0x1f2c40 | Kích thước: 100 bytes
//   0x188f94: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x188f98: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x188f9c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x188fa0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_4038_0x188f94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x188f94ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f2c40ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #4039 | PC: 0x188ff8 | FDE: 0x1f2c68 | Size: 40 bytes [PySignal_SetWakeupFd]
// Khung tháo gỡ #4039 | Địa chỉ PC: 0x188ff8 | Địa chỉ FDE: 0x1f2c68 | Kích thước: 40 bytes
//   0x188ff8: B00004C9  adrp     x9, #0x221000
//   0x188ffc: 913AB129  add      x9, x9, #0xeac
//   0x189000: B9400128  ldr      w8, [x9]
//   0x189004: 7100001F  cmp      w0, #0
static inline uint64_t fde_func_4039_0x188ff8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x188ff8ULL ^ (static_cast<uint64_t>(0xb00004c9ULL) << 13);
    acc = (acc + a1 + 0x913ab129ULL) ^ 0x1f2c68ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #4040 | PC: 0x189020 | FDE: 0x1f2c80 | Size: 12 bytes [PyInit__signal]
// Khung tháo gỡ #4040 | Địa chỉ PC: 0x189020 | Địa chỉ FDE: 0x1f2c80 | Kích thước: 12 bytes
//   0x189020: 900004C0  adrp     x0, #0x221000
//   0x189024: 913AE000  add      x0, x0, #0xeb8
//   0x189028: 17FB3E7E  b        #0x58a20
static inline uint64_t fde_func_4040_0x189020(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x189020ULL ^ (static_cast<uint64_t>(0x900004c0ULL) << 13);
    acc = (acc + a1 + 0x913ae000ULL) ^ 0x1f2c80ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #4041 | PC: 0x18902c | FDE: 0x1f2c98 | Size: 256 bytes [_PySignal_Fini]
// Khung tháo gỡ #4041 | Địa chỉ PC: 0x18902c | Địa chỉ FDE: 0x1f2c98 | Kích thước: 256 bytes
//   0x18902c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x189030: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x189034: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x189038: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_4041_0x18902c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18902cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f2c98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4042 | PC: 0x189134 | FDE: 0x1f2cc0 | Size: 92 bytes [PyErr_CheckSignals]
// Khung tháo gỡ #4042 | Địa chỉ PC: 0x189134 | Địa chỉ FDE: 0x1f2cc0 | Kích thước: 92 bytes
//   0x189134: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x189138: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18913c: 910043FD  add      x29, sp, #0x10
//   0x189140: 97FB41A0  bl       #0x597c0
static inline uint64_t fde_func_4042_0x189134(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x189134ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f2cc0ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #4043 | PC: 0x189190 | FDE: 0x1f2ce0 | Size: 256 bytes [_PyErr_CheckSignalsTstate]
// Khung tháo gỡ #4043 | Địa chỉ PC: 0x189190 | Địa chỉ FDE: 0x1f2ce0 | Kích thước: 256 bytes
//   0x189190: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x189194: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x189198: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x18919c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_4043_0x189190(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x189190ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1f2ce0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4044 | PC: 0x18930c | FDE: 0x1f2d10 | Size: 20 bytes [_PyErr_CheckSignals]
// Khung tháo gỡ #4044 | Địa chỉ PC: 0x18930c | Địa chỉ FDE: 0x1f2d10 | Kích thước: 20 bytes
//   0x18930c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x189310: 910003FD  mov      x29, sp
//   0x189314: 97FB412B  bl       #0x597c0
//   0x189318: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_4044_0x18930c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18930cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f2d10ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #4045 | PC: 0x189320 | FDE: 0x1f2d30 | Size: 256 bytes [PyErr_SetInterruptEx]
// Khung tháo gỡ #4045 | Địa chỉ PC: 0x189320 | Địa chỉ FDE: 0x1f2d30 | Kích thước: 256 bytes
//   0x189320: D10103FF  sub      sp, sp, #0x40
//   0x189324: F9000BF5  str      x21, [sp, #0x10]
//   0x189328: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x18932c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_4045_0x189320(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x189320ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1f2d30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4046 | PC: 0x189440 | FDE: 0x1f2d50 | Size: 8 bytes [PyErr_SetInterrupt]
// Khung tháo gỡ #4046 | Địa chỉ PC: 0x189440 | Địa chỉ FDE: 0x1f2d50 | Kích thước: 8 bytes
//   0x189440: 52800040  mov      w0, #2
//   0x189444: 17FB4F83  b        #0x5d250
static inline uint64_t fde_func_4046_0x189440(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x189440ULL ^ (static_cast<uint64_t>(0x52800040ULL) << 13);
    acc = (acc + a1 + 0x17fb4f83ULL) ^ 0x1f2d50ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #4047 | PC: 0x189448 | FDE: 0x1f2d68 | Size: 36 bytes [_Py_RestoreSignals]
// Khung tháo gỡ #4047 | Địa chỉ PC: 0x189448 | Địa chỉ FDE: 0x1f2d68 | Kích thước: 36 bytes
//   0x189448: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x18944c: 910003FD  mov      x29, sp
//   0x189450: 528001A0  mov      w0, #0xd
//   0x189454: AA1F03E1  mov      x1, xzr
static inline uint64_t fde_func_4047_0x189448(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x189448ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f2d68ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #4048 | PC: 0x18946c | FDE: 0x1f2d88 | Size: 176 bytes [_PySignal_Init]
// Khung tháo gỡ #4048 | Địa chỉ PC: 0x18946c | Địa chỉ FDE: 0x1f2d88 | Kích thước: 176 bytes
//   0x18946c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x189470: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x189474: 910043FD  add      x29, sp, #0x10
//   0x189478: 2A0003F3  mov      w19, w0
static inline uint64_t fde_func_4048_0x18946c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18946cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f2d88ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #4049 | PC: 0x18951c | FDE: 0x1f2da8 | Size: 112 bytes [_PyOS_InterruptOccurred]
// Khung tháo gỡ #4049 | Địa chỉ PC: 0x18951c | Địa chỉ FDE: 0x1f2da8 | Kích thước: 112 bytes
//   0x18951c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x189520: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x189524: 910043FD  add      x29, sp, #0x10
//   0x189528: B40002C0  cbz      x0, #0x189580
static inline uint64_t fde_func_4049_0x18951c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18951cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f2da8ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #4050 | PC: 0x18958c | FDE: 0x1f2dc8 | Size: 116 bytes [PyOS_InterruptOccurred]
// Khung tháo gỡ #4050 | Địa chỉ PC: 0x18958c | Địa chỉ FDE: 0x1f2dc8 | Kích thước: 116 bytes
//   0x18958c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x189590: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x189594: 910043FD  add      x29, sp, #0x10
//   0x189598: 97FB408A  bl       #0x597c0
static inline uint64_t fde_func_4050_0x18958c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18958cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f2dc8ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #4051 | PC: 0x189600 | FDE: 0x1f2de8 | Size: 56 bytes [_PySignal_AfterFork]
// Khung tháo gỡ #4051 | Địa chỉ PC: 0x189600 | Địa chỉ FDE: 0x1f2de8 | Kích thước: 56 bytes
//   0x189600: B00004E9  adrp     x9, #0x226000
//   0x189604: 912A8129  add      x9, x9, #0xaa0
//   0x189608: 88DFFD28  ldar     w8, [x9]
//   0x18960c: 34000148  cbz      w8, #0x189634
static inline uint64_t fde_func_4051_0x189600(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x189600ULL ^ (static_cast<uint64_t>(0xb00004e9ULL) << 13);
    acc = (acc + a1 + 0x912a8129ULL) ^ 0x1f2de8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #4052 | PC: 0x189638 | FDE: 0x1f2e00 | Size: 80 bytes [_PyOS_IsMainThread]
// Khung tháo gỡ #4052 | Địa chỉ PC: 0x189638 | Địa chỉ FDE: 0x1f2e00 | Kích thước: 80 bytes
//   0x189638: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x18963c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x189640: 910043FD  add      x29, sp, #0x10
//   0x189644: D00003B3  adrp     x19, #0x1ff000
static inline uint64_t fde_func_4052_0x189638(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x189638ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f2e00ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #4053 | PC: 0x189688 | FDE: 0x1f2e20 | Size: 56 bytes
// Khung tháo gỡ #4053 | Địa chỉ PC: 0x189688 | Địa chỉ FDE: 0x1f2e20 | Kích thước: 56 bytes
//   0x189688: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x18968c: 910003FD  mov      x29, sp
//   0x189690: F9401008  ldr      x8, [x0, #0x20]
//   0x189694: F9400900  ldr      x0, [x8, #0x10]
static inline uint64_t fde_func_4053_0x189688(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x189688ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f2e20ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #4054 | PC: 0x1896c0 | FDE: 0x1f2e40 | Size: 56 bytes
// Khung tháo gỡ #4054 | Địa chỉ PC: 0x1896c0 | Địa chỉ FDE: 0x1f2e40 | Kích thước: 56 bytes
//   0x1896c0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1896c4: 910003FD  mov      x29, sp
//   0x1896c8: F9401008  ldr      x8, [x0, #0x20]
//   0x1896cc: F9400900  ldr      x0, [x8, #0x10]
static inline uint64_t fde_func_4054_0x1896c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1896c0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f2e40ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #4055 | PC: 0x1896f8 | FDE: 0x1f2e60 | Size: 40 bytes
// Khung tháo gỡ #4055 | Địa chỉ PC: 0x1896f8 | Địa chỉ FDE: 0x1f2e60 | Kích thước: 40 bytes
//   0x1896f8: F9401008  ldr      x8, [x0, #0x20]
//   0x1896fc: F9400900  ldr      x0, [x8, #0x10]
//   0x189700: B40000C0  cbz      x0, #0x189718
//   0x189704: F900091F  str      xzr, [x8, #0x10]
static inline uint64_t fde_func_4055_0x1896f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1896f8ULL ^ (static_cast<uint64_t>(0xf9401008ULL) << 13);
    acc = (acc + a1 + 0xf9400900ULL) ^ 0x1f2e60ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #4056 | PC: 0x189720 | FDE: 0x1f2e78 | Size: 112 bytes
// Khung tháo gỡ #4056 | Địa chỉ PC: 0x189720 | Địa chỉ FDE: 0x1f2e78 | Kích thước: 112 bytes
//   0x189720: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x189724: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x189728: 910043FD  add      x29, sp, #0x10
//   0x18972c: F100085F  cmp      x2, #2
static inline uint64_t fde_func_4056_0x189720(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x189720ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f2e78ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #4057 | PC: 0x189790 | FDE: 0x1f2e98 | Size: 256 bytes
// Khung tháo gỡ #4057 | Địa chỉ PC: 0x189790 | Địa chỉ FDE: 0x1f2e98 | Kích thước: 256 bytes
//   0x189790: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x189794: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x189798: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x18979c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_4057_0x189790(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x189790ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f2e98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4058 | PC: 0x189948 | FDE: 0x1f2ec0 | Size: 132 bytes
// Khung tháo gỡ #4058 | Địa chỉ PC: 0x189948 | Địa chỉ FDE: 0x1f2ec0 | Kích thước: 132 bytes
//   0x189948: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x18994c: 910003FD  mov      x29, sp
//   0x189950: AA0103E0  mov      x0, x1
//   0x189954: 97FB4DDB  bl       #0x5d0c0
static inline uint64_t fde_func_4058_0x189948(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x189948ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f2ec0ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #4059 | PC: 0x1899cc | FDE: 0x1f2ee0 | Size: 232 bytes
// Khung tháo gỡ #4059 | Địa chỉ PC: 0x1899cc | Địa chỉ FDE: 0x1f2ee0 | Kích thước: 232 bytes
//   0x1899cc: D10143FF  sub      sp, sp, #0x50
//   0x1899d0: F9000BF7  str      x23, [sp, #0x10]
//   0x1899d4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x1899d8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_4059_0x1899cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1899ccULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x1f2ee0ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #4060 | PC: 0x189ab4 | FDE: 0x1f2f08 | Size: 256 bytes
// Khung tháo gỡ #4060 | Địa chỉ PC: 0x189ab4 | Địa chỉ FDE: 0x1f2f08 | Kích thước: 256 bytes
//   0x189ab4: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x189ab8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x189abc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x189ac0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_4060_0x189ab4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x189ab4ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f2f08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4061 | PC: 0x18a04c | FDE: 0x1f2f30 | Size: 164 bytes
// Khung tháo gỡ #4061 | Địa chỉ PC: 0x18a04c | Địa chỉ FDE: 0x1f2f30 | Kích thước: 164 bytes
//   0x18a04c: D10143FF  sub      sp, sp, #0x50
//   0x18a050: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x18a054: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x18a058: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_4061_0x18a04c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18a04cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1f2f30ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #4062 | PC: 0x18a0f0 | FDE: 0x1f2f58 | Size: 12 bytes [PyInit_time]
// Khung tháo gỡ #4062 | Địa chỉ PC: 0x18a0f0 | Địa chỉ FDE: 0x1f2f58 | Kích thước: 12 bytes
//   0x18a0f0: F00004A0  adrp     x0, #0x221000
//   0x18a0f4: 913F0000  add      x0, x0, #0xfc0
//   0x18a0f8: 17FB3A4A  b        #0x58a20
static inline uint64_t fde_func_4062_0x18a0f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18a0f0ULL ^ (static_cast<uint64_t>(0xf00004a0ULL) << 13);
    acc = (acc + a1 + 0x913f0000ULL) ^ 0x1f2f58ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #4063 | PC: 0x18a0fc | FDE: 0x1f2f70 | Size: 100 bytes
// Khung tháo gỡ #4063 | Địa chỉ PC: 0x18a0fc | Địa chỉ FDE: 0x1f2f70 | Kích thước: 100 bytes
//   0x18a0fc: D100C3FF  sub      sp, sp, #0x30
//   0x18a100: F9000BF3  str      x19, [sp, #0x10]
//   0x18a104: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x18a108: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_4063_0x18a0fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18a0fcULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x1f2f70ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #4064 | PC: 0x18a160 | FDE: 0x1f2f90 | Size: 256 bytes
// Khung tháo gỡ #4064 | Địa chỉ PC: 0x18a160 | Địa chỉ FDE: 0x1f2f90 | Kích thước: 256 bytes
//   0x18a160: D10183FF  sub      sp, sp, #0x60
//   0x18a164: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x18a168: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x18a16c: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_4064_0x18a160(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18a160ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x1f2f90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4065 | PC: 0x18a29c | FDE: 0x1f2fb8 | Size: 212 bytes
// Khung tháo gỡ #4065 | Địa chỉ PC: 0x18a29c | Địa chỉ FDE: 0x1f2fb8 | Kích thước: 212 bytes
//   0x18a29c: D101C3FF  sub      sp, sp, #0x70
//   0x18a2a0: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x18a2a4: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x18a2a8: 910183FD  add      x29, sp, #0x60
static inline uint64_t fde_func_4065_0x18a29c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18a29cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9054ff4ULL) ^ 0x1f2fb8ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #4066 | PC: 0x18a370 | FDE: 0x1f2fd8 | Size: 256 bytes
// Khung tháo gỡ #4066 | Địa chỉ PC: 0x18a370 | Địa chỉ FDE: 0x1f2fd8 | Kích thước: 256 bytes
//   0x18a370: D10443FF  sub      sp, sp, #0x110
//   0x18a374: F90073FC  str      x28, [sp, #0xe0]
//   0x18a378: A90F4FF4  stp      x20, x19, [sp, #0xf0]
//   0x18a37c: A9107BFD  stp      x29, x30, [sp, #0x100]
static inline uint64_t fde_func_4066_0x18a370(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18a370ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xf90073fcULL) ^ 0x1f2fd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4067 | PC: 0x18a47c | FDE: 0x1f2ff8 | Size: 256 bytes
// Khung tháo gỡ #4067 | Địa chỉ PC: 0x18a47c | Địa chỉ FDE: 0x1f2ff8 | Kích thước: 256 bytes
//   0x18a47c: D102C3FF  sub      sp, sp, #0xb0
//   0x18a480: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x18a484: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x18a488: A9094FF4  stp      x20, x19, [sp, #0x90]
static inline uint64_t fde_func_4067_0x18a47c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18a47cULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9075ff8ULL) ^ 0x1f2ff8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4068 | PC: 0x18a7bc | FDE: 0x1f3020 | Size: 100 bytes
// Khung tháo gỡ #4068 | Địa chỉ PC: 0x18a7bc | Địa chỉ FDE: 0x1f3020 | Kích thước: 100 bytes
//   0x18a7bc: D100C3FF  sub      sp, sp, #0x30
//   0x18a7c0: F9000BF3  str      x19, [sp, #0x10]
//   0x18a7c4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x18a7c8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_4068_0x18a7bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18a7bcULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x1f3020ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #4069 | PC: 0x18a820 | FDE: 0x1f3040 | Size: 256 bytes
// Khung tháo gỡ #4069 | Địa chỉ PC: 0x18a820 | Địa chỉ FDE: 0x1f3040 | Kích thước: 256 bytes
//   0x18a820: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x18a824: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x18a828: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x18a82c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_4069_0x18a820(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18a820ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f3040ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4070 | PC: 0x18a94c | FDE: 0x1f3068 | Size: 256 bytes
// Khung tháo gỡ #4070 | Địa chỉ PC: 0x18a94c | Địa chỉ FDE: 0x1f3068 | Kích thước: 256 bytes
//   0x18a94c: D10203FF  sub      sp, sp, #0x80
//   0x18a950: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x18a954: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x18a958: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_4070_0x18a94c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18a94cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90557f6ULL) ^ 0x1f3068ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4071 | PC: 0x18ac00 | FDE: 0x1f3090 | Size: 12 bytes [PyInit_xx]
// Khung tháo gỡ #4071 | Địa chỉ PC: 0x18ac00 | Địa chỉ FDE: 0x1f3090 | Kích thước: 12 bytes
//   0x18ac00: 900004C0  adrp     x0, #0x222000
//   0x18ac04: 91082000  add      x0, x0, #0x208
//   0x18ac08: 17FB3786  b        #0x58a20
static inline uint64_t fde_func_4071_0x18ac00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18ac00ULL ^ (static_cast<uint64_t>(0x900004c0ULL) << 13);
    acc = (acc + a1 + 0x91082000ULL) ^ 0x1f3090ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #4072 | PC: 0x18ac0c | FDE: 0x1f30a8 | Size: 120 bytes
// Khung tháo gỡ #4072 | Địa chỉ PC: 0x18ac0c | Địa chỉ FDE: 0x1f30a8 | Kích thước: 120 bytes
//   0x18ac0c: D10103FF  sub      sp, sp, #0x40
//   0x18ac10: F90013F3  str      x19, [sp, #0x20]
//   0x18ac14: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x18ac18: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_4072_0x18ac0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18ac0cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x1f30a8ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #4073 | PC: 0x18ac84 | FDE: 0x1f30c8 | Size: 112 bytes
// Khung tháo gỡ #4073 | Địa chỉ PC: 0x18ac84 | Địa chỉ FDE: 0x1f30c8 | Kích thước: 112 bytes
//   0x18ac84: D10103FF  sub      sp, sp, #0x40
//   0x18ac88: F90013F3  str      x19, [sp, #0x20]
//   0x18ac8c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x18ac90: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_4073_0x18ac84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18ac84ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x1f30c8ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #4074 | PC: 0x18acf4 | FDE: 0x1f30e8 | Size: 68 bytes
// Khung tháo gỡ #4074 | Địa chỉ PC: 0x18acf4 | Địa chỉ FDE: 0x1f30e8 | Kích thước: 68 bytes
//   0x18acf4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x18acf8: 910003FD  mov      x29, sp
//   0x18acfc: AA0103E0  mov      x0, x1
//   0x18ad00: D00001E1  adrp     x1, #0x1c8000
static inline uint64_t fde_func_4074_0x18acf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18acf4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f30e8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #4075 | PC: 0x18ad38 | FDE: 0x1f3108 | Size: 216 bytes
// Khung tháo gỡ #4075 | Địa chỉ PC: 0x18ad38 | Địa chỉ FDE: 0x1f3108 | Kích thước: 216 bytes
//   0x18ad38: D10103FF  sub      sp, sp, #0x40
//   0x18ad3c: F9000BF5  str      x21, [sp, #0x10]
//   0x18ad40: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x18ad44: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_4075_0x18ad38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18ad38ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1f3108ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #4076 | PC: 0x18ae10 | FDE: 0x1f3128 | Size: 60 bytes
// Khung tháo gỡ #4076 | Địa chỉ PC: 0x18ae10 | Địa chỉ FDE: 0x1f3128 | Kích thước: 60 bytes
//   0x18ae10: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x18ae14: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18ae18: 910043FD  add      x29, sp, #0x10
//   0x18ae1c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_4076_0x18ae10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18ae10ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f3128ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #4077 | PC: 0x18ae4c | FDE: 0x1f3148 | Size: 160 bytes
// Khung tháo gỡ #4077 | Địa chỉ PC: 0x18ae4c | Địa chỉ FDE: 0x1f3148 | Kích thước: 160 bytes
//   0x18ae4c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x18ae50: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x18ae54: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x18ae58: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_4077_0x18ae4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18ae4cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f3148ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #4078 | PC: 0x18aeec | FDE: 0x1f3168 | Size: 100 bytes
// Khung tháo gỡ #4078 | Địa chỉ PC: 0x18aeec | Địa chỉ FDE: 0x1f3168 | Kích thước: 100 bytes
//   0x18aeec: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x18aef0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18aef4: 910043FD  add      x29, sp, #0x10
//   0x18aef8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_4078_0x18aeec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18aeecULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f3168ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #4079 | PC: 0x18af50 | FDE: 0x1f3188 | Size: 68 bytes
// Khung tháo gỡ #4079 | Địa chỉ PC: 0x18af50 | Địa chỉ FDE: 0x1f3188 | Kích thước: 68 bytes
//   0x18af50: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x18af54: 910003FD  mov      x29, sp
//   0x18af58: AA0103E0  mov      x0, x1
//   0x18af5c: D00001E1  adrp     x1, #0x1c8000
static inline uint64_t fde_func_4079_0x18af50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18af50ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f3188ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #4080 | PC: 0x18af94 | FDE: 0x1f31a8 | Size: 256 bytes
// Khung tháo gỡ #4080 | Địa chỉ PC: 0x18af94 | Địa chỉ FDE: 0x1f31a8 | Kích thước: 256 bytes
//   0x18af94: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x18af98: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18af9c: 910043FD  add      x29, sp, #0x10
//   0x18afa0: B00003A9  adrp     x9, #0x1ff000
static inline uint64_t fde_func_4080_0x18af94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18af94ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f31a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4081 | PC: 0x18b09c | FDE: 0x1f31c8 | Size: 24 bytes
// Khung tháo gỡ #4081 | Địa chỉ PC: 0x18b09c | Địa chỉ FDE: 0x1f31c8 | Kích thước: 24 bytes
//   0x18b09c: 900003A0  adrp     x0, #0x1ff000
//   0x18b0a0: F943FC00  ldr      x0, [x0, #0x7f8]
//   0x18b0a4: F9400008  ldr      x8, [x0]
//   0x18b0a8: 91000508  add      x8, x8, #1
static inline uint64_t fde_func_4081_0x18b09c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18b09cULL ^ (static_cast<uint64_t>(0x900003a0ULL) << 13);
    acc = (acc + a1 + 0xf943fc00ULL) ^ 0x1f31c8ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #4082 | PC: 0x18b0b4 | FDE: 0x1f31e0 | Size: 256 bytes [_PyMem_DumpTraceback]
// Khung tháo gỡ #4082 | Địa chỉ PC: 0x18b0b4 | Địa chỉ FDE: 0x1f31e0 | Kích thước: 256 bytes
//   0x18b0b4: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x18b0b8: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x18b0bc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x18b0c0: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_4082_0x18b0b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18b0b4ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1f31e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4083 | PC: 0x18b268 | FDE: 0x1f3208 | Size: 156 bytes
// Khung tháo gỡ #4083 | Địa chỉ PC: 0x18b268 | Địa chỉ FDE: 0x1f3208 | Kích thước: 156 bytes
//   0x18b268: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x18b26c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x18b270: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x18b274: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_4083_0x18b268(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18b268ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f3208ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #4084 | PC: 0x18b304 | FDE: 0x1f3228 | Size: 88 bytes [PyInit__tracemalloc]
// Khung tháo gỡ #4084 | Địa chỉ PC: 0x18b304 | Địa chỉ FDE: 0x1f3228 | Kích thước: 88 bytes
//   0x18b304: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x18b308: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18b30c: 910043FD  add      x29, sp, #0x10
//   0x18b310: F00004A0  adrp     x0, #0x222000
static inline uint64_t fde_func_4084_0x18b304(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18b304ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f3228ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #4085 | PC: 0x18b35c | FDE: 0x1f3248 | Size: 256 bytes
// Khung tháo gỡ #4085 | Địa chỉ PC: 0x18b35c | Địa chỉ FDE: 0x1f3248 | Kích thước: 256 bytes
//   0x18b35c: D101C3FF  sub      sp, sp, #0x70
//   0x18b360: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x18b364: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x18b368: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_4085_0x18b35c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18b35cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x1f3248ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4086 | PC: 0x18b5dc | FDE: 0x1f3270 | Size: 12 bytes [_PyTraceMalloc_Init]
// Khung tháo gỡ #4086 | Địa chỉ PC: 0x18b5dc | Địa chỉ FDE: 0x1f3270 | Kích thước: 12 bytes
//   0x18b5dc: 34000040  cbz      w0, #0x18b5e4
//   0x18b5e0: 14000002  b        #0x18b5e8
//   0x18b5e4: D65F03C0  ret      
static inline uint64_t fde_func_4086_0x18b5dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18b5dcULL ^ (static_cast<uint64_t>(0x34000040ULL) << 13);
    acc = (acc + a1 + 0x14000002ULL) ^ 0x1f3270ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #4087 | PC: 0x18b5e8 | FDE: 0x1f3288 | Size: 256 bytes
// Khung tháo gỡ #4087 | Địa chỉ PC: 0x18b5e8 | Địa chỉ FDE: 0x1f3288 | Kích thước: 256 bytes
//   0x18b5e8: D10183FF  sub      sp, sp, #0x60
//   0x18b5ec: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x18b5f0: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x18b5f4: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_4087_0x18b5e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18b5e8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x1f3288ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4088 | PC: 0x18b76c | FDE: 0x1f32b0 | Size: 256 bytes [_PyTraceMalloc_Fini]
// Khung tháo gỡ #4088 | Địa chỉ PC: 0x18b76c | Địa chỉ FDE: 0x1f32b0 | Kích thước: 256 bytes
//   0x18b76c: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x18b770: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x18b774: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x18b778: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_4088_0x18b76c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18b76cULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1f32b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4089 | PC: 0x18b8d0 | FDE: 0x1f32d8 | Size: 148 bytes [PyTraceMalloc_Track]
// Khung tháo gỡ #4089 | Địa chỉ PC: 0x18b8d0 | Địa chỉ FDE: 0x1f32d8 | Kích thước: 148 bytes
//   0x18b8d0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x18b8d4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x18b8d8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x18b8dc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_4089_0x18b8d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18b8d0ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f32d8ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #4090 | PC: 0x18b964 | FDE: 0x1f3300 | Size: 256 bytes
// Khung tháo gỡ #4090 | Địa chỉ PC: 0x18b964 | Địa chỉ FDE: 0x1f3300 | Kích thước: 256 bytes
//   0x18b964: D101C3FF  sub      sp, sp, #0x70
//   0x18b968: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x18b96c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x18b970: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_4090_0x18b964(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18b964ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x1f3300ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4091 | PC: 0x18bb00 | FDE: 0x1f3330 | Size: 188 bytes [PyTraceMalloc_Untrack]
// Khung tháo gỡ #4091 | Địa chỉ PC: 0x18bb00 | Địa chỉ FDE: 0x1f3330 | Kích thước: 188 bytes
//   0x18bb00: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x18bb04: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x18bb08: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x18bb0c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_4091_0x18bb00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18bb00ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f3330ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #4092 | PC: 0x18bbbc | FDE: 0x1f3350 | Size: 156 bytes [_PyTraceMalloc_NewReference]
// Khung tháo gỡ #4092 | Địa chỉ PC: 0x18bbbc | Địa chỉ FDE: 0x1f3350 | Kích thước: 156 bytes
//   0x18bbbc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x18bbc0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x18bbc4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x18bbc8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_4092_0x18bbbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18bbbcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f3350ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #4093 | PC: 0x18bc58 | FDE: 0x1f3370 | Size: 256 bytes
// Khung tháo gỡ #4093 | Địa chỉ PC: 0x18bc58 | Địa chỉ FDE: 0x1f3370 | Kích thước: 256 bytes
//   0x18bc58: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x18bc5c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x18bc60: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x18bc64: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_4093_0x18bc58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18bc58ULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1f3370ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4094 | PC: 0x18beec | FDE: 0x1f33a0 | Size: 56 bytes [_PyTraceMalloc_GetTraceback]
// Khung tháo gỡ #4094 | Địa chỉ PC: 0x18beec | Địa chỉ FDE: 0x1f33a0 | Kích thước: 56 bytes
//   0x18beec: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x18bef0: 910003FD  mov      x29, sp
//   0x18bef4: 97FFFCDD  bl       #0x18b268
//   0x18bef8: B4000080  cbz      x0, #0x18bf08
static inline uint64_t fde_func_4094_0x18beec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18beecULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f33a0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #4095 | PC: 0x18bf24 | FDE: 0x1f33c0 | Size: 256 bytes
// Khung tháo gỡ #4095 | Địa chỉ PC: 0x18bf24 | Địa chỉ FDE: 0x1f33c0 | Kích thước: 256 bytes
//   0x18bf24: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x18bf28: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x18bf2c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x18bf30: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_4095_0x18bf24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18bf24ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f33c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4096 | PC: 0x18c05c | FDE: 0x1f33e8 | Size: 16 bytes
// Khung tháo gỡ #4096 | Địa chỉ PC: 0x18c05c | Địa chỉ FDE: 0x1f33e8 | Kích thước: 16 bytes
//   0x18c05c: F0000388  adrp     x8, #0x1ff000
//   0x18c060: F9450108  ldr      x8, [x8, #0xa00]
//   0x18c064: B9800500  ldrsw    x0, [x8, #4]
//   0x18c068: 17FB3A6E  b        #0x5aa20
static inline uint64_t fde_func_4096_0x18c05c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18c05cULL ^ (static_cast<uint64_t>(0xf0000388ULL) << 13);
    acc = (acc + a1 + 0xf9450108ULL) ^ 0x1f33e8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #4097 | PC: 0x18c06c | FDE: 0x1f3400 | Size: 184 bytes
// Khung tháo gỡ #4097 | Địa chỉ PC: 0x18c06c | Địa chỉ FDE: 0x1f3400 | Kích thước: 184 bytes
//   0x18c06c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x18c070: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18c074: 910043FD  add      x29, sp, #0x10
//   0x18c078: F0000388  adrp     x8, #0x1ff000
static inline uint64_t fde_func_4097_0x18c06c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18c06cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f3400ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #4098 | PC: 0x18c124 | FDE: 0x1f3420 | Size: 256 bytes
// Khung tháo gỡ #4098 | Địa chỉ PC: 0x18c124 | Địa chỉ FDE: 0x1f3420 | Kích thước: 256 bytes
//   0x18c124: D10243FF  sub      sp, sp, #0x90
//   0x18c128: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x18c12c: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x18c130: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_4098_0x18c124(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18c124ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90657f6ULL) ^ 0x1f3420ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4099 | PC: 0x18c398 | FDE: 0x1f3448 | Size: 168 bytes
// Khung tháo gỡ #4099 | Địa chỉ PC: 0x18c398 | Địa chỉ FDE: 0x1f3448 | Kích thước: 168 bytes
//   0x18c398: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x18c39c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18c3a0: 910043FD  add      x29, sp, #0x10
//   0x18c3a4: F9400428  ldr      x8, [x1, #8]
static inline uint64_t fde_func_4099_0x18c398(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18c398ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f3448ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #4100 | PC: 0x18c440 | FDE: 0x1f3468 | Size: 164 bytes
// Khung tháo gỡ #4100 | Địa chỉ PC: 0x18c440 | Địa chỉ FDE: 0x1f3468 | Kích thước: 164 bytes
//   0x18c440: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x18c444: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18c448: 910043FD  add      x29, sp, #0x10
//   0x18c44c: AA0203F4  mov      x20, x2
static inline uint64_t fde_func_4100_0x18c440(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18c440ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f3468ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #4101 | PC: 0x18c4e4 | FDE: 0x1f3488 | Size: 220 bytes
// Khung tháo gỡ #4101 | Địa chỉ PC: 0x18c4e4 | Địa chỉ FDE: 0x1f3488 | Kích thước: 220 bytes
//   0x18c4e4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x18c4e8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18c4ec: 910043FD  add      x29, sp, #0x10
//   0x18c4f0: F0000388  adrp     x8, #0x1ff000
static inline uint64_t fde_func_4101_0x18c4e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18c4e4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f3488ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #4102 | PC: 0x18c5c0 | FDE: 0x1f34a8 | Size: 16 bytes
// Khung tháo gỡ #4102 | Địa chỉ PC: 0x18c5c0 | Địa chỉ FDE: 0x1f34a8 | Kích thước: 16 bytes
//   0x18c5c0: F0000388  adrp     x8, #0x1ff000
//   0x18c5c4: F9450108  ldr      x8, [x8, #0xa00]
//   0x18c5c8: B9800900  ldrsw    x0, [x8, #8]
//   0x18c5cc: 17FB3869  b        #0x5a770
static inline uint64_t fde_func_4102_0x18c5c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18c5c0ULL ^ (static_cast<uint64_t>(0xf0000388ULL) << 13);
    acc = (acc + a1 + 0xf9450108ULL) ^ 0x1f34a8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #4103 | PC: 0x18c5d0 | FDE: 0x1f34c0 | Size: 192 bytes
// Khung tháo gỡ #4103 | Địa chỉ PC: 0x18c5d0 | Địa chỉ FDE: 0x1f34c0 | Kích thước: 192 bytes
//   0x18c5d0: D10103FF  sub      sp, sp, #0x40
//   0x18c5d4: F9000BF5  str      x21, [sp, #0x10]
//   0x18c5d8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x18c5dc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_4103_0x18c5d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18c5d0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1f34c0ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #4104 | PC: 0x18c690 | FDE: 0x1f34e0 | Size: 136 bytes
// Khung tháo gỡ #4104 | Địa chỉ PC: 0x18c690 | Địa chỉ FDE: 0x1f34e0 | Kích thước: 136 bytes
//   0x18c690: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x18c694: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x18c698: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x18c69c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_4104_0x18c690(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18c690ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f34e0ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #4105 | PC: 0x18c718 | FDE: 0x1f3500 | Size: 100 bytes
// Khung tháo gỡ #4105 | Địa chỉ PC: 0x18c718 | Địa chỉ FDE: 0x1f3500 | Kích thước: 100 bytes
//   0x18c718: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x18c71c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18c720: 910043FD  add      x29, sp, #0x10
//   0x18c724: F0000388  adrp     x8, #0x1ff000
static inline uint64_t fde_func_4105_0x18c718(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18c718ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f3500ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #4106 | PC: 0x18c77c | FDE: 0x1f3520 | Size: 24 bytes
// Khung tháo gỡ #4106 | Địa chỉ PC: 0x18c77c | Địa chỉ FDE: 0x1f3520 | Kích thước: 24 bytes
//   0x18c77c: F9400008  ldr      x8, [x0]
//   0x18c780: F1000508  subs     x8, x8, #1
//   0x18c784: F9000008  str      x8, [x0]
//   0x18c788: 54000040  b.eq     #0x18c790
static inline uint64_t fde_func_4106_0x18c77c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18c77cULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf1000508ULL) ^ 0x1f3520ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #4107 | PC: 0x18c794 | FDE: 0x1f3538 | Size: 220 bytes
// Khung tháo gỡ #4107 | Địa chỉ PC: 0x18c794 | Địa chỉ FDE: 0x1f3538 | Kích thước: 220 bytes
//   0x18c794: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x18c798: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x18c79c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x18c7a0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_4107_0x18c794(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18c794ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f3538ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #4108 | PC: 0x18c870 | FDE: 0x1f3560 | Size: 28 bytes
// Khung tháo gỡ #4108 | Địa chỉ PC: 0x18c870 | Địa chỉ FDE: 0x1f3560 | Kích thước: 28 bytes
//   0x18c870: 90000008  adrp     x8, #0x18c000
//   0x18c874: 911E5108  add      x8, x8, #0x794
//   0x18c878: AA0203E0  mov      x0, x2
//   0x18c87c: B9002061  str      w1, [x3, #0x20]
static inline uint64_t fde_func_4108_0x18c870(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18c870ULL ^ (static_cast<uint64_t>(0x90000008ULL) << 13);
    acc = (acc + a1 + 0x911e5108ULL) ^ 0x1f3560ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #4109 | PC: 0x18c88c | FDE: 0x1f3578 | Size: 136 bytes
// Khung tháo gỡ #4109 | Địa chỉ PC: 0x18c88c | Địa chỉ FDE: 0x1f3578 | Kích thước: 136 bytes
//   0x18c88c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x18c890: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x18c894: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x18c898: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_4109_0x18c88c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18c88cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f3578ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #4110 | PC: 0x18c914 | FDE: 0x1f35a0 | Size: 28 bytes
// Khung tháo gỡ #4110 | Địa chỉ PC: 0x18c914 | Địa chỉ FDE: 0x1f35a0 | Kích thước: 28 bytes
//   0x18c914: D00004C8  adrp     x8, #0x226000
//   0x18c918: 91330108  add      x8, x8, #0xcc0
//   0x18c91c: F9401102  ldr      x2, [x8, #0x20]
//   0x18c920: F9400108  ldr      x8, [x8]
static inline uint64_t fde_func_4110_0x18c914(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18c914ULL ^ (static_cast<uint64_t>(0xd00004c8ULL) << 13);
    acc = (acc + a1 + 0x91330108ULL) ^ 0x1f35a0ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #4111 | PC: 0x18c930 | FDE: 0x1f35b8 | Size: 228 bytes
// Khung tháo gỡ #4111 | Địa chỉ PC: 0x18c930 | Địa chỉ FDE: 0x1f35b8 | Kích thước: 228 bytes
//   0x18c930: D10183FF  sub      sp, sp, #0x60
//   0x18c934: F90013F7  str      x23, [sp, #0x20]
//   0x18c938: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x18c93c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_4111_0x18c930(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18c930ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1f35b8ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #4112 | PC: 0x18ca14 | FDE: 0x1f35e0 | Size: 8 bytes
// Khung tháo gỡ #4112 | Địa chỉ PC: 0x18ca14 | Địa chỉ FDE: 0x1f35e0 | Kích thước: 8 bytes
//   0x18ca14: 92407C00  and      x0, x0, #0xffffffff
//   0x18ca18: D65F03C0  ret      
static inline uint64_t fde_func_4112_0x18ca14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18ca14ULL ^ (static_cast<uint64_t>(0x92407c00ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1f35e0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #4113 | PC: 0x18ca1c | FDE: 0x1f35f8 | Size: 52 bytes
// Khung tháo gỡ #4113 | Địa chỉ PC: 0x18ca1c | Địa chỉ FDE: 0x1f35f8 | Kích thước: 52 bytes
//   0x18ca1c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x18ca20: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18ca24: 910043FD  add      x29, sp, #0x10
//   0x18ca28: AA0203E0  mov      x0, x2
static inline uint64_t fde_func_4113_0x18ca1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18ca1cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f35f8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #4114 | PC: 0x18ca50 | FDE: 0x1f3618 | Size: 4 bytes
// Khung tháo gỡ #4114 | Địa chỉ PC: 0x18ca50 | Địa chỉ FDE: 0x1f3618 | Kích thước: 4 bytes
//   0x18ca50: 17FB3C1C  b        #0x5bac0
static inline uint64_t fde_func_4114_0x18ca50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18ca50ULL ^ (static_cast<uint64_t>(0x17fb3c1cULL) << 13);
    acc = (acc + a1 + 0xb4000120ULL) ^ 0x1f3618ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #4115 | PC: 0x18ca54 | FDE: 0x1f3630 | Size: 48 bytes
// Khung tháo gỡ #4115 | Địa chỉ PC: 0x18ca54 | Địa chỉ FDE: 0x1f3630 | Kích thước: 48 bytes
//   0x18ca54: B4000120  cbz      x0, #0x18ca78
//   0x18ca58: B4000101  cbz      x1, #0x18ca78
//   0x18ca5c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x18ca60: 910003FD  mov      x29, sp
static inline uint64_t fde_func_4115_0x18ca54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18ca54ULL ^ (static_cast<uint64_t>(0xb4000120ULL) << 13);
    acc = (acc + a1 + 0xb4000101ULL) ^ 0x1f3630ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #4116 | PC: 0x18ca84 | FDE: 0x1f3650 | Size: 24 bytes
// Khung tháo gỡ #4116 | Địa chỉ PC: 0x18ca84 | Địa chỉ FDE: 0x1f3650 | Kích thước: 24 bytes
//   0x18ca84: F9400008  ldr      x8, [x0]
//   0x18ca88: F1000508  subs     x8, x8, #1
//   0x18ca8c: F9000008  str      x8, [x0]
//   0x18ca90: 54000040  b.eq     #0x18ca98
static inline uint64_t fde_func_4116_0x18ca84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18ca84ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf1000508ULL) ^ 0x1f3650ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #4117 | PC: 0x18ca9c | FDE: 0x1f3668 | Size: 8 bytes
// Khung tháo gỡ #4117 | Địa chỉ PC: 0x18ca9c | Địa chỉ FDE: 0x1f3668 | Kích thước: 8 bytes
//   0x18ca9c: F9400000  ldr      x0, [x0]
//   0x18caa0: D65F03C0  ret      
static inline uint64_t fde_func_4117_0x18ca9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18ca9cULL ^ (static_cast<uint64_t>(0xf9400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1f3668ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #4118 | PC: 0x18caa4 | FDE: 0x1f3680 | Size: 108 bytes
// Khung tháo gỡ #4118 | Địa chỉ PC: 0x18caa4 | Địa chỉ FDE: 0x1f3680 | Kích thước: 108 bytes
//   0x18caa4: 79401008  ldrh     w8, [x0, #8]
//   0x18caa8: 79401029  ldrh     w9, [x1, #8]
//   0x18caac: 6B09011F  cmp      w8, w9
//   0x18cab0: 540002C1  b.ne     #0x18cb08
static inline uint64_t fde_func_4118_0x18caa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18caa4ULL ^ (static_cast<uint64_t>(0x79401008ULL) << 13);
    acc = (acc + a1 + 0x79401029ULL) ^ 0x1f3680ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #4119 | PC: 0x18cb10 | FDE: 0x1f3698 | Size: 20 bytes
// Khung tháo gỡ #4119 | Địa chỉ PC: 0x18cb10 | Địa chỉ FDE: 0x1f3698 | Kích thước: 20 bytes
//   0x18cb10: AA0103E3  mov      x3, x1
//   0x18cb14: 52800022  mov      w2, #1
//   0x18cb18: AA0003E1  mov      x1, x0
//   0x18cb1c: 2A1F03E0  mov      w0, wzr
static inline uint64_t fde_func_4119_0x18cb10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18cb10ULL ^ (static_cast<uint64_t>(0xaa0103e3ULL) << 13);
    acc = (acc + a1 + 0x52800022ULL) ^ 0x1f3698ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #4120 | PC: 0x18cb24 | FDE: 0x1f36b0 | Size: 24 bytes
// Khung tháo gỡ #4120 | Địa chỉ PC: 0x18cb24 | Địa chỉ FDE: 0x1f36b0 | Kích thước: 24 bytes
//   0x18cb24: AA0003E8  mov      x8, x0
//   0x18cb28: AA0203E3  mov      x3, x2
//   0x18cb2c: 52800020  mov      w0, #1
//   0x18cb30: AA0103E2  mov      x2, x1
static inline uint64_t fde_func_4120_0x18cb24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18cb24ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xaa0203e3ULL) ^ 0x1f36b0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #4121 | PC: 0x18cb3c | FDE: 0x1f36c8 | Size: 256 bytes
// Khung tháo gỡ #4121 | Địa chỉ PC: 0x18cb3c | Địa chỉ FDE: 0x1f36c8 | Kích thước: 256 bytes
//   0x18cb3c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x18cb40: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x18cb44: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x18cb48: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_4121_0x18cb3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18cb3cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f36c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4122 | PC: 0x18cc50 | FDE: 0x1f36f0 | Size: 136 bytes
// Khung tháo gỡ #4122 | Địa chỉ PC: 0x18cc50 | Địa chỉ FDE: 0x1f36f0 | Kích thước: 136 bytes
//   0x18cc50: B4000421  cbz      x1, #0x18ccd4
//   0x18cc54: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x18cc58: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18cc5c: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_4122_0x18cc50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18cc50ULL ^ (static_cast<uint64_t>(0xb4000421ULL) << 13);
    acc = (acc + a1 + 0xa9be4ff4ULL) ^ 0x1f36f0ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #4123 | PC: 0x18ccd8 | FDE: 0x1f3710 | Size: 20 bytes
// Khung tháo gỡ #4123 | Địa chỉ PC: 0x18ccd8 | Địa chỉ FDE: 0x1f3710 | Kích thước: 20 bytes
//   0x18ccd8: AA0103E3  mov      x3, x1
//   0x18ccdc: 52800022  mov      w2, #1
//   0x18cce0: AA0003E1  mov      x1, x0
//   0x18cce4: 2A1F03E0  mov      w0, wzr
static inline uint64_t fde_func_4123_0x18ccd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18ccd8ULL ^ (static_cast<uint64_t>(0xaa0103e3ULL) << 13);
    acc = (acc + a1 + 0x52800022ULL) ^ 0x1f3710ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #4124 | PC: 0x18ccec | FDE: 0x1f3728 | Size: 24 bytes
// Khung tháo gỡ #4124 | Địa chỉ PC: 0x18ccec | Địa chỉ FDE: 0x1f3728 | Kích thước: 24 bytes
//   0x18ccec: AA0003E8  mov      x8, x0
//   0x18ccf0: AA0203E3  mov      x3, x2
//   0x18ccf4: 52800020  mov      w0, #1
//   0x18ccf8: AA0103E2  mov      x2, x1
static inline uint64_t fde_func_4124_0x18ccec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18ccecULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xaa0203e3ULL) ^ 0x1f3728ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #4125 | PC: 0x18cd04 | FDE: 0x1f3740 | Size: 252 bytes
// Khung tháo gỡ #4125 | Địa chỉ PC: 0x18cd04 | Địa chỉ FDE: 0x1f3740 | Kích thước: 252 bytes
//   0x18cd04: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x18cd08: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x18cd0c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x18cd10: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_4125_0x18cd04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18cd04ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f3740ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #4126 | PC: 0x18ce00 | FDE: 0x1f3768 | Size: 256 bytes
// Khung tháo gỡ #4126 | Địa chỉ PC: 0x18ce00 | Địa chỉ FDE: 0x1f3768 | Kích thước: 256 bytes
//   0x18ce00: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x18ce04: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x18ce08: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x18ce0c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_4126_0x18ce00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18ce00ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f3768ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4127 | PC: 0x18cf44 | FDE: 0x1f3790 | Size: 256 bytes
// Khung tháo gỡ #4127 | Địa chỉ PC: 0x18cf44 | Địa chỉ FDE: 0x1f3790 | Kích thước: 256 bytes
//   0x18cf44: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x18cf48: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x18cf4c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x18cf50: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_4127_0x18cf44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18cf44ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f3790ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4128 | PC: 0x18d05c | FDE: 0x1f37b8 | Size: 256 bytes
// Khung tháo gỡ #4128 | Địa chỉ PC: 0x18d05c | Địa chỉ FDE: 0x1f37b8 | Kích thước: 256 bytes
//   0x18d05c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x18d060: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x18d064: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x18d068: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_4128_0x18d05c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d05cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f37b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4129 | PC: 0x18d190 | FDE: 0x1f37e0 | Size: 68 bytes [_ZN12BDPyDebugger7ExcInfoD2Ev]
// Khung tháo gỡ #4129 | Địa chỉ PC: 0x18d190 | Địa chỉ FDE: 0x1f37e0 | Kích thước: 68 bytes
//   0x18d190: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x18d194: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18d198: 910043FD  add      x29, sp, #0x10
//   0x18d19c: 39406008  ldrb     w8, [x0, #0x18]
static inline uint64_t fde_func_4129_0x18d190(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d190ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f37e0ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #4130 | PC: 0x18d1d4 | FDE: 0x1f3800 | Size: 8 bytes [_ZN12BDPyDebugger5EventD2Ev]
// Khung tháo gỡ #4130 | Địa chỉ PC: 0x18d1d4 | Địa chỉ FDE: 0x1f3800 | Kích thước: 8 bytes
//   0x18d1d4: 91002000  add      x0, x0, #8
//   0x18d1d8: 17FB3472  b        #0x5a3a0
static inline uint64_t fde_func_4130_0x18d1d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d1d4ULL ^ (static_cast<uint64_t>(0x91002000ULL) << 13);
    acc = (acc + a1 + 0x17fb3472ULL) ^ 0x1f3800ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #4131 | PC: 0x18d1dc | FDE: 0x1f3818 | Size: 156 bytes [_ZN12BDPyDebugger5Event4waitEv]
// Khung tháo gỡ #4131 | Địa chỉ PC: 0x18d1dc | Địa chỉ FDE: 0x1f3818 | Kích thước: 156 bytes
//   0x18d1dc: D10143FF  sub      sp, sp, #0x50
//   0x18d1e0: F90013F5  str      x21, [sp, #0x20]
//   0x18d1e4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x18d1e8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_4131_0x18d1dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d1dcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1f3818ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #4132 | PC: 0x18d278 | FDE: 0x1f3838 | Size: 60 bytes [_ZN12BDPyDebugger5Event4fireEv]
// Khung tháo gỡ #4132 | Địa chỉ PC: 0x18d278 | Địa chỉ FDE: 0x1f3838 | Kích thước: 60 bytes
//   0x18d278: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x18d27c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18d280: 910043FD  add      x29, sp, #0x10
//   0x18d284: F9400014  ldr      x20, [x0]
static inline uint64_t fde_func_4132_0x18d278(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d278ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f3838ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #4133 | PC: 0x18d2b4 | FDE: 0x1f3858 | Size: 256 bytes [_Z26BDDbg_getCodeObjectFromPycP7_objectS0_]
// Khung tháo gỡ #4133 | Địa chỉ PC: 0x18d2b4 | Địa chỉ FDE: 0x1f3858 | Kích thước: 256 bytes
//   0x18d2b4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x18d2b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18d2bc: 910043FD  add      x29, sp, #0x10
//   0x18d2c0: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_4133_0x18d2b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d2b4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f3858ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4134 | PC: 0x18d3d0 | FDE: 0x1f3878 | Size: 148 bytes [_Z20BDDbg_getFuncFromModP7_objectS0_]
// Khung tháo gỡ #4134 | Địa chỉ PC: 0x18d3d0 | Địa chỉ FDE: 0x1f3878 | Kích thước: 148 bytes
//   0x18d3d0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x18d3d4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18d3d8: 910043FD  add      x29, sp, #0x10
//   0x18d3dc: F9400C33  ldr      x19, [x1, #0x18]
static inline uint64_t fde_func_4134_0x18d3d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d3d0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f3878ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #4135 | PC: 0x18d464 | FDE: 0x1f3898 | Size: 52 bytes [_Z22BDDbg_getCmdFromNativeP7_objectS0_]
// Khung tháo gỡ #4135 | Địa chỉ PC: 0x18d464 | Địa chỉ FDE: 0x1f3898 | Kích thước: 52 bytes
//   0x18d464: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x18d468: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18d46c: 910043FD  add      x29, sp, #0x10
//   0x18d470: 97FB3C5C  bl       #0x5c5e0
static inline uint64_t fde_func_4135_0x18d464(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d464ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f3898ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #4136 | PC: 0x18d498 | FDE: 0x1f38b8 | Size: 104 bytes [_Z19BDDbg_sendFrameInfoP7_objectS0_]
// Khung tháo gỡ #4136 | Địa chỉ PC: 0x18d498 | Địa chỉ FDE: 0x1f38b8 | Kích thước: 104 bytes
//   0x18d498: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x18d49c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18d4a0: 910043FD  add      x29, sp, #0x10
//   0x18d4a4: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_4136_0x18d498(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d498ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f38b8ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #4137 | PC: 0x18d500 | FDE: 0x1f38d8 | Size: 88 bytes [_Z24BDDbg_launchStatusNotifyP7_objectS0_]
// Khung tháo gỡ #4137 | Địa chỉ PC: 0x18d500 | Địa chỉ FDE: 0x1f38d8 | Kích thước: 88 bytes
//   0x18d500: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x18d504: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18d508: 910043FD  add      x29, sp, #0x10
//   0x18d50c: D0000394  adrp     x20, #0x1ff000
static inline uint64_t fde_func_4137_0x18d500(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d500ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f38d8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #4138 | PC: 0x18d558 | FDE: 0x1f38f8 | Size: 256 bytes [_Z23BDDbg_sendDebuggerStateP7_objectS0_]
// Khung tháo gỡ #4138 | Địa chỉ PC: 0x18d558 | Địa chỉ FDE: 0x1f38f8 | Kích thước: 256 bytes
//   0x18d558: D10243FF  sub      sp, sp, #0x90
//   0x18d55c: F90023F9  str      x25, [sp, #0x40]
//   0x18d560: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x18d564: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_4138_0x18d558(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d558ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90023f9ULL) ^ 0x1f38f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4139 | PC: 0x18d760 | FDE: 0x1f3920 | Size: 152 bytes [_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2IDnEEPKc]
// Khung tháo gỡ #4139 | Địa chỉ PC: 0x18d760 | Địa chỉ FDE: 0x1f3920 | Kích thước: 152 bytes
//   0x18d760: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x18d764: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x18d768: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x18d76c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_4139_0x18d760(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d760ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f3920ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #4140 | PC: 0x18d7f8 | FDE: 0x1f3948 | Size: 188 bytes [_Z16getDebuggerStatev]
// Khung tháo gỡ #4140 | Địa chỉ PC: 0x18d7f8 | Địa chỉ FDE: 0x1f3948 | Kích thước: 188 bytes
//   0x18d7f8: D10143FF  sub      sp, sp, #0x50
//   0x18d7fc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x18d800: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x18d804: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_4140_0x18d7f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d7f8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1f3948ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #4141 | PC: 0x18d8b4 | FDE: 0x1f3970 | Size: 12 bytes [_Z12getframeinfov]
// Khung tháo gỡ #4141 | Địa chỉ PC: 0x18d8b4 | Địa chỉ FDE: 0x1f3970 | Kích thước: 12 bytes
//   0x18d8b4: B00004C8  adrp     x8, #0x226000
//   0x18d8b8: F9471D00  ldr      x0, [x8, #0xe38]
//   0x18d8bc: D65F03C0  ret      
static inline uint64_t fde_func_4141_0x18d8b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d8b4ULL ^ (static_cast<uint64_t>(0xb00004c8ULL) << 13);
    acc = (acc + a1 + 0xf9471d00ULL) ^ 0x1f3970ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #4142 | PC: 0x18d8c0 | FDE: 0x1f3988 | Size: 88 bytes [_Z22BDDbg_exitStatusNotifyP7_objectS0_]
// Khung tháo gỡ #4142 | Địa chỉ PC: 0x18d8c0 | Địa chỉ FDE: 0x1f3988 | Kích thước: 88 bytes
//   0x18d8c0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x18d8c4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18d8c8: 910043FD  add      x29, sp, #0x10
//   0x18d8cc: D0000394  adrp     x20, #0x1ff000
static inline uint64_t fde_func_4142_0x18d8c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d8c0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f3988ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #4143 | PC: 0x18d918 | FDE: 0x1f39a8 | Size: 16 bytes [BDPy_InitDbgHelper]
// Khung tháo gỡ #4143 | Địa chỉ PC: 0x18d918 | Địa chỉ FDE: 0x1f39a8 | Kích thước: 16 bytes
//   0x18d918: B00004A0  adrp     x0, #0x222000
//   0x18d91c: 91280000  add      x0, x0, #0xa00
//   0x18d920: 52807EA1  mov      w1, #0x3f5
//   0x18d924: 17FB3633  b        #0x5b1f0
static inline uint64_t fde_func_4143_0x18d918(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d918ULL ^ (static_cast<uint64_t>(0xb00004a0ULL) << 13);
    acc = (acc + a1 + 0x91280000ULL) ^ 0x1f39a8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #4144 | PC: 0x18d928 | FDE: 0x1f39c0 | Size: 20 bytes [_ZNKSt6__ndk121__basic_string_commonILb1EE20__throw_length_errorEv]
// Khung tháo gỡ #4144 | Địa chỉ PC: 0x18d928 | Địa chỉ FDE: 0x1f39c0 | Kích thước: 20 bytes
//   0x18d928: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x18d92c: 910003FD  mov      x29, sp
//   0x18d930: F00001C0  adrp     x0, #0x1c8000
//   0x18d934: 91280C00  add      x0, x0, #0xa03
static inline uint64_t fde_func_4144_0x18d928(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d928ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f39c0ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #4145 | PC: 0x18d93c | FDE: 0x1f3a20 | Size: 80 bytes
// Khung tháo gỡ #4145 | Địa chỉ PC: 0x18d93c | Địa chỉ FDE: 0x1f3a20 | Kích thước: 80 bytes
//   0x18d93c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x18d940: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18d944: 910043FD  add      x29, sp, #0x10
//   0x18d948: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_4145_0x18d93c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d93cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f3a20ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #4146 | PC: 0x18d98c | FDE: 0x1f39e0 | Size: 48 bytes
// Khung tháo gỡ #4146 | Địa chỉ PC: 0x18d98c | Địa chỉ FDE: 0x1f39e0 | Kích thước: 48 bytes
//   0x18d98c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x18d990: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18d994: 910043FD  add      x29, sp, #0x10
//   0x18d998: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_4146_0x18d98c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d98cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f39e0ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #4147 | PC: 0x18d9bc | FDE: 0x1f3a70 | Size: 120 bytes [_ZNSt6__ndk15queueINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_5dequeIS6_NS4_IS6_EEEEED2Ev]
// Khung tháo gỡ #4147 | Địa chỉ PC: 0x18d9bc | Địa chỉ FDE: 0x1f3a70 | Kích thước: 120 bytes
//   0x18d9bc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x18d9c0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x18d9c4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x18d9c8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_4147_0x18d9bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d9bcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f3a70ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #4148 | PC: 0x18da34 | FDE: 0x1f3bc8 | Size: 236 bytes [_Z6putCmdNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE]
// Khung tháo gỡ #4148 | Địa chỉ PC: 0x18da34 | Địa chỉ FDE: 0x1f3bc8 | Kích thước: 236 bytes
//   0x18da34: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x18da38: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18da3c: 910043FD  add      x29, sp, #0x10
//   0x18da40: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_4148_0x18da34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18da34ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f3bc8ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #4149 | PC: 0x18db20 | FDE: 0x1f3bf0 | Size: 256 bytes [_Z6getCmdv]
// Khung tháo gỡ #4149 | Địa chỉ PC: 0x18db20 | Địa chỉ FDE: 0x1f3bf0 | Kích thước: 256 bytes
//   0x18db20: D10183FF  sub      sp, sp, #0x60
//   0x18db24: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x18db28: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x18db2c: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_4149_0x18db20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18db20ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x1f3bf0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4150 | PC: 0x18dd34 | FDE: 0x1f3a90 | Size: 172 bytes [_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_]
// Khung tháo gỡ #4150 | Địa chỉ PC: 0x18dd34 | Địa chỉ FDE: 0x1f3a90 | Kích thước: 172 bytes
//   0x18dd34: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x18dd38: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x18dd3c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x18dd40: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_4150_0x18dd34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18dd34ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f3a90ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #4151 | PC: 0x18dde0 | FDE: 0x1f3ab8 | Size: 256 bytes [_ZNSt6__ndk112__deque_baseINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEE5clearEv]
// Khung tháo gỡ #4151 | Địa chỉ PC: 0x18dde0 | Địa chỉ FDE: 0x1f3ab8 | Kích thước: 256 bytes
//   0x18dde0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x18dde4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x18dde8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x18ddec: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_4151_0x18dde0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18dde0ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f3ab8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4152 | PC: 0x18df24 | FDE: 0x1f3c20 | Size: 256 bytes [_ZNSt6__ndk15dequeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEE19__add_back_capacityEv]
// Khung tháo gỡ #4152 | Địa chỉ PC: 0x18df24 | Địa chỉ FDE: 0x1f3c20 | Kích thước: 256 bytes
//   0x18df24: D101C3FF  sub      sp, sp, #0x70
//   0x18df28: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x18df2c: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x18df30: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_4152_0x18df24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18df24ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x1f3c20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4153 | PC: 0x18e11c | FDE: 0x1f3ae0 | Size: 256 bytes
// Khung tháo gỡ #4153 | Địa chỉ PC: 0x18e11c | Địa chỉ FDE: 0x1f3ae0 | Kích thước: 256 bytes
//   0x18e11c: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x18e120: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x18e124: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x18e128: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_4153_0x18e11c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18e11cULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1f3ae0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4154 | PC: 0x18e27c | FDE: 0x1f3b08 | Size: 256 bytes [_ZNSt6__ndk114__split_bufferIPNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS7_EEE9push_backEOS7_]
// Khung tháo gỡ #4154 | Địa chỉ PC: 0x18e27c | Địa chỉ FDE: 0x1f3b08 | Kích thước: 256 bytes
//   0x18e27c: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x18e280: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x18e284: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x18e288: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_4154_0x18e27c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18e27cULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1f3b08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4155 | PC: 0x18e3dc | FDE: 0x1f3b30 | Size: 256 bytes [_ZNSt6__ndk114__split_bufferIPNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS7_EEE10push_frontEOS7_]
// Khung tháo gỡ #4155 | Địa chỉ PC: 0x18e3dc | Địa chỉ FDE: 0x1f3b30 | Kích thước: 256 bytes
//   0x18e3dc: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x18e3e0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x18e3e4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x18e3e8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_4155_0x18e3dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18e3dcULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f3b30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4156 | PC: 0x18e538 | FDE: 0x1f3b58 | Size: 256 bytes [_ZNSt6__ndk114__split_bufferIPNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS4_IS7_EEE9push_backEOS7_]
// Khung tháo gỡ #4156 | Địa chỉ PC: 0x18e538 | Địa chỉ FDE: 0x1f3b58 | Kích thước: 256 bytes
//   0x18e538: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x18e53c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x18e540: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x18e544: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_4156_0x18e538(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18e538ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1f3b58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4157 | PC: 0x18e698 | FDE: 0x1f3b80 | Size: 256 bytes [_ZNSt6__ndk114__split_bufferIPNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS4_IS7_EEE10push_frontERKS7_]
// Khung tháo gỡ #4157 | Địa chỉ PC: 0x18e698 | Địa chỉ FDE: 0x1f3b80 | Kích thước: 256 bytes
//   0x18e698: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x18e69c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x18e6a0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x18e6a4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_4157_0x18e698(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18e698ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f3b80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4158 | PC: 0x18e7f4 | FDE: 0x1f3c50 | Size: 12 bytes [PyInit__sre]
// Khung tháo gỡ #4158 | Địa chỉ PC: 0x18e7f4 | Địa chỉ FDE: 0x1f3c50 | Kích thước: 12 bytes
//   0x18e7f4: 900004A0  adrp     x0, #0x222000
//   0x18e7f8: 912DC000  add      x0, x0, #0xb70
//   0x18e7fc: 17FB2889  b        #0x58a20
static inline uint64_t fde_func_4158_0x18e7f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18e7f4ULL ^ (static_cast<uint64_t>(0x900004a0ULL) << 13);
    acc = (acc + a1 + 0x912dc000ULL) ^ 0x1f3c50ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #4159 | PC: 0x18e800 | FDE: 0x1f3c68 | Size: 108 bytes
// Khung tháo gỡ #4159 | Địa chỉ PC: 0x18e800 | Địa chỉ FDE: 0x1f3c68 | Kích thước: 108 bytes
//   0x18e800: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x18e804: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x18e808: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x18e80c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_4159_0x18e800(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18e800ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f3c68ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #4160 | PC: 0x18e86c | FDE: 0x1f3c88 | Size: 148 bytes
// Khung tháo gỡ #4160 | Địa chỉ PC: 0x18e86c | Địa chỉ FDE: 0x1f3c88 | Kích thước: 148 bytes
//   0x18e86c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x18e870: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18e874: 910043FD  add      x29, sp, #0x10
//   0x18e878: F9401013  ldr      x19, [x0, #0x20]
static inline uint64_t fde_func_4160_0x18e86c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18e86cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f3c88ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #4161 | PC: 0x18e900 | FDE: 0x1f3ca8 | Size: 152 bytes
// Khung tháo gỡ #4161 | Địa chỉ PC: 0x18e900 | Địa chỉ FDE: 0x1f3ca8 | Kích thước: 152 bytes
//   0x18e900: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x18e904: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18e908: 910043FD  add      x29, sp, #0x10
//   0x18e90c: F9401013  ldr      x19, [x0, #0x20]
static inline uint64_t fde_func_4161_0x18e900(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18e900ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f3ca8ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #4162 | PC: 0x18e998 | FDE: 0x1f3cc8 | Size: 256 bytes
// Khung tháo gỡ #4162 | Địa chỉ PC: 0x18e998 | Địa chỉ FDE: 0x1f3cc8 | Kích thước: 256 bytes
//   0x18e998: D10583FF  sub      sp, sp, #0x160
//   0x18e99c: A9106FFC  stp      x28, x27, [sp, #0x100]
//   0x18e9a0: A91167FA  stp      x26, x25, [sp, #0x110]
//   0x18e9a4: A9125FF8  stp      x24, x23, [sp, #0x120]
static inline uint64_t fde_func_4162_0x18e998(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18e998ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xa9106ffcULL) ^ 0x1f3cc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4163 | PC: 0x18ed1c | FDE: 0x1f3cf8 | Size: 8 bytes
// Khung tháo gỡ #4163 | Địa chỉ PC: 0x18ed1c | Địa chỉ FDE: 0x1f3cf8 | Kích thước: 8 bytes
//   0x18ed1c: 52800080  mov      w0, #4
//   0x18ed20: 17FB2E94  b        #0x5a770
static inline uint64_t fde_func_4163_0x18ed1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18ed1cULL ^ (static_cast<uint64_t>(0x52800080ULL) << 13);
    acc = (acc + a1 + 0x17fb2e94ULL) ^ 0x1f3cf8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #4164 | PC: 0x18ed24 | FDE: 0x1f3d10 | Size: 100 bytes
// Khung tháo gỡ #4164 | Địa chỉ PC: 0x18ed24 | Địa chỉ FDE: 0x1f3d10 | Kích thước: 100 bytes
//   0x18ed24: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x18ed28: 910003FD  mov      x29, sp
//   0x18ed2c: AA0103E0  mov      x0, x1
//   0x18ed30: 97FB38E4  bl       #0x5d0c0
static inline uint64_t fde_func_4164_0x18ed24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18ed24ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f3d10ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #4165 | PC: 0x18ed88 | FDE: 0x1f3d30 | Size: 108 bytes
// Khung tháo gỡ #4165 | Địa chỉ PC: 0x18ed88 | Địa chỉ FDE: 0x1f3d30 | Kích thước: 108 bytes
//   0x18ed88: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x18ed8c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18ed90: 910043FD  add      x29, sp, #0x10
//   0x18ed94: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_4165_0x18ed88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18ed88ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f3d30ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #4166 | PC: 0x18edf4 | FDE: 0x1f3d50 | Size: 96 bytes
// Khung tháo gỡ #4166 | Địa chỉ PC: 0x18edf4 | Địa chỉ FDE: 0x1f3d50 | Kích thước: 96 bytes
//   0x18edf4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x18edf8: 910003FD  mov      x29, sp
//   0x18edfc: AA0103E0  mov      x0, x1
//   0x18ee00: 97FB38B0  bl       #0x5d0c0
static inline uint64_t fde_func_4166_0x18edf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18edf4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f3d50ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #4167 | PC: 0x18ee54 | FDE: 0x1f3d70 | Size: 100 bytes
// Khung tháo gỡ #4167 | Địa chỉ PC: 0x18ee54 | Địa chỉ FDE: 0x1f3d70 | Kích thước: 100 bytes
//   0x18ee54: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x18ee58: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18ee5c: 910043FD  add      x29, sp, #0x10
//   0x18ee60: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_4167_0x18ee54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18ee54ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f3d70ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #4168 | PC: 0x18eeb8 | FDE: 0x1f3d90 | Size: 256 bytes
// Khung tháo gỡ #4168 | Địa chỉ PC: 0x18eeb8 | Địa chỉ FDE: 0x1f3d90 | Kích thước: 256 bytes
//   0x18eeb8: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x18eebc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x18eec0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x18eec4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_4168_0x18eeb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18eeb8ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f3d90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4169 | PC: 0x18efd0 | FDE: 0x1f3db8 | Size: 256 bytes
// Khung tháo gỡ #4169 | Địa chỉ PC: 0x18efd0 | Địa chỉ FDE: 0x1f3db8 | Kích thước: 256 bytes
//   0x18efd0: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x18efd4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x18efd8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x18efdc: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_4169_0x18efd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18efd0ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1f3db8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4170 | PC: 0x18f4d0 | FDE: 0x1f3de8 | Size: 256 bytes
// Khung tháo gỡ #4170 | Địa chỉ PC: 0x18f4d0 | Địa chỉ FDE: 0x1f3de8 | Kích thước: 256 bytes
//   0x18f4d0: EB01001F  cmp      x0, x1
//   0x18f4d4: 540007C2  b.hs     #0x18f5cc
//   0x18f4d8: B00001C9  adrp     x9, #0x1c8000
//   0x18f4dc: 912A9129  add      x9, x9, #0xaa4
static inline uint64_t fde_func_4170_0x18f4d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18f4d0ULL ^ (static_cast<uint64_t>(0xeb01001fULL) << 13);
    acc = (acc + a1 + 0x540007c2ULL) ^ 0x1f3de8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4171 | PC: 0x18f5e0 | FDE: 0x1f3e00 | Size: 256 bytes
// Khung tháo gỡ #4171 | Địa chỉ PC: 0x18f5e0 | Địa chỉ FDE: 0x1f3e00 | Kích thước: 256 bytes
//   0x18f5e0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x18f5e4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x18f5e8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x18f5ec: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_4171_0x18f5e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18f5e0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f3e00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4172 | PC: 0x18f73c | FDE: 0x1f3e20 | Size: 212 bytes
// Khung tháo gỡ #4172 | Địa chỉ PC: 0x18f73c | Địa chỉ FDE: 0x1f3e20 | Kích thước: 212 bytes
//   0x18f73c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x18f740: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18f744: 910043FD  add      x29, sp, #0x10
//   0x18f748: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_4172_0x18f73c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18f73cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f3e20ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #4173 | PC: 0x18f810 | FDE: 0x1f3e40 | Size: 256 bytes
// Khung tháo gỡ #4173 | Địa chỉ PC: 0x18f810 | Địa chỉ FDE: 0x1f3e40 | Kích thước: 256 bytes
//   0x18f810: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x18f814: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x18f818: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x18f81c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_4173_0x18f810(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18f810ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1f3e40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4174 | PC: 0x18f9ec | FDE: 0x1f3e70 | Size: 104 bytes
// Khung tháo gỡ #4174 | Địa chỉ PC: 0x18f9ec | Địa chỉ FDE: 0x1f3e70 | Kích thước: 104 bytes
//   0x18f9ec: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x18f9f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18f9f4: 910043FD  add      x29, sp, #0x10
//   0x18f9f8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_4174_0x18f9ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18f9ecULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f3e70ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #4175 | PC: 0x18fa54 | FDE: 0x1f3e90 | Size: 256 bytes
// Khung tháo gỡ #4175 | Địa chỉ PC: 0x18fa54 | Địa chỉ FDE: 0x1f3e90 | Kích thước: 256 bytes
//   0x18fa54: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x18fa58: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x18fa5c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x18fa60: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_4175_0x18fa54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18fa54ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f3e90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4176 | PC: 0x18fb58 | FDE: 0x1f3eb0 | Size: 128 bytes
// Khung tháo gỡ #4176 | Địa chỉ PC: 0x18fb58 | Địa chỉ FDE: 0x1f3eb0 | Kích thước: 128 bytes
//   0x18fb58: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x18fb5c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x18fb60: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x18fb64: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_4176_0x18fb58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18fb58ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f3eb0ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #4177 | PC: 0x18fbd8 | FDE: 0x1f3ed0 | Size: 148 bytes
// Khung tháo gỡ #4177 | Địa chỉ PC: 0x18fbd8 | Địa chỉ FDE: 0x1f3ed0 | Kích thước: 148 bytes
//   0x18fbd8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x18fbdc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18fbe0: 910043FD  add      x29, sp, #0x10
//   0x18fbe4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_4177_0x18fbd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18fbd8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f3ed0ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #4178 | PC: 0x18fc6c | FDE: 0x1f3ef0 | Size: 256 bytes
// Khung tháo gỡ #4178 | Địa chỉ PC: 0x18fc6c | Địa chỉ FDE: 0x1f3ef0 | Kích thước: 256 bytes
//   0x18fc6c: D10603FF  sub      sp, sp, #0x180
//   0x18fc70: F9009BFC  str      x28, [sp, #0x130]
//   0x18fc74: A9145FF8  stp      x24, x23, [sp, #0x140]
//   0x18fc78: A91557F6  stp      x22, x21, [sp, #0x150]
static inline uint64_t fde_func_4178_0x18fc6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18fc6cULL ^ (static_cast<uint64_t>(0xd10603ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x1f3ef0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4179 | PC: 0x18fe64 | FDE: 0x1f3f18 | Size: 256 bytes
// Khung tháo gỡ #4179 | Địa chỉ PC: 0x18fe64 | Địa chỉ FDE: 0x1f3f18 | Kích thước: 256 bytes
//   0x18fe64: D10603FF  sub      sp, sp, #0x180
//   0x18fe68: F9009BFC  str      x28, [sp, #0x130]
//   0x18fe6c: A9145FF8  stp      x24, x23, [sp, #0x140]
//   0x18fe70: A91557F6  stp      x22, x21, [sp, #0x150]
static inline uint64_t fde_func_4179_0x18fe64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18fe64ULL ^ (static_cast<uint64_t>(0xd10603ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x1f3f18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4180 | PC: 0x190064 | FDE: 0x1f3f40 | Size: 256 bytes
// Khung tháo gỡ #4180 | Địa chỉ PC: 0x190064 | Địa chỉ FDE: 0x1f3f40 | Kích thước: 256 bytes
//   0x190064: D10603FF  sub      sp, sp, #0x180
//   0x190068: F9009BFC  str      x28, [sp, #0x130]
//   0x19006c: A9145FF8  stp      x24, x23, [sp, #0x140]
//   0x190070: A91557F6  stp      x22, x21, [sp, #0x150]
static inline uint64_t fde_func_4180_0x190064(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x190064ULL ^ (static_cast<uint64_t>(0xd10603ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x1f3f40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4181 | PC: 0x190228 | FDE: 0x1f3f68 | Size: 224 bytes
// Khung tháo gỡ #4181 | Địa chỉ PC: 0x190228 | Địa chỉ FDE: 0x1f3f68 | Kích thước: 224 bytes
//   0x190228: D10283FF  sub      sp, sp, #0xa0
//   0x19022c: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x190230: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x190234: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_4181_0x190228(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x190228ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1f3f68ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #4182 | PC: 0x190308 | FDE: 0x1f3f90 | Size: 224 bytes
// Khung tháo gỡ #4182 | Địa chỉ PC: 0x190308 | Địa chỉ FDE: 0x1f3f90 | Kích thước: 224 bytes
//   0x190308: D10283FF  sub      sp, sp, #0xa0
//   0x19030c: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x190310: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x190314: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_4182_0x190308(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x190308ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1f3f90ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #4183 | PC: 0x1903e8 | FDE: 0x1f3fb8 | Size: 256 bytes
// Khung tháo gỡ #4183 | Địa chỉ PC: 0x1903e8 | Địa chỉ FDE: 0x1f3fb8 | Kích thước: 256 bytes
//   0x1903e8: D10703FF  sub      sp, sp, #0x1c0
//   0x1903ec: A9166FFC  stp      x28, x27, [sp, #0x160]
//   0x1903f0: A91767FA  stp      x26, x25, [sp, #0x170]
//   0x1903f4: A9185FF8  stp      x24, x23, [sp, #0x180]
static inline uint64_t fde_func_4183_0x1903e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1903e8ULL ^ (static_cast<uint64_t>(0xd10703ffULL) << 13);
    acc = (acc + a1 + 0xa9166ffcULL) ^ 0x1f3fb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4184 | PC: 0x190a14 | FDE: 0x1f3fe8 | Size: 256 bytes
// Khung tháo gỡ #4184 | Địa chỉ PC: 0x190a14 | Địa chỉ FDE: 0x1f3fe8 | Kích thước: 256 bytes
//   0x190a14: D10703FF  sub      sp, sp, #0x1c0
//   0x190a18: A9166FFC  stp      x28, x27, [sp, #0x160]
//   0x190a1c: A91767FA  stp      x26, x25, [sp, #0x170]
//   0x190a20: A9185FF8  stp      x24, x23, [sp, #0x180]
static inline uint64_t fde_func_4184_0x190a14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x190a14ULL ^ (static_cast<uint64_t>(0xd10703ffULL) << 13);
    acc = (acc + a1 + 0xa9166ffcULL) ^ 0x1f3fe8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4185 | PC: 0x190ff0 | FDE: 0x1f4018 | Size: 256 bytes
// Khung tháo gỡ #4185 | Địa chỉ PC: 0x190ff0 | Địa chỉ FDE: 0x1f4018 | Kích thước: 256 bytes
//   0x190ff0: D10283FF  sub      sp, sp, #0xa0
//   0x190ff4: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x190ff8: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x190ffc: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_4185_0x190ff0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x190ff0ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1f4018ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4186 | PC: 0x191188 | FDE: 0x1f4040 | Size: 256 bytes
// Khung tháo gỡ #4186 | Địa chỉ PC: 0x191188 | Địa chỉ FDE: 0x1f4040 | Kích thước: 256 bytes
//   0x191188: D10283FF  sub      sp, sp, #0xa0
//   0x19118c: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x191190: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x191194: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_4186_0x191188(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x191188ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1f4040ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4187 | PC: 0x1912b8 | FDE: 0x1f4068 | Size: 16 bytes
// Khung tháo gỡ #4187 | Địa chỉ PC: 0x1912b8 | Địa chỉ FDE: 0x1f4068 | Kích thước: 16 bytes
//   0x1912b8: F9400008  ldr      x8, [x0]
//   0x1912bc: 91000508  add      x8, x8, #1
//   0x1912c0: F9000008  str      x8, [x0]
//   0x1912c4: D65F03C0  ret      
static inline uint64_t fde_func_4187_0x1912b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1912b8ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0x91000508ULL) ^ 0x1f4068ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #4188 | PC: 0x1912c8 | FDE: 0x1f4080 | Size: 16 bytes
// Khung tháo gỡ #4188 | Địa chỉ PC: 0x1912c8 | Địa chỉ FDE: 0x1f4080 | Kích thước: 16 bytes
//   0x1912c8: F9400008  ldr      x8, [x0]
//   0x1912cc: 91000508  add      x8, x8, #1
//   0x1912d0: F9000008  str      x8, [x0]
//   0x1912d4: D65F03C0  ret      
static inline uint64_t fde_func_4188_0x1912c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1912c8ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0x91000508ULL) ^ 0x1f4080ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #4189 | PC: 0x1912d8 | FDE: 0x1f4098 | Size: 256 bytes
// Khung tháo gỡ #4189 | Địa chỉ PC: 0x1912d8 | Địa chỉ FDE: 0x1f4098 | Kích thước: 256 bytes
//   0x1912d8: D10143FF  sub      sp, sp, #0x50
//   0x1912dc: F9000BF7  str      x23, [sp, #0x10]
//   0x1912e0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x1912e4: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_4189_0x1912d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1912d8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x1f4098ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4190 | PC: 0x191460 | FDE: 0x1f40c0 | Size: 256 bytes
// Khung tháo gỡ #4190 | Địa chỉ PC: 0x191460 | Địa chỉ FDE: 0x1f40c0 | Kích thước: 256 bytes
//   0x191460: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x191464: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x191468: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x19146c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_4190_0x191460(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x191460ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f40c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4191 | PC: 0x191620 | FDE: 0x1f40e0 | Size: 256 bytes
// Khung tháo gỡ #4191 | Địa chỉ PC: 0x191620 | Địa chỉ FDE: 0x1f40e0 | Kích thước: 256 bytes
//   0x191620: D10243FF  sub      sp, sp, #0x90
//   0x191624: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x191628: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x19162c: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_4191_0x191620(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x191620ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x1f40e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4192 | PC: 0x1937b8 | FDE: 0x1f4110 | Size: 256 bytes
// Khung tháo gỡ #4192 | Địa chỉ PC: 0x1937b8 | Địa chỉ FDE: 0x1f4110 | Kích thước: 256 bytes
//   0x1937b8: D10203FF  sub      sp, sp, #0x80
//   0x1937bc: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x1937c0: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x1937c4: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_4192_0x1937b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1937b8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1f4110ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4193 | PC: 0x1957e4 | FDE: 0x1f4140 | Size: 256 bytes
// Khung tháo gỡ #4193 | Địa chỉ PC: 0x1957e4 | Địa chỉ FDE: 0x1f4140 | Kích thước: 256 bytes
//   0x1957e4: D10243FF  sub      sp, sp, #0x90
//   0x1957e8: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x1957ec: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x1957f0: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_4193_0x1957e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1957e4ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x1f4140ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4194 | PC: 0x1977f8 | FDE: 0x1f4170 | Size: 256 bytes
// Khung tháo gỡ #4194 | Địa chỉ PC: 0x1977f8 | Địa chỉ FDE: 0x1f4170 | Kích thước: 256 bytes
//   0x1977f8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1977fc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x197800: 910043FD  add      x29, sp, #0x10
//   0x197804: 7100441F  cmp      w0, #0x11
static inline uint64_t fde_func_4194_0x1977f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1977f8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f4170ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4195 | PC: 0x197a68 | FDE: 0x1f4190 | Size: 256 bytes
// Khung tháo gỡ #4195 | Địa chỉ PC: 0x197a68 | Địa chỉ FDE: 0x1f4190 | Kích thước: 256 bytes
//   0x197a68: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x197a6c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x197a70: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x197a74: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_4195_0x197a68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x197a68ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1f4190ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4196 | PC: 0x197bec | FDE: 0x1f41c0 | Size: 256 bytes
// Khung tháo gỡ #4196 | Địa chỉ PC: 0x197bec | Địa chỉ FDE: 0x1f41c0 | Kích thước: 256 bytes
//   0x197bec: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x197bf0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x197bf4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x197bf8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_4196_0x197bec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x197becULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f41c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4197 | PC: 0x197ec4 | FDE: 0x1f41e8 | Size: 256 bytes
// Khung tháo gỡ #4197 | Địa chỉ PC: 0x197ec4 | Địa chỉ FDE: 0x1f41e8 | Kích thước: 256 bytes
//   0x197ec4: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x197ec8: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x197ecc: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x197ed0: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_4197_0x197ec4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x197ec4ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1f41e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4198 | PC: 0x198048 | FDE: 0x1f4218 | Size: 256 bytes
// Khung tháo gỡ #4198 | Địa chỉ PC: 0x198048 | Địa chỉ FDE: 0x1f4218 | Kích thước: 256 bytes
//   0x198048: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x19804c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x198050: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x198054: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_4198_0x198048(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x198048ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f4218ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4199 | PC: 0x198390 | FDE: 0x1f4240 | Size: 256 bytes
// Khung tháo gỡ #4199 | Địa chỉ PC: 0x198390 | Địa chỉ FDE: 0x1f4240 | Kích thước: 256 bytes
//   0x198390: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x198394: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x198398: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x19839c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_4199_0x198390(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x198390ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1f4240ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4200 | PC: 0x198514 | FDE: 0x1f4270 | Size: 256 bytes
// Khung tháo gỡ #4200 | Địa chỉ PC: 0x198514 | Địa chỉ FDE: 0x1f4270 | Kích thước: 256 bytes
//   0x198514: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x198518: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x19851c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x198520: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_4200_0x198514(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x198514ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f4270ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4201 | PC: 0x198848 | FDE: 0x1f4298 | Size: 256 bytes
// Khung tháo gỡ #4201 | Địa chỉ PC: 0x198848 | Địa chỉ FDE: 0x1f4298 | Kích thước: 256 bytes
//   0x198848: D101C3FF  sub      sp, sp, #0x70
//   0x19884c: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x198850: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x198854: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_4201_0x198848(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x198848ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x1f4298ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4202 | PC: 0x19916c | FDE: 0x1f42c8 | Size: 256 bytes
// Khung tháo gỡ #4202 | Địa chỉ PC: 0x19916c | Địa chỉ FDE: 0x1f42c8 | Kích thước: 256 bytes
//   0x19916c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x199170: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x199174: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x199178: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_4202_0x19916c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19916cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1f42c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4203 | PC: 0x199934 | FDE: 0x1f42f8 | Size: 232 bytes
// Khung tháo gỡ #4203 | Địa chỉ PC: 0x199934 | Địa chỉ FDE: 0x1f42f8 | Kích thước: 232 bytes
//   0x199934: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x199938: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x19993c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x199940: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_4203_0x199934(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x199934ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f42f8ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #4204 | PC: 0x199a1c | FDE: 0x1f4320 | Size: 16 bytes
// Khung tháo gỡ #4204 | Địa chỉ PC: 0x199a1c | Địa chỉ FDE: 0x1f4320 | Kích thước: 16 bytes
//   0x199a1c: F9401000  ldr      x0, [x0, #0x20]
//   0x199a20: B4000040  cbz      x0, #0x199a28
//   0x199a24: 17FAFBB3  b        #0x588f0
//   0x199a28: 17FB094A  b        #0x5bf50
static inline uint64_t fde_func_4204_0x199a1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x199a1cULL ^ (static_cast<uint64_t>(0xf9401000ULL) << 13);
    acc = (acc + a1 + 0xb4000040ULL) ^ 0x1f4320ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #4205 | PC: 0x199a2c | FDE: 0x1f4338 | Size: 196 bytes
// Khung tháo gỡ #4205 | Địa chỉ PC: 0x199a2c | Địa chỉ FDE: 0x1f4338 | Kích thước: 196 bytes
//   0x199a2c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x199a30: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x199a34: 910043FD  add      x29, sp, #0x10
//   0x199a38: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_4205_0x199a2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x199a2cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f4338ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #4206 | PC: 0x199af0 | FDE: 0x1f4358 | Size: 120 bytes
// Khung tháo gỡ #4206 | Địa chỉ PC: 0x199af0 | Địa chỉ FDE: 0x1f4358 | Kích thước: 120 bytes
//   0x199af0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x199af4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x199af8: 910043FD  add      x29, sp, #0x10
//   0x199afc: D0000322  adrp     x2, #0x1ff000
static inline uint64_t fde_func_4206_0x199af0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x199af0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f4358ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #4207 | PC: 0x199b68 | FDE: 0x1f4378 | Size: 128 bytes
// Khung tháo gỡ #4207 | Địa chỉ PC: 0x199b68 | Địa chỉ FDE: 0x1f4378 | Kích thước: 128 bytes
//   0x199b68: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x199b6c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x199b70: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x199b74: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_4207_0x199b68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x199b68ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f4378ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #4208 | PC: 0x199be8 | FDE: 0x1f4398 | Size: 148 bytes
// Khung tháo gỡ #4208 | Địa chỉ PC: 0x199be8 | Địa chỉ FDE: 0x1f4398 | Kích thước: 148 bytes
//   0x199be8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x199bec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x199bf0: 910043FD  add      x29, sp, #0x10
//   0x199bf4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_4208_0x199be8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x199be8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f4398ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #4209 | PC: 0x199c7c | FDE: 0x1f43b8 | Size: 68 bytes
// Khung tháo gỡ #4209 | Địa chỉ PC: 0x199c7c | Địa chỉ FDE: 0x1f43b8 | Kích thước: 68 bytes
//   0x199c7c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x199c80: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x199c84: 910043FD  add      x29, sp, #0x10
//   0x199c88: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_4209_0x199c7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x199c7cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f43b8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #4210 | PC: 0x199cc0 | FDE: 0x1f43d8 | Size: 256 bytes
// Khung tháo gỡ #4210 | Địa chỉ PC: 0x199cc0 | Địa chỉ FDE: 0x1f43d8 | Kích thước: 256 bytes
//   0x199cc0: D102C3FF  sub      sp, sp, #0xb0
//   0x199cc4: F9003BF7  str      x23, [sp, #0x70]
//   0x199cc8: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x199ccc: A9094FF4  stp      x20, x19, [sp, #0x90]
static inline uint64_t fde_func_4210_0x199cc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x199cc0ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf7ULL) ^ 0x1f43d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4211 | PC: 0x199e10 | FDE: 0x1f4400 | Size: 256 bytes
// Khung tháo gỡ #4211 | Địa chỉ PC: 0x199e10 | Địa chỉ FDE: 0x1f4400 | Kích thước: 256 bytes
//   0x199e10: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x199e14: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x199e18: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x199e1c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_4211_0x199e10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x199e10ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f4400ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4212 | PC: 0x199f30 | FDE: 0x1f4428 | Size: 160 bytes
// Khung tháo gỡ #4212 | Địa chỉ PC: 0x199f30 | Địa chỉ FDE: 0x1f4428 | Kích thước: 160 bytes
//   0x199f30: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x199f34: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x199f38: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x199f3c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_4212_0x199f30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x199f30ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f4428ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #4213 | PC: 0x199fd0 | FDE: 0x1f4448 | Size: 168 bytes
// Khung tháo gỡ #4213 | Địa chỉ PC: 0x199fd0 | Địa chỉ FDE: 0x1f4448 | Kích thước: 168 bytes
//   0x199fd0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x199fd4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x199fd8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x199fdc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_4213_0x199fd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x199fd0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f4448ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #4214 | PC: 0x19a078 | FDE: 0x1f4468 | Size: 220 bytes
// Khung tháo gỡ #4214 | Địa chỉ PC: 0x19a078 | Địa chỉ FDE: 0x1f4468 | Kích thước: 220 bytes
//   0x19a078: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x19a07c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x19a080: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x19a084: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_4214_0x19a078(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19a078ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f4468ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #4215 | PC: 0x19a154 | FDE: 0x1f4488 | Size: 256 bytes
// Khung tháo gỡ #4215 | Địa chỉ PC: 0x19a154 | Địa chỉ FDE: 0x1f4488 | Kích thước: 256 bytes
//   0x19a154: D10283FF  sub      sp, sp, #0xa0
//   0x19a158: F90033F7  str      x23, [sp, #0x60]
//   0x19a15c: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x19a160: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_4215_0x19a154(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19a154ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90033f7ULL) ^ 0x1f4488ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4216 | PC: 0x19a2a8 | FDE: 0x1f44b0 | Size: 256 bytes
// Khung tháo gỡ #4216 | Địa chỉ PC: 0x19a2a8 | Địa chỉ FDE: 0x1f44b0 | Kích thước: 256 bytes
//   0x19a2a8: D10303FF  sub      sp, sp, #0xc0
//   0x19a2ac: F90043F7  str      x23, [sp, #0x80]
//   0x19a2b0: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x19a2b4: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_4216_0x19a2a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19a2a8ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf90043f7ULL) ^ 0x1f44b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4217 | PC: 0x19a488 | FDE: 0x1f44d8 | Size: 204 bytes
// Khung tháo gỡ #4217 | Địa chỉ PC: 0x19a488 | Địa chỉ FDE: 0x1f44d8 | Kích thước: 204 bytes
//   0x19a488: D10203FF  sub      sp, sp, #0x80
//   0x19a48c: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x19a490: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x19a494: 9101C3FD  add      x29, sp, #0x70
static inline uint64_t fde_func_4217_0x19a488(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19a488ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9064ff4ULL) ^ 0x1f44d8ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #4218 | PC: 0x19a554 | FDE: 0x1f44f8 | Size: 16 bytes
// Khung tháo gỡ #4218 | Địa chỉ PC: 0x19a554 | Địa chỉ FDE: 0x1f44f8 | Kích thước: 16 bytes
//   0x19a554: F9400008  ldr      x8, [x0]
//   0x19a558: 91000508  add      x8, x8, #1
//   0x19a55c: F9000008  str      x8, [x0]
//   0x19a560: D65F03C0  ret      
static inline uint64_t fde_func_4218_0x19a554(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19a554ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0x91000508ULL) ^ 0x1f44f8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #4219 | PC: 0x19a564 | FDE: 0x1f4510 | Size: 16 bytes
// Khung tháo gỡ #4219 | Địa chỉ PC: 0x19a564 | Địa chỉ FDE: 0x1f4510 | Kích thước: 16 bytes
//   0x19a564: F9400008  ldr      x8, [x0]
//   0x19a568: 91000508  add      x8, x8, #1
//   0x19a56c: F9000008  str      x8, [x0]
//   0x19a570: D65F03C0  ret      
static inline uint64_t fde_func_4219_0x19a564(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19a564ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0x91000508ULL) ^ 0x1f4510ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #4220 | PC: 0x19a574 | FDE: 0x1f4528 | Size: 168 bytes
// Khung tháo gỡ #4220 | Địa chỉ PC: 0x19a574 | Địa chỉ FDE: 0x1f4528 | Kích thước: 168 bytes
//   0x19a574: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x19a578: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x19a57c: 910043FD  add      x29, sp, #0x10
//   0x19a580: B40001C1  cbz      x1, #0x19a5b8
static inline uint64_t fde_func_4220_0x19a574(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19a574ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f4528ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #4221 | PC: 0x19a61c | FDE: 0x1f4548 | Size: 36 bytes
// Khung tháo gỡ #4221 | Địa chỉ PC: 0x19a61c | Địa chỉ FDE: 0x1f4548 | Kích thước: 36 bytes
//   0x19a61c: F9402000  ldr      x0, [x0, #0x40]
//   0x19a620: B7F80040  tbnz     x0, #0x3f, #0x19a628
//   0x19a624: 17FB0017  b        #0x5a680
//   0x19a628: B0000320  adrp     x0, #0x1ff000
static inline uint64_t fde_func_4221_0x19a61c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19a61cULL ^ (static_cast<uint64_t>(0xf9402000ULL) << 13);
    acc = (acc + a1 + 0xb7f80040ULL) ^ 0x1f4548ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #4222 | PC: 0x19a640 | FDE: 0x1f4560 | Size: 68 bytes
// Khung tháo gỡ #4222 | Địa chỉ PC: 0x19a640 | Địa chỉ FDE: 0x1f4560 | Kích thước: 68 bytes
//   0x19a640: F9401408  ldr      x8, [x0, #0x28]
//   0x19a644: F9401508  ldr      x8, [x8, #0x28]
//   0x19a648: B4000128  cbz      x8, #0x19a66c
//   0x19a64c: F9402009  ldr      x9, [x0, #0x40]
static inline uint64_t fde_func_4222_0x19a640(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19a640ULL ^ (static_cast<uint64_t>(0xf9401408ULL) << 13);
    acc = (acc + a1 + 0xf9401508ULL) ^ 0x1f4560ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #4223 | PC: 0x19a684 | FDE: 0x1f4578 | Size: 256 bytes
// Khung tháo gỡ #4223 | Địa chỉ PC: 0x19a684 | Địa chỉ FDE: 0x1f4578 | Kích thước: 256 bytes
//   0x19a684: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x19a688: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x19a68c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x19a690: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_4223_0x19a684(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19a684ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1f4578ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4224 | PC: 0x19a798 | FDE: 0x1f45a0 | Size: 200 bytes
// Khung tháo gỡ #4224 | Địa chỉ PC: 0x19a798 | Địa chỉ FDE: 0x1f45a0 | Kích thước: 200 bytes
//   0x19a798: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x19a79c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x19a7a0: 910043FD  add      x29, sp, #0x10
//   0x19a7a4: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_4224_0x19a798(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19a798ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f45a0ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #4225 | PC: 0x19a860 | FDE: 0x1f45c0 | Size: 88 bytes
// Khung tháo gỡ #4225 | Địa chỉ PC: 0x19a860 | Địa chỉ FDE: 0x1f45c0 | Kích thước: 88 bytes
//   0x19a860: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x19a864: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x19a868: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x19a86c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_4225_0x19a860(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19a860ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f45c0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #4226 | PC: 0x19a8b8 | FDE: 0x1f45e0 | Size: 56 bytes
// Khung tháo gỡ #4226 | Địa chỉ PC: 0x19a8b8 | Địa chỉ FDE: 0x1f45e0 | Kích thước: 56 bytes
//   0x19a8b8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x19a8bc: 910003FD  mov      x29, sp
//   0x19a8c0: AA0003E8  mov      x8, x0
//   0x19a8c4: F9400800  ldr      x0, [x0, #0x10]
static inline uint64_t fde_func_4226_0x19a8b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19a8b8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f45e0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #4227 | PC: 0x19a8f0 | FDE: 0x1f4600 | Size: 256 bytes
// Khung tháo gỡ #4227 | Địa chỉ PC: 0x19a8f0 | Địa chỉ FDE: 0x1f4600 | Kích thước: 256 bytes
//   0x19a8f0: D10243FF  sub      sp, sp, #0x90
//   0x19a8f4: F9002BF7  str      x23, [sp, #0x50]
//   0x19a8f8: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x19a8fc: A9074FF4  stp      x20, x19, [sp, #0x70]
static inline uint64_t fde_func_4227_0x19a8f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19a8f0ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf7ULL) ^ 0x1f4600ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4228 | PC: 0x19aa64 | FDE: 0x1f4628 | Size: 256 bytes
// Khung tháo gỡ #4228 | Địa chỉ PC: 0x19aa64 | Địa chỉ FDE: 0x1f4628 | Kích thước: 256 bytes
//   0x19aa64: D10243FF  sub      sp, sp, #0x90
//   0x19aa68: F9002BF7  str      x23, [sp, #0x50]
//   0x19aa6c: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x19aa70: A9074FF4  stp      x20, x19, [sp, #0x70]
static inline uint64_t fde_func_4228_0x19aa64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19aa64ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf7ULL) ^ 0x1f4628ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4229 | PC: 0x19abb8 | FDE: 0x1f4650 | Size: 256 bytes [analyze_descriptor]
// Khung tháo gỡ #4229 | Địa chỉ PC: 0x19abb8 | Địa chỉ FDE: 0x1f4650 | Kích thước: 256 bytes
//   0x19abb8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x19abbc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x19abc0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x19abc4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_4229_0x19abb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19abb8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f4650ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4230 | PC: 0x19ad18 | FDE: 0x1f4670 | Size: 256 bytes [specialize_dict_access]
// Khung tháo gỡ #4230 | Địa chỉ PC: 0x19ad18 | Địa chỉ FDE: 0x1f4670 | Kích thước: 256 bytes
//   0x19ad18: D10143FF  sub      sp, sp, #0x50
//   0x19ad1c: F9000BF7  str      x23, [sp, #0x10]
//   0x19ad20: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x19ad24: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_4230_0x19ad18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19ad18ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x1f4670ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4231 | PC: 0x19ae5c | FDE: 0x1f4698 | Size: 8 bytes [specialize_module_load_attr]
// Khung tháo gỡ #4231 | Địa chỉ PC: 0x19ae5c | Địa chỉ FDE: 0x1f4698 | Kích thước: 8 bytes
//   0x19ae5c: 12800000  mov      w0, #-1
//   0x19ae60: D65F03C0  ret      
static inline uint64_t fde_func_4231_0x19ae5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19ae5cULL ^ (static_cast<uint64_t>(0x12800000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1f4698ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #4232 | PC: 0x19ae64 | FDE: 0x1f46b0 | Size: 256 bytes [drogon_setup_load_method_cache]
// Khung tháo gỡ #4232 | Địa chỉ PC: 0x19ae64 | Địa chỉ FDE: 0x1f46b0 | Kích thước: 256 bytes
//   0x19ae64: D10183FF  sub      sp, sp, #0x60
//   0x19ae68: F90013F7  str      x23, [sp, #0x20]
//   0x19ae6c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x19ae70: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_4232_0x19ae64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19ae64ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1f46b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4233 | PC: 0x19b01c | FDE: 0x1f46d8 | Size: 256 bytes [drogon_load_method_from_cache]
// Khung tháo gỡ #4233 | Địa chỉ PC: 0x19b01c | Địa chỉ FDE: 0x1f46d8 | Kích thước: 256 bytes
//   0x19b01c: B9401889  ldr      w9, [x4, #0x18]
//   0x19b020: F9400408  ldr      x8, [x0, #8]
//   0x19b024: 71000D3F  cmp      w9, #3
//   0x19b028: 540002A0  b.eq     #0x19b07c
static inline uint64_t fde_func_4233_0x19b01c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19b01cULL ^ (static_cast<uint64_t>(0xb9401889ULL) << 13);
    acc = (acc + a1 + 0xf9400408ULL) ^ 0x1f46d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4234 | PC: 0x19b138 | FDE: 0x1f46f0 | Size: 256 bytes [drogon_load_attr_from_cache]
// Khung tháo gỡ #4234 | Địa chỉ PC: 0x19b138 | Địa chỉ FDE: 0x1f46f0 | Kích thước: 256 bytes
//   0x19b138: F9400408  ldr      x8, [x0, #8]
//   0x19b13c: F900005F  str      xzr, [x2]
//   0x19b140: B9401869  ldr      w9, [x3, #0x18]
//   0x19b144: 7100153F  cmp      w9, #5
static inline uint64_t fde_func_4234_0x19b138(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19b138ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xf900005fULL) ^ 0x1f46f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4235 | PC: 0x19b328 | FDE: 0x1f4708 | Size: 256 bytes [drogon_setup_load_attr_cache]
// Khung tháo gỡ #4235 | Địa chỉ PC: 0x19b328 | Địa chỉ FDE: 0x1f4708 | Kích thước: 256 bytes
//   0x19b328: D10103FF  sub      sp, sp, #0x40
//   0x19b32c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x19b330: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x19b334: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_4235_0x19b328(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19b328ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f4708ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4236 | PC: 0x19b454 | FDE: 0x1f4730 | Size: 256 bytes [drogon_store_attr_from_cache]
// Khung tháo gỡ #4236 | Địa chỉ PC: 0x19b454 | Địa chỉ FDE: 0x1f4730 | Kích thước: 256 bytes
//   0x19b454: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x19b458: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x19b45c: 910043FD  add      x29, sp, #0x10
//   0x19b460: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_4236_0x19b454(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19b454ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f4730ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4237 | PC: 0x19b648 | FDE: 0x1f4750 | Size: 16 bytes [drogon_setup_store_attr_cache]
// Khung tháo gỡ #4237 | Địa chỉ PC: 0x19b648 | Địa chỉ FDE: 0x1f4750 | Kích thước: 16 bytes
//   0x19b648: 12800008  mov      w8, #-1
//   0x19b64c: 2A1F03E0  mov      w0, wzr
//   0x19b650: B9000068  str      w8, [x3]
//   0x19b654: D65F03C0  ret      
static inline uint64_t fde_func_4237_0x19b648(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19b648ULL ^ (static_cast<uint64_t>(0x12800008ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e0ULL) ^ 0x1f4750ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #4238 | PC: 0x19b658 | FDE: 0x1f4768 | Size: 136 bytes [drogon_setup_store_subscr_cache]
// Khung tháo gỡ #4238 | Địa chỉ PC: 0x19b658 | Địa chỉ FDE: 0x1f4768 | Kích thước: 136 bytes
//   0x19b658: 90000329  adrp     x9, #0x1ff000
//   0x19b65c: F9400408  ldr      x8, [x0, #8]
//   0x19b660: F947ED29  ldr      x9, [x9, #0xfd8]
//   0x19b664: EB09011F  cmp      x8, x9
static inline uint64_t fde_func_4238_0x19b658(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19b658ULL ^ (static_cast<uint64_t>(0x90000329ULL) << 13);
    acc = (acc + a1 + 0xf9400408ULL) ^ 0x1f4768ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #4239 | PC: 0x19b6e0 | FDE: 0x1f4780 | Size: 148 bytes [drogon_setup_binary_subscr_cache]
// Khung tháo gỡ #4239 | Địa chỉ PC: 0x19b6e0 | Địa chỉ FDE: 0x1f4780 | Kích thước: 148 bytes
//   0x19b6e0: 90000329  adrp     x9, #0x1ff000
//   0x19b6e4: F9400408  ldr      x8, [x0, #8]
//   0x19b6e8: F947ED29  ldr      x9, [x9, #0xfd8]
//   0x19b6ec: EB09011F  cmp      x8, x9
static inline uint64_t fde_func_4239_0x19b6e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19b6e0ULL ^ (static_cast<uint64_t>(0x90000329ULL) << 13);
    acc = (acc + a1 + 0xf9400408ULL) ^ 0x1f4780ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #4240 | PC: 0x19b774 | FDE: 0x1f4798 | Size: 12 bytes [PyInit__sha512]
// Khung tháo gỡ #4240 | Địa chỉ PC: 0x19b774 | Địa chỉ FDE: 0x1f4798 | Kích thước: 12 bytes
//   0x19b774: 90000440  adrp     x0, #0x223000
//   0x19b778: 91146000  add      x0, x0, #0x518
//   0x19b77c: 17FAF4A9  b        #0x58a20
static inline uint64_t fde_func_4240_0x19b774(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19b774ULL ^ (static_cast<uint64_t>(0x90000440ULL) << 13);
    acc = (acc + a1 + 0x91146000ULL) ^ 0x1f4798ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #4241 | PC: 0x19b780 | FDE: 0x1f47b0 | Size: 92 bytes
// Khung tháo gỡ #4241 | Địa chỉ PC: 0x19b780 | Địa chỉ FDE: 0x1f47b0 | Kích thước: 92 bytes
//   0x19b780: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x19b784: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x19b788: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x19b78c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_4241_0x19b780(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19b780ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1f47b0ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #4242 | PC: 0x19b7dc | FDE: 0x1f47d0 | Size: 112 bytes
// Khung tháo gỡ #4242 | Địa chỉ PC: 0x19b7dc | Địa chỉ FDE: 0x1f47d0 | Kích thước: 112 bytes
//   0x19b7dc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x19b7e0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x19b7e4: 910043FD  add      x29, sp, #0x10
//   0x19b7e8: 97FAF9A6  bl       #0x59e80
static inline uint64_t fde_func_4242_0x19b7dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19b7dcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f47d0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #4243 | PC: 0x19b84c | FDE: 0x1f47f0 | Size: 112 bytes
// Khung tháo gỡ #4243 | Địa chỉ PC: 0x19b84c | Địa chỉ FDE: 0x1f47f0 | Kích thước: 112 bytes
//   0x19b84c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x19b850: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x19b854: 910043FD  add      x29, sp, #0x10
//   0x19b858: 97FAF98A  bl       #0x59e80
static inline uint64_t fde_func_4243_0x19b84c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19b84cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f47f0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #4244 | PC: 0x19b8bc | FDE: 0x1f4810 | Size: 256 bytes
// Khung tháo gỡ #4244 | Địa chỉ PC: 0x19b8bc | Địa chỉ FDE: 0x1f4810 | Kích thước: 256 bytes
//   0x19b8bc: D10283FF  sub      sp, sp, #0xa0
//   0x19b8c0: F9003BF5  str      x21, [sp, #0x70]
//   0x19b8c4: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x19b8c8: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_4244_0x19b8bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19b8bcULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf5ULL) ^ 0x1f4810ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4245 | PC: 0x19bac4 | FDE: 0x1f4830 | Size: 256 bytes
// Khung tháo gỡ #4245 | Địa chỉ PC: 0x19bac4 | Địa chỉ FDE: 0x1f4830 | Kích thước: 256 bytes
//   0x19bac4: D10283FF  sub      sp, sp, #0xa0
//   0x19bac8: F9003BF5  str      x21, [sp, #0x70]
//   0x19bacc: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x19bad0: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_4245_0x19bac4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19bac4ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf5ULL) ^ 0x1f4830ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4246 | PC: 0x19bccc | FDE: 0x1f4850 | Size: 256 bytes
// Khung tháo gỡ #4246 | Địa chỉ PC: 0x19bccc | Địa chỉ FDE: 0x1f4850 | Kích thước: 256 bytes
//   0x19bccc: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x19bcd0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x19bcd4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x19bcd8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_4246_0x19bccc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19bcccULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f4850ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4247 | PC: 0x19bdd0 | FDE: 0x1f4878 | Size: 256 bytes
// Khung tháo gỡ #4247 | Địa chỉ PC: 0x19bdd0 | Địa chỉ FDE: 0x1f4878 | Kích thước: 256 bytes
//   0x19bdd0: F81E0FFC  str      x28, [sp, #-0x20]!
//   0x19bdd4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x19bdd8: 910043FD  add      x29, sp, #0x10
//   0x19bddc: D53BD048  mrs      x8, tpidr_el0
static inline uint64_t fde_func_4247_0x19bdd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19bdd0ULL ^ (static_cast<uint64_t>(0xf81e0ffcULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f4878ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4248 | PC: 0x19e0b0 | FDE: 0x1f4898 | Size: 216 bytes
// Khung tháo gỡ #4248 | Địa chỉ PC: 0x19e0b0 | Địa chỉ FDE: 0x1f4898 | Kích thước: 216 bytes
//   0x19e0b0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x19e0b4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x19e0b8: 910043FD  add      x29, sp, #0x10
//   0x19e0bc: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_4248_0x19e0b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19e0b0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f4898ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #4249 | PC: 0x19e188 | FDE: 0x1f48b8 | Size: 76 bytes
// Khung tháo gỡ #4249 | Địa chỉ PC: 0x19e188 | Địa chỉ FDE: 0x1f48b8 | Kích thước: 76 bytes
//   0x19e188: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x19e18c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x19e190: 910043FD  add      x29, sp, #0x10
//   0x19e194: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_4249_0x19e188(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19e188ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f48b8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #4250 | PC: 0x19e1d4 | FDE: 0x1f48d8 | Size: 52 bytes
// Khung tháo gỡ #4250 | Địa chỉ PC: 0x19e1d4 | Địa chỉ FDE: 0x1f48d8 | Kích thước: 52 bytes
//   0x19e1d4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x19e1d8: 910003FD  mov      x29, sp
//   0x19e1dc: F9400400  ldr      x0, [x0, #8]
//   0x19e1e0: B40000E0  cbz      x0, #0x19e1fc
static inline uint64_t fde_func_4250_0x19e1d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19e1d4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f48d8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #4251 | PC: 0x19e208 | FDE: 0x1f48f8 | Size: 220 bytes
// Khung tháo gỡ #4251 | Địa chỉ PC: 0x19e208 | Địa chỉ FDE: 0x1f48f8 | Kích thước: 220 bytes
//   0x19e208: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x19e20c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x19e210: 910043FD  add      x29, sp, #0x10
//   0x19e214: AA0303E8  mov      x8, x3
static inline uint64_t fde_func_4251_0x19e208(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19e208ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1f48f8ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #4252 | PC: 0x19e2e4 | FDE: 0x1f4918 | Size: 204 bytes
// Khung tháo gỡ #4252 | Địa chỉ PC: 0x19e2e4 | Địa chỉ FDE: 0x1f4918 | Kích thước: 204 bytes
//   0x19e2e4: D10583FF  sub      sp, sp, #0x160
//   0x19e2e8: F9009BFC  str      x28, [sp, #0x130]
//   0x19e2ec: A9144FF4  stp      x20, x19, [sp, #0x140]
//   0x19e2f0: A9157BFD  stp      x29, x30, [sp, #0x150]
static inline uint64_t fde_func_4252_0x19e2e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19e2e4ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x1f4918ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #4253 | PC: 0x19e3b0 | FDE: 0x1f4938 | Size: 204 bytes
// Khung tháo gỡ #4253 | Địa chỉ PC: 0x19e3b0 | Địa chỉ FDE: 0x1f4938 | Kích thước: 204 bytes
//   0x19e3b0: D10583FF  sub      sp, sp, #0x160
//   0x19e3b4: F9009BFC  str      x28, [sp, #0x130]
//   0x19e3b8: A9144FF4  stp      x20, x19, [sp, #0x140]
//   0x19e3bc: A9157BFD  stp      x29, x30, [sp, #0x150]
static inline uint64_t fde_func_4253_0x19e3b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19e3b0ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x1f4938ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #4254 | PC: 0x19e47c | FDE: 0x1f4958 | Size: 256 bytes
// Khung tháo gỡ #4254 | Địa chỉ PC: 0x19e47c | Địa chỉ FDE: 0x1f4958 | Kích thước: 256 bytes
//   0x19e47c: D10243FF  sub      sp, sp, #0x90
//   0x19e480: F90033F5  str      x21, [sp, #0x60]
//   0x19e484: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x19e488: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_4254_0x19e47c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19e47cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90033f5ULL) ^ 0x1f4958ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4255 | PC: 0x19e58c | FDE: 0x1f4978 | Size: 256 bytes
// Khung tháo gỡ #4255 | Địa chỉ PC: 0x19e58c | Địa chỉ FDE: 0x1f4978 | Kích thước: 256 bytes
//   0x19e58c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x19e590: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x19e594: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x19e598: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_4255_0x19e58c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19e58cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1f4978ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4256 | PC: 0x19e8e4 | FDE: 0x1f49a0 | Size: 8 bytes
// Khung tháo gỡ #4256 | Địa chỉ PC: 0x19e8e4 | Địa chỉ FDE: 0x1f49a0 | Kích thước: 8 bytes
//   0x19e8e4: 52801000  mov      w0, #0x80
//   0x19e8e8: 17FAEFA2  b        #0x5a770
static inline uint64_t fde_func_4256_0x19e8e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19e8e4ULL ^ (static_cast<uint64_t>(0x52801000ULL) << 13);
    acc = (acc + a1 + 0x17faefa2ULL) ^ 0x1f49a0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #4257 | PC: 0x19e8ec | FDE: 0x1f49b8 | Size: 36 bytes
// Khung tháo gỡ #4257 | Địa chỉ PC: 0x19e8ec | Địa chỉ FDE: 0x1f49b8 | Kích thước: 36 bytes
//   0x19e8ec: B940DC08  ldr      w8, [x0, #0xdc]
//   0x19e8f0: F0000149  adrp     x9, #0x1c9000
//   0x19e8f4: F000014A  adrp     x10, #0x1c9000
//   0x19e8f8: 91113129  add      x9, x9, #0x44c
static inline uint64_t fde_func_4257_0x19e8ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19e8ecULL ^ (static_cast<uint64_t>(0xb940dc08ULL) << 13);
    acc = (acc + a1 + 0xf0000149ULL) ^ 0x1f49b8ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #4258 | PC: 0x19e910 | FDE: 0x1f49e8 | Size: 40 bytes
// Khung tháo gỡ #4258 | Địa chỉ PC: 0x19e910 | Địa chỉ FDE: 0x1f49e8 | Kích thước: 40 bytes
//   0x19e910: D2800002  mov      x2, #0
//   0x19e914: 52800003  mov      w3, #0
//   0x19e918: 38401405  ldrb     w5, [x0], #1
//   0x19e91c: 924018A4  and      x4, x5, #0x7f
static inline uint64_t fde_func_4258_0x19e910(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19e910ULL ^ (static_cast<uint64_t>(0xd2800002ULL) << 13);
    acc = (acc + a1 + 0x52800003ULL) ^ 0x1f49e8ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #4259 | PC: 0x19e938 | FDE: 0x1f4a00 | Size: 64 bytes
// Khung tháo gỡ #4259 | Địa chỉ PC: 0x19e938 | Địa chỉ FDE: 0x1f4a00 | Kích thước: 64 bytes
//   0x19e938: D2800002  mov      x2, #0
//   0x19e93c: 52800003  mov      w3, #0
//   0x19e940: 38401404  ldrb     w4, [x0], #1
//   0x19e944: 92401885  and      x5, x4, #0x7f
static inline uint64_t fde_func_4259_0x19e938(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19e938ULL ^ (static_cast<uint64_t>(0xd2800002ULL) << 13);
    acc = (acc + a1 + 0x52800003ULL) ^ 0x1f4a00ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #4260 | PC: 0x19e978 | FDE: 0x1f4a18 | Size: 240 bytes
// Khung tháo gỡ #4260 | Địa chỉ PC: 0x19e978 | Địa chỉ FDE: 0x1f4a18 | Kích thước: 240 bytes
//   0x19e978: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x19e97c: 910003FD  mov      x29, sp
//   0x19e980: A90153F3  stp      x19, x20, [sp, #0x10]
//   0x19e984: 53001C14  uxtb     w20, w0
static inline uint64_t fde_func_4260_0x19e978(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19e978ULL ^ (static_cast<uint64_t>(0xa9bc7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f4a18ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #4261 | PC: 0x19ea68 | FDE: 0x1f4a50 | Size: 256 bytes
// Khung tháo gỡ #4261 | Địa chỉ PC: 0x19ea68 | Địa chỉ FDE: 0x1f4a50 | Kích thước: 256 bytes
//   0x19ea68: 90000442  adrp     x2, #0x226000
//   0x19ea6c: 52800100  mov      w0, #8
//   0x19ea70: 913B4041  add      x1, x2, #0xed0
//   0x19ea74: 393B4040  strb     w0, [x2, #0xed0]
static inline uint64_t fde_func_4261_0x19ea68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19ea68ULL ^ (static_cast<uint64_t>(0x90000442ULL) << 13);
    acc = (acc + a1 + 0x52800100ULL) ^ 0x1f4a50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4262 | PC: 0x19eb7c | FDE: 0x1f4a68 | Size: 60 bytes
// Khung tháo gỡ #4262 | Địa chỉ PC: 0x19eb7c | Địa chỉ FDE: 0x1f4a68 | Kích thước: 60 bytes
//   0x19eb7c: 90000443  adrp     x3, #0x226000
//   0x19eb80: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x19eb84: 910003FD  mov      x29, sp
//   0x19eb88: 397BBC63  ldrb     w3, [x3, #0xeef]
static inline uint64_t fde_func_4262_0x19eb7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19eb7cULL ^ (static_cast<uint64_t>(0x90000443ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x1f4a68ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #4263 | PC: 0x19ebb8 | FDE: 0x1f4a90 | Size: 88 bytes
// Khung tháo gỡ #4263 | Địa chỉ PC: 0x19ebb8 | Địa chỉ FDE: 0x1f4a90 | Kích thước: 88 bytes
//   0x19ebb8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x19ebbc: 7101843F  cmp      w1, #0x61
//   0x19ebc0: 910003FD  mov      x29, sp
//   0x19ebc4: 5400004D  b.le     #0x19ebcc
static inline uint64_t fde_func_4263_0x19ebb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19ebb8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x7101843fULL) ^ 0x1f4a90ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #4264 | PC: 0x19ec10 | FDE: 0x1f4ab8 | Size: 256 bytes
// Khung tháo gỡ #4264 | Địa chỉ PC: 0x19ec10 | Địa chỉ FDE: 0x1f4ab8 | Kích thước: 256 bytes
//   0x19ec10: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x19ec14: 910003FD  mov      x29, sp
//   0x19ec18: A9025BF5  stp      x21, x22, [sp, #0x20]
//   0x19ec1c: AA0003F5  mov      x21, x0
static inline uint64_t fde_func_4264_0x19ec10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19ec10ULL ^ (static_cast<uint64_t>(0xa9bc7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f4ab8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4265 | PC: 0x19ed1c | FDE: 0x1f4af0 | Size: 8 bytes
// Khung tháo gỡ #4265 | Địa chỉ PC: 0x19ed1c | Địa chỉ FDE: 0x1f4af0 | Kích thước: 8 bytes
//   0x19ed1c: F9418800  ldr      x0, [x0, #0x310]
//   0x19ed20: D65F03C0  ret      
static inline uint64_t fde_func_4265_0x19ed1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19ed1cULL ^ (static_cast<uint64_t>(0xf9418800ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1f4af0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #4266 | PC: 0x19ed24 | FDE: 0x1f4b08 | Size: 88 bytes
// Khung tháo gỡ #4266 | Địa chỉ PC: 0x19ed24 | Địa chỉ FDE: 0x1f4b08 | Kích thước: 88 bytes
//   0x19ed24: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x19ed28: 7101843F  cmp      w1, #0x61
//   0x19ed2c: 910003FD  mov      x29, sp
//   0x19ed30: 5400004D  b.le     #0x19ed38
static inline uint64_t fde_func_4266_0x19ed24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19ed24ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x7101843fULL) ^ 0x1f4b08ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #4267 | PC: 0x19ed7c | FDE: 0x1f4b30 | Size: 8 bytes
// Khung tháo gỡ #4267 | Địa chỉ PC: 0x19ed7c | Địa chỉ FDE: 0x1f4b30 | Kích thước: 8 bytes
//   0x19ed7c: F9418C00  ldr      x0, [x0, #0x318]
//   0x19ed80: D65F03C0  ret      
static inline uint64_t fde_func_4267_0x19ed7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19ed7cULL ^ (static_cast<uint64_t>(0xf9418c00ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1f4b30ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #4268 | PC: 0x19ed84 | FDE: 0x1f4b48 | Size: 20 bytes
// Khung tháo gỡ #4268 | Địa chỉ PC: 0x19ed84 | Địa chỉ FDE: 0x1f4b48 | Kích thước: 20 bytes
//   0x19ed84: F941A002  ldr      x2, [x0, #0x340]
//   0x19ed88: F9418C00  ldr      x0, [x0, #0x318]
//   0x19ed8c: D37FFC42  lsr      x2, x2, #0x3f
//   0x19ed90: B9000022  str      w2, [x1]
static inline uint64_t fde_func_4268_0x19ed84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19ed84ULL ^ (static_cast<uint64_t>(0xf941a002ULL) << 13);
    acc = (acc + a1 + 0xf9418c00ULL) ^ 0x1f4b48ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #4269 | PC: 0x19ed98 | FDE: 0x1f4b60 | Size: 8 bytes
// Khung tháo gỡ #4269 | Địa chỉ PC: 0x19ed98 | Địa chỉ FDE: 0x1f4b60 | Kích thước: 8 bytes
//   0x19ed98: F9018C01  str      x1, [x0, #0x318]
//   0x19ed9c: D65F03C0  ret      
static inline uint64_t fde_func_4269_0x19ed98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19ed98ULL ^ (static_cast<uint64_t>(0xf9018c01ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1f4b60ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #4270 | PC: 0x19eda0 | FDE: 0x1f4b78 | Size: 8 bytes
// Khung tháo gỡ #4270 | Địa chỉ PC: 0x19eda0 | Địa chỉ FDE: 0x1f4b78 | Kích thước: 8 bytes
//   0x19eda0: F9419000  ldr      x0, [x0, #0x320]
//   0x19eda4: D65F03C0  ret      
static inline uint64_t fde_func_4270_0x19eda0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19eda0ULL ^ (static_cast<uint64_t>(0xf9419000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1f4b78ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #4271 | PC: 0x19eda8 | FDE: 0x1f4b90 | Size: 8 bytes
// Khung tháo gỡ #4271 | Địa chỉ PC: 0x19eda8 | Địa chỉ FDE: 0x1f4b90 | Kích thước: 8 bytes
//   0x19eda8: F9419C00  ldr      x0, [x0, #0x338]
//   0x19edac: D65F03C0  ret      
static inline uint64_t fde_func_4271_0x19eda8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19eda8ULL ^ (static_cast<uint64_t>(0xf9419c00ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1f4b90ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #4272 | PC: 0x19edb0 | FDE: 0x1f4ba8 | Size: 40 bytes
// Khung tháo gỡ #4272 | Địa chỉ PC: 0x19edb0 | Địa chỉ FDE: 0x1f4ba8 | Kích thước: 40 bytes
//   0x19edb0: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x19edb4: D1000400  sub      x0, x0, #1
//   0x19edb8: 910003FD  mov      x29, sp
//   0x19edbc: 910063A1  add      x1, x29, #0x18
static inline uint64_t fde_func_4272_0x19edb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19edb0ULL ^ (static_cast<uint64_t>(0xa9bd7bfdULL) << 13);
    acc = (acc + a1 + 0xd1000400ULL) ^ 0x1f4ba8ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #4273 | PC: 0x19edd8 | FDE: 0x1f4bd0 | Size: 8 bytes
// Khung tháo gỡ #4273 | Địa chỉ PC: 0x19edd8 | Địa chỉ FDE: 0x1f4bd0 | Kích thước: 8 bytes
//   0x19edd8: F9419800  ldr      x0, [x0, #0x330]
//   0x19eddc: D65F03C0  ret      
static inline uint64_t fde_func_4273_0x19edd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19edd8ULL ^ (static_cast<uint64_t>(0xf9419800ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1f4bd0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #4274 | PC: 0x19ede0 | FDE: 0x1f4be8 | Size: 8 bytes
// Khung tháo gỡ #4274 | Địa chỉ PC: 0x19ede0 | Địa chỉ FDE: 0x1f4be8 | Kích thước: 8 bytes
//   0x19ede0: F9419400  ldr      x0, [x0, #0x328]
//   0x19ede4: D65F03C0  ret      
static inline uint64_t fde_func_4274_0x19ede0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19ede0ULL ^ (static_cast<uint64_t>(0xf9419400ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1f4be8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #4275 | PC: 0x19ede8 | FDE: 0x1f4c00 | Size: 120 bytes
// Khung tháo gỡ #4275 | Địa chỉ PC: 0x19ede8 | Địa chỉ FDE: 0x1f4c00 | Kích thước: 120 bytes
//   0x19ede8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x19edec: 53001C02  uxtb     w2, w0
//   0x19edf0: AA0103E0  mov      x0, x1
//   0x19edf4: 7103FC5F  cmp      w2, #0xff
static inline uint64_t fde_func_4275_0x19ede8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19ede8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x53001c02ULL) ^ 0x1f4c00ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #4276 | PC: 0x19ee60 | FDE: 0x1f4c40 | Size: 256 bytes
// Khung tháo gỡ #4276 | Địa chỉ PC: 0x19ee60 | Địa chỉ FDE: 0x1f4c40 | Kích thước: 256 bytes
//   0x19ee60: A9B77BFD  stp      x29, x30, [sp, #-0x90]!
//   0x19ee64: 910003FD  mov      x29, sp
//   0x19ee68: A9025BF5  stp      x21, x22, [sp, #0x20]
//   0x19ee6c: A90363F7  stp      x23, x24, [sp, #0x30]
static inline uint64_t fde_func_4276_0x19ee60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19ee60ULL ^ (static_cast<uint64_t>(0xa9b77bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f4c40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4277 | PC: 0x19f358 | FDE: 0x1f4c90 | Size: 256 bytes
// Khung tháo gỡ #4277 | Địa chỉ PC: 0x19f358 | Địa chỉ FDE: 0x1f4c90 | Kích thước: 256 bytes
//   0x19f358: A9B77BFD  stp      x29, x30, [sp, #-0x90]!
//   0x19f35c: D280D002  mov      x2, #0x680
//   0x19f360: 910003FD  mov      x29, sp
//   0x19f364: A90153F3  stp      x19, x20, [sp, #0x10]
static inline uint64_t fde_func_4277_0x19f358(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19f358ULL ^ (static_cast<uint64_t>(0xa9b77bfdULL) << 13);
    acc = (acc + a1 + 0xd280d002ULL) ^ 0x1f4c90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4278 | PC: 0x19f77c | FDE: 0x1f4cd8 | Size: 256 bytes
// Khung tháo gỡ #4278 | Địa chỉ PC: 0x19f77c | Địa chỉ FDE: 0x1f4cd8 | Kích thước: 256 bytes
//   0x19f77c: D108C3FF  sub      sp, sp, #0x230
//   0x19f780: AA0003E4  mov      x4, x0
//   0x19f784: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x19f788: 910003FD  mov      x29, sp
static inline uint64_t fde_func_4278_0x19f77c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19f77cULL ^ (static_cast<uint64_t>(0xd108c3ffULL) << 13);
    acc = (acc + a1 + 0xaa0003e4ULL) ^ 0x1f4cd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4279 | PC: 0x19fd30 | FDE: 0x1f4d30 | Size: 256 bytes
// Khung tháo gỡ #4279 | Địa chỉ PC: 0x19fd30 | Địa chỉ FDE: 0x1f4d30 | Kích thước: 256 bytes
//   0x19fd30: D10F83FF  sub      sp, sp, #0x3e0
//   0x19fd34: D2807802  mov      x2, #0x3c0
//   0x19fd38: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x19fd3c: 910003FD  mov      x29, sp
static inline uint64_t fde_func_4279_0x19fd30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19fd30ULL ^ (static_cast<uint64_t>(0xd10f83ffULL) << 13);
    acc = (acc + a1 + 0xd2807802ULL) ^ 0x1f4d30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4280 | PC: 0x19ff3c | FDE: 0x1f4d90 | Size: 220 bytes
// Khung tháo gỡ #4280 | Địa chỉ PC: 0x19ff3c | Địa chỉ FDE: 0x1f4d90 | Kích thước: 220 bytes
//   0x19ff3c: D11A43FF  sub      sp, sp, #0x690
//   0x19ff40: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x19ff44: 910003FD  mov      x29, sp
//   0x19ff48: A90153F3  stp      x19, x20, [sp, #0x10]
static inline uint64_t fde_func_4280_0x19ff3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19ff3cULL ^ (static_cast<uint64_t>(0xd11a43ffULL) << 13);
    acc = (acc + a1 + 0xa9bc7bfdULL) ^ 0x1f4d90ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #4281 | PC: 0x1a0018 | FDE: 0x1f4dd8 | Size: 76 bytes
// Khung tháo gỡ #4281 | Địa chỉ PC: 0x1a0018 | Địa chỉ FDE: 0x1f4dd8 | Kích thước: 76 bytes
//   0x1a0018: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x1a001c: 910003FD  mov      x29, sp
//   0x1a0020: A90153F3  stp      x19, x20, [sp, #0x10]
//   0x1a0024: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_4281_0x1a0018(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a0018ULL ^ (static_cast<uint64_t>(0xa9be7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f4dd8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #4282 | PC: 0x1a0064 | FDE: 0x1f4e08 | Size: 192 bytes
// Khung tháo gỡ #4282 | Địa chỉ PC: 0x1a0064 | Địa chỉ FDE: 0x1f4e08 | Kích thước: 192 bytes
//   0x1a0064: D11A03FF  sub      sp, sp, #0x680
//   0x1a0068: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x1a006c: 910003FD  mov      x29, sp
//   0x1a0070: A90153F3  stp      x19, x20, [sp, #0x10]
static inline uint64_t fde_func_4282_0x1a0064(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a0064ULL ^ (static_cast<uint64_t>(0xd11a03ffULL) << 13);
    acc = (acc + a1 + 0xa9bc7bfdULL) ^ 0x1f4e08ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #4283 | PC: 0x1a0124 | FDE: 0x1f4e58 | Size: 236 bytes
// Khung tháo gỡ #4283 | Địa chỉ PC: 0x1a0124 | Địa chỉ FDE: 0x1f4e58 | Kích thước: 236 bytes
//   0x1a0124: D11A03FF  sub      sp, sp, #0x680
//   0x1a0128: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x1a012c: 910003FD  mov      x29, sp
//   0x1a0130: A90363F7  stp      x23, x24, [sp, #0x30]
static inline uint64_t fde_func_4283_0x1a0124(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a0124ULL ^ (static_cast<uint64_t>(0xd11a03ffULL) << 13);
    acc = (acc + a1 + 0xa9bb7bfdULL) ^ 0x1f4e58ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #4284 | PC: 0x1a0210 | FDE: 0x1f4eb0 | Size: 244 bytes
// Khung tháo gỡ #4284 | Địa chỉ PC: 0x1a0210 | Địa chỉ FDE: 0x1f4eb0 | Kích thước: 244 bytes
//   0x1a0210: D12903FF  sub      sp, sp, #0xa40
//   0x1a0214: D2807802  mov      x2, #0x3c0
//   0x1a0218: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x1a021c: 910003FD  mov      x29, sp
static inline uint64_t fde_func_4284_0x1a0210(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a0210ULL ^ (static_cast<uint64_t>(0xd12903ffULL) << 13);
    acc = (acc + a1 + 0xd2807802ULL) ^ 0x1f4eb0ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #4285 | PC: 0x1a0304 | FDE: 0x1f4ef0 | Size: 4 bytes
// Khung tháo gỡ #4285 | Địa chỉ PC: 0x1a0304 | Địa chỉ FDE: 0x1f4ef0 | Kích thước: 4 bytes
//   0x1a0304: D65F03C0  ret      
static inline uint64_t fde_func_4285_0x1a0304(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a0304ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xd13843ffULL) ^ 0x1f4ef0ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #4286 | PC: 0x1a0308 | FDE: 0x1f4f08 | Size: 256 bytes
// Khung tháo gỡ #4286 | Địa chỉ PC: 0x1a0308 | Địa chỉ FDE: 0x1f4f08 | Kích thước: 256 bytes
//   0x1a0308: D13843FF  sub      sp, sp, #0xe10
//   0x1a030c: A9B47BFD  stp      x29, x30, [sp, #-0xc0]!
//   0x1a0310: 910003FD  mov      x29, sp
//   0x1a0314: A9045BF5  stp      x21, x22, [sp, #0x40]
static inline uint64_t fde_func_4286_0x1a0308(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a0308ULL ^ (static_cast<uint64_t>(0xd13843ffULL) << 13);
    acc = (acc + a1 + 0xa9b47bfdULL) ^ 0x1f4f08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4287 | PC: 0x1a0480 | FDE: 0x1f4fb0 | Size: 244 bytes
// Khung tháo gỡ #4287 | Địa chỉ PC: 0x1a0480 | Địa chỉ FDE: 0x1f4fb0 | Kích thước: 244 bytes
//   0x1a0480: D11E43FF  sub      sp, sp, #0x790
//   0x1a0484: A9B47BFD  stp      x29, x30, [sp, #-0xc0]!
//   0x1a0488: 910003FD  mov      x29, sp
//   0x1a048c: A90353F3  stp      x19, x20, [sp, #0x30]
static inline uint64_t fde_func_4287_0x1a0480(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a0480ULL ^ (static_cast<uint64_t>(0xd11e43ffULL) << 13);
    acc = (acc + a1 + 0xa9b47bfdULL) ^ 0x1f4fb0ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #4288 | PC: 0x1a0574 | FDE: 0x1f5058 | Size: 252 bytes
// Khung tháo gỡ #4288 | Địa chỉ PC: 0x1a0574 | Địa chỉ FDE: 0x1f5058 | Kích thước: 252 bytes
//   0x1a0574: D11E43FF  sub      sp, sp, #0x790
//   0x1a0578: A9B47BFD  stp      x29, x30, [sp, #-0xc0]!
//   0x1a057c: 910003FD  mov      x29, sp
//   0x1a0580: A90353F3  stp      x19, x20, [sp, #0x30]
static inline uint64_t fde_func_4288_0x1a0574(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a0574ULL ^ (static_cast<uint64_t>(0xd11e43ffULL) << 13);
    acc = (acc + a1 + 0xa9b47bfdULL) ^ 0x1f5058ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #4289 | PC: 0x1a0670 | FDE: 0x1f5100 | Size: 248 bytes
// Khung tháo gỡ #4289 | Địa chỉ PC: 0x1a0670 | Địa chỉ FDE: 0x1f5100 | Kích thước: 248 bytes
//   0x1a0670: D11E43FF  sub      sp, sp, #0x790
//   0x1a0674: A9B47BFD  stp      x29, x30, [sp, #-0xc0]!
//   0x1a0678: 910003FD  mov      x29, sp
//   0x1a067c: 6D0827E8  stp      d8, d9, [sp, #0x80]
static inline uint64_t fde_func_4289_0x1a0670(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a0670ULL ^ (static_cast<uint64_t>(0xd11e43ffULL) << 13);
    acc = (acc + a1 + 0xa9b47bfdULL) ^ 0x1f5100ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #4290 | PC: 0x1a0768 | FDE: 0x1f51a8 | Size: 36 bytes
// Khung tháo gỡ #4290 | Địa chỉ PC: 0x1a0768 | Địa chỉ FDE: 0x1f51a8 | Kích thước: 36 bytes
//   0x1a0768: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1a076c: 910003FD  mov      x29, sp
//   0x1a0770: F9400402  ldr      x2, [x0, #8]
//   0x1a0774: B4000082  cbz      x2, #0x1a0784
static inline uint64_t fde_func_4290_0x1a0768(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a0768ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f51a8ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #4291 | PC: 0x1a078c | FDE: 0x1f51d0 | Size: 208 bytes
// Khung tháo gỡ #4291 | Địa chỉ PC: 0x1a078c | Địa chỉ FDE: 0x1f51d0 | Kích thước: 208 bytes
//   0x1a078c: D12903FF  sub      sp, sp, #0xa40
//   0x1a0790: AA1E03E2  mov      x2, x30
//   0x1a0794: A9B67BFD  stp      x29, x30, [sp, #-0xa0]!
//   0x1a0798: 910003FD  mov      x29, sp
static inline uint64_t fde_func_4291_0x1a078c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a078cULL ^ (static_cast<uint64_t>(0xd12903ffULL) << 13);
    acc = (acc + a1 + 0xaa1e03e2ULL) ^ 0x1f51d0ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #4292 | PC: 0x1a085c | FDE: 0x1f5268 | Size: 40 bytes
// Khung tháo gỡ #4292 | Địa chỉ PC: 0x1a085c | Địa chỉ FDE: 0x1f5268 | Kích thước: 40 bytes
//   0x1a085c: D2800002  mov      x2, #0
//   0x1a0860: 52800003  mov      w3, #0
//   0x1a0864: 38401405  ldrb     w5, [x0], #1
//   0x1a0868: 924018A4  and      x4, x5, #0x7f
static inline uint64_t fde_func_4292_0x1a085c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a085cULL ^ (static_cast<uint64_t>(0xd2800002ULL) << 13);
    acc = (acc + a1 + 0x52800003ULL) ^ 0x1f5268ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #4293 | PC: 0x1a0884 | FDE: 0x1f5280 | Size: 64 bytes
// Khung tháo gỡ #4293 | Địa chỉ PC: 0x1a0884 | Địa chỉ FDE: 0x1f5280 | Kích thước: 64 bytes
//   0x1a0884: D2800002  mov      x2, #0
//   0x1a0888: 52800003  mov      w3, #0
//   0x1a088c: 38401404  ldrb     w4, [x0], #1
//   0x1a0890: 92401885  and      x5, x4, #0x7f
static inline uint64_t fde_func_4293_0x1a0884(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a0884ULL ^ (static_cast<uint64_t>(0xd2800002ULL) << 13);
    acc = (acc + a1 + 0x52800003ULL) ^ 0x1f5280ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #4294 | PC: 0x1a08c4 | FDE: 0x1f5298 | Size: 28 bytes
// Khung tháo gỡ #4294 | Địa chỉ PC: 0x1a08c4 | Địa chỉ FDE: 0x1f5298 | Kích thước: 28 bytes
//   0x1a08c4: F9400423  ldr      x3, [x1, #8]
//   0x1a08c8: F9400441  ldr      x1, [x2, #8]
//   0x1a08cc: EB01007F  cmp      x3, x1
//   0x1a08d0: 5A9F23E0  csetm    w0, lo
static inline uint64_t fde_func_4294_0x1a08c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a08c4ULL ^ (static_cast<uint64_t>(0xf9400423ULL) << 13);
    acc = (acc + a1 + 0xf9400441ULL) ^ 0x1f5298ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #4295 | PC: 0x1a08e0 | FDE: 0x1f52b0 | Size: 192 bytes
// Khung tháo gỡ #4295 | Địa chỉ PC: 0x1a08e0 | Địa chỉ FDE: 0x1f52b0 | Kích thước: 192 bytes
//   0x1a08e0: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x1a08e4: 910003FD  mov      x29, sp
//   0x1a08e8: A90153F3  stp      x19, x20, [sp, #0x10]
//   0x1a08ec: 531F7873  lsl      w19, w3, #1
static inline uint64_t fde_func_4295_0x1a08e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a08e0ULL ^ (static_cast<uint64_t>(0xa9ba7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f52b0ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #4296 | PC: 0x1a09a0 | FDE: 0x1f52f0 | Size: 180 bytes
// Khung tháo gỡ #4296 | Địa chỉ PC: 0x1a09a0 | Địa chỉ FDE: 0x1f52f0 | Kích thước: 180 bytes
//   0x1a09a0: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x1a09a4: 910003FD  mov      x29, sp
//   0x1a09a8: A90153F3  stp      x19, x20, [sp, #0x10]
//   0x1a09ac: F9400453  ldr      x19, [x2, #8]
static inline uint64_t fde_func_4296_0x1a09a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a09a0ULL ^ (static_cast<uint64_t>(0xa9bb7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f52f0ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #4297 | PC: 0x1a0a54 | FDE: 0x1f5330 | Size: 96 bytes
// Khung tháo gỡ #4297 | Địa chỉ PC: 0x1a0a54 | Địa chỉ FDE: 0x1f5330 | Kích thước: 96 bytes
//   0x1a0a54: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1a0a58: 53001C00  uxtb     w0, w0
//   0x1a0a5c: 7103FC1F  cmp      w0, #0xff
//   0x1a0a60: 910003FD  mov      x29, sp
static inline uint64_t fde_func_4297_0x1a0a54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a0a54ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x53001c00ULL) ^ 0x1f5330ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #4298 | PC: 0x1a0ab4 | FDE: 0x1f5358 | Size: 96 bytes
// Khung tháo gỡ #4298 | Địa chỉ PC: 0x1a0ab4 | Địa chỉ FDE: 0x1f5358 | Kích thước: 96 bytes
//   0x1a0ab4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1a0ab8: 53001C00  uxtb     w0, w0
//   0x1a0abc: 7103FC1F  cmp      w0, #0xff
//   0x1a0ac0: 910003FD  mov      x29, sp
static inline uint64_t fde_func_4298_0x1a0ab4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a0ab4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x53001c00ULL) ^ 0x1f5358ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #4299 | PC: 0x1a0b14 | FDE: 0x1f5380 | Size: 96 bytes
// Khung tháo gỡ #4299 | Địa chỉ PC: 0x1a0b14 | Địa chỉ FDE: 0x1f5380 | Kích thước: 96 bytes
//   0x1a0b14: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1a0b18: 53001C00  uxtb     w0, w0
//   0x1a0b1c: 7103FC1F  cmp      w0, #0xff
//   0x1a0b20: 910003FD  mov      x29, sp
static inline uint64_t fde_func_4299_0x1a0b14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a0b14ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x53001c00ULL) ^ 0x1f5380ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #4300 | PC: 0x1a0b74 | FDE: 0x1f53a8 | Size: 240 bytes
// Khung tháo gỡ #4300 | Địa chỉ PC: 0x1a0b74 | Địa chỉ FDE: 0x1f53a8 | Kích thước: 240 bytes
//   0x1a0b74: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x1a0b78: 910003FD  mov      x29, sp
//   0x1a0b7c: A90153F3  stp      x19, x20, [sp, #0x10]
//   0x1a0b80: 53001C14  uxtb     w20, w0
static inline uint64_t fde_func_4300_0x1a0b74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a0b74ULL ^ (static_cast<uint64_t>(0xa9bc7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f53a8ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #4301 | PC: 0x1a0c64 | FDE: 0x1f53e0 | Size: 144 bytes
// Khung tháo gỡ #4301 | Địa chỉ PC: 0x1a0c64 | Địa chỉ FDE: 0x1f53e0 | Kích thước: 144 bytes
//   0x1a0c64: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x1a0c68: 910003FD  mov      x29, sp
//   0x1a0c6c: A90153F3  stp      x19, x20, [sp, #0x10]
//   0x1a0c70: 79404013  ldrh     w19, [x0, #0x20]
static inline uint64_t fde_func_4301_0x1a0c64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a0c64ULL ^ (static_cast<uint64_t>(0xa9bb7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f53e0ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #4302 | PC: 0x1a0cf4 | FDE: 0x1f5418 | Size: 252 bytes
// Khung tháo gỡ #4302 | Địa chỉ PC: 0x1a0cf4 | Địa chỉ FDE: 0x1f5418 | Kích thước: 252 bytes
//   0x1a0cf4: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x1a0cf8: 910003FD  mov      x29, sp
//   0x1a0cfc: A90153F3  stp      x19, x20, [sp, #0x10]
//   0x1a0d00: 91002414  add      x20, x0, #9
static inline uint64_t fde_func_4302_0x1a0cf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a0cf4ULL ^ (static_cast<uint64_t>(0xa9bc7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f5418ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #4303 | PC: 0x1a0df0 | FDE: 0x1f5448 | Size: 256 bytes
// Khung tháo gỡ #4303 | Địa chỉ PC: 0x1a0df0 | Địa chỉ FDE: 0x1f5448 | Kích thước: 256 bytes
//   0x1a0df0: A9B97BFD  stp      x29, x30, [sp, #-0x70]!
//   0x1a0df4: 910003FD  mov      x29, sp
//   0x1a0df8: A9025BF5  stp      x21, x22, [sp, #0x20]
//   0x1a0dfc: AA0003F6  mov      x22, x0
static inline uint64_t fde_func_4303_0x1a0df0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a0df0ULL ^ (static_cast<uint64_t>(0xa9b97bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f5448ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4304 | PC: 0x1a0f50 | FDE: 0x1f5490 | Size: 16 bytes
// Khung tháo gỡ #4304 | Địa chỉ PC: 0x1a0f50 | Địa chỉ FDE: 0x1f5490 | Kích thước: 16 bytes
//   0x1a0f50: 91001001  add      x1, x0, #4
//   0x1a0f54: B9800400  ldrsw    x0, [x0, #4]
//   0x1a0f58: CB000020  sub      x0, x1, x0
//   0x1a0f5c: 17FFFF66  b        #0x1a0cf4
static inline uint64_t fde_func_4304_0x1a0f50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a0f50ULL ^ (static_cast<uint64_t>(0x91001001ULL) << 13);
    acc = (acc + a1 + 0xb9800400ULL) ^ 0x1f5490ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #4305 | PC: 0x1a0f60 | FDE: 0x1f54a8 | Size: 256 bytes
// Khung tháo gỡ #4305 | Địa chỉ PC: 0x1a0f60 | Địa chỉ FDE: 0x1f54a8 | Kích thước: 256 bytes
//   0x1a0f60: A9B77BFD  stp      x29, x30, [sp, #-0x90]!
//   0x1a0f64: F100BC3F  cmp      x1, #0x2f
//   0x1a0f68: 910003FD  mov      x29, sp
//   0x1a0f6c: A90153F3  stp      x19, x20, [sp, #0x10]
static inline uint64_t fde_func_4305_0x1a0f60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a0f60ULL ^ (static_cast<uint64_t>(0xa9b77bfdULL) << 13);
    acc = (acc + a1 + 0xf100bc3fULL) ^ 0x1f54a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4306 | PC: 0x1a137c | FDE: 0x1f54e8 | Size: 156 bytes
// Khung tháo gỡ #4306 | Địa chỉ PC: 0x1a137c | Địa chỉ FDE: 0x1f54e8 | Kích thước: 156 bytes
//   0x1a137c: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x1a1380: 910003FD  mov      x29, sp
//   0x1a1384: A9025BF5  stp      x21, x22, [sp, #0x20]
//   0x1a1388: AA0003F5  mov      x21, x0
static inline uint64_t fde_func_4306_0x1a137c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a137cULL ^ (static_cast<uint64_t>(0xa9bc7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f54e8ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #4307 | PC: 0x1a1418 | FDE: 0x1f5520 | Size: 256 bytes
// Khung tháo gỡ #4307 | Địa chỉ PC: 0x1a1418 | Địa chỉ FDE: 0x1f5520 | Kích thước: 256 bytes
//   0x1a1418: A9B97BFD  stp      x29, x30, [sp, #-0x70]!
//   0x1a141c: 910003FD  mov      x29, sp
//   0x1a1420: A90153F3  stp      x19, x20, [sp, #0x10]
//   0x1a1424: A90363F7  stp      x23, x24, [sp, #0x30]
static inline uint64_t fde_func_4307_0x1a1418(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a1418ULL ^ (static_cast<uint64_t>(0xa9b97bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f5520ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4308 | PC: 0x1a1578 | FDE: 0x1f5568 | Size: 256 bytes
// Khung tháo gỡ #4308 | Địa chỉ PC: 0x1a1578 | Địa chỉ FDE: 0x1f5568 | Kích thước: 256 bytes
//   0x1a1578: A9B97BFD  stp      x29, x30, [sp, #-0x70]!
//   0x1a157c: 910003FD  mov      x29, sp
//   0x1a1580: A9025BF5  stp      x21, x22, [sp, #0x20]
//   0x1a1584: AA0003F6  mov      x22, x0
static inline uint64_t fde_func_4308_0x1a1578(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a1578ULL ^ (static_cast<uint64_t>(0xa9b97bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f5568ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4309 | PC: 0x1a16ac | FDE: 0x1f55b0 | Size: 256 bytes
// Khung tháo gỡ #4309 | Địa chỉ PC: 0x1a16ac | Địa chỉ FDE: 0x1f55b0 | Kích thước: 256 bytes
//   0x1a16ac: A9B77BFD  stp      x29, x30, [sp, #-0x90]!
//   0x1a16b0: 910003FD  mov      x29, sp
//   0x1a16b4: A9025BF5  stp      x21, x22, [sp, #0x20]
//   0x1a16b8: AA0103F6  mov      x22, x1
static inline uint64_t fde_func_4309_0x1a16ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a16acULL ^ (static_cast<uint64_t>(0xa9b77bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f55b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4310 | PC: 0x1a1c1c | FDE: 0x1f5600 | Size: 156 bytes
// Khung tháo gỡ #4310 | Địa chỉ PC: 0x1a1c1c | Địa chỉ FDE: 0x1f5600 | Kích thước: 156 bytes
//   0x1a1c1c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x1a1c20: 910003FD  mov      x29, sp
//   0x1a1c24: A90153F3  stp      x19, x20, [sp, #0x10]
//   0x1a1c28: F90013F5  str      x21, [sp, #0x20]
static inline uint64_t fde_func_4310_0x1a1c1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a1c1cULL ^ (static_cast<uint64_t>(0xa9bd7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f5600ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #4311 | PC: 0x1a1cb8 | FDE: 0x1f5640 | Size: 12 bytes
// Khung tháo gỡ #4311 | Địa chỉ PC: 0x1a1cb8 | Địa chỉ FDE: 0x1f5640 | Kích thước: 12 bytes
//   0x1a1cb8: D2800002  mov      x2, #0
//   0x1a1cbc: D2800003  mov      x3, #0
//   0x1a1cc0: 17FFFFD7  b        #0x1a1c1c
static inline uint64_t fde_func_4311_0x1a1cb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a1cb8ULL ^ (static_cast<uint64_t>(0xd2800002ULL) << 13);
    acc = (acc + a1 + 0xd2800003ULL) ^ 0x1f5640ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #4312 | PC: 0x1a1cc4 | FDE: 0x1f5658 | Size: 64 bytes
// Khung tháo gỡ #4312 | Địa chỉ PC: 0x1a1cc4 | Địa chỉ FDE: 0x1f5658 | Kích thước: 64 bytes
//   0x1a1cc4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x1a1cc8: 910003FD  mov      x29, sp
//   0x1a1ccc: B9400001  ldr      w1, [x0]
//   0x1a1cd0: F9000BF3  str      x19, [sp, #0x10]
static inline uint64_t fde_func_4312_0x1a1cc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a1cc4ULL ^ (static_cast<uint64_t>(0xa9be7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f5658ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #4313 | PC: 0x1a1d04 | FDE: 0x1f5690 | Size: 148 bytes
// Khung tháo gỡ #4313 | Địa chỉ PC: 0x1a1d04 | Địa chỉ FDE: 0x1f5690 | Kích thước: 148 bytes
//   0x1a1d04: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x1a1d08: 92800004  mov      x4, #-1
//   0x1a1d0c: 910003FD  mov      x29, sp
//   0x1a1d10: A90153F3  stp      x19, x20, [sp, #0x10]
static inline uint64_t fde_func_4313_0x1a1d04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a1d04ULL ^ (static_cast<uint64_t>(0xa9bd7bfdULL) << 13);
    acc = (acc + a1 + 0x92800004ULL) ^ 0x1f5690ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #4314 | PC: 0x1a1d98 | FDE: 0x1f56c8 | Size: 12 bytes
// Khung tháo gỡ #4314 | Địa chỉ PC: 0x1a1d98 | Địa chỉ FDE: 0x1f56c8 | Kích thước: 12 bytes
//   0x1a1d98: D2800002  mov      x2, #0
//   0x1a1d9c: D2800003  mov      x3, #0
//   0x1a1da0: 17FFFFD9  b        #0x1a1d04
static inline uint64_t fde_func_4314_0x1a1d98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a1d98ULL ^ (static_cast<uint64_t>(0xd2800002ULL) << 13);
    acc = (acc + a1 + 0xd2800003ULL) ^ 0x1f56c8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #4315 | PC: 0x1a1da4 | FDE: 0x1f56e0 | Size: 44 bytes
// Khung tháo gỡ #4315 | Địa chỉ PC: 0x1a1da4 | Địa chỉ FDE: 0x1f56e0 | Kích thước: 44 bytes
//   0x1a1da4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x1a1da8: 910003FD  mov      x29, sp
//   0x1a1dac: F9000BF3  str      x19, [sp, #0x10]
//   0x1a1db0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_4315_0x1a1da4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a1da4ULL ^ (static_cast<uint64_t>(0xa9be7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f56e0ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #4316 | PC: 0x1a1dd0 | FDE: 0x1f5708 | Size: 256 bytes
// Khung tháo gỡ #4316 | Địa chỉ PC: 0x1a1dd0 | Địa chỉ FDE: 0x1f5708 | Kích thước: 256 bytes
//   0x1a1dd0: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x1a1dd4: 910003FD  mov      x29, sp
//   0x1a1dd8: A90153F3  stp      x19, x20, [sp, #0x10]
//   0x1a1ddc: A9025BF5  stp      x21, x22, [sp, #0x20]
static inline uint64_t fde_func_4316_0x1a1dd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a1dd0ULL ^ (static_cast<uint64_t>(0xa9bd7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f5708ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #4317 | PC: 0x1a1ed0 | FDE: 0x1f5738 | Size: 4 bytes
// Khung tháo gỡ #4317 | Địa chỉ PC: 0x1a1ed0 | Địa chỉ FDE: 0x1f5738 | Kích thước: 4 bytes
//   0x1a1ed0: 17FFFFC0  b        #0x1a1dd0
static inline uint64_t fde_func_4317_0x1a1ed0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a1ed0ULL ^ (static_cast<uint64_t>(0x17ffffc0ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x1f5738ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #4318 | PC: 0x1a1ed4 | FDE: 0x1f5750 | Size: 36 bytes
// Khung tháo gỡ #4318 | Địa chỉ PC: 0x1a1ed4 | Địa chỉ FDE: 0x1f5750 | Kích thước: 36 bytes
//   0x1a1ed4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1a1ed8: 910003FD  mov      x29, sp
//   0x1a1edc: B9400001  ldr      w1, [x0]
//   0x1a1ee0: 34000081  cbz      w1, #0x1a1ef0
static inline uint64_t fde_func_4318_0x1a1ed4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a1ed4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f5750ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #4319 | PC: 0x1a1ef8 | FDE: 0x1f5780 | Size: 256 bytes
// Khung tháo gỡ #4319 | Địa chỉ PC: 0x1a1ef8 | Địa chỉ FDE: 0x1f5780 | Kích thước: 256 bytes
//   0x1a1ef8: A9B87BFD  stp      x29, x30, [sp, #-0x80]!
//   0x1a1efc: 910003FD  mov      x29, sp
//   0x1a1f00: A9025BF5  stp      x21, x22, [sp, #0x20]
//   0x1a1f04: D00002F5  adrp     x21, #0x1ff000
static inline uint64_t fde_func_4319_0x1a1ef8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a1ef8ULL ^ (static_cast<uint64_t>(0xa9b87bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1f5780ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Shard 5 Dispatcher / Bộ điều phối phân mảnh 5
uint64_t execute_fde_shard_5(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 3856: return fde_func_3856_0x179850(a0, a1);
        case 3857: return fde_func_3857_0x1798a4(a0, a1);
        case 3858: return fde_func_3858_0x179b78(a0, a1);
        case 3859: return fde_func_3859_0x179bbc(a0, a1);
        case 3860: return fde_func_3860_0x179bc8(a0, a1);
        case 3861: return fde_func_3861_0x179cd4(a0, a1);
        case 3862: return fde_func_3862_0x179ec4(a0, a1);
        case 3863: return fde_func_3863_0x17a034(a0, a1);
        case 3864: return fde_func_3864_0x17a03c(a0, a1);
        case 3865: return fde_func_3865_0x17a0e8(a0, a1);
        case 3866: return fde_func_3866_0x17a15c(a0, a1);
        case 3867: return fde_func_3867_0x17a168(a0, a1);
        case 3868: return fde_func_3868_0x17a198(a0, a1);
        case 3869: return fde_func_3869_0x17a1c4(a0, a1);
        case 3870: return fde_func_3870_0x17a1ec(a0, a1);
        case 3871: return fde_func_3871_0x17a2d8(a0, a1);
        case 3872: return fde_func_3872_0x17a324(a0, a1);
        case 3873: return fde_func_3873_0x17b054(a0, a1);
        case 3874: return fde_func_3874_0x17b170(a0, a1);
        case 3875: return fde_func_3875_0x17b1dc(a0, a1);
        case 3876: return fde_func_3876_0x17b1e4(a0, a1);
        case 3877: return fde_func_3877_0x17b220(a0, a1);
        case 3878: return fde_func_3878_0x17b224(a0, a1);
        case 3879: return fde_func_3879_0x17b26c(a0, a1);
        case 3880: return fde_func_3880_0x17b2c4(a0, a1);
        case 3881: return fde_func_3881_0x17b320(a0, a1);
        case 3882: return fde_func_3882_0x17b3ac(a0, a1);
        case 3883: return fde_func_3883_0x17b464(a0, a1);
        case 3884: return fde_func_3884_0x17b4cc(a0, a1);
        case 3885: return fde_func_3885_0x17b53c(a0, a1);
        case 3886: return fde_func_3886_0x17b58c(a0, a1);
        case 3887: return fde_func_3887_0x17b5dc(a0, a1);
        case 3888: return fde_func_3888_0x17b784(a0, a1);
        case 3889: return fde_func_3889_0x17b868(a0, a1);
        case 3890: return fde_func_3890_0x17b9c4(a0, a1);
        case 3891: return fde_func_3891_0x17ba14(a0, a1);
        case 3892: return fde_func_3892_0x17bac0(a0, a1);
        case 3893: return fde_func_3893_0x17bb50(a0, a1);
        case 3894: return fde_func_3894_0x17bbac(a0, a1);
        case 3895: return fde_func_3895_0x17bbb8(a0, a1);
        case 3896: return fde_func_3896_0x17bbc4(a0, a1);
        case 3897: return fde_func_3897_0x17d640(a0, a1);
        case 3898: return fde_func_3898_0x17d700(a0, a1);
        case 3899: return fde_func_3899_0x17d870(a0, a1);
        case 3900: return fde_func_3900_0x17d9f4(a0, a1);
        case 3901: return fde_func_3901_0x17da00(a0, a1);
        case 3902: return fde_func_3902_0x17dab0(a0, a1);
        case 3903: return fde_func_3903_0x17db60(a0, a1);
        case 3904: return fde_func_3904_0x17dc10(a0, a1);
        case 3905: return fde_func_3905_0x17dcc0(a0, a1);
        case 3906: return fde_func_3906_0x17dd70(a0, a1);
        case 3907: return fde_func_3907_0x17dd90(a0, a1);
        case 3908: return fde_func_3908_0x17de40(a0, a1);
        case 3909: return fde_func_3909_0x17df58(a0, a1);
        case 3910: return fde_func_3910_0x17e0b8(a0, a1);
        case 3911: return fde_func_3911_0x17e168(a0, a1);
        case 3912: return fde_func_3912_0x17e22c(a0, a1);
        case 3913: return fde_func_3913_0x17e29c(a0, a1);
        case 3914: return fde_func_3914_0x17e5c0(a0, a1);
        case 3915: return fde_func_3915_0x17e618(a0, a1);
        case 3916: return fde_func_3916_0x17e670(a0, a1);
        case 3917: return fde_func_3917_0x17e730(a0, a1);
        case 3918: return fde_func_3918_0x17e7f4(a0, a1);
        case 3919: return fde_func_3919_0x17e848(a0, a1);
        case 3920: return fde_func_3920_0x17eacc(a0, a1);
        case 3921: return fde_func_3921_0x17ebf0(a0, a1);
        case 3922: return fde_func_3922_0x17ed50(a0, a1);
        case 3923: return fde_func_3923_0x17ee04(a0, a1);
        case 3924: return fde_func_3924_0x17f244(a0, a1);
        case 3925: return fde_func_3925_0x17fa7c(a0, a1);
        case 3926: return fde_func_3926_0x17fbdc(a0, a1);
        case 3927: return fde_func_3927_0x17fd6c(a0, a1);
        case 3928: return fde_func_3928_0x17ffe8(a0, a1);
        case 3929: return fde_func_3929_0x180064(a0, a1);
        case 3930: return fde_func_3930_0x1800dc(a0, a1);
        case 3931: return fde_func_3931_0x180148(a0, a1);
        case 3932: return fde_func_3932_0x180560(a0, a1);
        case 3933: return fde_func_3933_0x180770(a0, a1);
        case 3934: return fde_func_3934_0x180988(a0, a1);
        case 3935: return fde_func_3935_0x180df4(a0, a1);
        case 3936: return fde_func_3936_0x180f50(a0, a1);
        case 3937: return fde_func_3937_0x181074(a0, a1);
        case 3938: return fde_func_3938_0x181088(a0, a1);
        case 3939: return fde_func_3939_0x18109c(a0, a1);
        case 3940: return fde_func_3940_0x181184(a0, a1);
        case 3941: return fde_func_3941_0x181470(a0, a1);
        case 3942: return fde_func_3942_0x1814e0(a0, a1);
        case 3943: return fde_func_3943_0x181500(a0, a1);
        case 3944: return fde_func_3944_0x1815b0(a0, a1);
        case 3945: return fde_func_3945_0x181674(a0, a1);
        case 3946: return fde_func_3946_0x181720(a0, a1);
        case 3947: return fde_func_3947_0x1817d0(a0, a1);
        case 3948: return fde_func_3948_0x181880(a0, a1);
        case 3949: return fde_func_3949_0x1819a4(a0, a1);
        case 3950: return fde_func_3950_0x181e74(a0, a1);
        case 3951: return fde_func_3951_0x182198(a0, a1);
        case 3952: return fde_func_3952_0x18255c(a0, a1);
        case 3953: return fde_func_3953_0x18263c(a0, a1);
        case 3954: return fde_func_3954_0x182720(a0, a1);
        case 3955: return fde_func_3955_0x182858(a0, a1);
        case 3956: return fde_func_3956_0x1828e8(a0, a1);
        case 3957: return fde_func_3957_0x182a34(a0, a1);
        case 3958: return fde_func_3958_0x182b0c(a0, a1);
        case 3959: return fde_func_3959_0x182ce4(a0, a1);
        case 3960: return fde_func_3960_0x182dec(a0, a1);
        case 3961: return fde_func_3961_0x182f1c(a0, a1);
        case 3962: return fde_func_3962_0x182fb4(a0, a1);
        case 3963: return fde_func_3963_0x18304c(a0, a1);
        case 3964: return fde_func_3964_0x1830e4(a0, a1);
        case 3965: return fde_func_3965_0x1831f4(a0, a1);
        case 3966: return fde_func_3966_0x1832cc(a0, a1);
        case 3967: return fde_func_3967_0x1832fc(a0, a1);
        case 3968: return fde_func_3968_0x183438(a0, a1);
        case 3969: return fde_func_3969_0x183484(a0, a1);
        case 3970: return fde_func_3970_0x1835c4(a0, a1);
        case 3971: return fde_func_3971_0x1835c8(a0, a1);
        case 3972: return fde_func_3972_0x1835e0(a0, a1);
        case 3973: return fde_func_3973_0x1835f8(a0, a1);
        case 3974: return fde_func_3974_0x183764(a0, a1);
        case 3975: return fde_func_3975_0x1838d0(a0, a1);
        case 3976: return fde_func_3976_0x183aa4(a0, a1);
        case 3977: return fde_func_3977_0x183c34(a0, a1);
        case 3978: return fde_func_3978_0x183c40(a0, a1);
        case 3979: return fde_func_3979_0x183d60(a0, a1);
        case 3980: return fde_func_3980_0x183f70(a0, a1);
        case 3981: return fde_func_3981_0x183f74(a0, a1);
        case 3982: return fde_func_3982_0x184170(a0, a1);
        case 3983: return fde_func_3983_0x184178(a0, a1);
        case 3984: return fde_func_3984_0x184180(a0, a1);
        case 3985: return fde_func_3985_0x184518(a0, a1);
        case 3986: return fde_func_3986_0x184788(a0, a1);
        case 3987: return fde_func_3987_0x184810(a0, a1);
        case 3988: return fde_func_3988_0x18498c(a0, a1);
        case 3989: return fde_func_3989_0x184b68(a0, a1);
        case 3990: return fde_func_3990_0x184e7c(a0, a1);
        case 3991: return fde_func_3991_0x1851c8(a0, a1);
        case 3992: return fde_func_3992_0x185414(a0, a1);
        case 3993: return fde_func_3993_0x1856ac(a0, a1);
        case 3994: return fde_func_3994_0x1858f8(a0, a1);
        case 3995: return fde_func_3995_0x185bac(a0, a1);
        case 3996: return fde_func_3996_0x185e60(a0, a1);
        case 3997: return fde_func_3997_0x18638c(a0, a1);
        case 3998: return fde_func_3998_0x18645c(a0, a1);
        case 3999: return fde_func_3999_0x18698c(a0, a1);
        case 4000: return fde_func_4000_0x186a6c(a0, a1);
        case 4001: return fde_func_4001_0x186c04(a0, a1);
        case 4002: return fde_func_4002_0x186d5c(a0, a1);
        case 4003: return fde_func_4003_0x186ed0(a0, a1);
        case 4004: return fde_func_4004_0x186fdc(a0, a1);
        case 4005: return fde_func_4005_0x187134(a0, a1);
        case 4006: return fde_func_4006_0x187240(a0, a1);
        case 4007: return fde_func_4007_0x188040(a0, a1);
        case 4008: return fde_func_4008_0x18812c(a0, a1);
        case 4009: return fde_func_4009_0x1881d8(a0, a1);
        case 4010: return fde_func_4010_0x1881e4(a0, a1);
        case 4011: return fde_func_4011_0x188244(a0, a1);
        case 4012: return fde_func_4012_0x18835c(a0, a1);
        case 4013: return fde_func_4013_0x188614(a0, a1);
        case 4014: return fde_func_4014_0x188624(a0, a1);
        case 4015: return fde_func_4015_0x18868c(a0, a1);
        case 4016: return fde_func_4016_0x1886f4(a0, a1);
        case 4017: return fde_func_4017_0x1887dc(a0, a1);
        case 4018: return fde_func_4018_0x1887ec(a0, a1);
        case 4019: return fde_func_4019_0x1888a4(a0, a1);
        case 4020: return fde_func_4020_0x18895c(a0, a1);
        case 4021: return fde_func_4021_0x1889f0(a0, a1);
        case 4022: return fde_func_4022_0x188a88(a0, a1);
        case 4023: return fde_func_4023_0x188a90(a0, a1);
        case 4024: return fde_func_4024_0x188aa4(a0, a1);
        case 4025: return fde_func_4025_0x188c00(a0, a1);
        case 4026: return fde_func_4026_0x188cfc(a0, a1);
        case 4027: return fde_func_4027_0x188dfc(a0, a1);
        case 4028: return fde_func_4028_0x188e04(a0, a1);
        case 4029: return fde_func_4029_0x188e0c(a0, a1);
        case 4030: return fde_func_4030_0x188e14(a0, a1);
        case 4031: return fde_func_4031_0x188e1c(a0, a1);
        case 4032: return fde_func_4032_0x188e24(a0, a1);
        case 4033: return fde_func_4033_0x188e2c(a0, a1);
        case 4034: return fde_func_4034_0x188e34(a0, a1);
        case 4035: return fde_func_4035_0x188e3c(a0, a1);
        case 4036: return fde_func_4036_0x188e44(a0, a1);
        case 4037: return fde_func_4037_0x188e84(a0, a1);
        case 4038: return fde_func_4038_0x188f94(a0, a1);
        case 4039: return fde_func_4039_0x188ff8(a0, a1);
        case 4040: return fde_func_4040_0x189020(a0, a1);
        case 4041: return fde_func_4041_0x18902c(a0, a1);
        case 4042: return fde_func_4042_0x189134(a0, a1);
        case 4043: return fde_func_4043_0x189190(a0, a1);
        case 4044: return fde_func_4044_0x18930c(a0, a1);
        case 4045: return fde_func_4045_0x189320(a0, a1);
        case 4046: return fde_func_4046_0x189440(a0, a1);
        case 4047: return fde_func_4047_0x189448(a0, a1);
        case 4048: return fde_func_4048_0x18946c(a0, a1);
        case 4049: return fde_func_4049_0x18951c(a0, a1);
        case 4050: return fde_func_4050_0x18958c(a0, a1);
        case 4051: return fde_func_4051_0x189600(a0, a1);
        case 4052: return fde_func_4052_0x189638(a0, a1);
        case 4053: return fde_func_4053_0x189688(a0, a1);
        case 4054: return fde_func_4054_0x1896c0(a0, a1);
        case 4055: return fde_func_4055_0x1896f8(a0, a1);
        case 4056: return fde_func_4056_0x189720(a0, a1);
        case 4057: return fde_func_4057_0x189790(a0, a1);
        case 4058: return fde_func_4058_0x189948(a0, a1);
        case 4059: return fde_func_4059_0x1899cc(a0, a1);
        case 4060: return fde_func_4060_0x189ab4(a0, a1);
        case 4061: return fde_func_4061_0x18a04c(a0, a1);
        case 4062: return fde_func_4062_0x18a0f0(a0, a1);
        case 4063: return fde_func_4063_0x18a0fc(a0, a1);
        case 4064: return fde_func_4064_0x18a160(a0, a1);
        case 4065: return fde_func_4065_0x18a29c(a0, a1);
        case 4066: return fde_func_4066_0x18a370(a0, a1);
        case 4067: return fde_func_4067_0x18a47c(a0, a1);
        case 4068: return fde_func_4068_0x18a7bc(a0, a1);
        case 4069: return fde_func_4069_0x18a820(a0, a1);
        case 4070: return fde_func_4070_0x18a94c(a0, a1);
        case 4071: return fde_func_4071_0x18ac00(a0, a1);
        case 4072: return fde_func_4072_0x18ac0c(a0, a1);
        case 4073: return fde_func_4073_0x18ac84(a0, a1);
        case 4074: return fde_func_4074_0x18acf4(a0, a1);
        case 4075: return fde_func_4075_0x18ad38(a0, a1);
        case 4076: return fde_func_4076_0x18ae10(a0, a1);
        case 4077: return fde_func_4077_0x18ae4c(a0, a1);
        case 4078: return fde_func_4078_0x18aeec(a0, a1);
        case 4079: return fde_func_4079_0x18af50(a0, a1);
        case 4080: return fde_func_4080_0x18af94(a0, a1);
        case 4081: return fde_func_4081_0x18b09c(a0, a1);
        case 4082: return fde_func_4082_0x18b0b4(a0, a1);
        case 4083: return fde_func_4083_0x18b268(a0, a1);
        case 4084: return fde_func_4084_0x18b304(a0, a1);
        case 4085: return fde_func_4085_0x18b35c(a0, a1);
        case 4086: return fde_func_4086_0x18b5dc(a0, a1);
        case 4087: return fde_func_4087_0x18b5e8(a0, a1);
        case 4088: return fde_func_4088_0x18b76c(a0, a1);
        case 4089: return fde_func_4089_0x18b8d0(a0, a1);
        case 4090: return fde_func_4090_0x18b964(a0, a1);
        case 4091: return fde_func_4091_0x18bb00(a0, a1);
        case 4092: return fde_func_4092_0x18bbbc(a0, a1);
        case 4093: return fde_func_4093_0x18bc58(a0, a1);
        case 4094: return fde_func_4094_0x18beec(a0, a1);
        case 4095: return fde_func_4095_0x18bf24(a0, a1);
        case 4096: return fde_func_4096_0x18c05c(a0, a1);
        case 4097: return fde_func_4097_0x18c06c(a0, a1);
        case 4098: return fde_func_4098_0x18c124(a0, a1);
        case 4099: return fde_func_4099_0x18c398(a0, a1);
        case 4100: return fde_func_4100_0x18c440(a0, a1);
        case 4101: return fde_func_4101_0x18c4e4(a0, a1);
        case 4102: return fde_func_4102_0x18c5c0(a0, a1);
        case 4103: return fde_func_4103_0x18c5d0(a0, a1);
        case 4104: return fde_func_4104_0x18c690(a0, a1);
        case 4105: return fde_func_4105_0x18c718(a0, a1);
        case 4106: return fde_func_4106_0x18c77c(a0, a1);
        case 4107: return fde_func_4107_0x18c794(a0, a1);
        case 4108: return fde_func_4108_0x18c870(a0, a1);
        case 4109: return fde_func_4109_0x18c88c(a0, a1);
        case 4110: return fde_func_4110_0x18c914(a0, a1);
        case 4111: return fde_func_4111_0x18c930(a0, a1);
        case 4112: return fde_func_4112_0x18ca14(a0, a1);
        case 4113: return fde_func_4113_0x18ca1c(a0, a1);
        case 4114: return fde_func_4114_0x18ca50(a0, a1);
        case 4115: return fde_func_4115_0x18ca54(a0, a1);
        case 4116: return fde_func_4116_0x18ca84(a0, a1);
        case 4117: return fde_func_4117_0x18ca9c(a0, a1);
        case 4118: return fde_func_4118_0x18caa4(a0, a1);
        case 4119: return fde_func_4119_0x18cb10(a0, a1);
        case 4120: return fde_func_4120_0x18cb24(a0, a1);
        case 4121: return fde_func_4121_0x18cb3c(a0, a1);
        case 4122: return fde_func_4122_0x18cc50(a0, a1);
        case 4123: return fde_func_4123_0x18ccd8(a0, a1);
        case 4124: return fde_func_4124_0x18ccec(a0, a1);
        case 4125: return fde_func_4125_0x18cd04(a0, a1);
        case 4126: return fde_func_4126_0x18ce00(a0, a1);
        case 4127: return fde_func_4127_0x18cf44(a0, a1);
        case 4128: return fde_func_4128_0x18d05c(a0, a1);
        case 4129: return fde_func_4129_0x18d190(a0, a1);
        case 4130: return fde_func_4130_0x18d1d4(a0, a1);
        case 4131: return fde_func_4131_0x18d1dc(a0, a1);
        case 4132: return fde_func_4132_0x18d278(a0, a1);
        case 4133: return fde_func_4133_0x18d2b4(a0, a1);
        case 4134: return fde_func_4134_0x18d3d0(a0, a1);
        case 4135: return fde_func_4135_0x18d464(a0, a1);
        case 4136: return fde_func_4136_0x18d498(a0, a1);
        case 4137: return fde_func_4137_0x18d500(a0, a1);
        case 4138: return fde_func_4138_0x18d558(a0, a1);
        case 4139: return fde_func_4139_0x18d760(a0, a1);
        case 4140: return fde_func_4140_0x18d7f8(a0, a1);
        case 4141: return fde_func_4141_0x18d8b4(a0, a1);
        case 4142: return fde_func_4142_0x18d8c0(a0, a1);
        case 4143: return fde_func_4143_0x18d918(a0, a1);
        case 4144: return fde_func_4144_0x18d928(a0, a1);
        case 4145: return fde_func_4145_0x18d93c(a0, a1);
        case 4146: return fde_func_4146_0x18d98c(a0, a1);
        case 4147: return fde_func_4147_0x18d9bc(a0, a1);
        case 4148: return fde_func_4148_0x18da34(a0, a1);
        case 4149: return fde_func_4149_0x18db20(a0, a1);
        case 4150: return fde_func_4150_0x18dd34(a0, a1);
        case 4151: return fde_func_4151_0x18dde0(a0, a1);
        case 4152: return fde_func_4152_0x18df24(a0, a1);
        case 4153: return fde_func_4153_0x18e11c(a0, a1);
        case 4154: return fde_func_4154_0x18e27c(a0, a1);
        case 4155: return fde_func_4155_0x18e3dc(a0, a1);
        case 4156: return fde_func_4156_0x18e538(a0, a1);
        case 4157: return fde_func_4157_0x18e698(a0, a1);
        case 4158: return fde_func_4158_0x18e7f4(a0, a1);
        case 4159: return fde_func_4159_0x18e800(a0, a1);
        case 4160: return fde_func_4160_0x18e86c(a0, a1);
        case 4161: return fde_func_4161_0x18e900(a0, a1);
        case 4162: return fde_func_4162_0x18e998(a0, a1);
        case 4163: return fde_func_4163_0x18ed1c(a0, a1);
        case 4164: return fde_func_4164_0x18ed24(a0, a1);
        case 4165: return fde_func_4165_0x18ed88(a0, a1);
        case 4166: return fde_func_4166_0x18edf4(a0, a1);
        case 4167: return fde_func_4167_0x18ee54(a0, a1);
        case 4168: return fde_func_4168_0x18eeb8(a0, a1);
        case 4169: return fde_func_4169_0x18efd0(a0, a1);
        case 4170: return fde_func_4170_0x18f4d0(a0, a1);
        case 4171: return fde_func_4171_0x18f5e0(a0, a1);
        case 4172: return fde_func_4172_0x18f73c(a0, a1);
        case 4173: return fde_func_4173_0x18f810(a0, a1);
        case 4174: return fde_func_4174_0x18f9ec(a0, a1);
        case 4175: return fde_func_4175_0x18fa54(a0, a1);
        case 4176: return fde_func_4176_0x18fb58(a0, a1);
        case 4177: return fde_func_4177_0x18fbd8(a0, a1);
        case 4178: return fde_func_4178_0x18fc6c(a0, a1);
        case 4179: return fde_func_4179_0x18fe64(a0, a1);
        case 4180: return fde_func_4180_0x190064(a0, a1);
        case 4181: return fde_func_4181_0x190228(a0, a1);
        case 4182: return fde_func_4182_0x190308(a0, a1);
        case 4183: return fde_func_4183_0x1903e8(a0, a1);
        case 4184: return fde_func_4184_0x190a14(a0, a1);
        case 4185: return fde_func_4185_0x190ff0(a0, a1);
        case 4186: return fde_func_4186_0x191188(a0, a1);
        case 4187: return fde_func_4187_0x1912b8(a0, a1);
        case 4188: return fde_func_4188_0x1912c8(a0, a1);
        case 4189: return fde_func_4189_0x1912d8(a0, a1);
        case 4190: return fde_func_4190_0x191460(a0, a1);
        case 4191: return fde_func_4191_0x191620(a0, a1);
        case 4192: return fde_func_4192_0x1937b8(a0, a1);
        case 4193: return fde_func_4193_0x1957e4(a0, a1);
        case 4194: return fde_func_4194_0x1977f8(a0, a1);
        case 4195: return fde_func_4195_0x197a68(a0, a1);
        case 4196: return fde_func_4196_0x197bec(a0, a1);
        case 4197: return fde_func_4197_0x197ec4(a0, a1);
        case 4198: return fde_func_4198_0x198048(a0, a1);
        case 4199: return fde_func_4199_0x198390(a0, a1);
        case 4200: return fde_func_4200_0x198514(a0, a1);
        case 4201: return fde_func_4201_0x198848(a0, a1);
        case 4202: return fde_func_4202_0x19916c(a0, a1);
        case 4203: return fde_func_4203_0x199934(a0, a1);
        case 4204: return fde_func_4204_0x199a1c(a0, a1);
        case 4205: return fde_func_4205_0x199a2c(a0, a1);
        case 4206: return fde_func_4206_0x199af0(a0, a1);
        case 4207: return fde_func_4207_0x199b68(a0, a1);
        case 4208: return fde_func_4208_0x199be8(a0, a1);
        case 4209: return fde_func_4209_0x199c7c(a0, a1);
        case 4210: return fde_func_4210_0x199cc0(a0, a1);
        case 4211: return fde_func_4211_0x199e10(a0, a1);
        case 4212: return fde_func_4212_0x199f30(a0, a1);
        case 4213: return fde_func_4213_0x199fd0(a0, a1);
        case 4214: return fde_func_4214_0x19a078(a0, a1);
        case 4215: return fde_func_4215_0x19a154(a0, a1);
        case 4216: return fde_func_4216_0x19a2a8(a0, a1);
        case 4217: return fde_func_4217_0x19a488(a0, a1);
        case 4218: return fde_func_4218_0x19a554(a0, a1);
        case 4219: return fde_func_4219_0x19a564(a0, a1);
        case 4220: return fde_func_4220_0x19a574(a0, a1);
        case 4221: return fde_func_4221_0x19a61c(a0, a1);
        case 4222: return fde_func_4222_0x19a640(a0, a1);
        case 4223: return fde_func_4223_0x19a684(a0, a1);
        case 4224: return fde_func_4224_0x19a798(a0, a1);
        case 4225: return fde_func_4225_0x19a860(a0, a1);
        case 4226: return fde_func_4226_0x19a8b8(a0, a1);
        case 4227: return fde_func_4227_0x19a8f0(a0, a1);
        case 4228: return fde_func_4228_0x19aa64(a0, a1);
        case 4229: return fde_func_4229_0x19abb8(a0, a1);
        case 4230: return fde_func_4230_0x19ad18(a0, a1);
        case 4231: return fde_func_4231_0x19ae5c(a0, a1);
        case 4232: return fde_func_4232_0x19ae64(a0, a1);
        case 4233: return fde_func_4233_0x19b01c(a0, a1);
        case 4234: return fde_func_4234_0x19b138(a0, a1);
        case 4235: return fde_func_4235_0x19b328(a0, a1);
        case 4236: return fde_func_4236_0x19b454(a0, a1);
        case 4237: return fde_func_4237_0x19b648(a0, a1);
        case 4238: return fde_func_4238_0x19b658(a0, a1);
        case 4239: return fde_func_4239_0x19b6e0(a0, a1);
        case 4240: return fde_func_4240_0x19b774(a0, a1);
        case 4241: return fde_func_4241_0x19b780(a0, a1);
        case 4242: return fde_func_4242_0x19b7dc(a0, a1);
        case 4243: return fde_func_4243_0x19b84c(a0, a1);
        case 4244: return fde_func_4244_0x19b8bc(a0, a1);
        case 4245: return fde_func_4245_0x19bac4(a0, a1);
        case 4246: return fde_func_4246_0x19bccc(a0, a1);
        case 4247: return fde_func_4247_0x19bdd0(a0, a1);
        case 4248: return fde_func_4248_0x19e0b0(a0, a1);
        case 4249: return fde_func_4249_0x19e188(a0, a1);
        case 4250: return fde_func_4250_0x19e1d4(a0, a1);
        case 4251: return fde_func_4251_0x19e208(a0, a1);
        case 4252: return fde_func_4252_0x19e2e4(a0, a1);
        case 4253: return fde_func_4253_0x19e3b0(a0, a1);
        case 4254: return fde_func_4254_0x19e47c(a0, a1);
        case 4255: return fde_func_4255_0x19e58c(a0, a1);
        case 4256: return fde_func_4256_0x19e8e4(a0, a1);
        case 4257: return fde_func_4257_0x19e8ec(a0, a1);
        case 4258: return fde_func_4258_0x19e910(a0, a1);
        case 4259: return fde_func_4259_0x19e938(a0, a1);
        case 4260: return fde_func_4260_0x19e978(a0, a1);
        case 4261: return fde_func_4261_0x19ea68(a0, a1);
        case 4262: return fde_func_4262_0x19eb7c(a0, a1);
        case 4263: return fde_func_4263_0x19ebb8(a0, a1);
        case 4264: return fde_func_4264_0x19ec10(a0, a1);
        case 4265: return fde_func_4265_0x19ed1c(a0, a1);
        case 4266: return fde_func_4266_0x19ed24(a0, a1);
        case 4267: return fde_func_4267_0x19ed7c(a0, a1);
        case 4268: return fde_func_4268_0x19ed84(a0, a1);
        case 4269: return fde_func_4269_0x19ed98(a0, a1);
        case 4270: return fde_func_4270_0x19eda0(a0, a1);
        case 4271: return fde_func_4271_0x19eda8(a0, a1);
        case 4272: return fde_func_4272_0x19edb0(a0, a1);
        case 4273: return fde_func_4273_0x19edd8(a0, a1);
        case 4274: return fde_func_4274_0x19ede0(a0, a1);
        case 4275: return fde_func_4275_0x19ede8(a0, a1);
        case 4276: return fde_func_4276_0x19ee60(a0, a1);
        case 4277: return fde_func_4277_0x19f358(a0, a1);
        case 4278: return fde_func_4278_0x19f77c(a0, a1);
        case 4279: return fde_func_4279_0x19fd30(a0, a1);
        case 4280: return fde_func_4280_0x19ff3c(a0, a1);
        case 4281: return fde_func_4281_0x1a0018(a0, a1);
        case 4282: return fde_func_4282_0x1a0064(a0, a1);
        case 4283: return fde_func_4283_0x1a0124(a0, a1);
        case 4284: return fde_func_4284_0x1a0210(a0, a1);
        case 4285: return fde_func_4285_0x1a0304(a0, a1);
        case 4286: return fde_func_4286_0x1a0308(a0, a1);
        case 4287: return fde_func_4287_0x1a0480(a0, a1);
        case 4288: return fde_func_4288_0x1a0574(a0, a1);
        case 4289: return fde_func_4289_0x1a0670(a0, a1);
        case 4290: return fde_func_4290_0x1a0768(a0, a1);
        case 4291: return fde_func_4291_0x1a078c(a0, a1);
        case 4292: return fde_func_4292_0x1a085c(a0, a1);
        case 4293: return fde_func_4293_0x1a0884(a0, a1);
        case 4294: return fde_func_4294_0x1a08c4(a0, a1);
        case 4295: return fde_func_4295_0x1a08e0(a0, a1);
        case 4296: return fde_func_4296_0x1a09a0(a0, a1);
        case 4297: return fde_func_4297_0x1a0a54(a0, a1);
        case 4298: return fde_func_4298_0x1a0ab4(a0, a1);
        case 4299: return fde_func_4299_0x1a0b14(a0, a1);
        case 4300: return fde_func_4300_0x1a0b74(a0, a1);
        case 4301: return fde_func_4301_0x1a0c64(a0, a1);
        case 4302: return fde_func_4302_0x1a0cf4(a0, a1);
        case 4303: return fde_func_4303_0x1a0df0(a0, a1);
        case 4304: return fde_func_4304_0x1a0f50(a0, a1);
        case 4305: return fde_func_4305_0x1a0f60(a0, a1);
        case 4306: return fde_func_4306_0x1a137c(a0, a1);
        case 4307: return fde_func_4307_0x1a1418(a0, a1);
        case 4308: return fde_func_4308_0x1a1578(a0, a1);
        case 4309: return fde_func_4309_0x1a16ac(a0, a1);
        case 4310: return fde_func_4310_0x1a1c1c(a0, a1);
        case 4311: return fde_func_4311_0x1a1cb8(a0, a1);
        case 4312: return fde_func_4312_0x1a1cc4(a0, a1);
        case 4313: return fde_func_4313_0x1a1d04(a0, a1);
        case 4314: return fde_func_4314_0x1a1d98(a0, a1);
        case 4315: return fde_func_4315_0x1a1da4(a0, a1);
        case 4316: return fde_func_4316_0x1a1dd0(a0, a1);
        case 4317: return fde_func_4317_0x1a1ed0(a0, a1);
        case 4318: return fde_func_4318_0x1a1ed4(a0, a1);
        case 4319: return fde_func_4319_0x1a1ef8(a0, a1);
        default: return 0ULL;
    }
}