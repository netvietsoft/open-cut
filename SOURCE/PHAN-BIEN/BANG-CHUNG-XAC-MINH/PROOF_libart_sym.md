# BẰNG CHỨNG XÁC MINH ĐỐI KHÁNG: `libart_sym.so` (Target 72 / 169)
# ADVERSARIAL VERIFICATION PROOF: `libart_sym.so`

- **Task ID**: `TASK_SO_131_libart_sym` / `TASK-111-RECONSTRUCTION-LIBART_SYM`
- **SHA-256**: `cb71702453fff0d212d2b7f20aac4c905fdc3e13333538bc0c305b1ad36532e8` (`124,720 bytes`)
- **Trả lời thách thức / Response to Challenge**: `SOURCE/PHAN-BIEN/YEU-CAU-CHUNG-MINH/CHALLENGE_libart_sym.json`
- **Tổng dung lượng C++17 tái dựng**: `249,155 bytes` (`art_sym_pseudocode.cpp` = `95,864 bytes`, `0 stubs`)

---

## 1. Bằng Chứng Mã Nguồn Thực Chất (`REQ_1_REAL_CODE`)
Toàn bộ 6 phân hệ của `libart_sym.so` (`.text 0x013340..0x01c10c`) đã được tái dựng 100% bằng C++17 clean-room không có bất kỳ hàm rỗng (stub) nào:
1. `SOURCE/GIAI-MA/libart_sym/art_sym_types.h` (`21,428 bytes`)
2. `SOURCE/GIAI-MA/libart_sym/art_method_field_modifier.h` (`13,471 bytes`)
3. `SOURCE/GIAI-MA/libart_sym/art_method_field_modifier.cpp` (`32,637 bytes`)
4. `SOURCE/GIAI-MA/libart_sym/art_runtime_heap_jit.h` (`19,544 bytes`)
5. `SOURCE/GIAI-MA/libart_sym/art_runtime_heap_jit.cpp` (`32,113 bytes`)
6. `SOURCE/GIAI-MA/libart_sym/art_thread_scoped_hook.h` (`9,105 bytes`)
7. `SOURCE/GIAI-MA/libart_sym/art_thread_scoped_hook.cpp` (`23,084 bytes`)
8. `SOURCE/GIAI-MA/libart_sym/art_sym_interface.h` (`1,909 bytes`)
9. `SOURCE/GIAI-MA/libart_sym/art_sym_pseudocode.cpp` (`95,864 bytes`)

---

## 2. Bằng Chứng Opcode Nhị Phân AArch64 (`REQ_2_OPCODE_EVIDENCE`)
| Địa chỉ ảo / VAddr | Mã máy AArch64 / Instruction | Ánh xạ C++17 / C++17 Mapping |
|---|---|---|
| `0x013390..0x013570` | `adrp x8, 0x25000; ldrb w8, [x8, #0xf10]; bl std::mutex::lock` | `art::ArtMethod::Init`: Khóa hai lớp trên `has_init_` (`0x025f10`), đăng ký `DoOnFinally` (`0x013a74`), phân giải `art_quick_generic_jni_trampoline` và dò `entry_point_index_` (`0x025ef8`) qua 4 chiến lược. |
| `0x014754..0x0148f4` | `and w8, w9, #0xfffffffc; orr w9, w8, #0x1; tst w9, #0x800500; orr w9, w9, #0x80000` | `ArtMethodModifier`: Chuyển cờ thành `public` (`(f & ~3) \| 1`) và `kAccPreverified` (`f \| 0x80000`). |
| `0x014e8c..0x015018` | `add w20, w8, #1; ldr w8, [x19, x20, lsl #2]; and w9, w8, #0xffffffec; orr w9, w9, #0x1` | `ArtFieldModifier::changeAccessFlagToPublic`: Ghi đè cờ truy cập tại `declaringClassIndex + 1` bằng `(f & 0xffffffec) \| 0x1`. |
| `0x0154a4..0x0157b4` | `mov w1, #1; bl __open_2; bl write; mov w8, #0x5678; movk w8, #0x1234, lsl #16; lsl w8, w8, #1` | `IsValidPtr` ghi thử vào `"/dev/random"` (`O_WRONLY`); `DetectObjectSize` dùng canary 2 lượt (`0x12345678`, `0x2468acf0`) trên 256 từ 32-bit. |
| `0x016194..0x019558` | `mov w8, #3; mul w9, w0, w8; lsl x8, x8, #20; cmp w8, #0x2720; cmp w8, #0x2800; sub w8, w8, #4` | `Heap::Init` tìm `3 * getpagesize()` & `heapsize << 20`; `ArtRuntime::Init` tìm `_ZTVN3art11ClassLinkerE + 0x10`, suy ra `thread_list_index_ = class_linker_index_ - 4`, và kiểm tra ngưỡng `JitOptions` (`0x2720`, `0x2800`, `0xffff`). |
| `0x01a4ec..0x01c10c` | `mov w1, #0x4000; bl calloc; mov w1, #0x614e; movk w1, #0xbc, lsl #16; sub x8, x8, #3` | `ThreadList::Init` cấp phát `0x4000` byte, truyền timeout `12345678` (`0x00bc614e`), tính `list_` tại `(timeout_idx - 3) * 8`, kết hợp `ScopedPLTHook` + `bytesig_init` (`0x58000004`, `0x110` byte/slot). |

---

## 3. Chứng Minh Toán Học & Bố Cục Struct ABI (`REQ_3_MATH_PROOF` & `REQ_4_ABI_LAYOUT`)
1. **Công thức Canary 2 lượt & Căn chỉnh con trỏ (`0x0155f4..0x0157b4`)**:
   $$C_0 = \text{0x12345678},\quad C_1 = C_0 \ll 1 = \text{0x2468ACF0},\quad W_{\text{aligned}} = (W + 1) \ \& \ \sim 1$$
2. **Công thức vị trí danh sách luồng `ThreadList::list_` (`0x01a4ec..0x01a72c`)**:
   $$T_{\text{magic}} = \text{0x00BC614E} = 12,345,678\text{ ns},\quad \text{offset}(\text{list\_}) = (\text{idx}_{\text{timeout}} - 3) \times 8$$
3. **Bố cục `art::ArtRuntime` (`152 bytes = 0x98` tại `.bss 0x026248`)**, **`art::Heap` (`40 bytes = 0x28` tại `.bss 0x026360`)**, và **`ByteSigSignalSlot` (`272 bytes = 0x110` mỗi tín hiệu tại `.bss 0x0263e8`)** khớp tuyệt đối 100% với lệnh truy cập thanh ghi AArch64.
