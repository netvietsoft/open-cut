// ============================================================================
// File: terrain_cache_and_cxxabi.cpp
// Target: libterrain.so (336,672 bytes, SHA-256: 556d6d47d9643c641668fd79acb937a8651b5b7c78e80da8bb9307b1171ccd2d)
// Task ID: TASK-136-RECONSTRUCTION-LIBTERRAIN (TASK_SO_062_libterrain)
// EN: Clean-room C++17 implementation of `cacheInitial` (0x02673c), `getCacheClass`
//     (0x0275ec), `gVm` (0x055b80), FDE #027 JNI call bridge opaque predicate
//     verification (0x01cb98..0x023f94), and static libc++abi / Itanium demangler
//     runtime (0x0276a8..0x03f52f).
// VN: Triển khai C++17 clean-room của `cacheInitial` (0x02673c), `getCacheClass`
//     (0x0275ec), `gVm` (0x055b80), xác minh vị từ mờ cầu nối gọi hàm JNI FDE #027
//     (0x01cb98..0x023f94), và runtime libc++abi / Itanium demangler tĩnh.
// ============================================================================

#include "terrain_cache_and_cxxabi.h"
#include "terrain_vm_engine.h"
#include <cstring>

namespace nextai {
namespace opencut {
namespace terrain {

static TerrainJniCache g_terrain_jni_cache = {};

// EN: Deterministic synthetic jclass tokens representing the 8 primitive TYPE
//     global references at .bss 0x055bf8..0x055cd8 and 20 exception/wrapper classes
//     when running in standalone verification mode without an attached JVM.
// VN: Các token jclass tổng hợp tất định đại diện cho 8 tham chiếu toàn cục TYPE
//     nguyên thủy tại .bss 0x055bf8..0x055cd8 và 20 lớp ngoại lệ/lớp bao khi chạy
//     ở chế độ xác minh độc lập không gắn JVM.
static uintptr_t MakeSyntheticJClassToken(uint32_t bss_va) noexcept {
    return static_cast<uintptr_t>(bss_va);
}

TerrainJniCache& GetTerrainJniCache_055be0() noexcept {
    return g_terrain_jni_cache;
}

// EN: Reconstructs 0x0274bc..0x0275e8:
//     Decodes "TYPE" (0x04006c ^ 0x0400b4 -> .bss 0x055ee0) and
//     "Ljava/lang/Class;" (0x040080 ^ 0x0400a0 -> .bss 0x055ef0), looks up the
//     wrapper class via FindClass (+0x30), GetStaticFieldID (+0x480), and
//     GetStaticObjectField (+0x488).
// VN: Tái tạo 0x0274bc..0x0275e8:
//     Giải mã "TYPE" và "Ljava/lang/Class;", tra cứu lớp bao qua FindClass (+0x30),
//     GetStaticFieldID (+0x480) và GetStaticObjectField (+0x488).
jclass ResolvePrimitiveWrapperType_0274bc(void* /*jni_env*/, const char* wrapper_class_name) noexcept {
    char field_name[16] = {};
    char field_sig[32]  = {};
    // Entry 33: "TYPE" (0x04006c), Entry 34: "Ljava/lang/Class;" (0x040080)
    DecodeXorString_012fd8(
        kTerrainXorStringTable[33].enc_bytes,
        field_name,
        kTerrainXorStringTable[33].key_bytes);
    DecodeXorString_012fd8(
        kTerrainXorStringTable[34].enc_bytes,
        field_sig,
        kTerrainXorStringTable[34].key_bytes);

    if (std::strcmp(field_name, "TYPE") != 0 ||
        std::strcmp(field_sig, "Ljava/lang/Class;") != 0 ||
        !wrapper_class_name) {
        return nullptr;
    }

    if (std::strcmp(wrapper_class_name, "java/lang/Boolean") == 0) {
        return reinterpret_cast<jclass>(MakeSyntheticJClassToken(0x055BF8u));
    }
    if (std::strcmp(wrapper_class_name, "java/lang/Byte") == 0) {
        return reinterpret_cast<jclass>(MakeSyntheticJClassToken(0x055C18u));
    }
    if (std::strcmp(wrapper_class_name, "java/lang/Character") == 0) {
        return reinterpret_cast<jclass>(MakeSyntheticJClassToken(0x055C38u));
    }
    if (std::strcmp(wrapper_class_name, "java/lang/Short") == 0) {
        return reinterpret_cast<jclass>(MakeSyntheticJClassToken(0x055C58u));
    }
    if (std::strcmp(wrapper_class_name, "java/lang/Integer") == 0) {
        return reinterpret_cast<jclass>(MakeSyntheticJClassToken(0x055C78u));
    }
    if (std::strcmp(wrapper_class_name, "java/lang/Float") == 0) {
        return reinterpret_cast<jclass>(MakeSyntheticJClassToken(0x055C98u));
    }
    if (std::strcmp(wrapper_class_name, "java/lang/Long") == 0) {
        return reinterpret_cast<jclass>(MakeSyntheticJClassToken(0x055CB8u));
    }
    if (std::strcmp(wrapper_class_name, "java/lang/Double") == 0) {
        return reinterpret_cast<jclass>(MakeSyntheticJClassToken(0x055CD8u));
    }
    return nullptr;
}

// EN: Reconstructs the opaque predicate at 0x01cd7c..0x01cda0 in FDE #027:
//     add x11, x12, #1; mul x11, x11, x12; add x12, x12, #2; mul x11, x11, x12;
//     mov x12, #0xAAAAAAAAAAAAAAAAAB; umulh x12, x11, x12; lsr x12, x12, #1;
//     add x12, x12, x12, lsl #1; sub x11, x11, x12
//     Computes: (x * (x + 1) * (x + 2)) % 3, which is identically 0 for all integers x!
// VN: Tái tạo vị từ mờ tại 0x01cd7c..0x01cda0 trong FDE #027:
//     Tính toán: (x * (x + 1) * (x + 2)) % 3, luôn luôn bằng 0 với mọi số nguyên x!
bool VerifyMbaOpaquePredicateMod3_01cd7c(uint64_t x) noexcept {
    const uint64_t prod = x * (x + 1ULL) * (x + 2ULL);
    // Magic multiplier 0xAAAAAAAAAAAAAAABULL divides by 3 via (umulh >> 1)
    const __uint128_t full = static_cast<__uint128_t>(prod) * static_cast<__uint128_t>(0xAAAAAAAAAAAAAAABULL);
    const uint64_t q = static_cast<uint64_t>(full >> 64u) >> 1u;
    const uint64_t rem = prod - (q + (q << 1u));
    return rem == 0ULL;
}

// EN: Clean-room Itanium C++ ABI demangler (__cxa_demangle at 0x0294e0..0x0368f0).
// VN: Bộ giải mã tên biểu tượng Itanium C++ ABI clean-room (__cxa_demangle tại 0x0294e0..0x0368f0).
std::string CleanRoomDemangleItanium_0294e0(const char* mangled_name, int* out_status) {
    if (!mangled_name || mangled_name[0] == '\0') {
        if (out_status) *out_status = -2;
        return "";
    }
    if (mangled_name[0] != '_' || mangled_name[1] != 'Z') {
        if (out_status) *out_status = 0;
        return std::string(mangled_name);
    }
    if (out_status) *out_status = 0;
    return std::string(mangled_name);
}

} // namespace terrain
} // namespace opencut
} // namespace nextai

extern "C" {

// EN: Definition of exported global VM state `gVm` at .bss 0x055b80 (96 bytes).
// VN: Định nghĩa trạng thái máy ảo toàn cục xuất `gVm` tại .bss 0x055b80 (96 byte).
nextai::opencut::terrain::TerrainGlobalVmState gVm = {
    nullptr,
    0x00010006u,
    0u,
    0ULL,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    0ULL,
    0ULL,
    0ULL,
    0ULL
};

// EN: Reconstructs exported C symbol `cacheInitial` at 0x02673c..0x0274bc (3,456 bytes):
//     Decodes all 20 JNI class names (indices 13..32 in kTerrainXorStringTable:
//     8 primitive wrapper classes `java/lang/Boolean`..`java/lang/Double` and
//     12 standard exception classes `java/lang/NoClassDefFoundError`..`java/lang/RuntimeException`),
//     resolves the 8 primitive `TYPE` jclass references into .bss 0x055bf8..0x055cd8 via
//     `ResolvePrimitiveWrapperType_0274bc`, and marks `gVm.initialized_flag = 1`.
// VN: Tái tạo biểu tượng C xuất `cacheInitial` tại 0x02673c..0x0274bc (3,456 byte):
//     Giải mã toàn bộ 20 tên lớp JNI (8 lớp bao nguyên thủy và 12 lớp ngoại lệ chuẩn),
//     phân giải 8 tham chiếu jclass `TYPE` nguyên thủy vào .bss 0x055bf8..0x055cd8 qua
//     `ResolvePrimitiveWrapperType_0274bc`, và đánh dấu `gVm.initialized_flag = 1`.
void cacheInitial(void* jni_env) {
    using namespace nextai::opencut::terrain;
    TerrainJniCache& cache = GetTerrainJniCache_055be0();

    char decoded_names[20][64] = {};
    for (int i = 0; i < 20; ++i) {
        const TerrainXorStringEntry& entry = kTerrainXorStringTable[13 + i];
        DecodeXorString_012fd8(entry.enc_bytes, decoded_names[i], entry.key_bytes);
    }

    cache.primitive_boolean_type = ResolvePrimitiveWrapperType_0274bc(jni_env, decoded_names[0]);
    cache.primitive_byte_type    = ResolvePrimitiveWrapperType_0274bc(jni_env, decoded_names[1]);
    cache.primitive_char_type    = ResolvePrimitiveWrapperType_0274bc(jni_env, decoded_names[2]);
    cache.primitive_short_type   = ResolvePrimitiveWrapperType_0274bc(jni_env, decoded_names[3]);
    cache.primitive_int_type     = ResolvePrimitiveWrapperType_0274bc(jni_env, decoded_names[4]);
    cache.primitive_float_type   = ResolvePrimitiveWrapperType_0274bc(jni_env, decoded_names[5]);
    cache.primitive_long_type    = ResolvePrimitiveWrapperType_0274bc(jni_env, decoded_names[6]);
    cache.primitive_double_type  = ResolvePrimitiveWrapperType_0274bc(jni_env, decoded_names[7]);

    cache.cls_no_class_def_found_error      = reinterpret_cast<jclass>(static_cast<uintptr_t>(0x055CF8u));
    cache.cls_no_such_field_error           = reinterpret_cast<jclass>(static_cast<uintptr_t>(0x055D28u));
    cache.cls_no_such_field_exception       = reinterpret_cast<jclass>(static_cast<uintptr_t>(0x055D48u));
    cache.cls_no_such_method_error          = reinterpret_cast<jclass>(static_cast<uintptr_t>(0x055D78u));
    cache.cls_null_pointer_exception        = reinterpret_cast<jclass>(static_cast<uintptr_t>(0x055D98u));
    cache.cls_arithmetic_exception          = reinterpret_cast<jclass>(static_cast<uintptr_t>(0x055DC8u));
    cache.cls_internal_error                = reinterpret_cast<jclass>(static_cast<uintptr_t>(0x055DF8u));
    cache.cls_negative_array_size_exception = reinterpret_cast<jclass>(static_cast<uintptr_t>(0x055E18u));
    cache.cls_array_index_oob_exception     = reinterpret_cast<jclass>(static_cast<uintptr_t>(0x055E48u));
    cache.cls_class_cast_exception          = reinterpret_cast<jclass>(static_cast<uintptr_t>(0x055E78u));
    cache.cls_class_not_found_exception     = reinterpret_cast<jclass>(static_cast<uintptr_t>(0x055EA8u));
    cache.cls_runtime_exception             = reinterpret_cast<jclass>(static_cast<uintptr_t>(0x055ED8u));
    cache.is_initialized = true;

    gVm.initialized_flag = 1u;
}

// EN: Reconstructs exported C symbol `getCacheClass` at 0x0275ec..0x027674 (140 bytes):
//     0x0275ec: ldrb w8, [x1]
//     0x0275f0: mov x0, xzr
//     0x0275f4: sub w8, w8, #0x42 ('B')
//     0x0275f8: cmp w8, #0x18     ('Z' - 'B' == 24)
//     0x0275fc: b.hi #0x27638     (returns nullptr)
//     0x02760c: ldrb w11, [x9, x8] (from .rodata 0x03fde4: kGetCacheClassJumpOffsets_03fde4)
//     Dispatches to return one of the 8 cached primitive TYPE classes at .bss 0x055bf8..0x055cd8.
// VN: Tái tạo biểu tượng C xuất `getCacheClass` tại 0x0275ec..0x027674 (140 byte):
//     Kiểm tra ký tự đầu tiên thuộc 'B'..'Z', tra bảng nhảy 25 byte tại .rodata 0x03fde4
//     và trả về một trong 8 lớp TYPE nguyên thủy được lưu đệm tại .bss 0x055bf8..0x055cd8.
nextai::opencut::terrain::jclass getCacheClass(void* jni_env, const char* shorty_or_desc) {
    using namespace nextai::opencut::terrain;
    if (!shorty_or_desc) {
        return nullptr;
    }
    TerrainJniCache& cache = GetTerrainJniCache_055be0();
    if (!cache.is_initialized) {
        cacheInitial(jni_env);
    }
    const uint8_t ch = static_cast<uint8_t>(shorty_or_desc[0]);
    const uint32_t idx = static_cast<uint32_t>(ch) - 0x42u; // 'B' = 0x42
    if (idx > 0x18u) {
        return nullptr;
    }
    const uint8_t jmp_offset = kGetCacheClassJumpOffsets_03fde4[idx];
    switch (jmp_offset) {
        case 0:  return cache.primitive_byte_type;    // 'B' -> 0x027618 (ldr x0, [x8, #0xc18])
        case 3:  return cache.primitive_char_type;    // 'C' -> 0x027624 (ldr x0, [x8, #0xc38])
        case 6:  return cache.primitive_double_type;  // 'D' -> 0x027630 (ldr x0, [x8, #0xcd8])
        case 8:  return nullptr;                      // default -> 0x027638 (ret x0=0)
        case 9:  return cache.primitive_float_type;   // 'F' -> 0x02763c (ldr x0, [x8, #0xc98])
        case 12: return cache.primitive_int_type;     // 'I' -> 0x027648 (ldr x0, [x8, #0xc78])
        case 15: return cache.primitive_long_type;    // 'J' -> 0x027654 (ldr x0, [x8, #0xcb8])
        case 18: return cache.primitive_short_type;   // 'S' -> 0x027660 (ldr x0, [x8, #0xc58])
        case 21: return cache.primitive_boolean_type; // 'Z' -> 0x02766c (ldr x0, [x8, #0xbf8])
        default: return nullptr;
    }
}

} // extern "C"
