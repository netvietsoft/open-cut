/**
 * @file ttheif_exif.cpp
 * @brief EXIF Orientation Metadata Extraction Implementation
 *        Triển khai trích xuất siêu dữ liệu hướng xoay EXIF
 *
 * Cleanroom implementation reconstructed from ByteDance libttheif_dec.so (AArch64).
 * Tái cấu trúc phòng sạch từ libttheif_dec.so (AArch64) của ByteDance.
 */

#include "ttheif_exif.h"
#include <string.h>

int heif_get_orientation_from_exif(const uint8_t* exif_data, size_t exif_len) {
    if (!exif_data || exif_len < 14) {
        return EXIF_ORIENTATION_NORMAL; // Default 1
    }

    size_t cursor = 0;

    // Check for "Exif\0\0" preamble if present / Kiểm tra tiền tố "Exif\0\0"
    if (exif_len >= 6 && memcmp(exif_data, "Exif\0\0", 6) == 0) {
        cursor += 6;
    }

    if (cursor + 8 > exif_len) return EXIF_ORIENTATION_NORMAL;

    const uint8_t* tiff_hdr = exif_data + cursor;
    bool is_le = false;

    if (tiff_hdr[0] == 'I' && tiff_hdr[1] == 'I') {
        is_le = true;
    } else if (tiff_hdr[0] == 'M' && tiff_hdr[1] == 'M') {
        is_le = false;
    } else {
        return EXIF_ORIENTATION_NORMAL;
    }

    // Verify TIFF magic number 42 / Xác minh số ma thuật 42 của TIFF
    uint16_t magic = is_le ? ((uint16_t)tiff_hdr[2] | ((uint16_t)tiff_hdr[3] << 8))
                           : (((uint16_t)tiff_hdr[2] << 8) | (uint16_t)tiff_hdr[3]);
    if (magic != 42) return EXIF_ORIENTATION_NORMAL;

    // Read offset to IFD0 / Đọc offset tới IFD0
    uint32_t ifd_offset = is_le ? ((uint32_t)tiff_hdr[4] | ((uint32_t)tiff_hdr[5] << 8) |
                                   ((uint32_t)tiff_hdr[6] << 16) | ((uint32_t)tiff_hdr[7] << 24))
                                : (((uint32_t)tiff_hdr[4] << 24) | ((uint32_t)tiff_hdr[5] << 16) |
                                   ((uint32_t)tiff_hdr[6] << 8) | (uint32_t)tiff_hdr[7]);

    size_t ifd_pos = cursor + ifd_offset;
    if (ifd_pos + 2 > exif_len) return EXIF_ORIENTATION_NORMAL;

    const uint8_t* p_ifd = exif_data + ifd_pos;
    uint16_t num_entries = is_le ? ((uint16_t)p_ifd[0] | ((uint16_t)p_ifd[1] << 8))
                                 : (((uint16_t)p_ifd[0] << 8) | (uint16_t)p_ifd[1]);

    size_t entry_cursor = ifd_pos + 2;
    for (uint16_t i = 0; i < num_entries && entry_cursor + 12 <= exif_len; ++i) {
        const uint8_t* entry = exif_data + entry_cursor;
        uint16_t tag = is_le ? ((uint16_t)entry[0] | ((uint16_t)entry[1] << 8))
                             : (((uint16_t)entry[0] << 8) | (uint16_t)entry[1]);

        if (tag == 0x0112) { // Orientation Tag / Thẻ chiều xoay
            uint16_t orientation = is_le ? ((uint16_t)entry[8] | ((uint16_t)entry[9] << 8))
                                         : (((uint16_t)entry[8] << 8) | (uint16_t)entry[9]);
            if (orientation >= 1 && orientation <= 8) {
                return (int)orientation;
            }
        }
        entry_cursor += 12;
    }

    return EXIF_ORIENTATION_NORMAL;
}
