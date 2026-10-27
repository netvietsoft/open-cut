# BÁO CÁO NGHIỆM THU TÁI DỰNG: `libwasm.so` (`TASK-124-RECONSTRUCTION-LIBWASM`)
# RECONSTRUCTION ACCEPTANCE REPORT: `libwasm.so` (`TASK_SO_051_libwasm`)

- **Target Binary / Thư viện mục tiêu**: `libwasm.so` (Target 85 / 169)
- **Binary Size / Kích thước**: `247,792 bytes`
- **SHA-256**: `41d9f6460616d3a74ee7b490891a0661329c9ccb98d72bbfd198be97bb8b255a`
- **Reconstructed C++17/H Size / Dung lượng mã nguồn tái dựng**: `331,571 bytes` (9 files, 0 stubs)
- **Verification Status / Trạng thái đối kháng**: `VERIFIED_AND_ACCEPTED`

## 1. Summary of Reconstructed Subsystems / Tóm Tắt Các Phân Hệ Đã Tái Dựng

1. **QuickJS / LepusNG WebAssembly Bindings (`wasm_qjs_bindings.h/.cpp`)**:
   - `RegisterWebAssembly` (`0x01003c`, `4,872 bytes`) & JNI `Java_com_bytedance_vmsdk_wasm_RegisterWebAssembly_loadWasmFactory` (`0x0117d8`, `12 bytes`).
   - All 7 `JSClassDef` classes in `.data.rel.ro 0x0380b0..0x038378` (`WebAssembly`, `WebAssembly.Module`, `WebAssembly.Instance`, `WebAssembly.Memory`, `WebAssembly.Table`, `WebAssembly.Global`, `WebAssembly.Function`) and `.bss 0x03c000..0x03c054` class IDs.
   - Base64 Wasm binary decoding (`WebAssembly.Module.supportBase64` @ `0x01f2e4`, alphabet @ `.rodata 0x007da7`).
2. **VMSDK `InteropRuntime`, `Wasm3Runtime` & 12 Section Parsers (`wasm_m3_runtime.h/.cpp`)**:
   - `InteropRuntime` (`0x78 = 120 bytes` @ `0x01020c`) and `Wasm3Runtime` (`0x20 = 32 bytes` @ `0x01026c`).
   - Unsigned & signed LEB128 decoders (`ReadLEB_u32`, `ReadLEB_u64`, `ReadLEB_i32`, `ReadLEB_i64`) and all 12 section parsers (`ParseSection_Custom`..`ParseSection_Data` at `.data.rel.ro 0x03b888..0x03b8e8`).
3. **Embedded Wasm3 Engine & Bytecode Interpreter (`wasm_m3_compile_exec.h/.cpp`)**:
   - `m3_NewEnvironment` (`0x02268c`), `m3_ParseModule` (`0x022bc0`, `0xF0 = 240B` `M3Module`), `m3_LoadModule` (`0x022e80`), `m3_FreeModule` (`0x032d08`, `0x458 = 1,112B` `M3Function`), `c_operations[256]` (`.data.rel.ro 0x038438..0x03b438`), `c_operationsFC[21]` (`0x03b438..0x03b818`), and 8 host imports (`_abort`, `_exit`, `_memcpy`, `_memmove`, `_memset`, `printf`, `clock_ms`, `_debug`).
