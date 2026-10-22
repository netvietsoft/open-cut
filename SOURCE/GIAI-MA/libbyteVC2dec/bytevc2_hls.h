/**
 * @file bytevc2_hls.h
 * @brief High-Level Syntax (HLS) and NAL Unit Bitstream Parser for ByteVC2
 *        Bộ phân giải cú pháp cấp cao (HLS) và gói NAL trong ByteVC2
 *
 * Implements NAL parsing, Access Unit delimitation, and parameter decoding matching libbyteVC2dec.so.
 * Thực thi phân tách NAL, xác định Access Unit và giải mã tham số khớp với libbyteVC2dec.so.
 */

#ifndef BYTEVC2_HLS_H
#define BYTEVC2_HLS_H

#include "bytevc2_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @struct ByteVC2Sps
 * @brief Decoded Sequence Parameter Set
 *        Tập tham số chuỗi đã giải mã
 */
typedef struct ByteVC2Sps {
    int32_t sps_id;                ///< SPS identifier / Mã định danh SPS
    int32_t max_pic_width;         ///< Maximum luma picture width / Chiều rộng ảnh tối đa
    int32_t max_pic_height;        ///< Maximum luma picture height / Chiều cao ảnh tối đa
    int32_t bit_depth;             ///< Bitdepth (8, 10, 12) / Độ sâu bit mẫu
    int32_t chroma_format_idc;     ///< Chroma sampling (1=4:2:0) / Định dạng lấy mẫu sắc độ
    int32_t log2_ctu_size;         ///< Coding Tree Unit log2 size (typically 5, 6, 7) / Kích thước CTU
    int32_t log2_max_poc_lsb;      ///< Max POC LSB bit length / Độ dài bit cho POC LSB
    bool gdr_enabled_flag;         ///< Gradual decoding refresh / Cờ làm mới giải mã tiệm tiến
    bool vui_present_flag;         ///< VUI parameters present / Cờ hiện diện tham số VUI
} ByteVC2Sps;

/**
 * @struct ByteVC2Pps
 * @brief Decoded Picture Parameter Set
 *        Tập tham số ảnh đã giải mã
 */
typedef struct ByteVC2Pps {
    int32_t pps_id;                ///< PPS identifier / Mã định danh PPS
    int32_t sps_id;                ///< Referenced SPS ID / ID SPS được tham chiếu
    int32_t pic_width_in_luma_samples;  ///< Width / Chiều rộng
    int32_t pic_height_in_luma_samples; ///< Height / Chiều cao
    int32_t cb_qp_offset;          ///< Cb QP offset / Độ lệch lượng tử Cb
    int32_t cr_qp_offset;          ///< Cr QP offset / Độ lệch lượng tử Cr
    bool conformance_window_flag;  ///< Cropping window present / Cờ cửa sổ cắt ảnh
} ByteVC2Pps;

/**
 * @struct ByteVC2SliceHeader
 * @brief Decoded Slice Header
 *        Tiêu đề phân đoạn đã giải mã
 */
typedef struct ByteVC2SliceHeader {
    int32_t slice_type;            ///< 0=B-slice, 1=P-slice, 2=I-slice / Loại phân đoạn
    int32_t pps_id;                ///< Referenced PPS ID / ID PPS tham chiếu
    int32_t poc;                   ///< Computed Picture Order Count / Thứ tự ảnh tính toán
    int32_t slice_address;         ///< CTU address / Địa chỉ khối cây CTU
    int32_t qp;                    ///< Slice initial QP / Lượng tử ban đầu của phân đoạn
} ByteVC2SliceHeader;

/**
 * @brief Scan bitstream buffer to locate next complete Access Unit (AU)
 *        Quét vùng đệm bitstream để xác định đơn vị truy cập (AU) kế tiếp
 *
 * Exported C API matching ARM64 symbol 'byteVC2_get_next_access_unit' at VAddr 0x0000da84.
 * Hàm C xuất khẩu tương ứng ký hiệu ARM64 'byteVC2_get_next_access_unit' tại VAddr 0x0000da84.
 *
 * @param buf Pointer to bitstream data / Con trỏ dữ liệu bitstream
 * @param buf_len Length of bitstream in bytes / Độ dài bitstream
 * @param next_au_offset Output offset to next AU / Offset đầu ra tới AU tiếp theo
 * @param next_au_len Output length of current AU / Độ dài đầu ra của AU hiện tại
 * @return 0 on success, -1 if no AU delimiter found
 *         0 nếu thành công, -1 nếu không tìm thấy phân tách AU
 */
int32_t byteVC2_get_next_access_unit(const uint8_t* buf, int32_t buf_len, int32_t* next_au_offset, int32_t* next_au_len);

/**
 * @brief Parse high-level parameter sets from bitstream NAL units
 *        Phân giải các tập tham số cấp cao từ các gói NAL bitstream
 * @param buf Bitstream buffer / Bộ đệm luồng bit
 * @param buf_len Buffer size / Kích thước bộ đệm
 * @param sps Output SPS structure / Cấu trúc SPS đầu ra
 * @param pps Output PPS structure / Cấu trúc PPS đầu ra
 * @return 0 on success, -1 on syntax error / 0 nếu thành công, -1 nếu lỗi cú pháp
 */
int32_t bytevc2_parse_hls_params(const uint8_t* buf, int32_t buf_len, ByteVC2Sps* sps, ByteVC2Pps* pps);

#ifdef __cplusplus
}
#endif

#endif // BYTEVC2_HLS_H
