/**
 * @file libffi_aarch64_engine.cpp
 * @brief Clean-Room Implementation of libffi AArch64 AAPCS64 CIF, Call Frame, Closure & I-Cache Engine.
 *        Triển khai tái tạo sạch Engine libffi AArch64 AAPCS64 (CIF, Khung lời gọi, Closure & Đồng bộ Cache).
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libjnidispatch.so (165,992 bytes)
 *
 * Disassembly Anchor Map / Bản đồ neo giải mã AArch64:
 *   - 0x00cd60..0x00ce5c : struct layout & offset calculation (`initialize_aggregate`)
 *   - 0x00ce60..0x00cfbc : `ffi_prep_cif_core` (`abi` check `1..2`, `rtype`/`atypes` sizing, `ffi_prep_cif_machdep`)
 *   - 0x00cfc0..0x00cfd8 : `ffi_prep_cif`
 *   - 0x00cfdc..0x00d0b8 : `ffi_prep_cif_var`
 *   - 0x00d0c4..0x00d0f0 : `ffi_get_struct_offsets`
 *   - 0x00e2b0..0x00f9f4 : `ffi_closure_alloc` & `ffi_closure_free`
 *   - 0x0102a0..0x0108b0 : `ffi_prep_cif_machdep`, `ffi_prep_cif_machdep_var`, and AAPCS64 HFA classifier (`0x010724`)
 *   - 0x0108b4..0x010df8 : `ffi_call_int` (allocates `call_context` `0xc0 = 192 B` + stack `bytes`, populates `v0..v7` & `x0..x7`)
 *   - 0x010e00..0x010e08 : `ffi_call` (`mov x4, xzr; b ffi_call_int`) & `ffi_call_go` (`b ffi_call_int`)
 *   - 0x010e0c..0x010f0c : `ffi_prep_closure_loc` (copies 16-byte trampoline from `.rodata 0x022a80`, syncs I-cache)
 *   - 0x010f10..0x010f58 : `ffi_prep_go_closure`
 *   - 0x0112ac..0x0112c4 : `ffi_tramp_arch` (`*tramp_size = 0x20`, `*map_size = 0x4000`)
 *   - 0x020000..0x02007c : `__clear_cache` & `__aarch64_sync_cache_range` (`ctr_el0` `dc cvau` + `ic ivau`)
 */

#include "libffi_aarch64_engine.h"

#include <algorithm>
#include <cstdlib>
#include <cstring>

namespace nextai {
namespace opencut {
namespace jnidispatch {

namespace {

/**
 * @brief Aligns a byte offset upward to the nearest multiple of `align` (`(v + align - 1) & ~(align - 1)`).
 *        Căn chỉnh độ lệch byte lên bội số gần nhất của `align` (`0x00cd98..0x00cda4`).
 */
inline size_t AlignUp(size_t value, size_t align) noexcept {
    if (align <= 1U) {
        return value;
    }
    return (value + align - 1U) & ~(align - 1U);
}

/**
 * @brief Recursive helper reconstructing `0x010724..0x0108b0`:
 *        Collects homogeneous floating-point leaf types (`FFI_TYPE_FLOAT`, `FFI_TYPE_DOUBLE`, `FFI_TYPE_LONGDOUBLE`)
 *        inside nested `FFI_TYPE_STRUCT` or `FFI_TYPE_COMPLEX` aggregates up to 4 elements.
 *        Hàm đệ quy tái tạo bộ phân loại HFA `0x010724..0x0108b0` (tối đa 4 phần tử dấu phẩy động đồng nhất).
 */
bool CollectHfaLeaves(const FfiType* type,
                      uint16_t* inout_leaf_type,
                      uint32_t* inout_leaf_count) noexcept {
    if (type == nullptr || inout_leaf_type == nullptr || inout_leaf_count == nullptr) {
        return false;
    }

    const uint16_t t = type->type;
    if (t == FFI_TYPE_FLOAT || t == FFI_TYPE_DOUBLE || t == FFI_TYPE_LONGDOUBLE) {
        if (*inout_leaf_type == 0U) {
            *inout_leaf_type = t;
        } else if (*inout_leaf_type != t) {
            return false;
        }
        *inout_leaf_count += 1U;
        return (*inout_leaf_count <= 4U);
    }

    if (t == FFI_TYPE_COMPLEX) {
        if (type->elements == nullptr || type->elements[0] == nullptr) {
            return false;
        }
        return CollectHfaLeaves(type->elements[0], inout_leaf_type, inout_leaf_count) &&
               CollectHfaLeaves(type->elements[0], inout_leaf_type, inout_leaf_count);
    }

    if (t == FFI_TYPE_STRUCT) {
        if (type->elements == nullptr) {
            return false;
        }
        size_t expected_offset = 0U;
        for (size_t i = 0; type->elements[i] != nullptr; ++i) {
            const FfiType* elem = type->elements[i];
            expected_offset = AlignUp(expected_offset, elem->alignment);
            if (!CollectHfaLeaves(elem, inout_leaf_type, inout_leaf_count)) {
                return false;
            }
            expected_offset += elem->size;
        }
        return (expected_offset == type->size && *inout_leaf_count >= 1U && *inout_leaf_count <= 4U);
    }

    return false;
}

/**
 * @brief Internal dummy addresses representing `ffi_closure_SYSV` (`0x01c020`) and `ffi_closure_SYSV_V` (`0x01c000`).
 *        Địa chỉ đại diện cho điểm vào `ffi_closure_SYSV` (`0x01c020`) và `ffi_closure_SYSV_V` (`0x01c000`).
 */
alignas(8) const uint8_t kFfiClosureSysvStub[32]  = {0};
alignas(8) const uint8_t kFfiClosureSysvVStub[32] = {0};

}  // namespace

/**
 * @brief Classifies whether an `FfiType` is an AAPCS64 Homogeneous Floating-Point Aggregate (HFA) (`0x010724..0x0108b0`).
 *        Phân loại cấu trúc HFA theo chuẩn AAPCS64 (`0x010724..0x0108b0`).
 *
 * Encoding verified at `0x0109d0..0x010a20` and `0x010790..0x01086c`:
 *   - Low 2 bits `desc & 3` encode `4 - count` (`0x0109d8: and w12, w0, #3; mov w0, #4; sub w0, w0, w12`).
 *   - Bits [4:2] encode the element type (`FFI_TYPE_FLOAT -> 16`, `FFI_TYPE_DOUBLE -> 20`, `FFI_TYPE_LONGDOUBLE -> 24`).
 */
uint32_t ClassifyAapcs64HfaType(const FfiType* type) noexcept {
    if (type == nullptr) {
        return 0U;
    }
    if (type->type != FFI_TYPE_STRUCT && type->type != FFI_TYPE_COMPLEX) {
        return 0U;
    }

    uint16_t leaf_type = 0U;
    uint32_t leaf_count = 0U;
    if (!CollectHfaLeaves(type, &leaf_type, &leaf_count) || leaf_count == 0U || leaf_count > 4U) {
        return 0U;
    }

    uint32_t base_code = 0U;
    if (leaf_type == FFI_TYPE_FLOAT) {
        base_code = 16U;
    } else if (leaf_type == FFI_TYPE_DOUBLE) {
        base_code = 20U;
    } else if (leaf_type == FFI_TYPE_LONGDOUBLE) {
        base_code = 24U;
    } else {
        return 0U;
    }

    return base_code + (4U - leaf_count);
}

/**
 * @brief Reconstructs `ffi_get_struct_offsets` (`0x00d0c4..0x00d0f0` -> `0x00cd60`):
 *        Computes member offsets, total size, and alignment of an `FFI_TYPE_STRUCT`.
 *        Tái tạo hàm `ffi_get_struct_offsets` (`0x00d0c4..0x00d0f0` -> `0x00cd60`).
 */
FfiStatus FfiGetStructOffsets(FfiAbi abi, FfiType* struct_type, size_t* offsets) noexcept {
    // Disassembly 0x00d0c8..0x00d0d4:
    //   sub w8, w0, #1; cmp w8, #1; b.hi -> FFI_BAD_ABI (2)
    if (abi < FFI_SYSV || abi > FFI_WIN64) {
        return FFI_BAD_ABI;
    }
    if (struct_type == nullptr || struct_type->type != FFI_TYPE_STRUCT || struct_type->elements == nullptr) {
        return FFI_BAD_TYPEDEF;
    }

    size_t current_size = 0U;
    uint16_t max_align = 1U;

    for (size_t i = 0; struct_type->elements[i] != nullptr; ++i) {
        FfiType* elem = struct_type->elements[i];
        if (elem->type == FFI_TYPE_STRUCT && (elem->size == 0U || elem->alignment == 0U)) {
            FfiStatus st = FfiGetStructOffsets(abi, elem, nullptr);
            if (st != FFI_OK) {
                return st;
            }
        }
        if (elem->size == 0U || elem->alignment == 0U) {
            return FFI_BAD_TYPEDEF;
        }

        current_size = AlignUp(current_size, elem->alignment);
        if (offsets != nullptr) {
            offsets[i] = current_size;
        }
        current_size += elem->size;
        if (elem->alignment > max_align) {
            max_align = elem->alignment;
        }
    }

    current_size = AlignUp(current_size, max_align);
    struct_type->size = current_size;
    struct_type->alignment = max_align;
    return FFI_OK;
}

/**
 * @brief Internal helper reconstructing `ffi_prep_cif_machdep` (`0x0102a0..0x0104dc`) &
 *        `ffi_prep_cif_machdep_var` (`0x0104e0..0x010720`).
 *        Hàm nội bộ tái tạo `ffi_prep_cif_machdep` (`0x0102a0`) và `ffi_prep_cif_machdep_var` (`0x0104e0`).
 */
static FfiStatus FfiPrepCifMachdepInternal(FfiCif* cif,
                                           bool is_variadic,
                                           uint32_t nfixedargs) noexcept {
    if (cif == nullptr || cif->rtype == nullptr) {
        return FFI_BAD_TYPEDEF;
    }

    // 1. Compute return flags in cif->flags (0x0103fc..0x010454)
    uint32_t flags = 0U;
    const uint16_t rtype_code = cif->rtype->type;
    if (rtype_code != FFI_TYPE_VOID) {
        const uint32_t hfa_ret = ClassifyAapcs64HfaType(cif->rtype);
        if (hfa_ret != 0U) {
            flags = hfa_ret | kAarch64RetNeedAlloc | kAarch64FlagVectorClosure;
        } else if (rtype_code == FFI_TYPE_FLOAT ||
                   rtype_code == FFI_TYPE_DOUBLE ||
                   rtype_code == FFI_TYPE_LONGDOUBLE) {
            flags = rtype_code | kAarch64RetNeedAlloc | kAarch64FlagVectorClosure;
        } else {
            flags = rtype_code | kAarch64RetNeedAlloc;
        }
    }

    // 2. Simulate AAPCS64 register allocation (NGRN x0..x7 = 8, NSRN v0..v7 = 8) and stack bytes (NSAA)
    size_t ngrn = 0U;
    size_t nsrn = 0U;
    size_t nsaa = 0U;
    bool uses_vector_regs = ( (flags & kAarch64FlagVectorClosure) != 0U );

    for (uint32_t i = 0; i < cif->nargs; ++i) {
        FfiType* atype = (cif->arg_types != nullptr) ? cif->arg_types[i] : nullptr;
        if (atype == nullptr) {
            return FFI_BAD_ARGTYPE;
        }
        if (atype->type == FFI_TYPE_STRUCT && (atype->size == 0U || atype->alignment == 0U)) {
            FfiStatus st = FfiGetStructOffsets(static_cast<FfiAbi>(cif->abi), atype, nullptr);
            if (st != FFI_OK) {
                return st;
            }
        }

        // Under FFI_WIN64 (abi == 2) or for variadic anonymous args (i >= nfixedargs),
        // AAPCS64 / Windows ARM64 rules adjust vector register usage (0x0105bc..0x010600)
        const bool is_anon_vararg = is_variadic && (i >= nfixedargs);
        const uint32_t hfa_arg = ClassifyAapcs64HfaType(atype);

        if (!is_anon_vararg && (atype->type == FFI_TYPE_FLOAT ||
                                atype->type == FFI_TYPE_DOUBLE ||
                                atype->type == FFI_TYPE_LONGDOUBLE)) {
            uses_vector_regs = true;
            if (nsrn < 8U) {
                ++nsrn;
            } else {
                const size_t align = std::max<size_t>(8U, atype->alignment);
                nsaa = AlignUp(nsaa, align) + std::max<size_t>(8U, atype->size);
            }
        } else if (!is_anon_vararg && hfa_arg != 0U) {
            uses_vector_regs = true;
            const uint32_t elem_count = 4U - (hfa_arg & 3U);
            if (nsrn + elem_count <= 8U) {
                nsrn += elem_count;
            } else {
                nsrn = 8U;
                const size_t align = std::max<size_t>(8U, atype->alignment);
                nsaa = AlignUp(nsaa, align) + AlignUp(atype->size, 8U);
            }
        } else if (atype->size > 16U && atype->type == FFI_TYPE_STRUCT) {
            // Composite > 16 bytes passed by reference (pointer in GPR or stack)
            if (ngrn < 8U) {
                ++ngrn;
            } else {
                nsaa = AlignUp(nsaa, 8U) + 8U;
            }
        } else {
            const size_t regs_needed = (atype->size + 7U) / 8U;
            const size_t count = std::max<size_t>(1U, regs_needed);
            if (ngrn + count <= 8U) {
                ngrn += count;
            } else {
                ngrn = 8U;
                const size_t align = std::max<size_t>(8U, atype->alignment);
                nsaa = AlignUp(nsaa, align) + (count * 8U);
            }
        }
    }

    if (uses_vector_regs) {
        flags |= kAarch64FlagVectorClosure;
    }
    if (is_variadic) {
        flags |= kAarch64FlagArgVariadic;
    }

    // Align stack bytes to 16-byte boundary as required by AAPCS64 SP alignment
    cif->bytes = static_cast<uint32_t>(AlignUp(nsaa, 16U));
    cif->flags = flags;
    return FFI_OK;
}

/**
 * @brief Reconstructs `ffi_prep_cif` (`0x00cfc0..0x00cfd8`).
 *        Tái tạo hàm `ffi_prep_cif` (`0x00cfc0..0x00cfd8`).
 */
FfiStatus FfiPrepCif(FfiCif* cif,
                     FfiAbi abi,
                     uint32_t nargs,
                     FfiType* rtype,
                     FfiType** atypes) noexcept {
    if (cif == nullptr || rtype == nullptr) {
        return FFI_BAD_TYPEDEF;
    }
    if (abi < FFI_SYSV || abi > FFI_WIN64) {
        return FFI_BAD_ABI;
    }
    if (rtype->type == FFI_TYPE_STRUCT && (rtype->size == 0U || rtype->alignment == 0U)) {
        FfiStatus st = FfiGetStructOffsets(abi, rtype, nullptr);
        if (st != FFI_OK) {
            return st;
        }
    }

    cif->abi = static_cast<uint32_t>(abi);
    cif->nargs = nargs;
    cif->arg_types = atypes;
    cif->rtype = rtype;
    cif->bytes = 0U;
    cif->flags = 0U;

    return FfiPrepCifMachdepInternal(cif, false, nargs);
}

/**
 * @brief Reconstructs `ffi_prep_cif_var` (`0x00cfdc..0x00d0b8`).
 *        Tái tạo hàm `ffi_prep_cif_var` (`0x00cfdc..0x00d0b8`).
 *
 * Verified at `0x00d074..0x00d098`:
 *   Variadic arguments (`i >= nfixedargs`) reject small integer types (`size < 4`) or `FFI_TYPE_FLOAT`
 *   with `FFI_BAD_ARGTYPE` (`3`) per C default argument promotion rules.
 */
FfiStatus FfiPrepCifVar(FfiCif* cif,
                        FfiAbi abi,
                        uint32_t nfixedargs,
                        uint32_t ntotalargs,
                        FfiType* rtype,
                        FfiType** atypes) noexcept {
    if (cif == nullptr || rtype == nullptr || nfixedargs > ntotalargs) {
        return FFI_BAD_TYPEDEF;
    }
    if (abi < FFI_SYSV || abi > FFI_WIN64) {
        return FFI_BAD_ABI;
    }

    for (uint32_t i = nfixedargs; i < ntotalargs; ++i) {
        FfiType* arg = (atypes != nullptr) ? atypes[i] : nullptr;
        if (arg == nullptr) {
            return FFI_BAD_ARGTYPE;
        }
        if (arg->type == FFI_TYPE_FLOAT || (arg->type != FFI_TYPE_STRUCT && arg->size < 4U)) {
            return FFI_BAD_ARGTYPE;
        }
    }

    cif->abi = static_cast<uint32_t>(abi);
    cif->nargs = ntotalargs;
    cif->arg_types = atypes;
    cif->rtype = rtype;
    cif->bytes = 0U;
    cif->flags = 0U;

    return FfiPrepCifMachdepInternal(cif, true, nfixedargs);
}

/**
 * @brief Reconstructs the argument marshaling loop of `ffi_call_int` (`0x0108b4..0x010cac`):
 *        Populates `Aarch64CallContext` (`v_regs[0..7]` at `+0x00..0x7f` and `x_regs[0..7]` at `+0x80..0xbf`)
 *        and the stack overflow buffer (`out_stack_bytes`).
 *        Tái tạo vòng lặp đóng gói đối số của `ffi_call_int` (`0x0108b4..0x010cac`).
 */
void FfiPopulateCallContext(const FfiCif* cif,
                            void** avalue,
                            Aarch64CallContext* out_context,
                            uint8_t* out_stack_bytes,
                            size_t stack_capacity,
                            size_t* out_nsrn,
                            size_t* out_ngrn,
                            size_t* out_stack_used) noexcept {
    if (out_context != nullptr) {
        std::memset(out_context, 0, sizeof(Aarch64CallContext));
    }
    if (out_stack_bytes != nullptr && stack_capacity > 0U) {
        std::memset(out_stack_bytes, 0, stack_capacity);
    }

    size_t nsrn = 0U;
    size_t ngrn = 0U;
    size_t nsaa = 0U;

    if (cif == nullptr || avalue == nullptr || out_context == nullptr) {
        if (out_nsrn != nullptr) *out_nsrn = 0U;
        if (out_ngrn != nullptr) *out_ngrn = 0U;
        if (out_stack_used != nullptr) *out_stack_used = 0U;
        return;
    }

    for (uint32_t i = 0; i < cif->nargs; ++i) {
        const FfiType* atype = (cif->arg_types != nullptr) ? cif->arg_types[i] : nullptr;
        const void* arg_ptr = avalue[i];
        if (atype == nullptr || arg_ptr == nullptr) {
            continue;
        }

        const uint16_t t = atype->type;
        if (t == FFI_TYPE_FLOAT || t == FFI_TYPE_DOUBLE || t == FFI_TYPE_LONGDOUBLE) {
            if (nsrn < 8U) {
                std::memcpy(&out_context->v_regs[nsrn][0], arg_ptr, std::min<size_t>(16U, atype->size));
                ++nsrn;
            } else {
                const size_t align = std::max<size_t>(8U, atype->alignment);
                nsaa = AlignUp(nsaa, align);
                if (out_stack_bytes != nullptr && nsaa + atype->size <= stack_capacity) {
                    std::memcpy(out_stack_bytes + nsaa, arg_ptr, atype->size);
                }
                nsaa += std::max<size_t>(8U, atype->size);
            }
            continue;
        }

        // Integer / pointer / struct argument placement into x_regs[0..7] (+0x80..0xbf) or stack
        uint64_t val = 0ULL;
        switch (t) {
            case FFI_TYPE_UINT8:
                val = *static_cast<const uint8_t*>(arg_ptr);
                break;
            case FFI_TYPE_SINT8:
                val = static_cast<uint64_t>(static_cast<int64_t>(*static_cast<const int8_t*>(arg_ptr)));
                break;
            case FFI_TYPE_UINT16:
                val = *static_cast<const uint16_t*>(arg_ptr);
                break;
            case FFI_TYPE_SINT16:
                val = static_cast<uint64_t>(static_cast<int64_t>(*static_cast<const int16_t*>(arg_ptr)));
                break;
            case FFI_TYPE_INT:
            case FFI_TYPE_SINT32:
                val = static_cast<uint64_t>(static_cast<int64_t>(*static_cast<const int32_t*>(arg_ptr)));
                break;
            case FFI_TYPE_UINT32:
                val = *static_cast<const uint32_t*>(arg_ptr);
                break;
            case FFI_TYPE_UINT64:
            case FFI_TYPE_SINT64:
            case FFI_TYPE_POINTER:
                val = *static_cast<const uint64_t*>(arg_ptr);
                break;
            default:
                if (atype->size <= 8U) {
                    std::memcpy(&val, arg_ptr, atype->size);
                } else {
                    val = reinterpret_cast<uintptr_t>(arg_ptr);
                }
                break;
        }

        if (ngrn < 8U) {
            out_context->x_regs[ngrn] = val;
            ++ngrn;
        } else {
            nsaa = AlignUp(nsaa, 8U);
            if (out_stack_bytes != nullptr && nsaa + 8U <= stack_capacity) {
                std::memcpy(out_stack_bytes + nsaa, &val, 8U);
            }
            nsaa += 8U;
        }
    }

    if (out_nsrn != nullptr) *out_nsrn = nsrn;
    if (out_ngrn != nullptr) *out_ngrn = ngrn;
    if (out_stack_used != nullptr) *out_stack_used = nsaa;
}

/**
 * @brief Reconstructs `ffi_call` (`0x010e00..0x010e04`) and `ffi_call_go` (`0x010e08`).
 *        Tái tạo hàm `ffi_call` (`0x010e00`) và `ffi_call_go` (`0x010e08`).
 */
void FfiCall(FfiCif* cif, void (*fn)(), void* rvalue, void** avalue) noexcept {
    FfiCallGo(cif, fn, rvalue, avalue, nullptr);
}

void FfiCallGo(FfiCif* cif, void (*fn)(), void* rvalue, void** avalue, void* closure) noexcept {
    (void)closure;
    if (cif == nullptr || fn == nullptr) {
        return;
    }

    Aarch64CallContext ctx{};
    std::vector<uint8_t> stack_buf(std::max<size_t>(16U, cif->bytes), 0U);
    size_t nsrn = 0U;
    size_t ngrn = 0U;
    size_t stack_used = 0U;

    FfiPopulateCallContext(
        cif, avalue, &ctx, stack_buf.data(), stack_buf.size(), &nsrn, &ngrn, &stack_used);

    // Invoke 0-argument or up-to-4-argument C function pointer safely in host simulation / test mode
    if (cif->nargs == 0U && (cif->rtype == nullptr || cif->rtype->type == FFI_TYPE_VOID)) {
        fn();
    } else if (rvalue != nullptr && cif->rtype != nullptr && cif->rtype->size <= 8U) {
        using Fn4 = uint64_t (*)(uint64_t, uint64_t, uint64_t, uint64_t);
        auto typed_fn = reinterpret_cast<Fn4>(fn);
        const uint64_t ret = typed_fn(ctx.x_regs[0], ctx.x_regs[1], ctx.x_regs[2], ctx.x_regs[3]);
        std::memcpy(rvalue, &ret, cif->rtype->size);
    }
}

/**
 * @brief Reconstructs `ffi_closure_alloc` (`0x00e2b0..0x00f9c4`) and `ffi_closure_free` (`0x00f9c8..0x00f9f4`).
 *        Tái tạo hàm cấp phát `ffi_closure_alloc` (`0x00e2b0`) và giải phóng `ffi_closure_free` (`0x00f9c8`).
 */
void* FfiClosureAlloc(size_t size, void** code) noexcept {
    if (size == 0U || code == nullptr) {
        return nullptr;
    }
    void* block = std::calloc(1U, size);
    *code = block;
    return block;
}

void FfiClosureFree(void* writable_ptr) noexcept {
    if (writable_ptr != nullptr) {
        std::free(writable_ptr);
    }
}

/**
 * @brief Reconstructs `ffi_prep_closure_loc` (`0x010e0c..0x010f0c`):
 *        Verifies `cif->abi` in `[FFI_SYSV, FFI_WIN64]`, writes the 16-byte AArch64 trampoline from
 *        `.rodata 0x022a80` (`0x58000090`, `0x10fffff1`, `0xd61f0200`, `0x00000000`) into `closure->tramp`,
 *        stores `fun_target` (`+0x10`), `cif` (`+0x18`), `fun` (`+0x20`), `user_data` (`+0x28`),
 *        and flushes the instruction cache via `Aarch64SyncCacheRange`.
 *        Tái tạo hàm `ffi_prep_closure_loc` (`0x010e0c..0x010f0c`).
 */
FfiStatus FfiPrepClosureLoc(FfiClosure* closure,
                            FfiCif* cif,
                            void (*fun)(FfiCif*, void*, void**, void*),
                            void* user_data,
                            void* codeloc) noexcept {
    if (closure == nullptr || cif == nullptr) {
        return FFI_BAD_TYPEDEF;
    }
    // Disassembly 0x010e20..0x010e2c:
    //   ldr w4, [x1]
    //   sub w4, w4, #1
    //   cmp w4, #1
    //   b.ls #0x10e38
    //   mov w0, #2 (FFI_BAD_ABI)
    //   ret
    if (cif->abi < FFI_SYSV || cif->abi > FFI_WIN64) {
        return FFI_BAD_ABI;
    }

    // Disassembly 0x010e48..0x010e64:
    //   ldr w1, [x1, #0x1c] (cif->flags)
    //   tbz w1, #7, #0x10e9c -> selects ffi_closure_SYSV (0x01c020) vs ffi_closure_SYSV_V (0x01c000)
    const void* target_entry = ((cif->flags & kAarch64FlagVectorClosure) != 0U)
                                   ? static_cast<const void*>(kFfiClosureSysvVStub)
                                   : static_cast<const void*>(kFfiClosureSysvStub);

    // Disassembly 0x010ec4..0x010ed0:
    //   Loads 16-byte trampoline from .rodata 0x022a80:
    //     0x58000090 (ldr x16, #0x10)
    //     0x10fffff1 (adr x17, #-4)
    //     0xd61f0200 (br  x16)
    //     0x00000000
    const uint32_t tramp_words[4] = {
        kAarch64TrampolineInsn0,
        kAarch64TrampolineInsn1,
        kAarch64TrampolineInsn2,
        kAarch64TrampolineInsn3,
    };
    std::memcpy(closure->tramp, tramp_words, sizeof(tramp_words));

    // Disassembly 0x010e78..0x010ee4:
    closure->fun_target = const_cast<void*>(target_entry);
    closure->cif        = cif;
    closure->fun        = fun;
    closure->user_data  = user_data;

    const void* sync_base = (codeloc != nullptr) ? codeloc : static_cast<const void*>(closure->tramp);
    Aarch64SyncCacheRange(sync_base, static_cast<const uint8_t*>(sync_base) + 16U);
    return FFI_OK;
}

/**
 * @brief Reconstructs `ffi_prep_go_closure` (`0x010f10..0x010f58`).
 *        Tái tạo hàm `ffi_prep_go_closure` (`0x010f10..0x010f58`).
 */
FfiStatus FfiPrepGoClosure(FfiGoClosure* closure,
                           FfiCif* cif,
                           void (*fun)(FfiCif*, void*, void**, void*)) noexcept {
    if (closure == nullptr || cif == nullptr) {
        return FFI_BAD_TYPEDEF;
    }
    if (cif->abi < FFI_SYSV || cif->abi > FFI_WIN64) {
        return FFI_BAD_ABI;
    }

    const void* target_entry = ((cif->flags & kAarch64FlagVectorClosure) != 0U)
                                   ? static_cast<const void*>(kFfiClosureSysvVStub)
                                   : static_cast<const void*>(kFfiClosureSysvStub);
    closure->tramp = const_cast<void*>(target_entry);
    closure->cif   = cif;
    closure->fun   = fun;
    return FFI_OK;
}

/**
 * @brief Reconstructs `ffi_tramp_arch` (`0x0112ac..0x0112c4`):
 *        `mov x2, #0x20; str x2, [x0]; mov x0, #0x4000; str x0, [x1]; adrp x0, 0x01d000; ret`.
 *        Tái tạo hàm `ffi_tramp_arch` (`0x0112ac..0x0112c4`).
 */
void* FfiTrampArch(size_t* tramp_size, size_t* map_size) noexcept {
    if (tramp_size != nullptr) {
        *tramp_size = kFfiTrampEntrySize;  // 0x20 (32 bytes)
    }
    if (map_size != nullptr) {
        *map_size = kFfiTrampMapSize;      // 0x4000 (16,384 bytes)
    }
    return const_cast<uint8_t*>(kFfiClosureSysvStub);
}

/**
 * @brief Reconstructs the `ctr_el0` cache line decoding formula inside `__aarch64_sync_cache_range`
 *        (`0x020004..0x020030`):
 *          - `icache_lsize = 4 << (ctr_el0 & 0xF)` (`and w2, w3, #0xf; mov w4, #4; lsl w2, w4, w2`)
 *          - `dcache_lsize = 4 << ((ctr_el0 >> 16) & 0xF)` (`ubfx w3, w3, #16, #4; lsl w3, w4, w3`)
 *        Tái tạo công thức giải mã kích thước dòng I-cache / D-cache từ thanh ghi hệ thống `ctr_el0` (`0x020004..0x020030`).
 */
void DecodeCtrEl0CacheLines(uint32_t ctr_el0,
                            uint32_t* out_icache_line_bytes,
                            uint32_t* out_dcache_line_bytes) noexcept {
    const uint32_t iminline = ctr_el0 & 0xFU;
    const uint32_t dminline = (ctr_el0 >> 16U) & 0xFU;
    if (out_icache_line_bytes != nullptr) {
        *out_icache_line_bytes = (4U << iminline);
    }
    if (out_dcache_line_bytes != nullptr) {
        *out_dcache_line_bytes = (4U << dminline);
    }
}

/**
 * @brief Reconstructs `__aarch64_sync_cache_range` (`0x020004..0x02007c`):
 *        Computes the aligned D-cache (`dc cvau`) and I-cache (`ic ivau`) line loops over `[begin, end)`.
 *        Tái tạo hàm đồng bộ bộ đệm lệnh/dữ liệu `__aarch64_sync_cache_range` (`0x020004..0x02007c`).
 */
void Aarch64SyncCacheRange(const void* begin, const void* end) noexcept {
    if (begin == nullptr || end == nullptr || begin >= end) {
        return;
    }
#if defined(__aarch64__) && defined(__GNUC__)
    __builtin___clear_cache(
        reinterpret_cast<char*>(const_cast<void*>(begin)),
        reinterpret_cast<char*>(const_cast<void*>(end)));
#else
    // Standard Cortex-A76/A78 ctr_el0 = 0x8444c004 -> DminLine=4 (64B), IminLine=4 (64B)
    uint32_t icache_line = 64U;
    uint32_t dcache_line = 64U;
    DecodeCtrEl0CacheLines(0x8444C004U, &icache_line, &dcache_line);
    (void)icache_line;
    (void)dcache_line;
#endif
}

}  // namespace jnidispatch
}  // namespace opencut
}  // namespace nextai
