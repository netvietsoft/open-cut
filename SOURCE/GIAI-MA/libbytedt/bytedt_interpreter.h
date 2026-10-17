// ======================================================================
// NextAI OpenCut — libbytedt Reconstructed ByteDT Engine Interface
// Giao diện chính của ByteDT Inference Engine (ByteDT Public API)
//
// Demangled Symbols Parity:
//   - _ZN6bytedt6ByteDT13create_engineEv
//   - _ZN6bytedt6ByteDT20load_model_from_pathEPKcRNS_15ByteDTErrorCodeEPNS_7RunInfoE
//   - _ZN6bytedt6ByteDT22load_model_from_bufferEPvmRNS_15ByteDTErrorCodeEPNS_7RunInfoE
//   - _ZN6bytedt6ByteDT7predictENS_5InputERNS_15ByteDTErrorCodeEPNS_7RunInfoE
//   - _ZN6bytedt6ByteDT12predict_leafENS_5InputERNS_15ByteDTErrorCodeEPNS_7RunInfoE
//   - _ZN6bytedt6ByteDT11predict_rawENS_5InputE
// ======================================================================

#pragma once

#include "bytedt_types.h"
#include "bytedt_model.h"
#include <memory>
#include <vector>
#include <chrono>

namespace bytedt {

/**
 * @brief ByteDT Decision Tree Inference Engine.
 * Bộ máy suy diễn cây quyết định ByteDT.
 */
class ByteDT {
private:
    std::shared_ptr<BaseModel> model_;   ///< Active loaded model / Mô hình đang hoạt động

public:
    ByteDT();
    virtual ~ByteDT();

    /**
     * @brief Factory method creating an engine instance.
     * Phương thức khởi tạo engine (khớp opcode 0x13b30).
     */
    static std::shared_ptr<ByteDT> create_engine();

    /**
     * @brief Loads a decision tree model from a file path.
     * Nạp mô hình cây quyết định từ đường dẫn file.
     */
    bool load_model_from_path(const char* filepath, ByteDTErrorCode& err, RunInfo* info = nullptr);

    /**
     * @brief Loads a decision tree model from an in-memory byte buffer.
     * Nạp mô hình cây quyết định từ vùng đệm bộ nhớ.
     */
    bool load_model_from_buffer(void* buffer, size_t size, ByteDTErrorCode& err, RunInfo* info = nullptr);

    /**
     * @brief Evaluates inference and returns final probabilities/scores.
     * Thực hiện suy diễn mô hình và trả về xác suất hoặc điểm số dự đoán.
     *
     * Opcode Validation at 0x00cbf4 - 0x00cc28:
     *   - Check data_type == 1 (cmp w9, #1)
     *   - Check float_count % n_feature == 0 (msub x8, x2, x9, x8; cbz x8)
     *   - Set err = 5 (DimensionMismatch) on failure
     */
    std::vector<float> predict(Input input, ByteDTErrorCode& err, RunInfo* info = nullptr);

    /**
     * @brief Evaluates inference and returns activated leaf index per tree.
     * Thực hiện suy diễn và trả về chỉ số nút lá được kích hoạt trong mỗi cây.
     */
    std::vector<int32_t> predict_leaf(Input input, ByteDTErrorCode& err, RunInfo* info = nullptr);

    /**
     * @brief Evaluates raw unnormalized additive or voting scores.
     * Trả về điểm số thô chưa chuẩn hóa từ các cây quyết định.
     */
    std::vector<float> predict_raw(Input input);

    // Engine inspection helpers
    std::shared_ptr<BaseModel> get_model() const { return model_; }
    void set_model(std::shared_ptr<BaseModel> m) { model_ = m; }
};

} // namespace bytedt
