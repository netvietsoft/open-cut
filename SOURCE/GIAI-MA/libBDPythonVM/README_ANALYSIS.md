# Báo Cáo Giải Mã & Tái Dựng C++17: `libBDPythonVM.so` (Target 49 / `TASK_SO_006`)

- **Đường dẫn nhị phân gốc**: `apktool-res/lib/arm64-v8a/libBDPythonVM.so`
- **Dung lượng nhị phân chính xác**: `418,008 bytes` (`0x0660D8`)
- **Kiến trúc**: `ELF64 AArch64 LSB shared object`
- **Tổng số ký hiệu `.dynsym` (`0x000ef8`)**: `447` (`50` exported: `42` `STT_FUNC` + `8` `STT_OBJECT`, `387` imported)

## Các Phân hệ Cốt lõi (Observed Subsystems)
1. **Pitaya <-> CPython 3.8 Object Conversion & 11 `PTYPyDictSet` Overloads (`bdpythonvm_cpy_convert.h/.cpp`)**:
   - `GetPyObject` (`0x04d6d8`), `EnvGetPyObject` (`0x04db38`), `GetPTYDict` (`0x04e788`), `PTYPyObjectString` (`0x04e918`)
   - 11 hàm nạp chồng `pitaya::PTYPyDictSet(PyObject*, const char*, ...)` (`0x04e998..0x04ee70`)
2. **3 CPython C-Extension Modules & 8 Exported Global Objects (`bdpythonvm_datawrapper_modules.h/.cpp`)**:
   - `PyInit_ByteNNModule` (`0x02451c`), `PyInit_ByteDTModule` (`0x04be28`), `PyInit_DataWrapperModule` (`0x04f9ac`), `CVMat_New` (`0x050e8c`)
   - 6 đối tượng `PyTypeObject` (`408 B` mỗi đối tượng tại `.data 0x068950..0x069720`): `BDPyMemoryViewType`, `BDPyCVMatType`, `BDPyTVMDeviceType`, `BDPyTVMDataInfoType`, `BDPyNDArrayType`, `BDPyTensorType` và 2 con trỏ hàm `ToCVMat` (`0x069908`), `ToPyMat` (`0x069910`)
3. **PyInterpreterPool, PyTaskExecutor, Java2CPy & 21 JNI Bridges (`bdpythonvm_executor_pool_jni.h/.cpp`)**:
   - `PyInterpreterPool` (`0x057105`), `PyTaskExecutor` (`0x057346`), `Java2CPy` (`0x056da8`), 10 hàm `CPyNativeArray_native*` (`0x05603c..0x056524`), 10 hàm `CPyNativeDict_native*` (`0x056570..0x056d08`), và `PyVMLoader_nativeInit` (`0x056ff4`).
