// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libmiddleware.so (ByteDance Retouch & CrossPlatform NLE Middleware)
// File: middleware_text_template.cpp
// Description: Full implementation of Kinetic Typography and Font Resolver
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#include "middleware_text_template.h"
#include <sstream>
#include <cmath>
#include <algorithm>

namespace retouch::middleware {

// ===================================================================================
// Bảng hàm nội suy Cubic Bezier cho Kinetic Typography
// Cubic Bezier interpolation helper for kinetic motion effects
// ===================================================================================
namespace {
    inline float cubicBezierEval(float t, float p0, float p1, float p2, float p3) {
        float u = 1.0f - t;
        float tt = t * t;
        float uu = u * u;
        float uuu = uu * u;
        float ttt = tt * t;
        return uuu * p0 + 3.0f * uu * t * p1 + 3.0f * u * tt * p2 + ttt * p3;
    }

    // Đường cong nảy pop (Overshoot bounce curve: [0, 0] -> [0.34, 1.56] -> [0.64, 1.0] -> [1.0, 1.0])
    inline float evaluateEaseOutBack(float progress) {
        float c1 = 1.70158f;
        float c3 = c1 + 1.0f;
        float t = progress - 1.0f;
        return 1.0f + c3 * (t * t * t) + c1 * (t * t);
    }
}

TextTemplateManager::TextTemplateManager() {
    // Khởi tạo một mẫu mặc định sẵn sàng sử dụng
    // Pre-populate default kinetic template
    TextTemplateModel default_tpl;
    default_tpl.template_id = 1;
    default_tpl.template_name = "CapCut_Kinetic_Pop_Intro";
    default_tpl.duration_ms = 4000;
    default_tpl.anim_preset_id = 101;
    default_tpl.canvas_aspect_ratio = 16.0f / 9.0f;

    // Font danh mục mặc định
    default_tpl.font_catalog.push_back(TextFontEntry(0, "ProximaNova-Bold", "/system/fonts/ProximaNova-Bold.ttf", true, false));
    default_tpl.font_catalog.push_back(TextFontEntry(1, "Montserrat-Regular", "/system/fonts/Montserrat-Regular.ttf", false, false));
    default_tpl.font_catalog.push_back(TextFontEntry(2, "BebasNeue-Regular", "/system/fonts/BebasNeue-Regular.ttf", false, false));

    // Đoạn chữ 1: Tiêu đề chính (Main Title)
    TextTemplateItem item1;
    item1.slot_index = 0;
    item1.title_text = "NEXTAI OPENCUT";
    item1.font_index = 0;
    item1.font_family = "ProximaNova-Bold";
    item1.font_path = "/system/fonts/ProximaNova-Bold.ttf";
    item1.font_size = 54.0f;
    item1.tracking = 2.0f;
    item1.line_spacing = 1.1f;
    item1.alignment = TextAlignment::CENTER;
    item1.color_r = 1.0f; item1.color_g = 0.85f; item1.color_b = 0.0f; item1.color_a = 1.0f; // Vàng ánh kim
    item1.has_stroke = true;
    item1.stroke_width = 3.0f;
    item1.stroke_r = 0.0f; item1.stroke_g = 0.0f; item1.stroke_b = 0.0f; item1.stroke_a = 1.0f;
    item1.position = PointF(0.0f, -40.0f);
    item1.bounding_box = computeItemBoundingBox(item1);
    default_tpl.items.push_back(item1);

    // Đoạn chữ 2: Phụ đề (Subtitle)
    TextTemplateItem item2;
    item2.slot_index = 1;
    item2.title_text = "Pro Video Editor Reborn";
    item2.font_index = 1;
    item2.font_family = "Montserrat-Regular";
    item2.font_path = "/system/fonts/Montserrat-Regular.ttf";
    item2.font_size = 28.0f;
    item2.tracking = 1.5f;
    item2.line_spacing = 1.0f;
    item2.alignment = TextAlignment::CENTER;
    item2.color_r = 1.0f; item2.color_g = 1.0f; item2.color_b = 1.0f; item2.color_a = 0.95f;
    item2.has_shadow = true;
    item2.shadow_dx = 2.0f; item2.shadow_dy = 2.0f; item2.shadow_blur = 4.0f;
    item2.position = PointF(0.0f, 40.0f);
    item2.bounding_box = computeItemBoundingBox(item2);
    default_tpl.items.push_back(item2);

    m_templates[default_tpl.template_id] = default_tpl;
}

bool TextTemplateManager::registerTemplate(const TextTemplateModel& model) {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (model.template_id <= 0) return false;
    m_templates[model.template_id] = model;
    return true;
}

// Khớp opcode 0x12f7c28: nativeGetTextTemplateTitles
bool TextTemplateManager::getTextTemplateTitles(int32_t template_id, std::vector<std::string>& out_titles) const {
    std::lock_guard<std::mutex> lock(m_mutex);
    out_titles.clear();

    auto it = m_templates.find(template_id);
    if (it == m_templates.end()) {
        // Khớp hành vi opcode 0x12f7c88: trả về rỗng nếu không tìm thấy
        return false;
    }

    const auto& items = it->second.items;
    out_titles.reserve(items.size());
    for (const auto& item : items) {
        out_titles.push_back(item.title_text);
    }
    return true;
}

bool TextTemplateManager::queryTextTemplateData(int32_t template_id, std::string& out_json) const {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_templates.find(template_id);
    if (it == m_templates.end()) {
        out_json = "{}";
        return false;
    }

    const auto& tpl = it->second;
    std::ostringstream ss;
    ss << "{\"template_id\":" << tpl.template_id
       << ",\"name\":\"" << tpl.template_name << "\""
       << ",\"duration_ms\":" << tpl.duration_ms
       << ",\"aspect_ratio\":" << tpl.canvas_aspect_ratio
       << ",\"item_count\":" << tpl.items.size()
       << ",\"items\":[";

    for (size_t i = 0; i < tpl.items.size(); ++i) {
        const auto& item = tpl.items[i];
        if (i > 0) ss << ",";
        ss << "{\"slot\":" << item.slot_index
           << ",\"text\":\"" << item.title_text << "\""
           << ",\"font\":\"" << item.font_family << "\""
           << ",\"font_size\":" << item.font_size
           << ",\"pos_x\":" << item.position.x
           << ",\"pos_y\":" << item.position.y
           << "}";
    }
    ss << "]}";
    out_json = ss.str();
    return true;
}

bool TextTemplateManager::queryTextData(int32_t template_id, int32_t item_index, TextTemplateItem& out_item) const {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_templates.find(template_id);
    if (it == m_templates.end()) return false;

    if (item_index < 0 || item_index >= static_cast<int32_t>(it->second.items.size())) {
        return false;
    }

    out_item = it->second.items[item_index];
    return true;
}

// Khớp opcode 0x12f5bb4: nativeSetTextFont
bool TextTemplateManager::setTextFont(int32_t template_id, int32_t item_index,
                                     const std::string& font_path, const std::string& font_name) {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_templates.find(template_id);
    if (it == m_templates.end()) return false;

    if (item_index < 0 || item_index >= static_cast<int32_t>(it->second.items.size())) {
        return false;
    }

    auto& item = it->second.items[item_index];
    item.font_path = font_path;
    item.font_family = font_name;
    item.bounding_box = computeItemBoundingBox(item);
    return true;
}

// Khớp opcode 0x12f5f5c: nativeSetTextTemplateFontByIndex
bool TextTemplateManager::setTextTemplateFontByIndex(int32_t template_id, int32_t item_index, int32_t font_index) {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_templates.find(template_id);
    if (it == m_templates.end()) return false;

    if (item_index < 0 || item_index >= static_cast<int32_t>(it->second.items.size())) {
        return false;
    }

    const auto& catalog = it->second.font_catalog;
    if (font_index < 0 || font_index >= static_cast<int32_t>(catalog.size())) {
        return false;
    }

    auto& item = it->second.items[item_index];
    item.font_index = font_index;
    item.font_family = catalog[font_index].font_family;
    item.font_path = catalog[font_index].font_path;
    item.bounding_box = computeItemBoundingBox(item);
    return true;
}

bool TextTemplateManager::updateItemText(int32_t template_id, int32_t item_index, const std::string& new_text) {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_templates.find(template_id);
    if (it == m_templates.end()) return false;

    if (item_index < 0 || item_index >= static_cast<int32_t>(it->second.items.size())) {
        return false;
    }

    auto& item = it->second.items[item_index];
    item.title_text = new_text;
    item.bounding_box = computeItemBoundingBox(item);
    return true;
}

RectF TextTemplateManager::computeItemBoundingBox(const TextTemplateItem& item) const {
    // Tính toán gần đúng kích thước đoạn chữ dựa trên số ký tự, cỡ font và tracking
    // Approximate typographical bounding box calculation
    size_t char_count = item.title_text.length();
    if (char_count == 0) {
        return RectF(item.position.x, item.position.y, item.position.x, item.position.y);
    }

    // Ước tính độ rộng trung bình của glyph = 0.55 * font_size + tracking
    float avg_char_width = item.font_size * 0.55f + item.tracking;
    float total_width = static_cast<float>(char_count) * avg_char_width;
    float total_height = item.font_size * item.line_spacing;

    float half_w = total_width * 0.5f;
    float half_h = total_height * 0.5f;

    return RectF(item.position.x - half_w, item.position.y - half_h,
                 item.position.x + half_w, item.position.y + half_h);
}

bool TextTemplateManager::evaluateKineticTransform(int32_t template_id, int32_t item_index,
                                                  int64_t current_time_ms,
                                                  Transform2D& out_animated_transform,
                                                  float& out_opacity) const {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_templates.find(template_id);
    if (it == m_templates.end()) return false;

    if (item_index < 0 || item_index >= static_cast<int32_t>(it->second.items.size())) {
        return false;
    }

    const auto& tpl = it->second;
    const auto& item = tpl.items[item_index];
    out_animated_transform.position = item.position;
    out_animated_transform.rotation_deg = item.rotation_deg;

    // Thời gian xuất hiện từng slot (Staggered entrance: slot 0 bắt đầu từ 0ms, slot 1 từ 250ms)
    int64_t slot_delay_ms = static_cast<int64_t>(item_index) * 250;
    int64_t anim_duration_ms = 600; // Thời gian bay vào 600ms

    if (current_time_ms < slot_delay_ms) {
        // Chưa tới thời điểm xuất hiện
        out_opacity = 0.0f;
        out_animated_transform.scale = PointF(0.0f, 0.0f);
        return true;
    }

    int64_t elapsed_in_anim = current_time_ms - slot_delay_ms;
    if (elapsed_in_anim >= anim_duration_ms) {
        // Hoạt họa đã ổn định tại trạng thái chuẩn
        out_opacity = item.color_a;
        out_animated_transform.scale = item.scale;
    } else {
        // Đang trong pha bay vào: EaseOutBack nảy phóng to
        float progress = static_cast<float>(elapsed_in_anim) / static_cast<float>(anim_duration_ms);
        float scale_factor = std::clamp(evaluateEaseOutBack(progress), 0.0f, 1.6f);

        out_opacity = progress * item.color_a;
        out_animated_transform.scale = PointF(item.scale.x * scale_factor, item.scale.y * scale_factor);
    }

    return true;
}

size_t TextTemplateManager::getTemplateCount() const {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_templates.size();
}

void TextTemplateManager::clear() {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_templates.clear();
}

// ===================================================================================
// Bộ tự kiểm chứng tính đúng đắn TextTemplateManager
// ===================================================================================
bool TextTemplateManager::runSelfTest() {
    TextTemplateManager mgr;

    // 1. Kiểm tra mẫu mặc định
    if (mgr.getTemplateCount() != 1) return false;

    // 2. Lấy tiêu đề mẫu ID 1 (Opcode 0x12f7c28)
    std::vector<std::string> titles;
    if (!mgr.getTextTemplateTitles(1, titles)) return false;
    if (titles.size() != 2) return false;
    if (titles[0] != "NEXTAI OPENCUT" || titles[1] != "Pro Video Editor Reborn") return false;

    // Kiểm tra mẫu không tồn tại (trả về false)
    std::vector<std::string> empty_titles;
    if (mgr.getTextTemplateTitles(999, empty_titles)) return false;
    if (!empty_titles.empty()) return false;

    // 3. Đổi phông chữ theo chỉ mục (Opcode 0x12f5f5c)
    // Đổi slot 0 từ ProximaNova (index 0) sang BebasNeue (index 2)
    if (!mgr.setTextTemplateFontByIndex(1, 0, 2)) return false;
    TextTemplateItem query_item;
    if (!mgr.queryTextData(1, 0, query_item)) return false;
    if (query_item.font_family != "BebasNeue-Regular") return false;
    if (query_item.font_index != 2) return false;

    // 4. Đổi phông chữ trực tiếp (Opcode 0x12f5bb4)
    if (!mgr.setTextFont(1, 1, "/custom/path/Roboto-Light.ttf", "Roboto-Light")) return false;
    if (!mgr.queryTextData(1, 1, query_item)) return false;
    if (query_item.font_family != "Roboto-Light") return false;

    // 5. Cập nhật nội dung văn bản và kiểm tra lại hộp bao
    if (!mgr.updateItemText(1, 0, "CAPCUT ALTERNATIVE ENGINE")) return false;
    if (!mgr.queryTextData(1, 0, query_item)) return false;
    if (query_item.title_text != "CAPCUT ALTERNATIVE ENGINE") return false;
    if (query_item.bounding_box.width() <= 0.0f) return false;

    // 6. Kiểm tra JSON serialization
    std::string json;
    if (!mgr.queryTextTemplateData(1, json)) return false;
    if (json.find("CAPCUT ALTERNATIVE ENGINE") == std::string::npos) return false;

    // 7. Kiểm tra hoạt họa Kinetic Pop-in
    Transform2D trans;
    float opacity = 0.0f;
    // t = 0ms: slot 1 (delay 250ms) phải có opacity = 0.0f
    mgr.evaluateKineticTransform(1, 1, 0, trans, opacity);
    if (opacity != 0.0f) return false;

    // t = 550ms: slot 1 (đã chạy 300ms) phải có opacity > 0 và scale > 0
    mgr.evaluateKineticTransform(1, 1, 550, trans, opacity);
    if (opacity <= 0.0f || trans.scale.x <= 0.0f) return false;

    // t = 2000ms: đã ổn định đầy đủ
    mgr.evaluateKineticTransform(1, 1, 2000, trans, opacity);
    if (std::abs(opacity - 0.95f) > 0.01f || std::abs(trans.scale.x - 1.0f) > 0.01f) return false;

    return true;
}

} // namespace retouch::middleware
