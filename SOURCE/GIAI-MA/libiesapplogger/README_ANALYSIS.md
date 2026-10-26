# PHÂN TÍCH KỸ THUẬT & TÁI DỰNG C++17: `libiesapplogger.so` (TARGET 63 / 169)
# TECHNICAL ANALYSIS & C++17 RECONSTRUCTION: `libiesapplogger.so` (TARGET 63 / 169)

- **Task ID**: `TASK-102-RECONSTRUCTION-LIBIESAPPLOGGER` / `TASK_SO_139`
- **Thư viện / Binary**: `extracted/lib/arm64-v8a/libiesapplogger.so` (`67,616 bytes`)
- **Kiến trúc / Architecture**: `AArch64 ELF64 Little-Endian` (`25` ELF64 sections, `123` `.dynsym` entries: `45` imports `[003..047]`, `75` exported symbols `[048..122]`)
- **Trạng thái / Status**: `VERIFIED_AND_ACCEPTED` (**100% Full Reconstruction — Zero Stubs**)

---

## 1. TỔNG QUAN KIẾN TRÚC / ARCHITECTURAL OVERVIEW

**VN**: `libiesapplogger.so` là cầu nối thu thập telemetry và báo cáo sự kiện C++ Native (`IESAppLogger`) của ByteDance. Thư viện cung cấp hai thành phần cốt lõi:
1. **`AppLogReporter` (`80 bytes = 0x50`)**: Singleton quản lý trạng thái bật/tắt báo cáo toàn cục (`+0x30`), danh sách trắng sự kiện lấy mẫu (`std::set<std::string>` Cây Đỏ-Đen tại `+0x38..+0x4f` được đồng bộ từ Java qua `Java_com_bytedance_ies_common_IESAppLogger_nativeSetSampler`), khóa `std::mutex` (`+0x00..+0x27`), và con trỏ hàm gửi sự kiện (`+0x28`, mặc định trỏ tới `appLogFunc` @ `0x004d3c` gọi phương thức Java `com.bytedance.ies.common.IESAppLogger.sharedInstance().appLogOnEvent(appId, eventName, paramsJson, toBusiness)`).
2. **`IESAppLogger::AppLogTracker` (`8-byte pImpl`) & `AppLogTracker::Impl` (`80 bytes = 0x50`)**: Bộ xây dựng chuỗi JSON sự kiện theo mô hình RAII (`reserve(512)` @ `0x005918`, khởi đầu bằng `"{"` @ `0x00c48b`, nối các cặp `"key":val` hoặc `"key":"v0,v1,..."` qua 14 hàm nạp chồng `putVal` và 6 hàm nạp chồng `putVals`, sau đó tự động đóng ngoặc `"}"` @ `0x00c48d` và gọi `AppLogReporter::GetSingleton()->report(...)` trong hàm hủy `~AppLogTracker()` @ `0x005c28`).

**EN**: `libiesapplogger.so` is ByteDance's native C++ telemetry & event reporting bridge (`IESAppLogger`). It provides two primary subsystems:
1. **`AppLogReporter` (`80 bytes = 0x50`)**: A thread-safe singleton managing global report enablement (`+0x30`), an RB-tree event sampler whitelist (`std::set<std::string>` at `+0x38..+0x4f` populated from Java via `Java_com_bytedance_ies_common_IESAppLogger_nativeSetSampler`), a 40-byte `std::mutex` (`+0x00..+0x27`), and a report callback pointer (`+0x28`, defaulting to `appLogFunc` @ `0x004d3c` which invokes `com.bytedance.ies.common.IESAppLogger.sharedInstance().appLogOnEvent(appId, eventName, paramsJson, toBusiness)`).
2. **`IESAppLogger::AppLogTracker` (`8-byte pImpl`) & `AppLogTracker::Impl` (`80 bytes = 0x50`)**: An RAII JSON event builder (`reserve(512)` @ `0x005918`, initialized to `"{"` @ `0x00c48b`, appending `"key":val` or `"key":"v0,v1,..."` across 14 `putVal` and 6 `putVals` overloads, and automatically appending `"}"` @ `0x00c48d` and dispatching `AppLogReporter::GetSingleton()->report(...)` inside `~AppLogTracker()` @ `0x005c28`).

---

## 2. BỐ CỤC SECTION ELF64 & BIẾN TOÀN CỤC `.bss` / ELF64 SECTIONS & `.bss` GLOBALS

| Section / Biến `.bss` | Địa chỉ VA / Offset | Kích thước / Size | Mô tả Chi tiết / Description (OBSERVED) |
|---|---|---|---|
| `.dynsym` | `0x000828` | `2,952 B` | `123` symbols (`45` imports `[003..047]`, `75` exports `[048..122]`) |
| `.rela.dyn` | `0x003038` | `720 B` | `30` dynamic relocations |
| `.rela.plt` | `0x003308` | `1,728 B` | `72` PLT jump-slot relocations |
| `.plt` | `0x0039d0` | `1,184 B` | `72` PLT stubs (`0x0039d0..0x003e6f`) |
| `.text` | `0x003e70` | `33,820 B` | Executable AArch64 instructions (`0x003e70..0x00c28c`) |
| `.rodata` | `0x00c28c` | `705 B` | JNI signatures & JSON formatting literals (`0x00c28c..0x00c54d`) |
| `.data.rel.ro` | `0x013ac8` | `168 B` | `std::__shared_ptr_pointer` vtables for `JNI_OnLoad::$_0` (`0x013ae0`) & `appLogFunc::$_2` (`0x013b30`) |
| `gJvm` | `0x014010` | `8 B` | Exported `JavaVM*` pointer (`.dynsym [053]`, GOT `0x013fe8`) |
| `sReporterSingleton` | `0x014018` | `8 B` | `AppLogReporter*` singleton instance (`80 B = 0x50` allocated @ `0x004cf8`) |
| `sReporterOnceFlag` | `0x014020` | `8 B` | `std::once_flag` state (`ldar x8, [x8]; cmn x8, #1` @ `0x0043e4`) |
| `gAppLogOnEventMethodId` | `0x014028` | `8 B` | Cached `jmethodID` for `IESAppLogger.appLogOnEvent` (@ `0x0041bc`) |
| `gIesAppLoggerInstance` | `0x014030` | `8 B` | Cached `GlobalRef` to `IESAppLogger.sharedInstance()` (@ `0x004250`) |
| `gJavaLangStringClass` | `0x014038` | `8 B` | Cached `GlobalRef` to `java/lang/String` (@ `0x004324`) |
| `gStringCtorMethodId` | `0x014040` | `8 B` | Cached `jmethodID` for `String.<init>([BLjava/lang/String;)V` (@ `0x00439c`) |
| `gJniIdsInitialized` | `0x014048` | `1 B` | Boolean initialization guard (`mov w8, #1; strb w8, [x9, #0x48]` @ `0x0043ac`) |

---

## 3. DANH SÁCH FILE TÁI DỰNG C++17 / RECONSTRUCTED C++17 FILES

1. [`iesapplogger_types.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libiesapplogger/iesapplogger_types.h): Cấu trúc ABI chuẩn xác (`AppLogReporterAbi` `80 B`, `AppLogTrackerImplAbi` `80 B`, `RbTreeNodeStringAbi` `56 B`, `LibcppSsoStringAbi` `24 B`).
2. [`iesapplogger_rbtree_stl.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libiesapplogger/iesapplogger_rbtree_stl.h): Khai báo Cây Đỏ-Đen `std::__ndk1::__tree<std::string>` và chuỗi SSO `std::__ndk1::basic_string<char>`.
3. [`iesapplogger_rbtree_stl.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libiesapplogger/iesapplogger_rbtree_stl.cpp): Triển khai đầy đủ các thuật toán xoay cây Đỏ-Đen (`__tree_balance_after_insert`), tìm kiếm (`find`, `__find_equal`), và quản lý bộ nhớ chuỗi SSO (`reserve`, `__grow_by_and_replace`, `append`, `assign`, `insert`, `operator+`).
4. [`iesapplogger_reporter_jni.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libiesapplogger/iesapplogger_reporter_jni.h): Khai báo `AppLogReporter`, `JNI_OnLoad`, `getEnv`, `nativeSetSampler`, `appLogFunc`.
5. [`iesapplogger_reporter_jni.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libiesapplogger/iesapplogger_reporter_jni.cpp): Triển khai chi tiết `AppLogReporter` singleton và cầu nối JNI.
6. [`iesapplogger_interface.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libiesapplogger/iesapplogger_interface.h): Khai báo `IESAppLogger::AppLogTracker` và `AppLogTracker::Impl`.
7. [`iesapplogger_interface.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libiesapplogger/iesapplogger_interface.cpp): Triển khai toàn bộ 14 hàm `putVal`, 6 hàm `putVals`, và vòng đời RAII JSON builder.
8. [`iesapplogger_pseudocode.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libiesapplogger/iesapplogger_pseudocode.cpp): Bảng ánh xạ 75 biểu tượng `.dynsym [048..122]` và hàm tự kiểm chứng độc lập.
