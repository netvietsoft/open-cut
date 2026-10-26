/**
 * @file godzilla_touphic_interface.cpp
 * @brief Implementation of ART, WebView, and JNI Entrypoints for libgodzilla-touphic.so
 *        Triển khai các phân hệ ART, WebView và Điểm nhập JNI cho libgodzilla-touphic.so
 *
 * Binary Target / Đích nhị phân:
 *   apktool-res/lib/arm64-v8a/libgodzilla-touphic.so (65,304 bytes, 27 exported functions [085..111])
 * Verification Scope / Phạm vi xác minh:
 *   - `VisitLocksOpt`: `0x007130..0x0072c0`
 *   - `DirectBufferOpt`: `0x0072c4..0x0076c0`
 *   - `ChromeSupportOpt`: `0x00892c..0x008e5c`
 *   - `JitCompileOpt`: `0x008e60..0x0093fc`
 *   - `SafeUffdGCOpt`: `0x00a2c4..0x00a884`
 *   - `WebviewChromiumOpt`: `0x00d3f4..0x00db48` & `0x00e5e8..0x00e810`
 */

#include "godzilla_touphic_interface.h"
#include "godzilla_touphic_core_infra.h"
#include "godzilla_touphic_gpu_opts.h"

#include <android/log.h>
#include <link.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

namespace bytedance {
namespace platform {
namespace godzilla {
namespace touphic {

namespace {

static constexpr const char* kLogTag    = "TOUPHIC";             // 0x0049f2
static constexpr const char* kUffdGcTag = "UFFDGC";              // 0x00401b
static constexpr const char* kWebviewTag = "WebviewChromiumOpt"; // 0x003f20

// ============================================================================
// SUBSYSTEM 1: VisitLocksOpt (.bss 0x0176d8, .text 0x007130..0x0072c0)
// ============================================================================
void (*g_visit_locks_orig_fn)(void*, void*, void*, bool) = nullptr;  // 0x0176d8

struct VisitLocksArgs {
    void* stack_visitor;  // +0x00
    void* callback;       // +0x08
    void* callback_arg;   // +0x10
    uint64_t unused_x3;   // +0x18
    uint64_t allow_long;  // +0x20
};

uint64_t visit_locks_trampoline(void* raw_args) {
    // 0x0071b8..0x0071db
    auto* args = static_cast<VisitLocksArgs*>(raw_args);
    g_visit_locks_orig_fn(args->stack_visitor, args->callback, args->callback_arg, args->allow_long != 0);
    return 0;
}

void visit_locks_wrapper(void* stack_visitor, void* callback, void* callback_arg, uint64_t x3, bool allow_long) {
    // 0x007130..0x0071b4
    VisitLocksArgs args{stack_visitor, callback, callback_arg, x3, allow_long ? 1ULL : 0ULL};
    TryExecuteTask task = {};
    task.magic = kTryExecuteMagic;
    task.target_fn = visit_locks_trampoline;
    int rc = safe_execute(&task, &args);
    __android_log_print(ANDROID_LOG_ERROR, kLogTag, "VisitLocksWrapper result %d", rc);
    shadowhook_pop_stack(__builtin_return_address(0));
}

// ============================================================================
// SUBSYSTEM 2: DirectBufferOpt (.bss 0x0176e0..0x0176f0, .text 0x0072c4..0x0076c0)
// ============================================================================
uint8_t g_direct_buf_enable_sigbus = 0;  // 0x0176e0
uint8_t g_direct_buf_enable_segv   = 0;  // 0x0176e1
void (*g_true_get_byte_array_orig)(JNIEnv*, jbyteArray, jint, jint, jbyte*)  = nullptr;  // 0x0176e8
void (*g_false_get_byte_array_orig)(JNIEnv*, jbyteArray, jint, jint, jbyte*) = nullptr;  // 0x0176f0

struct GetByteArrayRegionArgs {
    JNIEnv*    env;    // +0x00
    jbyteArray array;  // +0x08
    int64_t    start;  // +0x10
    int64_t    len;    // +0x18
    jbyte*     buf;    // +0x20
};

uint32_t get_byte_array_region_sig_callback(int* sig_ptr) {
    // 0x0072c4..0x00732c:
    // Checks *sig_ptr == 11 (SIGSEGV) && g_direct_buf_enable_segv, or *sig_ptr == 7 (SIGBUS) && g_direct_buf_enable_sigbus.
    // Returns 0x00aabbcc on match, or logs and returns 0x00112358.
    int signo = *sig_ptr;
    if (signo == SIGSEGV) {
        if (g_direct_buf_enable_segv != 0) {
            return kSignalBypassReturn;
        }
    } else if (signo == SIGBUS) {
        if (g_direct_buf_enable_sigbus != 0) {
            return kSignalBypassReturn;
        }
    }
    __android_log_print(ANDROID_LOG_ERROR, kLogTag, "GetByteArrayRegionCallback failed %d", signo);
    return kSignalPassThroughReturn;
}

uint64_t call_false_get_byte_array_trampoline(void* raw_args) {
    // 0x007664..0x007680
    auto* a = static_cast<GetByteArrayRegionArgs*>(raw_args);
    g_false_get_byte_array_orig(a->env, a->array, static_cast<jint>(a->start), static_cast<jint>(a->len), a->buf);
    return 0;
}

uint64_t call_true_get_byte_array_trampoline(void* raw_args) {
    // 0x007684..0x0076a0
    auto* a = static_cast<GetByteArrayRegionArgs*>(raw_args);
    g_true_get_byte_array_orig(a->env, a->array, static_cast<jint>(a->start), static_cast<jint>(a->len), a->buf);
    return 0;
}

void true_get_byte_array_region_proxy(JNIEnv* env, jbyteArray array, jint start, jint len, jbyte* buf) {
    // 0x007484..0x007570
    GetByteArrayRegionArgs args{env, array, start, len, buf};
    TryExecuteTask task = {};
    task.magic = kTryExecuteMagic;
    task.target_fn = call_true_get_byte_array_trampoline;
    task.sig_callback = get_byte_array_region_sig_callback;
    if (safe_execute(&task, &args) != 0) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "GetByteArrayRegion failed %d", 1);
        jclass io_ex_cls = env->FindClass("java/io/IOException");
        env->ThrowNew(io_ex_cls, "do GetByteArrayRegion error");
        env->DeleteLocalRef(io_ex_cls);
    }
    shadowhook_pop_stack(__builtin_return_address(0));
}

void false_get_byte_array_region_proxy(JNIEnv* env, jbyteArray array, jint start, jint len, jbyte* buf) {
    // 0x007574..0x007660
    GetByteArrayRegionArgs args{env, array, start, len, buf};
    TryExecuteTask task = {};
    task.magic = kTryExecuteMagic;
    task.target_fn = call_false_get_byte_array_trampoline;
    task.sig_callback = get_byte_array_region_sig_callback;
    if (safe_execute(&task, &args) != 0) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "GetByteArrayRegion failed %d", 1);
        jclass io_ex_cls = env->FindClass("java/io/IOException");
        env->ThrowNew(io_ex_cls, "do GetByteArrayRegion error");
        env->DeleteLocalRef(io_ex_cls);
    }
    shadowhook_pop_stack(__builtin_return_address(0));
}

// ============================================================================
// SUBSYSTEM 6: ChromeSupportOpt (.data 0x017600..0x017604, .bss 0x017750..0x01777c)
// ============================================================================
int32_t g_chrome_skip_error_count = 120;      // .data 0x017600 = 0x78
int32_t g_chrome_notify_remaining = -1;       // .data 0x017604 = -1
void (*g_draw_gl_30_orig)(int, void*, const void*)              = nullptr;  // .bss 0x017750
void (*g_draw_gl_31_orig)(int, void*, const void*, const void*) = nullptr;  // .bss 0x017758
int32_t g_chrome_cur_error_count  = 0;        // .bss 0x017760
uint8_t g_chrome_damage_webview   = 0;        // .bss 0x017764
sem_t   g_chrome_notify_sem       = {};       // .bss 0x017768
uint8_t g_chrome_need_gc          = 0;        // .bss 0x017778
int32_t g_chrome_notify_max_times = 0;        // .bss 0x01777c

struct DrawGlArgs {
    int64_t     functor;       // +0x00
    void*       data;          // +0x08
    const void* draw_gl_info;  // +0x10
    const void* overlay_data;  // +0x18
};

uint64_t call_draw_gl_30_trampoline(void* raw_args) {
    // 0x00892c..0x008940
    auto* a = static_cast<DrawGlArgs*>(raw_args);
    g_draw_gl_30_orig(static_cast<int>(a->functor), a->data, a->draw_gl_info);
    return 0;
}

uint64_t call_draw_gl_31_trampoline(void* raw_args) {
    // 0x008944..0x00895c
    auto* a = static_cast<DrawGlArgs*>(raw_args);
    g_draw_gl_31_orig(static_cast<int>(a->functor), a->data, a->draw_gl_info, a->overlay_data);
    return 0;
}

void handle_draw_gl_crash(int rc) {
    // 0x008a18..0x008b2c
    if (rc == 0) {
        return;
    }
    if (g_chrome_cur_error_count == 0) {
        __android_log_print(ANDROID_LOG_INFO, kLogTag, "first time execute failed %d", rc);
        if (g_chrome_need_gc != 0) {
            __android_log_print(ANDROID_LOG_INFO, kLogTag, "do_siggc");
            kill(getpid(), SIGUSR1);  // SIGUSR1 = 10 (0x008a7c: mov w1, #0xa)
        }
        if (g_chrome_notify_remaining >= 1 && g_chrome_notify_remaining <= g_chrome_notify_max_times) {
            __android_log_print(ANDROID_LOG_INFO, kLogTag, "do_notify");
            __android_log_print(ANDROID_LOG_INFO, kLogTag, "do_notify sem");
            sem_post(&g_chrome_notify_sem);
            g_chrome_notify_remaining--;
        }
    }
    g_chrome_cur_error_count++;
    if (g_chrome_cur_error_count == g_chrome_skip_error_count) {
        __android_log_print(ANDROID_LOG_INFO, kLogTag, "draw_glProxy get %d", g_chrome_cur_error_count);
    }
}

void draw_gl_proxy_30(int functor, void* data, const void* draw_gl_info) {
    // 0x008960..0x008a14
    if (g_chrome_cur_error_count > g_chrome_skip_error_count) {
        g_draw_gl_30_orig(functor, data, draw_gl_info);
        shadowhook_pop_stack(__builtin_return_address(0));
        return;
    }
    DrawGlArgs args{functor, data, draw_gl_info, nullptr};
    if (g_chrome_damage_webview != 0) {
        args.data         = reinterpret_cast<void*>(static_cast<uintptr_t>(kWebviewDamageLow));
        args.draw_gl_info = reinterpret_cast<const void*>(static_cast<uintptr_t>(kWebviewDamageHigh));
    }
    TryExecuteTask task = {};
    task.magic = kTryExecuteMagic;
    task.target_fn = call_draw_gl_30_trampoline;
    int rc = safe_execute(&task, &args);
    handle_draw_gl_crash(rc);
    shadowhook_pop_stack(__builtin_return_address(0));
}

void draw_gl_proxy_31(int functor, void* data, const void* draw_gl_info, const void* overlay_data) {
    // 0x008b30..0x008be4
    if (g_chrome_cur_error_count > g_chrome_skip_error_count) {
        g_draw_gl_31_orig(functor, data, draw_gl_info, overlay_data);
        shadowhook_pop_stack(__builtin_return_address(0));
        return;
    }
    DrawGlArgs args{functor, data, draw_gl_info, overlay_data};
    if (g_chrome_damage_webview != 0) {
        args.data         = reinterpret_cast<void*>(static_cast<uintptr_t>(kWebviewDamageLow));
        args.draw_gl_info = reinterpret_cast<const void*>(static_cast<uintptr_t>(kWebviewDamageHigh));
    }
    TryExecuteTask task = {};
    task.magic = kTryExecuteMagic;
    task.target_fn = call_draw_gl_31_trampoline;
    int rc = safe_execute(&task, &args);
    handle_draw_gl_crash(rc);
    shadowhook_pop_stack(__builtin_return_address(0));
}

// ============================================================================
// SUBSYSTEM 7: JitCompileOpt (.bss 0x017780..0x017798, .text 0x008e60..0x0093fc)
// ============================================================================
void*   g_pretty_method_sym      = nullptr;  // .bss 0x017780
uint8_t g_jit_damage             = 0;        // .bss 0x017788
int32_t g_jit_damage_counter     = 0;        // .bss 0x01778c
uint8_t g_jit_build_invoke_ready = 0;        // .bss 0x017790
pid_t   g_jit_failed_tid         = 0;        // .bss 0x017794
void*   g_jit_build_invoke_stub  = nullptr;  // .bss 0x017798

bool h_instruction_builder_build_invoke_proxy(
    void* builder, const void* instruction, uint32_t dex_pc, uint32_t method_idx,
    uint32_t number_of_vreg_arguments, bool is_range, uint32_t* args, uint32_t register_index) {
    // 0x009138..0x009224
    if (g_jit_failed_tid == gettid()) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag,
                            "HInstructionBuilder_BuildInvokeProxy bypass method_idx : %d", method_idx);
        g_jit_failed_tid = -1;
        shadowhook_pop_stack(__builtin_return_address(0));
        return false;
    }
    using BuildInvokeFn = bool (*)(void*, const void*, uint32_t, uint32_t, uint32_t, bool, uint32_t*, uint32_t);
    auto prev_fn = reinterpret_cast<BuildInvokeFn>(
        shadowhook_get_prev_func(reinterpret_cast<void*>(h_instruction_builder_build_invoke_proxy)));
    bool ret = prev_fn(builder, instruction, dex_pc, method_idx,
                       number_of_vreg_arguments, is_range, args, register_index);
    shadowhook_pop_stack(__builtin_return_address(0));
    return ret;
}

void jit_bytehook_hooked_callback(void* /*task_stub*/, int status_code, const char* caller_path_name,
                                  const char* /*sym_name*/, void* /*new_func*/, void* /*prev_func*/, void* /*arg*/) {
    // 0x009348..0x0093e8
    __android_log_print(ANDROID_LOG_ERROR, kLogTag,
                        "init_byteHook setdamage bytehook_hook_single result %d caller_path_name %s",
                        status_code, caller_path_name);
    if (status_code != 0) {
        return;
    }
    g_jit_build_invoke_stub = shadowhook_hook_sym_name(
        "libart-compiler.so",
        "_ZN3art19HInstructionBuilder11BuildInvokeERKNS_11InstructionEjjjbPjj",
        reinterpret_cast<void*>(h_instruction_builder_build_invoke_proxy),
        nullptr);
    if (g_jit_build_invoke_stub != nullptr) {
        g_jit_build_invoke_ready = 1;
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "initJitCompileOpt shadow hook init SUCCESS");
    } else {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "initJitCompileOpt shadow hook init failed");
    }
}

void* resolve_method_proxy(void* class_linker, uint32_t method_idx, void* dex_cache,
                           void* class_loader, void* referrer, int invoke_type);

struct ResolveMethodArgs {
    void*    class_linker;  // +0x00
    int64_t  method_idx;    // +0x08
    void*    dex_cache;     // +0x10
    void*    class_loader;  // +0x18
    void*    referrer;      // +0x20
    int64_t  invoke_type;   // +0x28
};

uint64_t call_resolve_method_trampoline(void* raw_args) {
    // 0x008e60..0x008f70
    auto* a = static_cast<ResolveMethodArgs*>(raw_args);
    void* dex_cache = a->dex_cache;
    if (g_jit_damage != 0) {
        dex_cache = nullptr;
        g_jit_damage_counter++;
    }
    using ResolveMethodFn = void* (*)(void*, uint32_t, void*, void*, void*, int);
    auto prev_fn = reinterpret_cast<ResolveMethodFn>(
        bytehook_get_prev_func(reinterpret_cast<void*>(resolve_method_proxy)));
    return reinterpret_cast<uint64_t>(prev_fn(
        a->class_linker, static_cast<uint32_t>(a->method_idx),
        dex_cache, a->class_loader, a->referrer, static_cast<int>(a->invoke_type)));
}

void* resolve_method_proxy(void* class_linker, uint32_t method_idx, void* dex_cache,
                           void* class_loader, void* referrer, int invoke_type) {
    // 0x008f74..0x009134
    if (g_jit_build_invoke_ready == 0) {
        using ResolveMethodFn = void* (*)(void*, uint32_t, void*, void*, void*, int);
        auto prev_fn = reinterpret_cast<ResolveMethodFn>(
            bytehook_get_prev_func(reinterpret_cast<void*>(resolve_method_proxy)));
        return prev_fn(class_linker, method_idx, dex_cache, class_loader, referrer, invoke_type);
    }
    ResolveMethodArgs args{class_linker, method_idx, dex_cache, class_loader, referrer, invoke_type};
    TryExecuteTask task = {};
    task.magic = kTryExecuteMagic;
    task.target_fn = call_resolve_method_trampoline;
    int rc = safe_execute(&task, &args);
    void* result = nullptr;
    if (rc != 0) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag,
                            "ResolveMethodProxy excute failed method_idx : %d", method_idx);
        g_jit_failed_tid = gettid();
    } else {
        result = reinterpret_cast<void*>(task.result);
    }
    if (bytehook_get_mode() == 0) {
        bytehook_pop_stack(__builtin_return_address(0));
    }
    return result;
}

// ============================================================================
// SUBSYSTEM 11: SafeUffdGCOpt (.data 0x017608..0x017610, .bss 0x017800..0x017820)
// ============================================================================
int32_t       g_uffd_mode              = 1;        // .data 0x017608 = 1
int32_t       g_uffd_backoff_time_us   = 5000;     // .data 0x01760c = 0x1388 (5000 us)
int32_t       g_uffd_backoff_max_count = 5;        // .data 0x017610 = 5
void        (*g_sigchain_handler_orig)(int, siginfo_t*, void*) = nullptr;  // .bss 0x017800
pthread_key_t g_uffd_tls_key           = 0;        // .bss 0x017808
uintptr_t     g_compact_page_addr      = 0;        // .bss 0x017810
uintptr_t     g_alloc_class_true_addr  = 0;        // .bss 0x017818
void*       (*g_alloc_obj_orig)(void*, void*, uint64_t, size_t, int, const void*) = nullptr;  // .bss 0x017820

void uffd_tls_destructor(void* ptr) {
    // 0x00a754..0x00a75c
    if (ptr != nullptr) {
        free(ptr);
    }
}

void signal_chain_handler_proxy(int signo, siginfo_t* info, void* ucontext_raw) {
    // 0x00a2c4..0x00a4a4:
    // Checks signo == 7 (SIGBUS), info->si_code == 2 (BUS_ADRERR), info->si_addr <= 0x22000000,
    // and (ucontext_pc - g_compact_page_addr) >> 14 == 0 (within 16,384 bytes of MarkCompact::CompactPage<false>).
    uint64_t pc = 0;
    if (ucontext_raw != nullptr) {
        pc = *reinterpret_cast<const uint64_t*>(static_cast<const uint8_t*>(ucontext_raw) + 0x1b8);
    }
    if (signo != SIGBUS || info == nullptr || info->si_code != 2 ||
        reinterpret_cast<uintptr_t>(info->si_addr) > 0x22000000ULL) {
        g_sigchain_handler_orig(signo, info, ucontext_raw);
        return;
    }

    auto* tls = static_cast<UffdGcTlsState*>(pthread_getspecific(g_uffd_tls_key));
    if (tls == nullptr) {
        tls = static_cast<UffdGcTlsState*>(malloc(sizeof(UffdGcTlsState)));
        tls->depth = 0;
        tls->retry_count = 0;
        pthread_setspecific(g_uffd_tls_key, tls);
    }
    int32_t cur_depth = ++tls->depth;

    if (pc != 0 && g_compact_page_addr != 0 && pc >= g_compact_page_addr &&
        ((pc - g_compact_page_addr) >> 14) == 0) {
        if (tls->retry_count < g_uffd_backoff_max_count) {
            __android_log_print(ANDROID_LOG_ERROR, kUffdGcTag,
                                "DO back off for signo:%d addr:%p depth:%d retry:%d",
                                SIGBUS, info->si_addr, cur_depth, tls->retry_count);
            usleep(static_cast<useconds_t>(g_uffd_backoff_time_us));
            tls->retry_count++;
        } else {
            __android_log_print(ANDROID_LOG_ERROR, kUffdGcTag,
                                "GIVEUP back off for signo:%d addr:%p depth:%d retry:%d",
                                SIGBUS, info->si_addr, cur_depth, tls->retry_count);
            tls->retry_count++;
            g_sigchain_handler_orig(signo, info, ucontext_raw);
        }
    } else {
        g_sigchain_handler_orig(signo, info, ucontext_raw);
    }

    cur_depth = --tls->depth;
    if (cur_depth <= 0 && tls->retry_count != 0) {
        __android_log_print(ANDROID_LOG_ERROR, kUffdGcTag,
                            "END backoff signo:%d addr:%p depth:%d retry:%d",
                            signo, info->si_addr, cur_depth, tls->retry_count);
    }
}

void* alloc_object_with_allocator_proxy(void* heap, void* self_thread, uint64_t klass,
                                        size_t byte_count, int allocator_type, const void* visitor) {
    // 0x00a760..0x00a820:
    // If allocator_type != 4 and (LR - 4096) < g_alloc_class_true_addr, try allocating with allocator_type = 4 (kAllocatorTypeNonMoving).
    uintptr_t caller_lr = reinterpret_cast<uintptr_t>(__builtin_return_address(0));
    if (allocator_type != 4 && (caller_lr - 0x1000ULL) < g_alloc_class_true_addr) {
        void* obj = g_alloc_obj_orig(heap, self_thread, klass, byte_count, 4, visitor);
        if (obj != nullptr) {
            return obj;
        }
    }
    return g_alloc_obj_orig(heap, self_thread, klass, byte_count, allocator_type, visitor);
}

// ============================================================================
// SUBSYSTEM 14: WebviewChromiumOpt (.bss 0x017870..0x0178a8, .text 0x00d3f4..0x00db48)
// ============================================================================
std::string g_webview_so_name = "libwebviewchromium.so";  // .bss 0x017870 (.init_array 0x00d3f4)
jboolean  (*g_exception_check_orig)(JNIEnv*) = nullptr;   // .bss 0x017888
uint8_t     g_webview_clear_exp              = 0;         // .bss 0x017890
jclass      g_webview_opt_clazz              = nullptr;   // .bss 0x017898
uintptr_t   g_webview_seg_start              = 0;         // .bss 0x0178a0
uintptr_t   g_webview_seg_end                = 0;         // .bss 0x0178a8

jboolean exception_check_proxy(JNIEnv* env) {
    // 0x00d8b8..0x00d9f4
    uintptr_t caller_lr = reinterpret_cast<uintptr_t>(__builtin_return_address(0));
    using ExceptionCheckFn = jboolean (*)(JNIEnv*);
    auto prev_fn = reinterpret_cast<ExceptionCheckFn>(
        shadowhook_get_prev_func(reinterpret_cast<void*>(exception_check_proxy)));
    jboolean has_exc = prev_fn(env);

    if (caller_lr >= g_webview_seg_start && caller_lr < g_webview_seg_end) {
        if (has_exc != JNI_FALSE) {
            jthrowable exc = env->ExceptionOccurred();
            if (exc != nullptr) {
                __android_log_print(ANDROID_LOG_ERROR, kWebviewTag, "exception occurred.");
                env->ExceptionClear();
                jmethodID get_stack_mid = env->GetStaticMethodID(
                    g_webview_opt_clazz, "getSanitizedStacktrace", "(Ljava/lang/Throwable;)Ljava/lang/String;");
                if (get_stack_mid != nullptr) {
                    auto stack_jstr = static_cast<jstring>(
                        env->CallStaticObjectMethod(g_webview_opt_clazz, get_stack_mid, exc));
                    std::string stack_str = convert_java_string_to_utf8(env, stack_jstr);
                    if (stack_jstr != nullptr) {
                        env->DeleteLocalRef(stack_jstr);
                    }
                    __android_log_print(ANDROID_LOG_ERROR, kWebviewTag, "%s", stack_str.c_str());
                } else {
                    __android_log_print(ANDROID_LOG_ERROR, kWebviewTag, "GetStaticMethodID failed");
                }
                if (g_webview_clear_exp != 0) {
                    has_exc = JNI_FALSE;
                } else {
                    env->Throw(exc);
                }
            }
        }
    }
    shadowhook_pop_stack(__builtin_return_address(0));
    return has_exc;
}

}  // namespace
}  // namespace touphic
}  // namespace godzilla
}  // namespace platform
}  // namespace bytedance

// ============================================================================
// EXPORTED C / JNI ENTRYPOINTS (.dynsym [085..111])
// ============================================================================

using namespace bytedance::platform::godzilla::touphic;

extern "C" {

JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_touphic_VisitLocksOpt_start(JNIEnv* /*env*/, jclass /*clazz*/, jint sdk_int) {
    // 0x0071dc..0x0072c0
    void* sym = find_symbol_in_so(
        "libart.so",
        "_ZN3art7Monitor10VisitLocksEPNS_12StackVisitorEPFvNS_6ObjPtrINS_6mirror6ObjectEEEPvES7_b");
    g_visit_locks_orig_fn = reinterpret_cast<void (*)(void*, void*, void*, bool)>(sym);
    if (sym == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag,
                            "in %s can not find VisitLocksFunc symbol, sdkInt = %d",
                            "libart.so", sdk_int);
        return 3;
    }
    if (shadowhook_init(0, false) != 0) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "init shadowhook failed !!!");
        return 7;
    }
    void* stub = shadowhook_hook_sym_addr(
        sym,
        reinterpret_cast<void*>(visit_locks_wrapper),
        reinterpret_cast<void**>(&g_visit_locks_orig_fn));
    if (stub != nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "VisitLocksWrapper init end");
        return 0;
    }
    __android_log_print(ANDROID_LOG_ERROR, kLogTag, "hook VisitLocksFunc failed !!!");
    return 5;
}

JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_touphic_DirectBufferOpt_start(JNIEnv* /*env*/, jclass /*clazz*/, jint sdk_int) {
    // 0x007330..0x007480
    void* sym_true = find_symbol_in_so(
        "libart.so", "_ZN3art3JNIILb1EE18GetByteArrayRegionEP7_JNIEnvP11_jbyteArrayiiPa");
    g_true_get_byte_array_orig = reinterpret_cast<void (*)(JNIEnv*, jbyteArray, jint, jint, jbyte*)>(sym_true);
    void* sym_false = find_symbol_in_so(
        "libart.so", "_ZN3art3JNIILb0EE18GetByteArrayRegionEP7_JNIEnvP11_jbyteArrayiiPa");
    g_false_get_byte_array_orig = reinterpret_cast<void (*)(JNIEnv*, jbyteArray, jint, jint, jbyte*)>(sym_false);

    if (sym_true == nullptr && sym_false == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag,
                            "in %s can not find GetByteArrayRegionFunc symbol, sdkInt = %d",
                            "libart.so", sdk_int);
        return 3;
    }
    if (shadowhook_init(0, false) != 0) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "init shadowhook failed !!!");
        return 7;
    }
    if (sym_true != nullptr) {
        if (shadowhook_hook_sym_addr(
                sym_true,
                reinterpret_cast<void*>(true_get_byte_array_region_proxy),
                reinterpret_cast<void**>(&g_true_get_byte_array_orig)) == nullptr) {
            __android_log_print(ANDROID_LOG_ERROR, kLogTag, "hook sTrue_GetByteArrayRegionFunc failed !!!");
            return 5;
        }
    }
    if (sym_false != nullptr) {
        if (shadowhook_hook_sym_addr(
                sym_false,
                reinterpret_cast<void*>(false_get_byte_array_region_proxy),
                reinterpret_cast<void**>(&g_false_get_byte_array_orig)) == nullptr) {
            __android_log_print(ANDROID_LOG_ERROR, kLogTag, "hook sFalse_GetByteArrayRegionFunc failed !!!");
            return 5;
        }
    }
    __android_log_print(ANDROID_LOG_ERROR, kLogTag, "do GetByteArrayRegionFunc success!");
    return 0;
}

JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_touphic_DirectBufferOpt_nativeEnableSEGV(JNIEnv* /*env*/, jclass /*clazz*/) {
    // 0x0076a4..0x0076b0
    g_direct_buf_enable_segv = 1;
}

JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_touphic_DirectBufferOpt_nativeEnableSIGBUS(JNIEnv* /*env*/, jclass /*clazz*/) {
    // 0x0076b4..0x0076c0
    g_direct_buf_enable_sigbus = 1;
}

JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_touphic_MaxTextureOpt_nStart(JNIEnv* env, jclass clazz, jint sdk_int) {
    return max_texture_opt_start(env, clazz, sdk_int);
}

JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_touphic_MaxTextureOpt_nSafeMaxTextureSize(JNIEnv* env, jclass clazz) {
    return max_texture_opt_safe_max_size(env, clazz);
}

JNIEXPORT jboolean JNICALL
Java_com_bytedance_platform_godzilla_touphic_impl_MakeFromTextureOptS_startHook(JNIEnv* env, jobject thiz) {
    return make_from_texture_opt_s_start_hook(env, thiz);
}

JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_touphic_impl_MakeFromTextureOptS_createCrash(JNIEnv* env, jobject thiz) {
    make_from_texture_opt_s_create_crash(env, thiz);
}

JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_touphic_impl_SurfaceUpdateOpt_start(JNIEnv* env, jobject thiz, jint sdk_int) {
    return surface_update_opt_start(env, thiz, sdk_int);
}

int _Z23updateTexImageByteProxyPv(void* surface_texture) {
    return update_tex_image_byte_proxy_impl(surface_texture);
}

int _Z19updateTexImageProxyPv(void* surface_texture) {
    return update_tex_image_proxy_impl(surface_texture);
}

JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_touphic_impl_ChromeSupportOpt_start(
    JNIEnv* /*env*/, jobject /*thiz*/, jboolean need_gc, jboolean need_listen,
    jint sdk_version, jint skip_error_count, jint notify_times) {
    // 0x008be8..0x008e28
    __android_log_print(
        ANDROID_LOG_INFO, kLogTag,
        "hook return: need_gc: %d , needListen: %d, sdkVersion: %d, skipErrorCount: %d, notifyTimes: %d",
        need_gc != JNI_FALSE, need_listen != JNI_FALSE, sdk_version, skip_error_count, notify_times);
    if (sdk_version < 29) {  // 0x008c3c: cmp w22, #0x1d; b.ge #0x8c4c
        return 0;
    }
    g_chrome_skip_error_count = skip_error_count;
    g_chrome_need_gc          = (need_gc != JNI_FALSE) ? 1 : 0;
    g_chrome_notify_max_times = notify_times;

    void* handle = shadowhook_dlopen("libwebviewchromium_plat_support.so");
    if (handle == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "dlopen NATIVE_CHROME_SUPPORT_SO failed");
        return 2;
    }
    int sh_rc = shadowhook_init(0, false);
    if (sh_rc != 0) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "init shadowhook failed: %d", sh_rc);
        shadowhook_dlclose(handle);
        return 7;
    }

    if (sdk_version <= 30) {
        const char* sym30 = "_ZN7android12_GLOBAL__N_17draw_glEiPvRKNS_10uirenderer10DrawGlInfoE";
        g_draw_gl_30_orig = reinterpret_cast<void (*)(int, void*, const void*)>(shadowhook_dlsym(handle, sym30));
        shadowhook_dlclose(handle);
        if (g_draw_gl_30_orig == nullptr) {
            __android_log_print(ANDROID_LOG_ERROR, kLogTag, "find draw_gl sym failed for %s", sym30);
            return 3;
        }
        if (shadowhook_hook_sym_addr(
                reinterpret_cast<void*>(g_draw_gl_30_orig),
                reinterpret_cast<void*>(draw_gl_proxy_30),
                reinterpret_cast<void**>(&g_draw_gl_30_orig)) == nullptr) {
            __android_log_print(ANDROID_LOG_ERROR, kLogTag, "hook draw_gl failed for %s", sym30);
            return 5;
        }
    } else {
        const char* sym31 = "_ZN7android12_GLOBAL__N_17draw_glEiPvRKNS_10uirenderer10DrawGlInfoERKNS2_18WebViewOverlayDataE";
        g_draw_gl_31_orig = reinterpret_cast<void (*)(int, void*, const void*, const void*)>(shadowhook_dlsym(handle, sym31));
        shadowhook_dlclose(handle);
        if (g_draw_gl_31_orig == nullptr) {
            __android_log_print(ANDROID_LOG_ERROR, kLogTag, "find draw_gl sym failed for %s", sym31);
            return 3;
        }
        if (shadowhook_hook_sym_addr(
                reinterpret_cast<void*>(g_draw_gl_31_orig),
                reinterpret_cast<void*>(draw_gl_proxy_31),
                reinterpret_cast<void**>(&g_draw_gl_31_orig)) == nullptr) {
            __android_log_print(ANDROID_LOG_ERROR, kLogTag, "hook draw_gl failed for %s", sym31);
            return 5;
        }
    }

    if (need_listen != JNI_FALSE) {
        g_chrome_notify_remaining = notify_times;
        if (sem_init(&g_chrome_notify_sem, 0, 0) < 0) {
            __android_log_print(ANDROID_LOG_ERROR, kLogTag, "sem_init failed !!!");
            return -1;
        }
    }
    return 0;
}

JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_touphic_impl_ChromeSupportOpt_doWait(JNIEnv* /*env*/, jobject /*thiz*/) {
    // 0x008e2c..0x008e48
    sem_wait(&g_chrome_notify_sem);
    return 0;
}

JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_touphic_impl_ChromeSupportOpt_setDamageWebview(
    JNIEnv* /*env*/, jobject /*thiz*/, jboolean damage) {
    // 0x008e4c..0x008e5c
    g_chrome_damage_webview = (damage != JNI_FALSE) ? 1 : 0;
}

JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_touphic_impl_JitCompileOpt_start(JNIEnv* /*env*/, jobject /*thiz*/, jint sdk_int) {
    // 0x009228..0x009344: sub w8, w2, #0x1d; cmn w8, #2; b.hs #0x9248
    if (sdk_int == 27 || sdk_int == 28) {
        return -10;
    }
    if (shadowhook_init(0, false) != 0) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "initJitCompileOpt shadow hook init failed");
        return -1;
    }
    if (bytehook_init(0, true) != 0) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "init_byteHook bytehook_init failed");
        return -2;
    }
    bytehook_set_debug(true);
    void* stub = bytehook_hook_single(
        "libart-compiler.so",
        "libart.so",
        "_ZN3art11ClassLinker13ResolveMethodILNS0_11ResolveModeE1EEEPNS_9ArtMethodEjNS_6HandleINS_6mirror8DexCacheEEENS5_INS6_11ClassLoaderEEES4_NS_10InvokeTypeE",
        reinterpret_cast<void*>(resolve_method_proxy),
        jit_bytehook_hooked_callback,
        nullptr);
    int ret = (stub != nullptr) ? 0 : -3;
    __android_log_print(ANDROID_LOG_ERROR, kLogTag, "initJitCompileOpt ret %d", ret);
    return ret;
}

JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_touphic_impl_JitCompileOpt_setDamage(
    JNIEnv* /*env*/, jobject /*thiz*/, jboolean damage) {
    // 0x0093ec..0x0093fc
    g_jit_damage = (damage != JNI_FALSE) ? 1 : 0;
}

JNIEXPORT jboolean JNICALL
Java_com_bytedance_platform_godzilla_touphic_util_TouphicInitUtil_initNativeAlog(JNIEnv* env, jclass clazz) {
    return init_native_alog_impl(env, clazz);
}

JNIEXPORT jboolean JNICALL
Java_com_bytedance_platform_godzilla_touphic_AvLockRegisterHelper_nativeIgnoreAVLockMgrRegister(
    JNIEnv* env, jclass clazz) {
    return ignore_av_lockmgr_register_impl(env, clazz);
}

JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_touphic_CreateLayerOpt_nativeInit(
    JNIEnv* env, jclass clazz, jint sdk_int, jint max_texture_size, jboolean is_debug) {
    return create_layer_opt_init(env, clazz, sdk_int, max_texture_size, is_debug);
}

JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_touphic_GLESMaliOpt_nativeInit(
    JNIEnv* env, jclass clazz, jstring build_id, jstring target_sym, jlong offset, jboolean is_debug) {
    return gles_mali_opt_init(env, clazz, build_id, target_sym, offset, is_debug);
}

JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_touphic_SafeUffdGCOpt_start(JNIEnv* /*env*/, jclass /*clazz*/, jint sdk_int) {
    // 0x00a4a8..0x00a750
    __android_log_print(ANDROID_LOG_ERROR, kUffdGcTag,
                        "init safe uffdgc start sMode : %d sdk_int : %d", g_uffd_mode, sdk_int);
    void* compact_15 = find_symbol_in_so(
        "libart.so",
        "_ZN3art2gc9collector11MarkCompact11CompactPageEPNS_6mirror6ObjectEjPhb");
    if (compact_15 != nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, kUffdGcTag, "shouldStart did found compact_15 %p", compact_15);
        return 0;
    }
    if (shadowhook_init(0, false) != 0) {
        __android_log_print(ANDROID_LOG_ERROR, kUffdGcTag, "init shadowhook failed !!!");
        return 7;
    }

    if ((g_uffd_mode & 1) != 0) {
        __android_log_print(ANDROID_LOG_ERROR, kUffdGcTag,
                            "init_back_off %d, %d", g_uffd_backoff_time_us, g_uffd_backoff_max_count);
        g_compact_page_addr = reinterpret_cast<uintptr_t>(find_symbol_in_so(
            "libart.so",
            "_ZN3art2gc9collector11MarkCompact11CompactPageILb0EEEvPNS_6mirror6ObjectEjPhS7_b"));
        g_sigchain_handler_orig = reinterpret_cast<void (*)(int, siginfo_t*, void*)>(
            find_symbol_in_so("libsigchain.so", "_ZN3art11SignalChain7HandlerEiP7siginfoPv"));
        if (g_compact_page_addr != 0 && g_sigchain_handler_orig != nullptr) {
            pthread_key_create(&g_uffd_tls_key, uffd_tls_destructor);
            shadowhook_hook_sym_addr_2(
                reinterpret_cast<void*>(g_sigchain_handler_orig),
                reinterpret_cast<void*>(signal_chain_handler_proxy),
                reinterpret_cast<void**>(&g_sigchain_handler_orig),
                4);
        }
    }

    if ((g_uffd_mode & 2) != 0) {
        g_alloc_class_true_addr = reinterpret_cast<uintptr_t>(find_symbol_in_so(
            "libart.so",
            "_ZN3art11ClassLinker10AllocClassILb1EEENS_6ObjPtrINS_6mirror5ClassEEEPNS_6ThreadES5_j"));
        g_alloc_obj_orig = reinterpret_cast<void* (*)(void*, void*, uint64_t, size_t, int, const void*)>(
            find_symbol_in_so(
                "libart.so",
                "_ZN3art2gc4Heap24AllocObjectWithAllocatorILb1ELb1ENS_6mirror5Class22InitializeClassVisitorEEEPNS3_6ObjectEPNS_6ThreadENS_6ObjPtrIS4_EEmNS0_13AllocatorTypeERKT1_"));
        if (g_alloc_class_true_addr != 0 && g_alloc_obj_orig != nullptr) {
            shadowhook_hook_sym_addr_2(
                reinterpret_cast<void*>(g_alloc_obj_orig),
                reinterpret_cast<void*>(alloc_object_with_allocator_proxy),
                reinterpret_cast<void**>(&g_alloc_obj_orig),
                4);
        }
    }

    __android_log_print(ANDROID_LOG_ERROR, kUffdGcTag, "SignalChainHandlerFunc init end");
    return 0;
}

JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_touphic_SafeUffdGCOpt_setParamNative(
    JNIEnv* /*env*/, jclass /*clazz*/, jint back_off_time, jint back_off_max_count) {
    // 0x00a824..0x00a878
    __android_log_print(ANDROID_LOG_ERROR, kUffdGcTag,
                        "set sbackOffTime:%d, sbackOffMaxCount:%d",
                        g_uffd_backoff_time_us, g_uffd_backoff_max_count);
    g_uffd_backoff_time_us   = back_off_time;
    g_uffd_backoff_max_count = back_off_max_count;
}

JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_touphic_SafeUffdGCOpt_setMode(JNIEnv* /*env*/, jclass /*clazz*/, jint mode) {
    // 0x00a87c..0x00a884
    g_uffd_mode = mode;
}

JNIEXPORT jboolean JNICALL
Java_com_bytedance_platform_godzilla_touphic_EglNotInitOpt_nativeWaitEglInit(
    JNIEnv* env, jclass clazz, jint delay_ms) {
    return egl_not_init_opt_wait(env, clazz, delay_ms);
}

JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_touphic_GLESAdrenoOpt_nativeInitDoubleFreeOpt(
    JNIEnv* env, jclass clazz, jint size, jint slot_size, jboolean need_timing, jboolean is_debug) {
    return gles_adreno_opt_init_double_free(env, clazz, size, slot_size, need_timing, is_debug);
}

JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_touphic_GLESAdrenoOpt_nativeInitUafOpt(
    JNIEnv* env, jclass clazz, jint mode, jobject config_obj) {
    return gles_adreno_opt_init_uaf(env, clazz, mode, config_obj);
}

JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_touphic_WebviewChromiumOpt_nativeInit(
    JNIEnv* env, jclass clazz, jstring so_name, jboolean clear_exp) {
    // 0x00d424..0x00d8b4
    g_webview_clear_exp = (clear_exp != JNI_FALSE) ? 1 : 0;
    g_webview_exception_check_orig:
    g_exception_check_orig = env->functions->ExceptionCheck;
    g_webview_opt_clazz = static_cast<jclass>(env->NewGlobalRef(clazz));
    if (g_webview_opt_clazz == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, kWebviewTag, "NewGlobalRef failed");
        return -1;
    }

    g_webview_so_name = convert_java_string_to_utf8(env, so_name);
    if (so_name != nullptr) {
        env->DeleteLocalRef(so_name);
    }
    if (g_webview_so_name.empty()) {
        __android_log_print(ANDROID_LOG_ERROR, kWebviewTag, "convert_java_string_to_utf8 failed");
        env->DeleteGlobalRef(g_webview_opt_clazz);
        return -1;
    }

    char maps_path[32] = {};
    format_buffer(maps_path, sizeof(maps_path), "/proc/%d/maps", getpid());
    FILE* fp = fopen(maps_path, "r");
    if (fp != nullptr) {
        char line[1024] = {};
        while (fgets(line, sizeof(line), fp) != nullptr) {
            unsigned long start_addr = 0, end_addr = 0;
            unsigned int offset_val = 0, inode = 0;
            char perms[8] = {}, path_buf[512] = {};
            int chars_read = 0;
            sscanf(line, "%lx-%lx %c%c%c%c %x %*x:%*x  %u %[^\n] %n",
                   &start_addr, &end_addr, &perms[0], &perms[1], &perms[2], &perms[3],
                   &offset_val, &inode, path_buf, &chars_read);
            if (strstr(path_buf, g_webview_so_name.c_str()) != nullptr) {
                if (g_webview_seg_start == 0) {
                    g_webview_seg_start = start_addr;
                }
                g_webview_seg_end = end_addr;
            }
        }
        fclose(fp);
    }

    if (g_webview_seg_start == 0 || g_webview_seg_end == 0) {
        __android_log_print(ANDROID_LOG_ERROR, kWebviewTag, "get_target_addr_range failed");
        env->DeleteGlobalRef(g_webview_opt_clazz);
        return -1;
    }

    void* stub = shadowhook_hook_func_addr(
        reinterpret_cast<void*>(g_exception_check_orig),
        reinterpret_cast<void*>(exception_check_proxy),
        nullptr);
    if (stub == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, kWebviewTag, "hook ExceptionCheck failed");
        env->DeleteGlobalRef(g_webview_opt_clazz);
        return -1;
    }

    __android_log_print(
        ANDROID_LOG_ERROR, kWebviewTag,
        "hook ExceptionCheck success, ExceptionCheck addr: %p, webview_chromium_so_name: %s, clearExp: %d, range: [%lx-%lx]",
        reinterpret_cast<void*>(g_exception_check_orig),
        g_webview_so_name.c_str(),
        g_webview_clear_exp,
        static_cast<unsigned long>(g_webview_seg_start),
        static_cast<unsigned long>(g_webview_seg_end));
    return 0;
}

}  // extern "C"
