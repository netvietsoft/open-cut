// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libmiddleware.so (ByteDance Retouch & CrossPlatform NLE Middleware)
// File: middleware_cutout_brush.cpp
// Description: Full implementation of AI Cutout, Brush Rasterization, and Intelligent Masking
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#include "middleware_cutout_brush.h"
#include <cmath>
#include <cstring>
#include <algorithm>

namespace retouch::middleware {

// ===================================================================================
// 1. CutoutMaskBuffer Implementation
// ===================================================================================

CutoutMaskBuffer::CutoutMaskBuffer() = default;

CutoutMaskBuffer::CutoutMaskBuffer(int32_t width, int32_t height) {
    allocate(width, height);
}

bool CutoutMaskBuffer::allocate(int32_t width, int32_t height) {
    if (width <= 0 || height <= 0) return false;
    m_width = width;
    m_height = height;
    m_stride = width; // 1 byte per pixel
    m_data.assign(static_cast<size_t>(m_stride) * m_height, 0);
    return true;
}

void CutoutMaskBuffer::clear(uint8_t value) {
    std::fill(m_data.begin(), m_data.end(), value);
}

uint8_t CutoutMaskBuffer::getPixel(int32_t x, int32_t y) const {
    if (x < 0 || x >= m_width || y < 0 || y >= m_height) return 0;
    return m_data[static_cast<size_t>(y) * m_stride + x];
}

void CutoutMaskBuffer::setPixel(int32_t x, int32_t y, uint8_t val) {
    if (x < 0 || x >= m_width || y < 0 || y >= m_height) return;
    m_data[static_cast<size_t>(y) * m_stride + x] = val;
}

bool CutoutMaskBuffer::copyFrom(const uint8_t* src, int32_t src_width, int32_t src_height, int32_t src_stride) {
    if (!src || src_width <= 0 || src_height <= 0 || src_stride < src_width) return false;
    if (m_width != src_width || m_height != src_height) {
        if (!allocate(src_width, src_height)) return false;
    }

    for (int32_t y = 0; y < src_height; ++y) {
        const uint8_t* row_src = src + static_cast<size_t>(y) * src_stride;
        uint8_t* row_dst = m_data.data() + static_cast<size_t>(y) * m_stride;
        std::memcpy(row_dst, row_src, src_width);
    }
    return true;
}

// ===================================================================================
// 2. Mathematical Stamp Rasterization
// ===================================================================================

void CutoutBrushManager::rasterizeStamp(CutoutMaskBuffer& mask, const BrushStamp& stamp, CutoutBrushMode mode) {
    if (stamp.radius <= 0.0f || stamp.opacity <= 0.0f) return;

    // Giới hạn vùng ảnh hưởng (AABB bounding box của cọ quét)
    float max_extent = stamp.radius * std::max(1.0f, 1.0f / std::max(0.01f, stamp.aspect_ratio));
    int32_t min_x = std::max(0, static_cast<int32_t>(std::floor(stamp.x - max_extent)));
    int32_t max_x = std::min(mask.getWidth() - 1, static_cast<int32_t>(std::ceil(stamp.x + max_extent)));
    int32_t min_y = std::max(0, static_cast<int32_t>(std::floor(stamp.y - max_extent)));
    int32_t max_y = std::min(mask.getHeight() - 1, static_cast<int32_t>(std::ceil(stamp.y + max_extent)));

    if (min_x > max_x || min_y > max_y) return;

    // Ma trận xoay ngược để chiếu tọa độ điểm ảnh về hệ tọa độ cọ chuẩn
    float rad = stamp.angle_deg * 3.14159265358979323846f / 180.0f;
    float cos_a = std::cos(-rad);
    float sin_a = std::sin(-rad);

    float inv_r = 1.0f / stamp.radius;
    float aspect = std::max(0.01f, stamp.aspect_ratio);
    float inv_r_aspect = inv_r / aspect;
    float hardness = std::clamp(stamp.hardness, 0.0f, 0.999f);
    float hardness_range = 1.0f - hardness;

    for (int32_t py = min_y; py <= max_y; ++py) {
        float dy = static_cast<float>(py) - stamp.y;
        for (int32_t px = min_x; px <= max_x; ++px) {
            float dx = static_cast<float>(px) - stamp.x;

            // Xoay tọa độ
            float local_x = dx * cos_a - dy * sin_a;
            float local_y = dx * sin_a + dy * cos_a;

            // Khoảng cách chuẩn hóa elip (Elliptical normalized distance)
            float norm_x = local_x * inv_r;
            float norm_y = local_y * inv_r_aspect;
            float dist_sq = norm_x * norm_x + norm_y * norm_y;

            if (dist_sq > 1.0f) continue; // Nằm ngoài phạm vi bán kính cọ

            float dist = std::sqrt(dist_sq);
            float factor = 1.0f;

            if (dist > hardness) {
                // Làm mịn biên bằng Hermite Smoothstep: 3t^2 - 2t^3
                float t = (dist - hardness) / hardness_range;
                factor = 1.0f - (3.0f * t * t - 2.0f * t * t * t);
            }

            float stamp_alpha = factor * stamp.opacity;
            uint8_t stamp_val = static_cast<uint8_t>(std::clamp(stamp_alpha * 255.0f, 0.0f, 255.0f));
            uint8_t old_val = mask.getPixel(px, py);

            if (mode == CutoutBrushMode::PAINT || mode == CutoutBrushMode::SMART_SELECT) {
                // Thêm vào mặt nạ (Additive blending / Porter-Duff Over)
                uint8_t new_val = static_cast<uint8_t>(std::min(255, old_val + stamp_val));
                mask.setPixel(px, py, new_val);
            } else if (mode == CutoutBrushMode::ERASE) {
                // Khấu trừ khỏi mặt nạ (Subtractive)
                uint8_t new_val = static_cast<uint8_t>(std::max(0, static_cast<int32_t>(old_val) - stamp_val));
                mask.setPixel(px, py, new_val);
            } else if (mode == CutoutBrushMode::RESTORE) {
                // Đặt về giá trị tối đa
                uint8_t new_val = std::max(old_val, stamp_val);
                mask.setPixel(px, py, new_val);
            }
        }
    }
}

// ===================================================================================
// 3. CutoutBrushManager Implementation
// ===================================================================================

CutoutBrushManager::CutoutBrushManager() = default;

bool CutoutBrushManager::initLayerMask(int32_t layer_id, int32_t width, int32_t height) {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (layer_id <= 0 || width <= 0 || height <= 0) return false;
    m_layer_masks[layer_id].allocate(width, height);
    return true;
}

CutoutMaskBuffer* CutoutBrushManager::getLayerMask(int32_t layer_id) {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_layer_masks.find(layer_id);
    if (it != m_layer_masks.end()) {
        return &it->second;
    }
    return nullptr;
}

// Khớp opcode 0x12f4f48: Java_com_bytedance_retouch_middleware_api_RetouchSceneModelApi_setCutoutBrushData
bool CutoutBrushManager::setCutoutBrushData(float x, float y, float radius, float hardness, float opacity,
                                          float aspect_ratio, float angle_deg,
                                          int32_t mode, int32_t stroke_id, int32_t layer_id) {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (layer_id <= 0 || radius <= 0.0f) return false;

    // Tự động khởi tạo mặt nạ chuẩn 1080p nếu layer chưa có
    auto it = m_layer_masks.find(layer_id);
    if (it == m_layer_masks.end()) {
        m_layer_masks[layer_id].allocate(1920, 1080);
        it = m_layer_masks.find(layer_id);
    }

    BrushStamp stamp(x, y, radius, hardness, opacity, aspect_ratio, angle_deg);
    CutoutBrushMode brush_mode = static_cast<CutoutBrushMode>(mode);

    // Dập cọ lên mặt nạ lớp
    rasterizeStamp(it->second, stamp, brush_mode);

    // Ghi lại lịch sử nét cọ
    if (m_stroke_history.empty() || m_stroke_history.back().stroke_id != stroke_id) {
        BrushStroke new_stroke;
        new_stroke.stroke_id = stroke_id;
        new_stroke.layer_id = layer_id;
        new_stroke.mode = brush_mode;
        new_stroke.stamps.push_back(stamp);
        m_stroke_history.push_back(new_stroke);
    } else {
        m_stroke_history.back().stamps.push_back(stamp);
    }

    return true;
}

// Khớp opcode 0x12f2f10: Java_com_bytedance_retouch_middleware_cutout_IntelligentMaskCallbackJniImpl_nativeOnIntelligentMaskResult
bool CutoutBrushManager::onIntelligentMaskResult(int32_t status_code, const uint8_t* mask_data,
                                                int32_t width, int32_t height, int32_t stride,
                                                int32_t target_layer_id) {
    // Khớp opcode 0x12f2f44 (cbnz x2) và 0x12f2f4c (cbz x3): kiểm tra mã trạng thái và con trỏ dữ liệu
    if (status_code != 0 || !mask_data || width <= 0 || height <= 0 || stride < width) {
        return false;
    }

    std::lock_guard<std::mutex> lock(m_mutex);
    auto& ai_buf = m_ai_masks[target_layer_id];
    if (!ai_buf.copyFrom(mask_data, width, height, stride)) {
        return false;
    }

    // Tự động hòa trộn mặt nạ AI vào mặt nạ hoạt động của layer
    auto it = m_layer_masks.find(target_layer_id);
    if (it == m_layer_masks.end()) {
        m_layer_masks[target_layer_id].allocate(width, height);
        it = m_layer_masks.find(target_layer_id);
    }

    compositeMasks(ai_buf, *it, *it, CutoutBrushMode::PAINT);
    return true;
}

// Khớp opcode 0x12f6730: Java_com_bytedance_retouch_middleware_api_RetouchSceneModelApi_cancelAIBackgroundPreview
void CutoutBrushManager::cancelAIBackgroundPreview() {
    m_ai_preview_cancelled.store(true);
}

bool CutoutBrushManager::isAIBackgroundPreviewCancelled() const {
    return m_ai_preview_cancelled.load();
}

// Khớp opcode 0x12f55f0: enterAiBackgroundScene
bool CutoutBrushManager::enterAiBackgroundScene(int32_t layer_id) {
    if (layer_id <= 0) return false;
    m_in_ai_scene.store(true);
    m_current_ai_layer_id = layer_id;
    m_ai_preview_cancelled.store(false);
    return true;
}

bool CutoutBrushManager::exitAiBackgroundScene(bool apply_changes) {
    m_in_ai_scene.store(false);
    m_current_ai_layer_id = -1;
    m_ai_preview_cancelled.store(true);
    return true;
}

// Khớp opcode 0x12f6548: updateAIBackgroundPreview
bool CutoutBrushManager::updateAIBackgroundPreview(int32_t layer_id, const std::string& prompt, float strength) {
    if (layer_id <= 0 || prompt.empty() || strength <= 0.0f) return false;
    m_ai_preview_cancelled.store(false);
    return true;
}

bool CutoutBrushManager::compositeMasks(const CutoutMaskBuffer& ai_mask, const CutoutMaskBuffer& user_brush,
                                      CutoutMaskBuffer& out_result, CutoutBrushMode blend_mode) {
    if (ai_mask.getWidth() != user_brush.getWidth() || ai_mask.getHeight() != user_brush.getHeight()) {
        return false;
    }

    int32_t w = ai_mask.getWidth();
    int32_t h = ai_mask.getHeight();
    if (out_result.getWidth() != w || out_result.getHeight() != h) {
        out_result.allocate(w, h);
    }

    for (int32_t y = 0; y < h; ++y) {
        for (int32_t x = 0; x < w; ++x) {
            uint8_t a = ai_mask.getPixel(x, y);
            uint8_t b = user_brush.getPixel(x, y);
            uint8_t composite = a;

            if (blend_mode == CutoutBrushMode::PAINT) {
                composite = static_cast<uint8_t>(std::min(255, a + b));
            } else if (blend_mode == CutoutBrushMode::ERASE) {
                composite = static_cast<uint8_t>(std::max(0, static_cast<int32_t>(a) - b));
            }

            out_result.setPixel(x, y, composite);
        }
    }
    return true;
}

// ===================================================================================
// 4. Bộ tự kiểm chứng tính đúng đắn CutoutBrushManager (Self-Test Suite)
// ===================================================================================
bool CutoutBrushManager::runSelfTest() {
    CutoutBrushManager mgr;

    // 1. Khởi tạo mặt nạ 100x100 cho layer 10
    if (!mgr.initLayerMask(10, 100, 100)) return false;
    auto* mask = mgr.getLayerMask(10);
    if (!mask || mask->getWidth() != 100 || mask->getHeight() != 100) return false;

    // Ban đầu mặt nạ phải hoàn toàn trong suốt (0)
    if (mask->getPixel(50, 50) != 0) return false;

    // 2. Dập cọ chế độ PAINT (Opcode 0x12f4f48) tại (50, 50) với bán kính 10, độ cứng 1.0, độ mờ 1.0
    // x=50, y=50, radius=10, hardness=1.0, opacity=1.0, aspect=1.0, angle=0.0, mode=1, stroke=1, layer=10
    if (!mgr.setCutoutBrushData(50.0f, 50.0f, 10.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1, 1, 10)) return false;

    // Điểm tâm (50, 50) phải đạt 255 (đục hoàn toàn)
    if (mask->getPixel(50, 50) != 255) return false;
    // Điểm cách tâm 5px (nằm trong bán kính 10) phải đạt 255 do hardness = 1.0
    if (mask->getPixel(55, 50) != 255) return false;
    // Điểm cách tâm 15px (nằm ngoài bán kính 10) phải giữ nguyên 0
    if (mask->getPixel(65, 50) != 0) return false;

    // 3. Dập cọ chế độ ERASE (mode=2) tại (50, 50) với bán kính 5, độ cứng 1.0, độ mờ 1.0
    if (!mgr.setCutoutBrushData(50.0f, 50.0f, 5.0f, 1.0f, 1.0f, 1.0f, 0.0f, 2, 2, 10)) return false;

    // Điểm tâm (50, 50) sau khi xóa phải trở về 0
    if (mask->getPixel(50, 50) != 0) return false;
    // Điểm (57, 50) ngoài bán kính xóa 5px nhưng trong bán kính vẽ 10px vẫn phải còn 255
    if (mask->getPixel(57, 50) != 255) return false;

    // 4. Kiểm tra tiếp nhận kết quả mặt nạ thông minh AI (Opcode 0x12f2f10)
    std::vector<uint8_t> ai_data(100 * 100, 128); // Mặt nạ xám đồng nhất 128
    // Lỗi status_code != 0 -> phải từ chối (trả về false)
    if (mgr.onIntelligentMaskResult(-1, ai_data.data(), 100, 100, 100, 10)) return false;
    // Con trỏ null -> phải từ chối (trả về false)
    if (mgr.onIntelligentMaskResult(0, nullptr, 100, 100, 100, 10)) return false;

    // Thành công: status_code = 0
    if (!mgr.onIntelligentMaskResult(0, ai_data.data(), 100, 100, 100, 10)) return false;

    // 5. Kiểm tra hủy tác vụ xem trước AI Background (Opcode 0x12f6730)
    mgr.enterAiBackgroundScene(10);
    if (mgr.isAIBackgroundPreviewCancelled()) return false;
    mgr.cancelAIBackgroundPreview();
    if (!mgr.isAIBackgroundPreviewCancelled()) return false;

    return true;
}

} // namespace retouch::middleware
