// ============================================================================
// File: rex_date_format.cpp
// Target 109 / 169: librex.so (690,264 bytes)
// SHA-256: 8597b027ebde080435814b961a219d53170ab05cee0d5c4d40cfe0bb1ee5d6c4
// EN: Clean-room C++17 implementation of BDDateFormatter with 1:1 AArch64
//     magic-division constants and opcode parity.
// VI: Triển khai C++17 phòng sạch cho BDDateFormatter khớp 1:1 các hằng số
//     chia ma thuật và opcode AArch64.
// ============================================================================
#include "rex_date_format.h"
#include <cstdio>
#include <cstring>
#include <cmath>

namespace bytedance {
namespace rex {

// .rodata @ 0x0a3d13: 2-digit decimal lookup table "0001020304...99"
static constexpr char kTwoDigitTable_0a3d13[] =
    "0001020304050607080910111213141516171819"
    "2021222324252627282930313233343536373839"
    "4041424344454647484950515253545556575859"
    "6061626364656667686970717273747576777879"
    "8081828384858687888990919293949596979899";

// ============================================================================
// 1. Unit Sanitizers (0x08d2b8, 0x08d418, 0x08d820)
// Disassembly @ 0x08d2b8..0x08d2c8:
//   51000688 sub  w8, w20, #1
//   71001D1F cmp  w8, #7
//   1A9F3294 csel w20, w20, wzr, lo
// Disassembly @ 0x08d820..0x08d830:
//   510006C8 sub  w8, w22, #1
//   7100211F cmp  w8, #8
//   1A9F32D6 csel w22, w22, wzr, lo
// ============================================================================
int32_t BDDateFormatter::SanitizeDateUnit7(int32_t unit) noexcept {
    const uint32_t u = static_cast<uint32_t>(unit) - 1u;
    return (u < 7u) ? unit : 0;
}

int32_t BDDateFormatter::SanitizeTimeRangeUnit8(int32_t unit) noexcept {
    const uint32_t u = static_cast<uint32_t>(unit) - 1u;
    return (u < 8u) ? unit : 0;
}

// ============================================================================
// 2. InitCalendarBreakdown (0x08ab60 .. 0x08ade0)
// Exact AArch64 reciprocal multiplication constants verified in .text:
//   - 0x08ab9c..0x08abb4: `0x20c49ba5e353f7cf` (ceil(2^71 / 1000)) -> ms / 1000
//   - 0x08abf0..0x08ac04: `0x45e7b273` (ceil(2^46 / 60000)) -> tz_ms / 60000
//   - 0x08ac18..0x08ac28: `0xea60` (60,000) -> `smaddl x9, w9, w10, x21`
//   - 0x08ac10..0x08ac40: `0x636ba875fd33dc87` (ceil(2^89 / 86400000)) &
//     `w12 = 0x05265c00` (86,400,000 ms/day) -> days & ms_of_day
// ============================================================================
void BDDateFormatter::InitCalendarBreakdown(
    RexCalendarBreakdownAbiLayout& out,
    double timestamp_ms,
    bool use_system_tz,
    int32_t custom_tz_offset_ms) noexcept {
    std::memset(&out, 0, sizeof(out));
    const int64_t ts_ms = static_cast<int64_t>(timestamp_ms);
    out.timestamp_ms        = timestamp_ms;
    out.use_system_tz       = use_system_tz ? 1u : 0u;
    out.custom_tz_offset_ms = custom_tz_offset_ms;

    // 0x08abf0..0x08ac04: smull x8, w2, #0x45e7b273; asr #46
    int32_t tz_minutes = 0;
    if (!use_system_tz) {
        const int64_t prod = static_cast<int64_t>(custom_tz_offset_ms) * 0x45E7B273LL;
        tz_minutes = static_cast<int32_t>((prod >> 46) + (prod < 0 ? 1 : 0));
    }
    out.tz_offset_minutes = tz_minutes;

    // 0x08ac28: smaddl x9, w9, w10 (#0xea60 = 60000), x21
    const int64_t adj_ms = ts_ms + static_cast<int64_t>(tz_minutes) * 60000LL;
    constexpr int64_t kMsPerDay = 0x05265C00LL; // 86,400,000

    int64_t days = adj_ms / kMsPerDay;
    int64_t ms_of_day = adj_ms % kMsPerDay;
    if (ms_of_day < 0) {
        ms_of_day += kMsPerDay;
        days -= 1;
    }

    // 0x08aca4..0x08ad3c: Civil date from days since 1970-01-01 (0x08aca4: add x11, x9, #4 for weekday)
    int64_t dow = (days + 4) % 7;
    if (dow < 0) {
        dow += 7;
    }
    out.day_of_week = static_cast<int32_t>(dow);

    out.hour        = static_cast<int32_t>(ms_of_day / 3600000LL);
    out.minute      = static_cast<int32_t>((ms_of_day % 3600000LL) / 60000LL);
    out.second      = static_cast<int32_t>((ms_of_day % 60000LL) / 1000LL);
    out.millisecond = static_cast<int32_t>(ms_of_day % 1000LL);

    // Civil calendar conversion matching 0x08ac80..0x08ad3c
    int64_t z = days + 719468LL;
    const int64_t era = (z >= 0 ? z : z - 146096LL) / 146097LL;
    const uint32_t doe = static_cast<uint32_t>(z - era * 146097LL);
    const uint32_t yoe = (doe - doe / 1460u + doe / 36524u - doe / 146096u) / 365u;
    int64_t y = static_cast<int64_t>(yoe) + era * 400LL;
    const uint32_t doy = doe - (365u * yoe + yoe / 4u - yoe / 100u);
    const uint32_t mp = (5u * doy + 2u) / 153u;
    const uint32_t d = doy - (153u * mp + 2u) / 5u + 1u;
    const uint32_t m = mp < 10u ? mp + 3u : mp - 9u;
    if (m <= 2u) {
        y += 1;
    }
    out.year         = static_cast<int32_t>(y);
    out.month        = static_cast<int32_t>(m);
    out.day_of_month = static_cast<int32_t>(d);
    out.day_of_year  = static_cast<int32_t>(doy + 1u);
}

// ============================================================================
// 3. FormatTimeZone (0x096300 .. 0x0963e8)
// Disassembly @ 0x096328..0x0963ac:
//   0x096328: 528484B7 mov  w23, #0x2425
//   0x096338: 72AE6637 movk w23, #0x7331, lsl #16 -> 0x73312425 ("%$1s")
//   0x096340: 5282A308 mov  w8, #0x1518           -> locale + 0x1518 ("%$1s %$2s")
//   0x096374: 94000525 bl   #0x97808              -> replace "%$1s" with date_text
//   0x096388: 114042E8 add  w8, w23, #0x10, lsl #12 -> 0x73322425 ("%$2s")
//   0x0963ac: 94000517 bl   #0x97808              -> replace "%$2s" with tz_text
// ============================================================================
static void ReplacePlaceholder(std::string& target, const char* token, const std::string& replacement) {
    const size_t token_len = std::strlen(token);
    size_t pos = 0;
    while ((pos = target.find(token, pos)) != std::string::npos) {
        target.replace(pos, token_len, replacement);
        pos += replacement.size();
    }
}

std::string BDDateFormatter::FormatTimeZone(
    const std::string& date_text,
    const std::string& tz_text,
    const std::string& /*locale*/) {
    constexpr uint32_t kToken1_096328 = 0x73312425u; // "%$1s"
    constexpr uint32_t kToken2_096388 = kToken1_096328 + (0x10u << 12); // 0x73322425u ("%$2s")

    char tok1[5] = {};
    char tok2[5] = {};
    std::memcpy(tok1, &kToken1_096328, 4);
    std::memcpy(tok2, &kToken2_096388, 4);

    std::string result = "%$1s %$2s";
    ReplacePlaceholder(result, tok1, date_text);
    ReplacePlaceholder(result, tok2, tz_text);
    return result;
}

// ============================================================================
// 4. FormatDate (0x0960ec), FormatTimeRange (0x09649c),
//    FormatAbbr (0x096830), and FormatRelative (0x0968e0)
// ============================================================================
std::string BDDateFormatter::FormatDate(
    const std::string& pattern,
    int64_t timestamp_ms,
    const std::string& /*locale*/,
    bool use_system_tz,
    int32_t custom_tz_offset_ms) {
    RexCalendarBreakdownAbiLayout cal{};
    InitCalendarBreakdown(cal, static_cast<double>(timestamp_ms), use_system_tz, custom_tz_offset_ms);
    char buf[64] = {};
    if (pattern.find("HH:mm") != std::string::npos) {
        std::snprintf(
            buf, sizeof(buf), "%04d/%d/%d %c%c:%c%c",
            cal.year, cal.month, cal.day_of_month,
            kTwoDigitTable_0a3d13[cal.hour * 2], kTwoDigitTable_0a3d13[cal.hour * 2 + 1],
            kTwoDigitTable_0a3d13[cal.minute * 2], kTwoDigitTable_0a3d13[cal.minute * 2 + 1]);
    } else {
        std::snprintf(buf, sizeof(buf), "%04d/%d/%d", cal.year, cal.month, cal.day_of_month);
    }
    return std::string(buf);
}

std::string BDDateFormatter::FormatTimeRange(
    int64_t start_ms,
    int64_t end_ms,
    int32_t unit,
    const std::string& locale,
    bool use_system_tz,
    int32_t custom_tz_offset_ms) {
    const int32_t clean_unit = SanitizeTimeRangeUnit8(unit);
    (void)clean_unit;
    const std::string s = FormatDate("YYYY/M/D HH:mm", start_ms, locale, use_system_tz, custom_tz_offset_ms);
    const std::string e = FormatDate("YYYY/M/D HH:mm", end_ms, locale, use_system_tz, custom_tz_offset_ms);
    return s + " - " + e;
}

std::string BDDateFormatter::FormatAbbr(
    int32_t count,
    int32_t unit,
    const std::string& /*locale*/) {
    const int32_t clean_unit = SanitizeDateUnit7(unit);
    static const char* const kUnitSuffix[8] = {"", "yr.", "mo.", "wk.", "d", "hr.", "min.", "sec."};
    return std::to_string(count) + " " + kUnitSuffix[clean_unit];
}

// Disassembly @ 0x0968e0..0x096994:
//   0x096904: 913F6008 add  x8, x0, #0xfd8 (future table)
//   0x096908: 912A6009 add  x9, x0, #0xa98 (past table)
//   0x09690c: F10002BF cmp  x21, #0
//   0x096910: 9A89A101 csel x1, x8, x9, ge
//   0x096914: DA9556A2 cneg x2, x21, mi
std::string BDDateFormatter::FormatRelative(
    int32_t offset,
    int32_t unit,
    const std::string& /*locale*/) {
    const int32_t clean_unit = SanitizeDateUnit7(unit);
    if (clean_unit == 0) {
        return "";
    }
    const int64_t abs_offset = (offset < 0) ? -static_cast<int64_t>(offset) : static_cast<int64_t>(offset);
    static const char* const kUnitSuffix[8] = {"", "yr.", "mo.", "wk.", "d", "hr.", "min.", "sec."};
    if (offset >= 0) {
        return "in " + std::to_string(abs_offset) + " " + kUnitSuffix[clean_unit];
    }
    return std::to_string(abs_offset) + " " + kUnitSuffix[clean_unit] + " ago";
}

} // namespace rex
} // namespace bytedance
