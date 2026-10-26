# Báo Cáo Giải Mã & Tái Dựng Sạch: `libgodzilla-memsponge.so` (Clean-Room Reverse Engineering & C++17 Reconstruction Report)

- **Thư viện mục tiêu (Target Binary)**: `SOURCE/apktool-res/lib/arm64-v8a/libgodzilla-memsponge.so`
- **Dung lượng nhị phân (Binary Size)**: `1,043,056 bytes` (`0.99 MB`)
- **Mã băm SHA-256 (SHA-256 Digest)**: `cc00ce74c83c07821b2d6e80f1a00c8839551e02572c0f39d373ef7ad489a466`
- **Kiến trúc (Architecture)**: `AArch64` (`EM_AARCH64`, Little-Endian, 64-bit ELF Shared Object)
- **Task ID**: `TASK-115-RECONSTRUCTION-LIBGODZILLA_MEMSPONGE` / `TASK_SO_067_libgodzilla_memsponge`
- **Phân loại bằng chứng (Evidence Classification)**: `OBSERVED` (ELF Sections, 26 JNI Exports, `.data` Proxy Tables, AArch64 Disassembly) + `NEW_DESIGN` (Clean-Room C++17 Implementation)

---

## 1. Bố Cục Phân Đoạn ELF / ELF Section Layout (`OBSERVED`)

| Phân đoạn (Section) | Địa chỉ ảo (VMA) | Kích thước (Size) | Ý nghĩa kỹ thuật (Technical Role) |
|---|---|---|---|
| `.rodata` | `0x0242c0 .. 0x0528eb` | `189,995 B` | Chuỗi log (`MemSponge`, `HeapClampOpt`, `StringOpt`, `scudo_vma_leak`), tên symbol C++ mangled của `libart.so` và `libc.so`, bảng nhảy `checkSupportApi` tại `0x04c510`. |
| `.text` | `0x0750d0 .. 0x0f3ae8` | `518,680 B` | Mã máy thực thi AArch64: vùng `0x0750d0..0x07dad4` (`35,332 B`) chứa toàn bộ 5 phân hệ Godzilla MemSponge; vùng `0x07dad4..0x0f3ae8` chứa trình inline hook Dobby/ShadowHook nội bộ và `xdl`. |
| `.data.rel.ro` | `0x0f4cd0 .. 0x0fc538` | `30,824 B` | Bảng hàm ảo và con trỏ hằng sau khi nạp động. |
| `.data` | `0x105b00 .. 0x106120` | `1,568 B` | Chứa bảng 20 mục `ArtProxyMapping` (`0x105ba0..0x106000`, stride `0x38 = 56 B`), `sApiLevel` (`0x106000`), `sMaxHeapRatio` (`0x106004`), `sSoftRefHeapThreshold` (`0x106008`), bảng 2 mục `SoftRefProxyMapping` (`0x106010..0x106060`, stride `0x28 = 40 B`), và `sOriginCapcacity` (`0x106068`). |
| `.bss` | `0x106120 .. 0x108db0` | `11,408 B` | Biến trạng thái thời gian thực: `sMemSpongeDebug` (`0x1062d0`), `sHideLargeObjectMaxBytes` (`0x1062e0`), `sAlreadyHiddenBytes` (`0x1062e8`), `sIsMSpongeOOM` (`0x1062f0`), `sCurrentHeapSize` (`0x1062f8`), `sGlobalTriggerGcValue` (`0x106300`), `sAddGcDiffBytes` (`0x106308`), `sHeap` (`0x106338`), `sScudoMaxBytes` (`0x106398`). |

---

## 2. Danh Sách 26 Hàm Xuất Khẩu JNI / 26 Exported JNI Functions (`OBSERVED`)

### 2.1. Lớp `com.bytedance.platform.godzilla.memopt.MemSpongeHelper` (14 hàm)
1. `Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_stop` (`0x077870`, `36 B`)
2. `Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_debug` (`0x077894`, `20 B`)
3. `Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_setHideLargeObjectMaxBytes` (`0x0778a8`, `80 B`)
4. `Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_start` (`0x0778f8`, `88 B`)
5. `Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_startWhenOOM` (`0x077950`, `132 B`)
6. `Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_setLargeObjThreshold` (`0x077c38`, `1,188 B`)
7. `Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_adjustSoftReference` (`0x078420`, `568 B`)
8. `Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_setCurrentHeapSize` (`0x078658`, `16 B`)
9. `Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_optGCHeapTargetPrint` (`0x0787bc`, `192 B`)
10. `Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_doFixFreeList` (`0x07a49c`, `1,564 B`)
11. `Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_doDamageFreeList` (`0x07aab8`, `4 B`)
12. `Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_doScudoVmaLeak` (`0x07d2fc`, `132 B`)
13. `Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_testScudoVmaLeak` (`0x07d380`, `184 B`)
14. `Java_com_bytedance_platform_godzilla_memopt_MemSpongeHelper_doIgnoreClampGrowLimit` (`0x07d438`, `248 B`)

### 2.2. Lớp `com.bytedance.platform.godzilla.memopt.HeapClampHelper` (10 hàm)
15. `Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_clampGrowthLimit` (`0x078e94`, `232 B`)
16. `Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_artHookInit` (`0x078f7c`, `16 B`)
17. `Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_clearGrowthLimit` (`0x078f8c`, `100 B`)
18. `Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_is64BitRuntime` (`0x078ff0`, `8 B`)
19. `Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_debug` (`0x078ff8`, `20 B`)
20. `Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_printProcessMaps` (`0x07900c`, `1,324 B`)
21. `Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_testVirtualMemOOM` (`0x079a08`, `640 B`)
22. `Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_shouldClampNative` (`0x079c88`, `1,012 B`)
23. `Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_doNoclassDef` (`0x07a20c`, `612 B`)
24. `Java_com_bytedance_platform_godzilla_memopt_HeapClampHelper_testSuspendhung` (`0x07a470`, `44 B`)

### 2.3. Lớp `com.bytedance.platform.godzilla.memopt.StringOptHelper` (2 hàm)
25. `Java_com_bytedance_platform_godzilla_memopt_StringOptHelper_startStringFromString` (`0x07888c`, `112 B`)
26. `Java_com_bytedance_platform_godzilla_memopt_StringOptHelper_debug` (`0x078940`, `20 B`)

---

## 3. Chứng Minh Toán Học & Đối Chiếu Opcode AArch64 / Mathematical & Opcode Proofs (`OBSERVED`)

### 3.1. Công thức giấu bộ nhớ `alignHideLargeObjectBytes` (`0x075ac4`) & `RecordFreeProxy` (`0x075b40`)
- Tại `0x075ac4..0x075b3c`:
  - `0x075b10`: `EB00013F` (`cmp x9, x0`) — So sánh `sHideLargeObjectMaxBytes` (`x9`) với `los_bytes = GetLOSBytesAllocated()` (`x0`).
  - `0x075b14`: `9A803129` (`csel x9, x9, x0, lo`) — `target_hide = min(sHideLargeObjectMaxBytes, los_bytes)`.
  - `0x075b18`: `CB0A026A` (`sub x10, x19, x10`) — `freed_bytes - sAlreadyHiddenBytes`.
  - `0x075b1c`: `8B090140` (`add x0, x10, x9`) — `adjusted_freed = (freed_bytes - sAlreadyHiddenBytes) + target_hide`.
  - `0x075b20`: `F9017509` (`str x9, [x8, #0x2e8]`) — Cập nhật `sAlreadyHiddenBytes = target_hide`.
  - `0x075b24`: `1A9F87EB` (`cset w11, ls`) — `sIsMSpongeOOM = (sHideLargeObjectMaxBytes <= los_bytes)`.
- Khi `RecordFree` trong `libart.so` được gọi, nó thực hiện `num_bytes_allocated_.FetchAndSubSequentiallyConsistent(freed_bytes)`. Việc truyền `adjusted_freed = freed_bytes + (target_hide - sAlreadyHiddenBytes)` làm giảm `num_bytes_allocated_` thêm đúng một lượng bằng `target_hide`, giúp trì hoãn `OutOfMemoryError` trên Java Heap.

### 3.2. Bảng 20 mục `ArtProxyMapping` (`0x105ba0..0x106000`) & Bảng nhảy `checkSupportApi` (`0x077310`)
- Vòng lặp trong `initArtHook` (`0x0773c0`) duyệt `x23` từ `0` đến `0x460` (`1,120 bytes = 20 * 56 bytes`, `cmp x23, #0x460` @ `0x077700`, opcode `0xF11182FF`).
- Trong `checkSupportApi(uint32_t mask, int32_t api_level)` (`0x077310`):
  - `0x077310`: `71005028` (`subs w8, w1, #0x14`) — `idx = api_level - 20`.
  - `0x077314`: `71003D1F` (`cmp w8, #0xf`) — Kiểm tra `idx <= 15` (`api_level` từ `20` đến `35`).
  - Bảng nhảy `.rodata` tại `0x04c510` có 16 mục. Đặc biệt, tại `idx = 12` (`api_level == 32`, Android 12L), mục bảng nhảy trỏ thẳng về `0x0773bc` (`ret` với `w0 = 0`) do mã nguồn gốc của ByteDance bỏ sót `case 32:`! Điều này hoàn toàn khớp với các mặt nạ `0xEFF8` (`0b1110_1111_1111_1000`) và `0xEFFE` (`0b1110_1111_1111_1110`) nơi bit 12 có giá trị `0`.

### 3.3. Dò tìm `large_object_threshold_` bằng `/dev/random` trong `setLargeObjThreshold` (`0x077c38`)
- `IsValidPtr(const void* p, size_t len)` (`0x0779d4`) mở `"/dev/random"` với cờ `O_WRONLY` (`mov w1, #1` @ `0x077a04`) và gọi `write(fd, p, len)`. Kernel Linux tự kiểm tra trang bộ nhớ hợp lệ của con trỏ `p` mà không gây lỗi `SIGSEGV` nếu `p` chưa được ánh xạ.
- Quét `art::gc::Heap` theo bước `8 byte` (`[300, 1200)`) tìm giá trị mặc định `0x3000` (`12,288 B = 3 trang 4KB`, `cmp x8, #3, lsl #12` @ `0x078040`, opcode `0xF1400D1F`) và ghi đè bằng `(int64_t)threshold_pages << 12` (`sbfiz x9, x9, #0xc, #0x20` @ `0x0780ac`, opcode `0x93747D29`).

### 3.4. Chống rò rỉ VMA của bộ cấp phát Scudo (`0x07c290..0x07d37c`)
- Ngưỡng Scudo Secondary VMA:
  - `0x07c434`: `531F7808` (`lsl w8, w0, #1`) — `2 * getpagesize()`.
  - `0x07c438`: `11402908` (`add w8, w8, #0xa, lsl #12`) — `+ 0xA000` (`40,960 B`), tổng cộng `49,152 B` (`48 KB`) trên hệ thống trang `4 KB`.
- Khi Scudo Secondary thực hiện `mmap` cố định (`flags & MAP_FIXED`) với `length <= 0xA000` trên vùng nhớ `"scudo:secondary"`, `scudoMmapProxy` (`0x07cbd8`) thay thế `mmap` bằng `mprotect(addr, length, PROT_READ | PROT_WRITE = 3)` để tránh tách nhỏ VMA trong nhân Linux; và khi giải phóng (`scudoUnmapProxy` @ `0x07cec4`), thay thế `munmap` bằng `madvise(addr, length, MADV_DONTNEED = 4)` và hợp nhất tên vùng nhớ thành `"scudo:secondary_unguard"` qua `scudoPrctlProxy` (`0x07d118`).
