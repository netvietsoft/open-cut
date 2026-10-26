# Clean-Room Architectural & Binary Reconstruction: `libosfix.so` (`TASK-112-RECONSTRUCTION-LIBOSFIX`)

## 1. Binary Overview / Tổng quan Nhị phân (`[OBSERVED]`)
- **File Path**: `apktool-res/lib/arm64-v8a/libosfix.so`
- **File Size**: `149,616 bytes` (`0x24870` bytes)
- **SHA-256**: `ddd8baabbcdd7941b13ab0e961a57e92843d957a0c64e6afa3613b2c433c937d`
- **Architecture**: `AArch64` (`ARM64-v8a`, Little-Endian LP64)
- **DT_NEEDED Dependencies**:
  `liblog.so`, `libnpth_dl.so`, `libbytehook.so`, `libshadowhook.so`, `libm.so`, `libc++_shared.so`, `libdl.so`, `libc.so`
- **ELF Section Layout**:
  - `.plt`: `0x005760 .. 0x005d4f` (`1,520 bytes`)
  - `.text`: `0x005d50 .. 0x01bfaf` (`90,720 bytes`, file offset `0x005d50`)
  - `.rodata`: `0x01bfb0 .. 0x01d68c` (`5,853 bytes`, file offset `0x01bfb0`)
  - `.init_array`: `0x026e10 .. 0x026e1f` (`16 bytes`, file offset `0x022e10`: constructors `0x005d50` & `0x005df4`)
  - `.fini_array`: `0x026e20 .. 0x026e2f` (`16 bytes`, file offset `0x022e20`: `0x005e50` & `0x005e40`)
  - `.data`: `0x028000 .. 0x028017` (`24 bytes`, file offset `0x024000`)
  - `.bss`: `0x028020 .. 0x02841f` (`1,024 bytes`)

---

## 2. Exported JNI Symbols & Subsystem Architecture / Kiến trúc 3 Phân hệ & 12 Biểu tượng JNI (`[OBSERVED]`)

### 2.1. `com.bytedance.osfix.NativeToolUtil` (`0x005d50 .. 0x0090d0`)
1. **`.init_array[0]` (`0x005d50 .. 0x005df3`)**:
   Initializes `std::shared_timed_mutex` (`144 bytes`) at `.bss 0x028040` (`pthread_mutex_init` at `0x028040`, `pthread_cond_init` at `0x028068`, `pthread_cond_init` at `0x028098`, state word `0` at `0x0280c8`) and registers `~shared_timed_mutex` (`0x005da8`) via `__cxa_atexit`.
2. **`Java_com_bytedance_osfix_NativeToolUtil_nativeCrash` (`0x005e7c`)**:
   Executes hardware breakpoint trap `brk #1` (`0xd4200020`).
3. **`Java_com_bytedance_osfix_NativeToolUtil_nativeOOM` (`0x005e80 .. 0x005eef`)**:
   Loops allocating `0x3200000` (`52,428,800 bytes` = 50 MB) chunks via `operator new[](0x3200000)`, pushing pointers into a `std::vector<void*>`, and calling `sleep(2)` (`mov w0, #2; bl sleep`).
4. **`Java_com_bytedance_osfix_NativeToolUtil_logSoLoader` (`0x005ef0 .. 0x006167`) & `fansheJVMLog` (`0x008ee0 .. 0x00902b`)**:
   Stores delay threshold (`jlong`) at `.bss 0x028020`, calls `bytehook_set_debug(1)`, registers `dlopen_pre_callback` (`0x005fe4`) and `dlopen_post_callback` (`0x00609c`) via `bytehook_add_dlopen_callback`, caches `JavaVM*` (`.bss 0x028028`), `com/bytedance/osfix/NativeToolUtil` GlobalRef (`.bss 0x028030`), and `alogDelay(Ljava/lang/String;J)V` (`.bss 0x028038`).
5. **`Java_com_bytedance_osfix_NativeToolUtil_nlogcatI` (`0x006168 .. 0x0061d7`)**:
   Logs Java string at `ANDROID_LOG_INFO` (`4`) under `"NativeToolUtil"`.
6. **`Java_com_bytedance_osfix_NativeToolUtil_fixGetSetEnvCall` (`0x0064ec .. 0x00656f`)**:
   Hooks `"setenv"` (`0x00627c`, acquiring exclusive `shared_timed_mutex::lock()` / `unlock()`) and `"getenv"` (`0x00633c`, acquiring shared `shared_timed_mutex::lock_shared()` / `unlock_shared()`) via `bytehook_hook_partial` (excluding `"libosfix.so"`, `"libbytehook.so"`, `"libc.so"` in filter `0x0061d8`).
7. **`Java_com_bytedance_osfix_NativeToolUtil_logGetEnvErrorCode` (`0x006570 .. 0x00699f`)**:
   Hooks `"__android_log_assert"` (`0x006678`, reading AArch64 `tpidr_el0` Bionic TLS slots `+0x08` `TLS_SLOT_THREAD_ID`, `+0x18` `TLS_SLOT_OPENGL`, `+0x20` `TLS_SLOT_OPENGL_API`, `+0x28` `TLS_SLOT_STACK_GUARD`, `+0x38` `TLS_SLOT_ART_THREAD_SELF`, `+0x40` `TLS_SLOT_DTV`, `+0x48` `TLS_SLOT_BIONIC_TLS`, logging `pthread_self()` and `gettid()`, and sleeping `1000` seconds `0x3e8`) and hooks `_ZN15SkAnimatedImage15decodeNextFrameEv` (`0x0063e4`) in `"libhwui.so"` via `shadowhook_hook_sym_name`.
8. **`Java_com_bytedance_osfix_NativeToolUtil_is64runtime` (`0x006b50 .. 0x006b57`)**:
   Returns `1` (`JNI_TRUE`: `mov w0, #1; ret`).
9. **`Java_com_bytedance_osfix_NativeToolUtil_logVdexOpen` (`0x006b58 .. 0x006bf3`)**:
   Hooks `"open"` (`0x006a98`) and `"openat"` (`0x0069d0`) in `"libart.so"` / `"libartbase.so"` to log `"open vdex"` when `.vdex` files are opened.
10. **`Java_com_bytedance_osfix_NativeToolUtil_fixVdexRepeatOpen` (`0x008d58 .. 0x008e3b`) & `freeVdex` (`0x006f9c .. 0x00856b`)**:
    Hooks `art::DexFileFromMemory::Create` (`0x008bf4`) in `"libart.so"` via `shadowhook_hook_sym_name` and `BacktraceCurrent::UnwindThread` (`0x008cb4`) in `"libbacktrace.so"` via `bytehook_hook_partial`. Invokes `freeVdex` (`0x006f9c`), which scans `/proc/self/smaps` for `.vdex` mappings belonging to the package in `/proc/self/cmdline` (`0x006bf4`), extracts `start_addr` and `end_addr` via `(\w{8})-(\w{8})` and `Pss` via `Pss:\s+(\d+)\skB`, and if `Pss <= 1024 kB` (`0x400` at `0x007da8`), calls `munmap((void*)start_addr, end_addr - start_addr)` (`0x007f2c`).

### 2.2. `com.bytedance.osfix.ThreadStackOptimizer` (`0x01681c .. 0x016b9b`)
11. **`Java_com_bytedance_osfix_ThreadStackOptimizer_nativeShrinkthread` (`0x016b7c .. 0x016b9b`)**:
    Calls `shrink_thread_impl` (`0x016908 .. 0x016ae7`), which checks `ro.build.version.release`, resolves `_ZN3art6Thread14CreateCallbackEPv` (`.bss 0x028198`) and (if Android release > 13 / `0xd`) `_ZN3art6Thread24CreateCallbackWithUffdGcEPv` (`.bss 0x028190`) in `"libart.so"` via `npth_dlopen` / `npth_dlsym`, stores `java_shrink_thread_size` (`.data 0x028008`, default `0x00030000` = 192 KB) and `native_shrink_thread_size` (`.data 0x02800c`, default `0x00080000` = 512 KB), and hooks `"pthread_create"` (`0x01681c`) via `bytehook_hook_partial` (excluding `"libosfix.so"`, `"libv8_libfull.cr.so"`, `"libquick.so"`, `"libGLES_mali.so"` in filter `0x016b08`).

### 2.3. `com.bytedance.osfix.TypeFaceOptimizer` (`0x016b9c .. 0x01814f`)
12. **`Java_com_bytedance_osfix_TypeFaceOptimizer_optimize` (`0x016b9c .. 0x016ba3`)**:
    Returns `1` (`JNI_TRUE`: `mov w0, #1; ret`).
13. **`Java_com_bytedance_osfix_TypeFaceOptimizer_nativeClearUnuseTTF` (`0x017dc0 .. 0x01814f`)**:
    Extracts `.ttf` filenames from the Java `ArrayList` via JNI (`size()I`, `get(I)Ljava/lang/Object;`, `getPath()Ljava/lang/String;`), then invokes `clear_unused_ttf_impl` (`0x017428 .. 0x017b97`) and `get_smaps_pss` (`0x016ba4 .. 0x016fe7`). For each matching `.ttf` region in `/proc/self/maps`, queries `"Pss:"` (`0x3a737350`) in `/proc/self/smaps`, and if `Pss <= 1023 kB` (`0x3ff` at `0x017998`), unmaps the region via `munmap((void*)start_addr, end_addr - start_addr)` (`0x0179ac`).

---

## 3. Reconstructed File Inventory / Danh mục Tệp Mã nguồn Tái cấu trúc
| File | Size (Bytes) | Description |
|---|---:|---|
| `osfix_types.h` | `12,760` | Bionic TLS offsets, 56-byte `BionicPthreadAttr`, `.data`/`.bss` layout |
| `osfix_native_tool_util.h` | `11,637` | Declarations for `NativeToolUtil` JNI entry points & proxies |
| `osfix_native_tool_util.cpp` | `28,707` | Full C++17 implementation of `NativeToolUtil` (`0x005d50..0x0090d0`) |
| `osfix_thread_typeface_optimizer.h` | `8,112` | Declarations for `ThreadStackOptimizer` & `TypeFaceOptimizer` |
| `osfix_thread_typeface_optimizer.cpp` | `18,481` | Full C++17 implementation of `ThreadStackOptimizer` & `TypeFaceOptimizer` |
| `osfix_interface.h` | `444` | Unified public header |
| `osfix_pseudocode.cpp` | `83,681` | Complete standalone C++17 reconstruction, regex/stream engines & self-test |
| **Total Reconstructed C++17** | **`163,822`** | **100% Real Code (`0` stubs)** |
