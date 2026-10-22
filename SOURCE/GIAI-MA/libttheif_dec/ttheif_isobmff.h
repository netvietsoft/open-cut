/**
 * @file ttheif_isobmff.h
 * @brief ISO Base Media File Format (ISO/IEC 14496-12 & 23008-12) Container Parser
 *        Bộ phân tích định dạng tệp cơ sở phương tiện ISO (ISOBMFF)
 *
 * Implements box tree traversal, item location mapping, and spatial property extraction.
 * Thực thi duyệt cây Box, ánh xạ vị trí phần tử và trích xuất thuộc tính không gian ảnh.
 */

#ifndef TTHEIF_ISOBMFF_H
#define TTHEIF_ISOBMFF_H

#include "ttheif_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @struct isobmff_box_header_t
 * @brief 4-byte size + 4-byte fourcc header
 *        Tiêu đề Box 8 bytes theo chuẩn ISOBMFF
 */
typedef struct isobmff_box_header {
    uint32_t size;
    uint32_t type;
    uint64_t largesize;
    size_t header_size;
} isobmff_box_header_t;

/**
 * @struct isobmff_item_t
 * @brief Descriptor of an image item in ISOBMFF
 *        Bộ mô tả một phần tử ảnh trong container ISOBMFF
 */
typedef struct isobmff_item {
    uint32_t item_id;
    uint32_t item_type;      ///< FourCC: 'hvc1', 'vvc1', 'Exif', 'mime'
    uint64_t offset;         ///< Absolute file offset of payload / Offset tuyệt đối
    uint64_t length;         ///< Payload byte length / Độ dài byte
    uint32_t width;          ///< From 'ispe' property / Chiều rộng từ ispe
    uint32_t height;         ///< From 'ispe' property / Chiều cao từ ispe
    bool is_primary;         ///< Whether item is primary item from 'pitm'
    bool is_thumbnail;       ///< Whether item is thumbnail from 'thmb'
    uint32_t ref_item_id;    ///< Target referenced item id
} isobmff_item_t;

/**
 * @struct isobmff_parser_ctx_t
 * @brief Context for ISOBMFF parser session
 *        Ngữ cảnh phiên phân tích ISOBMFF
 */
typedef struct isobmff_parser_ctx {
    const uint8_t* buffer;
    size_t buffer_size;
    size_t cursor;
    uint32_t major_brand;
    uint32_t minor_version;
    uint32_t compatible_brands[16];
    size_t compatible_brand_count;
    uint32_t primary_item_id;
    isobmff_item_t items[32];
    size_t item_count;
    uint64_t mdat_offset;
    uint64_t mdat_size;
} isobmff_parser_ctx_t;

/**
 * @brief Initialize ISOBMFF parser with input data buffer
 *        Khởi tạo bộ phân tích ISOBMFF với vùng đệm dữ liệu đầu vào
 */
int isobmff_parser_init(isobmff_parser_ctx_t* ctx, const uint8_t* data, size_t size);

/**
 * @brief Parse top-level boxes and build item registry
 *        Phân tích các hộp cấp cao nhất và xây dựng sổ đăng ký phần tử
 */
int isobmff_parse_container(isobmff_parser_ctx_t* ctx);

/**
 * @brief Find primary image item in container
 *        Tìm phần tử ảnh chính trong container
 */
const isobmff_item_t* isobmff_get_primary_item(const isobmff_parser_ctx_t* ctx);

/**
 * @brief Find thumbnail image item in container
 *        Tìm phần tử ảnh thu nhỏ (thumbnail) trong container
 */
const isobmff_item_t* isobmff_get_thumbnail_item(const isobmff_parser_ctx_t* ctx);

/**
 * @brief Find EXIF metadata item in container
 *        Tìm phần tử siêu dữ liệu EXIF trong container
 */
const isobmff_item_t* isobmff_get_exif_item(const isobmff_parser_ctx_t* ctx);

#ifdef __cplusplus
}
#endif

#endif // TTHEIF_ISOBMFF_H