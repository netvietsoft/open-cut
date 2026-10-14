// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libmiddleware.so (ByteDance Retouch & CrossPlatform NLE Middleware)
// File: middleware_crop_room.h
// Description: Image Content Crop Room Modal Manager
//              Reverse-engineered from ARM64 opcodes 0x12fc374, 0x12fc460
// ===================================================================================

#pragma once

#include "middleware_types.h"
#include <mutex>

namespace retouch::middleware {

/**
 * @brief Trình quản lý phòng cắt cúp ảnh tương tác (CropRoom Manager)
 * (Khớp opcodes 0x12fc374: nativeEnterImageContentCropRoom, 0x12fc460: nativeExitImageContentCropRoom)
 */
class CropRoom {
public:
    CropRoom();
    ~CropRoom() = default;

    /// Vào phòng cắt cúp ảnh tương tác cho Layer chỉ định
    bool enterCropRoom(int32_t layer_id, const RectF& initial_bounds, float aspect_ratio = 0.0f);

    /// Thoát phòng cắt cúp (apply = true để lưu vết cắt, apply = false để hủy)
    bool exitCropRoom(bool apply);

    /// Đặt lại vùng cắt về mặc định
    void resetCropRoom();

    /// Cập nhật vùng cắt mới
    bool updateCropBounds(const RectF& new_bounds);

    /// Lấy trạng thái phòng cắt cúp hiện tại
    CropRoomState getState() const;

    /// Kiểm tra xem phòng cắt cúp có đang hoạt động hay không
    bool isActive() const;

private:
    mutable std::mutex m_crop_mutex;
    CropRoomState m_state;
    RectF m_original_bounds;
};

} // namespace retouch::middleware
