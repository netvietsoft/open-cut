# BÁO CÁO PHÂN TÍCH NHỊ PHÂN & TÁI CẤU TRÚC C++17: `libPitayaBdComponent.so` (TARGET 46)
# BINARY DISASSEMBLY & C++17 RECONSTRUCTION REPORT: `libPitayaBdComponent.so` (TARGET 46)

## 1. Thông Số Nhị Phân Thực Tế (Binary Ground Truth)
- **Đường dẫn / Path**: `extracted/lib/arm64-v8a/libPitayaBdComponent.so`
- **Dung lượng / Size**: `100,176` bytes (`0x18750` bytes), ELF 64-bit LSB shared object, ARM aarch64
- **Phân đoạn nạp / Load Segments**:
  - `PT_LOAD[0]` (R+X): `vaddr 0x000000..0x014730 -> file offset 0x000000..0x014730`
  - `PT_LOAD[1]` (R+W): `vaddr 0x01b5a8..0x01c018 -> file offset 0x0175a8..0x018000` (`file_offset = vaddr - 0x4000`)
- **Tổng số Biểu tượng Động / Dynamic Symbols**: `60` (`14` exported + `46` imported)
- **Dung lượng C++17 đã tái tạo / Reconstructed C++17 Size**: `102,431` bytes trên 10 tệp `.cpp`/`.h` (`0` stubs)

## 2. Đối Chiếu Opcode AArch64 & Cấu Trúc ABI (Opcode & ABI Parity)
1. **`JStringToStdString` (`0x00264c`, 296 B)**:
   - Gọi `JNIEnv::GetStringUTFChars` tại độ lệch vtable `+0x548` (`0x002690: f942a508 ldr x8, [x8, #0x548]`) và `ReleaseStringUTFChars` tại `+0x550` (`0x002734: f942a908 ldr x8, [x8, #0x550]`).
2. **`Java_com_bytedance_pitaya_bdcomponentimpl_crash_NpthStackReporter_nativeGenerateAllStack` (`0x002780`, 132 B)**:
   - Lấy singleton `pitaya::PitayaNpthUtil::Instance()` (`0x002804`), chuyển đổi `jstring dir_path` sang `std::string` (`0x00264c`), và gọi `GenerteTombstone` (`0x002898`).
3. **`pitaya::PitayaNpthUtil` (`72` bytes = `0x48` @ `0x002848`) & `ThreadStackInfo` (`96` bytes = `0x60` @ `0x0029e0`)**:
   - `GenerteTombstone` (`0x002898`, 488 B): Gọi `npth_bt_all(dir_path.c_str())` (`0x0028d8`), phân tích ngăn xếp qua `ParseOriginStack` (`0x002a80`), mở `"%s/tombstone.txt"` (`0x012325`) với cờ `0x80042` (`O_RDWR | O_CREAT | O_CLOEXEC`) và mode `0x180` (`0600`), ghi từng khối luồng qua `WriteThreadTombstone` (`0x004098`) và `WriteBuildIds` (`0x004258`).
   - Ưu tiên luồng Pitaya `"pty-ord-t"` (`0x012421`): Các luồng có tên chứa `"pty-ord-t"` được chèn vào đầu danh sách (`vector::insert(begin(), info)` @ `0x003338 -> 0x0048b8`).
4. **Toán Học Nghịch Đảo Nhân 64-bit (`0xaaaaaaaaaaaaaaabULL`)**:
   - Chia cho `24` (`sizeof(std::sub_match)`): `(byte_diff >> 3) * 0xaaaaaaaaaaaaaaabULL` (`0x002e54..0x002e68`).
   - Chia cho `96` (`sizeof(ThreadStackInfo)`): `(byte_diff >> 5) * 0xaaaaaaaaaaaaaaabULL` (`0x0048e0..0x00490c`).
5. **`Java_com_bytedance_pitaya_bdcomponentimpl_monitor_ALogPrinter_nativeGetFuncAddr` (`0x004c54`, 340 B)**:
   - Nhánh chính: `dlopen("libalog.so", 0x102)` (`0x004c6c`) + `dlsym(handle, "alog_write")` (`0x004c7c`), log `"dl success!"` (`0x0124b8` = `0x0124b3 + 5`).
   - Nhánh dự phòng: `npth_dlopen("libalog.so")` (`0x004cd0`) + `npth_dlsym(handle, "alog_write")` (`0x004ce0`), log `"npth_dl success!"` (`0x0124b3`).
