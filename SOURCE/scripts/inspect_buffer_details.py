import struct

def get_plt_and_rodata(path):
    with open(path, 'rb') as f:
        data = f.read()
    e_shoff = struct.unpack('<Q', data[40:48])[0]
    e_shentsize = struct.unpack('<H', data[58:60])[0]
    e_shnum = struct.unpack('<H', data[60:62])[0]
    e_shstrndx = struct.unpack('<H', data[62:64])[0]
    shstr_hdr = data[e_shoff + e_shstrndx * e_shentsize : e_shoff + (e_shstrndx + 1) * e_shentsize]
    shstr_offset = struct.unpack('<Q', shstr_hdr[24:32])[0]
    shstr_size = struct.unpack('<Q', shstr_hdr[32:40])[0]
    shstrtab = data[shstr_offset : shstr_offset + shstr_size]
    def get_sh_name(idx):
        return shstrtab[idx:shstrtab.find(b'\x00', idx)].decode('ascii')
    
    sections = {}
    for i in range(e_shnum):
        sh = data[e_shoff + i * e_shentsize : e_shoff + (i + 1) * e_shentsize]
        name = get_sh_name(struct.unpack('<I', sh[0:4])[0])
        offset = struct.unpack('<Q', sh[24:32])[0]
        size = struct.unpack('<Q', sh[32:40])[0]
        sections[name] = (offset, size)
    
    # Read .rodata
    ro_off, ro_sz = sections['.rodata']
    print(f'rodata: off=0x{ro_off:x}, sz=0x{ro_sz:x}')
    ro_data = data[ro_off:ro_off+ro_sz]
    i = 0
    while i < len(ro_data):
        if ro_data[i] >= 32 and ro_data[i] <= 126:
            j = i
            while j < len(ro_data) and ro_data[j] != 0:
                j += 1
            if j - i >= 3:
                s = ro_data[i:j].decode('latin1')
                print(f'  rodata @ 0x{ro_off + i:04x}: "{s}"')
            i = j + 1
        else:
            i += 1

    # Inspect PLT entries
    plt_off, plt_sz = sections['.plt']
    print(f'plt: off=0x{plt_off:x}, sz=0x{plt_sz:x}')

    # Check rela.plt to see which symbols are called at PLT
    rela_off, rela_sz = sections['.rela.plt']
    dynsym_off, dynsym_sz = sections['.dynsym']
    dynstr_off, dynstr_sz = sections['.dynstr']
    dynstr = data[dynstr_off:dynstr_off+dynstr_sz]
    
    num_rela = rela_sz // 24
    print(f'rela.plt entries ({num_rela}):')
    for k in range(num_rela):
        r_entry = data[rela_off + k * 24 : rela_off + (k + 1) * 24]
        r_offset, r_info, r_addend = struct.unpack('<QQq', r_entry)
        sym_idx = r_info >> 32
        sym_entry = data[dynsym_off + sym_idx * 24 : dynsym_off + (sym_idx + 1) * 24]
        st_name = struct.unpack('<I', sym_entry[0:4])[0]
        sym_name = dynstr[st_name : dynstr.find(b'\x00', st_name)].decode('ascii')
        plt_addr = plt_off + 32 + k * 16
        print(f'  plt 0x{plt_addr:04x} -> {sym_name:20} (got 0x{r_offset:x})')

print('=== LIBBUFFER.SO ===')
get_plt_and_rodata('apktool-res/lib/arm64-v8a/libbuffer.so')
print('\n=== LIBBUFFER_PGL.SO ===')
get_plt_and_rodata('apktool-res/lib/arm64-v8a/libbuffer_pgl.so')
