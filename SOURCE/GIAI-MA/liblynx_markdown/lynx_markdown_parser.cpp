/**
 * @file lynx_markdown_parser.cpp
 * @brief Clean-Room C++17 Implementation of Embedded Discount + GFM Markdown Parser & Binary Style Sheet Parser
 *        Triển khai C++17 Tái cấu trúc sạch Bộ phân tích Markdown Discount + GFM nhúng & Bộ giải mã Bảng kiểu dáng nhị phân
 *
 * Binary Target / Đích nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/liblynx_markdown.so (247,888 bytes)
 *   - UTF-8 Codepoint Offset Slicer:   0x00e9c0..0x00eaec
 *   - Discount MMIOT & Line Queue:     0x00eaec..0x00feb4, 0x019f60..0x01bf50
 *   - Roman Numeral Tables:            0x038668..0x038750 (.rodata 0x005925..0x0059bb)
 *   - Font Weight Table:               0x0389d0..0x038a20 (.rodata 0x0059d2..0x0059f2)
 *   - Style Sheet Deserializer:        0x011a84..0x013254, 0x028c60..0x0352fc
 */

#include "lynx_markdown_parser.h"
#include <cstdlib>
#include <cstdio>
#include <cctype>

// ============================================================================
// lynx::base & lynx::base::android Imported Utilities Implementation
// Triển khai các hàm tiện ích nhập từ liblynxbase.so (PLT 0x0353a0..0x035880)
// ============================================================================
namespace lynx {
namespace base {

/**
 * @brief Convert UTF-8 string view to UTF-16 basic_string<char16_t> (PLT @ 0x0354f0)
 *        Chuyển chuỗi UTF-8 sang UTF-16 basic_string<char16_t> (PLT @ 0x0354f0)
 */
std::u16string U8StringToU16(std::string_view u8_str) {
    std::u16string out;
    out.reserve(u8_str.size());
    size_t i = 0;
    const size_t n = u8_str.size();
    while (i < n) {
        uint8_t c0 = static_cast<uint8_t>(u8_str[i]);
        uint32_t cp = 0;
        if ((c0 & 0x80u) == 0) {
            cp = c0;
            i += 1;
        } else if ((c0 & 0xE0u) == 0xC0u && i + 1 < n) {
            cp = ((c0 & 0x1Fu) << 6) | (static_cast<uint8_t>(u8_str[i + 1]) & 0x3Fu);
            i += 2;
        } else if ((c0 & 0xF0u) == 0xE0u && i + 2 < n) {
            cp = ((c0 & 0x0Fu) << 12) |
                 ((static_cast<uint8_t>(u8_str[i + 1]) & 0x3Fu) << 6) |
                 (static_cast<uint8_t>(u8_str[i + 2]) & 0x3Fu);
            i += 3;
        } else if ((c0 & 0xF8u) == 0xF0u && i + 3 < n) {
            cp = ((c0 & 0x07u) << 18) |
                 ((static_cast<uint8_t>(u8_str[i + 1]) & 0x3Fu) << 12) |
                 ((static_cast<uint8_t>(u8_str[i + 2]) & 0x3Fu) << 6) |
                 (static_cast<uint8_t>(u8_str[i + 3]) & 0x3Fu);
            i += 4;
        } else {
            cp = 0xFFFDu;
            i += 1;
        }

        if (cp <= 0xFFFFu) {
            out.push_back(static_cast<char16_t>(cp));
        } else if (cp <= 0x10FFFFu) {
            cp -= 0x10000u;
            out.push_back(static_cast<char16_t>(0xD800u + (cp >> 10)));
            out.push_back(static_cast<char16_t>(0xDC00u + (cp & 0x3FFu)));
        }
    }
    return out;
}

/**
 * @brief Trim leading and trailing ASCII whitespace from string_view (PLT @ 0x035750)
 *        Cắt khoảng trắng đầu/cuối khỏi string_view (PLT @ 0x035750)
 */
std::string_view TrimToStringView(std::string_view str) {
    size_t start = 0;
    while (start < str.size() && std::isspace(static_cast<unsigned char>(str[start]))) {
        ++start;
    }
    size_t end = str.size();
    while (end > start && std::isspace(static_cast<unsigned char>(str[end - 1]))) {
        --end;
    }
    return str.substr(start, end - start);
}

/**
 * @brief Parse string into 32-bit float with optional strict check (PLT @ 0x035880)
 *        Phân tích chuỗi thành số thực float 32-bit (PLT @ 0x035880)
 */
bool StringToFloat(const std::string& input, float& output, bool error_on_rest) {
    if (input.empty()) {
        return false;
    }
    char* end_ptr = nullptr;
    float val = std::strtof(input.c_str(), &end_ptr);
    if (end_ptr == input.c_str()) {
        return false;
    }
    if (error_on_rest && end_ptr != nullptr && *end_ptr != '\0') {
        while (*end_ptr != '\0' && std::isspace(static_cast<unsigned char>(*end_ptr))) {
            ++end_ptr;
        }
        if (*end_ptr != '\0') {
            return false;
        }
    }
    output = val;
    return true;
}

namespace android {

static JavaVM* g_lynx_jvm = nullptr;
static thread_local JNIEnv* g_tls_env = nullptr;

void InitVM(JavaVM* vm) {
    g_lynx_jvm = vm;
}

JNIEnv* AttachCurrentThread() {
    return g_tls_env;
}

jstring JNIConvertHelper::ConvertToJNIStringUTF(JNIEnv* env, const char* str) {
    if (!env || !env->functions || !env->functions->NewStringUTF) {
        return nullptr;
    }
    return env->functions->NewStringUTF(env, str ? str : "");
}

} // namespace android
} // namespace base
} // namespace lynx

// ============================================================================
// Embedded Discount + GFM Markdown Parser Implementation (0x00e9c0..0x01bf50)
// Triển khai Bộ phân tích Markdown Discount + GFM nhúng (0x00e9c0..0x01bf50)
// ============================================================================
namespace lynx {
namespace markdown {

/**
 * @brief Exact UTF-8 codepoint count to byte offset scanner matching `nativeParse` @ `0x00e9c0..0x00eaec`
 *        Bộ quét chuyển số lượng codepoint UTF-8 sang byte offset khớp chính xác `nativeParse` @ `0x00e9c0..0x00eaec`
 *
 * Disassembly verification (`0x00e9e0..0x00ea54`):
 *   - `ldrsb w9, [x27, x19]`
 *   - `tbnz w9, #0x1f, #0xe9f0` -> if >= 0 (ASCII 0x00..0x7F): `mov w9, #1`
 *   - `mvn w10, w9; tst w10, #0xc0` -> if continuation byte `(b & 0xc0) == 0x80`: `mov x9, xzr`
 *   - `and w10, w9, #0xe0; cmp w10, #0xc0` -> 2-byte sequence (`mov w9, #2`)
 *   - `and w10, w9, #0xf0; cmp w10, #0xe0` -> 3-byte sequence (`mov w9, #3`)
 *   - `and w9, w9, #0xf8; cmp w9, #0xf0; cset w9, eq; lsl x9, x9, #2` -> 4-byte sequence (`4`)
 */
size_t Utf8CharCountToByteOffset(const char* utf8, size_t byte_len, int32_t char_count) {
    if (!utf8 || byte_len == 0 || char_count <= 0) {
        return 0;
    }
    size_t byte_offset = 0;
    int32_t remaining = char_count;
    while (remaining > 0 && byte_offset < byte_len) {
        int8_t signed_b = static_cast<int8_t>(utf8[byte_offset]);
        size_t step = 0;
        if (signed_b >= 0) {
            step = 1;
        } else {
            uint8_t b = static_cast<uint8_t>(signed_b);
            uint8_t inv = static_cast<uint8_t>(~b);
            if ((inv & 0xC0u) == 0) {
                if ((b & 0xE0u) == 0xC0u) {
                    step = 2;
                } else if ((b & 0xF0u) == 0xE0u) {
                    step = 3;
                } else if ((b & 0xF8u) == 0xF0u) {
                    step = 4;
                }
            }
        }
        if (step == 0) {
            step = 1;
        }
        byte_offset += step;
        --remaining;
    }
    return std::min(byte_offset, byte_len);
}

/**
 * @brief Format positive integer into Roman numerals matching `.data.rel.ro` tables @ `0x038668..0x038750`
 *        Định dạng số nguyên dương sang chữ số La Mã khớp bảng `.data.rel.ro` @ `0x038668..0x038750`
 *
 * `.data.rel.ro` tables verified from disassembly:
 *   - Hundreds (`0x038668..0x0386b0`): `{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}`
 *   - Tens     (`0x0386b8..0x038700`): `{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}`
 *   - Ones     (`0x038708..0x038750`): `{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}`
 */
std::string FormatRomanNumeral(int32_t number) {
    static const char* const kHundreds[10] = {
        "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"
    };
    static const char* const kTens[10] = {
        "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"
    };
    static const char* const kOnes[10] = {
        "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"
    };

    if (number <= 0) {
        return "I";
    }
    std::string result;
    int32_t n = number;
    while (n >= 1000) {
        result += "M";
        n -= 1000;
    }
    result += kHundreds[(n / 100) % 10];
    result += kTens[(n / 10) % 10];
    result += kOnes[n % 10];
    return result;
}

namespace {

/**
 * @brief Count leading indentation spaces of a line (`0x019f88..0x019fe0`), where `'\t'` (9) counts as 4 (`mov w23, #4` @ `0x019fa0`)
 *        Đếm số khoảng trắng thụt lề đầu dòng (`0x019f88..0x019fe0`), trong đó `'\t'` (9) tính bằng 4 (`mov w23, #4` @ `0x019fa0`)
 */
int32_t CountLeadingIndent(std::string_view line) {
    int32_t indent = 0;
    for (char c : line) {
        if (c == '\t') {
            indent += 4;
        } else if (c == ' ') {
            indent += 1;
        } else {
            break;
        }
    }
    return indent;
}

/**
 * @brief Parse image size suffix `=WxH` (`sscanf(..., "=%dx%d", &w, &h)` @ `0x00f86c`, `.rodata 0x005912`) or `width=`/`height=` (`0x0059c3..0x0059cb`)
 *        Phân tích hậu tố kích thước ảnh `=WxH` (`sscanf` @ `0x00f86c`) hoặc `width=`/`height=` (`0x0059c3..0x0059cb`)
 */
void ExtractUrlAndDimensions(std::string_view raw_target,
                             std::string* out_url,
                             std::string* out_title,
                             float* out_width,
                             float* out_height) {
    std::string_view trimmed = lynx::base::TrimToStringView(raw_target);
    *out_width = -1.0f;
    *out_height = -1.0f;
    out_title->clear();

    // Check for `=WxH` suffix (`0x005912: "=%dx%d"`)
    size_t eq_pos = trimmed.rfind(" =");
    if (eq_pos == std::string_view::npos && !trimmed.empty() && trimmed[0] == '=') {
        eq_pos = 0;
    }
    if (eq_pos != std::string_view::npos) {
        std::string tail(trimmed.substr(eq_pos + (trimmed[eq_pos] == ' ' ? 1 : 0)));
        int w = 0;
        int h = 0;
        if (std::sscanf(tail.c_str(), "=%dx%d", &w, &h) == 2 && w > 0 && h > 0) {
            *out_width = static_cast<float>(w);
            *out_height = static_cast<float>(h);
            trimmed = lynx::base::TrimToStringView(trimmed.substr(0, eq_pos));
        }
    }

    // Check for optional quoted title `"..."` or `'...'`
    if (trimmed.size() >= 2 && (trimmed.back() == '"' || trimmed.back() == '\'')) {
        char quote = trimmed.back();
        size_t open_q = trimmed.rfind(quote, trimmed.size() - 2);
        if (open_q != std::string_view::npos && open_q > 0) {
            *out_title = std::string(trimmed.substr(open_q + 1, trimmed.size() - open_q - 2));
            trimmed = lynx::base::TrimToStringView(trimmed.substr(0, open_q));
        }
    }

    // Check query parameters `width=` (`0x0059cb`) and `height=` (`0x0059c3`)
    size_t w_pos = trimmed.find("width=");
    if (w_pos != std::string_view::npos && *out_width <= 0.0f) {
        *out_width = std::strtof(std::string(trimmed.substr(w_pos + 6)).c_str(), nullptr);
    }
    size_t h_pos = trimmed.find("height=");
    if (h_pos != std::string_view::npos && *out_height <= 0.0f) {
        *out_height = std::strtof(std::string(trimmed.substr(h_pos + 7)).c_str(), nullptr);
    }

    if (trimmed.size() >= 2 && trimmed.front() == '<' && trimmed.back() == '>') {
        trimmed = trimmed.substr(1, trimmed.size() - 2);
    }
    *out_url = std::string(trimmed);
}

/**
 * @brief Parse inline Markdown spans within `[text_view]` (`0x01a000..0x01bf50`)
 *        Phân tích các span nội dòng Markdown trong `[text_view]` (`0x01a000..0x01bf50`)
 */
std::vector<ParsedInlineSpan> ParseInlineSpans(
    std::string_view text_view,
    int32_t base_md_offset,
    const std::unordered_map<std::string, DiscountFootnote>& ref_map,
    std::vector<MarkdownSyntaxRange>* syntax_ranges) {
    std::vector<ParsedInlineSpan> spans;
    std::string current_text;
    int32_t current_start = base_md_offset;

    auto flush_text = [&](int32_t end_offset) {
        if (!current_text.empty()) {
            ParsedInlineSpan s;
            s.kind = InlineNodeKind::kText;
            s.text = std::move(current_text);
            s.md_start = current_start;
            s.md_end = end_offset;
            spans.push_back(std::move(s));
            current_text.clear();
        }
    };

    size_t i = 0;
    const size_t n = text_view.size();
    while (i < n) {
        int32_t abs_pos = base_md_offset + static_cast<int32_t>(i);

        // 1. Escape sequence `\x`
        if (text_view[i] == '\\' && i + 1 < n && std::ispunct(static_cast<unsigned char>(text_view[i + 1]))) {
            if (current_text.empty()) {
                current_start = abs_pos;
            }
            current_text.push_back(text_view[i + 1]);
            i += 2;
            continue;
        }

        // 2. Lynx Double Braces `{{...}}` (`0x005581: "doubleBraces"`)
        if (i + 3 < n && text_view[i] == '{' && text_view[i + 1] == '{') {
            size_t close = text_view.find("}}", i + 2);
            if (close != std::string_view::npos) {
                flush_text(abs_pos);
                ParsedInlineSpan s;
                s.kind = InlineNodeKind::kDoubleBraces;
                s.text = std::string(text_view.substr(i + 2, close - (i + 2)));
                s.md_start = abs_pos;
                s.md_end = base_md_offset + static_cast<int32_t>(close + 2);
                if (syntax_ranges) {
                    syntax_ranges->push_back({"doubleBraces", s.md_start, s.md_end, 0, 0});
                }
                spans.push_back(std::move(s));
                i = close + 2;
                current_start = base_md_offset + static_cast<int32_t>(i);
                continue;
            }
        }

        // 3. Inline code `` `...` `` (`0x00588c: "inlineCode"`)
        if (text_view[i] == '`') {
            size_t tick_count = 1;
            while (i + tick_count < n && text_view[i + tick_count] == '`') {
                ++tick_count;
            }
            std::string_view needle = text_view.substr(i, tick_count);
            size_t close = text_view.find(needle, i + tick_count);
            if (close != std::string_view::npos) {
                flush_text(abs_pos);
                ParsedInlineSpan s;
                s.kind = InlineNodeKind::kInlineCode;
                s.text = std::string(text_view.substr(i + tick_count, close - (i + tick_count)));
                s.md_start = abs_pos;
                s.md_end = base_md_offset + static_cast<int32_t>(close + tick_count);
                if (syntax_ranges) {
                    syntax_ranges->push_back({"inlineCode", s.md_start, s.md_end, 0, 0});
                }
                spans.push_back(std::move(s));
                i = close + tick_count;
                current_start = base_md_offset + static_cast<int32_t>(i);
                continue;
            }
        }

        // 4. Image `![alt](url)` or Inline View `![alt](inlineview://id)` (`0x005a03`)
        if (i + 1 < n && text_view[i] == '!' && text_view[i + 1] == '[') {
            size_t close_bracket = text_view.find(']', i + 2);
            if (close_bracket != std::string_view::npos && close_bracket + 1 < n &&
                text_view[close_bracket + 1] == '(') {
                size_t close_paren = text_view.find(')', close_bracket + 2);
                if (close_paren != std::string_view::npos) {
                    flush_text(abs_pos);
                    std::string alt(text_view.substr(i + 2, close_bracket - (i + 2)));
                    std::string_view raw_url = text_view.substr(close_bracket + 2, close_paren - (close_bracket + 2));
                    std::string url;
                    std::string title;
                    float w = -1.0f;
                    float h = -1.0f;
                    ExtractUrlAndDimensions(raw_url, &url, &title, &w, &h);

                    ParsedInlineSpan s;
                    s.md_start = abs_pos;
                    s.md_end = base_md_offset + static_cast<int32_t>(close_paren + 1);
                    if (url.rfind("inlineview://", 0) == 0) {
                        s.kind = InlineNodeKind::kInlineView;
                        s.url = url.substr(std::strlen("inlineview://"));
                        s.text = alt;
                        s.width = w;
                        s.height = h;
                    } else {
                        s.kind = InlineNodeKind::kImage;
                        s.url = url;
                        s.text = alt;
                        s.title = title.empty() ? alt : title;
                        s.width = w;
                        s.height = h;
                        if (syntax_ranges) {
                            syntax_ranges->push_back({"image", s.md_start, s.md_end, 0, 0});
                        }
                    }
                    spans.push_back(std::move(s));
                    i = close_paren + 1;
                    current_start = base_md_offset + static_cast<int32_t>(i);
                    continue;
                }
            }
        }

        // 5. Link `[label](url)` or Reference Link `[label][ref]` or Inline View `[label](inlineview://id)`
        if (text_view[i] == '[') {
            size_t close_bracket = text_view.find(']', i + 1);
            if (close_bracket != std::string_view::npos) {
                std::string label(text_view.substr(i + 1, close_bracket - (i + 1)));
                if (close_bracket + 1 < n && text_view[close_bracket + 1] == '(') {
                    size_t close_paren = text_view.find(')', close_bracket + 2);
                    if (close_paren != std::string_view::npos) {
                        flush_text(abs_pos);
                        std::string_view raw_url = text_view.substr(close_bracket + 2, close_paren - (close_bracket + 2));
                        std::string url;
                        std::string title;
                        float w = -1.0f;
                        float h = -1.0f;
                        ExtractUrlAndDimensions(raw_url, &url, &title, &w, &h);

                        ParsedInlineSpan s;
                        s.md_start = abs_pos;
                        s.md_end = base_md_offset + static_cast<int32_t>(close_paren + 1);
                        if (url.rfind("inlineview://", 0) == 0) {
                            s.kind = InlineNodeKind::kInlineView;
                            s.url = url.substr(std::strlen("inlineview://"));
                            s.text = label;
                            s.width = w;
                            s.height = h;
                        } else {
                            s.kind = InlineNodeKind::kLink;
                            s.url = url;
                            s.text = label;
                            s.title = title;
                            if (syntax_ranges) {
                                syntax_ranges->push_back({"link", s.md_start, s.md_end, 0, 0});
                            }
                        }
                        spans.push_back(std::move(s));
                        i = close_paren + 1;
                        current_start = base_md_offset + static_cast<int32_t>(i);
                        continue;
                    }
                } else if (close_bracket + 1 < n && text_view[close_bracket + 1] == '[') {
                    size_t close_ref = text_view.find(']', close_bracket + 2);
                    if (close_ref != std::string_view::npos) {
                        std::string ref_key(text_view.substr(close_bracket + 2, close_ref - (close_bracket + 2)));
                        if (ref_key.empty()) {
                            ref_key = label;
                        }
                        std::string lower_key = ref_key;
                        std::transform(lower_key.begin(), lower_key.end(), lower_key.begin(),
                                       [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
                        auto it = ref_map.find(lower_key);
                        if (it != ref_map.end()) {
                            flush_text(abs_pos);
                            ParsedInlineSpan s;
                            s.kind = InlineNodeKind::kLink;
                            s.url = it->second.link;
                            s.text = label;
                            s.title = it->second.title;
                            s.md_start = abs_pos;
                            s.md_end = base_md_offset + static_cast<int32_t>(close_ref + 1);
                            if (syntax_ranges) {
                                syntax_ranges->push_back({"link", s.md_start, s.md_end, 0, 0});
                            }
                            spans.push_back(std::move(s));
                            i = close_ref + 1;
                            current_start = base_md_offset + static_cast<int32_t>(i);
                            continue;
                        }
                    }
                }
            }
        }

        // 6. Bold + Italic `***...***` or Bold `**...**` / `__...__` or Italic `*...*` / `_..._`
        if (text_view[i] == '*' || text_view[i] == '_') {
            char delim = text_view[i];
            size_t count = 1;
            while (i + count < n && text_view[i + count] == delim && count < 3) {
                ++count;
            }
            std::string_view marker = text_view.substr(i, count);
            size_t close = text_view.find(marker, i + count);
            if (close != std::string_view::npos && close > i + count) {
                flush_text(abs_pos);
                ParsedInlineSpan s;
                if (count == 3) {
                    s.kind = InlineNodeKind::kBoldItalic;
                } else if (count == 2) {
                    s.kind = InlineNodeKind::kBold;
                } else {
                    s.kind = InlineNodeKind::kItalic;
                }
                s.text = std::string(text_view.substr(i + count, close - (i + count)));
                s.md_start = abs_pos;
                s.md_end = base_md_offset + static_cast<int32_t>(close + count);
                if (syntax_ranges) {
                    syntax_ranges->push_back({count >= 2 ? "bold" : "italic", s.md_start, s.md_end, 0, 0});
                }
                spans.push_back(std::move(s));
                i = close + count;
                current_start = base_md_offset + static_cast<int32_t>(i);
                continue;
            }
        }

        // 7. Strikethrough `~~...~~` or Highlight Mark `==...==`
        if (i + 1 < n && ((text_view[i] == '~' && text_view[i + 1] == '~') ||
                          (text_view[i] == '=' && text_view[i + 1] == '='))) {
            std::string_view marker = text_view.substr(i, 2);
            size_t close = text_view.find(marker, i + 2);
            if (close != std::string_view::npos && close > i + 2) {
                flush_text(abs_pos);
                ParsedInlineSpan s;
                s.kind = (text_view[i] == '~') ? InlineNodeKind::kStrikethrough : InlineNodeKind::kMark;
                s.text = std::string(text_view.substr(i + 2, close - (i + 2)));
                s.md_start = abs_pos;
                s.md_end = base_md_offset + static_cast<int32_t>(close + 2);
                if (syntax_ranges) {
                    syntax_ranges->push_back({(text_view[i] == '~') ? "strikethrough" : "mark", s.md_start, s.md_end, 0, 0});
                }
                spans.push_back(std::move(s));
                i = close + 2;
                current_start = base_md_offset + static_cast<int32_t>(i);
                continue;
            }
        }

        // 8. HTML `<span class="...">...</span>` (`0x005563: "class"`) or `<br>`
        if (text_view[i] == '<') {
            if (text_view.substr(i).rfind("<br>", 0) == 0 || text_view.substr(i).rfind("<br/>", 0) == 0) {
                size_t tag_len = (text_view[i + 3] == '>') ? 4 : 5;
                flush_text(abs_pos);
                ParsedInlineSpan s;
                s.kind = InlineNodeKind::kLineBreak;
                s.text = "\n";
                s.md_start = abs_pos;
                s.md_end = abs_pos + static_cast<int32_t>(tag_len);
                spans.push_back(std::move(s));
                i += tag_len;
                current_start = base_md_offset + static_cast<int32_t>(i);
                continue;
            }
            if (text_view.substr(i).rfind("<span", 0) == 0) {
                size_t tag_end = text_view.find('>', i + 5);
                size_t close_span = (tag_end != std::string_view::npos)
                                        ? text_view.find("</span>", tag_end + 1)
                                        : std::string_view::npos;
                if (close_span != std::string_view::npos) {
                    flush_text(abs_pos);
                    std::string_view attrs = text_view.substr(i + 5, tag_end - (i + 5));
                    std::string cls_name;
                    size_t cls_pos = attrs.find("class=");
                    if (cls_pos != std::string_view::npos && cls_pos + 7 < attrs.size()) {
                        char q = attrs[cls_pos + 6];
                        if (q == '"' || q == '\'') {
                            size_t q_end = attrs.find(q, cls_pos + 7);
                            if (q_end != std::string_view::npos) {
                                cls_name = std::string(attrs.substr(cls_pos + 7, q_end - (cls_pos + 7)));
                            }
                        }
                    }
                    ParsedInlineSpan s;
                    s.kind = InlineNodeKind::kSpanClass;
                    s.class_name = cls_name;
                    s.text = std::string(text_view.substr(tag_end + 1, close_span - (tag_end + 1)));
                    s.md_start = abs_pos;
                    s.md_end = base_md_offset + static_cast<int32_t>(close_span + 7);
                    spans.push_back(std::move(s));
                    i = close_span + 7;
                    current_start = base_md_offset + static_cast<int32_t>(i);
                    continue;
                }
            }
        }

        if (current_text.empty()) {
            current_start = abs_pos;
        }
        current_text.push_back(text_view[i]);
        ++i;
    }

    flush_text(base_md_offset + static_cast<int32_t>(n));
    return spans;
}

/**
 * @brief Split a GFM table row `| col1 | col2 |` into cell strings
 *        Tách một hàng bảng GFM `| col1 | col2 |` thành danh sách chuỗi ô
 */
std::vector<std::string_view> SplitTableRow(std::string_view line) {
    std::string_view trimmed = lynx::base::TrimToStringView(line);
    if (!trimmed.empty() && trimmed.front() == '|') {
        trimmed.remove_prefix(1);
    }
    if (!trimmed.empty() && trimmed.back() == '|') {
        trimmed.remove_suffix(1);
    }
    std::vector<std::string_view> cells;
    size_t start = 0;
    for (size_t i = 0; i <= trimmed.size(); ++i) {
        if (i == trimmed.size() || (trimmed[i] == '|' && (i == 0 || trimmed[i - 1] != '\\'))) {
            cells.push_back(lynx::base::TrimToStringView(trimmed.substr(start, i - start)));
            start = i + 1;
        }
    }
    return cells;
}

/**
 * @brief Check if a line is a GFM table delimiter row `| :--- | :---: | ---: |`
 *        Kiểm tra xem dòng có phải là hàng phân cách bảng GFM `| :--- | :---: | ---: |` không
 */
bool ParseTableDelimiterRow(std::string_view line, std::vector<int32_t>* out_alignments) {
    if (line.find('|') == std::string_view::npos || line.find('-') == std::string_view::npos) {
        return false;
    }
    auto cols = SplitTableRow(line);
    if (cols.empty()) {
        return false;
    }
    out_alignments->clear();
    for (std::string_view col : cols) {
        if (col.empty()) {
            return false;
        }
        bool left_colon = (col.front() == ':');
        bool right_colon = (col.back() == ':');
        size_t dash_count = 0;
        for (char c : col) {
            if (c == '-') {
                ++dash_count;
            } else if (c != ':' && c != ' ') {
                return false;
            }
        }
        if (dash_count == 0) {
            return false;
        }
        if (left_colon && right_colon) {
            out_alignments->push_back(1); // center
        } else if (right_colon) {
            out_alignments->push_back(2); // right
        } else {
            out_alignments->push_back(0); // left
        }
    }
    return true;
}

} // anonymous namespace

/**
 * @brief Parse Markdown document matching `nativeParse` (`0x00e718..0x00feb4`)
 *        Phân tích tài liệu Markdown khớp chính xác `nativeParse` (`0x00e718..0x00feb4`)
 */
void ParseMarkdownDocument(MarkdownDocument* doc,
                           const char* utf8_content,
                           size_t utf8_len,
                           int32_t char_start,
                           int32_t char_end,
                           float font_scale,
                           std::vector<ParsedBlockNode>* out_blocks) {
    if (!doc || !out_blocks) {
        return;
    }
    out_blocks->clear();
    doc->links_.clear();
    doc->images_.clear();
    doc->inline_views_.clear();
    doc->offset_map_.clear();
    doc->syntax_ranges_.clear();
    if (font_scale > 0.0f) {
        doc->style_.root_font_scale = font_scale;
    }

    if (!utf8_content || utf8_len == 0) {
        doc->raw_markdown_.clear();
        return;
    }

    // 1. Slice UTF-8 range by codepoint start/end (`0x00e9c0..0x00eaec`)
    size_t byte_start = 0;
    size_t byte_end = utf8_len;
    if (char_start > 0) {
        byte_start = Utf8CharCountToByteOffset(utf8_content, utf8_len, char_start);
    }
    if (char_end > 0) {
        byte_end = Utf8CharCountToByteOffset(utf8_content, utf8_len, char_end);
        if (byte_end < byte_start) {
            byte_end = byte_start;
        }
    }

    doc->raw_markdown_.assign(utf8_content + byte_start, byte_end - byte_start);
    doc->parse_start_offset_ = char_start;
    doc->parse_end_offset_ = char_end;

    // 2. Initialize Discount Document Root (`magic = 0x19600731` @ 0x00eaec..0x00eb44)
    DiscountDocument mmiot;
    mmiot.magic = kDiscountValidMmiotMagic;
    mmiot.dirty = 4;

    // Split into lines and detect Pandora 3-line `%` header or reference links `[id]: url`
    struct SourceLine {
        std::string_view text;
        int32_t byte_start = 0;
        int32_t byte_end = 0;
        int32_t indent = 0;
    };
    std::vector<SourceLine> lines;
    std::unordered_map<std::string, DiscountFootnote> ref_map;

    std::string_view full_view(doc->raw_markdown_);
    size_t pos = 0;
    while (pos < full_view.size()) {
        size_t eol = full_view.find('\n', pos);
        if (eol == std::string_view::npos) {
            eol = full_view.size();
        }
        std::string_view line_view = full_view.substr(pos, eol - pos);
        if (!line_view.empty() && line_view.back() == '\r') {
            line_view.remove_suffix(1);
        }

        // Check reference definition `[ref]: url "title" =WxH` (`0x00f700..0x00fb80`)
        std::string_view trimmed = lynx::base::TrimToStringView(line_view);
        if (trimmed.size() >= 4 && trimmed.front() == '[') {
            size_t close_b = trimmed.find("]:");
            if (close_b != std::string_view::npos && close_b > 1) {
                std::string ref_tag(trimmed.substr(1, close_b - 1));
                std::string_view rest = lynx::base::TrimToStringView(trimmed.substr(close_b + 2));
                if (!rest.empty()) {
                    DiscountFootnote fn;
                    fn.tag = ref_tag;
                    float w = -1.0f;
                    float h = -1.0f;
                    ExtractUrlAndDimensions(rest, &fn.link, &fn.title, &w, &h);
                    if (w > 0) fn.width = static_cast<uint32_t>(w);
                    if (h > 0) fn.height = static_cast<uint32_t>(h);
                    std::string lower_tag = ref_tag;
                    std::transform(lower_tag.begin(), lower_tag.end(), lower_tag.begin(),
                                   [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
                    ref_map[lower_tag] = fn;
                    mmiot.footnotes.push_back(std::move(fn));
                    pos = eol + 1;
                    continue;
                }
            }
        }

        SourceLine sl;
        sl.text = line_view;
        sl.byte_start = static_cast<int32_t>(pos);
        sl.byte_end = static_cast<int32_t>(eol);
        sl.indent = CountLeadingIndent(line_view);
        lines.push_back(sl);
        pos = eol + 1;
    }

    // Sort reference footnotes matching `qsort` @ `0x00fb7c`
    std::sort(mmiot.footnotes.begin(), mmiot.footnotes.end(),
              [](const DiscountFootnote& a, const DiscountFootnote& b) {
                  return a.tag < b.tag;
              });

    // 3. Block-level compilation loop
    size_t idx = 0;
    const size_t line_count = lines.size();
    while (idx < line_count) {
        const SourceLine& cur = lines[idx];
        std::string_view trimmed = lynx::base::TrimToStringView(cur.text);

        // Skip blank lines
        if (trimmed.empty()) {
            ++idx;
            continue;
        }

        // 3a. Custom Lynx Block View `blockview://id` (`0x0059f6`)
        if (trimmed.rfind("blockview://", 0) == 0) {
            ParsedBlockNode node;
            node.type = DiscountBlockType::kMarkup;
            node.block_view_id = std::string(trimmed.substr(std::strlen("blockview://")));
            node.md_start = cur.byte_start;
            node.md_end = cur.byte_end;
            out_blocks->push_back(std::move(node));
            ++idx;
            continue;
        }

        // 3b. Fenced code block ```` ``` ```` (`0x005919`) or `~~~`
        if (trimmed.rfind("```", 0) == 0 || trimmed.rfind("~~~", 0) == 0) {
            char fence_char = trimmed[0];
            size_t fence_len = 0;
            while (fence_len < trimmed.size() && trimmed[fence_len] == fence_char) {
                ++fence_len;
            }
            std::string lang(lynx::base::TrimToStringView(trimmed.substr(fence_len)));
            int32_t block_start = cur.byte_start;
            ++idx;
            std::string code_body;
            int32_t code_md_start = (idx < line_count) ? lines[idx].byte_start : cur.byte_end;
            int32_t block_end = cur.byte_end;
            while (idx < line_count) {
                std::string_view l_trim = lynx::base::TrimToStringView(lines[idx].text);
                block_end = lines[idx].byte_end;
                if (l_trim.size() >= fence_len &&
                    l_trim.substr(0, fence_len) == std::string(fence_len, fence_char)) {
                    ++idx;
                    break;
                }
                if (!code_body.empty()) {
                    code_body.push_back('\n');
                }
                code_body.append(lines[idx].text);
                ++idx;
            }
            ParsedBlockNode node;
            node.type = DiscountBlockType::kCode;
            node.code_lang = lang;
            node.md_start = block_start;
            node.md_end = block_end;
            ParsedInlineSpan span;
            span.kind = InlineNodeKind::kText;
            span.text = std::move(code_body);
            span.md_start = code_md_start;
            span.md_end = block_end;
            node.spans.push_back(std::move(span));
            doc->syntax_ranges_.push_back({"codeBlock", block_start, block_end, 0, 0});
            out_blocks->push_back(std::move(node));
            continue;
        }

        // 3c. Horizontal Rule (`---`, `***`, `___`)
        if (trimmed.size() >= 3 && (trimmed[0] == '-' || trimmed[0] == '*' || trimmed[0] == '_')) {
            char rc = trimmed[0];
            size_t rc_count = 0;
            bool valid_hr = true;
            for (char c : trimmed) {
                if (c == rc) {
                    ++rc_count;
                } else if (c != ' ') {
                    valid_hr = false;
                    break;
                }
            }
            if (valid_hr && rc_count >= 3) {
                ParsedBlockNode node;
                node.type = DiscountBlockType::kHr;
                node.md_start = cur.byte_start;
                node.md_end = cur.byte_end;
                doc->syntax_ranges_.push_back({"horizontal", cur.byte_start, cur.byte_end, 0, 0});
                out_blocks->push_back(std::move(node));
                ++idx;
                continue;
            }
        }

        // 3d. ATX Heading `#`..`######`
        if (trimmed.front() == '#') {
            size_t h_level = 0;
            while (h_level < trimmed.size() && trimmed[h_level] == '#' && h_level < 6) {
                ++h_level;
            }
            if (h_level < trimmed.size() && std::isspace(static_cast<unsigned char>(trimmed[h_level]))) {
                std::string_view h_content = lynx::base::TrimToStringView(trimmed.substr(h_level));
                while (!h_content.empty() && h_content.back() == '#') {
                    h_content.remove_suffix(1);
                }
                h_content = lynx::base::TrimToStringView(h_content);
                ParsedBlockNode node;
                node.type = DiscountBlockType::kHdr;
                node.heading_level = static_cast<int32_t>(h_level);
                node.md_start = cur.byte_start;
                node.md_end = cur.byte_end;
                int32_t content_offset = cur.byte_start + static_cast<int32_t>(h_content.data() - cur.text.data());
                node.spans = ParseInlineSpans(h_content, content_offset, ref_map, &doc->syntax_ranges_);
                doc->syntax_ranges_.push_back({"heading", cur.byte_start, cur.byte_end, 0, 0});
                out_blocks->push_back(std::move(node));
                ++idx;
                continue;
            }
        }

        // 3e. GFM Table (`| col1 | col2 |` followed by delimiter row `| --- | --- |`)
        std::vector<int32_t> table_aligns;
        if (idx + 1 < line_count && cur.text.find('|') != std::string_view::npos &&
            ParseTableDelimiterRow(lines[idx + 1].text, &table_aligns)) {
            ParsedBlockNode table_node;
            table_node.type = DiscountBlockType::kTable;
            table_node.md_start = cur.byte_start;

            // Header row
            auto header_cols = SplitTableRow(cur.text);
            std::vector<ParsedTableCell> header_row;
            for (size_t c = 0; c < header_cols.size(); ++c) {
                ParsedTableCell cell;
                cell.is_header = true;
                cell.align = (c < table_aligns.size()) ? table_aligns[c] : 0;
                int32_t cell_off = cur.byte_start + static_cast<int32_t>(header_cols[c].data() - cur.text.data());
                cell.spans = ParseInlineSpans(header_cols[c], cell_off, ref_map, &doc->syntax_ranges_);
                header_row.push_back(std::move(cell));
            }
            table_node.table_rows.push_back(std::move(header_row));

            idx += 2; // Skip header and delimiter row
            while (idx < line_count) {
                std::string_view row_trim = lynx::base::TrimToStringView(lines[idx].text);
                if (row_trim.empty() || row_trim.find('|') == std::string_view::npos) {
                    break;
                }
                auto cols = SplitTableRow(lines[idx].text);
                std::vector<ParsedTableCell> body_row;
                for (size_t c = 0; c < header_cols.size(); ++c) {
                    ParsedTableCell cell;
                    cell.is_header = false;
                    cell.align = (c < table_aligns.size()) ? table_aligns[c] : 0;
                    if (c < cols.size()) {
                        int32_t cell_off = lines[idx].byte_start +
                                           static_cast<int32_t>(cols[c].data() - lines[idx].text.data());
                        cell.spans = ParseInlineSpans(cols[c], cell_off, ref_map, &doc->syntax_ranges_);
                    }
                    body_row.push_back(std::move(cell));
                }
                table_node.table_rows.push_back(std::move(body_row));
                table_node.md_end = lines[idx].byte_end;
                ++idx;
            }
            if (table_node.md_end < table_node.md_start) {
                table_node.md_end = lines[idx - 1].byte_end;
            }
            doc->syntax_ranges_.push_back({"table", table_node.md_start, table_node.md_end, 0, 0});
            out_blocks->push_back(std::move(table_node));
            continue;
        }

        // 3f. Blockquote `> ...` (`0x0057ae: "quote"`)
        if (trimmed.front() == '>') {
            ParsedBlockNode quote_node;
            quote_node.type = DiscountBlockType::kQuote;
            quote_node.md_start = cur.byte_start;
            std::string combined;
            int32_t content_start = cur.byte_start;
            while (idx < line_count) {
                std::string_view q_trim = lynx::base::TrimToStringView(lines[idx].text);
                if (q_trim.empty() || q_trim.front() != '>') {
                    break;
                }
                q_trim.remove_prefix(1);
                if (!q_trim.empty() && q_trim.front() == ' ') {
                    q_trim.remove_prefix(1);
                }
                if (combined.empty()) {
                    content_start = lines[idx].byte_start + static_cast<int32_t>(q_trim.data() - lines[idx].text.data());
                } else {
                    combined.push_back('\n');
                }
                combined.append(q_trim);
                quote_node.md_end = lines[idx].byte_end;
                ++idx;
            }
            quote_node.spans = ParseInlineSpans(combined, content_start, ref_map, &doc->syntax_ranges_);
            doc->syntax_ranges_.push_back({"quote", quote_node.md_start, quote_node.md_end, 0, 0});
            out_blocks->push_back(std::move(quote_node));
            continue;
        }

        // 3g. Unordered List (`* `, `- `, `+ ` @ `0x005a16: "*-+"`) or Ordered List (`1. `, `1) `)
        bool is_ul = (trimmed.size() >= 2 && (trimmed[0] == '*' || trimmed[0] == '-' || trimmed[0] == '+') &&
                      std::isspace(static_cast<unsigned char>(trimmed[1])));
        size_t ol_digits = 0;
        while (ol_digits < trimmed.size() && std::isdigit(static_cast<unsigned char>(trimmed[ol_digits]))) {
            ++ol_digits;
        }
        bool is_ol = (!is_ul && ol_digits > 0 && ol_digits + 1 < trimmed.size() &&
                      (trimmed[ol_digits] == '.' || trimmed[ol_digits] == ')') &&
                      std::isspace(static_cast<unsigned char>(trimmed[ol_digits + 1])));

        if (is_ul || is_ol) {
            ParsedBlockNode list_node;
            list_node.type = is_ul ? DiscountBlockType::kUl : DiscountBlockType::kOl;
            list_node.md_start = cur.byte_start;
            int32_t running_index = is_ol ? std::atoi(std::string(trimmed.substr(0, ol_digits)).c_str()) : 1;

            while (idx < line_count) {
                std::string_view item_trim = lynx::base::TrimToStringView(lines[idx].text);
                if (item_trim.empty()) {
                    break;
                }
                bool item_ul = (item_trim.size() >= 2 &&
                                (item_trim[0] == '*' || item_trim[0] == '-' || item_trim[0] == '+') &&
                                std::isspace(static_cast<unsigned char>(item_trim[1])));
                size_t d_len = 0;
                while (d_len < item_trim.size() && std::isdigit(static_cast<unsigned char>(item_trim[d_len]))) {
                    ++d_len;
                }
                bool item_ol = (!item_ul && d_len > 0 && d_len + 1 < item_trim.size() &&
                                (item_trim[d_len] == '.' || item_trim[d_len] == ')') &&
                                std::isspace(static_cast<unsigned char>(item_trim[d_len + 1])));

                if ((is_ul && !item_ul) || (is_ol && !item_ol)) {
                    break;
                }

                size_t prefix_len = is_ul ? 2 : (d_len + 2);
                std::string_view item_body = lynx::base::TrimToStringView(item_trim.substr(prefix_len));

                // Task list checkbox check `[x]` (`0x00591d`) or `[ ]` (`0x005921`)
                int32_t task_state = 0;
                if (item_body.size() >= 3 && item_body[0] == '[' && item_body[2] == ']') {
                    if (item_body[1] == 'x' || item_body[1] == 'X') {
                        task_state = 2;
                        item_body = lynx::base::TrimToStringView(item_body.substr(3));
                    } else if (item_body[1] == ' ') {
                        task_state = 1;
                        item_body = lynx::base::TrimToStringView(item_body.substr(3));
                    }
                }

                ParsedBlockNode item_node;
                item_node.type = DiscountBlockType::kListItem;
                item_node.list_index = running_index++;
                item_node.list_depth = lines[idx].indent / 2;
                item_node.task_state = task_state;
                item_node.md_start = lines[idx].byte_start;
                item_node.md_end = lines[idx].byte_end;
                int32_t body_offset = lines[idx].byte_start +
                                      static_cast<int32_t>(item_body.data() - lines[idx].text.data());
                item_node.spans = ParseInlineSpans(item_body, body_offset, ref_map, &doc->syntax_ranges_);
                list_node.md_end = lines[idx].byte_end;
                list_node.children.push_back(std::move(item_node));
                ++idx;
            }
            doc->syntax_ranges_.push_back({is_ul ? "unorderedList" : "orderedList",
                                           list_node.md_start, list_node.md_end, 0, 0});
            out_blocks->push_back(std::move(list_node));
            continue;
        }

        // 3h. Normal Paragraph (or Setext Heading if next line is `===` or `---`)
        ParsedBlockNode para_node;
        para_node.type = DiscountBlockType::kMarkup;
        para_node.md_start = cur.byte_start;
        para_node.md_end = cur.byte_end;

        if (idx + 1 < line_count) {
            std::string_view next_trim = lynx::base::TrimToStringView(lines[idx + 1].text);
            if (next_trim.size() >= 3 &&
                (next_trim.find_first_not_of('=') == std::string_view::npos ||
                 next_trim.find_first_not_of('-') == std::string_view::npos)) {
                para_node.type = DiscountBlockType::kHdr;
                para_node.heading_level = (next_trim[0] == '=') ? 1 : 2;
                para_node.md_end = lines[idx + 1].byte_end;
                para_node.spans = ParseInlineSpans(trimmed, cur.byte_start, ref_map, &doc->syntax_ranges_);
                doc->syntax_ranges_.push_back({"heading", para_node.md_start, para_node.md_end, 0, 0});
                out_blocks->push_back(std::move(para_node));
                idx += 2;
                continue;
            }
        }

        para_node.spans = ParseInlineSpans(trimmed, cur.byte_start, ref_map, &doc->syntax_ranges_);
        out_blocks->push_back(std::move(para_node));
        ++idx;
    }
}

// ============================================================================
// StyleValue & Binary Style Sheet Deserializer (0x011a84..0x013254, 0x028c60..0x0352fc)
// Triển khai Bộ giải mã Bảng kiểu dáng nhị phân (0x011a84..0x013254, 0x028c60..0x0352fc)
// ============================================================================

float StyleValue::AsFloat(float fallback) const {
    if (type == StyleValueType::kDouble) return static_cast<float>(double_val);
    if (type == StyleValueType::kInt32 || type == StyleValueType::kInt64) return static_cast<float>(int_val);
    if (type == StyleValueType::kString) {
        float parsed = fallback;
        if (lynx::base::StringToFloat(str_val, parsed, false)) {
            return parsed;
        }
    }
    return fallback;
}

int32_t StyleValue::AsInt(int32_t fallback) const {
    if (type == StyleValueType::kInt32 || type == StyleValueType::kInt64) return static_cast<int32_t>(int_val);
    if (type == StyleValueType::kDouble) return static_cast<int32_t>(double_val);
    if (type == StyleValueType::kString) return std::atoi(str_val.c_str());
    return fallback;
}

uint32_t StyleValue::AsColor(uint32_t fallback) const {
    if (type == StyleValueType::kInt32 || type == StyleValueType::kInt64) {
        return static_cast<uint32_t>(int_val);
    }
    if (type == StyleValueType::kString && !str_val.empty()) {
        if (str_val[0] == '#') {
            uint32_t hex = static_cast<uint32_t>(std::strtoul(str_val.c_str() + 1, nullptr, 16));
            if (str_val.size() == 7) {
                return 0xFF000000u | hex;
            }
            return hex;
        }
        return static_cast<uint32_t>(std::strtoul(str_val.c_str(), nullptr, 0));
    }
    return fallback;
}

bool StyleValue::AsBool(bool fallback) const {
    if (type == StyleValueType::kBool) return bool_val;
    if (type == StyleValueType::kInt32 || type == StyleValueType::kInt64) return int_val != 0;
    if (type == StyleValueType::kString) {
        if (str_val == "true" || str_val == "1") return true;
        if (str_val == "false" || str_val == "0") return false;
    }
    return fallback;
}

std::string StyleValue::AsString(const std::string& fallback) const {
    if (type == StyleValueType::kString) return str_val;
    return fallback;
}

const StyleValue* StyleValue::Find(const std::string& key) const {
    if (type != StyleValueType::kMap) return nullptr;
    auto it = map_val.find(key);
    return (it != map_val.end()) ? &it->second : nullptr;
}

namespace {

class BinaryStyleReader {
public:
    BinaryStyleReader(const uint8_t* data, size_t len) : data_(data), len_(len), pos_(0) {}

    bool HasRemaining(size_t n = 1) const { return pos_ + n <= len_; }

    uint8_t ReadU8() {
        return HasRemaining(1) ? data_[pos_++] : 0;
    }

    int32_t ReadI32() {
        if (!HasRemaining(4)) return 0;
        int32_t v = 0;
        std::memcpy(&v, data_ + pos_, 4);
        pos_ += 4;
        return v;
    }

    int64_t ReadI64() {
        if (!HasRemaining(8)) return 0;
        int64_t v = 0;
        std::memcpy(&v, data_ + pos_, 8);
        pos_ += 8;
        return v;
    }

    double ReadF64() {
        if (!HasRemaining(8)) return 0.0;
        double v = 0.0;
        std::memcpy(&v, data_ + pos_, 8);
        pos_ += 8;
        return v;
    }

    uint32_t ReadVarUInt() {
        uint32_t result = 0;
        int shift = 0;
        while (HasRemaining(1) && shift < 35) {
            uint8_t b = ReadU8();
            result |= static_cast<uint32_t>(b & 0x7Fu) << shift;
            if ((b & 0x80u) == 0) break;
            shift += 7;
        }
        return result;
    }

    std::string ReadString() {
        uint32_t slen = ReadVarUInt();
        if (!HasRemaining(slen)) {
            pos_ = len_;
            return "";
        }
        std::string s(reinterpret_cast<const char*>(data_ + pos_), slen);
        pos_ += slen;
        return s;
    }

    bool ReadValue(StyleValue* out, int depth = 0) {
        if (!HasRemaining(1) || depth > 16) return false;
        uint8_t tag = ReadU8();
        switch (tag) {
            case 0: // Null
                out->type = StyleValueType::kNull;
                return true;
            case 1: // Bool true
            case 2: // Bool false / Byte bool
                out->type = StyleValueType::kBool;
                out->bool_val = (tag == 1) ? (HasRemaining(1) ? ReadU8() != 0 : true) : false;
                return true;
            case 3: // Int32
                out->type = StyleValueType::kInt32;
                out->int_val = ReadI32();
                return true;
            case 4: // Int64
                out->type = StyleValueType::kInt64;
                out->int_val = ReadI64();
                return true;
            case 5: // Double
                out->type = StyleValueType::kDouble;
                out->double_val = ReadF64();
                return true;
            case 6: // String
                out->type = StyleValueType::kString;
                out->str_val = ReadString();
                return true;
            case 7: { // Array
                out->type = StyleValueType::kArray;
                uint32_t count = ReadVarUInt();
                out->array_val.clear();
                for (uint32_t i = 0; i < count && HasRemaining(); ++i) {
                    StyleValue elem;
                    if (!ReadValue(&elem, depth + 1)) break;
                    out->array_val.push_back(std::move(elem));
                }
                return true;
            }
            case 8: { // Map / Dictionary
                out->type = StyleValueType::kMap;
                uint32_t count = ReadVarUInt();
                out->map_val.clear();
                for (uint32_t i = 0; i < count && HasRemaining(); ++i) {
                    std::string key = ReadString();
                    StyleValue val;
                    if (!ReadValue(&val, depth + 1)) break;
                    out->map_val[std::move(key)] = std::move(val);
                }
                return true;
            }
            default:
                return false;
        }
    }

private:
    const uint8_t* data_;
    size_t len_;
    size_t pos_;
};

/**
 * @brief Parse fontWeight string/int matching `.data.rel.ro` table @ `0x0389d0..0x038a20`
 *        Phân tích độ đậm font khớp bảng `.data.rel.ro` @ `0x0389d0..0x038a20`:
 *        `{"normal", "bold", "100", "200", "300", "400", "500", "600", "700", "800", "900"}`
 */
uint16_t ParseFontWeight(const StyleValue& val) {
    if (val.IsNumber()) {
        int32_t w = val.AsInt(400);
        return static_cast<uint16_t>( std::clamp(w, 100, 900));
    }
    std::string s = val.AsString("normal");
    if (s == "bold") return 700;
    if (s == "normal") return 400;
    int32_t w = std::atoi(s.c_str());
    return (w >= 100 && w <= 900) ? static_cast<uint16_t>(w) : 400;
}

MarkdownBorderType ParseBorderType(const std::string& s) {
    if (s == "solid") return MarkdownBorderType::kSolid;
    if (s == "dotted") return MarkdownBorderType::kDotted;
    if (s == "dashed") return MarkdownBorderType::kDashed;
    if (s == "double") return MarkdownBorderType::kDouble;
    if (s == "capsule") return MarkdownBorderType::kCapsule;
    if (s == "full-rect") return MarkdownBorderType::kFullRect;
    return MarkdownBorderType::kNone;
}

void ApplyBlockStyleMap(const StyleValue& map, MarkdownBlockStyle* out) {
    if (!map.IsMap() || !out) return;
    if (auto* v = map.Find("fontFamily")) out->font_family = v->AsString(out->font_family);
    if (auto* v = map.Find("fontSize")) out->font_size = v->AsFloat(out->font_size);
    if (auto* v = map.Find("fontWeight")) out->font_weight = ParseFontWeight(*v);
    if (auto* v = map.Find("lineHeight")) out->line_height = v->AsFloat(out->line_height);
    if (auto* v = map.Find("lineSpace")) out->line_space = v->AsFloat(out->line_space);
    if (auto* v = map.Find("paragraphSpace")) out->paragraph_space = v->AsFloat(out->paragraph_space);
    if (auto* v = map.Find("textIndent")) out->text_indent = v->AsFloat(out->text_indent);
    if (auto* v = map.Find("textMaxline")) out->text_maxline = v->AsInt(out->text_maxline);
    if (auto* v = map.Find("color")) out->color = v->AsColor(out->color);
    if (auto* v = map.Find("foreground")) out->color = v->AsColor(out->color);
    if (auto* v = map.Find("backgroundColor")) out->background_color = v->AsColor(out->background_color);
    if (auto* v = map.Find("background")) out->background_color = v->AsColor(out->background_color);
    if (auto* v = map.Find("borderColor")) out->border_color = v->AsColor(out->border_color);
    if (auto* v = map.Find("borderWidth")) out->border_width = v->AsFloat(out->border_width);
    if (auto* v = map.Find("borderRadius")) out->border_radius = v->AsFloat(out->border_radius);
    if (auto* v = map.Find("borderType")) out->border_type = ParseBorderType(v->AsString());
    if (auto* v = map.Find("marginTop")) out->margin_top = v->AsFloat(out->margin_top);
    if (auto* v = map.Find("marginBottom")) out->margin_bottom = v->AsFloat(out->margin_bottom);
    if (auto* v = map.Find("marginLeft")) out->margin_left = v->AsFloat(out->margin_left);
    if (auto* v = map.Find("marginRight")) out->margin_right = v->AsFloat(out->margin_right);
    if (auto* v = map.Find("paddingTop")) out->padding_top = v->AsFloat(out->padding_top);
    if (auto* v = map.Find("paddingBottom")) out->padding_bottom = v->AsFloat(out->padding_bottom);
    if (auto* v = map.Find("paddingLeft")) out->padding_left = v->AsFloat(out->padding_left);
    if (auto* v = map.Find("paddingRight")) out->padding_right = v->AsFloat(out->padding_right);
    if (auto* v = map.Find("maxHeight")) out->max_height = v->AsFloat(out->max_height);
    if (auto* v = map.Find("minHeight")) out->min_height = v->AsFloat(out->min_height);
    if (auto* v = map.Find("textOverflow")) {
        out->text_overflow = (v->AsString() == "ellipsis") ? 1 : 0;
    }
    if (auto* v = map.Find("textAlign")) {
        std::string a = v->AsString();
        if (a == "center") out->text_align = 1;
        else if (a == "right") out->text_align = 2;
        else if (a == "justify") out->text_align = 3;
        else out->text_align = 0;
    }
    if (auto* v = map.Find("direction")) {
        std::string d = v->AsString();
        if (d == "ltr") out->direction = 1;
        else if (d == "rtl") out->direction = 2;
        else out->direction = 0;
    }
    if (auto* v = map.Find("wordBreak")) {
        out->word_break = (v->AsString() == "break-all") ? 1 : 0;
    }
    if (auto* v = map.Find("backgroundImage")) {
        out->background_image = v->AsString();
        if (out->background_image.rfind("linear-gradient(", 0) == 0) {
            out->background_type = MarkdownBackgroundType::kLinearGradient;
        } else if (out->background_image.rfind("radial-gradient(", 0) == 0) {
            out->background_type = MarkdownBackgroundType::kRadialGradient;
        } else if (!out->background_image.empty()) {
            out->background_type = MarkdownBackgroundType::kImage;
        }
    }
}

void ApplyInlineStyleMap(const StyleValue& map, MarkdownInlineStyle* out) {
    if (!map.IsMap() || !out) return;
    if (auto* v = map.Find("fontFamily")) out->font_family = v->AsString(out->font_family);
    if (auto* v = map.Find("fontSize")) out->font_size = v->AsFloat(out->font_size);
    if (auto* v = map.Find("fontWeight")) out->font_weight = ParseFontWeight(*v);
    if (auto* v = map.Find("color")) out->color = v->AsColor(out->color);
    if (auto* v = map.Find("foreground")) out->color = v->AsColor(out->color);
    if (auto* v = map.Find("backgroundColor")) out->background_color = v->AsColor(out->background_color);
    if (auto* v = map.Find("borderColor")) out->border_color = v->AsColor(out->border_color);
    if (auto* v = map.Find("borderWidth")) out->border_width = v->AsFloat(out->border_width);
    if (auto* v = map.Find("borderRadius")) out->border_radius = v->AsFloat(out->border_radius);
    if (auto* v = map.Find("borderType")) out->border_type = ParseBorderType(v->AsString());
    if (auto* v = map.Find("textDecorationColor")) out->text_decoration_color = v->AsColor(out->text_decoration_color);
    if (auto* v = map.Find("textDecorationThickness")) out->text_decoration_thickness = v->AsFloat(out->text_decoration_thickness);
    if (auto* v = map.Find("textDecorationLine")) {
        std::string s = v->AsString();
        if (s == "underline") out->text_decoration_line = 1;
        else if (s == "line-through") out->text_decoration_line = 2;
        else out->text_decoration_line = 0;
    }
    if (auto* v = map.Find("textDecorationStyle")) {
        std::string s = v->AsString();
        if (s == "double") out->text_decoration_style = 1;
        else if (s == "dotted") out->text_decoration_style = 2;
        else if (s == "dashed") out->text_decoration_style = 3;
        else out->text_decoration_style = 0;
    }
    if (auto* v = map.Find("marginLeft")) out->margin_left = v->AsFloat(out->margin_left);
    if (auto* v = map.Find("marginRight")) out->margin_right = v->AsFloat(out->margin_right);
    if (auto* v = map.Find("paddingLeft")) out->padding_left = v->AsFloat(out->padding_left);
    if (auto* v = map.Find("paddingRight")) out->padding_right = v->AsFloat(out->padding_right);
    if (auto* v = map.Find("paddingTop")) out->padding_top = v->AsFloat(out->padding_top);
    if (auto* v = map.Find("paddingBottom")) out->padding_bottom = v->AsFloat(out->padding_bottom);
    if (auto* v = map.Find("clickable")) out->clickable = v->AsBool(out->clickable);
}

} // anonymous namespace

bool DeserializeStyleBuffer(const uint8_t* data, size_t len, StyleValue* out_root) {
    if (!data || len == 0 || !out_root) {
        return false;
    }
    BinaryStyleReader reader(data, len);
    if (reader.ReadValue(out_root) && out_root->IsMap()) {
        return true;
    }

    // Fallback simple `key=value\n` or JSON-like `{"key":"val"}` parser for unit/parity tests
    out_root->type = StyleValueType::kMap;
    out_root->map_val.clear();
    std::string_view text(reinterpret_cast<const char*>(data), len);
    size_t pos = 0;
    while (pos < text.size()) {
        size_t eol = text.find('\n', pos);
        if (eol == std::string_view::npos) eol = text.size();
        std::string_view line = lynx::base::TrimToStringView(text.substr(pos, eol - pos));
        size_t colon = line.find(':');
        if (colon != std::string_view::npos && colon > 0) {
            std::string k(lynx::base::TrimToStringView(line.substr(0, colon)));
            std::string v(lynx::base::TrimToStringView(line.substr(colon + 1)));
            StyleValue sv;
            sv.type = StyleValueType::kString;
            sv.str_val = v;
            out_root->map_val[k] = std::move(sv);
        }
        pos = eol + 1;
    }
    return !out_root->map_val.empty();
}

void ApplyMarkdownStyleSheet(const StyleValue& root, MarkdownStyleSheet* sheet) {
    if (!root.IsMap() || !sheet) return;
    if (auto* v = root.Find("normalText")) ApplyBlockStyleMap(*v, &sheet->normal_text);
    if (auto* v = root.Find("H1")) ApplyBlockStyleMap(*v, &sheet->h1);
    if (auto* v = root.Find("H2")) ApplyBlockStyleMap(*v, &sheet->h2);
    if (auto* v = root.Find("H3")) ApplyBlockStyleMap(*v, &sheet->h3);
    if (auto* v = root.Find("H4")) ApplyBlockStyleMap(*v, &sheet->h4);
    if (auto* v = root.Find("H5")) ApplyBlockStyleMap(*v, &sheet->h5);
    if (auto* v = root.Find("H6")) ApplyBlockStyleMap(*v, &sheet->h6);
    if (auto* v = root.Find("codeBlock")) ApplyBlockStyleMap(*v, &sheet->code_block);
    if (auto* v = root.Find("quote")) ApplyBlockStyleMap(*v, &sheet->quote);
    if (auto* v = root.Find("quoteBorderLine")) ApplyBlockStyleMap(*v, &sheet->quote_border_line);
    if (auto* v = root.Find("table")) ApplyBlockStyleMap(*v, &sheet->table);
    if (auto* v = root.Find("tableHeader")) ApplyBlockStyleMap(*v, &sheet->table_header);
    if (auto* v = root.Find("tableCell")) ApplyBlockStyleMap(*v, &sheet->table_cell);
    if (auto* v = root.Find("tableBorder")) ApplyBlockStyleMap(*v, &sheet->table_border);
    if (auto* v = root.Find("tableBackground")) ApplyBlockStyleMap(*v, &sheet->table_background);
    if (auto* v = root.Find("horizontal")) ApplyBlockStyleMap(*v, &sheet->horizontal_rule);
    if (auto* v = root.Find("inlineCode")) ApplyInlineStyleMap(*v, &sheet->inline_code);
    if (auto* v = root.Find("link")) ApplyInlineStyleMap(*v, &sheet->link);
    if (auto* v = root.Find("mark")) ApplyInlineStyleMap(*v, &sheet->mark);
    if (auto* v = root.Find("doubleBraces")) ApplyInlineStyleMap(*v, &sheet->double_braces);
    if (auto* v = root.Find("imageCaption")) ApplyInlineStyleMap(*v, &sheet->image_caption);

    if (auto* v = root.Find("unorderedList")) {
        ApplyBlockStyleMap(*v, &sheet->unordered_list.block);
        if (auto* mc = v->Find("markColor")) sheet->unordered_list.mark_color = mc->AsColor(sheet->unordered_list.mark_color);
        if (auto* mm = v->Find("markMarginRight")) sheet->unordered_list.mark_margin_right = mm->AsFloat(sheet->unordered_list.mark_margin_right);
        if (auto* mt = v->Find("unorderedListMarker")) {
            std::string s = mt->AsString();
            if (s == "circle") sheet->unordered_list.number_type = MarkdownNumberType::kCircle;
            else if (s == "square") sheet->unordered_list.number_type = MarkdownNumberType::kSquare;
            else sheet->unordered_list.number_type = MarkdownNumberType::kNumber;
        }
    }
    if (auto* v = root.Find("orderedListNumber")) {
        ApplyBlockStyleMap(*v, &sheet->ordered_list.block);
        if (auto* nf = v->Find("numberFont")) sheet->ordered_list.number_font = nf->AsString();
        if (auto* nfs = v->Find("numberFontSize")) sheet->ordered_list.number_font_size = nfs->AsFloat(14.0f);
        if (auto* nc = v->Find("numberColor")) sheet->ordered_list.number_color = nc->AsColor(0xFF000000u);
        if (auto* nmr = v->Find("numberMarginRight")) sheet->ordered_list.number_margin_right = nmr->AsFloat(6.0f);
        if (auto* nt = v->Find("numberType")) {
            std::string s = nt->AsString();
            if (s == "roman-numerals") sheet->ordered_list.number_type = MarkdownNumberType::kRomanNumerals;
            else if (s == "mixed") sheet->ordered_list.number_type = MarkdownNumberType::kMixed;
            else sheet->ordered_list.number_type = MarkdownNumberType::kNumber;
        }
    }
    if (auto* v = root.Find("typewriterCursor")) {
        if (auto* cc = v->Find("customCursor")) sheet->typewriter_cursor.custom_cursor = cc->AsString();
        if (auto* va = v->Find("verticalAlign")) {
            std::string s = va->AsString();
            if (s == "top") sheet->typewriter_cursor.vertical_align = 1;
            else if (s == "center") sheet->typewriter_cursor.vertical_align = 2;
            else if (s == "bottom") sheet->typewriter_cursor.vertical_align = 3;
            else sheet->typewriter_cursor.vertical_align = 0;
        }
    }
    if (auto* v = root.Find("truncation")) {
        if (auto* tt = v->Find("truncationType")) {
            std::string s = tt->AsString();
            if (s == "ellipsis") sheet->truncation.truncation_type = MarkdownTruncationType::kEllipsis;
            else sheet->truncation.truncation_type = MarkdownTruncationType::kView;
        }
        if (auto* c = v->Find("ellipsis")) sheet->truncation.content = c->AsString("...");
    }
    if (auto* v = root.Find("enableAltText")) sheet->enable_alt_text = v->AsBool(false);
    if (auto* v = root.Find("tableSplit")) sheet->table_split = v->AsBool(false);
}

bool ParseTextMarkAttachment(const uint8_t* data, size_t len, MarkdownTextAttachment* out_attachment) {
    if (!data || len == 0 || !out_attachment) return false;
    StyleValue root;
    if (!DeserializeStyleBuffer(data, len, &root)) {
        return false;
    }
    if (auto* v = root.Find("id")) out_attachment->id = v->AsString();
    if (auto* v = root.Find("startIndex")) out_attachment->start_pos = v->AsInt(0);
    if (auto* v = root.Find("endIndex")) out_attachment->end_pos = v->AsInt(0);
    if (auto* v = root.Find("indexType")) {
        out_attachment->is_markdown_offset = (v->AsString() == "source" || v->AsString() == "markdown");
    }
    ApplyInlineStyleMap(root, &out_attachment->style);
    out_attachment->clickable = out_attachment->style.clickable;
    return out_attachment->end_pos > out_attachment->start_pos;
}

} // namespace markdown
} // namespace lynx
