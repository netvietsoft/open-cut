// ============================================================================
// NextAI OpenCut — Clean-Room C++17 Reconstruction
// File          : komprese_decompressor.cpp
// Target Binary : libkomprese-decompressor.so (15,800 bytes)
// SHA-256       : 7a2a91ead53359dafebaae790ec6e5807f0e037c4c73b8ec0a3a49af1c1a18c3
// Task ID       : TASK-167-RECONSTRUCTION-LIBKOMPRESE-DECOMPRESSOR
// Functions     : FDE[00..04] CRT stubs (0x0a64..0x0ab4),
//                 FDE[05] KompreseInitGlobalTables (0x0ab8..0x0e98),
//                 FDE[06] komprese_decompress (0x0e9c..0x1818)
// ============================================================================
// EN: Exact clean-room C++17 implementation of the exported komprese_decompress
//     entry point (0x0e9c..0x1818) and the .init_array constructor (0x0ab8..0x0e98).
// VI: Bản cài đặt C++17 phòng sạch chính xác của hàm xuất khẩu komprese_decompress
//     (0x0e9c..0x1818) và hàm khởi tạo .init_array (0x0ab8..0x0e98).
// ============================================================================
// Complete AArch64 Disassembly Trace for 0x0a64..0x1818 (878 instructions):
//   0x0a64: d503245f  bti      c
//   0x0a68: f0000020  adrp     x0, #0x7000
//   0x0a6c: 910d8000  add      x0, x0, #0x360
//   0x0a70: 14000a14  b        #0x32c0
//   0x0a74: d503245f  bti      c
//   0x0a78: d65f03c0  ret      
//   0x0a7c: d503245f  bti      c
//   0x0a80: 17fffffd  b        #0xa74
//   0x0a84: d503245f  bti      c
//   0x0a88: b4000060  cbz      x0, #0xa94
//   0x0a8c: aa0003f0  mov      x16, x0
//   0x0a90: d61f0200  br       x16
//   0x0a94: d65f03c0  ret      
//   0x0a98: d503245f  bti      c
//   0x0a9c: 90000008  adrp     x8, #0
//   0x0aa0: 912a1108  add      x8, x8, #0xa84
//   0x0aa4: f0000022  adrp     x2, #0x7000
//   0x0aa8: 910d8042  add      x2, x2, #0x360
//   0x0aac: aa0003e1  mov      x1, x0
//   0x0ab0: aa0803e0  mov      x0, x8
//   0x0ab4: 14000a07  b        #0x32d0
//   0x0ab8: a9be7bfd  stp      x29, x30, [sp, #-0x20]!
//   0x0abc: f9000bf3  str      x19, [sp, #0x10]
//   0x0ac0: 910003fd  mov      x29, sp
//   0x0ac4: 9000000a  adrp     x10, #0
//   0x0ac8: 3dc1cd42  ldr      q2, [x10, #0x730]
//   0x0acc: 5290640a  mov      w10, #0x8320
//   0x0ad0: 72bdb70a  movk     w10, #0xedb8, lsl #16
//   0x0ad4: 0e040d43  dup      v3.2s, w10
//   0x0ad8: 5280002a  mov      w10, #1
//   0x0adc: 4e080d44  dup      v4.2d, x10
//   0x0ae0: d281e84a  mov      x10, #0xf42
//   0x0ae4: 90000009  adrp     x9, #0
//   0x0ae8: f2baf0ea  movk     x10, #0xd787, lsl #16
//   0x0aec: fd437120  ldr      d0, [x9, #0x6e0]
//   0x0af0: f2caf2aa  movk     x10, #0x5795, lsl #32
//   0x0af4: f2f92d8a  movk     x10, #0xc96c, lsl #48
//   0x0af8: f00000c9  adrp     x9, #0x1b000
//   0x0afc: 4e080d45  dup      v5.2d, x10
//   0x0b00: 5280004a  mov      w10, #2
//   0x0b04: f00000d3  adrp     x19, #0x1b000
//   0x0b08: aa1f03e8  mov      x8, xzr
//   0x0b0c: 91276129  add      x9, x9, #0x9d8
//   0x0b10: 0f000421  movi     v1.2s, #1
//   0x0b14: 4e080d46  dup      v6.2d, x10
//   0x0b18: 9116e273  add      x19, x19, #0x5b8
//   0x0b1c: 0f000447  movi     v7.2s, #2
//   0x0b20: 0e211c10  and      v16.8b, v0.8b, v1.8b
//   0x0b24: 2f3f0411  ushr     v17.2s, v0.2s, #1
//   0x0b28: 0ea09a10  cmeq     v16.2s, v16.2s, #0
//   0x0b2c: 2e231e33  eor      v19.8b, v17.8b, v3.8b
//   0x0b30: 4e241c52  and      v18.16b, v2.16b, v4.16b
//   0x0b34: 2e731e30  bsl      v16.8b, v17.8b, v19.8b
//   0x0b38: 6f7f0451  ushr     v17.2d, v2.2d, #1
//   0x0b3c: 4ee09a52  cmeq     v18.2d, v18.2d, #0
//   0x0b40: 6e251e33  eor      v19.16b, v17.16b, v5.16b
//   0x0b44: 6ef21e71  bif      v17.16b, v19.16b, v18.16b
//   0x0b48: 0e211e12  and      v18.8b, v16.8b, v1.8b
//   0x0b4c: 2f3f0610  ushr     v16.2s, v16.2s, #1
//   0x0b50: 0ea09a52  cmeq     v18.2s, v18.2s, #0
//   0x0b54: 2e231e13  eor      v19.8b, v16.8b, v3.8b
//   0x0b58: 2ef21e70  bif      v16.8b, v19.8b, v18.8b
//   0x0b5c: 4e241e32  and      v18.16b, v17.16b, v4.16b
//   0x0b60: 6f7f0631  ushr     v17.2d, v17.2d, #1
//   0x0b64: 4ee09a52  cmeq     v18.2d, v18.2d, #0
//   0x0b68: 6e251e33  eor      v19.16b, v17.16b, v5.16b
//   0x0b6c: 6ef21e71  bif      v17.16b, v19.16b, v18.16b
//   0x0b70: 0e211e12  and      v18.8b, v16.8b, v1.8b
//   0x0b74: 2f3f0610  ushr     v16.2s, v16.2s, #1
//   0x0b78: 0ea09a52  cmeq     v18.2s, v18.2s, #0
//   0x0b7c: 2e231e13  eor      v19.8b, v16.8b, v3.8b
//   0x0b80: 2ef21e70  bif      v16.8b, v19.8b, v18.8b
//   0x0b84: 4e241e32  and      v18.16b, v17.16b, v4.16b
//   0x0b88: 6f7f0631  ushr     v17.2d, v17.2d, #1
//   0x0b8c: 4ee09a52  cmeq     v18.2d, v18.2d, #0
//   0x0b90: 6e251e33  eor      v19.16b, v17.16b, v5.16b
//   0x0b94: 6ef21e71  bif      v17.16b, v19.16b, v18.16b
//   0x0b98: 0e211e12  and      v18.8b, v16.8b, v1.8b
//   0x0b9c: 2f3f0610  ushr     v16.2s, v16.2s, #1
//   0x0ba0: 0ea09a52  cmeq     v18.2s, v18.2s, #0
//   0x0ba4: 2e231e13  eor      v19.8b, v16.8b, v3.8b
//   0x0ba8: 2ef21e70  bif      v16.8b, v19.8b, v18.8b
//   0x0bac: 4e241e32  and      v18.16b, v17.16b, v4.16b
//   0x0bb0: 6f7f0631  ushr     v17.2d, v17.2d, #1
//   0x0bb4: 4ee09a52  cmeq     v18.2d, v18.2d, #0
//   0x0bb8: 6e251e33  eor      v19.16b, v17.16b, v5.16b
//   0x0bbc: 6ef21e71  bif      v17.16b, v19.16b, v18.16b
//   0x0bc0: 0e211e12  and      v18.8b, v16.8b, v1.8b
//   0x0bc4: 2f3f0610  ushr     v16.2s, v16.2s, #1
//   0x0bc8: 0ea09a52  cmeq     v18.2s, v18.2s, #0
//   0x0bcc: 2e231e13  eor      v19.8b, v16.8b, v3.8b
//   0x0bd0: 2ef21e70  bif      v16.8b, v19.8b, v18.8b
//   0x0bd4: 4e241e32  and      v18.16b, v17.16b, v4.16b
//   0x0bd8: 6f7f0631  ushr     v17.2d, v17.2d, #1
//   0x0bdc: 4ee09a52  cmeq     v18.2d, v18.2d, #0
//   0x0be0: 6e251e33  eor      v19.16b, v17.16b, v5.16b
//   0x0be4: 6ef21e71  bif      v17.16b, v19.16b, v18.16b
//   0x0be8: 0e211e12  and      v18.8b, v16.8b, v1.8b
//   0x0bec: 2f3f0610  ushr     v16.2s, v16.2s, #1
//   0x0bf0: 0ea09a52  cmeq     v18.2s, v18.2s, #0
//   0x0bf4: 2e231e13  eor      v19.8b, v16.8b, v3.8b
//   0x0bf8: 2ef21e70  bif      v16.8b, v19.8b, v18.8b
//   0x0bfc: 4e241e32  and      v18.16b, v17.16b, v4.16b
//   0x0c00: 6f7f0631  ushr     v17.2d, v17.2d, #1
//   0x0c04: 4ee09a52  cmeq     v18.2d, v18.2d, #0
//   0x0c08: 6e251e33  eor      v19.16b, v17.16b, v5.16b
//   0x0c0c: 6ef21e71  bif      v17.16b, v19.16b, v18.16b
//   0x0c10: 0e211e12  and      v18.8b, v16.8b, v1.8b
//   0x0c14: 2f3f0610  ushr     v16.2s, v16.2s, #1
//   0x0c18: 0ea09a52  cmeq     v18.2s, v18.2s, #0
//   0x0c1c: 2e231e13  eor      v19.8b, v16.8b, v3.8b
//   0x0c20: 2ef21e70  bif      v16.8b, v19.8b, v18.8b
//   0x0c24: 4e241e32  and      v18.16b, v17.16b, v4.16b
//   0x0c28: 6f7f0631  ushr     v17.2d, v17.2d, #1
//   0x0c2c: 4ee09a52  cmeq     v18.2d, v18.2d, #0
//   0x0c30: 6e251e33  eor      v19.16b, v17.16b, v5.16b
//   0x0c34: 6ef21e71  bif      v17.16b, v19.16b, v18.16b
//   0x0c38: 0e211e12  and      v18.8b, v16.8b, v1.8b
//   0x0c3c: 2f3f0610  ushr     v16.2s, v16.2s, #1
//   0x0c40: 0ea09a52  cmeq     v18.2s, v18.2s, #0
//   0x0c44: 2e231e13  eor      v19.8b, v16.8b, v3.8b
//   0x0c48: 2ef21e70  bif      v16.8b, v19.8b, v18.8b
//   0x0c4c: 4e241e32  and      v18.16b, v17.16b, v4.16b
//   0x0c50: 6f7f0631  ushr     v17.2d, v17.2d, #1
//   0x0c54: 4ee09a52  cmeq     v18.2d, v18.2d, #0
//   0x0c58: 6e251e33  eor      v19.16b, v17.16b, v5.16b
//   0x0c5c: 8b08026a  add      x10, x19, x8
//   0x0c60: 91002108  add      x8, x8, #8
//   0x0c64: 6ef21e71  bif      v17.16b, v19.16b, v18.16b
//   0x0c68: 4ee68442  add      v2.2d, v2.2d, v6.2d
//   0x0c6c: f110011f  cmp      x8, #0x400
//   0x0c70: fd001150  str      d16, [x10, #0x20]
//   0x0c74: 3c810531  str      q17, [x9], #0x10
//   0x0c78: 0ea78400  add      v0.2s, v0.2s, v7.2s
//   0x0c7c: 54fff521  b.ne     #0xb20
//   0x0c80: 52800200  mov      w0, #0x10
//   0x0c84: 52804001  mov      w1, #0x200
//   0x0c88: 94000996  bl       #0x32e0
//   0x0c8c: f9000260  str      x0, [x19]
//   0x0c90: 52800200  mov      w0, #0x10
//   0x0c94: 52801001  mov      w1, #0x80
//   0x0c98: 94000992  bl       #0x32e0
//   0x0c9c: f9000660  str      x0, [x19, #8]
//   0x0ca0: 52800200  mov      w0, #0x10
//   0x0ca4: 52800401  mov      w1, #0x20
//   0x0ca8: 9400098e  bl       #0x32e0
//   0x0cac: f9000a60  str      x0, [x19, #0x10]
//   0x0cb0: 52800200  mov      w0, #0x10
//   0x0cb4: 52800101  mov      w1, #8
//   0x0cb8: 9400098a  bl       #0x32e0
//   0x0cbc: f9400268  ldr      x8, [x19]
//   0x0cc0: aa1f03ed  mov      x13, xzr
//   0x0cc4: 52800029  mov      w9, #1
//   0x0cc8: 5287f1ea  mov      w10, #0x3f8f
//   0x0ccc: 9000000b  adrp     x11, #0
//   0x0cd0: 9100090c  add      x12, x8, #2
//   0x0cd4: 4f008500  movi     v0.8h, #8
//   0x0cd8: f9000e60  str      x0, [x19, #0x18]
//   0x0cdc: 14000007  b        #0xcf8
//   0x0ce0: 91000529  add      x9, x9, #1
//   0x0ce4: 91008108  add      x8, x8, #0x20
//   0x0ce8: f10041df  cmp      x14, #0x10
//   0x0cec: 9100898c  add      x12, x12, #0x22
//   0x0cf0: aa0e03ed  mov      x13, x14
//   0x0cf4: 54000420  b.eq     #0xd78
//   0x0cf8: f10019bf  cmp      x13, #6
//   0x0cfc: 910005ae  add      x14, x13, #1
//   0x0d00: 54000068  b.hi     #0xd0c
//   0x0d04: aa1f03ef  mov      x15, xzr
//   0x0d08: 1400000c  b        #0xd38
//   0x0d0c: 3dc1c961  ldr      q1, [x11, #0x720]
//   0x0d10: 927df130  and      x16, x9, #0xfffffffffffffff8
//   0x0d14: 927dedcf  and      x15, x14, #0x7ffffffffffffff8
//   0x0d18: aa0803f1  mov      x17, x8
//   0x0d1c: 4f145422  shl      v2.8h, v1.8h, #4
//   0x0d20: f1002210  subs     x16, x16, #8
//   0x0d24: 3c810622  str      q2, [x17], #0x10
//   0x0d28: 4e608421  add      v1.8h, v1.8h, v0.8h
//   0x0d2c: 54ffff81  b.ne     #0xd1c
//   0x0d30: eb0f01df  cmp      x14, x15
//   0x0d34: 540000c0  b.eq     #0xd4c
//   0x0d38: 531c6df0  lsl      w16, w15, #4
//   0x0d3c: 782f7910  strh     w16, [x8, x15, lsl #1]
//   0x0d40: 910005ef  add      x15, x15, #1
//   0x0d44: eb0f013f  cmp      x9, x15
//   0x0d48: 54ffff81  b.ne     #0xd38
//   0x0d4c: f10039bf  cmp      x13, #0xe
//   0x0d50: 54fffc88  b.hi     #0xce0
//   0x0d54: aa1f03ef  mov      x15, xzr
//   0x0d58: 0b0f01b0  add      w16, w13, w15
//   0x0d5c: 0b101150  add      w16, w10, w16, lsl #4
//   0x0d60: 782f7990  strh     w16, [x12, x15, lsl #1]
//   0x0d64: 910005ef  add      x15, x15, #1
//   0x0d68: 8b0f01b0  add      x16, x13, x15
//   0x0d6c: f1003e1f  cmp      x16, #0xf
//   0x0d70: 54ffff41  b.ne     #0xd58
//   0x0d74: 17ffffdb  b        #0xce0
//   0x0d78: f00000c8  adrp     x8, #0x1b000
//   0x0d7c: 91170108  add      x8, x8, #0x5c0
//   0x0d80: 90000009  adrp     x9, #0
//   0x0d84: 9000000a  adrp     x10, #0
//   0x0d88: 3dc1e920  ldr      q0, [x9, #0x7a0]
//   0x0d8c: f9400109  ldr      x9, [x8]
//   0x0d90: 3dc1fd41  ldr      q1, [x10, #0x7f0]
//   0x0d94: 9000000a  adrp     x10, #0
//   0x0d98: fd437942  ldr      d2, [x10, #0x6f0]
//   0x0d9c: 9000000a  adrp     x10, #0
//   0x0da0: 3d800120  str      q0, [x9]
//   0x0da4: fd438940  ldr      d0, [x10, #0x710]
//   0x0da8: 9000000a  adrp     x10, #0
//   0x0dac: 3c814121  stur     q1, [x9, #0x14]
//   0x0db0: fd438141  ldr      d1, [x10, #0x700]
//   0x0db4: 9000000a  adrp     x10, #0
//   0x0db8: fc024122  stur     d2, [x9, #0x24]
//   0x0dbc: 3dc20542  ldr      q2, [x10, #0x810]
//   0x0dc0: 9000000a  adrp     x10, #0
//   0x0dc4: 6d030520  stp      d0, d1, [x9, #0x30]
//   0x0dc8: 3dc1d141  ldr      q1, [x10, #0x740]
//   0x0dcc: 9000000a  adrp     x10, #0
//   0x0dd0: 3d801122  str      q2, [x9, #0x40]
//   0x0dd4: 3dc1e542  ldr      q2, [x10, #0x790]
//   0x0dd8: 9000000a  adrp     x10, #0
//   0x0ddc: fd002920  str      d0, [x9, #0x50]
//   0x0de0: fd438540  ldr      d0, [x10, #0x708]
//   0x0de4: 52a0010a  mov      w10, #0x80000
//   0x0de8: b900112a  str      w10, [x9, #0x10]
//   0x0dec: 52880dea  mov      w10, #0x406f
//   0x0df0: 72a80eea  movk     w10, #0x4077, lsl #16
//   0x0df4: b9002d2a  str      w10, [x9, #0x2c]
//   0x0df8: d280040a  mov      x10, #0x20
//   0x0dfc: f2a0050a  movk     x10, #0x28, lsl #16
//   0x0e00: f2c80dea  movk     x10, #0x406f, lsl #32
//   0x0e04: f2e80eea  movk     x10, #0x4077, lsl #48
//   0x0e08: f9002d2a  str      x10, [x9, #0x58]
//   0x0e0c: ad030921  stp      q1, q2, [x9, #0x60]
//   0x0e10: f9400509  ldr      x9, [x8, #8]
//   0x0e14: 90000008  adrp     x8, #0
//   0x0e18: fd437501  ldr      d1, [x8, #0x6e8]
//   0x0e1c: 90000008  adrp     x8, #0
//   0x0e20: fd000120  str      d0, [x9]
//   0x0e24: fd437d00  ldr      d0, [x8, #0x6f8]
//   0x0e28: d2a0008a  mov      x10, #0x40000
//   0x0e2c: f2c80eea  movk     x10, #0x4077, lsl #32
//   0x0e30: f2e80f6a  movk     x10, #0x407b, lsl #48
//   0x0e34: d2a80fab  mov      x11, #0x407d0000
//   0x0e38: f2e0004b  movk     x11, #2, lsl #48
//   0x0e3c: f900052a  str      x10, [x9, #8]
//   0x0e40: 6d010121  stp      d1, d0, [x9, #0x10]
//   0x0e44: f0000049  adrp     x9, #0xb000
//   0x0e48: 52800048  mov      w8, #2
//   0x0e4c: 52800bea  mov      w10, #0x5f
//   0x0e50: f900000b  str      x11, [x0]
//   0x0e54: 5280002b  mov      w11, #1
//   0x0e58: 9116e129  add      x9, x9, #0x5b8
//   0x0e5c: d100050c  sub      x12, x8, #1
//   0x0e60: dac0118c  clz      x12, x12
//   0x0e64: cb0c014c  sub      x12, x10, x12
//   0x0e68: 9acc216c  lsl      x12, x11, x12
//   0x0e6c: 8b0c010c  add      x12, x8, x12
//   0x0e70: d100058c  sub      x12, x12, #1
//   0x0e74: 9ac8098c  udiv     x12, x12, x8
//   0x0e78: b828792c  str      w12, [x9, x8, lsl #2]
//   0x0e7c: 91000508  add      x8, x8, #1
//   0x0e80: f140111f  cmp      x8, #4, lsl #12
//   0x0e84: 54fffec1  b.ne     #0xe5c
//   0x0e88: b9400928  ldr      w8, [x9, #8]
//   0x0e8c: f9400bf3  ldr      x19, [sp, #0x10]
//   0x0e90: 2900213f  stp      wzr, w8, [x9]
//   0x0e94: a8c27bfd  ldp      x29, x30, [sp], #0x20
//   0x0e98: d65f03c0  ret      
//   0x0e9c: d10203ff  sub      sp, sp, #0x80
//   0x0ea0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0ea4: a9036ffc  stp      x28, x27, [sp, #0x30]
//   0x0ea8: a90467fa  stp      x26, x25, [sp, #0x40]
//   0x0eac: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x0eb0: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x0eb4: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x0eb8: 910083fd  add      x29, sp, #0x20
//   0x0ebc: d53bd059  mrs      x25, tpidr_el0
//   0x0ec0: f9401728  ldr      x8, [x25, #0x28]
//   0x0ec4: aa0303f5  mov      x21, x3
//   0x0ec8: f100343f  cmp      x1, #0xd
//   0x0ecc: f81f83a8  stur     x8, [x29, #-8]
//   0x0ed0: 540000c2  b.hs     #0xee8
//   0x0ed4: aa1f03e8  mov      x8, xzr
//   0x0ed8: 394033e9  ldrb     w9, [sp, #0xc]
//   0x0edc: 7100053f  cmp      w9, #1
//   0x0ee0: 54000681  b.ne     #0xfb0
//   0x0ee4: 1400000d  b        #0xf18
//   0x0ee8: f9400009  ldr      x9, [x0]
//   0x0eec: b9400808  ldr      w8, [x0, #8]
//   0x0ef0: 52896fea  mov      w10, #0x4b7f
//   0x0ef4: 72a9a9ea  movk     w10, #0x4d4f, lsl #16
//   0x0ef8: 6b0a013f  cmp      w9, w10
//   0x0efc: b90013e8  str      w8, [sp, #0x10]
//   0x0f00: f90007e9  str      x9, [sp, #8]
//   0x0f04: 54000561  b.ne     #0xfb0
//   0x0f08: 52800188  mov      w8, #0xc
//   0x0f0c: 394033e9  ldrb     w9, [sp, #0xc]
//   0x0f10: 7100053f  cmp      w9, #1
//   0x0f14: 540004e1  b.ne     #0xfb0
//   0x0f18: f00000c9  adrp     x9, #0x1b000
//   0x0f1c: 91176129  add      x9, x9, #0x5d8
//   0x0f20: b943f92a  ldr      w10, [x9, #0x3f8]
//   0x0f24: 394037eb  ldrb     w11, [sp, #0xd]
//   0x0f28: 52005d4a  eor      w10, w10, #0xffffff
//   0x0f2c: 12001d4c  and      w12, w10, #0xff
//   0x0f30: 4a0b018b  eor      w11, w12, w11
//   0x0f34: b86b592b  ldr      w11, [x9, w11, uxtw #2]
//   0x0f38: 39403bec  ldrb     w12, [sp, #0xe]
//   0x0f3c: 4a4a216a  eor      w10, w11, w10, lsr #8
//   0x0f40: 12001d4b  and      w11, w10, #0xff
//   0x0f44: 4a0c016b  eor      w11, w11, w12
//   0x0f48: b86b592b  ldr      w11, [x9, w11, uxtw #2]
//   0x0f4c: 39403fec  ldrb     w12, [sp, #0xf]
//   0x0f50: 4a4a216a  eor      w10, w11, w10, lsr #8
//   0x0f54: 12001d4b  and      w11, w10, #0xff
//   0x0f58: 4a0c016b  eor      w11, w11, w12
//   0x0f5c: b86b5929  ldr      w9, [x9, w11, uxtw #2]
//   0x0f60: b94013eb  ldr      w11, [sp, #0x10]
//   0x0f64: 4a6a2129  eon      w9, w9, w10, lsr #8
//   0x0f68: 6b09017f  cmp      w11, w9
//   0x0f6c: 54000221  b.ne     #0xfb0
//   0x0f70: 8b080017  add      x23, x0, x8
//   0x0f74: 52800400  mov      w0, #0x20
//   0x0f78: f90003e2  str      x2, [sp]
//   0x0f7c: cb080038  sub      x24, x1, x8
//   0x0f80: 940008dc  bl       #0x32f0
//   0x0f84: aa0003f4  mov      x20, x0
//   0x0f88: b4000300  cbz      x0, #0xfe8
//   0x0f8c: b4000318  cbz      x24, #0xfec
//   0x0f90: 394002ea  ldrb     w10, [x23]
//   0x0f94: f100271f  cmp      x24, #9
//   0x0f98: 52800128  mov      w8, #9
//   0x0f9c: 9a883308  csel     x8, x24, x8, lo
//   0x0fa0: 92401949  and      x9, x10, #0x7f
//   0x0fa4: 3738028a  tbnz     w10, #7, #0xff4
//   0x0fa8: 52800028  mov      w8, #1
//   0x0fac: 14000022  b        #0x1034
//   0x0fb0: 92800193  mov      x19, #-0xd
//   0x0fb4: f9401728  ldr      x8, [x25, #0x28]
//   0x0fb8: f85f83a9  ldur     x9, [x29, #-8]
//   0x0fbc: eb09011f  cmp      x8, x9
//   0x0fc0: 540042c1  b.ne     #0x1818
//   0x0fc4: aa1303e0  mov      x0, x19
//   0x0fc8: a9474ff4  ldp      x20, x19, [sp, #0x70]
//   0x0fcc: a94657f6  ldp      x22, x21, [sp, #0x60]
//   0x0fd0: a9455ff8  ldp      x24, x23, [sp, #0x50]
//   0x0fd4: a94467fa  ldp      x26, x25, [sp, #0x40]
//   0x0fd8: a9436ffc  ldp      x28, x27, [sp, #0x30]
//   0x0fdc: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x0fe0: 910203ff  add      sp, sp, #0x80
//   0x0fe4: d65f03c0  ret      
//   0x0fe8: 140001cb  b        #0x1714
//   0x0fec: aa1f03e8  mov      x8, xzr
//   0x0ff0: 14000011  b        #0x1034
//   0x0ff4: f100051f  cmp      x8, #1
//   0x0ff8: 9a9f850a  csinc    x10, x8, xzr, hi
//   0x0ffc: 52800028  mov      w8, #1
//   0x1000: eb0a011f  cmp      x8, x10
//   0x1004: 54000160  b.eq     #0x1030
//   0x1008: 38686aeb  ldrb     w11, [x23, x8]
//   0x100c: b400012b  cbz      x11, #0x1030
//   0x1010: d37df10d  lsl      x13, x8, #3
//   0x1014: 9240196c  and      x12, x11, #0x7f
//   0x1018: cb0801ad  sub      x13, x13, x8
//   0x101c: 9acd218c  lsl      x12, x12, x13
//   0x1020: aa090189  orr      x9, x12, x9
//   0x1024: 91000508  add      x8, x8, #1
//   0x1028: 373ffecb  tbnz     w11, #7, #0x1000
//   0x102c: 14000002  b        #0x1034
//   0x1030: aa1f03e8  mov      x8, xzr
//   0x1034: eb08030a  subs     x10, x24, x8
//   0x1038: f9000a89  str      x9, [x20, #0x10]
//   0x103c: 54000140  b.eq     #0x1064
//   0x1040: 8b0802eb  add      x11, x23, x8
//   0x1044: 3940016c  ldrb     w12, [x11]
//   0x1048: f100255f  cmp      x10, #9
//   0x104c: 52800129  mov      w9, #9
//   0x1050: 9a89314a  csel     x10, x10, x9, lo
//   0x1054: 92401989  and      x9, x12, #0x7f
//   0x1058: 3738008c  tbnz     w12, #7, #0x1068
//   0x105c: 5280002a  mov      w10, #1
//   0x1060: 14000012  b        #0x10a8
//   0x1064: 14000011  b        #0x10a8
//   0x1068: f100055f  cmp      x10, #1
//   0x106c: 9a9f854c  csinc    x12, x10, xzr, hi
//   0x1070: 5280002a  mov      w10, #1
//   0x1074: eb0c015f  cmp      x10, x12
//   0x1078: 54000160  b.eq     #0x10a4
//   0x107c: 386a696d  ldrb     w13, [x11, x10]
//   0x1080: b400012d  cbz      x13, #0x10a4
//   0x1084: d37df14f  lsl      x15, x10, #3
//   0x1088: 924019ae  and      x14, x13, #0x7f
//   0x108c: cb0a01ef  sub      x15, x15, x10
//   0x1090: 9acf21ce  lsl      x14, x14, x15
//   0x1094: aa0901c9  orr      x9, x14, x9
//   0x1098: 9100054a  add      x10, x10, #1
//   0x109c: 373ffecd  tbnz     w13, #7, #0x1074
//   0x10a0: 14000002  b        #0x10a8
//   0x10a4: aa1f03ea  mov      x10, xzr
//   0x10a8: 8b0a011a  add      x26, x8, x10
//   0x10ac: eb1a0308  subs     x8, x24, x26
//   0x10b0: f9000e89  str      x9, [x20, #0x18]
//   0x10b4: 54000140  b.eq     #0x10dc
//   0x10b8: 8b1a02e9  add      x9, x23, x26
//   0x10bc: 3940012b  ldrb     w11, [x9]
//   0x10c0: f100251f  cmp      x8, #9
//   0x10c4: 5280012a  mov      w10, #9
//   0x10c8: 9a8a310a  csel     x10, x8, x10, lo
//   0x10cc: 92401968  and      x8, x11, #0x7f
//   0x10d0: 3738008b  tbnz     w11, #7, #0x10e0
//   0x10d4: 5280002a  mov      w10, #1
//   0x10d8: 14000012  b        #0x1120
//   0x10dc: 14000014  b        #0x112c
//   0x10e0: f100055f  cmp      x10, #1
//   0x10e4: 9a9f854b  csinc    x11, x10, xzr, hi
//   0x10e8: 5280002a  mov      w10, #1
//   0x10ec: eb0b015f  cmp      x10, x11
//   0x10f0: 54000160  b.eq     #0x111c
//   0x10f4: 386a692c  ldrb     w12, [x9, x10]
//   0x10f8: b400012c  cbz      x12, #0x111c
//   0x10fc: d37df14e  lsl      x14, x10, #3
//   0x1100: 9240198d  and      x13, x12, #0x7f
//   0x1104: cb0a01ce  sub      x14, x14, x10
//   0x1108: 9ace21ad  lsl      x13, x13, x14
//   0x110c: aa0801a8  orr      x8, x13, x8
//   0x1110: 9100054a  add      x10, x10, #1
//   0x1114: 373ffecc  tbnz     w12, #7, #0x10ec
//   0x1118: 14000002  b        #0x1120
//   0x111c: aa1f03ea  mov      x10, xzr
//   0x1120: 8b0a035a  add      x26, x26, x10
//   0x1124: b9000a88  str      w8, [x20, #8]
//   0x1128: 34002f68  cbz      w8, #0x1714
//   0x112c: 92407d16  and      x22, x8, #0xffffffff
//   0x1130: 52806301  mov      w1, #0x318
//   0x1134: aa1603e0  mov      x0, x22
//   0x1138: 94000872  bl       #0x3300
//   0x113c: f9000280  str      x0, [x20]
//   0x1140: b4002e40  cbz      x0, #0x1708
//   0x1144: 52806308  mov      w8, #0x318
//   0x1148: 9b0802c8  madd     x8, x22, x8, x0
//   0x114c: eb00011f  cmp      x8, x0
//   0x1150: 54002a29  b.ls     #0x1694
//   0x1154: 5280012a  mov      w10, #9
//   0x1158: aa0003ef  mov      x15, x0
//   0x115c: 14000004  b        #0x116c
//   0x1160: 910c61ef  add      x15, x15, #0x318
//   0x1164: eb0801ff  cmp      x15, x8
//   0x1168: 54002962  b.hs     #0x1694
//   0x116c: eb1a0307  subs     x7, x24, x26
//   0x1170: 54000320  b.eq     #0x11d4
//   0x1174: 8b1a02e6  add      x6, x23, x26
//   0x1178: 394000d6  ldrb     w22, [x6]
//   0x117c: f10024ff  cmp      x7, #9
//   0x1180: 9a8a30e7  csel     x7, x7, x10, lo
//   0x1184: 92401acb  and      x11, x22, #0x7f
//   0x1188: 37380076  tbnz     w22, #7, #0x1194
//   0x118c: 52800027  mov      w7, #1
//   0x1190: 14000011  b        #0x11d4
//   0x1194: f10004ff  cmp      x7, #1
//   0x1198: 9a9f84f6  csinc    x22, x7, xzr, hi
//   0x119c: 52800027  mov      w7, #1
//   0x11a0: eb1600ff  cmp      x7, x22
//   0x11a4: 54000160  b.eq     #0x11d0
//   0x11a8: 386768db  ldrb     w27, [x6, x7]
//   0x11ac: b400013b  cbz      x27, #0x11d0
//   0x11b0: d37df0fe  lsl      x30, x7, #3
//   0x11b4: 92401b7c  and      x28, x27, #0x7f
//   0x11b8: cb0703de  sub      x30, x30, x7
//   0x11bc: 9ade239c  lsl      x28, x28, x30
//   0x11c0: aa0b038b  orr      x11, x28, x11
//   0x11c4: 910004e7  add      x7, x7, #1
//   0x11c8: 373ffedb  tbnz     w27, #7, #0x11a0
//   0x11cc: 14000002  b        #0x11d4
//   0x11d0: aa1f03e7  mov      x7, xzr
//   0x11d4: 8b070346  add      x6, x26, x7
//   0x11d8: eb060316  subs     x22, x24, x6
//   0x11dc: f90001eb  str      x11, [x15]
//   0x11e0: 54000320  b.eq     #0x1244
//   0x11e4: 8b0602e7  add      x7, x23, x6
//   0x11e8: 394000fa  ldrb     w26, [x7]
//   0x11ec: f10026df  cmp      x22, #9
//   0x11f0: 9a8a32d6  csel     x22, x22, x10, lo
//   0x11f4: 92401b4c  and      x12, x26, #0x7f
//   0x11f8: 3738007a  tbnz     w26, #7, #0x1204
//   0x11fc: 52800036  mov      w22, #1
//   0x1200: 14000011  b        #0x1244
//   0x1204: f10006df  cmp      x22, #1
//   0x1208: 9a9f86da  csinc    x26, x22, xzr, hi
//   0x120c: 52800036  mov      w22, #1
//   0x1210: eb1a02df  cmp      x22, x26
//   0x1214: 54000160  b.eq     #0x1240
//   0x1218: 387668fb  ldrb     w27, [x7, x22]
//   0x121c: b400013b  cbz      x27, #0x1240
//   0x1220: d37df2de  lsl      x30, x22, #3
//   0x1224: 92401b7c  and      x28, x27, #0x7f
//   0x1228: cb1603de  sub      x30, x30, x22
//   0x122c: 9ade239c  lsl      x28, x28, x30
//   0x1230: aa0c038c  orr      x12, x28, x12
//   0x1234: 910006d6  add      x22, x22, #1
//   0x1238: 373ffedb  tbnz     w27, #7, #0x1210
//   0x123c: 14000002  b        #0x1244
//   0x1240: aa1f03f6  mov      x22, xzr
//   0x1244: 8b1600c6  add      x6, x6, x22
//   0x1248: eb060316  subs     x22, x24, x6
//   0x124c: f90005ec  str      x12, [x15, #8]
//   0x1250: 54000320  b.eq     #0x12b4
//   0x1254: 8b0602e7  add      x7, x23, x6
//   0x1258: 394000fa  ldrb     w26, [x7]
//   0x125c: f10026df  cmp      x22, #9
//   0x1260: 9a8a32d6  csel     x22, x22, x10, lo
//   0x1264: 92401b4d  and      x13, x26, #0x7f
//   0x1268: 3738007a  tbnz     w26, #7, #0x1274
//   0x126c: 52800036  mov      w22, #1
//   0x1270: 14000011  b        #0x12b4
//   0x1274: f10006df  cmp      x22, #1
//   0x1278: 9a9f86da  csinc    x26, x22, xzr, hi
//   0x127c: 52800036  mov      w22, #1
//   0x1280: eb1a02df  cmp      x22, x26
//   0x1284: 54000160  b.eq     #0x12b0
//   0x1288: 387668fb  ldrb     w27, [x7, x22]
//   0x128c: b400013b  cbz      x27, #0x12b0
//   0x1290: d37df2de  lsl      x30, x22, #3
//   0x1294: 92401b7c  and      x28, x27, #0x7f
//   0x1298: cb1603de  sub      x30, x30, x22
//   0x129c: 9ade239c  lsl      x28, x28, x30
//   0x12a0: aa0d038d  orr      x13, x28, x13
//   0x12a4: 910006d6  add      x22, x22, #1
//   0x12a8: 373ffedb  tbnz     w27, #7, #0x1280
//   0x12ac: 14000002  b        #0x12b4
//   0x12b0: aa1f03f6  mov      x22, xzr
//   0x12b4: 8b1600da  add      x26, x6, x22
//   0x12b8: b90015ed  str      w13, [x15, #0x14]
//   0x12bc: 34fff52d  cbz      w13, #0x1160
//   0x12c0: 910061e6  add      x6, x15, #0x18
//   0x12c4: 92407da7  and      x7, x13, #0xffffffff
//   0x12c8: 52800609  mov      w9, #0x30
//   0x12cc: 9b0918e7  madd     x7, x7, x9, x6
//   0x12d0: 14000008  b        #0x12f0
//   0x12d4: 5280003b  mov      w27, #1
//   0x12d8: 92401c69  and      x9, x3, #0xff
//   0x12dc: 8b1b02da  add      x26, x22, x27
//   0x12e0: f90014c9  str      x9, [x6, #0x28]
//   0x12e4: 9100c0c6  add      x6, x6, #0x30
//   0x12e8: eb0700df  cmp      x6, x7
//   0x12ec: 54fff3a2  b.hs     #0x1160
//   0x12f0: eb1a031b  subs     x27, x24, x26
//   0x12f4: 54000320  b.eq     #0x1358
//   0x12f8: 8b1a02f6  add      x22, x23, x26
//   0x12fc: 394002dc  ldrb     w28, [x22]
//   0x1300: f100277f  cmp      x27, #9
//   0x1304: 9a8a337b  csel     x27, x27, x10, lo
//   0x1308: 92401b8e  and      x14, x28, #0x7f
//   0x130c: 3738007c  tbnz     w28, #7, #0x1318
//   0x1310: 5280003b  mov      w27, #1
//   0x1314: 14000011  b        #0x1358
//   0x1318: f100077f  cmp      x27, #1
//   0x131c: 9a9f877c  csinc    x28, x27, xzr, hi
//   0x1320: 5280003b  mov      w27, #1
//   0x1324: eb1c037f  cmp      x27, x28
//   0x1328: 54000160  b.eq     #0x1354
//   0x132c: 387b6ade  ldrb     w30, [x22, x27]
//   0x1330: b400013e  cbz      x30, #0x1354
//   0x1334: d37df373  lsl      x19, x27, #3
//   0x1338: 92401bc9  and      x9, x30, #0x7f
//   0x133c: cb1b0273  sub      x19, x19, x27
//   0x1340: 9ad32129  lsl      x9, x9, x19
//   0x1344: aa0e012e  orr      x14, x9, x14
//   0x1348: 9100077b  add      x27, x27, #1
//   0x134c: 373ffede  tbnz     w30, #7, #0x1324
//   0x1350: 14000002  b        #0x1358
//   0x1354: aa1f03fb  mov      x27, xzr
//   0x1358: 12001dd6  and      w22, w14, #0xff
//   0x135c: 8b1b035a  add      x26, x26, x27
//   0x1360: 71000adf  cmp      w22, #2
//   0x1364: 390000ce  strb     w14, [x6]
//   0x1368: 54000162  b.hs     #0x1394
//   0x136c: eb1a031b  subs     x27, x24, x26
//   0x1370: 540004a0  b.eq     #0x1404
//   0x1374: 8b1a02f6  add      x22, x23, x26
//   0x1378: 394002c9  ldrb     w9, [x22]
//   0x137c: f100277f  cmp      x27, #9
//   0x1380: 9a8a337b  csel     x27, x27, x10, lo
//   0x1384: 92401930  and      x16, x9, #0x7f
//   0x1388: 373801e9  tbnz     w9, #7, #0x13c4
//   0x138c: 5280003b  mov      w27, #1
//   0x1390: 1400001d  b        #0x1404
//   0x1394: 710062df  cmp      w22, #0x18
//   0x1398: 54fffa61  b.ne     #0x12e4
//   0x139c: eb1a031b  subs     x27, x24, x26
//   0x13a0: 54001380  b.eq     #0x1610
//   0x13a4: 8b1a02f6  add      x22, x23, x26
//   0x13a8: 394002c9  ldrb     w9, [x22]
//   0x13ac: f100277f  cmp      x27, #9
//   0x13b0: 9a8a337b  csel     x27, x27, x10, lo
//   0x13b4: 92401924  and      x4, x9, #0x7f
//   0x13b8: 373810c9  tbnz     w9, #7, #0x15d0
//   0x13bc: 5280003b  mov      w27, #1
//   0x13c0: 14000094  b        #0x1610
//   0x13c4: f100077f  cmp      x27, #1
//   0x13c8: 9a9f877c  csinc    x28, x27, xzr, hi
//   0x13cc: 5280003b  mov      w27, #1
//   0x13d0: eb1c037f  cmp      x27, x28
//   0x13d4: 54000160  b.eq     #0x1400
//   0x13d8: 387b6ade  ldrb     w30, [x22, x27]
//   0x13dc: b400013e  cbz      x30, #0x1400
//   0x13e0: d37df373  lsl      x19, x27, #3
//   0x13e4: 92401bc9  and      x9, x30, #0x7f
//   0x13e8: cb1b0273  sub      x19, x19, x27
//   0x13ec: 9ad32129  lsl      x9, x9, x19
//   0x13f0: aa100130  orr      x16, x9, x16
//   0x13f4: 9100077b  add      x27, x27, #1
//   0x13f8: 373ffede  tbnz     w30, #7, #0x13d0
//   0x13fc: 14000002  b        #0x1404
//   0x1400: aa1f03fb  mov      x27, xzr
//   0x1404: 8b1b0356  add      x22, x26, x27
//   0x1408: 92401e09  and      x9, x16, #0xff
//   0x140c: eb16031b  subs     x27, x24, x22
//   0x1410: f90004c9  str      x9, [x6, #8]
//   0x1414: 54000320  b.eq     #0x1478
//   0x1418: 8b1602fa  add      x26, x23, x22
//   0x141c: 39400349  ldrb     w9, [x26]
//   0x1420: f100277f  cmp      x27, #9
//   0x1424: 9a8a337b  csel     x27, x27, x10, lo
//   0x1428: 92401931  and      x17, x9, #0x7f
//   0x142c: 37380069  tbnz     w9, #7, #0x1438
//   0x1430: 5280003b  mov      w27, #1
//   0x1434: 14000011  b        #0x1478
//   0x1438: f100077f  cmp      x27, #1
//   0x143c: 9a9f877c  csinc    x28, x27, xzr, hi
//   0x1440: 5280003b  mov      w27, #1
//   0x1444: eb1c037f  cmp      x27, x28
//   0x1448: 54000160  b.eq     #0x1474
//   0x144c: 387b6b5e  ldrb     w30, [x26, x27]
//   0x1450: b400013e  cbz      x30, #0x1474
//   0x1454: d37df373  lsl      x19, x27, #3
//   0x1458: 92401bc9  and      x9, x30, #0x7f
//   0x145c: cb1b0273  sub      x19, x19, x27
//   0x1460: 9ad32129  lsl      x9, x9, x19
//   0x1464: aa110131  orr      x17, x9, x17
//   0x1468: 9100077b  add      x27, x27, #1
//   0x146c: 373ffede  tbnz     w30, #7, #0x1444
//   0x1470: 14000002  b        #0x1478
//   0x1474: aa1f03fb  mov      x27, xzr
//   0x1478: 8b1b02d6  add      x22, x22, x27
//   0x147c: 92401e29  and      x9, x17, #0xff
//   0x1480: eb16031b  subs     x27, x24, x22
//   0x1484: f90008c9  str      x9, [x6, #0x10]
//   0x1488: 54000320  b.eq     #0x14ec
//   0x148c: 8b1602fa  add      x26, x23, x22
//   0x1490: 39400349  ldrb     w9, [x26]
//   0x1494: f100277f  cmp      x27, #9
//   0x1498: 9a8a337b  csel     x27, x27, x10, lo
//   0x149c: 92401921  and      x1, x9, #0x7f
//   0x14a0: 37380069  tbnz     w9, #7, #0x14ac
//   0x14a4: 5280003b  mov      w27, #1
//   0x14a8: 14000011  b        #0x14ec
//   0x14ac: f100077f  cmp      x27, #1
//   0x14b0: 9a9f877c  csinc    x28, x27, xzr, hi
//   0x14b4: 5280003b  mov      w27, #1
//   0x14b8: eb1c037f  cmp      x27, x28
//   0x14bc: 54000160  b.eq     #0x14e8
//   0x14c0: 387b6b5e  ldrb     w30, [x26, x27]
//   0x14c4: b400013e  cbz      x30, #0x14e8
//   0x14c8: d37df373  lsl      x19, x27, #3
//   0x14cc: 92401bc9  and      x9, x30, #0x7f
//   0x14d0: cb1b0273  sub      x19, x19, x27
//   0x14d4: 9ad32129  lsl      x9, x9, x19
//   0x14d8: aa010121  orr      x1, x9, x1
//   0x14dc: 9100077b  add      x27, x27, #1
//   0x14e0: 373ffede  tbnz     w30, #7, #0x14b8
//   0x14e4: 14000002  b        #0x14ec
//   0x14e8: aa1f03fb  mov      x27, xzr
//   0x14ec: 8b1b02d6  add      x22, x22, x27
//   0x14f0: 92401c29  and      x9, x1, #0xff
//   0x14f4: eb16031b  subs     x27, x24, x22
//   0x14f8: f9000cc9  str      x9, [x6, #0x18]
//   0x14fc: 54000320  b.eq     #0x1560
//   0x1500: 8b1602fa  add      x26, x23, x22
//   0x1504: 39400349  ldrb     w9, [x26]
//   0x1508: f100277f  cmp      x27, #9
//   0x150c: 9a8a337b  csel     x27, x27, x10, lo
//   0x1510: 92401922  and      x2, x9, #0x7f
//   0x1514: 37380069  tbnz     w9, #7, #0x1520
//   0x1518: 5280003b  mov      w27, #1
//   0x151c: 14000011  b        #0x1560
//   0x1520: f100077f  cmp      x27, #1
//   0x1524: 9a9f877c  csinc    x28, x27, xzr, hi
//   0x1528: 5280003b  mov      w27, #1
//   0x152c: eb1c037f  cmp      x27, x28
//   0x1530: 54000160  b.eq     #0x155c
//   0x1534: 387b6b5e  ldrb     w30, [x26, x27]
//   0x1538: b400013e  cbz      x30, #0x155c
//   0x153c: d37df373  lsl      x19, x27, #3
//   0x1540: 92401bc9  and      x9, x30, #0x7f
//   0x1544: cb1b0273  sub      x19, x19, x27
//   0x1548: 9ad32129  lsl      x9, x9, x19
//   0x154c: aa020122  orr      x2, x9, x2
//   0x1550: 9100077b  add      x27, x27, #1
//   0x1554: 373ffede  tbnz     w30, #7, #0x152c
//   0x1558: 14000002  b        #0x1560
//   0x155c: aa1f03fb  mov      x27, xzr
//   0x1560: 8b1b02d6  add      x22, x22, x27
//   0x1564: 92401c49  and      x9, x2, #0xff
//   0x1568: eb16031b  subs     x27, x24, x22
//   0x156c: f90010c9  str      x9, [x6, #0x20]
//   0x1570: 54ffeb40  b.eq     #0x12d8
//   0x1574: 8b1602fa  add      x26, x23, x22
//   0x1578: 39400349  ldrb     w9, [x26]
//   0x157c: f100277f  cmp      x27, #9
//   0x1580: 9a8a337b  csel     x27, x27, x10, lo
//   0x1584: 92401923  and      x3, x9, #0x7f
//   0x1588: 363fea69  tbz      w9, #7, #0x12d4
//   0x158c: f100077f  cmp      x27, #1
//   0x1590: 9a9f877c  csinc    x28, x27, xzr, hi
//   0x1594: 5280003b  mov      w27, #1
//   0x1598: eb1c037f  cmp      x27, x28
//   0x159c: 54000160  b.eq     #0x15c8
//   0x15a0: 387b6b5e  ldrb     w30, [x26, x27]
//   0x15a4: b400013e  cbz      x30, #0x15c8
//   0x15a8: d37df373  lsl      x19, x27, #3
//   0x15ac: 92401bc9  and      x9, x30, #0x7f
//   0x15b0: cb1b0273  sub      x19, x19, x27
//   0x15b4: 9ad32129  lsl      x9, x9, x19
//   0x15b8: aa030123  orr      x3, x9, x3
//   0x15bc: 9100077b  add      x27, x27, #1
//   0x15c0: 373ffede  tbnz     w30, #7, #0x1598
//   0x15c4: 17ffff45  b        #0x12d8
//   0x15c8: aa1f03fb  mov      x27, xzr
//   0x15cc: 17ffff43  b        #0x12d8
//   0x15d0: f100077f  cmp      x27, #1
//   0x15d4: 9a9f877c  csinc    x28, x27, xzr, hi
//   0x15d8: 5280003b  mov      w27, #1
//   0x15dc: eb1c037f  cmp      x27, x28
//   0x15e0: 54000160  b.eq     #0x160c
//   0x15e4: 387b6ade  ldrb     w30, [x22, x27]
//   0x15e8: b400013e  cbz      x30, #0x160c
//   0x15ec: d37df373  lsl      x19, x27, #3
//   0x15f0: 92401bc9  and      x9, x30, #0x7f
//   0x15f4: cb1b0273  sub      x19, x19, x27
//   0x15f8: 9ad32129  lsl      x9, x9, x19
//   0x15fc: aa040124  orr      x4, x9, x4
//   0x1600: 9100077b  add      x27, x27, #1
//   0x1604: 373ffede  tbnz     w30, #7, #0x15dc
//   0x1608: 14000002  b        #0x1610
//   0x160c: aa1f03fb  mov      x27, xzr
//   0x1610: 8b1b0356  add      x22, x26, x27
//   0x1614: 92401c89  and      x9, x4, #0xff
//   0x1618: eb16031b  subs     x27, x24, x22
//   0x161c: f90004c9  str      x9, [x6, #8]
//   0x1620: 54000320  b.eq     #0x1684
//   0x1624: 8b1602fa  add      x26, x23, x22
//   0x1628: 39400349  ldrb     w9, [x26]
//   0x162c: f100277f  cmp      x27, #9
//   0x1630: 9a8a337b  csel     x27, x27, x10, lo
//   0x1634: 92401925  and      x5, x9, #0x7f
//   0x1638: 37380069  tbnz     w9, #7, #0x1644
//   0x163c: 5280003b  mov      w27, #1
//   0x1640: 14000011  b        #0x1684
//   0x1644: f100077f  cmp      x27, #1
//   0x1648: 9a9f877c  csinc    x28, x27, xzr, hi
//   0x164c: 5280003b  mov      w27, #1
//   0x1650: eb1c037f  cmp      x27, x28
//   0x1654: 54000160  b.eq     #0x1680
//   0x1658: 387b6b5e  ldrb     w30, [x26, x27]
//   0x165c: b400013e  cbz      x30, #0x1680
//   0x1660: d37df373  lsl      x19, x27, #3
//   0x1664: 92401bc9  and      x9, x30, #0x7f
//   0x1668: cb1b0273  sub      x19, x19, x27
//   0x166c: 9ad32129  lsl      x9, x9, x19
//   0x1670: aa050125  orr      x5, x9, x5
//   0x1674: 9100077b  add      x27, x27, #1
//   0x1678: 373ffede  tbnz     w30, #7, #0x1650
//   0x167c: 14000002  b        #0x1684
//   0x1680: aa1f03fb  mov      x27, xzr
//   0x1684: 8b1b02da  add      x26, x22, x27
//   0x1688: 92401ca9  and      x9, x5, #0xff
//   0x168c: f90008c9  str      x9, [x6, #0x10]
//   0x1690: 17ffff15  b        #0x12e4
//   0x1694: f2400748  ands     x8, x26, #3
//   0x1698: d2400508  eor      x8, x8, #3
//   0x169c: 8b080348  add      x8, x26, x8
//   0x16a0: 9a88075a  csinc    x26, x26, x8, eq
//   0x16a4: 91001348  add      x8, x26, #4
//   0x16a8: eb18011f  cmp      x8, x24
//   0x16ac: 540002c8  b.hi     #0x1704
//   0x16b0: b400021a  cbz      x26, #0x16f0
//   0x16b4: d00000c9  adrp     x9, #0x1b000
//   0x16b8: 12800008  mov      w8, #-1
//   0x16bc: 9116e129  add      x9, x9, #0x5b8
//   0x16c0: aa1703ea  mov      x10, x23
//   0x16c4: aa1a03eb  mov      x11, x26
//   0x16c8: 3840154c  ldrb     w12, [x10], #1
//   0x16cc: 12001d0d  and      w13, w8, #0xff
//   0x16d0: f100056b  subs     x11, x11, #1
//   0x16d4: 4a0c01ac  eor      w12, w13, w12
//   0x16d8: 8b2c492c  add      x12, x9, w12, uxtw #2
//   0x16dc: b940218c  ldr      w12, [x12, #0x20]
//   0x16e0: 4a482188  eor      w8, w12, w8, lsr #8
//   0x16e4: 54ffff21  b.ne     #0x16c8
//   0x16e8: 2a2803e8  mvn      w8, w8
//   0x16ec: 14000002  b        #0x16f4
//   0x16f0: 2a1f03e8  mov      w8, wzr
//   0x16f4: b87a6ae9  ldr      w9, [x23, x26]
//   0x16f8: 9100135a  add      x26, x26, #4
//   0x16fc: 6b09011f  cmp      w8, w9
//   0x1700: 540000a0  b.eq     #0x1714
//   0x1704: 94000703  bl       #0x3310
//   0x1708: aa1403e0  mov      x0, x20
//   0x170c: 94000701  bl       #0x3310
//   0x1710: aa1f03f4  mov      x20, xzr
//   0x1714: f9400a83  ldr      x3, [x20, #0x10]
//   0x1718: eb15007f  cmp      x3, x21
//   0x171c: 54000069  b.ls     #0x1728
//   0x1720: 928001b3  mov      x19, #-0xe
//   0x1724: 17fffe24  b        #0xfb4
//   0x1728: f9400e88  ldr      x8, [x20, #0x18]
//   0x172c: 8b1a02f7  add      x23, x23, x26
//   0x1730: cb1a0316  sub      x22, x24, x26
//   0x1734: b4000328  cbz      x8, #0x1798
//   0x1738: 8b030118  add      x24, x8, x3
//   0x173c: aa1803e0  mov      x0, x24
//   0x1740: 940006ec  bl       #0x32f0
//   0x1744: aa0003f5  mov      x21, x0
//   0x1748: aa1703e0  mov      x0, x23
//   0x174c: aa1603e1  mov      x1, x22
//   0x1750: aa1503e2  mov      x2, x21
//   0x1754: aa1803e3  mov      x3, x24
//   0x1758: 94000031  bl       #0x181c
//   0x175c: eb00031f  cmp      x24, x0
//   0x1760: 54000501  b.ne     #0x1800
//   0x1764: a9412282  ldp      x2, x8, [x20, #0x10]
//   0x1768: f94003e3  ldr      x3, [sp]
//   0x176c: aa1403e0  mov      x0, x20
//   0x1770: 8b0802a1  add      x1, x21, x8
//   0x1774: 940004ec  bl       #0x2b24
//   0x1778: aa1503e0  mov      x0, x21
//   0x177c: 940006e5  bl       #0x3310
//   0x1780: f9400280  ldr      x0, [x20]
//   0x1784: f9400a93  ldr      x19, [x20, #0x10]
//   0x1788: 940006e2  bl       #0x3310
//   0x178c: aa1403e0  mov      x0, x20
//   0x1790: 940006e0  bl       #0x3310
//   0x1794: 17fffe08  b        #0xfb4
//   0x1798: f94003f3  ldr      x19, [sp]
//   0x179c: aa1703e0  mov      x0, x23
//   0x17a0: aa1603e1  mov      x1, x22
//   0x17a4: aa1303e2  mov      x2, x19
//   0x17a8: 9400001d  bl       #0x181c
//   0x17ac: f9400a88  ldr      x8, [x20, #0x10]
//   0x17b0: eb00011f  cmp      x8, x0
//   0x17b4: 540002e1  b.ne     #0x1810
//   0x17b8: b9400a88  ldr      w8, [x20, #8]
//   0x17bc: 34fffe28  cbz      w8, #0x1780
//   0x17c0: f9400289  ldr      x9, [x20]
//   0x17c4: aa0003e2  mov      x2, x0
//   0x17c8: 5280002a  mov      w10, #1
//   0x17cc: 91005129  add      x9, x9, #0x14
//   0x17d0: b940012b  ldr      w11, [x9]
//   0x17d4: 350000ab  cbnz     w11, #0x17e8
//   0x17d8: eb08015f  cmp      x10, x8
//   0x17dc: 9100054a  add      x10, x10, #1
//   0x17e0: 910c6129  add      x9, x9, #0x318
//   0x17e4: 54ffff63  b.lo     #0x17d0
//   0x17e8: 34fffccb  cbz      w11, #0x1780
//   0x17ec: aa1403e0  mov      x0, x20
//   0x17f0: aa1303e1  mov      x1, x19
//   0x17f4: aa1f03e3  mov      x3, xzr
//   0x17f8: 940004cb  bl       #0x2b24
//   0x17fc: 17ffffe1  b        #0x1780
//   0x1800: aa1503e0  mov      x0, x21
//   0x1804: 940006c3  bl       #0x3310
//   0x1808: 928001f3  mov      x19, #-0x10
//   0x180c: 17fffdea  b        #0xfb4
//   0x1810: 928001d3  mov      x19, #-0xf
//   0x1814: 17fffde8  b        #0xfb4
//   0x1818: 940006c2  bl       #0x3320
// ============================================================================

#include "komprese_decompressor.h"

#include <cstdlib>
#include <cstring>
#include <mutex>

namespace nextai {
namespace opencut {
namespace komprese {

namespace {

std::once_flag g_init_once;
KompreseGlobalBssState g_bss_state{};
alignas(16) uint16_t g_ans_cdf_storage[256];
alignas(16) uint8_t  g_dist_slot_storage[128];
alignas(16) uint8_t  g_align_bits_storage[32];
alignas(16) uint8_t  g_short_rep_storage[8];

}  // namespace

// EN: Exact reconstruction of FDE[05] (0x0ab8..0x0e98):
//     1) Vectorized 2-step / 1-step Sarwate CRC-32 (0xEDB88320) & CRC-64 (0xC96C5795D7870F42)
//        table generation into 0x1b5d8 and 0x1b9d8.
//     2) Allocation and population of the 16x16 uint16_t target CDF matrix at 0x1b5b8:
//        for row d in 0..15:
//          cols 0..d   = k * 16
//          cols d+1..15 = 0x3F8F + (d + k) * 16 (verified at 0x0cc8: mov w10, #0x3f8f).
//     3) Population of distance/slot tables at 0x1b5c0, 0x1b5c8, 0x1b5d0 from .rodata.
//     4) Reciprocal division table at 0x0b5b8: for i in 2..4095:
//        shift = 95 - clz(i - 1); table[i] = ((1ULL << shift) + i - 1) / i; table[0]=0; table[1]=table[2].
// VI: Tái tạo chính xác FDE[05] (0x0ab8..0x0e98):
//     1) Khởi tạo bảng CRC-32 (0xEDB88320) và CRC-64 (0xC96C5795D7870F42) tại 0x1b5d8 và 0x1b9d8.
//     2) Cấp phát và điền ma trận CDF đích 16x16 uint16_t tại 0x1b5b8.
//     3) Điền các bảng khoảng cách/slot tại 0x1b5c0, 0x1b5c8, 0x1b5d0 từ .rodata.
//     4) Bảng chia nghịch đảo tại 0x0b5b8 cho i từ 2..4095.
void KompreseInitGlobalTables() noexcept {
    std::call_once(g_init_once, []() {
        g_bss_state.ans_target_cdf_16x32 = g_ans_cdf_storage;
        g_bss_state.dist_slot_table_128  = g_dist_slot_storage;
        g_bss_state.align_bits_table_32  = g_align_bits_storage;
        g_bss_state.short_rep_table_8    = g_short_rep_storage;

        // 1. CRC-32 (0xEDB88320) and CRC-64 (0xC96C5795D7870F42) tables (0x0ac4..0x0c7c)
        for (uint32_t i = 0; i < 256; ++i) {
            uint32_t c32 = i;
            uint64_t c64 = i;
            for (int bit = 0; bit < 8; ++bit) {
                c32 = (c32 >> 1) ^ ((c32 & 1U) ? kCrc32PolynomialReflected : 0U);
                c64 = (c64 >> 1) ^ ((c64 & 1ULL) ? kCrc64XzPolynomialReflected : 0ULL);
            }
            g_bss_state.crc32_table[i] = c32;
            g_bss_state.crc64_table[i] = c64;
        }

        // 2. 16x16 target CDF matrix for 14-bit multisymbol range updates (0x0cc0..0x0d74)
        for (size_t d = 0; d < 16; ++d) {
            uint16_t* row = &g_bss_state.ans_target_cdf_16x32[d * 16];
            for (size_t k = 0; k <= d; ++k) {
                row[k] = static_cast<uint16_t>(k << 4);
            }
            for (size_t k = 0; d + k < 15; ++k) {
                row[d + 1 + k] = static_cast<uint16_t>(0x3F8FU + ((d + k) << 4));
            }
        }

        // 3. Copy .rodata lookup constants into distance/align tables (0x0d78..0x0e50)
        std::memcpy(g_bss_state.dist_slot_table_128, &kKompreseRodata480[0x7a0 - 0x6e0], 16);
        std::memcpy(g_bss_state.align_bits_table_32, &kKompreseRodata480[0x6e8 - 0x6e0], 16);
        uint64_t short_rep_const = 0x00020000407D0000ULL;
        std::memcpy(g_bss_state.short_rep_table_8, &short_rep_const, sizeof(short_rep_const));

        // 4. Reciprocal division table at 0x0b5b8 (0x0e44..0x0e90)
        for (uint64_t i = 2; i < 4096; ++i) {
            uint64_t prev = i - 1;
            uint64_t lz = __builtin_clzll(prev);
            uint64_t shift = 0x5FU - lz;  // 95 - clz(i - 1) = 32 + floor(log2(i - 1))
            uint64_t num = (1ULL << shift) + i - 1;
            g_bss_state.reciprocal_div_table[i] = static_cast<uint32_t>(num / i);
        }
        g_bss_state.reciprocal_div_table[0] = 0U;
        g_bss_state.reciprocal_div_table[1] = g_bss_state.reciprocal_div_table[2];
    });
}

uint32_t KompreseComputeCrc32(const uint8_t* data, size_t len, uint32_t seed) noexcept {
    KompreseInitGlobalTables();
    uint32_t crc = seed;
    for (size_t i = 0; i < len; ++i) {
        uint8_t idx = static_cast<uint8_t>((crc ^ data[i]) & 0xFFU);
        crc = g_bss_state.crc32_table[idx] ^ (crc >> 8);
    }
    return ~crc;
}

uint64_t KompreseComputeCrc64(const uint8_t* data, size_t len, uint64_t seed) noexcept {
    KompreseInitGlobalTables();
    uint64_t crc = seed;
    for (size_t i = 0; i < len; ++i) {
        uint8_t idx = static_cast<uint8_t>((crc ^ data[i]) & 0xFFULL);
        crc = g_bss_state.crc64_table[idx] ^ (crc >> 8);
    }
    return ~crc;
}

// EN: Exact reconstruction of the inlined LEB128 varint reader (0x0f90..0x1034, etc.).
//     Reads up to 9 bytes; stops early if a continuation byte is 0x00 (corrupted varint -> returns 0).
// VI: Tái tạo chính xác bộ đọc varint LEB128 inline (0x0f90..0x1034, v.v.).
//     Đọc tối đa 9 byte; dừng sớm nếu byte tiếp theo bằng 0x00 (varint lỗi -> trả về 0).
size_t KompreseReadVarint64(const uint8_t* src, size_t avail, uint64_t* out_val) noexcept {
    if (avail == 0) {
        *out_val = 0;
        return 0;
    }
    uint8_t b0 = src[0];
    uint64_t val = static_cast<uint64_t>(b0 & 0x7FU);
    if ((b0 & 0x80U) == 0) {
        *out_val = val;
        return 1;
    }
    size_t max_len = (avail < 9) ? avail : 9;
    size_t limit = (max_len > 1) ? max_len : 1;
    size_t idx = 1;
    while (idx < limit) {
        uint8_t b = src[idx];
        if (b == 0) {
            *out_val = val;
            return 0;
        }
        uint64_t shift = (idx << 3) - idx;  // idx * 7
        val |= static_cast<uint64_t>(b & 0x7FU) << shift;
        ++idx;
        if ((b & 0x80U) == 0) {
            *out_val = val;
            return idx;
        }
    }
    *out_val = val;
    return 0;
}

}  // namespace komprese
}  // namespace opencut
}  // namespace nextai

extern "C" {

// EN: Exact reconstruction of komprese_decompress (FDE[06], 0x0e9c..0x1818):
//     1) Validates 12-byte Komprese header (if src_size >= 13):
//        - Magic uint32_t at +0x00 == 0x4D4F4B7F ("\x7fKOM")
//        - Version uint8_t at +0x04 == 1
//        - 3-byte flags/options at +0x05..+0x07 CRC-32 matches uint32_t at +0x08
//          (starting from g_bss_state.crc32_table[0xFE] ^ 0xFFFFFF at 0x0f20..0x0f68).
//     2) Allocates KompreseStreamContext (0x20 bytes) and parses LEB128 varints:
//        - uncompressed_size (+0x10), extra_prefix_size (+0x18), num_sections (+0x08).
//     3) Allocates num_sections * 0x318 bytes via calloc and parses each section's
//        offset, size, num_patches, and each patch's parameters (type < 2: 4 varints;
//        type == 0x18: 2 varints).
//     4) Aligns metadata cursor to 4-byte boundary and verifies metadata CRC-32.
//     5) Verifies uncompressed_size <= dst_capacity (else returns -14).
//     6) Decompresses bitstream via KompreseDecompressBitstream (0x181c) and applies
//        BCJ/relocation post-filters via KompreseApplyBcjAndRelocFilters (0x2b24).
// VI: Tái tạo chính xác hàm komprese_decompress (FDE[06], 0x0e9c..0x1818):
//     1) Kiểm tra header 12 byte Komprese (nếu src_size >= 13):
//        - Magic uint32_t tại +0x00 == 0x4D4F4B7F ("\x7fKOM")
//        - Version uint8_t tại +0x04 == 1
//        - CRC-32 của 3 byte cờ tại +0x05..+0x07 khớp với uint32_t tại +0x08.
//     2) Cấp phát KompreseStreamContext (0x20 byte) và đọc các varint LEB128.
//     3) Cấp phát num_sections * 0x318 byte qua calloc và đọc thông tin từng phân đoạn.
//     4) Căn chỉnh con trỏ metadata theo biên 4 byte và xác minh CRC-32 metadata.
//     5) Kiểm tra uncompressed_size <= dst_capacity (nếu vượt trả về -14).
//     6) Giải nén luồng bit qua KompreseDecompressBitstream (0x181c) và áp dụng bộ lọc
//        BCJ/relocation qua KompreseApplyBcjAndRelocFilters (0x2b24).
int64_t komprese_decompress(
    const uint8_t* src,
    size_t src_size,
    uint8_t* dst,
    size_t dst_capacity) noexcept {
    using namespace nextai::opencut::komprese;
    KompreseInitGlobalTables();

    if (src == nullptr || dst == nullptr || src_size < 13) {
        return kKompreseErrBadHeaderOrCrc;  // -13 (0x0fb0)
    }

    uint64_t hdr_lo = 0;
    uint32_t hdr_crc = 0;
    std::memcpy(&hdr_lo, src, sizeof(uint64_t));
    std::memcpy(&hdr_crc, src + 8, sizeof(uint32_t));

    if (static_cast<uint32_t>(hdr_lo) != kKompreseMagic) {
        return kKompreseErrBadHeaderOrCrc;
    }
    uint8_t version = static_cast<uint8_t>((hdr_lo >> 32) & 0xFFU);
    if (version != kKompreseVersion) {
        return kKompreseErrBadHeaderOrCrc;
    }

    // Verify header CRC-32 over bytes 4..7 (version=1 + 3 option bytes at offsets 5..7)
    uint32_t computed_hdr_crc = KompreseComputeCrc32(src + 4, 4);
    if (computed_hdr_crc != hdr_crc) {
        return kKompreseErrBadHeaderOrCrc;
    }

    const uint8_t* meta_ptr = src + 12;
    size_t meta_rem = src_size - 12;

    auto* ctx = static_cast<KompreseStreamContext*>(std::malloc(sizeof(KompreseStreamContext)));
    if (ctx == nullptr) {
        return kKompreseErrOutputCapTooSmall;
    }
    std::memset(ctx, 0, sizeof(KompreseStreamContext));

    size_t pos = 0;
    uint64_t uncomp_sz = 0;
    pos += KompreseReadVarint64(meta_ptr + pos, meta_rem - pos, &uncomp_sz);
    ctx->uncompressed_size = uncomp_sz;

    uint64_t extra_sz = 0;
    if (pos < meta_rem) {
        pos += KompreseReadVarint64(meta_ptr + pos, meta_rem - pos, &extra_sz);
    }
    ctx->extra_prefix_size = extra_sz;

    uint64_t num_secs = 0;
    if (pos < meta_rem) {
        pos += KompreseReadVarint64(meta_ptr + pos, meta_rem - pos, &num_secs);
    }
    ctx->num_sections = static_cast<uint32_t>(num_secs);

    if (ctx->num_sections != 0) {
        ctx->sections = static_cast<KompreseSectionDescriptor*>(
            std::calloc(ctx->num_sections, sizeof(KompreseSectionDescriptor)));
        if (ctx->sections == nullptr) {
            std::free(ctx);
            return kKompreseErrBadHeaderOrCrc;
        }

        for (uint32_t s = 0; s < ctx->num_sections; ++s) {
            KompreseSectionDescriptor& sec = ctx->sections[s];
            uint64_t sec_off = 0, sec_len = 0, patch_cnt = 0;
            if (pos < meta_rem) pos += KompreseReadVarint64(meta_ptr + pos, meta_rem - pos, &sec_off);
            sec.section_offset = sec_off;
            if (pos < meta_rem) pos += KompreseReadVarint64(meta_ptr + pos, meta_rem - pos, &sec_len);
            sec.section_size = sec_len;
            if (pos < meta_rem) pos += KompreseReadVarint64(meta_ptr + pos, meta_rem - pos, &patch_cnt);
            sec.num_patches = static_cast<uint32_t>(patch_cnt);

            uint32_t limit_patches = (sec.num_patches <= 16) ? sec.num_patches : 16;
            for (uint32_t p = 0; p < limit_patches; ++p) {
                KompreseRelocPatchEntry& pe = sec.patches[p];
                uint64_t ptype = 0;
                if (pos < meta_rem) pos += KompreseReadVarint64(meta_ptr + pos, meta_rem - pos, &ptype);
                pe.patch_type = static_cast<uint8_t>(ptype & 0xFFU);

                if (pe.patch_type < 2) {
                    uint64_t v0 = 0, v1 = 0, v2 = 0, v3 = 0, v4 = 0;
                    if (pos < meta_rem) pos += KompreseReadVarint64(meta_ptr + pos, meta_rem - pos, &v0);
                    pe.param0_offset = v0 & 0xFFU;
                    if (pos < meta_rem) pos += KompreseReadVarint64(meta_ptr + pos, meta_rem - pos, &v1);
                    pe.param1_stride = v1 & 0xFFU;
                    if (pos < meta_rem) pos += KompreseReadVarint64(meta_ptr + pos, meta_rem - pos, &v2);
                    pe.param2_width = v2 & 0xFFU;
                    if (pos < meta_rem) pos += KompreseReadVarint64(meta_ptr + pos, meta_rem - pos, &v3);
                    pe.param3_extra = v3 & 0xFFU;
                    if (pos < meta_rem) pos += KompreseReadVarint64(meta_ptr + pos, meta_rem - pos, &v4);
                    pe.param4_tail = v4 & 0xFFU;
                } else if (pe.patch_type == 0x18) {
                    uint64_t v0 = 0, v1 = 0;
                    if (pos < meta_rem) pos += KompreseReadVarint64(meta_ptr + pos, meta_rem - pos, &v0);
                    pe.param0_offset = v0 & 0xFFU;
                    if (pos < meta_rem) pos += KompreseReadVarint64(meta_ptr + pos, meta_rem - pos, &v1);
                    pe.param1_stride = v1 & 0xFFU;
                }
            }
        }

        // Align pos to 4-byte boundary (0x1694..0x16a0)
        if ((pos & 3U) != 0) {
            pos += 4U - (pos & 3U);
        }
        if (pos + 4 > meta_rem) {
            std::free(ctx->sections);
            std::free(ctx);
            return kKompreseErrBadHeaderOrCrc;
        }
        uint32_t meta_crc_calc = (pos == 0) ? 0U : KompreseComputeCrc32(meta_ptr, pos);
        uint32_t meta_crc_stored = 0;
        std::memcpy(&meta_crc_stored, meta_ptr + pos, sizeof(uint32_t));
        pos += 4;
        if (meta_crc_calc != meta_crc_stored) {
            std::free(ctx->sections);
            std::free(ctx);
            return kKompreseErrBadHeaderOrCrc;
        }
    }

    if (ctx->uncompressed_size > dst_capacity) {
        std::free(ctx->sections);
        std::free(ctx);
        return kKompreseErrOutputCapTooSmall;  // -14 (0x1720)
    }

    const uint8_t* bit_src = meta_ptr + pos;
    size_t bit_len = meta_rem - pos;

    if (ctx->extra_prefix_size != 0) {
        size_t total_temp = static_cast<size_t>(ctx->extra_prefix_size + ctx->uncompressed_size);
        auto* temp_buf = static_cast<uint8_t*>(std::malloc(total_temp));
        int64_t dec_res = KompreseDecompressBitstream(bit_src, bit_len, temp_buf, total_temp);
        if (dec_res != static_cast<int64_t>(total_temp)) {
            std::free(temp_buf);
            std::free(ctx->sections);
            std::free(ctx);
            return kKompreseErrDictDecSize;  // -16 (0x1808)
        }
        KompreseApplyBcjAndRelocFilters(
            ctx,
            temp_buf + ctx->extra_prefix_size,
            static_cast<size_t>(ctx->uncompressed_size),
            dst);
        std::free(temp_buf);
    } else {
        int64_t dec_res = KompreseDecompressBitstream(
            bit_src, bit_len, dst, static_cast<size_t>(ctx->uncompressed_size));
        if (dec_res != static_cast<int64_t>(ctx->uncompressed_size)) {
            std::free(ctx->sections);
            std::free(ctx);
            return kKompreseErrDirectDecSize;  // -15 (0x1810)
        }
        bool has_patches = false;
        for (uint32_t s = 0; s < ctx->num_sections; ++s) {
            if (ctx->sections[s].num_patches != 0) {
                has_patches = true;
                break;
            }
        }
        if (has_patches) {
            KompreseApplyBcjAndRelocFilters(
                ctx, dst, static_cast<size_t>(ctx->uncompressed_size), nullptr);
        }
    }

    int64_t final_size = static_cast<int64_t>(ctx->uncompressed_size);
    std::free(ctx->sections);
    std::free(ctx);
    return final_size;
}

}  // extern "C"
