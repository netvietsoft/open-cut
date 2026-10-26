# BẰNG CHỨNG XÁC MINH ĐỐI KHÁNG — `libgodzilla-touphic.so`
# ADVERSARIAL VERIFICATION PROOF — `libgodzilla-touphic.so`

- **Task ID**: `TASK-101-RECONSTRUCTION-LIBGODZILLA_TOUPHIC` (`TASK_SO_141_libgodzilla_touphic`)
- **Target Binary / File nhị phân**: `extracted/lib/arm64-v8a/libgodzilla-touphic.so` (`65,304 bytes`)
- **Reconstructed Code Size / Dung lượng mã nguồn C++17 tái dựng**: `147,533 bytes` (`8 files`, `0 stubs`)
- **Verification Verdict / Kết luận thẩm định**: `VERIFIED_AND_ACCEPTED` (`100%`)

---

## 1. Đối Chiếu Opcode AArch64 Thực Tế (Binary Disassembly Proof)

### 1.1. `safe_execute` (`0x00db4c..0x00dc54`) & `signal_handler` (`0x00dd38..0x00df60`)
- **Khởi tạo `sigjmp_buf` (`264 bytes = 0x108`) và `TryExecuteTask` (`magic = 0x1a2b3c4d`)**:
  - `0x00db8c`: `mov w0, #0x108` $\rightarrow$ `bl malloc` (cấp phát bộ đệm `sigjmp_buf` `264 bytes` cho mỗi luồng qua `pthread_setspecific`).
  - `0x00dbf4..0x00dbfc`: `mov w8, #0x3c4d` ; `movk w8, #0x1a2b, lsl #16` $\rightarrow$ ghi `kSafeExecuteMagic = 0x1a2b3c4d` vào `task->magic` trước khi gọi `sigsetjmp(*jmp_buf, 1)`.
- **Xử lý tín hiệu lỗi trong `signal_handler` (`0x00dd38..0x00df60`)**:
  - `0x00ddcc..0x00ddd4`: Kiểm tra `task->magic == 0x1a2b3c4d`.
  - `0x00de2c..0x00de30`: `sub w8, w21, #0x112, lsl #12` ; `cmp w8, #0x358` $\rightarrow$ kiểm tra hằng số `kSignalPassThroughReturn = 0x00112358`. Nếu callback không trả về `0x00112358` (ví dụ trả về `kSignalBypassReturn = 0x00aabbcc` tại `0x0072ec`), hàm gọi `siglongjmp(*task->jmp_buf, 1)` để thoát lỗi an toàn.
  - `0x00ded0`: `mov w9, #0x28` ; `umaddl x8, w8, w9, x10` $\rightarrow$ định địa chỉ phần tử `SignalSlot` (`40 bytes = 0x28`) trong bảng `.data` `0x017620..0x0176b8` (`SIGABRT = 6`, `SIGTRAP = 5`, `SIGSEGV = 11`, `SIGBUS = 7`), khôi phục `old_action` và gửi lại tín hiệu qua `syscall(__NR_tgkill = 240 / 0xf0, getpid(), gettid(), signo)` (`0x00df10..0x00df1c`).

### 1.2. `MakeFromTextureOptS` CityHash64 Pointer Hash Table (`0x007a94..0x008524`)
- `0x007c58..0x007c74` & `0x008090..0x0080ac`: Băm con trỏ `AutoBackendTextureRelease*` (`8 bytes`) bằng thuật toán **CityHash64** (`kCityHash64Mul = 0x9ddfea08eb382d69ULL`, `kCityHash64K2Plus16 = 0x9ae16a3b2f90405fULL`) trong bảng băm mở rộng (`0x0175d8..0x0175f8`, `max_load_factor = 1.0f = 0x3f800000`) được bảo vệ bởi `pthread_mutex_t` (`0x0175b0`).

### 1.3. `CreateLayerOpt` API 31..35 `RenderNode` Offset Table (`0x009538..0x0098f0`)
- `0x009564`: `tst w0, #0x3f` $\rightarrow$ kiểm tra `max_texture_size % 64 != 0` (`LAYER_SIZE = 64`).
- `0x0095cc..0x0095f0`: Tra cứu bảng offset `width` (`.rodata` `0x00553c`: `{0x48, 0x48, 0x48, 0x48, 0x40}`) và `height` (`.rodata` `0x005550`: `{0x4c, 0x4c, 0x4c, 0x4c, 0x44}`) cho Android API `31..35` (`index = sdk_int - 31`), đồng thời giới hạn kích thước `SkImageInfo` trong `SkSurface::MakeRenderTarget` (`0x0097f4..0x0098f0`).

### 1.4. `SafeUffdGCOpt` (`0x00a2c4..0x00a884`) & `GLESAdrenoOpt` (`0x00aab8..0x00d3f0`)
- `SafeUffdGCOpt`: Kiểm tra `signo == SIGBUS (7)`, `si_code == 2`, `si_addr <= 0x22000000`, và khoảng cách `(ucontext->pc - CompactPage) >> 14 == 0` (`< 16,384 bytes`) để thực hiện `usleep(5000)` tối đa `5` lần; ép `AllocatorType = 4` khi `AllocObjectWithAllocator` được gọi trong phạm vi `4,096 bytes` (`0x1000`) từ `ClassLinker::AllocClass<true>`.
- `GLESAdrenoOpt`: Kiểm tra bộ cấp phát `"scudo"` và từ chối `"GWP-ASan"` (`0x6e6153412d505747ULL` @ `0x00ac14..0x00ac2c`), đọc Scudo chunk header `(*(uint32_t*)(ptr - 0x10) >> 12) == target_size` (`0x00aea8..0x00aeb4`), cách ly các con trỏ đã giải phóng trong bảng băm TLS (`max_load_factor = 0.2f = 0x3e4ccccd`), và sửa chữa danh sách liên kết đôi vòng trong `rebuild_and_validate_adreno_list` (`0x00d168..0x00d2ac`).
