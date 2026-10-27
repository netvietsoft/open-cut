/**
 * @file jna_type_conversion.cpp
 * @brief Clean-Room Implementation of JNA Type Classification, Marshaling & FFI Type Mapping (`0x0047a8..0x008168`).
 *        Triển khai tái tạo sạch cho Phân loại kiểu JNA, Chuyển đổi dữ liệu và Ánh xạ kiểu FFI (`0x0047a8..0x008168`).
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libjnidispatch.so
 *   Addresses covered / Phạm vi địa chỉ: 0x0047a8..0x008ad0
 */

#include "jna_type_conversion.h"

#include <cstdio>
#include <cstring>

namespace nextai {
namespace opencut {
namespace jnidispatch {

/**
 * @brief 16 Exported `ffi_type_*` Descriptors [OBSERVED at .rodata 0x022858..0x022990 & .data.rel.ro 0x02bb98..0x02bbe0]
 *        16 bộ mô tả kiểu `ffi_type_*` xuất khẩu [QUAN SÁT ĐƯỢC tại .rodata 0x022858..0x022990]
 */
FfiType kFfiTypeLongDouble        = {16U, 16U, FFI_TYPE_LONGDOUBLE, 0U, nullptr};  // 0x022858
FfiType kFfiTypeDouble            = { 8U,  8U, FFI_TYPE_DOUBLE,     0U, nullptr};  // 0x022870
FfiType kFfiTypeFloat             = { 4U,  4U, FFI_TYPE_FLOAT,      0U, nullptr};  // 0x022888
FfiType kFfiTypePointer           = { 8U,  8U, FFI_TYPE_POINTER,    0U, nullptr};  // 0x0228a0
FfiType kFfiTypeSint64            = { 8U,  8U, FFI_TYPE_SINT64,     0U, nullptr};  // 0x0228b8
FfiType kFfiTypeUint64            = { 8U,  8U, FFI_TYPE_UINT64,     0U, nullptr};  // 0x0228d0
FfiType kFfiTypeSint32            = { 4U,  4U, FFI_TYPE_SINT32,     0U, nullptr};  // 0x0228e8
FfiType kFfiTypeUint32            = { 4U,  4U, FFI_TYPE_UINT32,     0U, nullptr};  // 0x022900
FfiType kFfiTypeSint16            = { 2U,  2U, FFI_TYPE_SINT16,     0U, nullptr};  // 0x022918
FfiType kFfiTypeUint16            = { 2U,  2U, FFI_TYPE_UINT16,     0U, nullptr};  // 0x022930
FfiType kFfiTypeSint8             = { 1U,  1U, FFI_TYPE_SINT8,      0U, nullptr};  // 0x022948
FfiType kFfiTypeUint8             = { 1U,  1U, FFI_TYPE_UINT8,      0U, nullptr};  // 0x022960
FfiType kFfiTypeVoid              = { 1U,  1U, FFI_TYPE_VOID,       0U, nullptr};  // 0x022978
FfiType kFfiTypeComplexLongDouble = {32U, 16U, FFI_TYPE_COMPLEX,    0U, nullptr};  // 0x02bb98
FfiType kFfiTypeComplexDouble     = {16U,  8U, FFI_TYPE_COMPLEX,    0U, nullptr};  // 0x02bbb0
FfiType kFfiTypeComplexFloat      = { 8U,  4U, FFI_TYPE_COMPLEX,    0U, nullptr};  // 0x02bbc8

/**
 * @brief Reconstructs `ffi_error` (`0x004dfc..0x004ef0`):
 *        Maps `FFI_BAD_TYPEDEF (1)`, `FFI_BAD_ABI (2)`, `FFI_BAD_ARGTYPE (3)`, or default error
 *        to the exact `.rodata` format strings (`0x020368..0x020440`) and throws `IllegalArgumentException`
 *        (`0x020398`) or `Error` (`0x020338`).
 *        Tái tạo hàm `ffi_error` (`0x004dfc..0x004ef0`).
 */
bool FormatFfiError(const char* op,
                    FfiStatus status,
                    std::string* out_exception_class,
                    std::string* out_message) {
    if (status == FFI_OK) {
        return false;
    }

    const char* safe_op = (op != nullptr) ? op : "ffi";
    char msg_buf[512];
    const char* exc_cls = "java/lang/IllegalArgumentException";

    switch (status) {
        case FFI_BAD_TYPEDEF:
            // .rodata 0x0203c0
            std::snprintf(msg_buf, sizeof(msg_buf),
                          "%s: Invalid structure definition (native typedef error, FFI_BAD_TYPEDEF)",
                          safe_op);
            break;
        case FFI_BAD_ABI:
            // .rodata 0x020368
            std::snprintf(msg_buf, sizeof(msg_buf),
                          "%s: Invalid calling convention (FFI_BAD_ABI)",
                          safe_op);
            break;
        case FFI_BAD_ARGTYPE:
            // .rodata 0x020410
            std::snprintf(msg_buf, sizeof(msg_buf),
                          "%s: Invalid argument type (FFI_BAD_ARGTYPE)",
                          safe_op);
            break;
        default:
            // .rodata 0x020440 & 0x020338
            exc_cls = "java/lang/Error";
            std::snprintf(msg_buf, sizeof(msg_buf),
                          "%s failed (%d)",
                          safe_op, static_cast<int>(status));
            break;
    }

    if (out_exception_class != nullptr) {
        *out_exception_class = exc_cls;
    }
    if (out_message != nullptr) {
        *out_message = msg_buf;
    }
    return true;
}

/**
 * @brief Reconstructs `get_java_type_from_ffi_type` (`0x00548c..0x0054b4`):
 *        Uses `.rodata` lookup table indexed by `type->type` (`0..14`):
 *          - `FFI_TYPE_VOID (0)`       -> `'V'`
 *          - `FFI_TYPE_FLOAT (2)`      -> `'F'`
 *          - `FFI_TYPE_DOUBLE (3)`     -> `'D'`
 *          - `FFI_TYPE_UINT8/SINT8`    -> `'B'`
 *          - `FFI_TYPE_UINT16/SINT16`  -> `'S'`
 *          - `FFI_TYPE_INT/UINT32/SINT32` -> `'I'`
 *          - `FFI_TYPE_UINT64/SINT64`  -> `'J'`
 *          - `FFI_TYPE_STRUCT (13)`    -> `'s'`
 *          - `FFI_TYPE_POINTER (14)`   -> `'*'`
 *        Tái tạo hàm `get_java_type_from_ffi_type` (`0x00548c..0x0054b4`).
 */
char GetJavaTypeFromFfiType(const FfiType* type) noexcept {
    if (type == nullptr) {
        return 'V';
    }
    switch (type->type) {
        case FFI_TYPE_VOID:       return 'V';
        case FFI_TYPE_INT:        return 'I';
        case FFI_TYPE_FLOAT:      return 'F';
        case FFI_TYPE_DOUBLE:     return 'D';
        case FFI_TYPE_LONGDOUBLE: return 'D';
        case FFI_TYPE_UINT8:
        case FFI_TYPE_SINT8:      return 'B';
        case FFI_TYPE_UINT16:
        case FFI_TYPE_SINT16:     return 'S';
        case FFI_TYPE_UINT32:
        case FFI_TYPE_SINT32:     return 'I';
        case FFI_TYPE_UINT64:
        case FFI_TYPE_SINT64:     return 'J';
        case FFI_TYPE_STRUCT:     return 's';
        case FFI_TYPE_POINTER:    return '*';
        default:                  return 'V';
    }
}

/**
 * @brief Reconstructs `get_java_type` (`0x0054b8..0x00585c`):
 *        Classifies Java primitive/wrapper/JNA class names into JNA's internal type code.
 *        Tái tạo hàm `get_java_type` (`0x0054b8..0x00585c`).
 */
char GetJavaTypeFromClassName(const std::string& class_name) noexcept {
    if (class_name == "void" || class_name == "java.lang.Void" || class_name == "java/lang/Void") {
        return 'V';
    }
    if (class_name == "boolean" || class_name == "java.lang.Boolean" || class_name == "java/lang/Boolean") {
        return 'Z';
    }
    if (class_name == "byte" || class_name == "java.lang.Byte" || class_name == "java/lang/Byte") {
        return 'B';
    }
    if (class_name == "char" || class_name == "java.lang.Character" || class_name == "java/lang/Character") {
        return 'C';
    }
    if (class_name == "short" || class_name == "java.lang.Short" || class_name == "java/lang/Short") {
        return 'S';
    }
    if (class_name == "int" || class_name == "java.lang.Integer" || class_name == "java/lang/Integer") {
        return 'I';
    }
    if (class_name == "long" || class_name == "java.lang.Long" || class_name == "java/lang/Long") {
        return 'J';
    }
    if (class_name == "float" || class_name == "java.lang.Float" || class_name == "java/lang/Float") {
        return 'F';
    }
    if (class_name == "double" || class_name == "java.lang.Double" || class_name == "java/lang/Double") {
        return 'D';
    }
    if (class_name == "com.sun.jna.Structure$ByValue" || class_name == "com/sun/jna/Structure$ByValue") {
        return 's';
    }
    if (class_name == "com.sun.jna.Pointer" || class_name == "com/sun/jna/Pointer" ||
        class_name == "com.sun.jna.Structure" || class_name == "com/sun/jna/Structure" ||
        class_name == "java.lang.String" || class_name == "java/lang/String" ||
        class_name == "com.sun.jna.WString" || class_name == "com/sun/jna/WString" ||
        class_name == "java.nio.Buffer" || class_name == "java/nio/Buffer" ||
        class_name == "com.sun.jna.Callback" || class_name == "com/sun/jna/Callback") {
        return '*';
    }
    return 'L';
}

/**
 * @brief Reconstructs `get_conversion_flag` (`0x005860..0x0059d4`):
 *        Determines the `JnaConversionFlag` (`CVT_*`) for marshaling arguments and return values.
 *        Tái tạo hàm `get_conversion_flag` (`0x005860..0x0059d4`).
 */
JnaConversionFlag GetConversionFlagFromClassName(const std::string& class_name) noexcept {
    if (class_name == "com.sun.jna.Pointer" || class_name == "com/sun/jna/Pointer") {
        return CVT_POINTER;
    }
    if (class_name == "java.lang.String" || class_name == "java/lang/String") {
        return CVT_STRING;
    }
    if (class_name == "com.sun.jna.WString" || class_name == "com/sun/jna/WString") {
        return CVT_WSTRING;
    }
    if (class_name == "com.sun.jna.Structure$ByValue" || class_name == "com/sun/jna/Structure$ByValue") {
        return CVT_STRUCTURE_BYVAL;
    }
    if (class_name == "com.sun.jna.Structure" || class_name == "com/sun/jna/Structure") {
        return CVT_STRUCTURE;
    }
    if (class_name.find("Buffer") != std::string::npos) {
        return CVT_BUFFER;
    }
    if (class_name == "[B") return CVT_ARRAY_BYTE;
    if (class_name == "[S") return CVT_ARRAY_SHORT;
    if (class_name == "[C") return CVT_ARRAY_CHAR;
    if (class_name == "[I") return CVT_ARRAY_INT;
    if (class_name == "[J") return CVT_ARRAY_LONG;
    if (class_name == "[F") return CVT_ARRAY_FLOAT;
    if (class_name == "[D") return CVT_ARRAY_DOUBLE;
    if (class_name == "[Z") return CVT_ARRAY_BOOLEAN;
    if (class_name == "boolean" || class_name == "java.lang.Boolean" || class_name == "java/lang/Boolean") {
        return CVT_BOOLEAN;
    }
    if (class_name == "com.sun.jna.Callback" || class_name == "com/sun/jna/Callback") {
        return CVT_CALLBACK;
    }
    if (class_name == "com.sun.jna.IntegerType" || class_name == "com/sun/jna/IntegerType") {
        return CVT_INTEGER_TYPE;
    }
    if (class_name == "com.sun.jna.PointerType" || class_name == "com/sun/jna/PointerType") {
        return CVT_POINTER_TYPE;
    }
    if (class_name == "com.sun.jna.NativeMapped" || class_name == "com/sun/jna/NativeMapped") {
        return CVT_NATIVE_MAPPED;
    }
    return CVT_DEFAULT;
}

/**
 * @brief Reconstructs `get_ffi_type` (`0x008004..0x008130`):
 *        Maps JNA Java type characters to `FfiType*` pointers.
 *        Tái tạo hàm `get_ffi_type` (`0x008004..0x008130`).
 */
FfiType* GetFfiTypeForJavaType(char java_type, JnaConversionFlag /*cvt_flag*/) noexcept {
    switch (java_type) {
        case 'V': return &kFfiTypeVoid;
        case 'Z': return &kFfiTypeSint32;
        case 'B': return &kFfiTypeSint8;
        case 'C': return &kFfiTypeUint16;
        case 'S': return &kFfiTypeSint16;
        case 'I': return &kFfiTypeSint32;
        case 'J': return &kFfiTypeSint64;
        case 'F': return &kFfiTypeFloat;
        case 'D': return &kFfiTypeDouble;
        case '*':
        case 'L':
        default:  return &kFfiTypePointer;
    }
}

/**
 * @brief Reconstructs `get_ffi_return_type` (`0x008134..0x008168`):
 *        Promotes integer return types smaller than 64-bit (`'Z'`, `'B'`, `'C'`, `'S'`, `'I'`)
 *        to `ffi_type_sint64` (`kFfiTypeSint64`) per libffi return register convention.
 *        Tái tạo hàm `get_ffi_return_type` (`0x008134..0x008168`).
 */
FfiType* GetFfiReturnTypeForJavaType(char java_type, JnaConversionFlag cvt_flag) noexcept {
    switch (java_type) {
        case 'Z':
        case 'B':
        case 'C':
        case 'S':
        case 'I':
            return &kFfiTypeSint64;
        default:
            return GetFfiTypeForJavaType(java_type, cvt_flag);
    }
}

/**
 * @brief Reconstructs `Java_com_sun_jna_Native_sizeof` (`0x008a0c..0x008ad0`):
 *   - 0x008a10: `cmp w2, #5; b.ls #0x8a6c`
 *   - 0x008a6c..0x008a80: `adrp x0, #0x20000; add x0, x0, #0x1c4; ldrb w0, [x0, w2, uxtw]; adr x1, #0x8a84; add x0, x1, w0, sxtb #2; br x0`
 *   - Jump table at `.rodata 0x0201c4`: `[0, 0, 10, 0, 5, 15]`
 *     - `type = 0, 1, 3` -> `offset 0 * 4 = +0`  (`0x008a84`: `mov w0, #8`)
 *     - `type = 4`       -> `offset 5 * 4 = +20` (`0x008a98`: `mov w0, #1`)
 *     - `type = 2`       -> `offset 10 * 4 = +40`(`0x008aac`: `mov w0, #4`)
 *     - `type = 5`       -> `offset 15 * 4 = +60`(`0x008ac0`: `mov w0, #0x10`)
 *   Tái tạo hàm `Java_com_sun_jna_Native_sizeof` (`0x008a0c..0x008ad0`).
 */
int32_t EvaluateJnaNativeSizeof(int32_t type_code, std::string* out_error) {
    if (static_cast<uint32_t>(type_code) > 5U) {
        if (out_error != nullptr) {
            char buf[128];
            std::snprintf(buf, sizeof(buf), "Invalid sizeof type %d", type_code);
            *out_error = buf;
        }
        return -1;
    }

    constexpr uint8_t kJumpTable[6] = {0U, 0U, 10U, 0U, 5U, 15U};
    switch (kJumpTable[type_code]) {
        case 0U:  return 8;   // void*, long, size_t on LP64 AArch64
        case 5U:  return 1;   // bool
        case 10U: return 4;   // wchar_t (32-bit on Linux/Android)
        case 15U: return 16;  // long double (128-bit IEEE quad on AArch64)
        default:  return -1;
    }
}

/**
 * @brief Reconstructs `extract_value` (`0x006cd0..0x006d70`):
 *        Stores a scalar value into the native argument slot according to its `java_type`.
 *        Tái tạo hàm `extract_value` (`0x006cd0..0x006d70`).
 */
bool ExtractScalarValue(char java_type,
                        int64_t raw_input,
                        void* out_buffer,
                        size_t out_capacity) noexcept {
    if (out_buffer == nullptr || out_capacity < 8U) {
        return false;
    }
    switch (java_type) {
        case 'Z': {
            const int32_t v = (raw_input != 0) ? 1 : 0;
            std::memcpy(out_buffer, &v, sizeof(v));
            return true;
        }
        case 'B': {
            const auto v = static_cast<int8_t>(raw_input);
            std::memcpy(out_buffer, &v, sizeof(v));
            return true;
        }
        case 'C': {
            const auto v = static_cast<uint16_t>(raw_input);
            std::memcpy(out_buffer, &v, sizeof(v));
            return true;
        }
        case 'S': {
            const auto v = static_cast<int16_t>(raw_input);
            std::memcpy(out_buffer, &v, sizeof(v));
            return true;
        }
        case 'I': {
            const auto v = static_cast<int32_t>(raw_input);
            std::memcpy(out_buffer, &v, sizeof(v));
            return true;
        }
        case 'J':
        case '*': {
            std::memcpy(out_buffer, &raw_input, sizeof(raw_input));
            return true;
        }
        default:
            return false;
    }
}

}  // namespace jnidispatch
}  // namespace opencut
}  // namespace nextai
