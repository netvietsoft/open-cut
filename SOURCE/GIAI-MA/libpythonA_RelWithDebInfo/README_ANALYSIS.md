# Clean-Room Reconstruction of `libpythonA_RelWithDebInfo.so` (Target 119 / 169)
# Tái dựng Sạch `libpythonA_RelWithDebInfo.so` (Mục tiêu 119 / 169 — `TASK-158` / `TASK_SO_047_libpythonA_RelWithDebInfo`)

## 1. Binary Forensics & Overview / Pháp y Nhị phân & Tổng quan
- **Library**: `libpythonA_RelWithDebInfo.so` (ByteDance RelWithDebInfo Build of Custom CPython 3.x + `BDPythonVM` Sub-Interpreter Pool, Stuck Callback & Frozen Import Engine)
- **File Size**: `2,229,160 bytes`
- **SHA-256**: `adac15b692d2291567fdf9f43ae7d9f5e1d7cfec70c8db6c9b85109118cd92fe`
- **Architecture**: ELF64 AArch64 (`EM_AARCH64`, Little-Endian)
- **Dynamic Symbols (`.dynsym` @ `0x007c58`)**: `1,998` exported symbols & `222` imported symbols
- **Unwind Table (`.eh_frame_hdr` @ `0x1c9550`)**: `4,320` FDEs (`0x05d8f0 .. 0x1a20bc`; shards cover complementary FDEs `[2000 .. 4319]`)

## 2. Key AArch64 Opcode & Struct Layout Proofs / Bằng chứng Opcode AArch64 & Bố cục Struct
1. **`BD_PyInterpreterState_SetStuckCallback` (`0x1320e0..0x1320ec`) & `BD_Py_CheckStuckCallback` (`0x1320f0..0x132154`)**:
   - `SetStuckCallback` (`0x1320e0`): Loads 32-bit offset `0x0001b508` (`111,880 bytes`: `5296A108 mov w8, #0xb508; 72A00028 movk w8, #1, lsl #16`) and stores callback pointer `x1` into `[interp + 0x1b508]` (`F8286801 str x1, [x0, x8]`).
   - `CheckStuckCallback` (`0x1320f0`): Loads `tstate->interp` at `+0x10` (`F9400800 ldr x0, [x0, #0x10]`), loads `[interp + 0x1b508]` (`F8686801 ldr x1, [x0, x8]`), and tail-calls `D61F0020 br x1`.
2. **`BDPythonVMDispatchCreateSubInterpreters` (`0x1042a4..0x104358`) & `BDPythonVMDispatchGetInterperter` (`0x10435c..0x104430`)**:
   - `GetInterperter` (`0x10435c`) computes `rand() % (count + 1)` (`110006A8 add w8, w21, #1; 1AC80E69 sdiv w9, w19, w8; 1B08CD28 msub w8, w9, w8, w19`) and checks the atomic busy flag at `[interp + 0x278]` (`9109E008 add x8, x0, #0x278; 88DFFD08 ldar w8, [x8]; 340002A8 cbz w8, #0x104420`).
