import capstone
import struct

def main():
    with open('extracted/lib/arm64-v8a/libskity.so', 'rb') as f:
        data = f.read()

    md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)

    targets = [
        ('Rect::RoundOut', 0xf07e8, 20),
        ('Rect::Intersect', 0xf09b0, 72),
        ('Rect::MakeInset', 0xf0864, 28),
        ('Matrix::MapPoints', 0xef72c, 140),
        ('Matrix::HasPersp', 0xeecac, 60),
        ('MaskFilter::MakeBlur', 0xebcdc, 124),
        ('Path::AddCircle', 0xf87e8, 64),
        ('PathMeasure::GetPosTan', 0xfb370, 132),
        ('Paint::ComputeFastBounds', 0xf6718, 120),
        ('Quaternion::Dot', 0xf0224, 36),
        ('Quaternion::Reciprocal', 0xf0500, 24),
        ('Canvas::Flush', 0x107174, 12)
    ]

    for name, addr, sz in targets:
        chunk = data[addr:addr+sz]
        print(f"==================================================")
        print(f">>> {name} @ {hex(addr)} ({sz} bytes)")
        print(f"==================================================")
        for ins in md.disasm(chunk, addr):
            bytes_str = ' '.join(f'{b:02x}' for b in ins.bytes)
            print(f"  {hex(ins.address)}: {bytes_str:<12} {ins.mnemonic:<8} {ins.op_str}")
        print()

if __name__ == '__main__':
    main()
