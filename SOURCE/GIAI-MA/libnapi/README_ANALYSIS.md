# BÁO CÁO GIẢI MÃ & TÁI CẤU TRÚC CLEAN-ROOM C++17: `libnapi.so`

## 1. Siêu dữ liệu Nhị phân (Binary Forensics Metadata)
- **Tệp nhị phân gốc**: `SOURCE/apktool-res/lib/arm64-v8a/libnapi.so`
- **Dung lượng**: `247,904 bytes` (`0x3c860` bytes)
- **SHA-256**: `fb3a870c14315fcc8976c7edd2653ad80ef3ab96ceb534f0d6354aa91e82764c`
- **Kiến trúc**: AArch64 (`ARM64-v8a`), Little-Endian, LP64 ABI
- **Bố cục phân đoạn ELF**:
  - `.dynsym`: `0x000330..0x0031e0` (`11,952 bytes`, `498` symbols: `306` exports, `191` imports)
  - `.rodata`: `0x00c780..0x00e6af` (`7,983 bytes`)
  - `.text`: `0x014000..0x037070` (`143,472 bytes`)
  - `.data.rel.ro`: `0x038000..0x0389d8` (`2,520 bytes`)
  - `.bss`: `0x03c028..0x03c1d8` (`432 bytes`)
- **Thư viện phụ thuộc (`DT_NEEDED`)**: `libdl.so`, `libquick.so`, `liblog.so`, `libm.so`, `libc++_shared.so`, `libc.so`
- **Đường dẫn mã nguồn gốc rò rỉ trong `.rodata`**:
  - `0x00cb32`: `"/ws/228/bytebus/repositories/64f55d36a1934e8a59474a720b2d591d/b01c65cec201ce6e47a1f549784d4463/basic/android/java_only_map.cc"`
  - `0x00dbe1`: `"/ws/228/bytebus/repositories/64f55d36a1934e8a59474a720b2d591d/b01c65cec201ce6e47a1f549784d4463/oss/src/napi/quickjs/js_native_api_QuickJS.cc"`

---

## 2. Kiến trúc 5 Phân hệ Cốt lõi Đã Tái dựng (Clean-Room C++17 Reconstruction)

### Phân hệ 1: Bố cục `napi_env__` (`0x430 = 1,072 bytes`) & Vòng đời Môi trường (`napi_env_runtime.cpp`)
- **`napi_new_env` (`0x015e28..0x015ecc`)**:
  - Cấp phát `napi_env__` (`0x430 = 1,072 bytes` qua `mov w0, #0x430; bl operator new` @ `0x015e30..0x015e34`) và xóa 0 toàn bộ.
  - Cấp phát `NapiEnvState` (`0x20 = 32 bytes` @ `0x015e48`) chứa `napi_extended_error_info` (`24 B`) và con trỏ `CleanupHookTable*` tại `+0x18`.
  - Cấp phát `CleanupHookTable` (`0x28 = 40 bytes` @ `0x015e60`), gán `max_load_factor = 1.0f` (`0x3f800000` tại `+0x20`).
  - Khởi tạo 5 con trỏ hàm cấp môi trường tại `+0x018` (`0x01403c`), `+0x338` (`0x0146dc`), `+0x340` (`0x01405c`), `+0x348` (`0x0144c0`), và `+0x3a8` (`0x014704`).
- **`napi_free_env` (`0x015ecc..0x0160d0`)**:
  - Kiểm tra tràn số lượng phần tử với hằng số `0xaaaaaaaaaaaaaaaab` (`mov x24, #-0x5555555555555556; movk x24, #0xaaa, lsl #48` @ `0x015ef4..0x015ef8`).
  - Sao chép các nút `CleanupHookEntry` 24-byte (`{fn, arg, order}`), sắp xếp giảm dần theo thứ tự chèn (`sub_160d0` @ `0x015f74`), kiểm tra sự tồn tại bằng hàm băm `fn ^ (arg << 1)` (`eor x11, x9, x0, lsl #1` @ `0x015fcc`) và chỉ số bucket NEON popcount (`cnt v0.8b, v0.8b; uaddlv h0, v0.8b` @ `0x015fbc..0x015fc0`), thực thi `fn(arg)` theo thứ tự LIFO và giải phóng toàn bộ bộ nhớ.

### Phân hệ 2: Cấu hình Runtime, ThreadSafeFunction & Async Work (`0x017354..0x01c19f`)
- **`napi_runtime_configuration__` (`0x48 = 72 bytes` @ `0x018368`)** và **`NapiRuntimeContext` (`0x88 = 136 bytes` @ `0x0183c8` / `0x01b49c`)**.
- **`napi_runtime_get_threadsafe_function_context` (`0x017354`)**, **`napi_runtime_call_threadsafe_function` (`0x017364`, `1,460 B`)**, và **`napi_runtime_delete_threadsafe_function` (`0x018050`, `148 B`)**.

### Phân hệ 3: Backend QuickJS / LepusNG (`qjsimpl`, `0x01c1a0..0x027600`)
- **`napi_attach_quickjs` (`0x01c1a0..0x01c8b4`, `1,812 bytes`)**:
  - Gắn 78 con trỏ hàm N-API vào `napi_env__` (`+0x020..+0x428`).
  - Cấp phát `qjsimpl::Context` (`0x450 = 1,104 bytes` @ `0x01c6a8`), nạp cặp hằng số `{2ULL, 18ULL}` từ `.rodata 0x00c7c0` vào `+0x18..+0x20`, intern 11 `QuickJSAtom` (`80 bytes` mỗi khe tại `+0x0c8..+0x3e8`: `"name"`, `"length"`, `"prototype"`, `"constructor"`, `"@#fin@#"`, `"message"`, `"code"`, `"buffer"`, `"byteLength"`, `"byteOffset"`, `"@#ctor@#"`), và cấp phát `HandleScopeWrapper` gốc (`0x30 = 48 bytes` @ `0x01c83c`).
- **`napi_js_value_to_quickjs_value` (`0x027468..0x027510`)**: Giải hộp NaN-boxing 64-bit và tăng refcount khi `!is_gc_mode`.
- **`napi_module_register_xx` (`0x027568`) & `napi_find_module` (`0x0275a0`)**: Sử dụng khóa xoay nguyên tử 1-byte (`ldaxrb`/`stxrb`/`stlrb`) tại `.bss 0x03c038` bảo vệ danh sách liên kết đơn module tại `.bss 0x03c040`.

### Phân hệ 4: Mô hình Đối tượng C++ `Napi::*` (`0x027604..0x02db6c`)
- Phục hồi đầy đủ 217 hàm xuất khẩu `Napi::*`, bao gồm bảng nhảy dịch chuyển 11 phần tử của `Napi::TypedArray::ElementSize` (`0x02afd0..0x02b07c`) tại `.rodata 0x00c81b`: `[10, 10, 10, 6, 6, 0, 0, 0, 3, 3, 3]`.

### Phân hệ 5: Cầu nối Android `vmsdk::general::android`, `vmsdk::icu` & `JNI_OnLoad` (`0x02ef60..0x037070`)
- Phục hồi `JavaOnlyArray`, `JavaOnlyMap`, `JNIHelper`, `icu::createPartsFromJavaOnlyArray` (`0x030ed8`), `icu::optionsFromJava` (`0x035068`), `icu::optionsToJava` (`0x035df8`), và `JNI_OnLoad` (`0x036ef0..0x037070` trả về `0x00010006 = JNI_VERSION_1_6`).
