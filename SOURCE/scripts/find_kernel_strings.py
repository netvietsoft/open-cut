with open(r'D:\Decompiler\App\Video\Capcut\SOURCE\extracted\lib\arm64-v8a\libAGFX.so', 'rb') as f:
    data = f.read()

import re
matches = re.findall(b'[a-zA-Z0-9_/.-]{4,}(?:comp|pbf|particle|density|hash|advect|sort|grid)[a-zA-Z0-9_/.-]*', data, re.IGNORECASE)
unique = sorted(set(m.decode('utf-8', errors='ignore') for m in matches))
print(f"Found {len(unique)} matches:")
for m in unique[:40]:
    print("  ", m)
