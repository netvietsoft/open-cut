# Clean-Room Reconstruction Analysis: `libnpth.so`
# Phân Tích Tái Tạo Phòng Sạch: `libnpth.so`

## 1. Binary Identity / Định Danh Nhị Phân
- **File**: `libnpth.so`
- **Task ID**: `TASK-197-RECONSTRUCTION-LIBNPTH` (`TASK_SO_073_libnpth_unwind`)
- **Size**: `181,952` bytes
- **SHA-256**: `ba58fcc3cf3bc7dc02214be07e7f22cd193c6e3f73a9d703bdd2f67a86dc63d5`
- **Architecture**: `AArch64 (EM_AARCH64, 64-bit LSB shared object)`
- **SONAME**: `libnpth.so`

## 2. Exact ELF Layout & `.eh_frame_hdr` FDE Table / Bố Cục ELF & Bảng FDE
- `.rodata`: `0x057f0` (`20,646` bytes — `sighand.txt`, `%s/pthreads.txt`, `_ZN3art3Dbg9SuspendVMEv`, `monitor_handler callback thread receied signal %d...`)
- `.eh_frame_hdr`: `0x0a898` (`3,396` bytes, `423` sorted FDE entries)
- `.eh_frame`: `0x0b5e0` (`19,240` bytes)
- `.text`: `0x10110 .. 0x29b90` (`105,088` bytes = `26,272` AArch64 instructions)
- `.plt`: `0x29b90` (`2,400` bytes)
- `.data.rel.ro`: `0x2e4f0` (`3,984` bytes)
- `.data`: `0x33ba8` (`724` bytes)
- `.bss`: `0x33e80` (`11,192` bytes)

## 3. Architecture & Mathematical Formulation / Kiến Trúc & Công Thức Toán Học
1. **JNI Registration (`JNI_OnLoad` @ `0x10160`, `first_op = 0xa9bc7bfd`)**:
   - Registers native methods for ByteDance NPTH (`NativeCrashCollector`) and initializes alternate signal stacks (`sigaltstack`) and POSIX signal handlers.
2. **Signal Interception & Tombstone Serialization (`sighand.txt`, `pthreads.txt`)**:
   - Captures `ucontext_t` (`x0..x30`, `sp`, `pc`, `pstate`, `fault_address`), suspends the ART VM via `_ZN3art3Dbg9SuspendVMEv` when safe, and writes async-signal-safe crash logs.
