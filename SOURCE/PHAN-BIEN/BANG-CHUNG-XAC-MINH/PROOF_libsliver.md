# Bằng Chứng Xác Minh Đối Kháng: `libsliver.so` (`TASK_SO_077_libsliver`)
# Adversarial Verification Proof: `libsliver.so` (`TASK_SO_077_libsliver`)

---

## 1. Thông Số Nhị Phân & Mã Nguồn Tái Dựng / Binary & Reconstructed Code Metrics

- **Tệp nhị phân gốc / Original Binary**: `apktool-res/lib/arm64-v8a/libsliver.so` (`83,984 bytes`, 24 ELF64 sections).
- **Dung lượng mã nguồn C++17 tái dựng / Reconstructed C++17 Source Size**: `181,506 bytes` (`181.51 KB` > ngưỡng `40 KB` của Agent 13).
- **Danh sách 8 tệp mã nguồn trong `SOURCE/GIAI-MA/libsliver/`**:
  1. `sliver_types.h`
  2. `sliver_art_unwinder.h`
  3. `sliver_xhook_elf.h`
  4. `sliver_sampler_jni.h`
  5. `sliver_interface.h`
  6. `sliver_art_unwinder.cpp`
  7. `sliver_xhook_elf.cpp`
  8. `sliver_sampler_jni.cpp`
  9. `sliver_interface.cpp`
  10. `sliver_pseudocode.cpp`

---

## 2. Đối Chiếu Opcode AArch64 Trực Tiếp / Direct AArch64 Opcode Verification

1. **`JNI_OnLoad` (`0x0039ec..0x003ad4`)**:
   - Prologue `0x0039ec`: `ff 83 01 d1 f6 57 03 a9 f4 4f 04 a9 fd 7b 05 a9 fd 43 01 91` (`sub sp, sp, #0x60; stp x22, x21, [sp, #0x30]; ...`).
   - Đăng ký `12` phương thức của `com/bytedance/sliver/Sliver` tại `0x0171d8` (`mov w3, #0xc` @ `0x003a50`) và `8` phương thức của `com/bytedance/sliver/SliverAllThreadSupport` tại `0x0172f8` (`mov w3, #0x8` @ `0x003a8c`).
2. **Bitmask Phiên Bản Android SDK (`0x003b18..0x003b28` & `0x004d4c..0x004d5c`)**:
   - `929cfd0b` (`mov x11, #0xffe80000`) + `f2a000eb` (`movk x11, #0x7, lsl #32`) = `0x00000007FFE80000ULL` (hỗ trợ API 19 và API 21..34).
3. **`nGetThreadId` (`0x004110..0x004130`)**:
   - `09 02 80 52` (`mov w9, #0x10`), `88 6b 80 52` (`mov w8, #0x35c`), `08 01 89 9a` (`csel x8, x8, x9, eq`), `00 69 62 b8` (`ldr w0, [x8, x2]`).
4. **Hàm Băm ELF GNU Hash & SysV Hash (`0x0089c8..0x008a40`)**:
   - GNU Hash DJB2 khởi tạo `5381` (`0x1505` -> `a8 a0 82 52`) và nhân `33` (`08 15 08 0b`: `add w8, w8, w8, lsl #5`).
   - `DT_GNU_HASH` (`0x6ffffef5`) tại `0x008b28..0x008b3c`: `ac de 9f 52` (`mov w12, #0xfef5`) + `ec ff ad 72` (`movk w12, #0x6fff, lsl #16`).
5. **Trình Kiểm Tra ELF64 AArch64 (`0x00b0f4..0x00b164`)**:
   - Kiểm tra `\x7fELF` (`0x464c457f`), `EI_CLASS == 2` (`ELFCLASS64`), `e_machine == 183` (`cmp w9, #0xb7` -> `3f dd 02 71`), trả về mã lỗi `0x3ef` (`1007`) nếu không khớp.
6. **Đồng Bộ I-Cache / D-Cache AArch64 (`0x00f800..0x00f878`)**:
   - `23 00 3b d5` (`mrs x3, ctr_el0`), `24 7b 0b d5` (`dc cvau, x4`), `9f 3b 03 d5` (`dsb ish`), `22 75 0b d5` (`ic ivau, x2`), `df 3f 03 d5` (`isb`).
