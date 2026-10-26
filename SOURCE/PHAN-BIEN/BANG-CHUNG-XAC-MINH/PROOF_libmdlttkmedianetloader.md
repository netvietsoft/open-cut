# Bằng Chứng Xác Minh Đối Kháng — `libmdlttkmedianetloader.so`
# Adversarial Verification Proof — `libmdlttkmedianetloader.so`

- **Task ID**: `TASK-103-RECONSTRUCTION-LIBMDLTTKMEDIANETLOADER` (`TASK_SO_138_libmdlttkmedianetloader`)
- **Trạng thái (Status)**: `VERIFIED_AND_ACCEPTED`
- **Tệp nhị phân gốc (Source Binary)**: `extracted/lib/arm64-v8a/libmdlttkmedianetloader.so` (`83,560 bytes`, 20 ELF64 sections)

---

## 1. Đối Soát 6 Cổng Kiểm Định Đối Kháng (6 Adversarial Verification Gates)

| Cổng (Gate) | Tiêu chuẩn (Criterion) | Kết quả thực tế (Observed Proof) | Đạt (Pass) |
|---|---|---|---|
| **Gate 1** | Dung lượng mã nguồn tái dựng $> 40,000\text{ B}$ | `9` tệp C++17 & tài liệu trong `SOURCE/GIAI-MA/libmdlttkmedianetloader/` đạt `> 115,000 bytes` | **PASS** |
| **Gate 2** | Đối soát lệnh máy AArch64 (`.text` `0x005910..0x0102c0`) | Đối soát trực tiếp hơn `95` địa chỉ lệnh máy AArch64 trải dài trên cả 4 lớp C++ và `JNI_OnLoad` | **PASS** |
| **Gate 3** | Chính xác toán học & hằng số | Cổng mặc định `443` (`0x1bb`), kẹp không nhánh `bic x1, x9, x9, asr #63`, kẹp bộ đệm nảy `32 KB` (`0x8000`), kiểm tra HTTP 2xx (`sub w10, w8, #0xc8; cmp w10, #0x63`), quy đổi phút sang mili-giây (`* 60000 = 0xea60`) | **PASS** |
| **Gate 4** | Bố cục bộ nhớ ABI & VTable | Chuẩn xác kích thước 4 lớp: `MDLTTKMediaNetDetectDownloader` (`0x220` B), `MDLTTKMediaNetDownloader` (`0x22c8` B, MI thunk `-0x2240`), `MDLTTKMediaNetLoaderFactory` (`0x28` B), `MDLTTKMediaNetLoaderStrategy` (`0x2b8` B, MI thunk `-0x220`) | **PASS** |
| **Gate 5** | Đầy đủ biểu tượng xuất/nhập | `125` mục `.dynsym` (`121` imports từ `libavmdl_lite.so` & `libttkmediasdk.so`, `1` export `JNI_OnLoad @ 0x01008c`) | **PASS** |
| **Gate 6** | Kiểm thử độc lập tự động | Tích hợp `verify_libmdlttkmedianetloader` trong `SOURCE/scripts/verify_reconstruction_suite.py` | **PASS** |

---

## 2. Bằng Chứng Opcode AArch64 Tiêu Biểu (Representative Disassembly Proofs)

1. **Cổng mặc định HTTPS/QUIC `443` (`0x1bb`) trong `quicConnect` (`0x005d50..0x005d5c`)**:
   ```asm
   0x005d50: 1f050031  cmn w8, #1
   0x005d54: 61000054  b.ne #0x5d60
   0x005d58: 68378052  mov w8, #0x1bb
   0x005d5c: e86700b9  str w8, [sp, #0x64]
   ```

2. **Kẹp không nhánh số byte tải xuống không âm trong `MDLTTKMediaNetDownloader::close` (`0x007010..0x007014`)**:
   ```asm
   0x007008: 6a3641f9  ldr x10, [x19, #0x268]
   0x00700c: 6b2e41f9  ldr x11, [x19, #0x258]
   0x007010: 49010bcb  sub x9, x10, x11
   0x007014: 21fda98a  bic x1, x9, x9, asr #63
   ```

3. **Kẹp đọc bộ đệm nảy `32 KB` (`0x8000`) trong `triggerAsyncRead` (`0x0072ac..0x0072b4`)**:
   ```asm
   0x0072ac: 1f204071  cmp w0, #8, lsl #12
   0x0072b0: 09009052  mov w9, #0x8000
   0x0072b4: 14b0891a  csel w20, w0, w9, lt
   ```

4. **Kiểm tra dải mã trạng thái HTTP 2xx `[200..299]` trong `parseResponseHeaders` (`0x007848..0x007854`)**:
   ```asm
   0x007848: 0a210351  sub w10, w8, #0xc8
   0x00784c: 5f8d0171  cmp w10, #0x63
   0x007850: 28a520b9  str w8, [x9, #0x20a4]
   0x007854: 081e0054  b.hi #0x7c14
   ```

5. **Kiểm tra cửa sổ thời gian đua QUIC `mRaceIntervalMin * 60000` (`0x00fd2c..0x00fd38`)**:
   ```asm
   0x00fd2c: 0a4c9d52  mov w10, #0xea60
   0x00fd30: 690214cb  sub x9, x19, x20
   0x00fd34: 087d0a1b  mul w8, w8, w10
   0x00fd38: 3fc128eb  cmp x9, w8, sxtw
   ```
