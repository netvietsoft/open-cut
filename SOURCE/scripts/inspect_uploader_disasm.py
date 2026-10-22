import struct

with open(r'D:\Decompiler\App\Video\Capcut\SOURCE\apktool-res\lib\arm64-v8a\libbdvideouploader.so', 'rb') as f:
    elf = f.read()

def disasm_block(start, count):
    print(f"=== Disasm @ 0x{start:06x} ({count*4} bytes) ===")
    for i in range(count):
        addr = start + i*4
        if addr >= len(elf): break
        inst = struct.unpack('<I', elf[addr:addr+4])[0]
        # check bl
        bl_info = ''
        if (inst >> 26) == 0x25:
            imm26 = inst & 0x3FFFFFF
            if imm26 & 0x2000000: imm26 -= 0x4000000
            target = addr + (imm26 << 2)
            bl_info = f'-> BL 0x{target:06x}'
        print(f"0x{addr:06x}: {inst:08x} {bl_info}")

# 1. _create (0x011a68)
disasm_block(0x011a68, 25)

# 2. _setIntValue (0x0125a8)
disasm_block(0x0125a8, 25)

# 3. _setStringValue (0x011ff4)
disasm_block(0x011ff4, 25)
