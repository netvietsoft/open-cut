/**
 * NextAI OpenCut Face Mesh & AR Beauty Engine Header
 * Tệp Khai Báo Lõi Nhận Diện Khuôn Mặt 468 Điểm & Trang Điểm AR
 * Dual-language comments: Tiếng Việt (VN) / English (EN)
 */

#ifndef NEXTAI_FACE_MESH_ENGINE_H
#define NEXTAI_FACE_MESH_ENGINE_H

#include <vector>
#include <string>
#include <cstdint>

namespace nextai::ai {

/**
 * 3D Facial Landmark Point (Normalized 0.0 - 1.0)
 * Điểm mốc tọa độ 3D trên khuôn mặt
 */
struct FaceLandmarkPoint {
    float x;
    float y;
    float z;
    float visibility;
};

/**
 * Facial Morphing & Beauty Parameters
 * Thông số làm đẹp và biến dạng định hình khuôn mặt
 */
struct BeautyFaceConfig {
    float smooth_skin_level;    // 0.0 - 1.0 (Làm mịn da AI)
    float whiten_skin_level;    // 0.0 - 1.0 (Làm sáng & nâng tông da)
    float slim_face_factor;     // 0.0 - 1.0 (Thon gọn mặt V-line)
    float big_eyes_factor;      // 0.0 - 1.0 (Phóng to mắt tự nhiên)
    float nose_slimming_factor; // 0.0 - 1.0 (Thu gọn cánh mũi)
    float jawline_lift_factor;  // 0.0 - 1.0 (Gọt cằm & nâng cơ mặt)
    std::string ar_sticker_id;  // ID phụ kiện AR (Kính, Mũ, Tai mèo 3D)
};

/**
 * 468-Point Face Mesh & AR Beautification Processor
 * Lõi Xử Lý Lưới Gương Mặt 468 Điểm & Làm Đẹp Tự Động
 */
class FaceMeshEngine {
public:
    FaceMeshEngine();
    ~FaceMeshEngine();

    /**
     * Process frame and detect 468 3D landmarks
     * Nhận diện và trích xuất 468 điểm mốc không gian 3D
     */
    bool DetectFaceMesh(const uint8_t* nv21_buffer, int32_t width, int32_t height, 
                        std::vector<FaceLandmarkPoint>& out_landmarks);

    /**
     * Apply face beautification and morphing onto video texture
     * Áp dụng thuật toán làm đẹp và biến dạng khuôn mặt
     */
    bool ApplyBeautification(uint32_t input_texture, uint32_t output_texture,
                            const std::vector<FaceLandmarkPoint>& landmarks,
                            const BeautyFaceConfig& config,
                            int32_t width, int32_t height);

    /**
     * Render AR 3D stickers attached to face anchors
     * Vẽ phụ kiện 3D AR bám dính theo chuyển động khuôn mặt
     */
    bool RenderArAccessories(uint32_t target_texture, 
                            const std::vector<FaceLandmarkPoint>& landmarks,
                            const std::string& ar_asset_path);
};

} // namespace nextai::ai

#endif // NEXTAI_FACE_MESH_ENGINE_H
