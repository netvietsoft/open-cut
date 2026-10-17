# -*- coding: utf-8 -*-
import capstone

so_path = r"D:\Decompiler\App\Video\Capcut\SOURCE\apktool-res\lib\arm64-v8a\libfile_recorder.so"
with open(so_path, "rb") as f:
    elf = f.read()

md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)

addr = 0x31b0
size = 0x3264 - 0x31b0
code = elf[addr:addr + size]
print(f"==================== check_file_path start at 0x{addr:06x} ====================")
for insn in md.disasm(code, addr):
    print(f"0x{insn.address:06x}:  {insn.mnemonic:<8} {insn.op_str}")
