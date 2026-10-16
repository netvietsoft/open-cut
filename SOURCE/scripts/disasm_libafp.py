import os
from pathlib import Path
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM

so_path = Path("extracted/lib/arm64-v8a/libaudio_fingerprint_sdk.so")
if not so_path.exists():
    print(f"File not found: {so_path}")
    exit(1)

data = so_path.read_bytes()
md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)

# List of key functions to inspect
targets = [
    ("GetVersion", 0x94c4, 16),
    ("Reset", 0x956c, 4),
    ("gen_ham_win", 0x3914, 120),
    ("init", 0x323c, 24),
    ("AFP_SDK ctor", 0x9230, 80),
    ("compress_time_data", 0x48ec, 160),
    ("compress_frequency_data", 0x56cc, 120),
    ("locate_peaks", 0x4258, 160),
    ("write_size_ahead", 0x6950, 100),
]

for name, offset, length in targets:
    print(f"\n{'='*60}")
    print(f"Disassembly: {name} @ 0x{offset:x} (len {length})")
    print(f"{'='*60}")
    chunk = data[offset : offset + length]
    for ins in md.disasm(chunk, offset):
        print(f"  0x{ins.address:x}: {ins.mnemonic:<8} {ins.op_str}")
