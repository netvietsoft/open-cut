# Báo Cáo Giải Mã & Tái Cấu Trúc C++17: `libnpth_unw.so` (`TASK-095` / `TASK_SO_083`)

## 1. Thông Số Nhị Phân ELF64 (Binary Geometry)
- **Tệp gốc**: `SOURCE/apktool-res/lib/arm64-v8a/libnpth_unw.so` (`29,336 bytes`, 25 phân vùng ELF64)
- **Số biểu tượng `.dynsym`**: `97` (`73` biểu tượng nhập khẩu `[001]..[073]` từ `libnpth_unwind.so`, `libc.so`, `liblog.so`, `libc++_shared.so`; `23` biểu tượng xuất khẩu `STB_GLOBAL STT_FUNC` `[074]..[096]`)
- **Phân vùng `.text`**: `0x0031b0..0x0060bf` (`12,048 bytes`, `3,012` lệnh AArch64)
- **Phân vùng `.rodata`**: `0x002588..0x0027af` (`552 bytes`, log tag `"npth_unw"`, `"libnpth_unwind.so"`, `"libnpth_unw.so"`, `"exynos9810"`)
- **Phân vùng `.data.rel.ro`**: `0x00a5c0..0x00a5ff` (`64 bytes`, bảng vtable `__shared_ptr_emplace<std::string>` tại `0x00a5c8` với `vptr = 0x00a5d8`: `0x005de0`, `0x005df0`, `0x005e14`, `sym[055]`, `0x005e28`)
- **Phân vùng `.bss`**: `0x00eaa0..0x00eae7` (`72 bytes`: `0x00eaa0` `__aarch64_have_lse_atomics`, `0x00eaa8` `__aarch64_cpu_features`, `0x00eab0` `std::once_flag`, `0x00eab8` `g_local_unwinder`, `0x00eac0` guard, `0x00eac8` `g_empty_string_fallback`, `0x00eae0` guard)

## 2. Cấu Trúc Mã Nguồn Phục Dựng (`137,991 bytes` C++17 & Header, `0 stubs`)
1. [`npth_unw_types.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libnpth_unw/npth_unw_types.h): Toàn bộ hằng số `.rodata`, cờ tùy chọn `NpthUnwOptionFlags`, và cấu trúc ABI (`AArch64RawRegs` `264 B`, `UnwindStackFrameDataAbi` `80 B`, `AndroidUnwinderDataAbi` `160 B`, `NpthUnwContext` `40 B`, `BuildIdRbTreeNode` `56 B`, `SharedStringEmplaceControlBlock` `48 B`).
2. [`npth_unw_elf_tree.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libnpth_unw/npth_unw_elf_tree.h) & [`npth_unw_elf_tree.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libnpth_unw/npth_unw_elf_tree.cpp): Cây Đỏ-Đen 56 byte khử trùng lặp BuildId (`0x0047dc..0x004c78`, lọc `.vdex` & `.jar`) và bộ định dạng khung ngăn xếp 3 chế độ (`0x004198..0x004798`).
3. [`npth_unw_engine.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libnpth_unw/npth_unw_engine.h) & [`npth_unw_engine.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libnpth_unw/npth_unw_engine.cpp): Khởi tạo LSE Atomics & Exynos 9810 workaround (`0x003230`), bộ giải mã tính năng CPU AArch64 (`0x0032c8`), lõi giải mã ngăn xếp (`0x0038cc`), đính kèm `ptrace` (`0x0050e0`), và quét toàn tiến trình `/proc/%d/task` (`0x005198`).
4. [`npth_unw_interface.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libnpth_unw/npth_unw_interface.h), [`npth_unw_interface.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libnpth_unw/npth_unw_interface.cpp) & [`npth_unw_pseudocode.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libnpth_unw/npth_unw_pseudocode.cpp): Toàn bộ 23 hàm C xuất khẩu (`[074]..[096]`) và bảng đối chiếu mã máy AArch64.
