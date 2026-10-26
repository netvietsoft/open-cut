# Deep Architectural & AArch64 Binary Analysis: `libanimax_napi.so`
# Phân Tích Kiến Trúc & Nhị Phân AArch64 Chuyên Sâu: `libanimax_napi.so`

## 1. Binary Overview / Tổng Quan Tệp Nhị Phân
- **Library Name / Tên thư viện**: `libanimax_napi.so` (Lynx AnimaX NAPI Composition Element Bridge)
- **File Size / Dung lượng**: `84,064 bytes` (`25 ELF64 sections`)
- **SONAME**: `libanimax_napi.so`
- **Dependencies (`DT_NEEDED`)**: `libanimax.so`, `libnapi.so`, `liblynxbase.so`, `libm.so`, `libdl.so`, `libc.so`
- **Key Sections / Các phân đoạn chính**:
  - `.rodata`: `0x003198..0x00348f` (`760 bytes`: 210 primes `2..1297` at `0x0031a0..0x003343`, NAPI strings & error formats at `0x003200..0x00348f`)
  - `.text`: `0x008000..0x00c448` (`17,480 bytes`, `4,370` AArch64 instructions)
  - `.plt`: `0x00c450..0x00c9dc` (`1,420 bytes`, `87` PLT jump slots)
  - `.data.rel.ro`: `0x010000..0x0103f7` (`1,016 bytes`, `8` vtables & Napi instance data keys)
  - `.init_array`: `0x010408..0x01040f` (`8 bytes` -> `0x00803c` `__cxx_global_var_init`)
  - `.data`: `0x014000..0x014027` (`40 bytes` `NapiModuleXxDescriptor` for `"animax"`)

---

## 2. Core Subsystems & Exact AArch64 Opcode Proofs / Các Phân Hệ Cốt Lõi & Bằng Chứng Opcode AArch64

### 2.1 NAPI Module Registration (`0x00803c..0x008364`, `.data` `0x014000..0x014027`)
- At `.init_array` (`0x010408`), `__cxx_global_var_init` (`0x00803c..0x008044`) executes:
  ```asm
  0x00803c: 60000090 adrp x0, #0x14000
  0x008040: 00000091 add  x0, x0, #0
  0x008044: 13110014 b    #0xc490 ; napi_module_register_xx
  ```
- `.data` `0x014000..0x014027` (`40 bytes = 0x28` `NapiModuleXxDescriptor`):
  - `+0x00`: `nm_version = 1` (`01 00 00 00`)
  - `+0x04`: `nm_flags = 0` (`00 00 00 00`)
  - `+0x08`: `nm_filename = 0x003352` (`"../../platform/harmony/animax/src/main/cpp/src/napi/animax_module.cc"`)
  - `+0x10`: `nm_register_func = 0x008048` (`RegisterAnimaXModule`)
  - `+0x18`: `nm_modname = 0x003200` (`"animax"`)
  - `+0x20`: `nm_priv = 0`
- `RegisterAnimaXModule` (`0x008048..0x008364`) checks `exports.Has("CompositionElement")` (`0x003207`), queries `env.GetInstanceData(0x10150)` (`0x0080a8`) and `env.GetInstanceData(0x10148)` (`0x0080d8`), defines the `"CompositionElement"` class (`len = 18 = 0x12`) with 3 instance methods (`"updateLayerProperty"` @ `0x0099c4`, `"setResourceProperty"` @ `0x009fd0`, `"play"` @ `0x00a2ac`), and attaches `"CompositionElement"` to `exports`.

### 2.2 Color Property Bitmask (`0x009c6c..0x009c98`) & `"**"` KeyPath Splitting (`0x009d5c..0x009ea0`)
- Inside `UpdateLayerPropertyCallback` (`0x0099c4..0x009f10`), the property type `w20` is tested against a 19-bit window (`201..219`) plus explicit type `103` (`0x67`):
  ```asm
  0x009c6c: 883e0012 and  w8, w20, #0xffff
  0x009c70: 09250351 sub  w9, w8, #0xc9
  0x009c74: 3f490071 cmp  w9, #0x12
  0x009c78: c8000054 b.hi #0x9c90
  0x009c7c: 28008052 mov  w8, #1
  0x009c80: 0821c91a lsl  w8, w8, w9
  0x009c84: aa008052 mov  w10, #5
  0x009c88: 8a00a072 movk w10, #4, lsl #16
  0x009c8c: 1f010a6a tst  w8, w10
  0x009c90: 01010054 b.ne #0x9cb0
  0x009c94: 1f9d0171 cmp  w8, #0x67
  0x009c98: 41010054 b.ne #0x9cc0
  ```
  Since `w10 = 0x00040005 = (1 << 0) | (1 << 2) | (1 << 18)`, the color fast-path triggers iff `(prop_type & 0xFFFF) in {103, 201, 203, 219}`.
- The layer KeyPath string is split by `"**"` (`.rodata` `0x0033bc`, length `2`) via `std::string::find("**", pos, 2)` (`0x009dc0`), constructing `lynx::animax::AnimaXKeyPath(std::vector<std::string>&&)` (`0x009dd8`).

### 2.3 Restricted Double IEEE-754 Finite Validation (`0x00bed0..0x00bf48`)
- Validates JS number arguments against `NaN` and `±Infinity` using `0x7ff0000000000000ULL`:
  ```asm
  0x00bef8: 08feefd2 mov   x8, #0x7ff0000000000000
  0x00befc: 01c0601e fabs  d1, d0
  0x00bf00: 0020601e fcmp  d0, d0
  0x00bf04: 0201679e fmov  d2, x8
  0x00bf08: 2474621e fccmp d1, d2, #4, vc
  0x00bf0c: 01010054 b.ne  #0xbf2c
  ```
  If `d0` is `NaN` or `fabs(d0) == +Inf`, throws a JS `TypeError` formatted with `"Invalid type for argument %d, expecting: Restricted Double"` (`0x0033cd` + `0x003425`).

### 2.4 CityHash64 (`0x008718..0x0089fc`, `0x0096b4..0x009714`) & NEON Popcount (`0x00c3c0..0x00c3d0`)
- Full Google/LLVM libc++ `CityHash64` (`__murmur2_or_cityhash<unsigned long, 64>`) with `k0 = 0xc3a5c85c97cb3127ULL`, `k1 = 0xb492b66fbe98f273ULL`, `k2 = 0x9ae16a3b2f90404fULL`, and `kMul = 0x9ddfea08eb382d69ULL`.
- Power-of-2 bucket count test via AArch64 NEON vector popcount (`fmov d0, x1; cnt v0.8b, v0.8b; uaddlv h0, v0.8b; fmov w8, s0` @ `0x00c3c0..0x00c3cc`) and `std::__ndk1::__next_prime(size_t)` (`0x00bfec..0x00c1dc`) backed by the 210-entry `uint16_t` prime table at `.rodata` `0x0031a0..0x003343`.

---

## 3. Reconstructed Files / Danh Sách Tệp Tái Dựng (`101,654 bytes`, `0 stubs`)
1. [`animax_napi_types.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libanimax_napi/animax_napi_types.h) (`19,252 bytes`)
2. [`animax_napi_hash_stl.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libanimax_napi/animax_napi_hash_stl.h) (`4,776 bytes`)
3. [`animax_napi_hash_stl.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libanimax_napi/animax_napi_hash_stl.cpp) (`11,630 bytes`)
4. [`animax_napi_task_value.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libanimax_napi/animax_napi_task_value.h) (`6,230 bytes`)
5. [`animax_napi_task_value.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libanimax_napi/animax_napi_task_value.cpp) (`12,082 bytes`)
6. [`animax_napi_composition.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libanimax_napi/animax_napi_composition.h) (`9,465 bytes`)
7. [`animax_napi_composition.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libanimax_napi/animax_napi_composition.cpp) (`15,117 bytes`)
8. [`animax_napi_interface.h`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libanimax_napi/animax_napi_interface.h) (`4,355 bytes`)
9. [`animax_napi_pseudocode.cpp`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/GIAI-MA/libanimax_napi/animax_napi_pseudocode.cpp) (`18,747 bytes`)
