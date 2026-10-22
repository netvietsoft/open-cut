/**
 * @file bytevc2_types.h
 * @brief ByteDance ByteVC2 (H.266/VVC) Video Decoder Core Type Definitions
 *        Định nghĩa kiểu dữ liệu lõi bộ giải mã video ByteDance ByteVC2 (H.266/VVC)
 *
 * Reconstructed cleanroom implementation based on AArch64 binary analysis of libbyteVC2dec.so.
 * Tái cấu trúc phòng sạch dựa trên phân tích nhị phân AArch64 của libbyteVC2dec.so.
 */

#ifndef BYTEVC2_TYPES_H
#define BYTEVC2_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// Version string constant / Hằng số chuỗi phiên bản
#define BYTEVC2DEC_VERSION_STRING "0.8.1.3"

// Alignment constraints / Giới hạn căn lề bộ nhớ
#define BYTEVC2_ALIGN_BYTES 64

// Decoder return status codes / Mã trạng thái trả về của bộ giải mã
typedef enum {
    BYTEVC2_STATUS_OK                 =  0,  ///< Success / Thành công
    BYTEVC2_STATUS_ERROR              = -1,  ///< General error / Lỗi chung
    BYTEVC2_STATUS_INVALID_PARAM      = -2,  ///< Invalid parameter / Tham số không hợp lệ
    BYTEVC2_STATUS_NO_MEMORY          = -3,  ///< Out of memory / Hết bộ nhớ
    BYTEVC2_STATUS_NEED_MORE_DATA     = -4,  ///< Need more bitstream data / Cần thêm dữ liệu bitstream
    BYTEVC2_STATUS_NO_FRAME_OUTPUT    = -5,  ///< No frame available / Không có frame sẵn sàng
    BYTEVC2_STATUS_DPB_FULL           = -6,  ///< DPB buffer full / Bộ đệm DPB đầy
    BYTEVC2_STATUS_UNSUPPORTED        = -7,  ///< Unsupported feature / Tính năng chưa hỗ trợ
    BYTEVC2_STATUS_FLUSHING           = -8   ///< Decoder is flushing / Bộ giải mã đang xả đệm
} ByteVC2Status;

// Log level constants / Các mức độ ghi log
typedef enum {
    BYTEVC2_LOG_NONE    = 0,  ///< Suppress all logs / Tắt toàn bộ log
    BYTEVC2_LOG_ERROR   = 1,  ///< Error messages only / Chỉ thông báo lỗi
    BYTEVC2_LOG_WARNING = 2,  ///< Warnings and errors / Cảnh báo và lỗi
    BYTEVC2_LOG_DEBUG   = 3,  ///< Debug diagnostics / Thông tin gỡ lỗi
    BYTEVC2_LOG_FULL    = 4   ///< Full verbose tracing / Toàn bộ nhật ký chi tiết
} ByteVC2LogLevel;

// Pixel format definitions / Định nghĩa định dạng điểm ảnh
typedef enum {
    BYTEVC2_PIX_FMT_YUV420P = 0,  ///< Planar YUV 4:2:0 8-bit / YUV 4:2:0 phẳng 8-bit
    BYTEVC2_PIX_FMT_YV12    = 1,  ///< Planar YVU 4:2:0 8-bit / YVU 4:2:0 phẳng 8-bit
    BYTEVC2_PIX_FMT_NV12    = 2,  ///< Semi-planar Y/UV 4:2:0 / Bán phẳng NV12
    BYTEVC2_PIX_FMT_NV21    = 3,  ///< Semi-planar Y/VU 4:2:0 / Bán phẳng NV21
    BYTEVC2_PIX_FMT_P010    = 4,  ///< Semi-planar 10-bit YUV / 10-bit bán phẳng
    BYTEVC2_PIX_FMT_HARDWARE= 5   ///< AHardwareBuffer direct binding / Liên kết trực tiếp phần cứng
} ByteVC2PixelFormat;

// NAL Unit Types in ByteVC2 (H.266/VVC) / Phân loại gói NAL trong ByteVC2
typedef enum {
    BYTEVC2_NAL_TRAIL_NUT      = 0,   ///< Trailing non-IRAP / Gói dữ liệu đuôi không IRAP
    BYTEVC2_NAL_STSA_NUT       = 1,   ///< Step-wise Temporal Sublayer Access / Truy cập lớp thời gian theo bước
    BYTEVC2_NAL_RADL_NUT       = 2,   ///< Random Access Decodable Leading / Gói dẫn đường giải mã ngẫu nhiên
    BYTEVC2_NAL_RASL_NUT       = 3,   ///< Random Access Skipped Leading / Gói dẫn đường bỏ qua
    BYTEVC2_NAL_IDR_W_RADL     = 7,   ///< Instantaneous Decoder Refresh with RADL / Khởi tạo lại giải mã kèm RADL
    BYTEVC2_NAL_IDR_N_LP       = 8,   ///< IDR without leading pictures / IDR không kèm hình ảnh dẫn đường
    BYTEVC2_NAL_CRA_NUT        = 9,   ///< Clean Random Access / Truy cập ngẫu nhiên sạch
    BYTEVC2_NAL_GDR_NUT        = 10,  ///< Gradual Decoding Refresh / Làm mới giải mã tiệm tiến
    BYTEVC2_NAL_OPI_NUT        = 12,  ///< Operating Point Information / Thông tin điểm vận hành
    BYTEVC2_NAL_DCI_NUT        = 13,  ///< Decoding Capability Information / Thông tin năng lực giải mã
    BYTEVC2_NAL_VPS_NUT        = 14,  ///< Video Parameter Set / Tập tham số video
    BYTEVC2_NAL_SPS_NUT        = 15,  ///< Sequence Parameter Set / Tập tham số chuỗi
    BYTEVC2_NAL_PPS_NUT        = 16,  ///< Picture Parameter Set / Tập tham số ảnh
    BYTEVC2_NAL_PREFIX_APS_NUT = 17,  ///< Prefix Adaptation Parameter Set / Tham số thích ứng tiền tố (ALF/LMCS)
    BYTEVC2_NAL_SUFFIX_APS_NUT = 18,  ///< Suffix Adaptation Parameter Set / Tham số thích ứng hậu tố
    BYTEVC2_NAL_PH_NUT         = 19,  ///< Picture Header / Tiêu đề ảnh độc lập
    BYTEVC2_NAL_AUD_NUT        = 20,  ///< Access Unit Delimiter / Phân tách đơn vị truy cập
    BYTEVC2_NAL_EOS_NUT        = 21,  ///< End of Sequence / Kết thúc chuỗi
    BYTEVC2_NAL_EOB_NUT        = 22,  ///< End of Bitstream / Kết thúc luồng bit
    BYTEVC2_NAL_PREFIX_SEI_NUT = 23,  ///< Prefix SEI / Thông tin bổ sung SEI tiền tố
    BYTEVC2_NAL_SUFFIX_SEI_NUT = 24   ///< Suffix SEI / Thông tin bổ sung SEI hậu tố
} ByteVC2NalType;

// Forward declarations / Khai báo chuyển tiếp
typedef struct ByteVC2Param ByteVC2Param;
typedef struct ByteVC2Packet ByteVC2Packet;
typedef struct ByteVC2Frame ByteVC2Frame;
typedef struct ByteVC2Context ByteVC2Context;

// Log callback signature / Chữ ký hàm gọi lại nhật ký
typedef void (*ByteVC2LogCallback)(void* opaque, int level, const char* fmt, ...);

/**
 * @struct ByteVC2Param
 * @brief Decoder initialization parameters (ABI size: 0x2c = 44 bytes)
 *        Tham số khởi tạo bộ giải mã (Kích thước ABI: 44 bytes)
 */
struct ByteVC2Param {
    int32_t max_pic_width;         ///< Offset 0x00: Max picture width / Chiều rộng ảnh tối đa
    int32_t max_pic_height;        ///< Offset 0x04: Max picture height / Chiều cao ảnh tối đa
    int32_t max_parallel_frames;   ///< Offset 0x08: Max parallel frames / Khung hình song song tối đa
    int32_t threads;               ///< Offset 0x0c: Worker thread count / Số luồng xử lý
    int32_t output_time;           ///< Offset 0x10: Target output time limit / Thời gian giới hạn xuất
    int32_t output_method;         ///< Offset 0x14: Output queuing mode / Chế độ hàng đợi xuất
    int32_t md5_check;             ///< Offset 0x18: MD5 validation flag / Cờ kiểm tra mã hash MD5
    int32_t wpp_mode;              ///< Offset 0x1c: Wavefront Parallel Processing / Chế độ WPP
    int32_t parallel_frames;       ///< Offset 0x20: Active parallel frames / Khung hình song song kích hoạt
    int32_t advanced_simd;         ///< Offset 0x24: Enable NEON/SVE SIMD / Bật tập lệnh tăng tốc SIMD
    int32_t hardware_buffer;       ///< Offset 0x28: Enable AHardwareBuffer zero-copy / Bật đệm phần cứng không sao chép
};

/**
 * @struct ByteVC2Packet
 * @brief Input compressed bitstream packet (ABI size: 0x38 = 56 bytes)
 *        Gói dữ liệu bitstream nén đầu vào (Kích thước ABI: 56 bytes)
 */
struct ByteVC2Packet {
    int32_t flag;                  ///< Offset 0x00: Packet flags / Cờ điều khiển gói
    int32_t bs_len;                ///< Offset 0x04: Bitstream buffer size in bytes / Độ dài bitstream tính bằng byte
    uint8_t* bs;                   ///< Offset 0x08: Pointer to bitstream payload / Con trỏ đệm bitstream
    int32_t drop_frame;            ///< Offset 0x10: Drop frame indication / Chỉ báo bỏ qua frame
    float drop_rate;               ///< Offset 0x14: Dynamic drop rate ratio / Tỷ lệ bỏ frame động
    int64_t pts;                   ///< Offset 0x18: Presentation timestamp / Nhãn thời gian trình diễn (PTS)
    int64_t opt;                   ///< Offset 0x20: Operation presentation tag / Thẻ vận hành trình diễn
    int64_t simp;                  ///< Offset 0x28: Simplified timestamp tracking / Dấu thời gian giản lược
    int32_t wait_frame;            ///< Offset 0x30: Frame wait synchronization / Đồng bộ chờ khung hình
    int32_t reserved;              ///< Offset 0x34: Padding alignment / Căn lề cấu trúc
};

/**
 * @struct ByteVC2FrameInfoInternal
 * @brief Internal metadata structure attached to frame (ABI size: 0xe0 = 224 bytes)
 *        Cấu trúc siêu dữ liệu nội bộ gắn kèm khung hình (Kích thước ABI: 224 bytes)
 */
typedef struct ByteVC2FrameInfoInternal {
    void* ref_slice_ctx;           ///< Reference slice context / Ngữ cảnh phân đoạn tham chiếu
    void* decoder_core_ref;        ///< Back-reference to decoder context / Con trỏ ngược về bộ giải mã
    uint64_t decode_start_time_us; ///< Start timestamp in microseconds / Thời điểm bắt đầu giải mã
    uint64_t decode_end_time_us;   ///< End timestamp in microseconds / Thời điểm hoàn tất giải mã
    int32_t temporal_layer_id;     ///< VVC temporal sublayer ID / ID lớp thời gian VVC
    int32_t num_slices;            ///< Slice count in current frame / Số phân đoạn trong khung hình
    uint32_t crc_luma;             ///< Luma plane verification CRC / CRC kiểm tra mặt phẳng sáng
    uint32_t crc_chroma;           ///< Chroma plane verification CRC / CRC kiểm tra mặt phẳng màu
    int32_t is_dpb_locked;         ///< DPB lock count for reference / Số khóa tham chiếu trong DPB
    uint8_t padding[184];          ///< Pad to 224 bytes / Độn đủ 224 bytes
} ByteVC2FrameInfoInternal;

/**
 * @struct ByteVC2Frame
 * @brief Output decoded frame buffer structure (ABI size: 0x90 = 144 bytes)
 *        Cấu trúc đệm khung hình đã giải mã (Kích thước ABI: 144 bytes)
 */
struct ByteVC2Frame {
    int32_t width;                 ///< Offset 0x00: Picture width in pixels / Chiều rộng ảnh tính bằng pixel
    int32_t height;                ///< Offset 0x04: Picture height in pixels / Chiều cao ảnh tính bằng pixel
    int64_t pts;                   ///< Offset 0x08: Presentation timestamp / Nhãn thời gian hiển thị PTS
    int64_t opt;                   ///< Offset 0x10: Operation tag / Thẻ vận hành
    int64_t simp;                  ///< Offset 0x18: Simplified presentation mark / Dấu hiển thị giản lược
    int32_t flags;                 ///< Offset 0x20: Frame status flags / Cờ trạng thái frame
    int32_t stride[3];             ///< Offset 0x24: Strides for Y, U, V planes / Bước đệm cho các mặt phẳng Y, U, V
    int32_t linesize[3];           ///< Offset 0x30: Valid line bytes for Y, U, V / Kích thước dòng hữu ích Y, U, V
    uint8_t* data[3];              ///< Offset 0x40: Pointers to Y, U, V buffers / Con trỏ vùng nhớ ảnh Y, U, V
    int32_t crop_x;                ///< Offset 0x58: Conformance cropping left / Cắt cúp khung hình trục X
    int32_t crop_y;                ///< Offset 0x5c: Conformance cropping top / Cắt cúp khung hình trục Y
    void* hardware_buffer;         ///< Offset 0x60: AHardwareBuffer pointer / Con trỏ AHardwareBuffer
    uint8_t bit_depth;             ///< Offset 0x68: Luma/Chroma bitdepth (8, 10) / Độ sâu bit
    uint8_t color_info_present_flag;///< Offset 0x69: Color info presence / Cờ thông tin màu
    uint8_t video_full_range_flag; ///< Offset 0x6a: 0=limited [16..235], 1=full [0..255] / Cờ dải màu đầy đủ
    uint8_t color_primaries;       ///< Offset 0x6b: BT.709, BT.2020, etc. / Hệ màu cơ bản
    uint8_t color_trc;             ///< Offset 0x6c: Transfer characteristics / Đặc tính truyền dẫn bức xạ
    uint8_t color_space;           ///< Offset 0x6d: Matrix coefficients / Không gian ma trận màu
    uint8_t key_frame;             ///< Offset 0x6e: 1 if IDR/CRA/GDR, 0 if Inter / 1 nếu là khung khóa
    uint8_t matrix_flags;          ///< Offset 0x6f: Matrix flags / Cờ ma trận
    uint8_t pix_fmt;               ///< Offset 0x70: Pixel format enum / Định dạng pixel
    uint8_t reserved_byte[3];      ///< Offset 0x71: Padding / Căn lề
    int32_t got_frame;             ///< Offset 0x74: 1 if valid picture decoded / 1 nếu đã giải mã được ảnh hợp lệ
    int32_t poc;                   ///< Offset 0x78: Picture Order Count / Thứ tự hiển thị hình ảnh
    int32_t reserved_int;          ///< Offset 0x7c: Padding / Căn lề
    uint8_t finished_frame_num;    ///< Offset 0x80: Count of decoded frames / Số frame đã hoàn tất giải mã
    uint8_t decodable_frame_num;   ///< Offset 0x81: Count of decodable frames in queue / Số frame sẵn sàng
    uint8_t padding_end[6];        ///< Offset 0x82: Alignment to 0x88 / Độn căn lề đến offset 0x88
    ByteVC2FrameInfoInternal* internal_info; ///< Offset 0x88: Pointer to 224-byte internal info / Con trỏ siêu dữ liệu 224-byte
};

#ifdef __cplusplus
}
#endif

#endif // BYTEVC2_TYPES_H
