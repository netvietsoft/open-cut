with open(r'D:\Decompiler\App\Video\Capcut\SOURCE\extracted\lib\arm64-v8a\libAGFX.so', 'rb') as f:
    data = f.read()

import re
matches = re.findall(b'/ws/40391/AGFX/[a-zA-Z0-9_/.-]+', data)
unique = sorted(set(m.decode('utf-8', errors='ignore') for m in matches))
print(f"Found {len(unique)} source paths:")
for m in unique:
    print("  ", m)
