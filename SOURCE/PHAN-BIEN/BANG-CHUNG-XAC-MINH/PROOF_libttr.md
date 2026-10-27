# Clean-Room Reconstruction Analysis — `libttr.so`
## Phân Tích Tái Tạo Phòng Sạch — `libttr.so`

- **Target Binary / Nhị phân mục tiêu**: `libttr.so` (`625,192 bytes`)
- **SHA-256**: `38c13f772c29f2a6b03c5523b74730be6727dfc9c3de457b1e09fe32578d6f6f`
- **Task ID**: `TASK-143-RECONSTRUCTION-LIBTTR` / `TASK_SO_101_libttr`
- **Architecture / Kiến trúc**: `AArch64` (`ELF64 Little-Endian`, `.eh_frame_hdr` @ `0x08ab40` = `3,386` FDEs)
- **Exported Symbols / Biểu tượng xuất**: `490`
- **Imported Symbols / Biểu tượng nhập**: `161`
- **Reconstructed C++17 Size / Dung lượng C++17 tái tạo**: `1,372,517 bytes` across 9 files (`0` stubs)

---

## 1. Binary Architecture & Section Layout / Kiến Trúc Nhị Phân & Bố Cục Phân Đoạn

| Section | Virtual Address (`sh_addr`) | File Offset (`sh_offset`) | Size (Bytes) | Description (EN / VN) |
|---|---:|---:|---:|---|
| `.dynsym` | `0x0002c0` | `0x0002c0` | `15,648` | Dynamic symbol table (`651` entries: `490` exported, `161` imported) / Bảng ký hiệu động |
| `.text` | `0x01c750` | `0x01c750` | `295,504` | Executable AArch64 instructions (`0x01c750..0x0649a0`) / Mã máy thực thi AArch64 |
| `.rodata` | `0x0649a0` | `0x0649a0` | `62,420` | GLSL shaders (`0x068dce`), JNI class/method strings (`0x06b273..0x06b4cb`), GLES symbol names / Chuỗi hằng & shader |
| `.eh_frame_hdr` | `0x08ab40` | `0x08ab40` | `27,100` | DWARF unwind binary search table (`3,386` FDEs) / Bảng tra cứu FDE DWARF |
| `.data` | `0x09c000` | `0x098000` | `312` | `JNINativeMethod` tables (`0x09c048` = 1 entry, `0x09c060` = 9 entries) / Bảng phương thức JNI |
| `.bss` | `0x09c138` | `0x098138` | `13,272` | 358 `ttr_stub_wraper::gl*` pointers (`0x09c140..0x09cc68`), `g_gles_handle` (`0x09ce78`), `JavaVM*` (`0x09ce80`) / Vùng nhớ tĩnh |

---

## 2. Key Verified AArch64 Functions & Mathematical Proofs / Các Hàm AArch64 & Chứng Minh Toán Học

1. **`TTRUtilsTool::ClipInt16` (`0x023de0..0x023df0`)**:
   - `0x023de0`: `131F7C08` (`asr w8, w0, #0x1f`)
   - `0x023de4`: `52003908` (`eor w8, w8, #0x7fff`)
   - `0x023de8`: `6B20A01F` (`cmp w0, w0, sxth`)
   - `0x023dec`: `1A801100` (`csel w0, w8, w0, ne`)
   - Branchless signed 16-bit saturation (`[-32768, 32767]`): when `w0 != (int16_t)w0`, `(w0 >> 31) ^ 0x7FFF` evaluates to `0x7FFF` (`+32767`) for positive overflow and `0xFFFF8000` (`-32768`) for negative overflow.
2. **`TTRUtilsTool::GetCurrentTimeMs` (`0x023bc8..0x023bec`) & `GetCurrentTimeUs` (`0x023bf0..0x023c14`)**:
   - `0x023be0..0x023be8`: `mov w10, #0x3e8; sdiv x8, x8, x10; madd x0, x9, x10, x8` ($t_{\text{ms}} = \text{tv\_sec} \times 1000 + \lfloor \text{tv\_usec} / 1000 \rfloor$).
   - `0x023c08..0x023c10`: `mov w10, #0x4240; movk w10, #0xf, lsl #16; madd x0, x9, x10, x8` ($t_{\text{us}} = \text{tv\_sec} \times 10^6 + \text{tv\_usec}$).
3. **`TTRAudioEngine::TTRAudioEngine` (`0x029200..0x029248`) & `SetVolume` (`0x029560..0x029598`)**:
   - Initializes `+0x2c = 0x3f800000` (`1.0f` volume), `+0x30 = 0x3ff0000000000000` (`1.0` double speed), and `+0x40 = -1` (`device_id`).
   - `SetVolume` (`0x029560`) validates $0.0 \le v \le 1.0$ via `fmov s1, #1.0; fcmp s0, s1; b.hi; fcmp s0, #0.0; b.mi`.
4. **`JNI_OnLoad` (`0x0358b0..0x035a24`) & `glstubInit` (`0x03209c..0x03587c`)**:
   - `JNI_OnLoad` registers 9 methods from `.data 0x09c060` (`mov w3, #9` @ `0x03596c`) on `com/tiktok/ttr/video/TTRVideoRender` (`0x06b273`) and 1 method from `.data 0x09c048` (`mov w3, #1` @ `0x0359b0`) on `com/tiktok/ttr/video/TTRSurfaceWrap` (`0x06b30d`).
