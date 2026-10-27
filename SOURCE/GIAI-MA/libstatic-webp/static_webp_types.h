// ============================================================================
// File: static_webp_types.h
// Target: libstatic-webp.so (396,088 bytes, SHA-256: 757a3d4beac3a14fd300c3b74605f3c7e5e80cc1048e3183ec46cb2931b64415)
// Task ID: TASK-139-RECONSTRUCTION-LIBSTATIC-WEBP / TASK_SO_035_libstatic_webp
// Description:
//   [EN] Clean-room C++17 type definitions, WebPDecoderConfig/VP8StatusCode ABI
//        layouts, JNINativeMethod tables (.data 0x064000..0x064290), and JNI_OnLoad
//        declarations for Facebook Fresco Static-WebP + libwebp + libjpeg-turbo + libpng.
//   [VN] Định nghĩa kiểu dữ liệu C++17 sạch, bố cục ABI WebPDecoderConfig/VP8StatusCode,
//        bảng JNINativeMethod (.data 0x064000..0x064290) và khai báo JNI_OnLoad.
// ============================================================================

#pragma once

#include <cstdint>
#include <cstddef>

#ifndef JNI_VERSION_1_6
typedef uint8_t jboolean;
typedef int8_t jbyte;
typedef uint16_t jchar;
typedef int16_t jshort;
typedef int32_t jint;
typedef int64_t jlong;
typedef float jfloat;
typedef double jdouble;
typedef jint jsize;
struct _jobject;
typedef _jobject* jobject;
typedef jobject jclass;
typedef jobject jstring;
typedef jobject jarray;
typedef jobject jobjectArray;
typedef jobject jbyteArray;
typedef jobject jintArray;
struct _jmethodID;
typedef _jmethodID* jmethodID;
struct _jfieldID;
typedef _jfieldID* jfieldID;

struct JNINativeMethod {
    const char* name;
    const char* signature;
    void* fnPtr;
};

struct _JNIEnv {
    const void* functions;
};
typedef _JNIEnv JNIEnv;

struct _JavaVM {
    const void* functions;
};
typedef _JavaVM JavaVM;
#define JNI_VERSION_1_6 0x00010006
#define JNI_TRUE 1
#define JNI_FALSE 0
#endif

namespace facebook {
namespace imagepipeline {
namespace webp {

// ============================================================================
// [EN] VP8StatusCode & WEBP_CSP_MODE enumerations (matching 0x0049b0, 0x0049cc, 0x028d04)
// [VN] Kiểu liệt kê VP8StatusCode & WEBP_CSP_MODE (khớp mã máy tại 0x0049b0, 0x0049cc, 0x028d04)
// ============================================================================
enum VP8StatusCode : int32_t {
    VP8_STATUS_OK = 0,
    VP8_STATUS_OUT_OF_MEMORY = 1,
    VP8_STATUS_INVALID_PARAM = 2,   // 0x028d14: mov w22, #2
    VP8_STATUS_BITSTREAM_ERROR = 3, // 0x028d0c: mov w22, #3 (mapped from 7 @ 0x028d04)
    VP8_STATUS_UNSUPPORTED_FEATURE = 4,
    VP8_STATUS_SUSPENDED = 5,
    VP8_STATUS_USER_ABORT = 6,
    VP8_STATUS_NOT_ENOUGH_DATA = 7
};

enum WEBP_CSP_MODE : int32_t {
    MODE_RGB = 0,
    MODE_RGBA = 1,
    MODE_BGR = 2,
    MODE_BGRA = 3,
    MODE_ARGB = 4,
    MODE_RGBA_4444 = 5,
    MODE_RGB_565 = 6, // 0x0049b0: mov w8, #6 (stride = width << 1 @ 0x0049bc)
    MODE_rgbA = 7,    // 0x0049cc: mov w8, #7 (stride = width << 2 @ 0x0049d4)
    MODE_bgrA = 8,
    MODE_Argb = 9,
    MODE_rgbA_4444 = 10,
    MODE_YUV = 11,
    MODE_YUVA = 12,
    MODE_LAST = 13
};

// ============================================================================
// [EN] WebPBitstreamFeatures (40 bytes = 0x28, zeroed at 0x028cc8..0x028cf4)
// [VN] Cấu trúc WebPBitstreamFeatures (40 byte = 0x28, xóa về 0 tại 0x028cc8..0x028cf4)
// ============================================================================
struct WebPBitstreamFeatures {
    int32_t width;          // +0x00
    int32_t height;         // +0x04
    int32_t has_alpha;      // +0x08
    int32_t has_animation;  // +0x0c
    int32_t format;         // +0x10 (0=undefined/mixed, 1=lossy, 2=lossless)
    uint32_t pad[5];        // +0x14..+0x27
};

// ============================================================================
// [EN] WebPDecBuffer (120 bytes = 0x78, embedded at WebPDecoderConfig + 0x28)
//      Matches stack offsets in createBitmapDecode (0x0049b0..0x0049fc, config @ sp+0x18):
//        config.output.colorspace         @ sp+0x40 (config + 0x28)
//        config.output.width              @ sp+0x44 (config + 0x2c)
//        config.output.height             @ sp+0x48 (config + 0x30)
//        config.output.is_external_memory @ sp+0x4c (config + 0x34)
//        config.output.u.RGBA.rgba        @ sp+0x50 (config + 0x38)
//        config.output.u.RGBA.stride      @ sp+0x58 (config + 0x40)
//        config.output.u.RGBA.size        @ sp+0x60 (config + 0x48)
// [VN] Cấu trúc bộ đệm giải mã WebPDecBuffer (120 byte = 0x78, tại WebPDecoderConfig + 0x28).
// ============================================================================
struct WebPRGBABuffer {
    uint8_t* rgba;          // +0x10 (config + 0x38)
    int32_t stride;         // +0x18 (config + 0x40)
    int32_t pad_stride;     // +0x1c
    size_t size;            // +0x20 (config + 0x48)
};

struct WebPDecBuffer {
    WEBP_CSP_MODE colorspace;       // +0x00 (config + 0x28)
    int32_t width;                  // +0x04 (config + 0x2c)
    int32_t height;                 // +0x08 (config + 0x30)
    int32_t is_external_memory;     // +0x0c (config + 0x34)
    WebPRGBABuffer rgba_buf;        // +0x10..+0x27
    uint8_t yuva_or_pad[64];        // +0x28..+0x67
    uint32_t pad[2];                // +0x68..+0x6f
    uint8_t* private_memory;        // +0x70 (config + 0x98)
};

struct WebPDecoderOptions {
    int32_t bypass_filtering;           // +0x00 (config + 0xa0)
    int32_t no_fancy_upsampling;        // +0x04
    int32_t use_cropping;               // +0x08
    int32_t crop_left;                  // +0x0c
    int32_t crop_top;                   // +0x10
    int32_t crop_width;                 // +0x14
    int32_t crop_height;                // +0x18
    int32_t use_scaling;                // +0x1c
    int32_t scaled_width;               // +0x20
    int32_t scaled_height;              // +0x24
    int32_t use_threads;                // +0x28
    int32_t dithering_strength;         // +0x2c
    int32_t flip;                       // +0x30
    int32_t alpha_dithering_strength;   // +0x34
    uint32_t pad[5];                    // +0x38..+0x4b
};

struct WebPDecoderConfig {
    WebPBitstreamFeatures input;    // +0x00 (40 B)
    WebPDecBuffer output;           // +0x28 (120 B)
    WebPDecoderOptions options;     // +0xa0 (76 B)
};

} // namespace webp
} // namespace imagepipeline
} // namespace facebook

extern "C" {
jint JNI_OnLoad(JavaVM* vm, void* reserved);
}
