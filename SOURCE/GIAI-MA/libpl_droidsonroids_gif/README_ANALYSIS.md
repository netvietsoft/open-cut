# Deep Native Reconstruction Report — `libpl_droidsonroids_gif.so`
# Báo Cáo Tái Dựng Mã Gốc Chuyên Sâu — `libpl_droidsonroids_gif.so`

> **Target Binary / Nhị phân mục tiêu**: `libpl_droidsonroids_gif.so` (`42,464 bytes`, ELF64 AArch64)  
> **Task ID**: `TASK-096-RECONSTRUCTION-LIBPL_DROIDSONROIDS_GIF` (`TASK_SO_039_libpl_droidsonroids_gif`)  
> **Evidence Classification / Phân loại bằng chứng**: `OBSERVED` (100% Direct AArch64 Opcode Disassembly & `.rodata`/`.data` Inspection)  
> **Reconstruction Status / Trạng thái**: `VERIFIED_AND_ACCEPTED` (8 C++17 & Header Files, Zero Stubs)

---

## 1. ELF64 Binary & Section Geometry (Hình Học Phân Đoạn ELF64)

| Section | Virtual Address (`sh_addr`) | File Offset (`sh_offset`) | Size (`sh_size`) | Role (EN / VN) |
|---|---|---|---|---|
| `.dynsym` | `0x0002f8` | `0x0002f8` | `0x000918` (`2,328 B`) | `97` symbols (`[001]..[051]` imports, `[052]..[096]` exports) |
| `.dynstr` | `0x001178` | `0x001178` | `0x000c95` (`3,221 B`) | Dynamic symbol string table / Bảng chuỗi biểu tượng động |
| `.rela.dyn` | `0x001e10` | `0x001e10` | `0x0000d8` (`216 B`) | `9` `R_AARCH64_RELATIVE` relocations (`rewind` pointers & `.fini_array`) |
| `.rela.plt` | `0x001ee8` | `0x001ee8` | `0x0004c8` (`1,224 B`) | `51` `R_AARCH64_JUMP_SLOT` imports (`AndroidBitmap_*`, `glTex*`, `ANativeWindow_*`) |
| `.rodata` | `0x0023b0` | `0x0023b0` | `0x0007da` (`2,010 B`) | JNI signatures, error strings, 256-entry grayscale LUT (`0x002860`), interlace (`0x002b60`) & LZW bitmasks (`0x002b70`) |
| `.eh_frame_hdr` | `0x002b8c` | `0x002b8c` | `0x00032c` (`812 B`) | DWARF unwind binary search header |
| `.eh_frame` | `0x002eb8` | `0x002eb8` | `0x00118c` (`4,492 B`) | DWARF call frame information |
| `.text` | `0x004044` | `0x004044` | `0x005640` (`22,080 B`) | `5,520` AArch64 instructions across GIFLIB 5.1.4 + `android-gif-drawable` |
| `.plt` | `0x009690` | `0x009690` | `0x000350` (`848 B`) | `51` PLT trampolines (`0x0096b0..0x0099d0`) |
| `.data.rel.ro` | `0x00d9e0` | `0x0099e0` | `0x000030` (`48 B`) | `DecodeSource` template for `openStream` (`streamRewind` `0x005980` at `0x00da00`) |
| `.got` / `.got.plt` | `0x00dc00` | `0x009c00` | `0x0001d0` (`464 B`) | Global Offset Table |
| `.data` | `0x011dd0` | `0x009dd0` | `0x000018` (`24 B`) | `0x011dd0 = 0x00010006` (`JNI_VERSION_1_6`), `0x011dd8 -> "GifIOThread"` |
| `.bss` | `0x011de8` | `0x009de8` | `0x000018` (`24 B`) | `0x011de8 = descriptorFieldID`, `0x011df0 = g_jvm`, `0x011df8 = g_defaultCmap` |

---

## 2. Exact ABI Structure Layouts (Bố Cục Struct ABI Chuẩn Xác)

1. **`GifInfo` (`sizeof = 0xa8 = 168 bytes`, `malloc(0xa8)` @ `0x007a64`)**:
   - `+0x00`: `DestructorFunc destructor` (`releaseTexImageDescriptor` @ `0x008aa8` or `releaseSurfaceDescriptor` @ `0x0092f4`)
   - `+0x08`: `GifFileType* gifFilePtr`
   - `+0x10`: `uint64_t originalWidth`
   - `+0x18`: `uint64_t originalHeight`
   - `+0x20`: `uint64_t sampleSize` (initialized to `1`)
   - `+0x28`: `int64_t lastFrameRemainder` (initialized to `-1`)
   - `+0x30`: `int64_t nextStartTime`
   - `+0x38`: `uint64_t currentIndex`
   - `+0x40`: `FrameInfo* infos` (`0x18 = 24 bytes` per frame: `+0x00 disposalMethod`, `+0x08 duration`, `+0x10 transColor`)
   - `+0x48`: `argb* backupPtr` (allocated on demand when `disposalMethod == DISPOSE_PREVIOUS (3)`)
   - `+0x50`: `int64_t startPos`
   - `+0x58`: `uint8_t* rasterBits`
   - `+0x60`: `uint64_t rasterSize`
   - `+0x68`: `char* comment` (capped at `0x800 = 2048 bytes` @ `0x004dd0`)
   - `+0x70`: `uint64_t loopCount` (Netscape 2.0 / AnimExts 1.0 loop count)
   - `+0x78`: `uint64_t currentLoop`
   - `+0x80`: `RewindFunc rewindFunction` (`0x00593c`, `0x005980`, `0x005a14`, `0x005a30`)
   - `+0x88`: `float speedFactor` (initialized to `1.0f = 0x3f800000` @ `0x007aa8`)
   - `+0x8c`: `uint32_t stride`
   - `+0x90`: `int64_t sourceLength`
   - `+0x98`: `bool isOpaque`
   - `+0xa0`: `void* frameBufferDescriptor` (`TexImageDescriptor*` `0x40 B` or `SurfaceDescriptor*` `0xd0 B`)

2. **`GifFileType` (`0x78 = 120 bytes`, `calloc(1, 0x78)` @ `0x0066d4`) & `GifFilePrivateType` (`0x6160 = 24,928 bytes`, `calloc(1, 0x6160)` @ `0x0066f0`)**:
   - `GifFilePrivateType` embeds the 256-byte sub-block buffer `Buf` (`+0x0060`), 4096-byte LZW decode `Stack` (`+0x0160`), 4096-byte `Suffix` table (`+0x1160`), and 4096-entry `uint32_t Prefix` table (`+0x2160..+0x615f`, initialized to `NO_SUCH_CODE = 0x1002` via NEON `dup v0.4s, w9` @ `0x006df4..0x006e1c`).
