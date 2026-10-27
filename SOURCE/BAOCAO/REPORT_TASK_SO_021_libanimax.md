# Clean-Room Reconstruction Analysis — `libanimax.so`
## Phân Tích Tái Tạo Phòng Sạch — `libanimax.so`

- **Target Binary / Nhị phân mục tiêu**: `libanimax.so` (`657,720 bytes`)
- **SHA-256**: `7a0c3593e13aa50431ba537046a038c49decc30db1322810d77ea2b24259e93c`
- **Task ID**: `TASK-147-RECONSTRUCTION-LIBANIMAX` / `TASK_SO_021_libanimax`
- **Architecture / Kiến trúc**: `AArch64` (`ELF64 Little-Endian`, `.eh_frame_hdr` @ `0x020be4`, `3,965` FDEs)
- **Exported Symbols / Biểu tượng xuất**: `294`
- **Imported Symbols / Biểu tượng nhập**: `279`
- **Reconstructed C++17 Size / Dung lượng C++17 tái tạo**: `3,063,866 bytes` across 9 files (`0` stubs)

---

## 1. Key Verified AArch64 Functions & Mathematical Proofs / Các Hàm AArch64 & Chứng Minh Toán Học

1. **`ColorUtil::ParseHexColor` (`0x04dc78..0x04de78`)**:
   - `0x04dccc`: `71008D1F` (`cmp w8, #0x23` -> strips leading `'#'`)
   - `0x04dcfc..0x04dd04`: `F100217F cmp x11, #8; b.eq #0x4dd40; F100197F cmp x11, #6` (accepts 6 or 8 hex digits, prepending `"ff"` for 6-digit RGB)
   - `0x04de38..0x04de44`: Packs 32-bit `ARGB` via `(R << 16) | (A << 24) | (G << 8) | B` (`53103F08 lsl w8, w24, #0x10; 2A1B6108 orr w8, w8, w27, lsl #24; 2A162108 orr w8, w8, w22, lsl #8; 2A170113 orr w19, w8, w23`).
2. **`Color::Color(int)` (`0x0683d8..0x068408`)**:
   - `0x0683e4..0x0683f0`: `53187C29 lsr w9, w1, #0x18; B20883EA mov x10, #0x100010001000100; 53107C2B lsr w11, w1, #0x10; 53087C2C lsr w12, w1, #8`
   - `0x0683f4..0x068408`: Stores `vptr` and 4 `bool` valid flags (`0x0100010001000100`) at `[x0..x0+0x0F]`, then stores `A` at `+0x08`, `R` at `+0x0A`, `G` at `+0x0C`, and `B` at `+0x0E`.
3. **`YUVFrameInfo` (`0x073f08..0x074000`)**:
   - `GetVerticalSubsamplingFactor(uint32_t ch)` (`0x073fd0..0x073ffc`): Returns `0.0f` if `ch > 2`, `1.0f` if `ch == 0` (Y plane), and `(yuv_pix_fmt == 1) ? 0.5f : 1.0f` (`1E200C20 fcsel s0, s1, s0, eq`) for chroma planes (`ch == 1, 2`).
   - `GetChannelDataHeight(uint32_t ch)` (`0x073f90..0x073fcc`): Converts `uint32_t height` at `+0x24` via `7E21D800 ucvtf s0, s0`, multiplies by `GetVerticalSubsamplingFactor(ch)` (`1E200820 fmul s0, s1, s0`), and truncates via `1E390000 fcvtzu w0, s0`.
