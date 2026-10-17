// ======================================================================
// NextAI OpenCut — libbytedt Reconstructed BaseModel Architecture
// Lớp cơ sở trừu tượng cho Mô hình Ensemble (BaseModel)
//
// ABI Parity:
//   - n_feature_ located at offset 0x28 (ldrsw x9, [x0, #0x28])
//   - Input verification: sample_floats % n_feature_ == 0
//   - Model constraint assertions matching ByteDance runtime strings
// ======================================================================

#pragma once

#include "bytedt_tree.h"
#include <vector>
#include <string>
#include <stdexcept>
#include <sstream>

namespace bytedt {

/**
 * @brief Base ensemble model containing trees and configuration parameters.
 * Mô hình ensemble cơ sở chứa danh sách các cây quyết định và tham số cấu hình.
 */
class BaseModel {
protected:
    std::vector<Tree> trees_;        ///< Ensemble decision trees / Danh sách các cây quyết định
    int32_t n_feature_;             ///< Feature dimension at offset 0x28 / Số chiều đặc trưng
    int32_t num_group_;             ///< Number of classification groups / Số nhóm phân loại
    int32_t num_class_;             ///< Number of classes / Số lớp
    ModelType model_type_;          ///< Type of model / Kiểu mô hình
    TreeRelation tree_relation_;    ///< Ensemble relation / Mối quan hệ giữa các cây
    float base_score_;              ///< Baseline bias score / Điểm bias cơ sở

public:
    BaseModel()
        : n_feature_(0), num_group_(1), num_class_(1),
          model_type_(ModelType::UNKNOWN), tree_relation_(TreeRelation::UNKNOWN),
          base_score_(0.0f) {}

    virtual ~BaseModel() = default;

    // Getters and Setters
    void set_n_feature(int32_t n) { n_feature_ = n; }
    int32_t get_n_feature() const { return n_feature_; }

    void set_num_group(int32_t g) { num_group_ = g; }
    int32_t get_num_group() const { return num_group_; }

    void set_num_class(int32_t c) { num_class_ = c; }
    int32_t get_num_class() const { return num_class_; }

    void set_model_type(ModelType t) { model_type_ = t; }
    ModelType get_model_type() const { return model_type_; }

    void set_tree_relation(TreeRelation r) { tree_relation_ = r; }
    TreeRelation get_tree_relation() const { return tree_relation_; }

    void set_base_score(float s) { base_score_ = s; }
    float get_base_score() const { return base_score_; }

    void add_tree(const Tree& tree) { trees_.push_back(tree); }
    void add_tree(Tree&& tree) { trees_.push_back(std::move(tree)); }
    const std::vector<Tree>& get_trees() const { return trees_; }
    size_t get_tree_count() const { return trees_.size(); }

    /**
     * @brief Computes raw additive or voting output per tree.
     * Tính toán đầu ra thô (raw output) từ từng cây trong ensemble.
     * Output shape: [num_samples, num_trees]
     */
    virtual std::vector<float> predict_raw(const float* features, size_t num_samples) const {
        if (!features || num_samples == 0 || trees_.empty()) {
            return {};
        }

        std::vector<float> raw_out;
        raw_out.reserve(num_samples * trees_.size());

        for (size_t s = 0; s < num_samples; ++s) {
            const float* sample_feat = features + (s * n_feature_);
            for (const auto& tree : trees_) {
                float val = tree.predict(sample_feat, static_cast<size_t>(n_feature_));
                raw_out.push_back(val);
            }
        }
        return raw_out;
    }

    /**
     * @brief Predicts leaf index traversed in each tree.
     * Dự đoán chỉ số nút lá được kích hoạt trong mỗi cây quyết định.
     * Output shape: [num_samples, num_trees]
     */
    virtual std::vector<int32_t> predict_leaf(const float* features, size_t num_samples) const {
        if (!features || num_samples == 0 || trees_.empty()) {
            return {};
        }

        std::vector<int32_t> leaf_indices;
        leaf_indices.reserve(num_samples * trees_.size());

        for (size_t s = 0; s < num_samples; ++s) {
            const float* sample_feat = features + (s * n_feature_);
            for (const auto& tree : trees_) {
                int32_t leaf_idx = tree.predict_leaf(sample_feat, static_cast<size_t>(n_feature_));
                leaf_indices.push_back(leaf_idx);
            }
        }
        return leaf_indices;
    }

    /**
     * @brief High-level inference prediction method (overridden by sub-models).
     * Phương thức dự đoán hoàn chỉnh (được cài đè bởi từng lớp mô hình cụ thể).
     */
    virtual std::vector<float> predict(const float* features, size_t num_samples) const = 0;

    /**
     * @brief Validates model configuration invariants.
     * Xác thực các bất biến cấu hình mô hình (khớp chuỗi kiểm tra nội bộ).
     */
    virtual void validate() const {
        if (n_feature_ <= 0) {
            throw std::runtime_error("n_feature is required!");
        }
    }

    /**
     * @brief Formats human-readable model summary.
     * Định dạng chuỗi tóm tắt thông tin mô hình.
     */
    virtual std::string dump_summary() const {
        std::ostringstream oss;
        oss << "Model:\n"
            << "   Tree count: " << trees_.size() << "\n"
            << "   Feature count: " << n_feature_ << "\n"
            << "   Group count: " << num_group_ << "\n"
            << "   Class count: " << num_class_ << "\n";
        return oss.str();
    }
};

} // namespace bytedt
