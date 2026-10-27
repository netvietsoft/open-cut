/**
 * @file wasm_m3_compile_exec.h
 * @brief Embedded Wasm3 Environment, Module Lifecycle & Bytecode Interpreter Engine
 *        Môi trường Wasm3 nhúng, Vòng đời Module & Máy thực thi Bytecode WebAssembly
 *
 * @details
 * Clean-room C++17 reconstruction of the embedded Wasm3 engine inside `libwasm.so`
 * (`.text 0x02268c..0x035a24`, `.data.rel.ro 0x038438..0x03b8e8`):
 * - `m3_NewEnvironment` (`0x02268c..0x0228a8`)
 * - `m3_FreeEnvironment` (`0x0228ac..0x0229e8`)
 * - `m3_NewRuntime` (`0x0229ec..0x022bbc`)
 * - `m3_FreeRuntime`
 * - `m3_ParseModule` (`0x022bc0..0x022e80`)
 * - `m3_LoadModule` (`0x022e80..0x0234fc`)
 * - `m3_CompileModule` (`0x023500..0x023620`)
 * - `m3_FreeModule` (`0x032d08..0x033004`)
 * - `c_operations[256]` (`.data.rel.ro 0x038438..0x03b438`, `12,288 bytes`)
 * - `c_operationsFC[21]` (`.data.rel.ro 0x03b438..0x03b818`)
 */

#ifndef NEXTAI_OPENCUT_LIBWASM_WASM_M3_COMPILE_EXEC_H_
#define NEXTAI_OPENCUT_LIBWASM_WASM_M3_COMPILE_EXEC_H_

#include "wasm_types.h"
#include "wasm_m3_runtime.h"

namespace vmsdk {
namespace wasm {

// ============================================================================
// 1. Core Wasm3 C API Functions ([OBSERVED] in .text 0x02268c..0x033004)
//    Các hàm C cốt lõi của Wasm3 ([QUAN SÁT ĐƯỢC] tại .text 0x02268c..0x033004)
// ============================================================================

/**
 * @brief Allocates and initializes an `M3Environment`, pre-populating the 4 primitive
 *        single-return `M3FuncType` entries (`i32`, `i64`, `f32`, `f64`, each `0x11` bytes).
 *        Cấp phát và khởi tạo `M3Environment`, đăng ký trước 4 kiểu hàm trả về đơn nguyên thủy.
 *
 * [OBSERVED] Binary address `0x02268c..0x0228a8`.
 */
M3Environment* m3_NewEnvironment() noexcept;

/**
 * @brief Frees an `M3Environment` and its canonical `M3FuncType` linked list.
 *        Giải phóng `M3Environment` và danh sách liên kết `M3FuncType`.
 *
 * [OBSERVED] Binary address `0x0228ac..0x0229e8`.
 */
void m3_FreeEnvironment(M3Environment* env) noexcept;

/**
 * @brief Canonicalizes and adds an `M3FuncType` into `M3Environment::funcTypes`.
 *        Chuẩn hóa và thêm `M3FuncType` vào danh sách kiểu hàm của `M3Environment`.
 */
M3Result Environment_AddFuncType(M3Environment* env, M3FuncType** io_funcType) noexcept;

/**
 * @brief Allocates an `M3FuncType` with `numArgs + numRets` parameter/return slots.
 *        Cấp phát `M3FuncType` với kích thước `0x10 + numArgs + numRets` byte.
 */
M3Result AllocFuncType(M3FuncType** out_funcType, uint32_t numTypes) noexcept;

/**
 * @brief Allocates and initializes an `M3Runtime` execution context.
 *        Cấp phát và khởi tạo ngữ cảnh thực thi `M3Runtime`.
 *
 * [OBSERVED] Binary address `0x0229ec..0x022bbc`.
 */
M3Runtime* m3_NewRuntime(M3Environment* env, uint32_t stackSizeInBytes, void* userdata) noexcept;

/**
 * @brief Frees an `M3Runtime`, its execution stack, linear memory, and linked modules.
 *        Giải phóng `M3Runtime`, ngăn xếp thực thi, bộ nhớ tuyến tính và các module.
 */
void m3_FreeRuntime(M3Runtime* runtime) noexcept;

/**
 * @brief Parses a raw WebAssembly binary into an `M3Module` (`0xF0` = 240 bytes).
 *        Phân tích luồng byte nhị phân WebAssembly thành cấu trúc `M3Module` (240 byte).
 *
 * [OBSERVED] Binary address `0x022bc0..0x022e80`:
 * - Allocates `0xF0` bytes via `calloc(0xF0, 1)` (`0x022be0: mov w0, #0xf0`)
 * - Initializes `name = ".unnamed"` (`0x022bfc`), `startFunction = -1` (`0x022c00: movn w8, #0`)
 * - Checks magic `0x6d736100` (`"\0asm"`) and version `0x00000001`
 * - Dispatches sections `0..11` via `.data.rel.ro 0x03b888..0x03b8e8`.
 */
M3Result m3_ParseModule(M3Environment* env,
                        M3Module** out_module,
                        const uint8_t* wasmBytes,
                        uint32_t numWasmBytes) noexcept;

/**
 * @brief Links and loads a parsed `M3Module` into an `M3Runtime`.
 *        Liên kết và nạp `M3Module` đã phân tích vào `M3Runtime`.
 *
 * [OBSERVED] Binary address `0x022e80..0x0234fc`.
 */
M3Result m3_LoadModule(M3Runtime* runtime, M3Module* module) noexcept;

/**
 * @brief Frees an `M3Module` (`0xF0` bytes) and all owned `M3Function` (`0x458` bytes),
 *        `M3Global` (`0x30` bytes), `M3DataSegment` (`0x28` bytes), and `M3CustomSection` records.
 *        Giải phóng toàn bộ bộ nhớ của `M3Module` và các cấu trúc con.
 *
 * [OBSERVED] Binary address `0x032d08..0x033004`.
 */
void m3_FreeModule(M3Module* module) noexcept;

/**
 * @brief Compiles/validates all functions in an `M3Module`.
 *        Biên dịch và kiểm tra toàn bộ các hàm trong `M3Module`.
 *
 * [OBSERVED] Binary address `0x023500..0x023620`.
 */
M3Result m3_CompileModule(M3Module* module) noexcept;

// ============================================================================
// 2. Wasm3 Opcode Info Tables & Stack-Machine Interpreter ([OBSERVED] @ 0x038438)
//    Bảng thông tin Opcode Wasm3 & Máy thông dịch ngăn xếp ([QUAN SÁT ĐƯỢC] @ 0x038438)
// ============================================================================

/**
 * @brief Returns the 256-entry primary Wasm opcode table (`c_operations` @ `0x038438..0x03b438`).
 *        Trả về bảng 256 mục mô tả opcode chính của Wasm3 (`c_operations` tại `0x038438`).
 */
const M3OpInfo* GetWasm3OpcodeTable() noexcept;

/**
 * @brief Returns the `0xFC` extended opcode table (`c_operationsFC` @ `0x03b438..0x03b818`).
 *        Trả về bảng opcode mở rộng tiền tố `0xFC` (`c_operationsFC` tại `0x03b438`).
 */
const M3OpInfo* GetWasm3OpcodeFCTable(size_t* out_count = nullptr) noexcept;

/**
 * @brief Executes a WebAssembly function body using the deterministic Wasm3 stack/slot
 *        execution semantics reconstructed from `.text 0x023c04..0x02ff80`.
 *        Thực thi thân hàm WebAssembly theo ngữ nghĩa máy ảo Wasm3 tại `.text 0x023c04..0x02ff80`.
 */
M3Result ExecuteWasmFunctionBytecode(Wasm3Module* module,
                                     M3Function* func,
                                     const std::vector<WasmVal>& args,
                                     std::vector<WasmVal>* results);

// ============================================================================
// 3. Built-in Host Import Functions ([OBSERVED] in .text 0x0357c0..0x035990)
//    Các hàm Host tích hợp sẵn (`_abort`, `_exit`, `_memcpy`, `_memmove`, `_memset`, ...)
// ============================================================================

M3Result HostImport_Abort(Wasm3Module* mod, const std::vector<WasmVal>& args, std::vector<WasmVal>* rets);
M3Result HostImport_Exit(Wasm3Module* mod, const std::vector<WasmVal>& args, std::vector<WasmVal>* rets);
M3Result HostImport_Memcpy(Wasm3Module* mod, const std::vector<WasmVal>& args, std::vector<WasmVal>* rets);
M3Result HostImport_Memmove(Wasm3Module* mod, const std::vector<WasmVal>& args, std::vector<WasmVal>* rets);
M3Result HostImport_Memset(Wasm3Module* mod, const std::vector<WasmVal>& args, std::vector<WasmVal>* rets);
M3Result HostImport_Printf(Wasm3Module* mod, const std::vector<WasmVal>& args, std::vector<WasmVal>* rets);
M3Result HostImport_ClockMs(Wasm3Module* mod, const std::vector<WasmVal>& args, std::vector<WasmVal>* rets);
M3Result HostImport_Debug(Wasm3Module* mod, const std::vector<WasmVal>& args, std::vector<WasmVal>* rets);

} // namespace wasm
} // namespace vmsdk

#endif // NEXTAI_OPENCUT_LIBWASM_WASM_M3_COMPILE_EXEC_H_
