/**
 * NextAI OpenCut Sticker & Kinetic 3D Text Engine Header
 * Tệp Khai Báo Động Cơ Nhãn Dán Động & Kiểu Chữ Động 3D
 * Dual-language comments: Tiếng Việt (VN) / English (EN)
 */

#ifndef NEXTAI_STICKER_TEXT_ENGINE_H
#define NEXTAI_STICKER_TEXT_ENGINE_H

#include <string>
#include <vector>
#include <cstdint>

namespace nextai::graphics {

/**
 * Keyframe for Transformation (Position, Scale, Rotation, Opacity)
 * Điểm khóa biến đổi chuyển động theo thời gian
 */
struct TransformKeyframe {
    int64_t timestamp_ms;
    float pos_x;
    float pos_y;
    float scale_x;
    float scale_y;
    float rotation_deg;
    float opacity;
};

/**
 * Animated Sticker Item
 * Phần tử nhãn dán động đa lớp
 */
struct StickerItem {
    std::string sticker_id;
    std::string asset_url;
    int64_t start_time_ms;
    int64_t end_time_ms;
    bool is_lottie_vector;
    std::vector<TransformKeyframe> keyframes;
};

/**
 * Kinetic 3D Typography Item
 * Phần tử phụ đề và chữ nghệ thuật 3D
 */
struct TextItem3D {
    std::string text_id;
    std::string content;
    std::string font_family;
    std::string text_color_hex;
    std::string stroke_color_hex;
    float stroke_width;
    std::string animation_type; // "typewriter", "wave_bounce", "neon_pulse", "3d_extrude"
    int64_t start_time_ms;
    int64_t end_time_ms;
    std::vector<TransformKeyframe> keyframes;
};

/**
 * Sticker & Text Vector Rendering Engine
 * Động Cơ Kết Xuất Nhãn Dán & Chữ Nghệ Thuật
 */
class StickerTextEngine {
public:
    StickerTextEngine();
    ~StickerTextEngine();

    /**
     * Add or update animated sticker
     * Thêm hoặc cập nhật nhãn dán động
     */
    bool AddSticker(const StickerItem& sticker);

    /**
     * Add or update kinetic 3D text
     * Thêm hoặc cập nhật văn bản nghệ thuật 3D
     */
    bool AddText(const TextItem3D& text);

    /**
     * Render all active stickers and text at given timestamp
     * Vẽ tất cả nhãn dán và chữ đang hoạt động tại mốc thời gian
     */
    bool RenderOverlays(uint32_t target_fbo, int64_t current_time_ms, int32_t width, int32_t height);

private:
    std::vector<StickerItem> stickers_;
    std::vector<TextItem3D> text_items_;
};

} // namespace nextai::graphics

#endif // NEXTAI_STICKER_TEXT_ENGINE_H
