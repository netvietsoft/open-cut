// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libcccreator.so
// File: cccreator_ilasdk_matcher.cpp
// Description: Full implementation of ILASDK template matching engine
// ===================================================================================

#include "cccreator_ilasdk_matcher.h"
#include <cmath>
#include <algorithm>
#include <set>

namespace vesdk {
namespace ccmodel {
namespace ilasdk {

float ILAMatcher::computeCosineSimilarity(const std::vector<float>& vec_a, const std::vector<float>& vec_b) {
    if (vec_a.empty() || vec_b.empty() || vec_a.size() != vec_b.size()) {
        return 0.0f;
    }

    double dot_prod = 0.0;
    double norm_a = 0.0;
    double norm_b = 0.0;

    for (size_t i = 0; i < vec_a.size(); ++i) {
        dot_prod += static_cast<double>(vec_a[i]) * static_cast<double>(vec_b[i]);
        norm_a += static_cast<double>(vec_a[i]) * static_cast<double>(vec_a[i]);
        norm_b += static_cast<double>(vec_b[i]) * static_cast<double>(vec_b[i]);
    }

    double denominator = std::sqrt(norm_a) * std::sqrt(norm_b);
    if (denominator < 1e-7) {
        return 0.0f;
    }

    return static_cast<float>(dot_prod / denominator);
}

float ILAMatcher::evaluateFaceSuitability(const FaceQuality& face) {
    // If eyes are occluded (glasses/hair/hands), severe penalty
    float occlusion_factor = face.eye_not_occlude ? 1.0f : 0.35f;

    // Head orientation penalty: faces looking straight at camera (yaw/pitch near 0) are preferred for templates
    float angle_penalty = 1.0f - (std::abs(face.yaw) * 0.005f + std::abs(face.pitch) * 0.005f + std::abs(face.roll) * 0.003f);
    if (angle_penalty < 0.2f) angle_penalty = 0.2f;

    // Smile bonus (0.0 to 1.0)
    float smile_bonus = 1.0f + (face.smile_degree * 0.25f);

    float total_score = face.quality_score * occlusion_factor * angle_penalty * smile_bonus;
    if (total_score < 0.0f) total_score = 0.0f;
    if (total_score > 1.0f) total_score = 1.0f;

    return total_score;
}

std::vector<TemplateSlotMatch> ILAMatcher::matchAssetsToTemplateSlots(
    const std::vector<TemplateSlotRequirement>& slots,
    const std::vector<AssetInfo>& available_assets,
    const std::vector<FaceQuality>& face_qualities
) {
    std::vector<TemplateSlotMatch> results;
    if (slots.empty() || available_assets.empty()) {
        return results;
    }

    // Build map of face qualities by asset_id
    std::map<std::string, FaceQuality> face_map;
    for (const auto& fq : face_qualities) {
        face_map[fq.asset_id] = fq;
    }

    std::set<std::string> used_assets;

    for (const auto& slot : slots) {
        TemplateSlotMatch best_match;
        best_match.slot_index = slot.slot_index;
        best_match.match_confidence = -1.0f;

        for (const auto& asset : available_assets) {
            // Prioritize unused assets if possible
            float score = 0.5f;

            // 1. Duration compatibility
            if (asset.duration_us >= slot.target_duration_us) {
                score += 0.2f;
            } else if (asset.duration_us > 0) {
                score -= 0.2f;
            }

            // 2. Face requirement check
            auto it_face = face_map.find(asset.asset_id);
            if (slot.requires_face) {
                if (it_face != face_map.end()) {
                    float face_suit = evaluateFaceSuitability(it_face->second);
                    if (face_suit >= slot.min_quality_score) {
                        score += 0.3f * face_suit;
                    } else {
                        score -= 0.3f;
                    }
                } else {
                    score -= 0.4f; // Missing required face
                }
            }

            // 3. Embedding semantic similarity
            if (!slot.target_embedding.empty() && !asset.feature_embeddings.empty()) {
                float sim = computeCosineSimilarity(slot.target_embedding, asset.feature_embeddings);
                score += 0.3f * sim;
            }

            // Penalty if asset is already reused
            if (used_assets.count(asset.asset_id) > 0) {
                score *= 0.6f;
            }

            if (score > best_match.match_confidence) {
                best_match.match_confidence = score;
                best_match.matched_asset_id = asset.asset_id;
                best_match.suggested_trim_in = 0;
                best_match.suggested_trim_out = (asset.duration_us >= slot.target_duration_us) 
                                                ? slot.target_duration_us 
                                                : asset.duration_us;
            }
        }

        if (best_match.match_confidence > 0.0f) {
            used_assets.insert(best_match.matched_asset_id);
        } else if (!available_assets.empty()) {
            // Fallback: assign first asset
            best_match.matched_asset_id = available_assets[0].asset_id;
            best_match.suggested_trim_in = 0;
            best_match.suggested_trim_out = slot.target_duration_us;
            best_match.match_confidence = 0.1f;
        }

        results.push_back(best_match);
    }

    return results;
}

} // namespace ilasdk
} // namespace ccmodel
} // namespace vesdk
