// ==============================================================================
// NextAI OpenCut - Reconstructed Media & Animation Engine
// Target Library: libanimax_bytevc1.so (lynx::animax & libByteVC1_dec.so)
// Component: VideoDecoderByteVc1 Implementation (video_decoder_bytevc1.cc)
// Language: C++17 / Native Android NDK
// Bilingual Documentation: English & Vietnamese (Song ngữ Anh - Việt)
// ==============================================================================

#ifndef NEXTAI_OPENCUT_ANIMAX_BYTEVC1_DECODER_H
#define NEXTAI_OPENCUT_ANIMAX_BYTEVC1_DECODER_H

#include "animax_bytevc1_types.h"
#include "animax_bytevc1_loader.h"
#include "animax_yuv_frame.h"
#include <vector>
#include <memory>
#include <mutex>

namespace NextAI {
namespace OpenCut {
namespace AnimaxByteVC1 {

/**
 * @brief Video Decoder implementation for ByteDance ByteVC1 / HEVC.
 * Triển khai bộ giải mã video ByteDance ByteVC1 / HEVC cho Lynx AnimaX.
 * 
 * Reconstructed from:
 * - video_decoder_bytevc1.cc
 * - _ZN4lynx6animax17VideoPlayerCustomC1ENSt6__ndk110unique_ptrINS0_18VideoDecoderCustomENS2_14default_deleteIS4_EEEE
 * - _ZNK4lynx6animax17VideoAssetAndroid12IsHEVCFormatEv
 * - _ZNK4lynx6animax17VideoAssetAndroid23IsSupportDecodeBySystemEb
 */
class VideoDecoderByteVc1 {
public:
    VideoDecoderByteVc1();
    ~VideoDecoderByteVc1();

    /**
     * @brief Initialize decoder instance and parameters.
     * Khởi tạo thực thể giải mã và các tham số cấu hình.
     */
    bool init(uint32_t width = 1920, uint32_t height = 1080);

    /**
     * @brief Feed a compressed bitstream packet (NAL unit) into the decoder.
     * Nạp một gói dữ liệu nén bitstream (NAL unit) vào bộ giải mã.
     */
    bool sendPacket(const uint8_t* bitstream_data, size_t size, int64_t pts = 0);

    /**
     * @brief Execute decode step on current packet.
     * Thực hiện bước giải mã trên gói tin hiện tại.
     */
    bool decodeFrame();

    /**
     * @brief Retrieve decoded frame and convert into Lynx AnimaX YUVFrameInfo.
     * Lấy khung hình đã giải mã và đóng gói vào YUVFrameInfo của Lynx AnimaX.
     */
    bool receiveFrame(YUVFrameInfo& out_frame);

    /**
     * @brief Flush internal frame queues and reset decoder state.
     * Xả sạch hàng đợi khung hình nội bộ và đặt lại trạng thái giải mã.
     */
    void flush();

    /**
     * @brief Check whether input stream is HEVC / ByteVC1 format.
     * Kiểm tra xem luồng đầu vào có định dạng HEVC / ByteVC1 hay không.
     */
    static bool isHEVCFormat(const uint8_t* data, size_t size);

    /**
     * @brief Query whether system hardware decoder supports this stream.
     * Truy vấn xem phần cứng hệ thống có hỗ trợ giải mã luồng này không.
     */
    static bool isSupportDecodeBySystem(uint32_t width, uint32_t height, uint32_t fps);

    /**
     * @brief Get decoded frame counter.
     * Lấy bộ đếm số khung hình đã giải mã thành công.
     */
    size_t getDecodedFrameCount() const { return m_decoded_frames_count; }

private:
    void releaseResources();

    std::mutex m_mutex;
    ByteVC1Handle m_dec_handle{nullptr};
    ByteVC1Param m_param{nullptr};
    ByteVC1Packet m_packet{nullptr};
    ByteVC1Frame m_frame{nullptr};

    uint32_t m_width{0};
    uint32_t m_height{0};
    size_t m_decoded_frames_count{0};
    bool m_initialized{false};
};

} // namespace AnimaxByteVC1
} // namespace OpenCut
} // namespace NextAI

#endif // NEXTAI_OPENCUT_ANIMAX_BYTEVC1_DECODER_H
