# Forensic & Mathematical Verification Proof — `liblynx_markdown.so`
# Bằng chứng Xác minh Pháp yNhị phân & Toán học — `liblynx_markdown.so`

- **Binary Target / Đích nhị phân**: `SOURCE/apktool-res/lib/arm64-v8a/liblynx_markdown.so` (`247,888 bytes`)
- **SHA-256**: `3f238dfc468cd0b314eb0b828565c3353dba165c20dab0bb76d9957760bd9a2d`
- **Task ID**: `TASK-125-RECONSTRUCTION-LIBLYNX-MARKDOWN` (`TASK_SO_120_liblynx_markdown`)
- **Reconstructed C++17 Size / Dung lượng C++17 tái dựng**: `263,879 bytes` (`9` C++17/H files + `README_ANALYSIS.md`, `0` stubs)

---

## 1. AArch64 Disassembly & Opcode Proofs / Bằng chứng Disassembly AArch64 (`OBSERVED`)

1. **`Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeCreateInstance` (`0x00d300`, `880 B`)**:
   - `0x00d300`: `d10243ff` (`sub sp, sp, #0x90`)
   - `0x00d328`: `5281d100` (`mov w0, #0xe88` — allocates `3,720-byte` `MarkdownDocument`)
   - `0x00d33c`: `52800300` (`mov w0, #0x18` — allocates `24-byte` `MarkdownResourceLoader` with vtable `@ 0x038018`)
   - `0x00d568`: `52a7f008` (`mov w8, #0x3f800000` — stores `1.0f` default font scale at `[x19, #0xd20]`)
   - `0x00d5a4`: `f9070275` (`str x21, [x19, #0xe00]` — stores `resource_loader_`)
   - `0x00d634`: `f9070675` (`str x21, [x19, #0xe08]` — stores `event_listener_` with vtable `@ 0x038080`)
2. **`Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeParse` (`0x00e718`, `6,044 B`)**:
   - `0x00e718`: `fc190fe8` (`str d8, [sp, #-0x70]!`)
   - `0x00eaec`: `5280e63d` (`mov w29, #0x731`)
   - `0x00eaf0`: `52801300` (`mov w0, #0x98` — `calloc(0x98, 1)` for Discount `MMIOT`)
   - `0x00eaf8`: `72a32c1d` (`movk w29, #0x1960, lsl #16` -> `0x19600731` Discount `VALID_MMIOT` magic constant)
   - `0x00eb0c`: `52800f00` (`mov w0, #0x78` — `calloc(0x78, 1)` for root `Paragraph`)
   - `0x00eb30`: `b90002dd` (`str w29, [x22]` — writes `0x19600731` to `mmiot->magic`)
3. **`Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeMarkdownOffsetToChar` (`0x0142d4`, `132 B`)**:
   - `0x0142d4`: `f9472c48` (`ldr x8, [x2, #0xe58]`)
   - `0x0142d8`: `f9473049` (`ldr x9, [x2, #0xe60]`)
   - `0x0142e4`: `9344fd4a` (`asr x10, x10, #4` — `16-byte` `MarkdownOffsetRange` struct `{md_start, md_end, char_start, char_end}`)
   - `0x014304`: `9a8bd14a` (`csel x10, x10, x11, le`)
   - `0x014308`: `9a88d188` (`csel x8, x12, x8, le`)
4. **`Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeAllowBreakAroundPunctuation` (`0x01562c`, `16 B`)**:
   - `0x01562c`: `72001c7f` (`tst w3, #0xff`)
   - `0x015630`: `1a9f07e8` (`cset w8, ne`)
   - `0x015634`: `3938e048` (`strb w8, [x2, #0xe38]`)
   - `0x015638`: `d65f03c0` (`ret`)
5. **`BufferCanvasHelper::CreatePaint` (`0x01897c`, `100 B`)**:
   - `0x018980`: `52800b00` (`mov w0, #0x58` — `88-byte` `BufferPaintHelper` with vtable `@ 0x038398`)
   - `0x0189a8..0x0189b4`: `d28d2e08 f2acedc8 f2cc2cc8 f2ecedc8` (`0x676e6166676e6970` = `"pingfang"` default font family)
   - `0x0189bc`: `52a82c08` (`mov w8, #0x41600000` = `14.0f` default font size)
