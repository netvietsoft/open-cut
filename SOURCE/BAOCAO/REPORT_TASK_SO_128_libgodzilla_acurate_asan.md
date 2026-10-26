# Reconstruction Report — `libgodzilla-acurate-asan.so` (`TASK_SO_128_libgodzilla_acurate_asan`)
# Báo Cáo Nghiệm Thu Tái Tạo — `libgodzilla-acurate-asan.so`

- **Task ID**: `TASK-114-RECONSTRUCTION-LIBGODZILLA_ACURATE_ASAN` (`TASK_SO_128_libgodzilla_acurate_asan`)
- **Target Library**: `libgodzilla-acurate-asan.so` (`160,168 bytes`)
- **SHA-256**: `0c89ab013365273e0d1b626303f8948a1dbf72bf1d77ce5f2ec36b181b769a0c`
- **Status**: `VERIFIED_AND_ACCEPTED` (`100%`)

## Reconstructed Modules / Các Phân Hệ Đã Tái Tạo
1. **GWP-ASan `GuardedPoolAllocator` (`0x00eb28..0x01305c`)**:
   - `AllocatorState` (`0x58 = 88 B`), `AllocationMetadata` (`0x270 = 624 B`), `GuardedPoolAllocator` (`0xe8 = 232 B`).
   - `_ZN8gwp_asan20GuardedPoolAllocator13trapOnAddressEm5Error` (`0x011a0c`), `allocate` (`0x0116d0`), `deallocate` (`0x011a30`), `getSize` (`0x011c18`).
   - ZigZag + LEB128 backtrace compression (`pack` @ `0x01129c`, `unpack` @ `0x011320`) and Xorshift32 PRNG (`0x011438`).
2. **SIGSEGV Crash Handler & Recoverable `mprotect` (`0x01305c..0x014ce4`)**:
   - `cacheLoadedSharedLibBuildIds` (`0x01305c`) scanning `PT_NOTE` (`NT_GNU_BUILD_ID = 3`).
   - `dumpErrorReport` (`0x0132b8`), `signalHandler` (`0x0144a4`), `getBacktraceFastFP` (`0x01d5a8`), and `getBacktraceDwarf` (`0x01d684` with `0xdeadbeef` TLS guard).
3. **Custom Allocator Hooks `<0>..<7>` (`0x014ce8..0x01d5a4`)**:
   - Up to 8 `CustomHookContext` (`0xa0 = 160 B`) entries and 56 template hook functions supporting `ShadowHook` and `ByteHook`.
4. **Scudo Proxy Fault Handler (`0x01dfd4..0x01f5b8`)**:
   - `Java_com_bytedance_platform_godzilla_gwpasan_GodzillaAcurateAsan_initProxyFaultHandler` (`0x01ed68`), `isScudoMemoryAllocator` (`0x01f3e4`), and `patchInstructionWithRet` (`0x01f4ac`, patching `0xd65f03c0` `ret`).
5. **GodzillaRefDebug JNI GlobalRef Tracker (`0x01f810..0x021098`)**:
   - 7 JNI exports (`0x01ff1c..0x020108`), `RefRecordEntry` (`48 B`), `RefBucket` (`16 B`), `RefDebugState` (`24 B`), and bucket hash `(ref_val >> 2) % g_ref_bundle_size`.
