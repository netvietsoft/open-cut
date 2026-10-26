# BÁO CÁO NGHIỆM THU TÁI DỰNG C++17: `libart_sym.so` (Target 72 / 169)
# C++17 RECONSTRUCTION ACCEPTANCE REPORT: `libart_sym.so`

- **Report ID**: `REPORT_TASK_SO_131_libart_sym`
- **Task ID**: `TASK_SO_131_libart_sym` / `TASK-111-RECONSTRUCTION-LIBART_SYM`
- **Thư viện mục tiêu / Target Library**: `libart_sym.so` (`124,720 bytes`, SHA-256: `cb71702453fff0d212d2b7f20aac4c905fdc3e13333538bc0c305b1ad36532e8`)
- **Trạng thái / Status**: `VERIFIED_AND_ACCEPTED` (100%)
- **Tổng dung lượng C++17 tái dựng**: `249,155 bytes` (`art_sym_pseudocode.cpp` = `95,864 bytes`, `0 stubs`)

## Tóm tắt kết quả / Findings Summary
1. **`art::ArtMethod` & `art::ArtClassLinker` (`0x013340..0x013f9b`, `0x015a44..0x016143`)**: Khám phá `entry_point_index_` (`.data 0x025ef8 = -1`) qua 4 chiến lược dự phòng (`IsQuickToInterpreterBridge`, `art_quick_to_interpreter_bridge`, `SetEntryPointsForObsoleteMethod` + `art_invoke_obsolete_method_stub`, và `CreateResolutionMethod` + `art_quick_resolution_trampoline`).
2. **`art::ArtMethodModifier`, `art::ArtFieldModifier` & `art::DisableHiddenApi` (`0x013f9c..0x01541b`)**: Dò tìm `dexMethodIndexIndex` (`.bss 0x026078`), `accessFlagsIndex` (`.data 0x025efc`), `methodIndexIndex` (`.data 0x025f00`, kiểm tra `== 11 = 0x0b`), và `declaringClassIndex` (`.data 0x025f04`), chỉnh sửa cờ truy cập phương thức/trường và vượt rào Hidden API trên Android 9+ (`String[]{"L"}` qua `VMRuntime_setHiddenApiExemptions` hoặc JVMTI `+0x3d8`).
3. **Thăm dò bộ nhớ qua nhân Linux & Canary 2 lượt (`0x01541c..0x015860`)**: Kiểm tra con trỏ an toàn không gây `SIGSEGV` bằng cách ghi thử vào `"/dev/random"` (`O_WRONLY = 1`) trong `IsValidPtr` (`0x0154a4`), và đo kích thước đối tượng bằng 2 lượt canary (`0x12345678` và `0x2468acf0`) trong `DetectObjectSize` (`0x0155f4`).
4. **`art::Heap`, `ArtInstrumentation`, `Jit`, `ReaderWriterMutex` & `Locks` (`0x016144..0x01871b`)**: Khám phá `min_alloc_space_size_for_sticky_mark_sweep_` (`3 * getpagesize()`), phân tích `dalvik.vm.heapsize` (`<< 20`), kiểm tra `_ZTVN3art5MutexE + 0x10`, và dò tìm các khóa toàn cục trong `art::Locks`.
5. **`art::ArtRuntime`, `ArtThread`, `ThreadList` & Các lớp RAII (`0x01871c..0x01b5bf`)**: Khám phá toàn diện `art::Runtime::instance_`, kiểm tra ngưỡng `JitOptions` (`0x2720`, `0x2800`, `0xffff`), và dò tìm `ThreadList::thread_suspend_timeout_ns_index_` (`.data 0x025f08 = -1`) bằng vùng nhớ `calloc(1, 0x4000)` + hằng số `12345678` (`0x00bc614e`).
6. **`ScopedPLTHook`, `bytesig_*` & 3 hàm `.init_array` (`0x01b5c0..0x01c10c`)**: Vá GOT tạm thời dưới sự bảo vệ của `bytesig_protect` (`SIGSEGV=11, SIGTRAP=5`, `SA_FLAGS=0x58000004`, `0x110` byte/slot) và kiểm tra tập lệnh nguyên tử LSE (`HWCAP_ATOMICS = 0x100`, `ro.arch != "exynos9810"`).
