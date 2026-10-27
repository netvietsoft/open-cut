/**
 * @file napi_types.h
 * @brief Clean-Room C++17 Type Definitions & Binary ABI Layouts for libnapi.so
 *        Định nghĩa kiểu dữ liệu C++17 & bố cục ABI nhị phân cho libnapi.so
 *
 * Binary Metadata / Siêu dữ liệu nhị phân:
 *   - File: SOURCE/apktool-res/lib/arm64-v8a/libnapi.so
 *   - Size: 247,904 bytes (0x3c860)
 *   - SHA-256: fb3a870c14315fcc8976c7edd2653ad80ef3ab96ceb534f0d6354aa91e82764c
 *   - Architecture: AArch64 (ARM64-v8a), Little-Endian, LP64 ABI
 *   - .text: 0x014000..0x037070 (143,472 bytes)
 *   - .rodata: 0x00c780..0x00e6af (7,983 bytes)
 *   - .data.rel.ro: 0x038000..0x0389d8 (2,520 bytes)
 *   - .bss: 0x03c028..0x03c1d8 (432 bytes)
 *   - DT_NEEDED: libdl.so, libquick.so, liblog.so, libm.so, libc++_shared.so, libc.so
 */

#pragma once

#include <atomic>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <functional>
#include <initializer_list>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

// Forward declarations for JNI and QuickJS/LepusNG types
// Khai báo trước cho các kiểu JNI và QuickJS/LepusNG
struct _JNIEnv;
struct _JavaVM;
class _jobject;
class _jclass;
class _jstring;
class _jarray;
class _jobjectArray;
class _jbyteArray;
class _jlongArray;
struct _jmethodID;

using JNIEnv = _JNIEnv;
using JavaVM = _JavaVM;
using jobject = _jobject*;
using jclass = _jclass*;
using jstring = _jstring*;
using jarray = _jarray*;
using jobjectArray = _jobjectArray*;
using jbyteArray = _jbyteArray*;
using jlongArray = _jlongArray*;
using jmethodID = _jmethodID*;
using jboolean = uint8_t;
using jbyte = int8_t;
using jchar = uint16_t;
using jshort = int16_t;
using jint = int32_t;
using jlong = int64_t;
using jfloat = float;
using jdouble = double;
using jsize = jint;

#ifndef JNI_VERSION_1_6
#define JNI_VERSION_1_6 0x00010006
#endif

struct LEPUSRuntime;
struct LEPUSContext;
using LEPUSValue = uint64_t;
using LEPUSAtom = uint32_t;
using LEPUSClassID = uint32_t;

// ============================================================================
// 1. C Node-API (N-API) Core Enumerations & Opaque Handles
//    Các kiểu liệt kê và con trỏ mờ cốt lõi của C Node-API (N-API)
// ============================================================================

struct napi_env__;
struct napi_value__;
struct napi_ref__;
struct napi_handle_scope__;
struct napi_escapable_handle_scope__;
struct napi_callback_info__;
struct napi_deferred__;
struct napi_async_work__;
struct napi_threadsafe_function__;
struct napi_context_scope__;
struct napi_error_scope__;
struct napi_class__;
struct napi_runtime_configuration__;

using napi_env = napi_env__*;
using napi_value = napi_value__*;
using napi_ref = napi_ref__*;
using napi_handle_scope = napi_handle_scope__*;
using napi_escapable_handle_scope = napi_escapable_handle_scope__*;
using napi_callback_info = napi_callback_info__*;
using napi_deferred = napi_deferred__*;
using napi_async_work = napi_async_work__*;
using napi_threadsafe_function = napi_threadsafe_function__*;
using napi_context_scope = napi_context_scope__*;
using napi_error_scope = napi_error_scope__*;
using napi_class = napi_class__*;
using napi_runtime_configuration = napi_runtime_configuration__*;

/**
 * @brief Node-API Status Codes (OBSERVED in sub_27670 @ 0x027670..0x0278d0)
 *        Mã trạng thái Node-API (Quan sát tại sub_27670 @ 0x027670..0x0278d0)
 */
enum napi_status : int32_t {
    napi_ok = 0,
    napi_invalid_arg = 1,
    napi_object_expected = 2,
    napi_string_expected = 3,
    napi_name_expected = 4,
    napi_function_expected = 5,
    napi_number_expected = 6,
    napi_boolean_expected = 7,
    napi_array_expected = 8,
    napi_generic_failure = 9,
    napi_pending_exception = 10,
    napi_cancelled = 11,
    napi_escape_called_twice = 12,
    napi_handle_scope_mismatch = 13,
    napi_callback_scope_mismatch = 14,
    napi_queue_full = 15,
    napi_closing = 16,
    napi_bigint_expected = 17,
    napi_date_expected = 18,
    napi_arraybuffer_expected = 19,
    napi_detachable_arraybuffer_expected = 20,
    napi_would_deadlock = 21,
};

/**
 * @brief JS Value Type Enumeration (napi_valuetype)
 *        Kiểu liệt kê loại giá trị JS (napi_valuetype)
 */
enum napi_valuetype : int32_t {
    napi_undefined = 0,
    napi_null = 1,
    napi_boolean = 2,
    napi_number = 3,
    napi_string = 4,
    napi_symbol = 5,
    napi_object = 6,
    napi_function = 7,
    napi_external = 8,
    napi_bigint = 9,
};

/**
 * @brief TypedArray Element Type Enumeration (OBSERVED in ElementSize @ 0x02afd0)
 *        Kiểu liệt kê phần tử TypedArray (Quan sát tại ElementSize @ 0x02afd0)
 *
 * Displacement table at .rodata 0x00c81b:
 *   [10, 10, 10, 6, 6, 0, 0, 0, 3, 3, 3]
 *   -> types 0..2: disp 10 -> 1 byte (int8, uint8, uint8_clamped)
 *   -> types 3..4: disp  6 -> 2 bytes (int16, uint16)
 *   -> types 5..7: disp  0 -> 4 bytes (int32, uint32, float32)
 *   -> types 8..10: disp 3 -> 8 bytes (float64, bigint64, biguint64)
 */
enum napi_typedarray_type : int32_t {
    napi_int8_array = 0,
    napi_uint8_array = 1,
    napi_uint8_clamped_array = 2,
    napi_int16_array = 3,
    napi_uint16_array = 4,
    napi_int32_array = 5,
    napi_uint32_array = 6,
    napi_float32_array = 7,
    napi_float64_array = 8,
    napi_bigint64_array = 9,
    napi_biguint64_array = 10,
};

/**
 * @brief Property Attributes Bitmask (napi_property_attributes)
 *        Mặt nạ bit thuộc tính (napi_property_attributes)
 */
enum napi_property_attributes : int32_t {
    napi_default = 0,
    napi_writable = 1 << 0,
    napi_enumerable = 1 << 1,
    napi_configurable = 1 << 2,
    napi_static = 1 << 10,
    napi_default_method = napi_writable | napi_configurable,
    napi_default_jsproperty = napi_writable | napi_enumerable | napi_configurable,
};

enum napi_key_collection_mode : int32_t {
    napi_key_include_prototypes = 0,
    napi_key_own_only = 1,
};

enum napi_key_filter : int32_t {
    napi_key_all_properties = 0,
    napi_key_writable = 1 << 0,
    napi_key_enumerable = 1 << 1,
    napi_key_configurable = 1 << 2,
    napi_key_skip_strings = 1 << 3,
    napi_key_skip_symbols = 1 << 4,
};

enum napi_key_conversion : int32_t {
    napi_key_keep_numbers = 0,
    napi_key_numbers_to_strings = 1,
};

enum napi_threadsafe_function_release_mode : int32_t {
    napi_tsfn_release = 0,
    napi_tsfn_abort = 1,
};

enum napi_threadsafe_function_call_mode : int32_t {
    napi_tsfn_nonblocking = 0,
    napi_tsfn_blocking = 1,
};

using napi_callback = napi_value (*)(napi_env env, napi_callback_info info);
using napi_finalize = void (*)(napi_env env, void* finalize_data, void* finalize_hint);
using napi_async_execute_callback = void (*)(napi_env env, void* data);
using napi_async_complete_callback = void (*)(napi_env env, napi_status status, void* data);
using napi_threadsafe_function_call_js = void (*)(napi_env env, napi_value js_callback, void* context, void* data);

struct napi_property_descriptor {
    const char* utf8name;
    napi_value name;
    napi_callback method;
    napi_callback getter;
    napi_callback setter;
    napi_value value;
    napi_property_attributes attributes;
    void* data;
};

struct napi_extended_error_info {
    const char* error_message;
    void* engine_reserved;
    uint32_t engine_error_code;
    napi_status error_code;
};

// ============================================================================
// 2. Exact Binary Layout of napi_env__ (sizeof = 0x430 = 1,072 bytes)
//    Bố cục nhị phân chính xác của napi_env__ (0x430 = 1.072 bytes @ 0x015e30)
// ============================================================================

/**
 * @brief Cleanup Hook Entry in CleanupHookTable (24 bytes @ 0x015f2c..0x015f58)
 *        Phần tử Hook dọn dẹp trong CleanupHookTable (24 bytes @ 0x015f2c..0x015f58)
 */
struct CleanupHookEntry {
    void (*fn)(void*);      // +0x00: Cleanup callback function / Hàm gọi lại dọn dẹp
    void* arg;              // +0x08: User argument / Đối số người dùng
    uint64_t order;         // +0x10: Monotonic insertion counter / Bộ đếm thứ tự chèn
};
static_assert(sizeof(CleanupHookEntry) == 0x18, "CleanupHookEntry must be 24 bytes");

/**
 * @brief Hash node in CleanupHookTable (0x28 = 40 bytes)
 *        Nút băm trong CleanupHookTable (0x28 = 40 bytes)
 */
struct CleanupHookBucketNode {
    CleanupHookBucketNode* next; // +0x00
    size_t hash;                 // +0x08: fn ^ (arg << 1) (eor x11, x9, x0, lsl #1 @ 0x015fcc)
    CleanupHookEntry entry;      // +0x10..+0x27
};
static_assert(sizeof(CleanupHookBucketNode) == 0x28, "CleanupHookBucketNode must be 40 bytes");

/**
 * @brief CleanupHookTable allocated in napi_new_env (sizeof = 0x28 = 40 bytes @ 0x015e60)
 *        Bảng băm CleanupHookTable cấp phát trong napi_new_env (0x28 = 40 bytes @ 0x015e60)
 */
struct CleanupHookTable {
    CleanupHookBucketNode** buckets; // +0x00
    size_t bucket_count;             // +0x08
    CleanupHookBucketNode* head;     // +0x10
    size_t size;                     // +0x18
    float max_load_factor;           // +0x20: 1.0f = 0x3f800000 @ 0x015e68..0x015e74
    uint32_t pad;                    // +0x24
};
static_assert(sizeof(CleanupHookTable) == 0x28, "CleanupHookTable must be 40 bytes");

/**
 * @brief Environment State allocated at env->state (sizeof = 0x20 = 32 bytes @ 0x015e48)
 *        Trạng thái môi trường cấp phát tại env->state (0x20 = 32 bytes @ 0x015e48)
 */
struct NapiEnvState {
    napi_extended_error_info last_error; // +0x00..+0x17 (24 bytes)
    CleanupHookTable* cleanup_hooks;     // +0x18 (stored at [x20, #0x18] @ 0x015eb0)
};
static_assert(sizeof(NapiEnvState) == 0x20, "NapiEnvState must be 32 bytes");

/**
 * @brief Runtime Configuration struct (sizeof = 0x48 = 72 bytes @ 0x018368)
 *        Cấu trúc cấu hình Runtime (sizeof = 0x48 = 72 bytes @ 0x018368)
 */
struct napi_runtime_configuration__ {
    void* foreground_handler_fn;    // +0x00 (napi_runtime_config_foreground_handler @ 0x018398)
    void* foreground_handler_ctx;   // +0x08
    void* uncaught_handler_fn;      // +0x10 (napi_runtime_config_uncaught_handler @ 0x0183a0)
    void* uncaught_handler_ctx;     // +0x18
    void* worker_handler_fn;        // +0x20 (napi_runtime_config_worker_handler @ 0x0183a8)
    void* worker_handler_ctx;       // +0x28
    void* worker_Aux1;              // +0x30
    void* worker_Aux2;              // +0x38
    size_t worker_stack_size;       // +0x40 (napi_runtime_config_worker_stack_size @ 0x0183b4)
};
static_assert(sizeof(napi_runtime_configuration__) == 0x48, "napi_runtime_configuration__ must be 72 bytes");

/**
 * @brief RuntimeContext attached at env + 0x08 (sizeof = 0x88 = 136 bytes @ 0x0183c8 / 0x01b49c)
 *        Ngữ cảnh Runtime gắn tại env + 0x08 (sizeof = 0x88 = 136 bytes @ 0x0183c8 / 0x01b49c)
 */
struct NapiRuntimeContext {
    void* code_cache_delegate;      // +0x00
    void* worker_thread_runner;     // +0x08
    napi_env env;                   // +0x10
    void* foreground_fn;            // +0x18
    void* foreground_ctx;           // +0x20
    void* uncaught_fn;              // +0x28
    void* uncaught_ctx;             // +0x30
    void* worker_fn;                // +0x38
    void* worker_ctx;               // +0x40
    void* worker_aux1;              // +0x48
    void* worker_aux2;              // +0x50
    size_t worker_stack_size;       // +0x58
    void** hash_buckets;            // +0x60
    size_t hash_bucket_count;       // +0x68
    void* hash_head;                // +0x70
    size_t hash_size;               // +0x78
    float max_load_factor;          // +0x80: 1.0f = 0x3f800000 @ 0x018414 / 0x01b4b4
    uint32_t reserved_pad;          // +0x84
};
static_assert(sizeof(NapiRuntimeContext) == 0x88, "NapiRuntimeContext must be 136 bytes");

/**
 * @brief Complete 1,072-byte (0x430) napi_env__ Dispatch Table Structure
 *        Cấu trúc bảng điều phối napi_env__ 1.072 byte (0x430) đầy đủ
 *
 * Verified at napi_new_env (0x015e28), napi_attach_runtime (0x01b48c),
 * and napi_attach_quickjs (0x01c1a0..0x01c8b4).
 */
struct napi_env__ {
    NapiEnvState* state;                    // +0x000: Internal error & cleanup state
    NapiRuntimeContext* runtime_ctx;        // +0x008: Attached runtime context (0x88 B)
    void* ctx_impl;                         // +0x010: Attached engine context (qjsimpl::Context* 0x450 B)
    // Function pointer dispatch table (+0x018..+0x428 = 132 pointers):
    napi_status (*napi_get_last_error_info)(napi_env, const napi_extended_error_info**); // +0x018
    napi_status (*napi_get_undefined)(napi_env, napi_value*);                            // +0x020
    napi_status (*napi_get_null)(napi_env, napi_value*);                                 // +0x028
    napi_status (*napi_get_global)(napi_env, napi_value*);                               // +0x030
    napi_status (*napi_get_boolean)(napi_env, bool, napi_value*);                        // +0x038
    napi_status (*napi_create_object)(napi_env, napi_value*);                            // +0x040
    napi_status (*napi_create_array)(napi_env, napi_value*);                             // +0x048
    napi_status (*napi_create_array_with_length)(napi_env, size_t, napi_value*);         // +0x050
    napi_status (*napi_create_double)(napi_env, double, napi_value*);                    // +0x058
    napi_status (*napi_create_int32)(napi_env, int32_t, napi_value*);                    // +0x060
    napi_status (*napi_create_uint32)(napi_env, uint32_t, napi_value*);                  // +0x068
    napi_status (*napi_create_int64)(napi_env, int64_t, napi_value*);                    // +0x070
    napi_status (*napi_create_string_latin1)(napi_env, const char*, size_t, napi_value*);// +0x078
    napi_status (*napi_create_string_utf8)(napi_env, const char*, size_t, napi_value*);  // +0x080
    napi_status (*napi_create_string_utf16)(napi_env, const char16_t*, size_t, napi_value*); // +0x088
    napi_status (*napi_create_symbol)(napi_env, napi_value, napi_value*);                // +0x090
    napi_status (*napi_create_function)(napi_env, const char*, size_t, napi_callback, void*, napi_value*); // +0x098
    napi_status (*napi_create_error)(napi_env, napi_value, napi_value, napi_value*);     // +0x0a0
    napi_status (*napi_create_type_error)(napi_env, napi_value, napi_value, napi_value*);// +0x0a8
    napi_status (*napi_create_range_error)(napi_env, napi_value, napi_value, napi_value*);// +0x0b0
    napi_status (*napi_typeof)(napi_env, napi_value, napi_valuetype*);                   // +0x0b8
    napi_status (*napi_get_value_double)(napi_env, napi_value, double*);                 // +0x0c0
    napi_status (*napi_get_value_int32)(napi_env, napi_value, int32_t*);                 // +0x0c8
    napi_status (*napi_get_value_uint32)(napi_env, napi_value, uint32_t*);               // +0x0d0
    napi_status (*napi_get_value_int64)(napi_env, napi_value, int64_t*);                 // +0x0d8
    napi_status (*napi_get_value_bool)(napi_env, napi_value, bool*);                     // +0x0e0
    napi_status (*napi_get_value_string_latin1)(napi_env, napi_value, char*, size_t, size_t*); // +0x0e8
    napi_status (*napi_get_value_string_utf8)(napi_env, napi_value, char*, size_t, size_t*);   // +0x0f0
    napi_status (*napi_get_value_string_utf16)(napi_env, napi_value, char16_t*, size_t, size_t*);// +0x0f8
    napi_status (*napi_coerce_to_bool)(napi_env, napi_value, napi_value*);               // +0x100
    napi_status (*napi_coerce_to_number)(napi_env, napi_value, napi_value*);             // +0x108
    napi_status (*napi_coerce_to_object)(napi_env, napi_value, napi_value*);             // +0x110
    napi_status (*napi_coerce_to_string)(napi_env, napi_value, napi_value*);             // +0x118
    napi_status (*napi_get_prototype)(napi_env, napi_value, napi_value*);                // +0x120
    napi_status (*napi_get_property_names)(napi_env, napi_value, napi_value*);           // +0x128
    napi_status (*napi_set_property)(napi_env, napi_value, napi_value, napi_value);      // +0x130
    napi_status (*napi_has_property)(napi_env, napi_value, napi_value, bool*);           // +0x138
    napi_status (*napi_get_property)(napi_env, napi_value, napi_value, napi_value*);     // +0x140
    napi_status (*napi_delete_property)(napi_env, napi_value, napi_value, bool*);        // +0x148
    napi_status (*napi_has_own_property)(napi_env, napi_value, napi_value, bool*);       // +0x150
    napi_status (*napi_set_named_property)(napi_env, napi_value, const char*, napi_value);// +0x158
    napi_status (*napi_has_named_property)(napi_env, napi_value, const char*, bool*);    // +0x160
    napi_status (*napi_get_named_property)(napi_env, napi_value, const char*, napi_value*);// +0x168
    napi_status (*napi_set_element)(napi_env, napi_value, uint32_t, napi_value);         // +0x170
    napi_status (*napi_has_element)(napi_env, napi_value, uint32_t, bool*);              // +0x178
    napi_status (*napi_get_element)(napi_env, napi_value, uint32_t, napi_value*);        // +0x180
    napi_status (*napi_delete_element)(napi_env, napi_value, uint32_t, bool*);           // +0x188
    napi_status (*napi_define_properties)(napi_env, napi_value, size_t, const napi_property_descriptor*); // +0x190
    napi_status (*napi_is_array)(napi_env, napi_value, bool*);                           // +0x198
    napi_status (*napi_get_array_length)(napi_env, napi_value, uint32_t*);               // +0x1a0
    napi_status (*napi_strict_equals)(napi_env, napi_value, napi_value, bool*);          // +0x1a8
    napi_status (*napi_call_function)(napi_env, napi_value, napi_value, size_t, const napi_value*, napi_value*); // +0x1b0
    napi_status (*napi_new_instance)(napi_env, napi_value, size_t, const napi_value*, napi_value*); // +0x1b8
    napi_status (*napi_instanceof)(napi_env, napi_value, napi_value, bool*);             // +0x1c0
    napi_status (*napi_get_cb_info)(napi_env, napi_callback_info, size_t*, napi_value*, napi_value*, void**); // +0x1c8
    napi_status (*napi_get_new_target)(napi_env, napi_callback_info, napi_value*);       // +0x1d0
    napi_status (*napi_define_class)(napi_env, const char*, size_t, napi_callback, void*, size_t, const napi_property_descriptor*, napi_class*); // +0x1d8
    napi_status (*napi_wrap)(napi_env, napi_value, void*, napi_finalize, void*, napi_ref*); // +0x1e0
    napi_status (*napi_unwrap)(napi_env, napi_value, void**);                            // +0x1e8
    napi_status (*napi_remove_wrap)(napi_env, napi_value, void**);                       // +0x1f0
    napi_status (*napi_create_external)(napi_env, void*, napi_finalize, void*, napi_value*); // +0x1f8
    napi_status (*napi_get_value_external)(napi_env, napi_value, void**);                // +0x200
    napi_status (*napi_create_reference)(napi_env, napi_value, uint32_t, napi_ref*);     // +0x208
    napi_status (*napi_delete_reference)(napi_env, napi_ref);                            // +0x210
    napi_status (*napi_reference_ref)(napi_env, napi_ref, uint32_t*);                    // +0x218
    napi_status (*napi_reference_unref)(napi_env, napi_ref, uint32_t*);                  // +0x220
    napi_status (*napi_get_reference_value)(napi_env, napi_ref, napi_value*);            // +0x228
    napi_status (*napi_open_handle_scope)(napi_env, napi_handle_scope*);                 // +0x240 (0x230..0x238 reserved)
    void* reserved_0x230;                                                                // +0x230
    napi_status (*napi_open_escapable_handle_scope_slot)(napi_env, napi_escapable_handle_scope*); // +0x238
    napi_status (*napi_close_handle_scope)(napi_env, napi_handle_scope);                 // +0x248
    napi_status (*napi_open_escapable_handle_scope)(napi_env, napi_escapable_handle_scope*); // +0x250
    napi_status (*napi_close_escapable_handle_scope)(napi_env, napi_escapable_handle_scope); // +0x258
    napi_status (*napi_escape_handle)(napi_env, napi_escapable_handle_scope, napi_value, napi_value*); // +0x260
    napi_status (*napi_throw)(napi_env, napi_value);                                     // +0x268
    napi_status (*napi_throw_error)(napi_env, const char*, const char*);                 // +0x270
    napi_status (*napi_throw_type_error)(napi_env, const char*, const char*);            // +0x278
    napi_status (*napi_throw_range_error)(napi_env, const char*, const char*);           // +0x280
    napi_status (*napi_is_error)(napi_env, napi_value, bool*);                           // +0x288
    napi_status (*napi_is_exception_pending)(napi_env, bool*);                           // +0x290
    napi_status (*napi_get_and_clear_last_exception)(napi_env, napi_value*);             // +0x298
    napi_status (*napi_is_arraybuffer)(napi_env, napi_value, bool*);                     // +0x2a0
    napi_status (*napi_create_arraybuffer)(napi_env, size_t, void**, napi_value*);       // +0x2a8
    napi_status (*napi_create_external_arraybuffer)(napi_env, void*, size_t, napi_finalize, void*, napi_value*); // +0x2b0
    napi_status (*napi_get_arraybuffer_info)(napi_env, napi_value, void**, size_t*);     // +0x2b8
    napi_status (*napi_is_typedarray)(napi_env, napi_value, bool*);                      // +0x2c0
    napi_status (*napi_create_typedarray)(napi_env, napi_typedarray_type, size_t, napi_value, size_t, napi_value*); // +0x2c8
    napi_status (*napi_is_typedarray_of)(napi_env, napi_value, napi_typedarray_type, bool*); // +0x2d0
    napi_status (*napi_get_typedarray_info)(napi_env, napi_value, napi_typedarray_type*, size_t*, void**, napi_value*, size_t*); // +0x2d8
    napi_status (*napi_create_dataview)(napi_env, size_t, napi_value, size_t, napi_value*); // +0x2e0
    napi_status (*napi_is_dataview)(napi_env, napi_value, bool*);                        // +0x2e8
    napi_status (*napi_get_dataview_info)(napi_env, napi_value, size_t*, void**, napi_value*, size_t*); // +0x2f0
    napi_status (*napi_create_promise)(napi_env, napi_deferred*, napi_value*);           // +0x2f8
    napi_status (*napi_release_deferred)(napi_env, napi_deferred, napi_value, int32_t);  // +0x300
    napi_status (*napi_is_promise)(napi_env, napi_value, bool*);                         // +0x308
    napi_status (*napi_run_script)(napi_env, const char*, size_t, const char*, napi_value*); // +0x310
    napi_status (*napi_adjust_external_memory)(napi_env, int64_t, int64_t*);             // +0x318
    napi_status (*napi_AddFinalizer)(napi_env, napi_value, void*, napi_finalize, void*, napi_ref*); // +0x320
    napi_status (*napi_set_instance_data_ext)(napi_env, uint64_t, void*, napi_finalize, void*); // +0x328
    napi_status (*napi_get_instance_data_ext)(napi_env, uint64_t, void**);               // +0x330
    napi_status (*napi_set_instance_data)(napi_env, uint64_t, void*, napi_finalize, void*); // +0x338
    napi_status (*napi_get_instance_data)(napi_env, uint64_t, void**);                   // +0x340
    napi_status (*napi_add_env_cleanup_hook)(napi_env, void (*)(void*), void*);          // +0x348
    napi_status (*napi_create_async_work)(napi_env, napi_value, napi_value, napi_async_execute_callback, napi_async_complete_callback, void*, napi_async_work*); // +0x350
    napi_status (*napi_delete_async_work)(napi_env, napi_async_work);                    // +0x358
    napi_status (*napi_queue_async_work)(napi_env, napi_async_work);                     // +0x360
    napi_status (*napi_cancel_async_work)(napi_env, napi_async_work);                    // +0x368
    napi_status (*napi_create_threadsafe_function)(napi_env, napi_value, napi_value, napi_value, size_t, size_t, void*, napi_finalize, void*, napi_threadsafe_function_call_js, napi_threadsafe_function*); // +0x370
    napi_status (*napi_get_threadsafe_function_context)(napi_threadsafe_function, void**); // +0x378
    napi_status (*napi_call_threadsafe_function)(napi_threadsafe_function, void*, napi_threadsafe_function_call_mode); // +0x380
    napi_status (*napi_acquire_threadsafe_function)(napi_threadsafe_function);           // +0x388
    napi_status (*napi_release_threadsafe_function)(napi_threadsafe_function, napi_threadsafe_function_release_mode); // +0x390
    napi_status (*napi_unref_threadsafe_function)(napi_env, napi_threadsafe_function);   // +0x398
    napi_status (*napi_ref_threadsafe_function)(napi_env, napi_threadsafe_function);     // +0x3a0
    napi_status (*napi_remove_env_cleanup_hook)(napi_env, void (*)(void*), void*);       // +0x3a8
    napi_status (*napi_open_context_scope)(napi_env, napi_context_scope*);               // +0x3b0
    napi_status (*napi_close_context_scope)(napi_env, napi_context_scope);               // +0x3b8
    napi_status (*napi_open_error_scope)(napi_env, napi_error_scope*);                   // +0x3c0
    napi_status (*napi_close_error_scope)(napi_env, napi_error_scope);                   // +0x3c8
    napi_status (*napi_equals)(napi_env, napi_value, napi_value, bool*);                 // +0x3d0
    napi_status (*napi_get_unhandled_rejection_exception)(napi_env, napi_value*);        // +0x3d8
    napi_status (*napi_get_own_property_descriptor)(napi_env, napi_value, napi_value, napi_value*); // +0x3e0
    napi_status (*napi_init_code_cache)(napi_env, int32_t, const std::string&, std::function<void(bool)>); // +0x3e8
    napi_status (*napi_output_code_cache)(napi_env);                                     // +0x3f0
    napi_status (*napi_run_script_cache)(napi_env, const char*, size_t, const char*, napi_value*); // +0x3f8
    void (*napi_dump_cache_status)(napi_env, std::vector<std::pair<std::string, int>>*); // +0x400
    void* runtime_ext_0x408;                                                             // +0x408
    void* runtime_ext_0x410;                                                             // +0x410
    napi_status (*napi_class_get_function)(napi_env, napi_class, napi_value*);           // +0x418
    napi_status (*napi_release_class)(napi_env, napi_class);                             // +0x420
    napi_status (*napi_get_loader)(napi_env, napi_value*);                               // +0x428
};
static_assert(sizeof(napi_env__) == 0x430, "napi_env__ must be exactly 0x430 (1,072) bytes");

// ============================================================================
// 3. QuickJS / LepusNG N-API Backend Structures (qjsimpl)
//    Cấu trúc Backend N-API cho QuickJS / LepusNG (qjsimpl)
// ============================================================================

namespace qjsimpl {

/**
 * @brief Intrusive doubly-linked reference tracker list node
 *        Nút danh sách liên kết đôi theo dõi tham chiếu (RTTI: N7qjsimpl10RefTrackerE)
 */
class RefTracker {
public:
    virtual ~RefTracker() = default;
    virtual void Finalize(bool is_env_teardown) {}

    RefTracker* next_ = nullptr; // +0x08
    RefTracker* prev_ = nullptr; // +0x10

    void Link(RefTracker* list_head) noexcept {
        next_ = list_head->next_;
        prev_ = list_head;
        if (list_head->next_) {
            list_head->next_->prev_ = this;
        }
        list_head->next_ = this;
    }

    void Unlink() noexcept {
        if (prev_) prev_->next_ = next_;
        if (next_) next_->prev_ = prev_;
        next_ = nullptr;
        prev_ = nullptr;
    }
};

/**
 * @brief Cached QuickJS Atom wrapper (sizeof = 0x50 = 80 bytes @ 0x025060)
 *        Bộ bọc QuickJS Atom được lưu đệm (sizeof = 0x50 = 80 bytes @ 0x025060)
 */
struct QuickJSAtom {
    napi_env env = nullptr;           // +0x00
    LEPUSContext* ctx = nullptr;      // +0x08
    LEPUSAtom atom = 0;               // +0x10
    uint32_t flags = 0;               // +0x14
    uint64_t reserved[7] = {0};       // +0x18..+0x4f
};
static_assert(sizeof(QuickJSAtom) == 0x50, "QuickJSAtom must be 80 bytes");

/**
 * @brief HandleScopeWrapper (sizeof = 0x30 = 48 bytes @ 0x01c83c..0x01c884)
 *        Bộ bọc phạm vi Handle (sizeof = 0x30 = 48 bytes @ 0x01c83c..0x01c884)
 */
struct HandleScopeWrapper {
    struct ValueNode {
        LEPUSValue val;
        ValueNode* next;
    };
    napi_env env;                // +0x00
    LEPUSContext* ctx;           // +0x08
    bool is_gc_mode;             // +0x10
    uint8_t pad[7];              // +0x11..+0x17
    HandleScopeWrapper* prev;    // +0x18
    ValueNode* handle_head;      // +0x20
    void* gc_scope_or_fn;        // +0x28
};
static_assert(sizeof(HandleScopeWrapper) == 0x30, "HandleScopeWrapper must be 48 bytes");

/**
 * @brief qjsimpl::Context attached at env + 0x10 (sizeof = 0x450 = 1,104 bytes @ 0x01c6a8)
 *        Ngữ cảnh qjsimpl::Context gắn tại env + 0x10 (sizeof = 0x450 = 1.104 bytes @ 0x01c6a8)
 *
 * Verified from napi_attach_quickjs (0x01c6a8..0x01c898):
 *   +0x000: napi_env env
 *   +0x008: LEPUSRuntime* rt (from LEPUS_GetRuntime(ctx))
 *   +0x010: LEPUSContext* ctx
 *   +0x018: uint64_t prop_name_magic (2ULL from .rodata 0x00c7c0)
 *   +0x020: uint64_t prop_ctor_magic (18ULL from .rodata 0x00c7c8)
 *   +0x028..+0x040: RefTracker ref_tracker_head_ & finalizing_ref_tracker_
 *   +0x0c8..+0x437: 11 QuickJSAtom instances (11 * 0x50 = 0x370 bytes):
 *     [0] +0x0c8: "name"        (.rodata 0x00d0c4)
 *     [1] +0x118: "length"      (.rodata 0x00ca2d)
 *     [2] +0x168: "prototype"   (.rodata 0x00d5fc)
 *     [3] +0x1b8: "constructor" (.rodata 0x00d46c)
 *     [4] +0x208: "@#fin@#"     (.rodata 0x00dbd9)
 *     [5] +0x258: "message"     (.rodata 0x00ccc8)
 *     [6] +0x2a8: "code"        (.rodata 0x00d30e)
 *     [7] +0x2f8: "buffer"      (.rodata 0x00d5ad)
 *     [8] +0x348: "byteLength"  (.rodata 0x00d059)
 *     [9] +0x398: "byteOffset"  (.rodata 0x00d908)
 *    [10] +0x3e8: "@#ctor@#"    (.rodata 0x00ce69)
 *   +0x438: uint32_t open_handle_scopes (initialized to 1 @ 0x01c828)
 *   +0x440: HandleScopeWrapper* current_scope
 *   +0x448: bool is_gc_mode (LEPUS_IsGCModeRT(rt) & 1 @ 0x01c840)
 */
struct Context {
    napi_env env;                        // +0x000
    LEPUSRuntime* rt;                    // +0x008
    LEPUSContext* ctx;                   // +0x010
    uint64_t prop_name_magic;            // +0x018 (2ULL)
    uint64_t prop_ctor_magic;            // +0x020 (18ULL)
    uint64_t tracker_vtable_1;           // +0x028
    uint64_t tracker_next_1;             // +0x030
    uint64_t tracker_prev_1;             // +0x038
    uint64_t tracker_vtable_2;           // +0x040
    uint8_t tracker_state[0x20];         // +0x048..+0x067
    uint64_t pending_exception;          // +0x068
    bool has_exception;                  // +0x070
    uint8_t pad_0x071[0x0f];             // +0x071..+0x07f
    uint8_t instance_map_storage[0x40];  // +0x080..+0x0bf
    uint32_t wrapper_class_id;           // +0x0c0
    uint32_t pad_0x0c4;                  // +0x0c4
    QuickJSAtom atom_name;               // +0x0c8
    QuickJSAtom atom_length;             // +0x118
    QuickJSAtom atom_prototype;          // +0x168
    QuickJSAtom atom_constructor;        // +0x1b8
    QuickJSAtom atom_fin_magic;          // +0x208
    QuickJSAtom atom_message;            // +0x258
    QuickJSAtom atom_code;               // +0x2a8
    QuickJSAtom atom_buffer;             // +0x2f8
    QuickJSAtom atom_byte_length;        // +0x348
    QuickJSAtom atom_byte_offset;        // +0x398
    QuickJSAtom atom_ctor_magic;         // +0x3e8
    uint32_t open_handle_scopes;         // +0x438
    uint32_t pad_0x43c;                  // +0x43c
    HandleScopeWrapper* root_scope;      // +0x440
    bool is_gc_mode;                     // +0x448
    uint8_t tail_pad[7];                 // +0x449..+0x44f
};
static_assert(sizeof(Context) == 0x450, "qjsimpl::Context must be 0x450 (1,104) bytes");

} // namespace qjsimpl

/**
 * @brief Node-API Module Descriptor for QuickJS Registry (0x027568..0x027600)
 *        Cấu trúc mô tả Module Node-API cho Sổ đăng ký QuickJS (0x027568..0x027600)
 */
struct napi_module_qjs {
    int32_t nm_version;                  // +0x00
    uint32_t nm_flags;                   // +0x04
    const char* nm_filename;             // +0x08
    napi_value (*nm_register_func)(napi_env, napi_value); // +0x10
    const char* nm_modname;              // +0x18 (compared via strcmp @ 0x0275d8..0x0275e0)
    napi_module_qjs* nm_link;            // +0x20 (next pointer in .bss 0x03c040 list @ 0x027590)
    void* reserved[4];                   // +0x28..+0x47
};
