# -*- coding: utf-8 -*-
from elftools.elf.elffile import ELFFile

so_path = 'apktool-res/lib/arm64-v8a/libbvcparser.so'
with open(so_path, 'rb') as f:
    elf = ELFFile(f)
    print("ELF Machine:", elf.header['e_machine'])

    dynsym = elf.get_section_by_name('.dynsym')
    if dynsym:
        syms = [s for s in dynsym.iter_symbols() if s.name]
        print(f"\nDynamic Symbols Total: {len(syms)}")
        for s in syms:
            if s['st_info']['type'] in ['STT_FUNC', 'STT_OBJECT', 'STT_NOTYPE'] and s['st_value'] != 0:
                print(f"  {s.name:45s} type={s['st_info']['type']:10s} val={s['st_value']:#010x} size={s['st_size']:5d}")

    # Inspect .rodata strings
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

        print(f"\nTotal ASCII Strings in .rodata: {len(strings)}")
        print("Sample strings:")
        for addr, s in strings[:30]:
            print(f"  {addr:#08x}: {s}")
