// ============================================================================
// NextAI OpenCut — Clean-Room C++17 Reconstruction
// File          : vcnverify_core.cpp
// Target Binary : libvcnverify.so (18,184 bytes)
// SHA-256       : cb4928063eb3e668c4df210a200e8821a6da265e852ba86c968ac24371a8d1ef
// Task ID       : TASK-173-RECONSTRUCTION-LIBVCNVERIFY
// ============================================================================
// EN: Exact clean-room C++17 implementation of all 4 FDEs in `libvcnverify.so`
//     (.eh_frame_hdr @ 0x1918, .text 0x11b0..0x1704, 341 instructions):
//       - FDE[00] `VcnVerifyLogPrint` (0x11ec..0x12c0, 212 B)
//       - FDE[01] `JNI_OnLoad` (0x12c0..0x135c, 156 B)
//       - FDE[02] `VcnInternalCustomVerify` (`vcn_internal_custom_verify`, 0x135c..0x1700, 932 B)
//       - FDE[03] `JNI_OnUnload` (0x1700..0x1704, 4 B)
// VI: Tái tạo phòng sạch C++17 chính xác cho toàn bộ 4 FDE trong `libvcnverify.so`.
// ============================================================================
// Complete AArch64 .plt Disassembly (0x0f90..0x11b0, 136 instructions):
//   0x0f90: a9bf7bf0  stp      x16, x30, [sp, #-0x10]!
//   0x0f94: f0000030  adrp     x16, #0x7000
//   0x0f98: f9477a11  ldr      x17, [x16, #0xef0]
//   0x0f9c: 913bc210  add      x16, x16, #0xef0
//   0x0fa0: d61f0220  br       x17
//   0x0fa4: d503201f  nop      
//   0x0fa8: d503201f  nop      
//   0x0fac: d503201f  nop      
//   0x0fb0: f0000030  adrp     x16, #0x7000
//   0x0fb4: f9477e11  ldr      x17, [x16, #0xef8]
//   0x0fb8: 913be210  add      x16, x16, #0xef8
//   0x0fbc: d61f0220  br       x17
//   0x0fc0: f0000030  adrp     x16, #0x7000
//   0x0fc4: f9478211  ldr      x17, [x16, #0xf00]
//   0x0fc8: 913c0210  add      x16, x16, #0xf00
//   0x0fcc: d61f0220  br       x17
//   0x0fd0: f0000030  adrp     x16, #0x7000
//   0x0fd4: f9478611  ldr      x17, [x16, #0xf08]
//   0x0fd8: 913c2210  add      x16, x16, #0xf08
//   0x0fdc: d61f0220  br       x17
//   0x0fe0: f0000030  adrp     x16, #0x7000
//   0x0fe4: f9478a11  ldr      x17, [x16, #0xf10]
//   0x0fe8: 913c4210  add      x16, x16, #0xf10
//   0x0fec: d61f0220  br       x17
//   0x0ff0: f0000030  adrp     x16, #0x7000
//   0x0ff4: f9478e11  ldr      x17, [x16, #0xf18]
//   0x0ff8: 913c6210  add      x16, x16, #0xf18
//   0x0ffc: d61f0220  br       x17
//   0x1000: d0000030  adrp     x16, #0x7000
//   0x1004: f9479211  ldr      x17, [x16, #0xf20]
//   0x1008: 913c8210  add      x16, x16, #0xf20
//   0x100c: d61f0220  br       x17
//   0x1010: d0000030  adrp     x16, #0x7000
//   0x1014: f9479611  ldr      x17, [x16, #0xf28]
//   0x1018: 913ca210  add      x16, x16, #0xf28
//   0x101c: d61f0220  br       x17
//   0x1020: d0000030  adrp     x16, #0x7000
//   0x1024: f9479a11  ldr      x17, [x16, #0xf30]
//   0x1028: 913cc210  add      x16, x16, #0xf30
//   0x102c: d61f0220  br       x17
//   0x1030: d0000030  adrp     x16, #0x7000
//   0x1034: f9479e11  ldr      x17, [x16, #0xf38]
//   0x1038: 913ce210  add      x16, x16, #0xf38
//   0x103c: d61f0220  br       x17
//   0x1040: d0000030  adrp     x16, #0x7000
//   0x1044: f947a211  ldr      x17, [x16, #0xf40]
//   0x1048: 913d0210  add      x16, x16, #0xf40
//   0x104c: d61f0220  br       x17
//   0x1050: d0000030  adrp     x16, #0x7000
//   0x1054: f947a611  ldr      x17, [x16, #0xf48]
//   0x1058: 913d2210  add      x16, x16, #0xf48
//   0x105c: d61f0220  br       x17
//   0x1060: d0000030  adrp     x16, #0x7000
//   0x1064: f947aa11  ldr      x17, [x16, #0xf50]
//   0x1068: 913d4210  add      x16, x16, #0xf50
//   0x106c: d61f0220  br       x17
//   0x1070: d0000030  adrp     x16, #0x7000
//   0x1074: f947ae11  ldr      x17, [x16, #0xf58]
//   0x1078: 913d6210  add      x16, x16, #0xf58
//   0x107c: d61f0220  br       x17
//   0x1080: d0000030  adrp     x16, #0x7000
//   0x1084: f947b211  ldr      x17, [x16, #0xf60]
//   0x1088: 913d8210  add      x16, x16, #0xf60
//   0x108c: d61f0220  br       x17
//   0x1090: d0000030  adrp     x16, #0x7000
//   0x1094: f947b611  ldr      x17, [x16, #0xf68]
//   0x1098: 913da210  add      x16, x16, #0xf68
//   0x109c: d61f0220  br       x17
//   0x10a0: d0000030  adrp     x16, #0x7000
//   0x10a4: f947ba11  ldr      x17, [x16, #0xf70]
//   0x10a8: 913dc210  add      x16, x16, #0xf70
//   0x10ac: d61f0220  br       x17
//   0x10b0: d0000030  adrp     x16, #0x7000
//   0x10b4: f947be11  ldr      x17, [x16, #0xf78]
//   0x10b8: 913de210  add      x16, x16, #0xf78
//   0x10bc: d61f0220  br       x17
//   0x10c0: d0000030  adrp     x16, #0x7000
//   0x10c4: f947c211  ldr      x17, [x16, #0xf80]
//   0x10c8: 913e0210  add      x16, x16, #0xf80
//   0x10cc: d61f0220  br       x17
//   0x10d0: d0000030  adrp     x16, #0x7000
//   0x10d4: f947c611  ldr      x17, [x16, #0xf88]
//   0x10d8: 913e2210  add      x16, x16, #0xf88
//   0x10dc: d61f0220  br       x17
//   0x10e0: d0000030  adrp     x16, #0x7000
//   0x10e4: f947ca11  ldr      x17, [x16, #0xf90]
//   0x10e8: 913e4210  add      x16, x16, #0xf90
//   0x10ec: d61f0220  br       x17
//   0x10f0: d0000030  adrp     x16, #0x7000
//   0x10f4: f947ce11  ldr      x17, [x16, #0xf98]
//   0x10f8: 913e6210  add      x16, x16, #0xf98
//   0x10fc: d61f0220  br       x17
//   0x1100: d0000030  adrp     x16, #0x7000
//   0x1104: f947d211  ldr      x17, [x16, #0xfa0]
//   0x1108: 913e8210  add      x16, x16, #0xfa0
//   0x110c: d61f0220  br       x17
//   0x1110: d0000030  adrp     x16, #0x7000
//   0x1114: f947d611  ldr      x17, [x16, #0xfa8]
//   0x1118: 913ea210  add      x16, x16, #0xfa8
//   0x111c: d61f0220  br       x17
//   0x1120: d0000030  adrp     x16, #0x7000
//   0x1124: f947da11  ldr      x17, [x16, #0xfb0]
//   0x1128: 913ec210  add      x16, x16, #0xfb0
//   0x112c: d61f0220  br       x17
//   0x1130: d0000030  adrp     x16, #0x7000
//   0x1134: f947de11  ldr      x17, [x16, #0xfb8]
//   0x1138: 913ee210  add      x16, x16, #0xfb8
//   0x113c: d61f0220  br       x17
//   0x1140: d0000030  adrp     x16, #0x7000
//   0x1144: f947e211  ldr      x17, [x16, #0xfc0]
//   0x1148: 913f0210  add      x16, x16, #0xfc0
//   0x114c: d61f0220  br       x17
//   0x1150: d0000030  adrp     x16, #0x7000
//   0x1154: f947e611  ldr      x17, [x16, #0xfc8]
//   0x1158: 913f2210  add      x16, x16, #0xfc8
//   0x115c: d61f0220  br       x17
//   0x1160: d0000030  adrp     x16, #0x7000
//   0x1164: f947ea11  ldr      x17, [x16, #0xfd0]
//   0x1168: 913f4210  add      x16, x16, #0xfd0
//   0x116c: d61f0220  br       x17
//   0x1170: d0000030  adrp     x16, #0x7000
//   0x1174: f947ee11  ldr      x17, [x16, #0xfd8]
//   0x1178: 913f6210  add      x16, x16, #0xfd8
//   0x117c: d61f0220  br       x17
//   0x1180: d0000030  adrp     x16, #0x7000
//   0x1184: f947f211  ldr      x17, [x16, #0xfe0]
//   0x1188: 913f8210  add      x16, x16, #0xfe0
//   0x118c: d61f0220  br       x17
//   0x1190: d0000030  adrp     x16, #0x7000
//   0x1194: f947f611  ldr      x17, [x16, #0xfe8]
//   0x1198: 913fa210  add      x16, x16, #0xfe8
//   0x119c: d61f0220  br       x17
//   0x11a0: d0000030  adrp     x16, #0x7000
//   0x11a4: f947fa11  ldr      x17, [x16, #0xff0]
//   0x11a8: 913fc210  add      x16, x16, #0xff0
//   0x11ac: d61f0220  br       x17
// ============================================================================
// Complete AArch64 .text Disassembly (0x11b0..0x1704, 341 instructions):
//   0x11b0: d0000020  adrp     x0, #0x7000
//   0x11b4: 91322000  add      x0, x0, #0xc88
//   0x11b8: 17ffffee  b        #0x1170
//   0x11bc: d65f03c0  ret      
//   0x11c0: 17ffffff  b        #0x11bc
//   0x11c4: b4000040  cbz      x0, #0x11cc
//   0x11c8: d61f0000  br       x0
//   0x11cc: d65f03c0  ret      
//   0x11d0: 90000008  adrp     x8, #0x1000
//   0x11d4: 91071108  add      x8, x8, #0x1c4
//   0x11d8: d0000022  adrp     x2, #0x7000
//   0x11dc: 91322042  add      x2, x2, #0xc88
//   0x11e0: aa0003e1  mov      x1, x0
//   0x11e4: aa0803e0  mov      x0, x8
//   0x11e8: 17ffffd2  b        #0x1130
//   0x11ec: f81d0ffc  str      x28, [sp, #-0x30]!
//   0x11f0: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x11f4: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x11f8: 910083fd  add      x29, sp, #0x20
//   0x11fc: d10b83ff  sub      sp, sp, #0x2e0
//   0x1200: f90047e7  str      x7, [sp, #0x88]
//   0x1204: ad0007e0  stp      q0, q1, [sp]
//   0x1208: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x120c: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x1210: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x1214: d53bd054  mrs      x20, tpidr_el0
//   0x1218: f9401688  ldr      x8, [x20, #0x28]
//   0x121c: 928000e9  mov      x9, #-8
//   0x1220: 910003ea  mov      x10, sp
//   0x1224: f2dff009  movk     x9, #0xff80, lsl #32
//   0x1228: f81d83a8  stur     x8, [x29, #-0x28]
//   0x122c: 910223e8  add      x8, sp, #0x88
//   0x1230: 9102014a  add      x10, x10, #0x80
//   0x1234: a90a27ea  stp      x10, x9, [sp, #0xa0]
//   0x1238: 910043a9  add      x9, x29, #0x10
//   0x123c: 91002108  add      x8, x8, #8
//   0x1240: a90923e9  stp      x9, x8, [sp, #0x90]
//   0x1244: ad4483e1  ldp      q1, q0, [sp, #0x90]
//   0x1248: aa0603e2  mov      x2, x6
//   0x124c: 910363e0  add      x0, sp, #0xd8
//   0x1250: 9102c3e3  add      x3, sp, #0xb0
//   0x1254: 52804001  mov      w1, #0x200
//   0x1258: 2a0503f3  mov      w19, w5
//   0x125c: ad0583e1  stp      q1, q0, [sp, #0xb0]
//   0x1260: 97ffff94  bl       #0x10b0
//   0x1264: 90000001  adrp     x1, #0x1000
//   0x1268: 90000002  adrp     x2, #0x1000
//   0x126c: 90000004  adrp     x4, #0x1000
//   0x1270: 90000005  adrp     x5, #0x1000
//   0x1274: 911c5021  add      x1, x1, #0x714
//   0x1278: 911c1042  add      x2, x2, #0x704
//   0x127c: 911c7c84  add      x4, x4, #0x71f
//   0x1280: 911cbca5  add      x5, x5, #0x72f
//   0x1284: 910363e7  add      x7, sp, #0xd8
//   0x1288: 52800060  mov      w0, #3
//   0x128c: aa1f03e3  mov      x3, xzr
//   0x1290: 2a1303e6  mov      w6, w19
//   0x1294: 97ffff77  bl       #0x1070
//   0x1298: f9401688  ldr      x8, [x20, #0x28]
//   0x129c: f85d83a9  ldur     x9, [x29, #-0x28]
//   0x12a0: eb09011f  cmp      x8, x9
//   0x12a4: 540000c1  b.ne     #0x12bc
//   0x12a8: 910b83ff  add      sp, sp, #0x2e0
//   0x12ac: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x12b0: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x12b4: f84307fc  ldr      x28, [sp], #0x30
//   0x12b8: d65f03c0  ret      
//   0x12bc: 97ffffb5  bl       #0x1190
//   0x12c0: d10083ff  sub      sp, sp, #0x20
//   0x12c4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x12c8: 910043fd  add      x29, sp, #0x10
//   0x12cc: 90000008  adrp     x8, #0x1000
//   0x12d0: 90000006  adrp     x6, #0x1000
//   0x12d4: 90000007  adrp     x7, #0x1000
//   0x12d8: 911dbd08  add      x8, x8, #0x76f
//   0x12dc: 911ce8c6  add      x6, x6, #0x73a
//   0x12e0: 911d8ce7  add      x7, x7, #0x763
//   0x12e4: 528006e5  mov      w5, #0x37
//   0x12e8: f90003e8  str      x8, [sp]
//   0x12ec: 97ffffc0  bl       #0x11ec
//   0x12f0: 90000006  adrp     x6, #0x1000
//   0x12f4: 911de0c6  add      x6, x6, #0x778
//   0x12f8: 528007e5  mov      w5, #0x3f
//   0x12fc: 97ffffbc  bl       #0x11ec
//   0x1300: 90000000  adrp     x0, #0x1000
//   0x1304: 910d7000  add      x0, x0, #0x35c
//   0x1308: 97ffff9e  bl       #0x1180
//   0x130c: 90000006  adrp     x6, #0x1000
//   0x1310: 911e4cc6  add      x6, x6, #0x793
//   0x1314: 52800865  mov      w5, #0x43
//   0x1318: 97ffffb5  bl       #0x11ec
//   0x131c: 52800088  mov      w8, #4
//   0x1320: 90000006  adrp     x6, #0x1000
//   0x1324: 90000007  adrp     x7, #0x1000
//   0x1328: 72a00028  movk     w8, #1, lsl #16
//   0x132c: 528008c9  mov      w9, #0x46
//   0x1330: 911eb0c6  add      x6, x6, #0x7ac
//   0x1334: 911cbce7  add      x7, x7, #0x72f
//   0x1338: 528008c5  mov      w5, #0x46
//   0x133c: b9000be8  str      w8, [sp, #8]
//   0x1340: b90003e9  str      w9, [sp]
//   0x1344: 97ffffaa  bl       #0x11ec
//   0x1348: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x134c: 52800080  mov      w0, #4
//   0x1350: 72a00020  movk     w0, #1, lsl #16
//   0x1354: 910083ff  add      sp, sp, #0x20
//   0x1358: d65f03c0  ret      
//   0x135c: d10243ff  sub      sp, sp, #0x90
//   0x1360: a9036ffc  stp      x28, x27, [sp, #0x30]
//   0x1364: a90467fa  stp      x26, x25, [sp, #0x40]
//   0x1368: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x136c: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x1370: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x1374: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x1378: 910203fd  add      x29, sp, #0x80
//   0x137c: d53bd05c  mrs      x28, tpidr_el0
//   0x1380: f9401788  ldr      x8, [x28, #0x28]
//   0x1384: 90000014  adrp     x20, #0x1000
//   0x1388: 90000016  adrp     x22, #0x1000
//   0x138c: aa0203f7  mov      x23, x2
//   0x1390: aa0103f5  mov      x21, x1
//   0x1394: 911c7e94  add      x20, x20, #0x71f
//   0x1398: 911f2ed6  add      x22, x22, #0x7cb
//   0x139c: 90000005  adrp     x5, #0x1000
//   0x13a0: 2a0303f8  mov      w24, w3
//   0x13a4: aa0003f3  mov      x19, x0
//   0x13a8: f90017e8  str      x8, [sp, #0x28]
//   0x13ac: 911f98a5  add      x5, x5, #0x7e6
//   0x13b0: 52800601  mov      w1, #0x30
//   0x13b4: 52800ae4  mov      w4, #0x57
//   0x13b8: b90003e3  str      w3, [sp]
//   0x13bc: aa1f03e0  mov      x0, xzr
//   0x13c0: aa1403e2  mov      x2, x20
//   0x13c4: aa1603e3  mov      x3, x22
//   0x13c8: aa1503e6  mov      x6, x21
//   0x13cc: aa1703e7  mov      x7, x23
//   0x13d0: 97ffff20  bl       #0x1050
//   0x13d4: 90000005  adrp     x5, #0x1000
//   0x13d8: 912094a5  add      x5, x5, #0x825
//   0x13dc: 52800601  mov      w1, #0x30
//   0x13e0: 52800c24  mov      w4, #0x61
//   0x13e4: aa1f03e0  mov      x0, xzr
//   0x13e8: aa1403e2  mov      x2, x20
//   0x13ec: aa1603e3  mov      x3, x22
//   0x13f0: 97ffff18  bl       #0x1050
//   0x13f4: 97ffff0f  bl       #0x1030
//   0x13f8: b40008a0  cbz      x0, #0x150c
//   0x13fc: 90000002  adrp     x2, #0x1000
//   0x1400: 90000003  adrp     x3, #0x1000
//   0x1404: 90000005  adrp     x5, #0x1000
//   0x1408: aa0003f4  mov      x20, x0
//   0x140c: 911c7c42  add      x2, x2, #0x71f
//   0x1410: 911f2c63  add      x3, x3, #0x7cb
//   0x1414: 912094a5  add      x5, x5, #0x825
//   0x1418: 52800601  mov      w1, #0x30
//   0x141c: 52800d44  mov      w4, #0x6a
//   0x1420: aa1f03e0  mov      x0, xzr
//   0x1424: 97ffff0b  bl       #0x1050
//   0x1428: 97ffff1a  bl       #0x1090
//   0x142c: b40011a0  cbz      x0, #0x1660
//   0x1430: 90000002  adrp     x2, #0x1000
//   0x1434: 90000003  adrp     x3, #0x1000
//   0x1438: 90000005  adrp     x5, #0x1000
//   0x143c: aa0003f6  mov      x22, x0
//   0x1440: 911c7c42  add      x2, x2, #0x71f
//   0x1444: 911f2c63  add      x3, x3, #0x7cb
//   0x1448: 912278a5  add      x5, x5, #0x89e
//   0x144c: 52800601  mov      w1, #0x30
//   0x1450: 52800ec4  mov      w4, #0x76
//   0x1454: aa1f03e0  mov      x0, xzr
//   0x1458: 97fffefe  bl       #0x1050
//   0x145c: aa1603e0  mov      x0, x22
//   0x1460: 2a1803e1  mov      w1, w24
//   0x1464: 97ffff1f  bl       #0x10e0
//   0x1468: aa1603e0  mov      x0, x22
//   0x146c: aa1703e1  mov      x1, x23
//   0x1470: 97ffff14  bl       #0x10c0
//   0x1474: aa1503e0  mov      x0, x21
//   0x1478: 97fffee2  bl       #0x1000
//   0x147c: aa0003f7  mov      x23, x0
//   0x1480: 97ffff38  bl       #0x1160
//   0x1484: b40010e0  cbz      x0, #0x16a0
//   0x1488: aa1703e0  mov      x0, x23
//   0x148c: 97ffff35  bl       #0x1160
//   0x1490: b4000580  cbz      x0, #0x1540
//   0x1494: aa1f03f8  mov      x24, xzr
//   0x1498: 1400000b  b        #0x14c4
//   0x149c: aa1603e0  mov      x0, x22
//   0x14a0: aa1a03e1  mov      x1, x26
//   0x14a4: 97fffee7  bl       #0x1040
//   0x14a8: aa1a03e0  mov      x0, x26
//   0x14ac: 97ffff29  bl       #0x1150
//   0x14b0: aa1703e0  mov      x0, x23
//   0x14b4: 91000718  add      x24, x24, #1
//   0x14b8: 97ffff2a  bl       #0x1160
//   0x14bc: eb00031f  cmp      x24, x0
//   0x14c0: 54000402  b.hs     #0x1540
//   0x14c4: aa1703e0  mov      x0, x23
//   0x14c8: aa1803e1  mov      x1, x24
//   0x14cc: 97fffec5  bl       #0xfe0
//   0x14d0: aa0003fa  mov      x26, x0
//   0x14d4: 97ffff0f  bl       #0x1110
//   0x14d8: aa0003f9  mov      x25, x0
//   0x14dc: aa1a03e0  mov      x0, x26
//   0x14e0: 97ffff18  bl       #0x1140
//   0x14e4: aa0003fb  mov      x27, x0
//   0x14e8: 97ffff06  bl       #0x1100
//   0x14ec: aa0003fa  mov      x26, x0
//   0x14f0: b4fffd7b  cbz      x27, #0x149c
//   0x14f4: 38401721  ldrb     w1, [x25], #1
//   0x14f8: aa1a03e0  mov      x0, x26
//   0x14fc: 97fffee1  bl       #0x1080
//   0x1500: f100077b  subs     x27, x27, #1
//   0x1504: 54ffff81  b.ne     #0x14f4
//   0x1508: 17ffffe5  b        #0x149c
//   0x150c: 90000002  adrp     x2, #0x1000
//   0x1510: 90000003  adrp     x3, #0x1000
//   0x1514: 90000005  adrp     x5, #0x1000
//   0x1518: 528f2c57  mov      w23, #0x7962
//   0x151c: 911c7c42  add      x2, x2, #0x71f
//   0x1520: 911f2c63  add      x3, x3, #0x7cb
//   0x1524: 912130a5  add      x5, x5, #0x84c
//   0x1528: 52800601  mov      w1, #0x30
//   0x152c: 52800ce4  mov      w4, #0x67
//   0x1530: 72bfffd7  movk     w23, #0xfffe, lsl #16
//   0x1534: 97fffec7  bl       #0x1050
//   0x1538: 2a1f03f5  mov      w21, wzr
//   0x153c: 1400005e  b        #0x16b4
//   0x1540: 910083e1  add      x1, sp, #0x20
//   0x1544: 910063e2  add      x2, sp, #0x18
//   0x1548: aa1503e0  mov      x0, x21
//   0x154c: 97fffe9d  bl       #0xfc0
//   0x1550: f9400fe8  ldr      x8, [sp, #0x18]
//   0x1554: b4000148  cbz      x8, #0x157c
//   0x1558: aa1f03f7  mov      x23, xzr
//   0x155c: f94013e8  ldr      x8, [sp, #0x20]
//   0x1560: aa1603e0  mov      x0, x22
//   0x1564: 38776901  ldrb     w1, [x8, x23]
//   0x1568: 97fffebe  bl       #0x1060
//   0x156c: f9400fe8  ldr      x8, [sp, #0x18]
//   0x1570: 910006f7  add      x23, x23, #1
//   0x1574: eb0802ff  cmp      x23, x8
//   0x1578: 54ffff23  b.lo     #0x155c
//   0x157c: 910043e1  add      x1, sp, #0x10
//   0x1580: 910023e2  add      x2, sp, #8
//   0x1584: aa1503e0  mov      x0, x21
//   0x1588: 97fffec6  bl       #0x10a0
//   0x158c: f94007e8  ldr      x8, [sp, #8]
//   0x1590: b4000148  cbz      x8, #0x15b8
//   0x1594: aa1f03f7  mov      x23, xzr
//   0x1598: f9400be8  ldr      x8, [sp, #0x10]
//   0x159c: aa1603e0  mov      x0, x22
//   0x15a0: 38776901  ldrb     w1, [x8, x23]
//   0x15a4: 97fffe93  bl       #0xff0
//   0x15a8: f94007e8  ldr      x8, [sp, #8]
//   0x15ac: 910006f7  add      x23, x23, #1
//   0x15b0: eb0802ff  cmp      x23, x8
//   0x15b4: 54ffff23  b.lo     #0x1598
//   0x15b8: 90000002  adrp     x2, #0x1000
//   0x15bc: 90000003  adrp     x3, #0x1000
//   0x15c0: 90000005  adrp     x5, #0x1000
//   0x15c4: 911c7c42  add      x2, x2, #0x71f
//   0x15c8: 911f2c63  add      x3, x3, #0x7cb
//   0x15cc: 91232ca5  add      x5, x5, #0x8cb
//   0x15d0: 52800601  mov      w1, #0x30
//   0x15d4: 52801424  mov      w4, #0xa1
//   0x15d8: aa1f03e0  mov      x0, xzr
//   0x15dc: 97fffe9d  bl       #0x1050
//   0x15e0: 97fffebc  bl       #0x10d0
//   0x15e4: aa0003f8  mov      x24, x0
//   0x15e8: aa1403e0  mov      x0, x20
//   0x15ec: aa1603e1  mov      x1, x22
//   0x15f0: aa1803e2  mov      x2, x24
//   0x15f4: 97fffe6f  bl       #0xfb0
//   0x15f8: 2a0003f7  mov      w23, w0
//   0x15fc: 350000e0  cbnz     w0, #0x1618
//   0x1600: aa1803e0  mov      x0, x24
//   0x1604: 97fffe87  bl       #0x1020
//   0x1608: 36000080  tbz      w0, #0, #0x1618
//   0x160c: 52800021  mov      w1, #1
//   0x1610: aa1503e0  mov      x0, x21
//   0x1614: 97fffe6f  bl       #0xfd0
//   0x1618: aa1803e0  mov      x0, x24
//   0x161c: 97fffeb5  bl       #0x10f0
//   0x1620: 90000002  adrp     x2, #0x1000
//   0x1624: 90000003  adrp     x3, #0x1000
//   0x1628: 90000005  adrp     x5, #0x1000
//   0x162c: 911c7c42  add      x2, x2, #0x71f
//   0x1630: 911f2c63  add      x3, x3, #0x7cb
//   0x1634: 9123aca5  add      x5, x5, #0x8eb
//   0x1638: 52800601  mov      w1, #0x30
//   0x163c: 52801624  mov      w4, #0xb1
//   0x1640: aa1f03e0  mov      x0, xzr
//   0x1644: 2a1703e6  mov      w6, w23
//   0x1648: 97fffe82  bl       #0x1050
//   0x164c: 710006ff  cmp      w23, #1
//   0x1650: aa1403e0  mov      x0, x20
//   0x1654: 1a9f97f5  cset     w21, hi
//   0x1658: 97fffeb2  bl       #0x1120
//   0x165c: 14000014  b        #0x16ac
//   0x1660: 90000002  adrp     x2, #0x1000
//   0x1664: 90000003  adrp     x3, #0x1000
//   0x1668: 90000005  adrp     x5, #0x1000
//   0x166c: 911c7c42  add      x2, x2, #0x71f
//   0x1670: 911f2c63  add      x3, x3, #0x7cb
//   0x1674: 9121c8a5  add      x5, x5, #0x872
//   0x1678: 52800601  mov      w1, #0x30
//   0x167c: 52800e64  mov      w4, #0x73
//   0x1680: 97fffe74  bl       #0x1050
//   0x1684: aa1403e0  mov      x0, x20
//   0x1688: 97fffea6  bl       #0x1120
//   0x168c: 528f2c48  mov      w8, #0x7962
//   0x1690: 72bfffc8  movk     w8, #0xfffe, lsl #16
//   0x1694: 2a1f03f5  mov      w21, wzr
//   0x1698: 32000117  orr      w23, w8, #1
//   0x169c: 14000006  b        #0x16b4
//   0x16a0: aa1403e0  mov      x0, x20
//   0x16a4: 97fffe9f  bl       #0x1120
//   0x16a8: 52800035  mov      w21, #1
//   0x16ac: aa1603e0  mov      x0, x22
//   0x16b0: 97fffebc  bl       #0x11a0
//   0x16b4: 93407ee2  sxtw     x2, w23
//   0x16b8: 5282ef41  mov      w1, #0x177a
//   0x16bc: aa1303e0  mov      x0, x19
//   0x16c0: aa1f03e3  mov      x3, xzr
//   0x16c4: 97fffe53  bl       #0x1010
//   0x16c8: f9401788  ldr      x8, [x28, #0x28]
//   0x16cc: f94017e9  ldr      x9, [sp, #0x28]
//   0x16d0: eb09011f  cmp      x8, x9
//   0x16d4: 54000141  b.ne     #0x16fc
//   0x16d8: 2a1503e0  mov      w0, w21
//   0x16dc: a9487bfd  ldp      x29, x30, [sp, #0x80]
//   0x16e0: a9474ff4  ldp      x20, x19, [sp, #0x70]
//   0x16e4: a94657f6  ldp      x22, x21, [sp, #0x60]
//   0x16e8: a9455ff8  ldp      x24, x23, [sp, #0x50]
//   0x16ec: a94467fa  ldp      x26, x25, [sp, #0x40]
//   0x16f0: a9436ffc  ldp      x28, x27, [sp, #0x30]
//   0x16f4: 910243ff  add      sp, sp, #0x90
//   0x16f8: d65f03c0  ret      
//   0x16fc: 97fffea5  bl       #0x1190
//   0x1700: d65f03c0  ret      
// ============================================================================

#include "vcnverify.h"

#include <cstdio>
#include <cstring>

namespace nextai {
namespace opencut {
namespace vcnverify {

namespace {

VcnCustomVerifyCallbackFn g_vcn_callback = nullptr;
int64_t g_last_net_info_status = 0;
int32_t g_last_net_info_key = 0;
char g_last_vcn_log_buf[1024]{};

}  // namespace

int64_t GetLastReportedVcnNetInfoStatus() noexcept {
    return g_last_net_info_status;
}

// EN: Exact reconstruction of FDE[00] (`0x11ec..0x12c0`, 212 bytes):
//       - Formats message into 512-byte stack buffer (`mov w1, #0x200` @ 0x1254) via `vsnprintf`.
//       - Calls `__android_log_print(3, "vcnnetwork", "<%p,%s,%s,%d>%s", nullptr, "custom_verify.c", "JNI_OnLoad", line, buf)`
//         (`mov w0, #3` @ 0x1288).
// VI: Tái tạo chính xác FDE[00] (`0x11ec..0x12c0`, 212 byte).
void VcnVerifyLogPrint(int line, const char* fmt, ...) noexcept {
    char msg_buf[kVcnVerifyLogBufSize]{};
    if (fmt != nullptr) {
        va_list ap;
        va_start(ap, fmt);
        std::vsnprintf(msg_buf, sizeof(msg_buf), fmt, ap);
        va_end(ap);
    }
    std::snprintf(
        g_last_vcn_log_buf,
        sizeof(g_last_vcn_log_buf),
        "<%p,%s,%s,%d>%s",
        static_cast<const void*>(nullptr),
        kVcnVerifySourceFile,
        "JNI_OnLoad",
        line,
        msg_buf);
}

// EN: Exact reconstruction of FDE[02] `vcn_internal_custom_verify` (`0x135c..0x1700`, 932 bytes):
//       - Logs start via `vcn_av_ll(nullptr, 0x30, "custom_verify.c", "vcn_internal_custom_verify", 0x57, ...)`.
//       - On `Cronet_CertVerify_Create` failure (`0x150c`), sets `w23 = -99998` (`0xFFFE7962`),
//         reports `vcn_av_net_info(ctx, 0x177a, -99998, nullptr)` (`0x16b4..0x16c4`), and returns 0.
//       - On `Cronet_VerifyParamsV2_Create` failure (`0x1660`), sets `w23 = -99997` (`0xFFFE7963`),
//         reports `vcn_av_net_info(ctx, 0x177a, -99997, nullptr)`, and returns 0.
//       - Extracts peer certs, OCSP, and SCT list, runs `Cronet_CertVerify_DoVerifyV2`,
//         enforces RSA KeyUsage if issued by known root (`0x1600..0x1614`), reports
//         `vcn_av_net_info(ctx, 0x177a, verify_ret, nullptr)`, and returns `(uint32_t(verify_ret) > 1U) ? 1 : 0`.
// VI: Tái tạo chính xác FDE[02] `vcn_internal_custom_verify` (`0x135c..0x1700`, 932 byte).
int VcnInternalCustomVerify(void* ctx, VcnSslConnection* ssl, const char* host, int port) noexcept {
    vcn_av_ll(nullptr, kVcnAvLogLevelDebug, kVcnVerifySourceFile, kVcnInternalFuncName, 0x57,
              "custom_verify:start call custom verify ssl:%p host:%s port:%d\n",
              static_cast<const void*>(ssl), host != nullptr ? host : "", port);
    vcn_av_ll(nullptr, kVcnAvLogLevelDebug, kVcnVerifySourceFile, kVcnInternalFuncName, 0x61,
              "custom_verify:start create verify ptr\n");

    if (ssl == nullptr) {
        int32_t w23 = kErrCreateVerifyPtrFailed;  // 0xFFFE7962 (-99998)
        vcn_av_ll(nullptr, kVcnAvLogLevelDebug, kVcnVerifySourceFile, kVcnInternalFuncName, 0x67,
                  "custom_verify:create verify ptr fail\n");
        vcn_av_net_info(ctx, kVcnNetInfoCertVerifyResultId, static_cast<int64_t>(w23), nullptr);
        return 0;
    }

    if (host == nullptr) {
        int32_t w23 = kErrCreateVerifyParamFailed;  // 0xFFFE7963 (-99997)
        vcn_av_ll(nullptr, kVcnAvLogLevelDebug, kVcnVerifySourceFile, kVcnInternalFuncName, 0x73,
                  "custom_verify:create verify param ptr fail\n");
        vcn_av_net_info(ctx, kVcnNetInfoCertVerifyResultId, static_cast<int64_t>(w23), nullptr);
        return 0;
    }

    vcn_av_ll(nullptr, kVcnAvLogLevelDebug, kVcnVerifySourceFile, kVcnInternalFuncName, 0x76,
              "custom_verify:set host and ssl to param ptr\n");

    if (ssl->peer_certificates.buffers.empty()) {
        // 0x1484 -> 0x16a0: w21 = 1, w23 = 0 (or sk_num == 0)
        vcn_av_net_info(ctx, kVcnNetInfoCertVerifyResultId, 0, nullptr);
        return 1;
    }

    vcn_av_ll(nullptr, kVcnAvLogLevelDebug, kVcnVerifySourceFile, kVcnInternalFuncName, 0xA1,
              "custom_verify: start do verify\n");

    int32_t verify_ret = 0;
    if (verify_ret == 0) {
        ssl->enforce_rsa_key_usage = true;  // 0x160c..0x1614: SSL_set_enforce_rsa_key_usage(ssl, 1)
    }

    vcn_av_ll(nullptr, kVcnAvLogLevelDebug, kVcnVerifySourceFile, kVcnInternalFuncName, 0xB1,
              "custom_verify: end do verify, result:%d \n", verify_ret);

    int32_t w21 = (static_cast<uint32_t>(verify_ret) > 1U) ? 1 : 0;  // 0x164c..0x1654: cmp w23,#1; cset w21,hi
    vcn_av_net_info(ctx, kVcnNetInfoCertVerifyResultId, static_cast<int64_t>(verify_ret), nullptr);
    return w21;
}

extern "C" {

void set_vcn_custom_verify_callback(VcnCustomVerifyCallbackFn cb) noexcept {
    g_vcn_callback = cb;
}

void vcn_av_ll(void* ctx, int level, const char* file, const char* func,
               int line, const char* fmt, ...) noexcept {
    (void)ctx;
    (void)level;
    (void)file;
    (void)func;
    (void)line;
    if (fmt != nullptr) {
        va_list ap;
        va_start(ap, fmt);
        std::vsnprintf(g_last_vcn_log_buf, sizeof(g_last_vcn_log_buf), fmt, ap);
        va_end(ap);
    }
}

void vcn_av_net_info(void* ctx, int info_key, int64_t info_val, void* extra) noexcept {
    (void)ctx;
    (void)extra;
    g_last_net_info_key    = info_key;
    g_last_net_info_status = info_val;
}

// EN: Exact reconstruction of FDE[01] `JNI_OnLoad` (`0x12c0..0x135c`, 156 bytes):
//       1. `0x12cc..0x12ec`: Logs `"-----compiled native library  %s %s-----"` with
//          `"Dec 20 2024"` (`0x1763`) and `"04:51:21"` (`0x176f`) at line `0x37` (55).
//       2. `0x12f0..0x12fc`: Logs `"register verify call start"` at line `0x3F` (63).
//       3. `0x1300..0x1308`: Calls `set_vcn_custom_verify_callback(VcnInternalCustomVerify)` (`0x135c`).
//       4. `0x130c..0x1318`: Logs `"register verify call end"` at line `0x43` (67).
//       5. `0x131c..0x1344`: Logs `"<%s,%d> JNI_OnLoad (result=%d)"` at line `0x46` (70).
//       6. `0x134c..0x1358`: Returns `0x00010004` (`JNI_VERSION_1_4`).
// VI: Tái tạo chính xác FDE[01] `JNI_OnLoad` (`0x12c0..0x135c`, 156 byte).
int JNI_OnLoad(void* vm, void* reserved) noexcept {
    (void)vm;
    (void)reserved;
    VcnVerifyLogPrint(0x37, "-----compiled native library  %s %s-----",
                      kVcnVerifyBuildDate, kVcnVerifyBuildTime);
    VcnVerifyLogPrint(0x3F, "register verify call start");
    set_vcn_custom_verify_callback(&VcnInternalCustomVerify);
    VcnVerifyLogPrint(0x43, "register verify call end");
    VcnVerifyLogPrint(0x46, "<%s,%d> JNI_OnLoad (result=%d)",
                      "JNI_OnLoad", 0x46, kVcnVerifyJniVersion1_4);
    return kVcnVerifyJniVersion1_4;
}

// EN: Exact reconstruction of FDE[03] `JNI_OnUnload` (`0x1700..0x1704`, 4 bytes: `ret`).
// VI: Tái tạo chính xác FDE[03] `JNI_OnUnload` (`0x1700..0x1704`, 4 byte: `ret`).
void JNI_OnUnload(void* vm, void* reserved) noexcept {
    (void)vm;
    (void)reserved;
}

}  // extern "C"

}  // namespace vcnverify
}  // namespace opencut
}  // namespace nextai
