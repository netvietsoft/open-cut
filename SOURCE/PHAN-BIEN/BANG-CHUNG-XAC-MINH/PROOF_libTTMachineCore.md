# BẰNG CHỨNG XÁC MINH ĐỐI KHÁNG: `libTTMachineCore.so` (Target 44)

- **Trạng thái kiểm toán**: `VERIFIED_AND_ACCEPTED`
- **Cơ quan thẩm định**: Agent 13 (Adversary Auditor) & Agent 0 (Orchestrator)
- **Đường dẫn nhị phân**: `SOURCE/apktool-res/lib/arm64-v8a/libTTMachineCore.so` (`429,872 bytes`)
- **Dung lượng mã nguồn C++17 tái tạo**: `151,517 bytes` (`12 files` trong `SOURCE/GIAI-MA/libTTMachineCore/`, `0 stubs`)

---

## 1. Bằng chứng Khớp Opcode AArch64 (`OBSERVED`)

### 1.1. `ttm_support_max_bytecode_version` (`0x17244`) & `pre_process_byte_code` (`0x1a700`)
- `0x17244..0x17248`: `52800140 mov w0, #0xa; d65f03c0 ret` -> phiên bản bytecode tối đa là `10`.
- `0x1a724..0x1a738`: `mov w9, #0xc02e; movk w9, #0x775c, lsl #16; ldr w8, [x0]; cmp w8, w9; b.ne #0x1a750` -> kiểm tra hằng số ma thuật `0x775cc02e`, trả về mã lỗi `3` (`TTMStateErrorCodeInvalidContent`) nếu sai.
- `0x1a73c..0x1a748`: `ldrh w8, [x0, #4]; cmp w8, #0xa; b.ls #0x1a774` -> kiểm tra `version <= 10`, trả về mã lỗi `4` (`TTMStateErrorCodeGreaterVersion`) nếu vượt quá.

### 1.2. `ttm_state_error_code_for_business(int, int)` (`0x1758c`, 64 bytes)
- `0x1758c..0x175c0`: Kiểm tra `base_code >= 1000`, `base_code % 1000 == 0` bằng phép nhân nghịch đảo `0x26e978d5` kết hợp `extr w8, w8, w8, #3` (`ror #3`) so sánh với `0x00418938`, và `1 <= sub_code <= 1000` (`sub w9, w1, #1; cmp w9, #999`). Trả về `base_code + sub_code` nếu hợp lệ, ngược lại trả về `-1`.

### 1.3. `state_code_names` (`0x6a268`) & 8 `TTMTypeObject` (`0x6c048..0x6c588`)
- `0x6a268` (file `0x66268`, 584 bytes): Bảng 73 con trỏ tên trạng thái lệnh máy ảo từ `State_create_list_direct` (`[0]`) đến `State_bin_op` (`[72]`).
- `0x6c048..0x6c647` (file `0x68048..0x68647`): 8 bộ mô tả kiểu đối tượng 192 byte (`TTMDictO_Type`, `TTMFloatO_Type`, `TTMIntO_Type`, `TTMSeqIterO_Type`, `TTMListO_Type`, `TTMNoneO_Type`, `TTMSliceO_Type`, `TTMStrO_Type`).
