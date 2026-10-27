# BẰNG CHỨNG XÁC MINH ĐỐI KHÁNG — `libundead_native_ability_q.so` (`TASK-129`)

## 1. Thông tin định danh nhị phân (Binary Identity — `OBSERVED`)
- **Thư viện đích**: `libundead_native_ability_q.so` (ByteDance Vega UG Push Alive "Undead" Keep-Alive Native Ability for Android Q / Android 10+)
- **Dung lượng chính xác**: `264,448 bytes` (`0x40900`)
- **SHA-256**: `fbb084a422d41746a73918169874475da9170f3aae48b099f91d83635aab3d49`
- **Tổng dung lượng C++17 tái dựng sạch**: `328,681 bytes` trên `9` file (`0 stub`, song ngữ Anh-Việt)
- **Số lượng lệnh AArch64 trích xuất đối chiếu**: `1160 lệnh` trên `15` hàm cốt lõi (`.text 0x015b10..0x016d78`)

## 2. Giải phẫu kiến trúc Keep-Alive & NDK Binder (`0x015b10..0x0169d0`)
1. **Hàm khởi tạo tĩnh `.init_array` (`0x015b10..0x015b84`) & Cấu trúc đơn thể `kaAbility` (`.bss 0x0440b8`, `40 bytes` / `0x28`)**:
   - Đăng ký lớp NDK Binder `"android.app.IActivityManager"` (`.rodata 0x0323f3`) qua `AIBinder_Class_define` và `AIBinder_Class_setOnDump`, lưu con trỏ lớp vào `.bss 0x0440b0`.
   - Khởi tạo `kaAbility` (`0x0440b8`, `40 bytes`: `+0x00` `remote_am_binder`, `+0x08` `transact_code`, `+0x0C` `transact_flags`, `+0x10` `parcel_in`, `+0x18` `parcel_out`, `+0x20` `is_initialized`) và đăng ký hàm hủy `ka_ability::~ka_ability` (`0x01618c`) qua `__cxa_atexit`.
2. **Đóng gói `AParcel` & `Bundle` cho `IActivityManager::startInstrumentation` (`init_instr_internal` @ `0x0161c8..0x016450`)**:
   - Ghi `ComponentName` (`pkg_name`, `cls_name`), `profileFile = null`, `flags = 0`, chữ ký ma thuật `BUNDLE_MAGIC = 0x4C444E42` (`'B','N','D','L'` tại `0x0162a8..0x0162ac`), và 3 cặp khóa-giá trị:
     - `"instrumentation_type"` (`0x032410`) -> `"instrumentation_type_ka"` (`0x032425`)
     - `"source_process"` (`0x03243d`) -> `source_process`
     - `"use_native_mode"` (`0x03244c`) -> `1` (`VAL_INTEGER`)
   - Ghi đè độ dài byte của `Bundle` (`bundle_end_pos - bundle_start_pos`) tại `bundle_len_pos` (`0x0163d4..0x0163ec`).
3. **Vòng lặp canh gác `flock` & Đổi thời gian mili-giây nghịch đảo 64-bit (`do_ka` @ `0x015ca8..0x016138`)**:
   - Thực hiện double-fork (`fork()` @ `0x015e84` & `0x015f30`), đổi tên tiến trình qua `modify_process_name` (`prctl(PR_SET_NAME = 0x0f)`), thăm dò khóa tệp `flock(fd, LOCK_EX | LOCK_NB = 6)` mỗi `0x003D0900 = 4,000,000 us` (`4.0 giây` @ `0x015fac..0x015fb4`).
   - Khi tiến trình chính bị dừng (nhận được khóa `flock`), xóa tệp canh gác (`fopen("rw")`, `remove`), tính thời gian thực bằng hằng số nhân nghịch đảo `0x20C49BA5E353F7CFULL` (`0x016098..0x0160b0`) và gọi `start_instr()` (`0x016450`) để bắn trực tiếp giao dịch `AIBinder_transact` đánh thức ứng dụng.
