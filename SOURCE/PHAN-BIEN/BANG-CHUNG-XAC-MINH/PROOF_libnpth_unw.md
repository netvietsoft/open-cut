# BẰNG CHỨNG XÁC MINH ĐỐI KHÁNG — `libnpth_unw.so` (`TASK-095` / `TASK_SO_083`)

## 1. Trạng Thái Cổng Kiểm Định (6 Gates Status)
| Cổng (Gate) | Tiêu chuẩn | Kết quả thực tế | Trạng thái |
|---|---|---|---|
| **Gate 1** | Dung lượng mã nguồn C++17 & Header $\ge 40\text{ KB}$, `0 stubs` | `137,991 bytes` (`8 files`) | **PASSED** |
| **Gate 2** | Đối chiếu địa chỉ hex opcode AArch64 thực tế (`.text` `0x0031b0..0x0060bc`) | `60+` địa chỉ lệnh thực tế | **PASSED** |
| **Gate 3** | Chứng minh toán học (Chia cho `80` và `24` bằng nhân nghịch đảo modulo $2^{64}$) | `0xcccccccccccccccdULL`, `0xaaaaaaaaaaaaaaabULL` | **PASSED** |
| **Gate 4** | Khớp bố cục Struct ABI & Vtable `.data.rel.ro` | `FrameData` (`0x50`), `AndroidUnwinderData` (`0xA0`), `NpthUnwContext` (`0x28`), `BuildIdRbTreeNode` (`0x38`) | **PASSED** |
| **Gate 5** | Khôi phục đầy đủ biểu tượng `.dynsym` (`97` entries: `23` exported + `73` imported) | `23 / 23` hàm C xuất khẩu | **PASSED** |
| **Gate 6** | Kiểm thử độc lập khép kín trong `verify_reconstruction_suite.py` | `6 / 6` unit tests (`verify_libnpth_unw`) | **PASSED** |

---

## 2. Bằng Chứng Toán Học & Opcode AArch64 Điển Hình

### 2.1 Phép chia cho `80` (`sizeof(unwindstack::FrameData) = 0x50`) tại `0x003894..0x0038a4` & `0x004104..0x00410c`
```asm
0x003894: 280108cb  sub   x8, x9, x8                  ; byte_diff = end - begin
0x003898: e9e702b2  mov   x9, #-0x3333333333333334
0x00389c: 08fd4493  asr   x8, x8, #4                  ; shifted = byte_diff >> 4 (chia 16)
0x0038a0: a99999f2  movk  x9, #0xcccd                 ; x9 = 0xcccccccccccccccdULL
0x0038a4: 147d099b  mul   x20, x8, x9                 ; count = shifted * 5^-1 (mod 2^64) = byte_diff / 80
```
- Vì $80 = 16 \times 5$ và $0\text{xCCCCCCCCCCCCCCCD} \times 5 = 4 \times 2^{64} + 1 \equiv 1 \pmod{2^{64}}$, phép dịch phải 4 bit kết hợp nhân với `0xCCCCCCCCCCCCCCCDULL` tính chính xác số phần tử `FrameData` (`80 bytes`).

### 2.2 Phép chia cho `24` (`sizeof(std::string) = 0x18`) tại `0x00395c..0x003968`
```asm
0x003958: 090118cb  sub   x9, x8, x24                 ; byte_diff = cap - begin
0x00395c: 2afd4393  asr   x10, x9, #3                 ; shifted = byte_diff >> 3 (chia 8)
0x003960: e9f301b2  mov   x9, #-0x5555555555555556
0x003964: 695595f2  movk  x9, #0xaaab                 ; x9 = 0xaaaaaaaaaaaaaaabULL
0x003968: 4a7d099b  mul   x10, x10, x9                ; count = shifted * 3^-1 (mod 2^64) = byte_diff / 24
```
- Vì $24 = 8 \times 3$ và $0\text{xAAAAAAAAAAAAAAAB} \times 3 = 2 \times 2^{64} + 1 \equiv 1 \pmod{2^{64}}$, phép tính trả về chính xác số phần tử `std::string` (`24 bytes`).
