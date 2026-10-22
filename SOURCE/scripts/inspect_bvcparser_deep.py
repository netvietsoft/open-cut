# -*- coding: utf-8 -*-
from elftools.elf.elffile import ELFFile

so_path = 'apktool-res/lib/arm64-v8a/libbvcparser.so'
with open(so_path, 'rb') as f:
    elf = ELFFile(f)
    rela_plt = elf.get_section_by_name('.rela.plt')
    dynsym = elf.get_section_by_name('.dynsym')
    sym_names = [s.name for s in dynsym.iter_symbols()]

    print("--- PLT Entries of libbvcparser.so ---")
    if rela_plt:
        for idx, rel in enumerate(rela_plt.iter_relocations()):
            sym_idx = rel['r_info_sym']
            name = sym_names[sym_idx] if sym_idx < len(sym_names) else f"sym_{sym_idx}"
            print(f"[{idx:02d}] GOT {rel['r_offset']:#08x} : {name}")

    rodata = elf.get_section_by_name('.rodata')
    if rodata:
        ro_data = rodata.data()
        ro_vaddr = rodata['sh_addr']
        strings = []
        cur = bytearray()
        cur_addr = ro_vaddr
        for i, b in enumerate(ro_data):
            if 32 <= b <= 126:
                if not cur:
                    cur_addr = ro_vaddr + i
                cur.append(b)
            else:
                if len(cur) >= 3:
                    strings.append((cur_addr, cur.decode('ascii', errors='ignore')))
                cur = bytearray()

        print(f"\n--- All Strings in .rodata ({len(strings)}) ---")
        for addr, s in strings:
            print(f"  {addr:#08x}: {s}")
