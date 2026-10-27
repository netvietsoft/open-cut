/**
 * @file lynx_markdown_interface.h
 * @brief Unified Public C++17 Umbrella Header for liblynx_markdown.so Reconstruction
 *        Header C++17 hợp nhất công khai cho bản tái dựng sạch liblynx_markdown.so
 *
 * Binary Target / Đích nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/liblynx_markdown.so (247,888 bytes)
 *   SHA-256: 3f238dfc468cd0b314eb0b828565c3353dba165c20dab0bb76d9957760bd9a2d
 */

#pragma once

#include "lynx_markdown_types.h"
#include "lynx_markdown_parser.h"
#include "lynx_markdown_layout_draw.h"
#include "lynx_markdown_jni.h"

namespace lynx {
namespace markdown {

/**
 * @brief Run end-to-end self-verification of Markdown parsing, Roman numerals, offset binary search,
 *        layout, typewriter cursor, and BufferCanvasHelper stream serialization.
 *        Chạy tự kiểm tra đầu-cuối cho phân tích Markdown, số La Mã, tìm kiếm nhị phân offset,
 *        dàn trang, con trỏ máy chữ và luồng vẽ BufferCanvasHelper.
 */
bool RunLynxMarkdownSelfTest();

} // namespace markdown
} // namespace lynx
