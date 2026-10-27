# Adversarial Verification Proof: `libterrain.so` (`TASK-136` / `TASK_SO_062_libterrain`)

## 1. Binary & Reconstruction Metrics
- **Binary Path**: `SOURCE/apktool-res/lib/arm64-v8a/libterrain.so`
- **Binary Size**: `336,672 bytes`
- **SHA-256**: `556d6d47d9643c641668fd79acb937a8651b5b7c78e80da8bb9e07b1171ccd2d`
- **Reconstructed C++17 / Header Volume**: `1,323,503 bytes` across 9 source/header files
- **Verified AArch64 Instructions**: `46,213` instructions across `1,034` FDEs
- **Exported `.dynsym` Symbols**: `310` symbols (`0` stubs)

## 2. Direct AArch64 Opcode & `.rodata` / `.data` Evidence
- **MBA Pointer Deobfuscation (`0x013700..0x013774`)**:
  - `x13 = 0x0135AC` (`adrp x13, #0x13000; add x13, x13, #0x5ac`)
  - Evaluates to `0xFFFFFFFFFF722DE0ULL` (`-0x008DD220`), deobfuscating `.data 0x0559d8` (`0x00931228`) to `0x054008` (the 255-entry Dalvik opcode handler jump table in `.data 0x054008..0x054800`).
- **35 XOR-Encrypted Strings in `.rodata` (`0x03f530..0x040310`)**:
  - Decrypted via `DecodeXorString_012fd8` (`0x012fd8`, `0x01cb30`, `0x027678`) into `.bss 0x055a00..0x055ef0`: `"length=%d; index=%d"`, `"bad packed switch magic"`, `"bad sparse switch magic"`, `"bad array data magic"`, `"Can't new array"`, `"divide by zero"`, `"bad filled array req"`, `"filled-new-array not implemented for anything but 'int'"`, `"java/lang/Boolean"`..`"java/lang/RuntimeException"`, `"TYPE"`, `"Ljava/lang/Class;"`.
- **Dalvik Switch & Array Payload Handlers (`0x013010..0x01337c`)**:
  - `0x013060: 0x7104011F cmp w8, #0x100` (`packed-switch`)
  - `0x01310c: 0x7108011F cmp w8, #0x200` (`sparse-switch`)
  - `0x0131e8: 0x710C011F cmp w8, #0x300` (`fill-array-data`)
- **Exported `getCacheClass` (`0x0275ec..0x027674`)**:
  - `0x0275f4: 0x51010908 sub w8, w8, #0x42` (`'B'`), `0x0275f8: 0x7100611F cmp w8, #0x18` (`'Z' - 'B' = 24`), `0x02760c: 0x3868692B ldrb w11, [x9, x8]` (`.rodata 0x03fde4`).
