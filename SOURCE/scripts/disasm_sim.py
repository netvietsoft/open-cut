import capstone
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
import json

with open(r'D:\Decompiler\App\Video\Capcut\SOURCE\extracted\lib\arm64-v8a\libAGFX.so', 'rb') as f:
    so_bytes = f.read()

with open(r'D:\Decompiler\App\Video\Capcut\SOURCE\GIAI-MA\libAGFX\symbols_demangled.json', 'r', encoding='utf-8') as f:
    syms = json.load(f)

md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)

targets = ['Simulator::step', 'Simulator::setLim', 'Simulator::setFaceEclipse', 'Simulator::setNcorr', 'AmazingEngine::Utils::isASTCCompressionFormat', 'AmazingEngine::Utils::getASTCTexBlockDims']

for s in syms:
    d = s.get('demangled', '')
    for t in targets:
        if t in d and s.get('size') > 0:
            addr = int(s.get('value'), 16)
            sz = min(s.get('size'), 140)
            code = so_bytes[addr:addr+sz]
            sym_sz = s.get('size')
            print(f"=== {d} at {hex(addr)} (size {sym_sz}) ===")
            for insn in md.disasm(code, addr):
                print(f"  {hex(insn.address)}: {insn.mnemonic}\t{insn.op_str}")
            print()
            break
