// ============================================================================
// NextAI OpenCut — Clean-Room C++17 Reconstruction
// File          : komprese_elf_bcj_reloc_filter.cpp
// Target Binary : libkomprese-decompressor.so (15,800 bytes)
// SHA-256       : 7a2a91ead53359dafebaae790ec6e5807f0e037c4c73b8ec0a3a49af1c1a18c3
// Task ID       : TASK-167-RECONSTRUCTION-LIBKOMPRESE-DECOMPRESSOR
// Function      : FDE[08] KompreseApplyBcjAndRelocFilters (0x2b24..0x3294)
// ============================================================================
// EN: Clean-room C++17 reconstruction of FDE[08] (0x2b24..0x3294, 1,908 bytes,
//     477 AArch64 instructions): Multi-architecture executable BCJ & relocation
//     post-filter supporting:
//       1) Variable-width delta-coded relocation tables (0x2c8c..0x2eb4)
//       2) AArch64 BL (0x94000000) & ADRP (0x90000000) PC-relative BCJ filter (0x2eb8..0x2f6c)
//       3) ARM Thumb-2 32-bit BL (0xF000/0xD000) & BLX (0xF000/0xC000) BCJ filter (0x2f70..0x326c)
//       4) AArch64 4-instruction PLT stub synthesis (ADRP x16 + LDR x17 + ADD x16 + BR x17) (0x2f8c..0x30bc)
//       5) 31-bit relative offset (Prel31 / .ARM.exidx) delta reconstruction (0x30c0..0x3108)
// VI: Bản tái tạo C++17 phòng sạch của FDE[08] (0x2b24..0x3294, 1.908 byte,
//     477 lệnh AArch64): Bộ lọc hậu kỳ BCJ & relocation đa kiến trúc.
// ============================================================================
// Complete AArch64 Disassembly Trace for 0x2b24..0x3294 (477 instructions):
//   0x2b24: d10203ff  sub      sp, sp, #0x80
//   0x2b28: 6d0123e9  stp      d9, d8, [sp, #0x10]
//   0x2b2c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x2b30: a9036ffc  stp      x28, x27, [sp, #0x30]
//   0x2b34: a90467fa  stp      x26, x25, [sp, #0x40]
//   0x2b38: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x2b3c: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x2b40: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x2b44: 910083fd  add      x29, sp, #0x20
//   0x2b48: f90003e0  str      x0, [sp]
//   0x2b4c: b4000103  cbz      x3, #0x2b6c
//   0x2b50: aa0303e0  mov      x0, x3
//   0x2b54: aa0303f3  mov      x19, x3
//   0x2b58: 940001f6  bl       #0x3330
//   0x2b5c: f94003e8  ldr      x8, [sp]
//   0x2b60: b9400907  ldr      w7, [x8, #8]
//   0x2b64: 350000c7  cbnz     w7, #0x2b7c
//   0x2b68: 140001c2  b        #0x3270
//   0x2b6c: aa0103f3  mov      x19, x1
//   0x2b70: f94003e8  ldr      x8, [sp]
//   0x2b74: b9400907  ldr      w7, [x8, #8]
//   0x2b78: 340037c7  cbz      w7, #0x3270
//   0x2b7c: f94003e8  ldr      x8, [sp]
//   0x2b80: d0fffff0  adrp     x16, #0
//   0x2b84: d0ffffe0  adrp     x0, #0
//   0x2b88: d0ffffe1  adrp     x1, #0
//   0x2b8c: f9400115  ldr      x21, [x8]
//   0x2b90: d0ffffe2  adrp     x2, #0
//   0x2b94: d0ffffe3  adrp     x3, #0
//   0x2b98: 3dc1d600  ldr      q0, [x16, #0x750]
//   0x2b9c: d0fffff0  adrp     x16, #0
//   0x2ba0: 3dc1f801  ldr      q1, [x0, #0x7e0]
//   0x2ba4: d0ffffe0  adrp     x0, #0
//   0x2ba8: 3dc1e022  ldr      q2, [x1, #0x780]
//   0x2bac: d0ffffe1  adrp     x1, #0
//   0x2bb0: 3dc1dc43  ldr      q3, [x2, #0x770]
//   0x2bb4: 3dc20c64  ldr      q4, [x3, #0x830]
//   0x2bb8: 3dc1f605  ldr      q5, [x16, #0x7d0]
//   0x2bbc: 3dc1ec06  ldr      q6, [x0, #0x7b0]
//   0x2bc0: 3dc1cc27  ldr      q7, [x1, #0x730]
//   0x2bc4: 52804228  mov      w8, #0x211
//   0x2bc8: 52804409  mov      w9, #0x220
//   0x2bcc: 528003ea  mov      w10, #0x1f
//   0x2bd0: 5280420c  mov      w12, #0x210
//   0x2bd4: 5280020d  mov      w13, #0x10
//   0x2bd8: 9100066e  add      x14, x19, #1
//   0x2bdc: d0fffff1  adrp     x17, #0
//   0x2be0: 52800202  mov      w2, #0x10
//   0x2be4: 72bf2808  movk     w8, #0xf940, lsl #16
//   0x2be8: 72bac3e9  movk     w9, #0xd61f, lsl #16
//   0x2bec: 72b3e00a  movk     w10, #0x9f00, lsl #16
//   0x2bf0: 52b2800b  mov      w11, #-0x6c000000
//   0x2bf4: 72b2200c  movk     w12, #0x9100, lsl #16
//   0x2bf8: 72b2000d  movk     w13, #0x9000, lsl #16
//   0x2bfc: f90007ee  str      x14, [sp, #8]
//   0x2c00: 5280060e  mov      w14, #0x30
//   0x2c04: 5280630f  mov      w15, #0x318
//   0x2c08: 91210231  add      x17, x17, #0x840
//   0x2c0c: 4e080c50  dup      v16.2d, x2
//   0x2c10: 529a0001  mov      w1, #0xd000
//   0x2c14: aa1503e4  mov      x4, x21
//   0x2c18: 1400000a  b        #0x2c40
//   0x2c1c: f94003ee  ldr      x14, [sp]
//   0x2c20: 5280630f  mov      w15, #0x318
//   0x2c24: f94001d5  ldr      x21, [x14]
//   0x2c28: b94009c7  ldr      w7, [x14, #8]
//   0x2c2c: 5280060e  mov      w14, #0x30
//   0x2c30: 910c6084  add      x4, x4, #0x318
//   0x2c34: 9baf54f0  umaddl   x16, w7, w15, x21
//   0x2c38: eb10009f  cmp      x4, x16
//   0x2c3c: 540031a2  b.hs     #0x3270
//   0x2c40: b9401490  ldr      w16, [x4, #0x14]
//   0x2c44: 91006085  add      x5, x4, #0x18
//   0x2c48: 9b0e1606  madd     x6, x16, x14, x5
//   0x2c4c: d100c0d0  sub      x16, x6, #0x30
//   0x2c50: eb05021f  cmp      x16, x5
//   0x2c54: 540000a2  b.hs     #0x2c68
//   0x2c58: 17fffff6  b        #0x2c30
//   0x2c5c: d100c0d0  sub      x16, x6, #0x30
//   0x2c60: eb05021f  cmp      x16, x5
//   0x2c64: 54fffdc3  b.lo     #0x2c1c
//   0x2c68: aa0603e3  mov      x3, x6
//   0x2c6c: aa1003e6  mov      x6, x16
//   0x2c70: 39400210  ldrb     w16, [x16]
//   0x2c74: 7100721f  cmp      w16, #0x1c
//   0x2c78: 54ffff28  b.hi     #0x2c5c
//   0x2c7c: 10ffff00  adr      x0, #0x2c5c
//   0x2c80: 78707a22  ldrh     w2, [x17, x16, lsl #1]
//   0x2c84: 8b020800  add      x0, x0, x2, lsl #2
//   0x2c88: d61f0000  br       x0
//   0x2c8c: f9400490  ldr      x16, [x4, #8]
//   0x2c90: a97d8860  ldp      x0, x2, [x3, #-0x28]
//   0x2c94: f85f8075  ldur     x21, [x3, #-8]
//   0x2c98: a97e8c67  ldp      x7, x3, [x3, #-0x18]
//   0x2c9c: cb000210  sub      x16, x16, x0
//   0x2ca0: cb150215  sub      x21, x16, x21
//   0x2ca4: 8b0200f6  add      x22, x7, x2
//   0x2ca8: 8b0302d6  add      x22, x22, x3
//   0x2cac: eb1502df  cmp      x22, x21
//   0x2cb0: 54fffd68  b.hi     #0x2c5c
//   0x2cb4: f9400083  ldr      x3, [x4]
//   0x2cb8: f94007ee  ldr      x14, [sp, #8]
//   0x2cbc: 8b000058  add      x24, x2, x0
//   0x2cc0: aa1f03f7  mov      x23, xzr
//   0x2cc4: 8b03027a  add      x26, x19, x3
//   0x2cc8: 8b030303  add      x3, x24, x3
//   0x2ccc: 8b000340  add      x0, x26, x0
//   0x2cd0: 927ff8f0  and      x16, x7, #0xfffffffffffffffe
//   0x2cd4: 927cecf9  and      x25, x7, #0xfffffffffffffff0
//   0x2cd8: 8b02001a  add      x26, x0, x2
//   0x2cdc: 8b0301c2  add      x2, x14, x3
//   0x2ce0: aa1603fc  mov      x28, x22
//   0x2ce4: 14000006  b        #0x2cfc
//   0x2ce8: 8b16039c  add      x28, x28, x22
//   0x2cec: 8b160042  add      x2, x2, x22
//   0x2cf0: eb15039f  cmp      x28, x21
//   0x2cf4: 8b16035a  add      x26, x26, x22
//   0x2cf8: 54fffb28  b.hi     #0x2c5c
//   0x2cfc: b4ffff67  cbz      x7, #0x2ce8
//   0x2d00: f10004ff  cmp      x7, #1
//   0x2d04: 54000081  b.ne     #0x2d14
//   0x2d08: aa1f03f8  mov      x24, xzr
//   0x2d0c: aa1f03fe  mov      x30, xzr
//   0x2d10: 14000014  b        #0x2d60
//   0x2d14: aa1f03e0  mov      x0, xzr
//   0x2d18: aa1f03fe  mov      x30, xzr
//   0x2d1c: aa1f03e3  mov      x3, xzr
//   0x2d20: aa0203fb  mov      x27, x2
//   0x2d24: aa1003f8  mov      x24, x16
//   0x2d28: 385ff36f  ldurb    w15, [x27, #-1]
//   0x2d2c: 38402774  ldrb     w20, [x27], #2
//   0x2d30: 9100200e  add      x14, x0, #8
//   0x2d34: f1000b18  subs     x24, x24, #2
//   0x2d38: 9ac021ef  lsl      x15, x15, x0
//   0x2d3c: 9ace228e  lsl      x14, x20, x14
//   0x2d40: 91004000  add      x0, x0, #0x10
//   0x2d44: aa1e01fe  orr      x30, x15, x30
//   0x2d48: aa0301c3  orr      x3, x14, x3
//   0x2d4c: 54fffee1  b.ne     #0x2d28
//   0x2d50: eb07021f  cmp      x16, x7
//   0x2d54: aa1e007e  orr      x30, x3, x30
//   0x2d58: aa1003f8  mov      x24, x16
//   0x2d5c: 54000140  b.eq     #0x2d84
//   0x2d60: cb1800e0  sub      x0, x7, x24
//   0x2d64: d37df303  lsl      x3, x24, #3
//   0x2d68: 8b180358  add      x24, x26, x24
//   0x2d6c: 3840170e  ldrb     w14, [x24], #1
//   0x2d70: f1000400  subs     x0, x0, #1
//   0x2d74: 9ac321ce  lsl      x14, x14, x3
//   0x2d78: aa1e01de  orr      x30, x14, x30
//   0x2d7c: 91002063  add      x3, x3, #8
//   0x2d80: 54ffff61  b.ne     #0x2d6c
//   0x2d84: 8b1703d7  add      x23, x30, x23
//   0x2d88: b4fffb07  cbz      x7, #0x2ce8
//   0x2d8c: f10040ff  cmp      x7, #0x10
//   0x2d90: 54000062  b.hs     #0x2d9c
//   0x2d94: aa1f03e0  mov      x0, xzr
//   0x2d98: 14000040  b        #0x2e98
//   0x2d9c: aa1f03fe  mov      x30, xzr
//   0x2da0: 4e080ef1  dup      v17.2d, x23
//   0x2da4: 4ea71cf2  mov      v18.16b, v7.16b
//   0x2da8: 4ea61cd3  mov      v19.16b, v6.16b
//   0x2dac: 4ea51cb4  mov      v20.16b, v5.16b
//   0x2db0: 4ea41c95  mov      v21.16b, v4.16b
//   0x2db4: 4ea31c76  mov      v22.16b, v3.16b
//   0x2db8: 4ea21c57  mov      v23.16b, v2.16b
//   0x2dbc: 4ea11c38  mov      v24.16b, v1.16b
//   0x2dc0: 4ea01c19  mov      v25.16b, v0.16b
//   0x2dc4: 4f43569a  shl      v26.2d, v20.2d, #3
//   0x2dc8: 4f43565c  shl      v28.2d, v18.2d, #3
//   0x2dcc: 4f4356bb  shl      v27.2d, v21.2d, #3
//   0x2dd0: 4f43567d  shl      v29.2d, v19.2d, #3
//   0x2dd4: 6ee0bb9c  neg      v28.2d, v28.2d
//   0x2dd8: 6ee0bb5a  neg      v26.2d, v26.2d
//   0x2ddc: 4f43571e  shl      v30.2d, v24.2d, #3
//   0x2de0: 4f4356c8  shl      v8.2d, v22.2d, #3
//   0x2de4: 6ee0bbbd  neg      v29.2d, v29.2d
//   0x2de8: 6ee0bb7b  neg      v27.2d, v27.2d
//   0x2dec: 6efc463c  ushl     v28.2d, v17.2d, v28.2d
//   0x2df0: 6efa463a  ushl     v26.2d, v17.2d, v26.2d
//   0x2df4: 4f43573f  shl      v31.2d, v25.2d, #3
//   0x2df8: 4f4356e9  shl      v9.2d, v23.2d, #3
//   0x2dfc: 6ee0b908  neg      v8.2d, v8.2d
//   0x2e00: 6ee0bbde  neg      v30.2d, v30.2d
//   0x2e04: 6efd463d  ushl     v29.2d, v17.2d, v29.2d
//   0x2e08: 6efb463b  ushl     v27.2d, v17.2d, v27.2d
//   0x2e0c: 0ea12b5a  xtn      v26.2s, v26.2d
//   0x2e10: 0ea12b9c  xtn      v28.2s, v28.2d
//   0x2e14: 6ee0b929  neg      v9.2d, v9.2d
//   0x2e18: 6ee0bbff  neg      v31.2d, v31.2d
//   0x2e1c: 6ee84628  ushl     v8.2d, v17.2d, v8.2d
//   0x2e20: 6efe463e  ushl     v30.2d, v17.2d, v30.2d
//   0x2e24: 4ea12b7a  xtn2     v26.4s, v27.2d
//   0x2e28: 4ea12bbc  xtn2     v28.4s, v29.2d
//   0x2e2c: 6ee94629  ushl     v9.2d, v17.2d, v9.2d
//   0x2e30: 6eff463f  ushl     v31.2d, v17.2d, v31.2d
//   0x2e34: 0ea12bde  xtn      v30.2s, v30.2d
//   0x2e38: 0ea12908  xtn      v8.2s, v8.2d
//   0x2e3c: 0e612b9b  xtn      v27.4h, v28.4s
//   0x2e40: 4e612b5b  xtn2     v27.8h, v26.4s
//   0x2e44: 4ea12bfe  xtn2     v30.4s, v31.2d
//   0x2e48: 4ea12928  xtn2     v8.4s, v9.2d
//   0x2e4c: 0e212b7a  xtn      v26.8b, v27.8h
//   0x2e50: 0e61291b  xtn      v27.4h, v8.4s
//   0x2e54: 4e612bdb  xtn2     v27.8h, v30.4s
//   0x2e58: 4e212b7a  xtn2     v26.16b, v27.8h
//   0x2e5c: 3cbe6b5a  str      q26, [x26, x30]
//   0x2e60: 910043de  add      x30, x30, #0x10
//   0x2e64: 4ef08694  add      v20.2d, v20.2d, v16.2d
//   0x2e68: 4ef08673  add      v19.2d, v19.2d, v16.2d
//   0x2e6c: 4ef08652  add      v18.2d, v18.2d, v16.2d
//   0x2e70: 4ef086b5  add      v21.2d, v21.2d, v16.2d
//   0x2e74: 4ef086d6  add      v22.2d, v22.2d, v16.2d
//   0x2e78: 4ef086f7  add      v23.2d, v23.2d, v16.2d
//   0x2e7c: 4ef08718  add      v24.2d, v24.2d, v16.2d
//   0x2e80: eb1e033f  cmp      x25, x30
//   0x2e84: 4ef08739  add      v25.2d, v25.2d, v16.2d
//   0x2e88: 54fff9e1  b.ne     #0x2dc4
//   0x2e8c: eb07033f  cmp      x25, x7
//   0x2e90: aa1903e0  mov      x0, x25
//   0x2e94: 54fff2a0  b.eq     #0x2ce8
//   0x2e98: d37df003  lsl      x3, x0, #3
//   0x2e9c: 9ac326ee  lsr      x14, x23, x3
//   0x2ea0: 38206b4e  strb     w14, [x26, x0]
//   0x2ea4: 91000400  add      x0, x0, #1
//   0x2ea8: eb0000ff  cmp      x7, x0
//   0x2eac: 91002063  add      x3, x3, #8
//   0x2eb0: 54ffff61  b.ne     #0x2e9c
//   0x2eb4: 17ffff8d  b        #0x2ce8
//   0x2eb8: f9400487  ldr      x7, [x4, #8]
//   0x2ebc: f10010ff  cmp      x7, #4
//   0x2ec0: 54ffece3  b.lo     #0x2c5c
//   0x2ec4: f9400095  ldr      x21, [x4]
//   0x2ec8: aa1f03f7  mov      x23, xzr
//   0x2ecc: 8b150276  add      x22, x19, x21
//   0x2ed0: cb1503f8  neg      x24, x21
//   0x2ed4: b8776ac0  ldr      w0, [x22, x23]
//   0x2ed8: 1206140e  and      w14, w0, #0xfc000000
//   0x2edc: 6b0b01df  cmp      w14, w11
//   0x2ee0: 54000180  b.eq     #0x2f10
//   0x2ee4: 51007d4e  sub      w14, w10, #0x1f
//   0x2ee8: 0a0e000e  and      w14, w0, w14
//   0x2eec: 510041af  sub      w15, w13, #0x10
//   0x2ef0: 6b0f01df  cmp      w14, w15
//   0x2ef4: 54000160  b.eq     #0x2f20
//   0x2ef8: 910022ee  add      x14, x23, #8
//   0x2efc: 910012f7  add      x23, x23, #4
//   0x2f00: eb0701df  cmp      x14, x7
//   0x2f04: d1001318  sub      x24, x24, #4
//   0x2f08: 54fffe69  b.ls     #0x2ed4
//   0x2f0c: 17ffff54  b        #0x2c5c
//   0x2f10: 0b000b0e  add      w14, w24, w0, lsl #2
//   0x2f14: 53026dd0  ubfx     w16, w14, #2, #0x1a
//   0x2f18: 52b28000  mov      w0, #-0x6c000000
//   0x2f1c: 14000012  b        #0x2f64
//   0x2f20: d3517c0f  ubfx     x15, x0, #0x11, #0xf
//   0x2f24: d3455c0e  ubfx     x14, x0, #5, #0x13
//   0x2f28: 121405ef  and      w15, w15, #0x3000
//   0x2f2c: 52a00090  mov      w16, #0x40000
//   0x2f30: b37249cf  bfi      x15, x14, #0xe, #0x13
//   0x2f34: ea40161f  tst      x16, x0, lsr #5
//   0x2f38: b25f79ee  orr      x14, x15, #0xfffffffe00000000
//   0x2f3c: 9a8e01ee  csel     x14, x15, x14, eq
//   0x2f40: 8b1702af  add      x15, x21, x23
//   0x2f44: 9274cdef  and      x15, x15, #0xfffffffffffff000
//   0x2f48: cb0f01ce  sub      x14, x14, x15
//   0x2f4c: 530f39cf  lsl      w15, w14, #0x11
//   0x2f50: 0a0a0010  and      w16, w0, w10
//   0x2f54: d349fdce  lsr      x14, x14, #9
//   0x2f58: 120305ef  and      w15, w15, #0x60000000
//   0x2f5c: 2a1001f0  orr      w16, w15, w16
//   0x2f60: 121b49c0  and      w0, w14, #0xffffe0
//   0x2f64: 2a00020e  orr      w14, w16, w0
//   0x2f68: b8376ace  str      w14, [x22, x23]
//   0x2f6c: 17ffffe3  b        #0x2ef8
//   0x2f70: f9400487  ldr      x7, [x4, #8]
//   0x2f74: f10010ff  cmp      x7, #4
//   0x2f78: 54ffe723  b.lo     #0x2c5c
//   0x2f7c: f9400095  ldr      x21, [x4]
//   0x2f80: aa1f03f6  mov      x22, xzr
//   0x2f84: 8b150277  add      x23, x19, x21
//   0x2f88: 14000088  b        #0x31a8
//   0x2f8c: f9400487  ldr      x7, [x4, #8]
//   0x2f90: f10010ff  cmp      x7, #4
//   0x2f94: 54ffe643  b.lo     #0x2c5c
//   0x2f98: f9400095  ldr      x21, [x4]
//   0x2f9c: aa1f03f7  mov      x23, xzr
//   0x2fa0: 92800018  mov      x24, #-1
//   0x2fa4: 8b150276  add      x22, x19, x21
//   0x2fa8: 14000006  b        #0x2fc0
//   0x2fac: 910032f7  add      x23, x23, #0xc
//   0x2fb0: 910022ee  add      x14, x23, #8
//   0x2fb4: 910012f7  add      x23, x23, #4
//   0x2fb8: eb0701df  cmp      x14, x7
//   0x2fbc: 54ffe508  b.hi     #0x2c5c
//   0x2fc0: 910042ee  add      x14, x23, #0x10
//   0x2fc4: eb0701df  cmp      x14, x7
//   0x2fc8: 54ffff48  b.hi     #0x2fb0
//   0x2fcc: 8b1702d9  add      x25, x22, x23
//   0x2fd0: b9400320  ldr      w0, [x25]
//   0x2fd4: 0a0a000e  and      w14, w0, w10
//   0x2fd8: 6b0d01df  cmp      w14, w13
//   0x2fdc: 540003c1  b.ne     #0x3054
//   0x2fe0: b9400730  ldr      w16, [x25, #4]
//   0x2fe4: 120a4e0e  and      w14, w16, #0xffc003ff
//   0x2fe8: 6b0801df  cmp      w14, w8
//   0x2fec: 54fffe21  b.ne     #0x2fb0
//   0x2ff0: b9400b22  ldr      w2, [x25, #8]
//   0x2ff4: 120a4c4e  and      w14, w2, #0xffc003ff
//   0x2ff8: 6b0c01df  cmp      w14, w12
//   0x2ffc: 54fffda1  b.ne     #0x2fb0
//   0x3000: b9400f2e  ldr      w14, [x25, #0xc]
//   0x3004: 6b0901df  cmp      w14, w9
//   0x3008: 54fffd41  b.ne     #0x2fb0
//   0x300c: d3517c03  ubfx     x3, x0, #0x11, #0xf
//   0x3010: 52a00094  mov      w20, #0x40000
//   0x3014: d3455c0f  ubfx     x15, x0, #5, #0x13
//   0x3018: ea40169f  tst      x20, x0, lsr #5
//   0x301c: 530a5440  ubfx     w0, w2, #0xa, #0xc
//   0x3020: 12140462  and      w2, w3, #0x3000
//   0x3024: b37249e2  bfi      x2, x15, #0xe, #0x13
//   0x3028: 8b1502ee  add      x14, x23, x21
//   0x302c: b25f784f  orr      x15, x2, #0xfffffffe00000000
//   0x3030: d347fe10  lsr      x16, x16, #7
//   0x3034: 9274cdce  and      x14, x14, #0xfffffffffffff000
//   0x3038: 9a8f004f  csel     x15, x2, x15, eq
//   0x303c: 927d2e10  and      x16, x16, #0x7ff8
//   0x3040: 8b0e01ee  add      x14, x15, x14
//   0x3044: 6b00021f  cmp      w16, w0
//   0x3048: 8b1001ce  add      x14, x14, x16
//   0x304c: 9a9801d8  csel     x24, x14, x24, eq
//   0x3050: 17ffffd7  b        #0x2fac
//   0x3054: 35fffae0  cbnz     w0, #0x2fb0
//   0x3058: b940072e  ldr      w14, [x25, #4]
//   0x305c: 35fffaae  cbnz     w14, #0x2fb0
//   0x3060: b9400b2e  ldr      w14, [x25, #8]
//   0x3064: 35fffa6e  cbnz     w14, #0x2fb0
//   0x3068: b9400f2e  ldr      w14, [x25, #0xc]
//   0x306c: 35fffa2e  cbnz     w14, #0x2fb0
//   0x3070: b100071f  cmn      x24, #1
//   0x3074: 54001100  b.eq     #0x3294
//   0x3078: 8b1502ee  add      x14, x23, x21
//   0x307c: 91002318  add      x24, x24, #8
//   0x3080: 9274cf0f  and      x15, x24, #0xfffffffffffff000
//   0x3084: 9274cdce  and      x14, x14, #0xfffffffffffff000
//   0x3088: cb0e01ee  sub      x14, x15, x14
//   0x308c: 12002f10  and      w16, w24, #0xfff
//   0x3090: 530c7dc0  lsr      w0, w14, #0xc
//   0x3094: d349fdce  lsr      x14, x14, #9
//   0x3098: 5319620f  lsl      w15, w16, #7
//   0x309c: 121b49ce  and      w14, w14, #0xffffe0
//   0x30a0: 121621ef  and      w15, w15, #0x7fc00
//   0x30a4: 3303080e  bfi      w14, w0, #0x1d, #3
//   0x30a8: 2a102990  orr      w16, w12, w16, lsl #10
//   0x30ac: 2a0801ef  orr      w15, w15, w8
//   0x30b0: 2a0d01ce  orr      w14, w14, w13
//   0x30b4: 29012730  stp      w16, w9, [x25, #8]
//   0x30b8: 29003f2e  stp      w14, w15, [x25]
//   0x30bc: 17ffffbc  b        #0x2fac
//   0x30c0: f9400483  ldr      x3, [x4, #8]
//   0x30c4: f100207f  cmp      x3, #8
//   0x30c8: 54ffdca3  b.lo     #0x2c5c
//   0x30cc: f940008e  ldr      x14, [x4]
//   0x30d0: aa1f03e2  mov      x2, xzr
//   0x30d4: 2a1f03e0  mov      w0, wzr
//   0x30d8: 8b0e0267  add      x7, x19, x14
//   0x30dc: 4b0e03f0  neg      w16, w14
//   0x30e0: b86268ee  ldr      w14, [x7, x2]
//   0x30e4: 9100404f  add      x15, x2, #0x10
//   0x30e8: eb0301ff  cmp      x15, x3
//   0x30ec: 0b0001c0  add      w0, w14, w0
//   0x30f0: 0b00020e  add      w14, w16, w0
//   0x30f4: 120079ce  and      w14, w14, #0x7fffffff
//   0x30f8: b82268ee  str      w14, [x7, x2]
//   0x30fc: 91002042  add      x2, x2, #8
//   0x3100: 51010210  sub      w16, w16, #0x40
//   0x3104: 54fffee9  b.ls     #0x30e0
//   0x3108: 17fffed5  b        #0x2c5c
//   0x310c: 52800022  mov      w2, #1
//   0x3110: 530d372e  ubfx     w14, w25, #0xd, #1
//   0x3114: 6a40284f  ands     w15, w2, w0, lsr #10
//   0x3118: 530b2f30  ubfx     w16, w25, #0xb, #1
//   0x311c: 6b0f01df  cmp      w14, w15
//   0x3120: 1a9f17ee  cset     w14, eq
//   0x3124: 6b0f021f  cmp      w16, w15
//   0x3128: 1200240f  and      w15, w0, #0x3ff
//   0x312c: 53144def  lsl      w15, w15, #0xc
//   0x3130: 1a9f17f0  cset     w16, eq
//   0x3134: 6a402840  ands     w0, w2, w0, lsr #10
//   0x3138: 33081c0f  bfi      w15, w0, #0x18, #8
//   0x313c: 331f2b2f  bfi      w15, w25, #1, #0xb
//   0x3140: 330901cf  bfi      w15, w14, #0x17, #1
//   0x3144: 330a020f  bfi      w15, w16, #0x16, #1
//   0x3148: 320719ee  orr      w14, w15, #0xfe000000
//   0x314c: 0b1502c0  add      w0, w22, w21
//   0x3150: 1a8e01ee  csel     w14, w15, w14, eq
//   0x3154: 4b0001ce  sub      w14, w14, w0
//   0x3158: 510011ce  sub      w14, w14, #4
//   0x315c: 531861cf  ubfx     w15, w14, #0x18, #1
//   0x3160: 53175dd0  ubfx     w16, w14, #0x17, #1
//   0x3164: 531659c0  ubfx     w0, w14, #0x16, #1
//   0x3168: 530c55c2  ubfx     w2, w14, #0xc, #0xa
//   0x316c: 53012dce  ubfx     w14, w14, #1, #0xb
//   0x3170: 4a0f0210  eor      w16, w16, w15
//   0x3174: 4a0f0000  eor      w0, w0, w15
//   0x3178: 331601e2  bfi      w2, w15, #0xa, #1
//   0x317c: 3313020e  bfi      w14, w16, #0xd, #1
//   0x3180: 32140c4f  orr      w15, w2, #0xf000
//   0x3184: 3315000e  bfi      w14, w0, #0xb, #1
//   0x3188: 7900030f  strh     w15, [x24]
//   0x318c: 521511ce  eor      w14, w14, #0xf800
//   0x3190: 91000ad6  add      x22, x22, #2
//   0x3194: 7900070e  strh     w14, [x24, #2]
//   0x3198: 91001ace  add      x14, x22, #6
//   0x319c: 91000ad6  add      x22, x22, #2
//   0x31a0: eb0701df  cmp      x14, x7
//   0x31a4: 54ffd5c8  b.hi     #0x2c5c
//   0x31a8: 8b1602f8  add      x24, x23, x22
//   0x31ac: 79400300  ldrh     w0, [x24]
//   0x31b0: 1215100e  and      w14, w0, #0xf800
//   0x31b4: 71403ddf  cmp      w14, #0xf, lsl #12
//   0x31b8: 54ffff01  b.ne     #0x3198
//   0x31bc: 79400719  ldrh     w25, [x24, #2]
//   0x31c0: 0a010330  and      w16, w25, w1
//   0x31c4: 7140361f  cmp      w16, #0xd, lsl #12
//   0x31c8: 54fffa20  b.eq     #0x310c
//   0x31cc: 7140321f  cmp      w16, #0xc, lsl #12
//   0x31d0: 54fffe41  b.ne     #0x3198
//   0x31d4: 52800023  mov      w3, #1
//   0x31d8: 530d372e  ubfx     w14, w25, #0xd, #1
//   0x31dc: 6a40286f  ands     w15, w3, w0, lsr #10
//   0x31e0: 530b2f30  ubfx     w16, w25, #0xb, #1
//   0x31e4: 6b0f01df  cmp      w14, w15
//   0x31e8: 1a9f17ee  cset     w14, eq
//   0x31ec: 6b0f021f  cmp      w16, w15
//   0x31f0: 1200240f  and      w15, w0, #0x3ff
//   0x31f4: 53144def  lsl      w15, w15, #0xc
//   0x31f8: 1a9f17f0  cset     w16, eq
//   0x31fc: 6a402860  ands     w0, w3, w0, lsr #10
//   0x3200: 53017f22  lsr      w2, w25, #1
//   0x3204: 33081c0f  bfi      w15, w0, #0x18, #8
//   0x3208: 331e244f  bfi      w15, w2, #2, #0xa
//   0x320c: 330901cf  bfi      w15, w14, #0x17, #1
//   0x3210: 0b1502c0  add      w0, w22, w21
//   0x3214: 330a020f  bfi      w15, w16, #0x16, #1
//   0x3218: 11001000  add      w0, w0, #4
//   0x321c: 320719ee  orr      w14, w15, #0xfe000000
//   0x3220: 121e7400  and      w0, w0, #0xfffffffc
//   0x3224: 1a8e01ee  csel     w14, w15, w14, eq
//   0x3228: 4b0001ce  sub      w14, w14, w0
//   0x322c: 531861cf  ubfx     w15, w14, #0x18, #1
//   0x3230: 53175dd0  ubfx     w16, w14, #0x17, #1
//   0x3234: 531659c0  ubfx     w0, w14, #0x16, #1
//   0x3238: 530c55c2  ubfx     w2, w14, #0xc, #0xa
//   0x323c: 53017dce  lsr      w14, w14, #1
//   0x3240: 4a0f0210  eor      w16, w16, w15
//   0x3244: 121f25ce  and      w14, w14, #0x7fe
//   0x3248: 4a0f0000  eor      w0, w0, w15
//   0x324c: 331601e2  bfi      w2, w15, #0xa, #1
//   0x3250: 3313020e  bfi      w14, w16, #0xd, #1
//   0x3254: 32140c4f  orr      w15, w2, #0xf000
//   0x3258: 3315000e  bfi      w14, w0, #0xb, #1
//   0x325c: 7900030f  strh     w15, [x24]
//   0x3260: 3300032e  bfxil    w14, w25, #0, #1
//   0x3264: 529d000f  mov      w15, #0xe800
//   0x3268: 4a0f01ce  eor      w14, w14, w15
//   0x326c: 17ffffc9  b        #0x3190
//   0x3270: a9474ff4  ldp      x20, x19, [sp, #0x70]
//   0x3274: a94657f6  ldp      x22, x21, [sp, #0x60]
//   0x3278: a9455ff8  ldp      x24, x23, [sp, #0x50]
//   0x327c: a94467fa  ldp      x26, x25, [sp, #0x40]
//   0x3280: a9436ffc  ldp      x28, x27, [sp, #0x30]
//   0x3284: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x3288: 6d4123e9  ldp      d9, d8, [sp, #0x10]
//   0x328c: 910203ff  add      sp, sp, #0x80
//   0x3290: d65f03c0  ret      
//   0x3294: 9400002f  bl       #0x3350
// ============================================================================

#include "komprese_decompressor.h"

#include <cstring>

namespace nextai {
namespace opencut {
namespace komprese {

namespace {

// EN: Exact AArch64 opcode templates loaded at 0x2bc4..0x2bf8:
//     w8  = 0xF9400211 (ldr x17, [x16])
//     w9  = 0xD61F0220 (br  x17)
//     w10 = 0x9F00001F (ADRP mask)
//     w11 = 0x94000000 (bl  #0)
//     w12 = 0x91000210 (add x16, x16, #0)
//     w13 = 0x90000010 (adrp x16, #0)
// VI: Các mẫu opcode AArch64 chính xác được nạp tại 0x2bc4..0x2bf8.
constexpr uint32_t kA64LdrX17FromX16 = 0xF9400211U;
constexpr uint32_t kA64BrX17         = 0xD61F0220U;
constexpr uint32_t kA64AdrpMask      = 0x9F000000U;
constexpr uint32_t kA64AdrpOpcode    = 0x90000000U;
constexpr uint32_t kA64BlOpcode      = 0x94000000U;
constexpr uint32_t kA64AddX16Base    = 0x91000210U;
constexpr uint32_t kA64AdrpX16Base   = 0x90000010U;

// EN: Sub-filter 0x2eb8..0x2f6c: AArch64 BL and ADRP PC-relative restoration.
// VI: Bộ lọc con 0x2eb8..0x2f6c: Khôi phục địa chỉ tương đối PC cho lệnh BL và ADRP AArch64.
void FilterAArch64BlAndAdrp(uint8_t* sec_ptr, uint64_t sec_offset, uint64_t sec_size) noexcept {
    if (sec_size < 4) return;
    for (uint64_t off = 0; off + 8 <= sec_size; off += 4) {
        uint32_t insn = 0;
        std::memcpy(&insn, sec_ptr + off, sizeof(uint32_t));
        uint32_t pc = static_cast<uint32_t>(sec_offset + off);

        if ((insn & 0xFC000000U) == kA64BlOpcode) {
            // 0x2f10..0x2f1c: Convert absolute word target back to PC-relative BL imm26
            uint32_t rel_bytes = (insn << 2) - pc;
            uint32_t imm26 = (rel_bytes >> 2) & 0x03FFFFFFU;
            uint32_t patched = kA64BlOpcode | imm26;
            std::memcpy(sec_ptr + off, &patched, sizeof(uint32_t));
        } else if ((insn & kA64AdrpMask) == kA64AdrpOpcode) {
            // 0x2f20..0x2f68: Extract 33-bit signed page address and subtract (sec_offset + off) & ~0xFFF
            uint64_t immlo = (insn >> 29) & 0x3ULL;
            uint64_t immhi = (insn >> 5) & 0x7FFFFULL;
            uint64_t abs_page = (immhi << 14) | (immlo << 12);
            if ((insn & (1U << 23)) != 0) {
                abs_page |= 0xFFFFFFFE00000000ULL;
            }
            uint64_t pc_page = (sec_offset + off) & ~0xFFFULL;
            uint64_t rel_page = abs_page - pc_page;
            uint32_t new_immlo = static_cast<uint32_t>((rel_page >> 12) & 0x3ULL) << 29;
            uint32_t new_immhi = static_cast<uint32_t>((rel_page >> 14) & 0x7FFFFULL) << 5;
            uint32_t rd = insn & 0x1FU;
            uint32_t patched = kA64AdrpOpcode | new_immlo | new_immhi | rd;
            std::memcpy(sec_ptr + off, &patched, sizeof(uint32_t));
        }
    }
}

// EN: Sub-filter 0x2f8c..0x30bc: AArch64 16-byte PLT stub reconstruction.
//     When a 16-byte PLT entry is zeroed (0,0,0,0) after a valid PLT entry,
//     synthesizes ADRP x16, LDR x17, [x16, #off], ADD x16, x16, #off, BR x17
//     advancing the GOT target pointer by +8 bytes (`add x24, x24, #8` at 0x307c).
// VI: Bộ lọc con 0x2f8c..0x30bc: Tái tạo PLT stub 16 byte trên AArch64.
void FilterAArch64PltStubs(uint8_t* sec_ptr, uint64_t sec_offset, uint64_t sec_size) noexcept {
    if (sec_size < 4) return;
    int64_t last_got_target = -1;
    uint64_t off = 0;
    while (off + 16 <= sec_size) {
        uint32_t w0 = 0, w1 = 0, w2 = 0, w3 = 0;
        std::memcpy(&w0, sec_ptr + off, 4);
        std::memcpy(&w1, sec_ptr + off + 4, 4);
        std::memcpy(&w2, sec_ptr + off + 8, 4);
        std::memcpy(&w3, sec_ptr + off + 12, 4);

        if ((w0 & 0x9F00001FU) == kA64AdrpX16Base &&
            (w1 & 0xFFC003FFU) == kA64LdrX17FromX16 &&
            (w2 & 0xFFC003FFU) == kA64AddX16Base &&
            w3 == kA64BrX17) {
            uint64_t immlo = (w0 >> 29) & 0x3ULL;
            uint64_t immhi = (w0 >> 5) & 0x7FFFFULL;
            int64_t page_delta = static_cast<int64_t>((immhi << 14) | (immlo << 12));
            if ((w0 & (1U << 23)) != 0) {
                page_delta |= static_cast<int64_t>(0xFFFFFFFE00000000ULL);
            }
            uint64_t pc_page = (sec_offset + off) & ~0xFFFULL;
            uint32_t ldr_off = ((w1 >> 10) & 0xFFFU) << 3;
            uint32_t add_off = (w2 >> 10) & 0xFFFU;
            if (ldr_off == add_off) {
                last_got_target = static_cast<int64_t>(pc_page) + page_delta + ldr_off;
            }
            off += 16;
        } else if (w0 == 0 && w1 == 0 && w2 == 0 && w3 == 0 && last_got_target != -1) {
            last_got_target += 8;
            uint64_t target_page = static_cast<uint64_t>(last_got_target) & ~0xFFFULL;
            uint64_t pc_page = (sec_offset + off) & ~0xFFFULL;
            uint64_t rel_page = target_page - pc_page;
            uint32_t page_off = static_cast<uint32_t>(last_got_target) & 0xFFFU;

            uint32_t new_w0 = kA64AdrpX16Base |
                              (static_cast<uint32_t>((rel_page >> 12) & 0x3U) << 29) |
                              (static_cast<uint32_t>((rel_page >> 14) & 0x7FFFFU) << 5);
            uint32_t new_w1 = kA64LdrX17FromX16 | (((page_off >> 3) & 0xFFFU) << 10);
            uint32_t new_w2 = kA64AddX16Base | (page_off << 10);
            uint32_t new_w3 = kA64BrX17;

            std::memcpy(sec_ptr + off, &new_w0, 4);
            std::memcpy(sec_ptr + off + 4, &new_w1, 4);
            std::memcpy(sec_ptr + off + 8, &new_w2, 4);
            std::memcpy(sec_ptr + off + 12, &new_w3, 4);
            off += 16;
        } else {
            off += 4;
        }
    }
}

// EN: Sub-filter 0x30c0..0x3108: 31-bit relative offset (Prel31) delta accumulator.
// VI: Bộ lọc con 0x30c0..0x3108: Bộ cộng dồn delta cho bảng con trỏ tương đối 31-bit (Prel31).
void FilterPrel31Table(uint8_t* sec_ptr, uint64_t sec_offset, uint64_t sec_size) noexcept {
    if (sec_size < 8) return;
    uint32_t running_acc = 0;
    uint32_t rel_bias = static_cast<uint32_t>(-static_cast<int32_t>(sec_offset));
    for (uint64_t off = 0; off + 16 <= sec_size; off += 8) {
        uint32_t val = 0;
        std::memcpy(&val, sec_ptr + off, sizeof(uint32_t));
        running_acc += val;
        uint32_t patched = (running_acc + rel_bias) & 0x7FFFFFFFU;
        std::memcpy(sec_ptr + off, &patched, sizeof(uint32_t));
        rel_bias -= 0x40U;
    }
}

// EN: Sub-filter 0x2f70..0x326c: ARM Thumb-2 32-bit BL (0xF000/0xD000) & BLX (0xF000/0xC000) BCJ filter.
// VI: Bộ lọc con 0x2f70..0x326c: Bộ lọc BCJ cho lệnh nhảy 32-bit BL & BLX của ARM Thumb-2.
void FilterThumb2BlAndBlx(uint8_t* sec_ptr, uint64_t sec_offset, uint64_t sec_size) noexcept {
    if (sec_size < 4) return;
    uint64_t off = 0;
    while (off + 6 <= sec_size) {
        uint16_t hw0 = 0, hw1 = 0;
        std::memcpy(&hw0, sec_ptr + off, 2);
        if ((hw0 & 0xF800U) != 0xF000U) {
            off += 2;
            continue;
        }
        std::memcpy(&hw1, sec_ptr + off + 2, 2);
        uint16_t op_type = hw1 & 0xD000U;
        if (op_type != 0xD000U && op_type != 0xC000U) {
            off += 2;
            continue;
        }
        uint32_t s  = (hw0 >> 10) & 1U;
        uint32_t j1 = (hw1 >> 13) & 1U;
        uint32_t j2 = (hw1 >> 11) & 1U;
        uint32_t i1 = ~(j1 ^ s) & 1U;
        uint32_t i2 = ~(j2 ^ s) & 1U;
        uint32_t imm10 = hw0 & 0x3FFU;
        uint32_t imm11 = hw1 & 0x7FFU;
        uint32_t target = (s << 24) | (i1 << 23) | (i2 << 22) | (imm10 << 12) | (imm11 << 1);
        if (s != 0) {
            target |= 0xFE000000U;
        }
        uint32_t pc = static_cast<uint32_t>(sec_offset + off + 4);
        if (op_type == 0xC000U) {
            pc &= ~0x3U;
        }
        uint32_t rel = target - pc;
        uint32_t ns  = (rel >> 24) & 1U;
        uint32_t ni1 = (rel >> 23) & 1U;
        uint32_t ni2 = (rel >> 22) & 1U;
        uint32_t nj1 = (~ni1 ^ ns) & 1U;
        uint32_t nj2 = (~ni2 ^ ns) & 1U;
        uint16_t new_hw0 = static_cast<uint16_t>(0xF000U | (ns << 10) | ((rel >> 12) & 0x3FFU));
        uint16_t new_hw1 = (op_type == 0xD000U)
            ? static_cast<uint16_t>(0xD000U | (nj1 << 13) | (nj2 << 11) | ((rel >> 1) & 0x7FFU))
            : static_cast<uint16_t>(0xC000U | (nj1 << 13) | (nj2 << 11) | ((rel >> 2) & 0x3FEU) | (hw1 & 1U));
        std::memcpy(sec_ptr + off, &new_hw0, 2);
        std::memcpy(sec_ptr + off + 2, &new_hw1, 2);
        off += 4;
    }
}

// EN: Sub-filter 0x2c8c..0x2eb4: Variable-width delta-coded relocation table filter.
// VI: Bộ lọc con 0x2c8c..0x2eb4: Bộ lọc bảng relocation mã hóa delta có độ rộng thay đổi.
void FilterDeltaRelocRecords(
    uint8_t* sec_ptr,
    uint64_t sec_size,
    const KompreseRelocPatchEntry& patch) noexcept {
    uint64_t start_off = patch.param0_offset;
    uint64_t prefix_skip = patch.param1_stride;
    uint64_t width = patch.param2_width;
    uint64_t tail_skip = patch.param3_extra;
    uint64_t end_margin = patch.param4_tail;

    if (start_off > sec_size || end_margin > (sec_size - start_off)) return;
    uint64_t limit = sec_size - start_off - end_margin;
    uint64_t stride = prefix_skip + width + tail_skip;
    if (stride == 0 || stride > limit || width == 0 || width > 8) return;

    uint64_t running_val = 0;
    for (uint64_t pos = start_off + prefix_skip; pos + width <= start_off + limit; pos += stride) {
        uint64_t delta = 0;
        for (uint64_t b = 0; b < width; ++b) {
            delta |= static_cast<uint64_t>(sec_ptr[pos + b]) << (b * 8);
        }
        running_val += delta;
        for (uint64_t b = 0; b < width; ++b) {
            sec_ptr[pos + b] = static_cast<uint8_t>((running_val >> (b * 8)) & 0xFFU);
        }
    }
}

}  // namespace

// EN: Exact reconstruction of FDE[08] (0x2b24..0x3294).
//     If final_out_buf != nullptr (0x2b4c..0x2b58), copies decompressed_buf into final_out_buf
//     first, then iterates over all sections and executes their patches in reverse order.
// VI: Tái tạo chính xác FDE[08] (0x2b24..0x3294).
//     Nếu final_out_buf != nullptr (0x2b4c..0x2b58), sao chép decompressed_buf sang final_out_buf
//     trước, sau đó duyệt qua mọi phân đoạn và thực thi các bản vá theo thứ tự ngược.
void KompreseApplyBcjAndRelocFilters(
    const KompreseStreamContext* ctx,
    uint8_t* decompressed_buf,
    size_t decompressed_size,
    uint8_t* final_out_buf) noexcept {
    if (ctx == nullptr) return;
    uint8_t* target_buf = decompressed_buf;
    if (final_out_buf != nullptr) {
        std::memcpy(final_out_buf, decompressed_buf, decompressed_size);
        target_buf = final_out_buf;
    }
    if (ctx->num_sections == 0 || ctx->sections == nullptr) {
        return;
    }

    for (uint32_t s = 0; s < ctx->num_sections; ++s) {
        const KompreseSectionDescriptor& sec = ctx->sections[s];
        if (sec.num_patches == 0 || sec.section_offset >= decompressed_size) {
            continue;
        }
        uint8_t* sec_ptr = target_buf + sec.section_offset;
        uint64_t sec_size = sec.section_size;
        if (sec.section_offset + sec_size > decompressed_size) {
            sec_size = decompressed_size - sec.section_offset;
        }

        uint32_t count = (sec.num_patches <= 16) ? sec.num_patches : 16;
        for (int32_t p = static_cast<int32_t>(count) - 1; p >= 0; --p) {
            const KompreseRelocPatchEntry& pe = sec.patches[p];
            switch (pe.patch_type) {
                case 0x00:
                case 0x01:
                case 0x18:
                    FilterDeltaRelocRecords(sec_ptr, sec_size, pe);
                    break;
                case 0x19:
                    FilterPrel31Table(sec_ptr, sec.section_offset, sec_size);
                    break;
                case 0x1A:
                    FilterThumb2BlAndBlx(sec_ptr, sec.section_offset, sec_size);
                    break;
                case 0x1B:
                    FilterAArch64BlAndAdrp(sec_ptr, sec.section_offset, sec_size);
                    break;
                case 0x1C:
                    FilterAArch64PltStubs(sec_ptr, sec.section_offset, sec_size);
                    break;
                default:
                    break;
            }
        }
    }
}

}  // namespace komprese
}  // namespace opencut
}  // namespace nextai
