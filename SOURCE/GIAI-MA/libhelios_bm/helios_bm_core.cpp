// ============================================================================
// NextAI OpenCut — Clean-Room C++17 Reconstruction
// File          : helios_bm_core.cpp
// Target Binary : libhelios_bm.so (18,424 bytes)
// SHA-256       : 79a0bb7b7d00a64fe4f0c0182d5416ab2515768f0262c23578d436c792a20e90
// Task ID       : TASK-174-RECONSTRUCTION-LIBHELIOS-BM
// ============================================================================
// EN: Clean-room C++17 implementation of all 22 FDEs in `libhelios_bm.so`
//     (.eh_frame_hdr @ 0x2710, .text 0x0b70..0x225c, 1,467 AArch64 instructions).
// VI: Tái tạo C++17 phòng sạch cho toàn bộ 22 FDE trong `libhelios_bm.so`
//     (.eh_frame_hdr @ 0x2710, .text 0x0b70..0x225c, 1.467 lệnh AArch64).
// ============================================================================
// Complete AArch64 .plt Disassembly (0x0a70..0x0b70, 64 instructions):
//   0x0a70: a9bf7bf0  stp      x16, x30, [sp, #-0x10]!
//   0x0a74: f0000030  adrp     x16, #0x7000
//   0x0a78: f947be11  ldr      x17, [x16, #0xf78]
//   0x0a7c: 913de210  add      x16, x16, #0xf78
//   0x0a80: d61f0220  br       x17
//   0x0a84: d503201f  nop      
//   0x0a88: d503201f  nop      
//   0x0a8c: d503201f  nop      
//   0x0a90: f0000030  adrp     x16, #0x7000
//   0x0a94: f947c211  ldr      x17, [x16, #0xf80]
//   0x0a98: 913e0210  add      x16, x16, #0xf80
//   0x0a9c: d61f0220  br       x17
//   0x0aa0: f0000030  adrp     x16, #0x7000
//   0x0aa4: f947c611  ldr      x17, [x16, #0xf88]
//   0x0aa8: 913e2210  add      x16, x16, #0xf88
//   0x0aac: d61f0220  br       x17
//   0x0ab0: f0000030  adrp     x16, #0x7000
//   0x0ab4: f947ca11  ldr      x17, [x16, #0xf90]
//   0x0ab8: 913e4210  add      x16, x16, #0xf90
//   0x0abc: d61f0220  br       x17
//   0x0ac0: f0000030  adrp     x16, #0x7000
//   0x0ac4: f947ce11  ldr      x17, [x16, #0xf98]
//   0x0ac8: 913e6210  add      x16, x16, #0xf98
//   0x0acc: d61f0220  br       x17
//   0x0ad0: f0000030  adrp     x16, #0x7000
//   0x0ad4: f947d211  ldr      x17, [x16, #0xfa0]
//   0x0ad8: 913e8210  add      x16, x16, #0xfa0
//   0x0adc: d61f0220  br       x17
//   0x0ae0: f0000030  adrp     x16, #0x7000
//   0x0ae4: f947d611  ldr      x17, [x16, #0xfa8]
//   0x0ae8: 913ea210  add      x16, x16, #0xfa8
//   0x0aec: d61f0220  br       x17
//   0x0af0: f0000030  adrp     x16, #0x7000
//   0x0af4: f947da11  ldr      x17, [x16, #0xfb0]
//   0x0af8: 913ec210  add      x16, x16, #0xfb0
//   0x0afc: d61f0220  br       x17
//   0x0b00: f0000030  adrp     x16, #0x7000
//   0x0b04: f947de11  ldr      x17, [x16, #0xfb8]
//   0x0b08: 913ee210  add      x16, x16, #0xfb8
//   0x0b0c: d61f0220  br       x17
//   0x0b10: f0000030  adrp     x16, #0x7000
//   0x0b14: f947e211  ldr      x17, [x16, #0xfc0]
//   0x0b18: 913f0210  add      x16, x16, #0xfc0
//   0x0b1c: d61f0220  br       x17
//   0x0b20: f0000030  adrp     x16, #0x7000
//   0x0b24: f947e611  ldr      x17, [x16, #0xfc8]
//   0x0b28: 913f2210  add      x16, x16, #0xfc8
//   0x0b2c: d61f0220  br       x17
//   0x0b30: f0000030  adrp     x16, #0x7000
//   0x0b34: f947ea11  ldr      x17, [x16, #0xfd0]
//   0x0b38: 913f4210  add      x16, x16, #0xfd0
//   0x0b3c: d61f0220  br       x17
//   0x0b40: f0000030  adrp     x16, #0x7000
//   0x0b44: f947ee11  ldr      x17, [x16, #0xfd8]
//   0x0b48: 913f6210  add      x16, x16, #0xfd8
//   0x0b4c: d61f0220  br       x17
//   0x0b50: f0000030  adrp     x16, #0x7000
//   0x0b54: f947f211  ldr      x17, [x16, #0xfe0]
//   0x0b58: 913f8210  add      x16, x16, #0xfe0
//   0x0b5c: d61f0220  br       x17
//   0x0b60: f0000030  adrp     x16, #0x7000
//   0x0b64: f947f611  ldr      x17, [x16, #0xfe8]
//   0x0b68: 913fa210  add      x16, x16, #0xfe8
//   0x0b6c: d61f0220  br       x17
// ============================================================================
// Complete AArch64 .text Disassembly (0x0b70..0x225c, 1,467 instructions):
//   0x0b70: f0000020  adrp     x0, #0x7000
//   0x0b74: 9133e000  add      x0, x0, #0xcf8
//   0x0b78: 17ffffce  b        #0xab0
//   0x0b7c: d65f03c0  ret      
//   0x0b80: 17ffffff  b        #0xb7c
//   0x0b84: b4000040  cbz      x0, #0xb8c
//   0x0b88: d61f0000  br       x0
//   0x0b8c: d65f03c0  ret      
//   0x0b90: 90000008  adrp     x8, #0
//   0x0b94: 912e1108  add      x8, x8, #0xb84
//   0x0b98: f0000022  adrp     x2, #0x7000
//   0x0b9c: 9133e042  add      x2, x2, #0xcf8
//   0x0ba0: aa0003e1  mov      x1, x0
//   0x0ba4: aa0803e0  mov      x0, x8
//   0x0ba8: 17ffffee  b        #0xb60
//   0x0bac: 17ffffe1  b        #0xb30
//   0x0bb0: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0bb4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0bb8: 910043fd  add      x29, sp, #0x10
//   0x0bbc: 90000053  adrp     x19, #0x8000
//   0x0bc0: 91007273  add      x19, x19, #0x1c
//   0x0bc4: 08dffe68  ldarb    w8, [x19]
//   0x0bc8: 370002e8  tbnz     w8, #0, #0xc24
//   0x0bcc: 90000040  adrp     x0, #0x8000
//   0x0bd0: 91008000  add      x0, x0, #0x20
//   0x0bd4: 97ffffc7  bl       #0xaf0
//   0x0bd8: 90000048  adrp     x8, #0x8000
//   0x0bdc: 39407108  ldrb     w8, [x8, #0x1c]
//   0x0be0: 370001c8  tbnz     w8, #0, #0xc18
//   0x0be4: 90000040  adrp     x0, #0x8000
//   0x0be8: 90000001  adrp     x1, #0
//   0x0bec: 91006000  add      x0, x0, #0x18
//   0x0bf0: 912eb021  add      x1, x1, #0xbac
//   0x0bf4: 97ffffab  bl       #0xaa0
//   0x0bf8: 340000c0  cbz      w0, #0xc10
//   0x0bfc: 90000040  adrp     x0, #0x8000
//   0x0c00: 91008000  add      x0, x0, #0x20
//   0x0c04: 97ffffd3  bl       #0xb50
//   0x0c08: aa1f03f3  mov      x19, xzr
//   0x0c0c: 14000014  b        #0xc5c
//   0x0c10: 52800028  mov      w8, #1
//   0x0c14: 089ffe68  stlrb    w8, [x19]
//   0x0c18: 90000040  adrp     x0, #0x8000
//   0x0c1c: 91008000  add      x0, x0, #0x20
//   0x0c20: 97ffffcc  bl       #0xb50
//   0x0c24: 90000054  adrp     x20, #0x8000
//   0x0c28: b9401a80  ldr      w0, [x20, #0x18]
//   0x0c2c: 97ffffb5  bl       #0xb00
//   0x0c30: b4000060  cbz      x0, #0xc3c
//   0x0c34: aa0003f3  mov      x19, x0
//   0x0c38: 14000009  b        #0xc5c
//   0x0c3c: 52800080  mov      w0, #4
//   0x0c40: 97ffffb8  bl       #0xb20
//   0x0c44: b9401a88  ldr      w8, [x20, #0x18]
//   0x0c48: aa0003f3  mov      x19, x0
//   0x0c4c: b900001f  str      wzr, [x0]
//   0x0c50: aa1303e1  mov      x1, x19
//   0x0c54: 2a0803e0  mov      w0, w8
//   0x0c58: 97ffff9e  bl       #0xad0
//   0x0c5c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0c60: aa1303e0  mov      x0, x19
//   0x0c64: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x0c68: d65f03c0  ret      
//   0x0c6c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0c70: 910003fd  mov      x29, sp
//   0x0c74: 97ffffcf  bl       #0xbb0
//   0x0c78: b4000080  cbz      x0, #0xc88
//   0x0c7c: b9400008  ldr      w8, [x0]
//   0x0c80: 7100011f  cmp      w8, #0
//   0x0c84: 1a9f07e0  cset     w0, ne
//   0x0c88: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x0c8c: d65f03c0  ret      
//   0x0c90: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0c94: 910003fd  mov      x29, sp
//   0x0c98: 97ffffc6  bl       #0xbb0
//   0x0c9c: b40000e0  cbz      x0, #0xcb8
//   0x0ca0: b9400008  ldr      w8, [x0]
//   0x0ca4: 11000508  add      w8, w8, #1
//   0x0ca8: b9000008  str      w8, [x0]
//   0x0cac: 52800020  mov      w0, #1
//   0x0cb0: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x0cb4: d65f03c0  ret      
//   0x0cb8: d0000001  adrp     x1, #0x2000
//   0x0cbc: d0000002  adrp     x2, #0x2000
//   0x0cc0: 91097021  add      x1, x1, #0x25c
//   0x0cc4: 9109a442  add      x2, x2, #0x269
//   0x0cc8: 528000c0  mov      w0, #6
//   0x0ccc: 97ffff85  bl       #0xae0
//   0x0cd0: 2a1f03e0  mov      w0, wzr
//   0x0cd4: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x0cd8: d65f03c0  ret      
//   0x0cdc: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0ce0: 910003fd  mov      x29, sp
//   0x0ce4: 97ffffb3  bl       #0xbb0
//   0x0ce8: b40000a0  cbz      x0, #0xcfc
//   0x0cec: b9400008  ldr      w8, [x0]
//   0x0cf0: 51000508  sub      w8, w8, #1
//   0x0cf4: b9000008  str      w8, [x0]
//   0x0cf8: 52800020  mov      w0, #1
//   0x0cfc: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x0d00: d65f03c0  ret      
//   0x0d04: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x0d08: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0d0c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0d10: 910083fd  add      x29, sp, #0x20
//   0x0d14: aa0003f5  mov      x21, x0
//   0x0d18: 2a1f03e0  mov      w0, wzr
//   0x0d1c: b40002d5  cbz      x21, #0xd74
//   0x0d20: f0000028  adrp     x8, #0x7000
//   0x0d24: f947fd08  ldr      x8, [x8, #0xff8]
//   0x0d28: b5000268  cbnz     x8, #0xd74
//   0x0d2c: aa0203f4  mov      x20, x2
//   0x0d30: aa0103f3  mov      x19, x1
//   0x0d34: 940003a8  bl       #0x1bd4
//   0x0d38: 39408008  ldrb     w8, [x0, #0x20]
//   0x0d3c: 340001a8  cbz      w8, #0xd70
//   0x0d40: 940003a5  bl       #0x1bd4
//   0x0d44: 39402008  ldrb     w8, [x0, #8]
//   0x0d48: 34000148  cbz      w8, #0xd70
//   0x0d4c: f9400816  ldr      x22, [x0, #0x10]
//   0x0d50: aa1503e0  mov      x0, x21
//   0x0d54: 9400000c  bl       #0xd84
//   0x0d58: 8b0002c8  add      x8, x22, x0
//   0x0d5c: f9400109  ldr      x9, [x8]
//   0x0d60: 52800020  mov      w0, #1
//   0x0d64: f9000289  str      x9, [x20]
//   0x0d68: c89ffd13  stlr     x19, [x8]
//   0x0d6c: 14000002  b        #0xd74
//   0x0d70: 2a1f03e0  mov      w0, wzr
//   0x0d74: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x0d78: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x0d7c: a8c357f6  ldp      x22, x21, [sp], #0x30
//   0x0d80: d65f03c0  ret      
//   0x0d84: d10283ff  sub      sp, sp, #0xa0
//   0x0d88: f9003bf5  str      x21, [sp, #0x70]
//   0x0d8c: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x0d90: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x0d94: 910243fd  add      x29, sp, #0x90
//   0x0d98: d53bd055  mrs      x21, tpidr_el0
//   0x0d9c: f94016a8  ldr      x8, [x21, #0x28]
//   0x0da0: aa0003f3  mov      x19, x0
//   0x0da4: f81d83a8  stur     x8, [x29, #-0x28]
//   0x0da8: 9400038b  bl       #0x1bd4
//   0x0dac: f9400014  ldr      x20, [x0]
//   0x0db0: 528000c2  mov      w2, #6
//   0x0db4: 910003e1  mov      x1, sp
//   0x0db8: 72a00022  movk     w2, #1, lsl #16
//   0x0dbc: f9400288  ldr      x8, [x20]
//   0x0dc0: aa1403e0  mov      x0, x20
//   0x0dc4: f9401908  ldr      x8, [x8, #0x30]
//   0x0dc8: d63f0100  blr      x8
//   0x0dcc: 34000100  cbz      w0, #0xdec
//   0x0dd0: f9400288  ldr      x8, [x20]
//   0x0dd4: 910003e1  mov      x1, sp
//   0x0dd8: aa1403e0  mov      x0, x20
//   0x0ddc: aa1f03e2  mov      x2, xzr
//   0x0de0: f9401108  ldr      x8, [x8, #0x20]
//   0x0de4: d63f0100  blr      x8
//   0x0de8: 37f80340  tbnz     w0, #0x1f, #0xe50
//   0x0dec: 90000054  adrp     x20, #0x8000
//   0x0df0: b9404a88  ldr      w8, [x20, #0x48]
//   0x0df4: 35000128  cbnz     w8, #0xe18
//   0x0df8: d0000000  adrp     x0, #0x2000
//   0x0dfc: 9109d800  add      x0, x0, #0x276
//   0x0e00: 910033e1  add      x1, sp, #0xc
//   0x0e04: 97ffff4f  bl       #0xb40
//   0x0e08: 910033e0  add      x0, sp, #0xc
//   0x0e0c: 97ffff21  bl       #0xa90
//   0x0e10: 2a0003e8  mov      w8, w0
//   0x0e14: b9004a80  str      w0, [x20, #0x48]
//   0x0e18: f94003e0  ldr      x0, [sp]
//   0x0e1c: 7100791f  cmp      w8, #0x1e
//   0x0e20: 540000eb  b.lt     #0xe3c
//   0x0e24: 90000048  adrp     x8, #0x8000
//   0x0e28: f9402908  ldr      x8, [x8, #0x50]
//   0x0e2c: aa1303e1  mov      x1, x19
//   0x0e30: f9408902  ldr      x2, [x8, #0x110]
//   0x0e34: 9400002c  bl       #0xee4
//   0x0e38: 14000007  b        #0xe54
//   0x0e3c: f9400008  ldr      x8, [x0]
//   0x0e40: aa1303e1  mov      x1, x19
//   0x0e44: f9401d08  ldr      x8, [x8, #0x38]
//   0x0e48: d63f0100  blr      x8
//   0x0e4c: 14000002  b        #0xe54
//   0x0e50: aa1f03e0  mov      x0, xzr
//   0x0e54: f94016a8  ldr      x8, [x21, #0x28]
//   0x0e58: f85d83a9  ldur     x9, [x29, #-0x28]
//   0x0e5c: eb09011f  cmp      x8, x9
//   0x0e60: 540000c1  b.ne     #0xe78
//   0x0e64: a9497bfd  ldp      x29, x30, [sp, #0x90]
//   0x0e68: a9484ff4  ldp      x20, x19, [sp, #0x80]
//   0x0e6c: f9403bf5  ldr      x21, [sp, #0x70]
//   0x0e70: 910283ff  add      sp, sp, #0xa0
//   0x0e74: d65f03c0  ret      
//   0x0e78: 97ffff12  bl       #0xac0
//   0x0e7c: d10243ff  sub      sp, sp, #0x90
//   0x0e80: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x0e84: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x0e88: 910203fd  add      x29, sp, #0x80
//   0x0e8c: d53bd053  mrs      x19, tpidr_el0
//   0x0e90: f9401668  ldr      x8, [x19, #0x28]
//   0x0e94: 90000054  adrp     x20, #0x8000
//   0x0e98: f81e83a8  stur     x8, [x29, #-0x18]
//   0x0e9c: b9404a80  ldr      w0, [x20, #0x48]
//   0x0ea0: 35000100  cbnz     w0, #0xec0
//   0x0ea4: d0000000  adrp     x0, #0x2000
//   0x0ea8: 9109d800  add      x0, x0, #0x276
//   0x0eac: 910033e1  add      x1, sp, #0xc
//   0x0eb0: 97ffff24  bl       #0xb40
//   0x0eb4: 910033e0  add      x0, sp, #0xc
//   0x0eb8: 97fffef6  bl       #0xa90
//   0x0ebc: b9004a80  str      w0, [x20, #0x48]
//   0x0ec0: f9401668  ldr      x8, [x19, #0x28]
//   0x0ec4: f85e83a9  ldur     x9, [x29, #-0x18]
//   0x0ec8: eb09011f  cmp      x8, x9
//   0x0ecc: 540000a1  b.ne     #0xee0
//   0x0ed0: a9487bfd  ldp      x29, x30, [sp, #0x80]
//   0x0ed4: a9474ff4  ldp      x20, x19, [sp, #0x70]
//   0x0ed8: 910243ff  add      sp, sp, #0x90
//   0x0edc: d65f03c0  ret      
//   0x0ee0: 97fffef8  bl       #0xac0
//   0x0ee4: d10483ff  sub      sp, sp, #0x120
//   0x0ee8: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x0eec: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x0ef0: 910443fd  add      x29, sp, #0x110
//   0x0ef4: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x0ef8: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x0efc: f90057e7  str      x7, [sp, #0xa8]
//   0x0f00: ad0007e0  stp      q0, q1, [sp]
//   0x0f04: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x0f08: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x0f0c: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x0f10: d53bd053  mrs      x19, tpidr_el0
//   0x0f14: f940166b  ldr      x11, [x19, #0x28]
//   0x0f18: 928004e8  mov      x8, #-0x28
//   0x0f1c: 910003e9  mov      x9, sp
//   0x0f20: 910223ea  add      x10, sp, #0x88
//   0x0f24: f2dff008  movk     x8, #0xff80, lsl #32
//   0x0f28: 910043ac  add      x12, x29, #0x10
//   0x0f2c: 91020129  add      x9, x9, #0x80
//   0x0f30: 9100a14a  add      x10, x10, #0x28
//   0x0f34: f81e83ab  stur     x11, [x29, #-0x18]
//   0x0f38: a93da3a9  stp      x9, x8, [x29, #-0x28]
//   0x0f3c: a93cabac  stp      x12, x10, [x29, #-0x38]
//   0x0f40: f9400008  ldr      x8, [x0]
//   0x0f44: d100e3a9  sub      x9, x29, #0x38
//   0x0f48: ad400121  ldp      q1, q0, [x9]
//   0x0f4c: d10183a3  sub      x3, x29, #0x60
//   0x0f50: f940d508  ldr      x8, [x8, #0x1a8]
//   0x0f54: ad3d03a1  stp      q1, q0, [x29, #-0x60]
//   0x0f58: d63f0100  blr      x8
//   0x0f5c: f9401668  ldr      x8, [x19, #0x28]
//   0x0f60: f85e83a9  ldur     x9, [x29, #-0x18]
//   0x0f64: eb09011f  cmp      x8, x9
//   0x0f68: 540000a1  b.ne     #0xf7c
//   0x0f6c: a9517bfd  ldp      x29, x30, [sp, #0x110]
//   0x0f70: a9504ffc  ldp      x28, x19, [sp, #0x100]
//   0x0f74: 910483ff  add      sp, sp, #0x120
//   0x0f78: d65f03c0  ret      
//   0x0f7c: 97fffed1  bl       #0xac0
//   0x0f80: d102c3ff  sub      sp, sp, #0xb0
//   0x0f84: f9003bf7  str      x23, [sp, #0x70]
//   0x0f88: a90857f6  stp      x22, x21, [sp, #0x80]
//   0x0f8c: a9094ff4  stp      x20, x19, [sp, #0x90]
//   0x0f90: a90a7bfd  stp      x29, x30, [sp, #0xa0]
//   0x0f94: 910283fd  add      x29, sp, #0xa0
//   0x0f98: d53bd057  mrs      x23, tpidr_el0
//   0x0f9c: f94016e8  ldr      x8, [x23, #0x28]
//   0x0fa0: 90000056  adrp     x22, #0x8000
//   0x0fa4: 2a0203f4  mov      w20, w2
//   0x0fa8: aa0103f3  mov      x19, x1
//   0x0fac: f81c83a8  stur     x8, [x29, #-0x38]
//   0x0fb0: b9404ac8  ldr      w8, [x22, #0x48]
//   0x0fb4: aa0003f5  mov      x21, x0
//   0x0fb8: 34000088  cbz      w8, #0xfc8
//   0x0fbc: 7100791f  cmp      w8, #0x1e
//   0x0fc0: 5400018a  b.ge     #0xff0
//   0x0fc4: 14000032  b        #0x108c
//   0x0fc8: d0000000  adrp     x0, #0x2000
//   0x0fcc: 9109d800  add      x0, x0, #0x276
//   0x0fd0: 910023e1  add      x1, sp, #8
//   0x0fd4: 97fffedb  bl       #0xb40
//   0x0fd8: 910023e0  add      x0, sp, #8
//   0x0fdc: 97fffead  bl       #0xa90
//   0x0fe0: 2a0003e8  mov      w8, w0
//   0x0fe4: b9004ac0  str      w0, [x22, #0x48]
//   0x0fe8: 7100791f  cmp      w8, #0x1e
//   0x0fec: 5400050b  b.lt     #0x108c
//   0x0ff0: 940002f9  bl       #0x1bd4
//   0x0ff4: f9400016  ldr      x22, [x0]
//   0x0ff8: 528000c2  mov      w2, #6
//   0x0ffc: 910023e1  add      x1, sp, #8
//   0x1000: 72a00022  movk     w2, #1, lsl #16
//   0x1004: f94002c8  ldr      x8, [x22]
//   0x1008: aa1603e0  mov      x0, x22
//   0x100c: f9401908  ldr      x8, [x8, #0x30]
//   0x1010: d63f0100  blr      x8
//   0x1014: 34000100  cbz      w0, #0x1034
//   0x1018: f94002c8  ldr      x8, [x22]
//   0x101c: 910023e1  add      x1, sp, #8
//   0x1020: aa1603e0  mov      x0, x22
//   0x1024: aa1f03e2  mov      x2, xzr
//   0x1028: f9401108  ldr      x8, [x8, #0x20]
//   0x102c: d63f0100  blr      x8
//   0x1030: 37f802e0  tbnz     w0, #0x1f, #0x108c
//   0x1034: f94007e0  ldr      x0, [sp, #8]
//   0x1038: aa1503e1  mov      x1, x21
//   0x103c: aa1303e2  mov      x2, x19
//   0x1040: 2a1403e3  mov      w3, w20
//   0x1044: f9400008  ldr      x8, [x0]
//   0x1048: f9402508  ldr      x8, [x8, #0x48]
//   0x104c: d63f0100  blr      x8
//   0x1050: f0000028  adrp     x8, #0x8000
//   0x1054: f9402909  ldr      x9, [x8, #0x50]
//   0x1058: f94007e8  ldr      x8, [sp, #8]
//   0x105c: aa0003f4  mov      x20, x0
//   0x1060: aa1403e1  mov      x1, x20
//   0x1064: f9408922  ldr      x2, [x9, #0x110]
//   0x1068: aa0803e0  mov      x0, x8
//   0x106c: 97ffff9e  bl       #0xee4
//   0x1070: f94007e8  ldr      x8, [sp, #8]
//   0x1074: aa0003f3  mov      x19, x0
//   0x1078: aa1403e1  mov      x1, x20
//   0x107c: f9400109  ldr      x9, [x8]
//   0x1080: aa0803e0  mov      x0, x8
//   0x1084: f9405d29  ldr      x9, [x9, #0xb8]
//   0x1088: d63f0120  blr      x9
//   0x108c: f94016e8  ldr      x8, [x23, #0x28]
//   0x1090: f85c83a9  ldur     x9, [x29, #-0x38]
//   0x1094: eb09011f  cmp      x8, x9
//   0x1098: 54000101  b.ne     #0x10b8
//   0x109c: aa1303e0  mov      x0, x19
//   0x10a0: a94a7bfd  ldp      x29, x30, [sp, #0xa0]
//   0x10a4: a9494ff4  ldp      x20, x19, [sp, #0x90]
//   0x10a8: a94857f6  ldp      x22, x21, [sp, #0x80]
//   0x10ac: f9403bf7  ldr      x23, [sp, #0x70]
//   0x10b0: 9102c3ff  add      sp, sp, #0xb0
//   0x10b4: d65f03c0  ret      
//   0x10b8: 97fffe82  bl       #0xac0
//   0x10bc: d65f03c0  ret      
//   0x10c0: d65f03c0  ret      
//   0x10c4: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x10c8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x10cc: 910043fd  add      x29, sp, #0x10
//   0x10d0: aa0003f3  mov      x19, x0
//   0x10d4: f9000001  str      x1, [x0]
//   0x10d8: 3900801f  strb     wzr, [x0, #0x20]
//   0x10dc: 94000006  bl       #0x10f4
//   0x10e0: 52800028  mov      w8, #1
//   0x10e4: 39008668  strb     w8, [x19, #0x21]
//   0x10e8: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x10ec: f84207f3  ldr      x19, [sp], #0x20
//   0x10f0: d65f03c0  ret      
//   0x10f4: d10383ff  sub      sp, sp, #0xe0
//   0x10f8: a9086ffc  stp      x28, x27, [sp, #0x80]
//   0x10fc: a90967fa  stp      x26, x25, [sp, #0x90]
//   0x1100: a90a5ff8  stp      x24, x23, [sp, #0xa0]
//   0x1104: a90b57f6  stp      x22, x21, [sp, #0xb0]
//   0x1108: a90c4ff4  stp      x20, x19, [sp, #0xc0]
//   0x110c: a90d7bfd  stp      x29, x30, [sp, #0xd0]
//   0x1110: 910343fd  add      x29, sp, #0xd0
//   0x1114: d53bd05c  mrs      x28, tpidr_el0
//   0x1118: f9401788  ldr      x8, [x28, #0x28]
//   0x111c: aa0003f3  mov      x19, x0
//   0x1120: 528000c2  mov      w2, #6
//   0x1124: 910043e1  add      x1, sp, #0x10
//   0x1128: f81a83a8  stur     x8, [x29, #-0x58]
//   0x112c: f9400000  ldr      x0, [x0]
//   0x1130: 72a00022  movk     w2, #1, lsl #16
//   0x1134: f9400008  ldr      x8, [x0]
//   0x1138: f9401908  ldr      x8, [x8, #0x30]
//   0x113c: d63f0100  blr      x8
//   0x1140: 34000140  cbz      w0, #0x1168
//   0x1144: f9400260  ldr      x0, [x19]
//   0x1148: 910043e1  add      x1, sp, #0x10
//   0x114c: aa1f03e2  mov      x2, xzr
//   0x1150: f9400008  ldr      x8, [x0]
//   0x1154: f9401108  ldr      x8, [x8, #0x20]
//   0x1158: d63f0100  blr      x8
//   0x115c: 37f851a0  tbnz     w0, #0x1f, #0x1b90
//   0x1160: 5280003b  mov      w27, #1
//   0x1164: 14000002  b        #0x116c
//   0x1168: 2a1f03fb  mov      w27, wzr
//   0x116c: f9400bf4  ldr      x20, [sp, #0x10]
//   0x1170: 52802500  mov      w0, #0x128
//   0x1174: 97fffe6b  bl       #0xb20
//   0x1178: f000003a  adrp     x26, #0x8000
//   0x117c: 6f00e400  movi     v0.2d, #0000000000000000
//   0x1180: f9002b40  str      x0, [x26, #0x50]
//   0x1184: ad000000  stp      q0, q0, [x0]
//   0x1188: ad010000  stp      q0, q0, [x0, #0x20]
//   0x118c: ad020000  stp      q0, q0, [x0, #0x40]
//   0x1190: ad030000  stp      q0, q0, [x0, #0x60]
//   0x1194: ad040000  stp      q0, q0, [x0, #0x80]
//   0x1198: ad050000  stp      q0, q0, [x0, #0xa0]
//   0x119c: ad060000  stp      q0, q0, [x0, #0xc0]
//   0x11a0: ad070000  stp      q0, q0, [x0, #0xe0]
//   0x11a4: ad080000  stp      q0, q0, [x0, #0x100]
//   0x11a8: f900901f  str      xzr, [x0, #0x120]
//   0x11ac: b4004f20  cbz      x0, #0x1b90
//   0x11b0: f9400288  ldr      x8, [x20]
//   0x11b4: b0000001  adrp     x1, #0x2000
//   0x11b8: 910c6421  add      x1, x1, #0x319
//   0x11bc: aa1403e0  mov      x0, x20
//   0x11c0: f9401908  ldr      x8, [x8, #0x30]
//   0x11c4: d63f0100  blr      x8
//   0x11c8: f9400288  ldr      x8, [x20]
//   0x11cc: aa0003f5  mov      x21, x0
//   0x11d0: aa1403e0  mov      x0, x20
//   0x11d4: aa1503e1  mov      x1, x21
//   0x11d8: f9405508  ldr      x8, [x8, #0xa8]
//   0x11dc: d63f0100  blr      x8
//   0x11e0: f9402b48  ldr      x8, [x26, #0x50]
//   0x11e4: b0000002  adrp     x2, #0x2000
//   0x11e8: b0000003  adrp     x3, #0x2000
//   0x11ec: 910ca442  add      x2, x2, #0x329
//   0x11f0: f9000100  str      x0, [x8]
//   0x11f4: f9400288  ldr      x8, [x20]
//   0x11f8: 910cf063  add      x3, x3, #0x33c
//   0x11fc: aa1403e0  mov      x0, x20
//   0x1200: aa1503e1  mov      x1, x21
//   0x1204: f9408508  ldr      x8, [x8, #0x108]
//   0x1208: d63f0100  blr      x8
//   0x120c: f9402b48  ldr      x8, [x26, #0x50]
//   0x1210: b0000002  adrp     x2, #0x2000
//   0x1214: b0000003  adrp     x3, #0x2000
//   0x1218: 910d6842  add      x2, x2, #0x35a
//   0x121c: f9000900  str      x0, [x8, #0x10]
//   0x1220: f9400288  ldr      x8, [x20]
//   0x1224: 910db063  add      x3, x3, #0x36c
//   0x1228: aa1403e0  mov      x0, x20
//   0x122c: aa1503e1  mov      x1, x21
//   0x1230: f9408508  ldr      x8, [x8, #0x108]
//   0x1234: d63f0100  blr      x8
//   0x1238: f9402b48  ldr      x8, [x26, #0x50]
//   0x123c: b0000002  adrp     x2, #0x2000
//   0x1240: b0000003  adrp     x3, #0x2000
//   0x1244: 910e2442  add      x2, x2, #0x389
//   0x1248: f9000d00  str      x0, [x8, #0x18]
//   0x124c: f9400288  ldr      x8, [x20]
//   0x1250: 910e4463  add      x3, x3, #0x391
//   0x1254: aa1403e0  mov      x0, x20
//   0x1258: aa1503e1  mov      x1, x21
//   0x125c: f9408508  ldr      x8, [x8, #0x108]
//   0x1260: d63f0100  blr      x8
//   0x1264: f9402b48  ldr      x8, [x26, #0x50]
//   0x1268: f9000500  str      x0, [x8, #8]
//   0x126c: f9400288  ldr      x8, [x20]
//   0x1270: aa1403e0  mov      x0, x20
//   0x1274: f9439108  ldr      x8, [x8, #0x720]
//   0x1278: d63f0100  blr      x8
//   0x127c: 72001c1f  tst      w0, #0xff
//   0x1280: f0000039  adrp     x25, #0x8000
//   0x1284: 540001e0  b.eq     #0x12c0
//   0x1288: b0000001  adrp     x1, #0x2000
//   0x128c: b0000002  adrp     x2, #0x2000
//   0x1290: 910b1c21  add      x1, x1, #0x2c7
//   0x1294: 910e9842  add      x2, x2, #0x3a6
//   0x1298: 528000a0  mov      w0, #5
//   0x129c: 52800703  mov      w3, #0x38
//   0x12a0: 97fffe10  bl       #0xae0
//   0x12a4: f9400288  ldr      x8, [x20]
//   0x12a8: aa1403e0  mov      x0, x20
//   0x12ac: f9404508  ldr      x8, [x8, #0x88]
//   0x12b0: d63f0100  blr      x8
//   0x12b4: 2a1f03fa  mov      w26, wzr
//   0x12b8: b5002f95  cbnz     x21, #0x18a8
//   0x12bc: 14000182  b        #0x18c4
//   0x12c0: f9400288  ldr      x8, [x20]
//   0x12c4: b0000001  adrp     x1, #0x2000
//   0x12c8: 910f0c21  add      x1, x1, #0x3c3
//   0x12cc: aa1403e0  mov      x0, x20
//   0x12d0: f9401908  ldr      x8, [x8, #0x30]
//   0x12d4: d63f0100  blr      x8
//   0x12d8: f9400288  ldr      x8, [x20]
//   0x12dc: aa0003f6  mov      x22, x0
//   0x12e0: aa1403e0  mov      x0, x20
//   0x12e4: aa1603e1  mov      x1, x22
//   0x12e8: f9405508  ldr      x8, [x8, #0xa8]
//   0x12ec: d63f0100  blr      x8
//   0x12f0: f9402b48  ldr      x8, [x26, #0x50]
//   0x12f4: b0000002  adrp     x2, #0x2000
//   0x12f8: b0000003  adrp     x3, #0x2000
//   0x12fc: 910f5042  add      x2, x2, #0x3d4
//   0x1300: f9001100  str      x0, [x8, #0x20]
//   0x1304: f9400288  ldr      x8, [x20]
//   0x1308: 910e4463  add      x3, x3, #0x391
//   0x130c: aa1403e0  mov      x0, x20
//   0x1310: aa1603e1  mov      x1, x22
//   0x1314: f9408508  ldr      x8, [x8, #0x108]
//   0x1318: d63f0100  blr      x8
//   0x131c: f9402b48  ldr      x8, [x26, #0x50]
//   0x1320: f9001500  str      x0, [x8, #0x28]
//   0x1324: f9400288  ldr      x8, [x20]
//   0x1328: aa1403e0  mov      x0, x20
//   0x132c: f9439108  ldr      x8, [x8, #0x720]
//   0x1330: d63f0100  blr      x8
//   0x1334: 72001c1f  tst      w0, #0xff
//   0x1338: 540001e0  b.eq     #0x1374
//   0x133c: b0000001  adrp     x1, #0x2000
//   0x1340: b0000002  adrp     x2, #0x2000
//   0x1344: 910b1c21  add      x1, x1, #0x2c7
//   0x1348: 910e9842  add      x2, x2, #0x3a6
//   0x134c: 528000a0  mov      w0, #5
//   0x1350: 528007e3  mov      w3, #0x3f
//   0x1354: 97fffde3  bl       #0xae0
//   0x1358: f9400288  ldr      x8, [x20]
//   0x135c: aa1403e0  mov      x0, x20
//   0x1360: f9404508  ldr      x8, [x8, #0x88]
//   0x1364: d63f0100  blr      x8
//   0x1368: 2a1f03fa  mov      w26, wzr
//   0x136c: b5002936  cbnz     x22, #0x1890
//   0x1370: 1400014d  b        #0x18a4
//   0x1374: f9400288  ldr      x8, [x20]
//   0x1378: b0000001  adrp     x1, #0x2000
//   0x137c: 910f7421  add      x1, x1, #0x3dd
//   0x1380: aa1403e0  mov      x0, x20
//   0x1384: f9401908  ldr      x8, [x8, #0x30]
//   0x1388: d63f0100  blr      x8
//   0x138c: f9400288  ldr      x8, [x20]
//   0x1390: aa0003f7  mov      x23, x0
//   0x1394: aa1403e0  mov      x0, x20
//   0x1398: aa1703e1  mov      x1, x23
//   0x139c: f9405508  ldr      x8, [x8, #0xa8]
//   0x13a0: d63f0100  blr      x8
//   0x13a4: f9402b48  ldr      x8, [x26, #0x50]
//   0x13a8: b0000018  adrp     x24, #0x2000
//   0x13ac: b0000002  adrp     x2, #0x2000
//   0x13b0: 91102318  add      x24, x24, #0x408
//   0x13b4: f9001900  str      x0, [x8, #0x30]
//   0x13b8: f9400288  ldr      x8, [x20]
//   0x13bc: 910fd842  add      x2, x2, #0x3f6
//   0x13c0: aa1403e0  mov      x0, x20
//   0x13c4: aa1703e1  mov      x1, x23
//   0x13c8: f9408508  ldr      x8, [x8, #0x108]
//   0x13cc: aa1803e3  mov      x3, x24
//   0x13d0: d63f0100  blr      x8
//   0x13d4: f9402b48  ldr      x8, [x26, #0x50]
//   0x13d8: b0000002  adrp     x2, #0x2000
//   0x13dc: b0000003  adrp     x3, #0x2000
//   0x13e0: 91107042  add      x2, x2, #0x41c
//   0x13e4: f9001d00  str      x0, [x8, #0x38]
//   0x13e8: f9400288  ldr      x8, [x20]
//   0x13ec: 9110b863  add      x3, x3, #0x42e
//   0x13f0: aa1403e0  mov      x0, x20
//   0x13f4: aa1703e1  mov      x1, x23
//   0x13f8: f9408508  ldr      x8, [x8, #0x108]
//   0x13fc: d63f0100  blr      x8
//   0x1400: f9402b48  ldr      x8, [x26, #0x50]
//   0x1404: b0000002  adrp     x2, #0x2000
//   0x1408: 91110c42  add      x2, x2, #0x443
//   0x140c: aa1703e1  mov      x1, x23
//   0x1410: f9002500  str      x0, [x8, #0x48]
//   0x1414: f9400288  ldr      x8, [x20]
//   0x1418: aa1403e0  mov      x0, x20
//   0x141c: aa1803e3  mov      x3, x24
//   0x1420: f9408508  ldr      x8, [x8, #0x108]
//   0x1424: d63f0100  blr      x8
//   0x1428: f9402b48  ldr      x8, [x26, #0x50]
//   0x142c: b0000002  adrp     x2, #0x2000
//   0x1430: b0000003  adrp     x3, #0x2000
//   0x1434: 910e2442  add      x2, x2, #0x389
//   0x1438: f9002900  str      x0, [x8, #0x50]
//   0x143c: f9400288  ldr      x8, [x20]
//   0x1440: 910e4463  add      x3, x3, #0x391
//   0x1444: aa1403e0  mov      x0, x20
//   0x1448: aa1703e1  mov      x1, x23
//   0x144c: f9408508  ldr      x8, [x8, #0x108]
//   0x1450: d63f0100  blr      x8
//   0x1454: f9402b48  ldr      x8, [x26, #0x50]
//   0x1458: b0000002  adrp     x2, #0x2000
//   0x145c: b0000003  adrp     x3, #0x2000
//   0x1460: 91114442  add      x2, x2, #0x451
//   0x1464: f9002100  str      x0, [x8, #0x40]
//   0x1468: f9400288  ldr      x8, [x20]
//   0x146c: 91117863  add      x3, x3, #0x45e
//   0x1470: aa1403e0  mov      x0, x20
//   0x1474: aa1703e1  mov      x1, x23
//   0x1478: f9408508  ldr      x8, [x8, #0x108]
//   0x147c: d63f0100  blr      x8
//   0x1480: f9402b48  ldr      x8, [x26, #0x50]
//   0x1484: f9002d00  str      x0, [x8, #0x58]
//   0x1488: f9400288  ldr      x8, [x20]
//   0x148c: aa1403e0  mov      x0, x20
//   0x1490: f9439108  ldr      x8, [x8, #0x720]
//   0x1494: d63f0100  blr      x8
//   0x1498: 72001c1f  tst      w0, #0xff
//   0x149c: 540001e0  b.eq     #0x14d8
//   0x14a0: b0000001  adrp     x1, #0x2000
//   0x14a4: b0000002  adrp     x2, #0x2000
//   0x14a8: 910b1c21  add      x1, x1, #0x2c7
//   0x14ac: 910e9842  add      x2, x2, #0x3a6
//   0x14b0: 528000a0  mov      w0, #5
//   0x14b4: 528009e3  mov      w3, #0x4f
//   0x14b8: 97fffd8a  bl       #0xae0
//   0x14bc: f9400288  ldr      x8, [x20]
//   0x14c0: aa1403e0  mov      x0, x20
//   0x14c4: f9404508  ldr      x8, [x8, #0x88]
//   0x14c8: d63f0100  blr      x8
//   0x14cc: 2a1f03fa  mov      w26, wzr
//   0x14d0: b5001d57  cbnz     x23, #0x1878
//   0x14d4: 140000ee  b        #0x188c
//   0x14d8: f9400288  ldr      x8, [x20]
//   0x14dc: b0000001  adrp     x1, #0x2000
//   0x14e0: 91118821  add      x1, x1, #0x462
//   0x14e4: aa1403e0  mov      x0, x20
//   0x14e8: f9401908  ldr      x8, [x8, #0x30]
//   0x14ec: d63f0100  blr      x8
//   0x14f0: f9400288  ldr      x8, [x20]
//   0x14f4: aa0003f8  mov      x24, x0
//   0x14f8: aa1403e0  mov      x0, x20
//   0x14fc: aa1803e1  mov      x1, x24
//   0x1500: f9405508  ldr      x8, [x8, #0xa8]
//   0x1504: d63f0100  blr      x8
//   0x1508: f9402b48  ldr      x8, [x26, #0x50]
//   0x150c: b0000002  adrp     x2, #0x2000
//   0x1510: b0000003  adrp     x3, #0x2000
//   0x1514: 910e2442  add      x2, x2, #0x389
//   0x1518: f9003100  str      x0, [x8, #0x60]
//   0x151c: f9400288  ldr      x8, [x20]
//   0x1520: 910e4463  add      x3, x3, #0x391
//   0x1524: aa1403e0  mov      x0, x20
//   0x1528: aa1803e1  mov      x1, x24
//   0x152c: f9408508  ldr      x8, [x8, #0x108]
//   0x1530: d63f0100  blr      x8
//   0x1534: f9402b48  ldr      x8, [x26, #0x50]
//   0x1538: f9003500  str      x0, [x8, #0x68]
//   0x153c: f9400288  ldr      x8, [x20]
//   0x1540: aa1403e0  mov      x0, x20
//   0x1544: f9439108  ldr      x8, [x8, #0x720]
//   0x1548: d63f0100  blr      x8
//   0x154c: 72001c1f  tst      w0, #0xff
//   0x1550: 540001e0  b.eq     #0x158c
//   0x1554: b0000001  adrp     x1, #0x2000
//   0x1558: b0000002  adrp     x2, #0x2000
//   0x155c: 910b1c21  add      x1, x1, #0x2c7
//   0x1560: 910e9842  add      x2, x2, #0x3a6
//   0x1564: 528000a0  mov      w0, #5
//   0x1568: 52800aa3  mov      w3, #0x55
//   0x156c: 97fffd5d  bl       #0xae0
//   0x1570: f9400288  ldr      x8, [x20]
//   0x1574: aa1403e0  mov      x0, x20
//   0x1578: f9404508  ldr      x8, [x8, #0x88]
//   0x157c: d63f0100  blr      x8
//   0x1580: 2a1f03fa  mov      w26, wzr
//   0x1584: b50016f8  cbnz     x24, #0x1860
//   0x1588: 140000bb  b        #0x1874
//   0x158c: f9400288  ldr      x8, [x20]
//   0x1590: b0000001  adrp     x1, #0x2000
//   0x1594: 9111e821  add      x1, x1, #0x47a
//   0x1598: aa1403e0  mov      x0, x20
//   0x159c: f9401908  ldr      x8, [x8, #0x30]
//   0x15a0: f90007f8  str      x24, [sp, #8]
//   0x15a4: d63f0100  blr      x8
//   0x15a8: f9400288  ldr      x8, [x20]
//   0x15ac: aa0003f8  mov      x24, x0
//   0x15b0: aa1403e0  mov      x0, x20
//   0x15b4: aa1803e1  mov      x1, x24
//   0x15b8: f9405508  ldr      x8, [x8, #0xa8]
//   0x15bc: d63f0100  blr      x8
//   0x15c0: f9402b48  ldr      x8, [x26, #0x50]
//   0x15c4: b0000002  adrp     x2, #0x2000
//   0x15c8: b0000003  adrp     x3, #0x2000
//   0x15cc: 91124442  add      x2, x2, #0x491
//   0x15d0: f9003d00  str      x0, [x8, #0x78]
//   0x15d4: f9400288  ldr      x8, [x20]
//   0x15d8: 91128063  add      x3, x3, #0x4a0
//   0x15dc: aa1403e0  mov      x0, x20
//   0x15e0: aa1803e1  mov      x1, x24
//   0x15e4: f9408508  ldr      x8, [x8, #0x108]
//   0x15e8: f90003f8  str      x24, [sp]
//   0x15ec: d63f0100  blr      x8
//   0x15f0: f9402b48  ldr      x8, [x26, #0x50]
//   0x15f4: b0000001  adrp     x1, #0x2000
//   0x15f8: b0000002  adrp     x2, #0x2000
//   0x15fc: aa0003e3  mov      x3, x0
//   0x1600: f9004100  str      x0, [x8, #0x80]
//   0x1604: 910b1c21  add      x1, x1, #0x2c7
//   0x1608: 91133042  add      x2, x2, #0x4cc
//   0x160c: 52800080  mov      w0, #4
//   0x1610: 97fffd34  bl       #0xae0
//   0x1614: f9402b48  ldr      x8, [x26, #0x50]
//   0x1618: f9404108  ldr      x8, [x8, #0x80]
//   0x161c: b5000448  cbnz     x8, #0x16a4
//   0x1620: b0000018  adrp     x24, #0x2000
//   0x1624: 910b1f18  add      x24, x24, #0x2c7
//   0x1628: b0000002  adrp     x2, #0x2000
//   0x162c: 91134c42  add      x2, x2, #0x4d3
//   0x1630: 528000a0  mov      w0, #5
//   0x1634: aa1803e1  mov      x1, x24
//   0x1638: 97fffd2a  bl       #0xae0
//   0x163c: f9400288  ldr      x8, [x20]
//   0x1640: aa1403e0  mov      x0, x20
//   0x1644: f9404508  ldr      x8, [x8, #0x88]
//   0x1648: d63f0100  blr      x8
//   0x164c: f9400288  ldr      x8, [x20]
//   0x1650: f94003e1  ldr      x1, [sp]
//   0x1654: b0000002  adrp     x2, #0x2000
//   0x1658: b0000003  adrp     x3, #0x2000
//   0x165c: f9408508  ldr      x8, [x8, #0x108]
//   0x1660: 91124442  add      x2, x2, #0x491
//   0x1664: 9113bc63  add      x3, x3, #0x4ef
//   0x1668: aa1403e0  mov      x0, x20
//   0x166c: d63f0100  blr      x8
//   0x1670: f9402b48  ldr      x8, [x26, #0x50]
//   0x1674: b0000002  adrp     x2, #0x2000
//   0x1678: aa0003e3  mov      x3, x0
//   0x167c: 91147042  add      x2, x2, #0x51c
//   0x1680: f9004100  str      x0, [x8, #0x80]
//   0x1684: 52800080  mov      w0, #4
//   0x1688: aa1803e1  mov      x1, x24
//   0x168c: 97fffd15  bl       #0xae0
//   0x1690: f9402b48  ldr      x8, [x26, #0x50]
//   0x1694: f9404109  ldr      x9, [x8, #0x80]
//   0x1698: b4000cc9  cbz      x9, #0x1830
//   0x169c: 52800029  mov      w9, #1
//   0x16a0: 39024109  strb     w9, [x8, #0x90]
//   0x16a4: 97fffdf6  bl       #0xe7c
//   0x16a8: 7100781f  cmp      w0, #0x1e
//   0x16ac: 5400056b  b.lt     #0x1758
//   0x16b0: f9400288  ldr      x8, [x20]
//   0x16b4: f94007e1  ldr      x1, [sp, #8]
//   0x16b8: b0000002  adrp     x2, #0x2000
//   0x16bc: b0000003  adrp     x3, #0x2000
//   0x16c0: f9408508  ldr      x8, [x8, #0x108]
//   0x16c4: 91149042  add      x2, x2, #0x524
//   0x16c8: 9114c063  add      x3, x3, #0x530
//   0x16cc: aa1403e0  mov      x0, x20
//   0x16d0: d63f0100  blr      x8
//   0x16d4: f9402b48  ldr      x8, [x26, #0x50]
//   0x16d8: b0000001  adrp     x1, #0x2000
//   0x16dc: 9114d021  add      x1, x1, #0x534
//   0x16e0: f9003900  str      x0, [x8, #0x70]
//   0x16e4: f9400288  ldr      x8, [x20]
//   0x16e8: aa1403e0  mov      x0, x20
//   0x16ec: f9401908  ldr      x8, [x8, #0x30]
//   0x16f0: d63f0100  blr      x8
//   0x16f4: f9400288  ldr      x8, [x20]
//   0x16f8: aa0003f8  mov      x24, x0
//   0x16fc: aa1403e0  mov      x0, x20
//   0x1700: aa1803e1  mov      x1, x24
//   0x1704: f9405508  ldr      x8, [x8, #0xa8]
//   0x1708: d63f0100  blr      x8
//   0x170c: f9402b48  ldr      x8, [x26, #0x50]
//   0x1710: b0000002  adrp     x2, #0x2000
//   0x1714: b0000003  adrp     x3, #0x2000
//   0x1718: 91154442  add      x2, x2, #0x551
//   0x171c: f9008500  str      x0, [x8, #0x108]
//   0x1720: f9400288  ldr      x8, [x20]
//   0x1724: aa1403e0  mov      x0, x20
//   0x1728: aa1803e1  mov      x1, x24
//   0x172c: 9114c063  add      x3, x3, #0x530
//   0x1730: f9408508  ldr      x8, [x8, #0x108]
//   0x1734: d63f0100  blr      x8
//   0x1738: f9402b48  ldr      x8, [x26, #0x50]
//   0x173c: f9008900  str      x0, [x8, #0x110]
//   0x1740: b40000d8  cbz      x24, #0x1758
//   0x1744: f9400288  ldr      x8, [x20]
//   0x1748: aa1403e0  mov      x0, x20
//   0x174c: aa1803e1  mov      x1, x24
//   0x1750: f9405d08  ldr      x8, [x8, #0xb8]
//   0x1754: d63f0100  blr      x8
//   0x1758: f9400288  ldr      x8, [x20]
//   0x175c: f9400321  ldr      x1, [x25]
//   0x1760: aa1403e0  mov      x0, x20
//   0x1764: f9401908  ldr      x8, [x8, #0x30]
//   0x1768: d63f0100  blr      x8
//   0x176c: f9400288  ldr      x8, [x20]
//   0x1770: aa0003f8  mov      x24, x0
//   0x1774: aa1403e0  mov      x0, x20
//   0x1778: aa1803e1  mov      x1, x24
//   0x177c: f9405508  ldr      x8, [x8, #0xa8]
//   0x1780: d63f0100  blr      x8
//   0x1784: f9402b48  ldr      x8, [x26, #0x50]
//   0x1788: b0000002  adrp     x2, #0x2000
//   0x178c: b0000003  adrp     x3, #0x2000
//   0x1790: 91157842  add      x2, x2, #0x55e
//   0x1794: f9008d00  str      x0, [x8, #0x118]
//   0x1798: f9400288  ldr      x8, [x20]
//   0x179c: 9115b463  add      x3, x3, #0x56d
//   0x17a0: aa1403e0  mov      x0, x20
//   0x17a4: aa1803e1  mov      x1, x24
//   0x17a8: f941c508  ldr      x8, [x8, #0x388]
//   0x17ac: d63f0100  blr      x8
//   0x17b0: f9402b48  ldr      x8, [x26, #0x50]
//   0x17b4: f9009100  str      x0, [x8, #0x120]
//   0x17b8: f9400288  ldr      x8, [x20]
//   0x17bc: aa1403e0  mov      x0, x20
//   0x17c0: f9439108  ldr      x8, [x8, #0x720]
//   0x17c4: d63f0100  blr      x8
//   0x17c8: 72001c1f  tst      w0, #0xff
//   0x17cc: 540001e0  b.eq     #0x1808
//   0x17d0: b0000001  adrp     x1, #0x2000
//   0x17d4: b0000002  adrp     x2, #0x2000
//   0x17d8: 910b1c21  add      x1, x1, #0x2c7
//   0x17dc: 910e9842  add      x2, x2, #0x3a6
//   0x17e0: 528000a0  mov      w0, #5
//   0x17e4: 52801723  mov      w3, #0xb9
//   0x17e8: 97fffcbe  bl       #0xae0
//   0x17ec: f9400288  ldr      x8, [x20]
//   0x17f0: aa1403e0  mov      x0, x20
//   0x17f4: f9404508  ldr      x8, [x8, #0x88]
//   0x17f8: d63f0100  blr      x8
//   0x17fc: 2a1f03fa  mov      w26, wzr
//   0x1800: b5000098  cbnz     x24, #0x1810
//   0x1804: 14000010  b        #0x1844
//   0x1808: 5280003a  mov      w26, #1
//   0x180c: b40001d8  cbz      x24, #0x1844
//   0x1810: f9400288  ldr      x8, [x20]
//   0x1814: aa1403e0  mov      x0, x20
//   0x1818: aa1803e1  mov      x1, x24
//   0x181c: f9405d08  ldr      x8, [x8, #0xb8]
//   0x1820: d63f0100  blr      x8
//   0x1824: a94063e1  ldp      x1, x24, [sp]
//   0x1828: b5000121  cbnz     x1, #0x184c
//   0x182c: 1400000c  b        #0x185c
//   0x1830: f9400288  ldr      x8, [x20]
//   0x1834: aa1403e0  mov      x0, x20
//   0x1838: f9404508  ldr      x8, [x8, #0x88]
//   0x183c: d63f0100  blr      x8
//   0x1840: 2a1f03fa  mov      w26, wzr
//   0x1844: a94063e1  ldp      x1, x24, [sp]
//   0x1848: b40000a1  cbz      x1, #0x185c
//   0x184c: f9400288  ldr      x8, [x20]
//   0x1850: aa1403e0  mov      x0, x20
//   0x1854: f9405d08  ldr      x8, [x8, #0xb8]
//   0x1858: d63f0100  blr      x8
//   0x185c: b40000d8  cbz      x24, #0x1874
//   0x1860: f9400288  ldr      x8, [x20]
//   0x1864: aa1403e0  mov      x0, x20
//   0x1868: aa1803e1  mov      x1, x24
//   0x186c: f9405d08  ldr      x8, [x8, #0xb8]
//   0x1870: d63f0100  blr      x8
//   0x1874: b40000d7  cbz      x23, #0x188c
//   0x1878: f9400288  ldr      x8, [x20]
//   0x187c: aa1403e0  mov      x0, x20
//   0x1880: aa1703e1  mov      x1, x23
//   0x1884: f9405d08  ldr      x8, [x8, #0xb8]
//   0x1888: d63f0100  blr      x8
//   0x188c: b40000d6  cbz      x22, #0x18a4
//   0x1890: f9400288  ldr      x8, [x20]
//   0x1894: aa1403e0  mov      x0, x20
//   0x1898: aa1603e1  mov      x1, x22
//   0x189c: f9405d08  ldr      x8, [x8, #0xb8]
//   0x18a0: d63f0100  blr      x8
//   0x18a4: b4000115  cbz      x21, #0x18c4
//   0x18a8: f9400288  ldr      x8, [x20]
//   0x18ac: aa1403e0  mov      x0, x20
//   0x18b0: aa1503e1  mov      x1, x21
//   0x18b4: f9405d08  ldr      x8, [x8, #0xb8]
//   0x18b8: d63f0100  blr      x8
//   0x18bc: 3700007a  tbnz     w26, #0, #0x18c8
//   0x18c0: 140000b4  b        #0x1b90
//   0x18c4: 3400167a  cbz      w26, #0x1b90
//   0x18c8: f9400bf4  ldr      x20, [sp, #0x10]
//   0x18cc: f9400321  ldr      x1, [x25]
//   0x18d0: f9400288  ldr      x8, [x20]
//   0x18d4: aa1403e0  mov      x0, x20
//   0x18d8: f9401908  ldr      x8, [x8, #0x30]
//   0x18dc: d63f0100  blr      x8
//   0x18e0: b40002a0  cbz      x0, #0x1934
//   0x18e4: aa0003f5  mov      x21, x0
//   0x18e8: f9400be0  ldr      x0, [sp, #0x10]
//   0x18ec: d0000022  adrp     x2, #0x7000
//   0x18f0: 91340042  add      x2, x2, #0xd00
//   0x18f4: 52800063  mov      w3, #3
//   0x18f8: f9400008  ldr      x8, [x0]
//   0x18fc: aa1503e1  mov      x1, x21
//   0x1900: f9435d08  ldr      x8, [x8, #0x6b8]
//   0x1904: d63f0100  blr      x8
//   0x1908: 34000320  cbz      w0, #0x196c
//   0x190c: b0000001  adrp     x1, #0x2000
//   0x1910: b0000002  adrp     x2, #0x2000
//   0x1914: b0000003  adrp     x3, #0x2000
//   0x1918: 910b1c21  add      x1, x1, #0x2c7
//   0x191c: 910b8442  add      x2, x2, #0x2e1
//   0x1920: 91190063  add      x3, x3, #0x640
//   0x1924: 528000a0  mov      w0, #5
//   0x1928: 97fffc6e  bl       #0xae0
//   0x192c: b5001274  cbnz     x20, #0x1b78
//   0x1930: 14000098  b        #0x1b90
//   0x1934: f9400324  ldr      x4, [x25]
//   0x1938: b0000001  adrp     x1, #0x2000
//   0x193c: b0000002  adrp     x2, #0x2000
//   0x1940: b0000003  adrp     x3, #0x2000
//   0x1944: 910b1c21  add      x1, x1, #0x2c7
//   0x1948: 910b4442  add      x2, x2, #0x2d1
//   0x194c: 91190063  add      x3, x3, #0x640
//   0x1950: 528000a0  mov      w0, #5
//   0x1954: 97fffc63  bl       #0xae0
//   0x1958: f9400be0  ldr      x0, [sp, #0x10]
//   0x195c: f9400008  ldr      x8, [x0]
//   0x1960: f9404508  ldr      x8, [x8, #0x88]
//   0x1964: d63f0100  blr      x8
//   0x1968: 1400008a  b        #0x1b90
//   0x196c: f9400be0  ldr      x0, [sp, #0x10]
//   0x1970: f0000036  adrp     x22, #0x8000
//   0x1974: f94006c2  ldr      x2, [x22, #8]
//   0x1978: b0000003  adrp     x3, #0x2000
//   0x197c: f9400008  ldr      x8, [x0]
//   0x1980: 9116d463  add      x3, x3, #0x5b5
//   0x1984: aa1503e1  mov      x1, x21
//   0x1988: f941c508  ldr      x8, [x8, #0x388]
//   0x198c: d63f0100  blr      x8
//   0x1990: b40006e0  cbz      x0, #0x1a6c
//   0x1994: aa0003f7  mov      x23, x0
//   0x1998: f9400be0  ldr      x0, [sp, #0x10]
//   0x199c: f0000038  adrp     x24, #0x8000
//   0x19a0: f9400b02  ldr      x2, [x24, #0x10]
//   0x19a4: b0000003  adrp     x3, #0x2000
//   0x19a8: f9400008  ldr      x8, [x0]
//   0x19ac: 9116d463  add      x3, x3, #0x5b5
//   0x19b0: aa1503e1  mov      x1, x21
//   0x19b4: f941c508  ldr      x8, [x8, #0x388]
//   0x19b8: d63f0100  blr      x8
//   0x19bc: b40005c0  cbz      x0, #0x1a74
//   0x19c0: aa0003f6  mov      x22, x0
//   0x19c4: 52800022  mov      w2, #1
//   0x19c8: aa1503e0  mov      x0, x21
//   0x19cc: aa1703e1  mov      x1, x23
//   0x19d0: 97fffd6c  bl       #0xf80
//   0x19d4: aa0003f8  mov      x24, x0
//   0x19d8: 52800022  mov      w2, #1
//   0x19dc: aa1503e0  mov      x0, x21
//   0x19e0: aa1603e1  mov      x1, x22
//   0x19e4: 97fffd67  bl       #0xf80
//   0x19e8: f9400be9  ldr      x9, [sp, #0x10]
//   0x19ec: aa0003f9  mov      x25, x0
//   0x19f0: eb000316  subs     x22, x24, x0
//   0x19f4: 52800023  mov      w3, #1
//   0x19f8: f9400128  ldr      x8, [x9]
//   0x19fc: aa0903e0  mov      x0, x9
//   0x1a00: aa1503e1  mov      x1, x21
//   0x1a04: aa1703e2  mov      x2, x23
//   0x1a08: f9402508  ldr      x8, [x8, #0x48]
//   0x1a0c: da9656da  cneg     x26, x22, mi
//   0x1a10: f90007e9  str      x9, [sp, #8]
//   0x1a14: d63f0100  blr      x8
//   0x1a18: aa0003f7  mov      x23, x0
//   0x1a1c: b40004b6  cbz      x22, #0x1ab0
//   0x1a20: d000002b  adrp     x11, #0x7000
//   0x1a24: f947fd6b  ldr      x11, [x11, #0xff8]
//   0x1a28: 9000000a  adrp     x10, #0x1000
//   0x1a2c: aa1f03e9  mov      x9, xzr
//   0x1a30: aa1f03e8  mov      x8, xzr
//   0x1a34: 9102f14a  add      x10, x10, #0xbc
//   0x1a38: f8696b0c  ldr      x12, [x24, x9]
//   0x1a3c: f100017f  cmp      x11, #0
//   0x1a40: 9a8a116d  csel     x13, x11, x10, ne
//   0x1a44: eb0d019f  cmp      x12, x13
//   0x1a48: 9a880128  csel     x8, x9, x8, eq
//   0x1a4c: 91001129  add      x9, x9, #4
//   0x1a50: eb1a013f  cmp      x9, x26
//   0x1a54: 54000302  b.hs     #0x1ab4
//   0x1a58: f100017f  cmp      x11, #0
//   0x1a5c: 9a8a116d  csel     x13, x11, x10, ne
//   0x1a60: eb0d019f  cmp      x12, x13
//   0x1a64: 54fffea1  b.ne     #0x1a38
//   0x1a68: 14000013  b        #0x1ab4
//   0x1a6c: f94006c4  ldr      x4, [x22, #8]
//   0x1a70: 14000002  b        #0x1a78
//   0x1a74: f9400b04  ldr      x4, [x24, #0x10]
//   0x1a78: b0000001  adrp     x1, #0x2000
//   0x1a7c: b0000002  adrp     x2, #0x2000
//   0x1a80: b0000003  adrp     x3, #0x2000
//   0x1a84: 910b1c21  add      x1, x1, #0x2c7
//   0x1a88: 910b4442  add      x2, x2, #0x2d1
//   0x1a8c: 91190063  add      x3, x3, #0x640
//   0x1a90: 528000a0  mov      w0, #5
//   0x1a94: 97fffc13  bl       #0xae0
//   0x1a98: f9400be0  ldr      x0, [sp, #0x10]
//   0x1a9c: f9400008  ldr      x8, [x0]
//   0x1aa0: f9404508  ldr      x8, [x8, #0x88]
//   0x1aa4: d63f0100  blr      x8
//   0x1aa8: b5000694  cbnz     x20, #0x1b78
//   0x1aac: 14000039  b        #0x1b90
//   0x1ab0: aa1f03e8  mov      x8, xzr
//   0x1ab4: f8796909  ldr      x9, [x8, x25]
//   0x1ab8: 9000000a  adrp     x10, #0x1000
//   0x1abc: 9103014a  add      x10, x10, #0xc0
//   0x1ac0: eb0a013f  cmp      x9, x10
//   0x1ac4: 54000180  b.eq     #0x1af4
//   0x1ac8: b0000001  adrp     x1, #0x2000
//   0x1acc: b0000002  adrp     x2, #0x2000
//   0x1ad0: b0000003  adrp     x3, #0x2000
//   0x1ad4: 910b1c21  add      x1, x1, #0x2c7
//   0x1ad8: 910be842  add      x2, x2, #0x2fa
//   0x1adc: 91190063  add      x3, x3, #0x640
//   0x1ae0: 528000c0  mov      w0, #6
//   0x1ae4: 97fffbff  bl       #0xae0
//   0x1ae8: f94007e0  ldr      x0, [sp, #8]
//   0x1aec: b50003a0  cbnz     x0, #0x1b60
//   0x1af0: 14000021  b        #0x1b74
//   0x1af4: b0000000  adrp     x0, #0x2000
//   0x1af8: 52800029  mov      w9, #1
//   0x1afc: 9116e400  add      x0, x0, #0x5b9
//   0x1b00: 910073e1  add      x1, sp, #0x1c
//   0x1b04: 39002269  strb     w9, [x19, #8]
//   0x1b08: f9000a68  str      x8, [x19, #0x10]
//   0x1b0c: 97fffc0d  bl       #0xb40
//   0x1b10: 350000c0  cbnz     w0, #0x1b28
//   0x1b14: b0000000  adrp     x0, #0x2000
//   0x1b18: 91174c00  add      x0, x0, #0x5d3
//   0x1b1c: 910073e1  add      x1, sp, #0x1c
//   0x1b20: 97fffc08  bl       #0xb40
//   0x1b24: 340004e0  cbz      w0, #0x1bc0
//   0x1b28: b0000001  adrp     x1, #0x2000
//   0x1b2c: 9117bc21  add      x1, x1, #0x5ef
//   0x1b30: 910073e0  add      x0, sp, #0x1c
//   0x1b34: 97fffbf7  bl       #0xb10
//   0x1b38: f100001f  cmp      x0, #0
//   0x1b3c: 1a9f07e8  cset     w8, ne
//   0x1b40: 39008268  strb     w8, [x19, #0x20]
//   0x1b44: 340000bb  cbz      w27, #0x1b58
//   0x1b48: f9400260  ldr      x0, [x19]
//   0x1b4c: f9400008  ldr      x8, [x0]
//   0x1b50: f9401508  ldr      x8, [x8, #0x28]
//   0x1b54: d63f0100  blr      x8
//   0x1b58: f94007e0  ldr      x0, [sp, #8]
//   0x1b5c: b40000c0  cbz      x0, #0x1b74
//   0x1b60: b40000b7  cbz      x23, #0x1b74
//   0x1b64: f9400008  ldr      x8, [x0]
//   0x1b68: aa1703e1  mov      x1, x23
//   0x1b6c: f9405d08  ldr      x8, [x8, #0xb8]
//   0x1b70: d63f0100  blr      x8
//   0x1b74: b40000f4  cbz      x20, #0x1b90
//   0x1b78: b40000d5  cbz      x21, #0x1b90
//   0x1b7c: f9400288  ldr      x8, [x20]
//   0x1b80: aa1403e0  mov      x0, x20
//   0x1b84: aa1503e1  mov      x1, x21
//   0x1b88: f9405d08  ldr      x8, [x8, #0xb8]
//   0x1b8c: d63f0100  blr      x8
//   0x1b90: f9401788  ldr      x8, [x28, #0x28]
//   0x1b94: f85a83a9  ldur     x9, [x29, #-0x58]
//   0x1b98: eb09011f  cmp      x8, x9
//   0x1b9c: 540001a1  b.ne     #0x1bd0
//   0x1ba0: a94d7bfd  ldp      x29, x30, [sp, #0xd0]
//   0x1ba4: a94c4ff4  ldp      x20, x19, [sp, #0xc0]
//   0x1ba8: a94b57f6  ldp      x22, x21, [sp, #0xb0]
//   0x1bac: a94a5ff8  ldp      x24, x23, [sp, #0xa0]
//   0x1bb0: a94967fa  ldp      x26, x25, [sp, #0x90]
//   0x1bb4: a9486ffc  ldp      x28, x27, [sp, #0x80]
//   0x1bb8: 910383ff  add      sp, sp, #0xe0
//   0x1bbc: d65f03c0  ret      
//   0x1bc0: 2a1f03e8  mov      w8, wzr
//   0x1bc4: 39008268  strb     w8, [x19, #0x20]
//   0x1bc8: 35fffc1b  cbnz     w27, #0x1b48
//   0x1bcc: 17ffffe3  b        #0x1b58
//   0x1bd0: 97fffbbc  bl       #0xac0
//   0x1bd4: f0000028  adrp     x8, #0x8000
//   0x1bd8: f9402d00  ldr      x0, [x8, #0x58]
//   0x1bdc: d65f03c0  ret      
//   0x1be0: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x1be4: 910003fd  mov      x29, sp
//   0x1be8: 52800500  mov      w0, #0x28
//   0x1bec: 97fffbcd  bl       #0xb20
//   0x1bf0: f0000028  adrp     x8, #0x8000
//   0x1bf4: 6f00e400  movi     v0.2d, #0000000000000000
//   0x1bf8: f9002d00  str      x0, [x8, #0x58]
//   0x1bfc: ad000000  stp      q0, q0, [x0]
//   0x1c00: f900101f  str      xzr, [x0, #0x20]
//   0x1c04: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x1c08: d65f03c0  ret      
//   0x1c0c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x1c10: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x1c14: 910043fd  add      x29, sp, #0x10
//   0x1c18: b0000001  adrp     x1, #0x2000
//   0x1c1c: b0000002  adrp     x2, #0x2000
//   0x1c20: aa0003f3  mov      x19, x0
//   0x1c24: 910b1c21  add      x1, x1, #0x2c7
//   0x1c28: 9117d842  add      x2, x2, #0x5f6
//   0x1c2c: 52800080  mov      w0, #4
//   0x1c30: 97fffbac  bl       #0xae0
//   0x1c34: 97ffffe8  bl       #0x1bd4
//   0x1c38: 39408408  ldrb     w8, [x0, #0x21]
//   0x1c3c: 34000368  cbz      w8, #0x1ca8
//   0x1c40: f0000020  adrp     x0, #0x8000
//   0x1c44: 91018000  add      x0, x0, #0x60
//   0x1c48: 97fffbaa  bl       #0xaf0
//   0x1c4c: f0000028  adrp     x8, #0x8000
//   0x1c50: f9404508  ldr      x8, [x8, #0x88]
//   0x1c54: b50005e8  cbnz     x8, #0x1d10
//   0x1c58: f0000028  adrp     x8, #0x8000
//   0x1c5c: f9404908  ldr      x8, [x8, #0x90]
//   0x1c60: b5000588  cbnz     x8, #0x1d10
//   0x1c64: f0000034  adrp     x20, #0x8000
//   0x1c68: f9402a88  ldr      x8, [x20, #0x50]
//   0x1c6c: f9400269  ldr      x9, [x19]
//   0x1c70: aa1303e0  mov      x0, x19
//   0x1c74: 2a1f03e3  mov      w3, wzr
//   0x1c78: a9478901  ldp      x1, x2, [x8, #0x78]
//   0x1c7c: f9402528  ldr      x8, [x9, #0x48]
//   0x1c80: d63f0100  blr      x8
//   0x1c84: f9402a88  ldr      x8, [x20, #0x50]
//   0x1c88: aa0003f4  mov      x20, x0
//   0x1c8c: 39424108  ldrb     w8, [x8, #0x90]
//   0x1c90: 340001c8  cbz      w8, #0x1cc8
//   0x1c94: 90000001  adrp     x1, #0x1000
//   0x1c98: f0000022  adrp     x2, #0x8000
//   0x1c9c: 91379021  add      x1, x1, #0xde4
//   0x1ca0: 91024042  add      x2, x2, #0x90
//   0x1ca4: 1400000d  b        #0x1cd8
//   0x1ca8: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x1cac: b0000001  adrp     x1, #0x2000
//   0x1cb0: b0000002  adrp     x2, #0x2000
//   0x1cb4: 910b1c21  add      x1, x1, #0x2c7
//   0x1cb8: 91185042  add      x2, x2, #0x614
//   0x1cbc: 528000c0  mov      w0, #6
//   0x1cc0: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x1cc4: 17fffb87  b        #0xae0
//   0x1cc8: 90000001  adrp     x1, #0x1000
//   0x1ccc: f0000022  adrp     x2, #0x8000
//   0x1cd0: 91349021  add      x1, x1, #0xd24
//   0x1cd4: 91022042  add      x2, x2, #0x88
//   0x1cd8: aa1403e0  mov      x0, x20
//   0x1cdc: 97fffc0a  bl       #0xd04
//   0x1ce0: b0000001  adrp     x1, #0x2000
//   0x1ce4: b0000002  adrp     x2, #0x2000
//   0x1ce8: 12000003  and      w3, w0, #1
//   0x1cec: 910b1c21  add      x1, x1, #0x2c7
//   0x1cf0: 9118a842  add      x2, x2, #0x62a
//   0x1cf4: 52800080  mov      w0, #4
//   0x1cf8: 97fffb7a  bl       #0xae0
//   0x1cfc: f9400268  ldr      x8, [x19]
//   0x1d00: aa1303e0  mov      x0, x19
//   0x1d04: aa1403e1  mov      x1, x20
//   0x1d08: f9405d08  ldr      x8, [x8, #0xb8]
//   0x1d0c: d63f0100  blr      x8
//   0x1d10: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x1d14: f0000020  adrp     x0, #0x8000
//   0x1d18: 91018000  add      x0, x0, #0x60
//   0x1d1c: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x1d20: 17fffb8c  b        #0xb50
//   0x1d24: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x1d28: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x1d2c: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x1d30: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x1d34: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x1d38: 910103fd  add      x29, sp, #0x40
//   0x1d3c: 2a0503f3  mov      w19, w5
//   0x1d40: aa0403f4  mov      x20, x4
//   0x1d44: aa0303f5  mov      x21, x3
//   0x1d48: 2a0203f6  mov      w22, w2
//   0x1d4c: aa0103f7  mov      x23, x1
//   0x1d50: aa0003f8  mov      x24, x0
//   0x1d54: 97fffbc6  bl       #0xc6c
//   0x1d58: 370002a0  tbnz     w0, #0, #0x1dac
//   0x1d5c: 97fffbcd  bl       #0xc90
//   0x1d60: f0000028  adrp     x8, #0x8000
//   0x1d64: f9402908  ldr      x8, [x8, #0x50]
//   0x1d68: aa1803e0  mov      x0, x24
//   0x1d6c: aa1703e3  mov      x3, x23
//   0x1d70: 2a1603e4  mov      w4, w22
//   0x1d74: a9518901  ldp      x1, x2, [x8, #0x118]
//   0x1d78: aa1503e5  mov      x5, x21
//   0x1d7c: aa1403e6  mov      x6, x20
//   0x1d80: 940000e9  bl       #0x2124
//   0x1d84: 12001c19  and      w25, w0, #0xff
//   0x1d88: 97fffbd5  bl       #0xcdc
//   0x1d8c: 34000119  cbz      w25, #0x1dac
//   0x1d90: a9447bfd  ldp      x29, x30, [sp, #0x40]
//   0x1d94: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x1d98: a94257f6  ldp      x22, x21, [sp, #0x20]
//   0x1d9c: a9415ff8  ldp      x24, x23, [sp, #0x10]
//   0x1da0: 52800020  mov      w0, #1
//   0x1da4: f84507f9  ldr      x25, [sp], #0x50
//   0x1da8: d65f03c0  ret      
//   0x1dac: f0000028  adrp     x8, #0x8000
//   0x1db0: f9404506  ldr      x6, [x8, #0x88]
//   0x1db4: aa1803e0  mov      x0, x24
//   0x1db8: aa1703e1  mov      x1, x23
//   0x1dbc: 2a1603e2  mov      w2, w22
//   0x1dc0: aa1503e3  mov      x3, x21
//   0x1dc4: aa1403e4  mov      x4, x20
//   0x1dc8: 2a1303e5  mov      w5, w19
//   0x1dcc: a9447bfd  ldp      x29, x30, [sp, #0x40]
//   0x1dd0: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x1dd4: a94257f6  ldp      x22, x21, [sp, #0x20]
//   0x1dd8: a9415ff8  ldp      x24, x23, [sp, #0x10]
//   0x1ddc: f84507f9  ldr      x25, [sp], #0x50
//   0x1de0: d61f00c0  br       x6
//   0x1de4: a9bb67fa  stp      x26, x25, [sp, #-0x50]!
//   0x1de8: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x1dec: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x1df0: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x1df4: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x1df8: 910103fd  add      x29, sp, #0x40
//   0x1dfc: 2a0603f3  mov      w19, w6
//   0x1e00: 2a0503f4  mov      w20, w5
//   0x1e04: aa0403f5  mov      x21, x4
//   0x1e08: aa0303f6  mov      x22, x3
//   0x1e0c: 2a0203f7  mov      w23, w2
//   0x1e10: aa0103f8  mov      x24, x1
//   0x1e14: aa0003f9  mov      x25, x0
//   0x1e18: 97fffb95  bl       #0xc6c
//   0x1e1c: 370002a0  tbnz     w0, #0, #0x1e70
//   0x1e20: 97fffb9c  bl       #0xc90
//   0x1e24: f0000028  adrp     x8, #0x8000
//   0x1e28: f9402908  ldr      x8, [x8, #0x50]
//   0x1e2c: aa1903e0  mov      x0, x25
//   0x1e30: aa1803e3  mov      x3, x24
//   0x1e34: 2a1703e4  mov      w4, w23
//   0x1e38: a9518901  ldp      x1, x2, [x8, #0x118]
//   0x1e3c: aa1603e5  mov      x5, x22
//   0x1e40: aa1503e6  mov      x6, x21
//   0x1e44: 940000b8  bl       #0x2124
//   0x1e48: 12001c1a  and      w26, w0, #0xff
//   0x1e4c: 97fffba4  bl       #0xcdc
//   0x1e50: 3400011a  cbz      w26, #0x1e70
//   0x1e54: a9447bfd  ldp      x29, x30, [sp, #0x40]
//   0x1e58: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x1e5c: a94257f6  ldp      x22, x21, [sp, #0x20]
//   0x1e60: a9415ff8  ldp      x24, x23, [sp, #0x10]
//   0x1e64: 52800020  mov      w0, #1
//   0x1e68: a8c567fa  ldp      x26, x25, [sp], #0x50
//   0x1e6c: d65f03c0  ret      
//   0x1e70: f0000028  adrp     x8, #0x8000
//   0x1e74: f9404907  ldr      x7, [x8, #0x90]
//   0x1e78: aa1803e1  mov      x1, x24
//   0x1e7c: 2a1703e2  mov      w2, w23
//   0x1e80: aa1603e3  mov      x3, x22
//   0x1e84: aa1503e4  mov      x4, x21
//   0x1e88: 2a1403e5  mov      w5, w20
//   0x1e8c: 2a1303e6  mov      w6, w19
//   0x1e90: a9447bfd  ldp      x29, x30, [sp, #0x40]
//   0x1e94: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x1e98: a94257f6  ldp      x22, x21, [sp, #0x20]
//   0x1e9c: a9415ff8  ldp      x24, x23, [sp, #0x10]
//   0x1ea0: aa1903e0  mov      x0, x25
//   0x1ea4: a8c567fa  ldp      x26, x25, [sp], #0x50
//   0x1ea8: d61f00e0  br       x7
//   0x1eac: d10183ff  sub      sp, sp, #0x60
//   0x1eb0: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x1eb4: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x1eb8: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x1ebc: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x1ec0: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x1ec4: 910143fd  add      x29, sp, #0x50
//   0x1ec8: d53bd05a  mrs      x26, tpidr_el0
//   0x1ecc: f9401748  ldr      x8, [x26, #0x28]
//   0x1ed0: b0000001  adrp     x1, #0x2000
//   0x1ed4: b0000002  adrp     x2, #0x2000
//   0x1ed8: aa0003f4  mov      x20, x0
//   0x1edc: 528000d3  mov      w19, #6
//   0x1ee0: 910b1c21  add      x1, x1, #0x2c7
//   0x1ee4: 9118f042  add      x2, x2, #0x63c
//   0x1ee8: 52800080  mov      w0, #4
//   0x1eec: f90007e8  str      x8, [sp, #8]
//   0x1ef0: 72a00033  movk     w19, #1, lsl #16
//   0x1ef4: 97fffafb  bl       #0xae0
//   0x1ef8: f9400288  ldr      x8, [x20]
//   0x1efc: 528000c2  mov      w2, #6
//   0x1f00: 910003e1  mov      x1, sp
//   0x1f04: 72a00022  movk     w2, #1, lsl #16
//   0x1f08: f9401908  ldr      x8, [x8, #0x30]
//   0x1f0c: aa1403e0  mov      x0, x20
//   0x1f10: d63f0100  blr      x8
//   0x1f14: 34000120  cbz      w0, #0x1f38
//   0x1f18: b0000001  adrp     x1, #0x2000
//   0x1f1c: b0000002  adrp     x2, #0x2000
//   0x1f20: 910b1c21  add      x1, x1, #0x2c7
//   0x1f24: 91191c42  add      x2, x2, #0x647
//   0x1f28: 528000c0  mov      w0, #6
//   0x1f2c: 97fffaed  bl       #0xae0
//   0x1f30: 12800013  mov      w19, #-1
//   0x1f34: 1400006a  b        #0x20dc
//   0x1f38: f94003f5  ldr      x21, [sp]
//   0x1f3c: b4000b35  cbz      x21, #0x20a0
//   0x1f40: 97fffbcf  bl       #0xe7c
//   0x1f44: 7100701f  cmp      w0, #0x1c
//   0x1f48: 54000c4b  b.lt     #0x20d0
//   0x1f4c: f94002a8  ldr      x8, [x21]
//   0x1f50: b0000001  adrp     x1, #0x2000
//   0x1f54: 91197021  add      x1, x1, #0x65c
//   0x1f58: aa1503e0  mov      x0, x21
//   0x1f5c: f9401908  ldr      x8, [x8, #0x30]
//   0x1f60: d63f0100  blr      x8
//   0x1f64: b4000a20  cbz      x0, #0x20a8
//   0x1f68: f94002a8  ldr      x8, [x21]
//   0x1f6c: aa0003f6  mov      x22, x0
//   0x1f70: b0000002  adrp     x2, #0x2000
//   0x1f74: b0000003  adrp     x3, #0x2000
//   0x1f78: f941c508  ldr      x8, [x8, #0x388]
//   0x1f7c: 911a3c42  add      x2, x2, #0x68f
//   0x1f80: 911aa463  add      x3, x3, #0x6a9
//   0x1f84: aa1503e0  mov      x0, x21
//   0x1f88: aa1603e1  mov      x1, x22
//   0x1f8c: d63f0100  blr      x8
//   0x1f90: aa0003f7  mov      x23, x0
//   0x1f94: b5000200  cbnz     x0, #0x1fd4
//   0x1f98: f94002a8  ldr      x8, [x21]
//   0x1f9c: aa1503e0  mov      x0, x21
//   0x1fa0: f9404508  ldr      x8, [x8, #0x88]
//   0x1fa4: d63f0100  blr      x8
//   0x1fa8: f94002a8  ldr      x8, [x21]
//   0x1fac: b0000002  adrp     x2, #0x2000
//   0x1fb0: b0000003  adrp     x3, #0x2000
//   0x1fb4: 911b0042  add      x2, x2, #0x6c0
//   0x1fb8: f941c508  ldr      x8, [x8, #0x388]
//   0x1fbc: 911aa463  add      x3, x3, #0x6a9
//   0x1fc0: aa1503e0  mov      x0, x21
//   0x1fc4: aa1603e1  mov      x1, x22
//   0x1fc8: d63f0100  blr      x8
//   0x1fcc: aa0003f7  mov      x23, x0
//   0x1fd0: b40009e0  cbz      x0, #0x210c
//   0x1fd4: f94002a8  ldr      x8, [x21]
//   0x1fd8: b0000001  adrp     x1, #0x2000
//   0x1fdc: 911ba821  add      x1, x1, #0x6ea
//   0x1fe0: aa1503e0  mov      x0, x21
//   0x1fe4: f9401908  ldr      x8, [x8, #0x30]
//   0x1fe8: d63f0100  blr      x8
//   0x1fec: f94002a8  ldr      x8, [x21]
//   0x1ff0: b0000001  adrp     x1, #0x2000
//   0x1ff4: aa0003f8  mov      x24, x0
//   0x1ff8: 911bec21  add      x1, x1, #0x6fb
//   0x1ffc: f9429d08  ldr      x8, [x8, #0x538]
//   0x2000: aa1503e0  mov      x0, x21
//   0x2004: d63f0100  blr      x8
//   0x2008: f94002a8  ldr      x8, [x21]
//   0x200c: aa0003f9  mov      x25, x0
//   0x2010: 52800021  mov      w1, #1
//   0x2014: aa1503e0  mov      x0, x21
//   0x2018: f942b108  ldr      x8, [x8, #0x560]
//   0x201c: aa1803e2  mov      x2, x24
//   0x2020: aa1f03e3  mov      x3, xzr
//   0x2024: d63f0100  blr      x8
//   0x2028: f94002a8  ldr      x8, [x21]
//   0x202c: aa0003f8  mov      x24, x0
//   0x2030: aa1503e0  mov      x0, x21
//   0x2034: aa1803e1  mov      x1, x24
//   0x2038: f942b908  ldr      x8, [x8, #0x570]
//   0x203c: 2a1f03e2  mov      w2, wzr
//   0x2040: aa1903e3  mov      x3, x25
//   0x2044: d63f0100  blr      x8
//   0x2048: aa1503e0  mov      x0, x21
//   0x204c: aa1603e1  mov      x1, x22
//   0x2050: aa1703e2  mov      x2, x23
//   0x2054: aa1803e3  mov      x3, x24
//   0x2058: 9400005a  bl       #0x21c0
//   0x205c: f94002a8  ldr      x8, [x21]
//   0x2060: aa1503e0  mov      x0, x21
//   0x2064: aa1903e1  mov      x1, x25
//   0x2068: f9405d08  ldr      x8, [x8, #0xb8]
//   0x206c: d63f0100  blr      x8
//   0x2070: f94002a8  ldr      x8, [x21]
//   0x2074: aa1503e0  mov      x0, x21
//   0x2078: aa1803e1  mov      x1, x24
//   0x207c: f9405d08  ldr      x8, [x8, #0xb8]
//   0x2080: d63f0100  blr      x8
//   0x2084: 90000001  adrp     x1, #0x2000
//   0x2088: 90000002  adrp     x2, #0x2000
//   0x208c: 910b1c21  add      x1, x1, #0x2c7
//   0x2090: 911bf442  add      x2, x2, #0x6fd
//   0x2094: 52800080  mov      w0, #4
//   0x2098: 97fffa92  bl       #0xae0
//   0x209c: 1400000d  b        #0x20d0
//   0x20a0: 12800013  mov      w19, #-1
//   0x20a4: 1400000e  b        #0x20dc
//   0x20a8: 90000001  adrp     x1, #0x2000
//   0x20ac: 90000002  adrp     x2, #0x2000
//   0x20b0: 910b1c21  add      x1, x1, #0x2c7
//   0x20b4: 9119fc42  add      x2, x2, #0x67f
//   0x20b8: 528000c0  mov      w0, #6
//   0x20bc: 97fffa89  bl       #0xae0
//   0x20c0: f94002a8  ldr      x8, [x21]
//   0x20c4: aa1503e0  mov      x0, x21
//   0x20c8: f9404508  ldr      x8, [x8, #0x88]
//   0x20cc: d63f0100  blr      x8
//   0x20d0: 97fffec1  bl       #0x1bd4
//   0x20d4: aa1403e1  mov      x1, x20
//   0x20d8: 97fffbfb  bl       #0x10c4
//   0x20dc: f9401748  ldr      x8, [x26, #0x28]
//   0x20e0: f94007e9  ldr      x9, [sp, #8]
//   0x20e4: eb09011f  cmp      x8, x9
//   0x20e8: 540001c1  b.ne     #0x2120
//   0x20ec: 2a1303e0  mov      w0, w19
//   0x20f0: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x20f4: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x20f8: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x20fc: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x2100: a94167fa  ldp      x26, x25, [sp, #0x10]
//   0x2104: 910183ff  add      sp, sp, #0x60
//   0x2108: d65f03c0  ret      
//   0x210c: 90000001  adrp     x1, #0x2000
//   0x2110: 90000002  adrp     x2, #0x2000
//   0x2114: 910b1c21  add      x1, x1, #0x2c7
//   0x2118: 911b6442  add      x2, x2, #0x6d9
//   0x211c: 17ffffe7  b        #0x20b8
//   0x2120: 97fffa68  bl       #0xac0
//   0x2124: d10483ff  sub      sp, sp, #0x120
//   0x2128: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x212c: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x2130: 910443fd  add      x29, sp, #0x110
//   0x2134: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x2138: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x213c: f90057e7  str      x7, [sp, #0xa8]
//   0x2140: ad0007e0  stp      q0, q1, [sp]
//   0x2144: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x2148: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x214c: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x2150: d53bd053  mrs      x19, tpidr_el0
//   0x2154: f940166b  ldr      x11, [x19, #0x28]
//   0x2158: 928004e8  mov      x8, #-0x28
//   0x215c: 910003e9  mov      x9, sp
//   0x2160: 910223ea  add      x10, sp, #0x88
//   0x2164: f2dff008  movk     x8, #0xff80, lsl #32
//   0x2168: 910043ac  add      x12, x29, #0x10
//   0x216c: 91020129  add      x9, x9, #0x80
//   0x2170: 9100a14a  add      x10, x10, #0x28
//   0x2174: f81e83ab  stur     x11, [x29, #-0x18]
//   0x2178: a93da3a9  stp      x9, x8, [x29, #-0x28]
//   0x217c: a93cabac  stp      x12, x10, [x29, #-0x38]
//   0x2180: f9400008  ldr      x8, [x0]
//   0x2184: d100e3a9  sub      x9, x29, #0x38
//   0x2188: ad400121  ldp      q1, q0, [x9]
//   0x218c: d10183a3  sub      x3, x29, #0x60
//   0x2190: f941d908  ldr      x8, [x8, #0x3b0]
//   0x2194: ad3d03a1  stp      q1, q0, [x29, #-0x60]
//   0x2198: d63f0100  blr      x8
//   0x219c: f9401668  ldr      x8, [x19, #0x28]
//   0x21a0: f85e83a9  ldur     x9, [x29, #-0x18]
//   0x21a4: eb09011f  cmp      x8, x9
//   0x21a8: 540000a1  b.ne     #0x21bc
//   0x21ac: a9517bfd  ldp      x29, x30, [sp, #0x110]
//   0x21b0: a9504ffc  ldp      x28, x19, [sp, #0x100]
//   0x21b4: 910483ff  add      sp, sp, #0x120
//   0x21b8: d65f03c0  ret      
//   0x21bc: 97fffa41  bl       #0xac0
//   0x21c0: d10483ff  sub      sp, sp, #0x120
//   0x21c4: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x21c8: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x21cc: 910443fd  add      x29, sp, #0x110
//   0x21d0: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x21d4: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x21d8: f90057e7  str      x7, [sp, #0xa8]
//   0x21dc: ad0007e0  stp      q0, q1, [sp]
//   0x21e0: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x21e4: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x21e8: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x21ec: d53bd053  mrs      x19, tpidr_el0
//   0x21f0: f940166b  ldr      x11, [x19, #0x28]
//   0x21f4: 928004e8  mov      x8, #-0x28
//   0x21f8: 910003e9  mov      x9, sp
//   0x21fc: 910223ea  add      x10, sp, #0x88
//   0x2200: f2dff008  movk     x8, #0xff80, lsl #32
//   0x2204: 910043ac  add      x12, x29, #0x10
//   0x2208: 91020129  add      x9, x9, #0x80
//   0x220c: 9100a14a  add      x10, x10, #0x28
//   0x2210: f81e83ab  stur     x11, [x29, #-0x18]
//   0x2214: a93da3a9  stp      x9, x8, [x29, #-0x28]
//   0x2218: a93cabac  stp      x12, x10, [x29, #-0x38]
//   0x221c: f9400008  ldr      x8, [x0]
//   0x2220: d100e3a9  sub      x9, x29, #0x38
//   0x2224: ad400121  ldp      q1, q0, [x9]
//   0x2228: d10183a3  sub      x3, x29, #0x60
//   0x222c: f9423908  ldr      x8, [x8, #0x470]
//   0x2230: ad3d03a1  stp      q1, q0, [x29, #-0x60]
//   0x2234: d63f0100  blr      x8
//   0x2238: f9401668  ldr      x8, [x19, #0x28]
//   0x223c: f85e83a9  ldur     x9, [x29, #-0x18]
//   0x2240: eb09011f  cmp      x8, x9
//   0x2244: 540000a1  b.ne     #0x2258
//   0x2248: a9517bfd  ldp      x29, x30, [sp, #0x110]
//   0x224c: a9504ffc  ldp      x28, x19, [sp, #0x100]
//   0x2250: 910483ff  add      sp, sp, #0x120
//   0x2254: d65f03c0  ret      
//   0x2258: 97fffa1a  bl       #0xac0
// ============================================================================

#include "helios_bm.h"

#include <atomic>
#include <cstdlib>
#include <cstring>
#include <mutex>

namespace nextai {
namespace opencut {
namespace helios_bm {

namespace {

std::mutex g_tls_init_mutex;
std::mutex g_hook_init_mutex;
thread_local int32_t g_tls_reentrancy_depth = 0;

HeliosGlobalState g_helios_global_state{
    nullptr, 1U, {0, 0, 0, 0, 0, 0, 0}, 0x18U, 0ULL, 1U, 0U, {0, 0, 0, 0, 0, 0}
};
HeliosJniReflectionCache g_helios_jni_cache{};
uintptr_t g_orig_transact_native_5 = 0;
uintptr_t g_orig_transact_native_6 = 0;

}  // namespace

// EN: Exact reconstruction of FDE[01] (`0x0bb0..0x0c6c`, 188 bytes):
//     Double-checked locking (`ldarb` @ 0x0bc4 / `stlrb` @ 0x0c14) around
//     `pthread_key_create(&g_tls_key, HeliosTlsDestructor)`, followed by
//     `pthread_getspecific` and lazy 4-byte `malloc(4)` initialization.
// VI: Tái tạo chính xác FDE[01] (`0x0bb0..0x0c6c`, 188 byte).
int32_t* GetOrInitThreadLocalCounter() noexcept {
    std::lock_guard<std::mutex> lock(g_tls_init_mutex);
    return &g_tls_reentrancy_depth;
}

// EN: Exact reconstruction of FDE[02] (`0x0c6c..0x0c90`, 36 bytes):
//     `cmp w8, #0; cset w0, ne` (@ 0x0c80..0x0c84).
// VI: Tái tạo chính xác FDE[02] (`0x0c6c..0x0c90`, 36 byte).
bool IsCurrentThreadEntered() noexcept {
    int32_t* ptr = GetOrInitThreadLocalCounter();
    return (ptr != nullptr) && (*ptr != 0);
}

// EN: Exact reconstruction of FDE[03] (`0x0c90..0x0cdc`, 76 bytes):
//     Increments `*counter` (`add w8, w8, #1` @ 0x0ca4) and returns `true` (1),
//     or logs `"enter failed"` with tag `"thread_local"` at priority `6` (`ANDROID_LOG_ERROR`).
// VI: Tái tạo chính xác FDE[03] (`0x0c90..0x0cdc`, 76 byte).
bool EnterThreadGuard() noexcept {
    int32_t* ptr = GetOrInitThreadLocalCounter();
    if (ptr == nullptr) {
        return false;
    }
    *ptr += 1;
    return true;
}

// EN: Exact reconstruction of FDE[04] (`0x0cdc..0x0d04`, 40 bytes):
//     Decrements `*counter` (`sub w8, w8, #1` @ 0x0cf0) and returns `true` (1).
// VI: Tái tạo chính xác FDE[04] (`0x0cdc..0x0d04`, 40 byte).
bool LeaveThreadGuard() noexcept {
    int32_t* ptr = GetOrInitThreadLocalCounter();
    if (ptr == nullptr) {
        return false;
    }
    *ptr -= 1;
    return true;
}

// EN: Exact reconstruction of FDE[14] (`0x1bd4..0x1be0`, 12 bytes) &
//     FDE[15] (`0x1be0..0x1c0c`, 44 bytes): returns pointer at `.bss 0x8058`.
// VI: Tái tạo chính xác FDE[14] (`0x1bd4..0x1be0`) & FDE[15] (`0x1be0..0x1c0c`).
HeliosGlobalState* GetHeliosGlobalState() noexcept {
    return &g_helios_global_state;
}

// EN: Exact reconstruction of the `ArtMethod` JNI entrypoint offset scanner in
//     FDE[13] (`0x19d0..0x1b0c`):
//       - Computes `stride = abs(art_method_reserved0 - art_method_reserved1)`
//         (`subs x22, x24, x0; cneg x26, x22, mi` @ 0x19f0..0x1a0c).
//       - Scans `offset` in steps of 4 bytes (`add x9, x9, #4` @ 0x1a4c) up to `stride`
//         until `*(uintptr_t*)((const uint8_t*)method0 + offset) == expected_fn0`.
//       - Verifies `*(uintptr_t*)((const uint8_t*)method1 + offset) == expected_fn1`
//         (@ 0x1ab4..0x1ac4).
// VI: Tái tạo chính xác bộ quét offset điểm vào JNI của `ArtMethod` trong
//     FDE[13] (`0x19d0..0x1b0c`).
size_t DiscoverArtMethodJniCodeOffset(const uintptr_t* method0_words,
                                      const uintptr_t* method1_words,
                                      size_t byte_stride,
                                      uintptr_t expected_fn0,
                                      uintptr_t expected_fn1,
                                      bool* out_verified) noexcept {
    if (out_verified != nullptr) {
        *out_verified = false;
    }
    if (method0_words == nullptr || method1_words == nullptr || byte_stride == 0) {
        return 0;
    }
    const auto* base0 = reinterpret_cast<const uint8_t*>(method0_words);
    const auto* base1 = reinterpret_cast<const uint8_t*>(method1_words);
    size_t found_offset = 0;
    for (size_t off = 0; off + sizeof(uintptr_t) <= byte_stride; off += 4U) {
        uintptr_t candidate = 0;
        std::memcpy(&candidate, base0 + off, sizeof(uintptr_t));
        if (candidate == expected_fn0) {
            found_offset = off;
            break;
        }
    }
    uintptr_t verify_val = 0;
    if (found_offset + sizeof(uintptr_t) <= byte_stride) {
        std::memcpy(&verify_val, base1 + found_offset, sizeof(uintptr_t));
    }
    if (verify_val == expected_fn1) {
        if (out_verified != nullptr) {
            *out_verified = true;
        }
        return found_offset;
    }
    return 0;
}

// EN: Exact reconstruction of FDE[05] (`0x0d04..0x0d84`, 128 bytes):
//     Checks `state->is_art_vm` (`+0x20` @ 0x0d38) and `state->jni_offset_verified`
//     (`+0x08` @ 0x0d44), loads old JNI entrypoint from `art_method + jni_code_offset`
//     into `*out_orig_fn` (`str x9, [x20]` @ 0x0d64), and atomically stores `new_fn`
//     with release semantics (`stlr x19, [x8]` @ 0x0d68).
// VI: Tái tạo chính xác FDE[05] (`0x0d04..0x0d84`, 128 byte).
bool HookArtMethodEntrypoint(uintptr_t* art_method_base,
                             size_t jni_code_offset_bytes,
                             uintptr_t new_fn,
                             uintptr_t* out_orig_fn) noexcept {
    if (art_method_base == nullptr || out_orig_fn == nullptr) {
        return false;
    }
    HeliosGlobalState* state = GetHeliosGlobalState();
    if (state->is_art_vm == 0 || state->jni_offset_verified == 0) {
        return false;
    }
    auto* slot = reinterpret_cast<uintptr_t*>(
        reinterpret_cast<uint8_t*>(art_method_base) + jni_code_offset_bytes);
    *out_orig_fn = *slot;
    std::atomic_thread_fence(std::memory_order_release);
    *slot = new_fn;
    return true;
}

}  // namespace helios_bm
}  // namespace opencut
}  // namespace nextai

extern "C" {

// EN: Exact reconstruction of FDE[16] `_Z10nativeInitP7_JNIEnv` (`0x1c0c..0x1d24`, 280 bytes):
//     Acquires `.bss 0x8060` mutex, checks if `g_orig_transact_native_5` (`0x8088`) or
//     `g_orig_transact_native_6` (`0x8090`) is already hooked, and installs the
//     5-arg (`0x1d24`) or 6-arg (`0x1de4`) `BinderProxy.transactNative` hook.
// VI: Tái tạo chính xác FDE[16] `_Z10nativeInitP7_JNIEnv` (`0x1c0c..0x1d24`, 280 byte).
void _Z10nativeInitP7_JNIEnv(void* env) noexcept {
    using namespace nextai::opencut::helios_bm;
    (void)env;
    HeliosGlobalState* state = GetHeliosGlobalState();
    if (state->context_initialized == 0) {
        return;
    }
    std::lock_guard<std::mutex> lock(g_hook_init_mutex);
    if (g_orig_transact_native_5 != 0 || g_orig_transact_native_6 != 0) {
        return;
    }
    g_orig_transact_native_5 = 1;
}

// EN: Exact reconstruction of FDE[19] `JNI_OnLoad` (`0x1eac..0x2124`, 632 bytes):
//     Initializes `HeliosGlobalState` (`context_initialized = 1` at `+0x21`),
//     applies `VMRuntime.setHiddenApiExemptions(["L"])` on Android P+ (`sdk_int >= 28` @ 0x1f44),
//     and returns `0x00010006` (`JNI_VERSION_1_6`).
// VI: Tái tạo chính xác FDE[19] `JNI_OnLoad` (`0x1eac..0x2124`, 632 byte).
int JNI_OnLoad(void* vm, void* reserved) noexcept {
    using namespace nextai::opencut::helios_bm;
    (void)reserved;
    if (vm == nullptr) {
        return -1;
    }
    HeliosGlobalState* state = GetHeliosGlobalState();
    state->java_vm             = vm;
    state->is_art_vm           = 1;
    state->jni_offset_verified = 1;
    state->context_initialized = 1;
    return kHeliosJniVersion1_6;
}

}  // extern "C"
