# Clean-Room Forensic Analysis & C++17 Reconstruction: `libsscronet.so`
## Phân Tích Pháp Y Nhị Phân & Tái Tạo C++17 Sạch: `libsscronet.so`

- **Task ID**: `TASK-161-RECONSTRUCTION-LIBSSCRONET` (`TASK_SO_040_libsscronet`) — Target 122 / 169
- **Binary Size / Kích thước nhị phân**: `5,973,416 bytes` (`5.97 MB`)
- **SHA-256**: `2005c6574bf4c56204365be7f9cca38981e6bffb8bbd2eab03f2abb1a6b052c6`
- **Unwind Table (`.eh_frame_hdr`)**: `0x0f1dd8` (`19,032` FDEs)
- **Exported Symbols (`.dynsym` `0x000388`)**: `1,225` exported symbols (`Cronet_*`, `TTQuicHe_*`, `Q_Eng_*`, `Q_Conn_*`, `Q_Stream_*`, `JNI_OnLoad`)
- **Reconstructed C++17 Volume / Dung lượng C++17 tái dựng**: `2,421,027 bytes` across 9 files (`0` stubs)

## Key Binary Forensics (Bằng Chứng Nhị Phân Trực Tiếp)
1. **ARMv8.3-A PAC/BTI Hardware Control-Flow Integrity (`.note.gnu.property` @ `0x000368`)**:
   - All functions begin with `paciasp` (`0xD503233F`) or `bti c` (`0xD503245F`) and conclude with `autiasp; ret` (`0xD50323BF; 0xD65F03C0`).
2. **`JNI_OnLoad` (`0x1c74a8 .. 0x1c78bc`, `1,044 bytes`)**:
   - Uses atomic acquire guard at `.bss` `0x5df620` (`0x1c74cc: 08DFFD08 ldarb w8, [x8]; 0x1c74fc: 940EFE59 bl #0x586e60` = `__cxa_guard_acquire`), caches `JavaVM*` at `.bss` `0x5df790` (`0x1c7540: F903C913 str x19, [x8, #0x790]`), and returns `g_sscronet_jni_version` from `.data` `0x5b9918` (`0x1c74d4: B9491A80 ldr w0, [x20, #0x918]`).
3. **Consolidated Thunks (`0x1c9738`, `0x1ea6f4`, `0x1fac70`)**:
   - `0x1c9738`: `D503245F bti c; 14044B9E b #0x2dc5b4` (6 POD `Cronet_*_Destroy` symbols).
   - `0x1ea6f4`: `D503245F bti c; B4000040 cbz x0, #0x1ea700; 1403C7AE b #0x2dc5b4; D65F03C0 ret` (25 virtual `*_Destroy` symbols).
   - `0x1fac70`: `D503245F bti c; F9000401 str x1, [x0, #8]; D65F03C0 ret` (38 `*_SetClientContext` symbols storing `client_context` at offset `+0x08`).
4. **Exact Struct Allocation Sizes**:
   - `Cronet_Throttle_Create` (`0x267f10`): `0x88` (`136 B` @ `0x267f20: 52801100 mov w0, #0x88`).
   - `Q_Eng_Create` (`0x279dd0`): `0x1c0` (`448 B` @ `0x279de0: 52803800 mov w0, #0x1c0`), `max_streams = 256` at `+0x60` (`0x279e30`), `idle_timeout_ms = 500` at `+0x118` (`0x279e88`), returns `x19 + 0x10` (`0x279e1c` & `0x279ea4`).
   - `Q_Conn_Create` (`0x27caf4`): `0x168` (`360 B` @ `0x27cb04: 52802D00 mov w0, #0x168`), `socket_fd = -1` at `+0x80` (`0x27cb40`).
   - `Q_Stream_Create` (`0x27f834`): `0xb60` (`2,912 B` @ `0x27f844: 52816C00 mov w0, #0xb60`), `stream_flags = 0x101` at `+0xe0` (`0x27f898`).
   - `TTQuicHe_Engine_Create` (`0x28a96c`): `0x98` (`152 B` @ `0x28a97c: 52801300 mov w0, #0x98`).
   - `TTQuicHe_HttpRequest_Create` (`0x28a9f8`): `0xee8` (`3,816 B` @ `0x28aa08: 5281DD00 mov w0, #0xee8`).
