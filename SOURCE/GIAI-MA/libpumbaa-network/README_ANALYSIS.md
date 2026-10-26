# Báo Cáo Giải Mã Chuyên Sâu: `libpumbaa-network.so` (Pumbaa / Helios Network Sandbox & Domain Identity Recognition Bridge)
# Deep Reverse Engineering Analysis: `libpumbaa-network.so`

> **Task ID**: `TASK-099-RECONSTRUCTION-LIBPUMBAA_NETWORK` / `TASK_SO_043_libpumbaa_network`  
> **Target Binary**: `libpumbaa-network.so` (`51,232 bytes`, ARM64 / AArch64 ELF64 Shared Object)  
> **Assigned Roles**: Agent 4 (Integration/API) + Agent 3 (Frontend/Android Native) + Agent 13 (Adversary Auditor)  
> **Evidence Classification**: `100% OBSERVED` từ Capstone AArch64 Disassembly (`0x001cc0..0x006def`), `.dynsym` (`68` entries: `28` imports + `37` exports), `.rodata` (`0x006df0..0x007114`), và `.bss` (`0x010008..0x010078`).

---

## 1. Bố Cục Nhị Phân ELF64 (ELF64 Binary Section Layout)

| Section | Virtual Address (`sh_addr`) | File Offset (`sh_offset`) | Size (`sh_size`) | Ý Nghĩa Kỹ Thuật (Technical Purpose) |
|---|---|---|---|---|
| `.dynsym` | `0x000530` | `0x000530` | `0x0660` (`1,632 B`) | `68` symbol entries (`28` imported + `37` exported: `11` `.bss` globals + `26` functions). |
| `.plt` | `0x001cc0` | `0x001cc0` | `0x01d0` (`464 B`) | `27` PLT stubs (`0x001ce0..0x001e80`) cho `__android_log_print`, `_ZNSt6chrono12steady_clock3nowEv`, `_Znwm`, `_ZdlPv`, `strlen`, `memcpy`, `abort`, `calloc`, `realloc`, `free`. |
| `.text` | `0x001e90` | `0x001e90` | `0x4f60` (`20,320 B`) | Mã máy AArch64 của Pumbaa Network Sandbox JNI Bridge, `std::__ndk1::__tree` Red-Black Tree (`80-byte` nodes), và bộ giải mã DWARF `.eh_frame` / libunwind. |
| `.rodata` | `0x006df0` | `0x006df0` | `0x0324` (`804 B`) | Chuỗi class/signature JNI (`com/bytedance/helios/network/SandboxBridge`, `NetworkDomainRecognize`, `java/util/HashMap`), tag `"Pumbaa_Log"`, và bảng nhảy DWARF pointer encoding. |
| `.eh_frame` | `0x0074e8` | `0x0074e8` | `0x0dc4` (`3,524 B`) | DWARF Call Frame Information cho trình xử lý ngoại lệ `__gxx_personality_v0`. |
| `.bss` | `0x010008` | `0x00e008` | `0x0078` (`120 B`) | `11` con trỏ global JNI (`0x010010..0x010060`) và con trỏ cache `.eh_frame_hdr` (`0x010068`). |

---

## 2. Cấu Trúc ABI 11 Biến Toàn Cục `.bss` (`0x010010..0x010060`)

| Địa Chỉ `.bss` | Tên Symbol (`dynsym`) | Kiểu Dữ Liệu | Chuỗi / Phương Thức Liên Kết Trong `.rodata` |
|---|---|---|---|
| `0x010010` | `gClassNativeBridge` | `jclass` (GlobalRef) | `"com/bytedance/helios/network/SandboxBridge"` (`0x006df0`) |
| `0x010018` | `gNetworkDomainRecognize` | `jclass` (GlobalRef) | `"com/bytedance/helios/network/pipeline/recognize/NetworkDomainRecognize"` (`0x006e1b`) |
| `0x010020` | `gMethodHandleFromNativeSandbox` | `jmethodID` | `SandboxBridge.handleByPumbaa(IILjava/lang/String;Ljava/util/Map;Ljava/util/Map;Ljava/lang/String;Ljava/nio/ByteBuffer;I)Z` (`0x006e63` / `0x006e72`) |
| `0x010028` | `gMethodHandleFromNativeSandboxJson` | `jmethodID` | `SandboxBridge.handleByPumbaa2(IILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/nio/ByteBuffer;I)Z` (`0x006eec` / `0x006efc`) |
| `0x010030` | `gMethodDomainIdentityRecognize` | `jmethodID` | `NetworkDomainRecognize.domainIdentityRecognize(Ljava/lang/String;)Ljava/lang/String;` (`0x006f64` / `0x006f7c`) |
| `0x010038` | `gMethodMatchAgSchema` | `jmethodID` | `SandboxBridge.matchAgSchema(Ljava/lang/String;)Z` (`0x006ef0` reused +4 / `0x006f4e`) |
| `0x010040` | `gMethodMonitorCost` | `jmethodID` | `SandboxBridge.monitorCost(Ljava/lang/String;J)V` (`0x007016` / `0x007022`) |
| `0x010048` | `gClassHashMap` | `jclass` (GlobalRef) | `"java/util/HashMap"` (`0x006fa2`) |
| `0x010050` | `gMethodHashMapConstructor` | `jmethodID` | `HashMap.<init>(I)V` (`0x006fb4` / `0x006fbb`) |
| `0x010058` | `gMethodPut` | `jmethodID` | `HashMap.put(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;` (`0x006fc0` / `0x006fc4`) |
| `0x010060` | `gJvm` | `JavaVM*` | Lưu từ đối số `x0` của `JNI_OnLoad` tại `0x001ef4`. |

---

## 3. Phân Tích Toán Học & Thuật Toán Cốt Lõi (Core Mathematical & Algorithmic Proofs)

### 3.1. Phép Chia Số Nguyên Có Dấu 64-bit Cho $1000$ Bằng Hằng Số Nghịch Đảo Kép (`0x002b10..0x002b60`)
Trong hàm `handleByPumbaaForSandbox` (`0x0027bc..0x002bab`), để đo thời gian thực thi của `SandboxBridge.handleByPumbaa` và kiểm tra ngưỡng cảnh báo `> 0 ms` trước khi gọi `monitorCost("handleByPumbaaForSandbox", elapsed_us)`, trình biên dịch Clang AArch64 chuyển đổi hai mốc thời gian micro-giây (`start_us` trong `x22` và `end_us` trong `x8`) sang mili-giây bằng hai hằng số nhân nghịch đảo trái dấu:

1. **Hằng số dương cho `end_us / 1000` (`0x002b18..0x002b24`)**:
   $$M_+ = \text{0x20c49ba5e353f7cf} = 2361183241434822607 = \left\lfloor \frac{2^{70}}{1000} \right\rfloor + 1$$
   $$\text{end\_ms} = \text{asr}(\text{smulh}(\text{end\_us}, M_+), 7) + \text{lsr}(\text{smulh}(\text{end\_us}, M_+), 63) = \text{trunc}\left(\frac{\text{end\_us}}{1000}\right)$$

2. **Hằng số âm bù 2 cho `-start_us / 1000` (`0x002b28..0x002b34`)**:
   $$M_- = \text{0xdf3b645a1cac0831}_{\text{u64}} = -2361183241434822607_{\text{s64}} = -M_+$$
   $$\text{neg\_start\_ms} = \text{asr}(\text{smulh}(\text{start\_us}, M_-), 7) + \text{lsr}(\text{smulh}(\text{start\_us}, M_-), 63) = -\text{trunc}\left(\frac{\text{start\_us}}{1000}\right)$$

3. **Kiểm tra ngưỡng và tính `elapsed_us` bằng lệnh `madd` (`0x002b48..0x002b5c`)**:
   - Lệnh `adds x10, x10, x9` (`0x002b48`) tính $\Delta\text{ms} = \text{end\_ms} - \text{start\_ms}$ và đặt cờ điều kiện.
   - Nếu `b.le 0x2b68` không nhảy ($\Delta\text{ms} > 0$), lệnh `mov w10, #0x3e8` (`1000`) và `madd x1, x9, x10, x8` (`0x002b54`) tính đối số `cost` cho `monitorCost`:
     $$x_1 = \text{end\_us} + \left(-\text{trunc}\left(\frac{\text{start\_us}}{1000}\right)\right) \times 1000$$

### 3.2. Cấu Trúc Nút Cây Đỏ-Đen 80-Byte (`std::__ndk1::__tree_node` @ `0x002dfc` & `0x0020a0`)
Hàm `_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EE...` tại `0x002dfc` cấp phát mỗi nút của `std::map<std::string, std::string>` bằng lệnh `mov w0, #0x50; bl _Znwm` (`80 bytes` tại `0x002e44`):
- `+0x00..+0x1F` (`32 bytes`): Header liên kết cây đỏ-đen (`__left_`, `__right_`, `__parent_`, `__is_black_`).
- `+0x20..+0x37` (`24 bytes`): `key` (`std::__ndk1::basic_string<char>` theo libc++ SSO ABI).
- `+0x38..+0x4F` (`24 bytes`): `value` (`std::__ndk1::basic_string<char>` theo libc++ SSO ABI).
Khi `jni_convertMap` (`0x0020a0..0x0022bb`) duyệt cây, nó giải mã SSO cho cả `key` (`ldrb w8, [x26, #0x20]; tbz w8, #0, ...; ldp x27, x25, [x26, #0x20]`) và `value` (`ldrb w8, [x26, #0x38]; ldp x9, x8, [x26, #0x38]`), tạo `jstring` trong khung `PushLocalFrame(3)` (`0x0021ac`) rồi gọi `HashMap.put(key, val)`.
