# Clean-Room Forensic Analysis & C++17 Reconstruction: `libflipped.so`
## Phân Tích Pháp Y Nhị Phân & Tái Tạo C++17 Sạch: `libflipped.so`

- **Task ID**: `TASK-164-RECONSTRUCTION-LIBFLIPPED` (`TASK_SO_165_libflipped`) — Target 125 / 169
- **Binary Size / Kích thước nhị phân**: `7,320 bytes` (`0x1c98` bytes)
- **SHA-256**: `30aabc89f03ef6f8659469596f8a7e8cd65a1950b3bcc853e4caddcc92eb56b0`
- **Unwind FDEs**: `15` FDEs at `.eh_frame_hdr` (`0x000a68..0x000aec`)
- **Exported Symbols**: `8` (`_Z3LOGPKci`, `_Z3LOGPKcS0_`, `_Z3LOGPKc`, `_Z19AttachCurrentThreadv`, `_Z19DetachCurrentThreadv`, `_Z25GetDeclaredMethodInternalPv`, `_Z17GetDeclaredMethodP7_JNIEnvP8_jobjectS2_P8_jstringP13_jobjectArray`, `JNI_OnLoad`)
- **Reconstructed C++17 Volume**: `178,317 bytes` across 5 files (`0` stubs)

## Key Binary Forensics (Bằng Chứng Nhị Phân Trực Tiếp)
1. **Cơ chế vượt rào Hidden API trên Android 11+ (`FlippedV2Impl`)**:
   - Đăng ký phương thức JNI `getDeclaredMethod(Object, String, Class[]) -> Method` cho lớp `com/bytedance/mira/plugin/hook/flipped/compat/FlippedV2Impl` (`.rodata` `0x0980`, `.data.rel.ro` `0x5288`).
   - Khi được gọi tại `GetDeclaredMethod` (`0x0f40`), hàm chuyển đổi `clazz`, `name` và từng phần tử của `args` sang `NewGlobalRef` (`0x11a4`, vtable `+0xa8`), đóng gói vào struct 24 byte tại `sp + 0x10` và tạo một luồng POSIX thuần C++ mới qua `pthread_create` (`0x1044`) thực thi `GetDeclaredMethodInternal` (`0x0dc4`).
   - Trên luồng POSIX mới (không có bất kỳ khung ngăn xếp Java nào!), `GetDeclaredMethodInternal` gọi `AttachCurrentThread` (`0x0d1c`, `JavaVM` vtable `+0x20`), tra cứu `Class.getDeclaredMethod(String, Class[])` (`vtable +0x108` @ `0x0e0c`) và gọi `CallObjectMethodV` (`0x0ea4..0x0f18`, `vtable +0x118`). Vì ngăn xếp không có ClassLoader ứng dụng, ART coi lời gọi xuất phát từ hệ thống gốc và cho phép truy cập mọi Hidden API!
