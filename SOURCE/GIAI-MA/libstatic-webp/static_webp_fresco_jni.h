// ============================================================================
// File: static_webp_fresco_jni.h
// Target: libstatic-webp.so (396,088 bytes)
// Description:
//   [EN] Clean-room C++17 declarations for Fresco JNI_OnLoad (0x004ac0),
//        WebpBitmapFactoryImpl, WebpTranscoderImpl, WebPImage, WebPFrame,
//        and FDEs 0..239.
//   [VN] Khai báo C++17 sạch cho Fresco JNI_OnLoad (0x004ac0),
//        WebpBitmapFactoryImpl, WebpTranscoderImpl, WebPImage, WebPFrame và FDE 0..239.
// ============================================================================

#pragma once

#include "static_webp_types.h"

namespace facebook {
namespace imagepipeline {
namespace webp {
namespace jni {

bool ConfigureBitmapWebPDecBuffer(
    int32_t preferred_config_native_int,
    int32_t width,
    int32_t height,
    uint8_t* locked_pixels,
    WebPDecoderConfig* out_config) noexcept;

bool ValidateJpegQualityBounds(int32_t quality) noexcept;
bool ValidateScaleNumeratorBounds(int32_t scale_numerator) noexcept;

uint64_t DispatchFrescoJniFdeRange(uint32_t fde_index, uint64_t x0, uint64_t x1, uint64_t x2) noexcept;

} // namespace jni
} // namespace webp
} // namespace imagepipeline
} // namespace facebook
