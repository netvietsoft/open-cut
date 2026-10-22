with open(r'D:\Decompiler\App\Video\Capcut\SOURCE\apktool-res\lib\arm64-v8a\libbdvideouploader.so', 'rb') as f:
    elf = f.read()

import re

# Look for parameter strings in .rodata
# In .rodata: 0x911e0 to 0xa041e
rodata = elf[0x911e0:0xa041e]
strs = re.findall(b'[\x20-\x7e]{4,}', rodata)
print(f"Strings in .rodata: {len(strs)}")

uploader_params = []
for s in strs:
    s_dec = s.decode('latin1')
    if any(k in s_dec.lower() for k in ['slice', 'chunk', 'timeout', 'retry', 'socket', 'token', 'auth', 'dns', 'resume', 'speed', 'quic', 'header', 'host', 'port']):
        uploader_params.append(s_dec)

print(f"Uploader param strings: {len(uploader_params)}")
for p in uploader_params[:60]:
    print("  ", p)
