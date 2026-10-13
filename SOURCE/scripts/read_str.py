with open(r'D:\Decompiler\App\Video\Capcut\SOURCE\extracted\lib\arm64-v8a\libAGFX.so', 'rb') as f:
    f.seek(0x83451)
    s = f.read(64).split(b'\x00')[0]
    print("String at 0x83451:", s.decode('utf-8', errors='ignore'))
