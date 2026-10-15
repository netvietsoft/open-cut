// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libretouch_sdk.so (ByteDance Face & Body Retouch SDK)
// File: retouch_face_align.cpp
// Description: Implementation of Face106 landmarks parser, pose estimator, affine alignment
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#include "retouch_face_align.h"
#include <algorithm>
#include <cmath>
#include <cstring>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace retouch_sdk {

// EN: Default constructor for FaceAligner
// VN: Hàm khởi tạo mặc định cho FaceAligner
FaceAligner::FaceAligner() = default;

// EN: Destructor for FaceAligner
// VN: Hàm hủy cho FaceAligner
FaceAligner::~FaceAligner() = default;

// EN: Parse 106 2D points from raw float coordinate buffer (Opcode 0x847c0)
// VN: Phân tích cú pháp 106 điểm mốc 2D từ mảng tọa độ float thô (Opcode 0x847c0)
bool FaceAligner::ParseLandmarks(const float* raw_coords, size_t count, Face106Landmarks& out_landmarks) {
    if (!raw_coords || count < 212) {
        return false;
    }

    float sum_x = 0.0f;
    float sum_y = 0.0f;

    for (size_t i = 0; i < 106; ++i) {
        float px = raw_coords[i * 2 + 0];
        float py = raw_coords[i * 2 + 1];
        out_landmarks.points[i] = Point2F(px, py);
        sum_x += px;
        sum_y += py;
    }

    out_landmarks.face_center = Point2F(sum_x / 106.0f, sum_y / 106.0f);

    // Compute inter-ocular distance (Landmark 74: Left eye center, Landmark 77: Right eye center)
    const Point2F& left_eye = out_landmarks.points[Face106Landmarks::IDX_LEFT_EYE];
    const Point2F& right_eye = out_landmarks.points[Face106Landmarks::IDX_RIGHT_EYE];
    float dx = right_eye.x - left_eye.x;
    float dy = right_eye.y - left_eye.y;
    out_landmarks.eye_distance = std::sqrt(dx * dx + dy * dy);

    // Estimate 3D Euler pose angles
    EstimatePose(out_landmarks);

    return ValidateLandmarks(out_landmarks);
}

// EN: Compute tight bounding box enclosing Face106 landmarks with configurable margin
// VN: Tính hộp bao khít 106 điểm mốc khuôn mặt với lề đệm cấu hình được
FaceBoundingBox FaceAligner::ComputeBoundingBox(const Face106Landmarks& landmarks, float padding_ratio) {
    FaceBoundingBox bbox;
    if (landmarks.points.empty()) {
        return bbox;
    }

    float min_x = landmarks.points[0].x;
    float max_x = landmarks.points[0].x;
    float min_y = landmarks.points[0].y;
    float max_y = landmarks.points[0].y;

    for (size_t i = 1; i < 106; ++i) {
        const auto& pt = landmarks.points[i];
        if (pt.x < min_x) min_x = pt.x;
        if (pt.x > max_x) max_x = pt.x;
        if (pt.y < min_y) min_y = pt.y;
        if (pt.y > max_y) max_y = pt.y;
    }

    float w = max_x - min_x;
    float h = max_y - min_y;
    float pad_x = w * padding_ratio;
    float pad_y = h * padding_ratio;

    bbox.left = std::max(0.0f, min_x - pad_x);
    bbox.top = std::max(0.0f, min_y - pad_y);
    bbox.right = max_x + pad_x;
    bbox.bottom = max_y + pad_y;

    return bbox;
}

// EN: Estimate head pose angles (Yaw, Pitch, Roll in degrees) from key landmarks (Opcode 0x847c0)
// VN: Ước lượng các góc tư thế đầu (Yaw, Pitch, Roll theo độ) từ điểm mốc chính (Opcode 0x847c0)
void FaceAligner::EstimatePose(Face106Landmarks& landmarks) {
    const Point2F& p_left_eye = landmarks.points[Face106Landmarks::IDX_LEFT_EYE];
    const Point2F& p_right_eye = landmarks.points[Face106Landmarks::IDX_RIGHT_EYE];
    const Point2F& p_nose = landmarks.points[Face106Landmarks::IDX_NOSE_TIP];
    const Point2F& p_mouth = landmarks.points[Face106Landmarks::IDX_MOUTH_CENTER];
    const Point2F& p_left_contour = landmarks.points[0];   // Outer left cheek contour
    const Point2F& p_right_contour = landmarks.points[32]; // Outer right cheek contour

    // 1. Roll (In-plane rotation around Z axis)
    // VN: Góc nghiêng trong mặt phẳng ảnh quanh trục Z
    float delta_x = p_right_eye.x - p_left_eye.x;
    float delta_y = p_right_eye.y - p_left_eye.y;
    landmarks.roll = static_cast<float>(std::atan2(delta_y, delta_x) * (180.0 / M_PI));

    // 2. Yaw (Out-of-plane rotation around vertical Y axis via bilateral facial symmetry)
    // VN: Góc quay ngang quanh trục thẳng đứng Y thông qua tính đối xứng hai bên gò má
    float dist_left = std::abs(p_nose.x - p_left_contour.x);
    float dist_right = std::abs(p_right_contour.x - p_nose.x);
    float total_dist = dist_left + dist_right;
    if (total_dist > 1e-4f) {
        float symmetry_ratio = (dist_right - dist_left) / total_dist;
        landmarks.yaw = symmetry_ratio * 75.0f; // Scale to degrees approximation [-75, +75]
    } else {
        landmarks.yaw = 0.0f;
    }

    // 3. Pitch (Nodding rotation around lateral X axis via vertical proportion)
    // VN: Góc cúi/ngửa quanh trục ngang X thông qua tỉ lệ khoảng cách mắt-mũi-miệng
    float eye_center_y = (p_left_eye.y + p_right_eye.y) * 0.5f;
    float dist_eye_nose = p_nose.y - eye_center_y;
    float dist_nose_mouth = p_mouth.y - p_nose.y;
    float total_vert = dist_eye_nose + dist_nose_mouth;
    if (total_vert > 1e-4f) {
        float vert_ratio = (dist_nose_mouth - dist_eye_nose) / total_vert;
        landmarks.pitch = vert_ratio * 55.0f; // Scale to degrees approximation [-55, +55]
    } else {
        landmarks.pitch = 0.0f;
    }
}

// EN: Calculate 2x3 affine matrix to align face to canonical canonical_size coordinate frame (Opcode 0x153168)
// VN: Tính ma trận affine 2x3 căn chuẩn khuôn mặt về khung tọa độ chuẩn hóa kích thước target_size (Opcode 0x153168)
AffineMatrix2x3 FaceAligner::ComputeCanonicalAffine(const Face106Landmarks& landmarks, int32_t target_size) {
    AffineMatrix2x3 affine;
    const Point2F& p_left_eye = landmarks.points[Face106Landmarks::IDX_LEFT_EYE];
    const Point2F& p_right_eye = landmarks.points[Face106Landmarks::IDX_RIGHT_EYE];

    float src_eye_center_x = (p_left_eye.x + p_right_eye.x) * 0.5f;
    float src_eye_center_y = (p_left_eye.y + p_right_eye.y) * 0.5f;

    float dx = p_right_eye.x - p_left_eye.x;
    float dy = p_right_eye.y - p_left_eye.y;
    float current_eye_dist = std::sqrt(dx * dx + dy * dy);

    // Target eye distance in canonical space (approximately 35% of canonical image width)
    float target_eye_dist = static_cast<float>(target_size) * 0.35f;
    float scale = (current_eye_dist > 1e-4f) ? (target_eye_dist / current_eye_dist) : 1.0f;

    // Angle to rotate so eyes are horizontal
    float angle_rad = -std::atan2(dy, dx);
    float cos_a = std::cos(angle_rad) * scale;
    float sin_a = std::sin(angle_rad) * scale;

    // Target eye center placed at 50% width and 40% height of canonical canvas
    float dst_eye_center_x = static_cast<float>(target_size) * 0.50f;
    float dst_eye_center_y = static_cast<float>(target_size) * 0.40f;

    affine.a11 = cos_a;
    affine.a12 = -sin_a;
    affine.tx  = dst_eye_center_x - (cos_a * src_eye_center_x - sin_a * src_eye_center_y);

    affine.a21 = sin_a;
    affine.a22 = cos_a;
    affine.ty  = dst_eye_center_y - (sin_a * src_eye_center_x + cos_a * src_eye_center_y);

    return affine;
}

// EN: Validate landmarks geometry against human anatomy rules
// VN: Kiểm tra tính hợp lệ hình học của các điểm mốc theo giải phẫu khuôn mặt người
bool FaceAligner::ValidateLandmarks(const Face106Landmarks& landmarks) const {
    if (landmarks.eye_distance <= 0.0f) {
        return false;
    }

    const Point2F& p_left_eye = landmarks.points[Face106Landmarks::IDX_LEFT_EYE];
    const Point2F& p_right_eye = landmarks.points[Face106Landmarks::IDX_RIGHT_EYE];
    const Point2F& p_nose = landmarks.points[Face106Landmarks::IDX_NOSE_TIP];
    const Point2F& p_chin = landmarks.points[Face106Landmarks::IDX_CHIN];

    // Left eye must be to the left of right eye in face coordinate system
    if (p_right_eye.x <= p_left_eye.x && std::abs(landmarks.roll) < 45.0f) {
        return false;
    }

    // Nose must be vertically between eye line and chin
    float eye_y = (p_left_eye.y + p_right_eye.y) * 0.5f;
    if (std::abs(landmarks.roll) < 45.0f) {
        if (p_nose.y <= eye_y || p_nose.y >= p_chin.y) {
            return false;
        }
    }

    return true;
}

} // namespace retouch_sdk
