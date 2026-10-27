# BẰNG CHỨNG XÁC MINH ĐỐI KHÁNG — `libttmverifylite.so` (`TASK-180`)

- **Thư viện**: `libttmverifylite.so` (`34,672 bytes`)
- **SHA-256**: `672829f9be725b6867d86d6e0e2620361626c87539784cb7b300b71bedf3e5b5`
- **Dung lượng C++17 phòng sạch**: `508,906 bytes` trên 3 tệp (`ttmverifylite.hpp`, `ttmverifylite_core.cpp`, `ttmverifylite_elf_sections_and_image.cpp`)
- **Số lượng FDE**: `13` FDEs tại `.eh_frame_hdr 0x4d1c`
- **Số lượng lệnh `.text`**: `2,742` lệnh AArch64 (`0x11f0..0x3cc8`)

## Đối chiếu Opcode AArch64 thực tế
| Địa chỉ VA | Mã máy (Hex) | Lệnh hợp ngữ AArch64 | Hàm / Ý nghĩa |
|---|---|---|---|
| `0x11fc` | `f85fbca9` | `stp x24, x23, [sp, #-0x40]!` | Mở khung ngăn xếp `av_cert_hostcheck` (`7,252 B`) |
| `0x1270` | `ae79aeb8` | `ldrsw x14, [x13, x14, lsl #2]` | Tra bảng nhảy tương đối 32-bit tại `.rodata 0x3cc8` |
| `0x2e50` | `ff0302d1` | `sub sp, sp, #0x80` | Mở khung ngăn xếp `validate_hostname` (`844 B`) |
| `0x2ea8` | `a10a8052` | `mov w1, #0x55` | `NID_subject_alt_name = 85` cho `X509_get_ext_d2i` |
| `0x3288` | `08040051` | `sub w8, w0, #1` | `convertToVerifyRet`: dịch miền `1..4` về `0..3` |
| `0x3290` | `e0279f1a` | `cset w0, lo` | `convertToVerifyRet`: trả về `1` nếu `(uint32_t)(status-1) < 4` |
| `0x3298` | `ff0301d1` | `sub sp, sp, #0x40` | `registerNativeMethods` cho `gCustomVerify` (`0xc008`) |
| `0x337c` | `f50f1df8` | `str x21, [sp, #-0x30]!` | `init_clsz` khởi tạo `com/ss/ttffmpeg/CustomVerify` |
| `0x3578` | `f657bda9` | `stp x22, x21, [sp, #-0x30]!` | `ToJavaByteArray` (`100 B`) |
| `0x35dc` | `ff0302d1` | `sub sp, sp, #0x80` | `ToJavaArrayOfByteArray` (`440 B`) |
| `0x3794` | `ff0302d1` | `sub sp, sp, #0x80` | `vcn_internal_custom_verify_android` (`952 B`) |
| `0x3b4c` | `ffc301d1` | `sub sp, sp, #0x70` | `JNI_OnLoad` (`356 B`, `"Jun 26 2025"`, `"12:29:14"`) |
| `0x3cb0` | `c0035fd6` | `ret` | `JNI_OnUnload` (`4 B`) |
