# Báo Cáo Giải Mã Chuyên Sâu: `libnewep.so` (ByteDance EffectPlatform / EPKN Algorithm Model Resource Finder & Children Validator)
# Deep Reverse Engineering Analysis: `libnewep.so`

> **Task ID**: `TASK-100-RECONSTRUCTION-LIBNEWEP` / `TASK_SO_148_libnewep`  
> **Target Binary**: `libnewep.so` (`51,232 bytes`, ARM64 / AArch64 ELF64 Shared Object)  
> **Assigned Roles**: Agent 3 (Frontend/Android Native) + Agent 13 (Adversary Auditor)  
> **Evidence Classification**: `100% OBSERVED` từ Capstone AArch64 Disassembly (`0x001b60..0x00728b`), `.dynsym` (`75` entries: `43` imports + `29` exports), `.rodata` (`0x00728c..0x007584`), và `.bss` (`0x010010..0x01027f`).

---

## 1. Bố Cục Nhị Phân ELF64 (ELF64 Binary Section Layout)

| Section | Virtual Address (`sh_addr`) | File Offset (`sh_offset`) | Size (`sh_size`) | Ý Nghĩa Kỹ Thuật (Technical Purpose) |
|---|---|---|---|---|
| `.dynsym` | `0x000550` | `0x000550` | `0x0708` (`1,800 B`) | `75` symbol entries (`43` imported + `29` exported: `6` `.bss` JNI globals + `17` functions + `6` linker markers). |
| `.rela.dyn` | `0x001528` | `0x001528` | `0x01b0` (`432 B`) | `18` relocations (`3` `R_AARCH64_RELATIVE`, `14` `R_AARCH64_GLOB_DAT` @ `.got 0x00ff90..0x00fff8`, `1` `R_AARCH64_ABS64` @ `.data 0x010000`). |
| `.rela.plt` | `0x0016d8` | `0x0016d8` | `0x0480` (`1,152 B`) | `48` `R_AARCH64_JUMP_SLOT` relocations -> `.plt 0x001b80..0x001e70`. |
| `.text` | `0x001e80` | `0x001e80` | `0x540c` (`21,516 B`) | Mã máy AArch64 của `JNI_OnLoad`, `nativeCreateResourceFinder`, `findResourceUri_DownloadableModelSupport`, `nativeCheckEffectChildrenFile`, `std::__ndk1::basic_string` / `vector`, và bộ giải mã DWARF `.eh_frame`. |
| `.rodata` | `0x00728c` | `0x00728c` | `0x02f9` (`761 B`) | Chuỗi class/method JNI (`AlgorithmModelResourceFinder`, `DownloadableModelSupportResourceFinder`), `"/effect_platform_children.tag"`, `"asset://not_found"`, và bảng nhảy DWARF pointer encoding (`0x0074d0`). |
| `.bss` | `0x010010` | `0x00c010` | `0x0270` (`624 B`) | `6` con trỏ global JNI (`0x010010..0x010038`) và bảng `dwarf_reg_size_table[97]` (`0x010040..0x0100a0`). |

---

## 2. Cấu Trúc ABI 6 Biến Toàn Cục `.bss` (`0x010010..0x010038`)

| Địa Chỉ `.bss` | GOT Slot | Tên Symbol (`dynsym`) | Kiểu Dữ Liệu | Chuỗi / Phương Thức Liên Kết Trong `.rodata` |
|---|---|---|---|---|
| `0x010010` | `0x00ffd0` | `kn_resource_finder_class` (`[066]`) | `jclass` (GlobalRef) | `"com/ss/ugc/effectplatform/algorithm/AlgorithmModelResourceFinder"` (`0x00728c`) |
| `0x010018` | `0x00ffd8` | `kn_resource_finder_methodID` (`[064]`) | `jmethodID` | `AlgorithmModelResourceFinder.findResourceUri(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;` (`0x0073f3` / `0x0072cd`) |
| `0x010020` | `0x00ffe8` | `kn_model_not_found_methodID` (`[073]`) | `jmethodID` | `AlgorithmModelResourceFinder.modelNotFound(Ljava/lang/String;)V` (`0x007306` / `0x007314`) |
| `0x010028` | `0x00ffa0` | `old_resource_finder_methodID` (`[062]`) | `jmethodID` | `DownloadableModelSupportResourceFinder.findResourceUri(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;` (`0x0073f3` / `0x0072cd`) |
| `0x010030` | `0x00fff0` | `old_resource_finder_class` (`[050]`) | `jclass` (GlobalRef) | `"com/ss/android/ugc/effectmanager/DownloadableModelSupportResourceFinder"` (`0x00732a`) |
| `0x010038` | `0x00ffb8` | `g_vm` (`[061]`) | `JavaVM*` | Lưu từ đối số `x0` của `JNI_OnLoad` tại `0x001eec`. |

---

## 3. Phân Tích Toán Học & Thuật Toán Cốt Lõi (Core Mathematical & Algorithmic Proofs)

### 3.1. Phép Chia Cho $24$ (`sizeof(std::string) = 0x18`) Bằng Nghịch Đảo Modular `0xaaaaaaaaaaaaaaab` (`0x003568..0x003608` & `0x003778..0x003810`)
Trong hai hàm cấp phát lại bộ đệm vector `_ZNSt6__ndk16vectorINS_12basic_string...EE21__push_back_slow_pathIS6_EEvOT_` (`0x003558`, `[059]`) và `__push_back_slow_pathIRKS6_` (`0x003764`, `[052]`), độ lệch con trỏ $\Delta = \text{end} - \text{begin}$ luôn là bội số chính xác của $24 = 8 \times 3$.
Trình biên dịch Clang AArch64 tính $N = \Delta / 24$ bằng phép dịch phải 3 bit kết hợp nhân với nghịch đảo modular của $3 \pmod{2^{64}}$:
$$M_3 = \text{0xaaaaaaaaaaaaaaab}, \quad 3 \times \text{0xaaaaaaaaaaaaaaab} = 2^{64} + 1 \equiv 1 \pmod{2^{64}}$$
$$N = \left(\Delta \gg 3\right) \times \text{0xaaaaaaaaaaaaaaab} \pmod{2^{64}}$$
Và kiểm tra ngưỡng sức chứa tối đa của `std::vector<std::string>`:
$$\text{max\_size} = \left\lfloor \frac{2^{64}-1}{24} \right\rfloor = \text{0x0aaaaaaaaaaaaaaa}, \quad \frac{\text{max\_size}}{2} = \text{0x0555555555555555}$$

### 3.2. Tối Ưu Hóa Tái Sử Dụng Đuôi Chuỗi `.rodata` (`SHF_MERGE | SHF_STRINGS`)
Trình liên kết LLD của Android NDK gộp hai chuỗi con vào đuôi của hai chuỗi dài hơn trong `.rodata`:
1. **`0x0072cb` (`"r"`)**: Nằm ở byte cuối cùng của `"com/ss/ugc/effectplatform/algorithm/AlgorithmModelResourceFinder"` (`0x00728c + 63`), được nạp tại `0x002600` (`add x1, x1, #0x2cb`) làm đối số mode `"r"` cho `fopen(tagPath, "r")`.
2. **`0x0073f3` (`"findResourceUri"`)**: Nằm ở đuôi của `"tempJavaUri not found,then call old_resource_finder#findResourceUri"` (`0x0073bf + 52`), được nạp tại `0x001f64` và `0x002050` (`add x2, x2, #0x3f3`) làm tên phương thức trong `GetStaticMethodID`.
