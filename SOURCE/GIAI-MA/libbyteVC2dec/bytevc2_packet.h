/**
 * @file bytevc2_packet.h
 * @brief Input Compressed Packet Management for ByteVC2
 *        Quản lý gói nén bitstream đầu vào cho ByteVC2
 *
 * Implements packet allocation, lifecycle, and property setters matching libbyteVC2dec.so.
 * Thực thi cấp phát gói, vòng đời và gán thuộc tính khớp với libbyteVC2dec.so.
 */

#ifndef BYTEVC2_PACKET_H
#define BYTEVC2_PACKET_H

#include "bytevc2_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Allocate a new bitstream packet structure
 *        Cấp phát một cấu trúc gói bitstream mới
 * @return Pointer to ByteVC2Packet or NULL
 *         Con trỏ tới ByteVC2Packet hoặc NULL
 */
ByteVC2Packet* byteVC2dec_alloc_packet(void);

/**
 * @brief Release bitstream packet and any attached memory
 *        Giải phóng gói bitstream và bộ nhớ đính kèm
 * @param packet Pointer to packet to release / Con trỏ gói cần giải phóng
 */
void byteVC2dec_release_packet(ByteVC2Packet* packet);

/**
 * @brief Set integer metadata field on packet
 *        Thiết lập trường siêu dữ liệu số nguyên cho gói
 * @param packet Pointer to packet / Con trỏ gói
 * @param key Metadata key name / Tên khóa siêu dữ liệu
 * @param value Integer value / Giá trị nguyên
 * @return 0 on success, -1 on invalid key or NULL packet
 *         0 nếu thành công, -1 nếu sai khóa hoặc con trỏ rỗng
 */
int32_t byteVC2dec_set_packet_integer_info(ByteVC2Packet* packet, const char* key, int64_t value);

/**
 * @brief Set floating-point metadata field on packet (e.g. drop_rate)
 *        Thiết lập trường số thực dấu phẩy động cho gói (ví dụ drop_rate)
 * @param packet Pointer to packet / Con trỏ gói
 * @param key Metadata key name / Tên khóa siêu dữ liệu
 * @param value Floating-point ratio / Tỷ lệ số thực
 * @return 0 on success, -1 on failure
 *         0 nếu thành công, -1 nếu thất bại
 */
int32_t byteVC2dec_set_packet_float_info(ByteVC2Packet* packet, const char* key, float value);

/**
 * @brief Set pointer field on packet (e.g. "bs" bitstream buffer)
 *        Thiết lập trường con trỏ cho gói (ví dụ vùng đệm bitstream "bs")
 * @param packet Pointer to packet / Con trỏ gói
 * @param key Metadata key name ("bs") / Tên khóa siêu dữ liệu ("bs")
 * @param ptr Pointer to data / Con trỏ dữ liệu
 * @return 0 on success, -1 on failure
 *         0 nếu thành công, -1 nếu thất bại
 */
int32_t byteVC2dec_set_packet_pointer_info(ByteVC2Packet* packet, const char* key, void* ptr);

#ifdef __cplusplus
}
#endif

#endif // BYTEVC2_PACKET_H
