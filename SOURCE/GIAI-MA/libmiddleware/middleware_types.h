// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libmiddleware.so (ByteDance Retouch & CrossPlatform NLE Middleware)
// File: middleware_types.h
// Description: Data contracts, 2D affine transform, AABB bounding box,
//              Scene Graph layer hierarchy, and transaction batching.
//              Reverse-engineered from ARM64 opcodes 0x12fd4f4, 0x12fda14, 0x12fdc2c, 0x12fc094, 0x12fc5e8.
// ===================================================================================

#pragma once

#include <stdint.h>
#include <stddef.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <cmath>
#include <algorithm>

namespace retouch::middleware {

// ===================================================================================
// 1. 2D GEOMETRY, AFFINE TRANSFORM & AABB BOUNDING BOX
// Cấu trúc hình học 2D, biến đổi affine và hộp bao AABB
// ===================================================================================

struct PointF {
    float x;
    float y;

    PointF() : x(0.0f), y(0.0f) {}
    PointF(float px, float py) : x(px), y(py) {}
};

struct RectF {
    float left;
    float top;
    float right;
    float bottom;

    RectF() : left(0.0f), top(0.0f), right(0.0f), bottom(0.0f) {}
    RectF(float l, float t, float r, float b) : left(l), top(t), right(r), bottom(b) {}

    float width() const { return right - left; }
    float height() const { return bottom - top; }
    PointF center() const { return PointF((left + right) * 0.5f, (top + bottom) * 0.5f); }
};

/**
 * @brief Hộp bao trục song song AABB (Axis-Aligned Bounding Box)
 * (Khớp opcode 0x12fd4f4: nativeGetLayerAABBBox)
 */
struct LayerAABBBox {
    float min_x;
    float min_y;
    float max_x;
    float max_y;

    LayerAABBBox() : min_x(0.0f), min_y(0.0f), max_x(0.0f), max_y(0.0f) {}
    LayerAABBBox(float x0, float y0, float x1, float y1) : min_x(x0), min_y(y0), max_x(x1), max_y(y1) {}

    float width() const { return max_x - min_x; }
    float height() const { return max_y - min_y; }
};

/**
 * @brief Biến đổi Affine 2D của Layer (Vị trí, Phóng to/Thu nhỏ, Góc quay)
 * (Khớp opcode 0x12fdc2c: nativeScale, opcode 0x12fda14: nativeQueryLayerRotate)
 */
struct Transform2D {
    PointF position;      // Tọa độ tâm (x, y) trên canvas
    PointF scale;         // Hệ số tỷ lệ (scale_x, scale_y)
    float rotation_deg;   // Góc xoay theo độ [0, 360)
    PointF anchor;        // Điểm neo (mặc định 0.5, 0.5 là tâm layer)

    Transform2D()
        : position(0.0f, 0.0f),
          scale(1.0f, 1.0f),
          rotation_deg(0.0f),
          anchor(0.5f, 0.5f) {}
};

// ===================================================================================
// 2. LAYER MODEL & SCENE GRAPH SPECIFICATION
// Đặc tả mô hình Layer đồ họa trong cây phân cấp Scene Graph
// ===================================================================================

enum class LayerType : int32_t {
    UNKNOWN = 0,
    VIDEO = 1,
    IMAGE = 2,
    TEXT = 3,
    STICKER = 4,
    FILTER = 5,
    GROUP = 6
};

struct LayerDesc {
    int32_t layer_id;
    LayerType type;
    std::string name;
    float original_width;
    float original_height;
    Transform2D transform;
    float opacity;
    bool is_visible;
    int32_t z_order;
    int32_t parent_group_id;

    LayerDesc()
        : layer_id(0),
          type(LayerType::UNKNOWN),
          original_width(1080.0f),
          original_height(1920.0f),
          opacity(1.0f),
          is_visible(true),
          z_order(0),
          parent_group_id(0) {}
};

// ===================================================================================
// 3. IMAGE CONTENT CROP ROOM SPECIFICATION
// Trạng thái phòng cắt cúp ảnh tương tác (Opcodes 0x12fc374, 0x12fc460)
// ===================================================================================

struct CropRoomState {
    bool is_active;
    int32_t active_layer_id;
    RectF crop_bounds;
    float aspect_ratio; // 0 = Tự do, 1.0 = 1:1, 0.5625 = 9:16, 1.7778 = 16:9

    CropRoomState()
        : is_active(false),
          active_layer_id(0),
          crop_bounds(0, 0, 1, 1),
          aspect_ratio(0.0f) {}
};

// ===================================================================================
// 4. TRANSACTION BATCH PUSH (UNDO/REDO ATOMIC BATCHING)
// Quản lý bó giao dịch thao tác hoàn tác / làm lại (Opcodes 0x12fc5e8, 0x12fc620)
// ===================================================================================

struct BatchPushTransaction {
    int32_t transaction_id;
    int32_t command_count;
    bool is_open;
    int64_t start_time_ms;

    BatchPushTransaction()
        : transaction_id(0),
          command_count(0),
          is_open(false),
          start_time_ms(0) {}
};

} // namespace retouch::middleware
