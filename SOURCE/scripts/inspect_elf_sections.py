# -*- coding: utf-8 -*-
"""
Inspect ELF sections and disassembly of libfile_recorder.so
"""
import struct

so_path = r"D:\Decompiler\App\Video\Capcut\SOURCE\apktool-res\lib\arm64-v8a\libfile_recorder.so"

with open(so_path, "rb") as f:
    elf = f.read()

# Parse ELF64 Header
e_ident = elf[:16]
assert e_ident[:4] == b"\x7fELF", "Not an ELF file"

e_type, e_machine, e_version, e_entry, e_phoff, e_shoff, e_flags, e_ehsize, e_phentsize, e_phnum, e_shentsize, e_shnum, e_shstrndx = struct.unpack(
    "<HHIQQQIHHHHHH", elf[16:64]
)

print(f"ELF Header: e_shoff={hex(e_shoff)}, e_shnum={e_shnum}, e_shstrndx={e_shstrndx}")

# Section header table
sections = []
for i in range(e_shnum):
    offset = e_shoff + i * e_shentsize
    sh_name, sh_type, sh_flags, sh_addr, sh_offset, sh_size, sh_link, sh_info, sh_addralign, sh_entsize = struct.unpack(
        "<IIQQQQIIQQ", elf[offset:offset + 64]
    )
    sections.append({
        "index": i,
        "sh_name_idx": sh_name,
        "sh_type": sh_type,
        "sh_flags": sh_flags,
        "sh_addr": sh_addr,
        "sh_offset": sh_offset,
        "sh_size": sh_size,
        "sh_link": sh_link,
        "sh_info": sh_info,
        "sh_addralign": sh_addralign,
        "sh_entsize": sh_entsize
    })

# String table for section names
shstrtab = sections[e_shstrndx]
shstr_data = elf[shstrtab["sh_offset"]:shstrtab["sh_offset"] + shstrtab["sh_size"]]

def get_shstr(idx):
    end = shstr_data.find(b"\x00", idx)
    return shstr_data[idx:end].decode("ascii", errors="ignore")

for s in sections:
    s["name"] = get_shstr(s["sh_name_idx"])
    print(f"[{s['index']:02d}] {s['name']:<20} addr=0x{s['sh_addr']:06x} off=0x{s['sh_offset']:06x} size=0x{s['sh_size']:06x}")

