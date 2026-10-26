# BÁO CÁO NGHIỆM THU: REPORT_TASK_SO_141_libgodzilla_touphic

- **Task ID**: `TASK_SO_141_libgodzilla_touphic` (`TASK-101-RECONSTRUCTION-LIBGODZILLA_TOUPHIC`)
- **Thư viện mục tiêu**: `libgodzilla-touphic.so` (`65,304 bytes`)
- **Agent thực hiện**: `Agent 3 / Agent 7 - RECONSTRUCTION` (Verified by `Agent 13 - ADVERSARY AUDITOR`)
- **Trạng thái**: `VERIFIED_AND_ACCEPTED (100%)`

## Bằng chứng kỹ thuật & Toán học:
- **Symbols `.dynsym`**: `112` (`84` imports `[001..084]`, `27` exported functions `[085..111]`: `25` JNI methods + `2` C++ hooks `_Z23updateTexImageByteProxyPv`, `_Z19updateTexImageProxyPv`)
- **Dung lượng mã nguồn C++17 tái dựng**: `147,533 bytes` (`8` file `.h`/`.cpp` trong `SOURCE/GIAI-MA/libgodzilla-touphic/`, `0 stubs`)
- **Cơ chế cốt lõi đã khôi phục chính xác theo AArch64 opcode**:
  1. `safe_execute` (`0x00db4c`) & `signal_handler` (`0x00dd38`): `kSafeExecuteMagic = 0x1a2b3c4d`, `kSignalPassThroughReturn = 0x00112358`, `kSignalBypassReturn = 0x00aabbcc`, `SignalSlot` `40 bytes` (`0x017620..0x0176b8`), `syscall(__NR_tgkill = 240)`.
  2. `MakeFromTextureOptS` (`0x007a94..0x008524`): Bảng băm `unordered_map<void*, bool>` dùng **CityHash64** (`kCityHash64Mul = 0x9ddfea08eb382d69ULL`, `kCityHash64K2Plus16 = 0x9ae16a3b2f90405fULL`).
  3. `CreateLayerOpt` (`0x009538..0x0098f0`): Bảng offset `RenderNode` cho API `31..35` tại `.rodata` `0x00553c` (`{0x48, 0x48, 0x48, 0x48, 0x40}`) và `0x005550` (`{0x4c, 0x4c, 0x4c, 0x4c, 0x44}`).
  4. `SafeUffdGCOpt` (`0x00a2c4..0x00a884`): Xử lý `SIGBUS (7)` (`si_code == 2`, `si_addr <= 0x22000000`) trong phạm vi `16,384 bytes` (`lsr #14 == 0`) của `MarkCompact::CompactPage<false>` với `usleep(5000)` tối đa `5` lần.
  5. `GLESAdrenoOpt` (`0x00aab8..0x00d3f0`): Kiểm tra `"scudo"` & từ chối `"GWP-ASan"` (`0x6e6153412d505747ULL`), đọc Scudo chunk header `(*(uint32_t*)(ptr - 0x10) >> 12) == target_size`, cách ly double-free và sửa chữa danh sách liên kết đôi Adreno (`[rebuild_list]`).
