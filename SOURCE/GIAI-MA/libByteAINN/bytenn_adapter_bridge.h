// ======================================================================
// RECONSTRUCTED HEADER: bytenn_adapter_bridge.h
// Library: libByteAINN.so (ByteDance Pitaya ByteNN Neural Engine Bridge)
// Component: NextAI OpenCut AI & Computer Vision Core (CORE_02_AI_CV)
// Architecture: AArch64 (ARMv8-A / ARM64)
//
// Description (English):
//   High-level AI application bridge integrating ByteNNEngine into OpenCut video editing:
//   - Video Background Cutout / Matting (Chroma / Human Segmentation)
//   - Facial Landmark & Beauty Tracking
//   - Smart Dynamic Crop & Subject Framing
//   - Audio-to-Text Acoustic Feature Encoding
//
// Mô tả (Tiếng Việt):
//   Cầu nối ứng dụng AI cấp cao tích hợp ByteNNEngine vào biên tập video OpenCut:
//   - Tách nền video / Matting thông minh (Phân đoạn người / Khóa màu)
//   - Theo dõi điểm mốc khuôn mặt và làm đẹp tự động
//   - Cắt khung hình động thông minh bám theo chủ thể
//   - Mã hóa đặc trưng âm học phục vụ nhận dạng giọng nói thành văn bản
// ======================================================================

#pragma once

#include "pitaya_engine_bytenn.h"
#include <string>
#include <vector>
#include <memory>
#include <functional>

namespace NextAI::OpenCut::ByteAINN {

// ----------------------------------------------------------------------
// CutoutMaskResult (Kết quả mặt nạ tách nền video)
// ----------------------------------------------------------------------
struct CutoutMaskResult {
    int32_t width{0};
    int32_t height{0};
    std::vector<uint8_t> alpha_mask; // 8-bit alpha mask [0..255]
    float confidence{0.0f};
    int64_t inference_time_us{0};
};

// ----------------------------------------------------------------------
// FaceLandmarkResult (Điểm mốc khuôn mặt 106 điểm chuẩn ByteDance)
// ----------------------------------------------------------------------
struct FacePoint {
    float x{0.0f};
    float y{0.0f};
    float score{0.0f};
};

struct FaceLandmarkResult {
    std::vector<FacePoint> points; // 106 keypoints
    float roll{0.0f};
    float pitch{0.0f};
    float yaw{0.0f};
    float eye_open_left{1.0f};
    float eye_open_right{1.0f};
};

// ----------------------------------------------------------------------
// ByteNNAdapterBridge Class
// ----------------------------------------------------------------------
class ByteNNAdapterBridge {
public:
    static ByteNNAdapterBridge& Instance();

    // Khởi tạo cầu nối với đường dẫn mô hình
    bool Initialize(const std::string& model_root_dir, pitaya::ForwardType forward_type = pitaya::ForwardType::FORWARD_AUTO);

    // 1. Tách nền video (Human Matting)
    CutoutMaskResult SegmentHumanMatting(const uint8_t* rgba_frame, int32_t width, int32_t height);

    // 2. Nhận diện 106 điểm mốc khuôn mặt
    std::vector<FaceLandmarkResult> DetectFaceLandmarks(const uint8_t* rgba_frame, int32_t width, int32_t height);

    // 3. Khung hình thông minh (Smart Crop)
    void CalculateSmartCrop(const uint8_t* rgba_frame, int32_t width, int32_t height,
                            float& crop_x, float& crop_y, float& crop_w, float& crop_h);

    // Trạng thái sẵn sàng
    bool IsInitialized() const noexcept { return is_initialized_; }
    void Release();

private:
    ByteNNAdapterBridge();
    ~ByteNNAdapterBridge();

    std::shared_ptr<pitaya::ByteNNEngine> engine_{nullptr};
    bool is_initialized_{false};
    pitaya::ForwardType forward_type_{pitaya::ForwardType::FORWARD_CPU};
    std::string model_dir_{""};
    mutable std::mutex bridge_mutex_;
};

} // namespace NextAI::OpenCut::ByteAINN
