import capstone
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM

with open(r'D:\Decompiler\App\Video\Capcut\SOURCE\extracted\lib\arm64-v8a\libnative-filters.so', 'rb') as f:
    so_bytes = f.read()

md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)

funcs = [
    ("nativeIterativeBoxBlur", 0xc00, 200),
    ("nativeToCircleFilter", 0x13bc, 100),
    ("nativeToCircleWithBorderFilter", 0x13d0, 150)
]

for name, addr, sz in funcs:
    print(f"\n=== {name} at {hex(addr)} ===")
    code = so_bytes[addr:addr+sz]
    for insn in md.disasm(code, addr):
        print(f"  {hex(insn.address)}: {insn.mnemonic}\t{insn.op_str}")
