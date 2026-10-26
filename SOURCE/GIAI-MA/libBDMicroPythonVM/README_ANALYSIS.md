# Báo cáo Giải mã & Tái dựng C++17: `libBDMicroPythonVM.so` (Target 48 / `TASK_SO_005`)

- **Đường dẫn nhị phân gốc**: `apktool-res/lib/arm64-v8a/libBDMicroPythonVM.so`
- **Dung lượng nhị phân chính xác**: `379,248 bytes` (`0x05C970`)
- **Kiến trúc**: `ELF64 AArch64 LSB shared object`
- **Tổng số ký hiệu `.dynsym` (`0x000d88`)**: `396` (`41` exported: `33` `STT_FUNC` + `8` `STT_OBJECT`, `355` imported)
- **Tổng dung lượng C++17 & Header tái dựng**: `166,402 bytes` (`10` file `.h`/`.cpp`, `0` stub)

## Các Phân hệ Cốt lõi (Observed Subsystems)
1. **Pitaya <-> FastEngine Object Conversion (`bdmicropythonvm_obj_convert.h/.cpp`)**:
   - `pitaya::CreatePTYExtDict` (`0x03bec0`), `pitaya::CreatePTYExtList` (`0x03bf74`), `pitaya::CreateCepEvent` (`0x03c028` -> `0x03c02c`)
   - `fast_engine::GetCoreError` (`0x0430ac`), `fast_engine::EnvPTYObj2MPObj` (`0x043c84`), `fast_engine::PTYObj2MPObj` (`0x043d64`), `fast_engine::MPObj2PTYObj` (`0x0453d4`), `fast_engine::EnvMPObj2PTYObj` (`0x0453e0`), `fast_engine::GetPTYDict` (`0x045530`), `fast_engine::GetPTYList` (`0x045650`)
2. **PYBridge, TensorWrapper, BDByteDTBridge & BDByteNNBridge (`bdmicropythonvm_pybridge_tensor.h/.cpp`)**:
   - `RegisterMicroPyNativeModules` (`0x03b374`, `.init_array` @ `0x00f0a0`)
   - `PYBridge` (`"2.14.0"` @ `0x052131`, 52 methods @ `0x0519a3..0x051e77`, SQL timestamp regex `(timestamp)[\s]*(>|>=|=|!=|<=|<)[\s]*(\d*[.]*\d*)` @ `0x0517fa`, `CityHash64` @ `0x051da8`)
   - `TensorWrapperObj` (`.data 0x060000..0x0600b0` attributes: `dims`, `data_type`, `data_format`, `fraction`, `num_list`, exported `fast_engine::TensorType` @ `0x060210`)
   - `BDByteDTBridge` (`0x052565`, 3 methods) & `BDByteNNBridge` (`0x052797`, 17 methods)
3. **InitFastEngine, VM Pool & 21 JNI Bridges (`bdmicropythonvm_vm_pool_jni.h/.cpp`)**:
   - `pitaya::InitFastEngine` (`0x04ee2c`, `"fast_engine_settings"` @ `0x053528`)
   - `MicroPyPitayaVM` (`0x052f30`), `MinPyVMPool` (`0x053409`), `FastEngineTaskExecutor` (`0x052aef`), `FastEngineMemoryMonitor` (`0x0530ed`)
   - 10 `MicPyArray_*` JNI (`0x04fd08..0x0503dc`), 10 `MicPyDict_*` JNI (`0x0503e0..0x050d24`), `MicroPyLoader_nativeInit` (`0x050f88`)
