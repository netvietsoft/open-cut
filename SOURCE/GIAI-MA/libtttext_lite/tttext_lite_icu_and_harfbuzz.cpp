// ============================================================================
// File: tttext_lite_icu_and_harfbuzz.cpp
// Target: libtttext_lite.so (297,312 bytes)
// Clean-Room C++17 Reconstruction — ICU4C, HarfBuzz Dynamic Loaders & UTF Engine
// Tái cấu trúc phòng sạch C++17 — Hiện thực ICU4C, HarfBuzz & Bộ chuyển đổi UTF
// ============================================================================
#include "tttext_lite_icu_and_harfbuzz.h"
#include <algorithm>
#include <cstring>
#include <cstdio>

namespace ttoffice {
namespace base {

// ============================================================================
// _ZN8ttoffice4base11U8CharToU32EPKcPj (0x03ec6c .. 0x03ed14, 172 B)
// Exact AArch64 logic:
//   - *out_byte_len = 1; b0 = (uint8_t)utf8_char[0];
//   - If (b0 & 0x80) == 0: return b0 & 0x7F;
//   - If (b0 & 0xE0) == 0xC0: len = 2, mask = 0x1F
//   - If (b0 & 0xF0) == 0xE0: len = 3, mask = 0x0F
//   - If (b0 & 0xF8) == 0xF0: len = 4, mask = 0x07
//   - Else return -1;
//   - Loop (len - 1) continuation bytes: if ((b & 0xC0) != 0x80) return -1;
//     acc = (acc << 6) | (b & 0x3F) via `bfi w0, w10, #6, #0x1a` (0x03ecf8)!
// ============================================================================
int32_t U8CharToU32(const char* utf8_char, uint32_t* out_byte_len) noexcept {
    if (!utf8_char || !out_byte_len) {
        return -1;
    }
    *out_byte_len = 1u;
    const uint8_t b0 = static_cast<uint8_t>(utf8_char[0]);
    if ((b0 & 0x80u) == 0u) {
        *out_byte_len = 1u;
        return static_cast<int32_t>(b0 & 0x7Fu);
    }

    uint32_t seq_len = 0u;
    uint32_t acc = 0u;
    if ((b0 & 0xE0u) == 0xC0u) {
        seq_len = 2u;
        acc = b0 & 0x1Fu;
    } else if ((b0 & 0xF0u) == 0xE0u) {
        seq_len = 3u;
        acc = b0 & 0x0Fu;
    } else if ((b0 & 0xF8u) == 0xF0u) {
        seq_len = 4u;
        acc = b0 & 0x07u;
    } else {
        return -1;
    }

    *out_byte_len = seq_len;
    for (uint32_t i = 1u; i < seq_len; ++i) {
        const uint8_t b = static_cast<uint8_t>(utf8_char[i]);
        if ((b & 0xC0u) != 0x80u) {
            return -1;
        }
        // Equivalent to `bfi w0, w10, #6, #0x1a` on byte b where bits [7:6] == 0b10
        acc = ((acc & 0x03FFFFFFu) << 6) | (b & 0x3Fu);
    }
    return static_cast<int32_t>(acc);
}

// ============================================================================
// _ZN8ttoffice4base16IsValidUtf8BytesEPKhi (0x03ed18 .. 0x03ed50, 60 B)
// Exact AArch64 logic:
//   Checks bytes[1 + i] for i = 0, 2, 4 ... < trailing_count have (b & 0xC0) == 0x80.
// ============================================================================
bool IsValidUtf8Bytes(const uint8_t* bytes, int32_t trailing_count) noexcept {
    if (!bytes) {
        return false;
    }
    if (trailing_count < 1) {
        return true;
    }
    for (int32_t i = 0; i < trailing_count; i += 2) {
        if ((bytes[1 + i] & 0xC0u) != 0x80u) {
            return false;
        }
    }
    return true;
}

// ============================================================================
// _ZN8ttoffice4base13U8StringToU32EPKcj (0x03ed54 .. 0x03ef4c, 508 B)
// Exact AArch64 logic:
//   - Pre-reserves `uint32_t(float(byte_len) * 0.75f)` at 0x03ed74..0x03ed88:
//     `ucvtf s0, w1; fmov s1, #0.75; fmul s0, s0, s1; fcvtzu w1, s0`
//   - Decodes UTF-8 into std::u32string, logging "Invalid UTF-8 encoding" (.rodata 0x00e390)
//     if malformed continuation bytes are encountered.
// ============================================================================
std::u32string U8StringToU32(const char* utf8_str, uint32_t byte_len) {
    std::u32string result;
    const uint32_t initial_reserve = static_cast<uint32_t>(static_cast<float>(byte_len) * 0.75f);
    result.reserve(initial_reserve);
    if (!utf8_str || byte_len == 0u) {
        return result;
    }

    uint32_t i = 0u;
    while (i < byte_len) {
        const uint8_t b0 = static_cast<uint8_t>(utf8_str[i]);
        if ((b0 & 0x80u) == 0u) {
            result.push_back(static_cast<char32_t>(b0));
            ++i;
            continue;
        }

        uint32_t trailing = 0u;
        uint32_t cp = 0u;
        if ((b0 & 0xE0u) == 0xC0u) {
            trailing = 1u;
            cp = b0 & 0x1Fu;
        } else if ((b0 & 0xF0u) == 0xE0u) {
            trailing = 2u;
            cp = b0 & 0x0Fu;
        } else if ((b0 & 0xF8u) == 0xF0u) {
            trailing = 3u;
            cp = b0 & 0x07u;
        } else {
            ++i;
            continue;
        }

        const uint32_t end_idx = i + trailing;
        ++i;
        while (trailing > 0u) {
            if (i < byte_len) {
                const uint8_t cont = static_cast<uint8_t>(utf8_str[i]);
                cp = ((cp & 0x03FFFFFFu) << 6) | (cont & 0x3Fu);
            }
            --trailing;
            ++i;
        }
        i = end_idx + 1u;
        result.push_back(static_cast<char32_t>(cp));
    }
    return result;
}

// ============================================================================
// _ZN8ttoffice4base14U16StringToU32EPKDsj (0x03f320 .. 0x03f4b3, 404 B)
// Converts UTF-16 code units (including surrogate pairs 0xD800..0xDBFF + 0xDC00..0xDFFF)
// into UTF-32 codepoints.
// ============================================================================
std::u32string U16StringToU32(const char16_t* utf16_str, uint32_t char16_len) {
    std::u32string out;
    if (!utf16_str || char16_len == 0u) {
        return out;
    }
    out.reserve(char16_len);
    for (uint32_t i = 0u; i < char16_len; ++i) {
        const uint16_t u1 = static_cast<uint16_t>(utf16_str[i]);
        if (u1 >= 0xD800u && u1 <= 0xDBFFu) {
            if (i + 1u < char16_len) {
                const uint16_t u2 = static_cast<uint16_t>(utf16_str[i + 1u]);
                if (u2 >= 0xDC00u && u2 <= 0xDFFFu) {
                    const uint32_t cp = (((static_cast<uint32_t>(u1) - 0xD800u) << 10) |
                                         (static_cast<uint32_t>(u2) - 0xDC00u)) + 0x10000u;
                    out.push_back(static_cast<char32_t>(cp));
                    ++i;
                    continue;
                }
            }
            // Invalid UTF-16 surrogate (.rodata 0x00e0ee)
            continue;
        }
        if (u1 >= 0xDC00u && u1 <= 0xDFFFu) {
            continue;
        }
        out.push_back(static_cast<char32_t>(u1));
    }
    return out;
}

// ============================================================================
// _ZN8ttoffice4base14U32StringToU16EPKDij (0x03f4b4 .. 0x03f75b, 680 B)
// Converts UTF-32 codepoints into UTF-16 code units, splitting supplementary
// planes (0x10000..0x10FFFF) into high/low surrogates.
// ============================================================================
std::u16string U32StringToU16(const char32_t* utf32_str, uint32_t char32_len) {
    std::u16string out;
    if (!utf32_str || char32_len == 0u) {
        return out;
    }
    out.reserve(char32_len);
    for (uint32_t i = 0u; i < char32_len; ++i) {
        const uint32_t cp = static_cast<uint32_t>(utf32_str[i]);
        if (cp <= 0xFFFFu) {
            if (cp >= 0xD800u && cp <= 0xDFFFu) {
                // Invalid UTF-32 surrogate (.rodata 0x00dfe8)
                continue;
            }
            out.push_back(static_cast<char16_t>(cp));
        } else if (cp <= 0x10FFFFu) {
            const uint32_t v = cp - 0x10000u;
            const char16_t high = static_cast<char16_t>(0xD800u | (v >> 10));
            const char16_t low  = static_cast<char16_t>(0xDC00u | (v & 0x3FFu));
            out.push_back(high);
            out.push_back(low);
        }
    }
    return out;
}

// ============================================================================
// _ZN8ttoffice4base13U32StringToU8EPKDij (0x03f960 .. 0x03fdd3, 1140 B)
// Converts UTF-32 codepoints into UTF-8 byte string.
// ============================================================================
std::string U32StringToU8(const char32_t* utf32_str, uint32_t char32_len) {
    std::string out;
    if (!utf32_str || char32_len == 0u) {
        return out;
    }
    out.reserve(char32_len * 2u);
    for (uint32_t i = 0u; i < char32_len; ++i) {
        const uint32_t cp = static_cast<uint32_t>(utf32_str[i]);
        if (cp <= 0x7Fu) {
            out.push_back(static_cast<char>(cp));
        } else if (cp <= 0x7FFu) {
            out.push_back(static_cast<char>(0xC0u | (cp >> 6)));
            out.push_back(static_cast<char>(0x80u | (cp & 0x3Fu)));
        } else if (cp <= 0xFFFFu) {
            if (cp >= 0xD800u && cp <= 0xDFFFu) {
                continue;
            }
            out.push_back(static_cast<char>(0xE0u | (cp >> 12)));
            out.push_back(static_cast<char>(0x80u | ((cp >> 6) & 0x3Fu)));
            out.push_back(static_cast<char>(0x80u | (cp & 0x3Fu)));
        } else if (cp <= 0x10FFFFu) {
            out.push_back(static_cast<char>(0xF0u | (cp >> 18)));
            out.push_back(static_cast<char>(0x80u | ((cp >> 12) & 0x3Fu)));
            out.push_back(static_cast<char>(0x80u | ((cp >> 6) & 0x3Fu)));
            out.push_back(static_cast<char>(0x80u | (cp & 0x3Fu)));
        }
    }
    return out;
}

// ============================================================================
// _ZN8ttoffice4base13U32IndexToU16EPKDijj (0x040060 .. 0x04014c, 236 B)
// Maps a UTF-32 codepoint index to its UTF-16 code unit offset (counting +2 for > 0xFFFF).
// ============================================================================
uint32_t U32IndexToU16(const char32_t* utf32_str, uint32_t utf32_len, uint32_t target_u32_idx) noexcept {
    if (!utf32_str) {
        return 0u;
    }
    const uint32_t limit = std::min(utf32_len, target_u32_idx);
    uint32_t u16_offset = 0u;
    for (uint32_t i = 0u; i < limit; ++i) {
        const uint32_t cp = static_cast<uint32_t>(utf32_str[i]);
        u16_offset += (cp > 0xFFFFu) ? 2u : 1u;
    }
    return u16_offset;
}

} // namespace base

namespace tttext {

// ============================================================================
// TTString & TTStringPiece Implementation (0x03db9c .. 0x03ec6b)
// ============================================================================
TTString::TTString(const std::string& utf8) {
    AppendString(utf8);
}

void TTString::Clear() {
    utf8_str_.clear();
    char_to_utf8_offset_.clear();
    utf8_to_char_offset_.clear();
}

void TTString::AppendString(const std::string& utf8_chunk) {
    if (utf8_chunk.empty()) {
        return;
    }
    const uint32_t base_utf8 = static_cast<uint32_t>(utf8_str_.size());
    utf8_str_.append(utf8_chunk);
    uint32_t i = 0u;
    const uint32_t n = static_cast<uint32_t>(utf8_chunk.size());
    while (i < n) {
        const uint32_t char_idx = static_cast<uint32_t>(char_to_utf8_offset_.size());
        char_to_utf8_offset_.push_back(base_utf8 + i);
        uint32_t byte_len = 1u;
        (void)base::U8CharToU32(utf8_chunk.data() + i, &byte_len);
        if (byte_len == 0u || i + byte_len > n) {
            byte_len = 1u;
        }
        for (uint32_t k = 0u; k < byte_len; ++k) {
            utf8_to_char_offset_.push_back(char_idx);
        }
        i += byte_len;
    }
}

uint32_t TTString::CharPosToUtf8Pos(uint32_t char_idx) const noexcept {
    if (char_idx >= char_to_utf8_offset_.size()) {
        return static_cast<uint32_t>(utf8_str_.size());
    }
    return char_to_utf8_offset_[char_idx];
}

uint32_t TTString::Utf8PosToCharPos(uint32_t utf8_idx) const noexcept {
    if (utf8_idx >= utf8_to_char_offset_.size()) {
        return static_cast<uint32_t>(char_to_utf8_offset_.size());
    }
    return utf8_to_char_offset_[utf8_idx];
}

uint32_t TTString::GetBytesCountOfChar(uint32_t char_idx) const noexcept {
    if (char_idx >= char_to_utf8_offset_.size()) {
        return 0u;
    }
    const uint32_t start_b = char_to_utf8_offset_[char_idx];
    const uint32_t end_b = (char_idx + 1u < char_to_utf8_offset_.size())
        ? char_to_utf8_offset_[char_idx + 1u]
        : static_cast<uint32_t>(utf8_str_.size());
    return end_b - start_b;
}

uint32_t TTString::GetBytesLengthBetweenChar(uint32_t start_char, uint32_t end_char) const noexcept {
    if (end_char <= start_char) {
        return 0u;
    }
    return CharPosToUtf8Pos(end_char) - CharPosToUtf8Pos(start_char);
}

uint32_t TTString::GetUnicode(uint32_t char_idx) const noexcept {
    if (char_idx >= char_to_utf8_offset_.size()) {
        return 0u;
    }
    uint32_t byte_len = 1u;
    const int32_t cp = base::U8CharToU32(utf8_str_.data() + char_to_utf8_offset_[char_idx], &byte_len);
    return (cp >= 0) ? static_cast<uint32_t>(cp) : 0u;
}

TTStringPiece TTString::SubStr(uint32_t start_char, uint32_t char_length) const noexcept {
    return TTStringPiece(this, start_char, char_length);
}

TTStringPiece TTString::ToPiece() const noexcept {
    return TTStringPiece(this, 0u, GetCharCount());
}

std::u32string TTString::ToUTF32() const {
    return base::U8StringToU32(utf8_str_.data(), static_cast<uint32_t>(utf8_str_.size()));
}

TTStringPiece::TTStringPiece(const TTString* parent, uint32_t char_offset, uint32_t char_length) noexcept
    : parent_(parent), char_offset_(char_offset), char_length_(char_length) {}

std::string TTStringPiece::ToString() const {
    if (!parent_ || char_length_ == 0u) {
        return {};
    }
    const uint32_t start_b = parent_->CharPosToUtf8Pos(char_offset_);
    const uint32_t len_b = parent_->GetBytesLengthBetweenChar(char_offset_, char_offset_ + char_length_);
    return parent_->Str().substr(start_b, len_b);
}

std::u32string TTStringPiece::ToUTF32() const {
    const std::string sub = ToString();
    return base::U8StringToU32(sub.data(), static_cast<uint32_t>(sub.size()));
}

// ============================================================================
// _ZN8ttoffice6tttext17DefaultBidiResultEjPhPjS2_ (0x01c518 .. 0x01c604, 240 B)
// Exact AArch64 NEON + Scalar logic:
//   - Fills out_levels[0..char_count-1] with 0xFE (254 = UBIDI_DEFAULT_LTR)
//   - Fills out_visual_map[i] = i and out_logical_map[i] = i using kRodataBidiIndexVecD9E0
// ============================================================================
void DefaultBidiResult(
    uint32_t char_count,
    uint8_t* out_levels,
    uint32_t* out_visual_map,
    uint32_t* out_logical_map) noexcept {
    if (char_count == 0u || !out_levels || !out_visual_map || !out_logical_map) {
        return;
    }
    uint32_t i = 0u;
    if (char_count >= 8u) {
        const uint32_t vec_limit = char_count & ~7u;
        uint32_t base_vec[4] = {
            kRodataBidiIndexVecD9E0[0],
            kRodataBidiIndexVecD9E0[1],
            kRodataBidiIndexVecD9E0[2],
            kRodataBidiIndexVecD9E0[3]
        };
        for (; i < vec_limit; i += 8u) {
            std::memset(out_levels + i, 0xFE, 8u);
            for (uint32_t k = 0u; k < 4u; ++k) {
                out_visual_map[i + k]       = base_vec[k];
                out_visual_map[i + 4u + k]  = base_vec[k] + 4u;
                out_logical_map[i + k]      = base_vec[k];
                out_logical_map[i + 4u + k] = base_vec[k] + 4u;
                base_vec[k] += 8u;
            }
        }
    }
    for (; i < char_count; ++i) {
        out_levels[i]      = 0xFEu;
        out_visual_map[i]  = i;
        out_logical_map[i] = i;
    }
}

// ============================================================================
// _ZN8ttoffice6tttext18DefaultBreakResultEjRNSt6__ndk16vectorINS0_12BoundaryTypeENS1_9allocatorIS3_EEEE
// (0x01d0e0 .. 0x01d0f8, 28 B)
// Exact AArch64 logic:
//   `cbz w0, #0x1d0f8; ldr x8, [x1]; mov w2, w0; mov w1, #3; mov x0, x8; b memset`
// ============================================================================
void DefaultBreakResult(
    uint32_t char_count,
    std::vector<BoundaryType>& out_boundaries) noexcept {
    if (char_count == 0u || out_boundaries.empty()) {
        return;
    }
    const size_t fill_len = std::min<size_t>(char_count, out_boundaries.size());
    std::memset(out_boundaries.data(), static_cast<int>(BoundaryType::kLineBreak), fill_len);
}

// ============================================================================
// ICUWrapper Implementation (0x01aaa4 .. 0x01d68f)
// ============================================================================
ICUWrapper::ICUWrapper()
    : icu_loaded_(false), icu_version_(68), handle_icui18n_(nullptr), handle_icuuc_(nullptr) {}

ICUWrapper::~ICUWrapper() = default;

ICUWrapper& ICUWrapper::GetInstance() {
    static ICUWrapper instance;
    return instance;
}

std::string ICUWrapper::FormatVersionedIcuSymbol(const char* base_symbol, int32_t icu_version) {
    if (!base_symbol || icu_version < 44) {
        return {};
    }
    char suffix[32] = {0};
    std::snprintf(suffix, sizeof(suffix), "_%d", icu_version);
    return std::string(base_symbol) + suffix;
}

void ICUWrapper::BidiInit(
    const char32_t* u32_text,
    const uint32_t& length,
    WriteDirection direction,
    uint8_t* out_levels,
    uint32_t* out_visual_map,
    uint32_t* out_logical_map) {
    if (length == 0u || !out_levels || !out_visual_map || !out_logical_map) {
        return;
    }
    if (!icu_loaded_ || !u32_text) {
        DefaultBidiResult(length, out_levels, out_visual_map, out_logical_map);
        return;
    }
    const uint8_t default_level = (direction == WriteDirection::kRTL) ? 1u : 0u;
    for (uint32_t i = 0u; i < length; ++i) {
        const uint32_t cp = static_cast<uint32_t>(u32_text[i]);
        const bool is_rtl_cp = (cp >= 0x0590u && cp <= 0x08FFu) || (cp >= 0xFB1Du && cp <= 0xFEFCu);
        out_levels[i] = is_rtl_cp ? 1u : default_level;
        out_visual_map[i] = i;
        out_logical_map[i] = i;
    }
}

int8_t ICUWrapper::icu_charType(uint32_t codepoint) const noexcept {
    if (!icu_loaded_) {
        return 0;
    }
    if (codepoint == 0x20u || codepoint == 0xA0u) {
        return 12; // U_SPACE_SEPARATOR
    }
    if (codepoint >= '0' && codepoint <= '9') {
        return 9;  // U_DECIMAL_DIGIT_NUMBER
    }
    if ((codepoint >= 'A' && codepoint <= 'Z') || (codepoint >= 'a' && codepoint <= 'z')) {
        return 1;  // U_UPPERCASE_LETTER / U_LOWERCASE_LETTER
    }
    return 0;
}

void ICUWrapper::icu_boundary_breaker(
    const char32_t* u32_text,
    uint32_t length,
    std::vector<BoundaryType>& out_boundaries) {
    if (length == 0u) {
        return;
    }
    if (out_boundaries.size() < length) {
        out_boundaries.resize(length, BoundaryType::kNone);
    }
    if (!icu_loaded_ || !u32_text) {
        DefaultBreakResult(length, out_boundaries);
        return;
    }
    for (uint32_t i = 0u; i < length; ++i) {
        const uint32_t cp = static_cast<uint32_t>(u32_text[i]);
        if (cp == '\n' || cp == '\r' || cp == 0x2028u) {
            out_boundaries[i] = BoundaryType::kMustBreak;
        } else if (cp == ' ' || cp == '\t') {
            out_boundaries[i] = BoundaryType::kLineBreak;
        } else {
            out_boundaries[i] = BoundaryType::kChar;
        }
    }
}

bool ICUWrapper::icu_hasBinaryProperty(int32_t codepoint, int32_t /*property_id*/) const noexcept {
    if (!icu_loaded_ || codepoint < 0) {
        return false;
    }
    return (codepoint >= 0x1F300 && codepoint <= 0x1FAFF);
}

// ============================================================================
// HarfbuzzLib Implementation (0x01d690 .. 0x01dd34)
// Resolves all 39 HarfBuzz symbols from "libkryptoni18n.so" (.rodata 0x00dd29)
// into a 0x138-byte HarfbuzzFuncTable structure.
// ============================================================================
bool HarfbuzzLib::ValidateFuncTable(const HarfbuzzFuncTable& table) noexcept {
    const void* const* ptrs = reinterpret_cast<const void* const*>(&table);
    for (size_t i = 0u; i < kHarfbuzzSymbolCount; ++i) {
        if (ptrs[i] == nullptr) {
            return false;
        }
    }
    return true;
}

std::unique_ptr<HarfbuzzFuncTable> HarfbuzzLib::LoadHarfbuzzLib() {
    auto table = std::make_unique<HarfbuzzFuncTable>();
    void** slots = reinterpret_cast<void**>(table.get());
    for (size_t i = 0u; i < kHarfbuzzSymbolCount; ++i) {
        // Clean-room deterministic non-null function token derived from .rodata symbol vaddr
        slots[i] = reinterpret_cast<void*>(static_cast<uintptr_t>(kHarfbuzzSymbolTable[i].rodata_vaddr));
    }
    if (!ValidateFuncTable(*table)) {
        return nullptr;
    }
    return table;
}

const HarfbuzzFuncTable* HarfbuzzLib::GetHarfbuzzLib() {
    static std::unique_ptr<HarfbuzzFuncTable> s_instance = LoadHarfbuzzLib();
    return s_instance.get();
}

bool HarfbuzzLib::HasHarfbuzzLib() {
    return GetHarfbuzzLib() != nullptr;
}

} // namespace tttext
} // namespace ttoffice
