// ======================================================================
// RECONSTRUCTED HEADER: bytedt_adapter_bridge.h
// Library: libByteAIDT.so (ByteDance Pitaya ByteDT Decision Tree Bridge)
// Component: NextAI OpenCut AI & Decision Tree Core (CORE_02_AI_CV)
// Architecture: AArch64 (ARMv8-A / ARM64)
//
// Description (English):
//   High-level application bridge connecting ByteDTEngine to OpenCut video editor:
//   - Intelligent Export Bitrate Recommendation (predicting optimal bitrate vs quality)
//   - Dynamic Video Template Recommendation (ranking templates by visual/audio features)
//   - Video Aesthetic Quality Score Assessment
//
// Mô tả (Tiếng Việt):
//   Cầu nối ứng dụng cấp cao kết nối ByteDTEngine với trình biên tập video OpenCut:
//   - Gợi ý bitrate xuất video thông minh (tối ưu dung lượng vs chất lượng hình ảnh)
//   - Gợi ý mẫu video động (xếp hạng mẫu theo đặc trưng hình ảnh và nhịp điệu âm thanh)
//   - Đánh giá điểm chất lượng thẩm mỹ của video
// ======================================================================

#pragma once

#include "pitaya_engine_bytedt.h"
#include <string>
#include <vector>
#include <memory>
#include <mutex>

namespace NextAI::OpenCut::ByteAIDT {

struct VideoExportMeta {
    int32_t width{1920};
    int32_t height{1080};
    float fps{30.0f};
    float duration_sec{60.0f};
    float motion_score{0.5f};     // 0.0: static, 1.0: high motion
    float texture_complexity{0.5f};
    int32_t target_tier{1};       // 0: Draft, 1: Standard, 2: Ultra HD
};

struct TemplateRecommendation {
    std::string template_id{""};
    float match_score{0.0f};
    std::string category{""};
};

class ByteDTAdapterBridge {
public:
    static ByteDTAdapterBridge& Instance();

    bool Initialize(const std::string& model_dir);

    // 1. Gợi ý bitrate xuất video tối ưu (Kbps)
    int32_t RecommendExportBitrateKbps(const VideoExportMeta& meta);

    // 2. Gợi ý mẫu dựng video thông minh
    std::vector<TemplateRecommendation> RecommendTemplates(const std::vector<float>& video_features, int32_t top_k = 5);

    // 3. Đánh giá điểm thẩm mỹ video [0.0 .. 100.0]
    float EvaluateAestheticScore(const std::vector<float>& visual_audio_features);

    bool IsInitialized() const noexcept { return is_initialized_; }
    void Release();

private:
    ByteDTAdapterBridge();
    ~ByteDTAdapterBridge();

    std::shared_ptr<pitaya::ByteDTEngine> engine_{nullptr};
    bool is_initialized_{false};
    std::string model_dir_{""};
    mutable std::mutex bridge_mutex_;
};

} // namespace NextAI::OpenCut::ByteAIDT
