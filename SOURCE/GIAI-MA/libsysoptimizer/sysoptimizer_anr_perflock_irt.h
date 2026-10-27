// ============================================================================
// File: sysoptimizer_anr_perflock_irt.h
// Target: libsysoptimizer.so (412,248 bytes)
// Description:
//   [EN] Clean-room C++17 declarations for IndirectReferenceTableMonitor (0x048cec..0x051bc0),
//        JemallocExtend (0x05263c..0x053124), HeapGCOptimizerV2 (0x053540..0x0536b4),
//        PerfLockBooster (0x053b88..0x0548a0), TextureViewOptimizer (0x0548a0..0x054b30),
//        InputAnrOpt (0x055288..0x05678c), GcTimeCollect (0x05678c), and FDEs 500..731.
//   [VN] Khai báo C++17 sạch cho IndirectReferenceTableMonitor, JemallocExtend,
//        HeapGCOptimizerV2, PerfLockBooster, TextureViewOptimizer, InputAnrOpt và FDE 500..731.
// ============================================================================

#pragma once

#include "sysoptimizer_types.h"

namespace bytedance {
namespace sysoptimizer {
namespace anr_perflock {

jboolean SetHeapGCOptimizerV2ValuesExact(int64_t x2, int64_t x3, int64_t x4, HeapGCOptimizerV2ValuesAbi* out_values) noexcept;
uint64_t DispatchAnrPerflockIrtFdeRange(uint32_t fde_index, uint64_t x0, uint64_t x1, uint64_t x2) noexcept;

} // namespace anr_perflock
} // namespace sysoptimizer
} // namespace bytedance
