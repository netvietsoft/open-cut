// ==============================================================================
// NextAI OpenCut - Reconstructed Media & Animation Engine
// Target Library: libanimax_bytevc1.so (lynx::animax & libByteVC1_dec.so)
// Component: VideoDecoderByteVc1 Implementation (video_decoder_bytevc1.cc)
// Language: C++17 / Native Android NDK
// Bilingual Documentation: English & Vietnamese (Song ngữ Anh - Việt)
// ==============================================================================

#include "animax_bytevc1_decoder.h"
#include <iostream>
#include <cstring>

#if defined(__ANDROID__)
#include <android/log.h>
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, BinaryConstants::LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, BinaryConstants::LOG_TAG, __VA_ARGS__)
#else
#define LOGE(...) fprintf(stderr, "[VideoDecoderByteVc1] "); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\n")
#define LOGI(...) printf("[VideoDecoderByteVc1] "); printf(__VA_ARGS__); printf("\n")
#endif

namespace NextAI {
namespace OpenCut {
namespace AnimaxByteVC1 {

VideoDecoderByteVc1::VideoDecoderByteVc1() {
}

VideoDecoderByteVc1::~VideoDecoderByteVc1() {
    releaseResources();
}

void VideoDecoderByteVc1::releaseResources() {
    std::lock_guard<std::mutex> lock(m_mutex);
    const auto& sym = ByteVC1LibLoader::getInstance().getSymbols();

    if (m_frame && sym.return_frame && m_dec_handle) {
        sym.return_frame(m_dec_handle, m_frame);
        m_frame = nullptr;
    }

    if (m_packet) {
        if (sym.free_packet) {
            sym.free_packet(m_packet);
        } else if (sym.release_ttpacket) {
            sym.release_ttpacket(m_packet);
        }
        m_packet = nullptr;
    }

    if (m_dec_handle && sym.dec_destroy) {
        sym.dec_destroy(m_dec_handle);
        m_dec_handle = nullptr;
    }

    if (m_param) {
        if (sym.free_param) {
            sym.free_param(m_param);
        } else if (sym.release_param) {
            sym.release_param(m_param);
        }
        m_param = nullptr;
    }

    m_initialized = false;
}

bool VideoDecoderByteVc1::init(uint32_t width, uint32_t height) {
    std::lock_guard<std::mutex> lock(m_mutex);

    if (!ByteVC1LibLoader::getInstance().isLoaded()) {
        ByteVC1LibLoader::getInstance().loadLibrary();
    }

    const auto& sym = ByteVC1LibLoader::getInstance().getSymbols();
    if (!sym.is_loaded) {
        LOGE("Failed to initialize VideoDecoderByteVc1: library not loaded.");
        return false;
    }

    m_width = width;
    m_height = height;

    // 1. Allocate decoder parameters (opcode 0x00209f)
    if (sym.alloc_default_param) {
        m_param = sym.alloc_default_param();
    }
    if (!m_param) {
        LOGE("ByteVC1LibLoader: create decoder failed, failed to allocate decoder parameters.");
        return false;
    }

    // 2. Create decoder handle (opcode 0x002184)
    if (sym.dec_create) {
        m_dec_handle = sym.dec_create(m_param);
    }
    if (!m_dec_handle) {
        LOGE("ByteVC1LibLoader: create decoder failed, failed to create.");
        return false;
    }

    // 3. Allocate bitstream packet (opcode 0x002041)
    if (sym.alloc_packet) {
        m_packet = sym.alloc_packet();
    }
    if (!m_packet) {
        LOGE("%s", BinaryConstants::MSG_ALLOC_PACKET_FAIL);
        return false;
    }

    // 4. Allocate destination frame container
    if (sym.alloc_frame) {
        m_frame = sym.alloc_frame();
    }

    m_initialized = true;
    LOGI("[VideoDecoderByteVc1] Initialized successfully with dimensions %ux%u", width, height);
    return true;
}

bool VideoDecoderByteVc1::sendPacket(const uint8_t* bitstream_data, size_t size, int64_t pts) {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (!m_initialized || !m_packet || !bitstream_data || size == 0) return false;

    const auto& sym = ByteVC1LibLoader::getInstance().getSymbols();

    // Set bitstream payload into packet
    if (sym.set_packet_bs) {
        sym.set_packet_bs(m_packet, bitstream_data, size);
    }
    if (sym.set_packet_bs_len) {
        sym.set_packet_bs_len(m_packet, size);
    }

    // Send packet to decoder
    if (sym.send_packet) {
        int32_t ret = sym.send_packet(m_dec_handle, m_packet);
        return (ret == 0);
    }
    return true;
}

bool VideoDecoderByteVc1::decodeFrame() {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (!m_initialized || !m_dec_handle) return false;

    const auto& sym = ByteVC1LibLoader::getInstance().getSymbols();
    if (sym.dec_decode) {
        int32_t ret = sym.dec_decode(m_dec_handle, m_packet);
        return (ret == 0);
    }
    return true;
}

bool VideoDecoderByteVc1::receiveFrame(YUVFrameInfo& out_frame) {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (!m_initialized || !m_dec_handle || !m_frame) return false;

    const auto& sym = ByteVC1LibLoader::getInstance().getSymbols();

    int32_t got_frame = 0;
    if (sym.get_frame) {
        sym.get_frame(m_dec_handle, m_frame);
    }

    if (sym.get_frame_got_frame) {
        got_frame = sym.get_frame_got_frame(m_frame);
    } else if (sym.frame_got_frame) {
        got_frame = sym.frame_got_frame(m_frame);
    }

    if (!got_frame) {
        return false;
    }

    // Query frame properties
    uint32_t width = sym.get_frame_width ? sym.get_frame_width(m_frame) : m_width;
    uint32_t height = sym.get_frame_height ? sym.get_frame_height(m_frame) : m_height;
    int32_t pix_fmt = sym.get_frame_pix_fmt ? sym.get_frame_pix_fmt(m_frame) : 0;
    uint32_t bit_depth = sym.get_frame_bit_depth ? sym.get_frame_bit_depth(m_frame) : 8;

    out_frame.SetWidth(width);
    out_frame.SetHeight(height);
    out_frame.SetBitDepth(bit_depth);
    out_frame.SetYUVPixFmt(static_cast<YUVPixFmt>(pix_fmt));

    // Transfer planar data for Y, U, V
    for (uint32_t c = 0; c < 3; ++c) {
        uint32_t stride = sym.get_frame_stride ? sym.get_frame_stride(m_frame, c) : 0;
        out_frame.SetLineSize(c, stride);

        if (sym.get_frame_data) {
            const uint8_t* plane_data = sym.get_frame_data(m_frame, c);
            if (plane_data) {
                out_frame.UpdateChannelData(c, plane_data);
            }
        }
    }

    m_decoded_frames_count++;
    return true;
}

void VideoDecoderByteVc1::flush() {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_decoded_frames_count = 0;
}

bool VideoDecoderByteVc1::isHEVCFormat(const uint8_t* data, size_t size) {
    // Inspect Annex-B NAL unit headers for HEVC (H.265 / ByteVC1)
    // NAL unit type is in bits [1..6] of the first byte after the 3/4-byte start code
    if (!data || size < 6) return false;

    size_t offset = 0;
    if (data[0] == 0x00 && data[1] == 0x00) {
        if (data[2] == 0x01) offset = 3;
        else if (data[2] == 0x00 && data[3] == 0x01) offset = 4;
    }

    if (offset > 0 && offset + 1 < size) {
        uint8_t nal_byte0 = data[offset];
        uint8_t nal_type = (nal_byte0 >> 1) & 0x3F;
        // HEVC NAL types: VPS=32, SPS=33, PPS=34, IDR_W_RADL=19, IDR_N_LP=20, CRA=21
        if (nal_type == 32 || nal_type == 33 || nal_type == 34 || 
            nal_type == 19 || nal_type == 20 || nal_type == 21) {
            return true;
        }
    }
    return false;
}

bool VideoDecoderByteVc1::isSupportDecodeBySystem(uint32_t width, uint32_t height, uint32_t fps) {
    // Reconstructed from _ZNK4lynx6animax17VideoAssetAndroid23IsSupportDecodeBySystemEb
    // Checks standard limits for mobile hardware acceleration: 4K (3840x2160) @ 60fps
    if (width <= 3840 && height <= 2160 && fps <= 60) {
        return true;
    }
    return false;
}

} // namespace AnimaxByteVC1
} // namespace OpenCut
} // namespace NextAI
