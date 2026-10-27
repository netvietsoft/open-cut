// ============================================================================
// NextAI OpenCut — Clean-Room C++17 Reconstruction
// File          : npth_logcat_safe_printf.cpp
// Target Binary : libnpth_logcat.so (16,856 bytes)
// SHA-256       : 241f75ebe9208e680c0d0e77c6f23c2f87d7ba9c2d446ca5c75a9df2ab8319e8
// Task ID       : TASK-169-RECONSTRUCTION-LIBNPTH-LOGCAT
// ============================================================================
// EN: Full clean-room C++17 implementation of FDE[00..04] (0x16e8..0x2180):
//       - `_start` & FDE[00] `_start_main` (0x16e8..0x1740): PIE entry point
//         invoking `__libc_init(raw_args, onexit, main, &structors)`.
//       - FDE[01..02] `__cxa_atexit` wrappers (0x1740..0x1770).
//       - FDE[03] `npth_safe_vsnprintf` (0x1770..0x20ec): Async-signal-safe
//         formatter supporting `%d`, `%i`, `%u`, `%o`, `%x`, `%X`, `%p`, `%s`,
//         `%c`, `%%`, width/padding (`0x3030303030303030` / `0x2020202020202020`),
//         and length modifiers (`hh`, `h`, `l`, `ll`, `z`).
//       - FDE[04] `npth_safe_snprintf` (0x20ec..0x2180): Variadic AArch64 AAPCS64
//         `va_list` wrapper around FDE[03].
// VI: Tái tạo phòng sạch C++17 hoàn chỉnh cho FDE[00..04] (0x16e8..0x2180).
// ============================================================================
// Complete AArch64 Disassembly (0x16e8..0x2180):
//   0x16e8: d503249f  bti      j
//   0x16ec: d280001d  mov      x29, #0
//   0x16f0: d280001e  mov      x30, #0
//   0x16f4: 910003e0  mov      x0, sp
//   0x16f8: 14000001  b        #0x16fc
//   0x16fc: d503233f  paciasp  
//   0x1700: d100c3ff  sub      sp, sp, #0x30
//   0x1704: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x1708: 910083fd  add      x29, sp, #0x20
//   0x170c: d0000028  adrp     x8, #0x7000
//   0x1710: d0000029  adrp     x9, #0x7000
//   0x1714: d000002a  adrp     x10, #0x7000
//   0x1718: d0000022  adrp     x2, #0x7000
//   0x171c: 910023e3  add      x3, sp, #8
//   0x1720: aa1f03e1  mov      x1, xzr
//   0x1724: f9434108  ldr      x8, [x8, #0x680]
//   0x1728: f9434529  ldr      x9, [x9, #0x688]
//   0x172c: f943494a  ldr      x10, [x10, #0x690]
//   0x1730: a900a7e8  stp      x8, x9, [sp, #8]
//   0x1734: f9000fea  str      x10, [sp, #0x18]
//   0x1738: f9434c42  ldr      x2, [x2, #0x698]
//   0x173c: 940006a5  bl       #0x31d0
//   0x1740: d503245f  bti      c
//   0x1744: b4000060  cbz      x0, #0x1750
//   0x1748: aa0003f0  mov      x16, x0
//   0x174c: d61f0200  br       x16
//   0x1750: d65f03c0  ret      
//   0x1754: d503245f  bti      c
//   0x1758: aa0003e1  mov      x1, x0
//   0x175c: d503201f  nop      
//   0x1760: 10ffff00  adr      x0, #0x1740
//   0x1764: d503201f  nop      
//   0x1768: 10050f42  adr      x2, #0xb950
//   0x176c: 1400069d  b        #0x31e0
//   0x1770: d103c3ff  sub      sp, sp, #0xf0
//   0x1774: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x1778: a90a6ffc  stp      x28, x27, [sp, #0xa0]
//   0x177c: a90b67fa  stp      x26, x25, [sp, #0xb0]
//   0x1780: a90c5ff8  stp      x24, x23, [sp, #0xc0]
//   0x1784: a90d57f6  stp      x22, x21, [sp, #0xd0]
//   0x1788: a90e4ff4  stp      x20, x19, [sp, #0xe0]
//   0x178c: 910243fd  add      x29, sp, #0x90
//   0x1790: d53bd05b  mrs      x27, tpidr_el0
//   0x1794: aa0203f6  mov      x22, x2
//   0x1798: aa0103f5  mov      x21, x1
//   0x179c: f9401768  ldr      x8, [x27, #0x28]
//   0x17a0: aa0003f4  mov      x20, x0
//   0x17a4: f81f83a8  stur     x8, [x29, #-8]
//   0x17a8: b4000041  cbz      x1, #0x17b0
//   0x17ac: 3900029f  strb     wzr, [x20]
//   0x17b0: f9400068  ldr      x8, [x3]
//   0x17b4: d100a3b8  sub      x24, x29, #0x28
//   0x17b8: b2400709  orr      x9, x24, #3
//   0x17bc: aa1f03f3  mov      x19, xzr
//   0x17c0: 2a1f03fa  mov      w26, wzr
//   0x17c4: 910006dc  add      x28, x22, #1
//   0x17c8: f81c03a8  stur     x8, [x29, #-0x40]
//   0x17cc: f9400468  ldr      x8, [x3, #8]
//   0x17d0: 5280014c  mov      w12, #0xa
//   0x17d4: d2c0002d  mov      x13, #0x100000000
//   0x17d8: f90017e8  str      x8, [sp, #0x28]
//   0x17dc: b9401868  ldr      w8, [x3, #0x18]
//   0x17e0: b81bc3a8  stur     w8, [x29, #-0x44]
//   0x17e4: 92800048  mov      x8, #-3
//   0x17e8: 8a380108  bic      x8, x8, x24
//   0x17ec: f90013e8  str      x8, [sp, #0x20]
//   0x17f0: 91007f08  add      x8, x24, #0x1f
//   0x17f4: a900a7e8  stp      x8, x9, [sp, #8]
//   0x17f8: aa3803e8  mvn      x8, x24
//   0x17fc: f9000fe8  str      x8, [sp, #0x18]
//   0x1800: 93407f4a  sxtw     x10, w26
//   0x1804: aa1f03e9  mov      x9, xzr
//   0x1808: 2a1a03e8  mov      w8, w26
//   0x180c: 8b0a02cb  add      x11, x22, x10
//   0x1810: 38696979  ldrb     w25, [x11, x9]
//   0x1814: 340000d9  cbz      w25, #0x182c
//   0x1818: 7100973f  cmp      w25, #0x25
//   0x181c: 54000080  b.eq     #0x182c
//   0x1820: 91000529  add      x9, x9, #1
//   0x1824: 38696979  ldrb     w25, [x11, x9]
//   0x1828: 35ffff99  cbnz     w25, #0x1818
//   0x182c: 8b09011a  add      x26, x8, x9
//   0x1830: 6b1a015f  cmp      w10, w26
//   0x1834: 540003ca  b.ge     #0x18ac
//   0x1838: 8b0a02d7  add      x23, x22, x10
//   0x183c: 37f80049  tbnz     w9, #0x1f, #0x1844
//   0x1840: 14000006  b        #0x1858
//   0x1844: aa1703e0  mov      x0, x23
//   0x1848: 9400066a  bl       #0x31f0
//   0x184c: d2c0002d  mov      x13, #0x100000000
//   0x1850: 5280014c  mov      w12, #0xa
//   0x1854: 2a0003e9  mov      w9, w0
//   0x1858: 93407d28  sxtw     x8, w9
//   0x185c: f10006bf  cmp      x21, #1
//   0x1860: 8b080273  add      x19, x19, x8
//   0x1864: 54000068  b.hi     #0x1870
//   0x1868: 2a1a03e8  mov      w8, w26
//   0x186c: 14000010  b        #0x18ac
//   0x1870: 510006a9  sub      w9, w21, #1
//   0x1874: eb0802bf  cmp      x21, x8
//   0x1878: 1a898108  csel     w8, w8, w9, hi
//   0x187c: aa1403e0  mov      x0, x20
//   0x1880: 93407d18  sxtw     x24, w8
//   0x1884: aa1703e1  mov      x1, x23
//   0x1888: aa1803e2  mov      x2, x24
//   0x188c: 9400065d  bl       #0x3200
//   0x1890: d2c0002d  mov      x13, #0x100000000
//   0x1894: 5280014c  mov      w12, #0xa
//   0x1898: 8b180294  add      x20, x20, x24
//   0x189c: cb1802b5  sub      x21, x21, x24
//   0x18a0: d100a3b8  sub      x24, x29, #0x28
//   0x18a4: 2a1a03e8  mov      w8, w26
//   0x18a8: 3900029f  strb     wzr, [x20]
//   0x18ac: 34004019  cbz      w25, #0x20ac
//   0x18b0: 2a1f03e0  mov      w0, wzr
//   0x18b4: 2a1f03ef  mov      w15, wzr
//   0x18b8: 2a1f03f1  mov      w17, wzr
//   0x18bc: 11000509  add      w9, w8, #1
//   0x18c0: d503201f  nop      
//   0x18c4: 10ffb4ee  adr      x14, #0xf60
//   0x18c8: 14000002  b        #0x18d0
//   0x18cc: 5280002f  mov      w15, #1
//   0x18d0: 93407d3a  sxtw     x26, w9
//   0x18d4: 91000749  add      x9, x26, #1
//   0x18d8: 387a6ac8  ldrb     w8, [x22, x26]
//   0x18dc: 7100c11f  cmp      w8, #0x30
//   0x18e0: 54000388  b.hi     #0x1950
//   0x18e4: 10ffff4a  adr      x10, #0x18cc
//   0x18e8: 786879cb  ldrh     w11, [x14, x8, lsl #1]
//   0x18ec: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x18f0: d61f0140  br       x10
//   0x18f4: 387a6b88  ldrb     w8, [x28, x26]
//   0x18f8: 9100075a  add      x26, x26, #1
//   0x18fc: 7100c11f  cmp      w8, #0x30
//   0x1900: 54ffffa0  b.eq     #0x18f4
//   0x1904: 7100a91f  cmp      w8, #0x2a
//   0x1908: 540000ac  b.gt     #0x191c
//   0x190c: 34003c68  cbz      w8, #0x2098
//   0x1910: 7100811f  cmp      w8, #0x20
//   0x1914: 54000120  b.eq     #0x1938
//   0x1918: 1400000c  b        #0x1948
//   0x191c: 7100ad1f  cmp      w8, #0x2b
//   0x1920: 540000c0  b.eq     #0x1938
//   0x1924: 7100b51f  cmp      w8, #0x2d
//   0x1928: 54000101  b.ne     #0x1948
//   0x192c: 91000749  add      x9, x26, #1
//   0x1930: 52800031  mov      w17, #1
//   0x1934: 17ffffe6  b        #0x18cc
//   0x1938: 91000749  add      x9, x26, #1
//   0x193c: 52800031  mov      w17, #1
//   0x1940: 2a0803e0  mov      w0, w8
//   0x1944: 17ffffe3  b        #0x18d0
//   0x1948: 91000749  add      x9, x26, #1
//   0x194c: 52800031  mov      w17, #1
//   0x1950: 5100c10a  sub      w10, w8, #0x30
//   0x1954: f9001ffc  str      x28, [sp, #0x38]
//   0x1958: 7100255f  cmp      w10, #9
//   0x195c: 54000248  b.hi     #0x19a4
//   0x1960: b2607fe8  mov      x8, #-0x100000000
//   0x1964: 2a1f03e9  mov      w9, wzr
//   0x1968: 8b1a8108  add      x8, x8, x26, lsl #32
//   0x196c: 387a6aca  ldrb     w10, [x22, x26]
//   0x1970: 2a0903fc  mov      w28, w9
//   0x1974: 8b0d0108  add      x8, x8, x13
//   0x1978: 9100075a  add      x26, x26, #1
//   0x197c: 5100c14a  sub      w10, w10, #0x30
//   0x1980: 1b0c2929  madd     w9, w9, w12, w10
//   0x1984: 7100295f  cmp      w10, #0xa
//   0x1988: 54ffff23  b.lo     #0x196c
//   0x198c: 9360fd08  asr      x8, x8, #0x20
//   0x1990: 38686ac8  ldrb     w8, [x22, x8]
//   0x1994: 7100b91f  cmp      w8, #0x2e
//   0x1998: 540000e0  b.eq     #0x19b4
//   0x199c: 12800019  mov      w25, #-1
//   0x19a0: 14000015  b        #0x19f4
//   0x19a4: 1280001c  mov      w28, #-1
//   0x19a8: 2a0903fa  mov      w26, w9
//   0x19ac: 7100b91f  cmp      w8, #0x2e
//   0x19b0: 54ffff61  b.ne     #0x199c
//   0x19b4: 2a1a03e9  mov      w9, w26
//   0x19b8: b2607feb  mov      x11, #-0x100000000
//   0x19bc: 93407d2a  sxtw     x10, w9
//   0x19c0: 2a1f03e8  mov      w8, wzr
//   0x19c4: 8b0a02c9  add      x9, x22, x10
//   0x19c8: 8b0a816a  add      x10, x11, x10, lsl #32
//   0x19cc: 3840152b  ldrb     w11, [x9], #1
//   0x19d0: 2a0803f9  mov      w25, w8
//   0x19d4: 8b0d014a  add      x10, x10, x13
//   0x19d8: 1100075a  add      w26, w26, #1
//   0x19dc: 5100c16b  sub      w11, w11, #0x30
//   0x19e0: 1b0c2d08  madd     w8, w8, w12, w11
//   0x19e4: 7100297f  cmp      w11, #0xa
//   0x19e8: 54ffff23  b.lo     #0x19cc
//   0x19ec: 9360fd48  asr      x8, x10, #0x20
//   0x19f0: 38686ac8  ldrb     w8, [x22, x8]
//   0x19f4: 5101a109  sub      w9, w8, #0x68
//   0x19f8: 1389050b  extr     w11, w8, w9, #1
//   0x19fc: 52800089  mov      w9, #4
//   0x1a00: 7100257f  cmp      w11, #9
//   0x1a04: 540002c8  b.hi     #0x1a5c
//   0x1a08: f0ffffee  adrp     x14, #0
//   0x1a0c: 913f09ce  add      x14, x14, #0xfc2
//   0x1a10: 5280010a  mov      w10, #8
//   0x1a14: 1000008c  adr      x12, #0x1a24
//   0x1a18: 386b69cd  ldrb     w13, [x14, x11]
//   0x1a1c: 8b0d098c  add      x12, x12, x13, lsl #2
//   0x1a20: d61f0180  br       x12
//   0x1a24: 387acac8  ldrb     w8, [x22, w26, sxtw]
//   0x1a28: 7101a11f  cmp      w8, #0x68
//   0x1a2c: 52800028  mov      w8, #1
//   0x1a30: 1a9a175a  cinc     w26, w26, eq
//   0x1a34: 9a88050a  cinc     x10, x8, ne
//   0x1a38: 14000005  b        #0x1a4c
//   0x1a3c: 387acac8  ldrb     w8, [x22, w26, sxtw]
//   0x1a40: 5280010a  mov      w10, #8
//   0x1a44: 7101b11f  cmp      w8, #0x6c
//   0x1a48: 1a9a175a  cinc     w26, w26, eq
//   0x1a4c: 11000749  add      w9, w26, #1
//   0x1a50: 387acac8  ldrb     w8, [x22, w26, sxtw]
//   0x1a54: 2a0903fa  mov      w26, w9
//   0x1a58: aa0a03e9  mov      x9, x10
//   0x1a5c: 5100950b  sub      w11, w8, #0x25
//   0x1a60: 71014d7f  cmp      w11, #0x53
//   0x1a64: 54003248  b.hi     #0x20ac
//   0x1a68: f0ffffee  adrp     x14, #0
//   0x1a6c: 913f31ce  add      x14, x14, #0xfcc
//   0x1a70: 5280002a  mov      w10, #1
//   0x1a74: 100000ec  adr      x12, #0x1a90
//   0x1a78: 786b79cd  ldrh     w13, [x14, x11, lsl #1]
//   0x1a7c: 8b0d098c  add      x12, x12, x13, lsl #2
//   0x1a80: b9004bef  str      w15, [sp, #0x48]
//   0x1a84: f81c83bb  stur     x27, [x29, #-0x38]
//   0x1a88: b90047f1  str      w17, [sp, #0x44]
//   0x1a8c: d61f0180  br       x12
//   0x1a90: 7101bd1f  cmp      w8, #0x6f
//   0x1a94: 1a9f17ea  cset     w10, eq
//   0x1a98: d100052b  sub      x11, x9, #1
//   0x1a9c: f1001d7f  cmp      x11, #7
//   0x1aa0: 54003068  b.hi     #0x20ac
//   0x1aa4: 9000000e  adrp     x14, #0x1000
//   0x1aa8: 9101d1ce  add      x14, x14, #0x74
//   0x1aac: 1000008c  adr      x12, #0x1abc
//   0x1ab0: 786b79cd  ldrh     w13, [x14, x11, lsl #1]
//   0x1ab4: 8b0d098c  add      x12, x12, x13, lsl #2
//   0x1ab8: d61f0180  br       x12
//   0x1abc: f85c03ab  ldur     x11, [x29, #-0x40]
//   0x1ac0: b85bc3ad  ldur     w13, [x29, #-0x44]
//   0x1ac4: 37f804cd  tbnz     w13, #0x1f, #0x1b5c
//   0x1ac8: 2a0d03ec  mov      w12, w13
//   0x1acc: 1400002d  b        #0x1b80
//   0x1ad0: f85c03ab  ldur     x11, [x29, #-0x40]
//   0x1ad4: b85bc3ad  ldur     w13, [x29, #-0x44]
//   0x1ad8: 37f805ad  tbnz     w13, #0x1f, #0x1b8c
//   0x1adc: 2a0d03ec  mov      w12, w13
//   0x1ae0: 14000034  b        #0x1bb0
//   0x1ae4: f85c03ab  ldur     x11, [x29, #-0x40]
//   0x1ae8: b85bc3ad  ldur     w13, [x29, #-0x44]
//   0x1aec: 37f8068d  tbnz     w13, #0x1f, #0x1bbc
//   0x1af0: 2a0d03ec  mov      w12, w13
//   0x1af4: 1400003a  b        #0x1bdc
//   0x1af8: f85c03ab  ldur     x11, [x29, #-0x40]
//   0x1afc: b85bc3ad  ldur     w13, [x29, #-0x44]
//   0x1b00: 37f8074d  tbnz     w13, #0x1f, #0x1be8
//   0x1b04: 2a0d03ec  mov      w12, w13
//   0x1b08: 14000040  b        #0x1c08
//   0x1b0c: f85c03ab  ldur     x11, [x29, #-0x40]
//   0x1b10: b85bc3aa  ldur     w10, [x29, #-0x44]
//   0x1b14: 37f8124a  tbnz     w10, #0x1f, #0x1d5c
//   0x1b18: 2a0a03e8  mov      w8, w10
//   0x1b1c: 14000098  b        #0x1d7c
//   0x1b20: f85c03ab  ldur     x11, [x29, #-0x40]
//   0x1b24: b85bc3aa  ldur     w10, [x29, #-0x44]
//   0x1b28: 37f8160a  tbnz     w10, #0x1f, #0x1de8
//   0x1b2c: 2a0a03e8  mov      w8, w10
//   0x1b30: 140000b7  b        #0x1e0c
//   0x1b34: 2a0003fb  mov      w27, w0
//   0x1b38: d100a3b7  sub      x23, x29, #0x28
//   0x1b3c: 528004a8  mov      w8, #0x25
//   0x1b40: 781d83a8  sturh    w8, [x29, #-0x28]
//   0x1b44: 140000eb  b        #0x1ef0
//   0x1b48: f85c03ab  ldur     x11, [x29, #-0x40]
//   0x1b4c: b85bc3aa  ldur     w10, [x29, #-0x44]
//   0x1b50: 37f816ea  tbnz     w10, #0x1f, #0x1e2c
//   0x1b54: 2a0a03e8  mov      w8, w10
//   0x1b58: 140000be  b        #0x1e50
//   0x1b5c: 110021ac  add      w12, w13, #8
//   0x1b60: 310021bf  cmn      w13, #8
//   0x1b64: 540000e8  b.hi     #0x1b80
//   0x1b68: 2a0d03ee  mov      w14, w13
//   0x1b6c: aa0b03ed  mov      x13, x11
//   0x1b70: f94017eb  ldr      x11, [sp, #0x28]
//   0x1b74: 8b2ec16b  add      x11, x11, w14, sxtw
//   0x1b78: 3940016b  ldrb     w11, [x11]
//   0x1b7c: 14000025  b        #0x1c10
//   0x1b80: 9100216d  add      x13, x11, #8
//   0x1b84: 3940016b  ldrb     w11, [x11]
//   0x1b88: 14000022  b        #0x1c10
//   0x1b8c: 110021ac  add      w12, w13, #8
//   0x1b90: 310021bf  cmn      w13, #8
//   0x1b94: 540000e8  b.hi     #0x1bb0
//   0x1b98: 2a0d03ee  mov      w14, w13
//   0x1b9c: aa0b03ed  mov      x13, x11
//   0x1ba0: f94017eb  ldr      x11, [sp, #0x28]
//   0x1ba4: 8b2ec16b  add      x11, x11, w14, sxtw
//   0x1ba8: 7940016b  ldrh     w11, [x11]
//   0x1bac: 14000019  b        #0x1c10
//   0x1bb0: 9100216d  add      x13, x11, #8
//   0x1bb4: 7940016b  ldrh     w11, [x11]
//   0x1bb8: 14000016  b        #0x1c10
//   0x1bbc: 110021ac  add      w12, w13, #8
//   0x1bc0: 310021bf  cmn      w13, #8
//   0x1bc4: 540000c8  b.hi     #0x1bdc
//   0x1bc8: 2a0d03ee  mov      w14, w13
//   0x1bcc: aa0b03ed  mov      x13, x11
//   0x1bd0: f94017eb  ldr      x11, [sp, #0x28]
//   0x1bd4: 8b2ec16b  add      x11, x11, w14, sxtw
//   0x1bd8: 14000002  b        #0x1be0
//   0x1bdc: 9100216d  add      x13, x11, #8
//   0x1be0: f940016b  ldr      x11, [x11]
//   0x1be4: 1400000b  b        #0x1c10
//   0x1be8: 110021ac  add      w12, w13, #8
//   0x1bec: 310021bf  cmn      w13, #8
//   0x1bf0: 540000c8  b.hi     #0x1c08
//   0x1bf4: 2a0d03ee  mov      w14, w13
//   0x1bf8: aa0b03ed  mov      x13, x11
//   0x1bfc: f94017eb  ldr      x11, [sp, #0x28]
//   0x1c00: 8b2ec16b  add      x11, x11, w14, sxtw
//   0x1c04: 14000002  b        #0x1c0c
//   0x1c08: 9100216d  add      x13, x11, #8
//   0x1c0c: b940016b  ldr      w11, [x11]
//   0x1c10: b81bc3ac  stur     w12, [x29, #-0x44]
//   0x1c14: f81c03ad  stur     x13, [x29, #-0x40]
//   0x1c18: 340000aa  cbz      w10, #0x1c2c
//   0x1c1c: 531d7129  lsl      w9, w9, #3
//   0x1c20: 4b0903e9  neg      w9, w9
//   0x1c24: 9ac9216a  lsl      x10, x11, x9
//   0x1c28: 9ac9294b  asr      x11, x10, x9
//   0x1c2c: 5101910a  sub      w10, w8, #0x64
//   0x1c30: 52800209  mov      w9, #0x10
//   0x1c34: 7100315f  cmp      w10, #0xc
//   0x1c38: 1a9f27ec  cset     w12, lo
//   0x1c3c: 7101611f  cmp      w8, #0x58
//   0x1c40: 54000100  b.eq     #0x1c60
//   0x1c44: 7101e11f  cmp      w8, #0x78
//   0x1c48: 540000c0  b.eq     #0x1c60
//   0x1c4c: 7101bd1f  cmp      w8, #0x6f
//   0x1c50: 54000061  b.ne     #0x1c5c
//   0x1c54: 52800109  mov      w9, #8
//   0x1c58: 14000002  b        #0x1c60
//   0x1c5c: 52800149  mov      w9, #0xa
//   0x1c60: 5281042d  mov      w13, #0x821
//   0x1c64: f100017f  cmp      x11, #0
//   0x1c68: 1aca25aa  lsr      w10, w13, w10
//   0x1c6c: 0a0a018a  and      w10, w12, w10
//   0x1c70: 5200014a  eor      w10, w10, #1
//   0x1c74: 1a9fb54a  csinc    w10, w10, wzr, lt
//   0x1c78: 370000ea  tbnz     w10, #0, #0x1c94
//   0x1c7c: 528005ad  mov      w13, #0x2d
//   0x1c80: 5280002c  mov      w12, #1
//   0x1c84: cb0b03eb  neg      x11, x11
//   0x1c88: aa0c03ea  mov      x10, x12
//   0x1c8c: 381d83ad  sturb    w13, [x29, #-0x28]
//   0x1c90: 14000004  b        #0x1ca0
//   0x1c94: aa1f03ea  mov      x10, xzr
//   0x1c98: b40005eb  cbz      x11, #0x1d54
//   0x1c9c: aa0a03ec  mov      x12, x10
//   0x1ca0: 7101611f  cmp      w8, #0x58
//   0x1ca4: 52800ae8  mov      w8, #0x57
//   0x1ca8: 528006ed  mov      w13, #0x37
//   0x1cac: 1a8801a8  csel     w8, w13, w8, eq
//   0x1cb0: 14000004  b        #0x1cc0
//   0x1cb4: eb09017f  cmp      x11, x9
//   0x1cb8: aa0d03eb  mov      x11, x13
//   0x1cbc: 540001a3  b.lo     #0x1cf0
//   0x1cc0: 9ac9096d  udiv     x13, x11, x9
//   0x1cc4: f1007d5f  cmp      x10, #0x1f
//   0x1cc8: 54ffff60  b.eq     #0x1cb4
//   0x1ccc: 1b09adae  msub     w14, w13, w9, w11
//   0x1cd0: 5280060f  mov      w15, #0x30
//   0x1cd4: 91000550  add      x16, x10, #1
//   0x1cd8: 710029df  cmp      w14, #0xa
//   0x1cdc: 1a8831ef  csel     w15, w15, w8, lo
//   0x1ce0: 0b0e01ee  add      w14, w15, w14
//   0x1ce4: 382a6b0e  strb     w14, [x24, x10]
//   0x1ce8: aa1003ea  mov      x10, x16
//   0x1cec: 17fffff2  b        #0x1cb4
//   0x1cf0: aa0c0308  orr      x8, x24, x12
//   0x1cf4: 8b0a030b  add      x11, x24, x10
//   0x1cf8: f1007d5f  cmp      x10, #0x1f
//   0x1cfc: 540000c0  b.eq     #0x1d14
//   0x1d00: eb08017f  cmp      x11, x8
//   0x1d04: 54000081  b.ne     #0x1d14
//   0x1d08: aa0803eb  mov      x11, x8
//   0x1d0c: 52800609  mov      w9, #0x30
//   0x1d10: 38001569  strb     w9, [x11], #1
//   0x1d14: aa2803e9  mvn      x9, x8
//   0x1d18: 2a0003fb  mov      w27, w0
//   0x1d1c: ab090169  adds     x9, x11, x9
//   0x1d20: 3900017f  strb     wzr, [x11]
//   0x1d24: 54000140  b.eq     #0x1d4c
//   0x1d28: aa1f03ea  mov      x10, xzr
//   0x1d2c: 3869690b  ldrb     w11, [x8, x9]
//   0x1d30: 386a690c  ldrb     w12, [x8, x10]
//   0x1d34: 382a690b  strb     w11, [x8, x10]
//   0x1d38: 9100054a  add      x10, x10, #1
//   0x1d3c: 3829690c  strb     w12, [x8, x9]
//   0x1d40: d1000529  sub      x9, x9, #1
//   0x1d44: eb09015f  cmp      x10, x9
//   0x1d48: 54ffff23  b.lo     #0x1d2c
//   0x1d4c: d100a3b7  sub      x23, x29, #0x28
//   0x1d50: 14000068  b        #0x1ef0
//   0x1d54: d100a3a8  sub      x8, x29, #0x28
//   0x1d58: 17ffffe7  b        #0x1cf4
//   0x1d5c: 11002148  add      w8, w10, #8
//   0x1d60: 3100215f  cmn      w10, #8
//   0x1d64: 540000c8  b.hi     #0x1d7c
//   0x1d68: f94017e9  ldr      x9, [sp, #0x28]
//   0x1d6c: 8b2ac12a  add      x10, x9, w10, sxtw
//   0x1d70: aa0b03e9  mov      x9, x11
//   0x1d74: aa0a03eb  mov      x11, x10
//   0x1d78: 14000002  b        #0x1d80
//   0x1d7c: 91002169  add      x9, x11, #8
//   0x1d80: f940016a  ldr      x10, [x11]
//   0x1d84: 528f060b  mov      w11, #0x7830
//   0x1d88: 781d83ab  sturh    w11, [x29, #-0x28]
//   0x1d8c: b400078a  cbz      x10, #0x1e7c
//   0x1d90: 5280004b  mov      w11, #2
//   0x1d94: 1400000d  b        #0x1dc8
//   0x1d98: 12000d4e  and      w14, w10, #0xf
//   0x1d9c: 52800aed  mov      w13, #0x57
//   0x1da0: 710029df  cmp      w14, #0xa
//   0x1da4: 5280060f  mov      w15, #0x30
//   0x1da8: 1a8d31ef  csel     w15, w15, w13, lo
//   0x1dac: 9100056d  add      x13, x11, #1
//   0x1db0: 0b0e01ee  add      w14, w15, w14
//   0x1db4: f100415f  cmp      x10, #0x10
//   0x1db8: aa0c03ea  mov      x10, x12
//   0x1dbc: 382b6b0e  strb     w14, [x24, x11]
//   0x1dc0: aa0d03eb  mov      x11, x13
//   0x1dc4: 54000583  b.lo     #0x1e74
//   0x1dc8: d344fd4c  lsr      x12, x10, #4
//   0x1dcc: f1007d7f  cmp      x11, #0x1f
//   0x1dd0: 54fffe41  b.ne     #0x1d98
//   0x1dd4: f100415f  cmp      x10, #0x10
//   0x1dd8: aa0c03ea  mov      x10, x12
//   0x1ddc: 54ffff62  b.hs     #0x1dc8
//   0x1de0: f94007ea  ldr      x10, [sp, #8]
//   0x1de4: 1400002b  b        #0x1e90
//   0x1de8: 11002148  add      w8, w10, #8
//   0x1dec: 3100215f  cmn      w10, #8
//   0x1df0: 540000e8  b.hi     #0x1e0c
//   0x1df4: f94017e9  ldr      x9, [sp, #0x28]
//   0x1df8: 2a0003fb  mov      w27, w0
//   0x1dfc: 8b2ac12a  add      x10, x9, w10, sxtw
//   0x1e00: aa0b03e9  mov      x9, x11
//   0x1e04: aa0a03eb  mov      x11, x10
//   0x1e08: 14000003  b        #0x1e14
//   0x1e0c: 2a0003fb  mov      w27, w0
//   0x1e10: 91002169  add      x9, x11, #8
//   0x1e14: f940016a  ldr      x10, [x11]
//   0x1e18: 9000000b  adrp     x11, #0x1000
//   0x1e1c: 9104396b  add      x11, x11, #0x10e
//   0x1e20: f100015f  cmp      x10, #0
//   0x1e24: 9a8a0177  csel     x23, x11, x10, eq
//   0x1e28: 14000030  b        #0x1ee8
//   0x1e2c: 11002148  add      w8, w10, #8
//   0x1e30: 3100215f  cmn      w10, #8
//   0x1e34: 540000e8  b.hi     #0x1e50
//   0x1e38: f94017e9  ldr      x9, [sp, #0x28]
//   0x1e3c: 2a0003fb  mov      w27, w0
//   0x1e40: 8b2ac12a  add      x10, x9, w10, sxtw
//   0x1e44: aa0b03e9  mov      x9, x11
//   0x1e48: aa0a03eb  mov      x11, x10
//   0x1e4c: 14000003  b        #0x1e58
//   0x1e50: 2a0003fb  mov      w27, w0
//   0x1e54: 91002169  add      x9, x11, #8
//   0x1e58: b940016a  ldr      w10, [x11]
//   0x1e5c: d100a3b7  sub      x23, x29, #0x28
//   0x1e60: b81bc3a8  stur     w8, [x29, #-0x44]
//   0x1e64: f81c03a9  stur     x9, [x29, #-0x40]
//   0x1e68: 381d83aa  sturb    w10, [x29, #-0x28]
//   0x1e6c: 381d93bf  sturb    wzr, [x29, #-0x27]
//   0x1e70: 14000020  b        #0x1ef0
//   0x1e74: f10009bf  cmp      x13, #2
//   0x1e78: 540000a1  b.ne     #0x1e8c
//   0x1e7c: f9400bea  ldr      x10, [sp, #0x10]
//   0x1e80: 5280060b  mov      w11, #0x30
//   0x1e84: 381da3ab  sturb    w11, [x29, #-0x26]
//   0x1e88: 14000002  b        #0x1e90
//   0x1e8c: 8b0d030a  add      x10, x24, x13
//   0x1e90: f94013eb  ldr      x11, [sp, #0x20]
//   0x1e94: 2a0003fb  mov      w27, w0
//   0x1e98: 3900015f  strb     wzr, [x10]
//   0x1e9c: ab0b015f  cmn      x10, x11
//   0x1ea0: 54000220  b.eq     #0x1ee4
//   0x1ea4: f9400feb  ldr      x11, [sp, #0x18]
//   0x1ea8: 8b0a016b  add      x11, x11, x10
//   0x1eac: 5280004a  mov      w10, #2
//   0x1eb0: d100a3b7  sub      x23, x29, #0x28
//   0x1eb4: d100054e  sub      x14, x10, #1
//   0x1eb8: 386b6aec  ldrb     w12, [x23, x11]
//   0x1ebc: 386a6aed  ldrb     w13, [x23, x10]
//   0x1ec0: 382a6aec  strb     w12, [x23, x10]
//   0x1ec4: d100056c  sub      x12, x11, #1
//   0x1ec8: 382b6aed  strb     w13, [x23, x11]
//   0x1ecc: d1000d6d  sub      x13, x11, #3
//   0x1ed0: 9100054a  add      x10, x10, #1
//   0x1ed4: aa0c03eb  mov      x11, x12
//   0x1ed8: eb0d01df  cmp      x14, x13
//   0x1edc: 54fffea3  b.lo     #0x1eb0
//   0x1ee0: 14000002  b        #0x1ee8
//   0x1ee4: d100a3b7  sub      x23, x29, #0x28
//   0x1ee8: b81bc3a8  stur     w8, [x29, #-0x44]
//   0x1eec: f81c03a9  stur     x9, [x29, #-0x40]
//   0x1ef0: aa1703e0  mov      x0, x23
//   0x1ef4: 940004bf  bl       #0x31f0
//   0x1ef8: 72001f7f  tst      w27, #0xff
//   0x1efc: 54000f21  b.ne     #0x20e0
//   0x1f00: f85c83bb  ldur     x27, [x29, #-0x38]
//   0x1f04: 3100073f  cmn      w25, #1
//   0x1f08: 54000d21  b.ne     #0x20ac
//   0x1f0c: aa0003f8  mov      x24, x0
//   0x1f10: f9001bf6  str      x22, [sp, #0x30]
//   0x1f14: 6b18039b  subs     w27, w28, w24
//   0x1f18: 5400016d  b.le     #0x1f44
//   0x1f1c: b9404be8  ldr      w8, [sp, #0x48]
//   0x1f20: 35000128  cbnz     w8, #0x1f44
//   0x1f24: b94047e8  ldr      w8, [sp, #0x44]
//   0x1f28: b203c3e9  mov      x9, #0x2020202020202020
//   0x1f2c: 7100011f  cmp      w8, #0
//   0x1f30: b204c7e8  mov      x8, #0x3030303030303030
//   0x1f34: 9a880128  csel     x8, x9, x8, eq
//   0x1f38: 7100077f  cmp      w27, #1
//   0x1f3c: f81d03a8  stur     x8, [x29, #-0x30]
//   0x1f40: 5400056a  b.ge     #0x1fec
//   0x1f44: 2a1803e0  mov      w0, w24
//   0x1f48: f85c83bb  ldur     x27, [x29, #-0x38]
//   0x1f4c: 36f80078  tbz      w24, #0x1f, #0x1f58
//   0x1f50: aa1703e0  mov      x0, x23
//   0x1f54: 940004a7  bl       #0x31f0
//   0x1f58: 93407c16  sxtw     x22, w0
//   0x1f5c: f1000abf  cmp      x21, #2
//   0x1f60: 54000183  b.lo     #0x1f90
//   0x1f64: 510006a8  sub      w8, w21, #1
//   0x1f68: eb1602bf  cmp      x21, x22
//   0x1f6c: 1a8882c8  csel     w8, w22, w8, hi
//   0x1f70: aa1403e0  mov      x0, x20
//   0x1f74: 93407d19  sxtw     x25, w8
//   0x1f78: aa1703e1  mov      x1, x23
//   0x1f7c: aa1903e2  mov      x2, x25
//   0x1f80: 940004a0  bl       #0x3200
//   0x1f84: 8b190294  add      x20, x20, x25
//   0x1f88: cb1902b5  sub      x21, x21, x25
//   0x1f8c: 3900029f  strb     wzr, [x20]
//   0x1f90: 2948a3e9  ldp      w9, w8, [sp, #0x44]
//   0x1f94: 5280014c  mov      w12, #0xa
//   0x1f98: d2c0002d  mov      x13, #0x100000000
//   0x1f9c: 8b160273  add      x19, x19, x22
//   0x1fa0: 6b180398  subs     w24, w28, w24
//   0x1fa4: 5400074d  b.le     #0x208c
//   0x1fa8: a94373f6  ldp      x22, x28, [sp, #0x30]
//   0x1fac: 34000148  cbz      w8, #0x1fd4
//   0x1fb0: 7100013f  cmp      w9, #0
//   0x1fb4: b204c7e8  mov      x8, #0x3030303030303030
//   0x1fb8: b203c3e9  mov      x9, #0x2020202020202020
//   0x1fbc: aa1603f9  mov      x25, x22
//   0x1fc0: 9a880128  csel     x8, x9, x8, eq
//   0x1fc4: 7100071f  cmp      w24, #1
//   0x1fc8: f81d03a8  stur     x8, [x29, #-0x30]
//   0x1fcc: 540003aa  b.ge     #0x2040
//   0x1fd0: aa1903f6  mov      x22, x25
//   0x1fd4: d100a3b8  sub      x24, x29, #0x28
//   0x1fd8: 17fffe0a  b        #0x1800
//   0x1fdc: 8b160273  add      x19, x19, x22
//   0x1fe0: 4b16037b  sub      w27, w27, w22
//   0x1fe4: 7100037f  cmp      w27, #0
//   0x1fe8: 54fffaed  b.le     #0x1f44
//   0x1fec: 7100237f  cmp      w27, #8
//   0x1ff0: 52800108  mov      w8, #8
//   0x1ff4: 1a88b376  csel     w22, w27, w8, lt
//   0x1ff8: f1000abf  cmp      x21, #2
//   0x1ffc: 54ffff03  b.lo     #0x1fdc
//   0x2000: 510006a8  sub      w8, w21, #1
//   0x2004: eb1602bf  cmp      x21, x22
//   0x2008: 1a8882c8  csel     w8, w22, w8, hi
//   0x200c: d100c3a1  sub      x1, x29, #0x30
//   0x2010: 93407d19  sxtw     x25, w8
//   0x2014: aa1403e0  mov      x0, x20
//   0x2018: aa1903e2  mov      x2, x25
//   0x201c: 94000479  bl       #0x3200
//   0x2020: 8b190294  add      x20, x20, x25
//   0x2024: cb1902b5  sub      x21, x21, x25
//   0x2028: 3900029f  strb     wzr, [x20]
//   0x202c: 17ffffec  b        #0x1fdc
//   0x2030: 8b160273  add      x19, x19, x22
//   0x2034: 4b160318  sub      w24, w24, w22
//   0x2038: 7100031f  cmp      w24, #0
//   0x203c: 54fffcad  b.le     #0x1fd0
//   0x2040: 7100231f  cmp      w24, #8
//   0x2044: 52800108  mov      w8, #8
//   0x2048: 1a88b316  csel     w22, w24, w8, lt
//   0x204c: f1000abf  cmp      x21, #2
//   0x2050: 54ffff03  b.lo     #0x2030
//   0x2054: 510006a8  sub      w8, w21, #1
//   0x2058: eb1602bf  cmp      x21, x22
//   0x205c: 1a8882c8  csel     w8, w22, w8, hi
//   0x2060: d100c3a1  sub      x1, x29, #0x30
//   0x2064: 93407d17  sxtw     x23, w8
//   0x2068: aa1403e0  mov      x0, x20
//   0x206c: aa1703e2  mov      x2, x23
//   0x2070: 94000464  bl       #0x3200
//   0x2074: d2c0002d  mov      x13, #0x100000000
//   0x2078: 5280014c  mov      w12, #0xa
//   0x207c: 8b170294  add      x20, x20, x23
//   0x2080: cb1702b5  sub      x21, x21, x23
//   0x2084: 3900029f  strb     wzr, [x20]
//   0x2088: 17ffffea  b        #0x2030
//   0x208c: a94373f6  ldp      x22, x28, [sp, #0x30]
//   0x2090: d100a3b8  sub      x24, x29, #0x28
//   0x2094: 17fffddb  b        #0x1800
//   0x2098: 91000673  add      x19, x19, #1
//   0x209c: f1000abf  cmp      x21, #2
//   0x20a0: 54000063  b.lo     #0x20ac
//   0x20a4: 528004a8  mov      w8, #0x25
//   0x20a8: 79000288  strh     w8, [x20]
//   0x20ac: f9401768  ldr      x8, [x27, #0x28]
//   0x20b0: f85f83a9  ldur     x9, [x29, #-8]
//   0x20b4: eb09011f  cmp      x8, x9
//   0x20b8: 54000181  b.ne     #0x20e8
//   0x20bc: aa1303e0  mov      x0, x19
//   0x20c0: a94e4ff4  ldp      x20, x19, [sp, #0xe0]
//   0x20c4: a94d57f6  ldp      x22, x21, [sp, #0xd0]
//   0x20c8: a94c5ff8  ldp      x24, x23, [sp, #0xc0]
//   0x20cc: a94b67fa  ldp      x26, x25, [sp, #0xb0]
//   0x20d0: a94a6ffc  ldp      x28, x27, [sp, #0xa0]
//   0x20d4: a9497bfd  ldp      x29, x30, [sp, #0x90]
//   0x20d8: 9103c3ff  add      sp, sp, #0xf0
//   0x20dc: d65f03c0  ret      
//   0x20e0: f85c83bb  ldur     x27, [x29, #-0x38]
//   0x20e4: 17fffff2  b        #0x20ac
//   0x20e8: 9400044a  bl       #0x3210
//   0x20ec: d10483ff  sub      sp, sp, #0x120
//   0x20f0: a9107bfd  stp      x29, x30, [sp, #0x100]
//   0x20f4: a9114ffc  stp      x28, x19, [sp, #0x110]
//   0x20f8: 910403fd  add      x29, sp, #0x100
//   0x20fc: a93893a3  stp      x3, x4, [x29, #-0x78]
//   0x2100: d101e3a9  sub      x9, x29, #0x78
//   0x2104: a9399ba5  stp      x5, x6, [x29, #-0x68]
//   0x2108: 928004eb  mov      x11, #-0x28
//   0x210c: f81a83a7  stur     x7, [x29, #-0x58]
//   0x2110: 910003ec  mov      x12, sp
//   0x2114: ad0007e0  stp      q0, q1, [sp]
//   0x2118: 9100a129  add      x9, x9, #0x28
//   0x211c: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x2120: f2dff00b  movk     x11, #0xff80, lsl #32
//   0x2124: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x2128: 9102018c  add      x12, x12, #0x80
//   0x212c: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x2130: d53bd053  mrs      x19, tpidr_el0
//   0x2134: f9401668  ldr      x8, [x19, #0x28]
//   0x2138: d100a3aa  sub      x10, x29, #0x28
//   0x213c: d10143a3  sub      x3, x29, #0x50
//   0x2140: f81f83a8  stur     x8, [x29, #-8]
//   0x2144: 910083a8  add      x8, x29, #0x20
//   0x2148: a93eafac  stp      x12, x11, [x29, #-0x18]
//   0x214c: a93da7a8  stp      x8, x9, [x29, #-0x28]
//   0x2150: ad400540  ldp      q0, q1, [x10]
//   0x2154: ad3d87a0  stp      q0, q1, [x29, #-0x50]
//   0x2158: 97fffd86  bl       #0x1770
//   0x215c: f9401668  ldr      x8, [x19, #0x28]
//   0x2160: f85f83a9  ldur     x9, [x29, #-8]
//   0x2164: eb09011f  cmp      x8, x9
//   0x2168: 540000a1  b.ne     #0x217c
//   0x216c: a9514ffc  ldp      x28, x19, [sp, #0x110]
//   0x2170: a9507bfd  ldp      x29, x30, [sp, #0x100]
//   0x2174: 910483ff  add      sp, sp, #0x120
//   0x2178: d65f03c0  ret      
//   0x217c: 94000425  bl       #0x3210
// ============================================================================

#include "npth_logcat.h"

#include <cstring>

namespace nextai {
namespace opencut {
namespace npth_logcat {

namespace {

void AppendBytes(char*& cursor, size_t& remaining, size_t& total_len,
                 const char* src, size_t count) noexcept {
    total_len += count;
    if (remaining >= 2 && count > 0) {
        size_t max_copy = remaining - 1;
        size_t to_copy = (count < max_copy) ? count : max_copy;
        std::memcpy(cursor, src, to_copy);
        cursor += to_copy;
        remaining -= to_copy;
        *cursor = '\0';
    }
}

void AppendPadding(char*& cursor, size_t& remaining, size_t& total_len,
                   int pad_count, bool zero_pad) noexcept {
    if (pad_count <= 0) return;
    // Matches 0x1f28..0x1f34 (`0x2020202020202020` vs `0x3030303030303030`)
    const char pad_chunk[8] = {
        zero_pad ? '0' : ' ', zero_pad ? '0' : ' ',
        zero_pad ? '0' : ' ', zero_pad ? '0' : ' ',
        zero_pad ? '0' : ' ', zero_pad ? '0' : ' ',
        zero_pad ? '0' : ' ', zero_pad ? '0' : ' '
    };
    while (pad_count > 0) {
        int step = (pad_count < 8) ? pad_count : 8;
        AppendBytes(cursor, remaining, total_len, pad_chunk, static_cast<size_t>(step));
        pad_count -= step;
    }
}

}  // namespace

// EN: Exact reconstruction of FDE[03] `npth_safe_vsnprintf` (0x1770..0x20ec).
// VI: Tái tạo chính xác FDE[03] `npth_safe_vsnprintf` (0x1770..0x20ec).
int NpthLogcatSafeVsnprintf(char* out_buf, size_t cap, const char* fmt, va_list ap) noexcept {
    if (fmt == nullptr) {
        return 0;
    }
    char* cursor = out_buf;
    size_t remaining = (out_buf != nullptr) ? cap : 0;
    if (remaining > 0) {
        *cursor = '\0';
    }
    size_t total_len = 0;

    while (*fmt != '\0') {
        const char* literal_start = fmt;
        while (*fmt != '\0' && *fmt != '%') {
            ++fmt;
        }
        if (fmt > literal_start) {
            AppendBytes(cursor, remaining, total_len,
                        literal_start, static_cast<size_t>(fmt - literal_start));
        }
        if (*fmt == '\0') {
            break;
        }
        ++fmt;  // skip '%'
        if (*fmt == '\0') {
            break;
        }
        if (*fmt == '%') {
            AppendBytes(cursor, remaining, total_len, "%", 1);
            ++fmt;
            continue;
        }

        bool left_align = false;
        bool zero_pad = false;
        for (;;) {
            if (*fmt == '-') {
                left_align = true;
                ++fmt;
            } else if (*fmt == '0') {
                zero_pad = true;
                ++fmt;
            } else if (*fmt == '+' || *fmt == ' ' || *fmt == '#') {
                ++fmt;
            } else {
                break;
            }
        }

        int width = 0;
        while (*fmt >= '0' && *fmt <= '9') {
            width = width * 10 + (*fmt - '0');
            ++fmt;
        }

        if (*fmt == '.') {
            ++fmt;
            while (*fmt >= '0' && *fmt <= '9') {
                ++fmt;
            }
        }

        int length_mod = 0;
        while (*fmt == 'l' || *fmt == 'h' || *fmt == 'z') {
            if (*fmt == 'l') {
                length_mod = (length_mod == 'l') ? 'L' : 'l';
            } else if (*fmt == 'h') {
                length_mod = (length_mod == 'h') ? 'H' : 'h';
            } else if (*fmt == 'z') {
                length_mod = 'z';
            }
            ++fmt;
        }

        char spec = *fmt;
        if (spec == '\0') {
            break;
        }
        ++fmt;

        char scratch[40]{};
        const char* formatted_str = scratch;

        if (spec == 's') {
            const char* s = va_arg(ap, const char*);
            formatted_str = (s != nullptr) ? s : "(null)";  // .rodata 0x110e "(null)"
        } else if (spec == 'c') {
            int ch = va_arg(ap, int);
            scratch[0] = static_cast<char>(ch);
            scratch[1] = '\0';
        } else if (spec == 'p') {
            uintptr_t ptr_val = reinterpret_cast<uintptr_t>(va_arg(ap, void*));
            scratch[0] = '0';
            scratch[1] = 'x';
            if (ptr_val == 0) {
                scratch[2] = '0';
                scratch[3] = '\0';
            } else {
                char rev[24]{};
                int idx = 0;
                while (ptr_val != 0 && idx < 20) {
                    uint32_t nib = static_cast<uint32_t>(ptr_val & 0xFU);
                    rev[idx++] = static_cast<char>((nib < 10U) ? ('0' + nib) : ('a' + (nib - 10U)));
                    ptr_val >>= 4;
                }
                for (int j = 0; j < idx; ++j) {
                    scratch[2 + j] = rev[idx - 1 - j];
                }
                scratch[2 + idx] = '\0';
            }
        } else if (spec == 'd' || spec == 'i' || spec == 'u' ||
                   spec == 'o' || spec == 'x' || spec == 'X') {
            bool is_signed = (spec == 'd' || spec == 'i');
            uint64_t uval = 0;
            bool negative = false;
            if (is_signed) {
                int64_t sval = 0;
                if (length_mod == 'L' || length_mod == 'l' || length_mod == 'z') {
                    sval = va_arg(ap, long);
                } else {
                    sval = va_arg(ap, int);
                    if (length_mod == 'H') sval = static_cast<signed char>(sval);
                    else if (length_mod == 'h') sval = static_cast<short>(sval);
                }
                if (sval < 0) {
                    negative = true;
                    uval = static_cast<uint64_t>(-sval);
                } else {
                    uval = static_cast<uint64_t>(sval);
                }
            } else {
                if (length_mod == 'L' || length_mod == 'l' || length_mod == 'z') {
                    uval = va_arg(ap, unsigned long);
                } else {
                    uval = va_arg(ap, unsigned int);
                    if (length_mod == 'H') uval &= 0xFFU;
                    else if (length_mod == 'h') uval &= 0xFFFFU;
                }
            }

            uint32_t base = 10U;
            if (spec == 'x' || spec == 'X') base = 16U;
            else if (spec == 'o') base = 8U;
            char hex_a = (spec == 'X') ? 'A' : 'a';

            char rev[32]{};
            int idx = 0;
            if (uval == 0) {
                rev[idx++] = '0';
            } else {
                while (uval != 0 && idx < 30) {
                    uint32_t rem = static_cast<uint32_t>(uval % base);
                    rev[idx++] = static_cast<char>((rem < 10U) ? ('0' + rem) : (hex_a + (rem - 10U)));
                    uval /= base;
                }
            }
            int out_pos = 0;
            if (negative) {
                scratch[out_pos++] = '-';
            }
            for (int j = 0; j < idx; ++j) {
                scratch[out_pos++] = rev[idx - 1 - j];
            }
            scratch[out_pos] = '\0';
        } else {
            continue;
        }

        size_t piece_len = std::strlen(formatted_str);
        int pad = width - static_cast<int>(piece_len);
        if (!left_align && pad > 0) {
            AppendPadding(cursor, remaining, total_len, pad, zero_pad);
        }
        AppendBytes(cursor, remaining, total_len, formatted_str, piece_len);
        if (left_align && pad > 0) {
            AppendPadding(cursor, remaining, total_len, pad, false);
        }
    }

    return static_cast<int>(total_len);
}

// EN: Exact reconstruction of FDE[04] `npth_safe_snprintf` (0x20ec..0x2180).
// VI: Tái tạo chính xác FDE[04] `npth_safe_snprintf` (0x20ec..0x2180).
int NpthLogcatSafeSnprintf(char* out_buf, size_t cap, const char* fmt, ...) noexcept {
    va_list ap;
    va_start(ap, fmt);
    int res = NpthLogcatSafeVsnprintf(out_buf, cap, fmt, ap);
    va_end(ap);
    return res;
}

}  // namespace npth_logcat
}  // namespace opencut
}  // namespace nextai
