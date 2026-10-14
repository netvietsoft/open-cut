// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libmiddleware.so (ByteDance Retouch & CrossPlatform NLE Middleware)
// File: middleware_text_template.h
// Description: Kinetic Typography, Text Template Layout Engine, and Font Resolver
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>
#include <mutex>
#include "middleware_types.h"

namespace retouch::middleware {

/**
 * @brief Kiểu căn lề văn bản (Text Horizontal Alignment)
 */
enum class TextAlignment : int32_t {
    LEFT = 0,       ///< Căn lề trái / Align Left
    CENTER = 1,     ///< Căn lề giữa / Align Center
    RIGHT = 2,      ///< Căn lề phải / Align Right
    JUSTIFY = 3     ///< Căn đều hai bên / Justify
};

/**
 * @brief Định nghĩa Font chữ trong danh mục (Font catalog entry)
 */
struct TextFontEntry {
    int32_t font_id{0};             ///< Định danh font / Font unique identifier
    std::string font_family;        ///< Họ phông chữ / Font family name (e.g. "Roboto", "Montserrat")
    std::string font_path;          ///< Đường dẫn tệp phông (.ttf/.otf) / Font file path
    bool is_bold{false};            ///< Chữ đậm / Bold flag
    bool is_italic{false};          ///< Chữ nghiêng / Italic flag
    float ascent{0.0f};             ///< Khoảng trần font / Font ascent metric
    float descent{0.0f};            ///< Khoảng đáy font / Font descent metric

    TextFontEntry() = default;
    TextFontEntry(int32_t id, const std::string& family, const std::string& path, bool bold = false, bool italic = false)
        : font_id(id), font_family(family), font_path(path), is_bold(bold), is_italic(italic) {}
};

/**
 * @brief Một phần tử văn bản trong mẫu động (Single text slot within kinetic template)
 */
struct TextTemplateItem {
    int32_t slot_index{0};          ///< Chỉ số vị trí / Slot index
    std::string title_text;         ///< Nội dung chữ / Display text content
    int32_t font_index{0};          ///< Chỉ mục font / Font index in template catalog
    std::string font_family;        ///< Tên họ phông / Font family name
    std::string font_path;          ///< Đường dẫn phông / Font file path
    float font_size{32.0f};         ///< Cỡ chữ (pixel) / Font size in pixels
    float tracking{0.0f};           ///< Khoảng cách ký tự / Letter spacing (tracking)
    float line_spacing{1.2f};       ///< Khoảng cách dòng / Line height multiplier
    TextAlignment alignment{TextAlignment::CENTER}; ///< Căn lề / Text alignment

    // Thuộc tính màu sắc RGBA [0.0f, 1.0f]
    float color_r{1.0f};            ///< Màu chữ đỏ / Text color Red
    float color_g{1.0f};            ///< Màu chữ lục / Text color Green
    float color_b{1.0f};            ///< Màu chữ lam / Text color Blue
    float color_a{1.0f};            ///< Độ mờ chữ / Text Alpha

    // Viền chữ (Stroke/Outline)
    bool has_stroke{false};         ///< Có viền chữ hay không / Enable text stroke
    float stroke_width{0.0f};       ///< Độ dày viền / Stroke width
    float stroke_r{0.0f};           ///< Màu viền đỏ / Stroke color Red
    float stroke_g{0.0f};           ///< Màu viền lục / Stroke color Green
    float stroke_b{0.0f};           ///< Màu viền lam / Stroke color Blue
    float stroke_a{1.0f};           ///< Độ mờ viền / Stroke Alpha

    // Đổ bóng (Drop Shadow)
    bool has_shadow{false};         ///< Có bóng đổ / Enable drop shadow
    float shadow_dx{0.0f};          ///< Dời bóng X / Shadow offset X
    float shadow_dy{0.0f};          ///< Dời bóng Y / Shadow offset Y
    float shadow_blur{0.0f};        ///< Độ mờ nhòe bóng / Shadow blur radius
    float shadow_r{0.0f};           ///< Màu bóng đỏ / Shadow color Red
    float shadow_g{0.0f};           ///< Màu bóng lục / Shadow color Green
    float shadow_b{0.0f};           ///< Màu bóng lam / Shadow color Blue
    float shadow_a{0.5f};           ///< Độ mờ bóng / Shadow Alpha

    // Biến đổi không gian và bao đóng
    PointF position{0.0f, 0.0f};    ///< Tọa độ neo / Anchor position
    PointF scale{1.0f, 1.0f};       ///< Tỷ lệ phóng / Scale factor
    float rotation_deg{0.0f};       ///< Góc xoay độ / Rotation in degrees
    RectF bounding_box{0.0f, 0.0f, 0.0f, 0.0f}; ///< Khung bao tính toán / Computed bounding box

    TextTemplateItem() = default;
};

/**
 * @brief Mẫu văn bản hoàn chỉnh chứa nhiều slot (Kinetic Text Template Model)
 */
struct TextTemplateModel {
    int32_t template_id{0};                     ///< Mã định danh mẫu / Unique template ID
    std::string template_name;                  ///< Tên mẫu hiển thị / Display template name
    std::vector<TextTemplateItem> items;        ///< Danh sách các đoạn văn bản / Text items
    std::vector<TextFontEntry> font_catalog;    ///< Bảng danh mục font hỗ trợ / Supported font catalog
    int64_t duration_ms{3000};                  ///< Thời lượng hiệu ứng ms / Animation duration in ms
    int32_t anim_preset_id{0};                  ///< Mã kiểu hoạt họa / Animation preset identifier
    float canvas_aspect_ratio{16.0f / 9.0f};   ///< Tỷ lệ khung hình / Target canvas aspect ratio

    TextTemplateModel() = default;
};

/**
 * @brief Trình quản lý Mẫu Văn bản Động (Text Template Manager)
 * Khôi phục từ JNI RetouchTextSdkModule (opcode 0x12f7c28, 0x12f5bb4, 0x12f5f5c)
 */
class TextTemplateManager {
public:
    TextTemplateManager();
    ~TextTemplateManager() = default;

    /**
     * @brief Đăng ký hoặc nạp mẫu văn bản mới / Register or load text template
     */
    bool registerTemplate(const TextTemplateModel& model);

    /**
     * @brief Lấy danh sách tiêu đề của mẫu văn bản
     * Khớp opcode 0x12f7c28: Java_com_bytedance_retouch_middleware_api_RetouchTextSdkModule_nativeGetTextTemplateTitles
     * @param template_id Mã mẫu
     * @param out_titles Danh sách chuỗi tiêu đề trả về
     * @return true nếu tìm thấy mẫu, false nếu template_id không tồn tại
     */
    bool getTextTemplateTitles(int32_t template_id, std::vector<std::string>& out_titles) const;

    /**
     * @brief Truy vấn siêu dữ liệu đầy đủ dạng JSON
     * Khớp Java_com_bytedance_retouch_middleware_api_RetouchTextSdkModule_nativeQueryTextTemplateData
     */
    bool queryTextTemplateData(int32_t template_id, std::string& out_json) const;

    /**
     * @brief Truy vấn thông tin chi tiết một phần tử chữ
     * Khớp Java_com_bytedance_retouch_middleware_api_RetouchTextSdkModule_nativeQueryTextData
     */
    bool queryTextData(int32_t template_id, int32_t item_index, TextTemplateItem& out_item) const;

    /**
     * @brief Thiết lập trực tiếp phông chữ cho phần tử văn bản
     * Khớp opcode 0x12f5bb4: Java_com_bytedance_retouch_middleware_api_RetouchTextSdkModule_nativeSetTextFont
     * @param template_id Mã mẫu
     * @param item_index Vị trí phần tử
     * @param font_path Đường dẫn tệp phông chữ
     * @param font_name Tên họ phông chữ
     */
    bool setTextFont(int32_t template_id, int32_t item_index, const std::string& font_path, const std::string& font_name);

    /**
     * @brief Thiết lập phông chữ theo chỉ mục trong danh mục phông của mẫu
     * Khớp opcode 0x12f5f5c: Java_com_bytedance_retouch_middleware_api_RetouchTextSdkModule_nativeSetTextTemplateFontByIndex
     * @param template_id Mã mẫu
     * @param item_index Vị trí phần tử
     * @param font_index Chỉ số phông trong font_catalog
     */
    bool setTextTemplateFontByIndex(int32_t template_id, int32_t item_index, int32_t font_index);

    /**
     * @brief Cập nhật nội dung văn bản hiển thị
     */
    bool updateItemText(int32_t template_id, int32_t item_index, const std::string& new_text);

    /**
     * @brief Tính toán hộp bao của phần tử văn bản dựa trên cỡ chữ, số ký tự và dòng
     */
    RectF computeItemBoundingBox(const TextTemplateItem& item) const;

    /**
     * @brief Tính toán hoạt họa động lực học kinetic theo mốc thời gian t (ms)
     * Áp dụng hiệu ứng Pop-in, Bounce, Fade theo đường cong Cubic Bezier
     */
    bool evaluateKineticTransform(int32_t template_id, int32_t item_index, int64_t current_time_ms,
                                 Transform2D& out_animated_transform, float& out_opacity) const;

    /**
     * @brief Số lượng mẫu đã nạp
     */
    size_t getTemplateCount() const;

    /**
     * @brief Xóa toàn bộ mẫu
     */
    void clear();

    /**
     * @brief Tự kiểm chứng tính đúng đắn của module (Self-Test Suite)
     */
    static bool runSelfTest();

private:
    std::map<int32_t, TextTemplateModel> m_templates;
    mutable std::mutex m_mutex;
};

} // namespace retouch::middleware
