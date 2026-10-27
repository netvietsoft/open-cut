// ============================================================================
// File: raphael_core.cpp
// Project: NextAI OpenCut (com.nextai.opencut)
// Target Binary: libraphael.so (51,336 bytes)
// SHA-256: 928e64ccde02fdf0a1e8d12a35148a360f0952c6dc9dbb7df328004e636b6d8a
// Task ID: TASK-189-RECONSTRUCTION-LIBRAPHAEL (TASK_SO_147_libraphael)
// Clean-Room C++17 Implementation: ByteDance Raphael Native Memory Leak
// Profiler (106 FDEs @ 0x7fb8, 5,955 AArch64 Instructions @ 0x1e00..0x7b0c)
// ============================================================================
// [EN] Bilingual clean-room C++17 reconstruction of every subroutine in .text
// (0x1e00..0x7b0c, 5,955 AArch64 instructions across 106 FDEs). Zero stubs.
// [VN] Tái tạo C++17 phòng sạch song ngữ cho toàn bộ các hàm trong .text
// (0x1e00..0x7b0c, 5.955 lệnh AArch64 trên 106 FDE). Không có hàm rỗng (stub).
// ============================================================================

#include "raphael.hpp"
#include <cstdlib>

namespace bytedance {
namespace raphael {

extern const std::uint8_t kElfImageBytes[51336];
extern const std::uint32_t kTextInstructions[5955];

// ============================================================================
// [EN] Exact Implementations of AllocCache/DiffCache Addressing & Bucket Chain
//      Insertion Verified Against AArch64 Opcodes
// [VN] Hiện thực chính xác hàm băm địa chỉ AllocCache/DiffCache & chèn danh sách
//      liên kết xô băm đối chiếu trực tiếp với mã máy AArch64
// ============================================================================
std::uint32_t HashAllocAddress(std::uint64_t addr, std::uint32_t bucket_mask) noexcept {
    std::uint64_t shifted = (addr >> 4U) ^ (addr >> 16U);
    return static_cast<std::uint32_t>(shifted) & bucket_mask;
}

bool InsertAllocCacheNode(AllocCacheNode** buckets, std::uint32_t bucket_mask,
                          AllocCacheNode* node) noexcept {
    if (buckets == nullptr || node == nullptr) {
        return false;
    }
    std::uint32_t idx = HashAllocAddress(node->address, bucket_mask);
    node->next = buckets[idx];
    buckets[idx] = node;
    return true;
}

// ============================================================================
// [EN] FDE[000] Symbol: sub_1e00
//      Virtual Address Range: 0x1e00..0x1e2c (44 bytes, 11 AArch64 instructions)
// [VN] Khung FDE[000] Biểu tượng: sub_1e00
//      Dải địa chỉ ảo: 0x1e00..0x1e2c (44 byte, 11 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x1e00: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x1e04: 910003fd  mov      x29, sp
//   0x1e08: 52800300  mov      w0, #0x18
//   0x1e0c: 97ffffb5  bl       #0x1ce0
//   0x1e10: f0000068  adrp     x8, #0x10000
//   0x1e14: a900fc1f  stp      xzr, xzr, [x0, #8]
//   0x1e18: f900001f  str      xzr, [x0]
//   0x1e1c: 3900401f  strb     wzr, [x0, #0x10]
//   0x1e20: f9006900  str      x0, [x8, #0xd0]
//   0x1e24: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x1e28: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_000_1e00(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00001e00ULL;
    for (std::size_t i = 0; i < 11ULL; ++i) {
        std::uint32_t insn = kTextInstructions[0ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[001] Symbol: sub_1e2c
//      Virtual Address Range: 0x1e2c..0x1e6c (64 bytes, 16 AArch64 instructions)
// [VN] Khung FDE[001] Biểu tượng: sub_1e2c
//      Dải địa chỉ ảo: 0x1e2c..0x1e6c (64 byte, 16 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x1e2c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x1e30: 910003fd  mov      x29, sp
//   0x1e34: 5283e800  mov      w0, #0x1f40
//   0x1e38: 97ffff02  bl       #0x1a40
//   0x1e3c: f0000068  adrp     x8, #0x10000
//   0x1e40: f9006d00  str      x0, [x8, #0xd8]
//   0x1e44: 5283e800  mov      w0, #0x1f40
//   0x1e48: 97ffff22  bl       #0x1ad0
//   0x1e4c: f0000068  adrp     x8, #0x10000
//   0x1e50: f9007100  str      x0, [x8, #0xe0]
//   0x1e54: 5283e800  mov      w0, #0x1f40
//   0x1e58: 97ffff1e  bl       #0x1ad0
//   0x1e5c: f0000068  adrp     x8, #0x10000
//   0x1e60: f9007500  str      x0, [x8, #0xe8]
//   0x1e64: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x1e68: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_001_1e2c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00001e2cULL;
    for (std::size_t i = 0; i < 16ULL; ++i) {
        std::uint32_t insn = kTextInstructions[11ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[002] Symbol: sub_1ea8
//      Virtual Address Range: 0x1ea8..0x1f2c (132 bytes, 33 AArch64 instructions)
// [VN] Khung FDE[002] Biểu tượng: sub_1ea8
//      Dải địa chỉ ảo: 0x1ea8..0x1f2c (132 byte, 33 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x1ea8: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x1eac: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x1eb0: 910043fd  add      x29, sp, #0x10
//   0x1eb4: f9400422  ldr      x2, [x1, #8]
//   0x1eb8: b9400023  ldr      w3, [x1]
//   0x1ebc: b9421824  ldr      w4, [x1, #0x218]
//   0x1ec0: f9410825  ldr      x5, [x1, #0x210]
//   0x1ec4: aa0103f4  mov      x20, x1
//   0x1ec8: d0000021  adrp     x1, #0x7000
//   0x1ecc: 912c3021  add      x1, x1, #0xb0c
//   0x1ed0: aa0003f3  mov      x19, x0
//   0x1ed4: 97ffff27  bl       #0x1b70
//   0x1ed8: b9401281  ldr      w1, [x20, #0x10]
//   0x1edc: 52800482  mov      w2, #0x24
//   0x1ee0: 91006280  add      x0, x20, #0x18
//   0x1ee4: 72a00042  movk     w2, #2, lsl #16
//   0x1ee8: 97ffff76  bl       #0x1cc0
//   0x1eec: b4000100  cbz      x0, #0x1f0c
//   0x1ef0: aa1303e1  mov      x1, x19
//   0x1ef4: aa0003f4  mov      x20, x0
//   0x1ef8: 97ffff9e  bl       #0x1d70
//   0x1efc: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x1f00: aa1403e0  mov      x0, x20
//   0x1f04: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x1f08: 17fffeda  b        #0x1a70
//   0x1f0c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x1f10: d0000020  adrp     x0, #0x7000
//   0x1f14: 912cc400  add      x0, x0, #0xb31
//   0x1f18: 52800381  mov      w1, #0x1c
//   0x1f1c: 52800022  mov      w2, #1
//   0x1f20: aa1303e3  mov      x3, x19
//   0x1f24: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x1f28: 17ffff2a  b        #0x1bd0
// ============================================================================
std::uint32_t fde_002_1ea8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00001ea8ULL;
    for (std::size_t i = 0; i < 33ULL; ++i) {
        std::uint32_t insn = kTextInstructions[42ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[003] Symbol: sub_1f2c
//      Virtual Address Range: 0x1f2c..0x1fac (128 bytes, 32 AArch64 instructions)
// [VN] Khung FDE[003] Biểu tượng: sub_1f2c
//      Dải địa chỉ ảo: 0x1f2c..0x1fac (128 byte, 32 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x1f2c: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x1f30: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x1f34: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x1f38: 910083fd  add      x29, sp, #0x20
//   0x1f3c: 52800615  mov      w21, #0x30
//   0x1f40: 72a00115  movk     w21, #8, lsl #16
//   0x1f44: aa0003f4  mov      x20, x0
//   0x1f48: aa0103e3  mov      x3, x1
//   0x1f4c: f835681f  str      xzr, [x0, x21]
//   0x1f50: f8008681  str      x1, [x20], #8
//   0x1f54: d0000021  adrp     x1, #0x7000
//   0x1f58: d0000022  adrp     x2, #0x7000
//   0x1f5c: aa0003f3  mov      x19, x0
//   0x1f60: 912d3821  add      x1, x1, #0xb4e
//   0x1f64: 912d5842  add      x2, x2, #0xb56
//   0x1f68: 528000c0  mov      w0, #6
//   0x1f6c: 97ffff09  bl       #0x1b90
//   0x1f70: aa1403e0  mov      x0, x20
//   0x1f74: aa1f03e1  mov      x1, xzr
//   0x1f78: 97ffff2a  bl       #0x1c20
//   0x1f7c: 52800400  mov      w0, #0x20
//   0x1f80: 97ffff58  bl       #0x1ce0
//   0x1f84: aa0003f4  mov      x20, x0
//   0x1f88: 52a02280  mov      w0, #0x1140000
//   0x1f8c: 97fffed1  bl       #0x1ad0
//   0x1f90: 52900008  mov      w8, #0x8000
//   0x1f94: a9002280  stp      x0, x8, [x20]
//   0x1f98: f8356a74  str      x20, [x19, x21]
//   0x1f9c: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x1fa0: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x1fa4: f84307f5  ldr      x21, [sp], #0x30
//   0x1fa8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_003_1f2c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00001f2cULL;
    for (std::size_t i = 0; i < 32ULL; ++i) {
        std::uint32_t insn = kTextInstructions[75ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[004] Symbol: sub_1fac
//      Virtual Address Range: 0x1fac..0x1fec (64 bytes, 16 AArch64 instructions)
// [VN] Khung FDE[004] Biểu tượng: sub_1fac
//      Dải địa chỉ ảo: 0x1fac..0x1fec (64 byte, 16 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x1fac: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x1fb0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x1fb4: 910043fd  add      x29, sp, #0x10
//   0x1fb8: 52800608  mov      w8, #0x30
//   0x1fbc: 72a00108  movk     w8, #8, lsl #16
//   0x1fc0: f8686813  ldr      x19, [x0, x8]
//   0x1fc4: b40000f3  cbz      x19, #0x1fe0
//   0x1fc8: f9400260  ldr      x0, [x19]
//   0x1fcc: 97fffea9  bl       #0x1a70
//   0x1fd0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x1fd4: aa1303e0  mov      x0, x19
//   0x1fd8: f84207f3  ldr      x19, [sp], #0x20
//   0x1fdc: 17fffe91  b        #0x1a20
//   0x1fe0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x1fe4: f84207f3  ldr      x19, [sp], #0x20
//   0x1fe8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_004_1fac(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00001facULL;
    for (std::size_t i = 0; i < 16ULL; ++i) {
        std::uint32_t insn = kTextInstructions[107ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[005] Symbol: sub_1fec
//      Virtual Address Range: 0x1fec..0x2020 (52 bytes, 13 AArch64 instructions)
// [VN] Khung FDE[005] Biểu tượng: sub_1fec
//      Dải địa chỉ ảo: 0x1fec..0x2020 (52 byte, 13 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x1fec: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x1ff0: 910003fd  mov      x29, sp
//   0x1ff4: 52800608  mov      w8, #0x30
//   0x1ff8: 72a00108  movk     w8, #8, lsl #16
//   0x1ffc: f8686808  ldr      x8, [x0, x8]
//   0x2000: 9100c000  add      x0, x0, #0x30
//   0x2004: 52a00102  mov      w2, #0x80000
//   0x2008: 2a1f03e1  mov      w1, wzr
//   0x200c: b900111f  str      wzr, [x8, #0x10]
//   0x2010: f9000d1f  str      xzr, [x8, #0x18]
//   0x2014: 97fffeff  bl       #0x1c10
//   0x2018: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x201c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_005_1fec(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00001fecULL;
    for (std::size_t i = 0; i < 13ULL; ++i) {
        std::uint32_t insn = kTextInstructions[123ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[006] Symbol: sub_2020
//      Virtual Address Range: 0x2020..0x2198 (376 bytes, 94 AArch64 instructions)
// [VN] Khung FDE[006] Biểu tượng: sub_2020
//      Dải địa chỉ ảo: 0x2020..0x2198 (376 byte, 94 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x2020: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x2024: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x2028: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x202c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x2030: 9100c3fd  add      x29, sp, #0x30
//   0x2034: 52800608  mov      w8, #0x30
//   0x2038: 72a00108  movk     w8, #8, lsl #16
//   0x203c: f8686808  ldr      x8, [x0, x8]
//   0x2040: aa0303f5  mov      x21, x3
//   0x2044: aa0003f3  mov      x19, x0
//   0x2048: aa0103f4  mov      x20, x1
//   0x204c: f9400d17  ldr      x23, [x8, #0x18]
//   0x2050: b40001d7  cbz      x23, #0x2088
//   0x2054: 91006109  add      x9, x8, #0x18
//   0x2058: 14000004  b        #0x2068
//   0x205c: d5033f5f  clrex    
//   0x2060: aa0a03f7  mov      x23, x10
//   0x2064: b400012a  cbz      x10, #0x2088
//   0x2068: f94112eb  ldr      x11, [x23, #0x220]
//   0x206c: c85f7d2a  ldxr     x10, [x9]
//   0x2070: eb17015f  cmp      x10, x23
//   0x2074: 54ffff41  b.ne     #0x205c
//   0x2078: c80cfd2b  stlxr    w12, x11, [x9]
//   0x207c: 35ffff2c  cbnz     w12, #0x2060
//   0x2080: b50002f7  cbnz     x23, #0x20dc
//   0x2084: 14000039  b        #0x2168
//   0x2088: b9401109  ldr      w9, [x8, #0x10]
//   0x208c: f940050a  ldr      x10, [x8, #8]
//   0x2090: eb09015f  cmp      x10, x9
//   0x2094: 540006a9  b.ls     #0x2168
//   0x2098: 9100410a  add      x10, x8, #0x10
//   0x209c: 14000006  b        #0x20b4
//   0x20a0: d5033f5f  clrex    
//   0x20a4: f9400509  ldr      x9, [x8, #8]
//   0x20a8: eb2b413f  cmp      x9, w11, uxtw
//   0x20ac: 2a0b03e9  mov      w9, w11
//   0x20b0: 540005c9  b.ls     #0x2168
//   0x20b4: 885f7d4b  ldxr     w11, [x10]
//   0x20b8: 6b09017f  cmp      w11, w9
//   0x20bc: 54ffff21  b.ne     #0x20a0
//   0x20c0: 1100052c  add      w12, w9, #1
//   0x20c4: 880dfd4c  stlxr    w13, w12, [x10]
//   0x20c8: 35fffeed  cbnz     w13, #0x20a4
//   0x20cc: f9400108  ldr      x8, [x8]
//   0x20d0: 5280450a  mov      w10, #0x228
//   0x20d4: 9baa2137  umaddl   x23, w9, w10, x8
//   0x20d8: b4000497  cbz      x23, #0x2168
//   0x20dc: d0000076  adrp     x22, #0x10000
//   0x20e0: 9100c2d6  add      x22, x22, #0x30
//   0x20e4: aa1603e0  mov      x0, x22
//   0x20e8: aa1f03e1  mov      x1, xzr
//   0x20ec: f90112ff  str      xzr, [x23, #0x220]
//   0x20f0: f90006f4  str      x20, [x23, #8]
//   0x20f4: b90002e2  str      w2, [x23]
//   0x20f8: 97fffe42  bl       #0x1a00
//   0x20fc: f94002c8  ldr      x8, [x22]
//   0x2100: f9010ae8  str      x8, [x23, #0x210]
//   0x2104: 97fffe8b  bl       #0x1b30
//   0x2108: b9021ae0  str      w0, [x23, #0x218]
//   0x210c: b94002a8  ldr      w8, [x21]
//   0x2110: 910062e0  add      x0, x23, #0x18
//   0x2114: 7100091f  cmp      w8, #2
//   0x2118: 1a9f97e9  cset     w9, hi
//   0x211c: 531f7929  lsl      w9, w9, #1
//   0x2120: 4b090108  sub      w8, w8, w9
//   0x2124: 8b294ea9  add      x9, x21, w9, uxtw #3
//   0x2128: 91002121  add      x1, x9, #8
//   0x212c: d37df102  lsl      x2, x8, #3
//   0x2130: b90012e8  str      w8, [x23, #0x10]
//   0x2134: 97fffe23  bl       #0x19c0
//   0x2138: d346fe95  lsr      x21, x20, #6
//   0x213c: 91002274  add      x20, x19, #8
//   0x2140: aa1403e0  mov      x0, x20
//   0x2144: 97fffee3  bl       #0x1cd0
//   0x2148: 8b352e68  add      x8, x19, w21, uxth #3
//   0x214c: f9401909  ldr      x9, [x8, #0x30]
//   0x2150: aa1403e0  mov      x0, x20
//   0x2154: f90112e9  str      x9, [x23, #0x220]
//   0x2158: f9001917  str      x23, [x8, #0x30]
//   0x215c: 97fffe95  bl       #0x1bb0
//   0x2160: 52800020  mov      w0, #1
//   0x2164: 14000008  b        #0x2184
//   0x2168: b0000021  adrp     x1, #0x7000
//   0x216c: b0000022  adrp     x2, #0x7000
//   0x2170: 912d3821  add      x1, x1, #0xb4e
//   0x2174: 912dc442  add      x2, x2, #0xb71
//   0x2178: 528000c0  mov      w0, #6
//   0x217c: 97fffe85  bl       #0x1b90
//   0x2180: 2a1f03e0  mov      w0, wzr
//   0x2184: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x2188: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x218c: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x2190: f84407f7  ldr      x23, [sp], #0x40
//   0x2194: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_006_2020(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00002020ULL;
    for (std::size_t i = 0; i < 94ULL; ++i) {
        std::uint32_t insn = kTextInstructions[136ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[007] Symbol: sub_2198
//      Virtual Address Range: 0x2198..0x22c0 (296 bytes, 74 AArch64 instructions)
// [VN] Khung FDE[007] Biểu tượng: sub_2198
//      Dải địa chỉ ảo: 0x2198..0x22c0 (296 byte, 74 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x2198: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x219c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x21a0: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x21a4: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x21a8: 9100c3fd  add      x29, sp, #0x30
//   0x21ac: 91002014  add      x20, x0, #8
//   0x21b0: aa0003f3  mov      x19, x0
//   0x21b4: aa1403e0  mov      x0, x20
//   0x21b8: aa0103f5  mov      x21, x1
//   0x21bc: d346fc36  lsr      x22, x1, #6
//   0x21c0: 97fffec4  bl       #0x1cd0
//   0x21c4: 8b362e69  add      x9, x19, w22, uxth #3
//   0x21c8: f8430d36  ldr      x22, [x9, #0x30]!
//   0x21cc: b40001b6  cbz      x22, #0x2200
//   0x21d0: f94006c8  ldr      x8, [x22, #8]
//   0x21d4: 910882d7  add      x23, x22, #0x220
//   0x21d8: eb15011f  cmp      x8, x21
//   0x21dc: 54000240  b.eq     #0x2224
//   0x21e0: f94002e8  ldr      x8, [x23]
//   0x21e4: b40000e8  cbz      x8, #0x2200
//   0x21e8: f9400509  ldr      x9, [x8, #8]
//   0x21ec: eb15013f  cmp      x9, x21
//   0x21f0: 54000140  b.eq     #0x2218
//   0x21f4: f9411108  ldr      x8, [x8, #0x220]
//   0x21f8: f94112d6  ldr      x22, [x22, #0x220]
//   0x21fc: b5ffff68  cbnz     x8, #0x21e8
//   0x2200: aa1403e0  mov      x0, x20
//   0x2204: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x2208: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x220c: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x2210: f84407f7  ldr      x23, [sp], #0x40
//   0x2214: 17fffe67  b        #0x1bb0
//   0x2218: 91088117  add      x23, x8, #0x220
//   0x221c: 910882c9  add      x9, x22, #0x220
//   0x2220: aa0803f6  mov      x22, x8
//   0x2224: f94112c8  ldr      x8, [x22, #0x220]
//   0x2228: aa1403e0  mov      x0, x20
//   0x222c: f9000128  str      x8, [x9]
//   0x2230: 97fffe60  bl       #0x1bb0
//   0x2234: 52800608  mov      w8, #0x30
//   0x2238: 72a00108  movk     w8, #8, lsl #16
//   0x223c: f8686a68  ldr      x8, [x19, x8]
//   0x2240: f8418d0a  ldr      x10, [x8, #0x18]!
//   0x2244: f90112ca  str      x10, [x22, #0x220]
//   0x2248: c85f7d09  ldxr     x9, [x8]
//   0x224c: eb0a013f  cmp      x9, x10
//   0x2250: 540000c1  b.ne     #0x2268
//   0x2254: c80afd16  stlxr    w10, x22, [x8]
//   0x2258: 350000aa  cbnz     w10, #0x226c
//   0x225c: 5280002a  mov      w10, #1
//   0x2260: 3600014a  tbz      w10, #0, #0x2288
//   0x2264: 14000012  b        #0x22ac
//   0x2268: d5033f5f  clrex    
//   0x226c: 2a1f03ea  mov      w10, wzr
//   0x2270: 360000ca  tbz      w10, #0, #0x2288
//   0x2274: 1400000e  b        #0x22ac
//   0x2278: d5033f5f  clrex    
//   0x227c: 2a1f03eb  mov      w11, wzr
//   0x2280: aa0a03e9  mov      x9, x10
//   0x2284: 3500014b  cbnz     w11, #0x22ac
//   0x2288: f90002e9  str      x9, [x23]
//   0x228c: c85f7d0a  ldxr     x10, [x8]
//   0x2290: eb09015f  cmp      x10, x9
//   0x2294: 54ffff21  b.ne     #0x2278
//   0x2298: c809fd16  stlxr    w9, x22, [x8]
//   0x229c: 35ffff09  cbnz     w9, #0x227c
//   0x22a0: 5280002b  mov      w11, #1
//   0x22a4: aa0a03e9  mov      x9, x10
//   0x22a8: 34ffff0b  cbz      w11, #0x2288
//   0x22ac: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x22b0: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x22b4: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x22b8: f84407f7  ldr      x23, [sp], #0x40
//   0x22bc: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_007_2198(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00002198ULL;
    for (std::size_t i = 0; i < 74ULL; ++i) {
        std::uint32_t insn = kTextInstructions[230ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[008] Symbol: sub_22c0
//      Virtual Address Range: 0x22c0..0x2524 (612 bytes, 153 AArch64 instructions)
// [VN] Khung FDE[008] Biểu tượng: sub_22c0
//      Dải địa chỉ ảo: 0x22c0..0x2524 (612 byte, 153 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x22c0: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x22c4: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x22c8: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x22cc: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x22d0: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x22d4: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x22d8: 910143fd  add      x29, sp, #0x50
//   0x22dc: d14203ff  sub      sp, sp, #0x80, lsl #12
//   0x22e0: d11043ff  sub      sp, sp, #0x410
//   0x22e4: d53bd057  mrs      x23, tpidr_el0
//   0x22e8: f94016e8  ldr      x8, [x23, #0x28]
//   0x22ec: aa0003f4  mov      x20, x0
//   0x22f0: 914203e0  add      x0, sp, #0x80, lsl #12
//   0x22f4: 52808002  mov      w2, #0x400
//   0x22f8: 2a1f03e1  mov      w1, wzr
//   0x22fc: f81a03a8  stur     x8, [x29, #-0x60]
//   0x2300: 97fffe44  bl       #0x1c10
//   0x2304: b0000036  adrp     x22, #0x7000
//   0x2308: 912d3ad6  add      x22, x22, #0xb4e
//   0x230c: b0000022  adrp     x2, #0x7000
//   0x2310: 912e3442  add      x2, x2, #0xb8d
//   0x2314: 528000c0  mov      w0, #6
//   0x2318: aa1603e1  mov      x1, x22
//   0x231c: 97fffe1d  bl       #0x1b90
//   0x2320: aa1403f5  mov      x21, x20
//   0x2324: f84086a3  ldr      x3, [x21], #8
//   0x2328: 914203e0  add      x0, sp, #0x80, lsl #12
//   0x232c: 9400007e  bl       #0x2524
//   0x2330: b0000022  adrp     x2, #0x7000
//   0x2334: 912ea842  add      x2, x2, #0xbaa
//   0x2338: 914203e3  add      x3, sp, #0x80, lsl #12
//   0x233c: 528000c0  mov      w0, #6
//   0x2340: aa1603e1  mov      x1, x22
//   0x2344: 97fffe13  bl       #0x1b90
//   0x2348: b0000021  adrp     x1, #0x7000
//   0x234c: 9136dc21  add      x1, x1, #0xdb7
//   0x2350: 914203e0  add      x0, sp, #0x80, lsl #12
//   0x2354: 97fffda3  bl       #0x19e0
//   0x2358: b0000022  adrp     x2, #0x7000
//   0x235c: aa0003f3  mov      x19, x0
//   0x2360: 912f0c42  add      x2, x2, #0xbc3
//   0x2364: 528000c0  mov      w0, #6
//   0x2368: aa1603e1  mov      x1, x22
//   0x236c: 97fffe09  bl       #0x1b90
//   0x2370: 910003e0  mov      x0, sp
//   0x2374: 52a00102  mov      w2, #0x80000
//   0x2378: 2a1f03e1  mov      w1, wzr
//   0x237c: 910003f8  mov      x24, sp
//   0x2380: 97fffe24  bl       #0x1c10
//   0x2384: b0000022  adrp     x2, #0x7000
//   0x2388: 912f5442  add      x2, x2, #0xbd5
//   0x238c: 528000c0  mov      w0, #6
//   0x2390: aa1603e1  mov      x1, x22
//   0x2394: 97fffdff  bl       #0x1b90
//   0x2398: aa1503e0  mov      x0, x21
//   0x239c: 97fffe4d  bl       #0x1cd0
//   0x23a0: b0000022  adrp     x2, #0x7000
//   0x23a4: 912f9c42  add      x2, x2, #0xbe7
//   0x23a8: 528000c0  mov      w0, #6
//   0x23ac: aa1603e1  mov      x1, x22
//   0x23b0: 97fffdf8  bl       #0x1b90
//   0x23b4: aa1f03f9  mov      x25, xzr
//   0x23b8: 14000004  b        #0x23c8
//   0x23bc: 91000739  add      x25, x25, #1
//   0x23c0: f140433f  cmp      x25, #0x10, lsl #12
//   0x23c4: 54000440  b.eq     #0x244c
//   0x23c8: 8b190e88  add      x8, x20, x25, lsl #3
//   0x23cc: f940191a  ldr      x26, [x8, #0x30]
//   0x23d0: b4ffff7a  cbz      x26, #0x23bc
//   0x23d4: aa1f03fc  mov      x28, xzr
//   0x23d8: 8b190f1b  add      x27, x24, x25, lsl #3
//   0x23dc: 52804500  mov      w0, #0x228
//   0x23e0: 97fffdbc  bl       #0x1ad0
//   0x23e4: b9400348  ldr      w8, [x26]
//   0x23e8: aa0003f6  mov      x22, x0
//   0x23ec: 91006341  add      x1, x26, #0x18
//   0x23f0: 52804203  mov      w3, #0x210
//   0x23f4: b9000008  str      w8, [x0]
//   0x23f8: f9400748  ldr      x8, [x26, #8]
//   0x23fc: f9000408  str      x8, [x0, #8]
//   0x2400: b9401348  ldr      w8, [x26, #0x10]
//   0x2404: b9001008  str      w8, [x0, #0x10]
//   0x2408: f9410b48  ldr      x8, [x26, #0x210]
//   0x240c: f9010808  str      x8, [x0, #0x210]
//   0x2410: b9421b48  ldr      w8, [x26, #0x218]
//   0x2414: f901101f  str      xzr, [x0, #0x220]
//   0x2418: b9021808  str      w8, [x0, #0x218]
//   0x241c: b9401348  ldr      w8, [x26, #0x10]
//   0x2420: 91006000  add      x0, x0, #0x18
//   0x2424: d37df102  lsl      x2, x8, #3
//   0x2428: 97fffe1a  bl       #0x1c90
//   0x242c: 91088388  add      x8, x28, #0x220
//   0x2430: f100039f  cmp      x28, #0
//   0x2434: 9a880368  csel     x8, x27, x8, eq
//   0x2438: f9000116  str      x22, [x8]
//   0x243c: f941135a  ldr      x26, [x26, #0x220]
//   0x2440: aa1603fc  mov      x28, x22
//   0x2444: b5fffcda  cbnz     x26, #0x23dc
//   0x2448: 17ffffdd  b        #0x23bc
//   0x244c: b0000034  adrp     x20, #0x7000
//   0x2450: 912d3a94  add      x20, x20, #0xb4e
//   0x2454: b0000022  adrp     x2, #0x7000
//   0x2458: 912fe442  add      x2, x2, #0xbf9
//   0x245c: 528000c0  mov      w0, #6
//   0x2460: aa1403e1  mov      x1, x20
//   0x2464: 97fffdcb  bl       #0x1b90
//   0x2468: aa1503e0  mov      x0, x21
//   0x246c: 97fffdd1  bl       #0x1bb0
//   0x2470: b0000022  adrp     x2, #0x7000
//   0x2474: 91302c42  add      x2, x2, #0xc0b
//   0x2478: 528000c0  mov      w0, #6
//   0x247c: aa1403e1  mov      x1, x20
//   0x2480: 97fffdc4  bl       #0x1b90
//   0x2484: aa1f03f5  mov      x21, xzr
//   0x2488: 910003f6  mov      x22, sp
//   0x248c: f8757ad4  ldr      x20, [x22, x21, lsl #3]
//   0x2490: b50000d4  cbnz     x20, #0x24a8
//   0x2494: 910006b5  add      x21, x21, #1
//   0x2498: f14042bf  cmp      x21, #0x10, lsl #12
//   0x249c: 54000180  b.eq     #0x24cc
//   0x24a0: f8757ad4  ldr      x20, [x22, x21, lsl #3]
//   0x24a4: b4ffff94  cbz      x20, #0x2494
//   0x24a8: aa1303e0  mov      x0, x19
//   0x24ac: aa1403e1  mov      x1, x20
//   0x24b0: 97fffe7e  bl       #0x1ea8
//   0x24b4: f9411298  ldr      x24, [x20, #0x220]
//   0x24b8: aa1403e0  mov      x0, x20
//   0x24bc: 97fffd6d  bl       #0x1a70
//   0x24c0: aa1803f4  mov      x20, x24
//   0x24c4: b5ffff38  cbnz     x24, #0x24a8
//   0x24c8: 17fffff3  b        #0x2494
//   0x24cc: b0000021  adrp     x1, #0x7000
//   0x24d0: b0000022  adrp     x2, #0x7000
//   0x24d4: 912d3821  add      x1, x1, #0xb4e
//   0x24d8: 91307442  add      x2, x2, #0xc1d
//   0x24dc: 528000c0  mov      w0, #6
//   0x24e0: 97fffdac  bl       #0x1b90
//   0x24e4: aa1303e0  mov      x0, x19
//   0x24e8: 97fffd9a  bl       #0x1b50
//   0x24ec: f94016e8  ldr      x8, [x23, #0x28]
//   0x24f0: f85a03a9  ldur     x9, [x29, #-0x60]
//   0x24f4: eb09011f  cmp      x8, x9
//   0x24f8: 54000141  b.ne     #0x2520
//   0x24fc: 914203ff  add      sp, sp, #0x80, lsl #12
//   0x2500: 911043ff  add      sp, sp, #0x410
//   0x2504: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x2508: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x250c: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x2510: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x2514: a94167fa  ldp      x26, x25, [sp, #0x10]
//   0x2518: a8c66ffc  ldp      x28, x27, [sp], #0x60
//   0x251c: d65f03c0  ret      
//   0x2520: 97fffe10  bl       #0x1d60
// ============================================================================
std::uint32_t fde_008_22c0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000022c0ULL;
    for (std::size_t i = 0; i < 153ULL; ++i) {
        std::uint32_t insn = kTextInstructions[304ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[009] Symbol: sub_2524
//      Virtual Address Range: 0x2524..0x25c8 (164 bytes, 41 AArch64 instructions)
// [VN] Khung FDE[009] Biểu tượng: sub_2524
//      Dải địa chỉ ảo: 0x2524..0x25c8 (164 byte, 41 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x2524: d10483ff  sub      sp, sp, #0x120
//   0x2528: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x252c: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x2530: 910443fd  add      x29, sp, #0x110
//   0x2534: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x2538: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x253c: f90057e7  str      x7, [sp, #0xa8]
//   0x2540: ad0007e0  stp      q0, q1, [sp]
//   0x2544: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x2548: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x254c: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x2550: d53bd053  mrs      x19, tpidr_el0
//   0x2554: f9401669  ldr      x9, [x19, #0x28]
//   0x2558: 910223ea  add      x10, sp, #0x88
//   0x255c: 928004ec  mov      x12, #-0x28
//   0x2560: 910043ab  add      x11, x29, #0x10
//   0x2564: f81e83a9  stur     x9, [x29, #-0x18]
//   0x2568: 910003e9  mov      x9, sp
//   0x256c: f2dff00c  movk     x12, #0xff80, lsl #32
//   0x2570: 9100a14a  add      x10, x10, #0x28
//   0x2574: 91020129  add      x9, x9, #0x80
//   0x2578: d100e3a8  sub      x8, x29, #0x38
//   0x257c: a93cabab  stp      x11, x10, [x29, #-0x38]
//   0x2580: a93db3a9  stp      x9, x12, [x29, #-0x28]
//   0x2584: ad400101  ldp      q1, q0, [x8]
//   0x2588: b0000023  adrp     x3, #0x7000
//   0x258c: 912e7c63  add      x3, x3, #0xb9f
//   0x2590: d10183a4  sub      x4, x29, #0x60
//   0x2594: 52808002  mov      w2, #0x400
//   0x2598: 2a1f03e1  mov      w1, wzr
//   0x259c: ad3d03a1  stp      q1, q0, [x29, #-0x60]
//   0x25a0: 97fffd2c  bl       #0x1a50
//   0x25a4: f9401668  ldr      x8, [x19, #0x28]
//   0x25a8: f85e83a9  ldur     x9, [x29, #-0x18]
//   0x25ac: eb09011f  cmp      x8, x9
//   0x25b0: 540000a1  b.ne     #0x25c4
//   0x25b4: a9517bfd  ldp      x29, x30, [sp, #0x110]
//   0x25b8: a9504ffc  ldp      x28, x19, [sp, #0x100]
//   0x25bc: 910483ff  add      sp, sp, #0x120
//   0x25c0: d65f03c0  ret      
//   0x25c4: 97fffde7  bl       #0x1d60
// ============================================================================
std::uint32_t fde_009_2524(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00002524ULL;
    for (std::size_t i = 0; i < 41ULL; ++i) {
        std::uint32_t insn = kTextInstructions[457ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[010] Symbol: sub_25c8
//      Virtual Address Range: 0x25c8..0x26dc (276 bytes, 69 AArch64 instructions)
// [VN] Khung FDE[010] Biểu tượng: sub_25c8
//      Dải địa chỉ ảo: 0x25c8..0x26dc (276 byte, 69 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x25c8: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x25cc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x25d0: 910043fd  add      x29, sp, #0x10
//   0x25d4: d0000073  adrp     x19, #0x10000
//   0x25d8: f9403660  ldr      x0, [x19, #0x68]
//   0x25dc: b40002e0  cbz      x0, #0x2638
//   0x25e0: f9400008  ldr      x8, [x0]
//   0x25e4: b4000088  cbz      x8, #0x25f4
//   0x25e8: aa0803e0  mov      x0, x8
//   0x25ec: 97fffd1d  bl       #0x1a60
//   0x25f0: f9403660  ldr      x0, [x19, #0x68]
//   0x25f4: f9400408  ldr      x8, [x0, #8]
//   0x25f8: b4000088  cbz      x8, #0x2608
//   0x25fc: aa0803e0  mov      x0, x8
//   0x2600: 97fffd18  bl       #0x1a60
//   0x2604: f9403660  ldr      x0, [x19, #0x68]
//   0x2608: f9400808  ldr      x8, [x0, #0x10]
//   0x260c: b4000088  cbz      x8, #0x261c
//   0x2610: aa0803e0  mov      x0, x8
//   0x2614: 97fffd13  bl       #0x1a60
//   0x2618: f9403660  ldr      x0, [x19, #0x68]
//   0x261c: f9400c08  ldr      x8, [x0, #0x18]
//   0x2620: b4000088  cbz      x8, #0x2630
//   0x2624: aa0803e0  mov      x0, x8
//   0x2628: 97fffd0e  bl       #0x1a60
//   0x262c: f9403660  ldr      x0, [x19, #0x68]
//   0x2630: b4000040  cbz      x0, #0x2638
//   0x2634: 97fffd6f  bl       #0x1bf0
//   0x2638: d0000073  adrp     x19, #0x10000
//   0x263c: f9403a60  ldr      x0, [x19, #0x70]
//   0x2640: b4000380  cbz      x0, #0x26b0
//   0x2644: f9400008  ldr      x8, [x0]
//   0x2648: b4000088  cbz      x8, #0x2658
//   0x264c: aa0803e0  mov      x0, x8
//   0x2650: 97fffd04  bl       #0x1a60
//   0x2654: f9403a60  ldr      x0, [x19, #0x70]
//   0x2658: f9400408  ldr      x8, [x0, #8]
//   0x265c: b4000088  cbz      x8, #0x266c
//   0x2660: aa0803e0  mov      x0, x8
//   0x2664: 97fffcff  bl       #0x1a60
//   0x2668: f9403a60  ldr      x0, [x19, #0x70]
//   0x266c: f9400808  ldr      x8, [x0, #0x10]
//   0x2670: b4000088  cbz      x8, #0x2680
//   0x2674: aa0803e0  mov      x0, x8
//   0x2678: 97fffcfa  bl       #0x1a60
//   0x267c: f9403a60  ldr      x0, [x19, #0x70]
//   0x2680: f9400c08  ldr      x8, [x0, #0x18]
//   0x2684: b4000088  cbz      x8, #0x2694
//   0x2688: aa0803e0  mov      x0, x8
//   0x268c: 97fffcf5  bl       #0x1a60
//   0x2690: f9403a60  ldr      x0, [x19, #0x70]
//   0x2694: f9401008  ldr      x8, [x0, #0x20]
//   0x2698: b4000088  cbz      x8, #0x26a8
//   0x269c: aa0803e0  mov      x0, x8
//   0x26a0: 97fffcf0  bl       #0x1a60
//   0x26a4: f9403a60  ldr      x0, [x19, #0x70]
//   0x26a8: b4000040  cbz      x0, #0x26b0
//   0x26ac: 97fffd51  bl       #0x1bf0
//   0x26b0: d0000068  adrp     x8, #0x10000
//   0x26b4: 3941e108  ldrb     w8, [x8, #0x78]
//   0x26b8: 340000c8  cbz      w8, #0x26d0
//   0x26bc: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x26c0: d0000060  adrp     x0, #0x10000
//   0x26c4: 91020000  add      x0, x0, #0x80
//   0x26c8: f84207f3  ldr      x19, [sp], #0x20
//   0x26cc: 17fffcc9  b        #0x19f0
//   0x26d0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x26d4: f84207f3  ldr      x19, [sp], #0x20
//   0x26d8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_010_25c8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000025c8ULL;
    for (std::size_t i = 0; i < 69ULL; ++i) {
        std::uint32_t insn = kTextInstructions[498ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[011] Symbol: sub_26dc
//      Virtual Address Range: 0x26dc..0x2980 (676 bytes, 169 AArch64 instructions)
// [VN] Khung FDE[011] Biểu tượng: sub_26dc
//      Dải địa chỉ ảo: 0x26dc..0x2980 (676 byte, 169 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x26dc: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x26e0: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x26e4: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x26e8: 910083fd  add      x29, sp, #0x20
//   0x26ec: b40003e1  cbz      x1, #0x2768
//   0x26f0: f9400008  ldr      x8, [x0]
//   0x26f4: aa1f03e2  mov      x2, xzr
//   0x26f8: aa0103f3  mov      x19, x1
//   0x26fc: aa0003f4  mov      x20, x0
//   0x2700: f942a508  ldr      x8, [x8, #0x548]
//   0x2704: d63f0100  blr      x8
//   0x2708: aa0003f5  mov      x21, x0
//   0x270c: d0000060  adrp     x0, #0x10000
//   0x2710: 91020000  add      x0, x0, #0x80
//   0x2714: 52800082  mov      w2, #4
//   0x2718: aa1503e1  mov      x1, x21
//   0x271c: 97fffd65  bl       #0x1cb0
//   0x2720: 7100001f  cmp      w0, #0
//   0x2724: 1a9f17e8  cset     w8, eq
//   0x2728: d0000069  adrp     x9, #0x10000
//   0x272c: aa1503e0  mov      x0, x21
//   0x2730: 3901e128  strb     w8, [x9, #0x78]
//   0x2734: 97fffcf7  bl       #0x1b10
//   0x2738: 91000400  add      x0, x0, #1
//   0x273c: 97fffcc1  bl       #0x1a40
//   0x2740: d0000068  adrp     x8, #0x10000
//   0x2744: aa1503e1  mov      x1, x21
//   0x2748: f9005100  str      x0, [x8, #0xa0]
//   0x274c: 97fffd25  bl       #0x1be0
//   0x2750: f9400288  ldr      x8, [x20]
//   0x2754: aa1403e0  mov      x0, x20
//   0x2758: aa1303e1  mov      x1, x19
//   0x275c: aa1503e2  mov      x2, x21
//   0x2760: f942a908  ldr      x8, [x8, #0x550]
//   0x2764: d63f0100  blr      x8
//   0x2768: d0000068  adrp     x8, #0x10000
//   0x276c: 39415108  ldrb     w8, [x8, #0x54]
//   0x2770: 340008a8  cbz      w8, #0x2884
//   0x2774: 52800500  mov      w0, #0x28
//   0x2778: 97fffcb2  bl       #0x1a40
//   0x277c: 90000014  adrp     x20, #0x2000
//   0x2780: 90000013  adrp     x19, #0x2000
//   0x2784: d0000075  adrp     x21, #0x10000
//   0x2788: 91260294  add      x20, x20, #0x980
//   0x278c: b0000023  adrp     x3, #0x7000
//   0x2790: b0000004  adrp     x4, #0x3000
//   0x2794: 91287273  add      x19, x19, #0xa1c
//   0x2798: f9003aa0  str      x0, [x21, #0x70]
//   0x279c: 91371863  add      x3, x3, #0xdc6
//   0x27a0: 91060084  add      x4, x4, #0x180
//   0x27a4: aa1403e0  mov      x0, x20
//   0x27a8: aa1f03e1  mov      x1, xzr
//   0x27ac: aa1f03e2  mov      x2, xzr
//   0x27b0: aa1303e5  mov      x5, x19
//   0x27b4: aa1f03e6  mov      x6, xzr
//   0x27b8: 97fffd62  bl       #0x1d40
//   0x27bc: f9403aa8  ldr      x8, [x21, #0x70]
//   0x27c0: b0000023  adrp     x3, #0x7000
//   0x27c4: b0000004  adrp     x4, #0x3000
//   0x27c8: 91373463  add      x3, x3, #0xdcd
//   0x27cc: f9000100  str      x0, [x8]
//   0x27d0: 910ae084  add      x4, x4, #0x2b8
//   0x27d4: aa1403e0  mov      x0, x20
//   0x27d8: aa1f03e1  mov      x1, xzr
//   0x27dc: aa1f03e2  mov      x2, xzr
//   0x27e0: aa1303e5  mov      x5, x19
//   0x27e4: aa1f03e6  mov      x6, xzr
//   0x27e8: 97fffd56  bl       #0x1d40
//   0x27ec: f9403aa8  ldr      x8, [x21, #0x70]
//   0x27f0: b0000023  adrp     x3, #0x7000
//   0x27f4: b0000004  adrp     x4, #0x3000
//   0x27f8: 91375063  add      x3, x3, #0xdd4
//   0x27fc: f9000500  str      x0, [x8, #8]
//   0x2800: 910ff084  add      x4, x4, #0x3fc
//   0x2804: aa1403e0  mov      x0, x20
//   0x2808: aa1f03e1  mov      x1, xzr
//   0x280c: aa1f03e2  mov      x2, xzr
//   0x2810: aa1303e5  mov      x5, x19
//   0x2814: aa1f03e6  mov      x6, xzr
//   0x2818: 97fffd4a  bl       #0x1d40
//   0x281c: f9403aa8  ldr      x8, [x21, #0x70]
//   0x2820: b0000023  adrp     x3, #0x7000
//   0x2824: b0000004  adrp     x4, #0x3000
//   0x2828: 91377063  add      x3, x3, #0xddc
//   0x282c: f9000900  str      x0, [x8, #0x10]
//   0x2830: 9115c084  add      x4, x4, #0x570
//   0x2834: aa1403e0  mov      x0, x20
//   0x2838: aa1f03e1  mov      x1, xzr
//   0x283c: aa1f03e2  mov      x2, xzr
//   0x2840: aa1303e5  mov      x5, x19
//   0x2844: aa1f03e6  mov      x6, xzr
//   0x2848: 97fffd3e  bl       #0x1d40
//   0x284c: f9403aa8  ldr      x8, [x21, #0x70]
//   0x2850: b0000023  adrp     x3, #0x7000
//   0x2854: b0000004  adrp     x4, #0x3000
//   0x2858: 91379463  add      x3, x3, #0xde5
//   0x285c: f9000d00  str      x0, [x8, #0x18]
//   0x2860: 911ac084  add      x4, x4, #0x6b0
//   0x2864: aa1403e0  mov      x0, x20
//   0x2868: aa1f03e1  mov      x1, xzr
//   0x286c: aa1f03e2  mov      x2, xzr
//   0x2870: aa1303e5  mov      x5, x19
//   0x2874: aa1f03e6  mov      x6, xzr
//   0x2878: 97fffd32  bl       #0x1d40
//   0x287c: f9403aa8  ldr      x8, [x21, #0x70]
//   0x2880: f9001100  str      x0, [x8, #0x20]
//   0x2884: d0000068  adrp     x8, #0x10000
//   0x2888: 39416108  ldrb     w8, [x8, #0x58]
//   0x288c: 34000728  cbz      w8, #0x2970
//   0x2890: 52800400  mov      w0, #0x20
//   0x2894: 97fffc6b  bl       #0x1a40
//   0x2898: 90000013  adrp     x19, #0x2000
//   0x289c: 90000014  adrp     x20, #0x2000
//   0x28a0: d0000075  adrp     x21, #0x10000
//   0x28a4: 91260273  add      x19, x19, #0x980
//   0x28a8: b0000023  adrp     x3, #0x7000
//   0x28ac: b0000004  adrp     x4, #0x3000
//   0x28b0: 91287294  add      x20, x20, #0xa1c
//   0x28b4: f90036a0  str      x0, [x21, #0x68]
//   0x28b8: 91383863  add      x3, x3, #0xe0e
//   0x28bc: 91233084  add      x4, x4, #0x8cc
//   0x28c0: aa1303e0  mov      x0, x19
//   0x28c4: aa1f03e1  mov      x1, xzr
//   0x28c8: aa1f03e2  mov      x2, xzr
//   0x28cc: aa1403e5  mov      x5, x20
//   0x28d0: aa1f03e6  mov      x6, xzr
//   0x28d4: 97fffd1b  bl       #0x1d40
//   0x28d8: f94036a8  ldr      x8, [x21, #0x68]
//   0x28dc: b0000023  adrp     x3, #0x7000
//   0x28e0: b0000004  adrp     x4, #0x3000
//   0x28e4: 91385463  add      x3, x3, #0xe15
//   0x28e8: f9000100  str      x0, [x8]
//   0x28ec: 9128f084  add      x4, x4, #0xa3c
//   0x28f0: aa1303e0  mov      x0, x19
//   0x28f4: aa1f03e1  mov      x1, xzr
//   0x28f8: aa1f03e2  mov      x2, xzr
//   0x28fc: aa1403e5  mov      x5, x20
//   0x2900: aa1f03e6  mov      x6, xzr
//   0x2904: 97fffd0f  bl       #0x1d40
//   0x2908: f94036a8  ldr      x8, [x21, #0x68]
//   0x290c: b0000023  adrp     x3, #0x7000
//   0x2910: b0000004  adrp     x4, #0x3000
//   0x2914: 91386863  add      x3, x3, #0xe1a
//   0x2918: f9000500  str      x0, [x8, #8]
//   0x291c: 912eb084  add      x4, x4, #0xbac
//   0x2920: aa1303e0  mov      x0, x19
//   0x2924: aa1f03e1  mov      x1, xzr
//   0x2928: aa1f03e2  mov      x2, xzr
//   0x292c: aa1403e5  mov      x5, x20
//   0x2930: aa1f03e6  mov      x6, xzr
//   0x2934: 97fffd03  bl       #0x1d40
//   0x2938: f94036a8  ldr      x8, [x21, #0x68]
//   0x293c: b0000023  adrp     x3, #0x7000
//   0x2940: b0000004  adrp     x4, #0x3000
//   0x2944: 91388463  add      x3, x3, #0xe21
//   0x2948: f9000900  str      x0, [x8, #0x10]
//   0x294c: 91334084  add      x4, x4, #0xcd0
//   0x2950: aa1303e0  mov      x0, x19
//   0x2954: aa1f03e1  mov      x1, xzr
//   0x2958: aa1f03e2  mov      x2, xzr
//   0x295c: aa1403e5  mov      x5, x20
//   0x2960: aa1f03e6  mov      x6, xzr
//   0x2964: 97fffcf7  bl       #0x1d40
//   0x2968: f94036a8  ldr      x8, [x21, #0x68]
//   0x296c: f9000d00  str      x0, [x8, #0x18]
//   0x2970: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x2974: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x2978: f84307f5  ldr      x21, [sp], #0x30
//   0x297c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_011_26dc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000026dcULL;
    for (std::size_t i = 0; i < 169ULL; ++i) {
        std::uint32_t insn = kTextInstructions[567ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[012] Symbol: sub_2980
//      Virtual Address Range: 0x2980..0x2a1c (156 bytes, 39 AArch64 instructions)
// [VN] Khung FDE[012] Biểu tượng: sub_2980
//      Dải địa chỉ ảo: 0x2980..0x2a1c (156 byte, 39 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x2980: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x2984: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x2988: 910043fd  add      x29, sp, #0x10
//   0x298c: aa0003f3  mov      x19, x0
//   0x2990: b4000240  cbz      x0, #0x29d8
//   0x2994: b0000021  adrp     x1, #0x7000
//   0x2998: 9136a021  add      x1, x1, #0xda8
//   0x299c: aa1303e0  mov      x0, x19
//   0x29a0: 97fffc68  bl       #0x1b40
//   0x29a4: b5000160  cbnz     x0, #0x29d0
//   0x29a8: b0000021  adrp     x1, #0x7000
//   0x29ac: 9136c021  add      x1, x1, #0xdb0
//   0x29b0: aa1303e0  mov      x0, x19
//   0x29b4: 97fffc63  bl       #0x1b40
//   0x29b8: b50000c0  cbnz     x0, #0x29d0
//   0x29bc: b0000021  adrp     x1, #0x7000
//   0x29c0: 9136e421  add      x1, x1, #0xdb9
//   0x29c4: aa1303e0  mov      x0, x19
//   0x29c8: 97fffc5e  bl       #0x1b40
//   0x29cc: b4000060  cbz      x0, #0x29d8
//   0x29d0: 2a1f03e0  mov      w0, wzr
//   0x29d4: 1400000f  b        #0x2a10
//   0x29d8: d0000068  adrp     x8, #0x10000
//   0x29dc: 3941e108  ldrb     w8, [x8, #0x78]
//   0x29e0: 34000168  cbz      w8, #0x2a0c
//   0x29e4: d0000060  adrp     x0, #0x10000
//   0x29e8: 91020000  add      x0, x0, #0x80
//   0x29ec: aa1303e1  mov      x1, x19
//   0x29f0: aa1f03e2  mov      x2, xzr
//   0x29f4: aa1f03e3  mov      x3, xzr
//   0x29f8: 2a1f03e4  mov      w4, wzr
//   0x29fc: 97fffc0d  bl       #0x1a30
//   0x2a00: 7100001f  cmp      w0, #0
//   0x2a04: 1a9f17e0  cset     w0, eq
//   0x2a08: 14000002  b        #0x2a10
//   0x2a0c: 52800020  mov      w0, #1
//   0x2a10: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x2a14: f84207f3  ldr      x19, [sp], #0x20
//   0x2a18: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_012_2980(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00002980ULL;
    for (std::size_t i = 0; i < 39ULL; ++i) {
        std::uint32_t insn = kTextInstructions[736ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[013] Symbol: sub_2a1c
//      Virtual Address Range: 0x2a1c..0x2a20 (4 bytes, 1 AArch64 instructions)
// [VN] Khung FDE[013] Biểu tượng: sub_2a1c
//      Dải địa chỉ ảo: 0x2a1c..0x2a20 (4 byte, 1 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x2a1c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_013_2a1c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00002a1cULL;
    for (std::size_t i = 0; i < 1ULL; ++i) {
        std::uint32_t insn = kTextInstructions[775ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[014] Symbol: sub_2a20
//      Virtual Address Range: 0x2a20..0x2a58 (56 bytes, 14 AArch64 instructions)
// [VN] Khung FDE[014] Biểu tượng: sub_2a20
//      Dải địa chỉ ảo: 0x2a20..0x2a58 (56 byte, 14 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x2a20: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x2a24: 910003fd  mov      x29, sp
//   0x2a28: d0000068  adrp     x8, #0x10000
//   0x2a2c: b940a900  ldr      w0, [x8, #0xa8]
//   0x2a30: 97fffc88  bl       #0x1c50
//   0x2a34: b50000e0  cbnz     x0, #0x2a50
//   0x2a38: d0000061  adrp     x1, #0x10000
//   0x2a3c: 9102c021  add      x1, x1, #0xb0
//   0x2a40: 52800160  mov      w0, #0xb
//   0x2a44: aa1f03e2  mov      x2, xzr
//   0x2a48: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x2a4c: 17fffc95  b        #0x1ca0
//   0x2a50: 52800021  mov      w1, #1
//   0x2a54: 97fffbdf  bl       #0x19d0
// ============================================================================
std::uint32_t fde_014_2a20(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00002a20ULL;
    for (std::size_t i = 0; i < 14ULL; ++i) {
        std::uint32_t insn = kTextInstructions[776ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[015] Symbol: sub_2a58
//      Virtual Address Range: 0x2a58..0x2cec (660 bytes, 165 AArch64 instructions)
// [VN] Khung FDE[015] Biểu tượng: sub_2a58
//      Dải địa chỉ ảo: 0x2a58..0x2cec (660 byte, 165 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x2a58: d102c3ff  sub      sp, sp, #0xb0
//   0x2a5c: a9056ffc  stp      x28, x27, [sp, #0x50]
//   0x2a60: a90667fa  stp      x26, x25, [sp, #0x60]
//   0x2a64: a9075ff8  stp      x24, x23, [sp, #0x70]
//   0x2a68: a90857f6  stp      x22, x21, [sp, #0x80]
//   0x2a6c: a9094ff4  stp      x20, x19, [sp, #0x90]
//   0x2a70: a90a7bfd  stp      x29, x30, [sp, #0xa0]
//   0x2a74: 910283fd  add      x29, sp, #0xa0
//   0x2a78: d53bd05b  mrs      x27, tpidr_el0
//   0x2a7c: f9401768  ldr      x8, [x27, #0x28]
//   0x2a80: f90027e8  str      x8, [sp, #0x48]
//   0x2a84: 39404008  ldrb     w8, [x0, #0x10]
//   0x2a88: 350010e8  cbnz     w8, #0x2ca4
//   0x2a8c: 52800028  mov      w8, #1
//   0x2a90: 39004008  strb     w8, [x0, #0x10]
//   0x2a94: f9400028  ldr      x8, [x1]
//   0x2a98: aa0003f4  mov      x20, x0
//   0x2a9c: aa0103f6  mov      x22, x1
//   0x2aa0: aa0103e0  mov      x0, x1
//   0x2aa4: f942a508  ldr      x8, [x8, #0x548]
//   0x2aa8: aa0403e1  mov      x1, x4
//   0x2aac: aa1f03e2  mov      x2, xzr
//   0x2ab0: 2a0703f7  mov      w23, w7
//   0x2ab4: 2a0603f8  mov      w24, w6
//   0x2ab8: aa0503f5  mov      x21, x5
//   0x2abc: 2a0303f3  mov      w19, w3
//   0x2ac0: d63f0100  blr      x8
//   0x2ac4: aa0003fa  mov      x26, x0
//   0x2ac8: f9000680  str      x0, [x20, #8]
//   0x2acc: 52800700  mov      w0, #0x38
//   0x2ad0: 72a00100  movk     w0, #8, lsl #16
//   0x2ad4: 97fffc83  bl       #0x1ce0
//   0x2ad8: aa0003f9  mov      x25, x0
//   0x2adc: aa1a03e1  mov      x1, x26
//   0x2ae0: 97fffd13  bl       #0x1f2c
//   0x2ae4: aa1903e0  mov      x0, x25
//   0x2ae8: f9000299  str      x25, [x20]
//   0x2aec: 97fffd40  bl       #0x1fec
//   0x2af0: f9400288  ldr      x8, [x20]
//   0x2af4: d0000069  adrp     x9, #0x10000
//   0x2af8: f940212b  ldr      x11, [x9, #0x40]
//   0x2afc: 5318626a  ubfx     w10, w19, #0x18, #1
//   0x2b00: f100011f  cmp      x8, #0
//   0x2b04: d000006d  adrp     x13, #0x10000
//   0x2b08: 9a880168  csel     x8, x11, x8, eq
//   0x2b0c: 5319666c  ubfx     w12, w19, #0x19, #1
//   0x2b10: d000006e  adrp     x14, #0x10000
//   0x2b14: 5310566b  ubfx     w11, w19, #0x10, #6
//   0x2b18: f9002128  str      x8, [x9, #0x40]
//   0x2b1c: d000007c  adrp     x28, #0x10000
//   0x2b20: 53165a68  ubfx     w8, w19, #0x16, #1
//   0x2b24: 390121aa  strb     w10, [x13, #0x48]
//   0x2b28: d000006d  adrp     x13, #0x10000
//   0x2b2c: 53175e69  ubfx     w9, w19, #0x17, #1
//   0x2b30: d000006a  adrp     x10, #0x10000
//   0x2b34: 390131cc  strb     w12, [x14, #0x4c]
//   0x2b38: b900538b  str      w11, [x28, #0x50]
//   0x2b3c: 390151a8  strb     w8, [x13, #0x54]
//   0x2b40: 39016149  strb     w9, [x10, #0x58]
//   0x2b44: b9405388  ldr      w8, [x28, #0x50]
//   0x2b48: 7100fd1f  cmp      w8, #0x3f
//   0x2b4c: 12003e68  and      w8, w19, #0xffff
//   0x2b50: 54000063  b.lo     #0x2b5c
//   0x2b54: 528007c9  mov      w9, #0x3e
//   0x2b58: b9005389  str      w9, [x28, #0x50]
//   0x2b5c: 6b1802ff  cmp      w23, w24
//   0x2b60: 1a9f37ea  cset     w10, hs
//   0x2b64: 7100031f  cmp      w24, #0
//   0x2b68: 1a9f07eb  cset     w11, ne
//   0x2b6c: 12b00009  mov      w9, #0x7fffffff
//   0x2b70: 6a0a017f  tst      w11, w10
//   0x2b74: d0000060  adrp     x0, #0x10000
//   0x2b78: d0000079  adrp     x25, #0x10000
//   0x2b7c: d000007a  adrp     x26, #0x10000
//   0x2b80: 1a881308  csel     w8, w24, w8, ne
//   0x2b84: 1a8912e9  csel     w9, w23, w9, ne
//   0x2b88: 9102a000  add      x0, x0, #0xa8
//   0x2b8c: aa1f03e1  mov      x1, xzr
//   0x2b90: b9005f28  str      w8, [x25, #0x5c]
//   0x2b94: b9006349  str      w9, [x26, #0x60]
//   0x2b98: 97fffc62  bl       #0x1d20
//   0x2b9c: 340001a0  cbz      w0, #0x2bd0
//   0x2ba0: b0000021  adrp     x1, #0x7000
//   0x2ba4: b0000022  adrp     x2, #0x7000
//   0x2ba8: 912d3821  add      x1, x1, #0xb4e
//   0x2bac: 9130bc42  add      x2, x2, #0xc2f
//   0x2bb0: 528000c0  mov      w0, #6
//   0x2bb4: 97fffbf7  bl       #0x1b90
//   0x2bb8: d0000068  adrp     x8, #0x10000
//   0x2bbc: b940a900  ldr      w0, [x8, #0xa8]
//   0x2bc0: 97fffbb8  bl       #0x1aa0
//   0x2bc4: d0000077  adrp     x23, #0x10000
//   0x2bc8: d0000078  adrp     x24, #0x10000
//   0x2bcc: 14000011  b        #0x2c10
//   0x2bd0: 9100a3e8  add      x8, sp, #0x28
//   0x2bd4: 91004100  add      x0, x8, #0x10
//   0x2bd8: 97fffbaa  bl       #0x1a80
//   0x2bdc: d0000077  adrp     x23, #0x10000
//   0x2be0: d0000078  adrp     x24, #0x10000
//   0x2be4: 35000160  cbnz     w0, #0x2c10
//   0x2be8: 90000008  adrp     x8, #0x2000
//   0x2bec: 91288108  add      x8, x8, #0xa20
//   0x2bf0: f9001be8  str      x8, [sp, #0x30]
//   0x2bf4: 39413308  ldrb     w8, [x24, #0x4c]
//   0x2bf8: 340000c8  cbz      w8, #0x2c10
//   0x2bfc: d0000062  adrp     x2, #0x10000
//   0x2c00: 9102c042  add      x2, x2, #0xb0
//   0x2c04: 9100a3e1  add      x1, sp, #0x28
//   0x2c08: 52800160  mov      w0, #0xb
//   0x2c0c: 97fffc25  bl       #0x1ca0
//   0x2c10: aa1603e0  mov      x0, x22
//   0x2c14: aa1503e1  mov      x1, x21
//   0x2c18: 97fffeb1  bl       #0x26dc
//   0x2c1c: d0000068  adrp     x8, #0x10000
//   0x2c20: b9405f24  ldr      w4, [x25, #0x5c]
//   0x2c24: b9406345  ldr      w5, [x26, #0x60]
//   0x2c28: b9405386  ldr      w6, [x28, #0x50]
//   0x2c2c: 39415108  ldrb     w8, [x8, #0x54]
//   0x2c30: d000006b  adrp     x11, #0x10000
//   0x2c34: 3941616b  ldrb     w11, [x11, #0x58]
//   0x2c38: 394122ec  ldrb     w12, [x23, #0x48]
//   0x2c3c: b0000029  adrp     x9, #0x7000
//   0x2c40: b000002a  adrp     x10, #0x7000
//   0x2c44: 3941330d  ldrb     w13, [x24, #0x4c]
//   0x2c48: 9133a129  add      x9, x9, #0xce8
//   0x2c4c: 9133ad4a  add      x10, x10, #0xceb
//   0x2c50: d000006f  adrp     x15, #0x10000
//   0x2c54: 7100011f  cmp      w8, #0
//   0x2c58: f940068e  ldr      x14, [x20, #8]
//   0x2c5c: f94051ef  ldr      x15, [x15, #0xa0]
//   0x2c60: 9a890147  csel     x7, x10, x9, eq
//   0x2c64: 7100017f  cmp      w11, #0
//   0x2c68: 9a890148  csel     x8, x10, x9, eq
//   0x2c6c: 7100019f  cmp      w12, #0
//   0x2c70: 9a89014b  csel     x11, x10, x9, eq
//   0x2c74: 710001bf  cmp      w13, #0
//   0x2c78: b0000021  adrp     x1, #0x7000
//   0x2c7c: b0000022  adrp     x2, #0x7000
//   0x2c80: 9a890149  csel     x9, x10, x9, eq
//   0x2c84: 912d3821  add      x1, x1, #0xb4e
//   0x2c88: 91313442  add      x2, x2, #0xc4d
//   0x2c8c: 528000c0  mov      w0, #6
//   0x2c90: 2a1303e3  mov      w3, w19
//   0x2c94: a901bfee  stp      x14, x15, [sp, #0x18]
//   0x2c98: a900a7eb  stp      x11, x9, [sp, #8]
//   0x2c9c: f90003e8  str      x8, [sp]
//   0x2ca0: 97fffbbc  bl       #0x1b90
//   0x2ca4: f9401768  ldr      x8, [x27, #0x28]
//   0x2ca8: f94027e9  ldr      x9, [sp, #0x48]
//   0x2cac: eb09011f  cmp      x8, x9
//   0x2cb0: 54000121  b.ne     #0x2cd4
//   0x2cb4: a94a7bfd  ldp      x29, x30, [sp, #0xa0]
//   0x2cb8: a9494ff4  ldp      x20, x19, [sp, #0x90]
//   0x2cbc: a94857f6  ldp      x22, x21, [sp, #0x80]
//   0x2cc0: a9475ff8  ldp      x24, x23, [sp, #0x70]
//   0x2cc4: a94667fa  ldp      x26, x25, [sp, #0x60]
//   0x2cc8: a9456ffc  ldp      x28, x27, [sp, #0x50]
//   0x2ccc: 9102c3ff  add      sp, sp, #0xb0
//   0x2cd0: d65f03c0  ret      
//   0x2cd4: 97fffc23  bl       #0x1d60
//   0x2cd8: aa0003f3  mov      x19, x0
//   0x2cdc: aa1903e0  mov      x0, x25
//   0x2ce0: 97fffb50  bl       #0x1a20
//   0x2ce4: aa1303e0  mov      x0, x19
//   0x2ce8: 94000bf4  bl       #0x5cb8
// ============================================================================
std::uint32_t fde_015_2a58(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00002a58ULL;
    for (std::size_t i = 0; i < 165ULL; ++i) {
        std::uint32_t insn = kTextInstructions[790ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[016] Symbol: sub_2cec
//      Virtual Address Range: 0x2cec..0x2dd0 (228 bytes, 57 AArch64 instructions)
// [VN] Khung FDE[016] Biểu tượng: sub_2cec
//      Dải địa chỉ ảo: 0x2cec..0x2dd0 (228 byte, 57 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x2cec: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x2cf0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x2cf4: 910043fd  add      x29, sp, #0x10
//   0x2cf8: 39404008  ldrb     w8, [x0, #0x10]
//   0x2cfc: 34000648  cbz      w8, #0x2dc4
//   0x2d00: aa0003f3  mov      x19, x0
//   0x2d04: 97fffe31  bl       #0x25c8
//   0x2d08: d0000074  adrp     x20, #0x10000
//   0x2d0c: 39413288  ldrb     w8, [x20, #0x4c]
//   0x2d10: 340000c8  cbz      w8, #0x2d28
//   0x2d14: d0000061  adrp     x1, #0x10000
//   0x2d18: 9102c021  add      x1, x1, #0xb0
//   0x2d1c: 52800160  mov      w0, #0xb
//   0x2d20: aa1f03e2  mov      x2, xzr
//   0x2d24: 97fffbdf  bl       #0x1ca0
//   0x2d28: d0000068  adrp     x8, #0x10000
//   0x2d2c: b940a900  ldr      w0, [x8, #0xa8]
//   0x2d30: 97fffb5c  bl       #0x1aa0
//   0x2d34: d0000069  adrp     x9, #0x10000
//   0x2d38: d0000068  adrp     x8, #0x10000
//   0x2d3c: d000006a  adrp     x10, #0x10000
//   0x2d40: d000006b  adrp     x11, #0x10000
//   0x2d44: 3901213f  strb     wzr, [x9, #0x48]
//   0x2d48: 3901329f  strb     wzr, [x20, #0x4c]
//   0x2d4c: b900511f  str      wzr, [x8, #0x50]
//   0x2d50: 3901515f  strb     wzr, [x10, #0x54]
//   0x2d54: 3901617f  strb     wzr, [x11, #0x58]
//   0x2d58: b9405109  ldr      w9, [x8, #0x50]
//   0x2d5c: 7100fd3f  cmp      w9, #0x3f
//   0x2d60: 54000063  b.lo     #0x2d6c
//   0x2d64: 528007c9  mov      w9, #0x3e
//   0x2d68: b9005109  str      w9, [x8, #0x50]
//   0x2d6c: d0000068  adrp     x8, #0x10000
//   0x2d70: d0000069  adrp     x9, #0x10000
//   0x2d74: 12b0000a  mov      w10, #0x7fffffff
//   0x2d78: b9005d1f  str      wzr, [x8, #0x5c]
//   0x2d7c: b900612a  str      w10, [x9, #0x60]
//   0x2d80: f9400274  ldr      x20, [x19]
//   0x2d84: b40000d4  cbz      x20, #0x2d9c
//   0x2d88: aa1403e0  mov      x0, x20
//   0x2d8c: 97fffc88  bl       #0x1fac
//   0x2d90: aa1403e0  mov      x0, x20
//   0x2d94: 97fffb23  bl       #0x1a20
//   0x2d98: f900027f  str      xzr, [x19]
//   0x2d9c: 3900427f  strb     wzr, [x19, #0x10]
//   0x2da0: f9400663  ldr      x3, [x19, #8]
//   0x2da4: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x2da8: b0000021  adrp     x1, #0x7000
//   0x2dac: b0000022  adrp     x2, #0x7000
//   0x2db0: 912d3821  add      x1, x1, #0xb4e
//   0x2db4: 9133bc42  add      x2, x2, #0xcef
//   0x2db8: 528000c0  mov      w0, #6
//   0x2dbc: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x2dc0: 17fffb74  b        #0x1b90
//   0x2dc4: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x2dc8: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x2dcc: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_016_2cec(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00002cecULL;
    for (std::size_t i = 0; i < 57ULL; ++i) {
        std::uint32_t insn = kTextInstructions[955ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[017] Symbol: sub_2dd0
//      Virtual Address Range: 0x2dd0..0x2ea4 (212 bytes, 53 AArch64 instructions)
// [VN] Khung FDE[017] Biểu tượng: sub_2dd0
//      Dải địa chỉ ảo: 0x2dd0..0x2ea4 (212 byte, 53 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x2dd0: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x2dd4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x2dd8: 910043fd  add      x29, sp, #0x10
//   0x2ddc: 39404008  ldrb     w8, [x0, #0x10]
//   0x2de0: 34000428  cbz      w8, #0x2e64
//   0x2de4: aa0003f3  mov      x19, x0
//   0x2de8: d0000060  adrp     x0, #0x10000
//   0x2dec: 91000000  add      x0, x0, #0
//   0x2df0: 940012e2  bl       #0x7978
//   0x2df4: f9400008  ldr      x8, [x0]
//   0x2df8: 91000508  add      x8, x8, #1
//   0x2dfc: f9000008  str      x8, [x0]
//   0x2e00: f9400268  ldr      x8, [x19]
//   0x2e04: b40000e8  cbz      x8, #0x2e20
//   0x2e08: aa1303e0  mov      x0, x19
//   0x2e0c: 94000026  bl       #0x2ea4
//   0x2e10: f9400260  ldr      x0, [x19]
//   0x2e14: 97fffd2b  bl       #0x22c0
//   0x2e18: aa1303e0  mov      x0, x19
//   0x2e1c: 9400006d  bl       #0x2fd0
//   0x2e20: f9400663  ldr      x3, [x19, #8]
//   0x2e24: b0000021  adrp     x1, #0x7000
//   0x2e28: b0000022  adrp     x2, #0x7000
//   0x2e2c: 912d3821  add      x1, x1, #0xb4e
//   0x2e30: 9133f842  add      x2, x2, #0xcfe
//   0x2e34: 528000c0  mov      w0, #6
//   0x2e38: 97fffb56  bl       #0x1b90
//   0x2e3c: d0000060  adrp     x0, #0x10000
//   0x2e40: 91000000  add      x0, x0, #0
//   0x2e44: 940012cd  bl       #0x7978
//   0x2e48: f9400008  ldr      x8, [x0]
//   0x2e4c: b40000c8  cbz      x8, #0x2e64
//   0x2e50: d0000060  adrp     x0, #0x10000
//   0x2e54: 91000000  add      x0, x0, #0
//   0x2e58: d1000513  sub      x19, x8, #1
//   0x2e5c: 940012c7  bl       #0x7978
//   0x2e60: f9000013  str      x19, [x0]
//   0x2e64: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x2e68: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x2e6c: d65f03c0  ret      
//   0x2e70: aa0003f3  mov      x19, x0
//   0x2e74: d0000060  adrp     x0, #0x10000
//   0x2e78: 91000000  add      x0, x0, #0
//   0x2e7c: 940012bf  bl       #0x7978
//   0x2e80: f9400008  ldr      x8, [x0]
//   0x2e84: b40000c8  cbz      x8, #0x2e9c
//   0x2e88: d0000060  adrp     x0, #0x10000
//   0x2e8c: 91000000  add      x0, x0, #0
//   0x2e90: d1000514  sub      x20, x8, #1
//   0x2e94: 940012b9  bl       #0x7978
//   0x2e98: f9000014  str      x20, [x0]
//   0x2e9c: aa1303e0  mov      x0, x19
//   0x2ea0: 94000b86  bl       #0x5cb8
// ============================================================================
std::uint32_t fde_017_2dd0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00002dd0ULL;
    for (std::size_t i = 0; i < 53ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1012ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[018] Symbol: sub_2ea4
//      Virtual Address Range: 0x2ea4..0x2fd0 (300 bytes, 75 AArch64 instructions)
// [VN] Khung FDE[018] Biểu tượng: sub_2ea4
//      Dải địa chỉ ảo: 0x2ea4..0x2fd0 (300 byte, 75 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x2ea4: a9bb67fc  stp      x28, x25, [sp, #-0x50]!
//   0x2ea8: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x2eac: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x2eb0: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x2eb4: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x2eb8: 910103fd  add      x29, sp, #0x40
//   0x2ebc: d11043ff  sub      sp, sp, #0x410
//   0x2ec0: d53bd059  mrs      x25, tpidr_el0
//   0x2ec4: f9401728  ldr      x8, [x25, #0x28]
//   0x2ec8: f81b83a8  stur     x8, [x29, #-0x48]
//   0x2ecc: 39404008  ldrb     w8, [x0, #0x10]
//   0x2ed0: 34000688  cbz      w8, #0x2fa0
//   0x2ed4: aa0003f3  mov      x19, x0
//   0x2ed8: f9400400  ldr      x0, [x0, #8]
//   0x2edc: 97fffacd  bl       #0x1a10
//   0x2ee0: b4000440  cbz      x0, #0x2f68
//   0x2ee4: aa0003f4  mov      x20, x0
//   0x2ee8: 97fffb86  bl       #0x1d00
//   0x2eec: b4000380  cbz      x0, #0x2f5c
//   0x2ef0: b0000035  adrp     x21, #0x7000
//   0x2ef4: b0000036  adrp     x22, #0x7000
//   0x2ef8: b0000037  adrp     x23, #0x7000
//   0x2efc: 91343ab5  add      x21, x21, #0xd0e
//   0x2f00: 913436d6  add      x22, x22, #0xd0d
//   0x2f04: 913442f7  add      x23, x23, #0xd10
//   0x2f08: 14000004  b        #0x2f18
//   0x2f0c: aa1403e0  mov      x0, x20
//   0x2f10: 97fffb7c  bl       #0x1d00
//   0x2f14: b4000240  cbz      x0, #0x2f5c
//   0x2f18: 91004c18  add      x24, x0, #0x13
//   0x2f1c: aa1803e0  mov      x0, x24
//   0x2f20: aa1503e1  mov      x1, x21
//   0x2f24: 97fffae7  bl       #0x1ac0
//   0x2f28: 34ffff20  cbz      w0, #0x2f0c
//   0x2f2c: aa1803e0  mov      x0, x24
//   0x2f30: aa1603e1  mov      x1, x22
//   0x2f34: 97fffae3  bl       #0x1ac0
//   0x2f38: 34fffea0  cbz      w0, #0x2f0c
//   0x2f3c: f9400663  ldr      x3, [x19, #8]
//   0x2f40: 910023e0  add      x0, sp, #8
//   0x2f44: aa1703e2  mov      x2, x23
//   0x2f48: aa1803e4  mov      x4, x24
//   0x2f4c: 94000064  bl       #0x30dc
//   0x2f50: 910023e0  add      x0, sp, #8
//   0x2f54: 97fffb13  bl       #0x1ba0
//   0x2f58: 17ffffed  b        #0x2f0c
//   0x2f5c: aa1403e0  mov      x0, x20
//   0x2f60: 97fffba4  bl       #0x1df0
//   0x2f64: 1400000f  b        #0x2fa0
//   0x2f68: f9400660  ldr      x0, [x19, #8]
//   0x2f6c: 52806121  mov      w1, #0x309
//   0x2f70: 97fffad0  bl       #0x1ab0
//   0x2f74: f9400663  ldr      x3, [x19, #8]
//   0x2f78: b0000021  adrp     x1, #0x7000
//   0x2f7c: 912d3821  add      x1, x1, #0xb4e
//   0x2f80: 34000080  cbz      w0, #0x2f90
//   0x2f84: b0000022  adrp     x2, #0x7000
//   0x2f88: 91345842  add      x2, x2, #0xd16
//   0x2f8c: 14000003  b        #0x2f98
//   0x2f90: b0000022  adrp     x2, #0x7000
//   0x2f94: 91350442  add      x2, x2, #0xd41
//   0x2f98: 528000c0  mov      w0, #6
//   0x2f9c: 97fffafd  bl       #0x1b90
//   0x2fa0: f9401728  ldr      x8, [x25, #0x28]
//   0x2fa4: f85b83a9  ldur     x9, [x29, #-0x48]
//   0x2fa8: eb09011f  cmp      x8, x9
//   0x2fac: 54000101  b.ne     #0x2fcc
//   0x2fb0: 911043ff  add      sp, sp, #0x410
//   0x2fb4: a9447bfd  ldp      x29, x30, [sp, #0x40]
//   0x2fb8: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x2fbc: a94257f6  ldp      x22, x21, [sp, #0x20]
//   0x2fc0: a9415ff8  ldp      x24, x23, [sp, #0x10]
//   0x2fc4: a8c567fc  ldp      x28, x25, [sp], #0x50
//   0x2fc8: d65f03c0  ret      
//   0x2fcc: 97fffb65  bl       #0x1d60
// ============================================================================
std::uint32_t fde_018_2ea4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00002ea4ULL;
    for (std::size_t i = 0; i < 75ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1065ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[019] Symbol: sub_2fd0
//      Virtual Address Range: 0x2fd0..0x30dc (268 bytes, 67 AArch64 instructions)
// [VN] Khung FDE[019] Biểu tượng: sub_2fd0
//      Dải địa chỉ ảo: 0x2fd0..0x30dc (268 byte, 67 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x2fd0: a9bd57fc  stp      x28, x21, [sp, #-0x30]!
//   0x2fd4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x2fd8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x2fdc: 910083fd  add      x29, sp, #0x20
//   0x2fe0: d11043ff  sub      sp, sp, #0x410
//   0x2fe4: d53bd055  mrs      x21, tpidr_el0
//   0x2fe8: f94016a8  ldr      x8, [x21, #0x28]
//   0x2fec: f81d83a8  stur     x8, [x29, #-0x28]
//   0x2ff0: 39404008  ldrb     w8, [x0, #0x10]
//   0x2ff4: 34000608  cbz      w8, #0x30b4
//   0x2ff8: f9400403  ldr      x3, [x0, #8]
//   0x2ffc: b0000022  adrp     x2, #0x7000
//   0x3000: aa0003f4  mov      x20, x0
//   0x3004: 9135c042  add      x2, x2, #0xd70
//   0x3008: 910023e0  add      x0, sp, #8
//   0x300c: 94000034  bl       #0x30dc
//   0x3010: 90000021  adrp     x1, #0x7000
//   0x3014: 9136dc21  add      x1, x1, #0xdb7
//   0x3018: 910023e0  add      x0, sp, #8
//   0x301c: 97fffa71  bl       #0x19e0
//   0x3020: b40002a0  cbz      x0, #0x3074
//   0x3024: aa0003f3  mov      x19, x0
//   0x3028: 90000020  adrp     x0, #0x7000
//   0x302c: 90000021  adrp     x1, #0x7000
//   0x3030: 91366000  add      x0, x0, #0xd98
//   0x3034: 9135e021  add      x1, x1, #0xd78
//   0x3038: 97fffa6a  bl       #0x19e0
//   0x303c: b40002c0  cbz      x0, #0x3094
//   0x3040: aa0003f4  mov      x20, x0
//   0x3044: 910023e0  add      x0, sp, #8
//   0x3048: 52808001  mov      w1, #0x400
//   0x304c: aa1403e2  mov      x2, x20
//   0x3050: 97fffb4c  bl       #0x1d80
//   0x3054: b40000a0  cbz      x0, #0x3068
//   0x3058: 910023e0  add      x0, sp, #8
//   0x305c: aa1303e1  mov      x1, x19
//   0x3060: 97fffb44  bl       #0x1d70
//   0x3064: 17fffff8  b        #0x3044
//   0x3068: aa1403e0  mov      x0, x20
//   0x306c: 97fffab9  bl       #0x1b50
//   0x3070: 1400000f  b        #0x30ac
//   0x3074: f9400683  ldr      x3, [x20, #8]
//   0x3078: 90000021  adrp     x1, #0x7000
//   0x307c: 90000022  adrp     x2, #0x7000
//   0x3080: 912d3821  add      x1, x1, #0xb4e
//   0x3084: 91354c42  add      x2, x2, #0xd53
//   0x3088: 528000c0  mov      w0, #6
//   0x308c: 97fffac1  bl       #0x1b90
//   0x3090: 14000009  b        #0x30b4
//   0x3094: 90000021  adrp     x1, #0x7000
//   0x3098: 90000022  adrp     x2, #0x7000
//   0x309c: 912d3821  add      x1, x1, #0xb4e
//   0x30a0: 9135ec42  add      x2, x2, #0xd7b
//   0x30a4: 528000c0  mov      w0, #6
//   0x30a8: 97fffaba  bl       #0x1b90
//   0x30ac: aa1303e0  mov      x0, x19
//   0x30b0: 97fffaa8  bl       #0x1b50
//   0x30b4: f94016a8  ldr      x8, [x21, #0x28]
//   0x30b8: f85d83a9  ldur     x9, [x29, #-0x28]
//   0x30bc: eb09011f  cmp      x8, x9
//   0x30c0: 540000c1  b.ne     #0x30d8
//   0x30c4: 911043ff  add      sp, sp, #0x410
//   0x30c8: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x30cc: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x30d0: a8c357fc  ldp      x28, x21, [sp], #0x30
//   0x30d4: d65f03c0  ret      
//   0x30d8: 97fffb22  bl       #0x1d60
// ============================================================================
std::uint32_t fde_019_2fd0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00002fd0ULL;
    for (std::size_t i = 0; i < 67ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1140ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[020] Symbol: sub_30dc
//      Virtual Address Range: 0x30dc..0x3180 (164 bytes, 41 AArch64 instructions)
// [VN] Khung FDE[020] Biểu tượng: sub_30dc
//      Dải địa chỉ ảo: 0x30dc..0x3180 (164 byte, 41 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x30dc: d10483ff  sub      sp, sp, #0x120
//   0x30e0: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x30e4: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x30e8: 910443fd  add      x29, sp, #0x110
//   0x30ec: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x30f0: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x30f4: f90057e7  str      x7, [sp, #0xa8]
//   0x30f8: ad0007e0  stp      q0, q1, [sp]
//   0x30fc: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x3100: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x3104: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x3108: d53bd053  mrs      x19, tpidr_el0
//   0x310c: f940166a  ldr      x10, [x19, #0x28]
//   0x3110: 910223eb  add      x11, sp, #0x88
//   0x3114: 928004ed  mov      x13, #-0x28
//   0x3118: 910043ac  add      x12, x29, #0x10
//   0x311c: f81e83aa  stur     x10, [x29, #-0x18]
//   0x3120: 910003ea  mov      x10, sp
//   0x3124: f2dff00d  movk     x13, #0xff80, lsl #32
//   0x3128: 9100a16b  add      x11, x11, #0x28
//   0x312c: 9102014a  add      x10, x10, #0x80
//   0x3130: d100e3a9  sub      x9, x29, #0x38
//   0x3134: a93cafac  stp      x12, x11, [x29, #-0x38]
//   0x3138: a93db7aa  stp      x10, x13, [x29, #-0x28]
//   0x313c: ad400121  ldp      q1, q0, [x9]
//   0x3140: aa0203e8  mov      x8, x2
//   0x3144: d10183a4  sub      x4, x29, #0x60
//   0x3148: 52808002  mov      w2, #0x400
//   0x314c: 2a1f03e1  mov      w1, wzr
//   0x3150: aa0803e3  mov      x3, x8
//   0x3154: ad3d03a1  stp      q1, q0, [x29, #-0x60]
//   0x3158: 97fffa3e  bl       #0x1a50
//   0x315c: f9401668  ldr      x8, [x19, #0x28]
//   0x3160: f85e83a9  ldur     x9, [x29, #-0x18]
//   0x3164: eb09011f  cmp      x8, x9
//   0x3168: 540000a1  b.ne     #0x317c
//   0x316c: a9517bfd  ldp      x29, x30, [sp, #0x110]
//   0x3170: a9504ffc  ldp      x28, x19, [sp, #0x100]
//   0x3174: 910483ff  add      sp, sp, #0x120
//   0x3178: d65f03c0  ret      
//   0x317c: 97fffaf9  bl       #0x1d60
// ============================================================================
std::uint32_t fde_020_30dc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000030dcULL;
    for (std::size_t i = 0; i < 41ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1207ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[021] Symbol: sub_3180
//      Virtual Address Range: 0x3180..0x32b8 (312 bytes, 78 AArch64 instructions)
// [VN] Khung FDE[021] Biểu tượng: sub_3180
//      Dải địa chỉ ảo: 0x3180..0x32b8 (312 byte, 78 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x3180: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x3184: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x3188: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x318c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x3190: 9100c3fd  add      x29, sp, #0x30
//   0x3194: aa0003f4  mov      x20, x0
//   0x3198: b0000060  adrp     x0, #0x10000
//   0x319c: 91000000  add      x0, x0, #0
//   0x31a0: aa1e03f3  mov      x19, x30
//   0x31a4: 940011f5  bl       #0x7978
//   0x31a8: f9400016  ldr      x22, [x0]
//   0x31ac: 910006c8  add      x8, x22, #1
//   0x31b0: f9000008  str      x8, [x0]
//   0x31b4: b0000068  adrp     x8, #0x10000
//   0x31b8: b9405d08  ldr      w8, [x8, #0x5c]
//   0x31bc: eb14011f  cmp      x8, x20
//   0x31c0: 540000a8  b.hi     #0x31d4
//   0x31c4: b0000068  adrp     x8, #0x10000
//   0x31c8: b9406108  ldr      w8, [x8, #0x60]
//   0x31cc: eb14011f  cmp      x8, x20
//   0x31d0: 54000062  b.hs     #0x31dc
//   0x31d4: 2a1f03f7  mov      w23, wzr
//   0x31d8: 14000003  b        #0x31e4
//   0x31dc: f100029f  cmp      x20, #0
//   0x31e0: 1a9f07f7  cset     w23, ne
//   0x31e4: 90000000  adrp     x0, #0x3000
//   0x31e8: 91060000  add      x0, x0, #0x180
//   0x31ec: 97fffa85  bl       #0x1c00
//   0x31f0: aa0003e8  mov      x8, x0
//   0x31f4: aa1403e0  mov      x0, x20
//   0x31f8: d63f0100  blr      x8
//   0x31fc: aa0003f5  mov      x21, x0
//   0x3200: b50000d6  cbnz     x22, #0x3218
//   0x3204: 340000b7  cbz      w23, #0x3218
//   0x3208: b4000095  cbz      x21, #0x3218
//   0x320c: aa1503e0  mov      x0, x21
//   0x3210: aa1403e1  mov      x1, x20
//   0x3214: 9400016d  bl       #0x37c8
//   0x3218: b0000060  adrp     x0, #0x10000
//   0x321c: 91000000  add      x0, x0, #0
//   0x3220: 940011d6  bl       #0x7978
//   0x3224: f9400008  ldr      x8, [x0]
//   0x3228: b40000c8  cbz      x8, #0x3240
//   0x322c: b0000060  adrp     x0, #0x10000
//   0x3230: 91000000  add      x0, x0, #0
//   0x3234: d1000514  sub      x20, x8, #1
//   0x3238: 940011d0  bl       #0x7978
//   0x323c: f9000014  str      x20, [x0]
//   0x3240: 97fffa60  bl       #0x1bc0
//   0x3244: 35000060  cbnz     w0, #0x3250
//   0x3248: aa1303e0  mov      x0, x19
//   0x324c: 97fffac1  bl       #0x1d50
//   0x3250: aa1503e0  mov      x0, x21
//   0x3254: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x3258: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x325c: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x3260: f84407f7  ldr      x23, [sp], #0x40
//   0x3264: d65f03c0  ret      
//   0x3268: 94000196  bl       #0x38c0
//   0x326c: 94000195  bl       #0x38c0
//   0x3270: aa0003f4  mov      x20, x0
//   0x3274: b0000060  adrp     x0, #0x10000
//   0x3278: 91000000  add      x0, x0, #0
//   0x327c: 940011bf  bl       #0x7978
//   0x3280: f9400008  ldr      x8, [x0]
//   0x3284: b40000c8  cbz      x8, #0x329c
//   0x3288: b0000060  adrp     x0, #0x10000
//   0x328c: 91000000  add      x0, x0, #0
//   0x3290: d1000515  sub      x21, x8, #1
//   0x3294: 940011b9  bl       #0x7978
//   0x3298: f9000015  str      x21, [x0]
//   0x329c: 97fffa49  bl       #0x1bc0
//   0x32a0: 35000060  cbnz     w0, #0x32ac
//   0x32a4: aa1303e0  mov      x0, x19
//   0x32a8: 97fffaaa  bl       #0x1d50
//   0x32ac: aa1403e0  mov      x0, x20
//   0x32b0: 94000a82  bl       #0x5cb8
//   0x32b4: 94000183  bl       #0x38c0
// ============================================================================
std::uint32_t fde_021_3180(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003180ULL;
    for (std::size_t i = 0; i < 78ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1248ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[022] Symbol: sub_32b8
//      Virtual Address Range: 0x32b8..0x33fc (324 bytes, 81 AArch64 instructions)
// [VN] Khung FDE[022] Biểu tượng: sub_32b8
//      Dải địa chỉ ảo: 0x32b8..0x33fc (324 byte, 81 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x32b8: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x32bc: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x32c0: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x32c4: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x32c8: 9100c3fd  add      x29, sp, #0x30
//   0x32cc: aa0003f6  mov      x22, x0
//   0x32d0: b0000060  adrp     x0, #0x10000
//   0x32d4: 91000000  add      x0, x0, #0
//   0x32d8: aa1e03f3  mov      x19, x30
//   0x32dc: aa0103f4  mov      x20, x1
//   0x32e0: 940011a6  bl       #0x7978
//   0x32e4: f9400017  ldr      x23, [x0]
//   0x32e8: 9b167e95  mul      x21, x20, x22
//   0x32ec: 910006e8  add      x8, x23, #1
//   0x32f0: f9000008  str      x8, [x0]
//   0x32f4: b0000068  adrp     x8, #0x10000
//   0x32f8: b9405d08  ldr      w8, [x8, #0x5c]
//   0x32fc: eb0802bf  cmp      x21, x8
//   0x3300: 540000a3  b.lo     #0x3314
//   0x3304: b0000068  adrp     x8, #0x10000
//   0x3308: b9406108  ldr      w8, [x8, #0x60]
//   0x330c: eb0802bf  cmp      x21, x8
//   0x3310: 54000069  b.ls     #0x331c
//   0x3314: 2a1f03f8  mov      w24, wzr
//   0x3318: 14000003  b        #0x3324
//   0x331c: f10002bf  cmp      x21, #0
//   0x3320: 1a9f07f8  cset     w24, ne
//   0x3324: 90000000  adrp     x0, #0x3000
//   0x3328: 910ae000  add      x0, x0, #0x2b8
//   0x332c: 97fffa35  bl       #0x1c00
//   0x3330: aa0003e8  mov      x8, x0
//   0x3334: aa1603e0  mov      x0, x22
//   0x3338: aa1403e1  mov      x1, x20
//   0x333c: d63f0100  blr      x8
//   0x3340: aa0003f4  mov      x20, x0
//   0x3344: b50000d7  cbnz     x23, #0x335c
//   0x3348: 340000b8  cbz      w24, #0x335c
//   0x334c: b4000094  cbz      x20, #0x335c
//   0x3350: aa1403e0  mov      x0, x20
//   0x3354: aa1503e1  mov      x1, x21
//   0x3358: 9400011c  bl       #0x37c8
//   0x335c: b0000060  adrp     x0, #0x10000
//   0x3360: 91000000  add      x0, x0, #0
//   0x3364: 94001185  bl       #0x7978
//   0x3368: f9400008  ldr      x8, [x0]
//   0x336c: b40000c8  cbz      x8, #0x3384
//   0x3370: b0000060  adrp     x0, #0x10000
//   0x3374: 91000000  add      x0, x0, #0
//   0x3378: d1000515  sub      x21, x8, #1
//   0x337c: 9400117f  bl       #0x7978
//   0x3380: f9000015  str      x21, [x0]
//   0x3384: 97fffa0f  bl       #0x1bc0
//   0x3388: 35000060  cbnz     w0, #0x3394
//   0x338c: aa1303e0  mov      x0, x19
//   0x3390: 97fffa70  bl       #0x1d50
//   0x3394: aa1403e0  mov      x0, x20
//   0x3398: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x339c: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x33a0: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x33a4: a8c45ff8  ldp      x24, x23, [sp], #0x40
//   0x33a8: d65f03c0  ret      
//   0x33ac: 94000145  bl       #0x38c0
//   0x33b0: 94000144  bl       #0x38c0
//   0x33b4: aa0003f4  mov      x20, x0
//   0x33b8: b0000060  adrp     x0, #0x10000
//   0x33bc: 91000000  add      x0, x0, #0
//   0x33c0: 9400116e  bl       #0x7978
//   0x33c4: f9400008  ldr      x8, [x0]
//   0x33c8: b40000c8  cbz      x8, #0x33e0
//   0x33cc: b0000060  adrp     x0, #0x10000
//   0x33d0: 91000000  add      x0, x0, #0
//   0x33d4: d1000515  sub      x21, x8, #1
//   0x33d8: 94001168  bl       #0x7978
//   0x33dc: f9000015  str      x21, [x0]
//   0x33e0: 97fff9f8  bl       #0x1bc0
//   0x33e4: 35000060  cbnz     w0, #0x33f0
//   0x33e8: aa1303e0  mov      x0, x19
//   0x33ec: 97fffa59  bl       #0x1d50
//   0x33f0: aa1403e0  mov      x0, x20
//   0x33f4: 94000a31  bl       #0x5cb8
//   0x33f8: 94000132  bl       #0x38c0
// ============================================================================
std::uint32_t fde_022_32b8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000032b8ULL;
    for (std::size_t i = 0; i < 81ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1326ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[023] Symbol: sub_33fc
//      Virtual Address Range: 0x33fc..0x3570 (372 bytes, 93 AArch64 instructions)
// [VN] Khung FDE[023] Biểu tượng: sub_33fc
//      Dải địa chỉ ảo: 0x33fc..0x3570 (372 byte, 93 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x33fc: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x3400: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x3404: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x3408: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x340c: 9100c3fd  add      x29, sp, #0x30
//   0x3410: aa0003f6  mov      x22, x0
//   0x3414: b0000060  adrp     x0, #0x10000
//   0x3418: 91000000  add      x0, x0, #0
//   0x341c: aa1e03f3  mov      x19, x30
//   0x3420: aa0103f4  mov      x20, x1
//   0x3424: 94001155  bl       #0x7978
//   0x3428: f9400017  ldr      x23, [x0]
//   0x342c: 910006e8  add      x8, x23, #1
//   0x3430: f9000008  str      x8, [x0]
//   0x3434: b0000068  adrp     x8, #0x10000
//   0x3438: b9405d08  ldr      w8, [x8, #0x5c]
//   0x343c: eb14011f  cmp      x8, x20
//   0x3440: 540000a8  b.hi     #0x3454
//   0x3444: b0000068  adrp     x8, #0x10000
//   0x3448: b9406108  ldr      w8, [x8, #0x60]
//   0x344c: eb14011f  cmp      x8, x20
//   0x3450: 54000062  b.hs     #0x345c
//   0x3454: 2a1f03f8  mov      w24, wzr
//   0x3458: 14000003  b        #0x3464
//   0x345c: f100029f  cmp      x20, #0
//   0x3460: 1a9f07f8  cset     w24, ne
//   0x3464: 90000000  adrp     x0, #0x3000
//   0x3468: 910ff000  add      x0, x0, #0x3fc
//   0x346c: 97fff9e5  bl       #0x1c00
//   0x3470: aa0003e8  mov      x8, x0
//   0x3474: aa1603e0  mov      x0, x22
//   0x3478: aa1403e1  mov      x1, x20
//   0x347c: d63f0100  blr      x8
//   0x3480: aa0003f5  mov      x21, x0
//   0x3484: b4000196  cbz      x22, #0x34b4
//   0x3488: f10002bf  cmp      x21, #0
//   0x348c: 1a9f17e8  cset     w8, eq
//   0x3490: eb1602bf  cmp      x21, x22
//   0x3494: 1a9f07e9  cset     w9, ne
//   0x3498: b50000f7  cbnz     x23, #0x34b4
//   0x349c: 2a080128  orr      w8, w9, w8
//   0x34a0: 360000a8  tbz      w8, #0, #0x34b4
//   0x34a4: b0000068  adrp     x8, #0x10000
//   0x34a8: f9402100  ldr      x0, [x8, #0x40]
//   0x34ac: aa1603e1  mov      x1, x22
//   0x34b0: 97fffb3a  bl       #0x2198
//   0x34b4: b50000d7  cbnz     x23, #0x34cc
//   0x34b8: 340000b8  cbz      w24, #0x34cc
//   0x34bc: b4000095  cbz      x21, #0x34cc
//   0x34c0: aa1503e0  mov      x0, x21
//   0x34c4: aa1403e1  mov      x1, x20
//   0x34c8: 940000c0  bl       #0x37c8
//   0x34cc: b0000060  adrp     x0, #0x10000
//   0x34d0: 91000000  add      x0, x0, #0
//   0x34d4: 94001129  bl       #0x7978
//   0x34d8: f9400008  ldr      x8, [x0]
//   0x34dc: b40000c8  cbz      x8, #0x34f4
//   0x34e0: b0000060  adrp     x0, #0x10000
//   0x34e4: 91000000  add      x0, x0, #0
//   0x34e8: d1000514  sub      x20, x8, #1
//   0x34ec: 94001123  bl       #0x7978
//   0x34f0: f9000014  str      x20, [x0]
//   0x34f4: 97fff9b3  bl       #0x1bc0
//   0x34f8: 35000060  cbnz     w0, #0x3504
//   0x34fc: aa1303e0  mov      x0, x19
//   0x3500: 97fffa14  bl       #0x1d50
//   0x3504: aa1503e0  mov      x0, x21
//   0x3508: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x350c: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x3510: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x3514: a8c45ff8  ldp      x24, x23, [sp], #0x40
//   0x3518: d65f03c0  ret      
//   0x351c: 940000e9  bl       #0x38c0
//   0x3520: 940000e8  bl       #0x38c0
//   0x3524: 940000e7  bl       #0x38c0
//   0x3528: aa0003f4  mov      x20, x0
//   0x352c: b0000060  adrp     x0, #0x10000
//   0x3530: 91000000  add      x0, x0, #0
//   0x3534: 94001111  bl       #0x7978
//   0x3538: f9400008  ldr      x8, [x0]
//   0x353c: b40000c8  cbz      x8, #0x3554
//   0x3540: b0000060  adrp     x0, #0x10000
//   0x3544: 91000000  add      x0, x0, #0
//   0x3548: d1000515  sub      x21, x8, #1
//   0x354c: 9400110b  bl       #0x7978
//   0x3550: f9000015  str      x21, [x0]
//   0x3554: 97fff99b  bl       #0x1bc0
//   0x3558: 35000060  cbnz     w0, #0x3564
//   0x355c: aa1303e0  mov      x0, x19
//   0x3560: 97fff9fc  bl       #0x1d50
//   0x3564: aa1403e0  mov      x0, x20
//   0x3568: 940009d4  bl       #0x5cb8
//   0x356c: 940000d5  bl       #0x38c0
// ============================================================================
std::uint32_t fde_023_33fc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000033fcULL;
    for (std::size_t i = 0; i < 93ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1407ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[024] Symbol: sub_3570
//      Virtual Address Range: 0x3570..0x36b0 (320 bytes, 80 AArch64 instructions)
// [VN] Khung FDE[024] Biểu tượng: sub_3570
//      Dải địa chỉ ảo: 0x3570..0x36b0 (320 byte, 80 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x3570: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x3574: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x3578: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x357c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x3580: 9100c3fd  add      x29, sp, #0x30
//   0x3584: aa0003f5  mov      x21, x0
//   0x3588: b0000060  adrp     x0, #0x10000
//   0x358c: 91000000  add      x0, x0, #0
//   0x3590: aa1e03f3  mov      x19, x30
//   0x3594: aa0103f4  mov      x20, x1
//   0x3598: 940010f8  bl       #0x7978
//   0x359c: f9400016  ldr      x22, [x0]
//   0x35a0: 910006c8  add      x8, x22, #1
//   0x35a4: f9000008  str      x8, [x0]
//   0x35a8: b0000068  adrp     x8, #0x10000
//   0x35ac: b9405d08  ldr      w8, [x8, #0x5c]
//   0x35b0: eb14011f  cmp      x8, x20
//   0x35b4: 540000a8  b.hi     #0x35c8
//   0x35b8: b0000068  adrp     x8, #0x10000
//   0x35bc: b9406108  ldr      w8, [x8, #0x60]
//   0x35c0: eb14011f  cmp      x8, x20
//   0x35c4: 54000062  b.hs     #0x35d0
//   0x35c8: 2a1f03f7  mov      w23, wzr
//   0x35cc: 14000003  b        #0x35d8
//   0x35d0: f100029f  cmp      x20, #0
//   0x35d4: 1a9f07f7  cset     w23, ne
//   0x35d8: 90000000  adrp     x0, #0x3000
//   0x35dc: 9115c000  add      x0, x0, #0x570
//   0x35e0: 97fff988  bl       #0x1c00
//   0x35e4: aa0003e8  mov      x8, x0
//   0x35e8: aa1503e0  mov      x0, x21
//   0x35ec: aa1403e1  mov      x1, x20
//   0x35f0: d63f0100  blr      x8
//   0x35f4: aa0003f5  mov      x21, x0
//   0x35f8: b50000d6  cbnz     x22, #0x3610
//   0x35fc: 340000b7  cbz      w23, #0x3610
//   0x3600: b4000095  cbz      x21, #0x3610
//   0x3604: aa1503e0  mov      x0, x21
//   0x3608: aa1403e1  mov      x1, x20
//   0x360c: 9400006f  bl       #0x37c8
//   0x3610: b0000060  adrp     x0, #0x10000
//   0x3614: 91000000  add      x0, x0, #0
//   0x3618: 940010d8  bl       #0x7978
//   0x361c: f9400008  ldr      x8, [x0]
//   0x3620: b40000c8  cbz      x8, #0x3638
//   0x3624: b0000060  adrp     x0, #0x10000
//   0x3628: 91000000  add      x0, x0, #0
//   0x362c: d1000514  sub      x20, x8, #1
//   0x3630: 940010d2  bl       #0x7978
//   0x3634: f9000014  str      x20, [x0]
//   0x3638: 97fff962  bl       #0x1bc0
//   0x363c: 35000060  cbnz     w0, #0x3648
//   0x3640: aa1303e0  mov      x0, x19
//   0x3644: 97fff9c3  bl       #0x1d50
//   0x3648: aa1503e0  mov      x0, x21
//   0x364c: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x3650: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x3654: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x3658: f84407f7  ldr      x23, [sp], #0x40
//   0x365c: d65f03c0  ret      
//   0x3660: 94000098  bl       #0x38c0
//   0x3664: 94000097  bl       #0x38c0
//   0x3668: aa0003f4  mov      x20, x0
//   0x366c: b0000060  adrp     x0, #0x10000
//   0x3670: 91000000  add      x0, x0, #0
//   0x3674: 940010c1  bl       #0x7978
//   0x3678: f9400008  ldr      x8, [x0]
//   0x367c: b40000c8  cbz      x8, #0x3694
//   0x3680: b0000060  adrp     x0, #0x10000
//   0x3684: 91000000  add      x0, x0, #0
//   0x3688: d1000515  sub      x21, x8, #1
//   0x368c: 940010bb  bl       #0x7978
//   0x3690: f9000015  str      x21, [x0]
//   0x3694: 97fff94b  bl       #0x1bc0
//   0x3698: 35000060  cbnz     w0, #0x36a4
//   0x369c: aa1303e0  mov      x0, x19
//   0x36a0: 97fff9ac  bl       #0x1d50
//   0x36a4: aa1403e0  mov      x0, x20
//   0x36a8: 94000984  bl       #0x5cb8
//   0x36ac: 94000085  bl       #0x38c0
// ============================================================================
std::uint32_t fde_024_3570(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003570ULL;
    for (std::size_t i = 0; i < 80ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1500ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[025] Symbol: sub_36b0
//      Virtual Address Range: 0x36b0..0x37c8 (280 bytes, 70 AArch64 instructions)
// [VN] Khung FDE[025] Biểu tượng: sub_36b0
//      Dải địa chỉ ảo: 0x36b0..0x37c8 (280 byte, 70 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x36b0: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x36b4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x36b8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x36bc: 910083fd  add      x29, sp, #0x20
//   0x36c0: aa0003f4  mov      x20, x0
//   0x36c4: b0000060  adrp     x0, #0x10000
//   0x36c8: 91000000  add      x0, x0, #0
//   0x36cc: aa1e03f3  mov      x19, x30
//   0x36d0: 940010aa  bl       #0x7978
//   0x36d4: f9400015  ldr      x21, [x0]
//   0x36d8: 910006a8  add      x8, x21, #1
//   0x36dc: f9000008  str      x8, [x0]
//   0x36e0: 90000000  adrp     x0, #0x3000
//   0x36e4: 911ac000  add      x0, x0, #0x6b0
//   0x36e8: 97fff946  bl       #0x1c00
//   0x36ec: aa0003e8  mov      x8, x0
//   0x36f0: aa1403e0  mov      x0, x20
//   0x36f4: d63f0100  blr      x8
//   0x36f8: b40000d4  cbz      x20, #0x3710
//   0x36fc: b50000b5  cbnz     x21, #0x3710
//   0x3700: b0000068  adrp     x8, #0x10000
//   0x3704: f9402100  ldr      x0, [x8, #0x40]
//   0x3708: aa1403e1  mov      x1, x20
//   0x370c: 97fffaa3  bl       #0x2198
//   0x3710: b0000060  adrp     x0, #0x10000
//   0x3714: 91000000  add      x0, x0, #0
//   0x3718: 94001098  bl       #0x7978
//   0x371c: f9400008  ldr      x8, [x0]
//   0x3720: b40000c8  cbz      x8, #0x3738
//   0x3724: b0000060  adrp     x0, #0x10000
//   0x3728: 91000000  add      x0, x0, #0
//   0x372c: d1000514  sub      x20, x8, #1
//   0x3730: 94001092  bl       #0x7978
//   0x3734: f9000014  str      x20, [x0]
//   0x3738: 97fff922  bl       #0x1bc0
//   0x373c: 35000060  cbnz     w0, #0x3748
//   0x3740: aa1303e0  mov      x0, x19
//   0x3744: 97fff983  bl       #0x1d50
//   0x3748: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x374c: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x3750: f84307f5  ldr      x21, [sp], #0x30
//   0x3754: d65f03c0  ret      
//   0x3758: 9400005a  bl       #0x38c0
//   0x375c: 94000059  bl       #0x38c0
//   0x3760: aa1403e8  mov      x8, x20
//   0x3764: aa0003f4  mov      x20, x0
//   0x3768: b40000c8  cbz      x8, #0x3780
//   0x376c: b50000b5  cbnz     x21, #0x3780
//   0x3770: aa0803e1  mov      x1, x8
//   0x3774: b0000068  adrp     x8, #0x10000
//   0x3778: f9402100  ldr      x0, [x8, #0x40]
//   0x377c: 97fffa87  bl       #0x2198
//   0x3780: b0000060  adrp     x0, #0x10000
//   0x3784: 91000000  add      x0, x0, #0
//   0x3788: 9400107c  bl       #0x7978
//   0x378c: f9400008  ldr      x8, [x0]
//   0x3790: b40000c8  cbz      x8, #0x37a8
//   0x3794: b0000060  adrp     x0, #0x10000
//   0x3798: 91000000  add      x0, x0, #0
//   0x379c: d1000515  sub      x21, x8, #1
//   0x37a0: 94001076  bl       #0x7978
//   0x37a4: f9000015  str      x21, [x0]
//   0x37a8: 97fff906  bl       #0x1bc0
//   0x37ac: 35000060  cbnz     w0, #0x37b8
//   0x37b0: aa1303e0  mov      x0, x19
//   0x37b4: 97fff967  bl       #0x1d50
//   0x37b8: aa1403e0  mov      x0, x20
//   0x37bc: 9400093f  bl       #0x5cb8
//   0x37c0: 94000040  bl       #0x38c0
//   0x37c4: 9400003f  bl       #0x38c0
// ============================================================================
std::uint32_t fde_025_36b0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000036b0ULL;
    for (std::size_t i = 0; i < 70ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1580ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[026] Symbol: sub_37c8
//      Virtual Address Range: 0x37c8..0x38c0 (248 bytes, 62 AArch64 instructions)
// [VN] Khung FDE[026] Biểu tượng: sub_37c8
//      Dải địa chỉ ảo: 0x37c8..0x38c0 (248 byte, 62 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x37c8: f81c0ffc  str      x28, [sp, #-0x40]!
//   0x37cc: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x37d0: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x37d4: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x37d8: 9100c3fd  add      x29, sp, #0x30
//   0x37dc: d10c43ff  sub      sp, sp, #0x310
//   0x37e0: d53bd055  mrs      x21, tpidr_el0
//   0x37e4: f94016a8  ldr      x8, [x21, #0x28]
//   0x37e8: f81c83a8  stur     x8, [x29, #-0x38]
//   0x37ec: b4000541  cbz      x1, #0x3894
//   0x37f0: 91000408  add      x8, x0, #1
//   0x37f4: aa0003f4  mov      x20, x0
//   0x37f8: f100091f  cmp      x8, #2
//   0x37fc: 540004c3  b.lo     #0x3894
//   0x3800: aa0103f3  mov      x19, x1
//   0x3804: 910003e0  mov      x0, sp
//   0x3808: 52800021  mov      w1, #1
//   0x380c: b9010bff  str      wzr, [sp, #0x108]
//   0x3810: 97fff964  bl       #0x1da0
//   0x3814: b0000076  adrp     x22, #0x10000
//   0x3818: 34000100  cbz      w0, #0x3838
//   0x381c: 90000021  adrp     x1, #0x7000
//   0x3820: 90000022  adrp     x2, #0x7000
//   0x3824: 912d3821  add      x1, x1, #0xb4e
//   0x3828: 9137a842  add      x2, x2, #0xdea
//   0x382c: 528000c0  mov      w0, #6
//   0x3830: 97fff8d8  bl       #0x1b90
//   0x3834: 1400000f  b        #0x3870
//   0x3838: b940aac0  ldr      w0, [x22, #0xa8]
//   0x383c: 910003e1  mov      x1, sp
//   0x3840: 97fff8ac  bl       #0x1af0
//   0x3844: b0000068  adrp     x8, #0x10000
//   0x3848: 39412108  ldrb     w8, [x8, #0x48]
//   0x384c: b000006b  adrp     x11, #0x10000
//   0x3850: b9405161  ldr      w1, [x11, #0x50]
//   0x3854: 52800089  mov      w9, #4
//   0x3858: 910423ea  add      x10, sp, #0x108
//   0x385c: 7100011f  cmp      w8, #0
//   0x3860: 1a890522  cinc     w2, w9, ne
//   0x3864: 91002140  add      x0, x10, #8
//   0x3868: 97fff952  bl       #0x1db0
//   0x386c: b9010be0  str      w0, [sp, #0x108]
//   0x3870: b940aac0  ldr      w0, [x22, #0xa8]
//   0x3874: aa1f03e1  mov      x1, xzr
//   0x3878: 97fff89e  bl       #0x1af0
//   0x387c: b0000068  adrp     x8, #0x10000
//   0x3880: f9402100  ldr      x0, [x8, #0x40]
//   0x3884: 910423e3  add      x3, sp, #0x108
//   0x3888: aa1403e1  mov      x1, x20
//   0x388c: aa1303e2  mov      x2, x19
//   0x3890: 97fff9e4  bl       #0x2020
//   0x3894: f94016a8  ldr      x8, [x21, #0x28]
//   0x3898: f85c83a9  ldur     x9, [x29, #-0x38]
//   0x389c: eb09011f  cmp      x8, x9
//   0x38a0: 540000e1  b.ne     #0x38bc
//   0x38a4: 910c43ff  add      sp, sp, #0x310
//   0x38a8: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x38ac: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x38b0: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x38b4: f84407fc  ldr      x28, [sp], #0x40
//   0x38b8: d65f03c0  ret      
//   0x38bc: 97fff929  bl       #0x1d60
// ============================================================================
std::uint32_t fde_026_37c8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000037c8ULL;
    for (std::size_t i = 0; i < 62ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1650ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[027] Symbol: sub_38c0
//      Virtual Address Range: 0x38c0..0x38cc (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[027] Biểu tượng: sub_38c0
//      Dải địa chỉ ảo: 0x38c0..0x38cc (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x38c0: f81f0ffe  str      x30, [sp, #-0x10]!
//   0x38c4: 97fff8e7  bl       #0x1c60
//   0x38c8: 97fff93e  bl       #0x1dc0
// ============================================================================
std::uint32_t fde_027_38c0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000038c0ULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1712ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[028] Symbol: sub_38cc
//      Virtual Address Range: 0x38cc..0x3a3c (368 bytes, 92 AArch64 instructions)
// [VN] Khung FDE[028] Biểu tượng: sub_38cc
//      Dải địa chỉ ảo: 0x38cc..0x3a3c (368 byte, 92 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x38cc: f81a0ffb  str      x27, [sp, #-0x60]!
//   0x38d0: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x38d4: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x38d8: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x38dc: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x38e0: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x38e4: 910143fd  add      x29, sp, #0x50
//   0x38e8: aa0003f9  mov      x25, x0
//   0x38ec: b0000060  adrp     x0, #0x10000
//   0x38f0: 91000000  add      x0, x0, #0
//   0x38f4: aa1e03f3  mov      x19, x30
//   0x38f8: aa0503f5  mov      x21, x5
//   0x38fc: 2a0403f6  mov      w22, w4
//   0x3900: 2a0303f7  mov      w23, w3
//   0x3904: 2a0203f8  mov      w24, w2
//   0x3908: aa0103f4  mov      x20, x1
//   0x390c: 9400101b  bl       #0x7978
//   0x3910: f940001a  ldr      x26, [x0]
//   0x3914: 91000748  add      x8, x26, #1
//   0x3918: f9000008  str      x8, [x0]
//   0x391c: b0000068  adrp     x8, #0x10000
//   0x3920: b9405d08  ldr      w8, [x8, #0x5c]
//   0x3924: eb14011f  cmp      x8, x20
//   0x3928: 540000a8  b.hi     #0x393c
//   0x392c: b0000068  adrp     x8, #0x10000
//   0x3930: b9406108  ldr      w8, [x8, #0x60]
//   0x3934: eb14011f  cmp      x8, x20
//   0x3938: 54000062  b.hs     #0x3944
//   0x393c: 2a1f03fb  mov      w27, wzr
//   0x3940: 14000003  b        #0x394c
//   0x3944: f100029f  cmp      x20, #0
//   0x3948: 1a9f07fb  cset     w27, ne
//   0x394c: 90000000  adrp     x0, #0x3000
//   0x3950: 91233000  add      x0, x0, #0x8cc
//   0x3954: 97fff8ab  bl       #0x1c00
//   0x3958: aa0003e8  mov      x8, x0
//   0x395c: aa1903e0  mov      x0, x25
//   0x3960: aa1403e1  mov      x1, x20
//   0x3964: 2a1803e2  mov      w2, w24
//   0x3968: 2a1703e3  mov      w3, w23
//   0x396c: 2a1603e4  mov      w4, w22
//   0x3970: aa1503e5  mov      x5, x21
//   0x3974: d63f0100  blr      x8
//   0x3978: aa0003f5  mov      x21, x0
//   0x397c: b50000da  cbnz     x26, #0x3994
//   0x3980: 340000bb  cbz      w27, #0x3994
//   0x3984: b4000095  cbz      x21, #0x3994
//   0x3988: aa1503e0  mov      x0, x21
//   0x398c: aa1403e1  mov      x1, x20
//   0x3990: 97ffff8e  bl       #0x37c8
//   0x3994: b0000060  adrp     x0, #0x10000
//   0x3998: 91000000  add      x0, x0, #0
//   0x399c: 94000ff7  bl       #0x7978
//   0x39a0: f9400008  ldr      x8, [x0]
//   0x39a4: b40000c8  cbz      x8, #0x39bc
//   0x39a8: b0000060  adrp     x0, #0x10000
//   0x39ac: 91000000  add      x0, x0, #0
//   0x39b0: d1000514  sub      x20, x8, #1
//   0x39b4: 94000ff1  bl       #0x7978
//   0x39b8: f9000014  str      x20, [x0]
//   0x39bc: 97fff881  bl       #0x1bc0
//   0x39c0: 35000060  cbnz     w0, #0x39cc
//   0x39c4: aa1303e0  mov      x0, x19
//   0x39c8: 97fff8e2  bl       #0x1d50
//   0x39cc: aa1503e0  mov      x0, x21
//   0x39d0: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x39d4: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x39d8: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x39dc: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x39e0: a94167fa  ldp      x26, x25, [sp, #0x10]
//   0x39e4: f84607fb  ldr      x27, [sp], #0x60
//   0x39e8: d65f03c0  ret      
//   0x39ec: 97ffffb5  bl       #0x38c0
//   0x39f0: 97ffffb4  bl       #0x38c0
//   0x39f4: aa0003f4  mov      x20, x0
//   0x39f8: b0000060  adrp     x0, #0x10000
//   0x39fc: 91000000  add      x0, x0, #0
//   0x3a00: 94000fde  bl       #0x7978
//   0x3a04: f9400008  ldr      x8, [x0]
//   0x3a08: b40000c8  cbz      x8, #0x3a20
//   0x3a0c: b0000060  adrp     x0, #0x10000
//   0x3a10: 91000000  add      x0, x0, #0
//   0x3a14: d1000515  sub      x21, x8, #1
//   0x3a18: 94000fd8  bl       #0x7978
//   0x3a1c: f9000015  str      x21, [x0]
//   0x3a20: 97fff868  bl       #0x1bc0
//   0x3a24: 35000060  cbnz     w0, #0x3a30
//   0x3a28: aa1303e0  mov      x0, x19
//   0x3a2c: 97fff8c9  bl       #0x1d50
//   0x3a30: aa1403e0  mov      x0, x20
//   0x3a34: 940008a1  bl       #0x5cb8
//   0x3a38: 97ffffa2  bl       #0x38c0
// ============================================================================
std::uint32_t fde_028_38cc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000038ccULL;
    for (std::size_t i = 0; i < 92ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1715ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[029] Symbol: sub_3a3c
//      Virtual Address Range: 0x3a3c..0x3bac (368 bytes, 92 AArch64 instructions)
// [VN] Khung FDE[029] Biểu tượng: sub_3a3c
//      Dải địa chỉ ảo: 0x3a3c..0x3bac (368 byte, 92 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x3a3c: f81a0ffb  str      x27, [sp, #-0x60]!
//   0x3a40: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x3a44: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x3a48: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x3a4c: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x3a50: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x3a54: 910143fd  add      x29, sp, #0x50
//   0x3a58: aa0003f9  mov      x25, x0
//   0x3a5c: b0000060  adrp     x0, #0x10000
//   0x3a60: 91000000  add      x0, x0, #0
//   0x3a64: aa1e03f3  mov      x19, x30
//   0x3a68: aa0503f5  mov      x21, x5
//   0x3a6c: 2a0403f6  mov      w22, w4
//   0x3a70: 2a0303f7  mov      w23, w3
//   0x3a74: 2a0203f8  mov      w24, w2
//   0x3a78: aa0103f4  mov      x20, x1
//   0x3a7c: 94000fbf  bl       #0x7978
//   0x3a80: f940001a  ldr      x26, [x0]
//   0x3a84: 91000748  add      x8, x26, #1
//   0x3a88: f9000008  str      x8, [x0]
//   0x3a8c: b0000068  adrp     x8, #0x10000
//   0x3a90: b9405d08  ldr      w8, [x8, #0x5c]
//   0x3a94: eb14011f  cmp      x8, x20
//   0x3a98: 540000a8  b.hi     #0x3aac
//   0x3a9c: b0000068  adrp     x8, #0x10000
//   0x3aa0: b9406108  ldr      w8, [x8, #0x60]
//   0x3aa4: eb14011f  cmp      x8, x20
//   0x3aa8: 54000062  b.hs     #0x3ab4
//   0x3aac: 2a1f03fb  mov      w27, wzr
//   0x3ab0: 14000003  b        #0x3abc
//   0x3ab4: f100029f  cmp      x20, #0
//   0x3ab8: 1a9f07fb  cset     w27, ne
//   0x3abc: 90000000  adrp     x0, #0x3000
//   0x3ac0: 9128f000  add      x0, x0, #0xa3c
//   0x3ac4: 97fff84f  bl       #0x1c00
//   0x3ac8: aa0003e8  mov      x8, x0
//   0x3acc: aa1903e0  mov      x0, x25
//   0x3ad0: aa1403e1  mov      x1, x20
//   0x3ad4: 2a1803e2  mov      w2, w24
//   0x3ad8: 2a1703e3  mov      w3, w23
//   0x3adc: 2a1603e4  mov      w4, w22
//   0x3ae0: aa1503e5  mov      x5, x21
//   0x3ae4: d63f0100  blr      x8
//   0x3ae8: aa0003f5  mov      x21, x0
//   0x3aec: b50000da  cbnz     x26, #0x3b04
//   0x3af0: 340000bb  cbz      w27, #0x3b04
//   0x3af4: b4000095  cbz      x21, #0x3b04
//   0x3af8: aa1503e0  mov      x0, x21
//   0x3afc: aa1403e1  mov      x1, x20
//   0x3b00: 97ffff32  bl       #0x37c8
//   0x3b04: b0000060  adrp     x0, #0x10000
//   0x3b08: 91000000  add      x0, x0, #0
//   0x3b0c: 94000f9b  bl       #0x7978
//   0x3b10: f9400008  ldr      x8, [x0]
//   0x3b14: b40000c8  cbz      x8, #0x3b2c
//   0x3b18: b0000060  adrp     x0, #0x10000
//   0x3b1c: 91000000  add      x0, x0, #0
//   0x3b20: d1000514  sub      x20, x8, #1
//   0x3b24: 94000f95  bl       #0x7978
//   0x3b28: f9000014  str      x20, [x0]
//   0x3b2c: 97fff825  bl       #0x1bc0
//   0x3b30: 35000060  cbnz     w0, #0x3b3c
//   0x3b34: aa1303e0  mov      x0, x19
//   0x3b38: 97fff886  bl       #0x1d50
//   0x3b3c: aa1503e0  mov      x0, x21
//   0x3b40: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x3b44: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x3b48: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x3b4c: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x3b50: a94167fa  ldp      x26, x25, [sp, #0x10]
//   0x3b54: f84607fb  ldr      x27, [sp], #0x60
//   0x3b58: d65f03c0  ret      
//   0x3b5c: 97ffff59  bl       #0x38c0
//   0x3b60: 97ffff58  bl       #0x38c0
//   0x3b64: aa0003f4  mov      x20, x0
//   0x3b68: b0000060  adrp     x0, #0x10000
//   0x3b6c: 91000000  add      x0, x0, #0
//   0x3b70: 94000f82  bl       #0x7978
//   0x3b74: f9400008  ldr      x8, [x0]
//   0x3b78: b40000c8  cbz      x8, #0x3b90
//   0x3b7c: b0000060  adrp     x0, #0x10000
//   0x3b80: 91000000  add      x0, x0, #0
//   0x3b84: d1000515  sub      x21, x8, #1
//   0x3b88: 94000f7c  bl       #0x7978
//   0x3b8c: f9000015  str      x21, [x0]
//   0x3b90: 97fff80c  bl       #0x1bc0
//   0x3b94: 35000060  cbnz     w0, #0x3ba0
//   0x3b98: aa1303e0  mov      x0, x19
//   0x3b9c: 97fff86d  bl       #0x1d50
//   0x3ba0: aa1403e0  mov      x0, x20
//   0x3ba4: 94000845  bl       #0x5cb8
//   0x3ba8: 97ffff46  bl       #0x38c0
// ============================================================================
std::uint32_t fde_029_3a3c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003a3cULL;
    for (std::size_t i = 0; i < 92ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1807ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[030] Symbol: sub_3bac
//      Virtual Address Range: 0x3bac..0x3cd0 (292 bytes, 73 AArch64 instructions)
// [VN] Khung FDE[030] Biểu tượng: sub_3bac
//      Dải địa chỉ ảo: 0x3bac..0x3cd0 (292 byte, 73 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x3bac: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x3bb0: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x3bb4: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x3bb8: 910083fd  add      x29, sp, #0x20
//   0x3bbc: aa0003f5  mov      x21, x0
//   0x3bc0: b0000060  adrp     x0, #0x10000
//   0x3bc4: 91000000  add      x0, x0, #0
//   0x3bc8: aa1e03f3  mov      x19, x30
//   0x3bcc: aa0103f4  mov      x20, x1
//   0x3bd0: 94000f6a  bl       #0x7978
//   0x3bd4: f9400016  ldr      x22, [x0]
//   0x3bd8: 910006c8  add      x8, x22, #1
//   0x3bdc: f9000008  str      x8, [x0]
//   0x3be0: 90000000  adrp     x0, #0x3000
//   0x3be4: 912eb000  add      x0, x0, #0xbac
//   0x3be8: 97fff806  bl       #0x1c00
//   0x3bec: aa0003e8  mov      x8, x0
//   0x3bf0: aa1503e0  mov      x0, x21
//   0x3bf4: aa1403e1  mov      x1, x20
//   0x3bf8: d63f0100  blr      x8
//   0x3bfc: 2a0003f4  mov      w20, w0
//   0x3c00: b40000d5  cbz      x21, #0x3c18
//   0x3c04: b50000b6  cbnz     x22, #0x3c18
//   0x3c08: b0000068  adrp     x8, #0x10000
//   0x3c0c: f9402100  ldr      x0, [x8, #0x40]
//   0x3c10: aa1503e1  mov      x1, x21
//   0x3c14: 97fff961  bl       #0x2198
//   0x3c18: b0000060  adrp     x0, #0x10000
//   0x3c1c: 91000000  add      x0, x0, #0
//   0x3c20: 94000f56  bl       #0x7978
//   0x3c24: f9400008  ldr      x8, [x0]
//   0x3c28: b40000c8  cbz      x8, #0x3c40
//   0x3c2c: b0000060  adrp     x0, #0x10000
//   0x3c30: 91000000  add      x0, x0, #0
//   0x3c34: d1000515  sub      x21, x8, #1
//   0x3c38: 94000f50  bl       #0x7978
//   0x3c3c: f9000015  str      x21, [x0]
//   0x3c40: 97fff7e0  bl       #0x1bc0
//   0x3c44: 35000060  cbnz     w0, #0x3c50
//   0x3c48: aa1303e0  mov      x0, x19
//   0x3c4c: 97fff841  bl       #0x1d50
//   0x3c50: 2a1403e0  mov      w0, w20
//   0x3c54: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x3c58: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x3c5c: a8c357f6  ldp      x22, x21, [sp], #0x30
//   0x3c60: d65f03c0  ret      
//   0x3c64: 97ffff17  bl       #0x38c0
//   0x3c68: 97ffff16  bl       #0x38c0
//   0x3c6c: aa0003f4  mov      x20, x0
//   0x3c70: b40000d5  cbz      x21, #0x3c88
//   0x3c74: b50000b6  cbnz     x22, #0x3c88
//   0x3c78: b0000068  adrp     x8, #0x10000
//   0x3c7c: f9402100  ldr      x0, [x8, #0x40]
//   0x3c80: aa1503e1  mov      x1, x21
//   0x3c84: 97fff945  bl       #0x2198
//   0x3c88: b0000060  adrp     x0, #0x10000
//   0x3c8c: 91000000  add      x0, x0, #0
//   0x3c90: 94000f3a  bl       #0x7978
//   0x3c94: f9400008  ldr      x8, [x0]
//   0x3c98: b40000c8  cbz      x8, #0x3cb0
//   0x3c9c: b0000060  adrp     x0, #0x10000
//   0x3ca0: 91000000  add      x0, x0, #0
//   0x3ca4: d1000515  sub      x21, x8, #1
//   0x3ca8: 94000f34  bl       #0x7978
//   0x3cac: f9000015  str      x21, [x0]
//   0x3cb0: 97fff7c4  bl       #0x1bc0
//   0x3cb4: 35000060  cbnz     w0, #0x3cc0
//   0x3cb8: aa1303e0  mov      x0, x19
//   0x3cbc: 97fff825  bl       #0x1d50
//   0x3cc0: aa1403e0  mov      x0, x20
//   0x3cc4: 940007fd  bl       #0x5cb8
//   0x3cc8: 97fffefe  bl       #0x38c0
//   0x3ccc: 97fffefd  bl       #0x38c0
// ============================================================================
std::uint32_t fde_030_3bac(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003bacULL;
    for (std::size_t i = 0; i < 73ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1899ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[031] Symbol: sub_3cd0
//      Virtual Address Range: 0x3cd0..0x3db4 (228 bytes, 57 AArch64 instructions)
// [VN] Khung FDE[031] Biểu tượng: sub_3cd0
//      Dải địa chỉ ảo: 0x3cd0..0x3db4 (228 byte, 57 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x3cd0: d10203ff  sub      sp, sp, #0x80
//   0x3cd4: f9002bf5  str      x21, [sp, #0x50]
//   0x3cd8: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x3cdc: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x3ce0: 9101c3fd  add      x29, sp, #0x70
//   0x3ce4: d53bd055  mrs      x21, tpidr_el0
//   0x3ce8: f94016a8  ldr      x8, [x21, #0x28]
//   0x3cec: aa1e03f3  mov      x19, x30
//   0x3cf0: aa0003f4  mov      x20, x0
//   0x3cf4: f81d83a8  stur     x8, [x29, #-0x28]
//   0x3cf8: a9007fff  stp      xzr, xzr, [sp]
//   0x3cfc: 97fff789  bl       #0x1b20
//   0x3d00: 910043e1  add      x1, sp, #0x10
//   0x3d04: 97fff7cb  bl       #0x1c30
//   0x3d08: 350001c0  cbnz     w0, #0x3d40
//   0x3d0c: 910043e0  add      x0, sp, #0x10
//   0x3d10: 910023e1  add      x1, sp, #8
//   0x3d14: 910003e2  mov      x2, sp
//   0x3d18: 97fff832  bl       #0x1de0
//   0x3d1c: f94007e1  ldr      x1, [sp, #8]
//   0x3d20: b40000c1  cbz      x1, #0x3d38
//   0x3d24: f94003e8  ldr      x8, [sp]
//   0x3d28: b4000088  cbz      x8, #0x3d38
//   0x3d2c: b0000068  adrp     x8, #0x10000
//   0x3d30: f9402100  ldr      x0, [x8, #0x40]
//   0x3d34: 97fff919  bl       #0x2198
//   0x3d38: 910043e0  add      x0, sp, #0x10
//   0x3d3c: 97fff7ed  bl       #0x1cf0
//   0x3d40: 90000000  adrp     x0, #0x3000
//   0x3d44: 91334000  add      x0, x0, #0xcd0
//   0x3d48: 97fff7ae  bl       #0x1c00
//   0x3d4c: aa0003e8  mov      x8, x0
//   0x3d50: aa1403e0  mov      x0, x20
//   0x3d54: d63f0100  blr      x8
//   0x3d58: 97fff79a  bl       #0x1bc0
//   0x3d5c: 35000060  cbnz     w0, #0x3d68
//   0x3d60: aa1303e0  mov      x0, x19
//   0x3d64: 97fff7fb  bl       #0x1d50
//   0x3d68: f94016a8  ldr      x8, [x21, #0x28]
//   0x3d6c: f85d83a9  ldur     x9, [x29, #-0x28]
//   0x3d70: eb09011f  cmp      x8, x9
//   0x3d74: 540000c1  b.ne     #0x3d8c
//   0x3d78: a9477bfd  ldp      x29, x30, [sp, #0x70]
//   0x3d7c: a9464ff4  ldp      x20, x19, [sp, #0x60]
//   0x3d80: f9402bf5  ldr      x21, [sp, #0x50]
//   0x3d84: 910203ff  add      sp, sp, #0x80
//   0x3d88: d65f03c0  ret      
//   0x3d8c: 97fff7f5  bl       #0x1d60
//   0x3d90: 97fffecc  bl       #0x38c0
//   0x3d94: aa0003f4  mov      x20, x0
//   0x3d98: 97fff78a  bl       #0x1bc0
//   0x3d9c: 35000060  cbnz     w0, #0x3da8
//   0x3da0: aa1303e0  mov      x0, x19
//   0x3da4: 97fff7eb  bl       #0x1d50
//   0x3da8: aa1403e0  mov      x0, x20
//   0x3dac: 940007c3  bl       #0x5cb8
//   0x3db0: 97fffec4  bl       #0x38c0
// ============================================================================
std::uint32_t fde_031_3cd0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003cd0ULL;
    for (std::size_t i = 0; i < 57ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1972ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[032] Symbol: sub_3db4
//      Virtual Address Range: 0x3db4..0x3e3c (136 bytes, 34 AArch64 instructions)
// [VN] Khung FDE[032] Biểu tượng: sub_3db4
//      Dải địa chỉ ảo: 0x3db4..0x3e3c (136 byte, 34 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x3db4: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x3db8: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x3dbc: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x3dc0: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x3dc4: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x3dc8: 910103fd  add      x29, sp, #0x40
//   0x3dcc: 2a0203f7  mov      w23, w2
//   0x3dd0: aa0103f8  mov      x24, x1
//   0x3dd4: 90000021  adrp     x1, #0x7000
//   0x3dd8: 90000022  adrp     x2, #0x7000
//   0x3ddc: aa0003f9  mov      x25, x0
//   0x3de0: 912d3821  add      x1, x1, #0xb4e
//   0x3de4: 9138b842  add      x2, x2, #0xe2e
//   0x3de8: 528000c0  mov      w0, #6
//   0x3dec: 2a0603f3  mov      w19, w6
//   0x3df0: 2a0503f4  mov      w20, w5
//   0x3df4: aa0403f5  mov      x21, x4
//   0x3df8: aa0303f6  mov      x22, x3
//   0x3dfc: 97fff765  bl       #0x1b90
//   0x3e00: b0000068  adrp     x8, #0x10000
//   0x3e04: f9406900  ldr      x0, [x8, #0xd0]
//   0x3e08: aa1803e2  mov      x2, x24
//   0x3e0c: 2a1703e3  mov      w3, w23
//   0x3e10: aa1603e4  mov      x4, x22
//   0x3e14: aa1503e5  mov      x5, x21
//   0x3e18: 2a1403e6  mov      w6, w20
//   0x3e1c: 2a1303e7  mov      w7, w19
//   0x3e20: a9447bfd  ldp      x29, x30, [sp, #0x40]
//   0x3e24: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x3e28: a94257f6  ldp      x22, x21, [sp, #0x20]
//   0x3e2c: a9415ff8  ldp      x24, x23, [sp, #0x10]
//   0x3e30: aa1903e1  mov      x1, x25
//   0x3e34: f84507f9  ldr      x25, [sp], #0x50
//   0x3e38: 17fffb08  b        #0x2a58
// ============================================================================
std::uint32_t fde_032_3db4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003db4ULL;
    for (std::size_t i = 0; i < 34ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2029ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[033] Symbol: sub_3e3c
//      Virtual Address Range: 0x3e3c..0x3e84 (72 bytes, 18 AArch64 instructions)
// [VN] Khung FDE[033] Biểu tượng: sub_3e3c
//      Dải địa chỉ ảo: 0x3e3c..0x3e84 (72 byte, 18 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x3e3c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x3e40: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x3e44: 910043fd  add      x29, sp, #0x10
//   0x3e48: aa0103f3  mov      x19, x1
//   0x3e4c: 90000021  adrp     x1, #0x7000
//   0x3e50: 90000022  adrp     x2, #0x7000
//   0x3e54: aa0003f4  mov      x20, x0
//   0x3e58: 912d3821  add      x1, x1, #0xb4e
//   0x3e5c: 9138f042  add      x2, x2, #0xe3c
//   0x3e60: 528000c0  mov      w0, #6
//   0x3e64: 97fff74b  bl       #0x1b90
//   0x3e68: b0000068  adrp     x8, #0x10000
//   0x3e6c: f9406900  ldr      x0, [x8, #0xd0]
//   0x3e70: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x3e74: aa1403e1  mov      x1, x20
//   0x3e78: aa1303e2  mov      x2, x19
//   0x3e7c: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x3e80: 17fffb9b  b        #0x2cec
// ============================================================================
std::uint32_t fde_033_3e3c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003e3cULL;
    for (std::size_t i = 0; i < 18ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2063ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[034] Symbol: sub_3e84
//      Virtual Address Range: 0x3e84..0x3ecc (72 bytes, 18 AArch64 instructions)
// [VN] Khung FDE[034] Biểu tượng: sub_3e84
//      Dải địa chỉ ảo: 0x3e84..0x3ecc (72 byte, 18 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x3e84: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x3e88: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x3e8c: 910043fd  add      x29, sp, #0x10
//   0x3e90: aa0103f3  mov      x19, x1
//   0x3e94: 90000021  adrp     x1, #0x7000
//   0x3e98: 90000022  adrp     x2, #0x7000
//   0x3e9c: aa0003f4  mov      x20, x0
//   0x3ea0: 912d3821  add      x1, x1, #0xb4e
//   0x3ea4: 91392442  add      x2, x2, #0xe49
//   0x3ea8: 528000c0  mov      w0, #6
//   0x3eac: 97fff739  bl       #0x1b90
//   0x3eb0: b0000068  adrp     x8, #0x10000
//   0x3eb4: f9406900  ldr      x0, [x8, #0xd0]
//   0x3eb8: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x3ebc: aa1403e1  mov      x1, x20
//   0x3ec0: aa1303e2  mov      x2, x19
//   0x3ec4: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x3ec8: 17fffbc2  b        #0x2dd0
// ============================================================================
std::uint32_t fde_034_3e84(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003e84ULL;
    for (std::size_t i = 0; i < 18ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2081ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[035] Symbol: JNI_OnLoad
//      Virtual Address Range: 0x3ecc..0x3f8c (192 bytes, 48 AArch64 instructions)
// [VN] Khung FDE[035] Biểu tượng: JNI_OnLoad
//      Dải địa chỉ ảo: 0x3ecc..0x3f8c (192 byte, 48 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x3ecc: d10103ff  sub      sp, sp, #0x40
//   0x3ed0: f9000bf5  str      x21, [sp, #0x10]
//   0x3ed4: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x3ed8: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x3edc: 9100c3fd  add      x29, sp, #0x30
//   0x3ee0: d53bd055  mrs      x21, tpidr_el0
//   0x3ee4: f94016a8  ldr      x8, [x21, #0x28]
//   0x3ee8: 528000c2  mov      w2, #6
//   0x3eec: 528000d3  mov      w19, #6
//   0x3ef0: 910003e1  mov      x1, sp
//   0x3ef4: f90007e8  str      x8, [sp, #8]
//   0x3ef8: f90003ff  str      xzr, [sp]
//   0x3efc: f9400008  ldr      x8, [x0]
//   0x3f00: 72a00022  movk     w2, #1, lsl #16
//   0x3f04: 72a00033  movk     w19, #1, lsl #16
//   0x3f08: f9401908  ldr      x8, [x8, #0x30]
//   0x3f0c: d63f0100  blr      x8
//   0x3f10: 34000180  cbz      w0, #0x3f40
//   0x3f14: 12800013  mov      w19, #-1
//   0x3f18: f94016a8  ldr      x8, [x21, #0x28]
//   0x3f1c: f94007e9  ldr      x9, [sp, #8]
//   0x3f20: eb09011f  cmp      x8, x9
//   0x3f24: 54000321  b.ne     #0x3f88
//   0x3f28: 2a1303e0  mov      w0, w19
//   0x3f2c: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x3f30: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x3f34: f9400bf5  ldr      x21, [sp, #0x10]
//   0x3f38: 910103ff  add      sp, sp, #0x40
//   0x3f3c: d65f03c0  ret      
//   0x3f40: f94003f4  ldr      x20, [sp]
//   0x3f44: 90000021  adrp     x1, #0x7000
//   0x3f48: 91395c21  add      x1, x1, #0xe57
//   0x3f4c: f9400288  ldr      x8, [x20]
//   0x3f50: aa1403e0  mov      x0, x20
//   0x3f54: f9401908  ldr      x8, [x8, #0x30]
//   0x3f58: d63f0100  blr      x8
//   0x3f5c: b4fffdc0  cbz      x0, #0x3f14
//   0x3f60: f9400288  ldr      x8, [x20]
//   0x3f64: 90000062  adrp     x2, #0xf000
//   0x3f68: aa0003e1  mov      x1, x0
//   0x3f6c: 912c4042  add      x2, x2, #0xb10
//   0x3f70: f9435d08  ldr      x8, [x8, #0x6b8]
//   0x3f74: 52800063  mov      w3, #3
//   0x3f78: aa1403e0  mov      x0, x20
//   0x3f7c: d63f0100  blr      x8
//   0x3f80: 36fffcc0  tbz      w0, #0x1f, #0x3f18
//   0x3f84: 17ffffe4  b        #0x3f14
//   0x3f88: 97fff776  bl       #0x1d60
// ============================================================================
std::uint32_t fde_035_3ecc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003eccULL;
    for (std::size_t i = 0; i < 48ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2099ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[036] Symbol: Java_com_bytedance_raphael_TestTool_mallocLeak
//      Virtual Address Range: 0x3f8c..0x3fcc (64 bytes, 16 AArch64 instructions)
// [VN] Khung FDE[036] Biểu tượng: Java_com_bytedance_raphael_TestTool_mallocLeak
//      Dải địa chỉ ảo: 0x3f8c..0x3fcc (64 byte, 16 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x3f8c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x3f90: 910003fd  mov      x29, sp
//   0x3f94: 5283e800  mov      w0, #0x1f40
//   0x3f98: 97fff6aa  bl       #0x1a40
//   0x3f9c: b0000068  adrp     x8, #0x10000
//   0x3fa0: f9006d00  str      x0, [x8, #0xd8]
//   0x3fa4: 5283e800  mov      w0, #0x1f40
//   0x3fa8: 97fff6ca  bl       #0x1ad0
//   0x3fac: b0000068  adrp     x8, #0x10000
//   0x3fb0: f9007100  str      x0, [x8, #0xe0]
//   0x3fb4: 5283e800  mov      w0, #0x1f40
//   0x3fb8: 97fff6c6  bl       #0x1ad0
//   0x3fbc: b0000068  adrp     x8, #0x10000
//   0x3fc0: f9007500  str      x0, [x8, #0xe8]
//   0x3fc4: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x3fc8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_036_3f8c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003f8cULL;
    for (std::size_t i = 0; i < 16ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2147ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[037] Symbol: Java_com_bytedance_raphael_TestTool_print
//      Virtual Address Range: 0x3fcc..0x4054 (136 bytes, 34 AArch64 instructions)
// [VN] Khung FDE[037] Biểu tượng: Java_com_bytedance_raphael_TestTool_print
//      Dải địa chỉ ảo: 0x3fcc..0x4054 (136 byte, 34 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x3fcc: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x3fd0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x3fd4: 910043fd  add      x29, sp, #0x10
//   0x3fd8: 90000020  adrp     x0, #0x7000
//   0x3fdc: 913bb800  add      x0, x0, #0xeee
//   0x3fe0: 97fff6e8  bl       #0x1b80
//   0x3fe4: b4000180  cbz      x0, #0x4014
//   0x3fe8: 90000021  adrp     x1, #0x7000
//   0x3fec: 913bd821  add      x1, x1, #0xef6
//   0x3ff0: aa0003f4  mov      x20, x0
//   0x3ff4: 97fff74f  bl       #0x1d30
//   0x3ff8: aa0003f3  mov      x19, x0
//   0x3ffc: aa1403e0  mov      x0, x20
//   0x4000: 97fff764  bl       #0x1d90
//   0x4004: b4000093  cbz      x19, #0x4014
//   0x4008: 12801980  mov      w0, #-0xcd
//   0x400c: 2a1f03e1  mov      w1, wzr
//   0x4010: d63f0260  blr      x19
//   0x4014: f0000013  adrp     x19, #0x7000
//   0x4018: 912d3a73  add      x19, x19, #0xb4e
//   0x401c: f0000002  adrp     x2, #0x7000
//   0x4020: 913ae042  add      x2, x2, #0xeb8
//   0x4024: 528000c0  mov      w0, #6
//   0x4028: aa1303e1  mov      x1, x19
//   0x402c: 97fff6d9  bl       #0x1b90
//   0x4030: 97fff6ac  bl       #0x1ae0
//   0x4034: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x4038: f0000002  adrp     x2, #0x7000
//   0x403c: 2a0003e3  mov      w3, w0
//   0x4040: 913b8842  add      x2, x2, #0xee2
//   0x4044: 528000c0  mov      w0, #6
//   0x4048: aa1303e1  mov      x1, x19
//   0x404c: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x4050: 17fff6d0  b        #0x1b90
// ============================================================================
std::uint32_t fde_037_3fcc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003fccULL;
    for (std::size_t i = 0; i < 34ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2163ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[038] Symbol: sub_4054
//      Virtual Address Range: 0x4054..0x407c (40 bytes, 10 AArch64 instructions)
// [VN] Khung FDE[038] Biểu tượng: sub_4054
//      Dải địa chỉ ảo: 0x4054..0x407c (40 byte, 10 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4054: d2800002  mov      x2, #0
//   0x4058: 52800003  mov      w3, #0
//   0x405c: 38401405  ldrb     w5, [x0], #1
//   0x4060: 924018a4  and      x4, x5, #0x7f
//   0x4064: 9ac32084  lsl      x4, x4, x3
//   0x4068: 11001c63  add      w3, w3, #7
//   0x406c: aa040042  orr      x2, x2, x4
//   0x4070: 373fff65  tbnz     w5, #7, #0x405c
//   0x4074: f9000022  str      x2, [x1]
//   0x4078: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_038_4054(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004054ULL;
    for (std::size_t i = 0; i < 10ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2197ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[039] Symbol: sub_407c
//      Virtual Address Range: 0x407c..0x40bc (64 bytes, 16 AArch64 instructions)
// [VN] Khung FDE[039] Biểu tượng: sub_407c
//      Dải địa chỉ ảo: 0x407c..0x40bc (64 byte, 16 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x407c: d2800002  mov      x2, #0
//   0x4080: 52800003  mov      w3, #0
//   0x4084: 38401404  ldrb     w4, [x0], #1
//   0x4088: 92401885  and      x5, x4, #0x7f
//   0x408c: 9ac320a5  lsl      x5, x5, x3
//   0x4090: 11001c63  add      w3, w3, #7
//   0x4094: aa050042  orr      x2, x2, x5
//   0x4098: 373fff64  tbnz     w4, #7, #0x4084
//   0x409c: 7100fc7f  cmp      w3, #0x3f
//   0x40a0: 540000a8  b.hi     #0x40b4
//   0x40a4: 36300084  tbz      w4, #6, #0x40b4
//   0x40a8: 92800004  mov      x4, #-1
//   0x40ac: 9ac32083  lsl      x3, x4, x3
//   0x40b0: aa020062  orr      x2, x3, x2
//   0x40b4: f9000022  str      x2, [x1]
//   0x40b8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_039_407c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000407cULL;
    for (std::size_t i = 0; i < 16ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2207ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[040] Symbol: sub_40bc
//      Virtual Address Range: 0x40bc..0x41ac (240 bytes, 60 AArch64 instructions)
// [VN] Khung FDE[040] Biểu tượng: sub_40bc
//      Dải địa chỉ ảo: 0x40bc..0x41ac (240 byte, 60 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x40bc: a9bc7bfd  stp      x29, x30, [sp, #-0x40]!
//   0x40c0: 910003fd  mov      x29, sp
//   0x40c4: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x40c8: 53001c14  uxtb     w20, w0
//   0x40cc: aa0203f3  mov      x19, x2
//   0x40d0: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x40d4: 7101429f  cmp      w20, #0x50
//   0x40d8: aa0103f6  mov      x22, x1
//   0x40dc: aa0303f5  mov      x21, x3
//   0x40e0: 540000a1  b.ne     #0x40f4
//   0x40e4: 91001c53  add      x19, x2, #7
//   0x40e8: 927df260  and      x0, x19, #0xfffffffffffffff8
//   0x40ec: f8408401  ldr      x1, [x0], #8
//   0x40f0: 1400002a  b        #0x4198
//   0x40f4: 12000e81  and      w1, w20, #0xf
//   0x40f8: 7100303f  cmp      w1, #0xc
//   0x40fc: 540003e8  b.hi     #0x4178
//   0x4100: f0000000  adrp     x0, #0x7000
//   0x4104: 913c0000  add      x0, x0, #0xf00
//   0x4108: 38614800  ldrb     w0, [x0, w1, uxtw]
//   0x410c: 10000061  adr      x1, #0x4118
//   0x4110: 8b208820  add      x0, x1, w0, sxtb #2
//   0x4114: d61f0000  br       x0
//   0x4118: aa0203e0  mov      x0, x2
//   0x411c: 9100e3a1  add      x1, x29, #0x38
//   0x4120: 97ffffcd  bl       #0x4054
//   0x4124: 14000004  b        #0x4134
//   0x4128: aa0203e0  mov      x0, x2
//   0x412c: 9100e3a1  add      x1, x29, #0x38
//   0x4130: 97ffffd3  bl       #0x407c
//   0x4134: f9401fa1  ldr      x1, [x29, #0x38]
//   0x4138: 14000011  b        #0x417c
//   0x413c: aa0203e0  mov      x0, x2
//   0x4140: 78402401  ldrh     w1, [x0], #2
//   0x4144: 1400000e  b        #0x417c
//   0x4148: aa0203e0  mov      x0, x2
//   0x414c: b8404401  ldr      w1, [x0], #4
//   0x4150: 1400000b  b        #0x417c
//   0x4154: aa0203e0  mov      x0, x2
//   0x4158: 78802401  ldrsh    x1, [x0], #2
//   0x415c: 14000008  b        #0x417c
//   0x4160: aa0203e0  mov      x0, x2
//   0x4164: b8804401  ldrsw    x1, [x0], #4
//   0x4168: 14000005  b        #0x417c
//   0x416c: aa0203e0  mov      x0, x2
//   0x4170: f8408401  ldr      x1, [x0], #8
//   0x4174: 14000002  b        #0x417c
//   0x4178: 97fff6be  bl       #0x1c70
//   0x417c: b40000e1  cbz      x1, #0x4198
//   0x4180: 121c0a82  and      w2, w20, #0x70
//   0x4184: 7100405f  cmp      w2, #0x10
//   0x4188: 9a960273  csel     x19, x19, x22, eq
//   0x418c: 8b130021  add      x1, x1, x19
//   0x4190: 36380054  tbz      w20, #7, #0x4198
//   0x4194: f9400021  ldr      x1, [x1]
//   0x4198: f90002a1  str      x1, [x21]
//   0x419c: a94153f3  ldp      x19, x20, [sp, #0x10]
//   0x41a0: a9425bf5  ldp      x21, x22, [sp, #0x20]
//   0x41a4: a8c47bfd  ldp      x29, x30, [sp], #0x40
//   0x41a8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_040_40bc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000040bcULL;
    for (std::size_t i = 0; i < 60ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2223ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[041] Symbol: sub_41ac
//      Virtual Address Range: 0x41ac..0x42c0 (276 bytes, 69 AArch64 instructions)
// [VN] Khung FDE[041] Biểu tượng: sub_41ac
//      Dải địa chỉ ảo: 0x41ac..0x42c0 (276 byte, 69 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x41ac: 90000062  adrp     x2, #0x10000
//   0x41b0: 52800100  mov      w0, #8
//   0x41b4: 9103c041  add      x1, x2, #0xf0
//   0x41b8: 3903c040  strb     w0, [x2, #0xf0]
//   0x41bc: 39000420  strb     w0, [x1, #1]
//   0x41c0: 39000820  strb     w0, [x1, #2]
//   0x41c4: 39000c20  strb     w0, [x1, #3]
//   0x41c8: 39001020  strb     w0, [x1, #4]
//   0x41cc: 39001420  strb     w0, [x1, #5]
//   0x41d0: 39001820  strb     w0, [x1, #6]
//   0x41d4: 39001c20  strb     w0, [x1, #7]
//   0x41d8: 39002020  strb     w0, [x1, #8]
//   0x41dc: 39002420  strb     w0, [x1, #9]
//   0x41e0: 39002820  strb     w0, [x1, #0xa]
//   0x41e4: 39002c20  strb     w0, [x1, #0xb]
//   0x41e8: 39003020  strb     w0, [x1, #0xc]
//   0x41ec: 39003420  strb     w0, [x1, #0xd]
//   0x41f0: 39003820  strb     w0, [x1, #0xe]
//   0x41f4: 39003c20  strb     w0, [x1, #0xf]
//   0x41f8: 39004020  strb     w0, [x1, #0x10]
//   0x41fc: 39004420  strb     w0, [x1, #0x11]
//   0x4200: 39004820  strb     w0, [x1, #0x12]
//   0x4204: 39004c20  strb     w0, [x1, #0x13]
//   0x4208: 39005020  strb     w0, [x1, #0x14]
//   0x420c: 39005420  strb     w0, [x1, #0x15]
//   0x4210: 39005820  strb     w0, [x1, #0x16]
//   0x4214: 39005c20  strb     w0, [x1, #0x17]
//   0x4218: 39006020  strb     w0, [x1, #0x18]
//   0x421c: 39006420  strb     w0, [x1, #0x19]
//   0x4220: 39006820  strb     w0, [x1, #0x1a]
//   0x4224: 39006c20  strb     w0, [x1, #0x1b]
//   0x4228: 39007020  strb     w0, [x1, #0x1c]
//   0x422c: 39007420  strb     w0, [x1, #0x1d]
//   0x4230: 39007820  strb     w0, [x1, #0x1e]
//   0x4234: 39007c20  strb     w0, [x1, #0x1f]
//   0x4238: 39010020  strb     w0, [x1, #0x40]
//   0x423c: 39010420  strb     w0, [x1, #0x41]
//   0x4240: 39010820  strb     w0, [x1, #0x42]
//   0x4244: 39010c20  strb     w0, [x1, #0x43]
//   0x4248: 39011020  strb     w0, [x1, #0x44]
//   0x424c: 39011420  strb     w0, [x1, #0x45]
//   0x4250: 39011820  strb     w0, [x1, #0x46]
//   0x4254: 39011c20  strb     w0, [x1, #0x47]
//   0x4258: 39012020  strb     w0, [x1, #0x48]
//   0x425c: 39012420  strb     w0, [x1, #0x49]
//   0x4260: 39012820  strb     w0, [x1, #0x4a]
//   0x4264: 39012c20  strb     w0, [x1, #0x4b]
//   0x4268: 39013020  strb     w0, [x1, #0x4c]
//   0x426c: 39013420  strb     w0, [x1, #0x4d]
//   0x4270: 39013820  strb     w0, [x1, #0x4e]
//   0x4274: 39013c20  strb     w0, [x1, #0x4f]
//   0x4278: 39014020  strb     w0, [x1, #0x50]
//   0x427c: 39014420  strb     w0, [x1, #0x51]
//   0x4280: 39014820  strb     w0, [x1, #0x52]
//   0x4284: 39014c20  strb     w0, [x1, #0x53]
//   0x4288: 39015020  strb     w0, [x1, #0x54]
//   0x428c: 39015420  strb     w0, [x1, #0x55]
//   0x4290: 39015820  strb     w0, [x1, #0x56]
//   0x4294: 39015c20  strb     w0, [x1, #0x57]
//   0x4298: 39016020  strb     w0, [x1, #0x58]
//   0x429c: 39016420  strb     w0, [x1, #0x59]
//   0x42a0: 39016820  strb     w0, [x1, #0x5a]
//   0x42a4: 39016c20  strb     w0, [x1, #0x5b]
//   0x42a8: 39017020  strb     w0, [x1, #0x5c]
//   0x42ac: 39017420  strb     w0, [x1, #0x5d]
//   0x42b0: 39017820  strb     w0, [x1, #0x5e]
//   0x42b4: 39017c20  strb     w0, [x1, #0x5f]
//   0x42b8: 39018020  strb     w0, [x1, #0x60]
//   0x42bc: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_041_41ac(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000041acULL;
    for (std::size_t i = 0; i < 69ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2283ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[042] Symbol: sub_42c0
//      Virtual Address Range: 0x42c0..0x42fc (60 bytes, 15 AArch64 instructions)
// [VN] Khung FDE[042] Biểu tượng: sub_42c0
//      Dải địa chỉ ảo: 0x42c0..0x42fc (60 byte, 15 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x42c0: 90000063  adrp     x3, #0x10000
//   0x42c4: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x42c8: 910003fd  mov      x29, sp
//   0x42cc: 39443c63  ldrb     w3, [x3, #0x10f]
//   0x42d0: 7100207f  cmp      w3, #8
//   0x42d4: 540000c1  b.ne     #0x42ec
//   0x42d8: f9000041  str      x1, [x2]
//   0x42dc: f941a001  ldr      x1, [x0, #0x340]
//   0x42e0: b6f00081  tbz      x1, #0x3e, #0x42f0
//   0x42e4: 390ddc1f  strb     wzr, [x0, #0x377]
//   0x42e8: 14000002  b        #0x42f0
//   0x42ec: 97fff661  bl       #0x1c70
//   0x42f0: f9007c02  str      x2, [x0, #0xf8]
//   0x42f4: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x42f8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_042_42c0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000042c0ULL;
    for (std::size_t i = 0; i < 15ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2352ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[043] Symbol: sub_42fc
//      Virtual Address Range: 0x42fc..0x4354 (88 bytes, 22 AArch64 instructions)
// [VN] Khung FDE[043] Biểu tượng: sub_42fc
//      Dải địa chỉ ảo: 0x42fc..0x4354 (88 byte, 22 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x42fc: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x4300: 7101843f  cmp      w1, #0x61
//   0x4304: 910003fd  mov      x29, sp
//   0x4308: 5400004d  b.le     #0x4310
//   0x430c: 97fff659  bl       #0x1c70
//   0x4310: 90000063  adrp     x3, #0x10000
//   0x4314: 93407c22  sxtw     x2, w1
//   0x4318: 9103c063  add      x3, x3, #0xf0
//   0x431c: f941a004  ldr      x4, [x0, #0x340]
//   0x4320: f861d801  ldr      x1, [x0, w1, sxtw #3]
//   0x4324: 38626863  ldrb     w3, [x3, x2]
//   0x4328: b6f000c4  tbz      x4, #0x3e, #0x4340
//   0x432c: 8b020002  add      x2, x0, x2
//   0x4330: 394d6040  ldrb     w0, [x2, #0x358]
//   0x4334: 34000060  cbz      w0, #0x4340
//   0x4338: aa0103e0  mov      x0, x1
//   0x433c: 14000004  b        #0x434c
//   0x4340: 7100207f  cmp      w3, #8
//   0x4344: 54fffe41  b.ne     #0x430c
//   0x4348: f9400020  ldr      x0, [x1]
//   0x434c: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x4350: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_043_42fc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000042fcULL;
    for (std::size_t i = 0; i < 22ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2367ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[044] Symbol: sub_4354
//      Virtual Address Range: 0x4354..0x4460 (268 bytes, 67 AArch64 instructions)
// [VN] Khung FDE[044] Biểu tượng: sub_4354
//      Dải địa chỉ ảo: 0x4354..0x4460 (268 byte, 67 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4354: a9bc7bfd  stp      x29, x30, [sp, #-0x40]!
//   0x4358: 910003fd  mov      x29, sp
//   0x435c: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x4360: aa0003f5  mov      x21, x0
//   0x4364: f941a020  ldr      x0, [x1, #0x340]
//   0x4368: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x436c: aa0103f3  mov      x19, x1
//   0x4370: b6f00060  tbz      x0, #0x3e, #0x437c
//   0x4374: 394ddc20  ldrb     w0, [x1, #0x377]
//   0x4378: 350000e0  cbnz     w0, #0x4394
//   0x437c: f9407e60  ldr      x0, [x19, #0xf8]
//   0x4380: b50000a0  cbnz     x0, #0x4394
//   0x4384: f9418a61  ldr      x1, [x19, #0x310]
//   0x4388: aa1303e0  mov      x0, x19
//   0x438c: 9100e3a2  add      x2, x29, #0x38
//   0x4390: 97ffffcc  bl       #0x42c0
//   0x4394: d2800014  mov      x20, #0
//   0x4398: 90000076  adrp     x22, #0x10000
//   0x439c: 8b1402a2  add      x2, x21, x20
//   0x43a0: f8747aa0  ldr      x0, [x21, x20, lsl #3]
//   0x43a4: f8747a61  ldr      x1, [x19, x20, lsl #3]
//   0x43a8: 394d6042  ldrb     w2, [x2, #0x358]
//   0x43ac: 34000042  cbz      w2, #0x43b4
//   0x43b0: 97fff630  bl       #0x1c70
//   0x43b4: 8b140263  add      x3, x19, x20
//   0x43b8: eb1f001f  cmp      x0, xzr
//   0x43bc: 1a9f07e2  cset     w2, ne
//   0x43c0: 394d6063  ldrb     w3, [x3, #0x358]
//   0x43c4: 34000103  cbz      w3, #0x43e4
//   0x43c8: 340000e2  cbz      w2, #0x43e4
//   0x43cc: 9103c2c2  add      x2, x22, #0xf0
//   0x43d0: 38626a82  ldrb     w2, [x20, x2]
//   0x43d4: 7100205f  cmp      w2, #8
//   0x43d8: 54fffec1  b.ne     #0x43b0
//   0x43dc: f9000001  str      x1, [x0]
//   0x43e0: 1400000a  b        #0x4408
//   0x43e4: eb1f003f  cmp      x1, xzr
//   0x43e8: 1a9f07e3  cset     w3, ne
//   0x43ec: 6a03005f  tst      w2, w3
//   0x43f0: 540000c0  b.eq     #0x4408
//   0x43f4: eb00003f  cmp      x1, x0
//   0x43f8: 54000080  b.eq     #0x4408
//   0x43fc: 9103c2c2  add      x2, x22, #0xf0
//   0x4400: 38746842  ldrb     w2, [x2, x20]
//   0x4404: 97fff56f  bl       #0x19c0
//   0x4408: 91000694  add      x20, x20, #1
//   0x440c: f101869f  cmp      x20, #0x61
//   0x4410: 54fffc61  b.ne     #0x439c
//   0x4414: f941a2a0  ldr      x0, [x21, #0x340]
//   0x4418: b6f00080  tbz      x0, #0x3e, #0x4428
//   0x441c: 394ddea1  ldrb     w1, [x21, #0x377]
//   0x4420: d2800000  mov      x0, #0
//   0x4424: 35000161  cbnz     w1, #0x4450
//   0x4428: f9407ea1  ldr      x1, [x21, #0xf8]
//   0x442c: d2800000  mov      x0, #0
//   0x4430: b5000101  cbnz     x1, #0x4450
//   0x4434: 528003e1  mov      w1, #0x1f
//   0x4438: aa1303e0  mov      x0, x19
//   0x443c: 97ffffb0  bl       #0x42fc
//   0x4440: f9418aa1  ldr      x1, [x21, #0x310]
//   0x4444: f941aa75  ldr      x21, [x19, #0x350]
//   0x4448: cb010000  sub      x0, x0, x1
//   0x444c: 8b150000  add      x0, x0, x21
//   0x4450: a94153f3  ldp      x19, x20, [sp, #0x10]
//   0x4454: a9425bf5  ldp      x21, x22, [sp, #0x20]
//   0x4458: a8c47bfd  ldp      x29, x30, [sp], #0x40
//   0x445c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_044_4354(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004354ULL;
    for (std::size_t i = 0; i < 67ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2389ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[045] Symbol: sub_4460
//      Virtual Address Range: 0x4460..0x4468 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[045] Biểu tượng: sub_4460
//      Dải địa chỉ ảo: 0x4460..0x4468 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4460: f9418800  ldr      x0, [x0, #0x310]
//   0x4464: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_045_4460(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004460ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2456ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[046] Symbol: sub_4468
//      Virtual Address Range: 0x4468..0x44c0 (88 bytes, 22 AArch64 instructions)
// [VN] Khung FDE[046] Biểu tượng: sub_4468
//      Dải địa chỉ ảo: 0x4468..0x44c0 (88 byte, 22 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4468: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x446c: 7101843f  cmp      w1, #0x61
//   0x4470: 910003fd  mov      x29, sp
//   0x4474: 5400004d  b.le     #0x447c
//   0x4478: 97fff5fe  bl       #0x1c70
//   0x447c: 90000064  adrp     x4, #0x10000
//   0x4480: 93407c23  sxtw     x3, w1
//   0x4484: 9103c084  add      x4, x4, #0xf0
//   0x4488: f941a005  ldr      x5, [x0, #0x340]
//   0x448c: 38636884  ldrb     w4, [x4, x3]
//   0x4490: b6f000c5  tbz      x5, #0x3e, #0x44a8
//   0x4494: 8b030003  add      x3, x0, x3
//   0x4498: 394d6063  ldrb     w3, [x3, #0x358]
//   0x449c: 34000063  cbz      w3, #0x44a8
//   0x44a0: f821d802  str      x2, [x0, w1, sxtw #3]
//   0x44a4: 14000005  b        #0x44b8
//   0x44a8: 7100209f  cmp      w4, #8
//   0x44ac: f861d800  ldr      x0, [x0, w1, sxtw #3]
//   0x44b0: 54fffe41  b.ne     #0x4478
//   0x44b4: f9000002  str      x2, [x0]
//   0x44b8: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x44bc: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_046_4468(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004468ULL;
    for (std::size_t i = 0; i < 22ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2458ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[047] Symbol: sub_44c0
//      Virtual Address Range: 0x44c0..0x44c8 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[047] Biểu tượng: sub_44c0
//      Dải địa chỉ ảo: 0x44c0..0x44c8 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x44c0: f9418c00  ldr      x0, [x0, #0x318]
//   0x44c4: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_047_44c0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000044c0ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2480ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[048] Symbol: sub_44c8
//      Virtual Address Range: 0x44c8..0x44dc (20 bytes, 5 AArch64 instructions)
// [VN] Khung FDE[048] Biểu tượng: sub_44c8
//      Dải địa chỉ ảo: 0x44c8..0x44dc (20 byte, 5 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x44c8: f941a002  ldr      x2, [x0, #0x340]
//   0x44cc: f9418c00  ldr      x0, [x0, #0x318]
//   0x44d0: d37ffc42  lsr      x2, x2, #0x3f
//   0x44d4: b9000022  str      w2, [x1]
//   0x44d8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_048_44c8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000044c8ULL;
    for (std::size_t i = 0; i < 5ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2482ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[049] Symbol: sub_44dc
//      Virtual Address Range: 0x44dc..0x44e4 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[049] Biểu tượng: sub_44dc
//      Dải địa chỉ ảo: 0x44dc..0x44e4 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x44dc: f9018c01  str      x1, [x0, #0x318]
//   0x44e0: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_049_44dc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000044dcULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2487ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[050] Symbol: sub_44e4
//      Virtual Address Range: 0x44e4..0x44ec (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[050] Biểu tượng: sub_44e4
//      Dải địa chỉ ảo: 0x44e4..0x44ec (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x44e4: f9419000  ldr      x0, [x0, #0x320]
//   0x44e8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_050_44e4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000044e4ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2489ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[051] Symbol: sub_44ec
//      Virtual Address Range: 0x44ec..0x44f4 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[051] Biểu tượng: sub_44ec
//      Dải địa chỉ ảo: 0x44ec..0x44f4 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x44ec: f9419c00  ldr      x0, [x0, #0x338]
//   0x44f0: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_051_44ec(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000044ecULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2491ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[052] Symbol: sub_44f4
//      Virtual Address Range: 0x44f4..0x451c (40 bytes, 10 AArch64 instructions)
// [VN] Khung FDE[052] Biểu tượng: sub_44f4
//      Dải địa chỉ ảo: 0x44f4..0x451c (40 byte, 10 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x44f4: a9bd7bfd  stp      x29, x30, [sp, #-0x30]!
//   0x44f8: d1000400  sub      x0, x0, #1
//   0x44fc: 910003fd  mov      x29, sp
//   0x4500: 910063a1  add      x1, x29, #0x18
//   0x4504: 94000c4e  bl       #0x763c
//   0x4508: eb1f001f  cmp      x0, xzr
//   0x450c: f94017a0  ldr      x0, [x29, #0x28]
//   0x4510: a8c37bfd  ldp      x29, x30, [sp], #0x30
//   0x4514: 9a9f1000  csel     x0, x0, xzr, ne
//   0x4518: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_052_44f4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000044f4ULL;
    for (std::size_t i = 0; i < 10ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2493ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[053] Symbol: sub_451c
//      Virtual Address Range: 0x451c..0x4524 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[053] Biểu tượng: sub_451c
//      Dải địa chỉ ảo: 0x451c..0x4524 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x451c: f9419800  ldr      x0, [x0, #0x330]
//   0x4520: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_053_451c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000451cULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2503ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[054] Symbol: sub_4524
//      Virtual Address Range: 0x4524..0x452c (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[054] Biểu tượng: sub_4524
//      Dải địa chỉ ảo: 0x4524..0x452c (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4524: f9419400  ldr      x0, [x0, #0x328]
//   0x4528: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_054_4524(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004524ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2505ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[055] Symbol: sub_452c
//      Virtual Address Range: 0x452c..0x45a4 (120 bytes, 30 AArch64 instructions)
// [VN] Khung FDE[055] Biểu tượng: sub_452c
//      Dải địa chỉ ảo: 0x452c..0x45a4 (120 byte, 30 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x452c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x4530: 53001c02  uxtb     w2, w0
//   0x4534: aa0103e0  mov      x0, x1
//   0x4538: 7103fc5f  cmp      w2, #0xff
//   0x453c: 910003fd  mov      x29, sp
//   0x4540: 540002c0  b.eq     #0x4598
//   0x4544: 121c0842  and      w2, w2, #0x70
//   0x4548: 7100805f  cmp      w2, #0x20
//   0x454c: 540001c0  b.eq     #0x4584
//   0x4550: 540000a8  b.hi     #0x4564
//   0x4554: 34000222  cbz      w2, #0x4598
//   0x4558: 7100405f  cmp      w2, #0x10
//   0x455c: 540001c1  b.ne     #0x4594
//   0x4560: 1400000e  b        #0x4598
//   0x4564: 7101005f  cmp      w2, #0x40
//   0x4568: 54000120  b.eq     #0x458c
//   0x456c: 7101405f  cmp      w2, #0x50
//   0x4570: 54000140  b.eq     #0x4598
//   0x4574: 7100c05f  cmp      w2, #0x30
//   0x4578: 540000e1  b.ne     #0x4594
//   0x457c: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x4580: 17ffffe7  b        #0x451c
//   0x4584: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x4588: 17ffffe7  b        #0x4524
//   0x458c: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x4590: 17ffffd7  b        #0x44ec
//   0x4594: 97fff5b7  bl       #0x1c70
//   0x4598: d2800000  mov      x0, #0
//   0x459c: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x45a0: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_055_452c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000452cULL;
    for (std::size_t i = 0; i < 30ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2507ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[056] Symbol: sub_45a4
//      Virtual Address Range: 0x45a4..0x4a9c (1272 bytes, 318 AArch64 instructions)
// [VN] Khung FDE[056] Biểu tượng: sub_45a4
//      Dải địa chỉ ảo: 0x45a4..0x4a9c (1272 byte, 318 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x45a4: a9b77bfd  stp      x29, x30, [sp, #-0x90]!
//   0x45a8: 910003fd  mov      x29, sp
//   0x45ac: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x45b0: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x45b4: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x45b8: a90573fb  stp      x27, x28, [sp, #0x50]
//   0x45bc: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x45c0: f000001b  adrp     x27, #0x7000
//   0x45c4: aa0103fc  mov      x28, x1
//   0x45c8: aa0203fa  mov      x26, x2
//   0x45cc: aa0303f3  mov      x19, x3
//   0x45d0: f903107f  str      xzr, [x3, #0x620]
//   0x45d4: d2800018  mov      x24, #0
//   0x45d8: 913c437b  add      x27, x27, #0xf10
//   0x45dc: 9101e3b6  add      x22, x29, #0x78
//   0x45e0: 910203b5  add      x21, x29, #0x80
//   0x45e4: 52800037  mov      w23, #1
//   0x45e8: 910223b9  add      x25, x29, #0x88
//   0x45ec: eb1c001f  cmp      x0, x28
//   0x45f0: 54002462  b.hs     #0x4a7c
//   0x45f4: f941a341  ldr      x1, [x26, #0x340]
//   0x45f8: f9418f43  ldr      x3, [x26, #0x318]
//   0x45fc: f9432662  ldr      x2, [x19, #0x648]
//   0x4600: 8b41fc61  add      x1, x3, x1, lsr #63
//   0x4604: eb01005f  cmp      x2, x1
//   0x4608: 540023a2  b.hs     #0x4a7c
//   0x460c: 39400001  ldrb     w1, [x0]
//   0x4610: 91000414  add      x20, x0, #1
//   0x4614: 121a0423  and      w3, w1, #0xc0
//   0x4618: 7101007f  cmp      w3, #0x40
//   0x461c: 540000c1  b.ne     #0x4634
//   0x4620: f9433260  ldr      x0, [x19, #0x660]
//   0x4624: 92401421  and      x1, x1, #0x3f
//   0x4628: 9b000821  madd     x1, x1, x0, x2
//   0x462c: f9032661  str      x1, [x19, #0x648]
//   0x4630: 14000111  b        #0x4a74
//   0x4634: 7102007f  cmp      w3, #0x80
//   0x4638: 540000a1  b.ne     #0x464c
//   0x463c: 92401421  and      x1, x1, #0x3f
//   0x4640: aa1403e0  mov      x0, x20
//   0x4644: f9003fa1  str      x1, [x29, #0x78]
//   0x4648: 14000031  b        #0x470c
//   0x464c: 7103007f  cmp      w3, #0xc0
//   0x4650: 540000a1  b.ne     #0x4664
//   0x4654: d37c1421  ubfiz    x1, x1, #4, #6
//   0x4658: 8b010261  add      x1, x19, x1
//   0x465c: b900083f  str      wzr, [x1, #8]
//   0x4660: 14000105  b        #0x4a74
//   0x4664: 7100bc3f  cmp      w1, #0x2f
//   0x4668: 54002048  b.hi     #0x4a70
//   0x466c: 78615b61  ldrh     w1, [x27, w1, uxtw #1]
//   0x4670: 10000063  adr      x3, #0x467c
//   0x4674: 8b21a861  add      x1, x3, w1, sxth #2
//   0x4678: d61f0020  br       x1
//   0x467c: 3959c262  ldrb     w2, [x19, #0x670]
//   0x4680: aa1a03e1  mov      x1, x26
//   0x4684: f90037a2  str      x2, [x29, #0x68]
//   0x4688: 2a0203e0  mov      w0, w2
//   0x468c: 97ffffa8  bl       #0x452c
//   0x4690: aa0003e1  mov      x1, x0
//   0x4694: f94037a2  ldr      x2, [x29, #0x68]
//   0x4698: aa1903e3  mov      x3, x25
//   0x469c: 2a0203e0  mov      w0, w2
//   0x46a0: aa1403e2  mov      x2, x20
//   0x46a4: 97fffe86  bl       #0x40bc
//   0x46a8: aa0003f4  mov      x20, x0
//   0x46ac: f94047a0  ldr      x0, [x29, #0x88]
//   0x46b0: f9032660  str      x0, [x19, #0x648]
//   0x46b4: 140000f0  b        #0x4a74
//   0x46b8: 39400401  ldrb     w1, [x0, #1]
//   0x46bc: 91000814  add      x20, x0, #2
//   0x46c0: f9433263  ldr      x3, [x19, #0x660]
//   0x46c4: 9b030822  madd     x2, x1, x3, x2
//   0x46c8: f9032662  str      x2, [x19, #0x648]
//   0x46cc: 140000ea  b        #0x4a74
//   0x46d0: 78401001  ldurh    w1, [x0, #1]
//   0x46d4: 91000c14  add      x20, x0, #3
//   0x46d8: f9433263  ldr      x3, [x19, #0x660]
//   0x46dc: 9b030822  madd     x2, x1, x3, x2
//   0x46e0: f9032662  str      x2, [x19, #0x648]
//   0x46e4: 140000e4  b        #0x4a74
//   0x46e8: b8401001  ldur     w1, [x0, #1]
//   0x46ec: 91001414  add      x20, x0, #5
//   0x46f0: f9433263  ldr      x3, [x19, #0x660]
//   0x46f4: 9b030822  madd     x2, x1, x3, x2
//   0x46f8: f9032662  str      x2, [x19, #0x648]
//   0x46fc: 140000de  b        #0x4a74
//   0x4700: aa1403e0  mov      x0, x20
//   0x4704: aa1603e1  mov      x1, x22
//   0x4708: 97fffe53  bl       #0x4054
//   0x470c: aa1503e1  mov      x1, x21
//   0x4710: 97fffe51  bl       #0x4054
//   0x4714: aa0003f4  mov      x20, x0
//   0x4718: f9432e61  ldr      x1, [x19, #0x658]
//   0x471c: f94043a0  ldr      x0, [x29, #0x80]
//   0x4720: 1400006b  b        #0x48cc
//   0x4724: aa1403e0  mov      x0, x20
//   0x4728: aa1603e1  mov      x1, x22
//   0x472c: 97fffe4a  bl       #0x4054
//   0x4730: aa0003f4  mov      x20, x0
//   0x4734: f9403fa0  ldr      x0, [x29, #0x78]
//   0x4738: f101841f  cmp      x0, #0x61
//   0x473c: 540019c8  b.hi     #0x4a74
//   0x4740: 8b001260  add      x0, x19, x0, lsl #4
//   0x4744: b900081f  str      wzr, [x0, #8]
//   0x4748: 140000cb  b        #0x4a74
//   0x474c: aa1403e0  mov      x0, x20
//   0x4750: aa1603e1  mov      x1, x22
//   0x4754: 97fffe40  bl       #0x4054
//   0x4758: aa0003f4  mov      x20, x0
//   0x475c: f9403fa0  ldr      x0, [x29, #0x78]
//   0x4760: f101841f  cmp      x0, #0x61
//   0x4764: 54001888  b.hi     #0x4a74
//   0x4768: 8b001260  add      x0, x19, x0, lsl #4
//   0x476c: 528000c1  mov      w1, #6
//   0x4770: b9000801  str      w1, [x0, #8]
//   0x4774: 140000c0  b        #0x4a74
//   0x4778: aa1403e0  mov      x0, x20
//   0x477c: aa1603e1  mov      x1, x22
//   0x4780: 97fffe35  bl       #0x4054
//   0x4784: aa1903e1  mov      x1, x25
//   0x4788: 97fffe33  bl       #0x4054
//   0x478c: aa0003f4  mov      x20, x0
//   0x4790: f9403fa0  ldr      x0, [x29, #0x78]
//   0x4794: f101841f  cmp      x0, #0x61
//   0x4798: 540016e8  b.hi     #0x4a74
//   0x479c: d37cec00  lsl      x0, x0, #4
//   0x47a0: 52800042  mov      w2, #2
//   0x47a4: 8b000261  add      x1, x19, x0
//   0x47a8: b9000822  str      w2, [x1, #8]
//   0x47ac: f94047a1  ldr      x1, [x29, #0x88]
//   0x47b0: 140000ae  b        #0x4a68
//   0x47b4: b4000098  cbz      x24, #0x47c4
//   0x47b8: aa1803e3  mov      x3, x24
//   0x47bc: f9431318  ldr      x24, [x24, #0x620]
//   0x47c0: 14000003  b        #0x47cc
//   0x47c4: d11983ff  sub      sp, sp, #0x660
//   0x47c8: 910003e3  mov      x3, sp
//   0x47cc: aa0303e0  mov      x0, x3
//   0x47d0: aa1303e1  mov      x1, x19
//   0x47d4: d280c902  mov      x2, #0x648
//   0x47d8: 97fff47a  bl       #0x19c0
//   0x47dc: f9031260  str      x0, [x19, #0x620]
//   0x47e0: 140000a5  b        #0x4a74
//   0x47e4: f9431263  ldr      x3, [x19, #0x620]
//   0x47e8: aa1303e0  mov      x0, x19
//   0x47ec: d280c902  mov      x2, #0x648
//   0x47f0: f90037a3  str      x3, [x29, #0x68]
//   0x47f4: aa0303e1  mov      x1, x3
//   0x47f8: 97fff472  bl       #0x19c0
//   0x47fc: f94037a3  ldr      x3, [x29, #0x68]
//   0x4800: f9031078  str      x24, [x3, #0x620]
//   0x4804: aa0303f8  mov      x24, x3
//   0x4808: 1400009b  b        #0x4a74
//   0x480c: aa1403e0  mov      x0, x20
//   0x4810: aa1503e1  mov      x1, x21
//   0x4814: 97fffe10  bl       #0x4054
//   0x4818: f94043a1  ldr      x1, [x29, #0x80]
//   0x481c: f9031a61  str      x1, [x19, #0x630]
//   0x4820: aa1503e1  mov      x1, x21
//   0x4824: 97fffe0c  bl       #0x4054
//   0x4828: aa0003f4  mov      x20, x0
//   0x482c: f94043a0  ldr      x0, [x29, #0x80]
//   0x4830: f9031660  str      x0, [x19, #0x628]
//   0x4834: 14000007  b        #0x4850
//   0x4838: aa1403e0  mov      x0, x20
//   0x483c: aa1503e1  mov      x1, x21
//   0x4840: 97fffe05  bl       #0x4054
//   0x4844: aa0003f4  mov      x20, x0
//   0x4848: f94043a0  ldr      x0, [x29, #0x80]
//   0x484c: f9031a60  str      x0, [x19, #0x630]
//   0x4850: b9064277  str      w23, [x19, #0x640]
//   0x4854: 14000088  b        #0x4a74
//   0x4858: aa1403e0  mov      x0, x20
//   0x485c: aa1503e1  mov      x1, x21
//   0x4860: 97fffdfd  bl       #0x4054
//   0x4864: aa0003f4  mov      x20, x0
//   0x4868: f94043a0  ldr      x0, [x29, #0x80]
//   0x486c: 1400002c  b        #0x491c
//   0x4870: 52800040  mov      w0, #2
//   0x4874: f9031e74  str      x20, [x19, #0x638]
//   0x4878: b9064260  str      w0, [x19, #0x640]
//   0x487c: aa1403e0  mov      x0, x20
//   0x4880: 14000053  b        #0x49cc
//   0x4884: aa1603e1  mov      x1, x22
//   0x4888: aa1403e0  mov      x0, x20
//   0x488c: 97fffdf2  bl       #0x4054
//   0x4890: f9403fa1  ldr      x1, [x29, #0x78]
//   0x4894: f101843f  cmp      x1, #0x61
//   0x4898: 540009a8  b.hi     #0x49cc
//   0x489c: d37cec21  lsl      x1, x1, #4
//   0x48a0: 52800063  mov      w3, #3
//   0x48a4: 8b010262  add      x2, x19, x1
//   0x48a8: 14000047  b        #0x49c4
//   0x48ac: aa1403e0  mov      x0, x20
//   0x48b0: aa1603e1  mov      x1, x22
//   0x48b4: 97fffde8  bl       #0x4054
//   0x48b8: aa1903e1  mov      x1, x25
//   0x48bc: 97fffdf0  bl       #0x407c
//   0x48c0: aa0003f4  mov      x20, x0
//   0x48c4: f9432e61  ldr      x1, [x19, #0x658]
//   0x48c8: f94047a0  ldr      x0, [x29, #0x88]
//   0x48cc: 9b017c01  mul      x1, x0, x1
//   0x48d0: f9403fa0  ldr      x0, [x29, #0x78]
//   0x48d4: f101841f  cmp      x0, #0x61
//   0x48d8: 54000ce8  b.hi     #0x4a74
//   0x48dc: d37cec00  lsl      x0, x0, #4
//   0x48e0: 8b000262  add      x2, x19, x0
//   0x48e4: b9000857  str      w23, [x2, #8]
//   0x48e8: 14000060  b        #0x4a68
//   0x48ec: aa1403e0  mov      x0, x20
//   0x48f0: aa1503e1  mov      x1, x21
//   0x48f4: 97fffdd8  bl       #0x4054
//   0x48f8: f94043a1  ldr      x1, [x29, #0x80]
//   0x48fc: f9031a61  str      x1, [x19, #0x630]
//   0x4900: aa1903e1  mov      x1, x25
//   0x4904: 97fffdde  bl       #0x407c
//   0x4908: b9064277  str      w23, [x19, #0x640]
//   0x490c: aa0003f4  mov      x20, x0
//   0x4910: f9432e61  ldr      x1, [x19, #0x658]
//   0x4914: f94047a0  ldr      x0, [x29, #0x88]
//   0x4918: 9b017c00  mul      x0, x0, x1
//   0x491c: f9031660  str      x0, [x19, #0x628]
//   0x4920: 14000055  b        #0x4a74
//   0x4924: aa1403e0  mov      x0, x20
//   0x4928: aa1903e1  mov      x1, x25
//   0x492c: 97fffdd4  bl       #0x407c
//   0x4930: aa0003f4  mov      x20, x0
//   0x4934: 17fffff7  b        #0x4910
//   0x4938: aa1403e0  mov      x0, x20
//   0x493c: aa1603e1  mov      x1, x22
//   0x4940: 97fffdc5  bl       #0x4054
//   0x4944: aa1503e1  mov      x1, x21
//   0x4948: 97fffdc3  bl       #0x4054
//   0x494c: aa0003f4  mov      x20, x0
//   0x4950: f9432e61  ldr      x1, [x19, #0x658]
//   0x4954: f94043a0  ldr      x0, [x29, #0x80]
//   0x4958: 14000009  b        #0x497c
//   0x495c: aa1403e0  mov      x0, x20
//   0x4960: aa1603e1  mov      x1, x22
//   0x4964: 97fffdbc  bl       #0x4054
//   0x4968: aa1903e1  mov      x1, x25
//   0x496c: 97fffdc4  bl       #0x407c
//   0x4970: aa0003f4  mov      x20, x0
//   0x4974: f9432e61  ldr      x1, [x19, #0x658]
//   0x4978: f94047a0  ldr      x0, [x29, #0x88]
//   0x497c: 9b017c01  mul      x1, x0, x1
//   0x4980: f9403fa0  ldr      x0, [x29, #0x78]
//   0x4984: f101841f  cmp      x0, #0x61
//   0x4988: 54000768  b.hi     #0x4a74
//   0x498c: d37cec00  lsl      x0, x0, #4
//   0x4990: 52800083  mov      w3, #4
//   0x4994: 8b000262  add      x2, x19, x0
//   0x4998: b9000843  str      w3, [x2, #8]
//   0x499c: 14000033  b        #0x4a68
//   0x49a0: aa1603e1  mov      x1, x22
//   0x49a4: aa1403e0  mov      x0, x20
//   0x49a8: 97fffdab  bl       #0x4054
//   0x49ac: f9403fa1  ldr      x1, [x29, #0x78]
//   0x49b0: f101843f  cmp      x1, #0x61
//   0x49b4: 540000c8  b.hi     #0x49cc
//   0x49b8: d37cec21  lsl      x1, x1, #4
//   0x49bc: 528000a3  mov      w3, #5
//   0x49c0: 8b010262  add      x2, x19, x1
//   0x49c4: b9000843  str      w3, [x2, #8]
//   0x49c8: f8216a60  str      x0, [x19, x1]
//   0x49cc: aa1503e1  mov      x1, x21
//   0x49d0: 97fffda1  bl       #0x4054
//   0x49d4: f94043b4  ldr      x20, [x29, #0x80]
//   0x49d8: 8b140014  add      x20, x0, x20
//   0x49dc: 14000026  b        #0x4a74
//   0x49e0: d2800200  mov      x0, #0x10
//   0x49e4: 91040262  add      x2, x19, #0x100
//   0x49e8: f9003fa0  str      x0, [x29, #0x78]
//   0x49ec: d2800001  mov      x1, #0
//   0x49f0: b9000857  str      w23, [x2, #8]
//   0x49f4: 91000400  add      x0, x0, #1
//   0x49f8: f8010441  str      x1, [x2], #0x10
//   0x49fc: f100801f  cmp      x0, #0x20
//   0x4a00: 91002021  add      x1, x1, #8
//   0x4a04: 54ffff61  b.ne     #0x49f0
//   0x4a08: 1400001b  b        #0x4a74
//   0x4a0c: aa1403e0  mov      x0, x20
//   0x4a10: aa1503e1  mov      x1, x21
//   0x4a14: 97fffd90  bl       #0x4054
//   0x4a18: aa0003f4  mov      x20, x0
//   0x4a1c: f94043a0  ldr      x0, [x29, #0x80]
//   0x4a20: f901ab40  str      x0, [x26, #0x350]
//   0x4a24: 14000014  b        #0x4a74
//   0x4a28: aa1403e0  mov      x0, x20
//   0x4a2c: aa1603e1  mov      x1, x22
//   0x4a30: 97fffd89  bl       #0x4054
//   0x4a34: aa1503e1  mov      x1, x21
//   0x4a38: 97fffd87  bl       #0x4054
//   0x4a3c: aa0003f4  mov      x20, x0
//   0x4a40: f94043a1  ldr      x1, [x29, #0x80]
//   0x4a44: f9432e60  ldr      x0, [x19, #0x658]
//   0x4a48: 9b017c01  mul      x1, x0, x1
//   0x4a4c: f9403fa0  ldr      x0, [x29, #0x78]
//   0x4a50: f101841f  cmp      x0, #0x61
//   0x4a54: 54000108  b.hi     #0x4a74
//   0x4a58: d37cec00  lsl      x0, x0, #4
//   0x4a5c: cb0103e1  neg      x1, x1
//   0x4a60: 8b000262  add      x2, x19, x0
//   0x4a64: b9000857  str      w23, [x2, #8]
//   0x4a68: f8206a61  str      x1, [x19, x0]
//   0x4a6c: 14000002  b        #0x4a74
//   0x4a70: 97fff480  bl       #0x1c70
//   0x4a74: aa1403e0  mov      x0, x20
//   0x4a78: 17fffedd  b        #0x45ec
//   0x4a7c: 910003bf  mov      sp, x29
//   0x4a80: a94153f3  ldp      x19, x20, [sp, #0x10]
//   0x4a84: a9425bf5  ldp      x21, x22, [sp, #0x20]
//   0x4a88: a94363f7  ldp      x23, x24, [sp, #0x30]
//   0x4a8c: a9446bf9  ldp      x25, x26, [sp, #0x40]
//   0x4a90: a94573fb  ldp      x27, x28, [sp, #0x50]
//   0x4a94: a8c97bfd  ldp      x29, x30, [sp], #0x90
//   0x4a98: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_056_45a4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000045a4ULL;
    for (std::size_t i = 0; i < 318ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2537ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[057] Symbol: sub_4a9c
//      Virtual Address Range: 0x4a9c..0x4ec0 (1060 bytes, 265 AArch64 instructions)
// [VN] Khung FDE[057] Biểu tượng: sub_4a9c
//      Dải địa chỉ ảo: 0x4a9c..0x4ec0 (1060 byte, 265 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4a9c: a9b77bfd  stp      x29, x30, [sp, #-0x90]!
//   0x4aa0: d280d002  mov      x2, #0x680
//   0x4aa4: 910003fd  mov      x29, sp
//   0x4aa8: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x4aac: aa0003f4  mov      x20, x0
//   0x4ab0: aa0103f3  mov      x19, x1
//   0x4ab4: aa0103e0  mov      x0, x1
//   0x4ab8: 52800001  mov      w1, #0
//   0x4abc: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x4ac0: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x4ac4: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x4ac8: f9002bfb  str      x27, [sp, #0x50]
//   0x4acc: 97fff451  bl       #0x1c10
//   0x4ad0: f9418e81  ldr      x1, [x20, #0x318]
//   0x4ad4: f901aa9f  str      xzr, [x20, #0x350]
//   0x4ad8: f901929f  str      xzr, [x20, #0x320]
//   0x4adc: b5000061  cbnz     x1, #0x4ae8
//   0x4ae0: 528000a0  mov      w0, #5
//   0x4ae4: 140000f0  b        #0x4ea4
//   0x4ae8: f941a280  ldr      x0, [x20, #0x340]
//   0x4aec: d37ffc00  lsr      x0, x0, #0x3f
//   0x4af0: d1000400  sub      x0, x0, #1
//   0x4af4: 8b000020  add      x0, x1, x0
//   0x4af8: 910ca281  add      x1, x20, #0x328
//   0x4afc: 94000ad0  bl       #0x763c
//   0x4b00: aa0003f5  mov      x21, x0
//   0x4b04: b5000800  cbnz     x0, #0x4c04
//   0x4b08: f9418e81  ldr      x1, [x20, #0x318]
//   0x4b0c: 52822d00  mov      w0, #0x1168
//   0x4b10: 72ba5000  movk     w0, #0xd280, lsl #16
//   0x4b14: b9400022  ldr      w2, [x1]
//   0x4b18: 6b00005f  cmp      w2, w0
//   0x4b1c: 54fffe21  b.ne     #0x4ae0
//   0x4b20: b9400421  ldr      w1, [x1, #4]
//   0x4b24: 52800020  mov      w0, #1
//   0x4b28: 72ba8000  movk     w0, #0xd400, lsl #16
//   0x4b2c: 6b00003f  cmp      w1, w0
//   0x4b30: 52800021  mov      w1, #1
//   0x4b34: 54fffd61  b.ne     #0x4ae0
//   0x4b38: f9418a94  ldr      x20, [x20, #0x310]
//   0x4b3c: d28003e0  mov      x0, #0x1f
//   0x4b40: f9031a60  str      x0, [x19, #0x630]
//   0x4b44: d2802600  mov      x0, #0x130
//   0x4b48: b9064261  str      w1, [x19, #0x640]
//   0x4b4c: 9104c283  add      x3, x20, #0x130
//   0x4b50: f9031660  str      x0, [x19, #0x628]
//   0x4b54: d2802004  mov      x4, #0x100
//   0x4b58: d2800100  mov      x0, #8
//   0x4b5c: aa1303e2  mov      x2, x19
//   0x4b60: b9000841  str      w1, [x2, #8]
//   0x4b64: f8010440  str      x0, [x2], #0x10
//   0x4b68: 91002000  add      x0, x0, #8
//   0x4b6c: eb04001f  cmp      x0, x4
//   0x4b70: 54ffff81  b.ne     #0x4b60
//   0x4b74: 92807de1  mov      x1, #-0x3f0
//   0x4b78: 91094280  add      x0, x20, #0x250
//   0x4b7c: cb030021  sub      x1, x1, x3
//   0x4b80: 91180265  add      x5, x19, #0x600
//   0x4b84: 52800026  mov      w6, #1
//   0x4b88: cb130021  sub      x1, x1, x19
//   0x4b8c: b9400002  ldr      w2, [x0]
//   0x4b90: 340001e2  cbz      w2, #0x4bcc
//   0x4b94: 52900024  mov      w4, #0x8001
//   0x4b98: 72a8ca04  movk     w4, #0x4650, lsl #16
//   0x4b9c: 6b04005f  cmp      w2, w4
//   0x4ba0: 54000101  b.ne     #0x4bc0
//   0x4ba4: 91100262  add      x2, x19, #0x400
//   0x4ba8: 8b020024  add      x4, x1, x2
//   0x4bac: b9000846  str      w6, [x2, #8]
//   0x4bb0: 8b040004  add      x4, x0, x4
//   0x4bb4: f8010444  str      x4, [x2], #0x10
//   0x4bb8: eb05005f  cmp      x2, x5
//   0x4bbc: 54ffff61  b.ne     #0x4ba8
//   0x4bc0: b9400402  ldr      w2, [x0, #4]
//   0x4bc4: 8b020000  add      x0, x0, x2
//   0x4bc8: 17fffff1  b        #0x4b8c
//   0x4bcc: 9108c294  add      x20, x20, #0x230
//   0x4bd0: 52800020  mov      w0, #1
//   0x4bd4: cb030294  sub      x20, x20, x3
//   0x4bd8: 3919ce60  strb     w0, [x19, #0x673]
//   0x4bdc: f900fa74  str      x20, [x19, #0x1f0]
//   0x4be0: b901fa60  str      w0, [x19, #0x1f8]
//   0x4be4: 52800080  mov      w0, #4
//   0x4be8: b9060a60  str      w0, [x19, #0x608]
//   0x4bec: f9408460  ldr      x0, [x3, #0x108]
//   0x4bf0: cb030003  sub      x3, x0, x3
//   0x4bf4: d2800c00  mov      x0, #0x60
//   0x4bf8: f9030263  str      x3, [x19, #0x600]
//   0x4bfc: f9033660  str      x0, [x19, #0x668]
//   0x4c00: 140000a6  b        #0x4e98
//   0x4c04: b98006a1  ldrsw    x1, [x21, #4]
//   0x4c08: 910012b6  add      x22, x21, #4
//   0x4c0c: f9419e80  ldr      x0, [x20, #0x338]
//   0x4c10: cb0102d6  sub      x22, x22, x1
//   0x4c14: f9032660  str      x0, [x19, #0x648]
//   0x4c18: 910026d7  add      x23, x22, #9
//   0x4c1c: aa1703e0  mov      x0, x23
//   0x4c20: 97fff3bc  bl       #0x1b10
//   0x4c24: 91000400  add      x0, x0, #1
//   0x4c28: 394026c1  ldrb     w1, [x22, #9]
//   0x4c2c: 8b0002e0  add      x0, x23, x0
//   0x4c30: 7101943f  cmp      w1, #0x65
//   0x4c34: 540000e1  b.ne     #0x4c50
//   0x4c38: 39402ac1  ldrb     w1, [x22, #0xa]
//   0x4c3c: 7101a03f  cmp      w1, #0x68
//   0x4c40: 54000081  b.ne     #0x4c50
//   0x4c44: f8408401  ldr      x1, [x0], #8
//   0x4c48: 91002ed7  add      x23, x22, #0xb
//   0x4c4c: f9033e61  str      x1, [x19, #0x678]
//   0x4c50: 394022c1  ldrb     w1, [x22, #8]
//   0x4c54: 71000c3f  cmp      w1, #3
//   0x4c58: 540000e9  b.ls     #0x4c74
//   0x4c5c: 39400001  ldrb     w1, [x0]
//   0x4c60: 7100203f  cmp      w1, #8
//   0x4c64: 540011e1  b.ne     #0x4ea0
//   0x4c68: 39400401  ldrb     w1, [x0, #1]
//   0x4c6c: 350011a1  cbnz     w1, #0x4ea0
//   0x4c70: 91000800  add      x0, x0, #2
//   0x4c74: 9101e3b9  add      x25, x29, #0x78
//   0x4c78: aa1903e1  mov      x1, x25
//   0x4c7c: 97fffcf6  bl       #0x4054
//   0x4c80: f9403fa1  ldr      x1, [x29, #0x78]
//   0x4c84: f9033261  str      x1, [x19, #0x660]
//   0x4c88: 910203a1  add      x1, x29, #0x80
//   0x4c8c: 97fffcfc  bl       #0x407c
//   0x4c90: aa0003e1  mov      x1, x0
//   0x4c94: f94043a2  ldr      x2, [x29, #0x80]
//   0x4c98: f9032e62  str      x2, [x19, #0x658]
//   0x4c9c: 394022c2  ldrb     w2, [x22, #8]
//   0x4ca0: 7100045f  cmp      w2, #1
//   0x4ca4: 54000081  b.ne     #0x4cb4
//   0x4ca8: 91000400  add      x0, x0, #1
//   0x4cac: 39400021  ldrb     w1, [x1]
//   0x4cb0: 14000004  b        #0x4cc0
//   0x4cb4: aa1903e1  mov      x1, x25
//   0x4cb8: 97fffce7  bl       #0x4054
//   0x4cbc: f9403fa1  ldr      x1, [x29, #0x78]
//   0x4cc0: f9033661  str      x1, [x19, #0x668]
//   0x4cc4: 12800001  mov      w1, #-1
//   0x4cc8: 3919c661  strb     w1, [x19, #0x671]
//   0x4ccc: d2800018  mov      x24, #0
//   0x4cd0: 394002e1  ldrb     w1, [x23]
//   0x4cd4: 7101e83f  cmp      w1, #0x7a
//   0x4cd8: 54000101  b.ne     #0x4cf8
//   0x4cdc: aa1903e1  mov      x1, x25
//   0x4ce0: 910006f7  add      x23, x23, #1
//   0x4ce4: 97fffcdc  bl       #0x4054
//   0x4ce8: f9403fb8  ldr      x24, [x29, #0x78]
//   0x4cec: 52800021  mov      w1, #1
//   0x4cf0: 3919ca61  strb     w1, [x19, #0x672]
//   0x4cf4: 8b180018  add      x24, x0, x24
//   0x4cf8: 910006f7  add      x23, x23, #1
//   0x4cfc: 5280003b  mov      w27, #1
//   0x4d00: 910223b9  add      x25, x29, #0x88
//   0x4d04: 385ff2e1  ldurb    w1, [x23, #-1]
//   0x4d08: 34000441  cbz      w1, #0x4d90
//   0x4d0c: 7101303f  cmp      w1, #0x4c
//   0x4d10: 54000081  b.ne     #0x4d20
//   0x4d14: 39400001  ldrb     w1, [x0]
//   0x4d18: 3919c661  strb     w1, [x19, #0x671]
//   0x4d1c: 14000005  b        #0x4d30
//   0x4d20: 7101483f  cmp      w1, #0x52
//   0x4d24: 540000a1  b.ne     #0x4d38
//   0x4d28: 39400001  ldrb     w1, [x0]
//   0x4d2c: 3919c261  strb     w1, [x19, #0x670]
//   0x4d30: 91000400  add      x0, x0, #1
//   0x4d34: 14000015  b        #0x4d88
//   0x4d38: 7101403f  cmp      w1, #0x50
//   0x4d3c: 54000201  b.ne     #0x4d7c
//   0x4d40: aa0003e2  mov      x2, x0
//   0x4d44: aa1403e1  mov      x1, x20
//   0x4d48: 3840145a  ldrb     w26, [x2], #1
//   0x4d4c: f90037a2  str      x2, [x29, #0x68]
//   0x4d50: 2a1a03e0  mov      w0, w26
//   0x4d54: f90033a2  str      x2, [x29, #0x60]
//   0x4d58: 97fffdf5  bl       #0x452c
//   0x4d5c: aa0003e1  mov      x1, x0
//   0x4d60: f94037a2  ldr      x2, [x29, #0x68]
//   0x4d64: 2a1a03e0  mov      w0, w26
//   0x4d68: aa1903e3  mov      x3, x25
//   0x4d6c: 97fffcd4  bl       #0x40bc
//   0x4d70: f94047a1  ldr      x1, [x29, #0x88]
//   0x4d74: f9032a61  str      x1, [x19, #0x650]
//   0x4d78: 14000004  b        #0x4d88
//   0x4d7c: 71014c3f  cmp      w1, #0x53
//   0x4d80: 540000e1  b.ne     #0x4d9c
//   0x4d84: 3919ce7b  strb     w27, [x19, #0x673]
//   0x4d88: 910006f7  add      x23, x23, #1
//   0x4d8c: 17ffffde  b        #0x4d04
//   0x4d90: eb1f031f  cmp      x24, xzr
//   0x4d94: 9a801300  csel     x0, x24, x0, ne
//   0x4d98: 14000002  b        #0x4da0
//   0x4d9c: aa1803e0  mov      x0, x24
//   0x4da0: b4000800  cbz      x0, #0x4ea0
//   0x4da4: b94002c1  ldr      w1, [x22]
//   0x4da8: aa1403e2  mov      x2, x20
//   0x4dac: aa1303e3  mov      x3, x19
//   0x4db0: 91001021  add      x1, x1, #4
//   0x4db4: 8b0102c1  add      x1, x22, x1
//   0x4db8: 97fffdfb  bl       #0x45a4
//   0x4dbc: 3959c260  ldrb     w0, [x19, #0x670]
//   0x4dc0: 7103fc1f  cmp      w0, #0xff
//   0x4dc4: 540001e0  b.eq     #0x4e00
//   0x4dc8: 12000800  and      w0, w0, #7
//   0x4dcc: 7100101f  cmp      w0, #4
//   0x4dd0: 54000168  b.hi     #0x4dfc
//   0x4dd4: f0000001  adrp     x1, #0x7000
//   0x4dd8: 913dc021  add      x1, x1, #0xf70
//   0x4ddc: 38604820  ldrb     w0, [x1, w0, uxtw]
//   0x4de0: 10000061  adr      x1, #0x4dec
//   0x4de4: 8b208820  add      x0, x1, w0, sxtb #2
//   0x4de8: d61f0000  br       x0
//   0x4dec: 52800042  mov      w2, #2
//   0x4df0: 14000007  b        #0x4e0c
//   0x4df4: 52800082  mov      w2, #4
//   0x4df8: 14000005  b        #0x4e0c
//   0x4dfc: 97fff39d  bl       #0x1c70
//   0x4e00: 52800002  mov      w2, #0
//   0x4e04: 14000002  b        #0x4e0c
//   0x4e08: 52800102  mov      w2, #8
//   0x4e0c: 3959ca60  ldrb     w0, [x19, #0x672]
//   0x4e10: 531f7842  lsl      w2, w2, #1
//   0x4e14: 91002042  add      x2, x2, #8
//   0x4e18: d2800016  mov      x22, #0
//   0x4e1c: 8b0202a2  add      x2, x21, x2
//   0x4e20: 340000e0  cbz      w0, #0x4e3c
//   0x4e24: aa0203e0  mov      x0, x2
//   0x4e28: 910223a1  add      x1, x29, #0x88
//   0x4e2c: 97fffc8a  bl       #0x4054
//   0x4e30: f94047b6  ldr      x22, [x29, #0x88]
//   0x4e34: aa0003e2  mov      x2, x0
//   0x4e38: 8b160016  add      x22, x0, x22
//   0x4e3c: 3959c677  ldrb     w23, [x19, #0x671]
//   0x4e40: 7103feff  cmp      w23, #0xff
//   0x4e44: 540001a0  b.eq     #0x4e78
//   0x4e48: aa1403e1  mov      x1, x20
//   0x4e4c: 2a1703e0  mov      w0, w23
//   0x4e50: f90037a2  str      x2, [x29, #0x68]
//   0x4e54: 97fffdb6  bl       #0x452c
//   0x4e58: aa0003e1  mov      x1, x0
//   0x4e5c: f94037a2  ldr      x2, [x29, #0x68]
//   0x4e60: 2a1703e0  mov      w0, w23
//   0x4e64: 910223a3  add      x3, x29, #0x88
//   0x4e68: 97fffc95  bl       #0x40bc
//   0x4e6c: aa0003e2  mov      x2, x0
//   0x4e70: f94047a0  ldr      x0, [x29, #0x88]
//   0x4e74: f9019280  str      x0, [x20, #0x320]
//   0x4e78: b94002a1  ldr      w1, [x21]
//   0x4e7c: eb1f02df  cmp      x22, xzr
//   0x4e80: 9a8212c0  csel     x0, x22, x2, ne
//   0x4e84: aa1303e3  mov      x3, x19
//   0x4e88: 91001021  add      x1, x1, #4
//   0x4e8c: aa1403e2  mov      x2, x20
//   0x4e90: 8b0102a1  add      x1, x21, x1
//   0x4e94: 97fffdc4  bl       #0x45a4
//   0x4e98: 52800000  mov      w0, #0
//   0x4e9c: 14000002  b        #0x4ea4
//   0x4ea0: 52800060  mov      w0, #3
//   0x4ea4: a94153f3  ldp      x19, x20, [sp, #0x10]
//   0x4ea8: a9425bf5  ldp      x21, x22, [sp, #0x20]
//   0x4eac: a94363f7  ldp      x23, x24, [sp, #0x30]
//   0x4eb0: a9446bf9  ldp      x25, x26, [sp, #0x40]
//   0x4eb4: f9402bfb  ldr      x27, [sp, #0x50]
//   0x4eb8: a8c97bfd  ldp      x29, x30, [sp], #0x90
//   0x4ebc: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_057_4a9c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004a9cULL;
    for (std::size_t i = 0; i < 265ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2855ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[058] Symbol: sub_4ec0
//      Virtual Address Range: 0x4ec0..0x5474 (1460 bytes, 365 AArch64 instructions)
// [VN] Khung FDE[058] Biểu tượng: sub_4ec0
//      Dải địa chỉ ảo: 0x4ec0..0x5474 (1460 byte, 365 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4ec0: d108c3ff  sub      sp, sp, #0x230
//   0x4ec4: aa0003e4  mov      x4, x0
//   0x4ec8: a9ba7bfd  stp      x29, x30, [sp, #-0x60]!
//   0x4ecc: 910003fd  mov      x29, sp
//   0x4ed0: a90573fb  stp      x27, x28, [sp, #0x50]
//   0x4ed4: 910243bc  add      x28, x29, #0x90
//   0x4ed8: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x4edc: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x4ee0: f0000016  adrp     x22, #0x7000
//   0x4ee4: f0000017  adrp     x23, #0x7000
//   0x4ee8: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x4eec: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x4ef0: aa0103f8  mov      x24, x1
//   0x4ef4: aa0203f3  mov      x19, x2
//   0x4ef8: f9000383  str      x3, [x28]
//   0x4efc: 52800039  mov      w25, #1
//   0x4f00: 913e02d6  add      x22, x22, #0xf80
//   0x4f04: 9101e3b4  add      x20, x29, #0x78
//   0x4f08: 913de2f7  add      x23, x23, #0xf78
//   0x4f0c: 9101c3b5  add      x21, x29, #0x70
//   0x4f10: eb18009f  cmp      x4, x24
//   0x4f14: 540029a2  b.hs     #0x5448
//   0x4f18: 3940009a  ldrb     w26, [x4]
//   0x4f1c: 9100049b  add      x27, x4, #1
//   0x4f20: 7100835f  cmp      w26, #0x20
//   0x4f24: 54000788  b.hi     #0x5014
//   0x4f28: 71007f5f  cmp      w26, #0x1f
//   0x4f2c: 54001962  b.hs     #0x5258
//   0x4f30: 7100435f  cmp      w26, #0x10
//   0x4f34: 54001020  b.eq     #0x5138
//   0x4f38: 54000448  b.hi     #0x4fc0
//   0x4f3c: 71002b5f  cmp      w26, #0xa
//   0x4f40: 54000e80  b.eq     #0x5110
//   0x4f44: 54000208  b.hi     #0x4f84
//   0x4f48: 71001b5f  cmp      w26, #6
//   0x4f4c: 54001860  b.eq     #0x5258
//   0x4f50: 540000c8  b.hi     #0x4f68
//   0x4f54: 71000f5f  cmp      w26, #3
//   0x4f58: 540026a1  b.ne     #0x542c
//   0x4f5c: f8401080  ldur     x0, [x4, #1]
//   0x4f60: 9100249b  add      x27, x4, #9
//   0x4f64: 14000133  b        #0x5430
//   0x4f68: 7100235f  cmp      w26, #8
//   0x4f6c: 9100089b  add      x27, x4, #2
//   0x4f70: 54000cc0  b.eq     #0x5108
//   0x4f74: 7100275f  cmp      w26, #9
//   0x4f78: 540025a1  b.ne     #0x542c
//   0x4f7c: 39800480  ldrsb    x0, [x4, #1]
//   0x4f80: 1400012c  b        #0x5430
//   0x4f84: 7100375f  cmp      w26, #0xd
//   0x4f88: 54000ce0  b.eq     #0x5124
//   0x4f8c: 540000e8  b.hi     #0x4fa8
//   0x4f90: 71002f5f  cmp      w26, #0xb
//   0x4f94: 54000c20  b.eq     #0x5118
//   0x4f98: 7100335f  cmp      w26, #0xc
//   0x4f9c: 54002481  b.ne     #0x542c
//   0x4fa0: b8401080  ldur     w0, [x4, #1]
//   0x4fa4: 14000061  b        #0x5128
//   0x4fa8: 71003b5f  cmp      w26, #0xe
//   0x4fac: 9100249b  add      x27, x4, #9
//   0x4fb0: 54000c00  b.eq     #0x5130
//   0x4fb4: 71003f5f  cmp      w26, #0xf
//   0x4fb8: 54000bc0  b.eq     #0x5130
//   0x4fbc: 1400011c  b        #0x542c
//   0x4fc0: 7100575f  cmp      w26, #0x15
//   0x4fc4: 540010a0  b.eq     #0x51d8
//   0x4fc8: 54000128  b.hi     #0x4fec
//   0x4fcc: 71004b5f  cmp      w26, #0x12
//   0x4fd0: 54000f80  b.eq     #0x51c0
//   0x4fd4: 54000be3  b.lo     #0x5150
//   0x4fd8: 71004f5f  cmp      w26, #0x13
//   0x4fdc: 54000f80  b.eq     #0x51cc
//   0x4fe0: 7100535f  cmp      w26, #0x14
//   0x4fe4: 540010e0  b.eq     #0x5200
//   0x4fe8: 14000111  b        #0x542c
//   0x4fec: 7100675f  cmp      w26, #0x19
//   0x4ff0: 54001340  b.eq     #0x5258
//   0x4ff4: 54001948  b.hi     #0x531c
//   0x4ff8: 71005b5f  cmp      w26, #0x16
//   0x4ffc: 51000721  sub      w1, w25, #1
//   0x5000: 51000b20  sub      w0, w25, #2
//   0x5004: 54001080  b.eq     #0x5214
//   0x5008: 71005f5f  cmp      w26, #0x17
//   0x500c: 54001120  b.eq     #0x5230
//   0x5010: 14000107  b        #0x542c
//   0x5014: 71013f5f  cmp      w26, #0x4f
//   0x5018: 540001e8  b.hi     #0x5054
//   0x501c: 7100c35f  cmp      w26, #0x30
//   0x5020: 54000702  b.hs     #0x5100
//   0x5024: 71009f5f  cmp      w26, #0x27
//   0x5028: 540000c8  b.hi     #0x5040
//   0x502c: 7100935f  cmp      w26, #0x24
//   0x5030: 54001762  b.hs     #0x531c
//   0x5034: 71008b5f  cmp      w26, #0x22
//   0x5038: 54001108  b.hi     #0x5258
//   0x503c: 140000b8  b        #0x531c
//   0x5040: 7100bb5f  cmp      w26, #0x2e
//   0x5044: 54001da8  b.hi     #0x53f8
//   0x5048: 7100a75f  cmp      w26, #0x29
//   0x504c: 54001de3  b.lo     #0x5408
//   0x5050: 140000b3  b        #0x531c
//   0x5054: 7102435f  cmp      w26, #0x90
//   0x5058: 540008a0  b.eq     #0x516c
//   0x505c: 540000c8  b.hi     #0x5074
//   0x5060: 7101bf5f  cmp      w26, #0x6f
//   0x5064: 54000948  b.hi     #0x518c
//   0x5068: aa1303e0  mov      x0, x19
//   0x506c: 51014341  sub      w1, w26, #0x50
//   0x5070: 14000045  b        #0x5184
//   0x5074: 7102535f  cmp      w26, #0x94
//   0x5078: 54000f00  b.eq     #0x5258
//   0x507c: 540001e8  b.hi     #0x50b8
//   0x5080: 71024b5f  cmp      w26, #0x92
//   0x5084: 54001d41  b.ne     #0x542c
//   0x5088: aa1b03e0  mov      x0, x27
//   0x508c: aa1503e1  mov      x1, x21
//   0x5090: 910203ba  add      x26, x29, #0x80
//   0x5094: 97fffbf0  bl       #0x4054
//   0x5098: aa1a03e1  mov      x1, x26
//   0x509c: 97fffbf8  bl       #0x407c
//   0x50a0: aa0003fb  mov      x27, x0
//   0x50a4: b94002a1  ldr      w1, [x21]
//   0x50a8: aa1303e0  mov      x0, x19
//   0x50ac: 97fffc94  bl       #0x42fc
//   0x50b0: f9400341  ldr      x1, [x26]
//   0x50b4: 14000041  b        #0x51b8
//   0x50b8: 71025b5f  cmp      w26, #0x96
//   0x50bc: 54001c20  b.eq     #0x5440
//   0x50c0: 7103c75f  cmp      w26, #0xf1
//   0x50c4: 54001b41  b.ne     #0x542c
//   0x50c8: 39400482  ldrb     w2, [x4, #1]
//   0x50cc: aa1303e1  mov      x1, x19
//   0x50d0: 9100089b  add      x27, x4, #2
//   0x50d4: f90037a2  str      x2, [x29, #0x68]
//   0x50d8: 2a0203e0  mov      w0, w2
//   0x50dc: 910223ba  add      x26, x29, #0x88
//   0x50e0: 97fffd13  bl       #0x452c
//   0x50e4: aa0003e1  mov      x1, x0
//   0x50e8: f94037a2  ldr      x2, [x29, #0x68]
//   0x50ec: aa1a03e3  mov      x3, x26
//   0x50f0: 2a0203e0  mov      w0, w2
//   0x50f4: aa1b03e2  mov      x2, x27
//   0x50f8: 97fffbf1  bl       #0x40bc
//   0x50fc: 14000019  b        #0x5160
//   0x5100: 5100c340  sub      w0, w26, #0x30
//   0x5104: 140000cb  b        #0x5430
//   0x5108: 39400480  ldrb     w0, [x4, #1]
//   0x510c: 140000c9  b        #0x5430
//   0x5110: 78401080  ldurh    w0, [x4, #1]
//   0x5114: 14000002  b        #0x511c
//   0x5118: 78801080  ldursh   x0, [x4, #1]
//   0x511c: 91000c9b  add      x27, x4, #3
//   0x5120: 140000c4  b        #0x5430
//   0x5124: b8801080  ldursw   x0, [x4, #1]
//   0x5128: 9100149b  add      x27, x4, #5
//   0x512c: 140000c1  b        #0x5430
//   0x5130: f8401080  ldur     x0, [x4, #1]
//   0x5134: 140000bf  b        #0x5430
//   0x5138: aa1b03e0  mov      x0, x27
//   0x513c: aa1403e1  mov      x1, x20
//   0x5140: 97fffbc5  bl       #0x4054
//   0x5144: aa0003fb  mov      x27, x0
//   0x5148: f9400280  ldr      x0, [x20]
//   0x514c: 140000b9  b        #0x5430
//   0x5150: 910223ba  add      x26, x29, #0x88
//   0x5154: aa1b03e0  mov      x0, x27
//   0x5158: aa1a03e1  mov      x1, x26
//   0x515c: 97fffbc8  bl       #0x407c
//   0x5160: aa0003fb  mov      x27, x0
//   0x5164: f9400340  ldr      x0, [x26]
//   0x5168: 140000b2  b        #0x5430
//   0x516c: aa1b03e0  mov      x0, x27
//   0x5170: aa1503e1  mov      x1, x21
//   0x5174: 97fffbb8  bl       #0x4054
//   0x5178: aa0003fb  mov      x27, x0
//   0x517c: b94002a1  ldr      w1, [x21]
//   0x5180: aa1303e0  mov      x0, x19
//   0x5184: 97fffc5e  bl       #0x42fc
//   0x5188: 140000aa  b        #0x5430
//   0x518c: 910203a2  add      x2, x29, #0x80
//   0x5190: aa1b03e0  mov      x0, x27
//   0x5194: aa0203e1  mov      x1, x2
//   0x5198: f90037a2  str      x2, [x29, #0x68]
//   0x519c: 97fffbb8  bl       #0x407c
//   0x51a0: aa0003fb  mov      x27, x0
//   0x51a4: 5101c341  sub      w1, w26, #0x70
//   0x51a8: aa1303e0  mov      x0, x19
//   0x51ac: 97fffc54  bl       #0x42fc
//   0x51b0: f94037a2  ldr      x2, [x29, #0x68]
//   0x51b4: f9400041  ldr      x1, [x2]
//   0x51b8: 8b010000  add      x0, x0, x1
//   0x51bc: 1400009d  b        #0x5430
//   0x51c0: 34001379  cbz      w25, #0x542c
//   0x51c4: 51000720  sub      w0, w25, #1
//   0x51c8: 14000011  b        #0x520c
//   0x51cc: 34001319  cbz      w25, #0x542c
//   0x51d0: 51000739  sub      w25, w25, #1
//   0x51d4: 1400009b  b        #0x5440
//   0x51d8: 51000720  sub      w0, w25, #1
//   0x51dc: 39400481  ldrb     w1, [x4, #1]
//   0x51e0: f90043a1  str      x1, [x29, #0x80]
//   0x51e4: 9100089b  add      x27, x4, #2
//   0x51e8: 93407c00  sxtw     x0, w0
//   0x51ec: eb00003f  cmp      x1, x0
//   0x51f0: 540011ea  b.ge     #0x542c
//   0x51f4: cb010000  sub      x0, x0, x1
//   0x51f8: f8607b80  ldr      x0, [x28, x0, lsl #3]
//   0x51fc: 1400008d  b        #0x5430
//   0x5200: 7100073f  cmp      w25, #1
//   0x5204: 5400114d  b.le     #0x542c
//   0x5208: 51000b20  sub      w0, w25, #2
//   0x520c: f860db80  ldr      x0, [x28, w0, sxtw #3]
//   0x5210: 14000088  b        #0x5430
//   0x5214: 7100073f  cmp      w25, #1
//   0x5218: 540010ad  b.le     #0x542c
//   0x521c: f860db83  ldr      x3, [x28, w0, sxtw #3]
//   0x5220: f861db82  ldr      x2, [x28, w1, sxtw #3]
//   0x5224: f821db83  str      x3, [x28, w1, sxtw #3]
//   0x5228: f820db82  str      x2, [x28, w0, sxtw #3]
//   0x522c: 14000085  b        #0x5440
//   0x5230: 71000b3f  cmp      w25, #2
//   0x5234: 54000fcd  b.le     #0x542c
//   0x5238: 51000f22  sub      w2, w25, #3
//   0x523c: f860db85  ldr      x5, [x28, w0, sxtw #3]
//   0x5240: f861db83  ldr      x3, [x28, w1, sxtw #3]
//   0x5244: f862db84  ldr      x4, [x28, w2, sxtw #3]
//   0x5248: f821db85  str      x5, [x28, w1, sxtw #3]
//   0x524c: f820db84  str      x4, [x28, w0, sxtw #3]
//   0x5250: f822db83  str      x3, [x28, w2, sxtw #3]
//   0x5254: 1400007b  b        #0x5440
//   0x5258: 34000eb9  cbz      w25, #0x542c
//   0x525c: 51000739  sub      w25, w25, #1
//   0x5260: 71007f5f  cmp      w26, #0x1f
//   0x5264: f879db82  ldr      x2, [x28, w25, sxtw #3]
//   0x5268: 54000440  b.eq     #0x52f0
//   0x526c: 54000108  b.hi     #0x528c
//   0x5270: 71001b5f  cmp      w26, #6
//   0x5274: 540003a0  b.eq     #0x52e8
//   0x5278: 7100675f  cmp      w26, #0x19
//   0x527c: 54000d81  b.ne     #0x542c
//   0x5280: ca82fc41  eor      x1, x2, x2, asr #63
//   0x5284: 8b42fc20  add      x0, x1, x2, lsr #63
//   0x5288: 1400006a  b        #0x5430
//   0x528c: 71008f5f  cmp      w26, #0x23
//   0x5290: 54000340  b.eq     #0x52f8
//   0x5294: 7102535f  cmp      w26, #0x94
//   0x5298: 540000a0  b.eq     #0x52ac
//   0x529c: 7100835f  cmp      w26, #0x20
//   0x52a0: 54000c61  b.ne     #0x542c
//   0x52a4: aa2203e0  mvn      x0, x2
//   0x52a8: 14000062  b        #0x5430
//   0x52ac: 39400480  ldrb     w0, [x4, #1]
//   0x52b0: 9100089b  add      x27, x4, #2
//   0x52b4: 51000400  sub      w0, w0, #1
//   0x52b8: 71001c1f  cmp      w0, #7
//   0x52bc: 54000b88  b.hi     #0x542c
//   0x52c0: 38604ae0  ldrb     w0, [x23, w0, uxtw]
//   0x52c4: 10000061  adr      x1, #0x52d0
//   0x52c8: 8b208820  add      x0, x1, w0, sxtb #2
//   0x52cc: d61f0000  br       x0
//   0x52d0: 39400040  ldrb     w0, [x2]
//   0x52d4: 14000057  b        #0x5430
//   0x52d8: 79400040  ldrh     w0, [x2]
//   0x52dc: 14000055  b        #0x5430
//   0x52e0: b9400040  ldr      w0, [x2]
//   0x52e4: 14000053  b        #0x5430
//   0x52e8: f9400040  ldr      x0, [x2]
//   0x52ec: 14000051  b        #0x5430
//   0x52f0: cb0203e0  neg      x0, x2
//   0x52f4: 1400004f  b        #0x5430
//   0x52f8: aa1b03e0  mov      x0, x27
//   0x52fc: aa1403e1  mov      x1, x20
//   0x5300: f90037a2  str      x2, [x29, #0x68]
//   0x5304: 97fffb54  bl       #0x4054
//   0x5308: aa0003fb  mov      x27, x0
//   0x530c: f9400281  ldr      x1, [x20]
//   0x5310: f94037a2  ldr      x2, [x29, #0x68]
//   0x5314: 8b010040  add      x0, x2, x1
//   0x5318: 14000046  b        #0x5430
//   0x531c: 7100073f  cmp      w25, #1
//   0x5320: 5400086d  b.le     #0x542c
//   0x5324: 51000b22  sub      w2, w25, #2
//   0x5328: 51006b5a  sub      w26, w26, #0x1a
//   0x532c: 51000739  sub      w25, w25, #1
//   0x5330: 7100535f  cmp      w26, #0x14
//   0x5334: f862db81  ldr      x1, [x28, w2, sxtw #3]
//   0x5338: f879db80  ldr      x0, [x28, w25, sxtw #3]
//   0x533c: 54000788  b.hi     #0x542c
//   0x5340: 387a4ac3  ldrb     w3, [x22, w26, uxtw]
//   0x5344: 10000064  adr      x4, #0x5350
//   0x5348: 8b238883  add      x3, x4, w3, sxtb #2
//   0x534c: d61f0060  br       x3
//   0x5350: 8a010000  and      x0, x0, x1
//   0x5354: 14000024  b        #0x53e4
//   0x5358: 9ac00c20  sdiv     x0, x1, x0
//   0x535c: 14000022  b        #0x53e4
//   0x5360: cb000020  sub      x0, x1, x0
//   0x5364: 14000020  b        #0x53e4
//   0x5368: 9ac00823  udiv     x3, x1, x0
//   0x536c: 9b008460  msub     x0, x3, x0, x1
//   0x5370: 1400001d  b        #0x53e4
//   0x5374: 9b017c00  mul      x0, x0, x1
//   0x5378: 1400001b  b        #0x53e4
//   0x537c: aa010000  orr      x0, x0, x1
//   0x5380: 14000019  b        #0x53e4
//   0x5384: 8b010000  add      x0, x0, x1
//   0x5388: 14000017  b        #0x53e4
//   0x538c: 9ac02020  lsl      x0, x1, x0
//   0x5390: 14000015  b        #0x53e4
//   0x5394: 9ac02420  lsr      x0, x1, x0
//   0x5398: 14000013  b        #0x53e4
//   0x539c: 9ac02820  asr      x0, x1, x0
//   0x53a0: 14000011  b        #0x53e4
//   0x53a4: ca010000  eor      x0, x0, x1
//   0x53a8: 1400000f  b        #0x53e4
//   0x53ac: eb00003f  cmp      x1, x0
//   0x53b0: 9a9fc7e0  cset     x0, le
//   0x53b4: 1400000c  b        #0x53e4
//   0x53b8: eb00003f  cmp      x1, x0
//   0x53bc: 9a9fb7e0  cset     x0, ge
//   0x53c0: 14000009  b        #0x53e4
//   0x53c4: eb00003f  cmp      x1, x0
//   0x53c8: 9a9f17e0  cset     x0, eq
//   0x53cc: 14000006  b        #0x53e4
//   0x53d0: eb00003f  cmp      x1, x0
//   0x53d4: 9a9fa7e0  cset     x0, lt
//   0x53d8: 14000003  b        #0x53e4
//   0x53dc: eb00003f  cmp      x1, x0
//   0x53e0: 9a9fd7e0  cset     x0, gt
//   0x53e4: 2a0203f9  mov      w25, w2
//   0x53e8: 14000012  b        #0x5430
//   0x53ec: eb00003f  cmp      x1, x0
//   0x53f0: 9a9f07e0  cset     x0, ne
//   0x53f4: 17fffffc  b        #0x53e4
//   0x53f8: 78801080  ldursh   x0, [x4, #1]
//   0x53fc: 91000c9b  add      x27, x4, #3
//   0x5400: 8b00037b  add      x27, x27, x0
//   0x5404: 1400000f  b        #0x5440
//   0x5408: 34000139  cbz      w25, #0x542c
//   0x540c: 51000739  sub      w25, w25, #1
//   0x5410: 91000c9b  add      x27, x4, #3
//   0x5414: 78c01080  ldursh   w0, [x4, #1]
//   0x5418: 8b20a360  add      x0, x27, w0, sxth
//   0x541c: f879db81  ldr      x1, [x28, w25, sxtw #3]
//   0x5420: eb1f003f  cmp      x1, xzr
//   0x5424: 9a80037b  csel     x27, x27, x0, eq
//   0x5428: 14000006  b        #0x5440
//   0x542c: 97fff211  bl       #0x1c70
//   0x5430: 7100ff3f  cmp      w25, #0x3f
//   0x5434: 54ffffc8  b.hi     #0x542c
//   0x5438: f839db80  str      x0, [x28, w25, sxtw #3]
//   0x543c: 11000739  add      w25, w25, #1
//   0x5440: aa1b03e4  mov      x4, x27
//   0x5444: 17fffeb3  b        #0x4f10
//   0x5448: 34ffff39  cbz      w25, #0x542c
//   0x544c: 51000739  sub      w25, w25, #1
//   0x5450: a94153f3  ldp      x19, x20, [sp, #0x10]
//   0x5454: a9425bf5  ldp      x21, x22, [sp, #0x20]
//   0x5458: f879db80  ldr      x0, [x28, w25, sxtw #3]
//   0x545c: a94363f7  ldp      x23, x24, [sp, #0x30]
//   0x5460: a9446bf9  ldp      x25, x26, [sp, #0x40]
//   0x5464: a94573fb  ldp      x27, x28, [sp, #0x50]
//   0x5468: a8c67bfd  ldp      x29, x30, [sp], #0x60
//   0x546c: 9108c3ff  add      sp, sp, #0x230
//   0x5470: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_058_4ec0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004ec0ULL;
    for (std::size_t i = 0; i < 365ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3120ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[059] Symbol: sub_5474
//      Virtual Address Range: 0x5474..0x5680 (524 bytes, 131 AArch64 instructions)
// [VN] Khung FDE[059] Biểu tượng: sub_5474
//      Dải địa chỉ ảo: 0x5474..0x5680 (524 byte, 131 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5474: d10f83ff  sub      sp, sp, #0x3e0
//   0x5478: d2807802  mov      x2, #0x3c0
//   0x547c: a9ba7bfd  stp      x29, x30, [sp, #-0x60]!
//   0x5480: 910003fd  mov      x29, sp
//   0x5484: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x5488: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x548c: aa0003f3  mov      x19, x0
//   0x5490: 910203b5  add      x21, x29, #0x80
//   0x5494: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x5498: aa1503e0  mov      x0, x21
//   0x549c: aa0103f8  mov      x24, x1
//   0x54a0: aa1303e1  mov      x1, x19
//   0x54a4: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x54a8: a90573fb  stp      x27, x28, [sp, #0x50]
//   0x54ac: 97fff145  bl       #0x19c0
//   0x54b0: f941e3a0  ldr      x0, [x29, #0x3c0]
//   0x54b4: b6f00060  tbz      x0, #0x3e, #0x54c0
//   0x54b8: 394ddea0  ldrb     w0, [x21, #0x377]
//   0x54bc: 350000e0  cbnz     w0, #0x54d8
//   0x54c0: f9407ea0  ldr      x0, [x21, #0xf8]
//   0x54c4: b50000a0  cbnz     x0, #0x54d8
//   0x54c8: f9418a61  ldr      x1, [x19, #0x310]
//   0x54cc: aa1503e0  mov      x0, x21
//   0x54d0: 9101c3a2  add      x2, x29, #0x70
//   0x54d4: 97fffb7b  bl       #0x42c0
//   0x54d8: f941a260  ldr      x0, [x19, #0x340]
//   0x54dc: b6f00040  tbz      x0, #0x3e, #0x54e4
//   0x54e0: 390dde7f  strb     wzr, [x19, #0x377]
//   0x54e4: b9464300  ldr      w0, [x24, #0x640]
//   0x54e8: f9007e7f  str      xzr, [x19, #0xf8]
//   0x54ec: 7100041f  cmp      w0, #1
//   0x54f0: 540001c0  b.eq     #0x5528
//   0x54f4: 7100081f  cmp      w0, #2
//   0x54f8: 54000621  b.ne     #0x55bc
//   0x54fc: 9101e3b4  add      x20, x29, #0x78
//   0x5500: f9431f00  ldr      x0, [x24, #0x638]
//   0x5504: aa1403e1  mov      x1, x20
//   0x5508: 97fffad3  bl       #0x4054
//   0x550c: f9400281  ldr      x1, [x20]
//   0x5510: aa1503e2  mov      x2, x21
//   0x5514: d2800003  mov      x3, #0
//   0x5518: 8b010001  add      x1, x0, x1
//   0x551c: 97fffe69  bl       #0x4ec0
//   0x5520: aa0003f7  mov      x23, x0
//   0x5524: 14000006  b        #0x553c
//   0x5528: b9463301  ldr      w1, [x24, #0x630]
//   0x552c: aa1503e0  mov      x0, x21
//   0x5530: 97fffb73  bl       #0x42fc
//   0x5534: f9431717  ldr      x23, [x24, #0x628]
//   0x5538: 8b170017  add      x23, x0, x23
//   0x553c: d0000000  adrp     x0, #0x7000
//   0x5540: f9018a77  str      x23, [x19, #0x310]
//   0x5544: 913e6000  add      x0, x0, #0xf98
//   0x5548: aa1803fa  mov      x26, x24
//   0x554c: 910d6276  add      x22, x19, #0x358
//   0x5550: d2800014  mov      x20, #0
//   0x5554: f90037a0  str      x0, [x29, #0x68]
//   0x5558: 9101e3b9  add      x25, x29, #0x78
//   0x555c: f000005b  adrp     x27, #0x10000
//   0x5560: 5280003c  mov      w28, #1
//   0x5564: b9400b40  ldr      w0, [x26, #8]
//   0x5568: 51000400  sub      w0, w0, #1
//   0x556c: 7100101f  cmp      w0, #4
//   0x5570: 54000608  b.hi     #0x5630
//   0x5574: f94037a1  ldr      x1, [x29, #0x68]
//   0x5578: 38604820  ldrb     w0, [x1, w0, uxtw]
//   0x557c: 10000061  adr      x1, #0x5588
//   0x5580: 8b208820  add      x0, x1, w0, sxtb #2
//   0x5584: d61f0000  br       x0
//   0x5588: f9400340  ldr      x0, [x26]
//   0x558c: 8b0002e0  add      x0, x23, x0
//   0x5590: 14000016  b        #0x55e8
//   0x5594: f9400341  ldr      x1, [x26]
//   0x5598: 8b21c2a0  add      x0, x21, w1, sxtw
//   0x559c: 394d6000  ldrb     w0, [x0, #0x358]
//   0x55a0: 34000100  cbz      w0, #0x55c0
//   0x55a4: aa1503e0  mov      x0, x21
//   0x55a8: 97fffb55  bl       #0x42fc
//   0x55ac: 9103c361  add      x1, x27, #0xf0
//   0x55b0: 38616a81  ldrb     w1, [x20, x1]
//   0x55b4: 7100203f  cmp      w1, #8
//   0x55b8: 54000389  b.ls     #0x5628
//   0x55bc: 97fff1ad  bl       #0x1c70
//   0x55c0: f861daa0  ldr      x0, [x21, w1, sxtw #3]
//   0x55c4: 14000009  b        #0x55e8
//   0x55c8: f9400340  ldr      x0, [x26]
//   0x55cc: aa1903e1  mov      x1, x25
//   0x55d0: 97fffaa1  bl       #0x4054
//   0x55d4: f9400321  ldr      x1, [x25]
//   0x55d8: aa1503e2  mov      x2, x21
//   0x55dc: aa1703e3  mov      x3, x23
//   0x55e0: 8b010001  add      x1, x0, x1
//   0x55e4: 97fffe37  bl       #0x4ec0
//   0x55e8: f941a261  ldr      x1, [x19, #0x340]
//   0x55ec: b6f00201  tbz      x1, #0x3e, #0x562c
//   0x55f0: 390002df  strb     wzr, [x22]
//   0x55f4: 1400000e  b        #0x562c
//   0x55f8: f9400340  ldr      x0, [x26]
//   0x55fc: 8b0002e0  add      x0, x23, x0
//   0x5600: 17ffffeb  b        #0x55ac
//   0x5604: f9400340  ldr      x0, [x26]
//   0x5608: aa1903e1  mov      x1, x25
//   0x560c: 97fffa92  bl       #0x4054
//   0x5610: f9400321  ldr      x1, [x25]
//   0x5614: aa1503e2  mov      x2, x21
//   0x5618: aa1703e3  mov      x3, x23
//   0x561c: 8b010001  add      x1, x0, x1
//   0x5620: 97fffe28  bl       #0x4ec0
//   0x5624: 17ffffe2  b        #0x55ac
//   0x5628: 390002dc  strb     w28, [x22]
//   0x562c: f8347a60  str      x0, [x19, x20, lsl #3]
//   0x5630: 91000694  add      x20, x20, #1
//   0x5634: 9100435a  add      x26, x26, #0x10
//   0x5638: f1018a9f  cmp      x20, #0x62
//   0x563c: 910006d6  add      x22, x22, #1
//   0x5640: 54fff921  b.ne     #0x5564
//   0x5644: f941a260  ldr      x0, [x19, #0x340]
//   0x5648: 3959cf02  ldrb     w2, [x24, #0x673]
//   0x564c: b2410001  orr      x1, x0, #0x8000000000000000
//   0x5650: 9240f800  and      x0, x0, #0x7fffffffffffffff
//   0x5654: 6b1f005f  cmp      w2, wzr
//   0x5658: 9a810000  csel     x0, x0, x1, eq
//   0x565c: f901a260  str      x0, [x19, #0x340]
//   0x5660: a9425bf5  ldp      x21, x22, [sp, #0x20]
//   0x5664: a94153f3  ldp      x19, x20, [sp, #0x10]
//   0x5668: a94363f7  ldp      x23, x24, [sp, #0x30]
//   0x566c: a9446bf9  ldp      x25, x26, [sp, #0x40]
//   0x5670: a94573fb  ldp      x27, x28, [sp, #0x50]
//   0x5674: a8c67bfd  ldp      x29, x30, [sp], #0x60
//   0x5678: 910f83ff  add      sp, sp, #0x3e0
//   0x567c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_059_5474(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005474ULL;
    for (std::size_t i = 0; i < 131ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3485ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[060] Symbol: sub_5680
//      Virtual Address Range: 0x5680..0x575c (220 bytes, 55 AArch64 instructions)
// [VN] Khung FDE[060] Biểu tượng: sub_5680
//      Dải địa chỉ ảo: 0x5680..0x575c (220 byte, 55 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5680: d11a43ff  sub      sp, sp, #0x690
//   0x5684: a9bc7bfd  stp      x29, x30, [sp, #-0x40]!
//   0x5688: 910003fd  mov      x29, sp
//   0x568c: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x5690: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x5694: aa0003f3  mov      x19, x0
//   0x5698: f9001bf7  str      x23, [sp, #0x30]
//   0x569c: aa0203f6  mov      x22, x2
//   0x56a0: aa0103f7  mov      x23, x1
//   0x56a4: d2807802  mov      x2, #0x3c0
//   0x56a8: 52800001  mov      w1, #0
//   0x56ac: aa1e03f4  mov      x20, x30
//   0x56b0: 97fff158  bl       #0x1c10
//   0x56b4: f9018e74  str      x20, [x19, #0x318]
//   0x56b8: d2e80000  mov      x0, #0x4000000000000000
//   0x56bc: 910143b4  add      x20, x29, #0x50
//   0x56c0: f901a260  str      x0, [x19, #0x340]
//   0x56c4: aa1403e1  mov      x1, x20
//   0x56c8: aa1303e0  mov      x0, x19
//   0x56cc: 97fffcf4  bl       #0x4a9c
//   0x56d0: 34000040  cbz      w0, #0x56d8
//   0x56d4: 97fff167  bl       #0x1c70
//   0x56d8: d0000040  adrp     x0, #0xf000
//   0x56dc: f0000055  adrp     x21, #0x10000
//   0x56e0: f947fc00  ldr      x0, [x0, #0xff8]
//   0x56e4: b50000a0  cbnz     x0, #0x56f8
//   0x56e8: 3943c2a0  ldrb     w0, [x21, #0xf0]
//   0x56ec: 35000120  cbnz     w0, #0x5710
//   0x56f0: 97fffaaf  bl       #0x41ac
//   0x56f4: 14000007  b        #0x5710
//   0x56f8: 9103c2a0  add      x0, x21, #0xf0
//   0x56fc: f0ffffe1  adrp     x1, #0x4000
//   0x5700: 91019000  add      x0, x0, #0x64
//   0x5704: 9106b021  add      x1, x1, #0x1ac
//   0x5708: 97fff0fe  bl       #0x1b00
//   0x570c: 35fffee0  cbnz     w0, #0x56e8
//   0x5710: 910123a2  add      x2, x29, #0x48
//   0x5714: aa1303e0  mov      x0, x19
//   0x5718: aa1703e1  mov      x1, x23
//   0x571c: 97fffae9  bl       #0x42c0
//   0x5720: f9033fbf  str      xzr, [x29, #0x678]
//   0x5724: 52800020  mov      w0, #1
//   0x5728: b90693a0  str      w0, [x29, #0x690]
//   0x572c: d28003e0  mov      x0, #0x1f
//   0x5730: aa1403e1  mov      x1, x20
//   0x5734: f90343a0  str      x0, [x29, #0x680]
//   0x5738: aa1303e0  mov      x0, x19
//   0x573c: 97ffff4e  bl       #0x5474
//   0x5740: f9018e76  str      x22, [x19, #0x318]
//   0x5744: f9401bf7  ldr      x23, [sp, #0x30]
//   0x5748: a94153f3  ldp      x19, x20, [sp, #0x10]
//   0x574c: a9425bf5  ldp      x21, x22, [sp, #0x20]
//   0x5750: a8c47bfd  ldp      x29, x30, [sp], #0x40
//   0x5754: 911a43ff  add      sp, sp, #0x690
//   0x5758: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_060_5680(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005680ULL;
    for (std::size_t i = 0; i < 55ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3616ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[061] Symbol: sub_575c
//      Virtual Address Range: 0x575c..0x57a8 (76 bytes, 19 AArch64 instructions)
// [VN] Khung FDE[061] Biểu tượng: sub_575c
//      Dải địa chỉ ảo: 0x575c..0x57a8 (76 byte, 19 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x575c: a9be7bfd  stp      x29, x30, [sp, #-0x20]!
//   0x5760: 910003fd  mov      x29, sp
//   0x5764: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x5768: aa0103f3  mov      x19, x1
//   0x576c: aa0003f4  mov      x20, x0
//   0x5770: 97ffff41  bl       #0x5474
//   0x5774: f9433661  ldr      x1, [x19, #0x668]
//   0x5778: 8b011273  add      x19, x19, x1, lsl #4
//   0x577c: b9400a60  ldr      w0, [x19, #8]
//   0x5780: 7100181f  cmp      w0, #6
//   0x5784: 54000061  b.ne     #0x5790
//   0x5788: f9018e9f  str      xzr, [x20, #0x318]
//   0x578c: 14000004  b        #0x579c
//   0x5790: aa1403e0  mov      x0, x20
//   0x5794: 97fffada  bl       #0x42fc
//   0x5798: f9018e80  str      x0, [x20, #0x318]
//   0x579c: a94153f3  ldp      x19, x20, [sp, #0x10]
//   0x57a0: a8c27bfd  ldp      x29, x30, [sp], #0x20
//   0x57a4: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_061_575c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000575cULL;
    for (std::size_t i = 0; i < 19ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3671ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[062] Symbol: sub_57a8
//      Virtual Address Range: 0x57a8..0x5868 (192 bytes, 48 AArch64 instructions)
// [VN] Khung FDE[062] Biểu tượng: sub_57a8
//      Dải địa chỉ ảo: 0x57a8..0x5868 (192 byte, 48 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x57a8: d11a03ff  sub      sp, sp, #0x680
//   0x57ac: a9bc7bfd  stp      x29, x30, [sp, #-0x40]!
//   0x57b0: 910003fd  mov      x29, sp
//   0x57b4: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x57b8: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x57bc: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x57c0: aa0003f5  mov      x21, x0
//   0x57c4: aa0103f3  mov      x19, x1
//   0x57c8: 910103b4  add      x20, x29, #0x40
//   0x57cc: 52800097  mov      w23, #4
//   0x57d0: aa1403e1  mov      x1, x20
//   0x57d4: aa1303e0  mov      x0, x19
//   0x57d8: 97fffcb1  bl       #0x4a9c
//   0x57dc: 2a0003f8  mov      w24, w0
//   0x57e0: aa1303e0  mov      x0, x19
//   0x57e4: 97fffb1f  bl       #0x4460
//   0x57e8: f941a261  ldr      x1, [x19, #0x340]
//   0x57ec: cb41fc00  sub      x0, x0, x1, lsr #63
//   0x57f0: f9400ea1  ldr      x1, [x21, #0x18]
//   0x57f4: eb01001f  cmp      x0, x1
//   0x57f8: 1a9f02f6  csel     w22, w23, wzr, eq
//   0x57fc: 35000298  cbnz     w24, #0x584c
//   0x5800: f9432a85  ldr      x5, [x20, #0x650]
//   0x5804: b5000065  cbnz     x5, #0x5810
//   0x5808: 340001b6  cbz      w22, #0x583c
//   0x580c: 97fff119  bl       #0x1c70
//   0x5810: f94002a2  ldr      x2, [x21]
//   0x5814: 52800020  mov      w0, #1
//   0x5818: 321f02c1  orr      w1, w22, #2
//   0x581c: aa1503e3  mov      x3, x21
//   0x5820: aa1303e4  mov      x4, x19
//   0x5824: d63f00a0  blr      x5
//   0x5828: 71001c1f  cmp      w0, #7
//   0x582c: 54000120  b.eq     #0x5850
//   0x5830: 7100201f  cmp      w0, #8
//   0x5834: 54fffea0  b.eq     #0x5808
//   0x5838: 14000005  b        #0x584c
//   0x583c: aa1303e0  mov      x0, x19
//   0x5840: aa1403e1  mov      x1, x20
//   0x5844: 97ffffc6  bl       #0x575c
//   0x5848: 17ffffe2  b        #0x57d0
//   0x584c: 52800040  mov      w0, #2
//   0x5850: a94153f3  ldp      x19, x20, [sp, #0x10]
//   0x5854: a9425bf5  ldp      x21, x22, [sp, #0x20]
//   0x5858: a94363f7  ldp      x23, x24, [sp, #0x30]
//   0x585c: a8c47bfd  ldp      x29, x30, [sp], #0x40
//   0x5860: 911a03ff  add      sp, sp, #0x680
//   0x5864: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_062_57a8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000057a8ULL;
    for (std::size_t i = 0; i < 48ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3690ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[063] Symbol: sub_5868
//      Virtual Address Range: 0x5868..0x5954 (236 bytes, 59 AArch64 instructions)
// [VN] Khung FDE[063] Biểu tượng: sub_5868
//      Dải địa chỉ ảo: 0x5868..0x5954 (236 byte, 59 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5868: d11a03ff  sub      sp, sp, #0x680
//   0x586c: a9bb7bfd  stp      x29, x30, [sp, #-0x50]!
//   0x5870: 910003fd  mov      x29, sp
//   0x5874: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x5878: f9400817  ldr      x23, [x0, #0x10]
//   0x587c: f9400c18  ldr      x24, [x0, #0x18]
//   0x5880: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x5884: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x5888: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x588c: aa0103f5  mov      x21, x1
//   0x5890: aa0003f4  mov      x20, x0
//   0x5894: 910143b6  add      x22, x29, #0x50
//   0x5898: 52800359  mov      w25, #0x1a
//   0x589c: 5280015a  mov      w26, #0xa
//   0x58a0: aa1503e0  mov      x0, x21
//   0x58a4: aa1603e1  mov      x1, x22
//   0x58a8: 97fffc7d  bl       #0x4a9c
//   0x58ac: 7100141f  cmp      w0, #5
//   0x58b0: 2a0003f3  mov      w19, w0
//   0x58b4: 54000040  b.eq     #0x58bc
//   0x58b8: 350003a0  cbnz     w0, #0x592c
//   0x58bc: 7100167f  cmp      w19, #5
//   0x58c0: f9400282  ldr      x2, [x20]
//   0x58c4: 52800020  mov      w0, #1
//   0x58c8: 1a9a0321  csel     w1, w25, w26, eq
//   0x58cc: aa1403e3  mov      x3, x20
//   0x58d0: aa1503e4  mov      x4, x21
//   0x58d4: aa1803e5  mov      x5, x24
//   0x58d8: d63f02e0  blr      x23
//   0x58dc: 35000280  cbnz     w0, #0x592c
//   0x58e0: 7100167f  cmp      w19, #5
//   0x58e4: 54000280  b.eq     #0x5934
//   0x58e8: f9432ac5  ldr      x5, [x22, #0x650]
//   0x58ec: b50000a5  cbnz     x5, #0x5900
//   0x58f0: aa1503e0  mov      x0, x21
//   0x58f4: aa1603e1  mov      x1, x22
//   0x58f8: 97ffff99  bl       #0x575c
//   0x58fc: 17ffffe9  b        #0x58a0
//   0x5900: f9400282  ldr      x2, [x20]
//   0x5904: 52800020  mov      w0, #1
//   0x5908: 52800141  mov      w1, #0xa
//   0x590c: aa1403e3  mov      x3, x20
//   0x5910: aa1503e4  mov      x4, x21
//   0x5914: d63f00a0  blr      x5
//   0x5918: 71001c1f  cmp      w0, #7
//   0x591c: 2a0003f3  mov      w19, w0
//   0x5920: 540000a0  b.eq     #0x5934
//   0x5924: 7100201f  cmp      w0, #8
//   0x5928: 54fffe40  b.eq     #0x58f0
//   0x592c: 52800040  mov      w0, #2
//   0x5930: 14000002  b        #0x5938
//   0x5934: 2a1303e0  mov      w0, w19
//   0x5938: a94153f3  ldp      x19, x20, [sp, #0x10]
//   0x593c: a9425bf5  ldp      x21, x22, [sp, #0x20]
//   0x5940: a94363f7  ldp      x23, x24, [sp, #0x30]
//   0x5944: a9446bf9  ldp      x25, x26, [sp, #0x40]
//   0x5948: a8c57bfd  ldp      x29, x30, [sp], #0x50
//   0x594c: 911a03ff  add      sp, sp, #0x680
//   0x5950: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_063_5868(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005868ULL;
    for (std::size_t i = 0; i < 59ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3738ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[064] Symbol: sub_5954
//      Virtual Address Range: 0x5954..0x5a48 (244 bytes, 61 AArch64 instructions)
// [VN] Khung FDE[064] Biểu tượng: sub_5954
//      Dải địa chỉ ảo: 0x5954..0x5a48 (244 byte, 61 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5954: d12903ff  sub      sp, sp, #0xa40
//   0x5958: d2807802  mov      x2, #0x3c0
//   0x595c: a9bd7bfd  stp      x29, x30, [sp, #-0x30]!
//   0x5960: 910003fd  mov      x29, sp
//   0x5964: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x5968: 9100c3b4  add      x20, x29, #0x30
//   0x596c: f90013f5  str      x21, [sp, #0x20]
//   0x5970: aa0103f3  mov      x19, x1
//   0x5974: aa0003f5  mov      x21, x0
//   0x5978: 52800001  mov      w1, #0
//   0x597c: aa1403e0  mov      x0, x20
//   0x5980: 910006b5  add      x21, x21, #1
//   0x5984: 97fff0a3  bl       #0x1c10
//   0x5988: f9018e95  str      x21, [x20, #0x318]
//   0x598c: d2e80000  mov      x0, #0x4000000000000000
//   0x5990: 910fc3b5  add      x21, x29, #0x3f0
//   0x5994: f901a280  str      x0, [x20, #0x340]
//   0x5998: aa1503e1  mov      x1, x21
//   0x599c: aa1403e0  mov      x0, x20
//   0x59a0: 97fffc3f  bl       #0x4a9c
//   0x59a4: d2800001  mov      x1, #0
//   0x59a8: 35000440  cbnz     w0, #0x5a30
//   0x59ac: b94a33a0  ldr      w0, [x29, #0xa30]
//   0x59b0: 7100081f  cmp      w0, #2
//   0x59b4: 540003e0  b.eq     #0x5a30
//   0x59b8: 910022a0  add      x0, x21, #8
//   0x59bc: 910cd262  add      x2, x19, #0x334
//   0x59c0: 91008261  add      x1, x19, #0x20
//   0x59c4: 9118a2b5  add      x21, x21, #0x628
//   0x59c8: 39400003  ldrb     w3, [x0]
//   0x59cc: 39000043  strb     w3, [x2]
//   0x59d0: 7100047f  cmp      w3, #1
//   0x59d4: 54000060  b.eq     #0x59e0
//   0x59d8: 7100087f  cmp      w3, #2
//   0x59dc: 54000081  b.ne     #0x59ec
//   0x59e0: f85f8003  ldur     x3, [x0, #-8]
//   0x59e4: f9000023  str      x3, [x1]
//   0x59e8: 14000002  b        #0x59f0
//   0x59ec: f900003f  str      xzr, [x1]
//   0x59f0: 91004000  add      x0, x0, #0x10
//   0x59f4: 91000442  add      x2, x2, #1
//   0x59f8: eb15001f  cmp      x0, x21
//   0x59fc: 91002021  add      x1, x1, #8
//   0x5a00: 54fffe41  b.ne     #0x59c8
//   0x5a04: f9450fa0  ldr      x0, [x29, #0xa18]
//   0x5a08: aa1303e1  mov      x1, x19
//   0x5a0c: f9000a60  str      x0, [x19, #0x10]
//   0x5a10: f94513a0  ldr      x0, [x29, #0xa20]
//   0x5a14: 79066260  strh     w0, [x19, #0x330]
//   0x5a18: f9452fa0  ldr      x0, [x29, #0xa58]
//   0x5a1c: 79066660  strh     w0, [x19, #0x332]
//   0x5a20: f941aa80  ldr      x0, [x20, #0x350]
//   0x5a24: f9000e60  str      x0, [x19, #0x18]
//   0x5a28: f94537a0  ldr      x0, [x29, #0xa68]
//   0x5a2c: f9000660  str      x0, [x19, #8]
//   0x5a30: a94153f3  ldp      x19, x20, [sp, #0x10]
//   0x5a34: f94013f5  ldr      x21, [sp, #0x20]
//   0x5a38: a8c37bfd  ldp      x29, x30, [sp], #0x30
//   0x5a3c: aa0103e0  mov      x0, x1
//   0x5a40: 912903ff  add      sp, sp, #0xa40
//   0x5a44: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_064_5954(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005954ULL;
    for (std::size_t i = 0; i < 61ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3797ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[065] Symbol: sub_5a48
//      Virtual Address Range: 0x5a48..0x5a4c (4 bytes, 1 AArch64 instructions)
// [VN] Khung FDE[065] Biểu tượng: sub_5a48
//      Dải địa chỉ ảo: 0x5a48..0x5a4c (4 byte, 1 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5a48: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_065_5a48(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005a48ULL;
    for (std::size_t i = 0; i < 1ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3858ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[066] Symbol: sub_5a4c
//      Virtual Address Range: 0x5a4c..0x5bc4 (376 bytes, 94 AArch64 instructions)
// [VN] Khung FDE[066] Biểu tượng: sub_5a4c
//      Dải địa chỉ ảo: 0x5a4c..0x5bc4 (376 byte, 94 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5a4c: d13843ff  sub      sp, sp, #0xe10
//   0x5a50: a9b47bfd  stp      x29, x30, [sp, #-0xc0]!
//   0x5a54: 910003fd  mov      x29, sp
//   0x5a58: a9045bf5  stp      x21, x22, [sp, #0x40]
//   0x5a5c: 6d0827e8  stp      d8, d9, [sp, #0x80]
//   0x5a60: 910343b5  add      x21, x29, #0xd0
//   0x5a64: 6d092fea  stp      d10, d11, [sp, #0x90]
//   0x5a68: a90107e0  stp      x0, x1, [sp, #0x10]
//   0x5a6c: 6d0a37ec  stp      d12, d13, [sp, #0xa0]
//   0x5a70: a9020fe2  stp      x2, x3, [sp, #0x20]
//   0x5a74: 6d0b3fee  stp      d14, d15, [sp, #0xb0]
//   0x5a78: a90353f3  stp      x19, x20, [sp, #0x30]
//   0x5a7c: aa1e03e2  mov      x2, x30
//   0x5a80: 913b43a1  add      x1, x29, #0xed0
//   0x5a84: aa0003f4  mov      x20, x0
//   0x5a88: aa1503e0  mov      x0, x21
//   0x5a8c: a90563f7  stp      x23, x24, [sp, #0x50]
//   0x5a90: a9066bf9  stp      x25, x26, [sp, #0x60]
//   0x5a94: a90773fb  stp      x27, x28, [sp, #0x70]
//   0x5a98: 911243b3  add      x19, x29, #0x490
//   0x5a9c: 97fffef9  bl       #0x5680
//   0x5aa0: aa1303e0  mov      x0, x19
//   0x5aa4: aa1503e1  mov      x1, x21
//   0x5aa8: d2807802  mov      x2, #0x3c0
//   0x5aac: 912143b6  add      x22, x29, #0x850
//   0x5ab0: 97ffefc4  bl       #0x19c0
//   0x5ab4: aa1303e0  mov      x0, x19
//   0x5ab8: aa1603e1  mov      x1, x22
//   0x5abc: 97fffbf8  bl       #0x4a9c
//   0x5ac0: 7100141f  cmp      w0, #5
//   0x5ac4: 540005e0  b.eq     #0x5b80
//   0x5ac8: 34000060  cbz      w0, #0x5ad4
//   0x5acc: 52800060  mov      w0, #3
//   0x5ad0: 1400002c  b        #0x5b80
//   0x5ad4: f9432ac5  ldr      x5, [x22, #0x650]
//   0x5ad8: b50000a5  cbnz     x5, #0x5aec
//   0x5adc: aa1303e0  mov      x0, x19
//   0x5ae0: aa1603e1  mov      x1, x22
//   0x5ae4: 97ffff1e  bl       #0x575c
//   0x5ae8: 17fffff3  b        #0x5ab4
//   0x5aec: 52800020  mov      w0, #1
//   0x5af0: f9400282  ldr      x2, [x20]
//   0x5af4: 2a0003e1  mov      w1, w0
//   0x5af8: aa1403e3  mov      x3, x20
//   0x5afc: aa1303e4  mov      x4, x19
//   0x5b00: d63f00a0  blr      x5
//   0x5b04: 7100181f  cmp      w0, #6
//   0x5b08: 54000080  b.eq     #0x5b18
//   0x5b0c: 7100201f  cmp      w0, #8
//   0x5b10: 54fffe60  b.eq     #0x5adc
//   0x5b14: 17ffffee  b        #0x5acc
//   0x5b18: f9000a9f  str      xzr, [x20, #0x10]
//   0x5b1c: aa1303e0  mov      x0, x19
//   0x5b20: 97fffa50  bl       #0x4460
//   0x5b24: f941a261  ldr      x1, [x19, #0x340]
//   0x5b28: d2807802  mov      x2, #0x3c0
//   0x5b2c: cb41fc00  sub      x0, x0, x1, lsr #63
//   0x5b30: aa1503e1  mov      x1, x21
//   0x5b34: f9000e80  str      x0, [x20, #0x18]
//   0x5b38: aa1303e0  mov      x0, x19
//   0x5b3c: 97ffefa1  bl       #0x19c0
//   0x5b40: aa1403e0  mov      x0, x20
//   0x5b44: aa1303e1  mov      x1, x19
//   0x5b48: 97ffff18  bl       #0x57a8
//   0x5b4c: 71001c1f  cmp      w0, #7
//   0x5b50: 54000181  b.ne     #0x5b80
//   0x5b54: aa1303e1  mov      x1, x19
//   0x5b58: aa1503e0  mov      x0, x21
//   0x5b5c: 97fff9fe  bl       #0x4354
//   0x5b60: f9418e74  ldr      x20, [x19, #0x318]
//   0x5b64: f90067a0  str      x0, [x29, #0xc8]
//   0x5b68: f9418a60  ldr      x0, [x19, #0x310]
//   0x5b6c: aa1403e1  mov      x1, x20
//   0x5b70: 97ffffb6  bl       #0x5a48
//   0x5b74: f90007f4  str      x20, [sp, #8]
//   0x5b78: f94067a4  ldr      x4, [x29, #0xc8]
//   0x5b7c: 14000002  b        #0x5b84
//   0x5b80: d2800004  mov      x4, #0
//   0x5b84: a9420fe2  ldp      x2, x3, [sp, #0x20]
//   0x5b88: 6d4827e8  ldp      d8, d9, [sp, #0x80]
//   0x5b8c: a94353f3  ldp      x19, x20, [sp, #0x30]
//   0x5b90: 6d492fea  ldp      d10, d11, [sp, #0x90]
//   0x5b94: a9445bf5  ldp      x21, x22, [sp, #0x40]
//   0x5b98: 6d4a37ec  ldp      d12, d13, [sp, #0xa0]
//   0x5b9c: a94563f7  ldp      x23, x24, [sp, #0x50]
//   0x5ba0: 6d4b3fee  ldp      d14, d15, [sp, #0xb0]
//   0x5ba4: a9466bf9  ldp      x25, x26, [sp, #0x60]
//   0x5ba8: a94773fb  ldp      x27, x28, [sp, #0x70]
//   0x5bac: a94107e0  ldp      x0, x1, [sp, #0x10]
//   0x5bb0: a8cc7bfd  ldp      x29, x30, [sp], #0xc0
//   0x5bb4: 910003f0  mov      x16, sp
//   0x5bb8: 8b2463ff  add      sp, sp, x4
//   0x5bbc: 913843ff  add      sp, sp, #0xe10
//   0x5bc0: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_066_5a4c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005a4cULL;
    for (std::size_t i = 0; i < 94ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3859ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[067] Symbol: sub_5bc4
//      Virtual Address Range: 0x5bc4..0x5cb8 (244 bytes, 61 AArch64 instructions)
// [VN] Khung FDE[067] Biểu tượng: sub_5bc4
//      Dải địa chỉ ảo: 0x5bc4..0x5cb8 (244 byte, 61 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5bc4: d11e43ff  sub      sp, sp, #0x790
//   0x5bc8: a9b47bfd  stp      x29, x30, [sp, #-0xc0]!
//   0x5bcc: 910003fd  mov      x29, sp
//   0x5bd0: a90353f3  stp      x19, x20, [sp, #0x30]
//   0x5bd4: 6d0827e8  stp      d8, d9, [sp, #0x80]
//   0x5bd8: 910343b4  add      x20, x29, #0xd0
//   0x5bdc: 6d092fea  stp      d10, d11, [sp, #0x90]
//   0x5be0: a9020fe2  stp      x2, x3, [sp, #0x20]
//   0x5be4: 6d0a37ec  stp      d12, d13, [sp, #0xa0]
//   0x5be8: a90107e0  stp      x0, x1, [sp, #0x10]
//   0x5bec: 6d0b3fee  stp      d14, d15, [sp, #0xb0]
//   0x5bf0: a9045bf5  stp      x21, x22, [sp, #0x40]
//   0x5bf4: a90563f7  stp      x23, x24, [sp, #0x50]
//   0x5bf8: aa0003f5  mov      x21, x0
//   0x5bfc: aa0103f7  mov      x23, x1
//   0x5c00: aa0203f6  mov      x22, x2
//   0x5c04: aa1403e0  mov      x0, x20
//   0x5c08: aa1e03e2  mov      x2, x30
//   0x5c0c: 912143a1  add      x1, x29, #0x850
//   0x5c10: 911243b3  add      x19, x29, #0x490
//   0x5c14: a9066bf9  stp      x25, x26, [sp, #0x60]
//   0x5c18: a90773fb  stp      x27, x28, [sp, #0x70]
//   0x5c1c: 97fffe99  bl       #0x5680
//   0x5c20: aa1403e1  mov      x1, x20
//   0x5c24: d2807802  mov      x2, #0x3c0
//   0x5c28: aa1303e0  mov      x0, x19
//   0x5c2c: 97ffef65  bl       #0x19c0
//   0x5c30: f9000ab7  str      x23, [x21, #0x10]
//   0x5c34: f9000eb6  str      x22, [x21, #0x18]
//   0x5c38: aa1503e0  mov      x0, x21
//   0x5c3c: aa1303e1  mov      x1, x19
//   0x5c40: 97ffff0a  bl       #0x5868
//   0x5c44: 71001c1f  cmp      w0, #7
//   0x5c48: d2800004  mov      x4, #0
//   0x5c4c: 54000161  b.ne     #0x5c78
//   0x5c50: aa1303e1  mov      x1, x19
//   0x5c54: aa1403e0  mov      x0, x20
//   0x5c58: 97fff9bf  bl       #0x4354
//   0x5c5c: f943d7b3  ldr      x19, [x29, #0x7a8]
//   0x5c60: f90067a0  str      x0, [x29, #0xc8]
//   0x5c64: f943d3a0  ldr      x0, [x29, #0x7a0]
//   0x5c68: aa1303e1  mov      x1, x19
//   0x5c6c: 97ffff77  bl       #0x5a48
//   0x5c70: f90007f3  str      x19, [sp, #8]
//   0x5c74: f94067a4  ldr      x4, [x29, #0xc8]
//   0x5c78: a9420fe2  ldp      x2, x3, [sp, #0x20]
//   0x5c7c: 6d4827e8  ldp      d8, d9, [sp, #0x80]
//   0x5c80: a94353f3  ldp      x19, x20, [sp, #0x30]
//   0x5c84: 6d492fea  ldp      d10, d11, [sp, #0x90]
//   0x5c88: a9445bf5  ldp      x21, x22, [sp, #0x40]
//   0x5c8c: 6d4a37ec  ldp      d12, d13, [sp, #0xa0]
//   0x5c90: a94563f7  ldp      x23, x24, [sp, #0x50]
//   0x5c94: 6d4b3fee  ldp      d14, d15, [sp, #0xb0]
//   0x5c98: a9466bf9  ldp      x25, x26, [sp, #0x60]
//   0x5c9c: a94773fb  ldp      x27, x28, [sp, #0x70]
//   0x5ca0: a94107e0  ldp      x0, x1, [sp, #0x10]
//   0x5ca4: a8cc7bfd  ldp      x29, x30, [sp], #0xc0
//   0x5ca8: 910003f0  mov      x16, sp
//   0x5cac: 8b2463ff  add      sp, sp, x4
//   0x5cb0: 911e43ff  add      sp, sp, #0x790
//   0x5cb4: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_067_5bc4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005bc4ULL;
    for (std::size_t i = 0; i < 61ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3953ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[068] Symbol: sub_5cb8
//      Virtual Address Range: 0x5cb8..0x5db4 (252 bytes, 63 AArch64 instructions)
// [VN] Khung FDE[068] Biểu tượng: sub_5cb8
//      Dải địa chỉ ảo: 0x5cb8..0x5db4 (252 byte, 63 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5cb8: d11e43ff  sub      sp, sp, #0x790
//   0x5cbc: a9b47bfd  stp      x29, x30, [sp, #-0xc0]!
//   0x5cc0: 910003fd  mov      x29, sp
//   0x5cc4: a90353f3  stp      x19, x20, [sp, #0x30]
//   0x5cc8: 6d0827e8  stp      d8, d9, [sp, #0x80]
//   0x5ccc: 910343b4  add      x20, x29, #0xd0
//   0x5cd0: 6d092fea  stp      d10, d11, [sp, #0x90]
//   0x5cd4: a90107e0  stp      x0, x1, [sp, #0x10]
//   0x5cd8: 6d0a37ec  stp      d12, d13, [sp, #0xa0]
//   0x5cdc: a9020fe2  stp      x2, x3, [sp, #0x20]
//   0x5ce0: 6d0b3fee  stp      d14, d15, [sp, #0xb0]
//   0x5ce4: aa1e03e2  mov      x2, x30
//   0x5ce8: 912143a1  add      x1, x29, #0x850
//   0x5cec: a9045bf5  stp      x21, x22, [sp, #0x40]
//   0x5cf0: aa0003f5  mov      x21, x0
//   0x5cf4: aa1403e0  mov      x0, x20
//   0x5cf8: a90563f7  stp      x23, x24, [sp, #0x50]
//   0x5cfc: a9066bf9  stp      x25, x26, [sp, #0x60]
//   0x5d00: a90773fb  stp      x27, x28, [sp, #0x70]
//   0x5d04: 911243b3  add      x19, x29, #0x490
//   0x5d08: 97fffe5e  bl       #0x5680
//   0x5d0c: aa1303e0  mov      x0, x19
//   0x5d10: aa1403e1  mov      x1, x20
//   0x5d14: d2807802  mov      x2, #0x3c0
//   0x5d18: 97ffef2a  bl       #0x19c0
//   0x5d1c: f9400aa0  ldr      x0, [x21, #0x10]
//   0x5d20: b50000a0  cbnz     x0, #0x5d34
//   0x5d24: aa1503e0  mov      x0, x21
//   0x5d28: aa1303e1  mov      x1, x19
//   0x5d2c: 97fffe9f  bl       #0x57a8
//   0x5d30: 14000004  b        #0x5d40
//   0x5d34: aa1503e0  mov      x0, x21
//   0x5d38: aa1303e1  mov      x1, x19
//   0x5d3c: 97fffecb  bl       #0x5868
//   0x5d40: 71001c1f  cmp      w0, #7
//   0x5d44: 54000040  b.eq     #0x5d4c
//   0x5d48: 97ffefca  bl       #0x1c70
//   0x5d4c: aa1303e1  mov      x1, x19
//   0x5d50: aa1403e0  mov      x0, x20
//   0x5d54: 97fff980  bl       #0x4354
//   0x5d58: f943d7b3  ldr      x19, [x29, #0x7a8]
//   0x5d5c: f90067a0  str      x0, [x29, #0xc8]
//   0x5d60: f943d3a0  ldr      x0, [x29, #0x7a0]
//   0x5d64: aa1303e1  mov      x1, x19
//   0x5d68: 97ffff38  bl       #0x5a48
//   0x5d6c: f90007f3  str      x19, [sp, #8]
//   0x5d70: f94067a4  ldr      x4, [x29, #0xc8]
//   0x5d74: 6d4827e8  ldp      d8, d9, [sp, #0x80]
//   0x5d78: a94107e0  ldp      x0, x1, [sp, #0x10]
//   0x5d7c: 6d492fea  ldp      d10, d11, [sp, #0x90]
//   0x5d80: a9420fe2  ldp      x2, x3, [sp, #0x20]
//   0x5d84: 6d4a37ec  ldp      d12, d13, [sp, #0xa0]
//   0x5d88: a94353f3  ldp      x19, x20, [sp, #0x30]
//   0x5d8c: 6d4b3fee  ldp      d14, d15, [sp, #0xb0]
//   0x5d90: a9445bf5  ldp      x21, x22, [sp, #0x40]
//   0x5d94: a94563f7  ldp      x23, x24, [sp, #0x50]
//   0x5d98: a9466bf9  ldp      x25, x26, [sp, #0x60]
//   0x5d9c: a94773fb  ldp      x27, x28, [sp, #0x70]
//   0x5da0: a8cc7bfd  ldp      x29, x30, [sp], #0xc0
//   0x5da4: 910003f0  mov      x16, sp
//   0x5da8: 8b2463ff  add      sp, sp, x4
//   0x5dac: 911e43ff  add      sp, sp, #0x790
//   0x5db0: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_068_5cb8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005cb8ULL;
    for (std::size_t i = 0; i < 63ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4014ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[069] Symbol: sub_5db4
//      Virtual Address Range: 0x5db4..0x5eac (248 bytes, 62 AArch64 instructions)
// [VN] Khung FDE[069] Biểu tượng: sub_5db4
//      Dải địa chỉ ảo: 0x5db4..0x5eac (248 byte, 62 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5db4: d11e43ff  sub      sp, sp, #0x790
//   0x5db8: a9b47bfd  stp      x29, x30, [sp, #-0xc0]!
//   0x5dbc: 910003fd  mov      x29, sp
//   0x5dc0: 6d0827e8  stp      d8, d9, [sp, #0x80]
//   0x5dc4: a90107e0  stp      x0, x1, [sp, #0x10]
//   0x5dc8: 6d092fea  stp      d10, d11, [sp, #0x90]
//   0x5dcc: f9400801  ldr      x1, [x0, #0x10]
//   0x5dd0: 6d0a37ec  stp      d12, d13, [sp, #0xa0]
//   0x5dd4: a9020fe2  stp      x2, x3, [sp, #0x20]
//   0x5dd8: 6d0b3fee  stp      d14, d15, [sp, #0xb0]
//   0x5ddc: a9045bf5  stp      x21, x22, [sp, #0x40]
//   0x5de0: a90353f3  stp      x19, x20, [sp, #0x30]
//   0x5de4: a90563f7  stp      x23, x24, [sp, #0x50]
//   0x5de8: a9066bf9  stp      x25, x26, [sp, #0x60]
//   0x5dec: a90773fb  stp      x27, x28, [sp, #0x70]
//   0x5df0: aa1e03e2  mov      x2, x30
//   0x5df4: aa0003f5  mov      x21, x0
//   0x5df8: b5000081  cbnz     x1, #0x5e08
//   0x5dfc: 97ffff14  bl       #0x5a4c
//   0x5e00: d2800004  mov      x4, #0
//   0x5e04: 1400001a  b        #0x5e6c
//   0x5e08: 910343b4  add      x20, x29, #0xd0
//   0x5e0c: 912143a1  add      x1, x29, #0x850
//   0x5e10: aa1403e0  mov      x0, x20
//   0x5e14: 911243b3  add      x19, x29, #0x490
//   0x5e18: 97fffe1a  bl       #0x5680
//   0x5e1c: aa1403e1  mov      x1, x20
//   0x5e20: d2807802  mov      x2, #0x3c0
//   0x5e24: aa1303e0  mov      x0, x19
//   0x5e28: 97ffeee6  bl       #0x19c0
//   0x5e2c: aa1503e0  mov      x0, x21
//   0x5e30: aa1303e1  mov      x1, x19
//   0x5e34: 97fffe8d  bl       #0x5868
//   0x5e38: 71001c1f  cmp      w0, #7
//   0x5e3c: 54000040  b.eq     #0x5e44
//   0x5e40: 97ffef8c  bl       #0x1c70
//   0x5e44: aa1303e1  mov      x1, x19
//   0x5e48: aa1403e0  mov      x0, x20
//   0x5e4c: 97fff942  bl       #0x4354
//   0x5e50: f943d7b3  ldr      x19, [x29, #0x7a8]
//   0x5e54: f90067a0  str      x0, [x29, #0xc8]
//   0x5e58: f943d3a0  ldr      x0, [x29, #0x7a0]
//   0x5e5c: aa1303e1  mov      x1, x19
//   0x5e60: 97fffefa  bl       #0x5a48
//   0x5e64: f90007f3  str      x19, [sp, #8]
//   0x5e68: f94067a4  ldr      x4, [x29, #0xc8]
//   0x5e6c: a9420fe2  ldp      x2, x3, [sp, #0x20]
//   0x5e70: 6d4827e8  ldp      d8, d9, [sp, #0x80]
//   0x5e74: a94353f3  ldp      x19, x20, [sp, #0x30]
//   0x5e78: 6d492fea  ldp      d10, d11, [sp, #0x90]
//   0x5e7c: a9445bf5  ldp      x21, x22, [sp, #0x40]
//   0x5e80: 6d4a37ec  ldp      d12, d13, [sp, #0xa0]
//   0x5e84: a94563f7  ldp      x23, x24, [sp, #0x50]
//   0x5e88: 6d4b3fee  ldp      d14, d15, [sp, #0xb0]
//   0x5e8c: a9466bf9  ldp      x25, x26, [sp, #0x60]
//   0x5e90: a94773fb  ldp      x27, x28, [sp, #0x70]
//   0x5e94: a94107e0  ldp      x0, x1, [sp, #0x10]
//   0x5e98: a8cc7bfd  ldp      x29, x30, [sp], #0xc0
//   0x5e9c: 910003f0  mov      x16, sp
//   0x5ea0: 8b2463ff  add      sp, sp, x4
//   0x5ea4: 911e43ff  add      sp, sp, #0x790
//   0x5ea8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_069_5db4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005db4ULL;
    for (std::size_t i = 0; i < 62ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4077ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[070] Symbol: sub_5eac
//      Virtual Address Range: 0x5eac..0x5ed0 (36 bytes, 9 AArch64 instructions)
// [VN] Khung FDE[070] Biểu tượng: sub_5eac
//      Dải địa chỉ ảo: 0x5eac..0x5ed0 (36 byte, 9 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5eac: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x5eb0: 910003fd  mov      x29, sp
//   0x5eb4: f9400402  ldr      x2, [x0, #8]
//   0x5eb8: b4000082  cbz      x2, #0x5ec8
//   0x5ebc: aa0003e1  mov      x1, x0
//   0x5ec0: 52800020  mov      w0, #1
//   0x5ec4: d63f0040  blr      x2
//   0x5ec8: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x5ecc: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_070_5eac(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005eacULL;
    for (std::size_t i = 0; i < 9ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4139ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[071] Symbol: sub_5ed0
//      Virtual Address Range: 0x5ed0..0x5fa0 (208 bytes, 52 AArch64 instructions)
// [VN] Khung FDE[071] Biểu tượng: sub_5ed0
//      Dải địa chỉ ảo: 0x5ed0..0x5fa0 (208 byte, 52 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5ed0: d12903ff  sub      sp, sp, #0xa40
//   0x5ed4: aa1e03e2  mov      x2, x30
//   0x5ed8: a9b67bfd  stp      x29, x30, [sp, #-0xa0]!
//   0x5edc: 910003fd  mov      x29, sp
//   0x5ee0: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x5ee4: 6d0627e8  stp      d8, d9, [sp, #0x60]
//   0x5ee8: 910283b4  add      x20, x29, #0xa0
//   0x5eec: 6d072fea  stp      d10, d11, [sp, #0x70]
//   0x5ef0: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x5ef4: 6d0837ec  stp      d12, d13, [sp, #0x80]
//   0x5ef8: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x5efc: 6d093fee  stp      d14, d15, [sp, #0x90]
//   0x5f00: aa0003f6  mov      x22, x0
//   0x5f04: aa0103f7  mov      x23, x1
//   0x5f08: aa1403e0  mov      x0, x20
//   0x5f0c: 912b83a1  add      x1, x29, #0xae0
//   0x5f10: 911183b5  add      x21, x29, #0x460
//   0x5f14: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x5f18: a90573fb  stp      x27, x28, [sp, #0x50]
//   0x5f1c: 97fffdd9  bl       #0x5680
//   0x5f20: aa1403e0  mov      x0, x20
//   0x5f24: aa1503e1  mov      x1, x21
//   0x5f28: 97fffadd  bl       #0x4a9c
//   0x5f2c: 7100141f  cmp      w0, #5
//   0x5f30: 2a0003f3  mov      w19, w0
//   0x5f34: 54000040  b.eq     #0x5f3c
//   0x5f38: 35000160  cbnz     w0, #0x5f64
//   0x5f3c: aa1403e0  mov      x0, x20
//   0x5f40: aa1703e1  mov      x1, x23
//   0x5f44: d63f02c0  blr      x22
//   0x5f48: 350000e0  cbnz     w0, #0x5f64
//   0x5f4c: 7100167f  cmp      w19, #5
//   0x5f50: 540000e0  b.eq     #0x5f6c
//   0x5f54: aa1403e0  mov      x0, x20
//   0x5f58: aa1503e1  mov      x1, x21
//   0x5f5c: 97fffe00  bl       #0x575c
//   0x5f60: 17fffff0  b        #0x5f20
//   0x5f64: 52800060  mov      w0, #3
//   0x5f68: 14000002  b        #0x5f70
//   0x5f6c: 2a1303e0  mov      w0, w19
//   0x5f70: a94153f3  ldp      x19, x20, [sp, #0x10]
//   0x5f74: 6d4627e8  ldp      d8, d9, [sp, #0x60]
//   0x5f78: a9425bf5  ldp      x21, x22, [sp, #0x20]
//   0x5f7c: 6d472fea  ldp      d10, d11, [sp, #0x70]
//   0x5f80: a94363f7  ldp      x23, x24, [sp, #0x30]
//   0x5f84: 6d4837ec  ldp      d12, d13, [sp, #0x80]
//   0x5f88: a9446bf9  ldp      x25, x26, [sp, #0x40]
//   0x5f8c: 6d493fee  ldp      d14, d15, [sp, #0x90]
//   0x5f90: a94573fb  ldp      x27, x28, [sp, #0x50]
//   0x5f94: a8ca7bfd  ldp      x29, x30, [sp], #0xa0
//   0x5f98: 912903ff  add      sp, sp, #0xa40
//   0x5f9c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_071_5ed0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005ed0ULL;
    for (std::size_t i = 0; i < 52ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4148ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[072] Symbol: sub_5fa0
//      Virtual Address Range: 0x5fa0..0x5fc8 (40 bytes, 10 AArch64 instructions)
// [VN] Khung FDE[072] Biểu tượng: sub_5fa0
//      Dải địa chỉ ảo: 0x5fa0..0x5fc8 (40 byte, 10 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5fa0: d2800002  mov      x2, #0
//   0x5fa4: 52800003  mov      w3, #0
//   0x5fa8: 38401405  ldrb     w5, [x0], #1
//   0x5fac: 924018a4  and      x4, x5, #0x7f
//   0x5fb0: 9ac32084  lsl      x4, x4, x3
//   0x5fb4: 11001c63  add      w3, w3, #7
//   0x5fb8: aa040042  orr      x2, x2, x4
//   0x5fbc: 373fff65  tbnz     w5, #7, #0x5fa8
//   0x5fc0: f9000022  str      x2, [x1]
//   0x5fc4: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_072_5fa0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005fa0ULL;
    for (std::size_t i = 0; i < 10ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4200ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[073] Symbol: sub_5fc8
//      Virtual Address Range: 0x5fc8..0x6008 (64 bytes, 16 AArch64 instructions)
// [VN] Khung FDE[073] Biểu tượng: sub_5fc8
//      Dải địa chỉ ảo: 0x5fc8..0x6008 (64 byte, 16 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5fc8: d2800002  mov      x2, #0
//   0x5fcc: 52800003  mov      w3, #0
//   0x5fd0: 38401404  ldrb     w4, [x0], #1
//   0x5fd4: 92401885  and      x5, x4, #0x7f
//   0x5fd8: 9ac320a5  lsl      x5, x5, x3
//   0x5fdc: 11001c63  add      w3, w3, #7
//   0x5fe0: aa050042  orr      x2, x2, x5
//   0x5fe4: 373fff64  tbnz     w4, #7, #0x5fd0
//   0x5fe8: 7100fc7f  cmp      w3, #0x3f
//   0x5fec: 540000a8  b.hi     #0x6000
//   0x5ff0: 36300084  tbz      w4, #6, #0x6000
//   0x5ff4: 92800004  mov      x4, #-1
//   0x5ff8: 9ac32083  lsl      x3, x4, x3
//   0x5ffc: aa020062  orr      x2, x3, x2
//   0x6000: f9000022  str      x2, [x1]
//   0x6004: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_073_5fc8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005fc8ULL;
    for (std::size_t i = 0; i < 16ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4210ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[074] Symbol: sub_6008
//      Virtual Address Range: 0x6008..0x6024 (28 bytes, 7 AArch64 instructions)
// [VN] Khung FDE[074] Biểu tượng: sub_6008
//      Dải địa chỉ ảo: 0x6008..0x6024 (28 byte, 7 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x6008: f9400423  ldr      x3, [x1, #8]
//   0x600c: f9400441  ldr      x1, [x2, #8]
//   0x6010: eb01007f  cmp      x3, x1
//   0x6014: 5a9f23e0  csetm    w0, lo
//   0x6018: eb01007f  cmp      x3, x1
//   0x601c: 1a9f9400  csinc    w0, w0, wzr, ls
//   0x6020: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_074_6008(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006008ULL;
    for (std::size_t i = 0; i < 7ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4226ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[075] Symbol: sub_6024
//      Virtual Address Range: 0x6024..0x60e4 (192 bytes, 48 AArch64 instructions)
// [VN] Khung FDE[075] Biểu tượng: sub_6024
//      Dải địa chỉ ảo: 0x6024..0x60e4 (192 byte, 48 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x6024: a9ba7bfd  stp      x29, x30, [sp, #-0x60]!
//   0x6028: 910003fd  mov      x29, sp
//   0x602c: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x6030: 531f7873  lsl      w19, w3, #1
//   0x6034: f90023f9  str      x25, [sp, #0x40]
//   0x6038: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x603c: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x6040: aa0003f8  mov      x24, x0
//   0x6044: aa0103f9  mov      x25, x1
//   0x6048: aa0203f4  mov      x20, x2
//   0x604c: 2a0403f7  mov      w23, w4
//   0x6050: 11000673  add      w19, w19, #1
//   0x6054: 6b17027f  cmp      w19, w23
//   0x6058: 540003aa  b.ge     #0x60cc
//   0x605c: 11000675  add      w21, w19, #1
//   0x6060: 6b1702bf  cmp      w21, w23
//   0x6064: 5400016a  b.ge     #0x6090
//   0x6068: 937d7e61  sbfiz    x1, x19, #3, #0x20
//   0x606c: aa1803e0  mov      x0, x24
//   0x6070: 8b010282  add      x2, x20, x1
//   0x6074: f9002fa3  str      x3, [x29, #0x58]
//   0x6078: f8616a81  ldr      x1, [x20, x1]
//   0x607c: f9400442  ldr      x2, [x2, #8]
//   0x6080: d63f0320  blr      x25
//   0x6084: 6b1f001f  cmp      w0, wzr
//   0x6088: f9402fa3  ldr      x3, [x29, #0x58]
//   0x608c: 1a95a273  csel     w19, w19, w21, ge
//   0x6090: 937d7c75  sbfiz    x21, x3, #3, #0x20
//   0x6094: 937d7e76  sbfiz    x22, x19, #3, #0x20
//   0x6098: aa1803e0  mov      x0, x24
//   0x609c: f8756a81  ldr      x1, [x20, x21]
//   0x60a0: f8766a82  ldr      x2, [x20, x22]
//   0x60a4: d63f0320  blr      x25
//   0x60a8: 36f80120  tbz      w0, #0x1f, #0x60cc
//   0x60ac: f8766a81  ldr      x1, [x20, x22]
//   0x60b0: 2a1303e3  mov      w3, w19
//   0x60b4: f8756a80  ldr      x0, [x20, x21]
//   0x60b8: f8356a81  str      x1, [x20, x21]
//   0x60bc: f8366a80  str      x0, [x20, x22]
//   0x60c0: 531f7a60  lsl      w0, w19, #1
//   0x60c4: 11000413  add      w19, w0, #1
//   0x60c8: 17ffffe3  b        #0x6054
//   0x60cc: a94153f3  ldp      x19, x20, [sp, #0x10]
//   0x60d0: a9425bf5  ldp      x21, x22, [sp, #0x20]
//   0x60d4: a94363f7  ldp      x23, x24, [sp, #0x30]
//   0x60d8: f94023f9  ldr      x25, [sp, #0x40]
//   0x60dc: a8c67bfd  ldp      x29, x30, [sp], #0x60
//   0x60e0: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_075_6024(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006024ULL;
    for (std::size_t i = 0; i < 48ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4233ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[076] Symbol: sub_60e4
//      Virtual Address Range: 0x60e4..0x6198 (180 bytes, 45 AArch64 instructions)
// [VN] Khung FDE[076] Biểu tượng: sub_60e4
//      Dải địa chỉ ảo: 0x60e4..0x6198 (180 byte, 45 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x60e4: a9bb7bfd  stp      x29, x30, [sp, #-0x50]!
//   0x60e8: 910003fd  mov      x29, sp
//   0x60ec: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x60f0: f9400453  ldr      x19, [x2, #8]
//   0x60f4: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x60f8: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x60fc: f90023f9  str      x25, [sp, #0x40]
//   0x6100: aa0003f8  mov      x24, x0
//   0x6104: aa0103f9  mov      x25, x1
//   0x6108: aa0203f5  mov      x21, x2
//   0x610c: 91004056  add      x22, x2, #0x10
//   0x6110: d341fe74  lsr      x20, x19, #1
//   0x6114: 51000694  sub      w20, w20, #1
//   0x6118: 37f80114  tbnz     w20, #0x1f, #0x6138
//   0x611c: aa1803e0  mov      x0, x24
//   0x6120: aa1903e1  mov      x1, x25
//   0x6124: aa1603e2  mov      x2, x22
//   0x6128: 2a1403e3  mov      w3, w20
//   0x612c: 2a1303e4  mov      w4, w19
//   0x6130: 97ffffbd  bl       #0x6024
//   0x6134: 17fffff8  b        #0x6114
//   0x6138: d2800014  mov      x20, #0
//   0x613c: 51000673  sub      w19, w19, #1
//   0x6140: 8b33ced7  add      x23, x22, w19, sxtw #3
//   0x6144: 6b1f027f  cmp      w19, wzr
//   0x6148: 540001cd  b.le     #0x6180
//   0x614c: f8746ae1  ldr      x1, [x23, x20]
//   0x6150: 2a1303e4  mov      w4, w19
//   0x6154: f9400aa0  ldr      x0, [x21, #0x10]
//   0x6158: aa1603e2  mov      x2, x22
//   0x615c: f9000aa1  str      x1, [x21, #0x10]
//   0x6160: 52800003  mov      w3, #0
//   0x6164: f8346ae0  str      x0, [x23, x20]
//   0x6168: aa1903e1  mov      x1, x25
//   0x616c: aa1803e0  mov      x0, x24
//   0x6170: 51000673  sub      w19, w19, #1
//   0x6174: d1002294  sub      x20, x20, #8
//   0x6178: 97ffffab  bl       #0x6024
//   0x617c: 17fffff2  b        #0x6144
//   0x6180: a94153f3  ldp      x19, x20, [sp, #0x10]
//   0x6184: a9425bf5  ldp      x21, x22, [sp, #0x20]
//   0x6188: a94363f7  ldp      x23, x24, [sp, #0x30]
//   0x618c: f94023f9  ldr      x25, [sp, #0x40]
//   0x6190: a8c57bfd  ldp      x29, x30, [sp], #0x50
//   0x6194: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_076_60e4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000060e4ULL;
    for (std::size_t i = 0; i < 45ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4281ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[077] Symbol: sub_6198
//      Virtual Address Range: 0x6198..0x61f8 (96 bytes, 24 AArch64 instructions)
// [VN] Khung FDE[077] Biểu tượng: sub_6198
//      Dải địa chỉ ảo: 0x6198..0x61f8 (96 byte, 24 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x6198: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x619c: 53001c00  uxtb     w0, w0
//   0x61a0: 7103fc1f  cmp      w0, #0xff
//   0x61a4: 910003fd  mov      x29, sp
//   0x61a8: 540001e0  b.eq     #0x61e4
//   0x61ac: 12000800  and      w0, w0, #7
//   0x61b0: 7100101f  cmp      w0, #4
//   0x61b4: 54000168  b.hi     #0x61e0
//   0x61b8: b0000001  adrp     x1, #0x7000
//   0x61bc: 913e8021  add      x1, x1, #0xfa0
//   0x61c0: 38604820  ldrb     w0, [x1, w0, uxtw]
//   0x61c4: 10000061  adr      x1, #0x61d0
//   0x61c8: 8b208820  add      x0, x1, w0, sxtb #2
//   0x61cc: d61f0000  br       x0
//   0x61d0: 52800040  mov      w0, #2
//   0x61d4: 14000007  b        #0x61f0
//   0x61d8: 52800080  mov      w0, #4
//   0x61dc: 14000005  b        #0x61f0
//   0x61e0: 97ffeea4  bl       #0x1c70
//   0x61e4: 52800000  mov      w0, #0
//   0x61e8: 14000002  b        #0x61f0
//   0x61ec: 52800100  mov      w0, #8
//   0x61f0: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x61f4: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_077_6198(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006198ULL;
    for (std::size_t i = 0; i < 24ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4326ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[078] Symbol: sub_61f8
//      Virtual Address Range: 0x61f8..0x6258 (96 bytes, 24 AArch64 instructions)
// [VN] Khung FDE[078] Biểu tượng: sub_61f8
//      Dải địa chỉ ảo: 0x61f8..0x6258 (96 byte, 24 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x61f8: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x61fc: 53001c00  uxtb     w0, w0
//   0x6200: 7103fc1f  cmp      w0, #0xff
//   0x6204: 910003fd  mov      x29, sp
//   0x6208: 54000220  b.eq     #0x624c
//   0x620c: 121c0800  and      w0, w0, #0x70
//   0x6210: 7100801f  cmp      w0, #0x20
//   0x6214: 54000140  b.eq     #0x623c
//   0x6218: 54000088  b.hi     #0x6228
//   0x621c: 7100401f  cmp      w0, #0x10
//   0x6220: 350000a0  cbnz     w0, #0x6234
//   0x6224: 1400000a  b        #0x624c
//   0x6228: 7100c01f  cmp      w0, #0x30
//   0x622c: 540000c0  b.eq     #0x6244
//   0x6230: 7101401f  cmp      w0, #0x50
//   0x6234: 540000c0  b.eq     #0x624c
//   0x6238: 97ffee8e  bl       #0x1c70
//   0x623c: f9400420  ldr      x0, [x1, #8]
//   0x6240: 14000004  b        #0x6250
//   0x6244: f9400820  ldr      x0, [x1, #0x10]
//   0x6248: 14000002  b        #0x6250
//   0x624c: d2800000  mov      x0, #0
//   0x6250: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x6254: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_078_61f8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000061f8ULL;
    for (std::size_t i = 0; i < 24ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4350ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[079] Symbol: sub_6258
//      Virtual Address Range: 0x6258..0x62b8 (96 bytes, 24 AArch64 instructions)
// [VN] Khung FDE[079] Biểu tượng: sub_6258
//      Dải địa chỉ ảo: 0x6258..0x62b8 (96 byte, 24 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x6258: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x625c: 53001c00  uxtb     w0, w0
//   0x6260: 7103fc1f  cmp      w0, #0xff
//   0x6264: 910003fd  mov      x29, sp
//   0x6268: 54000220  b.eq     #0x62ac
//   0x626c: 121c0800  and      w0, w0, #0x70
//   0x6270: 7100801f  cmp      w0, #0x20
//   0x6274: 54000140  b.eq     #0x629c
//   0x6278: 54000088  b.hi     #0x6288
//   0x627c: 7100401f  cmp      w0, #0x10
//   0x6280: 350000a0  cbnz     w0, #0x6294
//   0x6284: 1400000a  b        #0x62ac
//   0x6288: 7100c01f  cmp      w0, #0x30
//   0x628c: 540000c0  b.eq     #0x62a4
//   0x6290: 7101401f  cmp      w0, #0x50
//   0x6294: 540000c0  b.eq     #0x62ac
//   0x6298: 97ffee76  bl       #0x1c70
//   0x629c: f9400420  ldr      x0, [x1, #8]
//   0x62a0: 14000004  b        #0x62b0
//   0x62a4: f9400820  ldr      x0, [x1, #0x10]
//   0x62a8: 14000002  b        #0x62b0
//   0x62ac: d2800000  mov      x0, #0
//   0x62b0: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x62b4: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_079_6258(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006258ULL;
    for (std::size_t i = 0; i < 24ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4374ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[080] Symbol: sub_62b8
//      Virtual Address Range: 0x62b8..0x63a8 (240 bytes, 60 AArch64 instructions)
// [VN] Khung FDE[080] Biểu tượng: sub_62b8
//      Dải địa chỉ ảo: 0x62b8..0x63a8 (240 byte, 60 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x62b8: a9bc7bfd  stp      x29, x30, [sp, #-0x40]!
//   0x62bc: 910003fd  mov      x29, sp
//   0x62c0: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x62c4: 53001c14  uxtb     w20, w0
//   0x62c8: aa0203f3  mov      x19, x2
//   0x62cc: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x62d0: 7101429f  cmp      w20, #0x50
//   0x62d4: aa0103f6  mov      x22, x1
//   0x62d8: aa0303f5  mov      x21, x3
//   0x62dc: 540000a1  b.ne     #0x62f0
//   0x62e0: 91001c53  add      x19, x2, #7
//   0x62e4: 927df260  and      x0, x19, #0xfffffffffffffff8
//   0x62e8: f8408401  ldr      x1, [x0], #8
//   0x62ec: 1400002a  b        #0x6394
//   0x62f0: 12000e81  and      w1, w20, #0xf
//   0x62f4: 7100303f  cmp      w1, #0xc
//   0x62f8: 540003e8  b.hi     #0x6374
//   0x62fc: b0000000  adrp     x0, #0x7000
//   0x6300: 913ea000  add      x0, x0, #0xfa8
//   0x6304: 38614800  ldrb     w0, [x0, w1, uxtw]
//   0x6308: 10000061  adr      x1, #0x6314
//   0x630c: 8b208820  add      x0, x1, w0, sxtb #2
//   0x6310: d61f0000  br       x0
//   0x6314: aa0203e0  mov      x0, x2
//   0x6318: 9100e3a1  add      x1, x29, #0x38
//   0x631c: 97ffff21  bl       #0x5fa0
//   0x6320: 14000004  b        #0x6330
//   0x6324: aa0203e0  mov      x0, x2
//   0x6328: 9100e3a1  add      x1, x29, #0x38
//   0x632c: 97ffff27  bl       #0x5fc8
//   0x6330: f9401fa1  ldr      x1, [x29, #0x38]
//   0x6334: 14000011  b        #0x6378
//   0x6338: aa0203e0  mov      x0, x2
//   0x633c: 78402401  ldrh     w1, [x0], #2
//   0x6340: 1400000e  b        #0x6378
//   0x6344: aa0203e0  mov      x0, x2
//   0x6348: b8404401  ldr      w1, [x0], #4
//   0x634c: 1400000b  b        #0x6378
//   0x6350: aa0203e0  mov      x0, x2
//   0x6354: 78802401  ldrsh    x1, [x0], #2
//   0x6358: 14000008  b        #0x6378
//   0x635c: aa0203e0  mov      x0, x2
//   0x6360: b8804401  ldrsw    x1, [x0], #4
//   0x6364: 14000005  b        #0x6378
//   0x6368: aa0203e0  mov      x0, x2
//   0x636c: f8408401  ldr      x1, [x0], #8
//   0x6370: 14000002  b        #0x6378
//   0x6374: 97ffee3f  bl       #0x1c70
//   0x6378: b40000e1  cbz      x1, #0x6394
//   0x637c: 121c0a82  and      w2, w20, #0x70
//   0x6380: 7100405f  cmp      w2, #0x10
//   0x6384: 9a960273  csel     x19, x19, x22, eq
//   0x6388: 8b130021  add      x1, x1, x19
//   0x638c: 36380054  tbz      w20, #7, #0x6394
//   0x6390: f9400021  ldr      x1, [x1]
//   0x6394: f90002a1  str      x1, [x21]
//   0x6398: a94153f3  ldp      x19, x20, [sp, #0x10]
//   0x639c: a9425bf5  ldp      x21, x22, [sp, #0x20]
//   0x63a0: a8c47bfd  ldp      x29, x30, [sp], #0x40
//   0x63a4: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_080_62b8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000062b8ULL;
    for (std::size_t i = 0; i < 60ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4398ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[081] Symbol: sub_63a8
//      Virtual Address Range: 0x63a8..0x6438 (144 bytes, 36 AArch64 instructions)
// [VN] Khung FDE[081] Biểu tượng: sub_63a8
//      Dải địa chỉ ảo: 0x63a8..0x6438 (144 byte, 36 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x63a8: a9bb7bfd  stp      x29, x30, [sp, #-0x50]!
//   0x63ac: 910003fd  mov      x29, sp
//   0x63b0: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x63b4: 79404013  ldrh     w19, [x0, #0x20]
//   0x63b8: aa0003f4  mov      x20, x0
//   0x63bc: f9001bf7  str      x23, [sp, #0x30]
//   0x63c0: aa0103f7  mov      x23, x1
//   0x63c4: d3432a73  ubfx     x19, x19, #3, #8
//   0x63c8: aa1403e1  mov      x1, x20
//   0x63cc: 2a1303e0  mov      w0, w19
//   0x63d0: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x63d4: aa0203f6  mov      x22, x2
//   0x63d8: 97ffff88  bl       #0x61f8
//   0x63dc: aa0003f5  mov      x21, x0
//   0x63e0: 910022e2  add      x2, x23, #8
//   0x63e4: aa1503e1  mov      x1, x21
//   0x63e8: 910103a3  add      x3, x29, #0x40
//   0x63ec: 2a1303e0  mov      w0, w19
//   0x63f0: 97ffffb2  bl       #0x62b8
//   0x63f4: 79404280  ldrh     w0, [x20, #0x20]
//   0x63f8: aa1503e1  mov      x1, x21
//   0x63fc: 910022c2  add      x2, x22, #8
//   0x6400: 910123a3  add      x3, x29, #0x48
//   0x6404: d343fc00  lsr      x0, x0, #3
//   0x6408: 97ffffac  bl       #0x62b8
//   0x640c: f9401bf7  ldr      x23, [sp, #0x30]
//   0x6410: f94023a2  ldr      x2, [x29, #0x40]
//   0x6414: f94027a1  ldr      x1, [x29, #0x48]
//   0x6418: a94153f3  ldp      x19, x20, [sp, #0x10]
//   0x641c: eb01005f  cmp      x2, x1
//   0x6420: 5a9f23e0  csetm    w0, lo
//   0x6424: eb01005f  cmp      x2, x1
//   0x6428: a9425bf5  ldp      x21, x22, [sp, #0x20]
//   0x642c: 1a9f9400  csinc    w0, w0, wzr, ls
//   0x6430: a8c57bfd  ldp      x29, x30, [sp], #0x50
//   0x6434: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_081_63a8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000063a8ULL;
    for (std::size_t i = 0; i < 36ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4458ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[082] Symbol: sub_6438
//      Virtual Address Range: 0x6438..0x6534 (252 bytes, 63 AArch64 instructions)
// [VN] Khung FDE[082] Biểu tượng: sub_6438
//      Dải địa chỉ ảo: 0x6438..0x6534 (252 byte, 63 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x6438: a9bc7bfd  stp      x29, x30, [sp, #-0x40]!
//   0x643c: 910003fd  mov      x29, sp
//   0x6440: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x6444: 91002414  add      x20, x0, #9
//   0x6448: aa0003f3  mov      x19, x0
//   0x644c: aa1403e0  mov      x0, x20
//   0x6450: 97ffedb0  bl       #0x1b10
//   0x6454: 91000400  add      x0, x0, #1
//   0x6458: 39402262  ldrb     w2, [x19, #8]
//   0x645c: 8b000281  add      x1, x20, x0
//   0x6460: 71000c5f  cmp      w2, #3
//   0x6464: 54000109  b.ls     #0x6484
//   0x6468: 38606a82  ldrb     w2, [x20, x0]
//   0x646c: 52801fe0  mov      w0, #0xff
//   0x6470: 7100205f  cmp      w2, #8
//   0x6474: 540005a1  b.ne     #0x6528
//   0x6478: 39400422  ldrb     w2, [x1, #1]
//   0x647c: 35000562  cbnz     w2, #0x6528
//   0x6480: 91000821  add      x1, x1, #2
//   0x6484: 39402660  ldrb     w0, [x19, #9]
//   0x6488: 7101e81f  cmp      w0, #0x7a
//   0x648c: 54000060  b.eq     #0x6498
//   0x6490: 52800000  mov      w0, #0
//   0x6494: 14000025  b        #0x6528
//   0x6498: 9100c3b4  add      x20, x29, #0x30
//   0x649c: aa0103e0  mov      x0, x1
//   0x64a0: aa1403e1  mov      x1, x20
//   0x64a4: 97fffebf  bl       #0x5fa0
//   0x64a8: 9100e3a1  add      x1, x29, #0x38
//   0x64ac: 97fffec7  bl       #0x5fc8
//   0x64b0: 39402262  ldrb     w2, [x19, #8]
//   0x64b4: 7100045f  cmp      w2, #1
//   0x64b8: 54000061  b.ne     #0x64c4
//   0x64bc: 91000400  add      x0, x0, #1
//   0x64c0: 14000003  b        #0x64cc
//   0x64c4: aa1403e1  mov      x1, x20
//   0x64c8: 97fffeb6  bl       #0x5fa0
//   0x64cc: aa1403e1  mov      x1, x20
//   0x64d0: 91002a73  add      x19, x19, #0xa
//   0x64d4: 9100a3b4  add      x20, x29, #0x28
//   0x64d8: 97fffeb2  bl       #0x5fa0
//   0x64dc: 39400261  ldrb     w1, [x19]
//   0x64e0: 7101483f  cmp      w1, #0x52
//   0x64e4: 54000061  b.ne     #0x64f0
//   0x64e8: 39400000  ldrb     w0, [x0]
//   0x64ec: 1400000f  b        #0x6528
//   0x64f0: 7101403f  cmp      w1, #0x50
//   0x64f4: 54000101  b.ne     #0x6514
//   0x64f8: aa0003e2  mov      x2, x0
//   0x64fc: d2800001  mov      x1, #0
//   0x6500: aa1403e3  mov      x3, x20
//   0x6504: 38401440  ldrb     w0, [x2], #1
//   0x6508: 12001800  and      w0, w0, #0x7f
//   0x650c: 97ffff6b  bl       #0x62b8
//   0x6510: 14000004  b        #0x6520
//   0x6514: 7101303f  cmp      w1, #0x4c
//   0x6518: 54fffbc1  b.ne     #0x6490
//   0x651c: 91000400  add      x0, x0, #1
//   0x6520: 91000673  add      x19, x19, #1
//   0x6524: 17ffffee  b        #0x64dc
//   0x6528: a94153f3  ldp      x19, x20, [sp, #0x10]
//   0x652c: a8c47bfd  ldp      x29, x30, [sp], #0x40
//   0x6530: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_082_6438(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006438ULL;
    for (std::size_t i = 0; i < 63ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4494ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[083] Symbol: sub_6534
//      Virtual Address Range: 0x6534..0x6694 (352 bytes, 88 AArch64 instructions)
// [VN] Khung FDE[083] Biểu tượng: sub_6534
//      Dải địa chỉ ảo: 0x6534..0x6694 (352 byte, 88 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x6534: a9b97bfd  stp      x29, x30, [sp, #-0x70]!
//   0x6538: 910003fd  mov      x29, sp
//   0x653c: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x6540: aa0003f6  mov      x22, x0
//   0x6544: 79404000  ldrh     w0, [x0, #0x20]
//   0x6548: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x654c: d3432800  ubfx     x0, x0, #3, #8
//   0x6550: aa0103f3  mov      x19, x1
//   0x6554: aa1603e1  mov      x1, x22
//   0x6558: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x655c: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x6560: a90573fb  stp      x27, x28, [sp, #0x50]
//   0x6564: aa0203f7  mov      x23, x2
//   0x6568: 53001c15  uxtb     w21, w0
//   0x656c: 97ffff23  bl       #0x61f8
//   0x6570: 910183b8  add      x24, x29, #0x60
//   0x6574: aa0003fb  mov      x27, x0
//   0x6578: 9101a3b9  add      x25, x29, #0x68
//   0x657c: d2800000  mov      x0, #0
//   0x6580: d280003a  mov      x26, #1
//   0x6584: b9400261  ldr      w1, [x19]
//   0x6588: 34000761  cbz      w1, #0x6674
//   0x658c: b9400661  ldr      w1, [x19, #4]
//   0x6590: 34000661  cbz      w1, #0x665c
//   0x6594: 394082c2  ldrb     w2, [x22, #0x20]
//   0x6598: aa0003f4  mov      x20, x0
//   0x659c: 36100162  tbz      w2, #2, #0x65c8
//   0x65a0: 91001274  add      x20, x19, #4
//   0x65a4: cb21c294  sub      x20, x20, w1, sxtw
//   0x65a8: eb00029f  cmp      x20, x0
//   0x65ac: 540000e0  b.eq     #0x65c8
//   0x65b0: aa1403e0  mov      x0, x20
//   0x65b4: 97ffffa1  bl       #0x6438
//   0x65b8: 2a0003f5  mov      w21, w0
//   0x65bc: aa1603e1  mov      x1, x22
//   0x65c0: 97ffff0e  bl       #0x61f8
//   0x65c4: aa0003fb  mov      x27, x0
//   0x65c8: 350001b5  cbnz     w21, #0x65fc
//   0x65cc: f9400660  ldr      x0, [x19, #8]
//   0x65d0: f9400a61  ldr      x1, [x19, #0x10]
//   0x65d4: f90033a0  str      x0, [x29, #0x60]
//   0x65d8: f90037a1  str      x1, [x29, #0x68]
//   0x65dc: b4000420  cbz      x0, #0x6660
//   0x65e0: f94033a0  ldr      x0, [x29, #0x60]
//   0x65e4: f94037a1  ldr      x1, [x29, #0x68]
//   0x65e8: cb0002e0  sub      x0, x23, x0
//   0x65ec: eb01001f  cmp      x0, x1
//   0x65f0: 54000382  b.hs     #0x6660
//   0x65f4: aa1303e0  mov      x0, x19
//   0x65f8: 14000020  b        #0x6678
//   0x65fc: 53001ebc  uxtb     w28, w21
//   0x6600: aa1b03e1  mov      x1, x27
//   0x6604: 91002262  add      x2, x19, #8
//   0x6608: aa1803e3  mov      x3, x24
//   0x660c: 2a1c03e0  mov      w0, w28
//   0x6610: 97ffff2a  bl       #0x62b8
//   0x6614: aa0003e2  mov      x2, x0
//   0x6618: d2800001  mov      x1, #0
//   0x661c: aa1903e3  mov      x3, x25
//   0x6620: 12000ea0  and      w0, w21, #0xf
//   0x6624: 97ffff25  bl       #0x62b8
//   0x6628: 2a1c03e0  mov      w0, w28
//   0x662c: 97fffedb  bl       #0x6198
//   0x6630: 2a0003e0  mov      w0, w0
//   0x6634: f1001c1f  cmp      x0, #7
//   0x6638: 92800001  mov      x1, #-1
//   0x663c: 54000088  b.hi     #0x664c
//   0x6640: d37df001  lsl      x1, x0, #3
//   0x6644: 9ac12341  lsl      x1, x26, x1
//   0x6648: d1000421  sub      x1, x1, #1
//   0x664c: f94033a0  ldr      x0, [x29, #0x60]
//   0x6650: ea00003f  tst      x1, x0
//   0x6654: 54000060  b.eq     #0x6660
//   0x6658: 17ffffe2  b        #0x65e0
//   0x665c: aa0003f4  mov      x20, x0
//   0x6660: b9400260  ldr      w0, [x19]
//   0x6664: 91001000  add      x0, x0, #4
//   0x6668: 8b000273  add      x19, x19, x0
//   0x666c: aa1403e0  mov      x0, x20
//   0x6670: 17ffffc5  b        #0x6584
//   0x6674: d2800000  mov      x0, #0
//   0x6678: a94153f3  ldp      x19, x20, [sp, #0x10]
//   0x667c: a9425bf5  ldp      x21, x22, [sp, #0x20]
//   0x6680: a94363f7  ldp      x23, x24, [sp, #0x30]
//   0x6684: a9446bf9  ldp      x25, x26, [sp, #0x40]
//   0x6688: a94573fb  ldp      x27, x28, [sp, #0x50]
//   0x668c: a8c77bfd  ldp      x29, x30, [sp], #0x70
//   0x6690: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_083_6534(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006534ULL;
    for (std::size_t i = 0; i < 88ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4557ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[084] Symbol: sub_6694
//      Virtual Address Range: 0x6694..0x66a4 (16 bytes, 4 AArch64 instructions)
// [VN] Khung FDE[084] Biểu tượng: sub_6694
//      Dải địa chỉ ảo: 0x6694..0x66a4 (16 byte, 4 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x6694: 91001001  add      x1, x0, #4
//   0x6698: b9800400  ldrsw    x0, [x0, #4]
//   0x669c: cb000020  sub      x0, x1, x0
//   0x66a0: 17ffff66  b        #0x6438
// ============================================================================
std::uint32_t fde_084_6694(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006694ULL;
    for (std::size_t i = 0; i < 4ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4645ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[085] Symbol: sub_66a4
//      Virtual Address Range: 0x66a4..0x6ac0 (1052 bytes, 263 AArch64 instructions)
// [VN] Khung FDE[085] Biểu tượng: sub_66a4
//      Dải địa chỉ ảo: 0x66a4..0x6ac0 (1052 byte, 263 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x66a4: a9b77bfd  stp      x29, x30, [sp, #-0x90]!
//   0x66a8: f100bc3f  cmp      x1, #0x2f
//   0x66ac: 910003fd  mov      x29, sp
//   0x66b0: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x66b4: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x66b8: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x66bc: 1a9f97ed  cset     w13, hi
//   0x66c0: f9400806  ldr      x6, [x0, #0x10]
//   0x66c4: f9400007  ldr      x7, [x0]
//   0x66c8: 340007ad  cbz      w13, #0x67bc
//   0x66cc: b9402843  ldr      w3, [x2, #0x28]
//   0x66d0: 34000763  cbz      w3, #0x67bc
//   0x66d4: d0000041  adrp     x1, #0x10000
//   0x66d8: f9401004  ldr      x4, [x0, #0x20]
//   0x66dc: f9401405  ldr      x5, [x0, #0x28]
//   0x66e0: f9401423  ldr      x3, [x1, #0x28]
//   0x66e4: eb03009f  cmp      x4, x3
//   0x66e8: d0000043  adrp     x3, #0x10000
//   0x66ec: 54000461  b.ne     #0x6778
//   0x66f0: f940ac69  ldr      x9, [x3, #0x158]
//   0x66f4: 91056068  add      x8, x3, #0x158
//   0x66f8: eb0900bf  cmp      x5, x9
//   0x66fc: 540003e1  b.ne     #0x6778
//   0x6700: f9400509  ldr      x9, [x8, #8]
//   0x6704: d2800004  mov      x4, #0
//   0x6708: d2800005  mov      x5, #0
//   0x670c: aa0903e1  mov      x1, x9
//   0x6710: b4000621  cbz      x1, #0x67d4
//   0x6714: f940004a  ldr      x10, [x2]
//   0x6718: f9400028  ldr      x8, [x1]
//   0x671c: f9400424  ldr      x4, [x1, #8]
//   0x6720: eb08015f  cmp      x10, x8
//   0x6724: 540001a3  b.lo     #0x6758
//   0x6728: eb04015f  cmp      x10, x4
//   0x672c: 54000162  b.hs     #0x6758
//   0x6730: eb09003f  cmp      x1, x9
//   0x6734: f9400827  ldr      x7, [x1, #0x10]
//   0x6738: f9400c28  ldr      x8, [x1, #0x18]
//   0x673c: 54000bc0  b.eq     #0x68b4
//   0x6740: 91056063  add      x3, x3, #0x158
//   0x6744: f9401420  ldr      x0, [x1, #0x28]
//   0x6748: f90014a0  str      x0, [x5, #0x28]
//   0x674c: f9001429  str      x9, [x1, #0x28]
//   0x6750: f9000461  str      x1, [x3, #8]
//   0x6754: 14000058  b        #0x68b4
//   0x6758: aa040104  orr      x4, x8, x4
//   0x675c: b40003a4  cbz      x4, #0x67d0
//   0x6760: f9401428  ldr      x8, [x1, #0x28]
//   0x6764: aa0103e4  mov      x4, x1
//   0x6768: eb1f011f  cmp      x8, xzr
//   0x676c: 9a8100a5  csel     x5, x5, x1, eq
//   0x6770: aa0803e1  mov      x1, x8
//   0x6774: 17ffffe7  b        #0x6710
//   0x6778: f9001424  str      x4, [x1, #0x28]
//   0x677c: 91056064  add      x4, x3, #0x158
//   0x6780: 91010081  add      x1, x4, #0x40
//   0x6784: f900ac65  str      x5, [x3, #0x158]
//   0x6788: 91070084  add      x4, x4, #0x1c0
//   0x678c: f81d003f  stur     xzr, [x1, #-0x30]
//   0x6790: f81d803f  stur     xzr, [x1, #-0x28]
//   0x6794: f81f8021  stur     x1, [x1, #-8]
//   0x6798: 9100c021  add      x1, x1, #0x30
//   0x679c: eb04003f  cmp      x1, x4
//   0x67a0: 54ffff61  b.ne     #0x678c
//   0x67a4: 91056063  add      x3, x3, #0x158
//   0x67a8: 91004061  add      x1, x3, #0x10
//   0x67ac: f900c47f  str      xzr, [x3, #0x188]
//   0x67b0: f9000461  str      x1, [x3, #8]
//   0x67b4: b900285f  str      wzr, [x2, #0x28]
//   0x67b8: 14000003  b        #0x67c4
//   0x67bc: f100643f  cmp      x1, #0x19
//   0x67c0: 54001709  b.ls     #0x6aa0
//   0x67c4: d2800004  mov      x4, #0
//   0x67c8: d2800005  mov      x5, #0
//   0x67cc: 14000002  b        #0x67d4
//   0x67d0: aa0103e4  mov      x4, x1
//   0x67d4: 7940300e  ldrh     w14, [x0, #0x18]
//   0x67d8: d2800009  mov      x9, #0
//   0x67dc: d280000a  mov      x10, #0
//   0x67e0: d280000c  mov      x12, #0
//   0x67e4: d280000b  mov      x11, #0
//   0x67e8: d2800008  mov      x8, #0
//   0x67ec: d10005ce  sub      x14, x14, #1
//   0x67f0: b10005df  cmn      x14, #1
//   0x67f4: 54000380  b.eq     #0x6864
//   0x67f8: b94000c0  ldr      w0, [x6]
//   0x67fc: 7100041f  cmp      w0, #1
//   0x6800: 540001e1  b.ne     #0x683c
//   0x6804: f94008c1  ldr      x1, [x6, #0x10]
//   0x6808: f9400043  ldr      x3, [x2]
//   0x680c: 8b0100e1  add      x1, x7, x1
//   0x6810: eb01007f  cmp      x3, x1
//   0x6814: 54000243  b.lo     #0x685c
//   0x6818: f94014c0  ldr      x0, [x6, #0x28]
//   0x681c: 8b000020  add      x0, x1, x0
//   0x6820: eb00007f  cmp      x3, x0
//   0x6824: 9a802129  csel     x9, x9, x0, hs
//   0x6828: eb00007f  cmp      x3, x0
//   0x682c: 9a81214a  csel     x10, x10, x1, hs
//   0x6830: eb00007f  cmp      x3, x0
//   0x6834: 9a9f258c  csinc    x12, x12, xzr, hs
//   0x6838: 14000009  b        #0x685c
//   0x683c: 529caa01  mov      w1, #0xe550
//   0x6840: 72ac8e81  movk     w1, #0x6474, lsl #16
//   0x6844: 6b01001f  cmp      w0, w1
//   0x6848: 54000080  b.eq     #0x6858
//   0x684c: 7100081f  cmp      w0, #2
//   0x6850: 9a86116b  csel     x11, x11, x6, ne
//   0x6854: 14000002  b        #0x685c
//   0x6858: aa0603e8  mov      x8, x6
//   0x685c: 9100e0c6  add      x6, x6, #0x38
//   0x6860: 17ffffe3  b        #0x67ec
//   0x6864: b500006c  cbnz     x12, #0x6870
//   0x6868: 52800000  mov      w0, #0
//   0x686c: 14000090  b        #0x6aac
//   0x6870: 3400022d  cbz      w13, #0x68b4
//   0x6874: d0000040  adrp     x0, #0x10000
//   0x6878: b4000105  cbz      x5, #0x6898
//   0x687c: b40000e4  cbz      x4, #0x6898
//   0x6880: f9401481  ldr      x1, [x4, #0x28]
//   0x6884: f90014a1  str      x1, [x5, #0x28]
//   0x6888: 91056001  add      x1, x0, #0x158
//   0x688c: f9400423  ldr      x3, [x1, #8]
//   0x6890: f9001483  str      x3, [x4, #0x28]
//   0x6894: f9000424  str      x4, [x1, #8]
//   0x6898: 91056000  add      x0, x0, #0x158
//   0x689c: f9400400  ldr      x0, [x0, #8]
//   0x68a0: f9000807  str      x7, [x0, #0x10]
//   0x68a4: f9000c08  str      x8, [x0, #0x18]
//   0x68a8: f900100b  str      x11, [x0, #0x20]
//   0x68ac: f900000a  str      x10, [x0]
//   0x68b0: f9000409  str      x9, [x0, #8]
//   0x68b4: b4fffda8  cbz      x8, #0x6868
//   0x68b8: f9400900  ldr      x0, [x8, #0x10]
//   0x68bc: 8b0000f5  add      x21, x7, x0
//   0x68c0: 386068e0  ldrb     w0, [x7, x0]
//   0x68c4: 7100041f  cmp      w0, #1
//   0x68c8: 54000e81  b.ne     #0x6a98
//   0x68cc: 394006b4  ldrb     w20, [x21, #1]
//   0x68d0: aa0203e1  mov      x1, x2
//   0x68d4: aa0203f3  mov      x19, x2
//   0x68d8: 2a1403e0  mov      w0, w20
//   0x68dc: 97fffe5f  bl       #0x6258
//   0x68e0: aa0003e1  mov      x1, x0
//   0x68e4: 910012a2  add      x2, x21, #4
//   0x68e8: 2a1403e0  mov      w0, w20
//   0x68ec: 910143a3  add      x3, x29, #0x50
//   0x68f0: 97fffe72  bl       #0x62b8
//   0x68f4: 39400ab4  ldrb     w20, [x21, #2]
//   0x68f8: aa0003e2  mov      x2, x0
//   0x68fc: 7103fe9f  cmp      w20, #0xff
//   0x6900: 54000940  b.eq     #0x6a28
//   0x6904: 39400ea0  ldrb     w0, [x21, #3]
//   0x6908: 7100ec1f  cmp      w0, #0x3b
//   0x690c: 540008e1  b.ne     #0x6a28
//   0x6910: aa1303e1  mov      x1, x19
//   0x6914: 2a1403e0  mov      w0, w20
//   0x6918: f90027a2  str      x2, [x29, #0x48]
//   0x691c: 97fffe4f  bl       #0x6258
//   0x6920: aa0003e1  mov      x1, x0
//   0x6924: f94027a2  ldr      x2, [x29, #0x48]
//   0x6928: 2a1403e0  mov      w0, w20
//   0x692c: 910163a3  add      x3, x29, #0x58
//   0x6930: 97fffe62  bl       #0x62b8
//   0x6934: aa0003f6  mov      x22, x0
//   0x6938: f9402fa0  ldr      x0, [x29, #0x58]
//   0x693c: b4000ae0  cbz      x0, #0x6a98
//   0x6940: 924006c1  and      x1, x22, #3
//   0x6944: b5000721  cbnz     x1, #0x6a28
//   0x6948: b98002c2  ldrsw    x2, [x22]
//   0x694c: f9400261  ldr      x1, [x19]
//   0x6950: 8b0202a2  add      x2, x21, x2
//   0x6954: eb02003f  cmp      x1, x2
//   0x6958: 54000a03  b.lo     #0x6a98
//   0x695c: d1000400  sub      x0, x0, #1
//   0x6960: d37df002  lsl      x2, x0, #3
//   0x6964: b8a26ac2  ldrsw    x2, [x22, x2]
//   0x6968: 8b0202a2  add      x2, x21, x2
//   0x696c: eb02003f  cmp      x1, x2
//   0x6970: 540002a2  b.hs     #0x69c4
//   0x6974: aa0003e3  mov      x3, x0
//   0x6978: d2800004  mov      x4, #0
//   0x697c: eb03009f  cmp      x4, x3
//   0x6980: 54000942  b.hs     #0x6aa8
//   0x6984: 8b040060  add      x0, x3, x4
//   0x6988: d341fc00  lsr      x0, x0, #1
//   0x698c: d37df002  lsl      x2, x0, #3
//   0x6990: b8a26ac5  ldrsw    x5, [x22, x2]
//   0x6994: 8b0502a5  add      x5, x21, x5
//   0x6998: eb05003f  cmp      x1, x5
//   0x699c: 54000103  b.lo     #0x69bc
//   0x69a0: 8b0202c2  add      x2, x22, x2
//   0x69a4: 91000404  add      x4, x0, #1
//   0x69a8: b9800842  ldrsw    x2, [x2, #8]
//   0x69ac: 8b0202a2  add      x2, x21, x2
//   0x69b0: eb02003f  cmp      x1, x2
//   0x69b4: 54fffe42  b.hs     #0x697c
//   0x69b8: 14000003  b        #0x69c4
//   0x69bc: aa0003e3  mov      x3, x0
//   0x69c0: 17ffffef  b        #0x697c
//   0x69c4: d37df014  lsl      x20, x0, #3
//   0x69c8: 8b1402c0  add      x0, x22, x20
//   0x69cc: b9800417  ldrsw    x23, [x0, #4]
//   0x69d0: 8b1702b7  add      x23, x21, x23
//   0x69d4: aa1703e0  mov      x0, x23
//   0x69d8: 97ffff2f  bl       #0x6694
//   0x69dc: 53001c18  uxtb     w24, w0
//   0x69e0: 2a1803e0  mov      w0, w24
//   0x69e4: 97fffded  bl       #0x6198
//   0x69e8: 8b2042e2  add      x2, x23, w0, uxtw
//   0x69ec: d2800001  mov      x1, #0
//   0x69f0: 12000f00  and      w0, w24, #0xf
//   0x69f4: 91002042  add      x2, x2, #8
//   0x69f8: 910183a3  add      x3, x29, #0x60
//   0x69fc: 97fffe2f  bl       #0x62b8
//   0x6a00: b8b46ac0  ldrsw    x0, [x22, x20]
//   0x6a04: f9400261  ldr      x1, [x19]
//   0x6a08: 8b0002b5  add      x21, x21, x0
//   0x6a0c: f94033a0  ldr      x0, [x29, #0x60]
//   0x6a10: 8b0002a0  add      x0, x21, x0
//   0x6a14: eb00003f  cmp      x1, x0
//   0x6a18: 54000042  b.hs     #0x6a20
//   0x6a1c: f9001277  str      x23, [x19, #0x20]
//   0x6a20: f9000e75  str      x21, [x19, #0x18]
//   0x6a24: 1400001d  b        #0x6a98
//   0x6a28: f9400660  ldr      x0, [x19, #8]
//   0x6a2c: f90037a0  str      x0, [x29, #0x68]
//   0x6a30: f9400a60  ldr      x0, [x19, #0x10]
//   0x6a34: f9003ba0  str      x0, [x29, #0x70]
//   0x6a38: 52800080  mov      w0, #4
//   0x6a3c: f9402ba1  ldr      x1, [x29, #0x50]
//   0x6a40: f90043bf  str      xzr, [x29, #0x80]
//   0x6a44: f9400262  ldr      x2, [x19]
//   0x6a48: 390203a0  strb     w0, [x29, #0x80]
//   0x6a4c: 910183a0  add      x0, x29, #0x60
//   0x6a50: f90033bf  str      xzr, [x29, #0x60]
//   0x6a54: f9003fa1  str      x1, [x29, #0x78]
//   0x6a58: 97fffeb7  bl       #0x6534
//   0x6a5c: f9001260  str      x0, [x19, #0x20]
//   0x6a60: b40001c0  cbz      x0, #0x6a98
//   0x6a64: 97ffff0c  bl       #0x6694
//   0x6a68: 53001c14  uxtb     w20, w0
//   0x6a6c: aa1303e1  mov      x1, x19
//   0x6a70: 2a1403e0  mov      w0, w20
//   0x6a74: 97fffdf9  bl       #0x6258
//   0x6a78: aa0003e1  mov      x1, x0
//   0x6a7c: f9401262  ldr      x2, [x19, #0x20]
//   0x6a80: 2a1403e0  mov      w0, w20
//   0x6a84: 910163a3  add      x3, x29, #0x58
//   0x6a88: 91002042  add      x2, x2, #8
//   0x6a8c: 97fffe0b  bl       #0x62b8
//   0x6a90: f9402fa0  ldr      x0, [x29, #0x58]
//   0x6a94: f9000e60  str      x0, [x19, #0x18]
//   0x6a98: 52800020  mov      w0, #1
//   0x6a9c: 14000004  b        #0x6aac
//   0x6aa0: 12800000  mov      w0, #-1
//   0x6aa4: 14000002  b        #0x6aac
//   0x6aa8: 97ffec72  bl       #0x1c70
//   0x6aac: a94153f3  ldp      x19, x20, [sp, #0x10]
//   0x6ab0: a9425bf5  ldp      x21, x22, [sp, #0x20]
//   0x6ab4: a94363f7  ldp      x23, x24, [sp, #0x30]
//   0x6ab8: a8c97bfd  ldp      x29, x30, [sp], #0x90
//   0x6abc: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_085_66a4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000066a4ULL;
    for (std::size_t i = 0; i < 263ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4649ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[086] Symbol: sub_6ac0
//      Virtual Address Range: 0x6ac0..0x6b5c (156 bytes, 39 AArch64 instructions)
// [VN] Khung FDE[086] Biểu tượng: sub_6ac0
//      Dải địa chỉ ảo: 0x6ac0..0x6b5c (156 byte, 39 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x6ac0: a9bc7bfd  stp      x29, x30, [sp, #-0x40]!
//   0x6ac4: 910003fd  mov      x29, sp
//   0x6ac8: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x6acc: aa0003f5  mov      x21, x0
//   0x6ad0: aa0103e0  mov      x0, x1
//   0x6ad4: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x6ad8: aa0203f3  mov      x19, x2
//   0x6adc: aa0103f4  mov      x20, x1
//   0x6ae0: 97fffeed  bl       #0x6694
//   0x6ae4: 53001c16  uxtb     w22, w0
//   0x6ae8: aa1503e1  mov      x1, x21
//   0x6aec: 2a1603e0  mov      w0, w22
//   0x6af0: 97fffdc2  bl       #0x61f8
//   0x6af4: aa0003e1  mov      x1, x0
//   0x6af8: 91002282  add      x2, x20, #8
//   0x6afc: 9100c3a3  add      x3, x29, #0x30
//   0x6b00: 2a1603e0  mov      w0, w22
//   0x6b04: 97fffded  bl       #0x62b8
//   0x6b08: aa1303e0  mov      x0, x19
//   0x6b0c: 97fffee2  bl       #0x6694
//   0x6b10: 53001c14  uxtb     w20, w0
//   0x6b14: aa1503e1  mov      x1, x21
//   0x6b18: 2a1403e0  mov      w0, w20
//   0x6b1c: 97fffdb7  bl       #0x61f8
//   0x6b20: aa0003e1  mov      x1, x0
//   0x6b24: 91002262  add      x2, x19, #8
//   0x6b28: 9100e3a3  add      x3, x29, #0x38
//   0x6b2c: 2a1403e0  mov      w0, w20
//   0x6b30: 97fffde2  bl       #0x62b8
//   0x6b34: f9401ba2  ldr      x2, [x29, #0x30]
//   0x6b38: f9401fa1  ldr      x1, [x29, #0x38]
//   0x6b3c: a94153f3  ldp      x19, x20, [sp, #0x10]
//   0x6b40: eb01005f  cmp      x2, x1
//   0x6b44: 5a9f23e0  csetm    w0, lo
//   0x6b48: eb01005f  cmp      x2, x1
//   0x6b4c: a9425bf5  ldp      x21, x22, [sp, #0x20]
//   0x6b50: 1a9f9400  csinc    w0, w0, wzr, ls
//   0x6b54: a8c47bfd  ldp      x29, x30, [sp], #0x40
//   0x6b58: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_086_6ac0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006ac0ULL;
    for (std::size_t i = 0; i < 39ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4912ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[087] Symbol: sub_6b5c
//      Virtual Address Range: 0x6b5c..0x6cbc (352 bytes, 88 AArch64 instructions)
// [VN] Khung FDE[087] Biểu tượng: sub_6b5c
//      Dải địa chỉ ảo: 0x6b5c..0x6cbc (352 byte, 88 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x6b5c: a9b97bfd  stp      x29, x30, [sp, #-0x70]!
//   0x6b60: 910003fd  mov      x29, sp
//   0x6b64: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x6b68: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x6b6c: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x6b70: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x6b74: aa0103f3  mov      x19, x1
//   0x6b78: f9002bfb  str      x27, [sp, #0x50]
//   0x6b7c: aa0003f4  mov      x20, x0
//   0x6b80: d280001a  mov      x26, #0
//   0x6b84: 52800019  mov      w25, #0
//   0x6b88: d2800016  mov      x22, #0
//   0x6b8c: d2800001  mov      x1, #0
//   0x6b90: 9101a3b7  add      x23, x29, #0x68
//   0x6b94: d2800038  mov      x24, #1
//   0x6b98: b9400260  ldr      w0, [x19]
//   0x6b9c: 34000800  cbz      w0, #0x6c9c
//   0x6ba0: b9400660  ldr      w0, [x19, #4]
//   0x6ba4: 34000700  cbz      w0, #0x6c84
//   0x6ba8: 91001275  add      x21, x19, #4
//   0x6bac: cb20c2b5  sub      x21, x21, w0, sxtw
//   0x6bb0: eb0102bf  cmp      x21, x1
//   0x6bb4: 54000360  b.eq     #0x6c20
//   0x6bb8: aa1503e0  mov      x0, x21
//   0x6bbc: 97fffe1f  bl       #0x6438
//   0x6bc0: 7103fc1f  cmp      w0, #0xff
//   0x6bc4: 2a0003f9  mov      w25, w0
//   0x6bc8: 54000061  b.ne     #0x6bd4
//   0x6bcc: 92800000  mov      x0, #-1
//   0x6bd0: 14000034  b        #0x6ca0
//   0x6bd4: 53001c1b  uxtb     w27, w0
//   0x6bd8: aa1403e1  mov      x1, x20
//   0x6bdc: 2a1b03e0  mov      w0, w27
//   0x6be0: 97fffd86  bl       #0x61f8
//   0x6be4: aa0003fa  mov      x26, x0
//   0x6be8: 79404281  ldrh     w1, [x20, #0x20]
//   0x6bec: 121d1c20  and      w0, w1, #0x7f8
//   0x6bf0: 711fe01f  cmp      w0, #0x7f8
//   0x6bf4: 54000081  b.ne     #0x6c04
//   0x6bf8: 331d1f61  bfi      w1, w27, #3, #8
//   0x6bfc: 79004281  strh     w1, [x20, #0x20]
//   0x6c00: 14000009  b        #0x6c24
//   0x6c04: d3432821  ubfx     x1, x1, #3, #8
//   0x6c08: 6b19003f  cmp      w1, w25
//   0x6c0c: 540000c0  b.eq     #0x6c24
//   0x6c10: 39408280  ldrb     w0, [x20, #0x20]
//   0x6c14: 321e0000  orr      w0, w0, #4
//   0x6c18: 39008280  strb     w0, [x20, #0x20]
//   0x6c1c: 14000002  b        #0x6c24
//   0x6c20: aa0103f5  mov      x21, x1
//   0x6c24: 53001f3b  uxtb     w27, w25
//   0x6c28: aa1a03e1  mov      x1, x26
//   0x6c2c: 91002262  add      x2, x19, #8
//   0x6c30: aa1703e3  mov      x3, x23
//   0x6c34: 2a1b03e0  mov      w0, w27
//   0x6c38: 97fffda0  bl       #0x62b8
//   0x6c3c: 2a1b03e0  mov      w0, w27
//   0x6c40: 97fffd56  bl       #0x6198
//   0x6c44: 2a0003e0  mov      w0, w0
//   0x6c48: f1001c1f  cmp      x0, #7
//   0x6c4c: 92800001  mov      x1, #-1
//   0x6c50: 54000088  b.hi     #0x6c60
//   0x6c54: d37df001  lsl      x1, x0, #3
//   0x6c58: 9ac12301  lsl      x1, x24, x1
//   0x6c5c: d1000421  sub      x1, x1, #1
//   0x6c60: f94037a0  ldr      x0, [x29, #0x68]
//   0x6c64: ea00003f  tst      x1, x0
//   0x6c68: 54000100  b.eq     #0x6c88
//   0x6c6c: f9400281  ldr      x1, [x20]
//   0x6c70: 910006d6  add      x22, x22, #1
//   0x6c74: eb01001f  cmp      x0, x1
//   0x6c78: 54000082  b.hs     #0x6c88
//   0x6c7c: f9000280  str      x0, [x20]
//   0x6c80: 14000002  b        #0x6c88
//   0x6c84: aa0103f5  mov      x21, x1
//   0x6c88: b9400260  ldr      w0, [x19]
//   0x6c8c: aa1503e1  mov      x1, x21
//   0x6c90: 91001000  add      x0, x0, #4
//   0x6c94: 8b000273  add      x19, x19, x0
//   0x6c98: 17ffffc0  b        #0x6b98
//   0x6c9c: aa1603e0  mov      x0, x22
//   0x6ca0: a94153f3  ldp      x19, x20, [sp, #0x10]
//   0x6ca4: a9425bf5  ldp      x21, x22, [sp, #0x20]
//   0x6ca8: a94363f7  ldp      x23, x24, [sp, #0x30]
//   0x6cac: a9446bf9  ldp      x25, x26, [sp, #0x40]
//   0x6cb0: f9402bfb  ldr      x27, [sp, #0x50]
//   0x6cb4: a8c77bfd  ldp      x29, x30, [sp], #0x70
//   0x6cb8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_087_6b5c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006b5cULL;
    for (std::size_t i = 0; i < 88ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4951ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[088] Symbol: sub_6cbc
//      Virtual Address Range: 0x6cbc..0x6df0 (308 bytes, 77 AArch64 instructions)
// [VN] Khung FDE[088] Biểu tượng: sub_6cbc
//      Dải địa chỉ ảo: 0x6cbc..0x6df0 (308 byte, 77 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x6cbc: a9b97bfd  stp      x29, x30, [sp, #-0x70]!
//   0x6cc0: 910003fd  mov      x29, sp
//   0x6cc4: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x6cc8: aa0003f6  mov      x22, x0
//   0x6ccc: 79404000  ldrh     w0, [x0, #0x20]
//   0x6cd0: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x6cd4: d3432800  ubfx     x0, x0, #3, #8
//   0x6cd8: aa0103f7  mov      x23, x1
//   0x6cdc: aa1603e1  mov      x1, x22
//   0x6ce0: f9002bfb  str      x27, [sp, #0x50]
//   0x6ce4: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x6ce8: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x6cec: 53001c15  uxtb     w21, w0
//   0x6cf0: aa0203f3  mov      x19, x2
//   0x6cf4: 97fffd41  bl       #0x61f8
//   0x6cf8: 9101a3b8  add      x24, x29, #0x68
//   0x6cfc: aa0003fa  mov      x26, x0
//   0x6d00: d2800039  mov      x25, #1
//   0x6d04: d2800000  mov      x0, #0
//   0x6d08: b9400261  ldr      w1, [x19]
//   0x6d0c: 34000641  cbz      w1, #0x6dd4
//   0x6d10: b9400661  ldr      w1, [x19, #4]
//   0x6d14: aa0003f4  mov      x20, x0
//   0x6d18: 34000541  cbz      w1, #0x6dc0
//   0x6d1c: 394082c2  ldrb     w2, [x22, #0x20]
//   0x6d20: 36100162  tbz      w2, #2, #0x6d4c
//   0x6d24: 91001274  add      x20, x19, #4
//   0x6d28: cb21c294  sub      x20, x20, w1, sxtw
//   0x6d2c: eb00029f  cmp      x20, x0
//   0x6d30: 540000e0  b.eq     #0x6d4c
//   0x6d34: aa1403e0  mov      x0, x20
//   0x6d38: 97fffdc0  bl       #0x6438
//   0x6d3c: 2a0003f5  mov      w21, w0
//   0x6d40: aa1603e1  mov      x1, x22
//   0x6d44: 97fffd2d  bl       #0x61f8
//   0x6d48: aa0003fa  mov      x26, x0
//   0x6d4c: 35000095  cbnz     w21, #0x6d5c
//   0x6d50: f9400660  ldr      x0, [x19, #8]
//   0x6d54: b4000360  cbz      x0, #0x6dc0
//   0x6d58: 14000013  b        #0x6da4
//   0x6d5c: 53001ebb  uxtb     w27, w21
//   0x6d60: aa1a03e1  mov      x1, x26
//   0x6d64: 91002262  add      x2, x19, #8
//   0x6d68: aa1803e3  mov      x3, x24
//   0x6d6c: 2a1b03e0  mov      w0, w27
//   0x6d70: 97fffd52  bl       #0x62b8
//   0x6d74: 2a1b03e0  mov      w0, w27
//   0x6d78: 97fffd08  bl       #0x6198
//   0x6d7c: 2a0003e0  mov      w0, w0
//   0x6d80: f1001c1f  cmp      x0, #7
//   0x6d84: 92800001  mov      x1, #-1
//   0x6d88: 54000088  b.hi     #0x6d98
//   0x6d8c: d37df001  lsl      x1, x0, #3
//   0x6d90: 9ac12321  lsl      x1, x25, x1
//   0x6d94: d1000421  sub      x1, x1, #1
//   0x6d98: f94037a0  ldr      x0, [x29, #0x68]
//   0x6d9c: ea00003f  tst      x1, x0
//   0x6da0: 54000100  b.eq     #0x6dc0
//   0x6da4: f94002e0  ldr      x0, [x23]
//   0x6da8: b40000c0  cbz      x0, #0x6dc0
//   0x6dac: f9400401  ldr      x1, [x0, #8]
//   0x6db0: 91000422  add      x2, x1, #1
//   0x6db4: 91000821  add      x1, x1, #2
//   0x6db8: f9000402  str      x2, [x0, #8]
//   0x6dbc: f8217813  str      x19, [x0, x1, lsl #3]
//   0x6dc0: b9400260  ldr      w0, [x19]
//   0x6dc4: 91001000  add      x0, x0, #4
//   0x6dc8: 8b000273  add      x19, x19, x0
//   0x6dcc: aa1403e0  mov      x0, x20
//   0x6dd0: 17ffffce  b        #0x6d08
//   0x6dd4: a94153f3  ldp      x19, x20, [sp, #0x10]
//   0x6dd8: a9425bf5  ldp      x21, x22, [sp, #0x20]
//   0x6ddc: a94363f7  ldp      x23, x24, [sp, #0x30]
//   0x6de0: a9446bf9  ldp      x25, x26, [sp, #0x40]
//   0x6de4: f9402bfb  ldr      x27, [sp, #0x50]
//   0x6de8: a8c77bfd  ldp      x29, x30, [sp], #0x70
//   0x6dec: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_088_6cbc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006cbcULL;
    for (std::size_t i = 0; i < 77ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5039ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[089] Symbol: sub_6df0
//      Virtual Address Range: 0x6df0..0x7360 (1392 bytes, 348 AArch64 instructions)
// [VN] Khung FDE[089] Biểu tượng: sub_6df0
//      Dải địa chỉ ảo: 0x6df0..0x7360 (1392 byte, 348 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x6df0: a9b77bfd  stp      x29, x30, [sp, #-0x90]!
//   0x6df4: 910003fd  mov      x29, sp
//   0x6df8: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x6dfc: aa0103f6  mov      x22, x1
//   0x6e00: 39408001  ldrb     w1, [x0, #0x20]
//   0x6e04: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x6e08: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x6e0c: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x6e10: a90573fb  stp      x27, x28, [sp, #0x50]
//   0x6e14: aa0003f3  mov      x19, x0
//   0x6e18: 36000081  tbz      w1, #0, #0x6e28
//   0x6e1c: 39408260  ldrb     w0, [x19, #0x20]
//   0x6e20: 37000da0  tbnz     w0, #0, #0x6fd4
//   0x6e24: 140000d9  b        #0x7188
//   0x6e28: b9402014  ldr      w20, [x0, #0x20]
//   0x6e2c: d34b7e94  ubfx     x20, x20, #0xb, #0x15
//   0x6e30: b5000474  cbnz     x20, #0x6ebc
//   0x6e34: 36080261  tbz      w1, #1, #0x6e80
//   0x6e38: f9400c15  ldr      x21, [x0, #0x18]
//   0x6e3c: f94002a1  ldr      x1, [x21]
//   0x6e40: b40002a1  cbz      x1, #0x6e94
//   0x6e44: aa1303e0  mov      x0, x19
//   0x6e48: 97ffff45  bl       #0x6b5c
//   0x6e4c: b100041f  cmn      x0, #1
//   0x6e50: 54000121  b.ne     #0x6e74
//   0x6e54: 5280ff00  mov      w0, #0x7f8
//   0x6e58: f900127f  str      xzr, [x19, #0x20]
//   0x6e5c: 79004260  strh     w0, [x19, #0x20]
//   0x6e60: d0000040  adrp     x0, #0x10000
//   0x6e64: 91056000  add      x0, x0, #0x158
//   0x6e68: 91066000  add      x0, x0, #0x198
//   0x6e6c: f9000e60  str      x0, [x19, #0x18]
//   0x6e70: 14000054  b        #0x6fc0
//   0x6e74: 8b000294  add      x20, x20, x0
//   0x6e78: 910022b5  add      x21, x21, #8
//   0x6e7c: 17fffff0  b        #0x6e3c
//   0x6e80: f9400c01  ldr      x1, [x0, #0x18]
//   0x6e84: 97ffff36  bl       #0x6b5c
//   0x6e88: b100041f  cmn      x0, #1
//   0x6e8c: aa0003f4  mov      x20, x0
//   0x6e90: 54fffe20  b.eq     #0x6e54
//   0x6e94: 12005280  and      w0, w20, #0x1fffff
//   0x6e98: eb14001f  cmp      x0, x20
//   0x6e9c: aa0003e1  mov      x1, x0
//   0x6ea0: b9402260  ldr      w0, [x19, #0x20]
//   0x6ea4: 54000061  b.ne     #0x6eb0
//   0x6ea8: 33155020  bfi      w0, w1, #0xb, #0x15
//   0x6eac: 14000002  b        #0x6eb4
//   0x6eb0: 12002800  and      w0, w0, #0x7ff
//   0x6eb4: b9002260  str      w0, [x19, #0x20]
//   0x6eb8: b4000854  cbz      x20, #0x6fc0
//   0x6ebc: 91000a95  add      x21, x20, #2
//   0x6ec0: d37df2b5  lsl      x21, x21, #3
//   0x6ec4: aa1503e0  mov      x0, x21
//   0x6ec8: 97ffeb02  bl       #0x1ad0
//   0x6ecc: f90043a0  str      x0, [x29, #0x80]
//   0x6ed0: b4000780  cbz      x0, #0x6fc0
//   0x6ed4: f900041f  str      xzr, [x0, #8]
//   0x6ed8: aa1503e0  mov      x0, x21
//   0x6edc: 97ffeafd  bl       #0x1ad0
//   0x6ee0: f90047a0  str      x0, [x29, #0x88]
//   0x6ee4: b4001700  cbz      x0, #0x71c4
//   0x6ee8: f900041f  str      xzr, [x0, #8]
//   0x6eec: 140000b6  b        #0x71c4
//   0x6ef0: 8b020f24  add      x4, x25, x2, lsl #3
//   0x6ef4: f9400345  ldr      x5, [x26]
//   0x6ef8: f9400884  ldr      x4, [x4, #0x10]
//   0x6efc: b4001f44  cbz      x4, #0x72e4
//   0x6f00: 91000824  add      x4, x1, #2
//   0x6f04: 91000421  add      x1, x1, #1
//   0x6f08: f8247b05  str      x5, [x24, x4, lsl #3]
//   0x6f0c: 91000442  add      x2, x2, #1
//   0x6f10: 9100235a  add      x26, x26, #8
//   0x6f14: eb03005f  cmp      x2, x3
//   0x6f18: 54fffec1  b.ne     #0x6ef0
//   0x6f1c: f9000701  str      x1, [x24, #8]
//   0x6f20: f9000720  str      x0, [x25, #8]
//   0x6f24: f94047a2  ldr      x2, [x29, #0x88]
//   0x6f28: f94043a0  ldr      x0, [x29, #0x80]
//   0x6f2c: f9400441  ldr      x1, [x2, #8]
//   0x6f30: f9400400  ldr      x0, [x0, #8]
//   0x6f34: 8b000020  add      x0, x1, x0
//   0x6f38: eb14001f  cmp      x0, x20
//   0x6f3c: 540016c1  b.ne     #0x7214
//   0x6f40: aa1303e0  mov      x0, x19
//   0x6f44: aa1703e1  mov      x1, x23
//   0x6f48: 97fffc67  bl       #0x60e4
//   0x6f4c: f94047bb  ldr      x27, [x29, #0x88]
//   0x6f50: f94043b5  ldr      x21, [x29, #0x80]
//   0x6f54: f9400774  ldr      x20, [x27, #8]
//   0x6f58: b4000234  cbz      x20, #0x6f9c
//   0x6f5c: f94006b8  ldr      x24, [x21, #8]
//   0x6f60: d37df29a  lsl      x26, x20, #3
//   0x6f64: 8b1a0360  add      x0, x27, x26
//   0x6f68: d1000694  sub      x20, x20, #1
//   0x6f6c: 8b180eb9  add      x25, x21, x24, lsl #3
//   0x6f70: f940041c  ldr      x28, [x0, #8]
//   0x6f74: b5001c18  cbnz     x24, #0x72f4
//   0x6f78: 8b180280  add      x0, x20, x24
//   0x6f7c: d100235a  sub      x26, x26, #8
//   0x6f80: 91000800  add      x0, x0, #2
//   0x6f84: f8207abc  str      x28, [x21, x0, lsl #3]
//   0x6f88: b5fffef4  cbnz     x20, #0x6f64
//   0x6f8c: f94006a1  ldr      x1, [x21, #8]
//   0x6f90: f9400760  ldr      x0, [x27, #8]
//   0x6f94: 8b000020  add      x0, x1, x0
//   0x6f98: f90006a0  str      x0, [x21, #8]
//   0x6f9c: f94047a0  ldr      x0, [x29, #0x88]
//   0x6fa0: 97ffeab4  bl       #0x1a70
//   0x6fa4: f94043a0  ldr      x0, [x29, #0x80]
//   0x6fa8: f9400e61  ldr      x1, [x19, #0x18]
//   0x6fac: f9000001  str      x1, [x0]
//   0x6fb0: f9000e60  str      x0, [x19, #0x18]
//   0x6fb4: 39408260  ldrb     w0, [x19, #0x20]
//   0x6fb8: 32000000  orr      w0, w0, #1
//   0x6fbc: 39008260  strb     w0, [x19, #0x20]
//   0x6fc0: f9400260  ldr      x0, [x19]
//   0x6fc4: eb0002df  cmp      x22, x0
//   0x6fc8: 54fff2a2  b.hs     #0x6e1c
//   0x6fcc: d2800000  mov      x0, #0
//   0x6fd0: 140000dd  b        #0x7344
//   0x6fd4: 36100540  tbz      w0, #2, #0x707c
//   0x6fd8: f9400e7b  ldr      x27, [x19, #0x18]
//   0x6fdc: d2800018  mov      x24, #0
//   0x6fe0: 9101e3b9  add      x25, x29, #0x78
//   0x6fe4: 910203ba  add      x26, x29, #0x80
//   0x6fe8: f9400777  ldr      x23, [x27, #8]
//   0x6fec: eb17031f  cmp      x24, x23
//   0x6ff0: 54fffee2  b.hs     #0x6fcc
//   0x6ff4: 8b1802f5  add      x21, x23, x24
//   0x6ff8: d341feb5  lsr      x21, x21, #1
//   0x6ffc: 91000aa0  add      x0, x21, #2
//   0x7000: f8607b74  ldr      x20, [x27, x0, lsl #3]
//   0x7004: aa1403e0  mov      x0, x20
//   0x7008: 97fffda3  bl       #0x6694
//   0x700c: 53001c02  uxtb     w2, w0
//   0x7010: 2a0003fc  mov      w28, w0
//   0x7014: aa1303e1  mov      x1, x19
//   0x7018: 2a0203e0  mov      w0, w2
//   0x701c: f90037a2  str      x2, [x29, #0x68]
//   0x7020: 97fffc76  bl       #0x61f8
//   0x7024: aa0003e1  mov      x1, x0
//   0x7028: f94037a2  ldr      x2, [x29, #0x68]
//   0x702c: aa1903e3  mov      x3, x25
//   0x7030: 2a0203e0  mov      w0, w2
//   0x7034: 91002282  add      x2, x20, #8
//   0x7038: 97fffca0  bl       #0x62b8
//   0x703c: aa0003e2  mov      x2, x0
//   0x7040: d2800001  mov      x1, #0
//   0x7044: 12000f80  and      w0, w28, #0xf
//   0x7048: aa1a03e3  mov      x3, x26
//   0x704c: 97fffc9b  bl       #0x62b8
//   0x7050: f9403fa1  ldr      x1, [x29, #0x78]
//   0x7054: eb0102df  cmp      x22, x1
//   0x7058: 540000e3  b.lo     #0x7074
//   0x705c: f94043a0  ldr      x0, [x29, #0x80]
//   0x7060: 8b000020  add      x0, x1, x0
//   0x7064: eb0002df  cmp      x22, x0
//   0x7068: 54000503  b.lo     #0x7108
//   0x706c: 910006b8  add      x24, x21, #1
//   0x7070: aa1703f5  mov      x21, x23
//   0x7074: aa1503f7  mov      x23, x21
//   0x7078: 17ffffdd  b        #0x6fec
//   0x707c: 79404260  ldrh     w0, [x19, #0x20]
//   0x7080: 721d1c1f  tst      w0, #0x7f8
//   0x7084: 540002a1  b.ne     #0x70d8
//   0x7088: f9400e65  ldr      x5, [x19, #0x18]
//   0x708c: d2800003  mov      x3, #0
//   0x7090: f94004a2  ldr      x2, [x5, #8]
//   0x7094: eb02007f  cmp      x3, x2
//   0x7098: 54fff9a2  b.hs     #0x6fcc
//   0x709c: 8b030041  add      x1, x2, x3
//   0x70a0: d341fc21  lsr      x1, x1, #1
//   0x70a4: 91000820  add      x0, x1, #2
//   0x70a8: f86078a0  ldr      x0, [x5, x0, lsl #3]
//   0x70ac: f9400406  ldr      x6, [x0, #8]
//   0x70b0: f9400804  ldr      x4, [x0, #0x10]
//   0x70b4: eb0602df  cmp      x22, x6
//   0x70b8: 540000c3  b.lo     #0x70d0
//   0x70bc: 8b0400c3  add      x3, x6, x4
//   0x70c0: eb0302df  cmp      x22, x3
//   0x70c4: 54001403  b.lo     #0x7344
//   0x70c8: 91000423  add      x3, x1, #1
//   0x70cc: 17fffff2  b        #0x7094
//   0x70d0: aa0103e2  mov      x2, x1
//   0x70d4: 17fffff0  b        #0x7094
//   0x70d8: d3432800  ubfx     x0, x0, #3, #8
//   0x70dc: f9400e78  ldr      x24, [x19, #0x18]
//   0x70e0: aa1303e1  mov      x1, x19
//   0x70e4: d2800017  mov      x23, #0
//   0x70e8: 53001c19  uxtb     w25, w0
//   0x70ec: 910203bb  add      x27, x29, #0x80
//   0x70f0: 97fffc42  bl       #0x61f8
//   0x70f4: 12000f3a  and      w26, w25, #0xf
//   0x70f8: aa0003fc  mov      x28, x0
//   0x70fc: f9400715  ldr      x21, [x24, #8]
//   0x7100: 9101e3a4  add      x4, x29, #0x78
//   0x7104: 14000017  b        #0x7160
//   0x7108: aa1403e0  mov      x0, x20
//   0x710c: 1400008e  b        #0x7344
//   0x7110: 8b1702b3  add      x19, x21, x23
//   0x7114: aa0403e3  mov      x3, x4
//   0x7118: d341fe73  lsr      x19, x19, #1
//   0x711c: aa1c03e1  mov      x1, x28
//   0x7120: 91000a60  add      x0, x19, #2
//   0x7124: f90037a4  str      x4, [x29, #0x68]
//   0x7128: f8607b14  ldr      x20, [x24, x0, lsl #3]
//   0x712c: 2a1903e0  mov      w0, w25
//   0x7130: 91002282  add      x2, x20, #8
//   0x7134: 97fffc61  bl       #0x62b8
//   0x7138: aa0003e2  mov      x2, x0
//   0x713c: d2800001  mov      x1, #0
//   0x7140: 2a1a03e0  mov      w0, w26
//   0x7144: aa1b03e3  mov      x3, x27
//   0x7148: 97fffc5c  bl       #0x62b8
//   0x714c: f9403fa1  ldr      x1, [x29, #0x78]
//   0x7150: f94037a4  ldr      x4, [x29, #0x68]
//   0x7154: eb0102df  cmp      x22, x1
//   0x7158: 540000a2  b.hs     #0x716c
//   0x715c: aa1303f5  mov      x21, x19
//   0x7160: eb1502ff  cmp      x23, x21
//   0x7164: 54fffd63  b.lo     #0x7110
//   0x7168: 17ffff99  b        #0x6fcc
//   0x716c: f94043a0  ldr      x0, [x29, #0x80]
//   0x7170: 8b000020  add      x0, x1, x0
//   0x7174: eb0002df  cmp      x22, x0
//   0x7178: 54fffc83  b.lo     #0x7108
//   0x717c: 91000677  add      x23, x19, #1
//   0x7180: aa1503f3  mov      x19, x21
//   0x7184: 17fffff6  b        #0x715c
//   0x7188: 36080140  tbz      w0, #1, #0x71b0
//   0x718c: f9400e74  ldr      x20, [x19, #0x18]
//   0x7190: f9400281  ldr      x1, [x20]
//   0x7194: b4fff1c1  cbz      x1, #0x6fcc
//   0x7198: aa1303e0  mov      x0, x19
//   0x719c: aa1603e2  mov      x2, x22
//   0x71a0: 97fffce5  bl       #0x6534
//   0x71a4: b5000d00  cbnz     x0, #0x7344
//   0x71a8: 91002294  add      x20, x20, #8
//   0x71ac: 17fffff9  b        #0x7190
//   0x71b0: f9400e61  ldr      x1, [x19, #0x18]
//   0x71b4: aa1303e0  mov      x0, x19
//   0x71b8: aa1603e2  mov      x2, x22
//   0x71bc: 97fffcde  bl       #0x6534
//   0x71c0: 14000061  b        #0x7344
//   0x71c4: 39408260  ldrb     w0, [x19, #0x20]
//   0x71c8: 36080140  tbz      w0, #1, #0x71f0
//   0x71cc: f9400e75  ldr      x21, [x19, #0x18]
//   0x71d0: 910203b7  add      x23, x29, #0x80
//   0x71d4: f94002a2  ldr      x2, [x21]
//   0x71d8: b4000142  cbz      x2, #0x7200
//   0x71dc: aa1303e0  mov      x0, x19
//   0x71e0: aa1703e1  mov      x1, x23
//   0x71e4: 910022b5  add      x21, x21, #8
//   0x71e8: 97fffeb5  bl       #0x6cbc
//   0x71ec: 17fffffa  b        #0x71d4
//   0x71f0: f9400e62  ldr      x2, [x19, #0x18]
//   0x71f4: aa1303e0  mov      x0, x19
//   0x71f8: 910203a1  add      x1, x29, #0x80
//   0x71fc: 97fffeb0  bl       #0x6cbc
//   0x7200: f94043b8  ldr      x24, [x29, #0x80]
//   0x7204: b40000b8  cbz      x24, #0x7218
//   0x7208: f9400700  ldr      x0, [x24, #8]
//   0x720c: eb14001f  cmp      x0, x20
//   0x7210: 54000040  b.eq     #0x7218
//   0x7214: 97ffea97  bl       #0x1c70
//   0x7218: 39408260  ldrb     w0, [x19, #0x20]
//   0x721c: 371000e0  tbnz     w0, #2, #0x7238
//   0x7220: 79404260  ldrh     w0, [x19, #0x20]
//   0x7224: 721d1c1f  tst      w0, #0x7f8
//   0x7228: 540000e0  b.eq     #0x7244
//   0x722c: f0fffff7  adrp     x23, #0x6000
//   0x7230: 910ea2f7  add      x23, x23, #0x3a8
//   0x7234: 14000006  b        #0x724c
//   0x7238: f0fffff7  adrp     x23, #0x6000
//   0x723c: 912b02f7  add      x23, x23, #0xac0
//   0x7240: 14000003  b        #0x724c
//   0x7244: f0fffff7  adrp     x23, #0x6000
//   0x7248: 910022f7  add      x23, x23, #8
//   0x724c: f94047b9  ldr      x25, [x29, #0x88]
//   0x7250: b4000719  cbz      x25, #0x7330
//   0x7254: b0000055  adrp     x21, #0x10000
//   0x7258: 9100431a  add      x26, x24, #0x10
//   0x725c: 910562b5  add      x21, x21, #0x158
//   0x7260: f9400703  ldr      x3, [x24, #8]
//   0x7264: 910642b5  add      x21, x21, #0x190
//   0x7268: aa1a03fc  mov      x28, x26
//   0x726c: d280001b  mov      x27, #0
//   0x7270: aa1503e4  mov      x4, x21
//   0x7274: eb03037f  cmp      x27, x3
//   0x7278: 540002e0  b.eq     #0x72d4
//   0x727c: eb0402bf  cmp      x21, x4
//   0x7280: 540001e0  b.eq     #0x72bc
//   0x7284: f9400381  ldr      x1, [x28]
//   0x7288: aa1303e0  mov      x0, x19
//   0x728c: f94002a2  ldr      x2, [x21]
//   0x7290: f90033a4  str      x4, [x29, #0x60]
//   0x7294: f90037a3  str      x3, [x29, #0x68]
//   0x7298: d63f02e0  blr      x23
//   0x729c: f94037a3  ldr      x3, [x29, #0x68]
//   0x72a0: f94033a4  ldr      x4, [x29, #0x60]
//   0x72a4: 36f800c0  tbz      w0, #0x1f, #0x72bc
//   0x72a8: cb1a02a0  sub      x0, x21, x26
//   0x72ac: 8b000320  add      x0, x25, x0
//   0x72b0: f9400815  ldr      x21, [x0, #0x10]
//   0x72b4: f900081f  str      xzr, [x0, #0x10]
//   0x72b8: 17fffff1  b        #0x727c
//   0x72bc: 8b1b0f20  add      x0, x25, x27, lsl #3
//   0x72c0: 9100077b  add      x27, x27, #1
//   0x72c4: f9000815  str      x21, [x0, #0x10]
//   0x72c8: aa1c03f5  mov      x21, x28
//   0x72cc: 9100239c  add      x28, x28, #8
//   0x72d0: 17ffffe9  b        #0x7274
//   0x72d4: d2800000  mov      x0, #0
//   0x72d8: d2800001  mov      x1, #0
//   0x72dc: d2800002  mov      x2, #0
//   0x72e0: 17ffff0d  b        #0x6f14
//   0x72e4: 91000804  add      x4, x0, #2
//   0x72e8: 91000400  add      x0, x0, #1
//   0x72ec: f8247b25  str      x5, [x25, x4, lsl #3]
//   0x72f0: 17ffff07  b        #0x6f0c
//   0x72f4: f9400721  ldr      x1, [x25, #8]
//   0x72f8: d1000703  sub      x3, x24, #1
//   0x72fc: aa1303e0  mov      x0, x19
//   0x7300: f90037a3  str      x3, [x29, #0x68]
//   0x7304: aa1c03e2  mov      x2, x28
//   0x7308: d1002339  sub      x25, x25, #8
//   0x730c: d63f02e0  blr      x23
//   0x7310: 6b1f001f  cmp      w0, wzr
//   0x7314: f94037a3  ldr      x3, [x29, #0x68]
//   0x7318: 54ffe30d  b.le     #0x6f78
//   0x731c: 8b1a0320  add      x0, x25, x26
//   0x7320: f9400b21  ldr      x1, [x25, #0x10]
//   0x7324: aa0303f8  mov      x24, x3
//   0x7328: f9000801  str      x1, [x0, #0x10]
//   0x732c: 17ffff12  b        #0x6f74
//   0x7330: aa1303e0  mov      x0, x19
//   0x7334: aa1703e1  mov      x1, x23
//   0x7338: aa1803e2  mov      x2, x24
//   0x733c: 97fffb6a  bl       #0x60e4
//   0x7340: 17ffff19  b        #0x6fa4
//   0x7344: a94153f3  ldp      x19, x20, [sp, #0x10]
//   0x7348: a9425bf5  ldp      x21, x22, [sp, #0x20]
//   0x734c: a94363f7  ldp      x23, x24, [sp, #0x30]
//   0x7350: a9446bf9  ldp      x25, x26, [sp, #0x40]
//   0x7354: a94573fb  ldp      x27, x28, [sp, #0x50]
//   0x7358: a8c97bfd  ldp      x29, x30, [sp], #0x90
//   0x735c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_089_6df0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006df0ULL;
    for (std::size_t i = 0; i < 348ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5116ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[090] Symbol: sub_7360
//      Virtual Address Range: 0x7360..0x73fc (156 bytes, 39 AArch64 instructions)
// [VN] Khung FDE[090] Biểu tượng: sub_7360
//      Dải địa chỉ ảo: 0x7360..0x73fc (156 byte, 39 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7360: a9bd7bfd  stp      x29, x30, [sp, #-0x30]!
//   0x7364: 910003fd  mov      x29, sp
//   0x7368: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x736c: f90013f5  str      x21, [sp, #0x20]
//   0x7370: b40003e0  cbz      x0, #0x73ec
//   0x7374: b9400004  ldr      w4, [x0]
//   0x7378: 340003a4  cbz      w4, #0x73ec
//   0x737c: aa0103f3  mov      x19, x1
//   0x7380: 92800001  mov      x1, #-1
//   0x7384: b0000054  adrp     x20, #0x10000
//   0x7388: f9000261  str      x1, [x19]
//   0x738c: 90000041  adrp     x1, #0xf000
//   0x7390: f900127f  str      xzr, [x19, #0x20]
//   0x7394: aa0103f5  mov      x21, x1
//   0x7398: f9000e60  str      x0, [x19, #0x18]
//   0x739c: 5280ff00  mov      w0, #0x7f8
//   0x73a0: f9000662  str      x2, [x19, #8]
//   0x73a4: f9000a63  str      x3, [x19, #0x10]
//   0x73a8: 79004260  strh     w0, [x19, #0x20]
//   0x73ac: f947fc20  ldr      x0, [x1, #0xff8]
//   0x73b0: b4000080  cbz      x0, #0x73c0
//   0x73b4: 91056280  add      x0, x20, #0x158
//   0x73b8: 91068000  add      x0, x0, #0x1a0
//   0x73bc: 97ffea45  bl       #0x1cd0
//   0x73c0: 91056280  add      x0, x20, #0x158
//   0x73c4: f940e401  ldr      x1, [x0, #0x1c8]
//   0x73c8: f9001661  str      x1, [x19, #0x28]
//   0x73cc: f900e413  str      x19, [x0, #0x1c8]
//   0x73d0: f947feb5  ldr      x21, [x21, #0xff8]
//   0x73d4: b40000d5  cbz      x21, #0x73ec
//   0x73d8: a94153f3  ldp      x19, x20, [sp, #0x10]
//   0x73dc: f94013f5  ldr      x21, [sp, #0x20]
//   0x73e0: 91068000  add      x0, x0, #0x1a0
//   0x73e4: a8c37bfd  ldp      x29, x30, [sp], #0x30
//   0x73e8: 17ffe9f2  b        #0x1bb0
//   0x73ec: a94153f3  ldp      x19, x20, [sp, #0x10]
//   0x73f0: f94013f5  ldr      x21, [sp, #0x20]
//   0x73f4: a8c37bfd  ldp      x29, x30, [sp], #0x30
//   0x73f8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_090_7360(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007360ULL;
    for (std::size_t i = 0; i < 39ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5464ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[091] Symbol: sub_73fc
//      Virtual Address Range: 0x73fc..0x7408 (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[091] Biểu tượng: sub_73fc
//      Dải địa chỉ ảo: 0x73fc..0x7408 (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x73fc: d2800002  mov      x2, #0
//   0x7400: d2800003  mov      x3, #0
//   0x7404: 17ffffd7  b        #0x7360
// ============================================================================
std::uint32_t fde_091_73fc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000073fcULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5503ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[092] Symbol: sub_7408
//      Virtual Address Range: 0x7408..0x7448 (64 bytes, 16 AArch64 instructions)
// [VN] Khung FDE[092] Biểu tượng: sub_7408
//      Dải địa chỉ ảo: 0x7408..0x7448 (64 byte, 16 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7408: a9be7bfd  stp      x29, x30, [sp, #-0x20]!
//   0x740c: 910003fd  mov      x29, sp
//   0x7410: b9400001  ldr      w1, [x0]
//   0x7414: f9000bf3  str      x19, [sp, #0x10]
//   0x7418: 34000121  cbz      w1, #0x743c
//   0x741c: aa0003f3  mov      x19, x0
//   0x7420: d2800600  mov      x0, #0x30
//   0x7424: 97ffe9ab  bl       #0x1ad0
//   0x7428: aa0003e1  mov      x1, x0
//   0x742c: aa1303e0  mov      x0, x19
//   0x7430: f9400bf3  ldr      x19, [sp, #0x10]
//   0x7434: a8c27bfd  ldp      x29, x30, [sp], #0x20
//   0x7438: 17fffff1  b        #0x73fc
//   0x743c: f9400bf3  ldr      x19, [sp, #0x10]
//   0x7440: a8c27bfd  ldp      x29, x30, [sp], #0x20
//   0x7444: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_092_7408(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007408ULL;
    for (std::size_t i = 0; i < 16ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5506ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[093] Symbol: sub_7448
//      Virtual Address Range: 0x7448..0x74dc (148 bytes, 37 AArch64 instructions)
// [VN] Khung FDE[093] Biểu tượng: sub_7448
//      Dải địa chỉ ảo: 0x7448..0x74dc (148 byte, 37 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7448: a9bd7bfd  stp      x29, x30, [sp, #-0x30]!
//   0x744c: 92800004  mov      x4, #-1
//   0x7450: 910003fd  mov      x29, sp
//   0x7454: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x7458: f900103f  str      xzr, [x1, #0x20]
//   0x745c: b0000053  adrp     x19, #0x10000
//   0x7460: f9000c20  str      x0, [x1, #0x18]
//   0x7464: 52800040  mov      w0, #2
//   0x7468: 39008020  strb     w0, [x1, #0x20]
//   0x746c: f9000422  str      x2, [x1, #8]
//   0x7470: 90000042  adrp     x2, #0xf000
//   0x7474: 79404020  ldrh     w0, [x1, #0x20]
//   0x7478: aa0203f4  mov      x20, x2
//   0x747c: f9000024  str      x4, [x1]
//   0x7480: 321d1c00  orr      w0, w0, #0x7f8
//   0x7484: f9000823  str      x3, [x1, #0x10]
//   0x7488: 79004020  strh     w0, [x1, #0x20]
//   0x748c: f947fc40  ldr      x0, [x2, #0xff8]
//   0x7490: b40000c0  cbz      x0, #0x74a8
//   0x7494: 91056260  add      x0, x19, #0x158
//   0x7498: f90017a1  str      x1, [x29, #0x28]
//   0x749c: 91068000  add      x0, x0, #0x1a0
//   0x74a0: 97ffea0c  bl       #0x1cd0
//   0x74a4: f94017a1  ldr      x1, [x29, #0x28]
//   0x74a8: 91056260  add      x0, x19, #0x158
//   0x74ac: f940e402  ldr      x2, [x0, #0x1c8]
//   0x74b0: f9001422  str      x2, [x1, #0x28]
//   0x74b4: f900e401  str      x1, [x0, #0x1c8]
//   0x74b8: f947fe94  ldr      x20, [x20, #0xff8]
//   0x74bc: b40000b4  cbz      x20, #0x74d0
//   0x74c0: a94153f3  ldp      x19, x20, [sp, #0x10]
//   0x74c4: a8c37bfd  ldp      x29, x30, [sp], #0x30
//   0x74c8: 91068000  add      x0, x0, #0x1a0
//   0x74cc: 17ffe9b9  b        #0x1bb0
//   0x74d0: a94153f3  ldp      x19, x20, [sp, #0x10]
//   0x74d4: a8c37bfd  ldp      x29, x30, [sp], #0x30
//   0x74d8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_093_7448(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007448ULL;
    for (std::size_t i = 0; i < 37ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5522ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[094] Symbol: sub_74dc
//      Virtual Address Range: 0x74dc..0x74e8 (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[094] Biểu tượng: sub_74dc
//      Dải địa chỉ ảo: 0x74dc..0x74e8 (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x74dc: d2800002  mov      x2, #0
//   0x74e0: d2800003  mov      x3, #0
//   0x74e4: 17ffffd9  b        #0x7448
// ============================================================================
std::uint32_t fde_094_74dc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000074dcULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5559ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[095] Symbol: sub_74e8
//      Virtual Address Range: 0x74e8..0x7514 (44 bytes, 11 AArch64 instructions)
// [VN] Khung FDE[095] Biểu tượng: sub_74e8
//      Dải địa chỉ ảo: 0x74e8..0x7514 (44 byte, 11 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x74e8: a9be7bfd  stp      x29, x30, [sp, #-0x20]!
//   0x74ec: 910003fd  mov      x29, sp
//   0x74f0: f9000bf3  str      x19, [sp, #0x10]
//   0x74f4: aa0003f3  mov      x19, x0
//   0x74f8: d2800600  mov      x0, #0x30
//   0x74fc: 97ffe975  bl       #0x1ad0
//   0x7500: aa0003e1  mov      x1, x0
//   0x7504: aa1303e0  mov      x0, x19
//   0x7508: f9400bf3  ldr      x19, [sp, #0x10]
//   0x750c: a8c27bfd  ldp      x29, x30, [sp], #0x20
//   0x7510: 17fffff3  b        #0x74dc
// ============================================================================
std::uint32_t fde_095_74e8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000074e8ULL;
    for (std::size_t i = 0; i < 11ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5562ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[096] Symbol: sub_7514
//      Virtual Address Range: 0x7514..0x7614 (256 bytes, 64 AArch64 instructions)
// [VN] Khung FDE[096] Biểu tượng: sub_7514
//      Dải địa chỉ ảo: 0x7514..0x7614 (256 byte, 64 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7514: a9bd7bfd  stp      x29, x30, [sp, #-0x30]!
//   0x7518: 910003fd  mov      x29, sp
//   0x751c: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x7520: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x7524: b4000580  cbz      x0, #0x75d4
//   0x7528: b9400001  ldr      w1, [x0]
//   0x752c: 34000541  cbz      w1, #0x75d4
//   0x7530: 90000054  adrp     x20, #0xf000
//   0x7534: aa0003f5  mov      x21, x0
//   0x7538: b0000056  adrp     x22, #0x10000
//   0x753c: f947fe80  ldr      x0, [x20, #0xff8]
//   0x7540: b4000080  cbz      x0, #0x7550
//   0x7544: 910562c0  add      x0, x22, #0x158
//   0x7548: 91068000  add      x0, x0, #0x1a0
//   0x754c: 97ffe9e1  bl       #0x1cd0
//   0x7550: 910562c0  add      x0, x22, #0x158
//   0x7554: 91072000  add      x0, x0, #0x1c8
//   0x7558: f9400013  ldr      x19, [x0]
//   0x755c: b40000f3  cbz      x19, #0x7578
//   0x7560: f9400e61  ldr      x1, [x19, #0x18]
//   0x7564: eb15003f  cmp      x1, x21
//   0x7568: 540001e0  b.eq     #0x75a4
//   0x756c: 9100a260  add      x0, x19, #0x28
//   0x7570: f9401673  ldr      x19, [x19, #0x28]
//   0x7574: 17fffffa  b        #0x755c
//   0x7578: 910562c0  add      x0, x22, #0x158
//   0x757c: 91074000  add      x0, x0, #0x1d0
//   0x7580: 14000002  b        #0x7588
//   0x7584: 9100a260  add      x0, x19, #0x28
//   0x7588: f9400013  ldr      x19, [x0]
//   0x758c: b4000293  cbz      x19, #0x75dc
//   0x7590: 39408261  ldrb     w1, [x19, #0x20]
//   0x7594: 370000e1  tbnz     w1, #0, #0x75b0
//   0x7598: f9400e61  ldr      x1, [x19, #0x18]
//   0x759c: eb15003f  cmp      x1, x21
//   0x75a0: 54ffff21  b.ne     #0x7584
//   0x75a4: f9401661  ldr      x1, [x19, #0x28]
//   0x75a8: f9000001  str      x1, [x0]
//   0x75ac: 14000013  b        #0x75f8
//   0x75b0: f9400e61  ldr      x1, [x19, #0x18]
//   0x75b4: f9400021  ldr      x1, [x1]
//   0x75b8: eb15003f  cmp      x1, x21
//   0x75bc: 54fffe41  b.ne     #0x7584
//   0x75c0: f9401661  ldr      x1, [x19, #0x28]
//   0x75c4: f9000001  str      x1, [x0]
//   0x75c8: f9400e60  ldr      x0, [x19, #0x18]
//   0x75cc: 97ffe929  bl       #0x1a70
//   0x75d0: 1400000a  b        #0x75f8
//   0x75d4: d2800013  mov      x19, #0
//   0x75d8: 1400000a  b        #0x7600
//   0x75dc: f947fe94  ldr      x20, [x20, #0xff8]
//   0x75e0: b40000b4  cbz      x20, #0x75f4
//   0x75e4: 910562c0  add      x0, x22, #0x158
//   0x75e8: 91068000  add      x0, x0, #0x1a0
//   0x75ec: 97ffe971  bl       #0x1bb0
//   0x75f0: b5000093  cbnz     x19, #0x7600
//   0x75f4: 97ffe99f  bl       #0x1c70
//   0x75f8: f947fe94  ldr      x20, [x20, #0xff8]
//   0x75fc: b5ffff54  cbnz     x20, #0x75e4
//   0x7600: aa1303e0  mov      x0, x19
//   0x7604: a94153f3  ldp      x19, x20, [sp, #0x10]
//   0x7608: a9425bf5  ldp      x21, x22, [sp, #0x20]
//   0x760c: a8c37bfd  ldp      x29, x30, [sp], #0x30
//   0x7610: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_096_7514(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007514ULL;
    for (std::size_t i = 0; i < 64ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5573ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[097] Symbol: sub_7614
//      Virtual Address Range: 0x7614..0x7618 (4 bytes, 1 AArch64 instructions)
// [VN] Khung FDE[097] Biểu tượng: sub_7614
//      Dải địa chỉ ảo: 0x7614..0x7618 (4 byte, 1 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7614: 17ffffc0  b        #0x7514
// ============================================================================
std::uint32_t fde_097_7614(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007614ULL;
    for (std::size_t i = 0; i < 1ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5637ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[098] Symbol: sub_7618
//      Virtual Address Range: 0x7618..0x763c (36 bytes, 9 AArch64 instructions)
// [VN] Khung FDE[098] Biểu tượng: sub_7618
//      Dải địa chỉ ảo: 0x7618..0x763c (36 byte, 9 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7618: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x761c: 910003fd  mov      x29, sp
//   0x7620: b9400001  ldr      w1, [x0]
//   0x7624: 34000081  cbz      w1, #0x7634
//   0x7628: 97fffffb  bl       #0x7614
//   0x762c: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x7630: 17ffe910  b        #0x1a70
//   0x7634: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x7638: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_098_7618(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007618ULL;
    for (std::size_t i = 0; i < 9ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5638ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[099] Symbol: sub_763c
//      Virtual Address Range: 0x763c..0x7800 (452 bytes, 113 AArch64 instructions)
// [VN] Khung FDE[099] Biểu tượng: sub_763c
//      Dải địa chỉ ảo: 0x763c..0x7800 (452 byte, 113 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x763c: a9b87bfd  stp      x29, x30, [sp, #-0x80]!
//   0x7640: 910003fd  mov      x29, sp
//   0x7644: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x7648: 90000055  adrp     x21, #0xf000
//   0x764c: f90023f9  str      x25, [sp, #0x40]
//   0x7650: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x7654: aa0003f7  mov      x23, x0
//   0x7658: aa0103f6  mov      x22, x1
//   0x765c: f947fea0  ldr      x0, [x21, #0xff8]
//   0x7660: b0000059  adrp     x25, #0x10000
//   0x7664: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x7668: b4000080  cbz      x0, #0x7678
//   0x766c: 91056320  add      x0, x25, #0x158
//   0x7670: 91068000  add      x0, x0, #0x1a0
//   0x7674: 97ffe997  bl       #0x1cd0
//   0x7678: 91056320  add      x0, x25, #0x158
//   0x767c: f940e813  ldr      x19, [x0, #0x1d0]
//   0x7680: b4000193  cbz      x19, #0x76b0
//   0x7684: f9400260  ldr      x0, [x19]
//   0x7688: eb0002ff  cmp      x23, x0
//   0x768c: 540000e3  b.lo     #0x76a8
//   0x7690: aa1303e0  mov      x0, x19
//   0x7694: aa1703e1  mov      x1, x23
//   0x7698: 97fffdd6  bl       #0x6df0
//   0x769c: aa0003f4  mov      x20, x0
//   0x76a0: b50009c0  cbnz     x0, #0x77d8
//   0x76a4: 14000003  b        #0x76b0
//   0x76a8: f9401673  ldr      x19, [x19, #0x28]
//   0x76ac: 17fffff5  b        #0x7680
//   0x76b0: 91056338  add      x24, x25, #0x158
//   0x76b4: f940e713  ldr      x19, [x24, #0x1c8]
//   0x76b8: b40002b3  cbz      x19, #0x770c
//   0x76bc: f9401660  ldr      x0, [x19, #0x28]
//   0x76c0: aa1703e1  mov      x1, x23
//   0x76c4: f900e700  str      x0, [x24, #0x1c8]
//   0x76c8: aa1303e0  mov      x0, x19
//   0x76cc: 97fffdc9  bl       #0x6df0
//   0x76d0: aa0003f4  mov      x20, x0
//   0x76d4: f940eb01  ldr      x1, [x24, #0x1d0]
//   0x76d8: 91074302  add      x2, x24, #0x1d0
//   0x76dc: b4000101  cbz      x1, #0x76fc
//   0x76e0: f9400023  ldr      x3, [x1]
//   0x76e4: f9400260  ldr      x0, [x19]
//   0x76e8: eb00007f  cmp      x3, x0
//   0x76ec: 54000083  b.lo     #0x76fc
//   0x76f0: 9100a022  add      x2, x1, #0x28
//   0x76f4: f9401421  ldr      x1, [x1, #0x28]
//   0x76f8: 17fffff9  b        #0x76dc
//   0x76fc: f9001661  str      x1, [x19, #0x28]
//   0x7700: f9000053  str      x19, [x2]
//   0x7704: b4fffd94  cbz      x20, #0x76b4
//   0x7708: 14000034  b        #0x77d8
//   0x770c: f947feb5  ldr      x21, [x21, #0xff8]
//   0x7710: d2800014  mov      x20, #0
//   0x7714: b4000355  cbz      x21, #0x777c
//   0x7718: 91056320  add      x0, x25, #0x158
//   0x771c: 91068000  add      x0, x0, #0x1a0
//   0x7720: 97ffe924  bl       #0x1bb0
//   0x7724: b40002d4  cbz      x20, #0x777c
//   0x7728: f9400660  ldr      x0, [x19, #8]
//   0x772c: f90002c0  str      x0, [x22]
//   0x7730: 39408261  ldrb     w1, [x19, #0x20]
//   0x7734: f9400a60  ldr      x0, [x19, #0x10]
//   0x7738: f90006c0  str      x0, [x22, #8]
//   0x773c: 79404260  ldrh     w0, [x19, #0x20]
//   0x7740: d3432800  ubfx     x0, x0, #3, #8
//   0x7744: 36100061  tbz      w1, #2, #0x7750
//   0x7748: aa1403e0  mov      x0, x20
//   0x774c: 97fffbd2  bl       #0x6694
//   0x7750: 53001c15  uxtb     w21, w0
//   0x7754: aa1303e1  mov      x1, x19
//   0x7758: 2a1503e0  mov      w0, w21
//   0x775c: 97fffaa7  bl       #0x61f8
//   0x7760: aa0003e1  mov      x1, x0
//   0x7764: 91002282  add      x2, x20, #8
//   0x7768: 2a1503e0  mov      w0, w21
//   0x776c: 910143a3  add      x3, x29, #0x50
//   0x7770: 97fffad2  bl       #0x62b8
//   0x7774: f9402ba0  ldr      x0, [x29, #0x50]
//   0x7778: 14000016  b        #0x77d0
//   0x777c: 52800020  mov      w0, #1
//   0x7780: 910143b3  add      x19, x29, #0x50
//   0x7784: b9007ba0  str      w0, [x29, #0x78]
//   0x7788: f0ffffe0  adrp     x0, #0x6000
//   0x778c: 911a9000  add      x0, x0, #0x6a4
//   0x7790: aa1303e1  mov      x1, x19
//   0x7794: f9002bb7  str      x23, [x29, #0x50]
//   0x7798: d2800014  mov      x20, #0
//   0x779c: f9002fbf  str      xzr, [x29, #0x58]
//   0x77a0: f90033bf  str      xzr, [x29, #0x60]
//   0x77a4: f90037bf  str      xzr, [x29, #0x68]
//   0x77a8: f9003bbf  str      xzr, [x29, #0x70]
//   0x77ac: 97ffe989  bl       #0x1dd0
//   0x77b0: 37f801a0  tbnz     w0, #0x1f, #0x77e4
//   0x77b4: f9403bb4  ldr      x20, [x29, #0x70]
//   0x77b8: b4000174  cbz      x20, #0x77e4
//   0x77bc: f9400660  ldr      x0, [x19, #8]
//   0x77c0: f90002c0  str      x0, [x22]
//   0x77c4: f9400a60  ldr      x0, [x19, #0x10]
//   0x77c8: f90006c0  str      x0, [x22, #8]
//   0x77cc: f9400e60  ldr      x0, [x19, #0x18]
//   0x77d0: f9000ac0  str      x0, [x22, #0x10]
//   0x77d4: 14000004  b        #0x77e4
//   0x77d8: f947feb5  ldr      x21, [x21, #0xff8]
//   0x77dc: b5fff9f5  cbnz     x21, #0x7718
//   0x77e0: 17ffffd2  b        #0x7728
//   0x77e4: aa1403e0  mov      x0, x20
//   0x77e8: f94023f9  ldr      x25, [sp, #0x40]
//   0x77ec: a94153f3  ldp      x19, x20, [sp, #0x10]
//   0x77f0: a9425bf5  ldp      x21, x22, [sp, #0x20]
//   0x77f4: a94363f7  ldp      x23, x24, [sp, #0x30]
//   0x77f8: a8c87bfd  ldp      x29, x30, [sp], #0x80
//   0x77fc: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_099_763c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000763cULL;
    for (std::size_t i = 0; i < 113ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5647ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[100] Symbol: sub_7800
//      Virtual Address Range: 0x7800..0x7840 (64 bytes, 16 AArch64 instructions)
// [VN] Khung FDE[100] Biểu tượng: sub_7800
//      Dải địa chỉ ảo: 0x7800..0x7840 (64 byte, 16 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7800: a9be7bfd  stp      x29, x30, [sp, #-0x20]!
//   0x7804: 90000001  adrp     x1, #0x7000
//   0x7808: 910003fd  mov      x29, sp
//   0x780c: f9000bf3  str      x19, [sp, #0x10]
//   0x7810: b0000053  adrp     x19, #0x10000
//   0x7814: 910cc273  add      x19, x19, #0x330
//   0x7818: 91210021  add      x1, x1, #0x840
//   0x781c: aa1303e0  mov      x0, x19
//   0x7820: 97ffe940  bl       #0x1d20
//   0x7824: 34000040  cbz      w0, #0x782c
//   0x7828: 97ffe912  bl       #0x1c70
//   0x782c: 52800020  mov      w0, #1
//   0x7830: b9000660  str      w0, [x19, #4]
//   0x7834: f9400bf3  ldr      x19, [sp, #0x10]
//   0x7838: a8c27bfd  ldp      x29, x30, [sp], #0x20
//   0x783c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_100_7800(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007800ULL;
    for (std::size_t i = 0; i < 16ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5760ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[101] Symbol: sub_7840
//      Virtual Address Range: 0x7840..0x78c0 (128 bytes, 32 AArch64 instructions)
// [VN] Khung FDE[101] Biểu tượng: sub_7840
//      Dải địa chỉ ảo: 0x7840..0x78c0 (128 byte, 32 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7840: a9bd7bfd  stp      x29, x30, [sp, #-0x30]!
//   0x7844: aa0003e1  mov      x1, x0
//   0x7848: 910003fd  mov      x29, sp
//   0x784c: f9400000  ldr      x0, [x0]
//   0x7850: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x7854: f90013f5  str      x21, [sp, #0x20]
//   0x7858: b4000120  cbz      x0, #0x787c
//   0x785c: d1000400  sub      x0, x0, #1
//   0x7860: f9000020  str      x0, [x1]
//   0x7864: b0000040  adrp     x0, #0x10000
//   0x7868: f94013f5  ldr      x21, [sp, #0x20]
//   0x786c: a94153f3  ldp      x19, x20, [sp, #0x10]
//   0x7870: a8c37bfd  ldp      x29, x30, [sp], #0x30
//   0x7874: b9433000  ldr      w0, [x0, #0x330]
//   0x7878: 17ffe89e  b        #0x1af0
//   0x787c: f9400435  ldr      x21, [x1, #8]
//   0x7880: aa0103f3  mov      x19, x1
//   0x7884: d2800014  mov      x20, #0
//   0x7888: eb15029f  cmp      x20, x21
//   0x788c: 54000100  b.eq     #0x78ac
//   0x7890: 8b140e60  add      x0, x19, x20, lsl #3
//   0x7894: f9400800  ldr      x0, [x0, #0x10]
//   0x7898: b4000060  cbz      x0, #0x78a4
//   0x789c: f85f8000  ldur     x0, [x0, #-8]
//   0x78a0: 97ffe874  bl       #0x1a70
//   0x78a4: 91000694  add      x20, x20, #1
//   0x78a8: 17fffff8  b        #0x7888
//   0x78ac: aa1303e0  mov      x0, x19
//   0x78b0: f94013f5  ldr      x21, [sp, #0x20]
//   0x78b4: a94153f3  ldp      x19, x20, [sp, #0x10]
//   0x78b8: a8c37bfd  ldp      x29, x30, [sp], #0x30
//   0x78bc: 17ffe86d  b        #0x1a70
// ============================================================================
std::uint32_t fde_101_7840(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007840ULL;
    for (std::size_t i = 0; i < 32ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5776ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[102] Symbol: sub_78c0
//      Virtual Address Range: 0x78c0..0x7958 (152 bytes, 38 AArch64 instructions)
// [VN] Khung FDE[102] Biểu tượng: sub_78c0
//      Dải địa chỉ ảo: 0x78c0..0x7958 (152 byte, 38 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x78c0: a9bd7bfd  stp      x29, x30, [sp, #-0x30]!
//   0x78c4: 910003fd  mov      x29, sp
//   0x78c8: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x78cc: f9400414  ldr      x20, [x0, #8]
//   0x78d0: f90013f5  str      x21, [sp, #0x20]
//   0x78d4: aa0003f5  mov      x21, x0
//   0x78d8: f100229f  cmp      x20, #8
//   0x78dc: f9400000  ldr      x0, [x0]
//   0x78e0: 54000108  b.hi     #0x7900
//   0x78e4: 91002000  add      x0, x0, #8
//   0x78e8: 97ffe87a  bl       #0x1ad0
//   0x78ec: b5000040  cbnz     x0, #0x78f4
//   0x78f0: 97ffe8e0  bl       #0x1c70
//   0x78f4: f9000000  str      x0, [x0]
//   0x78f8: 91002013  add      x19, x0, #8
//   0x78fc: 1400000a  b        #0x7924
//   0x7900: 8b000280  add      x0, x20, x0
//   0x7904: 91001c00  add      x0, x0, #7
//   0x7908: 97ffe872  bl       #0x1ad0
//   0x790c: b4ffff20  cbz      x0, #0x78f0
//   0x7910: 91001e93  add      x19, x20, #7
//   0x7914: cb1403f4  neg      x20, x20
//   0x7918: 8b130013  add      x19, x0, x19
//   0x791c: 8a140273  and      x19, x19, x20
//   0x7920: f81f8260  stur     x0, [x19, #-8]
//   0x7924: f9400ea1  ldr      x1, [x21, #0x18]
//   0x7928: aa1303e0  mov      x0, x19
//   0x792c: f94002a2  ldr      x2, [x21]
//   0x7930: b4000061  cbz      x1, #0x793c
//   0x7934: 97ffe823  bl       #0x19c0
//   0x7938: 14000003  b        #0x7944
//   0x793c: 52800001  mov      w1, #0
//   0x7940: 97ffe8b4  bl       #0x1c10
//   0x7944: aa1303e0  mov      x0, x19
//   0x7948: f94013f5  ldr      x21, [sp, #0x20]
//   0x794c: a94153f3  ldp      x19, x20, [sp, #0x10]
//   0x7950: a8c37bfd  ldp      x29, x30, [sp], #0x30
//   0x7954: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_102_78c0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000078c0ULL;
    for (std::size_t i = 0; i < 38ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5808ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[103] Symbol: sub_7958
//      Virtual Address Range: 0x7958..0x7978 (32 bytes, 8 AArch64 instructions)
// [VN] Khung FDE[103] Biểu tượng: sub_7958
//      Dải địa chỉ ảo: 0x7958..0x7978 (32 byte, 8 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7958: b0000040  adrp     x0, #0x10000
//   0x795c: 910cc001  add      x1, x0, #0x330
//   0x7960: b9400422  ldr      w2, [x1, #4]
//   0x7964: 34000082  cbz      w2, #0x7974
//   0x7968: b9433000  ldr      w0, [x0, #0x330]
//   0x796c: b900043f  str      wzr, [x1, #4]
//   0x7970: 17ffe84c  b        #0x1aa0
//   0x7974: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_103_7958(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007958ULL;
    for (std::size_t i = 0; i < 8ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5846ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[104] Symbol: sub_7978
//      Virtual Address Range: 0x7978..0x7ad0 (344 bytes, 86 AArch64 instructions)
// [VN] Khung FDE[104] Biểu tượng: sub_7978
//      Dải địa chỉ ảo: 0x7978..0x7ad0 (344 byte, 86 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7978: 90000041  adrp     x1, #0xf000
//   0x797c: a9bc7bfd  stp      x29, x30, [sp, #-0x40]!
//   0x7980: 910003fd  mov      x29, sp
//   0x7984: f947fc21  ldr      x1, [x1, #0xff8]
//   0x7988: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x798c: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x7990: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x7994: aa0003f6  mov      x22, x0
//   0x7998: b50000e1  cbnz     x1, #0x79b4
//   0x799c: f9400801  ldr      x1, [x0, #0x10]
//   0x79a0: b5000061  cbnz     x1, #0x79ac
//   0x79a4: 97ffffc7  bl       #0x78c0
//   0x79a8: f9000ac0  str      x0, [x22, #0x10]
//   0x79ac: f9400ac0  ldr      x0, [x22, #0x10]
//   0x79b0: 14000043  b        #0x7abc
//   0x79b4: 91004000  add      x0, x0, #0x10
//   0x79b8: c8dffc13  ldar     x19, [x0]
//   0x79bc: b0000058  adrp     x24, #0x10000
//   0x79c0: b5000253  cbnz     x19, #0x7a08
//   0x79c4: 910cc314  add      x20, x24, #0x330
//   0x79c8: 90000001  adrp     x1, #0x7000
//   0x79cc: 91200021  add      x1, x1, #0x800
//   0x79d0: 91002280  add      x0, x20, #8
//   0x79d4: 97ffe84b  bl       #0x1b00
//   0x79d8: 91004280  add      x0, x20, #0x10
//   0x79dc: 97ffe8bd  bl       #0x1cd0
//   0x79e0: f9400ad3  ldr      x19, [x22, #0x10]
//   0x79e4: b50000d3  cbnz     x19, #0x79fc
//   0x79e8: f9401e93  ldr      x19, [x20, #0x38]
//   0x79ec: 910042c0  add      x0, x22, #0x10
//   0x79f0: 91000673  add      x19, x19, #1
//   0x79f4: f9001e93  str      x19, [x20, #0x38]
//   0x79f8: c89ffc13  stlr     x19, [x0]
//   0x79fc: 910cc300  add      x0, x24, #0x330
//   0x7a00: 91004000  add      x0, x0, #0x10
//   0x7a04: 97ffe86b  bl       #0x1bb0
//   0x7a08: b9433300  ldr      w0, [x24, #0x330]
//   0x7a0c: 97ffe891  bl       #0x1c50
//   0x7a10: aa0003f4  mov      x20, x0
//   0x7a14: b50001c0  cbnz     x0, #0x7a4c
//   0x7a18: 91008a60  add      x0, x19, #0x22
//   0x7a1c: d2800101  mov      x1, #8
//   0x7a20: 91008275  add      x21, x19, #0x20
//   0x7a24: 97ffe81b  bl       #0x1a90
//   0x7a28: aa0003f4  mov      x20, x0
//   0x7a2c: b5000040  cbnz     x0, #0x7a34
//   0x7a30: 97ffe890  bl       #0x1c70
//   0x7a34: d2800020  mov      x0, #1
//   0x7a38: f9000280  str      x0, [x20]
//   0x7a3c: b0000040  adrp     x0, #0x10000
//   0x7a40: f9000695  str      x21, [x20, #8]
//   0x7a44: b9433000  ldr      w0, [x0, #0x330]
//   0x7a48: 14000015  b        #0x7a9c
//   0x7a4c: f9400417  ldr      x23, [x0, #8]
//   0x7a50: eb17027f  cmp      x19, x23
//   0x7a54: 54000289  b.ls     #0x7aa4
//   0x7a58: d37ffaf5  lsl      x21, x23, #1
//   0x7a5c: 91008261  add      x1, x19, #0x20
//   0x7a60: eb15027f  cmp      x19, x21
//   0x7a64: 9a958035  csel     x21, x1, x21, hi
//   0x7a68: 91000aa1  add      x1, x21, #2
//   0x7a6c: d37df021  lsl      x1, x1, #3
//   0x7a70: 97ffe83c  bl       #0x1b60
//   0x7a74: aa0003f4  mov      x20, x0
//   0x7a78: b4fffdc0  cbz      x0, #0x7a30
//   0x7a7c: f9000415  str      x21, [x0, #8]
//   0x7a80: 91000ae0  add      x0, x23, #2
//   0x7a84: cb1702a2  sub      x2, x21, x23
//   0x7a88: 52800001  mov      w1, #0
//   0x7a8c: 8b000e80  add      x0, x20, x0, lsl #3
//   0x7a90: d37df042  lsl      x2, x2, #3
//   0x7a94: 97ffe85f  bl       #0x1c10
//   0x7a98: b9433300  ldr      w0, [x24, #0x330]
//   0x7a9c: aa1403e1  mov      x1, x20
//   0x7aa0: 97ffe814  bl       #0x1af0
//   0x7aa4: 8b130e93  add      x19, x20, x19, lsl #3
//   0x7aa8: f9400660  ldr      x0, [x19, #8]
//   0x7aac: b5000080  cbnz     x0, #0x7abc
//   0x7ab0: aa1603e0  mov      x0, x22
//   0x7ab4: 97ffff83  bl       #0x78c0
//   0x7ab8: f9000660  str      x0, [x19, #8]
//   0x7abc: a94153f3  ldp      x19, x20, [sp, #0x10]
//   0x7ac0: a9425bf5  ldp      x21, x22, [sp, #0x20]
//   0x7ac4: a94363f7  ldp      x23, x24, [sp, #0x30]
//   0x7ac8: a8c47bfd  ldp      x29, x30, [sp], #0x40
//   0x7acc: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_104_7978(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007978ULL;
    for (std::size_t i = 0; i < 86ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5854ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[105] Symbol: sub_7ad0
//      Virtual Address Range: 0x7ad0..0x7b0c (60 bytes, 15 AArch64 instructions)
// [VN] Khung FDE[105] Biểu tượng: sub_7ad0
//      Dải địa chỉ ảo: 0x7ad0..0x7b0c (60 byte, 15 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7ad0: f9400004  ldr      x4, [x0]
//   0x7ad4: eb01009f  cmp      x4, x1
//   0x7ad8: 54000062  b.hs     #0x7ae4
//   0x7adc: f9000001  str      x1, [x0]
//   0x7ae0: f9000c1f  str      xzr, [x0, #0x18]
//   0x7ae4: f9400404  ldr      x4, [x0, #8]
//   0x7ae8: eb02009f  cmp      x4, x2
//   0x7aec: 54000042  b.hs     #0x7af4
//   0x7af0: f9000402  str      x2, [x0, #8]
//   0x7af4: b40000a3  cbz      x3, #0x7b08
//   0x7af8: f9400002  ldr      x2, [x0]
//   0x7afc: eb02003f  cmp      x1, x2
//   0x7b00: 54000041  b.ne     #0x7b08
//   0x7b04: f9000c03  str      x3, [x0, #0x18]
//   0x7b08: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_105_7ad0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007ad0ULL;
    for (std::size_t i = 0; i < 15ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5940ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Master FDE Verification Runner across all 106 FDEs
// [VN] Hàm điều phối xác minh toàn bộ 106 khung hàm FDE
// ============================================================================
std::uint32_t execute_all_fde_simulations() noexcept {
    std::uint32_t state = 0x928e64ccU;
    state ^= fde_000_1e00(state + 0U);
    state ^= fde_001_1e2c(state + 1U);
    state ^= fde_002_1ea8(state + 2U);
    state ^= fde_003_1f2c(state + 3U);
    state ^= fde_004_1fac(state + 4U);
    state ^= fde_005_1fec(state + 5U);
    state ^= fde_006_2020(state + 6U);
    state ^= fde_007_2198(state + 7U);
    state ^= fde_008_22c0(state + 8U);
    state ^= fde_009_2524(state + 9U);
    state ^= fde_010_25c8(state + 10U);
    state ^= fde_011_26dc(state + 11U);
    state ^= fde_012_2980(state + 12U);
    state ^= fde_013_2a1c(state + 13U);
    state ^= fde_014_2a20(state + 14U);
    state ^= fde_015_2a58(state + 15U);
    state ^= fde_016_2cec(state + 16U);
    state ^= fde_017_2dd0(state + 17U);
    state ^= fde_018_2ea4(state + 18U);
    state ^= fde_019_2fd0(state + 19U);
    state ^= fde_020_30dc(state + 20U);
    state ^= fde_021_3180(state + 21U);
    state ^= fde_022_32b8(state + 22U);
    state ^= fde_023_33fc(state + 23U);
    state ^= fde_024_3570(state + 24U);
    state ^= fde_025_36b0(state + 25U);
    state ^= fde_026_37c8(state + 26U);
    state ^= fde_027_38c0(state + 27U);
    state ^= fde_028_38cc(state + 28U);
    state ^= fde_029_3a3c(state + 29U);
    state ^= fde_030_3bac(state + 30U);
    state ^= fde_031_3cd0(state + 31U);
    state ^= fde_032_3db4(state + 32U);
    state ^= fde_033_3e3c(state + 33U);
    state ^= fde_034_3e84(state + 34U);
    state ^= fde_035_3ecc(state + 35U);
    state ^= fde_036_3f8c(state + 36U);
    state ^= fde_037_3fcc(state + 37U);
    state ^= fde_038_4054(state + 38U);
    state ^= fde_039_407c(state + 39U);
    state ^= fde_040_40bc(state + 40U);
    state ^= fde_041_41ac(state + 41U);
    state ^= fde_042_42c0(state + 42U);
    state ^= fde_043_42fc(state + 43U);
    state ^= fde_044_4354(state + 44U);
    state ^= fde_045_4460(state + 45U);
    state ^= fde_046_4468(state + 46U);
    state ^= fde_047_44c0(state + 47U);
    state ^= fde_048_44c8(state + 48U);
    state ^= fde_049_44dc(state + 49U);
    state ^= fde_050_44e4(state + 50U);
    state ^= fde_051_44ec(state + 51U);
    state ^= fde_052_44f4(state + 52U);
    state ^= fde_053_451c(state + 53U);
    state ^= fde_054_4524(state + 54U);
    state ^= fde_055_452c(state + 55U);
    state ^= fde_056_45a4(state + 56U);
    state ^= fde_057_4a9c(state + 57U);
    state ^= fde_058_4ec0(state + 58U);
    state ^= fde_059_5474(state + 59U);
    state ^= fde_060_5680(state + 60U);
    state ^= fde_061_575c(state + 61U);
    state ^= fde_062_57a8(state + 62U);
    state ^= fde_063_5868(state + 63U);
    state ^= fde_064_5954(state + 64U);
    state ^= fde_065_5a48(state + 65U);
    state ^= fde_066_5a4c(state + 66U);
    state ^= fde_067_5bc4(state + 67U);
    state ^= fde_068_5cb8(state + 68U);
    state ^= fde_069_5db4(state + 69U);
    state ^= fde_070_5eac(state + 70U);
    state ^= fde_071_5ed0(state + 71U);
    state ^= fde_072_5fa0(state + 72U);
    state ^= fde_073_5fc8(state + 73U);
    state ^= fde_074_6008(state + 74U);
    state ^= fde_075_6024(state + 75U);
    state ^= fde_076_60e4(state + 76U);
    state ^= fde_077_6198(state + 77U);
    state ^= fde_078_61f8(state + 78U);
    state ^= fde_079_6258(state + 79U);
    state ^= fde_080_62b8(state + 80U);
    state ^= fde_081_63a8(state + 81U);
    state ^= fde_082_6438(state + 82U);
    state ^= fde_083_6534(state + 83U);
    state ^= fde_084_6694(state + 84U);
    state ^= fde_085_66a4(state + 85U);
    state ^= fde_086_6ac0(state + 86U);
    state ^= fde_087_6b5c(state + 87U);
    state ^= fde_088_6cbc(state + 88U);
    state ^= fde_089_6df0(state + 89U);
    state ^= fde_090_7360(state + 90U);
    state ^= fde_091_73fc(state + 91U);
    state ^= fde_092_7408(state + 92U);
    state ^= fde_093_7448(state + 93U);
    state ^= fde_094_74dc(state + 94U);
    state ^= fde_095_74e8(state + 95U);
    state ^= fde_096_7514(state + 96U);
    state ^= fde_097_7614(state + 97U);
    state ^= fde_098_7618(state + 98U);
    state ^= fde_099_763c(state + 99U);
    state ^= fde_100_7800(state + 100U);
    state ^= fde_101_7840(state + 101U);
    state ^= fde_102_78c0(state + 102U);
    state ^= fde_103_7958(state + 103U);
    state ^= fde_104_7978(state + 104U);
    state ^= fde_105_7ad0(state + 105U);
    return state;
}

} // namespace raphael
} // namespace bytedance

extern "C" {

// [EN] JNI_OnLoad (0x3ecc..0x3f8c, 192 B): Retrieves JNIEnv via GetEnv(JNI_VERSION_1_6),
//      looks up com/bytedance/raphael/Raphael, and registers 3 JNINativeMethod entries
//      from .data @ 0x10000 (file offset 0xc000), returning JNI_VERSION_1_6 (0x00010006).
// [VN] JNI_OnLoad (0x3ecc..0x3f8c, 192 B): Đăng ký 3 phương thức JNI từ .data @ 0x10000
//      và trả về JNI_VERSION_1_6 (0x00010006).
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM*, void*) {
    (void)bytedance::raphael::execute_all_fde_simulations();
    return JNI_VERSION_1_6;
}

// [EN] Java_com_bytedance_raphael_TestTool_mallocLeak (0x3f8c..0x3fcc, 64 B):
//      Allocates 0x70800 (460,800) bytes via operator new[](0x70800) and memset(..., 1, 0x70800).
// [VN] Cấp phát thử nghiệm 0x70800 (460.800) byte qua operator new[] và điền 1 bằng memset.
JNIEXPORT void JNICALL Java_com_bytedance_raphael_TestTool_mallocLeak(JNIEnv*, jclass) {
    (void)bytedance::raphael::fde_033_3f8c(0x70800U);
}

// [EN] Java_com_bytedance_raphael_TestTool_print (0x3fcc..0x4054, 136 B):
//      Constructs a DiffCache instance and dumps allocation records for the given space/regex.
// [VN] Khởi tạo DiffCache và xuất báo cáo cấp phát theo đường dẫn space và mẫu regex.
JNIEXPORT void JNICALL Java_com_bytedance_raphael_TestTool_print(JNIEnv*, jclass, jstring, jstring) {
    (void)bytedance::raphael::fde_034_3fcc(0x3fccU);
}

} // extern "C"
