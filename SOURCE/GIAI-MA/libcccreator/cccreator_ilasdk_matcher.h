// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libcccreator.so
// File: cccreator_ilasdk_matcher.h
// Description: ILA SDK intelligent asset matching and template slot alignment engine
// ===================================================================================

#pragma once

#include "cccreator_types.h"
#include <vector>
#include <string>

namespace vesdk {
namespace ccmodel {
namespace ilasdk {

/**
 * @brief Template Slot Requirements
 * Yêu cầu đặc tả cho từng ô video trong mẫu CapCut CutSame
 */
struct TemplateSlotRequirement {
    int32_t slot_index;             // Thứ tự ô trong template
    VETimeCode target_duration_us;  // Thời lượng mong muốn
    bool requires_face;             // Yêu cầu có mặt người
    float min_quality_score;        // Ngưỡng chất lượng tối thiểu
    std::vector<float> target_embedding; // Vector đặc trưng ngữ cảnh mẫu
};

/**
 * @brief ILASDK Intelligent Template Matcher
 * Bộ điều phối ghép mẫu thông minh trích xuất từ ILASDKJianyingJNI
 */
class ILAMatcher {
public:
    /**
     * @brief Computes cosine similarity between two feature embeddings
     * Tính tương đồng Cosine giữa hai vector đặc trưng AI
     */
    static float computeCosineSimilarity(const std::vector<float>& vec_a, const std::vector<float>& vec_b);

    /**
     * @brief Evaluates asset suitability based on face quality, orientation, and smiles
     * Đánh giá độ phù hợp của tài nguyên khuôn mặt (khớp JNI FaceQuality)
     */
    static float evaluateFaceSuitability(const FaceQuality& face);

    /**
     * @brief Matches user media assets to CapCut template slots
     * Tự động gán tài nguyên người dùng vào các slot mẫu CutSame tối ưu nhất
     */
    static std::vector<TemplateSlotMatch> matchAssetsToTemplateSlots(
        const std::vector<TemplateSlotRequirement>& slots,
        const std::vector<AssetInfo>& available_assets,
        const std::vector<FaceQuality>& face_qualities
    );
};

} // namespace ilasdk
} // namespace ccmodel
} // namespace vesdk
