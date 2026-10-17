# -*- coding: utf-8 -*-
so_path = r"D:\Decompiler\App\Video\Capcut\SOURCE\apktool-res\lib\arm64-v8a\libfile_recorder.so"

with open(so_path, "rb") as f:
    data = f.read()

# Print all strings from 0x7f00 to 0x8600
chunk = data[0x7f00:0x8600]
print("Chunk length:", len(chunk))

offset = 0x7f00
s = []
for i, b in enumerate(chunk):
    if 32 <= b <= 126:
        s.append(chr(b))
    else:
        if len(s) >= 2:
            print(f"0x{offset + i - len(s):05x}: {''.join(s)}")
        s = []
