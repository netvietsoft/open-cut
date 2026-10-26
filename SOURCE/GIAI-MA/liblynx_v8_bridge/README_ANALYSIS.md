# Deep Binary Reverse Engineering & C++17 Reconstruction Report: `liblynx_v8_bridge.so`
# Báo Cáo Dịch Ngược Nhị Phân Chuyên Sâu & Tái Dựng C++17: `liblynx_v8_bridge.so`

## 1. Binary Identification & ELF64 Layout / Định Danh Nhị Phân & Bố Cục ELF64

| Property / Thuộc tính | Value / Giá trị |
|---|---|
| **Library Name / Tên thư viện** | `liblynx_v8_bridge.so` |
| **Task ID** | `TASK-109-RECONSTRUCTION-LIBLYNX_V8_BRIDGE` / `TASK_SO_134_liblynx_v8_bridge` |
| **File Size / Dung lượng** | `117,008 bytes` (`0x1C910`) |
| **SHA-256** | `a056a8578279f5b2aa07946891d83c060858fcdde25c31096bb3cdd09a53ad65` |
| **Architecture / Kiến trúc** | `AArch64 (ARM64-v8a, Little-Endian, ELF64 DYN)` |
| **ELF Sections / Số phân đoạn** | `26 sections` (`1:1 File Offset == Virtual Address` for `.rodata`, `.text`, `.plt`, `.data.rel.ro`, `.data`) |
| **Dynamic Symbols (`.dynsym`)** | `188 entries` (`178 imports`, `9 defined/exported symbols [179..187]`) |
| **`.rodata` Range** | `VA 0x0062f0 .. 0x006859` (`OFF 0x0062f0`, `1,386 bytes`) |
| **`.text` Range** | `VA 0x00c000 .. 0x014477` (`OFF 0x00c000`, `33,912 bytes`, `8,478 AArch64 instructions`) |
| **`.plt` Range** | `VA 0x014480 .. 0x014f3f` (`OFF 0x014480`, `2,752 bytes`, `170 PLT trampolines`) |
| **`.data.rel.ro` Range** | `VA 0x018000 .. 0x0188e7` (`OFF 0x018000`, `2,280 bytes`, C++ RTTI & Vtables) |
| **`.data` / `.bss` Range** | `.data`: `0x01c000 .. 0x01c08f` (`144 B`) / `.bss`: `0x01c090 .. 0x01c0d7` (`72 B`) |

---

## 2. Exported `.dynsym` Symbols (`[179..187]`) / Bảng Biểu Tượng Xuất Khẩu

| Index | Virtual Address | Size | Binding / Type | Mangled / Demangled Symbol |
|---|---|---|---|---|
| `[179]` | `0x00006820` | `10 B` | `STB_WEAK` / `STT_OBJECT` | `_ZZN4lynx5piper7Runtime22AddPrefixToUrlIfNeededERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEE12kUrlLynxCore` (`"lynx_core"`) |
| `[180]` | `0x000133a0` | `64 B` | `STB_GLOBAL` / `STT_FUNC` | `lynx::base::ObserverList::AddObserver(lynx::base::Observer*)` |
| `[181]` | `0x000133e0` | `220 B` | `STB_GLOBAL` / `STT_FUNC` | `lynx::base::ObserverList::RemoveObserver(lynx::base::Observer*)` |
| `[182]` | `0x00013538` | `88 B` | `STB_GLOBAL` / `STT_FUNC` | `lynx::base::ObserverList::ForEachObserver()` |
| `[183]` | `0x00013590` | `140 B` | `STB_GLOBAL` / `STT_FUNC` | `JNI_OnLoad(JavaVM*, void*)` |
| `[185]` | `0x0000682a` | `12 B` | `STB_WEAK` / `STT_OBJECT` | `_ZZN4lynx5piper7Runtime22AddPrefixToUrlIfNeededERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEE8kUrlHost` (`"file://lynx"`) |

---

## 3. Reconstructed Subsystems & AArch64 Disassembly Mapping / Phân Hệ Tái Dựng & Ánh Xạ Hợp Ngữ

### 3.1. V8 Bytecode Code-Cache Generator (`0x00c048 .. 0x00c744`)
- **[EN]** Implements `lynx::piper::cache::CacheGenerator` (vtable at `0x0180e0`, method `GenerateCache()` at `0x00c0f8..0x00c450`). Enters `v8::Isolate::Enter()`, `v8::HandleScope`, and `v8::Context::New()`, compiles unbound script via `v8::ScriptCompiler::CompileUnboundScript(isolate, &source, kEagerCompile = 2, kNoCacheNoReason = 0)` (`0x00c21c..0x00c228`), invokes `v8::ScriptCompiler::CreateCodeCache(unbound_script)` (`0x00c240`), checks `CachedData::rejected` (`[x24, #0x0c] == 0`) and `CachedData::length > 0` (`[x24, #0x08]`), and copies `[x24, #0x00]` into a `std::shared_ptr<Buffer>`.
- **[VN]** Cài đặt `lynx::piper::cache::CacheGenerator` (vtable tại `0x0180e0`, hàm `GenerateCache()` tại `0x00c0f8..0x00c450`). Biên dịch kịch bản độc lập với `kEagerCompile = 2`, trích xuất bộ nhớ đệm qua `CreateCodeCache`, kiểm tra cờ `rejected` (`[x24, #0x0c] == 0`) và sao chép dữ liệu vào `std::shared_ptr<Buffer>`.

### 3.2. V8 CPU Profiler & `120`-Byte (`0x78`) Node Tree Serializer (`0x00c748 .. 0x00d17f`)
- **[EN]** Wraps `v8::CpuProfiler::New` (`0x00c760`), `SetSamplingInterval` (`0x00ca60`), `StartProfiling` (`0x00c7a8`), and `StopProfiling` (`0x00c868`). Traverses `v8::CpuProfile::GetTopDownRoot()` recursively at `0x00ca6c..0x00cd0c`, serializing each `v8::CpuProfileNode` into a `120`-byte (`0x78`) record (`sdiv x20, x8, x11` where `w11 = #0x78` at `0x00cc20..0x00cc30` and capacity growth `umull x0, w20, w8` where `w8 = #0x78` at `0x00cf6c..0x00cf70`).
- **[VN]** Bao bọc `v8::CpuProfiler` và duyệt đệ quy cây gọi hàm `GetTopDownRoot()` tại `0x00ca6c..0x00cd0c`, đóng gói mỗi `v8::CpuProfileNode` thành bản ghi `120` byte (`0x78`) (`sdiv x20, x8, x11` với `w11 = #0x78` tại `0x00cc20..0x00cc30`).

### 3.3. V8 Isolate & Context Lifecycle (`0x00d1b8 .. 0x00d7dc`)
- **[EN]** `V8IsolateInstanceImpl::InitIsolate` (`0x00d258..0x00d394`) uses `std::call_once` (`0x01c0b8`, callback `0x00d39c..0x00d418`) to initialize `v8::platform::NewDefaultPlatform`, `v8::V8::InitializeICU`, `InitializePlatform`, and `Initialize`. Queries `lynx::tasm::LynxEnv::GetInstance()->GetV8HeapSize()` (`0x00d2dc..0x00d2e0`) and calls `v8::Isolate::UpdateMaxHeapSize` (`0x00d33c`). `V8ContextWrapperImpl::Init` (`0x00d5cc..0x00d7dc`) enables `SetCaptureStackTraceForUncaughtExceptions(true, 10, kDetailed = 7)` (`mov w1, #1; mov w2, #0xa; mov w3, #7` @ `0x00d6ec..0x00d6f4`).
- **[VN]** `V8IsolateInstanceImpl::InitIsolate` (`0x00d258..0x00d394`) dùng `std::call_once` khởi tạo nền tảng V8, cấu hình kích thước heap từ `LynxEnv::GetV8HeapSize()`, và `V8ContextWrapperImpl::Init` (`0x00d5cc..0x00d7dc`) bật thu thập stack trace 10 khung (`kDetailed = 7`).

### 3.4. V8 Tagged-Pointer Inspection & MurmurHash64A + NEON Popcount Hash Table (`0x00db48 .. 0x00fa78`, `0x012dd0 .. 0x012ec4`)
- **[EN]**
  - Direct V8 tagged pointer inspection (`and x9, x8, #3; cmp x9, #1; ldur x9, [x8, #-1]; ldurh w9, [x9, #0xb]` @ `0x00dc88..0x00dcd8`, `0x013e7c..0x013e88`, `0x01417c..0x0141ac`) checking `ODDBALL_TYPE == 0x83` (`Oddball::kind_` at `+0x2b`: `3 = Null`, `5 = Undefined`), `FIRST_NONSTRING_TYPE == 0x80`, and `JS_OBJECT_TYPE == 0x410` (inlined internal field 0 at `[x8, #0x17]`).
  - 7-way relative jump table at `.rodata` `0x006300` (`00 04 08 11 17 20 26`) dispatching `lynx::piper::Value::Kind` (`0..6`) at `0x012dd0..0x012ec4`.
  - MurmurHash64A / CityHash pointer hash at `0x00e9b8..0x00e9f0` (`kMul = 0x9ddfea08eb382d69ULL`, shift `47`) paired with NEON population count (`cnt v0.8b, v0.8b; uaddlv h0, v0.8b` @ `0x013f08..0x013f10`) for power-of-two vs prime-modulo bucket indexing.
- **[VN]** Kiểm tra trực tiếp con trỏ gắn thẻ V8 (`ODDBALL_TYPE == 0x83`, `JS_OBJECT_TYPE == 0x410`), bảng nhảy 7 nhánh tại `0x006300`, và hàm băm con trỏ MurmurHash64A (`0x9ddfea08eb382d69ULL`) kết hợp đếm bit NEON (`cnt v0.8b` + `uaddlv h0`).

### 3.5. `lynx::piper::V8Runtime`, `ObserverList`, `NapiRuntimeProxyV8` & `JNI_OnLoad` (`0x00fd2c .. 0x013bec`)
- **[EN]** Reconstructs the `352`-byte (`0x160`) `V8Runtime` (`0x01361c..0x013714`), `AddPrefixToUrlIfNeeded` (`0x010844..0x010b38`), circular doubly-linked `ObserverList` (`0x0133a0..0x01358c`), `NapiRuntimeProxyV8` (`0x013958..0x013bec`), and `JNI_OnLoad` (`0x013590..0x013618`).
- **[VN]** Tái dựng đầy đủ lớp `V8Runtime` (`352` byte), `AddPrefixToUrlIfNeeded`, danh sách liên kết đôi vòng `ObserverList`, `NapiRuntimeProxyV8`, và `JNI_OnLoad`.
