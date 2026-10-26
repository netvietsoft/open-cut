# BÁO CÁO PHÂN TÍCH NHỊ PHÂN & PHỤC DỰNG C++17: `libspeechengine.so`
## BINARY DISASSEMBLY & CLEAN-ROOM C++17 RECONSTRUCTION REPORT

- **Thư viện mục tiêu / Target Library**: `libspeechengine.so` (`18,256 bytes`, ELF64 AArch64, Little-Endian)
- **Task ID**: `TASK-093-RECONSTRUCTION-LIBSPEECHENGINE` (`TASK_SO_015`)
- **Trạng thái / Status**: `VERIFIED_AND_ACCEPTED` (8 tệp C++17 & Header, `112,721 bytes`, `0` stub)

---

## 1. Cấu trúc phân đoạn ELF64 / ELF64 Section Geometry (`OBSERVED`)
| Phân đoạn (Section) | Địa chỉ ảo (`vaddr`) | Kích thước (`bytes`) | Ghi chú kỹ thuật / Technical Notes |
|---|---|---|---|
| `.dynsym` | `0x000450 .. 0x000978` | `1,320 B` | 55 mục (`[000]..[054]`): 34 hàm nhập (`[003]..[036]`) + 18 hàm xuất xưởng (`[037]..[054]`) |
| `.dynstr` | `0x000978 .. 0x001558` | `3,040 B` | Chuỗi định danh biểu tượng động |
| `.rela.dyn` | `0x0015e8 .. 0x001720` | `312 B` | 13 bản ghi định vị lại động (bao gồm vtable `SpeechEngineListener` tại `0x007c28`) |
| `.rela.plt` | `0x001720 .. 0x001a38` | `792 B` | 33 bản ghi nhảy `.plt` cho `lab::speech::client::*`, libc, liblog |
| `.plt` | `0x001a40 .. 0x001c70` | `560 B` | 33 cầu nhảy `.plt` (`0x001a60..0x001c60`) |
| `.text` | `0x001c70 .. 0x003238` | `5,576 B` | Toàn bộ mã máy AArch64 (`1,394` lệnh 32-bit) |
| `.rodata` | `0x003238 .. 0x0034ce` | `662 B` | Chuỗi log `"SpeechEngine"`, `"onSpeechMessage"`, `"(I[BI)V"` |
| `.fini_array` | `0x007c10 .. 0x007c20` | `16 B` | 2 con trỏ hàm kết thúc: `0x001c80`, `0x001c70` |
| `.data.rel.ro` | `0x007c20 .. 0x007c50` | `48 B` | `0x007c20`: `__dso_handle`; `0x007c28..0x007c48`: vtable `SpeechEngineListener` |
| `.bss` | `0x008000 .. 0x008010` | `16 B` | `0x008000`: `JavaVM* g_jvm`; `0x008008`: `JavaVM* g_licbag_jvm` |

---

## 2. Bố cục Struct ABI & Bảng phương thức ảo / ABI Struct Layouts & Vtable (`OBSERVED`)

1. **`SpeechEngineHandler` (`24 bytes = 0x18`, cấp phát tại `0x002080: mov w0, #0x18; bl operator new(nothrow)`)**:
   - `+0x00`: `lab::speech::client::Engine* engine` (`str x20, [x19]` @ `0x002160`)
   - `+0x08`: `SpeechEngineListener* listener` (`str x21, [x19, #8]` @ `0x002124`)
   - `+0x10`: `lab::speech::client::Options* options` (`str x21, [x19, #0x10]` @ `0x0020d4`, được giải phóng và gán `nullptr` tại `0x0028a8: str xzr, [x19, #0x10]` ngay sau khi `Engine::Init(*options)` hoàn tất).

2. **`SpeechEngineListener` (`48 bytes = 0x30`, cấp phát tại `0x002108: mov w0, #0x30; bl operator new(nothrow)`)**:
   - `+0x00`: `void* vptr = 0x007c38` (`.data.rel.ro 0x007c28 + 0x10`: `[0]=0x002df0 ~D1Ev`, `[1]=0x002ea8 ~D0Ev`, `[2]=0x003098 OnMessage(int, const std::string&)`)
   - `+0x08`: `jclass callback_class_global_ref` (`str x0, [x19, #8]` @ `0x003018`)
   - `+0x10`: `jobject callback_obj_global_ref` (`str x0, [x19, #0x10]` @ `0x002fb4`)
   - `+0x18`: `jmethodID on_speech_message_mid` (`str x0, [x19, #0x18]` @ `0x002ff8`, tìm qua `"onSpeechMessage"` @ `0x0034b6` & `"(I[BI)V"` @ `0x0034c6`)
   - `+0x20..+0x2f`: `JniCallbackEnvironment` (`16 bytes`: `+0x20 JNIEnv* callback_env`, `+0x28 uint8_t is_attached`).

---

## 3. Chứng minh Toán học & Opcode / Mathematical & Opcode Proofs (`OBSERVED`)

- **Chuyển đổi độ dài byte sang số mẫu PCM 16-bit có dấu (`0x002a98..0x002aa0` & `0x002b88..0x002b94`)**:
  ```asm
  0x002a98: cmp  w22, #0
  0x002a9c: cinc w8, w22, lt
  0x002aa0: asr  w2, w8, #1
  ```
  Thực hiện phép chia nguyên có dấu cho 2 hướng về 0: $\text{samples} = \lfloor (\text{byte\_len} + [\text{byte\_len} < 0]) / 2 \rfloor$.
- **Kiểm tra tràn bộ đệm trong `fetchResultToNative` (`0x002cac..0x002cb8`)**:
  ```asm
  0x002cac: cmp  x8, w0, sxtw
  0x002cb0: b.ls #0x2cc0
  0x002cb8: mov  w21, #-0x709   // -1801 = ERR_BUFFER_TOO_SMALL
  ```
- **Tự động tách luồng callback khi nhận `MESSAGE_TYPE_ENGINE_STOP` (`1002 = 0x3ea` tại `0x00315c..0x003178`)**:
  ```asm
  0x00315c: cmp  w20, #0x3ea    // 1002
  0x003160: b.ne #0x317c
  0x003164: add  x0, x19, #0x20
  0x003178: b    #0x1e7c        // JniCallbackEnvironment::DetachCallback()
  ```
