// ============================================================================
// File: rex_types.h
// Target 109 / 169: librex.so (690,264 bytes)
// SHA-256: 8597b027ebde080435814b961a219d53170ab05cee0d5c4d40cfe0bb1ee5d6c4
// EN: Exact AArch64 ABI struct layouts for ByteDance BDDateFormat (`librex.so`):
//     RexCalendarBreakdown (0x08ab60..0x08ade0), RexLocaleResourceTable (0x0946c0),
//     and BDDateUnit / BDTimeRangeUnit enums.
// VI: Bố cục struct ABI AArch64 chính xác cho ByteDance BDDateFormat (`librex.so`):
//     RexCalendarBreakdown (0x08ab60..0x08ade0), RexLocaleResourceTable (0x0946c0)
//     và các enum BDDateUnit / BDTimeRangeUnit.
// ============================================================================
#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>

namespace bytedance {
namespace rex {

// EN: Unit enum validated in nFormatAbbr (0x08d2b8..0x08d2c8) & nFormatRelative (0x08d418..0x08d428):
//     `sub w8, w20, #1; cmp w8, #7; csel w20, w20, wzr, lo` -> valid range [1..7], else 0.
// VI: Enum đơn vị xác minh trong nFormatAbbr (0x08d2b8..0x08d2c8) & nFormatRelative (0x08d418..0x08d428):
enum class BDDateUnit : int32_t {
    kInvalid = 0,
    kYear    = 1,
    kMonth   = 2,
    kWeek    = 3,
    kDay     = 4,
    kHour    = 5,
    kMinute  = 6,
    kSecond  = 7
};

// EN: Time range unit validated in nFormatTimeRange (0x08d820..0x08d830):
//     `sub w8, w22, #1; cmp w8, #8; csel w22, w22, wzr, lo` -> valid range [1..8], else 0.
// VI: Đơn vị khoảng thời gian xác minh trong nFormatTimeRange (0x08d820..0x08d830):
enum class BDTimeRangeUnit : int32_t {
    kInvalid     = 0,
    kYear        = 1,
    kMonth       = 2,
    kWeek        = 3,
    kDay         = 4,
    kHour        = 5,
    kMinute      = 6,
    kSecond      = 7,
    kMillisecond = 8
};

// EN: Exact ABI layout of RexCalendarBreakdown populated at 0x08ab60..0x08ade0:
//     +0x00: double timestamp_ms (`str d0, [x0]` @ 0x08ab8c)
//     +0x08: int32_t year
//     +0x0C: int32_t month (1..12)
//     +0x10: int32_t day_of_month (1..31)
//     +0x14: int32_t day_of_week (0..6, Sunday=0)
//     +0x18: int32_t day_of_year (1..366)
//     +0x1C: int32_t hour (0..23)
//     +0x20: int32_t minute (0..59)
//     +0x24: int32_t second (0..59)
//     +0x28: int32_t millisecond (0..999)
//     +0x2C: int32_t tz_offset_minutes
//     +0x30: uint8_t reserved_30[0x20]
//     +0x50: uint8_t use_system_tz (`strb w9, [x0, #0x50]` @ 0x08ab90)
//     +0x54: int32_t custom_tz_offset_ms (`str w2, [x0, #0x54]` @ 0x08ab94)
// VI: Bố cục ABI chính xác của RexCalendarBreakdown khởi tạo tại 0x08ab60..0x08ade0:
struct RexCalendarBreakdownAbiLayout {
    double   timestamp_ms;        // +0x00
    int32_t  year;                // +0x08
    int32_t  month;               // +0x0C
    int32_t  day_of_month;        // +0x10
    int32_t  day_of_week;         // +0x14
    int32_t  day_of_year;         // +0x18
    int32_t  hour;                // +0x1C
    int32_t  minute;              // +0x20
    int32_t  second;              // +0x24
    int32_t  millisecond;         // +0x28
    int32_t  tz_offset_minutes;   // +0x2C
    uint8_t  reserved_30[0x20];   // +0x30..0x4F
    uint8_t  use_system_tz;       // +0x50
    uint8_t  pad_51[3];           // +0x51..0x53
    int32_t  custom_tz_offset_ms; // +0x54
};
static_assert(offsetof(RexCalendarBreakdownAbiLayout, timestamp_ms) == 0x00, "timestamp_ms must be at +0x00");
static_assert(offsetof(RexCalendarBreakdownAbiLayout, use_system_tz) == 0x50, "use_system_tz must be at +0x50");
static_assert(offsetof(RexCalendarBreakdownAbiLayout, custom_tz_offset_ms) == 0x54, "custom_tz_offset_ms must be at +0x54");
static_assert(sizeof(RexCalendarBreakdownAbiLayout) == 0x58, "RexCalendarBreakdownAbiLayout must be 0x58 bytes");

// EN: Exact ABI offsets in RexLocaleResourceTable verified from 0x096300..0x096984:
//     +0x558..0x9d8: 7 Abbr unit tables (stride 0xC0 = 192 bytes each: 0x558, 0x618, 0x6d8, 0x798, 0x858, 0x918, 0x9d8)
//     +0xa98..0xf18: 7 Past Relative unit tables (`add x9, x0, #0xa98` @ 0x096908, stride 0xC0)
//     +0xfd8..0x1458: 7 Future Relative unit tables (`add x8, x0, #0xfd8` @ 0x096904, stride 0xC0)
//     +0x1518: std::string time_zone_pattern (`mov w8, #0x1518; add x1, x0, x8` @ 0x096340 -> "%$1s %$2s")
//     +0x1530: std::string time_range_separator (`mov w8, #0x1530; add x1, x0, x8` @ 0x0964ec)
//     +0x1548: std::string time_range_patterns[18] (`mov w8, #0x1548; add x26, x26, x8` @ 0x096500)
// VI: Các offset ABI chính xác trong RexLocaleResourceTable xác minh từ 0x096300..0x096984:
struct RexLocaleResourceOffsets {
    static constexpr uint32_t kAbbrUnitBaseOffset       = 0x0558u;
    static constexpr uint32_t kUnitTableStride          = 0x00C0u;
    static constexpr uint32_t kPastRelativeBaseOffset   = 0x0A98u;
    static constexpr uint32_t kFutureRelativeBaseOffset = 0x0FD8u;
    static constexpr uint32_t kTimeZoneFormatOffset     = 0x1518u;
    static constexpr uint32_t kTimeRangeSepOffset       = 0x1530u;
    static constexpr uint32_t kTimeRangePatternsOffset  = 0x1548u;
};

} // namespace rex
} // namespace bytedance
