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
    text_offset = text_sec['sh_offset']

    print(f".text vaddr={text_vaddr:#x}, offset={text_offset:#x}, size={len(text_data)}")

    # Disassemble JNI_OnLoad (0x93a4, 256 bytes)
    onload_offset = 0x93a4 - text_vaddr
    onload_bytes = text_data[onload_offset:onload_offset + 256]

    md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    print("\n--- JNI_OnLoad (0x93a4) Disassembly ---")
    for ins in md.disasm(onload_bytes, 0x93a4):
        print(f"  {ins.address:#08x}:  {ins.mnemonic:8s} {ins.op_str}")

    # Also inspect .rodata strings around JNI
    rodata_sec = elf.get_section_by_name('.rodata')
    ro_data = rodata_sec.data()
    ro_vaddr = rodata_sec['sh_addr']

    print(f"\n.rodata vaddr={ro_vaddr:#x}, size={len(ro_data)}")
    # Find all ASCII strings > 3 chars in rodata
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

    print("\nSample .rodata strings:")
    for addr, s in strings:
        if any(k in s.lower() for k in ['alog', 'log', 'jni', 'bytedance', 'flush', 'write', 'create']):
            print(f"  {addr:#08x}: {s}")
