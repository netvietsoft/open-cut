# Forensic Binary Analysis & Clean-Room C++17 Reconstruction: `liblynxbase.so`
# Phân Tích Pháp Y Nhị Phân & Tái Tạo Sạch C++17: `liblynxbase.so`

## 1. Binary Identity & ELF64 Layout / Định Danh Nhị Phân & Bố Cục ELF64

| Property / Thuộc Tính | Value / Giá Trị |Evidence Classification / Phân Loại Bằng Chứng |
|---|---|---|
| **Binary Path** | `SOURCE/apktool-res/lib/arm64-v8a/liblynxbase.so` | `OBSERVED` |
| **File Size** | `232,080 bytes` (`0x38A90`) | `OBSERVED` |
| **SHA-256** | `6f73cb643285f2b6f59960dde9c053141e6f546429faaf7fa66bbae9e1a0d61d` | `OBSERVED` |
| **Architecture** | `AArch64 (EM_AARCH64 = 183)`, 64-bit LSB shared object | `OBSERVED` |
| **Dynamic Symbols (`.dynsym`)** | `449` total (`326` defined `STT_FUNC` + `6` defined `STT_OBJECT` + `117` imports) | `OBSERVED` |
| **`.rodata` Section** | Offset `0x00cc20`, Size `0x001b58` (`7,000 bytes`) | `OBSERVED` |
| **`.text` Section** | Offset `0x014000`, Size `0x01b4b0` (`111,792 bytes`) | `OBSERVED` |
| **`.data.rel.ro` Section** | Offset `0x034000`, Size `0x000790` (`1,936 bytes`) | `OBSERVED` |
| **`.data` Section** | Offset `0x038000`, Size `0x0001e8` (`488 bytes`) | `OBSERVED` |
| **`.bss` Section** | Offset `0x0381e8`, Size `0x000208` (`520 bytes`) | `OBSERVED` |
| **Needed Shared Libraries** | `libandroid.so`, `liblog.so`, `libm.so`, `libc++_shared.so`, `libc.so`, `libdl.so` | `OBSERVED` |

---

## 2. Exported `STT_OBJECT` Vtables & Global Singletons / Bảng Ảo & Singleton Xuất Khẩu

| Virtual Address | Size | Demangled Symbol | Purpose / Vai Trò |
|---|---|---|---|
| `0x034190` | `96 B` | `vtable for lynx::fml::MessageLoopImpl` | Base event loop vtable (`WakeUp`, `Run`, `Terminate`, `Bind`, `UnBind`, `SetMessageLoopRestrictionDuration`, `CanRunNow`) |
| `0x034260` | `72 B` | `vtable for lynx::fml::TaskRunner` | Task dispatcher vtable (`PostTask`, `PostTaskForTime`, `PostMicroTask`, `PostEmergencyTask`, `PostIdleTask`, `PostDelayedTask`, `PostSyncTask`) |
| `0x0344d8` | `40 B` | `vtable for lynx::base::android::JavaRef<_jobject*>` | Base JNI reference wrapper vtable |
| `0x034500` | `96 B` | `vtable for lynx::fml::MessageLoopAndroid` | Android `ALooper` + `timerfd_create` event loop vtable |
| `0x034768` | `40 B` | `vtable for lynx::base::RefCountedStringImpl` | Intrusive ref-counted string with cached `CityHash64` (`+0x28`), `utf8_len` (`+0x30`), `utf16_len` (`+0x34`) |
| `0x0382f8` | `56 B` | `lynx::base::RefCountedStringImpl::Unsafe::kEmptyString` | Pre-allocated empty string singleton initialized in `.init_array` (`0x02da00`) with hash `0x9AE16A3B2F90404FULL` |

---

## 3. Six Core Subsystems & AArch64 Disassembly Proofs / 6 Phân Hệ Cốt Lõi & Bằng Chứng Mã Máy AArch64

### 3.1 `JNI_OnLoad` (`0x01403c..0x01406c`) & `lynx::base::android` (`0x020944..0x023fe8`)
- `JNI_OnLoad` (`0x01403c`) invokes:
  1. `lynx::base::android::InitVM(JavaVM*)` (`0x022e40`: `adrp x8, #0x38000; str x0, [x8, #0x240]` = `0xF9012100`, storing `JavaVM*` at `.bss 0x038240`).
  2. `lynx::base::android::AttachCurrentThread()` (`0x022e88`).
  3. `lynx::fml::MessageLoopAndroid::Register(JNIEnv*)` (`0x024244`), which caches `"android/os/Looper"` (`.rodata 0x00ce0b`) at `.bss 0x038248` and resolves `prepare` (`.bss 0x038250`), `myLooper` (`.bss 0x038258`), `loop` (`.bss 0x038260`), and `quit` (`.bss 0x038268`).
  4. `RegisterJNI_LynxBaseTrace(JNIEnv*)` (`0x029218`), registering `"com/lynx/base/LynxBaseTrace"` (`.rodata 0x00d73a`) native method `nativeInitBaseTrace` (`()V` -> `0x029274`).
  5. `RegisterJNI_Logging(JNIEnv*)` (`0x028bf0`), registering `"com/lynx/tasm/base/LLog"` with 5 native methods at `.data.rel.ro 0x0345b0` (`nativeSetLogOutputByPlatform`, `nativeSetNativeMinLogLevel`, `nativeInternalLog`, `nativeInitALogNative`, `nativeInitLynxLoggingNative`).
  6. Returns `JNI_VERSION_1_6 = 0x00010006` (`mov w0, #6; movk w0, #1, lsl #16` = `0x528000C0`, `0x72A00020` at `0x014060..0x014064`).

### 3.2 `lynx::fml` Event Loop, Task Queues & Synchronization (`0x01499c..0x020838`)
- `MessageLoopTaskQueues` (`0x017d24..0x019ab0`): Singleton (`GetInstance` @ `0x017d24`) managing task queues with macrotask priority queue, microtask FIFO queue, task observers, and cross-thread queue merging (`Merge` @ `0x0194dc`, `Unmerge` @ `0x019718`, `Owns` @ `0x019820`, `IsSubsumed` @ `0x0198c0`).
- `TimePoint::Now()` (`0x01de5c`) jumps directly to `lynx::base::CurrentTimeNanoseconds()` (`0x02d5e0`).
- `TimePoint::CurrentWallTime()` (`0x01de60`) calls `CurrentSystemTimeMicroseconds()` (`0x02d540`) and multiplies by `1,000` (`mov w8, #0x3e8; mul x0, x0, x8` = `0x52807D08`, `0x9B087C00` at `0x01de68..0x01de6c`).
- `PlatformThreadPriority::Setter` (`0x020770`) maps `ThreadPriority` (`0..3`) to `setpriority(PRIO_PROCESS = 0, 0, nice)` with `nice = {10, 5, 0, -2}` (`mov w2, #-2` = `0x12800022` at `0x0207ac`).

### 3.3 RFC 1321 `lynx::base::md5` (`0x01efe4..0x01f0b4`) & `CityHash64` (`0x022314`)
- `lynx::base::md5` (`0x01efe4` & `0x01f050`) loads the 128-bit vector `[0, 0, 0x67452301, 0xEFCDAB89]` from `.rodata 0x00d250` (`ldr q0, [x8, #0x250]` = `0x3DC09500` at `0x01eff8`) and `0x1032547698BADCFEULL` (`0x01eff0..0x01f004`), runs the 64-round compression function `0x01e384` (`mov w13, #0xa478` = `0x52948F0D` at `0x01e3ac`), and formats the 16-byte digest via `0x01ee98` (`"%02x"` at `.rodata 0x00cc73`).
- `CityHash64` (`0x022314`) uses `k0 = 0xC3A5C85C97CB3127ULL`, `k1 = 0xB492B66FBE98F273ULL`, `k2 = 0x9AE16A3B2F90404FULL`.

### 3.4 `DataURIUtil::DecodeDataURI` (`0x029450`), `Base64Decode` (`0x02f290`) & `js_dtoa` (`0x029554`)
- `DataURIUtil::DecodeDataURI` (`0x029450`) searches for the 8-byte little-endian constant `0x2C3436657361623BULL` (`";base64,"` at `0x02946c..0x029480`) and computes output capacity `(b64_len >> 2) * 3 + 2` (`0x029510..0x029518`).
- `js_dtoa` (`0x029554`) masks the sign bit and compares against `0x7FF0000000000000ULL` (`mov x8, #0x7ff0000000000000` = `0xD2EFFE08` at `0x029574`), writing `"null"` (`0x6C6C756E`) on NaN/Infinity, or using the 53-bit integer fast-path `[-0x1FFFFFFFFFFFFF, +0x1FFFFFFFFFFFFF]` with unsigned division by 10 magic `0xCCCCCCCCCCCCCCCDULL` (`umulh x12, x11, x9; lsr x12, x12, #3` at `0x0295dc..0x0295e0`).

### 3.5 High-Precision Time Reciprocal Division (`0x02d520..0x02d65c`)
- Signed division by `1,000` (`0x02d528..0x02d538`): `smulh x8, x0, x8` (`0x9B487C08` at `0x02d538`) with magic `0x20C49BA5E353F7CFULL` (`ceil(2^70 / 1000)`), `asr x9, x8, #7`.
- Signed division by `1,000,000` (`0x02d558..0x02d56c`): `smulh x8, x0, x8` (`0x9B487C08` at `0x02d568`) with magic `0x431BDE82D7B634DBULL` (`ceil(2^82 / 1000000)`), `asr x9, x8, #0x12` (`0x9352FD09` at `0x02d56c`).

---

## 4. Reconstructed Source Inventory / Danh Mục Mã Nguồn Tái Tạo

| File | Role / Vai Trò |
|---|---|
| [`lynxbase_types.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynxbase/lynxbase_types.h) | Core types, `MoveOnlyClosure`, `InlineVector`, `RefPtr`, `TimeDelta`, `TimePoint`, `TaskQueueId` & hardware constants |
| [`lynxbase_fml_loop.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynxbase/lynxbase_fml_loop.h) / [`.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynxbase/lynxbase_fml_loop.cpp) | `MessageLoop`, `MessageLoopImpl`, `MessageLoopAndroid`, `MessageLoopTaskQueues`, `TaskRunner`, `ConcurrentMessageLoop`, `Thread`, `Timer`, `TimedTaskManager` & sync primitives |
| [`lynxbase_string_crypto.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynxbase/lynxbase_string_crypto.h) / [`.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynxbase/lynxbase_string_crypto.cpp) | `FileUtils`, RFC 1321 `md5`, `CityHash64`, `DataURIUtil`, `Base64Decode`, `js_dtoa`, UTF-8/16/32 suite, reciprocal time math & `RefCountedStringImpl` |
| [`lynxbase_jni_log_error.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynxbase/lynxbase_jni_log_error.h) / [`.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynxbase/lynxbase_jni_log_error.cpp) | `JNI_OnLoad`, `lynx::base::android::*`, `JNIConvertHelper`, `LynxError`, `ErrorStorage`, `logging::LogStream`/`LogMessage` & `trace::SetTraceBackend` |
| [`lynxbase_interface.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynxbase/lynxbase_interface.h) / [`lynxbase_pseudocode.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynxbase/lynxbase_pseudocode.cpp) | Public umbrella header & end-to-end binary parity verification suite |
