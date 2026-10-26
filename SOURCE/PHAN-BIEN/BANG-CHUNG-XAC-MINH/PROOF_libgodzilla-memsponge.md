# Hồ Sơ Bằng Chứng Xác Minh Đối Kháng: `libgodzilla-memsponge.so` (Adversarial Verification Proof Dossier)

- **Mã bằng chứng (Proof ID)**: `PROOF-LIBGODZILLA-MEMSPONGE-V1`
- **Thư viện mục tiêu (Target Library)**: `libgodzilla-memsponge.so` (`1,043,056 bytes`, SHA-256: `cc00ce74c83c07821b2d6e80f1a00c8839551e02572c0f39d373ef7ad489a466`)
- **Task ID**: `TASK_SO_067_libgodzilla_memsponge` / `TASK-115-RECONSTRUCTION-LIBGODZILLA_MEMSPONGE`
- **Trả lời thách thức (Challenge Addressed)**: `CHALLENGE_libgodzilla-memsponge.json`

---

## 1. Đối Chiếu 6 Cổng Kiểm Định Đối Kháng (6 Adversarial Verification Gates)

| Cổng (Gate) | Tiêu chuẩn của Agent 13 (Adversary Critic) | Bằng chứng thực tế nộp (Submitted Evidence) |
|---|---|---|
| **Gate 1** | Tổng dung lượng mã nguồn tái dựng `> 40,000 bytes` | 10 tệp C++17 & tài liệu trong `SOURCE/GIAI-MA/libgodzilla-memsponge/` đạt **`> 115,000 bytes`**. |
| **Gate 2** | Đối chiếu địa chỉ ảo (VA) & mã máy AArch64 (`>= 5` khối) | Đối chiếu trực tiếp các vùng lệnh `0x075ac4..0x075bf8`, `0x077310..0x077860`, `0x0779d4..0x0780dc`, `0x078668..0x07887c`, `0x079c88..0x07d37c` và bảng `.data` `0x105ba0..0x106060`. |
| **Gate 3** | Chứng minh công thức toán học & thuật toán | Chứng minh công thức `alignHideLargeObjectBytes` (`target_hide = min(sHideLargeObjectMaxBytes, los_bytes)`), mặt nạ API `0xEFF8`/`0xEFFE` (bỏ qua API 32), `HeapSetIdealFootPrintProxy` (`536870912.0f`), và `ScudoMaxBytes = (page_size << 1) + 0xA000`. |
| **Gate 4** | Bố cục struct ABI & offset thanh ghi | Bảng 20 mục `ArtProxyMapping` (`sizeof = 0x38 = 56 B`, tổng `0x460 = 1,120 B` tại `0x105ba0..0x106000`), bảng 2 mục `SoftRefProxyMapping` (`sizeof = 0x28 = 40 B` tại `0x106010..0x106060`), và sơ đồ `.bss` `0x1062d0..0x1063b0`. |
| **Gate 5** | Khớp toàn bộ symbol xuất khẩu JNI | Khớp chính xác cả 26 hàm xuất khẩu JNI (`MemSpongeHelper` x14, `HeapClampHelper` x10, `StringOptHelper` x2). |
| **Gate 6** | Tích hợp kiểm thử tự động trong `verify_reconstruction_suite.py` | Tích hợp hàm `verify_libgodzilla_memsponge(self)` với 6 phép kiểm tra độc lập. |

---

## 2. Bằng Chứng Opcode AArch64 Trọng Tâm (Core AArch64 Disassembly Evidence)

1. **`alignHideLargeObjectBytes` (`0x075ac4..0x075b3c`)**:
   - `0x075b10`: `3f 01 00 eb` (`cmp x9, x0`)
   - `0x075b14`: `29 31 80 9a` (`csel x9, x9, x0, lo`)
   - `0x075b18`: `6a 02 0a cb` (`sub x10, x19, x10`)
   - `0x075b1c`: `40 01 09 8b` (`add x0, x10, x9`)
   - `0x075b24`: `eb 87 9f 1a` (`cset w11, ls`)
2. **`checkSupportApi` (`0x077310`) & `initArtHook` (`0x0773c0`)**:
   - `0x077310`: `28 50 00 71` (`subs w8, w1, #0x14`)
   - `0x077314`: `1f 3d 00 71` (`cmp w8, #0xf`)
   - `0x0776fc`: `f7 e2 00 91` (`add x23, x23, #0x38`)
   - `0x077700`: `ff 82 11 f1` (`cmp x23, #0x460`)
3. **`setLargeObjThreshold` (`0x077c38`) & `IsValidPtr` (`0x0779d4`)**:
   - `0x078040`: `1f 0d 40 f1` (`cmp x8, #3, lsl #12`)
   - `0x0780ac`: `29 7d 74 93` (`sbfiz x9, x9, #0xc, #0x20`)
4. **`doFixFreeList` (`0x07a49c`) & `fix_scudo_vma_leak` (`0x07c368`)**:
   - `0x07a8f8`: `09 45 51 d3` (`lsr x9, x8, #0x11`)
   - `0x07a920`: `23 06 80 52` (`mov w3, #0x31`)
   - `0x07c434`: `08 78 1f 53` (`lsl w8, w0, #1`)
   - `0x07c438`: `08 29 40 11` (`add w8, w8, #0xa, lsl #12`)
