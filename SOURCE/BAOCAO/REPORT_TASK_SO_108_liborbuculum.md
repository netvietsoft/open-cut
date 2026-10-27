# Clean-Room C++17 Reconstruction: `liborbuculum.so` (TikTok Project Texas TTP Orbu / Orbuculum Native Network Security & Bytecode Validator Engine)
- **Target Number**: 101 / 169 (`TASK-140-RECONSTRUCTION-LIBORBUCULUM` / `TASK_SO_108_liborbuculum`)
- **Binary Size**: `412,176 bytes`
- **SHA-256**: `5f22a1ed255a53e0420ba6b8bcb36704673230d98a7e0e0ff619dfdd5cd5794f`
- **FDE Count (`.eh_frame_hdr` @ `0x053c64`)**: `577`
- **Exported `.dynsym` Symbols**: `625` (`11` `Java_ttp_orbu_sdk_netnative_TTPOrbuNetworkCaller_*` + `JNI_OnLoad` + `orbuculumProceedRequest` + `OrbuCodeEngine` + `SHA256` + `UrlParser`)
- **Reconstructed C++17/H Volume**: `1,055,206 bytes` across 9 files (`0` stubs)

## Architectural & Mathematical Proof Highlights
1. **`OrbuCodeEngine::init` (`0x0256fc..0x0258bc`) & `OrbuCodeEngine::processRequest` Division by `24` (`0x025d28..0x025d38`)**:
   - Checks 8-byte header magic at `.rodata 0x052b7d` (`0x02573c: mov w2, #8; bl memcmp`) and 8-byte alignment (`tst #7`) on `code_block_offset` (`+0x14`), `entry_table_offset` (`+0x0c`), `entry_table_size` (`+0x10`), and `data_table_offset` (`+0x1c`).
   - Allocates `DataTableReference` (`24 B = 0x18` @ `0x025800`), `BucketHandler` (`88 B = 0x58` @ `0x025820`, `max_load_factor = 1.0f = 0x3f800000` @ `+0x28`), and entry hash map (`40 B = 0x28` @ `0x025858`).
   - Computes executed instruction count via unsigned reciprocal multiplication by `0xAAAAAAAAAAAAAAABULL` (`0x025d28..0x025d38: umulh x8, x8, x9; lsr x8, x8, #4`), dividing byte delta by `24` (`sizeof(OrbuCodeInstructionStruct) == 0x18`).
2. **`isNetworkInstruction(OpCode)` (`0x02527c..0x025288`) & `BurstTime::shouldSend` Signed Division by `1,000` (`0x0442c0..0x044304`)**:
   - `isNetworkInstruction`: `sub w8, w0, #0x10; cmp w8, #0x17; cset w0, lo` (`(op - 0x10U) < 0x17U`).
   - `BurstTime::shouldSend`: converts microseconds to milliseconds via `smulh(x0, 0x20C49BA5E353F7CF) >> 7` + sign bit (`0x0442d4..0x0442f4`) and checks `<= threshold_ms` (`cset w0, le` @ `0x0442fc`).
3. **`SHA256::init` (`0x03da20..0x03da3c`) & `SHA256::sha256_k` (`.rodata 0x053600..0x0536ff`)**:
   - Loads initial 256-bit state `H0..H7` from `.rodata 0x0535e0..0x0535ff` into `ctx + 0x88` and `ctx + 0x98` via SIMD `ldr q0/q1` and `stur q0/q1`, and zeroes `m_tot_len` / `m_len` at `ctx + 0x00` (`str xzr, [x0]`).
