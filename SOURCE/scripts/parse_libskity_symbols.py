import struct

def parse_elf_symbols(path):
    with open(path, 'rb') as f:
        data = f.read()
    if data[:4] != b'\x7fELF':
        return []
    e_shoff = struct.unpack('<Q', data[40:48])[0]
    e_shentsize = struct.unpack('<H', data[58:60])[0]
    e_shnum = struct.unpack('<H', data[60:62])[0]
    e_shstrndx = struct.unpack('<H', data[62:64])[0]
    
    sections = []
    for i in range(e_shnum):
        off = e_shoff + i * e_shentsize
        sh = struct.unpack('<IIQQQQIIQQ', data[off:off+64])
        sections.append({
            'sh_name': sh[0], 'sh_type': sh[1], 'sh_flags': sh[2],
            'sh_addr': sh[3], 'sh_offset': sh[4], 'sh_size': sh[5],
            'sh_link': sh[6], 'sh_info': sh[7], 'sh_addralign': sh[8],
            'sh_entsize': sh[9]
        })
    shstr = sections[e_shstrndx]
    shstr_data = data[shstr['sh_offset']:shstr['sh_offset']+shstr['sh_size']]
    
    for s in sections:
        name_end = shstr_data.find(b'\x00', s['sh_name'])
        s['name'] = shstr_data[s['sh_name']:name_end].decode('ascii', errors='ignore')
    
    dynsym = next((s for s in sections if s['name'] == '.dynsym'), None)
    dynstr = next((s for s in sections if s['name'] == '.dynstr'), None)
    if not dynsym or not dynstr:
        return []
        
    dynstr_data = data[dynstr['sh_offset']:dynstr['sh_offset']+dynstr['sh_size']]
    syms = []
    num_syms = dynsym['sh_size'] // dynsym['sh_entsize']
    for i in range(num_syms):
        off = dynsym['sh_offset'] + i * dynsym['sh_entsize']
        st = struct.unpack('<IBBHQQ', data[off:off+24])
        st_name = st[0]
        st_value = st[4]
        st_size = st[5]
        name_end = dynstr_data.find(b'\x00', st_name)
        sym_name = dynstr_data[st_name:name_end].decode('ascii', errors='ignore')
        if sym_name and st_value > 0:
            syms.append({'name': sym_name, 'addr': hex(st_value), 'val': st_value, 'size': st_size})
    return syms

if __name__ == '__main__':
    syms = parse_elf_symbols('extracted/lib/arm64-v8a/libskity.so')
    classes = ['Matrix', 'Path', 'Canvas', 'Paint', 'Shader', 'Stroke', 'PathMeasure', 'MaskFilter', 'ColorFilter', 'RRect', 'Rect', 'Quaternion']
    for c in classes:
        csyms = [s for s in syms if c in s['name']]
        print(f'=== Class {c}: {len(csyms)} symbols ===')
        for s in csyms[:8]:
            print(f"  {s['addr']} ({s['size']}B): {s['name']}")

