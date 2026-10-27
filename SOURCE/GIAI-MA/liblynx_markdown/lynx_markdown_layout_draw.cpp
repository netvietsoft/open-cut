/**
 * @file lynx_markdown_layout_draw.cpp
 * @brief Clean-Room C++17 Implementation of TTText Layout Engine, Typewriter Renderer, Hit-Testing & BufferCanvasHelper
 *        Triển khai C++17 Tái cấu trúc sạch Động cơ dàn trang TTText, Bộ kết xuất Typewriter, Hit-Testing & BufferCanvasHelper
 *
 * Binary Target / Đích nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/liblynx_markdown.so (247,888 bytes)
 *   - BufferCanvasHelper & Paint:    0x018924..0x019d80 (vtables @ 0x038148, 0x038248, 0x038398)
 *   - nativeLayout:                  0x0102a0..0x010b84
 *   - nativeDraw / DrawWithCursor:   0x011100..0x011524
 *   - nativeGetCursorPosition:       0x011528..0x0117e8
 *   - nativeGetSelectionRectByCharPos: 0x013c4c..0x0140b8
 *   - nativeGetCharRangeByPoint:     0x0140bc..0x0141ec
 *   - nativeMarkdownOffsetToChar:    0x0142d4..0x014354
 *   - nativeDrawRegion / Typewriter: 0x01693c..0x016f74
 *   - nativeGetShowedRegion / Extra: 0x017dc4..0x018264
 *   - nativeInheritState:            0x018268..0x018420
 */

#include "lynx_markdown_layout_draw.h"
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

// ============================================================================
// ttoffice::tttext Runtime Implementation (PLT 0x0355b0..0x035850)
// Triển khai thời gian chạy ttoffice::tttext (PLT 0x0355b0..0x035850)
// ============================================================================
namespace ttoffice {
namespace tttext {

namespace {
class DefaultFontManagerImpl : public IFontManager {
public:
    ~DefaultFontManagerImpl() override = default;
};
} // namespace

FontmgrCollection::FontmgrCollection(std::shared_ptr<IFontManager> default_mgr)
    : default_font_manager_(std::move(default_mgr)) {}

TTTextJNIProxy& TTTextJNIProxy::GetInstance() {
    static TTTextJNIProxy instance;
    return instance;
}

std::shared_ptr<IFontManager> TTTextJNIProxy::GetDefaultFontManager() {
    static std::shared_ptr<IFontManager> mgr = std::make_shared<DefaultFontManagerImpl>();
    return mgr;
}

Style::Style() = default;
Style::Style(const Style& other) = default;
Style::~Style() = default;
Style& Style::operator=(const Style& other) = default;

void Style::ClearShapeStyle() const {}

ParagraphStyle::ParagraphStyle() = default;
ParagraphStyle::ParagraphStyle(const ParagraphStyle& other) = default;
ParagraphStyle::~ParagraphStyle() = default;

void ParagraphStyle::SetHangingIndentInPx(float px) { hanging_indent_px_ = px; }
float ParagraphStyle::GetHangingIndentInPx() const { return hanging_indent_px_; }
void ParagraphStyle::SetFirstLineIndentInPx(float px) { first_line_indent_px_ = px; }
void ParagraphStyle::SetLineHeightInPx(float px, RulerType ruler) {
    line_height_px_ = px;
    line_height_ruler_ = ruler;
}
void ParagraphStyle::SetLineSpaceAfterPx(float px) { line_space_after_px_ = px; }
void ParagraphStyle::AllowBreakAroundPunctuation(bool allow) { allow_break_around_punctuation_ = allow; }
void ParagraphStyle::SetEllipsis(const std::u16string& ellipsis) { ellipsis_u16_ = ellipsis; }
void ParagraphStyle::SetEllipsis(std::shared_ptr<RunDelegate> ellipsis_delegate) {
    ellipsis_delegate_ = std::move(ellipsis_delegate);
}

std::unique_ptr<Paragraph> Paragraph::Create() {
    return std::make_unique<Paragraph>();
}

void Paragraph::SetParagraphStyle(const ParagraphStyle* style) {
    if (style) {
        paragraph_style_ = *style;
    }
}

void Paragraph::AddTextRun(const Style* style, const char* text, uint32_t byte_len) {
    if (!text || byte_len == 0) return;
    std::string_view sv(text, byte_len);
    std::u16string u16 = lynx::base::U8StringToU16(sv);
    uint32_t start_char = static_cast<uint32_t>(u16_text_.size());
    u8_text_.append(text, byte_len);
    u16_text_.append(u16);
    uint32_t end_char = static_cast<uint32_t>(u16_text_.size());

    RunSpan span;
    span.char_start = start_char;
    span.char_end = end_char;
    if (style) {
        span.style = *style;
    } else {
        span.style = paragraph_style_.default_style_;
    }
    runs_.push_back(std::move(span));
}

void Paragraph::AddShapeRun(const Style* style, std::shared_ptr<RunDelegate> delegate, bool /*is_ghost*/) {
    if (!delegate) return;
    uint32_t start_char = static_cast<uint32_t>(u16_text_.size());
    u8_text_.append("\xEF\xBF\xBC"); // U+FFFC OBJECT REPLACEMENT CHARACTER
    u16_text_.push_back(0xFFFCu);
    uint32_t end_char = static_cast<uint32_t>(u16_text_.size());

    RunSpan span;
    span.char_start = start_char;
    span.char_end = end_char;
    if (style) {
        span.style = *style;
    } else {
        span.style = paragraph_style_.default_style_;
    }
    span.delegate = std::move(delegate);
    runs_.push_back(std::move(span));
}

TTTextContext::TTTextContext() = default;
TTTextContext::~TTTextContext() = default;
void TTTextContext::Reset() {
    first_line_ = true;
    layout_position_ = 0;
    layout_bottom_ = 0.0f;
    overflowed_ = false;
}

LayoutRegion::LayoutRegion(float width, float height, LayoutMode width_mode, LayoutMode height_mode,
                           LayoutPageListener* /*listener*/)
    : max_width_(width > 0.0f ? width : 10000.0f),
      max_height_(height > 0.0f ? height : 100000.0f),
      width_mode_(width_mode),
      height_mode_(height_mode) {}

LayoutRegion::~LayoutRegion() = default;

void LayoutRegion::UpdateLayoutedSize(TextLine* line, const TTTextContext& /*context*/) {
    if (!line) return;
    layouted_width_ = std::max(layouted_width_, line->line_right_ - line->line_left_);
    layouted_height_ = std::max(layouted_height_, line->line_bottom_);
}

TextLayout::TextLayout(FontmgrCollection* font_collection, ShaperType shaper_type)
    : font_collection_(font_collection), shaper_type_(shaper_type) {}

TextLayout::~TextLayout() = default;

/**
 * @brief Deterministic line-breaking & shaping pass (`TextLayout::LayoutEx` @ PLT `0x0356e0`)
 *        Lượt ngắt dòng & định hình văn bản tất định (`TextLayout::LayoutEx` @ PLT `0x0356e0`)
 */
uint32_t TextLayout::LayoutEx(Paragraph* paragraph, LayoutRegion* region, TTTextContext& context) const {
    if (!paragraph || !region) return 0;
    region->paragraph_ = paragraph;
    region->lines_.clear();
    region->layouted_width_ = 0.0f;
    region->layouted_height_ = 0.0f;

    const uint32_t total_chars = paragraph->GetCharCount();
    if (total_chars == 0) {
        return 0;
    }

    const float avail_width = std::max(32.0f, region->max_width_);
    const float base_line_height = (paragraph->paragraph_style_.line_height_px_ > 0.0f)
                                       ? paragraph->paragraph_style_.line_height_px_
                                       : std::max(18.0f, paragraph->paragraph_style_.default_style_.text_size_ * 1.4f);
    const float line_space = paragraph->paragraph_style_.line_space_after_px_;
    const int32_t max_lines = paragraph->paragraph_style_.max_lines_;

    // Precompute per-character advance and height from runs
    std::vector<float> advances(total_chars, paragraph->paragraph_style_.default_style_.text_size_ * 0.55f);
    std::vector<float> heights(total_chars, base_line_height);
    for (const auto& run : paragraph->runs_) {
        for (uint32_t c = run.char_start; c < run.char_end && c < total_chars; ++c) {
            if (run.delegate) {
                run.delegate->Layout();
                advances[c] = std::max(4.0f, run.delegate->GetAdvance());
                float h = std::fabs(run.delegate->GetAscent()) + std::fabs(run.delegate->GetDescent());
                heights[c] = std::max(base_line_height, h);
            } else {
                char16_t ch = paragraph->u16_text_[c];
                float char_w = (ch >= 0x2E80u) ? run.style.text_size_ : (run.style.text_size_ * 0.56f);
                advances[c] = char_w;
                heights[c] = std::max(base_line_height, run.style.text_size_ * 1.35f);
            }
        }
    }

    float cur_y = 0.0f;
    uint32_t line_start = 0;
    while (line_start < total_chars) {
        if (max_lines > 0 && static_cast<int32_t>(region->lines_.size()) >= max_lines) {
            context.overflowed_ = true;
            break;
        }
        float indent = (line_start == 0)
                           ? paragraph->paragraph_style_.first_line_indent_px_
                           : paragraph->paragraph_style_.hanging_indent_px_;
        float cur_x = std::max(0.0f, indent);
        float max_line_h = base_line_height;
        uint32_t cursor = line_start;

        while (cursor < total_chars) {
            char16_t ch = paragraph->u16_text_[cursor];
            if (ch == '\n') {
                ++cursor;
                break;
            }
            float w = advances[cursor];
            if (cursor > line_start && cur_x + w > avail_width) {
                break;
            }
            cur_x += w;
            max_line_h = std::max(max_line_h, heights[cursor]);
            ++cursor;
        }
        if (cursor == line_start) {
            ++cursor;
        }

        auto line = std::make_unique<TextLine>();
        line->paragraph_ = paragraph;
        line->start_char_pos_ = line_start;
        line->end_char_pos_ = cursor;
        line->line_left_ = std::max(0.0f, indent);
        line->line_right_ = cur_x;
        line->line_top_ = cur_y;
        line->line_bottom_ = cur_y + max_line_h;
        line->baseline_ = cur_y + max_line_h * 0.8f;
        line->char_advances_.assign(advances.begin() + line_start, advances.begin() + cursor);

        region->UpdateLayoutedSize(line.get(), context);
        region->lines_.push_back(std::move(line));

        cur_y += max_line_h + line_space;
        line_start = cursor;
        context.layout_position_ = line_start;
        context.layout_bottom_ = cur_y;
    }

    return context.overflowed_ ? 1u : 0u;
}

LayoutDrawer::LayoutDrawer(ICanvasHelper* canvas) : canvas_(canvas) {}
LayoutDrawer::~LayoutDrawer() = default;

void LayoutDrawer::DrawLayoutPage(LayoutRegion* region) {
    if (!region || !canvas_) return;
    for (uint32_t i = 0; i < region->GetLineCount(); ++i) {
        TextLine* line = region->GetLine(i);
        if (line) {
            DrawTextLine(line, line->start_char_pos_, line->end_char_pos_);
        }
    }
}

void LayoutDrawer::DrawTextLine(TextLine* line, uint32_t char_start, uint32_t char_end) {
    if (!line || !canvas_ || !line->paragraph_) return;
    uint32_t s = std::max(line->start_char_pos_, char_start);
    uint32_t e = std::min(line->end_char_pos_, char_end);
    if (s >= e) return;

    Paragraph* para = line->paragraph_;
    float x_cursor = line->line_left_;
    for (uint32_t c = line->start_char_pos_; c < s; ++c) {
        uint32_t rel = c - line->start_char_pos_;
        if (rel < line->char_advances_.size()) {
            x_cursor += line->char_advances_[rel];
        }
    }

    for (const auto& run : para->runs_) {
        uint32_t rs = std::max(s, run.char_start);
        uint32_t re = std::min(e, run.char_end);
        if (rs >= re) continue;

        float run_width = 0.0f;
        for (uint32_t c = rs; c < re; ++c) {
            uint32_t rel = c - line->start_char_pos_;
            if (rel < line->char_advances_.size()) {
                run_width += line->char_advances_[rel];
            }
        }

        auto paint = canvas_->CreatePaint();
        paint->font_family_ = run.style.font_family_;
        paint->text_size_ = run.style.text_size_;
        paint->color_ = run.style.foreground_color_;
        paint->bold_ = run.style.bold_ || (run.style.font_weight_ >= 600);
        paint->italic_ = run.style.italic_;
        paint->underline_ = (run.style.decoration_type_ == 1);
        paint->strike_through_ = (run.style.decoration_type_ == 2);

        if (run.style.background_color_ != 0) {
            auto bg_paint = canvas_->CreatePaint();
            bg_paint->color_ = run.style.background_color_;
            bg_paint->fill_style_ = 0;
            canvas_->DrawRect(x_cursor, line->line_top_, x_cursor + run_width, line->line_bottom_, bg_paint.get());
        }

        if (run.delegate) {
            canvas_->DrawRunDelegate(run.delegate.get(), x_cursor, line->line_top_,
                                     x_cursor + run_width, line->line_bottom_, paint.get());
        } else {
            // Convert UTF-16 slice back to UTF-8 for DrawText
            std::string run_u8;
            for (uint32_t c = rs; c < re && c < para->u16_text_.size(); ++c) {
                char16_t u = para->u16_text_[c];
                if (u < 0x80u) {
                    run_u8.push_back(static_cast<char>(u));
                } else if (u < 0x800u) {
                    run_u8.push_back(static_cast<char>(0xC0u | (u >> 6)));
                    run_u8.push_back(static_cast<char>(0x80u | (u & 0x3Fu)));
                } else {
                    run_u8.push_back(static_cast<char>(0xE0u | (u >> 12)));
                    run_u8.push_back(static_cast<char>(0x80u | ((u >> 6) & 0x3Fu)));
                    run_u8.push_back(static_cast<char>(0x80u | (u & 0x3Fu)));
                }
            }
            canvas_->DrawText(run_u8.c_str(), static_cast<uint32_t>(run_u8.size()),
                              x_cursor, line->baseline_, paint.get());
        }

        x_cursor += run_width;
    }
}

} // namespace tttext
} // namespace ttoffice

// ============================================================================
// BufferCanvasHelper & RunDelegate Implementation (0x018924..0x019d80)
// Triển khai BufferCanvasHelper & RunDelegate (0x018924..0x019d80)
// ============================================================================
namespace lynx {
namespace markdown {

BufferCanvasHelper::BufferCanvasHelper(size_t initial_capacity)
    : size_(0), capacity_(std::max<size_t>(initial_capacity, 0x400)) {
    buffer_ = static_cast<uint8_t*>(std::malloc(capacity_));
}

BufferCanvasHelper::~BufferCanvasHelper() {
    if (buffer_) {
        std::free(buffer_);
        buffer_ = nullptr;
    }
}

/**
 * @brief Allocate `IPaintHelper` (`sizeof = 0x58` = 88 bytes, default font `"pingfang"`, size `14.0f` @ `0x01897c..0x0189e0`)
 *        Cấp phát `IPaintHelper` (`sizeof = 0x58` = 88 byte, font mặc định `"pingfang"`, cỡ `14.0f` @ `0x01897c..0x0189e0`)
 */
std::unique_ptr<ttoffice::tttext::IPaintHelper> BufferCanvasHelper::CreatePaint() {
    auto paint = std::make_unique<ttoffice::tttext::IPaintHelper>();
    paint->font_family_ = "pingfang";
    paint->text_size_ = 14.0f;
    paint->color_ = 0xFF000000u;
    paint->stroke_width_ = 1.0f;
    return paint;
}

void BufferCanvasHelper::WriteBytes(const void* src, size_t len) {
    if (!src || len == 0) return;
    if (size_ + len > capacity_) {
        size_t new_cap = std::max(capacity_ * 2, size_ + len + 0x400);
        uint8_t* grown = static_cast<uint8_t*>(std::realloc(buffer_, new_cap));
        if (!grown) return;
        buffer_ = grown;
        capacity_ = new_cap;
    }
    std::memcpy(buffer_ + size_, src, len);
    size_ += len;
}

void BufferCanvasHelper::WritePaintState(const ttoffice::tttext::IPaintHelper* paint) {
    if (!paint) {
        WriteU32(0xFF000000u);
        WriteF32(1.0f);
        WriteU8(0);
        WriteF32(14.0f);
        return;
    }
    WriteU32(paint->color_);
    WriteF32(paint->stroke_width_);
    WriteU8(paint->fill_style_);
    WriteF32(paint->text_size_);
}

void BufferCanvasHelper::Save() {
    WriteU8(static_cast<uint8_t>(CanvasStreamOp::kSave)); // 0x0189e8: mov w9, #2
}

void BufferCanvasHelper::Restore() {
    WriteU8(static_cast<uint8_t>(CanvasStreamOp::kRestore)); // 0x018a34: mov w9, #3
}

void BufferCanvasHelper::Translate(float dx, float dy) {
    WriteU8(static_cast<uint8_t>(CanvasStreamOp::kTranslate)); // 0x018a80: mov w9, #4
    WriteF32(dx);
    WriteF32(dy);
}

void BufferCanvasHelper::ClipRect(float left, float top, float right, float bottom, bool doAntiAlias) {
    WriteU8(static_cast<uint8_t>(CanvasStreamOp::kClipRect)); // 0x018b10: mov w9, #8
    WriteF32(left);
    WriteF32(top);
    WriteF32(right);
    WriteF32(bottom);
    WriteU8(doAntiAlias ? 1 : 0);
}

void BufferCanvasHelper::DrawLine(float x1, float y1, float x2, float y2,
                                  ttoffice::tttext::IPaintHelper* paint) {
    WriteU8(static_cast<uint8_t>(CanvasStreamOp::kDrawLine)); // 0x018bd8: op = 13
    WriteF32(x1);
    WriteF32(y1);
    WriteF32(x2);
    WriteF32(y2);
    WritePaintState(paint);
}

void BufferCanvasHelper::DrawRect(float left, float top, float right, float bottom,
                                  ttoffice::tttext::IPaintHelper* paint) {
    WriteU8(static_cast<uint8_t>(CanvasStreamOp::kDrawRect)); // 0x018d40: op = 14
    WriteF32(left);
    WriteF32(top);
    WriteF32(right);
    WriteF32(bottom);
    WritePaintState(paint);
}

void BufferCanvasHelper::DrawCircle(float x, float y, float radius,
                                    ttoffice::tttext::IPaintHelper* paint) {
    WriteU8(static_cast<uint8_t>(CanvasStreamOp::kDrawCircle)); // 0x018ea8: op = 16
    WriteF32(x);
    WriteF32(y);
    WriteF32(radius);
    WritePaintState(paint);
}

void BufferCanvasHelper::DrawText(const char* text, uint32_t len, float x, float y,
                                  ttoffice::tttext::IPaintHelper* paint) {
    WriteU8(static_cast<uint8_t>(CanvasStreamOp::kDrawText)); // 0x018ff8: op = 19
    WriteU32(len);
    if (text && len > 0) {
        WriteBytes(text, len);
    }
    WriteF32(x);
    WriteF32(y);
    WritePaintState(paint);
}

void BufferCanvasHelper::DrawGlyphs(const uint16_t* glyphs, const float* positions, uint32_t count,
                                    float x, float y, ttoffice::tttext::IPaintHelper* paint) {
    WriteU8(static_cast<uint8_t>(CanvasStreamOp::kDrawGlyphs)); // 0x01914c: op = 20
    WriteU32(count);
    if (glyphs && count > 0) {
        WriteBytes(glyphs, count * sizeof(uint16_t));
    }
    if (positions && count > 0) {
        WriteBytes(positions, count * 2 * sizeof(float));
    }
    WriteF32(x);
    WriteF32(y);
    WritePaintState(paint);
}

void BufferCanvasHelper::DrawRunDelegate(ttoffice::tttext::RunDelegate* delegate,
                                         float left, float top, float right, float bottom,
                                         ttoffice::tttext::IPaintHelper* /*paint*/) {
    WriteU8(static_cast<uint8_t>(CanvasStreamOp::kDrawDelegate)); // 0x019390: op = 21
    WriteF32(left);
    WriteF32(top);
    WriteF32(right);
    WriteF32(bottom);
    if (delegate) {
        delegate->Draw(this, left, top);
    }
}

void BufferCanvasHelper::DrawRoundRect(float left, float top, float right, float bottom,
                                       float radius, ttoffice::tttext::IPaintHelper* paint) {
    WriteU8(static_cast<uint8_t>(CanvasStreamOp::kDrawRoundRect)); // 0x019474: op = 26
    WriteF32(left);
    WriteF32(top);
    WriteF32(right);
    WriteF32(bottom);
    WriteF32(radius);
    WritePaintState(paint);
}

void InlineViewRunDelegate::Draw(ttoffice::tttext::ICanvasHelper* canvas, float x, float y) {
    rect_ = RectF{x, y, x + width_, y + height_};
    if (canvas) {
        auto paint = canvas->CreatePaint();
        canvas->DrawRect(x, y, x + width_, y + height_, paint.get());
    }
}

void ImageRunDelegate::Draw(ttoffice::tttext::ICanvasHelper* canvas, float x, float y) {
    if (canvas) {
        auto paint = canvas->CreatePaint();
        canvas->DrawRect(x, y, x + width_, y + height_, paint.get());
    }
}

// ============================================================================
// ResourceLoader & EventListener Implementation (0x00d670..0x00e420)
// Triển khai ResourceLoader & EventListener (0x00d670..0x00e420)
// ============================================================================

MarkdownResourceLoader::MarkdownResourceLoader(jobject java_doc) {
    JNIEnv* env = lynx::base::android::AttachCurrentThread();
    weak_java_doc_.ResetNewWeakGlobalRef(env, java_doc);
}

MarkdownResourceLoader::~MarkdownResourceLoader() {
    JNIEnv* env = lynx::base::android::AttachCurrentThread();
    weak_java_doc_.ReleaseWeakGlobalRef(env);
}

int32_t MarkdownResourceLoader::MeasureInlineView(const char* /*id*/, float max_width, float max_height,
                                                  float* out_width, float* out_height, float* out_ascent) {
    if (out_width) *out_width = std::min(64.0f, std::max(16.0f, max_width * 0.25f));
    if (out_height) *out_height = std::min(24.0f, std::max(16.0f, max_height));
    if (out_ascent) *out_ascent = (out_height ? *out_height : 20.0f) * 0.8f;
    return 1;
}

int32_t MarkdownResourceLoader::LoadImage(const char* /*src*/, float max_width, float /*max_height*/,
                                          float style_width, float style_height,
                                          float* out_width, float* out_height) {
    float w = (style_width > 0.0f) ? style_width : std::min(120.0f, std::max(32.0f, max_width * 0.5f));
    float h = (style_height > 0.0f) ? style_height : (w * 0.75f);
    if (out_width) *out_width = w;
    if (out_height) *out_height = h;
    return 1;
}

int32_t MarkdownResourceLoader::LoadFont(const char* /*family*/, int32_t /*weight*/) {
    return 1;
}

int32_t MarkdownResourceLoader::LoadGradient(const char* /*gradient_css*/, float /*width*/, float /*height*/) {
    return 1;
}

MarkdownEventListener::MarkdownEventListener(jobject java_doc) {
    JNIEnv* env = lynx::base::android::AttachCurrentThread();
    weak_java_doc_.ResetNewWeakGlobalRef(env, java_doc);
}

MarkdownEventListener::~MarkdownEventListener() {
    JNIEnv* env = lynx::base::android::AttachCurrentThread();
    weak_java_doc_.ReleaseWeakGlobalRef(env);
}

void MarkdownEventListener::OnTextOverflow(const char* /*ellipsis_str*/) {}

// ============================================================================
// Core Layout, Offset Binary Search, Typewriter & Hit-Testing Implementation
// Triển khai Dàn trang, Tìm kiếm nhị phân Offset, Máy chữ & Kiểm tra va chạm
// ============================================================================

namespace {

const MarkdownBlockStyle& SelectBlockStyle(const MarkdownStyleSheet& sheet, const ParsedBlockNode& block) {
    if (block.type == DiscountBlockType::kHdr) {
        switch (block.heading_level) {
            case 1: return sheet.h1;
            case 2: return sheet.h2;
            case 3: return sheet.h3;
            case 4: return sheet.h4;
            case 5: return sheet.h5;
            case 6: return sheet.h6;
            default: return sheet.h1;
        }
    }
    if (block.type == DiscountBlockType::kCode) return sheet.code_block;
    if (block.type == DiscountBlockType::kQuote) return sheet.quote;
    if (block.type == DiscountBlockType::kUl) return sheet.unordered_list.block;
    if (block.type == DiscountBlockType::kOl) return sheet.ordered_list.block;
    if (block.type == DiscountBlockType::kTable) return sheet.table;
    if (block.type == DiscountBlockType::kHr) return sheet.horizontal_rule;
    return sheet.normal_text;
}

void AppendSpansToParagraph(MarkdownDocument* doc,
                            const std::vector<ParsedInlineSpan>& spans,
                            const ttoffice::tttext::Style& base_style,
                            uint32_t region_idx,
                            uint32_t global_char_base,
                            ttoffice::tttext::Paragraph* para,
                            std::string* page_plain_u8) {
    for (const auto& s : spans) {
        ttoffice::tttext::Style run_style = base_style;
        switch (s.kind) {
            case InlineNodeKind::kBold:
                run_style.bold_ = true;
                run_style.font_weight_ = 700;
                break;
            case InlineNodeKind::kItalic:
                run_style.italic_ = true;
                break;
            case InlineNodeKind::kBoldItalic:
                run_style.bold_ = true;
                run_style.italic_ = true;
                run_style.font_weight_ = 700;
                break;
            case InlineNodeKind::kStrikethrough:
                run_style.decoration_type_ = 2;
                break;
            case InlineNodeKind::kUnderline:
                run_style.decoration_type_ = 1;
                break;
            case InlineNodeKind::kInlineCode:
                run_style.background_color_ = doc->style_.inline_code.background_color
                                                  ? doc->style_.inline_code.background_color
                                                  : 0xFFF2F3F5u;
                if (doc->style_.inline_code.color != 0) {
                    run_style.foreground_color_ = doc->style_.inline_code.color;
                }
                break;
            case InlineNodeKind::kMark:
                run_style.background_color_ = doc->style_.mark.background_color
                                                  ? doc->style_.mark.background_color
                                                  : 0xFFFFF3A8u;
                break;
            case InlineNodeKind::kDoubleBraces:
                if (doc->style_.double_braces.color != 0) {
                    run_style.foreground_color_ = doc->style_.double_braces.color;
                }
                break;
            case InlineNodeKind::kLink: {
                run_style.foreground_color_ = doc->style_.link.color ? doc->style_.link.color : 0xFF165DFFu;
                run_style.decoration_type_ = 1;
                uint32_t local_start = para->GetCharCount();
                para->AddTextRun(&run_style, s.text.c_str(), static_cast<uint32_t>(s.text.size()));
                uint32_t local_end = para->GetCharCount();
                page_plain_u8->append(s.text);

                MarkdownLink link;
                link.url = s.url;
                link.content = s.text;
                link.char_start = global_char_base + local_start;
                link.char_count = local_end - local_start;
                link.attached_region_idx = region_idx;
                link.char_offset_in_region = local_start;
                doc->links_.push_back(std::move(link));

                doc->offset_map_.push_back(MarkdownOffsetRange{
                    s.md_start, s.md_end,
                    static_cast<int32_t>(global_char_base + local_start),
                    static_cast<int32_t>(global_char_base + local_end)
                });
                continue;
            }
            case InlineNodeKind::kImage: {
                float img_w = (s.width > 0.0f) ? s.width : 120.0f;
                float img_h = (s.height > 0.0f) ? s.height : 90.0f;
                if (doc->resource_loader_) {
                    doc->resource_loader_->LoadImage(s.url.c_str(), 400.0f, 400.0f,
                                                     s.width, s.height, &img_w, &img_h);
                }
                uint32_t local_start = para->GetCharCount();
                auto delegate = std::make_shared<ImageRunDelegate>(
                    s.url, static_cast<int32_t>(doc->images_.size()), img_w, img_h);
                doc->inline_delegates_.push_back(delegate);
                para->AddShapeRun(&run_style, delegate, false);
                uint32_t local_end = para->GetCharCount();
                page_plain_u8->append("\xEF\xBF\xBC");

                MarkdownImage img;
                img.url = s.url;
                img.char_index = global_char_base + local_start;
                img.width = img_w;
                img.height = img_h;
                doc->images_.push_back(std::move(img));

                doc->offset_map_.push_back(MarkdownOffsetRange{
                    s.md_start, s.md_end,
                    static_cast<int32_t>(global_char_base + local_start),
                    static_cast<int32_t>(global_char_base + local_end)
                });
                continue;
            }
            case InlineNodeKind::kInlineView: {
                float vw = (s.width > 0.0f) ? s.width : 48.0f;
                float vh = (s.height > 0.0f) ? s.height : 22.0f;
                float vascent = vh * 0.8f;
                if (doc->resource_loader_) {
                    doc->resource_loader_->MeasureInlineView(s.url.c_str(), 400.0f, 400.0f, &vw, &vh, &vascent);
                }
                uint32_t local_start = para->GetCharCount();
                auto delegate = std::make_shared<InlineViewRunDelegate>(
                    s.url, vw, vh, vascent, vh - vascent);
                doc->inline_delegates_.push_back(delegate);
                para->AddShapeRun(&run_style, delegate, false);
                uint32_t local_end = para->GetCharCount();
                page_plain_u8->append("\xEF\xBF\xBC");

                MarkdownInlineView iv;
                iv.id = s.url;
                iv.char_index = global_char_base + local_start;
                iv.is_block_view = false;
                iv.width = vw;
                iv.height = vh;
                iv.ascent = vascent;
                iv.descent = vh - vascent;
                doc->inline_views_[s.url] = iv;

                doc->offset_map_.push_back(MarkdownOffsetRange{
                    s.md_start, s.md_end,
                    static_cast<int32_t>(global_char_base + local_start),
                    static_cast<int32_t>(global_char_base + local_end)
                });
                continue;
            }
            default:
                break;
        }

        uint32_t local_start = para->GetCharCount();
        para->AddTextRun(&run_style, s.text.c_str(), static_cast<uint32_t>(s.text.size()));
        uint32_t local_end = para->GetCharCount();
        page_plain_u8->append(s.text);

        doc->offset_map_.push_back(MarkdownOffsetRange{
            s.md_start, s.md_end,
            static_cast<int32_t>(global_char_base + local_start),
            static_cast<int32_t>(global_char_base + local_end)
        });
    }
}

void DrawExtraContentItem(ttoffice::tttext::ICanvasHelper* canvas, const MarkdownExtraContent& extra) {
    if (!canvas) return;
    auto paint = canvas->CreatePaint();
    paint->color_ = extra.color;
    paint->stroke_width_ = std::max(1.0f, extra.border_width);

    switch (extra.kind) {
        case ExtraContentKind::kQuoteBorder:
            paint->fill_style_ = 0;
            canvas->DrawRect(extra.rect.left, extra.rect.top, extra.rect.right, extra.rect.bottom, paint.get());
            break;
        case ExtraContentKind::kCodeBlockBackground:
        case ExtraContentKind::kTableBackground:
            paint->fill_style_ = 0;
            if (extra.border_radius > 0.0f) {
                canvas->DrawRoundRect(extra.rect.left, extra.rect.top, extra.rect.right, extra.rect.bottom,
                                      extra.border_radius, paint.get());
            } else {
                canvas->DrawRect(extra.rect.left, extra.rect.top, extra.rect.right, extra.rect.bottom, paint.get());
            }
            break;
        case ExtraContentKind::kTableBorder:
            paint->color_ = extra.border_color;
            paint->fill_style_ = 1; // stroke
            canvas->DrawRect(extra.rect.left, extra.rect.top, extra.rect.right, extra.rect.bottom, paint.get());
            for (const auto& cell : extra.cell_rects) {
                canvas->DrawRect(cell.left, cell.top, cell.right, cell.bottom, paint.get());
            }
            break;
        case ExtraContentKind::kHorizontalRule:
            canvas->DrawLine(extra.rect.left, extra.rect.top, extra.rect.right, extra.rect.top, paint.get());
            break;
        case ExtraContentKind::kListMarker:
            if (!extra.marker_text.empty()) {
                canvas->DrawText(extra.marker_text.c_str(), static_cast<uint32_t>(extra.marker_text.size()),
                                 extra.rect.left, extra.rect.bottom, paint.get());
            } else {
                float cx = 0.5f * (extra.rect.left + extra.rect.right);
                float cy = 0.5f * (extra.rect.top + extra.rect.bottom);
                float r = std::max(2.0f, 0.5f * extra.rect.Width());
                canvas->DrawCircle(cx, cy, r, paint.get());
            }
            break;
    }
}

} // anonymous namespace

/**
 * @brief Perform full layout of `MarkdownDocument` (`nativeLayout` @ 0x0102a0)
 *        Thực hiện dàn trang toàn bộ `MarkdownDocument` (`nativeLayout` @ 0x0102a0)
 */
int64_t LayoutMarkdownDocument(MarkdownDocument* doc,
                               float max_width,
                               float max_height,
                               int32_t /*typewriter_step*/) {
    if (!doc) return 0;

    std::vector<ParsedBlockNode> blocks;
    ParseMarkdownDocument(doc,
                          doc->raw_markdown_.c_str(),
                          doc->raw_markdown_.size(),
                          doc->parse_start_offset_,
                          doc->parse_end_offset_,
                          doc->style_.root_font_scale,
                          &blocks);

    auto page = std::make_shared<MarkdownPage>();
    const float avail_w = (max_width > 0.0f) ? max_width : 360.0f;
    const float avail_h = (max_height > 0.0f) ? max_height : 100000.0f;

    ttoffice::tttext::TextLayout text_layout(doc->font_collection_.get(),
                                             ttoffice::tttext::ShaperType::kSystem);

    float cursor_y = 0.0f;
    float max_laid_w = 0.0f;
    uint32_t global_char_cursor = 0;

    auto layout_single_paragraph_block = [&](const ParsedBlockNode& block,
                                             const MarkdownBlockStyle& bstyle,
                                             float extra_left_indent,
                                             const std::string& list_marker_prefix,
                                             bool is_unordered_marker) {
        cursor_y += bstyle.margin_top;
        float content_left = bstyle.margin_left + bstyle.padding_left + extra_left_indent;
        float content_w = std::max(32.0f, avail_w - content_left - bstyle.margin_right - bstyle.padding_right);

        auto para = ttoffice::tttext::Paragraph::Create();
        ttoffice::tttext::ParagraphStyle pstyle;
        pstyle.default_style_.font_family_ = bstyle.font_family;
        pstyle.default_style_.text_size_ = bstyle.font_size * doc->style_.root_font_scale;
        pstyle.default_style_.foreground_color_ = bstyle.color;
        pstyle.default_style_.font_weight_ = bstyle.font_weight;
        pstyle.default_style_.bold_ = (bstyle.font_weight >= 600) || (block.type == DiscountBlockType::kHdr);
        if (bstyle.line_height > 0.0f) {
            pstyle.SetLineHeightInPx(bstyle.line_height, ttoffice::tttext::RulerType::kExact);
        }
        pstyle.SetLineSpaceAfterPx(bstyle.line_space);
        pstyle.SetFirstLineIndentInPx(bstyle.text_indent);
        pstyle.AllowBreakAroundPunctuation(doc->allow_break_around_punctuation_);
        pstyle.max_lines_ = bstyle.text_maxline;
        para->SetParagraphStyle(&pstyle);

        uint32_t reg_idx = static_cast<uint32_t>(page->regions.size());
        AppendSpansToParagraph(doc, block.spans, pstyle.default_style_, reg_idx,
                               global_char_cursor, para.get(), &page->plain_utf8_text);

        auto lregion = std::make_unique<ttoffice::tttext::LayoutRegion>(
            content_w, avail_h, ttoffice::tttext::LayoutMode::kDefinite,
            ttoffice::tttext::LayoutMode::kIndefinite);
        ttoffice::tttext::TTTextContext ctx;
        text_layout.LayoutEx(para.get(), lregion.get(), ctx);
        if (ctx.overflowed_) {
            page->is_overflowed = true;
            if (doc->event_listener_) {
                doc->event_listener_->OnTextOverflow(doc->style_.truncation.content.c_str());
            }
        }

        float reg_h = std::max(bstyle.min_height, lregion->layouted_height_);
        float reg_w = std::max(lregion->layouted_width_, content_w);

        auto mregion = std::make_unique<MarkdownRegion>();
        mregion->block_type = 0;
        mregion->char_start = global_char_cursor;
        mregion->char_end = global_char_cursor + para->GetCharCount();
        mregion->padding_rect = RectF{content_left, cursor_y + bstyle.padding_top,
                                      content_left + reg_w, cursor_y + bstyle.padding_top + reg_h};
        mregion->border_rect = RectF{bstyle.margin_left + extra_left_indent,
                                     cursor_y,
                                     content_left + reg_w + bstyle.padding_right,
                                     cursor_y + bstyle.padding_top + reg_h + bstyle.padding_bottom};
        mregion->scroll_x = (block.type == DiscountBlockType::kCode);

        // Record inline view / image origins from laid-out region
        for (auto& img : doc->images_) {
            if (img.char_index >= mregion->char_start && img.char_index < mregion->char_end) {
                img.rect = RectF{mregion->padding_rect.left, mregion->padding_rect.top,
                                 mregion->padding_rect.left + img.width,
                                 mregion->padding_rect.top + img.height};
            }
        }
        for (auto& kv : doc->inline_views_) {
            if (kv.second.char_index >= mregion->char_start && kv.second.char_index < mregion->char_end) {
                kv.second.origin_rect = RectF{mregion->padding_rect.left, mregion->padding_rect.top,
                                              mregion->padding_rect.left + kv.second.width,
                                              mregion->padding_rect.top + kv.second.height};
            }
        }

        // Extra content for quote vertical border, code block background, or list marker
        if (block.type == DiscountBlockType::kQuote) {
            auto extra = std::make_unique<MarkdownExtraContent>();
            extra->kind = ExtraContentKind::kQuoteBorder;
            extra->rect = RectF{mregion->border_rect.left, mregion->border_rect.top,
                                mregion->border_rect.left + 4.0f, mregion->border_rect.bottom};
            extra->color = doc->style_.quote_border_line.color ? doc->style_.quote_border_line.color : 0xFFCCCCCCu;
            extra->char_start = mregion->char_start;
            extra->char_end = mregion->char_end;
            page->extra_contents.push_back(std::move(extra));
        } else if (block.type == DiscountBlockType::kCode) {
            auto extra = std::make_unique<MarkdownExtraContent>();
            extra->kind = ExtraContentKind::kCodeBlockBackground;
            extra->rect = mregion->border_rect;
            extra->color = bstyle.background_color ? bstyle.background_color : 0xFFF7F8FAu;
            extra->border_radius = bstyle.border_radius > 0.0f ? bstyle.border_radius : 6.0f;
            extra->char_start = mregion->char_start;
            extra->char_end = mregion->char_end;
            page->extra_contents.push_back(std::move(extra));
        } else if (block.type == DiscountBlockType::kListItem) {
            auto extra = std::make_unique<MarkdownExtraContent>();
            extra->kind = ExtraContentKind::kListMarker;
            extra->marker_text = list_marker_prefix;
            float marker_x = std::max(0.0f, content_left - 16.0f);
            float marker_y = mregion->padding_rect.top + 6.0f;
            extra->rect = RectF{marker_x, marker_y,
                                marker_x + (is_unordered_marker ? 6.0f : 14.0f),
                                marker_y + (is_unordered_marker ? 6.0f : 14.0f)};
            extra->color = is_unordered_marker ? doc->style_.unordered_list.mark_color
                                               : doc->style_.ordered_list.number_color;
            extra->char_start = mregion->char_start;
            extra->char_end = mregion->char_end;
            page->extra_contents.push_back(std::move(extra));
        }

        global_char_cursor = mregion->char_end;
        cursor_y = mregion->border_rect.bottom + bstyle.margin_bottom + bstyle.paragraph_space;
        max_laid_w = std::max(max_laid_w, mregion->border_rect.right);

        mregion->paragraph = std::move(para);
        mregion->layout_region = std::move(lregion);
        page->regions.push_back(std::move(mregion));
    };

    for (const auto& block : blocks) {
        if (!block.block_view_id.empty()) {
            float bw = avail_w;
            float bh = 40.0f;
            float bascent = 32.0f;
            if (doc->resource_loader_) {
                doc->resource_loader_->MeasureInlineView(block.block_view_id.c_str(), avail_w, avail_h, &bw, &bh, &bascent);
            }
            MarkdownInlineView bv;
            bv.id = block.block_view_id;
            bv.char_index = global_char_cursor;
            bv.is_block_view = true;
            bv.width = bw;
            bv.height = bh;
            bv.origin_rect = RectF{0.0f, cursor_y, bw, cursor_y + bh};
            doc->inline_views_[block.block_view_id] = bv;
            cursor_y += bh + 8.0f;
            max_laid_w = std::max(max_laid_w, bw);
            continue;
        }

        if (block.type == DiscountBlockType::kHr) {
            auto extra = std::make_unique<MarkdownExtraContent>();
            extra->kind = ExtraContentKind::kHorizontalRule;
            extra->rect = RectF{0.0f, cursor_y + 6.0f, avail_w, cursor_y + 7.0f};
            extra->color = doc->style_.horizontal_rule.color ? doc->style_.horizontal_rule.color : 0xFFE5E6EBu;
            extra->border_width = std::max(1.0f, doc->style_.horizontal_rule.border_width);
            extra->char_start = global_char_cursor;
            extra->char_end = global_char_cursor;
            page->extra_contents.push_back(std::move(extra));
            cursor_y += 14.0f;
            max_laid_w = std::max(max_laid_w, avail_w);
            continue;
        }

        if (block.type == DiscountBlockType::kUl || block.type == DiscountBlockType::kOl) {
            bool is_ul = (block.type == DiscountBlockType::kUl);
            const MarkdownBlockStyle& lstyle = is_ul ? doc->style_.unordered_list.block
                                                     : doc->style_.ordered_list.block;
            for (const auto& item : block.children) {
                float indent = 20.0f + item.list_depth * 16.0f;
                std::string marker;
                if (!is_ul) {
                    if (doc->style_.ordered_list.number_type == MarkdownNumberType::kRomanNumerals) {
                        marker = FormatRomanNumeral(item.list_index) + ".";
                    } else {
                        marker = std::to_string(item.list_index) + ".";
                    }
                }
                layout_single_paragraph_block(item, lstyle, indent, marker, is_ul);
            }
            continue;
        }

        if (block.type == DiscountBlockType::kTable && !block.table_rows.empty()) {
            const size_t num_rows = block.table_rows.size();
            const size_t num_cols = block.table_rows[0].size();
            const float col_w = std::max(40.0f, avail_w / static_cast<float>(std::max<size_t>(1, num_cols)));

            auto tregion = std::make_unique<MarkdownRegion>();
            tregion->block_type = 1; // 1 = Table (`cmp w9, #1` in `nativeGetPageCharCount` @ 0x014248)
            tregion->scroll_x = true;
            tregion->char_start = global_char_cursor;

            auto grid_extra = std::make_unique<MarkdownExtraContent>();
            grid_extra->kind = ExtraContentKind::kTableBorder;
            grid_extra->border_color = doc->style_.table_border.color ? doc->style_.table_border.color : 0xFFD9D9D9u;
            grid_extra->border_width = std::max(1.0f, doc->style_.table_border.border_width);
            grid_extra->char_start = global_char_cursor;

            float table_top = cursor_y;
            for (size_t r = 0; r < num_rows; ++r) {
                std::vector<std::unique_ptr<ttoffice::tttext::LayoutRegion>> row_regions;
                float row_h = 24.0f;
                for (size_t c = 0; c < num_cols; ++c) {
                    const auto& cell = block.table_rows[r][c];
                    const MarkdownBlockStyle& cstyle = cell.is_header ? doc->style_.table_header : doc->style_.table_cell;
                    auto cpara = ttoffice::tttext::Paragraph::Create();
                    ttoffice::tttext::ParagraphStyle cpstyle;
                    cpstyle.default_style_.font_family_ = cstyle.font_family;
                    cpstyle.default_style_.text_size_ = cstyle.font_size * doc->style_.root_font_scale;
                    cpstyle.default_style_.bold_ = cell.is_header;
                    cpara->SetParagraphStyle(&cpstyle);

                    uint32_t reg_idx = static_cast<uint32_t>(page->regions.size());
                    AppendSpansToParagraph(doc, cell.spans, cpstyle.default_style_, reg_idx,
                                           global_char_cursor, cpara.get(), &page->plain_utf8_text);

                    auto clreg = std::make_unique<ttoffice::tttext::LayoutRegion>(
                        col_w - 8.0f, avail_h, ttoffice::tttext::LayoutMode::kDefinite,
                        ttoffice::tttext::LayoutMode::kIndefinite);
                    ttoffice::tttext::TTTextContext cctx;
                    text_layout.LayoutEx(cpara.get(), clreg.get(), cctx);
                    row_h = std::max(row_h, clreg->layouted_height_ + 8.0f);

                    global_char_cursor += cpara->GetCharCount();
                    tregion->table_cell_char_counts.push_back(global_char_cursor);
                    if (!tregion->paragraph) {
                        tregion->paragraph = std::move(cpara);
                    }
                    row_regions.push_back(std::move(clreg));

                    RectF cell_rect{static_cast<float>(c) * col_w, cursor_y,
                                    static_cast<float>(c + 1) * col_w, cursor_y + row_h};
                    grid_extra->cell_rects.push_back(cell_rect);
                }
                tregion->table_cells.push_back(std::move(row_regions));
                cursor_y += row_h;
            }

            tregion->char_end = global_char_cursor;
            tregion->padding_rect = RectF{0.0f, table_top, num_cols * col_w, cursor_y};
            tregion->border_rect = tregion->padding_rect;
            grid_extra->rect = tregion->border_rect;
            grid_extra->char_end = global_char_cursor;
            page->extra_contents.push_back(std::move(grid_extra));
            page->regions.push_back(std::move(tregion));
            max_laid_w = std::max(max_laid_w, num_cols * col_w);
            cursor_y += 8.0f;
            continue;
        }

        const MarkdownBlockStyle& bstyle = SelectBlockStyle(doc->style_, block);
        float quote_indent = (block.type == DiscountBlockType::kQuote) ? 12.0f : 0.0f;
        layout_single_paragraph_block(block, bstyle, quote_indent, "", false);
    }

    // Sort `offset_map_` by `md_start` for binary search in `nativeMarkdownOffsetToChar` (`0x0142d4`)
    std::sort(doc->offset_map_.begin(), doc->offset_map_.end(),
              [](const MarkdownOffsetRange& a, const MarkdownOffsetRange& b) {
                  return a.md_start < b.md_start;
              });

    // Update syntax ranges with character positions using `ConvertMarkdownOffsetToChar`
    for (auto& sr : doc->syntax_ranges_) {
        sr.char_start = ConvertMarkdownOffsetToChar(doc, sr.md_start);
        sr.char_end = ConvertMarkdownOffsetToChar(doc, sr.md_end);
    }

    page->layout_width = max_laid_w;
    page->layout_height = cursor_y;
    page->total_char_count = global_char_cursor;
    page->plain_u16_text = lynx::base::U8StringToU16(page->plain_utf8_text);

    // Compute rects for any pending text mark attachments (`nativeAddTextMarkAttachment`)
    for (const auto& pending : doc->pending_attachments_) {
        auto att = std::make_unique<MarkdownTextAttachment>(pending);
        int32_t c_start = att->is_markdown_offset
                              ? ConvertMarkdownOffsetToChar(doc, att->start_pos)
                              : att->start_pos;
        int32_t c_end = att->is_markdown_offset
                            ? ConvertMarkdownOffsetToChar(doc, att->end_pos)
                            : att->end_pos;
        att->rects = ComputeSelectionRectsByCharRange(page.get(), c_start, c_end);
        page->attachments.push_back(std::move(att));
    }

    {
        std::lock_guard<std::mutex> lock(doc->page_mutex_);
        doc->current_page_ = page;
    }

    uint32_t w_bits = 0;
    uint32_t h_bits = 0;
    std::memcpy(&w_bits, &max_laid_w, sizeof(uint32_t));
    std::memcpy(&h_bits, &cursor_y, sizeof(uint32_t));
    return (static_cast<int64_t>(w_bits) << 32) | static_cast<int64_t>(h_bits);
}

/**
 * @brief Exact AArch64 binary search matching `nativeMarkdownOffsetToChar` (`0x0142d4..0x014354`)
 *        Tìm kiếm nhị phân AArch64 khớp chính xác `nativeMarkdownOffsetToChar` (`0x0142d4..0x014354`)
 *
 * Disassembly verification (`0x0142d4..0x014354`):
 *   - Loads `begin = doc->offset_map_.begin()` (`[x2, #0xe58]`) and `end = doc->offset_map_.end()` (`[x2, #0xe60]`).
 *   - `count = (end - begin) >> 4` (`asr x10, x10, #4` — 16-byte `MarkdownOffsetRange` elements).
 *   - Binary search loop (`std::lower_bound` on `entry.md_end < markdown_offset` at `+0x04`):
 *     `ldr w13, [x12, #4]; cmp w13, w3; csel x8, x12, x8, le`.
 *   - If `it == end`: returns `end[-1].char_end` (`ldur w0, [x9, #-4]` @ `0x01432c`).
 *   - If `it->md_start > markdown_offset`: returns `it->char_start` (`ldr w0, [x8, #8]` @ `0x014324`).
 *   - If `it->md_end < markdown_offset`: returns `it->char_end` (`ldr w0, [x8, #0xc]` @ `0x014340`).
 *   - Otherwise (`md_start <= markdown_offset <= md_end`): returns `std::min(it->char_end, it->char_start + (markdown_offset - it->md_start))` (`0x014348..0x014354`).
 */
int32_t ConvertMarkdownOffsetToChar(const MarkdownDocument* doc, int32_t markdown_offset) {
    if (!doc || doc->offset_map_.empty()) {
        return 0;
    }
    const MarkdownOffsetRange* begin = doc->offset_map_.data();
    const MarkdownOffsetRange* end = begin + doc->offset_map_.size();

    // Binary search (`0x0142e4..0x01430c`)
    const MarkdownOffsetRange* cur = begin;
    size_t count = static_cast<size_t>(end - begin);
    while (count > 0) {
        size_t half = count >> 1;
        const MarkdownOffsetRange* mid = cur + half;
        if (mid->md_end <= markdown_offset) {
            cur = mid + 1;
            count = count - half - 1;
        } else {
            count = half;
        }
    }

    if (cur == end) {
        return (end - 1)->char_end; // 0x01432c: ldur w0, [x9, #-4]
    }
    if (cur->md_start > markdown_offset) {
        return cur->char_start;    // 0x014324: ldr w0, [x8, #8]
    }
    if (cur->md_end < markdown_offset) {
        return cur->char_end;      // 0x014340: ldr w0, [x8, #0xc]
    }
    int32_t interpolated = cur->char_start + (markdown_offset - cur->md_start);
    return std::min(cur->char_end, interpolated);
}

void ComputeTypewriterCursorPosition(MarkdownDocument* doc,
                                     int32_t char_count,
                                     bool /*is_custom_cursor*/,
                                     float out_xyh[3]) {
    out_xyh[0] = 0.0f;
    out_xyh[1] = 0.0f;
    out_xyh[2] = 0.0f;
    if (!doc) return;

    std::shared_ptr<MarkdownPage> page;
    {
        std::lock_guard<std::mutex> lock(doc->page_mutex_);
        page = doc->current_page_;
    }
    if (!page || page->regions.empty()) return;

    int32_t target_char = (char_count < 0)
                              ? static_cast<int32_t>(page->total_char_count)
                              : std::min(char_count, static_cast<int32_t>(page->total_char_count));

    for (const auto& reg : page->regions) {
        if (!reg || !reg->layout_region) continue;
        if (target_char <= static_cast<int32_t>(reg->char_end) || &reg == &page->regions.back()) {
            uint32_t local_char = (target_char > static_cast<int32_t>(reg->char_start))
                                      ? static_cast<uint32_t>(target_char - reg->char_start)
                                      : 0u;
            ttoffice::tttext::LayoutRegion* lreg = reg->layout_region.get();
            for (uint32_t li = 0; li < lreg->GetLineCount(); ++li) {
                ttoffice::tttext::TextLine* line = lreg->GetLine(li);
                if (!line) continue;
                if (local_char <= line->end_char_pos_ || li + 1 == lreg->GetLineCount()) {
                    float x = reg->padding_rect.left + line->line_left_;
                    uint32_t steps = std::min(local_char, line->end_char_pos_) - line->start_char_pos_;
                    for (uint32_t k = 0; k < steps && k < line->char_advances_.size(); ++k) {
                        x += line->char_advances_[k];
                    }
                    out_xyh[0] = x + doc->style_.typewriter_cursor.offset_x;
                    out_xyh[1] = reg->padding_rect.top + line->line_top_ + doc->style_.typewriter_cursor.offset_y;
                    out_xyh[2] = line->line_bottom_ - line->line_top_;
                    return;
                }
            }
        }
    }
}

std::vector<uint8_t> DrawMarkdownPageToBuffer(MarkdownDocument* doc) {
    return DrawMarkdownPageWithCursorToBuffer(doc, -1, false);
}

std::vector<uint8_t> DrawMarkdownPageWithCursorToBuffer(MarkdownDocument* doc,
                                                        int32_t char_count,
                                                        bool show_cursor) {
    if (!doc) return {};
    std::shared_ptr<MarkdownPage> page;
    {
        std::lock_guard<std::mutex> lock(doc->page_mutex_);
        page = doc->current_page_;
    }
    if (!page) return {};

    BufferCanvasHelper canvas(0x400);
    ttoffice::tttext::LayoutDrawer drawer(&canvas);
    uint32_t max_chars = (char_count < 0) ? page->total_char_count : static_cast<uint32_t>(char_count);

    // Draw visible extra contents first (backgrounds, quote bars, borders)
    for (const auto& extra : page->extra_contents) {
        if (extra && extra->char_start <= max_chars) {
            DrawExtraContentItem(&canvas, *extra);
        }
    }

    // Draw text mark attachments (highlights/underlines)
    for (const auto& att : page->attachments) {
        if (!att) continue;
        auto paint = canvas.CreatePaint();
        paint->color_ = att->style.background_color ? att->style.background_color : 0x66FFE58Fu;
        for (const auto& r : att->rects) {
            canvas.DrawRect(r.left, r.top, r.right, r.bottom, paint.get());
        }
    }

    // Draw regions up to `max_chars`
    for (const auto& reg : page->regions) {
        if (!reg || reg->char_start >= max_chars) break;
        if (!reg->layout_region) continue;
        canvas.Save();
        canvas.Translate(reg->padding_rect.left - reg->scroll_offset_x, reg->padding_rect.top);
        uint32_t local_limit = max_chars - reg->char_start;
        for (uint32_t li = 0; li < reg->layout_region->GetLineCount(); ++li) {
            ttoffice::tttext::TextLine* line = reg->layout_region->GetLine(li);
            if (!line || line->start_char_pos_ >= local_limit) break;
            drawer.DrawTextLine(line, line->start_char_pos_, std::min(line->end_char_pos_, local_limit));
        }
        canvas.Restore();
    }

    if (show_cursor) {
        float xyh[3] = {0.0f, 0.0f, 0.0f};
        ComputeTypewriterCursorPosition(doc, char_count, false, xyh);
        if (xyh[2] > 0.0f) {
            auto cpaint = canvas.CreatePaint();
            cpaint->color_ = doc->style_.normal_text.color;
            cpaint->stroke_width_ = 2.0f;
            canvas.DrawLine(xyh[0], xyh[1], xyh[0], xyh[1] + xyh[2], cpaint.get());
        }
    }

    return std::vector<uint8_t>(canvas.Data(), canvas.Data() + canvas.Size());
}

std::vector<uint8_t> DrawSingleRegionToBuffer(MarkdownDocument* doc, int32_t region_index) {
    return DrawTypewriterRegionToBuffer(doc, region_index, -1, false);
}

std::vector<uint8_t> DrawTypewriterRegionToBuffer(MarkdownDocument* doc,
                                                  int32_t region_index,
                                                  int32_t char_count,
                                                  bool show_cursor) {
    if (!doc || region_index < 0) return {};
    std::shared_ptr<MarkdownPage> page;
    {
        std::lock_guard<std::mutex> lock(doc->page_mutex_);
        page = doc->current_page_;
    }
    if (!page || static_cast<size_t>(region_index) >= page->regions.size()) return {};

    const auto& reg = page->regions[static_cast<size_t>(region_index)];
    if (!reg || !reg->layout_region) return {};

    BufferCanvasHelper canvas(0x400);
    ttoffice::tttext::LayoutDrawer drawer(&canvas);
    uint32_t max_chars = (char_count < 0) ? page->total_char_count : static_cast<uint32_t>(char_count);
    if (max_chars <= reg->char_start) return {};

    uint32_t local_limit = max_chars - reg->char_start;
    canvas.Save();
    canvas.Translate(reg->padding_rect.left - reg->scroll_offset_x, reg->padding_rect.top);
    for (uint32_t li = 0; li < reg->layout_region->GetLineCount(); ++li) {
        ttoffice::tttext::TextLine* line = reg->layout_region->GetLine(li);
        if (!line || line->start_char_pos_ >= local_limit) break;
        drawer.DrawTextLine(line, line->start_char_pos_, std::min(line->end_char_pos_, local_limit));
    }
    canvas.Restore();

    if (show_cursor && max_chars <= reg->char_end) {
        float xyh[3] = {0.0f, 0.0f, 0.0f};
        ComputeTypewriterCursorPosition(doc, char_count, false, xyh);
        if (xyh[2] > 0.0f) {
            auto cpaint = canvas.CreatePaint();
            cpaint->color_ = doc->style_.normal_text.color;
            cpaint->stroke_width_ = 2.0f;
            canvas.DrawLine(xyh[0], xyh[1], xyh[0], xyh[1] + xyh[2], cpaint.get());
        }
    }

    return std::vector<uint8_t>(canvas.Data(), canvas.Data() + canvas.Size());
}

std::vector<uint8_t> DrawSingleExtraContentToBuffer(MarkdownDocument* doc, int32_t extra_index) {
    if (!doc || extra_index < 0) return {};
    std::shared_ptr<MarkdownPage> page;
    {
        std::lock_guard<std::mutex> lock(doc->page_mutex_);
        page = doc->current_page_;
    }
    if (!page || static_cast<size_t>(extra_index) >= page->extra_contents.size()) return {};

    const auto& extra = page->extra_contents[static_cast<size_t>(extra_index)];
    if (!extra) return {};

    BufferCanvasHelper canvas(0x400);
    DrawExtraContentItem(&canvas, *extra);
    return std::vector<uint8_t>(canvas.Data(), canvas.Data() + canvas.Size());
}

std::vector<RectF> ComputeSelectionRectsByCharRange(const MarkdownPage* page,
                                                    int32_t char_start,
                                                    int32_t char_end) {
    std::vector<RectF> rects;
    if (!page || char_start >= char_end) return rects;
    uint32_t req_start = static_cast<uint32_t>(std::max(0, char_start));
    uint32_t req_end = static_cast<uint32_t>(std::max(0, char_end));

    for (const auto& reg : page->regions) {
        if (!reg || !reg->layout_region) continue;
        if (req_end <= reg->char_start || req_start >= reg->char_end) continue;
        uint32_t local_s = (req_start > reg->char_start) ? (req_start - reg->char_start) : 0u;
        uint32_t local_e = std::min(req_end - reg->char_start, reg->char_end - reg->char_start);

        ttoffice::tttext::LayoutRegion* lreg = reg->layout_region.get();
        for (uint32_t li = 0; li < lreg->GetLineCount(); ++li) {
            ttoffice::tttext::TextLine* line = lreg->GetLine(li);
            if (!line) continue;
            uint32_t ls = std::max(local_s, line->start_char_pos_);
            uint32_t le = std::min(local_e, line->end_char_pos_);
            if (ls >= le) continue;

            float x1 = reg->padding_rect.left + line->line_left_;
            for (uint32_t c = line->start_char_pos_; c < ls; ++c) {
                uint32_t rel = c - line->start_char_pos_;
                if (rel < line->char_advances_.size()) x1 += line->char_advances_[rel];
            }
            float x2 = x1;
            for (uint32_t c = ls; c < le; ++c) {
                uint32_t rel = c - line->start_char_pos_;
                if (rel < line->char_advances_.size()) x2 += line->char_advances_[rel];
            }
            rects.push_back(RectF{x1, reg->padding_rect.top + line->line_top_,
                                  x2, reg->padding_rect.top + line->line_bottom_});
        }
    }
    return rects;
}

/**
 * @brief Hit-test character index and expand by split type (`nativeGetCharRangeByPoint` @ 0x0140bc)
 *        Kiểm tra va chạm tìm chỉ số ký tự và mở rộng theo kiểu tách (`nativeGetCharRangeByPoint` @ 0x0140bc)
 *        Sentence delimiters at `.rodata 0x005a42..0x005a4b` (`.data.rel.ro 0x0388f8..0x038928`):
 *        `". "`, `"? "`, `"! "`, `"; "` plus CJK punctuation `。`, `？`, `！`, `；`.
 */
void ComputeCharRangeByPoint(const MarkdownPage* page,
                             float touch_x,
                             float touch_y,
                             int32_t split_type,
                             int32_t out_range[2]) {
    out_range[0] = -1;
    out_range[1] = -1;
    if (!page || page->regions.empty()) return;

    int32_t hit_char = -1;
    int32_t para_start = 0;
    int32_t para_end = static_cast<int32_t>(page->total_char_count);

    for (const auto& reg : page->regions) {
        if (!reg || !reg->layout_region) continue;
        if (touch_y >= reg->border_rect.top && touch_y <= reg->border_rect.bottom) {
            para_start = static_cast<int32_t>(reg->char_start);
            para_end = static_cast<int32_t>(reg->char_end);
            ttoffice::tttext::LayoutRegion* lreg = reg->layout_region.get();
            for (uint32_t li = 0; li < lreg->GetLineCount(); ++li) {
                ttoffice::tttext::TextLine* line = lreg->GetLine(li);
                if (!line) continue;
                float top = reg->padding_rect.top + line->line_top_;
                float bottom = reg->padding_rect.top + line->line_bottom_;
                if (touch_y >= top && touch_y <= bottom) {
                    float cur_x = reg->padding_rect.left + line->line_left_;
                    hit_char = static_cast<int32_t>(reg->char_start + line->start_char_pos_);
                    for (uint32_t k = 0; k < line->char_advances_.size(); ++k) {
                        float next_x = cur_x + line->char_advances_[k];
                        if (touch_x <= next_x) {
                            hit_char = static_cast<int32_t>(reg->char_start + line->start_char_pos_ + k);
                            break;
                        }
                        cur_x = next_x;
                        hit_char = static_cast<int32_t>(reg->char_start + line->start_char_pos_ + k);
                    }
                    break;
                }
            }
            break;
        }
    }

    if (hit_char < 0 || hit_char >= static_cast<int32_t>(page->plain_u16_text.size())) {
        return;
    }

    const std::u16string& u16 = page->plain_u16_text;
    const int32_t n = static_cast<int32_t>(u16.size());

    if (split_type == 0) { // Single character
        out_range[0] = hit_char;
        out_range[1] = std::min(n, hit_char + 1);
        return;
    }
    if (split_type == 3) { // Paragraph
        out_range[0] = para_start;
        out_range[1] = para_end;
        return;
    }
    if (split_type == 1) { // Word
        int32_t s = hit_char;
        int32_t e = hit_char + 1;
        auto is_word_ch = [](char16_t c) {
            return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
                   (c >= '0' && c <= '9') || c == '_' || c >= 0x00C0u;
        };
        while (s > para_start && is_word_ch(u16[s - 1])) --s;
        while (e < para_end && is_word_ch(u16[e])) ++e;
        out_range[0] = s;
        out_range[1] = e;
        return;
    }

    // Sentence split (`split_type == 2`, delimiters `. `, `? `, `! `, `; ` @ `0x005a42..0x005a4b`)
    auto is_sentence_break = [&](int32_t idx) {
        char16_t c = u16[idx];
        if (c == 0x3002u || c == 0xFF01u || c == 0xFF1Fu || c == 0xFF1Bu || c == '\n') {
            return true;
        }
        if ((c == '.' || c == '?' || c == '!' || c == ';') &&
            (idx + 1 >= n || u16[idx + 1] == ' ' || u16[idx + 1] == '\n')) {
            return true;
        }
        return false;
    };

    int32_t s = hit_char;
    while (s > para_start && !is_sentence_break(s - 1)) --s;
    while (s < hit_char && u16[s] == ' ') ++s;

    int32_t e = hit_char + 1;
    while (e < para_end && !is_sentence_break(e - 1)) ++e;
    out_range[0] = s;
    out_range[1] = e;
}

void ComputeShowedRegionRange(const MarkdownPage* page,
                              float view_top,
                              float view_bottom,
                              int32_t out_range[2]) {
    out_range[0] = -1;
    out_range[1] = -1;
    if (!page || page->regions.empty()) return;

    for (size_t i = 0; i < page->regions.size(); ++i) {
        const auto& r = page->regions[i];
        if (!r) continue;
        if (r->border_rect.bottom >= view_top && r->border_rect.top <= view_bottom) {
            if (out_range[0] < 0) out_range[0] = static_cast<int32_t>(i);
            out_range[1] = static_cast<int32_t>(i);
        }
    }
}

void ComputeShowedExtraContentRange(const MarkdownPage* page,
                                    float view_top,
                                    float view_bottom,
                                    int32_t out_range[2]) {
    out_range[0] = -1;
    out_range[1] = -1;
    if (!page || page->extra_contents.empty()) return;

    for (size_t i = 0; i < page->extra_contents.size(); ++i) {
        const auto& ex = page->extra_contents[i];
        if (!ex) continue;
        if (ex->rect.bottom >= view_top && ex->rect.top <= view_bottom) {
            if (out_range[0] < 0) out_range[0] = static_cast<int32_t>(i);
            out_range[1] = static_cast<int32_t>(i);
        }
    }
}

/**
 * @brief Inherit horizontal scroll state across layout passes (`nativeInheritState` @ 0x018268)
 *        Kế thừa trạng thái cuộn ngang giữa các lượt dàn trang (`nativeInheritState` @ 0x018268)
 */
void InheritDocumentScrollState(MarkdownDocument* dst_doc, const MarkdownDocument* src_doc) {
    if (!dst_doc || !src_doc) return;
    std::shared_ptr<MarkdownPage> src_page;
    {
        std::lock_guard<std::mutex> lock(src_doc->page_mutex_);
        src_page = src_doc->current_page_;
    }
    std::shared_ptr<MarkdownPage> dst_page;
    {
        std::lock_guard<std::mutex> lock(dst_doc->page_mutex_);
        dst_page = dst_doc->current_page_;
    }
    if (!src_page || !dst_page) return;

    size_t count = std::min(src_page->regions.size(), dst_page->regions.size());
    for (size_t i = 0; i < count; ++i) {
        if (src_page->regions[i] && dst_page->regions[i] &&
            src_page->regions[i]->block_type == dst_page->regions[i]->block_type &&
            src_page->regions[i]->scroll_x && dst_page->regions[i]->scroll_x) {
            dst_page->regions[i]->scroll_offset_x = src_page->regions[i]->scroll_offset_x;
        }
    }
}

} // namespace markdown
} // namespace lynx
