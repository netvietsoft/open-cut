# Clean-Room C++17 Reconstruction Analysis — `libluster.so` (`TASK_SO_118_libluster` / `TASK-127`)

## 1. Binary Identity & Forensics / Định danh Nhị phân
- **File**: `libluster.so` (`250,720 bytes` / `0x3D360`)
- **SHA-256**: `18d0ecc52de2a8eb93a63bda59bbba1d179c92c7c56b342bfc01ed4866ab52d4`
- **Architecture**: AArch64 (`ARM64-v8a`), Little-Endian, Android NDK r21d (`6352462`)
- **Dependencies (`DT_NEEDED`)**: `libterrain.so`, `liblog.so`, `libm.so`, `libdl.so`, `libc.so`
- **Imported Symbols from `libterrain.so`**:
  - `cacheInitial` (`PLT 0x034b0`, `GOT 0x03ff80`)
  - `getCacheClass` (`PLT 0x034c0`, `GOT 0x03ff88`)
  - `vmInterpret` (`PLT 0x034e0`, `GOT 0x03ff98`)
  - `gVm` (`GOT 0x03fff8`, `.dynsym [10]`)
- **Exported Function**: `JNI_OnLoad` (`0x01674c..0x0167d0`, `132 bytes`)
- **Reconstructed C++17 Source Volume**: `267,967 bytes` across `9` C++17/H files (`0` stubs)

---

## 2. Architectural Role: ByteDance Cloak / Terrain DEX-to-Native VM Bridge
`libluster.so` is ByteDance's **Cloak / Terrain DEX-to-Native Virtualization Module** protecting **42 core Kotlin/Java classes** and **93 sensitive methods** in CapCut (`com.vega.subscription.*`, `com.vega.subscribe.*`, `com.vega.ad.credit.*`, `com.vega.draft.data.template.CommerceInfo`, `com.vega.launcher.network.interceptors.CrackingInterceptor`, `com.lemon.editor.proxy.SubscribeImpl`, `com.bytedance.EnvGuard.Handler`, and `com.vega.util.WindowUtilsKt`).

1. **`JNI_OnLoad` (`0x01674c..0x0167d0`)**:
   - Calls `(*vm)->GetEnv(vm, &env, 0x00010006)` (`JNI_VERSION_1_6`).
   - Calls `cacheInitial(env, 0x272a)` (`10,026` cache slots in `libterrain.so`).
   - Calls `sub_3b94(env)` (`0x003b94..0x004398`), which decrypts `"com/illusion/light/EffectUtil"`, `"Ew0PFxIIElcAXVdHWFpVCEM0"`, and `"(I)V"` via `sub_16328` (`0x016328`) and registers `sub_4398` (`0x004398`) via `RegisterNatives`.
2. **Dynamic Per-Class JNI Registration (`sub_4398` @ `0x004398..0x0050a0`)**:
   - Invoked from each protected class's `<clinit>` via `EffectUtil.Ew0PFxIIElcAXVdHWFpVCEM0(int classIndex)` (`0..41`).
   - Reads the 12-byte `LusterClassRegEntry` at `.rodata 0x016814 + classIndex * 12` (`{class_id, first_method_idx, method_count}`).
   - Resolves the internal class name via double-indirection (`0x016a0c + 0x029380[0x02af78[class_id]]`), builds `JNINativeMethod[method_count]` from `.data.rel.ro 0x03f750 + m * 16`, and calls `(*env)->RegisterNatives`.
3. **93 Virtualized JNI Entry Thunks (`0x0050a0..0x01459c`) & 7 `LusterHelperTable` Callbacks (`.data.rel.ro 0x03fd20..0x03fd58`)**:
   - Each of the 93 JNI methods constructs a 48-byte (`0x30`) `TerrainVMContext` pointing to its `.rodata` bytecode unit (`0x030246..0x0365e4`) and invokes `vmInterpret(env, &ctx, &kLusterHelperTable, target_class)`.
