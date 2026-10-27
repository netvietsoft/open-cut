# libjazz.so — Clean-Room C++17 Reconstruction & Binary Forensics

> **Target Binary**: `SOURCE/apktool-res/lib/arm64-v8a/libjazz.so`  
> **File Size**: `231,840 bytes` (`0x389A0` bytes)  
> **SHA-256**: `f11496ae99e17699d6f2a2df40043c3014bc8391aab0d6422acc2a63590183e4`  
> **Task ID**: `TASK-122-RECONSTRUCTION-LIBJAZZ` (`TASK_SO_122_libjazz`, Target **83 / 169**)  
> **Namespace**: `AmazingEngine`  
> **Linked Dependencies**: `libquick.so` (Lynx Lepus / QuickJS engine), `libc++_shared.so`, `liblog.so`, `libm.so`, `libdl.so`, `libc.so`

---

## 1. Architectural Overview (Tổng Quan Kiến Trúc)

- **[EN]** `libjazz.so` is the **AmazingEngine Jazz JavaScript Runtime Bridge** used by CapCut's Effect SDK (`effect.Amaz`) to execute JavaScript effect scripts on top of `libquick.so` (`LEPUSRuntime` / `LEPUSContext`). It provides a multi-threaded task runner (`BEFBaseRunner` / `BEFTask`), isolated and multi-context JS runtimes (`Platform`, `Runtime`, `VM`, `Context`, `ContextExecutor`), a 256-byte $\text{GF}(2)^8$ affine involution S-Box script decryptor (`sub_17a08`) that decodes embedded `/bootstrap.js` (`7,097 bytes`) and `makeRequire.js` (`582 bytes`), and native Node/CommonJS-compatible modules (`FileSystemModule`, `ModuleRegistry`, `RequireModule`, `TimerModule`).
- **[VN]** `libjazz.so` là **Cầu nối Runtime JavaScript Jazz của AmazingEngine** được Effect SDK (`effect.Amaz`) sử dụng để thực thi các kịch bản hiệu ứng JavaScript trên nền `libquick.so` (`LEPUSRuntime` / `LEPUSContext`). Thư viện cung cấp bộ lập lịch tác vụ đa luồng (`BEFBaseRunner` / `BEFTask`), môi trường thực thi JS đơn/đa ngữ cảnh (`Platform`, `Runtime`, `VM`, `Context`, `ContextExecutor`), bộ giải mã kịch bản dùng hộp thế S-Box đối hợp affine $\text{GF}(2)^8$ 256-byte (`sub_17a08`) giải mã `/bootstrap.js` (`7.097 byte`) và `makeRequire.js` (`582 byte`), cùng các module gốc tương thích CommonJS (`FileSystemModule`, `ModuleRegistry`, `RequireModule`, `TimerModule`).

---

## 2. ELF64 Section Map (`libjazz.so`)

| Section | VMA (`sh_addr`) | File Offset (`sh_offset`) | Size (`sh_size`) | Description (EN / VN) |
|---|---:|---:|---:|---|
| `.dynsym` | `0x0002c0` | `0x0002c0` | `0x001f98` (`8,088 B`) | 336 dynamic symbols (182 defined `STT_FUNC`, 18 `STT_OBJECT`) / Bảng ký hiệu động |
| `.dynstr` | `0x002258` | `0x002258` | `0x003702` (`14,082 B`) | Dynamic string table / Bảng chuỗi ký hiệu động |
| `.rela.dyn` | `0x005ef0` | `0x005ef0` | `0x0054c0` (`21,696 B`) | Dynamic relocations (vtable & RTTI pointers) / Bảng định vị lại động |
| `.rela.plt` | `0x00b3b0` | `0x00b3b0` | `0x0010f8` (`4,344 B`) | PLT relocations (`LEPUS_*` imports from `libquick.so`) / Định vị lại PLT |
| `.plt` | `0x00c4b0` | `0x00c4b0` | `0x000608` (`1,544 B`) | Procedure Linkage Table / Bảng liên kết thủ tục |
| `.text` | `0x00cab8` | `0x00cab8` | `0x0190c0` (`102,592 B`) | Executable AArch64 instructions / Mã máy AArch64 thực thi |
| `.rodata` | `0x025b80` | `0x025b80` | `0x003eba` (`16,058 B`) | Constants, S-Box (`0x028bf0`), `/bootstrap.js` (`0x027037`), `makeRequire.js` (`0x0297d2`) |
| `.eh_frame` | `0x02af10` | `0x02af10` | `0x005e24` (`24,100 B`) | Unwind tables / Bảng tháo gỡ ngăn xếp |
| `.data.rel.ro` | `0x03a278` | `0x036278` | `0x001240` (`4,672 B`) | Read-only relocated vtables (`0x03a2a8..0x03b0f8`) / Bảng hàm ảo vtable |
| `.data` | `0x03c000` | `0x038000` | `0x0000d8` (`216 B`) | Writable initialized data / Dữ liệu khởi tạo có thể ghi |
| `.bss` | `0x03c0d8` | `0x0380d8` | `0x000098` (`152 B`) | Zero-initialized static state / Vùng nhớ tĩnh khởi tạo bằng 0 |

---

## 3. Mathematical Proof & AArch64 Disassembly Verification

### 3.1. 256-Byte $\text{GF}(2)^8$ Affine Involution S-Box (`sub_17a08` @ `0x017a08..0x017a38`, Table @ `.rodata 0x028bf0..0x028cf0`)

- **Closed-Form Algebraic Law**:
  $$\text{SBox}[x] = x \oplus \mathtt{0xF0} \oplus ((x \mathbin{\&} 3) \times \mathtt{0x54}), \quad \forall x \in \{0, \dots, 255\}$$
  Since $((x \oplus \mathtt{0xF0} \oplus ((x \mathbin{\&} 3) \times \mathtt{0x54})) \mathbin{\&} 3) = x \mathbin{\&} 3$ (both $\mathtt{0xF0}$ and $\mathtt{0x54}$ have bit $0$ and bit $1$ equal to $0$), applying $\text{SBox}$ twice cancels out:
  $$\text{SBox}[\text{SBox}[x]] = x \quad (\text{Self-Inverse Involution})$$

- **AArch64 Opcode Sequence (`0x017a08..0x017a38`)**:
  ```asm
  0x017a08: f1000448  subs x8, x2, #1            ; payload_len = len - 1
  0x017a0c: 54000120  b.eq 0x17a30               ; if len == 1 -> write '\0'
  0x017a10: 90000089  adrp x9, #0x28000
  0x017a14: 912fc129  add  x9, x9, #0xbf0        ; x9 = .rodata 0x028bf0 (S-Box)
  0x017a18: aa0003ea  mov  x10, x0               ; dst cursor
  0x017a1c: aa0803eb  mov  x11, x8               ; counter
  0x017a20: 3840142c  ldrb w12, [x1], #1         ; in_byte = *src++
  0x017a24: 386c692c  ldrb w12, [x9, x12]        ; out_byte = SBox[in_byte]
  0x017a28: f100056b  subs x11, x11, #1
  0x017a2c: 3800154c  strb w12, [x10], #1        ; *dst++ = out_byte
  0x017a30: 54ffffa1  b.ne 0x17a20
  0x017a34: 3828681f  strb wzr, [x0, x8]         ; dst[len - 1] = '\0'
  0x017a38: d65f03c0  ret
  ```

### 3.2. `BEFBaseRunner` Millisecond-to-Second Scaling & Delay Scheduling (`0x00cbc4` & `0x00ce74`)

- At `.rodata 0x025b80`, IEEE-754 double `1000.0` (`0x408f400000000000`) is stored and loaded by `BEFBaseRunner::GetNext` (`0x00cbc4`) to convert remaining seconds into milliseconds (`fmul d0, d0, d1`).
- At `BEFBaseRunner::PostDelayedTask` (`0x00ce74`), the task expiration timestamp is computed via `fadd d0, d0, d8` (`0x1e682800` at `0x00cecc`, adding `NowSeconds() + delaySeconds`).

### 3.3. `FileSystemModule::Stats` POSIX `struct stat` Accessors (`0x01d074..0x01d0b0`)

- `Stats::getSize()` (`0x01d074`):
  - `0x01d074`: `fd402400` (`ldr d0, [x0, #0x48]`)
  - `0x01d078`: `5e61d800` (`scvtf d0, d0` — signed 64-bit integer to IEEE-754 double)
  - `0x01d07c`: `52800020` (`mov w0, #1` — `ValueType::NUMBER`)
- `Stats::isDirectory()` (`0x01d084`):
  - `0x01d084`: `b9402808` (`ldr w8, [x0, #0x28]`)
  - `0x01d088`: `12140d08` (`and w8, w8, #0xf000`)
  - `0x01d090`: `7140111f` (`cmp w8, #4, lsl #12` — `S_IFDIR = 0x4000`)
- `Stats::isFile()` (`0x01d09c`):
  - `0x01d0a8`: `7140211f` (`cmp w8, #8, lsl #12` — `S_IFREG = 0x8000`)

### 3.4. `RequireModule` NEON Popcount Hash Bucket Index (`0x0220b4` & `0x0221c4`)

- `0x0220b4`: `9e670100` (`fmov d0, x8`)
- `0x0220b8`: `0e205800` (`cnt v0.8b, v0.8b`)
- `0x0220bc`: `2e303800` (`uaddlv h0, v0.8b`)
- Checks whether `bucket_count` has population count $\le 1$ (power of two) to select fast bitmask `hash & (bc - 1)` vs `udiv`/`msub` modulo `hash - (hash / bc) * bc`.

---

## 4. Reconstructed File Inventory (`SOURCE/GIAI-MA/libjazz/`)

| File | Role (EN / VN) |
|---|---|
| `jazz_types.h` | Core enums (`JSEngineType`, `RuntimeMode`, `ValueType`), `Value`, `Object`, S-Box closed-form math, and ABI constants |
| `jazz_runner_context.h` / `.cpp` | `BEFTask`, `BEFBaseRunner`, `Context`, and `ContextExecutor` CommonJS wrapper |
| `jazz_platform_runtime_vm.h` / `.cpp` | `Engine`, `VM`, `VMScope`, `CreateQuickJSPlatform`, `CreateQuickJSVM`, `Runtime`, `Platform`, and S-Box table/decoders |
| `jazz_modules.h` / `.cpp` | `FileSystemModule`, `FileSystemModule::Stats`, `ModuleRegistry`, `RequireModule`, and `TimerModule` |
| `jazz_interface.h` / `jazz_pseudocode.cpp` | Public umbrella header, AArch64 disassembly reference functions, and deterministic self-verification suite |
