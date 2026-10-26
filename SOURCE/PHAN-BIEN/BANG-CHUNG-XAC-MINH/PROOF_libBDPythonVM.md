# Bằng Chứng Xác Minh Đối Kháng (Adversarial Proof): `libBDPythonVM.so`

- **Thư viện**: `libBDPythonVM.so` (Target 49 / `TASK_SO_006` / `TASK-088-RECONSTRUCTION-LIBBDPYTHONVM`)
- **Dung lượng nhị phân gốc**: `418,008 bytes` (`apktool-res/lib/arm64-v8a/libBDPythonVM.so`)
- **Dung lượng C++17 & Header tái dựng**: `111,704 bytes` (`10` file `.h`/`.cpp`, `0` stub)
- **Tổng số ký hiệu `.dynsym` (`0x000ef8`)**: `447` (`50` exported: `42` `STT_FUNC` + `8` `STT_OBJECT`, `387` imported)

---

## Gate 1: Dung lượng & Không Stub (`> 40 KB`)
- Tổng dung lượng 10 file `.h`/`.cpp` trong `SOURCE/GIAI-MA/libBDPythonVM/` đạt **`111,704 bytes`** (`109.09 KB`), vượt xa ngưỡng tối thiểu `40,960 bytes`.
- Toàn bộ 42 hàm `STT_FUNC` và 8 đối tượng `STT_OBJECT` được tái dựng đầy đủ, không có bất kỳ hàm rỗng hay placeholder nào.

## Gate 2: Đối chiếu Opcode AArch64 Thực Tế
- `0x02451c` (`PyInit_ByteNNModule`): `PyType_Ready(&ByteNN_Engine_Type)` (`0x0682e8`), `mov w1, #0x3f5; bl PyModule_Create2` (`0x068280`), `PyModule_AddObject(mod, "Engine", &ByteNN_Engine_Type)`.
- `0x04be28` (`PyInit_ByteDTModule`): `PyType_Ready(&ByteDT_Engine_Type)` (`0x068650`), `mov w1, #0x3f5; bl PyModule_Create2` (`0x0685e8`), `PyModule_AddObject(mod, "Engine", &ByteDT_Engine_Type)`.
- `0x04f9ac` (`PyInit_DataWrapperModule`): `mov w1, #0x3f5; bl PyModule_Create2` (`0x0687e8`), đăng ký 6 kiểu `BDPy*Type` (`0x068950..0x069720`).
- `0x04d6d8` (`pitaya::GetPyObject`) & `0x04db38` (`pitaya::EnvGetPyObject`): nhảy đuôi (`b #0x4d6ec`) tới `GetPyObject_Internal`.
- `0x04e788` (`pitaya::GetPTYDict`): gọi `0x04db48` (`GetPTYObject_Internal`), kiểm tra `PTYObject::IsDict()`.
- `0x04e998..0x04ee70` (11 hàm nạp chồng `pitaya::PTYPyDictSet`): tạo `PyObject*` tương ứng, gọi `PyDict_SetItemString` (`#0xee70`) và giải phóng tham chiếu `Py_DECREF`.
- `0x050e8c` (`pitaya::CVMat_New`): gọi `BDPyCVMatType.tp_alloc` tại `[0x068c08 + 0x130]`, gán 3 trường `+0x10..+0x20` bằng `Py_None` qua SIMD `dup v0.2d, x8; str q0, [x0, #0x10]; str x8, [x0, #0x20]`, tăng `Py_None->ob_refcnt += 3`, và tạo capsule `"cvmat"` (`0x0594ca`) tại `[obj + 0x28]`.

## Gate 3: Chứng minh Toán học & Thuật toán
1. **Kiểm tra bit cờ `Py_TPFLAGS_LONG_SUBCLASS` (`0x04dba4..0x04dba8`)**:
   `ldrb w8, [x0, #0xab]; tbnz w8, #0, #0x4dc28` (kiểm tra bit 24 của `tp_flags` tại offset `+0xa8`).
2. **Tăng hàng loạt `ob_refcnt` bằng SIMD trong `CVMat_New` (`0x050ec0..0x050ed8`)**:
   `dup v0.2d, x8; str x8, [x0, #0x20]; str q0, [x0, #0x10]; add x9, x9, #3; str x9, [x8]`.

## Gate 4: Bố cục Struct ABI & 8 Đối tượng Toàn cục
- 6 đối tượng `PyTypeObject` (`408 bytes = 0x198 bytes` mỗi đối tượng tại `.data 0x068950..0x069720`):
  - `BDPyMemoryViewType` (`0x068950`, `tp_basicsize = 48`)
  - `BDPyCVMatType` (`0x068c08`, `tp_basicsize = 48`)
  - `BDPyTVMDeviceType` (`0x068e38`, `tp_basicsize = 24`)
  - `BDPyTVMDataInfoType` (`0x069070`, `tp_basicsize = 32`)
  - `BDPyNDArrayType` (`0x069358`, `tp_basicsize = 64`)
  - `BDPyTensorType` (`0x069720`, `tp_basicsize = 80`)
- 2 con trỏ hàm trong `.bss`: `pitaya::ToCVMat` (`0x069908`) và `pitaya::ToPyMat` (`0x069910`).
