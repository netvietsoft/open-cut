# Bằng Chứng Xác Minh Đối Kháng: `libnewep.so`
# Adversarial Verification Proof: `libnewep.so`

> **Task ID**: `TASK-100-RECONSTRUCTION-LIBNEWEP` / `TASK_SO_148_libnewep`  
> **Trạng Thái (Status)**: `VERIFIED_AND_ACCEPTED`  
> **Tổng Dung Lượng Mã Nguồn Tái Dựng (Gate 1)**: `93,779 bytes` (`8` files C++17 & Headers trong `SOURCE/GIAI-MA/libnewep/`, vượt ngưỡng `40,000 bytes`).

---

## 1. Đối Soát Opcode AArch64 (Gate 2 — Direct Disassembly Matching)

| Địa Chỉ (VA) | Lệnh Hợp Ngữ AArch64 (`libnewep.so`) | Hàm Phục Hồi Trong C++17 |
|---|---|---|
| `0x001ebc..0x00209b` | `mov w2, #6; movk w2, #1, lsl #16` / `tst w0, #0xff; b.eq #0x2020` | `JNI_OnLoad` (`newep_resource_finder_jni.cpp`) |
| `0x00209c..0x0020a7` | `adrp x0, #0xf000; ldr x0, [x0, #0xfb0]; ret` | `AlgorithmModelResourceFinder_nativeCreateResourceFinder` (`newep_resource_finder_jni.cpp`) |
| `0x0020a8..0x002437` | `cmn w0, #2; b.ne #0x2124` / `bl strcmp` (`"asset://not_found"`) / `bl modelNotFound` | `_Z40findResourceUri_DownloadableModelSupportPvPKcS1_` (`newep_resource_finder_jni.cpp`) |
| `0x002570..0x00326f` | `mov w1, #0x1e; bl __strlen_chk` / `cmp w14, #0x20` / `bl stat` | `EffectUtilKt_nativeCheckEffectChildrenFile` (`newep_resource_finder_jni.cpp`) |
| `0x003558..0x0038e3` | `asr x8, x8, #3; mul x22, x8, x10` (`0xaaaaaaaaaaaaaaab`) | `vector<string>::__push_back_slow_path` (`newep_stl_unwind.cpp`) |

---

## 2. Chứng Minh Toán Học & Bố Cục Struct ABI (Gates 3 & 4)

1. **Phép chia chính xác cho $24$ bằng nghịch đảo modular `0xaaaaaaaaaaaaaaab` (`0x00356c..0x0035d4` & `0x00377c..0x0037e4`)**:
   - $((\text{end} - \text{begin}) \gg 3) \times \text{0xaaaaaaaaaaaaaaab} \pmod{2^{64}}$ tính chính xác số phần tử `std::string` (`24 bytes`).
2. **Bố cục ABI `.bss` (`624 bytes = 0x270`)**:
   - Kiểm chứng bằng `static_assert(sizeof(NewepBssSegment) == 624)` với 6 con trỏ toàn cục JNI tại `0x010010..0x010038` và bảng `dwarf_reg_size_table[97]` tại `0x010040..0x0100a0`.
