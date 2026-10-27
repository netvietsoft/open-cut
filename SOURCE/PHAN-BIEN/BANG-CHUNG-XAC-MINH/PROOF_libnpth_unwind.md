# BẰNG CHỨNG XÁC MINH ĐỐI KHÁNG — PROOF FOR: `libnpth_unwind.so`

- **Thư viện**: `libnpth_unwind.so` (`222,368 bytes`, SHA-256: `c83bb94dbfc0aa4b2d306a0b57ba7bd83c489dc08379cbb7f362c02fd481cad8`)
- **Task ID**: `TASK-120-RECONSTRUCTION-LIBNPTH-UNWIND` (Legacy: `TASK_SO_073_libnpth_unwind`)
- **Dung lượng C++17 tái tạo sạch**: `115,208 bytes` (9 file `.h`/`.cpp`, `0` stub)

## 1. Bằng chứng Opcode AArch64 & Bảng Dữ Liệu Nhị Phân
1. **Bảng 15 mã lỗi `ErrorCode` tại `.data.rel.ro 0x038420..0x038490` (file offset `0x034420..0x034490`)**:
   - Được truy xuất tại `AndroidUnwinderData::GetErrorString()` (`0x014364..0x0143ec`) bằng `ldrsb x9, [x0, #0x18]; adrp x10, #0x38000; add x10, x10, #0x420; ldr x1, [x10, x9, lsl #3]`, từ `ERROR_NONE = 0` (`0x00738b`: `"None"`) đến `ERROR_PTRACE_CALL = 14` (`0x0076b1`: `"Ptrace Call Failed"`).
2. **Hằng số SHA-256 (`0x0077b0` & `0x0078c4`) và Magic XZ (`0x0079c4`) trong `.rodata`**:
   - 8 từ trạng thái khởi tạo SHA-256 $H_0^{(0)}\dots H_7^{(0)}$ tại `0x0077b0..0x0077d0` (`0x6a09e667`, `0xbb67ae85`, ...), 64 hằng số vòng $K_0\dots K_{63}$ tại `0x0078c4..0x0079c4` (`0x428a2f98`, `0x71374491`, ..., `0xc67178f2`) và 6 byte magic tiêu đề XZ `fd 37 7a 58 5a 00` tại `0x0079c4` phục vụ giải nén `.gnu_debugdata`.
3. **Cấu trúc `RegsArm64` (`0x58 = 88 B`) & `Registers` (`0x02f8f8..0x030750`)**:
   - `Registers::pc()` (`0x02f974`): đọc `+0x100` (`REG_ARM64_PC = 32`); `Registers::sp()` (`0x02f990`): đọc `+0xF8` (`REG_ARM64_SP = 31`).
   - `RegsArm64::RemoteGet` (`0x030518`): cấp phát `0x110` (`272`) byte, gọi `ptrace(PTRACE_GETREGSET = 0x4204, pid, NT_PRSTATUS = 1, &iov)`, khởi tạo `total_regs_ = 0x22` (`34`) tại `+0x08` và `return_address_reg_ = 0x1E` (`30`) tại `+0x0C`.
   - `RegsArm64::CreateFromUcontext` (`0x030628`): sao chép `0x110` byte từ `(uint8_t*)ucontext + 0xB8`.
4. **Tính toán `ElfGetRelPc` (`0x0272e0`) & Mặt nạ TBI `ElfGetVariableOffset` (`0x027314`)**:
   - `ElfGetRelPc`: `(pc - map_info->start_) + elf->load_bias_ + map_info->GetElfFields().elf_offset`.
   - `ElfGetVariableOffset`: xóa byte tag cao nhất của con trỏ ARM64 TBI/MTE bằng `and x8, x8, #0xffffffffffffff` (`0x00FFFFFFFFFFFFFFULL`) tại `0x027364`.
