// ==============================================================================
// NextAI OpenCut - Reconstructed Media & Animation Engine
// Target Library: libanimax_bytevc1.so (lynx::animax & libByteVC1_dec.so)
// Component: Lynx AnimaX YUVFrameInfo & Color Transform Engine
// Language: C++17 / Native Android NDK
// Bilingual Documentation: English & Vietnamese (Song ngữ Anh - Việt)
// ==============================================================================

#ifndef NEXTAI_OPENCUT_ANIMAX_YUV_FRAME_H
#define NEXTAI_OPENCUT_ANIMAX_YUV_FRAME_H

#include "animax_bytevc1_types.h"
#include <vector>
#include <array>
#include <cmath>

namespace NextAI {
namespace OpenCut {
namespace AnimaxByteVC1 {

/**
 * @brief Representation of an uncompressed YUV frame in Lynx AnimaX.
 * Biểu diễn khung hình YUV thô trong động cơ Lynx AnimaX.
 * 
 * Reconstructed from:
 * - _ZN4lynx6animax12YUVFrameInfo8SetWidthEj
 * - _ZN4lynx6animax12YUVFrameInfo9SetHeightEj
 * - _ZN4lynx6animax12YUVFrameInfo11SetBitDepthEj
 * - _ZN4lynx6animax12YUVFrameInfo12SetYUVPixFmtENS0_9YUVPixFmtE
 * - _ZN4lynx6animax12YUVFrameInfo11SetLineSizeEjj
 * - _ZN4lynx6animax12YUVFrameInfo12SetLineWidthEjj
 * - _ZN4lynx6animax12YUVFrameInfo17UpdateChannelDataEjPKh
 * - _ZNK4lynx6animax12YUVFrameInfo14GetChannelDataEj
 */
class YUVFrameInfo {
public:
    YUVFrameInfo();
    ~YUVFrameInfo() = default;

    void SetWidth(uint32_t width);
    void SetHeight(uint32_t height);
    void SetBitDepth(uint32_t bit_depth);
    void SetYUVPixFmt(YUVPixFmt fmt);
    void SetLineSize(uint32_t channel, uint32_t line_size);
    void SetLineWidth(uint32_t channel, uint32_t line_width);
    void UpdateChannelData(uint32_t channel, const uint8_t* data);

    uint32_t GetWidth() const { return m_width; }
    uint32_t GetHeight() const { return m_height; }
    uint32_t GetBitDepth() const { return m_bit_depth; }
    YUVPixFmt GetYUVPixFmt() const { return m_pix_fmt; }
    uint32_t GetChannelDataWidth(uint32_t channel) const;
    uint32_t GetChannelDataHeight(uint32_t channel) const;
    const uint8_t* GetChannelData(uint32_t channel) const;
    uint32_t GetLineSize(uint32_t channel) const;

    /**
     * @brief Allocate internal planar memory for width, height, and format.
     * Cấp phát bộ nhớ ba mặt phẳng nội bộ theo kích thước và định dạng.
     */
    void AllocateBuffers();

    /**
     * @brief Check whether frame has valid dimensions and plane buffers.
     * Kiểm tra tính hợp lệ của khung hình.
     */
    bool IsValid() const;

    /**
     * @brief Mathematical color conversion: Convert YUV (BT.709) to RGB.
     * Chuyển đổi màu toán học: YUV chuẩn BT.709 sang RGB.
     */
    static void YUV709ToRGB(float y, float u, float v, float& r, float& g, float& b);

    /**
     * @brief Invertible conversion: Convert RGB to YUV (BT.709).
     * Phép biến đổi khả nghịch: RGB sang YUV chuẩn BT.709.
     */
    static void RGBToYUV709(float r, float g, float b, float& y, float& u, float& v);

private:
    uint32_t m_width{0};
    uint32_t m_height{0};
    uint32_t m_bit_depth{8};
    YUVPixFmt m_pix_fmt{YUVPixFmt::PIX_FMT_YUV420P};

    std::array<uint32_t, 3> m_linesizes{0, 0, 0};
    std::array<uint32_t, 3> m_linewidths{0, 0, 0};
    std::array<std::vector<uint8_t>, 3> m_channel_data;
};

/**
 * @brief RAII GL state backup and restore utility.
 * Tiện ích sao lưu và khôi phục trạng thái OpenGL theo mẫu RAII.
 * Reconstructed from: _ZN4lynx6animax20ScopedGLResetRestoreC1Ej
 */
class ScopedGLResetRestore {
public:
    explicit ScopedGLResetRestore(uint32_t flags);
    ~ScopedGLResetRestore();

    bool IsActive() const { return m_active; }

private:
    uint32_t m_flags{0};
    bool m_active{true};
};

} // namespace AnimaxByteVC1
} // namespace OpenCut
} // namespace NextAI

#endif // NEXTAI_OPENCUT_ANIMAX_YUV_FRAME_H
