// ============================================================================
// File: serval_svg_interface.h
// Target: libserval_svg.so (282,912 bytes / 0x45120, SHA-256: 742e48019f3701911055dc50691d61bb7b517be98800be8b0dcdf9918f0d296a)
// Classification: OBSERVED (Unified Public C/C++17 Header for ByteDance Lynx Serval SVG)
// ============================================================================
// [EN] Master interface header combining all ABI structures, 147 named color
//      tables, 33 exported .dynsym C-ABI functions, SVG DOM tree classes,
//      SrAndroidCanvas JNI bridge, and deterministic verification entrypoints.
// [VN] Header giao diện tổng hợp toàn bộ cấu trúc ABI, bảng 147 màu định danh,
//      33 hàm/đối tượng C-ABI xuất khẩu trong .dynsym, cây lớp SVG DOM,
//      cầu nối JNI SrAndroidCanvas, và các điểm vào kiểm thử tất định.
// ============================================================================

#pragma once

#include "serval_svg_types.h"
#include "serval_svg_rodata_tables.h"
#include "serval_svg_math_and_parser.h"
#include "serval_svg_dom_and_jni.h"

namespace serval {
namespace svg {

struct ServalSvgSelfTestReport {
    uint32_t total_checks = 0;
    uint32_t passed_checks = 0;
    uint32_t failed_checks = 0;
    uint32_t verified_named_colors = 0;
    uint32_t verified_exported_symbols = 0;
    float    sample_viewbox_xform[6] = { 0.0f };
    float    sample_circle_bezier_ctrl = 0.0f;
    float    sample_diag_percent_px = 0.0f;
};

// [EN] Runs the complete deterministic mathematical & DOM verification suite
//      across all 33 .dynsym exports of libserval_svg.so.
// [VN] Chạy bộ kiểm thử toán học & cây DOM tất định trên toàn bộ 33 biểu tượng
//      xuất khẩu trong .dynsym của libserval_svg.so.
ServalSvgSelfTestReport run_serval_svg_self_verification() noexcept;

} // namespace svg
} // namespace serval
