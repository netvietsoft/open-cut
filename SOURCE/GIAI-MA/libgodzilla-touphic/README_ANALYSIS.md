# Deep Binary & Architectural Analysis — `libgodzilla-touphic.so`
# Phân Tích Nhị Phân & Kiến Trúc Chuyên Sâu — `libgodzilla-touphic.so`

- **Target Binary / Nhị phân mục tiêu**: `extracted/lib/arm64-v8a/libgodzilla-touphic.so`
- **Exact File Size / Kích thước chính xác**: `65,304 bytes` (`0xFF18`)
- **Architecture / Kiến trúc**: `ELF64 AArch64` (`EM_AARCH64`, Little-Endian, 26 sections)
- **Task ID**: `TASK-101-RECONSTRUCTION-LIBGODZILLA_TOUPHIC` (`TASK_SO_141_libgodzilla_touphic`)
- **Total Reconstructed C++17 & Header Volume / Tổng dung lượng C++17 & Header tái dựng**: `147,533 bytes` across 8 source/header files (`0 stubs`)

---

## 1. ELF64 Layout & Dynamic Symbol Inventory / Bố Cục ELF64 & Bảng Biểu Tượng Động

| Section | Virtual Address (`sh_addr`) | File Offset (`sh_offset`) | Size (`sh_size`) | Role / Vai trò |
|---|---|---|---|---|
| `.dynsym` | `0x00000270` | `0x000270` | `0x000A80` (`2,688 B`) | 112 dynamic symbols (`[001..084]` imports, `[085..111]` exports) |
| `.rodata` | `0x0000496C` | `0x00496C` | `0x001D78` (`7,544 B`) | Mangled symbol names, CityHash64 & Build-ID tables, API 31..35 `RenderNode` offset arrays |
| `.text` | `0x00007130` | `0x007130` | `0x0093AC` (`37,804 B`) | 14 Godzilla Touphic stability subsystems, `safe_execute` signal engine, tracepoint RB-Tree |
| `.data.rel.ro` | `0x00015FE8` | `0x00DFE8` | `0x0006E8` (`1,768 B`) | Vtables, RTTI descriptors, and relocation tables |
| `.data` | `0x00017500` | `0x00F500` | `0x000210` (`528 B`) | Pre-populated `SignalSlot[4]` table (`SIGABRT=6`, `SIGTRAP=5`, `SIGSEGV=11`, `SIGBUS=7`) & RB-Tree root |
| `.bss` | `0x00017710` | `0x00F710` | `0x000200` (`512 B`) | `pthread_once_t` guards, `sNotifySem`, hook stubs, and `MakeFromTexture` `unordered_map` |

### Exported Dynamic Functions (`.dynsym` `[085..111]` — 27 Functions)
1. `_Z23updateTexImageByteProxyPv` (`0x008528`, `280 B`) — C++ ByteHook proxy for `android::SurfaceTexture::updateTexImage()`
2. `_Z19updateTexImageProxyPv` (`0x008640`, `280 B`) — C++ ShadowHook proxy for `android::SurfaceTexture::updateTexImage()`
3. `Java_com_bytedance_platform_godzilla_touphic_SurfaceUpdateOpt_start` (`0x008758`, `468 B`)
4. `Java_com_bytedance_platform_godzilla_touphic_VisitLocksOpt_start` (`0x0071e8`, `216 B`)
5. `Java_com_bytedance_platform_godzilla_touphic_DirectBufferOpt_start` (`0x0075a0`, `288 B`)
6. `Java_com_bytedance_platform_godzilla_touphic_MaxTextureOpt_start` (`0x0076c4`, `172 B`)
7. `Java_com_bytedance_platform_godzilla_touphic_MakeFromTextureOptS_start` (`0x0082dc`, `584 B`)
8. `Java_com_bytedance_platform_godzilla_touphic_ChromeSupportOpt_start` (`0x0089a0`, `472 B`)
9. `Java_com_bytedance_platform_godzilla_touphic_ChromeSupportOpt_setDamageWebview` (`0x008b78`, `152 B`)
10. `Java_com_bytedance_platform_godzilla_touphic_ChromeSupportOpt_waitForWebviewDamage` (`0x008c10`, `24 B`)
11. `Java_com_bytedance_platform_godzilla_touphic_ChromeSupportOpt_getWebviewDamageCnt` (`0x008c28`, `16 B`)
12. `Java_com_bytedance_platform_godzilla_touphic_JitCompileOpt_start` (`0x009094`, `872 B`)
13. `Java_com_bytedance_platform_godzilla_touphic_FFmpegAvcodecOpt_start` (`0x0093fc`, `316 B`)
14. `Java_com_bytedance_platform_godzilla_touphic_CreateLayerOpt_start` (`0x009538`, `332 B`)
15. `Java_com_bytedance_platform_godzilla_touphic_GLESMaliOpt_start` (`0x009fb0`, `676 B`)
16. `Java_com_bytedance_platform_godzilla_touphic_SafeUffdGCOpt_start` (`0x00a2c4`, `424 B`)
17. `Java_com_bytedance_platform_godzilla_touphic_EglNotInitOpt_start` (`0x00a888`, `468 B`)
18. `Java_com_bytedance_platform_godzilla_touphic_GLESAdrenoOpt_nativeInitDoubleFreeOpt` (`0x00aab8`, `960 B`)
19. `Java_com_bytedance_platform_godzilla_touphic_GLESAdrenoOpt_nativeInitUafOpt` (`0x00ba0c`, `4088 B`)
20. `Java_com_bytedance_platform_godzilla_touphic_WebviewChromiumOpt_start` (`0x00d3f4`, `292 B`)
21. `Java_com_bytedance_sysoptimizer_StackLeakChecker_setStackLeakParams` (`0x00e0bc`, `28 B`)
22. `Java_com_bytedance_sysoptimizer_StackLeakChecker_registerStackLeakListener` (`0x00e0d8`, `768 B`)
23. `Java_com_bytedance_sysoptimizer_NativeBitmap_apply` (`0x00e8ec`, `360 B`)
24. `Java_com_bytedance_sysoptimizer_StageFrightAndroid4Opt_optimize` (`0x00ebd0`, `112 B`)
25. `Java_com_bytedance_sysoptimizer_MediaCodecReleaseOpt_optimize` (`0x00edec`, `88 B`)
26. `Java_com_bytedance_sysoptimizer_JemallocSetting_matching` (`0x00eee8`, `428 B`)
27. `Java_com_bytedance_sysoptimizer_JemallocSetting_purge` (`0x00f094`, `200 B`)

---

## 2. Core Algorithmic & Mathematical Breakdown / Phân Tích Thuật Toán & Toán Học Cốt Lõi

### 2.1. `safe_execute` (`0x00db4c..0x00dc54`) & `signal_handler` (`0x00dd38..0x00df60`)
- **Signal Table Layout (`.data` `0x017620..0x0176b8`)**:
  - 4 contiguous `40-byte` (`0x28`) `SignalSlot` entries for `SIGABRT (6)`, `SIGTRAP (5)`, `SIGSEGV (11)`, and `SIGBUS (7)`.
  - Indexed via `umaddl x8, w8, w9, x10` (`w9 = 0x28` @ `0x00ded0`).
  - Registered once via `pthread_once(0x0178c0, init_signal_handler)` with `sa_flags |= SA_SIGINFO (4)` (`orr w8, w8, #4` @ `0x00dca8`).
- **Per-Thread `TryExecuteTask` (`32 bytes`) & `sigjmp_buf` (`264 bytes = 0x108` @ `0x00db8c`)**:
  - When `safe_execute` runs, it writes `magic = 0x1a2b3c4d` (`mov w8, #0x3c4d; movk w8, #0x1a2b, lsl #16` @ `0x00dbf4..0x00dbfc`) into the thread-local `TryExecuteTask`.
  - On fault, `signal_handler` checks `task->magic == 0x1a2b3c4d` (`0x00ddcc..0x00ddd4`). If matched, it invokes `sig_callback(siginfo)` if non-null; if the callback does not return `0x00112358` (`sub w8, w21, #0x112, lsl #12; cmp w8, #0x358` @ `0x00de2c..0x00de30`), it calls `siglongjmp(*task->jmp_buf, 1)` to recover cleanly without crashing.
  - Otherwise, it restores `old_action` (`sigaction` @ `0x00def8`) and re-raises via `syscall(__NR_tgkill = 240 / 0xf0, getpid(), gettid(), signo)` (`0x00df10..0x00df1c`).

### 2.2. CityHash64 Pointer Hasher (`0x007c58..0x007c74` & `0x008090..0x0080ac`)
- `MakeFromTextureOptS` tracks active `AutoBackendTextureRelease::makeImage` calls in a global `std::unordered_map<void*, bool>` (`0x0175d8..0x0175f8`, `max_load_factor = 1.0f = 0x3f800000`) protected by `pthread_mutex_t` (`0x0175b0`).
- Pointer keys (`8 bytes`) are hashed with CityHash64 (`HashLen0to16` specialized for `len = 8`):
  $$\text{mul} = k_2 + 2 \times 8 = \text{0x9ae16a3b2f90404f} + \text{0x10} = \text{0x9ae16a3b2f90405f}$$
  $$u = \text{ptr} + k_2, \quad v = \text{ ROR}_{37}(\text{ptr}) \times \text{mul} + u$$
  $$d = (\text{ROR}_{25}(u) + \text{ptr}) \times \text{mul}$$
  $$a = (v \oplus d) \times k_{\text{Mul}}, \quad b = ((a \gg 47) \oplus d \oplus a) \times k_{\text{Mul}}$$
  $$h = ((b \gg 47) \oplus b) \times k_{\text{Mul}}, \quad k_{\text{Mul}} = \text{0x9ddfea08eb382d69}$$

### 2.3. `CreateLayerOpt` API 31..35 `RenderNode` Offset Table (`0x009538..0x0098f0`)
- Checks `(max_texture_size & 0x3f) != 0` (`tst w0, #0x3f` @ `0x009564`, `LAYER_SIZE = 64`).
- Uses API-indexed tables at `.rodata` `0x00553c` (`width_offsets = {0x48, 0x48, 0x48, 0x48, 0x40}`) and `0x005550` (`height_offsets = {0x4c, 0x4c, 0x4c, 0x4c, 0x44}`) for `sdk_int` `31..35` (`index = sdk_int - 31`).
- Also intercepts `SkSurface::MakeRenderTarget` (`0x0097f4..0x0098f0`) to clamp `SkImageInfo` dimensions exceeding `sMaxTextureSize`.

### 2.4. `GLESAdrenoOpt` Double-Free Quarantine & UAF Tracepoint Engine (`0x00aab8..0x00d3f0`)
- **Double-Free Quarantine (`0x00aab8..0x00b9bc`)**: Verifies Scudo allocator (`"scudo"` in `/proc/self/maps` without `"GWP-ASan"` = `0x6e6153412d505747ULL` @ `0x00ac14..0x00ac2c`), checks Scudo header `(*(uint32_t*)(ptr - 0x10) >> 12) == target_size` (`0x00aea8..0x00aeb4`), and stores freed chunks in a per-thread quarantine hash table (`max_load_factor = 0.2f = 0x3e4ccccd`) up to `cache_size` entries before releasing the oldest chunk via `orig_free`.
- **UAF Tracepoint Engine (`0x00ba0c..0x00ca04`, `0x00dfe8..0x00e0b8`)**: Installs `BRK` hardware/software instruction tracepoints managed in an intrusive Red-Black Tree (`0x0176c0..0x0176d0`) to validate Adreno command-buffer doubly-linked lists (`[rebuild_list]` @ `0x00d168..0x00d2ac`) and clear dangling UAF pointers (`context + uaf_offset` @ `0x00ca50..0x00ca64`).
