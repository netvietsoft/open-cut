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

    md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)

    def disasm_func(vaddr, size, name):
        offset = vaddr - text_vaddr
        bytes_data = text_data[offset:offset+size]
        print(f"\n{'='*70}\nFunction: {name} (VAddr {vaddr:#x}, Size {size} bytes)\n{'='*70}")
        count = 0
        for ins in md.disasm(bytes_data, vaddr):
            print(f"  {ins.address:#08x}:  {ins.mnemonic:8s} {ins.op_str}")
            count += 1
            if count >= 60:
                print("  ... (truncated for brevity)")
                break

    # Disasm nativeCreate (0x94a4, ~350 bytes)
    disasm_func(0x94a4, 250, "Java_com_bytedance_android_alog_Alog_nativeCreate")
    # Disasm nativeWrite (0x9700, 196 bytes)
    disasm_func(0x9700, 196, "Java_com_bytedance_android_alog_Alog_nativeWrite")
    # Disasm alog_create (0x2c8c, 4020 bytes, first 60 instructions)
    disasm_func(0x2c8c, 240, "alog_create")
    # Disasm init_async_logging (0x4390, 92 bytes)
    disasm_func(0x4390, 92, "init_async_logging")
