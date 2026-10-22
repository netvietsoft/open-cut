/**
 * @file bytevc2_dpb.h
 * @brief Decoded Picture Buffer (DPB) and Reference Queue Management for ByteVC2
 *        Quản lý bộ đệm hình ảnh giải mã (DPB) và hàng đợi tham chiếu cho ByteVC2
 *
 * Implements picture buffering, POC reordering, reference picture tracking, and buffer recycling.
 * Thực thi đệm khung hình, sắp xếp lại theo POC, theo dõi ảnh tham chiếu và tái chế đệm.
 */

#ifndef BYTEVC2_DPB_H
#define BYTEVC2_DPB_H

#include "bytevc2_types.h"
#include "bytevc2_frame.h"

#ifdef __cplusplus
extern "C" {
#endif

#define BYTEVC2_MAX_DPB_SIZE 16

/**
 * @struct ByteVC2DpbEntry
 * @brief Individual entry in the Decoded Picture Buffer
 *        Một phần tử riêng lẻ trong bộ đệm DPB
 */
typedef struct ByteVC2DpbEntry {
    ByteVC2Frame* frame;           ///< Frame buffer container / Bộ chứa khung hình
    int32_t poc;                   ///< Picture Order Count / Thứ tự hiển thị
    int64_t pts;                   ///< Presentation timestamp / Dấu thời gian hiển thị
    bool is_reference;             ///< Marked for long-term or short-term reference / Đánh dấu tham chiếu
    bool is_outputted;             ///< Already emitted to consumer / Đã xuất ra bên ngoài
    bool in_use;                   ///< Slot active in DPB / Ô nhớ đang hoạt động
    int32_t ref_count;             ///< Active consumer references / Số lượng tham chiếu đang giữ
} ByteVC2DpbEntry;

/**
 * @struct ByteVC2Dpb
 * @brief DPB manager managing picture pools and display reordering
 *        Bộ điều phối DPB quản lý nhóm bộ đệm ảnh và sắp xếp hiển thị
 */
typedef struct ByteVC2Dpb {
    ByteVC2DpbEntry entries[BYTEVC2_MAX_DPB_SIZE]; ///< Array of frame slots / Mảng các ô nhớ frame
    int32_t max_size;              ///< Maximum capacity / Dung lượng tối đa
    int32_t current_size;          ///< Current active pictures / Số ảnh đang giữ
    int32_t max_num_reorder_pics;  ///< Reordering limit / Giới hạn khung hình sắp xếp lại
    int32_t last_output_poc;       ///< Last emitted POC / POC xuất ra gần nhất
} ByteVC2Dpb;

/**
 * @brief Initialize Decoded Picture Buffer
 *        Khởi tạo bộ đệm DPB
 * @param dpb Pointer to DPB structure / Con trỏ cấu trúc DPB
 * @param max_size Capacity limit (<= 16) / Giới hạn dung lượng
 */
void bytevc2_dpb_init(ByteVC2Dpb* dpb, int32_t max_size);

/**
 * @brief Release all frame buffers in DPB
 *        Giải phóng toàn bộ đệm khung hình trong DPB
 * @param dpb Pointer to DPB structure / Con trỏ cấu trúc DPB
 */
void bytevc2_dpb_release(ByteVC2Dpb* dpb);

/**
 * @brief Insert newly decoded picture into DPB
 *        Đưa ảnh vừa giải mã vào bộ đệm DPB
 * @param dpb Pointer to DPB / Con trỏ DPB
 * @param frame Decoded frame / Khung hình đã giải mã
 * @param poc Picture Order Count / Thứ tự ảnh
 * @param pts Presentation timestamp / Nhãn thời gian hiển thị
 * @param is_ref Whether frame is reference / Cờ ảnh tham chiếu
 * @return 0 on success, -1 if DPB full / 0 nếu thành công, -1 nếu DPB đầy
 */
int32_t bytevc2_dpb_insert(ByteVC2Dpb* dpb, ByteVC2Frame* frame, int32_t poc, int64_t pts, bool is_ref);

/**
 * @brief Pop earliest picture ready for display (lowest un-outputted POC)
 *        Lấy ra khung hình sẵn sàng hiển thị sớm nhất (POC thấp nhất chưa xuất)
 * @param dpb Pointer to DPB / Con trỏ DPB
 * @return Pointer to ready frame or NULL / Con trỏ khung hình sẵn sàng hoặc NULL
 */
ByteVC2Frame* bytevc2_dpb_get_display_frame(ByteVC2Dpb* dpb);

/**
 * @brief Return displayed frame to DPB pool for recycling
 *        Hoàn trả khung hình đã hiển thị về nhóm đệm để tái sử dụng
 * @param dpb Pointer to DPB / Con trỏ DPB
 * @param frame Frame to return / Khung hình hoàn trả
 * @return 0 on success, -1 on invalid frame / 0 nếu thành công, -1 nếu sai khung hình
 */
int32_t bytevc2_dpb_return_frame(ByteVC2Dpb* dpb, ByteVC2Frame* frame);

/**
 * @brief Flush all remaining un-outputted pictures
 *        Xả toàn bộ các khung hình chưa xuất còn lại
 * @param dpb Pointer to DPB / Con trỏ DPB
 */
void bytevc2_dpb_flush(ByteVC2Dpb* dpb);

#ifdef __cplusplus
}
#endif

#endif // BYTEVC2_DPB_H
