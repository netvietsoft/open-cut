/**
 * @file bytevc2_dpb.cpp
 * @brief Decoded Picture Buffer (DPB) Management Implementation
 *        Thực thi quản lý bộ đệm hình ảnh giải mã (DPB)
 *
 * Implements POC reordering and display queue semantics matching ByteDance ByteVC2.
 * Thực thi sắp xếp thứ tự hiển thị theo POC khớp chuẩn ByteVC2 của ByteDance.
 */

#include "bytevc2_dpb.h"
#include <string.h>
#include <stdlib.h>

void bytevc2_dpb_init(ByteVC2Dpb* dpb, int32_t max_size) {
    if (!dpb) return;

    memset(dpb, 0, sizeof(ByteVC2Dpb));
    if (max_size <= 0 || max_size > BYTEVC2_MAX_DPB_SIZE) {
        max_size = BYTEVC2_MAX_DPB_SIZE;
    }
    dpb->max_size = max_size;
    dpb->max_num_reorder_pics = 4;
    dpb->last_output_poc = -1;
}

void bytevc2_dpb_release(ByteVC2Dpb* dpb) {
    if (!dpb) return;

    for (int i = 0; i < BYTEVC2_MAX_DPB_SIZE; i++) {
        if (dpb->entries[i].in_use && dpb->entries[i].frame) {
            byteVC2dec_release_frame(dpb->entries[i].frame);
            dpb->entries[i].frame = NULL;
        }
        dpb->entries[i].in_use = false;
    }
    dpb->current_size = 0;
}

int32_t bytevc2_dpb_insert(ByteVC2Dpb* dpb, ByteVC2Frame* frame, int32_t poc, int64_t pts, bool is_ref) {
    if (!dpb || !frame) return -1;

    // Find free slot
    int slot = -1;
    for (int i = 0; i < dpb->max_size; i++) {
        if (!dpb->entries[i].in_use) {
            slot = i;
            break;
        }
    }

    if (slot < 0) {
        return -1; // DPB full
    }

    dpb->entries[slot].frame = frame;
    dpb->entries[slot].poc = poc;
    dpb->entries[slot].pts = pts;
    dpb->entries[slot].is_reference = is_ref;
    dpb->entries[slot].is_outputted = false;
    dpb->entries[slot].in_use = true;
    dpb->entries[slot].ref_count = 1;
    dpb->current_size++;

    return 0;
}

ByteVC2Frame* bytevc2_dpb_get_display_frame(ByteVC2Dpb* dpb) {
    if (!dpb || dpb->current_size == 0) return NULL;

    // Find smallest un-outputted POC
    int best_slot = -1;
    int32_t min_poc = 0x7fffffff;

    for (int i = 0; i < dpb->max_size; i++) {
        if (dpb->entries[i].in_use && !dpb->entries[i].is_outputted) {
            if (dpb->entries[i].poc < min_poc) {
                min_poc = dpb->entries[i].poc;
                best_slot = i;
            }
        }
    }

    if (best_slot >= 0) {
        dpb->entries[best_slot].is_outputted = true;
        dpb->last_output_poc = min_poc;
        return dpb->entries[best_slot].frame;
    }

    return NULL;
}

int32_t bytevc2_dpb_return_frame(ByteVC2Dpb* dpb, ByteVC2Frame* frame) {
    if (!dpb || !frame) return -1;

    for (int i = 0; i < dpb->max_size; i++) {
        if (dpb->entries[i].in_use && dpb->entries[i].frame == frame) {
            dpb->entries[i].ref_count--;
            // If already outputted and no longer needed as reference
            if (dpb->entries[i].ref_count <= 0 && (!dpb->entries[i].is_reference || dpb->entries[i].is_outputted)) {
                byteVC2dec_release_frame(dpb->entries[i].frame);
                dpb->entries[i].frame = NULL;
                dpb->entries[i].in_use = false;
                dpb->current_size--;
            }
            return 0;
        }
    }

    return -1;
}

void bytevc2_dpb_flush(ByteVC2Dpb* dpb) {
    if (!dpb) return;

    for (int i = 0; i < dpb->max_size; i++) {
        if (dpb->entries[i].in_use && dpb->entries[i].frame) {
            dpb->entries[i].is_outputted = true;
        }
    }
}
