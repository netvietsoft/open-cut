/**
 * @file pumbaa_network_types.h
 * @brief Exact ELF64 AArch64 ABI structures, `.rodata` string pool (`0x006df0..0x007114`),
 *        `.bss` global pointer table (`0x010010..0x0102b0`, `672 bytes`),
 *        `std::__ndk1::__tree_node` (`80 B = 0x50` @ `0x002e44`), AArch64 AAPCS64
 *        `va_list` (`32 B`), and signed 64-bit reciprocal division-by-1000 math
 *        (`0x20c49ba5e353f7cf` & `0xdf3b645a1cac0831` @ `0x002b10..0x002b60`) for
 *        `libpumbaa-network.so` (`51,232 bytes`).
 *        Cấu trúc ABI ELF64 AArch64 chính xác, bể chuỗi `.rodata`, bảng con trỏ toàn cục
 *        `.bss` (`0x010010..0x0102b0`, `672 byte`), nút Cây Đỏ-Đen `80 byte` (`0x50`),
 *        `va_list` AArch64 (`32 byte`), và toán học chia có dấu 64-bit cho 1000 của
 *        `libpumbaa-network.so` (`51,232 byte`).
 *
 * Binary Ground Truth / Thực tế Nhị phân (`libpumbaa-network.so` — 51,232 bytes):
 * - Architecture: ELF64 AArch64 little-endian (`EM_AARCH64`)
 * - ELF64 Section Geometry:
 *   - `.dynsym`       : `0x000530` (`1,632 bytes`, `68` symbols: `[003]..[030]` = 28 imports, `[031]..[067]` = **37 exported symbols**)
 *   - `.dynstr`       : `0x000b90` (`2,554 bytes`)
 *   - `.rela.dyn`     : `0x001658` (`456 bytes`, `19` relocations: `3` `R_AARCH64_RELATIVE`, `15` `R_AARCH64_GLOB_DAT`, `1` `R_AARCH64_ABS64`)
 *   - `.rela.plt`     : `0x001820` (`936 bytes`, `39` `R_AARCH64_JUMP_SLOT` relocations -> PLT `0x001bf0..0x001e50`)
 *   - `.plt`          : `0x001bd0..0x001e5f` (`656 bytes`)
 *   - `.text`         : `0x001e60..0x006def` (`20,368 bytes`)
 *   - `.rodata`       : `0x006df0..0x007114` (`805 bytes`)
 *   - `.eh_frame_hdr` : `0x007118..0x0073bb` (`676 bytes`)
 *   - `.eh_frame`     : `0x0073c0..0x0084ff` (`4,416 bytes`)
 *   - `.gcc_except_table`: `0x008500..0x008557` (`88 bytes`)
 *   - `.fini_array`   : `0x00fc08..0x00fc17` (`16 bytes`: `0x001e70`, `0x001e60`)
 *   - `.data.rel.ro`  : `0x00fc18..0x00fc1f` (`8 bytes`: `__dso_handle = 0x00fc18`)
 *   - `.got`          : `0x00fe30..0x00ffff` (`464 bytes`)
 *   - `.data`         : `0x010000..0x01000f` (`16 bytes`: `+0x00` `__gxx_personality_v0`, `+0x08` `0xffffffffffffffff`)
 *   - `.bss`          : `0x010010..0x0102af` (`672 bytes = 0x2a0`: `0x010010..0x010067` 11 global JNI handles + `0x010070..0x0102af` libunwind register size table & FDE cache)
 */

#ifndef NEXTAI_OPENCUT_PUMBAA_NETWORK_TYPES_H_
#define NEXTAI_OPENCUT_PUMBAA_NETWORK_TYPES_H_

#include <cstddef>
#include <cstdint>
#include <map>
#include <string>
#include <vector>

namespace nextai {
namespace opencut {
namespace pumbaa_network {

// ============================================================================
// 1. ELF64 Binary Geometry Constants
//    Hằng số Hình học Nhị phân ELF64
// ============================================================================

struct Elf64GeometryConstants {
    static constexpr uint32_t kBinarySizeBytes      = 51232u;
    static constexpr uint32_t kDynsymOffset         = 0x000530u;
    static constexpr uint32_t kDynsymSizeBytes      = 1632u;
    static constexpr uint32_t kDynsymEntryCount     = 68u;
    static constexpr uint32_t kImportedSymbolCount  = 28u; // [003]..[030]
    static constexpr uint32_t kExportedSymbolCount  = 37u; // [031]..[067]

    static constexpr uint32_t kRelaDynOffset        = 0x001658u;
    static constexpr uint32_t kRelaDynSizeBytes     = 456u;
    static constexpr uint32_t kRelaDynEntryCount    = 19u;

    static constexpr uint32_t kRelaPltOffset        = 0x001820u;
    static constexpr uint32_t kRelaPltSizeBytes     = 936u;
    static constexpr uint32_t kRelaPltEntryCount    = 39u;

    static constexpr uint32_t kPltVaddr             = 0x001bd0u;
    static constexpr uint32_t kPltSizeBytes         = 656u;

    static constexpr uint32_t kTextVaddr            = 0x001e60u;
    static constexpr uint32_t kTextSizeBytes        = 20368u;

    static constexpr uint32_t kRodataVaddr          = 0x006df0u;
    static constexpr uint32_t kRodataSizeBytes      = 805u;

    static constexpr uint32_t kFiniArrayVaddr       = 0x00fc08u;
    static constexpr uint32_t kDataRelRoVaddr       = 0x00fc18u;
    static constexpr uint32_t kGotVaddr             = 0x00fe30u;
    static constexpr uint32_t kDataVaddr            = 0x010000u;
    static constexpr uint32_t kBssVaddr             = 0x010010u;
    static constexpr uint32_t kBssEndVaddr          = 0x0102b0u;
    static constexpr uint32_t kBssSizeBytes         = 672u; // 0x02a0
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

constexpr jint     kJniVersion1_2 = 0x00010002; // mov w2, #2; movk w2, #1, lsl #16 @ 0x001ebc..0x001ed8
constexpr jint     kJniErr        = -1;         // mov w0, #-1 @ 0x001ee8
constexpr jboolean kJniFalse      = 0u;
constexpr jboolean kJniTrue       = 1u;

/**
 * @brief Exact 32-byte AArch64 AAPCS64 `std::va_list` (`__va_list`) constructed on stack
 *        at `[x29, #-0x38]` and copied via `ldp q1, q0, [x9]; stp q1, q0, [x29, #-0x60]`
 *        in all 6 `_JNIEnv` variadic helpers (`0x0022bc`, `0x002358`, `0x00252c`,
 *        `0x002720`, `0x002bac`, `0x002d60`).
 *        Cấu trúc `va_list` 32-byte chuẩn AAPCS64 được dựng tại `[x29, #-0x38]` trong
 *        6 hàm hỗ trợ biến đối số `_JNIEnv`.
 *
 * Notice at `0x0022f0..0x0022fc`:
 * - `mov x8, #-0x28` (`0xffffffffffffffd8`)
 * - `movk x8, #0xff80, lsl #32` -> `x8 = 0xffffff80ffffffd8`
 *   - Low 32 bits (`__gr_offs`)  = `-0x28` (`-40`, 5 general registers `x3..x7` saved at `[sp, #0x88..#0xaf]`)
 *   - High 32 bits (`__vr_offs`) = `-0x80` (`-128`, 8 SIMD registers `q0..q7` saved at `[sp, #0x00..#0x7f]`)
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
// 3. `.rodata` Constants (`0x006df0..0x007114`, 805 bytes)
//    Hằng số Chuỗi & Bảng Nhảy `.rodata` (`0x006df0..0x007114`, 805 byte)
// ============================================================================

struct RodataConstants {
    static constexpr const char* kClassSandboxBridge                = "com/bytedance/helios/network/SandboxBridge";                        // 0x006df0
    static constexpr const char* kClassNetworkDomainRecognize       = "com/bytedance/helios/network/pipeline/recognize/NetworkDomainRecognize"; // 0x006e1b
    static constexpr const char* kMethodHandleByPumbaa              = "handleByPumbaa";                                                    // 0x006e62
    static constexpr const char* kSigHandleByPumbaa                 = "(Ljava/lang/String;Ljava/lang/String;Ljava/util/Map;Ljava/nio/ByteBuffer;ILjava/util/Map;)I"; // 0x006e71
    static constexpr const char* kMethodHandleByPumbaa2             = "handleByPumbaa2";                                                   // 0x006ecd
    static constexpr const char* kSigHandleByPumbaa2                = "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/nio/ByteBuffer;ILjava/lang/String;)I"; // 0x006edd
    static constexpr const char* kMethodDomainIdentityRecognize     = "domainIdentityRecognize";                                           // 0x006f3f
    static constexpr const char* kSigDomainIdentityRecognize        = "(Ljava/lang/String;)Ljava/lang/String;";                            // 0x006f57
    static constexpr const char* kMethodMatchAgSchema               = "matchAgSchema";                                                     // 0x006f7e
    static constexpr const char* kSigMatchAgSchema                  = "(Ljava/lang/String;)Z";                                             // 0x006f8c
    static constexpr const char* kClassHashMap                      = "java/util/HashMap";                                                 // 0x006fa2
    static constexpr const char* kMethodInit                        = "<init>";                                                            // 0x006fb4
    static constexpr const char* kSigInitInt                        = "(I)V";                                                              // 0x006fbb
    static constexpr const char* kMethodPut                         = "put";                                                               // 0x006fc0
    static constexpr const char* kSigPut                            = "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;";          // 0x006fc4
    static constexpr const char* kLogTag                            = "Pumbaa_Log";                                                        // 0x006ffd
    static constexpr const char* kErrEnvNotInit                     = "env not init!";                                                     // 0x007008
    static constexpr const char* kMethodMonitorCost                 = "monitorCost";                                                       // 0x007016
    static constexpr const char* kSigMonitorCost                    = "(Ljava/lang/String;J)V";                                            // 0x007022
    static constexpr const char* kLabelHandleByPumbaaForSandbox     = "handleByPumbaaForSandbox";                                          // 0x007039
    static constexpr const char* kLabelBasicString                  = "basic_string";                                                      // 0x007052
    static constexpr const char* kDwarfAugmentationWWW              = "WWW";                                                               // 0x0070dc
};

// ============================================================================
// 4. `.bss` Global Segment Layout (`0x010010..0x0102af`, `672 bytes = 0x2a0`)
//    Bố cục Phân đoạn Toàn cục `.bss` (`0x010010..0x0102af`, `672 byte`)
// ============================================================================

/**
 * @brief Exact layout of the 11 exported JNI global symbols at `.bss 0x010010..0x010067`
 *        plus the `libunwind` DWARF register size table at `.bss 0x010070..0x0100d0`:
 *        - `+0x000 (0x010010)`: `gClassNativeBridge` (`[031]`, `8 B`)
 *        - `+0x008 (0x010018)`: `gNetworkDomainRecognize` (`[037]`, `8 B`)
 *        - `+0x010 (0x010020)`: `gMethodHandleFromNativeSandbox` (`[065]`, `8 B`)
 *        - `+0x018 (0x010028)`: `gMethodHandleFromNativeSandboxJson` (`[054]`, `8 B`)
 *        - `+0x020 (0x010030)`: `gMethodDomainIdentityRecognize` (`[066]`, `8 B`)
 *        - `+0x028 (0x010038)`: `gMethodMatchAgSchema` (`[049]`, `8 B`)
 *        - `+0x030 (0x010040)`: `gMethodMonitorCost` (`[053]`, `8 B`)
 *        - `+0x038 (0x010048)`: `gClassHashMap` (`[056]`, `8 B`)
 *        - `+0x040 (0x010050)`: `gMethodHashMapConstructor` (`[033]`, `8 B`)
 *        - `+0x048 (0x010058)`: `gMethodPut` (`[044]`, `8 B`)
 *        - `+0x050 (0x010060)`: `gJvm` (`[048]`, `8 B`)
 *        - `+0x058 (0x010068)`: `reserved_0x10068` (`8 B`)
 *        - `+0x060 (0x010070)`: `dwarf_reg_size_table[97]` (`0x010070..0x0100d0`, initialized at `0x00379c`: `[0..31] = 8`, `[64..96] = 8`)
 */
struct PumbaaNetworkBssSegment {
    jclass    gClassNativeBridge;                  // +0x000 (0x010010) [031]
    jclass    gNetworkDomainRecognize;             // +0x008 (0x010018) [037]
    jmethodID gMethodHandleFromNativeSandbox;      // +0x010 (0x010020) [065]
    jmethodID gMethodHandleFromNativeSandboxJson;  // +0x018 (0x010028) [054]
    jmethodID gMethodDomainIdentityRecognize;      // +0x020 (0x010030) [066]
    jmethodID gMethodMatchAgSchema;                // +0x028 (0x010038) [049]
    jmethodID gMethodMonitorCost;                  // +0x030 (0x010040) [053]
    jclass    gClassHashMap;                       // +0x038 (0x010048) [056]
    jmethodID gMethodHashMapConstructor;           // +0x040 (0x010050) [033]
    jmethodID gMethodPut;                          // +0x048 (0x010058) [044]
    JavaVM*   gJvm;                                // +0x050 (0x010060) [048]
    uint64_t  reserved_0x10068;                    // +0x058 (0x010068)
    uint8_t   dwarf_reg_size_table[97];            // +0x060 (0x010070..0x0100d0)
    uint8_t   unwinder_cache_storage[479];         // +0x0c1 (0x0100d1..0x0102af)
};
static_assert(sizeof(PumbaaNetworkBssSegment) == 672, "PumbaaNetworkBssSegment must be 672 bytes (0x2a0)");
static_assert(offsetof(PumbaaNetworkBssSegment, gClassNativeBridge) == 0x00, "Offset 0x010010 mismatch");
static_assert(offsetof(PumbaaNetworkBssSegment, gNetworkDomainRecognize) == 0x08, "Offset 0x010018 mismatch");
static_assert(offsetof(PumbaaNetworkBssSegment, gMethodHandleFromNativeSandbox) == 0x10, "Offset 0x010020 mismatch");
static_assert(offsetof(PumbaaNetworkBssSegment, gMethodHandleFromNativeSandboxJson) == 0x18, "Offset 0x010028 mismatch");
static_assert(offsetof(PumbaaNetworkBssSegment, gMethodDomainIdentityRecognize) == 0x20, "Offset 0x010030 mismatch");
static_assert(offsetof(PumbaaNetworkBssSegment, gMethodMatchAgSchema) == 0x28, "Offset 0x010038 mismatch");
static_assert(offsetof(PumbaaNetworkBssSegment, gMethodMonitorCost) == 0x30, "Offset 0x010040 mismatch");
static_assert(offsetof(PumbaaNetworkBssSegment, gClassHashMap) == 0x38, "Offset 0x010048 mismatch");
static_assert(offsetof(PumbaaNetworkBssSegment, gMethodHashMapConstructor) == 0x40, "Offset 0x010050 mismatch");
static_assert(offsetof(PumbaaNetworkBssSegment, gMethodPut) == 0x48, "Offset 0x010058 mismatch");
static_assert(offsetof(PumbaaNetworkBssSegment, gJvm) == 0x50, "Offset 0x010060 mismatch");
static_assert(offsetof(PumbaaNetworkBssSegment, dwarf_reg_size_table) == 0x60, "Offset 0x010070 mismatch");

// ============================================================================
// 5. `std::__ndk1::basic_string` (24B) & `std::__ndk1::__tree_node` (80B = 0x50) ABI
//    Bố cục ABI `basic_string` (24B) & Nút Cây Đỏ-Đen `__tree_node` (80B = 0x50)
// ============================================================================

/**
 * @brief Exact 24-byte libc++ (`std::__ndk1::basic_string<char>`) layout on AArch64:
 *        - Short string mode (`byte[0] & 1 == 0`): length = `byte[0] >> 1` (`0..22`), chars at `byte[1..23]`.
 *        - Long string mode (`byte[0] & 1 == 1`): `+0x00` `cap | 1`, `+0x08` `size`, `+0x10` `char* data`.
 *        Verified at `0x0021dc..0x002218`, `0x002f4c..0x002f98`, and `0x003384..0x003424`.
 */
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

/**
 * @brief Exact 80-byte (`0x50`) layout of `std::__ndk1::__tree_node<std::__ndk1::__value_type<std::string, std::string>, void*>`
 *        allocated via `operator new(0x50)` (`mov w0, #0x50; bl #0x1dd0` at `0x002e44..0x002e48`):
 *        - `+0x00`: `__left_` (`__tree_node_base*`)
 *        - `+0x08`: `__right_` (`__tree_node_base*`)
 *        - `+0x10`: `__parent_` (`__tree_end_node*`)
 *        - `+0x18`: `__is_black_` (`bool`, `strb w8, [x1, #0x18]` in `__tree_balance_after_insert` @ `0x00344c`)
 *        - `+0x20`: `key` (`LibcxxString24Abi`, `add x23, x0, #0x20` @ `0x002e50`)
 *        - `+0x38`: `value` (`LibcxxString24Abi`, `add x0, x19, #0x38` @ `0x002e60`)
 */
struct RbTreeNodeStringPairAbi {
    RbTreeNodeStringPairAbi* left;        // +0x00
    RbTreeNodeStringPairAbi* right;       // +0x08
    RbTreeNodeStringPairAbi* parent;      // +0x10
    uint8_t                  is_black;    // +0x18
    uint8_t                  pad_19[7];   // +0x19..+0x1f
    LibcxxString24Abi        key;         // +0x20..+0x37
    LibcxxString24Abi        value;       // +0x38..+0x4f
};
static_assert(sizeof(RbTreeNodeStringPairAbi) == 80, "RbTreeNodeStringPairAbi must be 80 bytes (0x50)");
static_assert(offsetof(RbTreeNodeStringPairAbi, is_black) == 0x18, "Offset +0x18 mismatch");
static_assert(offsetof(RbTreeNodeStringPairAbi, key) == 0x20, "Offset +0x20 mismatch");
static_assert(offsetof(RbTreeNodeStringPairAbi, value) == 0x38, "Offset +0x38 mismatch");

/**
 * @brief Exact 24-byte layout of `std::__ndk1::map<std::string, std::string>`:
 *        - `+0x00`: `__begin_node_` (`ldr x24, [x19], #8` @ `0x0021a4`)
 *        - `+0x08`: `__pair1_.first_` (`__tree_end_node` root pointer, `stp xzr, xzr, [sp, #0x60]` @ `0x0028c4`)
 *        - `+0x10`: `__pair3_.first_` (`size_t size`, `ldr w3, [x19, #0x10]` @ `0x00218c`)
 */
struct LibcxxMapStringAbi {
    RbTreeNodeStringPairAbi* begin_node; // +0x00
    RbTreeNodeStringPairAbi* end_left;   // +0x08
    uint64_t                 node_count; // +0x10
};
static_assert(sizeof(LibcxxMapStringAbi) == 24, "LibcxxMapStringAbi must be 24 bytes (0x18)");

// ============================================================================
// 6. Signed 64-bit Reciprocal Division-by-1000 Math (`0x002b10..0x002b60`)
//    Toán học Chia Có dấu 64-bit cho 1000 (`0x002b10..0x002b60`)
// ============================================================================
//
// In `handleByPumbaaForSandbox` (`0x002b10..0x002b60`), elapsed time between
// `gettimeofday(&tv_start)` (`[sp, #0x10..#0x18]`: `tv_start.tv_usec` at `[sp, #0x10]`,
// `tv_start.tv_sec` at `[sp, #0x18]` stored reversed via `stp x26, x24, [sp, #0x10]` @ `0x002870`)
// and `gettimeofday(&tv_end)` (`[sp, #0x20..#0x28]`: `x9 = tv_end.tv_sec`, `x8 = tv_end.tv_usec`)
// is converted to milliseconds using two signed 64-bit magic multipliers:
// - `M_pos =  0x20c49ba5e353f7cf` (`ceil(2^64 * 2^7 / 1000)`)
// - `M_neg = -0x20c49ba5e353f7cf = 0xdf3b645a1cac0831`

struct MicrosToMillisMath {
    static constexpr uint64_t kMagicPosDiv1000 = 0x20c49ba5e353f7cfULL;
    static constexpr uint64_t kMagicNegDiv1000 = 0xdf3b645a1cac0831ULL;

    static inline int64_t SignedDiv1000Positive(int64_t tv_usec) noexcept {
        const __int128 prod = static_cast<__int128>(tv_usec) *
                              static_cast<__int128>(static_cast<int64_t>(kMagicPosDiv1000));
        const int64_t smulh_val = static_cast<int64_t>(prod >> 64);
        const int64_t shifted   = smulh_val >> 7;
        const int64_t sign_bit  = static_cast<int64_t>(static_cast<uint64_t>(smulh_val) >> 63);
        return shifted + sign_bit;
    }

    static inline int64_t SignedDiv1000Negative(int64_t tv_usec) noexcept {
        const __int128 prod = static_cast<__int128>(tv_usec) *
                              static_cast<__int128>(static_cast<int64_t>(kMagicNegDiv1000));
        const int64_t smulh_val = static_cast<int64_t>(prod >> 64);
        const int64_t shifted   = smulh_val >> 7;
        const int64_t sign_bit  = static_cast<int64_t>(static_cast<uint64_t>(smulh_val) >> 63);
        return shifted + sign_bit;
    }

    static inline int64_t ComputeElapsedCostMs(int64_t start_sec,
                                               int64_t start_usec,
                                               int64_t end_sec,
                                               int64_t end_usec) noexcept {
        const int64_t end_ms_part   = SignedDiv1000Positive(end_usec);   // 0x002b2c, 0x002b48, 0x002b50
        const int64_t start_ms_neg  = SignedDiv1000Negative(start_usec); // 0x002b3c, 0x002b40, 0x002b4c
        const int64_t sec_diff      = end_sec - start_sec;               // 0x002b44: sub x9, x9, x10
        const int64_t usec_ms_diff  = end_ms_part + start_ms_neg;        // 0x002b58: add x8, x8, x11
        return sec_diff * 1000LL + usec_ms_diff;                         // 0x002b60: madd x1, x9, x10, x8
    }
};

} // namespace pumbaa_network
} // namespace opencut
} // namespace nextai

#endif // NEXTAI_OPENCUT_PUMBAA_NETWORK_TYPES_H_
