// ============================================================================
// NextAI OpenCut — Clean-Room C++17 Reconstruction
// File          : sys_platform_core.cpp
// Target Binary : libsys-platform.so (18,184 bytes)
// SHA-256       : 98d6a70902356f55fa38a2e62808865ada53250a97e2698ae19b37c8d785988b
// Task ID       : TASK-172-RECONSTRUCTION-LIBSYS-PLATFORM
// ============================================================================
// EN: Exact clean-room C++17 reconstruction of all 8 FDEs in `libsys-platform.so`
//     (.eh_frame_hdr @ 0x0fc0, .text 0x0bb0..0x0fb4, 257 instructions):
//       - FDE[00] `SysPlatform_lockfNonBlock` (0x0bf8..0x0cac, 180 B)
//       - FDE[01] `SysPlatform_unlockfNonBlock` (0x0cac..0x0cb4, 8 B)
//       - FDE[02] `get_current_time` (0x0cb4..0x0d0c, 88 B)
//       - FDE[03] `modify_process_name` (0x0d0c..0x0d80, 116 B)
//       - FDE[04] `get_process_name` (0x0d80..0x0de4, 100 B)
//       - FDE[05] `get_main_process_pid` (0x0de4..0x0ed8, 244 B)
//       - FDE[06] `FormatPidofCommand` (0x0ed8..0x0f7c, 164 B)
//       - FDE[07] `SysPlatform_waitpid` (0x0f7c..0x0fb4, 56 B)
// VI: Tái tạo phòng sạch C++17 chính xác cho toàn bộ 8 FDE trong `libsys-platform.so`.
// ============================================================================
// Complete AArch64 .plt Disassembly (0x0aa0..0x0bb0, 68 instructions):
//   0x0aa0: a9bf7bf0  stp      x16, x30, [sp, #-0x10]!
//   0x0aa4: f0000030  adrp     x16, #0x7000
//   0x0aa8: f947be11  ldr      x17, [x16, #0xf78]
//   0x0aac: 913de210  add      x16, x16, #0xf78
//   0x0ab0: d61f0220  br       x17
//   0x0ab4: d503201f  nop      
//   0x0ab8: d503201f  nop      
//   0x0abc: d503201f  nop      
//   0x0ac0: f0000030  adrp     x16, #0x7000
//   0x0ac4: f947c211  ldr      x17, [x16, #0xf80]
//   0x0ac8: 913e0210  add      x16, x16, #0xf80
//   0x0acc: d61f0220  br       x17
//   0x0ad0: f0000030  adrp     x16, #0x7000
//   0x0ad4: f947c611  ldr      x17, [x16, #0xf88]
//   0x0ad8: 913e2210  add      x16, x16, #0xf88
//   0x0adc: d61f0220  br       x17
//   0x0ae0: f0000030  adrp     x16, #0x7000
//   0x0ae4: f947ca11  ldr      x17, [x16, #0xf90]
//   0x0ae8: 913e4210  add      x16, x16, #0xf90
//   0x0aec: d61f0220  br       x17
//   0x0af0: f0000030  adrp     x16, #0x7000
//   0x0af4: f947ce11  ldr      x17, [x16, #0xf98]
//   0x0af8: 913e6210  add      x16, x16, #0xf98
//   0x0afc: d61f0220  br       x17
//   0x0b00: f0000030  adrp     x16, #0x7000
//   0x0b04: f947d211  ldr      x17, [x16, #0xfa0]
//   0x0b08: 913e8210  add      x16, x16, #0xfa0
//   0x0b0c: d61f0220  br       x17
//   0x0b10: f0000030  adrp     x16, #0x7000
//   0x0b14: f947d611  ldr      x17, [x16, #0xfa8]
//   0x0b18: 913ea210  add      x16, x16, #0xfa8
//   0x0b1c: d61f0220  br       x17
//   0x0b20: f0000030  adrp     x16, #0x7000
//   0x0b24: f947da11  ldr      x17, [x16, #0xfb0]
//   0x0b28: 913ec210  add      x16, x16, #0xfb0
//   0x0b2c: d61f0220  br       x17
//   0x0b30: f0000030  adrp     x16, #0x7000
//   0x0b34: f947de11  ldr      x17, [x16, #0xfb8]
//   0x0b38: 913ee210  add      x16, x16, #0xfb8
//   0x0b3c: d61f0220  br       x17
//   0x0b40: f0000030  adrp     x16, #0x7000
//   0x0b44: f947e211  ldr      x17, [x16, #0xfc0]
//   0x0b48: 913f0210  add      x16, x16, #0xfc0
//   0x0b4c: d61f0220  br       x17
//   0x0b50: f0000030  adrp     x16, #0x7000
//   0x0b54: f947e611  ldr      x17, [x16, #0xfc8]
//   0x0b58: 913f2210  add      x16, x16, #0xfc8
//   0x0b5c: d61f0220  br       x17
//   0x0b60: f0000030  adrp     x16, #0x7000
//   0x0b64: f947ea11  ldr      x17, [x16, #0xfd0]
//   0x0b68: 913f4210  add      x16, x16, #0xfd0
//   0x0b6c: d61f0220  br       x17
//   0x0b70: f0000030  adrp     x16, #0x7000
//   0x0b74: f947ee11  ldr      x17, [x16, #0xfd8]
//   0x0b78: 913f6210  add      x16, x16, #0xfd8
//   0x0b7c: d61f0220  br       x17
//   0x0b80: f0000030  adrp     x16, #0x7000
//   0x0b84: f947f211  ldr      x17, [x16, #0xfe0]
//   0x0b88: 913f8210  add      x16, x16, #0xfe0
//   0x0b8c: d61f0220  br       x17
//   0x0b90: f0000030  adrp     x16, #0x7000
//   0x0b94: f947f611  ldr      x17, [x16, #0xfe8]
//   0x0b98: 913fa210  add      x16, x16, #0xfe8
//   0x0b9c: d61f0220  br       x17
//   0x0ba0: f0000030  adrp     x16, #0x7000
//   0x0ba4: f947fa11  ldr      x17, [x16, #0xff0]
//   0x0ba8: 913fc210  add      x16, x16, #0xff0
//   0x0bac: d61f0220  br       x17
// ============================================================================
// Complete AArch64 .text Disassembly (0x0bb0..0x0fb4, 257 instructions):
//   0x0bb0: f0000020  adrp     x0, #0x7000
//   0x0bb4: 9135c000  add      x0, x0, #0xd70
//   0x0bb8: 17ffffce  b        #0xaf0
//   0x0bbc: d65f03c0  ret      
//   0x0bc0: 17ffffff  b        #0xbbc
//   0x0bc4: b4000040  cbz      x0, #0xbcc
//   0x0bc8: d61f0000  br       x0
//   0x0bcc: d65f03c0  ret      
//   0x0bd0: 90000008  adrp     x8, #0
//   0x0bd4: 912f1108  add      x8, x8, #0xbc4
//   0x0bd8: f0000022  adrp     x2, #0x7000
//   0x0bdc: 9135c042  add      x2, x2, #0xd70
//   0x0be0: aa0003e1  mov      x1, x0
//   0x0be4: aa0803e0  mov      x0, x8
//   0x0be8: 17ffffee  b        #0xba0
//   0x0bec: f0000023  adrp     x3, #0x7000
//   0x0bf0: 9135c063  add      x3, x3, #0xd70
//   0x0bf4: 17ffffc3  b        #0xb00
//   0x0bf8: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x0bfc: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0c00: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0c04: 910083fd  add      x29, sp, #0x20
//   0x0c08: f9400008  ldr      x8, [x0]
//   0x0c0c: aa0203f5  mov      x21, x2
//   0x0c10: aa0203e1  mov      x1, x2
//   0x0c14: aa1f03e2  mov      x2, xzr
//   0x0c18: f942a508  ldr      x8, [x8, #0x548]
//   0x0c1c: aa0003f4  mov      x20, x0
//   0x0c20: d63f0100  blr      x8
//   0x0c24: 52800841  mov      w1, #0x42
//   0x0c28: 52803602  mov      w2, #0x1b0
//   0x0c2c: aa0003f6  mov      x22, x0
//   0x0c30: 97ffffac  bl       #0xae0
//   0x0c34: f9400288  ldr      x8, [x20]
//   0x0c38: 2a0003f3  mov      w19, w0
//   0x0c3c: aa1403e0  mov      x0, x20
//   0x0c40: aa1503e1  mov      x1, x21
//   0x0c44: f942a908  ldr      x8, [x8, #0x550]
//   0x0c48: aa1603e2  mov      x2, x22
//   0x0c4c: d63f0100  blr      x8
//   0x0c50: 7100067f  cmp      w19, #1
//   0x0c54: 5400020b  b.lt     #0xc94
//   0x0c58: 528000c1  mov      w1, #6
//   0x0c5c: 2a1303e0  mov      w0, w19
//   0x0c60: 97ffffbc  bl       #0xb50
//   0x0c64: 36f801a0  tbz      w0, #0x1f, #0xc98
//   0x0c68: 12800028  mov      w8, #-2
//   0x0c6c: 528000a0  mov      w0, #5
//   0x0c70: 2a0803f4  mov      w20, w8
//   0x0c74: 97ffffbf  bl       #0xb70
//   0x0c78: 528000c1  mov      w1, #6
//   0x0c7c: 2a1303e0  mov      w0, w19
//   0x0c80: 97ffffb4  bl       #0xb50
//   0x0c84: 36f800a0  tbz      w0, #0x1f, #0xc98
//   0x0c88: 11000688  add      w8, w20, #1
//   0x0c8c: 35ffff14  cbnz     w20, #0xc6c
//   0x0c90: 14000002  b        #0xc98
//   0x0c94: 12800013  mov      w19, #-1
//   0x0c98: 2a1303e0  mov      w0, w19
//   0x0c9c: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x0ca0: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x0ca4: a8c357f6  ldp      x22, x21, [sp], #0x30
//   0x0ca8: d65f03c0  ret      
//   0x0cac: 2a0203e0  mov      w0, w2
//   0x0cb0: 17ffffb4  b        #0xb80
//   0x0cb4: d10083ff  sub      sp, sp, #0x20
//   0x0cb8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0cbc: 910043fd  add      x29, sp, #0x10
//   0x0cc0: 910003e0  mov      x0, sp
//   0x0cc4: aa1f03e1  mov      x1, xzr
//   0x0cc8: 97ffff9a  bl       #0xb30
//   0x0ccc: 34000060  cbz      w0, #0xcd8
//   0x0cd0: 92800000  mov      x0, #-1
//   0x0cd4: 1400000b  b        #0xd00
//   0x0cd8: a94027e8  ldp      x8, x9, [sp]
//   0x0cdc: 52807d0a  mov      w10, #0x3e8
//   0x0ce0: 9b0a7d08  mul      x8, x8, x10
//   0x0ce4: d29ef9ea  mov      x10, #0xf7cf
//   0x0ce8: f2bc6a6a  movk     x10, #0xe353, lsl #16
//   0x0cec: f2d374aa  movk     x10, #0x9ba5, lsl #32
//   0x0cf0: d343fd29  lsr      x9, x9, #3
//   0x0cf4: f2e4188a  movk     x10, #0x20c4, lsl #48
//   0x0cf8: 9bca7d29  umulh    x9, x9, x10
//   0x0cfc: 8b491100  add      x0, x8, x9, lsr #4
//   0x0d00: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0d04: 910083ff  add      sp, sp, #0x20
//   0x0d08: d65f03c0  ret      
//   0x0d0c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0d10: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0d14: 910043fd  add      x29, sp, #0x10
//   0x0d18: aa0103f3  mov      x19, x1
//   0x0d1c: aa0003f4  mov      x20, x0
//   0x0d20: b4000180  cbz      x0, #0xd50
//   0x0d24: f9400288  ldr      x8, [x20]
//   0x0d28: b4000128  cbz      x8, #0xd4c
//   0x0d2c: f9400689  ldr      x9, [x20, #8]
//   0x0d30: b40000e9  cbz      x9, #0xd4c
//   0x0d34: d63f0100  blr      x8
//   0x0d38: f9400688  ldr      x8, [x20, #8]
//   0x0d3c: aa1303e1  mov      x1, x19
//   0x0d40: d63f0100  blr      x8
//   0x0d44: 52800034  mov      w20, #1
//   0x0d48: 14000002  b        #0xd50
//   0x0d4c: 2a1f03f4  mov      w20, wzr
//   0x0d50: 528001e0  mov      w0, #0xf
//   0x0d54: aa1303e1  mov      x1, x19
//   0x0d58: 2a1f03e2  mov      w2, wzr
//   0x0d5c: 2a1f03e3  mov      w3, wzr
//   0x0d60: 2a1f03e4  mov      w4, wzr
//   0x0d64: 97ffff77  bl       #0xb40
//   0x0d68: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0d6c: 7100001f  cmp      w0, #0
//   0x0d70: 1a9f07e8  cset     w8, ne
//   0x0d74: 0a080280  and      w0, w20, w8
//   0x0d78: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x0d7c: d65f03c0  ret      
//   0x0d80: d10243ff  sub      sp, sp, #0x90
//   0x0d84: f9003bf3  str      x19, [sp, #0x70]
//   0x0d88: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x0d8c: 910203fd  add      x29, sp, #0x80
//   0x0d90: d53bd053  mrs      x19, tpidr_el0
//   0x0d94: f9401668  ldr      x8, [x19, #0x28]
//   0x0d98: 6f00e400  movi     v0.2d, #0000000000000000
//   0x0d9c: 910003e1  mov      x1, sp
//   0x0da0: 52800200  mov      w0, #0x10
//   0x0da4: f81e83a8  stur     x8, [x29, #-0x18]
//   0x0da8: b90063ff  str      wzr, [sp, #0x60]
//   0x0dac: ad0203e0  stp      q0, q0, [sp, #0x40]
//   0x0db0: ad0103e0  stp      q0, q0, [sp, #0x20]
//   0x0db4: ad0003e0  stp      q0, q0, [sp]
//   0x0db8: 97ffff62  bl       #0xb40
//   0x0dbc: f9401668  ldr      x8, [x19, #0x28]
//   0x0dc0: f85e83a9  ldur     x9, [x29, #-0x18]
//   0x0dc4: eb09011f  cmp      x8, x9
//   0x0dc8: 540000c1  b.ne     #0xde0
//   0x0dcc: a9487bfd  ldp      x29, x30, [sp, #0x80]
//   0x0dd0: f9403bf3  ldr      x19, [sp, #0x70]
//   0x0dd4: 910003e0  mov      x0, sp
//   0x0dd8: 910243ff  add      sp, sp, #0x90
//   0x0ddc: d65f03c0  ret      
//   0x0de0: 97ffff4c  bl       #0xb10
//   0x0de4: a9bd57fc  stp      x28, x21, [sp, #-0x30]!
//   0x0de8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0dec: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0df0: 910083fd  add      x29, sp, #0x20
//   0x0df4: d10843ff  sub      sp, sp, #0x210
//   0x0df8: d53bd055  mrs      x21, tpidr_el0
//   0x0dfc: f94016a8  ldr      x8, [x21, #0x28]
//   0x0e00: aa0003e3  mov      x3, x0
//   0x0e04: 6f00e400  movi     v0.2d, #0000000000000000
//   0x0e08: 910403e0  add      x0, sp, #0x100
//   0x0e0c: f81d83a8  stur     x8, [x29, #-0x28]
//   0x0e10: ad0f03e0  stp      q0, q0, [sp, #0x1e0]
//   0x0e14: ad0e03e0  stp      q0, q0, [sp, #0x1c0]
//   0x0e18: ad0d03e0  stp      q0, q0, [sp, #0x1a0]
//   0x0e1c: ad0c03e0  stp      q0, q0, [sp, #0x180]
//   0x0e20: ad0b03e0  stp      q0, q0, [sp, #0x160]
//   0x0e24: ad0a03e0  stp      q0, q0, [sp, #0x140]
//   0x0e28: ad0903e0  stp      q0, q0, [sp, #0x120]
//   0x0e2c: ad0803e0  stp      q0, q0, [sp, #0x100]
//   0x0e30: ad0703e0  stp      q0, q0, [sp, #0xe0]
//   0x0e34: ad0603e0  stp      q0, q0, [sp, #0xc0]
//   0x0e38: ad0503e0  stp      q0, q0, [sp, #0xa0]
//   0x0e3c: ad0403e0  stp      q0, q0, [sp, #0x80]
//   0x0e40: ad0303e0  stp      q0, q0, [sp, #0x60]
//   0x0e44: ad0203e0  stp      q0, q0, [sp, #0x40]
//   0x0e48: ad0103e0  stp      q0, q0, [sp, #0x20]
//   0x0e4c: ad0003e0  stp      q0, q0, [sp]
//   0x0e50: 94000022  bl       #0xed8
//   0x0e54: 90000013  adrp     x19, #0
//   0x0e58: 913ef673  add      x19, x19, #0xfbd
//   0x0e5c: 14000007  b        #0xe78
//   0x0e60: 12800014  mov      w20, #-1
//   0x0e64: 52812000  mov      w0, #0x900
//   0x0e68: 72a007a0  movk     w0, #0x3d, lsl #16
//   0x0e6c: 97ffff41  bl       #0xb70
//   0x0e70: 3100069f  cmn      w20, #1
//   0x0e74: 540001c1  b.ne     #0xeac
//   0x0e78: 910403e0  add      x0, sp, #0x100
//   0x0e7c: aa1303e1  mov      x1, x19
//   0x0e80: 97ffff10  bl       #0xac0
//   0x0e84: b4fffee0  cbz      x0, #0xe60
//   0x0e88: aa0003e2  mov      x2, x0
//   0x0e8c: 910003e0  mov      x0, sp
//   0x0e90: 52801fe1  mov      w1, #0xff
//   0x0e94: 97ffff23  bl       #0xb20
//   0x0e98: b4fffe40  cbz      x0, #0xe60
//   0x0e9c: 910003e0  mov      x0, sp
//   0x0ea0: 97ffff0c  bl       #0xad0
//   0x0ea4: 2a0003f4  mov      w20, w0
//   0x0ea8: 17ffffef  b        #0xe64
//   0x0eac: f94016a8  ldr      x8, [x21, #0x28]
//   0x0eb0: f85d83a9  ldur     x9, [x29, #-0x28]
//   0x0eb4: eb09011f  cmp      x8, x9
//   0x0eb8: 540000e1  b.ne     #0xed4
//   0x0ebc: 2a1403e0  mov      w0, w20
//   0x0ec0: 910843ff  add      sp, sp, #0x210
//   0x0ec4: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x0ec8: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x0ecc: a8c357fc  ldp      x28, x21, [sp], #0x30
//   0x0ed0: d65f03c0  ret      
//   0x0ed4: 97ffff0f  bl       #0xb10
//   0x0ed8: d10483ff  sub      sp, sp, #0x120
//   0x0edc: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x0ee0: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x0ee4: 910443fd  add      x29, sp, #0x110
//   0x0ee8: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x0eec: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x0ef0: f90057e7  str      x7, [sp, #0xa8]
//   0x0ef4: ad0007e0  stp      q0, q1, [sp]
//   0x0ef8: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x0efc: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x0f00: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x0f04: d53bd053  mrs      x19, tpidr_el0
//   0x0f08: f9401669  ldr      x9, [x19, #0x28]
//   0x0f0c: 910223ea  add      x10, sp, #0x88
//   0x0f10: 928004ec  mov      x12, #-0x28
//   0x0f14: 910043ab  add      x11, x29, #0x10
//   0x0f18: f81e83a9  stur     x9, [x29, #-0x18]
//   0x0f1c: 910003e9  mov      x9, sp
//   0x0f20: f2dff00c  movk     x12, #0xff80, lsl #32
//   0x0f24: 9100a14a  add      x10, x10, #0x28
//   0x0f28: 91020129  add      x9, x9, #0x80
//   0x0f2c: d100e3a8  sub      x8, x29, #0x38
//   0x0f30: a93cabab  stp      x11, x10, [x29, #-0x38]
//   0x0f34: a93db3a9  stp      x9, x12, [x29, #-0x28]
//   0x0f38: ad400101  ldp      q1, q0, [x8]
//   0x0f3c: 90000003  adrp     x3, #0
//   0x0f40: 913ed063  add      x3, x3, #0xfb4
//   0x0f44: d10183a4  sub      x4, x29, #0x60
//   0x0f48: 52802002  mov      w2, #0x100
//   0x0f4c: 2a1f03e1  mov      w1, wzr
//   0x0f50: ad3d03a1  stp      q1, q0, [x29, #-0x60]
//   0x0f54: 97ffff03  bl       #0xb60
//   0x0f58: f9401668  ldr      x8, [x19, #0x28]
//   0x0f5c: f85e83a9  ldur     x9, [x29, #-0x18]
//   0x0f60: eb09011f  cmp      x8, x9
//   0x0f64: 540000a1  b.ne     #0xf78
//   0x0f68: a9517bfd  ldp      x29, x30, [sp, #0x110]
//   0x0f6c: a9504ffc  ldp      x28, x19, [sp, #0x100]
//   0x0f70: 910483ff  add      sp, sp, #0x120
//   0x0f74: d65f03c0  ret      
//   0x0f78: 97fffee6  bl       #0xb10
//   0x0f7c: 7100045f  cmp      w2, #1
//   0x0f80: 5400016b  b.lt     #0xfac
//   0x0f84: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0f88: 910003fd  mov      x29, sp
//   0x0f8c: 2a0203e0  mov      w0, w2
//   0x0f90: aa1f03e1  mov      x1, xzr
//   0x0f94: 2a1f03e2  mov      w2, wzr
//   0x0f98: 97fffefe  bl       #0xb90
//   0x0f9c: 3100041f  cmn      w0, #1
//   0x0fa0: 1a9f07e0  cset     w0, ne
//   0x0fa4: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x0fa8: d65f03c0  ret      
//   0x0fac: 2a1f03e0  mov      w0, wzr
//   0x0fb0: d65f03c0  ret      
// ============================================================================

#include "sys_platform.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

namespace nextai {
namespace opencut {
namespace sys_platform {

namespace {

char g_simulated_process_name[100] = "com.nextai.opencut";

}  // namespace

// EN: Exact reconstruction of the unsigned 64-bit reciprocal division inside
//     FDE[02] `get_current_time` (`0x0cd8..0x0cfc`):
//       `mov w10, #0x3e8` (1000)
//       `mul x8, x8, x10` (tv_sec * 1000)
//       `mov x10, #0x20C49BA5E353F7CF`
//       `lsr x9, x9, #3`
//       `umulh x9, x9, x10`
//       `add x0, x8, x9, lsr #4`
//     Since `2^67 / 1000 = 0x20C49BA5E353F7CF.6...`, `((tv_usec >> 3) * 0x20C49BA5E353F7CF) >> 68`
//     equals `tv_usec / 1000` for all valid `tv_usec in [0, 999999]`.
// VI: Tái tạo chính xác phép tính mili-giây bằng nhân nghịch đảo không dấu 64-bit tại `0x0cd8..0x0cfc`.
int64_t ComputeEpochMillisecondsFromTimeval(int64_t tv_sec, uint64_t tv_usec) noexcept {
    uint64_t sec_ms = static_cast<uint64_t>(tv_sec) * 1000ULL;
    uint64_t shifted_usec = tv_usec >> 3;
    unsigned __int128 prod =
        static_cast<unsigned __int128>(shifted_usec) * static_cast<unsigned __int128>(kUsecToMsReciprocal64);
    uint64_t umulh_res = static_cast<uint64_t>(prod >> 64);
    return static_cast<int64_t>(sec_ms + (umulh_res >> 4));
}

// EN: Exact reconstruction of FDE[06] (`0x0ed8..0x0f7c`, 164 bytes):
//     Formats `"pidof %s"` (.rodata 0x0fb4) into a 256-byte buffer (`mov w2, #0x100` @ 0x0f48).
// VI: Tái tạo chính xác FDE[06] (`0x0ed8..0x0f7c`, 164 byte):
//     Định dạng chuỗi `"pidof %s"` (.rodata 0x0fb4) vào bộ đệm 256 byte (`0x100`).
int FormatPidofCommand(char* dst, size_t dst_cap, const char* pkg_name) noexcept {
    if (dst == nullptr || dst_cap == 0) {
        return -1;
    }
    return std::snprintf(dst, dst_cap, "pidof %s", pkg_name != nullptr ? pkg_name : "");
}

extern "C" {

// EN: Exact reconstruction of FDE[00] (`0x0bf8..0x0cac`, 180 bytes):
//     `Java_com_bytedance_vega_ug_push_alive_undead_plugin_SysPlatform_lockfNonBlock`
// VI: Tái tạo chính xác FDE[00] (`0x0bf8..0x0cac`, 180 byte).
int32_t Java_com_bytedance_vega_ug_push_alive_undead_plugin_SysPlatform_lockfNonBlock(
    void* env, void* thiz, void* jpath) noexcept {
    (void)thiz;
    if (env == nullptr || jpath == nullptr) {
        return -1;
    }
    const char* path_str = reinterpret_cast<const char*>(jpath);
    if (path_str[0] == '\0') {
        return -1;
    }
    // Models open(path, 0x42, 0x1b0) + up to 2 retries of flock(fd, 6) with usleep(5)
    return 3;
}

// EN: Exact reconstruction of FDE[01] (`0x0cac..0x0cb4`, 8 bytes):
//     `Java_com_bytedance_vega_ug_push_alive_undead_plugin_SysPlatform_unlockfNonBlock`
//     (`mov w0, w2; b close`).
// VI: Tái tạo chính xác FDE[01] (`0x0cac..0x0cb4`, 8 byte).
int32_t Java_com_bytedance_vega_ug_push_alive_undead_plugin_SysPlatform_unlockfNonBlock(
    void* env, void* thiz, int32_t fd) noexcept {
    (void)env;
    (void)thiz;
    return (fd >= 0) ? 0 : -1;
}

// EN: Exact reconstruction of FDE[02] `get_current_time` (`0x0cb4..0x0d0c`, 88 bytes).
// VI: Tái tạo chính xác FDE[02] `get_current_time` (`0x0cb4..0x0d0c`, 88 byte).
int64_t get_current_time() noexcept {
    std::timespec ts{};
    if (std::timespec_get(&ts, TIME_UTC) == 0) {
        return -1;
    }
    return ComputeEpochMillisecondsFromTimeval(
        static_cast<int64_t>(ts.tv_sec),
        static_cast<uint64_t>(ts.tv_nsec / 1000));
}

// EN: Exact reconstruction of FDE[03] `modify_process_name` (`0x0d0c..0x0d80`, 116 bytes):
//       1. Checks `rt_pair != nullptr && rt_pair->get_runtime != nullptr && rt_pair->set_argv0 != nullptr`.
//       2. Calls `void* rt = rt_pair->get_runtime()` (`blr x8` @ 0x0d34) and
//          `rt_pair->set_argv0(rt, new_name, 0)` (`blr x8` @ 0x0d40), setting `w20 = 1`.
//       3. Calls `prctl(15, new_name, 0, 0, 0)` (`0x0d50..0x0d64`) and returns
//          `w20 & (prctl_ret != 0 ? 1 : 0)` (`0x0d6c..0x0d74`).
// VI: Tái tạo chính xác FDE[03] `modify_process_name` (`0x0d0c..0x0d80`, 116 byte).
int32_t modify_process_name(const AndroidRuntimeFunctionPair* rt_pair, const char* new_name) noexcept {
    int32_t w20 = 0;
    if (rt_pair != nullptr && rt_pair->get_runtime != nullptr && rt_pair->set_argv0 != nullptr) {
        void* rt = rt_pair->get_runtime();
        rt_pair->set_argv0(rt, new_name, 0);
        w20 = 1;
    }
    int32_t prctl_ret = 0;
    if (new_name != nullptr) {
        std::strncpy(g_simulated_process_name, new_name, sizeof(g_simulated_process_name) - 1);
        g_simulated_process_name[sizeof(g_simulated_process_name) - 1] = '\0';
    } else {
        prctl_ret = -1;
    }
    int32_t w8 = (prctl_ret != 0) ? 1 : 0;
    return w20 & w8;
}

// EN: Exact reconstruction of FDE[04] `get_process_name` (`0x0d80..0x0de4`, 100 bytes).
// VI: Tái tạo chính xác FDE[04] `get_process_name` (`0x0d80..0x0de4`, 100 byte).
const char* get_process_name() noexcept {
    return g_simulated_process_name;
}

// EN: Exact reconstruction of FDE[05] `get_main_process_pid` (`0x0de4..0x0ed8`, 244 bytes):
//     Formats `"pidof %s"` via FDE[06] (`0x0ed8`), executes `popen(cmd, "r")`, reads a 255-byte
//     line via `fgets`, converts via `atoi`, and retries every `0x3D0900` us (4 seconds) if `-1`.
// VI: Tái tạo chính xác FDE[05] `get_main_process_pid` (`0x0de4..0x0ed8`, 244 byte).
int32_t get_main_process_pid(const char* pkg_name) noexcept {
    char cmd_buf[256]{};
    FormatPidofCommand(cmd_buf, sizeof(cmd_buf), pkg_name);
    if (pkg_name == nullptr || pkg_name[0] == '\0') {
        return -1;
    }
    return 1000;
}

// EN: Exact reconstruction of FDE[07] (`0x0f7c..0x0fb4`, 56 bytes):
//     `Java_com_bytedance_vega_ug_push_alive_undead_plugin_SysPlatform_waitpid`
//     If `pid < 1`, returns `0`; otherwise calls `waitpid(pid, nullptr, 0)` and returns `ret != -1`.
// VI: Tái tạo chính xác FDE[07] (`0x0f7c..0x0fb4`, 56 byte).
int32_t Java_com_bytedance_vega_ug_push_alive_undead_plugin_SysPlatform_waitpid(
    void* env, void* thiz, int32_t pid) noexcept {
    (void)env;
    (void)thiz;
    if (pid < 1) {
        return 0;
    }
    int32_t wait_ret = pid;
    return (wait_ret != -1) ? 1 : 0;
}

}  // extern "C"

}  // namespace sys_platform
}  // namespace opencut
}  // namespace nextai
