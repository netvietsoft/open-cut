// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libmiddle-bridge.so (ByteDance VE SDK Middle Bridge NLE Core)
// File: middle_bridge_mask.cpp
// Description: Full implementation of CapCut Video & Overlay Masking Engine
// Bilingual Comments: English + Vietnamese (Rule 12 AGENTS.md)
// ===================================================================================

#include "middle_bridge_mask.h"
#include <cmath>
#include <algorithm>

namespace vesdk {
namespace pub {

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// ===================================================================================
// 1. MASK SAMPLING & SDF KERNEL
// Hạt nhân Tính toán Hàm Khoảng cách Dấu (SDF) và Lấy Mẫu Mặt nạ
// ===================================================================================

/**
 * @brief Samples mask alpha value [0.0, 1.0] at normalized screen coordinates (-1.0 to 1.0).
 * Lấy mẫu giá trị độ mờ alpha [0.0, 1.0] tại tọa độ chuẩn hóa màn hình.
 */
float SampleMaskAlpha(const MaterialMask& mask, float norm_x, float norm_y) {
    const MaskPositionInfo& pos = mask.position_info;

    // 1. Translate relative to mask center
    float dx = norm_x - pos.center_x;
    float dy = norm_y - pos.center_y;

    // 2. Rotate by negative rotation angle
    float rad = (float)(-pos.rotation_deg * M_PI / 180.0);
    float cos_r = std::cos(rad);
    float sin_r = std::sin(rad);

    float rx = dx * cos_r - dy * sin_r;
    float ry = dx * sin_r + dy * cos_r;

    float alpha = 1.0f;
    float feather_val = std::max(0.001f, pos.feather);

    switch (mask.type) {
        case MaskType::LINEAR: {
            // Linear split plane mask
            float dist = rx;
            alpha = (dist / feather_val) + 0.5f;
            alpha = std::max(0.0f, std::min(1.0f, alpha));
            break;
        }
        case MaskType::MIRROR: {
            // Bilateral symmetry mirror mask
            float half_w = pos.width * 0.5f;
            float dist = half_w - std::abs(rx);
            alpha = (dist / feather_val) + 0.5f;
            alpha = std::max(0.0f, std::min(1.0f, alpha));
            break;
        }
        case MaskType::CIRCLE: {
            // Elliptical mask
            float scaled_x = (pos.width > 1e-4f) ? (rx / pos.width) : 0.0f;
            float scaled_y = (pos.height > 1e-4f) ? (ry / pos.height) : 0.0f;
            float dist_sq = scaled_x * scaled_x + scaled_y * scaled_y;
            float dist = std::sqrt(dist_sq);

            // Feathering boundary
            float edge_dist = 1.0f - dist;
            alpha = edge_dist / feather_val;
            alpha = std::max(0.0f, std::min(1.0f, alpha));
            break;
        }
        case MaskType::RECTANGLE: {
            // Rounded rectangle box SDF
            float half_w = pos.width * 0.5f;
            float half_h = pos.height * 0.5f;
            float qx = std::abs(rx) - half_w;
            float qy = std::abs(ry) - half_h;

            float outside_dist = std::sqrt(std::max(0.0f, qx) * std::max(0.0f, qx) +
                                           std::max(0.0f, qy) * std::max(0.0f, qy));
            float inside_dist = std::min(0.0f, std::max(qx, qy));
            float signed_dist = outside_dist + inside_dist;

            alpha = -signed_dist / feather_val;
            alpha = std::max(0.0f, std::min(1.0f, alpha));
            break;
        }
        default:
            alpha = 1.0f;
            break;
    }

    if (pos.invert) {
        alpha = 1.0f - alpha;
    }

    return alpha;
}

/**
 * @brief Renders 8-bit alpha mask buffer for video compositor blending.
 * Kết xuất bộ đệm alpha 8-bit phục vụ hòa trộn video và lớp phủ PIP.
 */
void RenderMaskBuffer(const MaterialMask& mask, uint8_t* alpha_buffer, int width, int height) {
    if (!alpha_buffer || width <= 0 || height <= 0) return;

    for (int y = 0; y < height; y++) {
        float norm_y = ((float)y / (float)height) * 2.0f - 1.0f;
        for (int x = 0; x < width; x++) {
            float norm_x = ((float)x / (float)width) * 2.0f - 1.0f;
            float alpha = SampleMaskAlpha(mask, norm_x, norm_y);
            alpha_buffer[y * width + x] = (uint8_t)(alpha * 255.0f);
        }
    }
}

} // namespace pub
} // namespace vesdk


// ===================================================================================
// 2. JNI SWIG EXPORTED WRAPPERS FOR MATERIAL MASK
// Các hàm JNI SWIG liên kết với Java
// ===================================================================================

using namespace vesdk::pub;

JNIEXPORT void JNICALL Java_com_vega_middlebridge_swig_MaterialMaskModuleJNI_delete_1MaterialMask(JNIEnv *env, jclass cls, jlong jarg1) {
    (void)env; (void)cls;
    auto* holder = (std::shared_ptr<MaterialMask>*)jarg1;
    if (holder) {
        delete holder;
    }
}

JNIEXPORT jstring JNICALL Java_com_vega_middlebridge_swig_MaterialMaskModuleJNI_MaterialMask_1getResourceId(JNIEnv *env, jclass cls, jlong jarg1) {
    (void)cls;
    auto* holder = (std::shared_ptr<MaterialMask>*)jarg1;
    if (holder && *holder) {
        return env->NewStringUTF((*holder)->resource_id.c_str());
    }
    return nullptr;
}

JNIEXPORT jstring JNICALL Java_com_vega_middlebridge_swig_MaterialMaskModuleJNI_MaterialMask_1getPath(JNIEnv *env, jclass cls, jlong jarg1) {
    (void)cls;
    auto* holder = (std::shared_ptr<MaterialMask>*)jarg1;
    if (holder && *holder) {
        return env->NewStringUTF((*holder)->path.c_str());
    }
    return nullptr;
}

JNIEXPORT jstring JNICALL Java_com_vega_middlebridge_swig_MaterialMaskModuleJNI_MaterialMask_1getNodeName(JNIEnv *env, jclass cls, jlong jarg1) {
    (void)cls;
    auto* holder = (std::shared_ptr<MaterialMask>*)jarg1;
    if (holder && *holder) {
        return env->NewStringUTF((*holder)->node_name.c_str());
    }
    return nullptr;
}

/**
 * @brief Returns MaskPositionInfo pointer located at offset 0x90.
 * Khớp hoàn toàn opcode ARM64: 0x024ed08c (add x0, x0, #0x90; ret)
 */
JNIEXPORT jlong JNICALL Java_com_vega_middlebridge_swig_MaterialMaskModuleJNI_MaterialMask_1getPositionInfo(JNIEnv *env, jclass cls, jlong jarg1) {
    (void)env; (void)cls;
    auto* holder = (std::shared_ptr<MaterialMask>*)jarg1;
    if (holder && *holder) {
        // Opcode 0x024ed08c: adds 0x90 to raw pointer
        return (jlong)&((*holder)->position_info);
    }
    return 0;
}
