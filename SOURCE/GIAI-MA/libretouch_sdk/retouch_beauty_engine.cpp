// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libretouch_sdk.so (ByteDance Face & Body Retouch SDK)
// File: retouch_beauty_engine.cpp
// Description: Implementation of facial retouching, bilateral filter, warping algorithms
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#include "retouch_beauty_engine.h"
#include <algorithm>
#include <cmath>
#include <cstring>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace retouch_sdk {

// EN: Constructor initializing Gaussian kernel weights
// VN: Hàm khởi tạo thiết lập trọng số ma trận Gauss không gian
BeautyEngine::BeautyEngine() {
    InitSpatialWeights(2.0f);
}

// EN: Destructor
// VN: Hàm hủy
BeautyEngine::~BeautyEngine() = default;

// EN: Initialize 5x5 spatial Gaussian weights for bilateral filter
// VN: Khởi tạo trọng số Gauss không gian 5x5 cho bộ lọc song phương
void BeautyEngine::InitSpatialWeights(float sigma_s) {
    float two_sigma_sq = 2.0f * sigma_s * sigma_s;
    for (int dy = -2; dy <= 2; ++dy) {
        for (int dx = -2; dx <= 2; ++dx) {
            float dist_sq = static_cast<float>(dx * dx + dy * dy);
            m_gaussian_spatial[dy + 2][dx + 2] = std::exp(-dist_sq / two_sigma_sq);
        }
    }
}

// EN: Set beauty intensity parameters (Opcode 0xcbc80: nativeSetIntensities)
// VN: Cấu hình cường độ các bộ lọc làm đẹp (Opcode 0xcbc80: nativeSetIntensities)
void BeautyEngine::SetIntensities(const BeautyIntensityParams& params) {
    m_params.smooth_intensity      = std::clamp(params.smooth_intensity, 0.0f, 1.0f);
    m_params.whitening_intensity   = std::clamp(params.whitening_intensity, 0.0f, 1.0f);
    m_params.face_slim_intensity   = std::clamp(params.face_slim_intensity, 0.0f, 1.0f);
    m_params.eye_enlarge_intensity = std::clamp(params.eye_enlarge_intensity, 0.0f, 1.0f);
    m_params.teeth_whiten_intensity= std::clamp(params.teeth_whiten_intensity, 0.0f, 1.0f);
    m_params.lipstick_intensity    = std::clamp(params.lipstick_intensity, 0.0f, 1.0f);
    m_params.lipstick_color_rgb    = params.lipstick_color_rgb;
}

// EN: Reset/remove makeup composer descriptors (Opcode 0xcb9b8: nativeRemoveMakeupComposer)
// VN: Đặt lại và loại bỏ bộ hòa trộn hiệu ứng trang điểm (Opcode 0xcb9b8: nativeRemoveMakeupComposer)
void BeautyEngine::ResetMakeupComposer() {
    m_params = BeautyIntensityParams();
}

// EN: Generate skin tone probability mask using YCrCb color space Gaussian distribution
// VN: Tạo mặt nạ xác suất màu da dùng phân phối Gauss trong không gian màu YCrCb
std::vector<float> BeautyEngine::GenerateSkinMask(const ImageBuffer& src) {
    size_t pixel_count = static_cast<size_t>(src.width * src.height);
    std::vector<float> mask(pixel_count, 0.0f);

    const float cr_mean = 150.0f, cr_sigma = 18.0f;
    const float cb_mean = 105.0f, cb_sigma = 18.0f;
    const float two_cr_sigma_sq = 2.0f * cr_sigma * cr_sigma;
    const float two_cb_sigma_sq = 2.0f * cb_sigma * cb_sigma;

    for (int y = 0; y < src.height; ++y) {
        for (int x = 0; x < src.width; ++x) {
            const uint8_t* p = src.GetPixel(x, y);
            float r = static_cast<float>(p[0]);
            float g = static_cast<float>(p[1]);
            float b = static_cast<float>(p[2]);

            // RGB to YCrCb transformation matrix
            float cr = 0.5000f * r - 0.4187f * g - 0.0813f * b + 128.0f;
            float cb = -0.1687f * r - 0.3313f * g + 0.5000f * b + 128.0f;

            float d_cr = cr - cr_mean;
            float d_cb = cb - cb_mean;
            float prob = std::exp(-(d_cr * d_cr) / two_cr_sigma_sq - (d_cb * d_cb) / two_cb_sigma_sq);

            mask[y * src.width + x] = prob;
        }
    }
    return mask;
}

// EN: Apply edge-preserving bilateral skin smoothing (Opcode 0xcbc80)
// VN: Áp dụng bộ lọc song phương làm mịn da bảo toàn chi tiết cạnh (Opcode 0xcbc80)
void BeautyEngine::ApplySkinSmoothing(const ImageBuffer& src, ImageBuffer& dst, const std::vector<float>& skin_mask) {
    if (m_params.smooth_intensity <= 0.001f) {
        dst = src;
        return;
    }

    dst = src;
    const float sigma_r = 30.0f;
    const float two_sigma_r_sq = 2.0f * sigma_r * sigma_r;

    for (int y = 2; y < src.height - 2; ++y) {
        for (int x = 2; x < src.width - 2; ++x) {
            float m = skin_mask[y * src.width + x];
            if (m < 0.08f) continue; // Skip non-skin regions to preserve hair, eyes, background

            const uint8_t* center_px = src.GetPixel(x, y);
            float c_r = static_cast<float>(center_px[0]);
            float c_g = static_cast<float>(center_px[1]);
            float c_b = static_cast<float>(center_px[2]);

            float sum_weights = 0.0f;
            float sum_r = 0.0f, sum_g = 0.0f, sum_b = 0.0f;

            for (int dy = -2; dy <= 2; ++dy) {
                for (int dx = -2; dx <= 2; ++dx) {
                    const uint8_t* q = src.GetPixel(x + dx, y + dy);
                    float q_r = static_cast<float>(q[0]);
                    float q_g = static_cast<float>(q[1]);
                    float q_b = static_cast<float>(q[2]);

                    // Photometric color range distance
                    float dr = q_r - c_r;
                    float dg = q_g - c_g;
                    float db = q_b - c_b;
                    float color_dist_sq = dr * dr + dg * dg + db * db;

                    float w_range = std::exp(-color_dist_sq / two_sigma_r_sq);
                    float w_total = m_gaussian_spatial[dy + 2][dx + 2] * w_range;

                    sum_weights += w_total;
                    sum_r += q_r * w_total;
                    sum_g += q_g * w_total;
                    sum_b += q_b * w_total;
                }
            }

            if (sum_weights > 1e-5f) {
                float smooth_r = sum_r / sum_weights;
                float smooth_g = sum_g / sum_weights;
                float smooth_b = sum_b / sum_weights;

                float blend_alpha = m_params.smooth_intensity * m;
                uint8_t* out_px = dst.GetPixel(x, y);
                out_px[0] = static_cast<uint8_t>(std::clamp(c_r * (1.0f - blend_alpha) + smooth_r * blend_alpha, 0.0f, 255.0f));
                out_px[1] = static_cast<uint8_t>(std::clamp(c_g * (1.0f - blend_alpha) + smooth_g * blend_alpha, 0.0f, 255.0f));
                out_px[2] = static_cast<uint8_t>(std::clamp(c_b * (1.0f - blend_alpha) + smooth_b * blend_alpha, 0.0f, 255.0f));
            }
        }
    }
}

// EN: Apply skin tone whitening with luminance curve adjustment
// VN: Làm trắng da thông qua hiệu chỉnh đường cong độ sáng
void BeautyEngine::ApplySkinWhitening(ImageBuffer& img, const std::vector<float>& skin_mask) {
    if (m_params.whitening_intensity <= 0.001f) return;

    float intensity = m_params.whitening_intensity * 0.28f;

    for (int y = 0; y < img.height; ++y) {
        for (int x = 0; x < img.width; ++x) {
            float m = skin_mask[y * img.width + x];
            if (m < 0.08f) continue;

            uint8_t* p = img.GetPixel(x, y);
            float r = static_cast<float>(p[0]);
            float g = static_cast<float>(p[1]);
            float b = static_cast<float>(p[2]);

            // Gentle porcelain whitening: slightly boost blue and luminance
            float delta_r = (255.0f - r) * intensity * m * 0.90f;
            float delta_g = (255.0f - g) * intensity * m * 0.95f;
            float delta_b = (255.0f - b) * intensity * m * 1.05f;

            p[0] = static_cast<uint8_t>(std::clamp(r + delta_r, 0.0f, 255.0f));
            p[1] = static_cast<uint8_t>(std::clamp(g + delta_g, 0.0f, 255.0f));
            p[2] = static_cast<uint8_t>(std::clamp(b + delta_b, 0.0f, 255.0f));
        }
    }
}

// EN: Point-in-polygon test for mouth contour
// VN: Kiểm tra điểm nằm trong đa giác chu vi khuôn miệng
bool BeautyEngine::IsInPolygon(float px, float py, const std::vector<Point2F>& polygon) const {
    if (polygon.size() < 3) return false;
    bool inside = false;
    size_t count = polygon.size();
    for (size_t i = 0, j = count - 1; i < count; j = i++) {
        if (((polygon[i].y > py) != (polygon[j].y > py)) &&
            (px < (polygon[j].x - polygon[i].x) * (py - polygon[i].y) / (polygon[j].y - polygon[i].y) + polygon[i].x)) {
            inside = !inside;
        }
    }
    return inside;
}

// EN: Apply teeth whitening inside mouth landmark contour
// VN: Tẩy trắng răng trong phạm vi chu vi điểm mốc khuôn miệng
void BeautyEngine::ApplyTeethWhitening(ImageBuffer& img, const Face106Landmarks& landmarks) {
    if (m_params.teeth_whiten_intensity <= 0.001f) return;

    // Build inner mouth polygon from landmarks 96 to 105
    std::vector<Point2F> mouth_poly;
    for (int i = 96; i <= 105 && i < 106; ++i) {
        mouth_poly.push_back(landmarks.points[i]);
    }
    if (mouth_poly.size() < 3) return;

    // Find bounding box of mouth
    float min_x = mouth_poly[0].x, max_x = mouth_poly[0].x;
    float min_y = mouth_poly[0].y, max_y = mouth_poly[0].y;
    for (const auto& pt : mouth_poly) {
        min_x = std::min(min_x, pt.x);
        max_x = std::max(max_x, pt.x);
        min_y = std::min(min_y, pt.y);
        max_y = std::max(max_y, pt.y);
    }

    int start_x = std::max(0, static_cast<int>(min_x));
    int end_x   = std::min(img.width - 1, static_cast<int>(max_x));
    int start_y = std::max(0, static_cast<int>(min_y));
    int end_y   = std::min(img.height - 1, static_cast<int>(max_y));

    float boost = m_params.teeth_whiten_intensity * 0.35f;

    for (int y = start_y; y <= end_y; ++y) {
        for (int x = start_x; x <= end_x; ++x) {
            if (IsInPolygon(static_cast<float>(x), static_cast<float>(y), mouth_poly)) {
                uint8_t* p = img.GetPixel(x, y);
                float r = static_cast<float>(p[0]);
                float g = static_cast<float>(p[1]);
                float b = static_cast<float>(p[2]);

                // Teeth are characterized by moderate-to-high luminance and slight yellowish tint (R >= G >= B)
                float luminance = 0.299f * r + 0.587f * g + 0.114f * b;
                if (luminance > 110.0f && r >= b) {
                    // Reduce yellow cast by elevating blue towards red/green
                    float target_b = (r + g) * 0.5f;
                    float new_b = b + (target_b - b) * boost;
                    float new_r = r + (255.0f - r) * (boost * 0.5f);
                    float new_g = g + (255.0f - g) * (boost * 0.5f);

                    p[0] = static_cast<uint8_t>(std::clamp(new_r, 0.0f, 255.0f));
                    p[1] = static_cast<uint8_t>(std::clamp(new_g, 0.0f, 255.0f));
                    p[2] = static_cast<uint8_t>(std::clamp(new_b, 0.0f, 255.0f));
                }
            }
        }
    }
}

// EN: Apply radial mesh warp for eye enlargement (Opcode 0x153168: nativeTransformNormalizedCoordinates)
// VN: Biến dạng lưới bán kính phóng to mắt tự nhiên (Opcode 0x153168: nativeTransformNormalizedCoordinates)
void BeautyEngine::ApplyEyeEnlargement(const ImageBuffer& src, ImageBuffer& dst, const Face106Landmarks& landmarks) {
    if (m_params.eye_enlarge_intensity <= 0.001f) {
        dst = src;
        return;
    }

    dst = src;
    float eye_radius = landmarks.eye_distance * 0.28f;
    if (eye_radius <= 2.0f) return;

    float alpha = m_params.eye_enlarge_intensity * 0.35f;

    std::array<Point2F, 2> eye_centers = {
        landmarks.points[Face106Landmarks::IDX_LEFT_EYE],
        landmarks.points[Face106Landmarks::IDX_RIGHT_EYE]
    };

    for (const auto& center : eye_centers) {
        int min_x = std::max(0, static_cast<int>(center.x - eye_radius));
        int max_x = std::min(src.width - 1, static_cast<int>(center.x + eye_radius));
        int min_y = std::max(0, static_cast<int>(center.y - eye_radius));
        int max_y = std::min(src.height - 1, static_cast<int>(center.y + eye_radius));

        for (int y = min_y; y <= max_y; ++y) {
            for (int x = min_x; x <= max_x; ++x) {
                float dx = static_cast<float>(x) - center.x;
                float dy = static_cast<float>(y) - center.y;
                float r = std::sqrt(dx * dx + dy * dy);

                if (r < eye_radius && r > 1e-4f) {
                    // Radial distortion function: r_src = r * (1 - alpha * (1 - r/R)^2)
                    float ratio = r / eye_radius;
                    float factor = 1.0f - alpha * (1.0f - ratio) * (1.0f - ratio);
                    float src_x = center.x + dx * factor;
                    float src_y = center.y + dy * factor;

                    // Bilinear interpolation
                    int x0 = static_cast<int>(src_x);
                    int y0 = static_cast<int>(src_y);
                    int x1 = std::min(src.width - 1, x0 + 1);
                    int y1 = std::min(src.height - 1, y0 + 1);

                    float fx = src_x - static_cast<float>(x0);
                    float fy = src_y - static_cast<float>(y0);

                    const uint8_t* p00 = src.GetPixel(x0, y0);
                    const uint8_t* p10 = src.GetPixel(x1, y0);
                    const uint8_t* p01 = src.GetPixel(x0, y1);
                    const uint8_t* p11 = src.GetPixel(x1, y1);

                    if (p00 && p10 && p01 && p11) {
                        uint8_t* out_p = dst.GetPixel(x, y);
                        for (int c = 0; c < 3; ++c) {
                            float val = (1.0f - fx) * (1.0f - fy) * p00[c] +
                                        fx * (1.0f - fy) * p10[c] +
                                        (1.0f - fx) * fy * p01[c] +
                                        fx * fy * p11[c];
                            out_p[c] = static_cast<uint8_t>(std::clamp(val, 0.0f, 255.0f));
                        }
                    }
                }
            }
        }
    }
}

// EN: Apply jawline slimming vector deformation toward face center
// VN: Áp dụng trường vector gọt cằm thon gọn mặt hướng về tâm khuôn mặt
void BeautyEngine::ApplyFaceSlimming(const ImageBuffer& src, ImageBuffer& dst, const Face106Landmarks& landmarks) {
    if (m_params.face_slim_intensity <= 0.001f) {
        dst = src;
        return;
    }

    dst = src;
    const Point2F& center = landmarks.face_center;
    float max_influence_dist = landmarks.eye_distance * 1.5f;

    // Jawline landmarks from index 4 to 28 (left cheek to right cheek along lower chin)
    for (int idx = 4; idx <= 28; idx += 2) {
        const Point2F& p = landmarks.points[idx];
        float dir_x = center.x - p.x;
        float dir_y = center.y - p.y;
        float dist = std::sqrt(dir_x * dir_x + dir_y * dir_y);
        if (dist < 1e-4f) continue;

        dir_x /= dist;
        dir_y /= dist;

        float displacement = landmarks.eye_distance * 0.12f * m_params.face_slim_intensity;
        float radius = landmarks.eye_distance * 0.45f;

        int min_x = std::max(0, static_cast<int>(p.x - radius));
        int max_x = std::min(src.width - 1, static_cast<int>(p.x + radius));
        int min_y = std::max(0, static_cast<int>(p.y - radius));
        int max_y = std::min(src.height - 1, static_cast<int>(p.y + radius));

        for (int y = min_y; y <= max_y; ++y) {
            for (int x = min_x; x <= max_x; ++x) {
                float dx = static_cast<float>(x) - p.x;
                float dy = static_cast<float>(y) - p.y;
                float d = std::sqrt(dx * dx + dy * dy);

                if (d < radius) {
                    float weight = (1.0f - d / radius);
                    weight = weight * weight; // Quadratic falloff

                    float src_x = static_cast<float>(x) - dir_x * displacement * weight;
                    float src_y = static_cast<float>(y) - dir_y * displacement * weight;

                    int x0 = std::clamp(static_cast<int>(src_x), 0, src.width - 1);
                    int y0 = std::clamp(static_cast<int>(src_y), 0, src.height - 1);

                    const uint8_t* in_p = src.GetPixel(x0, y0);
                    uint8_t* out_p = dst.GetPixel(x, y);
                    if (in_p && out_p) {
                        out_p[0] = in_p[0];
                        out_p[1] = in_p[1];
                        out_p[2] = in_p[2];
                    }
                }
            }
        }
    }
}

// EN: Apply lipstick color blending with natural highlights
// VN: Hòa trộn màu son môi tự nhiên giữ lại vân môi và độ phản quang
void BeautyEngine::ApplyLipstick(ImageBuffer& img, const Face106Landmarks& landmarks) {
    if (m_params.lipstick_intensity <= 0.001f) return;

    // Outer lip contour: landmarks 84 to 95
    std::vector<Point2F> lip_poly;
    for (int i = 84; i <= 95 && i < 106; ++i) {
        lip_poly.push_back(landmarks.points[i]);
    }
    if (lip_poly.size() < 3) return;

    float r_lip = static_cast<float>((m_params.lipstick_color_rgb >> 16) & 0xFF);
    float g_lip = static_cast<float>((m_params.lipstick_color_rgb >> 8) & 0xFF);
    float b_lip = static_cast<float>(m_params.lipstick_color_rgb & 0xFF);

    float alpha = m_params.lipstick_intensity * 0.45f;

    for (int y = 0; y < img.height; ++y) {
        for (int x = 0; x < img.width; ++x) {
            if (IsInPolygon(static_cast<float>(x), static_cast<float>(y), lip_poly)) {
                uint8_t* p = img.GetPixel(x, y);
                float orig_r = static_cast<float>(p[0]);
                float orig_g = static_cast<float>(p[1]);
                float orig_b = static_cast<float>(p[2]);

                // Multiply-blend mode preserving natural lip specular highlight
                float lum = (0.299f * orig_r + 0.587f * orig_g + 0.114f * orig_b) / 255.0f;
                float blend_r = (orig_r * (1.0f - alpha)) + (r_lip * lum * alpha);
                float blend_g = (orig_g * (1.0f - alpha)) + (g_lip * lum * alpha);
                float blend_b = (orig_b * (1.0f - alpha)) + (b_lip * lum * alpha);

                p[0] = static_cast<uint8_t>(std::clamp(blend_r, 0.0f, 255.0f));
                p[1] = static_cast<uint8_t>(std::clamp(blend_g, 0.0f, 255.0f));
                p[2] = static_cast<uint8_t>(std::clamp(blend_b, 0.0f, 255.0f));
            }
        }
    }
}

// EN: Complete beauty retouch pipeline execution (Opcode 0x133e40, Opcode 0xcbc80)
// VN: Thực thi toàn bộ chu trình xử lý làm đẹp (Opcode 0x133e40, Opcode 0xcbc80)
bool BeautyEngine::ProcessFrame(const ImageBuffer& src, ImageBuffer& dst, const Face106Landmarks& landmarks) {
    if (src.data.empty() || src.width <= 0 || src.height <= 0) {
        return false;
    }

    // 1. Skin probability mask
    auto skin_mask = GenerateSkinMask(src);

    // 2. Bilateral smoothing
    ImageBuffer smooth_buf;
    ApplySkinSmoothing(src, smooth_buf, skin_mask);

    // 3. Whitening
    ApplySkinWhitening(smooth_buf, skin_mask);

    // 4. Teeth whitening
    ApplyTeethWhitening(smooth_buf, landmarks);

    // 5. Eye enlargement
    ImageBuffer eye_buf;
    ApplyEyeEnlargement(smooth_buf, eye_buf, landmarks);

    // 6. Face slimming
    ApplyFaceSlimming(eye_buf, dst, landmarks);

    // 7. Lipstick
    ApplyLipstick(dst, landmarks);

    return true;
}

} // namespace retouch_sdk
