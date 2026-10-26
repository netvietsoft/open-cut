# Bằng Chứng Xác Minh Đối Kháng `liborbuculumadapter.so` (Adversarial Verification Proof)

- **Mã bằng chứng / Proof ID**: `PROOF-LIBORBUCULUMADAPTER-V1`
- **Thư viện mục tiêu / Target Binary**: `SOURCE/apktool-res/lib/arm64-v8a/liborbuculumadapter.so` (`149,936 bytes`)
- **SHA-256**: `c79326a4419e98be93ce70b6b08f70a82852980d7322dadb3d5edac7ea179785`
- **Task ID**: `TASK-113-RECONSTRUCTION-LIBORBUCULUMADAPTER` (`TASK_SO_129_liborbuculumadapter`)

---

## 1. Bằng Chứng Opcode AArch64 Trực Tiếp (Direct AArch64 Opcode Evidence)

1. **`JNI_OnLoad` (`0x004540..0x0049fc`)**:
   - `0x004568`: `adrp x22, #0x28000; str x0, [x22, #0x1b8]` — Lưu `JavaVM*` vào `.bss 0x0281b8`.
   - `0x0045c4`: `adrp x1, #0x1a000; add x1, x1, #0x8dc` — Tìm lớp `"com/orbu/core/init/TTKNativeNetworkManager"`.
   - `0x0045dc`: `adrp x1, #0x1a000; add x1, x1, #0x907` — Tìm lớp `"com/orbu/core/init/TTKNativeLiveSeiFieldManager"`.
   - `0x004684`: `ldr x8, [x8, #0x6b8]; adrp x2, #0x28000; mov w3, #8; blr x8` — Gọi `env->RegisterNatives` với bảng 8 phương thức tại `.data 0x028000..0x0280b8`.

2. **Bảng Xuất Biểu Tượng ShadowHook `setenv` / `getenv` (`0x011db4..0x012354`)**:
   - `0x01207c`: `mov w0, wzr; mov w1, wzr; bl 0x4360` — Gọi `shadowhook_init(0, false)`.
   - `0x0120a8` & `0x0120ec`: Gọi `shadowhook_hook_sym_name("libc.so", "setenv", 0x011db4, &0x028878)` và `shadowhook_hook_sym_name("libc.so", "getenv", 0x011e74, &0x028880)`.
   - `0x011eb0`: Trong `hooked_getenv` (`0x011e74`), duyệt mảng 5 phần tử `EnvExportEntry` tại `.bss 0x028930` với bước nhảy `0x80` (`128 bytes`), so sánh `strcmp(name, entry.name)` và trả về trực tiếp chuỗi `"%p"` tại `entry + 0x40`.

3. **Toán Học Chia Cố Định 64-bit Cho $10^6$ (`0x0105dc` & `0x010db0`)**:
   - Lệnh máy: `mov x9, #0x34db; movk x9, #0xd7b6, lsl #16; movk x9, #0xde82, lsl #32; movk x9, #0x431b, lsl #48; smulh x9, x8, x9; asr x10, x9, #18; add x8, x10, x8, lsr #63`
   - Chứng minh: $\left\lceil \frac{2^{82}}{10^6} \right\rceil = 4835703278458516699 = \text{0x431BDE82D7B634DB}$, do đó phép nhân `smulh` dịch phải 18 bit tính chính xác $\lfloor \Delta t_{\text{ns}} / 10^6 \rfloor$ (mili-giây).
