/**
 * @file jna_dispatch_callbacks.h
 * @brief Clean-Room Header for JNA `dispatch`, Callback Closure Creation & Thread-Local Error Engine.
 *        Header tái tạo sạch bộ điều phối `dispatch`, tạo Callback Closure và quản lý lỗi theo luồng của JNA.
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libjnidispatch.so
 *   Addresses covered / Phạm vi địa chỉ:
 *     - 0x005e14..0x006ccc : `dispatch` (JNA core dynamic invocation engine, max 256 args)
 *     - 0x00c3fc..0x00c4b4 : `free_callback` (releases `ffi_closure`, `cif`, `arg_types`, and global refs)
 *     - 0x00c4b8..0x00ca34 : `create_callback` (allocates `callback` struct + `ffi_closure_alloc` + `ffi_prep_closure_loc`)
 *     - 0x00cbec..0x00cc4c : `JNA_detach` (TLS destructor detaching current native thread from JVM)
 *     - 0x00cc50..0x00cc70 : `JNA_set_last_error`
 *     - 0x00cc74..0x00cc98 : `JNA_get_last_error`
 *     - 0x00cc9c..0x00cd20 : `JNA_callback_init` (`pthread_key_create(&key, JNA_detach)`)
 *     - 0x00cd24..0x00cd5c : `JNA_callback_dispose` (`pthread_key_delete(key)`)
 */

#ifndef NEXTAI_OPENCUT_JNIDISPATCH_JNA_DISPATCH_CALLBACKS_H_
#define NEXTAI_OPENCUT_JNIDISPATCH_JNA_DISPATCH_CALLBACKS_H_

#include "jnidispatch_types.h"
#include "libffi_aarch64_engine.h"

#include <cstddef>
#include <cstdint>
#include <vector>

namespace nextai {
namespace opencut {
namespace jnidispatch {

/**
 * @brief Reconstructed JNA Callback Descriptor (`callback` struct in `callback.c`, allocated at `0x00c5ac`).
 *        Cấu trúc mô tả Callback của JNA (được cấp phát tại `0x00c5ac` trong `create_callback`).
 */
struct JnaCallbackRecord {
    void*                  x_closure;       // +0x00: executable closure trampoline pointer (`*code`)
    FfiClosure*            closure;         // +0x08: writable `ffi_closure*` from `ffi_closure_alloc`
    FfiCif                 cif;             // +0x10..0x2f: `ffi_cif` (32 bytes)
    FfiCif                 java_cif;        // +0x30..0x4f: secondary `ffi_cif` for direct/Java invocation
    std::vector<FfiType*>  arg_types;       // argument `ffi_type*` vector
    std::vector<int32_t>   cvt_flags;       // conversion flags per argument
    int32_t                rflag;           // return value conversion flag
    uint32_t               calling_conv;    // ABI (`FFI_SYSV = 1` or `FFI_WIN64 = 2`)
    void*                  java_object_ref; // GlobalRef to Java Callback instance
    void*                  java_method_id;  // `jmethodID` of callback method
    bool                   direct;          // Direct callback trampoline flag
};

/**
 * @brief Extracts the 8-bit calling-convention field from JNA dispatch `flags`
 *        (`0x005ed8`: `ubfx x0, x0, #7, #8`).
 *        Trích xuất trường quy ước gọi 8-bit từ `flags` của `dispatch` (`ubfx x0, x0, #7, #8`).
 */
inline uint32_t ExtractDispatchAbiFlags(int32_t call_flags) noexcept {
    return (static_cast<uint32_t>(call_flags) >> 7U) & 0xFFU;
}

/**
 * @brief Reconstructs `dispatch` (`0x005e14..0x006ccc`):
 *        Validates `nargs <= 256` (`0x005e84: cmp w0, #0x100; b.gt #0x6334`), resolves `FfiType*`
 *        for return type and arguments, calls `FfiPrepCif` / `FfiPrepCifVar`, invokes `FfiCall`,
 *        and captures last error if `(call_flags & 0x40)` (`THROW_LAST_ERROR`) is set.
 *        Tái tạo hàm điều phối `dispatch` (`0x005e14..0x006ccc`).
 */
int32_t JnaDispatchCall(void* func_ptr,
                        int32_t call_flags,
                        int32_t nargs,
                        FfiType* rtype,
                        FfiType** atypes,
                        void** avalues,
                        void* rvalue,
                        std::string* out_exception_class,
                        std::string* out_exception_msg) noexcept;

/**
 * @brief Reconstructs `create_callback` (`0x00c4b8..0x00ca34`) and `free_callback` (`0x00c3fc..0x00c4b4`).
 *        Tái tạo hàm khởi tạo `create_callback` (`0x00c4b8`) và giải phóng `free_callback` (`0x00c3fc`).
 */
JnaCallbackRecord* JnaCreateCallback(void* java_callback_obj,
                                     void* java_method_id,
                                     const std::vector<FfiType*>& arg_types,
                                     FfiType* return_type,
                                     FfiAbi abi,
                                     int32_t call_flags,
                                     std::string* out_error) noexcept;

void JnaFreeCallback(JnaCallbackRecord* cb) noexcept;

/**
 * @brief Reconstructs `JNA_callback_init` (`0x00cc9c`), `JNA_callback_dispose` (`0x00cd24`),
 *        `JNA_detach` (`0x00cbec`), `JNA_set_last_error` (`0x00cc50`), and `JNA_get_last_error` (`0x00cc74`).
 *        Tái tạo các hàm quản lý TLS và mã lỗi hệ thống của JNA (`0x00cbec..0x00cd5c`).
 */
void    JnaCallbackInit() noexcept;
void    JnaCallbackDispose() noexcept;
void    JnaDetachThread(void* tls_value) noexcept;
void    JnaSetLastError(int32_t err) noexcept;
int32_t JnaGetLastError() noexcept;

}  // namespace jnidispatch
}  // namespace opencut
}  // namespace nextai

#endif  // NEXTAI_OPENCUT_JNIDISPATCH_JNA_DISPATCH_CALLBACKS_H_
