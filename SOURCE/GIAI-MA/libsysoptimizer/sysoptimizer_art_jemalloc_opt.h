// ============================================================================
// File: sysoptimizer_art_jemalloc_opt.h
// Target: libsysoptimizer.so (412,248 bytes)
// Description:
//   [EN] Clean-room C++17 declarations for ArtMProtectOpt (0x02d790..0x02d944),
//        ArtOptimizer (0x02dcec..0x02e5a4), MaliMemOptimizer (0x031ccc..0x032350),
//        SurfaceUtils_nativeSetSurfaceGeometry (0x034730), HeapGCOptimizer (0x0390b0..0x039d00),
//        JemallocAllocatorOptimizer (0x03b67c..0x03d000), FindCatchBlockOpt (0x043c24),
//        and FDEs 250..499.
//   [VN] Khai báo C++17 sạch cho ArtMProtectOpt, ArtOptimizer, MaliMemOptimizer,
//        SurfaceUtils, HeapGCOptimizer, JemallocAllocatorOptimizer và FDE 250..499.
// ============================================================================

#pragma once

#include "sysoptimizer_types.h"

namespace bytedance {
namespace sysoptimizer {
namespace art_jemalloc {

int32_t StartArtMProtectPhase1Exact(uint32_t min_addr, uint32_t max_addr, ArtMProtectOptStateAbi* out_state) noexcept;
uint64_t DispatchArtJemallocFdeRange(uint32_t fde_index, uint64_t x0, uint64_t x1, uint64_t x2) noexcept;

} // namespace art_jemalloc
} // namespace sysoptimizer
} // namespace bytedance
