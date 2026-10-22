/**
 * @file sh_linker.h
 * @brief ShadowHook Linker Subsystem, Symbol Resolvers, and Proxy Callbacks
 *        Phân hệ Linker, bộ giải quyết biểu tượng và hàm đại diện (proxy) của ShadowHook
 *
 * Provides ELF symbol parsing (.dynsym and .symtab) and linker lifecycle interception.
 * Cung cấp phân tích biểu tượng ELF (.dynsym và .symtab) và can thiệp vòng đời linker.
 */

#ifndef SH_LINKER_H
#define SH_LINKER_H

#include "sh_types.h"
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*sh_dl_init_callback_t)(const char* lib_name, void* handle, void* arg);
typedef void (*sh_dl_fini_callback_t)(const char* lib_name, void* handle, void* arg);

/**
 * @struct sh_dl_callback_node_t
 * @brief Callback listener node for linker events
 *        Nút lắng nghe sự kiện nạp/hủy thư viện của linker
 */
typedef struct sh_dl_callback_node {
    void* callback_fn;
    void* user_data;
    struct sh_dl_callback_node* next;
} sh_dl_callback_node_t;

/**
 * @brief Initialize Linker interception subsystem
 *        Khởi tạo phân hệ can thiệp Linker
 */
int sh_linker_init(void);

// Exported Linker and Symbol APIs / Các hàm API xuất khẩu về Linker và biểu tượng
void* shadowhook_dlopen(const char* filename);
int shadowhook_dlclose(void* handle);
void* shadowhook_dlsym(void* handle, const char* symbol);
void* shadowhook_dlsym_dynsym(void* handle, const char* symbol);
void* shadowhook_dlsym_symtab(const char* lib_name, const char* symbol);

// Init and Fini callbacks / Các hàm gọi lại khi thư viện khởi tạo/hủy
int shadowhook_register_dl_init_callback(sh_dl_init_callback_t cb, void* arg);
int shadowhook_unregister_dl_init_callback(sh_dl_init_callback_t cb);
int shadowhook_register_dl_fini_callback(sh_dl_fini_callback_t cb, void* arg);
int shadowhook_unregister_dl_fini_callback(sh_dl_fini_callback_t cb);

// Linker proxies / Các hàm proxy can thiệp vào Android Linker
void shadowhook_proxy_android_linker_soinfo_call_constructors(void* soinfo);
void shadowhook_proxy_android_linker_soinfo_call_destructors(void* soinfo);

#ifdef __cplusplus
}
#endif

#endif // SH_LINKER_H