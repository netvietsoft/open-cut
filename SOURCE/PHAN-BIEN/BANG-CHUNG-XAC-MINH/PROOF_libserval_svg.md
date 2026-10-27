# Adversarial Proof & Binary Verification: `libserval_svg.so`
## Bằng Chứng Phản Biện & Xác Minh Nhị Phân: `libserval_svg.so`

- **Task ID**: `TASK-130-RECONSTRUCTION-LIBSERVAL-SVG` (`TASK_SO_037_libserval_svg`)
- **Target Library**: `libserval_svg.so` (`282,912 bytes`, SHA-256: `742e48019f3701911055dc50691d61bb7b517be98800be8b0dcdf9918f0d296a`)
- **Reconstructed C++17 Volume**: `195,870 bytes` across 9 files (`0` stubs)
- **Disassembled Instructions Verified**: `1819` AArch64 instructions

## 1. Key AArch64 Opcode Evidence (Bằng Chứng Opcode AArch64)
- `JNI_OnLoad` (`0x00ab2c..0x00abe8`):
  - `0x00ab64`: `c20100d0 adrp x2, #0x44000` + `0x00ab6c`: `42c03691 add x2, x2, #0xdb0` (loads `JNINativeMethod[2]` table at `.data.rel.ro 0x044db0`)
  - `0x00ab84`: `40008052 mov w0, #2` + `0x00ab88`: `2000a072 movk w0, #1, lsl #16` (returns `JNI_VERSION_1_2` = `0x00010002`)
- `calculate_view_box_transform` (`0x0129dc..0x012c58`):
  - `0x012a14`: `061a271e fdiv s6, s16, s7` (`sx = vp.width / vb.width`)
  - `0x012a18`: `a318241e fdiv s3, s5, s4` (`sy = vp.height / vb.height`)
  - `0x012ab8`: `c020231e fcmp s6, s3` + `0x012abc`: `c34c231e fcsel s3, s6, s3, mi` (`meet` -> `min(sx, sy)`)
  - `0x012ac4`: `c020231e fcmp s6, s3` + `0x012ac8`: `c3cc231e fcsel s3, s6, s3, gt` (`slice` -> `max(sx, sy)`)
- `make_serval_color` (`0x013108..0x01350c`):
  - `0x0131d0`: `0a568052 mov w10, #0x2b0` (hex length bitmask `(1<<4)|(1<<5)|(1<<7)|(1<<9)`)
  - `0x013334`: `eba39052 mov w11, #0x851f` + `0x013338`: `6b3daa72 movk w11, #0x51eb, lsl #16` (`0x51eb851f` magic reciprocal for `/ 100`)
  - `0x01348c`: `9fc224f1 cmp x20, #0x930` (scans `147 * 16 = 2,352` bytes of `sr_svg__colors` at `0x048000`)
- `convert_serval_length_to_float` (`0x013548..0x013698`):
  - `0x013674`: `033547fd ldr d3, [x8, #0xe68]` ($1/\sqrt{2} = 0.70710678118654757$ at `.rodata 0x032e68`)
- `add_circle_to_path` (`0x014ce8..0x0150d0`):
  - `0x014e40`: `fd473901 ldr d1, [x8, #0xe70]` ($\kappa = 0.55191502449351057$ at `.rodata 0x032e70`)
