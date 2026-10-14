// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libmiddleware.so (ByteDance Retouch & CrossPlatform NLE Middleware)
// File: middleware_scene_graph.cpp
// Description: SceneGraph and Layer Hierarchy Manager Implementation
//              ARM64 Parity: opcodes 0x12fd4f4, 0x12fda14, 0x12fdc2c, 0x12fc094
// ===================================================================================

#include "middleware_scene_graph.h"
#include <cmath>
#include <limits>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace retouch::middleware {

// ===================================================================================
// Constructor & Basic Controls / Khởi tạo & Điều khiển cơ bản
// ===================================================================================

SceneGraph::SceneGraph()
    : m_global_scale(1.0f) // Mặc định tỷ lệ hiển thị canvas = 1.0 (Opcode 0x12fc094)
{
}

void SceneGraph::reset() {
    std::lock_guard<std::mutex> lock(m_scene_mutex);
    m_layers.clear();
    m_global_scale = 1.0f;
}

size_t SceneGraph::getLayerCount() const {
    std::lock_guard<std::mutex> lock(m_scene_mutex);
    return m_layers.size();
}

// ===================================================================================
// Layer Addition & Retrieval / Thêm & Truy xuất Layer
// ===================================================================================

bool SceneGraph::addLayer(const LayerDesc& layer) {
    std::lock_guard<std::mutex> lock(m_scene_mutex);
    if (m_layers.find(layer.layer_id) != m_layers.end()) {
        return false; // Layer ID đã tồn tại
    }
    m_layers[layer.layer_id] = layer;
    return true;
}

bool SceneGraph::removeLayer(int32_t layer_id) {
    std::lock_guard<std::mutex> lock(m_scene_mutex);
    auto it = m_layers.find(layer_id);
    if (it != m_layers.end()) {
        m_layers.erase(it);
        return true;
    }
    return false;
}

bool SceneGraph::getLayer(int32_t layer_id, LayerDesc& out_layer) const {
    std::lock_guard<std::mutex> lock(m_scene_mutex);
    auto it = m_layers.find(layer_id);
    if (it != m_layers.end()) {
        out_layer = it->second;
        return true;
    }
    return false;
}

// ===================================================================================
// Layer Transform: Rotation, Scale, AABB Box / Biến đổi hình học & Hộp bao
// ===================================================================================

float SceneGraph::queryLayerRotate(int32_t layer_id) const {
    std::lock_guard<std::mutex> lock(m_scene_mutex);
    auto it = m_layers.find(layer_id);
    if (it == m_layers.end()) {
        // Khớp mã máy ARM64 tại opcode 0x12fda54: fmov s0, wzr; ret -> trả về 0.0f khi không tìm thấy
        return 0.0f;
    }
    return it->second.transform.rotation_deg;
}

bool SceneGraph::setLayerRotate(int32_t layer_id, float rotation_deg) {
    std::lock_guard<std::mutex> lock(m_scene_mutex);
    auto it = m_layers.find(layer_id);
    if (it == m_layers.end()) return false;

    // Chuẩn hóa góc xoay vào khoảng dương [0, 360) độ
    float norm = std::fmod(rotation_deg, 360.0f);
    if (norm < 0.0f) norm += 360.0f;
    it->second.transform.rotation_deg = norm;
    return true;
}

bool SceneGraph::scaleLayer(int32_t layer_id, float scale_x, float scale_y) {
    // Khớp opcode 0x12fdc2c: nativeScale(scale_x = v0, scale_y = v1, layer_id = w2)
    std::lock_guard<std::mutex> lock(m_scene_mutex);
    auto it = m_layers.find(layer_id);
    if (it == m_layers.end()) return false;

    it->second.transform.scale.x = scale_x;
    it->second.transform.scale.y = scale_y;
    return true;
}

LayerAABBBox SceneGraph::getLayerAABBBox(int32_t layer_id) const {
    // Khớp opcode 0x12fd4f4: nativeGetLayerAABBBox
    std::lock_guard<std::mutex> lock(m_scene_mutex);
    auto it = m_layers.find(layer_id);
    if (it == m_layers.end()) {
        return LayerAABBBox(0.0f, 0.0f, 0.0f, 0.0f);
    }

    const auto& layer = it->second;
    float half_w = (layer.original_width * 0.5f) * layer.transform.scale.x;
    float half_h = (layer.original_height * 0.5f) * layer.transform.scale.y;

    // 4 đỉnh cục bộ của hình chữ nhật: (-w/2, -h/2), (w/2, -h/2), (w/2, h/2), (-w/2, h/2)
    const float local_x[4] = { -half_w,  half_w, half_w, -half_w };
    const float local_y[4] = { -half_h, -half_h, half_h,  half_h };

    float rad = static_cast<float>(layer.transform.rotation_deg * M_PI / 180.0);
    float cos_r = std::cos(rad);
    float sin_r = std::sin(rad);

    float min_x = std::numeric_limits<float>::max();
    float min_y = std::numeric_limits<float>::max();
    float max_x = std::numeric_limits<float>::lowest();
    float max_y = std::numeric_limits<float>::lowest();

    // Biến đổi Affine 4 đỉnh qua ma trận xoay và tịnh tiến
    for (int32_t i = 0; i < 4; ++i) {
        float rot_x = local_x[i] * cos_r - local_y[i] * sin_r;
        float rot_y = local_x[i] * sin_r + local_y[i] * cos_r;

        float world_x = layer.transform.position.x + rot_x;
        float world_y = layer.transform.position.y + rot_y;

        if (world_x < min_x) min_x = world_x;
        if (world_x > max_x) max_x = world_x;
        if (world_y < min_y) min_y = world_y;
        if (world_y > max_y) max_y = world_y;
    }

    return LayerAABBBox(min_x, min_y, max_x, max_y);
}

// ===================================================================================
// Z-Order & Hierarchy Operations / Thứ tự hiển thị & Nhóm phân cấp
// ===================================================================================

bool SceneGraph::moveLayerOfSiblingNode(int32_t layer_id, int32_t direction) {
    // Khớp opcode 0x12fc114: nativeMoveLayerOfSiblingNode
    std::lock_guard<std::mutex> lock(m_scene_mutex);
    auto it = m_layers.find(layer_id);
    if (it == m_layers.end()) return false;

    it->second.z_order += direction;
    return true;
}

bool SceneGraph::setLayerVisible(int32_t layer_id, bool visible) {
    std::lock_guard<std::mutex> lock(m_scene_mutex);
    auto it = m_layers.find(layer_id);
    if (it == m_layers.end()) return false;

    it->second.is_visible = visible;
    return true;
}

bool SceneGraph::isLayerVisible(int32_t layer_id) const {
    std::lock_guard<std::mutex> lock(m_scene_mutex);
    auto it = m_layers.find(layer_id);
    if (it == m_layers.end()) return false;

    return it->second.is_visible;
}

int32_t SceneGraph::getGroupLayerId(int32_t layer_id) const {
    // Khớp opcode 0x12fcce8: nativeGetGroupLayerId
    std::lock_guard<std::mutex> lock(m_scene_mutex);
    auto it = m_layers.find(layer_id);
    if (it == m_layers.end()) return 0;

    return it->second.parent_group_id;
}

} // namespace retouch::middleware
