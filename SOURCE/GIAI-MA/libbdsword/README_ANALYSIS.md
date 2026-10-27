# Clean-Room Reconstruction Analysis: `libbdsword.so`
# Phân Tích Tái Tạo Phòng Sạch: `libbdsword.so`

## 1. Binary Identity / Định Danh Nhị Phân
- **File**: `libbdsword.so`
- **Task ID**: `TASK-196-RECONSTRUCTION-LIBBDSWORD` (`TASK_SO_130_libbdsword`)
- **Size**: `134,504` bytes
- **SHA-256**: `c9369ebdd087e79a30b8a9cf5baeb60bd7234b7b7bd80279e88268deddc0b868`
- **Architecture**: `AArch64 (EM_AARCH64, 64-bit LSB shared object)`
- **SONAME**: `libbdsword.so`

## 2. Exact ELF Layout & `.eh_frame_hdr` FDE Table / Bố Cục ELF & Bảng FDE
- `.plt`: `0x01b80` (`224` bytes)
- `.text`: `0x01c60 .. 0x18ed0` (`94,832` bytes = `23,708` AArch64 instructions)
- `.rodata`: `0x18ed0` (`17,876` bytes — White-Box Lookup Tables & XOR-Obfuscated String Pool)
- `.eh_frame_hdr`: `0x1d4a4` (`1,340` bytes, `166` sorted FDE entries)
- `.eh_frame`: `0x1d9e0` (`4,920` bytes)
- `.data.rel.ro`: `0x23790` (`1,512` bytes)
- `.data`: `0x24000` (`1,216` bytes)
- `.bss`: `0x244c0` (`808` bytes)

## 3. Architecture & Mathematical Formulation / Kiến Trúc & Công Thức Toán Học
1. **JNI Registration (`JNI_OnLoad` @ `0x03174`, `first_op = 0xa9be4ffc`)**:
   - Initializes global mutexes and environment attestation tables in `.bss` (`0x244c0`), registers native methods via `RegisterNatives`, and returns `JNI_VERSION_1_6` (`0x00010006`).
2. **Command Dispatcher (`bdsword_command` @ `0x0bc38`, `first_op = 0xa9be4ffc`)**:
   - Dispatches security/attestation commands over `BdSwordCommandFrameAbi` (`48` bytes) and transforms input buffers against the 17,876-byte `.rodata` table (`0x18ed0`).
