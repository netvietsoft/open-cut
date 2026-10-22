/**
 * @file bytevc2_core.h
 * @brief ByteDance ByteVC2 (H.266/VVC) Video Decoder Core Pipeline Engine
 *        Động cơ đường ống lõi bộ giải mã video ByteDance ByteVC2 (H.266/VVC)
 *
 * Implements main decoder lifecycle, packet queuing, picture reconstruction, and status reporting.
 * Thực thi vòng đời bộ giải mã, xếp hàng gói tin, tái dựng khung hình và báo cáo trạng thái.
 */

#ifndef BYTEVC2_CORE_H
#define BYTEVC2_CORE_H

#include "bytevc2_types.h"
#include "bytevc2_param.h"
#include "bytevc2_packet.h"
#include "bytevc2_frame.h"
#include "bytevc2_dpb.h"
#include "bytevc2_hls.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @struct ByteVC2Context
 * @brief Main decoder runtime context structure (ABI size: 0x7b8 = 1976 bytes)
 *        Cấu trúc ngữ cảnh thực thi bộ giải mã chính (Kích thước ABI: 1976 bytes)
 */
struct ByteVC2Context {
    ByteVC2Param params;           ///< Active configuration parameters / Tham số cấu hình đang kích hoạt
    ByteVC2Dpb dpb;                ///< Decoded Picture Buffer / Bộ đệm hình ảnh giải mã
    ByteVC2Sps active_sps;         ///< Currently active SPS / SPS đang áp dụng
    ByteVC2Pps active_pps;         ///< Currently active PPS / PPS đang áp dụng
    int32_t state;                 ///< Decoder operational state / Trạng thái vận hành bộ giải mã
    int32_t cur_poc;               ///< Current decoding POC / POC đang giải mã
    int64_t total_decoded_frames;  ///< Total pictures decoded / Tổng số khung hình đã giải mã
    int64_t total_dropped_frames;  ///< Total pictures dropped / Tổng số khung hình bị bỏ qua
    int64_t total_output_frames;   ///< Total pictures outputted / Tổng số khung hình đã xuất
    ByteVC2Packet* pending_packet; ///< Pending bitstream packet / Gói bitstream đang chờ
    void* mutex;                   ///< Thread synchronization lock / Khóa đồng bộ luồng
    uint8_t opaque_buffer[1500];   ///< Internal decoding scratchpads / Vùng nhớ nháp giải mã nội bộ
};

/**
 * @brief Retrieve decoder version string
 *        Lấy chuỗi phiên bản bộ giải mã
 *
 * Exported C API matching ARM64 symbol 'byteVC2dec_get_version' at VAddr 0x00004b30.
 * Writes 8 bytes "0.8.1.3\0" to version_out.
 *
 * @param version_out Output buffer of at least 8 bytes / Bộ đệm đầu ra tối thiểu 8 bytes
 */
void byteVC2dec_get_version(char* version_out);

/**
 * @brief Set global diagnostic log callback and severity threshold
 *        Thiết lập hàm gọi lại nhật ký và ngưỡng mức độ ghi log toàn cục
 *
 * Exported C API matching ARM64 symbol 'byteVC2_set_log_callback' at VAddr 0x00002988.
 *
 * @param cb Log callback function pointer / Con trỏ hàm gọi lại nhật ký
 * @param opaque User context pointer / Con trỏ ngữ cảnh người dùng
 * @param level Minimum log severity level / Mức độ nhật ký tối thiểu
 */
void byteVC2_set_log_callback(ByteVC2LogCallback cb, void* opaque, int32_t level);

/**
 * @brief Create and initialize a new ByteVC2 decoder instance
 *        Tạo mới và khởi tạo một thực thể bộ giải mã ByteVC2
 *
 * Exported C API matching ARM64 symbol 'byteVC2dec_create' at VAddr 0x00004d38.
 *
 * @param param Pointer to configuration parameters / Con trỏ tham số cấu hình
 * @return Pointer to allocated ByteVC2Context or NULL on failure
 *         Con trỏ tới ByteVC2Context đã cấp phát hoặc NULL khi thất bại
 */
ByteVC2Context* byteVC2dec_create(ByteVC2Param* param);

/**
 * @brief Reconfigure active decoder instance with new parameters
 *        Tái cấu hình thực thể bộ giải mã với các tham số mới
 *
 * Exported C API matching ARM64 symbol 'byteVC2dec_reconfig' at VAddr 0x00004fa4.
 *
 * @param ctx Decoder context / Ngữ cảnh bộ giải mã
 * @param param Updated parameter set / Tập tham số cập nhật
 * @return 0 on success, -1 on failure / 0 nếu thành công, -1 nếu thất bại
 */
int32_t byteVC2dec_reconfig(ByteVC2Context* ctx, const ByteVC2Param* param);

/**
 * @brief Destroy decoder instance and release all internal buffers
 *        Hủy thực thể bộ giải mã và giải phóng toàn bộ vùng đệm nội bộ
 *
 * Exported C API matching ARM64 symbol 'byteVC2dec_destroy' at VAddr 0x00005188.
 *
 * @param ctx Decoder context to destroy / Ngữ cảnh bộ giải mã cần hủy
 */
void byteVC2dec_destroy(ByteVC2Context* ctx);

/**
 * @brief Send compressed bitstream packet into decoder input queue
 *        Gửi gói dữ liệu bitstream nén vào hàng đợi đầu vào của bộ giải mã
 *
 * Exported C API matching ARM64 symbol 'byteVC2dec_send_packet' at VAddr 0x00030630.
 *
 * @param ctx Decoder context / Ngữ cảnh bộ giải mã
 * @param pkt Bitstream packet to decode / Gói bitstream cần giải mã
 * @return 0 on success, -1 on error / 0 nếu thành công, -1 nếu lỗi
 */
int32_t byteVC2dec_send_packet(ByteVC2Context* ctx, ByteVC2Packet* pkt);

/**
 * @brief Decode bitstream packet directly into destination frame
 *        Giải mã gói bitstream trực tiếp vào khung hình đích
 *
 * Exported C API matching ARM64 symbol 'byteVC2dec_decode' at VAddr 0x0003035c.
 *
 * @param ctx Decoder context / Ngữ cảnh bộ giải mã
 * @param pkt Input packet / Gói đầu vào
 * @param out_frame Destination frame buffer / Đệm khung hình đích
 * @return 0 on success, negative status code on failure
 *         0 nếu thành công, mã âm khi thất bại
 */
int32_t byteVC2dec_decode(ByteVC2Context* ctx, ByteVC2Packet* pkt, ByteVC2Frame* out_frame);

/**
 * @brief Retrieve next ready picture from Decoded Picture Buffer (DPB)
 *        Lấy khung hình sẵn sàng kế tiếp từ bộ đệm DPB
 *
 * Exported C API matching ARM64 symbol 'byteVC2dec_get_frame' at VAddr 0x0003074c.
 *
 * @param ctx Decoder context / Ngữ cảnh bộ giải mã
 * @param out_frame Frame container receiving picture metadata and plane pointers
 *                  Bộ chứa nhận siêu dữ liệu ảnh và con trỏ các mặt phẳng
 * @return 0 on success (frame available), -1 if no frame ready
 *         0 nếu thành công (có khung hình), -1 nếu chưa có khung hình sẵn sàng
 */
int32_t byteVC2dec_get_frame(ByteVC2Context* ctx, ByteVC2Frame* out_frame);

/**
 * @brief Return displayed frame back to decoder DPB pool for recycling
 *        Hoàn trả khung hình đã hiển thị về nhóm đệm DPB để tái sử dụng
 *
 * Exported C API matching ARM64 symbol 'byteVC2dec_return_frame' at VAddr 0x000308f8.
 *
 * @param ctx Decoder context / Ngữ cảnh bộ giải mã
 * @param frame Frame being returned / Khung hình hoàn trả
 * @return 0 on success, -1 on failure / 0 nếu thành công, -1 nếu thất bại
 */
int32_t byteVC2dec_return_frame(ByteVC2Context* ctx, ByteVC2Frame* frame);

/**
 * @brief Flush decoder pipeline and drain remaining queued pictures
 *        Xả đường ống giải mã và rút cạn các khung hình còn lưu trong hàng đợi
 *
 * Exported C API matching ARM64 symbol 'byteVC2dec_flush' at VAddr 0x0002ff48.
 *
 * @param ctx Decoder context / Ngữ cảnh bộ giải mã
 * @param flush_mode 1 for immediate drain, 0 for soft finish
 *                   1 để xả cạn lập tức, 0 để kết thúc êm dịu
 * @return 0 on success, -1 on failure / 0 nếu thành công, -1 nếu thất bại
 */
int32_t byteVC2dec_flush(ByteVC2Context* ctx, int32_t flush_mode);

/**
 * @brief Dump formatted video sequence parameters to string buffer
 *        Xuất các tham số chuỗi video đã định dạng ra bộ đệm chuỗi
 *
 * Exported C API matching ARM64 symbol 'byteVC2dec_dump_video_info' at VAddr 0x000051c0.
 *
 * @param ctx Decoder context / Ngữ cảnh bộ giải mã
 * @param buf Output string buffer / Bộ đệm chuỗi đầu ra
 * @param buf_len Buffer capacity / Dung lượng bộ đệm
 * @return Number of characters written or -1 on error
 *         Số ký tự đã ghi hoặc -1 nếu lỗi
 */
int32_t byteVC2dec_dump_video_info(const ByteVC2Context* ctx, char* buf, int32_t buf_len);

/**
 * @brief Dump runtime performance metrics and buffer counts
 *        Xuất các chỉ số hiệu năng thực thi và số lượng bộ đệm
 *
 * Exported C API matching ARM64 symbol 'byteVC2dec_dump_decoding_status' at VAddr 0x0000530c.
 *
 * @param ctx Decoder context / Ngữ cảnh bộ giải mã
 * @param buf Output string buffer / Bộ đệm chuỗi đầu ra
 * @param buf_len Buffer capacity / Dung lượng bộ đệm
 * @return Number of characters written or -1 on error
 *         Số ký tự đã ghi hoặc -1 nếu lỗi
 */
int32_t byteVC2dec_dump_decoding_status(const ByteVC2Context* ctx, char* buf, int32_t buf_len);

#ifdef __cplusplus
}
#endif

#endif // BYTEVC2_CORE_H
