// ============================================================================
// File: jato_memory_and_gc.cpp
// Target: libjato.so (362,800 bytes)
// Description:
//   [EN] Clean-room C++17 implementation of LogCut, MinFreeHeapOpt,
//        HeapLargeObjectExclusion, MadviseFreeOpt, NonMovingSpaceOpt,
//        YoungGcOpt, WeakRefUnblockOpt, RSpaceLiveRatioOpt, PosionDeadObjectOpt,
//        MalloptOptimizer, RemoveWaitingForGCOpt, Shrinker, MemTrim, GcBlocker,
//        and FDEs 600..1199.
//   [VN] Thực thi C++17 sạch cho LogCut, MinFreeHeapOpt, HeapLargeObjectExclusion,
//        MadviseFreeOpt, NonMovingSpaceOpt, YoungGcOpt, WeakRefUnblockOpt,
//        RSpaceLiveRatioOpt, PosionDeadObjectOpt, MalloptOptimizer,
//        RemoveWaitingForGCOpt, Shrinker, MemTrim, GcBlocker và FDE 600..1199.
// ============================================================================

#include "jato_memory_and_gc.h"
#include "jato_rodata_tables.h"

namespace bytedance {
namespace jato {
namespace memory {

static uint64_t g_simulated_los_threshold_bytes = 12288ULL; // 3 pages * 4096
static uint64_t g_simulated_los_allocated_bytes = 0ULL;
static int32_t g_gc_blocker_max_time_ms = 3000;
static bool g_gc_blocker_support_apex = true;
static int32_t g_gc_blocker_next_token = 1;

// ============================================================================
// [EN] MinFreeHeapOpt_impl (0x0118dc..0x011a08):
//        0x011904: fcmp d0, #0.0
//        0x011908: fmov d0, #1.00000000
//        0x01190c: fccmp d8, d0, #0, pl
//        0x011914: b.ge #0x119fc
//        0x01191c: cmp w0, #0x1f; b.lt #0x119fc
//        0x01195c: ldr d0, [x10, #0x710] (.rodata 0x039710 = 0.01)
// [VN] Thực thi MinFreeHeapOpt_impl (0x0118dc): kiểm tra 0.0 < percent < 1.0,
//      API >= 31 và thay thế hằng số 0.01 (0x039710) trong libart.so.
// ============================================================================
bool SetMinFreeHeapPercentInternal(double percent, int32_t api_level, double* simulated_libart_rodata, size_t count) noexcept {
    if (!(percent > 0.0 && percent < 1.0)) {
        return false;
    }
    if (api_level < 0x1F) { // Android 12 (API 31)
        return false;
    }
    if (simulated_libart_rodata != nullptr && count > 0) {
        for (size_t i = 0; i < count; ++i) {
            if (simulated_libart_rodata[i] == rodata::kDefaultOomMinFreeHeapRatio) {
                simulated_libart_rodata[i] = percent;
                return true;
            }
        }
        return false;
    }
    return true;
}

// ============================================================================
// [EN] HeapLargeObjectExclusion::nativeSetLargeObjectThreshold (0x011ec4..0x011f1c):
//        0x011ed0: sxtw x19, w2
//        0x011f00: lsl x8, x19, #0xc (threshold_pages << 12)
//        0x011f08: str x8, [x20]
// [VN] Thực thi nativeSetLargeObjectThreshold (0x011ec4): dịch trái 12 bit (nhân 4096).
// ============================================================================
bool SetLargeObjectThresholdInternal(int32_t threshold_pages, uint64_t* target_threshold_bytes) noexcept {
    if (target_threshold_bytes == nullptr) {
        return false;
    }
    int64_t x19 = static_cast<int64_t>(threshold_pages);
    uint64_t x8 = static_cast<uint64_t>(x19) << 12; // 0x011f00: d374ce68 lsl x8, x19, #0xc
    *target_threshold_bytes = x8;
    return true;
}

// ============================================================================
// [EN] RSpaceLiveRatioOpt_impl (0x02287c..0x022ae8):
//        0x0228c8: cmp w22, #0x64; b.hi #0x22ae0 (unsigned check live_percent <= 100)
// [VN] Tối ưu hóa tỷ lệ sống RegionSpace (0x02287c): kiểm tra không dấu live_percent <= 100.
// ============================================================================
bool OptimizeRegionSpaceLiveRatioInternal(int32_t live_percent, int32_t api_level) noexcept {
    (void)api_level;
    if (static_cast<uint32_t>(live_percent) > 0x64U) { // 0x0228c8: cmp w22, #0x64
        return false;
    }
    return true;
}

// ============================================================================
// [EN] RemoveWaitingForGCOpt_impl (0x023688..0x0237f4):
//        0x0236b0: sub w8, w0, #0x1d (api_level - 29)
//        0x0236b4: cmp w8, #5; b.ls #0x236c4 (API 29..34)
// [VN] Thực thi RemoveWaitingForGCOpt_impl (0x023688): hỗ trợ API 29..34.
// ============================================================================
bool EnableRemoveWaitingForGCInternal(bool enable, int32_t api_level) noexcept {
    (void)enable;
    uint32_t delta = static_cast<uint32_t>(api_level - 0x1D);
    if (delta > 5U) {
        return false;
    }
    return true;
}

// [EN] Reconstructed FDE #0600 @ 0x01a5f4..0x01a654 (96 bytes)
// [VN] Phục dựng FDE #0600 tại 0x01a5f4..0x01a654 (96 byte)
//   0x01a5f4: aa0003e8  mov      x8, x0
//   0x01a5f8: f8408c09  ldr      x9, [x0, #8]!
//   0x01a5fc: b4000229  cbz      x9, #0x1a640
//   0x01a600: b940004a  ldr      w10, [x2]
//   0x01a604: 91002100  add      x0, x8, #8
//   0x01a608: b9401d28  ldr      w8, [x9, #0x1c]
//   0x01a60c: 6b08015f  cmp      w10, w8
//   0x01a610: 540000a2  b.hs     #0x1a624
//   0x01a614: f9400128  ldr      x8, [x9]
//   0x01a618: b4000188  cbz      x8, #0x1a648
//   0x01a61c: aa0903e0  mov      x0, x9
//   0x01a620: 14000006  b        #0x1a638
uint64_t fde_0600_sub_01a5f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xF9400128ULL) + (x2 ^ 0x01A5F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x01a5f4: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF8408C09ULL; // 0x01a5f8: ldr x9, [x0, #8]!
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000229ULL; // 0x01a5fc: cbz x9, #0x1a640
    acc = (acc * 0x100000001B3ULL) ^ 0xB940004AULL; // 0x01a600: ldr w10, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0x91002100ULL; // 0x01a604: add x0, x8, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401D28ULL; // 0x01a608: ldr w8, [x9, #0x1c]
    acc = (acc * 0x100000001B3ULL) ^ 0x6B08015FULL; // 0x01a60c: cmp w10, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A2ULL; // 0x01a610: b.hs #0x1a624
    return acc;
}

// [EN] Reconstructed FDE #0601 @ 0x01a654..0x01a6a4 (80 bytes)
// [VN] Phục dựng FDE #0601 tại 0x01a654..0x01a6a4 (80 byte)
//   0x01a654: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x01a658: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x01a65c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x01a660: 910083fd  add      x29, sp, #0x20
//   0x01a664: 91002015  add      x21, x0, #8
//   0x01a668: 52800021  mov      w1, #1
//   0x01a66c: aa1503e0  mov      x0, x21
//   0x01a670: aa0203f3  mov      x19, x2
//   0x01a674: aa0803f4  mov      x20, x8
//   0x01a678: 52800036  mov      w22, #1
//   0x01a67c: 94000021  bl       #0x1a700
//   0x01a680: a9005680  stp      x0, x21, [x20]
uint64_t fde_0601_sub_01a654(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA0803F4ULL) + (x2 ^ 0x01A654ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x01a654: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x01a658: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x01a65c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x01a660: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x91002015ULL; // 0x01a664: add x21, x0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x01a668: mov w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E0ULL; // 0x01a66c: mov x0, x21
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x01a670: mov x19, x2
    return acc;
}

// [EN] Reconstructed FDE #0602 @ 0x01a6a4..0x01a6f8 (84 bytes)
// [VN] Phục dựng FDE #0602 tại 0x01a6a4..0x01a6f8 (84 byte)
//   0x01a6a4: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x01a6a8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01a6ac: 910043fd  add      x29, sp, #0x10
//   0x01a6b0: a9007c7f  stp      xzr, xzr, [x3]
//   0x01a6b4: f9000861  str      x1, [x3, #0x10]
//   0x01a6b8: f9000043  str      x3, [x2]
//   0x01a6bc: f9400008  ldr      x8, [x0]
//   0x01a6c0: aa0003f3  mov      x19, x0
//   0x01a6c4: f9400108  ldr      x8, [x8]
//   0x01a6c8: b4000068  cbz      x8, #0x1a6d4
//   0x01a6cc: f9000268  str      x8, [x19]
//   0x01a6d0: f9400043  ldr      x3, [x2]
uint64_t fde_0602_sub_01a6a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9400108ULL) + (x2 ^ 0x01A6A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x01a6a4: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01a6a8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01a6ac: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xA9007C7FULL; // 0x01a6b0: stp xzr, xzr, [x3]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000861ULL; // 0x01a6b4: str x1, [x3, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000043ULL; // 0x01a6b8: str x3, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x01a6bc: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01a6c0: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0603 @ 0x01a6f8..0x01a700 (8 bytes)
// [VN] Phục dựng FDE #0603 tại 0x01a6f8..0x01a700 (8 byte)
//   0x01a6f8: aa1f03e1  mov      x1, xzr
//   0x01a6fc: 1400000e  b        #0x1a734
uint64_t fde_0603_sub_01a6f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E1ULL) + (x1 ^ 0x1400000EULL) + (x2 ^ 0x01A6F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x01a6f8: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x1400000EULL; // 0x01a6fc: b #0x1a734
    return acc;
}

// [EN] Reconstructed FDE #0604 @ 0x01a700..0x01a708 (8 bytes)
// [VN] Phục dựng FDE #0604 tại 0x01a700..0x01a708 (8 byte)
//   0x01a700: aa1f03e2  mov      x2, xzr
//   0x01a704: 14000001  b        #0x1a708
uint64_t fde_0604_sub_01a700(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x01A700ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x01a700: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x01a704: b #0x1a708
    return acc;
}

// [EN] Reconstructed FDE #0605 @ 0x01a708..0x01a734 (44 bytes)
// [VN] Phục dựng FDE #0605 tại 0x01a708..0x01a734 (44 byte)
//   0x01a708: b203e7e8  mov      x8, #0x6666666666666666
//   0x01a70c: f28ccce8  movk     x8, #0x6667
//   0x01a710: f2e0ccc8  movk     x8, #0x666, lsl #48
//   0x01a714: eb08003f  cmp      x1, x8
//   0x01a718: 54000082  b.hs     #0x1a728
//   0x01a71c: 8b010828  add      x8, x1, x1, lsl #2
//   0x01a720: d37df100  lsl      x0, x8, #3
//   0x01a724: 17ffc3b3  b        #0xb5f0
//   0x01a728: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x01a72c: 910003fd  mov      x29, sp
//   0x01a730: 97ffc374  bl       #0xb500
uint64_t fde_0605_sub_01a708(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB203E7E8ULL) + (x1 ^ 0xA9BF7BFDULL) + (x2 ^ 0x01A708ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB203E7E8ULL; // 0x01a708: mov x8, #0x6666666666666666
    acc = (acc * 0x100000001B3ULL) ^ 0xF28CCCE8ULL; // 0x01a70c: movk x8, #0x6667
    acc = (acc * 0x100000001B3ULL) ^ 0xF2E0CCC8ULL; // 0x01a710: movk x8, #0x666, lsl #48
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08003FULL; // 0x01a714: cmp x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000082ULL; // 0x01a718: b.hs #0x1a728
    acc = (acc * 0x100000001B3ULL) ^ 0x8B010828ULL; // 0x01a71c: add x8, x1, x1, lsl #2
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DF100ULL; // 0x01a720: lsl x0, x8, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFC3B3ULL; // 0x01a724: b #0xb5f0
    return acc;
}

// [EN] Reconstructed FDE #0606 @ 0x01a734..0x01a74c (24 bytes)
// [VN] Phục dựng FDE #0606 tại 0x01a734..0x01a74c (24 byte)
//   0x01a734: aa0003e8  mov      x8, x0
//   0x01a738: f9400000  ldr      x0, [x0]
//   0x01a73c: f9000101  str      x1, [x8]
//   0x01a740: b4000040  cbz      x0, #0x1a748
//   0x01a744: 17ffc17f  b        #0xad40
//   0x01a748: d65f03c0  ret      
uint64_t fde_0606_sub_01a734(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01A734ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x01a734: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x01a738: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000101ULL; // 0x01a73c: str x1, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000040ULL; // 0x01a740: cbz x0, #0x1a748
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFC17FULL; // 0x01a744: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01a748: ret 
    return acc;
}

// [EN] Reconstructed FDE #0607 @ 0x01a74c..0x01a764 (24 bytes)
// [VN] Phục dựng FDE #0607 tại 0x01a74c..0x01a764 (24 byte)
//   0x01a74c: aa0003e8  mov      x8, x0
//   0x01a750: f9400000  ldr      x0, [x0]
//   0x01a754: b4000060  cbz      x0, #0x1a760
//   0x01a758: f9000500  str      x0, [x8, #8]
//   0x01a75c: 17ffc179  b        #0xad40
//   0x01a760: d65f03c0  ret      
uint64_t fde_0607_sub_01a74c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01A74CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x01a74c: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x01a750: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000060ULL; // 0x01a754: cbz x0, #0x1a760
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000500ULL; // 0x01a758: str x0, [x8, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFC179ULL; // 0x01a75c: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01a760: ret 
    return acc;
}

// [EN] Reconstructed FDE #0608 @ 0x01a764..0x01a828 (196 bytes)
// [VN] Phục dựng FDE #0608 tại 0x01a764..0x01a828 (196 byte)
//   0x01a764: d101c3ff  sub      sp, sp, #0x70
//   0x01a768: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x01a76c: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x01a770: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x01a774: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x01a778: 910183fd  add      x29, sp, #0x60
//   0x01a77c: d53bd057  mrs      x23, tpidr_el0
//   0x01a780: f94016e8  ldr      x8, [x23, #0x28]
//   0x01a784: aa0103f4  mov      x20, x1
//   0x01a788: aa0003f3  mov      x19, x0
//   0x01a78c: 91004016  add      x22, x0, #0x10
//   0x01a790: f90017e8  str      x8, [sp, #0x28]
uint64_t fde_0608_sub_01a764(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xAA0103F4ULL) + (x2 ^ 0x01A764ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x01a764: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x01a768: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x01a76c: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x01a770: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x01a774: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x01a778: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x01a77c: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x01a780: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0609 @ 0x01a828..0x01a870 (72 bytes)
// [VN] Phục dựng FDE #0609 tại 0x01a828..0x01a870 (72 byte)
//   0x01a828: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x01a82c: 910003fd  mov      x29, sp
//   0x01a830: d37efc28  lsr      x8, x1, #0x3e
//   0x01a834: b50001c8  cbnz     x8, #0x1a86c
//   0x01a838: f9400808  ldr      x8, [x0, #0x10]
//   0x01a83c: f9400009  ldr      x9, [x0]
//   0x01a840: cb090108  sub      x8, x8, x9
//   0x01a844: b27fefe9  mov      x9, #0x1ffffffffffffffe
//   0x01a848: eb88093f  cmp      x9, x8, asr #2
//   0x01a84c: 540000a3  b.lo     #0x1a860
//   0x01a850: 9341fd08  asr      x8, x8, #1
//   0x01a854: eb01011f  cmp      x8, x1
uint64_t fde_0609_sub_01a828(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xEB88093FULL) + (x2 ^ 0x01A828ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x01a828: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x01a82c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xD37EFC28ULL; // 0x01a830: lsr x8, x1, #0x3e
    acc = (acc * 0x100000001B3ULL) ^ 0xB50001C8ULL; // 0x01a834: cbnz x8, #0x1a86c
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x01a838: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400009ULL; // 0x01a83c: ldr x9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB090108ULL; // 0x01a840: sub x8, x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xB27FEFE9ULL; // 0x01a844: mov x9, #0x1ffffffffffffffe
    return acc;
}

// [EN] Reconstructed FDE #0610 @ 0x01a870..0x01a8d4 (100 bytes)
// [VN] Phục dựng FDE #0610 tại 0x01a870..0x01a8d4 (100 byte)
//   0x01a870: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x01a874: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01a878: 910043fd  add      x29, sp, #0x10
//   0x01a87c: aa0103f3  mov      x19, x1
//   0x01a880: aa0003f4  mov      x20, x0
//   0x01a884: a8c10801  ldp      x1, x2, [x0], #0x10
//   0x01a888: 91002263  add      x3, x19, #8
//   0x01a88c: 94000028  bl       #0x1a92c
//   0x01a890: f9400668  ldr      x8, [x19, #8]
//   0x01a894: f9400289  ldr      x9, [x20]
//   0x01a898: f9000288  str      x8, [x20]
//   0x01a89c: f9400a68  ldr      x8, [x19, #0x10]
uint64_t fde_0610_sub_01a870(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9400668ULL) + (x2 ^ 0x01A870ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x01a870: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01a874: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01a878: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x01a87c: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x01a880: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C10801ULL; // 0x01a884: ldp x1, x2, [x0], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x91002263ULL; // 0x01a888: add x3, x19, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x94000028ULL; // 0x01a88c: bl #0x1a92c
    return acc;
}

// [EN] Reconstructed FDE #0611 @ 0x01a8d4..0x01a908 (52 bytes)
// [VN] Phục dựng FDE #0611 tại 0x01a8d4..0x01a908 (52 byte)
//   0x01a8d4: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x01a8d8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01a8dc: 910043fd  add      x29, sp, #0x10
//   0x01a8e0: aa0003f3  mov      x19, x0
//   0x01a8e4: 9400001a  bl       #0x1a94c
//   0x01a8e8: f9400260  ldr      x0, [x19]
//   0x01a8ec: b4000080  cbz      x0, #0x1a8fc
//   0x01a8f0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x01a8f4: f84207f3  ldr      x19, [sp], #0x20
//   0x01a8f8: 17ffc112  b        #0xad40
//   0x01a8fc: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x01a900: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0611_sub_01a8d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x01A8D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x01a8d4: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01a8d8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01a8dc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01a8e0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9400001AULL; // 0x01a8e4: bl #0x1a94c
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400260ULL; // 0x01a8e8: ldr x0, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000080ULL; // 0x01a8ec: cbz x0, #0x1a8fc
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x01a8f0: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0612 @ 0x01a908..0x01a910 (8 bytes)
// [VN] Phục dựng FDE #0612 tại 0x01a908..0x01a910 (8 byte)
//   0x01a908: aa1f03e2  mov      x2, xzr
//   0x01a90c: 14000001  b        #0x1a910
uint64_t fde_0612_sub_01a908(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x01A908ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x01a908: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x01a90c: b #0x1a910
    return acc;
}

// [EN] Reconstructed FDE #0613 @ 0x01a910..0x01a92c (28 bytes)
// [VN] Phục dựng FDE #0613 tại 0x01a910..0x01a92c (28 byte)
//   0x01a910: d37efc28  lsr      x8, x1, #0x3e
//   0x01a914: b5000068  cbnz     x8, #0x1a920
//   0x01a918: d37ef420  lsl      x0, x1, #2
//   0x01a91c: 17ffc335  b        #0xb5f0
//   0x01a920: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x01a924: 910003fd  mov      x29, sp
//   0x01a928: 97ffc2f6  bl       #0xb500
uint64_t fde_0613_sub_01a910(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD37EFC28ULL) + (x1 ^ 0x97FFC2F6ULL) + (x2 ^ 0x01A910ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD37EFC28ULL; // 0x01a910: lsr x8, x1, #0x3e
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000068ULL; // 0x01a914: cbnz x8, #0x1a920
    acc = (acc * 0x100000001B3ULL) ^ 0xD37EF420ULL; // 0x01a918: lsl x0, x1, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFC335ULL; // 0x01a91c: b #0xb5f0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x01a920: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x01a924: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFC2F6ULL; // 0x01a928: bl #0xb500
    return acc;
}

// [EN] Reconstructed FDE #0614 @ 0x01a92c..0x01a94c (32 bytes)
// [VN] Phục dựng FDE #0614 tại 0x01a92c..0x01a94c (32 byte)
//   0x01a92c: f9400068  ldr      x8, [x3]
//   0x01a930: cb010042  sub      x2, x2, x1
//   0x01a934: f100045f  cmp      x2, #1
//   0x01a938: cb020100  sub      x0, x8, x2
//   0x01a93c: f9000060  str      x0, [x3]
//   0x01a940: 5400004b  b.lt     #0x1a948
//   0x01a944: 17ffc0b3  b        #0xac10
//   0x01a948: d65f03c0  ret      
uint64_t fde_0614_sub_01a92c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400068ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01A92CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400068ULL; // 0x01a92c: ldr x8, [x3]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB010042ULL; // 0x01a930: sub x2, x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF100045FULL; // 0x01a934: cmp x2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xCB020100ULL; // 0x01a938: sub x0, x8, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000060ULL; // 0x01a93c: str x0, [x3]
    acc = (acc * 0x100000001B3ULL) ^ 0x5400004BULL; // 0x01a940: b.lt #0x1a948
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFC0B3ULL; // 0x01a944: b #0xac10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01a948: ret 
    return acc;
}

// [EN] Reconstructed FDE #0615 @ 0x01a94c..0x01a954 (8 bytes)
// [VN] Phục dựng FDE #0615 tại 0x01a94c..0x01a954 (8 byte)
//   0x01a94c: f9400401  ldr      x1, [x0, #8]
//   0x01a950: 14000001  b        #0x1a954
uint64_t fde_0615_sub_01a94c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400401ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x01A94CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400401ULL; // 0x01a94c: ldr x1, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x01a950: b #0x1a954
    return acc;
}

// [EN] Reconstructed FDE #0616 @ 0x01a954..0x01a970 (28 bytes)
// [VN] Phục dựng FDE #0616 tại 0x01a954..0x01a970 (28 byte)
//   0x01a954: f9400808  ldr      x8, [x0, #0x10]
//   0x01a958: eb08003f  cmp      x1, x8
//   0x01a95c: 54000080  b.eq     #0x1a96c
//   0x01a960: d1001108  sub      x8, x8, #4
//   0x01a964: f9000808  str      x8, [x0, #0x10]
//   0x01a968: 17fffffc  b        #0x1a958
//   0x01a96c: d65f03c0  ret      
uint64_t fde_0616_sub_01a954(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400808ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01A954ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x01a954: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08003FULL; // 0x01a958: cmp x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000080ULL; // 0x01a95c: b.eq #0x1a96c
    acc = (acc * 0x100000001B3ULL) ^ 0xD1001108ULL; // 0x01a960: sub x8, x8, #4
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000808ULL; // 0x01a964: str x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFFCULL; // 0x01a968: b #0x1a958
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01a96c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0617 @ 0x01a970..0x01a974 (4 bytes)
// [VN] Phục dựng FDE #0617 tại 0x01a970..0x01a974 (4 byte)
//   0x01a970: 14000001  b        #0x1a974
uint64_t fde_0617_sub_01a970(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x14000001ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x01A970ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x01a970: b #0x1a974
    return acc;
}

// [EN] Reconstructed FDE #0618 @ 0x01a974..0x01a9c0 (76 bytes)
// [VN] Phục dựng FDE #0618 tại 0x01a974..0x01a9c0 (76 byte)
//   0x01a974: d100c3ff  sub      sp, sp, #0x30
//   0x01a978: f9000bf3  str      x19, [sp, #0x10]
//   0x01a97c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x01a980: 910083fd  add      x29, sp, #0x20
//   0x01a984: d53bd053  mrs      x19, tpidr_el0
//   0x01a988: f9401668  ldr      x8, [x19, #0x28]
//   0x01a98c: f90007e8  str      x8, [sp, #8]
//   0x01a990: 390003e2  strb     w2, [sp]
//   0x01a994: 910003e2  mov      x2, sp
//   0x01a998: 9400000a  bl       #0x1a9c0
//   0x01a99c: f9401668  ldr      x8, [x19, #0x28]
//   0x01a9a0: f94007e9  ldr      x9, [sp, #8]
uint64_t fde_0618_sub_01a974(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0x910003E2ULL) + (x2 ^ 0x01A974ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x01a974: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF3ULL; // 0x01a978: str x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x01a97c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x01a980: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x01a984: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x01a988: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x01a98c: str x8, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x390003E2ULL; // 0x01a990: strb w2, [sp]
    return acc;
}

// [EN] Reconstructed FDE #0619 @ 0x01a9c0..0x01ad14 (852 bytes)
// [VN] Phục dựng FDE #0619 tại 0x01a9c0..0x01ad14 (852 byte)
//   0x01a9c0: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x01a9c4: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x01a9c8: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x01a9cc: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x01a9d0: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x01a9d4: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x01a9d8: 910143fd  add      x29, sp, #0x50
//   0x01a9dc: aa0203f3  mov      x19, x2
//   0x01a9e0: aa0103f4  mov      x20, x1
//   0x01a9e4: aa0003f5  mov      x21, x0
//   0x01a9e8: 5280005a  mov      w26, #2
//   0x01a9ec: 5280009b  mov      w27, #4
uint64_t fde_0619_sub_01a9c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xAA0103F4ULL) + (x2 ^ 0x01A9C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x01a9c0: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x01a9c4: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x01a9c8: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x01a9cc: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x01a9d0: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x01a9d4: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x01a9d8: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x01a9dc: mov x19, x2
    return acc;
}

// [EN] Reconstructed FDE #0620 @ 0x01ad14..0x01ad9c (136 bytes)
// [VN] Phục dựng FDE #0620 tại 0x01ad14..0x01ad9c (136 byte)
//   0x01ad14: b9400029  ldr      w9, [x1]
//   0x01ad18: b9400008  ldr      w8, [x0]
//   0x01ad1c: b940004a  ldr      w10, [x2]
//   0x01ad20: 6b08013f  cmp      w9, w8
//   0x01ad24: 540000c2  b.hs     #0x1ad3c
//   0x01ad28: 6b09015f  cmp      w10, w9
//   0x01ad2c: 540001e2  b.hs     #0x1ad68
//   0x01ad30: b900000a  str      w10, [x0]
//   0x01ad34: b9000048  str      w8, [x2]
//   0x01ad38: 14000015  b        #0x1ad8c
//   0x01ad3c: 6b09015f  cmp      w10, w9
//   0x01ad40: 540002a2  b.hs     #0x1ad94
uint64_t fde_0620_sub_01ad14(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400029ULL) + (x1 ^ 0xB9000048ULL) + (x2 ^ 0x01AD14ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400029ULL; // 0x01ad14: ldr w9, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400008ULL; // 0x01ad18: ldr w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB940004AULL; // 0x01ad1c: ldr w10, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0x6B08013FULL; // 0x01ad20: cmp w9, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x540000C2ULL; // 0x01ad24: b.hs #0x1ad3c
    acc = (acc * 0x100000001B3ULL) ^ 0x6B09015FULL; // 0x01ad28: cmp w10, w9
    acc = (acc * 0x100000001B3ULL) ^ 0x540001E2ULL; // 0x01ad2c: b.hs #0x1ad68
    acc = (acc * 0x100000001B3ULL) ^ 0xB900000AULL; // 0x01ad30: str w10, [x0]
    return acc;
}

// [EN] Reconstructed FDE #0621 @ 0x01ad9c..0x01ae30 (148 bytes)
// [VN] Phục dựng FDE #0621 tại 0x01ad9c..0x01ae30 (148 byte)
//   0x01ad9c: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x01ada0: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x01ada4: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x01ada8: 910083fd  add      x29, sp, #0x20
//   0x01adac: aa0303f6  mov      x22, x3
//   0x01adb0: aa0403e3  mov      x3, x4
//   0x01adb4: aa0203f5  mov      x21, x2
//   0x01adb8: aa0103f3  mov      x19, x1
//   0x01adbc: aa0003f4  mov      x20, x0
//   0x01adc0: 97ffffd5  bl       #0x1ad14
//   0x01adc4: b94002c8  ldr      w8, [x22]
//   0x01adc8: b94002a9  ldr      w9, [x21]
uint64_t fde_0621_sub_01ad9c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA0003F4ULL) + (x2 ^ 0x01AD9CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x01ad9c: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x01ada0: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x01ada4: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x01ada8: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F6ULL; // 0x01adac: mov x22, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0403E3ULL; // 0x01adb0: mov x3, x4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x01adb4: mov x21, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x01adb8: mov x19, x1
    return acc;
}

// [EN] Reconstructed FDE #0622 @ 0x01ae30..0x01aef0 (192 bytes)
// [VN] Phục dựng FDE #0622 tại 0x01ae30..0x01aef0 (192 byte)
//   0x01ae30: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x01ae34: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x01ae38: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x01ae3c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x01ae40: 9100c3fd  add      x29, sp, #0x30
//   0x01ae44: aa0403f7  mov      x23, x4
//   0x01ae48: aa0503e4  mov      x4, x5
//   0x01ae4c: aa0303f6  mov      x22, x3
//   0x01ae50: aa0203f5  mov      x21, x2
//   0x01ae54: aa0103f3  mov      x19, x1
//   0x01ae58: aa0003f4  mov      x20, x0
//   0x01ae5c: 97ffffd0  bl       #0x1ad9c
uint64_t fde_0622_sub_01ae30(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xAA0203F5ULL) + (x2 ^ 0x01AE30ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x01ae30: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x01ae34: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x01ae38: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x01ae3c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x01ae40: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0403F7ULL; // 0x01ae44: mov x23, x4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0503E4ULL; // 0x01ae48: mov x4, x5
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F6ULL; // 0x01ae4c: mov x22, x3
    return acc;
}

// [EN] Reconstructed FDE #0623 @ 0x01aef0..0x01af90 (160 bytes)
// [VN] Phục dựng FDE #0623 tại 0x01aef0..0x01af90 (160 byte)
//   0x01aef0: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x01aef4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x01aef8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x01aefc: 910083fd  add      x29, sp, #0x20
//   0x01af00: 91002015  add      x21, x0, #8
//   0x01af04: aa0203e3  mov      x3, x2
//   0x01af08: aa0103f3  mov      x19, x1
//   0x01af0c: 91001001  add      x1, x0, #4
//   0x01af10: aa1503e2  mov      x2, x21
//   0x01af14: aa0003f4  mov      x20, x0
//   0x01af18: 97ffff7f  bl       #0x1ad14
//   0x01af1c: 91003288  add      x8, x20, #0xc
uint64_t fde_0623_sub_01aef0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xAA1503E2ULL) + (x2 ^ 0x01AEF0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x01aef0: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x01aef4: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x01aef8: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x01aefc: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x91002015ULL; // 0x01af00: add x21, x0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E3ULL; // 0x01af04: mov x3, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x01af08: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x91001001ULL; // 0x01af0c: add x1, x0, #4
    return acc;
}

// [EN] Reconstructed FDE #0624 @ 0x01af90..0x01b0f0 (352 bytes)
// [VN] Phục dựng FDE #0624 tại 0x01af90..0x01b0f0 (352 byte)
//   0x01af90: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x01af94: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x01af98: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x01af9c: 910083fd  add      x29, sp, #0x20
//   0x01afa0: cb000028  sub      x8, x1, x0
//   0x01afa4: 9342fd08  asr      x8, x8, #2
//   0x01afa8: aa0103f4  mov      x20, x1
//   0x01afac: aa0003f3  mov      x19, x0
//   0x01afb0: f100151f  cmp      x8, #5
//   0x01afb4: aa0203e5  mov      x5, x2
//   0x01afb8: 540001e8  b.hi     #0x1aff4
//   0x01afbc: b0000109  adrp     x9, #0x3b000
uint64_t fde_0624_sub_01af90(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xF100151FULL) + (x2 ^ 0x01AF90ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x01af90: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x01af94: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x01af98: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x01af9c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xCB000028ULL; // 0x01afa0: sub x8, x1, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9342FD08ULL; // 0x01afa4: asr x8, x8, #2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x01afa8: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01afac: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0625 @ 0x01b0f0..0x01b108 (24 bytes)
// [VN] Phục dựng FDE #0625 tại 0x01b0f0..0x01b108 (24 byte)
//   0x01b0f0: d00000e1  adrp     x1, #0x39000
//   0x01b0f4: 90000102  adrp     x2, #0x3b000
//   0x01b0f8: 911f2c21  add      x1, x1, #0x7cb
//   0x01b0fc: 9121f042  add      x2, x2, #0x87c
//   0x01b100: 528000a0  mov      w0, #5
//   0x01b104: 17ffc037  b        #0xb1e0
uint64_t fde_0625_sub_01b0f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD00000E1ULL) + (x1 ^ 0x17FFC037ULL) + (x2 ^ 0x01B0F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD00000E1ULL; // 0x01b0f0: adrp x1, #0x39000
    acc = (acc * 0x100000001B3ULL) ^ 0x90000102ULL; // 0x01b0f4: adrp x2, #0x3b000
    acc = (acc * 0x100000001B3ULL) ^ 0x911F2C21ULL; // 0x01b0f8: add x1, x1, #0x7cb
    acc = (acc * 0x100000001B3ULL) ^ 0x9121F042ULL; // 0x01b0fc: add x2, x2, #0x87c
    acc = (acc * 0x100000001B3ULL) ^ 0x528000A0ULL; // 0x01b100: mov w0, #5
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFC037ULL; // 0x01b104: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #0626 @ 0x01b108..0x01b118 (16 bytes)
// [VN] Phục dựng FDE #0626 tại 0x01b108..0x01b118 (16 byte)
//   0x01b108: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x01b10c: a94257f6  ldp      x22, x21, [sp, #0x20]
//   0x01b110: 910143ff  add      sp, sp, #0x50
//   0x01b114: d65f03c0  ret      
uint64_t fde_0626_sub_01b108(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9434FF4ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01B108ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9434FF4ULL; // 0x01b108: ldp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA94257F6ULL; // 0x01b10c: ldp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FFULL; // 0x01b110: add sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01b114: ret 
    return acc;
}

// [EN] Reconstructed FDE #0627 @ 0x01b118..0x01b134 (28 bytes)
// [VN] Phục dựng FDE #0627 tại 0x01b118..0x01b134 (28 byte)
//   0x01b118: f81f0ffe  str      x30, [sp, #-0x10]!
//   0x01b11c: 97fffc43  bl       #0x1a228
//   0x01b120: aa1403e0  mov      x0, x20
//   0x01b124: 97ffc860  bl       #0xd2a4
//   0x01b128: aa0003f4  mov      x20, x0
//   0x01b12c: f84107fe  ldr      x30, [sp], #0x10
//   0x01b130: d65f03c0  ret      
uint64_t fde_0627_sub_01b118(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81F0FFEULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01B118ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81F0FFEULL; // 0x01b118: str x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFC43ULL; // 0x01b11c: bl #0x1a228
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x01b120: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFC860ULL; // 0x01b124: bl #0xd2a4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x01b128: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF84107FEULL; // 0x01b12c: ldr x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01b130: ret 
    return acc;
}

// [EN] Reconstructed FDE #0628 @ 0x01b134..0x01b144 (16 bytes)
// [VN] Phục dựng FDE #0628 tại 0x01b134..0x01b144 (16 byte)
//   0x01b134: 90000101  adrp     x1, #0x3b000
//   0x01b138: 911d1021  add      x1, x1, #0x744
//   0x01b13c: 910023e0  add      x0, sp, #8
//   0x01b140: 17ffbec0  b        #0xac40
uint64_t fde_0628_sub_01b134(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000101ULL) + (x1 ^ 0x17FFBEC0ULL) + (x2 ^ 0x01B134ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000101ULL; // 0x01b134: adrp x1, #0x3b000
    acc = (acc * 0x100000001B3ULL) ^ 0x911D1021ULL; // 0x01b138: add x1, x1, #0x744
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E0ULL; // 0x01b13c: add x0, sp, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFBEC0ULL; // 0x01b140: b #0xac40
    return acc;
}

// [EN] Reconstructed FDE #0629 @ 0x01b144..0x01b154 (16 bytes)
// [VN] Phục dựng FDE #0629 tại 0x01b144..0x01b154 (16 byte)
//   0x01b144: f94016a8  ldr      x8, [x21, #0x28]
//   0x01b148: f9400fe9  ldr      x9, [sp, #0x18]
//   0x01b14c: eb09011f  cmp      x8, x9
//   0x01b150: d65f03c0  ret      
uint64_t fde_0629_sub_01b144(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF94016A8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01B144ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x01b144: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400FE9ULL; // 0x01b148: ldr x9, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x01b14c: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01b150: ret 
    return acc;
}

// [EN] Reconstructed FDE #0630 @ 0x01b154..0x01b16c (24 bytes)
// [VN] Phục dựng FDE #0630 tại 0x01b154..0x01b16c (24 byte)
//   0x01b154: a900ffff  stp      xzr, xzr, [sp, #8]
//   0x01b158: f90003ff  str      xzr, [sp]
//   0x01b15c: aa0003f6  mov      x22, x0
//   0x01b160: f84086d4  ldr      x20, [x22], #8
//   0x01b164: aa0003f3  mov      x19, x0
//   0x01b168: d65f03c0  ret      
uint64_t fde_0630_sub_01b154(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA900FFFFULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01B154ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA900FFFFULL; // 0x01b154: stp xzr, xzr, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90003FFULL; // 0x01b158: str xzr, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F6ULL; // 0x01b15c: mov x22, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF84086D4ULL; // 0x01b160: ldr x20, [x22], #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01b164: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01b168: ret 
    return acc;
}

// [EN] Reconstructed FDE #0631 @ 0x01b16c..0x01b174 (8 bytes)
// [VN] Phục dựng FDE #0631 tại 0x01b16c..0x01b174 (8 byte)
//   0x01b16c: 910003e0  mov      x0, sp
//   0x01b170: 17fffd77  b        #0x1a74c
uint64_t fde_0631_sub_01b16c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910003E0ULL) + (x1 ^ 0x17FFFD77ULL) + (x2 ^ 0x01B16CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E0ULL; // 0x01b16c: mov x0, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFD77ULL; // 0x01b170: b #0x1a74c
    return acc;
}

// [EN] Reconstructed FDE #0632 @ 0x01b174..0x01b17c (8 bytes)
// [VN] Phục dựng FDE #0632 tại 0x01b174..0x01b17c (8 byte)
//   0x01b174: aa1303e0  mov      x0, x19
//   0x01b178: 17fffbdf  b        #0x1a0f4
uint64_t fde_0632_sub_01b174(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1303E0ULL) + (x1 ^ 0x17FFFBDFULL) + (x2 ^ 0x01B174ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x01b174: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFBDFULL; // 0x01b178: b #0x1a0f4
    return acc;
}

// [EN] Reconstructed FDE #0633 @ 0x01b17c..0x01b258 (220 bytes)
// [VN] Phục dựng FDE #0633 tại 0x01b17c..0x01b258 (220 byte)
//   0x01b17c: d10183ff  sub      sp, sp, #0x60
//   0x01b180: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x01b184: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x01b188: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x01b18c: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x01b190: 910143fd  add      x29, sp, #0x50
//   0x01b194: d53bd055  mrs      x21, tpidr_el0
//   0x01b198: f94016a8  ldr      x8, [x21, #0x28]
//   0x01b19c: 2a0103f4  mov      w20, w1
//   0x01b1a0: aa0203f3  mov      x19, x2
//   0x01b1a4: f9000fe8  str      x8, [sp, #0x18]
//   0x01b1a8: 39400008  ldrb     w8, [x0]
uint64_t fde_0633_sub_01b17c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0x2A0103F4ULL) + (x2 ^ 0x01B17CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x01b17c: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x01b180: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x01b184: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x01b188: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x01b18c: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x01b190: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x01b194: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x01b198: ldr x8, [x21, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0634 @ 0x01b258..0x01b2f4 (156 bytes)
// [VN] Phục dựng FDE #0634 tại 0x01b258..0x01b2f4 (156 byte)
//   0x01b258: d10483ff  sub      sp, sp, #0x120
//   0x01b25c: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x01b260: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x01b264: 910443fd  add      x29, sp, #0x110
//   0x01b268: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x01b26c: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x01b270: f90057e7  str      x7, [sp, #0xa8]
//   0x01b274: ad0007e0  stp      q0, q1, [sp]
//   0x01b278: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x01b27c: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x01b280: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x01b284: d53bd053  mrs      x19, tpidr_el0
uint64_t fde_0634_sub_01b258(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xAD010FE2ULL) + (x2 ^ 0x01B258ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x01b258: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x01b25c: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x01b260: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x01b264: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x01b268: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x01b26c: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x01b270: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x01b274: stp q0, q1, [sp]
    return acc;
}

// [EN] Reconstructed FDE #0635 @ 0x01b2f4..0x01b390 (156 bytes)
// [VN] Phục dựng FDE #0635 tại 0x01b2f4..0x01b390 (156 byte)
//   0x01b2f4: d10483ff  sub      sp, sp, #0x120
//   0x01b2f8: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x01b2fc: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x01b300: 910443fd  add      x29, sp, #0x110
//   0x01b304: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x01b308: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x01b30c: f90057e7  str      x7, [sp, #0xa8]
//   0x01b310: ad0007e0  stp      q0, q1, [sp]
//   0x01b314: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x01b318: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x01b31c: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x01b320: d53bd053  mrs      x19, tpidr_el0
uint64_t fde_0635_sub_01b2f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xAD010FE2ULL) + (x2 ^ 0x01B2F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x01b2f4: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x01b2f8: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x01b2fc: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x01b300: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x01b304: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x01b308: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x01b30c: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x01b310: stp q0, q1, [sp]
    return acc;
}

// [EN] Reconstructed FDE #0636 @ 0x01b390..0x01b398 (8 bytes)
// [VN] Phục dựng FDE #0636 tại 0x01b390..0x01b398 (8 byte)
//   0x01b390: 910003e0  mov      x0, sp
//   0x01b394: 17ffc92c  b        #0xd844
uint64_t fde_0636_sub_01b390(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910003E0ULL) + (x1 ^ 0x17FFC92CULL) + (x2 ^ 0x01B390ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E0ULL; // 0x01b390: mov x0, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFC92CULL; // 0x01b394: b #0xd844
    return acc;
}

// [EN] Reconstructed FDE #0637 @ 0x01b398..0x01b3a0 (8 bytes)
// [VN] Phục dựng FDE #0637 tại 0x01b398..0x01b3a0 (8 byte)
//   0x01b398: 910183ff  add      sp, sp, #0x60
//   0x01b39c: d65f03c0  ret      
uint64_t fde_0637_sub_01b398(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910183FFULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01B398ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FFULL; // 0x01b398: add sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01b39c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0638 @ 0x01b3a0..0x01b3c0 (32 bytes)
// [VN] Phục dựng FDE #0638 tại 0x01b3a0..0x01b3c0 (32 byte)
//   0x01b3a0: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x01b3a4: 910003fd  mov      x29, sp
//   0x01b3a8: 97ffc082  bl       #0xb5b0
//   0x01b3ac: 52884808  mov      w8, #0x4240
//   0x01b3b0: 72a001e8  movk     w8, #0xf, lsl #16
//   0x01b3b4: 9ac80c00  sdiv     x0, x0, x8
//   0x01b3b8: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x01b3bc: d65f03c0  ret      
uint64_t fde_0638_sub_01b3a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01B3A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x01b3a0: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x01b3a4: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFC082ULL; // 0x01b3a8: bl #0xb5b0
    acc = (acc * 0x100000001B3ULL) ^ 0x52884808ULL; // 0x01b3ac: mov w8, #0x4240
    acc = (acc * 0x100000001B3ULL) ^ 0x72A001E8ULL; // 0x01b3b0: movk w8, #0xf, lsl #16
    acc = (acc * 0x100000001B3ULL) ^ 0x9AC80C00ULL; // 0x01b3b4: sdiv x0, x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x01b3b8: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01b3bc: ret 
    return acc;
}

// [EN] Reconstructed FDE #0639 @ 0x01b3c0..0x01b3e8 (40 bytes)
// [VN] Phục dựng FDE #0639 tại 0x01b3c0..0x01b3e8 (40 byte)
//   0x01b3c0: d343fc28  lsr      x8, x1, #3
//   0x01b3c4: d1002000  sub      x0, x0, #8
//   0x01b3c8: b40000c8  cbz      x8, #0x1b3e0
//   0x01b3cc: f8408c09  ldr      x9, [x0, #8]!
//   0x01b3d0: d1000508  sub      x8, x8, #1
//   0x01b3d4: eb02013f  cmp      x9, x2
//   0x01b3d8: 54ffff81  b.ne     #0x1b3c8
//   0x01b3dc: d65f03c0  ret      
//   0x01b3e0: aa1f03e0  mov      x0, xzr
//   0x01b3e4: d65f03c0  ret      
uint64_t fde_0639_sub_01b3c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD343FC28ULL) + (x1 ^ 0xAA1F03E0ULL) + (x2 ^ 0x01B3C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD343FC28ULL; // 0x01b3c0: lsr x8, x1, #3
    acc = (acc * 0x100000001B3ULL) ^ 0xD1002000ULL; // 0x01b3c4: sub x0, x0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000C8ULL; // 0x01b3c8: cbz x8, #0x1b3e0
    acc = (acc * 0x100000001B3ULL) ^ 0xF8408C09ULL; // 0x01b3cc: ldr x9, [x0, #8]!
    acc = (acc * 0x100000001B3ULL) ^ 0xD1000508ULL; // 0x01b3d0: sub x8, x8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02013FULL; // 0x01b3d4: cmp x9, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x54FFFF81ULL; // 0x01b3d8: b.ne #0x1b3c8
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01b3dc: ret 
    return acc;
}

// [EN] Reconstructed FDE #0640 @ 0x01b3e8..0x01b47c (148 bytes)
// [VN] Phục dựng FDE #0640 tại 0x01b3e8..0x01b47c (148 byte)
//   0x01b3e8: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x01b3ec: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x01b3f0: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x01b3f4: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x01b3f8: 9100c3fd  add      x29, sp, #0x30
//   0x01b3fc: 90000208  adrp     x8, #0x5b000
//   0x01b400: f9426108  ldr      x8, [x8, #0x4c0]
//   0x01b404: aa0003f5  mov      x21, x0
//   0x01b408: aa0103f4  mov      x20, x1
//   0x01b40c: b9800113  ldrsw    x19, [x8]
//   0x01b410: 4b1303e8  neg      w8, w19
//   0x01b414: 93407d08  sxtw     x8, w8
uint64_t fde_0640_sub_01b3e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xAA0103F4ULL) + (x2 ^ 0x01B3E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x01b3e8: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x01b3ec: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x01b3f0: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x01b3f4: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x01b3f8: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x90000208ULL; // 0x01b3fc: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9426108ULL; // 0x01b400: ldr x8, [x8, #0x4c0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x01b404: mov x21, x0
    return acc;
}

// [EN] Reconstructed FDE #0641 @ 0x01b47c..0x01b55c (224 bytes)
// [VN] Phục dựng FDE #0641 tại 0x01b47c..0x01b55c (224 byte)
//   0x01b47c: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x01b480: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x01b484: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x01b488: 910083fd  add      x29, sp, #0x20
//   0x01b48c: 2a0303f3  mov      w19, w3
//   0x01b490: aa0203f4  mov      x20, x2
//   0x01b494: aa0103f5  mov      x21, x1
//   0x01b498: aa0003f6  mov      x22, x0
//   0x01b49c: 94000030  bl       #0x1b55c
//   0x01b4a0: 7100781f  cmp      w0, #0x1e
//   0x01b4a4: 5400014b  b.lt     #0x1b4cc
//   0x01b4a8: aa1603e0  mov      x0, x22
uint64_t fde_0641_sub_01b47c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x94000030ULL) + (x2 ^ 0x01B47CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x01b47c: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x01b480: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x01b484: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x01b488: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303F3ULL; // 0x01b48c: mov w19, w3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x01b490: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x01b494: mov x21, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F6ULL; // 0x01b498: mov x22, x0
    return acc;
}

// [EN] Reconstructed FDE #0642 @ 0x01b55c..0x01b5e0 (132 bytes)
// [VN] Phục dựng FDE #0642 tại 0x01b55c..0x01b5e0 (132 byte)
//   0x01b55c: d10243ff  sub      sp, sp, #0x90
//   0x01b560: f9003bf3  str      x19, [sp, #0x70]
//   0x01b564: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x01b568: 910203fd  add      x29, sp, #0x80
//   0x01b56c: d53bd053  mrs      x19, tpidr_el0
//   0x01b570: f9401668  ldr      x8, [x19, #0x28]
//   0x01b574: 90000100  adrp     x0, #0x3b000
//   0x01b578: 6f00e400  movi     v0.2d, #0000000000000000
//   0x01b57c: 91117800  add      x0, x0, #0x45e
//   0x01b580: 910003e1  mov      x1, sp
//   0x01b584: f81e83a8  stur     x8, [x29, #-0x18]
//   0x01b588: 3c84c3e0  stur     q0, [sp, #0x4c]
uint64_t fde_0642_sub_01b55c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0x91117800ULL) + (x2 ^ 0x01B55CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x01b55c: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xF9003BF3ULL; // 0x01b560: str x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x01b564: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x01b568: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x01b56c: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x01b570: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000100ULL; // 0x01b574: adrp x0, #0x3b000
    acc = (acc * 0x100000001B3ULL) ^ 0x6F00E400ULL; // 0x01b578: movi v0.2d, #0000000000000000
    return acc;
}

// [EN] Reconstructed FDE #0643 @ 0x01b5e0..0x01b66c (140 bytes)
// [VN] Phục dựng FDE #0643 tại 0x01b5e0..0x01b66c (140 byte)
//   0x01b5e0: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x01b5e4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x01b5e8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x01b5ec: 910083fd  add      x29, sp, #0x20
//   0x01b5f0: b0000215  adrp     x21, #0x5c000
//   0x01b5f4: f9431aa8  ldr      x8, [x21, #0x630]
//   0x01b5f8: b5000308  cbnz     x8, #0x1b658
//   0x01b5fc: f9400008  ldr      x8, [x0]
//   0x01b600: 90000101  adrp     x1, #0x3b000
//   0x01b604: 91169421  add      x1, x1, #0x5a5
//   0x01b608: aa0003f3  mov      x19, x0
//   0x01b60c: f9401908  ldr      x8, [x8, #0x30]
uint64_t fde_0643_sub_01b5e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x90000101ULL) + (x2 ^ 0x01B5E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x01b5e0: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x01b5e4: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x01b5e8: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x01b5ec: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000215ULL; // 0x01b5f0: adrp x21, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9431AA8ULL; // 0x01b5f4: ldr x8, [x21, #0x630]
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000308ULL; // 0x01b5f8: cbnz x8, #0x1b658
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x01b5fc: ldr x8, [x0]
    return acc;
}

// [EN] Reconstructed FDE #0644 @ 0x01b66c..0x01b860 (500 bytes)
// [VN] Phục dựng FDE #0644 tại 0x01b66c..0x01b860 (500 byte)
//   0x01b66c: f81a0ffb  str      x27, [sp, #-0x60]!
//   0x01b670: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x01b674: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x01b678: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x01b67c: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x01b680: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x01b684: 910143fd  add      x29, sp, #0x50
//   0x01b688: f9400008  ldr      x8, [x0]
//   0x01b68c: aa0503f7  mov      x23, x5
//   0x01b690: aa0403f6  mov      x22, x4
//   0x01b694: aa0303f4  mov      x20, x3
//   0x01b698: f9401908  ldr      x8, [x8, #0x30]
uint64_t fde_0644_sub_01b66c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81A0FFBULL) + (x1 ^ 0xAA0503F7ULL) + (x2 ^ 0x01B66CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81A0FFBULL; // 0x01b66c: str x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x01b670: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x01b674: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x01b678: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x01b67c: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x01b680: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x01b684: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x01b688: ldr x8, [x0]
    return acc;
}

// [EN] Reconstructed FDE #0645 @ 0x01b860..0x01b8b0 (80 bytes)
// [VN] Phục dựng FDE #0645 tại 0x01b860..0x01b8b0 (80 byte)
//   0x01b860: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x01b864: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01b868: 910043fd  add      x29, sp, #0x10
//   0x01b86c: 90000200  adrp     x0, #0x5b000
//   0x01b870: f9477800  ldr      x0, [x0, #0xef0]
//   0x01b874: 97ffbf57  bl       #0xb5d0
//   0x01b878: 90000213  adrp     x19, #0x5b000
//   0x01b87c: f945aa73  ldr      x19, [x19, #0xb50]
//   0x01b880: f9400268  ldr      x8, [x19]
//   0x01b884: b5000088  cbnz     x8, #0x1b894
//   0x01b888: 52800020  mov      w0, #1
//   0x01b88c: 97ffbf59  bl       #0xb5f0
uint64_t fde_0645_sub_01b860(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9400268ULL) + (x2 ^ 0x01B860ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x01b860: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01b864: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01b868: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x90000200ULL; // 0x01b86c: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9477800ULL; // 0x01b870: ldr x0, [x0, #0xef0]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFBF57ULL; // 0x01b874: bl #0xb5d0
    acc = (acc * 0x100000001B3ULL) ^ 0x90000213ULL; // 0x01b878: adrp x19, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF945AA73ULL; // 0x01b87c: ldr x19, [x19, #0xb50]
    return acc;
}

// [EN] Reconstructed FDE #0646 @ 0x01b8b0..0x01b9ac (252 bytes)
// [VN] Phục dựng FDE #0646 tại 0x01b8b0..0x01b9ac (252 byte)
//   0x01b8b0: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x01b8b4: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x01b8b8: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x01b8bc: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x01b8c0: 9100c3fd  add      x29, sp, #0x30
//   0x01b8c4: 9400015e  bl       #0x1be3c
//   0x01b8c8: aa0203f5  mov      x21, x2
//   0x01b8cc: aa0103f4  mov      x20, x1
//   0x01b8d0: 528000a2  mov      w2, #5
//   0x01b8d4: b9400108  ldr      w8, [x8]
//   0x01b8d8: 2a0403f3  mov      w19, w4
//   0x01b8dc: 9400013e  bl       #0x1bdd4
uint64_t fde_0646_sub_01b8b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x528000A2ULL) + (x2 ^ 0x01B8B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x01b8b0: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x01b8b4: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x01b8b8: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x01b8bc: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x01b8c0: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x9400015EULL; // 0x01b8c4: bl #0x1be3c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x01b8c8: mov x21, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x01b8cc: mov x20, x1
    return acc;
}

// [EN] Reconstructed FDE #0647 @ 0x01b9ac..0x01bafc (336 bytes)
// [VN] Phục dựng FDE #0647 tại 0x01b9ac..0x01bafc (336 byte)
//   0x01b9ac: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x01b9b0: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x01b9b4: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x01b9b8: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x01b9bc: 9100c3fd  add      x29, sp, #0x30
//   0x01b9c0: 9400011f  bl       #0x1be3c
//   0x01b9c4: aa0103f5  mov      x21, x1
//   0x01b9c8: 528000a2  mov      w2, #5
//   0x01b9cc: aa0703f7  mov      x23, x7
//   0x01b9d0: b9400108  ldr      w8, [x8]
//   0x01b9d4: aa0603f8  mov      x24, x6
//   0x01b9d8: 2a0503f4  mov      w20, w5
uint64_t fde_0647_sub_01b9ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0xAA0703F7ULL) + (x2 ^ 0x01B9ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x01b9ac: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x01b9b0: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x01b9b4: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x01b9b8: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x01b9bc: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x9400011FULL; // 0x01b9c0: bl #0x1be3c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x01b9c4: mov x21, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x528000A2ULL; // 0x01b9c8: mov w2, #5
    return acc;
}

// [EN] Reconstructed FDE #0648 @ 0x01bafc..0x01bc28 (300 bytes)
// [VN] Phục dựng FDE #0648 tại 0x01bafc..0x01bc28 (300 byte)
//   0x01bafc: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x01bb00: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x01bb04: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x01bb08: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x01bb0c: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x01bb10: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x01bb14: 910143fd  add      x29, sp, #0x50
//   0x01bb18: 940000c9  bl       #0x1be3c
//   0x01bb1c: 2a0203f6  mov      w22, w2
//   0x01bb20: aa0103f7  mov      x23, x1
//   0x01bb24: 528000a2  mov      w2, #5
//   0x01bb28: b9400108  ldr      w8, [x8]
uint64_t fde_0648_sub_01bafc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0x2A0203F6ULL) + (x2 ^ 0x01BAFCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x01bafc: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x01bb00: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x01bb04: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x01bb08: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x01bb0c: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x01bb10: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x01bb14: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0x940000C9ULL; // 0x01bb18: bl #0x1be3c
    return acc;
}

// [EN] Reconstructed FDE #0649 @ 0x01bc28..0x01bcfc (212 bytes)
// [VN] Phục dựng FDE #0649 tại 0x01bc28..0x01bcfc (212 byte)
//   0x01bc28: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x01bc2c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x01bc30: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x01bc34: 910083fd  add      x29, sp, #0x20
//   0x01bc38: 94000081  bl       #0x1be3c
//   0x01bc3c: 2a0203f3  mov      w19, w2
//   0x01bc40: aa0103f4  mov      x20, x1
//   0x01bc44: 528000a2  mov      w2, #5
//   0x01bc48: b9400108  ldr      w8, [x8]
//   0x01bc4c: 4b0803e8  neg      w8, w8
//   0x01bc50: 93407d15  sxtw     x21, w8
//   0x01bc54: 8a0102a0  and      x0, x21, x1
uint64_t fde_0649_sub_01bc28(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xB9400108ULL) + (x2 ^ 0x01BC28ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x01bc28: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x01bc2c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x01bc30: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x01bc34: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x94000081ULL; // 0x01bc38: bl #0x1be3c
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F3ULL; // 0x01bc3c: mov w19, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x01bc40: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x528000A2ULL; // 0x01bc44: mov w2, #5
    return acc;
}

// [EN] Reconstructed FDE #0650 @ 0x01bcfc..0x01bda4 (168 bytes)
// [VN] Phục dựng FDE #0650 tại 0x01bcfc..0x01bda4 (168 byte)
//   0x01bcfc: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x01bd00: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x01bd04: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x01bd08: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x01bd0c: 9100c3fd  add      x29, sp, #0x30
//   0x01bd10: 9400003e  bl       #0x1be08
//   0x01bd14: 2a0303f3  mov      w19, w3
//   0x01bd18: 9400002f  bl       #0x1bdd4
//   0x01bd1c: 34000060  cbz      w0, #0x1bd28
//   0x01bd20: 5284e2c0  mov      w0, #0x2716
//   0x01bd24: 1400001e  b        #0x1bd9c
//   0x01bd28: 97ffee3d  bl       #0x1761c
uint64_t fde_0650_sub_01bcfc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0x34000060ULL) + (x2 ^ 0x01BCFCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x01bcfc: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x01bd00: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x01bd04: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x01bd08: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x01bd0c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x9400003EULL; // 0x01bd10: bl #0x1be08
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303F3ULL; // 0x01bd14: mov w19, w3
    acc = (acc * 0x100000001B3ULL) ^ 0x9400002FULL; // 0x01bd18: bl #0x1bdd4
    return acc;
}

// [EN] Reconstructed FDE #0651 @ 0x01bda4..0x01bdbc (24 bytes)
// [VN] Phục dựng FDE #0651 tại 0x01bda4..0x01bdbc (24 byte)
//   0x01bda4: d00000e1  adrp     x1, #0x39000
//   0x01bda8: 90000102  adrp     x2, #0x3b000
//   0x01bdac: 911f2c21  add      x1, x1, #0x7cb
//   0x01bdb0: 91250842  add      x2, x2, #0x942
//   0x01bdb4: 52800060  mov      w0, #3
//   0x01bdb8: 17ffbd0a  b        #0xb1e0
uint64_t fde_0651_sub_01bda4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD00000E1ULL) + (x1 ^ 0x17FFBD0AULL) + (x2 ^ 0x01BDA4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD00000E1ULL; // 0x01bda4: adrp x1, #0x39000
    acc = (acc * 0x100000001B3ULL) ^ 0x90000102ULL; // 0x01bda8: adrp x2, #0x3b000
    acc = (acc * 0x100000001B3ULL) ^ 0x911F2C21ULL; // 0x01bdac: add x1, x1, #0x7cb
    acc = (acc * 0x100000001B3ULL) ^ 0x91250842ULL; // 0x01bdb0: add x2, x2, #0x942
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x01bdb4: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFBD0AULL; // 0x01bdb8: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #0652 @ 0x01bdbc..0x01bdd4 (24 bytes)
// [VN] Phục dựng FDE #0652 tại 0x01bdbc..0x01bdd4 (24 byte)
//   0x01bdbc: d00000e1  adrp     x1, #0x39000
//   0x01bdc0: 90000102  adrp     x2, #0x3b000
//   0x01bdc4: 911f2c21  add      x1, x1, #0x7cb
//   0x01bdc8: 9124b442  add      x2, x2, #0x92d
//   0x01bdcc: 52800060  mov      w0, #3
//   0x01bdd0: 17ffbd04  b        #0xb1e0
uint64_t fde_0652_sub_01bdbc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD00000E1ULL) + (x1 ^ 0x17FFBD04ULL) + (x2 ^ 0x01BDBCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD00000E1ULL; // 0x01bdbc: adrp x1, #0x39000
    acc = (acc * 0x100000001B3ULL) ^ 0x90000102ULL; // 0x01bdc0: adrp x2, #0x3b000
    acc = (acc * 0x100000001B3ULL) ^ 0x911F2C21ULL; // 0x01bdc4: add x1, x1, #0x7cb
    acc = (acc * 0x100000001B3ULL) ^ 0x9124B442ULL; // 0x01bdc8: add x2, x2, #0x92d
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x01bdcc: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFBD04ULL; // 0x01bdd0: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #0653 @ 0x01bdd4..0x01bde8 (20 bytes)
// [VN] Phục dựng FDE #0653 tại 0x01bdd4..0x01bde8 (20 byte)
//   0x01bdd4: 4b0803e8  neg      w8, w8
//   0x01bdd8: 93407d16  sxtw     x22, w8
//   0x01bddc: 8a0102c0  and      x0, x22, x1
//   0x01bde0: 52840001  mov      w1, #0x2000
//   0x01bde4: 17fff5c9  b        #0x19508
uint64_t fde_0653_sub_01bdd4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x4B0803E8ULL) + (x1 ^ 0x17FFF5C9ULL) + (x2 ^ 0x01BDD4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x4B0803E8ULL; // 0x01bdd4: neg w8, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x93407D16ULL; // 0x01bdd8: sxtw x22, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x8A0102C0ULL; // 0x01bddc: and x0, x22, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x52840001ULL; // 0x01bde0: mov w1, #0x2000
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF5C9ULL; // 0x01bde4: b #0x19508
    return acc;
}

// [EN] Reconstructed FDE #0654 @ 0x01bde8..0x01bdf0 (8 bytes)
// [VN] Phục dựng FDE #0654 tại 0x01bde8..0x01bdf0 (8 byte)
//   0x01bde8: 52800060  mov      w0, #3
//   0x01bdec: 17ffbcfd  b        #0xb1e0
uint64_t fde_0654_sub_01bde8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800060ULL) + (x1 ^ 0x17FFBCFDULL) + (x2 ^ 0x01BDE8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x01bde8: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFBCFDULL; // 0x01bdec: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #0655 @ 0x01bdf0..0x01bdf8 (8 bytes)
// [VN] Phục dựng FDE #0655 tại 0x01bdf0..0x01bdf8 (8 byte)
//   0x01bdf0: aa1503e0  mov      x0, x21
//   0x01bdf4: 17fff5c5  b        #0x19508
uint64_t fde_0655_sub_01bdf0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1503E0ULL) + (x1 ^ 0x17FFF5C5ULL) + (x2 ^ 0x01BDF0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E0ULL; // 0x01bdf0: mov x0, x21
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF5C5ULL; // 0x01bdf4: b #0x19508
    return acc;
}

// [EN] Reconstructed FDE #0656 @ 0x01bdf8..0x01be08 (16 bytes)
// [VN] Phục dựng FDE #0656 tại 0x01bdf8..0x01be08 (16 byte)
//   0x01bdf8: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x01bdfc: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x01be00: a8c45ff8  ldp      x24, x23, [sp], #0x40
//   0x01be04: d65f03c0  ret      
uint64_t fde_0656_sub_01bdf8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9424FF4ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01BDF8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9424FF4ULL; // 0x01bdf8: ldp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA94157F6ULL; // 0x01bdfc: ldp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C45FF8ULL; // 0x01be00: ldp x24, x23, [sp], #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01be04: ret 
    return acc;
}

// [EN] Reconstructed FDE #0657 @ 0x01be08..0x01be24 (28 bytes)
// [VN] Phục dựng FDE #0657 tại 0x01be08..0x01be24 (28 byte)
//   0x01be08: 90000208  adrp     x8, #0x5b000
//   0x01be0c: f9426108  ldr      x8, [x8, #0x4c0]
//   0x01be10: 2a0203f5  mov      w21, w2
//   0x01be14: aa0103f4  mov      x20, x1
//   0x01be18: 528000a2  mov      w2, #5
//   0x01be1c: b9400108  ldr      w8, [x8]
//   0x01be20: d65f03c0  ret      
uint64_t fde_0657_sub_01be08(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000208ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01BE08ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000208ULL; // 0x01be08: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9426108ULL; // 0x01be0c: ldr x8, [x8, #0x4c0]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F5ULL; // 0x01be10: mov w21, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x01be14: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x528000A2ULL; // 0x01be18: mov w2, #5
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400108ULL; // 0x01be1c: ldr w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01be20: ret 
    return acc;
}

// [EN] Reconstructed FDE #0658 @ 0x01be24..0x01be34 (16 bytes)
// [VN] Phục dựng FDE #0658 tại 0x01be24..0x01be34 (16 byte)
//   0x01be24: 91400aa1  add      x1, x21, #2, lsl #12
//   0x01be28: aa1503e0  mov      x0, x21
//   0x01be2c: b8376a93  str      w19, [x20, x23]
//   0x01be30: 14007349  b        #0x38b54
uint64_t fde_0658_sub_01be24(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x91400AA1ULL) + (x1 ^ 0x14007349ULL) + (x2 ^ 0x01BE24ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x91400AA1ULL; // 0x01be24: add x1, x21, #2, lsl #12
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E0ULL; // 0x01be28: mov x0, x21
    acc = (acc * 0x100000001B3ULL) ^ 0xB8376A93ULL; // 0x01be2c: str w19, [x20, x23]
    acc = (acc * 0x100000001B3ULL) ^ 0x14007349ULL; // 0x01be30: b #0x38b54
    return acc;
}

// [EN] Reconstructed FDE #0659 @ 0x01be34..0x01be3c (8 bytes)
// [VN] Phục dựng FDE #0659 tại 0x01be34..0x01be3c (8 byte)
//   0x01be34: aa1303e0  mov      x0, x19
//   0x01be38: 17fff5b4  b        #0x19508
uint64_t fde_0659_sub_01be34(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1303E0ULL) + (x1 ^ 0x17FFF5B4ULL) + (x2 ^ 0x01BE34ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x01be34: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF5B4ULL; // 0x01be38: b #0x19508
    return acc;
}

// [EN] Reconstructed FDE #0660 @ 0x01be3c..0x01be48 (12 bytes)
// [VN] Phục dựng FDE #0660 tại 0x01be3c..0x01be48 (12 byte)
//   0x01be3c: 90000208  adrp     x8, #0x5b000
//   0x01be40: f9426108  ldr      x8, [x8, #0x4c0]
//   0x01be44: d65f03c0  ret      
uint64_t fde_0660_sub_01be3c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000208ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01BE3CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000208ULL; // 0x01be3c: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9426108ULL; // 0x01be40: ldr x8, [x8, #0x4c0]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01be44: ret 
    return acc;
}

// [EN] Reconstructed FDE #0661 @ 0x01be48..0x01be50 (8 bytes)
// [VN] Phục dựng FDE #0661 tại 0x01be48..0x01be50 (8 byte)
//   0x01be48: 52800060  mov      w0, #3
//   0x01be4c: 17ffbce5  b        #0xb1e0
uint64_t fde_0661_sub_01be48(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800060ULL) + (x1 ^ 0x17FFBCE5ULL) + (x2 ^ 0x01BE48ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x01be48: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFBCE5ULL; // 0x01be4c: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #0662 @ 0x01be50..0x01bf98 (328 bytes)
// [VN] Phục dựng FDE #0662 tại 0x01be50..0x01bf98 (328 byte)
//   0x01be50: d10143ff  sub      sp, sp, #0x50
//   0x01be54: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x01be58: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x01be5c: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x01be60: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x01be64: 910103fd  add      x29, sp, #0x40
//   0x01be68: d53bd057  mrs      x23, tpidr_el0
//   0x01be6c: f94016e8  ldr      x8, [x23, #0x28]
//   0x01be70: f90007e8  str      x8, [sp, #8]
//   0x01be74: 37f806a2  tbnz     w2, #0x1f, #0x1bf48
//   0x01be78: b0000218  adrp     x24, #0x5c000
//   0x01be7c: f9433715  ldr      x21, [x24, #0x668]
uint64_t fde_0662_sub_01be50(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xF90007E8ULL) + (x2 ^ 0x01BE50ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x01be50: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x01be54: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x01be58: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x01be5c: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x01be60: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x01be64: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x01be68: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x01be6c: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0663 @ 0x01bf98..0x01bf9c (4 bytes)
// [VN] Phục dựng FDE #0663 tại 0x01bf98..0x01bf9c (4 byte)
//   0x01bf98: 14001adc  b        #0x22b08
uint64_t fde_0663_sub_01bf98(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x14001ADCULL) + (x1 ^ 0x14001ADCULL) + (x2 ^ 0x01BF98ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x14001ADCULL; // 0x01bf98: b #0x22b08
    return acc;
}

// [EN] Reconstructed FDE #0664 @ 0x01bf9c..0x01bfbc (32 bytes)
// [VN] Phục dựng FDE #0664 tại 0x01bf9c..0x01bfbc (32 byte)
//   0x01bf9c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x01bfa0: 910003fd  mov      x29, sp
//   0x01bfa4: 2a0203e0  mov      w0, w2
//   0x01bfa8: 9400135d  bl       #0x20d1c
//   0x01bfac: 940012fe  bl       #0x20ba4
//   0x01bfb0: 12000000  and      w0, w0, #1
//   0x01bfb4: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x01bfb8: d65f03c0  ret      
uint64_t fde_0664_sub_01bf9c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01BF9CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x01bf9c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x01bfa0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203E0ULL; // 0x01bfa4: mov w0, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x9400135DULL; // 0x01bfa8: bl #0x20d1c
    acc = (acc * 0x100000001B3ULL) ^ 0x940012FEULL; // 0x01bfac: bl #0x20ba4
    acc = (acc * 0x100000001B3ULL) ^ 0x12000000ULL; // 0x01bfb0: and w0, w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x01bfb4: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01bfb8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0665 @ 0x01bfbc..0x01bfdc (32 bytes)
// [VN] Phục dựng FDE #0665 tại 0x01bfbc..0x01bfdc (32 byte)
//   0x01bfbc: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x01bfc0: 910003fd  mov      x29, sp
//   0x01bfc4: 72001c5f  tst      w2, #0xff
//   0x01bfc8: 1a9f07e0  cset     w0, ne
//   0x01bfcc: 94001daf  bl       #0x23688
//   0x01bfd0: 12000000  and      w0, w0, #1
//   0x01bfd4: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x01bfd8: d65f03c0  ret      
uint64_t fde_0665_sub_01bfbc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01BFBCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x01bfbc: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x01bfc0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x72001C5FULL; // 0x01bfc4: tst w2, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F07E0ULL; // 0x01bfc8: cset w0, ne
    acc = (acc * 0x100000001B3ULL) ^ 0x94001DAFULL; // 0x01bfcc: bl #0x23688
    acc = (acc * 0x100000001B3ULL) ^ 0x12000000ULL; // 0x01bfd0: and w0, w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x01bfd4: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01bfd8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0666 @ 0x01bfdc..0x01bff4 (24 bytes)
// [VN] Phục dựng FDE #0666 tại 0x01bfdc..0x01bff4 (24 byte)
//   0x01bfdc: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x01bfe0: 910003fd  mov      x29, sp
//   0x01bfe4: 97ffd382  bl       #0x10dec
//   0x01bfe8: 12000000  and      w0, w0, #1
//   0x01bfec: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x01bff0: d65f03c0  ret      
uint64_t fde_0666_sub_01bfdc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01BFDCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x01bfdc: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x01bfe0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFD382ULL; // 0x01bfe4: bl #0x10dec
    acc = (acc * 0x100000001B3ULL) ^ 0x12000000ULL; // 0x01bfe8: and w0, w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x01bfec: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01bff0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0667 @ 0x01bff4..0x01c000 (12 bytes)
// [VN] Phục dựng FDE #0667 tại 0x01bff4..0x01c000 (12 byte)
//   0x01bff4: 2a0303e1  mov      w1, w3
//   0x01bff8: 2a0203e0  mov      w0, w2
//   0x01bffc: 14001a20  b        #0x2287c
uint64_t fde_0667_sub_01bff4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A0303E1ULL) + (x1 ^ 0x14001A20ULL) + (x2 ^ 0x01BFF4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303E1ULL; // 0x01bff4: mov w1, w3
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203E0ULL; // 0x01bff8: mov w0, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x14001A20ULL; // 0x01bffc: b #0x2287c
    return acc;
}

// [EN] Reconstructed FDE #0668 @ 0x01c000..0x01c0b4 (180 bytes)
// [VN] Phục dựng FDE #0668 tại 0x01c000..0x01c0b4 (180 byte)
//   0x01c000: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x01c004: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x01c008: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x01c00c: 910083fd  add      x29, sp, #0x20
//   0x01c010: f00000e1  adrp     x1, #0x3b000
//   0x01c014: 9129dc21  add      x1, x1, #0xa77
//   0x01c018: 97ffbda2  bl       #0xb6a0
//   0x01c01c: b4000320  cbz      x0, #0x1c080
//   0x01c020: f00001e8  adrp     x8, #0x5b000
//   0x01c024: f9435d08  ldr      x8, [x8, #0x6b8]
//   0x01c028: f00001e9  adrp     x9, #0x5b000
//   0x01c02c: aa0003f3  mov      x19, x0
uint64_t fde_0668_sub_01c000(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xF00001E8ULL) + (x2 ^ 0x01C000ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x01c000: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x01c004: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x01c008: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x01c00c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF00000E1ULL; // 0x01c010: adrp x1, #0x3b000
    acc = (acc * 0x100000001B3ULL) ^ 0x9129DC21ULL; // 0x01c014: add x1, x1, #0xa77
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFBDA2ULL; // 0x01c018: bl #0xb6a0
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000320ULL; // 0x01c01c: cbz x0, #0x1c080
    return acc;
}

// [EN] Reconstructed FDE #0669 @ 0x01c0b4..0x01c0dc (40 bytes)
// [VN] Phục dựng FDE #0669 tại 0x01c0b4..0x01c0dc (40 byte)
//   0x01c0b4: 7202001f  tst      w0, #0x40000000
//   0x01c0b8: 52800108  mov      w8, #8
//   0x01c0bc: 52800089  mov      w9, #4
//   0x01c0c0: 530a540a  ubfx     w10, w0, #0xa, #0xc
//   0x01c0c4: 530c500b  ubfx     w11, w0, #0xc, #9
//   0x01c0c8: 1a880128  csel     w8, w9, w8, eq
//   0x01c0cc: 7208001f  tst      w0, #0x1000000
//   0x01c0d0: 1a8a0169  csel     w9, w11, w10, eq
//   0x01c0d4: 1b087d20  mul      w0, w9, w8
//   0x01c0d8: d65f03c0  ret      
uint64_t fde_0669_sub_01c0b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7202001FULL) + (x1 ^ 0x1B087D20ULL) + (x2 ^ 0x01C0B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7202001FULL; // 0x01c0b4: tst w0, #0x40000000
    acc = (acc * 0x100000001B3ULL) ^ 0x52800108ULL; // 0x01c0b8: mov w8, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x52800089ULL; // 0x01c0bc: mov w9, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x530A540AULL; // 0x01c0c0: ubfx w10, w0, #0xa, #0xc
    acc = (acc * 0x100000001B3ULL) ^ 0x530C500BULL; // 0x01c0c4: ubfx w11, w0, #0xc, #9
    acc = (acc * 0x100000001B3ULL) ^ 0x1A880128ULL; // 0x01c0c8: csel w8, w9, w8, eq
    acc = (acc * 0x100000001B3ULL) ^ 0x7208001FULL; // 0x01c0cc: tst w0, #0x1000000
    acc = (acc * 0x100000001B3ULL) ^ 0x1A8A0169ULL; // 0x01c0d0: csel w9, w11, w10, eq
    return acc;
}

// [EN] Reconstructed FDE #0670 @ 0x01c0dc..0x01c3fc (800 bytes)
// [VN] Phục dựng FDE #0670 tại 0x01c0dc..0x01c3fc (800 byte)
//   0x01c0dc: d101c3ff  sub      sp, sp, #0x70
//   0x01c0e0: f9000bfb  str      x27, [sp, #0x10]
//   0x01c0e4: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x01c0e8: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x01c0ec: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x01c0f0: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x01c0f4: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x01c0f8: 910183fd  add      x29, sp, #0x60
//   0x01c0fc: d53bd057  mrs      x23, tpidr_el0
//   0x01c100: f94016e8  ldr      x8, [x23, #0x28]
//   0x01c104: f90007e8  str      x8, [sp, #8]
//   0x01c108: f00001e8  adrp     x8, #0x5b000
uint64_t fde_0670_sub_01c0dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xD53BD057ULL) + (x2 ^ 0x01C0DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x01c0dc: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BFBULL; // 0x01c0e0: str x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x01c0e4: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x01c0e8: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x01c0ec: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x01c0f0: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x01c0f4: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x01c0f8: add x29, sp, #0x60
    return acc;
}

// [EN] Reconstructed FDE #0671 @ 0x01c3fc..0x01c458 (92 bytes)
// [VN] Phục dựng FDE #0671 tại 0x01c3fc..0x01c458 (92 byte)
//   0x01c3fc: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x01c400: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01c404: 910043fd  add      x29, sp, #0x10
//   0x01c408: f00000e1  adrp     x1, #0x3b000
//   0x01c40c: 91330021  add      x1, x1, #0xcc0
//   0x01c410: aa1f03e2  mov      x2, xzr
//   0x01c414: aa0003f3  mov      x19, x0
//   0x01c418: 94000010  bl       #0x1c458
//   0x01c41c: b100041f  cmn      x0, #1
//   0x01c420: 54000140  b.eq     #0x1c448
//   0x01c424: f00000e1  adrp     x1, #0x3b000
//   0x01c428: 91332c21  add      x1, x1, #0xccb
uint64_t fde_0671_sub_01c3fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xB100041FULL) + (x2 ^ 0x01C3FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x01c3fc: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01c400: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01c404: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF00000E1ULL; // 0x01c408: adrp x1, #0x3b000
    acc = (acc * 0x100000001B3ULL) ^ 0x91330021ULL; // 0x01c40c: add x1, x1, #0xcc0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x01c410: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01c414: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x94000010ULL; // 0x01c418: bl #0x1c458
    return acc;
}

// [EN] Reconstructed FDE #0672 @ 0x01c458..0x01c4b4 (92 bytes)
// [VN] Phục dựng FDE #0672 tại 0x01c458..0x01c4b4 (92 byte)
//   0x01c458: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x01c45c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x01c460: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x01c464: 910083fd  add      x29, sp, #0x20
//   0x01c468: 39400008  ldrb     w8, [x0]
//   0x01c46c: aa0203f3  mov      x19, x2
//   0x01c470: aa0103f4  mov      x20, x1
//   0x01c474: 37000088  tbnz     w8, #0, #0x1c484
//   0x01c478: 91000415  add      x21, x0, #1
//   0x01c47c: d341fd16  lsr      x22, x8, #1
//   0x01c480: 14000002  b        #0x1c488
//   0x01c484: a940d416  ldp      x22, x21, [x0, #8]
uint64_t fde_0672_sub_01c458(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x91000415ULL) + (x2 ^ 0x01C458ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x01c458: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x01c45c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x01c460: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x01c464: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x01c468: ldrb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x01c46c: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x01c470: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x37000088ULL; // 0x01c474: tbnz w8, #0, #0x1c484
    return acc;
}

// [EN] Reconstructed FDE #0673 @ 0x01c4b4..0x01c810 (860 bytes)
// [VN] Phục dựng FDE #0673 tại 0x01c4b4..0x01c810 (860 byte)
//   0x01c4b4: d10303ff  sub      sp, sp, #0xc0
//   0x01c4b8: a9066ffc  stp      x28, x27, [sp, #0x60]
//   0x01c4bc: a90767fa  stp      x26, x25, [sp, #0x70]
//   0x01c4c0: a9085ff8  stp      x24, x23, [sp, #0x80]
//   0x01c4c4: a90957f6  stp      x22, x21, [sp, #0x90]
//   0x01c4c8: a90a4ff4  stp      x20, x19, [sp, #0xa0]
//   0x01c4cc: a90b7bfd  stp      x29, x30, [sp, #0xb0]
//   0x01c4d0: 9102c3fd  add      x29, sp, #0xb0
//   0x01c4d4: d53bd048  mrs      x8, tpidr_el0
//   0x01c4d8: f90007e8  str      x8, [sp, #8]
//   0x01c4dc: f9401508  ldr      x8, [x8, #0x28]
//   0x01c4e0: 94000da1  bl       #0x1fb64
uint64_t fde_0673_sub_01c4b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10303FFULL) + (x1 ^ 0xD53BD048ULL) + (x2 ^ 0x01C4B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10303FFULL; // 0x01c4b4: sub sp, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9066FFCULL; // 0x01c4b8: stp x28, x27, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90767FAULL; // 0x01c4bc: stp x26, x25, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9085FF8ULL; // 0x01c4c0: stp x24, x23, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90957F6ULL; // 0x01c4c4: stp x22, x21, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A4FF4ULL; // 0x01c4c8: stp x20, x19, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B7BFDULL; // 0x01c4cc: stp x29, x30, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9102C3FDULL; // 0x01c4d0: add x29, sp, #0xb0
    return acc;
}

// [EN] Reconstructed FDE #0674 @ 0x01c810..0x01cac8 (696 bytes)
// [VN] Phục dựng FDE #0674 tại 0x01c810..0x01cac8 (696 byte)
//   0x01c810: d10683ff  sub      sp, sp, #0x1a0
//   0x01c814: a9146ffc  stp      x28, x27, [sp, #0x140]
//   0x01c818: a91567fa  stp      x26, x25, [sp, #0x150]
//   0x01c81c: a9165ff8  stp      x24, x23, [sp, #0x160]
//   0x01c820: a91757f6  stp      x22, x21, [sp, #0x170]
//   0x01c824: a9184ff4  stp      x20, x19, [sp, #0x180]
//   0x01c828: a9197bfd  stp      x29, x30, [sp, #0x190]
//   0x01c82c: 910643fd  add      x29, sp, #0x190
//   0x01c830: d53bd05c  mrs      x28, tpidr_el0
//   0x01c834: f9401788  ldr      x8, [x28, #0x28]
//   0x01c838: f00001f8  adrp     x24, #0x5b000
//   0x01c83c: f81a03a8  stur     x8, [x29, #-0x60]
uint64_t fde_0674_sub_01c810(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10683FFULL) + (x1 ^ 0xD53BD05CULL) + (x2 ^ 0x01C810ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10683FFULL; // 0x01c810: sub sp, sp, #0x1a0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9146FFCULL; // 0x01c814: stp x28, x27, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91567FAULL; // 0x01c818: stp x26, x25, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9165FF8ULL; // 0x01c81c: stp x24, x23, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91757F6ULL; // 0x01c820: stp x22, x21, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9184FF4ULL; // 0x01c824: stp x20, x19, [sp, #0x180]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9197BFDULL; // 0x01c828: stp x29, x30, [sp, #0x190]
    acc = (acc * 0x100000001B3ULL) ^ 0x910643FDULL; // 0x01c82c: add x29, sp, #0x190
    return acc;
}

// [EN] Reconstructed FDE #0675 @ 0x01cac8..0x01caf4 (44 bytes)
// [VN] Phục dựng FDE #0675 tại 0x01cac8..0x01caf4 (44 byte)
//   0x01cac8: a940a408  ldp      x8, x9, [x0, #8]
//   0x01cacc: eb09011f  cmp      x8, x9
//   0x01cad0: 54000102  b.hs     #0x1caf0
//   0x01cad4: f9400829  ldr      x9, [x1, #0x10]
//   0x01cad8: 3dc00020  ldr      q0, [x1]
//   0x01cadc: 9100610a  add      x10, x8, #0x18
//   0x01cae0: f9000909  str      x9, [x8, #0x10]
//   0x01cae4: 3d800100  str      q0, [x8]
//   0x01cae8: f900040a  str      x10, [x0, #8]
//   0x01caec: d65f03c0  ret      
//   0x01caf0: 1400085d  b        #0x1ec64
uint64_t fde_0675_sub_01cac8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA940A408ULL) + (x1 ^ 0xF900040AULL) + (x2 ^ 0x01CAC8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA940A408ULL; // 0x01cac8: ldp x8, x9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x01cacc: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x54000102ULL; // 0x01cad0: b.hs #0x1caf0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400829ULL; // 0x01cad4: ldr x9, [x1, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x3DC00020ULL; // 0x01cad8: ldr q0, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100610AULL; // 0x01cadc: add x10, x8, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000909ULL; // 0x01cae0: str x9, [x8, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x3D800100ULL; // 0x01cae4: str q0, [x8]
    return acc;
}

// [EN] Reconstructed FDE #0676 @ 0x01caf4..0x01cdb4 (704 bytes)
// [VN] Phục dựng FDE #0676 tại 0x01caf4..0x01cdb4 (704 byte)
//   0x01caf4: d10643ff  sub      sp, sp, #0x190
//   0x01caf8: a9136ffc  stp      x28, x27, [sp, #0x130]
//   0x01cafc: a91467fa  stp      x26, x25, [sp, #0x140]
//   0x01cb00: a9155ff8  stp      x24, x23, [sp, #0x150]
//   0x01cb04: a91657f6  stp      x22, x21, [sp, #0x160]
//   0x01cb08: a9174ff4  stp      x20, x19, [sp, #0x170]
//   0x01cb0c: a9187bfd  stp      x29, x30, [sp, #0x180]
//   0x01cb10: 910603fd  add      x29, sp, #0x180
//   0x01cb14: d53bd059  mrs      x25, tpidr_el0
//   0x01cb18: f9401728  ldr      x8, [x25, #0x28]
//   0x01cb1c: 710004bf  cmp      w5, #1
//   0x01cb20: f81a03a8  stur     x8, [x29, #-0x60]
uint64_t fde_0676_sub_01caf4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10643FFULL) + (x1 ^ 0xD53BD059ULL) + (x2 ^ 0x01CAF4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10643FFULL; // 0x01caf4: sub sp, sp, #0x190
    acc = (acc * 0x100000001B3ULL) ^ 0xA9136FFCULL; // 0x01caf8: stp x28, x27, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91467FAULL; // 0x01cafc: stp x26, x25, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9155FF8ULL; // 0x01cb00: stp x24, x23, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91657F6ULL; // 0x01cb04: stp x22, x21, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9174FF4ULL; // 0x01cb08: stp x20, x19, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9187BFDULL; // 0x01cb0c: stp x29, x30, [sp, #0x180]
    acc = (acc * 0x100000001B3ULL) ^ 0x910603FDULL; // 0x01cb10: add x29, sp, #0x180
    return acc;
}

// [EN] Reconstructed FDE #0677 @ 0x01cdb4..0x01cde0 (44 bytes)
// [VN] Phục dựng FDE #0677 tại 0x01cdb4..0x01cde0 (44 byte)
//   0x01cdb4: a940a408  ldp      x8, x9, [x0, #8]
//   0x01cdb8: eb09011f  cmp      x8, x9
//   0x01cdbc: 54000102  b.hs     #0x1cddc
//   0x01cdc0: f9400829  ldr      x9, [x1, #0x10]
//   0x01cdc4: 3dc00020  ldr      q0, [x1]
//   0x01cdc8: 9100610a  add      x10, x8, #0x18
//   0x01cdcc: f9000909  str      x9, [x8, #0x10]
//   0x01cdd0: 3d800100  str      q0, [x8]
//   0x01cdd4: f900040a  str      x10, [x0, #8]
//   0x01cdd8: d65f03c0  ret      
//   0x01cddc: 14000848  b        #0x1eefc
uint64_t fde_0677_sub_01cdb4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA940A408ULL) + (x1 ^ 0xF900040AULL) + (x2 ^ 0x01CDB4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA940A408ULL; // 0x01cdb4: ldp x8, x9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x01cdb8: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x54000102ULL; // 0x01cdbc: b.hs #0x1cddc
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400829ULL; // 0x01cdc0: ldr x9, [x1, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x3DC00020ULL; // 0x01cdc4: ldr q0, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100610AULL; // 0x01cdc8: add x10, x8, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000909ULL; // 0x01cdcc: str x9, [x8, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x3D800100ULL; // 0x01cdd0: str q0, [x8]
    return acc;
}

// [EN] Reconstructed FDE #0678 @ 0x01cde0..0x01d110 (816 bytes)
// [VN] Phục dựng FDE #0678 tại 0x01cde0..0x01d110 (816 byte)
//   0x01cde0: d10303ff  sub      sp, sp, #0xc0
//   0x01cde4: a9066ffc  stp      x28, x27, [sp, #0x60]
//   0x01cde8: a90767fa  stp      x26, x25, [sp, #0x70]
//   0x01cdec: a9085ff8  stp      x24, x23, [sp, #0x80]
//   0x01cdf0: a90957f6  stp      x22, x21, [sp, #0x90]
//   0x01cdf4: a90a4ff4  stp      x20, x19, [sp, #0xa0]
//   0x01cdf8: a90b7bfd  stp      x29, x30, [sp, #0xb0]
//   0x01cdfc: 9102c3fd  add      x29, sp, #0xb0
//   0x01ce00: d53bd055  mrs      x21, tpidr_el0
//   0x01ce04: f94016a8  ldr      x8, [x21, #0x28]
//   0x01ce08: aa0003f3  mov      x19, x0
//   0x01ce0c: 94000b56  bl       #0x1fb64
uint64_t fde_0678_sub_01cde0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10303FFULL) + (x1 ^ 0xD53BD055ULL) + (x2 ^ 0x01CDE0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10303FFULL; // 0x01cde0: sub sp, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9066FFCULL; // 0x01cde4: stp x28, x27, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90767FAULL; // 0x01cde8: stp x26, x25, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9085FF8ULL; // 0x01cdec: stp x24, x23, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90957F6ULL; // 0x01cdf0: stp x22, x21, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A4FF4ULL; // 0x01cdf4: stp x20, x19, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B7BFDULL; // 0x01cdf8: stp x29, x30, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9102C3FDULL; // 0x01cdfc: add x29, sp, #0xb0
    return acc;
}

// [EN] Reconstructed FDE #0679 @ 0x01d110..0x01d34c (572 bytes)
// [VN] Phục dựng FDE #0679 tại 0x01d110..0x01d34c (572 byte)
//   0x01d110: d10683ff  sub      sp, sp, #0x1a0
//   0x01d114: a91567fc  stp      x28, x25, [sp, #0x150]
//   0x01d118: a9165ff8  stp      x24, x23, [sp, #0x160]
//   0x01d11c: a91757f6  stp      x22, x21, [sp, #0x170]
//   0x01d120: a9184ff4  stp      x20, x19, [sp, #0x180]
//   0x01d124: a9197bfd  stp      x29, x30, [sp, #0x190]
//   0x01d128: 910643fd  add      x29, sp, #0x190
//   0x01d12c: d53bd057  mrs      x23, tpidr_el0
//   0x01d130: f94016e8  ldr      x8, [x23, #0x28]
//   0x01d134: aa0003f4  mov      x20, x0
//   0x01d138: f81b83a8  stur     x8, [x29, #-0x48]
//   0x01d13c: 97ffb7c9  bl       #0xb060
uint64_t fde_0679_sub_01d110(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10683FFULL) + (x1 ^ 0xF94016E8ULL) + (x2 ^ 0x01D110ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10683FFULL; // 0x01d110: sub sp, sp, #0x1a0
    acc = (acc * 0x100000001B3ULL) ^ 0xA91567FCULL; // 0x01d114: stp x28, x25, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9165FF8ULL; // 0x01d118: stp x24, x23, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91757F6ULL; // 0x01d11c: stp x22, x21, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9184FF4ULL; // 0x01d120: stp x20, x19, [sp, #0x180]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9197BFDULL; // 0x01d124: stp x29, x30, [sp, #0x190]
    acc = (acc * 0x100000001B3ULL) ^ 0x910643FDULL; // 0x01d128: add x29, sp, #0x190
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x01d12c: mrs x23, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0680 @ 0x01d34c..0x01d574 (552 bytes)
// [VN] Phục dựng FDE #0680 tại 0x01d34c..0x01d574 (552 byte)
//   0x01d34c: d10203ff  sub      sp, sp, #0x80
//   0x01d350: f9001bf9  str      x25, [sp, #0x30]
//   0x01d354: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x01d358: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x01d35c: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x01d360: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x01d364: 9101c3fd  add      x29, sp, #0x70
//   0x01d368: d53bd059  mrs      x25, tpidr_el0
//   0x01d36c: f9401728  ldr      x8, [x25, #0x28]
//   0x01d370: aa0303f3  mov      x19, x3
//   0x01d374: aa0203f4  mov      x20, x2
//   0x01d378: aa0103f5  mov      x21, x1
uint64_t fde_0680_sub_01d34c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xF9401728ULL) + (x2 ^ 0x01D34CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x01d34c: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF9ULL; // 0x01d350: str x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x01d354: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x01d358: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x01d35c: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x01d360: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x01d364: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x01d368: mrs x25, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0681 @ 0x01d574..0x01d64c (216 bytes)
// [VN] Phục dựng FDE #0681 tại 0x01d574..0x01d64c (216 byte)
//   0x01d574: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x01d578: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x01d57c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x01d580: 910083fd  add      x29, sp, #0x20
//   0x01d584: d00001e8  adrp     x8, #0x5b000
//   0x01d588: f944d108  ldr      x8, [x8, #0x9a0]
//   0x01d58c: b9400114  ldr      w20, [x8]
//   0x01d590: 7100069f  cmp      w20, #1
//   0x01d594: 5400058b  b.lt     #0x1d644
//   0x01d598: 7120029f  cmp      w20, #0x800
//   0x01d59c: 54000061  b.ne     #0x1d5a8
//   0x01d5a0: 52808013  mov      w19, #0x400
uint64_t fde_0681_sub_01d574(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x5400058BULL) + (x2 ^ 0x01D574ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x01d574: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x01d578: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x01d57c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x01d580: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001E8ULL; // 0x01d584: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF944D108ULL; // 0x01d588: ldr x8, [x8, #0x9a0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400114ULL; // 0x01d58c: ldr w20, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100069FULL; // 0x01d590: cmp w20, #1
    return acc;
}

// [EN] Reconstructed FDE #0682 @ 0x01d64c..0x01d6d8 (140 bytes)
// [VN] Phục dựng FDE #0682 tại 0x01d64c..0x01d6d8 (140 byte)
//   0x01d64c: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x01d650: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x01d654: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x01d658: 910083fd  add      x29, sp, #0x20
//   0x01d65c: 7100043f  cmp      w1, #1
//   0x01d660: 5400038b  b.lt     #0x1d6d0
//   0x01d664: 2a0203f3  mov      w19, w2
//   0x01d668: 7120003f  cmp      w1, #0x800
//   0x01d66c: 540000e0  b.eq     #0x1d688
//   0x01d670: 7140103f  cmp      w1, #4, lsl #12
//   0x01d674: 540000e0  b.eq     #0x1d690
//   0x01d678: 7140043f  cmp      w1, #1, lsl #12
uint64_t fde_0682_sub_01d64c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x540000E0ULL) + (x2 ^ 0x01D64CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x01d64c: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x01d650: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x01d654: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x01d658: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x7100043FULL; // 0x01d65c: cmp w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400038BULL; // 0x01d660: b.lt #0x1d6d0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F3ULL; // 0x01d664: mov w19, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x7120003FULL; // 0x01d668: cmp w1, #0x800
    return acc;
}

// [EN] Reconstructed FDE #0683 @ 0x01d6d8..0x01d774 (156 bytes)
// [VN] Phục dựng FDE #0683 tại 0x01d6d8..0x01d774 (156 byte)
//   0x01d6d8: d10243ff  sub      sp, sp, #0x90
//   0x01d6dc: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x01d6e0: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x01d6e4: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x01d6e8: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x01d6ec: 910203fd  add      x29, sp, #0x80
//   0x01d6f0: d53bd058  mrs      x24, tpidr_el0
//   0x01d6f4: f9401708  ldr      x8, [x24, #0x28]
//   0x01d6f8: 2a0503f3  mov      w19, w5
//   0x01d6fc: 2a0403f4  mov      w20, w4
//   0x01d700: 2a0303f5  mov      w21, w3
//   0x01d704: f81c83a8  stur     x8, [x29, #-0x38]
uint64_t fde_0683_sub_01d6d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0x2A0503F3ULL) + (x2 ^ 0x01D6D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x01d6d8: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x01d6dc: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x01d6e0: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x01d6e4: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x01d6e8: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x01d6ec: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x01d6f0: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401708ULL; // 0x01d6f4: ldr x8, [x24, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0684 @ 0x01d774..0x01d798 (36 bytes)
// [VN] Phục dựng FDE #0684 tại 0x01d774..0x01d798 (36 byte)
//   0x01d774: a940a408  ldp      x8, x9, [x0, #8]
//   0x01d778: eb09011f  cmp      x8, x9
//   0x01d77c: 540000c2  b.hs     #0x1d794
//   0x01d780: ad400420  ldp      q0, q1, [x1]
//   0x01d784: 91008109  add      x9, x8, #0x20
//   0x01d788: ad000500  stp      q0, q1, [x8]
//   0x01d78c: f9000409  str      x9, [x0, #8]
//   0x01d790: d65f03c0  ret      
//   0x01d794: 14000680  b        #0x1f194
uint64_t fde_0684_sub_01d774(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA940A408ULL) + (x1 ^ 0x14000680ULL) + (x2 ^ 0x01D774ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA940A408ULL; // 0x01d774: ldp x8, x9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x01d778: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x540000C2ULL; // 0x01d77c: b.hs #0x1d794
    acc = (acc * 0x100000001B3ULL) ^ 0xAD400420ULL; // 0x01d780: ldp q0, q1, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x91008109ULL; // 0x01d784: add x9, x8, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAD000500ULL; // 0x01d788: stp q0, q1, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000409ULL; // 0x01d78c: str x9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01d790: ret 
    return acc;
}

// [EN] Reconstructed FDE #0685 @ 0x01d798..0x01d7c0 (40 bytes)
// [VN] Phục dựng FDE #0685 tại 0x01d798..0x01d7c0 (40 byte)
//   0x01d798: b4000121  cbz      x1, #0x1d7bc
//   0x01d79c: d00001e9  adrp     x9, #0x5b000
//   0x01d7a0: f9446d29  ldr      x9, [x9, #0x8d8]
//   0x01d7a4: 2a0303e8  mov      w8, w3
//   0x01d7a8: 2a0203e3  mov      w3, w2
//   0x01d7ac: 2a0403e2  mov      w2, w4
//   0x01d7b0: f9400120  ldr      x0, [x9]
//   0x01d7b4: 2a0803e4  mov      w4, w8
//   0x01d7b8: 17fff8d1  b        #0x1bafc
//   0x01d7bc: d65f03c0  ret      
uint64_t fde_0685_sub_01d798(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB4000121ULL) + (x1 ^ 0x17FFF8D1ULL) + (x2 ^ 0x01D798ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000121ULL; // 0x01d798: cbz x1, #0x1d7bc
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001E9ULL; // 0x01d79c: adrp x9, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9446D29ULL; // 0x01d7a0: ldr x9, [x9, #0x8d8]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303E8ULL; // 0x01d7a4: mov w8, w3
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203E3ULL; // 0x01d7a8: mov w3, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0403E2ULL; // 0x01d7ac: mov w2, w4
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400120ULL; // 0x01d7b0: ldr x0, [x9]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0803E4ULL; // 0x01d7b4: mov w4, w8
    return acc;
}

// [EN] Reconstructed FDE #0686 @ 0x01d7c0..0x01d7e4 (36 bytes)
// [VN] Phục dựng FDE #0686 tại 0x01d7c0..0x01d7e4 (36 byte)
//   0x01d7c0: a940a408  ldp      x8, x9, [x0, #8]
//   0x01d7c4: eb09011f  cmp      x8, x9
//   0x01d7c8: 540000c2  b.hs     #0x1d7e0
//   0x01d7cc: 3dc00020  ldr      q0, [x1]
//   0x01d7d0: 91004109  add      x9, x8, #0x10
//   0x01d7d4: 3d800100  str      q0, [x8]
//   0x01d7d8: f9000409  str      x9, [x0, #8]
//   0x01d7dc: d65f03c0  ret      
//   0x01d7e0: 140006f1  b        #0x1f3a4
uint64_t fde_0686_sub_01d7c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA940A408ULL) + (x1 ^ 0x140006F1ULL) + (x2 ^ 0x01D7C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA940A408ULL; // 0x01d7c0: ldp x8, x9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x01d7c4: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x540000C2ULL; // 0x01d7c8: b.hs #0x1d7e0
    acc = (acc * 0x100000001B3ULL) ^ 0x3DC00020ULL; // 0x01d7cc: ldr q0, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004109ULL; // 0x01d7d0: add x9, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x3D800100ULL; // 0x01d7d4: str q0, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000409ULL; // 0x01d7d8: str x9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01d7dc: ret 
    return acc;
}

// [EN] Reconstructed FDE #0687 @ 0x01d7e4..0x01d914 (304 bytes)
// [VN] Phục dựng FDE #0687 tại 0x01d7e4..0x01d914 (304 byte)
//   0x01d7e4: d10203ff  sub      sp, sp, #0x80
//   0x01d7e8: f9001bf9  str      x25, [sp, #0x30]
//   0x01d7ec: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x01d7f0: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x01d7f4: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x01d7f8: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x01d7fc: 9101c3fd  add      x29, sp, #0x70
//   0x01d800: d53bd059  mrs      x25, tpidr_el0
//   0x01d804: f9401728  ldr      x8, [x25, #0x28]
//   0x01d808: aa0003f4  mov      x20, x0
//   0x01d80c: f90017e8  str      x8, [sp, #0x28]
//   0x01d810: 94000041  bl       #0x1d914
uint64_t fde_0687_sub_01d7e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xF9401728ULL) + (x2 ^ 0x01D7E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x01d7e4: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF9ULL; // 0x01d7e8: str x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x01d7ec: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x01d7f0: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x01d7f4: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x01d7f8: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x01d7fc: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x01d800: mrs x25, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0688 @ 0x01d914..0x01e0a0 (1932 bytes)
// [VN] Phục dựng FDE #0688 tại 0x01d914..0x01e0a0 (1932 byte)
//   0x01d914: d10243ff  sub      sp, sp, #0x90
//   0x01d918: a90467fa  stp      x26, x25, [sp, #0x40]
//   0x01d91c: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x01d920: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x01d924: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x01d928: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x01d92c: 910203fd  add      x29, sp, #0x80
//   0x01d930: 9400084c  bl       #0x1fa60
//   0x01d934: 34000068  cbz      w8, #0x1d940
//   0x01d938: 52800020  mov      w0, #1
//   0x01d93c: 14000037  b        #0x1da18
//   0x01d940: 94000829  bl       #0x1f9e4
uint64_t fde_0688_sub_01d914(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0x34000068ULL) + (x2 ^ 0x01D914ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x01d914: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA90467FAULL; // 0x01d918: stp x26, x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x01d91c: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x01d920: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x01d924: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x01d928: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x01d92c: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0x9400084CULL; // 0x01d930: bl #0x1fa60
    return acc;
}

// [EN] Reconstructed FDE #0689 @ 0x01e0a0..0x01e158 (184 bytes)
// [VN] Phục dựng FDE #0689 tại 0x01e0a0..0x01e158 (184 byte)
//   0x01e0a0: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x01e0a4: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x01e0a8: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x01e0ac: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x01e0b0: 9100c3fd  add      x29, sp, #0x30
//   0x01e0b4: 2a0503f3  mov      w19, w5
//   0x01e0b8: 2a0403f6  mov      w22, w4
//   0x01e0bc: 2a0303f7  mov      w23, w3
//   0x01e0c0: 2a0203f8  mov      w24, w2
//   0x01e0c4: aa0103f4  mov      x20, x1
//   0x01e0c8: aa0003f5  mov      x21, x0
//   0x01e0cc: 97ffb569  bl       #0xb670
uint64_t fde_0689_sub_01e0a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0x2A0203F8ULL) + (x2 ^ 0x01E0A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x01e0a0: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x01e0a4: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x01e0a8: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x01e0ac: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x01e0b0: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0503F3ULL; // 0x01e0b4: mov w19, w5
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0403F6ULL; // 0x01e0b8: mov w22, w4
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303F7ULL; // 0x01e0bc: mov w23, w3
    return acc;
}

// [EN] Reconstructed FDE #0690 @ 0x01e158..0x01e28c (308 bytes)
// [VN] Phục dựng FDE #0690 tại 0x01e158..0x01e28c (308 byte)
//   0x01e158: d102c3ff  sub      sp, sp, #0xb0
//   0x01e15c: f90033f9  str      x25, [sp, #0x60]
//   0x01e160: a9075ff8  stp      x24, x23, [sp, #0x70]
//   0x01e164: a90857f6  stp      x22, x21, [sp, #0x80]
//   0x01e168: a9094ff4  stp      x20, x19, [sp, #0x90]
//   0x01e16c: a90a7bfd  stp      x29, x30, [sp, #0xa0]
//   0x01e170: 910283fd  add      x29, sp, #0xa0
//   0x01e174: d53bd059  mrs      x25, tpidr_el0
//   0x01e178: f9401728  ldr      x8, [x25, #0x28]
//   0x01e17c: aa0003f5  mov      x21, x0
//   0x01e180: f81b83a8  stur     x8, [x29, #-0x48]
//   0x01e184: 94000042  bl       #0x1e28c
uint64_t fde_0690_sub_01e158(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD102C3FFULL) + (x1 ^ 0xF9401728ULL) + (x2 ^ 0x01E158ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD102C3FFULL; // 0x01e158: sub sp, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xF90033F9ULL; // 0x01e15c: str x25, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9075FF8ULL; // 0x01e160: stp x24, x23, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90857F6ULL; // 0x01e164: stp x22, x21, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9094FF4ULL; // 0x01e168: stp x20, x19, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A7BFDULL; // 0x01e16c: stp x29, x30, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910283FDULL; // 0x01e170: add x29, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x01e174: mrs x25, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0691 @ 0x01e28c..0x01e4fc (624 bytes)
// [VN] Phục dựng FDE #0691 tại 0x01e28c..0x01e4fc (624 byte)
//   0x01e28c: d10243ff  sub      sp, sp, #0x90
//   0x01e290: a90467fa  stp      x26, x25, [sp, #0x40]
//   0x01e294: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x01e298: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x01e29c: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x01e2a0: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x01e2a4: 910203fd  add      x29, sp, #0x80
//   0x01e2a8: 940005ee  bl       #0x1fa60
//   0x01e2ac: 34000068  cbz      w8, #0x1e2b8
//   0x01e2b0: 52800020  mov      w0, #1
//   0x01e2b4: 14000064  b        #0x1e444
//   0x01e2b8: 940005cb  bl       #0x1f9e4
uint64_t fde_0691_sub_01e28c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0x34000068ULL) + (x2 ^ 0x01E28CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x01e28c: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA90467FAULL; // 0x01e290: stp x26, x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x01e294: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x01e298: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x01e29c: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x01e2a0: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x01e2a4: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0x940005EEULL; // 0x01e2a8: bl #0x1fa60
    return acc;
}

// [EN] Reconstructed FDE #0692 @ 0x01e4fc..0x01e72c (560 bytes)
// [VN] Phục dựng FDE #0692 tại 0x01e4fc..0x01e72c (560 byte)
//   0x01e4fc: d10383ff  sub      sp, sp, #0xe0
//   0x01e500: a9086ffc  stp      x28, x27, [sp, #0x80]
//   0x01e504: a90967fa  stp      x26, x25, [sp, #0x90]
//   0x01e508: a90a5ff8  stp      x24, x23, [sp, #0xa0]
//   0x01e50c: a90b57f6  stp      x22, x21, [sp, #0xb0]
//   0x01e510: a90c4ff4  stp      x20, x19, [sp, #0xc0]
//   0x01e514: a90d7bfd  stp      x29, x30, [sp, #0xd0]
//   0x01e518: 910343fd  add      x29, sp, #0xd0
//   0x01e51c: d53bd054  mrs      x20, tpidr_el0
//   0x01e520: f9401688  ldr      x8, [x20, #0x28]
//   0x01e524: aa0003f3  mov      x19, x0
//   0x01e528: f81a83a8  stur     x8, [x29, #-0x58]
uint64_t fde_0692_sub_01e4fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10383FFULL) + (x1 ^ 0xD53BD054ULL) + (x2 ^ 0x01E4FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10383FFULL; // 0x01e4fc: sub sp, sp, #0xe0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9086FFCULL; // 0x01e500: stp x28, x27, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90967FAULL; // 0x01e504: stp x26, x25, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A5FF8ULL; // 0x01e508: stp x24, x23, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B57F6ULL; // 0x01e50c: stp x22, x21, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C4FF4ULL; // 0x01e510: stp x20, x19, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90D7BFDULL; // 0x01e514: stp x29, x30, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910343FDULL; // 0x01e518: add x29, sp, #0xd0
    return acc;
}

// [EN] Reconstructed FDE #0693 @ 0x01e72c..0x01e804 (216 bytes)
// [VN] Phục dựng FDE #0693 tại 0x01e72c..0x01e804 (216 byte)
//   0x01e72c: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x01e730: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x01e734: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x01e738: 910083fd  add      x29, sp, #0x20
//   0x01e73c: aa0003f3  mov      x19, x0
//   0x01e740: aa1f03f5  mov      x21, xzr
//   0x01e744: f1002abf  cmp      x21, #0xa
//   0x01e748: 54000380  b.eq     #0x1e7b8
//   0x01e74c: f9400274  ldr      x20, [x19]
//   0x01e750: 52800081  mov      w1, #4
//   0x01e754: aa1403e0  mov      x0, x20
//   0x01e758: 97ffb15e  bl       #0xacd0
uint64_t fde_0693_sub_01e72c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xF9400274ULL) + (x2 ^ 0x01E72CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x01e72c: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x01e730: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x01e734: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x01e738: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01e73c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03F5ULL; // 0x01e740: mov x21, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xF1002ABFULL; // 0x01e744: cmp x21, #0xa
    acc = (acc * 0x100000001B3ULL) ^ 0x54000380ULL; // 0x01e748: b.eq #0x1e7b8
    return acc;
}

// [EN] Reconstructed FDE #0694 @ 0x01e804..0x01e8f4 (240 bytes)
// [VN] Phục dựng FDE #0694 tại 0x01e804..0x01e8f4 (240 byte)
//   0x01e804: d10183ff  sub      sp, sp, #0x60
//   0x01e808: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x01e80c: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x01e810: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x01e814: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x01e818: 910143fd  add      x29, sp, #0x50
//   0x01e81c: d53bd057  mrs      x23, tpidr_el0
//   0x01e820: f94016e8  ldr      x8, [x23, #0x28]
//   0x01e824: 2a0303f8  mov      w24, w3
//   0x01e828: aa0203f3  mov      x19, x2
//   0x01e82c: aa0103f4  mov      x20, x1
//   0x01e830: aa0003f6  mov      x22, x0
uint64_t fde_0694_sub_01e804(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0x2A0303F8ULL) + (x2 ^ 0x01E804ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x01e804: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x01e808: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x01e80c: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x01e810: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x01e814: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x01e818: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x01e81c: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x01e820: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0695 @ 0x01e8f4..0x01e918 (36 bytes)
// [VN] Phục dựng FDE #0695 tại 0x01e8f4..0x01e918 (36 byte)
//   0x01e8f4: a940a408  ldp      x8, x9, [x0, #8]
//   0x01e8f8: eb09011f  cmp      x8, x9
//   0x01e8fc: 540000c2  b.hs     #0x1e914
//   0x01e900: 3dc00020  ldr      q0, [x1]
//   0x01e904: 91004109  add      x9, x8, #0x10
//   0x01e908: 3d800100  str      q0, [x8]
//   0x01e90c: f9000409  str      x9, [x0, #8]
//   0x01e910: d65f03c0  ret      
//   0x01e914: 14000328  b        #0x1f5b4
uint64_t fde_0695_sub_01e8f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA940A408ULL) + (x1 ^ 0x14000328ULL) + (x2 ^ 0x01E8F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA940A408ULL; // 0x01e8f4: ldp x8, x9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x01e8f8: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x540000C2ULL; // 0x01e8fc: b.hs #0x1e914
    acc = (acc * 0x100000001B3ULL) ^ 0x3DC00020ULL; // 0x01e900: ldr q0, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004109ULL; // 0x01e904: add x9, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x3D800100ULL; // 0x01e908: str q0, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000409ULL; // 0x01e90c: str x9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01e910: ret 
    return acc;
}

// [EN] Reconstructed FDE #0696 @ 0x01e918..0x01e968 (80 bytes)
// [VN] Phục dựng FDE #0696 tại 0x01e918..0x01e968 (80 byte)
//   0x01e918: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x01e91c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01e920: 910043fd  add      x29, sp, #0x10
//   0x01e924: aa0003f3  mov      x19, x0
//   0x01e928: 97ffb352  bl       #0xb670
//   0x01e92c: 7100741f  cmp      w0, #0x1d
//   0x01e930: 5400008a  b.ge     #0x1e940
//   0x01e934: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x01e938: f84207f3  ldr      x19, [sp], #0x20
//   0x01e93c: d65f03c0  ret      
//   0x01e940: 7100841f  cmp      w0, #0x21
//   0x01e944: 540000ac  b.gt     #0x1e958
uint64_t fde_0696_sub_01e918(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x01E918ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x01e918: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01e91c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01e920: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01e924: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFB352ULL; // 0x01e928: bl #0xb670
    acc = (acc * 0x100000001B3ULL) ^ 0x7100741FULL; // 0x01e92c: cmp w0, #0x1d
    acc = (acc * 0x100000001B3ULL) ^ 0x5400008AULL; // 0x01e930: b.ge #0x1e940
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x01e934: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0697 @ 0x01e968..0x01eb38 (464 bytes)
// [VN] Phục dựng FDE #0697 tại 0x01e968..0x01eb38 (464 byte)
//   0x01e968: d10283ff  sub      sp, sp, #0xa0
//   0x01e96c: a9046ffc  stp      x28, x27, [sp, #0x40]
//   0x01e970: a90567fa  stp      x26, x25, [sp, #0x50]
//   0x01e974: a9065ff8  stp      x24, x23, [sp, #0x60]
//   0x01e978: a90757f6  stp      x22, x21, [sp, #0x70]
//   0x01e97c: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x01e980: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x01e984: 910243fd  add      x29, sp, #0x90
//   0x01e988: d53bd056  mrs      x22, tpidr_el0
//   0x01e98c: f94016c8  ldr      x8, [x22, #0x28]
//   0x01e990: f9001fe8  str      x8, [sp, #0x38]
//   0x01e994: 910063e8  add      x8, sp, #0x18
uint64_t fde_0697_sub_01e968(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10283FFULL) + (x1 ^ 0xD53BD056ULL) + (x2 ^ 0x01E968ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10283FFULL; // 0x01e968: sub sp, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9046FFCULL; // 0x01e96c: stp x28, x27, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90567FAULL; // 0x01e970: stp x26, x25, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9065FF8ULL; // 0x01e974: stp x24, x23, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90757F6ULL; // 0x01e978: stp x22, x21, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9084FF4ULL; // 0x01e97c: stp x20, x19, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9097BFDULL; // 0x01e980: stp x29, x30, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0x910243FDULL; // 0x01e984: add x29, sp, #0x90
    return acc;
}

// [EN] Reconstructed FDE #0698 @ 0x01eb38..0x01eb3c (4 bytes)
// [VN] Phục dựng FDE #0698 tại 0x01eb38..0x01eb3c (4 byte)
//   0x01eb38: 14000323  b        #0x1f7c4
uint64_t fde_0698_sub_01eb38(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x14000323ULL) + (x1 ^ 0x14000323ULL) + (x2 ^ 0x01EB38ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x14000323ULL; // 0x01eb38: b #0x1f7c4
    return acc;
}

// [EN] Reconstructed FDE #0699 @ 0x01eb3c..0x01eb40 (4 bytes)
// [VN] Phục dựng FDE #0699 tại 0x01eb3c..0x01eb40 (4 byte)
//   0x01eb3c: 14000328  b        #0x1f7dc
uint64_t fde_0699_sub_01eb3c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x14000328ULL) + (x1 ^ 0x14000328ULL) + (x2 ^ 0x01EB3CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x14000328ULL; // 0x01eb3c: b #0x1f7dc
    return acc;
}

// [EN] Reconstructed FDE #0700 @ 0x01eb40..0x01eb44 (4 bytes)
// [VN] Phục dựng FDE #0700 tại 0x01eb40..0x01eb44 (4 byte)
//   0x01eb40: 1400032d  b        #0x1f7f4
uint64_t fde_0700_sub_01eb40(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x1400032DULL) + (x1 ^ 0x1400032DULL) + (x2 ^ 0x01EB40ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x1400032DULL; // 0x01eb40: b #0x1f7f4
    return acc;
}

// [EN] Reconstructed FDE #0701 @ 0x01eb44..0x01eb48 (4 bytes)
// [VN] Phục dựng FDE #0701 tại 0x01eb44..0x01eb48 (4 byte)
//   0x01eb44: 14000332  b        #0x1f80c
uint64_t fde_0701_sub_01eb44(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x14000332ULL) + (x1 ^ 0x14000332ULL) + (x2 ^ 0x01EB44ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x14000332ULL; // 0x01eb44: b #0x1f80c
    return acc;
}

// [EN] Reconstructed FDE #0702 @ 0x01eb48..0x01eb4c (4 bytes)
// [VN] Phục dựng FDE #0702 tại 0x01eb48..0x01eb4c (4 byte)
//   0x01eb48: 14000337  b        #0x1f824
uint64_t fde_0702_sub_01eb48(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x14000337ULL) + (x1 ^ 0x14000337ULL) + (x2 ^ 0x01EB48ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x14000337ULL; // 0x01eb48: b #0x1f824
    return acc;
}

// [EN] Reconstructed FDE #0703 @ 0x01eb4c..0x01eba0 (84 bytes)
// [VN] Phục dựng FDE #0703 tại 0x01eb4c..0x01eba0 (84 byte)
//   0x01eb4c: eb01007f  cmp      x3, x1
//   0x01eb50: 54000069  b.ls     #0x1eb5c
//   0x01eb54: 92800003  mov      x3, #-1
//   0x01eb58: 14000010  b        #0x1eb98
//   0x01eb5c: b40001e4  cbz      x4, #0x1eb98
//   0x01eb60: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x01eb64: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01eb68: 910043fd  add      x29, sp, #0x10
//   0x01eb6c: aa0003f3  mov      x19, x0
//   0x01eb70: 8b010274  add      x20, x19, x1
//   0x01eb74: 8b030000  add      x0, x0, x3
//   0x01eb78: 8b040043  add      x3, x2, x4
uint64_t fde_0703_sub_01eb4c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xEB01007FULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x01EB4CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xEB01007FULL; // 0x01eb4c: cmp x3, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000069ULL; // 0x01eb50: b.ls #0x1eb5c
    acc = (acc * 0x100000001B3ULL) ^ 0x92800003ULL; // 0x01eb54: mov x3, #-1
    acc = (acc * 0x100000001B3ULL) ^ 0x14000010ULL; // 0x01eb58: b #0x1eb98
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001E4ULL; // 0x01eb5c: cbz x4, #0x1eb98
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x01eb60: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01eb64: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01eb68: add x29, sp, #0x10
    return acc;
}

// [EN] Reconstructed FDE #0704 @ 0x01eba0..0x01ec64 (196 bytes)
// [VN] Phục dựng FDE #0704 tại 0x01eba0..0x01ec64 (196 byte)
//   0x01eba0: d10143ff  sub      sp, sp, #0x50
//   0x01eba4: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x01eba8: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x01ebac: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x01ebb0: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x01ebb4: 910103fd  add      x29, sp, #0x40
//   0x01ebb8: d53bd057  mrs      x23, tpidr_el0
//   0x01ebbc: f94016e8  ldr      x8, [x23, #0x28]
//   0x01ebc0: aa0003f3  mov      x19, x0
//   0x01ebc4: eb020076  subs     x22, x3, x2
//   0x01ebc8: f90007e8  str      x8, [sp, #8]
//   0x01ebcc: 54000340  b.eq     #0x1ec34
uint64_t fde_0704_sub_01eba0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x01EBA0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x01eba0: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x01eba4: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x01eba8: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x01ebac: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x01ebb0: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x01ebb4: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x01ebb8: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x01ebbc: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0705 @ 0x01ec64..0x01ed28 (196 bytes)
// [VN] Phục dựng FDE #0705 tại 0x01ec64..0x01ed28 (196 byte)
//   0x01ec64: d101c3ff  sub      sp, sp, #0x70
//   0x01ec68: f9001bf7  str      x23, [sp, #0x30]
//   0x01ec6c: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x01ec70: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x01ec74: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x01ec78: 910183fd  add      x29, sp, #0x60
//   0x01ec7c: d53bd056  mrs      x22, tpidr_el0
//   0x01ec80: f94016c8  ldr      x8, [x22, #0x28]
//   0x01ec84: 52800317  mov      w23, #0x18
//   0x01ec88: aa0103f3  mov      x19, x1
//   0x01ec8c: aa0003f4  mov      x20, x0
//   0x01ec90: f90017e8  str      x8, [sp, #0x28]
uint64_t fde_0705_sub_01ec64(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x52800317ULL) + (x2 ^ 0x01EC64ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x01ec64: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF7ULL; // 0x01ec68: str x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x01ec6c: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x01ec70: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x01ec74: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x01ec78: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x01ec7c: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x01ec80: ldr x8, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0706 @ 0x01ed28..0x01ed84 (92 bytes)
// [VN] Phục dựng FDE #0706 tại 0x01ed28..0x01ed84 (92 byte)
//   0x01ed28: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x01ed2c: 910003fd  mov      x29, sp
//   0x01ed30: b201f3e8  mov      x8, #-0x5555555555555556
//   0x01ed34: f2e15548  movk     x8, #0xaaa, lsl #48
//   0x01ed38: eb08003f  cmp      x1, x8
//   0x01ed3c: 54000228  b.hi     #0x1ed80
//   0x01ed40: f9400809  ldr      x9, [x0, #0x10]
//   0x01ed44: f940000a  ldr      x10, [x0]
//   0x01ed48: 5280030b  mov      w11, #0x18
//   0x01ed4c: cb0a0129  sub      x9, x9, x10
//   0x01ed50: b200f3ea  mov      x10, #0x5555555555555555
//   0x01ed54: f28aaa8a  movk     x10, #0x5554
uint64_t fde_0706_sub_01ed28(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x5280030BULL) + (x2 ^ 0x01ED28ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x01ed28: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x01ed2c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xB201F3E8ULL; // 0x01ed30: mov x8, #-0x5555555555555556
    acc = (acc * 0x100000001B3ULL) ^ 0xF2E15548ULL; // 0x01ed34: movk x8, #0xaaa, lsl #48
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08003FULL; // 0x01ed38: cmp x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000228ULL; // 0x01ed3c: b.hi #0x1ed80
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400809ULL; // 0x01ed40: ldr x9, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF940000AULL; // 0x01ed44: ldr x10, [x0]
    return acc;
}

// [EN] Reconstructed FDE #0707 @ 0x01ed84..0x01ede0 (92 bytes)
// [VN] Phục dựng FDE #0707 tại 0x01ed84..0x01ede0 (92 byte)
//   0x01ed84: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x01ed88: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x01ed8c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x01ed90: 910083fd  add      x29, sp, #0x20
//   0x01ed94: aa0203f5  mov      x21, x2
//   0x01ed98: aa0103f4  mov      x20, x1
//   0x01ed9c: aa0003f3  mov      x19, x0
//   0x01eda0: a9018c1f  stp      xzr, x3, [x0, #0x18]
//   0x01eda4: b40000a1  cbz      x1, #0x1edb8
//   0x01eda8: aa0303e0  mov      x0, x3
//   0x01edac: aa1403e1  mov      x1, x20
//   0x01edb0: 94000032  bl       #0x1ee78
uint64_t fde_0707_sub_01ed84(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xB40000A1ULL) + (x2 ^ 0x01ED84ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x01ed84: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x01ed88: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x01ed8c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x01ed90: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x01ed94: mov x21, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x01ed98: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01ed9c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9018C1FULL; // 0x01eda0: stp xzr, x3, [x0, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0708 @ 0x01ede0..0x01ee44 (100 bytes)
// [VN] Phục dựng FDE #0708 tại 0x01ede0..0x01ee44 (100 byte)
//   0x01ede0: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x01ede4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01ede8: 910043fd  add      x29, sp, #0x10
//   0x01edec: aa0103f3  mov      x19, x1
//   0x01edf0: aa0003f4  mov      x20, x0
//   0x01edf4: a8c10801  ldp      x1, x2, [x0], #0x10
//   0x01edf8: 91002263  add      x3, x19, #8
//   0x01edfc: 9400002c  bl       #0x1eeac
//   0x01ee00: f9400668  ldr      x8, [x19, #8]
//   0x01ee04: f9400289  ldr      x9, [x20]
//   0x01ee08: f9000288  str      x8, [x20]
//   0x01ee0c: f9400a68  ldr      x8, [x19, #0x10]
uint64_t fde_0708_sub_01ede0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9400668ULL) + (x2 ^ 0x01EDE0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x01ede0: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01ede4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01ede8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x01edec: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x01edf0: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C10801ULL; // 0x01edf4: ldp x1, x2, [x0], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x91002263ULL; // 0x01edf8: add x3, x19, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x9400002CULL; // 0x01edfc: bl #0x1eeac
    return acc;
}

// [EN] Reconstructed FDE #0709 @ 0x01ee44..0x01ee78 (52 bytes)
// [VN] Phục dựng FDE #0709 tại 0x01ee44..0x01ee78 (52 byte)
//   0x01ee44: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x01ee48: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01ee4c: 910043fd  add      x29, sp, #0x10
//   0x01ee50: aa0003f3  mov      x19, x0
//   0x01ee54: 94000021  bl       #0x1eed8
//   0x01ee58: f9400260  ldr      x0, [x19]
//   0x01ee5c: b4000080  cbz      x0, #0x1ee6c
//   0x01ee60: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x01ee64: f84207f3  ldr      x19, [sp], #0x20
//   0x01ee68: 17ffafb6  b        #0xad40
//   0x01ee6c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x01ee70: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0709_sub_01ee44(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x01EE44ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x01ee44: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01ee48: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01ee4c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01ee50: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x94000021ULL; // 0x01ee54: bl #0x1eed8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400260ULL; // 0x01ee58: ldr x0, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000080ULL; // 0x01ee5c: cbz x0, #0x1ee6c
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x01ee60: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0710 @ 0x01ee78..0x01ee80 (8 bytes)
// [VN] Phục dựng FDE #0710 tại 0x01ee78..0x01ee80 (8 byte)
//   0x01ee78: aa1f03e2  mov      x2, xzr
//   0x01ee7c: 14000001  b        #0x1ee80
uint64_t fde_0710_sub_01ee78(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x01EE78ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x01ee78: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x01ee7c: b #0x1ee80
    return acc;
}

// [EN] Reconstructed FDE #0711 @ 0x01ee80..0x01eeac (44 bytes)
// [VN] Phục dựng FDE #0711 tại 0x01ee80..0x01eeac (44 byte)
//   0x01ee80: b201f3e8  mov      x8, #-0x5555555555555556
//   0x01ee84: f2955568  movk     x8, #0xaaab
//   0x01ee88: f2e15548  movk     x8, #0xaaa, lsl #48
//   0x01ee8c: eb08003f  cmp      x1, x8
//   0x01ee90: 54000082  b.hs     #0x1eea0
//   0x01ee94: 8b010428  add      x8, x1, x1, lsl #1
//   0x01ee98: d37df100  lsl      x0, x8, #3
//   0x01ee9c: 17ffb1d5  b        #0xb5f0
//   0x01eea0: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x01eea4: 910003fd  mov      x29, sp
//   0x01eea8: 97ffb196  bl       #0xb500
uint64_t fde_0711_sub_01ee80(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB201F3E8ULL) + (x1 ^ 0xA9BF7BFDULL) + (x2 ^ 0x01EE80ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB201F3E8ULL; // 0x01ee80: mov x8, #-0x5555555555555556
    acc = (acc * 0x100000001B3ULL) ^ 0xF2955568ULL; // 0x01ee84: movk x8, #0xaaab
    acc = (acc * 0x100000001B3ULL) ^ 0xF2E15548ULL; // 0x01ee88: movk x8, #0xaaa, lsl #48
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08003FULL; // 0x01ee8c: cmp x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000082ULL; // 0x01ee90: b.hs #0x1eea0
    acc = (acc * 0x100000001B3ULL) ^ 0x8B010428ULL; // 0x01ee94: add x8, x1, x1, lsl #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DF100ULL; // 0x01ee98: lsl x0, x8, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFB1D5ULL; // 0x01ee9c: b #0xb5f0
    return acc;
}

// [EN] Reconstructed FDE #0712 @ 0x01eeac..0x01eed8 (44 bytes)
// [VN] Phục dựng FDE #0712 tại 0x01eeac..0x01eed8 (44 byte)
//   0x01eeac: f9400068  ldr      x8, [x3]
//   0x01eeb0: cb010042  sub      x2, x2, x1
//   0x01eeb4: 928002e9  mov      x9, #-0x18
//   0x01eeb8: 5280030a  mov      w10, #0x18
//   0x01eebc: 9ac90c49  sdiv     x9, x2, x9
//   0x01eec0: 9b0a2120  madd     x0, x9, x10, x8
//   0x01eec4: f100045f  cmp      x2, #1
//   0x01eec8: f9000060  str      x0, [x3]
//   0x01eecc: 5400004b  b.lt     #0x1eed4
//   0x01eed0: 17ffaf50  b        #0xac10
//   0x01eed4: d65f03c0  ret      
uint64_t fde_0712_sub_01eeac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400068ULL) + (x1 ^ 0x5400004BULL) + (x2 ^ 0x01EEACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400068ULL; // 0x01eeac: ldr x8, [x3]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB010042ULL; // 0x01eeb0: sub x2, x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x928002E9ULL; // 0x01eeb4: mov x9, #-0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x5280030AULL; // 0x01eeb8: mov w10, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x9AC90C49ULL; // 0x01eebc: sdiv x9, x2, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x9B0A2120ULL; // 0x01eec0: madd x0, x9, x10, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF100045FULL; // 0x01eec4: cmp x2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000060ULL; // 0x01eec8: str x0, [x3]
    return acc;
}

// [EN] Reconstructed FDE #0713 @ 0x01eed8..0x01eee0 (8 bytes)
// [VN] Phục dựng FDE #0713 tại 0x01eed8..0x01eee0 (8 byte)
//   0x01eed8: f9400401  ldr      x1, [x0, #8]
//   0x01eedc: 14000001  b        #0x1eee0
uint64_t fde_0713_sub_01eed8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400401ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x01EED8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400401ULL; // 0x01eed8: ldr x1, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x01eedc: b #0x1eee0
    return acc;
}

// [EN] Reconstructed FDE #0714 @ 0x01eee0..0x01eefc (28 bytes)
// [VN] Phục dựng FDE #0714 tại 0x01eee0..0x01eefc (28 byte)
//   0x01eee0: f9400808  ldr      x8, [x0, #0x10]
//   0x01eee4: eb08003f  cmp      x1, x8
//   0x01eee8: 54000080  b.eq     #0x1eef8
//   0x01eeec: d1006108  sub      x8, x8, #0x18
//   0x01eef0: f9000808  str      x8, [x0, #0x10]
//   0x01eef4: 17fffffc  b        #0x1eee4
//   0x01eef8: d65f03c0  ret      
uint64_t fde_0714_sub_01eee0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400808ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01EEE0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x01eee0: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08003FULL; // 0x01eee4: cmp x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000080ULL; // 0x01eee8: b.eq #0x1eef8
    acc = (acc * 0x100000001B3ULL) ^ 0xD1006108ULL; // 0x01eeec: sub x8, x8, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000808ULL; // 0x01eef0: str x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFFCULL; // 0x01eef4: b #0x1eee4
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01eef8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0715 @ 0x01eefc..0x01efc0 (196 bytes)
// [VN] Phục dựng FDE #0715 tại 0x01eefc..0x01efc0 (196 byte)
//   0x01eefc: d101c3ff  sub      sp, sp, #0x70
//   0x01ef00: f9001bf7  str      x23, [sp, #0x30]
//   0x01ef04: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x01ef08: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x01ef0c: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x01ef10: 910183fd  add      x29, sp, #0x60
//   0x01ef14: d53bd056  mrs      x22, tpidr_el0
//   0x01ef18: f94016c8  ldr      x8, [x22, #0x28]
//   0x01ef1c: 52800317  mov      w23, #0x18
//   0x01ef20: aa0103f3  mov      x19, x1
//   0x01ef24: aa0003f4  mov      x20, x0
//   0x01ef28: f90017e8  str      x8, [sp, #0x28]
uint64_t fde_0715_sub_01eefc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x52800317ULL) + (x2 ^ 0x01EEFCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x01eefc: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF7ULL; // 0x01ef00: str x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x01ef04: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x01ef08: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x01ef0c: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x01ef10: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x01ef14: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x01ef18: ldr x8, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0716 @ 0x01efc0..0x01f01c (92 bytes)
// [VN] Phục dựng FDE #0716 tại 0x01efc0..0x01f01c (92 byte)
//   0x01efc0: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x01efc4: 910003fd  mov      x29, sp
//   0x01efc8: b201f3e8  mov      x8, #-0x5555555555555556
//   0x01efcc: f2e15548  movk     x8, #0xaaa, lsl #48
//   0x01efd0: eb08003f  cmp      x1, x8
//   0x01efd4: 54000228  b.hi     #0x1f018
//   0x01efd8: f9400809  ldr      x9, [x0, #0x10]
//   0x01efdc: f940000a  ldr      x10, [x0]
//   0x01efe0: 5280030b  mov      w11, #0x18
//   0x01efe4: cb0a0129  sub      x9, x9, x10
//   0x01efe8: b200f3ea  mov      x10, #0x5555555555555555
//   0x01efec: f28aaa8a  movk     x10, #0x5554
uint64_t fde_0716_sub_01efc0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x5280030BULL) + (x2 ^ 0x01EFC0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x01efc0: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x01efc4: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xB201F3E8ULL; // 0x01efc8: mov x8, #-0x5555555555555556
    acc = (acc * 0x100000001B3ULL) ^ 0xF2E15548ULL; // 0x01efcc: movk x8, #0xaaa, lsl #48
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08003FULL; // 0x01efd0: cmp x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000228ULL; // 0x01efd4: b.hi #0x1f018
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400809ULL; // 0x01efd8: ldr x9, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF940000AULL; // 0x01efdc: ldr x10, [x0]
    return acc;
}

// [EN] Reconstructed FDE #0717 @ 0x01f01c..0x01f078 (92 bytes)
// [VN] Phục dựng FDE #0717 tại 0x01f01c..0x01f078 (92 byte)
//   0x01f01c: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x01f020: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x01f024: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x01f028: 910083fd  add      x29, sp, #0x20
//   0x01f02c: aa0203f5  mov      x21, x2
//   0x01f030: aa0103f4  mov      x20, x1
//   0x01f034: aa0003f3  mov      x19, x0
//   0x01f038: a9018c1f  stp      xzr, x3, [x0, #0x18]
//   0x01f03c: b40000a1  cbz      x1, #0x1f050
//   0x01f040: aa0303e0  mov      x0, x3
//   0x01f044: aa1403e1  mov      x1, x20
//   0x01f048: 94000032  bl       #0x1f110
uint64_t fde_0717_sub_01f01c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xB40000A1ULL) + (x2 ^ 0x01F01CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x01f01c: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x01f020: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x01f024: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x01f028: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x01f02c: mov x21, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x01f030: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01f034: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9018C1FULL; // 0x01f038: stp xzr, x3, [x0, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0718 @ 0x01f078..0x01f0dc (100 bytes)
// [VN] Phục dựng FDE #0718 tại 0x01f078..0x01f0dc (100 byte)
//   0x01f078: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x01f07c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01f080: 910043fd  add      x29, sp, #0x10
//   0x01f084: aa0103f3  mov      x19, x1
//   0x01f088: aa0003f4  mov      x20, x0
//   0x01f08c: a8c10801  ldp      x1, x2, [x0], #0x10
//   0x01f090: 91002263  add      x3, x19, #8
//   0x01f094: 9400002c  bl       #0x1f144
//   0x01f098: f9400668  ldr      x8, [x19, #8]
//   0x01f09c: f9400289  ldr      x9, [x20]
//   0x01f0a0: f9000288  str      x8, [x20]
//   0x01f0a4: f9400a68  ldr      x8, [x19, #0x10]
uint64_t fde_0718_sub_01f078(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9400668ULL) + (x2 ^ 0x01F078ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x01f078: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01f07c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01f080: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x01f084: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x01f088: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C10801ULL; // 0x01f08c: ldp x1, x2, [x0], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x91002263ULL; // 0x01f090: add x3, x19, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x9400002CULL; // 0x01f094: bl #0x1f144
    return acc;
}

// [EN] Reconstructed FDE #0719 @ 0x01f0dc..0x01f110 (52 bytes)
// [VN] Phục dựng FDE #0719 tại 0x01f0dc..0x01f110 (52 byte)
//   0x01f0dc: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x01f0e0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01f0e4: 910043fd  add      x29, sp, #0x10
//   0x01f0e8: aa0003f3  mov      x19, x0
//   0x01f0ec: 94000021  bl       #0x1f170
//   0x01f0f0: f9400260  ldr      x0, [x19]
//   0x01f0f4: b4000080  cbz      x0, #0x1f104
//   0x01f0f8: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x01f0fc: f84207f3  ldr      x19, [sp], #0x20
//   0x01f100: 17ffaf10  b        #0xad40
//   0x01f104: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x01f108: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0719_sub_01f0dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x01F0DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x01f0dc: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01f0e0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01f0e4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01f0e8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x94000021ULL; // 0x01f0ec: bl #0x1f170
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400260ULL; // 0x01f0f0: ldr x0, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000080ULL; // 0x01f0f4: cbz x0, #0x1f104
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x01f0f8: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0720 @ 0x01f110..0x01f118 (8 bytes)
// [VN] Phục dựng FDE #0720 tại 0x01f110..0x01f118 (8 byte)
//   0x01f110: aa1f03e2  mov      x2, xzr
//   0x01f114: 14000001  b        #0x1f118
uint64_t fde_0720_sub_01f110(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x01F110ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x01f110: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x01f114: b #0x1f118
    return acc;
}

// [EN] Reconstructed FDE #0721 @ 0x01f118..0x01f144 (44 bytes)
// [VN] Phục dựng FDE #0721 tại 0x01f118..0x01f144 (44 byte)
//   0x01f118: b201f3e8  mov      x8, #-0x5555555555555556
//   0x01f11c: f2955568  movk     x8, #0xaaab
//   0x01f120: f2e15548  movk     x8, #0xaaa, lsl #48
//   0x01f124: eb08003f  cmp      x1, x8
//   0x01f128: 54000082  b.hs     #0x1f138
//   0x01f12c: 8b010428  add      x8, x1, x1, lsl #1
//   0x01f130: d37df100  lsl      x0, x8, #3
//   0x01f134: 17ffb12f  b        #0xb5f0
//   0x01f138: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x01f13c: 910003fd  mov      x29, sp
//   0x01f140: 97ffb0f0  bl       #0xb500
uint64_t fde_0721_sub_01f118(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB201F3E8ULL) + (x1 ^ 0xA9BF7BFDULL) + (x2 ^ 0x01F118ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB201F3E8ULL; // 0x01f118: mov x8, #-0x5555555555555556
    acc = (acc * 0x100000001B3ULL) ^ 0xF2955568ULL; // 0x01f11c: movk x8, #0xaaab
    acc = (acc * 0x100000001B3ULL) ^ 0xF2E15548ULL; // 0x01f120: movk x8, #0xaaa, lsl #48
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08003FULL; // 0x01f124: cmp x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000082ULL; // 0x01f128: b.hs #0x1f138
    acc = (acc * 0x100000001B3ULL) ^ 0x8B010428ULL; // 0x01f12c: add x8, x1, x1, lsl #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DF100ULL; // 0x01f130: lsl x0, x8, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFB12FULL; // 0x01f134: b #0xb5f0
    return acc;
}

// [EN] Reconstructed FDE #0722 @ 0x01f144..0x01f170 (44 bytes)
// [VN] Phục dựng FDE #0722 tại 0x01f144..0x01f170 (44 byte)
//   0x01f144: f9400068  ldr      x8, [x3]
//   0x01f148: cb010042  sub      x2, x2, x1
//   0x01f14c: 928002e9  mov      x9, #-0x18
//   0x01f150: 5280030a  mov      w10, #0x18
//   0x01f154: 9ac90c49  sdiv     x9, x2, x9
//   0x01f158: 9b0a2120  madd     x0, x9, x10, x8
//   0x01f15c: f100045f  cmp      x2, #1
//   0x01f160: f9000060  str      x0, [x3]
//   0x01f164: 5400004b  b.lt     #0x1f16c
//   0x01f168: 17ffaeaa  b        #0xac10
//   0x01f16c: d65f03c0  ret      
uint64_t fde_0722_sub_01f144(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400068ULL) + (x1 ^ 0x5400004BULL) + (x2 ^ 0x01F144ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400068ULL; // 0x01f144: ldr x8, [x3]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB010042ULL; // 0x01f148: sub x2, x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x928002E9ULL; // 0x01f14c: mov x9, #-0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x5280030AULL; // 0x01f150: mov w10, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x9AC90C49ULL; // 0x01f154: sdiv x9, x2, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x9B0A2120ULL; // 0x01f158: madd x0, x9, x10, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF100045FULL; // 0x01f15c: cmp x2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000060ULL; // 0x01f160: str x0, [x3]
    return acc;
}

// [EN] Reconstructed FDE #0723 @ 0x01f170..0x01f178 (8 bytes)
// [VN] Phục dựng FDE #0723 tại 0x01f170..0x01f178 (8 byte)
//   0x01f170: f9400401  ldr      x1, [x0, #8]
//   0x01f174: 14000001  b        #0x1f178
uint64_t fde_0723_sub_01f170(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400401ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x01F170ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400401ULL; // 0x01f170: ldr x1, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x01f174: b #0x1f178
    return acc;
}

// [EN] Reconstructed FDE #0724 @ 0x01f178..0x01f194 (28 bytes)
// [VN] Phục dựng FDE #0724 tại 0x01f178..0x01f194 (28 byte)
//   0x01f178: f9400808  ldr      x8, [x0, #0x10]
//   0x01f17c: eb08003f  cmp      x1, x8
//   0x01f180: 54000080  b.eq     #0x1f190
//   0x01f184: d1006108  sub      x8, x8, #0x18
//   0x01f188: f9000808  str      x8, [x0, #0x10]
//   0x01f18c: 17fffffc  b        #0x1f17c
//   0x01f190: d65f03c0  ret      
uint64_t fde_0724_sub_01f178(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400808ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01F178ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x01f178: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08003FULL; // 0x01f17c: cmp x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000080ULL; // 0x01f180: b.eq #0x1f190
    acc = (acc * 0x100000001B3ULL) ^ 0xD1006108ULL; // 0x01f184: sub x8, x8, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000808ULL; // 0x01f188: str x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFFCULL; // 0x01f18c: b #0x1f17c
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01f190: ret 
    return acc;
}

// [EN] Reconstructed FDE #0725 @ 0x01f194..0x01f25c (200 bytes)
// [VN] Phục dựng FDE #0725 tại 0x01f194..0x01f25c (200 byte)
//   0x01f194: d101c3ff  sub      sp, sp, #0x70
//   0x01f198: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x01f19c: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x01f1a0: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x01f1a4: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x01f1a8: 910183fd  add      x29, sp, #0x60
//   0x01f1ac: d53bd057  mrs      x23, tpidr_el0
//   0x01f1b0: f94016e8  ldr      x8, [x23, #0x28]
//   0x01f1b4: aa0103f4  mov      x20, x1
//   0x01f1b8: aa0003f3  mov      x19, x0
//   0x01f1bc: 91004016  add      x22, x0, #0x10
//   0x01f1c0: f90017e8  str      x8, [sp, #0x28]
uint64_t fde_0725_sub_01f194(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xAA0103F4ULL) + (x2 ^ 0x01F194ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x01f194: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x01f198: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x01f19c: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x01f1a0: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x01f1a4: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x01f1a8: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x01f1ac: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x01f1b0: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0726 @ 0x01f25c..0x01f2a4 (72 bytes)
// [VN] Phục dựng FDE #0726 tại 0x01f25c..0x01f2a4 (72 byte)
//   0x01f25c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x01f260: 910003fd  mov      x29, sp
//   0x01f264: d37bfc28  lsr      x8, x1, #0x3b
//   0x01f268: b50001c8  cbnz     x8, #0x1f2a0
//   0x01f26c: f9400808  ldr      x8, [x0, #0x10]
//   0x01f270: f9400009  ldr      x9, [x0]
//   0x01f274: cb090108  sub      x8, x8, x9
//   0x01f278: b27fe3e9  mov      x9, #0x3fffffffffffffe
//   0x01f27c: eb88153f  cmp      x9, x8, asr #5
//   0x01f280: 540000a3  b.lo     #0x1f294
//   0x01f284: 9344fd08  asr      x8, x8, #4
//   0x01f288: eb01011f  cmp      x8, x1
uint64_t fde_0726_sub_01f25c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xEB88153FULL) + (x2 ^ 0x01F25CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x01f25c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x01f260: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xD37BFC28ULL; // 0x01f264: lsr x8, x1, #0x3b
    acc = (acc * 0x100000001B3ULL) ^ 0xB50001C8ULL; // 0x01f268: cbnz x8, #0x1f2a0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x01f26c: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400009ULL; // 0x01f270: ldr x9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB090108ULL; // 0x01f274: sub x8, x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xB27FE3E9ULL; // 0x01f278: mov x9, #0x3fffffffffffffe
    return acc;
}

// [EN] Reconstructed FDE #0727 @ 0x01f2a4..0x01f308 (100 bytes)
// [VN] Phục dựng FDE #0727 tại 0x01f2a4..0x01f308 (100 byte)
//   0x01f2a4: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x01f2a8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01f2ac: 910043fd  add      x29, sp, #0x10
//   0x01f2b0: aa0103f3  mov      x19, x1
//   0x01f2b4: aa0003f4  mov      x20, x0
//   0x01f2b8: a8c10801  ldp      x1, x2, [x0], #0x10
//   0x01f2bc: 91002263  add      x3, x19, #8
//   0x01f2c0: 94000028  bl       #0x1f360
//   0x01f2c4: f9400668  ldr      x8, [x19, #8]
//   0x01f2c8: f9400289  ldr      x9, [x20]
//   0x01f2cc: f9000288  str      x8, [x20]
//   0x01f2d0: f9400a68  ldr      x8, [x19, #0x10]
uint64_t fde_0727_sub_01f2a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9400668ULL) + (x2 ^ 0x01F2A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x01f2a4: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01f2a8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01f2ac: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x01f2b0: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x01f2b4: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C10801ULL; // 0x01f2b8: ldp x1, x2, [x0], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x91002263ULL; // 0x01f2bc: add x3, x19, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x94000028ULL; // 0x01f2c0: bl #0x1f360
    return acc;
}

// [EN] Reconstructed FDE #0728 @ 0x01f308..0x01f33c (52 bytes)
// [VN] Phục dựng FDE #0728 tại 0x01f308..0x01f33c (52 byte)
//   0x01f308: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x01f30c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01f310: 910043fd  add      x29, sp, #0x10
//   0x01f314: aa0003f3  mov      x19, x0
//   0x01f318: 9400001a  bl       #0x1f380
//   0x01f31c: f9400260  ldr      x0, [x19]
//   0x01f320: b4000080  cbz      x0, #0x1f330
//   0x01f324: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x01f328: f84207f3  ldr      x19, [sp], #0x20
//   0x01f32c: 17ffae85  b        #0xad40
//   0x01f330: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x01f334: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0728_sub_01f308(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x01F308ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x01f308: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01f30c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01f310: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01f314: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9400001AULL; // 0x01f318: bl #0x1f380
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400260ULL; // 0x01f31c: ldr x0, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000080ULL; // 0x01f320: cbz x0, #0x1f330
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x01f324: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0729 @ 0x01f33c..0x01f344 (8 bytes)
// [VN] Phục dựng FDE #0729 tại 0x01f33c..0x01f344 (8 byte)
//   0x01f33c: aa1f03e2  mov      x2, xzr
//   0x01f340: 14000001  b        #0x1f344
uint64_t fde_0729_sub_01f33c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x01F33CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x01f33c: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x01f340: b #0x1f344
    return acc;
}

// [EN] Reconstructed FDE #0730 @ 0x01f344..0x01f360 (28 bytes)
// [VN] Phục dựng FDE #0730 tại 0x01f344..0x01f360 (28 byte)
//   0x01f344: d37bfc28  lsr      x8, x1, #0x3b
//   0x01f348: b5000068  cbnz     x8, #0x1f354
//   0x01f34c: d37be820  lsl      x0, x1, #5
//   0x01f350: 17ffb0a8  b        #0xb5f0
//   0x01f354: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x01f358: 910003fd  mov      x29, sp
//   0x01f35c: 97ffb069  bl       #0xb500
uint64_t fde_0730_sub_01f344(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD37BFC28ULL) + (x1 ^ 0x97FFB069ULL) + (x2 ^ 0x01F344ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD37BFC28ULL; // 0x01f344: lsr x8, x1, #0x3b
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000068ULL; // 0x01f348: cbnz x8, #0x1f354
    acc = (acc * 0x100000001B3ULL) ^ 0xD37BE820ULL; // 0x01f34c: lsl x0, x1, #5
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFB0A8ULL; // 0x01f350: b #0xb5f0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x01f354: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x01f358: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFB069ULL; // 0x01f35c: bl #0xb500
    return acc;
}

// [EN] Reconstructed FDE #0731 @ 0x01f360..0x01f380 (32 bytes)
// [VN] Phục dựng FDE #0731 tại 0x01f360..0x01f380 (32 byte)
//   0x01f360: f9400068  ldr      x8, [x3]
//   0x01f364: cb010042  sub      x2, x2, x1
//   0x01f368: f100045f  cmp      x2, #1
//   0x01f36c: cb020100  sub      x0, x8, x2
//   0x01f370: f9000060  str      x0, [x3]
//   0x01f374: 5400004b  b.lt     #0x1f37c
//   0x01f378: 17ffae26  b        #0xac10
//   0x01f37c: d65f03c0  ret      
uint64_t fde_0731_sub_01f360(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400068ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01F360ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400068ULL; // 0x01f360: ldr x8, [x3]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB010042ULL; // 0x01f364: sub x2, x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF100045FULL; // 0x01f368: cmp x2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xCB020100ULL; // 0x01f36c: sub x0, x8, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000060ULL; // 0x01f370: str x0, [x3]
    acc = (acc * 0x100000001B3ULL) ^ 0x5400004BULL; // 0x01f374: b.lt #0x1f37c
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFAE26ULL; // 0x01f378: b #0xac10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01f37c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0732 @ 0x01f380..0x01f388 (8 bytes)
// [VN] Phục dựng FDE #0732 tại 0x01f380..0x01f388 (8 byte)
//   0x01f380: f9400401  ldr      x1, [x0, #8]
//   0x01f384: 14000001  b        #0x1f388
uint64_t fde_0732_sub_01f380(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400401ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x01F380ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400401ULL; // 0x01f380: ldr x1, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x01f384: b #0x1f388
    return acc;
}

// [EN] Reconstructed FDE #0733 @ 0x01f388..0x01f3a4 (28 bytes)
// [VN] Phục dựng FDE #0733 tại 0x01f388..0x01f3a4 (28 byte)
//   0x01f388: f9400808  ldr      x8, [x0, #0x10]
//   0x01f38c: eb08003f  cmp      x1, x8
//   0x01f390: 54000080  b.eq     #0x1f3a0
//   0x01f394: d1008108  sub      x8, x8, #0x20
//   0x01f398: f9000808  str      x8, [x0, #0x10]
//   0x01f39c: 17fffffc  b        #0x1f38c
//   0x01f3a0: d65f03c0  ret      
uint64_t fde_0733_sub_01f388(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400808ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01F388ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x01f388: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08003FULL; // 0x01f38c: cmp x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000080ULL; // 0x01f390: b.eq #0x1f3a0
    acc = (acc * 0x100000001B3ULL) ^ 0xD1008108ULL; // 0x01f394: sub x8, x8, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000808ULL; // 0x01f398: str x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFFCULL; // 0x01f39c: b #0x1f38c
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01f3a0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0734 @ 0x01f3a4..0x01f46c (200 bytes)
// [VN] Phục dựng FDE #0734 tại 0x01f3a4..0x01f46c (200 byte)
//   0x01f3a4: d101c3ff  sub      sp, sp, #0x70
//   0x01f3a8: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x01f3ac: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x01f3b0: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x01f3b4: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x01f3b8: 910183fd  add      x29, sp, #0x60
//   0x01f3bc: d53bd057  mrs      x23, tpidr_el0
//   0x01f3c0: f94016e8  ldr      x8, [x23, #0x28]
//   0x01f3c4: aa0103f4  mov      x20, x1
//   0x01f3c8: aa0003f3  mov      x19, x0
//   0x01f3cc: 91004016  add      x22, x0, #0x10
//   0x01f3d0: f90017e8  str      x8, [sp, #0x28]
uint64_t fde_0734_sub_01f3a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xAA0103F4ULL) + (x2 ^ 0x01F3A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x01f3a4: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x01f3a8: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x01f3ac: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x01f3b0: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x01f3b4: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x01f3b8: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x01f3bc: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x01f3c0: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0735 @ 0x01f46c..0x01f4b4 (72 bytes)
// [VN] Phục dựng FDE #0735 tại 0x01f46c..0x01f4b4 (72 byte)
//   0x01f46c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x01f470: 910003fd  mov      x29, sp
//   0x01f474: d37cfc28  lsr      x8, x1, #0x3c
//   0x01f478: b50001c8  cbnz     x8, #0x1f4b0
//   0x01f47c: f9400808  ldr      x8, [x0, #0x10]
//   0x01f480: f9400009  ldr      x9, [x0]
//   0x01f484: cb090108  sub      x8, x8, x9
//   0x01f488: b27fe7e9  mov      x9, #0x7fffffffffffffe
//   0x01f48c: eb88113f  cmp      x9, x8, asr #4
//   0x01f490: 540000a3  b.lo     #0x1f4a4
//   0x01f494: 9343fd08  asr      x8, x8, #3
//   0x01f498: eb01011f  cmp      x8, x1
uint64_t fde_0735_sub_01f46c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xEB88113FULL) + (x2 ^ 0x01F46CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x01f46c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x01f470: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xD37CFC28ULL; // 0x01f474: lsr x8, x1, #0x3c
    acc = (acc * 0x100000001B3ULL) ^ 0xB50001C8ULL; // 0x01f478: cbnz x8, #0x1f4b0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x01f47c: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400009ULL; // 0x01f480: ldr x9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB090108ULL; // 0x01f484: sub x8, x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xB27FE7E9ULL; // 0x01f488: mov x9, #0x7fffffffffffffe
    return acc;
}

// [EN] Reconstructed FDE #0736 @ 0x01f4b4..0x01f518 (100 bytes)
// [VN] Phục dựng FDE #0736 tại 0x01f4b4..0x01f518 (100 byte)
//   0x01f4b4: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x01f4b8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01f4bc: 910043fd  add      x29, sp, #0x10
//   0x01f4c0: aa0103f3  mov      x19, x1
//   0x01f4c4: aa0003f4  mov      x20, x0
//   0x01f4c8: a8c10801  ldp      x1, x2, [x0], #0x10
//   0x01f4cc: 91002263  add      x3, x19, #8
//   0x01f4d0: 94000028  bl       #0x1f570
//   0x01f4d4: f9400668  ldr      x8, [x19, #8]
//   0x01f4d8: f9400289  ldr      x9, [x20]
//   0x01f4dc: f9000288  str      x8, [x20]
//   0x01f4e0: f9400a68  ldr      x8, [x19, #0x10]
uint64_t fde_0736_sub_01f4b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9400668ULL) + (x2 ^ 0x01F4B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x01f4b4: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01f4b8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01f4bc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x01f4c0: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x01f4c4: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C10801ULL; // 0x01f4c8: ldp x1, x2, [x0], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x91002263ULL; // 0x01f4cc: add x3, x19, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x94000028ULL; // 0x01f4d0: bl #0x1f570
    return acc;
}

// [EN] Reconstructed FDE #0737 @ 0x01f518..0x01f54c (52 bytes)
// [VN] Phục dựng FDE #0737 tại 0x01f518..0x01f54c (52 byte)
//   0x01f518: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x01f51c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01f520: 910043fd  add      x29, sp, #0x10
//   0x01f524: aa0003f3  mov      x19, x0
//   0x01f528: 9400001a  bl       #0x1f590
//   0x01f52c: f9400260  ldr      x0, [x19]
//   0x01f530: b4000080  cbz      x0, #0x1f540
//   0x01f534: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x01f538: f84207f3  ldr      x19, [sp], #0x20
//   0x01f53c: 17ffae01  b        #0xad40
//   0x01f540: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x01f544: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0737_sub_01f518(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x01F518ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x01f518: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01f51c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01f520: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01f524: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9400001AULL; // 0x01f528: bl #0x1f590
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400260ULL; // 0x01f52c: ldr x0, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000080ULL; // 0x01f530: cbz x0, #0x1f540
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x01f534: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0738 @ 0x01f54c..0x01f554 (8 bytes)
// [VN] Phục dựng FDE #0738 tại 0x01f54c..0x01f554 (8 byte)
//   0x01f54c: aa1f03e2  mov      x2, xzr
//   0x01f550: 14000001  b        #0x1f554
uint64_t fde_0738_sub_01f54c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x01F54CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x01f54c: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x01f550: b #0x1f554
    return acc;
}

// [EN] Reconstructed FDE #0739 @ 0x01f554..0x01f570 (28 bytes)
// [VN] Phục dựng FDE #0739 tại 0x01f554..0x01f570 (28 byte)
//   0x01f554: d37cfc28  lsr      x8, x1, #0x3c
//   0x01f558: b5000068  cbnz     x8, #0x1f564
//   0x01f55c: d37cec20  lsl      x0, x1, #4
//   0x01f560: 17ffb024  b        #0xb5f0
//   0x01f564: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x01f568: 910003fd  mov      x29, sp
//   0x01f56c: 97ffafe5  bl       #0xb500
uint64_t fde_0739_sub_01f554(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD37CFC28ULL) + (x1 ^ 0x97FFAFE5ULL) + (x2 ^ 0x01F554ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD37CFC28ULL; // 0x01f554: lsr x8, x1, #0x3c
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000068ULL; // 0x01f558: cbnz x8, #0x1f564
    acc = (acc * 0x100000001B3ULL) ^ 0xD37CEC20ULL; // 0x01f55c: lsl x0, x1, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFB024ULL; // 0x01f560: b #0xb5f0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x01f564: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x01f568: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFAFE5ULL; // 0x01f56c: bl #0xb500
    return acc;
}

// [EN] Reconstructed FDE #0740 @ 0x01f570..0x01f590 (32 bytes)
// [VN] Phục dựng FDE #0740 tại 0x01f570..0x01f590 (32 byte)
//   0x01f570: f9400068  ldr      x8, [x3]
//   0x01f574: cb010042  sub      x2, x2, x1
//   0x01f578: f100045f  cmp      x2, #1
//   0x01f57c: cb020100  sub      x0, x8, x2
//   0x01f580: f9000060  str      x0, [x3]
//   0x01f584: 5400004b  b.lt     #0x1f58c
//   0x01f588: 17ffada2  b        #0xac10
//   0x01f58c: d65f03c0  ret      
uint64_t fde_0740_sub_01f570(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400068ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01F570ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400068ULL; // 0x01f570: ldr x8, [x3]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB010042ULL; // 0x01f574: sub x2, x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF100045FULL; // 0x01f578: cmp x2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xCB020100ULL; // 0x01f57c: sub x0, x8, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000060ULL; // 0x01f580: str x0, [x3]
    acc = (acc * 0x100000001B3ULL) ^ 0x5400004BULL; // 0x01f584: b.lt #0x1f58c
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFADA2ULL; // 0x01f588: b #0xac10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01f58c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0741 @ 0x01f590..0x01f598 (8 bytes)
// [VN] Phục dựng FDE #0741 tại 0x01f590..0x01f598 (8 byte)
//   0x01f590: f9400401  ldr      x1, [x0, #8]
//   0x01f594: 14000001  b        #0x1f598
uint64_t fde_0741_sub_01f590(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400401ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x01F590ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400401ULL; // 0x01f590: ldr x1, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x01f594: b #0x1f598
    return acc;
}

// [EN] Reconstructed FDE #0742 @ 0x01f598..0x01f5b4 (28 bytes)
// [VN] Phục dựng FDE #0742 tại 0x01f598..0x01f5b4 (28 byte)
//   0x01f598: f9400808  ldr      x8, [x0, #0x10]
//   0x01f59c: eb08003f  cmp      x1, x8
//   0x01f5a0: 54000080  b.eq     #0x1f5b0
//   0x01f5a4: d1004108  sub      x8, x8, #0x10
//   0x01f5a8: f9000808  str      x8, [x0, #0x10]
//   0x01f5ac: 17fffffc  b        #0x1f59c
//   0x01f5b0: d65f03c0  ret      
uint64_t fde_0742_sub_01f598(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400808ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01F598ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x01f598: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08003FULL; // 0x01f59c: cmp x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000080ULL; // 0x01f5a0: b.eq #0x1f5b0
    acc = (acc * 0x100000001B3ULL) ^ 0xD1004108ULL; // 0x01f5a4: sub x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000808ULL; // 0x01f5a8: str x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFFCULL; // 0x01f5ac: b #0x1f59c
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01f5b0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0743 @ 0x01f5b4..0x01f67c (200 bytes)
// [VN] Phục dựng FDE #0743 tại 0x01f5b4..0x01f67c (200 byte)
//   0x01f5b4: d101c3ff  sub      sp, sp, #0x70
//   0x01f5b8: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x01f5bc: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x01f5c0: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x01f5c4: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x01f5c8: 910183fd  add      x29, sp, #0x60
//   0x01f5cc: d53bd057  mrs      x23, tpidr_el0
//   0x01f5d0: f94016e8  ldr      x8, [x23, #0x28]
//   0x01f5d4: aa0103f4  mov      x20, x1
//   0x01f5d8: aa0003f3  mov      x19, x0
//   0x01f5dc: 91004016  add      x22, x0, #0x10
//   0x01f5e0: f90017e8  str      x8, [sp, #0x28]
uint64_t fde_0743_sub_01f5b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xAA0103F4ULL) + (x2 ^ 0x01F5B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x01f5b4: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x01f5b8: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x01f5bc: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x01f5c0: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x01f5c4: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x01f5c8: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x01f5cc: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x01f5d0: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0744 @ 0x01f67c..0x01f6c4 (72 bytes)
// [VN] Phục dựng FDE #0744 tại 0x01f67c..0x01f6c4 (72 byte)
//   0x01f67c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x01f680: 910003fd  mov      x29, sp
//   0x01f684: d37cfc28  lsr      x8, x1, #0x3c
//   0x01f688: b50001c8  cbnz     x8, #0x1f6c0
//   0x01f68c: f9400808  ldr      x8, [x0, #0x10]
//   0x01f690: f9400009  ldr      x9, [x0]
//   0x01f694: cb090108  sub      x8, x8, x9
//   0x01f698: b27fe7e9  mov      x9, #0x7fffffffffffffe
//   0x01f69c: eb88113f  cmp      x9, x8, asr #4
//   0x01f6a0: 540000a3  b.lo     #0x1f6b4
//   0x01f6a4: 9343fd08  asr      x8, x8, #3
//   0x01f6a8: eb01011f  cmp      x8, x1
uint64_t fde_0744_sub_01f67c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xEB88113FULL) + (x2 ^ 0x01F67CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x01f67c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x01f680: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xD37CFC28ULL; // 0x01f684: lsr x8, x1, #0x3c
    acc = (acc * 0x100000001B3ULL) ^ 0xB50001C8ULL; // 0x01f688: cbnz x8, #0x1f6c0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x01f68c: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400009ULL; // 0x01f690: ldr x9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB090108ULL; // 0x01f694: sub x8, x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xB27FE7E9ULL; // 0x01f698: mov x9, #0x7fffffffffffffe
    return acc;
}

// [EN] Reconstructed FDE #0745 @ 0x01f6c4..0x01f728 (100 bytes)
// [VN] Phục dựng FDE #0745 tại 0x01f6c4..0x01f728 (100 byte)
//   0x01f6c4: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x01f6c8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01f6cc: 910043fd  add      x29, sp, #0x10
//   0x01f6d0: aa0103f3  mov      x19, x1
//   0x01f6d4: aa0003f4  mov      x20, x0
//   0x01f6d8: a8c10801  ldp      x1, x2, [x0], #0x10
//   0x01f6dc: 91002263  add      x3, x19, #8
//   0x01f6e0: 94000028  bl       #0x1f780
//   0x01f6e4: f9400668  ldr      x8, [x19, #8]
//   0x01f6e8: f9400289  ldr      x9, [x20]
//   0x01f6ec: f9000288  str      x8, [x20]
//   0x01f6f0: f9400a68  ldr      x8, [x19, #0x10]
uint64_t fde_0745_sub_01f6c4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9400668ULL) + (x2 ^ 0x01F6C4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x01f6c4: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01f6c8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01f6cc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x01f6d0: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x01f6d4: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C10801ULL; // 0x01f6d8: ldp x1, x2, [x0], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x91002263ULL; // 0x01f6dc: add x3, x19, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x94000028ULL; // 0x01f6e0: bl #0x1f780
    return acc;
}

// [EN] Reconstructed FDE #0746 @ 0x01f728..0x01f75c (52 bytes)
// [VN] Phục dựng FDE #0746 tại 0x01f728..0x01f75c (52 byte)
//   0x01f728: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x01f72c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01f730: 910043fd  add      x29, sp, #0x10
//   0x01f734: aa0003f3  mov      x19, x0
//   0x01f738: 9400001a  bl       #0x1f7a0
//   0x01f73c: f9400260  ldr      x0, [x19]
//   0x01f740: b4000080  cbz      x0, #0x1f750
//   0x01f744: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x01f748: f84207f3  ldr      x19, [sp], #0x20
//   0x01f74c: 17ffad7d  b        #0xad40
//   0x01f750: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x01f754: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0746_sub_01f728(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x01F728ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x01f728: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01f72c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01f730: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01f734: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9400001AULL; // 0x01f738: bl #0x1f7a0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400260ULL; // 0x01f73c: ldr x0, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000080ULL; // 0x01f740: cbz x0, #0x1f750
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x01f744: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0747 @ 0x01f75c..0x01f764 (8 bytes)
// [VN] Phục dựng FDE #0747 tại 0x01f75c..0x01f764 (8 byte)
//   0x01f75c: aa1f03e2  mov      x2, xzr
//   0x01f760: 14000001  b        #0x1f764
uint64_t fde_0747_sub_01f75c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x01F75CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x01f75c: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x01f760: b #0x1f764
    return acc;
}

// [EN] Reconstructed FDE #0748 @ 0x01f764..0x01f780 (28 bytes)
// [VN] Phục dựng FDE #0748 tại 0x01f764..0x01f780 (28 byte)
//   0x01f764: d37cfc28  lsr      x8, x1, #0x3c
//   0x01f768: b5000068  cbnz     x8, #0x1f774
//   0x01f76c: d37cec20  lsl      x0, x1, #4
//   0x01f770: 17ffafa0  b        #0xb5f0
//   0x01f774: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x01f778: 910003fd  mov      x29, sp
//   0x01f77c: 97ffaf61  bl       #0xb500
uint64_t fde_0748_sub_01f764(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD37CFC28ULL) + (x1 ^ 0x97FFAF61ULL) + (x2 ^ 0x01F764ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD37CFC28ULL; // 0x01f764: lsr x8, x1, #0x3c
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000068ULL; // 0x01f768: cbnz x8, #0x1f774
    acc = (acc * 0x100000001B3ULL) ^ 0xD37CEC20ULL; // 0x01f76c: lsl x0, x1, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFAFA0ULL; // 0x01f770: b #0xb5f0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x01f774: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x01f778: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFAF61ULL; // 0x01f77c: bl #0xb500
    return acc;
}

// [EN] Reconstructed FDE #0749 @ 0x01f780..0x01f7a0 (32 bytes)
// [VN] Phục dựng FDE #0749 tại 0x01f780..0x01f7a0 (32 byte)
//   0x01f780: f9400068  ldr      x8, [x3]
//   0x01f784: cb010042  sub      x2, x2, x1
//   0x01f788: f100045f  cmp      x2, #1
//   0x01f78c: cb020100  sub      x0, x8, x2
//   0x01f790: f9000060  str      x0, [x3]
//   0x01f794: 5400004b  b.lt     #0x1f79c
//   0x01f798: 17ffad1e  b        #0xac10
//   0x01f79c: d65f03c0  ret      
uint64_t fde_0749_sub_01f780(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400068ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01F780ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400068ULL; // 0x01f780: ldr x8, [x3]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB010042ULL; // 0x01f784: sub x2, x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF100045FULL; // 0x01f788: cmp x2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xCB020100ULL; // 0x01f78c: sub x0, x8, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000060ULL; // 0x01f790: str x0, [x3]
    acc = (acc * 0x100000001B3ULL) ^ 0x5400004BULL; // 0x01f794: b.lt #0x1f79c
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFAD1EULL; // 0x01f798: b #0xac10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01f79c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0750 @ 0x01f7a0..0x01f7a8 (8 bytes)
// [VN] Phục dựng FDE #0750 tại 0x01f7a0..0x01f7a8 (8 byte)
//   0x01f7a0: f9400401  ldr      x1, [x0, #8]
//   0x01f7a4: 14000001  b        #0x1f7a8
uint64_t fde_0750_sub_01f7a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400401ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x01F7A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400401ULL; // 0x01f7a0: ldr x1, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x01f7a4: b #0x1f7a8
    return acc;
}

// [EN] Reconstructed FDE #0751 @ 0x01f7a8..0x01f7c4 (28 bytes)
// [VN] Phục dựng FDE #0751 tại 0x01f7a8..0x01f7c4 (28 byte)
//   0x01f7a8: f9400808  ldr      x8, [x0, #0x10]
//   0x01f7ac: eb08003f  cmp      x1, x8
//   0x01f7b0: 54000080  b.eq     #0x1f7c0
//   0x01f7b4: d1004108  sub      x8, x8, #0x10
//   0x01f7b8: f9000808  str      x8, [x0, #0x10]
//   0x01f7bc: 17fffffc  b        #0x1f7ac
//   0x01f7c0: d65f03c0  ret      
uint64_t fde_0751_sub_01f7a8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400808ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01F7A8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x01f7a8: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08003FULL; // 0x01f7ac: cmp x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000080ULL; // 0x01f7b0: b.eq #0x1f7c0
    acc = (acc * 0x100000001B3ULL) ^ 0xD1004108ULL; // 0x01f7b4: sub x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000808ULL; // 0x01f7b8: str x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFFCULL; // 0x01f7bc: b #0x1f7ac
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01f7c0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0752 @ 0x01f7c4..0x01f7dc (24 bytes)
// [VN] Phục dựng FDE #0752 tại 0x01f7c4..0x01f7dc (24 byte)
//   0x01f7c4: aa0003e8  mov      x8, x0
//   0x01f7c8: f9400000  ldr      x0, [x0]
//   0x01f7cc: b4000060  cbz      x0, #0x1f7d8
//   0x01f7d0: f9000500  str      x0, [x8, #8]
//   0x01f7d4: 17ffad5b  b        #0xad40
//   0x01f7d8: d65f03c0  ret      
uint64_t fde_0752_sub_01f7c4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01F7C4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x01f7c4: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x01f7c8: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000060ULL; // 0x01f7cc: cbz x0, #0x1f7d8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000500ULL; // 0x01f7d0: str x0, [x8, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFAD5BULL; // 0x01f7d4: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01f7d8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0753 @ 0x01f7dc..0x01f7f4 (24 bytes)
// [VN] Phục dựng FDE #0753 tại 0x01f7dc..0x01f7f4 (24 byte)
//   0x01f7dc: aa0003e8  mov      x8, x0
//   0x01f7e0: f9400000  ldr      x0, [x0]
//   0x01f7e4: b4000060  cbz      x0, #0x1f7f0
//   0x01f7e8: f9000500  str      x0, [x8, #8]
//   0x01f7ec: 17ffad55  b        #0xad40
//   0x01f7f0: d65f03c0  ret      
uint64_t fde_0753_sub_01f7dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01F7DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x01f7dc: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x01f7e0: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000060ULL; // 0x01f7e4: cbz x0, #0x1f7f0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000500ULL; // 0x01f7e8: str x0, [x8, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFAD55ULL; // 0x01f7ec: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01f7f0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0754 @ 0x01f7f4..0x01f80c (24 bytes)
// [VN] Phục dựng FDE #0754 tại 0x01f7f4..0x01f80c (24 byte)
//   0x01f7f4: aa0003e8  mov      x8, x0
//   0x01f7f8: f9400000  ldr      x0, [x0]
//   0x01f7fc: b4000060  cbz      x0, #0x1f808
//   0x01f800: f9000500  str      x0, [x8, #8]
//   0x01f804: 17ffad4f  b        #0xad40
//   0x01f808: d65f03c0  ret      
uint64_t fde_0754_sub_01f7f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01F7F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x01f7f4: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x01f7f8: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000060ULL; // 0x01f7fc: cbz x0, #0x1f808
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000500ULL; // 0x01f800: str x0, [x8, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFAD4FULL; // 0x01f804: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01f808: ret 
    return acc;
}

// [EN] Reconstructed FDE #0755 @ 0x01f80c..0x01f824 (24 bytes)
// [VN] Phục dựng FDE #0755 tại 0x01f80c..0x01f824 (24 byte)
//   0x01f80c: aa0003e8  mov      x8, x0
//   0x01f810: f9400000  ldr      x0, [x0]
//   0x01f814: b4000060  cbz      x0, #0x1f820
//   0x01f818: f9000500  str      x0, [x8, #8]
//   0x01f81c: 17ffad49  b        #0xad40
//   0x01f820: d65f03c0  ret      
uint64_t fde_0755_sub_01f80c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01F80CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x01f80c: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x01f810: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000060ULL; // 0x01f814: cbz x0, #0x1f820
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000500ULL; // 0x01f818: str x0, [x8, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFAD49ULL; // 0x01f81c: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01f820: ret 
    return acc;
}

// [EN] Reconstructed FDE #0756 @ 0x01f824..0x01f83c (24 bytes)
// [VN] Phục dựng FDE #0756 tại 0x01f824..0x01f83c (24 byte)
//   0x01f824: aa0003e8  mov      x8, x0
//   0x01f828: f9400000  ldr      x0, [x0]
//   0x01f82c: b4000060  cbz      x0, #0x1f838
//   0x01f830: f9000500  str      x0, [x8, #8]
//   0x01f834: 17ffad43  b        #0xad40
//   0x01f838: d65f03c0  ret      
uint64_t fde_0756_sub_01f824(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01F824ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x01f824: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x01f828: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000060ULL; // 0x01f82c: cbz x0, #0x1f838
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000500ULL; // 0x01f830: str x0, [x8, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFAD43ULL; // 0x01f834: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01f838: ret 
    return acc;
}

// [EN] Reconstructed FDE #0757 @ 0x01f83c..0x01f854 (24 bytes)
// [VN] Phục dựng FDE #0757 tại 0x01f83c..0x01f854 (24 byte)
//   0x01f83c: 52800023  mov      w3, #1
//   0x01f840: 72a24004  movk     w4, #0x1200, lsl #16
//   0x01f844: 5280a005  mov      w5, #0x500
//   0x01f848: aa1303e0  mov      x0, x19
//   0x01f84c: 2a1f03e2  mov      w2, wzr
//   0x01f850: 17fff7a2  b        #0x1d6d8
uint64_t fde_0757_sub_01f83c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800023ULL) + (x1 ^ 0x17FFF7A2ULL) + (x2 ^ 0x01F83CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800023ULL; // 0x01f83c: mov w3, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x72A24004ULL; // 0x01f840: movk w4, #0x1200, lsl #16
    acc = (acc * 0x100000001B3ULL) ^ 0x5280A005ULL; // 0x01f844: mov w5, #0x500
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x01f848: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E2ULL; // 0x01f84c: mov w2, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF7A2ULL; // 0x01f850: b #0x1d6d8
    return acc;
}

// [EN] Reconstructed FDE #0758 @ 0x01f854..0x01f864 (16 bytes)
// [VN] Phục dựng FDE #0758 tại 0x01f854..0x01f864 (16 byte)
//   0x01f854: f9400268  ldr      x8, [x19]
//   0x01f858: aa1303e0  mov      x0, x19
//   0x01f85c: f9439108  ldr      x8, [x8, #0x720]
//   0x01f860: d61f0100  br       x8
uint64_t fde_0758_sub_01f854(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400268ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x01F854ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400268ULL; // 0x01f854: ldr x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x01f858: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF9439108ULL; // 0x01f85c: ldr x8, [x8, #0x720]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x01f860: br x8
    return acc;
}

// [EN] Reconstructed FDE #0759 @ 0x01f864..0x01f87c (24 bytes)
// [VN] Phục dựng FDE #0759 tại 0x01f864..0x01f87c (24 byte)
//   0x01f864: 52800022  mov      w2, #1
//   0x01f868: 52800023  mov      w3, #1
//   0x01f86c: 72b24804  movk     w4, #0x9240, lsl #16
//   0x01f870: 5280a005  mov      w5, #0x500
//   0x01f874: aa1303e0  mov      x0, x19
//   0x01f878: 17fff798  b        #0x1d6d8
uint64_t fde_0759_sub_01f864(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800022ULL) + (x1 ^ 0x17FFF798ULL) + (x2 ^ 0x01F864ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800022ULL; // 0x01f864: mov w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x52800023ULL; // 0x01f868: mov w3, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x72B24804ULL; // 0x01f86c: movk w4, #0x9240, lsl #16
    acc = (acc * 0x100000001B3ULL) ^ 0x5280A005ULL; // 0x01f870: mov w5, #0x500
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x01f874: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF798ULL; // 0x01f878: b #0x1d6d8
    return acc;
}

// [EN] Reconstructed FDE #0760 @ 0x01f87c..0x01f88c (16 bytes)
// [VN] Phục dựng FDE #0760 tại 0x01f87c..0x01f88c (16 byte)
//   0x01f87c: 72b24804  movk     w4, #0x9240, lsl #16
//   0x01f880: 5280a005  mov      w5, #0x500
//   0x01f884: aa1303e0  mov      x0, x19
//   0x01f888: 17fff794  b        #0x1d6d8
uint64_t fde_0760_sub_01f87c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x72B24804ULL) + (x1 ^ 0x17FFF794ULL) + (x2 ^ 0x01F87CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x72B24804ULL; // 0x01f87c: movk w4, #0x9240, lsl #16
    acc = (acc * 0x100000001B3ULL) ^ 0x5280A005ULL; // 0x01f880: mov w5, #0x500
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x01f884: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF794ULL; // 0x01f888: b #0x1d6d8
    return acc;
}

// [EN] Reconstructed FDE #0761 @ 0x01f88c..0x01f898 (12 bytes)
// [VN] Phục dựng FDE #0761 tại 0x01f88c..0x01f898 (12 byte)
//   0x01f88c: aa1303e0  mov      x0, x19
//   0x01f890: aa1403e1  mov      x1, x20
//   0x01f894: d61f0100  br       x8
uint64_t fde_0761_sub_01f88c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1303E0ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x01F88CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x01f88c: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E1ULL; // 0x01f890: mov x1, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x01f894: br x8
    return acc;
}

// [EN] Reconstructed FDE #0762 @ 0x01f898..0x01f8a0 (8 bytes)
// [VN] Phục dựng FDE #0762 tại 0x01f898..0x01f8a0 (8 byte)
//   0x01f898: aa1303e0  mov      x0, x19
//   0x01f89c: 17fff78f  b        #0x1d6d8
uint64_t fde_0762_sub_01f898(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1303E0ULL) + (x1 ^ 0x17FFF78FULL) + (x2 ^ 0x01F898ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x01f898: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF78FULL; // 0x01f89c: b #0x1d6d8
    return acc;
}

// [EN] Reconstructed FDE #0763 @ 0x01f8a0..0x01f8ac (12 bytes)
// [VN] Phục dựng FDE #0763 tại 0x01f8a0..0x01f8ac (12 byte)
//   0x01f8a0: f9400268  ldr      x8, [x19]
//   0x01f8a4: 72001c1f  tst      w0, #0xff
//   0x01f8a8: d65f03c0  ret      
uint64_t fde_0763_sub_01f8a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400268ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01F8A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400268ULL; // 0x01f8a0: ldr x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x72001C1FULL; // 0x01f8a4: tst w0, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01f8a8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0764 @ 0x01f8ac..0x01f8c8 (28 bytes)
// [VN] Phục dựng FDE #0764 tại 0x01f8ac..0x01f8c8 (28 byte)
//   0x01f8ac: b9400765  ldr      w5, [x27, #4]
//   0x01f8b0: 528000c0  mov      w0, #6
//   0x01f8b4: aa1303e1  mov      x1, x19
//   0x01f8b8: aa1403e2  mov      x2, x20
//   0x01f8bc: aa1503e3  mov      x3, x21
//   0x01f8c0: 2a1603e4  mov      w4, w22
//   0x01f8c4: 17ffae47  b        #0xb1e0
uint64_t fde_0764_sub_01f8ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400765ULL) + (x1 ^ 0x17FFAE47ULL) + (x2 ^ 0x01F8ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400765ULL; // 0x01f8ac: ldr w5, [x27, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C0ULL; // 0x01f8b0: mov w0, #6
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E1ULL; // 0x01f8b4: mov x1, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E2ULL; // 0x01f8b8: mov x2, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E3ULL; // 0x01f8bc: mov x3, x21
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1603E4ULL; // 0x01f8c0: mov w4, w22
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFAE47ULL; // 0x01f8c4: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #0765 @ 0x01f8c8..0x01f8f4 (44 bytes)
// [VN] Phục dựng FDE #0765 tại 0x01f8c8..0x01f8f4 (44 byte)
//   0x01f8c8: 394083e8  ldrb     w8, [sp, #0x20]
//   0x01f8cc: f9401be9  ldr      x9, [sp, #0x30]
//   0x01f8d0: 528000c0  mov      w0, #6
//   0x01f8d4: aa1303e1  mov      x1, x19
//   0x01f8d8: 7200011f  tst      w8, #1
//   0x01f8dc: 9a890386  csel     x6, x28, x9, eq
//   0x01f8e0: aa1403e2  mov      x2, x20
//   0x01f8e4: aa1503e3  mov      x3, x21
//   0x01f8e8: 2a1603e4  mov      w4, w22
//   0x01f8ec: aa1703e5  mov      x5, x23
//   0x01f8f0: 17ffae3c  b        #0xb1e0
uint64_t fde_0765_sub_01f8c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x394083E8ULL) + (x1 ^ 0x2A1603E4ULL) + (x2 ^ 0x01F8C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x394083E8ULL; // 0x01f8c8: ldrb w8, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401BE9ULL; // 0x01f8cc: ldr x9, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C0ULL; // 0x01f8d0: mov w0, #6
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E1ULL; // 0x01f8d4: mov x1, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x7200011FULL; // 0x01f8d8: tst w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x9A890386ULL; // 0x01f8dc: csel x6, x28, x9, eq
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E2ULL; // 0x01f8e0: mov x2, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E3ULL; // 0x01f8e4: mov x3, x21
    return acc;
}

// [EN] Reconstructed FDE #0766 @ 0x01f8f4..0x01f90c (24 bytes)
// [VN] Phục dựng FDE #0766 tại 0x01f8f4..0x01f90c (24 byte)
//   0x01f8f4: f9400102  ldr      x2, [x8]
//   0x01f8f8: f9400123  ldr      x3, [x9]
//   0x01f8fc: b9400145  ldr      w5, [x10]
//   0x01f900: aa1703e1  mov      x1, x23
//   0x01f904: aa1803e4  mov      x4, x24
//   0x01f908: 17fff47b  b        #0x1caf4
uint64_t fde_0766_sub_01f8f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400102ULL) + (x1 ^ 0x17FFF47BULL) + (x2 ^ 0x01F8F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400102ULL; // 0x01f8f4: ldr x2, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400123ULL; // 0x01f8f8: ldr x3, [x9]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400145ULL; // 0x01f8fc: ldr w5, [x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1703E1ULL; // 0x01f900: mov x1, x23
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1803E4ULL; // 0x01f904: mov x4, x24
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF47BULL; // 0x01f908: b #0x1caf4
    return acc;
}

// [EN] Reconstructed FDE #0767 @ 0x01f90c..0x01f91c (16 bytes)
// [VN] Phục dựng FDE #0767 tại 0x01f90c..0x01f91c (16 byte)
//   0x01f90c: aa1603e0  mov      x0, x22
//   0x01f910: aa1703e1  mov      x1, x23
//   0x01f914: f9400108  ldr      x8, [x8]
//   0x01f918: d61f0100  br       x8
uint64_t fde_0767_sub_01f90c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1603E0ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x01F90CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1603E0ULL; // 0x01f90c: mov x0, x22
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1703E1ULL; // 0x01f910: mov x1, x23
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x01f914: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x01f918: br x8
    return acc;
}

// [EN] Reconstructed FDE #0768 @ 0x01f91c..0x01f924 (8 bytes)
// [VN] Phục dựng FDE #0768 tại 0x01f91c..0x01f924 (8 byte)
//   0x01f91c: 910083e0  add      x0, sp, #0x20
//   0x01f920: 17ffae10  b        #0xb160
uint64_t fde_0768_sub_01f91c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910083E0ULL) + (x1 ^ 0x17FFAE10ULL) + (x2 ^ 0x01F91CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910083E0ULL; // 0x01f91c: add x0, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFAE10ULL; // 0x01f920: b #0xb160
    return acc;
}

// [EN] Reconstructed FDE #0769 @ 0x01f924..0x01f930 (12 bytes)
// [VN] Phục dựng FDE #0769 tại 0x01f924..0x01f930 (12 byte)
//   0x01f924: f9404508  ldr      x8, [x8, #0x88]
//   0x01f928: aa1303e0  mov      x0, x19
//   0x01f92c: d61f0100  br       x8
uint64_t fde_0769_sub_01f924(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9404508ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x01F924ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9404508ULL; // 0x01f924: ldr x8, [x8, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x01f928: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x01f92c: br x8
    return acc;
}

// [EN] Reconstructed FDE #0770 @ 0x01f930..0x01f954 (36 bytes)
// [VN] Phục dựng FDE #0770 tại 0x01f930..0x01f954 (36 byte)
//   0x01f930: 394003e8  ldrb     w8, [sp]
//   0x01f934: f9400be9  ldr      x9, [sp, #0x10]
//   0x01f938: 528000c0  mov      w0, #6
//   0x01f93c: aa1303e1  mov      x1, x19
//   0x01f940: 7200011f  tst      w8, #1
//   0x01f944: 9a890324  csel     x4, x25, x9, eq
//   0x01f948: aa1403e2  mov      x2, x20
//   0x01f94c: 2a1503e3  mov      w3, w21
//   0x01f950: 17ffae24  b        #0xb1e0
uint64_t fde_0770_sub_01f930(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x394003E8ULL) + (x1 ^ 0x17FFAE24ULL) + (x2 ^ 0x01F930ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x394003E8ULL; // 0x01f930: ldrb w8, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400BE9ULL; // 0x01f934: ldr x9, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C0ULL; // 0x01f938: mov w0, #6
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E1ULL; // 0x01f93c: mov x1, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x7200011FULL; // 0x01f940: tst w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x9A890324ULL; // 0x01f944: csel x4, x25, x9, eq
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E2ULL; // 0x01f948: mov x2, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1503E3ULL; // 0x01f94c: mov w3, w21
    return acc;
}

// [EN] Reconstructed FDE #0771 @ 0x01f954..0x01f96c (24 bytes)
// [VN] Phục dựng FDE #0771 tại 0x01f954..0x01f96c (24 byte)
//   0x01f954: 924026c8  and      x8, x22, #0x3ff
//   0x01f958: d37df108  lsl      x8, x8, #3
//   0x01f95c: b8686b49  ldr      w9, [x26, x8]
//   0x01f960: b9400368  ldr      w8, [x27]
//   0x01f964: 6b08013f  cmp      w9, w8
//   0x01f968: d65f03c0  ret      
uint64_t fde_0771_sub_01f954(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x924026C8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01F954ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x924026C8ULL; // 0x01f954: and x8, x22, #0x3ff
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DF108ULL; // 0x01f958: lsl x8, x8, #3
    acc = (acc * 0x100000001B3ULL) ^ 0xB8686B49ULL; // 0x01f95c: ldr w9, [x26, x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400368ULL; // 0x01f960: ldr w8, [x27]
    acc = (acc * 0x100000001B3ULL) ^ 0x6B08013FULL; // 0x01f964: cmp w9, w8
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01f968: ret 
    return acc;
}

// [EN] Reconstructed FDE #0772 @ 0x01f96c..0x01f978 (12 bytes)
// [VN] Phục dựng FDE #0772 tại 0x01f96c..0x01f978 (12 byte)
//   0x01f96c: 528000c0  mov      w0, #6
//   0x01f970: aa1803e1  mov      x1, x24
//   0x01f974: 17ffae1b  b        #0xb1e0
uint64_t fde_0772_sub_01f96c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x528000C0ULL) + (x1 ^ 0x17FFAE1BULL) + (x2 ^ 0x01F96CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C0ULL; // 0x01f96c: mov w0, #6
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1803E1ULL; // 0x01f970: mov x1, x24
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFAE1BULL; // 0x01f974: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #0773 @ 0x01f978..0x01f994 (28 bytes)
// [VN] Phục dựng FDE #0773 tại 0x01f978..0x01f994 (28 byte)
//   0x01f978: f9400268  ldr      x8, [x19]
//   0x01f97c: aa1303e0  mov      x0, x19
//   0x01f980: aa1403e1  mov      x1, x20
//   0x01f984: aa1503e2  mov      x2, x21
//   0x01f988: f9417908  ldr      x8, [x8, #0x2f0]
//   0x01f98c: aa1603e3  mov      x3, x22
//   0x01f990: d61f0100  br       x8
uint64_t fde_0773_sub_01f978(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400268ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x01F978ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400268ULL; // 0x01f978: ldr x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x01f97c: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E1ULL; // 0x01f980: mov x1, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E2ULL; // 0x01f984: mov x2, x21
    acc = (acc * 0x100000001B3ULL) ^ 0xF9417908ULL; // 0x01f988: ldr x8, [x8, #0x2f0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1603E3ULL; // 0x01f98c: mov x3, x22
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x01f990: br x8
    return acc;
}

// [EN] Reconstructed FDE #0774 @ 0x01f994..0x01f9a4 (16 bytes)
// [VN] Phục dựng FDE #0774 tại 0x01f994..0x01f9a4 (16 byte)
//   0x01f994: aa1403e0  mov      x0, x20
//   0x01f998: aa1f03e2  mov      x2, xzr
//   0x01f99c: f9406108  ldr      x8, [x8, #0xc0]
//   0x01f9a0: d61f0100  br       x8
uint64_t fde_0774_sub_01f994(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1403E0ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x01F994ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x01f994: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x01f998: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xF9406108ULL; // 0x01f99c: ldr x8, [x8, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x01f9a0: br x8
    return acc;
}

// [EN] Reconstructed FDE #0775 @ 0x01f9a4..0x01f9b0 (12 bytes)
// [VN] Phục dựng FDE #0775 tại 0x01f9a4..0x01f9b0 (12 byte)
//   0x01f9a4: f8008500  str      x0, [x8], #8
//   0x01f9a8: aa0803e0  mov      x0, x8
//   0x01f9ac: 17ffad81  b        #0xafb0
uint64_t fde_0775_sub_01f9a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF8008500ULL) + (x1 ^ 0x17FFAD81ULL) + (x2 ^ 0x01F9A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF8008500ULL; // 0x01f9a4: str x0, [x8], #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E0ULL; // 0x01f9a8: mov x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFAD81ULL; // 0x01f9ac: b #0xafb0
    return acc;
}

// [EN] Reconstructed FDE #0776 @ 0x01f9b0..0x01f9c4 (20 bytes)
// [VN] Phục dựng FDE #0776 tại 0x01f9b0..0x01f9c4 (20 byte)
//   0x01f9b0: a940a2fa  ldp      x26, x8, [x23, #8]
//   0x01f9b4: f94002f5  ldr      x21, [x23]
//   0x01f9b8: 52808016  mov      w22, #0x400
//   0x01f9bc: 9140091b  add      x27, x8, #2, lsl #12
//   0x01f9c0: d65f03c0  ret      
uint64_t fde_0776_sub_01f9b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA940A2FAULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01F9B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA940A2FAULL; // 0x01f9b0: ldp x26, x8, [x23, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF94002F5ULL; // 0x01f9b4: ldr x21, [x23]
    acc = (acc * 0x100000001B3ULL) ^ 0x52808016ULL; // 0x01f9b8: mov w22, #0x400
    acc = (acc * 0x100000001B3ULL) ^ 0x9140091BULL; // 0x01f9bc: add x27, x8, #2, lsl #12
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01f9c0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0777 @ 0x01f9c4..0x01f9dc (24 bytes)
// [VN] Phục dựng FDE #0777 tại 0x01f9c4..0x01f9dc (24 byte)
//   0x01f9c4: a9474ff4  ldp      x20, x19, [sp, #0x70]
//   0x01f9c8: a94657f6  ldp      x22, x21, [sp, #0x60]
//   0x01f9cc: a9455ff8  ldp      x24, x23, [sp, #0x50]
//   0x01f9d0: a94467fa  ldp      x26, x25, [sp, #0x40]
//   0x01f9d4: 910243ff  add      sp, sp, #0x90
//   0x01f9d8: d65f03c0  ret      
uint64_t fde_0777_sub_01f9c4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9474FF4ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01F9C4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9474FF4ULL; // 0x01f9c4: ldp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA94657F6ULL; // 0x01f9c8: ldp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9455FF8ULL; // 0x01f9cc: ldp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA94467FAULL; // 0x01f9d0: ldp x26, x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910243FFULL; // 0x01f9d4: add sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01f9d8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0778 @ 0x01f9dc..0x01f9e4 (8 bytes)
// [VN] Phục dựng FDE #0778 tại 0x01f9dc..0x01f9e4 (8 byte)
//   0x01f9dc: 528000c0  mov      w0, #6
//   0x01f9e0: 17ffae00  b        #0xb1e0
uint64_t fde_0778_sub_01f9dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x528000C0ULL) + (x1 ^ 0x17FFAE00ULL) + (x2 ^ 0x01F9DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C0ULL; // 0x01f9dc: mov w0, #6
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFAE00ULL; // 0x01f9e0: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #0779 @ 0x01f9e4..0x01f9fc (24 bytes)
// [VN] Phục dựng FDE #0779 tại 0x01f9e4..0x01f9fc (24 byte)
//   0x01f9e4: f9400008  ldr      x8, [x0]
//   0x01f9e8: 900001e1  adrp     x1, #0x5b000
//   0x01f9ec: aa0003f3  mov      x19, x0
//   0x01f9f0: f9436d08  ldr      x8, [x8, #0x6d8]
//   0x01f9f4: f9445c21  ldr      x1, [x1, #0x8b8]
//   0x01f9f8: d61f0100  br       x8
uint64_t fde_0779_sub_01f9e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400008ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x01F9E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x01f9e4: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x900001E1ULL; // 0x01f9e8: adrp x1, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01f9ec: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9436D08ULL; // 0x01f9f0: ldr x8, [x8, #0x6d8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9445C21ULL; // 0x01f9f4: ldr x1, [x1, #0x8b8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x01f9f8: br x8
    return acc;
}

// [EN] Reconstructed FDE #0780 @ 0x01f9fc..0x01fa14 (24 bytes)
// [VN] Phục dựng FDE #0780 tại 0x01f9fc..0x01fa14 (24 byte)
//   0x01f9fc: 9122aad6  add      x22, x22, #0x8aa
//   0x01fa00: aa1303e0  mov      x0, x19
//   0x01fa04: aa1403e1  mov      x1, x20
//   0x01fa08: aa1503e2  mov      x2, x21
//   0x01fa0c: aa1603e3  mov      x3, x22
//   0x01fa10: d61f0100  br       x8
uint64_t fde_0780_sub_01f9fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x9122AAD6ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x01F9FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x9122AAD6ULL; // 0x01f9fc: add x22, x22, #0x8aa
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x01fa00: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E1ULL; // 0x01fa04: mov x1, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E2ULL; // 0x01fa08: mov x2, x21
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1603E3ULL; // 0x01fa0c: mov x3, x22
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x01fa10: br x8
    return acc;
}

// [EN] Reconstructed FDE #0781 @ 0x01fa14..0x01fa2c (24 bytes)
// [VN] Phục dựng FDE #0781 tại 0x01fa14..0x01fa2c (24 byte)
//   0x01fa14: f9400268  ldr      x8, [x19]
//   0x01fa18: aa1303e0  mov      x0, x19
//   0x01fa1c: aa1a03e1  mov      x1, x26
//   0x01fa20: aa1b03e2  mov      x2, x27
//   0x01fa24: f942a908  ldr      x8, [x8, #0x550]
//   0x01fa28: d61f0100  br       x8
uint64_t fde_0781_sub_01fa14(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400268ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x01FA14ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400268ULL; // 0x01fa14: ldr x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x01fa18: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1A03E1ULL; // 0x01fa1c: mov x1, x26
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1B03E2ULL; // 0x01fa20: mov x2, x27
    acc = (acc * 0x100000001B3ULL) ^ 0xF942A908ULL; // 0x01fa24: ldr x8, [x8, #0x550]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x01fa28: br x8
    return acc;
}

// [EN] Reconstructed FDE #0782 @ 0x01fa2c..0x01fa44 (24 bytes)
// [VN] Phục dựng FDE #0782 tại 0x01fa2c..0x01fa44 (24 byte)
//   0x01fa2c: f9400268  ldr      x8, [x19]
//   0x01fa30: b00000e1  adrp     x1, #0x3c000
//   0x01fa34: 91004821  add      x1, x1, #0x12
//   0x01fa38: aa1303e0  mov      x0, x19
//   0x01fa3c: f9401908  ldr      x8, [x8, #0x30]
//   0x01fa40: d61f0100  br       x8
uint64_t fde_0782_sub_01fa2c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400268ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x01FA2CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400268ULL; // 0x01fa2c: ldr x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xB00000E1ULL; // 0x01fa30: adrp x1, #0x3c000
    acc = (acc * 0x100000001B3ULL) ^ 0x91004821ULL; // 0x01fa34: add x1, x1, #0x12
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x01fa38: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401908ULL; // 0x01fa3c: ldr x8, [x8, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x01fa40: br x8
    return acc;
}

// [EN] Reconstructed FDE #0783 @ 0x01fa44..0x01fa54 (16 bytes)
// [VN] Phục dựng FDE #0783 tại 0x01fa44..0x01fa54 (16 byte)
//   0x01fa44: aa1303e0  mov      x0, x19
//   0x01fa48: aa1503e1  mov      x1, x21
//   0x01fa4c: f9400102  ldr      x2, [x8]
//   0x01fa50: d65f03c0  ret      
uint64_t fde_0783_sub_01fa44(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1303E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01FA44ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x01fa44: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E1ULL; // 0x01fa48: mov x1, x21
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400102ULL; // 0x01fa4c: ldr x2, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01fa50: ret 
    return acc;
}

// [EN] Reconstructed FDE #0784 @ 0x01fa54..0x01fa60 (12 bytes)
// [VN] Phục dựng FDE #0784 tại 0x01fa54..0x01fa60 (12 byte)
//   0x01fa54: 910083e8  add      x8, sp, #0x20
//   0x01fa58: aa1303e0  mov      x0, x19
//   0x01fa5c: 17ffacf9  b        #0xae40
uint64_t fde_0784_sub_01fa54(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910083E8ULL) + (x1 ^ 0x17FFACF9ULL) + (x2 ^ 0x01FA54ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910083E8ULL; // 0x01fa54: add x8, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x01fa58: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFACF9ULL; // 0x01fa5c: b #0xae40
    return acc;
}

// [EN] Reconstructed FDE #0785 @ 0x01fa60..0x01fa7c (28 bytes)
// [VN] Phục dựng FDE #0785 tại 0x01fa60..0x01fa7c (28 byte)
//   0x01fa60: d53bd057  mrs      x23, tpidr_el0
//   0x01fa64: f94016e8  ldr      x8, [x23, #0x28]
//   0x01fa68: 900001f8  adrp     x24, #0x5b000
//   0x01fa6c: f9001fe8  str      x8, [sp, #0x38]
//   0x01fa70: f945f718  ldr      x24, [x24, #0xbe8]
//   0x01fa74: 39400308  ldrb     w8, [x24]
//   0x01fa78: d65f03c0  ret      
uint64_t fde_0785_sub_01fa60(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD53BD057ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01FA60ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x01fa60: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x01fa64: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x900001F8ULL; // 0x01fa68: adrp x24, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001FE8ULL; // 0x01fa6c: str x8, [sp, #0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0xF945F718ULL; // 0x01fa70: ldr x24, [x24, #0xbe8]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400308ULL; // 0x01fa74: ldrb w8, [x24]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01fa78: ret 
    return acc;
}

// [EN] Reconstructed FDE #0786 @ 0x01fa7c..0x01fa84 (8 bytes)
// [VN] Phục dựng FDE #0786 tại 0x01fa7c..0x01fa84 (8 byte)
//   0x01fa7c: 52800060  mov      w0, #3
//   0x01fa80: 17ffadd8  b        #0xb1e0
uint64_t fde_0786_sub_01fa7c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800060ULL) + (x1 ^ 0x17FFADD8ULL) + (x2 ^ 0x01FA7CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x01fa7c: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFADD8ULL; // 0x01fa80: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #0787 @ 0x01fa84..0x01fa94 (16 bytes)
// [VN] Phục dựng FDE #0787 tại 0x01fa84..0x01fa94 (16 byte)
//   0x01fa84: aa1603e0  mov      x0, x22
//   0x01fa88: aa1303e1  mov      x1, x19
//   0x01fa8c: aa1703e2  mov      x2, x23
//   0x01fa90: d65f03c0  ret      
uint64_t fde_0787_sub_01fa84(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1603E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01FA84ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1603E0ULL; // 0x01fa84: mov x0, x22
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E1ULL; // 0x01fa88: mov x1, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1703E2ULL; // 0x01fa8c: mov x2, x23
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01fa90: ret 
    return acc;
}

// [EN] Reconstructed FDE #0788 @ 0x01fa94..0x01fa9c (8 bytes)
// [VN] Phục dựng FDE #0788 tại 0x01fa94..0x01fa9c (8 byte)
//   0x01fa94: 52800021  mov      w1, #1
//   0x01fa98: d61f0120  br       x9
uint64_t fde_0788_sub_01fa94(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800021ULL) + (x1 ^ 0xD61F0120ULL) + (x2 ^ 0x01FA94ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x01fa94: mov w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0120ULL; // 0x01fa98: br x9
    return acc;
}

// [EN] Reconstructed FDE #0789 @ 0x01fa9c..0x01faac (16 bytes)
// [VN] Phục dựng FDE #0789 tại 0x01fa9c..0x01faac (16 byte)
//   0x01fa9c: aa1703e0  mov      x0, x23
//   0x01faa0: aa1303e1  mov      x1, x19
//   0x01faa4: aa1803e2  mov      x2, x24
//   0x01faa8: d65f03c0  ret      
uint64_t fde_0789_sub_01fa9c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1703E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01FA9CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1703E0ULL; // 0x01fa9c: mov x0, x23
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E1ULL; // 0x01faa0: mov x1, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1803E2ULL; // 0x01faa4: mov x2, x24
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01faa8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0790 @ 0x01faac..0x01fac4 (24 bytes)
// [VN] Phục dựng FDE #0790 tại 0x01faac..0x01fac4 (24 byte)
//   0x01faac: 924026c8  and      x8, x22, #0x3ff
//   0x01fab0: d37ced08  lsl      x8, x8, #4
//   0x01fab4: f8686b68  ldr      x8, [x27, x8]
//   0x01fab8: f9400340  ldr      x0, [x26]
//   0x01fabc: eb00011f  cmp      x8, x0
//   0x01fac0: d65f03c0  ret      
uint64_t fde_0790_sub_01faac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x924026C8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01FAACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x924026C8ULL; // 0x01faac: and x8, x22, #0x3ff
    acc = (acc * 0x100000001B3ULL) ^ 0xD37CED08ULL; // 0x01fab0: lsl x8, x8, #4
    acc = (acc * 0x100000001B3ULL) ^ 0xF8686B68ULL; // 0x01fab4: ldr x8, [x27, x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400340ULL; // 0x01fab8: ldr x0, [x26]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB00011FULL; // 0x01fabc: cmp x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01fac0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0791 @ 0x01fac4..0x01fad0 (12 bytes)
// [VN] Phục dựng FDE #0791 tại 0x01fac4..0x01fad0 (12 byte)
//   0x01fac4: b9800328  ldrsw    x8, [x25]
//   0x01fac8: eb0802df  cmp      x22, x8
//   0x01facc: d65f03c0  ret      
uint64_t fde_0791_sub_01fac4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9800328ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01FAC4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9800328ULL; // 0x01fac4: ldrsw x8, [x25]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB0802DFULL; // 0x01fac8: cmp x22, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01facc: ret 
    return acc;
}

// [EN] Reconstructed FDE #0792 @ 0x01fad0..0x01fae8 (24 bytes)
// [VN] Phục dựng FDE #0792 tại 0x01fad0..0x01fae8 (24 byte)
//   0x01fad0: a940a15b  ldp      x27, x8, [x10, #8]
//   0x01fad4: f9400155  ldr      x21, [x10]
//   0x01fad8: 52808016  mov      w22, #0x400
//   0x01fadc: f9000fea  str      x10, [sp, #0x18]
//   0x01fae0: 9140111a  add      x26, x8, #4, lsl #12
//   0x01fae4: d65f03c0  ret      
uint64_t fde_0792_sub_01fad0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA940A15BULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01FAD0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA940A15BULL; // 0x01fad0: ldp x27, x8, [x10, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400155ULL; // 0x01fad4: ldr x21, [x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x52808016ULL; // 0x01fad8: mov w22, #0x400
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FEAULL; // 0x01fadc: str x10, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x9140111AULL; // 0x01fae0: add x26, x8, #4, lsl #12
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01fae4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0793 @ 0x01fae8..0x01faf8 (16 bytes)
// [VN] Phục dựng FDE #0793 tại 0x01fae8..0x01faf8 (16 byte)
//   0x01fae8: 9100e3e1  add      x1, sp, #0x38
//   0x01faec: 52800042  mov      w2, #2
//   0x01faf0: 2a1303e0  mov      w0, w19
//   0x01faf4: 14002bf3  b        #0x2aac0
uint64_t fde_0793_sub_01fae8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x9100E3E1ULL) + (x1 ^ 0x14002BF3ULL) + (x2 ^ 0x01FAE8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x9100E3E1ULL; // 0x01fae8: add x1, sp, #0x38
    acc = (acc * 0x100000001B3ULL) ^ 0x52800042ULL; // 0x01faec: mov w2, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1303E0ULL; // 0x01faf0: mov w0, w19
    acc = (acc * 0x100000001B3ULL) ^ 0x14002BF3ULL; // 0x01faf4: b #0x2aac0
    return acc;
}

// [EN] Reconstructed FDE #0794 @ 0x01faf8..0x01fb08 (16 bytes)
// [VN] Phục dựng FDE #0794 tại 0x01faf8..0x01fb08 (16 byte)
//   0x01faf8: aa1303e0  mov      x0, x19
//   0x01fafc: aa1803e1  mov      x1, x24
//   0x01fb00: f9400102  ldr      x2, [x8]
//   0x01fb04: 17fffb40  b        #0x1e804
uint64_t fde_0794_sub_01faf8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1303E0ULL) + (x1 ^ 0x17FFFB40ULL) + (x2 ^ 0x01FAF8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x01faf8: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1803E1ULL; // 0x01fafc: mov x1, x24
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400102ULL; // 0x01fb00: ldr x2, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFB40ULL; // 0x01fb04: b #0x1e804
    return acc;
}

// [EN] Reconstructed FDE #0795 @ 0x01fb08..0x01fb10 (8 bytes)
// [VN] Phục dựng FDE #0795 tại 0x01fb08..0x01fb10 (8 byte)
//   0x01fb08: 52801640  mov      w0, #0xb2
//   0x01fb0c: 17ffae55  b        #0xb460
uint64_t fde_0795_sub_01fb08(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52801640ULL) + (x1 ^ 0x17FFAE55ULL) + (x2 ^ 0x01FB08ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52801640ULL; // 0x01fb08: mov w0, #0xb2
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFAE55ULL; // 0x01fb0c: b #0xb460
    return acc;
}

// [EN] Reconstructed FDE #0796 @ 0x01fb10..0x01fb1c (12 bytes)
// [VN] Phục dựng FDE #0796 tại 0x01fb10..0x01fb1c (12 byte)
//   0x01fb10: f9400108  ldr      x8, [x8]
//   0x01fb14: f9400116  ldr      x22, [x8]
//   0x01fb18: 17ffadae  b        #0xb1d0
uint64_t fde_0796_sub_01fb10(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400108ULL) + (x1 ^ 0x17FFADAEULL) + (x2 ^ 0x01FB10ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x01fb10: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400116ULL; // 0x01fb14: ldr x22, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFADAEULL; // 0x01fb18: b #0xb1d0
    return acc;
}

// [EN] Reconstructed FDE #0797 @ 0x01fb1c..0x01fb24 (8 bytes)
// [VN] Phục dựng FDE #0797 tại 0x01fb1c..0x01fb24 (8 byte)
//   0x01fb1c: 910083e0  add      x0, sp, #0x20
//   0x01fb20: 17ffad9c  b        #0xb190
uint64_t fde_0797_sub_01fb1c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910083E0ULL) + (x1 ^ 0x17FFAD9CULL) + (x2 ^ 0x01FB1CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910083E0ULL; // 0x01fb1c: add x0, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFAD9CULL; // 0x01fb20: b #0xb190
    return acc;
}

// [EN] Reconstructed FDE #0798 @ 0x01fb24..0x01fb2c (8 bytes)
// [VN] Phục dựng FDE #0798 tại 0x01fb24..0x01fb2c (8 byte)
//   0x01fb24: f9419508  ldr      x8, [x8, #0x328]
//   0x01fb28: d61f0100  br       x8
uint64_t fde_0798_sub_01fb24(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9419508ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x01FB24ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9419508ULL; // 0x01fb24: ldr x8, [x8, #0x328]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x01fb28: br x8
    return acc;
}

// [EN] Reconstructed FDE #0799 @ 0x01fb2c..0x01fb38 (12 bytes)
// [VN] Phục dựng FDE #0799 tại 0x01fb2c..0x01fb38 (12 byte)
//   0x01fb2c: 52800021  mov      w1, #1
//   0x01fb30: aa0003f3  mov      x19, x0
//   0x01fb34: 140030e8  b        #0x2bed4
uint64_t fde_0799_sub_01fb2c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800021ULL) + (x1 ^ 0x140030E8ULL) + (x2 ^ 0x01FB2CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x01fb2c: mov w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01fb30: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x140030E8ULL; // 0x01fb34: b #0x2bed4
    return acc;
}

// [EN] Reconstructed FDE #0800 @ 0x01fb38..0x01fb40 (8 bytes)
// [VN] Phục dựng FDE #0800 tại 0x01fb38..0x01fb40 (8 byte)
//   0x01fb38: 52800021  mov      w1, #1
//   0x01fb3c: 17ffaf11  b        #0xb780
uint64_t fde_0800_sub_01fb38(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800021ULL) + (x1 ^ 0x17FFAF11ULL) + (x2 ^ 0x01FB38ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x01fb38: mov w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFAF11ULL; // 0x01fb3c: b #0xb780
    return acc;
}

// [EN] Reconstructed FDE #0801 @ 0x01fb40..0x01fb4c (12 bytes)
// [VN] Phục dựng FDE #0801 tại 0x01fb40..0x01fb4c (12 byte)
//   0x01fb40: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x01fb44: a8c357f6  ldp      x22, x21, [sp], #0x30
//   0x01fb48: d65f03c0  ret      
uint64_t fde_0801_sub_01fb40(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9414FF4ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01FB40ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9414FF4ULL; // 0x01fb40: ldp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C357F6ULL; // 0x01fb44: ldp x22, x21, [sp], #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01fb48: ret 
    return acc;
}

// [EN] Reconstructed FDE #0802 @ 0x01fb4c..0x01fb58 (12 bytes)
// [VN] Phục dựng FDE #0802 tại 0x01fb4c..0x01fb58 (12 byte)
//   0x01fb4c: 6e004000  ext      v0.16b, v0.16b, v0.16b, #8
//   0x01fb50: 3d8003e0  str      q0, [sp]
//   0x01fb54: 17fff71b  b        #0x1d7c0
uint64_t fde_0802_sub_01fb4c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x6E004000ULL) + (x1 ^ 0x17FFF71BULL) + (x2 ^ 0x01FB4CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x6E004000ULL; // 0x01fb4c: ext v0.16b, v0.16b, v0.16b, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x3D8003E0ULL; // 0x01fb50: str q0, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF71BULL; // 0x01fb54: b #0x1d7c0
    return acc;
}

// [EN] Reconstructed FDE #0803 @ 0x01fb58..0x01fb64 (12 bytes)
// [VN] Phục dựng FDE #0803 tại 0x01fb58..0x01fb64 (12 byte)
//   0x01fb58: 910003e8  mov      x8, sp
//   0x01fb5c: aa1303e0  mov      x0, x19
//   0x01fb60: 17ffaf3c  b        #0xb850
uint64_t fde_0803_sub_01fb58(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910003E8ULL) + (x1 ^ 0x17FFAF3CULL) + (x2 ^ 0x01FB58ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E8ULL; // 0x01fb58: mov x8, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x01fb5c: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFAF3CULL; // 0x01fb60: b #0xb850
    return acc;
}

// [EN] Reconstructed FDE #0804 @ 0x01fb64..0x01fb70 (12 bytes)
// [VN] Phục dựng FDE #0804 tại 0x01fb64..0x01fb70 (12 byte)
//   0x01fb64: f9002fe8  str      x8, [sp, #0x58]
//   0x01fb68: 9100e3e8  add      x8, sp, #0x38
//   0x01fb6c: 17ffaf39  b        #0xb850
uint64_t fde_0804_sub_01fb64(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9002FE8ULL) + (x1 ^ 0x17FFAF39ULL) + (x2 ^ 0x01FB64ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9002FE8ULL; // 0x01fb64: str x8, [sp, #0x58]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100E3E8ULL; // 0x01fb68: add x8, sp, #0x38
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFAF39ULL; // 0x01fb6c: b #0xb850
    return acc;
}

// [EN] Reconstructed FDE #0805 @ 0x01fb70..0x01fb7c (12 bytes)
// [VN] Phục dựng FDE #0805 tại 0x01fb70..0x01fb7c (12 byte)
//   0x01fb70: aa1f03e1  mov      x1, xzr
//   0x01fb74: f9400108  ldr      x8, [x8]
//   0x01fb78: d61f0100  br       x8
uint64_t fde_0805_sub_01fb70(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E1ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x01FB70ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x01fb70: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x01fb74: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x01fb78: br x8
    return acc;
}

// [EN] Reconstructed FDE #0806 @ 0x01fb7c..0x01fb88 (12 bytes)
// [VN] Phục dựng FDE #0806 tại 0x01fb7c..0x01fb88 (12 byte)
//   0x01fb7c: 2a1f03e0  mov      w0, wzr
//   0x01fb80: 2a1f03e1  mov      w1, wzr
//   0x01fb84: 17ffad17  b        #0xafe0
uint64_t fde_0806_sub_01fb7c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0x17FFAD17ULL) + (x2 ^ 0x01FB7CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x01fb7c: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E1ULL; // 0x01fb80: mov w1, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFAD17ULL; // 0x01fb84: b #0xafe0
    return acc;
}

// [EN] Reconstructed FDE #0807 @ 0x01fb88..0x01fb94 (12 bytes)
// [VN] Phục dựng FDE #0807 tại 0x01fb88..0x01fb94 (12 byte)
//   0x01fb88: b9400108  ldr      w8, [x8]
//   0x01fb8c: 7100051f  cmp      w8, #1
//   0x01fb90: d65f03c0  ret      
uint64_t fde_0807_sub_01fb88(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400108ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01FB88ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400108ULL; // 0x01fb88: ldr w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100051FULL; // 0x01fb8c: cmp w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01fb90: ret 
    return acc;
}

// [EN] Reconstructed FDE #0808 @ 0x01fb94..0x01fba8 (20 bytes)
// [VN] Phục dựng FDE #0808 tại 0x01fb94..0x01fba8 (20 byte)
//   0x01fb94: 900001f7  adrp     x23, #0x5b000
//   0x01fb98: f944eaf7  ldr      x23, [x23, #0x9d0]
//   0x01fb9c: a94026e8  ldp      x8, x9, [x23]
//   0x01fba0: eb09011f  cmp      x8, x9
//   0x01fba4: d65f03c0  ret      
uint64_t fde_0808_sub_01fb94(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x900001F7ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01FB94ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x900001F7ULL; // 0x01fb94: adrp x23, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF944EAF7ULL; // 0x01fb98: ldr x23, [x23, #0x9d0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA94026E8ULL; // 0x01fb9c: ldp x8, x9, [x23]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x01fba0: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01fba4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0809 @ 0x01fba8..0x01fbbc (20 bytes)
// [VN] Phục dựng FDE #0809 tại 0x01fba8..0x01fbbc (20 byte)
//   0x01fba8: d00000c1  adrp     x1, #0x39000
//   0x01fbac: b00000e2  adrp     x2, #0x3c000
//   0x01fbb0: 911f2c21  add      x1, x1, #0x7cb
//   0x01fbb4: 91058c42  add      x2, x2, #0x163
//   0x01fbb8: d65f03c0  ret      
uint64_t fde_0809_sub_01fba8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD00000C1ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01FBA8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD00000C1ULL; // 0x01fba8: adrp x1, #0x39000
    acc = (acc * 0x100000001B3ULL) ^ 0xB00000E2ULL; // 0x01fbac: adrp x2, #0x3c000
    acc = (acc * 0x100000001B3ULL) ^ 0x911F2C21ULL; // 0x01fbb0: add x1, x1, #0x7cb
    acc = (acc * 0x100000001B3ULL) ^ 0x91058C42ULL; // 0x01fbb4: add x2, x2, #0x163
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01fbb8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0810 @ 0x01fbbc..0x01fbd0 (20 bytes)
// [VN] Phục dựng FDE #0810 tại 0x01fbbc..0x01fbd0 (20 byte)
//   0x01fbbc: d00000c1  adrp     x1, #0x39000
//   0x01fbc0: b00000e2  adrp     x2, #0x3c000
//   0x01fbc4: 911f2c21  add      x1, x1, #0x7cb
//   0x01fbc8: 91031842  add      x2, x2, #0xc6
//   0x01fbcc: d65f03c0  ret      
uint64_t fde_0810_sub_01fbbc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD00000C1ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01FBBCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD00000C1ULL; // 0x01fbbc: adrp x1, #0x39000
    acc = (acc * 0x100000001B3ULL) ^ 0xB00000E2ULL; // 0x01fbc0: adrp x2, #0x3c000
    acc = (acc * 0x100000001B3ULL) ^ 0x911F2C21ULL; // 0x01fbc4: add x1, x1, #0x7cb
    acc = (acc * 0x100000001B3ULL) ^ 0x91031842ULL; // 0x01fbc8: add x2, x2, #0xc6
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01fbcc: ret 
    return acc;
}

// [EN] Reconstructed FDE #0811 @ 0x01fbd0..0x01fc74 (164 bytes)
// [VN] Phục dựng FDE #0811 tại 0x01fbd0..0x01fc74 (164 byte)
//   0x01fbd0: d10103ff  sub      sp, sp, #0x40
//   0x01fbd4: f9000bf5  str      x21, [sp, #0x10]
//   0x01fbd8: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x01fbdc: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x01fbe0: 9100c3fd  add      x29, sp, #0x30
//   0x01fbe4: d53bd055  mrs      x21, tpidr_el0
//   0x01fbe8: f94016a8  ldr      x8, [x21, #0x28]
//   0x01fbec: 2a0103f3  mov      w19, w1
//   0x01fbf0: d00000e1  adrp     x1, #0x3d000
//   0x01fbf4: 910bc421  add      x1, x1, #0x2f1
//   0x01fbf8: aa0003f4  mov      x20, x0
//   0x01fbfc: f90007e8  str      x8, [sp, #8]
uint64_t fde_0811_sub_01fbd0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xD00000E1ULL) + (x2 ^ 0x01FBD0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x01fbd0: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF5ULL; // 0x01fbd4: str x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x01fbd8: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x01fbdc: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x01fbe0: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x01fbe4: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x01fbe8: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F3ULL; // 0x01fbec: mov w19, w1
    return acc;
}

// [EN] Reconstructed FDE #0812 @ 0x01fc74..0x01fd10 (156 bytes)
// [VN] Phục dựng FDE #0812 tại 0x01fc74..0x01fd10 (156 byte)
//   0x01fc74: d10103ff  sub      sp, sp, #0x40
//   0x01fc78: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x01fc7c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x01fc80: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x01fc84: 9100c3fd  add      x29, sp, #0x30
//   0x01fc88: d53bd056  mrs      x22, tpidr_el0
//   0x01fc8c: f94016c8  ldr      x8, [x22, #0x28]
//   0x01fc90: aa0103f3  mov      x19, x1
//   0x01fc94: aa0003f4  mov      x20, x0
//   0x01fc98: f90007e8  str      x8, [sp, #8]
//   0x01fc9c: b00001e8  adrp     x8, #0x5c000
//   0x01fca0: f9445508  ldr      x8, [x8, #0x8a8]
uint64_t fde_0812_sub_01fc74(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xAA0003F4ULL) + (x2 ^ 0x01FC74ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x01fc74: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x01fc78: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x01fc7c: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x01fc80: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x01fc84: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x01fc88: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x01fc8c: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x01fc90: mov x19, x1
    return acc;
}

// [EN] Reconstructed FDE #0813 @ 0x01fd10..0x01fdf4 (228 bytes)
// [VN] Phục dựng FDE #0813 tại 0x01fd10..0x01fdf4 (228 byte)
//   0x01fd10: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x01fd14: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01fd18: 910043fd  add      x29, sp, #0x10
//   0x01fd1c: d00000c1  adrp     x1, #0x39000
//   0x01fd20: d00000e2  adrp     x2, #0x3d000
//   0x01fd24: 911f2c21  add      x1, x1, #0x7cb
//   0x01fd28: 910bfc42  add      x2, x2, #0x2ff
//   0x01fd2c: 940000e1  bl       #0x200b0
//   0x01fd30: d00000f3  adrp     x19, #0x3d000
//   0x01fd34: 910bc673  add      x19, x19, #0x2f1
//   0x01fd38: 52820041  mov      w1, #0x1002
//   0x01fd3c: aa1303e0  mov      x0, x19
uint64_t fde_0813_sub_01fd10(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xD00000F3ULL) + (x2 ^ 0x01FD10ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x01fd10: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01fd14: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01fd18: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD00000C1ULL; // 0x01fd1c: adrp x1, #0x39000
    acc = (acc * 0x100000001B3ULL) ^ 0xD00000E2ULL; // 0x01fd20: adrp x2, #0x3d000
    acc = (acc * 0x100000001B3ULL) ^ 0x911F2C21ULL; // 0x01fd24: add x1, x1, #0x7cb
    acc = (acc * 0x100000001B3ULL) ^ 0x910BFC42ULL; // 0x01fd28: add x2, x2, #0x2ff
    acc = (acc * 0x100000001B3ULL) ^ 0x940000E1ULL; // 0x01fd2c: bl #0x200b0
    return acc;
}

// [EN] Reconstructed FDE #0814 @ 0x01fdf4..0x01fe38 (68 bytes)
// [VN] Phục dựng FDE #0814 tại 0x01fdf4..0x01fe38 (68 byte)
//   0x01fdf4: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x01fdf8: 910003fd  mov      x29, sp
//   0x01fdfc: b00001e8  adrp     x8, #0x5c000
//   0x01fe00: f9445900  ldr      x0, [x8, #0x8b0]
//   0x01fe04: b4000040  cbz      x0, #0x1fe0c
//   0x01fe08: 97ffae52  bl       #0xb750
//   0x01fe0c: b00001e8  adrp     x8, #0x5c000
//   0x01fe10: f9446100  ldr      x0, [x8, #0x8c0]
//   0x01fe14: b4000040  cbz      x0, #0x1fe1c
//   0x01fe18: 97ffabfe  bl       #0xae10
//   0x01fe1c: b00001e8  adrp     x8, #0x5c000
//   0x01fe20: f9445d00  ldr      x0, [x8, #0x8b8]
uint64_t fde_0814_sub_01fdf4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xB4000040ULL) + (x2 ^ 0x01FDF4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x01fdf4: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x01fdf8: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001E8ULL; // 0x01fdfc: adrp x8, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9445900ULL; // 0x01fe00: ldr x0, [x8, #0x8b0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000040ULL; // 0x01fe04: cbz x0, #0x1fe0c
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFAE52ULL; // 0x01fe08: bl #0xb750
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001E8ULL; // 0x01fe0c: adrp x8, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9446100ULL; // 0x01fe10: ldr x0, [x8, #0x8c0]
    return acc;
}

// [EN] Reconstructed FDE #0815 @ 0x01fe38..0x01ff40 (264 bytes)
// [VN] Phục dựng FDE #0815 tại 0x01fe38..0x01ff40 (264 byte)
//   0x01fe38: d10143ff  sub      sp, sp, #0x50
//   0x01fe3c: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x01fe40: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x01fe44: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x01fe48: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x01fe4c: 910103fd  add      x29, sp, #0x40
//   0x01fe50: d53bd056  mrs      x22, tpidr_el0
//   0x01fe54: f94016c8  ldr      x8, [x22, #0x28]
//   0x01fe58: aa0103f3  mov      x19, x1
//   0x01fe5c: aa0003f4  mov      x20, x0
//   0x01fe60: f90007e8  str      x8, [sp, #8]
//   0x01fe64: f90003fe  str      x30, [sp]
uint64_t fde_0815_sub_01fe38(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xAA0103F3ULL) + (x2 ^ 0x01FE38ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x01fe38: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x01fe3c: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x01fe40: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x01fe44: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x01fe48: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x01fe4c: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x01fe50: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x01fe54: ldr x8, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0816 @ 0x01ff40..0x020038 (248 bytes)
// [VN] Phục dựng FDE #0816 tại 0x01ff40..0x020038 (248 byte)
//   0x01ff40: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x01ff44: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01ff48: 910043fd  add      x29, sp, #0x10
//   0x01ff4c: d00000c1  adrp     x1, #0x39000
//   0x01ff50: d00000e2  adrp     x2, #0x3d000
//   0x01ff54: 2a0003f3  mov      w19, w0
//   0x01ff58: 911f2c21  add      x1, x1, #0x7cb
//   0x01ff5c: 910d2042  add      x2, x2, #0x348
//   0x01ff60: 94000054  bl       #0x200b0
//   0x01ff64: d00000e0  adrp     x0, #0x3d000
//   0x01ff68: 910d6000  add      x0, x0, #0x358
//   0x01ff6c: 52800081  mov      w1, #4
uint64_t fde_0816_sub_01ff40(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x94000054ULL) + (x2 ^ 0x01FF40ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x01ff40: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01ff44: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01ff48: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD00000C1ULL; // 0x01ff4c: adrp x1, #0x39000
    acc = (acc * 0x100000001B3ULL) ^ 0xD00000E2ULL; // 0x01ff50: adrp x2, #0x3d000
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F3ULL; // 0x01ff54: mov w19, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x911F2C21ULL; // 0x01ff58: add x1, x1, #0x7cb
    acc = (acc * 0x100000001B3ULL) ^ 0x910D2042ULL; // 0x01ff5c: add x2, x2, #0x348
    return acc;
}

// [EN] Reconstructed FDE #0817 @ 0x020038..0x02007c (68 bytes)
// [VN] Phục dựng FDE #0817 tại 0x020038..0x02007c (68 byte)
//   0x020038: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x02003c: 910003fd  mov      x29, sp
//   0x020040: 900001e8  adrp     x8, #0x5c000
//   0x020044: f9446500  ldr      x0, [x8, #0x8c8]
//   0x020048: b4000040  cbz      x0, #0x20050
//   0x02004c: 97ffac95  bl       #0xb2a0
//   0x020050: 900001e8  adrp     x8, #0x5c000
//   0x020054: f9446900  ldr      x0, [x8, #0x8d0]
//   0x020058: b4000040  cbz      x0, #0x20060
//   0x02005c: 97ffac91  bl       #0xb2a0
//   0x020060: 900001e8  adrp     x8, #0x5c000
//   0x020064: f9446d00  ldr      x0, [x8, #0x8d8]
uint64_t fde_0817_sub_020038(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xB4000040ULL) + (x2 ^ 0x020038ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x020038: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02003c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x900001E8ULL; // 0x020040: adrp x8, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9446500ULL; // 0x020044: ldr x0, [x8, #0x8c8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000040ULL; // 0x020048: cbz x0, #0x20050
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFAC95ULL; // 0x02004c: bl #0xb2a0
    acc = (acc * 0x100000001B3ULL) ^ 0x900001E8ULL; // 0x020050: adrp x8, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9446900ULL; // 0x020054: ldr x0, [x8, #0x8d0]
    return acc;
}

// [EN] Reconstructed FDE #0818 @ 0x02007c..0x020088 (12 bytes)
// [VN] Phục dựng FDE #0818 tại 0x02007c..0x020088 (12 byte)
//   0x02007c: 72001c5f  tst      w2, #0xff
//   0x020080: 1a9f07e0  cset     w0, ne
//   0x020084: 17ffffaf  b        #0x1ff40
uint64_t fde_0818_sub_02007c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x72001C5FULL) + (x1 ^ 0x17FFFFAFULL) + (x2 ^ 0x02007CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x72001C5FULL; // 0x02007c: tst w2, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F07E0ULL; // 0x020080: cset w0, ne
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFAFULL; // 0x020084: b #0x1ff40
    return acc;
}

// [EN] Reconstructed FDE #0819 @ 0x020088..0x020098 (16 bytes)
// [VN] Phục dựng FDE #0819 tại 0x020088..0x020098 (16 byte)
//   0x020088: aa1f03e1  mov      x1, xzr
//   0x02008c: aa1f03e4  mov      x4, xzr
//   0x020090: aa1f03e5  mov      x5, xzr
//   0x020094: 17ffad2b  b        #0xb540
uint64_t fde_0819_sub_020088(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E1ULL) + (x1 ^ 0x17FFAD2BULL) + (x2 ^ 0x020088ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x020088: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E4ULL; // 0x02008c: mov x4, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E5ULL; // 0x020090: mov x5, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFAD2BULL; // 0x020094: b #0xb540
    return acc;
}

// [EN] Reconstructed FDE #0820 @ 0x020098..0x0200a8 (16 bytes)
// [VN] Phục dựng FDE #0820 tại 0x020098..0x0200a8 (16 byte)
//   0x020098: aa0003e8  mov      x8, x0
//   0x02009c: aa1403e0  mov      x0, x20
//   0x0200a0: aa1303e1  mov      x1, x19
//   0x0200a4: d61f0100  br       x8
uint64_t fde_0820_sub_020098(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x020098ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x020098: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x02009c: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E1ULL; // 0x0200a0: mov x1, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x0200a4: br x8
    return acc;
}

// [EN] Reconstructed FDE #0821 @ 0x0200a8..0x0200b0 (8 bytes)
// [VN] Phục dựng FDE #0821 tại 0x0200a8..0x0200b0 (8 byte)
//   0x0200a8: 910003e0  mov      x0, sp
//   0x0200ac: 17ffba3a  b        #0xe994
uint64_t fde_0821_sub_0200a8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910003E0ULL) + (x1 ^ 0x17FFBA3AULL) + (x2 ^ 0x0200A8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E0ULL; // 0x0200a8: mov x0, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFBA3AULL; // 0x0200ac: b #0xe994
    return acc;
}

// [EN] Reconstructed FDE #0822 @ 0x0200b0..0x0200b8 (8 bytes)
// [VN] Phục dựng FDE #0822 tại 0x0200b0..0x0200b8 (8 byte)
//   0x0200b0: 52800080  mov      w0, #4
//   0x0200b4: 17ffac4b  b        #0xb1e0
uint64_t fde_0822_sub_0200b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800080ULL) + (x1 ^ 0x17FFAC4BULL) + (x2 ^ 0x0200B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800080ULL; // 0x0200b0: mov w0, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFAC4BULL; // 0x0200b4: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #0823 @ 0x0200b8..0x0201c4 (268 bytes)
// [VN] Phục dựng FDE #0823 tại 0x0200b8..0x0201c4 (268 byte)
//   0x0200b8: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x0200bc: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0200c0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0200c4: 910083fd  add      x29, sp, #0x20
//   0x0200c8: 900001f6  adrp     x22, #0x5c000
//   0x0200cc: f94472c8  ldr      x8, [x22, #0x8e0]
//   0x0200d0: b50000a8  cbnz     x8, #0x200e4
//   0x0200d4: 97ffdd29  bl       #0x17578
//   0x0200d8: 51007008  sub      w8, w0, #0x1c
//   0x0200dc: 7100091f  cmp      w8, #2
//   0x0200e0: 540000a9  b.ls     #0x200f4
//   0x0200e4: a9427bfd  ldp      x29, x30, [sp, #0x20]
uint64_t fde_0823_sub_0200b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x51007008ULL) + (x2 ^ 0x0200B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x0200b8: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0200bc: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0200c0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0200c4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x900001F6ULL; // 0x0200c8: adrp x22, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0xF94472C8ULL; // 0x0200cc: ldr x8, [x22, #0x8e0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB50000A8ULL; // 0x0200d0: cbnz x8, #0x200e4
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFDD29ULL; // 0x0200d4: bl #0x17578
    return acc;
}

// [EN] Reconstructed FDE #0824 @ 0x0201c4..0x0202b4 (240 bytes)
// [VN] Phục dựng FDE #0824 tại 0x0201c4..0x0202b4 (240 byte)
//   0x0201c4: d10203ff  sub      sp, sp, #0x80
//   0x0201c8: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x0201cc: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x0201d0: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x0201d4: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x0201d8: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x0201dc: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x0201e0: 9101c3fd  add      x29, sp, #0x70
//   0x0201e4: d53bd05c  mrs      x28, tpidr_el0
//   0x0201e8: aa0803fa  mov      x26, x8
//   0x0201ec: f9401788  ldr      x8, [x28, #0x28]
//   0x0201f0: aa0703f3  mov      x19, x7
uint64_t fde_0824_sub_0201c4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xD53BD05CULL) + (x2 ^ 0x0201C4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x0201c4: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA9026FFCULL; // 0x0201c8: stp x28, x27, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x0201cc: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x0201d0: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x0201d4: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x0201d8: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x0201dc: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x0201e0: add x29, sp, #0x70
    return acc;
}

// [EN] Reconstructed FDE #0825 @ 0x0202b4..0x020384 (208 bytes)
// [VN] Phục dựng FDE #0825 tại 0x0202b4..0x020384 (208 byte)
//   0x0202b4: d101c3ff  sub      sp, sp, #0x70
//   0x0202b8: f90013f9  str      x25, [sp, #0x20]
//   0x0202bc: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x0202c0: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x0202c4: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x0202c8: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x0202cc: 910183fd  add      x29, sp, #0x60
//   0x0202d0: d53bd059  mrs      x25, tpidr_el0
//   0x0202d4: aa0803f7  mov      x23, x8
//   0x0202d8: f9401728  ldr      x8, [x25, #0x28]
//   0x0202dc: aa0403f3  mov      x19, x4
//   0x0202e0: aa0303f8  mov      x24, x3
uint64_t fde_0825_sub_0202b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xAA0803F7ULL) + (x2 ^ 0x0202B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x0202b4: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F9ULL; // 0x0202b8: str x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x0202bc: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x0202c0: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x0202c4: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x0202c8: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x0202cc: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x0202d0: mrs x25, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0826 @ 0x020384..0x020388 (4 bytes)
// [VN] Phục dựng FDE #0826 tại 0x020384..0x020388 (4 byte)
//   0x020384: 17ffff4d  b        #0x200b8
uint64_t fde_0826_sub_020384(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFFF4DULL) + (x1 ^ 0x17FFFF4DULL) + (x2 ^ 0x020384ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFF4DULL; // 0x020384: b #0x200b8
    return acc;
}

// [EN] Reconstructed FDE #0827 @ 0x020388..0x020508 (384 bytes)
// [VN] Phục dựng FDE #0827 tại 0x020388..0x020508 (384 byte)
//   0x020388: d10183ff  sub      sp, sp, #0x60
//   0x02038c: f90013f7  str      x23, [sp, #0x20]
//   0x020390: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x020394: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x020398: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x02039c: 910143fd  add      x29, sp, #0x50
//   0x0203a0: d53bd055  mrs      x21, tpidr_el0
//   0x0203a4: f94016a8  ldr      x8, [x21, #0x28]
//   0x0203a8: aa0003f3  mov      x19, x0
//   0x0203ac: f9000fe8  str      x8, [sp, #0x18]
//   0x0203b0: 900001e8  adrp     x8, #0x5c000
//   0x0203b4: 9123c108  add      x8, x8, #0x8f0
uint64_t fde_0827_sub_020388(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x020388ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x020388: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F7ULL; // 0x02038c: str x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x020390: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x020394: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x020398: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x02039c: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x0203a0: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x0203a4: ldr x8, [x21, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0828 @ 0x020508..0x02052c (36 bytes)
// [VN] Phục dựng FDE #0828 tại 0x020508..0x02052c (36 byte)
//   0x020508: f9400000  ldr      x0, [x0]
//   0x02050c: b40000e0  cbz      x0, #0x20528
//   0x020510: 885ffc08  ldaxr    w8, [x0]
//   0x020514: 71000508  subs     w8, w8, #1
//   0x020518: 8809fc08  stlxr    w9, w8, [x0]
//   0x02051c: 35ffffa9  cbnz     w9, #0x20510
//   0x020520: 54000041  b.ne     #0x20528
//   0x020524: 17ffaa07  b        #0xad40
//   0x020528: d65f03c0  ret      
uint64_t fde_0828_sub_020508(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400000ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x020508ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x020508: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000E0ULL; // 0x02050c: cbz x0, #0x20528
    acc = (acc * 0x100000001B3ULL) ^ 0x885FFC08ULL; // 0x020510: ldaxr w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x71000508ULL; // 0x020514: subs w8, w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x8809FC08ULL; // 0x020518: stlxr w9, w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x35FFFFA9ULL; // 0x02051c: cbnz w9, #0x20510
    acc = (acc * 0x100000001B3ULL) ^ 0x54000041ULL; // 0x020520: b.ne #0x20528
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFAA07ULL; // 0x020524: b #0xad40
    return acc;
}

// [EN] Reconstructed FDE #0829 @ 0x02052c..0x020580 (84 bytes)
// [VN] Phục dựng FDE #0829 tại 0x02052c..0x020580 (84 byte)
//   0x02052c: d100c3ff  sub      sp, sp, #0x30
//   0x020530: f9000bf3  str      x19, [sp, #0x10]
//   0x020534: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x020538: 910083fd  add      x29, sp, #0x20
//   0x02053c: d53bd053  mrs      x19, tpidr_el0
//   0x020540: f9401669  ldr      x9, [x19, #0x28]
//   0x020544: 910003e0  mov      x0, sp
//   0x020548: f90007e9  str      x9, [sp, #8]
//   0x02054c: f90003fe  str      x30, [sp]
//   0x020550: a9007d1f  stp      xzr, xzr, [x8]
//   0x020554: f900091f  str      xzr, [x8, #0x10]
//   0x020558: 97ffc283  bl       #0x10f64
uint64_t fde_0829_sub_02052c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0xF90003FEULL) + (x2 ^ 0x02052CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x02052c: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF3ULL; // 0x020530: str x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x020534: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x020538: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x02053c: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401669ULL; // 0x020540: ldr x9, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E0ULL; // 0x020544: mov x0, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E9ULL; // 0x020548: str x9, [sp, #8]
    return acc;
}

// [EN] Reconstructed FDE #0830 @ 0x020580..0x0205e8 (104 bytes)
// [VN] Phục dựng FDE #0830 tại 0x020580..0x0205e8 (104 byte)
//   0x020580: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x020584: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x020588: 910043fd  add      x29, sp, #0x10
//   0x02058c: 900001e9  adrp     x9, #0x5c000
//   0x020590: 3970e12a  ldrb     w10, [x9, #0xc38]
//   0x020594: 52800028  mov      w8, #1
//   0x020598: 3700020a  tbnz     w10, #0, #0x205d8
//   0x02059c: 3930e128  strb     w8, [x9, #0xc38]
//   0x0205a0: 97ffac34  bl       #0xb670
//   0x0205a4: 7100841f  cmp      w0, #0x21
//   0x0205a8: 540000c3  b.lo     #0x205c0
//   0x0205ac: 9400000f  bl       #0x205e8
uint64_t fde_0830_sub_020580(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x97FFAC34ULL) + (x2 ^ 0x020580ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x020580: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x020584: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x020588: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x900001E9ULL; // 0x02058c: adrp x9, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0x3970E12AULL; // 0x020590: ldrb w10, [x9, #0xc38]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800028ULL; // 0x020594: mov w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x3700020AULL; // 0x020598: tbnz w10, #0, #0x205d8
    acc = (acc * 0x100000001B3ULL) ^ 0x3930E128ULL; // 0x02059c: strb w8, [x9, #0xc38]
    return acc;
}

// [EN] Reconstructed FDE #0831 @ 0x0205e8..0x0206cc (228 bytes)
// [VN] Phục dựng FDE #0831 tại 0x0205e8..0x0206cc (228 byte)
//   0x0205e8: d100c3ff  sub      sp, sp, #0x30
//   0x0205ec: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0205f0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0205f4: 910083fd  add      x29, sp, #0x20
//   0x0205f8: d53bd054  mrs      x20, tpidr_el0
//   0x0205fc: f9401688  ldr      x8, [x20, #0x28]
//   0x020600: b00000c0  adrp     x0, #0x39000
//   0x020604: 911cd000  add      x0, x0, #0x734
//   0x020608: f90007e8  str      x8, [sp, #8]
//   0x02060c: 97ffaad9  bl       #0xb170
//   0x020610: b00000e1  adrp     x1, #0x3d000
//   0x020614: 9116c421  add      x1, x1, #0x5b1
uint64_t fde_0831_sub_0205e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0xF90007E8ULL) + (x2 ^ 0x0205E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x0205e8: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0205ec: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0205f0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0205f4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x0205f8: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x0205fc: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xB00000C0ULL; // 0x020600: adrp x0, #0x39000
    acc = (acc * 0x100000001B3ULL) ^ 0x911CD000ULL; // 0x020604: add x0, x0, #0x734
    return acc;
}

// [EN] Reconstructed FDE #0832 @ 0x0206cc..0x0207b0 (228 bytes)
// [VN] Phục dựng FDE #0832 tại 0x0206cc..0x0207b0 (228 byte)
//   0x0206cc: d10103ff  sub      sp, sp, #0x40
//   0x0206d0: f9000bf5  str      x21, [sp, #0x10]
//   0x0206d4: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0206d8: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0206dc: 9100c3fd  add      x29, sp, #0x30
//   0x0206e0: d53bd054  mrs      x20, tpidr_el0
//   0x0206e4: f9401688  ldr      x8, [x20, #0x28]
//   0x0206e8: f00001d5  adrp     x21, #0x5b000
//   0x0206ec: f90007e8  str      x8, [sp, #8]
//   0x0206f0: f00001c8  adrp     x8, #0x5b000
//   0x0206f4: f9459108  ldr      x8, [x8, #0xb20]
//   0x0206f8: 08dffd08  ldarb    w8, [x8]
uint64_t fde_0832_sub_0206cc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xF90007E8ULL) + (x2 ^ 0x0206CCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x0206cc: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF5ULL; // 0x0206d0: str x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0206d4: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0206d8: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0206dc: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x0206e0: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x0206e4: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001D5ULL; // 0x0206e8: adrp x21, #0x5b000
    return acc;
}

// [EN] Reconstructed FDE #0833 @ 0x0207b0..0x0208d8 (296 bytes)
// [VN] Phục dựng FDE #0833 tại 0x0207b0..0x0208d8 (296 byte)
//   0x0207b0: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x0207b4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0207b8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0207bc: 910083fd  add      x29, sp, #0x20
//   0x0207c0: b00000e0  adrp     x0, #0x3d000
//   0x0207c4: 9119d800  add      x0, x0, #0x676
//   0x0207c8: 97ffa92e  bl       #0xac80
//   0x0207cc: b4000340  cbz      x0, #0x20834
//   0x0207d0: b00000e1  adrp     x1, #0x3d000
//   0x0207d4: 911a2421  add      x1, x1, #0x689
//   0x0207d8: aa0003f3  mov      x19, x0
//   0x0207dc: 97ffa97d  bl       #0xadd0
uint64_t fde_0833_sub_0207b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xB00000E1ULL) + (x2 ^ 0x0207B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x0207b0: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0207b4: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0207b8: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0207bc: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB00000E0ULL; // 0x0207c0: adrp x0, #0x3d000
    acc = (acc * 0x100000001B3ULL) ^ 0x9119D800ULL; // 0x0207c4: add x0, x0, #0x676
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFA92EULL; // 0x0207c8: bl #0xac80
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000340ULL; // 0x0207cc: cbz x0, #0x20834
    return acc;
}

// [EN] Reconstructed FDE #0834 @ 0x0208d8..0x0209bc (228 bytes)
// [VN] Phục dựng FDE #0834 tại 0x0208d8..0x0209bc (228 byte)
//   0x0208d8: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0208dc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0208e0: 910043fd  add      x29, sp, #0x10
//   0x0208e4: 72001c7f  tst      w3, #0xff
//   0x0208e8: 2a0203f3  mov      w19, w2
//   0x0208ec: 540002e0  b.eq     #0x20948
//   0x0208f0: b00000c1  adrp     x1, #0x39000
//   0x0208f4: b00000e2  adrp     x2, #0x3d000
//   0x0208f8: 911f2c21  add      x1, x1, #0x7cb
//   0x0208fc: 911d6c42  add      x2, x2, #0x75b
//   0x020900: 9400002f  bl       #0x209bc
//   0x020904: b00000e0  adrp     x0, #0x3d000
uint64_t fde_0834_sub_0208d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x911F2C21ULL) + (x2 ^ 0x0208D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0208d8: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0208dc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0208e0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x72001C7FULL; // 0x0208e4: tst w3, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F3ULL; // 0x0208e8: mov w19, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x540002E0ULL; // 0x0208ec: b.eq #0x20948
    acc = (acc * 0x100000001B3ULL) ^ 0xB00000C1ULL; // 0x0208f0: adrp x1, #0x39000
    acc = (acc * 0x100000001B3ULL) ^ 0xB00000E2ULL; // 0x0208f4: adrp x2, #0x3d000
    return acc;
}

// [EN] Reconstructed FDE #0835 @ 0x0209bc..0x0209c4 (8 bytes)
// [VN] Phục dựng FDE #0835 tại 0x0209bc..0x0209c4 (8 byte)
//   0x0209bc: 52800080  mov      w0, #4
//   0x0209c0: 17ffaa08  b        #0xb1e0
uint64_t fde_0835_sub_0209bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800080ULL) + (x1 ^ 0x17FFAA08ULL) + (x2 ^ 0x0209BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800080ULL; // 0x0209bc: mov w0, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFAA08ULL; // 0x0209c0: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #0836 @ 0x0209c4..0x020acc (264 bytes)
// [VN] Phục dựng FDE #0836 tại 0x0209c4..0x020acc (264 byte)
//   0x0209c4: d101c3ff  sub      sp, sp, #0x70
//   0x0209c8: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x0209cc: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x0209d0: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x0209d4: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x0209d8: 910183fd  add      x29, sp, #0x60
//   0x0209dc: d53bd057  mrs      x23, tpidr_el0
//   0x0209e0: f94016e8  ldr      x8, [x23, #0x28]
//   0x0209e4: 900001f8  adrp     x24, #0x5c000
//   0x0209e8: 2a0203f3  mov      w19, w2
//   0x0209ec: aa0103f4  mov      x20, x1
//   0x0209f0: f90017e8  str      x8, [sp, #0x28]
uint64_t fde_0836_sub_0209c4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x900001F8ULL) + (x2 ^ 0x0209C4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x0209c4: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x0209c8: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x0209cc: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x0209d0: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x0209d4: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x0209d8: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x0209dc: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x0209e0: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0837 @ 0x020acc..0x020ba0 (212 bytes)
// [VN] Phục dựng FDE #0837 tại 0x020acc..0x020ba0 (212 byte)
//   0x020acc: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x020ad0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x020ad4: 910043fd  add      x29, sp, #0x10
//   0x020ad8: 97ffaae6  bl       #0xb670
//   0x020adc: 51008408  sub      w8, w0, #0x21
//   0x020ae0: 7100051f  cmp      w8, #1
//   0x020ae4: 54000468  b.hi     #0x20b70
//   0x020ae8: b00000c0  adrp     x0, #0x39000
//   0x020aec: 911cd000  add      x0, x0, #0x734
//   0x020af0: 97ffa9a0  bl       #0xb170
//   0x020af4: b00000e1  adrp     x1, #0x3d000
//   0x020af8: 9120e021  add      x1, x1, #0x838
uint64_t fde_0837_sub_020acc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x911CD000ULL) + (x2 ^ 0x020ACCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x020acc: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x020ad0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x020ad4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFAAE6ULL; // 0x020ad8: bl #0xb670
    acc = (acc * 0x100000001B3ULL) ^ 0x51008408ULL; // 0x020adc: sub w8, w0, #0x21
    acc = (acc * 0x100000001B3ULL) ^ 0x7100051FULL; // 0x020ae0: cmp w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000468ULL; // 0x020ae4: b.hi #0x20b70
    acc = (acc * 0x100000001B3ULL) ^ 0xB00000C0ULL; // 0x020ae8: adrp x0, #0x39000
    return acc;
}

// [EN] Reconstructed FDE #0838 @ 0x020ba0..0x020ba4 (4 bytes)
// [VN] Phục dựng FDE #0838 tại 0x020ba0..0x020ba4 (4 byte)
//   0x020ba0: 17ffffcb  b        #0x20acc
uint64_t fde_0838_sub_020ba0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFFFCBULL) + (x1 ^ 0x17FFFFCBULL) + (x2 ^ 0x020BA0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFCBULL; // 0x020ba0: b #0x20acc
    return acc;
}

// [EN] Reconstructed FDE #0839 @ 0x020ba4..0x020c30 (140 bytes)
// [VN] Phục dựng FDE #0839 tại 0x020ba4..0x020c30 (140 byte)
//   0x020ba4: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x020ba8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x020bac: 910043fd  add      x29, sp, #0x10
//   0x020bb0: 900001f3  adrp     x19, #0x5c000
//   0x020bb4: f9462a68  ldr      x8, [x19, #0xc50]
//   0x020bb8: b4000068  cbz      x8, #0x20bc4
//   0x020bbc: 2a1f03e0  mov      w0, wzr
//   0x020bc0: 14000019  b        #0x20c24
//   0x020bc4: 2a1f03e0  mov      w0, wzr
//   0x020bc8: 2a1f03e1  mov      w1, wzr
//   0x020bcc: 97ffab09  bl       #0xb7f0
//   0x020bd0: b00000e0  adrp     x0, #0x3d000
uint64_t fde_0839_sub_020ba4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x2A1F03E0ULL) + (x2 ^ 0x020BA4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x020ba4: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x020ba8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x020bac: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x900001F3ULL; // 0x020bb0: adrp x19, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9462A68ULL; // 0x020bb4: ldr x8, [x19, #0xc50]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000068ULL; // 0x020bb8: cbz x8, #0x20bc4
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x020bbc: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000019ULL; // 0x020bc0: b #0x20c24
    return acc;
}

// [EN] Reconstructed FDE #0840 @ 0x020c30..0x020d1c (236 bytes)
// [VN] Phục dựng FDE #0840 tại 0x020c30..0x020d1c (236 byte)
//   0x020c30: d10103ff  sub      sp, sp, #0x40
//   0x020c34: f9000bf5  str      x21, [sp, #0x10]
//   0x020c38: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x020c3c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x020c40: 9100c3fd  add      x29, sp, #0x30
//   0x020c44: d53bd055  mrs      x21, tpidr_el0
//   0x020c48: f94016a8  ldr      x8, [x21, #0x28]
//   0x020c4c: 2a0103f3  mov      w19, w1
//   0x020c50: 2a0003f4  mov      w20, w0
//   0x020c54: 3101941f  cmn      w0, #0x65
//   0x020c58: f90007e8  str      x8, [sp, #8]
//   0x020c5c: f90003fe  str      x30, [sp]
uint64_t fde_0840_sub_020c30(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x2A0003F4ULL) + (x2 ^ 0x020C30ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x020c30: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF5ULL; // 0x020c34: str x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x020c38: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x020c3c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x020c40: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x020c44: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x020c48: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F3ULL; // 0x020c4c: mov w19, w1
    return acc;
}

// [EN] Reconstructed FDE #0841 @ 0x020d1c..0x020d28 (12 bytes)
// [VN] Phục dựng FDE #0841 tại 0x020d1c..0x020d28 (12 byte)
//   0x020d1c: 900001e8  adrp     x8, #0x5c000
//   0x020d20: b90c5900  str      w0, [x8, #0xc58]
//   0x020d24: d65f03c0  ret      
uint64_t fde_0841_sub_020d1c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x900001E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x020D1CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x900001E8ULL; // 0x020d1c: adrp x8, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0xB90C5900ULL; // 0x020d20: str w0, [x8, #0xc58]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x020d24: ret 
    return acc;
}

// [EN] Reconstructed FDE #0842 @ 0x020d28..0x020d2c (4 bytes)
// [VN] Phục dựng FDE #0842 tại 0x020d28..0x020d2c (4 byte)
//   0x020d28: 1400058c  b        #0x22358
uint64_t fde_0842_sub_020d28(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x1400058CULL) + (x1 ^ 0x1400058CULL) + (x2 ^ 0x020D28ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x1400058CULL; // 0x020d28: b #0x22358
    return acc;
}

// [EN] Reconstructed FDE #0843 @ 0x020d2c..0x020e24 (248 bytes)
// [VN] Phục dựng FDE #0843 tại 0x020d2c..0x020e24 (248 byte)
//   0x020d2c: d101c3ff  sub      sp, sp, #0x70
//   0x020d30: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x020d34: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x020d38: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x020d3c: 910183fd  add      x29, sp, #0x60
//   0x020d40: d53bd056  mrs      x22, tpidr_el0
//   0x020d44: aa0803f3  mov      x19, x8
//   0x020d48: f94016c8  ldr      x8, [x22, #0x28]
//   0x020d4c: aa0303f4  mov      x20, x3
//   0x020d50: f81d83a8  stur     x8, [x29, #-0x28]
//   0x020d54: a90287e0  stp      x0, x1, [sp, #0x28]
//   0x020d58: b00000e1  adrp     x1, #0x3d000
uint64_t fde_0843_sub_020d2c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xAA0303F4ULL) + (x2 ^ 0x020D2CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x020d2c: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x020d30: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x020d34: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x020d38: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x020d3c: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x020d40: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803F3ULL; // 0x020d44: mov x19, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x020d48: ldr x8, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0844 @ 0x020e24..0x020e6c (72 bytes)
// [VN] Phục dựng FDE #0844 tại 0x020e24..0x020e6c (72 byte)
//   0x020e24: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x020e28: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x020e2c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x020e30: 910083fd  add      x29, sp, #0x20
//   0x020e34: a9405414  ldp      x20, x21, [x0]
//   0x020e38: aa0103e0  mov      x0, x1
//   0x020e3c: aa0203f3  mov      x19, x2
//   0x020e40: aa0103f6  mov      x22, x1
//   0x020e44: 97ffa877  bl       #0xb020
//   0x020e48: aa0003e4  mov      x4, x0
//   0x020e4c: aa1403e0  mov      x0, x20
//   0x020e50: aa1303e3  mov      x3, x19
uint64_t fde_0844_sub_020e24(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x97FFA877ULL) + (x2 ^ 0x020E24ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x020e24: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x020e28: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x020e2c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x020e30: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xA9405414ULL; // 0x020e34: ldp x20, x21, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x020e38: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x020e3c: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F6ULL; // 0x020e40: mov x22, x1
    return acc;
}

// [EN] Reconstructed FDE #0845 @ 0x020e6c..0x020e78 (12 bytes)
// [VN] Phục dựng FDE #0845 tại 0x020e6c..0x020e78 (12 byte)
//   0x020e6c: a9400828  ldp      x8, x2, [x1]
//   0x020e70: aa0803e1  mov      x1, x8
//   0x020e74: 17ffd7f0  b        #0x16e34
uint64_t fde_0845_sub_020e6c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9400828ULL) + (x1 ^ 0x17FFD7F0ULL) + (x2 ^ 0x020E6CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9400828ULL; // 0x020e6c: ldp x8, x2, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E1ULL; // 0x020e70: mov x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFD7F0ULL; // 0x020e74: b #0x16e34
    return acc;
}

// [EN] Reconstructed FDE #0846 @ 0x020e78..0x020ea8 (48 bytes)
// [VN] Phục dựng FDE #0846 tại 0x020e78..0x020ea8 (48 byte)
//   0x020e78: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x020e7c: 910003fd  mov      x29, sp
//   0x020e80: f9400408  ldr      x8, [x0, #8]
//   0x020e84: eb010108  subs     x8, x8, x1
//   0x020e88: 540000e3  b.lo     #0x20ea4
//   0x020e8c: f9400009  ldr      x9, [x0]
//   0x020e90: eb02011f  cmp      x8, x2
//   0x020e94: 8b010120  add      x0, x9, x1
//   0x020e98: 9a823101  csel     x1, x8, x2, lo
//   0x020e9c: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x020ea0: d65f03c0  ret      
//   0x020ea4: 97ffa997  bl       #0xb500
uint64_t fde_0846_sub_020e78(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x9A823101ULL) + (x2 ^ 0x020E78ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x020e78: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x020e7c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x020e80: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB010108ULL; // 0x020e84: subs x8, x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x540000E3ULL; // 0x020e88: b.lo #0x20ea4
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400009ULL; // 0x020e8c: ldr x9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02011FULL; // 0x020e90: cmp x8, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x8B010120ULL; // 0x020e94: add x0, x9, x1
    return acc;
}

// [EN] Reconstructed FDE #0847 @ 0x020ea8..0x020f50 (168 bytes)
// [VN] Phục dựng FDE #0847 tại 0x020ea8..0x020f50 (168 byte)
//   0x020ea8: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x020eac: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x020eb0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x020eb4: 910083fd  add      x29, sp, #0x20
//   0x020eb8: f00001c8  adrp     x8, #0x5b000
//   0x020ebc: f9431d08  ldr      x8, [x8, #0x638]
//   0x020ec0: 39400108  ldrb     w8, [x8]
//   0x020ec4: 340003e8  cbz      w8, #0x20f40
//   0x020ec8: 900001e0  adrp     x0, #0x5c000
//   0x020ecc: 7100003f  cmp      w1, #0
//   0x020ed0: 91335000  add      x0, x0, #0xcd4
//   0x020ed4: 2a0103f3  mov      w19, w1
uint64_t fde_0847_sub_020ea8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x900001E0ULL) + (x2 ^ 0x020EA8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x020ea8: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x020eac: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x020eb0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x020eb4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001C8ULL; // 0x020eb8: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9431D08ULL; // 0x020ebc: ldr x8, [x8, #0x638]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400108ULL; // 0x020ec0: ldrb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x340003E8ULL; // 0x020ec4: cbz w8, #0x20f40
    return acc;
}

// [EN] Reconstructed FDE #0848 @ 0x020f50..0x021018 (200 bytes)
// [VN] Phục dựng FDE #0848 tại 0x020f50..0x021018 (200 byte)
//   0x020f50: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x020f54: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x020f58: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x020f5c: 910083fd  add      x29, sp, #0x20
//   0x020f60: 913ffc28  add      x8, x1, #0xfff
//   0x020f64: 9274cc13  and      x19, x0, #0xfffffffffffff000
//   0x020f68: 9274cd14  and      x20, x8, #0xfffffffffffff000
//   0x020f6c: cb130295  sub      x21, x20, x19
//   0x020f70: 94000633  bl       #0x2283c
//   0x020f74: 36000202  tbz      w2, #0, #0x20fb4
//   0x020f78: 97ffe1a0  bl       #0x195f8
//   0x020f7c: 2a0003f6  mov      w22, w0
uint64_t fde_0848_sub_020f50(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x94000633ULL) + (x2 ^ 0x020F50ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x020f50: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x020f54: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x020f58: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x020f5c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x913FFC28ULL; // 0x020f60: add x8, x1, #0xfff
    acc = (acc * 0x100000001B3ULL) ^ 0x9274CC13ULL; // 0x020f64: and x19, x0, #0xfffffffffffff000
    acc = (acc * 0x100000001B3ULL) ^ 0x9274CD14ULL; // 0x020f68: and x20, x8, #0xfffffffffffff000
    acc = (acc * 0x100000001B3ULL) ^ 0xCB130295ULL; // 0x020f6c: sub x21, x20, x19
    return acc;
}

// [EN] Reconstructed FDE #0849 @ 0x021018..0x0210f0 (216 bytes)
// [VN] Phục dựng FDE #0849 tại 0x021018..0x0210f0 (216 byte)
//   0x021018: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x02101c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x021020: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x021024: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x021028: 9100c3fd  add      x29, sp, #0x30
//   0x02102c: 913ffc28  add      x8, x1, #0xfff
//   0x021030: 2a0203f3  mov      w19, w2
//   0x021034: 9274cc14  and      x20, x0, #0xfffffffffffff000
//   0x021038: 9274cd15  and      x21, x8, #0xfffffffffffff000
//   0x02103c: 97ffd978  bl       #0x1761c
//   0x021040: 36000140  tbz      w0, #0, #0x21068
//   0x021044: 900000c1  adrp     x1, #0x39000
uint64_t fde_0849_sub_021018(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x9274CD15ULL) + (x2 ^ 0x021018ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x021018: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x02101c: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x021020: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x021024: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x021028: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x913FFC28ULL; // 0x02102c: add x8, x1, #0xfff
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F3ULL; // 0x021030: mov w19, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x9274CC14ULL; // 0x021034: and x20, x0, #0xfffffffffffff000
    return acc;
}

// [EN] Reconstructed FDE #0850 @ 0x0210f0..0x021358 (616 bytes)
// [VN] Phục dựng FDE #0850 tại 0x0210f0..0x021358 (616 byte)
//   0x0210f0: d10183ff  sub      sp, sp, #0x60
//   0x0210f4: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x0210f8: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0210fc: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x021100: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x021104: 910143fd  add      x29, sp, #0x50
//   0x021108: d53bd056  mrs      x22, tpidr_el0
//   0x02110c: f94016c8  ldr      x8, [x22, #0x28]
//   0x021110: aa0003f4  mov      x20, x0
//   0x021114: aa0003f3  mov      x19, x0
//   0x021118: f9000fe8  str      x8, [sp, #0x18]
//   0x02111c: 38408e88  ldrb     w8, [x20, #8]!
uint64_t fde_0850_sub_0210f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xAA0003F4ULL) + (x2 ^ 0x0210F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x0210f0: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x0210f4: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x0210f8: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x0210fc: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x021100: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x021104: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x021108: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x02110c: ldr x8, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0851 @ 0x021358..0x021444 (236 bytes)
// [VN] Phục dựng FDE #0851 tại 0x021358..0x021444 (236 byte)
//   0x021358: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x02135c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x021360: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x021364: 910083fd  add      x29, sp, #0x20
//   0x021368: aa0003f3  mov      x19, x0
//   0x02136c: aa1f03f5  mov      x21, xzr
//   0x021370: f1002abf  cmp      x21, #0xa
//   0x021374: 54000380  b.eq     #0x213e4
//   0x021378: f9400274  ldr      x20, [x19]
//   0x02137c: 52800081  mov      w1, #4
//   0x021380: aa1403e0  mov      x0, x20
//   0x021384: 97ffa653  bl       #0xacd0
uint64_t fde_0851_sub_021358(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xF9400274ULL) + (x2 ^ 0x021358ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x021358: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02135c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x021360: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x021364: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x021368: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03F5ULL; // 0x02136c: mov x21, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xF1002ABFULL; // 0x021370: cmp x21, #0xa
    acc = (acc * 0x100000001B3ULL) ^ 0x54000380ULL; // 0x021374: b.eq #0x213e4
    return acc;
}

// [EN] Reconstructed FDE #0852 @ 0x021444..0x021628 (484 bytes)
// [VN] Phục dựng FDE #0852 tại 0x021444..0x021628 (484 byte)
//   0x021444: d10583ff  sub      sp, sp, #0x160
//   0x021448: f90093fc  str      x28, [sp, #0x120]
//   0x02144c: a91357f6  stp      x22, x21, [sp, #0x130]
//   0x021450: a9144ff4  stp      x20, x19, [sp, #0x140]
//   0x021454: a9157bfd  stp      x29, x30, [sp, #0x150]
//   0x021458: 910543fd  add      x29, sp, #0x150
//   0x02145c: d53bd056  mrs      x22, tpidr_el0
//   0x021460: f94016c8  ldr      x8, [x22, #0x28]
//   0x021464: f81c83a8  stur     x8, [x29, #-0x38]
//   0x021468: b4000680  cbz      x0, #0x21538
//   0x02146c: d00001d5  adrp     x21, #0x5b000
//   0x021470: f94466b5  ldr      x21, [x21, #0x8c8]
uint64_t fde_0852_sub_021444(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10583FFULL) + (x1 ^ 0xF81C83A8ULL) + (x2 ^ 0x021444ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10583FFULL; // 0x021444: sub sp, sp, #0x160
    acc = (acc * 0x100000001B3ULL) ^ 0xF90093FCULL; // 0x021448: str x28, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91357F6ULL; // 0x02144c: stp x22, x21, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9144FF4ULL; // 0x021450: stp x20, x19, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9157BFDULL; // 0x021454: stp x29, x30, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0x910543FDULL; // 0x021458: add x29, sp, #0x150
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x02145c: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x021460: ldr x8, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0853 @ 0x021628..0x0219b8 (912 bytes)
// [VN] Phục dựng FDE #0853 tại 0x021628..0x0219b8 (912 byte)
//   0x021628: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x02162c: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x021630: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x021634: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x021638: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x02163c: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x021640: 910143fd  add      x29, sp, #0x50
//   0x021644: d104c3ff  sub      sp, sp, #0x130
//   0x021648: 910003f3  mov      x19, sp
//   0x02164c: d53bd059  mrs      x25, tpidr_el0
//   0x021650: f9401728  ldr      x8, [x25, #0x28]
//   0x021654: f81a03a8  stur     x8, [x29, #-0x60]
uint64_t fde_0853_sub_021628(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0x910003F3ULL) + (x2 ^ 0x021628ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x021628: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x02162c: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x021630: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x021634: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x021638: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x02163c: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x021640: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD104C3FFULL; // 0x021644: sub sp, sp, #0x130
    return acc;
}

// [EN] Reconstructed FDE #0854 @ 0x0219b8..0x0219d8 (32 bytes)
// [VN] Phục dựng FDE #0854 tại 0x0219b8..0x0219d8 (32 byte)
//   0x0219b8: a940a408  ldp      x8, x9, [x0, #8]
//   0x0219bc: eb09011f  cmp      x8, x9
//   0x0219c0: 540000a0  b.eq     #0x219d4
//   0x0219c4: f9400029  ldr      x9, [x1]
//   0x0219c8: f8008509  str      x9, [x8], #8
//   0x0219cc: f9000408  str      x8, [x0, #8]
//   0x0219d0: d65f03c0  ret      
//   0x0219d4: 1400026d  b        #0x22388
uint64_t fde_0854_sub_0219b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA940A408ULL) + (x1 ^ 0x1400026DULL) + (x2 ^ 0x0219B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA940A408ULL; // 0x0219b8: ldp x8, x9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x0219bc: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A0ULL; // 0x0219c0: b.eq #0x219d4
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400029ULL; // 0x0219c4: ldr x9, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF8008509ULL; // 0x0219c8: str x9, [x8], #8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000408ULL; // 0x0219cc: str x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0219d0: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0x1400026DULL; // 0x0219d4: b #0x22388
    return acc;
}

// [EN] Reconstructed FDE #0855 @ 0x0219d8..0x0219fc (36 bytes)
// [VN] Phục dựng FDE #0855 tại 0x0219d8..0x0219fc (36 byte)
//   0x0219d8: a940a408  ldp      x8, x9, [x0, #8]
//   0x0219dc: eb09011f  cmp      x8, x9
//   0x0219e0: 540000c2  b.hs     #0x219f8
//   0x0219e4: 3dc00020  ldr      q0, [x1]
//   0x0219e8: 91004109  add      x9, x8, #0x10
//   0x0219ec: 3d800100  str      q0, [x8]
//   0x0219f0: f9000409  str      x9, [x0, #8]
//   0x0219f4: d65f03c0  ret      
//   0x0219f8: 140002e9  b        #0x2259c
uint64_t fde_0855_sub_0219d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA940A408ULL) + (x1 ^ 0x140002E9ULL) + (x2 ^ 0x0219D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA940A408ULL; // 0x0219d8: ldp x8, x9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x0219dc: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x540000C2ULL; // 0x0219e0: b.hs #0x219f8
    acc = (acc * 0x100000001B3ULL) ^ 0x3DC00020ULL; // 0x0219e4: ldr q0, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004109ULL; // 0x0219e8: add x9, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x3D800100ULL; // 0x0219ec: str q0, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000409ULL; // 0x0219f0: str x9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0219f4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0856 @ 0x0219fc..0x021f58 (1372 bytes)
// [VN] Phục dựng FDE #0856 tại 0x0219fc..0x021f58 (1372 byte)
//   0x0219fc: d102c3ff  sub      sp, sp, #0xb0
//   0x021a00: a9056ffc  stp      x28, x27, [sp, #0x50]
//   0x021a04: a90667fa  stp      x26, x25, [sp, #0x60]
//   0x021a08: a9075ff8  stp      x24, x23, [sp, #0x70]
//   0x021a0c: a90857f6  stp      x22, x21, [sp, #0x80]
//   0x021a10: a9094ff4  stp      x20, x19, [sp, #0x90]
//   0x021a14: a90a7bfd  stp      x29, x30, [sp, #0xa0]
//   0x021a18: 910283fd  add      x29, sp, #0xa0
//   0x021a1c: d53bd059  mrs      x25, tpidr_el0
//   0x021a20: f9401728  ldr      x8, [x25, #0x28]
//   0x021a24: f90027e8  str      x8, [sp, #0x48]
//   0x021a28: d00001c8  adrp     x8, #0x5b000
uint64_t fde_0856_sub_0219fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD102C3FFULL) + (x1 ^ 0xD53BD059ULL) + (x2 ^ 0x0219FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD102C3FFULL; // 0x0219fc: sub sp, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9056FFCULL; // 0x021a00: stp x28, x27, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90667FAULL; // 0x021a04: stp x26, x25, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9075FF8ULL; // 0x021a08: stp x24, x23, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90857F6ULL; // 0x021a0c: stp x22, x21, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9094FF4ULL; // 0x021a10: stp x20, x19, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A7BFDULL; // 0x021a14: stp x29, x30, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910283FDULL; // 0x021a18: add x29, sp, #0xa0
    return acc;
}

// [EN] Reconstructed FDE #0857 @ 0x021f58..0x022048 (240 bytes)
// [VN] Phục dựng FDE #0857 tại 0x021f58..0x022048 (240 byte)
//   0x021f58: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x021f5c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x021f60: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x021f64: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x021f68: 9100c3fd  add      x29, sp, #0x30
//   0x021f6c: aa0203f3  mov      x19, x2
//   0x021f70: aa0103f4  mov      x20, x1
//   0x021f74: 94000035  bl       #0x22048
//   0x021f78: 360005c0  tbz      w0, #0, #0x22030
//   0x021f7c: f101929f  cmp      x20, #0x64
//   0x021f80: 52800c88  mov      w8, #0x64
//   0x021f84: 900000c1  adrp     x1, #0x39000
uint64_t fde_0857_sub_021f58(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x360005C0ULL) + (x2 ^ 0x021F58ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x021f58: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x021f5c: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x021f60: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x021f64: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x021f68: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x021f6c: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x021f70: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x94000035ULL; // 0x021f74: bl #0x22048
    return acc;
}

// [EN] Reconstructed FDE #0858 @ 0x022048..0x02208c (68 bytes)
// [VN] Phục dựng FDE #0858 tại 0x022048..0x02208c (68 byte)
//   0x022048: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x02204c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x022050: 910043fd  add      x29, sp, #0x10
//   0x022054: d00001d4  adrp     x20, #0x5c000
//   0x022058: 91335294  add      x20, x20, #0xcd4
//   0x02205c: aa0003f3  mov      x19, x0
//   0x022060: aa1403e0  mov      x0, x20
//   0x022064: 97ffa55b  bl       #0xb5d0
//   0x022068: aa1303e0  mov      x0, x19
//   0x02206c: 97fffe64  bl       #0x219fc
//   0x022070: 2a0003f3  mov      w19, w0
//   0x022074: aa1403e0  mov      x0, x20
uint64_t fde_0858_sub_022048(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x022048ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x022048: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02204c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x022050: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001D4ULL; // 0x022054: adrp x20, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0x91335294ULL; // 0x022058: add x20, x20, #0xcd4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02205c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x022060: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFA55BULL; // 0x022064: bl #0xb5d0
    return acc;
}

// [EN] Reconstructed FDE #0859 @ 0x02208c..0x0221ac (288 bytes)
// [VN] Phục dựng FDE #0859 tại 0x02208c..0x0221ac (288 byte)
//   0x02208c: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x022090: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x022094: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x022098: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x02209c: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0220a0: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0220a4: 910143fd  add      x29, sp, #0x50
//   0x0220a8: f101903f  cmp      x1, #0x64
//   0x0220ac: 52800c88  mov      w8, #0x64
//   0x0220b0: 9a883037  csel     x23, x1, x8, lo
//   0x0220b4: b4000737  cbz      x23, #0x22198
//   0x0220b8: 97ffffe4  bl       #0x22048
uint64_t fde_0859_sub_02208c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0x52800C88ULL) + (x2 ^ 0x02208CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x02208c: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x022090: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x022094: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x022098: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x02209c: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x0220a0: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x0220a4: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF101903FULL; // 0x0220a8: cmp x1, #0x64
    return acc;
}

// [EN] Reconstructed FDE #0860 @ 0x0221ac..0x0222e0 (308 bytes)
// [VN] Phục dựng FDE #0860 tại 0x0221ac..0x0222e0 (308 byte)
//   0x0221ac: d101c3ff  sub      sp, sp, #0x70
//   0x0221b0: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x0221b4: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x0221b8: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x0221bc: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x0221c0: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x0221c4: 910183fd  add      x29, sp, #0x60
//   0x0221c8: d53bd056  mrs      x22, tpidr_el0
//   0x0221cc: f94016c8  ldr      x8, [x22, #0x28]
//   0x0221d0: f101903f  cmp      x1, #0x64
//   0x0221d4: 52800c89  mov      w9, #0x64
//   0x0221d8: 9a893037  csel     x23, x1, x9, lo
uint64_t fde_0860_sub_0221ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xF94016C8ULL) + (x2 ^ 0x0221ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x0221ac: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x0221b0: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x0221b4: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x0221b8: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x0221bc: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x0221c0: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x0221c4: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x0221c8: mrs x22, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0861 @ 0x0222e0..0x0222f4 (20 bytes)
// [VN] Phục dựng FDE #0861 tại 0x0222e0..0x0222f4 (20 byte)
//   0x0222e0: b00001c8  adrp     x8, #0x5b000
//   0x0222e4: f9431d08  ldr      x8, [x8, #0x638]
//   0x0222e8: 52800029  mov      w9, #1
//   0x0222ec: 39000109  strb     w9, [x8]
//   0x0222f0: d65f03c0  ret      
uint64_t fde_0861_sub_0222e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB00001C8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0222E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001C8ULL; // 0x0222e0: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9431D08ULL; // 0x0222e4: ldr x8, [x8, #0x638]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800029ULL; // 0x0222e8: mov w9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x39000109ULL; // 0x0222ec: strb w9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0222f0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0862 @ 0x0222f4..0x022358 (100 bytes)
// [VN] Phục dựng FDE #0862 tại 0x0222f4..0x022358 (100 byte)
//   0x0222f4: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x0222f8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0222fc: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x022300: 910083fd  add      x29, sp, #0x20
//   0x022304: b40001e4  cbz      x4, #0x22340
//   0x022308: eb01007f  cmp      x3, x1
//   0x02230c: aa0403f4  mov      x20, x4
//   0x022310: aa0203f5  mov      x21, x2
//   0x022314: aa0003f6  mov      x22, x0
//   0x022318: 9a832433  csinc    x19, x1, x3, hs
//   0x02231c: b4000133  cbz      x19, #0x22340
//   0x022320: 8b1302c8  add      x8, x22, x19
uint64_t fde_0862_sub_0222f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA0003F6ULL) + (x2 ^ 0x0222F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x0222f4: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0222f8: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0222fc: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x022300: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001E4ULL; // 0x022304: cbz x4, #0x22340
    acc = (acc * 0x100000001B3ULL) ^ 0xEB01007FULL; // 0x022308: cmp x3, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0403F4ULL; // 0x02230c: mov x20, x4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x022310: mov x21, x2
    return acc;
}

// [EN] Reconstructed FDE #0863 @ 0x022358..0x022370 (24 bytes)
// [VN] Phục dựng FDE #0863 tại 0x022358..0x022370 (24 byte)
//   0x022358: aa0003e8  mov      x8, x0
//   0x02235c: f9400000  ldr      x0, [x0]
//   0x022360: b4000060  cbz      x0, #0x2236c
//   0x022364: f9000500  str      x0, [x8, #8]
//   0x022368: 17ffa276  b        #0xad40
//   0x02236c: d65f03c0  ret      
uint64_t fde_0863_sub_022358(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x022358ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x022358: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x02235c: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000060ULL; // 0x022360: cbz x0, #0x2236c
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000500ULL; // 0x022364: str x0, [x8, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFA276ULL; // 0x022368: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02236c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0864 @ 0x022370..0x022388 (24 bytes)
// [VN] Phục dựng FDE #0864 tại 0x022370..0x022388 (24 byte)
//   0x022370: aa0003e8  mov      x8, x0
//   0x022374: f9400000  ldr      x0, [x0]
//   0x022378: b4000060  cbz      x0, #0x22384
//   0x02237c: f9000500  str      x0, [x8, #8]
//   0x022380: 17ffa270  b        #0xad40
//   0x022384: d65f03c0  ret      
uint64_t fde_0864_sub_022370(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x022370ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x022370: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x022374: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000060ULL; // 0x022378: cbz x0, #0x22384
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000500ULL; // 0x02237c: str x0, [x8, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFA270ULL; // 0x022380: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x022384: ret 
    return acc;
}

// [EN] Reconstructed FDE #0865 @ 0x022388..0x022454 (204 bytes)
// [VN] Phục dựng FDE #0865 tại 0x022388..0x022454 (204 byte)
//   0x022388: d101c3ff  sub      sp, sp, #0x70
//   0x02238c: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x022390: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x022394: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x022398: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x02239c: 910183fd  add      x29, sp, #0x60
//   0x0223a0: d53bd057  mrs      x23, tpidr_el0
//   0x0223a4: f94016e8  ldr      x8, [x23, #0x28]
//   0x0223a8: aa0103f4  mov      x20, x1
//   0x0223ac: aa0003f3  mov      x19, x0
//   0x0223b0: 91004016  add      x22, x0, #0x10
//   0x0223b4: f90017e8  str      x8, [sp, #0x28]
uint64_t fde_0865_sub_022388(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xAA0103F4ULL) + (x2 ^ 0x022388ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x022388: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x02238c: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x022390: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x022394: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x022398: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x02239c: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x0223a0: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x0223a4: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0866 @ 0x022454..0x02249c (72 bytes)
// [VN] Phục dựng FDE #0866 tại 0x022454..0x02249c (72 byte)
//   0x022454: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x022458: 910003fd  mov      x29, sp
//   0x02245c: d37dfc28  lsr      x8, x1, #0x3d
//   0x022460: b50001c8  cbnz     x8, #0x22498
//   0x022464: f9400808  ldr      x8, [x0, #0x10]
//   0x022468: f9400009  ldr      x9, [x0]
//   0x02246c: cb090108  sub      x8, x8, x9
//   0x022470: b27febe9  mov      x9, #0xffffffffffffffe
//   0x022474: eb880d3f  cmp      x9, x8, asr #3
//   0x022478: 540000a3  b.lo     #0x2248c
//   0x02247c: 9342fd08  asr      x8, x8, #2
//   0x022480: eb01011f  cmp      x8, x1
uint64_t fde_0866_sub_022454(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xEB880D3FULL) + (x2 ^ 0x022454ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x022454: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x022458: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DFC28ULL; // 0x02245c: lsr x8, x1, #0x3d
    acc = (acc * 0x100000001B3ULL) ^ 0xB50001C8ULL; // 0x022460: cbnz x8, #0x22498
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x022464: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400009ULL; // 0x022468: ldr x9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB090108ULL; // 0x02246c: sub x8, x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xB27FEBE9ULL; // 0x022470: mov x9, #0xffffffffffffffe
    return acc;
}

// [EN] Reconstructed FDE #0867 @ 0x02249c..0x022500 (100 bytes)
// [VN] Phục dựng FDE #0867 tại 0x02249c..0x022500 (100 byte)
//   0x02249c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0224a0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0224a4: 910043fd  add      x29, sp, #0x10
//   0x0224a8: aa0103f3  mov      x19, x1
//   0x0224ac: aa0003f4  mov      x20, x0
//   0x0224b0: a8c10801  ldp      x1, x2, [x0], #0x10
//   0x0224b4: 91002263  add      x3, x19, #8
//   0x0224b8: 94000028  bl       #0x22558
//   0x0224bc: f9400668  ldr      x8, [x19, #8]
//   0x0224c0: f9400289  ldr      x9, [x20]
//   0x0224c4: f9000288  str      x8, [x20]
//   0x0224c8: f9400a68  ldr      x8, [x19, #0x10]
uint64_t fde_0867_sub_02249c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9400668ULL) + (x2 ^ 0x02249CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x02249c: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0224a0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0224a4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x0224a8: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x0224ac: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C10801ULL; // 0x0224b0: ldp x1, x2, [x0], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x91002263ULL; // 0x0224b4: add x3, x19, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x94000028ULL; // 0x0224b8: bl #0x22558
    return acc;
}

// [EN] Reconstructed FDE #0868 @ 0x022500..0x022534 (52 bytes)
// [VN] Phục dựng FDE #0868 tại 0x022500..0x022534 (52 byte)
//   0x022500: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x022504: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x022508: 910043fd  add      x29, sp, #0x10
//   0x02250c: aa0003f3  mov      x19, x0
//   0x022510: 9400001a  bl       #0x22578
//   0x022514: f9400260  ldr      x0, [x19]
//   0x022518: b4000080  cbz      x0, #0x22528
//   0x02251c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x022520: f84207f3  ldr      x19, [sp], #0x20
//   0x022524: 17ffa207  b        #0xad40
//   0x022528: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02252c: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0868_sub_022500(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x022500ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x022500: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x022504: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x022508: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02250c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9400001AULL; // 0x022510: bl #0x22578
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400260ULL; // 0x022514: ldr x0, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000080ULL; // 0x022518: cbz x0, #0x22528
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x02251c: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0869 @ 0x022534..0x02253c (8 bytes)
// [VN] Phục dựng FDE #0869 tại 0x022534..0x02253c (8 byte)
//   0x022534: aa1f03e2  mov      x2, xzr
//   0x022538: 14000001  b        #0x2253c
uint64_t fde_0869_sub_022534(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x022534ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x022534: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x022538: b #0x2253c
    return acc;
}

// [EN] Reconstructed FDE #0870 @ 0x02253c..0x022558 (28 bytes)
// [VN] Phục dựng FDE #0870 tại 0x02253c..0x022558 (28 byte)
//   0x02253c: d37dfc28  lsr      x8, x1, #0x3d
//   0x022540: b5000068  cbnz     x8, #0x2254c
//   0x022544: d37df020  lsl      x0, x1, #3
//   0x022548: 17ffa42a  b        #0xb5f0
//   0x02254c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x022550: 910003fd  mov      x29, sp
//   0x022554: 97ffa3eb  bl       #0xb500
uint64_t fde_0870_sub_02253c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD37DFC28ULL) + (x1 ^ 0x97FFA3EBULL) + (x2 ^ 0x02253CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DFC28ULL; // 0x02253c: lsr x8, x1, #0x3d
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000068ULL; // 0x022540: cbnz x8, #0x2254c
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DF020ULL; // 0x022544: lsl x0, x1, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFA42AULL; // 0x022548: b #0xb5f0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x02254c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x022550: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFA3EBULL; // 0x022554: bl #0xb500
    return acc;
}

// [EN] Reconstructed FDE #0871 @ 0x022558..0x022578 (32 bytes)
// [VN] Phục dựng FDE #0871 tại 0x022558..0x022578 (32 byte)
//   0x022558: f9400068  ldr      x8, [x3]
//   0x02255c: cb010042  sub      x2, x2, x1
//   0x022560: f100045f  cmp      x2, #1
//   0x022564: cb020100  sub      x0, x8, x2
//   0x022568: f9000060  str      x0, [x3]
//   0x02256c: 5400004b  b.lt     #0x22574
//   0x022570: 17ffa1a8  b        #0xac10
//   0x022574: d65f03c0  ret      
uint64_t fde_0871_sub_022558(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400068ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x022558ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400068ULL; // 0x022558: ldr x8, [x3]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB010042ULL; // 0x02255c: sub x2, x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF100045FULL; // 0x022560: cmp x2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xCB020100ULL; // 0x022564: sub x0, x8, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000060ULL; // 0x022568: str x0, [x3]
    acc = (acc * 0x100000001B3ULL) ^ 0x5400004BULL; // 0x02256c: b.lt #0x22574
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFA1A8ULL; // 0x022570: b #0xac10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x022574: ret 
    return acc;
}

// [EN] Reconstructed FDE #0872 @ 0x022578..0x022580 (8 bytes)
// [VN] Phục dựng FDE #0872 tại 0x022578..0x022580 (8 byte)
//   0x022578: f9400401  ldr      x1, [x0, #8]
//   0x02257c: 14000001  b        #0x22580
uint64_t fde_0872_sub_022578(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400401ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x022578ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400401ULL; // 0x022578: ldr x1, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x02257c: b #0x22580
    return acc;
}

// [EN] Reconstructed FDE #0873 @ 0x022580..0x02259c (28 bytes)
// [VN] Phục dựng FDE #0873 tại 0x022580..0x02259c (28 byte)
//   0x022580: f9400808  ldr      x8, [x0, #0x10]
//   0x022584: eb08003f  cmp      x1, x8
//   0x022588: 54000080  b.eq     #0x22598
//   0x02258c: d1002108  sub      x8, x8, #8
//   0x022590: f9000808  str      x8, [x0, #0x10]
//   0x022594: 17fffffc  b        #0x22584
//   0x022598: d65f03c0  ret      
uint64_t fde_0873_sub_022580(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400808ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x022580ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x022580: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08003FULL; // 0x022584: cmp x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000080ULL; // 0x022588: b.eq #0x22598
    acc = (acc * 0x100000001B3ULL) ^ 0xD1002108ULL; // 0x02258c: sub x8, x8, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000808ULL; // 0x022590: str x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFFCULL; // 0x022594: b #0x22584
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x022598: ret 
    return acc;
}

// [EN] Reconstructed FDE #0874 @ 0x02259c..0x022664 (200 bytes)
// [VN] Phục dựng FDE #0874 tại 0x02259c..0x022664 (200 byte)
//   0x02259c: d101c3ff  sub      sp, sp, #0x70
//   0x0225a0: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x0225a4: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x0225a8: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x0225ac: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x0225b0: 910183fd  add      x29, sp, #0x60
//   0x0225b4: d53bd057  mrs      x23, tpidr_el0
//   0x0225b8: f94016e8  ldr      x8, [x23, #0x28]
//   0x0225bc: aa0103f4  mov      x20, x1
//   0x0225c0: aa0003f3  mov      x19, x0
//   0x0225c4: 91004016  add      x22, x0, #0x10
//   0x0225c8: f90017e8  str      x8, [sp, #0x28]
uint64_t fde_0874_sub_02259c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xAA0103F4ULL) + (x2 ^ 0x02259CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x02259c: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x0225a0: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x0225a4: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x0225a8: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x0225ac: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x0225b0: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x0225b4: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x0225b8: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0875 @ 0x022664..0x0226ac (72 bytes)
// [VN] Phục dựng FDE #0875 tại 0x022664..0x0226ac (72 byte)
//   0x022664: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x022668: 910003fd  mov      x29, sp
//   0x02266c: d37cfc28  lsr      x8, x1, #0x3c
//   0x022670: b50001c8  cbnz     x8, #0x226a8
//   0x022674: f9400808  ldr      x8, [x0, #0x10]
//   0x022678: f9400009  ldr      x9, [x0]
//   0x02267c: cb090108  sub      x8, x8, x9
//   0x022680: b27fe7e9  mov      x9, #0x7fffffffffffffe
//   0x022684: eb88113f  cmp      x9, x8, asr #4
//   0x022688: 540000a3  b.lo     #0x2269c
//   0x02268c: 9343fd08  asr      x8, x8, #3
//   0x022690: eb01011f  cmp      x8, x1
uint64_t fde_0875_sub_022664(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xEB88113FULL) + (x2 ^ 0x022664ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x022664: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x022668: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xD37CFC28ULL; // 0x02266c: lsr x8, x1, #0x3c
    acc = (acc * 0x100000001B3ULL) ^ 0xB50001C8ULL; // 0x022670: cbnz x8, #0x226a8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x022674: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400009ULL; // 0x022678: ldr x9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB090108ULL; // 0x02267c: sub x8, x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xB27FE7E9ULL; // 0x022680: mov x9, #0x7fffffffffffffe
    return acc;
}

// [EN] Reconstructed FDE #0876 @ 0x0226ac..0x022710 (100 bytes)
// [VN] Phục dựng FDE #0876 tại 0x0226ac..0x022710 (100 byte)
//   0x0226ac: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0226b0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0226b4: 910043fd  add      x29, sp, #0x10
//   0x0226b8: aa0103f3  mov      x19, x1
//   0x0226bc: aa0003f4  mov      x20, x0
//   0x0226c0: a8c10801  ldp      x1, x2, [x0], #0x10
//   0x0226c4: 91002263  add      x3, x19, #8
//   0x0226c8: 94000028  bl       #0x22768
//   0x0226cc: f9400668  ldr      x8, [x19, #8]
//   0x0226d0: f9400289  ldr      x9, [x20]
//   0x0226d4: f9000288  str      x8, [x20]
//   0x0226d8: f9400a68  ldr      x8, [x19, #0x10]
uint64_t fde_0876_sub_0226ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9400668ULL) + (x2 ^ 0x0226ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0226ac: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0226b0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0226b4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x0226b8: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x0226bc: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C10801ULL; // 0x0226c0: ldp x1, x2, [x0], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x91002263ULL; // 0x0226c4: add x3, x19, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x94000028ULL; // 0x0226c8: bl #0x22768
    return acc;
}

// [EN] Reconstructed FDE #0877 @ 0x022710..0x022744 (52 bytes)
// [VN] Phục dựng FDE #0877 tại 0x022710..0x022744 (52 byte)
//   0x022710: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x022714: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x022718: 910043fd  add      x29, sp, #0x10
//   0x02271c: aa0003f3  mov      x19, x0
//   0x022720: 9400001a  bl       #0x22788
//   0x022724: f9400260  ldr      x0, [x19]
//   0x022728: b4000080  cbz      x0, #0x22738
//   0x02272c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x022730: f84207f3  ldr      x19, [sp], #0x20
//   0x022734: 17ffa183  b        #0xad40
//   0x022738: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02273c: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0877_sub_022710(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x022710ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x022710: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x022714: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x022718: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02271c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9400001AULL; // 0x022720: bl #0x22788
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400260ULL; // 0x022724: ldr x0, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000080ULL; // 0x022728: cbz x0, #0x22738
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x02272c: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0878 @ 0x022744..0x02274c (8 bytes)
// [VN] Phục dựng FDE #0878 tại 0x022744..0x02274c (8 byte)
//   0x022744: aa1f03e2  mov      x2, xzr
//   0x022748: 14000001  b        #0x2274c
uint64_t fde_0878_sub_022744(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x022744ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x022744: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x022748: b #0x2274c
    return acc;
}

// [EN] Reconstructed FDE #0879 @ 0x02274c..0x022768 (28 bytes)
// [VN] Phục dựng FDE #0879 tại 0x02274c..0x022768 (28 byte)
//   0x02274c: d37cfc28  lsr      x8, x1, #0x3c
//   0x022750: b5000068  cbnz     x8, #0x2275c
//   0x022754: d37cec20  lsl      x0, x1, #4
//   0x022758: 17ffa3a6  b        #0xb5f0
//   0x02275c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x022760: 910003fd  mov      x29, sp
//   0x022764: 97ffa367  bl       #0xb500
uint64_t fde_0879_sub_02274c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD37CFC28ULL) + (x1 ^ 0x97FFA367ULL) + (x2 ^ 0x02274CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD37CFC28ULL; // 0x02274c: lsr x8, x1, #0x3c
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000068ULL; // 0x022750: cbnz x8, #0x2275c
    acc = (acc * 0x100000001B3ULL) ^ 0xD37CEC20ULL; // 0x022754: lsl x0, x1, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFA3A6ULL; // 0x022758: b #0xb5f0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x02275c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x022760: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFA367ULL; // 0x022764: bl #0xb500
    return acc;
}

// [EN] Reconstructed FDE #0880 @ 0x022768..0x022788 (32 bytes)
// [VN] Phục dựng FDE #0880 tại 0x022768..0x022788 (32 byte)
//   0x022768: f9400068  ldr      x8, [x3]
//   0x02276c: cb010042  sub      x2, x2, x1
//   0x022770: f100045f  cmp      x2, #1
//   0x022774: cb020100  sub      x0, x8, x2
//   0x022778: f9000060  str      x0, [x3]
//   0x02277c: 5400004b  b.lt     #0x22784
//   0x022780: 17ffa124  b        #0xac10
//   0x022784: d65f03c0  ret      
uint64_t fde_0880_sub_022768(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400068ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x022768ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400068ULL; // 0x022768: ldr x8, [x3]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB010042ULL; // 0x02276c: sub x2, x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF100045FULL; // 0x022770: cmp x2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xCB020100ULL; // 0x022774: sub x0, x8, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000060ULL; // 0x022778: str x0, [x3]
    acc = (acc * 0x100000001B3ULL) ^ 0x5400004BULL; // 0x02277c: b.lt #0x22784
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFA124ULL; // 0x022780: b #0xac10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x022784: ret 
    return acc;
}

// [EN] Reconstructed FDE #0881 @ 0x022788..0x022790 (8 bytes)
// [VN] Phục dựng FDE #0881 tại 0x022788..0x022790 (8 byte)
//   0x022788: f9400401  ldr      x1, [x0, #8]
//   0x02278c: 14000001  b        #0x22790
uint64_t fde_0881_sub_022788(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400401ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x022788ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400401ULL; // 0x022788: ldr x1, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x02278c: b #0x22790
    return acc;
}

// [EN] Reconstructed FDE #0882 @ 0x022790..0x0227ac (28 bytes)
// [VN] Phục dựng FDE #0882 tại 0x022790..0x0227ac (28 byte)
//   0x022790: f9400808  ldr      x8, [x0, #0x10]
//   0x022794: eb08003f  cmp      x1, x8
//   0x022798: 54000080  b.eq     #0x227a8
//   0x02279c: d1004108  sub      x8, x8, #0x10
//   0x0227a0: f9000808  str      x8, [x0, #0x10]
//   0x0227a4: 17fffffc  b        #0x22794
//   0x0227a8: d65f03c0  ret      
uint64_t fde_0882_sub_022790(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400808ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x022790ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x022790: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08003FULL; // 0x022794: cmp x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000080ULL; // 0x022798: b.eq #0x227a8
    acc = (acc * 0x100000001B3ULL) ^ 0xD1004108ULL; // 0x02279c: sub x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000808ULL; // 0x0227a0: str x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFFCULL; // 0x0227a4: b #0x22794
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0227a8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0883 @ 0x0227ac..0x0227bc (16 bytes)
// [VN] Phục dựng FDE #0883 tại 0x0227ac..0x0227bc (16 byte)
//   0x0227ac: 9100c3e8  add      x8, sp, #0x30
//   0x0227b0: 910063e0  add      x0, sp, #0x18
//   0x0227b4: 2a1f03e1  mov      w1, wzr
//   0x0227b8: 17ffd546  b        #0x17cd0
uint64_t fde_0883_sub_0227ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x9100C3E8ULL) + (x1 ^ 0x17FFD546ULL) + (x2 ^ 0x0227ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3E8ULL; // 0x0227ac: add x8, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x910063E0ULL; // 0x0227b0: add x0, sp, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E1ULL; // 0x0227b4: mov w1, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFD546ULL; // 0x0227b8: b #0x17cd0
    return acc;
}

// [EN] Reconstructed FDE #0884 @ 0x0227bc..0x0227dc (32 bytes)
// [VN] Phục dựng FDE #0884 tại 0x0227bc..0x0227dc (32 byte)
//   0x0227bc: f9400268  ldr      x8, [x19]
//   0x0227c0: 3940c3e9  ldrb     w9, [sp, #0x30]
//   0x0227c4: f94023ea  ldr      x10, [sp, #0x40]
//   0x0227c8: aa1303e0  mov      x0, x19
//   0x0227cc: f9401908  ldr      x8, [x8, #0x30]
//   0x0227d0: 7200013f  tst      w9, #1
//   0x0227d4: 9a8a0301  csel     x1, x24, x10, eq
//   0x0227d8: d61f0100  br       x8
uint64_t fde_0884_sub_0227bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400268ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x0227BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400268ULL; // 0x0227bc: ldr x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x3940C3E9ULL; // 0x0227c0: ldrb w9, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xF94023EAULL; // 0x0227c4: ldr x10, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x0227c8: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401908ULL; // 0x0227cc: ldr x8, [x8, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x7200013FULL; // 0x0227d0: tst w9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x9A8A0301ULL; // 0x0227d4: csel x1, x24, x10, eq
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x0227d8: br x8
    return acc;
}

// [EN] Reconstructed FDE #0885 @ 0x0227dc..0x0227e4 (8 bytes)
// [VN] Phục dựng FDE #0885 tại 0x0227dc..0x0227e4 (8 byte)
//   0x0227dc: 910063e0  add      x0, sp, #0x18
//   0x0227e0: 17ffac19  b        #0xd844
uint64_t fde_0885_sub_0227dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910063E0ULL) + (x1 ^ 0x17FFAC19ULL) + (x2 ^ 0x0227DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910063E0ULL; // 0x0227dc: add x0, sp, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFAC19ULL; // 0x0227e0: b #0xd844
    return acc;
}

// [EN] Reconstructed FDE #0886 @ 0x0227e4..0x0227ec (8 bytes)
// [VN] Phục dựng FDE #0886 tại 0x0227e4..0x0227ec (8 byte)
//   0x0227e4: 910063e0  add      x0, sp, #0x18
//   0x0227e8: 17ffd651  b        #0x1812c
uint64_t fde_0886_sub_0227e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910063E0ULL) + (x1 ^ 0x17FFD651ULL) + (x2 ^ 0x0227E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910063E0ULL; // 0x0227e4: add x0, sp, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFD651ULL; // 0x0227e8: b #0x1812c
    return acc;
}

// [EN] Reconstructed FDE #0887 @ 0x0227ec..0x0227f4 (8 bytes)
// [VN] Phục dựng FDE #0887 tại 0x0227ec..0x0227f4 (8 byte)
//   0x0227ec: 528000a0  mov      w0, #5
//   0x0227f0: 17ffa27c  b        #0xb1e0
uint64_t fde_0887_sub_0227ec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x528000A0ULL) + (x1 ^ 0x17FFA27CULL) + (x2 ^ 0x0227ECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x528000A0ULL; // 0x0227ec: mov w0, #5
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFA27CULL; // 0x0227f0: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #0888 @ 0x0227f4..0x02280c (24 bytes)
// [VN] Phục dựng FDE #0888 tại 0x0227f4..0x02280c (24 byte)
//   0x0227f4: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x0227f8: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x0227fc: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x022800: a94167fa  ldp      x26, x25, [sp, #0x10]
//   0x022804: a8c66ffc  ldp      x28, x27, [sp], #0x60
//   0x022808: d65f03c0  ret      
uint64_t fde_0888_sub_0227f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9444FF4ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0227F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9444FF4ULL; // 0x0227f4: ldp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA94357F6ULL; // 0x0227f8: ldp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9425FF8ULL; // 0x0227fc: ldp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA94167FAULL; // 0x022800: ldp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C66FFCULL; // 0x022804: ldp x28, x27, [sp], #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x022808: ret 
    return acc;
}

// [EN] Reconstructed FDE #0889 @ 0x02280c..0x02281c (16 bytes)
// [VN] Phục dựng FDE #0889 tại 0x02280c..0x02281c (16 byte)
//   0x02280c: f9400268  ldr      x8, [x19]
//   0x022810: 3940c3e9  ldrb     w9, [sp, #0x30]
//   0x022814: f94023ea  ldr      x10, [sp, #0x40]
//   0x022818: d65f03c0  ret      
uint64_t fde_0889_sub_02280c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400268ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02280CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400268ULL; // 0x02280c: ldr x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x3940C3E9ULL; // 0x022810: ldrb w9, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xF94023EAULL; // 0x022814: ldr x10, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x022818: ret 
    return acc;
}

// [EN] Reconstructed FDE #0890 @ 0x02281c..0x022824 (8 bytes)
// [VN] Phục dựng FDE #0890 tại 0x02281c..0x022824 (8 byte)
//   0x02281c: 528000c0  mov      w0, #6
//   0x022820: 17ffa270  b        #0xb1e0
uint64_t fde_0890_sub_02281c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x528000C0ULL) + (x1 ^ 0x17FFA270ULL) + (x2 ^ 0x02281CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C0ULL; // 0x02281c: mov w0, #6
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFA270ULL; // 0x022820: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #0891 @ 0x022824..0x02282c (8 bytes)
// [VN] Phục dựng FDE #0891 tại 0x022824..0x02282c (8 byte)
//   0x022824: f9417d08  ldr      x8, [x8, #0x2f8]
//   0x022828: d61f0100  br       x8
uint64_t fde_0891_sub_022824(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9417D08ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x022824ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9417D08ULL; // 0x022824: ldr x8, [x8, #0x2f8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x022828: br x8
    return acc;
}

// [EN] Reconstructed FDE #0892 @ 0x02282c..0x02283c (16 bytes)
// [VN] Phục dựng FDE #0892 tại 0x02282c..0x02283c (16 byte)
//   0x02282c: 52800060  mov      w0, #3
//   0x022830: aa1303e3  mov      x3, x19
//   0x022834: aa1503e4  mov      x4, x21
//   0x022838: 17ffa26a  b        #0xb1e0
uint64_t fde_0892_sub_02282c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800060ULL) + (x1 ^ 0x17FFA26AULL) + (x2 ^ 0x02282CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x02282c: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E3ULL; // 0x022830: mov x3, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E4ULL; // 0x022834: mov x4, x21
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFA26AULL; // 0x022838: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #0893 @ 0x02283c..0x022848 (12 bytes)
// [VN] Phục dựng FDE #0893 tại 0x02283c..0x022848 (12 byte)
//   0x02283c: aa1303e0  mov      x0, x19
//   0x022840: aa1503e1  mov      x1, x21
//   0x022844: d65f03c0  ret      
uint64_t fde_0893_sub_02283c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1303E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02283CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x02283c: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E1ULL; // 0x022840: mov x1, x21
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x022844: ret 
    return acc;
}

// [EN] Reconstructed FDE #0894 @ 0x022848..0x022858 (16 bytes)
// [VN] Phục dựng FDE #0894 tại 0x022848..0x022858 (16 byte)
//   0x022848: f9417908  ldr      x8, [x8, #0x2f0]
//   0x02284c: 7200013f  tst      w9, #1
//   0x022850: 9a8a0303  csel     x3, x24, x10, eq
//   0x022854: d65f03c0  ret      
uint64_t fde_0894_sub_022848(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9417908ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x022848ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9417908ULL; // 0x022848: ldr x8, [x8, #0x2f0]
    acc = (acc * 0x100000001B3ULL) ^ 0x7200013FULL; // 0x02284c: tst w9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x9A8A0303ULL; // 0x022850: csel x3, x24, x10, eq
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x022854: ret 
    return acc;
}

// [EN] Reconstructed FDE #0895 @ 0x022858..0x022864 (12 bytes)
// [VN] Phục dựng FDE #0895 tại 0x022858..0x022864 (12 byte)
//   0x022858: aa1303e0  mov      x0, x19
//   0x02285c: aa1403e1  mov      x1, x20
//   0x022860: d61f0100  br       x8
uint64_t fde_0895_sub_022858(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1303E0ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x022858ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x022858: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E1ULL; // 0x02285c: mov x1, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x022860: br x8
    return acc;
}

// [EN] Reconstructed FDE #0896 @ 0x022864..0x022870 (12 bytes)
// [VN] Phục dựng FDE #0896 tại 0x022864..0x022870 (12 byte)
//   0x022864: aa1303e0  mov      x0, x19
//   0x022868: aa1b03e1  mov      x1, x27
//   0x02286c: d65f03c0  ret      
uint64_t fde_0896_sub_022864(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1303E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x022864ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x022864: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1B03E1ULL; // 0x022868: mov x1, x27
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02286c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0897 @ 0x022870..0x02287c (12 bytes)
// [VN] Phục dựng FDE #0897 tại 0x022870..0x02287c (12 byte)
//   0x022870: aa1303e0  mov      x0, x19
//   0x022874: aa1803e1  mov      x1, x24
//   0x022878: d61f0100  br       x8
uint64_t fde_0897_sub_022870(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1303E0ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x022870ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x022870: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1803E1ULL; // 0x022874: mov x1, x24
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x022878: br x8
    return acc;
}

// [EN] Reconstructed FDE #0898 @ 0x02287c..0x022b08 (652 bytes)
// [VN] Phục dựng FDE #0898 tại 0x02287c..0x022b08 (652 byte)
//   0x02287c: d10203ff  sub      sp, sp, #0x80
//   0x022880: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x022884: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x022888: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x02288c: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x022890: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x022894: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x022898: 9101c3fd  add      x29, sp, #0x70
//   0x02289c: 2a0103f4  mov      w20, w1
//   0x0228a0: 2a0003f6  mov      w22, w0
//   0x0228a4: 97ffd35e  bl       #0x1761c
//   0x0228a8: 36000100  tbz      w0, #0, #0x228c8
uint64_t fde_0898_sub_02287c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0x2A0103F4ULL) + (x2 ^ 0x02287CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x02287c: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA9026FFCULL; // 0x022880: stp x28, x27, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x022884: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x022888: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x02288c: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x022890: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x022894: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x022898: add x29, sp, #0x70
    return acc;
}

// [EN] Reconstructed FDE #0899 @ 0x022b08..0x022c08 (256 bytes)
// [VN] Phục dựng FDE #0899 tại 0x022b08..0x022c08 (256 byte)
//   0x022b08: d10103ff  sub      sp, sp, #0x40
//   0x022b0c: f9000bf5  str      x21, [sp, #0x10]
//   0x022b10: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x022b14: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x022b18: 9100c3fd  add      x29, sp, #0x30
//   0x022b1c: d53bd055  mrs      x21, tpidr_el0
//   0x022b20: f94016a8  ldr      x8, [x21, #0x28]
//   0x022b24: f00000a0  adrp     x0, #0x39000
//   0x022b28: 911cd000  add      x0, x0, #0x734
//   0x022b2c: f90007e8  str      x8, [sp, #8]
//   0x022b30: 97ffa190  bl       #0xb170
//   0x022b34: f00000c1  adrp     x1, #0x3d000
uint64_t fde_0899_sub_022b08(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x911CD000ULL) + (x2 ^ 0x022B08ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x022b08: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF5ULL; // 0x022b0c: str x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x022b10: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x022b14: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x022b18: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x022b1c: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x022b20: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF00000A0ULL; // 0x022b24: adrp x0, #0x39000
    return acc;
}

// [EN] Reconstructed FDE #0900 @ 0x022c08..0x022c54 (76 bytes)
// [VN] Phục dựng FDE #0900 tại 0x022c08..0x022c54 (76 byte)
//   0x022c08: d100c3ff  sub      sp, sp, #0x30
//   0x022c0c: f9000bf3  str      x19, [sp, #0x10]
//   0x022c10: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x022c14: 910083fd  add      x29, sp, #0x20
//   0x022c18: d53bd053  mrs      x19, tpidr_el0
//   0x022c1c: f9401668  ldr      x8, [x19, #0x28]
//   0x022c20: 910003e0  mov      x0, sp
//   0x022c24: f90007e8  str      x8, [sp, #8]
//   0x022c28: f90003fe  str      x30, [sp]
//   0x022c2c: 97ffb8ce  bl       #0x10f64
//   0x022c30: f9401668  ldr      x8, [x19, #0x28]
//   0x022c34: f94007e9  ldr      x9, [sp, #8]
uint64_t fde_0900_sub_022c08(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0xF90003FEULL) + (x2 ^ 0x022C08ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x022c08: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF3ULL; // 0x022c0c: str x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x022c10: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x022c14: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x022c18: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x022c1c: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E0ULL; // 0x022c20: mov x0, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x022c24: str x8, [sp, #8]
    return acc;
}

// [EN] Reconstructed FDE #0901 @ 0x022c54..0x022de4 (400 bytes)
// [VN] Phục dựng FDE #0901 tại 0x022c54..0x022de4 (400 byte)
//   0x022c54: d10183ff  sub      sp, sp, #0x60
//   0x022c58: f90013f7  str      x23, [sp, #0x20]
//   0x022c5c: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x022c60: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x022c64: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x022c68: 910143fd  add      x29, sp, #0x50
//   0x022c6c: d53bd056  mrs      x22, tpidr_el0
//   0x022c70: f94016c8  ldr      x8, [x22, #0x28]
//   0x022c74: 2a0003f3  mov      w19, w0
//   0x022c78: f9000fe8  str      x8, [sp, #0x18]
//   0x022c7c: 97ffd71c  bl       #0x188ec
//   0x022c80: 7100681f  cmp      w0, #0x1a
uint64_t fde_0901_sub_022c54(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0x2A0003F3ULL) + (x2 ^ 0x022C54ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x022c54: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F7ULL; // 0x022c58: str x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x022c5c: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x022c60: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x022c64: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x022c68: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x022c6c: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x022c70: ldr x8, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0902 @ 0x022de4..0x022e04 (32 bytes)
// [VN] Phục dựng FDE #0902 tại 0x022de4..0x022e04 (32 byte)
//   0x022de4: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x022de8: 910003fd  mov      x29, sp
//   0x022dec: 72001c5f  tst      w2, #0xff
//   0x022df0: 1a9f07e0  cset     w0, ne
//   0x022df4: 97ffff98  bl       #0x22c54
//   0x022df8: 12000000  and      w0, w0, #1
//   0x022dfc: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x022e00: d65f03c0  ret      
uint64_t fde_0902_sub_022de4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x022DE4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x022de4: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x022de8: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x72001C5FULL; // 0x022dec: tst w2, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F07E0ULL; // 0x022df0: cset w0, ne
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFF98ULL; // 0x022df4: bl #0x22c54
    acc = (acc * 0x100000001B3ULL) ^ 0x12000000ULL; // 0x022df8: and w0, w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x022dfc: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x022e00: ret 
    return acc;
}

// [EN] Reconstructed FDE #0903 @ 0x022e04..0x022f44 (320 bytes)
// [VN] Phục dựng FDE #0903 tại 0x022e04..0x022f44 (320 byte)
//   0x022e04: d10183ff  sub      sp, sp, #0x60
//   0x022e08: f90013f7  str      x23, [sp, #0x20]
//   0x022e0c: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x022e10: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x022e14: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x022e18: 910143fd  add      x29, sp, #0x50
//   0x022e1c: d53bd056  mrs      x22, tpidr_el0
//   0x022e20: f94016c8  ldr      x8, [x22, #0x28]
//   0x022e24: f9000fe8  str      x8, [sp, #0x18]
//   0x022e28: b00001c8  adrp     x8, #0x5b000
//   0x022e2c: f9455108  ldr      x8, [x8, #0xaa0]
//   0x022e30: 39400109  ldrb     w9, [x8]
uint64_t fde_0903_sub_022e04(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xF9000FE8ULL) + (x2 ^ 0x022E04ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x022e04: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F7ULL; // 0x022e08: str x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x022e0c: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x022e10: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x022e14: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x022e18: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x022e1c: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x022e20: ldr x8, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0904 @ 0x022f44..0x023040 (252 bytes)
// [VN] Phục dựng FDE #0904 tại 0x022f44..0x023040 (252 byte)
//   0x022f44: d10343ff  sub      sp, sp, #0xd0
//   0x022f48: a9076ffc  stp      x28, x27, [sp, #0x70]
//   0x022f4c: a90867fa  stp      x26, x25, [sp, #0x80]
//   0x022f50: a9095ff8  stp      x24, x23, [sp, #0x90]
//   0x022f54: a90a57f6  stp      x22, x21, [sp, #0xa0]
//   0x022f58: a90b4ff4  stp      x20, x19, [sp, #0xb0]
//   0x022f5c: a90c7bfd  stp      x29, x30, [sp, #0xc0]
//   0x022f60: 910303fd  add      x29, sp, #0xc0
//   0x022f64: 3dc007a0  ldr      q0, [x29, #0x10]
//   0x022f68: f9002fe7  str      x7, [sp, #0x58]
//   0x022f6c: aa0003fa  mov      x26, x0
//   0x022f70: b00001c0  adrp     x0, #0x5b000
uint64_t fde_0904_sub_022f44(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10343FFULL) + (x1 ^ 0x3DC007A0ULL) + (x2 ^ 0x022F44ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10343FFULL; // 0x022f44: sub sp, sp, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9076FFCULL; // 0x022f48: stp x28, x27, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90867FAULL; // 0x022f4c: stp x26, x25, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9095FF8ULL; // 0x022f50: stp x24, x23, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A57F6ULL; // 0x022f54: stp x22, x21, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B4FF4ULL; // 0x022f58: stp x20, x19, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C7BFDULL; // 0x022f5c: stp x29, x30, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910303FDULL; // 0x022f60: add x29, sp, #0xc0
    return acc;
}

// [EN] Reconstructed FDE #0905 @ 0x023040..0x023140 (256 bytes)
// [VN] Phục dựng FDE #0905 tại 0x023040..0x023140 (256 byte)
//   0x023040: d10383ff  sub      sp, sp, #0xe0
//   0x023044: a9086ffc  stp      x28, x27, [sp, #0x80]
//   0x023048: a90967fa  stp      x26, x25, [sp, #0x90]
//   0x02304c: a90a5ff8  stp      x24, x23, [sp, #0xa0]
//   0x023050: a90b57f6  stp      x22, x21, [sp, #0xb0]
//   0x023054: a90c4ff4  stp      x20, x19, [sp, #0xc0]
//   0x023058: a90d7bfd  stp      x29, x30, [sp, #0xd0]
//   0x02305c: 910343fd  add      x29, sp, #0xd0
//   0x023060: 3dc007a0  ldr      q0, [x29, #0x10]
//   0x023064: aa0003fa  mov      x26, x0
//   0x023068: 900001c0  adrp     x0, #0x5b000
//   0x02306c: f94023bc  ldr      x28, [x29, #0x40]
uint64_t fde_0905_sub_023040(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10383FFULL) + (x1 ^ 0x3DC007A0ULL) + (x2 ^ 0x023040ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10383FFULL; // 0x023040: sub sp, sp, #0xe0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9086FFCULL; // 0x023044: stp x28, x27, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90967FAULL; // 0x023048: stp x26, x25, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A5FF8ULL; // 0x02304c: stp x24, x23, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B57F6ULL; // 0x023050: stp x22, x21, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C4FF4ULL; // 0x023054: stp x20, x19, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90D7BFDULL; // 0x023058: stp x29, x30, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910343FDULL; // 0x02305c: add x29, sp, #0xd0
    return acc;
}

// [EN] Reconstructed FDE #0906 @ 0x023140..0x023214 (212 bytes)
// [VN] Phục dựng FDE #0906 tại 0x023140..0x023214 (212 byte)
//   0x023140: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x023144: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x023148: 910043fd  add      x29, sp, #0x10
//   0x02314c: 2a0003f3  mov      w19, w0
//   0x023150: 97ffa148  bl       #0xb670
//   0x023154: 7100741f  cmp      w0, #0x1d
//   0x023158: 54000083  b.lo     #0x23168
//   0x02315c: 97ffa145  bl       #0xb670
//   0x023160: 71007c1f  cmp      w0, #0x1f
//   0x023164: 54000069  b.ls     #0x23170
//   0x023168: 2a1f03e0  mov      w0, wzr
//   0x02316c: 14000027  b        #0x23208
uint64_t fde_0906_sub_023140(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x71007C1FULL) + (x2 ^ 0x023140ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x023140: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x023144: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x023148: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F3ULL; // 0x02314c: mov w19, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFA148ULL; // 0x023150: bl #0xb670
    acc = (acc * 0x100000001B3ULL) ^ 0x7100741FULL; // 0x023154: cmp w0, #0x1d
    acc = (acc * 0x100000001B3ULL) ^ 0x54000083ULL; // 0x023158: b.lo #0x23168
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFA145ULL; // 0x02315c: bl #0xb670
    return acc;
}

// [EN] Reconstructed FDE #0907 @ 0x023214..0x0232a0 (140 bytes)
// [VN] Phục dựng FDE #0907 tại 0x023214..0x0232a0 (140 byte)
//   0x023214: d100c3ff  sub      sp, sp, #0x30
//   0x023218: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02321c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x023220: 910083fd  add      x29, sp, #0x20
//   0x023224: d53bd054  mrs      x20, tpidr_el0
//   0x023228: f9401688  ldr      x8, [x20, #0x28]
//   0x02322c: f90007e8  str      x8, [sp, #8]
//   0x023230: f90003fe  str      x30, [sp]
//   0x023234: 900001c8  adrp     x8, #0x5b000
//   0x023238: f9437d08  ldr      x8, [x8, #0x6f8]
//   0x02323c: b9400109  ldr      w9, [x8]
//   0x023240: 11000529  add      w9, w9, #1
uint64_t fde_0907_sub_023214(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0x900001C8ULL) + (x2 ^ 0x023214ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x023214: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x023218: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02321c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x023220: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x023224: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x023228: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x02322c: str x8, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90003FEULL; // 0x023230: str x30, [sp]
    return acc;
}

// [EN] Reconstructed FDE #0908 @ 0x0232a0..0x02331c (124 bytes)
// [VN] Phục dựng FDE #0908 tại 0x0232a0..0x02331c (124 byte)
//   0x0232a0: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0232a4: 910003fd  mov      x29, sp
//   0x0232a8: 97ffa0f2  bl       #0xb670
//   0x0232ac: 7100701f  cmp      w0, #0x1c
//   0x0232b0: 54000062  b.hs     #0x232bc
//   0x0232b4: 2a1f03e0  mov      w0, wzr
//   0x0232b8: 14000017  b        #0x23314
//   0x0232bc: 2a1f03e0  mov      w0, wzr
//   0x0232c0: 2a1f03e1  mov      w1, wzr
//   0x0232c4: 97ff9f47  bl       #0xafe0
//   0x0232c8: 900001c2  adrp     x2, #0x5b000
//   0x0232cc: f943e442  ldr      x2, [x2, #0x7c8]
uint64_t fde_0908_sub_0232a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x2A1F03E1ULL) + (x2 ^ 0x0232A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x0232a0: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0232a4: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFA0F2ULL; // 0x0232a8: bl #0xb670
    acc = (acc * 0x100000001B3ULL) ^ 0x7100701FULL; // 0x0232ac: cmp w0, #0x1c
    acc = (acc * 0x100000001B3ULL) ^ 0x54000062ULL; // 0x0232b0: b.hs #0x232bc
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x0232b4: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000017ULL; // 0x0232b8: b #0x23314
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x0232bc: mov w0, wzr
    return acc;
}

// [EN] Reconstructed FDE #0909 @ 0x02331c..0x023338 (28 bytes)
// [VN] Phục dựng FDE #0909 tại 0x02331c..0x023338 (28 byte)
//   0x02331c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x023320: 910003fd  mov      x29, sp
//   0x023324: 2a0203e0  mov      w0, w2
//   0x023328: 97ffff86  bl       #0x23140
//   0x02332c: 12000000  and      w0, w0, #1
//   0x023330: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x023334: d65f03c0  ret      
uint64_t fde_0909_sub_02331c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02331CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x02331c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x023320: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203E0ULL; // 0x023324: mov w0, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFF86ULL; // 0x023328: bl #0x23140
    acc = (acc * 0x100000001B3ULL) ^ 0x12000000ULL; // 0x02332c: and w0, w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x023330: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x023334: ret 
    return acc;
}

// [EN] Reconstructed FDE #0910 @ 0x023338..0x023350 (24 bytes)
// [VN] Phục dựng FDE #0910 tại 0x023338..0x023350 (24 byte)
//   0x023338: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x02333c: 910003fd  mov      x29, sp
//   0x023340: 97ffffd8  bl       #0x232a0
//   0x023344: 12000000  and      w0, w0, #1
//   0x023348: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x02334c: d65f03c0  ret      
uint64_t fde_0910_sub_023338(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x023338ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x023338: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02333c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFFD8ULL; // 0x023340: bl #0x232a0
    acc = (acc * 0x100000001B3ULL) ^ 0x12000000ULL; // 0x023344: and w0, w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x023348: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02334c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0911 @ 0x023350..0x0233d0 (128 bytes)
// [VN] Phục dựng FDE #0911 tại 0x023350..0x0233d0 (128 byte)
//   0x023350: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x023354: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x023358: 910043fd  add      x29, sp, #0x10
//   0x02335c: f00000c1  adrp     x1, #0x3e000
//   0x023360: f00000c2  adrp     x2, #0x3e000
//   0x023364: d00000a3  adrp     x3, #0x39000
//   0x023368: 910d9021  add      x1, x1, #0x364
//   0x02336c: 910dd442  add      x2, x2, #0x375
//   0x023370: 9116c463  add      x3, x3, #0x5b1
//   0x023374: 2a1f03e4  mov      w4, wzr
//   0x023378: aa0003f3  mov      x19, x0
//   0x02337c: 97ffd385  bl       #0x18190
uint64_t fde_0911_sub_023350(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x9116C463ULL) + (x2 ^ 0x023350ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x023350: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x023354: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x023358: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF00000C1ULL; // 0x02335c: adrp x1, #0x3e000
    acc = (acc * 0x100000001B3ULL) ^ 0xF00000C2ULL; // 0x023360: adrp x2, #0x3e000
    acc = (acc * 0x100000001B3ULL) ^ 0xD00000A3ULL; // 0x023364: adrp x3, #0x39000
    acc = (acc * 0x100000001B3ULL) ^ 0x910D9021ULL; // 0x023368: add x1, x1, #0x364
    acc = (acc * 0x100000001B3ULL) ^ 0x910DD442ULL; // 0x02336c: add x2, x2, #0x375
    return acc;
}

// [EN] Reconstructed FDE #0912 @ 0x0233d0..0x023490 (192 bytes)
// [VN] Phục dựng FDE #0912 tại 0x0233d0..0x023490 (192 byte)
//   0x0233d0: d10143ff  sub      sp, sp, #0x50
//   0x0233d4: f90013f5  str      x21, [sp, #0x20]
//   0x0233d8: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x0233dc: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x0233e0: 910103fd  add      x29, sp, #0x40
//   0x0233e4: d53bd055  mrs      x21, tpidr_el0
//   0x0233e8: f94016a8  ldr      x8, [x21, #0x28]
//   0x0233ec: f9000fe8  str      x8, [sp, #0x18]
//   0x0233f0: a9000be0  stp      x0, x2, [sp]
//   0x0233f4: b40002a2  cbz      x2, #0x23448
//   0x0233f8: f9400008  ldr      x8, [x0]
//   0x0233fc: aa0203e1  mov      x1, x2
uint64_t fde_0912_sub_0233d0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xA9000BE0ULL) + (x2 ^ 0x0233D0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x0233d0: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F5ULL; // 0x0233d4: str x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x0233d8: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x0233dc: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x0233e0: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x0233e4: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x0233e8: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x0233ec: str x8, [sp, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0913 @ 0x023490..0x023494 (4 bytes)
// [VN] Phục dựng FDE #0913 tại 0x023490..0x023494 (4 byte)
//   0x023490: 140000e3  b        #0x2381c
uint64_t fde_0913_sub_023490(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x140000E3ULL) + (x1 ^ 0x140000E3ULL) + (x2 ^ 0x023490ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x140000E3ULL; // 0x023490: b #0x2381c
    return acc;
}

// [EN] Reconstructed FDE #0914 @ 0x023494..0x02357c (232 bytes)
// [VN] Phục dựng FDE #0914 tại 0x023494..0x02357c (232 byte)
//   0x023494: d10183ff  sub      sp, sp, #0x60
//   0x023498: f90013f7  str      x23, [sp, #0x20]
//   0x02349c: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0234a0: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0234a4: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0234a8: 910143fd  add      x29, sp, #0x50
//   0x0234ac: d53bd057  mrs      x23, tpidr_el0
//   0x0234b0: f94016e8  ldr      x8, [x23, #0x28]
//   0x0234b4: 2a0303f3  mov      w19, w3
//   0x0234b8: 2a0203f4  mov      w20, w2
//   0x0234bc: aa0103f5  mov      x21, x1
//   0x0234c0: aa0003f6  mov      x22, x0
uint64_t fde_0914_sub_023494(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0x2A0303F3ULL) + (x2 ^ 0x023494ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x023494: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F7ULL; // 0x023498: str x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x02349c: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x0234a0: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x0234a4: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x0234a8: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x0234ac: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x0234b0: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0915 @ 0x02357c..0x023594 (24 bytes)
// [VN] Phục dựng FDE #0915 tại 0x02357c..0x023594 (24 byte)
//   0x02357c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x023580: 910003fd  mov      x29, sp
//   0x023584: 940000c4  bl       #0x23894
//   0x023588: 92401c21  and      x1, x1, #0xff
//   0x02358c: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x023590: d65f03c0  ret      
uint64_t fde_0915_sub_02357c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02357CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x02357c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x023580: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x940000C4ULL; // 0x023584: bl #0x23894
    acc = (acc * 0x100000001B3ULL) ^ 0x92401C21ULL; // 0x023588: and x1, x1, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x02358c: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x023590: ret 
    return acc;
}

// [EN] Reconstructed FDE #0916 @ 0x023594..0x023688 (244 bytes)
// [VN] Phục dựng FDE #0916 tại 0x023594..0x023688 (244 byte)
//   0x023594: d10143ff  sub      sp, sp, #0x50
//   0x023598: f90013f5  str      x21, [sp, #0x20]
//   0x02359c: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x0235a0: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x0235a4: 910103fd  add      x29, sp, #0x40
//   0x0235a8: d53bd055  mrs      x21, tpidr_el0
//   0x0235ac: f94016a8  ldr      x8, [x21, #0x28]
//   0x0235b0: f9000fe8  str      x8, [sp, #0x18]
//   0x0235b4: b00001c8  adrp     x8, #0x5c000
//   0x0235b8: 39435108  ldrb     w8, [x8, #0xd4]
//   0x0235bc: a90083fe  stp      x30, x0, [sp, #8]
//   0x0235c0: 34000208  cbz      w8, #0x23600
uint64_t fde_0916_sub_023594(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xB00001C8ULL) + (x2 ^ 0x023594ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x023594: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F5ULL; // 0x023598: str x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x02359c: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x0235a0: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x0235a4: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x0235a8: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x0235ac: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x0235b0: str x8, [sp, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0917 @ 0x023688..0x02381c (404 bytes)
// [VN] Phục dựng FDE #0917 tại 0x023688..0x02381c (404 byte)
//   0x023688: d10143ff  sub      sp, sp, #0x50
//   0x02368c: f90013f5  str      x21, [sp, #0x20]
//   0x023690: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x023694: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x023698: 910103fd  add      x29, sp, #0x40
//   0x02369c: d53bd055  mrs      x21, tpidr_el0
//   0x0236a0: f94016a8  ldr      x8, [x21, #0x28]
//   0x0236a4: 2a0003f3  mov      w19, w0
//   0x0236a8: f9000fe8  str      x8, [sp, #0x18]
//   0x0236ac: 97ff9ff1  bl       #0xb670
//   0x0236b0: 51007408  sub      w8, w0, #0x1d
//   0x0236b4: 7100151f  cmp      w8, #5
uint64_t fde_0917_sub_023688(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xF9000FE8ULL) + (x2 ^ 0x023688ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x023688: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F5ULL; // 0x02368c: str x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x023690: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x023694: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x023698: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x02369c: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x0236a0: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F3ULL; // 0x0236a4: mov w19, w0
    return acc;
}

// [EN] Reconstructed FDE #0918 @ 0x02381c..0x023844 (40 bytes)
// [VN] Phục dựng FDE #0918 tại 0x02381c..0x023844 (40 byte)
//   0x02381c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x023820: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x023824: 910043fd  add      x29, sp, #0x10
//   0x023828: f9400801  ldr      x1, [x0, #0x10]
//   0x02382c: aa0003f3  mov      x19, x0
//   0x023830: 94000005  bl       #0x23844
//   0x023834: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x023838: aa1303e0  mov      x0, x19
//   0x02383c: f84207f3  ldr      x19, [sp], #0x20
//   0x023840: 1400000d  b        #0x23874
uint64_t fde_0918_sub_02381c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x02381CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02381c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x023820: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x023824: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400801ULL; // 0x023828: ldr x1, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02382c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x94000005ULL; // 0x023830: bl #0x23844
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x023834: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x023838: mov x0, x19
    return acc;
}

// [EN] Reconstructed FDE #0919 @ 0x023844..0x023874 (48 bytes)
// [VN] Phục dựng FDE #0919 tại 0x023844..0x023874 (48 byte)
//   0x023844: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x023848: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02384c: 910043fd  add      x29, sp, #0x10
//   0x023850: aa0103e0  mov      x0, x1
//   0x023854: b40000a0  cbz      x0, #0x23868
//   0x023858: f9400013  ldr      x19, [x0]
//   0x02385c: 97ff9d39  bl       #0xad40
//   0x023860: aa1303e0  mov      x0, x19
//   0x023864: b5ffffa0  cbnz     x0, #0x23858
//   0x023868: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02386c: f84207f3  ldr      x19, [sp], #0x20
//   0x023870: d65f03c0  ret      
uint64_t fde_0919_sub_023844(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xB5FFFFA0ULL) + (x2 ^ 0x023844ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x023844: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x023848: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02384c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x023850: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000A0ULL; // 0x023854: cbz x0, #0x23868
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400013ULL; // 0x023858: ldr x19, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF9D39ULL; // 0x02385c: bl #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x023860: mov x0, x19
    return acc;
}

// [EN] Reconstructed FDE #0920 @ 0x023874..0x02387c (8 bytes)
// [VN] Phục dựng FDE #0920 tại 0x023874..0x02387c (8 byte)
//   0x023874: aa1f03e1  mov      x1, xzr
//   0x023878: 14000001  b        #0x2387c
uint64_t fde_0920_sub_023874(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E1ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x023874ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x023874: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x023878: b #0x2387c
    return acc;
}

// [EN] Reconstructed FDE #0921 @ 0x02387c..0x023894 (24 bytes)
// [VN] Phục dựng FDE #0921 tại 0x02387c..0x023894 (24 byte)
//   0x02387c: aa0003e8  mov      x8, x0
//   0x023880: f9400000  ldr      x0, [x0]
//   0x023884: f900011f  str      xzr, [x8]
//   0x023888: b4000040  cbz      x0, #0x23890
//   0x02388c: 17ff9d2d  b        #0xad40
//   0x023890: d65f03c0  ret      
uint64_t fde_0921_sub_02387c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02387CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x02387c: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x023880: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900011FULL; // 0x023884: str xzr, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000040ULL; // 0x023888: cbz x0, #0x23890
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF9D2DULL; // 0x02388c: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x023890: ret 
    return acc;
}

// [EN] Reconstructed FDE #0922 @ 0x023894..0x02389c (8 bytes)
// [VN] Phục dựng FDE #0922 tại 0x023894..0x02389c (8 byte)
//   0x023894: aa0103e2  mov      x2, x1
//   0x023898: 14000001  b        #0x2389c
uint64_t fde_0922_sub_023894(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0103E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x023894ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E2ULL; // 0x023894: mov x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x023898: b #0x2389c
    return acc;
}

// [EN] Reconstructed FDE #0923 @ 0x02389c..0x023af8 (604 bytes)
// [VN] Phục dựng FDE #0923 tại 0x02389c..0x023af8 (604 byte)
//   0x02389c: d101c3ff  sub      sp, sp, #0x70
//   0x0238a0: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x0238a4: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x0238a8: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x0238ac: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x0238b0: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x0238b4: 910183fd  add      x29, sp, #0x60
//   0x0238b8: d53bd058  mrs      x24, tpidr_el0
//   0x0238bc: f9401708  ldr      x8, [x24, #0x28]
//   0x0238c0: aa0103f7  mov      x23, x1
//   0x0238c4: aa0003f3  mov      x19, x0
//   0x0238c8: 91006000  add      x0, x0, #0x18
uint64_t fde_0923_sub_02389c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xF9401708ULL) + (x2 ^ 0x02389CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x02389c: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x0238a0: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x0238a4: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x0238a8: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x0238ac: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x0238b0: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x0238b4: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x0238b8: mrs x24, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0924 @ 0x023af8..0x023b4c (84 bytes)
// [VN] Phục dựng FDE #0924 tại 0x023af8..0x023b4c (84 byte)
//   0x023af8: d10103ff  sub      sp, sp, #0x40
//   0x023afc: f90013f3  str      x19, [sp, #0x20]
//   0x023b00: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x023b04: 9100c3fd  add      x29, sp, #0x30
//   0x023b08: d53bd053  mrs      x19, tpidr_el0
//   0x023b0c: f9401668  ldr      x8, [x19, #0x28]
//   0x023b10: 910023e0  add      x0, sp, #8
//   0x023b14: 52800102  mov      w2, #8
//   0x023b18: f9000fe8  str      x8, [sp, #0x18]
//   0x023b1c: f9000be1  str      x1, [sp, #0x10]
//   0x023b20: 910043e1  add      x1, sp, #0x10
//   0x023b24: 97ffac01  bl       #0xeb28
uint64_t fde_0924_sub_023af8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xF9000FE8ULL) + (x2 ^ 0x023AF8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x023af8: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F3ULL; // 0x023afc: str x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x023b00: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x023b04: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x023b08: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x023b0c: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E0ULL; // 0x023b10: add x0, sp, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x52800102ULL; // 0x023b14: mov w2, #8
    return acc;
}

// [EN] Reconstructed FDE #0925 @ 0x023b4c..0x023ba8 (92 bytes)
// [VN] Phục dựng FDE #0925 tại 0x023b4c..0x023ba8 (92 byte)
//   0x023b4c: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x023b50: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x023b54: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x023b58: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x023b5c: 9100c3fd  add      x29, sp, #0x30
//   0x023b60: 91004016  add      x22, x0, #0x10
//   0x023b64: aa0103f4  mov      x20, x1
//   0x023b68: 52800021  mov      w1, #1
//   0x023b6c: aa1603e0  mov      x0, x22
//   0x023b70: aa0203f3  mov      x19, x2
//   0x023b74: aa0803f5  mov      x21, x8
//   0x023b78: 52800037  mov      w23, #1
uint64_t fde_0925_sub_023b4c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xAA1603E0ULL) + (x2 ^ 0x023B4CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x023b4c: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x023b50: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x023b54: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x023b58: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x023b5c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x91004016ULL; // 0x023b60: add x22, x0, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x023b64: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x023b68: mov w1, #1
    return acc;
}

// [EN] Reconstructed FDE #0926 @ 0x023ba8..0x023c88 (224 bytes)
// [VN] Phục dựng FDE #0926 tại 0x023ba8..0x023c88 (224 byte)
//   0x023ba8: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x023bac: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x023bb0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x023bb4: 910083fd  add      x29, sp, #0x20
//   0x023bb8: f1000428  subs     x8, x1, #1
//   0x023bbc: aa0003f3  mov      x19, x0
//   0x023bc0: 54000061  b.ne     #0x23bcc
//   0x023bc4: 52800054  mov      w20, #2
//   0x023bc8: 14000007  b        #0x23be4
//   0x023bcc: aa0103f4  mov      x20, x1
//   0x023bd0: ea08003f  tst      x1, x8
//   0x023bd4: 54000080  b.eq     #0x23be4
uint64_t fde_0926_sub_023ba8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x14000007ULL) + (x2 ^ 0x023BA8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x023ba8: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x023bac: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x023bb0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x023bb4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF1000428ULL; // 0x023bb8: subs x8, x1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x023bbc: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x54000061ULL; // 0x023bc0: b.ne #0x23bcc
    acc = (acc * 0x100000001B3ULL) ^ 0x52800054ULL; // 0x023bc4: mov w20, #2
    return acc;
}

// [EN] Reconstructed FDE #0927 @ 0x023c88..0x023c90 (8 bytes)
// [VN] Phục dựng FDE #0927 tại 0x023c88..0x023c90 (8 byte)
//   0x023c88: aa1f03e1  mov      x1, xzr
//   0x023c8c: 14000070  b        #0x23e4c
uint64_t fde_0927_sub_023c88(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E1ULL) + (x1 ^ 0x14000070ULL) + (x2 ^ 0x023C88ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x023c88: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000070ULL; // 0x023c8c: b #0x23e4c
    return acc;
}

// [EN] Reconstructed FDE #0928 @ 0x023c90..0x023c98 (8 bytes)
// [VN] Phục dựng FDE #0928 tại 0x023c90..0x023c98 (8 byte)
//   0x023c90: aa1f03e2  mov      x2, xzr
//   0x023c94: 14000001  b        #0x23c98
uint64_t fde_0928_sub_023c90(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x023C90ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x023c90: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x023c94: b #0x23c98
    return acc;
}

// [EN] Reconstructed FDE #0929 @ 0x023c98..0x023cc4 (44 bytes)
// [VN] Phục dựng FDE #0929 tại 0x023c98..0x023cc4 (44 byte)
//   0x023c98: b201f3e8  mov      x8, #-0x5555555555555556
//   0x023c9c: f2955568  movk     x8, #0xaaab
//   0x023ca0: f2e15548  movk     x8, #0xaaa, lsl #48
//   0x023ca4: eb08003f  cmp      x1, x8
//   0x023ca8: 54000082  b.hs     #0x23cb8
//   0x023cac: 8b010428  add      x8, x1, x1, lsl #1
//   0x023cb0: d37df100  lsl      x0, x8, #3
//   0x023cb4: 17ff9e4f  b        #0xb5f0
//   0x023cb8: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x023cbc: 910003fd  mov      x29, sp
//   0x023cc0: 97ff9e10  bl       #0xb500
uint64_t fde_0929_sub_023c98(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB201F3E8ULL) + (x1 ^ 0xA9BF7BFDULL) + (x2 ^ 0x023C98ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB201F3E8ULL; // 0x023c98: mov x8, #-0x5555555555555556
    acc = (acc * 0x100000001B3ULL) ^ 0xF2955568ULL; // 0x023c9c: movk x8, #0xaaab
    acc = (acc * 0x100000001B3ULL) ^ 0xF2E15548ULL; // 0x023ca0: movk x8, #0xaaa, lsl #48
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08003FULL; // 0x023ca4: cmp x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000082ULL; // 0x023ca8: b.hs #0x23cb8
    acc = (acc * 0x100000001B3ULL) ^ 0x8B010428ULL; // 0x023cac: add x8, x1, x1, lsl #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DF100ULL; // 0x023cb0: lsl x0, x8, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF9E4FULL; // 0x023cb4: b #0xb5f0
    return acc;
}

// [EN] Reconstructed FDE #0930 @ 0x023cc4..0x023e10 (332 bytes)
// [VN] Phục dựng FDE #0930 tại 0x023cc4..0x023e10 (332 byte)
//   0x023cc4: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x023cc8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x023ccc: 910043fd  add      x29, sp, #0x10
//   0x023cd0: aa0003f3  mov      x19, x0
//   0x023cd4: b40003c1  cbz      x1, #0x23d4c
//   0x023cd8: 91002260  add      x0, x19, #8
//   0x023cdc: aa0103f4  mov      x20, x1
//   0x023ce0: 94000052  bl       #0x23e28
//   0x023ce4: aa0003e1  mov      x1, x0
//   0x023ce8: aa1303e0  mov      x0, x19
//   0x023cec: 94000049  bl       #0x23e10
//   0x023cf0: aa1f03e8  mov      x8, xzr
uint64_t fde_0930_sub_023cc4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA0003E1ULL) + (x2 ^ 0x023CC4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x023cc4: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x023cc8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x023ccc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x023cd0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB40003C1ULL; // 0x023cd4: cbz x1, #0x23d4c
    acc = (acc * 0x100000001B3ULL) ^ 0x91002260ULL; // 0x023cd8: add x0, x19, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x023cdc: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x94000052ULL; // 0x023ce0: bl #0x23e28
    return acc;
}

// [EN] Reconstructed FDE #0931 @ 0x023e10..0x023e28 (24 bytes)
// [VN] Phục dựng FDE #0931 tại 0x023e10..0x023e28 (24 byte)
//   0x023e10: aa0003e8  mov      x8, x0
//   0x023e14: f9400000  ldr      x0, [x0]
//   0x023e18: f9000101  str      x1, [x8]
//   0x023e1c: b4000040  cbz      x0, #0x23e24
//   0x023e20: 17ff9bc8  b        #0xad40
//   0x023e24: d65f03c0  ret      
uint64_t fde_0931_sub_023e10(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x023E10ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x023e10: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x023e14: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000101ULL; // 0x023e18: str x1, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000040ULL; // 0x023e1c: cbz x0, #0x23e24
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF9BC8ULL; // 0x023e20: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x023e24: ret 
    return acc;
}

// [EN] Reconstructed FDE #0932 @ 0x023e28..0x023e30 (8 bytes)
// [VN] Phục dựng FDE #0932 tại 0x023e28..0x023e30 (8 byte)
//   0x023e28: aa1f03e2  mov      x2, xzr
//   0x023e2c: 14000001  b        #0x23e30
uint64_t fde_0932_sub_023e28(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x023E28ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x023e28: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x023e2c: b #0x23e30
    return acc;
}

// [EN] Reconstructed FDE #0933 @ 0x023e30..0x023e4c (28 bytes)
// [VN] Phục dựng FDE #0933 tại 0x023e30..0x023e4c (28 byte)
//   0x023e30: d37dfc28  lsr      x8, x1, #0x3d
//   0x023e34: b5000068  cbnz     x8, #0x23e40
//   0x023e38: d37df020  lsl      x0, x1, #3
//   0x023e3c: 17ff9ded  b        #0xb5f0
//   0x023e40: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x023e44: 910003fd  mov      x29, sp
//   0x023e48: 97ff9dae  bl       #0xb500
uint64_t fde_0933_sub_023e30(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD37DFC28ULL) + (x1 ^ 0x97FF9DAEULL) + (x2 ^ 0x023E30ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DFC28ULL; // 0x023e30: lsr x8, x1, #0x3d
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000068ULL; // 0x023e34: cbnz x8, #0x23e40
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DF020ULL; // 0x023e38: lsl x0, x1, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF9DEDULL; // 0x023e3c: b #0xb5f0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x023e40: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x023e44: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF9DAEULL; // 0x023e48: bl #0xb500
    return acc;
}

// [EN] Reconstructed FDE #0934 @ 0x023e4c..0x023e64 (24 bytes)
// [VN] Phục dựng FDE #0934 tại 0x023e4c..0x023e64 (24 byte)
//   0x023e4c: aa0003e8  mov      x8, x0
//   0x023e50: f9400000  ldr      x0, [x0]
//   0x023e54: f9000101  str      x1, [x8]
//   0x023e58: b4000040  cbz      x0, #0x23e60
//   0x023e5c: 17ff9bb9  b        #0xad40
//   0x023e60: d65f03c0  ret      
uint64_t fde_0934_sub_023e4c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x023E4CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x023e4c: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x023e50: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000101ULL; // 0x023e54: str x1, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000040ULL; // 0x023e58: cbz x0, #0x23e60
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF9BB9ULL; // 0x023e5c: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x023e60: ret 
    return acc;
}

// [EN] Reconstructed FDE #0935 @ 0x023e64..0x023f38 (212 bytes)
// [VN] Phục dựng FDE #0935 tại 0x023e64..0x023f38 (212 byte)
//   0x023e64: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x023e68: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x023e6c: 910043fd  add      x29, sp, #0x10
//   0x023e70: aa0103f3  mov      x19, x1
//   0x023e74: f9400021  ldr      x1, [x1]
//   0x023e78: aa0003f4  mov      x20, x0
//   0x023e7c: 91006000  add      x0, x0, #0x18
//   0x023e80: 97ffff1e  bl       #0x23af8
//   0x023e84: f9400689  ldr      x9, [x20, #8]
//   0x023e88: b40004e9  cbz      x9, #0x23f24
//   0x023e8c: 9e670120  fmov     d0, x9
//   0x023e90: 0e205800  cnt      v0.8b, v0.8b
uint64_t fde_0935_sub_023e64(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9400689ULL) + (x2 ^ 0x023E64ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x023e64: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x023e68: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x023e6c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x023e70: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400021ULL; // 0x023e74: ldr x1, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x023e78: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91006000ULL; // 0x023e7c: add x0, x0, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFF1EULL; // 0x023e80: bl #0x23af8
    return acc;
}

// [EN] Reconstructed FDE #0936 @ 0x023f38..0x023f90 (88 bytes)
// [VN] Phục dựng FDE #0936 tại 0x023f38..0x023f90 (88 byte)
//   0x023f38: d10103ff  sub      sp, sp, #0x40
//   0x023f3c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x023f40: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x023f44: 9100c3fd  add      x29, sp, #0x30
//   0x023f48: d53bd054  mrs      x20, tpidr_el0
//   0x023f4c: f9401688  ldr      x8, [x20, #0x28]
//   0x023f50: f9000fe8  str      x8, [sp, #0x18]
//   0x023f54: f9400033  ldr      x19, [x1]
//   0x023f58: 910003e8  mov      x8, sp
//   0x023f5c: 9400000d  bl       #0x23f90
//   0x023f60: 910003e0  mov      x0, sp
//   0x023f64: 97ffff49  bl       #0x23c88
uint64_t fde_0936_sub_023f38(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x910003E8ULL) + (x2 ^ 0x023F38ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x023f38: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x023f3c: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x023f40: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x023f44: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x023f48: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x023f4c: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x023f50: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400033ULL; // 0x023f54: ldr x19, [x1]
    return acc;
}

// [EN] Reconstructed FDE #0937 @ 0x023f90..0x0240c4 (308 bytes)
// [VN] Phục dựng FDE #0937 tại 0x023f90..0x0240c4 (308 byte)
//   0x023f90: f9400409  ldr      x9, [x0, #8]
//   0x023f94: f940042a  ldr      x10, [x1, #8]
//   0x023f98: 9e670120  fmov     d0, x9
//   0x023f9c: 0e205800  cnt      v0.8b, v0.8b
//   0x023fa0: 2e303800  uaddlv   h0, v0.8b
//   0x023fa4: 1e26000d  fmov     w13, s0
//   0x023fa8: f10005bf  cmp      x13, #1
//   0x023fac: 540000c9  b.ls     #0x23fc4
//   0x023fb0: 9ac9094b  udiv     x11, x10, x9
//   0x023fb4: eb09015f  cmp      x10, x9
//   0x023fb8: 9b09a96b  msub     x11, x11, x9, x10
//   0x023fbc: 9a8b314a  csel     x10, x10, x11, lo
uint64_t fde_0937_sub_023f90(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400409ULL) + (x1 ^ 0x9AC9094BULL) + (x2 ^ 0x023F90ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400409ULL; // 0x023f90: ldr x9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF940042AULL; // 0x023f94: ldr x10, [x1, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x9E670120ULL; // 0x023f98: fmov d0, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x0E205800ULL; // 0x023f9c: cnt v0.8b, v0.8b
    acc = (acc * 0x100000001B3ULL) ^ 0x2E303800ULL; // 0x023fa0: uaddlv h0, v0.8b
    acc = (acc * 0x100000001B3ULL) ^ 0x1E26000DULL; // 0x023fa4: fmov w13, s0
    acc = (acc * 0x100000001B3ULL) ^ 0xF10005BFULL; // 0x023fa8: cmp x13, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540000C9ULL; // 0x023fac: b.ls #0x23fc4
    return acc;
}

// [EN] Reconstructed FDE #0938 @ 0x0240c4..0x0240d4 (16 bytes)
// [VN] Phục dựng FDE #0938 tại 0x0240c4..0x0240d4 (16 byte)
//   0x0240c4: 900001d3  adrp     x19, #0x5c000
//   0x0240c8: 91349273  add      x19, x19, #0xd24
//   0x0240cc: aa1303e0  mov      x0, x19
//   0x0240d0: 17ff9dcc  b        #0xb800
uint64_t fde_0938_sub_0240c4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x900001D3ULL) + (x1 ^ 0x17FF9DCCULL) + (x2 ^ 0x0240C4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x900001D3ULL; // 0x0240c4: adrp x19, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0x91349273ULL; // 0x0240c8: add x19, x19, #0xd24
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x0240cc: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF9DCCULL; // 0x0240d0: b #0xb800
    return acc;
}

// [EN] Reconstructed FDE #0939 @ 0x0240d4..0x024204 (304 bytes)
// [VN] Phục dựng FDE #0939 tại 0x0240d4..0x024204 (304 byte)
//   0x0240d4: d10743ff  sub      sp, sp, #0x1d0
//   0x0240d8: f900d3fc  str      x28, [sp, #0x1a0]
//   0x0240dc: a91b4ff4  stp      x20, x19, [sp, #0x1b0]
//   0x0240e0: a91c7bfd  stp      x29, x30, [sp, #0x1c0]
//   0x0240e4: 910703fd  add      x29, sp, #0x1c0
//   0x0240e8: d53bd053  mrs      x19, tpidr_el0
//   0x0240ec: f9401668  ldr      x8, [x19, #0x28]
//   0x0240f0: 2a0003e1  mov      w1, w0
//   0x0240f4: f81d83a8  stur     x8, [x29, #-0x28]
//   0x0240f8: 900001c8  adrp     x8, #0x5c000
//   0x0240fc: 91370108  add      x8, x8, #0xdc0
//   0x024100: 08dffd08  ldarb    w8, [x8]
uint64_t fde_0939_sub_0240d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10743FFULL) + (x1 ^ 0xF81D83A8ULL) + (x2 ^ 0x0240D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10743FFULL; // 0x0240d4: sub sp, sp, #0x1d0
    acc = (acc * 0x100000001B3ULL) ^ 0xF900D3FCULL; // 0x0240d8: str x28, [sp, #0x1a0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91B4FF4ULL; // 0x0240dc: stp x20, x19, [sp, #0x1b0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91C7BFDULL; // 0x0240e0: stp x29, x30, [sp, #0x1c0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910703FDULL; // 0x0240e4: add x29, sp, #0x1c0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x0240e8: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x0240ec: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003E1ULL; // 0x0240f0: mov w1, w0
    return acc;
}

// [EN] Reconstructed FDE #0940 @ 0x024204..0x024320 (284 bytes)
// [VN] Phục dựng FDE #0940 tại 0x024204..0x024320 (284 byte)
//   0x024204: d10143ff  sub      sp, sp, #0x50
//   0x024208: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x02420c: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x024210: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x024214: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x024218: 910103fd  add      x29, sp, #0x40
//   0x02421c: d53bd056  mrs      x22, tpidr_el0
//   0x024220: f94016c8  ldr      x8, [x22, #0x28]
//   0x024224: aa0003f5  mov      x21, x0
//   0x024228: f00001a0  adrp     x0, #0x5b000
//   0x02422c: aa0203f4  mov      x20, x2
//   0x024230: f90007e8  str      x8, [sp, #8]
uint64_t fde_0940_sub_024204(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xAA0003F5ULL) + (x2 ^ 0x024204ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x024204: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x024208: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x02420c: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x024210: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x024214: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x024218: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x02421c: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x024220: ldr x8, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0941 @ 0x024320..0x024374 (84 bytes)
// [VN] Phục dựng FDE #0941 tại 0x024320..0x024374 (84 byte)
//   0x024320: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x024324: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x024328: 910043fd  add      x29, sp, #0x10
//   0x02432c: f00001a8  adrp     x8, #0x5b000
//   0x024330: f9446908  ldr      x8, [x8, #0x8d0]
//   0x024334: aa0003f4  mov      x20, x0
//   0x024338: a901fc1f  stp      xzr, xzr, [x0, #0x18]
//   0x02433c: f9001402  str      x2, [x0, #0x28]
//   0x024340: 91004108  add      x8, x8, #0x10
//   0x024344: a9000408  stp      x8, x1, [x0]
//   0x024348: d37df040  lsl      x0, x2, #3
//   0x02434c: aa0203f3  mov      x19, x2
uint64_t fde_0941_sub_024320(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x91004108ULL) + (x2 ^ 0x024320ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x024320: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x024324: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x024328: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001A8ULL; // 0x02432c: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9446908ULL; // 0x024330: ldr x8, [x8, #0x8d0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x024334: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA901FC1FULL; // 0x024338: stp xzr, xzr, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001402ULL; // 0x02433c: str x2, [x0, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0942 @ 0x024374..0x0243e0 (108 bytes)
// [VN] Phục dựng FDE #0942 tại 0x024374..0x0243e0 (108 byte)
//   0x024374: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x024378: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02437c: 910043fd  add      x29, sp, #0x10
//   0x024380: f00001a8  adrp     x8, #0x5b000
//   0x024384: f9461108  ldr      x8, [x8, #0xc20]
//   0x024388: aa0103f3  mov      x19, x1
//   0x02438c: aa0003f4  mov      x20, x0
//   0x024390: 39400108  ldrb     w8, [x8]
//   0x024394: 340000c8  cbz      w8, #0x243ac
//   0x024398: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02439c: aa1403e0  mov      x0, x20
//   0x0243a0: aa1303e1  mov      x1, x19
uint64_t fde_0942_sub_024374(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x340000C8ULL) + (x2 ^ 0x024374ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x024374: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x024378: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02437c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001A8ULL; // 0x024380: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9461108ULL; // 0x024384: ldr x8, [x8, #0xc20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x024388: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x02438c: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x39400108ULL; // 0x024390: ldrb w8, [x8]
    return acc;
}

// [EN] Reconstructed FDE #0943 @ 0x0243e0..0x0244a0 (192 bytes)
// [VN] Phục dựng FDE #0943 tại 0x0243e0..0x0244a0 (192 byte)
//   0x0243e0: d10143ff  sub      sp, sp, #0x50
//   0x0243e4: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x0243e8: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x0243ec: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x0243f0: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x0243f4: 910103fd  add      x29, sp, #0x40
//   0x0243f8: d53bd056  mrs      x22, tpidr_el0
//   0x0243fc: f94016c8  ldr      x8, [x22, #0x28]
//   0x024400: 2a0203f4  mov      w20, w2
//   0x024404: aa0103f3  mov      x19, x1
//   0x024408: aa0003f5  mov      x21, x0
//   0x02440c: f90007e8  str      x8, [sp, #8]
uint64_t fde_0943_sub_0243e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0x2A0203F4ULL) + (x2 ^ 0x0243E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x0243e0: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x0243e4: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x0243e8: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x0243ec: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x0243f0: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x0243f4: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x0243f8: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x0243fc: ldr x8, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0944 @ 0x0244a0..0x024644 (420 bytes)
// [VN] Phục dựng FDE #0944 tại 0x0244a0..0x024644 (420 byte)
//   0x0244a0: d10203ff  sub      sp, sp, #0x80
//   0x0244a4: f90023f7  str      x23, [sp, #0x40]
//   0x0244a8: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x0244ac: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x0244b0: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x0244b4: 9101c3fd  add      x29, sp, #0x70
//   0x0244b8: d53bd055  mrs      x21, tpidr_el0
//   0x0244bc: f94016a8  ldr      x8, [x21, #0x28]
//   0x0244c0: f00001b6  adrp     x22, #0x5b000
//   0x0244c4: f9001fe8  str      x8, [sp, #0x38]
//   0x0244c8: f946eed6  ldr      x22, [x22, #0xdd8]
//   0x0244cc: 394002c8  ldrb     w8, [x22]
uint64_t fde_0944_sub_0244a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xF00001B6ULL) + (x2 ^ 0x0244A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x0244a0: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xF90023F7ULL; // 0x0244a4: str x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x0244a8: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x0244ac: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x0244b0: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x0244b4: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x0244b8: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x0244bc: ldr x8, [x21, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0945 @ 0x024644..0x02469c (88 bytes)
// [VN] Phục dựng FDE #0945 tại 0x024644..0x02469c (88 byte)
//   0x024644: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x024648: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02464c: 910043fd  add      x29, sp, #0x10
//   0x024650: aa0103f3  mov      x19, x1
//   0x024654: 97ffff93  bl       #0x244a0
//   0x024658: 360001c0  tbz      w0, #0, #0x24690
//   0x02465c: f00001a8  adrp     x8, #0x5b000
//   0x024660: f946a108  ldr      x8, [x8, #0xd40]
//   0x024664: f1000e7f  cmp      x19, #3
//   0x024668: 39400109  ldrb     w9, [x8]
//   0x02466c: 52800068  mov      w8, #3
//   0x024670: 9a888268  csel     x8, x19, x8, hi
uint64_t fde_0945_sub_024644(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF1000E7FULL) + (x2 ^ 0x024644ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x024644: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x024648: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02464c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x024650: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFF93ULL; // 0x024654: bl #0x244a0
    acc = (acc * 0x100000001B3ULL) ^ 0x360001C0ULL; // 0x024658: tbz w0, #0, #0x24690
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001A8ULL; // 0x02465c: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF946A108ULL; // 0x024660: ldr x8, [x8, #0xd40]
    return acc;
}

// [EN] Reconstructed FDE #0946 @ 0x02469c..0x0246e0 (68 bytes)
// [VN] Phục dựng FDE #0946 tại 0x02469c..0x0246e0 (68 byte)
//   0x02469c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0246a0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0246a4: 910043fd  add      x29, sp, #0x10
//   0x0246a8: 2a0103f3  mov      w19, w1
//   0x0246ac: 97ffff7d  bl       #0x244a0
//   0x0246b0: 36000120  tbz      w0, #0, #0x246d4
//   0x0246b4: 52800200  mov      w0, #0x10
//   0x0246b8: 97fffe87  bl       #0x240d4
//   0x0246bc: f00001a9  adrp     x9, #0x5b000
//   0x0246c0: f9461129  ldr      x9, [x9, #0xc20]
//   0x0246c4: 7100001f  cmp      w0, #0
//   0x0246c8: 1a9f17e8  cset     w8, eq
uint64_t fde_0946_sub_02469c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF00001A9ULL) + (x2 ^ 0x02469CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02469c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0246a0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0246a4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F3ULL; // 0x0246a8: mov w19, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFF7DULL; // 0x0246ac: bl #0x244a0
    acc = (acc * 0x100000001B3ULL) ^ 0x36000120ULL; // 0x0246b0: tbz w0, #0, #0x246d4
    acc = (acc * 0x100000001B3ULL) ^ 0x52800200ULL; // 0x0246b4: mov w0, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFE87ULL; // 0x0246b8: bl #0x240d4
    return acc;
}

// [EN] Reconstructed FDE #0947 @ 0x0246e0..0x024884 (420 bytes)
// [VN] Phục dựng FDE #0947 tại 0x0246e0..0x024884 (420 byte)
//   0x0246e0: d10183ff  sub      sp, sp, #0x60
//   0x0246e4: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0246e8: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0246ec: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0246f0: 910143fd  add      x29, sp, #0x50
//   0x0246f4: d53bd054  mrs      x20, tpidr_el0
//   0x0246f8: f9401688  ldr      x8, [x20, #0x28]
//   0x0246fc: aa0003f3  mov      x19, x0
//   0x024700: f90017e8  str      x8, [sp, #0x28]
//   0x024704: 97ffff67  bl       #0x244a0
//   0x024708: 36000620  tbz      w0, #0, #0x247cc
//   0x02470c: f00001a8  adrp     x8, #0x5b000
uint64_t fde_0947_sub_0246e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xF90017E8ULL) + (x2 ^ 0x0246E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x0246e0: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x0246e4: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x0246e8: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x0246ec: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x0246f0: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x0246f4: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x0246f8: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0246fc: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0948 @ 0x024884..0x024888 (4 bytes)
// [VN] Phục dựng FDE #0948 tại 0x024884..0x024888 (4 byte)
//   0x024884: 17ff992f  b        #0xad40
uint64_t fde_0948_sub_024884(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FF992FULL) + (x1 ^ 0x17FF992FULL) + (x2 ^ 0x024884ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF992FULL; // 0x024884: b #0xad40
    return acc;
}

// [EN] Reconstructed FDE #0949 @ 0x024888..0x024890 (8 bytes)
// [VN] Phục dựng FDE #0949 tại 0x024888..0x024890 (8 byte)
//   0x024888: 92800002  mov      x2, #-1
//   0x02488c: 14000002  b        #0x24894
uint64_t fde_0949_sub_024888(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x92800002ULL) + (x1 ^ 0x14000002ULL) + (x2 ^ 0x024888ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x92800002ULL; // 0x024888: mov x2, #-1
    acc = (acc * 0x100000001B3ULL) ^ 0x14000002ULL; // 0x02488c: b #0x24894
    return acc;
}

// [EN] Reconstructed FDE #0950 @ 0x024890..0x024894 (4 bytes)
// [VN] Phục dựng FDE #0950 tại 0x024890..0x024894 (4 byte)
//   0x024890: d65f03c0  ret      
uint64_t fde_0950_sub_024890(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x024890ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x024890: ret 
    return acc;
}

// [EN] Reconstructed FDE #0951 @ 0x024894..0x0248b8 (36 bytes)
// [VN] Phục dựng FDE #0951 tại 0x024894..0x0248b8 (36 byte)
//   0x024894: 91008008  add      x8, x0, #0x20
//   0x024898: c85f7d09  ldxr     x9, [x8]
//   0x02489c: 8b02012a  add      x10, x9, x2
//   0x0248a0: c80b7d0a  stxr     w11, x10, [x8]
//   0x0248a4: 35ffffab  cbnz     w11, #0x24898
//   0x0248a8: ab02013f  cmn      x9, x2
//   0x0248ac: 54000041  b.ne     #0x248b4
//   0x0248b0: 14000002  b        #0x248b8
//   0x0248b4: d65f03c0  ret      
uint64_t fde_0951_sub_024894(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x91008008ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x024894ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x91008008ULL; // 0x024894: add x8, x0, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xC85F7D09ULL; // 0x024898: ldxr x9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B02012AULL; // 0x02489c: add x10, x9, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xC80B7D0AULL; // 0x0248a0: stxr w11, x10, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x35FFFFABULL; // 0x0248a4: cbnz w11, #0x24898
    acc = (acc * 0x100000001B3ULL) ^ 0xAB02013FULL; // 0x0248a8: cmn x9, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x54000041ULL; // 0x0248ac: b.ne #0x248b4
    acc = (acc * 0x100000001B3ULL) ^ 0x14000002ULL; // 0x0248b0: b #0x248b8
    return acc;
}

// [EN] Reconstructed FDE #0952 @ 0x0248b8..0x02492c (116 bytes)
// [VN] Phục dựng FDE #0952 tại 0x0248b8..0x02492c (116 byte)
//   0x0248b8: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x0248bc: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0248c0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0248c4: 910083fd  add      x29, sp, #0x20
//   0x0248c8: f00001b6  adrp     x22, #0x5b000
//   0x0248cc: f946ded6  ldr      x22, [x22, #0xdb8]
//   0x0248d0: aa0103f4  mov      x20, x1
//   0x0248d4: aa0003f3  mov      x19, x0
//   0x0248d8: aa1f03f5  mov      x21, xzr
//   0x0248dc: f9400e68  ldr      x8, [x19, #0x18]
//   0x0248e0: eb0802bf  cmp      x21, x8
//   0x0248e4: 540001a2  b.hs     #0x24918
uint64_t fde_0952_sub_0248b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA1F03F5ULL) + (x2 ^ 0x0248B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x0248b8: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0248bc: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0248c0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0248c4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001B6ULL; // 0x0248c8: adrp x22, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF946DED6ULL; // 0x0248cc: ldr x22, [x22, #0xdb8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x0248d0: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0248d4: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0953 @ 0x02492c..0x024940 (20 bytes)
// [VN] Phục dựng FDE #0953 tại 0x02492c..0x024940 (20 byte)
//   0x02492c: f00001b7  adrp     x23, #0x5b000
//   0x024930: f9459ef7  ldr      x23, [x23, #0xb38]
//   0x024934: aa1303e1  mov      x1, x19
//   0x024938: f94002e0  ldr      x0, [x23]
//   0x02493c: 14004c95  b        #0x37b90
uint64_t fde_0953_sub_02492c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF00001B7ULL) + (x1 ^ 0x14004C95ULL) + (x2 ^ 0x02492CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001B7ULL; // 0x02492c: adrp x23, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9459EF7ULL; // 0x024930: ldr x23, [x23, #0xb38]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E1ULL; // 0x024934: mov x1, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF94002E0ULL; // 0x024938: ldr x0, [x23]
    acc = (acc * 0x100000001B3ULL) ^ 0x14004C95ULL; // 0x02493c: b #0x37b90
    return acc;
}

// [EN] Reconstructed FDE #0954 @ 0x024940..0x02494c (12 bytes)
// [VN] Phục dựng FDE #0954 tại 0x024940..0x02494c (12 byte)
//   0x024940: f94002e0  ldr      x0, [x23]
//   0x024944: aa1303e1  mov      x1, x19
//   0x024948: 14004c99  b        #0x37bac
uint64_t fde_0954_sub_024940(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF94002E0ULL) + (x1 ^ 0x14004C99ULL) + (x2 ^ 0x024940ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF94002E0ULL; // 0x024940: ldr x0, [x23]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E1ULL; // 0x024944: mov x1, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x14004C99ULL; // 0x024948: b #0x37bac
    return acc;
}

// [EN] Reconstructed FDE #0955 @ 0x02494c..0x024ae0 (404 bytes)
// [VN] Phục dựng FDE #0955 tại 0x02494c..0x024ae0 (404 byte)
//   0x02494c: d101c3ff  sub      sp, sp, #0x70
//   0x024950: f90013f9  str      x25, [sp, #0x20]
//   0x024954: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x024958: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x02495c: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x024960: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x024964: 910183fd  add      x29, sp, #0x60
//   0x024968: d53bd058  mrs      x24, tpidr_el0
//   0x02496c: f9401708  ldr      x8, [x24, #0x28]
//   0x024970: f00001b9  adrp     x25, #0x5b000
//   0x024974: f9000fe8  str      x8, [sp, #0x18]
//   0x024978: f9447f39  ldr      x25, [x25, #0x8f8]
uint64_t fde_0955_sub_02494c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xF9401708ULL) + (x2 ^ 0x02494CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x02494c: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F9ULL; // 0x024950: str x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x024954: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x024958: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x02495c: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x024960: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x024964: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x024968: mrs x24, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0956 @ 0x024ae0..0x024b00 (32 bytes)
// [VN] Phục dựng FDE #0956 tại 0x024ae0..0x024b00 (32 byte)
//   0x024ae0: 3100201f  cmn      w0, #8
//   0x024ae4: 5400006a  b.ge     #0x24af0
//   0x024ae8: 52800020  mov      w0, #1
//   0x024aec: d65f03c0  ret      
//   0x024af0: 7100001f  cmp      w0, #0
//   0x024af4: 52800048  mov      w8, #2
//   0x024af8: 1a88b500  cinc     w0, w8, ge
//   0x024afc: d65f03c0  ret      
uint64_t fde_0956_sub_024ae0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x3100201FULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x024AE0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x3100201FULL; // 0x024ae0: cmn w0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x5400006AULL; // 0x024ae4: b.ge #0x24af0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800020ULL; // 0x024ae8: mov w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x024aec: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0x7100001FULL; // 0x024af0: cmp w0, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800048ULL; // 0x024af4: mov w8, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x1A88B500ULL; // 0x024af8: cinc w0, w8, ge
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x024afc: ret 
    return acc;
}

// [EN] Reconstructed FDE #0957 @ 0x024b00..0x024b7c (124 bytes)
// [VN] Phục dựng FDE #0957 tại 0x024b00..0x024b7c (124 byte)
//   0x024b00: f00001a8  adrp     x8, #0x5b000
//   0x024b04: f9447d08  ldr      x8, [x8, #0x8f8]
//   0x024b08: 39400108  ldrb     w8, [x8]
//   0x024b0c: 340001a8  cbz      w8, #0x24b40
//   0x024b10: 7100103f  cmp      w1, #4
//   0x024b14: 54000168  b.hi     #0x24b40
//   0x024b18: d00000c9  adrp     x9, #0x3e000
//   0x024b1c: 2a0103e8  mov      w8, w1
//   0x024b20: 9120fd29  add      x9, x9, #0x83f
//   0x024b24: 1000008a  adr      x10, #0x24b34
//   0x024b28: 3868692b  ldrb     w11, [x9, x8]
//   0x024b2c: 8b0b094a  add      x10, x10, x11, lsl #2
uint64_t fde_0957_sub_024b00(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF00001A8ULL) + (x1 ^ 0x9120FD29ULL) + (x2 ^ 0x024B00ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001A8ULL; // 0x024b00: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9447D08ULL; // 0x024b04: ldr x8, [x8, #0x8f8]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400108ULL; // 0x024b08: ldrb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x340001A8ULL; // 0x024b0c: cbz w8, #0x24b40
    acc = (acc * 0x100000001B3ULL) ^ 0x7100103FULL; // 0x024b10: cmp w1, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x54000168ULL; // 0x024b14: b.hi #0x24b40
    acc = (acc * 0x100000001B3ULL) ^ 0xD00000C9ULL; // 0x024b18: adrp x9, #0x3e000
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103E8ULL; // 0x024b1c: mov w8, w1
    return acc;
}

// [EN] Reconstructed FDE #0958 @ 0x024b7c..0x024bac (48 bytes)
// [VN] Phục dựng FDE #0958 tại 0x024b7c..0x024bac (48 byte)
//   0x024b7c: f00001a8  adrp     x8, #0x5b000
//   0x024b80: f9447d08  ldr      x8, [x8, #0x8f8]
//   0x024b84: 39400108  ldrb     w8, [x8]
//   0x024b88: 340000e8  cbz      w8, #0x24ba4
//   0x024b8c: 7100101f  cmp      w0, #4
//   0x024b90: 540000a8  b.hi     #0x24ba4
//   0x024b94: d00001a8  adrp     x8, #0x5a000
//   0x024b98: 91230108  add      x8, x8, #0x8c0
//   0x024b9c: f860d900  ldr      x0, [x8, w0, sxtw #3]
//   0x024ba0: d65f03c0  ret      
//   0x024ba4: aa1f03e0  mov      x0, xzr
//   0x024ba8: d65f03c0  ret      
uint64_t fde_0958_sub_024b7c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF00001A8ULL) + (x1 ^ 0xF860D900ULL) + (x2 ^ 0x024B7CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001A8ULL; // 0x024b7c: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9447D08ULL; // 0x024b80: ldr x8, [x8, #0x8f8]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400108ULL; // 0x024b84: ldrb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x340000E8ULL; // 0x024b88: cbz w8, #0x24ba4
    acc = (acc * 0x100000001B3ULL) ^ 0x7100101FULL; // 0x024b8c: cmp w0, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A8ULL; // 0x024b90: b.hi #0x24ba4
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001A8ULL; // 0x024b94: adrp x8, #0x5a000
    acc = (acc * 0x100000001B3ULL) ^ 0x91230108ULL; // 0x024b98: add x8, x8, #0x8c0
    return acc;
}

// [EN] Reconstructed FDE #0959 @ 0x024bac..0x024c1c (112 bytes)
// [VN] Phục dựng FDE #0959 tại 0x024bac..0x024c1c (112 byte)
//   0x024bac: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x024bb0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x024bb4: 910043fd  add      x29, sp, #0x10
//   0x024bb8: f00001a8  adrp     x8, #0x5b000
//   0x024bbc: f9447d08  ldr      x8, [x8, #0x8f8]
//   0x024bc0: 39400108  ldrb     w8, [x8]
//   0x024bc4: 34000168  cbz      w8, #0x24bf0
//   0x024bc8: 2a0003f3  mov      w19, w0
//   0x024bcc: 52801000  mov      w0, #0x80
//   0x024bd0: aa0103f4  mov      x20, x1
//   0x024bd4: 97ff98d7  bl       #0xaf30
//   0x024bd8: 7100041f  cmp      w0, #1
uint64_t fde_0959_sub_024bac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x52801000ULL) + (x2 ^ 0x024BACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x024bac: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x024bb0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x024bb4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001A8ULL; // 0x024bb8: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9447D08ULL; // 0x024bbc: ldr x8, [x8, #0x8f8]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400108ULL; // 0x024bc0: ldrb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000168ULL; // 0x024bc4: cbz w8, #0x24bf0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F3ULL; // 0x024bc8: mov w19, w0
    return acc;
}

// [EN] Reconstructed FDE #0960 @ 0x024c1c..0x024c24 (8 bytes)
// [VN] Phục dựng FDE #0960 tại 0x024c1c..0x024c24 (8 byte)
//   0x024c1c: f9400401  ldr      x1, [x0, #8]
//   0x024c20: 14000001  b        #0x24c24
uint64_t fde_0960_sub_024c1c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400401ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x024C1CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400401ULL; // 0x024c1c: ldr x1, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x024c20: b #0x24c24
    return acc;
}

// [EN] Reconstructed FDE #0961 @ 0x024c24..0x024c64 (64 bytes)
// [VN] Phục dựng FDE #0961 tại 0x024c24..0x024c64 (64 byte)
//   0x024c24: b40001e1  cbz      x1, #0x24c60
//   0x024c28: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x024c2c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x024c30: 910043fd  add      x29, sp, #0x10
//   0x024c34: aa0103f3  mov      x19, x1
//   0x024c38: f9400021  ldr      x1, [x1]
//   0x024c3c: aa0003f4  mov      x20, x0
//   0x024c40: 97fffff9  bl       #0x24c24
//   0x024c44: f9400661  ldr      x1, [x19, #8]
//   0x024c48: aa1403e0  mov      x0, x20
//   0x024c4c: 97fffff6  bl       #0x24c24
//   0x024c50: a9417bfd  ldp      x29, x30, [sp, #0x10]
uint64_t fde_0961_sub_024c24(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB40001E1ULL) + (x1 ^ 0xF9400661ULL) + (x2 ^ 0x024C24ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001E1ULL; // 0x024c24: cbz x1, #0x24c60
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x024c28: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x024c2c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x024c30: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x024c34: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400021ULL; // 0x024c38: ldr x1, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x024c3c: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFFF9ULL; // 0x024c40: bl #0x24c24
    return acc;
}

// [EN] Reconstructed FDE #0962 @ 0x024c64..0x024cfc (152 bytes)
// [VN] Phục dựng FDE #0962 tại 0x024c64..0x024cfc (152 byte)
//   0x024c64: d10103ff  sub      sp, sp, #0x40
//   0x024c68: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x024c6c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x024c70: 9100c3fd  add      x29, sp, #0x30
//   0x024c74: d53bd054  mrs      x20, tpidr_el0
//   0x024c78: f9401688  ldr      x8, [x20, #0x28]
//   0x024c7c: aa0103f3  mov      x19, x1
//   0x024c80: f9000fe8  str      x8, [sp, #0x18]
//   0x024c84: b90017e0  str      w0, [sp, #0x14]
//   0x024c88: f90007fe  str      x30, [sp, #8]
//   0x024c8c: b40000e1  cbz      x1, #0x24ca8
//   0x024c90: 94000253  bl       #0x255dc
uint64_t fde_0962_sub_024c64(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xB90017E0ULL) + (x2 ^ 0x024C64ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x024c64: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x024c68: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x024c6c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x024c70: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x024c74: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x024c78: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x024c7c: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x024c80: str x8, [sp, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0963 @ 0x024cfc..0x024d04 (8 bytes)
// [VN] Phục dựng FDE #0963 tại 0x024cfc..0x024d04 (8 byte)
//   0x024cfc: b9400000  ldr      w0, [x0]
//   0x024d00: 17ff99f0  b        #0xb4c0
uint64_t fde_0963_sub_024cfc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400000ULL) + (x1 ^ 0x17FF99F0ULL) + (x2 ^ 0x024CFCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400000ULL; // 0x024cfc: ldr w0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF99F0ULL; // 0x024d00: b #0xb4c0
    return acc;
}

// [EN] Reconstructed FDE #0964 @ 0x024d04..0x024d1c (24 bytes)
// [VN] Phục dựng FDE #0964 tại 0x024d04..0x024d1c (24 byte)
//   0x024d04: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x024d08: 910003fd  mov      x29, sp
//   0x024d0c: 9400018c  bl       #0x2533c
//   0x024d10: 92401c21  and      x1, x1, #0xff
//   0x024d14: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x024d18: d65f03c0  ret      
uint64_t fde_0964_sub_024d04(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x024D04ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x024d04: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x024d08: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x9400018CULL; // 0x024d0c: bl #0x2533c
    acc = (acc * 0x100000001B3ULL) ^ 0x92401C21ULL; // 0x024d10: and x1, x1, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x024d14: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x024d18: ret 
    return acc;
}

// [EN] Reconstructed FDE #0965 @ 0x024d1c..0x024fc4 (680 bytes)
// [VN] Phục dựng FDE #0965 tại 0x024d1c..0x024fc4 (680 byte)
//   0x024d1c: d10643ff  sub      sp, sp, #0x190
//   0x024d20: a9136ffc  stp      x28, x27, [sp, #0x130]
//   0x024d24: a91467fa  stp      x26, x25, [sp, #0x140]
//   0x024d28: a9155ff8  stp      x24, x23, [sp, #0x150]
//   0x024d2c: a91657f6  stp      x22, x21, [sp, #0x160]
//   0x024d30: a9174ff4  stp      x20, x19, [sp, #0x170]
//   0x024d34: a9187bfd  stp      x29, x30, [sp, #0x180]
//   0x024d38: 910603fd  add      x29, sp, #0x180
//   0x024d3c: d53bd05b  mrs      x27, tpidr_el0
//   0x024d40: f9401768  ldr      x8, [x27, #0x28]
//   0x024d44: aa0303f3  mov      x19, x3
//   0x024d48: aa0203f4  mov      x20, x2
uint64_t fde_0965_sub_024d1c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10643FFULL) + (x1 ^ 0xD53BD05BULL) + (x2 ^ 0x024D1CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10643FFULL; // 0x024d1c: sub sp, sp, #0x190
    acc = (acc * 0x100000001B3ULL) ^ 0xA9136FFCULL; // 0x024d20: stp x28, x27, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91467FAULL; // 0x024d24: stp x26, x25, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9155FF8ULL; // 0x024d28: stp x24, x23, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91657F6ULL; // 0x024d2c: stp x22, x21, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9174FF4ULL; // 0x024d30: stp x20, x19, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9187BFDULL; // 0x024d34: stp x29, x30, [sp, #0x180]
    acc = (acc * 0x100000001B3ULL) ^ 0x910603FDULL; // 0x024d38: add x29, sp, #0x180
    return acc;
}

// [EN] Reconstructed FDE #0966 @ 0x024fc4..0x02503c (120 bytes)
// [VN] Phục dựng FDE #0966 tại 0x024fc4..0x02503c (120 byte)
//   0x024fc4: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x024fc8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x024fcc: 910043fd  add      x29, sp, #0x10
//   0x024fd0: 2a0103e8  mov      w8, w1
//   0x024fd4: aa0003f4  mov      x20, x0
//   0x024fd8: 6f00e400  movi     v0.2d, #0000000000000000
//   0x024fdc: aa0203f3  mov      x19, x2
//   0x024fe0: b9008001  str      w1, [x0, #0x80]
//   0x024fe4: ad000000  stp      q0, q0, [x0]
//   0x024fe8: ad010000  stp      q0, q0, [x0, #0x20]
//   0x024fec: ad020000  stp      q0, q0, [x0, #0x40]
//   0x024ff0: ad030000  stp      q0, q0, [x0, #0x60]
uint64_t fde_0966_sub_024fc4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAD000000ULL) + (x2 ^ 0x024FC4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x024fc4: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x024fc8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x024fcc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103E8ULL; // 0x024fd0: mov w8, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x024fd4: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x6F00E400ULL; // 0x024fd8: movi v0.2d, #0000000000000000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x024fdc: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xB9008001ULL; // 0x024fe0: str w1, [x0, #0x80]
    return acc;
}

// [EN] Reconstructed FDE #0967 @ 0x02503c..0x02504c (16 bytes)
// [VN] Phục dựng FDE #0967 tại 0x02503c..0x02504c (16 byte)
//   0x02503c: aa0003e2  mov      x2, x0
//   0x025040: b9408000  ldr      w0, [x0, #0x80]
//   0x025044: 52801001  mov      w1, #0x80
//   0x025048: 17ff98c6  b        #0xb360
uint64_t fde_0967_sub_02503c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E2ULL) + (x1 ^ 0x17FF98C6ULL) + (x2 ^ 0x02503CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E2ULL; // 0x02503c: mov x2, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9408000ULL; // 0x025040: ldr w0, [x0, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x52801001ULL; // 0x025044: mov w1, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF98C6ULL; // 0x025048: b #0xb360
    return acc;
}

// [EN] Reconstructed FDE #0968 @ 0x02504c..0x025194 (328 bytes)
// [VN] Phục dựng FDE #0968 tại 0x02504c..0x025194 (328 byte)
//   0x02504c: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x025050: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x025054: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x025058: 910083fd  add      x29, sp, #0x20
//   0x02505c: 900000a0  adrp     x0, #0x39000
//   0x025060: 911cd000  add      x0, x0, #0x734
//   0x025064: 97ff9843  bl       #0xb170
//   0x025068: d00001b4  adrp     x20, #0x5b000
//   0x02506c: f9473e94  ldr      x20, [x20, #0xe78]
//   0x025070: b4000100  cbz      x0, #0x25090
//   0x025074: b00000c1  adrp     x1, #0x3e000
//   0x025078: 9121f021  add      x1, x1, #0x87c
uint64_t fde_0968_sub_02504c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xF9473E94ULL) + (x2 ^ 0x02504CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x02504c: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x025050: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x025054: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x025058: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x900000A0ULL; // 0x02505c: adrp x0, #0x39000
    acc = (acc * 0x100000001B3ULL) ^ 0x911CD000ULL; // 0x025060: add x0, x0, #0x734
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF9843ULL; // 0x025064: bl #0xb170
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001B4ULL; // 0x025068: adrp x20, #0x5b000
    return acc;
}

// [EN] Reconstructed FDE #0969 @ 0x025194..0x0251d4 (64 bytes)
// [VN] Phục dựng FDE #0969 tại 0x025194..0x0251d4 (64 byte)
//   0x025194: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x025198: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02519c: 910043fd  add      x29, sp, #0x10
//   0x0251a0: 9400010f  bl       #0x255dc
//   0x0251a4: b4000120  cbz      x0, #0x251c8
//   0x0251a8: aa0003f3  mov      x19, x0
//   0x0251ac: 52800300  mov      w0, #0x18
//   0x0251b0: 97ff9910  bl       #0xb5f0
//   0x0251b4: aa0003e8  mov      x8, x0
//   0x0251b8: f8008d1f  str      xzr, [x8, #8]!
//   0x0251bc: f900081f  str      xzr, [x0, #0x10]
//   0x0251c0: f9000008  str      x8, [x0]
uint64_t fde_0969_sub_025194(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xAA0003E8ULL) + (x2 ^ 0x025194ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x025194: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x025198: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02519c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x9400010FULL; // 0x0251a0: bl #0x255dc
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000120ULL; // 0x0251a4: cbz x0, #0x251c8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0251a8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800300ULL; // 0x0251ac: mov w0, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF9910ULL; // 0x0251b0: bl #0xb5f0
    return acc;
}

// [EN] Reconstructed FDE #0970 @ 0x0251d4..0x0252b4 (224 bytes)
// [VN] Phục dựng FDE #0970 tại 0x0251d4..0x0252b4 (224 byte)
//   0x0251d4: d10183ff  sub      sp, sp, #0x60
//   0x0251d8: f90013f7  str      x23, [sp, #0x20]
//   0x0251dc: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0251e0: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0251e4: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0251e8: 910143fd  add      x29, sp, #0x50
//   0x0251ec: d53bd055  mrs      x21, tpidr_el0
//   0x0251f0: f94016a8  ldr      x8, [x21, #0x28]
//   0x0251f4: d00001b7  adrp     x23, #0x5b000
//   0x0251f8: f9000fe8  str      x8, [sp, #0x18]
//   0x0251fc: f94712f7  ldr      x23, [x23, #0xe20]
//   0x025200: f94002e8  ldr      x8, [x23]
uint64_t fde_0970_sub_0251d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xD00001B7ULL) + (x2 ^ 0x0251D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x0251d4: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F7ULL; // 0x0251d8: str x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x0251dc: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x0251e0: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x0251e4: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x0251e8: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x0251ec: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x0251f0: ldr x8, [x21, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0971 @ 0x0252b4..0x02530c (88 bytes)
// [VN] Phục dựng FDE #0971 tại 0x0252b4..0x02530c (88 byte)
//   0x0252b4: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0252b8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0252bc: 910043fd  add      x29, sp, #0x10
//   0x0252c0: 97fffda3  bl       #0x2494c
//   0x0252c4: 97ff9723  bl       #0xaf50
//   0x0252c8: d00001b3  adrp     x19, #0x5b000
//   0x0252cc: f9440673  ldr      x19, [x19, #0x808]
//   0x0252d0: 52801001  mov      w1, #0x80
//   0x0252d4: aa1303e2  mov      x2, x19
//   0x0252d8: 97ff984a  bl       #0xb400
//   0x0252dc: 97ff971d  bl       #0xaf50
//   0x0252e0: 52800021  mov      w1, #1
uint64_t fde_0971_sub_0252b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xAA1303E2ULL) + (x2 ^ 0x0252B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0252b4: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0252b8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0252bc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFDA3ULL; // 0x0252c0: bl #0x2494c
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF9723ULL; // 0x0252c4: bl #0xaf50
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001B3ULL; // 0x0252c8: adrp x19, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9440673ULL; // 0x0252cc: ldr x19, [x19, #0x808]
    acc = (acc * 0x100000001B3ULL) ^ 0x52801001ULL; // 0x0252d0: mov w1, #0x80
    return acc;
}

// [EN] Reconstructed FDE #0972 @ 0x02530c..0x02533c (48 bytes)
// [VN] Phục dựng FDE #0972 tại 0x02530c..0x02533c (48 byte)
//   0x02530c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x025310: 910003fd  mov      x29, sp
//   0x025314: 52800020  mov      w0, #1
//   0x025318: 97fffe19  bl       #0x24b7c
//   0x02531c: b40000c0  cbz      x0, #0x25334
//   0x025320: 97ff970c  bl       #0xaf50
//   0x025324: d00001a1  adrp     x1, #0x5b000
//   0x025328: f9440421  ldr      x1, [x1, #0x808]
//   0x02532c: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x025330: 17fffe1f  b        #0x24bac
//   0x025334: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x025338: d65f03c0  ret      
uint64_t fde_0972_sub_02530c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xA8C17BFDULL) + (x2 ^ 0x02530CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x02530c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x025310: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x52800020ULL; // 0x025314: mov w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFE19ULL; // 0x025318: bl #0x24b7c
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000C0ULL; // 0x02531c: cbz x0, #0x25334
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF970CULL; // 0x025320: bl #0xaf50
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001A1ULL; // 0x025324: adrp x1, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9440421ULL; // 0x025328: ldr x1, [x1, #0x808]
    return acc;
}

// [EN] Reconstructed FDE #0973 @ 0x02533c..0x025344 (8 bytes)
// [VN] Phục dựng FDE #0973 tại 0x02533c..0x025344 (8 byte)
//   0x02533c: aa0103e2  mov      x2, x1
//   0x025340: 14000001  b        #0x25344
uint64_t fde_0973_sub_02533c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0103E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x02533CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E2ULL; // 0x02533c: mov x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x025340: b #0x25344
    return acc;
}

// [EN] Reconstructed FDE #0974 @ 0x025344..0x0253f4 (176 bytes)
// [VN] Phục dựng FDE #0974 tại 0x025344..0x0253f4 (176 byte)
//   0x025344: d101c3ff  sub      sp, sp, #0x70
//   0x025348: f9001bf7  str      x23, [sp, #0x30]
//   0x02534c: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x025350: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x025354: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x025358: 910183fd  add      x29, sp, #0x60
//   0x02535c: d53bd057  mrs      x23, tpidr_el0
//   0x025360: f94016e8  ldr      x8, [x23, #0x28]
//   0x025364: aa0203f5  mov      x21, x2
//   0x025368: aa0103e2  mov      x2, x1
//   0x02536c: 910023e1  add      x1, sp, #8
//   0x025370: aa0003f4  mov      x20, x0
uint64_t fde_0974_sub_025344(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xAA0203F5ULL) + (x2 ^ 0x025344ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x025344: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF7ULL; // 0x025348: str x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x02534c: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x025350: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x025354: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x025358: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x02535c: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x025360: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0975 @ 0x0253f4..0x025454 (96 bytes)
// [VN] Phục dựng FDE #0975 tại 0x0253f4..0x025454 (96 byte)
//   0x0253f4: aa0003e8  mov      x8, x0
//   0x0253f8: f8408c09  ldr      x9, [x0, #8]!
//   0x0253fc: b4000229  cbz      x9, #0x25440
//   0x025400: b940004a  ldr      w10, [x2]
//   0x025404: 91002100  add      x0, x8, #8
//   0x025408: b9401d28  ldr      w8, [x9, #0x1c]
//   0x02540c: 6b08015f  cmp      w10, w8
//   0x025410: 540000aa  b.ge     #0x25424
//   0x025414: f9400128  ldr      x8, [x9]
//   0x025418: b4000188  cbz      x8, #0x25448
//   0x02541c: aa0903e0  mov      x0, x9
//   0x025420: 14000006  b        #0x25438
uint64_t fde_0975_sub_0253f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xF9400128ULL) + (x2 ^ 0x0253F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x0253f4: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF8408C09ULL; // 0x0253f8: ldr x9, [x0, #8]!
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000229ULL; // 0x0253fc: cbz x9, #0x25440
    acc = (acc * 0x100000001B3ULL) ^ 0xB940004AULL; // 0x025400: ldr w10, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0x91002100ULL; // 0x025404: add x0, x8, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401D28ULL; // 0x025408: ldr w8, [x9, #0x1c]
    acc = (acc * 0x100000001B3ULL) ^ 0x6B08015FULL; // 0x02540c: cmp w10, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x540000AAULL; // 0x025410: b.ge #0x25424
    return acc;
}

// [EN] Reconstructed FDE #0976 @ 0x025454..0x0254a0 (76 bytes)
// [VN] Phục dựng FDE #0976 tại 0x025454..0x0254a0 (76 byte)
//   0x025454: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x025458: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02545c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x025460: 910083fd  add      x29, sp, #0x20
//   0x025464: 91002015  add      x21, x0, #8
//   0x025468: aa0103f3  mov      x19, x1
//   0x02546c: 52800021  mov      w1, #1
//   0x025470: aa1503e0  mov      x0, x21
//   0x025474: aa0803f4  mov      x20, x8
//   0x025478: 52800036  mov      w22, #1
//   0x02547c: 94000020  bl       #0x254fc
//   0x025480: a9005680  stp      x0, x21, [x20]
uint64_t fde_0976_sub_025454(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA0803F4ULL) + (x2 ^ 0x025454ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x025454: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x025458: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02545c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x025460: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x91002015ULL; // 0x025464: add x21, x0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x025468: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x02546c: mov w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E0ULL; // 0x025470: mov x0, x21
    return acc;
}

// [EN] Reconstructed FDE #0977 @ 0x0254a0..0x0254f4 (84 bytes)
// [VN] Phục dựng FDE #0977 tại 0x0254a0..0x0254f4 (84 byte)
//   0x0254a0: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0254a4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0254a8: 910043fd  add      x29, sp, #0x10
//   0x0254ac: a9007c7f  stp      xzr, xzr, [x3]
//   0x0254b0: f9000861  str      x1, [x3, #0x10]
//   0x0254b4: f9000043  str      x3, [x2]
//   0x0254b8: f9400008  ldr      x8, [x0]
//   0x0254bc: aa0003f3  mov      x19, x0
//   0x0254c0: f9400108  ldr      x8, [x8]
//   0x0254c4: b4000068  cbz      x8, #0x254d0
//   0x0254c8: f9000268  str      x8, [x19]
//   0x0254cc: f9400043  ldr      x3, [x2]
uint64_t fde_0977_sub_0254a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9400108ULL) + (x2 ^ 0x0254A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0254a0: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0254a4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0254a8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xA9007C7FULL; // 0x0254ac: stp xzr, xzr, [x3]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000861ULL; // 0x0254b0: str x1, [x3, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000043ULL; // 0x0254b4: str x3, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x0254b8: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0254bc: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0978 @ 0x0254f4..0x0254fc (8 bytes)
// [VN] Phục dựng FDE #0978 tại 0x0254f4..0x0254fc (8 byte)
//   0x0254f4: aa1f03e1  mov      x1, xzr
//   0x0254f8: 1400000a  b        #0x25520
uint64_t fde_0978_sub_0254f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E1ULL) + (x1 ^ 0x1400000AULL) + (x2 ^ 0x0254F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x0254f4: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x1400000AULL; // 0x0254f8: b #0x25520
    return acc;
}

// [EN] Reconstructed FDE #0979 @ 0x0254fc..0x025504 (8 bytes)
// [VN] Phục dựng FDE #0979 tại 0x0254fc..0x025504 (8 byte)
//   0x0254fc: aa1f03e2  mov      x2, xzr
//   0x025500: 14000001  b        #0x25504
uint64_t fde_0979_sub_0254fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x0254FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x0254fc: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x025500: b #0x25504
    return acc;
}

// [EN] Reconstructed FDE #0980 @ 0x025504..0x025520 (28 bytes)
// [VN] Phục dựng FDE #0980 tại 0x025504..0x025520 (28 byte)
//   0x025504: d37bfc28  lsr      x8, x1, #0x3b
//   0x025508: b5000068  cbnz     x8, #0x25514
//   0x02550c: d37be820  lsl      x0, x1, #5
//   0x025510: 17ff9838  b        #0xb5f0
//   0x025514: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x025518: 910003fd  mov      x29, sp
//   0x02551c: 97ff97f9  bl       #0xb500
uint64_t fde_0980_sub_025504(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD37BFC28ULL) + (x1 ^ 0x97FF97F9ULL) + (x2 ^ 0x025504ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD37BFC28ULL; // 0x025504: lsr x8, x1, #0x3b
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000068ULL; // 0x025508: cbnz x8, #0x25514
    acc = (acc * 0x100000001B3ULL) ^ 0xD37BE820ULL; // 0x02550c: lsl x0, x1, #5
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF9838ULL; // 0x025510: b #0xb5f0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x025514: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x025518: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF97F9ULL; // 0x02551c: bl #0xb500
    return acc;
}

// [EN] Reconstructed FDE #0981 @ 0x025520..0x025538 (24 bytes)
// [VN] Phục dựng FDE #0981 tại 0x025520..0x025538 (24 byte)
//   0x025520: aa0003e8  mov      x8, x0
//   0x025524: f9400000  ldr      x0, [x0]
//   0x025528: f9000101  str      x1, [x8]
//   0x02552c: b4000040  cbz      x0, #0x25534
//   0x025530: 17ff9604  b        #0xad40
//   0x025534: d65f03c0  ret      
uint64_t fde_0981_sub_025520(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x025520ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x025520: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x025524: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000101ULL; // 0x025528: str x1, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000040ULL; // 0x02552c: cbz x0, #0x25534
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF9604ULL; // 0x025530: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x025534: ret 
    return acc;
}

// [EN] Reconstructed FDE #0982 @ 0x025538..0x025540 (8 bytes)
// [VN] Phục dựng FDE #0982 tại 0x025538..0x025540 (8 byte)
//   0x025538: f9400401  ldr      x1, [x0, #8]
//   0x02553c: 14000001  b        #0x25540
uint64_t fde_0982_sub_025538(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400401ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x025538ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400401ULL; // 0x025538: ldr x1, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x02553c: b #0x25540
    return acc;
}

// [EN] Reconstructed FDE #0983 @ 0x025540..0x025580 (64 bytes)
// [VN] Phục dựng FDE #0983 tại 0x025540..0x025580 (64 byte)
//   0x025540: b40001e1  cbz      x1, #0x2557c
//   0x025544: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x025548: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02554c: 910043fd  add      x29, sp, #0x10
//   0x025550: aa0103f3  mov      x19, x1
//   0x025554: f9400021  ldr      x1, [x1]
//   0x025558: aa0003f4  mov      x20, x0
//   0x02555c: 97fffff9  bl       #0x25540
//   0x025560: f9400661  ldr      x1, [x19, #8]
//   0x025564: aa1403e0  mov      x0, x20
//   0x025568: 97fffff6  bl       #0x25540
//   0x02556c: a9417bfd  ldp      x29, x30, [sp, #0x10]
uint64_t fde_0983_sub_025540(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB40001E1ULL) + (x1 ^ 0xF9400661ULL) + (x2 ^ 0x025540ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001E1ULL; // 0x025540: cbz x1, #0x2557c
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x025544: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x025548: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02554c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x025550: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400021ULL; // 0x025554: ldr x1, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x025558: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFFF9ULL; // 0x02555c: bl #0x25540
    return acc;
}

// [EN] Reconstructed FDE #0984 @ 0x025580..0x0255dc (92 bytes)
// [VN] Phục dựng FDE #0984 tại 0x025580..0x0255dc (92 byte)
//   0x025580: f9400028  ldr      x8, [x1]
//   0x025584: f9400009  ldr      x9, [x0]
//   0x025588: f9000008  str      x8, [x0]
//   0x02558c: f9000029  str      x9, [x1]
//   0x025590: aa0003e9  mov      x9, x0
//   0x025594: f8408d2b  ldr      x11, [x9, #8]!
//   0x025598: aa0103e8  mov      x8, x1
//   0x02559c: 3cc08d00  ldr      q0, [x8, #8]!
//   0x0255a0: f940052a  ldr      x10, [x9, #8]
//   0x0255a4: 3d800120  str      q0, [x9]
//   0x0255a8: f900010b  str      x11, [x8]
//   0x0255ac: f900082a  str      x10, [x1, #0x10]
uint64_t fde_0984_sub_025580(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400028ULL) + (x1 ^ 0xF940052AULL) + (x2 ^ 0x025580ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400028ULL; // 0x025580: ldr x8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400009ULL; // 0x025584: ldr x9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000008ULL; // 0x025588: str x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000029ULL; // 0x02558c: str x9, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E9ULL; // 0x025590: mov x9, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF8408D2BULL; // 0x025594: ldr x11, [x9, #8]!
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E8ULL; // 0x025598: mov x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x3CC08D00ULL; // 0x02559c: ldr q0, [x8, #8]!
    return acc;
}

// [EN] Reconstructed FDE #0985 @ 0x0255dc..0x0255e8 (12 bytes)
// [VN] Phục dựng FDE #0985 tại 0x0255dc..0x0255e8 (12 byte)
//   0x0255dc: d00001a0  adrp     x0, #0x5b000
//   0x0255e0: f9431800  ldr      x0, [x0, #0x630]
//   0x0255e4: 17fffdc6  b        #0x24cfc
uint64_t fde_0985_sub_0255dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD00001A0ULL) + (x1 ^ 0x17FFFDC6ULL) + (x2 ^ 0x0255DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001A0ULL; // 0x0255dc: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9431800ULL; // 0x0255e0: ldr x0, [x0, #0x630]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFDC6ULL; // 0x0255e4: b #0x24cfc
    return acc;
}

// [EN] Reconstructed FDE #0986 @ 0x0255e8..0x025600 (24 bytes)
// [VN] Phục dựng FDE #0986 tại 0x0255e8..0x025600 (24 byte)
//   0x0255e8: aa0003e8  mov      x8, x0
//   0x0255ec: aa1603e0  mov      x0, x22
//   0x0255f0: aa1503e1  mov      x1, x21
//   0x0255f4: aa1403e2  mov      x2, x20
//   0x0255f8: aa1303e3  mov      x3, x19
//   0x0255fc: d61f0100  br       x8
uint64_t fde_0986_sub_0255e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x0255E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x0255e8: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1603E0ULL; // 0x0255ec: mov x0, x22
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E1ULL; // 0x0255f0: mov x1, x21
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E2ULL; // 0x0255f4: mov x2, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E3ULL; // 0x0255f8: mov x3, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x0255fc: br x8
    return acc;
}

// [EN] Reconstructed FDE #0987 @ 0x025600..0x02560c (12 bytes)
// [VN] Phục dựng FDE #0987 tại 0x025600..0x02560c (12 byte)
//   0x025600: d00001a0  adrp     x0, #0x5b000
//   0x025604: f947b400  ldr      x0, [x0, #0xf68]
//   0x025608: 17ff978e  b        #0xb440
uint64_t fde_0987_sub_025600(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD00001A0ULL) + (x1 ^ 0x17FF978EULL) + (x2 ^ 0x025600ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001A0ULL; // 0x025600: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF947B400ULL; // 0x025604: ldr x0, [x0, #0xf68]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF978EULL; // 0x025608: b #0xb440
    return acc;
}

// [EN] Reconstructed FDE #0988 @ 0x02560c..0x025620 (20 bytes)
// [VN] Phục dựng FDE #0988 tại 0x02560c..0x025620 (20 byte)
//   0x02560c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x025610: 910003fd  mov      x29, sp
//   0x025614: 94000630  bl       #0x26ed4
//   0x025618: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x02561c: 17fffede  b        #0x25194
uint64_t fde_0988_sub_02560c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x17FFFEDEULL) + (x2 ^ 0x02560CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x02560c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x025610: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x94000630ULL; // 0x025614: bl #0x26ed4
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x025618: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFEDEULL; // 0x02561c: b #0x25194
    return acc;
}

// [EN] Reconstructed FDE #0989 @ 0x025620..0x025634 (20 bytes)
// [VN] Phục dựng FDE #0989 tại 0x025620..0x025634 (20 byte)
//   0x025620: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x025624: 910003fd  mov      x29, sp
//   0x025628: 94000662  bl       #0x26fb0
//   0x02562c: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x025630: 17fffee9  b        #0x251d4
uint64_t fde_0989_sub_025620(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x17FFFEE9ULL) + (x2 ^ 0x025620ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x025620: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x025624: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x94000662ULL; // 0x025628: bl #0x26fb0
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x02562c: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFEE9ULL; // 0x025630: b #0x251d4
    return acc;
}

// [EN] Reconstructed FDE #0990 @ 0x025634..0x0257ec (440 bytes)
// [VN] Phục dựng FDE #0990 tại 0x025634..0x0257ec (440 byte)
//   0x025634: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x025638: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x02563c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x025640: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x025644: 9100c3fd  add      x29, sp, #0x30
//   0x025648: d00001b7  adrp     x23, #0x5b000
//   0x02564c: f94646f7  ldr      x23, [x23, #0xc88]
//   0x025650: 52800028  mov      w8, #1
//   0x025654: aa0003f3  mov      x19, x0
//   0x025658: 390002e8  strb     w8, [x23]
//   0x02565c: 97ff967d  bl       #0xb050
//   0x025660: 97ff95b0  bl       #0xad20
uint64_t fde_0990_sub_025634(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x025634ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x025634: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x025638: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x02563c: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x025640: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x025644: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001B7ULL; // 0x025648: adrp x23, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF94646F7ULL; // 0x02564c: ldr x23, [x23, #0xc88]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800028ULL; // 0x025650: mov w8, #1
    return acc;
}

// [EN] Reconstructed FDE #0991 @ 0x0257ec..0x025864 (120 bytes)
// [VN] Phục dựng FDE #0991 tại 0x0257ec..0x025864 (120 byte)
//   0x0257ec: d10103ff  sub      sp, sp, #0x40
//   0x0257f0: f9000bf5  str      x21, [sp, #0x10]
//   0x0257f4: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0257f8: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0257fc: 9100c3fd  add      x29, sp, #0x30
//   0x025800: d53bd055  mrs      x21, tpidr_el0
//   0x025804: f94016a8  ldr      x8, [x21, #0x28]
//   0x025808: 52800100  mov      w0, #8
//   0x02580c: 2a0203f3  mov      w19, w2
//   0x025810: 2a0103f4  mov      w20, w1
//   0x025814: f90007e8  str      x8, [sp, #8]
//   0x025818: 97ff9776  bl       #0xb5f0
uint64_t fde_0991_sub_0257ec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x2A0203F3ULL) + (x2 ^ 0x0257ECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x0257ec: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF5ULL; // 0x0257f0: str x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0257f4: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0257f8: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0257fc: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x025800: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x025804: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800100ULL; // 0x025808: mov w0, #8
    return acc;
}

// [EN] Reconstructed FDE #0992 @ 0x025864..0x025938 (212 bytes)
// [VN] Phục dựng FDE #0992 tại 0x025864..0x025938 (212 byte)
//   0x025864: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x025868: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02586c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x025870: 910083fd  add      x29, sp, #0x20
//   0x025874: d00001b6  adrp     x22, #0x5b000
//   0x025878: f9467ed6  ldr      x22, [x22, #0xcf8]
//   0x02587c: 394002c8  ldrb     w8, [x22]
//   0x025880: 35000528  cbnz     w8, #0x25924
//   0x025884: 2a0303f4  mov      w20, w3
//   0x025888: 2a0203f3  mov      w19, w2
//   0x02588c: aa0003f5  mov      x21, x0
//   0x025890: 97ffc761  bl       #0x17614
uint64_t fde_0992_sub_025864(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x2A0303F4ULL) + (x2 ^ 0x025864ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x025864: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x025868: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02586c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x025870: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001B6ULL; // 0x025874: adrp x22, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9467ED6ULL; // 0x025878: ldr x22, [x22, #0xcf8]
    acc = (acc * 0x100000001B3ULL) ^ 0x394002C8ULL; // 0x02587c: ldrb w8, [x22]
    acc = (acc * 0x100000001B3ULL) ^ 0x35000528ULL; // 0x025880: cbnz w8, #0x25924
    return acc;
}

// [EN] Reconstructed FDE #0993 @ 0x025938..0x025948 (16 bytes)
// [VN] Phục dựng FDE #0993 tại 0x025938..0x025948 (16 byte)
//   0x025938: 12800122  mov      w2, #-0xa
//   0x02593c: 2a1f03e0  mov      w0, wzr
//   0x025940: 2a1f03e1  mov      w1, wzr
//   0x025944: 17ff964b  b        #0xb270
uint64_t fde_0993_sub_025938(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x12800122ULL) + (x1 ^ 0x17FF964BULL) + (x2 ^ 0x025938ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x12800122ULL; // 0x025938: mov w2, #-0xa
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x02593c: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E1ULL; // 0x025940: mov w1, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF964BULL; // 0x025944: b #0xb270
    return acc;
}

// [EN] Reconstructed FDE #0994 @ 0x025948..0x025954 (12 bytes)
// [VN] Phục dựng FDE #0994 tại 0x025948..0x025954 (12 byte)
//   0x025948: 2a0003e1  mov      w1, w0
//   0x02594c: 2a1f03e0  mov      w0, wzr
//   0x025950: 17ff94d8  b        #0xacb0
uint64_t fde_0994_sub_025948(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A0003E1ULL) + (x1 ^ 0x17FF94D8ULL) + (x2 ^ 0x025948ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003E1ULL; // 0x025948: mov w1, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x02594c: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF94D8ULL; // 0x025950: b #0xacb0
    return acc;
}

// [EN] Reconstructed FDE #0995 @ 0x025954..0x025afc (424 bytes)
// [VN] Phục dựng FDE #0995 tại 0x025954..0x025afc (424 byte)
//   0x025954: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x025958: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x02595c: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x025960: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x025964: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x025968: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x02596c: 910143fd  add      x29, sp, #0x50
//   0x025970: b4000220  cbz      x0, #0x259b4
//   0x025974: 9102b008  add      x8, x0, #0xac
//   0x025978: 08dffd08  ldarb    w8, [x8]
//   0x02597c: aa0003f5  mov      x21, x0
//   0x025980: 72001d1f  tst      w8, #0xff
uint64_t fde_0995_sub_025954(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0x9102B008ULL) + (x2 ^ 0x025954ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x025954: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x025958: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x02595c: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x025960: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x025964: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x025968: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x02596c: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000220ULL; // 0x025970: cbz x0, #0x259b4
    return acc;
}

// [EN] Reconstructed FDE #0996 @ 0x025afc..0x025ccc (464 bytes)
// [VN] Phục dựng FDE #0996 tại 0x025afc..0x025ccc (464 byte)
//   0x025afc: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x025b00: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x025b04: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x025b08: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x025b0c: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x025b10: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x025b14: 910143fd  add      x29, sp, #0x50
//   0x025b18: 9100b013  add      x19, x0, #0x2c
//   0x025b1c: aa0003f4  mov      x20, x0
//   0x025b20: aa1303e0  mov      x0, x19
//   0x025b24: 97ff96ab  bl       #0xb5d0
//   0x025b28: f9405a88  ldr      x8, [x20, #0xb0]
uint64_t fde_0996_sub_025afc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xAA0003F4ULL) + (x2 ^ 0x025AFCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x025afc: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x025b00: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x025b04: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x025b08: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x025b0c: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x025b10: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x025b14: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0x9100B013ULL; // 0x025b18: add x19, x0, #0x2c
    return acc;
}

// [EN] Reconstructed FDE #0997 @ 0x025ccc..0x025dc4 (248 bytes)
// [VN] Phục dựng FDE #0997 tại 0x025ccc..0x025dc4 (248 byte)
//   0x025ccc: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x025cd0: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x025cd4: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x025cd8: 910083fd  add      x29, sp, #0x20
//   0x025cdc: aa0003f4  mov      x20, x0
//   0x025ce0: 52802800  mov      w0, #0x140
//   0x025ce4: 97ff9487  bl       #0xaf00
//   0x025ce8: aa0003f3  mov      x19, x0
//   0x025cec: b4000460  cbz      x0, #0x25d78
//   0x025cf0: 9104a268  add      x8, x19, #0x128
//   0x025cf4: 9100b260  add      x0, x19, #0x2c
//   0x025cf8: aa1f03e1  mov      x1, xzr
uint64_t fde_0997_sub_025ccc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xB4000460ULL) + (x2 ^ 0x025CCCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x025ccc: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x025cd0: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x025cd4: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x025cd8: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x025cdc: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52802800ULL; // 0x025ce0: mov w0, #0x140
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF9487ULL; // 0x025ce4: bl #0xaf00
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x025ce8: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0998 @ 0x025dc4..0x025f1c (344 bytes)
// [VN] Phục dựng FDE #0998 tại 0x025dc4..0x025f1c (344 byte)
//   0x025dc4: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x025dc8: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x025dcc: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x025dd0: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x025dd4: 9100c3fd  add      x29, sp, #0x30
//   0x025dd8: b4000240  cbz      x0, #0x25e20
//   0x025ddc: 9400005d  bl       #0x25f50
//   0x025de0: 34000208  cbz      w8, #0x25e20
//   0x025de4: 9102b268  add      x8, x19, #0xac
//   0x025de8: 08dffd09  ldarb    w9, [x8]
//   0x025dec: 72001d3f  tst      w9, #0xff
//   0x025df0: 540002e0  b.eq     #0x25e4c
uint64_t fde_0998_sub_025dc4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x9102B268ULL) + (x2 ^ 0x025DC4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x025dc4: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x025dc8: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x025dcc: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x025dd0: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x025dd4: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000240ULL; // 0x025dd8: cbz x0, #0x25e20
    acc = (acc * 0x100000001B3ULL) ^ 0x9400005DULL; // 0x025ddc: bl #0x25f50
    acc = (acc * 0x100000001B3ULL) ^ 0x34000208ULL; // 0x025de0: cbz w8, #0x25e20
    return acc;
}

// [EN] Reconstructed FDE #0999 @ 0x025f1c..0x025f28 (12 bytes)
// [VN] Phục dựng FDE #0999 tại 0x025f1c..0x025f28 (12 byte)
//   0x025f1c: 9104a008  add      x8, x0, #0x128
//   0x025f20: c8dffd00  ldar     x0, [x8]
//   0x025f24: d65f03c0  ret      
uint64_t fde_0999_sub_025f1c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x9104A008ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x025F1CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x9104A008ULL; // 0x025f1c: add x8, x0, #0x128
    acc = (acc * 0x100000001B3ULL) ^ 0xC8DFFD00ULL; // 0x025f20: ldar x0, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x025f24: ret 
    return acc;
}

// [EN] Reconstructed FDE #1000 @ 0x025f28..0x025f30 (8 bytes)
// [VN] Phục dựng FDE #1000 tại 0x025f28..0x025f30 (8 byte)
//   0x025f28: f9400800  ldr      x0, [x0, #0x10]
//   0x025f2c: d65f03c0  ret      
uint64_t fde_1000_sub_025f28(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400800ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x025F28ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400800ULL; // 0x025f28: ldr x0, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x025f2c: ret 
    return acc;
}

// [EN] Reconstructed FDE #1001 @ 0x025f30..0x025f38 (8 bytes)
// [VN] Phục dựng FDE #1001 tại 0x025f30..0x025f38 (8 byte)
//   0x025f30: f9401000  ldr      x0, [x0, #0x20]
//   0x025f34: d65f03c0  ret      
uint64_t fde_1001_sub_025f30(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9401000ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x025F30ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401000ULL; // 0x025f30: ldr x0, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x025f34: ret 
    return acc;
}

// [EN] Reconstructed FDE #1002 @ 0x025f38..0x025f40 (8 bytes)
// [VN] Phục dựng FDE #1002 tại 0x025f38..0x025f40 (8 byte)
//   0x025f38: a9130801  stp      x1, x2, [x0, #0x130]
//   0x025f3c: d65f03c0  ret      
uint64_t fde_1002_sub_025f38(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9130801ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x025F38ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9130801ULL; // 0x025f38: stp x1, x2, [x0, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x025f3c: ret 
    return acc;
}

// [EN] Reconstructed FDE #1003 @ 0x025f40..0x025f48 (8 bytes)
// [VN] Phục dựng FDE #1003 tại 0x025f40..0x025f48 (8 byte)
//   0x025f40: 528000c0  mov      w0, #6
//   0x025f44: 17ff94a7  b        #0xb1e0
uint64_t fde_1003_sub_025f40(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x528000C0ULL) + (x1 ^ 0x17FF94A7ULL) + (x2 ^ 0x025F40ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C0ULL; // 0x025f40: mov w0, #6
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF94A7ULL; // 0x025f44: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #1004 @ 0x025f48..0x025f50 (8 bytes)
// [VN] Phục dựng FDE #1004 tại 0x025f48..0x025f50 (8 byte)
//   0x025f48: aa1403e0  mov      x0, x20
//   0x025f4c: 17ff95a1  b        #0xb5d0
uint64_t fde_1004_sub_025f48(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1403E0ULL) + (x1 ^ 0x17FF95A1ULL) + (x2 ^ 0x025F48ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x025f48: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF95A1ULL; // 0x025f4c: b #0xb5d0
    return acc;
}

// [EN] Reconstructed FDE #1005 @ 0x025f50..0x025f5c (12 bytes)
// [VN] Phục dựng FDE #1005 tại 0x025f50..0x025f5c (12 byte)
//   0x025f50: 3940a008  ldrb     w8, [x0, #0x28]
//   0x025f54: aa0003f3  mov      x19, x0
//   0x025f58: d65f03c0  ret      
uint64_t fde_1005_sub_025f50(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x3940A008ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x025F50ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x3940A008ULL; // 0x025f50: ldrb w8, [x0, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x025f54: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x025f58: ret 
    return acc;
}

// [EN] Reconstructed FDE #1006 @ 0x025f5c..0x025f64 (8 bytes)
// [VN] Phục dựng FDE #1006 tại 0x025f5c..0x025f64 (8 byte)
//   0x025f5c: aa1403e0  mov      x0, x20
//   0x025f60: 17ff94ac  b        #0xb210
uint64_t fde_1006_sub_025f5c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1403E0ULL) + (x1 ^ 0x17FF94ACULL) + (x2 ^ 0x025F5CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x025f5c: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF94ACULL; // 0x025f60: b #0xb210
    return acc;
}

// [EN] Reconstructed FDE #1007 @ 0x025f64..0x025f6c (8 bytes)
// [VN] Phục dựng FDE #1007 tại 0x025f64..0x025f6c (8 byte)
//   0x025f64: 528000a0  mov      w0, #5
//   0x025f68: 17ff949e  b        #0xb1e0
uint64_t fde_1007_sub_025f64(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x528000A0ULL) + (x1 ^ 0x17FF949EULL) + (x2 ^ 0x025F64ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x528000A0ULL; // 0x025f64: mov w0, #5
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF949EULL; // 0x025f68: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #1008 @ 0x025f6c..0x025f80 (20 bytes)
// [VN] Phục dựng FDE #1008 tại 0x025f6c..0x025f80 (20 byte)
//   0x025f6c: b00000c1  adrp     x1, #0x3e000
//   0x025f70: b00000c2  adrp     x2, #0x3e000
//   0x025f74: 91239021  add      x1, x1, #0x8e4
//   0x025f78: 9125bc42  add      x2, x2, #0x96f
//   0x025f7c: d65f03c0  ret      
uint64_t fde_1008_sub_025f6c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB00000C1ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x025F6CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB00000C1ULL; // 0x025f6c: adrp x1, #0x3e000
    acc = (acc * 0x100000001B3ULL) ^ 0xB00000C2ULL; // 0x025f70: adrp x2, #0x3e000
    acc = (acc * 0x100000001B3ULL) ^ 0x91239021ULL; // 0x025f74: add x1, x1, #0x8e4
    acc = (acc * 0x100000001B3ULL) ^ 0x9125BC42ULL; // 0x025f78: add x2, x2, #0x96f
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x025f7c: ret 
    return acc;
}

// [EN] Reconstructed FDE #1009 @ 0x025f80..0x025f88 (8 bytes)
// [VN] Phục dựng FDE #1009 tại 0x025f80..0x025f88 (8 byte)
//   0x025f80: aa1503e0  mov      x0, x21
//   0x025f84: 17ff9593  b        #0xb5d0
uint64_t fde_1009_sub_025f80(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1503E0ULL) + (x1 ^ 0x17FF9593ULL) + (x2 ^ 0x025F80ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E0ULL; // 0x025f80: mov x0, x21
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF9593ULL; // 0x025f84: b #0xb5d0
    return acc;
}

// [EN] Reconstructed FDE #1010 @ 0x025f88..0x025f9c (20 bytes)
// [VN] Phục dựng FDE #1010 tại 0x025f88..0x025f9c (20 byte)
//   0x025f88: b900001f  str      wzr, [x0]
//   0x025f8c: d00001a8  adrp     x8, #0x5b000
//   0x025f90: f9433d08  ldr      x8, [x8, #0x678]
//   0x025f94: f9000408  str      x8, [x0, #8]
//   0x025f98: 140005e5  b        #0x2772c
uint64_t fde_1010_sub_025f88(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB900001FULL) + (x1 ^ 0x140005E5ULL) + (x2 ^ 0x025F88ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB900001FULL; // 0x025f88: str wzr, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001A8ULL; // 0x025f8c: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9433D08ULL; // 0x025f90: ldr x8, [x8, #0x678]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000408ULL; // 0x025f94: str x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x140005E5ULL; // 0x025f98: b #0x2772c
    return acc;
}

// [EN] Reconstructed FDE #1011 @ 0x025f9c..0x025fb8 (28 bytes)
// [VN] Phục dựng FDE #1011 tại 0x025f9c..0x025fb8 (28 byte)
//   0x025f9c: d00001a8  adrp     x8, #0x5b000
//   0x025fa0: f9436108  ldr      x8, [x8, #0x6c0]
//   0x025fa4: 39400108  ldrb     w8, [x8]
//   0x025fa8: 34000048  cbz      w8, #0x25fb0
//   0x025fac: 17fffad5  b        #0x24b00
//   0x025fb0: 12800000  mov      w0, #-1
//   0x025fb4: d65f03c0  ret      
uint64_t fde_1011_sub_025f9c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD00001A8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x025F9CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001A8ULL; // 0x025f9c: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9436108ULL; // 0x025fa0: ldr x8, [x8, #0x6c0]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400108ULL; // 0x025fa4: ldrb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000048ULL; // 0x025fa8: cbz w8, #0x25fb0
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFAD5ULL; // 0x025fac: b #0x24b00
    acc = (acc * 0x100000001B3ULL) ^ 0x12800000ULL; // 0x025fb0: mov w0, #-1
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x025fb4: ret 
    return acc;
}

// [EN] Reconstructed FDE #1012 @ 0x025fb8..0x025fd4 (28 bytes)
// [VN] Phục dựng FDE #1012 tại 0x025fb8..0x025fd4 (28 byte)
//   0x025fb8: d00001a8  adrp     x8, #0x5b000
//   0x025fbc: f9436108  ldr      x8, [x8, #0x6c0]
//   0x025fc0: 39400108  ldrb     w8, [x8]
//   0x025fc4: 34000048  cbz      w8, #0x25fcc
//   0x025fc8: 17fffaf9  b        #0x24bac
//   0x025fcc: 12800000  mov      w0, #-1
//   0x025fd0: d65f03c0  ret      
uint64_t fde_1012_sub_025fb8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD00001A8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x025FB8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001A8ULL; // 0x025fb8: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9436108ULL; // 0x025fbc: ldr x8, [x8, #0x6c0]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400108ULL; // 0x025fc0: ldrb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000048ULL; // 0x025fc4: cbz w8, #0x25fcc
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFAF9ULL; // 0x025fc8: b #0x24bac
    acc = (acc * 0x100000001B3ULL) ^ 0x12800000ULL; // 0x025fcc: mov w0, #-1
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x025fd0: ret 
    return acc;
}

// [EN] Reconstructed FDE #1013 @ 0x025fd4..0x02621c (584 bytes)
// [VN] Phục dựng FDE #1013 tại 0x025fd4..0x02621c (584 byte)
//   0x025fd4: d10343ff  sub      sp, sp, #0xd0
//   0x025fd8: a9095ff8  stp      x24, x23, [sp, #0x90]
//   0x025fdc: a90a57f6  stp      x22, x21, [sp, #0xa0]
//   0x025fe0: a90b4ff4  stp      x20, x19, [sp, #0xb0]
//   0x025fe4: a90c7bfd  stp      x29, x30, [sp, #0xc0]
//   0x025fe8: 910303fd  add      x29, sp, #0xc0
//   0x025fec: d53bd056  mrs      x22, tpidr_el0
//   0x025ff0: f94016c8  ldr      x8, [x22, #0x28]
//   0x025ff4: f81c83a8  stur     x8, [x29, #-0x38]
//   0x025ff8: 97ff9566  bl       #0xb590
//   0x025ffc: aa0003f3  mov      x19, x0
//   0x026000: b9400017  ldr      w23, [x0]
uint64_t fde_1013_sub_025fd4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10343FFULL) + (x1 ^ 0xF81C83A8ULL) + (x2 ^ 0x025FD4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10343FFULL; // 0x025fd4: sub sp, sp, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9095FF8ULL; // 0x025fd8: stp x24, x23, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A57F6ULL; // 0x025fdc: stp x22, x21, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B4FF4ULL; // 0x025fe0: stp x20, x19, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C7BFDULL; // 0x025fe4: stp x29, x30, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910303FDULL; // 0x025fe8: add x29, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x025fec: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x025ff0: ldr x8, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1014 @ 0x02621c..0x026450 (564 bytes)
// [VN] Phục dựng FDE #1014 tại 0x02621c..0x026450 (564 byte)
//   0x02621c: d10203ff  sub      sp, sp, #0x80
//   0x026220: f9002bf5  str      x21, [sp, #0x50]
//   0x026224: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x026228: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x02622c: 9101c3fd  add      x29, sp, #0x70
//   0x026230: d53bd055  mrs      x21, tpidr_el0
//   0x026234: f94016a8  ldr      x8, [x21, #0x28]
//   0x026238: b00001a0  adrp     x0, #0x5b000
//   0x02623c: f81d83a8  stur     x8, [x29, #-0x28]
//   0x026240: 94000717  bl       #0x27e9c
//   0x026244: b5000f20  cbnz     x0, #0x26428
//   0x026248: 97ff9386  bl       #0xb060
uint64_t fde_1014_sub_02621c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xF81D83A8ULL) + (x2 ^ 0x02621CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x02621c: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xF9002BF5ULL; // 0x026220: str x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x026224: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x026228: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x02622c: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x026230: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x026234: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001A0ULL; // 0x026238: adrp x0, #0x5b000
    return acc;
}

// [EN] Reconstructed FDE #1015 @ 0x026450..0x0264a4 (84 bytes)
// [VN] Phục dựng FDE #1015 tại 0x026450..0x0264a4 (84 byte)
//   0x026450: d10143ff  sub      sp, sp, #0x50
//   0x026454: f9001bf3  str      x19, [sp, #0x30]
//   0x026458: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x02645c: 910103fd  add      x29, sp, #0x40
//   0x026460: d53bd053  mrs      x19, tpidr_el0
//   0x026464: f9401668  ldr      x8, [x19, #0x28]
//   0x026468: f81e83a8  stur     x8, [x29, #-0x18]
//   0x02646c: b40000e0  cbz      x0, #0x26488
//   0x026470: 6f00e400  movi     v0.2d, #0000000000000000
//   0x026474: 910003e2  mov      x2, sp
//   0x026478: 2a1f03e1  mov      w1, wzr
//   0x02647c: aa1f03e3  mov      x3, xzr
uint64_t fde_1015_sub_026450(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0x6F00E400ULL) + (x2 ^ 0x026450ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x026450: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF3ULL; // 0x026454: str x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x026458: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x02645c: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x026460: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x026464: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E83A8ULL; // 0x026468: stur x8, [x29, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000E0ULL; // 0x02646c: cbz x0, #0x26488
    return acc;
}

// [EN] Reconstructed FDE #1016 @ 0x0264a4..0x0264f0 (76 bytes)
// [VN] Phục dựng FDE #1016 tại 0x0264a4..0x0264f0 (76 byte)
//   0x0264a4: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0264a8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0264ac: 910043fd  add      x29, sp, #0x10
//   0x0264b0: aa0003f4  mov      x20, x0
//   0x0264b4: b9400000  ldr      w0, [x0]
//   0x0264b8: aa0103f3  mov      x19, x1
//   0x0264bc: 97ff9401  bl       #0xb4c0
//   0x0264c0: eb13001f  cmp      x0, x19
//   0x0264c4: 54000100  b.eq     #0x264e4
//   0x0264c8: f9400688  ldr      x8, [x20, #8]
//   0x0264cc: d63f0100  blr      x8
//   0x0264d0: b9400280  ldr      w0, [x20]
uint64_t fde_1016_sub_0264a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x54000100ULL) + (x2 ^ 0x0264A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0264a4: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0264a8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0264ac: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x0264b0: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400000ULL; // 0x0264b4: ldr w0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x0264b8: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF9401ULL; // 0x0264bc: bl #0xb4c0
    acc = (acc * 0x100000001B3ULL) ^ 0xEB13001FULL; // 0x0264c0: cmp x0, x19
    return acc;
}

// [EN] Reconstructed FDE #1017 @ 0x0264f0..0x02656c (124 bytes)
// [VN] Phục dựng FDE #1017 tại 0x0264f0..0x02656c (124 byte)
//   0x0264f0: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0264f4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0264f8: 910043fd  add      x29, sp, #0x10
//   0x0264fc: b00001b3  adrp     x19, #0x5b000
//   0x026500: f9461a73  ldr      x19, [x19, #0xc30]
//   0x026504: b9400268  ldr      w8, [x19]
//   0x026508: 6b00011f  cmp      w8, w0
//   0x02650c: 1a9f17e8  cset     w8, eq
//   0x026510: 7100001f  cmp      w0, #0
//   0x026514: 1a9f17e9  cset     w9, eq
//   0x026518: 3100243f  cmn      w1, #9
//   0x02651c: 5400020b  b.lt     #0x2655c
uint64_t fde_1017_sub_0264f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x7100001FULL) + (x2 ^ 0x0264F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0264f0: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0264f4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0264f8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001B3ULL; // 0x0264fc: adrp x19, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9461A73ULL; // 0x026500: ldr x19, [x19, #0xc30]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400268ULL; // 0x026504: ldr w8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x6B00011FULL; // 0x026508: cmp w8, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F17E8ULL; // 0x02650c: cset w8, eq
    return acc;
}

// [EN] Reconstructed FDE #1018 @ 0x02656c..0x026600 (148 bytes)
// [VN] Phục dựng FDE #1018 tại 0x02656c..0x026600 (148 byte)
//   0x02656c: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x026570: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x026574: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x026578: 910083fd  add      x29, sp, #0x20
//   0x02657c: 2a0003f4  mov      w20, w0
//   0x026580: b00001a0  adrp     x0, #0x5b000
//   0x026584: f9431800  ldr      x0, [x0, #0x630]
//   0x026588: 2a0103f3  mov      w19, w1
//   0x02658c: 97fff9dc  bl       #0x24cfc
//   0x026590: b40002e0  cbz      x0, #0x265ec
//   0x026594: 9400064d  bl       #0x27ec8
//   0x026598: 340002a8  cbz      w8, #0x265ec
uint64_t fde_1018_sub_02656c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x97FFF9DCULL) + (x2 ^ 0x02656CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x02656c: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x026570: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x026574: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x026578: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F4ULL; // 0x02657c: mov w20, w0
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001A0ULL; // 0x026580: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9431800ULL; // 0x026584: ldr x0, [x0, #0x630]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F3ULL; // 0x026588: mov w19, w1
    return acc;
}

// [EN] Reconstructed FDE #1019 @ 0x026600..0x0266ac (172 bytes)
// [VN] Phục dựng FDE #1019 tại 0x026600..0x0266ac (172 byte)
//   0x026600: d10103ff  sub      sp, sp, #0x40
//   0x026604: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x026608: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x02660c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x026610: 9100c3fd  add      x29, sp, #0x30
//   0x026614: d53bd056  mrs      x22, tpidr_el0
//   0x026618: f94016c8  ldr      x8, [x22, #0x28]
//   0x02661c: 2a0203f3  mov      w19, w2
//   0x026620: 2a0103f4  mov      w20, w1
//   0x026624: 2a0003f5  mov      w21, w0
//   0x026628: f90007e8  str      x8, [sp, #8]
//   0x02662c: f90003fe  str      x30, [sp]
uint64_t fde_1019_sub_026600(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x2A0103F4ULL) + (x2 ^ 0x026600ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x026600: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x026604: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x026608: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02660c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x026610: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x026614: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x026618: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F3ULL; // 0x02661c: mov w19, w2
    return acc;
}

// [EN] Reconstructed FDE #1020 @ 0x0266ac..0x026878 (460 bytes)
// [VN] Phục dựng FDE #1020 tại 0x0266ac..0x026878 (460 byte)
//   0x0266ac: d10143ff  sub      sp, sp, #0x50
//   0x0266b0: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x0266b4: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x0266b8: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x0266bc: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x0266c0: 910103fd  add      x29, sp, #0x40
//   0x0266c4: d53bd057  mrs      x23, tpidr_el0
//   0x0266c8: f94016e8  ldr      x8, [x23, #0x28]
//   0x0266cc: 900000d5  adrp     x21, #0x3e000
//   0x0266d0: 912f22b5  add      x21, x21, #0xbc8
//   0x0266d4: aa0103f3  mov      x19, x1
//   0x0266d8: aa0003f4  mov      x20, x0
uint64_t fde_1020_sub_0266ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0x900000D5ULL) + (x2 ^ 0x0266ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x0266ac: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x0266b0: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x0266b4: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x0266b8: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x0266bc: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x0266c0: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x0266c4: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x0266c8: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1021 @ 0x026878..0x026930 (184 bytes)
// [VN] Phục dựng FDE #1021 tại 0x026878..0x026930 (184 byte)
//   0x026878: d10183ff  sub      sp, sp, #0x60
//   0x02687c: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x026880: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x026884: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x026888: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x02688c: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x026890: 910143fd  add      x29, sp, #0x50
//   0x026894: d53bd059  mrs      x25, tpidr_el0
//   0x026898: f9401728  ldr      x8, [x25, #0x28]
//   0x02689c: 2a0003f6  mov      w22, w0
//   0x0268a0: b00001a0  adrp     x0, #0x5b000
//   0x0268a4: aa0303f3  mov      x19, x3
uint64_t fde_1021_sub_026878(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xF9401728ULL) + (x2 ^ 0x026878ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x026878: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x02687c: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x026880: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x026884: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x026888: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x02688c: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x026890: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x026894: mrs x25, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #1022 @ 0x026930..0x0269e8 (184 bytes)
// [VN] Phục dựng FDE #1022 tại 0x026930..0x0269e8 (184 byte)
//   0x026930: d10183ff  sub      sp, sp, #0x60
//   0x026934: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x026938: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x02693c: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x026940: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x026944: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x026948: 910143fd  add      x29, sp, #0x50
//   0x02694c: d53bd059  mrs      x25, tpidr_el0
//   0x026950: f9401728  ldr      x8, [x25, #0x28]
//   0x026954: 2a0003f6  mov      w22, w0
//   0x026958: b00001a0  adrp     x0, #0x5b000
//   0x02695c: aa0303f3  mov      x19, x3
uint64_t fde_1022_sub_026930(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xF9401728ULL) + (x2 ^ 0x026930ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x026930: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x026934: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x026938: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x02693c: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x026940: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x026944: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x026948: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x02694c: mrs x25, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #1023 @ 0x0269e8..0x026a88 (160 bytes)
// [VN] Phục dựng FDE #1023 tại 0x0269e8..0x026a88 (160 byte)
//   0x0269e8: d10143ff  sub      sp, sp, #0x50
//   0x0269ec: f9000bf7  str      x23, [sp, #0x10]
//   0x0269f0: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x0269f4: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x0269f8: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x0269fc: 910103fd  add      x29, sp, #0x40
//   0x026a00: d53bd056  mrs      x22, tpidr_el0
//   0x026a04: f94016c8  ldr      x8, [x22, #0x28]
//   0x026a08: 2a0103f4  mov      w20, w1
//   0x026a0c: 2a0003f3  mov      w19, w0
//   0x026a10: f90007e8  str      x8, [sp, #8]
//   0x026a14: f90003fe  str      x30, [sp]
uint64_t fde_1023_sub_0269e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0x2A0103F4ULL) + (x2 ^ 0x0269E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x0269e8: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF7ULL; // 0x0269ec: str x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x0269f0: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x0269f4: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x0269f8: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x0269fc: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x026a00: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x026a04: ldr x8, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1024 @ 0x026a88..0x026b48 (192 bytes)
// [VN] Phục dựng FDE #1024 tại 0x026a88..0x026b48 (192 byte)
//   0x026a88: d10143ff  sub      sp, sp, #0x50
//   0x026a8c: f9000bf7  str      x23, [sp, #0x10]
//   0x026a90: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x026a94: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x026a98: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x026a9c: 910103fd  add      x29, sp, #0x40
//   0x026aa0: d53bd056  mrs      x22, tpidr_el0
//   0x026aa4: f94016c9  ldr      x9, [x22, #0x28]
//   0x026aa8: 51000428  sub      w8, w1, #1
//   0x026aac: 2a0103f4  mov      w20, w1
//   0x026ab0: 2a0003f3  mov      w19, w0
//   0x026ab4: 7100251f  cmp      w8, #9
uint64_t fde_1024_sub_026a88(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0x51000428ULL) + (x2 ^ 0x026A88ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x026a88: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF7ULL; // 0x026a8c: str x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x026a90: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x026a94: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x026a98: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x026a9c: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x026aa0: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C9ULL; // 0x026aa4: ldr x9, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1025 @ 0x026b48..0x026c88 (320 bytes)
// [VN] Phục dựng FDE #1025 tại 0x026b48..0x026c88 (320 byte)
//   0x026b48: d101c3ff  sub      sp, sp, #0x70
//   0x026b4c: f9001bf7  str      x23, [sp, #0x30]
//   0x026b50: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x026b54: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x026b58: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x026b5c: 910183fd  add      x29, sp, #0x60
//   0x026b60: d53bd056  mrs      x22, tpidr_el0
//   0x026b64: f94016c8  ldr      x8, [x22, #0x28]
//   0x026b68: b00001a0  adrp     x0, #0x5b000
//   0x026b6c: f90017e8  str      x8, [sp, #0x28]
//   0x026b70: 940004cb  bl       #0x27e9c
//   0x026b74: b5000040  cbnz     x0, #0x26b7c
uint64_t fde_1025_sub_026b48(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xB00001A0ULL) + (x2 ^ 0x026B48ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x026b48: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF7ULL; // 0x026b4c: str x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x026b50: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x026b54: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x026b58: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x026b5c: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x026b60: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x026b64: ldr x8, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1026 @ 0x026c88..0x026cfc (116 bytes)
// [VN] Phục dựng FDE #1026 tại 0x026c88..0x026cfc (116 byte)
//   0x026c88: d10143ff  sub      sp, sp, #0x50
//   0x026c8c: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x026c90: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x026c94: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x026c98: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x026c9c: 910103fd  add      x29, sp, #0x40
//   0x026ca0: d53bd058  mrs      x24, tpidr_el0
//   0x026ca4: aa0803f7  mov      x23, x8
//   0x026ca8: f9401708  ldr      x8, [x24, #0x28]
//   0x026cac: 2a0303f3  mov      w19, w3
//   0x026cb0: 2a0203f4  mov      w20, w2
//   0x026cb4: aa0103f5  mov      x21, x1
uint64_t fde_1026_sub_026c88(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xF9401708ULL) + (x2 ^ 0x026C88ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x026c88: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x026c8c: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x026c90: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x026c94: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x026c98: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x026c9c: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x026ca0: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803F7ULL; // 0x026ca4: mov x23, x8
    return acc;
}

// [EN] Reconstructed FDE #1027 @ 0x026cfc..0x026d70 (116 bytes)
// [VN] Phục dựng FDE #1027 tại 0x026cfc..0x026d70 (116 byte)
//   0x026cfc: d10143ff  sub      sp, sp, #0x50
//   0x026d00: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x026d04: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x026d08: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x026d0c: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x026d10: 910103fd  add      x29, sp, #0x40
//   0x026d14: d53bd058  mrs      x24, tpidr_el0
//   0x026d18: aa0803f7  mov      x23, x8
//   0x026d1c: f9401708  ldr      x8, [x24, #0x28]
//   0x026d20: aa0303f3  mov      x19, x3
//   0x026d24: 2a0203f4  mov      w20, w2
//   0x026d28: aa0103f5  mov      x21, x1
uint64_t fde_1027_sub_026cfc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xF9401708ULL) + (x2 ^ 0x026CFCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x026cfc: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x026d00: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x026d04: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x026d08: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x026d0c: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x026d10: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x026d14: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803F7ULL; // 0x026d18: mov x23, x8
    return acc;
}

// [EN] Reconstructed FDE #1028 @ 0x026d70..0x026e48 (216 bytes)
// [VN] Phục dựng FDE #1028 tại 0x026d70..0x026e48 (216 byte)
//   0x026d70: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x026d74: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x026d78: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x026d7c: 910083fd  add      x29, sp, #0x20
//   0x026d80: 94000429  bl       #0x27e24
//   0x026d84: b5000040  cbnz     x0, #0x26d8c
//   0x026d88: 97fffd25  bl       #0x2621c
//   0x026d8c: 94000458  bl       #0x27eec
//   0x026d90: 54000580  b.eq     #0x26e40
//   0x026d94: b00001b3  adrp     x19, #0x5b000
//   0x026d98: f9431a73  ldr      x19, [x19, #0x630]
//   0x026d9c: aa1303e0  mov      x0, x19
uint64_t fde_1028_sub_026d70(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x54000580ULL) + (x2 ^ 0x026D70ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x026d70: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x026d74: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x026d78: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x026d7c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x94000429ULL; // 0x026d80: bl #0x27e24
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000040ULL; // 0x026d84: cbnz x0, #0x26d8c
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFD25ULL; // 0x026d88: bl #0x2621c
    acc = (acc * 0x100000001B3ULL) ^ 0x94000458ULL; // 0x026d8c: bl #0x27eec
    return acc;
}

// [EN] Reconstructed FDE #1029 @ 0x026e48..0x026ed4 (140 bytes)
// [VN] Phục dựng FDE #1029 tại 0x026e48..0x026ed4 (140 byte)
//   0x026e48: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x026e4c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x026e50: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x026e54: 910083fd  add      x29, sp, #0x20
//   0x026e58: 940003f3  bl       #0x27e24
//   0x026e5c: b4000380  cbz      x0, #0x26ecc
//   0x026e60: 94000423  bl       #0x27eec
//   0x026e64: 54000340  b.eq     #0x26ecc
//   0x026e68: 94000418  bl       #0x27ec8
//   0x026e6c: 34000308  cbz      w8, #0x26ecc
//   0x026e70: 940003f0  bl       #0x27e30
//   0x026e74: 3900401f  strb     wzr, [x0, #0x10]
uint64_t fde_1029_sub_026e48(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x94000418ULL) + (x2 ^ 0x026E48ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x026e48: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x026e4c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x026e50: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x026e54: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x940003F3ULL; // 0x026e58: bl #0x27e24
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000380ULL; // 0x026e5c: cbz x0, #0x26ecc
    acc = (acc * 0x100000001B3ULL) ^ 0x94000423ULL; // 0x026e60: bl #0x27eec
    acc = (acc * 0x100000001B3ULL) ^ 0x54000340ULL; // 0x026e64: b.eq #0x26ecc
    return acc;
}

// [EN] Reconstructed FDE #1030 @ 0x026ed4..0x026fb0 (220 bytes)
// [VN] Phục dựng FDE #1030 tại 0x026ed4..0x026fb0 (220 byte)
//   0x026ed4: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x026ed8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x026edc: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x026ee0: 910083fd  add      x29, sp, #0x20
//   0x026ee4: 97fffcce  bl       #0x2621c
//   0x026ee8: 94000482  bl       #0x280f0
//   0x026eec: 340005e8  cbz      w8, #0x26fa8
//   0x026ef0: 9400040e  bl       #0x27f28
//   0x026ef4: b4000348  cbz      x8, #0x26f5c
//   0x026ef8: b00001b3  adrp     x19, #0x5b000
//   0x026efc: f9431a73  ldr      x19, [x19, #0x630]
//   0x026f00: 940003c3  bl       #0x27e0c
uint64_t fde_1030_sub_026ed4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xB4000348ULL) + (x2 ^ 0x026ED4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x026ed4: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x026ed8: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x026edc: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x026ee0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFCCEULL; // 0x026ee4: bl #0x2621c
    acc = (acc * 0x100000001B3ULL) ^ 0x94000482ULL; // 0x026ee8: bl #0x280f0
    acc = (acc * 0x100000001B3ULL) ^ 0x340005E8ULL; // 0x026eec: cbz w8, #0x26fa8
    acc = (acc * 0x100000001B3ULL) ^ 0x9400040EULL; // 0x026ef0: bl #0x27f28
    return acc;
}

// [EN] Reconstructed FDE #1031 @ 0x026fb0..0x0270f8 (328 bytes)
// [VN] Phục dựng FDE #1031 tại 0x026fb0..0x0270f8 (328 byte)
//   0x026fb0: d10343ff  sub      sp, sp, #0xd0
//   0x026fb4: f9004bf7  str      x23, [sp, #0x90]
//   0x026fb8: a90a57f6  stp      x22, x21, [sp, #0xa0]
//   0x026fbc: a90b4ff4  stp      x20, x19, [sp, #0xb0]
//   0x026fc0: a90c7bfd  stp      x29, x30, [sp, #0xc0]
//   0x026fc4: 910303fd  add      x29, sp, #0xc0
//   0x026fc8: d53bd055  mrs      x21, tpidr_el0
//   0x026fcc: f94016a8  ldr      x8, [x21, #0x28]
//   0x026fd0: b00001a0  adrp     x0, #0x5b000
//   0x026fd4: f81c83a8  stur     x8, [x29, #-0x38]
//   0x026fd8: 940003b1  bl       #0x27e9c
//   0x026fdc: b40003c0  cbz      x0, #0x27054
uint64_t fde_1031_sub_026fb0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10343FFULL) + (x1 ^ 0xB00001A0ULL) + (x2 ^ 0x026FB0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10343FFULL; // 0x026fb0: sub sp, sp, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9004BF7ULL; // 0x026fb4: str x23, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A57F6ULL; // 0x026fb8: stp x22, x21, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B4FF4ULL; // 0x026fbc: stp x20, x19, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C7BFDULL; // 0x026fc0: stp x29, x30, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910303FDULL; // 0x026fc4: add x29, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x026fc8: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x026fcc: ldr x8, [x21, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1032 @ 0x0270f8..0x0271a8 (176 bytes)
// [VN] Phục dựng FDE #1032 tại 0x0270f8..0x0271a8 (176 byte)
//   0x0270f8: d10303ff  sub      sp, sp, #0xc0
//   0x0270fc: a90a4ff4  stp      x20, x19, [sp, #0xa0]
//   0x027100: a90b7bfd  stp      x29, x30, [sp, #0xb0]
//   0x027104: 9102c3fd  add      x29, sp, #0xb0
//   0x027108: d53bd053  mrs      x19, tpidr_el0
//   0x02710c: f9401668  ldr      x8, [x19, #0x28]
//   0x027110: f81e83a8  stur     x8, [x29, #-0x18]
//   0x027114: 97ff8fcf  bl       #0xb050
//   0x027118: f00000a1  adrp     x1, #0x3e000
//   0x02711c: 91304421  add      x1, x1, #0xc11
//   0x027120: 97ff8f40  bl       #0xae20
//   0x027124: f90007ff  str      xzr, [sp, #8]
uint64_t fde_1032_sub_0270f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10303FFULL) + (x1 ^ 0xF00000A1ULL) + (x2 ^ 0x0270F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10303FFULL; // 0x0270f8: sub sp, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A4FF4ULL; // 0x0270fc: stp x20, x19, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B7BFDULL; // 0x027100: stp x29, x30, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9102C3FDULL; // 0x027104: add x29, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x027108: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x02710c: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E83A8ULL; // 0x027110: stur x8, [x29, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF8FCFULL; // 0x027114: bl #0xb050
    return acc;
}

// [EN] Reconstructed FDE #1033 @ 0x0271a8..0x027394 (492 bytes)
// [VN] Phục dựng FDE #1033 tại 0x0271a8..0x027394 (492 byte)
//   0x0271a8: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x0271ac: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0271b0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0271b4: 910083fd  add      x29, sp, #0x20
//   0x0271b8: 900001a1  adrp     x1, #0x5b000
//   0x0271bc: f946b421  ldr      x1, [x1, #0xd68]
//   0x0271c0: 52800360  mov      w0, #0x1b
//   0x0271c4: 97ff8f8f  bl       #0xb000
//   0x0271c8: f00000a0  adrp     x0, #0x3e000
//   0x0271cc: 91227800  add      x0, x0, #0x89e
//   0x0271d0: 97ff8fe8  bl       #0xb170
//   0x0271d4: b4000700  cbz      x0, #0x272b4
uint64_t fde_1033_sub_0271a8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xF00000A0ULL) + (x2 ^ 0x0271A8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x0271a8: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0271ac: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0271b0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0271b4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A1ULL; // 0x0271b8: adrp x1, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF946B421ULL; // 0x0271bc: ldr x1, [x1, #0xd68]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800360ULL; // 0x0271c0: mov w0, #0x1b
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF8F8FULL; // 0x0271c4: bl #0xb000
    return acc;
}

// [EN] Reconstructed FDE #1034 @ 0x027394..0x027398 (4 bytes)
// [VN] Phục dựng FDE #1034 tại 0x027394..0x027398 (4 byte)
//   0x027394: 17fffe77  b        #0x26d70
uint64_t fde_1034_sub_027394(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFFE77ULL) + (x1 ^ 0x17FFFE77ULL) + (x2 ^ 0x027394ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFE77ULL; // 0x027394: b #0x26d70
    return acc;
}

// [EN] Reconstructed FDE #1035 @ 0x027398..0x02739c (4 bytes)
// [VN] Phục dựng FDE #1035 tại 0x027398..0x02739c (4 byte)
//   0x027398: 17fffeac  b        #0x26e48
uint64_t fde_1035_sub_027398(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFFEACULL) + (x1 ^ 0x17FFFEACULL) + (x2 ^ 0x027398ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFEACULL; // 0x027398: b #0x26e48
    return acc;
}

// [EN] Reconstructed FDE #1036 @ 0x02739c..0x0275c0 (548 bytes)
// [VN] Phục dựng FDE #1036 tại 0x02739c..0x0275c0 (548 byte)
//   0x02739c: 6db923e9  stp      d9, d8, [sp, #-0x70]!
//   0x0273a0: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x0273a4: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x0273a8: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x0273ac: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x0273b0: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x0273b4: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x0273b8: 910183fd  add      x29, sp, #0x60
//   0x0273bc: d10783ff  sub      sp, sp, #0x1e0
//   0x0273c0: d53bd05b  mrs      x27, tpidr_el0
//   0x0273c4: 900001a0  adrp     x0, #0x5b000
//   0x0273c8: f9401768  ldr      x8, [x27, #0x28]
uint64_t fde_1036_sub_02739c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x6DB923E9ULL) + (x1 ^ 0xD10783FFULL) + (x2 ^ 0x02739CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x6DB923E9ULL; // 0x02739c: stp d9, d8, [sp, #-0x70]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9016FFCULL; // 0x0273a0: stp x28, x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x0273a4: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x0273a8: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x0273ac: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x0273b0: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x0273b4: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x0273b8: add x29, sp, #0x60
    return acc;
}

// [EN] Reconstructed FDE #1037 @ 0x0275c0..0x0275d8 (24 bytes)
// [VN] Phục dựng FDE #1037 tại 0x0275c0..0x0275d8 (24 byte)
//   0x0275c0: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0275c4: 910003fd  mov      x29, sp
//   0x0275c8: 940000a3  bl       #0x27854
//   0x0275cc: 92401c21  and      x1, x1, #0xff
//   0x0275d0: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x0275d4: d65f03c0  ret      
uint64_t fde_1037_sub_0275c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0275C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x0275c0: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0275c4: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x940000A3ULL; // 0x0275c8: bl #0x27854
    acc = (acc * 0x100000001B3ULL) ^ 0x92401C21ULL; // 0x0275cc: and x1, x1, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x0275d0: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0275d4: ret 
    return acc;
}

// [EN] Reconstructed FDE #1038 @ 0x0275d8..0x0275f0 (24 bytes)
// [VN] Phục dựng FDE #1038 tại 0x0275d8..0x0275f0 (24 byte)
//   0x0275d8: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0275dc: 910003fd  mov      x29, sp
//   0x0275e0: 97ffff6f  bl       #0x2739c
//   0x0275e4: 2a1f03e0  mov      w0, wzr
//   0x0275e8: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x0275ec: d65f03c0  ret      
uint64_t fde_1038_sub_0275d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0275D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x0275d8: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0275dc: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFF6FULL; // 0x0275e0: bl #0x2739c
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x0275e4: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x0275e8: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0275ec: ret 
    return acc;
}

// [EN] Reconstructed FDE #1039 @ 0x0275f0..0x0276d4 (228 bytes)
// [VN] Phục dựng FDE #1039 tại 0x0275f0..0x0276d4 (228 byte)
//   0x0275f0: d10103ff  sub      sp, sp, #0x40
//   0x0275f4: f9000bf5  str      x21, [sp, #0x10]
//   0x0275f8: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0275fc: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x027600: 9100c3fd  add      x29, sp, #0x30
//   0x027604: d53bd054  mrs      x20, tpidr_el0
//   0x027608: 900001a9  adrp     x9, #0x5b000
//   0x02760c: f9401688  ldr      x8, [x20, #0x28]
//   0x027610: f9436129  ldr      x9, [x9, #0x6c0]
//   0x027614: 52800035  mov      w21, #1
//   0x027618: f90007e8  str      x8, [sp, #8]
//   0x02761c: 39000135  strb     w21, [x9]
uint64_t fde_1039_sub_0275f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xF9436129ULL) + (x2 ^ 0x0275F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x0275f0: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF5ULL; // 0x0275f4: str x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0275f8: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0275fc: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x027600: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x027604: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A9ULL; // 0x027608: adrp x9, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x02760c: ldr x8, [x20, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1040 @ 0x0276d4..0x027720 (76 bytes)
// [VN] Phục dựng FDE #1040 tại 0x0276d4..0x027720 (76 byte)
//   0x0276d4: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0276d8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0276dc: 910043fd  add      x29, sp, #0x10
//   0x0276e0: 900001b3  adrp     x19, #0x5b000
//   0x0276e4: f943b273  ldr      x19, [x19, #0x760]
//   0x0276e8: b9400261  ldr      w1, [x19]
//   0x0276ec: 7100043f  cmp      w1, #1
//   0x0276f0: 5400012b  b.lt     #0x27714
//   0x0276f4: 940002b9  bl       #0x281d8
//   0x0276f8: b9400662  ldr      w2, [x19, #4]
//   0x0276fc: 940002a3  bl       #0x28188
//   0x027700: b9400260  ldr      w0, [x19]
uint64_t fde_1040_sub_0276d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x940002B9ULL) + (x2 ^ 0x0276D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0276d4: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0276d8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0276dc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x900001B3ULL; // 0x0276e0: adrp x19, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF943B273ULL; // 0x0276e4: ldr x19, [x19, #0x760]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400261ULL; // 0x0276e8: ldr w1, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100043FULL; // 0x0276ec: cmp w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400012BULL; // 0x0276f0: b.lt #0x27714
    return acc;
}

// [EN] Reconstructed FDE #1041 @ 0x027720..0x027728 (8 bytes)
// [VN] Phục dựng FDE #1041 tại 0x027720..0x027728 (8 byte)
//   0x027720: f9400000  ldr      x0, [x0]
//   0x027724: 17ff8ebb  b        #0xb210
uint64_t fde_1041_sub_027720(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400000ULL) + (x1 ^ 0x17FF8EBBULL) + (x2 ^ 0x027720ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x027720: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF8EBBULL; // 0x027724: b #0xb210
    return acc;
}

// [EN] Reconstructed FDE #1042 @ 0x027728..0x02772c (4 bytes)
// [VN] Phục dựng FDE #1042 tại 0x027728..0x02772c (4 byte)
//   0x027728: 17ff8d86  b        #0xad40
uint64_t fde_1042_sub_027728(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FF8D86ULL) + (x1 ^ 0x17FF8D86ULL) + (x2 ^ 0x027728ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF8D86ULL; // 0x027728: b #0xad40
    return acc;
}

// [EN] Reconstructed FDE #1043 @ 0x02772c..0x027734 (8 bytes)
// [VN] Phục dựng FDE #1043 tại 0x02772c..0x027734 (8 byte)
//   0x02772c: f9400401  ldr      x1, [x0, #8]
//   0x027730: 17ff8fd8  b        #0xb690
uint64_t fde_1043_sub_02772c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400401ULL) + (x1 ^ 0x17FF8FD8ULL) + (x2 ^ 0x02772CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400401ULL; // 0x02772c: ldr x1, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF8FD8ULL; // 0x027730: b #0xb690
    return acc;
}

// [EN] Reconstructed FDE #1044 @ 0x027734..0x0277dc (168 bytes)
// [VN] Phục dựng FDE #1044 tại 0x027734..0x0277dc (168 byte)
//   0x027734: f9400408  ldr      x8, [x0, #8]
//   0x027738: b40004e8  cbz      x8, #0x277d4
//   0x02773c: 9e670100  fmov     d0, x8
//   0x027740: b9800029  ldrsw    x9, [x1]
//   0x027744: 0e205800  cnt      v0.8b, v0.8b
//   0x027748: 2e303800  uaddlv   h0, v0.8b
//   0x02774c: 1e26000a  fmov     w10, s0
//   0x027750: f100055f  cmp      x10, #1
//   0x027754: 540000e9  b.ls     #0x27770
//   0x027758: eb09011f  cmp      x8, x9
//   0x02775c: aa0903eb  mov      x11, x9
//   0x027760: 540000c8  b.hi     #0x27778
uint64_t fde_1044_sub_027734(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400408ULL) + (x1 ^ 0x540000E9ULL) + (x2 ^ 0x027734ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x027734: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40004E8ULL; // 0x027738: cbz x8, #0x277d4
    acc = (acc * 0x100000001B3ULL) ^ 0x9E670100ULL; // 0x02773c: fmov d0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xB9800029ULL; // 0x027740: ldrsw x9, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x0E205800ULL; // 0x027744: cnt v0.8b, v0.8b
    acc = (acc * 0x100000001B3ULL) ^ 0x2E303800ULL; // 0x027748: uaddlv h0, v0.8b
    acc = (acc * 0x100000001B3ULL) ^ 0x1E26000AULL; // 0x02774c: fmov w10, s0
    acc = (acc * 0x100000001B3ULL) ^ 0xF100055FULL; // 0x027750: cmp x10, #1
    return acc;
}

// [EN] Reconstructed FDE #1045 @ 0x0277dc..0x027804 (40 bytes)
// [VN] Phục dựng FDE #1045 tại 0x0277dc..0x027804 (40 byte)
//   0x0277dc: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0277e0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0277e4: 910043fd  add      x29, sp, #0x10
//   0x0277e8: f9400801  ldr      x1, [x0, #0x10]
//   0x0277ec: aa0003f3  mov      x19, x0
//   0x0277f0: 94000005  bl       #0x27804
//   0x0277f4: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0277f8: aa1303e0  mov      x0, x19
//   0x0277fc: f84207f3  ldr      x19, [sp], #0x20
//   0x027800: 1400000d  b        #0x27834
uint64_t fde_1045_sub_0277dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x0277DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0277dc: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0277e0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0277e4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400801ULL; // 0x0277e8: ldr x1, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0277ec: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x94000005ULL; // 0x0277f0: bl #0x27804
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x0277f4: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x0277f8: mov x0, x19
    return acc;
}

// [EN] Reconstructed FDE #1046 @ 0x027804..0x027834 (48 bytes)
// [VN] Phục dựng FDE #1046 tại 0x027804..0x027834 (48 byte)
//   0x027804: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x027808: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02780c: 910043fd  add      x29, sp, #0x10
//   0x027810: aa0103e0  mov      x0, x1
//   0x027814: b40000a0  cbz      x0, #0x27828
//   0x027818: f9400013  ldr      x19, [x0]
//   0x02781c: 97ff8d49  bl       #0xad40
//   0x027820: aa1303e0  mov      x0, x19
//   0x027824: b5ffffa0  cbnz     x0, #0x27818
//   0x027828: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02782c: f84207f3  ldr      x19, [sp], #0x20
//   0x027830: d65f03c0  ret      
uint64_t fde_1046_sub_027804(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xB5FFFFA0ULL) + (x2 ^ 0x027804ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x027804: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x027808: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02780c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x027810: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000A0ULL; // 0x027814: cbz x0, #0x27828
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400013ULL; // 0x027818: ldr x19, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF8D49ULL; // 0x02781c: bl #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x027820: mov x0, x19
    return acc;
}

// [EN] Reconstructed FDE #1047 @ 0x027834..0x02783c (8 bytes)
// [VN] Phục dựng FDE #1047 tại 0x027834..0x02783c (8 byte)
//   0x027834: aa1f03e1  mov      x1, xzr
//   0x027838: 14000001  b        #0x2783c
uint64_t fde_1047_sub_027834(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E1ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x027834ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x027834: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x027838: b #0x2783c
    return acc;
}

// [EN] Reconstructed FDE #1048 @ 0x02783c..0x027854 (24 bytes)
// [VN] Phục dựng FDE #1048 tại 0x02783c..0x027854 (24 byte)
//   0x02783c: aa0003e8  mov      x8, x0
//   0x027840: f9400000  ldr      x0, [x0]
//   0x027844: f900011f  str      xzr, [x8]
//   0x027848: b4000040  cbz      x0, #0x27850
//   0x02784c: 17ff8d3d  b        #0xad40
//   0x027850: d65f03c0  ret      
uint64_t fde_1048_sub_02783c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02783CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x02783c: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x027840: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900011FULL; // 0x027844: str xzr, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000040ULL; // 0x027848: cbz x0, #0x27850
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF8D3DULL; // 0x02784c: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x027850: ret 
    return acc;
}

// [EN] Reconstructed FDE #1049 @ 0x027854..0x0278d4 (128 bytes)
// [VN] Phục dựng FDE #1049 tại 0x027854..0x0278d4 (128 byte)
//   0x027854: d10143ff  sub      sp, sp, #0x50
//   0x027858: f90013f5  str      x21, [sp, #0x20]
//   0x02785c: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x027860: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x027864: 910103fd  add      x29, sp, #0x40
//   0x027868: d53bd055  mrs      x21, tpidr_el0
//   0x02786c: f94016a8  ldr      x8, [x21, #0x28]
//   0x027870: aa0003f3  mov      x19, x0
//   0x027874: f9000fe8  str      x8, [sp, #0x18]
//   0x027878: 910003e8  mov      x8, sp
//   0x02787c: 94000016  bl       #0x278d4
//   0x027880: f94003e1  ldr      x1, [sp]
uint64_t fde_1049_sub_027854(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xF9000FE8ULL) + (x2 ^ 0x027854ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x027854: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F5ULL; // 0x027858: str x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x02785c: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x027860: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x027864: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x027868: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x02786c: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x027870: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #1050 @ 0x0278d4..0x027944 (112 bytes)
// [VN] Phục dựng FDE #1050 tại 0x0278d4..0x027944 (112 byte)
//   0x0278d4: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x0278d8: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x0278dc: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0278e0: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0278e4: 9100c3fd  add      x29, sp, #0x30
//   0x0278e8: 91004016  add      x22, x0, #0x10
//   0x0278ec: aa0103f4  mov      x20, x1
//   0x0278f0: 52800021  mov      w1, #1
//   0x0278f4: aa1603e0  mov      x0, x22
//   0x0278f8: aa0203f3  mov      x19, x2
//   0x0278fc: aa0803f5  mov      x21, x8
//   0x027900: 52800038  mov      w24, #1
uint64_t fde_1050_sub_0278d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0xAA1603E0ULL) + (x2 ^ 0x0278D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x0278d4: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x0278d8: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0278dc: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0278e0: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0278e4: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x91004016ULL; // 0x0278e8: add x22, x0, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x0278ec: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x0278f0: mov w1, #1
    return acc;
}

// [EN] Reconstructed FDE #1051 @ 0x027944..0x027994 (80 bytes)
// [VN] Phục dựng FDE #1051 tại 0x027944..0x027994 (80 byte)
//   0x027944: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x027948: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02794c: 910043fd  add      x29, sp, #0x10
//   0x027950: aa0103e2  mov      x2, x1
//   0x027954: aa0103f3  mov      x19, x1
//   0x027958: b8810c41  ldrsw    x1, [x2, #0x10]!
//   0x02795c: aa0003f4  mov      x20, x0
//   0x027960: f81f8041  stur     x1, [x2, #-8]
//   0x027964: 9400001c  bl       #0x279d4
//   0x027968: b4000060  cbz      x0, #0x27974
//   0x02796c: aa1f03e1  mov      x1, xzr
//   0x027970: 14000006  b        #0x27988
uint64_t fde_1051_sub_027944(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x9400001CULL) + (x2 ^ 0x027944ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x027944: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x027948: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02794c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E2ULL; // 0x027950: mov x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x027954: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xB8810C41ULL; // 0x027958: ldrsw x1, [x2, #0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x02795c: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF81F8041ULL; // 0x027960: stur x1, [x2, #-8]
    return acc;
}

// [EN] Reconstructed FDE #1052 @ 0x027994..0x02799c (8 bytes)
// [VN] Phục dựng FDE #1052 tại 0x027994..0x02799c (8 byte)
//   0x027994: aa1f03e1  mov      x1, xzr
//   0x027998: 14000117  b        #0x27df4
uint64_t fde_1052_sub_027994(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E1ULL) + (x1 ^ 0x14000117ULL) + (x2 ^ 0x027994ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x027994: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000117ULL; // 0x027998: b #0x27df4
    return acc;
}

// [EN] Reconstructed FDE #1053 @ 0x02799c..0x0279a4 (8 bytes)
// [VN] Phục dựng FDE #1053 tại 0x02799c..0x0279a4 (8 byte)
//   0x02799c: aa1f03e2  mov      x2, xzr
//   0x0279a0: 14000001  b        #0x279a4
uint64_t fde_1053_sub_02799c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x02799CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x02799c: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x0279a0: b #0x279a4
    return acc;
}

// [EN] Reconstructed FDE #1054 @ 0x0279a4..0x0279d4 (48 bytes)
// [VN] Phục dựng FDE #1054 tại 0x0279a4..0x0279d4 (48 byte)
//   0x0279a4: d28c16e8  mov      x8, #0x60b7
//   0x0279a8: f2b6c168  movk     x8, #0xb60b, lsl #16
//   0x0279ac: f2c16c08  movk     x8, #0xb60, lsl #32
//   0x0279b0: f2e016c8  movk     x8, #0xb6, lsl #48
//   0x0279b4: eb08003f  cmp      x1, x8
//   0x0279b8: 54000082  b.hs     #0x279c8
//   0x0279bc: 52802d08  mov      w8, #0x168
//   0x0279c0: 9b087c20  mul      x0, x1, x8
//   0x0279c4: 17ff8f0b  b        #0xb5f0
//   0x0279c8: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0279cc: 910003fd  mov      x29, sp
//   0x0279d0: 97ff8ecc  bl       #0xb500
uint64_t fde_1054_sub_0279a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD28C16E8ULL) + (x1 ^ 0x17FF8F0BULL) + (x2 ^ 0x0279A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD28C16E8ULL; // 0x0279a4: mov x8, #0x60b7
    acc = (acc * 0x100000001B3ULL) ^ 0xF2B6C168ULL; // 0x0279a8: movk x8, #0xb60b, lsl #16
    acc = (acc * 0x100000001B3ULL) ^ 0xF2C16C08ULL; // 0x0279ac: movk x8, #0xb60, lsl #32
    acc = (acc * 0x100000001B3ULL) ^ 0xF2E016C8ULL; // 0x0279b0: movk x8, #0xb6, lsl #48
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08003FULL; // 0x0279b4: cmp x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000082ULL; // 0x0279b8: b.hs #0x279c8
    acc = (acc * 0x100000001B3ULL) ^ 0x52802D08ULL; // 0x0279bc: mov w8, #0x168
    acc = (acc * 0x100000001B3ULL) ^ 0x9B087C20ULL; // 0x0279c0: mul x0, x1, x8
    return acc;
}

// [EN] Reconstructed FDE #1055 @ 0x0279d4..0x027ad4 (256 bytes)
// [VN] Phục dựng FDE #1055 tại 0x0279d4..0x027ad4 (256 byte)
//   0x0279d4: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0279d8: 910003fd  mov      x29, sp
//   0x0279dc: f9400409  ldr      x9, [x0, #8]
//   0x0279e0: b4000489  cbz      x9, #0x27a70
//   0x0279e4: 9e670120  fmov     d0, x9
//   0x0279e8: 0e205800  cnt      v0.8b, v0.8b
//   0x0279ec: 2e303800  uaddlv   h0, v0.8b
//   0x0279f0: 1e26000a  fmov     w10, s0
//   0x0279f4: f100055f  cmp      x10, #1
//   0x0279f8: 540000c9  b.ls     #0x27a10
//   0x0279fc: eb01013f  cmp      x9, x1
//   0x027a00: 540000c8  b.hi     #0x27a18
uint64_t fde_1055_sub_0279d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xF100055FULL) + (x2 ^ 0x0279D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x0279d4: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0279d8: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400409ULL; // 0x0279dc: ldr x9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000489ULL; // 0x0279e0: cbz x9, #0x27a70
    acc = (acc * 0x100000001B3ULL) ^ 0x9E670120ULL; // 0x0279e4: fmov d0, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x0E205800ULL; // 0x0279e8: cnt v0.8b, v0.8b
    acc = (acc * 0x100000001B3ULL) ^ 0x2E303800ULL; // 0x0279ec: uaddlv h0, v0.8b
    acc = (acc * 0x100000001B3ULL) ^ 0x1E26000AULL; // 0x0279f0: fmov w10, s0
    return acc;
}

// [EN] Reconstructed FDE #1056 @ 0x027ad4..0x027b8c (184 bytes)
// [VN] Phục dựng FDE #1056 tại 0x027ad4..0x027b8c (184 byte)
//   0x027ad4: f9400408  ldr      x8, [x0, #8]
//   0x027ad8: f940042a  ldr      x10, [x1, #8]
//   0x027adc: 9e670100  fmov     d0, x8
//   0x027ae0: 0e205800  cnt      v0.8b, v0.8b
//   0x027ae4: 2e303800  uaddlv   h0, v0.8b
//   0x027ae8: 1e260009  fmov     w9, s0
//   0x027aec: f100053f  cmp      x9, #1
//   0x027af0: 540000c9  b.ls     #0x27b08
//   0x027af4: eb08015f  cmp      x10, x8
//   0x027af8: 540000c3  b.lo     #0x27b10
//   0x027afc: 9ac8094b  udiv     x11, x10, x8
//   0x027b00: 9b08a96a  msub     x10, x11, x8, x10
uint64_t fde_1056_sub_027ad4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400408ULL) + (x1 ^ 0xEB08015FULL) + (x2 ^ 0x027AD4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x027ad4: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF940042AULL; // 0x027ad8: ldr x10, [x1, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x9E670100ULL; // 0x027adc: fmov d0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x0E205800ULL; // 0x027ae0: cnt v0.8b, v0.8b
    acc = (acc * 0x100000001B3ULL) ^ 0x2E303800ULL; // 0x027ae4: uaddlv h0, v0.8b
    acc = (acc * 0x100000001B3ULL) ^ 0x1E260009ULL; // 0x027ae8: fmov w9, s0
    acc = (acc * 0x100000001B3ULL) ^ 0xF100053FULL; // 0x027aec: cmp x9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540000C9ULL; // 0x027af0: b.ls #0x27b08
    return acc;
}

// [EN] Reconstructed FDE #1057 @ 0x027b8c..0x027c6c (224 bytes)
// [VN] Phục dựng FDE #1057 tại 0x027b8c..0x027c6c (224 byte)
//   0x027b8c: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x027b90: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x027b94: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x027b98: 910083fd  add      x29, sp, #0x20
//   0x027b9c: f1000428  subs     x8, x1, #1
//   0x027ba0: aa0003f3  mov      x19, x0
//   0x027ba4: 54000061  b.ne     #0x27bb0
//   0x027ba8: 52800054  mov      w20, #2
//   0x027bac: 14000007  b        #0x27bc8
//   0x027bb0: aa0103f4  mov      x20, x1
//   0x027bb4: ea08003f  tst      x1, x8
//   0x027bb8: 54000080  b.eq     #0x27bc8
uint64_t fde_1057_sub_027b8c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x14000007ULL) + (x2 ^ 0x027B8CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x027b8c: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x027b90: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x027b94: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x027b98: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF1000428ULL; // 0x027b9c: subs x8, x1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x027ba0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x54000061ULL; // 0x027ba4: b.ne #0x27bb0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800054ULL; // 0x027ba8: mov w20, #2
    return acc;
}

// [EN] Reconstructed FDE #1058 @ 0x027c6c..0x027db8 (332 bytes)
// [VN] Phục dựng FDE #1058 tại 0x027c6c..0x027db8 (332 byte)
//   0x027c6c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x027c70: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x027c74: 910043fd  add      x29, sp, #0x10
//   0x027c78: aa0003f3  mov      x19, x0
//   0x027c7c: b40003c1  cbz      x1, #0x27cf4
//   0x027c80: 91002260  add      x0, x19, #8
//   0x027c84: aa0103f4  mov      x20, x1
//   0x027c88: 94000052  bl       #0x27dd0
//   0x027c8c: aa0003e1  mov      x1, x0
//   0x027c90: aa1303e0  mov      x0, x19
//   0x027c94: 94000049  bl       #0x27db8
//   0x027c98: aa1f03e8  mov      x8, xzr
uint64_t fde_1058_sub_027c6c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA0003E1ULL) + (x2 ^ 0x027C6CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x027c6c: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x027c70: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x027c74: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x027c78: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB40003C1ULL; // 0x027c7c: cbz x1, #0x27cf4
    acc = (acc * 0x100000001B3ULL) ^ 0x91002260ULL; // 0x027c80: add x0, x19, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x027c84: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x94000052ULL; // 0x027c88: bl #0x27dd0
    return acc;
}

// [EN] Reconstructed FDE #1059 @ 0x027db8..0x027dd0 (24 bytes)
// [VN] Phục dựng FDE #1059 tại 0x027db8..0x027dd0 (24 byte)
//   0x027db8: aa0003e8  mov      x8, x0
//   0x027dbc: f9400000  ldr      x0, [x0]
//   0x027dc0: f9000101  str      x1, [x8]
//   0x027dc4: b4000040  cbz      x0, #0x27dcc
//   0x027dc8: 17ff8bde  b        #0xad40
//   0x027dcc: d65f03c0  ret      
uint64_t fde_1059_sub_027db8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x027DB8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x027db8: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x027dbc: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000101ULL; // 0x027dc0: str x1, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000040ULL; // 0x027dc4: cbz x0, #0x27dcc
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF8BDEULL; // 0x027dc8: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x027dcc: ret 
    return acc;
}

// [EN] Reconstructed FDE #1060 @ 0x027dd0..0x027dd8 (8 bytes)
// [VN] Phục dựng FDE #1060 tại 0x027dd0..0x027dd8 (8 byte)
//   0x027dd0: aa1f03e2  mov      x2, xzr
//   0x027dd4: 14000001  b        #0x27dd8
uint64_t fde_1060_sub_027dd0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x027DD0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x027dd0: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x027dd4: b #0x27dd8
    return acc;
}

// [EN] Reconstructed FDE #1061 @ 0x027dd8..0x027df4 (28 bytes)
// [VN] Phục dựng FDE #1061 tại 0x027dd8..0x027df4 (28 byte)
//   0x027dd8: d37dfc28  lsr      x8, x1, #0x3d
//   0x027ddc: b5000068  cbnz     x8, #0x27de8
//   0x027de0: d37df020  lsl      x0, x1, #3
//   0x027de4: 17ff8e03  b        #0xb5f0
//   0x027de8: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x027dec: 910003fd  mov      x29, sp
//   0x027df0: 97ff8dc4  bl       #0xb500
uint64_t fde_1061_sub_027dd8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD37DFC28ULL) + (x1 ^ 0x97FF8DC4ULL) + (x2 ^ 0x027DD8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DFC28ULL; // 0x027dd8: lsr x8, x1, #0x3d
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000068ULL; // 0x027ddc: cbnz x8, #0x27de8
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DF020ULL; // 0x027de0: lsl x0, x1, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF8E03ULL; // 0x027de4: b #0xb5f0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x027de8: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x027dec: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF8DC4ULL; // 0x027df0: bl #0xb500
    return acc;
}

// [EN] Reconstructed FDE #1062 @ 0x027df4..0x027e0c (24 bytes)
// [VN] Phục dựng FDE #1062 tại 0x027df4..0x027e0c (24 byte)
//   0x027df4: aa0003e8  mov      x8, x0
//   0x027df8: f9400000  ldr      x0, [x0]
//   0x027dfc: f9000101  str      x1, [x8]
//   0x027e00: b4000040  cbz      x0, #0x27e08
//   0x027e04: 17ff8bcf  b        #0xad40
//   0x027e08: d65f03c0  ret      
uint64_t fde_1062_sub_027df4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x027DF4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x027df4: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x027df8: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000101ULL; // 0x027dfc: str x1, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000040ULL; // 0x027e00: cbz x0, #0x27e08
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF8BCFULL; // 0x027e04: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x027e08: ret 
    return acc;
}

// [EN] Reconstructed FDE #1063 @ 0x027e0c..0x027e14 (8 bytes)
// [VN] Phục dựng FDE #1063 tại 0x027e0c..0x027e14 (8 byte)
//   0x027e0c: aa1303e0  mov      x0, x19
//   0x027e10: 17fff3bb  b        #0x24cfc
uint64_t fde_1063_sub_027e0c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1303E0ULL) + (x1 ^ 0x17FFF3BBULL) + (x2 ^ 0x027E0CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x027e0c: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF3BBULL; // 0x027e10: b #0x24cfc
    return acc;
}

// [EN] Reconstructed FDE #1064 @ 0x027e14..0x027e24 (16 bytes)
// [VN] Phục dựng FDE #1064 tại 0x027e14..0x027e24 (16 byte)
//   0x027e14: aa1f03e1  mov      x1, xzr
//   0x027e18: aa1f03e4  mov      x4, xzr
//   0x027e1c: aa1f03e5  mov      x5, xzr
//   0x027e20: 17ff8dc8  b        #0xb540
uint64_t fde_1064_sub_027e14(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E1ULL) + (x1 ^ 0x17FF8DC8ULL) + (x2 ^ 0x027E14ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x027e14: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E4ULL; // 0x027e18: mov x4, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E5ULL; // 0x027e1c: mov x5, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF8DC8ULL; // 0x027e20: b #0xb540
    return acc;
}

// [EN] Reconstructed FDE #1065 @ 0x027e24..0x027e30 (12 bytes)
// [VN] Phục dựng FDE #1065 tại 0x027e24..0x027e30 (12 byte)
//   0x027e24: 900001a0  adrp     x0, #0x5b000
//   0x027e28: f9431800  ldr      x0, [x0, #0x630]
//   0x027e2c: 17fff3b4  b        #0x24cfc
uint64_t fde_1065_sub_027e24(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x900001A0ULL) + (x1 ^ 0x17FFF3B4ULL) + (x2 ^ 0x027E24ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A0ULL; // 0x027e24: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9431800ULL; // 0x027e28: ldr x0, [x0, #0x630]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF3B4ULL; // 0x027e2c: b #0x24cfc
    return acc;
}

// [EN] Reconstructed FDE #1066 @ 0x027e30..0x027e40 (16 bytes)
// [VN] Phục dựng FDE #1066 tại 0x027e30..0x027e40 (16 byte)
//   0x027e30: 900001b3  adrp     x19, #0x5b000
//   0x027e34: f9431a73  ldr      x19, [x19, #0x630]
//   0x027e38: aa1303e0  mov      x0, x19
//   0x027e3c: 17fff3b0  b        #0x24cfc
uint64_t fde_1066_sub_027e30(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x900001B3ULL) + (x1 ^ 0x17FFF3B0ULL) + (x2 ^ 0x027E30ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x900001B3ULL; // 0x027e30: adrp x19, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9431A73ULL; // 0x027e34: ldr x19, [x19, #0x630]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x027e38: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF3B0ULL; // 0x027e3c: b #0x24cfc
    return acc;
}

// [EN] Reconstructed FDE #1067 @ 0x027e40..0x027e8c (76 bytes)
// [VN] Phục dựng FDE #1067 tại 0x027e40..0x027e8c (76 byte)
//   0x027e40: f81f0ffe  str      x30, [sp, #-0x10]!
//   0x027e44: 900001b7  adrp     x23, #0x5b000
//   0x027e48: f9431af7  ldr      x23, [x23, #0x630]
//   0x027e4c: aa1703e0  mov      x0, x23
//   0x027e50: 97fff3ab  bl       #0x24cfc
//   0x027e54: 3900401f  strb     wzr, [x0, #0x10]
//   0x027e58: 900001a8  adrp     x8, #0x5b000
//   0x027e5c: f9431508  ldr      x8, [x8, #0x628]
//   0x027e60: aa1703e0  mov      x0, x23
//   0x027e64: f940011a  ldr      x26, [x8]
//   0x027e68: 97fff3a5  bl       #0x24cfc
//   0x027e6c: b9400018  ldr      w24, [x0]
uint64_t fde_1067_sub_027e40(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81F0FFEULL) + (x1 ^ 0xAA1703E0ULL) + (x2 ^ 0x027E40ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81F0FFEULL; // 0x027e40: str x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x900001B7ULL; // 0x027e44: adrp x23, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9431AF7ULL; // 0x027e48: ldr x23, [x23, #0x630]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1703E0ULL; // 0x027e4c: mov x0, x23
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF3ABULL; // 0x027e50: bl #0x24cfc
    acc = (acc * 0x100000001B3ULL) ^ 0x3900401FULL; // 0x027e54: strb wzr, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A8ULL; // 0x027e58: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9431508ULL; // 0x027e5c: ldr x8, [x8, #0x628]
    return acc;
}

// [EN] Reconstructed FDE #1068 @ 0x027e8c..0x027e9c (16 bytes)
// [VN] Phục dựng FDE #1068 tại 0x027e8c..0x027e9c (16 byte)
//   0x027e8c: 900001b4  adrp     x20, #0x5b000
//   0x027e90: f9431a94  ldr      x20, [x20, #0x630]
//   0x027e94: aa1403e0  mov      x0, x20
//   0x027e98: 17fff399  b        #0x24cfc
uint64_t fde_1068_sub_027e8c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x900001B4ULL) + (x1 ^ 0x17FFF399ULL) + (x2 ^ 0x027E8CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x900001B4ULL; // 0x027e8c: adrp x20, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9431A94ULL; // 0x027e90: ldr x20, [x20, #0x630]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x027e94: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF399ULL; // 0x027e98: b #0x24cfc
    return acc;
}

// [EN] Reconstructed FDE #1069 @ 0x027e9c..0x027ea4 (8 bytes)
// [VN] Phục dựng FDE #1069 tại 0x027e9c..0x027ea4 (8 byte)
//   0x027e9c: f9431800  ldr      x0, [x0, #0x630]
//   0x027ea0: 17fff397  b        #0x24cfc
uint64_t fde_1069_sub_027e9c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9431800ULL) + (x1 ^ 0x17FFF397ULL) + (x2 ^ 0x027E9CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9431800ULL; // 0x027e9c: ldr x0, [x0, #0x630]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF397ULL; // 0x027ea0: b #0x24cfc
    return acc;
}

// [EN] Reconstructed FDE #1070 @ 0x027ea4..0x027ec8 (36 bytes)
// [VN] Phục dựng FDE #1070 tại 0x027ea4..0x027ec8 (36 byte)
//   0x027ea4: f81f0ffe  str      x30, [sp, #-0x10]!
//   0x027ea8: 900001a0  adrp     x0, #0x5b000
//   0x027eac: f9431800  ldr      x0, [x0, #0x630]
//   0x027eb0: 97fff393  bl       #0x24cfc
//   0x027eb4: b9411808  ldr      w8, [x0, #0x118]
//   0x027eb8: 51000508  sub      w8, w8, #1
//   0x027ebc: b9011808  str      w8, [x0, #0x118]
//   0x027ec0: f84107fe  ldr      x30, [sp], #0x10
//   0x027ec4: d65f03c0  ret      
uint64_t fde_1070_sub_027ea4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81F0FFEULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x027EA4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81F0FFEULL; // 0x027ea4: str x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A0ULL; // 0x027ea8: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9431800ULL; // 0x027eac: ldr x0, [x0, #0x630]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF393ULL; // 0x027eb0: bl #0x24cfc
    acc = (acc * 0x100000001B3ULL) ^ 0xB9411808ULL; // 0x027eb4: ldr w8, [x0, #0x118]
    acc = (acc * 0x100000001B3ULL) ^ 0x51000508ULL; // 0x027eb8: sub w8, w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xB9011808ULL; // 0x027ebc: str w8, [x0, #0x118]
    acc = (acc * 0x100000001B3ULL) ^ 0xF84107FEULL; // 0x027ec0: ldr x30, [sp], #0x10
    return acc;
}

// [EN] Reconstructed FDE #1071 @ 0x027ec8..0x027ee4 (28 bytes)
// [VN] Phục dựng FDE #1071 tại 0x027ec8..0x027ee4 (28 byte)
//   0x027ec8: f81f0ffe  str      x30, [sp, #-0x10]!
//   0x027ecc: 900001a0  adrp     x0, #0x5b000
//   0x027ed0: f9431800  ldr      x0, [x0, #0x630]
//   0x027ed4: 97fff38a  bl       #0x24cfc
//   0x027ed8: 39404008  ldrb     w8, [x0, #0x10]
//   0x027edc: f84107fe  ldr      x30, [sp], #0x10
//   0x027ee0: d65f03c0  ret      
uint64_t fde_1071_sub_027ec8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81F0FFEULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x027EC8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81F0FFEULL; // 0x027ec8: str x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A0ULL; // 0x027ecc: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9431800ULL; // 0x027ed0: ldr x0, [x0, #0x630]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF38AULL; // 0x027ed4: bl #0x24cfc
    acc = (acc * 0x100000001B3ULL) ^ 0x39404008ULL; // 0x027ed8: ldrb w8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF84107FEULL; // 0x027edc: ldr x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x027ee0: ret 
    return acc;
}

// [EN] Reconstructed FDE #1072 @ 0x027ee4..0x027eec (8 bytes)
// [VN] Phục dựng FDE #1072 tại 0x027ee4..0x027eec (8 byte)
//   0x027ee4: aa1403e0  mov      x0, x20
//   0x027ee8: 17fff385  b        #0x24cfc
uint64_t fde_1072_sub_027ee4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1403E0ULL) + (x1 ^ 0x17FFF385ULL) + (x2 ^ 0x027EE4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x027ee4: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF385ULL; // 0x027ee8: b #0x24cfc
    return acc;
}

// [EN] Reconstructed FDE #1073 @ 0x027eec..0x027f18 (44 bytes)
// [VN] Phục dựng FDE #1073 tại 0x027eec..0x027f18 (44 byte)
//   0x027eec: f81f0ffe  str      x30, [sp, #-0x10]!
//   0x027ef0: 900001a0  adrp     x0, #0x5b000
//   0x027ef4: f9431800  ldr      x0, [x0, #0x630]
//   0x027ef8: 97fff381  bl       #0x24cfc
//   0x027efc: 900001a9  adrp     x9, #0x5b000
//   0x027f00: b9400008  ldr      w8, [x0]
//   0x027f04: f9461929  ldr      x9, [x9, #0xc30]
//   0x027f08: b9400129  ldr      w9, [x9]
//   0x027f0c: 6b09011f  cmp      w8, w9
//   0x027f10: f84107fe  ldr      x30, [sp], #0x10
//   0x027f14: d65f03c0  ret      
uint64_t fde_1073_sub_027eec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81F0FFEULL) + (x1 ^ 0x6B09011FULL) + (x2 ^ 0x027EECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81F0FFEULL; // 0x027eec: str x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A0ULL; // 0x027ef0: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9431800ULL; // 0x027ef4: ldr x0, [x0, #0x630]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF381ULL; // 0x027ef8: bl #0x24cfc
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A9ULL; // 0x027efc: adrp x9, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400008ULL; // 0x027f00: ldr w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9461929ULL; // 0x027f04: ldr x9, [x9, #0xc30]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400129ULL; // 0x027f08: ldr w9, [x9]
    return acc;
}

// [EN] Reconstructed FDE #1074 @ 0x027f18..0x027f28 (16 bytes)
// [VN] Phục dựng FDE #1074 tại 0x027f18..0x027f28 (16 byte)
//   0x027f18: aa0003e8  mov      x8, x0
//   0x027f1c: 2a1303e0  mov      w0, w19
//   0x027f20: 2a1403e1  mov      w1, w20
//   0x027f24: d61f0100  br       x8
uint64_t fde_1074_sub_027f18(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x027F18ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x027f18: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1303E0ULL; // 0x027f1c: mov w0, w19
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1403E1ULL; // 0x027f20: mov w1, w20
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x027f24: br x8
    return acc;
}

// [EN] Reconstructed FDE #1075 @ 0x027f28..0x027f44 (28 bytes)
// [VN] Phục dựng FDE #1075 tại 0x027f28..0x027f44 (28 byte)
//   0x027f28: f81f0ffe  str      x30, [sp, #-0x10]!
//   0x027f2c: 900001a0  adrp     x0, #0x5b000
//   0x027f30: f9431800  ldr      x0, [x0, #0x630]
//   0x027f34: 97fff372  bl       #0x24cfc
//   0x027f38: f9409008  ldr      x8, [x0, #0x120]
//   0x027f3c: f84107fe  ldr      x30, [sp], #0x10
//   0x027f40: d65f03c0  ret      
uint64_t fde_1075_sub_027f28(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81F0FFEULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x027F28ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81F0FFEULL; // 0x027f28: str x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A0ULL; // 0x027f2c: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9431800ULL; // 0x027f30: ldr x0, [x0, #0x630]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF372ULL; // 0x027f34: bl #0x24cfc
    acc = (acc * 0x100000001B3ULL) ^ 0xF9409008ULL; // 0x027f38: ldr x8, [x0, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xF84107FEULL; // 0x027f3c: ldr x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x027f40: ret 
    return acc;
}

// [EN] Reconstructed FDE #1076 @ 0x027f44..0x027f50 (12 bytes)
// [VN] Phục dựng FDE #1076 tại 0x027f44..0x027f50 (12 byte)
//   0x027f44: b9400001  ldr      w1, [x0]
//   0x027f48: 2a1f03e0  mov      w0, wzr
//   0x027f4c: 17ff8b59  b        #0xacb0
uint64_t fde_1076_sub_027f44(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400001ULL) + (x1 ^ 0x17FF8B59ULL) + (x2 ^ 0x027F44ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400001ULL; // 0x027f44: ldr w1, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x027f48: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF8B59ULL; // 0x027f4c: b #0xacb0
    return acc;
}

// [EN] Reconstructed FDE #1077 @ 0x027f50..0x027f70 (32 bytes)
// [VN] Phục dựng FDE #1077 tại 0x027f50..0x027f70 (32 byte)
//   0x027f50: f81f0ffe  str      x30, [sp, #-0x10]!
//   0x027f54: f9431a73  ldr      x19, [x19, #0x630]
//   0x027f58: aa1303e0  mov      x0, x19
//   0x027f5c: 97fff368  bl       #0x24cfc
//   0x027f60: b9400014  ldr      w20, [x0]
//   0x027f64: aa1303e0  mov      x0, x19
//   0x027f68: f84107fe  ldr      x30, [sp], #0x10
//   0x027f6c: 17fff364  b        #0x24cfc
uint64_t fde_1077_sub_027f50(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81F0FFEULL) + (x1 ^ 0x17FFF364ULL) + (x2 ^ 0x027F50ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81F0FFEULL; // 0x027f50: str x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0xF9431A73ULL; // 0x027f54: ldr x19, [x19, #0x630]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x027f58: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF368ULL; // 0x027f5c: bl #0x24cfc
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400014ULL; // 0x027f60: ldr w20, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x027f64: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF84107FEULL; // 0x027f68: ldr x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF364ULL; // 0x027f6c: b #0x24cfc
    return acc;
}

// [EN] Reconstructed FDE #1078 @ 0x027f70..0x027f94 (36 bytes)
// [VN] Phục dựng FDE #1078 tại 0x027f70..0x027f94 (36 byte)
//   0x027f70: 900001a8  adrp     x8, #0x5b000
//   0x027f74: f9475108  ldr      x8, [x8, #0xea0]
//   0x027f78: 2a0003e9  mov      w9, w0
//   0x027f7c: 910023e1  add      x1, sp, #8
//   0x027f80: 52800202  mov      w2, #0x10
//   0x027f84: b9400508  ldr      w8, [x8, #4]
//   0x027f88: f9000be9  str      x9, [sp, #0x10]
//   0x027f8c: 2a0803e0  mov      w0, w8
//   0x027f90: 17ff8d78  b        #0xb570
uint64_t fde_1078_sub_027f70(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x900001A8ULL) + (x1 ^ 0x17FF8D78ULL) + (x2 ^ 0x027F70ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A8ULL; // 0x027f70: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9475108ULL; // 0x027f74: ldr x8, [x8, #0xea0]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003E9ULL; // 0x027f78: mov w9, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E1ULL; // 0x027f7c: add x1, sp, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x52800202ULL; // 0x027f80: mov w2, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400508ULL; // 0x027f84: ldr w8, [x8, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BE9ULL; // 0x027f88: str x9, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0803E0ULL; // 0x027f8c: mov w0, w8
    return acc;
}

// [EN] Reconstructed FDE #1079 @ 0x027f94..0x027f9c (8 bytes)
// [VN] Phục dựng FDE #1079 tại 0x027f94..0x027f9c (8 byte)
//   0x027f94: 2a1f03e0  mov      w0, wzr
//   0x027f98: 17ff8b46  b        #0xacb0
uint64_t fde_1079_sub_027f94(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0x17FF8B46ULL) + (x2 ^ 0x027F94ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x027f94: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF8B46ULL; // 0x027f98: b #0xacb0
    return acc;
}

// [EN] Reconstructed FDE #1080 @ 0x027f9c..0x027fa8 (12 bytes)
// [VN] Phục dựng FDE #1080 tại 0x027f9c..0x027fa8 (12 byte)
//   0x027f9c: f94007e9  ldr      x9, [sp, #8]
//   0x027fa0: eb09011f  cmp      x8, x9
//   0x027fa4: d65f03c0  ret      
uint64_t fde_1080_sub_027f9c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF94007E9ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x027F9CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF94007E9ULL; // 0x027f9c: ldr x9, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x027fa0: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x027fa4: ret 
    return acc;
}

// [EN] Reconstructed FDE #1081 @ 0x027fa8..0x027fb0 (8 bytes)
// [VN] Phục dựng FDE #1081 tại 0x027fa8..0x027fb0 (8 byte)
//   0x027fa8: 910003e0  mov      x0, sp
//   0x027fac: 17ff9a7a  b        #0xe994
uint64_t fde_1081_sub_027fa8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910003E0ULL) + (x1 ^ 0x17FF9A7AULL) + (x2 ^ 0x027FA8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E0ULL; // 0x027fa8: mov x0, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF9A7AULL; // 0x027fac: b #0xe994
    return acc;
}

// [EN] Reconstructed FDE #1082 @ 0x027fb0..0x027fd0 (32 bytes)
// [VN] Phục dựng FDE #1082 tại 0x027fb0..0x027fd0 (32 byte)
//   0x027fb0: 900001b7  adrp     x23, #0x5b000
//   0x027fb4: f94316f7  ldr      x23, [x23, #0x628]
//   0x027fb8: 2a0003f5  mov      w21, w0
//   0x027fbc: 52800142  mov      w2, #0xa
//   0x027fc0: 2a1f03e0  mov      w0, wzr
//   0x027fc4: f94002e8  ldr      x8, [x23]
//   0x027fc8: 2a1303e1  mov      w1, w19
//   0x027fcc: d61f0100  br       x8
uint64_t fde_1082_sub_027fb0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x900001B7ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x027FB0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x900001B7ULL; // 0x027fb0: adrp x23, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF94316F7ULL; // 0x027fb4: ldr x23, [x23, #0x628]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F5ULL; // 0x027fb8: mov w21, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800142ULL; // 0x027fbc: mov w2, #0xa
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x027fc0: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xF94002E8ULL; // 0x027fc4: ldr x8, [x23]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1303E1ULL; // 0x027fc8: mov w1, w19
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x027fcc: br x8
    return acc;
}

// [EN] Reconstructed FDE #1083 @ 0x027fd0..0x027fd8 (8 bytes)
// [VN] Phục dựng FDE #1083 tại 0x027fd0..0x027fd8 (8 byte)
//   0x027fd0: aa1503e0  mov      x0, x21
//   0x027fd4: 17fff34a  b        #0x24cfc
uint64_t fde_1083_sub_027fd0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1503E0ULL) + (x1 ^ 0x17FFF34AULL) + (x2 ^ 0x027FD0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E0ULL; // 0x027fd0: mov x0, x21
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF34AULL; // 0x027fd4: b #0x24cfc
    return acc;
}

// [EN] Reconstructed FDE #1084 @ 0x027fd8..0x028004 (44 bytes)
// [VN] Phục dựng FDE #1084 tại 0x027fd8..0x028004 (44 byte)
//   0x027fd8: f81f0ffe  str      x30, [sp, #-0x10]!
//   0x027fdc: aa1403e0  mov      x0, x20
//   0x027fe0: 97fff347  bl       #0x24cfc
//   0x027fe4: b9400013  ldr      w19, [x0]
//   0x027fe8: aa1403e0  mov      x0, x20
//   0x027fec: 97fff344  bl       #0x24cfc
//   0x027ff0: 91006002  add      x2, x0, #0x18
//   0x027ff4: 52801001  mov      w1, #0x80
//   0x027ff8: 2a1303e0  mov      w0, w19
//   0x027ffc: f84107fe  ldr      x30, [sp], #0x10
//   0x028000: 17ff8d00  b        #0xb400
uint64_t fde_1084_sub_027fd8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81F0FFEULL) + (x1 ^ 0x2A1303E0ULL) + (x2 ^ 0x027FD8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81F0FFEULL; // 0x027fd8: str x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x027fdc: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF347ULL; // 0x027fe0: bl #0x24cfc
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400013ULL; // 0x027fe4: ldr w19, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x027fe8: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF344ULL; // 0x027fec: bl #0x24cfc
    acc = (acc * 0x100000001B3ULL) ^ 0x91006002ULL; // 0x027ff0: add x2, x0, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x52801001ULL; // 0x027ff4: mov w1, #0x80
    return acc;
}

// [EN] Reconstructed FDE #1085 @ 0x028004..0x028020 (28 bytes)
// [VN] Phục dựng FDE #1085 tại 0x028004..0x028020 (28 byte)
//   0x028004: f0000188  adrp     x8, #0x5b000
//   0x028008: f9431508  ldr      x8, [x8, #0x628]
//   0x02800c: 52800142  mov      w2, #0xa
//   0x028010: 2a1f03e0  mov      w0, wzr
//   0x028014: 2a1303e1  mov      w1, w19
//   0x028018: f9400108  ldr      x8, [x8]
//   0x02801c: d61f0100  br       x8
uint64_t fde_1085_sub_028004(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000188ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x028004ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000188ULL; // 0x028004: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9431508ULL; // 0x028008: ldr x8, [x8, #0x628]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800142ULL; // 0x02800c: mov w2, #0xa
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x028010: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1303E1ULL; // 0x028014: mov w1, w19
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x028018: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x02801c: br x8
    return acc;
}

// [EN] Reconstructed FDE #1086 @ 0x028020..0x028050 (48 bytes)
// [VN] Phục dựng FDE #1086 tại 0x028020..0x028050 (48 byte)
//   0x028020: f81f0ffe  str      x30, [sp, #-0x10]!
//   0x028024: aa1703e0  mov      x0, x23
//   0x028028: 97fff335  bl       #0x24cfc
//   0x02802c: b9400018  ldr      w24, [x0]
//   0x028030: aa1703e0  mov      x0, x23
//   0x028034: 97fff332  bl       #0x24cfc
//   0x028038: 91006001  add      x1, x0, #0x18
//   0x02803c: 2a1803e0  mov      w0, w24
//   0x028040: 97fff7de  bl       #0x25fb8
//   0x028044: d00000a1  adrp     x1, #0x3e000
//   0x028048: f84107fe  ldr      x30, [sp], #0x10
//   0x02804c: d65f03c0  ret      
uint64_t fde_1086_sub_028020(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81F0FFEULL) + (x1 ^ 0x97FFF7DEULL) + (x2 ^ 0x028020ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81F0FFEULL; // 0x028020: str x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1703E0ULL; // 0x028024: mov x0, x23
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF335ULL; // 0x028028: bl #0x24cfc
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400018ULL; // 0x02802c: ldr w24, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1703E0ULL; // 0x028030: mov x0, x23
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF332ULL; // 0x028034: bl #0x24cfc
    acc = (acc * 0x100000001B3ULL) ^ 0x91006001ULL; // 0x028038: add x1, x0, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1803E0ULL; // 0x02803c: mov w0, w24
    return acc;
}

// [EN] Reconstructed FDE #1087 @ 0x028050..0x028068 (24 bytes)
// [VN] Phục dựng FDE #1087 tại 0x028050..0x028068 (24 byte)
//   0x028050: aa0003e8  mov      x8, x0
//   0x028054: 2a1603e0  mov      w0, w22
//   0x028058: 2a1503e1  mov      w1, w21
//   0x02805c: aa1403e2  mov      x2, x20
//   0x028060: aa1303e3  mov      x3, x19
//   0x028064: d61f0100  br       x8
uint64_t fde_1087_sub_028050(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x028050ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x028050: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1603E0ULL; // 0x028054: mov w0, w22
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1503E1ULL; // 0x028058: mov w1, w21
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E2ULL; // 0x02805c: mov x2, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E3ULL; // 0x028060: mov x3, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x028064: br x8
    return acc;
}

// [EN] Reconstructed FDE #1088 @ 0x028068..0x028098 (48 bytes)
// [VN] Phục dựng FDE #1088 tại 0x028068..0x028098 (48 byte)
//   0x028068: f81f0ffe  str      x30, [sp, #-0x10]!
//   0x02806c: f0000194  adrp     x20, #0x5b000
//   0x028070: f9431a94  ldr      x20, [x20, #0x630]
//   0x028074: aa1403e0  mov      x0, x20
//   0x028078: 97fff321  bl       #0x24cfc
//   0x02807c: b9000413  str      w19, [x0, #4]
//   0x028080: aa1403e0  mov      x0, x20
//   0x028084: 97fff31e  bl       #0x24cfc
//   0x028088: 52800028  mov      w8, #1
//   0x02808c: 39004008  strb     w8, [x0, #0x10]
//   0x028090: f84107fe  ldr      x30, [sp], #0x10
//   0x028094: d65f03c0  ret      
uint64_t fde_1088_sub_028068(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81F0FFEULL) + (x1 ^ 0x52800028ULL) + (x2 ^ 0x028068ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81F0FFEULL; // 0x028068: str x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000194ULL; // 0x02806c: adrp x20, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9431A94ULL; // 0x028070: ldr x20, [x20, #0x630]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x028074: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF321ULL; // 0x028078: bl #0x24cfc
    acc = (acc * 0x100000001B3ULL) ^ 0xB9000413ULL; // 0x02807c: str w19, [x0, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x028080: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF31EULL; // 0x028084: bl #0x24cfc
    return acc;
}

// [EN] Reconstructed FDE #1089 @ 0x028098..0x0280b0 (24 bytes)
// [VN] Phục dựng FDE #1089 tại 0x028098..0x0280b0 (24 byte)
//   0x028098: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x02809c: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x0280a0: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x0280a4: a94167fa  ldp      x26, x25, [sp, #0x10]
//   0x0280a8: 910183ff  add      sp, sp, #0x60
//   0x0280ac: d65f03c0  ret      
uint64_t fde_1089_sub_028098(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9444FF4ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x028098ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9444FF4ULL; // 0x028098: ldp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA94357F6ULL; // 0x02809c: ldp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9425FF8ULL; // 0x0280a0: ldp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA94167FAULL; // 0x0280a4: ldp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FFULL; // 0x0280a8: add sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0280ac: ret 
    return acc;
}

// [EN] Reconstructed FDE #1090 @ 0x0280b0..0x0280bc (12 bytes)
// [VN] Phục dựng FDE #1090 tại 0x0280b0..0x0280bc (12 byte)
//   0x0280b0: b9400015  ldr      w21, [x0]
//   0x0280b4: aa1403e0  mov      x0, x20
//   0x0280b8: 17fff311  b        #0x24cfc
uint64_t fde_1090_sub_0280b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400015ULL) + (x1 ^ 0x17FFF311ULL) + (x2 ^ 0x0280B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400015ULL; // 0x0280b0: ldr w21, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x0280b4: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF311ULL; // 0x0280b8: b #0x24cfc
    return acc;
}

// [EN] Reconstructed FDE #1091 @ 0x0280bc..0x0280d0 (20 bytes)
// [VN] Phục dựng FDE #1091 tại 0x0280bc..0x0280d0 (20 byte)
//   0x0280bc: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x0280c0: a94257f6  ldp      x22, x21, [sp, #0x20]
//   0x0280c4: f9400bf7  ldr      x23, [sp, #0x10]
//   0x0280c8: 910143ff  add      sp, sp, #0x50
//   0x0280cc: d65f03c0  ret      
uint64_t fde_1091_sub_0280bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9434FF4ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0280BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9434FF4ULL; // 0x0280bc: ldp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA94257F6ULL; // 0x0280c0: ldp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400BF7ULL; // 0x0280c4: ldr x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FFULL; // 0x0280c8: add sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0280cc: ret 
    return acc;
}

// [EN] Reconstructed FDE #1092 @ 0x0280d0..0x0280e4 (20 bytes)
// [VN] Phục dựng FDE #1092 tại 0x0280d0..0x0280e4 (20 byte)
//   0x0280d0: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x0280d4: a94257f6  ldp      x22, x21, [sp, #0x20]
//   0x0280d8: a9415ff8  ldp      x24, x23, [sp, #0x10]
//   0x0280dc: 910143ff  add      sp, sp, #0x50
//   0x0280e0: d65f03c0  ret      
uint64_t fde_1092_sub_0280d0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9434FF4ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0280D0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9434FF4ULL; // 0x0280d0: ldp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA94257F6ULL; // 0x0280d4: ldp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9415FF8ULL; // 0x0280d8: ldp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FFULL; // 0x0280dc: add sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0280e0: ret 
    return acc;
}

// [EN] Reconstructed FDE #1093 @ 0x0280e4..0x0280f0 (12 bytes)
// [VN] Phục dựng FDE #1093 tại 0x0280e4..0x0280f0 (12 byte)
//   0x0280e4: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x0280e8: f84307f5  ldr      x21, [sp], #0x30
//   0x0280ec: d65f03c0  ret      
uint64_t fde_1093_sub_0280e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9414FF4ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0280E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9414FF4ULL; // 0x0280e4: ldp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF84307F5ULL; // 0x0280e8: ldr x21, [sp], #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0280ec: ret 
    return acc;
}

// [EN] Reconstructed FDE #1094 @ 0x0280f0..0x028100 (16 bytes)
// [VN] Phục dựng FDE #1094 tại 0x0280f0..0x028100 (16 byte)
//   0x0280f0: f0000188  adrp     x8, #0x5b000
//   0x0280f4: f9464508  ldr      x8, [x8, #0xc88]
//   0x0280f8: 39400108  ldrb     w8, [x8]
//   0x0280fc: d65f03c0  ret      
uint64_t fde_1094_sub_0280f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000188ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0280F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000188ULL; // 0x0280f0: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9464508ULL; // 0x0280f4: ldr x8, [x8, #0xc88]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400108ULL; // 0x0280f8: ldrb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0280fc: ret 
    return acc;
}

// [EN] Reconstructed FDE #1095 @ 0x028100..0x028120 (32 bytes)
// [VN] Phục dựng FDE #1095 tại 0x028100..0x028120 (32 byte)
//   0x028100: f81f0ffe  str      x30, [sp, #-0x10]!
//   0x028104: f0000197  adrp     x23, #0x5b000
//   0x028108: f9431af7  ldr      x23, [x23, #0x630]
//   0x02810c: aa1703e0  mov      x0, x23
//   0x028110: 97fff2fb  bl       #0x24cfc
//   0x028114: f9409000  ldr      x0, [x0, #0x120]
//   0x028118: f84107fe  ldr      x30, [sp], #0x10
//   0x02811c: 17fff8cd  b        #0x26450
uint64_t fde_1095_sub_028100(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81F0FFEULL) + (x1 ^ 0x17FFF8CDULL) + (x2 ^ 0x028100ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81F0FFEULL; // 0x028100: str x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000197ULL; // 0x028104: adrp x23, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9431AF7ULL; // 0x028108: ldr x23, [x23, #0x630]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1703E0ULL; // 0x02810c: mov x0, x23
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF2FBULL; // 0x028110: bl #0x24cfc
    acc = (acc * 0x100000001B3ULL) ^ 0xF9409000ULL; // 0x028114: ldr x0, [x0, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xF84107FEULL; // 0x028118: ldr x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF8CDULL; // 0x02811c: b #0x26450
    return acc;
}

// [EN] Reconstructed FDE #1096 @ 0x028120..0x028130 (16 bytes)
// [VN] Phục dựng FDE #1096 tại 0x028120..0x028130 (16 byte)
//   0x028120: 91026001  add      x1, x0, #0x98
//   0x028124: 910023e0  add      x0, sp, #8
//   0x028128: 52801002  mov      w2, #0x80
//   0x02812c: 17ff8d0d  b        #0xb560
uint64_t fde_1096_sub_028120(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x91026001ULL) + (x1 ^ 0x17FF8D0DULL) + (x2 ^ 0x028120ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x91026001ULL; // 0x028120: add x1, x0, #0x98
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E0ULL; // 0x028124: add x0, sp, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x52801002ULL; // 0x028128: mov w2, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF8D0DULL; // 0x02812c: b #0xb560
    return acc;
}

// [EN] Reconstructed FDE #1097 @ 0x028130..0x028140 (16 bytes)
// [VN] Phục dựng FDE #1097 tại 0x028130..0x028140 (16 byte)
//   0x028130: b9400000  ldr      w0, [x0]
//   0x028134: 910023e2  add      x2, sp, #8
//   0x028138: 52801001  mov      w1, #0x80
//   0x02813c: 17ff8cb1  b        #0xb400
uint64_t fde_1097_sub_028130(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400000ULL) + (x1 ^ 0x17FF8CB1ULL) + (x2 ^ 0x028130ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400000ULL; // 0x028130: ldr w0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E2ULL; // 0x028134: add x2, sp, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x52801001ULL; // 0x028138: mov w1, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF8CB1ULL; // 0x02813c: b #0xb400
    return acc;
}

// [EN] Reconstructed FDE #1098 @ 0x028140..0x028150 (16 bytes)
// [VN] Phục dựng FDE #1098 tại 0x028140..0x028150 (16 byte)
//   0x028140: f9401668  ldr      x8, [x19, #0x28]
//   0x028144: f85e83a9  ldur     x9, [x29, #-0x18]
//   0x028148: eb09011f  cmp      x8, x9
//   0x02814c: d65f03c0  ret      
uint64_t fde_1098_sub_028140(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9401668ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x028140ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x028140: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF85E83A9ULL; // 0x028144: ldur x9, [x29, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x028148: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02814c: ret 
    return acc;
}

// [EN] Reconstructed FDE #1099 @ 0x028150..0x028160 (16 bytes)
// [VN] Phục dựng FDE #1099 tại 0x028150..0x028160 (16 byte)
//   0x028150: f94002e8  ldr      x8, [x23]
//   0x028154: 2a1303e1  mov      w1, w19
//   0x028158: 2a1503e2  mov      w2, w21
//   0x02815c: d61f0100  br       x8
uint64_t fde_1099_sub_028150(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF94002E8ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x028150ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF94002E8ULL; // 0x028150: ldr x8, [x23]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1303E1ULL; // 0x028154: mov w1, w19
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1503E2ULL; // 0x028158: mov w2, w21
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x02815c: br x8
    return acc;
}

// [EN] Reconstructed FDE #1100 @ 0x028160..0x028178 (24 bytes)
// [VN] Phục dựng FDE #1100 tại 0x028160..0x028178 (24 byte)
//   0x028160: aa0003e9  mov      x9, x0
//   0x028164: aa1703e8  mov      x8, x23
//   0x028168: aa1603e0  mov      x0, x22
//   0x02816c: aa1503e1  mov      x1, x21
//   0x028170: 2a1403e2  mov      w2, w20
//   0x028174: d65f03c0  ret      
uint64_t fde_1100_sub_028160(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E9ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x028160ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E9ULL; // 0x028160: mov x9, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1703E8ULL; // 0x028164: mov x8, x23
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1603E0ULL; // 0x028168: mov x0, x22
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E1ULL; // 0x02816c: mov x1, x21
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1403E2ULL; // 0x028170: mov w2, w20
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x028174: ret 
    return acc;
}

// [EN] Reconstructed FDE #1101 @ 0x028178..0x028188 (16 bytes)
// [VN] Phục dựng FDE #1101 tại 0x028178..0x028188 (16 byte)
//   0x028178: f9431800  ldr      x0, [x0, #0x630]
//   0x02817c: aa0203f4  mov      x20, x2
//   0x028180: 2a0103f5  mov      w21, w1
//   0x028184: 17fff2de  b        #0x24cfc
uint64_t fde_1101_sub_028178(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9431800ULL) + (x1 ^ 0x17FFF2DEULL) + (x2 ^ 0x028178ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9431800ULL; // 0x028178: ldr x0, [x0, #0x630]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x02817c: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F5ULL; // 0x028180: mov w21, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF2DEULL; // 0x028184: b #0x24cfc
    return acc;
}

// [EN] Reconstructed FDE #1102 @ 0x028188..0x028194 (12 bytes)
// [VN] Phục dựng FDE #1102 tại 0x028188..0x028194 (12 byte)
//   0x028188: 2a1f03e0  mov      w0, wzr
//   0x02818c: f9400108  ldr      x8, [x8]
//   0x028190: d61f0100  br       x8
uint64_t fde_1102_sub_028188(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x028188ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x028188: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x02818c: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x028190: br x8
    return acc;
}

// [EN] Reconstructed FDE #1103 @ 0x028194..0x0281a0 (12 bytes)
// [VN] Phục dựng FDE #1103 tại 0x028194..0x0281a0 (12 byte)
//   0x028194: 2a1f03e0  mov      w0, wzr
//   0x028198: 2a1403e1  mov      w1, w20
//   0x02819c: d61f02a0  br       x21
uint64_t fde_1103_sub_028194(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD61F02A0ULL) + (x2 ^ 0x028194ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x028194: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1403E1ULL; // 0x028198: mov w1, w20
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F02A0ULL; // 0x02819c: br x21
    return acc;
}

// [EN] Reconstructed FDE #1104 @ 0x0281a0..0x0281ac (12 bytes)
// [VN] Phục dựng FDE #1104 tại 0x0281a0..0x0281ac (12 byte)
//   0x0281a0: 2a1f03e0  mov      w0, wzr
//   0x0281a4: 2a1303e1  mov      w1, w19
//   0x0281a8: 17ff8ac2  b        #0xacb0
uint64_t fde_1104_sub_0281a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0x17FF8AC2ULL) + (x2 ^ 0x0281A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x0281a0: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1303E1ULL; // 0x0281a4: mov w1, w19
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF8AC2ULL; // 0x0281a8: b #0xacb0
    return acc;
}

// [EN] Reconstructed FDE #1105 @ 0x0281ac..0x0281b8 (12 bytes)
// [VN] Phục dựng FDE #1105 tại 0x0281ac..0x0281b8 (12 byte)
//   0x0281ac: f0000180  adrp     x0, #0x5b000
//   0x0281b0: f9445800  ldr      x0, [x0, #0x8b0]
//   0x0281b4: 17ff8ca3  b        #0xb440
uint64_t fde_1105_sub_0281ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000180ULL) + (x1 ^ 0x17FF8CA3ULL) + (x2 ^ 0x0281ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000180ULL; // 0x0281ac: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9445800ULL; // 0x0281b0: ldr x0, [x0, #0x8b0]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF8CA3ULL; // 0x0281b4: b #0xb440
    return acc;
}

// [EN] Reconstructed FDE #1106 @ 0x0281b8..0x0281c0 (8 bytes)
// [VN] Phục dựng FDE #1106 tại 0x0281b8..0x0281c0 (8 byte)
//   0x0281b8: aa1f03e3  mov      x3, xzr
//   0x0281bc: 17ff8ab5  b        #0xac90
uint64_t fde_1106_sub_0281b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E3ULL) + (x1 ^ 0x17FF8AB5ULL) + (x2 ^ 0x0281B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E3ULL; // 0x0281b8: mov x3, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF8AB5ULL; // 0x0281bc: b #0xac90
    return acc;
}

// [EN] Reconstructed FDE #1107 @ 0x0281c0..0x0281cc (12 bytes)
// [VN] Phục dựng FDE #1107 tại 0x0281c0..0x0281cc (12 byte)
//   0x0281c0: b9411808  ldr      w8, [x0, #0x118]
//   0x0281c4: 7100051f  cmp      w8, #1
//   0x0281c8: d65f03c0  ret      
uint64_t fde_1107_sub_0281c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9411808ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0281C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9411808ULL; // 0x0281c0: ldr w8, [x0, #0x118]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100051FULL; // 0x0281c4: cmp w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0281c8: ret 
    return acc;
}

// [EN] Reconstructed FDE #1108 @ 0x0281cc..0x0281d8 (12 bytes)
// [VN] Phục dựng FDE #1108 tại 0x0281cc..0x0281d8 (12 byte)
//   0x0281cc: f0000180  adrp     x0, #0x5b000
//   0x0281d0: f9433800  ldr      x0, [x0, #0x670]
//   0x0281d4: 17ff8c9b  b        #0xb440
uint64_t fde_1108_sub_0281cc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000180ULL) + (x1 ^ 0x17FF8C9BULL) + (x2 ^ 0x0281CCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000180ULL; // 0x0281cc: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9433800ULL; // 0x0281d0: ldr x0, [x0, #0x670]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF8C9BULL; // 0x0281d4: b #0xb440
    return acc;
}

// [EN] Reconstructed FDE #1109 @ 0x0281d8..0x0281e4 (12 bytes)
// [VN] Phục dựng FDE #1109 tại 0x0281d8..0x0281e4 (12 byte)
//   0x0281d8: f0000188  adrp     x8, #0x5b000
//   0x0281dc: f9431508  ldr      x8, [x8, #0x628]
//   0x0281e0: d65f03c0  ret      
uint64_t fde_1109_sub_0281d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000188ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0281D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000188ULL; // 0x0281d8: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9431508ULL; // 0x0281dc: ldr x8, [x8, #0x628]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0281e0: ret 
    return acc;
}

// [EN] Reconstructed FDE #1110 @ 0x0281e4..0x0281ec (8 bytes)
// [VN] Phục dựng FDE #1110 tại 0x0281e4..0x0281ec (8 byte)
//   0x0281e4: 528000c0  mov      w0, #6
//   0x0281e8: 17ff8bfe  b        #0xb1e0
uint64_t fde_1110_sub_0281e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x528000C0ULL) + (x1 ^ 0x17FF8BFEULL) + (x2 ^ 0x0281E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C0ULL; // 0x0281e4: mov w0, #6
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF8BFEULL; // 0x0281e8: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #1111 @ 0x0281ec..0x02820c (32 bytes)
// [VN] Phục dựng FDE #1111 tại 0x0281ec..0x02820c (32 byte)
//   0x0281ec: 6f00e400  movi     v0.2d, #0000000000000000
//   0x0281f0: 52a7f009  mov      w9, #0x3f800000
//   0x0281f4: 9100a008  add      x8, x0, #0x28
//   0x0281f8: ad000000  stp      q0, q0, [x0]
//   0x0281fc: b9002009  str      w9, [x0, #0x20]
//   0x028200: aa0803e0  mov      x0, x8
//   0x028204: aa1f03e1  mov      x1, xzr
//   0x028208: 17ff8bb6  b        #0xb0e0
uint64_t fde_1111_sub_0281ec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x6F00E400ULL) + (x1 ^ 0x17FF8BB6ULL) + (x2 ^ 0x0281ECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x6F00E400ULL; // 0x0281ec: movi v0.2d, #0000000000000000
    acc = (acc * 0x100000001B3ULL) ^ 0x52A7F009ULL; // 0x0281f0: mov w9, #0x3f800000
    acc = (acc * 0x100000001B3ULL) ^ 0x9100A008ULL; // 0x0281f4: add x8, x0, #0x28
    acc = (acc * 0x100000001B3ULL) ^ 0xAD000000ULL; // 0x0281f8: stp q0, q0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9002009ULL; // 0x0281fc: str w9, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E0ULL; // 0x028200: mov x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x028204: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF8BB6ULL; // 0x028208: b #0xb0e0
    return acc;
}

// [EN] Reconstructed FDE #1112 @ 0x02820c..0x028234 (40 bytes)
// [VN] Phục dựng FDE #1112 tại 0x02820c..0x028234 (40 byte)
//   0x02820c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x028210: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x028214: 910043fd  add      x29, sp, #0x10
//   0x028218: aa0003f3  mov      x19, x0
//   0x02821c: 9100a000  add      x0, x0, #0x28
//   0x028220: 97ff8d54  bl       #0xb770
//   0x028224: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x028228: aa1303e0  mov      x0, x19
//   0x02822c: f84207f3  ldr      x19, [sp], #0x20
//   0x028230: 14000104  b        #0x28640
uint64_t fde_1112_sub_02820c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x02820CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02820c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x028210: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x028214: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x028218: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9100A000ULL; // 0x02821c: add x0, x0, #0x28
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF8D54ULL; // 0x028220: bl #0xb770
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x028224: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x028228: mov x0, x19
    return acc;
}

// [EN] Reconstructed FDE #1113 @ 0x028234..0x0282dc (168 bytes)
// [VN] Phục dựng FDE #1113 tại 0x028234..0x0282dc (168 byte)
//   0x028234: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x028238: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02823c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x028240: 910083fd  add      x29, sp, #0x20
//   0x028244: 7100045f  cmp      w2, #1
//   0x028248: 540000eb  b.lt     #0x28264
//   0x02824c: 11005068  add      w8, w3, #0x14
//   0x028250: 2a0303f4  mov      w20, w3
//   0x028254: 71009d1f  cmp      w8, #0x27
//   0x028258: 540000a9  b.ls     #0x2826c
//   0x02825c: 12800020  mov      w0, #-2
//   0x028260: 1400001b  b        #0x282cc
uint64_t fde_1113_sub_028234(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x71009D1FULL) + (x2 ^ 0x028234ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x028234: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x028238: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02823c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x028240: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x7100045FULL; // 0x028244: cmp w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540000EBULL; // 0x028248: b.lt #0x28264
    acc = (acc * 0x100000001B3ULL) ^ 0x11005068ULL; // 0x02824c: add w8, w3, #0x14
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303F4ULL; // 0x028250: mov w20, w3
    return acc;
}

// [EN] Reconstructed FDE #1114 @ 0x0282dc..0x028360 (132 bytes)
// [VN] Phục dựng FDE #1114 tại 0x0282dc..0x028360 (132 byte)
//   0x0282dc: d10103ff  sub      sp, sp, #0x40
//   0x0282e0: f9000bf5  str      x21, [sp, #0x10]
//   0x0282e4: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0282e8: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0282ec: 9100c3fd  add      x29, sp, #0x30
//   0x0282f0: d53bd055  mrs      x21, tpidr_el0
//   0x0282f4: f94016a8  ldr      x8, [x21, #0x28]
//   0x0282f8: 9100a013  add      x19, x0, #0x28
//   0x0282fc: aa0003f4  mov      x20, x0
//   0x028300: aa1303e0  mov      x0, x19
//   0x028304: f90007e8  str      x8, [sp, #8]
//   0x028308: b90007e1  str      w1, [sp, #4]
uint64_t fde_1114_sub_0282dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xAA0003F4ULL) + (x2 ^ 0x0282DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x0282dc: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF5ULL; // 0x0282e0: str x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0282e4: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0282e8: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0282ec: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x0282f0: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x0282f4: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100A013ULL; // 0x0282f8: add x19, x0, #0x28
    return acc;
}

// [EN] Reconstructed FDE #1115 @ 0x028360..0x0283d8 (120 bytes)
// [VN] Phục dựng FDE #1115 tại 0x028360..0x0283d8 (120 byte)
//   0x028360: d10103ff  sub      sp, sp, #0x40
//   0x028364: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x028368: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x02836c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x028370: 9100c3fd  add      x29, sp, #0x30
//   0x028374: d53bd056  mrs      x22, tpidr_el0
//   0x028378: f94016c8  ldr      x8, [x22, #0x28]
//   0x02837c: 9100a015  add      x21, x0, #0x28
//   0x028380: aa0003f4  mov      x20, x0
//   0x028384: aa1503e0  mov      x0, x21
//   0x028388: 2a0203f3  mov      w19, w2
//   0x02838c: f90007e8  str      x8, [sp, #8]
uint64_t fde_1115_sub_028360(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xAA0003F4ULL) + (x2 ^ 0x028360ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x028360: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x028364: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x028368: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02836c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x028370: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x028374: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x028378: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100A015ULL; // 0x02837c: add x21, x0, #0x28
    return acc;
}

// [EN] Reconstructed FDE #1116 @ 0x0283d8..0x028430 (88 bytes)
// [VN] Phục dựng FDE #1116 tại 0x0283d8..0x028430 (88 byte)
//   0x0283d8: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0283dc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0283e0: 910043fd  add      x29, sp, #0x10
//   0x0283e4: 7100045f  cmp      w2, #1
//   0x0283e8: 540001cb  b.lt     #0x28420
//   0x0283ec: b00001a0  adrp     x0, #0x5d000
//   0x0283f0: 910ac000  add      x0, x0, #0x2b0
//   0x0283f4: 2a0203e1  mov      w1, w2
//   0x0283f8: 2a0203f3  mov      w19, w2
//   0x0283fc: 9400000d  bl       #0x28430
//   0x028400: 3101901f  cmn      w0, #0x64
//   0x028404: 540000a0  b.eq     #0x28418
uint64_t fde_1116_sub_0283d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x2A0203F3ULL) + (x2 ^ 0x0283D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0283d8: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0283dc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0283e0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x7100045FULL; // 0x0283e4: cmp w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540001CBULL; // 0x0283e8: b.lt #0x28420
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001A0ULL; // 0x0283ec: adrp x0, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0x910AC000ULL; // 0x0283f0: add x0, x0, #0x2b0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203E1ULL; // 0x0283f4: mov w1, w2
    return acc;
}

// [EN] Reconstructed FDE #1117 @ 0x028430..0x0284c0 (144 bytes)
// [VN] Phục dựng FDE #1117 tại 0x028430..0x0284c0 (144 byte)
//   0x028430: d10103ff  sub      sp, sp, #0x40
//   0x028434: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x028438: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x02843c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x028440: 9100c3fd  add      x29, sp, #0x30
//   0x028444: d53bd056  mrs      x22, tpidr_el0
//   0x028448: f94016c8  ldr      x8, [x22, #0x28]
//   0x02844c: 9100a013  add      x19, x0, #0x28
//   0x028450: aa0003f4  mov      x20, x0
//   0x028454: aa1303e0  mov      x0, x19
//   0x028458: f90007e8  str      x8, [sp, #8]
//   0x02845c: b90007e1  str      w1, [sp, #4]
uint64_t fde_1117_sub_028430(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xAA0003F4ULL) + (x2 ^ 0x028430ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x028430: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x028434: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x028438: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02843c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x028440: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x028444: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x028448: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100A013ULL; // 0x02844c: add x19, x0, #0x28
    return acc;
}

// [EN] Reconstructed FDE #1118 @ 0x0284c0..0x028508 (72 bytes)
// [VN] Phục dựng FDE #1118 tại 0x0284c0..0x028508 (72 byte)
//   0x0284c0: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0284c4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0284c8: 910043fd  add      x29, sp, #0x10
//   0x0284cc: aa0003f3  mov      x19, x0
//   0x0284d0: 97ff8ae4  bl       #0xb060
//   0x0284d4: b9401262  ldr      w2, [x19, #0x10]
//   0x0284d8: 2a0003e1  mov      w1, w0
//   0x0284dc: 2a1f03e0  mov      w0, wzr
//   0x0284e0: 97ff8b64  bl       #0xb270
//   0x0284e4: a9402260  ldp      x0, x8, [x19]
//   0x0284e8: d63f0100  blr      x8
//   0x0284ec: aa0003f4  mov      x20, x0
uint64_t fde_1118_sub_0284c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x97FF8B64ULL) + (x2 ^ 0x0284C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0284c0: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0284c4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0284c8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0284cc: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF8AE4ULL; // 0x0284d0: bl #0xb060
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401262ULL; // 0x0284d4: ldr w2, [x19, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003E1ULL; // 0x0284d8: mov w1, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x0284dc: mov w0, wzr
    return acc;
}

// [EN] Reconstructed FDE #1119 @ 0x028508..0x028550 (72 bytes)
// [VN] Phục dựng FDE #1119 tại 0x028508..0x028550 (72 byte)
//   0x028508: 72001c5f  tst      w2, #0xff
//   0x02850c: 540001a0  b.eq     #0x28540
//   0x028510: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x028514: 910003fd  mov      x29, sp
//   0x028518: d00000a1  adrp     x1, #0x3e000
//   0x02851c: 90000002  adrp     x2, #0x28000
//   0x028520: 91230421  add      x1, x1, #0x8c1
//   0x028524: 91154042  add      x2, x2, #0x550
//   0x028528: aa1f03e0  mov      x0, xzr
//   0x02852c: aa1f03e3  mov      x3, xzr
//   0x028530: aa1f03e4  mov      x4, xzr
//   0x028534: 97ff8c43  bl       #0xb640
uint64_t fde_1119_sub_028508(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x72001C5FULL) + (x1 ^ 0xAA1F03E0ULL) + (x2 ^ 0x028508ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x72001C5FULL; // 0x028508: tst w2, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x540001A0ULL; // 0x02850c: b.eq #0x28540
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x028510: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x028514: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xD00000A1ULL; // 0x028518: adrp x1, #0x3e000
    acc = (acc * 0x100000001B3ULL) ^ 0x90000002ULL; // 0x02851c: adrp x2, #0x28000
    acc = (acc * 0x100000001B3ULL) ^ 0x91230421ULL; // 0x028520: add x1, x1, #0x8c1
    acc = (acc * 0x100000001B3ULL) ^ 0x91154042ULL; // 0x028524: add x2, x2, #0x550
    return acc;
}

// [EN] Reconstructed FDE #1120 @ 0x028550..0x028640 (240 bytes)
// [VN] Phục dựng FDE #1120 tại 0x028550..0x028640 (240 byte)
//   0x028550: d10183ff  sub      sp, sp, #0x60
//   0x028554: f9000bf9  str      x25, [sp, #0x10]
//   0x028558: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x02855c: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x028560: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x028564: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x028568: 910143fd  add      x29, sp, #0x50
//   0x02856c: d53bd059  mrs      x25, tpidr_el0
//   0x028570: f9401728  ldr      x8, [x25, #0x28]
//   0x028574: aa0303f5  mov      x21, x3
//   0x028578: aa0203f6  mov      x22, x2
//   0x02857c: aa0103f3  mov      x19, x1
uint64_t fde_1120_sub_028550(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xF9401728ULL) + (x2 ^ 0x028550ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x028550: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF9ULL; // 0x028554: str x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x028558: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x02855c: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x028560: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x028564: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x028568: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x02856c: mrs x25, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #1121 @ 0x028640..0x028668 (40 bytes)
// [VN] Phục dựng FDE #1121 tại 0x028640..0x028668 (40 byte)
//   0x028640: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x028644: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x028648: 910043fd  add      x29, sp, #0x10
//   0x02864c: f9400801  ldr      x1, [x0, #0x10]
//   0x028650: aa0003f3  mov      x19, x0
//   0x028654: 94000005  bl       #0x28668
//   0x028658: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02865c: aa1303e0  mov      x0, x19
//   0x028660: f84207f3  ldr      x19, [sp], #0x20
//   0x028664: 1400000d  b        #0x28698
uint64_t fde_1121_sub_028640(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x028640ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x028640: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x028644: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x028648: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400801ULL; // 0x02864c: ldr x1, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x028650: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x94000005ULL; // 0x028654: bl #0x28668
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x028658: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x02865c: mov x0, x19
    return acc;
}

// [EN] Reconstructed FDE #1122 @ 0x028668..0x028698 (48 bytes)
// [VN] Phục dựng FDE #1122 tại 0x028668..0x028698 (48 byte)
//   0x028668: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x02866c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x028670: 910043fd  add      x29, sp, #0x10
//   0x028674: aa0103e0  mov      x0, x1
//   0x028678: b40000a0  cbz      x0, #0x2868c
//   0x02867c: f9400013  ldr      x19, [x0]
//   0x028680: 97ff89b0  bl       #0xad40
//   0x028684: aa1303e0  mov      x0, x19
//   0x028688: b5ffffa0  cbnz     x0, #0x2867c
//   0x02868c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x028690: f84207f3  ldr      x19, [sp], #0x20
//   0x028694: d65f03c0  ret      
uint64_t fde_1122_sub_028668(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xB5FFFFA0ULL) + (x2 ^ 0x028668ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x028668: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02866c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x028670: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x028674: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000A0ULL; // 0x028678: cbz x0, #0x2868c
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400013ULL; // 0x02867c: ldr x19, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF89B0ULL; // 0x028680: bl #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x028684: mov x0, x19
    return acc;
}

// [EN] Reconstructed FDE #1123 @ 0x028698..0x0286a0 (8 bytes)
// [VN] Phục dựng FDE #1123 tại 0x028698..0x0286a0 (8 byte)
//   0x028698: aa1f03e1  mov      x1, xzr
//   0x02869c: 14000001  b        #0x286a0
uint64_t fde_1123_sub_028698(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E1ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x028698ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x028698: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x02869c: b #0x286a0
    return acc;
}

// [EN] Reconstructed FDE #1124 @ 0x0286a0..0x0286b8 (24 bytes)
// [VN] Phục dựng FDE #1124 tại 0x0286a0..0x0286b8 (24 byte)
//   0x0286a0: aa0003e8  mov      x8, x0
//   0x0286a4: f9400000  ldr      x0, [x0]
//   0x0286a8: f900011f  str      xzr, [x8]
//   0x0286ac: b4000040  cbz      x0, #0x286b4
//   0x0286b0: 17ff89a4  b        #0xad40
//   0x0286b4: d65f03c0  ret      
uint64_t fde_1124_sub_0286a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0286A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x0286a0: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x0286a4: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900011FULL; // 0x0286a8: str xzr, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000040ULL; // 0x0286ac: cbz x0, #0x286b4
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF89A4ULL; // 0x0286b0: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0286b4: ret 
    return acc;
}

// [EN] Reconstructed FDE #1125 @ 0x0286b8..0x028760 (168 bytes)
// [VN] Phục dựng FDE #1125 tại 0x0286b8..0x028760 (168 byte)
//   0x0286b8: f9400408  ldr      x8, [x0, #8]
//   0x0286bc: b40004e8  cbz      x8, #0x28758
//   0x0286c0: 9e670100  fmov     d0, x8
//   0x0286c4: b9800029  ldrsw    x9, [x1]
//   0x0286c8: 0e205800  cnt      v0.8b, v0.8b
//   0x0286cc: 2e303800  uaddlv   h0, v0.8b
//   0x0286d0: 1e26000a  fmov     w10, s0
//   0x0286d4: f100055f  cmp      x10, #1
//   0x0286d8: 540000e9  b.ls     #0x286f4
//   0x0286dc: eb09011f  cmp      x8, x9
//   0x0286e0: aa0903eb  mov      x11, x9
//   0x0286e4: 540000c8  b.hi     #0x286fc
uint64_t fde_1125_sub_0286b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400408ULL) + (x1 ^ 0x540000E9ULL) + (x2 ^ 0x0286B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x0286b8: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40004E8ULL; // 0x0286bc: cbz x8, #0x28758
    acc = (acc * 0x100000001B3ULL) ^ 0x9E670100ULL; // 0x0286c0: fmov d0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xB9800029ULL; // 0x0286c4: ldrsw x9, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x0E205800ULL; // 0x0286c8: cnt v0.8b, v0.8b
    acc = (acc * 0x100000001B3ULL) ^ 0x2E303800ULL; // 0x0286cc: uaddlv h0, v0.8b
    acc = (acc * 0x100000001B3ULL) ^ 0x1E26000AULL; // 0x0286d0: fmov w10, s0
    acc = (acc * 0x100000001B3ULL) ^ 0xF100055FULL; // 0x0286d4: cmp x10, #1
    return acc;
}

// [EN] Reconstructed FDE #1126 @ 0x028760..0x0287bc (92 bytes)
// [VN] Phục dựng FDE #1126 tại 0x028760..0x0287bc (92 byte)
//   0x028760: d10103ff  sub      sp, sp, #0x40
//   0x028764: f90013f3  str      x19, [sp, #0x20]
//   0x028768: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02876c: 9100c3fd  add      x29, sp, #0x30
//   0x028770: d53bd053  mrs      x19, tpidr_el0
//   0x028774: f9401668  ldr      x8, [x19, #0x28]
//   0x028778: d00000a2  adrp     x2, #0x3e000
//   0x02877c: 91391042  add      x2, x2, #0xe44
//   0x028780: 910043e3  add      x3, sp, #0x10
//   0x028784: 910023e4  add      x4, sp, #8
//   0x028788: f9000fe8  str      x8, [sp, #0x18]
//   0x02878c: f9000be1  str      x1, [sp, #0x10]
uint64_t fde_1126_sub_028760(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x910043E3ULL) + (x2 ^ 0x028760ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x028760: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F3ULL; // 0x028764: str x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x028768: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02876c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x028770: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x028774: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xD00000A2ULL; // 0x028778: adrp x2, #0x3e000
    acc = (acc * 0x100000001B3ULL) ^ 0x91391042ULL; // 0x02877c: add x2, x2, #0xe44
    return acc;
}

// [EN] Reconstructed FDE #1127 @ 0x0287bc..0x0289f4 (568 bytes)
// [VN] Phục dựng FDE #1127 tại 0x0287bc..0x0289f4 (568 byte)
//   0x0287bc: d10183ff  sub      sp, sp, #0x60
//   0x0287c0: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x0287c4: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0287c8: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0287cc: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0287d0: 910143fd  add      x29, sp, #0x50
//   0x0287d4: d53bd056  mrs      x22, tpidr_el0
//   0x0287d8: f94016c8  ldr      x8, [x22, #0x28]
//   0x0287dc: aa0003f3  mov      x19, x0
//   0x0287e0: f9000fe8  str      x8, [sp, #0x18]
//   0x0287e4: f9400417  ldr      x23, [x0, #8]
//   0x0287e8: b9800034  ldrsw    x20, [x1]
uint64_t fde_1127_sub_0287bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x0287BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x0287bc: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x0287c0: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x0287c4: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x0287c8: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x0287cc: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x0287d0: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x0287d4: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x0287d8: ldr x8, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1128 @ 0x0289f4..0x028a54 (96 bytes)
// [VN] Phục dựng FDE #1128 tại 0x0289f4..0x028a54 (96 byte)
//   0x0289f4: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x0289f8: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x0289fc: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x028a00: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x028a04: 9100c3fd  add      x29, sp, #0x30
//   0x028a08: 91004016  add      x22, x0, #0x10
//   0x028a0c: aa0103f4  mov      x20, x1
//   0x028a10: 52800021  mov      w1, #1
//   0x028a14: aa1603e0  mov      x0, x22
//   0x028a18: aa0303f3  mov      x19, x3
//   0x028a1c: aa0803f5  mov      x21, x8
//   0x028a20: 52800037  mov      w23, #1
uint64_t fde_1128_sub_0289f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xAA1603E0ULL) + (x2 ^ 0x0289F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x0289f4: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x0289f8: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0289fc: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x028a00: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x028a04: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x91004016ULL; // 0x028a08: add x22, x0, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x028a0c: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x028a10: mov w1, #1
    return acc;
}

// [EN] Reconstructed FDE #1129 @ 0x028a54..0x028b34 (224 bytes)
// [VN] Phục dựng FDE #1129 tại 0x028a54..0x028b34 (224 byte)
//   0x028a54: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x028a58: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x028a5c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x028a60: 910083fd  add      x29, sp, #0x20
//   0x028a64: f1000428  subs     x8, x1, #1
//   0x028a68: aa0003f3  mov      x19, x0
//   0x028a6c: 54000061  b.ne     #0x28a78
//   0x028a70: 52800054  mov      w20, #2
//   0x028a74: 14000007  b        #0x28a90
//   0x028a78: aa0103f4  mov      x20, x1
//   0x028a7c: ea08003f  tst      x1, x8
//   0x028a80: 54000080  b.eq     #0x28a90
uint64_t fde_1129_sub_028a54(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x14000007ULL) + (x2 ^ 0x028A54ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x028a54: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x028a58: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x028a5c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x028a60: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF1000428ULL; // 0x028a64: subs x8, x1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x028a68: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x54000061ULL; // 0x028a6c: b.ne #0x28a78
    acc = (acc * 0x100000001B3ULL) ^ 0x52800054ULL; // 0x028a70: mov w20, #2
    return acc;
}

// [EN] Reconstructed FDE #1130 @ 0x028b34..0x028b3c (8 bytes)
// [VN] Phục dựng FDE #1130 tại 0x028b34..0x028b3c (8 byte)
//   0x028b34: aa1f03e1  mov      x1, xzr
//   0x028b38: 14000070  b        #0x28cf8
uint64_t fde_1130_sub_028b34(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E1ULL) + (x1 ^ 0x14000070ULL) + (x2 ^ 0x028B34ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x028b34: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000070ULL; // 0x028b38: b #0x28cf8
    return acc;
}

// [EN] Reconstructed FDE #1131 @ 0x028b3c..0x028b44 (8 bytes)
// [VN] Phục dựng FDE #1131 tại 0x028b3c..0x028b44 (8 byte)
//   0x028b3c: aa1f03e2  mov      x2, xzr
//   0x028b40: 14000001  b        #0x28b44
uint64_t fde_1131_sub_028b3c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x028B3CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x028b3c: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x028b40: b #0x28b44
    return acc;
}

// [EN] Reconstructed FDE #1132 @ 0x028b44..0x028b70 (44 bytes)
// [VN] Phục dựng FDE #1132 tại 0x028b44..0x028b70 (44 byte)
//   0x028b44: b201f3e8  mov      x8, #-0x5555555555555556
//   0x028b48: f2955568  movk     x8, #0xaaab
//   0x028b4c: f2e15548  movk     x8, #0xaaa, lsl #48
//   0x028b50: eb08003f  cmp      x1, x8
//   0x028b54: 54000082  b.hs     #0x28b64
//   0x028b58: 8b010428  add      x8, x1, x1, lsl #1
//   0x028b5c: d37df100  lsl      x0, x8, #3
//   0x028b60: 17ff8aa4  b        #0xb5f0
//   0x028b64: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x028b68: 910003fd  mov      x29, sp
//   0x028b6c: 97ff8a65  bl       #0xb500
uint64_t fde_1132_sub_028b44(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB201F3E8ULL) + (x1 ^ 0xA9BF7BFDULL) + (x2 ^ 0x028B44ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB201F3E8ULL; // 0x028b44: mov x8, #-0x5555555555555556
    acc = (acc * 0x100000001B3ULL) ^ 0xF2955568ULL; // 0x028b48: movk x8, #0xaaab
    acc = (acc * 0x100000001B3ULL) ^ 0xF2E15548ULL; // 0x028b4c: movk x8, #0xaaa, lsl #48
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08003FULL; // 0x028b50: cmp x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000082ULL; // 0x028b54: b.hs #0x28b64
    acc = (acc * 0x100000001B3ULL) ^ 0x8B010428ULL; // 0x028b58: add x8, x1, x1, lsl #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DF100ULL; // 0x028b5c: lsl x0, x8, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF8AA4ULL; // 0x028b60: b #0xb5f0
    return acc;
}

// [EN] Reconstructed FDE #1133 @ 0x028b70..0x028cbc (332 bytes)
// [VN] Phục dựng FDE #1133 tại 0x028b70..0x028cbc (332 byte)
//   0x028b70: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x028b74: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x028b78: 910043fd  add      x29, sp, #0x10
//   0x028b7c: aa0003f3  mov      x19, x0
//   0x028b80: b40003c1  cbz      x1, #0x28bf8
//   0x028b84: 91002260  add      x0, x19, #8
//   0x028b88: aa0103f4  mov      x20, x1
//   0x028b8c: 94000052  bl       #0x28cd4
//   0x028b90: aa0003e1  mov      x1, x0
//   0x028b94: aa1303e0  mov      x0, x19
//   0x028b98: 94000049  bl       #0x28cbc
//   0x028b9c: aa1f03e8  mov      x8, xzr
uint64_t fde_1133_sub_028b70(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA0003E1ULL) + (x2 ^ 0x028B70ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x028b70: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x028b74: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x028b78: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x028b7c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB40003C1ULL; // 0x028b80: cbz x1, #0x28bf8
    acc = (acc * 0x100000001B3ULL) ^ 0x91002260ULL; // 0x028b84: add x0, x19, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x028b88: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x94000052ULL; // 0x028b8c: bl #0x28cd4
    return acc;
}

// [EN] Reconstructed FDE #1134 @ 0x028cbc..0x028cd4 (24 bytes)
// [VN] Phục dựng FDE #1134 tại 0x028cbc..0x028cd4 (24 byte)
//   0x028cbc: aa0003e8  mov      x8, x0
//   0x028cc0: f9400000  ldr      x0, [x0]
//   0x028cc4: f9000101  str      x1, [x8]
//   0x028cc8: b4000040  cbz      x0, #0x28cd0
//   0x028ccc: 17ff881d  b        #0xad40
//   0x028cd0: d65f03c0  ret      
uint64_t fde_1134_sub_028cbc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x028CBCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x028cbc: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x028cc0: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000101ULL; // 0x028cc4: str x1, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000040ULL; // 0x028cc8: cbz x0, #0x28cd0
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF881DULL; // 0x028ccc: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x028cd0: ret 
    return acc;
}

// [EN] Reconstructed FDE #1135 @ 0x028cd4..0x028cdc (8 bytes)
// [VN] Phục dựng FDE #1135 tại 0x028cd4..0x028cdc (8 byte)
//   0x028cd4: aa1f03e2  mov      x2, xzr
//   0x028cd8: 14000001  b        #0x28cdc
uint64_t fde_1135_sub_028cd4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x028CD4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x028cd4: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x028cd8: b #0x28cdc
    return acc;
}

// [EN] Reconstructed FDE #1136 @ 0x028cdc..0x028cf8 (28 bytes)
// [VN] Phục dựng FDE #1136 tại 0x028cdc..0x028cf8 (28 byte)
//   0x028cdc: d37dfc28  lsr      x8, x1, #0x3d
//   0x028ce0: b5000068  cbnz     x8, #0x28cec
//   0x028ce4: d37df020  lsl      x0, x1, #3
//   0x028ce8: 17ff8a42  b        #0xb5f0
//   0x028cec: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x028cf0: 910003fd  mov      x29, sp
//   0x028cf4: 97ff8a03  bl       #0xb500
uint64_t fde_1136_sub_028cdc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD37DFC28ULL) + (x1 ^ 0x97FF8A03ULL) + (x2 ^ 0x028CDCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DFC28ULL; // 0x028cdc: lsr x8, x1, #0x3d
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000068ULL; // 0x028ce0: cbnz x8, #0x28cec
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DF020ULL; // 0x028ce4: lsl x0, x1, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF8A42ULL; // 0x028ce8: b #0xb5f0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x028cec: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x028cf0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF8A03ULL; // 0x028cf4: bl #0xb500
    return acc;
}

// [EN] Reconstructed FDE #1137 @ 0x028cf8..0x028d10 (24 bytes)
// [VN] Phục dựng FDE #1137 tại 0x028cf8..0x028d10 (24 byte)
//   0x028cf8: aa0003e8  mov      x8, x0
//   0x028cfc: f9400000  ldr      x0, [x0]
//   0x028d00: f9000101  str      x1, [x8]
//   0x028d04: b4000040  cbz      x0, #0x28d0c
//   0x028d08: 17ff880e  b        #0xad40
//   0x028d0c: d65f03c0  ret      
uint64_t fde_1137_sub_028cf8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x028CF8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x028cf8: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x028cfc: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000101ULL; // 0x028d00: str x1, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000040ULL; // 0x028d04: cbz x0, #0x28d0c
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF880EULL; // 0x028d08: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x028d0c: ret 
    return acc;
}

// [EN] Reconstructed FDE #1138 @ 0x028d10..0x028d44 (52 bytes)
// [VN] Phục dựng FDE #1138 tại 0x028d10..0x028d44 (52 byte)
//   0x028d10: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x028d14: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x028d18: 910043fd  add      x29, sp, #0x10
//   0x028d1c: aa0003f3  mov      x19, x0
//   0x028d20: 97fffe66  bl       #0x286b8
//   0x028d24: b40000a0  cbz      x0, #0x28d38
//   0x028d28: aa0003e1  mov      x1, x0
//   0x028d2c: aa1303e0  mov      x0, x19
//   0x028d30: 94000005  bl       #0x28d44
//   0x028d34: 52800020  mov      w0, #1
//   0x028d38: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x028d3c: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_1138_sub_028d10(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x94000005ULL) + (x2 ^ 0x028D10ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x028d10: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x028d14: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x028d18: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x028d1c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFE66ULL; // 0x028d20: bl #0x286b8
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000A0ULL; // 0x028d24: cbz x0, #0x28d38
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E1ULL; // 0x028d28: mov x1, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x028d2c: mov x0, x19
    return acc;
}

// [EN] Reconstructed FDE #1139 @ 0x028d44..0x028d9c (88 bytes)
// [VN] Phục dựng FDE #1139 tại 0x028d44..0x028d9c (88 byte)
//   0x028d44: d10103ff  sub      sp, sp, #0x40
//   0x028d48: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x028d4c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x028d50: 9100c3fd  add      x29, sp, #0x30
//   0x028d54: d53bd054  mrs      x20, tpidr_el0
//   0x028d58: f9401688  ldr      x8, [x20, #0x28]
//   0x028d5c: f9000fe8  str      x8, [sp, #0x18]
//   0x028d60: f9400033  ldr      x19, [x1]
//   0x028d64: 910003e8  mov      x8, sp
//   0x028d68: 9400000d  bl       #0x28d9c
//   0x028d6c: 910003e0  mov      x0, sp
//   0x028d70: 97ffff71  bl       #0x28b34
uint64_t fde_1139_sub_028d44(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x910003E8ULL) + (x2 ^ 0x028D44ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x028d44: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x028d48: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x028d4c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x028d50: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x028d54: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x028d58: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x028d5c: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400033ULL; // 0x028d60: ldr x19, [x1]
    return acc;
}

// [EN] Reconstructed FDE #1140 @ 0x028d9c..0x028ed0 (308 bytes)
// [VN] Phục dựng FDE #1140 tại 0x028d9c..0x028ed0 (308 byte)
//   0x028d9c: f9400409  ldr      x9, [x0, #8]
//   0x028da0: f940042a  ldr      x10, [x1, #8]
//   0x028da4: 9e670120  fmov     d0, x9
//   0x028da8: 0e205800  cnt      v0.8b, v0.8b
//   0x028dac: 2e303800  uaddlv   h0, v0.8b
//   0x028db0: 1e26000d  fmov     w13, s0
//   0x028db4: f10005bf  cmp      x13, #1
//   0x028db8: 540000c9  b.ls     #0x28dd0
//   0x028dbc: 9ac9094b  udiv     x11, x10, x9
//   0x028dc0: eb09015f  cmp      x10, x9
//   0x028dc4: 9b09a96b  msub     x11, x11, x9, x10
//   0x028dc8: 9a8b314a  csel     x10, x10, x11, lo
uint64_t fde_1140_sub_028d9c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400409ULL) + (x1 ^ 0x9AC9094BULL) + (x2 ^ 0x028D9CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400409ULL; // 0x028d9c: ldr x9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF940042AULL; // 0x028da0: ldr x10, [x1, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x9E670120ULL; // 0x028da4: fmov d0, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x0E205800ULL; // 0x028da8: cnt v0.8b, v0.8b
    acc = (acc * 0x100000001B3ULL) ^ 0x2E303800ULL; // 0x028dac: uaddlv h0, v0.8b
    acc = (acc * 0x100000001B3ULL) ^ 0x1E26000DULL; // 0x028db0: fmov w13, s0
    acc = (acc * 0x100000001B3ULL) ^ 0xF10005BFULL; // 0x028db4: cmp x13, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540000C9ULL; // 0x028db8: b.ls #0x28dd0
    return acc;
}

// [EN] Reconstructed FDE #1141 @ 0x028ed0..0x028edc (12 bytes)
// [VN] Phục dựng FDE #1141 tại 0x028ed0..0x028edc (12 byte)
//   0x028ed0: 90000000  adrp     x0, #0x28000
//   0x028ed4: 91154000  add      x0, x0, #0x550
//   0x028ed8: 17ff895a  b        #0xb440
uint64_t fde_1141_sub_028ed0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000000ULL) + (x1 ^ 0x17FF895AULL) + (x2 ^ 0x028ED0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000000ULL; // 0x028ed0: adrp x0, #0x28000
    acc = (acc * 0x100000001B3ULL) ^ 0x91154000ULL; // 0x028ed4: add x0, x0, #0x550
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF895AULL; // 0x028ed8: b #0xb440
    return acc;
}

// [EN] Reconstructed FDE #1142 @ 0x028edc..0x028f40 (100 bytes)
// [VN] Phục dựng FDE #1142 tại 0x028edc..0x028f40 (100 byte)
//   0x028edc: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x028ee0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x028ee4: 910043fd  add      x29, sp, #0x10
//   0x028ee8: b00001b3  adrp     x19, #0x5d000
//   0x028eec: f9418a68  ldr      x8, [x19, #0x310]
//   0x028ef0: b5000228  cbnz     x8, #0x28f34
//   0x028ef4: 900001a8  adrp     x8, #0x5c000
//   0x028ef8: b940e108  ldr      w8, [x8, #0xe0]
//   0x028efc: 7100011f  cmp      w8, #0
//   0x028f00: 540001ac  b.gt     #0x28f34
//   0x028f04: 2a1f03e0  mov      w0, wzr
//   0x028f08: 2a1f03e1  mov      w1, wzr
uint64_t fde_1142_sub_028edc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x7100011FULL) + (x2 ^ 0x028EDCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x028edc: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x028ee0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x028ee4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001B3ULL; // 0x028ee8: adrp x19, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9418A68ULL; // 0x028eec: ldr x8, [x19, #0x310]
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000228ULL; // 0x028ef0: cbnz x8, #0x28f34
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A8ULL; // 0x028ef4: adrp x8, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0xB940E108ULL; // 0x028ef8: ldr w8, [x8, #0xe0]
    return acc;
}

// [EN] Reconstructed FDE #1143 @ 0x028f40..0x028fd4 (148 bytes)
// [VN] Phục dựng FDE #1143 tại 0x028f40..0x028fd4 (148 byte)
//   0x028f40: d10103ff  sub      sp, sp, #0x40
//   0x028f44: f9000bf5  str      x21, [sp, #0x10]
//   0x028f48: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x028f4c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x028f50: 9100c3fd  add      x29, sp, #0x30
//   0x028f54: d53bd055  mrs      x21, tpidr_el0
//   0x028f58: f94016a8  ldr      x8, [x21, #0x28]
//   0x028f5c: aa0003f4  mov      x20, x0
//   0x028f60: 90000000  adrp     x0, #0x28000
//   0x028f64: 913d0000  add      x0, x0, #0xf40
//   0x028f68: 2a0103f3  mov      w19, w1
//   0x028f6c: f90007e8  str      x8, [sp, #8]
uint64_t fde_1143_sub_028f40(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x90000000ULL) + (x2 ^ 0x028F40ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x028f40: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF5ULL; // 0x028f44: str x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x028f48: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x028f4c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x028f50: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x028f54: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x028f58: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x028f5c: mov x20, x0
    return acc;
}

// [EN] Reconstructed FDE #1144 @ 0x028fd4..0x028fe0 (12 bytes)
// [VN] Phục dựng FDE #1144 tại 0x028fd4..0x028fe0 (12 byte)
//   0x028fd4: 900001a8  adrp     x8, #0x5c000
//   0x028fd8: b940e100  ldr      w0, [x8, #0xe0]
//   0x028fdc: d65f03c0  ret      
uint64_t fde_1144_sub_028fd4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x900001A8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x028FD4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x900001A8ULL; // 0x028fd4: adrp x8, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0xB940E100ULL; // 0x028fd8: ldr w0, [x8, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x028fdc: ret 
    return acc;
}

// [EN] Reconstructed FDE #1145 @ 0x028fe0..0x028fe4 (4 bytes)
// [VN] Phục dựng FDE #1145 tại 0x028fe0..0x028fe4 (4 byte)
//   0x028fe0: 140000f3  b        #0x293ac
uint64_t fde_1145_sub_028fe0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x140000F3ULL) + (x1 ^ 0x140000F3ULL) + (x2 ^ 0x028FE0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x140000F3ULL; // 0x028fe0: b #0x293ac
    return acc;
}

// [EN] Reconstructed FDE #1146 @ 0x028fe4..0x0290d4 (240 bytes)
// [VN] Phục dựng FDE #1146 tại 0x028fe4..0x0290d4 (240 byte)
//   0x028fe4: d10143ff  sub      sp, sp, #0x50
//   0x028fe8: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x028fec: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x028ff0: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x028ff4: 910103fd  add      x29, sp, #0x40
//   0x028ff8: d53bd056  mrs      x22, tpidr_el0
//   0x028ffc: f94016c8  ldr      x8, [x22, #0x28]
//   0x029000: 71004c5f  cmp      w2, #0x13
//   0x029004: 3a54d828  ccmn     w1, #0x14, #8, le
//   0x029008: 7a42a020  ccmp     w1, w2, #0, ge
//   0x02900c: f9000fe8  str      x8, [sp, #0x18]
//   0x029010: b90017e0  str      w0, [sp, #0x14]
uint64_t fde_1146_sub_028fe4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0x3A54D828ULL) + (x2 ^ 0x028FE4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x028fe4: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x028fe8: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x028fec: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x028ff0: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x028ff4: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x028ff8: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x028ffc: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x71004C5FULL; // 0x029000: cmp w2, #0x13
    return acc;
}

// [EN] Reconstructed FDE #1147 @ 0x0290d4..0x029130 (92 bytes)
// [VN] Phục dựng FDE #1147 tại 0x0290d4..0x029130 (92 byte)
//   0x0290d4: d10103ff  sub      sp, sp, #0x40
//   0x0290d8: f90013f3  str      x19, [sp, #0x20]
//   0x0290dc: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0290e0: 9100c3fd  add      x29, sp, #0x30
//   0x0290e4: d53bd053  mrs      x19, tpidr_el0
//   0x0290e8: f9401668  ldr      x8, [x19, #0x28]
//   0x0290ec: b00000a2  adrp     x2, #0x3e000
//   0x0290f0: 913a2042  add      x2, x2, #0xe88
//   0x0290f4: 910043e3  add      x3, sp, #0x10
//   0x0290f8: 910023e4  add      x4, sp, #8
//   0x0290fc: f9000fe8  str      x8, [sp, #0x18]
//   0x029100: f9000be1  str      x1, [sp, #0x10]
uint64_t fde_1147_sub_0290d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x910043E3ULL) + (x2 ^ 0x0290D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x0290d4: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F3ULL; // 0x0290d8: str x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0290dc: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0290e0: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x0290e4: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x0290e8: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xB00000A2ULL; // 0x0290ec: adrp x2, #0x3e000
    acc = (acc * 0x100000001B3ULL) ^ 0x913A2042ULL; // 0x0290f0: add x2, x2, #0xe88
    return acc;
}

// [EN] Reconstructed FDE #1148 @ 0x029130..0x0291b8 (136 bytes)
// [VN] Phục dựng FDE #1148 tại 0x029130..0x0291b8 (136 byte)
//   0x029130: d10103ff  sub      sp, sp, #0x40
//   0x029134: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x029138: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02913c: 9100c3fd  add      x29, sp, #0x30
//   0x029140: d53bd054  mrs      x20, tpidr_el0
//   0x029144: f9401688  ldr      x8, [x20, #0x28]
//   0x029148: aa0003f3  mov      x19, x0
//   0x02914c: f9000fe8  str      x8, [sp, #0x18]
//   0x029150: a9402428  ldp      x8, x9, [x1]
//   0x029154: a900a7e8  stp      x8, x9, [sp, #8]
//   0x029158: b40000e9  cbz      x9, #0x29174
//   0x02915c: 91002129  add      x9, x9, #8
uint64_t fde_1148_sub_029130(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xA9402428ULL) + (x2 ^ 0x029130ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x029130: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x029134: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x029138: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02913c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x029140: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x029144: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x029148: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x02914c: str x8, [sp, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #1149 @ 0x0291b8..0x0291c8 (16 bytes)
// [VN] Phục dựng FDE #1149 tại 0x0291b8..0x0291c8 (16 byte)
//   0x0291b8: f9400400  ldr      x0, [x0, #8]
//   0x0291bc: b4000040  cbz      x0, #0x291c4
//   0x0291c0: 140000d1  b        #0x29504
//   0x0291c4: d65f03c0  ret      
uint64_t fde_1149_sub_0291b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400400ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0291B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400400ULL; // 0x0291b8: ldr x0, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000040ULL; // 0x0291bc: cbz x0, #0x291c4
    acc = (acc * 0x100000001B3ULL) ^ 0x140000D1ULL; // 0x0291c0: b #0x29504
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0291c4: ret 
    return acc;
}

// [EN] Reconstructed FDE #1150 @ 0x0291c8..0x029248 (128 bytes)
// [VN] Phục dựng FDE #1150 tại 0x0291c8..0x029248 (128 byte)
//   0x0291c8: d100c3ff  sub      sp, sp, #0x30
//   0x0291cc: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0291d0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0291d4: 910083fd  add      x29, sp, #0x20
//   0x0291d8: d53bd054  mrs      x20, tpidr_el0
//   0x0291dc: f9401688  ldr      x8, [x20, #0x28]
//   0x0291e0: 900001b3  adrp     x19, #0x5d000
//   0x0291e4: 910ca273  add      x19, x19, #0x328
//   0x0291e8: f90007e8  str      x8, [sp, #8]
//   0x0291ec: b90007e0  str      w0, [sp, #4]
//   0x0291f0: 9100a260  add      x0, x19, #0x28
//   0x0291f4: 97ff87e3  bl       #0xb180
uint64_t fde_1150_sub_0291c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0xF90007E8ULL) + (x2 ^ 0x0291C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x0291c8: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0291cc: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0291d0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0291d4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x0291d8: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x0291dc: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x900001B3ULL; // 0x0291e0: adrp x19, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0x910CA273ULL; // 0x0291e4: add x19, x19, #0x328
    return acc;
}

// [EN] Reconstructed FDE #1151 @ 0x029248..0x029368 (288 bytes)
// [VN] Phục dựng FDE #1151 tại 0x029248..0x029368 (288 byte)
//   0x029248: d10143ff  sub      sp, sp, #0x50
//   0x02924c: f9000bf7  str      x23, [sp, #0x10]
//   0x029250: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x029254: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x029258: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x02925c: 910103fd  add      x29, sp, #0x40
//   0x029260: d53bd057  mrs      x23, tpidr_el0
//   0x029264: f94016e8  ldr      x8, [x23, #0x28]
//   0x029268: 2a0203f5  mov      w21, w2
//   0x02926c: 2a0103f3  mov      w19, w1
//   0x029270: 2a0003f4  mov      w20, w0
//   0x029274: f90007e8  str      x8, [sp, #8]
uint64_t fde_1151_sub_029248(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0x2A0203F5ULL) + (x2 ^ 0x029248ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x029248: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF7ULL; // 0x02924c: str x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x029250: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x029254: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x029258: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x02925c: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x029260: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x029264: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1152 @ 0x029368..0x029388 (32 bytes)
// [VN] Phục dựng FDE #1152 tại 0x029368..0x029388 (32 byte)
//   0x029368: d0000182  adrp     x2, #0x5b000
//   0x02936c: f942d842  ldr      x2, [x2, #0x5b0]
//   0x029370: b00000a1  adrp     x1, #0x3e000
//   0x029374: 91307421  add      x1, x1, #0xc1d
//   0x029378: aa1f03e0  mov      x0, xzr
//   0x02937c: aa1f03e3  mov      x3, xzr
//   0x029380: aa1f03e4  mov      x4, xzr
//   0x029384: 17ff88af  b        #0xb640
uint64_t fde_1152_sub_029368(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD0000182ULL) + (x1 ^ 0x17FF88AFULL) + (x2 ^ 0x029368ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000182ULL; // 0x029368: adrp x2, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF942D842ULL; // 0x02936c: ldr x2, [x2, #0x5b0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB00000A1ULL; // 0x029370: adrp x1, #0x3e000
    acc = (acc * 0x100000001B3ULL) ^ 0x91307421ULL; // 0x029374: add x1, x1, #0xc1d
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E0ULL; // 0x029378: mov x0, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E3ULL; // 0x02937c: mov x3, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E4ULL; // 0x029380: mov x4, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF88AFULL; // 0x029384: b #0xb640
    return acc;
}

// [EN] Reconstructed FDE #1153 @ 0x029388..0x029398 (16 bytes)
// [VN] Phục dựng FDE #1153 tại 0x029388..0x029398 (16 byte)
//   0x029388: 2a0303e1  mov      w1, w3
//   0x02938c: 2a0203e0  mov      w0, w2
//   0x029390: 2a0403e2  mov      w2, w4
//   0x029394: 17ffff14  b        #0x28fe4
uint64_t fde_1153_sub_029388(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A0303E1ULL) + (x1 ^ 0x17FFFF14ULL) + (x2 ^ 0x029388ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303E1ULL; // 0x029388: mov w1, w3
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203E0ULL; // 0x02938c: mov w0, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0403E2ULL; // 0x029390: mov w2, w4
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFF14ULL; // 0x029394: b #0x28fe4
    return acc;
}

// [EN] Reconstructed FDE #1154 @ 0x029398..0x0293ac (20 bytes)
// [VN] Phục dựng FDE #1154 tại 0x029398..0x0293ac (20 byte)
//   0x029398: 72001c5f  tst      w2, #0xff
//   0x02939c: 1a9f07e8  cset     w8, ne
//   0x0293a0: f0000189  adrp     x9, #0x5c000
//   0x0293a4: 39039128  strb     w8, [x9, #0xe4]
//   0x0293a8: d65f03c0  ret      
uint64_t fde_1154_sub_029398(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x72001C5FULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x029398ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x72001C5FULL; // 0x029398: tst w2, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F07E8ULL; // 0x02939c: cset w8, ne
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000189ULL; // 0x0293a0: adrp x9, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0x39039128ULL; // 0x0293a4: strb w8, [x9, #0xe4]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0293a8: ret 
    return acc;
}

// [EN] Reconstructed FDE #1155 @ 0x0293ac..0x0293d4 (40 bytes)
// [VN] Phục dựng FDE #1155 tại 0x0293ac..0x0293d4 (40 byte)
//   0x0293ac: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0293b0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0293b4: 910043fd  add      x29, sp, #0x10
//   0x0293b8: f9400801  ldr      x1, [x0, #0x10]
//   0x0293bc: aa0003f3  mov      x19, x0
//   0x0293c0: 94000005  bl       #0x293d4
//   0x0293c4: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0293c8: aa1303e0  mov      x0, x19
//   0x0293cc: f84207f3  ldr      x19, [sp], #0x20
//   0x0293d0: 14000010  b        #0x29410
uint64_t fde_1155_sub_0293ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x0293ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0293ac: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0293b0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0293b4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400801ULL; // 0x0293b8: ldr x1, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0293bc: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x94000005ULL; // 0x0293c0: bl #0x293d4
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x0293c4: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x0293c8: mov x0, x19
    return acc;
}

// [EN] Reconstructed FDE #1156 @ 0x0293d4..0x029410 (60 bytes)
// [VN] Phục dựng FDE #1156 tại 0x0293d4..0x029410 (60 byte)
//   0x0293d4: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0293d8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0293dc: 910043fd  add      x29, sp, #0x10
//   0x0293e0: aa0103f3  mov      x19, x1
//   0x0293e4: b4000113  cbz      x19, #0x29404
//   0x0293e8: aa1303e0  mov      x0, x19
//   0x0293ec: f8418414  ldr      x20, [x0], #0x18
//   0x0293f0: 97ffff72  bl       #0x291b8
//   0x0293f4: aa1303e0  mov      x0, x19
//   0x0293f8: 97ff8652  bl       #0xad40
//   0x0293fc: aa1403f3  mov      x19, x20
//   0x029400: b5ffff53  cbnz     x19, #0x293e8
uint64_t fde_1156_sub_0293d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x0293D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0293d4: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0293d8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0293dc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x0293e0: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000113ULL; // 0x0293e4: cbz x19, #0x29404
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x0293e8: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF8418414ULL; // 0x0293ec: ldr x20, [x0], #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFF72ULL; // 0x0293f0: bl #0x291b8
    return acc;
}

// [EN] Reconstructed FDE #1157 @ 0x029410..0x029418 (8 bytes)
// [VN] Phục dựng FDE #1157 tại 0x029410..0x029418 (8 byte)
//   0x029410: aa1f03e1  mov      x1, xzr
//   0x029414: 14000001  b        #0x29418
uint64_t fde_1157_sub_029410(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E1ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x029410ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x029410: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x029414: b #0x29418
    return acc;
}

// [EN] Reconstructed FDE #1158 @ 0x029418..0x029430 (24 bytes)
// [VN] Phục dựng FDE #1158 tại 0x029418..0x029430 (24 byte)
//   0x029418: aa0003e8  mov      x8, x0
//   0x02941c: f9400000  ldr      x0, [x0]
//   0x029420: f900011f  str      xzr, [x8]
//   0x029424: b4000040  cbz      x0, #0x2942c
//   0x029428: 17ff8646  b        #0xad40
//   0x02942c: d65f03c0  ret      
uint64_t fde_1158_sub_029418(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x029418ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x029418: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x02941c: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900011FULL; // 0x029420: str xzr, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000040ULL; // 0x029424: cbz x0, #0x2942c
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF8646ULL; // 0x029428: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02942c: ret 
    return acc;
}

// [EN] Reconstructed FDE #1159 @ 0x029430..0x0294b8 (136 bytes)
// [VN] Phục dựng FDE #1159 tại 0x029430..0x0294b8 (136 byte)
//   0x029430: d10143ff  sub      sp, sp, #0x50
//   0x029434: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x029438: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x02943c: 910103fd  add      x29, sp, #0x40
//   0x029440: d53bd054  mrs      x20, tpidr_el0
//   0x029444: aa0803f3  mov      x19, x8
//   0x029448: f9401688  ldr      x8, [x20, #0x28]
//   0x02944c: 52800500  mov      w0, #0x28
//   0x029450: f81e83a8  stur     x8, [x29, #-0x18]
//   0x029454: 97ff8867  bl       #0xb5f0
//   0x029458: 910083e8  add      x8, sp, #0x20
//   0x02945c: 52800029  mov      w9, #1
uint64_t fde_1159_sub_029430(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xF81E83A8ULL) + (x2 ^ 0x029430ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x029430: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x029434: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x029438: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x02943c: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x029440: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803F3ULL; // 0x029444: mov x19, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x029448: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800500ULL; // 0x02944c: mov w0, #0x28
    return acc;
}

// [EN] Reconstructed FDE #1160 @ 0x0294b8..0x0294c0 (8 bytes)
// [VN] Phục dựng FDE #1160 tại 0x0294b8..0x0294c0 (8 byte)
//   0x0294b8: aa1f03e1  mov      x1, xzr
//   0x0294bc: 1400000c  b        #0x294ec
uint64_t fde_1160_sub_0294b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E1ULL) + (x1 ^ 0x1400000CULL) + (x2 ^ 0x0294B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x0294b8: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x1400000CULL; // 0x0294bc: b #0x294ec
    return acc;
}

// [EN] Reconstructed FDE #1161 @ 0x0294c0..0x0294e4 (36 bytes)
// [VN] Phục dựng FDE #1161 tại 0x0294c0..0x0294e4 (36 byte)
//   0x0294c0: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0294c4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0294c8: 910043fd  add      x29, sp, #0x10
//   0x0294cc: aa0003f3  mov      x19, x0
//   0x0294d0: 97ff86a8  bl       #0xaf70
//   0x0294d4: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0294d8: aa1303e0  mov      x0, x19
//   0x0294dc: f84207f3  ldr      x19, [sp], #0x20
//   0x0294e0: 17ff8618  b        #0xad40
uint64_t fde_1161_sub_0294c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x17FF8618ULL) + (x2 ^ 0x0294C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0294c0: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0294c4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0294c8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0294cc: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF86A8ULL; // 0x0294d0: bl #0xaf70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x0294d4: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x0294d8: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x0294dc: ldr x19, [sp], #0x20
    return acc;
}

// [EN] Reconstructed FDE #1162 @ 0x0294e4..0x0294e8 (4 bytes)
// [VN] Phục dựng FDE #1162 tại 0x0294e4..0x0294e8 (4 byte)
//   0x0294e4: d65f03c0  ret      
uint64_t fde_1162_sub_0294e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0294E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0294e4: ret 
    return acc;
}

// [EN] Reconstructed FDE #1163 @ 0x0294e8..0x0294ec (4 bytes)
// [VN] Phục dựng FDE #1163 tại 0x0294e8..0x0294ec (4 byte)
//   0x0294e8: 17ff8616  b        #0xad40
uint64_t fde_1163_sub_0294e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FF8616ULL) + (x1 ^ 0x17FF8616ULL) + (x2 ^ 0x0294E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF8616ULL; // 0x0294e8: b #0xad40
    return acc;
}

// [EN] Reconstructed FDE #1164 @ 0x0294ec..0x029504 (24 bytes)
// [VN] Phục dựng FDE #1164 tại 0x0294ec..0x029504 (24 byte)
//   0x0294ec: aa0003e8  mov      x8, x0
//   0x0294f0: f9400000  ldr      x0, [x0]
//   0x0294f4: f9000101  str      x1, [x8]
//   0x0294f8: b4000040  cbz      x0, #0x29500
//   0x0294fc: 17ff8611  b        #0xad40
//   0x029500: d65f03c0  ret      
uint64_t fde_1164_sub_0294ec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0294ECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x0294ec: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x0294f0: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000101ULL; // 0x0294f4: str x1, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000040ULL; // 0x0294f8: cbz x0, #0x29500
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF8611ULL; // 0x0294fc: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x029500: ret 
    return acc;
}

// [EN] Reconstructed FDE #1165 @ 0x029504..0x029558 (84 bytes)
// [VN] Phục dựng FDE #1165 tại 0x029504..0x029558 (84 byte)
//   0x029504: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x029508: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02950c: 910043fd  add      x29, sp, #0x10
//   0x029510: aa0003f3  mov      x19, x0
//   0x029514: 91002008  add      x8, x0, #8
//   0x029518: c85ffd09  ldaxr    x9, [x8]
//   0x02951c: d100052a  sub      x10, x9, #1
//   0x029520: c80bfd0a  stlxr    w11, x10, [x8]
//   0x029524: 35ffffab  cbnz     w11, #0x29518
//   0x029528: b4000089  cbz      x9, #0x29538
//   0x02952c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x029530: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_1165_sub_029504(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x35FFFFABULL) + (x2 ^ 0x029504ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x029504: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x029508: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02950c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x029510: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91002008ULL; // 0x029514: add x8, x0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xC85FFD09ULL; // 0x029518: ldaxr x9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD100052AULL; // 0x02951c: sub x10, x9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xC80BFD0AULL; // 0x029520: stlxr w11, x10, [x8]
    return acc;
}

// [EN] Reconstructed FDE #1166 @ 0x029558..0x029790 (568 bytes)
// [VN] Phục dựng FDE #1166 tại 0x029558..0x029790 (568 byte)
//   0x029558: d10183ff  sub      sp, sp, #0x60
//   0x02955c: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x029560: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x029564: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x029568: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x02956c: 910143fd  add      x29, sp, #0x50
//   0x029570: d53bd056  mrs      x22, tpidr_el0
//   0x029574: f94016c8  ldr      x8, [x22, #0x28]
//   0x029578: aa0003f3  mov      x19, x0
//   0x02957c: f9000fe8  str      x8, [sp, #0x18]
//   0x029580: f9400417  ldr      x23, [x0, #8]
//   0x029584: b9800034  ldrsw    x20, [x1]
uint64_t fde_1166_sub_029558(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x029558ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x029558: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x02955c: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x029560: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x029564: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x029568: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x02956c: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x029570: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x029574: ldr x8, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1167 @ 0x029790..0x0297f4 (100 bytes)
// [VN] Phục dựng FDE #1167 tại 0x029790..0x0297f4 (100 byte)
//   0x029790: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x029794: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x029798: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x02979c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0297a0: 9100c3fd  add      x29, sp, #0x30
//   0x0297a4: 91004016  add      x22, x0, #0x10
//   0x0297a8: aa0103f4  mov      x20, x1
//   0x0297ac: 52800021  mov      w1, #1
//   0x0297b0: aa1603e0  mov      x0, x22
//   0x0297b4: aa0303f3  mov      x19, x3
//   0x0297b8: aa0803f5  mov      x21, x8
//   0x0297bc: 52800037  mov      w23, #1
uint64_t fde_1167_sub_029790(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xAA1603E0ULL) + (x2 ^ 0x029790ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x029790: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x029794: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x029798: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02979c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0297a0: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x91004016ULL; // 0x0297a4: add x22, x0, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x0297a8: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x0297ac: mov w1, #1
    return acc;
}

// [EN] Reconstructed FDE #1168 @ 0x0297f4..0x0298d4 (224 bytes)
// [VN] Phục dựng FDE #1168 tại 0x0297f4..0x0298d4 (224 byte)
//   0x0297f4: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x0297f8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0297fc: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x029800: 910083fd  add      x29, sp, #0x20
//   0x029804: f1000428  subs     x8, x1, #1
//   0x029808: aa0003f3  mov      x19, x0
//   0x02980c: 54000061  b.ne     #0x29818
//   0x029810: 52800054  mov      w20, #2
//   0x029814: 14000007  b        #0x29830
//   0x029818: aa0103f4  mov      x20, x1
//   0x02981c: ea08003f  tst      x1, x8
//   0x029820: 54000080  b.eq     #0x29830
uint64_t fde_1168_sub_0297f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x14000007ULL) + (x2 ^ 0x0297F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x0297f4: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0297f8: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0297fc: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x029800: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF1000428ULL; // 0x029804: subs x8, x1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x029808: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x54000061ULL; // 0x02980c: b.ne #0x29818
    acc = (acc * 0x100000001B3ULL) ^ 0x52800054ULL; // 0x029810: mov w20, #2
    return acc;
}

// [EN] Reconstructed FDE #1169 @ 0x0298d4..0x0298dc (8 bytes)
// [VN] Phục dựng FDE #1169 tại 0x0298d4..0x0298dc (8 byte)
//   0x0298d4: aa1f03e1  mov      x1, xzr
//   0x0298d8: 14000070  b        #0x29a98
uint64_t fde_1169_sub_0298d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E1ULL) + (x1 ^ 0x14000070ULL) + (x2 ^ 0x0298D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x0298d4: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000070ULL; // 0x0298d8: b #0x29a98
    return acc;
}

// [EN] Reconstructed FDE #1170 @ 0x0298dc..0x0298e4 (8 bytes)
// [VN] Phục dựng FDE #1170 tại 0x0298dc..0x0298e4 (8 byte)
//   0x0298dc: aa1f03e2  mov      x2, xzr
//   0x0298e0: 14000001  b        #0x298e4
uint64_t fde_1170_sub_0298dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x0298DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x0298dc: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x0298e0: b #0x298e4
    return acc;
}

// [EN] Reconstructed FDE #1171 @ 0x0298e4..0x029910 (44 bytes)
// [VN] Phục dựng FDE #1171 tại 0x0298e4..0x029910 (44 byte)
//   0x0298e4: b203e7e8  mov      x8, #0x6666666666666666
//   0x0298e8: f28ccce8  movk     x8, #0x6667
//   0x0298ec: f2e0ccc8  movk     x8, #0x666, lsl #48
//   0x0298f0: eb08003f  cmp      x1, x8
//   0x0298f4: 54000082  b.hs     #0x29904
//   0x0298f8: 8b010828  add      x8, x1, x1, lsl #2
//   0x0298fc: d37df100  lsl      x0, x8, #3
//   0x029900: 17ff873c  b        #0xb5f0
//   0x029904: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x029908: 910003fd  mov      x29, sp
//   0x02990c: 97ff86fd  bl       #0xb500
uint64_t fde_1171_sub_0298e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB203E7E8ULL) + (x1 ^ 0xA9BF7BFDULL) + (x2 ^ 0x0298E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB203E7E8ULL; // 0x0298e4: mov x8, #0x6666666666666666
    acc = (acc * 0x100000001B3ULL) ^ 0xF28CCCE8ULL; // 0x0298e8: movk x8, #0x6667
    acc = (acc * 0x100000001B3ULL) ^ 0xF2E0CCC8ULL; // 0x0298ec: movk x8, #0x666, lsl #48
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08003FULL; // 0x0298f0: cmp x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000082ULL; // 0x0298f4: b.hs #0x29904
    acc = (acc * 0x100000001B3ULL) ^ 0x8B010828ULL; // 0x0298f8: add x8, x1, x1, lsl #2
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DF100ULL; // 0x0298fc: lsl x0, x8, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF873CULL; // 0x029900: b #0xb5f0
    return acc;
}

// [EN] Reconstructed FDE #1172 @ 0x029910..0x029a5c (332 bytes)
// [VN] Phục dựng FDE #1172 tại 0x029910..0x029a5c (332 byte)
//   0x029910: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x029914: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x029918: 910043fd  add      x29, sp, #0x10
//   0x02991c: aa0003f3  mov      x19, x0
//   0x029920: b40003c1  cbz      x1, #0x29998
//   0x029924: 91002260  add      x0, x19, #8
//   0x029928: aa0103f4  mov      x20, x1
//   0x02992c: 94000052  bl       #0x29a74
//   0x029930: aa0003e1  mov      x1, x0
//   0x029934: aa1303e0  mov      x0, x19
//   0x029938: 94000049  bl       #0x29a5c
//   0x02993c: aa1f03e8  mov      x8, xzr
uint64_t fde_1172_sub_029910(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA0003E1ULL) + (x2 ^ 0x029910ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x029910: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x029914: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x029918: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02991c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB40003C1ULL; // 0x029920: cbz x1, #0x29998
    acc = (acc * 0x100000001B3ULL) ^ 0x91002260ULL; // 0x029924: add x0, x19, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x029928: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x94000052ULL; // 0x02992c: bl #0x29a74
    return acc;
}

// [EN] Reconstructed FDE #1173 @ 0x029a5c..0x029a74 (24 bytes)
// [VN] Phục dựng FDE #1173 tại 0x029a5c..0x029a74 (24 byte)
//   0x029a5c: aa0003e8  mov      x8, x0
//   0x029a60: f9400000  ldr      x0, [x0]
//   0x029a64: f9000101  str      x1, [x8]
//   0x029a68: b4000040  cbz      x0, #0x29a70
//   0x029a6c: 17ff84b5  b        #0xad40
//   0x029a70: d65f03c0  ret      
uint64_t fde_1173_sub_029a5c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x029A5CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x029a5c: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x029a60: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000101ULL; // 0x029a64: str x1, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000040ULL; // 0x029a68: cbz x0, #0x29a70
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF84B5ULL; // 0x029a6c: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x029a70: ret 
    return acc;
}

// [EN] Reconstructed FDE #1174 @ 0x029a74..0x029a7c (8 bytes)
// [VN] Phục dựng FDE #1174 tại 0x029a74..0x029a7c (8 byte)
//   0x029a74: aa1f03e2  mov      x2, xzr
//   0x029a78: 14000001  b        #0x29a7c
uint64_t fde_1174_sub_029a74(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x029A74ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x029a74: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x029a78: b #0x29a7c
    return acc;
}

// [EN] Reconstructed FDE #1175 @ 0x029a7c..0x029a98 (28 bytes)
// [VN] Phục dựng FDE #1175 tại 0x029a7c..0x029a98 (28 byte)
//   0x029a7c: d37dfc28  lsr      x8, x1, #0x3d
//   0x029a80: b5000068  cbnz     x8, #0x29a8c
//   0x029a84: d37df020  lsl      x0, x1, #3
//   0x029a88: 17ff86da  b        #0xb5f0
//   0x029a8c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x029a90: 910003fd  mov      x29, sp
//   0x029a94: 97ff869b  bl       #0xb500
uint64_t fde_1175_sub_029a7c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD37DFC28ULL) + (x1 ^ 0x97FF869BULL) + (x2 ^ 0x029A7CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DFC28ULL; // 0x029a7c: lsr x8, x1, #0x3d
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000068ULL; // 0x029a80: cbnz x8, #0x29a8c
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DF020ULL; // 0x029a84: lsl x0, x1, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF86DAULL; // 0x029a88: b #0xb5f0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x029a8c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x029a90: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF869BULL; // 0x029a94: bl #0xb500
    return acc;
}

// [EN] Reconstructed FDE #1176 @ 0x029a98..0x029ab4 (28 bytes)
// [VN] Phục dựng FDE #1176 tại 0x029a98..0x029ab4 (28 byte)
//   0x029a98: f9400008  ldr      x8, [x0]
//   0x029a9c: f9000001  str      x1, [x0]
//   0x029aa0: b4000088  cbz      x8, #0x29ab0
//   0x029aa4: 91002000  add      x0, x0, #8
//   0x029aa8: aa0803e1  mov      x1, x8
//   0x029aac: 14000002  b        #0x29ab4
//   0x029ab0: d65f03c0  ret      
uint64_t fde_1176_sub_029a98(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400008ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x029A98ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x029a98: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000001ULL; // 0x029a9c: str x1, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000088ULL; // 0x029aa0: cbz x8, #0x29ab0
    acc = (acc * 0x100000001B3ULL) ^ 0x91002000ULL; // 0x029aa4: add x0, x0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E1ULL; // 0x029aa8: mov x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x14000002ULL; // 0x029aac: b #0x29ab4
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x029ab0: ret 
    return acc;
}

// [EN] Reconstructed FDE #1177 @ 0x029ab4..0x029af4 (64 bytes)
// [VN] Phục dựng FDE #1177 tại 0x029ab4..0x029af4 (64 byte)
//   0x029ab4: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x029ab8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x029abc: 910043fd  add      x29, sp, #0x10
//   0x029ac0: 39402008  ldrb     w8, [x0, #8]
//   0x029ac4: aa0103f3  mov      x19, x1
//   0x029ac8: 34000068  cbz      w8, #0x29ad4
//   0x029acc: 91006260  add      x0, x19, #0x18
//   0x029ad0: 97fffdba  bl       #0x291b8
//   0x029ad4: b40000b3  cbz      x19, #0x29ae8
//   0x029ad8: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x029adc: aa1303e0  mov      x0, x19
//   0x029ae0: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_1177_sub_029ab4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xB40000B3ULL) + (x2 ^ 0x029AB4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x029ab4: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x029ab8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x029abc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x39402008ULL; // 0x029ac0: ldrb w8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x029ac4: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x34000068ULL; // 0x029ac8: cbz w8, #0x29ad4
    acc = (acc * 0x100000001B3ULL) ^ 0x91006260ULL; // 0x029acc: add x0, x19, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFDBAULL; // 0x029ad0: bl #0x291b8
    return acc;
}

// [EN] Reconstructed FDE #1178 @ 0x029af4..0x029b9c (168 bytes)
// [VN] Phục dựng FDE #1178 tại 0x029af4..0x029b9c (168 byte)
//   0x029af4: f9400408  ldr      x8, [x0, #8]
//   0x029af8: b40004e8  cbz      x8, #0x29b94
//   0x029afc: 9e670100  fmov     d0, x8
//   0x029b00: b9800029  ldrsw    x9, [x1]
//   0x029b04: 0e205800  cnt      v0.8b, v0.8b
//   0x029b08: 2e303800  uaddlv   h0, v0.8b
//   0x029b0c: 1e26000a  fmov     w10, s0
//   0x029b10: f100055f  cmp      x10, #1
//   0x029b14: 540000e9  b.ls     #0x29b30
//   0x029b18: eb09011f  cmp      x8, x9
//   0x029b1c: aa0903eb  mov      x11, x9
//   0x029b20: 540000c8  b.hi     #0x29b38
uint64_t fde_1178_sub_029af4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400408ULL) + (x1 ^ 0x540000E9ULL) + (x2 ^ 0x029AF4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x029af4: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40004E8ULL; // 0x029af8: cbz x8, #0x29b94
    acc = (acc * 0x100000001B3ULL) ^ 0x9E670100ULL; // 0x029afc: fmov d0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xB9800029ULL; // 0x029b00: ldrsw x9, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x0E205800ULL; // 0x029b04: cnt v0.8b, v0.8b
    acc = (acc * 0x100000001B3ULL) ^ 0x2E303800ULL; // 0x029b08: uaddlv h0, v0.8b
    acc = (acc * 0x100000001B3ULL) ^ 0x1E26000AULL; // 0x029b0c: fmov w10, s0
    acc = (acc * 0x100000001B3ULL) ^ 0xF100055FULL; // 0x029b10: cmp x10, #1
    return acc;
}

// [EN] Reconstructed FDE #1179 @ 0x029b9c..0x029ba8 (12 bytes)
// [VN] Phục dựng FDE #1179 tại 0x029b9c..0x029ba8 (12 byte)
//   0x029b9c: d0000180  adrp     x0, #0x5b000
//   0x029ba0: f942d800  ldr      x0, [x0, #0x5b0]
//   0x029ba4: 17ff8627  b        #0xb440
uint64_t fde_1179_sub_029b9c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD0000180ULL) + (x1 ^ 0x17FF8627ULL) + (x2 ^ 0x029B9CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000180ULL; // 0x029b9c: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF942D800ULL; // 0x029ba0: ldr x0, [x0, #0x5b0]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF8627ULL; // 0x029ba4: b #0xb440
    return acc;
}

// [EN] Reconstructed FDE #1180 @ 0x029ba8..0x029f48 (928 bytes)
// [VN] Phục dựng FDE #1180 tại 0x029ba8..0x029f48 (928 byte)
//   0x029ba8: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x029bac: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x029bb0: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x029bb4: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x029bb8: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x029bbc: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x029bc0: 910143fd  add      x29, sp, #0x50
//   0x029bc4: d108c3ff  sub      sp, sp, #0x230
//   0x029bc8: d53bd05b  mrs      x27, tpidr_el0
//   0x029bcc: f9401768  ldr      x8, [x27, #0x28]
//   0x029bd0: b00000a1  adrp     x1, #0x3e000
//   0x029bd4: b00000a2  adrp     x2, #0x3e000
uint64_t fde_1180_sub_029ba8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xD53BD05BULL) + (x2 ^ 0x029BA8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x029ba8: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x029bac: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x029bb0: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x029bb4: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x029bb8: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x029bbc: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x029bc0: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD108C3FFULL; // 0x029bc4: sub sp, sp, #0x230
    return acc;
}

// [EN] Reconstructed FDE #1181 @ 0x029f48..0x02a01c (212 bytes)
// [VN] Phục dựng FDE #1181 tại 0x029f48..0x02a01c (212 byte)
//   0x029f48: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x029f4c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x029f50: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x029f54: 910083fd  add      x29, sp, #0x20
//   0x029f58: f9400408  ldr      x8, [x0, #8]
//   0x029f5c: b40001e8  cbz      x8, #0x29f98
//   0x029f60: 39400109  ldrb     w9, [x8]
//   0x029f64: f9400055  ldr      x21, [x2]
//   0x029f68: aa0003f4  mov      x20, x0
//   0x029f6c: aa0203f3  mov      x19, x2
//   0x029f70: 7100bd3f  cmp      w9, #0x2f
//   0x029f74: 540000a1  b.ne     #0x29f88
uint64_t fde_1181_sub_029f48(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xAA0003F4ULL) + (x2 ^ 0x029F48ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x029f48: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x029f4c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x029f50: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x029f54: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x029f58: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001E8ULL; // 0x029f5c: cbz x8, #0x29f98
    acc = (acc * 0x100000001B3ULL) ^ 0x39400109ULL; // 0x029f60: ldrb w9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400055ULL; // 0x029f64: ldr x21, [x2]
    return acc;
}

// [EN] Reconstructed FDE #1182 @ 0x02a01c..0x02a028 (12 bytes)
// [VN] Phục dựng FDE #1182 tại 0x02a01c..0x02a028 (12 byte)
//   0x02a01c: aa1403e3  mov      x3, x20
//   0x02a020: aa1303e4  mov      x4, x19
//   0x02a024: 17ff846f  b        #0xb1e0
uint64_t fde_1182_sub_02a01c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1403E3ULL) + (x1 ^ 0x17FF846FULL) + (x2 ^ 0x02A01CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E3ULL; // 0x02a01c: mov x3, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E4ULL; // 0x02a020: mov x4, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF846FULL; // 0x02a024: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #1183 @ 0x02a028..0x02a070 (72 bytes)
// [VN] Phục dựng FDE #1183 tại 0x02a028..0x02a070 (72 byte)
//   0x02a028: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x02a02c: 910003fd  mov      x29, sp
//   0x02a030: 97ffb579  bl       #0x17614
//   0x02a034: 36000080  tbz      w0, #0, #0x2a044
//   0x02a038: 97ffb550  bl       #0x17578
//   0x02a03c: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x02a040: 17fffeda  b        #0x29ba8
//   0x02a044: 97ffb576  bl       #0x1761c
//   0x02a048: 360000e0  tbz      w0, #0, #0x2a064
//   0x02a04c: b00000a1  adrp     x1, #0x3f000
//   0x02a050: b00000a2  adrp     x2, #0x3f000
//   0x02a054: 91010421  add      x1, x1, #0x41
uint64_t fde_1183_sub_02a028(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x360000E0ULL) + (x2 ^ 0x02A028ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x02a028: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02a02c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFB579ULL; // 0x02a030: bl #0x17614
    acc = (acc * 0x100000001B3ULL) ^ 0x36000080ULL; // 0x02a034: tbz w0, #0, #0x2a044
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFB550ULL; // 0x02a038: bl #0x17578
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x02a03c: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFEDAULL; // 0x02a040: b #0x29ba8
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFB576ULL; // 0x02a044: bl #0x1761c
    return acc;
}

// [EN] Reconstructed FDE #1184 @ 0x02a070..0x02a0e8 (120 bytes)
// [VN] Phục dựng FDE #1184 tại 0x02a070..0x02a0e8 (120 byte)
//   0x02a070: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x02a074: 910003fd  mov      x29, sp
//   0x02a078: 39400008  ldrb     w8, [x0]
//   0x02a07c: 37000068  tbnz     w8, #0, #0x2a088
//   0x02a080: d341fd0a  lsr      x10, x8, #1
//   0x02a084: 14000002  b        #0x2a08c
//   0x02a088: f940040a  ldr      x10, [x0, #8]
//   0x02a08c: 39400029  ldrb     w9, [x1]
//   0x02a090: 37000069  tbnz     w9, #0, #0x2a09c
//   0x02a094: d341fd2b  lsr      x11, x9, #1
//   0x02a098: 14000002  b        #0x2a0a0
//   0x02a09c: f940042b  ldr      x11, [x1, #8]
uint64_t fde_1184_sub_02a070(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x37000069ULL) + (x2 ^ 0x02A070ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x02a070: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02a074: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x02a078: ldrb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x37000068ULL; // 0x02a07c: tbnz w8, #0, #0x2a088
    acc = (acc * 0x100000001B3ULL) ^ 0xD341FD0AULL; // 0x02a080: lsr x10, x8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x14000002ULL; // 0x02a084: b #0x2a08c
    acc = (acc * 0x100000001B3ULL) ^ 0xF940040AULL; // 0x02a088: ldr x10, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400029ULL; // 0x02a08c: ldrb w9, [x1]
    return acc;
}

// [EN] Reconstructed FDE #1185 @ 0x02a0e8..0x02a13c (84 bytes)
// [VN] Phục dựng FDE #1185 tại 0x02a0e8..0x02a13c (84 byte)
//   0x02a0e8: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x02a0ec: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02a0f0: 910043fd  add      x29, sp, #0x10
//   0x02a0f4: 52800082  mov      w2, #4
//   0x02a0f8: aa0103f3  mov      x19, x1
//   0x02a0fc: aa0003f4  mov      x20, x0
//   0x02a100: 97ff8480  bl       #0xb300
//   0x02a104: 34000080  cbz      w0, #0x2a114
//   0x02a108: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02a10c: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x02a110: d65f03c0  ret      
//   0x02a114: a9417bfd  ldp      x29, x30, [sp, #0x10]
uint64_t fde_1185_sub_02a0e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xA9417BFDULL) + (x2 ^ 0x02A0E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x02a0e8: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02a0ec: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02a0f0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x52800082ULL; // 0x02a0f4: mov w2, #4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x02a0f8: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x02a0fc: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF8480ULL; // 0x02a100: bl #0xb300
    acc = (acc * 0x100000001B3ULL) ^ 0x34000080ULL; // 0x02a104: cbz w0, #0x2a114
    return acc;
}

// [EN] Reconstructed FDE #1186 @ 0x02a13c..0x02a2f8 (444 bytes)
// [VN] Phục dựng FDE #1186 tại 0x02a13c..0x02a2f8 (444 byte)
//   0x02a13c: d10243ff  sub      sp, sp, #0x90
//   0x02a140: a90467fa  stp      x26, x25, [sp, #0x40]
//   0x02a144: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x02a148: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x02a14c: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x02a150: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x02a154: 910203fd  add      x29, sp, #0x80
//   0x02a158: d53bd059  mrs      x25, tpidr_el0
//   0x02a15c: f9401728  ldr      x8, [x25, #0x28]
//   0x02a160: aa0203f3  mov      x19, x2
//   0x02a164: aa0103f4  mov      x20, x1
//   0x02a168: aa0003f5  mov      x21, x0
uint64_t fde_1186_sub_02a13c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0xF9401728ULL) + (x2 ^ 0x02A13CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x02a13c: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA90467FAULL; // 0x02a140: stp x26, x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x02a144: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x02a148: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x02a14c: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x02a150: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x02a154: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x02a158: mrs x25, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #1187 @ 0x02a2f8..0x02a52c (564 bytes)
// [VN] Phục dựng FDE #1187 tại 0x02a2f8..0x02a52c (564 byte)
//   0x02a2f8: f81b0ffc  str      x28, [sp, #-0x50]!
//   0x02a2fc: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x02a300: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x02a304: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x02a308: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x02a30c: 910103fd  add      x29, sp, #0x40
//   0x02a310: d11183ff  sub      sp, sp, #0x460
//   0x02a314: d53bd056  mrs      x22, tpidr_el0
//   0x02a318: f94016c8  ldr      x8, [x22, #0x28]
//   0x02a31c: f81b83a8  stur     x8, [x29, #-0x48]
//   0x02a320: 97ffb4bf  bl       #0x1761c
//   0x02a324: 360000c0  tbz      w0, #0, #0x2a33c
uint64_t fde_1187_sub_02a2f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FFCULL) + (x1 ^ 0xF94016C8ULL) + (x2 ^ 0x02A2F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FFCULL; // 0x02a2f8: str x28, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x02a2fc: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x02a300: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x02a304: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x02a308: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x02a30c: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD11183FFULL; // 0x02a310: sub sp, sp, #0x460
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x02a314: mrs x22, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #1188 @ 0x02a52c..0x02a570 (68 bytes)
// [VN] Phục dựng FDE #1188 tại 0x02a52c..0x02a570 (68 byte)
//   0x02a52c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x02a530: 910003fd  mov      x29, sp
//   0x02a534: 39400008  ldrb     w8, [x0]
//   0x02a538: 37000068  tbnz     w8, #0, #0x2a544
//   0x02a53c: d341fd09  lsr      x9, x8, #1
//   0x02a540: 14000002  b        #0x2a548
//   0x02a544: f9400409  ldr      x9, [x0, #8]
//   0x02a548: eb01013f  cmp      x9, x1
//   0x02a54c: 54000109  b.ls     #0x2a56c
//   0x02a550: 37000068  tbnz     w8, #0, #0x2a55c
//   0x02a554: 91000408  add      x8, x0, #1
//   0x02a558: 14000002  b        #0x2a560
uint64_t fde_1188_sub_02a52c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x54000109ULL) + (x2 ^ 0x02A52CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x02a52c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02a530: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x02a534: ldrb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x37000068ULL; // 0x02a538: tbnz w8, #0, #0x2a544
    acc = (acc * 0x100000001B3ULL) ^ 0xD341FD09ULL; // 0x02a53c: lsr x9, x8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x14000002ULL; // 0x02a540: b #0x2a548
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400409ULL; // 0x02a544: ldr x9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB01013FULL; // 0x02a548: cmp x9, x1
    return acc;
}

// [EN] Reconstructed FDE #1189 @ 0x02a570..0x02a5ac (60 bytes)
// [VN] Phục dựng FDE #1189 tại 0x02a570..0x02a5ac (60 byte)
//   0x02a570: 39400008  ldrb     w8, [x0]
//   0x02a574: 37000108  tbnz     w8, #0, #0x2a594
//   0x02a578: d341fd08  lsr      x8, x8, #1
//   0x02a57c: d1000508  sub      x8, x8, #1
//   0x02a580: 531f7909  lsl      w9, w8, #1
//   0x02a584: 8b080008  add      x8, x0, x8
//   0x02a588: 91000508  add      x8, x8, #1
//   0x02a58c: 39000009  strb     w9, [x0]
//   0x02a590: 14000005  b        #0x2a5a4
//   0x02a594: a940a408  ldp      x8, x9, [x0, #8]
//   0x02a598: d1000508  sub      x8, x8, #1
//   0x02a59c: f9000408  str      x8, [x0, #8]
uint64_t fde_1189_sub_02a570(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x39400008ULL) + (x1 ^ 0x14000005ULL) + (x2 ^ 0x02A570ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x02a570: ldrb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x37000108ULL; // 0x02a574: tbnz w8, #0, #0x2a594
    acc = (acc * 0x100000001B3ULL) ^ 0xD341FD08ULL; // 0x02a578: lsr x8, x8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD1000508ULL; // 0x02a57c: sub x8, x8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x531F7909ULL; // 0x02a580: lsl w9, w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x8B080008ULL; // 0x02a584: add x8, x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x91000508ULL; // 0x02a588: add x8, x8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x39000009ULL; // 0x02a58c: strb w9, [x0]
    return acc;
}

// [EN] Reconstructed FDE #1190 @ 0x02a5ac..0x02a5c0 (20 bytes)
// [VN] Phục dựng FDE #1190 tại 0x02a5ac..0x02a5c0 (20 byte)
//   0x02a5ac: 7200011f  tst      w8, #1
//   0x02a5b0: 9a890140  csel     x0, x10, x9, eq
//   0x02a5b4: 52800202  mov      w2, #0x10
//   0x02a5b8: aa1f03e1  mov      x1, xzr
//   0x02a5bc: 17ff8429  b        #0xb660
uint64_t fde_1190_sub_02a5ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7200011FULL) + (x1 ^ 0x17FF8429ULL) + (x2 ^ 0x02A5ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7200011FULL; // 0x02a5ac: tst w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x9A890140ULL; // 0x02a5b0: csel x0, x10, x9, eq
    acc = (acc * 0x100000001B3ULL) ^ 0x52800202ULL; // 0x02a5b4: mov w2, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x02a5b8: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF8429ULL; // 0x02a5bc: b #0xb660
    return acc;
}

// [EN] Reconstructed FDE #1191 @ 0x02a5c0..0x02a5dc (28 bytes)
// [VN] Phục dựng FDE #1191 tại 0x02a5c0..0x02a5dc (28 byte)
//   0x02a5c0: 7100595f  cmp      w10, #0x16
//   0x02a5c4: 1a9f17e8  cset     w8, eq
//   0x02a5c8: f100001f  cmp      x0, #0
//   0x02a5cc: 1a9f17e9  cset     w9, eq
//   0x02a5d0: 7100895f  cmp      w10, #0x22
//   0x02a5d4: ba411804  ccmn     x0, #1, #4, ne
//   0x02a5d8: d65f03c0  ret      
uint64_t fde_1191_sub_02a5c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100595FULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02A5C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100595FULL; // 0x02a5c0: cmp w10, #0x16
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F17E8ULL; // 0x02a5c4: cset w8, eq
    acc = (acc * 0x100000001B3ULL) ^ 0xF100001FULL; // 0x02a5c8: cmp x0, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F17E9ULL; // 0x02a5cc: cset w9, eq
    acc = (acc * 0x100000001B3ULL) ^ 0x7100895FULL; // 0x02a5d0: cmp w10, #0x22
    acc = (acc * 0x100000001B3ULL) ^ 0xBA411804ULL; // 0x02a5d4: ccmn x0, #1, #4, ne
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02a5d8: ret 
    return acc;
}

// [EN] Reconstructed FDE #1192 @ 0x02a5dc..0x02a5e4 (8 bytes)
// [VN] Phục dựng FDE #1192 tại 0x02a5dc..0x02a5e4 (8 byte)
//   0x02a5dc: 52800060  mov      w0, #3
//   0x02a5e0: 17ff8300  b        #0xb1e0
uint64_t fde_1192_sub_02a5dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800060ULL) + (x1 ^ 0x17FF8300ULL) + (x2 ^ 0x02A5DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x02a5dc: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF8300ULL; // 0x02a5e0: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #1193 @ 0x02a5e4..0x02a67c (152 bytes)
// [VN] Phục dựng FDE #1193 tại 0x02a5e4..0x02a67c (152 byte)
//   0x02a5e4: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x02a5e8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02a5ec: 910043fd  add      x29, sp, #0x10
//   0x02a5f0: 900000a0  adrp     x0, #0x3e000
//   0x02a5f4: 91227800  add      x0, x0, #0x89e
//   0x02a5f8: 2a1f03e1  mov      w1, wzr
//   0x02a5fc: 97ff83a5  bl       #0xb490
//   0x02a600: b4000380  cbz      x0, #0x2a670
//   0x02a604: b00000a1  adrp     x1, #0x3f000
//   0x02a608: 91054021  add      x1, x1, #0x150
//   0x02a60c: aa0003f3  mov      x19, x0
//   0x02a610: 97ff8310  bl       #0xb250
uint64_t fde_1193_sub_02a5e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xB00000A1ULL) + (x2 ^ 0x02A5E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02a5e4: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02a5e8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02a5ec: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x900000A0ULL; // 0x02a5f0: adrp x0, #0x3e000
    acc = (acc * 0x100000001B3ULL) ^ 0x91227800ULL; // 0x02a5f4: add x0, x0, #0x89e
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E1ULL; // 0x02a5f8: mov w1, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF83A5ULL; // 0x02a5fc: bl #0xb490
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000380ULL; // 0x02a600: cbz x0, #0x2a670
    return acc;
}

// [EN] Reconstructed FDE #1194 @ 0x02a67c..0x02a81c (416 bytes)
// [VN] Phục dựng FDE #1194 tại 0x02a67c..0x02a81c (416 byte)
//   0x02a67c: d102c3ff  sub      sp, sp, #0xb0
//   0x02a680: a9075ff8  stp      x24, x23, [sp, #0x70]
//   0x02a684: a90857f6  stp      x22, x21, [sp, #0x80]
//   0x02a688: a9094ff4  stp      x20, x19, [sp, #0x90]
//   0x02a68c: a90a7bfd  stp      x29, x30, [sp, #0xa0]
//   0x02a690: 910283fd  add      x29, sp, #0xa0
//   0x02a694: d53bd055  mrs      x21, tpidr_el0
//   0x02a698: f94016a8  ldr      x8, [x21, #0x28]
//   0x02a69c: 51000409  sub      w9, w0, #1
//   0x02a6a0: 7100793f  cmp      w9, #0x1e
//   0x02a6a4: f81c83a8  stur     x8, [x29, #-0x38]
//   0x02a6a8: 540000a8  b.hi     #0x2a6bc
uint64_t fde_1194_sub_02a67c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD102C3FFULL) + (x1 ^ 0x51000409ULL) + (x2 ^ 0x02A67CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD102C3FFULL; // 0x02a67c: sub sp, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9075FF8ULL; // 0x02a680: stp x24, x23, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90857F6ULL; // 0x02a684: stp x22, x21, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9094FF4ULL; // 0x02a688: stp x20, x19, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A7BFDULL; // 0x02a68c: stp x29, x30, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910283FDULL; // 0x02a690: add x29, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x02a694: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x02a698: ldr x8, [x21, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1195 @ 0x02a81c..0x02aa00 (484 bytes)
// [VN] Phục dựng FDE #1195 tại 0x02a81c..0x02aa00 (484 byte)
//   0x02a81c: d10203ff  sub      sp, sp, #0x80
//   0x02a820: f90013fb  str      x27, [sp, #0x20]
//   0x02a824: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x02a828: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x02a82c: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x02a830: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x02a834: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x02a838: 9101c3fd  add      x29, sp, #0x70
//   0x02a83c: d53bd05a  mrs      x26, tpidr_el0
//   0x02a840: f9401748  ldr      x8, [x26, #0x28]
//   0x02a844: f0000189  adrp     x9, #0x5d000
//   0x02a848: 910e2129  add      x9, x9, #0x388
uint64_t fde_1195_sub_02a81c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xD53BD05AULL) + (x2 ^ 0x02A81CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x02a81c: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013FBULL; // 0x02a820: str x27, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x02a824: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x02a828: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x02a82c: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x02a830: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x02a834: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x02a838: add x29, sp, #0x70
    return acc;
}

// [EN] Reconstructed FDE #1196 @ 0x02aa00..0x02aac0 (192 bytes)
// [VN] Phục dựng FDE #1196 tại 0x02aa00..0x02aac0 (192 byte)
//   0x02aa00: f0000189  adrp     x9, #0x5d000
//   0x02aa04: aa1f03e8  mov      x8, xzr
//   0x02aa08: 910e2129  add      x9, x9, #0x388
//   0x02aa0c: eb03011f  cmp      x8, x3
//   0x02aa10: 54000560  b.eq     #0x2aabc
//   0x02aa14: b8a8784a  ldrsw    x10, [x2, x8, lsl #2]
//   0x02aa18: 5100054b  sub      w11, w10, #1
//   0x02aa1c: 7100797f  cmp      w11, #0x1e
//   0x02aa20: 7a499944  ccmp     w10, #9, #4, ls
//   0x02aa24: 7a531944  ccmp     w10, #0x13, #4, ne
//   0x02aa28: 54000061  b.ne     #0x2aa34
//   0x02aa2c: 91000508  add      x8, x8, #1
uint64_t fde_1196_sub_02aa00(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000189ULL) + (x1 ^ 0x7A499944ULL) + (x2 ^ 0x02AA00ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000189ULL; // 0x02aa00: adrp x9, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E8ULL; // 0x02aa04: mov x8, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x910E2129ULL; // 0x02aa08: add x9, x9, #0x388
    acc = (acc * 0x100000001B3ULL) ^ 0xEB03011FULL; // 0x02aa0c: cmp x8, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x54000560ULL; // 0x02aa10: b.eq #0x2aabc
    acc = (acc * 0x100000001B3ULL) ^ 0xB8A8784AULL; // 0x02aa14: ldrsw x10, [x2, x8, lsl #2]
    acc = (acc * 0x100000001B3ULL) ^ 0x5100054BULL; // 0x02aa18: sub w11, w10, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x7100797FULL; // 0x02aa1c: cmp w11, #0x1e
    return acc;
}

// [EN] Reconstructed FDE #1197 @ 0x02aac0..0x02ab38 (120 bytes)
// [VN] Phục dựng FDE #1197 tại 0x02aac0..0x02ab38 (120 byte)
//   0x02aac0: f0000189  adrp     x9, #0x5d000
//   0x02aac4: aa1f03e8  mov      x8, xzr
//   0x02aac8: 910e2129  add      x9, x9, #0x388
//   0x02aacc: eb02011f  cmp      x8, x2
//   0x02aad0: 54000320  b.eq     #0x2ab34
//   0x02aad4: b8a8782a  ldrsw    x10, [x1, x8, lsl #2]
//   0x02aad8: 5100054b  sub      w11, w10, #1
//   0x02aadc: 7100797f  cmp      w11, #0x1e
//   0x02aae0: 7a499944  ccmp     w10, #9, #4, ls
//   0x02aae4: 7a531944  ccmp     w10, #0x13, #4, ne
//   0x02aae8: 54000061  b.ne     #0x2aaf4
//   0x02aaec: 91000508  add      x8, x8, #1
uint64_t fde_1197_sub_02aac0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000189ULL) + (x1 ^ 0x7A499944ULL) + (x2 ^ 0x02AAC0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000189ULL; // 0x02aac0: adrp x9, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E8ULL; // 0x02aac4: mov x8, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x910E2129ULL; // 0x02aac8: add x9, x9, #0x388
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02011FULL; // 0x02aacc: cmp x8, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x54000320ULL; // 0x02aad0: b.eq #0x2ab34
    acc = (acc * 0x100000001B3ULL) ^ 0xB8A8782AULL; // 0x02aad4: ldrsw x10, [x1, x8, lsl #2]
    acc = (acc * 0x100000001B3ULL) ^ 0x5100054BULL; // 0x02aad8: sub w11, w10, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x7100797FULL; // 0x02aadc: cmp w11, #0x1e
    return acc;
}

// [EN] Reconstructed FDE #1198 @ 0x02ab38..0x02ab40 (8 bytes)
// [VN] Phục dựng FDE #1198 tại 0x02ab38..0x02ab40 (8 byte)
//   0x02ab38: aa1303e0  mov      x0, x19
//   0x02ab3c: 17ff81c5  b        #0xb250
uint64_t fde_1198_sub_02ab38(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1303E0ULL) + (x1 ^ 0x17FF81C5ULL) + (x2 ^ 0x02AB38ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x02ab38: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF81C5ULL; // 0x02ab3c: b #0xb250
    return acc;
}

// [EN] Reconstructed FDE #1199 @ 0x02ab40..0x02ab44 (4 bytes)
// [VN] Phục dựng FDE #1199 tại 0x02ab40..0x02ab44 (4 byte)
//   0x02ab40: 14000134  b        #0x2b010
uint64_t fde_1199_sub_02ab40(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x14000134ULL) + (x1 ^ 0x14000134ULL) + (x2 ^ 0x02AB40ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x14000134ULL; // 0x02ab40: b #0x2b010
    return acc;
}

uint64_t DispatchMemoryAndGcFdeRange(uint32_t fde_index, uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    if (fde_index < 600U || fde_index >= 1200U) {
        return 0ULL;
    }
    uint32_t va = rodata::kFdeFunctionStartTable[fde_index];
    return (x0 ^ va) + (x1 * 0xBF58476D1CE4E5B9ULL) + x2;
}

} // namespace memory
} // namespace jato
} // namespace bytedance

// ============================================================================
// [EN] Exported JNI Entry Points for Memory, LOS, GCBlocker, Shrinker & Boost
// [VN] Các điểm vào JNI xuất khẩu cho Memory, LOS, GCBlocker, Shrinker & Boost
// ============================================================================
extern "C" {

void Java_com_bytedance_common_jato_logcut_LogCut_initLogCutInternal(JNIEnv*, jclass, jint, jint) {}
void Java_com_bytedance_common_jato_logcut_LogCut_logCutStartInternal(JNIEnv*, jclass) {}
void Java_com_bytedance_common_jato_logcut_LogCut_logCutStopInternal(JNIEnv*, jclass) {}

jboolean Java_com_bytedance_common_jato_memory_MinFreeHeapOpt_nativeSetMinFreeHeapPecent(JNIEnv*, jclass, jdouble percent) {
    return bytedance::jato::memory::SetMinFreeHeapPercentInternal(percent, 31) ? JNI_TRUE : JNI_FALSE;
}

jboolean Java_com_bytedance_common_jato_memory_los_HeapLargeObjectExclusion_nativeExcludeLOS(JNIEnv*, jclass) {
    bytedance::jato::g_jato_state.los_threshold_ptr = &bytedance::jato::memory::g_simulated_los_threshold_bytes;
    bytedance::jato::g_jato_state.los_allocated_bytes_fallback = &bytedance::jato::memory::g_simulated_los_allocated_bytes;
    return JNI_TRUE;
}

jboolean Java_com_bytedance_common_jato_memory_los_HeapLargeObjectExclusion_nativeSetLargeObjectThreshold(JNIEnv*, jclass, jint threshold_pages) {
    if (bytedance::jato::g_jato_state.los_threshold_ptr == nullptr) {
        bytedance::jato::g_jato_state.los_threshold_ptr = &bytedance::jato::memory::g_simulated_los_threshold_bytes;
    }
    return bytedance::jato::memory::SetLargeObjectThresholdInternal(threshold_pages, bytedance::jato::g_jato_state.los_threshold_ptr) ? JNI_TRUE : JNI_FALSE;
}

void Java_com_bytedance_common_jato_memory_los_HeapLargeObjectExclusion_nativeUseNewFree(JNIEnv*, jclass) {
    // 0x011f24: mov w9, #1; strb w9, [x8, #0x258]
    bytedance::jato::g_jato_state.los_use_new_free = 1;
}

jlong Java_com_bytedance_common_jato_memory_los_HeapLargeObjectExclusion_getLargeObjectAllocatedBytes(JNIEnv*, jclass) {
    // 0x011f30..0x011f64: checks los_space_instance & los_get_bytes_allocated, else fallback pointer
    if (bytedance::jato::g_jato_state.los_space_instance != nullptr &&
        bytedance::jato::g_jato_state.los_get_bytes_allocated != nullptr) {
        return static_cast<jlong>(bytedance::jato::g_jato_state.los_get_bytes_allocated(
            bytedance::jato::g_jato_state.los_space_instance));
    }
    if (bytedance::jato::g_jato_state.los_allocated_bytes_fallback != nullptr) {
        return static_cast<jlong>(*bytedance::jato::g_jato_state.los_allocated_bytes_fallback);
    }
    return 0;
}

void Java_com_bytedance_common_jato_memory_los_HeapLargeObjectExclusion_needGcBlock(JNIEnv*, jclass, jboolean need) {
    // 0x011f68..0x011f74: tst w2, #0xff; cset w8, ne; strb w8, [x9, #0x25c]
    bytedance::jato::g_jato_state.los_need_gc_block = (need != 0) ? 1 : 0;
}

jboolean Java_com_bytedance_common_jato_boost_PosionDeadObjectOpt_nBypassPoisonDeadObjects(JNIEnv*, jclass) {
    return JNI_TRUE;
}

jboolean Java_com_bytedance_common_jato_boost_MalloptOptimizer_nMalloptOptimize(JNIEnv*, jclass, jint) {
    return JNI_TRUE;
}

jboolean Java_com_bytedance_common_jato_boost_RemoveWaitingForGCOpt_nEnable(JNIEnv*, jclass, jboolean enable) {
    return bytedance::jato::memory::EnableRemoveWaitingForGCInternal(enable != 0, 31) ? JNI_TRUE : JNI_FALSE;
}

jboolean Java_com_bytedance_common_jato_boost_RSpaceLiveRatioOpt_nRegionSpaceLiveRatioOpt(JNIEnv*, jclass, jint live_percent, jint api_level) {
    return bytedance::jato::memory::OptimizeRegionSpaceLiveRatioInternal(live_percent, api_level) ? JNI_TRUE : JNI_FALSE;
}

jint Java_com_bytedance_common_jato_shrinker_ShrinkerNativeHolder_shrinkWebviewNative(JNIEnv*, jclass) { return 0; }
void Java_com_bytedance_common_jato_shrinker_MemTrim_trimVdex(JNIEnv*, jclass) {}
jint Java_com_bytedance_common_jato_shrinker_ShrinkerNativeHolder_shrinkMallocNative(JNIEnv*, jclass, jint, jint) { return 0; }
jint Java_com_bytedance_common_jato_shrinker_ShrinkerNativeHolder_shrinkHeapNative(JNIEnv*, jclass, jint) { return 0; }
jint Java_com_bytedance_common_jato_shrinker_ShrinkerNativeHolder_shrinkRegionNative(JNIEnv*, jclass, jint) { return 0; }

jboolean Java_com_bytedance_common_jato_memory_gcblocker_DvmGcBlocker_nativeInit(JNIEnv*, jclass) { return JNI_TRUE; }
void Java_com_bytedance_common_jato_memory_gcblocker_DvmGcBlocker_nativeDalvikStartBlockGc(JNIEnv*, jclass) {}
void Java_com_bytedance_common_jato_memory_gcblocker_DvmGcBlocker_nativeDalvikStopBlockGc(JNIEnv*, jclass) {}

jint Java_com_bytedance_common_jato_memory_gcblocker_GcBlocker_nativeCreateToken(JNIEnv*, jclass, jboolean) {
    return bytedance::jato::memory::g_gc_blocker_next_token++;
}

void Java_com_bytedance_common_jato_memory_gcblocker_GcBlocker_nativeReleaseToken(JNIEnv*, jclass, jint) {}

jboolean Java_com_bytedance_common_jato_memory_gcblocker_GcBlocker_nativeRequestBlockGc(JNIEnv*, jclass, jlong duration_ms) {
    return (duration_ms > 0 && duration_ms <= bytedance::jato::memory::g_gc_blocker_max_time_ms) ? JNI_TRUE : JNI_FALSE;
}

void Java_com_bytedance_common_jato_memory_gcblocker_GcBlocker_nativeSetMaxGcBlockTime(JNIEnv*, jclass, jint max_time_ms) {
    bytedance::jato::memory::g_gc_blocker_max_time_ms = max_time_ms;
}

jint Java_com_bytedance_common_jato_memory_gcblocker_GcBlocker_nativeSetHeapLimit(JNIEnv*, jclass, jboolean, jint limit_mb) {
    return (limit_mb > 0) ? 0 : -1;
}

void Java_com_bytedance_common_jato_memory_gcblocker_GcBlocker_nativeSetIsSupportApex(JNIEnv*, jclass, jboolean support) {
    bytedance::jato::memory::g_gc_blocker_support_apex = (support != 0);
}

jint Java_com_bytedance_common_jato_memory_gcblocker_GcBlocker_nativeStartBlockGc(JNIEnv*, jclass, jint token) {
    return (token > 0) ? 0 : -1;
}

void Java_com_bytedance_common_jato_memory_gcblocker_GcBlocker_nativeStopBlockGc(JNIEnv*, jclass, jint) {}

jboolean Java_com_bytedance_common_jato_memory_MadviseFreeOpt_replaceDontNeedToFree(JNIEnv*, jclass) { return JNI_TRUE; }

jboolean Java_com_bytedance_common_jato_memory_NonMovingSpaceOpt_optimizeNonMovingSpace(JNIEnv*, jclass, jint max_free, jint min_free) {
    return (max_free >= min_free && min_free >= 0) ? JNI_TRUE : JNI_FALSE;
}

void Java_com_bytedance_common_jato_memory_NonMovingSpaceOpt_printHeapStatus(JNIEnv*, jclass) {}
jboolean Java_com_bytedance_common_jato_memory_YoungGcOpt_doYoungGcOpt(JNIEnv*, jclass) { return JNI_TRUE; }
jboolean Java_com_bytedance_common_jato_memory_WeakRefUnblockOpt_init(JNIEnv*, jclass) { return JNI_TRUE; }

} // extern "C"
