# Clean-Room Reconstruction of `liblynx.so` (Target 120 / 169)
# Tái dựng Sạch `liblynx.so` (Mục tiêu 120 / 169 — `TASK-159` / `TASK_SO_031_liblynx`)

## 1. Binary Forensics & Overview / Pháp y Nhị phân & Tổng quan
- **Library**: `liblynx.so` (ByteDance Lynx Core Cross-Platform UI Engine: `lynx::lepus::Value`, `lynx::tasm::*`, `lynx::shell::LynxShell`, `ListContainerProxy`, and `lynx::piper::Runtime`)
- **File Size**: `3,570,952 bytes`
- **SHA-256**: `aef1876ef56f0de73666e3bf828a97d451e83de81274848c187174e8341ee16c`
- **Architecture**: ELF64 AArch64 (`EM_AARCH64`, Little-Endian)
- **Dynamic Symbols (`.dynsym` @ `0x000330`)**: `586` exported symbols & `459` imported symbols
- **Unwind Table (`.eh_frame_hdr` @ `0x08d1d0`)**: `21,675` FDEs (`0x14c000 .. 0x3400fc`)

## 2. Key AArch64 Opcode & Struct Layout Proofs / Bằng chứng Opcode AArch64 & Bố cục Struct
1. **`lynx::lepus::Value` 32-Byte ABI & Type Tags (`0x14c03c..0x14c90c`)**:
   - `Value(CreateAsUndefinedTag)` (`0x14c03c`): Stores `type_ = 1` (`Value_Undefined`) at `+0x08` (`52800028 mov w8, #1; 39002008 strb w8, [x0, #8]; D65F03C0 ret`).
   - `Value(const Value&)` (`0x14c048`): Tests `(type_ - 9) <= 4` (`51002509 sub w9, w8, #9; 7100113F cmp w9, #4`) for reference-counted types (`9=String`, `10=Array`, `11=Table`, `12=RefCounted`, `13=ByteArray`) and atomically increments `ref_count_` at `[ptr + 8]` (`885F7D09 ldxr w9, [x8]; 11000529 add w9, w9, #1; 880A7D09 stxr w10, w9, [x8]`).
   - Scalar constructors (`0x14c790..0x14c85c`): Set `type_` at `+0x08` to `0x10` (`CPointer`), `0x0e` (`CFunction`), `0x0f` (`BuiltinFunctionTable`), `8` (`Bool`), `3` (`Double`), `4` (`Int32`), `5` (`UInt32`), `6` (`Int64`), `7` (`UInt64`).
2. **`lynx::shell::ListContainerProxy` (`0x2e1bfc..0x2e1c40`) & `LynxShell::GetTasm()` (`0x2ea954`)**:
   - `ScrollByListContainer` (`0x2e1bfc`) & `ScrollToPosition` (`0x2e1c14`) load `delegate_` at `[this + 0x00]` and tail-call vtable slots `+0x00` and `+0x08`.
   - `LynxShell::GetTasm()` (`0x2ea954`): Loads `mediator_` at `[this + 0x20]` (`F9401008 ldr x8, [x0, #0x20]`) and `tasm_ptr` at `[x8 + 0x10]` (`F9400908 ldr x8, [x8, #0x10]`).
