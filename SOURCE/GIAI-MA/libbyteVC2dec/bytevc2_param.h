/**
 * @file bytevc2_param.h
 * @brief Decoder Parameter Configuration and Management for ByteVC2
 *        Quản lý và cấu hình tham số giải mã cho ByteVC2
 *
 * Implements param allocation, defaults, string-based property setters matching libbyteVC2dec.so.
 * Thực thi cấp phát tham số, giá trị mặc định và thiết lập thuộc tính theo chuỗi khớp libbyteVC2dec.so.
 */

#ifndef BYTEVC2_PARAM_H
#define BYTEVC2_PARAM_H

#include "bytevc2_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Allocate and initialize default parameters for ByteVC2 decoder
 *        Cấp phát và khởi tạo tham số mặc định cho bộ giải mã ByteVC2
 * @return Pointer to newly allocated ByteVC2Param or NULL on failure
 *         Con trỏ tới ByteVC2Param mới cấp phát hoặc NULL nếu thất bại
 */
ByteVC2Param* byteVC2dec_get_default_param(void);

/**
 * @brief Release allocated parameter structure
 *        Giải phóng cấu trúc tham số đã cấp phát
 * @param param Pointer to parameter structure / Con trỏ cấu trúc tham số
 */
void byteVC2dec_release_param(ByteVC2Param* param);

/**
 * @brief Print formatted parameter values to log
 *        In các giá trị tham số đã định dạng ra nhật ký
 * @param param Pointer to parameter structure / Con trỏ cấu trúc tham số
 */
void byteVC2dec_print_param(const ByteVC2Param* param);

/**
 * @brief Set integer parameter value by string key
 *        Thiết lập giá trị tham số kiểu số nguyên bằng khóa chuỗi
 * @param param Pointer to parameter structure / Con trỏ cấu trúc tham số
 * @param key Null-terminated parameter name / Tên tham số kết thúc bằng null
 * @param value Integer value to set / Giá trị nguyên cần gán
 * @return 0 on success, -1 on invalid key or NULL param
 *         0 nếu thành công, -1 nếu sai khóa hoặc con trỏ rỗng
 */
int32_t byteVC2dec_set_param_integer_info(ByteVC2Param* param, const char* key, int32_t value);

/**
 * @brief Set floating-point parameter value by string key
 *        Thiết lập giá trị tham số kiểu số thực dấu phẩy động bằng khóa chuỗi
 * @param param Pointer to parameter structure / Con trỏ cấu trúc tham số
 * @param key Null-terminated parameter name / Tên tham số
 * @param value Float value to set / Giá trị thực cần gán
 * @return Always returns -1 (Not supported in ByteVC2 ABI) / Luôn trả về -1 (Không hỗ trợ)
 */
int32_t byteVC2dec_set_param_float_info(ByteVC2Param* param, const char* key, float value);

/**
 * @brief Set pointer parameter value by string key
 *        Thiết lập giá trị tham số dạng con trỏ bằng khóa chuỗi
 * @param param Pointer to parameter structure / Con trỏ cấu trúc tham số
 * @param key Null-terminated parameter name / Tên tham số
 * @param ptr Pointer value to set / Con trỏ cần gán
 * @return Always returns -1 (Not supported in ByteVC2 ABI) / Luôn trả về -1 (Không hỗ trợ)
 */
int32_t byteVC2dec_set_param_pointer_info(ByteVC2Param* param, const char* key, void* ptr);

#ifdef __cplusplus
}
#endif

#endif // BYTEVC2_PARAM_H
