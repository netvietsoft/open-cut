// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libretouch_sdk.so (ByteDance Face & Body Retouch SDK)
// File: retouch_types.h
// Description: Core data types, Face106 landmarks, beauty parameters, and ABI structs
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <array>

namespace retouch_sdk {

// EN: 2D Point structure for facial landmarks and deformation vectors
// VN: Cấu trúc điểm 2D cho điểm mốc khuôn mặt và vector biến dạng
struct Point2F {
    float x = 0.0f;
    float y = 0.0f;

    Point2F() = default;
    Point2F(float _x, float _y) : x(_x), y(_y) {}
};

// EN: 106-Point Facial Landmark representation (ByteDance Face106 standard)
// VN: Biểu diễn 106 điểm mốc khuôn mặt chuẩn Face106 của ByteDance
struct Face106Landmarks {
    std::array<Point2F, 106> points;
    float score = 0.0f;
    float yaw = 0.0f;
    float pitch = 0.0f;
    float roll = 0.0f;
    float eye_distance = 0.0f;
    Point2F face_center;

    // Landmark indices for key features:
    // Left eye center: 74, Right eye center: 77
    // Nose tip: 46, Mouth center: 84, Chin: 16
    static constexpr int32_t IDX_LEFT_EYE = 74;
    static constexpr int32_t IDX_RIGHT_EYE = 77;
    static constexpr int32_t IDX_NOSE_TIP = 46;
    static constexpr int32_t IDX_MOUTH_CENTER = 84;
    static constexpr int32_t IDX_CHIN = 16;
};

// EN: Beauty intensity parameters (Smooth, Whitening, Slim, Eye, Teeth, Lip)
// VN: Tham số cường độ làm đẹp (Mịn da, Trắng da, Gọt mặt, To mắt, Trắng răng, Son môi)
struct BeautyIntensityParams {
    float smooth_intensity = 0.0f;      // 0.0 to 1.0 (Làm mịn da)
    float whitening_intensity = 0.0f;   // 0.0 to 1.0 (Trắng da toàn diện)
    float face_slim_intensity = 0.0f;   // 0.0 to 1.0 (Gọt hàm thon gọn)
    float eye_enlarge_intensity = 0.0f; // 0.0 to 1.0 (Phóng to mắt)
    float teeth_whiten_intensity = 0.0f;// 0.0 to 1.0 (Tẩy trắng men răng)
    float lipstick_intensity = 0.0f;    // 0.0 to 1.0 (Đậm nhạt son môi)
    uint32_t lipstick_color_rgb = 0xDE3163; // Default Rose Red (Đỏ hồng)
};

// EN: Body reshaping parameters (Leg extension, Waist slimming)
// VN: Tham số định hình cơ thể (Kéo dài chân, Thon gọn eo)
struct BodyReshapeParams {
    float leg_extend_ratio = 0.0f;      // 0.0 to 0.40 (Kéo dài chân in-frame)
    float waist_slim_ratio = 0.0f;      // 0.0 to 0.30 (Thu nhỏ vòng eo)
    float hip_line_y = 0.60f;           // Normalized Y coord of hip (0.0 to 1.0)
    float ankle_line_y = 0.90f;         // Normalized Y coord of ankle (0.0 to 1.0)
};

// EN: VIP Layer Property Info matching ABI symbol _ZNK11retouch_sdk13LayerPropInfo19GetAvailableVipInfoEv
// VN: Thông tin quyền VIP của layer khớp biểu tượng ABI 0x8d2e0
struct LayerPropInfo {
    int32_t layer_id = 0;
    bool is_vip_feature = false;
    int32_t min_vip_level = 0;
    std::string feature_name = "";

    bool IsAvailableForVip(int32_t current_vip_level) const {
        return !is_vip_feature || (current_vip_level >= min_vip_level);
    }
};

} // namespace retouch_sdk

namespace painter {

// EN: Composer Intensity Descriptor matching ABI symbol vector<painter::ComposerIntensityDesc>
// VN: Mô tả cường độ bộ hòa trộn hiệu ứng khớp biểu tượng vector tại opcode 0x140560
struct ComposerIntensityDesc {
    std::string tag = "";
    float intensity = 0.0f;
    int32_t sub_type = 0;
};

// EN: Painter Parameters matching ABI symbol painter::JniHelper::JavaToCpp (opcode 0x847c0)
// VN: Tham số cấu hình Painter khớp hàm chuyển đổi JNI tại opcode 0x847c0
struct PainterPrams {
    int32_t canvas_width = 1080;
    int32_t canvas_height = 1920;
    float render_scale = 1.0f;
    std::vector<ComposerIntensityDesc> intensities;
};

} // namespace painter
