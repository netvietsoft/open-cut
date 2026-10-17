// ======================================================================
// NextAI OpenCut — libbytedt Reconstructed ByteDT Engine Implementation
// Triển khai chi tiết ByteDT Inference Engine
// ======================================================================

#include "bytedt_interpreter.h"
#include "bytedt_protobuf.h"

namespace bytedt {

ByteDT::ByteDT() : model_(nullptr) {}

ByteDT::~ByteDT() = default;

std::shared_ptr<ByteDT> ByteDT::create_engine() {
    // Matches opcode 0x13b30: operator new(0x30 = 48 bytes) and vtable setup
    // Khởi tạo thực thể ByteDT tương ứng mã máy AArch64 tại 0x13b30
    return std::make_shared<ByteDT>();
}

bool ByteDT::load_model_from_path(const char* filepath, ByteDTErrorCode& err, RunInfo* info) {
    if (!filepath) {
        err = ByteDTErrorCode::INVALID_INPUT;
        return false;
    }

    auto start_time = std::chrono::high_resolution_clock::now();

    try {
        model_ = protobuf::ModelParser::parse_from_path(filepath);
        if (!model_) {
            err = ByteDTErrorCode::MODEL_LOAD_ERROR;
            return false;
        }

        if (info) {
            auto end_time = std::chrono::high_resolution_clock::now();
            std::chrono::duration<float, std::milli> elapsed = end_time - start_time;
            info->inference_time_ms = elapsed.count();
            info->trees_evaluated = static_cast<int32_t>(model_->get_tree_count());
        }

        err = ByteDTErrorCode::OK;
        return true;
    } catch (const std::exception& e) {
        Warning::warn(SourceLocation(__FILE__, __LINE__), e.what());
        err = ByteDTErrorCode::INVALID_MODEL;
        return false;
    }
}

bool ByteDT::load_model_from_buffer(void* buffer, size_t size, ByteDTErrorCode& err, RunInfo* info) {
    if (!buffer || size == 0) {
        err = ByteDTErrorCode::INVALID_INPUT;
        return false;
    }

    auto start_time = std::chrono::high_resolution_clock::now();

    try {
        model_ = protobuf::ModelParser::parse_from_buffer(buffer, size);
        if (!model_) {
            err = ByteDTErrorCode::MODEL_LOAD_ERROR;
            return false;
        }

        if (info) {
            auto end_time = std::chrono::high_resolution_clock::now();
            std::chrono::duration<float, std::milli> elapsed = end_time - start_time;
            info->inference_time_ms = elapsed.count();
            info->trees_evaluated = static_cast<int32_t>(model_->get_tree_count());
        }

        err = ByteDTErrorCode::OK;
        return true;
    } catch (const std::exception& e) {
        Warning::warn(SourceLocation(__FILE__, __LINE__), e.what());
        err = ByteDTErrorCode::INVALID_MODEL;
        return false;
    }
}

std::vector<float> ByteDT::predict(Input input, ByteDTErrorCode& err, RunInfo* info) {
    // Opcode 0x00caf4 - 0x00cbf4 validation:
    // If input.data is null or model is not loaded:
    if (!input.data) {
        err = ByteDTErrorCode::INVALID_INPUT; // opcode 0xcbb4: mov w8, #3; strb w8, [x21]
        return {};
    }

    if (!model_) {
        err = ByteDTErrorCode::INVALID_MODEL;
        return {};
    }

    // Check data_type == 1 (FP32) at opcode 0x00cbf4 (cmp w9, #1)
    if (input.data_type != 1) {
        err = ByteDTErrorCode::DIMENSION_MISMATCH; // opcode 0xcc28: mov w8, #5; strb w8, [x20]
        return {};
    }

    // Number of float elements = input.size / 4 (lsr x8, x8, #2 at opcode 0x00cc10)
    size_t total_floats = input.size / sizeof(float);
    int32_t n_feat = model_->get_n_feature();

    if (n_feat <= 0) {
        err = ByteDTErrorCode::INVALID_MODEL;
        return {};
    }

    // Check dimension modulo: total_floats % n_feat == 0 (opcode 0x00cc20: msub x8, x2, x9, x8; cbz x8)
    if (total_floats % static_cast<size_t>(n_feat) != 0) {
        err = ByteDTErrorCode::DIMENSION_MISMATCH; // opcode 0xcc28
        return {};
    }

    size_t num_samples = total_floats / static_cast<size_t>(n_feat);

    auto start_time = std::chrono::high_resolution_clock::now();

    std::vector<float> output = model_->predict(input.data, num_samples);

    if (info) {
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float, std::milli> elapsed = end_time - start_time;
        info->inference_time_ms = elapsed.count();
        info->trees_evaluated = static_cast<int32_t>(model_->get_tree_count());
    }

    err = ByteDTErrorCode::OK;
    return output;
}

std::vector<int32_t> ByteDT::predict_leaf(Input input, ByteDTErrorCode& err, RunInfo* info) {
    if (!input.data) {
        err = ByteDTErrorCode::INVALID_INPUT;
        return {};
    }

    if (!model_) {
        err = ByteDTErrorCode::INVALID_MODEL;
        return {};
    }

    if (input.data_type != 1) {
        err = ByteDTErrorCode::DIMENSION_MISMATCH;
        return {};
    }

    size_t total_floats = input.size / sizeof(float);
    int32_t n_feat = model_->get_n_feature();

    if (n_feat <= 0 || (total_floats % static_cast<size_t>(n_feat) != 0)) {
        err = ByteDTErrorCode::DIMENSION_MISMATCH;
        return {};
    }

    size_t num_samples = total_floats / static_cast<size_t>(n_feat);

    auto start_time = std::chrono::high_resolution_clock::now();

    std::vector<int32_t> output = model_->predict_leaf(input.data, num_samples);

    if (info) {
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float, std::milli> elapsed = end_time - start_time;
        info->inference_time_ms = elapsed.count();
        info->trees_evaluated = static_cast<int32_t>(model_->get_tree_count());
    }

    err = ByteDTErrorCode::OK;
    return output;
}

std::vector<float> ByteDT::predict_raw(Input input) {
    if (!input.data || !model_) {
        return {};
    }

    size_t total_floats = input.size / sizeof(float);
    int32_t n_feat = model_->get_n_feature();
    if (n_feat <= 0) return {};

    size_t num_samples = total_floats / static_cast<size_t>(n_feat);
    return model_->predict_raw(input.data, num_samples);
}

} // namespace bytedt
