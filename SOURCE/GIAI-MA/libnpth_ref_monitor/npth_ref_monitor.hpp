// ============================================================================
// File: npth_ref_monitor.hpp
// Library: libnpth_ref_monitor.so (28,040 bytes)
// SHA-256: 8d4e40740d2ff59cecf0b6fd84188d47cafbb676638b263a657847747ae340aa
// Task ID: TASK-178-RECONSTRUCTION-LIBNPTH-REF-MONITOR / TASK_SO_084_libnpth_ref_monitor
// Architecture: AArch64 (arm64-v8a) - ByteDance Npth JNI Reference Table Monitor
// Clean-Room C++17 Header with Bilingual English + Vietnamese Annotations
// ============================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <pthread.h>

namespace npth::ref_monitor {

enum RefKind : uint32_t {
    kRefKindIrtEntry           = 0, // .rodata 0x1f38 ("")
    kRefKindLocal              = 1, // .rodata 0x1f9e ("local reference table")
    kRefKindGlobal             = 2, // .rodata 0x226a ("global reference table")
    kRefKindWeakGlobal         = 3, // .rodata 0x1e40 ("weak global reference table")
};

enum MonitorBitFlags : uint32_t {
    kMonitorBitLocal           = (1u << 1), // 0x02 (Cleared if sdk_int >= 26 @ 0x3298..0x32a8)
    kMonitorBitGlobal          = (1u << 2), // 0x04
    kMonitorBitWeakGlobal      = (1u << 3), // 0x08
};

enum BacktraceBitFlags : uint32_t {
    kBacktraceBitNative        = (1u << 0), // 0x01: npth_fp_frames / npth_fp_format
    kBacktraceBitJava          = (1u << 1), // 0x02: xp_get_current_backtrace / xp_pretty_method
};

struct RefMonitorConfig {
    int32_t     debuggable;      // +0x00: parsed from "debug=" in ref_monitor.config (@ 0x310c)
    uint32_t    bt_flags;        // +0x04: parsed from "bt=" (bit 0 = native, bit 1 = java @ 0x31ac)
    int32_t     limit_global;    // +0x08: default 10000 (0x2710 via dup v0.2s @ 0x3030..0x3040), "limitGlobal=" (@ 0x320c)
    int32_t     limit_weak;      // +0x0c: default 10000 (0x2710 via dup v0.2s @ 0x3030..0x3040), "limitWeak=" (@ 0x3244)
    int32_t     limit_local;     // +0x10: default 5000 (0x1388 @ 0x3038..0x303c), "limitLocal=" (@ 0x3250)
    uint32_t    monitor_type;    // +0x14: parsed from "monitorType=" via ((v>>1)&2) | ((v&3)<<2) (@ 0x3228..0x3238)
    char*       proc_name;       // +0x18: strdup(process_name) (@ 0x3268..0x3270)
};
static_assert(sizeof(RefMonitorConfig) == 0x20, "RefMonitorConfig ABI must be 32 bytes");

struct ArtSymbolTable {
    void*       irt_dump_fn;                // +0x00: _ZNK3art22IndirectReferenceTable4DumpERNSt3__113basic_ostreamIcNS1_11char_traitsIcEEEE
    void*       jni_dump_ref_tables_fn;     // +0x08: _ZN3art9JNIEnvExt19DumpReferenceTablesERNSt3__113basic_ostreamIcNS1_11char_traitsIcEEEE
    void*       pretty_type_of_fn;          // +0x10: _ZN3art12PrettyTypeOfEPNS_6mirror6ObjectE (API < 26) or _ZN3art6mirror6Object12PrettyTypeOfEv (API >= 26)
    void*       std_cerr_ptr;               // +0x18: _ZNSt3__14cerrE from libc++.so
};
static_assert(sizeof(ArtSymbolTable) == 0x20, "ArtSymbolTable ABI must be 32 bytes");

struct RefTreeNode {
    RefTreeNode* left;           // +0x00
    RefTreeNode* right;          // +0x08
    RefTreeNode* parent;         // +0x10
    uint32_t     color;          // +0x18: 1 = RED, 0 = BLACK
    uint32_t     reserved_1c;    // +0x1c
    void*        jobject_ref;    // +0x20: jobject reference key
    char*        type_name;      // +0x28: heap C-string of mirror::Object::PrettyTypeOf
};
static_assert(sizeof(RefTreeNode) == 0x30, "RefTreeNode ABI must be 48 bytes");

struct RefBacktraceAttachment {
    uintptr_t*   java_methods;   // +0x00: ArtMethod* array from xp_get_current_backtrace (@ 0x5578)
    size_t       java_depth;     // +0x08: Java frame count (@ 0x558c)
    uintptr_t*   native_pcs;     // +0x10: PC array from npth_fp_frames (@ 0x5470)
    size_t       native_depth;   // +0x18: Native frame count (@ 0x5484)
};
static_assert(sizeof(RefBacktraceAttachment) == 0x20, "RefBacktraceAttachment ABI must be 32 bytes");

struct RefHashEntry {
    RefHashEntry*           next;       // +0x00: collision chain or sorted linked-list next
    char*                   type_name;  // +0x08: strdup(type_name)
    RefBacktraceAttachment* bt_info;    // +0x10: backtrace captured on first insertion
    uint64_t                ref_count;  // +0x18: active reference count for this class
};
static_assert(sizeof(RefHashEntry) == 0x20, "RefHashEntry ABI must be 32 bytes");

struct RefHashTable {
    RefHashEntry** buckets;      // +0x00
    uint32_t       ref_kind;     // +0x08: 1 = Local, 2 = Global, 3 = WeakGlobal
    uint32_t       total_refs;   // +0x0c: incremented via NEON add v0.2s @ 0x5724
    uint32_t       unique_types; // +0x10: incremented via NEON add v0.2s @ 0x5724, decremented @ 0x5650
    uint32_t       bucket_count; // +0x14: 0x20 (32) for local (@ 0x3640), 0x80 (128) for global/weak (@ 0x4cf8)
};
static_assert(sizeof(RefHashTable) == 0x18, "RefHashTable ABI must be 24 bytes");

struct LocalRefThreadManager {
    RefTreeNode** base_tree_root;  // +0x00: calloc(1, 8) (@ 0x3634)
    RefTreeNode** frame_tree_root; // +0x08: calloc(1, 8) (@ 0x3624), freed on release_local_ref (@ 0x4080)
    int32_t       local_count;     // +0x10: active local ref count
    int32_t       saved_count;     // +0x14: count saved at store_local_ref (@ 0x402c)
    int32_t       in_jni_frame;    // +0x18: 1 if inside JniMethodStart..End frame
    int32_t       reserved_1c;     // +0x1c
    RefHashTable* hash_table;      // +0x20: new_hash_table(1, 0x20) (@ 0x3644)
    void*         irt_table_ptr;   // +0x28: IndirectReferenceTable* for local refs
};
static_assert(sizeof(LocalRefThreadManager) == 0x30, "LocalRefThreadManager ABI must be 48 bytes");

struct RefMonitorManager {
    int32_t         sdk_int;            // +0x00: Android API level (>= 21)
    int32_t         monitor_state;      // +0x04: 0 = stopped, 1 = running, 2 = dumping
    int32_t         initialized;        // +0x08: 1 = initialized
    int32_t         reserved_0c;        // +0x0c
    int32_t         weak_ref_count;     // +0x10: active weak global ref count
    int32_t         global_ref_count;   // +0x14: active global ref count
    char*           log_dir;            // +0x18: strdup(log_path)
    char*           ref_table_path;     // +0x20: "<log_dir>/ref_table.txt"
    char*           crash_time_path;    // +0x28: "<log_dir>/crash_time"
    pthread_key_t   tls_key;            // +0x30: pthread_key_create(&tls_key, tls_destructor_4d70)
    uint32_t        reserved_34;        // +0x34
    ArtSymbolTable* art_syms;           // +0x38: ArtSymbolTable* (0x20 B)
    void*           weak_irt_ptr;       // +0x40: IndirectReferenceTable* for weak global refs
    void*           global_irt_ptr;     // +0x48: IndirectReferenceTable* for global refs
    RefHashTable*   global_hash_table;  // +0x50: new_hash_table(2, 0x80)
    RefHashTable*   weak_hash_table;    // +0x58: new_hash_table(3, 0x80)
};
static_assert(sizeof(RefMonitorManager) == 0x60, "RefMonitorManager ABI must be 96 bytes");

struct RefHookDescriptor {
    int32_t     min_sdk;        // +0x00
    int32_t     max_sdk;        // +0x04
    const char* sym_name;       // +0x08
    void*       new_func;       // +0x10
    int32_t     error_code;     // +0x18
    int32_t     reserved_1c;    // +0x1c
};
static_assert(sizeof(RefHookDescriptor) == 0x20, "RefHookDescriptor ABI must be 32 bytes");

struct RefMonitorNativeInterface {
    int (*initialize)(int sdk_int, const char* proc_name, const char* log_dir, const char* config_dir);
    int (*stop)();
};

extern "C" {
    extern RefMonitorConfig*        g_ref_config;                       // .bss  0xe590 (8 B)
    extern RefMonitorManager*       g_ref_monitor_manager;              // .bss  0xe598 (8 B)
    extern RefMonitorNativeInterface ref_monitor_native_interface_func; // .data 0xe578 (16 B)
    extern int32_t                  npth_ref_log_prior;                 // .data 0xe588 (4 B)

    int so_initialize(int sdk_int, const char* proc_name, const char* log_dir, const char* config_dir); // 0x2fd0
    int stop_monitor();                                                 // 0x3510
    int get_ref_limit(uint32_t kind);                                   // 0x3578
    LocalRefThreadManager* get_or_init_local_manager(int create_if_null); // 0x35d4
    void unhook_reftable();                                             // 0x371c
    int do_ref_hook();                                                  // 0x3810
    void free_global_hash_tables(int skip_lock, uint32_t kind);         // 0x3d60
    void free_global_trees(int skip_lock, uint32_t kind);               // 0x3e38
    void store_local_ref();                                             // 0x3fc0
    void release_local_ref();                                           // 0x403c
    void delete_ref_info(void* jobject_ref);                            // 0x40a4
    void insert_ref_info(void* irt_table, void* jobject_ref, void* mirror_obj); // 0x46c0
    int init_ref_info();                                                // 0x4ca4
    int64_t get_time_millis();                                          // 0x4db8
    void dump_ref_file(void* irt_table, RefTreeNode** tree_root, uint32_t kind, uint32_t top_index); // 0x4e2c
    void native_backtrace(RefBacktraceAttachment* bt, size_t skip_frames); // 0x5404
    char* native_backtrace_format(uintptr_t* pcs, size_t depth);        // 0x5500
    void java_backtrace(RefBacktraceAttachment* bt);                    // 0x5504
    int java_backtrace_format(uintptr_t art_method, char* buf, size_t buf_len); // 0x55bc
    void hash_table_remove_entry(RefHashTable* table, const char* key); // 0x55c0
    RefHashEntry* hash_table_insert_entry(RefHashTable* table, const char* key); // 0x5668
    void free_entry_list(RefHashEntry* head);                           // 0x57d4
    void free_hash_table(RefHashTable* table);                          // 0x584c
    RefHashEntry* sort_table(RefHashTable* table);                      // 0x589c
    RefHashTable* new_hash_table(uint32_t kind, uint32_t bucket_count); // 0x59b4
    RefHashTable* get_hash_table(uint32_t kind);                        // 0x5a0c
    bool ref_log_get_debuggable();                                      // 0x5a78
    void ref_log_set_debuggable(int debuggable);                        // 0x5a90
    void ref_log_set_ref_type(uint32_t kind);                           // 0x5ab0
    uint32_t get_ref_log_type();                                        // 0x5abc
}

extern const uint8_t  kRodataSection_1e20[1584];
extern const uint8_t  kEhFrameHdrSection_2450[428];
extern const uint8_t  kEhFrameSection_2600[2432];
extern const uint32_t kTextSectionWords_2f80[2770];
extern const uint32_t kPltSectionWords_5ad0[304];
extern const uint8_t  kDataRelRoSection_9f90[360];
extern const uint8_t  kDataSection_e578[24];

bool VerifyBinarySectionsIntegrity() noexcept;
uint32_t ReadTextInstructionWord(uint32_t va) noexcept;

} // namespace npth::ref_monitor
