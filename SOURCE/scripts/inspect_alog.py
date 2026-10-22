# -*- coding: utf-8 -*-
import sys
from elftools.elf.elffile import ELFFile

so_path = 'apktool-res/lib/arm64-v8a/libalog.so'
with open(so_path, 'rb') as f:
    elf = ELFFile(f)
    print("ELF Machine:", elf.header['e_machine'])
    for sec in elf.iter_sections():
        print(f"Section {sec.name:22s} size={sec['sh_size']:8d} vaddr={sec['sh_addr']:#010x}")

    dynsym = elf.get_section_by_name('.dynsym')
    if dynsym:
        syms = [s for s in dynsym.iter_symbols() if s.name]
        print(f"\nDynamic Symbols Total: {len(syms)}")
        for s in syms:
            if s['st_info']['type'] in ['STT_FUNC', 'STT_OBJECT', 'STT_NOTYPE'] and s['st_value'] != 0:
                print(f"  {s.name:45s} type={s['st_info']['type']:10s} val={s['st_value']:#010x} size={s['st_size']:5d}")
