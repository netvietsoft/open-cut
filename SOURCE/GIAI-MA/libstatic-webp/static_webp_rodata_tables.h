// ============================================================================
// File: static_webp_rodata_tables.h
// Target: libstatic-webp.so (396,088 bytes)
// Description:
//   [EN] Read-only constants (.rodata 0x04fac0..0x055ae5), .data (0x064000..0x064328)
//        27 JNINativeMethod descriptors, and 701 FDE function addresses.
//   [VN] Bảng hằng số chỉ đọc (.rodata 0x04fac0..0x055ae5), 27 mục JNINativeMethod
//        trong .data (0x064000..0x064328) và 701 địa chỉ hàm FDE.
// ============================================================================

#pragma once

#include "static_webp_types.h"

namespace facebook {
namespace imagepipeline {
namespace webp {
namespace rodata {

// [EN] Packed (input_components=3, in_color_space=JCS_RGB=2) @ .rodata 0x04ff68 (loaded at 0x005820)
// [VN] Cặp hằng số đóng gói (input_components=3, in_color_space=JCS_RGB=2) tại .rodata 0x04ff68
constexpr uint64_t kJpegRgbComponentsAndColorspace = 0x0000000200000003ULL;

// [EN] libjpeg-turbo struct size & version checked at 0x0057f4..0x0057f8
// [VN] Kích thước cấu trúc và phiên bản libjpeg-turbo kiểm tra tại 0x0057f4..0x0057f8
constexpr int32_t kJpegLibVersion = 80;              // 0x50
constexpr size_t kJpegCompressStructSize = 0x248U;   // 584 bytes

struct RodataStringEntry {
    uint32_t va;
    const char* text;
};

struct DataJniMethodDescriptor {
    uint32_t table_va;
    uint32_t name_va;
    const char* name;
    uint32_t sig_va;
    const char* signature;
    uint32_t fn_va;
};

extern const DataJniMethodDescriptor kWebpBitmapFactoryJniMethods_064000[3];
extern const DataJniMethodDescriptor kWebpTranscoderJniMethods_064050[2];
extern const DataJniMethodDescriptor kWebPImageJniMethods_064080[12];
extern const DataJniMethodDescriptor kWebPFrameJniMethods_0641a0[10];

extern const RodataStringEntry kRodataStringTable[];
extern const size_t kRodataStringTableCount;
extern const uint32_t kFdeFunctionStartTable[701];

const char* LookupRodataString(uint32_t va) noexcept;

} // namespace rodata
} // namespace webp
} // namespace imagepipeline
} // namespace facebook
