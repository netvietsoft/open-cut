/**
 * @file libffi_aarch64_engine.h
 * @brief Clean-Room Header for libffi AArch64 AAPCS64 CIF, Call Frame, Closure & I-Cache Engine.
 *        Header tái tạo sạch cho Engine libffi AArch64 AAPCS64 (CIF, Khung gọi, Closure & Đồng bộ Cache).
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libjnidispatch.so
 *   Addresses covered / Phạm vi địa chỉ:
 *     - 0x00ce60..0x00d150 : ffi_prep_cif_core, ffi_prep_cif, ffi_prep_cif_var, ffi_get_struct_offsets
 *     - 0x00df10..0x00f9f4 : open_temp_exec_file, ffi_closure_alloc, ffi_closure_free
 *     - 0x00ffec..0x01029c : ffi_tramp_is_supported, ffi_tramp_alloc, ffi_tramp_set_parms, ffi_tramp_get_addr, ffi_tramp_free
 *     - 0x0102a0..0x0108b0 : AAPCS64 HFA/HVA Classifier & ffi_prep_cif_machdep
 *     - 0x0108b4..0x010f58 : ffi_call_int, ffi_call, ffi_call_go, ffi_prep_closure_loc, ffi_prep_go_closure
 *     - 0x010f5c..0x0112c4 : ffi_closure_SYSV_inner, ffi_call_SYSV, ffi_closure_SYSV, ffi_tramp_arch
 *     - 0x020000..0x02007c : __clear_cache & __aarch64_sync_cache_range (ctr_el0 dc cvau / ic ivau)
 */

#ifndef NEXTAI_OPENCUT_JNIDISPATCH_LIBFFI_AARCH64_ENGINE_H_
#define NEXTAI_OPENCUT_JNIDISPATCH_LIBFFI_AARCH64_ENGINE_H_

#include "jnidispatch_types.h"

#include <cstddef>
#include <cstdint>

namespace nextai {
namespace opencut {
namespace jnidispatch {

/**
 * @brief Classifies whether an `FfiType` is an AAPCS64 Homogeneous Floating-Point Aggregate (HFA)
 *        with 1..4 elements of `float`, `double`, or `long double` (`0x010724..0x0108b0`).
 *        Phân loại cấu trúc HFA (1..4 phần tử dấu phẩy động đồng nhất) theo chuẩn AAPCS64 (`0x010724..0x0108b0`).
 *
 * @return Non-zero HFA descriptor where `count = 4 - (desc & 3)` (`0x0109d8..0x0109e0`), or `0` if not HFA.
 */
uint32_t ClassifyAapcs64HfaType(const FfiType* type) noexcept;

/**
 * @brief Reconstructs `ffi_get_struct_offsets` (`0x00d0c4..0x00d0f0` -> `0x00cd60`):
 *        Computes member offsets, total size, and alignment of an `FFI_TYPE_STRUCT`.
 *        Tái tạo hàm `ffi_get_struct_offsets` (`0x00d0c4..0x00d0f0`).
 */
FfiStatus FfiGetStructOffsets(FfiAbi abi, FfiType* struct_type, size_t* offsets) noexcept;

/**
 * @brief Reconstructs `ffi_prep_cif` (`0x00cfc0..0x00cfd8`) and `ffi_prep_cif_var` (`0x00cfdc..0x00d0b8`).
 *        Tái tạo hàm `ffi_prep_cif` (`0x00cfc0`) và `ffi_prep_cif_var` (`0x00cfdc`).
 */
FfiStatus FfiPrepCif(FfiCif* cif,
                     FfiAbi abi,
                     uint32_t nargs,
                     FfiType* rtype,
                     FfiType** atypes) noexcept;

FfiStatus FfiPrepCifVar(FfiCif* cif,
                        FfiAbi abi,
                        uint32_t nfixedargs,
                        uint32_t ntotalargs,
                        FfiType* rtype,
                        FfiType** atypes) noexcept;

/**
 * @brief Reconstructs `ffi_call_int` (`0x0108b4..0x010df8`), `ffi_call` (`0x010e00`), and `ffi_call_go` (`0x010e08`):
 *        Marshals arguments into an `Aarch64CallContext` (`v0..v7`, `x0..x7`) + stack overflow area
 *        and invokes `fn`.
 *        Tái tạo hàm `ffi_call_int` (`0x0108b4`), `ffi_call` (`0x010e00`) và `ffi_call_go` (`0x010e08`).
 */
void FfiPopulateCallContext(const FfiCif* cif,
                            void** avalue,
                            Aarch64CallContext* out_context,
                            uint8_t* out_stack_bytes,
                            size_t stack_capacity,
                            size_t* out_nsrn,
                            size_t* out_ngrn,
                            size_t* out_stack_used) noexcept;

void FfiCall(FfiCif* cif, void (*fn)(), void* rvalue, void** avalue) noexcept;
void FfiCallGo(FfiCif* cif, void (*fn)(), void* rvalue, void** avalue, void* closure) noexcept;

/**
 * @brief Reconstructs `ffi_closure_alloc` (`0x00e2b0..0x00f9c4`) and `ffi_closure_free` (`0x00f9c8..0x00f9f4`).
 *        Tái tạo hàm cấp phát và giải phóng `ffi_closure_alloc` (`0x00e2b0`) / `ffi_closure_free` (`0x00f9c8`).
 */
void* FfiClosureAlloc(size_t size, void** code) noexcept;
void  FfiClosureFree(void* writable_ptr) noexcept;

/**
 * @brief Reconstructs `ffi_prep_closure_loc` (`0x010e0c..0x010f0c`), `ffi_prep_closure` (`0x00d0bc`),
 *        and `ffi_prep_go_closure` (`0x010f10..0x010f58`).
 *        Tái tạo hàm `ffi_prep_closure_loc` (`0x010e0c`) và `ffi_prep_go_closure` (`0x010f10`).
 */
FfiStatus FfiPrepClosureLoc(FfiClosure* closure,
                            FfiCif* cif,
                            void (*fun)(FfiCif*, void*, void**, void*),
                            void* user_data,
                            void* codeloc) noexcept;

FfiStatus FfiPrepGoClosure(FfiGoClosure* closure,
                           FfiCif* cif,
                           void (*fun)(FfiCif*, void*, void**, void*)) noexcept;

/**
 * @brief Reconstructs `ffi_tramp_arch` (`0x0112ac..0x0112c4`):
 *        Writes `*tramp_size = 0x20` (`32`) and `*map_size = 0x4000` (`16384`).
 *        Tái tạo hàm `ffi_tramp_arch` (`0x0112ac..0x0112c4`).
 */
void* FfiTrampArch(size_t* tramp_size, size_t* map_size) noexcept;

/**
 * @brief Reconstructs `__aarch64_sync_cache_range` (`0x020004..0x02007c`) and `__clear_cache` (`0x020000`):
 *        Decodes `ctr_el0` (`DminLine = 4 << ((ctr_el0 >> 16) & 0xF)`, `IminLine = 4 << (ctr_el0 & 0xF)`)
 *        and computes the aligned D-cache and I-cache line sweep counts.
 *        Tái tạo hàm đồng bộ bộ đệm lệnh/dữ liệu `__aarch64_sync_cache_range` (`0x020004..0x02007c`).
 */
void DecodeCtrEl0CacheLines(uint32_t ctr_el0,
                            uint32_t* out_icache_line_bytes,
                            uint32_t* out_dcache_line_bytes) noexcept;

void Aarch64SyncCacheRange(const void* begin, const void* end) noexcept;

}  // namespace jnidispatch
}  // namespace opencut
}  // namespace nextai

#endif  // NEXTAI_OPENCUT_JNIDISPATCH_LIBFFI_AARCH64_ENGINE_H_
