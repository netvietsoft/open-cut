with open(r'D:\Decompiler\App\Video\Capcut\SOURCE\apktool-res\lib\arm64-v8a\libbdvideouploader.so', 'rb') as f:
    elf = f.read()

import re
keys = set()
# Look for log strings like 'uploader string value:%s, key:%d' or similar
for m in re.finditer(b'key:%d|key:%s|key: %d|key: %s|Key:%d', elf):
    ctx = elf[max(0, m.start()-50):min(len(elf), m.end()+50)]
    print(ctx)
