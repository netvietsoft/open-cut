# Bằng Chứng Xác Minh Đối Kháng: `libpumbaa-network.so`
# Adversarial Verification Proof: `libpumbaa-network.so`

> **Task ID**: `TASK-099-RECONSTRUCTION-LIBPUMBAA_NETWORK` / `TASK_SO_043_libpumbaa_network`  
> **Trạng Thái (Status)**: `VERIFIED_AND_ACCEPTED`  
> **Tổng Dung Lượng Mã Nguồn Tái Dựng (Gate 1)**: `99,439 bytes` (`8` files C++17 & Headers trong `SOURCE/GIAI-MA/libpumbaa-network/`, vượt ngưỡng `40,000 bytes`).

---

## 1. Đối Soát Opcode AArch64 (Gate 2 — Direct Disassembly Matching)

| Địa Chỉ (VA) | Lệnh Hợp Ngữ AArch64 (`libpumbaa-network.so`) | Hàm Phục Hồi Trong C++17 |
|---|---|---|
| `0x001e9c..0x00209f` | `ldr x8, [x0]; ldr x8, [x8, #0x30]; mov w2, #0x10002; blr x8` / `csinv w0, w22, wzr, ne` | `JNI_OnLoad` (`pumbaa_network_sandbox_jni.cpp`) |
| `0x0020a0..0x0022bb` | `mov w1, #3; blr PushLocalFrame` / `ldrb w8, [x26, #0x20]` / `ldrb w8, [x26, #0x38]` | `jni_convertMap` (`pumbaa_network_sandbox_jni.cpp`) |
| `0x0023f4..0x00252b` | `ldr x8, [x22, #0x40]; cbz x8, 0x2434` / `ldr x8, [x8, #0x478]` | `monitorCost(const char*, long long)` (`pumbaa_network_sandbox_jni.cpp`) |
| `0x0025c8..0x00271f` | `bl _ZNSt6chrono12steady_clock3nowEv` / `ldr x8, [x8, #0x430]` | `domainIdentityRecognize` (`pumbaa_network_sandbox_jni.cpp`) |
| `0x0027bc..0x002bab` | `ldr x9, [x8, #0x728]` (`NewDirectByteBuffer`) / `smulh x9, x22, x9` (`0xdf3b645a1cac0831`) / `madd x1, x9, x10, x8` | `handleByPumbaaForSandbox` (`pumbaa_network_sandbox_jni.cpp`) |
| `0x002c48..0x002d5f` | `ldr x8, [x8, #0x390]` (`CallStaticBooleanMethod`) / `tst w0, #0xff; cset w19, ne` | `matchAgSchema` (`pumbaa_network_sandbox_jni.cpp`) |
| `0x002dfc..0x002ed0` | `mov w0, #0x50; bl _Znwm` / `bl __tree_balance_after_insert` | `__emplace_hint_unique_key_args` (`pumbaa_network_rbtree_dwarf.cpp`) |
| `0x0031ac..0x003388` | `ldr x11, [x1, #0x10]; cmp x11, x0; cset w12, eq` | `__tree_balance_after_insert` (`pumbaa_network_rbtree_dwarf.cpp`) |

---

## 2. Chứng Minh Toán Học & Bố Cục Struct ABI (Gates 3 & 4)

1. **Chia 64-bit có dấu cho $1000$ bằng hằng số nghịch đảo kép (`0x002b18..0x002b54`)**:
   - $M_+ = \text{0x20c49ba5e353f7cf}$ (`2361183241434822607`) và $M_- = \text{0xdf3b645a1cac0831}$ (`-2361183241434822607`).
   - Phép nhân `madd x1, x9, x10, x8` với `w10 = 0x3e8` (`1000`) tái tạo chính xác độ trễ micro-giây tương đối so với mili-giây nguyên của thời điểm bắt đầu.
2. **Bố cục ABI nút cây đỏ-đen `80 bytes` (`0x50`) & `.bss` (`88 bytes`)**:
   - Kiểm chứng bằng `static_assert(sizeof(PumbaaMapTreeNodeAbi) == 0x50)` và `static_assert(sizeof(PumbaaBssGlobalsLayout) == 0x58)`.
