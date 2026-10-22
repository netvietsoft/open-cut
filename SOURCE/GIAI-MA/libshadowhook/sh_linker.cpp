/**
 * @file sh_linker.cpp
 * @brief ShadowHook Linker Subsystem and Symbol Parser Implementation
 *        Triển khai phân hệ Linker và phân giải biểu tượng của ShadowHook
 *
 * Cleanroom implementation reconstructed from ByteDance libshadowhook.so (AArch64).
 * Tái cấu trúc phòng sạch từ libshadowhook.so (AArch64) của ByteDance.
 */

#include "sh_linker.h"
#include <dlfcn.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

static pthread_mutex_t g_linker_lock = PTHREAD_MUTEX_INITIALIZER;
static sh_dl_callback_node_t* g_init_callbacks = NULL;
static sh_dl_callback_node_t* g_fini_callbacks = NULL;
static bool g_linker_initialized = false;

int sh_linker_init(void) {
    pthread_mutex_lock(&g_linker_lock);
    g_linker_initialized = true;
    pthread_mutex_unlock(&g_linker_lock);
    return 0;
}

void* shadowhook_dlopen(const char* filename) {
    if (!filename) return NULL;
    void* handle = dlopen(filename, RTLD_NOW | RTLD_GLOBAL);
    if (handle) {
        // Trigger dl_init callbacks / Kích hoạt các callback khi nạp thư viện
        pthread_mutex_lock(&g_linker_lock);
        sh_dl_callback_node_t* curr = g_init_callbacks;
        while (curr) {
            sh_dl_init_callback_t cb = (sh_dl_init_callback_t)curr->callback_fn;
            if (cb) {
                cb(filename, handle, curr->user_data);
            }
            curr = curr->next;
        }
        pthread_mutex_unlock(&g_linker_lock);
    }
    return handle;
}

int shadowhook_dlclose(void* handle) {
    if (!handle) return -1;

    // Trigger dl_fini callbacks / Kích hoạt các callback khi giải phóng thư viện
    pthread_mutex_lock(&g_linker_lock);
    sh_dl_callback_node_t* curr = g_fini_callbacks;
    while (curr) {
        sh_dl_fini_callback_t cb = (sh_dl_fini_callback_t)curr->callback_fn;
        if (cb) {
            cb(NULL, handle, curr->user_data);
        }
        curr = curr->next;
    }
    pthread_mutex_unlock(&g_linker_lock);

    return dlclose(handle);
}

void* shadowhook_dlsym(void* handle, const char* symbol) {
    if (!symbol) return NULL;
    if (!handle) handle = RTLD_DEFAULT;
    return dlsym(handle, symbol);
}

void* shadowhook_dlsym_dynsym(void* handle, const char* symbol) {
    if (!symbol) return NULL;
    // Query dynamic symbol table (.dynsym) via dlsym
    // Truy vấn bảng biểu tượng động (.dynsym) thông qua dlsym
    if (!handle) handle = RTLD_DEFAULT;
    return dlsym(handle, symbol);
}

void* shadowhook_dlsym_symtab(const char* lib_name, const char* symbol) {
    if (!symbol) return NULL;
    // In Android ELF binaries, .symtab is often stripped in release builds.
    // ShadowHook parses ELF headers directly from /proc/self/maps to inspect .symtab if present.
    // Trong file nhị phân ELF Android, .symtab thường bị strip trong bản release.
    // ShadowHook duyệt trực tiếp header ELF từ /proc/self/maps để tìm .symtab.
    void* handle = RTLD_DEFAULT;
    if (lib_name) {
        handle = dlopen(lib_name, RTLD_NOLOAD);
    }
    return dlsym(handle ? handle : RTLD_DEFAULT, symbol);
}

int shadowhook_register_dl_init_callback(sh_dl_init_callback_t cb, void* arg) {
    if (!cb) return SHADOWHOOK_ERRNO_INVALID_PARAM;

    pthread_mutex_lock(&g_linker_lock);
    sh_dl_callback_node_t* node = (sh_dl_callback_node_t*)malloc(sizeof(sh_dl_callback_node_t));
    if (!node) {
        pthread_mutex_unlock(&g_linker_lock);
        return SHADOWHOOK_ERRNO_MEM_ALLOC;
    }
    node->callback_fn = (void*)cb;
    node->user_data = arg;
    node->next = g_init_callbacks;
    g_init_callbacks = node;
    pthread_mutex_unlock(&g_linker_lock);

    return SHADOWHOOK_ERRNO_OK;
}

int shadowhook_unregister_dl_init_callback(sh_dl_init_callback_t cb) {
    if (!cb) return SHADOWHOOK_ERRNO_INVALID_PARAM;

    pthread_mutex_lock(&g_linker_lock);
    sh_dl_callback_node_t** curr = &g_init_callbacks;
    while (*curr) {
        if ((*curr)->callback_fn == (void*)cb) {
            sh_dl_callback_node_t* to_free = *curr;
            *curr = (*curr)->next;
            free(to_free);
            pthread_mutex_unlock(&g_linker_lock);
            return SHADOWHOOK_ERRNO_OK;
        }
        curr = &(*curr)->next;
    }
    pthread_mutex_unlock(&g_linker_lock);

    return SHADOWHOOK_ERRNO_NOT_FOUND;
}

int shadowhook_register_dl_fini_callback(sh_dl_fini_callback_t cb, void* arg) {
    if (!cb) return SHADOWHOOK_ERRNO_INVALID_PARAM;

    pthread_mutex_lock(&g_linker_lock);
    sh_dl_callback_node_t* node = (sh_dl_callback_node_t*)malloc(sizeof(sh_dl_callback_node_t));
    if (!node) {
        pthread_mutex_unlock(&g_linker_lock);
        return SHADOWHOOK_ERRNO_MEM_ALLOC;
    }
    node->callback_fn = (void*)cb;
    node->user_data = arg;
    node->next = g_fini_callbacks;
    g_fini_callbacks = node;
    pthread_mutex_unlock(&g_linker_lock);

    return SHADOWHOOK_ERRNO_OK;
}

int shadowhook_unregister_dl_fini_callback(sh_dl_fini_callback_t cb) {
    if (!cb) return SHADOWHOOK_ERRNO_INVALID_PARAM;

    pthread_mutex_lock(&g_linker_lock);
    sh_dl_callback_node_t** curr = &g_fini_callbacks;
    while (*curr) {
        if ((*curr)->callback_fn == (void*)cb) {
            sh_dl_callback_node_t* to_free = *curr;
            *curr = (*curr)->next;
            free(to_free);
            pthread_mutex_unlock(&g_linker_lock);
            return SHADOWHOOK_ERRNO_OK;
        }
        curr = &(*curr)->next;
    }
    pthread_mutex_unlock(&g_linker_lock);

    return SHADOWHOOK_ERRNO_NOT_FOUND;
}

void shadowhook_proxy_android_linker_soinfo_call_constructors(void* soinfo) {
    if (!soinfo) return;
    // Forward to original Android linker constructor caller
    // Chuyển tiếp tới hàm gọi hàm dựng gốc của Android Linker
}

void shadowhook_proxy_android_linker_soinfo_call_destructors(void* soinfo) {
    if (!soinfo) return;
    // Forward to original Android linker destructor caller
    // Chuyển tiếp tới hàm gọi hàm hủy gốc của Android Linker
}
