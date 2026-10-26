# BẰNG CHỨNG XÁC MINH ĐỐI KHÁNG (ADVERSARIAL PROOF): `libiesapplogger.so`

- **Task ID**: `TASK-102-RECONSTRUCTION-LIBIESAPPLOGGER` / `TASK_SO_139`
- **Thư viện / Target Binary**: `extracted/lib/arm64-v8a/libiesapplogger.so` (`67,616 bytes`)
- **Tổng dung lượng C++17 tái dựng / Reconstructed Code Size**: `122,777 bytes` (`8` C++17 & Header files + `README_ANALYSIS.md`, `0 stubs`)
- **Kết luận của Agent 13 / Adversary Verdict**: `VERIFIED_AND_ACCEPTED`

---

## 1. BẰNG CHỨNG OPCODE NHỊ PHÂN AArch64 / AARCH64 OPCODE EVIDENCE

### 1.1. `JNI_OnLoad` (`0x003f60..0x004128`) & `initJniIds` (`0x00412c..0x0043bc`)
- `0x003f8c`: `f9000100 str x0, [x8]` — Lưu `JavaVM*` vào `gJvm` (`0x014010`, GOT `0x013fe8`).
- `0x003fb0`: `52800400 mov w0, #0x20 ; 97fffec0 bl #0x3ab0 (_Znwm)` — Cấp phát khối điều khiển `32 byte` (`0x20`) cho `std::shared_ptr<int>` với vtable `.data.rel.ro 0x013ae0` (`Z10JNI_OnLoadE3$_0`) tự động gọi `DetachCurrentThread` (`0x004c70`) nếu luồng mới được đính kèm (`attached == 0`).
- `0x0041bc..0x0043ac`: Lưu các `jmethodID` và `GlobalRef` vào `.bss` (`0x014028` = `appLogOnEvent`, `0x014030` = `IESAppLogger.sharedInstance()`, `0x014038` = `java/lang/String`, `0x014040` = `String.<init>([BLjava/lang/String;)V`, `0x014048` = `1`).

### 1.2. `AppLogReporter::GetSingleton()` (`0x0043c0..0x00443c`) & Hàm khởi tạo `80 byte` (`0x004cf0..0x004d38`)
- `0x0043e4`: `c8dffc08 ldar x8, [x8] ; b100051f cmn x8, #1` — Kiểm tra cờ `std::once_flag` tại `0x014020`.
- `0x004cf4`: `52800a00 mov w0, #0x50 ; 97fffb6e bl #0x3ab0 (_Znwm)` — Cấp phát `80 byte` (`0x50`) cho `AppLogReporter`.
- `0x004d04..0x004d1c`:
  - `+0x00..+0x27`: `std::mutex` (`40 byte`)
  - `+0x28`: `report_func_` = `0x004d3c` (`appLogFunc`)
  - `+0x30`: `enabled_` = `1` (`mov w9, #1; strb w9, [x0, #0x30]`)
  - `+0x38..+0x4f`: `std::set<std::string> sampler_set_` (`24 byte`).

### 1.3. `IESAppLogger::AppLogTracker` & `AppLogTracker::Impl` (`0x005878..0x0083f0`)
- `0x00588c` & `0x0059e4` & `0x005b60` & `0x005bd0`: `52800a00 mov w0, #0x50 ; bl _Znwm` — Cấp phát `80 byte` (`0x50`) cho `AppLogTracker::Impl`.
- `0x005914`: `52804001 mov w1, #0x200 ; bl reserve` — Dự trữ `512 byte` (`0x200`) cho `json_buffer_` (`+0x30`) và gán `"{"` (`0x00c48b`).
- `0x008204..0x008214`: `b201f3f7 mov x23, #-0x5555555555555556 ; f2955577 movk x23, #0xaaab ; 9343fd29 asr x9, x9, #3 ; 9b177d29 mul x9, x9, x23` — Phép chia số học điểm cố định `(end - begin) / 24` để tính số phần tử `std::vector<std::string>` trong `putVals`.
