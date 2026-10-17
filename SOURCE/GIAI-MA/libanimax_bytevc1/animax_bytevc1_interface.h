// ==============================================================================
// NextAI OpenCut - Reconstructed Media & Animation Engine
// Target Library: libanimax_bytevc1.so (lynx::animax & libByteVC1_dec.so)
// Component: Master Cleanroom Engine & Verification Interface
// Language: C++17 / Native Android NDK
// Bilingual Documentation: English & Vietnamese (Song ngữ Anh - Việt)
// ==============================================================================

#ifndef NEXTAI_OPENCUT_ANIMAX_BYTEVC1_INTERFACE_H
#define NEXTAI_OPENCUT_ANIMAX_BYTEVC1_INTERFACE_H

#include "animax_bytevc1_types.h"
#include "animax_bytevc1_loader.h"
#include "animax_bytevc1_decoder.h"
#include "animax_yuv_frame.h"
#include "animax_bytevc1_jni.h"
#include <string>
#include <vector>
#include <memory>

namespace NextAI {
namespace OpenCut {
namespace AnimaxByteVC1 {

/**
 * @brief Self-test stage execution details.
 * Chi tiết kết quả thực thi từng giai đoạn tự kiểm thử.
 */
struct SelfTestResult {
    bool passed{false};
    size_t tests_run{0};
    size_t tests_passed{0};
    std::string summary;
    std::vector<std::string> stage_details;
};

/**
 * @brief Master Cleanroom Engine for Animax ByteVC1 Video Decoder.
 * Động cơ sạch master cho bộ giải mã video Animax ByteVC1.
 */
class AnimaxByteVC1Engine {
public:
    AnimaxByteVC1Engine();
    ~AnimaxByteVC1Engine() = default;

    /**
     * @brief Initialize engine and dependencies.
     */
    bool initialize();

    /**
     * @brief Run 7-stage comprehensive self-test suite.
     * Chạy chuỗi tự kiểm thử toàn diện 7 giai đoạn.
     */
    SelfTestResult runSelfTest();

    /**
     * @brief Create a decoder instance for Lynx AnimaX playback.
     */
    std::unique_ptr<VideoDecoderByteVc1> createDecoder();

    /**
     * @brief Check whether engine is initialized and ready.
     */
    bool isReady() const { return m_initialized; }

private:
    bool m_initialized{false};
};

} // namespace AnimaxByteVC1
} // namespace OpenCut
} // namespace NextAI

#endif // NEXTAI_OPENCUT_ANIMAX_BYTEVC1_INTERFACE_H
