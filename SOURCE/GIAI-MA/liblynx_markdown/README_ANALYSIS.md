# Forensic Analysis & Clean-Room Reconstruction of `liblynx_markdown.so`
# Phân tích Pháp y & Tái cấu trúc Sạch (Clean-Room) `liblynx_markdown.so`

## 1. Binary Identification / Định danh Nhị phân (`OBSERVED`)

| Property / Thuộc tính | Value / Giá trị |
|---|---|
| **File Path / Đường dẫn** | `SOURCE/apktool-res/lib/arm64-v8a/liblynx_markdown.so` |
| **File Size / Dung lượng** | `247,888 bytes` (`242.08 KB`) |
| **SHA-256** | `3f238dfc468cd0b314eb0b828565c3353dba165c20dab0bb76d9957760bd9a2d` |
| **Architecture / Kiến trúc** | ELF 64-bit LSB shared object, ARM aarch64 |
| **Java Class Bound / Lớp Java** | `com.bytedance.xelement.markdown.MarkdownDocument` |
| **Exported JNI Symbols** | `38` (`STT_FUNC` @ `0x00d300..0x018420`) |
| **Total `.dynsym` Symbols** | `131` (`38` exports + `93` imports from `liblynxbase.so`, `libtttext_lite.so`, `libc++_shared.so`, `libc.so`) |

---

## 2. ELF64 Section Layout / Bố cục Phân đoạn ELF64 (`OBSERVED`)

| Section | Virtual Address | File Offset | Size (Bytes) | Role / Vai trò |
|---|---|---|---|---|
| `.dynsym` | `0x000320` | `0x000320` | `3,168` (`0x000c60`) | 132 symbol table entries (131 named symbols) |
| `.rodata` | `0x005020` | `0x005020` | `2,696` (`0x000a88`) | JNI signatures, style keys, Roman numerals, Markdown delimiters |
| `.text` | `0x00c000` | `0x00c000` | `168,700` (`0x0292fc`) | 38 JNI entry points + Discount/GFM parser + TTText layout & draw |
| `.plt` | `0x035300` | `0x035300` | `1,456` (`0x0005b0`) | 89 PLT thunks (`0x035320..0x0358a0`) |
| `.data.rel.ro` | `0x038000` | `0x038000` | `2,720` (`0x000aa0`) | Vtables (`ResourceLoader`, `EventListener`, `BufferCanvasHelper`, `RunDelegate`), Roman numeral & font-weight tables |
| `.got.plt` | `0x038c70` | `0x038c70` | `736` (`0x0002e0`) | Global Offset Table for PLT |
| `.data` | `0x03c000` | `0x03c000` | `96` (`0x000060`) | Initialized static state |
| `.bss` | `0x03c060` | `0x03c060` | `136` (`0x000088`) | `MarkdownJNIHelper` singleton (`0x03c068`, guard @ `0x03c060`) + syntax tag map (`0x03c0d0`, guard @ `0x03c0c8`) |

---

## 3. Core ABI Layouts & AArch64 Opcode Verification / Bố cục ABI & Xác minh Opcode (`OBSERVED`)

### 3.1 `MarkdownDocument` (`sizeof = 0xe88 = 3,720 bytes` @ `0x00d328`)
- Allocated in `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeCreateInstance` (`0x00d300`):
  - `0x00d328`: `5281d100` -> `mov w0, #0xe88` (`3,720 bytes`)
  - `0x00d334`: `9400a003` -> `bl 0x35340` (`operator new(unsigned long)`)
  - `0x00d33c`: `52800300` -> `mov w0, #0x18` (`24 bytes` `MarkdownResourceLoader`, vtable `@ 0x038018`)
  - `0x00d568`: `52a7f008` -> `mov w8, #0x3f800000` (`1.0f` default font scale stored at `[x19, #0xd20]`)
  - `0x00d5a4`: `f9070275` -> `str x21, [x19, #0xe00]` (`doc->resource_loader_`)
  - `0x00d5c8`: `94009f5e` -> `bl 0x35340` (`24 bytes` `MarkdownEventListener`, vtable `@ 0x038080`)
  - `0x00d634`: `f9070675` -> `str x21, [x19, #0xe08]` (`doc->event_listener_`)

### 3.2 Embedded Discount (`MMIOT`) + ByteDance GFM Parser (`0x00e718..0x00feb4`)
- In `Java_com_bytedance_xelement_markdown_MarkdownDocument_nativeParse` (`0x00e718`):
  - `0x00e9c0..0x00eaec`: UTF-8 codepoint boundary slicer converting character indices `(char_start, char_end)` into exact UTF-8 byte offsets.
  - `0x00eaec..0x00eb30`: Allocates Discount `MMIOT` (`calloc(0x98, 1)` = `152 bytes` @ `0x00eaf0`) and root `Paragraph` (`calloc(0x78, 1)` = `120 bytes` @ `0x00eb0c`), storing David Parsons' Discount magic number **`0x19600731`** (`mov w29, #0x731; movk w29, #0x1960, lsl #16` -> `0x19600731` @ `0x00eaec..0x00eaf8`, `str w29, [x22]` @ `0x00eb30`).

### 3.3 `nativeMarkdownOffsetToChar` Binary Search (`0x0142d4..0x014354`)
- Searches `doc->offset_map_` (`[x2, #0xe58..0xe60]`) of `16-byte` `MarkdownOffsetRange` structs (`asr x10, x10, #4` @ `0x0142e4`, `{int32_t md_start, md_end, char_start, char_end}`) using branchless `csel` binary search (`0x0142e8..0x01430c`).

### 3.4 `BufferCanvasHelper` & `BufferPaintHelper` (`0x018924..0x019d80`)
- `BufferPaintHelper` (`0x01897c`): `sizeof = 0x58` (`88 bytes`), vtable `@ 0x038398`, default font family `"pingfang"` (`0x676e6166676e6970` @ `0x0189a8..0x0189b8`), default text size `14.0f` (`0x41600000` @ `0x0189bc`).
- `BufferCanvasHelper` (`0x018924`): vtable `@ 0x038148`, initial command stream buffer `malloc(0x400)` (`1,024 bytes` @ `0x011134`), serializing draw opcodes (`Save=2`, `Restore=3`, `Translate=4`, `ClipRect=8`, `DrawLine=13`, `DrawRect=14`, `DrawCircle=16`, `DrawText=19`, `DrawGlyphs=20`, `DrawRunDelegate=21`, `DrawRoundRect=26`).

---

## 4. Reconstructed Source Files / Danh mục File Tái cấu trúc (`SOURCE/GIAI-MA/liblynx_markdown/`)

| File | Description / Mô tả |
|---|---|
| [`lynx_markdown_types.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynx_markdown/lynx_markdown_types.h) | ABI structures for `MarkdownDocument` (`0xe88` B), `ttoffice::tttext`, `lynx::base`, Discount `MMIOT` (`0x98` B, magic `0x19600731`), and `MarkdownStyleSheet` |
| [`lynx_markdown_parser.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynx_markdown/lynx_markdown_parser.h) | Declarations for Discount + GFM AST parser, Roman numeral formatter, UTF-8 codepoint slicer, and binary style deserializer |
| [`lynx_markdown_parser.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynx_markdown/lynx_markdown_parser.cpp) | Full implementation of Markdown block/inline parser, Roman numerals (`0x038668..0x038750`), font weight table (`0x0389d0..0x038a20`), and style sheet parser |
| [`lynx_markdown_layout_draw.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynx_markdown/lynx_markdown_layout_draw.h) | Declarations for `BufferCanvasHelper`, `RunDelegate` subclasses, `LayoutMarkdownDocument`, hit-testing, and typewriter cursor |
| [`lynx_markdown_layout_draw.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynx_markdown/lynx_markdown_layout_draw.cpp) | Full implementation of `ttoffice::tttext` runtime, `BufferCanvasHelper`, `ConvertMarkdownOffsetToChar`, selection rects, and state inheritance |
| [`lynx_markdown_jni.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynx_markdown/lynx_markdown_jni.h) | Prototypes for all 38 exported `Java_com_bytedance_xelement_markdown_MarkdownDocument_*` JNI functions |
| [`lynx_markdown_jni.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynx_markdown/lynx_markdown_jni.cpp) | Complete implementation of all 38 exported JNI methods (`0x00d300..0x018420`) |
| [`lynx_markdown_interface.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynx_markdown/lynx_markdown_interface.h) | Public umbrella header and self-test entry point |
| [`lynx_markdown_pseudocode.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/liblynx_markdown/lynx_markdown_pseudocode.cpp) | End-to-end self-verification harness for `liblynx_markdown.so` |
