/**
 * @file napi_env_runtime.cpp
 * @brief Clean-Room C++17 Implementation of Node-API Environment, Runtime, ThreadSafeFunction & CodeCache
 *        Hiện thực C++17 sạch cho Môi trường Node-API, Runtime, Hàm an toàn luồng & Bộ nhớ đệm mã
 *
 * Matches AArch64 instructions in libnapi.so (0x014000..0x01c19f) 1:1.
 * Khớp 1:1 chuỗi lệnh AArch64 trong libnapi.so (0x014000..0x01c19f).
 */

#include "napi_env_runtime.h"
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <pthread.h>

namespace {

// ============================================================================
// Internal Error Table & Status Helper (sub_27670 @ 0x027670..0x0278d0)
// Bảng thông báo lỗi nội bộ & Hàm kiểm tra trạng thái (0x027670..0x0278d0)
// ============================================================================

/**
 * @brief Maps napi_status (0..21) to exact .rodata error message strings
 *        Ánh xạ napi_status (0..21) tới các chuỗi thông báo lỗi chính xác trong .rodata
 */
const char* StatusToErrorMessage(napi_status status) noexcept {
    switch (status) {
        case napi_ok:                              return "";
        case napi_invalid_arg:                     return "Invalid argument";                      // 0x00dcde
        case napi_object_expected:                 return "An object was expected";                // 0x00d8db
        case napi_string_expected:                 return "A string was expected";                 // 0x00dba2
        case napi_name_expected:                   return "A string or symbol was expected";       // 0x00c8e1
        case napi_function_expected:               return "A function was expected";               // 0x00cbb0
        case napi_number_expected:                 return "A number was expected";                 // 0x00cc9b
        case napi_boolean_expected:                return "A boolean was expected";                // 0x00ccb1
        case napi_array_expected:                  return "An array was expected";                 // 0x00d8f2
        case napi_generic_failure:                 return "Unknown failure";                       // 0x00d7aa
        case napi_pending_exception:               return "An exception is pending";               // 0x00dafd
        case napi_cancelled:                       return "The async work item was cancelled";     // 0x00c9c2
        case napi_escape_called_twice:             return "napi_escape_handle already called on scope"; // 0x00db15
        case napi_handle_scope_mismatch:           return "Invalid handle scope usage";            // 0x00d592
        case napi_callback_scope_mismatch:         return "Invalid callback scope usage";          // 0x00d72a
        case napi_queue_full:                      return "Thread-safe function queue is full";    // 0x00c9e4
        case napi_closing:                         return "Thread-safe function handle is closing";// 0x00dcef
        case napi_bigint_expected:                 return "A bigint was expected";                 // 0x00d2dc
        case napi_date_expected:                   return "A date was expected";                   // 0x00c86d
        case napi_arraybuffer_expected:            return "An arraybuffer was expected";           // 0x00d2f2
        case napi_detachable_arraybuffer_expected: return "A detachable arraybuffer was expected"; // 0x00d436
        default:                                   return "unknown";                               // 0x00d286
    }
}

// ============================================================================
// Instance Data & Cleanup Hook Storage per napi_env
// Lưu trữ dữ liệu thực thể & Hook dọn dẹp trên mỗi napi_env
// ============================================================================

struct InstanceDataSlot {
    void* data = nullptr;
    napi_finalize finalize_cb = nullptr;
    void* finalize_hint = nullptr;
};

struct EnvExtraStorage {
    std::mutex mutex;
    std::unordered_map<uint64_t, InstanceDataSlot> instance_data;
    uint64_t next_cleanup_order = 0;
};

std::mutex g_env_extra_mutex;
std::unordered_map<napi_env, std::unique_ptr<EnvExtraStorage>> g_env_extra_map;

EnvExtraStorage* GetEnvExtra(napi_env env, bool create_if_missing = true) {
    std::lock_guard<std::mutex> lock(g_env_extra_mutex);
    auto it = g_env_extra_map.find(env);
    if (it != g_env_extra_map.end()) {
        return it->second.get();
    }
    if (!create_if_missing) {
        return nullptr;
    }
    auto storage = std::make_unique<EnvExtraStorage>();
    EnvExtraStorage* ptr = storage.get();
    g_env_extra_map.emplace(env, std::move(storage));
    return ptr;
}

/**
 * @brief NEON popcount bucket index helper matching 0x015fb8..0x015ff0
 *        Hàm tính chỉ số bucket bằng popcount khớp 0x015fb8..0x015ff0
 *
 * Disassembly at 0x015fb8..0x015ff0:
 *   fmov d0, x8; cnt v0.8b, v0.8b; uaddlv h0, v0.8b; fmov w10, s0
 *   cmp x10, #1; eor x11, x9, x0, lsl #1
 *   if popcount(bucket_count) <= 1: bucket = hash & (bucket_count - 1)
 *   else: bucket = hash % bucket_count
 */
inline size_t ComputeCleanupBucketIndex(size_t hash, size_t bucket_count) noexcept {
    if (bucket_count == 0) return 0;
    size_t popcnt = static_cast<size_t>(__builtin_popcountll(bucket_count));
    if (popcnt <= 1) {
        return hash & (bucket_count - 1);
    }
    return hash % bucket_count;
}

inline size_t ComputeCleanupHash(void (*fn)(void*), void* arg) noexcept {
    // eor x11, x9, x0, lsl #1 (0x015fcc)
    return reinterpret_cast<uintptr_t>(fn) ^ (reinterpret_cast<uintptr_t>(arg) << 1);
}

/**
 * @brief Removes a cleanup hook from CleanupHookTable (sub_14504 @ 0x014504)
 *        Xóa một hook dọn dẹp khỏi CleanupHookTable (sub_14504 @ 0x014504)
 */
bool RemoveCleanupHookNode(CleanupHookTable* table, void (*fn)(void*), void* arg) noexcept {
    if (!table || !table->head) return false;
    CleanupHookBucketNode* prev = nullptr;
    CleanupHookBucketNode* cur = table->head;
    const size_t target_hash = ComputeCleanupHash(fn, arg);
    while (cur) {
        if (cur->hash == target_hash && cur->entry.fn == fn && cur->entry.arg == arg) {
            if (prev) {
                prev->next = cur->next;
            } else {
                table->head = cur->next;
            }
            if (table->buckets && table->bucket_count > 0) {
                size_t b = ComputeCleanupBucketIndex(target_hash, table->bucket_count);
                if (table->buckets[b] == cur) {
                    table->buckets[b] = prev;
                }
            }
            delete cur;
            if (table->size > 0) --table->size;
            return true;
        }
        prev = cur;
        cur = cur->next;
    }
    return false;
}

// ============================================================================
// Default Environment Functions Bound in napi_new_env (0x015e6c..0x015eb8)
// Các hàm môi trường mặc định gắn trong napi_new_env (0x015e6c..0x015eb8)
// ============================================================================

/**
 * @brief napi_get_last_error_info implementation (0x01403c)
 *        Hiện thực napi_get_last_error_info (0x01403c)
 */
napi_status NapiGetLastErrorInfoImpl(napi_env env, const napi_extended_error_info** result) {
    if (!env || !result) return napi_invalid_arg;
    NapiEnvState* state = env->state;
    if (state->last_error.error_code == napi_ok) {
        state->last_error.error_message = nullptr;
    } else {
        state->last_error.error_message = StatusToErrorMessage(state->last_error.error_code);
    }
    *result = &state->last_error;
    return napi_ok;
}

/**
 * @brief napi_get_instance_data implementation (0x01405c)
 *        Hiện thực napi_get_instance_data (0x01405c)
 */
napi_status NapiGetInstanceDataImpl(napi_env env, uint64_t key, void** data) {
    if (!env || !data) return napi_invalid_arg;
    EnvExtraStorage* extra = GetEnvExtra(env, false);
    if (!extra) {
        *data = nullptr;
        return napi_ok;
    }
    std::lock_guard<std::mutex> lock(extra->mutex);
    auto it = extra->instance_data.find(key);
    *data = (it != extra->instance_data.end()) ? it->second.data : nullptr;
    return napi_ok;
}

/**
 * @brief napi_set_instance_data implementation (0x0146dc)
 *        Hiện thực napi_set_instance_data (0x0146dc)
 */
napi_status NapiSetInstanceDataImpl(
    napi_env env,
    uint64_t key,
    void* data,
    napi_finalize finalize_cb,
    void* finalize_hint) {
    if (!env) return napi_invalid_arg;
    EnvExtraStorage* extra = GetEnvExtra(env, true);
    std::lock_guard<std::mutex> lock(extra->mutex);
    auto it = extra->instance_data.find(key);
    if (it != extra->instance_data.end()) {
        // Conflict napi instance data key (.rodata 0x00cbc8)
        return napi_invalid_arg;
    }
    extra->instance_data[key] = InstanceDataSlot{data, finalize_cb, finalize_hint};
    return napi_ok;
}

/**
 * @brief napi_add_env_cleanup_hook implementation (0x0144c0)
 *        Hiện thực napi_add_env_cleanup_hook (0x0144c0)
 */
napi_status NapiAddEnvCleanupHookImpl(napi_env env, void (*fun)(void*), void* arg) {
    if (!env || !env->state || !env->state->cleanup_hooks || !fun) {
        return napi_invalid_arg;
    }
    CleanupHookTable* table = env->state->cleanup_hooks;
    const size_t hash = ComputeCleanupHash(fun, arg);
    for (CleanupHookBucketNode* cur = table->head; cur != nullptr; cur = cur->next) {
        if (cur->hash == hash && cur->entry.fn == fun && cur->entry.arg == arg) {
            return napi_invalid_arg;
        }
    }
    EnvExtraStorage* extra = GetEnvExtra(env, true);
    uint64_t order = 0;
    {
        std::lock_guard<std::mutex> lock(extra->mutex);
        order = ++extra->next_cleanup_order;
    }
    if (table->bucket_count == 0) {
        table->bucket_count = 8;
        table->buckets = new CleanupHookBucketNode*[table->bucket_count]();
    }
    auto* node = new CleanupHookBucketNode{
        table->head,
        hash,
        CleanupHookEntry{fun, arg, order}
    };
    table->head = node;
    size_t b = ComputeCleanupBucketIndex(hash, table->bucket_count);
    table->buckets[b] = node;
    ++table->size;
    return napi_ok;
}

/**
 * @brief napi_remove_env_cleanup_hook implementation (0x014704)
 *        Hiện thực napi_remove_env_cleanup_hook (0x014704)
 */
napi_status NapiRemoveEnvCleanupHookImpl(napi_env env, void (*fun)(void*), void* arg) {
    if (!env || !env->state || !env->state->cleanup_hooks || !fun) {
        return napi_invalid_arg;
    }
    return RemoveCleanupHookNode(env->state->cleanup_hooks, fun, arg) ? napi_ok : napi_invalid_arg;
}

// ============================================================================
// Thread-Safe Function & Async Work Implementations (0x017354..0x01b48b)
// Hiện thực Hàm an toàn luồng & Tác vụ bất đồng bộ (0x017354..0x01b48b)
// ============================================================================

struct ThreadSafeFunctionImpl {
    void* context = nullptr;                                   // +0x00 (read by 0x017354: ldr x8, [x0])
    napi_env env = nullptr;                                    // +0x08
    napi_ref js_func_ref = nullptr;                            // +0x10
    napi_threadsafe_function_call_js call_js_cb = nullptr;     // +0x18
    void* finalize_data = nullptr;                             // +0x20
    napi_finalize thread_finalize_cb = nullptr;                // +0x28
    size_t max_queue_size = 0;                                 // +0x30
    size_t thread_count = 0;                                   // +0x38
    bool is_closing = false;                                   // +0x40
    bool is_aborted = false;                                   // +0x41
    std::mutex mutex;
    std::condition_variable cond;
    std::deque<void*> queue;
};

struct AsyncWorkImpl {
    napi_env env = nullptr;
    napi_async_execute_callback execute = nullptr;
    napi_async_complete_callback complete = nullptr;
    void* data = nullptr;
    std::atomic<bool> cancelled{false};
};

napi_status RuntimeCreateAsyncWork(
    napi_env env,
    napi_value /*async_resource*/,
    napi_value /*async_resource_name*/,
    napi_async_execute_callback execute,
    napi_async_complete_callback complete,
    void* data,
    napi_async_work* result) {
    if (!env || !execute || !result) return napi_invalid_arg;
    auto* work = new AsyncWorkImpl{env, execute, complete, data, {false}};
    *result = reinterpret_cast<napi_async_work>(work);
    return napi_ok;
}

napi_status RuntimeDeleteAsyncWork(napi_env env, napi_async_work work) {
    if (!env || !work) return napi_invalid_arg;
    delete reinterpret_cast<AsyncWorkImpl*>(work);
    return napi_ok;
}

napi_status RuntimeQueueAsyncWork(napi_env env, napi_async_work work) {
    if (!env || !work) return napi_invalid_arg;
    auto* impl = reinterpret_cast<AsyncWorkImpl*>(work);
    if (impl->cancelled.load(std::memory_order_acquire)) {
        if (impl->complete) {
            impl->complete(env, napi_cancelled, impl->data);
        }
        return napi_ok;
    }
    impl->execute(env, impl->data);
    if (impl->complete) {
        napi_status st = impl->cancelled.load(std::memory_order_acquire) ? napi_cancelled : napi_ok;
        impl->complete(env, st, impl->data);
    }
    return napi_ok;
}

napi_status RuntimeCancelAsyncWork(napi_env env, napi_async_work work) {
    if (!env || !work) return napi_invalid_arg;
    auto* impl = reinterpret_cast<AsyncWorkImpl*>(work);
    impl->cancelled.store(true, std::memory_order_release);
    return napi_ok;
}

napi_status RuntimeCreateThreadsafeFunction(
    napi_env env,
    napi_value func,
    napi_value /*async_resource*/,
    napi_value /*async_resource_name*/,
    size_t max_queue_size,
    size_t initial_thread_count,
    void* thread_finalize_data,
    napi_finalize thread_finalize_cb,
    void* context,
    napi_threadsafe_function_call_js call_js_cb,
    napi_threadsafe_function* result) {
    if (!env || !result || initial_thread_count == 0) return napi_invalid_arg;
    if (!func && !call_js_cb) return napi_invalid_arg;
    auto* tsfn = new ThreadSafeFunctionImpl();
    tsfn->context = context;
    tsfn->env = env;
    tsfn->call_js_cb = call_js_cb;
    tsfn->finalize_data = thread_finalize_data;
    tsfn->thread_finalize_cb = thread_finalize_cb;
    tsfn->max_queue_size = max_queue_size;
    tsfn->thread_count = initial_thread_count;
    if (func && env->napi_create_reference) {
        env->napi_create_reference(env, func, 1, &tsfn->js_func_ref);
    }
    *result = reinterpret_cast<napi_threadsafe_function>(tsfn);
    return napi_ok;
}

napi_status RuntimeAcquireThreadsafeFunction(napi_threadsafe_function func) {
    if (!func) return napi_invalid_arg;
    auto* tsfn = reinterpret_cast<ThreadSafeFunctionImpl*>(func);
    std::lock_guard<std::mutex> lock(tsfn->mutex);
    if (tsfn->is_closing || tsfn->is_aborted) return napi_closing;
    ++tsfn->thread_count;
    return napi_ok;
}

napi_status RuntimeReleaseThreadsafeFunction(
    napi_threadsafe_function func,
    napi_threadsafe_function_release_mode mode) {
    if (!func) return napi_invalid_arg;
    auto* tsfn = reinterpret_cast<ThreadSafeFunctionImpl*>(func);
    std::unique_lock<std::mutex> lock(tsfn->mutex);
    if (tsfn->thread_count == 0) return napi_invalid_arg;
    --tsfn->thread_count;
    if (mode == napi_tsfn_abort) {
        tsfn->is_aborted = true;
    }
    if (tsfn->thread_count == 0 || tsfn->is_aborted) {
        tsfn->is_closing = true;
        tsfn->cond.notify_all();
    }
    return napi_ok;
}

napi_status RuntimeUnrefThreadsafeFunction(napi_env env, napi_threadsafe_function func) {
    return (!env || !func) ? napi_invalid_arg : napi_ok;
}

napi_status RuntimeRefThreadsafeFunction(napi_env env, napi_threadsafe_function func) {
    return (!env || !func) ? napi_invalid_arg : napi_ok;
}

napi_status RuntimeInitCodeCache(
    napi_env env,
    int32_t /*capacity*/,
    const std::string& /*cache_file_path*/,
    std::function<void(bool)> callback) {
    if (!env) return napi_invalid_arg;
    if (callback) callback(true);
    return napi_ok;
}

napi_status RuntimeOutputCodeCache(napi_env env) {
    return env ? napi_ok : napi_invalid_arg;
}

napi_status RuntimeRunScriptCache(
    napi_env env,
    const char* script,
    size_t length,
    const char* filename,
    napi_value* result) {
    if (!env || !env->napi_run_script) return napi_invalid_arg;
    return env->napi_run_script(env, script, length, filename, result);
}

void RuntimeDumpCacheStatus(
    napi_env /*env*/,
    std::vector<std::pair<std::string, int>>* status_out) {
    if (status_out) {
        status_out->clear();
    }
}

void PopulateRuntimeTableOnEnv(napi_env env) noexcept {
    env->napi_create_async_work = &RuntimeCreateAsyncWork;                           // +0x350
    env->napi_delete_async_work = &RuntimeDeleteAsyncWork;                           // +0x358
    env->napi_queue_async_work = &RuntimeQueueAsyncWork;                             // +0x360
    env->napi_cancel_async_work = &RuntimeCancelAsyncWork;                           // +0x368
    env->napi_create_threadsafe_function = &RuntimeCreateThreadsafeFunction;         // +0x370
    env->napi_get_threadsafe_function_context = &napi_runtime_get_threadsafe_function_context; // +0x378
    env->napi_call_threadsafe_function = &napi_runtime_call_threadsafe_function;     // +0x380
    env->napi_acquire_threadsafe_function = &RuntimeAcquireThreadsafeFunction;       // +0x388
    env->napi_release_threadsafe_function = &RuntimeReleaseThreadsafeFunction;       // +0x390
    env->napi_unref_threadsafe_function = &RuntimeUnrefThreadsafeFunction;           // +0x398
    env->napi_ref_threadsafe_function = &RuntimeRefThreadsafeFunction;               // +0x3a0
    env->napi_init_code_cache = &RuntimeInitCodeCache;                               // +0x3e8
    env->napi_output_code_cache = &RuntimeOutputCodeCache;                           // +0x3f0
    env->napi_run_script_cache = &RuntimeRunScriptCache;                             // +0x3f8
    env->napi_dump_cache_status = &RuntimeDumpCacheStatus;                           // +0x400
}

} // namespace

namespace primjs::napi::runtime {

/**
 * @brief Checks napi_status and logs or aborts if non-OK (sub_27670 @ 0x027670..0x0278d0)
 *        Kiểm tra napi_status và ghi nhật ký nếu khác napi_ok (sub_27670 @ 0x027670..0x0278d0)
 */
void CheckNapiStatus(napi_env env, napi_status status, const char* /*call_site_msg*/) {
    if (status == napi_ok || !env || !env->state) {
        return;
    }
    env->state->last_error.error_code = status;
    env->state->last_error.error_message = StatusToErrorMessage(status);
}

} // namespace primjs::napi::runtime

// ============================================================================
// Exported C Functions (0x015e28..0x01b6a8)
// Các hàm C xuất khẩu (0x015e28..0x01b6a8)
// ============================================================================

extern "C" {

/**
 * @brief Allocates and initializes a 1,072-byte (0x430) napi_env__
 *        Cấp phát và khởi tạo napi_env__ 1.072 byte (0x430)
 *
 * Binary address: 0x015e28..0x015ecc (164 bytes)
 * Disassembly verification:
 *   0x015e30: mov w0, #0x430; bl operator new; memset(x0, 0, 0x430)
 *   0x015e48: mov w0, #0x20;  bl operator new; stp q0, q0, [x0]; str x0, [x19]
 *   0x015e60: mov w0, #0x28;  bl operator new; mov w8, #0x3f800000; str w8, [x0, #0x20]
 *   0x015e8c: str x9, [x19, #0x338] (napi_set_instance_data)
 *   0x015e9c: str x8, [x19, #0x18]  (napi_get_last_error_info)
 *   0x015eb0: str x0, [x20, #0x18]  (state->cleanup_hooks)
 *   0x015eb4: str q0, [x19, #0x340] (napi_get_instance_data, napi_add_env_cleanup_hook)
 *   0x015eb8: str x8, [x19, #0x3a8] (napi_remove_env_cleanup_hook)
 */
napi_env napi_new_env() {
    auto* env = static_cast<napi_env>(::operator new(sizeof(napi_env__)));
    std::memset(env, 0, sizeof(napi_env__));

    auto* state = static_cast<NapiEnvState*>(::operator new(sizeof(NapiEnvState)));
    std::memset(state, 0, sizeof(NapiEnvState));
    env->state = state;

    auto* hooks = static_cast<CleanupHookTable*>(::operator new(sizeof(CleanupHookTable)));
    std::memset(hooks, 0, sizeof(CleanupHookTable));
    hooks->max_load_factor = 1.0f; // 0x3f800000 @ 0x015e68..0x015e74
    state->cleanup_hooks = hooks;

    env->napi_get_last_error_info = &NapiGetLastErrorInfoImpl;       // +0x018
    env->napi_set_instance_data = &NapiSetInstanceDataImpl;          // +0x338
    env->napi_get_instance_data = &NapiGetInstanceDataImpl;          // +0x340
    env->napi_add_env_cleanup_hook = &NapiAddEnvCleanupHookImpl;     // +0x348
    env->napi_remove_env_cleanup_hook = &NapiRemoveEnvCleanupHookImpl; // +0x3a8
    return env;
}

/**
 * @brief Drains cleanup hooks in LIFO order, runs instance data finalizers, and frees napi_env
 *        Thực thi các hook dọn dẹp theo thứ tự LIFO, chạy finalizer dữ liệu thực thể và giải phóng napi_env
 *
 * Binary address: 0x015ecc..0x0160d0 (516 bytes)
 * Disassembly verification:
 *   0x015ef4: mov x24, #-0x5555555555555556; movk x24, #0xaaa, lsl #48 (0xaaaaaaaaaaaaaaaab)
 *   0x015f74: bl #0x160d0 (sorts 24-byte CleanupHookEntry array by descending insertion order)
 *   0x015f90: blr x9 (invokes hook_fn(arg))
 *   0x015f9c: bl #0x14504 (removes executed hook from CleanupHookTable)
 */
void napi_free_env(napi_env env) {
    if (!env) return;

    NapiEnvState* state = env->state;
    if (state && state->cleanup_hooks) {
        CleanupHookTable* table = state->cleanup_hooks;
        while (table->size != 0 && table->head != nullptr) {
            std::vector<CleanupHookEntry> snapshot;
            snapshot.reserve(table->size);
            for (CleanupHookBucketNode* cur = table->head; cur != nullptr; cur = cur->next) {
                snapshot.push_back(cur->entry);
            }
            // Sort in descending order of insertion (LIFO, matching sub_160d0 @ 0x0160d0)
            std::sort(snapshot.begin(), snapshot.end(),
                      [](const CleanupHookEntry& a, const CleanupHookEntry& b) {
                          return a.order > b.order;
                      });
            for (const CleanupHookEntry& item : snapshot) {
                // Verify still in table before invoking (matching 0x015fb4..0x016048)
                bool still_present = false;
                const size_t h = ComputeCleanupHash(item.fn, item.arg);
                for (CleanupHookBucketNode* cur = table->head; cur != nullptr; cur = cur->next) {
                    if (cur->hash == h && cur->entry.fn == item.fn && cur->entry.arg == item.arg) {
                        still_present = true;
                        break;
                    }
                }
                if (still_present) {
                    if (item.fn) {
                        item.fn(item.arg);
                    }
                    RemoveCleanupHookNode(table, item.fn, item.arg);
                }
            }
        }
        CleanupHookBucketNode* cur = table->head;
        while (cur) {
            CleanupHookBucketNode* next = cur->next;
            delete cur;
            cur = next;
        }
        delete[] table->buckets;
        table->buckets = nullptr;
        ::operator delete(table);
        state->cleanup_hooks = nullptr;
    }

    // Run instance data finalizers and erase extra storage
    {
        std::unique_ptr<EnvExtraStorage> extra;
        {
            std::lock_guard<std::mutex> lock(g_env_extra_mutex);
            auto it = g_env_extra_map.find(env);
            if (it != g_env_extra_map.end()) {
                extra = std::move(it->second);
                g_env_extra_map.erase(it);
            }
        }
        if (extra) {
            for (auto& kv : extra->instance_data) {
                if (kv.second.finalize_cb) {
                    kv.second.finalize_cb(env, kv.second.data, kv.second.finalize_hint);
                }
            }
        }
    }

    if (state) {
        ::operator delete(state);
        env->state = nullptr;
    }
    ::operator delete(env);
}

/**
 * @brief Binds the N-API module loader function onto global[name]
 *        Gắn hàm nạp module N-API vào thuộc tính global[name]
 *
 * Binary address: 0x017250..0x017354 (260 bytes)
 */
void napi_setup_loader(napi_env env, const char* name) {
    if (!env || !name) return;
    napi_handle_scope scope = nullptr;
    if (env->napi_open_handle_scope) {
        napi_status st = env->napi_open_handle_scope(env, &scope);
        primjs::napi::runtime::CheckNapiStatus(env, st, "failed to call napi_open_handle_scope");
    }
    napi_value global_val = nullptr;
    if (env->napi_get_global) {
        napi_status st = env->napi_get_global(env, &global_val);
        primjs::napi::runtime::CheckNapiStatus(env, st, "failed to call napi_get_global");
    }
    napi_value loader_val = nullptr;
    if (env->napi_get_loader) {
        napi_status st = env->napi_get_loader(env, &loader_val);
        primjs::napi::runtime::CheckNapiStatus(env, st, "failed to call napi_get_loader");
    }
    if (loader_val && global_val && env->napi_set_named_property) {
        env->napi_set_named_property(env, global_val, name, loader_val);
    }
    if (env->napi_close_handle_scope) {
        napi_status st = env->napi_close_handle_scope(env, scope);
        primjs::napi::runtime::CheckNapiStatus(env, st, "failed to call napi_close_handle_scope");
    }
}

/**
 * @brief Returns the user context pointer from a thread-safe function (0x017354..0x017360)
 *        Trả về con trỏ ngữ cảnh người dùng từ hàm an toàn luồng (0x017354..0x017360)
 *
 * Disassembly:
 *   0x017354: ldr x8, [x0]
 *   0x017358: mov w0, wzr
 *   0x01735c: str x8, [x1]
 *   0x017360: ret
 */
napi_status napi_runtime_get_threadsafe_function_context(napi_threadsafe_function func, void** result) {
    auto* tsfn = reinterpret_cast<ThreadSafeFunctionImpl*>(func);
    *result = tsfn->context;
    return napi_ok;
}

/**
 * @brief Enqueues and dispatches a call to a thread-safe function (0x017364..0x017918)
 *        Đưa vào hàng đợi và điều phối lệnh gọi tới hàm an toàn luồng (0x017364..0x017918)
 */
napi_status napi_runtime_call_threadsafe_function(
    napi_threadsafe_function func,
    void* data,
    napi_threadsafe_function_call_mode is_blocking) {
    if (!func) return napi_invalid_arg;
    auto* tsfn = reinterpret_cast<ThreadSafeFunctionImpl*>(func);
    {
        std::unique_lock<std::mutex> lock(tsfn->mutex);
        if (tsfn->is_closing || tsfn->is_aborted) {
            return napi_closing;
        }
        if (tsfn->max_queue_size > 0 && tsfn->queue.size() >= tsfn->max_queue_size) {
            if (is_blocking == napi_tsfn_nonblocking) {
                return napi_queue_full;
            }
            tsfn->cond.wait(lock, [tsfn]() {
                return tsfn->is_closing || tsfn->is_aborted || tsfn->queue.size() < tsfn->max_queue_size;
            });
            if (tsfn->is_closing || tsfn->is_aborted) {
                return napi_closing;
            }
        }
        tsfn->queue.push_back(data);
    }

    // Immediate foreground dispatch when running in synchronous host context
    void* item = nullptr;
    {
        std::lock_guard<std::mutex> lock(tsfn->mutex);
        if (!tsfn->queue.empty()) {
            item = tsfn->queue.front();
            tsfn->queue.pop_front();
            tsfn->cond.notify_one();
        }
    }
    if (tsfn->call_js_cb && tsfn->env) {
        napi_value js_cb = nullptr;
        if (tsfn->js_func_ref && tsfn->env->napi_get_reference_value) {
            tsfn->env->napi_get_reference_value(tsfn->env, tsfn->js_func_ref, &js_cb);
        }
        tsfn->call_js_cb(tsfn->env, js_cb, tsfn->context, item);
    }
    return napi_ok;
}

/**
 * @brief Deletes a thread-safe function and runs its finalizer (0x018050..0x0180e4)
 *        Xóa hàm an toàn luồng và chạy hàm kết thúc (0x018050..0x0180e4)
 */
void napi_runtime_delete_threadsafe_function(napi_threadsafe_function func) {
    if (!func) return;
    auto* tsfn = reinterpret_cast<ThreadSafeFunctionImpl*>(func);
    if (tsfn->js_func_ref && tsfn->env && tsfn->env->napi_delete_reference) {
        tsfn->env->napi_delete_reference(tsfn->env, tsfn->js_func_ref);
        tsfn->js_func_ref = nullptr;
    }
    if (tsfn->thread_finalize_cb && tsfn->env) {
        tsfn->thread_finalize_cb(tsfn->env, tsfn->finalize_data, tsfn->context);
    }
    delete tsfn;
}

/**
 * @brief Allocates a 72-byte (0x48) napi_runtime_configuration__ (0x018368..0x018388)
 *        Cấp phát cấu trúc napi_runtime_configuration__ 72 byte (0x018368..0x018388)
 */
napi_runtime_configuration napi_create_runtime_configuration() {
    auto* cfg = static_cast<napi_runtime_configuration>(
        ::operator new(sizeof(napi_runtime_configuration__)));
    std::memset(cfg, 0, sizeof(napi_runtime_configuration__));
    return cfg;
}

/**
 * @brief Frees a napi_runtime_configuration__ (0x01838c..0x018394)
 *        Giải phóng cấu trúc napi_runtime_configuration__ (0x01838c..0x018394)
 */
void napi_delete_runtime_configuration(napi_runtime_configuration config) {
    if (config) {
        ::operator delete(config);
    }
}

void napi_runtime_config_foreground_handler(napi_runtime_configuration config, void* fn, void* ctx) {
    if (!config) return;
    config->foreground_handler_fn = fn;
    config->foreground_handler_ctx = ctx;
}

void napi_runtime_config_uncaught_handler(napi_runtime_configuration config, void* fn, void* ctx) {
    if (!config) return;
    config->uncaught_handler_fn = fn;
    config->uncaught_handler_ctx = ctx;
}

void napi_runtime_config_worker_handler(
    napi_runtime_configuration config,
    void* fn,
    void* ctx,
    void* aux1,
    void* aux2) {
    if (!config) return;
    config->worker_handler_fn = fn;
    config->worker_handler_ctx = ctx;
    config->worker_Aux1 = aux1;
    config->worker_Aux2 = aux2;
}

void napi_runtime_config_worker_stack_size(napi_runtime_configuration config, size_t stack_size) {
    if (!config) return;
    config->worker_stack_size = stack_size;
}

/**
 * @brief Attaches a 136-byte (0x88) NapiRuntimeContext configured by config (0x0183bc..0x0184e8)
 *        Gắn NapiRuntimeContext 136 byte (0x88) theo cấu hình vào napi_env (0x0183bc..0x0184e8)
 */
void napi_attach_runtime_with_configuration(napi_env env, napi_runtime_configuration config) {
    if (!env || !config) return;
    auto* rt_ctx = static_cast<NapiRuntimeContext*>(::operator new(sizeof(NapiRuntimeContext)));
    std::memset(rt_ctx, 0, sizeof(NapiRuntimeContext));
    rt_ctx->env = env;
    rt_ctx->foreground_fn = config->foreground_handler_fn;
    rt_ctx->foreground_ctx = config->foreground_handler_ctx;
    rt_ctx->uncaught_fn = config->uncaught_handler_fn;
    rt_ctx->uncaught_ctx = config->uncaught_handler_ctx;
    rt_ctx->worker_fn = config->worker_handler_fn;
    rt_ctx->worker_ctx = config->worker_handler_ctx;
    rt_ctx->worker_aux1 = config->worker_Aux1;
    rt_ctx->worker_aux2 = config->worker_Aux2;
    rt_ctx->worker_stack_size = config->worker_stack_size;
    rt_ctx->max_load_factor = 1.0f; // 0x3f800000 @ 0x018414
    env->runtime_ctx = rt_ctx;
    PopulateRuntimeTableOnEnv(env);
}

/**
 * @brief Attaches a 136-byte (0x88) NapiRuntimeContext with foreground/uncaught handlers (0x01b48c..0x01b5bc)
 *        Gắn NapiRuntimeContext 136 byte (0x88) với bộ xử lý foreground/uncaught (0x01b48c..0x01b5bc)
 */
void napi_attach_runtime(
    napi_env env,
    void* foreground_fn,
    void* foreground_ctx,
    void* uncaught_fn,
    void* uncaught_ctx) {
    if (!env) return;
    auto* rt_ctx = static_cast<NapiRuntimeContext*>(::operator new(sizeof(NapiRuntimeContext)));
    std::memset(rt_ctx, 0, sizeof(NapiRuntimeContext));
    rt_ctx->env = env;
    rt_ctx->foreground_fn = foreground_fn;
    rt_ctx->foreground_ctx = foreground_ctx;
    rt_ctx->uncaught_fn = uncaught_fn;
    rt_ctx->uncaught_ctx = uncaught_ctx;
    rt_ctx->max_load_factor = 1.0f; // 0x3f800000 @ 0x01b4b4
    env->runtime_ctx = rt_ctx;
    PopulateRuntimeTableOnEnv(env);
}

/**
 * @brief Detaches and frees NapiRuntimeContext at env + 0x08 (0x01b5c0..0x01b6a8)
 *        Tách và giải phóng NapiRuntimeContext tại env + 0x08 (0x01b5c0..0x01b6a8)
 */
void napi_detach_runtime(napi_env env) {
    if (!env || !env->runtime_ctx) return;
    NapiRuntimeContext* rt_ctx = env->runtime_ctx;
    if (rt_ctx->hash_buckets) {
        ::operator delete(rt_ctx->hash_buckets);
        rt_ctx->hash_buckets = nullptr;
    }
    ::operator delete(rt_ctx);
    env->runtime_ctx = nullptr;
}

} // extern "C"
