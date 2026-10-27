# Clean-Room Forensics & C++17 Reconstruction: `libgaia_lib.so` (`TASK-135` / `TASK_SO_112_libgaia_lib`)

## 1. Binary Identity & ELF Layout (Định danh Nhị phân & Bố cục ELF)
- **File Name**: `libgaia_lib.so` (ByteDance AmazingEngine GAIA Core Math, Geometry, PerlinNoise, ThreadPool, FileUtils, MemoryPool, NetworkClient & `stb_truetype` SDF Engine)
- **File Size**: `329,704 bytes` (`329,704 bytes`)
- **SHA-256**: `a42c9645c2acd2bebcf524e5eec1b759c39f85403fd89c36afabadfaa9e6a911`
- **Architecture**: `AArch64 (ELF64 Little-Endian, arm64-v8a, 16KB page-aligned PT_LOAD)`
- **Dependencies (`DT_NEEDED`)**: `liblog.so`, `libm.so`, `libc++_shared.so`, `libdl.so`, `libc.so`
- **Exported `.dynsym` Symbols**: `392` symbols (`386` functions + `6` `.rodata`/`.bss` objects)
- **Unwind `.eh_frame_hdr` FDEs**: `757` functions (`0x010550 .. 0x04379c`)

| Section | Virtual Address (`VA`) | File Offset | Size (Bytes) | Role (EN / VN) |
|---|---:|---:|---:|---|
| `.text` | `0x010550` | `0x010550` | `209,484` | Executable AArch64 instructions / Mã máy thực thi AArch64 |
| `.rodata` | `0x0437a0` | `0x0437a0` | `10,775` | Perlin 256-entry table, `Vector2f` constants, `stbtt` tables / Bảng hằng số |
| `.eh_frame_hdr` | `0x0461b8` | `0x0461b8` | `6,068` | `757` binary-search FDE unwind entries / Bảng tháo ngăn xếp 757 hàm |
| `.init_array` | `0x052628` | `0x04e628` | `24` | 3 global C++ constructors (`0x010550`, `0x01056c`, `0x010628`) |
| `.data.rel.ro` | `0x052650` | `0x04e650` | `3,192` | Vtables (`RefBase`, `ThreadPool`, `NetworkClient`, `MemoryStream`) |
| `.data` | `0x054000` | `0x050000` | `4` | `DefaultMemoryAlignment = 0x00000010` (`16`) |
| `.bss` | `0x054010` | `0x050004` | `1,136` | `g_aeLogT` (`0x054010`) and singleton state |

---

## 2. Key Mathematical & Binary Proofs (Bằng chứng Toán học & Nhị phân Cốt lõi)
1. **3x3 Determinant (`AmazingEngine::Matrix3x3f::GetDeterminant` at `0x0135a4 .. 0x0135fc`)**:
   - Loads `m_Data[0..8]` via `ldp s0, s7, [x0]` (`0x0135a4: 0x2D401C00`), `ldp s4, s1, [x0, #0xc]` (`0x0135a8: 0x2D418404`), `ldp s6, s2, [x0, #0x1c]` (`0x0135ac: 0x2D438806`), and computes:
     $$\det(M) = (m_0 m_4 m_8 + m_3 m_7 m_2 + m_6 m_1 m_5) - (m_2 m_4 m_6 + m_8 m_3 m_1 + m_0 m_7 m_5)$$
2. **4x4 Gauss-Jordan Full Inversion (`AmazingEngine::InvertMatrix4x4_Full` at `0x0151e0 .. 0x0159dc`)**:
   - Allocates `0xA0` stack frame (`0x0151e0: 0xD10283FF`), loads 4x4 identity basis rows from `.rodata` (`0x043950`, `0x0439a0`, `0x0439b0`, `0x0439c0`), performs partial pivoting on each column, and returns `false` (`0`) when any pivot is `0.0f` (`0x01535c: 0x1E202028 fcmp s1, #0.0; 0x015360: 0x54001D80 b.eq #0x15710`).
3. **3D Perlin Improved Noise (`AmazingEngine::PerlinNoise::Perlin3D` at `0x017098 .. 0x01834b`)**:
   - Uses `.rodata 0x043ae0` (`kPerlinPermTable_043ae0[256]`, starting with `151, 160, 137, 91, 90, 15, 131, 13`, ending with `180`) and 8 gradient dispatch jump tables at `.rodata 0x043a60 .. 0x043adf`.
   - Evaluates Ken Perlin's quintic fade polynomial $f(t) = t^3(t(6t - 15) + 10)$ using exact AArch64 floating-point immediates:
     - `0x0170e8: 0x1E231004 fmov s4, #6.00000000`
     - `0x0170f8: 0x1E35D007 fmov s7, #-15.00000000`
     - `0x017128: 0x1E249016 fmov s22, #10.00000000`
4. **Quaternion Spherical Linear Interpolation (`AmazingEngine::Slerp` at `0x018720 .. 0x018890`)**:
   - Computes 4D dot product $\cos\Omega = q_1 \cdot q_2$, negates $q_2$ if $\cos\Omega < 0$, and compares against threshold `0x3F733333` (`0.95f` via `0x018770: 0x52866668 mov w8, #0x3333; 0x018774: 0x72A7EE68 movk w8, #0x3f73, lsl #16`), switching between exact spherical trigonometric interpolation (`acosf`/`sinf`) and normalized linear interpolation (`NLerp`).
5. **Signed Distance Field Glyph Generator (`AmazingEngine::stbtt_GetGlyphSDF` at `0x03f928 .. 0x040843`)**:
   - Checks `scale == 0.0f` (`0x03f960: 0x1E202008 fcmp s0, #0.0`), computes padded glyph box, and iterates 14-byte `stbtt_vertex` entries (`0x03fae8: 0x528001CB mov w11, #0xe; 0x03fafc: 0x9B2B21AD smaddl x13, w13, w11, x8`).
6. **Atomic Intrusive Reference Counting (`AmazingEngine::RefBase` at `0x043728 .. 0x04379c`)**:
   - `retain()` (`0x043728`) and `release()` (`0x043740`) use AArch64 `ldaxr`/`stlxr` atomic loops on `this + 0x08`, dispatching `vtable[+0x28]` when the previous reference count reaches `1`.
