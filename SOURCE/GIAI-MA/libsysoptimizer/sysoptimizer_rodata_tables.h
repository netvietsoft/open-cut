// ============================================================================
// File: sysoptimizer_rodata_tables.h
// Target: libsysoptimizer.so (412,248 bytes)
// Description:
//   [EN] Read-only strings (.rodata 0x00b230..0x015d28), 14 .init_array relocated
//        constructors (0x0609b0..0x060a18 -> 0x02c6b0..0x02ca20), and 732 FDEs.
//   [VN] Bảng chuỗi chỉ đọc (.rodata 0x00b230..0x015d28), 14 hàm khởi tạo .init_array
//        (0x0609b0..0x060a18 -> 0x02c6b0..0x02ca20) và 732 FDE.
// ============================================================================

#pragma once

#include "sysoptimizer_types.h"

namespace bytedance {
namespace sysoptimizer {
namespace rodata {

constexpr int32_t kXhErrnoFormat = 0x3EF; // 1007 @ 0x02587c & 0x025898

struct RodataStringEntry {
    uint32_t va;
    const char* text;
};

extern const uint64_t kInitArrayRelocatedTargets_0609b0[14];
extern const RodataStringEntry kRodataStringTable[];
extern const size_t kRodataStringTableCount;
extern const uint32_t kFdeFunctionStartTable[732];

const char* LookupRodataString(uint32_t va) noexcept;

} // namespace rodata
} // namespace sysoptimizer
} // namespace bytedance
