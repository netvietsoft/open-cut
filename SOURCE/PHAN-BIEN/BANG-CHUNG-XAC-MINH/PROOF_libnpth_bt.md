# Clean-Room Forensic Analysis & C++17 Reconstruction: `libnpth_bt.so`
## Phân Tích Pháp Y Nhị Phân & Tái Tạo C++17 Sạch: `libnpth_bt.so`

- **Task ID**: `TASK-165-RECONSTRUCTION-LIBNPTH-BT` (`TASK_SO_091_libnpth_bt`) — Target 126 / 169
- **Binary Size / Kích thước nhị phân**: `7,344 bytes` (`0x1cb0` bytes)
- **SHA-256**: `da4df4ef3b317309cbb3363bdf8e352ecdb8ae45a670d87ee1b426c32abdd150`
- **Unwind FDEs**: `18` FDEs at `.eh_frame_hdr` (`0x0009f4..0x000a90`)
- **Exported Symbols**: `5` (`npth_bt_thread` @ `0x0cb0`, `npth_bt_current` @ `0x0f84`, `npth_bt_all` @ `0x0f8c`, `npth_bt_free` @ `0x1138`, `npth_bt_increase` @ `0x119c`)
- **Reconstructed C++17 Volume**: `193,369 bytes` across 5 files (`0` stubs)

## Key Binary Forensics (Bằng Chứng Nhị Phân Trực Tiếp)
1. **Kiểm tra dải API Android (`0x0d38..0x0d40` & `0x100c..0x1014`)**:
   - `sub w8, w0, #0x24; cmn w8, #0x11; b.hs` kiểm tra `(uint32_t)(api - 36) >= 0xFFFFFFEF`, tức mức API nằm trong `[19 .. 35]`.
   - Từ API 28+ (`cmp w0, #0x1c` @ `0x0dfc`, `0x109c`), ưu tiên mở `libutilscallstack.so` (`0x08a8`), nếu thất bại mới fallback về `libutils.so` (`0x089c`).
2. **Bố cục 3 bảng con trỏ hàm động trong `.bss` (`0x009548..0x0095e8`)**:
   - `0x009558`: `CallStackSymbolTable40B` (`0x28 = 40 B` @ `0x0ea0`: `CallStackC1Ev`, `updateEii`, `updateEiii`, `toStringEPKc`, `CallStackD1Ev`).
   - `0x009560`: `String8SymbolTable16B` (`0x10 = 16 B` @ `0x0f50`: `String8C1Ev`, `String8D1Ev`).
   - `0x009568`: `ProcessCallStackSymbolTable32B` (`0x20 = 32 B` @ `0x1114`: `ProcessCallStackC1Ev`, `updateEv`, `toStringEPKc`, `ProcessCallStackD1Ev`).
