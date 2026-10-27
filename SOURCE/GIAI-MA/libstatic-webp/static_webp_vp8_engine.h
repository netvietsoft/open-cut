// ============================================================================
// File: static_webp_vp8_engine.h
// Target: libstatic-webp.so (396,088 bytes)
// Description:
//   [EN] Clean-room C++17 declarations for WebPDecode (0x028c94),
//        WebPGetFeaturesInternal (0x028238), VP8/VP8L decoder & ARM64 NEON DSP,
//        and FDEs 470..700.
//   [VN] Khai báo C++17 sạch cho WebPDecode (0x028c94), WebPGetFeaturesInternal (0x028238),
//        bộ giải mã VP8/VP8L, các hàm DSP ARM64 NEON và FDE 470..700.
// ============================================================================

#pragma once

#include "static_webp_types.h"

namespace facebook {
namespace imagepipeline {
namespace webp {
namespace vp8 {

VP8StatusCode WebPDecodeCleanRoom(
    const uint8_t* data,
    size_t data_size,
    WebPDecoderConfig* config) noexcept;

uint64_t DispatchVp8EngineFdeRange(uint32_t fde_index, uint64_t x0, uint64_t x1, uint64_t x2) noexcept;

} // namespace vp8
} // namespace webp
} // namespace imagepipeline
} // namespace facebook
