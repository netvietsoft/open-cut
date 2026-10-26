# Technical Analysis & Clean-Room C++17 Reconstruction — `libgodzilla-acurate-asan.so`
# Phân Tích Kỹ Thuật & Tái Tạo C++17 Phòng Sạch — `libgodzilla-acurate-asan.so`

## 1. Binary Identity / Định Danh Nhị Phân
- **Library Name**: `libgodzilla-acurate-asan.so`
- **Task ID**: `TASK-114-RECONSTRUCTION-LIBGODZILLA_ACURATE_ASAN` (`TASK_SO_128_libgodzilla_acurate_asan`)
- **File Size**: `160,168 bytes` (`0x271A8`)
- **SHA-256**: `0c89ab013365273e0d1b626303f8948a1dbf72bf1d77ce5f2ec36b181b769a0c`
- **Architecture**: `AArch64 (ARM64-v8a)`, Little-Endian, Android Bionic ABI
- **Dependencies (`DT_NEEDED`)**: `liblog.so`, `libshadowhook.so`, `libbytehook.so`, `libxdl.so`, `libm.so`, `libdl.so`, `libc.so`

---

## 2. ELF Section Layout / Bố Cục Phân Đoạn ELF

| Section | Virtual Address | File Offset | Size (Bytes) | Description (EN / VN) |
|---|---|---|---|---|
| `.rodata` | `0x006a60` | `0x006a60` | `10,964` (`0x2ad4`) | Format strings, GWP-ASan templates, JSON keys, ART mangled names / Chuỗi định dạng, mẫu GWP-ASan, khóa JSON, ký hiệu ART |
| `.text` | `0x00dc70` | `0x00dc70` | `95,980` (`0x176ec`) | `23,995` AArch64 instructions (`0x00dc70..0x021650` application + `0x021650..0x02535c` unwind runtime) |
| `.plt` | `0x025360` | `0x025360` | `2,592` (`0x0a20`) | `160` PLT stubs (`mmap`, `mprotect`, `prctl`, `shadowhook_*`, `bytehook_*`, `xdl_*`) |
| `.data.rel.ro` | `0x029d80` | `0x025d80` | `824` (`0x0338`) | Error string pointer table (`0x02a0d8..0x02a108`), GOT pointers (`0x02a3b0 -> 0x05ea48`) |
| `.fini_array` | `0x02a0b8` | `0x0260b8` | `16` (`0x0010`) | `[0] = 0x00dc88`, `[1] = 0x00dc70` |
| `.init_array` | `0x02a0c8` | `0x0260c8` | `16` (`0x0010`) | `[0] = 0x021160` (`__init_cpu_features_resolver`), `[1] = 0x021630` |
| `.data` | `0x02e8d0` | `0x0268d0` | `72` (`0x0048`) | Initialized PRNG seed, FDs (`-1`), TLS keys (`0x7a8b9cde`, `0x7a8b9cef`), RefDebug counters |
| `.bss` | `0x02e918` | `0x026918` | `199,072` (`0x309a0`) | `SingletonPtr`, BuildId caches (`192 KB`), `sigaction`, hook contexts, `RefDebugState` |

---

## 3. Exported Symbols in `.dynsym` (10 Exports) / 10 Biểu Tượng Xuất `.dynsym`

| # | Symbol Name | Virtual Address | Size | Role (EN / VN) |
|---|---|---|---|---|
| 1 | `Java_com_bytedance_platform_godzilla_gwpasan_GodzillaAcurateAsan_initAcurateAsan` | `0x00dcc0` | `1572 B` | Initializes `GuardedPoolAllocator` (`0xe8` B), SIGSEGV crash handler, custom ShadowHook/ByteHook allocator hooks, and optional ART JIT disabler / Khởi tạo GWP-ASan, trình xử lý SIGSEGV và các hook cấp phát |
| 2 | `_ZN8gwp_asan20GuardedPoolAllocator13trapOnAddressEm5Error` | `0x011a0c` | `20 B` | Stores `Error` at `+0x48`, `Address` at `+0x50`, and writes `0` to `*[this + 0x28]` (`CrashTriggerSortingPage`) to trigger deterministic SIGSEGV / Ghi mã lỗi và kích hoạt bẫy trang bảo vệ |
| 3 | `Java_com_bytedance_platform_godzilla_gwpasan_GodzillaAcurateAsan_initProxyFaultHandler` | `0x01ed68` | `784 B` | Checks `/proc/self/maps` for `"scudo"`, resolves target symbols via `xdl_open`/`xdl_sym`, and patches first instruction to `ret` (`0xd65f03c0`) / Vá hàm xử lý lỗi Scudo bằng lệnh `ret` (`0xd65f03c0`) |
| 4 | `Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_nativeRefrecordInit` | `0x01ff1c` | `4 B` | Tail-branches (`b #0x20190`) to allocate `RefDebugState` (`24` B) and hook ART `NewGlobalRef`/`AddGlobalRef`/`DeleteGlobalRef` / Khởi tạo GodzillaRefDebug |
| 5 | `Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_nativeRefrecordDumpLatest` | `0x01ff20` | `12 B` | Swaps JNI arguments and jumps to `0x020694` to dump bucket records and latest `max_count` GlobalRef records / Kết xuất các bản ghi GlobalRef mới nhất |
| 6 | `Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_nativeRefrecordConfig` | `0x01ff2c` | `16 B` | Configures `g_ref_bundle_size` (`1..10000`), `g_ref_local_size` (`1..128`), and `g_ref_hook_add_global_ref` (`0x0208e0`) / Cấu hình kích thước bộ đệm vòng RefDebug |
| 7 | `Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_nativeSetRefdebugDebuglog` | `0x01ff3c` | `28 B` | Sets `g_refdebug_debuglog` (`0x05ea48` via GOT `0x02a3b0`) / Bật/tắt nhật ký gỡ lỗi RefDebug |
| 8 | `Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_testcase1` | `0x01ff58` | `124 B` | Calls `env->NewGlobalRef(obj)` and `env->DeleteGlobalRef(ref)` for self-test / Kịch bản kiểm thử 1 |
| 9 | `Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_testcase2_11` | `0x01ffd4` | `308 B` | Allocates `RefTestArray` (`16` B) and `count` GlobalRefs / Kịch bản kiểm thử 2.1 |
| 10 | `Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_testcase2_12` | `0x020108` | `124 B` | Deletes `count` GlobalRefs in `RefTestArray` and frees buffers / Kịch bản kiểm thử 2.2 |

---

## 4. Exact `.data` (`0x02e8d0..0x02e918`) & `.bss` (`0x02e918..0x05f2b8`) Map

| Address | Section | Type | Initial Value | Symbol / Purpose (EN / VN) |
|---|---|---|---|---|
| `0x02e8d8` | `.data` | `uint32_t` | `0` | `g_prng_state` (Xorshift32 state initialized at `0x011404`) |
| `0x02e8dc` | `.data` | `int32_t` | `-1` (`0xffffffff`) | `g_tombstone_fd` (`<dump_dir>/tombstone.txt` file descriptor) |
| `0x02e8e0` | `.data` | `int32_t` | `-1` (`0xffffffff`) | `g_glog_fd` (`<dump_dir>/glog.txt` file descriptor) |
| `0x02e8e4` | `.data` | `pthread_key_t` | `-1` (`0xffffffff`) | `g_signal_reentrancy_key` (SIGSEGV nested crash guard) |
| `0x02e8e8` | `.data` | `pthread_key_t` | `0x7a8b9cde` | `g_custom_hook_tls_key` (Custom hook recursion TLS key) |
| `0x02e8ec` | `.data` | `pthread_key_t` | `0x7a8b9cef` | `g_dwarf_unwind_tls_key` (Stores `0xdeadbeef` during DWARF unwind) |
| `0x02e8f0` | `.data` | `uint32_t` | `1` | `g_ref_alloc_seq` (Monotonic GlobalRef allocation sequence ID) |
| `0x02e8f4` | `.data` | `uint32_t` | `1` | `g_ref_free_seq` (Monotonic GlobalRef deallocation sequence ID) |
| `0x02e8f8` | `.data` | `uint32_t` | `512` (`0x200`) | `g_ref_bundle_size` (Default number of hash buckets in `GodzillaRefDebug`) |
| `0x02e8fc` | `.data` | `uint32_t` | `8` (`0x08`) | `g_ref_local_size` (Default ring-buffer depth per bucket in `GodzillaRefDebug`) |
| `0x02e920` | `.bss` | `GuardedPoolAllocator*` | `nullptr` | `g_mmap_alloc` (`232-byte` instance allocated via `mmap` at `0x00dff4`) |
| `0x02e928` | `.bss` | `GuardedPoolAllocator*` | `nullptr` | `SingletonPtr` (Used by `pthread_atfork` handlers at `0x011cc8`) |
| `0x02e930` | `.bss` | `char[512][128]` | `0` | `g_build_id_map_values` (`65,536 B` hex `NT_GNU_BUILD_ID` strings) |
| `0x03e930` | `.bss` | `char[512][256]` | `0` | `g_build_id_map_keys` (`131,072 B` shared library paths from `dl_iterate_phdr`) |
| `0x05e930` | `.bss` | `uint32_t` | `0` | `g_build_id_map_count` (Number of cached ELF BuildIds, max 512) |
| `0x05e938` | `.bss` | `struct sigaction` | `0` | `g_previous_sigsegv_action` (`32 B` chained handler) |
| `0x05e9f8` | `.bss` | `RefHookContext` | `0` | `g_ref_hook_ctx` (`80 B`: 5 ShadowHook stubs + 5 original ART JNI pointers) |
| `0x05ea48` | `.bss` | `bool` | `false` | `g_refdebug_debuglog` (Referenced via `.data.rel.ro` `0x02a3b0`) |
| `0x05ea58` | `.bss` | `RefDebugState*` | `nullptr` | `g_ref_debug_state` (`24-byte` state allocated at `0x020198`) |
