/**
 * @file bh_dl_monitor.cpp
 * @brief Dynamic Linker Monitor Implementation
 *        Thực thi bộ giám sát trình liên kết động
 *
 * Implements callback management matching VAddr 0x0000cb24 and 0x0000cb28.
 * Thực thi quản lý hàm gọi lại khớp mã máy tại VAddr 0x0000cb24 và 0x0000cb28.
 */

#include "bh_dl_monitor.h"
#include <string.h>

static bh_dlopen_cb_entry_t g_dlopen_cbs[BH_MAX_DLOPEN_CBS] = {{0}};

int bh_dl_monitor_init(void) {
    memset(g_dlopen_cbs, 0, sizeof(g_dlopen_cbs));
    return 0;
}

int bytehook_add_dlopen_callback(bytehook_dlopen_cb_t cb, void* data) {
    if (!cb) return BYTEHOOK_STATUS_ERROR_PARAM;

    for (int i = 0; i < BH_MAX_DLOPEN_CBS; i++) {
        if (!g_dlopen_cbs[i].in_use) {
            g_dlopen_cbs[i].cb = cb;
            g_dlopen_cbs[i].data = data;
            g_dlopen_cbs[i].in_use = true;
            return BYTEHOOK_STATUS_OK;
        }
    }
    return BYTEHOOK_STATUS_ERROR_INIT; // Max callbacks reached
}

int bytehook_del_dlopen_callback(bytehook_dlopen_cb_t cb, void* data) {
    if (!cb) return BYTEHOOK_STATUS_ERROR_PARAM;

    for (int i = 0; i < BH_MAX_DLOPEN_CBS; i++) {
        if (g_dlopen_cbs[i].in_use && g_dlopen_cbs[i].cb == cb && g_dlopen_cbs[i].data == data) {
            g_dlopen_cbs[i].in_use = false;
            g_dlopen_cbs[i].cb = NULL;
            g_dlopen_cbs[i].data = NULL;
            return BYTEHOOK_STATUS_OK;
        }
    }
    return BYTEHOOK_STATUS_ERROR_NOT_FOUND;
}

void bh_dl_monitor_notify(const char* filename) {
    if (!filename) return;

    for (int i = 0; i < BH_MAX_DLOPEN_CBS; i++) {
        if (g_dlopen_cbs[i].in_use && g_dlopen_cbs[i].cb) {
            g_dlopen_cbs[i].cb(filename, g_dlopen_cbs[i].data);
        }
    }
}
