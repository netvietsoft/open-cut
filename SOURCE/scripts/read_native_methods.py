# -*- coding: utf-8 -*-
"""
Inspect the 10 JNINativeMethods in libfile_recorder.so
"""
import struct

so_path = r"D:\Decompiler\App\Video\Capcut\SOURCE\apktool-res\lib\arm64-v8a\libfile_recorder.so"
with open(so_path, "rb") as f:
    elf = f.read()

# Parse .rela.dyn to see relocations for .data (0x10000)
# In inspect_elf_sections:
# [08] .rela.dyn addr=0x000fb0 off=0x000fb0 size=0x0003d8 entsize=24
rela_off = 0x000fb0
rela_size = 0x0003d8

relocs = {}
for i in range(rela_size // 24):
    r_offset, r_info, r_addend = struct.unpack("<QQq", elf[rela_off + i*24 : rela_off + (i+1)*24])
    r_type = r_info & 0xffffffff
    r_sym = r_info >> 32
    relocs[r_offset] = (r_type, r_sym, r_addend)

# Also check .data at file offset 0x00c000 (virtual addr 0x10000)
data_off = 0x00c000
data_virt = 0x010000

print(f"Relocations count in .rela.dyn: {len(relocs)}")

# Each JNINativeMethod is 24 bytes on AArch64 (3 pointers: char* name, char* signature, void* fnPtr)
# 10 methods = 240 bytes (0xf0)
methods = []
for i in range(10):
    m_addr = data_virt + i * 24
    name_ptr = relocs.get(m_addr, (None, None, 0))[2]
    sig_ptr = relocs.get(m_addr + 8, (None, None, 0))[2]
    fn_ptr = relocs.get(m_addr + 16, (None, None, 0))[2]
    
    # Read strings from elf
    def read_str(virt_addr):
        if virt_addr is None or virt_addr == 0:
            return ""
        # virt_addr in .rodata (0x80b8 -> file offset 0x80b8)
        # Check sections
        f_off = virt_addr # since in this ELF, text/rodata virtual addr == file offset
        end = elf.find(b"\x00", f_off)
        return elf[f_off:end].decode("ascii", errors="ignore")
    
    name_str = read_str(name_ptr)
    sig_str = read_str(sig_ptr)
    print(f"Method [{i}]:")
    print(f"  name_ptr = 0x{name_ptr or 0:x} -> '{name_str}'")
    print(f"  sig_ptr  = 0x{sig_ptr or 0:x} -> '{sig_str}'")
    print(f"  fn_ptr   = 0x{fn_ptr or 0:x}")
    methods.append((name_str, sig_str, fn_ptr))

