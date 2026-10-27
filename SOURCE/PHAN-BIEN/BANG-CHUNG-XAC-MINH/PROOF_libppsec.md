# Adversarial Proof & Mathematical Verification: `libppsec.so` (`PROOF-LIBPPSEC-V1`)

- **Target Binary**: `SOURCE/apktool-res/lib/arm64-v8a/libppsec.so` (`166,400 bytes`)
- **SHA-256**: `1815ed63470ca5e5f251f66730ca849e01ed3d1ccdbde9cb162e96d2ccfa7f2f`
- **Task ID**: `TASK_SO_058_libppsec` / `TASK-118-RECONSTRUCTION-LIBPPSEC`
- **Reconstructed Code Size**: `98,781 bytes` across 9 C++17/H files + `README_ANALYSIS.md` (`0` stubs)

## 1. AArch64 Disassembly & Binary Table Evidence (`[OBSERVED]`)
1. **Static Constructors (`.init_array 0x02b6e8` -> `0x002a10`, `0x0185fc`)**:
   - `0x002a10..0x002aa8` copies the 344-byte (`0x158`) Base64 RSA public key from `.rodata 0x0214c0` (`"sRPDexql9c6Kf8bDfPigRyfJxJXbcxgJaOVmeEk4kOoleBXz1V136VmfDu605sHkKcj4I/..."`) into `.bss 0x02c9e0` and initializes default Kid `"0"` (`0x002a80: mov w8, #0x3002; strh w8, [x1]`) at `.bss 0x02c9f8`.
   - `0x0185fc..0x018940` copies the 16-byte packet seed (`de fa ce de ad 30 30 30 30 39 35 32 37 00 91 23`) from `.rodata 0x0243bb` and decrypts `"19572"` (`0x0187d4: bl #0x4714`, `.rodata 0x0243cc ^ 0x0245f4`), storing `atoi("19572") = 19572`.
2. **Dynamic JNI Registration (`JNI_OnLoad` `0x003188` -> `0x002dbc..0x003180`)**:
   - Registers 6 native methods on `com/bytedance/pipo/sec/IlIlllIiI` (`.data 0x02c000..0x02c08f`, `mov w3, #6` at `0x002d88`): `0x00318c`, `0x003560`, `0x003960`, `0x003f2c`, `0x004288`, `0x004408`.
   - Registers 3 native methods on `com/bytedance/pipo/sec/CryptTool` (`.data 0x02c0d0..0x02c117`, `mov w3, #3` at `0x0115dc`): `encrypt([B)[B` (`0x0115ec`), `decrypt([B)[B` (`0x0117a0`), `getKid()Ljava/lang/String;` (`0x011948`).
   - Returns `0x00010004` (`JNI_VERSION_1_4` at `0x003178..0x003180`).
3. **OLLVM Opaque Predicates & MBA Identities**:
   - Quadratic Modular Inverse (`0x002b40..0x002b70`): `((0x1A0^2 + 1) * 0xA1AF286CU) == 0x0D79435EU` (mod $2^{32}$).
   - 3-Consecutive-Integers Divisibility by 6 (`0x002ee0..0x002f14`): `umulh(p, 0xAAAAAAAAAAAAAAABULL) >> 1`.
   - CRC-16/XMODEM (`0x018948..0x0189a0`): `.rodata 0x0243d2` lookup table with MBA XOR `(a | b) - (a & b)` and MBA increment `((i << 1) | 2) - (i ^ 1)`.
