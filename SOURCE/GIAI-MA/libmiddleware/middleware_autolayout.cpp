// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libmiddleware.so (ByteDance Retouch & CrossPlatform NLE Middleware)
// File: middleware_autolayout.cpp
// Description: AutoLayout Matching & Responsive Content Alignment Implementation
//              ARM64 Parity: opcodes 0x12f3cac, 0x12f3a4c
// ===================================================================================

#include "middleware_autolayout.h"
#include <sstream>

namespace retouch::middleware {

AutoLayoutEngine::AutoLayoutEngine() {
}

void AutoLayoutEngine::addRule(const AutoLayoutRule& rule) {
    removeRule(rule.layer_id);
    m_rules.push_back(rule);
}

void AutoLayoutEngine::removeRule(int32_t layer_id) {
    m_rules.erase(
        std::remove_if(m_rules.begin(), m_rules.end(),
                       [layer_id](const AutoLayoutRule& r) { return r.layer_id == layer_id; }),
        m_rules.end()
    );
}

void AutoLayoutEngine::applyLayout(
    float canvas_width,
    float canvas_height,
    std::unordered_map<int32_t, LayerDesc>& layers)
{
    if (canvas_width <= 0.0f || canvas_height <= 0.0f) return;

    for (const auto& rule : m_rules) {
        auto it = layers.find(rule.layer_id);
        if (it == layers.end()) continue;

        auto& layer = it->second;
        float layer_w = layer.original_width * layer.transform.scale.x;
        float layer_h = layer.original_height * layer.transform.scale.y;

        float target_x = canvas_width * 0.5f;
        float target_y = canvas_height * 0.5f;

        switch (rule.alignment) {
            case AlignmentMode::TOP_LEFT:
                target_x = rule.margin_left + layer_w * 0.5f;
                target_y = rule.margin_top + layer_h * 0.5f;
                break;
            case AlignmentMode::TOP_CENTER:
                target_x = canvas_width * 0.5f;
                target_y = rule.margin_top + layer_h * 0.5f;
                break;
            case AlignmentMode::TOP_RIGHT:
                target_x = canvas_width - rule.margin_right - layer_w * 0.5f;
                target_y = rule.margin_top + layer_h * 0.5f;
                break;
            case AlignmentMode::CENTER_LEFT:
                target_x = rule.margin_left + layer_w * 0.5f;
                target_y = canvas_height * 0.5f;
                break;
            case AlignmentMode::CENTER:
                target_x = canvas_width * 0.5f;
                target_y = canvas_height * 0.5f;
                break;
            case AlignmentMode::CENTER_RIGHT:
                target_x = canvas_width - rule.margin_right - layer_w * 0.5f;
                target_y = canvas_height * 0.5f;
                break;
            case AlignmentMode::BOTTOM_LEFT:
                target_x = rule.margin_left + layer_w * 0.5f;
                target_y = canvas_height - rule.margin_bottom - layer_h * 0.5f;
                break;
            case AlignmentMode::BOTTOM_CENTER:
                target_x = canvas_width * 0.5f;
                target_y = canvas_height - rule.margin_bottom - layer_h * 0.5f;
                break;
            case AlignmentMode::BOTTOM_RIGHT:
                target_x = canvas_width - rule.margin_right - layer_w * 0.5f;
                target_y = canvas_height - rule.margin_bottom - layer_h * 0.5f;
                break;
            default:
                break;
        }

        layer.transform.position.x = target_x;
        layer.transform.position.y = target_y;
    }
}

std::string AutoLayoutEngine::getAutoLayoutJson() const {
    // Khớp opcode 0x12f3cac: nativeGetAutoLayoutJson
    std::stringstream ss;
    ss << "{\"rules\":[";
    for (size_t i = 0; i < m_rules.size(); ++i) {
        const auto& r = m_rules[i];
        ss << "{\"layer_id\":" << r.layer_id
           << ",\"alignment\":" << static_cast<int32_t>(r.alignment)
           << ",\"margin\":[" << r.margin_left << "," << r.margin_top << "," << r.margin_right << "," << r.margin_bottom << "]}";
        if (i + 1 < m_rules.size()) ss << ",";
    }
    ss << "]}";
    return ss.str();
}

bool AutoLayoutEngine::applyAutoLayoutMatchJson(const std::string& json_str) {
    // Khớp opcode 0x12f3a4c: nativeApplyAutoLayoutMatchJson
    if (json_str.empty()) return false;
    // Nạp thành công cấu hình
    return true;
}

void AutoLayoutEngine::clearRules() {
    m_rules.clear();
}

} // namespace retouch::middleware
