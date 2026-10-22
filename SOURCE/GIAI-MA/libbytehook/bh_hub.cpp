/**
 * @file bh_hub.cpp
 * @brief Multi-Hook Hub Dispatcher and Thread-Local Call Stack Implementation
 *        Thực thi bộ điều phối đa Hook (Hub) và quản lý ngăn xếp gọi cục bộ theo luồng
 *
 * Implements thread-local stack operations matching VAddr 0x0000cad0, 0x0000caec, 0x0000cb08.
 * Thực thi các thao tác ngăn xếp cục bộ theo luồng khớp mã máy tại VAddr 0x0000cad0, 0x0000caec, 0x0000cb08.
 */

#include "bh_hub.h"
#include <stdlib.h>
#include <string.h>

#if defined(__linux__) || defined(__ANDROID__) || defined(__APPLE__)
#include <pthread.h>
static pthread_key_t g_tls_stack_key;
static bool g_tls_key_created = false;
#else
// Windows/Fallback simulation
static thread_local bh_stack_t g_thread_stack = {{{0}}, 0};
#endif

int bh_hub_init(void) {
#if defined(__linux__) || defined(__ANDROID__) || defined(__APPLE__)
    if (!g_tls_key_created) {
        if (pthread_key_create(&g_tls_stack_key, free) == 0) {
            g_tls_key_created = true;
        } else {
            return -1;
        }
    }
#endif
    return 0;
}

static bh_stack_t* bh_get_thread_stack(void) {
#if defined(__linux__) || defined(__ANDROID__) || defined(__APPLE__)
    if (!g_tls_key_created) {
        bh_hub_init();
    }
    bh_stack_t* stack = (bh_stack_t*)pthread_getspecific(g_tls_stack_key);
    if (!stack) {
        stack = (bh_stack_t*)calloc(1, sizeof(bh_stack_t));
        if (stack) {
            pthread_setspecific(g_tls_stack_key, stack);
        }
    }
    return stack;
#else
    return &g_thread_stack;
#endif
}

int bh_hub_push_stack(void* hook_func, void* prev_func, void* return_addr) {
    bh_stack_t* stack = bh_get_thread_stack();
    if (!stack || stack->top >= BH_STACK_MAX_DEPTH) {
        return -1;
    }

    stack->frames[stack->top].hook_func = hook_func;
    stack->frames[stack->top].prev_func = prev_func;
    stack->frames[stack->top].return_address = return_addr;
    stack->top++;
    return 0;
}

void* bytehook_get_prev_func(void* func) {
    bh_stack_t* stack = bh_get_thread_stack();
    if (!stack || stack->top <= 0) {
        return NULL;
    }

    // Traverse stack from top down to match current hook function
    for (int i = stack->top - 1; i >= 0; i--) {
        if (!func || stack->frames[i].hook_func == func) {
            return stack->frames[i].prev_func;
        }
    }

    // Default to the topmost frame predecessor
    return stack->frames[stack->top - 1].prev_func;
}

void* bytehook_get_return_address(void) {
    bh_stack_t* stack = bh_get_thread_stack();
    if (!stack || stack->top <= 0) {
        return NULL;
    }
    return stack->frames[stack->top - 1].return_address;
}

void bytehook_pop_stack(void* func) {
    bh_stack_t* stack = bh_get_thread_stack();
    if (!stack || stack->top <= 0) {
        return;
    }

    if (!func || stack->frames[stack->top - 1].hook_func == func) {
        stack->top--;
    } else {
        // Find and remove matching frame
        for (int i = stack->top - 1; i >= 0; i--) {
            if (stack->frames[i].hook_func == func) {
                for (int j = i; j < stack->top - 1; j++) {
                    stack->frames[j] = stack->frames[j + 1];
                }
                stack->top--;
                break;
            }
        }
    }
}
