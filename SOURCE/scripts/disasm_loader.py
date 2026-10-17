# -*- coding: utf-8 -*-
import capstone

so_path = r"D:\Decompiler\App\Video\Capcut\SOURCE\apktool-res\lib\arm64-v8a\libanimax_bytevc1.so"
with open(so_path, "rb") as f:
    elf = f.read()

md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)

addr = 0x4660
size = 0x4920 - 0x4660
code = elf[addr:addr + size]
print(f"==================== ByteVC1LibLoader at 0x{addr:06x} (size={size}) ====================")
for insn in md.disasm(code, addr):
    print(f"0x{insn.address:06x}:  {insn.mnemonic:<8} {insn.op_str}")

