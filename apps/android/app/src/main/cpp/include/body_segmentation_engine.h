/**
 * NextAI OpenCut Body Pose & Segmentation Engine Header
 * Tệp Khai Báo Lõi Nhận Diện Dáng Người 33 Điểm, Tách Nền AI & Hiệu Ứng Viền Neon
 * Dual-language comments: Tiếng Việt (VN) / English (EN)
 */

#ifndef NEXTAI_BODY_SEGMENTATION_ENGINE_H
#define NEXTAI_BODY_SEGMENTATION_ENGINE_H

#include <vector>
#include <string>
#include <cstdint>

namespace nextai::ai {

/**
 * 33-point Pose Landmark Point
 * Tọa độ điểm khớp xương trên cơ thể người
 */
struct PoseLandmarkPoint {
    float x;
    float y;
    float z;
    float score;
};

/**
 * Body Effect Configuration
 * Cấu hình hiệu ứng cơ thể và tách nền AI
 */
struct BodyEffectConfig {
    bool enable_ai_matting;          // Tách nền thông minh không cần phông xanh
    bool enable_contour_glow;        // Viền sáng phát quang quanh cơ thể
    std::string glow_color_hex;      // Màu viền Neon (VD: "#00E5FF", "#FF007F")
    float glow_thickness;            // Độ dày viền sáng (1.0 - 10.0)
    bool enable_clone_ghost_trail;   // Phân thân vệt bóng chuyển động
    int32_t ghost_trail_count;       // Số lượng vệt bóng phân thân (1 - 5)
};

/**
 * Body Segmentation & Pose Tracking Engine
 * Động Cơ Tách Nền Người & Theo Dõi Khớp Xương Cơ Thể
 */
class BodySegmentationEngine {
public:
    BodySegmentationEngine();
    ~BodySegmentationEngine();

    /**
     * Detect 33 body pose landmarks
     * Nhận diện 33 điểm khớp xương chuyển động
     */
    bool DetectPoseLandmarks(const uint8_t* frame_buffer, int32_t width, int32_t height,
                            std::vector<PoseLandmarkPoint>& out_pose_points);

    /**
     * Generate Alpha Matting Mask (Human Segmentation)
     * Trích xuất mặt nạ tách người chuẩn xác
     */
    bool GenerateMattingMask(uint32_t input_texture, uint32_t mask_texture, int32_t width, int32_t height);

    /**
     * Render Neon Contour Glow & Ghost Clone Trails
     * Vẽ viền phát quang Neon & vệt bóng phân thân theo dáng người
     */
    bool RenderBodyEffects(uint32_t source_texture, uint32_t target_texture,
                           const BodyEffectConfig& config, int32_t width, int32_t height, float time_sec);
};

} // namespace nextai::ai

#endif // NEXTAI_BODY_SEGMENTATION_ENGINE_H
