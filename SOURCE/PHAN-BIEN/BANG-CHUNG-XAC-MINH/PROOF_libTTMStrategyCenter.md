# BẰNG CHỨNG XÁC MINH ĐỐI KHÁNG: `libTTMStrategyCenter.so` (Target 43)

- **Trạng thái kiểm toán**: `VERIFIED_AND_ACCEPTED`
- **Cơ quan thẩm định**: Agent 13 (Adversary Auditor) & Agent 0 (Orchestrator)
- **Đường dẫn nhị phân**: `SOURCE/apktool-res/lib/arm64-v8a/libTTMStrategyCenter.so` (`395,664 bytes`)
- **Dung lượng mã nguồn C++17 tái tạo**: `191,663 bytes` (`12 files` trong `SOURCE/GIAI-MA/libTTMStrategyCenter/`, `0 stubs`)

---

## 1. Bằng chứng Khớp Opcode AArch64 (`OBSERVED`)

### 1.1. `JNI_OnLoad` (`0x2e6cc`, 488 bytes)
- `0x2e6f4..0x2e710`: `mov w2, #6; movk w2, #1, lsl #16` -> yêu cầu `JNI_VERSION_1_6` (`0x00010006`).
- `0x2e728..0x2e750`: Đăng ký **11 hàm JNI** cho lớp `com/tiktok/strategycenter/TTMStrategyCenter` (`0x5196b`) từ bảng `.data.rel.ro` tại `0x62050` (file offset `0x5e050`).
- `0x2e768..0x2e790`: Đăng ký **5 hàm JNI** cho lớp `com/tiktok/strategycenter/bytedt/TTMStrategyCenterByteDTEngineManager` (`0x51c87`) từ bảng `.data.rel.ro` tại `0x62158` (file offset `0x5e158`).

### 1.2. `ttm_sc_list::make_real_index(long)` (`0x41fa0`, 648 bytes)
- `0x41fc8`: `ldp x8, x9, [x19, #0x10]` -> nạp `begin` và `end` của `std::vector<std::any>`.
- `0x41fcc..0x41fdc`: `sub x8, x9, x8; mov x9, #-0x3333333333333334; asr x8, x8, #3; movk x9, #0xcccd; mul x8, x8, x9` -> chia nhanh khoảng cách byte cho `40` (`sizeof(std::any) == 40`) bằng nghịch đảo nhân `0xcccccccccccccccdULL` ($\equiv 5^{-1} \pmod{2^{64}}$).
- `0x41fe0..0x41fe8`: `cmp x20, #0x0; add x9, x20, x8; csel x9, x20, x9, lt` -> chuẩn hóa chỉ số âm `index < 0 ? index + size : index`.

### 1.3. `transformByteDtErrorToTTMErrorCode(signed char)` (`0x4d21c`, 40 bytes)
- `0x4d21c..0x4d224`: `and w8, w0, #0xff; cmp w8, #0x6; b.hi #0x4d23c` -> kiểm tra biên không dấu $[0..6]$.
- `0x4d228..0x4d238`: `adrp x9, #0x52000; sxtb x8, w0; add x9, x9, #0x3d8; ldr w0, [x9, x8, lsl #2]; ret` -> tra bảng `.rodata` tại `0x523d8`: `[0, 401, 402, 403, 404, 405, 406]`.
- `0x4d23c..0x4d240`: `mov w0, #0x197; ret` -> trả về mặc định `407` (`0x197`) khi ngoài đoạn $[0..6]$.
