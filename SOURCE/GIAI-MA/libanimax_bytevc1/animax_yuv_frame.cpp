// ==============================================================================
// NextAI OpenCut - Reconstructed Media & Animation Engine
// Target Library: libanimax_bytevc1.so (lynx::animax & libByteVC1_dec.so)
// Component: Lynx AnimaX YUVFrameInfo & Color Space Mathematics
// Language: C++17 / Native Android NDK
// Bilingual Documentation: English & Vietnamese (Song ngữ Anh - Việt)
// ==============================================================================

#include "animax_yuv_frame.h"
#include <cstring>
#include <algorithm>
#include <cstdio>

namespace NextAI {
namespace OpenCut {
namespace AnimaxByteVC1 {

YUVFrameInfo::YUVFrameInfo() {
    m_linesizes.fill(0);
    m_linewidths.fill(0);
}

void YUVFrameInfo::SetWidth(uint32_t width) {
    m_width = width;
}

void YUVFrameInfo::SetHeight(uint32_t height) {
    m_height = height;
}

void YUVFrameInfo::SetBitDepth(uint32_t bit_depth) {
    m_bit_depth = bit_depth;
}

void YUVFrameInfo::SetYUVPixFmt(YUVPixFmt fmt) {
    m_pix_fmt = fmt;
}

void YUVFrameInfo::SetLineSize(uint32_t channel, uint32_t line_size) {
    if (channel < 3) {
        m_linesizes[channel] = line_size;
    }
}

void YUVFrameInfo::SetLineWidth(uint32_t channel, uint32_t line_width) {
    if (channel < 3) {
        m_linewidths[channel] = line_width;
    }
}

uint32_t YUVFrameInfo::GetLineSize(uint32_t channel) const {
    if (channel < 3) {
        return m_linesizes[channel];
    }
    return 0;
}

uint32_t YUVFrameInfo::GetChannelDataWidth(uint32_t channel) const {
    if (channel == 0) return m_width;
    // For 4:2:0 subsampling, chroma width is half
    if (m_pix_fmt == YUVPixFmt::PIX_FMT_YUV420P || m_pix_fmt == YUVPixFmt::PIX_FMT_NV12 || m_pix_fmt == YUVPixFmt::PIX_FMT_P010) {
        return (m_width + 1) / 2;
    }
    return m_width;
}

uint32_t YUVFrameInfo::GetChannelDataHeight(uint32_t channel) const {
    if (channel == 0) return m_height;
    // For 4:2:0 subsampling, chroma height is half
    if (m_pix_fmt == YUVPixFmt::PIX_FMT_YUV420P || m_pix_fmt == YUVPixFmt::PIX_FMT_NV12 || m_pix_fmt == YUVPixFmt::PIX_FMT_P010) {
        return (m_height + 1) / 2;
    }
    return m_height;
}

const uint8_t* YUVFrameInfo::GetChannelData(uint32_t channel) const {
    if (channel < 3 && !m_channel_data[channel].empty()) {
        return m_channel_data[channel].data();
    }
    return nullptr;
}

void YUVFrameInfo::UpdateChannelData(uint32_t channel, const uint8_t* data) {
    if (channel >= 3 || !data) return;

    uint32_t h = GetChannelDataHeight(channel);
    uint32_t stride = m_linesizes[channel];
    if (stride == 0) {
        stride = GetChannelDataWidth(channel) * ((m_bit_depth > 8) ? 2 : 1);
        m_linesizes[channel] = stride;
    }

    size_t plane_bytes = static_cast<size_t>(h) * stride;
    m_channel_data[channel].resize(plane_bytes);
    std::memcpy(m_channel_data[channel].data(), data, plane_bytes);
}

void YUVFrameInfo::AllocateBuffers() {
    for (uint32_t c = 0; c < 3; ++c) {
        uint32_t h = GetChannelDataHeight(c);
        uint32_t w = GetChannelDataWidth(c);
        uint32_t bytes_per_sample = (m_bit_depth > 8) ? 2 : 1;
        uint32_t stride = w * bytes_per_sample;
        m_linesizes[c] = stride;
        m_linewidths[c] = w;
        m_channel_data[c].assign(static_cast<size_t>(h) * stride, 0);
    }
}

bool YUVFrameInfo::IsValid() const {
    return (m_width > 0 && m_height > 0 && !m_channel_data[0].empty());
}

// ==============================================================================
// Mathematical Color Space Transformation (BT.709 ITU-R)
// ==============================================================================
// Forward Matrix (YUV to RGB):
// R = Y + 1.5748 * (V - 128)
// G = Y - 0.1873 * (U - 128) - 0.4681 * (V - 128)
// B = Y + 1.8556 * (U - 128)
void YUVFrameInfo::YUV709ToRGB(float y, float u, float v, float& r, float& g, float& b) {
    float c = y - 16.0f;
    float d = u - 128.0f;
    float e = v - 128.0f;

    r = 1.164383f * c + 1.792741f * e;
    g = 1.164383f * c - 0.213249f * d - 0.532909f * e;
    b = 1.164383f * c + 2.112402f * d;

    // Clamping to [0, 255]
    r = std::max(0.0f, std::min(255.0f, r));
    g = std::max(0.0f, std::min(255.0f, g));
    b = std::max(0.0f, std::min(255.0f, b));
}

// Inverse Matrix (RGB to YUV):
// Y = 0.2126 * R + 0.7152 * G + 0.0722 * B
// U = -0.1146 * R - 0.3854 * G + 0.5000 * B + 128
// V = 0.5000 * R - 0.4542 * G - 0.0458 * B + 128
void YUVFrameInfo::RGBToYUV709(float r, float g, float b, float& y, float& u, float& v) {
    y = 16.0f + (0.182586f * r + 0.614231f * g + 0.062007f * b);
    u = 128.0f + (-0.100644f * r - 0.338572f * g + 0.439216f * b);
    v = 128.0f + (0.439216f * r - 0.398942f * g - 0.040274f * b);

    y = std::max(16.0f, std::min(235.0f, y));
    u = std::max(16.0f, std::min(240.0f, u));
    v = std::max(16.0f, std::min(240.0f, v));
}

ScopedGLResetRestore::ScopedGLResetRestore(uint32_t flags)
    : m_flags(flags), m_active(true) {
    // In real GL, saves glGetIntegerv(GL_ACTIVE_TEXTURE), glPixelStorei, etc.
}

ScopedGLResetRestore::~ScopedGLResetRestore() {
    // In real GL, restores prior bound textures and pixel packing
    m_active = false;
}

} // namespace AnimaxByteVC1
} // namespace OpenCut
} // namespace NextAI
