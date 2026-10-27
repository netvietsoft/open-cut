# `libwasm.so` — Clean-Room C++17 Reconstruction & Binary Forensics Report
# Báo Cáo Giải Mã Nhị Phân & Tái Dựng Phòng Sạch Chuẩn C++17 Cho `libwasm.so`

- **Task ID**: `TASK-124-RECONSTRUCTION-LIBWASM` (Legacy: `TASK_SO_051_libwasm`, Target 85 / 169)
- **Binary Path**: `SOURCE/apktool-res/lib/arm64-v8a/libwasm.so`
- **Binary Size**: `247,792 bytes`
- **SHA-256**: `41d9f6460616d3a74ee7b490891a0661329c9ccb98d72bbfd198be97bb8b255a`
- **Architecture**: `ELF64 AArch64 (arm64-v8a)`
- **SONAME**: `libwasm.so`
- **Dependencies (`DT_NEEDED`)**: `libquick.so`, `liblog.so`, `libc++_shared.so`, `libm.so`, `libdl.so`, `libc.so`

---

## 1. Executive Summary / Tổng Quan Kiến Trúc (`[OBSERVED]`)

**EN**: `libwasm.so` is ByteDance's VMSDK / PrimJS / LepusNG WebAssembly JS Binding and Embedded **Wasm3** Interpreter Engine (`com.bytedance.vmsdk.wasm.RegisterWebAssembly`). It exposes the W3C WebAssembly JavaScript API (`WebAssembly.compile`, `WebAssembly.instantiate`, `WebAssembly.validate`, `WebAssembly.Module`, `WebAssembly.Instance`, `WebAssembly.Memory`, `WebAssembly.Table`, `WebAssembly.Global`, `WebAssembly.Function`, and Base64 extension `WebAssembly.Module.supportBase64`) into QuickJS/LepusNG (`LEPUSContext*`) backed by a complete embedded Wasm3 stack/slot virtual machine.

**VN**: `libwasm.so` là thư viện liên kết API JavaScript WebAssembly của ByteDance VMSDK / PrimJS / LepusNG kết hợp với máy ảo thông dịch **Wasm3** nhúng (`com.bytedance.vmsdk.wasm.RegisterWebAssembly`). Thư viện cung cấp đầy đủ chuẩn W3C WebAssembly JS API (`WebAssembly.compile`, `WebAssembly.instantiate`, `WebAssembly.validate`, `WebAssembly.Module`, `WebAssembly.Instance`, `WebAssembly.Memory`, `WebAssembly.Table`, `WebAssembly.Global`, `WebAssembly.Function`, và tiện ích giải mã Base64 `WebAssembly.Module.supportBase64`) vào ngữ cảnh `LEPUSContext*` của `libquick.so`.

---

## 2. ELF64 Section Map / Bản Đồ Phân Đoạn ELF64 (`[OBSERVED]`)

| Section | Virtual Address / Offset | Size (Bytes) | Description (EN / VN) |
|---|---:|---:|---|
| `.dynsym` | `0x000330` | `2,616` (`0x000A38`) | 109 symbol entries: 2 defined `STT_FUNC` exports + 103 imports from `libquick.so` & `libc.so` |
| `.rodata` | `0x006430` | `13,312` (`0x003400`) | 282 string literals, VMSDK error messages `[1001]..[1010]`, Base64 alphabet, Wasm3 traps |
| `.text` | `0x010000` | `154,152` (`0x025A28`) | AArch64 machine code (`QJSWebAssembly` @ `0x01003c..0x021880`, Wasm3 Engine @ `0x02268c..0x035990`) |
| `.plt` | `0x035A30` | `1,584` (`0x000630`) | 98 PLT trampolines (`LEPUS_*`, `calloc`, `realloc`, `free`, `__android_log_print`) |
| `.data.rel.ro` | `0x038000` | `14,576` (`0x0038F0`) | 7 `JSClassDef` structs, 5 `JSCFunctionListEntry` tables, `c_operations[256]`, `c_operationsFC[21]`, 12-entry section parser table |
| `.got` | `0x03BAD0` | `32` (`0x000020`) | Global Offset Table (`0x03BAE0` -> `0x01003c` `RegisterWebAssembly`) |
| `.bss` | `0x03C000` | `88` (`0x000058`) | 7 global `JSClassID` slots (`0x03C000..0x03C018`) & atomic initialization guards (`0x03C020..0x03C054`) |

---

## 3. AArch64 Disassembly & ABI Verification / Đối Chiếu Mã Máy AArch64 (`[OBSERVED]`)

1. **`RegisterWebAssembly` (`0x01003c`, size `4,872 bytes`)**:
   - `0x010054`: `cbz x0, #0x109f4` (`0xB4004D00`) — null check on `LEPUSContext*` (`"Register WebAssembly with invalid js context!"` @ `.rodata 0x006ea4`).
   - `0x01005c..0x01007c`: Queries `GetSettingsWithKey("vmsdk_wasm_runtime_type")` and logs warning (`mov w0, #5` = `0x528000A0` at `0x01007c`, tag `"VmsdkWasmWarn"` @ `0x007ec5`): `"[VmSdkWasm] PRISM runtime requested but not built into libwasm.so; falling back to WASM3."`.
   - `0x01020c`: `mov w0, #0x78` (`0x52800F00`) — allocates `120 bytes` for `vmsdk::InteropRuntime`.
   - `0x01026c`: `mov w0, #0x20` (`0x52800400`) — allocates `32 bytes` for `vmsdk::wasm3::Wasm3Runtime`.
2. **`Java_com_bytedance_vmsdk_wasm_RegisterWebAssembly_loadWasmFactory` (`0x0117d8`, size `12 bytes`)**:
   - `0x0117d8`: `adrp x0, #0x3b000` (`0xD0000140`)
   - `0x0117dc`: `ldr x0, [x0, #0xae0]` (`0xF9457000`) -> loads `&RegisterWebAssembly` (`0x01003c`) from `.got 0x03bae0`
   - `0x0117e0`: `ret` (`0xD65F03C0`).
3. **`m3_NewEnvironment` (`0x02268c`)**:
   - `0x022770`: `mov w0, #0x11` (`0x52800220`) — allocates `17 bytes` (`0x11`) via `calloc(0x11, 1)` for each canonical 1-return 0-arg `M3FuncType` (`i32=1`, `i64=2`, `f32=3`, `f64=4`).
4. **`m3_ParseModule` (`0x022bc0`)**:
   - `0x022be0`: `mov w0, #0xf0` (`0x52801E00`) — allocates `240 bytes` (`0xF0`) for `M3Module`.
   - `0x022c00`: `movn w8, #0` (`0x92800008`) — initializes `module->startFunction = -1`.
   - Dispatches sections `0..11` through `.data.rel.ro 0x03b888..0x03b8e8`.
5. **`m3_FreeModule` (`0x032d08`)**:
   - `0x032d30`: `mov w21, #0x458` (`0x52808B15`) — iterates over `module->functions` with exact `M3Function` stride `0x458` (`1,112 bytes`).

---

## 4. Reconstructed Source Files / Danh Sách Tập Tin Mã Nguồn Tái Dựng

| File | Size (Bytes) | Role (EN / VN) |
|---|---:|---|
| [`wasm_types.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libwasm/wasm_types.h) | `38,646` | ELF64 offsets, QuickJS `JSClassDef` / `JSCFunctionListEntry`, `WASMGCPersistent`, `M3Module` (`0xF0` B), `M3Function` (`0x458` B), `M3OpInfo` (`0x30` B) |
| [`wasm_qjs_bindings.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libwasm/wasm_qjs_bindings.h) | `18,634` | `QJSWebAssembly`, `QJSWasmModule`, `QJSWasmInstance`, `QJSWasmMemory`, `QJSWasmTable`, `QJSWasmGlobal`, `QJSWasmFunction` declarations |
| [`wasm_qjs_bindings.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libwasm/wasm_qjs_bindings.cpp) | `78,270` | Full implementation of `RegisterWebAssembly` (`0x01003c`), JNI `loadWasmFactory` (`0x0117d8`), and all 7 QuickJS classes |
| [`wasm_m3_runtime.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libwasm/wasm_m3_runtime.h) | `19,938` | `InteropRuntime` (`0x78` B), `Wasm3Runtime` (`0x20` B), LEB128 decoders, and 12 section parsers |
| [`wasm_m3_runtime.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libwasm/wasm_m3_runtime.cpp) | `59,401` | Implementation of LEB128 decoders, 12 Wasm section parsers (`0x033008..0x035670`), and runtime object wrappers |
| [`wasm_m3_compile_exec.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libwasm/wasm_m3_compile_exec.h) | `7,605` | Declarations for `m3_NewEnvironment`, `m3_ParseModule`, `m3_LoadModule`, `m3_FreeModule`, `c_operations[256]`, and host imports |
| [`wasm_m3_compile_exec.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libwasm/wasm_m3_compile_exec.cpp) | `87,602` | Full Wasm3 bytecode interpreter (`0x00..0xFC`), `c_operations[256]`, `c_operationsFC[21]`, and 8 host imports |
| [`wasm_interface.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libwasm/wasm_interface.h) | `2,490` | Unified public header & self-test report structure |
| [`wasm_pseudocode.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libwasm/wasm_pseudocode.cpp) | `18,985` | End-to-end Wasm binary synthesis & verification suite `RunLibWasmSelfTest()` |
