/**
 * @file jnidispatch_types.h
 * @brief Clean-Room ABI Structs, Constants & libffi AArch64 Descriptors for libjnidispatch.so.
 *        Cấu trúc ABI, hằng số và các bộ mô tả kiểu libffi AArch64 cho libjnidispatch.so (JNA 7.0.4).
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libjnidispatch.so
 *   Size / Dung lượng: 165,992 bytes (0x28868)
 *   SHA-256: ddfc6c965bbe366615c000ec1f06552ddf0bb2b4f9d921d0bff8c75b3cb2ca4c
 *   Sections / Các phân đoạn ELF:
 *     - .text        : VMA 0x004000..0x020080 (114,816 bytes)
 *     - .rodata      : VMA 0x020080..0x022a90 (10,768 bytes)
 *     - .eh_frame_hdr: VMA 0x022a90..0x02300c (1,404 bytes)
 *     - .eh_frame    : VMA 0x023010..0x025338 (9,000 bytes)
 *     - .data.rel.ro : VMA 0x02bb98..0x02bc70 (file offset 0x027b98, 216 bytes)
 *     - .data        : VMA 0x02c000..0x02c244 (file offset 0x028000, 580 bytes)
 *     - .bss         : VMA 0x02c248..0x02ca80 (2,104 bytes)
 *
 * Evidence Classification / Phân loại bằng chứng:
 *   [OBSERVED] Directly verified from AArch64 machine code & .rodata/.data.rel.ro bytes of libjnidispatch.so.
 *              Được kiểm chứng trực tiếp từ mã máy AArch64 và byte .rodata/.data.rel.ro của libjnidispatch.so.
 */

#ifndef NEXTAI_OPENCUT_JNIDISPATCH_TYPES_H_
#define NEXTAI_OPENCUT_JNIDISPATCH_TYPES_H_

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace nextai {
namespace opencut {
namespace jnidispatch {

/**
 * @brief Binary & Version Constants [OBSERVED at .rodata 0x021738 & 0x021740]
 *        Hằng số định danh nhị phân và phiên bản JNA [QUAN SÁT ĐƯỢC tại .rodata 0x021738 & 0x021740]
 *
 * - `kJnaNativeVersion`: `"7.0.4"` at `.rodata 0x021738` (loaded at `0x009820..0x009830` in `Java_com_sun_jna_Native_getNativeVersion`).
 * - `kJnaApiChecksum`: `"5fb98531302accd485c534c452dd952a"` at `.rodata 0x021740` (loaded at `0x009834..0x009844` in `Java_com_sun_jna_Native_getAPIChecksum`).
 * - `kJnaMaxStackArgs`: `256` (`0x100`, checked via `cmp w0, #0x100; b.gt #0x6334` at `0x005e84..0x005e8c` in `dispatch`).
 */
constexpr uint32_t kBinarySizeBytes          = 165992U;
constexpr const char* kJnaNativeVersion      = "7.0.4";
constexpr const char* kJnaApiChecksum        = "5fb98531302accd485c534c452dd952a";
constexpr int32_t kJnaMaxDispatchArguments   = 256;

/**
 * @brief libffi Status Codes (`ffi_status`) [OBSERVED at 0x004dfc, 0x00cfdc, 0x010e0c]
 *        Mã trạng thái trả về của libffi (`ffi_status`) [QUAN SÁT ĐƯỢC tại 0x004dfc, 0x00cfdc, 0x010e0c]
 */
enum FfiStatus : int32_t {
    FFI_OK          = 0,
    FFI_BAD_TYPEDEF = 1,
    FFI_BAD_ABI     = 2,
    FFI_BAD_ARGTYPE = 3,
};

/**
 * @brief libffi AArch64 ABI Enumeration (`ffi_abi`) [OBSERVED at 0x010e20..0x010e2c]
 *        Bảng liệt kê ABI AArch64 của libffi (`sub w4, w4, #1; cmp w4, #1; b.ls` -> accepts 1..2)
 */
enum FfiAbi : uint32_t {
    FFI_FIRST_ABI   = 0U,
    FFI_SYSV        = 1U,
    FFI_WIN64       = 2U,
    FFI_DEFAULT_ABI = FFI_SYSV,
};

/**
 * @brief libffi Type Codes (`FFI_TYPE_*`) [OBSERVED at .rodata 0x022858..0x022990 & .data.rel.ro 0x02bb98..0x02bbe0]
 *        Mã kiểu dữ liệu libffi (`FFI_TYPE_*`) [QUAN SÁT ĐƯỢC tại .rodata 0x022858..0x022990]
 */
enum FfiTypeCode : uint16_t {
    FFI_TYPE_VOID       = 0U,
    FFI_TYPE_INT        = 1U,
    FFI_TYPE_FLOAT      = 2U,
    FFI_TYPE_DOUBLE     = 3U,
    FFI_TYPE_LONGDOUBLE = 4U,
    FFI_TYPE_UINT8      = 5U,
    FFI_TYPE_SINT8      = 6U,
    FFI_TYPE_UINT16     = 7U,
    FFI_TYPE_SINT16     = 8U,
    FFI_TYPE_UINT32     = 9U,
    FFI_TYPE_SINT32     = 10U,
    FFI_TYPE_UINT64     = 11U,
    FFI_TYPE_SINT64     = 12U,
    FFI_TYPE_STRUCT     = 13U,
    FFI_TYPE_POINTER    = 14U,
    FFI_TYPE_COMPLEX    = 15U,
};

/**
 * @brief AArch64 AAPCS64 Return / CIF Flags [OBSERVED at 0x010408..0x010904]
 *        Cờ trạng thái trả về & HFA/HVA của AAPCS64 trong `ffi_cif.flags` (+0x1c)
 *
 * - Bits [1:0] : HFA element count `4 - (flags & 3)` when HFA flag is set (`0x0109d8: and w12, w0, #3; mov w0, #4; sub w0, w0, w12`).
 * - Bit 5 (`0x0020`) : Non-void return / needs stack frame allocation (`tbz w28, #5, #0x10ac0` at `0x010904`).
 * - Bit 7 (`0x0080`) : Vector/HFA closure entry (`tbz w1, #7, #0x10e9c` at `0x010e58` & `tbnz w0, #7, #0x10f50` at `0x010f30`).
 * - Bit 8 (`0x0100`) : Variadic CIF (`AARCH64_FLAG_ARG_V`, `tbz w28, #8, #0x10904; and w28, w28, #0xfffffeff` at `0x0108f8..0x0108fc`).
 */
constexpr uint32_t kAarch64RetVoid           = 0U;
constexpr uint32_t kAarch64RetNeedAlloc      = (1U << 5U);   // 0x0020
constexpr uint32_t kAarch64FlagVectorClosure = (1U << 7U);   // 0x0080
constexpr uint32_t kAarch64FlagArgVariadic   = (1U << 8U);   // 0x0100

/**
 * @brief 24-Byte `ffi_type` Descriptor ABI Layout [OBSERVED at 0x022858..0x022990]
 *        Cấu trúc ABI 24-byte của `ffi_type` [QUAN SÁT ĐƯỢC tại 0x022858..0x022990]
 *
 * Verified at `0x00d06c..0x00d080` and `0x010980..0x010984`:
 *   - `+0x00` : `size_t size`        (8 bytes, `ldr x8, [x5]`)
 *   - `+0x08` : `uint16_t alignment` (2 bytes, `ldrh w2, [x5, #8]`)
 *   - `+0x0a` : `uint16_t type`      (2 bytes, `ldrh w0, [x5, #0xa]`)
 *   - `+0x0c` : `uint32_t _pad`      (4 bytes padding on 64-bit)
 *   - `+0x10` : `ffi_type** elements`(8 bytes, null-terminated array for `FFI_TYPE_STRUCT`)
 */
struct FfiType {
    size_t     size;
    uint16_t   alignment;
    uint16_t   type;
    uint32_t   _pad;
    FfiType**  elements;
};
static_assert(sizeof(FfiType) == 24, "FfiType must be exactly 24 bytes on AArch64");

/**
 * @brief 32-Byte `ffi_cif` Call Interface Descriptor [OBSERVED at 0x00ce60..0x010974]
 *        Cấu trúc ABI 32-byte của `ffi_cif` [QUAN SÁT ĐƯỢC tại 0x00ce60..0x010974]
 *
 * Offsets verified in `ffi_call_int` (`0x0108b4..0x010974`) and `ffi_prep_closure_loc` (`0x010e20..0x010e48`):
 *   - `+0x00` : `uint32_t abi`       (`ldr w4, [x1]` at `0x010e20`)
 *   - `+0x04` : `uint32_t nargs`     (`ldr w6, [x26, #4]` at `0x010934`)
 *   - `+0x08` : `FfiType** arg_types`(`ldr x0, [x26, #8]` at `0x010974`)
 *   - `+0x10` : `FfiType* rtype`     (`ldr x0, [x0, #0x10]` at `0x0108d8`)
 *   - `+0x18` : `uint32_t bytes`     (`ldr w27, [x26, #0x18]` at `0x0108f4`, stack argument bytes)
 *   - `+0x1c` : `uint32_t flags`     (`ldr w28, [x26, #0x1c]` at `0x0108e8`, AAPCS64 return/HFA/variadic flags)
 */
struct FfiCif {
    uint32_t  abi;
    uint32_t  nargs;
    FfiType** arg_types;
    FfiType*  rtype;
    uint32_t  bytes;
    uint32_t  flags;
};
static_assert(sizeof(FfiCif) == 32, "FfiCif must be exactly 32 bytes on AArch64");

/**
 * @brief 48-Byte `ffi_closure` Executable Closure Descriptor [OBSERVED at 0x010e0c..0x010f0c]
 *        Cấu trúc ABI 48-byte của `ffi_closure` [QUAN SÁT ĐƯỢC tại 0x010e0c..0x010f0c]
 *
 * Offsets verified in `ffi_prep_closure_loc` (`0x010e6c..0x010ee8`):
 *   - `+0x00..0x0f` : `uint8_t tramp[16]` (or `void* ftramp` at `+0x00` when static trampoline active;
 *                     16-byte machine code copied from `.rodata 0x022a80`:
 *                     `0x58000090` (`ldr x16, #0x10`), `0x10fffff1` (`adr x17, #-4`), `0xd61f0200` (`br x16`), `0x00000000`)
 *   - `+0x10`       : `void* fun_target`  (`str x0, [x19, #0x10]` at `0x010edc`, points to `ffi_closure_SYSV` or `ffi_closure_SYSV_V`)
 *   - `+0x18`       : `FfiCif* cif`       (`str x20, [x19, #0x18]` at `0x010e78`)
 *   - `+0x20`       : `void (*fun)(FfiCif*, void*, void**, void*)` (`str x21, [x19, #0x20]` at `0x010e80`)
 *   - `+0x28`       : `void* user_data`   (`str x22, [x19, #0x28]` at `0x010e88`)
 */
struct FfiClosure {
    uint8_t tramp[16];
    void*   fun_target;
    FfiCif* cif;
    void    (*fun)(FfiCif* cif, void* ret, void** args, void* user_data);
    void*   user_data;
};
static_assert(sizeof(FfiClosure) == 48, "FfiClosure must be exactly 48 bytes on AArch64");

/**
 * @brief 24-Byte `ffi_go_closure` Descriptor [OBSERVED at 0x010f10..0x010f58]
 *        Cấu trúc ABI 24-byte của `ffi_go_closure` [QUAN SÁT ĐƯỢC tại 0x010f10..0x010f58]
 *
 *   - `+0x00` : `void* tramp` (`str x0, [x4]` at `0x010f3c`, `0x01c000` or `0x01c020`)
 *   - `+0x08` : `FfiCif* cif` (`str x1, [x4, #8]` at `0x010f44`)
 *   - `+0x10` : `void (*fun)(FfiCif*, void*, void**, void*)` (`str x2, [x4, #0x10]` at `0x010f48`)
 */
struct FfiGoClosure {
    void*   tramp;
    FfiCif* cif;
    void    (*fun)(FfiCif* cif, void* ret, void** args, void* user_data);
};
static_assert(sizeof(FfiGoClosure) == 24, "FfiGoClosure must be exactly 24 bytes on AArch64");

/**
 * @brief AArch64 Call Context Frame (`call_context`, 192 bytes = `0xc0`) [OBSERVED at 0x010924 & 0x011128..0x0112a8]
 *        Khung thanh ghi ngữ cảnh lời gọi AArch64 (`0xc0 = 192 bytes`) [QUAN SÁT ĐƯỢC tại 0x010924 & 0x011128..0x0112a8]
 *
 * - `+0x00..0x7f` : `v[0..7]`  (8 x 16-byte SIMD/FP registers `q0..q7` = 128 bytes, indexed via `add x13, x3, x2, lsl #4` at `0x011240`)
 * - `+0x80..0xbf` : `x[0..7]`  (8 x 8-byte general registers `x0..x7` = 64 bytes, indexed via `add x0, x0, #0x10; add x0, x3, x0, lsl #3` at `0x011130..0x011134`)
 */
struct Aarch64CallContext {
    uint64_t v_regs[8][2];  // +0x00..0x7f: 8 x 128-bit Q registers (128 B)
    uint64_t x_regs[8];     // +0x80..0xbf: 8 x 64-bit X registers (64 B)
};
static_assert(sizeof(Aarch64CallContext) == 192, "Aarch64CallContext must be 192 bytes (0xc0)");

/**
 * @brief AArch64 Closure Trampoline Machine Code Template [OBSERVED at .rodata 0x022a80..0x022a8f]
 *        Mẫu mã máy Trampoline 16-byte của `ffi_closure` [QUAN SÁT ĐƯỢC tại .rodata 0x022a80..0x022a8f]
 */
constexpr uint32_t kAarch64TrampolineInsn0 = 0x58000090U;  // ldr x16, #0x10 (loads fun_target at +0x10)
constexpr uint32_t kAarch64TrampolineInsn1 = 0x10FFFFF1U;  // adr x17, #-4   (loads closure address at +0x00)
constexpr uint32_t kAarch64TrampolineInsn2 = 0xD61F0200U;  // br  x16        (jumps to fun_target)
constexpr uint32_t kAarch64TrampolineInsn3 = 0x00000000U;  // padding

/**
 * @brief AArch64 Static Trampoline Architecture Parameters [OBSERVED at `ffi_tramp_arch` 0x0112ac..0x0112c4]
 *        Thông số kiến trúc Trampoline tĩnh AArch64 [QUAN SÁT ĐƯỢC tại `ffi_tramp_arch` 0x0112ac..0x0112c4]
 *
 * - `0x0112ac: mov x2, #0x20; str x2, [x0]`   -> `tramp_size = 32` (`0x20`)
 * - `0x0112b4: mov x0, #0x4000; str x0, [x1]` -> `map_size   = 16384` (`0x4000`)
 */
constexpr size_t kFfiTrampEntrySize = 0x20U;
constexpr size_t kFfiTrampMapSize   = 0x4000U;

/**
 * @brief JNA `Native.sizeof(int type)` Jump Table Constants [OBSERVED at 0x008a0c..0x008ad0 & .rodata 0x0201c4]
 *        Bảng nhảy `Native.sizeof(int type)` [QUAN SÁT ĐƯỢC tại 0x008a0c..0x008ad0 & .rodata 0x0201c4]
 *
 * Type indices `0..5` map via `.rodata 0x0201c4` (`[0, 0, 10, 0, 5, 15]`) multiplied by 4 (`sxtb #2` at `0x008a7c`):
 *   - `0` (`TYPE_VOID_PTR`)   -> offset `+0`  (`0x008a84`: returns `8`)
 *   - `1` (`TYPE_LONG`)       -> offset `+0`  (`0x008a84`: returns `8`)
 *   - `2` (`TYPE_WCHAR_T`)    -> offset `+40` (`0x008aac`: returns `4`)
 *   - `3` (`TYPE_SIZE_T`)     -> offset `+0`  (`0x008a84`: returns `8`)
 *   - `4` (`TYPE_BOOL`)       -> offset `+20` (`0x008a98`: returns `1`)
 *   - `5` (`TYPE_LONG_DOUBLE`)-> offset `+60` (`0x008ac0`: returns `16` = `0x10`)
 *   - `> 5`                   -> throws `IllegalArgumentException("Invalid sizeof type %d")` and returns `-1`.
 */
enum JnaSizeofType : int32_t {
    JNA_SIZEOF_VOID_PTR    = 0,
    JNA_SIZEOF_LONG        = 1,
    JNA_SIZEOF_WCHAR_T     = 2,
    JNA_SIZEOF_SIZE_T      = 3,
    JNA_SIZEOF_BOOL        = 4,
    JNA_SIZEOF_LONG_DOUBLE = 5,
};

/**
 * @brief JNA Conversion Flag Enumeration [OBSERVED at `get_conversion_flag` 0x005860..0x0059d4]
 *        Cờ chuyển đổi kiểu dữ liệu giữa Java và Native [QUAN SÁT ĐƯỢC tại `0x005860..0x0059d4`]
 */
enum JnaConversionFlag : int32_t {
    CVT_DEFAULT         = 0,
    CVT_POINTER         = 1,
    CVT_STRING          = 2,
    CVT_STRUCTURE       = 3,
    CVT_STRUCTURE_BYVAL = 4,
    CVT_BUFFER          = 5,
    CVT_ARRAY_BYTE      = 6,
    CVT_ARRAY_SHORT     = 7,
    CVT_ARRAY_CHAR      = 8,
    CVT_ARRAY_INT       = 9,
    CVT_ARRAY_LONG      = 10,
    CVT_ARRAY_FLOAT     = 11,
    CVT_ARRAY_DOUBLE    = 12,
    CVT_ARRAY_BOOLEAN   = 13,
    CVT_BOOLEAN         = 14,
    CVT_CALLBACK        = 15,
    CVT_FLOAT           = 16,
    CVT_NATIVE_MAPPED   = 17,
    CVT_NATIVE_MAPPED_STRING = 18,
    CVT_NATIVE_MAPPED_WSTRING = 19,
    CVT_WSTRING         = 20,
    CVT_INTEGER_TYPE    = 21,
    CVT_POINTER_TYPE    = 22,
    CVT_TYPE_MAPPER     = 23,
    CVT_TYPE_MAPPER_STRING = 24,
    CVT_TYPE_MAPPER_WSTRING = 25,
    CVT_OBJECT          = 26,
    CVT_JNIENV          = 27,
};

/**
 * @brief JNA Thread-Local Storage (`thread_storage`) [OBSERVED at `JNA_set_last_error` 0x00cc50..0x00cd5c]
 *        Bộ nhớ cục bộ theo luồng của JNA (`last_error`, `env`, `name`) [QUAN SÁT ĐƯỢC tại `0x00cc50..0x00cd5c`]
 */
struct JnaThreadStorage {
    int32_t     last_error;
    bool        detach_state;
    std::string thread_name;
};

}  // namespace jnidispatch
}  // namespace opencut
}  // namespace nextai

#endif  // NEXTAI_OPENCUT_JNIDISPATCH_TYPES_H_
