# -*- coding: utf-8 -*-
"""
Inspect nativeStartIllegalRemoveMonitor and hook implementations
"""
import capstone

so_path = r"D:\Decompiler\App\Video\Capcut\SOURCE\apktool-res\lib\arm64-v8a\libfile_recorder.so"
with open(so_path, "rb") as f:
    elf = f.read()

md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)

funcs = [
    ("nativeStartIllegalRemoveMonitor", 0x1c9c, 0x1d5c - 0x1c9c),
    ("hooked_open", 0x3048, 0x30fc - 0x3048),
    ("hooked_open64", 0x30fc, 180),
]

for name, addr, size in funcs:
    print(f"\n==================== {name} at 0x{addr:06x} ====================")
    code = elf[addr:addr + size]
    for insn in md.disasm(code, addr):
        print(f"0x{insn.address:06x}:  {insn.mnemonic:<8} {insn.op_str}")

