# -*- coding: utf-8 -*-
import sys
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.elf.elffile import ELFFile

so_path = 'apktool-res/lib/arm64-v8a/libalog.so'
with open(so_path, 'rb') as f:
    elf = ELFFile(f)
    text_sec = elf.get_section_by_name('.text')
    text_data = text_sec.data()
    text_vaddr = text_sec['sh_addr']

    md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)

    # Disassemble full nativeCreate (0x94a4 to 0x9700)
    offset = 0x94a4 - text_vaddr
    size = 0x9700 - 0x94a4
    bytes_data = text_data[offset:offset+size]

    print(f"Disassembling nativeCreate ({size} bytes):")
    for ins in md.disasm(bytes_data, 0x94a4):
        # Filter interesting instructions
        if ins.mnemonic in ['bl', 'blr', 'ldr', 'str', 'stp', 'ldp', 'mov', 'movk', 'cbz', 'cbnz']:
            print(f"  {ins.address:#08x}:  {ins.mnemonic:8s} {ins.op_str}")
