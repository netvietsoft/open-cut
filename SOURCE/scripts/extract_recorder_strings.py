# -*- coding: utf-8 -*-
"""
Dump strings, sections, and disassembly of libfile_recorder.so
"""
import struct

so_path = r"D:\Decompiler\App\Video\Capcut\SOURCE\apktool-res\lib\arm64-v8a\libfile_recorder.so"

with open(so_path, "rb") as f:
    data = f.read()

print("File size:", len(data))

# Extract ASCII / UTF-8 strings of length >= 4
strings = []
current = []
start_idx = 0
for idx, b in enumerate(data):
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
    if any(k in s.lower() for k in ["helios", "file", "record", "hook", "open", "close", "jni", "byte", "bytedance", "java", "log", "trace", "path"]):
        print(f"0x{offset:05x}: {s}")

