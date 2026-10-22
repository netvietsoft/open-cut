import capstone, struct

with open('apktool-res/lib/arm64-v8a/libbuffer.so', 'rb') as f:
    data = f.read()

plt_map = {
    0x0e00: 'open',
    0x0e10: '__cxa_finalize',
    0x0e20: 'calloc',
    0x0e30: 'msync',
    0x0e40: 'mremap',
    0x0e50: 'strerror',
    0x0e60: '__errno',
    0x0e70: 'write',
    0x0e80: '__read_chk',
    0x0e90: 'lseek',
    0x0ea0: '__stack_chk_fail',
    0x0eb0: '__android_log_print',
    0x0ec0: 'mmap',
    0x0ed0: 'close',
    0x0ee0: 'munmap',
    0x0ef0: 'ftruncate',
    0x0f00: 'free',
    0x0f10: '__cxa_atexit',
}

rodata_strs = {
    0x19a8: "java/io/IOException",
    0x19bc: "inconsistent file length",
    0x19d5: "Buffer",
    0x19dc: "mmap failed, %s",
    0x19ec: "length illegal",
    0x19fb: "seek failed",
    0x1a07: "native calloc failed",
    0x1a1c: "read full failed",
    0x1a2d: "close failed",
    0x1a3a: "close file failed",
    0x1a4c: "mremap failed",
}

# JNIEnv vtable offsets (64-bit ARM64 pointer size = 8 bytes):
# index = offset / 8
# 6 (0x30): FindClass
# 14 (0x70): ThrowNew
# 169 (0x548): GetStringUTFChars
# 170 (0x550): ReleaseStringUTFChars
# 188 (0x5e0): GetByteArrayRegion
# 192 (0x600): SetByteArrayRegion
# 208 (0x680): GetDirectBufferAddress
jni_env_vtable = {
    0x30: 'FindClass',
    0x70: 'ThrowNew',
    0x548: 'GetStringUTFChars',
    0x550: 'ReleaseStringUTFChars',
    0x5e0: 'GetByteArrayRegion',
    0x600: 'SetByteArrayRegion',
    0x680: 'GetDirectBufferAddress',
}

funcs = [
    ('MMapBuffer_nCreate', 0x0f5c, 480),
    ('MMapBuffer_nWrite', 0x113c, 92),
    ('MMapBuffer_nRelease', 0x1198, 76),
    ('MMapBuffer_nRead', 0x11e4, 92),
    ('MMapBuffer_nFlush', 0x1240, 172),
    ('MemoryBuffer_nCreate', 0x12ec, 776),
    ('readFull', 0x15f4, 172),
    ('MemoryBuffer_nWrite', 0x16a0, 92),
    ('MemoryBuffer_nRead', 0x16fc, 92),
    ('MemoryBuffer_nRelease', 0x1758, 72),
    ('MemoryBuffer_nFlush', 0x17a0, 336),
    ('MReMapBuffer_nMReMap', 0x18f0, 184),
]

md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
for name, off, sz in funcs:
    print(f'\n======================================================')
    print(f'FUNCTION: {name} @ 0x{off:04x}..0x{off+sz:04x} ({sz} bytes)')
    print(f'======================================================')
    code = data[off : off + sz]
    for ins in md.disasm(code, off):
        target_comment = ''
        if ins.mnemonic.startswith('bl') or ins.mnemonic == 'b':
            try:
                tgt = int(ins.op_str.strip('#'), 16)
                if tgt in plt_map:
                    target_comment = f' // CALL {plt_map[tgt]}'
            except:
                pass
        print(f'  0x{ins.address:04x}: {ins.bytes.hex():10} {ins.mnemonic:8} {ins.op_str:30}{target_comment}')
