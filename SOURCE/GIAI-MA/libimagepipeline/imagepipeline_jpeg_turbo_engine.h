/**
 * @file imagepipeline_jpeg_turbo_engine.h
 * @brief Clean-Room C++17 Declarations for Embedded libjpeg-turbo 1.5.3 (build 20180808) in libimagepipeline.so
 *        Khai báo C++17 cho nhân giải mã/mã hóa ảnh JPEG libjpeg-turbo 1.5.3 nhúng trong libimagepipeline.so
 *        (.text 0x003710..0x03726c, 347 hàm lõi + bộ biến đổi không suy hao transupp + ARM64 NEON SIMD)
 */

#ifndef NEXTAI_OPENCUT_IMAGEPIPELINE_JPEG_TURBO_ENGINE_H_
#define NEXTAI_OPENCUT_IMAGEPIPELINE_JPEG_TURBO_ENGINE_H_

#include "imagepipeline_types.h"
#include "imagepipeline_rodata_tables.h"

namespace nextai {
namespace opencut {
namespace imagepipeline {

// ============================================================================
// 1. LIBJPEG-TURBO 1.5.3 CORE ABI STRUCTURES (sizeof = 0x248 & 0x290)
//    CẤU TRÚC ABI LÕI CỦA LIBJPEG-TURBO 1.5.3
// ============================================================================

enum J_COLOR_SPACE : int32_t {
    JCS_UNKNOWN   = 0,
    JCS_GRAYSCALE = 1,
    JCS_RGB       = 2,
    JCS_YCbCr     = 3,
    JCS_CMYK      = 4,
    JCS_YCCK      = 5,
    JCS_EXT_RGB   = 6,
    JCS_EXT_RGBX  = 7,
    JCS_EXT_BGR   = 8,
    JCS_EXT_BGRX  = 9,
    JCS_EXT_XBGR  = 10,
    JCS_EXT_XRGB  = 11,
    JCS_EXT_RGBA  = 12,
    JCS_EXT_BGRA  = 13,
    JCS_EXT_ABGR  = 14,
    JCS_EXT_ARGB  = 15,
    JCS_RGB565    = 16
};

enum J_DCT_METHOD : int32_t {
    JDCT_ISLOW = 0,
    JDCT_IFAST = 1,
    JDCT_FLOAT = 2
};

enum JCOPY_OPTION : int32_t {
    JCOPYOPT_NONE     = 0,
    JCOPYOPT_COMMENTS = 1,
    JCOPYOPT_ALL      = 2
};

struct jpeg_memory_mgr {
    void* (*alloc_small)(jpeg_common_struct* cinfo, int pool_id, size_t sizeofobject); ///< +0x00
    void* (*alloc_large)(jpeg_common_struct* cinfo, int pool_id, size_t sizeofobject); ///< +0x08
    uint8_t** (*alloc_sarray)(jpeg_common_struct* cinfo, int pool_id, uint32_t samplesperrow, uint32_t numrows); ///< +0x10
    JBLOCKARRAY (*alloc_barray)(jpeg_common_struct* cinfo, int pool_id, uint32_t blocksperrow, uint32_t numrows); ///< +0x18
    void* (*request_virt_sarray)(jpeg_common_struct* cinfo, int pool_id, int pre_zero, uint32_t samplesperrow, uint32_t numrows, uint32_t maxaccess); ///< +0x20
    void* (*request_virt_barray)(jpeg_common_struct* cinfo, int pool_id, int pre_zero, uint32_t blocksperrow, uint32_t numrows, uint32_t maxaccess); ///< +0x28
    void (*realize_virt_arrays)(jpeg_common_struct* cinfo); ///< +0x30
    uint8_t** (*access_virt_sarray)(jpeg_common_struct* cinfo, void* ptr, uint32_t start_row, uint32_t num_rows, int writable); ///< +0x38
    JBLOCKARRAY (*access_virt_barray)(jpeg_common_struct* cinfo, void* ptr, uint32_t start_row, uint32_t num_rows, int writable); ///< +0x40
    void (*free_pool)(jpeg_common_struct* cinfo, int pool_id); ///< +0x48
    void (*self_destruct)(jpeg_common_struct* cinfo);         ///< +0x50
    long max_memory_to_use;                                   ///< +0x58
    long max_alloc_chunk;                                     ///< +0x60
};

struct jpeg_common_struct {
    jpeg_error_mgr*  err;           ///< +0x00
    jpeg_memory_mgr* mem;           ///< +0x08
    void*            progress;      ///< +0x10
    void*            client_data;   ///< +0x18
    int32_t          is_decompressor; ///< +0x20
    int32_t          global_state;  ///< +0x24
};

struct jpeg_compress_struct : public jpeg_common_struct {
    jpeg_destination_mgr* dest;             ///< +0x28
    uint32_t              image_width;      ///< +0x30
    uint32_t              image_height;     ///< +0x34
    int32_t               input_components; ///< +0x38
    J_COLOR_SPACE         in_color_space;   ///< +0x3C
    double                input_gamma;      ///< +0x40
    int32_t               data_precision;   ///< +0x48
    int32_t               num_components;   ///< +0x4C
    J_COLOR_SPACE         jpeg_color_space; ///< +0x50
    int32_t               optimize_coding;  ///< +0x138 in binary (str w22, [sp, #0x138] @ 0x0026b8)
    uint32_t              next_scanline;    ///< +0x168
    uint8_t               reserved_pad[0x248 - 0x60];
};

struct jpeg_decompress_struct : public jpeg_common_struct {
    jpeg_source_mgr* src;               ///< +0x28 (`str x22, [sp, #0x270]` @ 0x002650)
    uint32_t         image_width;       ///< +0x30
    uint32_t         image_height;      ///< +0x34
    int32_t          num_components;    ///< +0x38
    J_COLOR_SPACE    jpeg_color_space;  ///< +0x3C
    J_COLOR_SPACE    out_color_space;   ///< +0x40 (`str w9, [sp, #0x288]` @ 0x002670)
    uint32_t         scale_num;         ///< +0x44 (`str w8, [sp, #0x28c]` @ 0x002668)
    uint32_t         scale_denom;       ///< +0x48 (`str w8, [sp, #0x290]` @ 0x002674)
    int32_t          pad_gamma_;        ///< +0x4C
    double           output_gamma;      ///< +0x60 (`str d0, [sp, #0x2a8]` @ 0x00264c)
    int32_t          buffered_image;    ///< +0x68
    int32_t          raw_data_out;      ///< +0x6C
    J_DCT_METHOD     dct_method;        ///< +0x70
    int32_t          do_fancy_upsampling; ///< +0x74
    int32_t          do_block_smoothing;  ///< +0x78
    int32_t          quantize_colors;   ///< +0x7C
    int32_t          dither_mode;       ///< +0x80
    int32_t          two_pass_quantize; ///< +0x84
    int32_t          desired_number_of_colors; ///< +0x88
    uint32_t         output_width;      ///< +0x88 (`ldr w10, [sp, #0x2d0]` @ 0x0026fc)
    uint32_t         output_height;     ///< +0x8C (`ldr w9, [sp, #0x2d4]` @ 0x00271c)
    int32_t          out_color_components; ///< +0x90
    int32_t          output_components; ///< +0x94 (`ldr w9, [sp, #0x2dc]` @ 0x0026f8)
    int32_t          rec_outbuf_height; ///< +0x98
    int32_t          actual_number_of_colors; ///< +0x9C
    uint8_t**        colormap;          ///< +0xA0
    uint32_t         output_scanline;   ///< +0xA8 (`ldr w8, [sp, #0x2f0]` @ 0x002718)
    uint8_t          reserved_pad[0x290 - 0xB0];
};

// ============================================================================
// 2. LIBJPEG-TURBO 1.5.3 CORE FUNCTIONS (.text 0x003710..0x03726c)
//    CÁC HÀM LÕI CỦA LIBJPEG-TURBO 1.5.3 (.text 0x003710..0x03726c)
// ============================================================================

void jpeg_CreateCompress(jpeg_compress_struct* cinfo, int version, size_t structsize) noexcept;
void jpeg_destroy_compress(jpeg_compress_struct* cinfo) noexcept;
void jpeg_abort_compress(jpeg_compress_struct* cinfo) noexcept;
void jpeg_finish_compress(jpeg_compress_struct* cinfo) noexcept;
void jpeg_start_compress(jpeg_compress_struct* cinfo, int write_all_tables) noexcept;
uint32_t jpeg_write_scanlines(jpeg_compress_struct* cinfo, uint8_t** scanlines, uint32_t num_lines) noexcept;
void jpeg_set_defaults(jpeg_compress_struct* cinfo) noexcept;
void jpeg_set_quality(jpeg_compress_struct* cinfo, int quality, int force_baseline) noexcept;
void jpeg_add_quant_table(jpeg_compress_struct* cinfo, int which_tbl, const uint32_t* basic_table, int scale_factor, int force_baseline) noexcept;
void jpeg_write_coefficients(jpeg_compress_struct* cinfo, void* coef_arrays) noexcept;
void jpeg_copy_critical_parameters(const jpeg_decompress_struct* srcinfo, jpeg_compress_struct* dstinfo) noexcept;

void jpeg_CreateDecompress(jpeg_decompress_struct* dinfo, int version, size_t structsize) noexcept;
void jpeg_destroy_decompress(jpeg_decompress_struct* dinfo) noexcept;
int  jpeg_read_header(jpeg_decompress_struct* dinfo, int require_image) noexcept;
int  jpeg_start_decompress(jpeg_decompress_struct* dinfo) noexcept;
uint32_t jpeg_read_scanlines(jpeg_decompress_struct* dinfo, uint8_t** scanlines, uint32_t max_lines) noexcept;
int  jpeg_resync_to_restart(jpeg_decompress_struct* dinfo, int desired) noexcept;
void* jpeg_read_coefficients(jpeg_decompress_struct* dinfo) noexcept;
jpeg_error_mgr* jpeg_std_error(jpeg_error_mgr* err) noexcept;
void jinit_memory_mgr(jpeg_common_struct* cinfo) noexcept;

// ============================================================================
// 3. LOSSLESS DCT TRANSFORMATION ENGINE (`transupp.c` @ 0x01984c..0x01c3f8)
//    BỘ BIẾN ĐỔI KHỐI HỆ SỐ DCT KHÔNG SUY HAO (`transupp.c` @ 0x01984c..0x01c3f8)
// ============================================================================

int  jtransform_request_workspace(jpeg_decompress_struct* srcinfo, jpeg_transform_info* info) noexcept;
void* jtransform_adjust_parameters(jpeg_decompress_struct* srcinfo,
                                   jpeg_compress_struct* dstinfo,
                                   void* src_coef_arrays,
                                   jpeg_transform_info* info) noexcept;
void jtransform_execute_transform(jpeg_decompress_struct* srcinfo,
                                  jpeg_compress_struct* dstinfo,
                                  void* src_coef_arrays,
                                  jpeg_transform_info* info) noexcept;
void jcopy_markers_setup(jpeg_decompress_struct* srcinfo, JCOPY_OPTION option) noexcept;
void jcopy_markers_execute(jpeg_decompress_struct* srcinfo,
                           jpeg_compress_struct* dstinfo,
                           JCOPY_OPTION option) noexcept;

void TransformDctBlock8x8(const JBLOCK src_block, JBLOCK dst_block, JXFORM_CODE xform) noexcept;

// ============================================================================
// 4. HUFFMAN ENTROPY CODER & ARM64 NEON FDCT / IDCT / YCbCr-RGB KERNELS
//    BỘ MÃ HÓA ENTROPY HUFFMAN & NHÂN TÍNH TOÁN FDCT / IDCT / YCbCr-RGB NEON
// ============================================================================

int  encode_one_block_0x020c90(uint8_t* out_buf,
                               size_t* out_bytes,
                               const JBLOCK block,
                               int16_t last_dc_val,
                               const uint32_t* dc_ehufco,
                               const uint8_t* dc_ehufsi,
                               const uint32_t* ac_ehufco,
                               const uint8_t* ac_ehufsi) noexcept;

void jpeg_fdct_islow_0x02f8bc(int32_t* data) noexcept;
void jpeg_fdct_ifast_0x02fbb8(int32_t* data) noexcept;
void jpeg_idct_islow_0x0324c8(const JCOEF* coef_block, const uint16_t* quant_tbl, uint8_t* output_buf, uint32_t output_stride) noexcept;
void jpeg_idct_ifast_0x033058(const JCOEF* coef_block, const uint16_t* quant_tbl, uint8_t* output_buf, uint32_t output_stride) noexcept;
void jpeg_idct_4x4_0x0346e8(const JCOEF* coef_block, const uint16_t* quant_tbl, uint8_t* output_buf, uint32_t output_stride) noexcept;
void jpeg_idct_2x2_0x035240(const JCOEF* coef_block, const uint16_t* quant_tbl, uint8_t* output_buf, uint32_t output_stride) noexcept;
void jpeg_idct_1x1_0x035e50(const JCOEF* coef_block, const uint16_t* quant_tbl, uint8_t* output_buf, uint32_t output_stride) noexcept;

void ycc_rgb_convert_0x02db60(uint32_t width,
                              const uint8_t* y_row,
                              const uint8_t* cb_row,
                              const uint8_t* cr_row,
                              uint8_t* out_rgb_row) noexcept;

void rgb_ycc_convert_0x008024(uint32_t width,
                              const uint8_t* in_rgb_row,
                              uint8_t* y_row,
                              uint8_t* cb_row,
                              uint8_t* cr_row) noexcept;

} // namespace imagepipeline
} // namespace opencut
} // namespace nextai

#endif // NEXTAI_OPENCUT_IMAGEPIPELINE_JPEG_TURBO_ENGINE_H_
