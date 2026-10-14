// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libmiddleware.so (ByteDance Retouch & CrossPlatform NLE Middleware)
// File: middleware_autolayout.h
// Description: AutoLayout Matching & Responsive Content Alignment Engine
//              Reverse-engineered from ARM64 opcodes 0x12f3cac, 0x12f3a4c
// ===================================================================================

#pragma once

#include "middleware_types.h"
#include <string>
#include <vector>
#include <memory>

namespace retouch::middleware {

enum class AlignmentMode : int32_t {
    NONE = 0,
    TOP_LEFT = 1,
    TOP_CENTER = 2,
    TOP_RIGHT = 3,
    CENTER_LEFT = 4,
    CENTER = 5,
    CENTER_RIGHT = 6,
    BOTTOM_LEFT = 7,
    BOTTOM_CENTER = 8,
    BOTTOM_RIGHT = 9
};

struct AutoLayoutRule {
    int32_t layer_id;
    AlignmentMode alignment;
    float margin_left;
    float margin_top;
    float margin_right;
    float margin_bottom;
    bool keep_aspect_ratio;

    AutoLayoutRule()
        : layer_id(0),
          alignment(AlignmentMode::CENTER),
          margin_left(0.0f),
          margin_top(0.0f),
          margin_right(0.0f),
          margin_bottom(0.0f),
          keep_aspect_ratio(true) {}
};

/**
 * @brief Động cơ tự động căn chỉnh bố cục đáp ứng AutoLayout Engine
 * (Khớp opcodes 0x12f3cac: nativeGetAutoLayoutJson, 0x12f3a4c: nativeApplyAutoLayoutMatchJson)
 */
class AutoLayoutEngine {
public:
    AutoLayoutEngine();
    ~AutoLayoutEngine() = default;

    /// Thêm quy tắc căn chỉnh cho Layer
    void addRule(const AutoLayoutRule& rule);

    /// Xóa quy tắc căn chỉnh
    void removeRule(int32_t layer_id);

    /// Áp dụng tự động căn chỉnh lại toàn bộ Layer theo kích thước canvas mới
    void applyLayout(
        float canvas_width,
        float canvas_height,
        std::unordered_map<int32_t, LayerDesc>& layers
    );

    /// Trích xuất cấu hình căn chỉnh dưới dạng chuỗi JSON
    std::string getAutoLayoutJson() const;

    /// Nạp cấu hình căn chỉnh từ chuỗi JSON
    bool applyAutoLayoutMatchJson(const std::string& json_str);

    void clearRules();

private:
    std::vector<AutoLayoutRule> m_rules;
};

} // namespace retouch::middleware
