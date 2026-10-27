/**
 * @file imagepipeline_types.h
 * @brief Clean-Room C++17 ABI Structures, Constants, and Mathematical Proofs for libimagepipeline.so
 *        Cấu trúc ABI C++17, Hằng số và Chứng minh Toán học cho libimagepipeline.so
 *        (Facebook Fresco ImagePipeline Native Engine & Embedded libjpeg-turbo 1.5.3)
 *
 * Binary Forensics / Thông số Nhị phân:
 *   - Library / Thư viện         : libimagepipeline.so (TASK_SO_117_libimagepipeline / TASK-128)
 *   - File Size / Dung lượng     : 264,328 bytes (0x40888)
 *   - SHA-256                    : 38fed18184707429505cfabd7540d22f5560965d310b6501ae05a67a0f7d2266
 *   - Architecture / Kiến trúc   : AArch64 (ARM64-v8a), Little-Endian, Android NDK
 *   - Embedded Codec             : libjpeg-turbo version 1.5.3 (build 20180808), IJG JPEG 80 (8d 15-Jan-2012)
 *   - DT_NEEDED                  : libc++_shared.so, liblog.so, libjnigraphics.so, libc.so, libm.so, libdl.so
 *   - ELF Sections / Các phân đoạn:
 *       .text        : vaddr 0x001fc0, file 0x001fc0, size 0x035854 (219,220 bytes, 393 FDE functions)
 *       .rodata      : vaddr 0x037820, file 0x037820, size 0x0030aa ( 12,458 bytes)
 *       .eh_frame_hdr: vaddr 0x03a8cc, file 0x03a8cc, size 0x000c54 (  3,156 bytes, 393 entries)
 *       .eh_frame    : vaddr 0x03b520, file 0x03b520, size 0x0035d0 ( 13,776 bytes)
 *       .data.rel.ro : vaddr 0x043768, file 0x03f768, size 0x000408 (  1,032 bytes, 129 message pointers)
 *       .data        : vaddr 0x044000, file 0x040000, size 0x0000f0 (    240 bytes, 10 JNINativeMethod entries)
 *       .bss         : vaddr 0x0440f0, file 0x0400f0, size 0x000038 (     56 bytes, 7 global JNI handles)
 */

#ifndef NEXTAI_OPENCUT_IMAGEPIPELINE_TYPES_H_
#define NEXTAI_OPENCUT_IMAGEPIPELINE_TYPES_H_

#include <csetjmp>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <vector>

#ifndef JNI_VERSION_1_6
#define JNI_VERSION_1_6 0x00010006
#define JNI_OK          0
#define JNI_ERR         (-1)
#define JNI_FALSE       0
#define JNI_TRUE        1
#endif

using jboolean = uint8_t;
using jbyte    = int8_t;
using jchar    = uint16_t;
using jshort   = int16_t;
using jint     = int32_t;
using jlong    = int64_t;
using jfloat   = float;
using jdouble  = double;
using jsize    = jint;

struct _jobject;
struct _jclass;
struct _jstring;
struct _jthrowable;
struct _jbyteArray;
struct _jfieldID;
struct _jmethodID;

using jobject    = _jobject*;
using jclass     = _jclass*;
using jstring    = _jstring*;
using jthrowable = _jthrowable*;
using jbyteArray = _jbyteArray*;
using jfieldID   = _jfieldID*;
using jmethodID  = _jmethodID*;

struct JNINativeMethod {
    const char* name;
    const char* signature;
    void*       fnPtr;
};

struct JNIEnv {
    const void* functions;
};

struct JavaVM {
    const void* functions;
};

namespace nextai {
namespace opencut {
namespace imagepipeline {

// ============================================================================
// 1. BINARY CONSTANTS & SECTION ADDRESSES
//    HẰNG SỐ NHỊ PHÂN & ĐỊA CHỈ PHÂN ĐOẠN ELF
// ============================================================================

constexpr uint32_t kImagePipelineBinarySize      = 264328U;
constexpr uint32_t kImagePipelineFdeFunctionCount = 393U;
constexpr uint32_t kJpegLibVersion80             = 80U;    // 0x50 (cmp w1, #0x50 @ 0x003728 & 0x00aff4)
constexpr uint32_t kJpegCompressStructSize       = 0x248U; // 584 bytes (cmp x20, #0x248 @ 0x00375c)
constexpr uint32_t kJpegDecompressStructSize     = 0x290U; // 656 bytes (cmp x20, #0x290 @ 0x00b028)
constexpr uint32_t kJpegStreamBufferSize         = 0x2000U; // 8,192 bytes (mov w2, #0x2000 @ 0x002b68, 0x002f30, 0x003118)
constexpr uint32_t kJpegScaleDenominator         = 8U;     // Fixed DCT scale denominator (mov w9, #8 @ 0x0035dc)
constexpr uint32_t kJpegMinScaleNumerator        = 1U;
constexpr uint32_t kJpegMaxScaleNumerator        = 16U;    // cmp w9, #0x11 @ 0x0025b0
constexpr uint32_t kJpegStdMessageCount          = 129U;   // .data.rel.ro 0x043768..0x043b68
constexpr uint32_t kDctSize                      = 8U;
constexpr uint32_t kDctSize2                     = 64U;

// ============================================================================
// 2. MATHEMATICAL PROOFS OF LOSSLESS DCT DIHEDRAL TRANSFORMATIONS & QUANTIZATION
//    CHỨNG MINH TOÁN HỌC BIẾN ĐỔI KHỐI DCT KHÔNG SUY HAO & LƯỢNG TỬ HÓA IJG
// ============================================================================
//
// Theorem 1 (2D Type-II DCT Frequency-Domain Dihedral Group D_4 Identities):
//   Let f(x, y) be an 8x8 spatial pixel block (x, y in 0..7) and F(u, v) be its
//   64-coefficient 2D Type-II Discrete Cosine Transform:
//     F(u, v) = (1/4) C(u) C(v) sum_{x=0}^7 sum_{y=0}^7 f(x, y)
//               * cos((2x + 1) u pi / 16) * cos((2y + 1) v pi / 16).
//   Under spatial reflection x -> 7 - x:
//     cos((2(7 - x) + 1) u pi / 16) = cos(u pi - (2x + 1) u pi / 16)
//                                   = (-1)^u cos((2x + 1) u pi / 16).
//   Consequently, every element of the dihedral group D_4 acts directly on the
//   quantized 8x8 DCT coefficient matrix F(u, v) without inverse DCT or
//   re-quantization loss (implemented in transupp.c @ 0x01a740..0x01c18c):
//     1. JXFORM_FLIP_H     (1): F'(u, v) = (-1)^u F(u, v)       (negate odd columns u = 1, 3, 5, 7)
//     2. JXFORM_FLIP_V     (2): F'(u, v) = (-1)^v F(u, v)       (negate odd rows    v = 1, 3, 5, 7)
//     3. JXFORM_TRANSPOSE  (3): F'(u, v) = F(v, u)              (swap indices u <-> v)
//     4. JXFORM_TRANSVERSE (4): F'(u, v) = (-1)^(u+v) F(v, u)   (swap u <-> v, negate when u+v is odd)
//     5. JXFORM_ROT_90     (5): F'(u, v) = (-1)^u F(v, u)       (transpose + flip_h, negate odd u)
//     6. JXFORM_ROT_180    (6): F'(u, v) = (-1)^(u+v) F(u, v)   (flip_h + flip_v, negate when u+v is odd)
//     7. JXFORM_ROT_270    (7): F'(u, v) = (-1)^v F(v, u)       (transpose + flip_v, negate odd v)
//
// Theorem 2 (IJG Quality-to-Linear Scale Factor Mapping @ 0x007ae4..0x007b18):
//   Given quality q in [1, 100]:
//     scale_factor(q) = floor(5000 / q)   if 1 <= q < 50   (0x007af8: mov w8, #0x1388; sdiv w1, w8, w9)
//                     = 200 - 2 * q       if 50 <= q <= 100 (0x007b04: mov w8, #0xc8; sub w1, w8, w9, lsl #1)
//   And each quantization step Q[i] is scaled in jpeg_add_quant_table (0x00795c..0x007ae4):
//     Q_scaled[i] = clamp(floor((Q[i] * scale_factor(q) + 50) / 100), 1, 255).

/**
 * @brief Lossless DCT transformation codes from transupp.h (JXFORM_CODE).
 *        Mã phép biến đổi khối DCT không suy hao từ transupp.h.
 */
enum JXFORM_CODE : int32_t {
    JXFORM_NONE       = 0, ///< No transformation / Không biến đổi
    JXFORM_FLIP_H     = 1, ///< Horizontal flip / Lật ngang
    JXFORM_FLIP_V     = 2, ///< Vertical flip / Lật dọc
    JXFORM_TRANSPOSE  = 3, ///< Transpose across main diagonal / Chuyển vị đường chéo chính
    JXFORM_TRANSVERSE = 4, ///< Transpose across anti-diagonal / Chuyển vị đường chéo phụ
    JXFORM_ROT_90     = 5, ///< Rotate 90 degrees CW / Xoay 90 độ thuận chiều kim đồng hồ
    JXFORM_ROT_180    = 6, ///< Rotate 180 degrees / Xoay 180 độ
    JXFORM_ROT_270    = 7  ///< Rotate 270 degrees CW / Xoay 270 độ thuận chiều kim đồng hồ
};

/**
 * @brief Fresco internal RotationType enum (0..7) returned by 0x003468 and 0x0034dc.
 *        Kiểu liệt kê RotationType nội bộ của Fresco (0..7) trả về từ 0x003468 và 0x0034dc.
 */
enum class FrescoRotationType : uint32_t {
    ROTATE_0            = 0,
    ROTATE_90           = 1,
    ROTATE_180          = 2,
    ROTATE_270          = 3,
    FLIP_HORIZONTAL     = 4,
    FLIP_VERTICAL       = 5,
    TRANSPOSE           = 6,
    TRANSVERSE          = 7
};

/**
 * @brief 2-byte ScaleFactor passed on stack at 0x0035f4 (`strb w5, [sp]; strb w9, [sp, #1]`).
 *        Cấu trúc tỷ lệ thu phóng 2 byte truyền trên ngăn xếp (`numerator / 8`).
 */
struct ScaleFactor {
    uint8_t numerator;   ///< +0x00: Scale numerator (1..16, where 8 = 1.0x)
    uint8_t denominator; ///< +0x01: Always 8 (`mov w9, #8` @ 0x0035dc & 0x003688)

    constexpr bool shouldScale() const noexcept {
        return (numerator != denominator) && (numerator != 0U);
    }
};
static_assert(sizeof(ScaleFactor) == 2, "ScaleFactor must be 2 bytes");

/**
 * @brief Computes the exact IJG linear quality scale factor matching `jpeg_quality_scaling` (0x007ae4).
 *        Tính hệ số tỷ lệ chất lượng tuyến tính IJG khớp lệnh máy tại 0x007ae4..0x007b18.
 */
inline constexpr int32_t ComputeJpegQualityScaleFactor(int32_t quality) noexcept {
    if (quality <= 0) {
        quality = 1;
    } else if (quality > 100) {
        quality = 100;
    }
    if (quality < 50) {
        return 5000 / quality; // mov w8, #0x1388; sdiv w1, w8, w9
    }
    return 200 - (quality * 2); // mov w8, #0xc8; sub w1, w8, w9, lsl #1
}

/**
 * @brief Computes a scaled quantization table entry matching `jpeg_add_quant_table` (0x00795c).
 *        Tính giá trị mục bảng lượng tử hóa đã nhân tỷ lệ khớp `jpeg_add_quant_table` (0x00795c).
 */
inline constexpr uint16_t ComputeScaledQuantEntry(uint32_t basic_val,
                                                  int32_t scale_factor,
                                                  bool force_baseline = true) noexcept {
    int64_t temp = (static_cast<int64_t>(basic_val) * static_cast<int64_t>(scale_factor) + 50LL) / 100LL;
    if (temp <= 0) {
        temp = 1;
    }
    if (temp > 32767) {
        temp = 32767;
    }
    if (force_baseline && temp > 255) {
        temp = 255;
    }
    return static_cast<uint16_t>(temp);
}

// ============================================================================
// 3. CORE LIBJPEG-TURBO 1.5.3 & FRESCO STREAM WRAPPER ABI STRUCTURES
//    CẤU TRÚC ABI LÕI CỦA LIBJPEG-TURBO 1.5.3 & BỘ BAO LUỒNG FRESCO
// ============================================================================

using JCOEF  = int16_t;
using JBLOCK = JCOEF[64];
using JBLOCKROW = JBLOCK*;
using JBLOCKARRAY = JBLOCKROW*;

struct jpeg_common_struct;
struct jpeg_compress_struct;
struct jpeg_decompress_struct;

/**
 * @brief Standard libjpeg error manager (`sizeof = 0xa8 = 168 bytes`, `jmp_buf` follows at `+0xa8` in Fresco).
 *        Cấu trúc quản lý lỗi chuẩn của libjpeg (`sizeof = 0xa8 = 168 byte`).
 */
struct jpeg_error_mgr {
    void (*error_exit)(jpeg_common_struct* cinfo);                ///< +0x00: 0x002980 in Fresco
    void (*emit_message)(jpeg_common_struct* cinfo, int msg_level); ///< +0x08
    void (*output_message)(jpeg_common_struct* cinfo);            ///< +0x10
    void (*format_message)(jpeg_common_struct* cinfo, char* buffer); ///< +0x18
    void (*reset_error_mgr)(jpeg_common_struct* cinfo);           ///< +0x20
    int   msg_code;                                               ///< +0x28: e.g. 0x2b = JWRN_JPEG_EOF @ 0x003024
    union {
        int  i[8];
        char s[80];
    } msg_parm;                                                   ///< +0x2C..+0x7C
    int   trace_level;                                            ///< +0x7C
    long  num_warnings;                                           ///< +0x80
    const char* const* jpeg_message_table;                        ///< +0x88: 0x043768 in .data.rel.ro
    int   last_jpeg_message;                                      ///< +0x90: 127 (0x7f)
    const char* const* addon_message_table;                       ///< +0x98
    int   first_addon_message;                                    ///< +0xA0
    int   last_addon_message;                                     ///< +0xA4
};
static_assert(sizeof(jpeg_error_mgr) == 0xA8, "jpeg_error_mgr must be 0xA8 (168) bytes");

/**
 * @brief Fresco `JpegErrorHandler` (`0x00294c..0x002a94`, `sizeof = 0x1c0 = 448 bytes`):
 *        +0x000: `jpeg_error_mgr pub` (`0xa8` bytes)
 *        +0x0a8: `uint64_t setjmp_buffer[32]` (`0x100` bytes, passed to `setjmp` at `0x0025fc` & `0x0027c0`)
 *        +0x1a8: `JNIEnv* env` (`str x1, [x0, #0x1a8]` @ `0x002960`)
 *        +0x1b0: `jpeg_decompress_struct* dinfo_ptr` (`str x1, [x0, #0x1b0]` @ `0x0029b4`)
 *        +0x1b8: `jpeg_compress_struct* cinfo_ptr` (`str x1, [x0, #0x1b8]` @ `0x0029c0`)
 */
struct JpegErrorHandler {
    jpeg_error_mgr          pub;              ///< +0x000..+0x0A8
    uint64_t                setjmp_buf[32];   ///< +0x0A8..+0x1A8 (AArch64 jmp_buf)
    JNIEnv*                 env;              ///< +0x1A8
    jpeg_decompress_struct* dinfo_ptr;        ///< +0x1B0
    jpeg_compress_struct*   cinfo_ptr;        ///< +0x1B8
};
static_assert(sizeof(JpegErrorHandler) == 0x1C0, "JpegErrorHandler must be 0x1C0 (448) bytes");

/**
 * @brief Standard libjpeg source manager (`sizeof = 0x38 = 56 bytes`).
 *        Bộ quản lý nguồn dữ liệu đầu vào chuẩn của libjpeg (`56 byte`).
 */
struct jpeg_source_mgr {
    const uint8_t* next_input_byte;                                           ///< +0x00
    size_t         bytes_in_buffer;                                           ///< +0x08
    void (*init_source)(jpeg_decompress_struct* dinfo);                       ///< +0x10
    int  (*fill_input_buffer)(jpeg_decompress_struct* dinfo);                 ///< +0x18
    void (*skip_input_data)(jpeg_decompress_struct* dinfo, long num_bytes);   ///< +0x20
    int  (*resync_to_restart)(jpeg_decompress_struct* dinfo, int desired);    ///< +0x28
    void (*term_source)(jpeg_decompress_struct* dinfo);                       ///< +0x30
};
static_assert(sizeof(jpeg_source_mgr) == 0x38, "jpeg_source_mgr must be 0x38 (56) bytes");

/**
 * @brief Standard libjpeg destination manager (`sizeof = 0x28 = 40 bytes`).
 *        Bộ quản lý đích dữ liệu đầu ra chuẩn của libjpeg (`40 byte`).
 */
struct jpeg_destination_mgr {
    uint8_t* next_output_byte;                                                ///< +0x00
    size_t   free_in_buffer;                                                  ///< +0x08
    void (*init_destination)(jpeg_compress_struct* cinfo);                    ///< +0x10
    int  (*empty_output_buffer)(jpeg_compress_struct* cinfo);                 ///< +0x18
    void (*term_destination)(jpeg_compress_struct* cinfo);                    ///< +0x20
};
static_assert(sizeof(jpeg_destination_mgr) == 0x28, "jpeg_destination_mgr must be 0x28 (40) bytes");

/**
 * @brief Fresco `JpegInputStreamWrapper` (`0x002ed8..0x0030dc`, `sizeof = 0x60 = 96 bytes`):
 *        Wraps a Java `java.io.InputStream` for libjpeg decompression.
 */
struct JpegInputStreamWrapper {
    jpeg_source_mgr pub;         ///< +0x00..+0x38
    jobject         input_stream;///< +0x38: Java InputStream reference
    jbyteArray      java_buffer; ///< +0x40: 8,192-byte Java byte[] buffer (`NewByteArray(env, 0x2000)`)
    uint8_t*        native_buf;  ///< +0x48: 8,192-byte libjpeg pool buffer
    JNIEnv*         env;         ///< +0x50: Current thread JNIEnv*
    int32_t         start_of_file; ///< +0x58: Boolean flag (1 on init, 0 after first read)
    int32_t         padding_;    ///< +0x5C
};
static_assert(sizeof(JpegInputStreamWrapper) == 0x60, "JpegInputStreamWrapper must be 0x60 (96) bytes");

/**
 * @brief Fresco `JpegOutputStreamWrapper` (`0x0030dc..0x003294`, `sizeof = 0x48 = 72 bytes`):
 *        Wraps a Java `java.io.OutputStream` for libjpeg compression.
 */
struct JpegOutputStreamWrapper {
    jpeg_destination_mgr pub;          ///< +0x00..+0x28
    jobject              output_stream;///< +0x28: Java OutputStream reference
    jbyteArray           java_buffer;  ///< +0x30: 8,192-byte Java byte[] buffer
    uint8_t*             native_buf;   ///< +0x38: 8,192-byte libjpeg pool buffer
    JNIEnv*              env;          ///< +0x40: Current thread JNIEnv*
};
static_assert(sizeof(JpegOutputStreamWrapper) == 0x48, "JpegOutputStreamWrapper must be 0x48 (72) bytes");

/**
 * @brief Fresco `JpegMemoryDestinationWrapper` (`0x002b28..0x002c08`, `sizeof = 0x48 = 72 bytes`):
 *        Used as intermediate in-memory buffer when both downscaling and lossless DCT rotation run.
 */
struct JpegMemoryDestinationWrapper {
    jpeg_destination_mgr pub;        ///< +0x00..+0x28
    std::vector<uint8_t> encoded;    ///< +0x28..+0x40 (24-byte libc++ std::vector<uint8_t>)
    uint8_t*             block_buf;  ///< +0x40: 8,192-byte pool buffer (`[x20, #0x40]` @ 0x002b78)
};

/**
 * @brief Fresco `JpegMemorySourceWrapper` (`0x002a94..0x002b28`, `sizeof = 0x50 = 80 bytes`):
 *        Reads back the intermediate `std::vector<uint8_t>` into `rotateJpeg` (`0x00277c`).
 */
struct JpegMemorySourceWrapper {
    jpeg_source_mgr      pub;        ///< +0x00..+0x38
    std::vector<uint8_t> encoded;    ///< +0x38..+0x50 (`ldp x9, x10, [x8, #0x38]` @ 0x002ad8)
};

/**
 * @brief 96-byte (`0x60`) `jpeg_transform_info` structure passed to `jtransform_*` (`0x002874..0x002904`).
 *        Cấu trúc điều khiển biến đổi khối DCT `jpeg_transform_info` 96 byte (`0x60`).
 */
struct jpeg_transform_info {
    JXFORM_CODE transform;         ///< +0x00: Transformation code (0..7)
    int32_t     perfect;           ///< +0x04: Require perfect MCU alignment
    int32_t     trim;              ///< +0x08: Trim partial edge MCUs (`str w21, [sp, #8]` = 1 @ 0x0028a0)
    int32_t     force_grayscale;   ///< +0x0C: Drop Cb/Cr components
    int32_t     crop;              ///< +0x10: Crop flag
    int32_t     slow_hflip;        ///< +0x14
    uint32_t    crop_width;        ///< +0x18
    int32_t     crop_width_set;    ///< +0x1C
    uint32_t    crop_height;       ///< +0x20
    int32_t     crop_height_set;   ///< +0x24
    uint32_t    crop_xoffset;      ///< +0x28
    int32_t     crop_xoffset_set;  ///< +0x2C
    uint32_t    crop_yoffset;      ///< +0x30
    int32_t     crop_yoffset_set;  ///< +0x34
    int32_t     num_components;    ///< +0x38
    void*       workspace_coef_arrays; ///< +0x40
    uint32_t    output_width;      ///< +0x48
    uint32_t    output_height;     ///< +0x4C
    uint32_t    x_crop_offset;     ///< +0x50
    uint32_t    y_crop_offset;     ///< +0x54
    int32_t     iMCU_sample_width; ///< +0x58
    int32_t     iMCU_sample_height;///< +0x5C
};
static_assert(sizeof(jpeg_transform_info) == 0x60, "jpeg_transform_info must be 0x60 (96) bytes");

/**
 * @brief Descriptor for each of the 393 `.eh_frame` functions in `libimagepipeline.so`.
 *        Bộ mô tả cho từng hàm trong 393 hàm `.eh_frame` của `libimagepipeline.so`.
 */
struct ImagePipelineFdeEntry {
    uint32_t index;
    uint32_t start_vaddr;
    uint32_t size_bytes;
    uint32_t first_insn_le;
    uint32_t second_insn_le;
};

/**
 * @brief Descriptor for each of the 10 `JNINativeMethod` entries in `.data 0x044000..0x0440f0`.
 *        Bộ mô tả cho 10 mục `JNINativeMethod` trong `.data 0x044000..0x0440f0`.
 */
struct ImagePipelineJniRegRecord {
    uint32_t    index;
    uint64_t    data_vaddr;
    uint64_t    name_rodata_vaddr;
    const char* name;
    uint64_t    sig_rodata_vaddr;
    const char* signature;
    uint64_t    fn_text_vaddr;
    const char* owning_class;
};

} // namespace imagepipeline
} // namespace opencut
} // namespace nextai

#endif // NEXTAI_OPENCUT_IMAGEPIPELINE_TYPES_H_
