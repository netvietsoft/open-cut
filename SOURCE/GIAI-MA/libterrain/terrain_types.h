// ============================================================================
// File: terrain_types.h
// Target: libterrain.so (336,672 bytes, SHA-256: 556d6d47d9643c641668fd79acb937a8651b5b7c78e80da8bb9307b1171ccd2d)
// Task ID: TASK-136-RECONSTRUCTION-LIBTERRAIN (TASK_SO_062_libterrain)
// EN: Clean-room C++17 ABI data structures, Dalvik bytecode payload layouts,
//     virtual register frame, MBA deobfuscation constants, and JNI class cache
//     reconstructed from AArch64 binary analysis of libterrain.so.
// VN: Các cấu trúc dữ liệu ABI C++17 clean-room, bố cục payload bytecode Dalvik,
//     khung thanh ghi ảo, hằng số giải mã MBA và bộ nhớ đệm lớp JNI được tái tạo
//     từ phân tích nhị phân AArch64 của libterrain.so.
// ============================================================================

#pragma once

#include <cstdint>
#include <cstddef>

namespace nextai {
namespace opencut {
namespace terrain {

// EN: Forward declarations of minimal JNI opaque handles for standalone compilation.
// VN: Khai báo trước các handle mờ JNI tối thiểu để biên dịch độc lập.
using jboolean = uint8_t;
using jbyte    = int8_t;
using jchar    = uint16_t;
using jshort   = int16_t;
using jint     = int32_t;
using jlong    = int64_t;
using jfloat   = float;
using jdouble  = double;
using jobject  = void*;
using jclass   = void*;
using jstring  = void*;
using jarray   = void*;
using jthrowable = void*;
using jmethodID = void*;
using jfieldID  = void*;

// EN: 64-bit union matching JNI jvalue and Dalvik 32/64-bit virtual register pair.
// VN: Union 64-bit khớp với jvalue JNI và cặp thanh ghi ảo 32/64-bit của Dalvik.
union TerrainJValue {
    jboolean z;
    jbyte    b;
    jchar    c;
    jshort   s;
    jint     i;
    jlong    j;
    jfloat   f;
    jdouble  d;
    jobject  l;
    uint64_t raw;
};
static_assert(sizeof(TerrainJValue) == 8, "TerrainJValue must be 8 bytes");

// EN: Dalvik packed-switch payload header (ident == 0x0100 at 0x013060).
// VN: Header payload packed-switch của Dalvik (ident == 0x0100 tại 0x013060).
struct TerrainPackedSwitchPayload {
    uint16_t ident;      // 0x0100 (verified at 0x013060: cmp w8, #0x100)
    uint16_t size;       // Number of entries (ldrh w9, [x19, #2])
    int32_t  first_key;  // Starting switch key (ldr w20, [x19, #4])
    // Followed by int32_t targets[size] at offset +8
};
static_assert(sizeof(TerrainPackedSwitchPayload) == 8, "PackedSwitch header is 8 bytes");

// EN: Dalvik sparse-switch payload header (ident == 0x0200 at 0x01310c).
// VN: Header payload sparse-switch của Dalvik (ident == 0x0200 tại 0x01310c).
struct TerrainSparseSwitchPayload {
    uint16_t ident;      // 0x0200 (verified at 0x01310c: cmp w8, #0x200)
    uint16_t size;       // Number of sorted keys (ldrh w8, [x20, #2])
    // Followed by int32_t keys[size] at +4 and int32_t targets[size] at +4 + size*4
};
static_assert(sizeof(TerrainSparseSwitchPayload) == 4, "SparseSwitch header is 4 bytes");

// EN: Dalvik fill-array-data payload header (ident == 0x0300 at 0x0131e8).
// VN: Header payload fill-array-data của Dalvik (ident == 0x0300 tại 0x0131e8).
struct TerrainArrayDataPayload {
    uint16_t ident;          // 0x0300 (verified at 0x0131e8: cmp w8, #0x300)
    uint16_t element_width;  // 1, 2, 4, or 8 bytes (ldrh w8, [x21, #2])
    uint32_t size;           // Number of elements (ldr w2, [x21, #4])
    // Followed by uint8_t data[size * element_width] at offset +8
};
static_assert(sizeof(TerrainArrayDataPayload) == 8, "ArrayData header is 8 bytes");

// EN: Exception table catch range entry searched by binary search at 0x01231c..0x0123b0.
//     Layout: 3 x int32_t (12 bytes per entry: [start_pc, end_pc, handler_offset]).
// VN: Mục phạm vi bắt ngoại lệ được tìm kiếm nhị phân tại 0x01231c..0x0123b0.
//     Bố cục: 3 x int32_t (12 byte mỗi mục: [start_pc, end_pc, handler_offset]).
struct TerrainCatchRangeEntry {
    uint32_t start_pc;       // Offset +0x00
    uint32_t end_pc;         // Offset +0x04
    uint32_t handler_offset; // Offset +0x08
};
static_assert(sizeof(TerrainCatchRangeEntry) == 12, "CatchRangeEntry must be 12 bytes");

// EN: Exception table header passed to SearchExceptionCatchHandler_01231c (x0).
// VN: Header bảng ngoại lệ được truyền vào SearchExceptionCatchHandler_01231c (x0).
struct TerrainExceptionTable {
    int32_t count;                            // Offset +0x00 (ldrsw x8, [x0])
    int32_t reserved;                         // Offset +0x04
    const uint8_t* sleb128_stream_base;       // Offset +0x08 (used by DecodeSleb128 at 0x0123b4)
    const TerrainCatchRangeEntry* entries;    // Offset +0x10 (Ranges starting at +8 in compact layout)
};

// EN: Method bytecode descriptor passed to exported vmInterpret (0x0133c0).
//     Verified from prologue of vmInterpret (0x0133c0..0x0134f0) and FDE #023 (0x0135ac).
// VN: Bộ mô tả bytecode phương thức truyền vào hàm xuất vmInterpret (0x0133c0).
//     Được xác minh từ phần mở đầu của vmInterpret (0x0133c0..0x0134f0) và FDE #023 (0x0135ac).
struct TerrainVmMethodCode {
    uint16_t registers_size;              // +0x00 (ldrh w8, [x21])
    uint16_t ins_size;                    // +0x02 (ldrh w13, [x21, #2])
    uint16_t outs_size;                   // +0x04
    uint16_t tries_size;                  // +0x06
    uint32_t insns_count;                 // +0x08
    uint32_t flags;                       // +0x0c
    const uint16_t* insns;                // +0x10 (ldr x10, [x21, #0x10] at 0x013904)
    const char* shorty_descriptor;        // +0x18 (ldr x9, [x21, #0x18] at 0x013404)
    const TerrainExceptionTable* tries;   // +0x20 (ldr x0, [x21, #0x20] at 0x014fcc)
    const void* const_pool;               // +0x28
};

// EN: Exported global symbol `gVm` at .bss 0x055b80 (size = 96 bytes = 0x60).
//     Holds JavaVM*, JNI version, and cached runtime hooks initialized in cacheInitial.
// VN: Biểu tượng toàn cục xuất `gVm` tại .bss 0x055b80 (kích thước = 96 byte = 0x60).
//     Lưu trữ JavaVM*, phiên bản JNI và các hook runtime được khởi tạo trong cacheInitial.
struct TerrainGlobalVmState {
    void*    java_vm;                 // +0x00 (0x055b80)
    uint32_t jni_version;             // +0x08 (0x055b88, default 0x00010006 = JNI_VERSION_1_6)
    uint32_t initialized_flag;        // +0x0c (0x055b8c)
    uint64_t vm_lock_state;           // +0x10 (0x055b90)
    void*    class_loader_global_ref; // +0x18 (0x055b98)
    void*    reflect_method_table;    // +0x20 (0x055ba0)
    void*    field_lookup_table;      // +0x28 (0x055ba8)
    void*    string_pool_table;       // +0x30 (0x055bb0)
    void*    exception_hook;          // +0x38 (0x055bb8)
    uint64_t total_invocations;       // +0x40 (0x055bc0)
    uint64_t total_exceptions;        // +0x48 (0x055bc8)
    uint64_t reserved_055bd0;         // +0x50 (0x055bd0)
    uint64_t reserved_055bd8;         // +0x58 (0x055bd8)
};
static_assert(sizeof(TerrainGlobalVmState) == 96, "gVm at 0x055b80 must be exactly 96 bytes");

// EN: Cached JNI classes & primitive TYPE classes populated by cacheInitial (0x02673c..0x0274bc)
//     and queried by getCacheClass (0x0275ec..0x027674) at .bss 0x055be0..0x055ef0.
// VN: Các lớp JNI & lớp TYPE nguyên thủy được lưu đệm bởi cacheInitial (0x02673c..0x0274bc)
//     và được truy vấn bởi getCacheClass (0x0275ec..0x027674) tại .bss 0x055be0..0x055ef0.
struct TerrainJniCache {
    jclass primitive_boolean_type; // 0x055bf8 ('Z' -> target 0x02766c)
    jclass primitive_byte_type;    // 0x055c18 ('B' -> target 0x027618)
    jclass primitive_char_type;    // 0x055c38 ('C' -> target 0x027624)
    jclass primitive_short_type;   // 0x055c58 ('S' -> target 0x027660)
    jclass primitive_int_type;     // 0x055c78 ('I' -> target 0x027648)
    jclass primitive_float_type;   // 0x055c98 ('F' -> target 0x02763c)
    jclass primitive_long_type;    // 0x055cb8 ('J' -> target 0x027654)
    jclass primitive_double_type;  // 0x055cd8 ('D' -> target 0x027630)

    jclass cls_boolean_wrapper;    // java/lang/Boolean
    jclass cls_byte_wrapper;       // java/lang/Byte
    jclass cls_character_wrapper;  // java/lang/Character
    jclass cls_short_wrapper;      // java/lang/Short
    jclass cls_integer_wrapper;    // java/lang/Integer
    jclass cls_float_wrapper;      // java/lang/Float
    jclass cls_long_wrapper;       // java/lang/Long
    jclass cls_double_wrapper;     // java/lang/Double

    jclass cls_no_class_def_found_error;        // java/lang/NoClassDefFoundError
    jclass cls_no_such_field_error;             // java/lang/NoSuchFieldError
    jclass cls_no_such_field_exception;         // java/lang/NoSuchFieldException
    jclass cls_no_such_method_error;            // java/lang/NoSuchMethodError
    jclass cls_null_pointer_exception;          // java/lang/NullPointerException
    jclass cls_arithmetic_exception;            // java/lang/ArithmeticException
    jclass cls_internal_error;                  // java/lang/InternalError
    jclass cls_negative_array_size_exception;   // java/lang/NegativeArraySizeException
    jclass cls_array_index_oob_exception;       // java/lang/ArrayIndexOutOfBoundsException
    jclass cls_class_cast_exception;            // java/lang/ClassCastException
    jclass cls_class_not_found_exception;       // java/lang/ClassNotFoundException
    jclass cls_runtime_exception;               // java/lang/RuntimeException
    bool   is_initialized;
};

// EN: Exact Mixed Boolean-Arithmetic (MBA) constants from FDE #023 (0x0135ac..0x01386c).
// VN: Các hằng số Mixed Boolean-Arithmetic (MBA) chính xác từ FDE #023 (0x0135ac..0x01386c).
constexpr uint64_t kTerrainMbaAnchorVa_0135ac  = 0x00000000000135ACULL;
constexpr uint64_t kTerrainMbaAndMask_013704   = 0x0000010400040400ULL;
constexpr uint64_t kTerrainMbaOrrMask_01372c   = 0x0000000001010104ULL;
constexpr uint64_t kTerrainMbaOrnMaskA_013700  = 0x00A060400A021040ULL;
constexpr uint64_t kTerrainMbaAndMaskB_01370c  = 0x00A061440A061440ULL;
constexpr uint64_t kTerrainMbaXorKey_013748    = 0xFF5F9EBBF47538A4ULL;
constexpr uint64_t kTerrainMbaExpectedDelta    = 0xFFFFFFFFFF722DE0ULL; // -0x008DD220

} // namespace terrain
} // namespace opencut
} // namespace nextai
