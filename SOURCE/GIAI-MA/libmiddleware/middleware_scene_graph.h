// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libmiddleware.so (ByteDance Retouch & CrossPlatform NLE Middleware)
// File: middleware_scene_graph.h
// Description: SceneGraph and Layer Hierarchy Manager
//              Reverse-engineered from ARM64 opcodes 0x12fd4f4, 0x12fda14, 0x12fdc2c, 0x12fc094
// ===================================================================================

#pragma once

#include "middleware_types.h"
#include <mutex>
#include <unordered_map>
#include <vector>

namespace retouch::middleware {

/**
 * @brief Bộ quản lý đồ thị phân cảnh và các Layer đồ họa (SceneGraph & LayerManager)
 * Khôi phục từ vtable offset 0x3a0 của RetouchContext (opcode 0x12fd530, 0x12fda30)
 */
class SceneGraph {
public:
    SceneGraph();
    ~SceneGraph() = default;

    /// Thêm một Layer vào phân cảnh
    bool addLayer(const LayerDesc& layer);

    /// Xóa một Layer theo ID
    bool removeLayer(int32_t layer_id);

    /// Truy xuất Layer theo ID
    bool getLayer(int32_t layer_id, LayerDesc& out_layer) const;

    /// Truy vấn góc xoay của Layer (Khớp opcode 0x12fda14: nativeQueryLayerRotate)
    float queryLayerRotate(int32_t layer_id) const;

    /// Cập nhật góc xoay của Layer (tự động chuẩn hóa modulo 360 độ)
    bool setLayerRotate(int32_t layer_id, float rotation_deg);

    /// Phóng to / Thu nhỏ Layer (Khớp opcode 0x12fdc2c: nativeScale)
    bool scaleLayer(int32_t layer_id, float scale_x, float scale_y);

    /// Truy vấn tỷ lệ hiển thị canvas toàn cục (Khớp opcode 0x12fc094: nativeGetGlobalScale)
    float getGlobalScale() const { return m_global_scale; }
    void setGlobalScale(float scale) { m_global_scale = scale > 0.0f ? scale : 1.0f; }

    /// Tính toán hộp bao trục song song AABB (Khớp opcode 0x12fd4f4: nativeGetLayerAABBBox)
    LayerAABBBox getLayerAABBBox(int32_t layer_id) const;

    /// Di chuyển vị trí hiển thị giữa các Layer anh em (Khớp opcode 0x12fc114: nativeMoveLayerOfSiblingNode)
    bool moveLayerOfSiblingNode(int32_t layer_id, int32_t direction);

    /// Đặt và kiểm tra trạng thái hiển thị của Layer (Opcode 0x12f4dc4)
    bool setLayerVisible(int32_t layer_id, bool visible);
    bool isLayerVisible(int32_t layer_id) const;

    /// Truy vấn ID nhóm chứa Layer (Opcode 0x12fcce8: nativeGetGroupLayerId)
    int32_t getGroupLayerId(int32_t layer_id) const;

    /// Lấy tổng số Layer đang quản lý
    size_t getLayerCount() const;

    /// Đặt lại toàn bộ phân cảnh
    void reset();

private:
    mutable std::mutex m_scene_mutex;
    float m_global_scale; // Opcode 0x12fc094
    std::unordered_map<int32_t, LayerDesc> m_layers;
};

} // namespace retouch::middleware
