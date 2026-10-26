# Phân Tích Kiến Trúc & Giải Mã Nhị Phân: `libsliver.so` (Target 66 / `TASK_SO_077_libsliver`)
# Architectural Analysis & Binary Reconstruction: `libsliver.so` (Target 66 / `TASK_SO_077_libsliver`)

---

## 1. Thông Tin Tổng Quan Nhị Phân / Binary Overview (`OBSERVED`)

| Thuộc tính / Property | Giá trị xác thực / Verified Value |
|---|---|
| **Đường dẫn gốc / Binary Path** | `apktool-res/lib/arm64-v8a/libsliver.so` |
| **Kích thước / File Size** | `83,984 bytes` (`0x14810`) |
| **Kiến trúc / Architecture** | `ELF 64-bit LSB shared object, ARM aarch64` (`EM_AARCH64 = 183`) |
| **Số lượng Section / Section Count** | `24 sections` (`.text` @ `0x0039ec`, size `0x00bedc` = `48,860 bytes`) |
| **Biểu tượng động xuất khẩu / Exported Symbols** | `7 FUNC symbols` (`.dynsym [100..106]`) |
| **Biểu tượng nhập khẩu / Imported Symbols** | `99 symbols` (`liblog.so`, `libc.so`, `libm.so`, `libstdc++.so`, `libdl.so`) |
| **Phương thức JNI đăng ký / JNI Methods** | `20 methods` (`12` trên `com/bytedance/sliver/Sliver` + `8` trên `com/bytedance/sliver/SliverAllThreadSupport`) |

---

## 2. Danh Sách 7 Biểu Tượng Xuất Khẩu (`.dynsym [100..106]`) / 7 Exported Symbols

1. **`[100] xhook_clear` (`0x00b9f0`, `344 bytes`)**:
   - Giải phóng toàn bộ danh sách quy tắc PLT/GOT hook (`0x18d88`) và ignore (`0x18d98`) cùng bộ nhớ `regfree()`.
   - Frees all registered PLT/GOT hook (`0x18d88`) and ignore (`0x18d98`) rule lists and invokes `regfree()`.
2. **`[101] xhook_enable_sigsegv_protection` (`0x00bb64`, `20 bytes`)**:
   - Mã máy AArch64 / AArch64 Opcodes:
     ```asm
     0x00bb64: 7100001f  cmp  w0, #0x0
     0x00bb68: 1a9f07e8  cset w8, ne
     0x00bb6c: 90000069  adrp x9, 0x18000
     0x00bb70: b9000928  str  w8, [x9, #8]   ; g_sigsegv_enabled @ 0x18008
     0x00bb74: d65f03c0  ret
     ```
3. **`[102] xhook_refresh` (`0x00b844`, `428 bytes`)**:
   - Quét `/proc/self/maps`, dựng Cây Đỏ-Đen lưu các module ELF64 và vá bảng `.got.plt` / `.rela.plt` đồng bộ hoặc qua luồng nền.
   - Scans `/proc/self/maps`, builds the Red-Black Tree of ELF64 modules, and patches `.got.plt` / `.rela.plt` entries synchronously or asynchronously.
4. **`[103] xhook_register` (`0x00b61c`, `276 bytes`)**:
   - Đăng ký biểu thức chính quy POSIX (`regcomp`) khớp đường dẫn thư viện và tên hàm cần thay thế trong bảng PLT/GOT.
   - Registers a POSIX regular expression (`regcomp`) matching library pathnames and symbol names to intercept in PLT/GOT tables.
5. **`[104] JNI_OnLoad` (`0x0039ec`, `232 bytes`)**:
   - Lưu `JavaVM*` vào `0x18be0`, gọi `GetEnv(JNI_VERSION_1_6)` (`0x00010006`), tìm 2 lớp `com/bytedance/sliver/Sliver` và `com/bytedance/sliver/SliverAllThreadSupport` và đăng ký 12 + 8 phương thức native tương ứng.
   - Stores `JavaVM*` at `0x18be0`, invokes `GetEnv(JNI_VERSION_1_6)` (`0x00010006`), resolves `com/bytedance/sliver/Sliver` and `com/bytedance/sliver/SliverAllThreadSupport`, and registers 12 + 8 native methods.
6. **`[105] xhook_enable_debug` (`0x00bb48`, `28 bytes`)**:
   - Mã máy AArch64 / AArch64 Opcodes:
     ```asm
     0x00bb48: 7100001f  cmp  w0, #0x0
     0x00bb4c: 52800068  mov  w8, #0x3        ; ANDROID_LOG_DEBUG = 3
     0x00bb50: 528000a9  mov  w9, #0x5        ; ANDROID_LOG_WARN  = 5
     0x00bb54: 1a880128  csel w8, w9, w8, eq
     0x00bb58: 90000069  adrp x9, 0x18000
     0x00bb5c: b9000d28  str  w8, [x9, #12]  ; g_xhook_log_prio @ 0x1800c
     0x00bb60: d65f03c0  ret
     ```
7. **`[106] xhook_ignore` (`0x00b730`, `276 bytes`)**:
   - Đăng ký quy tắc loại trừ thư viện hoặc biểu tượng khỏi quá trình hook PLT/GOT.
   - Registers an exclusion rule to skip matching libraries or symbols during PLT/GOT hooking.

---

## 3. Bảng 20 Phương Thức JNI Tại `.data.rel.ro` (`0x0171d8..0x0173b0`) / 20 JNI Native Methods

### 3.1. Lớp `com/bytedance/sliver/Sliver` (`12 methods` @ `0x0171d8..0x0172f0`)

| STT | Tên phương thức / Method | Chữ ký JNI / Signature | Địa chỉ hàm / Function RVA |
|---|---|---|---|
| 1 | `nInit` | `(ILjava/lang/reflect/Member;I)V` | `0x003de4` |
| 2 | `nStart` | `(Ljava/lang/Thread;JII)J` | `0x003e30` |
| 3 | `nPause` | `(J)V` | `0x003ebc` |
| 4 | `nResume` | `(J)V` | `0x003ed8` |
| 5 | `nStop` | `(J)V` | `0x003ef4` |
| 6 | `nDump` | `(JLjava/lang/String;Ljava/lang/String;)Z` | `0x003f14` |
| 7 | `nGetMethodStackTrace` | `(Ljava/lang/Thread;)[J` | `0x003fe0` |
| 8 | `nGetStackTrace` | `([J)[Ljava/lang/String;` | `0x00405c` |
| 9 | `nClear` | `(J)V` | `0x0040c8` |
| 10 | `nGetThreadPeer` | `(Ljava/lang/Thread;)J` | `0x0040ec` |
| 11 | `nGetThreadId` | `(J)I` | `0x004110` |
| 12 | `nMark` | `(J)V` | `0x004120` |

### 3.2. Lớp `com/bytedance/sliver/SliverAllThreadSupport` (`8 methods` @ `0x0172f8..0x0173b0`)

| STT | Tên phương thức / Method | Chữ ký JNI / Signature | Địa chỉ hàm / Function RVA |
|---|---|---|---|
| 1 | `nStartAllThread` | `(III)J` | `0x0048e8` |
| 2 | `nNotifyThreadChange` | `(J[Ljava/lang/Thread;[J)V` | `0x0049bc` |
| 3 | `nStopAllThread` | `(J)V` | `0x004aa4` |
| 4 | `nPauseAllThread` | `(J)V` | `0x004b44` |
| 5 | `nResumeAllThread` | `(J)V` | `0x004be4` |
| 6 | `nClearAllThread` | `(J)V` | `0x004ca0` |
| 7 | `nDumpAllThread` | `(JLjava/lang/String;Ljava/lang/String;)Z` | `0x004d78` |
| 8 | `nDumpHeader` | `(Ljava/lang/String;Ljava/lang/String;)Z` | `0x004eb0` |

---

## 4. Bằng Chứng Toán Học & Opcode AArch64 Trọng Tâm / Mathematical & Opcode Proofs

1. **Bitmask Kiểm Tra Phiên Bản Android SDK (`0x003b18..0x003b28` & `0x004d4c..0x004d5c`)**:
   - Lệnh `mov x11, #0xffe80000` (`0x929cfd0b`) kết hợp `movk x11, #0x7, lsl #32` (`0xf2a000eb`) tạo hằng số `0x00000007FFE80000ULL`.
   - Các bit bật bằng `1` nằm tại vị trí `19` và `21..34` ($\text{API } 19 \text{ và } 21 \le \text{API} \le 34$, bỏ qua API 20 Android 4.4W).
2. **Đọc `tid` Nội Bộ Của `art::Thread*` (`nGetThreadId` @ `0x004110..0x004130`)**:
   - Nếu `sdk_int == 0` (hoặc cấu hình cũ): đọc `*(uint32_t*)(thread_ptr + 0x35c)` (`mov w8, #0x35c` = `0x52806b88`).
   - Ngược lại (Android 5.0+ chuẩn): đọc `*(uint32_t*)(thread_ptr + 0x10)` (`tls32_.tid`, `mov w9, #0x10` = `0x52800209`).
3. **Thuật Toán Băm Biểu Tượng ELF (`0x0089c8..0x008a40`)**:
   - **GNU Hash (DJB2)** (`0x0089c8..0x0089e4`): `h = 5381 (0x1505); h = (h + (h << 5)) + c`.
   - **SysV ELF Hash** (`0x008a04..0x008a40`): `h = (h << 4) + c; g = h & 0xF0000000; h ^= (g >> 24); h &= ~g`.
4. **Đồng Bộ Cache Lệnh/Dữ Liệu AArch64 Sau Khi Vá GOT (`0x00f800..0x00f878`)**:
   - Đọc thanh ghi hệ thống `ctr_el0` (`mrs x3, ctr_el0` = `0xd53b0023`), đẩy D-Cache bằng `dc cvau, x4` (`0xd50b7b24`), rào chắn `dsb ish` (`0xd5033b9f`), vô hiệu hóa I-Cache bằng `ic ivau, x2` (`0xd50b7522`), và đồng bộ đường ống lệnh `isb` (`0xd5033fdf`).
