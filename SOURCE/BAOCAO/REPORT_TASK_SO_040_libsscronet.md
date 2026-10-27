# BẰNG CHỨNG XÁC MINH ĐỐI KHÁNG — PROOF FOR: `libsscronet.so`

- **Task ID**: `TASK-161-RECONSTRUCTION-LIBSSCRONET` (`TASK_SO_040_libsscronet`) — Target 122 / 169
- **Dung lượng nhị phân**: `5,973,416 bytes` | **SHA-256**: `2005c6574bf4c56204365be7f9cca38981e6bffb8bbd2eab03f2abb1a6b052c6`
- **Bảng `.eh_frame_hdr`**: `0x0f1dd8` (`19,032` FDEs) | **Bảng `.dynsym` (`0x000388`)**: `1,225` biểu tượng xuất
- **Dung lượng C++17 tái dựng**: `2,421,027 bytes` (9 files `.h`/`.cpp`, `0` stubs)

## 1. Bằng Chứng Disassembly AArch64 Trực Tiếp
- `0x1c74a8` (`JNI_OnLoad`): `D503233F` (`paciasp`), `0x1c74ac: D101C3FF` (`sub sp, sp, #0x70`), `0x1c74cc: 08DFFD08` (`ldarb w8, [x8]` tại `.bss` `0x5df620`), `0x1c74d4: B9491A80` (`ldr w0, [x20, #0x918]`), `0x1c7540: F903C913` (`str x19, [x8, #0x790]`).
- `0x1c9738` (6 hàm `Cronet_*_Destroy` POD): `D503245F` (`bti c`), `14044B9E` (`b #0x2dc5b4`).
- `0x1ea6f4` (25 hàm `*_Destroy` có kiểm tra null): `D503245F` (`bti c`), `B4000040` (`cbz x0, #0x1ea700`), `1403C7AE` (`b #0x2dc5b4`), `D65F03C0` (`ret`).
- `0x1fac70` (38 hàm `*_SetClientContext`): `D503245F` (`bti c`), `F9000401` (`str x1, [x0, #8]`), `D65F03C0` (`ret`).
- 6 hàm khởi tạo QUIC / HTTP3 / Cronet:
  - `Cronet_Throttle_Create` (`0x267f10`): `mov w0, #0x88` (`136 B` @ `0x267f20`).
  - `Q_Eng_Create` (`0x279dd0`): `mov w0, #0x1c0` (`448 B` @ `0x279de0`), `max_streams = 0x100` (`256` @ `0x279e30`), `idle_timeout_ms = 0x1f4` (`500` @ `0x279e88`), trả về `x19 + 0x10` (`str x9, [x20, #0x10]!` @ `0x279e1c`).
  - `Q_Conn_Create` (`0x27caf4`): `mov w0, #0x168` (`360 B` @ `0x27cb04`), `socket_fd = -1` tại `+0x80` (`0x27cb40`).
  - `Q_Stream_Create` (`0x27f834`): `mov w0, #0xb60` (`2,912 B` @ `0x27f844`), `stream_flags = 0x101` tại `+0xe0` (`0x27f898`).
  - `TTQuicHe_Engine_Create` (`0x28a96c`): `mov w0, #0x98` (`152 B` @ `0x28a97c`).
  - `TTQuicHe_HttpRequest_Create` (`0x28a9f8`): `mov w0, #0xee8` (`3,816 B` @ `0x28aa08`).

## 2. Chứng Minh Toán Học & Bố Cục Struct ABI
1. **Định lý dịch chuyển con trỏ đa kế thừa `Q_Eng_Create` (`0x279de0..0x279ea4`) & `Q_Eng_SetClientContext` (`0x1fac70`)**:
   - `Q_Eng_Create` cấp phát khối `0x1c0` (`448 B`) tại `x19`, khởi tạo `[x19 + 0x00] = vptr_outer`, `[x19 + 0x10] = vptr_qeng`, `[x19 + 0x18] = 0` (`stp xzr, x10, [x19, #0x18]` @ `0x279e20`), và trả về `x20 = x19 + 0x10` (`str x9, [x20, #0x10]!` @ `0x279e1c`).
   - Khi người dùng gọi `Q_Eng_SetClientContext(q_eng, ctx)` (`0x1fac70`: `str x1, [x0, #8]`), `x0 = x20 = x19 + 0x10`, do đó `ctx` được ghi vào `[x20 + 0x08] == [x19 + 0x18]` — khớp tuyệt đối với trường `xzr` được khởi tạo tại `[x19 + 0x18]` ở lệnh `0x279e20`!
