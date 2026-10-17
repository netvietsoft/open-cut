// ======================================================================
// NextAI OpenCut — libbytedt Reconstructed Training Engine Interface
// Giao diện Engine huấn luyện cây quyết định (ByteDTTrain)
//
// Demangled Symbols Parity:
//   - _ZN6bytedt11ByteDTTrain13create_engineEv
//   - _ZN6bytedt11ByteDTTrain20load_model_from_pathEPKcRNS_15ByteDTErrorCodeEPNS_7RunInfoE
//   - _ZN6bytedt11ByteDTTrain22load_model_from_bufferEPvmRNS_15ByteDTErrorCodeEPNS_7RunInfoE
//   - _ZN6bytedt11ByteDTTrain12get_pb_modelEv
//   - _ZN6bytedt11ByteDTTrain5trainENS_5InputERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEESA_RNS_15ByteDTErrorCodeEPNS_7RunInfoE
// ======================================================================

#pragma once

#include "bytedt_interpreter.h"
#include <string>
#include <memory>
#include <vector>
#include <utility>

namespace bytedt {

/**
 * @brief Training hyperparameter configuration.
 * Cấu hình siêu tham số huấn luyện mô hình cây quyết định.
 */
struct TrainConfig {
    int32_t n_feature = 0;           ///< Number of features / Số đặc trưng (n_feature is required!)
    int32_t n_iteration = 10;        ///< Number of trees / Số vòng lặp cây (n_iteration is required!)
    int32_t max_depth = 6;           ///< Maximum tree depth / Độ sâu tối đa của cây
    float learning_rate = 0.1f;      ///< Shrinkage factor / Tốc độ học (eta)
    float min_split_gain = 0.0f;     ///< Minimum loss reduction / Lượng giảm mất mát tối thiểu
    int32_t min_data_in_leaf = 5;    ///< Minimum samples per leaf / Số mẫu tối thiểu trên mỗi lá
    std::string objective = "regression"; ///< Loss objective / Hàm mục tiêu tối ưu
    std::string tree_method = "exact";    ///< Splitting algorithm / Giải thuật tìm điểm phân nhánh
};

/**
 * @brief ByteDTTrain Training Engine.
 * Bộ máy huấn luyện cây quyết định trực tiếp trên thiết bị (On-Device GBDT Training).
 */
class ByteDTTrain {
private:
    std::shared_ptr<BaseModel> model_;
    TrainConfig config_;

public:
    ByteDTTrain();
    virtual ~ByteDTTrain();

    /**
     * @brief Factory creating training engine instance.
     * Khởi tạo thực thể bộ máy huấn luyện (khớp opcode 0x21ca8).
     */
    static std::shared_ptr<ByteDTTrain> create_engine();

    /**
     * @brief Loads model checkpoint for fine-tuning or resumed training.
     * Nạp mô hình có sẵn từ file để tiếp tục huấn luyện (Fine-tuning).
     */
    bool load_model_from_path(const char* filepath, ByteDTErrorCode& err, RunInfo* info = nullptr);

    /**
     * @brief Loads model checkpoint from memory buffer.
     * Nạp mô hình từ vùng đệm bộ nhớ.
     */
    bool load_model_from_buffer(void* buffer, size_t size, ByteDTErrorCode& err, RunInfo* info = nullptr);

    /**
     * @brief Trains model on provided dataset features and target labels.
     * Huấn luyện mô hình từ dữ liệu đặc trưng và nhãn mục tiêu.
     *
     * @param features Input dataset features
     * @param train_config_json Serialized JSON or config string
     * @param target_labels Target labels/values serialized string or CSV
     * @param err Output error code
     * @param info Performance diagnostic information
     */
    bool train(Input features,
               const std::string& train_config_json,
               const std::string& target_labels,
               ByteDTErrorCode& err,
               RunInfo* info = nullptr);

    /**
     * @brief Exports trained model as serialized Protobuf binary string.
     * Xuất mô hình đã huấn luyện thành chuỗi nhị phân định dạng Protobuf (khớp opcode 0x22834).
     */
    std::string get_pb_model();

    /**
     * @brief Finds optimal numerical split point maximizing information gain / gradient reduction.
     * Tìm điểm cắt tối ưu cho đặc trưng số học (khớp BaseModel.cpp::split_numerical_feature).
     *
     * @return pair of (best_feature_index, best_threshold)
     */
    static std::pair<int32_t, float> split_numerical_feature(
        const float* features,
        const float* gradients,
        const float* hessians,
        size_t num_samples,
        int32_t feature_index,
        float min_gain);

    std::shared_ptr<BaseModel> get_model() const { return model_; }
};

} // namespace bytedt
