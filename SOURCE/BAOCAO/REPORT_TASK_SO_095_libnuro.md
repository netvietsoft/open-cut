# Clean-Room Reconstruction of `libnuro.so` (Target 112 / 169)
# Tái dựng Sạch `libnuro.so` (Mục tiêu 112 / 169 — `TASK-151` / `TASK_SO_095_libnuro`)

## 1. Binary Forensics & Overview / Pháp y Nhị phân & Tổng quan
- **Library**: `libnuro.so` (`com.lemon.nuro.*` / `nuro::*` Native AI Agent Conversation Hub, ToolCall Execution, Local History Cacher & SyncChannel Engine)
- **File Size**: `953,040 bytes`
- **SHA-256**: `3f62590d84f43083524aa061a54045dc541947328447a446ee253d59b2a160c3`
- **Architecture**: ELF64 AArch64 (`EM_AARCH64`, Little-Endian)
- **Unwind Table (`.eh_frame_hdr` @ `0x0b8c58`)**: `1,835` FDEs (`0x0131b0 .. 0x0acd40`)
- **Dynamic Symbols (`.dynsym` @ `0x001128`)**: `176` exported symbols & `176` imported symbols
- **Static Constructors (`.init_array` @ `0x0e7c60`)**: `117` entries (`936 bytes`)

## 2. Key AArch64 Opcode & Mathematical Proofs / Bằng chứng Opcode AArch64 & Toán học
1. **`nuro::ConversationHub::instance()` (`0x017a64..0x017b48`, `228 bytes`)**:
   - Guard check at `.bss 0x0ec290` (`08DFFD08 ldarb w8, [x8]`, `36000188 tbz w8, #0, #0x17ab8`), allocates `0x90` (`144 bytes`) via `operator new` (`52801200 mov w0, #0x90`, `bl #0x12f40`), sets `max_load_factor_ = 1.0f` (`52A7F009 mov w9, #0x3f800000`, `F9004409 str x9, [x0, #0x88]`), stores `std::shared_ptr<ConversationHub>` at `.bss 0x0ec280` (`A900028A stp x10, x0, [x20]`), and atomically increments reference count via `ldxr/stxr` (`C85F7D09` / `C80A7D09`).
2. **`nuro::FileInfo`, `nuro::ToolCallResult`, `nuro::ToolCall`, and `nuro::ConversationInfo` Struct Layouts**:
   - `FileInfo` (`0x022610..0x0226fc`, `0x70 = 112 bytes`): `file_type` (`+0x00`), `file_id` (`+0x08`), `source_type` (`+0x20`), `uri` (`+0x28`), `url` (`+0x40`), `meta` (`+0x58`).
   - `ToolCallResult` (`0x022ab8..0x022bd0`, `0x78 = 120 bytes`): `call_id` (`+0x00`), `name` (`+0x18`), `result` (`+0x30`), `status` (`+0x48`), `optional<string> err_msg` (`+0x50..+0x68`), `err_code` (`+0x70`).
   - `ToolCall` (`0x0659f0..0x065bd8`, `0x90 = 144 bytes`): `id` (`+0x00`), `type` (`+0x18`), `name` (`+0x30`), `compose_type` (`+0x48`), `optional<vector<string>> patch_list` (`+0x50..+0x68`), `optional<string> arguments` (`+0x70..+0x88`).
   - `ConversationInfo::operator=(ConversationInfo&&)` (`0x073ee0..0x073ffc`, `0x50 = 80 bytes`): Moves 3 SSO strings (`+0x00`, `+0x18`, `+0x30`) and `int64_t create_time` (`+0x48`).
3. **`nuro::SyncChannel::create` (`0x07c7b4..0x07c87c`)**:
   - Allocates `0xa8` (`168 bytes`) via `operator new` (`52801500 mov w0, #0xa8`) for `std::__ndk1::__shared_ptr_emplace<nuro::SyncChannelImpl>`.
