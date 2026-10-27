# Clean-Room Reconstruction of `libkrypton.so` (Target 115 / 169)
# Tái dựng Sạch `libkrypton.so` (Mục tiêu 115 / 169 — `TASK-154` / `TASK_SO_032_libkrypton`)

## 1. Binary Forensics & Overview / Pháp y Nhị phân & Tổng quan
- **Library**: `libkrypton.so` (ByteDance Lynx `lynx::canvas::*` Krypton 2D/WebGL Canvas, `DataHolder`, `CanvasResourceProvider`, `CanvasApp`, `RemoteBridge`, and `RemoteEnvImpl` Engine)
- **File Size**: `1,674,432 bytes`
- **SHA-256**: `98f116548e87179434692198a52cc6ddbf1bfddf89d271c8b09d53b3e2bace31`
- **Architecture**: ELF64 AArch64 (`EM_AARCH64`, Little-Endian)
- **Dynamic Symbols (`.dynsym` @ `0x000330`)**: `345` exported symbols & `490` imported symbols
- **Unwind Table (`.eh_frame_hdr` @ `0x057848`)**: `9,255` FDEs (`0x0a6c30 .. 0x188740`)

## 2. Key AArch64 Opcode & Struct Layout Proofs / Bằng chứng Opcode AArch64 & Bố cục Struct
1. **`lynx::canvas::DataHolder` (`0x0a8824..0x0a8fec`, `0x20 = 32 bytes`)**:
   - `MakeWithProc` (`0x0a8f20..0x0a8f5c`) allocates `0x20` (`32 bytes`, `52800400 mov w0, #0x20`) and stores `(data_, size_)` at `+0x00..+0x08` (`A9005416 stp x22, x21, [x0]`) and `(release_ctx_, release_proc_)` at `+0x10..+0x18` (`A9014C14 stp x20, x19, [x0, #0x10]`).
   - `DataHolder::C1(const void*, size_t, ReleaseProc)` (`0x0a8f60`): `A9000801 stp x1, x2, [x0]`, `A9010C1F stp xzr, x3, [x0, #0x10]`, `D65F03C0 ret`.
   - `DataHolder::~DataHolder()` (`0x0a8f78..0x0a8f90`): Loads `release_proc_` at `[x0, #0x18]` (`F9400C02 ldr x2, [x0, #0x18]`), checks non-null (`B40000A2 cbz x2, #0xa8f90`), loads `data_` (`F9400008 ldr x8, [x0]`) and `release_ctx_` (`F9400801 ldr x1, [x0, #0x10]`), and tail-calls `D61F0040 br x2`.
2. **`lynx::canvas::LogMessage` (`0x0a8fec..0x0a90f8`) & `ThreadAssert` (`0x0a9ddc..0x0a9ee0`)**:
   - `LogMessage::LogMessage` (`0x0a8fec`) stores `file_` at `+0x00` (`F9000001 str x1, [x0]`), `(line_, level_)` at `+0x08..+0x0c` (`29010C02 stp w2, w3, [x0, #8]`), and constructs `std::ostringstream` at `+0x10` (`91004000 add x0, x0, #0x10`).
   - `ThreadAssert::Assert` (`0x0a9ddc`) reads the TLS thread type byte (`39400008 ldrb w8, [x0]`) and compares against `expected` (`6B33011F cmp w8, w19, uxtb`).
