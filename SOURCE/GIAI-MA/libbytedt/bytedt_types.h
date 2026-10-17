// ======================================================================
// NextAI OpenCut — libbytedt Reconstructed Core Types & Definitions
// Định nghĩa kiểu dữ liệu và cấu trúc nền tảng cho libbytedt
//
// Demangled Symbols Parity:
//   - _ZN6bytedt11get_versionEv (version "2.1.6")
//   - _ZN6bytedt14WarningHandler7processE...
//   - _ZN6bytedt7Warning4warnE...
//   - _ZN6bytedt15SmallVectorBase8grow_podEPvmm
// ======================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <mutex>
#include <cstring>
#include <cmath>

namespace bytedt {

/**
 * @brief Error codes returned by ByteDT inference engine.
 * Mã lỗi trả về từ công cụ suy diễn ByteDT (khớp mã opcode strb [x20/x21]).
 */
enum class ByteDTErrorCode : uint8_t {
    OK = 0,                     ///< Success / Thành công
    MODEL_LOAD_ERROR = 1,       ///< Failed to parse or load model / Lỗi nạp mô hình
    INVALID_MODEL = 2,          ///< Model structure corrupted / Cấu trúc mô hình hỏng
    INVALID_INPUT = 3,          ///< Null pointer or bad state / Dữ liệu đầu vào không hợp lệ (opcode 0xcbb4)
    INFERENCE_ERROR = 4,        ///< Evaluation failed / Lỗi suy diễn
    DIMENSION_MISMATCH = 5      ///< Float count % n_feature != 0 / Không khớp số chiều (opcode 0xcc28)
};

/**
 * @brief Machine Learning Model Type enum.
 * Kiểu mô hình học máy: Phân loại, Hồi quy, Đa nhãn (GBDT & Random Forest).
 */
enum class ModelType : int32_t {
    UNKNOWN = 0,
    BOOSTING_CLASSIFICATION = 1,
    BOOSTING_REGRESSION = 2,
    VOTING_CLASSIFICATION = 3,
    VOTING_REGRESSION = 4,
    BOOSTING_MULTI_LABEL_CLASSIFICATION = 5,
    VOTING_MULTI_LABEL_CLASSIFICATION = 6
};

/**
 * @brief Relationship between trees in the ensemble.
 * Mối quan hệ giữa các cây quyết định trong quần thể (Cộng dồn Boosting hoặc Biểu quyết Voting).
 */
enum class TreeRelation : int32_t {
    UNKNOWN = 0,
    BOOSTING = 1,
    VOTING = 2
};

/**
 * @brief Numerical split comparison operator.
 * Toán tử so sánh phân nhánh số học (khớp các khối lệnh fcmp trong AArch64).
 */
enum class CompareOp : uint8_t {
    OP_EQUAL = 0,          ///< feature == threshold (cset w0, eq)
    OP_LESS_THAN = 1,      ///< feature < threshold (fcmp s1, s0; cset w0, gt)
    OP_LESS_EQUAL = 2,     ///< feature <= threshold (fcmp s1, s0; cset w0, ge)
    OP_GREATER_THAN = 3,   ///< feature > threshold (fcmp s1, s0; cset w0, mi)
    OP_GREATER_EQUAL = 4   ///< feature >= threshold (fcmp s1, s0; cset w0, ls)
};

/**
 * @brief Source location tracker for debug assertions and warnings.
 * Vị trí mã nguồn phục vụ cảnh báo và ghi vết lỗi.
 */
struct SourceLocation {
    const char* file;
    int line;

    SourceLocation(const char* f = "unknown", int l = 0) : file(f), line(l) {}
};

/**
 * @brief Input feature container for inference.
 * Cấu trúc đóng gói đặc trưng đầu vào (24 bytes ABI layout).
 * 
 * ABI Layout:
 *   [0x00] data: float* (pointer to feature buffer)
 *   [0x08] size: uint64_t (size in bytes, divided by 4 = float count)
 *   [0x10] data_type: uint8_t (1 = Float32, checked at opcode 0x00cbf4)
 */
struct Input {
    const float* data;
    size_t size;           ///< Size in bytes / Kích thước tính theo byte
    uint8_t data_type;     ///< Type identifier (1 = FP32) / Mã định danh kiểu dữ liệu

    Input() : data(nullptr), size(0), data_type(1) {}
    Input(const float* ptr, size_t bytes, uint8_t type = 1)
        : data(ptr), size(bytes), data_type(type) {}
    Input(const std::vector<float>& vec)
        : data(vec.data()), size(vec.size() * sizeof(float)), data_type(1) {}
};

/**
 * @brief Performance profiling and diagnostic run information.
 * Thông tin chẩn đoán hiệu năng và thống kê lượt chạy suy diễn.
 *
 * ABI Layout:
 *   [0x1c] inference_time_ms: float (measured via timer division at opcode 0xd0e4)
 *   [0x24] trees_evaluated: int32_t (evaluated tree count at opcode 0xd0ec)
 */
struct RunInfo {
    uint8_t reserved[0x1c];
    float inference_time_ms;
    uint32_t padding;
    int32_t trees_evaluated;

    RunInfo() : inference_time_ms(0.0f), padding(0), trees_evaluated(0) {
        std::memset(reserved, 0, sizeof(reserved));
    }
};

/**
 * @brief Custom warning handler interface for ByteDT.
 * Giao diện bộ xử lý cảnh báo tùy biến.
 */
class WarningHandler {
public:
    virtual ~WarningHandler() = default;
    virtual void process(const SourceLocation& loc, const std::string& msg) {
        // Default standard error logging
        // Ghi nhật ký chuẩn ra stderr theo mặc định
        std::cerr << "[ByteDT Warning] " << loc.file << ":" << loc.line << " " << msg << std::endl;
    }
};

/**
 * @brief Global warning registry.
 * Đăng ký cảnh báo toàn cục cho engine.
 */
class Warning {
private:
    static inline WarningHandler default_handler_;
    static inline WarningHandler* current_handler_ = &default_handler_;
    static inline std::mutex warning_mutex_;

public:
    static void set_warning_handler(WarningHandler* handler) {
        std::lock_guard<std::mutex> lock(warning_mutex_);
        current_handler_ = handler ? handler : &default_handler_;
    }

    static WarningHandler* get_warning_handler() {
        std::lock_guard<std::mutex> lock(warning_mutex_);
        return current_handler_;
    }

    static void warn(SourceLocation loc, const std::string& msg) {
        WarningHandler* h = get_warning_handler();
        if (h) {
            h->process(loc, msg);
        }
    }
};

/**
 * @brief SmallVector dynamic memory allocator helper.
 * Bộ hỗ trợ cấp phát động cho SmallVector (khớp _ZN6bytedt15SmallVectorBase8grow_podEPvmm).
 */
class SmallVectorBase {
public:
    static void* grow_pod(void* first_el, size_t min_capacity, size_t type_size) {
        // Geometric 2x growth strategy matching opcode 0x2cc5c (add x8, x3, x8, lsl #1)
        // Chiến lược mở rộng gấp đôi hình học
        size_t new_cap = (min_capacity < 8) ? 8 : min_capacity * 2;
        size_t total_bytes = new_cap * type_size;
        void* new_buf = std::malloc(total_bytes);
        if (!new_buf) {
            throw std::bad_alloc();
        }
        if (first_el) {
            std::memcpy(new_buf, first_el, min_capacity * type_size);
        }
        return new_buf;
    }
};

/**
 * @brief String utilities used in model parsing and diagnostic naming.
 * Tiện ích chuỗi ký tự khớp symbol ReplaceAll và StripBasename.
 */
inline void ReplaceAll(std::string& str, const char* from, const char* to) {
    if (!from || !to || std::strlen(from) == 0) return;
    size_t start_pos = 0;
    std::string from_str(from);
    std::string to_str(to);
    while ((start_pos = str.find(from_str, start_pos)) != std::string::npos) {
        str.replace(start_pos, from_str.length(), to_str);
        start_pos += to_str.length();
    }
}

namespace detail {
inline std::string StripBasename(const std::string& path) {
    size_t last_slash = path.find_last_of("/\\");
    if (last_slash == std::string::npos) {
        return path;
    }
    return path.substr(last_slash + 1);
}
} // namespace detail

/**
 * @brief Library version query.
 * Truy vấn phiên bản thư viện (trả về std::string("2.1.6") theo opcode 0x144a8).
 */
inline std::string get_version() {
    return std::string("2.1.6");
}

} // namespace bytedt
