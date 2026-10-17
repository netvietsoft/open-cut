# -*- coding: utf-8 -*-
"""
Disassemble JNI_OnLoad and ByteVC1 loader/decoder in libanimax_bytevc1.so
"""
import capstone

so_path = r"D:\Decompiler\App\Video\Capcut\SOURCE\apktool-res\lib\arm64-v8a\libanimax_bytevc1.so"
with open(so_path, "rb") as f:
    elf = f.read()

md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)

# JNI_OnLoad is at 0x59cc
print("==================== JNI_OnLoad at 0x59cc ====================")
code = elf[0x59cc:0x59cc + 180]
for insn in md.disasm(code, 0x59cc):
    print(f"0x{insn.address:06x}:  {insn.mnemonic:<8} {insn.op_str}")

