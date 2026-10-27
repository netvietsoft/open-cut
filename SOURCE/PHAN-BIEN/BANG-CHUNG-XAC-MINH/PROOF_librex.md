# Clean-Room Reconstruction Analysis — `librex.so`
## Phân Tích Tái Tạo Phòng Sạch — `librex.so`

- **Target Binary / Nhị phân mục tiêu**: `librex.so` (`690,264 bytes`)
- **SHA-256**: `8597b027ebde080435814b961a219d53170ab05cee0d5c4d40cfe0bb1ee5d6c4`
- **Task ID**: `TASK-148-RECONSTRUCTION-LIBREX` / `TASK_SO_068_librex`
- **Architecture / Kiến trúc**: `AArch64` (`ELF64 Little-Endian`, `.text` @ `0x001c10..0x097c48` = `614,456 B`, `.eh_frame_hdr` @ `0x0a3ddc` = `211` FDEs)
- **Exported Symbols / Biểu tượng xuất**: `13` (`6` JNI functions for `com/bytedance/bddatefmt/BDDateFormat`)
- **Imported Symbols / Biểu tượng nhập**: `22`
- **Reconstructed C++17 Size / Dung lượng C++17 tái tạo**: `1,265,067 bytes` across 9 files (`0` stubs)

---

## 1. Key Verified AArch64 Functions & Mathematical Proofs / Các Hàm AArch64 & Chứng Minh Toán Học

1. **`InitCalendarBreakdown` (`0x08ab60..0x08ade0`)**:
   - `0x08ab9c..0x08abb4`: Reciprocal multiplication by `0x20c49ba5e353f7cf` ($\lceil 2^{71} / 1000 \rceil$) with `9B487EA8 smulh x8, x21, x8; 9347FD09 asr x9, x8, #7; 8B48FD28 add x8, x9, x8, lsr #63` to divide `timestamp_ms` by `1,000`.
   - `0x08abf0..0x08ac04`: Reciprocal multiplication by `0x45e7b273` ($\lceil 2^{46} / 60000 \rceil$) with `9B287C48 smull x8, w2, w8; 936EFD08 asr x8, x8, #0x2e` to divide `custom_tz_offset_ms` by `60,000`.
   - `0x08ac10..0x08ac40`: Reciprocal multiplication by `0x636ba875fd33dc87` ($\lceil 2^{89} / 86400000 \rceil$) and remainder via `w12 = 0x05265c00` (`86,400,000` ms/day) with `9B0CA631 msub x17, x17, x12, x9`.
2. **`FormatTimeZone` (`0x096300..0x0963e8`)**:
   - `0x096328..0x096338`: `528484B7 mov w23, #0x2425; 72AE6637 movk w23, #0x7331, lsl #16` -> `0x73312425` (`"%$1s"`).
   - `0x096388`: `114042E8 add w8, w23, #0x10, lsl #12` -> `0x73322425` (`"%$2s"`).
3. **`FormatRelative` (`0x0968e0..0x096994`) & `JNI_OnLoad` (`0x08d944..0x08d9f0`)**:
   - `0x096904..0x096914`: `add x8, x0, #0xfd8; add x9, x0, #0xa98; cmp x21, #0; csel x1, x8, x9, ge; cneg x2, x21, mi` (selects future `+0xfd8` vs past `+0xa98` table and takes `|offset|`).
   - `0x08d9b8..0x08d9cc`: Registers 5 `JNINativeMethod` entries at `0x0ac000` (`mov w3, #5`) and returns `0x00010006` (`5A9F0280 csinv w0, w20, wzr, eq`).
