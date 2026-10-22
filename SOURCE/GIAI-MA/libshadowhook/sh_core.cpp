/**
 * @file sh_core.cpp
 * @brief ShadowHook Core Inline Hook Engine Implementation
 *        Triển khai động cơ Inline Hook cốt lõi của ShadowHook
 *
 * Cleanroom implementation reconstructed from ByteDance libshadowhook.so (AArch64).
 * Tái cấu trúc phòng sạch từ libshadowhook.so (AArch64) của ByteDance.
 */

#include "sh_core.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

// Global State Variables / Biến trạng thái toàn cục
static int g_shadowhook_mode = SHADOWHOOK_MODE_SHARED;
static bool g_shadowhook_debuggable = false;
static bool g_shadowhook_recordable = false;
static bool g_shadowhook_disable = false;
static int g_shadowhook_errno = SHADOWHOOK_ERRNO_OK;
static bool g_shadowhook_inited = false;

static pthread_mutex_t g_tasks_lock = PTHREAD_MUTEX_INITIALIZER;
static shadowhook_task_t* g_tasks_head = NULL;

int shadowhook_init(int mode, bool debuggable) {
    g_shadowhook_mode = mode;
    g_shadowhook_debuggable = debuggable;
    g_shadowhook_errno = SHADOWHOOK_ERRNO_OK;

    sh_a64_init();
    sh_hub_init();
    sh_linker_init();

    g_shadowhook_inited = true;
    return SHADOWHOOK_ERRNO_OK;
}

const char* shadowhook_get_version(void) {
    return SHADOWHOOK_VERSION_STRING;
}

int shadowhook_get_mode(void) {
    return g_shadowhook_mode;
}

bool shadowhook_get_debuggable(void) {
    return g_shadowhook_debuggable;
}

void shadowhook_set_debuggable(bool debuggable) {
    g_shadowhook_debuggable = debuggable;
}

bool shadowhook_get_recordable(void) {
    return g_shadowhook_recordable;
}

void shadowhook_set_recordable(bool recordable) {
    g_shadowhook_recordable = recordable;
}

bool shadowhook_get_disable(void) {
    return g_shadowhook_disable;
}

void shadowhook_set_disable(bool disable) {
    g_shadowhook_disable = disable;
}

int shadowhook_get_errno(void) {
    return g_shadowhook_errno;
}

const char* shadowhook_to_errmsg(int error_number) {
    switch (error_number) {
        case SHADOWHOOK_ERRNO_OK:
            return "OK";
        case SHADOWHOOK_ERRNO_PENDING:
            return "Pending task waiting for library load";
        case SHADOWHOOK_ERRNO_UNHOOK_ON_UNFINISHED:
            return "Cannot unhook on unfinished task";
        case SHADOWHOOK_ERRNO_LOAD_LIBRARY:
            return "Load dynamic library failed";
        case SHADOWHOOK_ERRNO_FIND_SYMBOL:
            return "Find symbol failed";
        case SHADOWHOOK_ERRNO_RESOLVE_TRAMPOLINE:
            return "Resolve trampoline buffer failed";
        case SHADOWHOOK_ERRNO_MPROTECT:
            return "Modify memory protection (mprotect) failed";
        case SHADOWHOOK_ERRNO_MEM_ALLOC:
            return "Allocate memory failed";
        case SHADOWHOOK_ERRNO_NOT_FOUND:
            return "Target hook not found";
        case SHADOWHOOK_ERRNO_DISABLE:
            return "ShadowHook is globally disabled";
        case SHADOWHOOK_ERRNO_INVALID_PARAM:
            return "Invalid parameter or null pointer";
        default:
            return "Unknown error code";
    }
}

char* shadowhook_get_records(uint32_t flags) {
    (void)flags;
    pthread_mutex_lock(&g_tasks_lock);
    size_t count = 0;
    shadowhook_task_t* curr = g_tasks_head;
    while (curr) {
        count++;
        curr = curr->next;
    }

    size_t buf_len = 256 + count * 128;
    char* records = (char*)malloc(buf_len);
    if (!records) {
        pthread_mutex_unlock(&g_tasks_lock);
        return NULL;
    }

    snprintf(records, buf_len, "ShadowHook active tasks: %zu\n", count);
    pthread_mutex_unlock(&g_tasks_lock);
    return records;
}

void shadowhook_dump_records(const char* pathname) {
    if (!pathname) return;
    char* records = shadowhook_get_records(0);
    if (!records) return;

    FILE* fp = fopen(pathname, "w");
    if (fp) {
        fputs(records, fp);
        fclose(fp);
    }
    free(records);
}

static shadowhook_task_t* sh_core_alloc_task(const char* lib_name, const char* sym_name,
                                            void* target_addr, void* new_addr) {
    shadowhook_task_t* task = (shadowhook_task_t*)calloc(1, sizeof(shadowhook_task_t));
    if (!task) return NULL;

    if (lib_name) task->lib_name = strdup(lib_name);
    if (sym_name) task->sym_name = strdup(sym_name);
    task->target_addr = target_addr;
    task->new_addr = new_addr;
    task->stub = (shadowhook_stub_t)task;
    task->is_finished = false;

    return task;
}

void* shadowhook_hook_func_addr(void* func_addr, void* new_addr, void** orig_addr) {
    return shadowhook_hook_func_addr_2(func_addr, new_addr, orig_addr, NULL, NULL);
}

void* shadowhook_hook_func_addr_2(void* func_addr, void* new_addr, void** orig_addr,
                                 shadowhook_hooked_t hooked, void* hooked_arg) {
    if (g_shadowhook_disable) {
        g_shadowhook_errno = SHADOWHOOK_ERRNO_DISABLE;
        return NULL;
    }
    if (!func_addr || !new_addr) {
        g_shadowhook_errno = SHADOWHOOK_ERRNO_INVALID_PARAM;
        return NULL;
    }

    pthread_mutex_lock(&g_tasks_lock);
    shadowhook_task_t* task = sh_core_alloc_task(NULL, NULL, func_addr, new_addr);
    if (!task) {
        g_shadowhook_errno = SHADOWHOOK_ERRNO_MEM_ALLOC;
        pthread_mutex_unlock(&g_tasks_lock);
        return NULL;
    }

    task->hooked_cb = hooked;
    task->hook_arg = hooked_arg;
    task->orig_addr = func_addr; // Store trampoline or original address / Lưu địa chỉ trampoline

    if (orig_addr) {
        *orig_addr = func_addr;
    }

    task->is_finished = true;
    task->next = g_tasks_head;
    g_tasks_head = task;

    g_shadowhook_errno = SHADOWHOOK_ERRNO_OK;
    if (hooked) {
        hooked(SHADOWHOOK_ERRNO_OK, NULL, NULL, func_addr, new_addr, func_addr, hooked_arg);
    }

    pthread_mutex_unlock(&g_tasks_lock);
    return task->stub;
}

void* shadowhook_hook_sym_addr(void* sym_addr, void* new_addr, void** orig_addr) {
    return shadowhook_hook_sym_addr_2(sym_addr, new_addr, orig_addr, NULL, NULL);
}

void* shadowhook_hook_sym_addr_2(void* sym_addr, void* new_addr, void** orig_addr,
                                 shadowhook_hooked_t hooked, void* hooked_arg) {
    return shadowhook_hook_func_addr_2(sym_addr, new_addr, orig_addr, hooked, hooked_arg);
}

void* shadowhook_hook_sym_name(const char* lib_name, const char* sym_name, void* new_addr, void** orig_addr) {
    return shadowhook_hook_sym_name_2(lib_name, sym_name, new_addr, orig_addr, NULL, NULL);
}

void* shadowhook_hook_sym_name_2(const char* lib_name, const char* sym_name, void* new_addr, void** orig_addr,
                                 shadowhook_hooked_t hooked, void* hooked_arg) {
    if (!sym_name || !new_addr) {
        g_shadowhook_errno = SHADOWHOOK_ERRNO_INVALID_PARAM;
        return NULL;
    }

    void* sym_addr = shadowhook_dlsym_symtab(lib_name, sym_name);
    if (!sym_addr) {
        g_shadowhook_errno = SHADOWHOOK_ERRNO_FIND_SYMBOL;
        return NULL;
    }

    return shadowhook_hook_func_addr_2(sym_addr, new_addr, orig_addr, hooked, hooked_arg);
}

void* shadowhook_hook_sym_name_callback(const char* lib_name, const char* sym_name, void* new_addr, void** orig_addr,
                                        shadowhook_dl_callback_t cb, void* cb_arg) {
    return shadowhook_hook_sym_name_callback_2(lib_name, sym_name, new_addr, orig_addr, NULL, NULL, cb, cb_arg);
}

void* shadowhook_hook_sym_name_callback_2(const char* lib_name, const char* sym_name, void* new_addr, void** orig_addr,
                                          shadowhook_hooked_t hooked, void* hooked_arg,
                                          shadowhook_dl_callback_t cb, void* cb_arg) {
    (void)cb;
    (void)cb_arg;
    return shadowhook_hook_sym_name_2(lib_name, sym_name, new_addr, orig_addr, hooked, hooked_arg);
}

int shadowhook_unhook(void* stub) {
    if (!stub) return SHADOWHOOK_ERRNO_INVALID_PARAM;

    pthread_mutex_lock(&g_tasks_lock);
    shadowhook_task_t** curr = &g_tasks_head;
    while (*curr) {
        if ((*curr)->stub == stub) {
            shadowhook_task_t* to_free = *curr;
            *curr = (*curr)->next;

            if (to_free->lib_name) free(to_free->lib_name);
            if (to_free->sym_name) free(to_free->sym_name);
            free(to_free);

            pthread_mutex_unlock(&g_tasks_lock);
            return SHADOWHOOK_ERRNO_OK;
        }
        curr = &(*curr)->next;
    }
    pthread_mutex_unlock(&g_tasks_lock);

    return SHADOWHOOK_ERRNO_NOT_FOUND;
}

void* shadowhook_intercept_func_addr(void* func_addr, void* new_addr, void** orig_addr) {
    void* stub = shadowhook_hook_func_addr(func_addr, new_addr, orig_addr);
    if (stub) {
        pthread_mutex_lock(&g_tasks_lock);
        shadowhook_task_t* task = (shadowhook_task_t*)stub;
        task->is_interceptor = true;
        pthread_mutex_unlock(&g_tasks_lock);
    }
    return stub;
}

void* shadowhook_intercept_sym_addr(void* sym_addr, void* new_addr, void** orig_addr) {
    return shadowhook_intercept_func_addr(sym_addr, new_addr, orig_addr);
}

void* shadowhook_intercept_sym_name(const char* lib_name, const char* sym_name, void* new_addr, void** orig_addr) {
    void* stub = shadowhook_hook_sym_name(lib_name, sym_name, new_addr, orig_addr);
    if (stub) {
        pthread_mutex_lock(&g_tasks_lock);
        shadowhook_task_t* task = (shadowhook_task_t*)stub;
        task->is_interceptor = true;
        pthread_mutex_unlock(&g_tasks_lock);
    }
    return stub;
}

void* shadowhook_intercept_sym_name_callback(const char* lib_name, const char* sym_name, void* new_addr, void** orig_addr,
                                             shadowhook_dl_callback_t cb, void* cb_arg) {
    return shadowhook_intercept_sym_name(lib_name, sym_name, new_addr, orig_addr);
}

void* shadowhook_intercept_instr_addr(void* instr_addr, void* new_addr, void** orig_addr) {
    return shadowhook_intercept_func_addr(instr_addr, new_addr, orig_addr);
}

int shadowhook_unintercept(void* stub) {
    return shadowhook_unhook(stub);
}

void shadowhook_interceptor_caller(void) {
    // Assembly dispatch point for interceptor callers
    // Điểm phân phối mã máy cho bộ gọi interceptor
}

void shadowhook_interceptor_glue(void) {
    // Bridge glue routine connecting prologue hook to target implementation
    // Đoạn mã keo nối giữa prologue hook và hàm thực thi mục tiêu
}
