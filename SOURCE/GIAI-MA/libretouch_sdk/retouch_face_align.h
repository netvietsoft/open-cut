// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libretouch_sdk.so (ByteDance Face & Body Retouch SDK)
// File: retouch_face_align.h
// Description: Face106 landmarks parser, head pose estimation, affine normalization
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#pragma once

#include "retouch_types.h"
#include <vector>
#include <cmath>
#include <string>

namespace retouch_sdk {

// EN: Face bounding box in normalized coordinates [0.0, 1.0]
// VN: Hộp bao khuôn mặt theo tọa độ chuẩn hóa [0.0, 1.0]
struct FaceBoundingBox {
    float left = 0.0f;
    float top = 0.0f;
    float right = 0.0f;
    float bottom = 0.0f;
    float width() const { return right - left; }
    float height() const { return bottom - top; }
    Point2F center() const { return Point2F((left + right) * 0.5f, (top + bottom) * 0.5f); }
};

// EN: 2x3 Affine Transformation Matrix [a11, a12, tx; a21, a22, ty]
// VN: Ma trận biến đổi Affine 2x3 [a11, a12, tx; a21, a22, ty]
struct AffineMatrix2x3 {
    float a11 = 1.0f, a12 = 0.0f, tx = 0.0f;
    float a21 = 0.0f, a22 = 1.0f, ty = 0.0f;

    // EN: Transform point by affine matrix (Opcode 0x153168)
    // VN: Biến đổi tọa độ điểm qua ma trận affine (Opcode 0x153168)
    Point2F Transform(const Point2F& pt) const {
        return Point2F(
            a11 * pt.x + a12 * pt.y + tx,
            a21 * pt.x + a22 * pt.y + ty
        );
    }

    // EN: Compute inverse affine transform
    // VN: Tính ma trận nghịch đảo affine
    AffineMatrix2x3 Invert() const {
        float det = a11 * a22 - a12 * a21;
        if (std::abs(det) < 1e-7f) {
            return AffineMatrix2x3(); // Identity on singular matrix
        }
        float inv_det = 1.0f / det;
        AffineMatrix2x3 inv;
        inv.a11 =  a22 * inv_det;
        inv.a12 = -a12 * inv_det;
        inv.tx  = (a12 * ty - a22 * tx) * inv_det;
        inv.a21 = -a21 * inv_det;
        inv.a22 =  a11 * inv_det;
        inv.ty  = (a21 * tx - a11 * ty) * inv_det;
        return inv;
    }
};

// EN: Facial Alignment and Pose Estimator
// VN: Bộ ước lượng góc quay tư thế đầu và căn chỉnh khuôn mặt
class FaceAligner {
public:
    FaceAligner();
    ~FaceAligner();

    // EN: Parse 106 2D points from float buffer (length >= 212)
    // VN: Trích xuất 106 điểm mốc 2D từ mảng float (chiều dài tối thiểu 212)
    bool ParseLandmarks(const float* raw_coords, size_t count, Face106Landmarks& out_landmarks);

    // EN: Compute tight bounding box enclosing Face106 landmarks
    // VN: Tính hộp bao khít bao quanh 106 điểm mốc khuôn mặt
    FaceBoundingBox ComputeBoundingBox(const Face106Landmarks& landmarks, float padding_ratio = 0.20f);

    // EN: Estimate head pose angles (Yaw, Pitch, Roll in degrees) from key landmarks
    // VN: Ước lượng các góc tư thế đầu (Yaw, Pitch, Roll theo độ) từ điểm mốc chính
    void EstimatePose(Face106Landmarks& landmarks);

    // EN: Calculate 2x3 affine matrix to align face to canonical canonical_size x canonical_size space
    // VN: Tính ma trận affine 2x3 để căn chuẩn khuôn mặt về không gian chuẩn hóa canonical_size
    AffineMatrix2x3 ComputeCanonicalAffine(const Face106Landmarks& landmarks, int32_t target_size = 256);

    // EN: Check if landmarks represent a valid detectable human face
    // VN: Kiểm tra tính hợp lệ hình học của các điểm mốc khuôn mặt
    bool ValidateLandmarks(const Face106Landmarks& landmarks) const;
};

} // namespace retouch_sdk
