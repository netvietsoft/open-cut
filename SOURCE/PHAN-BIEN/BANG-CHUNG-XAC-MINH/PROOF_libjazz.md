# Bằng Chứng Xác Minh Đối Kháng `libjazz.so` (`TASK-122-RECONSTRUCTION-LIBJAZZ`)
# Adversarial Verification Proof for `libjazz.so`

## 1. Thông Tin Chung / General Metadata
- **Thư viện / Binary**: `libjazz.so` (`231,840 bytes`, SHA-256: `f11496ae99e17699d6f2a2df40043c3014bc8391aab0d6422acc2a63590183e4`)
- **Mã nhiệm vụ / Task ID**: `TASK-122-RECONSTRUCTION-LIBJAZZ` (`TASK_SO_122_libjazz`)
- **Dung lượng C++17/H tái tạo / Reconstructed C++17/H Size**: `144,859 bytes` (9 files, 0 stubs)
- **Tổng số biểu tượng `.dynsym`**: `336` (`182` exported `STT_FUNC`, `18` exported `STT_OBJECT`)

## 2. Đối Chiếu 6 Cổng Kiểm Toán Đối Kháng / 6-Gate Adversarial Verification
1. **Gate 1 (Dung lượng > 40KB)**: `144,859 bytes` C++17/H thực chất trong `SOURCE/GIAI-MA/libjazz/`.
2. **Gate 2 (Khớp Opcode AArch64)**: Đối xuất trực tiếp `sub_17a08` (`0x017a08..0x017a38`), `BEFBaseRunner::_PumpLoop` (`0x00cb34`), `BEFBaseRunner::GetNext` (`0x00cbc4`), `BEFBaseRunner::PostDelayedTask` (`0x00ce74`), `ContextExecutor::ExecuteProgram` (`0x011a44`), `Platform::CreateRuntime` (`0x014fcc`), `Runtime::Runtime` (`0x018fd8`), `VM::CreateVM` (`0x01a46c`), `CreateQuickJSVM` (`0x024638`), `FileSystemModule::Stats` (`0x01d074..0x01d0b0`), `RequireModule` (`0x021618..0x0221ec`), và `TimerModule` (`0x022bb4..0x022f70`).
3. **Gate 3 (Chứng minh toán học & hằng số `.rodata`)**:
   - Bảng hộp thế S-Box 256-byte tại `.rodata 0x028bf0..0x028cf0` thỏa mãn phương trình đại số đóng $\text{SBox}[x] = x \oplus \mathtt{0xF0} \oplus ((x \mathbin{\&} 3) \times \mathtt{0x54})$ và đối hợp tự nghịch đảo $\text{SBox}[\text{SBox}[x]] = x$ trên toàn bộ 256 giá trị.
   - Giải mã chuẩn xác `/bootstrap.js` tại `.rodata 0x027037` (`0x1bb9 = 7,097 bytes` -> `7,096` ký tự) và `makeRequire.js` tại `.rodata 0x0297d2` (`0x0246 = 582 bytes` -> `581` ký tự).
   - Hằng số IEEE-754 double `1000.0` (`0x408f400000000000`) tại `.rodata 0x025b80` và lệnh đếm bit NEON `cnt v0.8b, v0.8b; uaddlv h0, v0.8b` (`0x0220b4`).
4. **Gate 4 (Bố cục Struct ABI)**: Xác minh chuẩn xác kích thước và độ lệch của `BEFBaseRunner` (`+0x4c` `m_cancelled`), `Runtime` (`+0x08` `m_id = -1`, `+0x18` `m_mode`, `+0x68` & `+0x90` `1.0f`), `FileSystemModule::Stats` (`+0x28` `st_mode`, `+0x48` `st_size`), và `TimerModule` (`+0x38` `m_nextTimerId`).
5. **Gate 5 (Demangled Symbols)**: Đầy đủ `336` symbols (`AmazingEngine::*`).
6. **Gate 6 (Kịch bản kiểm thử độc lập)**: Tích hợp `verify_libjazz(self)` trong `SOURCE/scripts/verify_reconstruction_suite.py` (6/6 checks PASS).
