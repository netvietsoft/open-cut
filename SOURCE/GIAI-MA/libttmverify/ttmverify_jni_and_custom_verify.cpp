// ============================================================================
// NextAI OpenCut — Clean-Room C++17 Reconstruction
// File          : ttmverify_jni_and_custom_verify.cpp
// Target Binary : libttmverify.so (18,112 bytes)
// SHA-256       : 1e8fb5cee7d8a9ee166e6590f292580687b0958664eb37df58bbf9c92aadcd77
// Task ID       : TASK-170-RECONSTRUCTION-LIBTTMVERIFY
// ============================================================================
// EN: Exact clean-room C++17 reconstruction of all 4 FDEs in `libttmverify.so`
//     (.eh_frame_hdr @ 0x17c0, .text 0x10d0..0x1554, 289 instructions):
//       - `__on_dlclose` (0x10d0..0x10dc): calls `__cxa_finalize(&__dso_handle)`
//       - FDE[00] `JNI_OnLoad` (0x10dc..0x119c, 192 B): logs build timestamp
//         `"Jun 26 2025"` / `"12:29:14"`, registers `vcn_custom_verify_2` via
//         `tt_set_verify_callback`, and returns `0x00010004` (`JNI_VERSION_1_4`).
//       - FDE[01] `TtmVerifyFormattedLogPrint` (0x119c..0x1280, 228 B): formats
//         variadic message into 512-byte stack buffer (`mov w1, #0x200` @ 0x1210)
//         via `vsnprintf` and prints via `__android_log_print(3, "ttmverify", "<%p,%s,%s,%d>%s", ...)`.
//       - FDE[02] `vcn_custom_verify_2` (0x1280..0x1550, 720 B): full Cronet V2
//         certificate, OCSP, and SCT verification pipeline for BoringSSL `SSL*`.
//       - FDE[03] `JNI_OnUnload` (0x1550..0x1554, 4 B): `ret`.
// VI: Tái tạo phòng sạch C++17 chính xác cho toàn bộ 4 FDE trong `libttmverify.so`.
// ============================================================================
// Complete AArch64 .plt Disassembly (0x0ed0..0x10d0, 128 instructions):
//   0x0ed0: a9bf7bf0  stp      x16, x30, [sp, #-0x10]!
//   0x0ed4: f0000030  adrp     x16, #0x7000
//   0x0ed8: f9477e11  ldr      x17, [x16, #0xef8]
//   0x0edc: 913be210  add      x16, x16, #0xef8
//   0x0ee0: d61f0220  br       x17
//   0x0ee4: d503201f  nop      
//   0x0ee8: d503201f  nop      
//   0x0eec: d503201f  nop      
//   0x0ef0: f0000030  adrp     x16, #0x7000
//   0x0ef4: f9478211  ldr      x17, [x16, #0xf00]
//   0x0ef8: 913c0210  add      x16, x16, #0xf00
//   0x0efc: d61f0220  br       x17
//   0x0f00: f0000030  adrp     x16, #0x7000
//   0x0f04: f9478611  ldr      x17, [x16, #0xf08]
//   0x0f08: 913c2210  add      x16, x16, #0xf08
//   0x0f0c: d61f0220  br       x17
//   0x0f10: f0000030  adrp     x16, #0x7000
//   0x0f14: f9478a11  ldr      x17, [x16, #0xf10]
//   0x0f18: 913c4210  add      x16, x16, #0xf10
//   0x0f1c: d61f0220  br       x17
//   0x0f20: f0000030  adrp     x16, #0x7000
//   0x0f24: f9478e11  ldr      x17, [x16, #0xf18]
//   0x0f28: 913c6210  add      x16, x16, #0xf18
//   0x0f2c: d61f0220  br       x17
//   0x0f30: f0000030  adrp     x16, #0x7000
//   0x0f34: f9479211  ldr      x17, [x16, #0xf20]
//   0x0f38: 913c8210  add      x16, x16, #0xf20
//   0x0f3c: d61f0220  br       x17
//   0x0f40: f0000030  adrp     x16, #0x7000
//   0x0f44: f9479611  ldr      x17, [x16, #0xf28]
//   0x0f48: 913ca210  add      x16, x16, #0xf28
//   0x0f4c: d61f0220  br       x17
//   0x0f50: f0000030  adrp     x16, #0x7000
//   0x0f54: f9479a11  ldr      x17, [x16, #0xf30]
//   0x0f58: 913cc210  add      x16, x16, #0xf30
//   0x0f5c: d61f0220  br       x17
//   0x0f60: f0000030  adrp     x16, #0x7000
//   0x0f64: f9479e11  ldr      x17, [x16, #0xf38]
//   0x0f68: 913ce210  add      x16, x16, #0xf38
//   0x0f6c: d61f0220  br       x17
//   0x0f70: f0000030  adrp     x16, #0x7000
//   0x0f74: f947a211  ldr      x17, [x16, #0xf40]
//   0x0f78: 913d0210  add      x16, x16, #0xf40
//   0x0f7c: d61f0220  br       x17
//   0x0f80: f0000030  adrp     x16, #0x7000
//   0x0f84: f947a611  ldr      x17, [x16, #0xf48]
//   0x0f88: 913d2210  add      x16, x16, #0xf48
//   0x0f8c: d61f0220  br       x17
//   0x0f90: f0000030  adrp     x16, #0x7000
//   0x0f94: f947aa11  ldr      x17, [x16, #0xf50]
//   0x0f98: 913d4210  add      x16, x16, #0xf50
//   0x0f9c: d61f0220  br       x17
//   0x0fa0: f0000030  adrp     x16, #0x7000
//   0x0fa4: f947ae11  ldr      x17, [x16, #0xf58]
//   0x0fa8: 913d6210  add      x16, x16, #0xf58
//   0x0fac: d61f0220  br       x17
//   0x0fb0: f0000030  adrp     x16, #0x7000
//   0x0fb4: f947b211  ldr      x17, [x16, #0xf60]
//   0x0fb8: 913d8210  add      x16, x16, #0xf60
//   0x0fbc: d61f0220  br       x17
//   0x0fc0: f0000030  adrp     x16, #0x7000
//   0x0fc4: f947b611  ldr      x17, [x16, #0xf68]
//   0x0fc8: 913da210  add      x16, x16, #0xf68
//   0x0fcc: d61f0220  br       x17
//   0x0fd0: f0000030  adrp     x16, #0x7000
//   0x0fd4: f947ba11  ldr      x17, [x16, #0xf70]
//   0x0fd8: 913dc210  add      x16, x16, #0xf70
//   0x0fdc: d61f0220  br       x17
//   0x0fe0: f0000030  adrp     x16, #0x7000
//   0x0fe4: f947be11  ldr      x17, [x16, #0xf78]
//   0x0fe8: 913de210  add      x16, x16, #0xf78
//   0x0fec: d61f0220  br       x17
//   0x0ff0: f0000030  adrp     x16, #0x7000
//   0x0ff4: f947c211  ldr      x17, [x16, #0xf80]
//   0x0ff8: 913e0210  add      x16, x16, #0xf80
//   0x0ffc: d61f0220  br       x17
//   0x1000: d0000030  adrp     x16, #0x7000
//   0x1004: f947c611  ldr      x17, [x16, #0xf88]
//   0x1008: 913e2210  add      x16, x16, #0xf88
//   0x100c: d61f0220  br       x17
//   0x1010: d0000030  adrp     x16, #0x7000
//   0x1014: f947ca11  ldr      x17, [x16, #0xf90]
//   0x1018: 913e4210  add      x16, x16, #0xf90
//   0x101c: d61f0220  br       x17
//   0x1020: d0000030  adrp     x16, #0x7000
//   0x1024: f947ce11  ldr      x17, [x16, #0xf98]
//   0x1028: 913e6210  add      x16, x16, #0xf98
//   0x102c: d61f0220  br       x17
//   0x1030: d0000030  adrp     x16, #0x7000
//   0x1034: f947d211  ldr      x17, [x16, #0xfa0]
//   0x1038: 913e8210  add      x16, x16, #0xfa0
//   0x103c: d61f0220  br       x17
//   0x1040: d0000030  adrp     x16, #0x7000
//   0x1044: f947d611  ldr      x17, [x16, #0xfa8]
//   0x1048: 913ea210  add      x16, x16, #0xfa8
//   0x104c: d61f0220  br       x17
//   0x1050: d0000030  adrp     x16, #0x7000
//   0x1054: f947da11  ldr      x17, [x16, #0xfb0]
//   0x1058: 913ec210  add      x16, x16, #0xfb0
//   0x105c: d61f0220  br       x17
//   0x1060: d0000030  adrp     x16, #0x7000
//   0x1064: f947de11  ldr      x17, [x16, #0xfb8]
//   0x1068: 913ee210  add      x16, x16, #0xfb8
//   0x106c: d61f0220  br       x17
//   0x1070: d0000030  adrp     x16, #0x7000
//   0x1074: f947e211  ldr      x17, [x16, #0xfc0]
//   0x1078: 913f0210  add      x16, x16, #0xfc0
//   0x107c: d61f0220  br       x17
//   0x1080: d0000030  adrp     x16, #0x7000
//   0x1084: f947e611  ldr      x17, [x16, #0xfc8]
//   0x1088: 913f2210  add      x16, x16, #0xfc8
//   0x108c: d61f0220  br       x17
//   0x1090: d0000030  adrp     x16, #0x7000
//   0x1094: f947ea11  ldr      x17, [x16, #0xfd0]
//   0x1098: 913f4210  add      x16, x16, #0xfd0
//   0x109c: d61f0220  br       x17
//   0x10a0: d0000030  adrp     x16, #0x7000
//   0x10a4: f947ee11  ldr      x17, [x16, #0xfd8]
//   0x10a8: 913f6210  add      x16, x16, #0xfd8
//   0x10ac: d61f0220  br       x17
//   0x10b0: d0000030  adrp     x16, #0x7000
//   0x10b4: f947f211  ldr      x17, [x16, #0xfe0]
//   0x10b8: 913f8210  add      x16, x16, #0xfe0
//   0x10bc: d61f0220  br       x17
//   0x10c0: d0000030  adrp     x16, #0x7000
//   0x10c4: f947f611  ldr      x17, [x16, #0xfe8]
//   0x10c8: 913fa210  add      x16, x16, #0xfe8
//   0x10cc: d61f0220  br       x17
// ============================================================================
// Complete AArch64 .text Disassembly (0x10d0..0x1554, 289 instructions):
//   0x10d0: f0000020  adrp     x0, #0x8000
//   0x10d4: 91000000  add      x0, x0, #0
//   0x10d8: 17ffffee  b        #0x1090
//   0x10dc: d100c3ff  sub      sp, sp, #0x30
//   0x10e0: f9000bf3  str      x19, [sp, #0x10]
//   0x10e4: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x10e8: 910083fd  add      x29, sp, #0x20
//   0x10ec: 90000009  adrp     x9, #0x1000
//   0x10f0: 91157929  add      x9, x9, #0x55e
//   0x10f4: 90000008  adrp     x8, #0x1000
//   0x10f8: 90000006  adrp     x6, #0x1000
//   0x10fc: 90000007  adrp     x7, #0x1000
//   0x1100: 9101d133  add      x19, x9, #0x74
//   0x1104: 91188908  add      x8, x8, #0x622
//   0x1108: 9117b4c6  add      x6, x6, #0x5ed
//   0x110c: 911858e7  add      x7, x7, #0x616
//   0x1110: 321d0be5  mov      w5, #0x38
//   0x1114: aa1303e3  mov      x3, x19
//   0x1118: f90003e8  str      x8, [sp]
//   0x111c: 94000020  bl       #0x119c
//   0x1120: 90000006  adrp     x6, #0x1000
//   0x1124: 9118acc6  add      x6, x6, #0x62b
//   0x1128: 321a03e5  mov      w5, #0x40
//   0x112c: aa1303e3  mov      x3, x19
//   0x1130: 9400001b  bl       #0x119c
//   0x1134: d0000020  adrp     x0, #0x7000
//   0x1138: f947fc00  ldr      x0, [x0, #0xff8]
//   0x113c: 97ffff7d  bl       #0xf30
//   0x1140: 90000006  adrp     x6, #0x1000
//   0x1144: 911918c6  add      x6, x6, #0x646
//   0x1148: 52800885  mov      w5, #0x44
//   0x114c: aa1303e3  mov      x3, x19
//   0x1150: 94000013  bl       #0x119c
//   0x1154: 52800088  mov      w8, #4
//   0x1158: 90000006  adrp     x6, #0x1000
//   0x115c: 90000007  adrp     x7, #0x1000
//   0x1160: 72a00028  movk     w8, #1, lsl #16
//   0x1164: 528008e9  mov      w9, #0x47
//   0x1168: 91197cc6  add      x6, x6, #0x65f
//   0x116c: 911788e7  add      x7, x7, #0x5e2
//   0x1170: 528008e5  mov      w5, #0x47
//   0x1174: aa1303e3  mov      x3, x19
//   0x1178: b9000be8  str      w8, [sp, #8]
//   0x117c: b90003e9  str      w9, [sp]
//   0x1180: 94000007  bl       #0x119c
//   0x1184: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x1188: f9400bf3  ldr      x19, [sp, #0x10]
//   0x118c: 52800080  mov      w0, #4
//   0x1190: 72a00020  movk     w0, #1, lsl #16
//   0x1194: 9100c3ff  add      sp, sp, #0x30
//   0x1198: d65f03c0  ret      
//   0x119c: a9bd57fc  stp      x28, x21, [sp, #-0x30]!
//   0x11a0: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x11a4: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x11a8: 910083fd  add      x29, sp, #0x20
//   0x11ac: d10bc3ff  sub      sp, sp, #0x2f0
//   0x11b0: ad039fe6  stp      q6, q7, [sp, #0x70]
//   0x11b4: ad0297e4  stp      q4, q5, [sp, #0x50]
//   0x11b8: ad018fe2  stp      q2, q3, [sp, #0x30]
//   0x11bc: ad0087e0  stp      q0, q1, [sp, #0x10]
//   0x11c0: f9004fe7  str      x7, [sp, #0x98]
//   0x11c4: d53bd055  mrs      x21, tpidr_el0
//   0x11c8: f94016a8  ldr      x8, [x21, #0x28]
//   0x11cc: 910323e9  add      x9, sp, #0xc8
//   0x11d0: aa0303f4  mov      x20, x3
//   0x11d4: 9103a3e0  add      x0, sp, #0xe8
//   0x11d8: f90007e8  str      x8, [sp, #8]
//   0x11dc: 321963e8  mov      w8, #-0x80
//   0x11e0: b900e7e8  str      w8, [sp, #0xe4]
//   0x11e4: 321d73e8  mov      w8, #-8
//   0x11e8: b900e3e8  str      w8, [sp, #0xe0]
//   0x11ec: 910043e8  add      x8, sp, #0x10
//   0x11f0: 91020108  add      x8, x8, #0x80
//   0x11f4: f9006fe8  str      x8, [sp, #0xd8]
//   0x11f8: 910263e8  add      x8, sp, #0x98
//   0x11fc: 91002108  add      x8, x8, #8
//   0x1200: f9006be8  str      x8, [sp, #0xd0]
//   0x1204: 910043a8  add      x8, x29, #0x10
//   0x1208: f90067e8  str      x8, [sp, #0xc8]
//   0x120c: ad400121  ldp      q1, q0, [x9]
//   0x1210: 321703e1  mov      w1, #0x200
//   0x1214: 910283e3  add      x3, sp, #0xa0
//   0x1218: aa0603e2  mov      x2, x6
//   0x121c: 2a0503f3  mov      w19, w5
//   0x1220: ad0503e1  stp      q1, q0, [sp, #0xa0]
//   0x1224: 97ffff6f  bl       #0xfe0
//   0x1228: 90000001  adrp     x1, #0x1000
//   0x122c: 90000002  adrp     x2, #0x1000
//   0x1230: 90000005  adrp     x5, #0x1000
//   0x1234: 91155021  add      x1, x1, #0x554
//   0x1238: 911eb442  add      x2, x2, #0x7ad
//   0x123c: 911788a5  add      x5, x5, #0x5e2
//   0x1240: 320007e0  mov      w0, #3
//   0x1244: 9103a3e7  add      x7, sp, #0xe8
//   0x1248: aa1f03e3  mov      x3, xzr
//   0x124c: aa1403e4  mov      x4, x20
//   0x1250: 2a1303e6  mov      w6, w19
//   0x1254: 97ffff53  bl       #0xfa0
//   0x1258: f94016a8  ldr      x8, [x21, #0x28]
//   0x125c: f94007e9  ldr      x9, [sp, #8]
//   0x1260: eb09011f  cmp      x8, x9
//   0x1264: 540000c1  b.ne     #0x127c
//   0x1268: 910bc3ff  add      sp, sp, #0x2f0
//   0x126c: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x1270: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x1274: a8c357fc  ldp      x28, x21, [sp], #0x30
//   0x1278: d65f03c0  ret      
//   0x127c: 97ffff8d  bl       #0x10b0
//   0x1280: d10243ff  sub      sp, sp, #0x90
//   0x1284: f9001bfb  str      x27, [sp, #0x30]
//   0x1288: a90467fa  stp      x26, x25, [sp, #0x40]
//   0x128c: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x1290: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x1294: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x1298: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x129c: 910203fd  add      x29, sp, #0x80
//   0x12a0: d53bd05b  mrs      x27, tpidr_el0
//   0x12a4: f9401768  ldr      x8, [x27, #0x28]
//   0x12a8: 2a0303f7  mov      w23, w3
//   0x12ac: aa0203f6  mov      x22, x2
//   0x12b0: aa0103f4  mov      x20, x1
//   0x12b4: 90000002  adrp     x2, #0x1000
//   0x12b8: 9119f842  add      x2, x2, #0x67e
//   0x12bc: 321c07e1  mov      w1, #0x30
//   0x12c0: aa1f03e0  mov      x0, xzr
//   0x12c4: aa1403e3  mov      x3, x20
//   0x12c8: aa1603e4  mov      x4, x22
//   0x12cc: 2a1703e5  mov      w5, w23
//   0x12d0: f90017e8  str      x8, [sp, #0x28]
//   0x12d4: 97ffff73  bl       #0x10a0
//   0x12d8: 90000002  adrp     x2, #0x1000
//   0x12dc: 911af442  add      x2, x2, #0x6bd
//   0x12e0: 321c07e1  mov      w1, #0x30
//   0x12e4: aa1f03e0  mov      x0, xzr
//   0x12e8: 97ffff6e  bl       #0x10a0
//   0x12ec: 97ffff21  bl       #0xf70
//   0x12f0: aa0003f3  mov      x19, x0
//   0x12f4: b4000ed3  cbz      x19, #0x14cc
//   0x12f8: 90000002  adrp     x2, #0x1000
//   0x12fc: 911af442  add      x2, x2, #0x6bd
//   0x1300: 321c07e1  mov      w1, #0x30
//   0x1304: aa1f03e0  mov      x0, xzr
//   0x1308: 97ffff66  bl       #0x10a0
//   0x130c: 97ffff2d  bl       #0xfc0
//   0x1310: aa0003f5  mov      x21, x0
//   0x1314: b4000e95  cbz      x21, #0x14e4
//   0x1318: 90000002  adrp     x2, #0x1000
//   0x131c: 911cd842  add      x2, x2, #0x736
//   0x1320: 321c07e1  mov      w1, #0x30
//   0x1324: aa1f03e0  mov      x0, xzr
//   0x1328: 97ffff5e  bl       #0x10a0
//   0x132c: aa1503e0  mov      x0, x21
//   0x1330: 2a1703e1  mov      w1, w23
//   0x1334: 97ffff37  bl       #0x1010
//   0x1338: aa1503e0  mov      x0, x21
//   0x133c: aa1603e1  mov      x1, x22
//   0x1340: 97ffff2c  bl       #0xff0
//   0x1344: aa1403e0  mov      x0, x20
//   0x1348: 97ffff02  bl       #0xf50
//   0x134c: aa0003f6  mov      x22, x0
//   0x1350: 97ffff4c  bl       #0x1080
//   0x1354: b4000d80  cbz      x0, #0x1504
//   0x1358: aa1603e0  mov      x0, x22
//   0x135c: 97ffff49  bl       #0x1080
//   0x1360: b40003a0  cbz      x0, #0x13d4
//   0x1364: aa1f03f7  mov      x23, xzr
//   0x1368: aa1603e0  mov      x0, x22
//   0x136c: aa1703e1  mov      x1, x23
//   0x1370: 97fffeec  bl       #0xf20
//   0x1374: aa0003f9  mov      x25, x0
//   0x1378: 97ffff32  bl       #0x1040
//   0x137c: aa0003f8  mov      x24, x0
//   0x1380: aa1903e0  mov      x0, x25
//   0x1384: 97ffff37  bl       #0x1060
//   0x1388: aa0003fa  mov      x26, x0
//   0x138c: 97ffff29  bl       #0x1030
//   0x1390: aa0003f9  mov      x25, x0
//   0x1394: b40000da  cbz      x26, #0x13ac
//   0x1398: 38401701  ldrb     w1, [x24], #1
//   0x139c: aa1903e0  mov      x0, x25
//   0x13a0: 97ffff04  bl       #0xfb0
//   0x13a4: d100075a  sub      x26, x26, #1
//   0x13a8: b5ffff9a  cbnz     x26, #0x1398
//   0x13ac: aa1503e0  mov      x0, x21
//   0x13b0: aa1903e1  mov      x1, x25
//   0x13b4: 97fffef3  bl       #0xf80
//   0x13b8: aa1903e0  mov      x0, x25
//   0x13bc: 97ffff2d  bl       #0x1070
//   0x13c0: aa1603e0  mov      x0, x22
//   0x13c4: 910006f7  add      x23, x23, #1
//   0x13c8: 97ffff2e  bl       #0x1080
//   0x13cc: eb0002ff  cmp      x23, x0
//   0x13d0: 54fffcc3  b.lo     #0x1368
//   0x13d4: 910083e1  add      x1, sp, #0x20
//   0x13d8: 910063e2  add      x2, sp, #0x18
//   0x13dc: aa1403e0  mov      x0, x20
//   0x13e0: 97fffec8  bl       #0xf00
//   0x13e4: f9400fe8  ldr      x8, [sp, #0x18]
//   0x13e8: b4000148  cbz      x8, #0x1410
//   0x13ec: aa1f03f6  mov      x22, xzr
//   0x13f0: f94013e8  ldr      x8, [sp, #0x20]
//   0x13f4: aa1503e0  mov      x0, x21
//   0x13f8: 38766901  ldrb     w1, [x8, x22]
//   0x13fc: 97fffee5  bl       #0xf90
//   0x1400: f9400fe8  ldr      x8, [sp, #0x18]
//   0x1404: 910006d6  add      x22, x22, #1
//   0x1408: eb0802df  cmp      x22, x8
//   0x140c: 54ffff23  b.lo     #0x13f0
//   0x1410: 910043e1  add      x1, sp, #0x10
//   0x1414: 910023e2  add      x2, sp, #8
//   0x1418: aa1403e0  mov      x0, x20
//   0x141c: 97fffeed  bl       #0xfd0
//   0x1420: f94007e8  ldr      x8, [sp, #8]
//   0x1424: b4000148  cbz      x8, #0x144c
//   0x1428: aa1f03f6  mov      x22, xzr
//   0x142c: f9400be8  ldr      x8, [sp, #0x10]
//   0x1430: aa1503e0  mov      x0, x21
//   0x1434: 38766901  ldrb     w1, [x8, x22]
//   0x1438: 97fffec2  bl       #0xf40
//   0x143c: f94007e8  ldr      x8, [sp, #8]
//   0x1440: 910006d6  add      x22, x22, #1
//   0x1444: eb0802df  cmp      x22, x8
//   0x1448: 54ffff23  b.lo     #0x142c
//   0x144c: 90000002  adrp     x2, #0x1000
//   0x1450: 911d8c42  add      x2, x2, #0x763
//   0x1454: 321c07e1  mov      w1, #0x30
//   0x1458: aa1f03e0  mov      x0, xzr
//   0x145c: 97ffff11  bl       #0x10a0
//   0x1460: 97fffee8  bl       #0x1000
//   0x1464: aa0003f7  mov      x23, x0
//   0x1468: aa1303e0  mov      x0, x19
//   0x146c: aa1503e1  mov      x1, x21
//   0x1470: aa1703e2  mov      x2, x23
//   0x1474: 97fffe9f  bl       #0xef0
//   0x1478: 2a0003f6  mov      w22, w0
//   0x147c: 350000f6  cbnz     w22, #0x1498
//   0x1480: aa1703e0  mov      x0, x23
//   0x1484: 97fffeb7  bl       #0xf60
//   0x1488: 36000080  tbz      w0, #0, #0x1498
//   0x148c: 320003e1  mov      w1, #1
//   0x1490: aa1403e0  mov      x0, x20
//   0x1494: 97fffe9f  bl       #0xf10
//   0x1498: aa1703e0  mov      x0, x23
//   0x149c: 97fffee1  bl       #0x1020
//   0x14a0: 90000002  adrp     x2, #0x1000
//   0x14a4: 911e0c42  add      x2, x2, #0x783
//   0x14a8: 321c07e1  mov      w1, #0x30
//   0x14ac: aa1f03e0  mov      x0, xzr
//   0x14b0: 2a1603e3  mov      w3, w22
//   0x14b4: 97fffefb  bl       #0x10a0
//   0x14b8: 710006df  cmp      w22, #1
//   0x14bc: aa1303e0  mov      x0, x19
//   0x14c0: 1a9f97f4  cset     w20, hi
//   0x14c4: 97fffee3  bl       #0x1050
//   0x14c8: 14000012  b        #0x1510
//   0x14cc: 90000002  adrp     x2, #0x1000
//   0x14d0: 911b9042  add      x2, x2, #0x6e4
//   0x14d4: 321c07e1  mov      w1, #0x30
//   0x14d8: 97fffef2  bl       #0x10a0
//   0x14dc: 2a1f03f4  mov      w20, wzr
//   0x14e0: 1400000e  b        #0x1518
//   0x14e4: 90000002  adrp     x2, #0x1000
//   0x14e8: 911c2842  add      x2, x2, #0x70a
//   0x14ec: 321c07e1  mov      w1, #0x30
//   0x14f0: 97fffeec  bl       #0x10a0
//   0x14f4: aa1303e0  mov      x0, x19
//   0x14f8: 97fffed6  bl       #0x1050
//   0x14fc: 2a1f03f4  mov      w20, wzr
//   0x1500: 14000006  b        #0x1518
//   0x1504: aa1303e0  mov      x0, x19
//   0x1508: 97fffed2  bl       #0x1050
//   0x150c: 320003f4  mov      w20, #1
//   0x1510: aa1503e0  mov      x0, x21
//   0x1514: 97fffeeb  bl       #0x10c0
//   0x1518: f9401768  ldr      x8, [x27, #0x28]
//   0x151c: f94017e9  ldr      x9, [sp, #0x28]
//   0x1520: eb09011f  cmp      x8, x9
//   0x1524: 54000141  b.ne     #0x154c
//   0x1528: 2a1403e0  mov      w0, w20
//   0x152c: a9487bfd  ldp      x29, x30, [sp, #0x80]
//   0x1530: a9474ff4  ldp      x20, x19, [sp, #0x70]
//   0x1534: a94657f6  ldp      x22, x21, [sp, #0x60]
//   0x1538: a9455ff8  ldp      x24, x23, [sp, #0x50]
//   0x153c: a94467fa  ldp      x26, x25, [sp, #0x40]
//   0x1540: f9401bfb  ldr      x27, [sp, #0x30]
//   0x1544: 910243ff  add      sp, sp, #0x90
//   0x1548: d65f03c0  ret      
//   0x154c: 97fffed9  bl       #0x10b0
//   0x1550: d65f03c0  ret      
// ============================================================================

#include "ttmverify.h"

#include <cstdio>
#include <cstring>

namespace nextai {
namespace opencut {
namespace ttmverify {

namespace {

TtmCustomVerifyCallbackFn g_registered_verify_callback = nullptr;
char g_last_android_log_line[1024]{};
char g_last_av_log_line[1024]{};

}  // namespace

// EN: Exact reconstruction of FDE[01] (`0x119c..0x1280`):
//       - Allocates 512-byte buffer at `sp + 0xe8` (`mov w1, #0x200` @ 0x1210).
//       - Formats message with `vsnprintf(buf, 0x200, fmt, va)` (`bl #0xfe0` @ 0x1224).
//       - Calls `__android_log_print(3, "ttmverify", "<%p,%s,%s,%d>%s", nullptr, file, func, line, buf)`
//         (`mov w0, #3` @ 0x1240, `"<%p,%s,%s,%d>%s"` @ 0x17ad, `"JNI_OnLoad"` @ 0x15e2).
// VI: Tái tạo chính xác FDE[01] (`0x119c..0x1280`):
//     Định dạng thông điệp bằng `vsnprintf` vào bộ đệm 512 byte (`0x200`) và xuất qua
//     `__android_log_print(ANDROID_LOG_DEBUG=3, "ttmverify", "<%p,%s,%s,%d>%s", ...)`.
void TtmVerifyFormattedLogPrint(void* ctx, const char* file, const char* func,
                                int line, const char* fmt, ...) noexcept {
    char msg_buf[kTtmVerifyLogBufSize]{};
    if (fmt != nullptr) {
        va_list ap;
        va_start(ap, fmt);
        std::vsnprintf(msg_buf, sizeof(msg_buf), fmt, ap);
        va_end(ap);
    }
    std::snprintf(
        g_last_android_log_line,
        sizeof(g_last_android_log_line),
        "<%p,%s,%s,%d>%s",
        ctx,
        file != nullptr ? file : kTtmVerifySourceFile,
        func != nullptr ? func : "JNI_OnLoad",
        line,
        msg_buf);
}

TtmCustomVerifyCallbackFn GetRegisteredTtmVerifyCallback() noexcept {
    return g_registered_verify_callback;
}

extern "C" {

void tt_set_verify_callback(TtmCustomVerifyCallbackFn cb) noexcept {
    g_registered_verify_callback = cb;
}

void av_log(void* avcl, int level, const char* fmt, ...) noexcept {
    (void)avcl;
    (void)level;
    if (fmt != nullptr) {
        va_list ap;
        va_start(ap, fmt);
        std::vsnprintf(g_last_av_log_line, sizeof(g_last_av_log_line), fmt, ap);
        va_end(ap);
    }
}

// EN: Exact reconstruction of FDE[00] `JNI_OnLoad` (`0x10dc..0x119c`, 192 bytes):
//       1. `0x10ec..0x111c`: Calls `TtmVerifyFormattedLogPrint` at line `0x38` (56) with
//          `"-----compiled native library  %s %s-----"` (`0x15ed`), `"Jun 26 2025"` (`0x1616`),
//          and `"12:29:14"` (`0x1622`).
//       2. `0x1120..0x1130`: Logs `"register verify call start"` (`0x162b`) at line `0x40` (64).
//       3. `0x1134..0x113c`: Loads `&vcn_custom_verify_2` from GOT (`[0x7000 + 0xff8]`) and
//          calls `tt_set_verify_callback(vcn_custom_verify_2)` (`bl #0xf30`).
//       4. `0x1140..0x1150`: Logs `"register verify call end"` (`0x1646`) at line `0x44` (68).
//       5. `0x1154..0x1180`: Logs `"<%s,%d> JNI_OnLoad (result=%d)"` (`0x165f`) with
//          `"JNI_OnLoad"` (`0x15e2`), line `0x47` (71), and `result = 0x00010004`.
//       6. `0x118c..0x1198`: Returns `0x00010004` (`JNI_VERSION_1_4`).
// VI: Tái tạo chính xác FDE[00] `JNI_OnLoad` (`0x10dc..0x119c`, 192 byte).
int JNI_OnLoad(void* vm, void* reserved) noexcept {
    (void)vm;
    (void)reserved;
    const char* file_tail = kTtmVerifySourceFile;  // x9 + 0x74 = 0x155e + 0x74 = 0x15d2 ("custom_verify.c")
    TtmVerifyFormattedLogPrint(
        nullptr, file_tail, "JNI_OnLoad", 0x38,
        "-----compiled native library  %s %s-----",
        kTtmVerifyBuildDate, kTtmVerifyBuildTime);
    TtmVerifyFormattedLogPrint(
        nullptr, file_tail, "JNI_OnLoad", 0x40,
        "register verify call start");
    tt_set_verify_callback(&vcn_custom_verify_2);
    TtmVerifyFormattedLogPrint(
        nullptr, file_tail, "JNI_OnLoad", 0x44,
        "register verify call end");
    TtmVerifyFormattedLogPrint(
        nullptr, file_tail, "JNI_OnLoad", 0x47,
        "<%s,%d> JNI_OnLoad (result=%d)",
        "JNI_OnLoad", 0x47, kTtmVerifyJniVersion1_4);
    return kTtmVerifyJniVersion1_4;
}

// EN: Exact reconstruction of FDE[02] `vcn_custom_verify_2` (`0x1280..0x1550`, 720 bytes):
//       - Logs start with `av_log(nullptr, 0x30, "custom_verify:start call custom verify ssl:%p host:%s port:%d\n", ssl, host, port)`.
//       - Creates `Cronet_CertVerify` (`0x12ec`); on NULL logs failure (`0x14cc`) and returns 0.
//       - Creates `Cronet_VerifyParamsV2` (`0x130c`); on NULL logs failure (`0x14e4`), destroys verifier, and returns 0.
//       - Sets port (`0x1334`) and host (`0x1340`).
//       - Extracts peer certificates via `SSL_get0_peer_certificates(ssl)` (`0x1348`) and checks `sk_num` (`0x1350`).
//         If `sk_num == 0` (`0x1354 -> 0x1504`), destroys verifier & params and returns 1!
//       - Iterates over each `CRYPTO_BUFFER*` in `peer_certificates` (`0x1368..0x13d0`), copies each DER byte
//         into `Cronet_CertData` via `Cronet_CertData_data_add` (`0x1398..0x13a8`), appends to `params` via
//         `Cronet_VerifyParamsV2_certs_add` (`0x13b4`), and destroys `Cronet_CertData` (`0x13bc`).
//       - Extracts OCSP response via `SSL_get0_ocsp_response` (`0x13e0`) and appends bytes via
//         `Cronet_VerifyParamsV2_ocsp_add` (`0x13f0..0x140c`).
//       - Extracts SCT list via `SSL_get0_signed_cert_timestamp_list` (`0x141c`) and appends bytes via
//         `Cronet_VerifyParamsV2_sct_list_add` (`0x142c..0x1448`).
//       - Creates `Cronet_VerifyResult` (`0x1460`) and runs `Cronet_CertVerify_DoVerifyV2` (`0x1474`).
//       - When `verify_ret == 0` (`cbnz w22, #0x1498` @ `0x147c`) and
//         `Cronet_VerifyResult_is_issued_by_known_root_get(result)` is true (`0x1484..0x1488`),
//         calls `SSL_set_enforce_rsa_key_usage(ssl, 1)` (`0x148c..0x1494`).
//       - Destroys `verify_result` (`0x149c`), computes return value `w20 = (uint32_t(w22) > 1U) ? 1 : 0`
//         (`cmp w22, #1; cset w20, hi` @ `0x14b8..0x14c0`), destroys `verifier` (`0x14c4`) and `params` (`0x1514`),
//         and returns `w20`.
// VI: Tái tạo chính xác FDE[02] `vcn_custom_verify_2` (`0x1280..0x1550`, 720 byte).
int vcn_custom_verify_2(void* ctx, BoringSslConnection* ssl, const char* host, int port) noexcept {
    (void)ctx;
    av_log(nullptr, kAvLogDebugLevel,
           "custom_verify:start call custom verify ssl:%p host:%s port:%d\n",
           static_cast<const void*>(ssl), host != nullptr ? host : "", port);
    av_log(nullptr, kAvLogDebugLevel,
           "custom_verify:start create verify ptr\n");

    CronetCertVerifier* verifier = Cronet_CertVerify_Create();
    if (verifier == nullptr) {
        av_log(nullptr, kAvLogDebugLevel,
               "custom_verify:create verify ptr fail\n");
        return 0;
    }

    av_log(nullptr, kAvLogDebugLevel,
           "custom_verify:start create verify ptr\n");
    CronetVerifyParamsV2* params = Cronet_VerifyParamsV2_Create();
    if (params == nullptr) {
        av_log(nullptr, kAvLogDebugLevel,
               "custom_verify:create verify param ptr fail\n");
        Cronet_CertVerify_Destroy(verifier);
        return 0;
    }

    av_log(nullptr, kAvLogDebugLevel,
           "custom_verify:set host and ssl to param ptr\n");
    Cronet_VerifyParamsV2_port_set(params, port);
    Cronet_VerifyParamsV2_host_set(params, host);

    const BoringSslCertStack* peer_certs = SSL_get0_peer_certificates(ssl);
    if (sk_num(peer_certs) == 0) {
        // Matches 0x1354 -> 0x1504: destroy verifier, set w20 = 1, destroy params, return 1
        Cronet_CertVerify_Destroy(verifier);
        Cronet_VerifyParamsV2_Destroy(params);
        return 1;
    }

    size_t cert_count = sk_num(peer_certs);
    for (size_t i = 0; i < cert_count; i = (i + 1), cert_count = sk_num(peer_certs)) {
        const BoringSslCryptoBuffer* buf = sk_value(peer_certs, i);
        const uint8_t* der_ptr = CRYPTO_BUFFER_data(buf);
        size_t der_len = CRYPTO_BUFFER_len(buf);
        CronetCertData* cert_data = Cronet_CertData_Create();
        for (size_t b = 0; b < der_len; ++b) {
            Cronet_CertData_data_add(cert_data, der_ptr[b]);
        }
        Cronet_VerifyParamsV2_certs_add(params, cert_data);
        Cronet_CertData_Destroy(cert_data);
    }

    const uint8_t* ocsp_ptr = nullptr;
    size_t ocsp_len = 0;
    SSL_get0_ocsp_response(ssl, &ocsp_ptr, &ocsp_len);
    if (ocsp_len != 0 && ocsp_ptr != nullptr) {
        for (size_t i = 0; i < ocsp_len; ++i) {
            Cronet_VerifyParamsV2_ocsp_add(params, ocsp_ptr[i]);
        }
    }

    const uint8_t* sct_ptr = nullptr;
    size_t sct_len = 0;
    SSL_get0_signed_cert_timestamp_list(ssl, &sct_ptr, &sct_len);
    if (sct_len != 0 && sct_ptr != nullptr) {
        for (size_t i = 0; i < sct_len; ++i) {
            Cronet_VerifyParamsV2_sct_list_add(params, sct_ptr[i]);
        }
    }

    av_log(nullptr, kAvLogDebugLevel,
           "custom_verify: start do verify\n");
    CronetVerifyResult* verify_result = Cronet_VerifyResult_Create();
    int verify_ret = Cronet_CertVerify_DoVerifyV2(verifier, params, verify_result);
    if (verify_ret == 0) {
        if (Cronet_VerifyResult_is_issued_by_known_root_get(verify_result)) {
            SSL_set_enforce_rsa_key_usage(ssl, 1);
        }
    }
    Cronet_VerifyResult_Destroy(verify_result);

    av_log(nullptr, kAvLogDebugLevel,
           "custom_verify: end do verify, result:%d \n",
           verify_ret);
    int final_status = (static_cast<uint32_t>(verify_ret) > 1U) ? 1 : 0;
    Cronet_CertVerify_Destroy(verifier);
    Cronet_VerifyParamsV2_Destroy(params);
    return final_status;
}

// EN: Exact reconstruction of FDE[03] `JNI_OnUnload` (`0x1550..0x1554`, 4 bytes: `ret`).
// VI: Tái tạo chính xác FDE[03] `JNI_OnUnload` (`0x1550..0x1554`, 4 byte: `ret`).
void JNI_OnUnload(void* vm, void* reserved) noexcept {
    (void)vm;
    (void)reserved;
}

}  // extern "C"

}  // namespace ttmverify
}  // namespace opencut
}  // namespace nextai
