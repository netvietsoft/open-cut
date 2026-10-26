# BÁO CÁO PHÂN TÍCH NHỊ PHÂN & PHỤC DỰNG C++17: `libspeechepg.so`
## BINARY DISASSEMBLY & CLEAN-ROOM C++17 RECONSTRUCTION REPORT

- **Thư viện mục tiêu / Target Library**: `libspeechepg.so` (`18,256 bytes`, ELF64 AArch64, Little-Endian)
- **Task ID**: `TASK-094-RECONSTRUCTION-LIBSPEECHEPG` (`TASK_SO_016`)
- **Trạng thái / Status**: `VERIFIED_AND_ACCEPTED` (8 tệp C++17 & Header, `> 100 KB`, `0` stub)

---

## 1. Cấu trúc phân đoạn ELF64 / ELF64 Section Geometry (`OBSERVED`)
| Phân đoạn (Section) | Địa chỉ ảo (`vaddr`) | Kích thước (`bytes`) | Ghi chú kỹ thuật / Technical Notes |
|---|---|---|---|
| `.dynsym` | `0x000450 .. 0x000978` | `1,320 B` | 55 mục (`[000]..[054]`): 34 hàm nhập (`[003]..[036]`) + 18 hàm xuất xưởng (`[037]..[054]`) |
| `.dynstr` | `0x000978 .. 0x001564` | `3,052 B` | Chuỗi định danh biểu tượng động (`SpeechPluginBridge`) |
| `.rela.dyn` | `0x0015f8 .. 0x001730` | `312 B` | 13 bản ghi định vị lại động (bao gồm vtable `SpeechPluginListener` tại `0x007c18`) |
| `.rela.plt` | `0x001730 .. 0x001a48` | `792 B` | 33 bản ghi nhảy `.plt` cho `lab::speech::client::*`, libc, liblog |
| `.plt` | `0x001a50 .. 0x001c80` | `560 B` | 33 cầu nhảy `.plt` (`0x001a70..0x001c70`) |
| `.text` | `0x001c80 .. 0x003248` | `5,576 B` | Toàn bộ mã máy AArch64 (`1,394` lệnh 32-bit) |
| `.rodata` | `0x003248 .. 0x0034de` | `662 B` | Chuỗi log `"speechengine"` (`0x003248`), `"onSpeechMessage"` (`0x003368`), `"(I[BI)V"` (`0x003378`) |
| `.fini_array` | `0x007c00 .. 0x007c10` | `16 B` | 2 con trỏ hàm kết thúc: `0x001c90`, `0x001c80` |
| `.data.rel.ro` | `0x007c10 .. 0x007c40` | `48 B` | `0x007c10`: `__dso_handle`; `0x007c18..0x007c38`: vtable `SpeechPluginListener` |
| `.bss` | `0x008000 .. 0x008010` | `16 B` | `0x008000`: `JavaVM* g_jvm` (GOT `0x007fe8`); `0x008008`: `JavaVM* g_licbag_jvm` (GOT `0x007fc8`) |

---

## 2. Bố cục Struct ABI & Khác biệt giữa `SpeechPluginBridge` (`libspeechepg.so`) và `SpeechEngineBridge` (`libspeechengine.so`) (`OBSERVED`)

1. **`SpeechEngineHandler` (`24 bytes = 0x18`, cấp phát tại `0x0024f8: mov w0, #0x18; bl operator new(nothrow)`)**:
   - `+0x00`: `lab::speech::client::Engine* engine` (`str x20, [x19]` @ `0x0025d8`)
   - `+0x08`: `SpeechPluginListener* listener` (`str x21, [x19, #8]` @ `0x00259c`)
   - `+0x10`: `lab::speech::client::Options* options` (`str x21, [x19, #0x10]` @ `0x00254c`).
   - **Khác biệt kiến trúc quan trọng**: Trong `libspeechepg.so`, `createEngineToNative(env, thiz, jcallback_obj)` (`0x0024e0`) gọi `DefaultOptions(Options*)` (`0x002550`) và `Options::IsValid()` (`0x002558`) ngay lúc tạo, còn `JNI_SetAssetManager(jvm, jasset_mgr)` (`0x002cfc`) và `Engine::AddListener(listener)` (`0x002d4c`) được hoãn sang `initEngineToNative(env, thiz, handle, jasset_mgr)` (`0x002cb4`).

2. **`SpeechPluginListener` (`48 bytes = 0x30`, cấp phát tại `0x002580: mov w0, #0x30; bl operator new(nothrow)`)**:
   - `+0x00`: `void* vptr = 0x007c28` (`.data.rel.ro 0x007c18 + 0x10`: `[0]=0x001fa0 ~D1Ev`, `[1]=0x002058 ~D0Ev`, `[2]=0x002248 OnMessage(int, const std::string&)`)
   - `+0x08`: `jclass callback_class_global_ref` (`str x0, [x19, #8]` @ `0x0021c8`)
   - `+0x10`: `jobject callback_obj_global_ref` (`str x0, [x19, #0x10]` @ `0x002164`)
   - `+0x18`: `jmethodID on_speech_message_mid` (`str x0, [x19, #0x18]` @ `0x0021a8`)
   - `+0x20..+0x2f`: `JniCallbackEnvironment` (`16 bytes`: `+0x20 JNIEnv* callback_env`, `+0x28 uint8_t is_attached`).

---

## 3. Chứng minh Toán học & Opcode / Mathematical & Opcode Proofs (`OBSERVED`)

- **Chuyển đổi độ dài byte sang số mẫu PCM 16-bit có dấu (`0x002f10..0x002f18` & `0x003000..0x00300c`)**:
  ```asm
  0x002f10: cmp  w22, #0
  0x002f14: cinc w8, w22, lt
  0x002f18: asr  w2, w8, #1
  ```
- **Kiểm tra tràn bộ đệm trong `fetchResultToNative` (`0x003124..0x003130`)**:
  ```asm
  0x003124: cmp  x11, w0, sxtw
  0x00312c: b.ls #0x313c
  0x003130: mov  w21, #-0x709   // -1801 = ERR_BUFFER_TOO_SMALL
  ```
- **Tự động tách luồng callback khi nhận `MESSAGE_TYPE_ENGINE_STOP` (`1002 = 0x3ea` tại `0x00230c..0x002328`)**:
  ```asm
  0x00230c: cmp  w20, #0x3ea    // 1002
  0x002310: b.ne #0x232c
  0x002328: b    #0x1e8c        // JniCallbackEnvironment::DetachCallback()
  ```
