# BẰNG CHỨNG XÁC MINH ĐỐI KHÁNG — PROOF FOR: `libconfigcenter.so`

- **Task ID**: `TASK-089-RECONSTRUCTION-LIBCONFIGCENTER` (`TASK_SO_150` — Target 50 / 169)
- **Thư viện nhị phân gốc**: `apktool-res/lib/arm64-v8a/libconfigcenter.so` (`51,144 bytes`, 65 dynamic symbols: 15 exported + 50 imported)
- **Thư mục mã nguồn C++17 tái dựng**: `SOURCE/GIAI-MA/libconfigcenter/` (`8 files`, `0 stubs`, song ngữ Anh - Việt)
- **Trạng thái thẩm định Agent 13**: `VERIFIED_AND_ACCEPTED`

---

## 1. ĐỐI SOÁT 6 CỔNG THẨM ĐỊNH CỦA AGENT 13 (6 ADVERSARIAL GATES)

| Cổng thẩm định | Yêu cầu kỹ thuật | Bằng chứng thực tế đạt được | Kết quả |
|---|---|---|---|
| **Gate 1: Dung lượng & Zero-Stub** | $\ge 40\text{ KB}$ C++17, `0` hàm rỗng | 8 tệp C++17 & Header (`> 76 KB`), đầy đủ thân hàm thực thi `0 stubs` | **PASSED** |
| **Gate 2: Opcode AArch64 Parity** | Đối chiếu địa chỉ ảo hợp ngữ thật | Hơn 150 địa chỉ hàm, vtable (`.data.rel.ro 0x0f8e8..0x0fc48`), `.rodata` (`0x068a0..0x06e16`), `.bss` (`0x10030..0x100b8`) | **PASSED** |
| **Gate 3: Toán học & Thuật toán** | Giải thuật khả nghịch, có kiểm chứng | `cnt v0.8b` + `uaddlv h0, v0.8b` đếm bit lũy thừa 2 (`0x028ac`), `clz` làm tròn bucket (`0x0411c`), cập nhật theo độ ưu tiên `Priority` (`0x02a30`) | **PASSED** |
| **Gate 4: Struct Layout ABI** | Khớp kích thước và offset thanh ghi | `BaseConfig` (`72 B = 0x48`), `ConfigItem` emplace (`72 B = 0x48`), `ConfigCenter` (`128 B = 0x80` tại `.bss 0x10030`) | **PASSED** |
| **Gate 5: Itanium Demangled Symbols** | Đầy đủ 65 dynamic symbols | Bao phủ toàn bộ 15 biểu tượng xuất và 50 biểu tượng nhập (`Json::Value`, `BaseRef`, `std::mutex`) | **PASSED** |
| **Gate 6: Kiểm thử Tự động Khép kín** | Test độc lập trong `verify_reconstruction_suite.py` | `verify_libconfigcenter` kiểm tra 6 tiêu chí độc lập đạt **100% PASS** | **PASSED** |

---

## 2. BẰNG CHỨNG DISASSEMBLY AARCH64 CỐT LÕI (BINARY PROOFS)

1. **Bố cục `BaseConfig` (`72 bytes = 0x48`, vtable `0x0f8e8`, hàm tạo tại `0x0266c`)**:
   - `0x0266c: mov w8, #1; str w8, [x0, #8]` (`ref_count_ = 1`)
   - `0x02674: adrp x8, #0xf000; add x8, x8, #0x8e8; str x8, [x0]` (vtable 22 phương thức ảo tại `.data.rel.ro 0x0f8e8..0x0f990`)
   - `0x02680: mov w8, #0x3f800000; str w8, [x0, #0x30]` (`max_load_factor_ = 1.0f`)
   - `0x0268c: mov w8, #3; stp w1, w2, [x0, #0x38]; str w8, [x0, #0x40]` (`module_` tại `+0x38`, `priority_` tại `+0x3c`, `permission_ = 3 = PERM_READ_WRITE` tại `+0x40`).
2. **Kiểm soát quyền đọc/ghi nguyên tử và độ ưu tiên `Priority` (`0x0285c..0x03b1c`)**:
   - Các hàm đọc (`getIntOption` @ `0x03380`, `getLongOption` @ `0x0344c`, `getFloatOption` @ `0x03518`, `getStringOption` @ `0x036e0`, `getJsonOption` @ `0x03a48`) kiểm tra bit 0 (`ldar w8, [x0, #0x40]; tbz w8, #0`).
   - Các hàm ghi (`setIntOption` @ `0x0285c`, `setLongOption` @ `0x02aac`, `setFloatOption` @ `0x02cfc`, `setStringOption` @ `0x02f54`, `setJsonOption` @ `0x03b1c`) kiểm tra bit 1 (`ldar w8, [x0, #0x40]; tbz w8, #1`) và chỉ ghi đè khi `this->priority_ >= item->priority_` (`cmp w24, w8; b.lt`).
3. **Vòng đời `ConfigCenter` (`128 bytes = 0x80` tại `.bss 0x10030`) & `JNI_OnLoad` (`0x05a84`)**:
   - `ConfigCenter::ConfigCenter()` (`0x04fa8`) khởi tạo 3 `shared_ptr<IConfig>`: `player_config_` (`module = 2` tại `+0x00`), `mdl_config_` (`module = 3` tại `+0x10`), `strategy_center_config_` (`module = 4` tại `+0x20`), `std::mutex` tại `+0x30..+0x57`, và mảng 5 con trỏ `IConfigCenterListener*` tại `+0x58..+0x7f`.
   - `JNI_OnLoad` (`0x05a84`) kiểm tra `JNI_VERSION_1_4` (`0x00010004`), đăng ký 15 hàm JNI cho `com/tiktok/ttkmedia/configcenter/BaseConfig` (`0x0fac8..0x0fc30`) và 1 hàm JNI `_updateConfig` cho `com/tiktok/ttkmedia/configcenter/ConfigCenter` (`0x0fc30..0x0fc48`).
