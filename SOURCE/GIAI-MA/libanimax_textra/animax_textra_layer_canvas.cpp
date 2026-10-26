/**
 * @file animax_textra_layer_canvas.cpp
 * @brief Complete Implementation of TextLayerImplTextra, CanvasHelperTextra, ParagraphStyleTextra, TextHelperTextra & JNI_OnLoad (0x00a180 .. 0x00b8c3)
 *        Triển khai đầy đủ TextLayerImplTextra, CanvasHelperTextra, ParagraphStyleTextra, TextHelperTextra & JNI_OnLoad (0x00a180 .. 0x00b8c3)
 *
 * Binary Ground Truth / Bằng chứng nhị phân:
 * - 0x00a180 .. 0x00a1e7: TextLayerImplTextra::~TextLayerImplTextra (D1 & D0)
 * - 0x00a1e8 .. 0x00ab0c: TextLayerImplTextra::OnDraw(skity::Canvas*, float)
 * - 0x00ab10 .. 0x00ab5c: std::vector<std::string>::__push_back_slow_path
 * - 0x00ab64 .. 0x00abb7: CanvasHelperTextra::CanvasHelperTextra(skity::Canvas*, float) & D1 destructor
 * - 0x00abb8 .. 0x00acf3: CanvasHelperTextra simple virtual overrides (Save, Restore, Translate, Scale, Rotate, Skew, ClipRect, DrawColor, DrawLine, DrawRect)
 * - 0x00acf4 .. 0x00b174: CanvasHelperTextra::DrawGlyphs(ITypefaceHelper const*, uint32_t, uint16_t const*, char const*, uint32_t, float, float, float const*, float const*, IPaintHelper*)
 * - 0x00b178 .. 0x00b314: CanvasHelperTextra D0 destructor & no-op virtual overrides
 * - 0x00b318 .. 0x00b458: std::vector<skity::TextRun>::__emplace_back_slow_path (sizeof(skity::TextRun) == 0x68 = 104 bytes)
 * - 0x00b45c .. 0x00b52c: ParagraphStyleTextra::GetDefaultFontManager() & GetDefaultStyle()
 * - 0x00b538 .. 0x00b598: TextHelperTextra::CreateTextLayer(TextLayer*)
 * - 0x00b59c .. 0x00b600: TextHelperTextra::CreateFontAsset(FontAsset*)
 * - 0x00b604 .. 0x00b7b8: TextHelperTextra::CheckIfTextSupported(FontAsset*, std::string const&)
 * - 0x00b7cc .. 0x00b8c3: JNI_OnLoad (Exported symbol [101], returns 0x00010006)
 */

#include "animax_textra_layer_canvas.h"

#include <algorithm>
#include <cmath>
#include <cstring>

// ============================================================================
// 1. TTText LayoutDrawer & UTF-8 Decoding Support
//    Triển khai hỗ trợ LayoutDrawer và giải mã UTF-8
// ============================================================================

namespace ttoffice {
namespace tttext {

void LayoutDrawer::DrawLayoutPage(LayoutRegion* region) {
    if (canvas_helper_ == nullptr || region == nullptr || region->GetParagraph() == nullptr) {
        return;
    }

    const Paragraph* paragraph = region->GetParagraph();
    FontmgrCollection* font_collection = region->GetFontCollection();
    std::shared_ptr<IFontManager> font_mgr =
        (font_collection != nullptr) ? font_collection->GetDefaultFontManager() : nullptr;

    float cursor_x = 0.0f;
    for (const auto& run : paragraph->GetRuns()) {
        if (run.text.empty()) {
            continue;
        }

        const auto& desc = run.style.GetFontDescriptor();
        const char* family_name =
            desc.font_family_list_.empty() ? "sans-serif" : desc.font_family_list_.front().c_str();
        std::shared_ptr<ITypefaceHelper> typeface =
            (font_mgr != nullptr)
                ? font_mgr->onMatchFamilyStyle(family_name, desc.font_style_)
                : nullptr;
        if (typeface == nullptr) {
            auto fallback_mgr = lynx::animax::ParagraphStyleTextra::GetDefaultFontManager();
            typeface = fallback_mgr->onMatchFamilyStyle(family_name, desc.font_style_);
        }

        const std::u32string utf32 = lynx::base::UTF8ToUTF32(run.text);
        if (utf32.empty()) {
            continue;
        }

        const uint32_t glyph_count = static_cast<uint32_t>(utf32.size());
        std::vector<uint16_t> glyphs(glyph_count, 0);
        std::vector<float> x_positions(glyph_count, 0.0f);
        std::vector<float> y_positions(glyph_count, run.style.GetBaselineOffset());

        const float font_size = run.style.GetTextSize();
        const float word_spacing = run.style.GetWordSpacing();
        for (uint32_t i = 0; i < glyph_count; ++i) {
            glyphs[i] = (typeface != nullptr) ? typeface->UnicharToGlyph(static_cast<uint32_t>(utf32[i])) : 1U;
            x_positions[i] = cursor_x;
            const float adv = (typeface != nullptr) ? typeface->GetHorizontalAdvance(glyphs[i], font_size) : (font_size * 0.6f);
            cursor_x += adv + word_spacing;
        }

        IPaintHelper paint_helper{};
        paint_helper.text_size_  = font_size;
        paint_helper.bold_       = run.style.IsBold() ? 1U : 0U;
        paint_helper.italic_     = run.style.IsItalic() ? 1U : 0U;
        paint_helper.blur_radius_ = run.style.GetBlurRadius();

        if (run.style.HasStrokeColor() && run.style.GetStrokeWidth() > 0.0f) {
            paint_helper.draw_style_   = 1U; // Stroke
            paint_helper.stroke_width_ = run.style.GetStrokeWidth();
            paint_helper.color_        = run.style.GetStrokeColor();
            canvas_helper_->DrawGlyphs(
                typeface.get(), glyph_count, glyphs.data(),
                run.text.data(), static_cast<uint32_t>(run.text.size()),
                0.0f, 0.0f, x_positions.data(), y_positions.data(), &paint_helper);
        }

        if (run.style.HasForegroundColor() || !run.style.HasStrokeColor()) {
            paint_helper.draw_style_   = 0U; // Fill
            paint_helper.stroke_width_ = 0.0f;
            paint_helper.color_        = run.style.GetForegroundColor();
            canvas_helper_->DrawGlyphs(
                typeface.get(), glyph_count, glyphs.data(),
                run.text.data(), static_cast<uint32_t>(run.text.size()),
                0.0f, 0.0f, x_positions.data(), y_positions.data(), &paint_helper);
        }
    }
}

}  // namespace tttext
}  // namespace ttoffice

namespace lynx {
namespace base {

std::u32string UTF8ToUTF32(const std::string& utf8_str) {
    std::u32string out;
    out.reserve(utf8_str.size());
    const uint8_t* bytes = reinterpret_cast<const uint8_t*>(utf8_str.data());
    const size_t len = utf8_str.size();
    size_t i = 0;

    while (i < len) {
        const uint8_t b0 = bytes[i];
        if ((b0 & 0x80U) == 0U) {
            out.push_back(static_cast<char32_t>(b0));
            i += 1;
        } else if ((b0 & 0xE0U) == 0xC0U && (i + 1 < len)) {
            const char32_t cp =
                (static_cast<char32_t>(b0 & 0x1FU) << 6) |
                static_cast<char32_t>(bytes[i + 1] & 0x3FU);
            out.push_back(cp);
            i += 2;
        } else if ((b0 & 0xF0U) == 0xE0U && (i + 2 < len)) {
            const char32_t cp =
                (static_cast<char32_t>(b0 & 0x0FU) << 12) |
                (static_cast<char32_t>(bytes[i + 1] & 0x3FU) << 6) |
                static_cast<char32_t>(bytes[i + 2] & 0x3FU);
            out.push_back(cp);
            i += 3;
        } else if ((b0 & 0xF8U) == 0xF0U && (i + 3 < len)) {
            const char32_t cp =
                (static_cast<char32_t>(b0 & 0x07U) << 18) |
                (static_cast<char32_t>(bytes[i + 1] & 0x3FU) << 12) |
                (static_cast<char32_t>(bytes[i + 2] & 0x3FU) << 6) |
                static_cast<char32_t>(bytes[i + 3] & 0x3FU);
            out.push_back(cp);
            i += 4;
        } else {
            out.push_back(static_cast<char32_t>(0xFFFDU));
            i += 1;
        }
    }
    return out;
}

}  // namespace base

namespace animax {

// ============================================================================
// 2. TextLayerImplTextra Implementation (0x00a180 .. 0x00ab0c)
//    Triển khai TextLayerImplTextra (0x00a180 .. 0x00ab0c)
// ============================================================================

/**
 * @brief Constructed inside `TextHelperTextra::CreateTextLayer` (`0x00b538 .. 0x00b598`):
 *        Initializes `default_family_name_` (`+0x10`) to `"pingfang"` (`0x003539`, 8 chars, SSO tag `0x10` @ `0x00b550`).
 */
TextLayerImplTextra::TextLayerImplTextra(TextLayer* text_layer)
    : TextLayerImpl(text_layer),
      default_family_name_(rodata::kStrPingFang) {}

/**
 * @brief `TextLayerImplTextra::~TextLayerImplTextra` (`0x00a180` D1 / `0x00a1d0` D0):
 *        Releases `default_family_name_` if heap-allocated (`tbz w8, #0, 0x00a1b8`) and calls `TextLayerImpl::~TextLayerImpl()`.
 */
TextLayerImplTextra::~TextLayerImplTextra() = default;

/**
 * @brief Exact bit-packed alignment lookup (`0x00a52c .. 0x00a54c`):
 *        Disassembly:
 *        ```asm
 *        0x00a52c: ldr w8, [x22, #0x34]
 *        0x00a530: sub w8, w8, #1
 *        0x00a534: mov x9, #0x102
 *        0x00a538: movk x9, #0x303, lsl #16
 *        0x00a53c: movk x9, #0x303, lsl #32
 *        0x00a540: cmp w8, #6
 *        0x00a544: lsl w8, w8, #3
 *        0x00a548: lsr x8, x9, x8
 *        0x00a54c: csel w26, wzr, w8, hs
 *        ```
 *        - `justify == 0` -> `idx = 0xFFFFFFFF >= 6` -> `0` (`kLeft`)
 *        - `justify == 1` -> `idx = 0` -> `(0x0000030303030102 >> 0) & 0xFF = 2` (`kCenter`)
 *        - `justify == 2` -> `idx = 1` -> `(0x0000030303030102 >> 8) & 0xFF = 1` (`kRight`)
 *        - `justify in [3..6]` -> `idx in [2..5]` -> `3` (`kJustify`)
 */
ttoffice::tttext::ParagraphHorizontalAlignment TextLayerImplTextra::MapJustifyToAlignment(uint32_t justify) noexcept {
    const uint32_t idx = justify - 1U;
    if (idx >= 6U) {
        return ttoffice::tttext::ParagraphHorizontalAlignment::kLeft;
    }
    const uint32_t shift = idx << 3U;
    const uint8_t mapped = static_cast<uint8_t>((rodata::kParagraphAlignBitLut >> shift) & 0xFFULL);
    return static_cast<ttoffice::tttext::ParagraphHorizontalAlignment>(mapped);
}

/**
 * @brief Exact tracking formula (`0x00a594 .. 0x00a5a8`):
 *        ```asm
 *        0x00a594: ldr s0, [x22, #0x38]
 *        0x00a598: mov w8, #0x42c80000   // 100.0f
 *        0x00a59c: scvtf s0, s0
 *        0x00a5a0: fmul s0, s0, s9       // tracking * text_size
 *        0x00a5a4: fmov s1, w8
 *        0x00a5a8: fdiv s10, s0, s1      // (tracking * text_size) / 100.0f
 *        ```
 */
float TextLayerImplTextra::ComputeTrackingPixels(float text_size, int32_t tracking) noexcept {
    return (static_cast<float>(tracking) * text_size) / rodata::kTrackingDivisor100;
}

/**
 * @brief Exact unconstrained horizontal offset (`0x00aa44 .. 0x00aa6c`):
 *        - `kLeft (0)`: `0.0f` (`fmov s0, wzr` @ `0x00aa68`)
 *        - `kRight (1)`: `-1000000.0f` (`ldr s0, [x8, #0x51c]` @ `0x00aa60`)
 *        - `kCenter (2)`: `-500000.0f` (`ldr s0, [x8, #0x518]` @ `0x00aa54`)
 */
float TextLayerImplTextra::ComputeUnconstrainedHorizontalOffset(
    ttoffice::tttext::ParagraphHorizontalAlignment align) noexcept {
    switch (align) {
        case ttoffice::tttext::ParagraphHorizontalAlignment::kCenter:
            return rodata::kLayoutOffsetNegHalfMillion; // -500000.0f (0x003518)
        case ttoffice::tttext::ParagraphHorizontalAlignment::kRight:
            return rodata::kLayoutOffsetNegOneMillion;  // -1000000.0f (0x00351c)
        case ttoffice::tttext::ParagraphHorizontalAlignment::kLeft:
        case ttoffice::tttext::ParagraphHorizontalAlignment::kJustify:
        default:
            return 0.0f;
    }
}

/**
 * @brief Helper computing byte offset of the N-th UTF-8 codepoint (`0x00a800 .. 0x00a864`).
 *        Disassembly: `(byte & 0xC0) != 0x80` (`and w16, w16, #0xc0; cmp w16, #0x80; cinc x14, x14, ne`).
 *        Hàm phụ tính vị trí byte của ký tự UTF-8 thứ N khớp đoạn lệnh `0x00a800 .. 0x00a864`.
 */
static size_t FindUtf8CodepointByteOffset(const std::string& utf8, uint32_t target_cp_index) noexcept {
    if (target_cp_index == 0) {
        return 0;
    }
    uint32_t cp_count = 0;
    for (size_t i = 0; i < utf8.size(); ++i) {
        const uint8_t b = static_cast<uint8_t>(utf8[i]);
        if ((b & 0xC0U) != 0x80U) {
            if (cp_count == target_cp_index) {
                return i;
            }
            ++cp_count;
        }
    }
    return utf8.size();
}

static uint32_t CountUtf8Codepoints(const std::string& utf8) noexcept {
    uint32_t cp_count = 0;
    for (char c : utf8) {
        if ((static_cast<uint8_t>(c) & 0xC0U) != 0x80U) {
            ++cp_count;
        }
    }
    return cp_count;
}

/**
 * @brief `TextLayerImplTextra::OnDraw(skity::Canvas* canvas, float alpha)` (`0x00a1e8 .. 0x00ab0c`).
 *        Tái dựng toàn bộ đường ống dàn trang và kết xuất văn bản `TextLayerImplTextra::OnDraw`.
 */
void TextLayerImplTextra::OnDraw(skity::Canvas* canvas, float alpha) {
    if (canvas == nullptr || text_layer_ == nullptr) {
        return;
    }

    FontAssetImpl* font_asset_impl = text_layer_->GetFontAssetImpl();
    if (font_asset_impl == nullptr) {
        return;
    }

    const DocumentData& doc = text_layer_->GetDocumentData();
    const std::string& text = doc.text;
    const uint32_t total_codepoints = CountUtf8Codepoints(text);

    // 1. Evaluate RangeSelector & TextAnimator overrides (0x00a280 .. 0x00a524)
    //    Đánh giá vùng chọn RangeSelector và các thuộc tính hoạt họa TextAnimator
    const float current_frame =
        (text_layer_->GetComposition() != nullptr) ? text_layer_->GetComposition()->GetCurrentFrame() : 0.0f;

    uint32_t range_start = 0;
    uint32_t range_end   = 0;
    const RangeSelector& selector = text_layer_->GetRangeSelector();
    if (selector.enabled) {
        const skity::Vec2 r = selector.GetRange(current_frame, total_codepoints);
        range_start = static_cast<uint32_t>(std::max(0.0f, r.x));
        range_end   = static_cast<uint32_t>(std::max(0.0f, r.y));
    }

    bool     has_anim_fill_color   = false;
    uint32_t anim_fill_color       = 0;
    bool     has_anim_stroke_color = false;
    uint32_t anim_stroke_color     = 0;
    bool     has_anim_stroke_width = false;
    float    anim_stroke_width     = 0.0f;
    bool     has_anim_tracking     = false;
    float    anim_tracking         = 0.0f;
    bool     has_anim_blur         = false;
    float    anim_blur_radius      = 0.0f;
    bool     anim_bold             = false;
    bool     anim_italic           = false;

    for (const auto& animator : text_layer_->GetAnimators()) {
        if (animator.has_fill_color) {
            has_anim_fill_color = true;
            anim_fill_color = animator.fill_color;
        }
        if (animator.has_stroke_color) {
            has_anim_stroke_color = true;
            anim_stroke_color = animator.stroke_color;
        }
        if (animator.has_stroke_width) {
            has_anim_stroke_width = true;
            anim_stroke_width = animator.stroke_width;
        }
        if (animator.has_tracking) {
            has_anim_tracking = true;
            anim_tracking = animator.tracking;
        }
        if (animator.has_blur) {
            const float max_blur = std::max(animator.blur_radius.x, animator.blur_radius.y);
            if (max_blur > 0.0f) {
                has_anim_blur = true;
                anim_blur_radius = max_blur;
            }
        }
        if ((animator.font_style_flags & 1) != 0) {
            anim_bold = true;
        }
        if ((animator.font_style_flags & 2) != 0) {
            anim_italic = true;
        }
    }

    // 2. Map alignment & compute base style metrics (0x00a52c .. 0x00a658)
    //    Ánh xạ căn lề ngang và tính toán thông số định dạng cơ sở
    const auto horiz_align = MapJustifyToAlignment(doc.justify);
    const float tracking_px = ComputeTrackingPixels(doc.size, doc.tracking);

    ttoffice::tttext::FontDescriptor font_desc{};
    font_desc.font_style_ = ttoffice::tttext::FontStyle(400, 5, 0); // 0x00a5c4: mov w8, #0x190; movk w8, #5, lsl #16
    font_desc.platform_font_ = 0;

    const std::string& asset_family = font_asset_impl->GetFontFamilyName();
    if (!asset_family.empty()) {
        font_desc.font_family_list_.push_back(asset_family);
    }
    if (!doc.font_name.empty()) {
        font_desc.font_family_list_.push_back(doc.font_name);
    }
    font_desc.font_family_list_.push_back(default_family_name_);        // "pingfang"
    font_desc.font_family_list_.push_back(rodata::kStrSansSerif);       // "sans-serif"

    ttoffice::tttext::Style base_style = ParagraphStyleTextra::GetDefaultStyle();
    base_style.SetFontDescriptor(font_desc);
    base_style.SetTextSize(doc.size);
    base_style.SetLineHeightInPx(doc.line_height);
    base_style.SetLineHeightOverride(ttoffice::tttext::RulerType::kExact); // 0x00a640: mov w1, #1
    base_style.SetWordSpacing(tracking_px);
    base_style.SetBaselineOffset(-doc.baseline_shift); // 0x00a650: fneg s0, s11

    if (doc.stroke_width > 0.0f) {
        base_style.SetStrokeWidth(doc.stroke_width);
        if (doc.stroke_over_fill) {
            base_style.SetStrokeColor(ttoffice::tttext::TTColor(doc.stroke_color));
        } else {
            base_style.SetForegroundColor(ttoffice::tttext::TTColor(doc.fill_color));
            base_style.SetStrokeColor(ttoffice::tttext::TTColor(doc.stroke_color));
        }
    } else {
        base_style.SetForegroundColor(ttoffice::tttext::TTColor(doc.fill_color));
    }

    // 3. Configure Paragraph & ParagraphStyle (0x00a65c .. 0x00a928)
    //    Cấu hình Paragraph và ParagraphStyle
    auto paragraph = ttoffice::tttext::Paragraph::Create();
    ttoffice::tttext::ParagraphStyle para_style{};
    para_style.SetDefaultStyle(base_style);
    para_style.SetHorizontalAlign(horiz_align);
    para_style.AllowBreakAroundPunctuation(true); // 0x00a678: mov w1, #1
    paragraph->SetParagraphStyle(&para_style);

    if (range_end > range_start && range_start < total_codepoints) {
        const size_t start_byte = FindUtf8CodepointByteOffset(text, range_start);
        const size_t end_byte   = FindUtf8CodepointByteOffset(text, range_end);

        ttoffice::tttext::Style animated_style = base_style;
        if (has_anim_fill_color) {
            animated_style.SetForegroundColor(ttoffice::tttext::TTColor(anim_fill_color));
        }
        if (has_anim_stroke_color) {
            animated_style.SetStrokeColor(ttoffice::tttext::TTColor(anim_stroke_color));
        }
        if (has_anim_stroke_width) {
            animated_style.SetStrokeWidth(anim_stroke_width);
        }
        if (has_anim_tracking) {
            animated_style.SetWordSpacing(tracking_px + anim_tracking);
        }
        if (anim_bold) {
            animated_style.SetBold(true);
        }
        if (anim_italic) {
            animated_style.SetItalic(true);
        }
        if (has_anim_blur) {
            animated_style.SetBlurRadius(anim_blur_radius);
        }

        if (start_byte > 0) {
            paragraph->AddTextRun(&base_style, text.data(), static_cast<uint32_t>(start_byte));
        }
        if (end_byte > start_byte) {
            paragraph->AddTextRun(
                &animated_style,
                text.data() + start_byte,
                static_cast<uint32_t>(end_byte - start_byte));
        }
        if (end_byte < text.size()) {
            paragraph->AddTextRun(
                &base_style,
                text.data() + end_byte,
                static_cast<uint32_t>(text.size() - end_byte));
        }
    } else {
        paragraph->AddTextRun(&base_style, text.c_str());
    }

    // 4. Layout Region & TextLayout::LayoutEx (0x00a938 .. 0x00a9f4)
    //    Khởi tạo LayoutRegion (40 byte) và chạy TextLayout::LayoutEx
    ttoffice::tttext::FontmgrCollection* font_collection = font_asset_impl->GetFontmgrCollection();
    ttoffice::tttext::TextLayout text_layout(font_collection);
    ttoffice::tttext::TTTextContext layout_context{};
    layout_context.SetSkipSpacingBeforeFirstLine(true); // 0x00a958: mov w1, #1

    const bool has_constrained_box = (doc.box_size.x > 0.0f && doc.box_size.y > 0.0f);
    std::unique_ptr<ttoffice::tttext::LayoutRegion> region;
    if (has_constrained_box) {
        // 0x00a988..0x00a994: LayoutMode::kAtMost (1)
        region = std::make_unique<ttoffice::tttext::LayoutRegion>(
            doc.box_size.x,
            doc.box_size.y,
            ttoffice::tttext::LayoutMode::kAtMost,
            ttoffice::tttext::LayoutMode::kAtMost);
    } else {
        // 0x00a9a8..0x00a9bc: 1000000.0f (0x003520), LayoutMode::kIndefinite (2)
        region = std::make_unique<ttoffice::tttext::LayoutRegion>(
            rodata::kLayoutUnconstrainedMaxDimension,
            rodata::kLayoutUnconstrainedMaxDimension,
            ttoffice::tttext::LayoutMode::kIndefinite,
            ttoffice::tttext::LayoutMode::kIndefinite);
    }

    text_layout.LayoutEx(paragraph.get(), region.get(), layout_context);

    // 5. Compute first line ascent & canvas translation (0x00a9f8 .. 0x00aab8)
    //    Tính độ cao dòng đầu tiên và dịch chuyển hệ tọa độ Canvas
    float first_line_ascent = 0.0f;
    if (region->GetLineCount() > 0 && region->GetLine(0) != nullptr) {
        first_line_ascent = region->GetLine(0)->GetLineAscent();
    }

    canvas->Save();
    if (has_constrained_box) {
        // 0x00aa24..0x00aa3c: Translate(box_position.x, box_position.y - first_line_ascent)
        canvas->Translate(doc.box_position.x, doc.box_position.y - first_line_ascent);
    } else {
        // 0x00aa44..0x00aa78: Translate(offset_x, -first_line_ascent)
        const float offset_x = ComputeUnconstrainedHorizontalOffset(horiz_align);
        canvas->Translate(offset_x, -first_line_ascent);
    }

    CanvasHelperTextra canvas_helper(canvas, alpha);
    ttoffice::tttext::LayoutDrawer drawer(&canvas_helper);
    drawer.DrawLayoutPage(region.get());
    canvas->Restore();
}

// ============================================================================
// 3. CanvasHelperTextra Implementation (0x00ab64 .. 0x00b458)
//    Triển khai CanvasHelperTextra (0x00ab64 .. 0x00b458)
// ============================================================================

/**
 * @brief `CanvasHelperTextra::CanvasHelperTextra(skity::Canvas*, float)` (`0x00ab64 .. 0x00abac`):
 *        Disassembly trace:
 *        - `0x00ab78: bl ttoffice::tttext::ICanvasHelper::ICanvasHelper()`
 *        - `0x00ab88..0x00ab90: str x20, [x19, #8]; add x20, x19, #0x10; bl skity::Paint::Paint()`
 *        - `0x00ab9c: mov w1, #1; bl skity::Paint::SetAntiAlias(bool)`
 *        - `0x00aba4: str s8, [x19, #0xb8]` (`this->alpha_ = alpha`)
 */
CanvasHelperTextra::CanvasHelperTextra(skity::Canvas* canvas, float alpha)
    : ttoffice::tttext::ICanvasHelper(),
      canvas_(canvas),
      paint_(),
      alpha_(alpha) {
    paint_.SetAntiAlias(true);
}

/**
 * @brief `CanvasHelperTextra::~CanvasHelperTextra` (`0x00abb0` D1 / `0x00b178` D0):
 *        Destroys `paint_` (`+0x10`) and calls `ICanvasHelper::~ICanvasHelper()`.
 */
CanvasHelperTextra::~CanvasHelperTextra() = default;

std::unique_ptr<ttoffice::tttext::IPaintHelper> CanvasHelperTextra::CreatePaint() {
    return nullptr; // 0x00abb8: str xzr, [x8]; ret
}

void* CanvasHelperTextra::GetCanvas() {
    return nullptr; // 0x00abc4: mov x0, xzr; ret
}

void CanvasHelperTextra::Save() {
    if (canvas_ != nullptr) {
        canvas_->Save(); // 0x00abcc: ldr x0, [x0, #8]; b skity::Canvas::Save()
    }
}

void CanvasHelperTextra::Restore() {
    if (canvas_ != nullptr) {
        canvas_->Restore(); // 0x00abd4: ldr x0, [x0, #8]; b skity::Canvas::Restore()
    }
}

void CanvasHelperTextra::Translate(float dx, float dy) {
    if (canvas_ != nullptr) {
        canvas_->Translate(dx, dy); // 0x00abdc
    }
}

void CanvasHelperTextra::Scale(float sx, float sy) {
    if (canvas_ != nullptr) {
        canvas_->Scale(sx, sy); // 0x00abe4
    }
}

void CanvasHelperTextra::Rotate(float degrees) {
    if (canvas_ != nullptr) {
        canvas_->Rotate(degrees); // 0x00abec
    }
}

void CanvasHelperTextra::Skew(float sx, float sy) {
    if (canvas_ != nullptr) {
        canvas_->Skew(sx, sy); // 0x00abf4
    }
}

void CanvasHelperTextra::ClipRect(float left, float top, float right, float bottom, bool do_anti_alias) {
    (void)do_anti_alias;
    if (canvas_ != nullptr) {
        const skity::Rect rect{left, top, right, bottom};
        canvas_->ClipRect(rect); // 0x00abfc .. 0x00ac28
    }
}

void CanvasHelperTextra::Clear() {
    // 0x00ac2c: ret
}

void CanvasHelperTextra::ClearRect(float left, float top, float right, float bottom) {
    (void)left; (void)top; (void)right; (void)bottom;
    // 0x00ac30: ret
}

void CanvasHelperTextra::FillRect(float left, float top, float right, float bottom, uint32_t color) {
    (void)left; (void)top; (void)right; (void)bottom; (void)color;
    // 0x00ac34: ret
}

void CanvasHelperTextra::DrawColor(uint32_t color) {
    if (canvas_ != nullptr) {
        const uint8_t a = static_cast<uint8_t>((color >> 24) & 0xFFU);
        const uint8_t r = static_cast<uint8_t>((color >> 16) & 0xFFU);
        const uint8_t g = static_cast<uint8_t>((color >> 8) & 0xFFU);
        const uint8_t b = static_cast<uint8_t>(color & 0xFFU);
        canvas_->DrawColor(skity::Paint::ColorMakeARGB(a, r, g, b)); // 0x00ac38 .. 0x00ac50
    }
}

void CanvasHelperTextra::DrawLine(
    float x0, float y0, float x1, float y1, ttoffice::tttext::IPaintHelper* paint) {
    if (canvas_ == nullptr || paint == nullptr) {
        return;
    }
    // 0x00ac54 .. 0x00ac90: Sets stroke width (`paint->stroke_width_` @ +0x0c) and color (`paint->color_` @ +0x10)
    paint_.SetStrokeWidth(paint->stroke_width_);
    const uint32_t argb =
        ((paint->color_.flags_ & 1U) != 0U) ? paint->color_.GetPlainColor() : paint->color_.argb_;
    paint_.SetColor(argb);
    canvas_->DrawLine(x0, y0, x1, y1, paint_);
}

void CanvasHelperTextra::DrawRect(
    float left, float top, float right, float bottom, ttoffice::tttext::IPaintHelper* paint) {
    if (canvas_ == nullptr || paint == nullptr) {
        return;
    }
    // 0x00ac94 .. 0x00acf0
    paint_.SetStrokeWidth(paint->stroke_width_);
    const uint32_t argb =
        ((paint->color_.flags_ & 1U) != 0U) ? paint->color_.GetPlainColor() : paint->color_.argb_;
    paint_.SetColor(argb);
    const skity::Rect rect{left, top, right, bottom};
    canvas_->DrawRect(rect, paint_);
}

void CanvasHelperTextra::DrawOval(
    float left, float top, float right, float bottom, ttoffice::tttext::IPaintHelper* paint) {
    (void)left; (void)top; (void)right; (void)bottom; (void)paint;
}

void CanvasHelperTextra::DrawCircle(
    float x, float y, float radius, ttoffice::tttext::IPaintHelper* paint) {
    (void)x; (void)y; (void)radius; (void)paint;
}

void CanvasHelperTextra::DrawArc(
    float left, float top, float right, float bottom,
    float start_angle, float sweep_angle, bool use_center,
    ttoffice::tttext::IPaintHelper* paint) {
    (void)left; (void)top; (void)right; (void)bottom;
    (void)start_angle; (void)sweep_angle; (void)use_center; (void)paint;
}

void CanvasHelperTextra::DrawPath(void* path, ttoffice::tttext::IPaintHelper* paint) {
    (void)path; (void)paint;
}

void CanvasHelperTextra::DrawArcTo(
    float x1, float y1, float x2, float y2, float radius,
    ttoffice::tttext::IPaintHelper* paint) {
    (void)x1; (void)y1; (void)x2; (void)y2; (void)radius; (void)paint;
}

void CanvasHelperTextra::DrawText(
    const ttoffice::tttext::ITypefaceHelper* typeface, const char* text, uint32_t text_bytes,
    float x, float y, ttoffice::tttext::IPaintHelper* paint) {
    (void)typeface; (void)text; (void)text_bytes; (void)x; (void)y; (void)paint;
}

/**
 * @brief `CanvasHelperTextra::DrawGlyphs` (`0x00acf4 .. 0x00b174`):
 *        Disassembly trace:
 *        1. `0x00ad24: cbz w2, 0x00b134` -> Early return if `glyph_count == 0`.
 *        2. `0x00ad34: bl skity::Paint::Reset()` on `this->paint_` (`+0x10`).
 *        3. `0x00ad48..0x00ad5c`: If `typeface == nullptr`, calls `ParagraphStyleTextra::GetDefaultFontManager()`
 *           and `onMatchFamilyStyle(nullptr, FontStyle(400, 5, 0))` to obtain fallback `TypefaceTextra`.
 *        4. `0x00ad70..0x00ad9c`: Reads `paint->draw_style_` (`ldrb w8, [x22, #8]`):
 *           - `0` -> `Paint::kFill_Style (0)`
 *           - `1` -> `Paint::kStroke_Style (1)`
 *           - `2` -> `Paint::kStrokeAndFill_Style (2)`
 *        5. `0x00ada0..0x00adf8`: Sets `StrokeWidth(paint->stroke_width_)`, `SetTextSize(paint->text_size_)`,
 *           and if `paint->bold_ != 0 && sk_typeface->GetFontStyle().weight <= 400`, adds `paint->text_size_ * 0.0f` stroke adjustment.
 *        6. `0x00ae00..0x00ae60`: Converts `paint->color_` via `skity::Paint::Color4fFromColor`, sets `SetFillColor` & `SetStrokeColor`,
 *           and multiplies `paint_.GetAlphaF() * this->alpha_` (`fmul s0, s0, s1` @ `0x00ae54`).
 *        7. `0x00ae68..0x00af44`: Allocates `glyph_count` `skity::GlyphData` (`0x50` bytes each) and `skity::Vec2` positions (`8` bytes each),
 *           storing `{x_positions[i], -y_positions[i]}` (`fneg s10, s0` @ `0x00aeb0`).
 *        8. `0x00af58..0x00af98`: Constructs `skity::Font(sk_typeface)` with `size = paint->text_size_`;
 *           if `paint->italic_ != 0 && sk_typeface->GetFontStyle().slant == 0`, sets `skew_x = -0.25f` (`fmov s0, #-0.25000000` @ `0x00af84`).
 *        9. `0x00afac..0x00b0c8`: Builds `std::vector<skity::TextRun>` (`sizeof(TextRun) == 0x68 = 104 bytes`),
 *           wraps in `skity::TextBlob`, applies `skity::MaskFilter::MakeBlur(BlurStyle::kNormal = 1, blur_radius)` if `blur_radius > 0.0f` (`0x00b0a8`),
 *           and calls `canvas_->DrawTextBlob(&blob, origin_x, origin_y, paint_)` (`0x00b0c8`).
 */
void CanvasHelperTextra::DrawGlyphs(
    const ttoffice::tttext::ITypefaceHelper* typeface, uint32_t glyph_count,
    const uint16_t* glyphs, const char* text, uint32_t text_len,
    float origin_x, float origin_y, const float* x_positions, const float* y_positions,
    ttoffice::tttext::IPaintHelper* paint) {
    (void)text;
    (void)text_len;
    if (canvas_ == nullptr || paint == nullptr || glyph_count == 0 || glyphs == nullptr) {
        return;
    }

    paint_.Reset();

    std::shared_ptr<ttoffice::tttext::ITypefaceHelper> fallback_holder;
    const ttoffice::tttext::ITypefaceHelper* resolved_tf = typeface;
    if (resolved_tf == nullptr) {
        auto default_mgr = ParagraphStyleTextra::GetDefaultFontManager();
        fallback_holder = default_mgr->onMatchFamilyStyle(nullptr, ttoffice::tttext::FontStyle(400, 5, 0));
        resolved_tf = fallback_holder.get();
    }

    const auto* textra_tf = static_cast<const TypefaceTextra*>(resolved_tf);
    std::shared_ptr<skity::Typeface> sk_typeface =
        (textra_tf != nullptr) ? textra_tf->GetSkityTypeface() : nullptr;

    // Map draw style (0x00ad70 .. 0x00ad9c)
    if (paint->draw_style_ == 2U) {
        paint_.SetStyle(skity::Paint::kStrokeAndFill_Style);
    } else if (paint->draw_style_ == 1U) {
        paint_.SetStyle(skity::Paint::kStroke_Style);
    } else {
        paint_.SetStyle(skity::Paint::kFill_Style);
    }

    paint_.SetStrokeWidth(paint->stroke_width_);
    paint_.SetTextSize(paint->text_size_);

    // Resolve color and apply layer alpha (0x00ae00 .. 0x00ae60)
    const uint32_t argb =
        ((paint->color_.flags_ & 1U) != 0U) ? paint->color_.GetPlainColor() : paint->color_.argb_;
    const skity::Vec4 c4f = skity::Paint::Color4fFromColor(argb);
    paint_.SetFillColor(c4f.r, c4f.g, c4f.b, c4f.a);
    paint_.SetStrokeColor(c4f.r, c4f.g, c4f.b, c4f.a);
    paint_.SetAlphaF(paint_.GetAlphaF() * alpha_);

    // Configure skity::Font and faux italic skew -0.25f (0x00af58 .. 0x00af98)
    skity::Font font(sk_typeface);
    font.SetSize(paint->text_size_);
    if (paint->italic_ != 0U && sk_typeface != nullptr && sk_typeface->GetFontStyle().slant == 0U) {
        font.SetSkewX(rodata::kFauxItalicSkewX); // -0.25f (0x00af84)
    }

    // Build GlyphData and negated-Y positions (0x00ae68 .. 0x00af44)
    std::vector<skity::GlyphData> glyph_data(glyph_count);
    font.LoadGlyphMetrics(glyphs, glyph_count, glyph_data.data(), paint_);

    std::vector<skity::Vec2> positions(glyph_count);
    for (uint32_t i = 0; i < glyph_count; ++i) {
        const float px = (x_positions != nullptr) ? x_positions[i] : 0.0f;
        const float py = (y_positions != nullptr) ? -y_positions[i] : 0.0f; // 0x00aeb0: fneg s10, s0
        positions[i] = skity::Vec2{px, py};
    }

    std::vector<skity::TextRun> runs;
    runs.emplace_back(font, std::move(glyph_data), std::move(positions));
    skity::TextBlob blob(std::move(runs));

    // Apply Gaussian blur MaskFilter if blur_radius > 0.0f (0x00b0a4 .. 0x00b0c0)
    if (paint->blur_radius_ > 0.0f) {
        paint_.SetMaskFilter(skity::MaskFilter::MakeBlur(skity::BlurStyle::kNormal, paint->blur_radius_));
    }

    canvas_->DrawTextBlob(&blob, origin_x, origin_y, paint_);
}

void CanvasHelperTextra::DrawRunDelegate(
    const void* delegate, float left, float top, float right, float bottom,
    ttoffice::tttext::IPaintHelper* paint) {
    (void)delegate; (void)left; (void)top; (void)right; (void)bottom; (void)paint;
}

void CanvasHelperTextra::DrawBackgroundDelegate(
    const void* delegate, ttoffice::tttext::IPaintHelper* paint) {
    (void)delegate; (void)paint;
}

void CanvasHelperTextra::DrawImage(
    const char* src, float left, float top, float right, float bottom,
    ttoffice::tttext::IPaintHelper* paint) {
    (void)src; (void)left; (void)top; (void)right; (void)bottom; (void)paint;
}

void CanvasHelperTextra::DrawImageRect(
    const char* src, float src_left, float src_top, float src_right, float src_bottom,
    float dst_left, float dst_top, float dst_right, float dst_bottom,
    ttoffice::tttext::IPaintHelper* paint, bool fill_background) {
    (void)src; (void)src_left; (void)src_top; (void)src_right; (void)src_bottom;
    (void)dst_left; (void)dst_top; (void)dst_right; (void)dst_bottom;
    (void)paint; (void)fill_background;
}

// ============================================================================
// 4. ParagraphStyleTextra Implementation (0x00b45c .. 0x00b52c)
//    Triển khai ParagraphStyleTextra (0x00b45c .. 0x00b52c)
// ============================================================================

/**
 * @brief `ParagraphStyleTextra::GetDefaultFontManager` (`0x00b45c .. 0x00b4d8`):
 *        Allocates `0x50` (80 bytes) `std::__shared_ptr_emplace<FontManagerTextra>` with `font_asset_impl = nullptr`.
 */
std::shared_ptr<ttoffice::tttext::IFontManager> ParagraphStyleTextra::GetDefaultFontManager() {
    return std::make_shared<FontManagerTextra>(nullptr);
}

/**
 * @brief `ParagraphStyleTextra::GetDefaultStyle` (`0x00b4dc .. 0x00b52c`):
 *        Constructs default `ttoffice::tttext::Style` with `FontStyle(400, 5, 0)`.
 */
ttoffice::tttext::Style ParagraphStyleTextra::GetDefaultStyle() {
    ttoffice::tttext::Style style{};
    ttoffice::tttext::FontDescriptor desc{};
    desc.font_style_ = ttoffice::tttext::FontStyle(400, 5, 0);
    desc.font_family_list_.emplace_back(rodata::kStrPingFang);
    desc.font_family_list_.emplace_back(rodata::kStrSansSerif);
    style.SetFontDescriptor(desc);
    return style;
}

// ============================================================================
// 5. TextHelper & TextHelperTextra Implementation (0x00b538 .. 0x00b7c8)
//    Triển khai TextHelper & TextHelperTextra (0x00b538 .. 0x00b7c8)
// ============================================================================

namespace {

TextHelper* g_registered_text_helper = nullptr;

}  // namespace

void TextHelper::RegisterImpl(TextHelper* impl) noexcept {
    g_registered_text_helper = impl;
}

TextHelper* TextHelper::GetRegisteredImpl() noexcept {
    return g_registered_text_helper;
}

TextHelperTextra::TextHelperTextra() = default;

/**
 * @brief `TextHelperTextra::CreateTextLayer` (`0x00b538 .. 0x00b598`):
 *        Allocates `0x28` (40 bytes) `TextLayerImplTextra` (`mov w0, #0x28; bl operator new` @ `0x00b544`)
 *        and initializes `default_family_name_` (`+0x10`) to `"pingfang"`.
 */
std::unique_ptr<TextLayerImpl> TextHelperTextra::CreateTextLayer(TextLayer* text_layer) {
    return std::make_unique<TextLayerImplTextra>(text_layer);
}

/**
 * @brief `TextHelperTextra::CreateFontAsset` (`0x00b59c .. 0x00b600`):
 *        Allocates `0x58` (88 bytes) `FontAssetImplTextra` (`mov w0, #0x58; bl operator new` @ `0x00b5c0`).
 */
std::unique_ptr<FontAssetImpl> TextHelperTextra::CreateFontAsset(FontAsset* font_asset) {
    return std::make_unique<FontAssetImplTextra>(font_asset);
}

/**
 * @brief `TextHelperTextra::CheckIfTextSupported` (`0x00b604 .. 0x00b7b8`):
 *        Disassembly trace:
 *        - `0x00b634`: Returns `false` (`mov w20, wzr`) if `font_asset == nullptr`.
 *        - `0x00b640`: Calls `lynx::base::UTF8ToUTF32(text)`.
 *        - `0x00b650`: Returns `true` (`mov w20, #1`) if UTF-32 string is empty.
 *        - `0x00b660..0x00b6a8`: Iterates through `font_asset->GetTypefaceMap()`; if a custom `skity::Typeface` exists,
 *          checks `ContainGlyph(cp)` for every codepoint in the UTF-32 string.
 *        - `0x00b6bc..0x00b770`: Otherwise queries `skity::FontManager::RefDefault()->MatchFamilyStyleCharacter`
 *          using `font_asset->GetName()` (`+0x30`) and `FontStyle(400, 5, 0)` (`0x00b6cc: mov w8, #0x190; movk w8, #5, lsl #16`),
 *          and verifies `ContainGlyph(cp)` for each character.
 */
bool TextHelperTextra::CheckIfTextSupported(FontAsset* font_asset, const std::string& text) {
    if (font_asset == nullptr) {
        return false;
    }

    const std::u32string utf32 = lynx::base::UTF8ToUTF32(text);
    if (utf32.empty()) {
        return true;
    }

    const auto& tf_map = font_asset->GetTypefaceMap();
    if (!tf_map.empty()) {
        for (const auto& kv : tf_map) {
            if (kv.second != nullptr) {
                for (char32_t cp : utf32) {
                    if (!kv.second->ContainGlyph(static_cast<skity::Unichar>(cp))) {
                        return false;
                    }
                }
                return true;
            }
        }
        return false;
    }

    auto default_mgr = skity::FontManager::RefDefault();
    const skity::FontStyle default_style(400, 5, 0);
    for (char32_t cp : utf32) {
        auto matched = default_mgr->MatchFamilyStyleCharacter(
            font_asset->GetName().c_str(), default_style, nullptr, 0, static_cast<skity::Unichar>(cp));
        if (matched == nullptr || !matched->ContainGlyph(static_cast<skity::Unichar>(cp))) {
            return false;
        }
    }
    return true;
}

TextHelperTextra* TextHelperTextra::GetSingletonInstance() {
    // Matches static singleton @ .bss 0x014018 (guard @ .bss 0x014010) initialized in JNI_OnLoad (0x00b804 .. 0x00b858)
    static TextHelperTextra s_instance{};
    return &s_instance;
}

}  // namespace animax
}  // namespace lynx

// ============================================================================
// 6. Exported JNI_OnLoad Implementation (0x00b7cc .. 0x00b8c3)
//    Triển khai hàm xuất khẩu JNI_OnLoad (0x00b7cc .. 0x00b8c3)
// ============================================================================

extern "C" {

int32_t AnimaxTextra_JNI_OnLoad(void* vm, void* reserved) {
    (void)vm;
    (void)reserved;
    // 0x00b7e0..0x00b800: Logs "animax textra JNI_OnLoad" ("textra_jni.cc":13)
    // 0x00b804..0x00b848: Initializes TextHelperTextra singleton ("use textra text impl" @ "text_helper_textra.cc":15)
    //                     and calls lynx::animax::TextHelper::RegisterImpl(&s_instance)
    lynx::animax::TextHelperTextra* instance = lynx::animax::TextHelperTextra::GetSingletonInstance();
    lynx::animax::TextHelper::RegisterImpl(instance);

    // 0x00b84c..0x00b850: mov w0, #0x6; movk w0, #1, lsl #16 -> 0x00010006 (JNI_VERSION_1_6)
    return 0x00010006;
}

}  // extern "C"
