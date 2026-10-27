# BÁO CÁO GIẢI MÃ & TÁI TẠO C++17: `libnpth_unwind.so` (TARGET 81 / 169)

- **Thư viện mục tiêu (Target Binary)**: `libnpth_unwind.so` (`222,368 bytes`, SHA-256: `c83bb94dbfc0aa4b2d306a0b57ba7bd83c489dc08379cbb7f362c02fd481cad8`)
- **Mã nhiệm vụ (Task ID)**: `TASK-120-RECONSTRUCTION-LIBNPTH-UNWIND` (Legacy: `TASK_SO_073_libnpth_unwind`)
- **Phân loại Lõi C++ (Subsystem)**: `CORE_10_MONITORING` (ByteDance NPTH Custom `libunwindstack` Engine)
- **Tổng số dynamic symbols**: `194` (`79` hàm `STT_FUNC` xuất khẩu tại `.dynsym 0x01419c..0x030354`)
- **Dung lượng C++17 tái tạo sạch (Clean-room C++17 Size)**: `115,208 bytes` trên 9 file `.h`/`.cpp` (`0` stub, `0` TODO)

---

## 1. Kiến trúc Nhị phân & Bố cục Phân đoạn ELF64 (ELF64 Section Layout)

| Phân đoạn (Section) | Địa chỉ ảo (`sh_addr`) | Offset file (`sh_offset`) | Kích thước (`sh_size`) | Vai trò kỹ thuật (Technical Role) |
|---|---:|---:|---:|---|
| `.dynsym` | `0x0002f8` | `0x0002f8` | `0x001248` | Bảng 194 dynamic symbols (`79` hàm xuất khẩu `unwindstack::*`) |
| `.rodata` | `0x007200` | `0x007200` | `0x000ce8` | Chuỗi định dạng khung, tên 34 thanh ghi, hằng SHA-256 (`0x0077b0`, `0x0078c4`), magic XZ (`0x0079c4`) và bảng DWARF CFA/OP (`0x0079ca..0x007ee8`) |
| `.eh_frame_hdr` | `0x007ee8` | `0x007ee8` | `0x001084` | Bảng tra nhị phân DWARF Call Frame Header |
| `.eh_frame` | `0x008f70` | `0x008f70` | `0x003de4` | Bản ghi CIE/FDE gỡ ngăn xếp AArch64 |
| `.text` | `0x00cd60` | `0x00cd60` | `0x026cfc` | Mã máy thực thi AArch64 (`158,972 bytes`) |
| `.data.rel.ro` | `0x038120` | `0x034120` | `0x0015b0` | Bảng vtable (`RegsArm64` tại `0x039510`, `BufferMaps` tại `0x0390a8`) & bảng 15 mã lỗi `ErrorCode` tại `0x038420` |
| `.init_array` | `0x0396e0` | `0x0356e0` | `0x000020` | 4 hàm khởi tạo tĩnh (`0x00cde0`, `0x00e684`, `0x00e6b8`, `0x00e708`) |
| `.data` | `0x03dc78` | `0x035c78` | `0x000004` | Biến toàn cục `g_api_level` khởi tạo bằng `0xFFFFFFFF` (`-1`) |
| `.bss` | `0x03dc80` | `0x035c7c` | `0x0041a8` | Cờ lỗi Exynos 9810 (`0x03dc80`), bộ nhớ đệm ELF (`0x041d18..0x041d50`) và `g_dex_cached_size` (`0x041d28`) |

---

## 2. Đối soát Opcode AArch64 & Bố cục Struct ABI

1. **`AndroidUnwinderData` (`0x40 = 64 bytes`, `0x01419c..0x014428`)**:
   - `+0x00..0x17`: `std::vector<FrameData> frames` (mỗi phần tử `FrameData` rộng `0x48 = 72 bytes`, `function_name` tại `+0x28`, `function_offset` tại `+0x38`, `map_info` tại `+0x40`).
   - `+0x18`: `ErrorCode error.code` (`ldrsb x9, [x0, #0x18]` tại `0x014370`, tra bảng 15 chuỗi tại `.data.rel.ro 0x038420`).
   - `+0x20`: `uint64_t error.address` (`ldr x1, [x20, #0x20]` tại `0x014390`, nối thêm `" at address 0x%lx"` tại `.rodata 0x007278`).
   - `+0x38`: `DexPositionInfoContext* dex_context` (`ldr x0, [x0, #0x38]; ret` tại `0x0143f0`).
2. **`AndroidUnwinder::Impl` (`0x48 = 72 bytes`, cấp phát tại `0x015610: mov w0, #0x48`)**:
   - `+0x00`: `int pid` (`str w22, [x21]`).
   - `+0x08`: `uint64_t max_frames` (`str xzr, [x21, #8]`).
   - `+0x10`: `bool initialized` (`strb wzr, [x21, #0x10]`).
   - `+0x11`: `bool is_local_mode` (`strb w8, [x21, #0x11]`, đọc bởi `IsLocalMode()` tại `0x015c0c`).
   - `+0x18`: `Maps* maps` (`ldr x0, [x8, #0x18]` tại `0x015c00`).
   - `+0x20`: `std::unique_ptr<Maps> maps_guard`.
   - `+0x28..0x37`: `std::shared_ptr<Memory> process_memory` (`add x0, x8, #0x28` tại `0x015bf4`).
   - `+0x38`: `std::unique_ptr<JitDebug> jit_debug` (`ldr x0, [x8, #0x38]` tại `0x015c18`).
   - `+0x40`: `std::unique_ptr<DexFiles> dex_files` (`ldr x0, [x8, #0x40]` tại `0x015c34`).
3. **`RegsArm64` (`0x58 = 88 bytes`, cấp phát tại `0x03056c`, `0x030634`, `0x0306ac`)**:
   - `+0x08`: `uint16_t total_regs_ = 0x22` (`34`, `mov w8, #0x22; strh w8, [x0, #8]`).
   - `+0x0A`: `uint16_t last_regs_ = 1`, `+0x0C`: `uint16_t return_address_reg_ = 0x1E` (`30 = REG_ARM64_LR`).
   - `+0x0E`: `bool vregs_enabled_` (bật lên `1` trong `enable_vregs()` tại `0x0304fc`, cấp phát `8 * 8 = 64 bytes` cho `d8..d15`).
   - `+0x18..0x2F`: `std::vector<uint64_t> regs_` (`0x110 = 272 bytes`, `sp` tại `[31]`/`+0xF8`, `pc` tại `[32]`/`+0x100`, `pst` tại `[33]`/`+0x108`).
   - Trong `CreateFromUcontext` (`0x030668`): sao chép `0x110` bytes từ `(const uint8_t*)ucontext + 0xB8`.
   - Trong `RemoteGet` (`0x030550`): gọi `ptrace(PTRACE_GETREGSET = 0x4204, pid, NT_PRSTATUS = 1, &iov)`, trả lỗi `ERROR_PTRACE_CALL = 0x0E` nếu thất bại.
4. **`ElfGetRelPc` (`0x0272e0`) & `ElfGetVariableOffset` (`0x027314`)**:
   - `ElfGetRelPc`: $\text{rel\_pc} = (\text{pc} - \text{map\_info}\to\text{start}) + \text{elf}\to\text{load\_bias} + \text{map\_info}\to\text{GetElfFields}().\text{elf\_offset}$.
   - `ElfGetVariableOffset`: mặt nạ hóa byte cao nhất ARM64 TBI/MTE bằng `and x8, x8, #0xffffffffffffff` (`0x00FFFFFFFFFFFFFFULL`) tại `0x027364`.
