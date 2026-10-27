/**
 * @file lynx_markdown_pseudocode.cpp
 * @brief Clean-Room C++17 Verification Harness & Opcode-Accurate Behavioral Reconstruction for liblynx_markdown.so
 *        Bộ kiểm tra xác minh C++17 Tái cấu trúc sạch & đối chiếu hành vi mức mã máy AArch64 cho liblynx_markdown.so
 *
 * Binary Target / Đích nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/liblynx_markdown.so (247,888 bytes)
 *   SHA-256: 3f238dfc468cd0b314eb0b828565c3353dba165c20dab0bb76d9957760bd9a2d
 */

#include "lynx_markdown_interface.h"

namespace lynx {
namespace markdown {

bool RunLynxMarkdownSelfTest() {
    // 1. Verify Roman Numeral conversion matching .data.rel.ro tables @ 0x038668..0x038750
    if (FormatRomanNumeral(1) != "I" ||
        FormatRomanNumeral(4) != "IV" ||
        FormatRomanNumeral(9) != "IX" ||
        FormatRomanNumeral(49) != "XLIX" ||
        FormatRomanNumeral(99) != "XCIX" ||
        FormatRomanNumeral(2026) != "MMXXVI") {
        return false;
    }

    // 2. Verify UTF-8 codepoint boundary slicer matching 0x00e9c0..0x00eaec
    const char* sample_u8 = "A\xC3\xA9\xE4\xB8\xAD\xF0\x9F\x98\x80Z"; // 'A'(1) + 'é'(2) + '中'(3) + '😀'(4) + 'Z'(1) = 11 bytes, 5 chars
    const size_t sample_len = std::strlen(sample_u8);
    if (Utf8CharCountToByteOffset(sample_u8, sample_len, 1) != 1 ||
        Utf8CharCountToByteOffset(sample_u8, sample_len, 2) != 3 ||
        Utf8CharCountToByteOffset(sample_u8, sample_len, 3) != 6 ||
        Utf8CharCountToByteOffset(sample_u8, sample_len, 4) != 10 ||
        Utf8CharCountToByteOffset(sample_u8, sample_len, 5) != 11) {
        return false;
    }

    // 3. Create MarkdownDocument via JNI entry point @ 0x00d300
    jlong handle = Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeCreateInstance(nullptr, nullptr);
    if (handle == 0) {
        return false;
    }

    Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeAllowBreakAroundPunctuation(
        nullptr, nullptr, handle, 1);

    const char* md_doc =
        "# NextAI OpenCut Markdown\n\n"
        "Paragraph with **bold**, *italic*, `inlineCode`, {{doubleBraces}}, and [OpenCut](https://nextai.tech).\n\n"
        "- [x] Task item 1\n"
        "- [ ] Task item 2\n\n"
        "| Engine | Status |\n"
        "| :--- | :---: |\n"
        "| TTText | Ready |\n\n"
        "```cpp\n"
        "int main() { return 0; }\n"
        "```\n";

    Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeParse(
        nullptr, nullptr, handle,
        reinterpret_cast<jstring>(const_cast<char*>(md_doc)),
        0, -1, 1.0f);

    jlong packed_size = Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeLayout(
        nullptr, nullptr, handle, 360.0f, 1000.0f, -1);
    if (packed_size == 0) {
        Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeDestroyInstance(nullptr, nullptr, handle);
        return false;
    }

    jint region_count = Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetRegionCount(
        nullptr, nullptr, handle);
    jint extra_count = Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetExtraContentCount(
        nullptr, nullptr, handle);
    jint page_chars = Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeGetPageCharCount(
        nullptr, nullptr, handle);
    jint mapped_char = Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeMarkdownOffsetToChar(
        nullptr, nullptr, handle, 30);

    auto* doc = reinterpret_cast<MarkdownDocument*>(static_cast<uintptr_t>(handle));
    std::vector<uint8_t> draw_stream = DrawMarkdownPageWithCursorToBuffer(doc, 24, true);

    bool ok = (region_count >= 4) && (extra_count >= 2) && (page_chars > 20) &&
              (mapped_char >= 0) && (!draw_stream.empty());

    Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeDestroyInstance(nullptr, nullptr, handle);
    return ok;
}

} // namespace markdown
} // namespace lynx
