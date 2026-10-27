# Adversarial Proof & Mathematical Verification: `libmonitorcollector-lib.so`
# Bằng Chứng Phản Biện & Xác Minh Toán Học: `libmonitorcollector-lib.so`

- **Task ID**: `TASK-134-RECONSTRUCTION-LIBMONITORCOLLECTOR-LIB` (`TASK_SO_114_libmonitorcollector_lib`)
- **Binary SHA-256**: `739e2276dd31bc2805670367cfff2abc4a3d26e73e5b75635daff2a1f125e183`
- **Binary Size**: `313,744 bytes` (`313,744 bytes`)
- **Reconstructed C++17 Size**: `736,422 bytes` across `11` files (`0` stubs)
- **Verified Opcodes**: `5,200` AArch64 instructions
- **Unwind Table Coverage**: `1,030 / 1,030` FDE functions (`0x0117b0..0x038cf0`)

## Key Mathematical & Binary Proofs / Bằng Chứng Nhị Phân & Toán Học Cốt Lõi
1. **`JNI_OnLoad` (`0x0147b4..0x01498c`)**: Copies `0x450 = 1,104 bytes` (`46 * 24`) from `.data.rel.ro 0x04c948` and registers `0x2e = 46` JNI methods on `com/bytedance/monitor/collector/MonitorJni`.
2. **Binder Transaction Hook (`0x0143a0..0x0144a4`)**: Main-thread `IPCThreadState::transact` threshold `0x003D0900 = 4,000,000 ns` (`4 ms` at `0x01441c..0x014424`) and nanosecond-to-millisecond divisor `0x000F4240 = 1,000,000` (`0x014430..0x01443c`).
3. **Systrace Atomic Injection (`0x014174..0x014308`) & Lock Contention Detector (`0x0125b4..0x013670`)**: Atomic `ldaxr`/`stlxr` OR of `atrace_tags = 0x401a` (`.data 0x050028`) and ring buffers of `1,000` / `10,000` `AtraceEvent` entries (`.data 0x050000..0x050004`).
4. **`.rodata` Jump Tables (`0x038cf4[11]` & `0x038cff[7]`)**: `CollectStateValueFd` `/proc/[pid]/stat` fields 14..24 jump table (`0x016648..0x0166e8`) and `a64_get_imm` AArch64 instruction immediate decoder (`0x01c078..0x01c08c`).
