// ============================================================================
// File: tttext_lite_shaper_and_layout.cpp
// Target: libtttext_lite.so (297,312 bytes)
// Clean-Room C++17 Reconstruction — Shaper, BoundaryAnalyst, StyleManager & Layout
// Tái cấu trúc phòng sạch C++17 — Hiện thực Shaper, BoundaryAnalyst, StyleManager & Layout
// ============================================================================
#include "tttext_lite_shaper_and_layout.h"
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>

namespace ttoffice {
namespace tttext {

// ============================================================================
// 1. PointF, Range, RangeF, RectF Implementation (0x03d28c .. 0x03db98)
// ============================================================================
// _ZNK8ttoffice6tttext6PointFeqERKS1_ (0x03d28c .. 0x03d2ec, 100 B)
bool PointF::operator==(const PointF& rhs) const noexcept {
    if (x != rhs.x && std::fabs(x - rhs.x) >= kFloatEpsilon) {
        return false;
    }
    if (y == rhs.y) {
        return true;
    }
    return std::fabs(y - rhs.y) < kFloatEpsilon;
}

// _ZN8ttoffice6tttext5Range9SetLengthEj (0x03d2f0 .. 0x03d300, 20 B)
// `ldr w8, [x0]; adds w8, w8, w1; csinv w8, w8, wzr, lo; str w8, [x0, #4]; ret`
void Range::SetLength(uint32_t len) noexcept {
    const uint64_t sum = static_cast<uint64_t>(start) + static_cast<uint64_t>(len);
    end = (sum > 0xFFFFFFFFULL) ? 0xFFFFFFFFu : static_cast<uint32_t>(sum);
}

// _ZN8ttoffice6tttext5Range5MergeERKS1_ (0x03d304 .. 0x03d3a0, 160 B)
void Range::Merge(const Range& other) noexcept {
    if (IsEmpty()) {
        *this = other;
        return;
    }
    if (other.IsEmpty()) {
        return;
    }
    if (start == other.end || end == other.start) {
        start = std::min(start, other.start);
        end   = std::max(end, other.end);
        return;
    }
    if (other.end > start && end > other.start) {
        const uint32_t ov_start = std::max(start, other.start);
        const uint32_t ov_end   = std::min(end, other.end);
        if (ov_end > ov_start) {
            start = std::min(start, other.start);
            end   = std::max(end, other.end);
        }
    }
}

// _ZN8ttoffice6tttext5Range9IntersectERKS1_S3_ (0x03d3a4 .. 0x03d3ec, 76 B)
Range Range::Intersect(const Range& a, const Range& b) noexcept {
    if (a.IsEmpty() || a.end <= b.start || b.end <= a.start) {
        return Range{0u, 0u};
    }
    return Range{std::max(a.start, b.start), std::min(a.end, b.end)};
}

// _ZN8ttoffice6tttext5Range9IntersectERKS1_ (0x03d4b4 .. 0x03d4f8, 72 B)
void Range::Intersect(const Range& other) noexcept {
    *this = Intersect(*this, other);
}

// _ZN8ttoffice6tttext5Range10DifferenceERKS1_ (0x03d3f0 .. 0x03d484, 152 B)
Range Range::Difference(const Range& other) noexcept {
    if (IsEmpty() || other.IsEmpty()) {
        return Range{0u, 0u};
    }
    uint32_t ov_start = 0u;
    uint32_t ov_end   = 0u;
    if (other.end > start && end > other.start) {
        ov_start = std::max(start, other.start);
        ov_end   = std::min(end, other.end);
    }
    if (ov_end <= ov_start) {
        return Range{0u, 0u};
    }
    if (start == ov_start && end == ov_end) {
        start = 0u;
        end   = 0u;
        return Range{0u, 0u};
    }
    if (start != ov_start) {
        const uint32_t old_end = end;
        end = ov_start;
        if (old_end == ov_end) {
            return Range{0u, 0u};
        }
        return Range{ov_end, old_end};
    }
    start = ov_end;
    return Range{0u, 0u};
}

// _ZN8ttoffice6tttext5Range4SwapEv (0x03d4fc .. 0x03d508, 16 B)
// `ldr d0, [x0]; rev64 v0.2s, v0.2s; str d0, [x0]; ret`
void Range::Swap() noexcept {
    std::swap(start, end);
}

// _ZNK8ttoffice6tttext5RangeeqERKS1_ (0x03d488 .. 0x03d4b0, 44 B)
bool Range::operator==(const Range& rhs) const noexcept {
    return start == rhs.start && end == rhs.end;
}

// _ZNK8ttoffice6tttext5RangeltERKS1_ (0x03d50c .. 0x03d540, 56 B)
bool Range::operator<(const Range& rhs) const noexcept {
    if (start != rhs.start) {
        return start < rhs.start;
    }
    return end < rhs.end;
}

// _ZNK8ttoffice6tttext5RangegtERKS1_ (0x03d544 .. 0x03d578, 56 B)
bool Range::operator>(const Range& rhs) const noexcept {
    if (start != rhs.start) {
        return start > rhs.start;
    }
    return end > rhs.end;
}

// _ZN8ttoffice6tttext6RangeF5MergeERKS1_ (0x03d57c .. 0x03d690, 280 B)
void RangeF::Merge(const RangeF& other) noexcept {
    if (std::fabs(end - start) < kFloatEpsilon) {
        *this = other;
        return;
    }
    if (std::fabs(other.end - other.start) < kFloatEpsilon) {
        return;
    }
    start = std::min(start, other.start);
    end   = std::max(end, other.end);
}

// _ZN8ttoffice6tttext6RangeF10DifferenceERKS1_ (0x03d694 .. 0x03d81c, 396 B)
RangeF RangeF::Difference(const RangeF& other) noexcept {
    if (std::fabs(end - start) < kFloatEpsilon || std::fabs(other.end - other.start) < kFloatEpsilon) {
        return RangeF{0.0f, 0.0f};
    }
    const float ov_start = std::max(start, other.start);
    const float ov_end   = std::min(end, other.end);
    if (ov_end - ov_start < kFloatEpsilon) {
        return RangeF{0.0f, 0.0f};
    }
    if (std::fabs(start - ov_start) < kFloatEpsilon && std::fabs(end - ov_end) < kFloatEpsilon) {
        start = 0.0f;
        end   = 0.0f;
        return RangeF{0.0f, 0.0f};
    }
    if (std::fabs(start - ov_start) >= kFloatEpsilon) {
        const float old_end = end;
        end = ov_start;
        if (std::fabs(old_end - ov_end) < kFloatEpsilon) {
            return RangeF{0.0f, 0.0f};
        }
        return RangeF{ov_end, old_end};
    }
    start = ov_end;
    return RangeF{0.0f, 0.0f};
}

// _ZNK8ttoffice6tttext5RectF8ContainsEff (0x03d820 .. 0x03d904, 232 B)
bool RectF::Contains(float px, float py) const noexcept {
    if (px != left && (px - left) < kFloatEpsilon && std::fabs(px - left) >= kFloatEpsilon) {
        return false;
    }
    const float right = left + width;
    if (right == px || (right - px) < kFloatEpsilon) {
        return false;
    }
    if (py != top && (py - top) < kFloatEpsilon && std::fabs(py - top) >= kFloatEpsilon) {
        return false;
    }
    const float bottom = top + height;
    return (bottom != py) && ((bottom - py) >= kFloatEpsilon);
}

// _ZNK8ttoffice6tttext5RectF10InterSectsEffff (0x03d908 .. 0x03d9bc, 184 B)
bool RectF::InterSects(float l, float t, float r, float b) const noexcept {
    if (left != r && (left - r) >= kFloatEpsilon) {
        return false;
    }
    if (top != b && (top - b) >= kFloatEpsilon) {
        return false;
    }
    const float right = left + width;
    if (right != l && (l - right) >= kFloatEpsilon) {
        return false;
    }
    const float bottom = top + height;
    return (bottom == t) || ((t - bottom) < kFloatEpsilon);
}

// _ZNK8ttoffice6tttext5RectF10InterSectsERKS1_ (0x03d9c0 .. 0x03da88, 204 B)
bool RectF::InterSects(const RectF& other) const noexcept {
    return InterSects(other.left, other.top, other.left + other.width, other.top + other.height);
}

// _ZNK8ttoffice6tttext5RectF7IsEmptyEv (0x03da8c .. 0x03dae4, 92 B)
bool RectF::IsEmpty() const noexcept {
    if (width == 0.0f || std::fabs(width) < kFloatEpsilon) {
        return true;
    }
    if (height == 0.0f) {
        return true;
    }
    return std::fabs(height) < kFloatEpsilon;
}

// _ZNK8ttoffice6tttext5RectFeqERKS1_ (0x03dae8 .. 0x03db98, 180 B)
bool RectF::operator==(const RectF& other) const noexcept {
    if (left != other.left && std::fabs(left - other.left) >= kFloatEpsilon) {
        return false;
    }
    if (top != other.top && std::fabs(top - other.top) >= kFloatEpsilon) {
        return false;
    }
    if (width != other.width && std::fabs(width - other.width) >= kFloatEpsilon) {
        return false;
    }
    if (height == other.height) {
        return true;
    }
    return std::fabs(height - other.height) < kFloatEpsilon;
}

// ============================================================================
// 2. TTColor & Style Implementation (0x031ea4 .. 0x034704)
// ============================================================================
// _ZNK8ttoffice6tttext7TTColor11ToHexStringEv (0x03453c .. 0x03469c, 200 B)
std::string TTColor::ToHexString() const {
    char buf[16] = {0};
    std::snprintf(buf, 9, "%8x", argb);
    return std::string(buf);
}

// _ZN8ttoffice6tttext7TTColor13ReadHexStringEPKc (0x0346a0 .. 0x034704, 104 B)
TTColor TTColor::ReadHexString(const char* hex_str) noexcept {
    if (!hex_str) {
        return TTColor{0u};
    }
    uint32_t parsed = 0u;
    const int matched = std::sscanf(hex_str, "%8x", &parsed);
    return TTColor{(matched == 0) ? 0u : parsed};
}

// _ZN8ttoffice6tttext5Style12DefaultStyleEv (0x031ea4, 220 B)
const Style& Style::DefaultStyle() {
    static const Style kDefault{};
    return kDefault;
}

// ============================================================================
// 3. BoundaryAnalyst Implementation (0x02b1dc .. 0x02b667)
// ============================================================================
// Reconstructed from 0x02b254 .. 0x02b3b8:
//   w9  = -0x4e00, w10 = -0x3400, w11 = -0x3040, w12 = -0x2013
//   w14 = 0x00080440, w15 = 0x00000220, x16 = .rodata 0x00d9fc
//   w17 = -0xff01, w0 = -0x3001, w1 = 0xff5e, w2 = 0x00010403, w3 = 0x00008200, w4 = 0x46000901
uint32_t BoundaryAnalyst::ClassifyCodepointForBreak(uint32_t cp) noexcept {
    if (cp == 0u) {
        return 1u;
    }
    if ((cp & 0xFFFF0000u) == 0x00020000u) {
        return 2u; // SIP CJK Unified Ideographs Extension B..F
    }
    if ((cp - 0x3040u) < 0xC0u) {
        return 2u; // Hiragana / Katakana (U+3040..U+30FF)
    }
    if (((cp - 0x4E00u) >> 9) < 0x29u) {
        return 2u; // CJK Unified Ideographs (U+4E00..U+9FFF)
    }
    if (((cp - 0x3400u) >> 6) < 0x67u) {
        return 2u; // CJK Unified Ideographs Extension A (U+3400..U+4DBF)
    }
    if (cp <= 0x3000u) {
        const uint32_t ascii_idx = cp - 9u;
        if (ascii_idx <= 0xAEu) {
            const uint8_t rel_off = kBoundaryCharJumpTableD9FC[ascii_idx];
            switch (rel_off) {
                case 0x00u: return 1u; // 0x2b2ac + (0x00<<2) = 0x2b2ac (w5=1: Tab/LF/CR/Space/NBSP)
                case 0x1Fu: return 4u; // 0x2b2ac + (0x1f<<2) = 0x2b328 (mov w5, #4: Hyphen/Break-after)
                case 0x3Eu: return 3u; // 0x2b2ac + (0x3e<<2) = 0x2b3a4 (mov w5, #3: Opening punctuation '(', '[', '{')
                case 0x40u: return 5u; // 0x2b2ac + (0x40<<2) = 0x2b3ac (mov w5, #5: Closing punctuation ')', ']', '}', '!', ',', '.', '?')
                case 0x2Eu:
                default:    return 0u; // 0x2b2ac + (0x2e<<2) = 0x2b364 (mov w5, wzr: Ordinary Latin/Digit)
            }
        }
        const uint32_t gen_punct_idx = cp - 0x2013u;
        if (gen_punct_idx <= 0x13u) {
            const uint32_t bit = 1u << gen_punct_idx;
            if ((bit & 0x00080440u) != 0u) {
                return 5u; // U+2019 (’), U+201D (”), U+2026 (…)
            }
            if ((bit & 0x00000220u) != 0u) {
                return 3u; // U+2018 (‘), U+201C (“)
            }
            if (gen_punct_idx == 0u) {
                return 4u;
            }
        }
        return 0u;
    }

    // cp > 0x3000
    const uint32_t fw_idx = cp - 0xFF01u;
    if (fw_idx <= 0x1Eu) {
        const uint32_t bit = 1u << fw_idx;
        if ((bit & 0x46000901u) != 0u) {
            return 5u; // Fullwidth closing punctuation ('！', '，', '．', '：', '；', '？', '）')
        }
        if (fw_idx == 7u) {
            return 3u; // U+FF08 Fullwidth Left Parenthesis '（'
        }
    }
    const uint32_t cjk_punct_idx = cp - 0x3001u;
    if (cjk_punct_idx <= 0x10u) {
        const uint32_t bit = 1u << cjk_punct_idx;
        if ((bit & 0x00010403u) != 0u) {
            return 5u; // U+3001 '、', U+3002 '。', U+300B '》', U+3011 '】'
        }
        if ((bit & 0x00008200u) != 0u) {
            return 3u; // U+300A '《', U+3010 '【'
        }
    }
    if (cp == 0xFF5Eu) {
        return 5u; // Fullwidth Tilde '～'
    }
    return 0u;
}

BoundaryAnalyst::BoundaryAnalyst(const char32_t* u32_text, uint32_t char_count, LineBreakStrategy strategy) {
    if (!u32_text || char_count == 0u) {
        return;
    }
    boundary_types_.assign(char_count, BoundaryType::kNone);
    std::vector<uint32_t> classes(char_count, 0u);
    for (uint32_t i = 0u; i < char_count; ++i) {
        classes[i] = ClassifyCodepointForBreak(static_cast<uint32_t>(u32_text[i]));
    }

    const bool use_advanced = (static_cast<uint8_t>(strategy) & 1u) != 0u;
    for (uint32_t i = 0u; i < char_count; ++i) {
        const uint32_t cls = classes[i];
        if (cls == 0u) {
            if (i + 1u < char_count && classes[i + 1u] == 0u) {
                boundary_types_[i] = BoundaryType::kChar;
            } else {
                boundary_types_[i] = BoundaryType::kWord;
            }
        } else if (cls == 1u) {
            boundary_types_[i] = BoundaryType::kLineBreak;
            if (i > 0u && boundary_types_[i - 1u] == BoundaryType::kLineBreak && classes[i - 1u] != 1u) {
                boundary_types_[i - 1u] = BoundaryType::kWord;
            }
        } else if (cls == 2u) {
            boundary_types_[i] = BoundaryType::kLineBreak;
            if (i > 0u && classes[i - 1u] == 0u) {
                boundary_types_[i - 1u] = BoundaryType::kLineBreak;
            }
        } else if (cls == 4u) {
            boundary_types_[i] = BoundaryType::kMustBreak;
        } else if (cls == 5u && use_advanced && i > 0u && classes[i - 1u] != 1u) {
            boundary_types_[i - 1u] = BoundaryType::kWord;
            boundary_types_[i]      = BoundaryType::kLineBreak;
        } else {
            boundary_types_[i] = BoundaryType::kLineBreak;
        }
    }
}

// _ZNK8ttoffice6tttext15BoundaryAnalyst16FindNextBoundaryEjNS0_12BoundaryTypeE (0x02b5bc, 56 B)
uint32_t BoundaryAnalyst::FindNextBoundary(uint32_t start_pos, BoundaryType min_type) const noexcept {
    const uint32_t n = static_cast<uint32_t>(boundary_types_.size());
    for (uint32_t i = start_pos; i < n; ++i) {
        if (static_cast<uint8_t>(boundary_types_[i]) >= static_cast<uint8_t>(min_type)) {
            return i + 1u;
        }
    }
    return n;
}

// _ZNK8ttoffice6tttext15BoundaryAnalyst16FindPrevBoundaryEjNS0_12BoundaryTypeE (0x02b5f4, 40 B)
uint32_t BoundaryAnalyst::FindPrevBoundary(uint32_t start_pos, BoundaryType min_type) const noexcept {
    const uint32_t n = static_cast<uint32_t>(boundary_types_.size());
    uint32_t i = std::min(start_pos, n);
    while (i > 0u) {
        --i;
        if (static_cast<uint8_t>(boundary_types_[i]) >= static_cast<uint8_t>(min_type)) {
            return i;
        }
    }
    return 0u;
}

// _ZN8ttoffice6tttext15BoundaryAnalyst19UpgradeBoundaryTypeERKNS0_5RangeENS0_12BoundaryTypeE (0x02b61c, 76 B)
void BoundaryAnalyst::UpgradeBoundaryType(const Range& range, BoundaryType new_type) noexcept {
    const uint32_t n = static_cast<uint32_t>(boundary_types_.size());
    const uint32_t end_idx = std::min(range.end, n);
    for (uint32_t i = range.start; i < end_idx; ++i) {
        if (static_cast<uint8_t>(boundary_types_[i]) < static_cast<uint8_t>(new_type)) {
            boundary_types_[i] = new_type;
        }
    }
}

// ============================================================================
// 4. LayoutMeasurer Implementation (0x02ca84 .. 0x02cbf4)
// ============================================================================
// _ZN8ttoffice6tttext14LayoutMeasurer24CalcRunHeightByLinePitchERKNS0_7SpacingEff (0x02ca84, 156 B)
float LayoutMeasurer::CalcRunHeightByLinePitch(
    const Spacing& spacing,
    float run_height,
    float line_pitch) noexcept {
    const RulerType rule = spacing.line_height_rule;
    if (rule == RulerType::kExact) {
        return spacing.line_height_px;
    }
    if (rule == RulerType::kAtLeast) {
        const float mult = spacing.line_height_percent;
        if (line_pitch <= 0.0f) {
            return mult * run_height;
        }
        float h = std::round(mult * line_pitch);
        while (h < run_height) {
            h += line_pitch;
        }
        return h;
    }
    if (rule == RulerType::kNormal) {
        float h = run_height;
        if (line_pitch > 0.0f) {
            h = std::round(line_pitch);
            while (h < run_height) {
                h += line_pitch;
            }
        }
        return (h < spacing.line_height_px) ? spacing.line_height_px : h;
    }
    return run_height;
}

// _ZN8ttoffice6tttext14LayoutMeasurer19GetLineSpacingRatioE... (0x02cb20, 8 B)
float LayoutMeasurer::GetLineSpacingRatio(const std::string& /*locale*/) noexcept {
    return 1.0f;
}

// _ZN8ttoffice6tttext14LayoutMeasurer19GetLinePitchSpacingEfff (0x02cb28, 36 B)
float LayoutMeasurer::GetLinePitchSpacing(float run_height, float line_pitch, float ratio) noexcept {
    float h = std::round(line_pitch * ratio);
    while (h < run_height) {
        h += line_pitch;
    }
    return h;
}

// _ZN8ttoffice6tttext14LayoutMeasurer12CalcElementYENS0_26CharacterVerticalAlignmentEffff (0x02cb94, 100 B)
float LayoutMeasurer::CalcElementY(
    CharacterVerticalAlignment alignment,
    float line_ascent,
    float line_descent,
    float elem_ascent,
    float elem_descent) noexcept {
    const uint8_t a = static_cast<uint8_t>(alignment);
    if (a < 2u) {
        // kTop (0), kTextTop (1): -(line_ascent + elem_ascent)
        return -(line_ascent + elem_ascent);
    }
    if (static_cast<uint32_t>(a - 6u) < 2u) {
        // kSuperScript (6), kTextBottom (7): line_descent - elem_descent
        return line_descent - elem_descent;
    }
    if (a == 3u) {
        // kCenter (3): (line_descent + ((line_ascent + line_descent) - (elem_descent - elem_ascent)) * (-0.5f)) - elem_descent
        const float elem_span = elem_descent - elem_ascent;
        const float line_span = line_ascent + line_descent;
        const float centered = line_descent + (line_span - elem_span) * (-0.5f);
        return centered - elem_descent;
    }
    return 0.0f;
}

// ============================================================================
// 5. AttributesRangeList & StyleManager Implementation (0x032fa0 .. 0x03453b)
// ============================================================================
void AttributesRangeList::SetRangeValue(const Range& range, uint64_t value) {
    if (range.IsEmpty()) {
        return;
    }
    entries_.push_back(AttrRangeEntry{range, value});
}

uint64_t AttributesRangeList::GetAttrValue(uint32_t char_pos) const noexcept {
    for (auto it = entries_.rbegin(); it != entries_.rend(); ++it) {
        if (char_pos >= it->range.start && char_pos < it->range.end) {
            return it->value;
        }
    }
    return ~0ULL;
}

AttrRangeEntry AttributesRangeList::GetAttributeRange(uint32_t char_pos) const noexcept {
    for (auto it = entries_.rbegin(); it != entries_.rend(); ++it) {
        if (char_pos >= it->range.start && char_pos < it->range.end) {
            return *it;
        }
    }
    return AttrRangeEntry{Range{0u, 0xFFFFFFFFu}, ~0ULL};
}

// _ZN8ttoffice6tttext12StyleManager13GetStyleValueEPKNS0_5StyleENS0_13AttributeTypeE (0x033990, 156 B)
uint64_t StyleManager::GetStyleValue(const Style* style, AttributeType attr_type) noexcept {
    if (!style) {
        return ~0ULL;
    }
    const uint32_t idx = static_cast<uint32_t>(attr_type) - 6u;
    if (idx > 13u) {
        return ~0ULL;
    }
    switch (attr_type) {
        case AttributeType::kForegroundColor:
            return style->fg_color;
        case AttributeType::kBackgroundColor:
            return style->bg_color;
        case AttributeType::kDecorationColor:
            return style->decoration_color;
        case AttributeType::kDecorationType:
            return style->decoration_type;
        case AttributeType::kDecorationStyle:
            return style->decoration_style;
        case AttributeType::kDecorationThickness: {
            uint32_t bits = 0u;
            std::memcpy(&bits, &style->decoration_thickness_multiplier, sizeof(bits));
            return bits;
        }
        case AttributeType::kFontFeatureSettings:
            return style->font_feature_flags;
        case AttributeType::kBold:
            return style->bold;
        case AttributeType::kItalic:
            return style->italic;
        case AttributeType::kTextShadowList:
            return reinterpret_cast<uintptr_t>(&style->text_shadows);
        case AttributeType::kForegroundPainter:
            return style->foreground_painter;
        case AttributeType::kBackgroundPainter:
            return style->background_painter;
        case AttributeType::kWordBreak:
            return style->word_break;
        case AttributeType::kSubSupType:
            return style->sub_sup_type;
        default:
            return ~0ULL;
    }
}

// _ZNK8ttoffice6tttext12StyleManager8SetStyleEPNS0_5StyleEmNS0_13AttributeTypeE (0x033c74, 272 B)
void StyleManager::SetStyle(Style* style, uint64_t value, AttributeType attr_type) noexcept {
    if (!style) {
        return;
    }
    const uint32_t idx = static_cast<uint32_t>(attr_type) - 6u;
    if (idx > 13u) {
        return;
    }
    switch (attr_type) {
        case AttributeType::kForegroundColor:
            style->fg_color = static_cast<uint32_t>(value);
            break;
        case AttributeType::kBackgroundColor:
            style->bg_color = static_cast<uint32_t>(value);
            break;
        case AttributeType::kDecorationColor:
            style->decoration_color = static_cast<uint32_t>(value);
            break;
        case AttributeType::kDecorationType:
            style->decoration_type = static_cast<uint8_t>(value);
            break;
        case AttributeType::kDecorationStyle:
            style->decoration_style = static_cast<uint8_t>(value);
            break;
        case AttributeType::kDecorationThickness: {
            const uint32_t bits = static_cast<uint32_t>(value);
            std::memcpy(&style->decoration_thickness_multiplier, &bits, sizeof(bits));
            break;
        }
        case AttributeType::kFontFeatureSettings:
            style->font_feature_flags = value;
            break;
        case AttributeType::kBold:
            style->bold = static_cast<uint8_t>(value);
            break;
        case AttributeType::kItalic:
            style->italic = static_cast<uint8_t>(value);
            break;
        case AttributeType::kForegroundPainter:
            style->foreground_painter = value;
            break;
        case AttributeType::kBackgroundPainter:
            style->background_painter = value;
            break;
        case AttributeType::kWordBreak:
            style->word_break = static_cast<uint8_t>(value);
            break;
        case AttributeType::kSubSupType:
            style->sub_sup_type = static_cast<uint32_t>(value);
            break;
        default:
            break;
    }
}

void StyleManager::ApplyStyleInRange(const Style& style, uint32_t start_char, uint32_t char_len) {
    Range r{start_char, 0u};
    r.SetLength(char_len);
    for (uint32_t a = 6u; a <= 19u; ++a) {
        if (a == static_cast<uint32_t>(AttributeType::kTextShadowList)) {
            continue;
        }
        const AttributeType attr = static_cast<AttributeType>(a);
        attr_lists_[a].SetRangeValue(r, GetStyleValue(&style, attr));
    }
}

Style StyleManager::GetStyle(uint32_t char_pos) const {
    Style s{};
    for (uint32_t a = 6u; a <= 19u; ++a) {
        if (a == static_cast<uint32_t>(AttributeType::kTextShadowList)) {
            continue;
        }
        const uint64_t val = attr_lists_[a].GetAttrValue(char_pos);
        if (val != ~0ULL) {
            SetStyle(&s, val, static_cast<AttributeType>(a));
        }
    }
    return s;
}

void StyleManager::SetExtraFloatAttributesInRange(
    AttributeType attr_type,
    float value,
    uint32_t start_char,
    uint32_t char_len) {
    const uint32_t idx = static_cast<uint32_t>(attr_type);
    if (idx >= attr_lists_.size()) {
        return;
    }
    uint32_t bits = 0u;
    std::memcpy(&bits, &value, sizeof(bits));
    Range r{start_char, 0u};
    r.SetLength(char_len);
    attr_lists_[idx].SetRangeValue(r, bits);
}

float StyleManager::GetExtraFloatAttributes(
    AttributeType attr_type,
    uint32_t char_pos,
    float default_val) const noexcept {
    const uint32_t idx = static_cast<uint32_t>(attr_type);
    if (idx >= attr_lists_.size()) {
        return default_val;
    }
    const uint64_t raw = attr_lists_[idx].GetAttrValue(char_pos);
    if (raw == ~0ULL) {
        return default_val;
    }
    const uint32_t bits = static_cast<uint32_t>(raw);
    float out = default_val;
    std::memcpy(&out, &bits, sizeof(out));
    return out;
}

// ============================================================================
// 6. ShapeResult, BaseRun, ParagraphImpl & TTTextJNIProxy
// ============================================================================
void ShapeResult::AppendGlyph(uint16_t glyph_id, float advance_x, float x, float y, uint32_t cluster) {
    glyphs_.push_back(GlyphData{glyph_id, advance_x, x, y, cluster});
}

float ShapeResult::MeasureWidth(uint32_t start_char, uint32_t char_count, float letter_spacing) const noexcept {
    const uint32_t end_char = start_char + char_count;
    float total = 0.0f;
    for (const auto& g : glyphs_) {
        if (g.cluster >= start_char && g.cluster < end_char) {
            total += g.advance_x + letter_spacing;
        }
    }
    return total;
}

BaseRun::BaseRun(const std::u32string& text, const Style& style)
    : u32_text_(text), style_(style) {}

// _ZN8ttoffice6tttext7BaseRun14ControlRunListEv (0x0307f4, 12 B)
const ControlRunEntry* BaseRun::ControlRunList() noexcept {
    return kDataControlRunList;
}

// _ZN8ttoffice6tttext7BaseRun9SpaceListEv (0x030800, 12 B)
const char* const* BaseRun::SpaceList() noexcept {
    return kDataSpaceList;
}

float BaseRun::GetWidth(uint32_t start_char, uint32_t char_count) const noexcept {
    return shape_result_.MeasureWidth(start_char, char_count, style_.letter_spacing);
}

float BaseRun::MeasureRunByWidth(uint32_t& in_out_char_count, float max_width) const noexcept {
    const uint32_t limit = std::min<uint32_t>(in_out_char_count, static_cast<uint32_t>(u32_text_.size()));
    float acc_width = 0.0f;
    uint32_t fitted = 0u;
    for (uint32_t i = 0u; i < limit; ++i) {
        const float w = GetWidth(i, 1u);
        if (acc_width + w > max_width && fitted > 0u) {
            break;
        }
        acc_width += w;
        ++fitted;
    }
    in_out_char_count = fitted;
    return acc_width;
}

void BaseRun::Layout() {
    shape_result_ = ShapeResult{};
    const float char_advance = style_.text_size * style_.text_scale * 0.6f;
    float cur_x = 0.0f;
    for (uint32_t i = 0u; i < u32_text_.size(); ++i) {
        shape_result_.AppendGlyph(static_cast<uint16_t>(u32_text_[i] & 0xFFFFu), char_advance, cur_x, 0.0f, i);
        cur_x += char_advance + style_.letter_spacing;
    }
}

ParagraphImpl::ParagraphImpl() = default;

void ParagraphImpl::AddTextRun(const Style& style, const char* utf8_text, uint32_t byte_length, bool /*is_ghost*/) {
    if (!utf8_text || byte_length == 0u) {
        return;
    }
    const uint32_t start_char = content_.GetCharCount();
    content_.AppendString(std::string(utf8_text, byte_length));
    const uint32_t added_chars = content_.GetCharCount() - start_char;
    style_manager_.ApplyStyleInRange(style, start_char, added_chars);
    std::u32string u32 = base::U8StringToU32(utf8_text, byte_length);
    auto run = std::make_unique<BaseRun>(u32, style);
    run->Layout();
    max_intrinsic_width_ += run->GetWidth(0u, static_cast<uint32_t>(u32.size()));
    runs_.push_back(std::move(run));
}

void ParagraphImpl::ApplyStyleInRange(const Style& style, uint32_t start_char, uint32_t char_count) {
    style_manager_.ApplyStyleInRange(style, start_char, char_count);
}

float ParagraphImpl::GetMaxIntrinsicWidth() const noexcept {
    return max_intrinsic_width_;
}

Range ParagraphImpl::GetWordBoundary(uint32_t char_pos) const {
    const std::u32string u32 = content_.ToUTF32();
    BoundaryAnalyst analyst(u32.data(), static_cast<uint32_t>(u32.size()), paragraph_style_.line_break_strategy);
    const uint32_t prev = analyst.FindPrevBoundary(char_pos, BoundaryType::kWord);
    const uint32_t next = analyst.FindNextBoundary(char_pos, BoundaryType::kWord);
    return Range{prev, next};
}

void ParagraphImpl::FormatRunList() {
    max_intrinsic_width_ = 0.0f;
    for (auto& run : runs_) {
        run->Layout();
        max_intrinsic_width_ += run->GetWidth(0u, run->CharCount());
    }
}

TTTextJNIProxy& TTTextJNIProxy::GetInstance() {
    static TTTextJNIProxy s_proxy;
    return s_proxy;
}

// JNI_OnLoad (0x01a7a0 .. 0x01a823): returns JNI_VERSION_1_6 (0x00010006)
int32_t TTTextJNIProxy::OnLoad(uint64_t java_vm_handle) noexcept {
    if (java_vm_handle == 0ULL) {
        return -1;
    }
    cache_.java_vm = java_vm_handle;
    return 0x00010006; // JNI_VERSION_1_6 (mov w19, #6; movk w19, #1, lsl #16)
}

void TTTextJNIProxy::InitialCache() noexcept {
    cache_.java_shaper_class       = 0x00E403ULL;
    cache_.java_font_manager_class = 0x00E41EULL;
}

} // namespace tttext
} // namespace ttoffice
