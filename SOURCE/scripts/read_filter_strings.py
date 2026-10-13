with open(r'D:\Decompiler\App\Video\Capcut\SOURCE\extracted\lib\arm64-v8a\libnative-filters.so', 'rb') as f:
    data = f.read()

offsets = [0x42e0, 0x42fb, 0x430d, 0x4333, 0x435f]
for off in offsets:
    if off < len(data):
        s = data[off:off+64].split(b'\x00')[0]
        print(f"Offset {hex(off)}: {s.decode('utf-8', errors='ignore')}")

# Also search all JNINativeMethod tables or strings
import re
print("\nAll strings in .rodata / data:")
for m in re.finditer(b'[a-zA-Z0-9_/$().;]{3,}', data):
    print(f"  {hex(m.start())}: {m.group().decode('utf-8', errors='ignore')}")
