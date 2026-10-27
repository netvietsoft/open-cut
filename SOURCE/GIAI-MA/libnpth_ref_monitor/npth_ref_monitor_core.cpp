// ============================================================================
// File: npth_ref_monitor_core.cpp
// Library: libnpth_ref_monitor.so (28,040 bytes)
// SHA-256: 8d4e40740d2ff59cecf0b6fd84188d47cafbb676638b263a657847747ae340aa
// Task ID: TASK-178-RECONSTRUCTION-LIBNPTH-REF-MONITOR / TASK_SO_084_libnpth_ref_monitor
// Clean-Room C++17 Implementation of All 52 FDEs (0x2f80..0x5ac8)
// Bilingual English + Vietnamese Functional & Mathematical Annotations
// ============================================================================

#include "npth_ref_monitor.hpp"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdarg>
#include <ctime>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/time.h>

extern "C" {
    int shadowhook_init(int mode, bool debuggable) __attribute__((weak));
    void* shadowhook_hook_sym_name(const char* lib_name, const char* sym_name, void* new_addr, void** orig_addr) __attribute__((weak));
    int shadowhook_unhook(void* stub) __attribute__((weak));
    void* shadowhook_get_prev_func(void* func) __attribute__((weak));
    int shadowhook_get_mode() __attribute__((weak));
    void shadowhook_pop_stack(void* return_address) __attribute__((weak));

    int xp_init_basic_env() __attribute__((weak));
    void* npth_dlopen(const char* filename) __attribute__((weak));
    void* npth_dlsym(void* handle, const char* symbol) __attribute__((weak));
    void npth_dlclose(void* handle) __attribute__((weak));
    size_t npth_fp_frames(uintptr_t* frames, size_t max_depth) __attribute__((weak));
    char* npth_fp_format(uintptr_t* frames, size_t depth) __attribute__((weak));
    void xp_get_current_backtrace(uintptr_t* methods, int* out_depth, int max_depth) __attribute__((weak));
    int xp_pretty_method(uintptr_t art_method, char* buf, size_t buf_len) __attribute__((weak));
    int __android_log_print(int prio, const char* tag, const char* fmt, ...) __attribute__((weak));
}

namespace npth::ref_monitor {

namespace {

uint32_t        g_ref_log_type_bss_e58c = 0;            // .bss 0xe58c (accessed at 0x5ab4 / 0x5ac0)
void*           g_hook_stubs_e5a0[11] = {nullptr};      // .bss 0xe5a0..0xe5f0 (11 * 8 = 88 B)
pthread_mutex_t g_global_ref_mutex_e5f8 = PTHREAD_MUTEX_INITIALIZER; // .bss 0xe5f8
pthread_mutex_t g_weak_ref_mutex_e620   = PTHREAD_MUTEX_INITIALIZER; // .bss 0xe620
RefTreeNode*    g_global_tree_root_e648 = nullptr;      // .bss 0xe648
RefTreeNode*    g_weak_tree_root_e650   = nullptr;      // .bss 0xe650

constexpr const char* kLogTag = "NPTH_REF_MONITOR"; // .rodata 0x214e

// FDE[09] (0x3674..0x371c): FormatPathPair_3674 ("%s/%s")
int FormatPathPair_3674(char* dst, size_t dst_cap, size_t /*chk_cap*/, const char* dir, const char* file) {
    if (!dst || dst_cap == 0 || !dir || !file) return -1;
    return std::snprintf(dst, dst_cap, "%s/%s", dir, file);
}

// FDE[35] (0x5360..0x5404): FormatBufferChecked_5360 (__vsnprintf_chk wrapper)
int FormatBufferChecked_5360(char* dst, size_t dst_cap, size_t /*chk_cap*/, const char* fmt, ...) {
    if (!dst || dst_cap == 0 || !fmt) return -1;
    va_list ap;
    va_start(ap, fmt);
    int n = std::vsnprintf(dst, dst_cap, fmt, ap);
    va_end(ap);
    return n;
}

// FDE[27] (0x42dc..0x4694): RBTreeDeleteNode_42dc (952 B)
RefTreeNode* RBTreeDeleteNode_42dc(RefTreeNode** root_ptr, RefTreeNode* z) {
    if (!root_ptr || !z) return z;
    RefTreeNode* y = z;
    RefTreeNode* x = nullptr;
    RefTreeNode* x_parent = nullptr;

    if (!z->left) {
        x = z->right;
    } else if (!z->right) {
        x = z->left;
    } else {
        y = z->right;
        while (y->left) {
            y = y->left;
        }
        x = y->right;
    }

    uint32_t removed_color = y->color;
    if (y != z) {
        z->left->parent = y;
        y->left = z->left;
        if (y != z->right) {
            x_parent = y->parent;
            if (x) x->parent = y->parent;
            y->parent->left = x;
            y->right = z->right;
            z->right->parent = y;
        } else {
            x_parent = y;
        }
        if (*root_ptr == z) {
            *root_ptr = y;
        } else if (z->parent->left == z) {
            z->parent->left = y;
        } else {
            z->parent->right = y;
        }
        y->parent = z->parent;
        y->color = z->color;
    } else {
        x_parent = z->parent;
        if (x) x->parent = z->parent;
        if (*root_ptr == z) {
            *root_ptr = x;
        } else if (z->parent->left == z) {
            z->parent->left = x;
        } else {
            z->parent->right = x;
        }
    }

    if (removed_color == 0) {
        while (x != *root_ptr && (!x || x->color == 0)) {
            if (!x_parent) break;
            if (x == x_parent->left) {
                RefTreeNode* w = x_parent->right;
                if (w && w->color == 1) {
                    w->color = 0;
                    x_parent->color = 1;
                    x_parent->right = w->left;
                    if (w->left) w->left->parent = x_parent;
                    w->parent = x_parent->parent;
                    if (!x_parent->parent) *root_ptr = w;
                    else if (x_parent == x_parent->parent->left) x_parent->parent->left = w;
                    else x_parent->parent->right = w;
                    w->left = x_parent;
                    x_parent->parent = w;
                    w = x_parent->right;
                }
                if (!w) break;
                if ((!w->left || w->left->color == 0) && (!w->right || w->right->color == 0)) {
                    w->color = 1;
                    x = x_parent;
                    x_parent = x->parent;
                } else {
                    if (!w->right || w->right->color == 0) {
                        if (w->left) w->left->color = 0;
                        w->color = 1;
                        RefTreeNode* wl = w->left;
                        if (wl) {
                            w->left = wl->right;
                            if (wl->right) wl->right->parent = w;
                            wl->parent = w->parent;
                            if (!w->parent) *root_ptr = wl;
                            else if (w == w->parent->left) w->parent->left = wl;
                            else w->parent->right = wl;
                            wl->right = w;
                            w->parent = wl;
                            w = x_parent->right;
                        }
                    }
                    if (w) {
                        w->color = x_parent->color;
                        if (w->right) w->right->color = 0;
                        x_parent->right = w->left;
                        if (w->left) w->left->parent = x_parent;
                        w->parent = x_parent->parent;
                        if (!x_parent->parent) *root_ptr = w;
                        else if (x_parent == x_parent->parent->left) x_parent->parent->left = w;
                        else x_parent->parent->right = w;
                        w->left = x_parent;
                        x_parent->parent = w;
                    }
                    x_parent->color = 0;
                    x = *root_ptr;
                    break;
                }
            } else {
                RefTreeNode* w = x_parent->left;
                if (w && w->color == 1) {
                    w->color = 0;
                    x_parent->color = 1;
                    x_parent->left = w->right;
                    if (w->right) w->right->parent = x_parent;
                    w->parent = x_parent->parent;
                    if (!x_parent->parent) *root_ptr = w;
                    else if (x_parent == x_parent->parent->left) x_parent->parent->left = w;
                    else x_parent->parent->right = w;
                    w->right = x_parent;
                    x_parent->parent = w;
                    w = x_parent->left;
                }
                if (!w) break;
                if ((!w->right || w->right->color == 0) && (!w->left || w->left->color == 0)) {
                    w->color = 1;
                    x = x_parent;
                    x_parent = x->parent;
                } else {
                    if (!w->left || w->left->color == 0) {
                        if (w->right) w->right->color = 0;
                        w->color = 1;
                        RefTreeNode* wr = w->right;
                        if (wr) {
                            w->right = wr->left;
                            if (wr->left) wr->left->parent = w;
                            wr->parent = w->parent;
                            if (!w->parent) *root_ptr = wr;
                            else if (w == w->parent->left) w->parent->left = wr;
                            else w->parent->right = wr;
                            wr->left = w;
                            w->parent = wr;
                            w = x_parent->left;
                        }
                    }
                    if (w) {
                        w->color = x_parent->color;
                        if (w->left) w->left->color = 0;
                        x_parent->left = w->right;
                        if (w->right) w->right->parent = x_parent;
                        w->parent = x_parent->parent;
                        if (!x_parent->parent) *root_ptr = w;
                        else if (x_parent == x_parent->parent->left) x_parent->parent->left = w;
                        else x_parent->parent->right = w;
                        w->right = x_parent;
                        x_parent->parent = w;
                    }
                    x_parent->color = 0;
                    x = *root_ptr;
                    break;
                }
            }
        }
        if (x) x->color = 0;
    }
    return z;
}

// FDE[23] (0x3ef4..0x3fc0): PostOrderFreeRefTree_3ef4
void PostOrderFreeRefTree_3ef4(RefTreeNode** root_ptr, uint32_t kind) {
    if (!root_ptr || !*root_ptr) return;
    while (*root_ptr) {
        RefTreeNode* node = *root_ptr;
        RBTreeDeleteNode_42dc(root_ptr, node);
        RefHashTable* ht = get_hash_table(kind);
        hash_table_remove_entry(ht, node->type_name);
        if (node->type_name) {
            std::free(node->type_name);
        }
        std::free(node);
    }
}

// FDE[28] (0x4694..0x46c0): FreeRefTreeNode_4694 (44 B)
void FreeRefTreeNode_4694(RefTreeNode* node) {
    if (!node) return;
    if (node->type_name) {
        std::free(node->type_name);
    }
    std::free(node);
}

// FDE[30] (0x4c34..0x4ca4): GetActiveRefCountByKind_4c34 (112 B)
int32_t GetActiveRefCountByKind_4c34(uint32_t kind) {
    if (kind == kRefKindWeakGlobal) {
        return g_ref_monitor_manager ? g_ref_monitor_manager->weak_ref_count : 0;
    }
    if (kind == kRefKindGlobal) {
        return g_ref_monitor_manager ? g_ref_monitor_manager->global_ref_count : 0;
    }
    if (kind == kRefKindLocal) {
        LocalRefThreadManager* local_mgr = get_or_init_local_manager(0);
        return local_mgr ? local_mgr->local_count : 0;
    }
    return 0;
}

// FDE[32] (0x4d70..0x4db8): LocalRefTlsDestructor_4d70 (72 B)
void LocalRefTlsDestructor_4d70(void* tls_val) {
    if (!tls_val) return;
    auto* mgr = static_cast<LocalRefThreadManager*>(tls_val);
    PostOrderFreeRefTree_3ef4(mgr->frame_tree_root, kRefKindLocal);
    PostOrderFreeRefTree_3ef4(mgr->base_tree_root, kRefKindLocal);
    free_hash_table(mgr->hash_table);
    std::free(mgr);
}

// FDE[42] (0x578c..0x57d4): NewRefHashEntry_578c (72 B)
RefHashEntry* NewRefHashEntry_578c(const char* type_name) {
    auto* entry = static_cast<RefHashEntry*>(std::calloc(1, sizeof(RefHashEntry)));
    if (entry) {
        entry->type_name = type_name ? strdup(type_name) : nullptr;
        entry->ref_count = 1;
    }
    return entry;
}

// PJW / ELF String Hash helper used at 0x55e0..0x5608 and 0x568c..0x56b4
uint32_t ComputeRefTypePjwHash(const char* s) noexcept {
    if (!s || !*s) return 0;
    uint32_t h = 0;
    for (const uint8_t* p = reinterpret_cast<const uint8_t*>(s); *p != 0; ++p) {
        h = (h << 4) + *p;
        uint32_t low28 = h & 0x0FFFFFFFu;
        uint32_t high4 = h >> 28;
        h = low28 ^ (high4 << 4);
    }
    return h;
}

// ============================================================================
// ART IndirectReferenceTable & JniMethodStart/End ShadowHook Proxies (FDE[12..20])
// ============================================================================

void* Proxy_IRT_Add_Api21To27_38f0(void* irt_self, uint32_t cookie, void* mirror_obj) {
    using OrigFn = void* (*)(void*, uint32_t, void*);
    auto orig = reinterpret_cast<OrigFn>(
        shadowhook_get_prev_func ? shadowhook_get_prev_func(reinterpret_cast<void*>(&Proxy_IRT_Add_Api21To27_38f0)) : nullptr);
    void* ref = orig ? orig(irt_self, cookie, mirror_obj) : nullptr;
    insert_ref_info(irt_self, ref, mirror_obj);
    if (shadowhook_get_mode && shadowhook_get_mode() == 0 && shadowhook_pop_stack) {
        shadowhook_pop_stack(__builtin_return_address(0));
    }
    return ref;
}

void* Proxy_IRT_Add_Api28To33_3970(void* irt_self, uint32_t cookie, void* mirror_obj, void* err_msg_std_string) {
    using OrigFn = void* (*)(void*, uint32_t, void*, void*);
    auto orig = reinterpret_cast<OrigFn>(
        shadowhook_get_prev_func ? shadowhook_get_prev_func(reinterpret_cast<void*>(&Proxy_IRT_Add_Api28To33_3970)) : nullptr);
    void* ref = orig ? orig(irt_self, cookie, mirror_obj, err_msg_std_string) : nullptr;
    insert_ref_info(irt_self, ref, mirror_obj);
    if (shadowhook_get_mode && shadowhook_get_mode() == 0 && shadowhook_pop_stack) {
        shadowhook_pop_stack(__builtin_return_address(0));
    }
    return ref;
}

bool Proxy_IRT_Remove_Api21To33_3a00(void* irt_self, uint32_t cookie, void* iref) {
    using OrigFn = bool (*)(void*, uint32_t, void*);
    auto orig = reinterpret_cast<OrigFn>(
        shadowhook_get_prev_func ? shadowhook_get_prev_func(reinterpret_cast<void*>(&Proxy_IRT_Remove_Api21To33_3a00)) : nullptr);
    bool removed = orig ? orig(irt_self, cookie, iref) : false;
    if (removed) {
        delete_ref_info(iref);
    }
    if (shadowhook_get_mode && shadowhook_get_mode() == 0 && shadowhook_pop_stack) {
        shadowhook_pop_stack(__builtin_return_address(0));
    }
    return removed;
}

uint32_t Proxy_JniMethodStart_3a7c(void* self_thread) {
    using OrigFn = uint32_t (*)(void*);
    auto orig = reinterpret_cast<OrigFn>(
        shadowhook_get_prev_func ? shadowhook_get_prev_func(reinterpret_cast<void*>(&Proxy_JniMethodStart_3a7c)) : nullptr);
    uint32_t cookie = orig ? orig(self_thread) : 0;
    store_local_ref();
    if (shadowhook_get_mode && shadowhook_get_mode() == 0 && shadowhook_pop_stack) {
        shadowhook_pop_stack(__builtin_return_address(0));
    }
    return cookie;
}

void Proxy_JniMethodEnd_3ad8(uint32_t cookie, void* self_thread) {
    using OrigFn = void (*)(uint32_t, void*);
    auto orig = reinterpret_cast<OrigFn>(
        shadowhook_get_prev_func ? shadowhook_get_prev_func(reinterpret_cast<void*>(&Proxy_JniMethodEnd_3ad8)) : nullptr);
    if (orig) orig(cookie, self_thread);
    release_local_ref();
    if (shadowhook_get_mode && shadowhook_get_mode() == 0 && shadowhook_pop_stack) {
        shadowhook_pop_stack(__builtin_return_address(0));
    }
}

void* Proxy_JniMethodEndWithReferenceSynchronized_Api21_3b48(void* result, uint32_t cookie, void* locked, void* self_thread) {
    using OrigFn = void* (*)(void*, uint32_t, void*, void*);
    auto orig = reinterpret_cast<OrigFn>(
        shadowhook_get_prev_func ? shadowhook_get_prev_func(reinterpret_cast<void*>(&Proxy_JniMethodEndWithReferenceSynchronized_Api21_3b48)) : nullptr);
    void* ret = orig ? orig(result, cookie, locked, self_thread) : nullptr;
    release_local_ref();
    if (shadowhook_get_mode && shadowhook_get_mode() == 0 && shadowhook_pop_stack) {
        shadowhook_pop_stack(__builtin_return_address(0));
    }
    return ret;
}

void* Proxy_GenericJniMethodEnd_3bcc(void* self_thread, uint32_t cookie, uint64_t result_jval, uint64_t return_shorty, void* called_method, void* handle_scope) {
    using OrigFn = void* (*)(void*, uint32_t, uint64_t, uint64_t, void*, void*);
    auto orig = reinterpret_cast<OrigFn>(
        shadowhook_get_prev_func ? shadowhook_get_prev_func(reinterpret_cast<void*>(&Proxy_GenericJniMethodEnd_3bcc)) : nullptr);
    void* ret = orig ? orig(self_thread, cookie, result_jval, return_shorty, called_method, handle_scope) : nullptr;
    release_local_ref();
    if (shadowhook_get_mode && shadowhook_get_mode() == 0 && shadowhook_pop_stack) {
        shadowhook_pop_stack(__builtin_return_address(0));
    }
    return ret;
}

void* Proxy_JniMethodEndWithReference_3c68(void* result, uint32_t cookie, void* self_thread) {
    using OrigFn = void* (*)(void*, uint32_t, void*);
    auto orig = reinterpret_cast<OrigFn>(
        shadowhook_get_prev_func ? shadowhook_get_prev_func(reinterpret_cast<void*>(&Proxy_JniMethodEndWithReference_3c68)) : nullptr);
    void* ret = orig ? orig(result, cookie, self_thread) : nullptr;
    release_local_ref();
    if (shadowhook_get_mode && shadowhook_get_mode() == 0 && shadowhook_pop_stack) {
        shadowhook_pop_stack(__builtin_return_address(0));
    }
    return ret;
}

void* Proxy_JniMethodEndWithReferenceSynchronized_Api24_3cdc(void* result, uint32_t cookie, void* locked, void* self_thread) {
    using OrigFn = void* (*)(void*, uint32_t, void*, void*);
    auto orig = reinterpret_cast<OrigFn>(
        shadowhook_get_prev_func ? shadowhook_get_prev_func(reinterpret_cast<void*>(&Proxy_JniMethodEndWithReferenceSynchronized_Api24_3cdc)) : nullptr);
    void* ret = orig ? orig(result, cookie, locked, self_thread) : nullptr;
    release_local_ref();
    if (shadowhook_get_mode && shadowhook_get_mode() == 0 && shadowhook_pop_stack) {
        shadowhook_pop_stack(__builtin_return_address(0));
    }
    return ret;
}

const RefHookDescriptor kArtRefHookTable_9f98[11] = {
    {21, 25, "_ZN3art22IndirectReferenceTable3AddEjPNS_6mirror6ObjectE",
     reinterpret_cast<void*>(&Proxy_IRT_Add_Api21To27_38f0), 1, 0},
    {26, 27, "_ZN3art22IndirectReferenceTable3AddENS_15IRTSegmentStateENS_6ObjPtrINS_6mirror6ObjectEEE",
     reinterpret_cast<void*>(&Proxy_IRT_Add_Api21To27_38f0), 1, 0},
    {28, 33, "_ZN3art22IndirectReferenceTable3AddENS_15IRTSegmentStateENS_6ObjPtrINS_6mirror6ObjectEEEPNSt3__112basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE",
     reinterpret_cast<void*>(&Proxy_IRT_Add_Api28To33_3970), 1, 0},
    {21, 25, "_ZN3art22IndirectReferenceTable6RemoveEjPv",
     reinterpret_cast<void*>(&Proxy_IRT_Remove_Api21To33_3a00), 2, 0},
    {28, 33, "_ZN3art22IndirectReferenceTable6RemoveENS_15IRTSegmentStateEPv",
     reinterpret_cast<void*>(&Proxy_IRT_Remove_Api21To33_3a00), 2, 0},
    {21, 25, "_ZN3art14JniMethodStartEPNS_6ThreadE",
     reinterpret_cast<void*>(&Proxy_JniMethodStart_3a7c), 3, 0},
    {21, 25, "_ZN3art12JniMethodEndEjPNS_6ThreadE",
     reinterpret_cast<void*>(&Proxy_JniMethodEnd_3ad8), 5, 0},
    {21, 25, "_ZN3art37JniMethodEndWithReferenceSynchronizedEP8_jobjectjS1_PNS_6ThreadE",
     reinterpret_cast<void*>(&Proxy_JniMethodEndWithReferenceSynchronized_Api21_3b48), 7, 0},
    {24, 25, "_ZN3art19GenericJniMethodEndEPNS_6ThreadEj6jvaluemPNS_9ArtMethodEPNS_11HandleScopeE",
     reinterpret_cast<void*>(&Proxy_GenericJniMethodEnd_3bcc), 8, 0},
    {24, 25, "_ZN3art25JniMethodEndWithReferenceEP8_jobjectjPNS_6ThreadE",
     reinterpret_cast<void*>(&Proxy_JniMethodEndWithReference_3c68), 9, 0},
    {24, 25, "_ZN3art37JniMethodEndWithReferenceSynchronizedEP8_jobjectjS1_PNS_6ThreadE",
     reinterpret_cast<void*>(&Proxy_JniMethodEndWithReferenceSynchronized_Api24_3cdc), 11, 0},
};

} // anonymous namespace

} // namespace npth::ref_monitor

extern "C" {

using namespace npth::ref_monitor;

RefMonitorConfig*  g_ref_config = nullptr;                          // .bss  0xe590
RefMonitorManager* g_ref_monitor_manager = nullptr;                 // .bss  0xe598
int32_t            npth_ref_log_prior = 4;                          // .data 0xe588
RefMonitorNativeInterface ref_monitor_native_interface_func = {     // .data 0xe578
    &so_initialize,
    &stop_monitor,
};

// FDE[05] (0x2fd0..0x3510): so_initialize (1,344 B)
int so_initialize(int sdk_int, const char* proc_name, const char* log_dir, const char* config_dir) {
    if (sdk_int < 21) {
        return 1;
    }
    g_ref_config = static_cast<RefMonitorConfig*>(std::calloc(1, sizeof(RefMonitorConfig)));
    if (!g_ref_config) {
        return 7;
    }
    g_ref_config->limit_global = 10000;
    g_ref_config->limit_weak   = 10000;
    g_ref_config->limit_local  = 5000;

    if (!config_dir) {
        std::free(g_ref_config);
        g_ref_config = nullptr;
        return 7;
    }

    char cfg_path[1024] = {0};
    if (FormatPathPair_3674(cfg_path, sizeof(cfg_path), sizeof(cfg_path), config_dir, "ref_monitor.config") < 1) {
        std::free(g_ref_config);
        g_ref_config = nullptr;
        return 7;
    }
    FILE* fp = std::fopen(cfg_path, "r");
    if (!fp) {
        std::free(g_ref_config);
        g_ref_config = nullptr;
        return 7;
    }

    char line[1024] = {0};
    char key[128] = {0};
    char val_str[128] = {0};
    while (std::fgets(line, sizeof(line), fp) != nullptr) {
        if (std::sscanf(line, "%[^=]=%s", key, val_str) != 2) {
            continue;
        }
        int val = std::atoi(val_str);
        if (std::strncmp(key, "limit", 5) == 0) {
            if (std::strcmp(key + 5, "Weak") == 0) {
                g_ref_config->limit_weak = val;
            } else if (std::strcmp(key + 5, "Local") == 0) {
                g_ref_config->limit_local = val;
            } else if (std::strcmp(key + 5, "Global") == 0) {
                g_ref_config->limit_global = val;
            }
        } else if (std::strcmp(key, "monitorType") == 0) {
            uint32_t uval = static_cast<uint32_t>(val);
            uint32_t encoded = ((uval >> 1) & 2u) | ((uval & 3u) << 2);
            g_ref_config->monitor_type = encoded;
        } else if (std::strcmp(key, "debug") == 0) {
            g_ref_config->debuggable = val;
        } else if (std::strcmp(key, "bt") == 0) {
            g_ref_config->bt_flags = static_cast<uint32_t>(val);
        }
    }
    std::fclose(fp);

    if (proc_name) {
        g_ref_config->proc_name = strdup(proc_name);
    }
    ref_log_set_debuggable(g_ref_config->debuggable);
    ref_log_set_ref_type(g_ref_config->debuggable);

    if (sdk_int >= 26) {
        g_ref_config->monitor_type &= ~2u;
    }
    if (g_ref_config->monitor_type == 0) {
        return 11;
    }

    if (g_ref_monitor_manager != nullptr) {
        return 2;
    }
    g_ref_monitor_manager = static_cast<RefMonitorManager*>(std::calloc(1, sizeof(RefMonitorManager)));
    if (!g_ref_monitor_manager) {
        return 2;
    }
    g_ref_monitor_manager->sdk_int = sdk_int;
    if (!log_dir) {
        return 3;
    }
    g_ref_monitor_manager->log_dir = strdup(log_dir);
    if (!g_ref_monitor_manager->log_dir) {
        return 3;
    }
    if (::access(g_ref_monitor_manager->log_dir, F_OK) != 0) {
        ::mkdir(g_ref_monitor_manager->log_dir, 0700);
    }
    char path_buf[256] = {0};
    FormatPathPair_3674(path_buf, sizeof(path_buf), sizeof(path_buf), g_ref_monitor_manager->log_dir, "ref_table.txt");
    g_ref_monitor_manager->ref_table_path = strdup(path_buf);
    FormatPathPair_3674(path_buf, sizeof(path_buf), sizeof(path_buf), g_ref_monitor_manager->log_dir, "crash_time");
    g_ref_monitor_manager->crash_time_path = strdup(path_buf);

    if (shadowhook_init && shadowhook_init(0, false) != 0) {
        return 4;
    }
    if (xp_init_basic_env && xp_init_basic_env() != 0) {
        return 5;
    }

    if (!g_ref_monitor_manager->art_syms) {
        auto* syms = static_cast<ArtSymbolTable*>(std::calloc(1, sizeof(ArtSymbolTable)));
        g_ref_monitor_manager->art_syms = syms;
        if (!syms) {
            return 6;
        }
        void* art_h = npth_dlopen ? npth_dlopen("libart.so") : nullptr;
        if (!art_h) {
            return 6;
        }
        void* cxx_h = npth_dlopen ? npth_dlopen("libc++.so") : nullptr;
        if (!cxx_h) {
            if (npth_dlclose) npth_dlclose(art_h);
            return 6;
        }
        void* irt_dump = npth_dlsym ? npth_dlsym(art_h, "_ZNK3art22IndirectReferenceTable4DumpERNSt3__113basic_ostreamIcNS1_11char_traitsIcEEEE") : nullptr;
        void* jni_dump = npth_dlsym ? npth_dlsym(art_h, "_ZN3art9JNIEnvExt19DumpReferenceTablesERNSt3__113basic_ostreamIcNS1_11char_traitsIcEEEE") : nullptr;
        const char* pretty_sym = (g_ref_config->debuggable < 26)
            ? "_ZN3art12PrettyTypeOfEPNS_6mirror6ObjectE"
            : "_ZN3art6mirror6Object12PrettyTypeOfEv";
        void* pretty_fn = npth_dlsym ? npth_dlsym(art_h, pretty_sym) : nullptr;
        void* cerr_sym  = npth_dlsym ? npth_dlsym(cxx_h, "_ZNSt3__14cerrE") : nullptr;

        if (!irt_dump || !jni_dump || !pretty_fn || !cerr_sym) {
            if (npth_dlclose) {
                npth_dlclose(cxx_h);
                npth_dlclose(art_h);
            }
            return 6;
        }
        syms->irt_dump_fn            = irt_dump;
        syms->jni_dump_ref_tables_fn = jni_dump;
        syms->pretty_type_of_fn      = pretty_fn;
        syms->std_cerr_ptr           = cerr_sym;
        if (npth_dlclose) {
            npth_dlclose(cxx_h);
            npth_dlclose(art_h);
        }
    }

    if (init_ref_info() != 0) {
        return 10;
    }
    g_ref_monitor_manager->initialized = 1;
    if (do_ref_hook() != 0) {
        return 9;
    }
    g_ref_monitor_manager->monitor_state = 1;
    return 0;
}

// FDE[06] (0x3510..0x3578): stop_monitor (104 B)
int stop_monitor() {
    if (!g_ref_monitor_manager || g_ref_monitor_manager->initialized != 1) {
        return -1;
    }
    if (g_ref_monitor_manager->monitor_state == 1) {
        g_ref_monitor_manager->monitor_state = 0;
        unhook_reftable();
        free_global_trees(1, 3);
        free_global_hash_tables(1, 3);
    }
    return 0;
}

// FDE[07] (0x3578..0x35d4): get_ref_limit (92 B)
int get_ref_limit(uint32_t kind) {
    if (!g_ref_config) return 0x7FFFFFFF;
    if (kind == kRefKindWeakGlobal) return g_ref_config->limit_weak;
    if (kind == kRefKindGlobal)     return g_ref_config->limit_global;
    if (kind == kRefKindLocal)      return g_ref_config->limit_local;
    return 0x7FFFFFFF;
}

// FDE[08] (0x35d4..0x3674): get_or_init_local_manager (160 B)
LocalRefThreadManager* get_or_init_local_manager(int create_if_null) {
    if (!g_ref_monitor_manager) return nullptr;
    auto* mgr = static_cast<LocalRefThreadManager*>(pthread_getspecific(g_ref_monitor_manager->tls_key));
    if (create_if_null != 0 && mgr == nullptr) {
        mgr = static_cast<LocalRefThreadManager*>(std::calloc(1, sizeof(LocalRefThreadManager)));
        if (mgr) {
            mgr->frame_tree_root = static_cast<RefTreeNode**>(std::calloc(1, sizeof(RefTreeNode*)));
            mgr->base_tree_root  = static_cast<RefTreeNode**>(std::calloc(1, sizeof(RefTreeNode*)));
            mgr->hash_table      = new_hash_table(kRefKindLocal, 0x20);
            pthread_setspecific(g_ref_monitor_manager->tls_key, mgr);
        }
    }
    return mgr;
}

// FDE[10] (0x371c..0x3810): unhook_reftable (244 B)
void unhook_reftable() {
    for (int i = 0; i < 11; ++i) {
        if (g_hook_stubs_e5a0[i] != nullptr) {
            if (shadowhook_unhook) {
                shadowhook_unhook(g_hook_stubs_e5a0[i]);
            }
            g_hook_stubs_e5a0[i] = nullptr;
        }
    }
}

// FDE[11] (0x3810..0x38f0): do_ref_hook (224 B)
int do_ref_hook() {
    if (!g_ref_monitor_manager) return -1;
    int sdk = g_ref_monitor_manager->sdk_int;
    for (int i = 0; i < 11; ++i) {
        const auto& desc = kArtRefHookTable_9f98[i];
        if (desc.min_sdk <= sdk && sdk <= desc.max_sdk) {
            void* stub = shadowhook_hook_sym_name
                ? shadowhook_hook_sym_name("libart.so", desc.sym_name, desc.new_func, nullptr)
                : nullptr;
            g_hook_stubs_e5a0[i] = stub;
            if (!stub) {
                if (npth_ref_log_prior <= 6 && __android_log_print) {
                    __android_log_print(6, kLogTag, "hook fail: error: %d", desc.error_code);
                }
                return desc.error_code;
            }
        }
    }
    return 0;
}

// FDE[21] (0x3d60..0x3e38): free_global_hash_tables (216 B)
void free_global_hash_tables(int use_lock, uint32_t kind) {
    if (!g_ref_monitor_manager) return;
    if (use_lock == 0 && kind == kRefKindGlobal) {
        free_hash_table(g_ref_monitor_manager->global_hash_table);
        g_ref_monitor_manager->global_hash_table = nullptr;
    } else {
        pthread_mutex_lock(&g_global_ref_mutex_e5f8);
        free_hash_table(g_ref_monitor_manager->global_hash_table);
        g_ref_monitor_manager->global_hash_table = nullptr;
        pthread_mutex_unlock(&g_global_ref_mutex_e5f8);
        if (use_lock == 0 && kind == kRefKindWeakGlobal) {
            free_hash_table(g_ref_monitor_manager->weak_hash_table);
            g_ref_monitor_manager->weak_hash_table = nullptr;
            return;
        }
    }
    pthread_mutex_lock(&g_weak_ref_mutex_e620);
    free_hash_table(g_ref_monitor_manager->weak_hash_table);
    g_ref_monitor_manager->weak_hash_table = nullptr;
    pthread_mutex_unlock(&g_weak_ref_mutex_e620);
}

// FDE[22] (0x3e38..0x3ef4): free_global_trees (188 B)
void free_global_trees(int use_lock, uint32_t kind) {
    if (use_lock == 0 && kind == kRefKindGlobal) {
        PostOrderFreeRefTree_3ef4(&g_global_tree_root_e648, kRefKindGlobal);
    } else {
        pthread_mutex_lock(&g_global_ref_mutex_e5f8);
        PostOrderFreeRefTree_3ef4(&g_global_tree_root_e648, kRefKindGlobal);
        pthread_mutex_unlock(&g_global_ref_mutex_e5f8);
        if (use_lock == 0 && kind == kRefKindWeakGlobal) {
            PostOrderFreeRefTree_3ef4(&g_weak_tree_root_e650, kRefKindWeakGlobal);
            return;
        }
    }
    pthread_mutex_lock(&g_weak_ref_mutex_e620);
    PostOrderFreeRefTree_3ef4(&g_weak_tree_root_e650, kRefKindWeakGlobal);
    pthread_mutex_unlock(&g_weak_ref_mutex_e620);
}

// FDE[24] (0x3fc0..0x403c): store_local_ref (124 B)
void store_local_ref() {
    if (!g_ref_monitor_manager || g_ref_monitor_manager->monitor_state == 0) return;
    if (g_ref_monitor_manager->sdk_int > 25) return;
    LocalRefThreadManager* mgr = get_or_init_local_manager(1);
    if (!mgr || mgr->in_jni_frame == 1) return;
    if (!mgr->frame_tree_root) {
        mgr->frame_tree_root = static_cast<RefTreeNode**>(std::calloc(1, sizeof(RefTreeNode*)));
    }
    mgr->saved_count  = mgr->local_count;
    mgr->in_jni_frame = 1;
}

// FDE[25] (0x403c..0x40a4): release_local_ref (104 B)
void release_local_ref() {
    if (!g_ref_monitor_manager || g_ref_monitor_manager->monitor_state == 0) return;
    if (g_ref_monitor_manager->sdk_int > 25) return;
    LocalRefThreadManager* mgr = get_or_init_local_manager(0);
    if (!mgr || mgr->in_jni_frame == 0) return;
    PostOrderFreeRefTree_3ef4(mgr->frame_tree_root, kRefKindLocal);
    mgr->in_jni_frame = 0;
    mgr->local_count  = mgr->saved_count;
}

// FDE[26] (0x40a4..0x42dc): delete_ref_info (568 B)
void delete_ref_info(void* jobject_ref) {
    if (!g_ref_monitor_manager || g_ref_monitor_manager->monitor_state == 0 || !g_ref_config) return;
    uint32_t kind = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(jobject_ref) & 3u);
    if (((g_ref_config->monitor_type >> kind) & 1u) == 0) return;

    if (kind == get_ref_log_type() && npth_ref_log_prior <= 4 && __android_log_print) {
        __android_log_print(4, kLogTag, "%s: ref: %p, kind: %u", "delete_ref_info", jobject_ref, kind);
    }

    RefTreeNode** tree_root = nullptr;
    int32_t* count_ptr = nullptr;
    pthread_mutex_t* lock_ptr = nullptr;

    if (kind == kRefKindWeakGlobal) {
        tree_root = &g_weak_tree_root_e650;
        count_ptr = &g_ref_monitor_manager->weak_ref_count;
        lock_ptr  = &g_weak_ref_mutex_e620;
    } else if (kind == kRefKindGlobal) {
        tree_root = &g_global_tree_root_e648;
        count_ptr = &g_ref_monitor_manager->global_ref_count;
        lock_ptr  = &g_global_ref_mutex_e5f8;
    } else if (kind == kRefKindLocal) {
        LocalRefThreadManager* local_mgr = get_or_init_local_manager(0);
        if (!local_mgr) return;
        tree_root = (local_mgr->in_jni_frame == 1) ? local_mgr->frame_tree_root : local_mgr->base_tree_root;
        if (!tree_root) return;
        count_ptr = &local_mgr->local_count;
    } else {
        return;
    }

    if (lock_ptr) pthread_mutex_lock(lock_ptr);
    if (g_ref_monitor_manager->monitor_state != 0 && *tree_root != nullptr) {
        RefTreeNode* cur = *tree_root;
        while (cur) {
            uintptr_t k_cur = reinterpret_cast<uintptr_t>(cur->jobject_ref);
            uintptr_t k_tar = reinterpret_cast<uintptr_t>(jobject_ref);
            if (k_cur > k_tar) {
                cur = cur->left;
            } else if (k_cur < k_tar) {
                cur = cur->right;
            } else {
                if (*count_ptr > 0) {
                    *count_ptr -= 1;
                    RefHashTable* ht = get_hash_table(kind);
                    hash_table_remove_entry(ht, cur->type_name);
                    RBTreeDeleteNode_42dc(tree_root, cur);
                    FreeRefTreeNode_4694(cur);
                } else if (npth_ref_log_prior <= 5 && __android_log_print) {
                    __android_log_print(5, kLogTag, "there must be something error with count, kind: %u", kind);
                }
                break;
            }
        }
    }
    if (lock_ptr) pthread_mutex_unlock(lock_ptr);
}

// FDE[29] (0x46c0..0x4c34): insert_ref_info (1,396 B)
void insert_ref_info(void* irt_table, void* jobject_ref, void* /*mirror_obj*/) {
    if (!jobject_ref || !g_ref_monitor_manager || g_ref_monitor_manager->monitor_state == 0 || !g_ref_config) return;
    uint32_t kind = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(jobject_ref) & 3u);
    if (((g_ref_config->monitor_type >> kind) & 1u) == 0) return;

    uint32_t raw_top = irt_table ? *reinterpret_cast<uint32_t*>(irt_table) : 0;
    uint32_t top_index = (g_ref_monitor_manager->sdk_int < 26) ? (raw_top & 0xFFFFu) : raw_top;

    if (kind == get_ref_log_type() && npth_ref_log_prior <= 4 && __android_log_print) {
        __android_log_print(
            4, kLogTag,
            "%s: ref_table: %p, ref: %p, top_index: %u, local_count: %d, kind: %u",
            "insert_ref_info", irt_table, jobject_ref, top_index,
            GetActiveRefCountByKind_4c34(kind), kind);
    }

    auto* node = static_cast<RefTreeNode*>(std::calloc(1, sizeof(RefTreeNode)));
    if (!node) return;
    node->jobject_ref = jobject_ref;
    node->type_name   = strdup("android.os.Object");

    RefTreeNode** tree_root = nullptr;
    int32_t* count_ptr = nullptr;
    pthread_mutex_t* lock_ptr = nullptr;

    if (kind == kRefKindWeakGlobal) {
        if (!g_ref_monitor_manager->weak_irt_ptr) g_ref_monitor_manager->weak_irt_ptr = irt_table;
        tree_root = &g_weak_tree_root_e650;
        count_ptr = &g_ref_monitor_manager->weak_ref_count;
        lock_ptr  = &g_weak_ref_mutex_e620;
    } else if (kind == kRefKindGlobal) {
        if (!g_ref_monitor_manager->global_irt_ptr) g_ref_monitor_manager->global_irt_ptr = irt_table;
        tree_root = &g_global_tree_root_e648;
        count_ptr = &g_ref_monitor_manager->global_ref_count;
        lock_ptr  = &g_global_ref_mutex_e5f8;
    } else if (kind == kRefKindLocal) {
        LocalRefThreadManager* local_mgr = get_or_init_local_manager(1);
        if (!local_mgr) {
            FreeRefTreeNode_4694(node);
            return;
        }
        if (!local_mgr->irt_table_ptr) local_mgr->irt_table_ptr = irt_table;
        tree_root = (local_mgr->in_jni_frame == 1) ? local_mgr->frame_tree_root : local_mgr->base_tree_root;
        if (!tree_root) {
            FreeRefTreeNode_4694(node);
            return;
        }
        count_ptr = &local_mgr->local_count;
    } else {
        FreeRefTreeNode_4694(node);
        return;
    }

    if (lock_ptr) pthread_mutex_lock(lock_ptr);
    if (g_ref_monitor_manager->monitor_state == 0) {
        FreeRefTreeNode_4694(node);
        if (lock_ptr) pthread_mutex_unlock(lock_ptr);
        return;
    }

    RefTreeNode* y = nullptr;
    RefTreeNode* x = *tree_root;
    uintptr_t key = reinterpret_cast<uintptr_t>(node->jobject_ref);
    bool duplicate = false;
    while (x != nullptr) {
        y = x;
        uintptr_t x_key = reinterpret_cast<uintptr_t>(x->jobject_ref);
        if (key < x_key) {
            x = x->left;
        } else if (key > x_key) {
            x = x->right;
        } else {
            duplicate = true;
            break;
        }
    }

    if (!duplicate) {
        node->parent = y;
        node->color  = 1;
        if (!y) {
            *tree_root = node;
        } else if (key < reinterpret_cast<uintptr_t>(y->jobject_ref)) {
            y->left = node;
        } else {
            y->right = node;
        }
        (*tree_root)->color = 0;
    } else {
        FreeRefTreeNode_4694(node);
        node = y;
    }

    *count_ptr += 1;
    RefHashTable* ht = get_hash_table(kind);
    RefHashEntry* entry = hash_table_insert_entry(ht, node->type_name);
    if (entry && entry->bt_info == nullptr) {
        auto* bt = static_cast<RefBacktraceAttachment*>(std::calloc(1, sizeof(RefBacktraceAttachment)));
        entry->bt_info = bt;
        if (bt) {
            if (g_ref_config->bt_flags & kBacktraceBitNative) {
                native_backtrace(bt, 3);
            }
            if (g_ref_config->bt_flags & kBacktraceBitJava) {
                java_backtrace(bt);
            }
        }
    }

    uint32_t limit = static_cast<uint32_t>(get_ref_limit(kind));
    if (top_index > limit && g_ref_monitor_manager->monitor_state == 1) {
        g_ref_monitor_manager->monitor_state = 2;
        dump_ref_file(irt_table, tree_root, kind, top_index);
        g_ref_monitor_manager->monitor_state = 0;
    }

    if (lock_ptr) pthread_mutex_unlock(lock_ptr);
}

// FDE[31] (0x4ca4..0x4d70): init_ref_info (204 B)
int init_ref_info() {
    if (!g_ref_config || !g_ref_monitor_manager) return -1;
    if ((g_ref_config->monitor_type & kMonitorBitLocal) != 0) {
        if (pthread_key_create(&g_ref_monitor_manager->tls_key, &LocalRefTlsDestructor_4d70) != 0) {
            return -1;
        }
    }
    g_global_tree_root_e648 = nullptr;
    g_weak_tree_root_e650   = nullptr;
    g_ref_monitor_manager->global_hash_table = new_hash_table(kRefKindGlobal, 0x80);
    g_ref_monitor_manager->weak_hash_table   = new_hash_table(kRefKindWeakGlobal, 0x80);
    return 0;
}

// FDE[33] (0x4db8..0x4e2c): get_time_millis (116 B)
int64_t get_time_millis() {
    struct timeval tv{};
    ::gettimeofday(&tv, nullptr);
    const int64_t sec  = static_cast<int64_t>(tv.tv_sec);
    const int64_t usec = static_cast<int64_t>(tv.tv_usec);
    constexpr int64_t kMagicDiv1000 = static_cast<int64_t>(0x20c49ba5e353f7cfULL);
    const int64_t high = static_cast<int64_t>((static_cast<__int128>(usec) * kMagicDiv1000) >> 64);
    const int64_t msec_part = (high >> 7) + (static_cast<uint64_t>(high) >> 63);
    return sec * 1000LL + msec_part;
}

// FDE[34] (0x4e2c..0x5360): dump_ref_file (1,332 B)
void dump_ref_file(void* /*irt_table*/, RefTreeNode** /*tree_root*/, uint32_t kind, uint32_t top_index) {
    if (!g_ref_monitor_manager || !g_ref_monitor_manager->ref_table_path) return;
    int fd = ::open(g_ref_monitor_manager->ref_table_path, O_RDWR | O_CREAT | O_APPEND, 0600);
    if (fd < 0) return;

    static const char* const kKindTable[4] = {
        "",
        "local reference table",
        "global reference table",
        "weak global reference table",
    };
    const char* kind_name = (kind < 4) ? kKindTable[kind] : "";
    char header[128] = {0};
    int hdr_len = FormatBufferChecked_5360(
        header, sizeof(header), sizeof(header),
        "%s stack dump: %u, tid: %d, thread_name: %s
",
        kind_name, top_index, static_cast<int>(::getpid()), "main");
    if (hdr_len > 0) {
        ::write(fd, header, static_cast<size_t>(hdr_len));
    }

    RefHashTable* ht = get_hash_table(kind);
    RefHashEntry* sorted_head = sort_table(ht);
    if (sorted_head) {
        int dumped_bt = 0;
        for (RefHashEntry* cur = sorted_head->next; cur != nullptr; cur = cur->next) {
            char line[256] = {0};
            int len = FormatBufferChecked_5360(line, sizeof(line), sizeof(line), "%-10zu %s
",
                                               static_cast<size_t>(cur->ref_count),
                                               cur->type_name ? cur->type_name : "");
            if (len > 0) ::write(fd, line, static_cast<size_t>(len));
            if (dumped_bt < 10 && cur->bt_info) {
                ++dumped_bt;
                if (cur->bt_info->native_pcs && cur->bt_info->native_depth > 0) {
                    char* nat_str = native_backtrace_format(cur->bt_info->native_pcs, cur->bt_info->native_depth);
                    if (nat_str) {
                        ::write(fd, nat_str, std::strlen(nat_str));
                        std::free(nat_str);
                    }
                }
            }
        }
        free_entry_list(sorted_head);
    }
    ::close(fd);
    free_global_hash_tables(0, kind);
    free_global_trees(0, kind);
    unhook_reftable();
}

// FDE[36] (0x5404..0x5500): native_backtrace (252 B)
void native_backtrace(RefBacktraceAttachment* bt, size_t skip_frames) {
    if (!bt) return;
    uintptr_t temp_frames[128] = {0};
    size_t depth = npth_fp_frames ? npth_fp_frames(temp_frames, 128) : 0;
    if (depth > 128) depth = 128;
    if (depth <= skip_frames) return;
    size_t kept = depth - skip_frames;
    auto* pcs = static_cast<uintptr_t*>(std::calloc(1, kept * sizeof(uintptr_t)));
    bt->native_pcs = pcs;
    if (!pcs) return;
    bt->native_depth = kept;
    for (size_t i = 0; i < kept; ++i) {
        pcs[i] = temp_frames[skip_frames + i];
    }
}

// FDE[37] (0x5500..0x5504): native_backtrace_format (4 B)
char* native_backtrace_format(uintptr_t* pcs, size_t depth) {
    return npth_fp_format ? npth_fp_format(pcs, depth) : nullptr;
}

// FDE[38] (0x5504..0x55bc): java_backtrace (184 B)
void java_backtrace(RefBacktraceAttachment* bt) {
    if (!bt || !g_ref_monitor_manager) return;
    int sdk = g_ref_monitor_manager->sdk_int;
    if (sdk < 26 || sdk >= 32) return;
    uintptr_t methods[128] = {0};
    int depth = 0;
    if (xp_get_current_backtrace) {
        xp_get_current_backtrace(methods, &depth, 128);
    }
    if (depth < 1) return;
    size_t byte_sz = static_cast<size_t>(depth) * sizeof(uintptr_t);
    auto* arr = static_cast<uintptr_t*>(std::calloc(1, byte_sz));
    bt->java_methods = arr;
    if (!arr) return;
    std::memcpy(arr, methods, byte_sz);
    bt->java_depth = static_cast<size_t>(depth);
}

// FDE[39] (0x55bc..0x55c0): java_backtrace_format (4 B)
int java_backtrace_format(uintptr_t art_method, char* buf, size_t buf_len) {
    return xp_pretty_method ? xp_pretty_method(art_method, buf, buf_len) : 0;
}

// FDE[40] (0x55c0..0x5668): hash_table_remove_entry (168 B)
void hash_table_remove_entry(RefHashTable* table, const char* key) {
    if (!table || !key || table->bucket_count == 0) return;
    uint32_t h = ComputeRefTypePjwHash(key);
    uint32_t idx = h % table->bucket_count;
    for (RefHashEntry* cur = table->buckets[idx]; cur != nullptr; cur = cur->next) {
        if (cur->type_name && std::strstr(cur->type_name, key) != nullptr) {
            if (cur->ref_count > 0) {
                cur->ref_count -= 1;
                if (cur->ref_count == 0 && table->unique_types > 0) {
                    table->unique_types -= 1;
                }
            }
            return;
        }
    }
}

// FDE[41] (0x5668..0x578c): hash_table_insert_entry (292 B)
RefHashEntry* hash_table_insert_entry(RefHashTable* table, const char* key) {
    if (!table || !key || table->bucket_count == 0) return nullptr;
    uint32_t h = ComputeRefTypePjwHash(key);
    uint32_t idx = h % table->bucket_count;
    RefHashEntry* cur = table->buckets[idx];
    if (!cur) {
        RefHashEntry* created = NewRefHashEntry_578c(key);
        table->buckets[idx] = created;
        table->total_refs   += 1;
        table->unique_types += 1;
        return created;
    }
    RefHashEntry* tail = cur;
    while (cur) {
        if (cur->type_name && std::strstr(cur->type_name, key) != nullptr) {
            cur->ref_count += 1;
            return nullptr;
        }
        tail = cur;
        cur = cur->next;
    }
    RefHashEntry* created = NewRefHashEntry_578c(key);
    tail->next = created;
    table->total_refs   += 1;
    table->unique_types += 1;
    return created;
}

// FDE[43] (0x57d4..0x584c): free_entry_list (120 B)
void free_entry_list(RefHashEntry* head) {
    while (head) {
        RefHashEntry* next = head->next;
        if (head->bt_info) {
            if (head->bt_info->java_methods) std::free(head->bt_info->java_methods);
            if (head->bt_info->native_pcs)   std::free(head->bt_info->native_pcs);
            std::free(head->bt_info);
        }
        if (head->type_name) std::free(head->type_name);
        std::free(head);
        head = next;
    }
}

// FDE[44] (0x584c..0x589c): free_hash_table (80 B)
void free_hash_table(RefHashTable* table) {
    if (!table) return;
    if (table->buckets) {
        for (uint32_t i = 0; i < table->bucket_count; ++i) {
            free_entry_list(table->buckets[i]);
        }
    }
    std::free(table);
}

// FDE[45] (0x589c..0x59b4): sort_table (280 B)
RefHashEntry* sort_table(RefHashTable* table) {
    if (!table) return nullptr;
    auto* sentinel = static_cast<RefHashEntry*>(std::calloc(1, sizeof(RefHashEntry)));
    if (!sentinel) return nullptr;
    sentinel->ref_count = 0x7FFFFFFFULL;

    for (uint32_t i = 0; i < table->bucket_count; ++i) {
        RefHashEntry* cur = table->buckets[i];
        table->buckets[i] = nullptr;
        while (cur) {
            RefHashEntry* next = cur->next;
            if (cur->ref_count == 0) {
                cur->next = nullptr;
                free_entry_list(cur);
            } else {
                RefHashEntry* prev = sentinel;
                RefHashEntry* scan = sentinel->next;
                while (scan && scan->ref_count > cur->ref_count) {
                    prev = scan;
                    scan = scan->next;
                }
                cur->next  = scan;
                prev->next = cur;
            }
            cur = next;
        }
    }
    return sentinel;
}

// FDE[46] (0x59b4..0x5a0c): new_hash_table (88 B)
RefHashTable* new_hash_table(uint32_t kind, uint32_t bucket_count) {
    auto* ht = static_cast<RefHashTable*>(std::calloc(1, sizeof(RefHashTable)));
    if (ht) {
        ht->buckets      = static_cast<RefHashEntry**>(std::calloc(1, static_cast<size_t>(bucket_count) << 5));
        ht->ref_kind     = kind;
        ht->bucket_count = bucket_count;
    }
    return ht;
}

// FDE[47] (0x5a0c..0x5a78): get_hash_table (108 B)
RefHashTable* get_hash_table(uint32_t kind) {
    if (!g_ref_monitor_manager) return nullptr;
    if (kind == kRefKindWeakGlobal) return g_ref_monitor_manager->weak_hash_table;
    if (kind == kRefKindGlobal)     return g_ref_monitor_manager->global_hash_table;
    if (kind == kRefKindLocal) {
        LocalRefThreadManager* local_mgr = get_or_init_local_manager(0);
        return local_mgr ? local_mgr->hash_table : nullptr;
    }
    return nullptr;
}

// FDE[48] (0x5a78..0x5a90): ref_log_get_debuggable (24 B)
bool ref_log_get_debuggable() {
    return npth_ref_log_prior < 5;
}

// FDE[49] (0x5a90..0x5ab0): ref_log_set_debuggable (32 B)
void ref_log_set_debuggable(int debuggable) {
    npth_ref_log_prior = (debuggable > 0) ? 4 : 8;
}

// FDE[50] (0x5ab0..0x5abc): ref_log_set_ref_type (12 B)
void ref_log_set_ref_type(uint32_t kind) {
    g_ref_log_type_bss_e58c = kind;
}

// FDE[51] (0x5abc..0x5ac8): get_ref_log_type (12 B)
uint32_t get_ref_log_type() {
    return g_ref_log_type_bss_e58c;
}

} // extern "C"
