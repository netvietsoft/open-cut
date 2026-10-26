# BẰNG CHỨNG XÁC MINH ĐỐI KHÁNG (ADVERSARIAL PROOF): `libCepEngine.so`

- **Thư viện mục tiêu**: `libCepEngine.so` (`362,464 bytes`, ELF64 AArch64, 318 dynamic symbols: 266 exported + 52 imported, 13 JNI exports)
- **Dung lượng C++17 & Header tái cấu trúc**: `271,814 bytes` (`271.8 KB` trên 12 file `.h`/`.cpp`, `0 stubs`)
- **Trạng thái thẩm định 6 cổng (6-Gate Audit)**: `VERIFIED_AND_ACCEPTED`

---

## 1. Bằng chứng Opcode AArch64 trực tiếp (Gate 2)
1. **`ApiVersion()` (`0x0c33c`, 8 B)** & **`cep::DataInterface::InterfaceType()` (`0x0c4e8`, 8 B)** & **`cep::NativeData::InterfaceType()` (`0x2930c`, 8 B)**:
   - `0x0c33c`: `52800040 mov w0, #2; d65f03c0 ret` -> `ApiVersion() == 2`.
   - `0x0c4e8`: `52800040 mov w0, #2; d65f03c0 ret` -> `DataInterface::InterfaceType() == 2`.
   - `0x2930c`: `52800020 mov w0, #1; d65f03c0 ret` -> `NativeData::InterfaceType() == 1`.
2. **`cep::DataInterface` VTable (`_ZTVN3cep13DataInterfaceE` @ `0x5a9d8`, 120 B) & Type Checks (`0x0c4f8..0x0c764`)**:
   - `IsInt` (`0x0c680: 7100001f cmp w0, #0`), `IsFloat` (`0x0c6a4: 7100041f cmp w0, #1`), `IsBool` (`0x0c6c8: 7100081f cmp w0, #2`), `IsStr` (`0x0c6ec: 71000c1f cmp w0, #3`), `IsList` (`0x0c710: 7100101f cmp w0, #4`), `IsDict` (`0x0c734: 7100141f cmp w0, #5`), `IsNull` (`0x0c758: 7100181f cmp w0, #6`).
   - `ConvertToIntValue` (`0x0c4f8`, 136 B): gọi vtable `+0x10` (`IntValue()`), `+0x18` (`FloatValue()` + `9e780000 fcvtzs x0, d0`), hoặc `+0x20` (`BoolValue()` + `92400000 and x0, x0, #1`).
   - `ConvertToDoubleValue` (`0x0c580`, 136 B): gọi vtable `+0x10` (`IntValue()` + `9e620000 scvtf d0, x0`), `+0x18` (`FloatValue()`), hoặc `+0x20` (`BoolValue()` + `1e630100 ucvtf d0, w8`).
3. **`cep::Env::Instance()` (`0x243a8`, 248 B)**:
   - Khởi tạo singleton tại `.bss 0x5c558` (guard `.bss 0x5c650`):
   - `0x24444`: `5285c628 mov w8, #0x2e31; 72a5c6a8 movk w8, #0x2e35, lsl #16` -> chuỗi SSO `"1.5.0"` tại `+0x58`.
   - `0x243f8`: `52800c89 mov w9, #0x64` -> `100` cho `max_queuing_events_count_` (`+0xa0`), `max_matches_count_` (`+0xa8`), `max_matched_events_length_` (`+0xb0`).
   - `0x24404..0x24428`: `52927c08 mov w8, #0x93e0; 72a00088 movk w8, #4, lsl #16` -> `0x493e0 = 300000 ms` tại `+0xc0` và `+0xd0`.

---

## 2. Chứng minh Toán học (Gate 3)
- **Phép chia cố định có dấu 64-bit cho 1000 trong `cep::GetCurrentTimestamp()` (`0x41e94..0x41ec0`, 48 B)**:
  - Mã máy:
    ```
    0x41e9c: 97ff2899  bl    #0xc100                 // std::chrono::system_clock::now() -> us in x0
    0x41ea0: d29ef9e8  mov   x8, #0xf7cf
    0x41ea4: f2bc6a68  movk  x8, #0xe353, lsl #16
    0x41ea8: f2d374a8  movk  x8, #0x9ba5, lsl #32
    0x41eac: f2e41888  movk  x8, #0x20c4, lsl #48    // x8 = 0x20c49ba5e353f7cf
    0x41eb0: 9b487c08  smulh x8, x0, x8              // high 64 bits of (x0 * M)
    0x41eb4: 9347fd09  asr   x9, x8, #7              // x8 >> 7 (total shift 64 + 7 = 71)
    0x41eb8: 8b48fd20  add   x0, x9, x8, lsr #63     // sign correction for negative x0
    ```
  - Chứng minh:
    $$M = \left\lceil \frac{2^{71}}{1000} \right\rceil = \left\lceil \frac{2361183241434822606848}{1000} \right\rceil = 2361183241434822607 = \text{0x20C49BA5E353F7CF}$$
    Lệnh `smulh` lấy 64 bit cao (tương đương dịch phải 64 bit), tiếp theo `asr x9, x8, #7` dịch phải thêm 7 bit (tổng cộng $64 + 7 = 71$ bit), và `add x0, x9, x8, lsr #63` cộng bit dấu để làm tròn về 0 đối với số âm, cho kết quả chính xác tuyệt đối $\text{ms} = \text{trunc}(\text{us} / 1000)$.

---

## 3. Đối soát Bố cục Struct ABI (Gate 4)
- **`cep::EngineConfig` (`104 bytes`, `0x13a48..0x144bc`)**:
  - `+0x00..+0x0f`: `std::enable_shared_from_this<EngineConfig>` (`weak_this_`)
  - `+0x10`: `extra_` (`void*`, `0x13a5c: str x1, [x0, #0x10]`)
  - `+0x18`: `match_timeout_inference_strategy_` (`int32_t`, `0x13b30: str w1, [x0, #0x18]`)
  - `+0x1c`: `overwrite_` (`bool`, `0x13aa4: strb w9, [x0, #0x1c]`)
  - `+0x1d`: `debug_` (`bool`, `0x13aec: strb w9, [x0, #0x1d]`)
  - `+0x20`: `max_matched_events_length_` (`int64_t`, `0x13b74: str x1, [x0, #0x20]`)
  - `+0x28`: `max_matches_count_` (`int64_t`, `0x13bb8: str x1, [x0, #0x28]`)
  - `+0x30`: `max_queuing_count_` (`int64_t`, `0x13bfc: str x1, [x0, #0x30]`)
  - `+0x38`: `process_mode_` (`int32_t`, `0x13c40: str w1, [x0, #0x38]`)
  - `+0x40..+0x67`: `variables_` (`std::unordered_map`, `max_load_factor = 0x3f800000` tại `+0x60`)
- **`cep::Semaphore` (`96 bytes`, `0x431cc..0x43450`)**:
  - `+0x00..+0x27`: `std::mutex mutex_` (`40 B`)
  - `+0x28..+0x57`: `std::condition_variable cv_` (`48 B`, `0x43444: add x0, x19, #0x28`)
  - `+0x58..+0x5f`: `unsigned long count_` (`8 B`, `0x4342c: ldr x8, [x19, #0x58]`)
