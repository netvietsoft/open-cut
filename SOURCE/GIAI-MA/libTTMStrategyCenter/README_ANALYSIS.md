# BÁO CÁO GIẢI MÃ KỸ THUẬT: `libTTMStrategyCenter.so` (Target 43)

- **Dung lượng nhị phân (`OBSERVED`)**: `395,664 bytes` (`0.38 MB`)
- **Định dạng nhị phân**: `ELF 64-bit LSB shared object, ARM aarch64`
- **Phân loại Lõi C++**: `CORE_04_MULTIMEDIA` / `AI_STRATEGY_CEP_BYTEDT_ENGINE`
- **Tổng số dynamic symbols (`.dynsym`)**: `899` (`757` exported + `142` imported)
- **Hàm JNI xuất xưởng & đăng ký động (`JNI_OnLoad` @ `0x2e6cc`)**: `2` exported (`JNI_OnLoad`, `JNI_OnUnload`) + `16` `JNINativeMethod` đăng ký qua `RegisterNatives` (`11` thuộc `TTMStrategyCenter` tại `0x62050` + `5` thuộc `TTMStrategyCenterByteDTEngineManager` tại `0x62158`)
- **Hàm C++ demangled bóc tách được**: `644`
- **Phụ thuộc thư viện động (`DT_NEEDED`)**: `libTTMachineCore.so`, `libCepEngine.so`, `liblog.so`, `libc++_shared.so`, `libm.so`, `libdl.so`, `libc.so`

---

## 1. Bố cục Phân đoạn ELF64 & Hằng số Sentinel (`OBSERVED`)

| Phân đoạn / Biến toàn cục | Địa chỉ ảo (`vaddr`) | Offset file | Kích thước / Giá trị thực tế |
|---|---|---|---|
| `PT_LOAD 0` (R+X `.rodata` + `.text`) | `0x000000..0x05d798` | `0x000000..0x05d798` | `382,872 bytes` |
| `PT_LOAD 1` (R+W `.data.rel.ro` + `.data` + `.bss`) | `0x061b38..0x064590` | `0x05db38..0x060138` | `file_offset = vaddr - 0x4000` |
| `LONG_MAX_VALUE` / `TTM_SC_LONG_MAX_VALUE` | `0x064008` / `0x064048` | `0x060008` / `0x060048` | `0x7fffffffffffffff` (`9223372036854775807`) |
| `INT_MAX_VALUE` / `TTM_SC_INT_MAX_VALUE` | `0x064010` / `0x064050` | `0x060010` / `0x060050` | `0x7fffffff` (`2147483647`) |
| `DOUBLE_MAX_VALUE` / `TTM_SC_DOUBLE_MAX_VALUE` | `0x064018` / `0x064058` | `0x060018` / `0x060058` | `0x7fefffffffffffff` (`1.7976931348623157e+308`) |
| `g_ttm_sc_methods` (`11 x JNINativeMethod`) | `0x062050..0x062157` | `0x05e050..0x05e157` | `264 bytes` (`com/tiktok/strategycenter/TTMStrategyCenter`) |
| `g_bytedt_methods` (`5 x JNINativeMethod`) | `0x062158..0x0621cf` | `0x05e158..0x05e1cf` | `120 bytes` (`com/tiktok/strategycenter/bytedt/TTMStrategyCenterByteDTEngineManager`) |

---

## 2. Kiến trúc 4 Phân hệ C++17 Đã Tái Tạo Hoàn Chỉnh (`12 files`, `> 100 KB`)

1. **`ttmstrategycenter_types.h`**: Định nghĩa kiểu dữ liệu cốt lõi, `TTMDataType`, `TTMStateCode`, `__TTMTransparentStruct`, hằng số sentinel `.data` (`0x64008`..`0x64058`), và cấu trúc `bytedt::Input` / `bytedt::PredictResult` / `bytedt::ModelInfo`.
2. **`ttmstrategycenter_bdi_feature.h` & `.cpp`**: Tái tạo 17 hàm Universal BDI (`universal.str.length`, `universal.math.ceil`, `universal.sys.Random`, `universal.list.count`, v.v. tại `0x22fe0`..`0x26a9c`), bộ nạp `AnTTMPlatformUniversalBdiFunLoader` (`0x2324c`, `10,216 bytes`), và cổng truy vấn đặc trưng `AnTTMGetFeatureValue` (`0x26ab8`, `3,004 bytes`).
3. **`ttmstrategycenter_data_wrappers.h` & `.cpp`**: Tái tạo giao diện đa hình `TTMExtDataInterface` (`vtable` tại `0x61b38`, 38 phương thức ảo), `TTMExtJavaMap` (`0x28568`), `TTMExtJavaList` (`0x2ad90`), `TTMExtJavaBdi` (`0x29ec0`), `ttm_sc_map` (`0x36088`), `ttm_sc_list` (`0x41214`, bao gồm thuật toán chia `sizeof(std::any) == 40` bằng hằng số nhân nghịch đảo `0xcccccccccccccccdULL` tại `0x41fd0`..`0x41fdc`), và `TTMExtJson` (`0x44f4c`).
4. **`ttmstrategycenter_cep_engine.h` & `.cpp`**: Tái tạo bộ đánh giá biểu thức `cep::TTMCEPExprEvaluator` (`0x32df8`), `registerTTMCEPExprEvaluator` (`0x34704`), `ttm_sc_process` (`0x35d34`), và `cep::EngineManager` (`0x47504`..`0x4c174`).
5. **`ttmstrategycenter_bytedt_jni.h` & `.cpp`**: Tái tạo động cơ cây quyết định GBDT `bytedt::ByteDT` (`0x4c370`..`0x4ea30`), hàm ánh xạ mã lỗi `transformByteDtErrorToTTMErrorCode` (`0x4d21c`, bảng tra `.rodata` tại `0x523d8`: `[0, 401, 402, 403, 404, 405, 406]`, mặc định `407`), cùng toàn bộ 16 hàm JNI và `JNI_OnLoad` (`0x2e6cc`).
6. **`ttmstrategycenter_interface.h`, `.cpp` & `ttmstrategycenter_pseudocode.cpp`**: Lớp Facade hợp nhất `TtmstrategycenterEngine` và mô hình đối chiếu hợp ngữ AArch64 phục vụ kiểm toán đối kháng Agent 13.
