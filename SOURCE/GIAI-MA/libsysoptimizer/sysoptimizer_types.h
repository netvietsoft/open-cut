// ============================================================================
// File: sysoptimizer_types.h
// Target: libsysoptimizer.so (412,248 bytes, SHA-256: 0f63dc8761da723206e36de507b0af1b06b647815ae2e0f80bca858d4c904a03)
// Task ID: TASK-141-RECONSTRUCTION-LIBSYSOPTIMIZER / TASK_SO_070_libsysoptimizer
// Description:
//   [EN] Clean-room C++17 type definitions, ELF64 header validator ABI,
//        Android APS2 relocation flags (.rodata 0x015790..0x0157a8),
//        and JNI/xHook declarations for ByteDance SysOptimizer.
//   [VN] Định nghĩa kiểu dữ liệu C++17 sạch, cấu trúc kiểm tra ELF64 của xHook,
//        cờ tái định vị APS2 (.rodata 0x015790..0x0157a8) và khai báo JNI/xHook.
// ============================================================================

#pragma once

#include <cstdint>
#include <cstddef>

#ifndef JNI_VERSION_1_6
typedef uint8_t jboolean;
typedef int8_t jbyte;
typedef uint16_t jchar;
typedef int16_t jshort;
typedef int32_t jint;
typedef int64_t jlong;
typedef float jfloat;
typedef double jdouble;
typedef jint jsize;
struct _jobject;
typedef _jobject* jobject;
typedef jobject jclass;
typedef jobject jstring;
struct _JNIEnv { const void* functions; };
typedef _JNIEnv JNIEnv;
struct _JavaVM { const void* functions; };
typedef _JavaVM JavaVM;
#define JNI_VERSION_1_6 0x00010006
#endif

namespace bytedance {
namespace sysoptimizer {

// ============================================================================
// [EN] Android packed relocation flags exported in .rodata 0x015790..0x0157a8
// [VN] Các cờ tái định vị đóng gói Android APS2 xuất khẩu tại .rodata 0x015790..0x0157a8
// ============================================================================
constexpr uint64_t kRelocationGroupedByInfoFlag        = 0x0000000000000001ULL; // 0x015790
constexpr uint64_t kRelocationGroupedByOffsetDeltaFlag = 0x0000000000000002ULL; // 0x015798
constexpr uint64_t kRelocationGroupedByAddendFlag      = 0x0000000000000004ULL; // 0x0157a0
constexpr uint64_t kRelocationGroupHasAddendFlag       = 0x0000000000000008ULL; // 0x0157a8

// ============================================================================
// [EN] xHook ELF64 header prefix (24 bytes, checked in xh_elf_check_elfheader @ 0x02582c..0x02589c)
// [VN] Đầu tệp ELF64 24-byte được kiểm tra trong xh_elf_check_elfheader (0x02582c..0x02589c)
// ============================================================================
struct Elf64HeaderPrefixAbi {
    uint32_t e_ident_magic;      // +0x00 (0x464C457F = "\x7fELF" @ 0x025830..0x025834)
    uint8_t  e_ident_class;      // +0x04 (2 = ELFCLASS64 @ 0x025848)
    uint8_t  e_ident_data;       // +0x05 (1 = ELFDATA2LSB @ 0x025854)
    uint8_t  e_ident_version;    // +0x06 (1 = EV_CURRENT @ 0x025860)
    uint8_t  e_ident_pad[9];     // +0x07..+0x0f
    uint16_t e_type;             // +0x10 ((e_type & 0xFFFE) == 2 -> ET_EXEC/ET_DYN @ 0x02586c..0x025870)
    uint16_t e_machine;          // +0x12 (0xB7 = 183 = EM_AARCH64 @ 0x025880)
    uint32_t e_version;          // +0x14 (1 = EV_CURRENT @ 0x02588c)
};
static_assert(sizeof(Elf64HeaderPrefixAbi) == 24, "Elf64HeaderPrefixAbi must be 24 bytes (0x18)");

// ============================================================================
// [EN] ArtMProtectOpt state block at .bss 0x064fd8 (24 bytes, written at 0x02d79c..0x02d800)
// [VN] Khối trạng thái ArtMProtectOpt tại .bss 0x064fd8 (24 byte, ghi tại 0x02d79c..0x02d800)
// ============================================================================
struct ArtMProtectOptStateAbi {
    uint64_t min_protect_addr;   // +0x00 (0x064fd8)
    uint64_t max_protect_addr;   // +0x08 (0x064fe0)
    void*    shadowhook_stub;    // +0x10 (0x064fe8)
};
static_assert(sizeof(ArtMProtectOptStateAbi) == 24, "ArtMProtectOptStateAbi must be 24 bytes (0x18)");

// ============================================================================
// [EN] HeapGCOptimizerV2 config block at .bss 0x065770 (32 bytes, written at 0x0535d8..0x0535ec)
// [VN] Khối cấu hình HeapGCOptimizerV2 tại .bss 0x065770 (32 byte, ghi tại 0x0535d8..0x0535ec)
// ============================================================================
struct HeapGCOptimizerV2ValuesAbi {
    int64_t val_0;               // +0x00 (0x065770: stp x2, x3, [x8])
    int64_t val_1;               // +0x08 (0x065778)
    int64_t reserved_10;         // +0x10 (0x065780)
    int64_t val_2;               // +0x18 (0x065788: str x4, [x8, #0x18])
};
static_assert(sizeof(HeapGCOptimizerV2ValuesAbi) == 32, "HeapGCOptimizerV2ValuesAbi must be 32 bytes (0x20)");

} // namespace sysoptimizer
} // namespace bytedance

extern "C" {
jint JNI_OnLoad(JavaVM* vm, void* reserved);
int xh_elf_check_elfheader(uintptr_t base_addr);
void xh_util_flush_instruction_cache(uintptr_t addr);
}
