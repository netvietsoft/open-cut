# Clean-Room Reconstruction of `libpythonA.so` (Target 118 / 169)
# Tái dựng Sạch `libpythonA.so` (Mục tiêu 118 / 169 — `TASK-157` / `TASK_SO_046_libpythonA`)

## 1. Binary Forensics & Overview / Pháp y Nhị phân & Tổng quan
- **Library**: `libpythonA.so` (ByteDance Custom CPython 3.x + Drogon JIT Specialization, `BDPythonVM` Sub-Interpreters, `BDPythonImportEncryptName` NEON/Scalar Cipher & `BDPyDebugger`)
- **File Size**: `2,229,160 bytes`
- **SHA-256**: `adac15b692d2291567fdf9f43ae7d9f5e1d7cfec70c8db6c9b85109118cd92fe`
- **Architecture**: ELF64 AArch64 (`EM_AARCH64`, Little-Endian)
- **Dynamic Symbols (`.dynsym` @ `0x007c58`)**: `1,998` exported symbols & `222` imported symbols
- **Unwind Table (`.eh_frame_hdr` @ `0x1c9550`)**: `4,320` FDEs (`0x05d8f0 .. 0x1a20bc`)

## 2. Key AArch64 Opcode & Mathematical Proofs / Bằng chứng Opcode AArch64 & Toán học
1. **`BDPythonImportEncryptName` (`0x1192d4..0x119424`, 336 bytes — NEON + Scalar Base-26 XOR-7 Bijection)**:
   - Allocates `calloc(1, (len << 1) | 1)` (`0x1192ec: B37FFA81 bfi x1, x20, #1, #0x3f`).
   - **NEON 16-Byte Vector Loop (`0x11936c..0x1193c0`)**: Loads `v0 = 7` (`4F00E4E0 movi v0.16b, #7`), `v1 = 0x4f` (`4F02E5E1 movi v1.16b, #0x4f`), `v2 = 26` (`4F00E742 movi v2.16b, #0x1a`), `v3 = 'A'` (`4F02E423 movi v3.16b, #0x41`). Computes `x = b ^ 7`, `q = (x * 79) >> 11 = x / 26`, `r = x - 26 * q = x % 26`, and interleaves `out[2*i] = r + 'A'` and `out[2*i+1] = q + 'A'` via `4C0081C6 st2 {v6.16b, v7.16b}, [x14]`.
   - **Scalar Tail Loop (`0x1193cc..0x119414`)**: Uses 32-bit reciprocal `0x4ec4ec4f >> 35` (`529D89EB mov w11, #0xec4f; 72A9D88B movk w11, #0x4ec4, lsl #16`).
2. **`PyToken_OneChar` (`0x05db1c..0x05dbfc`) & `PyObject_Type` / `PyObject_Size` (`0x05e130..0x05e1d8`)**:
   - `PyToken_OneChar`: Subtracts `0x25` (`'%'`: `51009408 sub w8, w0, #0x25`), checks `<= 0x59` (`7101651F cmp w8, #0x59`), and dispatches via `.rodata` byte table at `0x1a20c0`.
   - `PyObject_Type` (`0x05e130`): Loads `ob_type` at `+0x08` (`F9400400 ldr x0, [x0, #8]`) and increments `ob_refcnt` at `+0x00`.
3. **`Drogon_PyNumber_*` Type-Specializing Operators (`0x05fb9c..0x0602a8`)**:
   - Dispatches `PyNumberMethods` slot offsets (`0x78` Or, `0x70` Xor, `0x68` And, `0x58` Lshift, `0x60` Rshift, `0x08` Subtract, `0x20` Divmod) while recording type-specialization feedback for Drogon.
