# -*- coding: utf-8 -*-
"""
Inspect symbols, strings, and sections of libanimax_bytevc1.so
"""
import os
import struct
import json

so_path = r"D:\Decompiler\App\Video\Capcut\SOURCE\apktool-res\lib\arm64-v8a\libanimax_bytevc1.so"
print("File size:", os.path.getsize(so_path), "bytes")

with open(so_path, "rb") as f:
    elf = f.read()

# Extract strings of length >= 4
strings = []
current = []
start_idx = 0
for idx, b in enumerate(elf):
    if 32 <= b <= 126:
        if not current:
            start_idx = idx
        current.append(chr(b))
    else:
        if len(current) >= 4:
            strings.append((start_idx, "".join(current)))
        current = []

print("Total extracted strings:", len(strings))
print("\n--- Key strings found ---")
for offset, s in strings:
    if any(k in s.lower() for k in ["animax", "bytevc1", "hevc", "h265", "codec", "decode", "video", "frame", "yuv", "stream", "jni", "render", "bytedance"]):
        print(f"0x{offset:05x}: {s}")

# Check symbols if demangled file exists
sym_path = r"D:\Decompiler\App\Video\Capcut\SOURCE\GIAI-MA\libanimax_bytevc1\symbols_demangled.json"
if os.path.exists(sym_path):
    with open(sym_path, "r", encoding="utf-8") as f:
        syms = json.load(f)
    print(f"\nTotal demangled symbols in json: {len(syms)}")
    defined = [s for s in syms if s.get("value") != "0x0"]
    print(f"Defined symbols count: {len(defined)}")
    for s in defined:
        print(f"  {s.get('value')} | {s.get('name')} | {s.get('demangled')}")

