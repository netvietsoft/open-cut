# Clean-Room Forensic Analysis & C++17 Reconstruction: `libpreload.so`
## Phân Tích Pháp Y Nhị Phân & Tái Tạo C++17 Sạch: `libpreload.so`

- **Task ID**: `TASK-160-RECONSTRUCTION-LIBPRELOAD` (`TASK_SO_093_libpreload`) — Target 121 / 169
- **Binary Size / Kích thước nhị phân**: `3,657,488 bytes` (`3.66 MB`)
- **SHA-256**: `9f88e5ffe24e072d7ba2fb5a9bfe50378664a36db5998d0524574b8a238a11b9`
- **Unwind Table (`.eh_frame_hdr`)**: `0x305cfc` (`8,944` FDEs)
- **JNI Native Method Table (`.data` `0x3800d8`)**: `51` `JNINativeMethod` entries registered on `com/bytedance/vcloud/strategy/StrategyCenter`
- **Reconstructed C++17 Volume / Dung lượng C++17 tái dựng**: `2,274,029 bytes` across 9 files (`0` stubs)

## Key Binary Forensics (Bằng Chứng Nhị Phân Trực Tiếp)
1. **`JNI_OnLoad` (`0x27b3d0 .. 0x27b4b4`, `228 bytes`) & `RegisterNativeMethods` (`0x27b51c`)**:
   - Requests `JNI_VERSION_1_4` (`0x00010004` via `mov w2, #4; movk w2, #1, lsl #16` @ `0x27b3ec..0x27b404`).
   - Registers `51` (`#0x33` @ `0x27b430`) native methods from `.data` `0x3800d8` (`adrp x1, #0x380000; add x1, x1, #0xd8`) onto `"com/bytedance/vcloud/strategy/StrategyCenter"` (`.rodata` `0x2fc56e`).
   - Logs build banner `"-----compiled native library  %s %s-----"` (`0x2fc530`) with `"ManagerBridge.cpp"` (`0x2fc513`), `"Apr 10 2025"` (`0x2fc559`), `"06:51:27"` (`0x2fc565`), line `#0x4e7 = 1255`.
2. **`_create` (`0x27b5a4`) & `com::bd::vod::ST::StrategyCenter` (`0x0e3d9c`, `0x10d0 = 4,304 bytes`)**:
   - Allocates `0x10d0` (`4,304`) bytes (`0x27b5f4: 52821A00 mov w0, #0x10d0`), invokes `StrategyCenter::StrategyCenter()` (`0x0e3d9c`), and stores singleton at `.bss` `0x380dc0` (`0x27b60c: F906E314 str x20, [x24, #0xdc0]`).
3. **`_setIntValue` (`0x27c18c .. 0x27c1b8`)**:
   - Checks if key `w3 == 0xC3BF` (`50111`, `0x27c190: 529877E8 mov w8, #0xc3bf; 6B08007F cmp w3, w8`) to update the global preload log level at `0x04589c`, or forwards to `StrategyCenter::setIntValue` (`0x0e6dec`).
4. **`com::ss::ttm::player::Parcel::init` (`0x2919d4 .. 0x291b2c`, `344 bytes`)**:
   - Manages a 32-byte-per-element (`#0x20`, `asr x25, x9, #5` @ `0x291a40`) dynamic vector with $2\times$ capacity doubling (`asr x10, x10, #4` @ `0x291a64`) and max capacity `0x07FFFFFFFFFFFFFF` (`0x291a88`).
5. **`Json::FastWriter::~FastWriter` (`0x04aac8 .. 0x04ab08`, `64 bytes`)**:
   - Tests bit 0 of `[this + 0x08]` (`ldrb w8, [x0, #8]; tbz w8, #0, #0x4aaf8`) to conditionally free the heap string buffer at `[this + 0x18]`.
