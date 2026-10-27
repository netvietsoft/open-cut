# Báo Cáo Giải Mã & Tái Tạo Sạch `libvcbasekit.so` (`TASK-121-RECONSTRUCTION-LIBVCBASEKIT`)
# Clean-Room Forensic Analysis & C++17 Reconstruction of `libvcbasekit.so`

## 1. Định Danh Nhị Phân / Binary Identity (`OBSERVED`)
- **Tên thư viện / Binary Name**: `libvcbasekit.so` (`APK/lib/arm64-v8a/libvcbasekit.so`)
- **Dung lượng chuẩn / Exact Size**: `231,568 bytes`
- **SHA-256**: `d5a87dc8436f7ee8aa114f986f5c9c556b534d4dae750d4f69cbc1b38f679129`
- **Kiến trúc / Architecture**: ELF 64-bit LSB shared object, ARM aarch64 (`EM_AARCH64 = 183`)
- **Build ID (GNU)**: `725e6f2fa20fb58821210ec4a7d6d5f68d0d658c`
- **Thư viện phụ thuộc (`DT_NEEDED`)**: `liblog.so`, `libc++_shared.so`, `libm.so`, `libdl.so`, `libc.so`
- **Tổng số biểu tượng động (`.dynsym`)**: `559` symbols (`399` exported `STT_FUNC`, `54` exported `STT_OBJECT`)
- **Phân loại / Classification**: `CORE_10_MONITORING` (ByteDance Video Cloud BaseKit `com::ss::vcbkit` & Embedded `JsonCpp`)

---

## 2. Bảng Phân Đoạn ELF64 / ELF64 Section Layout (`OBSERVED`)

| Section | VMA (`sh_addr`) | Offset (`sh_offset`) | Size (`sh_size`) | Vai Trò / Purpose |
|---|---:|---:|---:|---|
| `.dynsym` | `0x00000270` | `0x00000270` | `0x00003468` (13,416 B) | 559 dynamic symbols (399 exported `STT_FUNC`, 54 `STT_OBJECT`) |
| `.text` | `0x0000f9b0` | `0x0000f9b0` | `0x0001b890` (112,784 B) | Executable AArch64 instructions (`Json::*` & `com::ss::vcbkit::*`) |
| `.plt` | `0x0002b240` | `0x0002b240` | `0x00000c60` (3,168 B) | Procedure Linkage Table |
| `.rodata` | `0x0002bea0` | `0x0002bea0` | `0x000025a0` (9,632 B) | `Json::Value` numeric limits (`0x02bec8..0x02bf08`), JNI/ALOG strings |
| `.eh_frame` | `0x0002fe48` | `0x0002fe48` | `0x00006024` (24,612 B) | DWARF Call Frame Information |
| `.init_array` | `0x00039400` | `0x00038400` | `0x00000008` (8 B) | Pointer to `0x0000f9b0` (`_GLOBAL__sub_I_json_value.cpp`) |
| `.data.rel.ro` | `0x00039408` | `0x00038408` | `0x000023c8` (9,160 B) | Vtables & RTTI for `Json::*` and `com::ss::vcbkit::*` |
| `.bss` | `0x0003c040` | `0x0003a8e4` | `0x000000f8` (248 B) | `Json::Value::null` (`0x03c088`), ALOG fn (`0x03c0e0`), `JavaVM*` (`0x03c0f0`) |

---

## 3. Bằng Chứng Hợp Ngữ AArch64 & Chứng Minh Toán Học / Opcode & Mathematical Proofs (`OBSERVED`)

### 3.1. 9 Hằng Số Giới Hạn Số Nguyên `Json::Value` (`.rodata 0x02bec8..0x02bf08`)
Đối xuất trực tiếp từ bảng `.dynsym` (`STT_OBJECT`) và vùng nhớ `.rodata`:
- `0x02bec8` (`_ZN4Json5Value13maxLargestIntE`, 8 B): `0x7FFFFFFFFFFFFFFF` (`9223372036854775807`)
- `0x02bed0` (`_ZN4Json5Value14maxLargestUIntE`, 8 B): `0xFFFFFFFFFFFFFFFF` (`18446744073709551615`)
- `0x02bed8` (`_ZN4Json5Value13minLargestIntE`, 8 B): `0x8000000000000000` (`-9223372036854775808`)
- `0x02bee0` (`_ZN4Json5Value6maxIntE`, 4 B): `0x7FFFFFFF` (`2147483647`)
- `0x02bee8` (`_ZN4Json5Value6minIntE`, 4 B): `0x80000000` (`-2147483648`)
- `0x02beec` (`_ZN4Json5Value7maxUIntE`, 4 B): `0xFFFFFFFF` (`4294967295`)
- `0x02bef0` (`_ZN4Json5Value8minInt64E`, 8 B): `0x8000000000000000` (`-9223372036854775808`)
- `0x02bef8` (`_ZN4Json5Value8maxInt64E`, 8 B): `0x7FFFFFFFFFFFFFFF` (`9223372036854775807`)
- `0x02bf00` (`_ZN4Json5Value9maxUInt64E`, 8 B): `0xFFFFFFFFFFFFFFFF` (`18446744073709551615`)

### 3.2. `TimePoint<Clock::Fast1>::now()` (`0x027db8..0x027e10`)
```assembly
0x027dc8: mov  w0, #0x1                  ; CLOCK_MONOTONIC = 1
0x027dcc: add  x1, sp, #0x10             ; struct timespec* ts
0x027dd0: bl   0x2b6f0 <clock_gettime@plt>
0x027df8: ldp  x9, x8, [sp, #0x10]       ; x9 = tv_sec, x8 = tv_nsec
0x027dfc: mov  w10, #0xca00
0x027e00: movk w10, #0x3b9a, lsl #16     ; x10 = 0x3B9ACA00 = 1,000,000,000
0x027e04: madd x0, x9, x10, x8           ; x0 = tv_sec * 1,000,000,000 + tv_nsec
```

### 3.3. Chuỗi 24-Byte 3 Tầng `com::ss::vcbkit::String` (`0x028ad4..0x029154`)
- **Tầng 1 — Small (SSO, `len <= 0x17 = 23` bytes)**:
  - Tại `0x028ad4` (`String::String()`): `mov w8, #0x17; stp xzr, xzr, [x0]; str xzr, [x0, #0x10]; strb w8, [x0, #0x17]; ret`.
  - Byte thứ 24 (`+0x17`) lưu phần dư `0x17 - size`, các bit phân loại `0xC0 == 0x00`.
  - Tại `0x028ef0` (`String::size()`): `ldrb w8, [x0, #0x17]; ldr x9, [x0, #8]; mov w10, #0x17; sub w10, w10, w8; cmp w8, #0x18; csel x0, x10, x9, lo; ret`.
- **Tầng 2 — Medium (`24 <= len <= 0x3F = 63` bytes)**:
  - Tại `0x028b90`: kiểm tra `cmp x19, #0x3f`, cấp phát vùng nhớ riêng trên heap và đánh dấu cờ `0x80` tại byte `+0x17`.
  - Tại `0x028f34` (`String::capacity()`): che mặt nạ `and x0, x8, #0x3fffffffffffffff`.
- **Tầng 3 — Large COW (`len >= 64` bytes)**:
  - Cấp phát tiền tố 8-byte bộ đếm tham chiếu nguyên tử tại `data_ - 8`, đánh dấu cờ `0x40` tại byte `+0x17`.
  - Tại `0x028f10` (`String::isShared()`): `ldr x8, [x0]; sub x8, x8, #8; ldar x8, [x8]; cmp x8, #2; cset w0, hs; ret`.

### 3.4. Cầu Nối Động ALOG (`0x029b10`) & `JNI_OnLoad` (`0x02a55c`)
- `vcbkit_init_logger_wrapper` (`0x029b10`): Kiểm tra biến đếm thử lại tại `.bss 0x03c0e8` tối đa `5` lần (`cmp w8, #5; b.gt 0x29bf8`), gọi `dlopen("libalog.so", RTLD_LAZY)` (`.rodata 0x02c506`) và `dlsym("alog_write_default_instance")` (`.rodata 0x02c511`), lưu con trỏ hàm tại `.bss 0x03c0e0`.
- `JNI_OnLoad` (`0x02a55c`): Lưu `JavaVM*` tại `.bss 0x03c0f0`, tìm lớp `"com/ss/vcbkit/UnExpected"` (`.rodata 0x02c5af`, lưu `GlobalRef` tại `.bss 0x03c0f8`) và phương thức tĩnh `"notReachHereNative"` với chữ ký `"(Ljava/lang/String;Ljava/lang/String;Ljava/util/Map;)V"` (`.rodata 0x02c5c8` & `0x02c5db`, lưu tại `.bss 0x03c100`), trả về `0x00010004` (`JNI_VERSION_1_4`).
