// ======================================================================
// NextAI OpenCut — libbytedt Reconstructed Training Engine Implementation
// Triển khai chi tiết On-Device Training Engine cho ByteDT
// ======================================================================

#include "bytedt_train.h"
#include "bytedt_protobuf.h"
#include <sstream>
#include <algorithm>
#include <cmath>

namespace bytedt {

ByteDTTrain::ByteDTTrain() : model_(nullptr) {}

ByteDTTrain::~ByteDTTrain() = default;

std::shared_ptr<ByteDTTrain> ByteDTTrain::create_engine() {
    return std::make_shared<ByteDTTrain>();
}

bool ByteDTTrain::load_model_from_path(const char* filepath, ByteDTErrorCode& err, RunInfo* info) {
    if (!filepath) {
        err = ByteDTErrorCode::INVALID_INPUT;
        return false;
    }
    model_ = protobuf::ModelParser::parse_from_path(filepath);
    if (!model_) {
        err = ByteDTErrorCode::MODEL_LOAD_ERROR;
        return false;
    }
    err = ByteDTErrorCode::OK;
    return true;
}

bool ByteDTTrain::load_model_from_buffer(void* buffer, size_t size, ByteDTErrorCode& err, RunInfo* info) {
    if (!buffer || size == 0) {
        err = ByteDTErrorCode::INVALID_INPUT;
        return false;
    }
    model_ = protobuf::ModelParser::parse_from_buffer(buffer, size);
    if (!model_) {
        err = ByteDTErrorCode::MODEL_LOAD_ERROR;
        return false;
    }
    err = ByteDTErrorCode::OK;
    return true;
}

std::string ByteDTTrain::get_pb_model() {
    // Opcode 0x22834: serializes model into protobuf binary string
    if (!model_) {
        return "";
    }
    std::vector<uint8_t> buf = protobuf::ModelParser::serialize_to_buffer(*model_);
    return std::string(reinterpret_cast<const char*>(buf.data()), buf.size());
}

std::pair<int32_t, float> ByteDTTrain::split_numerical_feature(
    const float* features,
    const float* gradients,
    const float* hessians,
    size_t num_samples,
    int32_t feature_index,
    float min_gain) {

    if (!features || !gradients || !hessians || num_samples == 0) {
        return {-1, 0.0f};
    }

    // Sort samples by feature value
    // Sắp xếp các mẫu theo giá trị đặc trưng để quét ngưỡng cắt tối ưu
    struct SampleEntry {
        float val;
        float grad;
        float hess;
    };

    std::vector<SampleEntry> entries;
    entries.reserve(num_samples);

    float sum_grad_total = 0.0f;
    float sum_hess_total = 0.0f;

    for (size_t i = 0; i < num_samples; ++i) {
        float v = features[i];
        if (!std::isnan(v)) {
            entries.push_back({v, gradients[i], hessians[i]});
            sum_grad_total += gradients[i];
            sum_hess_total += hessians[i];
        }
    }

    if (entries.size() < 2) {
        return {-1, 0.0f};
    }

    std::sort(entries.begin(), entries.end(), [](const SampleEntry& a, const SampleEntry& b) {
        return a.val < b.val;
    });

    const float reg_lambda = 1.0f;
    float best_gain = min_gain;
    float best_threshold = entries[0].val;
    int32_t best_feat = -1;

    float sum_grad_l = 0.0f;
    float sum_hess_l = 0.0f;

    float root_score = (sum_grad_total * sum_grad_total) / (sum_hess_total + reg_lambda);

    for (size_t i = 0; i < entries.size() - 1; ++i) {
        sum_grad_l += entries[i].grad;
        sum_hess_l += entries[i].hess;

        float sum_grad_r = sum_grad_total - sum_grad_l;
        float sum_hess_r = sum_hess_total - sum_hess_l;

        if (sum_hess_l <= 0.0f || sum_hess_r <= 0.0f) continue;

        // Skip identical consecutive values
        if (std::abs(entries[i].val - entries[i + 1].val) < 1e-6f) continue;

        // XGBoost / GBDT Split Gain formula:
        // Gain = 0.5 * [ G_L^2 / (H_L + \lambda) + G_R^2 / (H_R + \lambda) - (G_L+G_R)^2 / (H_L+H_R+\lambda) ]
        float score_l = (sum_grad_l * sum_grad_l) / (sum_hess_l + reg_lambda);
        float score_r = (sum_grad_r * sum_grad_r) / (sum_hess_r + reg_lambda);
        float gain = 0.5f * (score_l + score_r - root_score);

        if (gain > best_gain) {
            best_gain = gain;
            best_threshold = 0.5f * (entries[i].val + entries[i + 1].val);
            best_feat = feature_index;
        }
    }

    return {best_feat, best_threshold};
}

bool ByteDTTrain::train(Input features,
                        const std::string& train_config_json,
                        const std::string& target_labels,
                        ByteDTErrorCode& err,
                        RunInfo* info) {
    if (!features.data || features.size == 0) {
        err = ByteDTErrorCode::INVALID_INPUT;
        return false;
    }

    // Parse simple parameters from train_config_json or use defaults
    // Thiết lập cấu hình huấn luyện
    int32_t n_feat = 0;
    int32_t n_iter = 10;
    int32_t max_depth = 4;
    float lr = 0.1f;

    // Search for n_feature in string
    size_t feat_pos = train_config_json.find("n_feature");
    if (feat_pos != std::string::npos) {
        size_t colon = train_config_json.find(':', feat_pos);
        if (colon != std::string::npos) {
            n_feat = std::atoi(train_config_json.c_str() + colon + 1);
        }
    }

    if (n_feat <= 0) {
        // Fallback default: calculate from total bytes if provided or throw required error
        n_feat = static_cast<int32_t>(features.size / (sizeof(float) * 10)); // estimate
        if (n_feat <= 0) n_feat = 4;
    }

    size_t total_floats = features.size / sizeof(float);
    if (total_floats % static_cast<size_t>(n_feat) != 0) {
        err = ByteDTErrorCode::DIMENSION_MISMATCH;
        return false;
    }
    size_t num_samples = total_floats / static_cast<size_t>(n_feat);

    // Parse target labels (CSV of floats)
    std::vector<float> targets;
    targets.reserve(num_samples);
    std::istringstream tss(target_labels);
    std::string token;
    while (std::getline(tss, token, ',')) {
        if (!token.empty()) {
            targets.push_back(std::atof(token.c_str()));
        }
    }
    while (targets.size() < num_samples) {
        targets.push_back(0.0f);
    }

    auto start_time = std::chrono::high_resolution_clock::now();

    // Create GBDT Regressor model
    auto reg_model = std::make_shared<BoostingRegressor>();
    reg_model->set_n_feature(n_feat);
    reg_model->set_num_group(1);
    reg_model->set_num_class(1);

    // Initial base score = mean of targets
    float sum_y = 0.0f;
    for (float y : targets) sum_y += y;
    float base_score = sum_y / static_cast<float>(num_samples);
    reg_model->set_base_score(base_score);

    std::vector<float> current_preds(num_samples, base_score);
    std::vector<float> gradients(num_samples);
    std::vector<float> hessians(num_samples, 1.0f);

    // Iterative Boosting Tree Construction Loop
    // Vòng lặp xây dựng cây tăng cường GBDT
    for (int iter = 0; iter < n_iter; ++iter) {
        // Compute negative gradients: g_i = current_pred_i - target_i (squared error loss)
        for (size_t i = 0; i < num_samples; ++i) {
            gradients[i] = current_preds[i] - targets[i];
        }

        // Build single regression tree to fit negative gradients
        Tree tree(iter);
        int32_t best_feat = -1;
        float best_thresh = 0.0f;
        float best_gain = -1.0f;

        // Find best split across all features
        for (int32_t f = 0; f < n_feat; ++f) {
            std::vector<float> feat_col(num_samples);
            for (size_t s = 0; s < num_samples; ++s) {
                feat_col[s] = features.data[s * n_feat + f];
            }
            auto split = split_numerical_feature(feat_col.data(), gradients.data(),
                                                 hessians.data(), num_samples, f, 0.0f);
            if (split.first >= 0) {
                best_feat = split.first;
                best_thresh = split.second;
            }
        }

        if (best_feat >= 0) {
            // Split into left and right
            float sum_gl = 0.0f, sum_hl = 0.0f;
            float sum_gr = 0.0f, sum_hr = 0.0f;

            for (size_t s = 0; s < num_samples; ++s) {
                float v = features.data[s * n_feat + best_feat];
                if (v <= best_thresh) {
                    sum_gl += gradients[s];
                    sum_hl += hessians[s];
                } else {
                    sum_gr += gradients[s];
                    sum_hr += hessians[s];
                }
            }

            float w_l = (sum_hl > 0.0f) ? (-lr * sum_gl / (sum_hl + 1.0f)) : 0.0f;
            float w_r = (sum_hr > 0.0f) ? (-lr * sum_gr / (sum_hr + 1.0f)) : 0.0f;

            auto root = std::make_shared<NumericalNode>(0, best_feat, best_thresh, CompareOp::OP_LESS_EQUAL, true);
            auto leaf_l = std::make_shared<LeafNode>(1, w_l, 0);
            auto leaf_r = std::make_shared<LeafNode>(2, w_r, 1);
            root->set_children(leaf_l, leaf_r);

            tree.set_root(root);
            tree.set_num_leaves(2);
            tree.set_max_depth(1);

            // Update predictions
            for (size_t s = 0; s < num_samples; ++s) {
                float v = features.data[s * n_feat + best_feat];
                current_preds[s] += (v <= best_thresh) ? w_l : w_r;
            }
        } else {
            // Constant leaf fallback
            float sum_g = 0.0f, sum_h = 0.0f;
            for (size_t s = 0; s < num_samples; ++s) {
                sum_g += gradients[s];
                sum_h += hessians[s];
            }
            float w = (sum_h > 0.0f) ? (-lr * sum_g / (sum_h + 1.0f)) : 0.0f;
            auto leaf = std::make_shared<LeafNode>(0, w, 0);
            tree.set_root(leaf);
            tree.set_num_leaves(1);
            tree.set_max_depth(0);

            for (size_t s = 0; s < num_samples; ++s) {
                current_preds[s] += w;
            }
        }

        reg_model->add_tree(tree);
    }

    model_ = reg_model;

    if (info) {
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float, std::milli> elapsed = end_time - start_time;
        info->inference_time_ms = elapsed.count();
        info->trees_evaluated = static_cast<int32_t>(model_->get_tree_count());
    }

    err = ByteDTErrorCode::OK;
    return true;
}

} // namespace bytedt
