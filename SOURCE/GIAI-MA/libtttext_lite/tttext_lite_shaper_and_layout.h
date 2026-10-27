// ============================================================================
// File: tttext_lite_shaper_and_layout.h
// Target: libtttext_lite.so (297,312 bytes)
// Clean-Room C++17 Reconstruction — Shaper, BoundaryAnalyst, StyleManager & Layout
// Tái cấu trúc phòng sạch C++17 — Bộ định hình chữ, Phân tích ranh giới & Bố cục
// ============================================================================
#pragma once

#include "tttext_lite_types.h"
#include "tttext_lite_rodata_tables.h"
#include "tttext_lite_icu_and_harfbuzz.h"
#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <memory>

namespace ttoffice {
namespace tttext {

// ============================================================================
// 1. BoundaryAnalyst (0x02b1dc .. 0x02b667)
//    Bộ phân tích ranh giới từ/dòng Unicode & CJK (0x02b1dc .. 0x02b667)
// ============================================================================
class BoundaryAnalyst {
public:
    // _ZN8ttoffice6tttext15BoundaryAnalystC2EPKDijNS0_17LineBreakStrategyE (0x02b1dc, 992 B)
    BoundaryAnalyst(const char32_t* u32_text, uint32_t char_count, LineBreakStrategy strategy);

    // Exact codepoint class classifier reconstructed from 0x02b254 .. 0x02b3b8
    // Returns class in {0: Neutral/Word, 1: Space/BreakAfter, 2: CJK/Ideograph,
    //                   3: OpenPunct/NoBreakAfter, 4: MustBreakNewline, 5: ClosePunct/NoBreakBefore}
    static uint32_t ClassifyCodepointForBreak(uint32_t cp) noexcept;

    // _ZNK8ttoffice6tttext15BoundaryAnalyst16FindNextBoundaryEjNS0_12BoundaryTypeE (0x02b5bc, 56 B)
    uint32_t FindNextBoundary(uint32_t start_pos, BoundaryType min_type) const noexcept;

    // _ZNK8ttoffice6tttext15BoundaryAnalyst16FindPrevBoundaryEjNS0_12BoundaryTypeE (0x02b5f4, 40 B)
    uint32_t FindPrevBoundary(uint32_t start_pos, BoundaryType min_type) const noexcept;

    // _ZN8ttoffice6tttext15BoundaryAnalyst19UpgradeBoundaryTypeERKNS0_5RangeENS0_12BoundaryTypeE (0x02b61c, 76 B)
    void UpgradeBoundaryType(const Range& range, BoundaryType new_type) noexcept;

    const std::vector<BoundaryType>& Boundaries() const noexcept { return boundary_types_; }

private:
    std::vector<BoundaryType> boundary_types_{};
};

// ============================================================================
// 2. LayoutMeasurer (0x02ca68 .. 0x02cbf4)
//    Bộ đo lường chiều cao dòng và căn chỉnh dọc (0x02ca68 .. 0x02cbf4)
// ============================================================================
class LayoutMeasurer {
public:
    LayoutMeasurer() = default;
    virtual ~LayoutMeasurer() = default;

    // _ZN8ttoffice6tttext14LayoutMeasurer24CalcRunHeightByLinePitchERKNS0_7SpacingEff (0x02ca84, 156 B)
    static float CalcRunHeightByLinePitch(
        const Spacing& spacing,
        float run_height,
        float line_pitch) noexcept;

    // _ZN8ttoffice6tttext14LayoutMeasurer19GetLineSpacingRatioERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE (0x02cb20, 8 B)
    static float GetLineSpacingRatio(const std::string& locale) noexcept;

    // _ZN8ttoffice6tttext14LayoutMeasurer19GetLinePitchSpacingEfff (0x02cb28, 36 B)
    static float GetLinePitchSpacing(float run_height, float line_pitch, float ratio) noexcept;

    // _ZN8ttoffice6tttext14LayoutMeasurer12CalcElementYENS0_26CharacterVerticalAlignmentEffff (0x02cb94, 100 B)
    static float CalcElementY(
        CharacterVerticalAlignment alignment,
        float line_ascent,
        float line_descent,
        float elem_ascent,
        float elem_descent) noexcept;
};

// ============================================================================
// 3. AttributesRangeList & StyleManager (0x032fa0 .. 0x03453b)
//    Quản lý phạm vi thuộc tính và kiểu chữ (0x032fa0 .. 0x03453b)
// ============================================================================
struct AttrRangeEntry {
    Range range{};
    uint64_t value{0};
};

class AttributesRangeList {
public:
    // _ZN8ttoffice6tttext19AttributesRangeList13SetRangeValueERKNS0_5RangeEm (0x032fa0, 1468 B)
    void SetRangeValue(const Range& range, uint64_t value);

    // _ZNK8ttoffice6tttext19AttributesRangeList12GetAttrValueEj (0x0337a0, 76 B)
    uint64_t GetAttrValue(uint32_t char_pos) const noexcept;

    // _ZNK8ttoffice6tttext19AttributesRangeList17GetAttributeRangeEj (0x0337ec, 128 B)
    AttrRangeEntry GetAttributeRange(uint32_t char_pos) const noexcept;

    bool Empty() const noexcept { return entries_.empty(); }

private:
    std::vector<AttrRangeEntry> entries_{};
};

class StyleManager {
public:
    StyleManager() = default;

    // _ZN8ttoffice6tttext12StyleManager13GetStyleValueEPKNS0_5StyleENS0_13AttributeTypeE (0x033990, 156 B)
    static uint64_t GetStyleValue(const Style* style, AttributeType attr_type) noexcept;

    // _ZNK8ttoffice6tttext12StyleManager8SetStyleEPNS0_5StyleEmNS0_13AttributeTypeE (0x033c74, 272 B)
    static void SetStyle(Style* style, uint64_t value, AttributeType attr_type) noexcept;

    // _ZN8ttoffice6tttext12StyleManager17ApplyStyleInRangeERKNS0_5StyleEjj (0x03386c, 292 B)
    void ApplyStyleInRange(const Style& style, uint32_t start_char, uint32_t char_len);

    // _ZNK8ttoffice6tttext12StyleManager8GetStyleEj (0x033a2c, 584 B)
    Style GetStyle(uint32_t char_pos) const;

    // _ZN8ttoffice6tttext12StyleManager30SetExtraFloatAttributesInRangeENS0_13AttributeTypeEfjj (0x0340f4, 312 B)
    void SetExtraFloatAttributesInRange(AttributeType attr_type, float value, uint32_t start_char, uint32_t char_len);

    // _ZN8ttoffice6tttext12StyleManager23GetExtraFloatAttributesENS0_13AttributeTypeEjf (0x0343d8, 356 B)
    float GetExtraFloatAttributes(AttributeType attr_type, uint32_t char_pos, float default_val) const noexcept;

private:
    std::array<AttributesRangeList, 20> attr_lists_{};
};

// ============================================================================
// 4. BaseRun, ShapeResult, TTShaper, ParagraphImpl & TextLayout (0x02445c .. 0x03d288)
//    Các lớp Run, Shaper, ParagraphImpl & TextLayout (0x02445c .. 0x03d288)
// ============================================================================
struct GlyphData {
    uint16_t glyph_id{0};
    float advance_x{0.0f};
    float pos_x{0.0f};
    float pos_y{0.0f};
    uint32_t cluster{0};
};

class ShapeResult {
public:
    ShapeResult() = default;

    // _ZNK8ttoffice6tttext11ShapeResult12MeasureWidthEjjf (0x03d140, 200 B)
    float MeasureWidth(uint32_t start_char, uint32_t char_count, float letter_spacing) const noexcept;

    void AppendGlyph(uint16_t glyph_id, float advance_x, float x, float y, uint32_t cluster);
    uint32_t GlyphCount() const noexcept { return static_cast<uint32_t>(glyphs_.size()); }
    const std::vector<GlyphData>& Glyphs() const noexcept { return glyphs_; }

private:
    std::vector<GlyphData> glyphs_{};
};

class BaseRun {
public:
    BaseRun() = default;
    BaseRun(const std::u32string& text, const Style& style);
    virtual ~BaseRun() = default;

    // _ZN8ttoffice6tttext7BaseRun14ControlRunListEv (0x0307f4, 12 B -> returns 0x048008)
    static const ControlRunEntry* ControlRunList() noexcept;

    // _ZN8ttoffice6tttext7BaseRun9SpaceListEv (0x030800, 12 B -> returns 0x048068)
    static const char* const* SpaceList() noexcept;

    // _ZNK8ttoffice6tttext7BaseRun8GetWidthEjj (0x03080c, 248 B)
    float GetWidth(uint32_t start_char, uint32_t char_count) const noexcept;

    // _ZNK8ttoffice6tttext7BaseRun17MeasureRunByWidthERjf (0x030904, 292 B)
    float MeasureRunByWidth(uint32_t& in_out_char_count, float max_width) const noexcept;

    // _ZN8ttoffice6tttext7BaseRun6LayoutEv (0x030a28, 2116 B)
    void Layout();

    uint32_t CharCount() const noexcept { return static_cast<uint32_t>(u32_text_.size()); }
    const Style& GetStyle() const noexcept { return style_; }

private:
    std::u32string u32_text_{};
    Style style_{};
    ShapeResult shape_result_{};
};

class ParagraphImpl {
public:
    // _ZN8ttoffice6tttext13ParagraphImplC2Ev (0x02ea58, 512 B)
    ParagraphImpl();
    virtual ~ParagraphImpl() = default;

    // _ZN8ttoffice6tttext13ParagraphImpl10AddTextRunERKNS0_5StyleEPKcjb (0x02e480, 1132 B)
    void AddTextRun(const Style& style, const char* utf8_text, uint32_t byte_length, bool is_ghost);

    // _ZNK8ttoffice6tttext13ParagraphImpl17ApplyStyleInRangeERKNS0_5StyleEjj (0x02d90c, 296 B)
    void ApplyStyleInRange(const Style& style, uint32_t start_char, uint32_t char_count);

    // _ZNK8ttoffice6tttext13ParagraphImpl20GetMaxIntrinsicWidthEv (0x02da34, 576 B)
    float GetMaxIntrinsicWidth() const noexcept;

    // _ZNK8ttoffice6tttext13ParagraphImpl20GetMinIntrinsicWidthEv (0x02dc74, 8 B)
    float GetMinIntrinsicWidth() const noexcept { return min_intrinsic_width_; }

    // _ZNK8ttoffice6tttext13ParagraphImpl15GetWordBoundaryEj (0x02dc7c, 116 B)
    Range GetWordBoundary(uint32_t char_pos) const;

    // _ZN8ttoffice6tttext13ParagraphImpl13FormatRunListEv (0x02f088, 3912 B)
    void FormatRunList();

    const TTString& GetContent() const noexcept { return content_; }
    const ParagraphStyle& GetParagraphStyle() const noexcept { return paragraph_style_; }
    void SetParagraphStyle(const ParagraphStyle& ps) { paragraph_style_ = ps; }
    const std::vector<std::unique_ptr<BaseRun>>& Runs() const noexcept { return runs_; }

private:
    TTString content_{};
    ParagraphStyle paragraph_style_{};
    StyleManager style_manager_{};
    std::vector<std::unique_ptr<BaseRun>> runs_{};
    float max_intrinsic_width_{0.0f};
    float min_intrinsic_width_{0.0f};
};

// ============================================================================
// 5. TTTextJNIProxy & JNI Entry Points (0x019c64 .. 0x01a9cf)
//    Lớp cầu nối JNI TTTextJNIProxy & Các điểm nhập JNI (0x019c64 .. 0x01a9cf)
// ============================================================================
class TTTextJNIProxy {
public:
    static TTTextJNIProxy& GetInstance();
    int32_t OnLoad(uint64_t java_vm_handle) noexcept;
    void InitialCache() noexcept;
    const TTTextJniCacheState& CacheState() const noexcept { return cache_; }

private:
    TTTextJniCacheState cache_{};
};

} // namespace tttext
} // namespace ttoffice
