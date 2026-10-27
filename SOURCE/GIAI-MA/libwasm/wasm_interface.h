/**
 * @file wasm_interface.h
 * @brief Public Unified Interface Header for `libwasm.so` Reconstruction
 *        Header giao diện hợp nhất công khai cho bản tái dựng `libwasm.so`
 *
 * @details
 * Aggregates all reconstructed subsystems of `libwasm.so` (`247,792 bytes`,
 * SHA-256 `41d9f6460616d3a74ee7b490891a0661329c9ccb98d72bbfd198be97bb8b255a`):
 * 1. `wasm_types.h`: ELF64 metadata, QuickJS/LepusNG ABI structs (`JSClassDef`,
 *    `JSCFunctionListEntry`, `WASMGCPersistent`), Wasm3 ABI structs (`M3Environment`,
 *    `M3Runtime`, `M3Module` (`0xF0` B), `M3Function` (`0x458` B), `M3Global` (`0x30` B),
 *    `M3DataSegment` (`0x28` B), `M3OpInfo` (`0x30` B)).
 * 2. `wasm_m3_runtime.h`: `InteropRuntime` (`0x78` B), `Wasm3Runtime` (`0x20` B),
 *    LEB128 decoders, and 12 Wasm section parsers (`.data.rel.ro 0x03b888..0x03b8e8`).
 * 3. `wasm_m3_compile_exec.h`: `m3_NewEnvironment` (`0x02268c`), `m3_ParseModule` (`0x022bc0`),
 *    `m3_LoadModule` (`0x022e80`), `m3_FreeModule` (`0x032d08`), `c_operations[256]`
 *    (`.data.rel.ro 0x038438..0x03b438`), and Wasm3 stack-machine interpreter.
 * 4. `wasm_qjs_bindings.h`: `RegisterWebAssembly` (`0x01003c`),
 *    `Java_com_bytedance_vmsdk_wasm_RegisterWebAssembly_loadWasmFactory` (`0x0117d8`),
 *    and all 7 `WebAssembly.*` QuickJS/LepusNG classes.
 */

#ifndef NEXTAI_OPENCUT_LIBWASM_WASM_INTERFACE_H_
#define NEXTAI_OPENCUT_LIBWASM_WASM_INTERFACE_H_

#include "wasm_types.h"
#include "wasm_m3_runtime.h"
#include "wasm_m3_compile_exec.h"
#include "wasm_qjs_bindings.h"

namespace vmsdk {
namespace wasm {

/**
 * @brief Diagnostic report structure returned by `RunLibWasmSelfTest()`.
 *        Cấu trúc báo cáo chẩn đoán trả về bởi hàm tự kiểm tra `RunLibWasmSelfTest()`.
 */
struct LibWasmSelfTestReport {
    bool     passed                     = false;
    uint32_t total_checks               = 0;
    uint32_t passed_checks              = 0;
    int32_t  fib10_result               = 0;
    int32_t  linear_mem_sum_result      = 0;
    int32_t  indirect_call_result       = 0;
    uint32_t custom_section_byte_length = 0;
    char     failure_reason[256]        = {0};
};

/**
 * @brief Runs the complete deterministic verification suite for `libwasm.so`.
 *        Chạy bộ kiểm thử xác minh tất định toàn diện cho `libwasm.so`.
 */
LibWasmSelfTestReport RunLibWasmSelfTest();

} // namespace wasm
} // namespace vmsdk

#endif // NEXTAI_OPENCUT_LIBWASM_WASM_INTERFACE_H_
