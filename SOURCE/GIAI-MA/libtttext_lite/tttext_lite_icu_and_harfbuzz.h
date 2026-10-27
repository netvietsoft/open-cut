// ============================================================================
// File: tttext_lite_icu_and_harfbuzz.h
// Target: libtttext_lite.so (297,312 bytes)
// Clean-Room C++17 Reconstruction — ICU4C, HarfBuzz Dynamic Loaders & UTF Engine
// Tái cấu trúc phòng sạch C++17 — Bộ nạp động ICU4C, HarfBuzz & Bộ chuyển đổi UTF
// ============================================================================
#pragma once

#include "tttext_lite_types.h"
#include "tttext_lite_rodata_tables.h"
#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>

namespace ttoffice {
namespace base {

// ============================================================================
// 1. UTF-8 / UTF-16 / UTF-32 Conversion Suite (0x03ec6c .. 0x04014c)
//    Bộ hàm chuyển đổi mã hóa UTF-8 / UTF-16 / UTF-32 (0x03ec6c .. 0x04014c)
// ============================================================================
// _ZN8ttoffice4base11U8CharToU32EPKcPj (0x03ec6c, 172 B)
int32_t U8CharToU32(const char* utf8_char, uint32_t* out_byte_len) noexcept;

// _ZN8ttoffice4base16IsValidUtf8BytesEPKhi (0x03ed18, 60 B)
bool IsValidUtf8Bytes(const uint8_t* bytes, int32_t trailing_count) noexcept;

// _ZN8ttoffice4base13U8StringToU32EPKcj (0x03ed54, 508 B)
std::u32string U8StringToU32(const char* utf8_str, uint32_t byte_len);

// _ZN8ttoffice4base14U16StringToU32EPKDsj (0x03f320, 404 B)
std::u32string U16StringToU32(const char16_t* utf16_str, uint32_t char16_len);

// _ZN8ttoffice4base14U32StringToU16EPKDij (0x03f4b4, 680 B)
std::u16string U32StringToU16(const char32_t* utf32_str, uint32_t char32_len);

// _ZN8ttoffice4base13U32StringToU8EPKDij (0x03f960, 1140 B)
std::string U32StringToU8(const char32_t* utf32_str, uint32_t char32_len);

// _ZN8ttoffice4base13U32IndexToU16EPKDijj (0x040060, 236 B)
uint32_t U32IndexToU16(const char32_t* utf32_str, uint32_t utf32_len, uint32_t target_u32_idx) noexcept;

} // namespace base

namespace tttext {

// ============================================================================
// 2. TTString & TTStringPiece (0x03db9c .. 0x03ec6b)
//    Lớp chuỗi đa mã hóa TTString & TTStringPiece (0x03db9c .. 0x03ec6b)
// ============================================================================
class TTStringPiece;

class TTString {
public:
    TTString() = default;
    explicit TTString(const std::string& utf8);
    virtual ~TTString() = default;

    // _ZN8ttoffice6tttext8TTString5ClearEv (0x03dc9c, 60 B)
    void Clear();

    // _ZN8ttoffice6tttext8TTString12AppendStringERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE (0x03df78, 984 B)
    void AppendString(const std::string& utf8_chunk);

    // _ZNK8ttoffice6tttext8TTString16CharPosToUtf8PosEj (0x03dc68, 52 B)
    uint32_t CharPosToUtf8Pos(uint32_t char_idx) const noexcept;

    // _ZNK8ttoffice6tttext8TTString16Utf8PosToCharPosEj (0x03deb0, 44 B)
    uint32_t Utf8PosToCharPos(uint32_t utf8_idx) const noexcept;

    // _ZNK8ttoffice6tttext8TTString19GetBytesCountOfCharEj (0x03dedc, 156 B)
    uint32_t GetBytesCountOfChar(uint32_t char_idx) const noexcept;

    // _ZNK8ttoffice6tttext8TTString25GetBytesLengthBetweenCharEjj (0x03dbe8, 128 B)
    uint32_t GetBytesLengthBetweenChar(uint32_t start_char, uint32_t end_char) const noexcept;

    // _ZNK8ttoffice6tttext8TTString10GetUnicodeEj (0x03dda8, 240 B)
    uint32_t GetUnicode(uint32_t char_idx) const noexcept;

    // _ZNK8ttoffice6tttext8TTString6SubStrEjj (0x03dbc0, 24 B)
    TTStringPiece SubStr(uint32_t start_char, uint32_t char_length) const noexcept;

    // _ZNK8ttoffice6tttext8TTString7ToPieceEv (0x03db9c, 36 B)
    TTStringPiece ToPiece() const noexcept;

    // _ZNK8ttoffice6tttext8TTString7ToUTF32Ev (0x03e350, 376 B)
    std::u32string ToUTF32() const;

    const std::string& Str() const noexcept { return utf8_str_; }
    uint32_t GetCharCount() const noexcept { return static_cast<uint32_t>(char_to_utf8_offset_.size()); }

private:
    std::string utf8_str_{};
    std::vector<uint32_t> char_to_utf8_offset_{};
    std::vector<uint32_t> utf8_to_char_offset_{};
};

class TTStringPiece {
public:
    // _ZN8ttoffice6tttext13TTStringPieceC2EPKNS0_8TTStringEjj (0x03e6b0, 24 B)
    TTStringPiece(const TTString* parent, uint32_t char_offset, uint32_t char_length) noexcept;
    virtual ~TTStringPiece() = default;

    // _ZNK8ttoffice6tttext13TTStringPiece8ToStringEv (0x03e6e0, 284 B)
    std::string ToString() const;

    // _ZNK8ttoffice6tttext13TTStringPiece7ToUTF32Ev (0x03eba4, 200 B)
    std::u32string ToUTF32() const;

    uint32_t GetOffset() const noexcept { return char_offset_; }
    uint32_t GetLength() const noexcept { return char_length_; }

private:
    const TTString* parent_{nullptr};
    uint32_t char_offset_{0};
    uint32_t char_length_{0};
};

// ============================================================================
// 3. ICUWrapper & Bidi / Break Analysis (0x01a9d0 .. 0x01d68f)
//    Trình bọc ICUWrapper & Phân tích Bidi / Ngắt dòng (0x01a9d0 .. 0x01d68f)
// ============================================================================
// _ZN8ttoffice6tttext17DefaultBidiResultEjPhPjS2_ (0x01c518, 240 B)
void DefaultBidiResult(
    uint32_t char_count,
    uint8_t* out_levels,
    uint32_t* out_visual_map,
    uint32_t* out_logical_map) noexcept;

// _ZN8ttoffice6tttext18DefaultBreakResultEjRNSt6__ndk16vectorINS0_12BoundaryTypeENS1_9allocatorIS3_EEEE (0x01d0e0, 28 B)
void DefaultBreakResult(
    uint32_t char_count,
    std::vector<BoundaryType>& out_boundaries) noexcept;

class ICUWrapper {
public:
    // _ZN8ttoffice6tttext10ICUWrapperC2Ev (0x01c150, 496 B)
    ICUWrapper();
    // _ZN8ttoffice6tttext10ICUWrapperD2Ev (0x01c340, 356 B)
    ~ICUWrapper();

    // _ZN8ttoffice6tttext10ICUWrapper11GetInstanceEv (0x01c4a4, 116 B)
    static ICUWrapper& GetInstance();

    // Probes /system/usr/icu for icudt<ver>l.dat (ver >= 44) and resolves symbol_<ver> (0x01aaa4..0x01ad34)
    static std::string FormatVersionedIcuSymbol(const char* base_symbol, int32_t icu_version);

    // _ZN8ttoffice6tttext10ICUWrapper8BidiInitEPKDiRKjNS0_14WriteDirectionEPhPjS8_ (0x01c608, 2636 B)
    void BidiInit(
        const char32_t* u32_text,
        const uint32_t& length,
        WriteDirection direction,
        uint8_t* out_levels,
        uint32_t* out_visual_map,
        uint32_t* out_logical_map);

    // _ZN8ttoffice6tttext10ICUWrapper12icu_charTypeEj (0x01d054, 140 B)
    int8_t icu_charType(uint32_t codepoint) const noexcept;

    // _ZN8ttoffice6tttext10ICUWrapper20icu_boundary_breakerEPKDijRNSt6__ndk16vectorINS0_12BoundaryTypeENS4_9allocatorIS6_EEEE (0x01d0fc, 1248 B)
    void icu_boundary_breaker(
        const char32_t* u32_text,
        uint32_t length,
        std::vector<BoundaryType>& out_boundaries);

    // _ZN8ttoffice6tttext10ICUWrapper21icu_hasBinaryPropertyEi9UProperty (0x01d5dc, 180 B)
    bool icu_hasBinaryProperty(int32_t codepoint, int32_t property_id) const noexcept;

    bool IsLoaded() const noexcept { return icu_loaded_; }
    int32_t DetectedVersion() const noexcept { return icu_version_; }

private:
    bool icu_loaded_{false};
    int32_t icu_version_{68};
    void* handle_icui18n_{nullptr};
    void* handle_icuuc_{nullptr};
};

// ============================================================================
// 4. HarfbuzzLib Dynamic Loader (0x01d690 .. 0x01dd34)
//    Trình nạp động thư viện HarfbuzzLib (0x01d690 .. 0x01dd34)
// ============================================================================
class HarfbuzzLib {
public:
    // _ZN8ttoffice6tttext11HarfbuzzLib14HasHarfbuzzLibEv (0x01d690, 124 B)
    static bool HasHarfbuzzLib();

    // _ZN8ttoffice6tttext11HarfbuzzLib14GetHarfbuzzLibEv (0x01d724, 116 B)
    static const HarfbuzzFuncTable* GetHarfbuzzLib();

    // _ZN8ttoffice6tttext11HarfbuzzLib15LoadHarfbuzzLibEv (0x01d798, 1436 B)
    static std::unique_ptr<HarfbuzzFuncTable> LoadHarfbuzzLib();

    // Validates that all 39 function pointers in HarfbuzzFuncTable are non-null (0x01dadc..0x01dbee)
    static bool ValidateFuncTable(const HarfbuzzFuncTable& table) noexcept;
};

} // namespace tttext
} // namespace ttoffice
