/**
 * @file lynx_markdown_parser.h
 * @brief Clean-Room C++17 Header for Embedded Discount + GFM Markdown Parser & Binary Style Sheet Parser
 *        Header C++17 Tái cấu trúc sạch Bộ phân tích Markdown Discount + GFM nhúng & Bộ giải mã Bảng kiểu dáng nhị phân
 *
 * Binary Target / Đích nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/liblynx_markdown.so (247,888 bytes)
 *   - nativeParse:                  0x00e718..0x00feb4 (6,044 bytes)
 *   - nativeSetStyle:               0x011a84..0x011e7b (1,016 bytes)
 *   - nativeAddTextMarkAttachment:  0x015970..0x016558 (3,048 bytes)
 *   - Discount Line/Block Lexer:    0x019f60..0x01bf50
 *   - Style Sheet & CSS Parser:     0x028c60..0x0352fc
 */

#pragma once

#include "lynx_markdown_types.h"

namespace lynx {
namespace markdown {

// ============================================================================
// Parsed Rich-Text AST Nodes (Intermediate representation between Discount & TTText)
// Các nút AST văn bản giàu định dạng (Biểu diễn trung gian giữa Discount & TTText)
// ============================================================================

enum class InlineNodeKind : int32_t {
    kText = 0,
    kBold = 1,
    kItalic = 2,
    kBoldItalic = 3,
    kStrikethrough = 4,
    kUnderline = 5,
    kInlineCode = 6,
    kMark = 7,
    kDoubleBraces = 8,
    kLink = 9,
    kImage = 10,
    kInlineView = 11,
    kSpanClass = 12,
    kLineBreak = 13
};

struct ParsedInlineSpan {
    InlineNodeKind kind = InlineNodeKind::kText;
    std::string text;                  // Visible text content
    std::string url;                   // For kLink / kImage / kInlineView
    std::string title;                 // Optional title or alt text
    std::string class_name;            // For <span class="...">
    float width = -1.0f;               // Explicit `=WxH` or `width=` attribute
    float height = -1.0f;              // Explicit `=WxH` or `height=` attribute
    int32_t md_start = 0;              // Source markdown byte start
    int32_t md_end = 0;                // Source markdown byte end
    std::vector<ParsedInlineSpan> children;
};

struct ParsedTableCell {
    std::vector<ParsedInlineSpan> spans;
    int32_t align = 0;                 // 0=left, 1=center, 2=right
    bool is_header = false;
};

struct ParsedBlockNode {
    DiscountBlockType type = DiscountBlockType::kMarkup;
    int32_t heading_level = 0;         // 1..6 for kHdr
    int32_t list_index = 1;            // 1-based index for ordered list items
    int32_t list_depth = 0;            // Nesting depth
    int32_t task_state = 0;            // 0=none, 1=unchecked `[ ]`, 2=checked `[x]`
    std::string code_lang;             // Info string for fenced code block
    std::string block_view_id;         // ID for `blockview://`
    int32_t md_start = 0;
    int32_t md_end = 0;
    std::vector<ParsedInlineSpan> spans;
    std::vector<ParsedBlockNode> children;
    std::vector<std::vector<ParsedTableCell>> table_rows;
};

// ============================================================================
// Binary Style Value Tree (`0x031c44..0x0352fc`)
// Cây giá trị kiểu dáng nhị phân (`0x031c44..0x0352fc`)
// ============================================================================

enum class StyleValueType : uint8_t {
    kNull = 0,
    kBool = 1,
    kInt32 = 2,
    kInt64 = 3,
    kDouble = 4,
    kString = 5,
    kArray = 6,
    kMap = 7
};

struct StyleValue {
    StyleValueType type = StyleValueType::kNull;
    bool bool_val = false;
    int64_t int_val = 0;
    double double_val = 0.0;
    std::string str_val;
    std::vector<StyleValue> array_val;
    std::unordered_map<std::string, StyleValue> map_val;

    bool IsMap() const { return type == StyleValueType::kMap; }
    bool IsArray() const { return type == StyleValueType::kArray; }
    bool IsString() const { return type == StyleValueType::kString; }
    bool IsNumber() const {
        return type == StyleValueType::kInt32 ||
               type == StyleValueType::kInt64 ||
               type == StyleValueType::kDouble;
    }

    float AsFloat(float fallback = 0.0f) const;
    int32_t AsInt(int32_t fallback = 0) const;
    uint32_t AsColor(uint32_t fallback = 0xFF000000u) const;
    bool AsBool(bool fallback = false) const;
    std::string AsString(const std::string& fallback = "") const;
    const StyleValue* Find(const std::string& key) const;
};

// ============================================================================
// Parser Entry Points
// Các điểm vào bộ phân tích
// ============================================================================

/**
 * @brief Convert UTF-8 character index to byte offset matching `0x00e9c0..0x00eaec`
 *        Chuyển chỉ số ký tự UTF-8 sang offset byte khớp chính xác `0x00e9c0..0x00eaec`
 */
size_t Utf8CharCountToByteOffset(const char* utf8, size_t byte_len, int32_t char_count);

/**
 * @brief Format positive integer (1..3999) into Roman numerals using `.data.rel.ro` tables @ `0x038668..0x038750`
 *        Định dạng số nguyên dương (1..3999) sang chữ số La Mã dùng bảng `.data.rel.ro` @ `0x038668..0x038750`
 */
std::string FormatRomanNumeral(int32_t number);

/**
 * @brief Parse Markdown document into AST blocks, link/image tables, offset map, and syntax ranges (`nativeParse` @ 0x00e718)
 *        Phân tích tài liệu Markdown thành các khối AST, bảng liên kết/ảnh, bản đồ offset và phạm vi cú pháp (`nativeParse` @ 0x00e718)
 */
void ParseMarkdownDocument(MarkdownDocument* doc,
                           const char* utf8_content,
                           size_t utf8_len,
                           int32_t char_start,
                           int32_t char_end,
                           float font_scale,
                           std::vector<ParsedBlockNode>* out_blocks);

/**
 * @brief Deserialize binary style buffer or JSON/key-value buffer into `StyleValue` tree (`0x011a84`, `0x015970`)
 *        Giải tuần tự hóa bộ đệm kiểu dáng nhị phân hoặc JSON/key-value thành cây `StyleValue` (`0x011a84`, `0x015970`)
 */
bool DeserializeStyleBuffer(const uint8_t* data, size_t len, StyleValue* out_root);

/**
 * @brief Apply `StyleValue` root dictionary onto `MarkdownStyleSheet` (`nativeSetStyle` @ 0x011a84, `0x029080..0x0352fc`)
 *        Áp dụng từ điển `StyleValue` gốc vào `MarkdownStyleSheet` (`nativeSetStyle` @ 0x011a84, `0x029080..0x0352fc`)
 */
void ApplyMarkdownStyleSheet(const StyleValue& root, MarkdownStyleSheet* sheet);

/**
 * @brief Parse a single `MarkdownTextAttachment` from binary style buffer (`nativeAddTextMarkAttachment` @ 0x015970)
 *        Phân tích một `MarkdownTextAttachment` từ bộ đệm kiểu dáng nhị phân (`nativeAddTextMarkAttachment` @ 0x015970)
 */
bool ParseTextMarkAttachment(const uint8_t* data, size_t len, MarkdownTextAttachment* out_attachment);

} // namespace markdown
} // namespace lynx
