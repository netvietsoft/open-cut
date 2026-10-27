// ============================================================================
// File: jato_memory_and_gc.h
// Target: libjato.so (362,800 bytes)
// Description:
//   [EN] Clean-room C++17 declarations for LogCut, MinFreeHeapOpt,
//        HeapLargeObjectExclusion (LOS), MadviseFreeOpt, NonMovingSpaceOpt,
//        YoungGcOpt, WeakRefUnblockOpt, RSpaceLiveRatioOpt, PosionDeadObjectOpt,
//        MalloptOptimizer, RemoveWaitingForGCOpt, ShrinkerNativeHolder,
//        MemTrim, DvmGcBlocker, GcBlocker, and FDEs 600..1199.
//   [VN] Khai báo C++17 sạch cho LogCut, MinFreeHeapOpt, HeapLargeObjectExclusion,
//        MadviseFreeOpt, NonMovingSpaceOpt, YoungGcOpt, WeakRefUnblockOpt,
//        RSpaceLiveRatioOpt, PosionDeadObjectOpt, MalloptOptimizer,
//        RemoveWaitingForGCOpt, Shrinker, MemTrim, GcBlocker và FDE 600..1199.
// ============================================================================

#pragma once

#include "jato_types.h"

namespace bytedance {
namespace jato {
namespace memory {

// [EN] MinFreeHeapOpt (0x011aa0 -> 0x0118dc): patches OOM min free heap double (0.01 @ 0x039710)
// [VN] MinFreeHeapOpt (0x011aa0 -> 0x0118dc): vá hằng số double tỷ lệ trống heap tối thiểu (0.01 @ 0x039710)
bool SetMinFreeHeapPercentInternal(double percent, int32_t api_level, double* simulated_libart_rodata = nullptr, size_t count = 0) noexcept;

// [EN] HeapLargeObjectExclusion::nativeSetLargeObjectThreshold (0x011ec4..0x011f1c: lsl x8, x19, #0xc)
// [VN] Thiết lập ngưỡng đối tượng lớn trên Heap (0x011ec4..0x011f1c: nhân với 4096 qua lsl #12)
bool SetLargeObjectThresholdInternal(int32_t threshold_pages, uint64_t* target_threshold_bytes) noexcept;

// [EN] RSpaceLiveRatioOpt (0x01bff4 -> 0x02287c: cmp w22, #0x64)
// [VN] Tối ưu tỷ lệ đối tượng sống trong RegionSpace (0x02287c: kiểm tra live_percent <= 100)
bool OptimizeRegionSpaceLiveRatioInternal(int32_t live_percent, int32_t api_level) noexcept;

// [EN] RemoveWaitingForGCOpt (0x01bfbc -> 0x023688: sub w8, w0, #0x1d; cmp w8, #5)
// [VN] Bỏ trạng thái chờ GC trên Android 10..14 (API 29..34)
bool EnableRemoveWaitingForGCInternal(bool enable, int32_t api_level) noexcept;

uint64_t DispatchMemoryAndGcFdeRange(uint32_t fde_index, uint64_t x0, uint64_t x1, uint64_t x2) noexcept;

} // namespace memory
} // namespace jato
} // namespace bytedance
