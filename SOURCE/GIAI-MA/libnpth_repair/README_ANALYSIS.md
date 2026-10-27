# Clean-Room Reconstruction of `libnpth_repair.so` (Target 138 / 169)
# Tái Cấu Trúc Sạch Thư Viện `libnpth_repair.so` (Mục tiêu 138 / 169)

## 1. Binary Metadata / Siêu dữ liệu Nhị phân
| Property / Thuộc tính | Value / Giá trị |
|---|---|
| **Library / Thư viện** | `libnpth_repair.so` (ByteDance Npth Native Crash Repair & Signal Registration Monitor) |
| **File Size / Dung lượng** | `27,896 bytes` |
| **SHA-256** | `ddf5f8b8929bd70444c23ac90cc8b5434d7f681755f56d7c14f8300a2393338e` |
| **Architecture / Kiến trúc** | `AArch64` (`ARM64-v8a`, BTI/PAC-enabled) |
| **`.rodata`** | `0x002070..0x0026a8` (`1,592 B`) |
| **`.eh_frame_hdr`** | `0x0026a8..0x0028a4` (`508 B`, `62` FDEs) |
| **`.text`** | `0x0032a0..0x00590c` (`9,836 B`, `2,459` AArch64 instructions) |
| **`.plt`** | `0x005910..0x005d60` (`1,104 B`, `276` AArch64 instructions) |
| **Exported Symbols / Ký hiệu xuất** | `32` (`JNI_OnLoad`, `npth_repair_init`, `fix_art_dump_native_stack`, `fix_scudo_vma_leak`, `start_sig_register_monitor`, ...) |
| **Reconstructed C++17 Size** | `324,842 bytes` across 3 files (`0` stubs) |

## 2. Key Technical Findings / Phát hiện Kỹ thuật Trọng tâm
1. **Android 11..13 `art::DumpNativeStack` Crash Fixer (`0x3a28..0x3dfc`, FDE[26..28])**:
   - Hooks `_ZN3art15DumpNativeStackERNSt3__113basic_ostreamIcNS0_11char_traitsIcEEEEiP12BacktraceMapPKcPNS_9ArtMethodEPvb` in `libart.so` on API 30..33 (`sub w8, w0, #0x22; cmn w8, #4` @ `0x3a58..0x3a60`).
   - Checks `ArtMethod` entry-point at offset `+0x20` (API 30 @ `0x3c48`) or `+0x18` (API $\ge 31$ @ `0x3c64`) against `art_quick_proxy_invoke_handler` and `art_quick_instrumentation_entry`, skipping native stack unwinding when matched.
2. **Android 11+ Scudo `scudo:secondary` VMA Fragmentation Fixer (`0x3e6c..0x415c`, FDE[38..39])**:
   - Hooks `prctl` in `libc.so` via ByteHook when `scudo_mallopt` is present.
   - Intercepts `prctl(PR_SET_VMA = 0x53564d41, 0, addr, size <= 0xa000, "scudo:secondary")` (`0x3fb8..0x3fe4`), remaps surrounding guard pages with `PROT_READ | PROT_WRITE` (`3`) and `MAP_PRIVATE | MAP_FIXED | MAP_ANONYMOUS` (`0x32`), and renames the merged VMA `"scudo:secondary_unguard"`.
3. **Signal Registration Monitor (`0x4178..0x51ec`, FDE[42..55])**:
   - Uses vectorized NEON `cmhi v1.4s, v0.4s, v2.4s; xtn v3.4h, v1.4s` (`0x42ec..0x43d4`) to populate `.bss 0xe590` signal filter table (`sig < 32`), hooks `signal`, `bsd_signal`, `sigaction`, and `sigaction64` across `libc.so` and `libsigchain.so`, and records a 2-slot history per signal (`40 B` `SignalMonitorRecord` @ `0x50e0`) with `xpaclri`-stripped caller return addresses.
