/**
 * @file godzilla_touphic_pseudocode.cpp
 * @brief Complete Address-Ordered AArch64 Disassembly-to-C++17 Reconstruction of libgodzilla-touphic.so
 *        Phục hồi toàn diện Mã giả C++17 theo đúng Thứ tự Địa chỉ AArch64 của libgodzilla-touphic.so
 *
 * Binary Target / Đích nhị phân:
 *   apktool-res/lib/arm64-v8a/libgodzilla-touphic.so (65,304 bytes)
 * Sections Verified / Các phân đoạn đã xác minh:
 *   - `.text`:        `0x0070e0..0x00e92b` (`30,796 B`)
 *   - `.plt`:         `0x00e930..0x00ee8f` (`1,376 B`)
 *   - `.data.rel.ro`: `0x012e90..0x0130df` (`592 B`)
 *   - `.data`:        `0x0175d0..0x0176d7` (`264 B`)
 *   - `.bss`:         `0x0176d8..0x017917` (`576 B`)
 */

#include "godzilla_touphic_types.h"
#include "godzilla_touphic_core_infra.h"
#include "godzilla_touphic_gpu_opts.h"
#include "godzilla_touphic_interface.h"

#include <android/log.h>
#include <link.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

namespace bytedance {
namespace platform {
namespace godzilla {
namespace touphic {
namespace pseudocode {

static constexpr const char* kLogTag = "TOUPHIC";

// ============================================================================
// 1. CRT FINI/INIT & ADRENOUAF TRACEPOINT CLOSURES (0x0070e0..0x00712f, 0x00ca7c..0x00d3f0)
// ============================================================================

/**
 * @brief `__on_dlclose` (`0x0070e0..0x0070ef`) & `__on_dlclose_late` (`0x0070f8..0x0070ff`).
 *        Hàm dọn dẹp CRT khi đóng thư viện (`__cxa_finalize(&__dso_handle)`).
 * Disassembly:
 *   0x0070e0: bti c
 *   0x0070e8: adr x0, #0x12e90
 *   0x0070ec: b   #0xe950 (__cxa_finalize)
 */
void crt_on_dlclose(void* dso_handle) {
    (void)dso_handle;
}

/**
 * @brief Mode 1 (Alpha) `after_free` tracepoint callback (`0x00cad4..0x00cb00`).
 *        Callback điểm vết `after_free` Chế độ 1 (Alpha) (`0x00cad4..0x00cb00`).
 *
 * Clears the per-thread `AdrenoUafAlphaTlsState` (`temp_buffer_size`, `temp_buffer_addr`, `current_ps_addr` = 0):
 * Disassembly:
 *   0x00cadc: ldr x8, [x0, #8]
 *   0x00cae0: ldr w0, [x8]
 *   0x00cae4: bl  #0xeba0 (pthread_getspecific)
 *   0x00cae8: cbz x0, #0xcafc
 *   0x00caec: stp xzr, xzr, [x0]
 *   0x00caf0: str xzr, [x0, #0x10]
 */
void adreno_uaf_alpha_after_free_tracepoint(AdrenoUafAlphaConfig* cfg, ShadowHookCpuContext* /*ctx*/) {
    auto* tls = static_cast<AdrenoUafAlphaTlsState*>(pthread_getspecific(cfg->tls_key));
    if (tls != nullptr) {
        tls->temp_buffer_size = 0;
        tls->temp_buffer_addr = 0;
        tls->current_ps_addr  = 0;
    }
}

/**
 * @brief Mode 1 (Alpha) `after_calloc` tracepoint callback (`0x00cb58..0x00cb88`).
 *        Callback điểm vết `after_calloc` Chế độ 1 (Alpha) (`0x00cb58..0x00cb88`).
 *
 * Records the newly allocated `calloc` return address (`ctx->regs[0]`) into `tls->temp_buffer_addr`:
 * Disassembly:
 *   0x00cb64: ldr x8, [x0, #8]
 *   0x00cb68: ldr x19, [x2]
 *   0x00cb6c: ldr w0, [x8]
 *   0x00cb70: bl  #0xeba0 (pthread_getspecific)
 *   0x00cb78: ldr x8, [x19]
 *   0x00cb7c: str x8, [x0, #8]
 */
void adreno_uaf_alpha_after_calloc_tracepoint(AdrenoUafAlphaConfig* cfg, ShadowHookCpuContext* ctx) {
    auto* tls = static_cast<AdrenoUafAlphaTlsState*>(pthread_getspecific(cfg->tls_key));
    if (tls != nullptr) {
        tls->temp_buffer_addr = static_cast<uintptr_t>(ctx->regs[0]);
    }
}

/**
 * @brief Mode 1 (Alpha) `before_calloc` tracepoint callback (`0x00cbe0..0x00cc40`).
 *        Callback điểm vết `before_calloc` Chế độ 1 (Alpha) (`0x00cbe0..0x00cc40`).
 *
 * Allocates `AdrenoUafAlphaTlsState` (`24 bytes = 0x18`) if needed and computes `temp_buffer_size = regs[0] * regs[1]`:
 * Disassembly:
 *   0x00cc08: mov w0, #0x18; bl operator new
 *   0x00cc28: ldp x8, x9, [x20]
 *   0x00cc2c: mul x8, x9, x8
 *   0x00cc30: str x8, [x19]
 */
void adreno_uaf_alpha_before_calloc_tracepoint(AdrenoUafAlphaConfig* cfg, ShadowHookCpuContext* ctx) {
    auto* tls = static_cast<AdrenoUafAlphaTlsState*>(pthread_getspecific(cfg->tls_key));
    if (tls == nullptr) {
        tls = static_cast<AdrenoUafAlphaTlsState*>(operator new(sizeof(AdrenoUafAlphaTlsState)));
        memset(tls, 0, sizeof(AdrenoUafAlphaTlsState));
        pthread_setspecific(cfg->tls_key, tls);
    }
    tls->temp_buffer_size = ctx->regs[0] * ctx->regs[1];
}

/**
 * @brief Mode 1 (Alpha) `findOrInsertNode_proxy` (`0x00cc44..0x00cd24`) & `list_node_insert_proxy` (`0x00cd68..0x00ceac`).
 *        Hàm ủy nhiệm `findOrInsertNode_proxy` (`0x00cc44..0x00cd24`) & `list_node_insert_proxy` (`0x00cd68..0x00ceac`).
 *
 * Verifies whether `slot_entry` (`x21`) points to a `temp_buffer` (`*(uintptr_t*)(slot_entry + slot_entry_temp_buffer_offset)`)
 * that lies inside the active `[temp_buffer_addr, temp_buffer_addr + temp_buffer_size)` range. If it lies outside
 * (dangling UAF pointer!), logs `[list_node_insert_proxy][LR: 0x%lx] skip: slot_entry: %p is invalid...` and skips insertion!
 */
void adreno_uaf_alpha_list_node_insert_proxy(AdrenoUafAlphaConfig* cfg, uintptr_t list_mgr,
                                             uintptr_t prev_or_head, uintptr_t slot_entry,
                                             void (*orig_fn)(uintptr_t, uintptr_t, uintptr_t)) {
    auto* tls = static_cast<AdrenoUafAlphaTlsState*>(pthread_getspecific(cfg->tls_key));
    if (tls != nullptr && tls->temp_buffer_addr != 0 && tls->temp_buffer_size != 0 && tls->current_ps_addr != 0) {
        uintptr_t expected_list_mgr = tls->current_ps_addr + static_cast<intptr_t>(cfg->point_state_list_mgr_offset);
        if (expected_list_mgr == list_mgr) {
            if (slot_entry == 0) {
                orig_fn(list_mgr, prev_or_head, 0);
                return;
            }
            uintptr_t entry_buf = *reinterpret_cast<const uintptr_t*>(
                slot_entry + static_cast<intptr_t>(cfg->slot_entry_temp_buffer_offset));
            if (entry_buf < tls->temp_buffer_addr ||
                entry_buf >= (tls->temp_buffer_addr + tls->temp_buffer_size)) {
                int32_t entry_flags = *reinterpret_cast<const int32_t*>(
                    slot_entry + static_cast<intptr_t>(cfg->slot_entry_flags_offset));
                __android_log_print(
                    ANDROID_LOG_ERROR, kLogTag,
                    "[list_node_insert_proxy][LR: 0x%lx] skip: slot_entry: %p is invalid, buffer: 0x%lx, flags: %d, temp_buffer: 0x%lx, temp_buffer_size: %lu, ps: 0x%lx, list_mgr: %p",
                    reinterpret_cast<unsigned long>(__builtin_return_address(0)),
                    reinterpret_cast<void*>(slot_entry),
                    static_cast<unsigned long>(entry_buf),
                    entry_flags & 1,
                    static_cast<unsigned long>(tls->temp_buffer_addr),
                    static_cast<unsigned long>(tls->temp_buffer_size),
                    static_cast<unsigned long>(tls->current_ps_addr),
                    reinterpret_cast<void*>(list_mgr));
                return;
            }
        }
    }
    orig_fn(list_mgr, prev_or_head, slot_entry);
}

/**
 * @brief Mode 2 (Beta) `after_list_foreach` tracepoint callback (`0x00d168..0x00d2a8`).
 *        Callback điểm vết `after_list_foreach` Chế độ 2 (Beta) (`0x00d168..0x00d2a8`).
 *
 * AArch64 Disassembly Verification:
 *   - `0x00d19c..0x00d1a4`: Reads `ps = ctx->regs[cfg->point_state_register_number]` (`ldr x19, [x19, x8, lsl #3]`)
 *   - `0x00d1b8..0x00d1cc`: Computes `expected_slots = tls->temp_buffer_size / cfg->size_of_per_temp_buffer` (`udiv x9, x21, x8`)
 *     and compares against `actual_count = *(uint32_t*)(ps + cfg->point_state_node_count_offset)`.
 *   - `0x00d218..0x00d2a8`: If mismatch (`b.ne #0xd1f0`), iterates the doubly-linked list starting at
 *     `*(uintptr_t*)(ps + cfg->point_state_list_head_offset)` and unlinks every node whose `slot_entry->temp_buffer`
 *     falls inside `[tls->temp_buffer_addr, tls->temp_buffer_addr + tls->temp_buffer_size)` (`[rebuild_list]`),
 *     updating `prev->next`, `next->prev`, `list_head`, `list_tail`, and decrementing `node_count`!
 */
void adreno_uaf_beta_rebuild_list_tracepoint(AdrenoUafBetaConfig* cfg, ShadowHookCpuContext* ctx) {
    auto* tls = static_cast<AdrenoUafBetaTlsState*>(pthread_getspecific(cfg->tls_key));
    if (tls == nullptr || tls->temp_buffer_addr == 0 || tls->temp_buffer_size == 0) {
        return;
    }
    uintptr_t ps = ctx->regs[cfg->point_state_register_number];
    if (ps == 0) {
        return;
    }

    uint64_t expected_slots = tls->temp_buffer_size / static_cast<uint64_t>(cfg->size_of_per_temp_buffer);
    uint32_t actual_count = *reinterpret_cast<const uint32_t*>(
        ps + static_cast<intptr_t>(cfg->point_state_node_count_offset));
    if (expected_slots == actual_count) {
        return;
    }

    uintptr_t cur_node = *reinterpret_cast<const uintptr_t*>(
        ps + static_cast<intptr_t>(cfg->point_state_list_head_offset));
    uintptr_t buf_end = tls->temp_buffer_addr + tls->temp_buffer_size;

    while (cur_node != 0) {
        uintptr_t slot_entry = *reinterpret_cast<const uintptr_t*>(
            cur_node + static_cast<intptr_t>(cfg->list_node_slot_entry_offset));
        uintptr_t next_node = *reinterpret_cast<const uintptr_t*>(
            cur_node + static_cast<intptr_t>(cfg->list_node_next_offset));
        uintptr_t entry_buf = *reinterpret_cast<const uintptr_t*>(
            slot_entry + static_cast<intptr_t>(cfg->slot_entry_temp_buffer_offset));

        if (entry_buf >= tls->temp_buffer_addr && entry_buf < buf_end) {
            __android_log_print(
                ANDROID_LOG_ERROR, kLogTag,
                "[rebuild_list] ps: 0x%lx, slot_entry: 0x%lx, buffer: 0x%lx, temp_buffer: 0x%lx, temp_buffer_size: %lu, count: %d",
                static_cast<unsigned long>(ps),
                static_cast<unsigned long>(slot_entry),
                static_cast<unsigned long>(entry_buf),
                static_cast<unsigned long>(tls->temp_buffer_addr),
                static_cast<unsigned long>(tls->temp_buffer_size),
                actual_count);

            uintptr_t prev_node = *reinterpret_cast<const uintptr_t*>(
                cur_node + static_cast<intptr_t>(cfg->list_node_prev_offset));
            if (prev_node == 0) {
                *reinterpret_cast<uintptr_t*>(
                    ps + static_cast<intptr_t>(cfg->point_state_list_head_offset)) = next_node;
            } else {
                *reinterpret_cast<uintptr_t*>(
                    prev_node + static_cast<intptr_t>(cfg->list_node_next_offset)) = next_node;
            }

            if (next_node == 0) {
                *reinterpret_cast<uintptr_t*>(
                    ps + static_cast<intptr_t>(cfg->point_state_list_tail_offset)) = prev_node;
            } else {
                *reinterpret_cast<uintptr_t*>(
                    next_node + static_cast<intptr_t>(cfg->list_node_prev_offset)) = prev_node;
            }

            *reinterpret_cast<uintptr_t*>(cur_node + static_cast<intptr_t>(cfg->list_node_prev_offset)) = 0;
            *reinterpret_cast<uintptr_t*>(cur_node + static_cast<intptr_t>(cfg->list_node_next_offset)) = 0;

            uint32_t cur_cnt = *reinterpret_cast<const uint32_t*>(
                ps + static_cast<intptr_t>(cfg->point_state_node_count_offset));
            if (cur_cnt != 0) {
                *reinterpret_cast<uint32_t*>(
                    ps + static_cast<intptr_t>(cfg->point_state_node_count_offset)) = cur_cnt - 1;
            }
        }
        cur_node = next_node;
    }
}

// ============================================================================
// 2. DL_ITERATE_PHDR WEBVIEW SEGMENT SCANNER (0x00e5e8..0x00e810)
// ============================================================================

struct DlIterateWebviewData {
    std::string target_so_name;  // +0x00..0x17
    uintptr_t   seg_start;       // +0x18
    uintptr_t   seg_end;         // +0x20
    uint8_t     found;           // +0x28
};

/**
 * @brief `dl_iterate_phdr` callback (`0x00e5e8..0x00e810`) finding `PT_LOAD` (`p_type == 1`) segments of `libwebviewchromium.so`.
 *        Callback `dl_iterate_phdr` (`0x00e5e8..0x00e810`) tìm các phân đoạn `PT_LOAD` (`p_type == 1`) của `libwebviewchromium.so`.
 */
int webview_dl_iterate_phdr_callback(struct dl_phdr_info* info, size_t /*size*/, void* data_raw) {
    auto* data = static_cast<DlIterateWebviewData*>(data_raw);
    if (info->dlpi_name == nullptr || info->dlpi_name[0] == '\0' || data->found != 0) {
        return 0;
    }
    std::string dlpi_name_str(info->dlpi_name);
    if (dlpi_name_str.find(data->target_so_name) == std::string::npos) {
        return 0;
    }
    if (info->dlpi_phnum == 0) {
        return 0;
    }

    uintptr_t min_start = UINTPTR_MAX;
    uintptr_t max_end   = 0;
    for (uint16_t i = 0; i < info->dlpi_phnum; ++i) {
        const Elf64_Phdr& phdr = info->dlpi_phdr[i];
        if (phdr.p_type == PT_LOAD) {  // p_type == 1 (0x00e740: cmp w10, #1)
            uintptr_t seg_s = info->dlpi_addr + phdr.p_vaddr;
            uintptr_t seg_e = seg_s + phdr.p_memsz;
            __android_log_print(ANDROID_LOG_ERROR, kLogTag,
                                "so_name: %s, seg_start: %lx, seg_end: %lx",
                                info->dlpi_name,
                                static_cast<unsigned long>(seg_s),
                                static_cast<unsigned long>(seg_e));
            if (seg_s < min_start) {
                min_start = seg_s;
            }
            if (seg_e > max_end) {
                max_end = seg_e;
            }
        }
    }

    if (max_end != 0) {
        data->seg_start = min_start;
        data->seg_end   = max_end;
        data->found     = 1;
        return 1;
    }
    return 0;
}

}  // namespace pseudocode
}  // namespace touphic
}  // namespace godzilla
}  // namespace platform
}  // namespace bytedance
