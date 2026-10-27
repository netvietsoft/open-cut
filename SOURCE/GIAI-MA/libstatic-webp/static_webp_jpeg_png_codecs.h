// ============================================================================
// File: static_webp_jpeg_png_codecs.h
// Target: libstatic-webp.so (396,088 bytes)
// Description:
//   [EN] Clean-room C++17 declarations for embedded libjpeg-turbo 1.5.3 (build 20180808)
//        and libpng 1.6.37 transcode pipelines and FDEs 240..469.
//   [VN] Khai báo C++17 sạch cho pipeline chuyển mã libjpeg-turbo 1.5.3 và libpng 1.6.37.
// ============================================================================

#pragma once

#include "static_webp_types.h"

namespace facebook {
namespace imagepipeline {
namespace webp {
namespace codecs {

bool TranscodeRgbScanlinesToJpeg(
    const uint8_t* rgb_pixels,
    int32_t width,
    int32_t height,
    int32_t stride,
    int32_t quality,
    uint64_t* out_digest) noexcept;

bool TranscodeRgbaScanlinesToPng(
    const uint8_t* rgba_pixels,
    int32_t width,
    int32_t height,
    int32_t stride,
    uint64_t* out_digest) noexcept;

uint64_t DispatchJpegPngCodecsFdeRange(uint32_t fde_index, uint64_t x0, uint64_t x1, uint64_t x2) noexcept;

} // namespace codecs
} // namespace webp
} // namespace imagepipeline
} // namespace facebook
