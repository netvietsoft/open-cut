# Bằng Chứng Xác Minh Đối Kháng `libvcbasekit.so` (`TASK-121-RECONSTRUCTION-LIBVCBASEKIT`)
# Adversarial Verification Proof for `libvcbasekit.so`

## 1. Thông Tin Chung / General Metadata
- **Thư viện / Binary**: `libvcbasekit.so` (`231,568 bytes`, SHA-256: `d5a87dc8436f7ee8aa114f986f5c9c556b534d4dae750d4f69cbc1b38f679129`)
- **Mã nhiệm vụ / Task ID**: `TASK-121-RECONSTRUCTION-LIBVCBASEKIT` (`TASK_SO_072_libvcbasekit`)
- **Dung lượng C++17/H tái tạo / Reconstructed C++17/H Size**: `136,499 bytes` (9 files, 0 stubs)
- **Tổng số biểu tượng `.dynsym`**: `559` (`399` exported `STT_FUNC`, `54` exported `STT_OBJECT`)

## 2. Đối Chiếu 6 Cổng Kiểm Toán Đối Kháng / 6-Gate Adversarial Verification
1. **Gate 1 (Dung lượng > 40KB)**: `136,499 bytes` C++17/H thực chất trong `SOURCE/GIAI-MA/libvcbasekit/`.
2. **Gate 2 (Khớp Opcode AArch64)**: Đối xuất trực tiếp `_GLOBAL__sub_I_json_value.cpp` (`0x00f9b0`), `BaseRef::addRef/decRef` (`0x021740..0x021794`), `AutoWaitEvent` & `ManualWaitEvent` (`0x021a3c..0x021da8`), `TimePoint<Clock::Fast1>::now` (`0x027db8`), `com::ss::vcbkit::String` (`0x028ad4..0x029154`), `vcbkit_init_logger_wrapper` (`0x029b10`), `JNI_OnLoad` (`0x02a55c`), và `UnExpected::reportStack` (`0x02a698`).
3. **Gate 3 (Chứng minh toán học & hằng số `.rodata`)**:
   - 9 hằng số giới hạn số nguyên `Json::Value` tại `.rodata 0x02bec8..0x02bf08`.
   - Công thức `TimePoint<Clock::Fast1>::now()`: `tv_sec * 0x3B9ACA00ULL + tv_nsec` (`madd x0, x9, x10, x8` tại `0x027e04`).
   - Công thức chuỗi 24-byte 3 tầng `com::ss::vcbkit::String` (`0x17 - size` cho SSO, mặt nạ dung lượng `0x3FFFFFFFFFFFFFFFULL` cho Medium `0x80`, và bộ đếm tham chiếu nguyên tử 8-byte tại `data_ - 8` cho Large COW `0x40`).
4. **Gate 4 (Bố cục Struct ABI)**: Xác minh chuẩn xác kích thước và độ lệch của `BaseRef` (`+0x08` ref_count), `AutoWaitEvent`/`ManualWaitEvent` (`+0x00` CondVar, `+0x30` Mutex, `+0x58` `is_signaled_`), và `String` (`0x18 = 24 bytes`).
5. **Gate 5 (Demangled Symbols)**: Đầy đủ `559` symbols (`Json::*` và `com::ss::vcbkit::*`).
6. **Gate 6 (Kịch bản kiểm thử độc lập)**: Tích hợp `verify_libvcbasekit(self)` trong `SOURCE/scripts/verify_reconstruction_suite.py` (6/6 checks PASS).
