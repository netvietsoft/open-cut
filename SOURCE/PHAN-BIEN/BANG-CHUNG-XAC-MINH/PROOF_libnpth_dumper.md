# Bằng Chứng Xác Minh Nhị Phân & Toán Học — `libnpth_dumper.so`

- **Task ID**: `TASK_SO_076_libnpth_dumper` / `TASK-108-RECONSTRUCTION-LIBNPTH_DUMPER`
- **Dung lượng nhị phân gốc**: `90,384 bytes` (`28` ELF64 sections, `160` `.dynsym` entries, PIE executable `/system/bin/linker64`)
- **Dung lượng mã nguồn C++17 tái tạo**: `> 120,000 bytes` trên 9 tệp `.h`/`.cpp` tại `SOURCE/GIAI-MA/libnpth_dumper/` (`0` stubs)

## 1. Đối Chiếu Opcode AArch64 Thực Tế
1. **`0x000270` (`.interp`)**: `2f 73 79 73 74 65 6d 2f 62 69 6e 2f 6c 69 6e 6b 65 72 36 34 00` (`"/system/bin/linker64\0"`).
2. **`0x007aa0` (`_start`)**: `5f 24 03 d5 1d 00 80 d2 1e 00 80 d2 e0 03 00 91` (`bti j; mov x29, #0; mov x30, #0; mov x0, sp`).
3. **`0x007b40` (`__aarch64_ldadd8_acq_rel`)**: `20 00 e0 f8 c0 03 5f d6 02 00 80 d2 28 fc 5f c8 09 01 02 8b 2a fc 09 c8` (`ldaddal x0, x0, [x1]; ret; mov x2, #0; ldaxr x8, [x1]; add x9, x8, x2; stlxr w10, x9, [x1]`).
4. **`0x008140` (`dumper_main` sigaction flags)**: `93 00 80 52 13 00 a2 72` (`mov w19, #4; movk w19, #0x1000, lsl #16` -> `0x10000004`).
5. **`0x0081bc` (`dumper_main` watchdog alarm)**: `c0 03 80 52` (`mov w0, #0x1e` -> `alarm(30)`).
6. **`0x0081d8` (`dumper_main` pipe packet size)**: `01 56 82 52` (`mov w1, #0x12b0` -> `4,784 bytes`).
7. **`0x0084a8` (`FPSIMD_MAGIC` check)**: `2a 00 90 52 0a ca a8 72` (`mov w10, #0x8001; movk w10, #0x4650, lsl #16` -> `0x46508001`).
8. **`0x008d4c` (`DivideSignedBy1000`)**: `08 7d 49 9b` (`smulh x8, x8, x9` với `0x20c49ba5e353f7cf`).
9. **`0x00fb3c` (`CrashProtectorEngine` `"PROT004\x02"`)**: `09 4a 8a d2 e9 89 aa f2 09 06 c6 f2 89 46 e0 f2` (`0x02343030544f5250ULL`).
10. **`0x010760` (`CrashProtectorEngine` `"V002"`)**: `ca 0a 86 52 0a 46 a6 72` (`0x32303056`).
11. **`0x010dcc` (`DecodeUnsignedLeb128`)**: `20 19 19 33` (`bfi w0, w9, #7, #7`).
12. **`0x01167c` & `0x0116a0` (`MinidumpGenerator` raw syscalls)**: `c8 07 80 d2 01 00 00 d4` (`__NR_lseek = 62`) & `08 08 80 d2 01 00 00 d4` (`__NR_write = 64`).
13. **`0x012bf4` (`MinidumpGenerator` `"LEBp"`)**: `88 a9 88 52 08 4e a8 72` (`0x4270454c`).
14. **`0x013764` (`CountCpuCoresFromPresentMask`)**: `21 58 20 4e 21 28 20 6e 20 68 60 6e 00 b8 b1 4e` (`cnt` -> `uaddlp` -> `uadalp` -> `addv`).
15. **`0x005fc0` (`.rodata` `MDRawHeader`)**: `4d 44 4d 50 93 a7 00 00` (`"MDMP"` + `0x0000a793`).
