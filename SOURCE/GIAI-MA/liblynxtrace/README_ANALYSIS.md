# Deep-Dive Binary & Architecture Analysis: `liblynxtrace.so` (`TASK_SO_149` / `TASK-098`)

## 1. Binary Identification & ELF64 Segment Geometry
## 1. Định danh Nhị phân & Hình học Phân đoạn ELF64

- **Library Name / Tên thư viện**: `liblynxtrace.so`
- **Architecture / Kiến trúc**: `AArch64` (`EM_AARCH64`, Little-Endian ELF64 shared object)
- **Exact File Size / Kích thước tệp chính xác**: `51,200 bytes` (`0x00c800`)
- **SONAME**: `liblynxtrace.so`
- **DT_NEEDED Dependencies (`4` libraries)**:
  1. `liblynxbase.so` (`lynx::base::android::InitVM`, `AttachCurrentThread`, `GetClass`, `JavaRef<jobject>::ReleaseLocalRef`)
  2. `liblog.so`
  3. `libm.so`
  4. `libc.so` (`__cxa_finalize`, `__cxa_atexit`, `__cxa_guard_acquire`, `__cxa_guard_release`, `operator delete`)

### ELF64 Section Table (`.dynsym`, `.rela.dyn`, `.rela.plt`, `.rodata`, `.text`, `.data.rel.ro`, `.data`, `.bss`)

| Section | Virtual Address | File Offset | Size (Bytes) | Description (EN / VN) |
|---|---|---|---|---|
| `.dynsym` | `0x000320` | `0x000320` | `1,056` (`44` entries) | `[001..009]` = 9 imports, `[010..043]` = **34 exported symbols** / 9 hàm nhập, 34 hàm xuất |
| `.rela.dyn` | `0x001500` | `0x001500` | `1,488` (`62` entries) | `62` `R_AARCH64_RELATIVE` (`1027`) relocations for vtables, JNI method tables, `.fini_array`, and `.data 0x00c000` / 62 mục tái định vị tương đối |
| `.rela.plt` | `0x001ad0` | `0x001ad0` | `240` (`10` entries) | `10` `R_AARCH64_JUMP_SLOT` (`1026`) PLT entries (`0x004240..0x0042d0`) / 10 khe nhảy PLT |
| `.rodata` | `0x001bc0` | `0x001bc0` | `736` | Class paths (`com/lynx/tasm/base/TraceController`, `com/lynx/tasm/base/TraceEvent`) and 14 JNI method names & signatures / Các chuỗi tên lớp và chữ ký JNI |
| `.text` | `0x004000` | `0x004000` | `532` (`133` instructions) | 18 AArch64 subroutines (`0x004000..0x004210`) / 18 hàm con thực thi AArch64 |
| `.plt` | `0x004220` | `0x004220` | `192` | PLT header (`0x004220..0x00423f`) + 10 PLT jump stubs (`0x004240..0x0042df`) |
| `.data.rel.ro` | `0x008000` | `0x008000` | `496` | `__dso_handle` (`0x008000`), `TraceController` 13-slot vtable (`0x008018`), `TraceController` 4 `JNINativeMethod`s (`0x008080`), `JavaRef<jobject>` 3-slot vtable (`0x0080f0`), `TraceEvent` 10 `JNINativeMethod`s (`0x008108`) |
| `.fini_array` | `0x0081f8` | `0x0081f8` | `16` (`2` entries) | `[0] = 0x004010`, `[1] = 0x004000` (`__cxa_finalize`) |
| `.data` | `0x00c000` | `0x00c000` | `16` | `TraceController::s_instance` (`vptr = 0x008018` at `0x00c000`, `delegate_ = nullptr` at `0x00c008`) |
| `.bss` | `0x00c010` | `0x00c010` | `24` | Guard variable (`0x00c010`), `g_TraceController_clazz` (`0x00c018`), `g_TraceEvent_clazz` (`0x00c020`) |

---

## 2. Disassembly Verification of Key Subroutines
## 2. Đối soát Mã máy AArch64 các Hàm Trọng tâm

### 2.1 `JNI_OnLoad(JavaVM*, void*)` (`0x00403c..0x0040f4`, `188 bytes`)
1. `0x004048: bl #0x4260` -> Calls `lynx::base::android::InitVM(vm)`.
2. `0x00404c: bl #0x4270` -> Calls `lynx::base::android::AttachCurrentThread()` to obtain `JNIEnv*` in `x19`.
3. `0x004050..0x00407c`: Resolves `"com/lynx/tasm/base/TraceController"` (`.rodata 0x001bc0`) via `GetClass`, converts to a GlobalRef via helper `0x0041f4` (`JNIEnv` vtable offset `+0xa8` = `NewGlobalRef`), stores `jclass` at `.bss 0x00c018`, and releases the `ScopedLocalJavaRef` via `0x0041b0`.
4. `0x004080..0x004098`: Loads `TraceController::kMethods` (`4` entries at `.data.rel.ro 0x008080`) and calls `JNIEnv::RegisterNatives` (vtable offset `+0x6b8`, slot `215`) with `w3 = 4`.
5. `0x00409c..0x0040dc`: Resolves `"com/lynx/tasm/base/TraceEvent"` (`.rodata 0x001e80`), stores `jclass` at `.bss 0x00c020`, loads `TraceEvent::kMethods` (`10` entries at `.data.rel.ro 0x008108`), and calls `JNIEnv::RegisterNatives` with `w3 = 10` (`0xa`).
6. `0x0040e8..0x0040f4`: Executes `mov w0, #6; movk w0, #1, lsl #16; ret` (`0x00010006` = `JNI_VERSION_1_6`).

### 2.2 `lynx::trace::TraceController::Instance()` (`0x0040fc..0x004158`, `96 bytes`)
- Uses Itanium C++ ABI thread-safe static initialization:
  - `0x004104..0x00410c`: `ldarb w8, [x8]` (`0x00c010`) + `tbz w8, #0, #0x4120`.
  - If uninitialized (`bit 0 == 0`), calls `__cxa_guard_acquire(0x00c010)` (`0x004128`), registers `~TraceController` (`0x00415c`) on `.data 0x00c000` with `__dso_handle` (`0x008000`) via `__cxa_atexit` (`0x004148`), and calls `__cxa_guard_release(0x00c010)` (`0x004154`).
  - Returns `&s_instance` (`0x00c000`).

---

## 3. Reconstructed C++17 Module Inventory (`SOURCE/GIAI-MA/liblynxtrace/`)
## 3. Danh mục Module C++17 Tái dựng (`SOURCE/GIAI-MA/liblynxtrace/`)

| File | Description (EN / VN) |
|---|---|
| [`lynxtrace_types.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynxtrace/lynxtrace_types.h) | ELF64 geometry constants, `.data`/`.bss` layout structs, `TraceController` 13-slot vtable ABI, 14 `JNINativeMethod` descriptors, and Perfetto protobuf types |
| [`lynxtrace_perfetto_event.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynxtrace/lynxtrace_perfetto_event.h) | Declarations for `TraceEventBeginEx`, `TraceEventEndEx`, `TraceCounterEx`, `GetFlowId`, `GetTraceTimeNs`, `TraceEventCategoryEnabled`, `TrackEvent`, `TrackEvent_LegacyEvent`, and `LynxDebugAnnotation` |
| [`lynxtrace_perfetto_event.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynxtrace/lynxtrace_perfetto_event.cpp) | Full implementation of all 32 Perfetto & Lynx trace functions + optional 256-slot thread-safe telemetry capture ring buffer |
| [`lynxtrace_controller_jni.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynxtrace/lynxtrace_controller_jni.h) | Declarations for `TraceController` singleton (`0x00c000`), D1/D0 destructors (`0x00415c`/`0x004184`), `ScopedLocalJavaRef` (`0x0041b0`), and 14 JNI callbacks |
| [`lynxtrace_controller_jni.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynxtrace/lynxtrace_controller_jni.cpp) | Exact implementation of `ExecuteJniOnLoad` (`0x00403c`), `TraceController::Instance()` (`0x0040fc`), 4 `TraceController` JNI methods (`0x008080`), and 10 `TraceEvent` JNI methods (`0x008108`) |
| [`lynxtrace_interface.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynxtrace/lynxtrace_interface.h) | Exact Itanium C++ ABI mangled exports (`34` symbols in `.dynsym[10..43]`) and `ExportedDynSymDescriptor` directory |
| [`lynxtrace_interface.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynxtrace/lynxtrace_interface.cpp) | All 34 exported `.dynsym` entry points (`JNI_OnLoad`, `_ZN4lynx5trace...`, `_ZN9lynxtrace10TrackEvent...`) |
| [`lynxtrace_pseudocode.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynxtrace/lynxtrace_pseudocode.cpp) | 18 `.text` subroutine descriptors, 10 `.rela.plt` entries, 62 `.rela.dyn` relocations, 60 verified AArch64 opcodes, 23 `.rodata` strings, Perfetto Protobuf wire encoder, and `RunLibLynxTraceSelfTest()` |
