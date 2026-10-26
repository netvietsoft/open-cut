# Adversarial Proof & Mathematical Verification: `liblynx_v8_bridge.so`
# Bằng Chứng Phản Biện & Xác Minh Toán Học: `liblynx_v8_bridge.so`

- **Binary Target**: `SOURCE/apktool-res/lib/arm64-v8a/liblynx_v8_bridge.so` (`117,008 bytes`)
- **SHA-256**: `a056a8578279f5b2aa07946891d83c060858fcdde25c31096bb3cdd09a53ad65`
- **Reconstructed Code Size**: `147,448 bytes` across 9 C++17 `.h`/`.cpp` files (`0 stubs`)
- **Task ID**: `TASK-109-RECONSTRUCTION-LIBLYNX_V8_BRIDGE` / `TASK_SO_134_liblynx_v8_bridge`

## 1. AArch64 Opcode Evidence / Bằng Chứng Mã Máy AArch64

1. **`.rodata` 7-Way Value::Kind Jump Table (`0x006300`) & Exported URL Constants (`0x006820`, `0x00682a`)**:
   - `0x006300`: `00 04 08 11 17 20 26` — indexed by `lynx::piper::Value::Kind` (`0..6`) at `0x012dd0..0x012df4` (`adr x10, #0x12df8; ldrb w11, [x9, x8]; add x10, x10, x11, lsl #2; br x10`).
   - `0x006820`: `"lynx_core\0"` (exported weak symbol `[179]`).
   - `0x00682a`: `"file://lynx\0"` (exported weak symbol `[185]`).
2. **V8 CPU Profile Node `120`-Byte (`0x78`) Stride Division (`0x00cc20..0x00cc30`)**:
   - `0x00cc20`: `0b 0f 80 52` (`mov w11, #0x78`)
   - `0x00cc2c`: `14 0d c8 9a` (`sdiv x20, x8, x11`)
3. **V8 Tagged-Pointer & Oddball Inspection (`0x00dc88..0x00dcd8`)**:
   - `0x00dc98`: `09 f1 5f f8` (`ldur x9, [x8, #-1]`)
   - `0x00dc9c`: `29 b1 40 78` (`ldurh w9, [x9, #0xb]`)
   - `0x00dca0`: `3f 0d 02 71` (`cmp w9, #0x83`)
4. **MurmurHash64A Pointer Hash (`0x00e9b8..0x00e9f0`)**:
   - `0x00e9bc..0x00e9d4`: `mov x10, #0x2d69; movk x10, #0xeb38, lsl #16; movk x10, #0xea08, lsl #32; movk x10, #0x9ddf, lsl #48` (`0x9ddfea08eb382d69ULL`).
5. **Exported `ObserverList` (`0x0133a0..0x01358c`) & `JNI_OnLoad` (`0x013590..0x013618`)**:
   - `AddObserver` (`0x0133a0`, `SZ=64`), `RemoveObserver` (`0x0133e0`, `SZ=220`), `ForEachObserver` (`0x013538`, `SZ=88`), and `JNI_OnLoad` (`0x013590`, `SZ=140`) returning `0x00010006` (`JNI_VERSION_1_6`).
