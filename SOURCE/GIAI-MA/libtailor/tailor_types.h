/**
 * @file tailor_types.h
 * @brief Exact Binary Types, Constants, HPROF Tags, and ABI Structs for libtailor.so
 *        Các kiểu dữ liệu nhị phân, Hằng số, Thẻ HPROF và Cấu trúc ABI chính xác cho libtailor.so
 *
 * Binary Ground Truth (libtailor.so — 84,136 bytes, 27 ELF64 sections, 92 exported symbols):
 *   - `.rodata`:      `0x0041b8..0x00594b` (`6,036 bytes`)
 *   - `.text`:        `0x007fd8..0x013023` (`45,132 bytes`)
 *   - `.plt`:         `0x013030..0x0137ef` (`1,984 bytes`)
 *   - `.data.rel.ro`: `0x0177f0..0x0178f7` (`264 bytes`, including `JNINativeMethod[5]` @ `0x0177f8..0x01786f`)
 *   - `.init_array`:  `0x017908..0x01790f` (`8 bytes` -> `0x00d67c` `_GLOBAL__sub_I_tailor.cpp`)
 *   - `.data`:        `0x01bfa8..0x01c017` (`112 bytes`: `xh_log_priority = 5` @ `0x01bfd0`, `tailor_deepshrink = 1` @ `0x01bfd4`,
 *                     `mainActivityString` @ `0x01bfd8`, `TAILOR_VERSION_MESSAGE` @ `0x01bfe8`, `target_tid = -1` @ `0x01bff0`)
 *   - `.bss`:         `0x01c018..0x01d307` (`4,848 bytes`: `classInfoMap` @ `0x01c1f0`, `instanceInfoMap` @ `0x01c218`,
 *                     `stringNameID2classID` @ `0x01c240`, `needKeepClassIDSet` @ `0x01c268`, `mainClassID` @ `0x01c290`,
 *                     `mainActivityStringID` @ `0x01c298`, `BUILD_VERSION_SDK_INT` @ `0x01c2a0`, `istream` @ `0x01c2a8`,
 *                     `ostream` @ `0x01c2b0`, `pWriter` @ `0x01c2b8`)
 */

#ifndef OPENCUT_TAILOR_TYPES_H_
#define OPENCUT_TAILOR_TYPES_H_

#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace bytedance {
namespace tailor {

// ============================================================================
// 1. EXPORTED RODATA RELOCATION FLAGS & GLOBAL CONSTANTS (.rodata 0x0051d0..0x0051ef)
// ============================================================================

/**
 * @brief Exported Android packed relocation flags at `.rodata` `0x0051d0..0x0051ef`:
 *        - `RELOCATION_GROUPED_BY_INFO_FLAG` (`0x0051d0`)         = `1ULL`
 *        - `RELOCATION_GROUPED_BY_OFFSET_DELTA_FLAG` (`0x0051d8`) = `2ULL`
 *        - `RELOCATION_GROUPED_BY_ADDEND_FLAG` (`0x0051e0`)       = `4ULL`
 *        - `RELOCATION_GROUP_HAS_ADDEND_FLAG` (`0x0051e8`)        = `8ULL`
 *
 *        Các cờ relocation nén Android xuất khẩu tại `.rodata` `0x0051d0..0x0051ef`.
 */
constexpr uint64_t RELOCATION_GROUPED_BY_INFO_FLAG         = 1ULL;  // 0x0051d0
constexpr uint64_t RELOCATION_GROUPED_BY_OFFSET_DELTA_FLAG = 2ULL;  // 0x0051d8
constexpr uint64_t RELOCATION_GROUPED_BY_ADDEND_FLAG       = 4ULL;  // 0x0051e0
constexpr uint64_t RELOCATION_GROUP_HAS_ADDEND_FLAG        = 8ULL;  // 0x0051e8

/**
 * @brief Exact `.rodata` string constants in `libtailor.so`.
 *        Các hằng chuỗi `.rodata` chính xác trong `libtailor.so`.
 */
constexpr const char* kTailorJniClassPath      = "com/bytedance/tailor/Tailor";                // 0x004dda
constexpr const char* kMainActivityClassName   = "android.app.Activity";                       // 0x0044d7
constexpr const char* kTailorVersionHeader     = "JAVA PROFILE 6.0.1";                         // 0x004c74 (18 bytes = 0x12 @ 0x00dcf0)
constexpr size_t      kTailorVersionHeaderLen  = 18u;                                          // 0x12 (@ 0x00dcf0)
constexpr const char* kZlibVersionString       = "1.2.8";                                      // 0x00481b (@ 0x00d73c)
constexpr const char* kTailorDirFmt            = "/data/data/%s/files/tailor";                 // 0x00486f
constexpr const char* kTailorCrashFileFmt      = "/data/data/%s/files/tailor/tailor_crash_%ld.txt"; // 0x004b69
constexpr const char* kTailorCrashPrefix       = "tailor_crash_";                              // 0x0048bf
constexpr const char* kProcSelfMapsPath        = "/proc/self/maps";                            // 0x0050b4
constexpr const char* kSdkVersionPropName      = "ro.build.version.sdk";                       // 0x004bf4
constexpr const char* kHookTargetSoRegex       = ".*\\.so$";                                   // 0x004ec9
constexpr const char* kHookIgnoreTailorRegex   = ".*libtailor\\.so$";                          // 0x0044a0

/**
 * @brief Buffer and struct allocation sizes verified in `.text`:
 *        - `kStreamBufferCapacity = 0x40000` (`262,144 bytes = 256 KB` @ `0x00aabc` & `0x00d7c8`)
 *        - `kWriterStructSize = 0x40088` (`262,280 bytes` @ `0x00dc70..0x00dc74`: `mov w0, #0x88; movk w0, #4, lsl #16`)
 *        - `kZStreamStructSize = 0x70` (`112 bytes` @ `0x00d758`: `mov w7, #0x70`)
 *        - `kMprotectFallbackError = 0x3e9` (`1001` @ `0x00aa30`: `mov w8, #0x3e9`)
 *        - `kJniVersion1_6 = 0x00010006` (`mov w2, #6; movk w2, #1, lsl #16` @ `0x00e668..0x00e674`)
 *
 *        Kích thước bộ đệm và cấu trúc xác minh trong `.text`.
 */
constexpr size_t   kStreamBufferCapacity  = 0x40000u;     // 262,144 bytes (256 KB)
constexpr size_t   kWriterStructSize      = 0x40088u;     // 262,280 bytes
constexpr uint32_t kZStreamStructSize     = 0x70u;        // 112 bytes
constexpr int32_t  kMprotectFallbackError = 0x3e9;        // 1001 (@ 0x00aa30)
constexpr int32_t  kJniVersion1_6         = 0x00010006;   // JNI_VERSION_1_6 (@ 0x00e668)
constexpr uint32_t kSigActionFlags        = 0x08000004u;  // SA_SIGINFO | SA_ONSTACK (@ 0x00dd20..0x00dd2c)

// ============================================================================
// 2. HPROF RECORD TAGS, SUB-TAGS & BASIC TYPES (0x00b34c..0x00c6d4)
// ============================================================================

/**
 * @brief Top-level HPROF tags dispatched in `tailor_XHOOK` (`0x00b34c..0x00b444`, jump table @ `0x0051f0`).
 *        Các thẻ HPROF cấp cao nhất được phân phối trong `tailor_XHOOK` (`0x00b34c..0x00b444`).
 */
enum class HprofTag : uint8_t {
    kStringInUtf8       = 0x01,  // Dispatches tailor_STRING (0x00b448)
    kLoadClass          = 0x02,  // Dispatches tailor_LOAD_CLASS (0x00b550)
    kHeapDump           = 0x0C,  // Dispatches tailor_HEAP_DUMP_SEGMENT (0x00b690)
    kHeapDumpSegment    = 0x1C,  // Dispatches tailor_HEAP_DUMP_SEGMENT (0x00b690)
    kHeapDumpEnd        = 0x2C   // Dispatches initKeepClassIDSet + tailor_INSTANCE_DUMP_WRITE + clearCache (0x00b404..0x00b430)
};

/**
 * @brief HPROF heap dump sub-record tags dispatched in `tailor_HEAP_DUMP_SEGMENT` (`0x00b690..0x00b884`, jump table @ `0x00521c`).
 *        Các thẻ con trong phân đoạn heap dump HPROF xử lý tại `tailor_HEAP_DUMP_SEGMENT` (`0x00b690..0x00b884`).
 */
enum class HprofSubTag : uint8_t {
    kRootJniGlobal       = 0x01,  // 1B tag + 4B obj_id + 4B jni_global_ref (copy 5B, seek 4B @ 0x00b75c)
    kRootJniLocal        = 0x02,  // 1B tag + 4B obj_id + 4B thread_serial + 4B frame (copy 5B, seek 8B @ 0x00b730)
    kRootJavaFrame       = 0x03,  // 1B tag + 4B obj_id + 4B thread_serial + 4B frame (copy 5B, seek 8B @ 0x00b730)
    kRootNativeStack     = 0x04,  // 1B tag + 4B obj_id + 4B thread_serial (copy 5B, seek 4B @ 0x00b75c)
    kRootStickyClass     = 0x05,  // 1B tag + 4B obj_id (copy 5B @ 0x00b6d8)
    kRootThreadBlock     = 0x06,  // 1B tag + 4B obj_id + 4B thread_serial (copy 5B, seek 4B @ 0x00b75c)
    kRootMonitorUsed     = 0x07,  // 1B tag + 4B obj_id (copy 5B @ 0x00b6d8)
    kRootThreadObject    = 0x08,  // 1B tag + 4B obj_id + 4B thread_serial + 4B stack_trace (copy 5B, seek 8B @ 0x00b730)
    kClassDump           = 0x20,  // Dispatches tailor_CLASS_DUMP (0x00bd6c @ 0x00b7bc)
    kInstanceDump        = 0x21,  // Dispatches tailor_INSTANCE_DUMP (0x00c260 @ 0x00b7cc)
    kObjectArrayDump     = 0x22,  // Dispatches tailor_OBJECT_ARRAY_DUMP (0x00c414 @ 0x00b7dc)
    kPrimitiveArrayDump  = 0x23,  // Dispatches tailor_PRIMITIVE_ARRAY_DUMP (0x00c470 @ 0x00b82c)
    kRootInternedString  = 0x89,  // 1B tag + 4B obj_id (copy 5B @ 0x00b6d8)
    kRootFinalizing      = 0x8A,  // 1B tag + 4B obj_id (copy 5B @ 0x00b6d8)
    kRootDebugger        = 0x8B,  // 1B tag + 4B obj_id (copy 5B @ 0x00b6d8)
    kRootReferenceCleanup= 0x8C,  // 1B tag + 4B obj_id (copy 5B @ 0x00b6d8)
    kRootVmInternal      = 0x8D,  // 1B tag + 4B obj_id (copy 5B @ 0x00b6d8)
    kRootJniMonitor      = 0x8E,  // 1B tag + 4B obj_id + 4B thread + 4B depth (copy 5B, seek 8B @ 0x00b730)
    kRootUnreachable     = 0x90,  // 1B tag + 4B obj_id (copy 5B @ 0x00b6d8)
    kHeapDumpInfo        = 0xFE,  // 1B tag + 4B heap_type + 4B string_id (copy 9B @ 0x00b78c)
    kRootUnknown         = 0xFF   // 1B tag + 4B obj_id (copy 5B @ 0x00b6d8)
};

/**
 * @brief HPROF basic field/array element types (`2..11`, LUTs at `.rodata` `0x0052df..0x005430`).
 *        Các kiểu dữ liệu cơ bản của trường/mảng HPROF (`2..11`, bảng tra tại `.rodata` `0x0052df..0x005430`).
 */
enum class HprofBasicType : uint8_t {
    kObject  = 2,   // 4-byte object ID in 32-bit ID HPROF
    kBoolean = 4,   // 1 byte
    kChar    = 5,   // 2 bytes
    kFloat   = 6,   // 4 bytes
    kDouble  = 7,   // 8 bytes
    kByte    = 8,   // 1 byte
    kShort   = 9,   // 2 bytes
    kInt     = 10,  // 4 bytes
    kLong    = 11   // 8 bytes
};

/**
 * @brief Returns the byte width of an HPROF basic type (`2..11`), matching `.rodata` `0x0053a0` / `0x0053e8`:
 *        `{2: 4, 4: 1, 5: 2, 6: 4, 7: 8, 8: 1, 9: 2, 10: 4, 11: 8}`.
 *        Trả về độ rộng byte của kiểu cơ bản HPROF (`2..11`), khớp bảng `.rodata` `0x0053a0` / `0x0053e8`.
 */
inline constexpr size_t GetHprofBasicTypeSize(uint8_t basic_type) noexcept {
    switch (basic_type) {
        case 2:  return 4;  // kObject (4-byte ID)
        case 4:  return 1;  // kBoolean
        case 5:  return 2;  // kChar
        case 6:  return 4;  // kFloat
        case 7:  return 8;  // kDouble
        case 8:  return 1;  // kByte
        case 9:  return 2;  // kShort
        case 10: return 4;  // kInt
        case 11: return 8;  // kLong
        default: return 0;
    }
}

// ============================================================================
// 3. CLASS DUMP & INSTANCE INFO ABI STRUCTS (0x00bd6c..0x00c410)
// ============================================================================

/**
 * @brief Reconstructs `ClassDumpInfo` (`16 bytes = 0x10` allocated at `0x00bf80: mov w0, #0x10; bl _Znwm`
 *        plus `24 bytes = 0x18` `std::vector<int>` allocated at `0x00bf98: mov w0, #0x18; bl _Znwm`):
 *        - `+0x00`: `int64_t super_class_id` (`x28` stored at `0x00c1a0`)
 *        - `+0x08`: `std::vector<int>* instance_field_types` (`x22` stored at `0x00c1a0`)
 *
 *        Tái dựng `ClassDumpInfo` (`16 bytes = 0x10` cấp phát tại `0x00bf80` kèm `std::vector<int>*` `24B` tại `0x00bf98`).
 */
struct ClassDumpInfo {
    int64_t super_class_id{0};                  // +0x00
    std::vector<int32_t> instance_field_types;  // +0x08 (heap vector in binary)
};

/**
 * @brief Reconstructs `InstanceInfo` (`32 bytes = 0x20` allocated at `0x00c298: mov w0, #0x20; bl _Znwm`):
 *        - `+0x00`: `uint32_t sub_tag` (`0x21` read at `0x00c2bc: str w0, [x20]`)
 *        - `+0x08`: `int64_t class_id` (`str x0, [x20, #8]` @ `0x00c2f0`)
 *        - `+0x10`: `int32_t byte_size` (`str w0, [x20, #0x10]` @ `0x00c308`)
 *        - `+0x18`: `uint8_t* raw_fields_bytes` (`str x0, [x20, #0x18]` @ `0x00c31c`)
 *
 *        Tái dựng `InstanceInfo` (`32 bytes = 0x20` cấp phát tại `0x00c298`).
 */
struct InstanceInfo {
    uint32_t sub_tag{0x21};                 // +0x00
    uint32_t padding{0};                    // +0x04
    int64_t  class_id{0};                   // +0x08
    int32_t  byte_size{0};                  // +0x10
    uint32_t padding2{0};                   // +0x14
    std::vector<uint8_t> raw_fields_bytes;  // +0x18 (managed buffer of length byte_size)
};

/**
 * @brief Singly-linked string set node (`16 bytes = 0x10` allocated at `0x00e9bc: mov w0, #0x10; bl malloc`)
 *        and `Set` head (`8 bytes` allocated at `0x00e8f0: mov w0, #8; bl malloc`).
 *        Nút danh sách liên kết đơn của `Set` (`16B` tại `0x00e9bc`) và đầu danh sách `Set` (`8B` tại `0x00e8f0`).
 */
struct SetNode {
    char* value{nullptr};    // +0x00 (allocated via strdup @ 0x00e9cc)
    SetNode* next{nullptr};  // +0x08
};

struct Set {
    SetNode* head{nullptr};  // +0x00
};

/**
 * @brief JNI method descriptor matching `.data.rel.ro` `0x0177f8..0x01786f` (`5 * 24 = 120 bytes`).
 *        Mô tả phương thức JNI khớp với `.data.rel.ro` `0x0177f8..0x01786f` (`5 * 24 = 120 bytes`).
 */
struct TailorJniMethodEntry {
    const char* name;
    const char* signature;
    uint64_t    fn_vaddr;
};

}  // namespace tailor
}  // namespace bytedance

#endif  // OPENCUT_TAILOR_TYPES_H_
