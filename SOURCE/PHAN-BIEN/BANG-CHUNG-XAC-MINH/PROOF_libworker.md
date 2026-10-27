# Adversarial Proof & Mathematical Verification: `libworker.so`
# Bằng Chứng Phản Biện & Xác Minh Toán Học: `libworker.so`

- **Task ID**: `TASK-133-RECONSTRUCTION-LIBWORKER` (`TASK_SO_071_libworker`)
- **Binary SHA-256**: `35c47b55e99c2789000c60cb0fa814c27df1187aee0974a34651b4aee69c2aa6`
- **Binary Size**: `313,400 bytes` (`313,400 bytes`)
- **Reconstructed C++17 Size**: `555,108 bytes` across `9` files (`0` stubs)
- **Verified Opcodes**: `3,803` AArch64 instructions
- **Unwind Table Coverage**: `572 / 572` FDE functions (`0x01c03c..0x0458b8`)

## Key Mathematical & Binary Proofs / Bằng Chứng Nhị Phân & Toán Học Cốt Lõi
1. **`JNI_OnLoad` (`0x01c03c..0x01c648`)**: Stores `JavaVM*` at `.bss 0x04c000`, calls `RegisterNativeall` (`0x0452d0`) for `Response` (`1`), `SystemThread` (`1`), `SystemMessageHandler` (`1`), `JsWorker` (`28` at `.data.rel.ro 0x049d28`), and `CallbackImpl` (`2`), and returns `0x00010006` (`JNI_VERSION_1_6`).
2. **`.rodata` SIMD Vector & 5 Piper JSB Jump Tables (`0x00d860..0x00da5f`)**: Exact byte-for-byte reconstruction of `{1ULL, 0xFFFFFFFFFFFFFFFFULL}` (`0x00d860`), `2ULL` (`0x00d870`), `MethodInvoker` signature char validator (`0x00d878`, 98B), and 4 switch jump tables (`0x00d8da`, `0x00d914`, `0x00d978`, `0x00d9ec`).
3. **Full `CityHash64` (`0x022d58..0x0231c4`) & NEON Popcount Hash Lookup (`0x022a68`, `0x0374b8`)**: Exact 64-bit primes (`k0..k3`, `kMul`) and `cnt v0.8b, v0.8b; uaddlv h0, v0.8b` power-of-two bucket test.
4. **`JsWorkerAndroid` `0xA8` (`168-byte`) ABI (`0x040708`) & `MessagePumpPosix` `0x000F4240` (`0x01fb7c`)**: Full structural and timing fidelity.
