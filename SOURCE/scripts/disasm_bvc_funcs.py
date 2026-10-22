# -*- coding: utf-8 -*-
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.elf.elffile import ELFFile

so_path = 'apktool-res/lib/arm64-v8a/libbvcparser.so'
with open(so_path, 'rb') as f:
    elf = ELFFile(f)
    text_sec = elf.get_section_by_name('.text')
    text_data = text_sec.data()
    text_vaddr = text_sec['sh_addr']

    md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)

    def disasm(vaddr, size, name):
        offset = vaddr - text_vaddr
        bytes_data = text_data[offset:offset+size]
        print(f"\n{'='*70}\nFunction: {name} (VAddr {vaddr:#x}, Size {size} bytes)\n{'='*70}")
        for ins in md.disasm(bytes_data, vaddr):
            print(f"  {ins.address:#08x}:  {ins.mnemonic:8s} {ins.op_str}")

    disasm(0x0076d4, 20, "register_bvcparser")
    disasm(0x007538, 100, "bvc_get_se_golomb")
    disasm(0x0075f4, 100, "bvc_get_ue_golomb")
