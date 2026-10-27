# Clean-Room Reconstruction of `libfast_engine_RelWithDebInfo.so` (Target 113 / 169)
# Tái dựng Sạch `libfast_engine_RelWithDebInfo.so` (Mục tiêu 113 / 169 — `TASK-152` / `TASK_SO_008_libfast_engine_RelWithDebInfo`)

## 1. Binary Forensics & Overview / Pháp y Nhị phân & Tổng quan
- **Library**: `libfast_engine_RelWithDebInfo.so` (`fast_engine::FastEngine` Native Python-Compatible Bytecode VM, VM Pool Scheduler & Base-26 Module Cipher Engine)
- **File Size**: `1,309,048 bytes`
- **SHA-256**: `937ec38b3511f7df50b82c02c87db88ec472d8756d7c21e7ecf792c86a7281f8`
- **Architecture**: ELF64 AArch64 (`EM_AARCH64`, Little-Endian)
- **Unwind Table (`.eh_frame_hdr` @ `0x1127c8`)**: `2,082` FDEs (`0x045cbc .. 0x1098c8`)
- **Dynamic Symbols (`.dynsym` @ `0x006190`)**: `1,691` exported symbols & `144` imported symbols

## 2. Key AArch64 Opcode & Mathematical Proofs / Bằng chứng Opcode AArch64 & Toán học
1. **`fast_engine::FastEngine::Instance()` (`0x045cd4..0x045d7c`, `168 bytes`)**:
   - Checks singleton guard at `.bss 0x143178` (`08DFFD08 ldarb w8, [x8]`), allocates `0x120` (`288 bytes`) via `operator new` (`52802400 mov w0, #0x120`), sets `max_vm_count_ = 1` at `+0x118` (`52800028 mov w8, #1`, `B9011808 str w8, [x0, #0x118]`) and `initialized_ = false` at `+0x11c` (`3904701F strb wzr, [x0, #0x11c]`).
2. **VM Pool Stride `0x19450` (`103,504 bytes`) in `HasFreeVM` (`0x04632c`) & `GetOrCreateVM` (`0x046394`)**:
   - Iterates `std::vector<Engine>` at `[this + 0x18..0x28]` with stride `0x19450` (`52928A0A mov w10, #0x9450`, `72A0002A movk w10, #1, lsl #16`), checking `is_free` at `[engine + 0x04]`.
3. **Bijective Base-26 XOR-7 Module Name Cipher (`EncryptModuleName` @ `0x046b54`, `DecryptModuleName` @ `0x046db0`)**:
   - Encryption: `x = c ^ 7` (`520009AD eor w13, w13, #7`), `q = (x * 0x4ec4ec4fULL) >> 35` (`9BAB7DCE umull` + `D363FDCE lsr #0x23`), `r = x - 26 * q` (`1B0CB5CD msub`), outputting `(r + 'A', q + 'A')`.
   - Decryption: Folds `- 'A'` (`65 * 26 + 65 = 1755`) via `+ 0x25` (`37`, since `1755 + 37 = 1792 = 7 * 256 ≡ 0 mod 256`): `((hi * 26 + lo + 0x25) & 0xff) ^ 7` (`1B08358C madd`, `1100958C add #0x25`, `5200098C eor #7`).
