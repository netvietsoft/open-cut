/**
 * @file jna_type_conversion.h
 * @brief Clean-Room Header for JNA Type Classification, Marshaling & FFI Type Mapping (`0x0047a8..0x008168`).
 *        Header tái tạo sạch cho Phân loại kiểu JNA, Chuyển đổi dữ liệu và Ánh xạ kiểu FFI (`0x0047a8..0x008168`).
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libjnidispatch.so
 *   Addresses covered / Phạm vi địa chỉ:
 *     - 0x0047a8..0x00481c : throwByName(JNIEnv* env, const char* name, const char* msg)
 *     - 0x004dfc..0x004ef0 : ffi_error(JNIEnv* env, const char* op, ffi_status status)
 *     - 0x004ef4..0x004fa8 : encodingString(JNIEnv* env, const char* encoding)
 *     - 0x004fac..0x00531c : newJavaString(JNIEnv* env, const char* ptr, const char* encoding)
 *     - 0x005320..0x005328 : newCStringUTF8(JNIEnv* env, jstring jstr)
 *     - 0x00532c..0x00537c : newJavaWString(JNIEnv* env, const wchar_t* ptr)
 *     - 0x005380..0x0053b8 : newJavaPointer(JNIEnv* env, void* p)
 *     - 0x0053bc..0x00542c : newJavaStructure(JNIEnv* env, void* p, jclass type, int32_tize)
 *     - 0x005430..0x005488 : newJavaCallback(JNIEnv* env, void* fptr, jclass type)
 *     - 0x00548c..0x0054b4 : get_java_type_from_ffi_type(ffi_type* type)
 *     - 0x0054b8..0x00585c : get_java_type(JNIEnv* env, jclass cls)
 *     - 0x005860..0x0059d4 : get_conversion_flag(JNIEnv* env, jclass cls)
 *     - 0x0059d8..0x005d9c : getIntegerTypeValue..getCallbackAddress
 *     - 0x006cd0..0x007144 : extract_value, toNative, new_object, fromNativeCallbackParam, fromNative
 *     - 0x008004..0x008168 : get_ffi_type, get_ffi_return_type
 */

#ifndef NEXTAI_OPENCUT_JNIDISPATCH_JNA_TYPE_CONVERSION_H_
#define NEXTAI_OPENCUT_JNIDISPATCH_JNA_TYPE_CONVERSION_H_

#include "jnidispatch_types.h"

#include <cstddef>
#include <cstdint>
#include <string>

namespace nextai {
namespace opencut {
namespace jnidispatch {

/**
 * @brief 16 Exported `ffi_type_*` Descriptors [OBSERVED at .rodata 0x022858..0x022990 & .data.rel.ro 0x02bb98..0x02bbe0]
 *        16 bộ mô tả kiểu `ffi_type_*` xuất khẩu [QUAN SÁT ĐƯỢC tại .rodata 0x022858..0x022990]
 */
extern FfiType kFfiTypeLongDouble;         // 0x022858: size=16, align=16, type=4
extern FfiType kFfiTypeDouble;             // 0x022870: size=8,  align=8,  type=3
extern FfiType kFfiTypeFloat;              // 0x022888: size=4,  align=4,  type=2
extern FfiType kFfiTypePointer;            // 0x0228a0: size=8,  align=8,  type=14
extern FfiType kFfiTypeSint64;             // 0x0228b8: size=8,  align=8,  type=12
extern FfiType kFfiTypeUint64;             // 0x0228d0: size=8,  align=8,  type=11
extern FfiType kFfiTypeSint32;             // 0x0228e8: size=4,  align=4,  type=10
extern FfiType kFfiTypeUint32;             // 0x022900: size=4,  align=4,  type=9
extern FfiType kFfiTypeSint16;             // 0x022918: size=2,  align=2,  type=8
extern FfiType kFfiTypeUint16;             // 0x022930: size=2,  align=2,  type=7
extern FfiType kFfiTypeSint8;              // 0x022948: size=1,  align=1,  type=6
extern FfiType kFfiTypeUint8;              // 0x022960: size=1,  align=1,  type=5
extern FfiType kFfiTypeVoid;               // 0x022978: size=1,  align=1,  type=0
extern FfiType kFfiTypeComplexLongDouble;  // 0x02bb98: size=32, align=16, type=15
extern FfiType kFfiTypeComplexDouble;      // 0x02bbb0: size=16, align=8,  type=15
extern FfiType kFfiTypeComplexFloat;       // 0x02bbc8: size=8,  align=4,  type=15

/**
 * @brief Reconstructs `ffi_error` (`0x004dfc..0x004ef0`):
 *        Formats the exact error string and exception class name for a non-zero `ffi_status`.
 *        Tái tạo hàm `ffi_error` (`0x004dfc..0x004ef0`) định dạng thông báo lỗi và lớp ngoại lệ Java.
 *
 * @return true if an error was raised (`status != FFI_OK`), false on `FFI_OK`.
 */
bool FormatFfiError(const char* op,
                    FfiStatus status,
                    std::string* out_exception_class,
                    std::string* out_message);

/**
 * @brief Reconstructs `get_java_type_from_ffi_type` (`0x00548c..0x0054b4`):
 *        Maps an `FfiType*` descriptor to its corresponding JVM descriptor character (`'V'`, `'F'`, `'D'`,
 *        `'B'`, `'S'`, `'I'`, `'J'`, `'P'`, `'s'`).
 *        Tái tạo hàm `get_java_type_from_ffi_type` (`0x00548c..0x0054b4`).
 */
char GetJavaTypeFromFfiType(const FfiType* type) noexcept;

/**
 * @brief Reconstructs `get_java_type` (`0x0054b8..0x00585c`) and `get_conversion_flag` (`0x005860..0x0059d4`):
 *        Classifies a Java class name (`"java.lang.Integer"`, `"com.sun.jna.Pointer"`, `"com.sun.jna.Structure"`, etc.)
 *        into its JVM type character and `JnaConversionFlag`.
 *        Tái tạo hàm `get_java_type` (`0x0054b8`) và `get_conversion_flag` (`0x005860`).
 */
char GetJavaTypeFromClassName(const std::string& class_name) noexcept;
JnaConversionFlag GetConversionFlagFromClassName(const std::string& class_name) noexcept;

/**
 * @brief Reconstructs `get_ffi_type` (`0x008004..0x008130`) and `get_ffi_return_type` (`0x008134..0x008168`):
 *        Maps a JVM type character (`'Z'`, `'B'`, `'C'`, `'S'`, `'I'`, `'J'`, `'F'`, `'D'`, `'V'`, `'*'`)
 *        or `JnaConversionFlag` to the canonical `FfiType*` descriptor.
 *        Tái tạo hàm `get_ffi_type` (`0x008004`) và `get_ffi_return_type` (`0x008134`).
 */
FfiType* GetFfiTypeForJavaType(char java_type, JnaConversionFlag cvt_flag) noexcept;
FfiType* GetFfiReturnTypeForJavaType(char java_type, JnaConversionFlag cvt_flag) noexcept;

/**
 * @brief Reconstructs `Java_com_sun_jna_Native_sizeof` (`0x008a0c..0x008ad0`):
 *        Evaluates the 6-entry `.rodata 0x0201c4` jump table (`[0, 0, 10, 0, 5, 15]`) for `type in 0..5`.
 *        Tái tạo hàm `Java_com_sun_jna_Native_sizeof` (`0x008a0c..0x008ad0`).
 */
int32_t EvaluateJnaNativeSizeof(int32_t type_code, std::string* out_error = nullptr);

/**
 * @brief Reconstructs `extract_value` (`0x006cd0..0x006d70`):
 *        Extracts a scalar primitive or pointer value from a Java wrapper into a 64-bit slot.
 *        Tái tạo hàm `extract_value` (`0x006cd0..0x006d70`).
 */
bool ExtractScalarValue(char java_type,
                        int64_t raw_input,
                        void* out_buffer,
                        size_t out_capacity) noexcept;

}  // namespace jnidispatch
}  // namespace opencut
}  // namespace nextai

#endif  // NEXTAI_OPENCUT_JNIDISPATCH_JNA_TYPE_CONVERSION_H_
