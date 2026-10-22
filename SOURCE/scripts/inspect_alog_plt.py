# -*- coding: utf-8 -*-
from elftools.elf.elffile import ELFFile

so_path = 'apktool-res/lib/arm64-v8a/libalog.so'
with open(so_path, 'rb') as f:
    elf = ELFFile(f)
    rela_plt = elf.get_section_by_name('.rela.plt')
    dynsym = elf.get_section_by_name('.dynsym')
    sym_names = [s.name for s in dynsym.iter_symbols()]

    plt_sec = elf.get_section_by_name('.plt')
    plt_vaddr = plt_sec['sh_addr']

    print(f".plt at {plt_vaddr:#x}")
    print("\n--- PLT Entries ---")
    idx = 0
    for rel in rela_plt.iter_relocations():
        sym_idx = rel['r_info_sym']
        name = sym_names[sym_idx] if sym_idx < len(sym_names) else f"sym_{sym_idx}"
        # In ARM64, PLT entries are typically 16 bytes each, starting after PLT0 (32 bytes)
        plt_addr = plt_vaddr + 32 + idx * 16
        print(f"[{idx:02d}] PLT {plt_addr:#08x} -> GOT {rel['r_offset']:#08x} : {name}")
        idx += 1
