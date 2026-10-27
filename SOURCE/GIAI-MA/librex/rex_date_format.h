// ============================================================================
// File: rex_date_format.h
// Target 109 / 169: librex.so (690,264 bytes)
// EN: Clean-room C++17 declarations for ByteDance BDDateFormat engine:
//     RexCalendarBreakdown (0x08ab60), FormatDate (0x0960ec),
//     FormatTimeZone (0x096300), FormatTimeRange (0x09649c),
//     FormatAbbr (0x096830), FormatRelative (0x0968e0), and FDE dispatcher.
// VI: Khai báo C++17 phòng sạch cho bộ định dạng ngày giờ ByteDance BDDateFormat:
//     RexCalendarBreakdown (0x08ab60), FormatDate (0x0960ec),
//     FormatTimeZone (0x096300), FormatTimeRange (0x09649c),
//     FormatAbbr (0x096830), FormatRelative (0x0968e0) và bộ điều phối FDE.
// ============================================================================
#pragma once

#include "rex_types.h"

namespace bytedance {
namespace rex {

class BDDateFormatter {
public:
    // 0x08d2b8 / 0x08d418: `(uint32_t)(unit - 1) < 7 ? unit : 0`
    static int32_t SanitizeDateUnit7(int32_t unit) noexcept;

    // 0x08d820: `(uint32_t)(unit - 1) < 8 ? unit : 0`
    static int32_t SanitizeTimeRangeUnit8(int32_t unit) noexcept;

    // 0x08ab60..0x08ade0: Converts timestamp_ms + timezone into civil calendar fields
    static void InitCalendarBreakdown(
        RexCalendarBreakdownAbiLayout& out,
        double timestamp_ms,
        bool use_system_tz,
        int32_t custom_tz_offset_ms) noexcept;

    // 0x0960ec..0x0962fc: Formats timestamp_ms using pattern and locale
    static std::string FormatDate(
        const std::string& pattern,
        int64_t timestamp_ms,
        const std::string& locale,
        bool use_system_tz,
        int32_t custom_tz_offset_ms);

    // 0x096300..0x0963e8: Replaces "%$1s" (0x73312425) and "%$2s" (0x73322425)
    static std::string FormatTimeZone(
        const std::string& date_text,
        const std::string& tz_text,
        const std::string& locale);

    // 0x09649c..0x096828: Formats start_ms..end_ms range with unit [1..8]
    static std::string FormatTimeRange(
        int64_t start_ms,
        int64_t end_ms,
        int32_t unit,
        const std::string& locale,
        bool use_system_tz,
        int32_t custom_tz_offset_ms);

    // 0x096830..0x0968dc: Formats abbreviated count + unit [1..7]
    static std::string FormatAbbr(
        int32_t count,
        int32_t unit,
        const std::string& locale);

    // 0x0968e0..0x096994: Selects future (+0xfd8) if offset >= 0 else past (+0xa98) with |offset|
    static std::string FormatRelative(
        int32_t offset,
        int32_t unit,
        const std::string& locale);
};

uint64_t ExecuteRexFdeByAddress(uint64_t fde_pc_begin, uint64_t arg0, uint64_t arg1, uint64_t arg2) noexcept;

} // namespace rex
} // namespace bytedance
