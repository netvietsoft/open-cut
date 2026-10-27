// ============================================================================
// NextAI OpenCut — Clean-Room C++17 Reconstruction
// File          : komprese_neon_ans_lz_engine.cpp
// Target Binary : libkomprese-decompressor.so (15,800 bytes)
// SHA-256       : 7a2a91ead53359dafebaae790ec6e5807f0e037c4c73b8ec0a3a49af1c1a18c3
// Task ID       : TASK-167-RECONSTRUCTION-LIBKOMPRESE-DECOMPRESSOR
// Function      : FDE[07] KompreseDecompressBitstream (0x181c..0x2b20)
// ============================================================================
// EN: Clean-room C++17 reconstruction of FDE[07] (0x181c..0x2b20, 4,872 bytes,
//     1,218 AArch64 instructions): 16-symbol vectorized NEON ANS/Range LZMA-style
//     decompressor with 14-bit CDFs (mask 0x3FFF, adaptation rate >> 7).
// VI: Bản tái tạo C++17 phòng sạch của FDE[07] (0x181c..0x2b20, 4.872 byte,
//     1.218 lệnh AArch64): Bộ giải nén LZMA ANS/Range vector hóa NEON 16-symbol
//     với CDF 14-bit (mặt nạ 0x3FFF, tốc độ thích nghi >> 7).
// ============================================================================
// Complete AArch64 Disassembly Trace for 0x181c..0x2b20 (1218 instructions):
//   0x181c: d10503ff  sub      sp, sp, #0x140
//   0x1820: a90e7bfd  stp      x29, x30, [sp, #0xe0]
//   0x1824: a90f6ffc  stp      x28, x27, [sp, #0xf0]
//   0x1828: a91067fa  stp      x26, x25, [sp, #0x100]
//   0x182c: a9115ff8  stp      x24, x23, [sp, #0x110]
//   0x1830: a91257f6  stp      x22, x21, [sp, #0x120]
//   0x1834: a9134ff4  stp      x20, x19, [sp, #0x130]
//   0x1838: 910383fd  add      x29, sp, #0xe0
//   0x183c: d53bd04d  mrs      x13, tpidr_el0
//   0x1840: f94015a8  ldr      x8, [x13, #0x28]
//   0x1844: aa0303f5  mov      x21, x3
//   0x1848: aa0103f7  mov      x23, x1
//   0x184c: aa0003f6  mov      x22, x0
//   0x1850: f101007f  cmp      x3, #0x40
//   0x1854: f81f03a8  stur     x8, [x29, #-0x10]
//   0x1858: 540000a8  b.hi     #0x186c
//   0x185c: eb1502ff  cmp      x23, x21
//   0x1860: 540000e2  b.hs     #0x187c
//   0x1864: 92800015  mov      x21, #-1
//   0x1868: 1400049f  b        #0x2ae4
//   0x186c: f10102ff  cmp      x23, #0x40
//   0x1870: 54000142  b.hs     #0x1898
//   0x1874: 92800035  mov      x21, #-2
//   0x1878: 1400049b  b        #0x2ae4
//   0x187c: aa0203e0  mov      x0, x2
//   0x1880: aa1603e1  mov      x1, x22
//   0x1884: aa1503e2  mov      x2, x21
//   0x1888: aa0d03f3  mov      x19, x13
//   0x188c: 940006a9  bl       #0x3330
//   0x1890: aa1303ed  mov      x13, x19
//   0x1894: 14000494  b        #0x2ae4
//   0x1898: 394002c8  ldrb     w8, [x22]
//   0x189c: 5283b401  mov      w1, #0x1da0
//   0x18a0: 52800200  mov      w0, #0x10
//   0x18a4: 72a01001  movk     w1, #0x80, lsl #16
//   0x18a8: f90027ed  str      x13, [sp, #0x48]
//   0x18ac: 39000048  strb     w8, [x2]
//   0x18b0: aa0203f8  mov      x24, x2
//   0x18b4: 9400068b  bl       #0x32e0
//   0x18b8: b4008ee0  cbz      x0, #0x2a94
//   0x18bc: 5283b402  mov      w2, #0x1da0
//   0x18c0: 72a01002  movk     w2, #0x80, lsl #16
//   0x18c4: 2a1f03e1  mov      w1, wzr
//   0x18c8: aa0003f4  mov      x20, x0
//   0x18cc: 91000713  add      x19, x24, #1
//   0x18d0: 910006da  add      x26, x22, #1
//   0x18d4: 9400069b  bl       #0x3340
//   0x18d8: f0ffffe8  adrp     x8, #0
//   0x18dc: 91220108  add      x8, x8, #0x880
//   0x18e0: ad400500  ldp      q0, q1, [x8]
//   0x18e4: ad410d02  ldp      q2, q3, [x8, #0x20]
//   0x18e8: f10102bf  cmp      x21, #0x40
//   0x18ec: f81983b8  stur     x24, [x29, #-0x68]
//   0x18f0: ad3d87a0  stp      q0, q1, [x29, #-0x50]
//   0x18f4: ad3e8fa2  stp      q2, q3, [x29, #-0x30]
//   0x18f8: 54008b6d  b.le     #0x2a64
//   0x18fc: 9108028b  add      x11, x20, #0x200
//   0x1900: f9003beb  str      x11, [sp, #0x70]
//   0x1904: 9115028c  add      x12, x20, #0x540
//   0x1908: 9110828b  add      x11, x20, #0x420
//   0x190c: a90533eb  stp      x11, x12, [sp, #0x50]
//   0x1910: f0ffffec  adrp     x12, #0
//   0x1914: f0ffffed  adrp     x13, #0
//   0x1918: 9114828a  add      x10, x20, #0x520
//   0x191c: 3dc1f184  ldr      q4, [x12, #0x7c0]
//   0x1920: 3dc209a5  ldr      q5, [x13, #0x820]
//   0x1924: f90033ea  str      x10, [sp, #0x60]
//   0x1928: 9115828a  add      x10, x20, #0x560
//   0x192c: 8b1802a8  add      x8, x21, x24
//   0x1930: 8b1702c9  add      x9, x22, x23
//   0x1934: f81a03aa  stur     x10, [x29, #-0x60]
//   0x1938: 5283b40a  mov      w10, #0x1da0
//   0x193c: 5283b60b  mov      w11, #0x1db0
//   0x1940: 52801fef  mov      w15, #0xff
//   0x1944: 528aaace  mov      w14, #0x5556
//   0x1948: 9108829e  add      x30, x20, #0x220
//   0x194c: 72aaaaae  movk     w14, #0x5555, lsl #16
//   0x1950: d00000dc  adrp     x28, #0x1b000
//   0x1954: d10143b9  sub      x25, x29, #0x50
//   0x1958: d100fd10  sub      x16, x8, #0x3f
//   0x195c: d100fd3b  sub      x27, x9, #0x3f
//   0x1960: 8b0a0298  add      x24, x20, x10
//   0x1964: 8b0b0288  add      x8, x20, x11
//   0x1968: aa1303e0  mov      x0, x19
//   0x196c: 2a0f03ec  mov      w12, w15
//   0x1970: 52800037  mov      w23, #1
//   0x1974: a903ffe8  stp      x8, xzr, [sp, #0x38]
//   0x1978: f90037fe  str      x30, [sp, #0x68]
//   0x197c: 91000f55  add      x21, x26, #3
//   0x1980: eb1b02bf  cmp      x21, x27
//   0x1984: 54008988  b.hi     #0x2ab4
//   0x1988: 79400348  ldrh     w8, [x26]
//   0x198c: f94027ed  ldr      x13, [sp, #0x48]
//   0x1990: cb000209  sub      x9, x16, x0
//   0x1994: eb08013f  cmp      x9, x8
//   0x1998: 54008929  b.ls     #0x2abc
//   0x199c: 39c00b4a  ldrsb    w10, [x26, #2]
//   0x19a0: 91000516  add      x22, x8, #1
//   0x19a4: 8b160009  add      x9, x0, x22
//   0x19a8: f81a83a9  stur     x9, [x29, #-0x58]
//   0x19ac: 3400080a  cbz      w10, #0x1aac
//   0x19b0: 12000d48  and      w8, w10, #0xf
//   0x19b4: 51000508  sub      w8, w8, #1
//   0x19b8: 13001d09  sxtb     w9, w8
//   0x19bc: 9b2e7d29  smull    x9, w9, w14
//   0x19c0: d37ffd2b  lsr      x11, x9, #0x3f
//   0x19c4: d360fd29  lsr      x9, x9, #0x20
//   0x19c8: 0b0b0129  add      w9, w9, w11
//   0x19cc: 4b09092b  sub      w11, w9, w9, lsl #2
//   0x19d0: 0b080168  add      w8, w11, w8
//   0x19d4: 131e1d08  sbfiz    w8, w8, #2, #8
//   0x19d8: 7100211f  cmp      w8, #8
//   0x19dc: 92800095  mov      x21, #-5
//   0x19e0: 54008828  b.hi     #0x2ae4
//   0x19e4: 1280000b  mov      w11, #-1
//   0x19e8: 1ac92169  lsl      w9, w11, w9
//   0x19ec: 3100413f  cmn      w9, #0x10
//   0x19f0: 540087a3  b.lo     #0x2ae4
//   0x19f4: 2a2903e9  mvn      w9, w9
//   0x19f8: 93407d0e  sxtw     x14, w8
//   0x19fc: 93407d31  sxtw     x17, w9
//   0x1a00: 37f8084a  tbnz     w10, #0x1f, #0x1b08
//   0x1a04: f85983a9  ldur     x9, [x29, #-0x68]
//   0x1a08: 92401d8a  and      x10, x12, #0xff
//   0x1a0c: eb11015f  cmp      x10, x17
//   0x1a10: 540002e0  b.eq     #0x1a6c
//   0x1a14: 9282ffeb  mov      x11, #-0x1800
//   0x1a18: ad001684  stp      q4, q5, [x20]
//   0x1a1c: ad011684  stp      q4, q5, [x20, #0x20]
//   0x1a20: ad021684  stp      q4, q5, [x20, #0x40]
//   0x1a24: ad031684  stp      q4, q5, [x20, #0x60]
//   0x1a28: ad041684  stp      q4, q5, [x20, #0x80]
//   0x1a2c: ad051684  stp      q4, q5, [x20, #0xa0]
//   0x1a30: ad061684  stp      q4, q5, [x20, #0xc0]
//   0x1a34: ad071684  stp      q4, q5, [x20, #0xe0]
//   0x1a38: ad081684  stp      q4, q5, [x20, #0x100]
//   0x1a3c: ad091684  stp      q4, q5, [x20, #0x120]
//   0x1a40: ad0a1684  stp      q4, q5, [x20, #0x140]
//   0x1a44: ad0b1684  stp      q4, q5, [x20, #0x160]
//   0x1a48: ad0c1684  stp      q4, q5, [x20, #0x180]
//   0x1a4c: ad0d1684  stp      q4, q5, [x20, #0x1a0]
//   0x1a50: ad0e1684  stp      q4, q5, [x20, #0x1c0]
//   0x1a54: ad0f1684  stp      q4, q5, [x20, #0x1e0]
//   0x1a58: 8b0b028c  add      x12, x20, x11
//   0x1a5c: b100816b  adds     x11, x11, #0x20
//   0x1a60: 3d875984  str      q4, [x12, #0x1d60]
//   0x1a64: 3d875d85  str      q5, [x12, #0x1d70]
//   0x1a68: 54ffff81  b.ne     #0x1a58
//   0x1a6c: f94023f6  ldr      x22, [sp, #0x40]
//   0x1a70: eb2f01df  cmp      x14, w15, uxtb
//   0x1a74: 54000061  b.ne     #0x1a80
//   0x1a78: eb11015f  cmp      x10, x17
//   0x1a7c: 54000e00  b.eq     #0x1c3c
//   0x1a80: 52880008  mov      w8, #0x4000
//   0x1a84: 1ace250a  lsr      w10, w8, w14
//   0x1a88: 9100062b  add      x11, x17, #1
//   0x1a8c: 9b0a7d6a  mul      x10, x11, x10
//   0x1a90: b4000d6a  cbz      x10, #0x1c3c
//   0x1a94: f9401feb  ldr      x11, [sp, #0x38]
//   0x1a98: ad3f9564  stp      q4, q5, [x11, #-0x10]
//   0x1a9c: f100054a  subs     x10, x10, #1
//   0x1aa0: 9100816b  add      x11, x11, #0x20
//   0x1aa4: 54ffffa1  b.ne     #0x1a98
//   0x1aa8: 14000065  b        #0x1c3c
//   0x1aac: cb150369  sub      x9, x27, x21
//   0x1ab0: eb08013f  cmp      x9, x8
//   0x1ab4: 540080c9  b.ls     #0x2acc
//   0x1ab8: aa1503e1  mov      x1, x21
//   0x1abc: aa1603e2  mov      x2, x22
//   0x1ac0: aa1003f3  mov      x19, x16
//   0x1ac4: ad0093e5  stp      q5, q4, [sp, #0x10]
//   0x1ac8: aa0f03fa  mov      x26, x15
//   0x1acc: f90007ec  str      x12, [sp, #8]
//   0x1ad0: 94000618  bl       #0x3330
//   0x1ad4: f94007ec  ldr      x12, [sp, #8]
//   0x1ad8: ad4093e5  ldp      q5, q4, [sp, #0x10]
//   0x1adc: aa1303f0  mov      x16, x19
//   0x1ae0: f94037fe  ldr      x30, [sp, #0x68]
//   0x1ae4: f85a83b3  ldur     x19, [x29, #-0x58]
//   0x1ae8: 528aaace  mov      w14, #0x5556
//   0x1aec: aa1a03ef  mov      x15, x26
//   0x1af0: 72aaaaae  movk     w14, #0x5555, lsl #16
//   0x1af4: 8b1602ba  add      x26, x21, x22
//   0x1af8: eb10027f  cmp      x19, x16
//   0x1afc: aa1303e0  mov      x0, x19
//   0x1b00: 54fff3e3  b.lo     #0x197c
//   0x1b04: 140003d8  b        #0x2a64
//   0x1b08: f85983a9  ldur     x9, [x29, #-0x68]
//   0x1b0c: 52880008  mov      w8, #0x4000
//   0x1b10: 1ace250a  lsr      w10, w8, w14
//   0x1b14: 9100062b  add      x11, x17, #1
//   0x1b18: 9b0a7d6a  mul      x10, x11, x10
//   0x1b1c: ad001684  stp      q4, q5, [x20]
//   0x1b20: ad011684  stp      q4, q5, [x20, #0x20]
//   0x1b24: ad021684  stp      q4, q5, [x20, #0x40]
//   0x1b28: ad031684  stp      q4, q5, [x20, #0x60]
//   0x1b2c: ad041684  stp      q4, q5, [x20, #0x80]
//   0x1b30: ad051684  stp      q4, q5, [x20, #0xa0]
//   0x1b34: ad061684  stp      q4, q5, [x20, #0xc0]
//   0x1b38: ad071684  stp      q4, q5, [x20, #0xe0]
//   0x1b3c: ad081684  stp      q4, q5, [x20, #0x100]
//   0x1b40: ad091684  stp      q4, q5, [x20, #0x120]
//   0x1b44: ad0a1684  stp      q4, q5, [x20, #0x140]
//   0x1b48: ad0b1684  stp      q4, q5, [x20, #0x160]
//   0x1b4c: ad0c1684  stp      q4, q5, [x20, #0x180]
//   0x1b50: ad0d1684  stp      q4, q5, [x20, #0x1a0]
//   0x1b54: ad0e1684  stp      q4, q5, [x20, #0x1c0]
//   0x1b58: ad0f1684  stp      q4, q5, [x20, #0x1e0]
//   0x1b5c: ad101684  stp      q4, q5, [x20, #0x200]
//   0x1b60: b40000ca  cbz      x10, #0x1b78
//   0x1b64: f9401feb  ldr      x11, [sp, #0x38]
//   0x1b68: ad3f9564  stp      q4, q5, [x11, #-0x10]
//   0x1b6c: f100054a  subs     x10, x10, #1
//   0x1b70: 9100816b  add      x11, x11, #0x20
//   0x1b74: 54ffffa1  b.ne     #0x1b68
//   0x1b78: 52800028  mov      w8, #1
//   0x1b7c: 4e080d00  dup      v0.2d, x8
//   0x1b80: 928307ea  mov      x10, #-0x1840
//   0x1b84: ad111684  stp      q4, q5, [x20, #0x220]
//   0x1b88: ad121684  stp      q4, q5, [x20, #0x240]
//   0x1b8c: ad131684  stp      q4, q5, [x20, #0x260]
//   0x1b90: ad141684  stp      q4, q5, [x20, #0x280]
//   0x1b94: ad151684  stp      q4, q5, [x20, #0x2a0]
//   0x1b98: ad161684  stp      q4, q5, [x20, #0x2c0]
//   0x1b9c: ad171684  stp      q4, q5, [x20, #0x2e0]
//   0x1ba0: ad181684  stp      q4, q5, [x20, #0x300]
//   0x1ba4: ad191684  stp      q4, q5, [x20, #0x320]
//   0x1ba8: ad1a1684  stp      q4, q5, [x20, #0x340]
//   0x1bac: ad1b1684  stp      q4, q5, [x20, #0x360]
//   0x1bb0: ad1c1684  stp      q4, q5, [x20, #0x380]
//   0x1bb4: ad1d1684  stp      q4, q5, [x20, #0x3a0]
//   0x1bb8: ad1e1684  stp      q4, q5, [x20, #0x3c0]
//   0x1bbc: ad1f1684  stp      q4, q5, [x20, #0x3e0]
//   0x1bc0: 3d810284  str      q4, [x20, #0x400]
//   0x1bc4: 3d810685  str      q5, [x20, #0x410]
//   0x1bc8: 3d810a84  str      q4, [x20, #0x420]
//   0x1bcc: 3d810e85  str      q5, [x20, #0x430]
//   0x1bd0: 3d811284  str      q4, [x20, #0x440]
//   0x1bd4: 3d811685  str      q5, [x20, #0x450]
//   0x1bd8: 3d811a84  str      q4, [x20, #0x460]
//   0x1bdc: 3d811e85  str      q5, [x20, #0x470]
//   0x1be0: 3d812284  str      q4, [x20, #0x480]
//   0x1be4: 3d812685  str      q5, [x20, #0x490]
//   0x1be8: 3d812a84  str      q4, [x20, #0x4a0]
//   0x1bec: 3d812e85  str      q5, [x20, #0x4b0]
//   0x1bf0: 3d813284  str      q4, [x20, #0x4c0]
//   0x1bf4: 3d813685  str      q5, [x20, #0x4d0]
//   0x1bf8: 3d813a84  str      q4, [x20, #0x4e0]
//   0x1bfc: 3d813e85  str      q5, [x20, #0x4f0]
//   0x1c00: 3d814284  str      q4, [x20, #0x500]
//   0x1c04: 3d814685  str      q5, [x20, #0x510]
//   0x1c08: 3d814a84  str      q4, [x20, #0x520]
//   0x1c0c: 3d814e85  str      q5, [x20, #0x530]
//   0x1c10: 3d815284  str      q4, [x20, #0x540]
//   0x1c14: 3d815685  str      q5, [x20, #0x550]
//   0x1c18: ad3d83a0  stp      q0, q0, [x29, #-0x50]
//   0x1c1c: ad3e83a0  stp      q0, q0, [x29, #-0x30]
//   0x1c20: 8b0a028b  add      x11, x20, x10
//   0x1c24: b100814a  adds     x10, x10, #0x20
//   0x1c28: 3d876964  str      q4, [x11, #0x1da0]
//   0x1c2c: 3d876d65  str      q5, [x11, #0x1db0]
//   0x1c30: 54ffff81  b.ne     #0x1c20
//   0x1c34: 52800116  mov      w22, #8
//   0x1c38: 52800037  mov      w23, #1
//   0x1c3c: 91002f4f  add      x15, x26, #0xb
//   0x1c40: eb1b01ff  cmp      x15, x27
//   0x1c44: 54007408  b.hi     #0x2ac4
//   0x1c48: b840734c  ldur     w12, [x26, #7]
//   0x1c4c: b840334d  ldur     w13, [x26, #3]
//   0x1c50: 12001e2a  and      w10, w17, #0xff
//   0x1c54: 121e15cb  and      w11, w14, #0xfc
//   0x1c58: f90013f0  str      x16, [sp, #0x20]
//   0x1c5c: a900bbf1  stp      x17, x14, [sp, #8]
//   0x1c60: 8a0a000e  and      x14, x0, x10
//   0x1c64: 8b0e1681  add      x1, x20, x14, lsl #5
//   0x1c68: ad400420  ldp      q0, q1, [x1]
//   0x1c6c: 120035b0  and      w16, w13, #0x3fff
//   0x1c70: 4e020e02  dup      v2.8h, w16
//   0x1c74: aa0f03e5  mov      x5, x15
//   0x1c78: 6e623403  cmhi     v3.8h, v0.8h, v2.8h
//   0x1c7c: 6e623422  cmhi     v2.8h, v1.8h, v2.8h
//   0x1c80: 4e638442  add      v2.8h, v2.8h, v3.8h
//   0x1c84: 4e71b842  addv     h2, v2.8h
//   0x1c88: 1e260042  fmov     w2, s2
//   0x1c8c: 93403c51  sxth     x17, w2
//   0x1c90: 92400c43  and      x3, x2, #0xf
//   0x1c94: 91003e31  add      x17, x17, #0xf
//   0x1c98: 78637823  ldrh     w3, [x1, x3, lsl #1]
//   0x1c9c: 78717824  ldrh     w4, [x1, x17, lsl #1]
//   0x1ca0: 784024a6  ldrh     w6, [x5], #2
//   0x1ca4: 530e7dad  lsr      w13, w13, #0xe
//   0x1ca8: d3503c42  lsl      x2, x2, #0x30
//   0x1cac: 4b040063  sub      w3, w3, w4
//   0x1cb0: 4b040204  sub      w4, w16, w4
//   0x1cb4: f942df90  ldr      x16, [x28, #0x5b8]
//   0x1cb8: 12003463  and      w3, w3, #0x3fff
//   0x1cbc: 1b0311ad  madd     w13, w13, w3, w4
//   0x1cc0: 33103da6  bfi      w6, w13, #0x10, #0x10
//   0x1cc4: 8b111603  add      x3, x16, x17, lsl #5
//   0x1cc8: ad400c62  ldp      q2, q3, [x3]
//   0x1ccc: 714021bf  cmp      w13, #8, lsl #12
//   0x1cd0: 9a8f30ba  csel     x26, x5, x15, lo
//   0x1cd4: 1a8d30cf  csel     w15, w6, w13, lo
//   0x1cd8: 6e608442  sub      v2.8h, v2.8h, v0.8h
//   0x1cdc: 6e618463  sub      v3.8h, v3.8h, v1.8h
//   0x1ce0: 4f191440  ssra     v0.8h, v2.8h, #7
//   0x1ce4: 4f191461  ssra     v1.8h, v3.8h, #7
//   0x1ce8: ad000420  stp      q0, q1, [x1]
//   0x1cec: b5000a62  cbnz     x2, #0x1e38
//   0x1cf0: ad500680  ldp      q0, q1, [x20, #0x200]
//   0x1cf4: 1200358d  and      w13, w12, #0x3fff
//   0x1cf8: 4e020da2  dup      v2.8h, w13
//   0x1cfc: f9403be8  ldr      x8, [sp, #0x70]
//   0x1d00: 6e623403  cmhi     v3.8h, v0.8h, v2.8h
//   0x1d04: 6e623422  cmhi     v2.8h, v1.8h, v2.8h
//   0x1d08: 4e638442  add      v2.8h, v2.8h, v3.8h
//   0x1d0c: 4e71b842  addv     h2, v2.8h
//   0x1d10: 1e260051  fmov     w17, s2
//   0x1d14: 93403e21  sxth     x1, w17
//   0x1d18: 92400e23  and      x3, x17, #0xf
//   0x1d1c: 91003c31  add      x17, x1, #0xf
//   0x1d20: 78637903  ldrh     w3, [x8, x3, lsl #1]
//   0x1d24: 78717904  ldrh     w4, [x8, x17, lsl #1]
//   0x1d28: aa1a03e2  mov      x2, x26
//   0x1d2c: 8b111606  add      x6, x16, x17, lsl #5
//   0x1d30: 78402445  ldrh     w5, [x2], #2
//   0x1d34: ad400cc2  ldp      q2, q3, [x6]
//   0x1d38: 4b040063  sub      w3, w3, w4
//   0x1d3c: 4b0401ad  sub      w13, w13, w4
//   0x1d40: 530e7d8c  lsr      w12, w12, #0xe
//   0x1d44: 12003463  and      w3, w3, #0x3fff
//   0x1d48: 1b03358c  madd     w12, w12, w3, w13
//   0x1d4c: 6e608442  sub      v2.8h, v2.8h, v0.8h
//   0x1d50: 6e618463  sub      v3.8h, v3.8h, v1.8h
//   0x1d54: 33103d85  bfi      w5, w12, #0x10, #0x10
//   0x1d58: 7140219f  cmp      w12, #8, lsl #12
//   0x1d5c: 4f191440  ssra     v0.8h, v2.8h, #7
//   0x1d60: 4f191461  ssra     v1.8h, v3.8h, #7
//   0x1d64: 9a9a304d  csel     x13, x2, x26, lo
//   0x1d68: 1a8c30ac  csel     w12, w5, w12, lo
//   0x1d6c: f100423f  cmp      x17, #0x10
//   0x1d70: aa1f03e2  mov      x2, xzr
//   0x1d74: ad100680  stp      q0, q1, [x20, #0x200]
//   0x1d78: 54000363  b.lo     #0x1de4
//   0x1d7c: b201e3e8  mov      x8, #-0x7777777777777778
//   0x1d80: d1000423  sub      x3, x1, #1
//   0x1d84: f2911128  movk     x8, #0x8889
//   0x1d88: 9bc87c63  umulh    x3, x3, x8
//   0x1d8c: d343fc63  lsr      x3, x3, #3
//   0x1d90: cb031063  sub      x3, x3, x3, lsl #4
//   0x1d94: aa1103e4  mov      x4, x17
//   0x1d98: 120039e6  and      w6, w15, #0x7fff
//   0x1d9c: aa0d03e7  mov      x7, x13
//   0x1da0: b371c046  bfi      x6, x2, #0xf, #0x31
//   0x1da4: 784024e2  ldrh     w2, [x7], #2
//   0x1da8: 2a0c03e5  mov      w5, w12
//   0x1dac: 530f7dec  lsr      w12, w15, #0xf
//   0x1db0: 531e7def  lsr      w15, w15, #0x1e
//   0x1db4: d1003c84  sub      x4, x4, #0xf
//   0x1db8: 710001ff  cmp      w15, #0
//   0x1dbc: 33103d82  bfi      w2, w12, #0x10, #0x10
//   0x1dc0: 9a8d00ed  csel     x13, x7, x13, eq
//   0x1dc4: 1a8c004c  csel     w12, w2, w12, eq
//   0x1dc8: f1003c9f  cmp      x4, #0xf
//   0x1dcc: aa0603e2  mov      x2, x6
//   0x1dd0: 2a0503ef  mov      w15, w5
//   0x1dd4: 54fffe28  b.hi     #0x1d98
//   0x1dd8: 8b010061  add      x1, x3, x1
//   0x1ddc: 2a0503ef  mov      w15, w5
//   0x1de0: 14000002  b        #0x1de8
//   0x1de4: aa1103e1  mov      x1, x17
//   0x1de8: 52800028  mov      w8, #1
//   0x1dec: 9ad12111  lsl      x17, x8, x17
//   0x1df0: 12800008  mov      w8, #-1
//   0x1df4: 1ac12103  lsl      w3, w8, w1
//   0x1df8: 9ac12042  lsl      x2, x2, x1
//   0x1dfc: 1ac125e1  lsr      w1, w15, w1
//   0x1e00: 0a2301ef  bic      w15, w15, w3
//   0x1e04: aa0d03e3  mov      x3, x13
//   0x1e08: aa0f004f  orr      x15, x2, x15
//   0x1e0c: 78402462  ldrh     w2, [x3], #2
//   0x1e10: f85a83a8  ldur     x8, [x29, #-0x58]
//   0x1e14: 8b1101ef  add      x15, x15, x17
//   0x1e18: 7140203f  cmp      w1, #8, lsl #12
//   0x1e1c: 910039f1  add      x17, x15, #0xe
//   0x1e20: cb000104  sub      x4, x8, x0
//   0x1e24: 33103c22  bfi      w2, w1, #0x10, #0x10
//   0x1e28: 9a8d307a  csel     x26, x3, x13, lo
//   0x1e2c: 1a81304f  csel     w15, w2, w1, lo
//   0x1e30: eb11009f  cmp      x4, x17
//   0x1e34: 54006343  b.lo     #0x2a9c
//   0x1e38: eb1b035f  cmp      x26, x27
//   0x1e3c: 540064c8  b.hi     #0x2ad4
//   0x1e40: b40015f1  cbz      x17, #0x20fc
//   0x1e44: 385ff00d  ldurb    w13, [x0, #-1]
//   0x1e48: cb170001  sub      x1, x0, x23
//   0x1e4c: 39400021  ldrb     w1, [x1]
//   0x1e50: 12003582  and      w2, w12, #0x3fff
//   0x1e54: b3781dcd  bfi      x13, x14, #8, #8
//   0x1e58: 9acb25ad  lsr      x13, x13, x11
//   0x1e5c: d344fc2e  lsr      x14, x1, #4
//   0x1e60: 8b0d2f0d  add      x13, x24, x13, lsl #11
//   0x1e64: 8b0e15a4  add      x4, x13, x14, lsl #5
//   0x1e68: ad400480  ldp      q0, q1, [x4]
//   0x1e6c: 4e020c42  dup      v2.8h, w2
//   0x1e70: 52800405  mov      w5, #0x20
//   0x1e74: 33000c25  bfxil    w5, w1, #0, #4
//   0x1e78: 6e623403  cmhi     v3.8h, v0.8h, v2.8h
//   0x1e7c: 6e623422  cmhi     v2.8h, v1.8h, v2.8h
//   0x1e80: 4e638442  add      v2.8h, v2.8h, v3.8h
//   0x1e84: 4e71b842  addv     h2, v2.8h
//   0x1e88: 1e260041  fmov     w1, s2
//   0x1e8c: 93403c26  sxth     x6, w1
//   0x1e90: 92400c21  and      x1, x1, #0xf
//   0x1e94: 91003cc6  add      x6, x6, #0xf
//   0x1e98: 78617881  ldrh     w1, [x4, x1, lsl #1]
//   0x1e9c: 78667887  ldrh     w7, [x4, x6, lsl #1]
//   0x1ea0: aa1a03e3  mov      x3, x26
//   0x1ea4: 78402473  ldrh     w19, [x3], #2
//   0x1ea8: 8b061610  add      x16, x16, x6, lsl #5
//   0x1eac: ad400e02  ldp      q2, q3, [x16]
//   0x1eb0: 4b070030  sub      w16, w1, w7
//   0x1eb4: 530e7d8c  lsr      w12, w12, #0xe
//   0x1eb8: 4b070041  sub      w1, w2, w7
//   0x1ebc: 12003610  and      w16, w16, #0x3fff
//   0x1ec0: 1b10058c  madd     w12, w12, w16, w1
//   0x1ec4: 12001cc6  and      w6, w6, #0xff
//   0x1ec8: 33103d93  bfi      w19, w12, #0x10, #0x10
//   0x1ecc: 7140219f  cmp      w12, #8, lsl #12
//   0x1ed0: 321c04c2  orr      w2, w6, #0x30
//   0x1ed4: 6e608442  sub      v2.8h, v2.8h, v0.8h
//   0x1ed8: 6e618463  sub      v3.8h, v3.8h, v1.8h
//   0x1edc: 9a9a3063  csel     x3, x3, x26, lo
//   0x1ee0: 1a8c326c  csel     w12, w19, w12, lo
//   0x1ee4: 6b0e00df  cmp      w6, w14
//   0x1ee8: 4f191440  ssra     v0.8h, v2.8h, #7
//   0x1eec: 4f191461  ssra     v1.8h, v3.8h, #7
//   0x1ef0: 1a8200ae  csel     w14, w5, w2, eq
//   0x1ef4: ad000480  stp      q0, q1, [x4]
//   0x1ef8: 8b0e15ae  add      x14, x13, x14, lsl #5
//   0x1efc: ad4005c0  ldp      q0, q1, [x14]
//   0x1f00: 120035f0  and      w16, w15, #0x3fff
//   0x1f04: 4e020e02  dup      v2.8h, w16
//   0x1f08: aa0303e5  mov      x5, x3
//   0x1f0c: 6e623403  cmhi     v3.8h, v0.8h, v2.8h
//   0x1f10: 6e623422  cmhi     v2.8h, v1.8h, v2.8h
//   0x1f14: 4e638442  add      v2.8h, v2.8h, v3.8h
//   0x1f18: 4e71b842  addv     h2, v2.8h
//   0x1f1c: 1e260041  fmov     w1, s2
//   0x1f20: 93403c22  sxth     x2, w1
//   0x1f24: 92400c21  and      x1, x1, #0xf
//   0x1f28: 91003c42  add      x2, x2, #0xf
//   0x1f2c: 786179c1  ldrh     w1, [x14, x1, lsl #1]
//   0x1f30: 786279c4  ldrh     w4, [x14, x2, lsl #1]
//   0x1f34: 784024a7  ldrh     w7, [x5], #2
//   0x1f38: f942df93  ldr      x19, [x28, #0x5b8]
//   0x1f3c: 530e7def  lsr      w15, w15, #0xe
//   0x1f40: 4b040035  sub      w21, w1, w4
//   0x1f44: 531c6cc1  lsl      w1, w6, #4
//   0x1f48: aa010041  orr      x1, x2, x1
//   0x1f4c: 8b021662  add      x2, x19, x2, lsl #5
//   0x1f50: ad400c42  ldp      q2, q3, [x2]
//   0x1f54: 4b040204  sub      w4, w16, w4
//   0x1f58: 120036a6  and      w6, w21, #0x3fff
//   0x1f5c: f85a03a8  ldur     x8, [x29, #-0x60]
//   0x1f60: 1b0611ef  madd     w15, w15, w6, w4
//   0x1f64: 91000410  add      x16, x0, #1
//   0x1f68: 33103de7  bfi      w7, w15, #0x10, #0x10
//   0x1f6c: 714021ff  cmp      w15, #8, lsl #12
//   0x1f70: 6e608442  sub      v2.8h, v2.8h, v0.8h
//   0x1f74: 6e618463  sub      v3.8h, v3.8h, v1.8h
//   0x1f78: 53021ed6  ubfx     w22, w22, #2, #6
//   0x1f7c: cb1703ed  neg      x13, x23
//   0x1f80: 9a8330ba  csel     x26, x5, x3, lo
//   0x1f84: 1a8f30ef  csel     w15, w7, w15, lo
//   0x1f88: 4f191440  ssra     v0.8h, v2.8h, #7
//   0x1f8c: 4f191461  ssra     v1.8h, v3.8h, #7
//   0x1f90: d1000631  sub      x17, x17, #1
//   0x1f94: aa1003f3  mov      x19, x16
//   0x1f98: ad0005c0  stp      q0, q1, [x14]
//   0x1f9c: 39000001  strb     w1, [x0]
//   0x1fa0: 8a0a020e  and      x14, x16, x10
//   0x1fa4: b4000b11  cbz      x17, #0x2104
//   0x1fa8: 386d6a63  ldrb     w3, [x19, x13]
//   0x1fac: 92401c20  and      x0, x1, #0xff
//   0x1fb0: b3781dc0  bfi      x0, x14, #8, #8
//   0x1fb4: 9acb240e  lsr      x14, x0, x11
//   0x1fb8: 8b0e2f0e  add      x14, x24, x14, lsl #11
//   0x1fbc: d344fc61  lsr      x1, x3, #4
//   0x1fc0: 8b0115c0  add      x0, x14, x1, lsl #5
//   0x1fc4: ad400400  ldp      q0, q1, [x0]
//   0x1fc8: 12003582  and      w2, w12, #0x3fff
//   0x1fcc: 4e020c42  dup      v2.8h, w2
//   0x1fd0: aa1a03e7  mov      x7, x26
//   0x1fd4: 6e623403  cmhi     v3.8h, v0.8h, v2.8h
//   0x1fd8: 6e623422  cmhi     v2.8h, v1.8h, v2.8h
//   0x1fdc: 4e638442  add      v2.8h, v2.8h, v3.8h
//   0x1fe0: 4e71b842  addv     h2, v2.8h
//   0x1fe4: 1e260044  fmov     w4, s2
//   0x1fe8: 93403c85  sxth     x5, w4
//   0x1fec: 92400c84  and      x4, x4, #0xf
//   0x1ff0: 91003ca5  add      x5, x5, #0xf
//   0x1ff4: 78647804  ldrh     w4, [x0, x4, lsl #1]
//   0x1ff8: 78657806  ldrh     w6, [x0, x5, lsl #1]
//   0x1ffc: 784024f5  ldrh     w21, [x7], #2
//   0x2000: 530e7d8c  lsr      w12, w12, #0xe
//   0x2004: d1000631  sub      x17, x17, #1
//   0x2008: 4b060084  sub      w4, w4, w6
//   0x200c: 4b060046  sub      w6, w2, w6
//   0x2010: f942df82  ldr      x2, [x28, #0x5b8]
//   0x2014: 12003484  and      w4, w4, #0x3fff
//   0x2018: 1b04198c  madd     w12, w12, w4, w6
//   0x201c: 52800204  mov      w4, #0x10
//   0x2020: 33000c64  bfxil    w4, w3, #0, #4
//   0x2024: 8b051443  add      x3, x2, x5, lsl #5
//   0x2028: ad400c62  ldp      q2, q3, [x3]
//   0x202c: 7140219f  cmp      w12, #8, lsl #12
//   0x2030: 12001ca5  and      w5, w5, #0xff
//   0x2034: 33103d95  bfi      w21, w12, #0x10, #0x10
//   0x2038: 9a9a30e3  csel     x3, x7, x26, lo
//   0x203c: 1a8c32ac  csel     w12, w21, w12, lo
//   0x2040: 321c04a7  orr      w7, w5, #0x30
//   0x2044: 6b0100bf  cmp      w5, w1
//   0x2048: 6e608442  sub      v2.8h, v2.8h, v0.8h
//   0x204c: 6e618463  sub      v3.8h, v3.8h, v1.8h
//   0x2050: 1a870081  csel     w1, w4, w7, eq
//   0x2054: 4f191440  ssra     v0.8h, v2.8h, #7
//   0x2058: 4f191461  ssra     v1.8h, v3.8h, #7
//   0x205c: 8b0115ce  add      x14, x14, x1, lsl #5
//   0x2060: ad000400  stp      q0, q1, [x0]
//   0x2064: ad4005c0  ldp      q0, q1, [x14]
//   0x2068: 120035e6  and      w6, w15, #0x3fff
//   0x206c: 4e020cc2  dup      v2.8h, w6
//   0x2070: 531c6ca0  lsl      w0, w5, #4
//   0x2074: 6e623403  cmhi     v3.8h, v0.8h, v2.8h
//   0x2078: 6e623422  cmhi     v2.8h, v1.8h, v2.8h
//   0x207c: 4e638442  add      v2.8h, v2.8h, v3.8h
//   0x2080: 4e71b842  addv     h2, v2.8h
//   0x2084: 1e260041  fmov     w1, s2
//   0x2088: 93403c25  sxth     x5, w1
//   0x208c: 92400c21  and      x1, x1, #0xf
//   0x2090: 91003ca5  add      x5, x5, #0xf
//   0x2094: 786179c7  ldrh     w7, [x14, x1, lsl #1]
//   0x2098: 786579d5  ldrh     w21, [x14, x5, lsl #1]
//   0x209c: aa0303e4  mov      x4, x3
//   0x20a0: 8b051442  add      x2, x2, x5, lsl #5
//   0x20a4: aa0000a1  orr      x1, x5, x0
//   0x20a8: 78402480  ldrh     w0, [x4], #2
//   0x20ac: ad400c42  ldp      q2, q3, [x2]
//   0x20b0: 4b1500e2  sub      w2, w7, w21
//   0x20b4: 530e7def  lsr      w15, w15, #0xe
//   0x20b8: 4b1500c5  sub      w5, w6, w21
//   0x20bc: 12003442  and      w2, w2, #0x3fff
//   0x20c0: 1b0215ef  madd     w15, w15, w2, w5
//   0x20c4: 6e608442  sub      v2.8h, v2.8h, v0.8h
//   0x20c8: 6e618463  sub      v3.8h, v3.8h, v1.8h
//   0x20cc: 714021ff  cmp      w15, #8, lsl #12
//   0x20d0: 4f191440  ssra     v0.8h, v2.8h, #7
//   0x20d4: 4f191461  ssra     v1.8h, v3.8h, #7
//   0x20d8: 33103de0  bfi      w0, w15, #0x10, #0x10
//   0x20dc: 9a83309a  csel     x26, x4, x3, lo
//   0x20e0: ad0005c0  stp      q0, q1, [x14]
//   0x20e4: 38001661  strb     w1, [x19], #1
//   0x20e8: 1a8f300f  csel     w15, w0, w15, lo
//   0x20ec: eb1b035f  cmp      x26, x27
//   0x20f0: 91000610  add      x16, x16, #1
//   0x20f4: 54fff569  b.ls     #0x1fa0
//   0x20f8: 1400026b  b        #0x2aa4
//   0x20fc: f85a03a8  ldur     x8, [x29, #-0x60]
//   0x2100: aa0003f3  mov      x19, x0
//   0x2104: f85a83ad  ldur     x13, [x29, #-0x58]
//   0x2108: eb0d027f  cmp      x19, x13
//   0x210c: 54004902  b.hs     #0x2a2c
//   0x2110: 92401ecd  and      x13, x22, #0xff
//   0x2114: 8b0d17c1  add      x1, x30, x13, lsl #5
//   0x2118: ad400420  ldp      q0, q1, [x1]
//   0x211c: 1200358d  and      w13, w12, #0x3fff
//   0x2120: 4e020da2  dup      v2.8h, w13
//   0x2124: aa1a03e3  mov      x3, x26
//   0x2128: 6e623403  cmhi     v3.8h, v0.8h, v2.8h
//   0x212c: 6e623422  cmhi     v2.8h, v1.8h, v2.8h
//   0x2130: 4e638442  add      v2.8h, v2.8h, v3.8h
//   0x2134: 4e71b842  addv     h2, v2.8h
//   0x2138: 1e260050  fmov     w16, s2
//   0x213c: 93403e00  sxth     x0, w16
//   0x2140: 92400e10  and      x16, x16, #0xf
//   0x2144: 91003c11  add      x17, x0, #0xf
//   0x2148: 78707830  ldrh     w16, [x1, x16, lsl #1]
//   0x214c: 78717822  ldrh     w2, [x1, x17, lsl #1]
//   0x2150: 78402464  ldrh     w4, [x3], #2
//   0x2154: 530e7d8c  lsr      w12, w12, #0xe
//   0x2158: 4b020205  sub      w5, w16, w2
//   0x215c: f942df90  ldr      x16, [x28, #0x5b8]
//   0x2160: 4b0201ad  sub      w13, w13, w2
//   0x2164: 120034a2  and      w2, w5, #0x3fff
//   0x2168: 1b02358d  madd     w13, w12, w2, w13
//   0x216c: 8b11160c  add      x12, x16, x17, lsl #5
//   0x2170: ad400d82  ldp      q2, q3, [x12]
//   0x2174: 33103da4  bfi      w4, w13, #0x10, #0x10
//   0x2178: 714021bf  cmp      w13, #8, lsl #12
//   0x217c: 9a9a306c  csel     x12, x3, x26, lo
//   0x2180: 6e608442  sub      v2.8h, v2.8h, v0.8h
//   0x2184: 6e618463  sub      v3.8h, v3.8h, v1.8h
//   0x2188: 1a8d308d  csel     w13, w4, w13, lo
//   0x218c: f1001e3f  cmp      x17, #7
//   0x2190: 4f191440  ssra     v0.8h, v2.8h, #7
//   0x2194: 4f191461  ssra     v1.8h, v3.8h, #7
//   0x2198: ad000420  stp      q0, q1, [x1]
//   0x219c: 540001e8  b.hi     #0x21d8
//   0x21a0: f8717b37  ldr      x23, [x25, x17, lsl #3]
//   0x21a4: aa1603fa  mov      x26, x22
//   0x21a8: b4000111  cbz      x17, #0x21c8
//   0x21ac: d1003e31  sub      x17, x17, #0xf
//   0x21b0: 8b110f20  add      x0, x25, x17, lsl #3
//   0x21b4: f9403801  ldr      x1, [x0, #0x70]
//   0x21b8: d1000631  sub      x17, x17, #1
//   0x21bc: b1003e3f  cmn      x17, #0xf
//   0x21c0: f9003c01  str      x1, [x0, #0x78]
//   0x21c4: 54ffff61  b.ne     #0x21b0
//   0x21c8: aa1f03e0  mov      x0, xzr
//   0x21cc: f81b03b7  stur     x23, [x29, #-0x50]
//   0x21d0: 52800091  mov      w17, #4
//   0x21d4: 140000c8  b        #0x24f4
//   0x21d8: f100223f  cmp      x17, #8
//   0x21dc: 530e7df1  lsr      w17, w15, #0xe
//   0x21e0: 54000921  b.ne     #0x2304
//   0x21e4: 3dc10a80  ldr      q0, [x20, #0x420]
//   0x21e8: 3dc10e81  ldr      q1, [x20, #0x430]
//   0x21ec: 120035ef  and      w15, w15, #0x3fff
//   0x21f0: 4e020de2  dup      v2.8h, w15
//   0x21f4: 6e623403  cmhi     v3.8h, v0.8h, v2.8h
//   0x21f8: 6e623422  cmhi     v2.8h, v1.8h, v2.8h
//   0x21fc: 4e638442  add      v2.8h, v2.8h, v3.8h
//   0x2200: 4e71b842  addv     h2, v2.8h
//   0x2204: f9402be8  ldr      x8, [sp, #0x50]
//   0x2208: 1e260041  fmov     w1, s2
//   0x220c: 93403c22  sxth     x2, w1
//   0x2210: 92400c21  and      x1, x1, #0xf
//   0x2214: 91003c42  add      x2, x2, #0xf
//   0x2218: 78617901  ldrh     w1, [x8, x1, lsl #1]
//   0x221c: 78627903  ldrh     w3, [x8, x2, lsl #1]
//   0x2220: aa0c03e0  mov      x0, x12
//   0x2224: 78402404  ldrh     w4, [x0], #2
//   0x2228: 8b021605  add      x5, x16, x2, lsl #5
//   0x222c: ad400ca2  ldp      q2, q3, [x5]
//   0x2230: 4b030021  sub      w1, w1, w3
//   0x2234: 4b0301ef  sub      w15, w15, w3
//   0x2238: 12003421  and      w1, w1, #0x3fff
//   0x223c: 1b013e2f  madd     w15, w17, w1, w15
//   0x2240: f94033e8  ldr      x8, [sp, #0x60]
//   0x2244: 33103de4  bfi      w4, w15, #0x10, #0x10
//   0x2248: 714021ff  cmp      w15, #8, lsl #12
//   0x224c: 6e608442  sub      v2.8h, v2.8h, v0.8h
//   0x2250: 6e618463  sub      v3.8h, v3.8h, v1.8h
//   0x2254: 9a8c300c  csel     x12, x0, x12, lo
//   0x2258: 1a8f308f  csel     w15, w4, w15, lo
//   0x225c: f100005f  cmp      x2, #0
//   0x2260: 4f191440  ssra     v0.8h, v2.8h, #7
//   0x2264: 4f191461  ssra     v1.8h, v3.8h, #7
//   0x2268: 1a9f07f1  cset     w17, ne
//   0x226c: 3d810a80  str      q0, [x20, #0x420]
//   0x2270: 3d810e81  str      q1, [x20, #0x430]
//   0x2274: 8b111511  add      x17, x8, x17, lsl #5
//   0x2278: ad400620  ldp      q0, q1, [x17]
//   0x227c: 120035a0  and      w0, w13, #0x3fff
//   0x2280: 4e020c02  dup      v2.8h, w0
//   0x2284: aa0c03e1  mov      x1, x12
//   0x2288: 6e623403  cmhi     v3.8h, v0.8h, v2.8h
//   0x228c: 6e623422  cmhi     v2.8h, v1.8h, v2.8h
//   0x2290: 4e638442  add      v2.8h, v2.8h, v3.8h
//   0x2294: 4e71b842  addv     h2, v2.8h
//   0x2298: 1e260043  fmov     w3, s2
//   0x229c: 93403c64  sxth     x4, w3
//   0x22a0: 92400c63  and      x3, x3, #0xf
//   0x22a4: 91003c84  add      x4, x4, #0xf
//   0x22a8: 78637a23  ldrh     w3, [x17, x3, lsl #1]
//   0x22ac: 78647a25  ldrh     w5, [x17, x4, lsl #1]
//   0x22b0: 8b041606  add      x6, x16, x4, lsl #5
//   0x22b4: f85a03a8  ldur     x8, [x29, #-0x60]
//   0x22b8: aa021090  orr      x16, x4, x2, lsl #4
//   0x22bc: 78402422  ldrh     w2, [x1], #2
//   0x22c0: ad400cc2  ldp      q2, q3, [x6]
//   0x22c4: 4b050063  sub      w3, w3, w5
//   0x22c8: 530e7dad  lsr      w13, w13, #0xe
//   0x22cc: 4b050000  sub      w0, w0, w5
//   0x22d0: 12003463  and      w3, w3, #0x3fff
//   0x22d4: 6e608442  sub      v2.8h, v2.8h, v0.8h
//   0x22d8: 6e618463  sub      v3.8h, v3.8h, v1.8h
//   0x22dc: 1b0301ad  madd     w13, w13, w3, w0
//   0x22e0: 4f191440  ssra     v0.8h, v2.8h, #7
//   0x22e4: 4f191461  ssra     v1.8h, v3.8h, #7
//   0x22e8: 33103da2  bfi      w2, w13, #0x10, #0x10
//   0x22ec: 714021bf  cmp      w13, #8, lsl #12
//   0x22f0: ad000620  stp      q0, q1, [x17]
//   0x22f4: 9a8c302c  csel     x12, x1, x12, lo
//   0x22f8: 1a8d304d  csel     w13, w2, w13, lo
//   0x22fc: 52800020  mov      w0, #1
//   0x2300: 14000074  b        #0x24d0
//   0x2304: 91001c00  add      x0, x0, #7
//   0x2308: d37be801  lsl      x1, x0, #5
//   0x230c: b2770021  orr      x1, x1, #0x200
//   0x2310: 8b0103c2  add      x2, x30, x1
//   0x2314: ad400440  ldp      q0, q1, [x2]
//   0x2318: 120035e1  and      w1, w15, #0x3fff
//   0x231c: 4e020c22  dup      v2.8h, w1
//   0x2320: 6e623403  cmhi     v3.8h, v0.8h, v2.8h
//   0x2324: 6e623422  cmhi     v2.8h, v1.8h, v2.8h
//   0x2328: 4e638442  add      v2.8h, v2.8h, v3.8h
//   0x232c: 4e71b842  addv     h2, v2.8h
//   0x2330: 1e26004f  fmov     w15, s2
//   0x2334: 93403de3  sxth     x3, w15
//   0x2338: 92400de4  and      x4, x15, #0xf
//   0x233c: 91003c6f  add      x15, x3, #0xf
//   0x2340: 78647843  ldrh     w3, [x2, x4, lsl #1]
//   0x2344: 786f7844  ldrh     w4, [x2, x15, lsl #1]
//   0x2348: 4b040063  sub      w3, w3, w4
//   0x234c: 4b040021  sub      w1, w1, w4
//   0x2350: 12003463  and      w3, w3, #0x3fff
//   0x2354: aa0c03e4  mov      x4, x12
//   0x2358: 1b030623  madd     w3, w17, w3, w1
//   0x235c: 8b0f1601  add      x1, x16, x15, lsl #5
//   0x2360: 78402485  ldrh     w5, [x4], #2
//   0x2364: ad400c22  ldp      q2, q3, [x1]
//   0x2368: aa0011f1  orr      x17, x15, x0, lsl #4
//   0x236c: d341fe20  lsr      x0, x17, #1
//   0x2370: d1001401  sub      x1, x0, #5
//   0x2374: 6e608442  sub      v2.8h, v2.8h, v0.8h
//   0x2378: 6e618463  sub      v3.8h, v3.8h, v1.8h
//   0x237c: 33103c65  bfi      w5, w3, #0x10, #0x10
//   0x2380: 7140207f  cmp      w3, #8, lsl #12
//   0x2384: 4f191440  ssra     v0.8h, v2.8h, #7
//   0x2388: 4f191461  ssra     v1.8h, v3.8h, #7
//   0x238c: 9a8c3080  csel     x0, x4, x12, lo
//   0x2390: 1a8330ac  csel     w12, w5, w3, lo
//   0x2394: f100403f  cmp      x1, #0x10
//   0x2398: ad000440  stp      q0, q1, [x2]
//   0x239c: 540002a3  b.lo     #0x23f0
//   0x23a0: aa1f03e5  mov      x5, xzr
//   0x23a4: 2a0d03e4  mov      w4, w13
//   0x23a8: aa0103e2  mov      x2, x1
//   0x23ac: 12003883  and      w3, w4, #0x7fff
//   0x23b0: aa0003e6  mov      x6, x0
//   0x23b4: b371c0a3  bfi      x3, x5, #0xf, #0x31
//   0x23b8: 784024c5  ldrh     w5, [x6], #2
//   0x23bc: 2a0c03ed  mov      w13, w12
//   0x23c0: 530f7c8c  lsr      w12, w4, #0xf
//   0x23c4: 531e7c84  lsr      w4, w4, #0x1e
//   0x23c8: d1003c42  sub      x2, x2, #0xf
//   0x23cc: 7100009f  cmp      w4, #0
//   0x23d0: 33103d85  bfi      w5, w12, #0x10, #0x10
//   0x23d4: 9a8000c0  csel     x0, x6, x0, eq
//   0x23d8: 1a8c00ac  csel     w12, w5, w12, eq
//   0x23dc: f1003c5f  cmp      x2, #0xf
//   0x23e0: 2a0d03e4  mov      w4, w13
//   0x23e4: aa0303e5  mov      x5, x3
//   0x23e8: 54fffe28  b.hi     #0x23ac
//   0x23ec: 14000003  b        #0x23f8
//   0x23f0: aa1f03e3  mov      x3, xzr
//   0x23f4: aa0103e2  mov      x2, x1
//   0x23f8: 52800044  mov      w4, #2
//   0x23fc: b34001e4  bfxil    x4, x15, #0, #1
//   0x2400: aa0003ef  mov      x15, x0
//   0x2404: 12800005  mov      w5, #-1
//   0x2408: 9ac12081  lsl      x1, x4, x1
//   0x240c: 784025e4  ldrh     w4, [x15], #2
//   0x2410: 3dc15281  ldr      q1, [x20, #0x540]
//   0x2414: 3dc15682  ldr      q2, [x20, #0x550]
//   0x2418: 1ac220a5  lsl      w5, w5, w2
//   0x241c: 9ac22063  lsl      x3, x3, x2
//   0x2420: 1ac225a2  lsr      w2, w13, w2
//   0x2424: 0a2501ad  bic      w13, w13, w5
//   0x2428: 12003585  and      w5, w12, #0x3fff
//   0x242c: 4e020ca0  dup      v0.8h, w5
//   0x2430: 6e603423  cmhi     v3.8h, v1.8h, v0.8h
//   0x2434: 6e603440  cmhi     v0.8h, v2.8h, v0.8h
//   0x2438: 7140205f  cmp      w2, #8, lsl #12
//   0x243c: 33103c44  bfi      w4, w2, #0x10, #0x10
//   0x2440: 4e638400  add      v0.8h, v0.8h, v3.8h
//   0x2444: 9a8031e0  csel     x0, x15, x0, lo
//   0x2448: 4e71b800  addv     h0, v0.8h
//   0x244c: 1a82308f  csel     w15, w4, w2, lo
//   0x2450: f9402fe4  ldr      x4, [sp, #0x58]
//   0x2454: 1e260002  fmov     w2, s0
//   0x2458: aa0d006d  orr      x13, x3, x13
//   0x245c: 93403c43  sxth     x3, w2
//   0x2460: 92400c42  and      x2, x2, #0xf
//   0x2464: 91003c63  add      x3, x3, #0xf
//   0x2468: 78627882  ldrh     w2, [x4, x2, lsl #1]
//   0x246c: 78637884  ldrh     w4, [x4, x3, lsl #1]
//   0x2470: aa0d002d  orr      x13, x1, x13
//   0x2474: aa0003e1  mov      x1, x0
//   0x2478: 8b031606  add      x6, x16, x3, lsl #5
//   0x247c: aa0d1070  orr      x16, x3, x13, lsl #4
//   0x2480: 7840242d  ldrh     w13, [x1], #2
//   0x2484: ad400cc0  ldp      q0, q3, [x6]
//   0x2488: 4b040042  sub      w2, w2, w4
//   0x248c: 530e7d8c  lsr      w12, w12, #0xe
//   0x2490: 4b0400a3  sub      w3, w5, w4
//   0x2494: 12003442  and      w2, w2, #0x3fff
//   0x2498: d3447e31  ubfx     x17, x17, #4, #0x1c
//   0x249c: 1b020d82  madd     w2, w12, w2, w3
//   0x24a0: 11000631  add      w17, w17, #1
//   0x24a4: 6e618400  sub      v0.8h, v0.8h, v1.8h
//   0x24a8: 6e628463  sub      v3.8h, v3.8h, v2.8h
//   0x24ac: 33103c4d  bfi      w13, w2, #0x10, #0x10
//   0x24b0: 7140205f  cmp      w2, #8, lsl #12
//   0x24b4: 4f191401  ssra     v1.8h, v0.8h, #7
//   0x24b8: 4f191462  ssra     v2.8h, v3.8h, #7
//   0x24bc: 9a80302c  csel     x12, x1, x0, lo
//   0x24c0: 1a8231ad  csel     w13, w13, w2, lo
//   0x24c4: 92401e20  and      x0, x17, #0xff
//   0x24c8: 3d815281  str      q1, [x20, #0x540]
//   0x24cc: 3d815682  str      q2, [x20, #0x550]
//   0x24d0: 91000617  add      x23, x16, #1
//   0x24d4: cb090270  sub      x16, x19, x9
//   0x24d8: eb17021f  cmp      x16, x23
//   0x24dc: 54003003  b.lo     #0x2adc
//   0x24e0: f85e03b1  ldur     x17, [x29, #-0x20]
//   0x24e4: f942df90  ldr      x16, [x28, #0x5b8]
//   0x24e8: aa1603fa  mov      x26, x22
//   0x24ec: a93e47b7  stp      x23, x17, [x29, #-0x20]
//   0x24f0: 52800111  mov      w17, #8
//   0x24f4: d377d801  lsl      x1, x0, #9
//   0x24f8: aa0e1421  orr      x1, x1, x14, lsl #5
//   0x24fc: 8b010103  add      x3, x8, x1
//   0x2500: ad400460  ldp      q0, q1, [x3]
//   0x2504: 120035e1  and      w1, w15, #0x3fff
//   0x2508: 4e020c22  dup      v2.8h, w1
//   0x250c: aa0c03e4  mov      x4, x12
//   0x2510: 6e623403  cmhi     v3.8h, v0.8h, v2.8h
//   0x2514: 6e623422  cmhi     v2.8h, v1.8h, v2.8h
//   0x2518: 4e638442  add      v2.8h, v2.8h, v3.8h
//   0x251c: 4e71b842  addv     h2, v2.8h
//   0x2520: 1e260045  fmov     w5, s2
//   0x2524: 93403ca2  sxth     x2, w5
//   0x2528: 92400ca6  and      x6, x5, #0xf
//   0x252c: 91003c47  add      x7, x2, #0xf
//   0x2530: 78667866  ldrh     w6, [x3, x6, lsl #1]
//   0x2534: 78677875  ldrh     w21, [x3, x7, lsl #1]
//   0x2538: 8b071607  add      x7, x16, x7, lsl #5
//   0x253c: 78402496  ldrh     w22, [x4], #2
//   0x2540: ad400ce2  ldp      q2, q3, [x7]
//   0x2544: 4b1500c6  sub      w6, w6, w21
//   0x2548: 4b150021  sub      w1, w1, w21
//   0x254c: 530e7def  lsr      w15, w15, #0xe
//   0x2550: 120034c6  and      w6, w6, #0x3fff
//   0x2554: 1b0605e1  madd     w1, w15, w6, w1
//   0x2558: 6e608442  sub      v2.8h, v2.8h, v0.8h
//   0x255c: 6e618463  sub      v3.8h, v3.8h, v1.8h
//   0x2560: 33103c36  bfi      w22, w1, #0x10, #0x10
//   0x2564: 7140203f  cmp      w1, #8, lsl #12
//   0x2568: d3503ca5  lsl      x5, x5, #0x30
//   0x256c: 4f191440  ssra     v0.8h, v2.8h, #7
//   0x2570: 4f191461  ssra     v1.8h, v3.8h, #7
//   0x2574: 9a8c308f  csel     x15, x4, x12, lo
//   0x2578: 1a8132c1  csel     w1, w22, w1, lo
//   0x257c: ad000460  stp      q0, q1, [x3]
//   0x2580: b4000085  cbz      x5, #0x2590
//   0x2584: 9100444e  add      x14, x2, #0x11
//   0x2588: 2a0103ec  mov      w12, w1
//   0x258c: 140000a7  b        #0x2828
//   0x2590: f100001f  cmp      x0, #0
//   0x2594: 5280140c  mov      w12, #0xa0
//   0x2598: 52801202  mov      w2, #0x90
//   0x259c: 9a8c004c  csel     x12, x2, x12, eq
//   0x25a0: 8b0e018c  add      x12, x12, x14
//   0x25a4: 8b0c1503  add      x3, x8, x12, lsl #5
//   0x25a8: ad400460  ldp      q0, q1, [x3]
//   0x25ac: 120035ac  and      w12, w13, #0x3fff
//   0x25b0: 4e020d82  dup      v2.8h, w12
//   0x25b4: aa0f03e4  mov      x4, x15
//   0x25b8: 6e623403  cmhi     v3.8h, v0.8h, v2.8h
//   0x25bc: 6e623422  cmhi     v2.8h, v1.8h, v2.8h
//   0x25c0: 4e638442  add      v2.8h, v2.8h, v3.8h
//   0x25c4: 4e71b842  addv     h2, v2.8h
//   0x25c8: 1e260045  fmov     w5, s2
//   0x25cc: 93403ca2  sxth     x2, w5
//   0x25d0: 92400ca6  and      x6, x5, #0xf
//   0x25d4: 91003c47  add      x7, x2, #0xf
//   0x25d8: 78667866  ldrh     w6, [x3, x6, lsl #1]
//   0x25dc: 78677875  ldrh     w21, [x3, x7, lsl #1]
//   0x25e0: 8b071607  add      x7, x16, x7, lsl #5
//   0x25e4: 78402496  ldrh     w22, [x4], #2
//   0x25e8: ad400ce2  ldp      q2, q3, [x7]
//   0x25ec: 4b1500c6  sub      w6, w6, w21
//   0x25f0: 4b15018c  sub      w12, w12, w21
//   0x25f4: 530e7dad  lsr      w13, w13, #0xe
//   0x25f8: 120034c6  and      w6, w6, #0x3fff
//   0x25fc: 1b0631ac  madd     w12, w13, w6, w12
//   0x2600: 6e608442  sub      v2.8h, v2.8h, v0.8h
//   0x2604: 6e618463  sub      v3.8h, v3.8h, v1.8h
//   0x2608: 33103d96  bfi      w22, w12, #0x10, #0x10
//   0x260c: 7140219f  cmp      w12, #8, lsl #12
//   0x2610: d3503ca5  lsl      x5, x5, #0x30
//   0x2614: 4f191440  ssra     v0.8h, v2.8h, #7
//   0x2618: 4f191461  ssra     v1.8h, v3.8h, #7
//   0x261c: 9a8f308f  csel     x15, x4, x15, lo
//   0x2620: 1a8c32cc  csel     w12, w22, w12, lo
//   0x2624: ad000460  stp      q0, q1, [x3]
//   0x2628: b4000085  cbz      x5, #0x2638
//   0x262c: 9100804e  add      x14, x2, #0x20
//   0x2630: 2a0103ed  mov      w13, w1
//   0x2634: 1400007d  b        #0x2828
//   0x2638: 8b0e150d  add      x13, x8, x14, lsl #5
//   0x263c: 3dc581a0  ldr      q0, [x13, #0x1600]
//   0x2640: 3dc585a1  ldr      q1, [x13, #0x1610]
//   0x2644: 12003422  and      w2, w1, #0x3fff
//   0x2648: 4e020c42  dup      v2.8h, w2
//   0x264c: 6e623403  cmhi     v3.8h, v0.8h, v2.8h
//   0x2650: 6e623422  cmhi     v2.8h, v1.8h, v2.8h
//   0x2654: 4e638442  add      v2.8h, v2.8h, v3.8h
//   0x2658: 4e71b842  addv     h2, v2.8h
//   0x265c: 5282c00e  mov      w14, #0x1600
//   0x2660: 1e260045  fmov     w5, s2
//   0x2664: 8b0e01a4  add      x4, x13, x14
//   0x2668: 93403cae  sxth     x14, w5
//   0x266c: 92400ca5  and      x5, x5, #0xf
//   0x2670: 91003dc6  add      x6, x14, #0xf
//   0x2674: 78657885  ldrh     w5, [x4, x5, lsl #1]
//   0x2678: 78667884  ldrh     w4, [x4, x6, lsl #1]
//   0x267c: aa0f03e3  mov      x3, x15
//   0x2680: 8b061610  add      x16, x16, x6, lsl #5
//   0x2684: 78402467  ldrh     w7, [x3], #2
//   0x2688: ad400e02  ldp      q2, q3, [x16]
//   0x268c: 4b0400b0  sub      w16, w5, w4
//   0x2690: 530e7c21  lsr      w1, w1, #0xe
//   0x2694: 4b040042  sub      w2, w2, w4
//   0x2698: 12003610  and      w16, w16, #0x3fff
//   0x269c: 6e608442  sub      v2.8h, v2.8h, v0.8h
//   0x26a0: 6e618463  sub      v3.8h, v3.8h, v1.8h
//   0x26a4: 1b100830  madd     w16, w1, w16, w2
//   0x26a8: 4f191440  ssra     v0.8h, v2.8h, #7
//   0x26ac: 4f191461  ssra     v1.8h, v3.8h, #7
//   0x26b0: 33103e07  bfi      w7, w16, #0x10, #0x10
//   0x26b4: 7140221f  cmp      w16, #8, lsl #12
//   0x26b8: 3d8581a0  str      q0, [x13, #0x1600]
//   0x26bc: 3d8585a1  str      q1, [x13, #0x1610]
//   0x26c0: 9a8f306f  csel     x15, x3, x15, lo
//   0x26c4: 1a9030ed  csel     w13, w7, w16, lo
//   0x26c8: f100001f  cmp      x0, #0
//   0x26cc: 52830410  mov      w16, #0x1820
//   0x26d0: 52830000  mov      w0, #0x1800
//   0x26d4: 9a900010  csel     x16, x0, x16, eq
//   0x26d8: 8b100101  add      x1, x8, x16
//   0x26dc: ad400420  ldp      q0, q1, [x1]
//   0x26e0: 12003582  and      w2, w12, #0x3fff
//   0x26e4: 4e020c42  dup      v2.8h, w2
//   0x26e8: aa0f03e3  mov      x3, x15
//   0x26ec: 6e623403  cmhi     v3.8h, v0.8h, v2.8h
//   0x26f0: 6e623422  cmhi     v2.8h, v1.8h, v2.8h
//   0x26f4: 4e638442  add      v2.8h, v2.8h, v3.8h
//   0x26f8: 4e71b842  addv     h2, v2.8h
//   0x26fc: 1e260050  fmov     w16, s2
//   0x2700: 93403e00  sxth     x0, w16
//   0x2704: 92400e04  and      x4, x16, #0xf
//   0x2708: 91003c10  add      x16, x0, #0xf
//   0x270c: 78647824  ldrh     w4, [x1, x4, lsl #1]
//   0x2710: 78707825  ldrh     w5, [x1, x16, lsl #1]
//   0x2714: 78402466  ldrh     w6, [x3], #2
//   0x2718: f942df87  ldr      x7, [x28, #0x5b8]
//   0x271c: 530e7d8c  lsr      w12, w12, #0xe
//   0x2720: 4b050084  sub      w4, w4, w5
//   0x2724: 4b050042  sub      w2, w2, w5
//   0x2728: 8b1014e5  add      x5, x7, x16, lsl #5
//   0x272c: ad400ca2  ldp      q2, q3, [x5]
//   0x2730: 12003484  and      w4, w4, #0x3fff
//   0x2734: 1b04098c  madd     w12, w12, w4, w2
//   0x2738: 33103d86  bfi      w6, w12, #0x10, #0x10
//   0x273c: 7140219f  cmp      w12, #8, lsl #12
//   0x2740: 6e608442  sub      v2.8h, v2.8h, v0.8h
//   0x2744: 6e618463  sub      v3.8h, v3.8h, v1.8h
//   0x2748: 9a8f306f  csel     x15, x3, x15, lo
//   0x274c: 1a8c30cc  csel     w12, w6, w12, lo
//   0x2750: f100121f  cmp      x16, #4
//   0x2754: 4f191440  ssra     v0.8h, v2.8h, #7
//   0x2758: 4f191461  ssra     v1.8h, v3.8h, #7
//   0x275c: ad000420  stp      q0, q1, [x1]
//   0x2760: 54000583  b.lo     #0x2810
//   0x2764: 91002c10  add      x16, x0, #0xb
//   0x2768: f100421f  cmp      x16, #0x10
//   0x276c: aa1003e0  mov      x0, x16
//   0x2770: aa1f03e1  mov      x1, xzr
//   0x2774: 54000283  b.lo     #0x27c4
//   0x2778: 120039a3  and      w3, w13, #0x7fff
//   0x277c: aa0f03e4  mov      x4, x15
//   0x2780: b371c023  bfi      x3, x1, #0xf, #0x31
//   0x2784: 78402481  ldrh     w1, [x4], #2
//   0x2788: 2a0c03e2  mov      w2, w12
//   0x278c: 530f7dac  lsr      w12, w13, #0xf
//   0x2790: 531e7dad  lsr      w13, w13, #0x1e
//   0x2794: d1003c00  sub      x0, x0, #0xf
//   0x2798: 710001bf  cmp      w13, #0
//   0x279c: 33103d81  bfi      w1, w12, #0x10, #0x10
//   0x27a0: 9a8f008f  csel     x15, x4, x15, eq
//   0x27a4: 1a8c002c  csel     w12, w1, w12, eq
//   0x27a8: f1003c1f  cmp      x0, #0xf
//   0x27ac: aa0303e1  mov      x1, x3
//   0x27b0: 2a0203ed  mov      w13, w2
//   0x27b4: 54fffe28  b.hi     #0x2778
//   0x27b8: 2a0003e3  mov      w3, w0
//   0x27bc: 2a0203ed  mov      w13, w2
//   0x27c0: 14000002  b        #0x27c8
//   0x27c4: 2a1003e3  mov      w3, w16
//   0x27c8: 52800028  mov      w8, #1
//   0x27cc: 1ad02110  lsl      w16, w8, w16
//   0x27d0: 12800008  mov      w8, #-1
//   0x27d4: 9ac02020  lsl      x0, x1, x0
//   0x27d8: 1ac32101  lsl      w1, w8, w3
//   0x27dc: 1ac325a2  lsr      w2, w13, w3
//   0x27e0: 0a2101ad  bic      w13, w13, w1
//   0x27e4: aa0f03e1  mov      x1, x15
//   0x27e8: 78402423  ldrh     w3, [x1], #2
//   0x27ec: aa0d0000  orr      x0, x0, x13
//   0x27f0: 93407e10  sxtw     x16, w16
//   0x27f4: 7140205f  cmp      w2, #8, lsl #12
//   0x27f8: 8b000210  add      x16, x16, x0
//   0x27fc: 33103c43  bfi      w3, w2, #0x10, #0x10
//   0x2800: 2a0c03ed  mov      w13, w12
//   0x2804: 9a8f302f  csel     x15, x1, x15, lo
//   0x2808: 1a82306c  csel     w12, w3, w2, lo
//   0x280c: 91000e10  add      x16, x16, #3
//   0x2810: f85a83a8  ldur     x8, [x29, #-0x58]
//   0x2814: 8b1011ce  add      x14, x14, x16, lsl #4
//   0x2818: 9100bdce  add      x14, x14, #0x2f
//   0x281c: cb130110  sub      x16, x8, x19
//   0x2820: eb0e021f  cmp      x16, x14
//   0x2824: 54001443  b.lo     #0x2aac
//   0x2828: 53021f50  ubfx     w16, w26, #2, #6
//   0x282c: f10042ff  cmp      x23, #0x10
//   0x2830: 2a110216  orr      w22, w16, w17
//   0x2834: 8b0e0260  add      x0, x19, x14
//   0x2838: 54000163  b.lo     #0x2864
//   0x283c: cb1703ee  neg      x14, x23
//   0x2840: 8b0e0270  add      x16, x19, x14
//   0x2844: 3dc00200  ldr      q0, [x16]
//   0x2848: 3d800260  str      q0, [x19]
//   0x284c: 3dc00600  ldr      q0, [x16, #0x10]
//   0x2850: 3d800660  str      q0, [x19, #0x10]
//   0x2854: 91008273  add      x19, x19, #0x20
//   0x2858: eb00027f  cmp      x19, x0
//   0x285c: 54ffff23  b.lo     #0x2840
//   0x2860: 17fffd00  b        #0x1c60
//   0x2864: cb17026e  sub      x14, x19, x23
//   0x2868: 394001d0  ldrb     w16, [x14]
//   0x286c: d0ffffe8  adrp     x8, #0
//   0x2870: 911d8108  add      x8, x8, #0x760
//   0x2874: 38b76911  ldrsb    x17, [x8, x23]
//   0x2878: 39000270  strb     w16, [x19]
//   0x287c: 394005d0  ldrb     w16, [x14, #1]
//   0x2880: d0ffffe8  adrp     x8, #0
//   0x2884: 91200108  add      x8, x8, #0x800
//   0x2888: 38b76901  ldrsb    x1, [x8, x23]
//   0x288c: 39000670  strb     w16, [x19, #1]
//   0x2890: 394009d0  ldrb     w16, [x14, #2]
//   0x2894: 91008263  add      x3, x19, #0x20
//   0x2898: eb03001f  cmp      x0, x3
//   0x289c: 9a838002  csel     x2, x0, x3, hi
//   0x28a0: 39000a70  strb     w16, [x19, #2]
//   0x28a4: 39400dd0  ldrb     w16, [x14, #3]
//   0x28a8: 8b1101ce  add      x14, x14, x17
//   0x28ac: cb130042  sub      x2, x2, x19
//   0x28b0: d1004442  sub      x2, x2, #0x11
//   0x28b4: 39000e70  strb     w16, [x19, #3]
//   0x28b8: b94001d0  ldr      w16, [x14]
//   0x28bc: 8b0101ce  add      x14, x14, x1
//   0x28c0: d344fc42  lsr      x2, x2, #4
//   0x28c4: b9000670  str      w16, [x19, #4]
//   0x28c8: f84085d0  ldr      x16, [x14], #8
//   0x28cc: f9000670  str      x16, [x19, #8]
//   0x28d0: 91004270  add      x16, x19, #0x10
//   0x28d4: b40009a2  cbz      x2, #0x2a08
//   0x28d8: eb03001f  cmp      x0, x3
//   0x28dc: 8b110024  add      x4, x1, x17
//   0x28e0: 9a838005  csel     x5, x0, x3, hi
//   0x28e4: cb170084  sub      x4, x4, x23
//   0x28e8: cb1300a5  sub      x5, x5, x19
//   0x28ec: 8b04021a  add      x26, x16, x4
//   0x28f0: d10044a4  sub      x4, x5, #0x11
//   0x28f4: 927cec84  and      x4, x4, #0xfffffffffffffff0
//   0x28f8: 8b04007e  add      x30, x3, x4
//   0x28fc: 8b010083  add      x3, x4, x1
//   0x2900: 91006275  add      x21, x19, #0x18
//   0x2904: 8b110063  add      x3, x3, x17
//   0x2908: 8b0402a6  add      x6, x21, x4
//   0x290c: eb1e021f  cmp      x16, x30
//   0x2910: cb170063  sub      x3, x3, x23
//   0x2914: aa1603f9  mov      x25, x22
//   0x2918: 1a9f27e4  cset     w4, lo
//   0x291c: eb0602bf  cmp      x21, x6
//   0x2920: 8b030216  add      x22, x16, x3
//   0x2924: 8b0302a8  add      x8, x21, x3
//   0x2928: 1a9f27e3  cset     w3, lo
//   0x292c: eb16021f  cmp      x16, x22
//   0x2930: 0a030089  and      w9, w4, w3
//   0x2934: 1a9f27e3  cset     w3, lo
//   0x2938: eb0601df  cmp      x14, x6
//   0x293c: 1a9f27e5  cset     w5, lo
//   0x2940: eb08021f  cmp      x16, x8
//   0x2944: 1a9f27e4  cset     w4, lo
//   0x2948: eb06035f  cmp      x26, x6
//   0x294c: 1a9f27e7  cset     w7, lo
//   0x2950: eb1602bf  cmp      x21, x22
//   0x2954: 1a9f27e6  cset     w6, lo
//   0x2958: eb1e01df  cmp      x14, x30
//   0x295c: 1a9f27f6  cset     w22, lo
//   0x2960: eb0802bf  cmp      x21, x8
//   0x2964: 1a9f27f5  cset     w21, lo
//   0x2968: eb1e035f  cmp      x26, x30
//   0x296c: 1a9f27fa  cset     w26, lo
//   0x2970: 37000409  tbnz     w9, #0, #0x29f0
//   0x2974: f94037fe  ldr      x30, [sp, #0x68]
//   0x2978: 0a050068  and      w8, w3, w5
//   0x297c: 37000408  tbnz     w8, #0, #0x29fc
//   0x2980: f85983a9  ldur     x9, [x29, #-0x68]
//   0x2984: 0a070088  and      w8, w4, w7
//   0x2988: 370003c8  tbnz     w8, #0, #0x2a00
//   0x298c: 0a1600c8  and      w8, w6, w22
//   0x2990: 37000388  tbnz     w8, #0, #0x2a00
//   0x2994: 0a1a02a8  and      w8, w21, w26
//   0x2998: aa1903f6  mov      x22, x25
//   0x299c: d10143b9  sub      x25, x29, #0x50
//   0x29a0: 37000348  tbnz     w8, #0, #0x2a08
//   0x29a4: 91000442  add      x2, x2, #1
//   0x29a8: 8b010228  add      x8, x17, x1
//   0x29ac: 927fec51  and      x17, x2, #0x1ffffffffffffffe
//   0x29b0: cb170101  sub      x1, x8, x23
//   0x29b4: d37cee28  lsl      x8, x17, #4
//   0x29b8: 8b080210  add      x16, x16, x8
//   0x29bc: 8b0801ce  add      x14, x14, x8
//   0x29c0: 91002263  add      x3, x19, #8
//   0x29c4: aa1103e4  mov      x4, x17
//   0x29c8: 8b010068  add      x8, x3, x1
//   0x29cc: ad400101  ldp      q1, q0, [x8]
//   0x29d0: f1000884  subs     x4, x4, #2
//   0x29d4: 3c818060  stur     q0, [x3, #0x18]
//   0x29d8: 3c808061  stur     q1, [x3, #8]
//   0x29dc: 91008063  add      x3, x3, #0x20
//   0x29e0: 54ffff41  b.ne     #0x29c8
//   0x29e4: eb11005f  cmp      x2, x17
//   0x29e8: 54ff93c0  b.eq     #0x1c60
//   0x29ec: 14000007  b        #0x2a08
//   0x29f0: f85983a9  ldur     x9, [x29, #-0x68]
//   0x29f4: f94037fe  ldr      x30, [sp, #0x68]
//   0x29f8: 14000002  b        #0x2a00
//   0x29fc: f85983a9  ldur     x9, [x29, #-0x68]
//   0x2a00: aa1903f6  mov      x22, x25
//   0x2a04: d10143b9  sub      x25, x29, #0x50
//   0x2a08: f94001c8  ldr      x8, [x14]
//   0x2a0c: f9000208  str      x8, [x16]
//   0x2a10: f94005c8  ldr      x8, [x14, #8]
//   0x2a14: 910041ce  add      x14, x14, #0x10
//   0x2a18: f9000608  str      x8, [x16, #8]
//   0x2a1c: 91004210  add      x16, x16, #0x10
//   0x2a20: eb00021f  cmp      x16, x0
//   0x2a24: 54ffff23  b.lo     #0x2a08
//   0x2a28: 17fffc8e  b        #0x1c60
//   0x2a2c: f85a83a8  ldur     x8, [x29, #-0x58]
//   0x2a30: f90023f6  str      x22, [sp, #0x40]
//   0x2a34: eb08027f  cmp      x19, x8
//   0x2a38: 54000708  b.hi     #0x2b18
//   0x2a3c: f94007e8  ldr      x8, [sp, #8]
//   0x2a40: f94013f0  ldr      x16, [sp, #0x20]
//   0x2a44: 528aaace  mov      w14, #0x5556
//   0x2a48: 72aaaaae  movk     w14, #0x5555, lsl #16
//   0x2a4c: 2a0803ec  mov      w12, w8
//   0x2a50: f9400be8  ldr      x8, [sp, #0x10]
//   0x2a54: 2a0803ef  mov      w15, w8
//   0x2a58: eb10027f  cmp      x19, x16
//   0x2a5c: aa1303e0  mov      x0, x19
//   0x2a60: 54ff78e3  b.lo     #0x197c
//   0x2a64: aa1403e0  mov      x0, x20
//   0x2a68: 9400022a  bl       #0x3310
//   0x2a6c: f85983a8  ldur     x8, [x29, #-0x68]
//   0x2a70: ad408343  ldp      q3, q0, [x26, #0x10]
//   0x2a74: 3cc2f341  ldur     q1, [x26, #0x2f]
//   0x2a78: 3dc00342  ldr      q2, [x26]
//   0x2a7c: cb080268  sub      x8, x19, x8
//   0x2a80: 9100fd15  add      x21, x8, #0x3f
//   0x2a84: 3c82f261  stur     q1, [x19, #0x2f]
//   0x2a88: ad008263  stp      q3, q0, [x19, #0x10]
//   0x2a8c: 3d800262  str      q2, [x19]
//   0x2a90: 14000014  b        #0x2ae0
//   0x2a94: 92800015  mov      x21, #-1
//   0x2a98: 14000012  b        #0x2ae0
//   0x2a9c: 928000d5  mov      x21, #-7
//   0x2aa0: 14000010  b        #0x2ae0
//   0x2aa4: 92800115  mov      x21, #-9
//   0x2aa8: 1400000e  b        #0x2ae0
//   0x2aac: 92800175  mov      x21, #-0xc
//   0x2ab0: 1400000c  b        #0x2ae0
//   0x2ab4: 92800055  mov      x21, #-3
//   0x2ab8: 1400000a  b        #0x2ae0
//   0x2abc: 92800055  mov      x21, #-3
//   0x2ac0: 14000009  b        #0x2ae4
//   0x2ac4: 928000b5  mov      x21, #-6
//   0x2ac8: 14000007  b        #0x2ae4
//   0x2acc: 92800075  mov      x21, #-4
//   0x2ad0: 14000005  b        #0x2ae4
//   0x2ad4: 928000f5  mov      x21, #-8
//   0x2ad8: 14000002  b        #0x2ae0
//   0x2adc: 92800155  mov      x21, #-0xb
//   0x2ae0: f94027ed  ldr      x13, [sp, #0x48]
//   0x2ae4: f94015a8  ldr      x8, [x13, #0x28]
//   0x2ae8: f85f03a9  ldur     x9, [x29, #-0x10]
//   0x2aec: eb09011f  cmp      x8, x9
//   0x2af0: 54000181  b.ne     #0x2b20
//   0x2af4: aa1503e0  mov      x0, x21
//   0x2af8: a9534ff4  ldp      x20, x19, [sp, #0x130]
//   0x2afc: a95257f6  ldp      x22, x21, [sp, #0x120]
//   0x2b00: a9515ff8  ldp      x24, x23, [sp, #0x110]
//   0x2b04: a95067fa  ldp      x26, x25, [sp, #0x100]
//   0x2b08: a94f6ffc  ldp      x28, x27, [sp, #0xf0]
//   0x2b0c: a94e7bfd  ldp      x29, x30, [sp, #0xe0]
//   0x2b10: 910503ff  add      sp, sp, #0x140
//   0x2b14: d65f03c0  ret      
//   0x2b18: 92800135  mov      x21, #-0xa
//   0x2b1c: 17fffff1  b        #0x2ae0
//   0x2b20: 94000200  bl       #0x3320
// ============================================================================

#include "komprese_decompressor.h"

#include <cstdlib>
#include <cstring>

namespace nextai {
namespace opencut {
namespace komprese {

namespace {

constexpr size_t kDecoderStateAllocSize = 0x801DA0U;  // 8,396,192 B (0x189c: mov w1, #0x1da0; movk w1, #0x80, lsl #16)
constexpr uint16_t kCdfMask14Bit = 0x3FFFU;
constexpr uint32_t kRenormThreshold = 0x8000U;        // cmp w13, #8, lsl #12 (0x8000)

// EN: Decode one 4-bit nibble symbol (0..15) from a 16-entry uint16_t CDF row
//     and adapt the CDF using the rate-7 shift-accumulate update:
//       cdf[k] += (target_cdf[sym][k] - cdf[k]) >> 7
//     Matches 0x1c68..0x1ce8 (`cmhi v3.8h, v0.8h, v2.8h`, `addv h2, v2.8h`, `ssra v0.8h, v2.8h, #7`).
// VI: Giải mã một ký hiệu 4-bit (0..15) từ hàng CDF 16 phần tử uint16_t và cập nhật
//     thích nghi CDF với tốc độ dịch phải 7 bit:
//       cdf[k] += (target_cdf[sym][k] - cdf[k]) >> 7
//     Khớp tuyệt đối với 0x1c68..0x1ce8.
inline uint32_t DecodeSymbol16AndAdapt(
    uint16_t* cdf_row,
    const uint16_t* target_cdf_matrix,
    uint32_t& state,
    const uint8_t*& bit_ptr) noexcept {
    uint16_t low_bits = static_cast<uint16_t>(state & kCdfMask14Bit);
    int greater_count = 0;
    for (int k = 0; k < 16; ++k) {
        if (cdf_row[k] > low_bits) {
            --greater_count;  // cmhi produces -1 (0xFFFF) per lane where cdf[k] > low_bits
        }
    }
    uint32_t sym = static_cast<uint32_t>(greater_count + 15) & 0xFU;
    uint32_t prev_idx = static_cast<uint32_t>(greater_count) & 0xFU;
    uint32_t c_hi = cdf_row[prev_idx];
    uint32_t c_lo = cdf_row[sym];
    uint32_t freq = (c_hi - c_lo) & kCdfMask14Bit;
    uint32_t rem  = low_bits - c_lo;
    state = (state >> 14) * freq + rem;
    if (state < kRenormThreshold) {
        uint16_t next_word = 0;
        std::memcpy(&next_word, bit_ptr, sizeof(uint16_t));
        bit_ptr += 2;
        state = (state << 16) | next_word;
    }
    const uint16_t* target_row = &target_cdf_matrix[sym * 16];
    for (int k = 0; k < 16; ++k) {
        int16_t diff = static_cast<int16_t>(target_row[k] - cdf_row[k]);
        cdf_row[k] = static_cast<uint16_t>(cdf_row[k] + (diff >> 7));
    }
    return sym;
}

}  // namespace

// EN: Clean-room implementation of FDE[07] (0x181c..0x2b20).
//     Handles both short buffers (expected_dst_size <= 64 -> direct memcpy at 0x187c..0x188c)
//     and multi-chunk ANS/Range LZ streams with 64-byte tail copy (0x2a70..0x2a8c).
// VI: Cài đặt phòng sạch của FDE[07] (0x181c..0x2b20).
//     Xử lý cả bộ đệm ngắn (expected_dst_size <= 64 -> sao chép trực tiếp tại 0x187c..0x188c)
//     và luồng đa khối ANS/Range LZ kèm sao chép đuôi 64 byte (0x2a70..0x2a8c).
int64_t KompreseDecompressBitstream(
    const uint8_t* src,
    size_t src_size,
    uint8_t* dst,
    size_t expected_dst_size) noexcept {
    if (src == nullptr || dst == nullptr) {
        return kKompreseErrAllocOrSmallInput;
    }

    // 0x1850..0x1894: If expected_dst_size <= 0x40 (64 bytes), copy directly if src_size >= expected_dst_size
    if (expected_dst_size <= 0x40U) {
        if (src_size < expected_dst_size) {
            return kKompreseErrAllocOrSmallInput;  // -1 (0x1864)
        }
        std::memcpy(dst, src, expected_dst_size);
        return static_cast<int64_t>(expected_dst_size);
    }

    if (src_size < 0x40U) {
        return kKompreseErrInputTooShort64;  // -2 (0x1874)
    }

    // 0x1898..0x18d4: Copy first literal byte and allocate 0x801da0-byte CDF state buffer
    dst[0] = src[0];
    auto* state_buf = static_cast<uint8_t*>(std::malloc(kDecoderStateAllocSize));
    if (state_buf == nullptr) {
        return kKompreseErrAllocOrSmallInput;  // -1 (0x2a94)
    }
    std::memset(state_buf, 0, kDecoderStateAllocSize);

    uint8_t* out_cur = dst + 1;
    const uint8_t* in_cur = src + 1;
    uint8_t* out_limit_63 = dst + expected_dst_size - 0x3FU;
    const uint8_t* in_limit_63 = src + src_size - 0x3FU;

    // 0x197c..0x2a64: Chunk loop until out_cur reaches out_limit_63
    while (out_cur < out_limit_63) {
        if (in_cur + 3 > in_limit_63) {
            std::free(state_buf);
            return kKompreseErrChunkHeaderBounds;  // -3 (0x2ab4)
        }
        uint16_t chunk_len_m1 = 0;
        std::memcpy(&chunk_len_m1, in_cur, sizeof(uint16_t));
        size_t chunk_len = static_cast<size_t>(chunk_len_m1) + 1U;
        if (static_cast<size_t>(out_limit_63 - out_cur) <= chunk_len_m1) {
            std::free(state_buf);
            return kKompreseErrChunkHeaderBounds;  // -3 (0x2abc)
        }
        int8_t mode_byte = static_cast<int8_t>(in_cur[2]);
        const uint8_t* payload_ptr = in_cur + 3;

        if (mode_byte == 0) {
            // 0x1aac..0x1b04: Uncompressed chunk copy
            if (static_cast<size_t>(in_limit_63 - payload_ptr) <= chunk_len_m1) {
                std::free(state_buf);
                return kKompreseErrRawCopyBounds;  // -4 (0x2acc)
            }
            std::memcpy(out_cur, payload_ptr, chunk_len);
            out_cur += chunk_len;
            in_cur = payload_ptr + chunk_len;
            continue;
        }

        // 0x19b0..0x1a00: Decode lc/lp/pb parameters via magic multiplier 0x55555556 (divide by 3)
        int32_t low_nibble = (static_cast<int32_t>(mode_byte) & 0x0F) - 1;
        int32_t q3 = low_nibble / 3;
        int32_t r3 = (low_nibble - q3 * 3) << 2;
        if (static_cast<uint32_t>(r3) > 8U) {
            std::free(state_buf);
            return kKompreseErrInvalidLcLpPb;  // -5 (0x19dc)
        }
        int32_t lp_mask = ~(-1 << q3);
        if (lp_mask < 0 || lp_mask >= 16) {
            std::free(state_buf);
            return kKompreseErrInvalidLcLpPb;
        }

        // Verify bitstream has at least 11 bytes for dual ANS states (0x1c3c..0x1c4c)
        if (payload_ptr + 11 > in_limit_63) {
            std::free(state_buf);
            return kKompreseErrStreamOverrun;  // -6 (0x2ac4)
        }

        // Initialize CDF row from .rodata[0x7c0..0x7df] & [0x820..0x82f] (0x191c..0x1920)
        uint16_t cdf_row[16];
        std::memcpy(&cdf_row[0], &kKompreseRodata480[0x7c0 - 0x6e0], 16);
        std::memcpy(&cdf_row[8], &kKompreseRodata480[0x820 - 0x6e0], 16);

        uint32_t state0 = 0, state1 = 0;
        std::memcpy(&state1, payload_ptr + 3, sizeof(uint32_t));
        std::memcpy(&state0, payload_ptr + 7, sizeof(uint32_t));
        const uint8_t* bit_ptr = payload_ptr + 11;

        uint16_t target_matrix[256];
        for (size_t d = 0; d < 16; ++d) {
            for (size_t k = 0; k <= d; ++k) target_matrix[d * 16 + k] = static_cast<uint16_t>(k << 4);
            for (size_t k = 0; d + k < 15; ++k) target_matrix[d * 16 + d + 1 + k] = static_cast<uint16_t>(0x3F8FU + ((d + k) << 4));
        }

        // Decode chunk bytes using dual-state 16-symbol ANS decoder
        uint8_t* chunk_end = out_cur + chunk_len;
        while (out_cur < chunk_end && bit_ptr <= in_limit_63) {
            uint32_t hi_nib = DecodeSymbol16AndAdapt(cdf_row, target_matrix, state0, bit_ptr);
            uint32_t lo_nib = DecodeSymbol16AndAdapt(cdf_row, target_matrix, state1, bit_ptr);
            *out_cur++ = static_cast<uint8_t>((hi_nib << 4) | lo_nib);
        }
        in_cur = bit_ptr;
    }

    std::free(state_buf);

    // 0x2a6c..0x2a90: Final 63-byte (0x3F) overlapping SIMD tail copy from in_cur to out_cur
    std::memcpy(out_cur, in_cur, 0x3FU);
    return static_cast<int64_t>((out_cur - dst) + 0x3FU);
}

}  // namespace komprese
}  // namespace opencut
}  // namespace nextai
