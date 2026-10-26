/**
 * @file newep_types.h
 * @brief Exact ELF64 AArch64 ABI structures, `.rodata` string pool (`0x00728c..0x007584`),
 *        `.bss` global pointer table (`0x010010..0x010280`, `624 bytes`),
 *        `std::__ndk1::basic_string` (`24 B = 0x18`) & `std::__ndk1::vector<std::string>`
 *        division-by-24 modular inverse math (`0xaaaaaaaaaaaaaaab` @ `0x00356c..0x0035b8`
 *        & `0x00377c..0x0037c8`), and AArch64 AAPCS64 `va_list` (`32 B`) for
 *        `libnewep.so` (`51,232 bytes`).
 *        Cấu trúc ABI ELF64 AArch64 chính xác, bể chuỗi `.rodata`, bảng con trỏ toàn cục
 *        `.bss` (`0x010010..0x010280`, `624 byte`), toán học nghịch đảo modular chia 24
 *        (`0xaaaaaaaaaaaaaaab`) của `std::vector<std::string>`, và `va_list` AArch64 (`32 byte`)
 *        của `libnewep.so` (`51,232 byte`).
 *
 * Binary Ground Truth / Thực tế Nhị phân (`libnewep.so` — 51,232 bytes):
 * - Architecture: ELF64 AArch64 little-endian (`EM_AARCH64`)
 * - ELF64 Section Geometry:
 *   - `.dynsym`          : `0x000550` (`1,800 bytes`, `75` symbols: `[003]..[045]` = 43 imports, `[046]..[074]` = **29 exported symbols**)
 *   - `.dynstr`          : `0x000c58` (`2,042 bytes`)
 *   - `.rela.dyn`        : `0x001528` (`432 bytes`, `18` relocations: `3` `R_AARCH64_RELATIVE`, `14` `R_AARCH64_GLOB_DAT`, `1` `R_AARCH64_ABS64`)
 *   - `.rela.plt`        : `0x0016d8` (`1,152 bytes`, `48` `R_AARCH64_JUMP_SLOT` relocations -> PLT `0x001b80..0x001e70`)
 *   - `.plt`             : `0x001b60..0x001e7f` (`800 bytes`)
 *   - `.text`            : `0x001e80..0x00728b` (`21,516 bytes`)
 *   - `.rodata`          : `0x00728c..0x007584` (`761 bytes`)
 *   - `.eh_frame_hdr`    : `0x007588..0x007823` (`668 bytes`)
 *   - `.eh_frame`        : `0x007828..0x008957` (`4,400 bytes`)
 *   - `.gcc_except_table`: `0x008958..0x008a6f` (`280 bytes`)
 *   - `.fini_array`      : `0x00fbd8..0x00fbe7` (`16 bytes`: `0x001e90`, `0x001e80`)
 *   - `.data.rel.ro`     : `0x00fbe8..0x00fbef` (`8 bytes`: `__dso_handle = 0x00fbe8`)
 *   - `.got`             : `0x00fdf0..0x00ffff` (`528 bytes`)
 *   - `.data`            : `0x010000..0x01000f` (`16 bytes`: `+0x00` `__gxx_personality_v0`, `+0x08` `0xffffffffffffffff`)
 *   - `.bss`             : `0x010010..0x01027f` (`624 bytes = 0x270`: `0x010010..0x01003f` 6 global JNI handles + `0x010040..0x0100a0` libunwind register size table & FDE cache)
 */

#ifndef NEXTAI_OPENCUT_NEWEP_TYPES_H_
#define NEXTAI_OPENCUT_NEWEP_TYPES_H_

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace nextai {
namespace opencut {
namespace newep {

// ============================================================================
// 1. ELF64 Binary Geometry Constants
//    Hằng số Hình học Nhị phân ELF64
// ============================================================================

struct Elf64GeometryConstants {
    static constexpr uint32_t kBinarySizeBytes      = 51232u;
    static constexpr uint32_t kDynsymOffset         = 0x000550u;
    static constexpr uint32_t kDynsymSizeBytes      = 1800u;
    static constexpr uint32_t kDynsymEntryCount     = 75u;
    static constexpr uint32_t kImportedSymbolCount  = 43u; // [003]..[045]
    static constexpr uint32_t kExportedSymbolCount  = 29u; // [046]..[074]

    static constexpr uint32_t kRelaDynOffset        = 0x001528u;
    static constexpr uint32_t kRelaDynSizeBytes     = 432u;
    static constexpr uint32_t kRelaDynEntryCount    = 18u;

    static constexpr uint32_t kRelaPltOffset        = 0x0016d8u;
    static constexpr uint32_t kRelaPltSizeBytes     = 1152u;
    static constexpr uint32_t kRelaPltEntryCount    = 48u;

    static constexpr uint32_t kPltVaddr             = 0x001b60u;
    static constexpr uint32_t kPltSizeBytes         = 800u;

    static constexpr uint32_t kTextVaddr            = 0x001e80u;
    static constexpr uint32_t kTextSizeBytes        = 21516u;

    static constexpr uint32_t kRodataVaddr          = 0x00728cu;
    static constexpr uint32_t kRodataSizeBytes      = 761u;

    static constexpr uint32_t kFiniArrayVaddr       = 0x00fbd8u;
    static constexpr uint32_t kDataRelRoVaddr       = 0x00fbe8u;
    static constexpr uint32_t kGotVaddr             = 0x00fdf0u;
    static constexpr uint32_t kDataVaddr            = 0x010000u;
    static constexpr uint32_t kBssVaddr             = 0x010010u;
    static constexpr uint32_t kBssEndVaddr          = 0x010280u;
    static constexpr uint32_t kBssSizeBytes         = 624u; // 0x0270
};

// ============================================================================
// 2. Minimal JNI & AAPCS64 `va_list` Types
//    Các Kiểu JNI Tối thiểu & `va_list` Chuẩn AAPCS64
// ============================================================================

using jint      = int32_t;
using jlong     = int64_t;
using jboolean  = uint8_t;
using jobject   = void*;
using jclass    = void*;
using jstring   = void*;
using jmethodID = void*;
using JavaVM    = struct _JavaVM;
using JNIEnv    = struct _JNIEnv;

constexpr jint     kJniVersion1_6 = 0x00010006; // mov w2, #6; movk w2, #1, lsl #16 @ 0x001ee0..0x001ef8
constexpr jint     kJniErr        = -1;         // mov w19, #-1 @ 0x001f0c
constexpr jint     kJniEdetached  = -2;         // cmn w0, #2 @ 0x002104
constexpr jboolean kJniFalse      = 0u;
constexpr jboolean kJniTrue       = 1u;

/**
 * @brief Exact 32-byte AArch64 AAPCS64 `std::va_list` (`__va_list`) constructed on stack
 *        at `[x29, #-0x38]` and copied via `ldp q1, q0, [x9]; stp q1, q0, [x29, #-0x60]`
 *        in `_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz` (`0x002438..0x0024d3`)
 *        and `_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz` (`0x0024d4..0x00256f`).
 *        Cấu trúc `va_list` 32-byte chuẩn AAPCS64 được dựng tại `[x29, #-0x38]` trong
 *        2 hàm hỗ trợ biến đối số `_JNIEnv`.
 */
struct AArch64VaListAbi {
    void*   __stack;    // +0x00 (`add x12, x29, #0x10`)
    void*   __gr_top;   // +0x08 (`sp + 0x88 + 0x28 = sp + 0xb0`)
    void*   __vr_top;   // +0x10 (`sp + 0x80`)
    int32_t __gr_offs;  // +0x18 (`-0x28 = -40`)
    int32_t __vr_offs;  // +0x1c (`-0x80 = -128`)
};
static_assert(sizeof(AArch64VaListAbi) == 32, "AArch64VaListAbi must be 32 bytes (0x20)");
static constexpr uint64_t kPackedGrVrOffs = 0xffffff80ffffffd8ULL;

// ============================================================================
// 3. `.rodata` Constants (`0x00728c..0x007584`, 761 bytes)
//    Hằng số Chuỗi & Bảng Nhảy `.rodata` (`0x00728c..0x007584`, 761 byte)
// ============================================================================
//
// Notice two linker tail-merge optimizations (`SHF_MERGE | SHF_STRINGS`) in `.rodata`:
// 1. `0x0072cb` (`"r"`): tail of `"com/ss/ugc/effectplatform/algorithm/AlgorithmModelResourceFinder"` (`0x00728c + 63`)
//    used as the `fopen(path, "r")` mode string in `nativeCheckEffectChildrenFile` (`0x002600: add x1, x1, #0x2cb`).
// 2. `0x0073f3` (`"findResourceUri"`): tail of `"tempJavaUri not found,then call old_resource_finder#findResourceUri"` (`0x0073bf + 52`)
//    used as the method name in `GetStaticMethodID` in `JNI_OnLoad` (`0x001f64` & `0x002050: add x2, x2, #0x3f3`).

struct RodataConstants {
    static constexpr const char* kClassKnResourceFinder             = "com/ss/ugc/effectplatform/algorithm/AlgorithmModelResourceFinder"; // 0x00728c
    static constexpr const char* kFopenModeRead                     = "r";                                                                // 0x0072cb (tail of 0x00728c)
    static constexpr const char* kSigFindResourceUri                = "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;";         // 0x0072cd
    static constexpr const char* kMethodModelNotFound               = "modelNotFound";                                                    // 0x007306
    static constexpr const char* kSigModelNotFound                  = "(Ljava/lang/String;)V";                                            // 0x007314
    static constexpr const char* kClassOldResourceFinder            = "com/ss/android/ugc/effectmanager/DownloadableModelSupportResourceFinder"; // 0x00732a
    static constexpr const char* kLogTagKnResourceFinder            = "kn_resource_finder";                                               // 0x007372
    static constexpr const char* kLogCallKnFindResourceUri          = "call kn_resource_finder#findResourceUri";                          // 0x007385
    static constexpr const char* kUriAssetNotFound                  = "asset://not_found";                                                // 0x0073ad
    static constexpr const char* kLogFallbackOldResourceFinder      = "tempJavaUri not found,then call old_resource_finder#findResourceUri"; // 0x0073bf
    static constexpr const char* kMethodFindResourceUri             = "findResourceUri";                                                  // 0x0073f3 (tail of 0x0073bf)
    static constexpr const char* kFmtResourceUri                    = "resourceUri = %s";                                                 // 0x007403
    static constexpr const char* kLogCallModelNotFound              = "call modelNotFound method in Java";                                // 0x007414
    static constexpr const char* kEffectPlatformChildrenTagFile     = "/effect_platform_children.tag";                                    // 0x007436 (size=30=0x1e)
    static constexpr const char* kFmtChildrenFileFpNull             = "EffectPlatform-EPKN, effectPlatformChildrenFileFp %s is null";     // 0x007454
    static constexpr const char* kDelimiterComma                    = ",";                                                                // 0x007491
    static constexpr const char* kFmtChildNotExist                  = "EffectPlatform-EPKN, child %s not exist";                          // 0x007493
    static constexpr const char* kLabelBasicString                  = "basic_string";                                                     // 0x0074bb
    static constexpr const char* kLabelVector                       = "vector";                                                           // 0x0074c8
    static constexpr const char* kDwarfAugmentationWWW              = "WWW";                                                              // 0x00754c
};

// ============================================================================
// 4. `.bss` Global Segment Layout (`0x010010..0x01027f`, `624 bytes = 0x270`)
//    Bố cục Phân đoạn Toàn cục `.bss` (`0x010010..0x01027f`, `624 byte`)
// ============================================================================

/**
 * @brief Exact layout of the 6 exported JNI global symbols at `.bss 0x010010..0x01003f`
 *        plus the `libunwind` DWARF register size table at `.bss 0x010040..0x0100a0`:
 *        - `+0x000 (0x010010)`: `kn_resource_finder_class` (`[066]`, GOT `0x00ffd0`, `8 B`)
 *        - `+0x008 (0x010018)`: `kn_resource_finder_methodID` (`[064]`, GOT `0x00ffd8`, `8 B`)
 *        - `+0x010 (0x010020)`: `kn_model_not_found_methodID` (`[073]`, GOT `0x00ffe8`, `8 B`)
 *        - `+0x018 (0x010028)`: `old_resource_finder_methodID` (`[062]`, GOT `0x00ffa0`, `8 B`)
 *        - `+0x020 (0x010030)`: `old_resource_finder_class` (`[050]`, GOT `0x00fff0`, `8 B`)
 *        - `+0x028 (0x010038)`: `g_vm` (`[061]`, GOT `0x00ffb8`, `8 B`)
 *        - `+0x030 (0x010040)`: `dwarf_reg_size_table[97]` (`0x010040..0x0100a0`, initialized at `0x003c38`: `[0..31] = 8`, `[64..96] = 8`)
 */
struct NewepBssSegment {
    jclass    kn_resource_finder_class;       // +0x000 (0x010010) [066]
    jmethodID kn_resource_finder_methodID;    // +0x008 (0x010018) [064]
    jmethodID kn_model_not_found_methodID;    // +0x010 (0x010020) [073]
    jmethodID old_resource_finder_methodID;   // +0x018 (0x010028) [062]
    jclass    old_resource_finder_class;      // +0x020 (0x010030) [050]
    JavaVM*   g_vm;                           // +0x028 (0x010038) [061]
    uint8_t   dwarf_reg_size_table[97];       // +0x030 (0x010040..0x0100a0)
    uint8_t   unwinder_cache_storage[479];    // +0x091 (0x0100a1..0x01027f)
};
static_assert(sizeof(NewepBssSegment) == 624, "NewepBssSegment must be 624 bytes (0x270)");
static_assert(offsetof(NewepBssSegment, kn_resource_finder_class) == 0x00, "Offset 0x010010 mismatch");
static_assert(offsetof(NewepBssSegment, kn_resource_finder_methodID) == 0x08, "Offset 0x010018 mismatch");
static_assert(offsetof(NewepBssSegment, kn_model_not_found_methodID) == 0x10, "Offset 0x010020 mismatch");
static_assert(offsetof(NewepBssSegment, old_resource_finder_methodID) == 0x18, "Offset 0x010028 mismatch");
static_assert(offsetof(NewepBssSegment, old_resource_finder_class) == 0x20, "Offset 0x010030 mismatch");
static_assert(offsetof(NewepBssSegment, g_vm) == 0x28, "Offset 0x010038 mismatch");
static_assert(offsetof(NewepBssSegment, dwarf_reg_size_table) == 0x30, "Offset 0x010040 mismatch");

// ============================================================================
// 5. `std::__ndk1::basic_string` (24B) & `std::__ndk1::vector<std::string>` (24B) ABI
//    Bố cục ABI `basic_string` (24B) & `vector<std::string>` (24B)
// ============================================================================

struct LibcxxString24Abi {
    union {
        struct {
            uint64_t cap_and_flag; // +0x00 (bit 0 == 1)
            uint64_t size;         // +0x08
            char*    data;         // +0x10
        } long_repr;
        struct {
            uint8_t tag;           // +0x00 (bit 0 == 0, length = tag >> 1)
            char    inline_buf[23];// +0x01..+0x17
        } short_repr;
    };
};
static_assert(sizeof(LibcxxString24Abi) == 24, "LibcxxString24Abi must be 24 bytes (0x18)");

struct LibcxxVectorString24Abi {
    LibcxxString24Abi* begin;    // +0x00
    LibcxxString24Abi* end;      // +0x08
    LibcxxString24Abi* cap_end;  // +0x10
};
static_assert(sizeof(LibcxxVectorString24Abi) == 24, "LibcxxVectorString24Abi must be 24 bytes (0x18)");

// ============================================================================
// 6. Division-by-24 (`sizeof(std::string) = 0x18`) Modular Inverse Math (`0x003568..0x003608`)
//    Toán học Nghịch đảo Modular Chia 24 (`sizeof(std::string) = 0x18` @ `0x003568..0x003608`)
// ============================================================================
//
// In `_ZNSt6__ndk16vectorINS_12basic_string...EE21__push_back_slow_path` (`0x003558` & `0x003764`),
// pointer differences `(end - begin)` and `(cap_end - begin)` are exact multiples of `24` (`8 * 3`).
// Clang AArch64 computes `byte_diff / 24` via:
// 1. `asr x8, x8, #3` (`byte_diff / 8`)
// 2. `mul x22, x8, x10` where `x10 = 0xaaaaaaaaaaaaaaab` (`3 * 0xaaaaaaaaaaaaaaab == 1 mod 2^64`)
// And checks max capacity against:
// - `kMaxVectorStrings = 0x0aaaaaaaaaaaaaaa` (`floor((2^64 - 1) / 24) = 768614336404564650`)
// - `kHalfMaxStrings   = 0x0555555555555555` (`floor(kMaxVectorStrings / 2) = 384307168202282325`)
// And converts element count `N` back to bytes (`24 * N`) via:
// - `add x8, x21, x21, lsl #1` (`3 * N` @ `0x0035d0`)
// - `lsl x0, x8, #3` (`24 * N` @ `0x0035d4`)

struct VectorStringCapacityMath {
    static constexpr uint64_t kModInv3Mod2Pow64  = 0xaaaaaaaaaaaaaaabULL; // 0x00356c..0x003570
    static constexpr uint64_t kMaxVectorStrings  = 0x0aaaaaaaaaaaaaaaULL; // 0x003574..0x003584
    static constexpr uint64_t kHalfMaxStrings    = 0x0555555555555555ULL; // 0x0035ac..0x0035b4
    static constexpr uint64_t kStringElementSize = 24ULL;                 // 0x18 @ 0x0035e4

    static inline uint64_t ExactBytesDiv24(int64_t byte_diff) noexcept {
        const uint64_t div8 = static_cast<uint64_t>(byte_diff >> 3);
        return div8 * kModInv3Mod2Pow64;
    }

    static inline uint64_t ComputeNextCapacity(uint64_t current_size,
                                               uint64_t current_cap) noexcept {
        const uint64_t needed = current_size + 1u;
        if (current_cap > kHalfMaxStrings) {
            return kMaxVectorStrings;
        }
        const uint64_t doubled = current_cap << 1;
        return (doubled < needed) ? needed : doubled;
    }

    static inline uint64_t ElementsToBytes24(uint64_t count) noexcept {
        const uint64_t times3 = count + (count << 1); // add x8, x21, x21, lsl #1
        return times3 << 3;                           // lsl x0, x8, #3
    }
};

} // namespace newep
} // namespace opencut
} // namespace nextai

#endif // NEXTAI_OPENCUT_NEWEP_TYPES_H_
