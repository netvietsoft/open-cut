# Clean-Room Reconstruction Analysis — `libbytebench.so`
## Phân Tích Tái Tạo Phòng Sạch — `libbytebench.so`

- **Target Binary / Nhị phân mục tiêu**: `libbytebench.so` (`641,376 bytes`)
- **SHA-256**: `0c50323c365781575186c196f06dd36acea1eb80eba82d7d647581306dc4d7b2`
- **Task ID**: `TASK-146-RECONSTRUCTION-LIBBYTEBENCH` / `TASK_SO_099_libbytebench`
- **Architecture / Kiến trúc**: `AArch64` (`ELF64 Little-Endian`, `.text` @ `0x024410..0x080cf0` = `379,104 B`, `.eh_frame_hdr` @ `0x094cf8` = `6` FDEs)
- **Exported Symbols / Biểu tượng xuất**: `616`
- **Imported Symbols / Biểu tượng nhập**: `173`
- **Reconstructed C++17 Size / Dung lượng C++17 tái tạo**: `1,339,882 bytes` across 9 files (`0` stubs)

---

## 1. Key Verified AArch64 Functions & Mathematical Proofs / Các Hàm AArch64 & Chứng Minh Toán Học

1. **`CUtils::CalcFramePsnr` (`0x066d00..0x066d7c`)**:
   - `0x066d20`: `1B027C68` (`mul w8, w3, w2` -> $N = W \times H$)
   - `0x066d44..0x066d50`: `sub w10, w10, w11; scvtf d1, w10; fmul d1, d1, d1; fadd d0, d0, d1` ($\sum (I_1 - I_2)^2$)
   - `0x066d5c..0x066d74`: Loads $255^2 = 65025.0$ from `.rodata 0x080d10` (`FD468921`: `ldr d1, [x9, #0xd10]`), computes $\text{MSE} = \frac{1}{N}\sum (I_1 - I_2)^2$, calls `log10(65025.0 / MSE)` (`bl #0x23b10`), and multiplies by `10.0` (`1E649001`: `fmov d1, #10.0; fmul d0, d0, d1`).
2. **`BXFFReduce(STERational&)` (`0x06b084..0x06b244`)**:
   - `0x06b098`: `69405C16` (`ldpsw x22, x23, [x0]`)
   - `0x06b0a4..0x06b0ac`: `cneg x8, x22, mi; cneg x9, x23, mi`
   - `0x06b0c8..0x06b0cc`: `sdiv x11, x10, x11; msub x11, x11, x12, x10` (Euclidean GCD remainder step $r = a - \lfloor a/b \rfloor \cdot b$)
3. **`CUtils::flip(uint16_t)` (`0x0668b0`), `CUtils::flip(uint32_t)` (`0x0668bc`) & `CUtils::isSpecialSar` (`0x066eec..0x066f0c`)**:
   - `flip(uint16_t)`: `5AC00808 53107D00 D65F03C0` (`rev w8, w0; lsr w0, w8, #16; ret`).
   - `flip(uint32_t)`: `5AC00800 D65F03C0` (`rev w0, w0; ret`).
   - `isSpecialSar`: branchlessly evaluates `(num > 0) && (den > 0) && (num != den)`.
