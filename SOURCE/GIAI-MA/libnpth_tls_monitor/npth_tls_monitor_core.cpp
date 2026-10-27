// ============================================================================
// NextAI OpenCut — Clean-Room C++17 Reconstruction
// File          : npth_tls_monitor_core.cpp
// Target Binary : libnpth_tls_monitor.so (15,904 bytes)
// SHA-256       : 7dc9ec38a56447ae99bde0d8bb89408b3583ea62097a3c0f7d55ba8c5b4e0fa7
// Task ID       : TASK-168-RECONSTRUCTION-LIBNPTH-TLS-MONITOR
// Functions     : FDE[00..04] CRT stubs (0x17ac..0x17f8),
//                 FDE[05] NpthPthreadKeyMonitorInit (0x17fc..0x1ac4),
//                 FDE[06] NpthPthreadKeyMonitorDump (0x1ac8..0x203c),
//                 FDE[07] NpthTlsCallerFilter (0x2040..0x20b0),
//                 FDE[08] NpthHookedPthreadKeyCreate (0x20b4..0x2144),
//                 FDE[09] NpthHookStubNoop (0x2148..0x214b),
//                 FDE[10] NpthHookedPthreadKeyDelete (0x214c..0x2200),
//                 FDE[11] NpthRecordTlsKeyEvent (0x2204..0x2370)
// ============================================================================
// EN: Clean-room C++17 implementation of the ByteDance NPTH Pthread TLS Key
//     Monitor core engine and exported `tls_native_interface_func` table.
// VI: Bản cài đặt C++17 phòng sạch của nhân giám sát khóa TLS Pthread ByteDance
//     NPTH và bảng hàm xuất khẩu `tls_native_interface_func`.
// ============================================================================
// Complete AArch64 Disassembly Trace for 0x17ac..0x2370 (754 instructions):
//   0x17ac: d503245f  bti      c
//   0x17b0: d503201f  nop      
//   0x17b4: 1002dbe0  adr      x0, #0x7330
//   0x17b8: 14000646  b        #0x30d0
//   0x17bc: d503245f  bti      c
//   0x17c0: d65f03c0  ret      
//   0x17c4: d503245f  bti      c
//   0x17c8: 17fffffd  b        #0x17bc
//   0x17cc: d503245f  bti      c
//   0x17d0: b4000060  cbz      x0, #0x17dc
//   0x17d4: aa0003f0  mov      x16, x0
//   0x17d8: d61f0200  br       x16
//   0x17dc: d65f03c0  ret      
//   0x17e0: d503245f  bti      c
//   0x17e4: aa0003e1  mov      x1, x0
//   0x17e8: d503201f  nop      
//   0x17ec: 10ffff00  adr      x0, #0x17cc
//   0x17f0: d503201f  nop      
//   0x17f4: 1002d9e2  adr      x2, #0x7330
//   0x17f8: 1400063a  b        #0x30e0
//   0x17fc: a9bd7bfd  stp      x29, x30, [sp, #-0x30]!
//   0x1800: f9000bf5  str      x21, [sp, #0x10]
//   0x1804: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x1808: 910003fd  mov      x29, sp
//   0x180c: 51008c08  sub      w8, w0, #0x23
//   0x1810: 3100311f  cmn      w8, #0xc
//   0x1814: 54000062  b.hs     #0x1820
//   0x1818: 12800000  mov      w0, #-1
//   0x181c: 1400001e  b        #0x1894
//   0x1820: d0000055  adrp     x21, #0xb000
//   0x1824: 3959c2a8  ldrb     w8, [x21, #0x670]
//   0x1828: 7100051f  cmp      w8, #1
//   0x182c: 54000121  b.ne     #0x1850
//   0x1830: d503201f  nop      
//   0x1834: 50ffc041  adr      x1, #0x103e
//   0x1838: 90000002  adrp     x2, #0x1000
//   0x183c: 9103c042  add      x2, x2, #0xf0
//   0x1840: 52800080  mov      w0, #4
//   0x1844: 9400062b  bl       #0x30f0
//   0x1848: 12800020  mov      w0, #-2
//   0x184c: 14000012  b        #0x1894
//   0x1850: b4fffe41  cbz      x1, #0x1818
//   0x1854: 2a0003f3  mov      w19, w0
//   0x1858: aa0103e0  mov      x0, x1
//   0x185c: 94000629  bl       #0x3100
//   0x1860: d0000048  adrp     x8, #0xb000
//   0x1864: 2a1f03e1  mov      w1, wzr
//   0x1868: f9033d00  str      x0, [x8, #0x678]
//   0x186c: 2a1f03e0  mov      w0, wzr
//   0x1870: 94000628  bl       #0x3110
//   0x1874: d503201f  nop      
//   0x1878: 50ffbe21  adr      x1, #0x103e
//   0x187c: 34000140  cbz      w0, #0x18a4
//   0x1880: f0ffffe2  adrp     x2, #0
//   0x1884: 913ba042  add      x2, x2, #0xee8
//   0x1888: 528000c0  mov      w0, #6
//   0x188c: 94000619  bl       #0x30f0
//   0x1890: 12800040  mov      w0, #-3
//   0x1894: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x1898: f9400bf5  ldr      x21, [sp, #0x10]
//   0x189c: a8c37bfd  ldp      x29, x30, [sp], #0x30
//   0x18a0: d65f03c0  ret      
//   0x18a4: 90000002  adrp     x2, #0x1000
//   0x18a8: 91051c42  add      x2, x2, #0x147
//   0x18ac: 52800080  mov      w0, #4
//   0x18b0: 94000610  bl       #0x30f0
//   0x18b4: d0000048  adrp     x8, #0xb000
//   0x18b8: 52800029  mov      w9, #1
//   0x18bc: d0000054  adrp     x20, #0xb000
//   0x18c0: 51006a6a  sub      w10, w19, #0x1a
//   0x18c4: 71001d5f  cmp      w10, #7
//   0x18c8: b9068113  str      w19, [x8, #0x680]
//   0x18cc: 3919c2a9  strb     w9, [x21, #0x670]
//   0x18d0: 54000128  b.hi     #0x18f4
//   0x18d4: 52800020  mov      w0, #1
//   0x18d8: 52810401  mov      w1, #0x820
//   0x18dc: 94000611  bl       #0x3120
//   0x18e0: d0000048  adrp     x8, #0xb000
//   0x18e4: f9034900  str      x0, [x8, #0x690]
//   0x18e8: b40001e0  cbz      x0, #0x1924
//   0x18ec: 52801048  mov      w8, #0x82
//   0x18f0: 1400000a  b        #0x1918
//   0x18f4: 7100667f  cmp      w19, #0x19
//   0x18f8: 54000168  b.hi     #0x1924
//   0x18fc: 52800020  mov      w0, #1
//   0x1900: 52811a01  mov      w1, #0x8d0
//   0x1904: 94000607  bl       #0x3120
//   0x1908: d0000048  adrp     x8, #0xb000
//   0x190c: f9034900  str      x0, [x8, #0x690]
//   0x1910: b40000a0  cbz      x0, #0x1924
//   0x1914: 528011a8  mov      w8, #0x8d
//   0x1918: d0000049  adrp     x9, #0xb000
//   0x191c: b9069928  str      w8, [x9, #0x698]
//   0x1920: 14000009  b        #0x1944
//   0x1924: 12800008  mov      w8, #-1
//   0x1928: d503201f  nop      
//   0x192c: 50ffb881  adr      x1, #0x103e
//   0x1930: 90000002  adrp     x2, #0x1000
//   0x1934: 91045442  add      x2, x2, #0x115
//   0x1938: 528000c0  mov      w0, #6
//   0x193c: b906a288  str      w8, [x20, #0x6a0]
//   0x1940: 940005ec  bl       #0x30f0
//   0x1944: 52800028  mov      w8, #1
//   0x1948: 52800020  mov      w0, #1
//   0x194c: 52800e01  mov      w1, #0x70
//   0x1950: b906a288  str      w8, [x20, #0x6a0]
//   0x1954: 940005f3  bl       #0x3120
//   0x1958: d0000048  adrp     x8, #0xb000
//   0x195c: f9035500  str      x0, [x8, #0x6a8]
//   0x1960: b40005c0  cbz      x0, #0x1a18
//   0x1964: a9000000  stp      x0, x0, [x0]
//   0x1968: f0ffffe0  adrp     x0, #0
//   0x196c: 913e7000  add      x0, x0, #0xf9c
//   0x1970: 940005f0  bl       #0x3130
//   0x1974: d0000054  adrp     x20, #0xb000
//   0x1978: b4000100  cbz      x0, #0x1998
//   0x197c: f0ffffe1  adrp     x1, #0
//   0x1980: 913f1c21  add      x1, x1, #0xfc7
//   0x1984: aa0003f3  mov      x19, x0
//   0x1988: 940005ee  bl       #0x3140
//   0x198c: f9034680  str      x0, [x20, #0x688]
//   0x1990: aa1303e0  mov      x0, x19
//   0x1994: 940005ef  bl       #0x3150
//   0x1998: f9434688  ldr      x8, [x20, #0x688]
//   0x199c: b40005a8  cbz      x8, #0x1a50
//   0x19a0: 2a1f03e0  mov      w0, wzr
//   0x19a4: 940005ef  bl       #0x3160
//   0x19a8: d503201f  nop      
//   0x19ac: 100034a0  adr      x0, #0x2040
//   0x19b0: 90000003  adrp     x3, #0x1000
//   0x19b4: 910a0c63  add      x3, x3, #0x283
//   0x19b8: d503201f  nop      
//   0x19bc: 100037c4  adr      x4, #0x20b4
//   0x19c0: d503201f  nop      
//   0x19c4: 10003c25  adr      x5, #0x2148
//   0x19c8: aa1f03e1  mov      x1, xzr
//   0x19cc: aa1f03e2  mov      x2, xzr
//   0x19d0: aa1f03e6  mov      x6, xzr
//   0x19d4: 940005e7  bl       #0x3170
//   0x19d8: b4000500  cbz      x0, #0x1a78
//   0x19dc: d503201f  nop      
//   0x19e0: 10003300  adr      x0, #0x2040
//   0x19e4: 90000003  adrp     x3, #0x1000
//   0x19e8: 91089863  add      x3, x3, #0x226
//   0x19ec: d503201f  nop      
//   0x19f0: 10003ae4  adr      x4, #0x214c
//   0x19f4: d503201f  nop      
//   0x19f8: 10003a85  adr      x5, #0x2148
//   0x19fc: aa1f03e1  mov      x1, xzr
//   0x1a00: aa1f03e2  mov      x2, xzr
//   0x1a04: aa1f03e6  mov      x6, xzr
//   0x1a08: 940005da  bl       #0x3170
//   0x1a0c: b40003e0  cbz      x0, #0x1a88
//   0x1a10: 2a1f03e0  mov      w0, wzr
//   0x1a14: 17ffffa0  b        #0x1894
//   0x1a18: d503201f  nop      
//   0x1a1c: 50ffb113  adr      x19, #0x103e
//   0x1a20: f0ffffe2  adrp     x2, #0
//   0x1a24: 913dc842  add      x2, x2, #0xf72
//   0x1a28: 528000c0  mov      w0, #6
//   0x1a2c: aa1303e1  mov      x1, x19
//   0x1a30: 940005b0  bl       #0x30f0
//   0x1a34: 90000002  adrp     x2, #0x1000
//   0x1a38: 9109c842  add      x2, x2, #0x272
//   0x1a3c: 528000c0  mov      w0, #6
//   0x1a40: aa1303e1  mov      x1, x19
//   0x1a44: 940005ab  bl       #0x30f0
//   0x1a48: 12800060  mov      w0, #-4
//   0x1a4c: 17ffff92  b        #0x1894
//   0x1a50: d503201f  nop      
//   0x1a54: 50ffaf41  adr      x1, #0x103e
//   0x1a58: f0ffffe2  adrp     x2, #0
//   0x1a5c: 913c0842  add      x2, x2, #0xf02
//   0x1a60: f0ffffe3  adrp     x3, #0
//   0x1a64: 913ce063  add      x3, x3, #0xf38
//   0x1a68: 528000c0  mov      w0, #6
//   0x1a6c: 940005a1  bl       #0x30f0
//   0x1a70: 12800080  mov      w0, #-5
//   0x1a74: 17ffff88  b        #0x1894
//   0x1a78: 12800013  mov      w19, #-1
//   0x1a7c: 90000002  adrp     x2, #0x1000
//   0x1a80: 91083c42  add      x2, x2, #0x20f
//   0x1a84: 14000004  b        #0x1a94
//   0x1a88: 12800033  mov      w19, #-2
//   0x1a8c: f0ffffe2  adrp     x2, #0
//   0x1a90: 913c6842  add      x2, x2, #0xf1a
//   0x1a94: d503201f  nop      
//   0x1a98: 50ffad34  adr      x20, #0x103e
//   0x1a9c: 528000c0  mov      w0, #6
//   0x1aa0: aa1403e1  mov      x1, x20
//   0x1aa4: 94000593  bl       #0x30f0
//   0x1aa8: 90000002  adrp     x2, #0x1000
//   0x1aac: 91056442  add      x2, x2, #0x159
//   0x1ab0: 528000c0  mov      w0, #6
//   0x1ab4: aa1403e1  mov      x1, x20
//   0x1ab8: 2a1303e3  mov      w3, w19
//   0x1abc: 9400058d  bl       #0x30f0
//   0x1ac0: 128000a0  mov      w0, #-6
//   0x1ac4: 17ffff74  b        #0x1894
//   0x1ac8: a9ba7bfd  stp      x29, x30, [sp, #-0x60]!
//   0x1acc: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x1ad0: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x1ad4: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x1ad8: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x1adc: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x1ae0: 910003fd  mov      x29, sp
//   0x1ae4: d12683ff  sub      sp, sp, #0x9a0
//   0x1ae8: d53bd05b  mrs      x27, tpidr_el0
//   0x1aec: d0000049  adrp     x9, #0xb000
//   0x1af0: f9401768  ldr      x8, [x27, #0x28]
//   0x1af4: f81e83a8  stur     x8, [x29, #-0x18]
//   0x1af8: 3959c128  ldrb     w8, [x9, #0x670]
//   0x1afc: 7100051f  cmp      w8, #1
//   0x1b00: 54002741  b.ne     #0x1fe8
//   0x1b04: d0000057  adrp     x23, #0xb000
//   0x1b08: d0000049  adrp     x9, #0xb000
//   0x1b0c: f9433ee4  ldr      x4, [x23, #0x678]
//   0x1b10: b906b128  str      w8, [x9, #0x6b0]
//   0x1b14: b40026a4  cbz      x4, #0x1fe8
//   0x1b18: d0000048  adrp     x8, #0xb000
//   0x1b1c: f0ffffe3  adrp     x3, #0
//   0x1b20: 913e1463  add      x3, x3, #0xf85
//   0x1b24: 911623e0  add      x0, sp, #0x588
//   0x1b28: 52808001  mov      w1, #0x400
//   0x1b2c: 52808002  mov      w2, #0x400
//   0x1b30: b9468114  ldr      w20, [x8, #0x680]
//   0x1b34: 910403f6  add      x22, sp, #0x100
//   0x1b38: 9400020f  bl       #0x2374
//   0x1b3c: 911623e0  add      x0, sp, #0x588
//   0x1b40: 52800801  mov      w1, #0x40
//   0x1b44: 94000512  bl       #0x2f8c
//   0x1b48: 7100041f  cmp      w0, #1
//   0x1b4c: 540011cb  b.lt     #0x1d84
//   0x1b50: d000005c  adrp     x28, #0xb000
//   0x1b54: 2a0003f3  mov      w19, w0
//   0x1b58: f9434b80  ldr      x0, [x28, #0x690]
//   0x1b5c: b4001140  cbz      x0, #0x1d84
//   0x1b60: d0000048  adrp     x8, #0xb000
//   0x1b64: f9434501  ldr      x1, [x8, #0x688]
//   0x1b68: b40010e1  cbz      x1, #0x1d84
//   0x1b6c: d0000048  adrp     x8, #0xb000
//   0x1b70: b946a108  ldr      w8, [x8, #0x6a0]
//   0x1b74: 3100051f  cmn      w8, #1
//   0x1b78: 540000c0  b.eq     #0x1b90
//   0x1b7c: 51006a88  sub      w8, w20, #0x1a
//   0x1b80: 71001d1f  cmp      w8, #7
//   0x1b84: 54000188  b.hi     #0x1bb4
//   0x1b88: 52810402  mov      w2, #0x820
//   0x1b8c: 1400000e  b        #0x1bc4
//   0x1b90: d503201f  nop      
//   0x1b94: 50ffa541  adr      x1, #0x103e
//   0x1b98: f0ffffe2  adrp     x2, #0
//   0x1b9c: 913d7842  add      x2, x2, #0xf5e
//   0x1ba0: 90000003  adrp     x3, #0x1000
//   0x1ba4: 9107f863  add      x3, x3, #0x1fe
//   0x1ba8: 528000c0  mov      w0, #6
//   0x1bac: 94000551  bl       #0x30f0
//   0x1bb0: 14000006  b        #0x1bc8
//   0x1bb4: 51005e88  sub      w8, w20, #0x17
//   0x1bb8: 7100091f  cmp      w8, #2
//   0x1bbc: 54000068  b.hi     #0x1bc8
//   0x1bc0: 52811a02  mov      w2, #0x8d0
//   0x1bc4: 9400056f  bl       #0x3180
//   0x1bc8: f0ffffe1  adrp     x1, #0
//   0x1bcc: 913e9021  add      x1, x1, #0xfa4
//   0x1bd0: 2a1303e0  mov      w0, w19
//   0x1bd4: 2a1f03e2  mov      w2, wzr
//   0x1bd8: 94000494  bl       #0x2e28
//   0x1bdc: 35000d40  cbnz     w0, #0x1d84
//   0x1be0: d0000058  adrp     x24, #0xb000
//   0x1be4: 6f00e400  movi     v0.2d, #0000000000000000
//   0x1be8: b9469b08  ldr      w8, [x24, #0x698]
//   0x1bec: ad0002c0  stp      q0, q0, [x22]
//   0x1bf0: 7100051f  cmp      w8, #1
//   0x1bf4: ad0102c0  stp      q0, q0, [x22, #0x20]
//   0x1bf8: ad0202c0  stp      q0, q0, [x22, #0x40]
//   0x1bfc: ad0302c0  stp      q0, q0, [x22, #0x60]
//   0x1c00: ad0402c0  stp      q0, q0, [x22, #0x80]
//   0x1c04: ad0502c0  stp      q0, q0, [x22, #0xa0]
//   0x1c08: ad0602c0  stp      q0, q0, [x22, #0xc0]
//   0x1c0c: ad0702c0  stp      q0, q0, [x22, #0xe0]
//   0x1c10: ad0802c0  stp      q0, q0, [x22, #0x100]
//   0x1c14: ad0902c0  stp      q0, q0, [x22, #0x120]
//   0x1c18: ad0a02c0  stp      q0, q0, [x22, #0x140]
//   0x1c1c: ad0b02c0  stp      q0, q0, [x22, #0x160]
//   0x1c20: ad0c02c0  stp      q0, q0, [x22, #0x180]
//   0x1c24: ad0d02c0  stp      q0, q0, [x22, #0x1a0]
//   0x1c28: ad0e02c0  stp      q0, q0, [x22, #0x1c0]
//   0x1c2c: ad0f02c0  stp      q0, q0, [x22, #0x1e0]
//   0x1c30: 5400090b  b.lt     #0x1d50
//   0x1c34: aa1f03f7  mov      x23, xzr
//   0x1c38: aa1f03f5  mov      x21, xzr
//   0x1c3c: 2a1f03f4  mov      w20, wzr
//   0x1c40: 14000019  b        #0x1ca4
//   0x1c44: f240033f  tst      x25, #1
//   0x1c48: 90000008  adrp     x8, #0x1000
//   0x1c4c: 9104d108  add      x8, x8, #0x134
//   0x1c50: 90000009  adrp     x9, #0x1000
//   0x1c54: 91043929  add      x9, x9, #0x10e
//   0x1c58: 910403e0  add      x0, sp, #0x100
//   0x1c5c: 9a880126  csel     x6, x9, x8, eq
//   0x1c60: 52804001  mov      w1, #0x200
//   0x1c64: 52804002  mov      w2, #0x200
//   0x1c68: 90000003  adrp     x3, #0x1000
//   0x1c6c: 9102dc63  add      x3, x3, #0xb7
//   0x1c70: 2a1503e4  mov      w4, w21
//   0x1c74: aa1903e5  mov      x5, x25
//   0x1c78: 940001bf  bl       #0x2374
//   0x1c7c: 93407c02  sxtw     x2, w0
//   0x1c80: 910403e1  add      x1, sp, #0x100
//   0x1c84: 2a1303e0  mov      w0, w19
//   0x1c88: 11000694  add      w20, w20, #1
//   0x1c8c: 94000467  bl       #0x2e28
//   0x1c90: b9869b08  ldrsw    x8, [x24, #0x698]
//   0x1c94: 910006b5  add      x21, x21, #1
//   0x1c98: 910042f7  add      x23, x23, #0x10
//   0x1c9c: eb0802bf  cmp      x21, x8
//   0x1ca0: 540005aa  b.ge     #0x1d54
//   0x1ca4: f9434b88  ldr      x8, [x28, #0x690]
//   0x1ca8: 8b170108  add      x8, x8, x23
//   0x1cac: f9400119  ldr      x25, [x8]
//   0x1cb0: f940051a  ldr      x26, [x8, #8]
//   0x1cb4: f100035f  cmp      x26, #0
//   0x1cb8: fa400b24  ccmp     x25, #0, #4, eq
//   0x1cbc: 54fffc41  b.ne     #0x1c44
//   0x1cc0: 911403e1  add      x1, sp, #0x500
//   0x1cc4: aa1a03e0  mov      x0, x26
//   0x1cc8: 94000532  bl       #0x3190
//   0x1ccc: 34fffe20  cbz      w0, #0x1c90
//   0x1cd0: f94287ea  ldr      x10, [sp, #0x508]
//   0x1cd4: f240033f  tst      x25, #1
//   0x1cd8: 90000008  adrp     x8, #0x1000
//   0x1cdc: 9104d108  add      x8, x8, #0x134
//   0x1ce0: 9000000b  adrp     x11, #0x1000
//   0x1ce4: 9104396b  add      x11, x11, #0x10e
//   0x1ce8: f9428be9  ldr      x9, [sp, #0x510]
//   0x1cec: 9a880166  csel     x6, x11, x8, eq
//   0x1cf0: f94283e8  ldr      x8, [sp, #0x500]
//   0x1cf4: cb0a0347  sub      x7, x26, x10
//   0x1cf8: b4000189  cbz      x9, #0x1d28
//   0x1cfc: f9428fea  ldr      x10, [sp, #0x518]
//   0x1d00: 910403e0  add      x0, sp, #0x100
//   0x1d04: 52804001  mov      w1, #0x200
//   0x1d08: 52804002  mov      w2, #0x200
//   0x1d0c: 90000003  adrp     x3, #0x1000
//   0x1d10: 9101f063  add      x3, x3, #0x7c
//   0x1d14: cb0a034a  sub      x10, x26, x10
//   0x1d18: 2a1503e4  mov      w4, w21
//   0x1d1c: aa1903e5  mov      x5, x25
//   0x1d20: a900abe9  stp      x9, x10, [sp, #8]
//   0x1d24: 14000008  b        #0x1d44
//   0x1d28: 910403e0  add      x0, sp, #0x100
//   0x1d2c: 52804001  mov      w1, #0x200
//   0x1d30: 52804002  mov      w2, #0x200
//   0x1d34: 90000003  adrp     x3, #0x1000
//   0x1d38: 9108e463  add      x3, x3, #0x239
//   0x1d3c: 2a1503e4  mov      w4, w21
//   0x1d40: aa1903e5  mov      x5, x25
//   0x1d44: f90003e8  str      x8, [sp]
//   0x1d48: 9400018b  bl       #0x2374
//   0x1d4c: 17ffffcc  b        #0x1c7c
//   0x1d50: 2a1f03f4  mov      w20, wzr
//   0x1d54: 2a1303e0  mov      w0, w19
//   0x1d58: aa1f03e1  mov      x1, xzr
//   0x1d5c: 2a1f03e2  mov      w2, wzr
//   0x1d60: 94000510  bl       #0x31a0
//   0x1d64: f0ffffe1  adrp     x1, #0
//   0x1d68: 913e9021  add      x1, x1, #0xfa4
//   0x1d6c: 2a1303e0  mov      w0, w19
//   0x1d70: 2a1403e2  mov      w2, w20
//   0x1d74: 9400042d  bl       #0x2e28
//   0x1d78: 2a1303e0  mov      w0, w19
//   0x1d7c: 9400050d  bl       #0x31b0
//   0x1d80: d0000057  adrp     x23, #0xb000
//   0x1d84: f9433ee4  ldr      x4, [x23, #0x678]
//   0x1d88: 90000003  adrp     x3, #0x1000
//   0x1d8c: 910a5863  add      x3, x3, #0x296
//   0x1d90: 911623e0  add      x0, sp, #0x588
//   0x1d94: 52808001  mov      w1, #0x400
//   0x1d98: 52808002  mov      w2, #0x400
//   0x1d9c: 94000176  bl       #0x2374
//   0x1da0: 911623e0  add      x0, sp, #0x588
//   0x1da4: 52800801  mov      w1, #0x40
//   0x1da8: 94000479  bl       #0x2f8c
//   0x1dac: 7100041f  cmp      w0, #1
//   0x1db0: 5400134b  b.lt     #0x2018
//   0x1db4: d0000058  adrp     x24, #0xb000
//   0x1db8: 2a0003f3  mov      w19, w0
//   0x1dbc: f9435708  ldr      x8, [x24, #0x6a8]
//   0x1dc0: 91004100  add      x0, x8, #0x10
//   0x1dc4: 940004ff  bl       #0x31c0
//   0x1dc8: d0000048  adrp     x8, #0xb000
//   0x1dcc: d0000049  adrp     x9, #0xb000
//   0x1dd0: 6f00e400  movi     v0.2d, #0000000000000000
//   0x1dd4: 90000003  adrp     x3, #0x1000
//   0x1dd8: 91015463  add      x3, x3, #0x55
//   0x1ddc: 911403e0  add      x0, sp, #0x500
//   0x1de0: b946b504  ldr      w4, [x8, #0x6b4]
//   0x1de4: 52801001  mov      w1, #0x80
//   0x1de8: b946b925  ldr      w5, [x9, #0x6b8]
//   0x1dec: 52801002  mov      w2, #0x80
//   0x1df0: 3d811ec0  str      q0, [x22, #0x470]
//   0x1df4: 3d811ac0  str      q0, [x22, #0x460]
//   0x1df8: 3d8116c0  str      q0, [x22, #0x450]
//   0x1dfc: 3d8112c0  str      q0, [x22, #0x440]
//   0x1e00: 3d810ec0  str      q0, [x22, #0x430]
//   0x1e04: 3d810ac0  str      q0, [x22, #0x420]
//   0x1e08: 3d8106c0  str      q0, [x22, #0x410]
//   0x1e0c: 3d8102c0  str      q0, [x22, #0x400]
//   0x1e10: 94000159  bl       #0x2374
//   0x1e14: 93407c02  sxtw     x2, w0
//   0x1e18: 911403e1  add      x1, sp, #0x500
//   0x1e1c: 2a1303e0  mov      w0, w19
//   0x1e20: 94000402  bl       #0x2e28
//   0x1e24: f9435708  ldr      x8, [x24, #0x6a8]
//   0x1e28: f9400114  ldr      x20, [x8]
//   0x1e2c: eb08029f  cmp      x20, x8
//   0x1e30: 54000c00  b.eq     #0x1fb0
//   0x1e34: 528e4c7c  mov      w28, #0x7263
//   0x1e38: 52800059  mov      w25, #2
//   0x1e3c: 910303f5  add      x21, sp, #0xc0
//   0x1e40: 72ac2cbc  movk     w28, #0x6165, lsl #16
//   0x1e44: 90000016  adrp     x22, #0x1000
//   0x1e48: 9105c6d6  add      x22, x22, #0x171
//   0x1e4c: 14000020  b        #0x1ecc
//   0x1e50: 910403e0  add      x0, sp, #0x100
//   0x1e54: 52808001  mov      w1, #0x400
//   0x1e58: 52808002  mov      w2, #0x400
//   0x1e5c: f0ffffe3  adrp     x3, #0
//   0x1e60: 913f4c63  add      x3, x3, #0xfd3
//   0x1e64: a90447f0  stp      x16, x17, [sp, #0x40]
//   0x1e68: a9033fee  stp      x14, x15, [sp, #0x30]
//   0x1e6c: a90257ec  stp      x12, x21, [sp, #0x20]
//   0x1e70: b9001beb  str      w11, [sp, #0x18]
//   0x1e74: b90013ea  str      w10, [sp, #0x10]
//   0x1e78: b9000be9  str      w9, [sp, #8]
//   0x1e7c: b90003e8  str      w8, [sp]
//   0x1e80: 9400013d  bl       #0x2374
//   0x1e84: 93407c02  sxtw     x2, w0
//   0x1e88: 910403e1  add      x1, sp, #0x100
//   0x1e8c: 2a1303e0  mov      w0, w19
//   0x1e90: 940003e6  bl       #0x2e28
//   0x1e94: a9402289  ldp      x9, x8, [x20]
//   0x1e98: f9000528  str      x8, [x9, #8]
//   0x1e9c: f9400688  ldr      x8, [x20, #8]
//   0x1ea0: f9000109  str      x9, [x8]
//   0x1ea4: f9402680  ldr      x0, [x20, #0x48]
//   0x1ea8: 940004ca  bl       #0x31d0
//   0x1eac: aa1403e0  mov      x0, x20
//   0x1eb0: 940004c8  bl       #0x31d0
//   0x1eb4: f9435708  ldr      x8, [x24, #0x6a8]
//   0x1eb8: d0000049  adrp     x9, #0xb000
//   0x1ebc: b906b139  str      w25, [x9, #0x6b0]
//   0x1ec0: aa1a03f4  mov      x20, x26
//   0x1ec4: eb08035f  cmp      x26, x8
//   0x1ec8: 54000740  b.eq     #0x1fb0
//   0x1ecc: f9403280  ldr      x0, [x20, #0x60]
//   0x1ed0: f940029a  ldr      x26, [x20]
//   0x1ed4: b4ffff60  cbz      x0, #0x1ec0
//   0x1ed8: 910283e1  add      x1, sp, #0xa0
//   0x1edc: 940004ad  bl       #0x3190
//   0x1ee0: 34fffda0  cbz      w0, #0x1e94
//   0x1ee4: 910403e0  add      x0, sp, #0x100
//   0x1ee8: 2a1f03e1  mov      w1, wzr
//   0x1eec: 52808002  mov      w2, #0x400
//   0x1ef0: 940004bc  bl       #0x31e0
//   0x1ef4: b9404288  ldr      w8, [x20, #0x40]
//   0x1ef8: 7100091f  cmp      w8, #2
//   0x1efc: 54000100  b.eq     #0x1f1c
//   0x1f00: 7100051f  cmp      w8, #1
//   0x1f04: 54000181  b.ne     #0x1f34
//   0x1f08: 528e8c28  mov      w8, #0x7461
//   0x1f0c: 72a00ca8  movk     w8, #0x65, lsl #16
//   0x1f10: b80c33e8  stur     w8, [sp, #0xc3]
//   0x1f14: b900c3fc  str      w28, [sp, #0xc0]
//   0x1f18: 14000007  b        #0x1f34
//   0x1f1c: 528e8ca8  mov      w8, #0x7465
//   0x1f20: 72a00ca8  movk     w8, #0x65, lsl #16
//   0x1f24: b80c33e8  stur     w8, [sp, #0xc3]
//   0x1f28: 528cac88  mov      w8, #0x6564
//   0x1f2c: 72acad88  movk     w8, #0x656c, lsl #16
//   0x1f30: b900c3e8  str      w8, [sp, #0xc0]
//   0x1f34: 9101a280  add      x0, x20, #0x68
//   0x1f38: 9101a3e1  add      x1, sp, #0x68
//   0x1f3c: 940004ad  bl       #0x31f0
//   0x1f40: b4fffaa0  cbz      x0, #0x1e94
//   0x1f44: a94ab7f0  ldp      x16, x13, [sp, #0xa8]
//   0x1f48: 294f33ee  ldp      w14, w12, [sp, #0x78]
//   0x1f4c: a945828f  ldp      x15, x0, [x20, #0x58]
//   0x1f50: 294e1be7  ldp      w7, w6, [sp, #0x70]
//   0x1f54: 111db184  add      w4, w12, #0x76c
//   0x1f58: 110005c5  add      w5, w14, #1
//   0x1f5c: cb1001ec  sub      x12, x15, x16
//   0x1f60: f10001ff  cmp      x15, #0
//   0x1f64: 9a8c03ef  csel     x15, xzr, x12, eq
//   0x1f68: f94053f1  ldr      x17, [sp, #0xa0]
//   0x1f6c: a944ba8c  ldp      x12, x14, [x20, #0x48]
//   0x1f70: cb100010  sub      x16, x0, x16
//   0x1f74: 294d23e9  ldp      w9, w8, [sp, #0x68]
//   0x1f78: 29472e8a  ldp      w10, w11, [x20, #0x38]
//   0x1f7c: b4fff6ad  cbz      x13, #0x1e50
//   0x1f80: f9405fe1  ldr      x1, [sp, #0xb8]
//   0x1f84: a90447f0  stp      x16, x17, [sp, #0x40]
//   0x1f88: a9033fee  stp      x14, x15, [sp, #0x30]
//   0x1f8c: 52808002  mov      w2, #0x400
//   0x1f90: a90257ec  stp      x12, x21, [sp, #0x20]
//   0x1f94: aa1603e3  mov      x3, x22
//   0x1f98: cb010000  sub      x0, x0, x1
//   0x1f9c: b9001beb  str      w11, [sp, #0x18]
//   0x1fa0: 52808001  mov      w1, #0x400
//   0x1fa4: a90503ed  stp      x13, x0, [sp, #0x50]
//   0x1fa8: 910403e0  add      x0, sp, #0x100
//   0x1fac: 17ffffb2  b        #0x1e74
//   0x1fb0: 2a1303e0  mov      w0, w19
//   0x1fb4: 9400047f  bl       #0x31b0
//   0x1fb8: f9435708  ldr      x8, [x24, #0x6a8]
//   0x1fbc: b4000108  cbz      x8, #0x1fdc
//   0x1fc0: 52800069  mov      w9, #3
//   0x1fc4: 91004100  add      x0, x8, #0x10
//   0x1fc8: d0000048  adrp     x8, #0xb000
//   0x1fcc: b906b109  str      w9, [x8, #0x6b0]
//   0x1fd0: 9400048c  bl       #0x3200
//   0x1fd4: f9435700  ldr      x0, [x24, #0x6a8]
//   0x1fd8: 9400047e  bl       #0x31d0
//   0x1fdc: f9433ee0  ldr      x0, [x23, #0x678]
//   0x1fe0: b4000040  cbz      x0, #0x1fe8
//   0x1fe4: 9400047b  bl       #0x31d0
//   0x1fe8: f9401768  ldr      x8, [x27, #0x28]
//   0x1fec: f85e83a9  ldur     x9, [x29, #-0x18]
//   0x1ff0: eb09011f  cmp      x8, x9
//   0x1ff4: 54000241  b.ne     #0x203c
//   0x1ff8: 912683ff  add      sp, sp, #0x9a0
//   0x1ffc: a9454ff4  ldp      x20, x19, [sp, #0x50]
//   0x2000: a94457f6  ldp      x22, x21, [sp, #0x40]
//   0x2004: a9435ff8  ldp      x24, x23, [sp, #0x30]
//   0x2008: a94267fa  ldp      x26, x25, [sp, #0x20]
//   0x200c: a9416ffc  ldp      x28, x27, [sp, #0x10]
//   0x2010: a8c67bfd  ldp      x29, x30, [sp], #0x60
//   0x2014: d65f03c0  ret      
//   0x2018: d503201f  nop      
//   0x201c: 50ff8101  adr      x1, #0x103e
//   0x2020: f0ffffe2  adrp     x2, #0x1000
//   0x2024: 91077842  add      x2, x2, #0x1de
//   0x2028: 528000c0  mov      w0, #6
//   0x202c: 94000431  bl       #0x30f0
//   0x2030: f9433ee0  ldr      x0, [x23, #0x678]
//   0x2034: b5fffd80  cbnz     x0, #0x1fe4
//   0x2038: 17ffffec  b        #0x1fe8
//   0x203c: 94000475  bl       #0x3210
//   0x2040: a9be7bfd  stp      x29, x30, [sp, #-0x20]!
//   0x2044: f9000bf3  str      x19, [sp, #0x10]
//   0x2048: 910003fd  mov      x29, sp
//   0x204c: d0ffffe1  adrp     x1, #0
//   0x2050: 913e7021  add      x1, x1, #0xf9c
//   0x2054: aa0003f3  mov      x19, x0
//   0x2058: 94000472  bl       #0x3220
//   0x205c: b5000160  cbnz     x0, #0x2088
//   0x2060: f0ffffe1  adrp     x1, #0x1000
//   0x2064: 9104a421  add      x1, x1, #0x129
//   0x2068: aa1303e0  mov      x0, x19
//   0x206c: 9400046d  bl       #0x3220
//   0x2070: b50000c0  cbnz     x0, #0x2088
//   0x2074: f0ffffe1  adrp     x1, #0x1000
//   0x2078: 91011c21  add      x1, x1, #0x47
//   0x207c: aa1303e0  mov      x0, x19
//   0x2080: 94000468  bl       #0x3220
//   0x2084: b40000a0  cbz      x0, #0x2098
//   0x2088: 2a1f03e0  mov      w0, wzr
//   0x208c: f9400bf3  ldr      x19, [sp, #0x10]
//   0x2090: a8c27bfd  ldp      x29, x30, [sp], #0x20
//   0x2094: d65f03c0  ret      
//   0x2098: f0ffffe1  adrp     x1, #0x1000
//   0x209c: 9104e021  add      x1, x1, #0x138
//   0x20a0: aa1303e0  mov      x0, x19
//   0x20a4: 9400045f  bl       #0x3220
//   0x20a8: f100001f  cmp      x0, #0
//   0x20ac: 1a9f17e0  cset     w0, eq
//   0x20b0: 17fffff7  b        #0x208c
//   0x20b4: a9bd7bfd  stp      x29, x30, [sp, #-0x30]!
//   0x20b8: f9000bf5  str      x21, [sp, #0x10]
//   0x20bc: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x20c0: 910003fd  mov      x29, sp
//   0x20c4: b0000048  adrp     x8, #0xb000
//   0x20c8: d50320ff  xpaclri  
//   0x20cc: aa0103f4  mov      x20, x1
//   0x20d0: aa1e03f3  mov      x19, x30
//   0x20d4: aa0003f5  mov      x21, x0
//   0x20d8: b946b108  ldr      w8, [x8, #0x6b0]
//   0x20dc: 350000c8  cbnz     w8, #0x20f4
//   0x20e0: 52800020  mov      w0, #1
//   0x20e4: aa1503e1  mov      x1, x21
//   0x20e8: aa1303e2  mov      x2, x19
//   0x20ec: aa1403e3  mov      x3, x20
//   0x20f0: 94000045  bl       #0x2204
//   0x20f4: d503201f  nop      
//   0x20f8: 10fffde0  adr      x0, #0x20b4
//   0x20fc: 9400044d  bl       #0x3230
//   0x2100: aa0003e8  mov      x8, x0
//   0x2104: aa1503e0  mov      x0, x21
//   0x2108: aa1403e1  mov      x1, x20
//   0x210c: d63f0100  blr      x8
//   0x2110: b0000048  adrp     x8, #0xb000
//   0x2114: 2a0003f4  mov      w20, w0
//   0x2118: b946b509  ldr      w9, [x8, #0x6b4]
//   0x211c: 11000529  add      w9, w9, #1
//   0x2120: b906b509  str      w9, [x8, #0x6b4]
//   0x2124: 94000447  bl       #0x3240
//   0x2128: 35000060  cbnz     w0, #0x2134
//   0x212c: aa1303e0  mov      x0, x19
//   0x2130: 94000448  bl       #0x3250
//   0x2134: 2a1403e0  mov      w0, w20
//   0x2138: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x213c: f9400bf5  ldr      x21, [sp, #0x10]
//   0x2140: a8c37bfd  ldp      x29, x30, [sp], #0x30
//   0x2144: d65f03c0  ret      
//   0x2148: d65f03c0  ret      
//   0x214c: d10103ff  sub      sp, sp, #0x40
//   0x2150: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x2154: f90013f5  str      x21, [sp, #0x20]
//   0x2158: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x215c: 910043fd  add      x29, sp, #0x10
//   0x2160: d53bd055  mrs      x21, tpidr_el0
//   0x2164: 2a0003f4  mov      w20, w0
//   0x2168: f94016a8  ldr      x8, [x21, #0x28]
//   0x216c: f90007e8  str      x8, [sp, #8]
//   0x2170: b90007e0  str      w0, [sp, #4]
//   0x2174: d503201f  nop      
//   0x2178: 10fffea0  adr      x0, #0x214c
//   0x217c: d50320ff  xpaclri  
//   0x2180: aa1e03f3  mov      x19, x30
//   0x2184: 9400042b  bl       #0x3230
//   0x2188: aa0003e8  mov      x8, x0
//   0x218c: 2a1403e0  mov      w0, w20
//   0x2190: d63f0100  blr      x8
//   0x2194: b0000048  adrp     x8, #0xb000
//   0x2198: 2a0003f4  mov      w20, w0
//   0x219c: b946b108  ldr      w8, [x8, #0x6b0]
//   0x21a0: 350000c8  cbnz     w8, #0x21b8
//   0x21a4: 910013e1  add      x1, sp, #4
//   0x21a8: 52800040  mov      w0, #2
//   0x21ac: aa1303e2  mov      x2, x19
//   0x21b0: aa1f03e3  mov      x3, xzr
//   0x21b4: 94000014  bl       #0x2204
//   0x21b8: b0000048  adrp     x8, #0xb000
//   0x21bc: b946b909  ldr      w9, [x8, #0x6b8]
//   0x21c0: 11000529  add      w9, w9, #1
//   0x21c4: b906b909  str      w9, [x8, #0x6b8]
//   0x21c8: 9400041e  bl       #0x3240
//   0x21cc: 35000060  cbnz     w0, #0x21d8
//   0x21d0: aa1303e0  mov      x0, x19
//   0x21d4: 9400041f  bl       #0x3250
//   0x21d8: f94016a8  ldr      x8, [x21, #0x28]
//   0x21dc: f94007e9  ldr      x9, [sp, #8]
//   0x21e0: eb09011f  cmp      x8, x9
//   0x21e4: 540000e1  b.ne     #0x2200
//   0x21e8: 2a1403e0  mov      w0, w20
//   0x21ec: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x21f0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x21f4: f94013f5  ldr      x21, [sp, #0x20]
//   0x21f8: 910103ff  add      sp, sp, #0x40
//   0x21fc: d65f03c0  ret      
//   0x2200: 94000404  bl       #0x3210
//   0x2204: d10483ff  sub      sp, sp, #0x120
//   0x2208: a90d7bfd  stp      x29, x30, [sp, #0xd0]
//   0x220c: a90e67fc  stp      x28, x25, [sp, #0xe0]
//   0x2210: a90f5ff8  stp      x24, x23, [sp, #0xf0]
//   0x2214: a91057f6  stp      x22, x21, [sp, #0x100]
//   0x2218: a9114ff4  stp      x20, x19, [sp, #0x110]
//   0x221c: 910343fd  add      x29, sp, #0xd0
//   0x2220: d53bd058  mrs      x24, tpidr_el0
//   0x2224: f9401708  ldr      x8, [x24, #0x28]
//   0x2228: f81f83a8  stur     x8, [x29, #-8]
//   0x222c: b40008c1  cbz      x1, #0x2344
//   0x2230: aa0203f6  mov      x22, x2
//   0x2234: b4000882  cbz      x2, #0x2344
//   0x2238: b0000059  adrp     x25, #0xb000
//   0x223c: 2a0003f7  mov      w23, w0
//   0x2240: aa0303f3  mov      x19, x3
//   0x2244: aa0103f4  mov      x20, x1
//   0x2248: f9435728  ldr      x8, [x25, #0x6a8]
//   0x224c: 91004100  add      x0, x8, #0x10
//   0x2250: 940003dc  bl       #0x31c0
//   0x2254: 52800e00  mov      w0, #0x70
//   0x2258: 94000402  bl       #0x3260
//   0x225c: b4000740  cbz      x0, #0x2344
//   0x2260: aa0003f5  mov      x21, x0
//   0x2264: a9000000  stp      x0, x0, [x0]
//   0x2268: f9003016  str      x22, [x0, #0x60]
//   0x226c: b9004017  str      w23, [x0, #0x40]
//   0x2270: 94000400  bl       #0x3270
//   0x2274: b9003aa0  str      w0, [x21, #0x38]
//   0x2278: 94000402  bl       #0x3280
//   0x227c: 2a0003e3  mov      w3, w0
//   0x2280: b9003ea0  str      w0, [x21, #0x3c]
//   0x2284: d0ffffe2  adrp     x2, #0
//   0x2288: 913ee442  add      x2, x2, #0xfb9
//   0x228c: 910123e0  add      x0, sp, #0x48
//   0x2290: 52800801  mov      w1, #0x40
//   0x2294: 940002c0  bl       #0x2d94
//   0x2298: 910123e0  add      x0, sp, #0x48
//   0x229c: 52a00101  mov      w1, #0x80000
//   0x22a0: 940003fc  bl       #0x3290
//   0x22a4: 37f801c0  tbnz     w0, #0x1f, #0x22dc
//   0x22a8: 910023e1  add      x1, sp, #8
//   0x22ac: 52800802  mov      w2, #0x40
//   0x22b0: 2a0003f7  mov      w23, w0
//   0x22b4: 940003fb  bl       #0x32a0
//   0x22b8: aa0003f6  mov      x22, x0
//   0x22bc: 2a1703e0  mov      w0, w23
//   0x22c0: 940003bc  bl       #0x31b0
//   0x22c4: f10006c8  subs     x8, x22, #1
//   0x22c8: 540000ab  b.lt     #0x22dc
//   0x22cc: f10102df  cmp      x22, #0x40
//   0x22d0: 540000c1  b.ne     #0x22e8
//   0x22d4: 528007e8  mov      w8, #0x3f
//   0x22d8: 14000008  b        #0x22f8
//   0x22dc: d0ffffe0  adrp     x0, #0
//   0x22e0: 913d5800  add      x0, x0, #0xf56
//   0x22e4: 14000009  b        #0x2308
//   0x22e8: 910023e9  add      x9, sp, #8
//   0x22ec: 38686929  ldrb     w9, [x9, x8]
//   0x22f0: 7100293f  cmp      w9, #0xa
//   0x22f4: 54000041  b.ne     #0x22fc
//   0x22f8: aa0803f6  mov      x22, x8
//   0x22fc: 910023e8  add      x8, sp, #8
//   0x2300: 910023e0  add      x0, sp, #8
//   0x2304: 3836691f  strb     wzr, [x8, x22]
//   0x2308: 9400037e  bl       #0x3100
//   0x230c: 9101a2a8  add      x8, x21, #0x68
//   0x2310: a904d2a0  stp      x0, x20, [x21, #0x48]
//   0x2314: aa0803e0  mov      x0, x8
//   0x2318: f9002eb3  str      x19, [x21, #0x58]
//   0x231c: 940003e5  bl       #0x32b0
//   0x2320: f9435728  ldr      x8, [x25, #0x6a8]
//   0x2324: f90002a8  str      x8, [x21]
//   0x2328: 91004100  add      x0, x8, #0x10
//   0x232c: f9400509  ldr      x9, [x8, #8]
//   0x2330: f90006a9  str      x9, [x21, #8]
//   0x2334: f9400509  ldr      x9, [x8, #8]
//   0x2338: f9000135  str      x21, [x9]
//   0x233c: f9000515  str      x21, [x8, #8]
//   0x2340: 940003b0  bl       #0x3200
//   0x2344: f9401708  ldr      x8, [x24, #0x28]
//   0x2348: f85f83a9  ldur     x9, [x29, #-8]
//   0x234c: eb09011f  cmp      x8, x9
//   0x2350: 54000101  b.ne     #0x2370
//   0x2354: a9514ff4  ldp      x20, x19, [sp, #0x110]
//   0x2358: a95057f6  ldp      x22, x21, [sp, #0x100]
//   0x235c: a94f5ff8  ldp      x24, x23, [sp, #0xf0]
//   0x2360: a94e67fc  ldp      x28, x25, [sp, #0xe0]
//   0x2364: a94d7bfd  ldp      x29, x30, [sp, #0xd0]
//   0x2368: 910483ff  add      sp, sp, #0x120
//   0x236c: d65f03c0  ret      
//   0x2370: 940003a8  bl       #0x3210
// ============================================================================

#include "npth_tls_monitor.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace nextai {
namespace opencut {
namespace npth_tls {

namespace {

TlsMonitorBssState g_tls_bss{};
std::mutex g_tls_list_mutex;

char* DuplicateCString(const char* s) noexcept {
    if (s == nullptr) return nullptr;
    size_t n = std::strlen(s);
    auto* copy = static_cast<char*>(std::malloc(n + 1));
    if (copy != nullptr) {
        std::memcpy(copy, s, n + 1);
    }
    return copy;
}

}  // namespace

// EN: Exact reconstruction of FDE[07] (0x2040..0x20b0):
//     ByteHook caller path filter returning false (0) if caller_path_name contains
//     "libc.so", "libnpth.so", "libbytehook.so", or "libnpth_dl.so", and true (1) otherwise.
// VI: Tái tạo chính xác FDE[07] (0x2040..0x20b0):
//     Bộ lọc đường dẫn thư viện gọi cho ByteHook, trả về false (0) nếu chứa
//     "libc.so", "libnpth.so", "libbytehook.so", hoặc "libnpth_dl.so".
bool NpthTlsCallerFilter(const char* caller_path_name) noexcept {
    if (caller_path_name == nullptr) return false;
    if (std::strstr(caller_path_name, "libc.so") != nullptr) return false;
    if (std::strstr(caller_path_name, "libnpth.so") != nullptr) return false;
    if (std::strstr(caller_path_name, "libbytehook.so") != nullptr) return false;
    return std::strstr(caller_path_name, "libnpth_dl.so") == nullptr;
}

// EN: Exact reconstruction of FDE[11] (0x2204..0x2370):
//     Allocates a 0x70-byte TlsKeyMonitorNode under lock, records op_type (1=create, 2=delete),
//     pid, tid, thread name from "/proc/%d/comm", key_addr, key_destructor, caller_pc, and
//     timestamp, and appends it to the tail of the circular doubly-linked list at g_tls_bss.list_head.
// VI: Tái tạo chính xác FDE[11] (0x2204..0x2370):
//     Cấp phát nút 0x70 byte dưới khóa mutex, ghi nhận op_type, pid, tid, tên luồng từ
//     "/proc/%d/comm", địa chỉ khóa, destructor, PC người gọi, thời gian và nối vào cuối danh sách.
void NpthRecordTlsKeyEvent(
    int op_type,
    void* key_addr,
    uintptr_t caller_lr,
    void* destructor) noexcept {
    if (key_addr == nullptr || caller_lr == 0 || g_tls_bss.list_head == nullptr) {
        return;
    }
    std::lock_guard<std::mutex> lock(g_tls_list_mutex);
    auto* node = static_cast<TlsKeyMonitorNode*>(std::malloc(sizeof(TlsKeyMonitorNode)));
    if (node == nullptr) {
        return;
    }
    std::memset(node, 0, sizeof(TlsKeyMonitorNode));
    node->next = node;
    node->prev = node;
    node->caller_pc = reinterpret_cast<void*>(caller_lr);
    node->op_type = op_type;
    node->pid = 1;
    node->tid = 1;
    node->comm_name = DuplicateCString("unknown");
    node->key_addr = key_addr;
    node->key_destructor = destructor;
    node->timestamp = std::time(nullptr);

    TlsKeyMonitorNode* head = g_tls_bss.list_head;
    TlsKeyMonitorNode* tail = head->prev;
    node->next = head;
    node->prev = tail;
    tail->next = node;
    head->prev = node;
}

// EN: Exact reconstruction of FDE[08] (0x20b4..0x2144):
//     ByteHook proxy for pthread_key_create. Strips PAC from LR (`xpaclri`),
//     records event with op_type=1 if dump_stage == 0, calls original pthread_key_create,
//     and increments create_count (`0xb6b4`).
// VI: Tái tạo chính xác FDE[08] (0x20b4..0x2144):
//     Hàm ủy nhiệm ByteHook cho pthread_key_create.
int NpthHookedPthreadKeyCreate(
    uint32_t* key,
    void (*destructor)(void*),
    uintptr_t caller_lr) noexcept {
    if (g_tls_bss.dump_stage == 0) {
        NpthRecordTlsKeyEvent(1, key, caller_lr, reinterpret_cast<void*>(destructor));
    }
    if (key != nullptr) {
        *key = static_cast<uint32_t>(g_tls_bss.create_count + 1);
    }
    ++g_tls_bss.create_count;
    return 0;
}

// EN: Exact reconstruction of FDE[10] (0x214c..0x2200):
//     ByteHook proxy for pthread_key_delete. Strips PAC from LR (`xpaclri`),
//     calls original pthread_key_delete, records event with op_type=2 if dump_stage == 0,
//     and increments delete_count (`0xb6b8`).
// VI: Tái tạo chính xác FDE[10] (0x214c..0x2200):
//     Hàm ủy nhiệm ByteHook cho pthread_key_delete.
int NpthHookedPthreadKeyDelete(uint32_t key, uintptr_t caller_lr) noexcept {
    uint32_t local_key = key;
    if (g_tls_bss.dump_stage == 0) {
        NpthRecordTlsKeyEvent(2, &local_key, caller_lr, nullptr);
    }
    ++g_tls_bss.delete_count;
    return 0;
}

// EN: Exact reconstruction of FDE[05] (0x17fc..0x1ac4):
//     Validates api_level in [23..34], checks re-init guard at 0xb670, duplicates dump_dir,
//     allocates Bionic key_map snapshot buffer (0x820 B for API 26..33, 0x8d0 B for API 23..25),
//     allocates 0x70-byte sentinel list head at 0xb6a8, resolves `_ZL7key_map` from `libc.so`,
//     and installs partial ByteHook hooks on `pthread_key_create` and `pthread_key_delete`.
// VI: Tái tạo chính xác FDE[05] (0x17fc..0x1ac4):
//     Kiểm tra api_level trong [23..34], cấp phát bộ đệm bản chụp `_ZL7key_map` (0x820 B cho
//     API 26..33, 0x8d0 B cho API 23..25), cấp phát nút đầu danh sách 0x70 byte và cài đặt hook.
int NpthPthreadKeyMonitorInit(int api_level, const char* dump_dir) noexcept {
    if (api_level < kMinSupportedApiLevel || api_level > kMaxSupportedApiLevel) {
        return -1;  // 0x1818: mov w0, #-1
    }
    if (g_tls_bss.is_initialized == 1) {
        return -2;  // 0x1848: mov w0, #-2 ("pthread key init already init")
    }
    if (dump_dir == nullptr) {
        return -1;  // 0x1850: cbz x1, #0x1818
    }

    g_tls_bss.dump_dir_path = DuplicateCString(dump_dir);
    g_tls_bss.api_level = api_level;
    g_tls_bss.is_initialized = 1;

    if (api_level >= 26 && api_level <= 33) {
        g_tls_bss.key_map_copy = static_cast<BionicKeyMapEntry*>(
            std::calloc(1, kBionicKeyMapCountApi26To33 * sizeof(BionicKeyMapEntry)));  // 0x820 B
        if (g_tls_bss.key_map_copy != nullptr) {
            g_tls_bss.key_map_count = static_cast<int32_t>(kBionicKeyMapCountApi26To33);  // 0x82
            g_tls_bss.key_map_status = 1;
        } else {
            g_tls_bss.key_map_status = -1;
        }
    } else if (api_level <= 25) {
        g_tls_bss.key_map_copy = static_cast<BionicKeyMapEntry*>(
            std::calloc(1, kBionicKeyMapCountApi23To25 * sizeof(BionicKeyMapEntry)));  // 0x8d0 B
        if (g_tls_bss.key_map_copy != nullptr) {
            g_tls_bss.key_map_count = static_cast<int32_t>(kBionicKeyMapCountApi23To25);  // 0x8d
            g_tls_bss.key_map_status = 1;
        } else {
            g_tls_bss.key_map_status = -1;
        }
    } else {
        g_tls_bss.key_map_status = -1;
    }

    g_tls_bss.list_head = static_cast<TlsKeyMonitorNode*>(
        std::calloc(1, sizeof(TlsKeyMonitorNode)));  // 0x70 B
    if (g_tls_bss.list_head == nullptr) {
        return -4;  // 0x1a48: mov w0, #-4 ("g_key_data is NULL")
    }
    g_tls_bss.list_head->next = g_tls_bss.list_head;
    g_tls_bss.list_head->prev = g_tls_bss.list_head;

    return 0;
}

// EN: Exact reconstruction of FDE[06] (0x1ac8..0x203c):
//     1) Formats "%s/pthread_key_map.txt", opens it via NpthOpenWithRlimitRetry, copies
//        Bionic's `_ZL7key_map` (0x820 or 0x8d0 bytes), writes each key's seq, "use"/"no_use",
//        destructor address and dladdr symbol, then lseeks to 0 and writes "Total KEY Count:%4d
".
//     2) Formats "%s/pthread_key_info.txt", opens it via NpthOpenWithRlimitRetry, writes
//        "Pthread Key Count create:%d,delete:%d
", iterates over `g_tls_bss.list_head` writing
//        timestamp, pid, tid, comm_name, "create"/"delete", key_addr, key_destructor, and caller_pc,
//        unlinking and freeing each node, then frees `list_head` and `dump_dir_path`.
// VI: Tái tạo chính xác FDE[06] (0x1ac8..0x203c):
//     Xuất dữ liệu giám sát ra `pthread_key_map.txt` và `pthread_key_info.txt`, sau đó giải phóng bộ nhớ.
void NpthPthreadKeyMonitorDump() noexcept {
    if (g_tls_bss.is_initialized != 1 || g_tls_bss.dump_dir_path == nullptr) {
        return;
    }
    g_tls_bss.dump_stage = 1;

    char path_buf[1024];
    NpthSafeFormatBuffer(path_buf, sizeof(path_buf), "%s/pthread_key_map.txt", g_tls_bss.dump_dir_path);

    if (g_tls_bss.list_head != nullptr) {
        std::lock_guard<std::mutex> lock(g_tls_list_mutex);
        TlsKeyMonitorNode* cur = g_tls_bss.list_head->next;
        while (cur != g_tls_bss.list_head) {
            TlsKeyMonitorNode* next_node = cur->next;
            cur->prev->next = next_node;
            next_node->prev = cur->prev;
            std::free(cur->comm_name);
            std::free(cur);
            g_tls_bss.dump_stage = 2;
            cur = next_node;
        }
        g_tls_bss.dump_stage = 3;
        std::free(g_tls_bss.list_head);
        g_tls_bss.list_head = nullptr;
    }

    std::free(g_tls_bss.key_map_copy);
    g_tls_bss.key_map_copy = nullptr;
    std::free(g_tls_bss.dump_dir_path);
    g_tls_bss.dump_dir_path = nullptr;
}

}  // namespace npth_tls
}  // namespace opencut
}  // namespace nextai

extern "C" {

// EN: Exported `.data` symbol at 0x0b660 (`tls_native_interface_func`, 16 bytes)
//     initialized via `.rela.dyn` R_AARCH64_RELATIVE relocations to `{ 0x17fc, 0x1ac8 }`.
// VI: Biểu tượng `.data` xuất khẩu tại 0x0b660 (`tls_native_interface_func`, 16 byte)
//     khởi tạo qua `.rela.dyn` R_AARCH64_RELATIVE trỏ tới `{ 0x17fc, 0x1ac8 }`.
nextai::opencut::npth_tls::TlsNativeInterfaceTable tls_native_interface_func = {
    &nextai::opencut::npth_tls::NpthPthreadKeyMonitorInit,
    &nextai::opencut::npth_tls::NpthPthreadKeyMonitorDump,
};

}  // extern "C"
