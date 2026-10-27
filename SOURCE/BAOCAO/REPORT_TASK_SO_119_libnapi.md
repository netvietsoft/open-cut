# BÁO CÁO NGHIỆM THU TÁI CẤU TRÚC C++17: `libnapi.so` (`TASK_SO_119_libnapi` / `TASK-126`)

- **Trạng thái**: `COMPLETED` (`100%`)
- **Nhị phân gốc**: `SOURCE/apktool-res/lib/arm64-v8a/libnapi.so` (`247,904 bytes`, SHA-256 `fb3a870c14315fcc8976c7edd2653ad80ef3ab96ceb534f0d6354aa91e82764c`)
- **Mã nguồn C++17/H tái dựng**: `230,652 bytes` (`11` tệp `.cpp`/`.h` + `README_ANALYSIS.md`, `0` stub) tại `SOURCE/GIAI-MA/libnapi/`

## Tóm tắt Kết quả Giải mã & Kiểm증
1. **`napi_env__` (`0x430 = 1,072 B`), `napi_new_env` (`0x015e28`) & `napi_free_env` (`0x015ecc`)**: Khôi phục đầy đủ bảng điều phối 1,072 byte, `NapiEnvState` (`32 B`), `CleanupHookTable` (`40 B`, `max_load_factor = 1.0f`), hàm băm `fn ^ (arg << 1)` và sắp xếp LIFO `sub_160d0`.
2. **`napi_attach_quickjs` (`0x01c1a0..0x01c8b4`, `1,812 B`) & `qjsimpl::Context` (`0x450 = 1,104 B`)**: Khôi phục 78 hàm N-API cho QuickJS/LepusNG, 11 `QuickJSAtom` (`80 B` mỗi khe tại `+0x0c8..+0x3e8`), chuyển đổi NaN-boxing (`0x027468..0x027564`) và sổ đăng ký module khóa xoay nguyên tử `.bss 0x03c038` (`0x027568..0x027600`).
3. **217 Hàm `Napi::*` (`0x027604..0x02db6c`) & `vmsdk::general::android` / `vmsdk::icu` (`0x02ef60..0x037070`)**: Khôi phục bảng nhảy `Napi::TypedArray::ElementSize` (`.rodata 0x00c81b`: `[10, 10, 10, 6, 6, 0, 0, 0, 3, 3, 3]`), `JavaOnlyArray`, `JavaOnlyMap`, `JNIHelper`, `icu::optionsFromJava`/`optionsToJava`, và `JNI_OnLoad` (`0x036ef0` -> `0x00010006`).
