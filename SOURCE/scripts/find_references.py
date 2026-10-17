# -*- coding: utf-8 -*-
"""
Find functions referencing ByteVC1 strings in libanimax_bytevc1.so
"""
import capstone

so_path = r"D:\Decompiler\App\Video\Capcut\SOURCE\apktool-res\lib\arm64-v8a\libanimax_bytevc1.so"
with open(so_path, "rb") as f:
    elf = f.read()

md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)

# Search text section from 0x4000 to 0x84d8
text_start = 0x4000
text_end = 0x8000

for addr in range(text_start, text_end, 4):
    chunk = elf[addr:addr+4]
    for insn in md.disasm(chunk, addr):
        # Look for adrp referencing 0x1000 or 0x2000
        if insn.mnemonic == "adrp" and ("#0x1000" in insn.op_str or "#0x2000" in insn.op_str):
            print(f"0x{insn.address:06x}: {insn.mnemonic:<8} {insn.op_str}")

