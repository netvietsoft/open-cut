# BẰNG CHỨNG XÁC MINH ĐỐI KHÁNG (ADVERSARIAL PROOF): `libnapi.so`

- **Task ID**: `TASK-126-RECONSTRUCTION-LIBNAPI` (`TASK_SO_119_libnapi`)
- **Thư viện mục tiêu**: `SOURCE/apktool-res/lib/arm64-v8a/libnapi.so` (`247,904 bytes`, SHA-256 `fb3a870c14315fcc8976c7edd2653ad80ef3ab96ceb534f0d6354aa91e82764c`)
- **Dung lượng C++17/H tái dựng sạch**: `230,652 bytes` (`11` tệp `.cpp`/`.h` + `README_ANALYSIS.md`, `0` stub)

---

## 1. Bằng chứng Opcode AArch64 & Bố cục ABI `napi_env__` (`0x015e28..0x0160d0`)

### 1.1. `napi_new_env` (`0x015e28..0x015ecc`)
```assembly
0x015e30: 52808600  mov  w0, #0x430          ; sizeof(napi_env__) = 1,072 bytes
0x015e34: 9400849f  bl   #0x370b0            ; operator new(0x430)
0x015e38: 52808602  mov  w2, #0x430
0x015e44: 940084c3  bl   #0x37150            ; memset(env, 0, 0x430)
0x015e48: 52800400  mov  w0, #0x20           ; sizeof(NapiEnvState) = 32 bytes
0x015e4c: 94008499  bl   #0x370b0
0x015e60: 52800500  mov  w0, #0x28           ; sizeof(CleanupHookTable) = 40 bytes
0x015e68: 52a7f008  mov  w8, #0x3f800000     ; max_load_factor = 1.0f at +0x20
```

### 1.2. `napi_free_env` (`0x015ecc..0x0160d0`)
- Kiểm tra tràn mảng phần tử 24-byte (`CleanupHookEntry`):
  `0x015ef4: mov x24, #-0x5555555555555556; movk x24, #0xaaa, lsl #48` (`0xaaaaaaaaaaaaaaaab = floor(2^64 / 24)`).
- Tính băm hook và chỉ số bucket bằng NEON popcount:
  `0x015fbc: cnt v0.8b, v0.8b; uaddlv h0, v0.8b`
  `0x015fcc: eor x11, x9, x0, lsl #1` (`hash = fn ^ (arg << 1)`).

---

## 2. Bằng chứng `napi_attach_quickjs` (`0x01c1a0..0x01c8b4`) & NaN-Boxing (`0x027468..0x027564`)
- Cấp phát `qjsimpl::Context` (`sizeof = 0x450 = 1,104 bytes` tại `0x01c6a8: mov w0, #0x450; bl #0x370b0`), nạp cặp hằng số `{2ULL, 18ULL}` từ `.rodata 0x00c7c0` vào `+0x18..+0x20`, và intern 11 `QuickJSAtom` (`0x50 = 80 bytes` mỗi khe tại `+0x0c8..+0x3e8`).
- `napi_module_register_xx` (`0x027568..0x02759c`) và `napi_find_module` (`0x0275a0..0x027600`) dùng khóa xoay nguyên tử 1-byte (`ldaxrb`/`stxrb`/`stlrb`) tại `.bss 0x03c038` bảo vệ danh sách liên kết đơn module tại `.bss 0x03c040`.

---

## 3. Bằng chứng Bảng Nhảy `Napi::TypedArray::ElementSize` (`0x02afd0..0x02b07c`) & `JNI_OnLoad` (`0x036ef0..0x037070`)
- Tại `.rodata 0x00c81b`: bảng dịch chuyển 11 byte `[10, 10, 10, 6, 6, 0, 0, 0, 3, 3, 3]` nhảy từ `0x02b04c` với `w0 = 1` nạp trước tại `0x02b044`, trả về chính xác `1`, `2`, `4`, hoặc `8` byte cho `napi_typedarray_type` `0..10`.
- `JNI_OnLoad` (`0x036ef0..0x037070`) lưu 3 GlobalRef (`JavaOnlyMap` -> `.bss 0x03c118`, `JavaOnlyArray` -> `.bss 0x03c048`, `NativeHostObject` -> `.bss 0x03c1c8`), gọi `__android_log_print(3, "PRIMJS", "load")` và trả về `0x00010006` (`JNI_VERSION_1_6`).
