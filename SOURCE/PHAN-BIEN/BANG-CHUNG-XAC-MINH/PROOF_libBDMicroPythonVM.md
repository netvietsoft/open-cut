# Bằng Chứng Xác Minh Đối Kháng (Adversarial Proof): `libBDMicroPythonVM.so`

- **Thư viện**: `libBDMicroPythonVM.so` (Target 48 / `TASK_SO_005` / `TASK-087-RECONSTRUCTION-LIBBDMICROPYTHONVM`)
- **Dung lượng nhị phân gốc**: `379,248 bytes` (`apktool-res/lib/arm64-v8a/libBDMicroPythonVM.so`)
- **Dung lượng C++17 & Header tái dựng**: `166,402 bytes` (`10` file `.h`/`.cpp`, `0` stub)
- **Tổng số ký hiệu `.dynsym` (`0x000d88`)**: `396` (`41` exported: `33` `STT_FUNC` + `8` `STT_OBJECT`, `355` imported)

---

## Gate 1: Dung lượng & Không Stub (`> 40 KB`)
- Tổng dung lượng 10 file `.h`/`.cpp` trong `SOURCE/GIAI-MA/libBDMicroPythonVM/` đạt **`166,402 bytes`** (`162.50 KB`), vượt xa ngưỡng tối thiểu `40,960 bytes`.
- Toàn bộ 33 hàm `STT_FUNC` và 8 đối tượng `STT_OBJECT` được tái dựng đầy đủ, không có bất kỳ hàm rỗng hay placeholder nào.

## Gate 2: Đối chiếu Opcode AArch64 Thực Tế
- `0x03bec0` (`pitaya::CreatePTYExtDict`): `mov w0, #0x50; bl _Znwm; mov w2, #0x40; bl ExtDictObj::ExtDictObj; ldr x8, [0x05ee30]; add x8, x8, #0x10; str x8, [x19]; stp x9, x8, [x19, #0x40]`.
- `0x03bf74` (`pitaya::CreatePTYExtList`): `mov w0, #0x50; bl _Znwm; mov w2, #0x40; bl ExtListObj::ExtListObj; ldr x8, [0x05eeb0]; add x8, x8, #0x10; str x8, [x19]; stp x9, x8, [x19, #0x40]`.
- `0x03c028 -> 0x03c02c` (`pitaya::CreateCepEvent`): kiểm tra `engine->cep_event_pool` tại `[x0, #0x30]`, gọi `ObjCachePool::Pop()`, đặt lại `ref_count = 1` tại `[x19, #0x38]`.
- `0x0430ac` (`fast_engine::GetCoreError`): kiểm tra `engine->has_exception` tại `[x1, #0x10e0]`, gọi `Engine::FetchException`, tách chuỗi stack trace theo delimiter `"\n\x02"` (`mov w8, #0x20a` tại `0x0432d0`).
- `0x04ee2c` (`pitaya::InitFastEngine`): kiểm tra `FastEngine::Instance() + 0x11c`, đọc `"fast_engine_settings"` (`0x053528`), đăng ký 6 hàm callback vào `FastEngineAdapter`.
- `0x04fe74` (`MicPyArray_nativeSetLong`): kiểm tra bộ nhớ đệm số nguyên nhỏ `[-5, 257]` (`add x8, x3, #5; cmp x8, #0x106; add x8, x0, x8, lsl #3; ldr x0, [x8, #0x860]`).
- `0x050f88` (`MicroPyLoader_nativeInit`): lưu `JavaVM*` tại `0x060928`, tìm lớp `com/bytedance/pitaya/api/bean/nativeobj/micropy/MicPyDict` (`0x0535f0`), lưu `fromJSONObject` tại `0x060938`, `getNativePtr` tại `0x060940`, và nhảy đuôi (`b #0x3b374`) tới `RegisterMicroPyNativeModules`.

## Gate 3: Chứng minh Toán học & Thuật toán
1. **Công thức chỉ mục Small-Int Cache (`0x04fe74..0x04fe88`)**:
   $$\text{idx} = \text{uint64\_t}(v + 5) \le 262 \iff v \in [-5, 257], \quad \text{addr} = \text{engine} + \text{0x860} + 8 \cdot (v + 5)$$
2. **Hàm băm `CityHash64` (`0x051da8 -> PLT 0x00ded0`)**:
   Sử dụng 3 hằng số chuẩn `k0 = 0xc3a5c85c97cb3127`, `k1 = 0xb492b66fbe98f273`, `k2 = 0x9ae16a3b2f90404f`.
3. **Biểu thức chính quy lọc Timestamp SQL (`0x0517fa`)**:
   `(timestamp)[\s]*(>|>=|=|!=|<=|<)[\s]*(\d*[.]*\d*)`.

## Gate 4: Bố cục Struct ABI & Vtable
- `fast_engine::Obj`: `+0x20` `gc_generation`, `+0x28` `type_obj`, `+0x30` `engine`, `+0x38` `ref_count`.
- `fast_engine::Engine`: `+0x08` `pool_table`, `+0x30` `cep_event_pool`, `+0x860` `small_int_cache[263]`, `+0x10e0` `has_exception`, `+0x1140` `gc_generation`.
- `TensorWrapperObj` (`0x78 = 120 B`, `TensorType` @ `0x060210`): bảng `AttrDef` 5 mục tại `.data 0x060000..0x0600b0` (`dims`, `data_type`, `data_format`, `fraction`, `num_list`).
