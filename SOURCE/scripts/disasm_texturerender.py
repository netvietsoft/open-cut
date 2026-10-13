import capstone
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
import json

with open(r'D:\Decompiler\App\Video\Capcut\SOURCE\extracted\lib\arm64-v8a\libtexturerender_native.so', 'rb') as f:
    so_bytes = f.read()

with open(r'D:\Decompiler\App\Video\Capcut\SOURCE\GIAI-MA\libtexturerender_native\symbols_demangled.json', 'r', encoding='utf-8') as f:
    syms = json.load(f)

md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)

print("=== ALL DEFINED SYMBOLS IN libtexturerender_native.so ===")
for s in syms:
    val = int(s.get('value'), 16)
    sz = s.get('size', 0)
    name = s.get('name')
    if val > 0 and sz > 0:
        print(f"\n--- {name} at {hex(val)} (size {sz}) ---")
        code = so_bytes[val:val+min(sz, 120)]
        for insn in md.disasm(code, val):
            print(f"  {hex(insn.address)}: {insn.mnemonic}\t{insn.op_str}")
