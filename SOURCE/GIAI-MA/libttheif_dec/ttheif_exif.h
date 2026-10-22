/**
 * @file ttheif_exif.h
 * @brief EXIF Orientation Metadata Extraction Header
 *        Tiêu đề trích xuất siêu dữ liệu hướng xoay EXIF
 *
 * Implements TIFF IFD0 parsing for Tag 0x0112 (Orientation).
 * Triển khai phân tích TIFF IFD0 cho Thẻ 0x0112 (Chiều xoay).
 */

#ifndef TTHEIF_EXIF_H
#define TTHEIF_EXIF_H

#include "ttheif_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Extract EXIF orientation integer (1..8) from raw EXIF payload
 *        Trích xuất giá trị nguyên hướng xoay EXIF (1..8) từ dữ liệu EXIF thô
 * @param exif_data Pointer to EXIF payload bytes / Con trỏ khối byte EXIF
 * @param exif_len Length of EXIF payload / Độ dài khối EXIF
 * @return Orientation value (1..8) or 1 (normal) if not found / Chiều xoay hoặc 1 nếu không có
 */
int heif_get_orientation_from_exif(const uint8_t* exif_data, size_t exif_len);

#ifdef __cplusplus
}
#endif

#endif // TTHEIF_EXIF_H