# Clean-Room Reconstruction Analysis: `libEncryptor.so`
# Phân Tích Tái Tạo Phòng Sạch: `libEncryptor.so`

## 1. Binary Identity / Định Danh Nhị Phân
- **File**: `libEncryptor.so`
- **Task ID**: `TASK-193-RECONSTRUCTION-LIBENCRYPTOR` (`TASK_SO_137_libEncryptor`)
- **Size**: `83,896` bytes
- **SHA-256**: `6ffd80242ce93782454b9e76521f81526debe01d60f27a88c68da4f114c15dcb`
- **Architecture**: `AArch64 (EM_AARCH64, 64-bit LSB shared object)`
- **SONAME**: `libEncryptor.so`

## 2. Exact ELF Layout & `.eh_frame_hdr` FDE Table / Bố Cục ELF & Bảng FDE
- `.plt`: `0x08a0` (`192` bytes)
- `.text`: `0x0960 .. 0x7af0` (`29,072` bytes = `7,268` AArch64 instructions)
- `.rodata`: `0x7c50` (`35,480` bytes) — White-Box AES-128 T-Boxes, S-Boxes, SHA-512 round constants, and `([BI)[B` JNI signature
- `.eh_frame_hdr`: `0x106e8` (`340` bytes, `41` sorted FDE entries)
- `.eh_frame`: `0x10840` (`1,304` bytes)
- `.data.rel.ro`: `0x17d00` (`120` bytes)
- `.data`: `0x18000` (`32` bytes — `JNINativeMethod` registration table)
- `.bss`: `0x18020` (`56` bytes)

## 3. Architecture & Mathematical Formulation / Kiến Trúc & Công Thức Toán Học
1. **JNI Registration (`JNI_OnLoad` @ `0x099c`, `first_op = 0xa9be4ffc`)**:
   - Decrypts stack-encoded class string `com/bytedance/frameworks/encryptor/EncryptorUtil` and method name `ttEncrypt` with signature `([BI)[B` (`@ 0x106d4`), registering the native callback via `RegisterNatives` and returning `JNI_VERSION_1_6` (`0x00010006`).
2. **Applog `ttEncrypt` Packet Framing (`0x72 0x01`) & White-Box AES-128-CBC**:
   - Prepends the 2-byte Applog magic header `{0x72, 0x01}`, derives a 64-byte key/IV block using SHA-512 over the 32-byte salt, and encrypts the payload in CBC mode with PKCS#7 padding using the 35,480-byte white-box T-tables in `.rodata` (`0x7c50`).
