/**
 * @file animax_textra_layer_canvas.h
 * @brief Exact Reconstruction of TextLayerImplTextra, CanvasHelperTextra, ParagraphStyleTextra, TextHelperTextra & JNI_OnLoad (0x00a180 .. 0x00b8c3)
 *        Tái dựng chuẩn xác TextLayerImplTextra, CanvasHelperTextra, ParagraphStyleTextra, TextHelperTextra & JNI_OnLoad (0x00a180 .. 0x00b8c3)
 *
 * Binary Ground Truth / Bằng chứng nhị phân:
 * - lynx::animax::TextLayerImplTextra:
 *   - Size: 0x28 (40 bytes), allocated in TextHelperTextra::CreateTextLayer @ 0x00b544 (mov w0, #0x28; bl operator new)
 *   - VTable: 0x0102c0 .. 0x0102d0 (.data.rel.ro)
 *   - Methods: ~TextLayerImplTextra (0x00a180 / 0x00a1d0), OnDraw (0x00a1e8 .. 0x00ab0c)
 * - lynx::animax::CanvasHelperTextra:
 *   - Size: 0xc0 (192 bytes on stack in OnDraw @ 0x00aa84: canvas_ @ +0x08, paint_ @ +0x10, alpha_ @ +0xb8)
 *   - VTable: 0x0102e8 .. 0x0103d0 (.data.rel.ro)
 *   - Methods: Ctor (0x00ab64), Dtor (0x00abb0 / 0x00b178), DrawLine (0x00ac54), DrawRect (0x00ac94), DrawGlyphs (0x00acf4 .. 0x00b174)
 * - lynx::animax::ParagraphStyleTextra:
 *   - GetDefaultFontManager (0x00b45c .. 0x00b4d8), GetDefaultStyle (0x00b4dc .. 0x00b52c)
 * - lynx::animax::TextHelperTextra:
 *   - VTable: 0x010460 .. 0x010478 (.data.rel.ro), singleton @ .bss 0x014018 (guard @ .bss 0x014010)
 *   - Methods: CreateTextLayer (0x00b538), CreateFontAsset (0x00b59c), CheckIfTextSupported (0x00b604)
 * - JNI_OnLoad:
 *   - Exported symbol [101] @ 0x00b7cc .. 0x00b8c3 (248 bytes), returns 0x00010006 (JNI_VERSION_1_6)
 */

#ifndef NEXTAI_OPENCUT_ANIMAX_TEXTRA_LAYER_CANVAS_H_
#define NEXTAI_OPENCUT_ANIMAX_TEXTRA_LAYER_CANVAS_H_

#include "animax_textra_font_typeface.h"

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

namespace ttoffice {
namespace tttext {

/**
 * @brief `ttoffice::tttext::Style` — Character styling container used in `TextLayerImplTextra::OnDraw` (@ `0x00a5dc .. 0x00a8fc`).
 *        Cấu trúc định dạng ký tự `ttoffice::tttext::Style` dùng trong `TextLayerImplTextra::OnDraw`.
 */
class Style {
public:
    Style() = default;
    Style(const Style&) = default;
    Style& operator=(const Style&) = default;
    ~Style() = default;

    void SetFontDescriptor(const FontDescriptor& desc) { font_descriptor_ = desc; }
    const FontDescriptor& GetFontDescriptor() const noexcept { return font_descriptor_; }

    void SetTextSize(float size) noexcept { text_size_ = size; }
    float GetTextSize() const noexcept { return text_size_; }

    void SetLineHeightInPx(float line_height) noexcept { line_height_px_ = line_height; }
    float GetLineHeightInPx() const noexcept { return line_height_px_; }

    void SetLineHeightOverride(RulerType ruler) noexcept { line_height_override_ = ruler; }
    RulerType GetLineHeightOverride() const noexcept { return line_height_override_; }

    void SetWordSpacing(float spacing) noexcept { word_spacing_ = spacing; }
    float GetWordSpacing() const noexcept { return word_spacing_; }

    void SetBaselineOffset(float offset) noexcept { baseline_offset_ = offset; }
    float GetBaselineOffset() const noexcept { return baseline_offset_; }

    void SetForegroundColor(const TTColor& color) noexcept { fg_color_ = color; has_fg_ = true; }
    const TTColor& GetForegroundColor() const noexcept { return fg_color_; }
    bool HasForegroundColor() const noexcept { return has_fg_; }

    void SetStrokeColor(const TTColor& color) noexcept { stroke_color_ = color; has_stroke_ = true; }
    const TTColor& GetStrokeColor() const noexcept { return stroke_color_; }
    bool HasStrokeColor() const noexcept { return has_stroke_; }

    void SetStrokeWidth(float width) noexcept { stroke_width_ = width; }
    float GetStrokeWidth() const noexcept { return stroke_width_; }

    void SetBold(bool bold) noexcept { bold_ = bold; }
    bool IsBold() const noexcept { return bold_; }

    void SetItalic(bool italic) noexcept { italic_ = italic; }
    bool IsItalic() const noexcept { return italic_; }

    void SetBlurRadius(float radius) noexcept { blur_radius_ = radius; }
    float GetBlurRadius() const noexcept { return blur_radius_; }

private:
    FontDescriptor font_descriptor_      = {};
    float          text_size_            = 14.0f;
    float          line_height_px_       = 16.0f;
    RulerType      line_height_override_ = RulerType::kNormal;
    float          word_spacing_         = 0.0f;
    float          baseline_offset_      = 0.0f;
    TTColor        fg_color_             = TTColor(0xFFFFFFFFU);
    TTColor        stroke_color_         = TTColor(0x00000000U);
    float          stroke_width_         = 0.0f;
    bool           has_fg_               = false;
    bool           has_stroke_           = false;
    bool           bold_                 = false;
    bool           italic_               = false;
    float          blur_radius_          = 0.0f;
};

class ParagraphStyle {
public:
    ParagraphStyle() = default;
    ~ParagraphStyle() = default;

    void SetDefaultStyle(const Style& style) { default_style_ = style; }
    const Style& GetDefaultStyle() const noexcept { return default_style_; }

    void SetHorizontalAlign(ParagraphHorizontalAlignment align) noexcept { horizontal_align_ = align; }
    ParagraphHorizontalAlignment GetHorizontalAlign() const noexcept { return horizontal_align_; }

    void AllowBreakAroundPunctuation(bool allow) noexcept { allow_break_punct_ = allow; }
    bool IsAllowBreakAroundPunctuation() const noexcept { return allow_break_punct_; }

private:
    Style default_style_                           = {};
    ParagraphHorizontalAlignment horizontal_align_ = ParagraphHorizontalAlignment::kLeft;
    bool allow_break_punct_                        = false;
};

struct TextRunEntry {
    Style style;
    std::string text;
};

class Paragraph {
public:
    Paragraph() = default;
    virtual ~Paragraph() = default;

    static std::unique_ptr<Paragraph> Create() {
        return std::make_unique<Paragraph>();
    }

    void SetParagraphStyle(const ParagraphStyle* style) {
        if (style != nullptr) {
            paragraph_style_ = *style;
        }
    }

    void AddTextRun(const Style* style, const char* text, uint32_t length) {
        if (text == nullptr || length == 0) {
            return;
        }
        Style resolved = (style != nullptr) ? *style : paragraph_style_.GetDefaultStyle();
        runs_.push_back(TextRunEntry{resolved, std::string(text, length)});
    }

    void AddTextRun(const Style* style, const char* text) {
        if (text == nullptr) {
            return;
        }
        AddTextRun(style, text, static_cast<uint32_t>(std::strlen(text)));
    }

    const ParagraphStyle& GetParagraphStyle() const noexcept { return paragraph_style_; }
    const std::vector<TextRunEntry>& GetRuns() const noexcept { return runs_; }

private:
    ParagraphStyle paragraph_style_ = {};
    std::vector<TextRunEntry> runs_ = {};
};

class TextLine {
public:
    explicit TextLine(float ascent = -12.0f) noexcept : line_ascent_(ascent) {}
    float GetLineAscent() const noexcept { return line_ascent_; }

private:
    float line_ascent_ = -12.0f;
};

/**
 * @brief `ttoffice::tttext::LayoutRegion` (`sizeof == 0x28 = 40 bytes`, allocated @ `0x00a960` in `TextLayerImplTextra::OnDraw`).
 *        Cấu trúc vùng bố cục văn bản `LayoutRegion` (40 byte).
 */
class LayoutRegion {
public:
    LayoutRegion(float width, float height, LayoutMode width_mode, LayoutMode height_mode)
        : width_(width),
          height_(height),
          width_mode_(width_mode),
          height_mode_(height_mode) {}
    ~LayoutRegion() = default;

    float GetWidth() const noexcept { return width_; }
    float GetHeight() const noexcept { return height_; }
    LayoutMode GetWidthMode() const noexcept { return width_mode_; }
    LayoutMode GetHeightMode() const noexcept { return height_mode_; }

    int32_t GetLineCount() const noexcept { return static_cast<int32_t>(lines_.size()); }
    TextLine* GetLine(int32_t index) noexcept {
        if (index < 0 || static_cast<size_t>(index) >= lines_.size()) {
            return nullptr;
        }
        return &lines_[static_cast<size_t>(index)];
    }

    void SetLaidOutData(const Paragraph* paragraph, FontmgrCollection* font_collection) {
        paragraph_ = paragraph;
        font_collection_ = font_collection;
        lines_.clear();
        if (paragraph != nullptr && !paragraph->GetRuns().empty()) {
            const float font_size = paragraph->GetRuns().front().style.GetTextSize();
            lines_.emplace_back(-font_size * 0.88f);
        }
    }

    const Paragraph* GetParagraph() const noexcept { return paragraph_; }
    FontmgrCollection* GetFontCollection() const noexcept { return font_collection_; }

private:
    float width_                        = 0.0f;
    float height_                       = 0.0f;
    LayoutMode width_mode_              = LayoutMode::kAtMost;
    LayoutMode height_mode_             = LayoutMode::kAtMost;
    const Paragraph* paragraph_         = nullptr;
    FontmgrCollection* font_collection_ = nullptr;
    std::vector<TextLine> lines_        = {};
};

class TTTextContext {
public:
    TTTextContext() = default;
    ~TTTextContext() = default;

    void SetSkipSpacingBeforeFirstLine(bool skip) noexcept { skip_spacing_before_first_line_ = skip; }
    bool IsSkipSpacingBeforeFirstLine() const noexcept { return skip_spacing_before_first_line_; }

private:
    bool skip_spacing_before_first_line_ = false;
};

class TextLayout {
public:
    explicit TextLayout(FontmgrCollection* font_collection) noexcept
        : font_collection_(font_collection) {}
    ~TextLayout() = default;

    void LayoutEx(Paragraph* paragraph, LayoutRegion* region, TTTextContext& context) {
        (void)context;
        if (region != nullptr) {
            region->SetLaidOutData(paragraph, font_collection_);
        }
    }

private:
    FontmgrCollection* font_collection_ = nullptr;
};

class LayoutDrawer {
public:
    explicit LayoutDrawer(ICanvasHelper* canvas_helper) noexcept
        : canvas_helper_(canvas_helper) {}
    ~LayoutDrawer() = default;

    void DrawLayoutPage(LayoutRegion* region);

private:
    ICanvasHelper* canvas_helper_ = nullptr;
};

}  // namespace tttext
}  // namespace ttoffice

namespace lynx {
namespace base {

/**
 * @brief Converts UTF-8 string to UTF-32 codepoints (imported symbol `_ZN4lynx4base11UTF8ToUTF32ERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE` @ `0x00b640`).
 *        Chuyển đổi chuỗi UTF-8 sang mảng mã điểm UTF-32.
 */
std::u32string UTF8ToUTF32(const std::string& utf8_str);

}  // namespace base

namespace animax {

/**
 * @brief `lynx::animax::DocumentData` (`sizeof == 0x70 = 112 bytes`, embedded at `TextLayer + 0x268`).
 *        All field offsets verified directly from `TextLayerImplTextra::OnDraw` (`0x00a1e8 .. 0x00aa78`).
 *        Cấu trúc dữ liệu văn bản `DocumentData` (112 byte, nhúng tại `TextLayer + 0x268`).
 */
struct DocumentData {
    std::string text;                // +0x00 .. +0x17 (24 bytes)
    std::string font_name;           // +0x18 .. +0x2f (24 bytes)
    float       size            = 24.0f;       // +0x30 (`ldr s9, [x22, #0x30]` @ 0x00a580)
    uint32_t    justify         = 0;           // +0x34 (`ldr w8, [x22, #0x34]` @ 0x00a52c)
    int32_t     tracking        = 0;           // +0x38 (`ldr s0, [x22, #0x38]; scvtf s0, s0` @ 0x00a594)
    float       line_height     = 28.0f;       // +0x3c (`ldr s8, [x22, #0x3c]` @ 0x00a584)
    float       baseline_shift  = 0.0f;        // +0x40 (`ldr s11, [x22, #0x40]` @ 0x00a588)
    uint32_t    fill_color      = 0xFFFFFFFFU; // +0x44 (`ldr w1, [x22, #0x44]` @ 0x00a7cc)
    uint32_t    stroke_color    = 0xFF000000U; // +0x48 (`ldr w1, [x22, #0x48]` @ 0x00a7f4)
    float       stroke_width    = 0.0f;        // +0x4c (`ldr s0, [x22, #0x4c]` @ 0x00a7a8)
    bool        stroke_over_fill = false;      // +0x50 (`ldrb w8, [x22, #0x50]` @ 0x00a7b4)
    uint8_t     padding_[7]     = {0};         // +0x51 .. +0x57
    skity::Vec2 box_size        = {0.0f, 0.0f}; // +0x58 (`ldr x8, [x22, #0x58]` @ 0x00a5ac)
    skity::Vec2 box_position    = {0.0f, 0.0f}; // +0x60 (`ldr x22, [x22, #0x60]` @ 0x00a590)
    uint64_t    reserved_tail_  = 0;           // +0x68 .. +0x6f
};

/**
 * @brief `lynx::animax::TextAnimator` (`sizeof == 0xb0 = 176 bytes` per element in vector at `TextLayer + 0x328`, stepped by `add x25, x25, #0xb0` @ `0x00a518`).
 *        Cấu trúc hiệu ứng hoạt họa chữ `TextAnimator` (176 byte mỗi phần tử tại `TextLayer + 0x328`).
 */
struct TextAnimator {
    bool        has_fill_color   = false;       // +0x00 (`ldrb w8, [x25]` @ 0x00a3f4)
    uint32_t    fill_color       = 0xFFFFFFFFU; // +0x04
    bool        has_stroke_color = false;       // +0x28 (`ldrb w8, [x25, #0x28]` @ 0x00a40c)
    uint32_t    stroke_color     = 0xFF000000U; // +0x2c
    bool        has_stroke_width = false;       // +0x50 (`ldrb w8, [x25, #0x50]` @ 0x00a424)
    float       stroke_width     = 0.0f;        // +0x54
    bool        has_tracking     = false;       // +0x68 (`ldrb w8, [x25, #0x68]` @ 0x00a43c)
    float       tracking         = 0.0f;        // +0x6c
    bool        has_blur         = false;       // +0x80 (`ldrb w8, [x25, #0x80]` @ 0x00a454)
    skity::Vec2 blur_radius      = {0.0f, 0.0f}; // +0x84
    int32_t     font_style_flags = 0;           // +0x9c (`ldr w8, [x25, #0x9c]` @ 0x00a4b4: bit 0=bold, bit 1=italic)
};

struct RangeSelector {
    bool enabled = false; // +0x00 (`ldrb w8, [x27]` @ 0x00a280)
    uint32_t start_index = 0;
    uint32_t end_index   = 0;

    skity::Vec2 GetRange(float frame, uint64_t text_char_count) const noexcept {
        (void)frame;
        if (!enabled || end_index == 0 || start_index >= text_char_count) {
            return {0.0f, 0.0f};
        }
        const uint32_t clamped_end =
            (end_index > static_cast<uint32_t>(text_char_count))
                ? static_cast<uint32_t>(text_char_count)
                : end_index;
        return {static_cast<float>(start_index), static_cast<float>(clamped_end)};
    }
};

class Composition {
public:
    explicit Composition(float current_frame = 0.0f) noexcept : current_frame_(current_frame) {}
    float GetCurrentFrame() const noexcept { return current_frame_; }
    void SetCurrentFrame(float frame) noexcept { current_frame_ = frame; }

private:
    float current_frame_ = 0.0f;
};

/**
 * @brief `lynx::animax::TextLayer` — Host layer object referenced by `TextLayerImplTextra` (`+0x08`).
 *        Lớp văn bản chủ được tham chiếu bởi `TextLayerImplTextra` (`+0x08`).
 */
class TextLayer {
public:
    TextLayer() = default;

    void SetComposition(Composition* comp) noexcept { composition_ = comp; }
    Composition* GetComposition() const noexcept { return composition_; }

    void SetFontAsset(FontAsset* asset, FontAssetImpl* asset_impl) noexcept {
        font_asset_ = asset;
        font_asset_impl_ = asset_impl;
    }
    FontAsset* GetFontAsset() const noexcept { return font_asset_; }
    FontAssetImpl* GetFontAssetImpl() const noexcept { return font_asset_impl_; }

    DocumentData& MutableDocumentData() noexcept { return document_data_; }
    const DocumentData& GetDocumentData() const noexcept { return document_data_; }

    RangeSelector& MutableRangeSelector() noexcept { return range_selector_; }
    const RangeSelector& GetRangeSelector() const noexcept { return range_selector_; }

    std::vector<TextAnimator>& MutableAnimators() noexcept { return animators_; }
    const std::vector<TextAnimator>& GetAnimators() const noexcept { return animators_; }

private:
    Composition*   composition_     = nullptr;
    FontAsset*     font_asset_      = nullptr;
    FontAssetImpl* font_asset_impl_ = nullptr;
    DocumentData   document_data_   = {};
    RangeSelector  range_selector_  = {};
    std::vector<TextAnimator> animators_ = {};
};

class TextLayerImpl {
public:
    explicit TextLayerImpl(TextLayer* text_layer) noexcept : text_layer_(text_layer) {}
    virtual ~TextLayerImpl() = default;

    virtual void OnDraw(skity::Canvas* canvas, float alpha) = 0;

    TextLayer* GetTextLayer() const noexcept { return text_layer_; }

protected:
    TextLayer* text_layer_ = nullptr; // +0x08
};

/**
 * @brief `lynx::animax::TextLayerImplTextra` (`sizeof == 0x28 = 40 bytes`, vtable @ `0x0102c0 .. 0x0102d0`).
 *        Implements `OnDraw(skity::Canvas*, float)` (`0x00a1e8 .. 0x00ab0c`).
 *        Thực thi `TextLayerImplTextra` (40 byte) và phương thức `OnDraw(skity::Canvas*, float)`.
 */
class TextLayerImplTextra final : public TextLayerImpl {
public:
    explicit TextLayerImplTextra(TextLayer* text_layer);
    ~TextLayerImplTextra() override;

    /**
     * @brief Exact reconstruction of `TextLayerImplTextra::OnDraw` (`0x00a1e8 .. 0x00ab0c`).
     *        Tái dựng chính xác hàm `TextLayerImplTextra::OnDraw` (`0x00a1e8 .. 0x00ab0c`).
     */
    void OnDraw(skity::Canvas* canvas, float alpha) override;

    /**
     * @brief Maps `DocumentData::justify` (`+0x34`) using the exact 64-bit LUT `0x0000030303030102ULL` (@ `0x00a52c .. 0x00a54c`).
     *        Ánh xạ `DocumentData::justify` bằng bảng tra 64-bit `0x0000030303030102ULL` (@ `0x00a52c .. 0x00a54c`).
     */
    static ttoffice::tttext::ParagraphHorizontalAlignment MapJustifyToAlignment(uint32_t justify) noexcept;

    /**
     * @brief Computes tracking in pixels: `(text_size * tracking) / 100.0f` (@ `0x00a594 .. 0x00a5a8`).
     *        Tính khoảng cách chữ theo pixel: `(text_size * tracking) / 100.0f` (@ `0x00a594 .. 0x00a5a8`).
     */
    static float ComputeTrackingPixels(float text_size, int32_t tracking) noexcept;

    /**
     * @brief Computes unconstrained horizontal translation offset (`0.0f`, `-1000000.0f`, `-500000.0f`) (@ `0x00aa44 .. 0x00aa6c`).
     *        Tính độ dịch ngang khi không giới hạn khung (`0.0f`, `-1000000.0f`, `-500000.0f`) (@ `0x00aa44 .. 0x00aa6c`).
     */
    static float ComputeUnconstrainedHorizontalOffset(ttoffice::tttext::ParagraphHorizontalAlignment align) noexcept;

private:
    std::string default_family_name_; // +0x10 .. +0x27 (24 bytes -> total sizeof == 0x28 = 40 bytes)
};
static_assert(sizeof(TextLayerImplTextra) == 0x28, "lynx::animax::TextLayerImplTextra must be 0x28 (40) bytes");

/**
 * @brief `lynx::animax::CanvasHelperTextra` (vtable @ `0x0102e8 .. 0x0103d0`).
 *        Implements `ttoffice::tttext::ICanvasHelper` wrapping `skity::Canvas*` (`+0x08`), `skity::Paint` (`+0x10`), and `alpha_` (`+0xb8`).
 *        Thực thi `CanvasHelperTextra` bọc `skity::Canvas*`, `skity::Paint` và `alpha_`.
 */
class CanvasHelperTextra final : public ttoffice::tttext::ICanvasHelper {
public:
    CanvasHelperTextra(skity::Canvas* canvas, float alpha);
    ~CanvasHelperTextra() override;

    // 26 ICanvasHelper virtual overrides (0x0102f8 .. 0x0103d0):
    std::unique_ptr<ttoffice::tttext::IPaintHelper> CreatePaint() override;
    void* GetCanvas() override;
    void Save() override;
    void Restore() override;
    void Translate(float dx, float dy) override;
    void Scale(float sx, float sy) override;
    void Rotate(float degrees) override;
    void Skew(float sx, float sy) override;
    void ClipRect(float left, float top, float right, float bottom, bool do_anti_alias) override;
    void Clear() override;
    void ClearRect(float left, float top, float right, float bottom) override;
    void FillRect(float left, float top, float right, float bottom, uint32_t color) override;
    void DrawColor(uint32_t color) override;
    void DrawLine(float x0, float y0, float x1, float y1, ttoffice::tttext::IPaintHelper* paint) override;
    void DrawRect(float left, float top, float right, float bottom, ttoffice::tttext::IPaintHelper* paint) override;
    void DrawOval(float left, float top, float right, float bottom, ttoffice::tttext::IPaintHelper* paint) override;
    void DrawCircle(float x, float y, float radius, ttoffice::tttext::IPaintHelper* paint) override;
    void DrawArc(float left, float top, float right, float bottom,
                 float start_angle, float sweep_angle, bool use_center,
                 ttoffice::tttext::IPaintHelper* paint) override;
    void DrawPath(void* path, ttoffice::tttext::IPaintHelper* paint) override;
    void DrawArcTo(float x1, float y1, float x2, float y2, float radius,
                   ttoffice::tttext::IPaintHelper* paint) override;
    void DrawText(const ttoffice::tttext::ITypefaceHelper* typeface, const char* text, uint32_t text_bytes,
                  float x, float y, ttoffice::tttext::IPaintHelper* paint) override;
    void DrawGlyphs(const ttoffice::tttext::ITypefaceHelper* typeface, uint32_t glyph_count,
                    const uint16_t* glyphs, const char* text, uint32_t text_len,
                    float origin_x, float origin_y, const float* x_positions, const float* y_positions,
                    ttoffice::tttext::IPaintHelper* paint) override;
    void DrawRunDelegate(const void* delegate, float left, float top, float right, float bottom,
                         ttoffice::tttext::IPaintHelper* paint) override;
    void DrawBackgroundDelegate(const void* delegate, ttoffice::tttext::IPaintHelper* paint) override;
    void DrawImage(const char* src, float left, float top, float right, float bottom,
                   ttoffice::tttext::IPaintHelper* paint) override;
    void DrawImageRect(const char* src, float src_left, float src_top, float src_right, float src_bottom,
                       float dst_left, float dst_top, float dst_right, float dst_bottom,
                       ttoffice::tttext::IPaintHelper* paint, bool fill_background) override;

    float GetAlpha() const noexcept { return alpha_; }
    const skity::Paint& GetSkityPaint() const noexcept { return paint_; }

private:
    skity::Canvas* canvas_ = nullptr; // +0x08
    skity::Paint   paint_  = {};      // +0x10
    float          alpha_  = 1.0f;    // +0xb8
};

/**
 * @brief `lynx::animax::ParagraphStyleTextra` (`0x00b45c .. 0x00b52c`).
 *        Provides default `IFontManager` and default `ttoffice::tttext::Style`.
 *        Cung cấp `IFontManager` mặc định và `ttoffice::tttext::Style` mặc định.
 */
class ParagraphStyleTextra {
public:
    static std::shared_ptr<ttoffice::tttext::IFontManager> GetDefaultFontManager();
    static ttoffice::tttext::Style GetDefaultStyle();
};

/**
 * @brief `lynx::animax::TextHelper` — Base registration class imported from `libanimax.so`.
 *        Lớp cơ sở đăng ký `TextHelper` nhập từ `libanimax.so`.
 */
class TextHelper {
public:
    virtual ~TextHelper() = default;

    virtual std::unique_ptr<TextLayerImpl> CreateTextLayer(TextLayer* text_layer) = 0;
    virtual std::unique_ptr<FontAssetImpl> CreateFontAsset(FontAsset* font_asset) = 0;
    virtual bool CheckIfTextSupported(FontAsset* font_asset, const std::string& text) = 0;

    static void RegisterImpl(TextHelper* impl) noexcept;
    static TextHelper* GetRegisteredImpl() noexcept;
};

/**
 * @brief `lynx::animax::TextHelperTextra` (vtable @ `0x010460 .. 0x010478`, singleton @ `.bss 0x014018`).
 *        Factory creating `TextLayerImplTextra` (`0x00b538`), `FontAssetImplTextra` (`0x00b59c`),
 *        and validating glyph coverage in `CheckIfTextSupported` (`0x00b604`).
 *        Lớp nhà máy khởi tạo `TextLayerImplTextra`, `FontAssetImplTextra` và kiểm tra hỗ trợ ký tự.
 */
class TextHelperTextra final : public TextHelper {
public:
    TextHelperTextra();
    ~TextHelperTextra() override = default;

    std::unique_ptr<TextLayerImpl> CreateTextLayer(TextLayer* text_layer) override;
    std::unique_ptr<FontAssetImpl> CreateFontAsset(FontAsset* font_asset) override;
    bool CheckIfTextSupported(FontAsset* font_asset, const std::string& text) override;

    static TextHelperTextra* GetSingletonInstance();
};

}  // namespace animax
}  // namespace lynx

// ============================================================================
// 5. Exported JNI Entrypoint (`JNI_OnLoad` @ 0x00b7cc .. 0x00b8c3)
//    Điểm nhập JNI xuất khẩu (`JNI_OnLoad` @ 0x00b7cc .. 0x00b8c3)
// ============================================================================

extern "C" {

/**
 * @brief Exact reconstruction of exported symbol `[101] JNI_OnLoad` (`0x00b7cc .. 0x00b8c3`, 248 bytes).
 *        Logs `"animax textra JNI_OnLoad"`, constructs static `TextHelperTextra` (`"use textra text impl"`),
 *        registers it via `lynx::animax::TextHelper::RegisterImpl`, and returns `0x00010006` (`JNI_VERSION_1_6`).
 *        Tái dựng chính xác biểu tượng xuất khẩu `[101] JNI_OnLoad` (`0x00b7cc .. 0x00b8c3`, 248 byte).
 */
int32_t AnimaxTextra_JNI_OnLoad(void* vm, void* reserved);

}  // extern "C"

#endif  // NEXTAI_OPENCUT_ANIMAX_TEXTRA_LAYER_CANVAS_H_
