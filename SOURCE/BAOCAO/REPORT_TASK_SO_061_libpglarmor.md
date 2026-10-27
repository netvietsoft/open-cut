# Clean-Room Reconstruction Analysis: `libpglarmor.so`
# Phân Tích Tái Tạo Phòng Sạch: `libpglarmor.so`

## 1. Binary Identity / Định Danh Nhị Phân
- **File**: `libpglarmor.so`
- **Task ID**: `TASK-192-RECONSTRUCTION-LIBPGLARMOR` (`TASK_SO_061_libpglarmor`)
- **Size**: `68,776` bytes
- **SHA-256**: `69218eb7accd450feb707bfe9fa6533c390a2c0bf63b5c685c5548c18a0fe716`
- **Architecture**: `AArch64 (EM_AARCH64, 64-bit LSB shared object)`
- **SONAME**: `libpglarmor.so`

## 2. Exact ELF Layout & `.eh_frame_hdr` FDE Table / Bố Cục ELF & Bảng FDE
- `.rodata`: `0x2070` (`3,083` bytes) — White-box AES S-Box tables, Galois Field tables, Base64/XOR constants
- `.eh_frame_hdr`: `0x2c7c` (`348` bytes, `42` sorted FDE entries)
- `.eh_frame`: `0x2dd8` (`1,292` bytes)
- `.text`: `0x32e4 .. 0xf8f4` (`50,704` bytes = `12,676` AArch64 instructions)
- `.plt`: `0xf900` (`224` bytes)
- `.data.rel.ro`: `0x139e0` (`1,792` bytes)
- `.data`: `0x18330` (`344` bytes)
- `.bss`: `0x18488` (`20` bytes)

## 3. Architecture & Mathematical Formulation / Kiến Trúc & Công Thức Toán Học
1. **JNI Entry Point (`Java_com_bytedance_sdk_component_pglcrypt_PglCryptUtils_bc` @ `0x003564`)**:
   - First opcode `0xa9bf7bfd` (`stp x29, x30, [sp, #-0x10]!`), frame setup, and tail branch `b #0x35a8` (`fde_04_35a8`, `2,012` bytes) which unpacks the Java `byte[]`, dispatches the cipher/compression command `cmd`, and returns a newly allocated `jbyteArray`.
2. **Galois Field $\text{GF}(2^8)$ MixColumns & CRC-32 Integrity**:
   - Uses irreducible polynomial $m(x) = x^8 + x^4 + x^3 + x + 1$ (`0x11B`) for column mixing and IEEE 802.3 reflected polynomial `0xEDB88320` for packet payload verification.
