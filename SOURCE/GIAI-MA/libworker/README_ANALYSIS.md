# Clean-Room Forensic Analysis & C++17 Reconstruction: `libworker.so`
# Phân Tích Pháp Y & Tái Cấu Trúc C++17 Clean-Room: `libworker.so`

## 1. Binary Identity / Định Danh Nhị Phân
- **Library / Thư viện**: `libworker.so`
- **Canonical Task ID**: `TASK-133-RECONSTRUCTION-LIBWORKER` (`TASK_SO_071_libworker`)
- **Size / Dung lượng**: `313,400 bytes` (`313,400 bytes`)
- **SHA-256**: `35c47b55e99c2789000c60cb0fa814c27df1187aee0974a34651b4aee69c2aa6`
- **Architecture / Kiến trúc**: `AArch64 (ARM64-v8a)`
- **Dynamic Dependencies (`DT_NEEDED`)**: `libdl.so`, `libnapi.so`, `liblog.so`, `libquick.so`, `libm.so`, `libc++_shared.so`, `libc.so`
- **Exported `.dynsym` Symbols**: `54` (`JNI_OnLoad`, `GetNapiEnv`, `PostTaskOnJSRunner`, `PostTaskOnDelegateRunner`, `EvaluateJavaScript`, `Bind`, `RegisterVMSDKModules`, `GeneralGlobalRef`, `VMSDKPipe`, `WorkerScope`)
- **Unwind `.eh_frame_hdr` FDE Count**: `572` functions (`0x01c03c..0x0458b8`)
- **Reconstructed C++17 Volume**: `555,108 bytes` across `9` files (`0` stubs)

---

## 2. Core Architecture & Disassembly Anchors / Kiến Trúc Cốt Lõi & Điểm Neo Mã Máy

### 2.1 `JNI_OnLoad` (`0x01c03c..0x01c648`, `1,548 bytes`) & 33 Registered JNI Callbacks
1. Stores `JavaVM*` at `.bss 0x04c000` (`0x01c058..0x01c064`), attaches the current thread with `0x00010002 = JNI_VERSION_1_2` (`0x01c06c..0x01c070`), queries the OS thread name via `prctl(PR_GET_NAME = 0x10)` (`0x01c0a8..0x01c0b0`), and attaches if `GetEnv` returns `JNI_EDETACHED (-2)`.
2. Calls `RegisterNativeall` (`0x0452d0`) on 5 Java classes:
   - `com/bytedance/vmsdk/net/Response` (`1` method at `.data.rel.ro 0x04a978`: `nativeCreateResponse` -> `0x0453b8`)
   - `com/bytedance/vmsdk/thread/SystemThread` (`1` method at `.data.rel.ro 0x0486c0`: `nativeRun` -> `0x021ae8`)
   - `com/bytedance/vmsdk/message/SystemMessageHandler` (`1` method at `.data.rel.ro 0x048410`: `nativeRunWork` -> `0x020a70`)
   - `com/bytedance/vmsdk/worker/JsWorker` via `JsWorkerAndroid::RegisterJni` (`0x03ba34`, `28 = 0x1c` methods at `.data.rel.ro 0x049d28..0x049fc0`)
   - `com/bytedance/vmsdk/jsbridge/CallbackImpl` (`2` methods at `.data.rel.ro 0x048ab8`: `nativeInvoke` -> `0x0265e0`, `nativeReleaseNativePtr` -> `0x026964`)
3. Caches `GlobalRef`s for 11 VMSDK Java classes in `.bss 0x04c0a8..0x04c878` and returns `w21 + 4 = 0x00010002 + 4 = 0x00010006` (`JNI_VERSION_1_6` at `0x01c628: add w0, w21, #4`).

### 2.2 `.rodata` SIMD Constants & Piper JSB Jump Tables (`0x00d860..0x00da5f`)
- **`0x00d860` (`16 bytes`)**: NEON `uint64x2_t` vector `{1ULL, 0xFFFFFFFFFFFFFFFFULL}` (`01 00 00 00 00 00 00 00 ff ff ff ff ff ff ff ff`) loaded at `0x01e0f0`, `0x01e444`, and `0x03380c` to increment `front_index` (+1) and decrement `size` (-1) in a single `add v0.2d, v0.2d, v1.2d` instruction, compacting the task queue when `front_index >= 0x400` (`1024` at `0x01e450`).
- **`0x00d878..0x00d8d9` (`98 bytes`)**: `MethodInvoker` signature char validator table (`0x02a91c..0x02a940`), returning `true` (`table[ch] == 0`) for valid VMSDK JSB signature chars (`'\0', 'A', 'B', 'C', 'D', 'F', 'I', 'L', 'M', 'P', 'S', 'T', 'X', 'Y', 'Z', '`', 'a'`).
- **`0x00d8da..0x00da5f` (`390 bytes`)**: Four position-independent switch jump tables (`MethodInvoker` signature type name @ `0x00d8da`, `MethodInvoker::extractJSValue` @ `0x00d914`, `MethodInvoker` JNI return dispatch @ `0x00d978`, and `JsWorkerAndroid::InvokeJavaScriptModuleInner` return conversion @ `0x00d9ec`).

### 2.3 CityHash64 (`0x022d58..0x0231c4`) & NEON Popcount Hash Table Indexing (`0x022a68` & `0x0374b8`)
- Full Google `CityHash64` (`0x022d58..0x0231c4`, `1,132 bytes`) with exact 64-bit primes `k0 = 0xc3a5c85c97cb3127ULL`, `k1 = 0xb492b66fbe98f273ULL`, `k2 = 0x9ae16a3b2f90404fULL`, `k3 = 0xc949d7c7509e6557ULL`, and `kMul = 0x9ddfea08eb382d69ULL`.
- Bucket index selection at `0x022a68` (`ModuleManager`) and `0x0374b8` (`JsWorkerAndroid` / `VMSDKRuntime`) executes `cnt v0.8b, v0.8b; uaddlv h0, v0.8b` to test `popcount(bucket_count) <= 1`: power-of-two tables use `hash & (bucket_count - 1)`, otherwise `hash % bucket_count` (`udiv` + `msub`).
