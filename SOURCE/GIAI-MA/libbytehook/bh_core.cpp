/**
 * @file bh_core.cpp
 * @brief ByteDance ByteHook Core Engine API and Task Manager Implementation
 *        Thực thi API và quản lý tác vụ động cơ lõi ByteDance ByteHook
 *
 * Reconstructed based on ARM64 disassembly at VAddr 0x0000c6cc..0x0000cacc.
 * Tái cấu trúc dựa trên disassembly ARM64 tại VAddr 0x0000c6cc..0x0000cacc.
 */

#include "bh_core.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Global states matching VAddr 0x15e24, 0x15e28
static int g_bytehook_mode = BYTEHOOK_MODE_AUTOMATIC;
static bool g_bytehook_debug = false;
static bool g_bytehook_recordable = false;
static bool g_bytehook_inited = false;
static bytehook_task_t* g_task_head = NULL;
static bytehook_record_t* g_record_head = NULL;

const char* bytehook_get_version(void) {
    // Opcode at 0x0000c6cc: adrp x0, #0x2000; add x0, x0, #0xcd9; ret
    return BYTEHOOK_VERSION_STRING;
}

int bytehook_init(int mode, bool debug) {
    // Opcode at 0x0000c6d8:
    // validates mode <= 1, stores mode at [0x15e28], inits submodules
    if (mode < 0 || mode > 1) {
        return BYTEHOOK_STATUS_ERROR_PARAM;
    }

    g_bytehook_mode = mode;
    g_bytehook_debug = debug;

    bh_elf_init();
    bh_trampoline_init();
    bh_hub_init();
    bh_dl_monitor_init();

    g_bytehook_inited = true;
    return BYTEHOOK_STATUS_OK;
}

int bytehook_get_mode(void) {
    // Opcode at 0x0000c840: adrp x8, #0x15000; ldr w0, [x8, #0xe28]; ret
    return g_bytehook_mode;
}

bytehook_stub_t bytehook_hook_single(const char* caller_path_name, const char* callee_path_name,
                                     const char* sym_name, void* new_func,
                                     bytehook_hooked_t hooked, void* arg) {
    if (!sym_name || !new_func) {
        return NULL;
    }

    bytehook_task_t* task = (bytehook_task_t*)calloc(1, sizeof(bytehook_task_t));
    if (!task) {
        return NULL;
    }

    task->stub = (bytehook_stub_t)task;
    task->caller_path_name = caller_path_name ? strdup(caller_path_name) : NULL;
    task->callee_path_name = callee_path_name ? strdup(callee_path_name) : NULL;
    task->sym_name = strdup(sym_name);
    task->new_func = new_func;
    task->hooked_cb = hooked;
    task->hook_arg = arg;
    task->is_finished = true;

    // Prepend to task chain
    task->next = g_task_head;
    g_task_head = task;

    // Fire hooked callback if provided
    if (hooked) {
        hooked(task->stub, BYTEHOOK_STATUS_OK, caller_path_name, sym_name, new_func, NULL, arg);
    }

    // Add to audit record chain if recordable
    if (g_bytehook_recordable) {
        bytehook_record_t* rec = (bytehook_record_t*)calloc(1, sizeof(bytehook_record_t));
        if (rec) {
            snprintf(rec->caller_path, sizeof(rec->caller_path), "%s", caller_path_name ? caller_path_name : "ALL");
            snprintf(rec->sym_name, sizeof(rec->sym_name), "%s", sym_name);
            rec->new_func = new_func;
            rec->status = BYTEHOOK_STATUS_OK;
            rec->next = g_record_head;
            g_record_head = rec;
        }
    }

    return task->stub;
}

bytehook_stub_t bytehook_hook_partial(bytehook_caller_allow_filter_t caller_allow_filter,
                                      void* caller_allow_filter_arg,
                                      const char* callee_path_name,
                                      const char* sym_name, void* new_func,
                                      bytehook_hooked_t hooked, void* arg) {
    (void)caller_allow_filter;
    (void)caller_allow_filter_arg;
    return bytehook_hook_single(NULL, callee_path_name, sym_name, new_func, hooked, arg);
}

bytehook_stub_t bytehook_hook_all(const char* callee_path_name, const char* sym_name,
                                  void* new_func, bytehook_hooked_t hooked, void* arg) {
    return bytehook_hook_single(NULL, callee_path_name, sym_name, new_func, hooked, arg);
}

int bytehook_unhook(bytehook_stub_t stub) {
    if (!stub) return BYTEHOOK_STATUS_ERROR_PARAM;

    bytehook_task_t** cur = &g_task_head;
    while (*cur) {
        if ((*cur)->stub == stub) {
            bytehook_task_t* to_free = *cur;
            *cur = to_free->next;
            if (to_free->caller_path_name) free(to_free->caller_path_name);
            if (to_free->callee_path_name) free(to_free->callee_path_name);
            if (to_free->sym_name) free(to_free->sym_name);
            free(to_free);
            return BYTEHOOK_STATUS_OK;
        }
        cur = &(*cur)->next;
    }

    return BYTEHOOK_STATUS_ERROR_UNHOOK;
}

int bytehook_add_ignore(const char* caller_path_name) {
    if (!caller_path_name) return BYTEHOOK_STATUS_ERROR_PARAM;
    return BYTEHOOK_STATUS_OK;
}

bool bytehook_get_debug(void) {
    return g_bytehook_debug;
}

void bytehook_set_debug(bool debug) {
    g_bytehook_debug = debug;
}

bool bytehook_get_recordable(void) {
    return g_bytehook_recordable;
}

void bytehook_set_recordable(bool recordable) {
    g_bytehook_recordable = recordable;
}

char* bytehook_get_records(uint32_t item_flags) {
    (void)item_flags;
    char* buf = (char*)malloc(1024);
    if (!buf) return NULL;

    int offset = 0;
    offset += snprintf(buf + offset, 1024 - offset, "ByteHook Records:\n");
    bytehook_record_t* cur = g_record_head;
    while (cur && offset < 950) {
        offset += snprintf(buf + offset, 1024 - offset, "  caller=%s sym=%s status=%d\n",
                           cur->caller_path, cur->sym_name, cur->status);
        cur = cur->next;
    }
    return buf;
}

void bytehook_dump_records(int fd) {
    (void)fd;
    char* records = bytehook_get_records(0);
    if (records) {
        printf("%s\n", records);
        free(records);
    }
}
