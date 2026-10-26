# BÁO CÁO GIẢI MÃ KỸ THUẬT: `libTTMachineCore.so` (Target 44)

- **Dung lượng nhị phân (`OBSERVED`)**: `429,872 bytes` (`0.41 MB`)
- **Định dạng nhị phân**: `ELF 64-bit LSB shared object, ARM aarch64`
- **Phân loại Lõi C++**: `CORE_04_MULTIMEDIA` / `TTM_BYTECODE_VIRTUAL_MACHINE`
- **Tổng số dynamic symbols (`.dynsym`)**: `830` (`734` exported + `96` imported)
- **Hàm JNI xuất xưởng & đăng ký động (`JNI_OnLoad` @ `0x4f538`)**: `1` exported (`JNI_OnLoad`, `3,488 bytes`) + `19` `JNINativeMethod` đăng ký qua `RegisterNatives` (`10` thuộc `com/tiktok/ttm/TTMCore$JNIHelper` tại `0x6a8f0` + `9` thuộc `com/tiktok/ttm/storage/TTMCoreKVManager` tại `0x6a9e0`)
- **Hàm C++ demangled bóc tách được**: `273`

---

## 1. Bố cục Phân đoạn ELF64, 8 Kiểu `TTMTypeObject` & Bảng 73 Opcode (`OBSERVED`)

| Phân đoạn / Biến toàn cục | Địa chỉ ảo (`vaddr`) | Offset file | Kích thước / Giá trị thực tế |
|---|---|---|---|
| `PT_LOAD 0` (R+X `.rodata` + `.text`) | `0x000000..0x064cc0` | `0x000000..0x064cc0` | `412,864 bytes` |
| `PT_LOAD 1` (R+W `.data.rel.ro` + `.data` + `.bss`) | `0x069ec8..0x06e0d0` | `0x065ec8..0x0686d8` | `file_offset = vaddr - 0x4000` |
| `state_code_names` (`73 x char*`) | `0x06a268..0x06a4af` | `0x066268..0x0664af` | `584 bytes` (`State_create_list_direct` [0] .. `State_bin_op` [72]) |
| `ttm_base46_map` (Bảng Base64) | `0x06c001..0x06c040` | `0x068001..0x068040` | `64 bytes` (`"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"`) |
| `TTMDictO_Type`..`TTMStrO_Type` | `0x06c048..0x06c647` | `0x068048..0x068647` | `8 x 192 bytes` (`dict`, `float`, `int`, `iterator`, `list`, `none`, `slice`, `str`) |
| `LONG_MAX_VALUE` / `INT_MAX_VALUE` / `DOUBLE_MAX_VALUE` | `0x06c650` / `0x06c658` / `0x06c660` | `0x068650` / `0x068658` / `0x068660` | `0x7fffffffffffffff` / `0x7fffffff` / `0x7fefffffffffffff` |

---

## 2. Kiến trúc 4 Phân hệ C++17 Đã Tái Tạo Hoàn Chỉnh (`12 files`, `> 70 KB`)

1. **`ttmachinecore_types.h`**: Định nghĩa 73 mã lệnh máy ảo `TTMInstructionState`, bảng mã lỗi `TTMStateErrorCode`, 8 cấu trúc `TTMTypeObject` (`192 bytes`), và hằng số `.data`.
2. **`ttmachinecore_objects_hashmap.h` & `.cpp`**: Tái tạo bảng băm địa chỉ mở `ttm_hashmap_*` kèm `hashmap_sip` (`0x1b5e8`) và `hashmap_murmur` (`0x1b81c`), bộ cấp phát `ttm_am_*`, cùng toàn bộ hàm thao tác `TTMDict`, `TTMListO`, `TTMStrO`, `TTMSliceO` (`TTMSlice_adjust_indices` @ `0x238dc`).
3. **`ttmachinecore_vm_bytecode.h` & `.cpp`**: Tái tạo bộ tiền xử lý `pre_process_byte_code` (`0x1a700`, kiểm tra magic `0x775cc02e` và version `<= 10`), `ttm_state_error_code_for_business` (`0x1758c`, kiểm tra chia hết cho 1000 bằng hằng số nhân `0x26e978d5` và `extr #3`), và máy ảo thực thi 73 trạng thái `ttm_travel` (`0x1bb64`, `12,544 bytes`).
4. **`ttmachinecore_bdi_bridges.h` & `.cpp`**: Tái tạo `TTMUniversalBdiFunLoader` (`0x2869c`), `AnTTMUniversalBdiFunLoader` (`0x44208`), các hàm cầu nối xử lý chuỗi/toán học/thống kê danh sách, và lưu trữ Keva KV (`0x4934c..0x4a2fc`).
5. **`ttmachinecore_extdata_cjson_jni.h` & `.cpp`**: Tái tạo `ITTMExtDataBdi`, `TTMExtJsonDataBdi`, `TTMExtDataDelegate`, bộ phân tích `cJSON`, cùng `JNI_OnLoad` (`0x4f538`) và 19 hàm JNI (`0x6a8f0` & `0x6a9e0`).
6. **`TTMachineCore_interface.h`, `ttmachinecore_interface.cpp` & `TTMachineCore_pseudocode.cpp`**: Lớp Facade hợp nhất `TtmachinecoreEngine` và tham chiếu hợp ngữ AArch64.
