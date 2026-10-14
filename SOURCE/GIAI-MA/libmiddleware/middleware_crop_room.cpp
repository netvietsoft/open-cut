// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libmiddleware.so (ByteDance Retouch & CrossPlatform NLE Middleware)
// File: middleware_crop_room.cpp
// Description: Image Content Crop Room Modal Manager Implementation
//              ARM64 Parity: opcodes 0x12fc374, 0x12fc460
// ===================================================================================

#include "middleware_crop_room.h"

namespace retouch::middleware {

CropRoom::CropRoom() {
    m_state.is_active = false;
    m_state.active_layer_id = 0;
    m_state.aspect_ratio = 0.0f;
}

bool CropRoom::enterCropRoom(int32_t layer_id, const RectF& initial_bounds, float aspect_ratio) {
    std::lock_guard<std::mutex> lock(m_crop_mutex);
    if (m_state.is_active) {
        return false; // Đang ở trong phòng cắt cúp của Layer khác
    }

    m_state.is_active = true;
    m_state.active_layer_id = layer_id;
    m_state.crop_bounds = initial_bounds;
    m_state.aspect_ratio = aspect_ratio;
    m_original_bounds = initial_bounds;

    return true;
}

bool CropRoom::exitCropRoom(bool apply) {
    std::lock_guard<std::mutex> lock(m_crop_mutex);
    if (!m_state.is_active) {
        return false;
    }

    if (!apply) {
        // Phục hồi lại vùng cắt ban đầu
        m_state.crop_bounds = m_original_bounds;
    }

    m_state.is_active = false;
    m_state.active_layer_id = 0;
    return true;
}

void CropRoom::resetCropRoom() {
    std::lock_guard<std::mutex> lock(m_crop_mutex);
    if (m_state.is_active) {
        m_state.crop_bounds = m_original_bounds;
    }
}

bool CropRoom::updateCropBounds(const RectF& new_bounds) {
    std::lock_guard<std::mutex> lock(m_crop_mutex);
    if (!m_state.is_active) {
        return false;
    }

    m_state.crop_bounds = new_bounds;

    // Ép tỉ lệ aspect ratio nếu được chỉ định
    if (m_state.aspect_ratio > 0.001f) {
        float w = m_state.crop_bounds.width();
        float target_h = w / m_state.aspect_ratio;
        m_state.crop_bounds.bottom = m_state.crop_bounds.top + target_h;
    }

    return true;
}

CropRoomState CropRoom::getState() const {
    std::lock_guard<std::mutex> lock(m_crop_mutex);
    return m_state;
}

bool CropRoom::isActive() const {
    std::lock_guard<std::mutex> lock(m_crop_mutex);
    return m_state.is_active;
}

} // namespace retouch::middleware
