/**
 * @file ttheif_types.h
 * @brief ByteDance HEIF / VVIF Image & Animation Decoder Core Type Definitions
 *        Định nghĩa kiểu dữ liệu lõi cho bộ giải mã ảnh và hoạt ảnh HEIF/VVIF của ByteDance
 *
 * Cleanroom implementation reconstructed from ByteDance libttheif_dec.so (AArch64).
 * Tái cấu trúc phòng sạch từ libttheif_dec.so (AArch64) của ByteDance.
 */

#ifndef TTHEIF_TYPES_H
#define TTHEIF_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// Version String / Chuỗi phiên bản
#define TTHEIF_DEC_VERSION_STRING "ttheif_dec version 1.2.0-rc.3"

// FourCC Box Types / Các kiểu hộp FourCC trong chuẩn ISO-BMFF
#define FOURCC_FTYP 0x66747970 // 'ftyp'
#define FOURCC_META 0x6d657461 // 'meta'
#define FOURCC_HDLR 0x68646c72 // 'hdlr'
#define FOURCC_PITM 0x7069746d // 'pitm'
#define FOURCC_ILOC 0x696c6f63 // 'iloc'
#define FOURCC_IINF 0x69696e66 // 'iinf'
#define FOURCC_INFE 0x696e6665 // 'infe'
#define FOURCC_IPRP 0x69707270 // 'iprp'
#define FOURCC_IPCO 0x6970636f // 'ipco'
#define FOURCC_ISPE 0x69737065 // 'ispe'
#define FOURCC_COLR 0x636f6c72 // 'colr'
#define FOURCC_THMB 0x74686d62 // 'thmb'
#define FOURCC_MDAT 0x6d646174 // 'mdat'
#define FOURCC_IDAT 0x69646174 // 'idat'
#define FOURCC_IREF 0x69726566 // 'iref'
#define FOURCC_HVCC 0x68766343 // 'hvcC'
#define FOURCC_VVCC 0x76766343 // 'vvcC'

// Brand Identifiers / Các định danh Brand
#define BRAND_HEIC 0x68656963 // 'heic'
#define BRAND_HEIX 0x68656978 // 'heix'
#define BRAND_HEVC 0x68657663 // 'hevc'
#define BRAND_MIF1 0x6d696631 // 'mif1'
#define BRAND_MSF1 0x6d736631 // 'msf1'
#define BRAND_VVIF 0x76766966 // 'vvif'
#define BRAND_VVS1 0x76767331 // 'vvs1'

// File Types / Phân loại kiểu tệp
typedef enum {
    HEIF_TYPE_UNKNOWN   = 0,
    HEIF_TYPE_HEIC      = 1, ///< ISO/IEC 23008-12 HEIC (H.265 / ByteVC1)
    HEIF_TYPE_HEIF_ANIM = 2, ///< Animated HEIF sequence (msf1)
    HEIF_TYPE_VVIF      = 3, ///< Versatile Video Image Format (H.266 / ByteVC2)
    HEIF_TYPE_VVIF_ANIM = 4  ///< Animated VVIF sequence (vvs1)
} heif_file_type_t;

// Color Formats / Các định dạng không gian màu đầu ra
typedef enum {
    HEIF_COLOR_RGBA8888 = 0, ///< 32-bit RGBA (R, G, B, A)
    HEIF_COLOR_RGB888   = 1, ///< 24-bit RGB (R, G, B)
    HEIF_COLOR_RGB565   = 2, ///< 16-bit RGB 5-6-5
    HEIF_COLOR_YUV420P  = 3  ///< Planar YUV 4:2:0 (Y plane + U plane + V plane)
} heif_color_format_t;

// EXIF Orientation Constants / Hằng số chiều xoay EXIF
typedef enum {
    EXIF_ORIENTATION_NORMAL              = 1, ///< Top-left (0 deg)
    EXIF_ORIENTATION_FLIP_HORIZONTAL     = 2, ///< Top-right (flip horizontal)
    EXIF_ORIENTATION_ROTATE_180          = 3, ///< Bottom-right (rotate 180 deg)
    EXIF_ORIENTATION_FLIP_VERTICAL       = 4, ///< Bottom-left (flip vertical)
    EXIF_ORIENTATION_TRANSPOSE           = 5, ///< Left-top (transpose)
    EXIF_ORIENTATION_ROTATE_90           = 6, ///< Right-top (rotate 90 deg CW)
    EXIF_ORIENTATION_TRANSVERSE          = 7, ///< Right-bottom (transverse)
    EXIF_ORIENTATION_ROTATE_270          = 8  ///< Left-bottom (rotate 270 deg CW)
} exif_orientation_t;

// Error Codes / Mã lỗi giải mã
#define HEIF_DEC_OK               0
#define HEIF_DEC_ERR_INVALID_PARAM -1
#define HEIF_DEC_ERR_INVALID_FORMAT -2
#define HEIF_DEC_ERR_PARSE_BOX    -3
#define HEIF_DEC_ERR_NO_IMAGE     -4
#define HEIF_DEC_ERR_DECODE_FAIL  -5
#define HEIF_DEC_ERR_OUT_OF_MEM   -6
#define HEIF_DEC_ERR_UNSUPPORTED  -7

/**
 * @struct heif_image_meta_t
 * @brief Metadata parsed from HEIF / VVIF container
 *        Siêu dữ liệu bóc tách từ container HEIF / VVIF
 */
typedef struct heif_image_meta {
    uint32_t width;             ///< Image width in pixels / Chiều rộng ảnh
    uint32_t height;            ///< Image height in pixels / Chiều cao ảnh
    uint32_t bit_depth;         ///< Color bit depth (8 or 10 bits) / Độ sâu màu
    uint32_t orientation;       ///< EXIF orientation (1..8) / Chiều xoay ảnh
    bool has_alpha;             ///< Presence of auxiliary alpha channel / Có kênh alpha
    bool has_thumbnail;         ///< Presence of embedded thumbnail / Có ảnh thu nhỏ
    uint32_t thumb_width;       ///< Thumbnail width / Chiều rộng thumbnail
    uint32_t thumb_height;      ///< Thumbnail height / Chiều cao thumbnail
    uint32_t frame_count;       ///< Number of animation frames / Số lượng khung hình hoạt ảnh
    uint32_t duration_ms;       ///< Total duration for animation / Tổng thời lượng tính bằng ms
} heif_image_meta_t;

/**
 * @struct heif_output_stream_t
 * @brief Decoded pixel output stream buffer
 *        Bộ đệm luồng dữ liệu pixel đầu ra đã giải mã
 */
typedef struct heif_output_stream {
    uint8_t* data;              ///< Raw pixel memory pointer / Con trỏ vùng nhớ pixel
    size_t size;                ///< Total buffer size in bytes / Kích thước bộ đệm (bytes)
    uint32_t width;             ///< Decoded width / Chiều rộng giải mã
    uint32_t height;            ///< Decoded height / Chiều cao giải mã
    uint32_t stride;            ///< Row stride in bytes / Bước nhảy mỗi dòng
    heif_color_format_t format; ///< Pixel color format / Định dạng màu pixel
    bool is_extern;             ///< Whether buffer is externally allocated / Vùng nhớ do bên ngoài cấp phát
} heif_output_stream_t;

/**
 * @struct heif_anim_context_t
 * @brief Animation playback state context
 *        Ngữ cảnh trạng thái phát hoạt ảnh HEIF/VVIF
 */
typedef struct heif_anim_context {
    void* demuxer;              ///< Demuxer handle / Con trỏ tách luồng
    void* decoder;              ///< Underlying video decoder / Bộ giải mã video nền tảng
    uint32_t current_frame;     ///< Current frame index / Chỉ số khung hình hiện tại
    uint32_t total_frames;      ///< Total frames in animation / Tổng số khung hình
    int64_t current_pts;        ///< Presentation timestamp / Dấu thời gian hiển thị
    uint32_t loop_count;        ///< Animation loop count / Số lần lặp
} heif_anim_context_t;

#ifdef __cplusplus
}
#endif

#endif // TTHEIF_TYPES_H