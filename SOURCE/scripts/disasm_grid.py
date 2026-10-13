import capstone
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM

with open(r'D:\Decompiler\App\Video\Capcut\SOURCE\extracted\lib\arm64-v8a\libAGFX.so', 'rb') as f:
    so_bytes = f.read()

md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)

# buildGridHash is at 0x606e8
addr = 0x606e8
code = so_bytes[addr:addr+120]
print("=== Simulator::buildGridHash first 120 bytes ===")
for insn in md.disasm(code, addr):
    print(f"  {hex(insn.address)}: {insn.mnemonic}\t{insn.op_str}")
