import struct

with open(r'D:\Decompiler\App\Video\Capcut\SOURCE\extracted\lib\arm64-v8a\libnative-filters.so', 'rb') as f:
    data = f.read()

# Look for strings: nativeIterativeBoxBlur (0x43c6), nativeToCircleFilter (0x45bb), nativeToCircleWithBorderFilter (0x45ee)
str_addrs = [0x43c6, 0x45bb, 0x45ee]
for sa in str_addrs:
    pattern = struct.pack('<Q', sa)
    idx = 0
    while True:
        pos = data.find(pattern, idx)
        if pos == -1: break
        print(f"Found pointer to string {hex(sa)} at offset {hex(pos)}")
        # JNINativeMethod in 64-bit:
        # const char* name (8 bytes)
        # const char* signature (8 bytes)
        # void* fnPtr (8 bytes)
        name_ptr, sig_ptr, fn_ptr = struct.unpack('<QQQ', data[pos:pos+24])
        print(f"  name_ptr: {hex(name_ptr)}, sig_ptr: {hex(sig_ptr)}, fn_ptr: {hex(fn_ptr)}")
        idx = pos + 1
