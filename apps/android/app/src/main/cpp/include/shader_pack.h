/**
 * NextAI OpenCut Shader Pack & 3D Effects Engine Header
 * Tệp Khai Báo Bộ Lọc Đồ Họa Shader Pack & Hiệu Ứng Không Gian 3D
 * Dual-language comments: Tiếng Việt (VN) / English (EN)
 */

#ifndef NEXTAI_SHADER_PACK_H
#define NEXTAI_SHADER_PACK_H

#include <string>
#include <vector>
#include <unordered_map>
#include <cstdint>

namespace nextai::graphics {

/**
 * Shader Category Enum / Phân loại bộ lọc Shader
 */
enum class ShaderCategory {
    COLOR_LUT_GRADING,     // 3D Color LUT & Tone Mapping / Phối màu LUT 3D điện ảnh
    SPATIAL_3D_PARALLAX,   // 3D Parallax, Dolly Zoom & Perspective / Không gian 3D & Parallax
    GLITCH_DISTORTION,     // RGB Split, VHS Scanline, Wave Warp / Nhiễu sóng & Biến dạng
    ATMOSPHERIC_LIGHT,     // Lens Flare, Light Leaks, Bloom, Halation / Vệt sáng & Hào quang
    FILM_EMULATION,        // 35mm Grain, Super 8 Scratches, Vignette / Giả lập máy quay phim nhựa
    MOTION_BLUR_SHARPEN,   // Directional Blur, Zoom Blur, High-Pass / Mờ chuyển động & Làm nét
    SPLIT_SCREEN_COLLAGE,  // 2-way, 4-grid, Diagonal Mirror / Phân chia màn hình đa góc
    DYNAMIC_TRANSITION     // Zoom Spin, Whip Pan, Dissolve Ripple / Chuyển cảnh động
};

/**
 * Shader Effect Metadata / Dữ liệu mô tả hiệu ứng Shader
 */
struct ShaderEffectInfo {
    std::string effect_id;
    std::string display_name;
    std::string display_name_vi;
    ShaderCategory category;
    std::string vertex_shader_glsl;
    std::string fragment_shader_glsl;
    std::unordered_map<std::string, float> default_params;
    bool requires_depth_map;
    bool is_vip;
};

/**
 * Shader Pack Registry & Pipeline Executor
 * Động Cơ Đăng Ký & Thực Thi Bộ Lọc Shader OpenGL ES 3.0
 */
class ShaderPackEngine {
public:
    ShaderPackEngine();
    ~ShaderPackEngine();

    /**
     * Initialize shader registry with 100+ built-in presets
     * Khởi tạo danh mục với hơn 100 hiệu ứng shader chuẩn hóa
     */
    void InitializePresets();

    /**
     * Get list of all available effects in category
     * Lấy danh sách hiệu ứng theo từng danh mục
     */
    std::vector<ShaderEffectInfo> GetEffectsByCategory(ShaderCategory category) const;

    /**
     * Get specific effect by ID
     * Lấy thông tin hiệu ứng theo ID
     */
    const ShaderEffectInfo* GetEffectById(const std::string& effect_id) const;

    /**
     * Compile & link GLSL shader program on GPU
     * Biên dịch và liên kết chương trình GLSL trên GPU
     */
    uint32_t CompileShaderProgram(const std::string& effect_id);

    /**
     * Apply shader effect onto frame texture
     * Áp dụng hiệu ứng shader lên texture khung hình video
     */
    bool ApplyEffect(uint32_t input_texture_id, uint32_t output_fbo_id, 
                     const std::string& effect_id, const std::unordered_map<std::string, float>& params,
                     int32_t width, int32_t height, float progress);

private:
    std::unordered_map<std::string, ShaderEffectInfo> registry_;
    std::unordered_map<std::string, uint32_t> compiled_programs_;
};

} // namespace nextai::graphics

#endif // NEXTAI_SHADER_PACK_H
