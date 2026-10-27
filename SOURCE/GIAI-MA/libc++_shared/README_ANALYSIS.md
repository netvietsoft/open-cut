# Clean-Room Reconstruction Analysis — `libc++_shared.so`
## Phân Tích Tái Tạo Phòng Sạch — `libc++_shared.so`

- **Target Binary / Nhị phân mục tiêu**: `libc++_shared.so` (`919,888 bytes`)
- **SHA-256**: `e861c5cc64fd7045f2208cec91092009d3aef2af834f6928c1299cc21ca28bc6`
- **Task ID**: `TASK-150-RECONSTRUCTION-LIBCXX-SHARED` / `TASK_SO_096_libc++_shared`
- **Architecture / Kiến trúc**: `AArch64` (`ELF64 Little-Endian`, `.eh_frame_hdr` @ `0x0bc000`, `1,953` FDEs)
- **Exported Symbols / Biểu tượng xuất**: `2,195`
- **Imported Symbols / Biểu tượng nhập**: `132`
- **Reconstructed C++17 Size / Dung lượng C++17 tái tạo**: `1,603,669 bytes` across 9 files (`0` stubs)

---

## 1. Key Verified AArch64 Functions & Mathematical Proofs / Các Hàm AArch64 & Chứng Minh Toán Học

1. **`std::__ndk1::__rs_default::operator()` (`0x048c74..0x048dc8`) — Mersenne Twister MT19937**:
   - `0x048d70..0x048da4`: Seeds `mt[0] = 0x1571` (`5489`) and iterates $mt[i] = 1812433253 \cdot (mt[i-1] \oplus (mt[i-1] \gg 30)) + i$ (`0x6c078965`) for $i = 1 \dots 623$ (`0x270 = 624`).
   - `0x048ce8..0x048d48`: Twists with `M = 397` (`0x18d`) and `MATRIX_A = 0x9908b0df`, then tempers with `0x9d2c5680` and `0xefc60000`.
2. **`std::__ndk1::chrono::system_clock` & `steady_clock` (`0x0520d4..0x0521f4`)**:
   - `system_clock::now()` (`0x052114..0x052140`): Divides `tv_nsec` by `1,000` via `0x20c49ba5e353f7cf` (`smulh + asr #7`) and adds `tv_sec * 1,000,000` (`0x000f4240`).
   - `system_clock::to_time_t` (`0x052168..0x052188`): Divides microseconds by `1,000,000` via `0x431bde82d7b634db` (`9B497D08 smulh x8, x8, x9; 9352FD09 asr x9, x8, #0x12; 8B48FD20 add x0, x9, x8, lsr #63`).
3. **`std::__ndk1::__shared_weak_count` (`0x0918a8..0x091a38`)**:
   - Uses AArch64 `ldxr/stxr` (`__add_shared` @ `0x091910`, `__add_weak` @ `0x091928`) and `ldaxr/stlxr` (`__release_shared` @ `0x091940`, `lock` @ `0x0919ec`).
