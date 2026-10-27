# Clean-Room Reconstruction Analysis — `libapplovin-native-crash-reporter.so`
## Phân Tích Tái Tạo Phòng Sạch — `libapplovin-native-crash-reporter.so`

- **Target Binary / Nhị phân mục tiêu**: `libapplovin-native-crash-reporter.so` (`860,200 bytes`)
- **SHA-256**: `ecf2a7327be482870f4c791392a50cecfeaabb2c76a7224898e9713a18c4c36a`
- **Task ID**: `TASK-149-RECONSTRUCTION-LIBAPPLOVIN-NATIVE-CRASH-REPORTER` / `TASK_SO_097_libapplovin_native_crash_reporter`
- **Architecture / Kiến trúc**: `AArch64` (`ELF64 Little-Endian`, `.eh_frame_hdr` @ `0x04e014`, `1,757` FDEs)
- **Exported Symbols / Biểu tượng xuất**: `1,994`
- **Imported Symbols / Biểu tượng nhập**: `143`
- **Reconstructed C++17 Size / Dung lượng C++17 tái tạo**: `1,424,637 bytes` across 9 files (`0` stubs)

---

## 1. Key Verified AArch64 Functions & Mathematical Proofs / Các Hàm AArch64 & Chứng Minh Toán Học

1. **`NativeCrashReporterContext` Constructor & Destructor (`0x0606e8..0x060b4c`)**:
   - `0x060720..0x06074c`: Allocates 32 KB (`0x8000`) alternate signal stack (`52900008 mov w8, #0x8000; F9001668 str x8, [x19, #0x28]; F8018F20 str x0, [x25, #0x18]!`).
   - `0x060768..0x060778`: Sets `sa_flags = 0x08000004` (`SA_SIGINFO | SA_ONSTACK`: `52800088 mov w8, #4; 72A10008 movk w8, #0x800, lsl #16; B90002E8 str w8, [x23]`) and `sa_sigaction` at `+0x38`.
   - `invoke_old_signal_handler` (`0x060abc..0x060b3c`): Searches `signals_` vector at `+0x00`, indexes `old_actions_` at `+0x50` with 32-byte stride (`8B081548 add x8, x10, x8, lsl #5`), and branches on `SA_SIGINFO` bit `#2` (`37100109 tbnz w9, #2, #0x60b28`).
2. **Atomic Crash State Machine (`0x0618c8..0x061ab0`)**:
   - `crash_detected` (`0x0618c8..0x0618f0`): `08DFFD08 ldarb` on `0x0d9798` (`g_is_handling_crash`) and `0x0d979c` (`g_crash_handled`).
   - `begin_handling_crash` (`0x061a24..0x061a90`): `085FFD69 ldaxrb w9, [x11]; 6B0A013F cmp w9, w10; 54000121 b.ne #0x61a7c; 5280002C mov w12, #1; 080DFD6C stlxrb w13, w12, [x11]; 35FFFF6D cbnz w13, #0x61a50`.
   - `end_handling_crash` (`0x061a94..0x061ab0`): `089FFD09 stlrb w9, [x8]` (`0x0d979c = 1`) and `089FFD5F stlrb wzr, [x10]` (`0x0d9798 = 0`).
3. **`get_signal_cause(int, int)` (`0x061ab4..0x062084`)**:
   - Validates `si_code > 0` (`7100003F cmp w1, #0; 540003AD b.le #0x61b3c`) and `uint32_t(signo - 4) <= 13` (`51001008 sub w8, w0, #4; 7100351F cmp w8, #0xd; 54000348 b.hi #0x61b3c`).
