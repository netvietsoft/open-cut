# Clean-Room Reconstruction Analysis — `libraphael.so`

- **Task ID**: `TASK-189-RECONSTRUCTION-LIBRAPHAEL` (`TASK_SO_147_libraphael`)
- **Target Index**: 150 / 169
- **Binary Size**: `51,336 bytes`
- **SHA-256**: `928e64ccde02fdf0a1e8d12a35148a360f0952c6dc9dbb7df328004e636b6d8a`
- **Architecture**: `EM_AARCH64` (64-bit ARMv8-A Little-Endian)
- **Unwind Table**: `106` FDEs in `.eh_frame_hdr` (`0x7fb8..0x8314`)
- **Executable `.text` Section**: `0x1e00..0x7b0c` (`23,820 bytes` = `5,955` AArch64 instructions)
- **Exported Symbols**: `JNI_OnLoad` (`0x3ecc`), `Java_com_bytedance_raphael_TestTool_mallocLeak` (`0x3f8c`), `Java_com_bytedance_raphael_TestTool_print` (`0x3fcc`)

## Key Subsystems Reconstructed
1. **JNI Registration & Control (`0x3ecc..0x463c`)**:
   - `JNI_OnLoad` (`0x3ecc..0x3f8c`) registers 3 `JNINativeMethod` entries stored in `.data` (`0x10000`, file offset `0xc000`).
   - `Java_com_bytedance_raphael_TestTool_mallocLeak` (`0x3f8c..0x3fcc`) allocates `0x70800` (`460,800`) bytes via `_Znam` (`operator new[]`) and fills with `1`.
   - `Java_com_bytedance_raphael_TestTool_print` (`0x3fcc..0x4054`) triggers `DiffCache` report generation.
2. **ByteHook Allocation Interceptors & Stack Unwinding (`0x463c..0x7b0c`)**:
   - Hooks `malloc`, `calloc`, `realloc`, `free`, `memalign`, `mmap`, `munmap`, and `pthread_create`/`pthread_exit` via `bytehook_hook_partial`.
   - Captures native stack traces via `npth_unw_frames_option` / `npth_unw_format_option` with `sigsetjmp`/`siglongjmp` (`sigsegv_buf`) fault protection.
3. **AllocCache & DiffCache (`0x1e00..0x3ecc`)**:
   - Lock-protected open-addressed/bucketed allocation cache (`"Alloc cache is full!!!!!!!!"`) and `/proc/self/maps` + report dumper (`"%s/reports"`).
