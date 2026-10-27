// ============================================================================
// File: jato_rodata_tables.h
// Target: libjato.so (362,800 bytes)
// Description:
//   [EN] Read-only constants (.rodata 0x0390b0..0x0431c8), .data.rel.ro
//        (0x05a5e8..0x05abc0), and .data (0x05c000..0x05c124) tables.
//   [VN] Bảng hằng số chỉ đọc (.rodata 0x0390b0..0x0431c8), .data.rel.ro
//        (0x05a5e8..0x05abc0) và .data (0x05c000..0x05c124).
// ============================================================================

#pragma once

#include <cstdint>
#include <cstddef>

namespace bytedance {
namespace jato {
namespace rodata {

// [EN] Default Android ART OOM min free heap ratio @ .rodata 0x039710 (0x3f847ae147ae147b = 0.01)
// [VN] Tỷ lệ heap trống tối thiểu mặc định của ART @ .rodata 0x039710 (0x3f847ae147ae147b = 0.01)
constexpr uint64_t kDefaultOomMinFreeHeapBits = 0x3F847AE147AE147BULL;
constexpr double kDefaultOomMinFreeHeapRatio = 0.01;

// [EN] Default live ratio threshold in .data @ 0x05c020 (0x3fe0000000000000 = 0.5)
// [VN] Ngưỡng tỷ lệ đối tượng sống mặc định trong .data @ 0x05c020 (0x3fe0000000000000 = 0.5)
constexpr uint64_t kDefaultDataRatioBits = 0x3FE0000000000000ULL;
constexpr double kDefaultDataRatio = 0.5;

// [EN] Instrumentation crash fix API level bitmask @ 0x016b84..0x016b88 (Android 10/11/12/13: API 29, 30, 31, 33)
// [VN] Mặt nạ bit cấp độ API sửa lỗi crash Instrumentation @ 0x016b84..0x016b88 (API 29, 30, 31, 33)
constexpr uint64_t kInstrumentationCrashFixApiMask = 0x00000002E0000000ULL;

// [EN] DecodeJObject AArch64 LDR instruction mask & opcode @ 0x01c050..0x01c064
// [VN] Mặt nạ và mã lệnh LDR AArch64 dùng trong DecodeJObject @ 0x01c050..0x01c064
constexpr uint32_t kDecodeJObjectLdrBase = 0xB8400000U; // mov w21, #-0x47c00000
constexpr uint32_t kDecodeJObjectLdrMask = 0xB84003E0U; // add w8, w21, #0x3e0

// [EN] Exact .data section initial snapshot (0x05c000..0x05c124, 292 bytes)
// [VN] Ảnh chụp khởi tạo chính xác của phân đoạn .data (0x05c000..0x05c124, 292 bytes)
extern const uint8_t kDataSectionSnapshot[292];

// [EN] Key .rodata symbol & diagnostic string table (0x0390b0..0x0431c8)
// [VN] Bảng chuỗi biểu tượng và chẩn đoán trong .rodata (0x0390b0..0x0431c8)
struct RodataStringEntry {
    uint32_t va;
    const char* text;
};

extern const RodataStringEntry kRodataStringTable[];
extern const size_t kRodataStringTableCount;

// [EN] Exact .eh_frame_hdr FDE function start table (1,765 entries @ 0x0431c8)
// [VN] Bảng địa chỉ bắt đầu hàm FDE từ .eh_frame_hdr (1.765 mục @ 0x0431c8)
extern const uint32_t kFdeFunctionStartTable[1765];

const char* LookupRodataString(uint32_t va) noexcept;

} // namespace rodata
} // namespace jato
} // namespace bytedance
