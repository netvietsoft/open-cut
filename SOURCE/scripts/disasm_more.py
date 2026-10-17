# -*- coding: utf-8 -*-
"""
Disassemble nativeIsFileInUse, nativeModifyTime, unlinkat hook, and worker thread in libfile_recorder.so
"""
import capstone

so_path = r"D:\Decompiler\App\Video\Capcut\SOURCE\apktool-res\lib\arm64-v8a\libfile_recorder.so"
with open(so_path, "rb") as f:
    elf = f.read()

md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)

funcs = [
    ("nativeIsFileInUse", 0x1d5c, 0x1e1c - 0x1d5c),
    ("nativeModifyTime", 0x1e1c, 0x1ecc - 0x1e1c),
    ("hooked_unlinkat", 0x25ec, 0x27c8 - 0x25ec),
    ("worker_thread_func", 0x4364, 256),
]

for name, addr, size in funcs:
    print(f"\n==================== {name} at 0x{addr:06x} (size={size}) ====================")
    code = elf[addr:addr + size]
    for insn in md.disasm(code, addr):
        print(f"0x{insn.address:06x}:  {insn.mnemonic:<8} {insn.op_str}")

