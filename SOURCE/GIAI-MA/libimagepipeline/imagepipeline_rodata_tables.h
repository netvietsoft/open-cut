/**
 * @file imagepipeline_rodata_tables.h
 * @brief Clean-Room C++17 Declarations for libimagepipeline.so .rodata, .data.rel.ro & .data Tables
 *        Khai báo C++17 cho các bảng hằng số .rodata (0x037820..0x03a8ca), .data.rel.ro (0x043768..0x043b70)
 *        và .data (0x044000..0x0440f0) của libimagepipeline.so
 */

#ifndef NEXTAI_OPENCUT_IMAGEPIPELINE_RODATA_TABLES_H_
#define NEXTAI_OPENCUT_IMAGEPIPELINE_RODATA_TABLES_H_

#include "imagepipeline_types.h"

namespace nextai {
namespace opencut {
namespace imagepipeline {

/// 8-entry Exif orientation (1..8) -> FrescoRotationType lookup table (.rodata 0x037c00..0x037c20).
/// Bảng ánh xạ hướng Exif (1..8) sang FrescoRotationType tại .rodata 0x037c00..0x037c20.
extern const uint32_t kFrescoExifToRotationTable[8];

/// 7-entry FrescoRotationType (1..7) -> JXFORM_CODE lookup table (.rodata 0x037b28..0x037b44).
/// Bảng ánh xạ FrescoRotationType (1..7) sang JXFORM_CODE tại .rodata 0x037b28..0x037b44.
extern const JXFORM_CODE kFrescoRotationToJxformTable[7];

/// 2-byte static JPEG EOI marker {0xFF, 0xD9} at .rodata 0x037b44 used by JpegMemorySourceWrapper (0x002af0).
/// Dấu kết thúc ảnh JPEG tĩnh 2 byte {0xFF, 0xD9} tại .rodata 0x037b44.
extern const uint8_t kJpegStaticEoiMarker[2];

/// 64-entry standard Annex K luminance quantization table (.rodata 0x037ea8..0x037fa8).
/// Bảng lượng tử hóa độ chói chuẩn Annex K 64 phần tử tại .rodata 0x037ea8..0x037fa8.
extern const uint32_t kStdLuminanceQuantTbl[64];

/// 64-entry standard Annex K chrominance quantization table (.rodata 0x037fa8..0x0380a8).
/// Bảng lượng tử hóa sắc độ chuẩn Annex K 64 phần tử tại .rodata 0x037fa8..0x0380a8.
extern const uint32_t kStdChrominanceQuantTbl[64];

/// 80-entry zigzag natural order table `jpeg_natural_order` (.rodata 0x038270).
/// Bảng thứ tự zíc-zắc tự nhiên `jpeg_natural_order` 80 phần tử tại .rodata 0x038270.
extern const int32_t kJpegNaturalOrder[80];

/// 129-entry standard libjpeg error/trace message table (.data.rel.ro 0x043768..0x043b68).
/// Bảng 129 thông báo lỗi/vết chuẩn của libjpeg-turbo tại .data.rel.ro 0x043768..0x043b68.
extern const char* const kJpegStdMessageTable[kJpegStdMessageCount];

/// 10-entry JNI registration metadata table (.data 0x044000..0x0440f0).
/// Bảng 10 mục đăng ký phương thức gốc JNI tại .data 0x044000..0x0440f0.
extern const ImagePipelineJniRegRecord kImagePipelineJniMethodTable[10];

/// 393-entry .eh_frame function descriptor table (.text 0x001ffc..0x037814).
/// Bảng 393 hàm trong .text trích xuất từ .eh_frame_hdr (0x03a8cc).
extern const ImagePipelineFdeEntry kImagePipelineFdeTable[kImagePipelineFdeFunctionCount];

} // namespace imagepipeline
} // namespace opencut
} // namespace nextai

#endif // NEXTAI_OPENCUT_IMAGEPIPELINE_RODATA_TABLES_H_
