# Technical Analysis & 1:1 C++17 Reconstruction: `libtailor.so` (ByteDance Tailor HPROF Heap Dump Stream Cropper & xHook Engine)
# Phân Tích Kỹ Thuật & Tái Tạo C++17 1:1: `libtailor.so` (Bộ Máy Cắt Gọt Luồng Nhị Phân HPROF ByteDance Tailor & xHook)

---

## 1. Binary Identity & ELF64 Section Layout (Định Danh Nhị Phân & Bố Cục Phân Đoạn ELF64)

- **File Path**: `extracted/lib/arm64-v8a/libtailor.so`
- **File Size**: `84,136 bytes` (`0x148a8` bytes)
- **Architecture**: `AArch64` (`EM_AARCH64 = 183`, Little-Endian ELF64 shared object)
- **SONAME**: `libtailor.so`
- **Dynamic Dependencies (`DT_NEEDED`, 5 libraries)**:
  1. `liblog.so` (`__android_log_print`, `__android_log_vprint`)
  2. `libz.so` (`deflateInit2_`, `deflate`, `deflateEnd`)
  3. `libc++_shared.so` (`std::__ndk1::basic_string`, `operator new`, `operator delete`)
  4. `libm.so`
  5. `libc.so` (`open`, `write`, `fopen`, `fwrite`, `fflush`, `fclose`, `mprotect`, `regcomp`, `regexec`, `dl_iterate_phdr`, `sigaction`, `siglongjmp`, `__system_property_get`, etc.)
- **Dynamic Symbol Table (`.dynsym`)**: `175` entries total (`83` imported / undefined + `92` exported symbols `[083..174]`: `63` exported functions + `29` exported objects/vtables/typeinfo/globals).
- **Relocations**:
  - `.rela.dyn` (`0x002460..0x002a78`, `1,560 bytes`, `65` entries: `26 R_AARCH64_RELATIVE`, `33 R_AARCH64_ABS64`, `6 R_AARCH64_GLOB_DAT`)
  - `.rela.plt` (`0x002a78..0x0035e8`, `2,928 bytes`, `122` `R_AARCH64_JUMP_SLOT` entries)

---

## 2. Core Subsystem Architecture (Kiến Trúc Các Hệ Thống Con Cốt Lõi)

| # | Subsystem | Address Range (`.text` / `.data.rel.ro`) | Exported Symbols | Reconstructed C++17 Module |
|---|---|---|---|---|
| 1 | **JNI Bridge & Crash Log Discovery (`com/bytedance/tailor/Tailor`)** | `0x00d868..0x00e7a8`, `.data.rel.ro` `0x0177f8..0x01786f` | `JNI_OnLoad`, `JNI_OnUnload`, `open_tailor`, `close_tailor`, `crop_hprof`, `getCrashLogFiles`, `clearCrashLogFiles` | `tailor_xhook_jni.h`, `tailor_xhook_jni.cpp` |
| 2 | **Streaming `Writer` Hierarchy (`Writer`, `LibzWriter`, `FileWriter`)** | `0x00d484..0x00d864`, `0x00da34..0x00daf8`, `.data.rel.ro` `0x017888..0x0178e7` | `Writer::Writer`, `Writer::fillByte`, `Writer::fillZero`, `Writer::fill`, `Writer::fillInt`, `Writer::flush`, `FileWriter::FileWriter`, `_ZTV6Writer`, `_ZTI6Writer`, `_ZTI10FileWriter` | `tailor_stream_writer.h`, `tailor_stream_writer.cpp` |
| 3 | **Circular/Sliding `Stream` Buffer (`256 KB` initial capacity)** | `0x00aaa4..0x00af40`, `.data.rel.ro` `0x017870..0x017887` | `Stream::Stream`, `Stream::~Stream`, `Stream::peek`, `Stream::peekByte`, `Stream::peekShort`, `Stream::peekInt`, `Stream::reset`, `Stream::flush`, `Stream::handle`, `Stream::copy`, `Stream::skip`, `Stream::fillZero`, `Stream::isAvailable`, `Stream::seek`, `_ZTV6Stream` | `tailor_stream_writer.h`, `tailor_stream_writer.cpp` |
| 4 | **HPROF 1.0.2/1.0.3 Stream Cropper Engine (`Tailor`)** | `0x00b068..0x00c6d4`, `0x00dc88..0x00dda4`, `.data.rel.ro` `0x0178a0..0x0178b7` | `Tailor::Tailor`, `Tailor::~Tailor`, `Tailor::init`, `Tailor::tailor_XHOOK`, `initKeepClassIDSet`, `clearCache`, `tailor_STRING`, `tailor_LOAD_CLASS`, `tailor_HEAP_DUMP_SEGMENT`, `tailor_INSTANCE_DUMP_WRITE`, `tailor_HEAP_DUMP_END`, `tailor_CLASS_DUMP`, `tailor_INSTANCE_DUMP`, `tailor_OBJECT_ARRAY_DUMP`, `tailor_PRIMITIVE_ARRAY_DUMP`, `shrinkField`, `bytesForTypeSignature`, `bytesForType` | `tailor_hprof_engine.h`, `tailor_hprof_engine.cpp` |
| 5 | **Embedded xHook PLT/GOT Hooking Engine & Chained `Set`** | `0x007fd8..0x00aa4c`, `0x00e8e8..0x00eac0` | `xhook_*` (6), `xh_core_*` (6), `xh_elf_*` (3), `xh_util_*` (3), `createSet`, `hash`, `setContains`, `setInsert`, `clearSet`, `open_proxy`, `write_proxy`, `fill_Regex`, `try_to_hook` | `tailor_xhook_jni.h`, `tailor_xhook_jni.cpp` |

---

## 3. Exact AArch64 Opcode & Mathematical Proofs (Bằng Chứng Opcode AArch64 & Toán Học)

1. **`JNI_OnLoad` (`0x00e650..0x00e744`) & `JNINativeMethod[5]` (`0x0177f8..0x01786f`)**:
   - `0x00e668`: `c2 00 80 52` (`mov w2, #6`), `0x00e674`: `22 00 a0 72` (`movk w2, #1, lsl #16` -> `JNI_VERSION_1_6 = 0x00010006`).
   - Queries `"ro.build.version.sdk"` via `__system_property_get` and stores `atoi(sdk_str)` in `BUILD_VERSION_SDK_INT` (`.bss` `0x01c2a0`).
   - Registers `5` native methods (`0x00e730: a3 00 80 52` -> `mov w3, #5`) on `"com/bytedance/tailor/Tailor"` (`0x004dda`).
2. **`Writer::Writer(__sFILE*)` (`0x00d72c..0x00d764`)**:
   - Computes `&this->strm_` at offset `0x40018` (`262,168 bytes`) via:
     - `0x00d72c: 08 00 41 91` (`add x8, x0, #0x40, lsl #12`)
     - `0x00d734: 08 61 00 91` (`add x8, x8, #0x18`)
   - Initializes gzip compression via `deflateInit2_(&strm, 1, 8, 12, 4, 0, "1.2.8", 0x70)` (`level = 1`, `method = Z_DEFLATED (8)`, `windowBits = 12` (`4 KB` window), `memLevel = 4`, `sizeof(z_stream) = 0x70 = 112 bytes`).
3. **`Stream::Stream(Writer*)` (`0x00aab0..0x00aae4`) & `Stream::peek` (`0x00ab74..0x00aba4`)**:
   - Allocates `256 KB` (`0x00aabc: 88 00 a0 52` -> `mov w8, #0x40000`) circular/sliding HPROF buffer.
   - `Stream::peek(offset, count)` decodes big-endian integers via `0x00ab94: 20 21 00 aa` (`orr x0, x9, x0, lsl #8`).
4. **`hash(const char*)` (`0x00e904..0x00e92c`)**:
   - Computes `h = (h * 33 + c) & 0x3FF` (`1024` buckets) via `0x00e918: 20 15 00 0b` (`add w0, w9, w0, lsl #5`) and `0x00e928: 00 24 40 92` (`and x0, x0, #0x3ff`).
5. **`xh_util_flush_instruction_cache` (`0x00ea30..0x00eac0`)**:
   - Reads cache line sizes via `0x00ea48: 29 00 3b d5` (`mrs x9, ctr_el0`), cleans data cache by VA to PoU via `0x00ea70: 2a 7b 0b d5` (`dc cvau, x10`), barriers via `0x00ea80: 9f 3b 03 d5` (`dsb ish`), invalidates instruction cache by VA to PoU via `0x00eaa8: 29 75 0b d5` (`ic ivau, x9`), and synchronizes via `0x00eabc: df 3f 03 d5` (`isb`).
