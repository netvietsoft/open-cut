# Báo Cáo Nghiệm Thu Tái Cấu Trúc Clean-Room: `libosfix.so` (`TASK_SO_075_libosfix` / `TASK-112-RECONSTRUCTION-LIBOSFIX`)

- **Thư viện mục tiêu**: `libosfix.so` (`149,616 bytes`, SHA-256: `ddd8baabbcdd7941b13ab0e961a57e92843d957a0c64e6afa3613b2c433c937d`)
- **Trạng thái**: `VERIFIED_AND_ACCEPTED` (100% Hoàn thành — `0` stubs)
- **Tổng dung lượng C++17 Clean-Room**: `163,822 bytes` (`osfix_pseudocode.cpp` = `83,681 bytes`)

## Kết Quả Tái Cấu Trúc 3 Phân Hệ & 12 Hàm JNI Xuất Khẩu
1. **`com.bytedance.osfix.NativeToolUtil` (`0x005d50..0x0090d0`)**:
   - Khởi tạo `std::shared_timed_mutex` (`144 bytes`) tại `.bss 0x028040` trong `.init_array[0]` (`0x005d50`).
   - `nativeCrash` (`0x005e7c`: `brk #1`), `nativeOOM` (`0x005e80`: cấp phát lặp 50 MB = `0x3200000` byte mỗi 2 giây), `logSoLoader` (`0x005ef0`: đăng ký callback `dlopen` của ByteHook và gọi `NativeToolUtil.alogDelay`), `nlogcatI` (`0x006168`).
   - `fixGetSetEnvCall` (`0x0064ec`): Hook `setenv` (`0x00627c`, khóa ghi độc quyền) và `getenv` (`0x00633c`, khóa đọc chia sẻ) qua `bytehook_hook_partial`.
   - `logGetEnvErrorCode` (`0x006570`): Hook `__android_log_assert` (`0x006678`, đọc 7 khe Bionic TLS từ `tpidr_el0` và ngủ 1000 giây) và `SkAnimatedImage::decodeNextFrame` (`0x0063e4`) trong `libhwui.so` qua ShadowHook.
   - `is64runtime` (`0x006b50`), `logVdexOpen` (`0x006b58`), `fixVdexRepeatOpen` (`0x008d58`) & `freeVdex` (`0x006f9c`: quét `/proc/self/smaps` bằng regex `(\w{8})-(\w{8})` và `Pss:\s+(\d+)\skB`, gọi `munmap` nếu `Pss <= 1024 kB`).
2. **`com.bytedance.osfix.ThreadStackOptimizer` (`0x01681c..0x016b9b`)**:
   - `nativeShrinkthread` (`0x016b7c` -> `0x016908`): Tra cứu `_ZN3art6Thread14CreateCallbackEPv` và `_ZN3art6Thread24CreateCallbackWithUffdGcEPv` trong `libart.so` qua `npth_dlopen`/`npth_dlsym`, hook `pthread_create` (`0x01681c`), cấp phát `pthread_attr_t` (`0x38` = 56 byte) và ghi đè `stack_size` (`+0x10`) bằng `java_shrink_thread_size` (`.data 0x028008` = `0x30000`) hoặc `native_shrink_thread_size` (`.data 0x02800c` = `0x80000`).
3. **`com.bytedance.osfix.TypeFaceOptimizer` (`0x016b9c..0x01814f`)**:
   - `optimize` (`0x016b9c`) & `nativeClearUnuseTTF` (`0x017dc0` -> `0x017428` & `0x016ba4`): Quét `/proc/self/maps` và `/proc/self/smaps` tìm `"Pss:"` (`0x3a737350`) trước `"VmFlags"`, gọi `munmap` nếu `Pss <= 1023 kB` (`0x3ff`).
