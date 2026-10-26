# BẰNG CHỨNG XÁC MINH ĐỐI KHÁNG — `libpns_ttmachine_adapter.so` (Target 47 / TASK_SO_111)
# ADVERSARIAL VERIFICATION PROOF — `libpns_ttmachine_adapter.so` (Target 47 / TASK_SO_111)

- **Tệp nhị phân gốc / Original Binary**: `apktool-res/lib/arm64-v8a/libpns_ttmachine_adapter.so` (`330,032 bytes`)
- **Tổng dung lượng C++17 tái tạo / Reconstructed C++17 Size**: `150,427 bytes` across 10 files (`0 stubs`)
- **Tổng số ký hiệu động / Total Dynamic Symbols**: `165` (`27` exported + `138` imported)
- **Trạng thái / Status**: `VERIFIED_AND_ACCEPTED` (**47 / 169**)

---

## 1. Đối Soát Opcode AArch64 Thực Tế (Gate 2) / AArch64 Disassembly Verification

| Địa chỉ VA | Opcode Hex | Lệnh AArch64 | Ý nghĩa Kỹ thuật / Technical Meaning |
|---|---|---|---|
| `0x00746c` | `00498052` | `mov w0, #0x248` | `init_array_0`: Cấp phát `JniCacheTable` (`584 B`) lưu vào `0x0541e8` |
| `0x0074bc` | `14f0a752` | `mov w20, #0x3f800000` | `init_array_1`: Khởi tạo `max_load_factor = 1.0f` cho map tại `0x054208` & `0x054230`, nhảy tới `0x014598` |
| `0x007ed4` | `3f8000f1` | `cmp x1, #0x20` | `ComputeNdkStringHash64` (`CityHash64` với `k0=0xc3a5c85c97cb3127`, `k2=0x9ae16a3b2f90404f`) |
| `0x008868` | `fc6fbaa9` | `stp x28, x27, [sp, #-0x60]!` | `Java_com_bytedance_pns_pns_1ttmachine_1adapter_TTMAdapter_init` (`7,012 B`) |
| `0x00c188` | `ff4302d1` | `sub sp, sp, #0x90` | `Java_com_bytedance_pns_pns_1ttmachine_1adapter_TTMAdapter_validate3` (`544 B`) |
| `0x00c3a8` | `ffc302d1` | `sub sp, sp, #0xb0` | `Java_com_bytedance_pns_pns_1ttmachine_1adapter_TTMAdapter_attribution` (`844 B`) |
| `0x00d430` | `ff0301d1` | `sub sp, sp, #0x40` | `JNI_OnLoad` (`224 B`): Đăng ký 9 hàm `JNINativeMethod` tại `0x054000` lên `RuleEngineService` |
| `0x00d510` | `ff0306d1` | `sub sp, sp, #0x180` | `active` (`1,644 B`): Phân tích cấu hình JSON chiến lược & khởi tạo `RuleEngine` (`0x02b66c`) |
| `0x00e400` | `f50f1df8` | `str x21, [sp, #-0x30]!` | `destroy` (`148 B`): Khóa `pthread_rwlock_wrlock` (`0x055680`), giải phóng `RuleEngine` |
| `0x00e494` | `ff4307d1` | `sub sp, sp, #0x1d0` | `validate` (`1,332 B`): Thực thi cây quyết định chiến lược đồng bộ/bất đồng bộ |
| `0x00f8ec` | `ff0302d1` | `sub sp, sp, #0x80` | `isInNameList` (`764 B`): Kiểm tra giá trị trong `NameListManager` (`0x03963c` & `0x03ac80`) |
| `0x00fc7c` | `c0035fd6` | `ret` | `update` (`4 B`): Hàm rỗng trả về trực tiếp |
| `0x00fc80` | `280200b0` | `adrp x8, #0x54000` | `isActivated` (`20 B`): Đọc `ldarb w8, [0x0541f8]; and w0, w8, #1` |
| `0x00fc94` | `f44fbea9` | `stp x20, x19, [sp, #-0x20]!` | `getStrategyVersion` (`192 B`): Đọc `ldr w19, [x8, #0xc8]` dưới `pthread_rwlock_rdlock` |
| `0x00fd54` | `00008092` | `mov x0, #-1` | `getGetConstPoolVersion` (`8 B`): Trả về `-1` |
| `0x00fd5c` | `fc6fbaa9` | `stp x28, x27, [sp, #-0x60]!` | `loadConstPoolExtra` (`360 B`): Duyệt `List<String>` gọi `0x0318a8` |
| `0x0360f0` | `fa67bba9` | `stp x26, x25, [sp, #-0x50]!` | `_Z36calculate_network_sample_rate_resultPPvPdS1_S1_S1_S1_P22__TTMTransparentStruct` (`332 B`) |
| `0x03623c` | `fc0f1df8` | `str x28, [sp, #-0x30]!` | `_Z5isHitPd` (`388 B`): Bộ sinh số giả ngẫu nhiên `std::mt19937` 624 từ (`0x270`) |
| `0x0363c0` | `ff0302d1` | `sub sp, sp, #0x80` | `_Z12isInNameListPlPPvS1_S_P22__TTMTransparentStruct` (`548 B`) |
| `0x0365e4` | `ff8302d1` | `sub sp, sp, #0xa0` | `_Z21isDomainPathMatchListPlPPvS1_S1_S_P22__TTMTransparentStruct` (`768 B`) |
| `0x0368e4` | `ff0306d1` | `sub sp, sp, #0x180` | `_Z26isDomainPathMatchConditionPlPPvS1_S1_S_P22__TTMTransparentStruct` (`1,480 B`) |
| `0x036eac` | `e80f1bfc` | `str d8, [sp, #-0x50]!` | `_Z10randomSeedPlPPvPdP22__TTMTransparentStruct` (`484 B`) |

---

## 2. Chứng Minh Toán Học & Thuật Toán (Gate 3) / Mathematical Proofs

1. **Thuật toán lấy mẫu Mersenne Twister MT19937 (`0x03623c..0x036388` & `0x036fd4..0x037004`)**:
   - Khởi tạo mảng trạng thái $N = 624$ (`0x270`) từ `seed & 0xffffffff` với hệ số nhân $f = 1812433253$ (`0x6c078965` tại `0x036280..0x03628c`):
     $$S_i = \left(1812433253 \times \left(S_{i-1} \oplus (S_{i-1} \gg 30)\right) + i\right) \bmod 2^{32}, \quad i \in [1, 623]$$
   - Xoắn (Twist) 2 từ đầu tiên với $M = 397$ (`sp + 0xc68` tại `0x0362e0`) và đa thức `MATRIX_A = 0x9908b0df` (`0x0362ec..0x0362f0`).
   - Tôi luyện (Tempering) tại `0x036314..0x036368`:
     $$y \leftarrow y \oplus (y \gg 11), \quad y \leftarrow y \oplus ((y \ll 7) \mathbin{\&} \text{0x9d2c5680}), \quad y \leftarrow y \oplus ((y \ll 15) \mathbin{\&} \text{0xefc60000}), \quad y \leftarrow y \oplus (y \gg 18)$$
   - Chuyển đổi sang số thực chuẩn IEEE-754 $[0, 1)$ tại `0x0362bc..0x036388` (`0x41f0000000000000` $= 2^{32}$, `0x3bf0000000000000` $= 2^{-64}$):
     $$U = \left(\text{double}(z_1) \times 2^{32} + \text{double}(z_0)\right) \times 2^{-64}$$
2. **Hàm băm chuỗi 64-bit `CityHash64` (`0x007ed4..0x008338`)**:
   - Được gọi tại `0x036fc0` trong `_Z10randomSeed`: sử dụng các hằng số chuẩn `k0 = 0xc3a5c85c97cb3127`, `k1 = 0xb492b66fbe98f273`, `k2 = 0x9ae16a3b2f90404f`, `k3 = 0xc949d7c7509e6557`, `kMul = 0x9ddfea08eb382d69`.

---

## 3. Bố Cục Struct ABI & Bảng `.data` / `.bss` (Gate 4)

- **Bảng `JNINativeMethod` (9 phần tử $\times 24\text{ B} = 216\text{ B}$ tại `0x054000..0x0540d8`, file offset `0x050000..0x0500d8`)**:
  Đăng ký lên lớp `"com/bytedance/pns/engine/RuleEngineService"` (`0x044029`) trong `JNI_OnLoad` (`0x00d430`).
- **`JniCacheTable` (`0x248 = 584 bytes` tại `0x0541e8`)**:
  Được cấp phát trong `init_array_0` (`0x007460`) và nạp bởi `0x00fec4` & `0x0103a0`.
- **`RuleEngine` (`0xd0 = 208 bytes` tại `0x02b6ac`, vtable `0x0533b0`)**:
  Chứa `ConstPoolConfig` (`0x40 = 64 B` tại `+0x60`), `std::recursive_mutex` tại `+0x70`, và `strategy_version_` (`int32_t`) tại `+0xc8` (đọc tại `0x00fcf8`).
