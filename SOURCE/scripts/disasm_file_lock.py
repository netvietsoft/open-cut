import capstone, struct

def analyze_file_lock(path):
    print('='*70)
    print('ANALYZING:', path)
    print('='*70)
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
        sections[name] = (struct.unpack('<Q', sh[24:32])[0], struct.unpack('<Q', sh[32:40])[0])

    dynsym_off, dynsym_sz = sections['.dynsym']
    dynstr_off, dynstr_sz = sections['.dynstr']
    dynstr = data[dynstr_off : dynstr_off + dynstr_sz]

    # PLT resolution
    plt_map = {}
    if '.rela.plt' in sections and '.plt' in sections:
        rela_off, rela_sz = sections['.rela.plt']
        plt_off, _ = sections['.plt']
        num_rela = rela_sz // 24
        for k in range(num_rela):
            r_entry = data[rela_off + k * 24 : rela_off + (k + 1) * 24]
            r_offset, r_info, _ = struct.unpack('<QQq', r_entry)
            sym_idx = r_info >> 32
            sym_entry = data[dynsym_off + sym_idx * 24 : dynsym_off + (sym_idx + 1) * 24]
            st_name = struct.unpack('<I', sym_entry[0:4])[0]
            sym_name = dynstr[st_name : dynstr.find(b'\x00', st_name)].decode('ascii')
            # In ARM64 ELF, first PLT entry is 32 bytes, each subsequent is 16 bytes
            plt_addr = plt_off + 32 + k * 16
            plt_map[plt_addr] = sym_name

    print('PLT MAP:', {hex(k): v for k, v in plt_map.items()})

    # Read .rodata
    if '.rodata' in sections:
        ro_off, ro_sz = sections['.rodata']
        ro_data = data[ro_off : ro_off + ro_sz]
        i = 0
        while i < len(ro_data):
            if 32 <= ro_data[i] <= 126:
                j = i
                while j < len(ro_data) and ro_data[j] != 0:
                    j += 1
                if j - i >= 3:
                    s = ro_data[i:j].decode('latin1')
                    print(f'  rodata @ 0x{ro_off + i:04x}: "{s}"')
                i = j + 1
            else:
                i += 1

    # Disassemble functions
    md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
    num_syms = dynsym_sz // 24
    funcs = []
    for i in range(num_syms):
        sym = data[dynsym_off + i * 24 : dynsym_off + (i + 1) * 24]
        st_name = struct.unpack('<I', sym[0:4])[0]
        st_value = struct.unpack('<Q', sym[8:16])[0]
        st_size = struct.unpack('<Q', sym[16:24])[0]
        name = dynstr[st_name : dynstr.find(b'\x00', st_name)].decode('ascii')
        if st_value > 0 and st_size > 0:
            funcs.append((name, st_value, st_size))

    funcs.sort(key=lambda x: x[1])
    for name, off, sz in funcs:
        print(f'\n--- {name} @ 0x{off:04x} ({sz}B) ---')
        code = data[off : off + sz]
        for ins in md.disasm(code, off):
            comment = ''
            if ins.mnemonic.startswith('bl') or ins.mnemonic.startswith('b'):
                try:
                    tgt = int(ins.op_str.strip('#'), 16)
                    if tgt in plt_map:
                        comment = f' // CALL {plt_map[tgt]}'
                except:
                    pass
            print(f'  0x{ins.address:04x}: {ins.bytes.hex():10} {ins.mnemonic:8} {ins.op_str:30}{comment}')

analyze_file_lock('apktool-res/lib/arm64-v8a/libfile_lock.so')
analyze_file_lock('apktool-res/lib/arm64-v8a/libfile_lock_pgl.so')
