# Clean-Room Reconstruction of `libmetasec_ov.so` (Target 117 / 169)
# Tái dựng Sạch `libmetasec_ov.so` (Mục tiêu 117 / 169 — `TASK-156` / `TASK_SO_055_libmetasec_ov`)

## 1. Binary Forensics & Overview / Pháp y Nhị phân & Tổng quan
- **Library**: `libmetasec_ov.so` (ByteDance MetaSec Overseas `v05.02.03-alpha.9` Anti-Bot, Device Fingerprinting & OLLVM-Protected Security Engine)
- **File Size**: `1,932,896 bytes`
- **SHA-256**: `1b82fc11ad72e1afc99b5399ecf44c0e4dd055f715ed9c3dda9b716355e5581e`
- **Architecture**: ELF64 AArch64 (`EM_AARCH64`, Little-Endian)
- **Dynamic Symbols (`.dynsym` @ `0x000df8`)**: `14` exported symbols (including `JNI_OnLoad` @ `0x04aae0`, `4,776 bytes`) & `451` imported symbols
- **Unwind Table (`.eh_frame_hdr` @ `0x18b288`)**: `5,296` FDEs (`0x02ea00 .. 0x16b76c`)

## 2. Key AArch64 Opcode & Mathematical Proofs / Bằng chứng Opcode AArch64 & Toán học
1. **13 Overseas AppID Whitelist Initializer (`0x02ea00..0x02ebc0`, `.rodata` @ `0x16b790..0x16b7d8`)**:
   - Guards one-time initialization with `0x02ea34: 08DFFD08 ldarb w8, [x8]` at `.bss 0x1db7a8` and constructs 13 `std::string` entries: `"1180"`, `"1233"`, `"259"` (CapCut Overseas), `"662155"`, `"1340"`, `"4082"`, `"8660"`, `"385522"`, `"364225"`, `"310024"`, `"580589"`, `"3332"`, `"214304"`.
2. **OLLVM Number-Theoretic Opaque Predicates in `JNI_OnLoad` (`0x04aae0..0x04bd88`)**:
   - **Quadratic Non-Residue Modulo 19 (`0x04bc40..0x04bc70` & `0x04bd18..0x04bd48`)**: Computes $(4x^2 + 4) \bmod 19$ using magic reciprocal `0xAF286BCB` (`528D7969 mov w9, #0x6bcb; 72B5E509 movk w9, #0xaf28, lsl #16`). Since $-1$ is a quadratic non-residue mod $19$, $(4x^2 + 4) \bmod 19 \ne 0$ for all $x \in \mathbb{Z}$ (specifically $r(0x19b) = 10$ and $r(0xea) = 15$), bypassing bogus stack adjustments `add sp, sp, #0x680` (`0x04bc74`) and `add sp, sp, #0x800` (`0x04bcf4`).
   - **Pell-Type Non-Residue Modulo 7 (`0x04bc7c..0x04bcac`)**: Checks $x^2 + 1 == 7y^2$ (`1B082908 madd w8, w8, w8, w10`; `531D712A lsl w10, w9, #3; 4B090149 sub w9, w10, w9`), which has no integer solutions since $-1$ is a quadratic non-residue mod $7$.
   - **Polynomial Modulo 81 (`0x04bcb0..0x04bcf0`)**: Computes $(x^2 + x + 7) \bmod 81$ using magic reciprocal `0xCA4587E7 >> 38` (`5290FCE9 mov w9, #0x87e7; 72B948A9 movk w9, #0xca45, lsl #16`), yielding $61 \ne 0$ for $x = 0x36 = 54$.
