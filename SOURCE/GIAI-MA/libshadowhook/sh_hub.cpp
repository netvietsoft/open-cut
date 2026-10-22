/**
 * @file sh_hub.cpp
 * @brief ShadowHook Multi-Hook Hub and Thread-Local Storage Stack Implementation
 *        Triển khai trung tâm điều phối đa hook và ngăn xếp TLS của ShadowHook
 *
 * Cleanroom implementation reconstructed from ByteDance libshadowhook.so (AArch64).
 * Tái cấu trúc phòng sạch từ libshadowhook.so (AArch64) của ByteDance.
 */

#include "sh_hub.h"
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

static pthread_key_t g_hub_tls_key;
static pthread_once_t g_hub_tls_once = PTHREAD_ONCE_INIT;

static void sh_hub_tls_destructor(void* val) {
    if (val) {
        free(val);
    }
}

static void sh_hub_tls_init_once(void) {
    pthread_key_create(&g_hub_tls_key, sh_hub_tls_destructor);
}

int sh_hub_init(void) {
    pthread_once(&g_hub_tls_once, sh_hub_tls_init_once);
    return 0;
}

static sh_hub_stack_t* sh_hub_get_or_create_stack(void) {
    pthread_once(&g_hub_tls_once, sh_hub_tls_init_once);
    sh_hub_stack_t* stack = (sh_hub_stack_t*)pthread_getspecific(g_hub_tls_key);
    if (!stack) {
        stack = (sh_hub_stack_t*)calloc(1, sizeof(sh_hub_stack_t));
        if (stack) {
            pthread_setspecific(g_hub_tls_key, stack);
        }
    }
    return stack;
}

int sh_hub_push_frame(void* target_addr, void* orig_addr, void* caller_addr) {
    sh_hub_stack_t* stack = sh_hub_get_or_create_stack();
    if (!stack) return -1;

    if (stack->depth >= SH_HUB_STACK_MAX_DEPTH) {
        return -2; // Stack overflow / Tràn ngăn xếp
    }

    sh_hub_frame_t* frame = &stack->frames[stack->depth++];
    frame->target_addr = target_addr;
    frame->orig_addr = orig_addr;
    frame->caller_addr = caller_addr;
    frame->allow_reentrant = true;

    return 0;
}

void shadowhook_pop_stack(void* target_addr) {
    sh_hub_stack_t* stack = sh_hub_get_or_create_stack();
    if (!stack || stack->depth == 0) return;

    if (target_addr) {
        // Pop matching target frame or top frame
        // Rút khung khớp với target hoặc khung đỉnh
        if (stack->frames[stack->depth - 1].target_addr == target_addr) {
            stack->depth--;
        } else {
            // Find and pop backwards / Tìm và loại bỏ ngược
            for (size_t i = stack->depth; i > 0; --i) {
                if (stack->frames[i - 1].target_addr == target_addr) {
                    for (size_t j = i - 1; j < stack->depth - 1; ++j) {
                        stack->frames[j] = stack->frames[j + 1];
                    }
                    stack->depth--;
                    break;
                }
            }
        }
    } else {
        stack->depth--;
    }
}

void* shadowhook_get_prev_func(void* func) {
    sh_hub_stack_t* stack = sh_hub_get_or_create_stack();
    if (!stack || stack->depth == 0) return NULL;

    // Search from top of stack for frame matching func
    // Tìm kiếm từ đỉnh ngăn xếp cho khung tương ứng với func
    for (size_t i = stack->depth; i > 0; --i) {
        if (stack->frames[i - 1].target_addr == func) {
            return stack->frames[i - 1].orig_addr;
        }
    }

    // Default to the top frame's original address
    // Mặc định trả về địa chỉ gốc của khung trên cùng
    return stack->frames[stack->depth - 1].orig_addr;
}

void* shadowhook_get_return_address(void) {
    sh_hub_stack_t* stack = sh_hub_get_or_create_stack();
    if (!stack || stack->depth == 0) return NULL;

    return stack->frames[stack->depth - 1].caller_addr;
}

void shadowhook_allow_reentrant(void* func) {
    sh_hub_stack_t* stack = sh_hub_get_or_create_stack();
    if (!stack) return;

    if (func) {
        for (size_t i = stack->depth; i > 0; --i) {
            if (stack->frames[i - 1].target_addr == func) {
                stack->frames[i - 1].allow_reentrant = true;
                return;
            }
        }
    }
    stack->global_disallow_reentrant = false;
}

void shadowhook_disallow_reentrant(void* func) {
    sh_hub_stack_t* stack = sh_hub_get_or_create_stack();
    if (!stack) return;

    if (func) {
        for (size_t i = stack->depth; i > 0; --i) {
            if (stack->frames[i - 1].target_addr == func) {
                stack->frames[i - 1].allow_reentrant = false;
                return;
            }
        }
    }
    stack->global_disallow_reentrant = true;
}
