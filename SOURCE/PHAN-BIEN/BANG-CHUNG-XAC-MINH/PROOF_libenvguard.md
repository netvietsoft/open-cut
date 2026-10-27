# Clean-Room Reconstruction Analysis: `libenvguard.so`
# Phân Tích Tái Tạo Phòng Sạch: `libenvguard.so`

## 1. Binary Identity / Định Danh Nhị Phân
- **File**: `libenvguard.so`
- **Task ID**: `TASK-199-RECONSTRUCTION-LIBENVGUARD` (`TASK_SO_124_libenvguard`)
- **Size**: `224,680` bytes
- **SHA-256**: `1e54f59bf1e158d86d01c2b5ebd5938950f2cc03981b7d1286302fddcab2bce5`
- **Architecture**: `AArch64 (EM_AARCH64, 64-bit LSB shared object)`
- **SONAME**: `libenvguard.so`

## 2. Exact ELF Layout & `.eh_frame_hdr` FDE Table / Bố Cục ELF & Bảng FDE
- `.rodata`: `0x06850` (`136,340` bytes — `envguard`, `\x7fELF`, `1weis`, bytecode VM tables & obfuscated strings)
- `.eh_frame_hdr`: `0x27ce4` (`996` bytes, `123` sorted FDE entries)
- `.eh_frame`: `0x280c8` (`3,108` bytes)
- `.text`: `0x28cec .. 0x3430c` (`46,624` bytes = `11,656` AArch64 instructions)
- `.plt`: `0x34310` (`80` bytes)
- `.data.rel.ro`: `0x38360` (`7,600` bytes)
- `.data`: `0x3e310` (`568` bytes)
- `.bss`: `0x3e548` (`3,505` bytes)

## 3. Architecture & Mathematical Formulation / Kiến Trúc & Công Thức Toán Học
1. **JNI Registration (`JNI_OnLoad` @ `0x28d3c`, `first_op = 0xa9be7bfd`)**:
   - Initializes the `envguard` native runtime attestation context, verifies ELF64 header magic `\x7fELF` and `EM_AARCH64` (`183`), and registers JNI callbacks.
2. **Bytecode VM & Environment Integrity Probes (`.rodata` @ `0x06850`, `136,340` bytes)**:
   - Evaluates 123 subroutines across `.text` (`0x28cec..0x3430c`) against the 136 KB `.rodata` state tables to detect tampering or instrumentation hooks.
