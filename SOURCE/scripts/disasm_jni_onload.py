# -*- coding: utf-8 -*-
"""
Disassemble JNI_OnLoad and locate JNINativeMethod table
"""
try:
    import capstone
    has_capstone = True
except ImportError:
    has_capstone = False

print("Has capstone:", has_capstone)

so_path = r"D:\Decompiler\App\Video\Capcut\SOURCE\apktool-res\lib\arm64-v8a\libfile_recorder.so"
with open(so_path, "rb") as f:
    elf = f.read()

# JNI_OnLoad is at 0x1bdc, size 192 (0xc0)
jni_onload_offset = 0x1bdc
jni_onload_bytes = elf[jni_onload_offset:jni_onload_offset + 192]

if has_capstone:
    md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
    for insn in md.disasm(jni_onload_bytes, 0x1bdc):
        print(f"0x{insn.address:06x}:  {insn.mnemonic:<8} {insn.op_str}")
else:
    print("Hex dump of JNI_OnLoad:")
    for i in range(0, len(jni_onload_bytes), 16):
        chunk = jni_onload_bytes[i:i+16]
        print(f"0x{0x1bdc + i:06x}: " + " ".join(f"{b:02x}" for b in chunk))

