# Clean-Room Reconstruction Analysis: `libnpth_vm_monitor.so`
# Phân Tích Tái Tạo Phòng Sạch: `libnpth_vm_monitor.so`

## 1. Binary Identity / Định Danh Nhị Phân
- **File**: `libnpth_vm_monitor.so`
- **Task ID**: `TASK-191-RECONSTRUCTION-LIBNPTH-VM-MONITOR` (`TASK_SO_079_libnpth_vm_monitor`)
- **Size**: `55,968` bytes
- **SHA-256**: `877db3380e7c313c441509651dd39a8d1d26643d35dc3c513e59e6680e8331cc`
- **Architecture**: `AArch64 (EM_AARCH64, 64-bit LSB shared object)`
- **SONAME**: `libnpth_vm_monitor.so`
- **Dependencies (`DT_NEEDED`)**: `libc++.so`, `libdl.so`, `liblog.so`, `libm.so`, `libc.so`

## 2. Exact ELF Layout & `.eh_frame_hdr` FDE Table / Bố Cục ELF & Bảng FDE
- `.rodata`: `0x2828` (`2,892` bytes) — `/proc/self/maps`, `/proc/self/status`, `/proc/self/smaps_rollup`, `mprotect(addr,len,prot)` & `mmap`/`munmap`/`mremap` format strings
- `.eh_frame_hdr`: `0x3374` (`708` bytes, `87` sorted FDE entries)
- `.eh_frame`: `0x3638` (`4,248` bytes)
- `.text`: `0x4744 .. 0xc518` (`32,212` bytes = `8,053` AArch64 instructions)
- `.plt`: `0xc520` (`1,136` bytes)
- `.data`: `vaddr=0x15290` (`off=0xd290`, `24` bytes — `vm_monitor_native_interface_func` table)
- `.bss`: `vaddr=0x152a8` (`192` bytes — mutexes, arena pointers, hook tables, counters)

## 3. Architecture & Mathematical Formulation / Kiến Trúc & Công Thức Toán Học
1. **Virtual Memory Region Interval Tracking (`insert_mmap_info` @ `0x7b0c`, `delete_mmap_info` @ `0x7e10`, `change_mmap_info` @ `0x7850`, `insert_mprotect_info` @ `0x51e8`)**:
   - Tracks intervals $[a_i, a_i + L_i)$ in the process virtual address space with page-rounding:
     $$L_{\text{aligned}} = (L + 4095) \,\&\, \sim 4095$$
   - Handles partial/complete unmaps and protection updates (`PROT_READ | PROT_WRITE | PROT_EXEC`) by splitting, trimming, or removing overlapping intervals.
2. **Syscall/GOT Hook Dispatch (`tools_mmap_do_hook` @ `0x878c`, `so_initialize` @ `0x4794`, `npth_vm_monitor_execute_command` @ `0x4be0`)**:
   - Installs hooks on `mmap`/`mmap64`/`munmap`/`mremap`/`mprotect` across loaded libraries and records backtraces (`max_depth <= 64`) into arena pools (`npth_mmap_alloc_space` @ `0x59cc`, `clear_mem_arenas` @ `0x6030`).
3. **VM Leak Classification & `/proc/self/maps` Dump (`dump_native` @ `0x5058`, `dump_mmap_info` @ `0x93b0`, `vm_leak_reason` @ `0xb8b0`, `mm_get_physical_memory_info` @ `0xc350`)**:
   - Classifies virtual memory regions against high-watermarks and exports human-readable reports and `smaps_rollup` physical RSS/PSS statistics.
