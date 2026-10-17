// ======================================================================
// NextAI OpenCut — libbytedt Reconstructed Specific Model Implementations
// Các triển khai mô hình học máy cụ thể: Boosting, Voting, Multi-Label
//
// Equations & Algorithms:
//   - Sigmoid: \sigma(z) = 1 / (1 + exp(-z))
//   - Softmax: p_k = exp(z_k - max_j z_j) / \sum_j exp(z_j - max_j z_j)
//   - GBDT Additive: \hat{y} = bias + \sum_m f_m(x)
//   - RF Bagging: \hat{y} = (1 / M) \sum_m f_m(x)
// ======================================================================

#pragma once

#include "bytedt_model.h"
#include <cmath>
#include <algorithm>
#include <numeric>

namespace bytedt {

/**
 * @brief GBDT Boosting Classifier (Binary and Multi-Class).
 * Bộ phân loại tăng cường độ dốc GBDT (Nhị phân và Đa lớp).
 */
class BoostingClassifier : public BaseModel {
public:
    BoostingClassifier() {
        model_type_ = ModelType::BOOSTING_CLASSIFICATION;
        tree_relation_ = TreeRelation::BOOSTING;
    }

    void validate() const override {
        BaseModel::validate();
        if (num_group_ <= 0) {
            throw std::runtime_error("num_group must be positive in boosting classification model.");
        }
        if (!trees_.empty() && (trees_.size() % static_cast<size_t>(num_group_) != 0)) {
            throw std::runtime_error("Trees count must be integer multiple of `num_group` in boosting classification model.");
        }
    }

    /**
     * @brief Computes classification probabilities.
     * Tính toán phân phối xác suất phân loại.
     */
    std::vector<float> predict(const float* features, size_t num_samples) const override {
        validate();
        if (!features || num_samples == 0 || trees_.empty()) {
            return {};
        }

        std::vector<float> results;
        if (num_group_ == 1) {
            // Binary classification: Sigmoid activation
            // Phân loại nhị phân: Hàm kích hoạt Logistic Sigmoid
            results.reserve(num_samples);
            for (size_t s = 0; s < num_samples; ++s) {
                const float* sample_feat = features + (s * n_feature_);
                float raw_sum = base_score_;
                for (const auto& tree : trees_) {
                    raw_sum += tree.predict(sample_feat, static_cast<size_t>(n_feature_));
                }
                // Sigmoid \sigma(z) = 1 / (1 + exp(-z))
                float prob = 1.0f / (1.0f + std::exp(-raw_sum));
                results.push_back(prob);
            }
        } else {
            // Multi-class classification: Softmax activation across groups
            // Phân loại đa lớp: Hàm kích hoạt Softmax ổn định số học
            size_t num_groups = static_cast<size_t>(num_group_);
            results.reserve(num_samples * num_groups);

            for (size_t s = 0; s < num_samples; ++s) {
                const float* sample_feat = features + (s * n_feature_);
                std::vector<float> group_logits(num_groups, base_score_);

                for (size_t t = 0; t < trees_.size(); ++t) {
                    size_t group_idx = t % num_groups;
                    group_logits[group_idx] += trees_[t].predict(sample_feat, static_cast<size_t>(n_feature_));
                }

                // Numerically stable Softmax
                float max_logit = *std::max_element(group_logits.begin(), group_logits.end());
                float sum_exp = 0.0f;
                std::vector<float> exp_logits(num_groups);
                for (size_t g = 0; g < num_groups; ++g) {
                    exp_logits[g] = std::exp(group_logits[g] - max_logit);
                    sum_exp += exp_logits[g];
                }

                float inv_sum = (sum_exp > 0.0f) ? (1.0f / sum_exp) : 0.0f;
                for (size_t g = 0; g < num_groups; ++g) {
                    results.push_back(exp_logits[g] * inv_sum);
                }
            }
        }
        return results;
    }
};

/**
 * @brief GBDT Boosting Regressor.
 * Bộ hồi quy tăng cường độ dốc GBDT (tích lũy cộng dồn).
 */
class BoostingRegressor : public BaseModel {
public:
    BoostingRegressor() {
        model_type_ = ModelType::BOOSTING_REGRESSION;
        tree_relation_ = TreeRelation::BOOSTING;
    }

    std::vector<float> predict(const float* features, size_t num_samples) const override {
        validate();
        if (!features || num_samples == 0 || trees_.empty()) {
            return {};
        }

        std::vector<float> results;
        results.reserve(num_samples);

        for (size_t s = 0; s < num_samples; ++s) {
            const float* sample_feat = features + (s * n_feature_);
            float sum = base_score_;
            for (const auto& tree : trees_) {
                sum += tree.predict(sample_feat, static_cast<size_t>(n_feature_));
            }
            results.push_back(sum);
        }
        return results;
    }
};

/**
 * @brief GBDT Boosting Multi-Label Classifier.
 * Bộ phân loại đa nhãn GBDT với kích hoạt Sigmoid độc lập từng nhãn.
 */
class BoostingMultiLabelClassifier : public BaseModel {
public:
    BoostingMultiLabelClassifier() {
        model_type_ = ModelType::BOOSTING_MULTI_LABEL_CLASSIFICATION;
        tree_relation_ = TreeRelation::BOOSTING;
    }

    void validate() const override {
        BaseModel::validate();
        if (num_class_ <= 1) {
            throw std::runtime_error("num_class must be greater than 1 in multi-label classification model.");
        }
        if (!trees_.empty() && (trees_.size() % static_cast<size_t>(num_class_) != 0)) {
            throw std::runtime_error("Trees count must be integer multiple of `num_class` in boosting multi-label classification model.");
        }
    }

    std::vector<float> predict(const float* features, size_t num_samples) const override {
        validate();
        if (!features || num_samples == 0 || trees_.empty()) {
            return {};
        }

        size_t n_classes = static_cast<size_t>(num_class_);
        std::vector<float> results;
        results.reserve(num_samples * n_classes);

        for (size_t s = 0; s < num_samples; ++s) {
            const float* sample_feat = features + (s * n_feature_);
            std::vector<float> class_logits(n_classes, base_score_);

            for (size_t t = 0; t < trees_.size(); ++t) {
                size_t c_idx = t % n_classes;
                class_logits[c_idx] += trees_[t].predict(sample_feat, static_cast<size_t>(n_feature_));
            }

            for (size_t c = 0; c < n_classes; ++c) {
                float prob = 1.0f / (1.0f + std::exp(-class_logits[c]));
                results.push_back(prob);
            }
        }
        return results;
    }
};

/**
 * @brief Random Forest / Bagging Voting Classifier.
 * Bộ phân loại biểu quyết đa số (Random Forest).
 */
class VotingClassifier : public BaseModel {
public:
    VotingClassifier() {
        model_type_ = ModelType::VOTING_CLASSIFICATION;
        tree_relation_ = TreeRelation::VOTING;
    }

    std::vector<float> predict(const float* features, size_t num_samples) const override {
        validate();
        if (!features || num_samples == 0 || trees_.empty()) {
            return {};
        }

        float inv_trees = 1.0f / static_cast<float>(trees_.size());
        std::vector<float> results;
        results.reserve(num_samples);

        for (size_t s = 0; s < num_samples; ++s) {
            const float* sample_feat = features + (s * n_feature_);
            float vote_sum = 0.0f;
            for (const auto& tree : trees_) {
                vote_sum += tree.predict(sample_feat, static_cast<size_t>(n_feature_));
            }
            results.push_back(vote_sum * inv_trees);
        }
        return results;
    }
};

/**
 * @brief Random Forest Voting Regressor.
 * Bộ hồi quy lấy giá trị trung bình quần thể (Random Forest Regressor).
 */
class VotingRegressor : public BaseModel {
public:
    VotingRegressor() {
        model_type_ = ModelType::VOTING_REGRESSION;
        tree_relation_ = TreeRelation::VOTING;
    }

    std::vector<float> predict(const float* features, size_t num_samples) const override {
        validate();
        if (!features || num_samples == 0 || trees_.empty()) {
            return {};
        }

        float inv_trees = 1.0f / static_cast<float>(trees_.size());
        std::vector<float> results;
        results.reserve(num_samples);

        for (size_t s = 0; s < num_samples; ++s) {
            const float* sample_feat = features + (s * n_feature_);
            float sum = 0.0f;
            for (const auto& tree : trees_) {
                sum += tree.predict(sample_feat, static_cast<size_t>(n_feature_));
            }
            results.push_back(sum * inv_trees);
        }
        return results;
    }
};

/**
 * @brief Random Forest Voting Multi-Label Classifier.
 * Bộ phân loại đa nhãn biểu quyết (Random Forest Multi-Label).
 */
class VotingMultiLabelClassifier : public BaseModel {
public:
    VotingMultiLabelClassifier() {
        model_type_ = ModelType::VOTING_MULTI_LABEL_CLASSIFICATION;
        tree_relation_ = TreeRelation::VOTING;
    }

    void validate() const override {
        BaseModel::validate();
        if (num_class_ <= 1) {
            throw std::runtime_error("num_class must be greater than 1 in multi-label classification model.");
        }
    }

    std::vector<float> predict(const float* features, size_t num_samples) const override {
        validate();
        if (!features || num_samples == 0 || trees_.empty()) {
            return {};
        }

        size_t n_classes = static_cast<size_t>(num_class_);
        size_t trees_per_class = trees_.size() / n_classes;
        if (trees_per_class == 0) trees_per_class = 1;
        float inv_scale = 1.0f / static_cast<float>(trees_per_class);

        std::vector<float> results;
        results.reserve(num_samples * n_classes);

        for (size_t s = 0; s < num_samples; ++s) {
            const float* sample_feat = features + (s * n_feature_);
            std::vector<float> class_votes(n_classes, 0.0f);

            for (size_t t = 0; t < trees_.size(); ++t) {
                size_t c_idx = t % n_classes;
                class_votes[c_idx] += trees_[t].predict(sample_feat, static_cast<size_t>(n_feature_));
            }

            for (size_t c = 0; c < n_classes; ++c) {
                results.push_back(class_votes[c] * inv_scale);
            }
        }
        return results;
    }
};

} // namespace bytedt
