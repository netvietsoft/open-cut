# Clean-Room Reconstruction of `libquick.so` (Target 116 / 169)
# Tái dựng Sạch `libquick.so` (Mục tiêu 116 / 169 — `TASK-155` / `TASK_SO_048_libquick`)

## 1. Binary Forensics & Overview / Pháp y Nhị phân & Tổng quan
- **Library**: `libquick.so` (ByteDance LEPUS / PrimJS / QuickJS JavaScript Engine, GarbageCollector, GlobalHandles & VmSdkMonitorAndroid)
- **File Size**: `1,837,504 bytes`
- **SHA-256**: `605dd5a78cda21f3b7758d9a69e88a497ef9f9df55543961037664f42a88f00d`
- **Architecture**: ELF64 AArch64 (`EM_AARCH64`, Little-Endian)
- **Dynamic Symbols (`.dynsym` @ `0x000330`)**: `1,547` exported symbols & `99` imported symbols
- **Unwind Table (`.eh_frame_hdr` @ `0x03768c`)**: `1,893` FDEs (`0x062670 .. 0x1b0b50`)

## 2. Key AArch64 Opcode & Struct Layout Proofs / Bằng chứng Opcode AArch64 & Bố cục Struct
1. **Heap Object Negative-Offset Metadata Header (`0x068440..0x068a90`)**:
   - `set_mark_multi(void* ptr)` (`0x068a44`): `52800028 mov w8, #1`, `B81FC008 stur w8, [x0, #-4]`, `D65F03C0 ret`.
   - `set_alloc_tag(void* ptr, int tag)` (`0x068a50`): `B85F8008 ldur w8, [x0, #-8]`, `121A6508 and w8, w8, #0xffffffc0`, `2A010108 orr w8, w8, w1`, `B81F8008 stur w8, [x0, #-8]`.
   - `set_heap_obj_len(void* ptr, int len)` (`0x068a64`): Checks `len < 0x2000000` (`52A04008 mov w8, #0x2000000`), inserts 26-bit length into bits `[31:6]` of `[ptr - 8]` (`331A6428 bfi w8, w1, #6, #0x1a`), and `get_heap_obj_len` (`0x068a88`) extracts it via `13067D00 asr w0, w8, #6`.
2. **`GlobalHandles` & `NodeSpace` (`0x06a018..0x06a2ac`)**:
   - `TotalSize()` (`0x06a018..0x06a028`): Computes `(block_count_ * 5) << 11 = block_count_ * 10240` (`0x2800` bytes per `NodeBlock`).
   - `UsedSize()` (`0x06a02c..0x06a03c`): Computes `(handles_count_ * 5) << 3 = handles_count_ * 40` (`40` bytes per `Node`).
   - `Create(LEPUSValue, bool)` (`0x06a0c8`): Allocates `0x2830` (`10,288 bytes`: `52850600 mov w0, #0x2830`) per `NodeBlock`.
3. **`JNI_OnLoad` (`0x1afc1c..0x1afd18`)**:
   - Stores `JavaVM*` to `.bss 0x1c1f30`, registers `VmSdkMonitorAndroid::RegisterJNI` (`0x1afd18`) and `vmsdk::general::logging::RegisterJNI` (`0x1af58c`), and returns `JNI_VERSION_1_6` (`0x00010006`: `11001280 add w0, w20, #4`).
