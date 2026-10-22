# -*- coding: utf-8 -*-
import struct
from elftools.elf.elffile import ELFFile

so_path = 'apktool-res/lib/arm64-v8a/libalog.so'
with open(so_path, 'rb') as f:
    elf = ELFFile(f)

    # We need a function to read string at vaddr
    def read_str_at_vaddr(vaddr):
        for sec in elf.iter_sections():
            sh_addr = sec['sh_addr']
            sh_size = sec['sh_size']
            if sh_addr <= vaddr < sh_addr + sh_size:
                offset = vaddr - sh_addr
                data = sec.data()[offset:]
                end = data.find(b'\x00')
                if end != -1:
                    return data[:end].decode('ascii', errors='ignore')
                return data.decode('ascii', errors='ignore')
        return None

    def read_bytes_at_vaddr(vaddr, length):
        for sec in elf.iter_sections():
            sh_addr = sec['sh_addr']
            sh_size = sec['sh_size']
            if sh_addr <= vaddr < sh_addr + sh_size:
                offset = vaddr - sh_addr
                return sec.data()[offset:offset+length]
        return None

    # Table is at 0x14008 (18 entries)
    # Check if there are relocations for 0x14008
    rela_dyn = elf.get_section_by_name('.rela.dyn')
    relocs = {}
    if rela_dyn:
        for rel in rela_dyn.iter_relocations():
            r_offset = rel['r_offset']
            r_info_type = rel['r_info_type']
            r_addend = rel['r_addend']
            relocs[r_offset] = (r_info_type, r_addend)

    print(f"Total dynamic relocations: {len(relocs)}")

    table_vaddr = 0x14008
    print(f"\n--- Reading JNINativeMethod table at {table_vaddr:#x} (18 entries) ---")
    for i in range(18):
        entry_vaddr = table_vaddr + i * 24
        raw = read_bytes_at_vaddr(entry_vaddr, 24)
        name_ptr, sig_ptr, fn_ptr = struct.unpack('<QQQ', raw)

        # Check if relocated
        if entry_vaddr in relocs:
            name_ptr = relocs[entry_vaddr][1]
        if entry_vaddr + 8 in relocs:
            sig_ptr = relocs[entry_vaddr + 8][1]
        if entry_vaddr + 16 in relocs:
            fn_ptr = relocs[entry_vaddr + 16][1]

        name_str = read_str_at_vaddr(name_ptr) if name_ptr else "NULL"
        sig_str = read_str_at_vaddr(sig_ptr) if sig_ptr else "NULL"
        print(f"[{i:02d}] {name_str:32s} sig={sig_str:35s} fnPtr={fn_ptr:#010x}")
