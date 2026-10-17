# -*- coding: utf-8 -*-
import capstone

so_path = r"D:\Decompiler\App\Video\Capcut\SOURCE\apktool-res\lib\arm64-v8a\libanimax_bytevc1.so"
with open(so_path, "rb") as f:
    elf = f.read()

md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)

print("==================== JNI_OnLoad end ====================")
code = elf[0x5a78:0x5b00]
for insn in md.disasm(code, 0x5a78):
    print(f"0x{insn.address:06x}:  {insn.mnemonic:<8} {insn.op_str}")

