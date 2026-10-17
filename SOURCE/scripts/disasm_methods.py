# -*- coding: utf-8 -*-
"""
Disassemble all 10 native methods in libfile_recorder.so
"""
import capstone

so_path = r"D:\Decompiler\App\Video\Capcut\SOURCE\apktool-res\lib\arm64-v8a\libfile_recorder.so"
with open(so_path, "rb") as f:
    elf = f.read()

md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)

funcs = [
    ("nativeStartIllegalRemoveMonitor", 0x1c9c, 0x1d5c - 0x1c9c),
    ("nativeIsFileInUse", 0x1d5c, 0x1e1c - 0x1d5c),
    ("nativeModifyTime", 0x1e1c, 0x1ecc - 0x1e1c),
    ("nativeRootPath", 0x1ecc, 0x1f98 - 0x1ecc),
    ("nativeRootLevel", 0x1f98, 0x2064 - 0x1f98),
    ("nativeTimeForCount", 0x2064, 0x20c4 - 0x2064),
    ("nativeIllegalRemovePath", 0x20c4, 0x2190 - 0x20c4),
    ("nativeIllegalRemoveCallback", 0x2190, 0x2214 - 0x2190),
    ("nativeStartFileRecord", 0x2214, 0x24c8 - 0x2214),
    ("nativeUpdateFileCheckParams", 0x24c8, 256),
]

for name, addr, size in funcs:
    print(f"\n==================== {name} at 0x{addr:06x} (size={size}) ====================")
    code = elf[addr:addr + size]
    for insn in md.disasm(code, addr):
        print(f"0x{insn.address:06x}:  {insn.mnemonic:<8} {insn.op_str}")

