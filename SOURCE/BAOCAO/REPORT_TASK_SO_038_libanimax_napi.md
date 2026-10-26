# Reconstruction Report: `libanimax_napi.so` (`TASK_SO_038_libanimax_napi` / `TASK-106`)
# Báo Cáo Tái Dựng Mã Nguồn: `libanimax_napi.so`

- **Status / Trạng thái**: `VERIFIED_AND_ACCEPTED` (`100%`)
- **Binary Size / Dung lượng nhị phân**: `84,064 bytes` (`25 ELF64 sections`)
- **Reconstructed Code Size / Dung lượng mã nguồn tái dựng**: `101,654 bytes` (`9 C++17 & Header files`, `0 stubs`)
- **Adversarial Proof / Bằng chứng đối kháng**: [`PROOF_libanimax_napi.json`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/PHAN-BIEN/BANG-CHUNG-XAC-MINH/PROOF_libanimax_napi.json) & [`PROOF_libanimax_napi.md`](file:///D:/Decompiler/App/Video/Capcut/SOURCE/PHAN-BIEN/BANG-CHUNG-XAC-MINH/PROOF_libanimax_napi.md)

## Reconstructed Subsystems / Các Phân Hệ Đã Tái Dựng
1. **NAPI Module Registration (`0x00803c..0x008364`, `.data` `0x014000..0x014027`)**:
   - `.init_array` (`0x010408` -> `0x00803c`) registers `"animax"` (`NapiModuleXxDescriptor` at `0x014000`) via `napi_module_register_xx` (`PLT 0x00c490`).
   - `RegisterAnimaXModule` (`0x008048..0x008364`) defines JS class `"CompositionElement"` (`0x003207`) with `"updateLayerProperty"` (`0x0099c4`), `"setResourceProperty"` (`0x009fd0`), and `"play"` (`0x00a2ac`).
2. **Color Property Fast-Path Bitmask (`0x009c6c..0x009c98`) & `"**"` KeyPath Splitting (`0x009d5c..0x009ea0`)**:
   - Exact bitmask `0x00040005` (`mov w10, #5; movk w10, #4, lsl #16`) over `(prop_type & 0xFFFF) - 0xC9 <= 0x12` plus `cmp w8, #0x67` matching `{103, 201, 203, 219}`.
   - Splits KeyPath strings by `"**"` (`0x0033bc`) into `lynx::animax::AnimaXKeyPath(std::vector<std::string>&&)`.
3. **Restricted Double Finite Check (`0x00bed0..0x00bf48`) & `ConvertToAnimaXValueParam` (`0x008430..0x008548`)**:
   - Validates `!isnan(d0) && fabs(d0) != +Inf` (`0x7ff0000000000000ULL` @ `0x00bef8..0x00bf0c`) and formats `"Invalid type for argument %d, expecting: Restricted Double"`.
   - Converts `JSValueParamDict` (`0x70` stack layout) into heap-allocated `AnimaXValueParam` (`144 bytes = 0x90`).
4. **CityHash64 (`0x008718..0x0089fc`, `0x0096b4..0x009714`), NEON Popcount (`0x00c3c0..0x00c3cc`), & 210-Entry Prime Table (`0x0031a0..0x003343`)**:
   - Full `CityHash64` (`k0..k2`, `kMul`), NEON `cnt v0.8b, v0.8b; uaddlv h0, v0.8b`, `RoundUpToPowerOfTwo` (`clz`), and `NextPrime`.
