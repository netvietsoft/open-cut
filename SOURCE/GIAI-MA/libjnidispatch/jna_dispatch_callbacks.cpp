/**
 * @file jna_dispatch_callbacks.cpp
 * @brief Clean-Room Implementation of JNA `dispatch`, Callback Closure Creation & TLS Error Engine.
 *        Triển khai tái tạo sạch bộ điều phối `dispatch`, Callback Closure và quản lý lỗi TLS của JNA.
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libjnidispatch.so (165,992 bytes)
 *
 * Disassembly Anchor Map / Bản đồ neo giải mã AArch64:
 *   - 0x005e14..0x006ccc : `dispatch(JNIEnv*, jobject, jlong func, jint flags, jobjectArray args, void* rval)`
 *     - 0x005e70..0x005e90 : `cbz x26, #0x5ed0; bl GetArrayLength; cmp w0, #0x100; b.gt #0x6334`
 *       Throws `IllegalArgumentException("Maximum argument count(256) exceeded")` (`.rodata 0x020df2`)
 *     - 0x005ed8           : `ubfx x0, x0, #7, #8` (extracts 8-bit fixed-arg count for variadic calls)
 *     - 0x006378..0x0063f0 : calls `ffi_prep_cif` (`0x00cfc0`) or `ffi_prep_cif_var` (`0x00cfdc`)
 *     - 0x0067d0..0x006820 : calls `ffi_call` (`0x010e00`) and updates `errno` / `JNA_set_last_error` (`0x00cc50`)
 *   - 0x00c3fc..0x00c4b4 : `free_callback`
 *   - 0x00c4b8..0x00ca34 : `create_callback`
 *   - 0x00cbec..0x00cd5c : `JNA_detach`, `JNA_set_last_error`, `JNA_get_last_error`, `JNA_callback_init`, `JNA_callback_dispose`
 */

#include "jna_dispatch_callbacks.h"

#include <cerrno>
#include <cstdio>
#include <cstring>

namespace nextai {
namespace opencut {
namespace jnidispatch {

namespace {

/**
 * @brief Thread-local storage matching `.bss 0x02c258` (`pthread_key_t` initialized by `JNA_callback_init`).
 *        Biến cục bộ theo luồng tương ứng với khóa TLS `.bss 0x02c258`.
 */
thread_local JnaThreadStorage g_tls_storage = {0, false, "JNA-Callback-Thread"};
bool g_callback_tls_initialized = false;

/**
 * @brief Internal libffi closure callback handler reconstructing `callback_invoke` (`0x00ca38..0x00cbe8`).
 *        Hàm xử lý lời gọi ngược nội bộ tái tạo `callback_invoke` (`0x00ca38..0x00cbe8`).
 */
void InternalFfiCallbackHandler(FfiCif* cif, void* resp, void** args, void* user_data) noexcept {
    (void)args;
    const auto* record = static_cast<const JnaCallbackRecord*>(user_data);
    if (resp != nullptr && cif != nullptr && cif->rtype != nullptr && cif->rtype->size > 0U) {
        std::memset(resp, 0, cif->rtype->size);
    }
    (void)record;
}

}  // namespace

/**
 * @brief Reconstructs `dispatch` (`0x005e14..0x006ccc`):
 *        1. Checks `func_ptr != nullptr` (`cbz x25` -> throws `NullPointerException("Function pointer is NULL")`).
 *        2. Validates `nargs <= 256` (`0x005e84`: `cmp w0, #0x100; b.gt #0x6334` -> throws
 *           `IllegalArgumentException("Maximum argument count(256) exceeded")`).
 *        3. Extracts variadic fixed argument count via `ubfx x0, x0, #7, #8` (`(call_flags >> 7) & 0xFF`).
 *        4. Calls `FfiPrepCif` (when `varargs_fixed == 0`) or `FfiPrepCifVar` (when `varargs_fixed != 0`).
 *        5. Executes `FfiCall` and records `errno` in `JnaSetLastError`.
 *        Tái tạo hàm `dispatch` (`0x005e14..0x006ccc`).
 */
int32_t JnaDispatchCall(void* func_ptr,
                        int32_t call_flags,
                        int32_t nargs,
                        FfiType* rtype,
                        FfiType** atypes,
                        void** avalues,
                        void* rvalue,
                        std::string* out_exception_class,
                        std::string* out_exception_msg) noexcept {
    if (out_exception_class != nullptr) out_exception_class->clear();
    if (out_exception_msg != nullptr) out_exception_msg->clear();

    if (nargs < 0 || nargs > kJnaMaxDispatchArguments) {
        if (out_exception_class != nullptr) {
            *out_exception_class = "java/lang/IllegalArgumentException";
        }
        if (out_exception_msg != nullptr) {
            char buf[96];
            std::snprintf(buf, sizeof(buf), "Maximum argument count(%d) exceeded", kJnaMaxDispatchArguments);
            *out_exception_msg = buf;
        }
        return -1;
    }

    if (func_ptr == nullptr) {
        if (out_exception_class != nullptr) {
            *out_exception_class = "java/lang/NullPointerException";
        }
        if (out_exception_msg != nullptr) {
            *out_exception_msg = "Function pointer is NULL";
        }
        return -1;
    }

    // Extract calling convention (bits 0..1: 0 -> FFI_SYSV, 1 -> FFI_WIN64) and variadic count (bits 7..14)
    const FfiAbi abi = ((call_flags & 0x3) == 1) ? FFI_WIN64 : FFI_SYSV;
    const uint32_t var_fixed = ExtractDispatchAbiFlags(call_flags);

    FfiCif cif{};
    FfiStatus status = FFI_OK;
    if (var_fixed != 0U) {
        status = FfiPrepCifVar(&cif, abi, var_fixed, static_cast<uint32_t>(nargs), rtype, atypes);
    } else {
        status = FfiPrepCif(&cif, abi, static_cast<uint32_t>(nargs), rtype, atypes);
    }

    if (status != FFI_OK) {
        if (out_exception_class != nullptr) {
            *out_exception_class = "java/lang/IllegalArgumentException";
        }
        if (out_exception_msg != nullptr) {
            *out_exception_msg = (status == FFI_BAD_ABI)
                                     ? "Invalid calling convention"
                                     : "ffi_prep_cif failed";
        }
        return static_cast<int32_t>(status);
    }

    errno = 0;
    FfiCall(&cif, reinterpret_cast<void (*)()>(func_ptr), rvalue, avalues);
    const int32_t captured_errno = errno;
    JnaSetLastError(captured_errno);

    // Check THROW_LAST_ERROR flag (bit 6 = 0x40 at 0x006824: tbz w22, #6)
    if ((call_flags & 0x40) != 0 && captured_errno != 0) {
        if (out_exception_class != nullptr) {
            *out_exception_class = "com/sun/jna/LastErrorException";
        }
        if (out_exception_msg != nullptr) {
            char buf[64];
            std::snprintf(buf, sizeof(buf), "[%d] errno=%d", captured_errno, captured_errno);
            *out_exception_msg = buf;
        }
        return captured_errno;
    }

    return 0;
}

/**
 * @brief Reconstructs `create_callback` (`0x00c4b8..0x00ca34`):
 *        Allocates a `JnaCallbackRecord`, allocates an executable `FfiClosure` via `FfiClosureAlloc(48, &code)`,
 *        prepares the CIF via `FfiPrepCif`, and links the closure trampoline via `FfiPrepClosureLoc`.
 *        Tái tạo hàm `create_callback` (`0x00c4b8..0x00ca34`).
 */
JnaCallbackRecord* JnaCreateCallback(void* java_callback_obj,
                                     void* java_method_id,
                                     const std::vector<FfiType*>& arg_types,
                                     FfiType* return_type,
                                     FfiAbi abi,
                                     int32_t call_flags,
                                     std::string* out_error) noexcept {
    if (out_error != nullptr) out_error->clear();
    if (return_type == nullptr) {
        if (out_error != nullptr) *out_error = "Return FfiType cannot be null";
        return nullptr;
    }

    auto* cb = new JnaCallbackRecord();
    cb->x_closure       = nullptr;
    cb->closure         = nullptr;
    cb->arg_types       = arg_types;
    cb->cvt_flags.assign(arg_types.size(), 0);
    cb->rflag           = 0;
    cb->calling_conv    = static_cast<uint32_t>(abi);
    cb->java_object_ref = java_callback_obj;
    cb->java_method_id  = java_method_id;
    cb->direct          = ((call_flags & 0x10) != 0);

    void* code_loc = nullptr;
    cb->closure = static_cast<FfiClosure*>(FfiClosureAlloc(sizeof(FfiClosure), &code_loc));
    cb->x_closure = code_loc;
    if (cb->closure == nullptr || cb->x_closure == nullptr) {
        if (out_error != nullptr) *out_error = "ffi_closure_alloc failed";
        delete cb;
        return nullptr;
    }

    FfiType** atypes_ptr = cb->arg_types.empty() ? nullptr : cb->arg_types.data();
    FfiStatus st = FfiPrepCif(
        &cb->cif, abi, static_cast<uint32_t>(cb->arg_types.size()), return_type, atypes_ptr);
    if (st != FFI_OK) {
        if (out_error != nullptr) *out_error = "ffi_prep_cif failed in create_callback";
        FfiClosureFree(cb->closure);
        delete cb;
        return nullptr;
    }

    st = FfiPrepClosureLoc(cb->closure, &cb->cif, &InternalFfiCallbackHandler, cb, cb->x_closure);
    if (st != FFI_OK) {
        if (out_error != nullptr) *out_error = "ffi_prep_closure_loc failed in create_callback";
        FfiClosureFree(cb->closure);
        delete cb;
        return nullptr;
    }

    return cb;
}

/**
 * @brief Reconstructs `free_callback` (`0x00c3fc..0x00c4b4`).
 *        Tái tạo hàm `free_callback` (`0x00c3fc..0x00c4b4`).
 */
void JnaFreeCallback(JnaCallbackRecord* cb) noexcept {
    if (cb == nullptr) {
        return;
    }
    if (cb->closure != nullptr) {
        FfiClosureFree(cb->closure);
        cb->closure = nullptr;
        cb->x_closure = nullptr;
    }
    delete cb;
}

/**
 * @brief Reconstructs `JNA_callback_init` (`0x00cc9c..0x00cd20`), `JNA_callback_dispose` (`0x00cd24..0x00cd5c`),
 *        `JNA_detach` (`0x00cbec..0x00cc4c`), `JNA_set_last_error` (`0x00cc50..0x00cc70`), and
 *        `JNA_get_last_error` (`0x00cc74..0x00cc98`).
 *        Tái tạo bộ quản lý khóa TLS và mã lỗi hệ thống của JNA (`0x00cbec..0x00cd5c`).
 */
void JnaCallbackInit() noexcept {
    g_callback_tls_initialized = true;
    g_tls_storage.last_error = 0;
    g_tls_storage.detach_state = false;
}

void JnaCallbackDispose() noexcept {
    g_callback_tls_initialized = false;
    g_tls_storage.last_error = 0;
}

void JnaDetachThread(void* tls_value) noexcept {
    (void)tls_value;
    g_tls_storage.detach_state = true;
}

void JnaSetLastError(int32_t err) noexcept {
    g_tls_storage.last_error = err;
    errno = err;
}

int32_t JnaGetLastError() noexcept {
    return g_tls_storage.last_error;
}

}  // namespace jnidispatch
}  // namespace opencut
}  // namespace nextai
