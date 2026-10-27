# Adversarial Verification Proof: `liblynxbase.so` (`TASK-123-RECONSTRUCTION-LIBLYNXBASE`)
# Bằng Chứng Xác Minh Đối Kháng: `liblynxbase.so` (`TASK_SO_121_liblynxbase`)

## 1. Binary & Reconstruction Summary / Tóm Tắt Nhị Phân & Tái Tạo
- **Target Binary**: `SOURCE/apktool-res/lib/arm64-v8a/liblynxbase.so` (`232,080 bytes`, SHA-256: `6f73cb643285f2b6f59960dde9c053141e6f546429faaf7fa66bbae9e1a0d61d`)
- **Dynamic Symbols**: `449` total (`326` defined `STT_FUNC` + `6` defined `STT_OBJECT`)
- **Reconstructed C++17/H Size**: `188,263 bytes` (`188.26 KB` across 9 files in `SOURCE/GIAI-MA/liblynxbase/`, `0` stubs)

## 2. Six-Gate Verification Evidence / Bằng Chứng 6 Cổng Kiểm Định
1. **Gate 1 (Code Volume $\ge 40\text{ KB}$)**: `188,263 bytes` (`470.6%` of minimum threshold).
2. **Gate 2 (AArch64 Opcode Disassembly Matching)**:
   - `JNI_OnLoad` (`0x01403c..0x01406c`): `0x528000C0` (`mov w0, #6`), `0x72A00020` (`movk w0, #1, lsl #16` -> `0x00010006`).
   - `InitVM` (`0x022e40..0x022e44`): `0xF9012100` (`str x0, [x8, #0x240]` storing `JavaVM*` at `.bss 0x038240`).
   - `GetAPILevel` (`0x023d3c..0x023d6c`): `0x12800000` (`mov w0, #-1` fallback at `0x023d6c`).
   - `TimePoint::CurrentWallTime` (`0x01de68..0x01de6c`): `0x52807D08` (`mov w8, #0x3e8`), `0x9B087C00` (`mul x0, x0, x8`).
   - `MD5_Transform` (`0x01e3ac`) & `lynx::base::md5` (`0x01eff8`): `0x52948F0D` (`mov w13, #0xa478`), `0x3DC09500` (`ldr q0, [x8, #0x250]`).
   - `js_dtoa` (`0x029574`): `0xD2EFFE08` (`mov x8, #0x7ff0000000000000`).
   - `CurrentSystemTimeMilliseconds` (`0x02d538`) & `CurrentTimeMilliseconds` (`0x02d568..0x02d56c`): `0x9B487C08` (`smulh x8, x0, x8`), `0x9352FD09` (`asr x9, x8, #0x12`).
3. **Gate 3 (Mathematical & Algorithmic Proofs)**:
   - Signed 64-bit reciprocal division by `1,000` (`0x20C49BA5E353F7CFULL`, shift `7`) and `1,000,000` (`0x431BDE82D7B634DBULL`, shift `18`).
   - RFC 1321 MD5 (`[0, 0, 0x67452301, 0xEFCDAB89]` at `.rodata 0x00d250`, `0x1032547698BADCFEULL`) and `CityHash64` (`k0=0xC3A5C85C97CB3127ULL`, `k1=0xB492B66FBE98F273ULL`, `k2=0x9AE16A3B2F90404FULL`).
   - `DataURIUtil::DecodeDataURI` 8-byte little-endian marker `0x2C3436657361623BULL` (`";base64,"`) and `js_dtoa` unsigned division by 10 magic `0xCCCCCCCCCCCCCCCDULL`.
4. **Gate 4 (ABI Struct Offsets)**: Verified `RefCountedStringImpl` (`56 bytes = 0x38`, vtable @ `0x034768`, `Unsafe::kEmptyString` @ `0x0382f8`) and `Md5Context`.
5. **Gate 5 (Demangled Symbols)**: `449` dynamic symbols (`326` `STT_FUNC` + `6` `STT_OBJECT`).
6. **Gate 6 (Automated Parity Test)**: `verify_liblynxbase` in `SOURCE/scripts/verify_reconstruction_suite.py`.
