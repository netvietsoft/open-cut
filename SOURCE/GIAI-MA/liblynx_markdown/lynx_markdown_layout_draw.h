/**
 * @file lynx_markdown_layout_draw.h
 * @brief Clean-Room C++17 Header for TTText Layout Engine, Typewriter Renderer, Hit-Testing & BufferCanvasHelper
 *        Header C++17 Tái cấu trúc sạch Động cơ dàn trang TTText, Bộ kết xuất Typewriter, Hit-Testing & BufferCanvasHelper
 *
 * Binary Target / Đích nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/liblynx_markdown.so (247,888 bytes)
 *   - BufferCanvasHelper & Paint: 0x018924..0x019d80 (vtables @ 0x038148, 0x038248, 0x038398)
 *   - RunDelegate subclasses:     0x01c198..0x01f740 (vtables @ 0x0383f0, 0x038470, 0x038490, 0x0384b0)
 *   - Layout & Hit-Testing:       0x0102a0..0x018420
 */

#pragma once

#include "lynx_markdown_types.h"
#include "lynx_markdown_parser.h"

namespace lynx {
namespace markdown {

// ============================================================================
// BufferCanvasHelper (Serialized Canvas Stream @ 0x018924..0x019d80)
// Bộ đệm lệnh vẽ Canvas nhị phân tuần tự (@ 0x018924..0x019d80)
// ============================================================================

enum class CanvasStreamOp : uint8_t {
    kStartPaint    = 0,
    kEndPaint      = 1,
    kSave          = 2,   // 0x0189e8: mov w9, #2
    kRestore       = 3,   // 0x018a34: mov w9, #3
    kTranslate     = 4,   // 0x018a80: mov w9, #4
    kScale         = 5,
    kRotate        = 6,
    kSkew          = 7,
    kClipRect      = 8,   // 0x018b10: mov w9, #8
    kClear         = 9,
    kClearRect     = 10,
    kFillRect      = 11,
    kDrawColor     = 12,
    kDrawLine      = 13,  // 0x018bd8
    kDrawRect      = 14,  // 0x018d40
    kDrawOval      = 15,
    kDrawCircle    = 16,  // 0x018ea8
    kDrawArc       = 17,
    kDrawPath      = 18,
    kDrawText      = 19,  // 0x018ff8
    kDrawGlyphs    = 20,  // 0x01914c
    kDrawDelegate  = 21,  // 0x019390
    kDrawRoundRect = 26   // 0x019474
};

/**
 * @brief Serialized binary canvas command stream (`vtable @ 0x038148`, initial capacity `0x400` = 1,024 bytes @ 0x011134)
 *        Luồng lệnh vẽ Canvas nhị phân tuần tự (`vtable @ 0x038148`, dung lượng khởi tạo `0x400` = 1.024 byte @ 0x011134)
 */
class BufferCanvasHelper : public ttoffice::tttext::ICanvasHelper {
public:
    explicit BufferCanvasHelper(size_t initial_capacity = 0x400);
    ~BufferCanvasHelper() override;

    std::unique_ptr<ttoffice::tttext::IPaintHelper> CreatePaint() override;    // 0x01897c
    void Save() override;                                                      // 0x0189e8 (op = 2)
    void Restore() override;                                                   // 0x018a34 (op = 3)
    void Translate(float dx, float dy) override;                               // 0x018a80 (op = 4)
    void ClipRect(float left, float top, float right, float bottom, bool doAntiAlias) override; // 0x018b10 (op = 8)
    void DrawLine(float x1, float y1, float x2, float y2, ttoffice::tttext::IPaintHelper* paint) override; // 0x018bd8
    void DrawRect(float left, float top, float right, float bottom, ttoffice::tttext::IPaintHelper* paint) override; // 0x018d40
    void DrawCircle(float x, float y, float radius, ttoffice::tttext::IPaintHelper* paint) override; // 0x018ea8
    void DrawText(const char* text, uint32_t len, float x, float y, ttoffice::tttext::IPaintHelper* paint) override; // 0x018ff8
    void DrawGlyphs(const uint16_t* glyphs, const float* positions, uint32_t count, float x, float y, ttoffice::tttext::IPaintHelper* paint) override; // 0x01914c
    void DrawRunDelegate(ttoffice::tttext::RunDelegate* delegate, float left, float top, float right, float bottom, ttoffice::tttext::IPaintHelper* paint) override; // 0x019390
    void DrawRoundRect(float left, float top, float right, float bottom, float radius, ttoffice::tttext::IPaintHelper* paint) override; // 0x019474

    const uint8_t* Data() const { return buffer_; }
    size_t Size() const { return size_; }

private:
    void WriteBytes(const void* src, size_t len);                              // 0x0199d4
    void WriteU8(uint8_t val) { WriteBytes(&val, 1); }
    void WriteU32(uint32_t val) { WriteBytes(&val, 4); }
    void WriteF32(float val) { WriteBytes(&val, 4); }
    void WritePaintState(const ttoffice::tttext::IPaintHelper* paint);

    uint8_t* buffer_ = nullptr; // +0x08 (`malloc(0x400)` @ 0x01114c)
    size_t size_ = 0;           // +0x10
    size_t capacity_ = 0;       // +0x18
};

// ============================================================================
// RunDelegate Implementations (InlineView, Image, UnorderedBullet, OrderedNumber)
// Các lớp thực thi RunDelegate (InlineView, Image, UnorderedBullet, OrderedNumber)
// ============================================================================

class InlineViewRunDelegate : public ttoffice::tttext::RunDelegate {
public:
    InlineViewRunDelegate(std::string view_id, float width, float height, float ascent, float descent)
        : view_id_(std::move(view_id)), width_(width), height_(height), ascent_(ascent), descent_(descent) {}

    float GetAscent() const override { return -ascent_; }                      // 0x02682c: ldr s0, [x0, #0x14]; fneg s0, s0
    float GetDescent() const override { return descent_; }
    float GetAdvance() const override { return width_; }
    void Draw(ttoffice::tttext::ICanvasHelper* canvas, float x, float y) override;

    const std::string& GetViewId() const { return view_id_; }
    void SetOriginRect(const RectF& r) { rect_ = r; }
    const RectF& GetOriginRect() const { return rect_; }

private:
    std::string view_id_;
    float width_ = 0.0f;
    float height_ = 0.0f;
    float ascent_ = 0.0f;
    float descent_ = 0.0f;
    RectF rect_{};
};

class ImageRunDelegate : public ttoffice::tttext::RunDelegate {
public:
    ImageRunDelegate(std::string image_url, int32_t delegate_id, float width, float height)
        : image_url_(std::move(image_url)), delegate_id_(delegate_id), width_(width), height_(height) {}

    float GetAscent() const override { return -height_; }
    float GetDescent() const override { return 0.0f; }
    float GetAdvance() const override { return width_; }
    void Draw(ttoffice::tttext::ICanvasHelper* canvas, float x, float y) override;

    const std::string& GetImageUrl() const { return image_url_; }
    int32_t GetDelegateId() const { return delegate_id_; }

private:
    std::string image_url_;
    int32_t delegate_id_ = 0;
    float width_ = 0.0f;
    float height_ = 0.0f;
};

// ============================================================================
// Core Markdown Document Layout, Drawing & Hit-Testing Operations
// Các hàm Dàn trang, Vẽ và Kiểm tra va chạm (Hit-Testing) của MarkdownDocument
// ============================================================================

/**
 * @brief Perform full layout of `MarkdownDocument` (`nativeLayout` @ 0x0102a0)
 *        Thực hiện dàn trang toàn bộ `MarkdownDocument` (`nativeLayout` @ 0x0102a0)
 * @return Packed `int64_t`: `(int64_t(bit_cast<uint32_t>(width)) << 32) | bit_cast<uint32_t>(height)`
 */
int64_t LayoutMarkdownDocument(MarkdownDocument* doc,
                               float max_width,
                               float max_height,
                               int32_t typewriter_step);

/**
 * @brief Exact binary search converting Markdown byte offset to rendered character index (`nativeMarkdownOffsetToChar` @ 0x0142d4)
 *        Tìm kiếm nhị phân chính xác chuyển byte offset Markdown sang chỉ số ký tự hiển thị (`nativeMarkdownOffsetToChar` @ 0x0142d4)
 */
int32_t ConvertMarkdownOffsetToChar(const MarkdownDocument* doc, int32_t markdown_offset);

/**
 * @brief Compute typewriter cursor `(x, y, height)` position (`nativeGetCursorPosition` @ 0x011528)
 *        Tính tọa độ con trỏ máy chữ `(x, y, height)` (`nativeGetCursorPosition` @ 0x011528)
 */
void ComputeTypewriterCursorPosition(MarkdownDocument* doc,
                                     int32_t char_count,
                                     bool is_custom_cursor,
                                     float out_xyh[3]);

/**
 * @brief Render entire `MarkdownPage` into a `BufferCanvasHelper` byte stream (`nativeDraw` @ 0x011100)
 *        Kết xuất toàn bộ `MarkdownPage` vào luồng byte `BufferCanvasHelper` (`nativeDraw` @ 0x011100)
 */
std::vector<uint8_t> DrawMarkdownPageToBuffer(MarkdownDocument* doc);

/**
 * @brief Render `MarkdownPage` with typewriter character limit and cursor (`nativeDrawWithCursor` @ 0x011294)
 *        Kết xuất `MarkdownPage` với giới hạn ký tự máy chữ và con trỏ (`nativeDrawWithCursor` @ 0x011294)
 */
std::vector<uint8_t> DrawMarkdownPageWithCursorToBuffer(MarkdownDocument* doc,
                                                        int32_t char_count,
                                                        bool show_cursor);

/**
 * @brief Render a single layout region by index (`nativeDrawRegion` @ 0x01693c)
 *        Kết xuất một vùng bố cục đơn lẻ theo chỉ số (`nativeDrawRegion` @ 0x01693c)
 */
std::vector<uint8_t> DrawSingleRegionToBuffer(MarkdownDocument* doc, int32_t region_index);

/**
 * @brief Render a single region clipped to typewriter step (`nativeDrawTypewriterRegion` @ 0x016ae4)
 *        Kết xuất một vùng bố cục được cắt theo bước máy chữ (`nativeDrawTypewriterRegion` @ 0x016ae4)
 */
std::vector<uint8_t> DrawTypewriterRegionToBuffer(MarkdownDocument* doc,
                                                  int32_t region_index,
                                                  int32_t char_count,
                                                  bool show_cursor);

/**
 * @brief Render a single extra content element by index (`nativeDrawExtraContent` @ 0x016d94)
 *        Kết xuất một phần tử nội dung phụ theo chỉ số (`nativeDrawExtraContent` @ 0x016d94)
 */
std::vector<uint8_t> DrawSingleExtraContentToBuffer(MarkdownDocument* doc, int32_t extra_index);

/**
 * @brief Compute selection bounding rectangles for `[char_start, char_end)` (`nativeGetSelectionRectByCharPos` @ 0x013c4c)
 *        Tính danh sách hình chữ nhật vùng chọn cho `[char_start, char_end)` (`nativeGetSelectionRectByCharPos` @ 0x013c4c)
 */
std::vector<RectF> ComputeSelectionRectsByCharRange(const MarkdownPage* page,
                                                    int32_t char_start,
                                                    int32_t char_end);

/**
 * @brief Hit-test character index and expand by split type (`nativeGetCharRangeByPoint` @ 0x0140bc)
 *        Kiểm tra va chạm tìm chỉ số ký tự và mở rộng theo kiểu tách (`nativeGetCharRangeByPoint` @ 0x0140bc)
 *        split_type: 0=char, 1=word, 2=sentence (`. `, `? `, `! `, `; ` @ 0x005a42..0x005a4b), 3=paragraph
 */
void ComputeCharRangeByPoint(const MarkdownPage* page,
                             float touch_x,
                             float touch_y,
                             int32_t split_type,
                             int32_t out_range[2]);

/**
 * @brief Find visible region range `[first_idx, last_idx]` intersecting `[top_y, bottom_y]` (`nativeGetShowedRegion` @ 0x017dc4)
 *        Tìm khoảng vùng hiển thị `[first_idx, last_idx]` giao với `[top_y, bottom_y]` (`nativeGetShowedRegion` @ 0x017dc4)
 */
void ComputeShowedRegionRange(const MarkdownPage* page,
                              float view_top,
                              float view_bottom,
                              int32_t out_range[2]);

/**
 * @brief Find visible extra content range `[first_idx, last_idx]` intersecting `[top_y, bottom_y]` (`nativeGetShowedExtraContent` @ 0x0180c4)
 *        Tìm khoảng nội dung phụ hiển thị `[first_idx, last_idx]` giao với `[top_y, bottom_y]` (`nativeGetShowedExtraContent` @ 0x0180c4)
 */
void ComputeShowedExtraContentRange(const MarkdownPage* page,
                                    float view_top,
                                    float view_bottom,
                                    int32_t out_range[2]);

/**
 * @brief Inherit horizontal scroll state from previous `MarkdownDocument` (`nativeInheritState` @ 0x018268)
 *        Kế thừa trạng thái cuộn ngang từ `MarkdownDocument` trước đó (`nativeInheritState` @ 0x018268)
 */
void InheritDocumentScrollState(MarkdownDocument* dst_doc, const MarkdownDocument* src_doc);

} // namespace markdown
} // namespace lynx
