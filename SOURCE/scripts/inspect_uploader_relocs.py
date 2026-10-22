import struct

with open(r'D:\Decompiler\App\Video\Capcut\SOURCE\apktool-res\lib\arm64-v8a\libbdvideouploader.so', 'rb') as f:
    elf = f.read()

def get_str(addr):
    if 0 <= addr < len(elf):
        end = elf.find(b'\x00', addr)
        if end != -1 and end - addr < 150:
            return elf[addr:end].decode('latin1', errors='ignore')
    return ''

rela_off = 0x5610
rela_sz = 0x7c98

relocs = {}
for i in range(0, rela_sz, 24):
    r_offset, r_info, r_addend = struct.unpack('<QQq', elf[rela_off+i : rela_off+i+24])
    r_type = r_info & 0xFFFFFFFF
    if r_type == 1027:
        relocs[r_offset] = r_addend

sorted_offsets = sorted(relocs.keys())
print("Scanning all string pointers in .data.rel.ro for bridges:")
for i in range(len(sorted_offsets) - 2):
    off1 = sorted_offsets[i]
    off2 = sorted_offsets[i+1]
    off3 = sorted_offsets[i+2]
    if off2 == off1 + 8 and off3 == off1 + 16:
        add1 = relocs[off1]
        add2 = relocs[off2]
        add3 = relocs[off3]
        s1 = get_str(add1)
        s2 = get_str(add2)
        if s1 and s2 and '(' in s2:
            print(f"[0x{off1:06x}] {s1:25} {s2:35} -> 0x{add3:06x}")
