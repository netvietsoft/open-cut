# Phân Tích Nhị Phân & Tái Dựng C++17: `liblynx_krypton.so` (`TASK-097` / `TASK_SO_151`)

> **Binary Size**: `51,112 bytes` (`ELF64 AArch64`, Android NDK r21d `clang 9.0.8`)  
> **Package**: `com.nextai.opencut` | **Module**: Lynx Krypton WebGL/Canvas Android Bridge (`liblynx_krypton.so`)  
> **Trạng thái đối kháng**: `VERIFIED_AND_ACCEPTED` (Agent 13 Adversary Auditor)  
> **Evidence Classification**: `OBSERVED` (100% Capstone AArch64 Disassembly & ELF64 Relocation Verification)

---

## 1. Kiến Trúc Tổng Quan & Bố Cục Phân Đoạn ELF64 (ELF64 Section Geometry)

`liblynx_krypton.so` là cầu nối JNI Android cho engine đồ họa **Lynx Krypton** (`com.lynx.canvas.*`), chịu trách nhiệm:
1. Cung cấp con trỏ hàm log C++ (`KryptonLogFunction` @ `0x00403c`) và nạp động `liblynxtrace.so` qua `dlopen(..., RTLD_LAZY=2)` / `dlsym` (`TraceEventBeginEx`, `TraceEventEndEx`, `TraceCounterEx`) để gắn vào `lynx::canvas::AttachKryptonTraceHandler`.
2. Quản lý vòng đời `ANativeWindow` cho các bề mặt phụ (`LynxCanvasDownStreamManager`: `nativeAddSurface` @ `0x004328` và `nativeRemoveSurface` @ `0x0045bc`), tự động kiểm tra luồng `TaskRunner` (`vtable + 0x08` @ `0x005158`) và điều phối closure `0x60` byte (`96 B`) hoặc `0x48` byte (`72 B`) qua `TaskRunner::PostTask`.
3. Cầu nối đồng bộ khung hình VSync 2 giai đoạn (`LynxKryptonFrameService`: `RequestVSync` $\rightarrow$ `OnVSync(J)V` và `RegisterBeforeVSyncEndListener` $\rightarrow$ `OnBeforeVSyncEnd(J)V`).
4. Tạo `lynx::canvas::SurfaceWithAndroidNativeWindow` (`32 bytes` / `0x20`) cho `UICanvasSurfaceView.nativeCreateSurface` (`0x004f6c`).

| Phân đoạn (Section) | Địa chỉ Ảo (`vaddr`) | Kích thước (`bytes`) | Vai trò Kỹ thuật (`OBSERVED`) |
|---|---:|---:|---|
| `.dynsym` | `0x000330` | `1,056` | `44` biểu tượng (`[001]..[039]` = 39 imports, `[040]` = `JNI_OnLoad` @ `0x004ff4`, `[041]..[043]` = `_edata`, `_end`, `__bss_start`) |
| `.rela.dyn` | `0x001148` | `1,152` | `48` mục `R_AARCH64_RELATIVE` điền địa chỉ cho 4 bảng `JNINativeMethod` và 5 bảng vtable C++ trong `.data.rel.ro` |
| `.rela.plt` | `0x0015c8` | `936` | `39` mục `R_AARCH64_JUMP_SLOT` ánh xạ PLT `0x005250..0x0054b0` tới `.got.plt 0x008380..0x0084b0` |
| `.rodata` | `0x001970` | `928` | Bảng nhảy 5 mức log tại `0x001970` (`{0x05, 0x09, 0x0b, 0x0d, 0x07}`) và toàn bộ chuỗi tên lớp/chữ ký JNI/thông điệp log |
| `.text` | `0x004000` | `4,656` | `26` hàm con AArch64 (`0x004000..0x00522c`), kết thúc bằng `JNI_OnLoad` (`0x004ff4..0x005124`) và các helper `0x005128..0x00522c` |
| `.data.rel.ro` | `0x008000` | `464` | `.fini_array[0]` (`0x008000`), 4 bảng `JNINativeMethod` (`9` phương thức) và 5 vtable C++ (`0x008090..0x0081b7`) |
| `.bss` | `0x00c000` | `72` | 4 biến `jclass` toàn cục (`0x00c000`, `0x00c020`, `0x00c028`, `0x00c040`), `KryptonTraceFunctions` (`24 B` tại `0x00c008..0x00c01f`), và 2 biến `jmethodID` (`0x00c030`, `0x00c038`) |

---

## 2. Danh Sách 8 Tập Tin Mã Nguồn C++17 Tái Dựng (`0 Stubs`)

1. [`lynx_krypton_types.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynx_krypton/lynx_krypton_types.h): Khai báo hằng số hình học ELF64, cấu trúc `.bss` 72-byte (`KryptonBssSegment`), `KryptonTraceFunctions` (`24 B`), `SurfaceConfig` (`72 B`), `AddSurfaceTaskClosureLayout` (`96 B`), `RemoveSurfaceTaskClosureLayout` (`72 B`), và `VSyncJavaCallbackFunctorLayout` (`24 B`).
2. [`lynx_krypton_trace_log.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynx_krypton/lynx_krypton_trace_log.h) & [`lynx_krypton_trace_log.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynx_krypton/lynx_krypton_trace_log.cpp): Tái dựng `KryptonLogFunction` (`0x00403c..0x004148`), bảng nhảy 5 mức log (`.rodata 0x001970`), `nativeGetLogFunctionPtr` (`0x004160`), và `RuntimeLoadLynxTraceFunc` / `nativeRegisterTraceFunc` (`0x00416c..0x0042fc`).
3. [`lynx_krypton_surface_vsync.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynx_krypton/lynx_krypton_surface_vsync.h) & [`lynx_krypton_surface_vsync.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynx_krypton/lynx_krypton_surface_vsync.cpp): Tái dựng `LynxCanvasDownStreamManager` (`nativeAddSurface` @ `0x004328`, `nativeRemoveSurface` @ `0x0045bc`), `LynxKryptonFrameService` (`0x004bb4..0x004f68`), và `UICanvasSurfaceView` (`0x004f6c..0x004ff0`).
4. [`lynx_krypton_interface.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynx_krypton/lynx_krypton_interface.h), [`lynx_krypton_interface.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynx_krypton/lynx_krypton_interface.cpp), & [`lynx_krypton_pseudocode.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynx_krypton/lynx_krypton_pseudocode.cpp): Tái dựng `JNI_OnLoad` (`0x004ff4..0x005124`), 4 bảng đăng ký `JNINativeMethod`, 48 mục `.rela.dyn`, 39 mục `.rela.plt`, và tự kiểm tra `RunLibLynxKryptonSelfTest()`.
