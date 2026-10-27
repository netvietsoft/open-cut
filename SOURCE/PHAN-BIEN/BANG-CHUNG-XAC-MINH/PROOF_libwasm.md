# Adversarial Verification Proof: `libwasm.so`
# Bằng Chứng Xác Minh Đối Kháng: `libwasm.so` (`TASK-124-RECONSTRUCTION-LIBWASM`)

- **Library**: `libwasm.so` (`247,792 bytes`, SHA-256 `41d9f6460616d3a74ee7b490891a0661329c9ccb98d72bbfd198be97bb8b255a`)
- **Reconstructed Code**: `331,571 bytes` across 9 clean-room C++17/H files (`0` stubs, `0` TODOs)

## 1. AArch64 Opcode Evidence / Bằng Chứng Mã Máy AArch64

1. **`RegisterWebAssembly` (`0x01003c..0x011344`)**:
   - `0x01003c`: `0xD10243FF` (`sub sp, sp, #0x90`)
   - `0x010054`: `0xB4004D00` (`cbz x0, #0x109f4` -> logs `"Register WebAssembly with invalid js context!"` @ `.rodata 0x006ea4`)
   - `0x01007c`: `0x528000A0` (`mov w0, #5` -> `ANDROID_LOG_WARN`, tag `"VmsdkWasmWarn"` @ `.rodata 0x007ec5`, message `"[VmSdkWasm] PRISM runtime requested but not built into libwasm.so; falling back to WASM3."` @ `.rodata 0x00724b`)
   - `0x01020c`: `0x52800F00` (`mov w0, #0x78` -> allocates `120 bytes` for `vmsdk::InteropRuntime`)
   - `0x01026c`: `0x52800400` (`mov w0, #0x20` -> allocates `32 bytes` for `vmsdk::wasm3::Wasm3Runtime`)
2. **`Java_com_bytedance_vmsdk_wasm_RegisterWebAssembly_loadWasmFactory` (`0x0117d8..0x0117e0`)**:
   - `0x0117d8`: `0xD0000140` (`adrp x0, #0x3b000`)
   - `0x0117dc`: `0xF9457000` (`ldr x0, [x0, #0xae0]` -> `.got 0x03bae0` = `0x01003c`)
   - `0x0117e0`: `0xD65F03C0` (`ret`)
3. **`m3_NewEnvironment` (`0x02268c..0x0228a8`)**:
   - `0x022770`: `0x52800220` (`mov w0, #0x11` -> `calloc(17, 1)` for 1-ret 0-arg `M3FuncType`)
   - `0x0227f8`: `0x52800220` (`mov w0, #0x11`)
   - `0x022880`: `0x52800220` (`mov w0, #0x11`)
4. **`m3_ParseModule` (`0x022bc0..0x022e80`)**:
   - `0x022be0`: `0x52801E00` (`mov w0, #0xf0` -> `calloc(240, 1)` for `M3Module`)
   - `0x022c00`: `0x92800008` (`movn w8, #0` -> `startFunction = -1`)
   - Dispatches sections `0..11` through `.data.rel.ro 0x03b888..0x03b8e8`.
5. **`m3_FreeModule` (`0x032d08..0x033004`)**:
   - `0x032d30`: `0x52808B15` (`mov w21, #0x458` -> `M3Function` stride `1,112 bytes`).

## 2. ABI & Mathematical Proofs / Chứng Minh Toán Học & Bố Cục ABI

- **`M3Module` (`0xF0` = 240 bytes)**, **`M3Function` (`0x458` = 1,112 bytes)**, **`M3Global` (`0x30` = 48 bytes)**, **`M3DataSegment` (`0x28` = 40 bytes)**, **`M3OpInfo` (`0x30` = 48 bytes)**, **`JSClassDef` (`0x28` = 40 bytes)**, **`JSCFunctionListEntry` (`0x28` = 40 bytes)** verified via `static_assert` and binary offset checks.
- **12-Section Parser Jump Table (`.data.rel.ro 0x03b888..0x03b8e8`)**: `[0]=0x035670`, `[1]=0x033008`, `[2]=0x0338cc`, `[3]=0x0335f8`, `[4]=0x034e98`, `[5]=0x035190`, `[6]=0x0353d8`, `[7]=0x0342e0`, `[8]=0x034678`, `[9]=0x034758`, `[10]=0x034848`, `[11]=0x034a58`.
