/**
 * @file godzilla_touphic_core_infra.cpp
 * @brief Implementation of Core Signal-Safe Execution (`safe_execute`), Symbol Resolution, Tracepoint RB-Tree, and Alog/FFmpeg Helpers
 *        Triển khai Thực thi An toàn Tín hiệu (`safe_execute`), Phân giải Biểu tượng, Cây Đỏ-Đen Tracepoint, và Tiện ích Alog/FFmpeg
 *
 * Binary Target / Đích nhị phân:
 *   apktool-res/lib/arm64-v8a/libgodzilla-touphic.so (65,304 bytes)
 * Verification Scope / Phạm vi xác minh:
 *   .text 0x009400..0x009534 & 0x00db4c..0x00e928
 */

#include "godzilla_touphic_core_infra.h"

#include <android/log.h>
#include <dlfcn.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <unistd.h>

namespace bytedance {
namespace platform {
namespace godzilla {
namespace touphic {

namespace {

static constexpr const char* kLogTag = "TOUPHIC";  // .rodata 0x0049f2

// .data 0x017620..0x0176b8: 4 SignalSlot entries (40 bytes = 0x28 each)
//   [0] 0x017620: signo = 6  (SIGABRT)
//   [1] 0x017648: signo = 5  (SIGTRAP)
//   [2] 0x017670: signo = 11 (SIGSEGV)
//   [3] 0x017698: signo = 7  (SIGBUS)
SignalSlot g_signal_slots[4] = {
    {6,  0, {}},
    {5,  0, {}},
    {11, 0, {}},
    {7,  0, {}}
};

// .bss 0x0178b0..0x0178b8: Native Alog function pointers
void* g_alog_write_fn                  = nullptr;  // 0x0178b0
void* g_alog_write_default_instance_fn = nullptr;  // 0x0178b8

// .bss 0x0178c0..0x0178ee: safe_execute & sigaction state
pthread_once_t g_sigaction_once = PTHREAD_ONCE_INIT;  // 0x0178c0
pthread_key_t  g_jmpbuf_tls_key = 0;                  // 0x0178c4
pthread_key_t  g_task_tls_key   = 0;                  // 0x0178c8
struct sigaction g_new_sigaction = {};                // 0x0178d0

// .data/.bss 0x0176c0..0x0176d0 & 0x0178f0: Tracepoint RB-Tree & mutex
struct TracepointRbTreeHeader {
    TracepointRbNode* begin_node;  // 0x0176c0 (initialized to &end_node = 0x0176c8 via .rela.dyn)
    TracepointRbNode* end_left;    // 0x0176c8 (root pointer)
    uint64_t          node_count;  // 0x0176d0
};
TracepointRbTreeHeader g_tracepoint_tree = {
    reinterpret_cast<TracepointRbNode*>(&g_tracepoint_tree.end_left),
    nullptr,
    0
};
std::mutex g_tracepoint_mutex;  // 0x0178f0

/**
 * @brief TLS destructor for `g_jmpbuf_tls_key` (`0x00dd90..0x00dd98`).
 *        Hàm hủy TLS cho `g_jmpbuf_tls_key` (`0x00dd90..0x00dd98`).
 * Disassembly:
 *   0x00dd90: cbz x0, #0xdd98
 *   0x00dd94: b   #0xed00 (free)
 */
void jmpbuf_tls_destructor(void* ptr) {
    if (ptr != nullptr) {
        free(ptr);
    }
}

/**
 * @brief Instruction interceptor trampoline (`0x00e09c..0x00e0dc`) invoking `std::function<void(ShadowHookCpuContext*)>`.
 *        Hàm cầu nối chặn lệnh (`0x00e09c..0x00e0dc`) gọi `std::function<void(ShadowHookCpuContext*)>`.
 */
void tracepoint_interceptor_trampoline(ShadowHookCpuContext* cpu_ctx, void* data) {
    if (data == nullptr) {
        return;
    }
    auto* fn = reinterpret_cast<std::function<void(ShadowHookCpuContext*)>*>(data);
    if (!(*fn)) {
        abort();  // 0x00e0e0 -> 0x00e0e4 -> bl abort
    }
    (*fn)(cpu_ctx);
}

/**
 * @brief Recursive post-order deletion of Tracepoint RB-Tree nodes (`0x00e53c..0x00e570`).
 *        Xóa đệ quy hậu thứ tự các nút Cây Đỏ-Đen Tracepoint (`0x00e53c..0x00e570`).
 */
void destroy_tracepoint_rbtree(TracepointRbNode* node) {
    if (node == nullptr) {
        return;
    }
    destroy_tracepoint_rbtree(node->left);
    destroy_tracepoint_rbtree(node->right);
    operator delete(node);
}

}  // namespace

// ============================================================================
// 1. SAFE_EXECUTE & SIGNAL RECOVERY / THỰC THI AN TOÀN & PHỤC HỒI TÍN HIỆU
// ============================================================================

/**
 * @brief Signal handler for `SIGABRT(6)`, `SIGTRAP(5)`, `SIGSEGV(11)`, `SIGBUS(7)` (`0x00dd9c..0x00df60`).
 *        Trình xử lý tín hiệu cho `SIGABRT(6)`, `SIGTRAP(5)`, `SIGSEGV(11)`, `SIGBUS(7)` (`0x00dd9c..0x00df60`).
 *
 * AArch64 Disassembly Verification:
 *   - `0x00ddb8`: `ldr w0, [x8, #0x8c8]; bl pthread_getspecific` (loads `TryExecuteTask*`)
 *   - `0x00ddcc`: `mov w9, #0x3c4d; movk w9, #0x1a2b, lsl #16; cmp w8, w9` (checks `magic == 0x1a2b3c4d`)
 *   - `0x00ddf8`: `ldr x8, [x21, #0x18]; cbz x8, #0xde38; mov x0, x20; blr x8` (calls `sig_callback(siginfo)`)
 *   - `0x00de2c`: `sub w8, w21, #0x112, lsl #12; cmp w8, #0x358; b.eq #0xde48` (checks `ret == 0x00112358`)
 *   - `0x00df5c`: `mov w1, #1; bl siglongjmp` (jumps back to `safe_execute` on `g_jmpbuf_tls_key`)
 *   - `0x00de64..0x00dedc`: Restores `old_action` (`umaddl x8, w8, w9, x10` with `w9 = 0x28`) and calls `syscall(0xf0, getpid(), gettid(), signo)`
 */
void signal_handler(int signo, siginfo_t* info, void* /*ucontext*/) {
    auto* task = static_cast<TryExecuteTask*>(pthread_getspecific(g_task_tls_key));
    if (task != nullptr && task->magic == kTryExecuteMagic) {
        __android_log_print(ANDROID_LOG_INFO, kLogTag, "get sig %u while do try excute ", signo);
        bool should_longjmp = true;
        if (task->sig_callback != nullptr) {
            uint32_t cb_ret = task->sig_callback(reinterpret_cast<int*>(info));
            __android_log_print(ANDROID_LOG_INFO, kLogTag, "get sig %u callback ret 0x%x, bypass set ", signo, cb_ret);
            if (cb_ret == kSignalPassThroughReturn) {
                should_longjmp = false;
            }
        }
        if (should_longjmp) {
            auto* jmp_buf_ptr = static_cast<sigjmp_buf*>(pthread_getspecific(g_jmpbuf_tls_key));
            if (jmp_buf_ptr != nullptr) {
                siglongjmp(*jmp_buf_ptr, 1);
            }
        }
    }

    __android_log_print(ANDROID_LOG_INFO, kLogTag, "excute_sighandler resend %d ", signo);
    int slot_index = -1;
    if (g_signal_slots[0].signo == signo) {
        slot_index = 0;
    } else if (g_signal_slots[1].signo == signo) {
        slot_index = 1;
    } else if (g_signal_slots[2].signo == signo) {
        slot_index = 2;
    } else if (g_signal_slots[3].signo == signo) {
        slot_index = 3;
    }

    if (slot_index >= 0) {
        sigaction(signo, &g_signal_slots[slot_index].old_action, nullptr);
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "resend_sig %d", signo);
    }

    pid_t pid = getpid();
    pid_t tid = gettid();
    int si_signo = (info != nullptr) ? info->si_signo : signo;
    long ret = syscall(kSysTgkillAArch64, pid, tid, si_signo, info);
    if (ret != 0) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "failed to resend %d", signo);
    }
}

/**
 * @brief One-time initializer (`0x00dc4c..0x00dd8c`) creating TLS keys and installing 4 signal handlers.
 *        Hàm khởi tạo một lần (`0x00dc4c..0x00dd8c`) tạo khóa TLS và cài đặt 4 trình xử lý tín hiệu.
 */
void init_sigaction() {
    pthread_key_create(&g_jmpbuf_tls_key, jmpbuf_tls_destructor);
    pthread_key_create(&g_task_tls_key, nullptr);

    sigemptyset(&g_new_sigaction.sa_mask);
    g_new_sigaction.sa_flags = SA_SIGINFO;  // 0x00dca8: orr w8, w8, #4 (SA_SIGINFO = 4)
    g_new_sigaction.sa_sigaction = signal_handler;

    for (int i = 0; i < 4; ++i) {
        sigaction(g_signal_slots[i].signo, &g_new_sigaction, &g_signal_slots[i].old_action);
        __android_log_print(
            ANDROID_LOG_INFO, kLogTag,
            "excecute_init signo %d, new : %p, old %p ",
            g_signal_slots[i].signo,
            reinterpret_cast<void*>(g_new_sigaction.sa_sigaction),
            reinterpret_cast<void*>(g_signal_slots[i].old_action.sa_sigaction));
    }
    __android_log_print(ANDROID_LOG_INFO, kLogTag, "excecute_init finish ");
}

/**
 * @brief Executes `task->target_fn(arg)` under `sigsetjmp` protection (`0x00db4c..0x00dc48`).
 *        Thực thi `task->target_fn(arg)` dưới sự bảo vệ của `sigsetjmp` (`0x00db4c..0x00dc48`).
 *
 * AArch64 Disassembly Verification:
 *   - `0x00db74`: `bl pthread_once` (`&g_sigaction_once`, `init_sigaction`)
 *   - `0x00db8c`: `mov w8, #0x108; mov w0, w8; bl malloc` (`sizeof(sigjmp_buf) = 264 = 0x108` bytes on AArch64!)
 *   - `0x00dbb4`: `bl sigsetjmp(jmp_buf, 1)`
 *   - If `sigsetjmp != 0`: clears `task->magic = 0`, clears TLS task pointer, logs `"excute fatal while do func %p"`, returns `1`.
 *   - If `sigsetjmp == 0`: sets `task->magic = 0x1a2b3c4d`, stores `task` in `g_task_tls_key`, calls `task->result = task->target_fn(arg)`, clears `task->magic = 0` and TLS key, returns `0`.
 */
int safe_execute(TryExecuteTask* task, void* arg) {
    pthread_once(&g_sigaction_once, init_sigaction);

    auto* jmp_buf_ptr = static_cast<sigjmp_buf*>(pthread_getspecific(g_jmpbuf_tls_key));
    if (jmp_buf_ptr == nullptr) {
        // 0x00db8c: mov w8, #0x108 (264 bytes = AArch64 sigjmp_buf)
        jmp_buf_ptr = static_cast<sigjmp_buf*>(malloc(0x108));
        pthread_setspecific(g_jmpbuf_tls_key, jmp_buf_ptr);
    }

    if (sigsetjmp(*jmp_buf_ptr, 1) != 0) {
        task->magic = 0;
        pthread_setspecific(g_task_tls_key, nullptr);
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "excute fatal while do func %p",
                            reinterpret_cast<void*>(task->target_fn));
        return 1;
    }

    task->magic = kTryExecuteMagic;
    pthread_setspecific(g_task_tls_key, task);
    task->result = task->target_fn(arg);
    task->magic = 0;
    pthread_setspecific(g_task_tls_key, nullptr);
    return 0;
}

// ============================================================================
// 2. SYMBOL RESOLUTION & TRACEPOINT RB-TREE / PHÂN GIẢI SYMBOL & CÂY RB-TREE
// ============================================================================

/**
 * @brief Resolves a symbol in `so_name` via NPTH (`npth_dlopen` / `npth_dlsym_size` / `npth_dlsym_symtab_size`)
 *        with fallback to ShadowHook (`shadowhook_dlopen` / `shadowhook_dlsym`) (`0x00df64..0x00e098`).
 *        Phân giải biểu tượng trong `so_name` qua NPTH kèm dự phòng ShadowHook (`0x00df64..0x00e098`).
 */
void* find_symbol_in_so(const char* so_name, const char* sym_name) {
    void* npth_handle = npth_dlopen(so_name);
    if (npth_handle != nullptr) {
        size_t sym_size = 0;
        void* sym_addr = npth_dlsym_size(npth_handle, sym_name, &sym_size);
        if (sym_addr == nullptr) {
            sym_addr = npth_dlsym_symtab_size(npth_handle, sym_name, &sym_size);
        }
        __android_log_print(ANDROID_LOG_INFO, kLogTag, "from %s find %s symbol %p, size %zu",
                            so_name, sym_name, sym_addr, sym_size);
        npth_dlclose(npth_handle);
        if (sym_addr != nullptr) {
            return sym_addr;
        }
    } else {
        __android_log_print(ANDROID_LOG_INFO, kLogTag, "so npth NOT FOUND from %s find %s",
                            so_name, sym_name);
    }

    void* sh_handle = shadowhook_dlopen(so_name);
    if (sh_handle != nullptr) {
        void* sym_addr = shadowhook_dlsym(sh_handle, sym_name);
        if (sym_addr != nullptr) {
            __android_log_print(ANDROID_LOG_INFO, kLogTag, "from %s find %s symbol %p",
                                so_name, sym_name, sym_addr);
        }
        shadowhook_dlclose(sh_handle);
        return sym_addr;
    }

    __android_log_print(ANDROID_LOG_INFO, kLogTag, "so shadow NOT FOUND from %s find %s",
                        so_name, sym_name);
    return nullptr;
}

/**
 * @brief Installs an instruction tracepoint and inserts it into the RB-Tree (`0x00e0f0..0x00e440`).
 *        Cài đặt điểm vết lệnh và chèn vào Cây Đỏ-Đen (`0x00e0f0..0x00e440`).
 */
bool add_tracepoint(uintptr_t base_addr, int64_t offset,
                    std::function<void(ShadowHookCpuContext*)> callback) {
    auto* closure_box = new std::function<void(ShadowHookCpuContext*)>(std::move(callback));
    uintptr_t target_instr = base_addr + static_cast<uintptr_t>(offset);
    void* stub = shadowhook_intercept_instr_addr(
        reinterpret_cast<void*>(target_instr),
        tracepoint_interceptor_trampoline,
        closure_box,
        0);
    if (stub == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag,
                            "shadowhook_intercept_instr_addr: 0x%lx failed",
                            static_cast<unsigned long>(target_instr));
        delete closure_box;
        return false;
    }

    std::lock_guard<std::mutex> lock(g_tracepoint_mutex);
    TracepointRbNode** link = &g_tracepoint_tree.end_left;
    TracepointRbNode* parent = reinterpret_cast<TracepointRbNode*>(&g_tracepoint_tree.end_left);

    while (*link != nullptr) {
        parent = *link;
        if (stub < parent->stub_token) {
            link = &parent->left;
        } else if (stub > parent->stub_token) {
            link = &parent->right;
        } else {
            parent->closure_box = closure_box;
            return true;
        }
    }

    auto* new_node = static_cast<TracepointRbNode*>(operator new(sizeof(TracepointRbNode)));
    new_node->left = nullptr;
    new_node->right = nullptr;
    new_node->parent = parent;
    new_node->is_black = (parent == reinterpret_cast<TracepointRbNode*>(&g_tracepoint_tree.end_left)) ? 1 : 0;
    new_node->stub_token = stub;
    new_node->closure_box = closure_box;
    *link = new_node;

    if (g_tracepoint_tree.begin_node->left != nullptr) {
        g_tracepoint_tree.begin_node = g_tracepoint_tree.begin_node->left;
    }
    g_tracepoint_tree.node_count++;
    return true;
}

/**
 * @brief Unhooks all registered instruction tracepoints and destroys the RB-Tree (`0x00e444..0x00e538`).
 *        Gỡ toàn bộ các điểm vết lệnh đã đăng ký và hủy Cây Đỏ-Đen (`0x00e444..0x00e538`).
 */
void clear_tracepoints() {
    std::lock_guard<std::mutex> lock(g_tracepoint_mutex);
    TracepointRbNode* end_sentinel = reinterpret_cast<TracepointRbNode*>(&g_tracepoint_tree.end_left);
    TracepointRbNode* cur = g_tracepoint_tree.begin_node;

    while (cur != end_sentinel) {
        shadowhook_unhook(cur->stub_token);
        if (cur->closure_box != nullptr) {
            delete static_cast<std::function<void(ShadowHookCpuContext*)>*>(cur->closure_box);
        }
        if (cur->right != nullptr) {
            cur = cur->right;
            while (cur->left != nullptr) {
                cur = cur->left;
            }
        } else {
            TracepointRbNode* p = cur->parent;
            while (cur != p->left) {
                cur = p;
                p = cur->parent;
            }
            cur = p;
        }
    }

    destroy_tracepoint_rbtree(g_tracepoint_tree.end_left);
    g_tracepoint_tree.begin_node = end_sentinel;
    g_tracepoint_tree.end_left = nullptr;
    g_tracepoint_tree.node_count = 0;
}

// ============================================================================
// 3. STRING & LOGGING UTILITIES / TIỆN ÍCH CHUỖI & GHI LOG
// ============================================================================

/**
 * @brief Converts `jstring` to `std::string` UTF-8 (`0x00e814..0x00e928`).
 *        Chuyển đổi `jstring` sang `std::string` UTF-8 (`0x00e814..0x00e928`).
 */
std::string convert_java_string_to_utf8(JNIEnv* env, jstring jstr) {
    if (jstr == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag,
                            "ConvertJavaStringToUTF8 called with null string.");
        return std::string();
    }
    const char* utf_chars = env->GetStringUTFChars(jstr, nullptr);
    if (utf_chars == nullptr) {
        env->ExceptionClear();
        return std::string();
    }
    std::string result(utf_chars);
    env->ReleaseStringUTFChars(jstr, utf_chars);
    env->ExceptionClear();
    return result;
}

/**
 * @brief Formats string buffer using `vsnprintf` (`0x009d9c`, `0x00ae7c`, `0x00ca08`, `0x00d020`, `0x00e574`).
 *        Định dạng bộ đệm chuỗi bằng `vsnprintf`.
 */
void format_buffer(char* buf, size_t buf_size, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vsnprintf(buf, buf_size, fmt, args);
    va_end(args);
}

/**
 * @brief `TouphicInitUtil.initNativeAlog` (`0x009400..0x009478`, 124 B).
 *        Khởi tạo `libalog.so` (`alog_write` và `alog_write_default_instance`).
 */
jboolean init_native_alog_impl(JNIEnv* /*env*/, jclass /*clazz*/) {
    if (g_alog_write_default_instance_fn != nullptr) {
        return JNI_TRUE;
    }
    void* handle = dlopen("libalog.so", RTLD_LAZY);
    if (handle == nullptr) {
        return JNI_FALSE;
    }
    void* alog_write_sym = dlsym(handle, "alog_write");
    if (alog_write_sym == nullptr) {
        return JNI_FALSE;
    }
    g_alog_write_fn = alog_write_sym;

    void* alog_default_sym = dlsym(handle, "alog_write_default_instance");
    if (alog_default_sym == nullptr) {
        return JNI_FALSE;
    }
    g_alog_write_default_instance_fn = alog_default_sym;
    return JNI_TRUE;
}

namespace {

/**
 * @brief Proxy for `av_lockmgr_register` (`0x0094e8..0x009534`, 76 B).
 *        Hàm ủy nhiệm cho `av_lockmgr_register` (`0x0094e8..0x009534`, 76 B).
 */
int av_lockmgr_register_proxy(void* /*cb*/) {
    __android_log_print(ANDROID_LOG_ERROR, kLogTag,
                        "[%s:%d] proxy av_lockmgr_register",
                        "av_lockmgr_register_proxy", 8);
    shadowhook_pop_stack(__builtin_return_address(0));
    return 0;
}

}  // namespace

/**
 * @brief `AvLockRegisterHelper.nativeIgnoreAVLockMgrRegister` (`0x00947c..0x0094e4`, 108 B).
 *        Vô hiệu hóa `av_lockmgr_register` trong `libttffmpeg.so` để tránh xung đột khóa FFmpeg.
 */
jboolean ignore_av_lockmgr_register_impl(JNIEnv* /*env*/, jclass /*clazz*/) {
    if (shadowhook_init(0, false) != 0) {
        __android_log_print(ANDROID_LOG_ERROR, kLogTag, "shadowhook_init failed !!!");
        return JNI_FALSE;
    }
    void* stub = shadowhook_hook_sym_name(
        "libttffmpeg.so",
        "av_lockmgr_register",
        reinterpret_cast<void*>(av_lockmgr_register_proxy),
        nullptr);
    return (stub != nullptr) ? JNI_TRUE : JNI_FALSE;
}

}  // namespace touphic
}  // namespace godzilla
}  // namespace platform
}  // namespace bytedance
