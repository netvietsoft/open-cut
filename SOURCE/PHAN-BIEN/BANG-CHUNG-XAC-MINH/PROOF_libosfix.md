# Hồ Sơ Bằng Chứng Xác Minh Khép Kín: `libosfix.so` (`TASK-112-RECONSTRUCTION-LIBOSFIX`)

- **Target Binary**: `apktool-res/lib/arm64-v8a/libosfix.so` (`149,616 bytes`)
- **SHA-256**: `ddd8baabbcdd7941b13ab0e961a57e92843d957a0c64e6afa3613b2c433c937d`
- **Challenge Answered**: `SOURCE/PHAN-BIEN/YEU-CAU-CHUNG-MINH/CHALLENGE_libosfix.json`
- **Total Clean-Room C++17 Reconstructed**: `163,822 bytes` across 7 `.h`/`.cpp` files (`osfix_pseudocode.cpp` = `83,681 bytes`, `0` stubs)

---

## 1. Bằng Chứng Opcode Nhị Phân AArch64 (`REQ_2_OPCODE_EVIDENCE` — `[OBSERVED]`)

| Địa chỉ (`.text`) | Opcode (LE `uint32_t`) | Lệnh hợp ngữ AArch64 | Ánh xạ logic C++17 Clean-Room |
|---|---|---|---|
| `0x005d50..0x005da4` | `0xa9be4ff4`, `0xd0000113`, `0x91010273`, `0xf900467f` | `stp x20, x19, [sp, #-0x20]!`; `adrp x19, #0x28000`; `add x19, x19, #0x40`; `str xzr, [x19, #0x88]` | `.init_array[0]`: Khởi tạo `std::shared_timed_mutex` (`144 bytes`) tại `.bss 0x028040` (`pthread_mutex_init` tại `+0x00`, `pthread_cond_init` tại `+0x28` & `+0x58`, `state = 0` tại `+0x88`). |
| `0x005e7c` | `0xd4200020` | `brk #1` | `Java_com_bytedance_osfix_NativeToolUtil_nativeCrash`: Thực thi bẫy phần cứng `brk #1`. |
| `0x005e80..0x005eef` | `0x52a06400`, `0x97fffec7`, `0x52800040` | `mov w0, #0x3200000`; `bl operator new[]`; `mov w0, #2`; `bl sleep` | `Java_com_bytedance_osfix_NativeToolUtil_nativeOOM`: Vòng lặp cấp phát 50 MB (`0x3200000` = `52,428,800` byte) mỗi 2 giây. |
| `0x00627c..0x0063e3` | `0x97ffff89`, `0x97ffff86`, `0x97ffff50`, `0x97ffff4f` | `bl shared_timed_mutex::lock/unlock`; `bl shared_timed_mutex::lock_shared/unlock_shared` | `setenv_proxy` (`0x00627c`) khóa ghi độc quyền và `getenv_proxy` (`0x00633c`) khóa đọc chia sẻ trên `.bss 0x028040` khi được cài đặt bởi `fixGetSetEnvCall` (`0x0064ec`). |
| `0x006678..0x00699f` | `0xd53bd058`, `0xf9400703`..`0xf9402703`, `0x52807d00` | `mrs x24, tpidr_el0`; `ldr x3, [x24, #0x08..#0x48]`; `mov w0, #0x3e8`; `bl sleep` | `log_assert_proxy`: Đọc 7 khe Bionic TLS từ `tpidr_el0` (`+0x08`, `+0x18`, `+0x20`, `+0x28`, `+0x38`, `+0x40`, `+0x48`), ghi log `pthread_self()` & `gettid()`, và ngủ `1000` giây (`0x3e8`). |
| `0x006f9c..0x00856b` | `0x7110027f`, `0xcb13001c`, `0x97fff69d` | `cmp w19, #0x400`; `sub x28, x0, x19`; `bl munmap` | `freeVdex`: Quét `/proc/self/smaps`, trích xuất phạm vi địa chỉ qua regex `(\w{8})-(\w{8})` và `Pss:\s+(\d+)\skB`; nếu `Pss <= 1024 kB` (`0x400`), gọi `munmap(start, end - start)`. |
| `0x01681c..0x016b9b` | `0xb40001a1`, `0xd0000088`, `0xb9800908`, `0x52800700`, `0xf9000ae8` | `cbz x1, #0x16874`; `adrp x8, #0x28000`; `ldrsw x8, [x8, #8]`; `mov w0, #0x38`; `str x8, [x23, #0x10]` | `ThreadStackOptimizer`: Cấp phát `pthread_attr_t` (`0x38` = 56 byte) nếu `attr == nullptr`, ghi đè `attr->stack_size` (`+0x10`) bằng `java_shrink_thread_size` (`.data 0x028008` = `0x30000`) hoặc `native_shrink_thread_size` (`.data 0x02800c` = `0x80000`). |
| `0x016ba4..0x01814f` | `0x528e6a15`, `0x72a74e75`, `0xf10ffc1f`, `0x97fff7fd` | `mov w21, #0x7350; movk w21, #0x3a73, lsl #16`; `cmp x0, #0x3ff`; `bl munmap` | `TypeFaceOptimizer`: Quét `/proc/self/maps` và `/proc/self/smaps` tìm `"Pss:"` (`0x3a737350`) trước `"VmFlags"`; nếu `Pss <= 1023 kB` (`0x3ff`), gọi `munmap(start, end - start)`. |

---

## 2. Chứng Minh Toán Học (`REQ_3_MATH_PROOF` — `[OBSERVED]`)

1. **Phương trình Chọn Kích thước Ngăn xếp Luồng (`0x016840..0x01688c`)**:
   $$\text{stack\_size}(r, \text{attr}) = \begin{cases} S_{\text{java}} = \text{0x00030000}\ (196,608\text{ B}) & \text{nếu } \text{attr} \neq \text{NULL} \land r \in \{\text{CreateCallback}, \text{CreateCallbackWithUffdGc}\} \\ S_{\text{native}} = \text{0x00080000}\ (524,288\text{ B}) & \text{ngược lại} \end{cases}$$
2. **Phương trình Ngưỡng Giải phóng Bộ nhớ Ánh xạ `munmap` cho `.vdex` và `.ttf` (`0x007da8` & `0x017998`)**:
   $$\text{Unmap}_{\text{VDEX}} \iff 0 \le \text{Pss}_{\text{kB}} \le \text{0x400}\ (1024\text{ kB}), \qquad \text{Unmap}_{\text{TTF}} \iff 0 \le \text{Pss}_{\text{kB}} \le \text{0x3FF}\ (1023\text{ kB})$$
3. **Phép chia cho 24 (`sizeof(std::sub_match)`) bằng Nghịch đảo Nhân Modulo $2^{64}$ (`0x007580..0x007594`)**:
   $$3 \times \text{0xAAAAAAAAAAAAAAAB} = \text{0x20000000000000001} \equiv 1 \pmod{2^{64}} \implies N = \left(\frac{\text{end} - \text{begin}}{8}\right) \times \text{0xAAAAAAAAAAAAAAAB} \bmod 2^{64} = \frac{\text{end} - \text{begin}}{24}$$
4. **Hằng số 4 byte `"Pss:"` Little-Endian (`0x016d90..0x016da0`)**:
   $$\text{0x50}\ ('\text{P}') \mid (\text{0x73}\ ('\text{s}') \ll 8) \mid (\text{0x73}\ ('\text{s}') \ll 16) \mid (\text{0x3A}\ ('\text{:}') \ll 24) = \text{0x3A737350}$$
