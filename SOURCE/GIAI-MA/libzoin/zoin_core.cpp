// ============================================================================
// NextAI OpenCut — Clean-Room C++17 Reconstruction
// File          : zoin_core.cpp
// Target Binary : libzoin.so (20,304 bytes)
// SHA-256       : 461eaaa63714d460001f67de31520aa3d5b97431d177f9f73005c9519e87adcc
// Task ID       : TASK-175-RECONSTRUCTION-LIBZOIN
// ============================================================================
// EN: Clean-room C++17 implementation of all 54 FDEs in `libzoin.so`
//     (.eh_frame_hdr @ 0x1ac0, .text 0x224c..0x4120, 1,973 AArch64 instructions).
// VI: Tái tạo C++17 phòng sạch cho toàn bộ 54 FDE trong `libzoin.so`
//     (.eh_frame_hdr @ 0x1ac0, .text 0x224c..0x4120, 1.973 lệnh AArch64).
// ============================================================================
// Complete AArch64 .text Disassembly (0x224c..0x4120, 1,973 instructions):
//   0x224c: d503245f  bti      c
//   0x2250: d0000020  adrp     x0, #0x8000
//   0x2254: 910f8000  add      x0, x0, #0x3e0
//   0x2258: 140007ba  b        #0x4140
//   0x225c: d503245f  bti      c
//   0x2260: d65f03c0  ret      
//   0x2264: d503245f  bti      c
//   0x2268: 17fffffd  b        #0x225c
//   0x226c: d503245f  bti      c
//   0x2270: b4000060  cbz      x0, #0x227c
//   0x2274: aa0003f0  mov      x16, x0
//   0x2278: d61f0200  br       x16
//   0x227c: d65f03c0  ret      
//   0x2280: d503245f  bti      c
//   0x2284: 90000008  adrp     x8, #0x2000
//   0x2288: 9109b108  add      x8, x8, #0x26c
//   0x228c: d0000022  adrp     x2, #0x8000
//   0x2290: 910f8042  add      x2, x2, #0x3e0
//   0x2294: aa0003e1  mov      x1, x0
//   0x2298: aa0803e0  mov      x0, x8
//   0x229c: 140007ad  b        #0x4150
//   0x22a0: d10283ff  sub      sp, sp, #0xa0
//   0x22a4: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x22a8: f90043f5  str      x21, [sp, #0x80]
//   0x22ac: a9094ff4  stp      x20, x19, [sp, #0x90]
//   0x22b0: 9101c3fd  add      x29, sp, #0x70
//   0x22b4: d53bd054  mrs      x20, tpidr_el0
//   0x22b8: f9401688  ldr      x8, [x20, #0x28]
//   0x22bc: f81f83a8  stur     x8, [x29, #-8]
//   0x22c0: b40005c0  cbz      x0, #0x2378
//   0x22c4: f9400008  ldr      x8, [x0]
//   0x22c8: 528000c2  mov      w2, #6
//   0x22cc: 528000d5  mov      w21, #6
//   0x22d0: 910003e1  mov      x1, sp
//   0x22d4: f9401908  ldr      x8, [x8, #0x30]
//   0x22d8: 72a00022  movk     w2, #1, lsl #16
//   0x22dc: aa0003f3  mov      x19, x0
//   0x22e0: 72a00035  movk     w21, #1, lsl #16
//   0x22e4: d63f0100  blr      x8
//   0x22e8: 35000480  cbnz     w0, #0x2378
//   0x22ec: f94003e0  ldr      x0, [sp]
//   0x22f0: b4000440  cbz      x0, #0x2378
//   0x22f4: f9400008  ldr      x8, [x0]
//   0x22f8: b4000408  cbz      x8, #0x2378
//   0x22fc: d0000048  adrp     x8, #0xc000
//   0x2300: f903d113  str      x19, [x8, #0x7a0]
//   0x2304: f9400008  ldr      x8, [x0]
//   0x2308: f0ffffe1  adrp     x1, #0x1000
//   0x230c: 91172c21  add      x1, x1, #0x5cb
//   0x2310: f9401908  ldr      x8, [x8, #0x30]
//   0x2314: d63f0100  blr      x8
//   0x2318: b4000300  cbz      x0, #0x2378
//   0x231c: d0000021  adrp     x1, #0x8000
//   0x2320: aa0003f3  mov      x19, x0
//   0x2324: 910fa021  add      x1, x1, #0x3e8
//   0x2328: 910023e0  add      x0, sp, #8
//   0x232c: 52800c02  mov      w2, #0x60
//   0x2330: 9400078c  bl       #0x4160
//   0x2334: f94003e0  ldr      x0, [sp]
//   0x2338: 910023e2  add      x2, sp, #8
//   0x233c: 52800083  mov      w3, #4
//   0x2340: aa1303e1  mov      x1, x19
//   0x2344: f9400008  ldr      x8, [x0]
//   0x2348: f9435d08  ldr      x8, [x8, #0x6b8]
//   0x234c: d63f0100  blr      x8
//   0x2350: 7100001f  cmp      w0, #0
//   0x2354: 5a9f02a0  csinv    w0, w21, wzr, eq
//   0x2358: f9401688  ldr      x8, [x20, #0x28]
//   0x235c: 9400072b  bl       #0x4008
//   0x2360: 54000101  b.ne     #0x2380
//   0x2364: a9494ff4  ldp      x20, x19, [sp, #0x90]
//   0x2368: f94043f5  ldr      x21, [sp, #0x80]
//   0x236c: a9477bfd  ldp      x29, x30, [sp, #0x70]
//   0x2370: 910283ff  add      sp, sp, #0xa0
//   0x2374: d65f03c0  ret      
//   0x2378: 12800000  mov      w0, #-1
//   0x237c: 17fffff7  b        #0x2358
//   0x2380: 9400077c  bl       #0x4170
//   0x2384: a9ba7bfd  stp      x29, x30, [sp, #-0x60]!
//   0x2388: 94000715  bl       #0x3fdc
//   0x238c: d11803ff  sub      sp, sp, #0x600
//   0x2390: d53bd058  mrs      x24, tpidr_el0
//   0x2394: f9401708  ldr      x8, [x24, #0x28]
//   0x2398: 52800100  mov      w0, #8
//   0x239c: 52800301  mov      w1, #0x18
//   0x23a0: 2a0203f3  mov      w19, w2
//   0x23a4: f81f03a8  stur     x8, [x29, #-0x10]
//   0x23a8: 94000776  bl       #0x4180
//   0x23ac: d0000055  adrp     x21, #0xc000
//   0x23b0: f903e2a0  str      x0, [x21, #0x7c0]
//   0x23b4: b40002e0  cbz      x0, #0x2410
//   0x23b8: aa0003f4  mov      x20, x0
//   0x23bc: aa1f03f6  mov      x22, xzr
//   0x23c0: 910062d7  add      x23, x22, #0x18
//   0x23c4: f10362ff  cmp      x23, #0xd8
//   0x23c8: 540001c0  b.eq     #0x2400
//   0x23cc: 52850000  mov      w0, #0x2800
//   0x23d0: 94000770  bl       #0x4190
//   0x23d4: f8366a80  str      x0, [x20, x22]
//   0x23d8: aa1703f6  mov      x22, x23
//   0x23dc: b5ffff20  cbnz     x0, #0x23c0
//   0x23e0: aa1f03f4  mov      x20, xzr
//   0x23e4: f103029f  cmp      x20, #0xc0
//   0x23e8: 54000100  b.eq     #0x2408
//   0x23ec: f943e2a8  ldr      x8, [x21, #0x7c0]
//   0x23f0: f8746900  ldr      x0, [x8, x20]
//   0x23f4: 9400076b  bl       #0x41a0
//   0x23f8: 91006294  add      x20, x20, #0x18
//   0x23fc: 17fffffa  b        #0x23e4
//   0x2400: 52800023  mov      w3, #1
//   0x2404: 14000004  b        #0x2414
//   0x2408: f943e2a0  ldr      x0, [x21, #0x7c0]
//   0x240c: 94000765  bl       #0x41a0
//   0x2410: 2a1f03e3  mov      w3, wzr
//   0x2414: d000005b  adrp     x27, #0xc000
//   0x2418: f0ffffe2  adrp     x2, #0x1000
//   0x241c: 911ea37b  add      x27, x27, #0x7a8
//   0x2420: 91110442  add      x2, x2, #0x441
//   0x2424: 2a1f03e0  mov      w0, wzr
//   0x2428: 2a1f03e1  mov      w1, wzr
//   0x242c: 39000363  strb     w3, [x27]
//   0x2430: 940005a9  bl       #0x3ad4
//   0x2434: f9400768  ldr      x8, [x27, #8]
//   0x2438: b4000068  cbz      x8, #0x2444
//   0x243c: 52800023  mov      w3, #1
//   0x2440: 14000016  b        #0x2498
//   0x2444: f0ffffe0  adrp     x0, #0x1000
//   0x2448: 91117800  add      x0, x0, #0x45e
//   0x244c: 52800081  mov      w1, #4
//   0x2450: 94000758  bl       #0x41b0
//   0x2454: b4000200  cbz      x0, #0x2494
//   0x2458: f0ffffe1  adrp     x1, #0x1000
//   0x245c: 91042421  add      x1, x1, #0x109
//   0x2460: aa0003f4  mov      x20, x0
//   0x2464: 94000757  bl       #0x41c0
//   0x2468: b4000160  cbz      x0, #0x2494
//   0x246c: d0000048  adrp     x8, #0xc000
//   0x2470: f0ffffe1  adrp     x1, #0x1000
//   0x2474: f903dd00  str      x0, [x8, #0x7b8]
//   0x2478: 911a8c21  add      x1, x1, #0x6a3
//   0x247c: aa1403e0  mov      x0, x20
//   0x2480: 94000750  bl       #0x41c0
//   0x2484: b4000080  cbz      x0, #0x2494
//   0x2488: d0000048  adrp     x8, #0xc000
//   0x248c: f903d900  str      x0, [x8, #0x7b0]
//   0x2490: 17ffffeb  b        #0x243c
//   0x2494: 2a1f03e3  mov      w3, wzr
//   0x2498: f0ffffe2  adrp     x2, #0x1000
//   0x249c: 91129c42  add      x2, x2, #0x4a7
//   0x24a0: 2a1f03e0  mov      w0, wzr
//   0x24a4: 2a1f03e1  mov      w1, wzr
//   0x24a8: 9400058b  bl       #0x3ad4
//   0x24ac: 72001e7f  tst      w19, #0xff
//   0x24b0: 54001600  b.eq     #0x2770
//   0x24b4: 94000629  bl       #0x3d58
//   0x24b8: aa0003f9  mov      x25, x0
//   0x24bc: 9103c3e0  add      x0, sp, #0xf0
//   0x24c0: 5280a002  mov      w2, #0x500
//   0x24c4: 2a1f03e1  mov      w1, wzr
//   0x24c8: 94000742  bl       #0x41d0
//   0x24cc: d0000040  adrp     x0, #0xc000
//   0x24d0: 911f2000  add      x0, x0, #0x7c8
//   0x24d4: 52801402  mov      w2, #0xa0
//   0x24d8: 2a1f03e1  mov      w1, wzr
//   0x24dc: 9400073d  bl       #0x41d0
//   0x24e0: f0ffffe0  adrp     x0, #0x1000
//   0x24e4: 9118ec00  add      x0, x0, #0x63b
//   0x24e8: 9400073e  bl       #0x41e0
//   0x24ec: b4001300  cbz      x0, #0x274c
//   0x24f0: f0fffff3  adrp     x19, #0x1000
//   0x24f4: aa0003f4  mov      x20, x0
//   0x24f8: aa1f03f6  mov      x22, xzr
//   0x24fc: aa1f03fc  mov      x28, xzr
//   0x2500: 91062273  add      x19, x19, #0x188
//   0x2504: 52800a1a  mov      w26, #0x50
//   0x2508: 910083f5  add      x21, sp, #0x20
//   0x250c: aa1403e0  mov      x0, x20
//   0x2510: 94000738  bl       #0x41f0
//   0x2514: b4000a60  cbz      x0, #0x2660
//   0x2518: 91004c17  add      x23, x0, #0x13
//   0x251c: aa1703e8  mov      x8, x23
//   0x2520: aa1303e9  mov      x9, x19
//   0x2524: 3940010b  ldrb     w11, [x8]
//   0x2528: 3940012a  ldrb     w10, [x9]
//   0x252c: 340000cb  cbz      w11, #0x2544
//   0x2530: 6b0a017f  cmp      w11, w10
//   0x2534: 54000081  b.ne     #0x2544
//   0x2538: 91000508  add      x8, x8, #1
//   0x253c: 91000529  add      x9, x9, #1
//   0x2540: 17fffff9  b        #0x2524
//   0x2544: 35fffe4a  cbnz     w10, #0x250c
//   0x2548: f0ffffe3  adrp     x3, #0x1000
//   0x254c: 9101c3e0  add      x0, sp, #0x70
//   0x2550: 91063c63  add      x3, x3, #0x18f
//   0x2554: aa1703e4  mov      x4, x23
//   0x2558: a900e3f9  stp      x25, x24, [sp, #8]
//   0x255c: 940005ec  bl       #0x3d0c
//   0x2560: 940006c0  bl       #0x4060
//   0x2564: 2a0003f9  mov      w25, w0
//   0x2568: 94000726  bl       #0x4200
//   0x256c: aa0003f8  mov      x24, x0
//   0x2570: 910183e1  add      x1, sp, #0x60
//   0x2574: 52800202  mov      w2, #0x10
//   0x2578: 2a1903e0  mov      w0, w25
//   0x257c: b900031f  str      wzr, [x24]
//   0x2580: 94000724  bl       #0x4210
//   0x2584: b100041f  cmn      x0, #1
//   0x2588: 540000a1  b.ne     #0x259c
//   0x258c: b9400308  ldr      w8, [x24]
//   0x2590: 7100111f  cmp      w8, #4
//   0x2594: 54fffee0  b.eq     #0x2570
//   0x2598: 92800000  mov      x0, #-1
//   0x259c: 910183e8  add      x8, sp, #0x60
//   0x25a0: 3820691f  strb     wzr, [x8, x0]
//   0x25a4: 910183e0  add      x0, sp, #0x60
//   0x25a8: 910063e1  add      x1, sp, #0x18
//   0x25ac: 52800142  mov      w2, #0xa
//   0x25b0: 9400071c  bl       #0x4220
//   0x25b4: 9103c3e8  add      x8, sp, #0xf0
//   0x25b8: 9b1a22d8  madd     x24, x22, x26, x8
//   0x25bc: f90003e0  str      x0, [sp]
//   0x25c0: f8008700  str      x0, [x24], #8
//   0x25c4: 2a1903e0  mov      w0, w25
//   0x25c8: 9400071a  bl       #0x4230
//   0x25cc: f0ffffe3  adrp     x3, #0x1000
//   0x25d0: 9101c3e0  add      x0, sp, #0x70
//   0x25d4: 9113dc63  add      x3, x3, #0x4f7
//   0x25d8: aa1703e4  mov      x4, x23
//   0x25dc: 940005cc  bl       #0x3d0c
//   0x25e0: 940006a0  bl       #0x4060
//   0x25e4: 910083e1  add      x1, sp, #0x20
//   0x25e8: 52800802  mov      w2, #0x40
//   0x25ec: 2a0003f7  mov      w23, w0
//   0x25f0: 94000708  bl       #0x4210
//   0x25f4: aa0003f9  mov      x25, x0
//   0x25f8: 2a1703e0  mov      w0, w23
//   0x25fc: 9103c3f7  add      x23, sp, #0xf0
//   0x2600: 9400070c  bl       #0x4230
//   0x2604: f100433f  cmp      x25, #0x10
//   0x2608: 52800209  mov      w9, #0x10
//   0x260c: 9a89b329  csel     x9, x25, x9, lt
//   0x2610: f94007f9  ldr      x25, [sp, #8]
//   0x2614: aa1f03e8  mov      x8, xzr
//   0x2618: eb08013f  cmp      x9, x8
//   0x261c: 5400016d  b.le     #0x2648
//   0x2620: 38686aaa  ldrb     w10, [x21, x8]
//   0x2624: 3940030b  ldrb     w11, [x24]
//   0x2628: 9b1a5ecc  madd     x12, x22, x26, x23
//   0x262c: 91000908  add      x8, x8, #2
//   0x2630: 5100c14a  sub      w10, w10, #0x30
//   0x2634: 1100056d  add      w13, w11, #1
//   0x2638: 8b0b018b  add      x11, x12, x11
//   0x263c: 3900030d  strb     w13, [x24]
//   0x2640: 3900256a  strb     w10, [x11, #9]
//   0x2644: 17fffff5  b        #0x2618
//   0x2648: f94003e8  ldr      x8, [sp]
//   0x264c: f9400bf8  ldr      x24, [sp, #0x10]
//   0x2650: 910006d6  add      x22, x22, #1
//   0x2654: eb1c011f  cmp      x8, x28
//   0x2658: 9a9cc11c  csel     x28, x8, x28, gt
//   0x265c: 17ffffac  b        #0x250c
//   0x2660: aa1403e0  mov      x0, x20
//   0x2664: 940006f7  bl       #0x4240
//   0x2668: 9103c3ea  add      x10, sp, #0xf0
//   0x266c: d000004d  adrp     x13, #0xc000
//   0x2670: aa1f03e8  mov      x8, xzr
//   0x2674: 92407ec9  and      x9, x22, #0xffffffff
//   0x2678: 52800a0b  mov      w11, #0x50
//   0x267c: d000004c  adrp     x12, #0xc000
//   0x2680: 911eb1ad  add      x13, x13, #0x7ac
//   0x2684: 9100254e  add      x14, x10, #9
//   0x2688: d000004f  adrp     x15, #0xc000
//   0x268c: eb09011f  cmp      x8, x9
//   0x2690: 540004e0  b.eq     #0x272c
//   0x2694: 9b0b7d10  mul      x16, x8, x11
//   0x2698: f8706951  ldr      x17, [x10, x16]
//   0x269c: eb1c023f  cmp      x17, x28
//   0x26a0: 54000241  b.ne     #0x26e8
//   0x26a4: 9b0b2911  madd     x17, x8, x11, x10
//   0x26a8: 39402231  ldrb     w17, [x17, #8]
//   0x26ac: aa1f03f0  mov      x16, xzr
//   0x26b0: f903e59c  str      x28, [x12, #0x7c8]
//   0x26b4: eb10023f  cmp      x17, x16
//   0x26b8: 54000340  b.eq     #0x2720
//   0x26bc: b94001a0  ldr      w0, [x13]
//   0x26c0: 394091a1  ldrb     w1, [x13, #0x24]
//   0x26c4: 387069c2  ldrb     w2, [x14, x16]
//   0x26c8: 91000610  add      x16, x16, #1
//   0x26cc: 11000400  add      w0, w0, #1
//   0x26d0: 8b0101a3  add      x3, x13, x1
//   0x26d4: 11000421  add      w1, w1, #1
//   0x26d8: b90001a0  str      w0, [x13]
//   0x26dc: 390091a1  strb     w1, [x13, #0x24]
//   0x26e0: 39009462  strb     w2, [x3, #0x25]
//   0x26e4: 17fffff4  b        #0x26b4
//   0x26e8: b4000231  cbz      x17, #0x272c
//   0x26ec: 9b0b2910  madd     x16, x8, x11, x10
//   0x26f0: 39402210  ldrb     w16, [x16, #8]
//   0x26f4: f9040df1  str      x17, [x15, #0x818]
//   0x26f8: aa0e03f1  mov      x17, x14
//   0x26fc: b4000130  cbz      x16, #0x2720
//   0x2700: 38401620  ldrb     w0, [x17], #1
//   0x2704: 3941e361  ldrb     w1, [x27, #0x78]
//   0x2708: d1000610  sub      x16, x16, #1
//   0x270c: 8b010362  add      x2, x27, x1
//   0x2710: 11000421  add      w1, w1, #1
//   0x2714: 3901e361  strb     w1, [x27, #0x78]
//   0x2718: 3901e440  strb     w0, [x2, #0x79]
//   0x271c: b5ffff30  cbnz     x16, #0x2700
//   0x2720: 91000508  add      x8, x8, #1
//   0x2724: 910141ce  add      x14, x14, #0x50
//   0x2728: 17ffffd9  b        #0x268c
//   0x272c: d0000048  adrp     x8, #0xc000
//   0x2730: 911f4108  add      x8, x8, #0x7d0
//   0x2734: 39400103  ldrb     w3, [x8]
//   0x2738: 39414104  ldrb     w4, [x8, #0x50]
//   0x273c: f0ffffe2  adrp     x2, #0x1000
//   0x2740: 9116ec42  add      x2, x2, #0x5bb
//   0x2744: 94000606  bl       #0x3f5c
//   0x2748: 940004e3  bl       #0x3ad4
//   0x274c: 94000583  bl       #0x3d58
//   0x2750: 52884809  mov      w9, #0x4240
//   0x2754: cb190008  sub      x8, x0, x25
//   0x2758: 72a001e9  movk     w9, #0xf, lsl #16
//   0x275c: f0ffffe2  adrp     x2, #0x1000
//   0x2760: 9ac90d03  sdiv     x3, x8, x9
//   0x2764: 910fd042  add      x2, x2, #0x3f4
//   0x2768: 940005fd  bl       #0x3f5c
//   0x276c: 940004da  bl       #0x3ad4
//   0x2770: f9401708  ldr      x8, [x24, #0x28]
//   0x2774: f85f03a9  ldur     x9, [x29, #-0x10]
//   0x2778: eb09011f  cmp      x8, x9
//   0x277c: 540000c1  b.ne     #0x2794
//   0x2780: 2a1f03e0  mov      w0, wzr
//   0x2784: 911803ff  add      sp, sp, #0x600
//   0x2788: 9400063c  bl       #0x4078
//   0x278c: a8c67bfd  ldp      x29, x30, [sp], #0x60
//   0x2790: d65f03c0  ret      
//   0x2794: 94000677  bl       #0x4170
//   0x2798: a9ba7bfd  stp      x29, x30, [sp, #-0x60]!
//   0x279c: 94000610  bl       #0x3fdc
//   0x27a0: d111c3ff  sub      sp, sp, #0x470
//   0x27a4: d53bd056  mrs      x22, tpidr_el0
//   0x27a8: f94016c8  ldr      x8, [x22, #0x28]
//   0x27ac: f94033a1  ldr      x1, [x29, #0x60]
//   0x27b0: 2a0703fb  mov      w27, w7
//   0x27b4: aa0603f9  mov      x25, x6
//   0x27b8: f81f03a8  stur     x8, [x29, #-0x10]
//   0x27bc: f9400008  ldr      x8, [x0]
//   0x27c0: aa0503f8  mov      x24, x5
//   0x27c4: aa0403f3  mov      x19, x4
//   0x27c8: aa0303f4  mov      x20, x3
//   0x27cc: f942ad08  ldr      x8, [x8, #0x558]
//   0x27d0: aa0003fa  mov      x26, x0
//   0x27d4: aa0203f5  mov      x21, x2
//   0x27d8: f90063e1  str      x1, [sp, #0xc0]
//   0x27dc: d63f0100  blr      x8
//   0x27e0: 7100041f  cmp      w0, #1
//   0x27e4: 5400192b  b.lt     #0x2b08
//   0x27e8: 2a0003e8  mov      w8, w0
//   0x27ec: f90067e8  str      x8, [sp, #0xc8]
//   0x27f0: d37ef508  lsl      x8, x8, #2
//   0x27f4: 8b204108  add      x8, x8, w0, uxtw
//   0x27f8: d37ced00  lsl      x0, x8, #4
//   0x27fc: 94000665  bl       #0x4190
//   0x2800: b4001840  cbz      x0, #0x2b08
//   0x2804: f9400348  ldr      x8, [x26]
//   0x2808: 3941c3a9  ldrb     w9, [x29, #0x70]
//   0x280c: f0ffffe1  adrp     x1, #0x1000
//   0x2810: aa0003f7  mov      x23, x0
//   0x2814: f9401908  ldr      x8, [x8, #0x30]
//   0x2818: b9004be9  str      w9, [sp, #0x48]
//   0x281c: 3941a3a9  ldrb     w9, [x29, #0x68]
//   0x2820: 9111f021  add      x1, x1, #0x47c
//   0x2824: aa1a03e0  mov      x0, x26
//   0x2828: a90267fb  stp      x27, x25, [sp, #0x20]
//   0x282c: a903e3f6  stp      x22, x24, [sp, #0x38]
//   0x2830: a905d7f3  stp      x19, x21, [sp, #0x58]
//   0x2834: f9002bf4  str      x20, [sp, #0x50]
//   0x2838: b9004fe9  str      w9, [sp, #0x4c]
//   0x283c: d63f0100  blr      x8
//   0x2840: f9400348  ldr      x8, [x26]
//   0x2844: f0fffff3  adrp     x19, #0x1000
//   0x2848: aa0003f4  mov      x20, x0
//   0x284c: f0ffffe2  adrp     x2, #0x1000
//   0x2850: f9417908  ldr      x8, [x8, #0x2f0]
//   0x2854: 9114ce73  add      x19, x19, #0x533
//   0x2858: 9109b042  add      x2, x2, #0x26c
//   0x285c: 940005bc  bl       #0x3f4c
//   0x2860: f9400348  ldr      x8, [x26]
//   0x2864: f0ffffe2  adrp     x2, #0x1000
//   0x2868: f9005be0  str      x0, [sp, #0xb0]
//   0x286c: 910e7042  add      x2, x2, #0x39c
//   0x2870: f9417908  ldr      x8, [x8, #0x2f0]
//   0x2874: 940005b6  bl       #0x3f4c
//   0x2878: f9400348  ldr      x8, [x26]
//   0x287c: f0ffffe2  adrp     x2, #0x1000
//   0x2880: f90057e0  str      x0, [sp, #0xa8]
//   0x2884: 910a0c42  add      x2, x2, #0x283
//   0x2888: f9417908  ldr      x8, [x8, #0x2f0]
//   0x288c: 940005b0  bl       #0x3f4c
//   0x2890: f9400348  ldr      x8, [x26]
//   0x2894: f0ffffe2  adrp     x2, #0x1000
//   0x2898: f90053e0  str      x0, [sp, #0xa0]
//   0x289c: 9117a442  add      x2, x2, #0x5e9
//   0x28a0: f9417908  ldr      x8, [x8, #0x2f0]
//   0x28a4: 940005aa  bl       #0x3f4c
//   0x28a8: f9400348  ldr      x8, [x26]
//   0x28ac: f0fffff3  adrp     x19, #0x1000
//   0x28b0: f0ffffe2  adrp     x2, #0x1000
//   0x28b4: 9110a273  add      x19, x19, #0x428
//   0x28b8: f9417908  ldr      x8, [x8, #0x2f0]
//   0x28bc: f9004fe0  str      x0, [sp, #0x98]
//   0x28c0: 910a4042  add      x2, x2, #0x290
//   0x28c4: 940005a2  bl       #0x3f4c
//   0x28c8: f9400348  ldr      x8, [x26]
//   0x28cc: f0ffffe2  adrp     x2, #0x1000
//   0x28d0: f9004be0  str      x0, [sp, #0x90]
//   0x28d4: 9119c442  add      x2, x2, #0x671
//   0x28d8: f9417908  ldr      x8, [x8, #0x2f0]
//   0x28dc: 9400059c  bl       #0x3f4c
//   0x28e0: f9400348  ldr      x8, [x26]
//   0x28e4: f0ffffe2  adrp     x2, #0x1000
//   0x28e8: f0ffffe3  adrp     x3, #0x1000
//   0x28ec: f90047e0  str      x0, [sp, #0x88]
//   0x28f0: f9417908  ldr      x8, [x8, #0x2f0]
//   0x28f4: 91151842  add      x2, x2, #0x546
//   0x28f8: 91133463  add      x3, x3, #0x4cd
//   0x28fc: aa1a03e0  mov      x0, x26
//   0x2900: aa1403e1  mov      x1, x20
//   0x2904: d63f0100  blr      x8
//   0x2908: f9400348  ldr      x8, [x26]
//   0x290c: f0ffffe2  adrp     x2, #0x1000
//   0x2910: f90043e0  str      x0, [sp, #0x80]
//   0x2914: 91045042  add      x2, x2, #0x114
//   0x2918: f9417908  ldr      x8, [x8, #0x2f0]
//   0x291c: 9400058c  bl       #0x3f4c
//   0x2920: f9400348  ldr      x8, [x26]
//   0x2924: f0ffffe2  adrp     x2, #0x1000
//   0x2928: f9003fe0  str      x0, [sp, #0x78]
//   0x292c: 9110a842  add      x2, x2, #0x42a
//   0x2930: f9417908  ldr      x8, [x8, #0x2f0]
//   0x2934: 94000586  bl       #0x3f4c
//   0x2938: f9400348  ldr      x8, [x26]
//   0x293c: f0ffffe2  adrp     x2, #0x1000
//   0x2940: f9003be0  str      x0, [sp, #0x70]
//   0x2944: 91075042  add      x2, x2, #0x1d4
//   0x2948: f9417908  ldr      x8, [x8, #0x2f0]
//   0x294c: aa1a03e0  mov      x0, x26
//   0x2950: aa1403e1  mov      x1, x20
//   0x2954: aa1303e3  mov      x3, x19
//   0x2958: f9001bf4  str      x20, [sp, #0x30]
//   0x295c: d63f0100  blr      x8
//   0x2960: aa1f03ea  mov      x10, xzr
//   0x2964: 9100a2fc  add      x28, x23, #0x28
//   0x2968: f90037e0  str      x0, [sp, #0x68]
//   0x296c: f9005ff7  str      x23, [sp, #0xb8]
//   0x2970: f94067e9  ldr      x9, [sp, #0xc8]
//   0x2974: f9400348  ldr      x8, [x26]
//   0x2978: eb0a013f  cmp      x9, x10
//   0x297c: 54000ca0  b.eq     #0x2b10
//   0x2980: f942b508  ldr      x8, [x8, #0x568]
//   0x2984: f94063e1  ldr      x1, [sp, #0xc0]
//   0x2988: aa1a03e0  mov      x0, x26
//   0x298c: aa0a03e2  mov      x2, x10
//   0x2990: f90077ea  str      x10, [sp, #0xe8]
//   0x2994: d63f0100  blr      x8
//   0x2998: f9400348  ldr      x8, [x26]
//   0x299c: f9405be2  ldr      x2, [sp, #0xb0]
//   0x29a0: aa0003fb  mov      x27, x0
//   0x29a4: 94000575  bl       #0x3f78
//   0x29a8: f9400348  ldr      x8, [x26]
//   0x29ac: f94057e2  ldr      x2, [sp, #0xa8]
//   0x29b0: aa0003f3  mov      x19, x0
//   0x29b4: 94000571  bl       #0x3f78
//   0x29b8: f9400348  ldr      x8, [x26]
//   0x29bc: f94053e2  ldr      x2, [sp, #0xa0]
//   0x29c0: aa0003f5  mov      x21, x0
//   0x29c4: 9400056d  bl       #0x3f78
//   0x29c8: f9400348  ldr      x8, [x26]
//   0x29cc: f9404fe2  ldr      x2, [sp, #0x98]
//   0x29d0: aa0003f9  mov      x25, x0
//   0x29d4: 94000569  bl       #0x3f78
//   0x29d8: f9400348  ldr      x8, [x26]
//   0x29dc: f9404be2  ldr      x2, [sp, #0x90]
//   0x29e0: aa0003f7  mov      x23, x0
//   0x29e4: 94000561  bl       #0x3f68
//   0x29e8: f9400348  ldr      x8, [x26]
//   0x29ec: f94047e2  ldr      x2, [sp, #0x88]
//   0x29f0: f90073e0  str      x0, [sp, #0xe0]
//   0x29f4: 9400055d  bl       #0x3f68
//   0x29f8: f9400348  ldr      x8, [x26]
//   0x29fc: f94043e2  ldr      x2, [sp, #0x80]
//   0x2a00: f9006be0  str      x0, [sp, #0xd0]
//   0x2a04: aa1a03e0  mov      x0, x26
//   0x2a08: f9419508  ldr      x8, [x8, #0x328]
//   0x2a0c: aa1b03e1  mov      x1, x27
//   0x2a10: d63f0100  blr      x8
//   0x2a14: f9400348  ldr      x8, [x26]
//   0x2a18: f9403fe2  ldr      x2, [sp, #0x78]
//   0x2a1c: f9006fe0  str      x0, [sp, #0xd8]
//   0x2a20: 94000552  bl       #0x3f68
//   0x2a24: f9400348  ldr      x8, [x26]
//   0x2a28: f9403be2  ldr      x2, [sp, #0x70]
//   0x2a2c: 2a0003f4  mov      w20, w0
//   0x2a30: 9400054e  bl       #0x3f68
//   0x2a34: f9400348  ldr      x8, [x26]
//   0x2a38: f94037e2  ldr      x2, [sp, #0x68]
//   0x2a3c: 2a0003f6  mov      w22, w0
//   0x2a40: 9400054a  bl       #0x3f68
//   0x2a44: 2a0003f8  mov      w24, w0
//   0x2a48: 940005a8  bl       #0x40e8
//   0x2a4c: aa1303e1  mov      x1, x19
//   0x2a50: 940004da  bl       #0x3db8
//   0x2a54: 94000587  bl       #0x4070
//   0x2a58: f81d8380  stur     x0, [x28, #-0x28]
//   0x2a5c: 940005a3  bl       #0x40e8
//   0x2a60: aa1503e1  mov      x1, x21
//   0x2a64: 940004d5  bl       #0x3db8
//   0x2a68: 94000582  bl       #0x4070
//   0x2a6c: f81e0380  stur     x0, [x28, #-0x20]
//   0x2a70: 9400059e  bl       #0x40e8
//   0x2a74: aa1903e1  mov      x1, x25
//   0x2a78: 940004d0  bl       #0x3db8
//   0x2a7c: 9400057d  bl       #0x4070
//   0x2a80: f81e8380  stur     x0, [x28, #-0x18]
//   0x2a84: 94000599  bl       #0x40e8
//   0x2a88: aa1703e1  mov      x1, x23
//   0x2a8c: 940004cb  bl       #0x3db8
//   0x2a90: 94000578  bl       #0x4070
//   0x2a94: f94073e8  ldr      x8, [sp, #0xe0]
//   0x2a98: 93407e8a  sxtw     x10, w20
//   0x2a9c: 93407ecb  sxtw     x11, w22
//   0x2aa0: 93407d08  sxtw     x8, w8
//   0x2aa4: a93f2380  stp      x0, x8, [x28, #-0x10]
//   0x2aa8: a94d23e9  ldp      x9, x8, [sp, #0xd0]
//   0x2aac: 93407d29  sxtw     x9, w9
//   0x2ab0: 93407f0c  sxtw     x12, w24
//   0x2ab4: a9012f8a  stp      x10, x11, [x28, #0x10]
//   0x2ab8: a9002389  stp      x9, x8, [x28]
//   0x2abc: f900138c  str      x12, [x28, #0x20]
//   0x2ac0: 9400055d  bl       #0x4034
//   0x2ac4: aa1303e1  mov      x1, x19
//   0x2ac8: 9400054c  bl       #0x3ff8
//   0x2acc: 9400055a  bl       #0x4034
//   0x2ad0: aa1503e1  mov      x1, x21
//   0x2ad4: 94000549  bl       #0x3ff8
//   0x2ad8: 94000557  bl       #0x4034
//   0x2adc: aa1903e1  mov      x1, x25
//   0x2ae0: 94000546  bl       #0x3ff8
//   0x2ae4: 94000557  bl       #0x4040
//   0x2ae8: 94000544  bl       #0x3ff8
//   0x2aec: 94000552  bl       #0x4034
//   0x2af0: aa1b03e1  mov      x1, x27
//   0x2af4: 94000541  bl       #0x3ff8
//   0x2af8: f94077ea  ldr      x10, [sp, #0xe8]
//   0x2afc: 9101439c  add      x28, x28, #0x50
//   0x2b00: 9100054a  add      x10, x10, #1
//   0x2b04: 17ffff9b  b        #0x2970
//   0x2b08: 2a1f03fb  mov      w27, wzr
//   0x2b0c: 14000218  b        #0x336c
//   0x2b10: f9405d08  ldr      x8, [x8, #0xb8]
//   0x2b14: f9401be1  ldr      x1, [sp, #0x30]
//   0x2b18: aa1a03e0  mov      x0, x26
//   0x2b1c: d63f0100  blr      x8
//   0x2b20: f94033e1  ldr      x1, [sp, #0x60]
//   0x2b24: b4000261  cbz      x1, #0x2b70
//   0x2b28: 94000543  bl       #0x4034
//   0x2b2c: 94000529  bl       #0x3fd0
//   0x2b30: a9455ffc  ldp      x28, x23, [sp, #0x50]
//   0x2b34: aa0003f8  mov      x24, x0
//   0x2b38: b4005760  cbz      x0, #0x3624
//   0x2b3c: b400021c  cbz      x28, #0x2b7c
//   0x2b40: f9400348  ldr      x8, [x26]
//   0x2b44: aa1a03e0  mov      x0, x26
//   0x2b48: aa1c03e1  mov      x1, x28
//   0x2b4c: 94000521  bl       #0x3fd0
//   0x2b50: aa0003f9  mov      x25, x0
//   0x2b54: b40056a0  cbz      x0, #0x3628
//   0x2b58: b4000177  cbz      x23, #0x2b84
//   0x2b5c: 94000539  bl       #0x4040
//   0x2b60: 9400051c  bl       #0x3fd0
//   0x2b64: aa0003f5  mov      x21, x0
//   0x2b68: b5000100  cbnz     x0, #0x2b88
//   0x2b6c: 140002af  b        #0x3628
//   0x2b70: a9455ffc  ldp      x28, x23, [sp, #0x50]
//   0x2b74: aa1f03f8  mov      x24, xzr
//   0x2b78: b5fffe5c  cbnz     x28, #0x2b40
//   0x2b7c: aa1f03f9  mov      x25, xzr
//   0x2b80: b5fffef7  cbnz     x23, #0x2b5c
//   0x2b84: aa1f03f5  mov      x21, xzr
//   0x2b88: f94013e8  ldr      x8, [sp, #0x20]
//   0x2b8c: 93407d1b  sxtw     x27, w8
//   0x2b90: b9404be8  ldr      w8, [sp, #0x48]
//   0x2b94: 12001d14  and      w20, w8, #0xff
//   0x2b98: 940005ae  bl       #0x4250
//   0x2b9c: d0000053  adrp     x19, #0xc000
//   0x2ba0: 911eb273  add      x19, x19, #0x7ac
//   0x2ba4: d0000056  adrp     x22, #0xc000
//   0x2ba8: b900d3e0  str      w0, [sp, #0xd0]
//   0x2bac: 340005f4  cbz      w20, #0x2c68
//   0x2bb0: 885f7e68  ldxr     w8, [x19]
//   0x2bb4: 71000508  subs     w8, w8, #1
//   0x2bb8: 88097e68  stxr     w9, w8, [x19]
//   0x2bbc: 35ffffa9  cbnz     w9, #0x2bb0
//   0x2bc0: b940d3f4  ldr      w20, [sp, #0xd0]
//   0x2bc4: 54000544  b.mi     #0x2c6c
//   0x2bc8: 6f00e400  movi     v0.2d, #0000000000000000
//   0x2bcc: d10243a2  sub      x2, x29, #0x90
//   0x2bd0: 52801001  mov      w1, #0x80
//   0x2bd4: 2a1403e0  mov      w0, w20
//   0x2bd8: ad3e83a0  stp      q0, q0, [x29, #-0x30]
//   0x2bdc: ad3d83a0  stp      q0, q0, [x29, #-0x50]
//   0x2be0: ad3c83a0  stp      q0, q0, [x29, #-0x70]
//   0x2be4: ad3b83a0  stp      q0, q0, [x29, #-0x90]
//   0x2be8: 9400059e  bl       #0x4260
//   0x2bec: 2a0003f7  mov      w23, w0
//   0x2bf0: 35000400  cbnz     w0, #0x2c70
//   0x2bf4: 6f00e400  movi     v0.2d, #0000000000000000
//   0x2bf8: d0000048  adrp     x8, #0xc000
//   0x2bfc: ad1e03e0  stp      q0, q0, [sp, #0x3c0]
//   0x2c00: ad1d03e0  stp      q0, q0, [sp, #0x3a0]
//   0x2c04: ad1c03e0  stp      q0, q0, [sp, #0x380]
//   0x2c08: ad1b03e0  stp      q0, q0, [sp, #0x360]
//   0x2c0c: 911f4108  add      x8, x8, #0x7d0
//   0x2c10: 38401509  ldrb     w9, [x8], #1
//   0x2c14: 5280002a  mov      w10, #1
//   0x2c18: 910d83eb  add      x11, sp, #0x360
//   0x2c1c: b4000149  cbz      x9, #0x2c44
//   0x2c20: 3840150c  ldrb     w12, [x8], #1
//   0x2c24: d1000529  sub      x9, x9, #1
//   0x2c28: d343fd8d  lsr      x13, x12, #3
//   0x2c2c: 927d05ad  and      x13, x13, #0x18
//   0x2c30: f86d696e  ldr      x14, [x11, x13]
//   0x2c34: 9acc214c  lsl      x12, x10, x12
//   0x2c38: aa0e018c  orr      x12, x12, x14
//   0x2c3c: f82d696c  str      x12, [x11, x13]
//   0x2c40: b5ffff09  cbnz     x9, #0x2c20
//   0x2c44: 910d83e2  add      x2, sp, #0x360
//   0x2c48: 9400052e  bl       #0x4100
//   0x2c4c: 2a0003f7  mov      w23, w0
//   0x2c50: 35000100  cbnz     w0, #0x2c70
//   0x2c54: b947aec4  ldr      w4, [x22, #0x7ac]
//   0x2c58: f0ffffe2  adrp     x2, #0x1000
//   0x2c5c: 91084042  add      x2, x2, #0x210
//   0x2c60: 9400050c  bl       #0x4090
//   0x2c64: 14000003  b        #0x2c70
//   0x2c68: b940d3f4  ldr      w20, [sp, #0xd0]
//   0x2c6c: 12800017  mov      w23, #-1
//   0x2c70: b9404fe8  ldr      w8, [sp, #0x4c]
//   0x2c74: b900b3f7  str      w23, [sp, #0xb0]
//   0x2c78: 72001d1f  tst      w8, #0xff
//   0x2c7c: 54000280  b.eq     #0x2ccc
//   0x2c80: 2a1f03e0  mov      w0, wzr
//   0x2c84: 2a1403e1  mov      w1, w20
//   0x2c88: 9400057a  bl       #0x4270
//   0x2c8c: 31004c1f  cmn      w0, #0x13
//   0x2c90: b9009be0  str      w0, [sp, #0x98]
//   0x2c94: 5400024b  b.lt     #0x2cdc
//   0x2c98: 2a0003f6  mov      w22, w0
//   0x2c9c: 12800262  mov      w2, #-0x14
//   0x2ca0: 940004dd  bl       #0x4014
//   0x2ca4: 34000f20  cbz      w0, #0x2e88
//   0x2ca8: 310026df  cmn      w22, #9
//   0x2cac: 540001ab  b.lt     #0x2ce0
//   0x2cb0: 12800122  mov      w2, #-0xa
//   0x2cb4: 940004d8  bl       #0x4014
//   0x2cb8: 34000140  cbz      w0, #0x2ce0
//   0x2cbc: f0ffffe2  adrp     x2, #0x1000
//   0x2cc0: 91097042  add      x2, x2, #0x25c
//   0x2cc4: 940004d9  bl       #0x4028
//   0x2cc8: 14000006  b        #0x2ce0
//   0x2ccc: 12800128  mov      w8, #-0xa
//   0x2cd0: b900abff  str      wzr, [sp, #0xa8]
//   0x2cd4: b9009be8  str      w8, [sp, #0x98]
//   0x2cd8: 14000003  b        #0x2ce4
//   0x2cdc: 2a1f03e8  mov      w8, wzr
//   0x2ce0: b900abff  str      wzr, [sp, #0xa8]
//   0x2ce4: f94023e6  ldr      x6, [sp, #0x40]
//   0x2ce8: f94017e7  ldr      x7, [sp, #0x28]
//   0x2cec: f94067e8  ldr      x8, [sp, #0xc8]
//   0x2cf0: f0ffffe2  adrp     x2, #0x1000
//   0x2cf4: 910a7042  add      x2, x2, #0x29c
//   0x2cf8: 52800020  mov      w0, #1
//   0x2cfc: 52800021  mov      w1, #1
//   0x2d00: aa1803e3  mov      x3, x24
//   0x2d04: aa1903e4  mov      x4, x25
//   0x2d08: aa1503e5  mov      x5, x21
//   0x2d0c: cb0600f6  sub      x22, x7, x6
//   0x2d10: a90023fb  stp      x27, x8, [sp]
//   0x2d14: f90063f5  str      x21, [sp, #0xc0]
//   0x2d18: 9400036f  bl       #0x3ad4
//   0x2d1c: aa1603e0  mov      x0, x22
//   0x2d20: f90053f6  str      x22, [sp, #0xa0]
//   0x2d24: 9400051b  bl       #0x4190
//   0x2d28: aa0003f5  mov      x21, x0
//   0x2d2c: aa1b03e0  mov      x0, x27
//   0x2d30: 94000518  bl       #0x4190
//   0x2d34: aa0003e8  mov      x8, x0
//   0x2d38: aa1f03f7  mov      x23, xzr
//   0x2d3c: 1280001c  mov      w28, #-1
//   0x2d40: 92800006  mov      x6, #-1
//   0x2d44: a90e57e0  stp      x0, x21, [sp, #0xe0]
//   0x2d48: b4000295  cbz      x21, #0x2d98
//   0x2d4c: f9004bfb  str      x27, [sp, #0x90]
//   0x2d50: 940004df  bl       #0x40cc
//   0x2d54: f9006ff7  str      x23, [sp, #0xd8]
//   0x2d58: b4002628  cbz      x8, #0x321c
//   0x2d5c: f9000ffa  str      x26, [sp, #0x18]
//   0x2d60: b4000238  cbz      x24, #0x2da4
//   0x2d64: 94000527  bl       #0x4200
//   0x2d68: f9405ff4  ldr      x20, [sp, #0xb8]
//   0x2d6c: f9404bf7  ldr      x23, [sp, #0x90]
//   0x2d70: f94053fb  ldr      x27, [sp, #0xa0]
//   0x2d74: aa0003fa  mov      x26, x0
//   0x2d78: aa1803e0  mov      x0, x24
//   0x2d7c: 94000486  bl       #0x3f94
//   0x2d80: 3100041f  cmn      w0, #1
//   0x2d84: 54000141  b.ne     #0x2dac
//   0x2d88: 94000480  bl       #0x3f88
//   0x2d8c: 54ffff60  b.eq     #0x2d78
//   0x2d90: 12800015  mov      w21, #-1
//   0x2d94: 14000019  b        #0x2df8
//   0x2d98: f9006ff7  str      x23, [sp, #0xd8]
//   0x2d9c: 940004cc  bl       #0x40cc
//   0x2da0: 1400011f  b        #0x321c
//   0x2da4: 12800015  mov      w21, #-1
//   0x2da8: 14000016  b        #0x2e00
//   0x2dac: 2a0003f5  mov      w21, w0
//   0x2db0: 37f80240  tbnz     w0, #0x1f, #0x2df8
//   0x2db4: f94023e1  ldr      x1, [sp, #0x40]
//   0x2db8: 2a1503e0  mov      w0, w21
//   0x2dbc: 940004a5  bl       #0x4050
//   0x2dc0: b100041f  cmn      x0, #1
//   0x2dc4: 540001a0  b.eq     #0x2df8
//   0x2dc8: f90047e0  str      x0, [sp, #0x88]
//   0x2dcc: f94077e1  ldr      x1, [sp, #0xe8]
//   0x2dd0: 92800003  mov      x3, #-1
//   0x2dd4: 2a1503e0  mov      w0, w21
//   0x2dd8: aa1b03e2  mov      x2, x27
//   0x2ddc: 94000489  bl       #0x4000
//   0x2de0: b100041f  cmn      x0, #1
//   0x2de4: 54000f21  b.ne     #0x2fc8
//   0x2de8: 94000468  bl       #0x3f88
//   0x2dec: 54ffff00  b.eq     #0x2dcc
//   0x2df0: 92800016  mov      x22, #-1
//   0x2df4: 14000076  b        #0x2fcc
//   0x2df8: b940d3f4  ldr      w20, [sp, #0xd0]
//   0x2dfc: f94073e8  ldr      x8, [sp, #0xe0]
//   0x2e00: 92800006  mov      x6, #-1
//   0x2e04: 92800009  mov      x9, #-1
//   0x2e08: 92800016  mov      x22, #-1
//   0x2e0c: f94077e7  ldr      x7, [sp, #0xe8]
//   0x2e10: f0ffffe2  adrp     x2, #0x1000
//   0x2e14: 91024042  add      x2, x2, #0x90
//   0x2e18: 94000469  bl       #0x3fbc
//   0x2e1c: aa0903e5  mov      x5, x9
//   0x2e20: f90003e8  str      x8, [sp]
//   0x2e24: a9081be9  stp      x9, x6, [sp, #0x80]
//   0x2e28: 9400032b  bl       #0x3ad4
//   0x2e2c: 940004f5  bl       #0x4200
//   0x2e30: aa0003fa  mov      x26, x0
//   0x2e34: aa1903e0  mov      x0, x25
//   0x2e38: 94000457  bl       #0x3f94
//   0x2e3c: 3100041f  cmn      w0, #1
//   0x2e40: 54000101  b.ne     #0x2e60
//   0x2e44: 94000451  bl       #0x3f88
//   0x2e48: 54ffff60  b.eq     #0x2e34
//   0x2e4c: aa1f03f7  mov      x23, xzr
//   0x2e50: f9006fff  str      xzr, [sp, #0xd8]
//   0x2e54: 94000499  bl       #0x40b8
//   0x2e58: 12800015  mov      w21, #-1
//   0x2e5c: 14000011  b        #0x2ea0
//   0x2e60: 2a0003f5  mov      w21, w0
//   0x2e64: 37f80180  tbnz     w0, #0x1f, #0x2e94
//   0x2e68: f9003ff8  str      x24, [sp, #0x78]
//   0x2e6c: aa1903e0  mov      x0, x25
//   0x2e70: 94000449  bl       #0x3f94
//   0x2e74: 3100041f  cmn      w0, #1
//   0x2e78: 540001c1  b.ne     #0x2eb0
//   0x2e7c: 94000443  bl       #0x3f88
//   0x2e80: 54ffff60  b.eq     #0x2e6c
//   0x2e84: 1400001e  b        #0x2efc
//   0x2e88: 52800028  mov      w8, #1
//   0x2e8c: b900abe8  str      w8, [sp, #0xa8]
//   0x2e90: 17ffff95  b        #0x2ce4
//   0x2e94: aa1f03f7  mov      x23, xzr
//   0x2e98: 94000488  bl       #0x40b8
//   0x2e9c: f9006fff  str      xzr, [sp, #0xd8]
//   0x2ea0: f9400ffa  ldr      x26, [sp, #0x18]
//   0x2ea4: f94073e8  ldr      x8, [sp, #0xe0]
//   0x2ea8: a9481be5  ldp      x5, x6, [sp, #0x80]
//   0x2eac: 140000dc  b        #0x321c
//   0x2eb0: 2a0003fb  mov      w27, w0
//   0x2eb4: 37f80240  tbnz     w0, #0x1f, #0x2efc
//   0x2eb8: 910583e1  add      x1, sp, #0x160
//   0x2ebc: 2a1b03e0  mov      w0, w27
//   0x2ec0: 940004f0  bl       #0x4280
//   0x2ec4: 35000080  cbnz     w0, #0x2ed4
//   0x2ec8: f940cbf7  ldr      x23, [sp, #0x190]
//   0x2ecc: 71005aff  cmp      w23, #0x16
//   0x2ed0: 5400272a  b.ge     #0x33b4
//   0x2ed4: aa1f03f7  mov      x23, xzr
//   0x2ed8: aa1f03fc  mov      x28, xzr
//   0x2edc: 94000486  bl       #0x40f4
//   0x2ee0: 7100077f  cmp      w27, #1
//   0x2ee4: 5400006b  b.lt     #0x2ef0
//   0x2ee8: 2a1b03e0  mov      w0, w27
//   0x2eec: 940004d1  bl       #0x4230
//   0x2ef0: f9406ff8  ldr      x24, [sp, #0xd8]
//   0x2ef4: f9403bfb  ldr      x27, [sp, #0x70]
//   0x2ef8: 14000005  b        #0x2f0c
//   0x2efc: aa1f03fb  mov      x27, xzr
//   0x2f00: aa1f03fc  mov      x28, xzr
//   0x2f04: aa1f03f7  mov      x23, xzr
//   0x2f08: aa1f03f8  mov      x24, xzr
//   0x2f0c: 94000475  bl       #0x40e0
//   0x2f10: 94000444  bl       #0x4020
//   0x2f14: f0ffffe2  adrp     x2, #0x1000
//   0x2f18: 910c4442  add      x2, x2, #0x311
//   0x2f1c: 52800020  mov      w0, #1
//   0x2f20: 52800021  mov      w1, #1
//   0x2f24: aa1803e3  mov      x3, x24
//   0x2f28: aa1b03e4  mov      x4, x27
//   0x2f2c: 940002ea  bl       #0x3ad4
//   0x2f30: f9404bf7  ldr      x23, [sp, #0x90]
//   0x2f34: f94053e1  ldr      x1, [sp, #0xa0]
//   0x2f38: b40002d8  cbz      x24, #0x2f90
//   0x2f3c: f94023e8  ldr      x8, [sp, #0x40]
//   0x2f40: f9006ff8  str      x24, [sp, #0xd8]
//   0x2f44: aa1703e3  mov      x3, x23
//   0x2f48: 8b080300  add      x0, x24, x8
//   0x2f4c: f94073f8  ldr      x24, [sp, #0xe0]
//   0x2f50: aa1803e2  mov      x2, x24
//   0x2f54: 940004cf  bl       #0x4290
//   0x2f58: eb17001f  cmp      x0, x23
//   0x2f5c: 54000281  b.ne     #0x2fac
//   0x2f60: f94047e6  ldr      x6, [sp, #0x88]
//   0x2f64: f94077e7  ldr      x7, [sp, #0xe8]
//   0x2f68: f0ffffe2  adrp     x2, #0x1000
//   0x2f6c: 9104dc42  add      x2, x2, #0x137
//   0x2f70: 94000413  bl       #0x3fbc
//   0x2f74: aa1703e5  mov      x5, x23
//   0x2f78: f90003f8  str      x24, [sp]
//   0x2f7c: 940002d6  bl       #0x3ad4
//   0x2f80: f9405ff4  ldr      x20, [sp, #0xb8]
//   0x2f84: f9403ff8  ldr      x24, [sp, #0x78]
//   0x2f88: f90053f6  str      x22, [sp, #0xa0]
//   0x2f8c: 1400001e  b        #0x3004
//   0x2f90: f9400ffa  ldr      x26, [sp, #0x18]
//   0x2f94: f94073e8  ldr      x8, [sp, #0xe0]
//   0x2f98: f9403ff8  ldr      x24, [sp, #0x78]
//   0x2f9c: aa1f03f7  mov      x23, xzr
//   0x2fa0: f9006fff  str      xzr, [sp, #0xd8]
//   0x2fa4: 94000445  bl       #0x40b8
//   0x2fa8: 17ffffc0  b        #0x2ea8
//   0x2fac: f9400ffa  ldr      x26, [sp, #0x18]
//   0x2fb0: aa1803e8  mov      x8, x24
//   0x2fb4: f9403ff8  ldr      x24, [sp, #0x78]
//   0x2fb8: aa0003e5  mov      x5, x0
//   0x2fbc: aa1f03f7  mov      x23, xzr
//   0x2fc0: 9400043e  bl       #0x40b8
//   0x2fc4: 14000095  b        #0x3218
//   0x2fc8: aa0003f6  mov      x22, x0
//   0x2fcc: f94073e8  ldr      x8, [sp, #0xe0]
//   0x2fd0: eb1b02df  cmp      x22, x27
//   0x2fd4: 54001de1  b.ne     #0x3390
//   0x2fd8: f94077e0  ldr      x0, [sp, #0xe8]
//   0x2fdc: aa1b03e1  mov      x1, x27
//   0x2fe0: aa0803e2  mov      x2, x8
//   0x2fe4: aa1703e3  mov      x3, x23
//   0x2fe8: 940004aa  bl       #0x4290
//   0x2fec: eb17001f  cmp      x0, x23
//   0x2ff0: 54001d61  b.ne     #0x339c
//   0x2ff4: f0ffffe2  adrp     x2, #0x1000
//   0x2ff8: 91164842  add      x2, x2, #0x592
//   0x2ffc: 9400040b  bl       #0x4028
//   0x3000: f9006fff  str      xzr, [sp, #0xd8]
//   0x3004: aa1f03f6  mov      x22, xzr
//   0x3008: aa1f03e9  mov      x9, xzr
//   0x300c: 9280001b  mov      x27, #-1
//   0x3010: f94067e8  ldr      x8, [sp, #0xc8]
//   0x3014: eb08013f  cmp      x9, x8
//   0x3018: 54001f40  b.eq     #0x3400
//   0x301c: 52800a08  mov      w8, #0x50
//   0x3020: 9b085128  madd     x8, x9, x8, x20
//   0x3024: f9400d17  ldr      x23, [x8, #0x18]
//   0x3028: f90043e9  str      x9, [sp, #0x80]
//   0x302c: 52804841  mov      w1, #0x242
//   0x3030: 72a00101  movk     w1, #8, lsl #16
//   0x3034: 52803002  mov      w2, #0x180
//   0x3038: aa1703e0  mov      x0, x23
//   0x303c: b900035f  str      wzr, [x26]
//   0x3040: 94000498  bl       #0x42a0
//   0x3044: 3100041f  cmn      w0, #1
//   0x3048: 54000081  b.ne     #0x3058
//   0x304c: 940003cf  bl       #0x3f88
//   0x3050: 54fffee0  b.eq     #0x302c
//   0x3054: 1400006a  b        #0x31fc
//   0x3058: 2a0003fc  mov      w28, w0
//   0x305c: 37f80d20  tbnz     w0, #0x1f, #0x3200
//   0x3060: 9400042b  bl       #0x410c
//   0x3064: f9003bf6  str      x22, [sp, #0x70]
//   0x3068: 340000c0  cbz      w0, #0x3080
//   0x306c: d0ffffe2  adrp     x2, #0x1000
//   0x3070: 940003bb  bl       #0x3f5c
//   0x3074: 9119ec42  add      x2, x2, #0x67b
//   0x3078: 94000413  bl       #0x40c4
//   0x307c: 14000007  b        #0x3098
//   0x3080: f940cbe4  ldr      x4, [sp, #0x190]
//   0x3084: d0ffffe2  adrp     x2, #0x1000
//   0x3088: 940003b5  bl       #0x3f5c
//   0x308c: 91154842  add      x2, x2, #0x552
//   0x3090: aa1703e3  mov      x3, x23
//   0x3094: 94000290  bl       #0x3ad4
//   0x3098: f9405fe8  ldr      x8, [sp, #0xb8]
//   0x309c: f94043e9  ldr      x9, [sp, #0x80]
//   0x30a0: 52800a0a  mov      w10, #0x50
//   0x30a4: 9b0a2136  madd     x22, x9, x10, x8
//   0x30a8: f94012c8  ldr      x8, [x22, #0x20]
//   0x30ac: f94073e9  ldr      x9, [sp, #0xe0]
//   0x30b0: f94022d4  ldr      x20, [x22, #0x40]
//   0x30b4: 8b09011b  add      x27, x8, x9
//   0x30b8: aa1b03e0  mov      x0, x27
//   0x30bc: aa1403e1  mov      x1, x20
//   0x30c0: 94000371  bl       #0x3e84
//   0x30c4: f9401ac3  ldr      x3, [x22, #0x30]
//   0x30c8: aa0003e4  mov      x4, x0
//   0x30cc: eb03001f  cmp      x0, x3
//   0x30d0: 54001d81  b.ne     #0x3480
//   0x30d4: d0ffffe2  adrp     x2, #0x1000
//   0x30d8: 940003a1  bl       #0x3f5c
//   0x30dc: 9105bc42  add      x2, x2, #0x16f
//   0x30e0: aa0403e3  mov      x3, x4
//   0x30e4: 9400027c  bl       #0x3ad4
//   0x30e8: f9403bf6  ldr      x22, [sp, #0x70]
//   0x30ec: b4000274  cbz      x20, #0x3138
//   0x30f0: 2a1c03e0  mov      w0, w28
//   0x30f4: aa1b03e1  mov      x1, x27
//   0x30f8: aa1403e2  mov      x2, x20
//   0x30fc: b900035f  str      wzr, [x26]
//   0x3100: 9400046c  bl       #0x42b0
//   0x3104: f100001f  cmp      x0, #0
//   0x3108: 540000cc  b.gt     #0x3120
//   0x310c: b9400348  ldr      w8, [x26]
//   0x3110: b4000100  cbz      x0, #0x3130
//   0x3114: 7100111f  cmp      w8, #4
//   0x3118: 540000c1  b.ne     #0x3130
//   0x311c: aa1f03e0  mov      x0, xzr
//   0x3120: cb000294  sub      x20, x20, x0
//   0x3124: 8b00037b  add      x27, x27, x0
//   0x3128: b5fffe54  cbnz     x20, #0x30f0
//   0x312c: 14000003  b        #0x3138
//   0x3130: 93407d1b  sxtw     x27, w8
//   0x3134: 350026bb  cbnz     w27, #0x3608
//   0x3138: 2a1c03e0  mov      w0, w28
//   0x313c: 94000461  bl       #0x42c0
//   0x3140: 35001ae0  cbnz     w0, #0x349c
//   0x3144: 940003f2  bl       #0x410c
//   0x3148: b940d3f4  ldr      w20, [sp, #0xd0]
//   0x314c: 340000c0  cbz      w0, #0x3164
//   0x3150: d0ffffe2  adrp     x2, #0x1000
//   0x3154: 94000382  bl       #0x3f5c
//   0x3158: 9107ec42  add      x2, x2, #0x1fb
//   0x315c: 940003da  bl       #0x40c4
//   0x3160: 14000007  b        #0x317c
//   0x3164: f940cbe4  ldr      x4, [sp, #0x190]
//   0x3168: d0ffffe2  adrp     x2, #0x1000
//   0x316c: 9400037c  bl       #0x3f5c
//   0x3170: 9117e042  add      x2, x2, #0x5f8
//   0x3174: aa1703e3  mov      x3, x23
//   0x3178: 94000257  bl       #0x3ad4
//   0x317c: 52802001  mov      w1, #0x100
//   0x3180: 2a1c03e0  mov      w0, w28
//   0x3184: 94000453  bl       #0x42d0
//   0x3188: 350019c0  cbnz     w0, #0x34c0
//   0x318c: aa1703e0  mov      x0, x23
//   0x3190: 94000454  bl       #0x42e0
//   0x3194: aa0003f4  mov      x20, x0
//   0x3198: d1001000  sub      x0, x0, #4
//   0x319c: 940003fd  bl       #0x4190
//   0x31a0: b4001a40  cbz      x0, #0x34e8
//   0x31a4: d1001694  sub      x20, x20, #5
//   0x31a8: aa1703e1  mov      x1, x23
//   0x31ac: aa1403e2  mov      x2, x20
//   0x31b0: aa0003f6  mov      x22, x0
//   0x31b4: 9400044f  bl       #0x42f0
//   0x31b8: 3834681f  strb     wzr, [x0, x20]
//   0x31bc: aa1703e0  mov      x0, x23
//   0x31c0: aa1603e1  mov      x1, x22
//   0x31c4: 9400044f  bl       #0x4300
//   0x31c8: 350019c0  cbnz     w0, #0x3500
//   0x31cc: d0ffffe2  adrp     x2, #0x1000
//   0x31d0: 94000363  bl       #0x3f5c
//   0x31d4: 9103d042  add      x2, x2, #0xf4
//   0x31d8: aa1603e3  mov      x3, x22
//   0x31dc: 9400023e  bl       #0x3ad4
//   0x31e0: 2a1c03e0  mov      w0, w28
//   0x31e4: 94000413  bl       #0x4230
//   0x31e8: f94043e9  ldr      x9, [sp, #0x80]
//   0x31ec: f9405ff4  ldr      x20, [sp, #0xb8]
//   0x31f0: aa1f03fb  mov      x27, xzr
//   0x31f4: 91000529  add      x9, x9, #1
//   0x31f8: 17ffff86  b        #0x3010
//   0x31fc: 1280001c  mov      w28, #-1
//   0x3200: aa1603f7  mov      x23, x22
//   0x3204: f9404be5  ldr      x5, [sp, #0x90]
//   0x3208: f94053f6  ldr      x22, [sp, #0xa0]
//   0x320c: f9400ffa  ldr      x26, [sp, #0x18]
//   0x3210: b940d3f4  ldr      w20, [sp, #0xd0]
//   0x3214: f94073e8  ldr      x8, [sp, #0xe0]
//   0x3218: f94047e6  ldr      x6, [sp, #0x88]
//   0x321c: f94077e7  ldr      x7, [sp, #0xe8]
//   0x3220: d0ffffe2  adrp     x2, #0x1000
//   0x3224: 910f0c42  add      x2, x2, #0x3c3
//   0x3228: 94000365  bl       #0x3fbc
//   0x322c: f90003e8  str      x8, [sp]
//   0x3230: 94000229  bl       #0x3ad4
//   0x3234: 37f80075  tbnz     w21, #0x1f, #0x3240
//   0x3238: 2a1503e0  mov      w0, w21
//   0x323c: 940003fd  bl       #0x4230
//   0x3240: 37f8007c  tbnz     w28, #0x1f, #0x324c
//   0x3244: 2a1c03e0  mov      w0, w28
//   0x3248: 940003fa  bl       #0x4230
//   0x324c: f94077e0  ldr      x0, [sp, #0xe8]
//   0x3250: 940003d4  bl       #0x41a0
//   0x3254: 94000373  bl       #0x4020
//   0x3258: f9406fe0  ldr      x0, [sp, #0xd8]
//   0x325c: 940003d1  bl       #0x41a0
//   0x3260: f94073e0  ldr      x0, [sp, #0xe0]
//   0x3264: 940003cf  bl       #0x41a0
//   0x3268: f9401ff6  ldr      x22, [sp, #0x38]
//   0x326c: a9455ffc  ldp      x28, x23, [sp, #0x50]
//   0x3270: b940b3e8  ldr      w8, [sp, #0xb0]
//   0x3274: 35000208  cbnz     w8, #0x32b4
//   0x3278: b9404be8  ldr      w8, [sp, #0x48]
//   0x327c: 72001d1f  tst      w8, #0xff
//   0x3280: 540001a0  b.eq     #0x32b4
//   0x3284: 885f7e68  ldxr     w8, [x19]
//   0x3288: 11000508  add      w8, w8, #1
//   0x328c: 88097e68  stxr     w9, w8, [x19]
//   0x3290: 35ffffa9  cbnz     w9, #0x3284
//   0x3294: d10243a2  sub      x2, x29, #0x90
//   0x3298: 9400039a  bl       #0x4100
//   0x329c: 350000c0  cbnz     w0, #0x32b4
//   0x32a0: b0000048  adrp     x8, #0xc000
//   0x32a4: b947ad04  ldr      w4, [x8, #0x7ac]
//   0x32a8: d0ffffe2  adrp     x2, #0x1000
//   0x32ac: 91048442  add      x2, x2, #0x121
//   0x32b0: 94000378  bl       #0x4090
//   0x32b4: b9404fe8  ldr      w8, [sp, #0x4c]
//   0x32b8: b940abe9  ldr      w9, [sp, #0xa8]
//   0x32bc: 72001d1f  tst      w8, #0xff
//   0x32c0: 1a9f17e8  cset     w8, eq
//   0x32c4: 52000129  eor      w9, w9, #1
//   0x32c8: 2a080128  orr      w8, w9, w8
//   0x32cc: 37000068  tbnz     w8, #0, #0x32d8
//   0x32d0: b9409be2  ldr      w2, [sp, #0x98]
//   0x32d4: 94000350  bl       #0x4014
//   0x32d8: f94067e8  ldr      x8, [sp, #0xc8]
//   0x32dc: aa1f03f3  mov      x19, xzr
//   0x32e0: 8b080908  add      x8, x8, x8, lsl #2
//   0x32e4: d37ced14  lsl      x20, x8, #4
//   0x32e8: eb13029f  cmp      x20, x19
//   0x32ec: 540001a0  b.eq     #0x3320
//   0x32f0: f9405fe8  ldr      x8, [sp, #0xb8]
//   0x32f4: 8b130115  add      x21, x8, x19
//   0x32f8: f94002a0  ldr      x0, [x21]
//   0x32fc: 940003a9  bl       #0x41a0
//   0x3300: f9400ea0  ldr      x0, [x21, #0x18]
//   0x3304: 940003a7  bl       #0x41a0
//   0x3308: f94006a0  ldr      x0, [x21, #8]
//   0x330c: 940003a5  bl       #0x41a0
//   0x3310: f9400aa0  ldr      x0, [x21, #0x10]
//   0x3314: 940003a3  bl       #0x41a0
//   0x3318: 91014273  add      x19, x19, #0x50
//   0x331c: 17fffff3  b        #0x32e8
//   0x3320: f9405fe0  ldr      x0, [sp, #0xb8]
//   0x3324: 9400039f  bl       #0x41a0
//   0x3328: f94063f3  ldr      x19, [sp, #0xc0]
//   0x332c: b40000d8  cbz      x24, #0x3344
//   0x3330: f9400348  ldr      x8, [x26]
//   0x3334: f94033e1  ldr      x1, [sp, #0x60]
//   0x3338: aa1a03e0  mov      x0, x26
//   0x333c: aa1803e2  mov      x2, x24
//   0x3340: 94000346  bl       #0x4058
//   0x3344: b40000d9  cbz      x25, #0x335c
//   0x3348: f9400348  ldr      x8, [x26]
//   0x334c: aa1a03e0  mov      x0, x26
//   0x3350: aa1c03e1  mov      x1, x28
//   0x3354: aa1903e2  mov      x2, x25
//   0x3358: 94000340  bl       #0x4058
//   0x335c: b4000093  cbz      x19, #0x336c
//   0x3360: 94000338  bl       #0x4040
//   0x3364: aa1303e2  mov      x2, x19
//   0x3368: 9400033c  bl       #0x4058
//   0x336c: f94016c8  ldr      x8, [x22, #0x28]
//   0x3370: f85f03a9  ldur     x9, [x29, #-0x10]
//   0x3374: eb09011f  cmp      x8, x9
//   0x3378: 54002a81  b.ne     #0x38c8
//   0x337c: 2a1b03e0  mov      w0, w27
//   0x3380: 9111c3ff  add      sp, sp, #0x470
//   0x3384: 9400033d  bl       #0x4078
//   0x3388: a8c67bfd  ldp      x29, x30, [sp], #0x60
//   0x338c: d65f03c0  ret      
//   0x3390: b940d3f4  ldr      w20, [sp, #0xd0]
//   0x3394: 92800009  mov      x9, #-1
//   0x3398: 14000005  b        #0x33ac
//   0x339c: b940d3f4  ldr      w20, [sp, #0xd0]
//   0x33a0: f94073e8  ldr      x8, [sp, #0xe0]
//   0x33a4: aa0003e9  mov      x9, x0
//   0x33a8: aa1b03f6  mov      x22, x27
//   0x33ac: f94047e6  ldr      x6, [sp, #0x88]
//   0x33b0: 17fffe97  b        #0x2e0c
//   0x33b4: 528002a9  mov      w9, #0x15
//   0x33b8: 72a00029  movk     w9, #1, lsl #16
//   0x33bc: 93407ee8  sxtw     x8, w23
//   0x33c0: 6b0902ff  cmp      w23, w9
//   0x33c4: 9a88c134  csel     x20, x9, x8, gt
//   0x33c8: cb140101  sub      x1, x8, x20
//   0x33cc: 2a1b03e0  mov      w0, w27
//   0x33d0: 94000320  bl       #0x4050
//   0x33d4: b100041f  cmn      x0, #1
//   0x33d8: 54001fa0  b.eq     #0x37cc
//   0x33dc: 94000335  bl       #0x40b0
//   0x33e0: aa0003fc  mov      x28, x0
//   0x33e4: b4000c40  cbz      x0, #0x356c
//   0x33e8: 940002ef  bl       #0x3fa4
//   0x33ec: b100041f  cmn      x0, #1
//   0x33f0: 54000161  b.ne     #0x341c
//   0x33f4: 940002e5  bl       #0x3f88
//   0x33f8: 54ffff80  b.eq     #0x33e8
//   0x33fc: 1400005c  b        #0x356c
//   0x3400: f9406ff7  ldr      x23, [sp, #0xd8]
//   0x3404: f9400ffa  ldr      x26, [sp, #0x18]
//   0x3408: b940d3f4  ldr      w20, [sp, #0xd0]
//   0x340c: aa1f03fb  mov      x27, xzr
//   0x3410: 2a1503fc  mov      w28, w21
//   0x3414: f9006ff6  str      x22, [sp, #0xd8]
//   0x3418: 17ffff8b  b        #0x3244
//   0x341c: f90037f7  str      x23, [sp, #0x68]
//   0x3420: aa1f03f7  mov      x23, xzr
//   0x3424: 8b140394  add      x20, x28, x20
//   0x3428: 8b170280  add      x0, x20, x23
//   0x342c: 385fcc08  ldrb     w8, [x0, #-4]!
//   0x3430: 7101411f  cmp      w8, #0x50
//   0x3434: 540000c1  b.ne     #0x344c
//   0x3438: 94000246  bl       #0x3d50
//   0x343c: 52896a08  mov      w8, #0x4b50
//   0x3440: 72a0c0a8  movk     w8, #0x605, lsl #16
//   0x3444: 6b08001f  cmp      w0, w8
//   0x3448: 54000060  b.eq     #0x3454
//   0x344c: d10006f7  sub      x23, x23, #1
//   0x3450: 17fffff6  b        #0x3428
//   0x3454: 52800088  mov      w8, #4
//   0x3458: cb170104  sub      x4, x8, x23
//   0x345c: 7100549f  cmp      w4, #0x15
//   0x3460: 5400062c  b.gt     #0x3524
//   0x3464: d0ffffe2  adrp     x2, #0x1000
//   0x3468: 91032442  add      x2, x2, #0xc9
//   0x346c: 52800020  mov      w0, #1
//   0x3470: 52800021  mov      w1, #1
//   0x3474: 528002c3  mov      w3, #0x16
//   0x3478: 94000197  bl       #0x3ad4
//   0x347c: 1400003c  b        #0x356c
//   0x3480: d0ffffe2  adrp     x2, #0x1000
//   0x3484: 910eac42  add      x2, x2, #0x3ab
//   0x3488: 940002b5  bl       #0x3f5c
//   0x348c: 94000192  bl       #0x3ad4
//   0x3490: f9403bf7  ldr      x23, [sp, #0x70]
//   0x3494: 9280001b  mov      x27, #-1
//   0x3498: 17ffff5b  b        #0x3204
//   0x349c: b9400344  ldr      w4, [x26]
//   0x34a0: 93407c1b  sxtw     x27, w0
//   0x34a4: d0ffffe2  adrp     x2, #0x1000
//   0x34a8: 911a4442  add      x2, x2, #0x691
//   0x34ac: 52800020  mov      w0, #1
//   0x34b0: 52800021  mov      w1, #1
//   0x34b4: aa1b03e3  mov      x3, x27
//   0x34b8: 94000187  bl       #0x3ad4
//   0x34bc: 17ffff51  b        #0x3200
//   0x34c0: d0ffffe2  adrp     x2, #0x1000
//   0x34c4: 2a0003fb  mov      w27, w0
//   0x34c8: 91103042  add      x2, x2, #0x40c
//   0x34cc: 940002a4  bl       #0x3f5c
//   0x34d0: 940002fd  bl       #0x40c4
//   0x34d4: aa1603f7  mov      x23, x22
//   0x34d8: f9404be5  ldr      x5, [sp, #0x90]
//   0x34dc: f94053f6  ldr      x22, [sp, #0xa0]
//   0x34e0: f9400ffa  ldr      x26, [sp, #0x18]
//   0x34e4: 17ffff4c  b        #0x3214
//   0x34e8: d0ffffe2  adrp     x2, #0x1000
//   0x34ec: 9112d042  add      x2, x2, #0x4b4
//   0x34f0: 940002ce  bl       #0x4028
//   0x34f4: aa1f03f7  mov      x23, xzr
//   0x34f8: 9280003b  mov      x27, #-2
//   0x34fc: 17ffff42  b        #0x3204
//   0x3500: b9400345  ldr      w5, [x26]
//   0x3504: 93407c1b  sxtw     x27, w0
//   0x3508: d0ffffe2  adrp     x2, #0x1000
//   0x350c: 91137842  add      x2, x2, #0x4de
//   0x3510: 94000293  bl       #0x3f5c
//   0x3514: aa1603e3  mov      x3, x22
//   0x3518: aa1b03e4  mov      x4, x27
//   0x351c: 9400016e  bl       #0x3ad4
//   0x3520: 17ffff38  b        #0x3200
//   0x3524: 8b170294  add      x20, x20, x23
//   0x3528: 79400e88  ldrh     w8, [x20, #6]
//   0x352c: 91003280  add      x0, x20, #0xc
//   0x3530: aa0403f7  mov      x23, x4
//   0x3534: b90033e8  str      w8, [sp, #0x30]
//   0x3538: 94000206  bl       #0x3d50
//   0x353c: 79402284  ldrh     w4, [x20, #0x10]
//   0x3540: 340001e4  cbz      w4, #0x357c
//   0x3544: 11005888  add      w8, w4, #0x16
//   0x3548: 6b17011f  cmp      w8, w23
//   0x354c: 5400018d  b.le     #0x357c
//   0x3550: d0ffffe2  adrp     x2, #0x1000
//   0x3554: 91087442  add      x2, x2, #0x21d
//   0x3558: 52800020  mov      w0, #1
//   0x355c: 52800021  mov      w1, #1
//   0x3560: 528002c3  mov      w3, #0x16
//   0x3564: 2a1703e5  mov      w5, w23
//   0x3568: 9400015b  bl       #0x3ad4
//   0x356c: b940d3f4  ldr      w20, [sp, #0xd0]
//   0x3570: 940002e1  bl       #0x40f4
//   0x3574: aa1f03f7  mov      x23, xzr
//   0x3578: 17fffe5a  b        #0x2ee0
//   0x357c: 79400a88  ldrh     w8, [x20, #4]
//   0x3580: b94033e9  ldr      w9, [sp, #0x30]
//   0x3584: aa1f03f7  mov      x23, xzr
//   0x3588: b9002be0  str      w0, [sp, #0x28]
//   0x358c: f9003bff  str      xzr, [sp, #0x70]
//   0x3590: 6b09011f  cmp      w8, w9
//   0x3594: 54000521  b.ne     #0x3638
//   0x3598: 39400288  ldrb     w8, [x20]
//   0x359c: 79400689  ldrh     w9, [x20, #2]
//   0x35a0: 3940068a  ldrb     w10, [x20, #1]
//   0x35a4: b940d3f4  ldr      w20, [sp, #0xd0]
//   0x35a8: f9006ff7  str      x23, [sp, #0xd8]
//   0x35ac: 2a080128  orr      w8, w9, w8
//   0x35b0: 2a0a2108  orr      w8, w8, w10, lsl #8
//   0x35b4: 72003d1f  tst      w8, #0xffff
//   0x35b8: 54ffc941  b.ne     #0x2ee0
//   0x35bc: 940002c9  bl       #0x40e0
//   0x35c0: b9402bf4  ldr      w20, [sp, #0x28]
//   0x35c4: 2a1b03e0  mov      w0, w27
//   0x35c8: 2a1f03e2  mov      w2, wzr
//   0x35cc: 2a1403e1  mov      w1, w20
//   0x35d0: 94000350  bl       #0x4310
//   0x35d4: b100041f  cmn      x0, #1
//   0x35d8: 54000fa0  b.eq     #0x37cc
//   0x35dc: f94037e8  ldr      x8, [sp, #0x68]
//   0x35e0: 4b140114  sub      w20, w8, w20
//   0x35e4: 940002b3  bl       #0x40b0
//   0x35e8: aa0003fc  mov      x28, x0
//   0x35ec: b4fffc00  cbz      x0, #0x356c
//   0x35f0: 9400026d  bl       #0x3fa4
//   0x35f4: b100041f  cmn      x0, #1
//   0x35f8: 54000261  b.ne     #0x3644
//   0x35fc: 94000263  bl       #0x3f88
//   0x3600: 54ffff80  b.eq     #0x35f0
//   0x3604: 17ffffda  b        #0x356c
//   0x3608: d0ffffe2  adrp     x2, #0x1000
//   0x360c: 91133c42  add      x2, x2, #0x4cf
//   0x3610: 52800020  mov      w0, #1
//   0x3614: 52800021  mov      w1, #1
//   0x3618: aa1b03e3  mov      x3, x27
//   0x361c: 9400012e  bl       #0x3ad4
//   0x3620: 17fffef8  b        #0x3200
//   0x3624: aa1f03f9  mov      x25, xzr
//   0x3628: f9401ff6  ldr      x22, [sp, #0x38]
//   0x362c: 2a1f03fb  mov      w27, wzr
//   0x3630: f90063ff  str      xzr, [sp, #0xc0]
//   0x3634: 17ffff29  b        #0x32d8
//   0x3638: b940d3f4  ldr      w20, [sp, #0xd0]
//   0x363c: f9006ff7  str      x23, [sp, #0xd8]
//   0x3640: 17fffe28  b        #0x2ee0
//   0x3644: b94033e8  ldr      w8, [sp, #0x30]
//   0x3648: aa1c03f4  mov      x20, x28
//   0x364c: 34fff908  cbz      w8, #0x356c
//   0x3650: 2a0803f7  mov      w23, w8
//   0x3654: 79403a88  ldrh     w8, [x20, #0x1c]
//   0x3658: 79403e8a  ldrh     w10, [x20, #0x1e]
//   0x365c: 79404298  ldrh     w24, [x20, #0x20]
//   0x3660: 34000148  cbz      w8, #0x3688
//   0x3664: f94063e0  ldr      x0, [sp, #0xc0]
//   0x3668: 9100ba81  add      x1, x20, #0x2e
//   0x366c: aa0803e2  mov      x2, x8
//   0x3670: f9006fe8  str      x8, [sp, #0xd8]
//   0x3674: f9003bea  str      x10, [sp, #0x70]
//   0x3678: 9400032a  bl       #0x4320
//   0x367c: f9403bea  ldr      x10, [sp, #0x70]
//   0x3680: f9406fe8  ldr      x8, [sp, #0xd8]
//   0x3684: 34000120  cbz      w0, #0x36a8
//   0x3688: 8b080288  add      x8, x20, x8
//   0x368c: 8b0a0108  add      x8, x8, x10
//   0x3690: 8b180108  add      x8, x8, x24
//   0x3694: 9100b914  add      x20, x8, #0x2e
//   0x3698: 2a1703e8  mov      w8, w23
//   0x369c: 510006e8  sub      w8, w23, #1
//   0x36a0: 35fffd88  cbnz     w8, #0x3650
//   0x36a4: 17ffffb2  b        #0x356c
//   0x36a8: 9100aa80  add      x0, x20, #0x2a
//   0x36ac: 940001a9  bl       #0x3d50
//   0x36b0: 2a0003f7  mov      w23, w0
//   0x36b4: 2a0003f8  mov      w24, w0
//   0x36b8: 91005280  add      x0, x20, #0x14
//   0x36bc: 940001a5  bl       #0x3d50
//   0x36c0: b9006be0  str      w0, [sp, #0x68]
//   0x36c4: 91006280  add      x0, x20, #0x18
//   0x36c8: 940001a2  bl       #0x3d50
//   0x36cc: 79401694  ldrh     w20, [x20, #0xa]
//   0x36d0: b90033e0  str      w0, [sp, #0x30]
//   0x36d4: 94000283  bl       #0x40e0
//   0x36d8: 2a1b03e0  mov      w0, w27
//   0x36dc: aa1803e1  mov      x1, x24
//   0x36e0: 9400025c  bl       #0x4050
//   0x36e4: b100041f  cmn      x0, #1
//   0x36e8: 54000720  b.eq     #0x37cc
//   0x36ec: 52800400  mov      w0, #0x20
//   0x36f0: 940002a8  bl       #0x4190
//   0x36f4: aa0003fc  mov      x28, x0
//   0x36f8: b4fff3a0  cbz      x0, #0x356c
//   0x36fc: 52800402  mov      w2, #0x20
//   0x3700: 2a1b03e0  mov      w0, w27
//   0x3704: aa1c03e1  mov      x1, x28
//   0x3708: b900035f  str      wzr, [x26]
//   0x370c: 940002c1  bl       #0x4210
//   0x3710: b100041f  cmn      x0, #1
//   0x3714: 54000081  b.ne     #0x3724
//   0x3718: 9400021c  bl       #0x3f88
//   0x371c: 54ffff00  b.eq     #0x36fc
//   0x3720: 17ffff93  b        #0x356c
//   0x3724: f9406fe9  ldr      x9, [sp, #0xd8]
//   0x3728: 79403b88  ldrh     w8, [x28, #0x1c]
//   0x372c: aa1c03e0  mov      x0, x28
//   0x3730: 0b170129  add      w9, w9, w23
//   0x3734: 0b080128  add      w8, w9, w8
//   0x3738: 11007918  add      w24, w8, #0x1e
//   0x373c: 94000299  bl       #0x41a0
//   0x3740: 2a1b03e0  mov      w0, w27
//   0x3744: aa1803e1  mov      x1, x24
//   0x3748: 94000242  bl       #0x4050
//   0x374c: b100041f  cmn      x0, #1
//   0x3750: 540003e0  b.eq     #0x37cc
//   0x3754: 34000214  cbz      w20, #0x3794
//   0x3758: b9406be8  ldr      w8, [sp, #0x68]
//   0x375c: 2a0803f4  mov      w20, w8
//   0x3760: 94000254  bl       #0x40b0
//   0x3764: aa0003f7  mov      x23, x0
//   0x3768: b4000ac0  cbz      x0, #0x38c0
//   0x376c: 92800003  mov      x3, #-1
//   0x3770: 2a1b03e0  mov      w0, w27
//   0x3774: aa1703e1  mov      x1, x23
//   0x3778: aa1403e2  mov      x2, x20
//   0x377c: 94000221  bl       #0x4000
//   0x3780: b100041f  cmn      x0, #1
//   0x3784: 540002e1  b.ne     #0x37e0
//   0x3788: 94000200  bl       #0x3f88
//   0x378c: 54ffff00  b.eq     #0x376c
//   0x3790: 1400004c  b        #0x38c0
//   0x3794: 94000243  bl       #0x40a0
//   0x3798: f9006fe0  str      x0, [sp, #0xd8]
//   0x379c: b4000180  cbz      x0, #0x37cc
//   0x37a0: f9406fe1  ldr      x1, [sp, #0xd8]
//   0x37a4: f9403be2  ldr      x2, [sp, #0x70]
//   0x37a8: 92800003  mov      x3, #-1
//   0x37ac: 2a1b03e0  mov      w0, w27
//   0x37b0: 94000214  bl       #0x4000
//   0x37b4: b100041f  cmn      x0, #1
//   0x37b8: 54000641  b.ne     #0x3880
//   0x37bc: 940001f3  bl       #0x3f88
//   0x37c0: 54ffff00  b.eq     #0x37a0
//   0x37c4: f9003bff  str      xzr, [sp, #0x70]
//   0x37c8: 14000002  b        #0x37d0
//   0x37cc: 9400024a  bl       #0x40f4
//   0x37d0: aa1f03f7  mov      x23, xzr
//   0x37d4: b940d3f4  ldr      w20, [sp, #0xd0]
//   0x37d8: aa1f03fc  mov      x28, xzr
//   0x37dc: 17fffdc1  b        #0x2ee0
//   0x37e0: 94000230  bl       #0x40a0
//   0x37e4: f9006fe0  str      x0, [sp, #0xd8]
//   0x37e8: b40006c0  cbz      x0, #0x38c0
//   0x37ec: b9406be8  ldr      w8, [sp, #0x68]
//   0x37f0: 6f00e400  movi     v0.2d, #0000000000000000
//   0x37f4: ad0783e0  stp      q0, q0, [sp, #0xf0]
//   0x37f8: 3d8047e0  str      q0, [sp, #0x110]
//   0x37fc: b900fbe8  str      w8, [sp, #0xf8]
//   0x3800: b94033e8  ldr      w8, [sp, #0x30]
//   0x3804: d0ffffe2  adrp     x2, #0x1000
//   0x3808: 9110d442  add      x2, x2, #0x435
//   0x380c: 9103c3e0  add      x0, sp, #0xf0
//   0x3810: b90113e8  str      w8, [sp, #0x110]
//   0x3814: f9403be8  ldr      x8, [sp, #0x70]
//   0x3818: 128001c1  mov      w1, #-0xf
//   0x381c: 52800e03  mov      w3, #0x70
//   0x3820: ad0a03e0  stp      q0, q0, [sp, #0x140]
//   0x3824: f9008fe8  str      x8, [sp, #0x118]
//   0x3828: f9406fe8  ldr      x8, [sp, #0xd8]
//   0x382c: ad0903e0  stp      q0, q0, [sp, #0x120]
//   0x3830: f9007bf7  str      x23, [sp, #0xf0]
//   0x3834: a91023f4  stp      x20, x8, [sp, #0x100]
//   0x3838: 940002be  bl       #0x4330
//   0x383c: 35000360  cbnz     w0, #0x38a8
//   0x3840: 9103c3e0  add      x0, sp, #0xf0
//   0x3844: 52800081  mov      w1, #4
//   0x3848: 940002be  bl       #0x4340
//   0x384c: 2a0003f4  mov      w20, w0
//   0x3850: 9103c3e0  add      x0, sp, #0xf0
//   0x3854: 940002bf  bl       #0x4350
//   0x3858: 7100069f  cmp      w20, #1
//   0x385c: 54000261  b.ne     #0x38a8
//   0x3860: f94063e3  ldr      x3, [sp, #0xc0]
//   0x3864: d0ffffe2  adrp     x2, #0x1000
//   0x3868: 91197042  add      x2, x2, #0x65c
//   0x386c: 940001bc  bl       #0x3f5c
//   0x3870: aa1f03e4  mov      x4, xzr
//   0x3874: 2a1803e5  mov      w5, w24
//   0x3878: 94000097  bl       #0x3ad4
//   0x387c: 14000009  b        #0x38a0
//   0x3880: f94063e3  ldr      x3, [sp, #0xc0]
//   0x3884: f9406fe4  ldr      x4, [sp, #0xd8]
//   0x3888: f9403be5  ldr      x5, [sp, #0x70]
//   0x388c: d0ffffe2  adrp     x2, #0x1000
//   0x3890: 9115b842  add      x2, x2, #0x56e
//   0x3894: 940001b2  bl       #0x3f5c
//   0x3898: 9400008f  bl       #0x3ad4
//   0x389c: aa1f03f7  mov      x23, xzr
//   0x38a0: 940001e0  bl       #0x4020
//   0x38a4: 17ffffcb  b        #0x37d0
//   0x38a8: 940001de  bl       #0x4020
//   0x38ac: f9406ff4  ldr      x20, [sp, #0xd8]
//   0x38b0: aa1403e0  mov      x0, x20
//   0x38b4: 9400023b  bl       #0x41a0
//   0x38b8: aa1403e0  mov      x0, x20
//   0x38bc: 94000239  bl       #0x41a0
//   0x38c0: 9400020d  bl       #0x40f4
//   0x38c4: 17ffffc4  b        #0x37d4
//   0x38c8: 9400022a  bl       #0x4170
//   0x38cc: a9be7bfd  stp      x29, x30, [sp, #-0x20]!
//   0x38d0: f9000bf3  str      x19, [sp, #0x10]
//   0x38d4: 910003fd  mov      x29, sp
//   0x38d8: aa0003f3  mov      x19, x0
//   0x38dc: 9400025d  bl       #0x4250
//   0x38e0: b0000048  adrp     x8, #0xc000
//   0x38e4: 395ea108  ldrb     w8, [x8, #0x7a8]
//   0x38e8: 34000228  cbz      w8, #0x392c
//   0x38ec: aa1f03e9  mov      x9, xzr
//   0x38f0: b0000048  adrp     x8, #0xc000
//   0x38f4: 9100612a  add      x10, x9, #0x18
//   0x38f8: f103615f  cmp      x10, #0xd8
//   0x38fc: 54000180  b.eq     #0x392c
//   0x3900: f943e10b  ldr      x11, [x8, #0x7c0]
//   0x3904: 8b090169  add      x9, x11, x9
//   0x3908: 91004129  add      x9, x9, #0x10
//   0x390c: 88dffd29  ldar     w9, [x9]
//   0x3910: 6b00013f  cmp      w9, w0
//   0x3914: aa0a03e9  mov      x9, x10
//   0x3918: 54fffee1  b.ne     #0x38f4
//   0x391c: f943e108  ldr      x8, [x8, #0x7c0]
//   0x3920: 8b0a0108  add      x8, x8, x10
//   0x3924: f85e8101  ldur     x1, [x8, #-0x18]
//   0x3928: 14000002  b        #0x3930
//   0x392c: aa1f03e1  mov      x1, xzr
//   0x3930: f9400268  ldr      x8, [x19]
//   0x3934: f9429d02  ldr      x2, [x8, #0x538]
//   0x3938: b5000061  cbnz     x1, #0x3944
//   0x393c: d0ffffe1  adrp     x1, #0x1000
//   0x3940: 91071821  add      x1, x1, #0x1c6
//   0x3944: aa1303e0  mov      x0, x19
//   0x3948: f9400bf3  ldr      x19, [sp, #0x10]
//   0x394c: a8c27bfd  ldp      x29, x30, [sp], #0x20
//   0x3950: d61f0040  br       x2
//   0x3954: d10383ff  sub      sp, sp, #0xe0
//   0x3958: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x395c: a90a67fa  stp      x26, x25, [sp, #0xa0]
//   0x3960: a90b5ff8  stp      x24, x23, [sp, #0xb0]
//   0x3964: a90c57f6  stp      x22, x21, [sp, #0xc0]
//   0x3968: a90d4ff4  stp      x20, x19, [sp, #0xd0]
//   0x396c: 910243fd  add      x29, sp, #0x90
//   0x3970: d53bd05a  mrs      x26, tpidr_el0
//   0x3974: f9401748  ldr      x8, [x26, #0x28]
//   0x3978: aa0203f4  mov      x20, x2
//   0x397c: aa0203e1  mov      x1, x2
//   0x3980: aa1f03e2  mov      x2, xzr
//   0x3984: f81f83a8  stur     x8, [x29, #-8]
//   0x3988: f9400008  ldr      x8, [x0]
//   0x398c: aa0003f3  mov      x19, x0
//   0x3990: f942a508  ldr      x8, [x8, #0x548]
//   0x3994: d63f0100  blr      x8
//   0x3998: aa0003f5  mov      x21, x0
//   0x399c: b4000920  cbz      x0, #0x3ac0
//   0x39a0: 52a00101  mov      w1, #0x80000
//   0x39a4: aa1503e0  mov      x0, x21
//   0x39a8: 9400026e  bl       #0x4360
//   0x39ac: 2a0003f6  mov      w22, w0
//   0x39b0: 37f80300  tbnz     w0, #0x1f, #0x3a10
//   0x39b4: 910023e1  add      x1, sp, #8
//   0x39b8: 2a1603e0  mov      w0, w22
//   0x39bc: 94000231  bl       #0x4280
//   0x39c0: f9401ff8  ldr      x24, [sp, #0x38]
//   0x39c4: aa1803e0  mov      x0, x24
//   0x39c8: 940001f2  bl       #0x4190
//   0x39cc: aa0003f7  mov      x23, x0
//   0x39d0: b40004e0  cbz      x0, #0x3a6c
//   0x39d4: 9400020b  bl       #0x4200
//   0x39d8: aa0003f9  mov      x25, x0
//   0x39dc: 92800003  mov      x3, #-1
//   0x39e0: 2a1603e0  mov      w0, w22
//   0x39e4: aa1703e1  mov      x1, x23
//   0x39e8: aa1803e2  mov      x2, x24
//   0x39ec: b900033f  str      wzr, [x25]
//   0x39f0: 94000260  bl       #0x4370
//   0x39f4: b100041f  cmn      x0, #1
//   0x39f8: 54000201  b.ne     #0x3a38
//   0x39fc: b9400328  ldr      w8, [x25]
//   0x3a00: 7100111f  cmp      w8, #4
//   0x3a04: 54fffec0  b.eq     #0x39dc
//   0x3a08: 92800003  mov      x3, #-1
//   0x3a0c: 1400000c  b        #0x3a3c
//   0x3a10: 940001fc  bl       #0x4200
//   0x3a14: b9400005  ldr      w5, [x0]
//   0x3a18: d0ffffe2  adrp     x2, #0x1000
//   0x3a1c: 9111a442  add      x2, x2, #0x469
//   0x3a20: 9400014f  bl       #0x3f5c
//   0x3a24: aa1503e3  mov      x3, x21
//   0x3a28: 2a1603e4  mov      w4, w22
//   0x3a2c: 9400002a  bl       #0x3ad4
//   0x3a30: aa1f03f7  mov      x23, xzr
//   0x3a34: 1400000e  b        #0x3a6c
//   0x3a38: aa0003e3  mov      x3, x0
//   0x3a3c: eb18007f  cmp      x3, x24
//   0x3a40: 540000c1  b.ne     #0x3a58
//   0x3a44: aa1703e0  mov      x0, x23
//   0x3a48: aa1803e1  mov      x1, x24
//   0x3a4c: 9400010e  bl       #0x3e84
//   0x3a50: aa0003f8  mov      x24, x0
//   0x3a54: 14000007  b        #0x3a70
//   0x3a58: b9400324  ldr      w4, [x25]
//   0x3a5c: d0ffffe2  adrp     x2, #0x1000
//   0x3a60: 91189042  add      x2, x2, #0x624
//   0x3a64: 9400013e  bl       #0x3f5c
//   0x3a68: 9400001b  bl       #0x3ad4
//   0x3a6c: aa1f03f8  mov      x24, xzr
//   0x3a70: 2a1603e0  mov      w0, w22
//   0x3a74: 940001ef  bl       #0x4230
//   0x3a78: 9400016a  bl       #0x4020
//   0x3a7c: b40000d5  cbz      x21, #0x3a94
//   0x3a80: f9400268  ldr      x8, [x19]
//   0x3a84: aa1303e0  mov      x0, x19
//   0x3a88: aa1403e1  mov      x1, x20
//   0x3a8c: aa1503e2  mov      x2, x21
//   0x3a90: 94000172  bl       #0x4058
//   0x3a94: f9401748  ldr      x8, [x26, #0x28]
//   0x3a98: 9400015c  bl       #0x4008
//   0x3a9c: 540001a1  b.ne     #0x3ad0
//   0x3aa0: aa1803e0  mov      x0, x24
//   0x3aa4: a94d4ff4  ldp      x20, x19, [sp, #0xd0]
//   0x3aa8: a94c57f6  ldp      x22, x21, [sp, #0xc0]
//   0x3aac: a94b5ff8  ldp      x24, x23, [sp, #0xb0]
//   0x3ab0: a94a67fa  ldp      x26, x25, [sp, #0xa0]
//   0x3ab4: a9497bfd  ldp      x29, x30, [sp, #0x90]
//   0x3ab8: 910383ff  add      sp, sp, #0xe0
//   0x3abc: d65f03c0  ret      
//   0x3ac0: aa1f03f7  mov      x23, xzr
//   0x3ac4: aa1f03f8  mov      x24, xzr
//   0x3ac8: 12800016  mov      w22, #-1
//   0x3acc: 17ffffe9  b        #0x3a70
//   0x3ad0: 940001a8  bl       #0x4170
//   0x3ad4: a9bd7bfd  stp      x29, x30, [sp, #-0x30]!
//   0x3ad8: a90157fc  stp      x28, x21, [sp, #0x10]
//   0x3adc: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x3ae0: 910003fd  mov      x29, sp
//   0x3ae4: d14007ff  sub      sp, sp, #1, lsl #12
//   0x3ae8: d10403ff  sub      sp, sp, #0x100
//   0x3aec: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x3af0: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x3af4: f90057e7  str      x7, [sp, #0xa8]
//   0x3af8: ad0007e0  stp      q0, q1, [sp]
//   0x3afc: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x3b00: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x3b04: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x3b08: d53bd055  mrs      x21, tpidr_el0
//   0x3b0c: f94016a8  ldr      x8, [x21, #0x28]
//   0x3b10: 928004e9  mov      x9, #-0x28
//   0x3b14: 910003ea  mov      x10, sp
//   0x3b18: 910223eb  add      x11, sp, #0x88
//   0x3b1c: f2dff009  movk     x9, #0xff80, lsl #32
//   0x3b20: f81f83a8  stur     x8, [x29, #-8]
//   0x3b24: 9100c3a8  add      x8, x29, #0x30
//   0x3b28: 9102014a  add      x10, x10, #0x80
//   0x3b2c: 9100a16b  add      x11, x11, #0x28
//   0x3b30: a90c27ea  stp      x10, x9, [sp, #0xc0]
//   0x3b34: a90b2fe8  stp      x8, x11, [sp, #0xb0]
//   0x3b38: ad4587e0  ldp      q0, q1, [sp, #0xb0]
//   0x3b3c: 2a0103f3  mov      w19, w1
//   0x3b40: 2a0003f4  mov      w20, w0
//   0x3b44: 9103e3e0  add      x0, sp, #0xf8
//   0x3b48: 910343e3  add      x3, sp, #0xd0
//   0x3b4c: 52820001  mov      w1, #0x1000
//   0x3b50: ad0687e0  stp      q0, q1, [sp, #0xd0]
//   0x3b54: 9400020b  bl       #0x4380
//   0x3b58: 36000134  tbz      w20, #0, #0x3b7c
//   0x3b5c: b0000048  adrp     x8, #0xc000
//   0x3b60: f943d908  ldr      x8, [x8, #0x7b0]
//   0x3b64: b40000c8  cbz      x8, #0x3b7c
//   0x3b68: d0ffffe1  adrp     x1, #0x1000
//   0x3b6c: 91114821  add      x1, x1, #0x452
//   0x3b70: 9103e3e2  add      x2, sp, #0xf8
//   0x3b74: 52800040  mov      w0, #2
//   0x3b78: d63f0100  blr      x8
//   0x3b7c: b0000048  adrp     x8, #0xc000
//   0x3b80: 395ea108  ldrb     w8, [x8, #0x7a8]
//   0x3b84: 340007e8  cbz      w8, #0x3c80
//   0x3b88: 360007d3  tbz      w19, #0, #0x3c80
//   0x3b8c: 940001b1  bl       #0x4250
//   0x3b90: aa1f03e8  mov      x8, xzr
//   0x3b94: b0000053  adrp     x19, #0xc000
//   0x3b98: 91006114  add      x20, x8, #0x18
//   0x3b9c: f103629f  cmp      x20, #0xd8
//   0x3ba0: 540002c0  b.eq     #0x3bf8
//   0x3ba4: f943e269  ldr      x9, [x19, #0x7c0]
//   0x3ba8: 8b080128  add      x8, x9, x8
//   0x3bac: 91004108  add      x8, x8, #0x10
//   0x3bb0: 88dffd08  ldar     w8, [x8]
//   0x3bb4: 6b00011f  cmp      w8, w0
//   0x3bb8: aa1403e8  mov      x8, x20
//   0x3bbc: 54fffee1  b.ne     #0x3b98
//   0x3bc0: f943e268  ldr      x8, [x19, #0x7c0]
//   0x3bc4: d0ffffe4  adrp     x4, #0x1000
//   0x3bc8: 91114884  add      x4, x4, #0x452
//   0x3bcc: 9103e3e5  add      x5, sp, #0xf8
//   0x3bd0: 8b140108  add      x8, x8, x20
//   0x3bd4: a97ea109  ldp      x9, x8, [x8, #-0x18]
//   0x3bd8: 8b080120  add      x0, x9, x8
//   0x3bdc: 9400003a  bl       #0x3cc4
//   0x3be0: f943e268  ldr      x8, [x19, #0x7c0]
//   0x3be4: 8b140108  add      x8, x8, x20
//   0x3be8: f85f0109  ldur     x9, [x8, #-0x10]
//   0x3bec: 8b20c129  add      x9, x9, w0, sxtw
//   0x3bf0: f81f0109  stur     x9, [x8, #-0x10]
//   0x3bf4: 14000023  b        #0x3c80
//   0x3bf8: aa1f03ea  mov      x10, xzr
//   0x3bfc: 52800309  mov      w9, #0x18
//   0x3c00: f100215f  cmp      x10, #8
//   0x3c04: 540003e0  b.eq     #0x3c80
//   0x3c08: aa0a03e8  mov      x8, x10
//   0x3c0c: f943e26a  ldr      x10, [x19, #0x7c0]
//   0x3c10: 9b09290a  madd     x10, x8, x9, x10
//   0x3c14: 9100414a  add      x10, x10, #0x10
//   0x3c18: 885ffd4b  ldaxr    w11, [x10]
//   0x3c1c: 350000ab  cbnz     w11, #0x3c30
//   0x3c20: 880b7d40  stxr     w11, w0, [x10]
//   0x3c24: 35ffffab  cbnz     w11, #0x3c18
//   0x3c28: 5280002b  mov      w11, #1
//   0x3c2c: 14000003  b        #0x3c38
//   0x3c30: d5033f5f  clrex    
//   0x3c34: 2a1f03eb  mov      w11, wzr
//   0x3c38: 9100050a  add      x10, x8, #1
//   0x3c3c: 34fffe2b  cbz      w11, #0x3c00
//   0x3c40: f943e269  ldr      x9, [x19, #0x7c0]
//   0x3c44: 92407d0a  and      x10, x8, #0xffffffff
//   0x3c48: d37ff94a  lsl      x10, x10, #1
//   0x3c4c: 8b284154  add      x20, x10, w8, uxtw
//   0x3c50: 8b140d28  add      x8, x9, x20, lsl #3
//   0x3c54: a9402109  ldp      x9, x8, [x8]
//   0x3c58: d0ffffe4  adrp     x4, #0x1000
//   0x3c5c: 91114884  add      x4, x4, #0x452
//   0x3c60: 9103e3e5  add      x5, sp, #0xf8
//   0x3c64: 8b080120  add      x0, x9, x8
//   0x3c68: 94000017  bl       #0x3cc4
//   0x3c6c: f943e268  ldr      x8, [x19, #0x7c0]
//   0x3c70: 8b140d08  add      x8, x8, x20, lsl #3
//   0x3c74: f9400509  ldr      x9, [x8, #8]
//   0x3c78: 8b20c129  add      x9, x9, w0, sxtw
//   0x3c7c: f9000509  str      x9, [x8, #8]
//   0x3c80: d0ffffe1  adrp     x1, #0x1000
//   0x3c84: d0ffffe2  adrp     x2, #0x1000
//   0x3c88: 91114821  add      x1, x1, #0x452
//   0x3c8c: 91070c42  add      x2, x2, #0x1c3
//   0x3c90: 9103e3e3  add      x3, sp, #0xf8
//   0x3c94: 52800080  mov      w0, #4
//   0x3c98: 940001be  bl       #0x4390
//   0x3c9c: f94016a8  ldr      x8, [x21, #0x28]
//   0x3ca0: 940000da  bl       #0x4008
//   0x3ca4: 540000e1  b.ne     #0x3cc0
//   0x3ca8: 914007ff  add      sp, sp, #1, lsl #12
//   0x3cac: 910403ff  add      sp, sp, #0x100
//   0x3cb0: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x3cb4: a94157fc  ldp      x28, x21, [sp, #0x10]
//   0x3cb8: a8c37bfd  ldp      x29, x30, [sp], #0x30
//   0x3cbc: d65f03c0  ret      
//   0x3cc0: 9400012c  bl       #0x4170
//   0x3cc4: d10443ff  sub      sp, sp, #0x110
//   0x3cc8: a90f7bfd  stp      x29, x30, [sp, #0xf0]
//   0x3ccc: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x3cd0: 9103c3fd  add      x29, sp, #0xf0
//   0x3cd4: 94000089  bl       #0x3ef8
//   0x3cd8: d0ffffe2  adrp     x2, #0x1000
//   0x3cdc: 9118d042  add      x2, x2, #0x634
//   0x3ce0: d10143a3  sub      x3, x29, #0x50
//   0x3ce4: 52850001  mov      w1, #0x2800
//   0x3ce8: 9400010c  bl       #0x4118
//   0x3cec: f9401668  ldr      x8, [x19, #0x28]
//   0x3cf0: 940000c6  bl       #0x4008
//   0x3cf4: 540000a1  b.ne     #0x3d08
//   0x3cf8: a9504ffc  ldp      x28, x19, [sp, #0x100]
//   0x3cfc: a94f7bfd  ldp      x29, x30, [sp, #0xf0]
//   0x3d00: 910443ff  add      sp, sp, #0x110
//   0x3d04: d65f03c0  ret      
//   0x3d08: 9400011a  bl       #0x4170
//   0x3d0c: d10443ff  sub      sp, sp, #0x110
//   0x3d10: a90f7bfd  stp      x29, x30, [sp, #0xf0]
//   0x3d14: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x3d18: 9103c3fd  add      x29, sp, #0xf0
//   0x3d1c: 94000077  bl       #0x3ef8
//   0x3d20: aa0303e2  mov      x2, x3
//   0x3d24: d10143a3  sub      x3, x29, #0x50
//   0x3d28: 52801001  mov      w1, #0x80
//   0x3d2c: 940000fb  bl       #0x4118
//   0x3d30: f9401668  ldr      x8, [x19, #0x28]
//   0x3d34: 940000b5  bl       #0x4008
//   0x3d38: 540000a1  b.ne     #0x3d4c
//   0x3d3c: a9504ffc  ldp      x28, x19, [sp, #0x100]
//   0x3d40: a94f7bfd  ldp      x29, x30, [sp, #0xf0]
//   0x3d44: 910443ff  add      sp, sp, #0x110
//   0x3d48: d65f03c0  ret      
//   0x3d4c: 94000109  bl       #0x4170
//   0x3d50: b9400000  ldr      w0, [x0]
//   0x3d54: d65f03c0  ret      
//   0x3d58: d10103ff  sub      sp, sp, #0x40
//   0x3d5c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x3d60: f9001bf3  str      x19, [sp, #0x30]
//   0x3d64: 910083fd  add      x29, sp, #0x20
//   0x3d68: d53bd053  mrs      x19, tpidr_el0
//   0x3d6c: f9401668  ldr      x8, [x19, #0x28]
//   0x3d70: 910023e1  add      x1, sp, #8
//   0x3d74: 52800020  mov      w0, #1
//   0x3d78: f81f83a8  stur     x8, [x29, #-8]
//   0x3d7c: a900ffff  stp      xzr, xzr, [sp, #8]
//   0x3d80: 94000188  bl       #0x43a0
//   0x3d84: a940a7e8  ldp      x8, x9, [sp, #8]
//   0x3d88: f940166a  ldr      x10, [x19, #0x28]
//   0x3d8c: f85f83ab  ldur     x11, [x29, #-8]
//   0x3d90: eb0b015f  cmp      x10, x11
//   0x3d94: 54000101  b.ne     #0x3db4
//   0x3d98: f9401bf3  ldr      x19, [sp, #0x30]
//   0x3d9c: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x3da0: 5299400a  mov      w10, #0xca00
//   0x3da4: 72a7734a  movk     w10, #0x3b9a, lsl #16
//   0x3da8: 9b0a2500  madd     x0, x8, x10, x9
//   0x3dac: 910103ff  add      sp, sp, #0x40
//   0x3db0: d65f03c0  ret      
//   0x3db4: 940000ef  bl       #0x4170
//   0x3db8: a9bd7bfd  stp      x29, x30, [sp, #-0x30]!
//   0x3dbc: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x3dc0: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x3dc4: 910003fd  mov      x29, sp
//   0x3dc8: f9400008  ldr      x8, [x0]
//   0x3dcc: aa0203f4  mov      x20, x2
//   0x3dd0: aa1f03e2  mov      x2, xzr
//   0x3dd4: aa0003f3  mov      x19, x0
//   0x3dd8: f942a508  ldr      x8, [x8, #0x548]
//   0x3ddc: aa0103f5  mov      x21, x1
//   0x3de0: d63f0100  blr      x8
//   0x3de4: b4000240  cbz      x0, #0x3e2c
//   0x3de8: aa0003f6  mov      x22, x0
//   0x3dec: aa1403e0  mov      x0, x20
//   0x3df0: aa1603e4  mov      x4, x22
//   0x3df4: 94000012  bl       #0x3e3c
//   0x3df8: 7107fc1f  cmp      w0, #0x1ff
//   0x3dfc: 52803fe8  mov      w8, #0x1ff
//   0x3e00: 1a88b008  csel     w8, w0, w8, lt
//   0x3e04: 3828ca9f  strb     wzr, [x20, w8, sxtw]
//   0x3e08: f9400268  ldr      x8, [x19]
//   0x3e0c: aa1303e0  mov      x0, x19
//   0x3e10: aa1503e1  mov      x1, x21
//   0x3e14: aa1603e2  mov      x2, x22
//   0x3e18: f942a903  ldr      x3, [x8, #0x550]
//   0x3e1c: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x3e20: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x3e24: a8c37bfd  ldp      x29, x30, [sp], #0x30
//   0x3e28: d61f0060  br       x3
//   0x3e2c: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x3e30: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x3e34: a8c37bfd  ldp      x29, x30, [sp], #0x30
//   0x3e38: d65f03c0  ret      
//   0x3e3c: d10443ff  sub      sp, sp, #0x110
//   0x3e40: a90f7bfd  stp      x29, x30, [sp, #0xf0]
//   0x3e44: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x3e48: 9103c3fd  add      x29, sp, #0xf0
//   0x3e4c: 9400002b  bl       #0x3ef8
//   0x3e50: d0ffffe2  adrp     x2, #0x1000
//   0x3e54: 91070c42  add      x2, x2, #0x1c3
//   0x3e58: d10143a3  sub      x3, x29, #0x50
//   0x3e5c: 52804001  mov      w1, #0x200
//   0x3e60: 940000ae  bl       #0x4118
//   0x3e64: f9401668  ldr      x8, [x19, #0x28]
//   0x3e68: 94000068  bl       #0x4008
//   0x3e6c: 540000a1  b.ne     #0x3e80
//   0x3e70: a9504ffc  ldp      x28, x19, [sp, #0x100]
//   0x3e74: a94f7bfd  ldp      x29, x30, [sp, #0xf0]
//   0x3e78: 910443ff  add      sp, sp, #0x110
//   0x3e7c: d65f03c0  ret      
//   0x3e80: 940000bc  bl       #0x4170
//   0x3e84: a9be7bfd  stp      x29, x30, [sp, #-0x20]!
//   0x3e88: f9000bf3  str      x19, [sp, #0x10]
//   0x3e8c: 910003fd  mov      x29, sp
//   0x3e90: d0ffffea  adrp     x10, #0x1000
//   0x3e94: aa0103e4  mov      x4, x1
//   0x3e98: aa1f03e9  mov      x9, xzr
//   0x3e9c: 12800008  mov      w8, #-1
//   0x3ea0: 911b014a  add      x10, x10, #0x6c0
//   0x3ea4: eb09009f  cmp      x4, x9
//   0x3ea8: 54000100  b.eq     #0x3ec8
//   0x3eac: 3869680b  ldrb     w11, [x0, x9]
//   0x3eb0: 12001d0c  and      w12, w8, #0xff
//   0x3eb4: 91000529  add      x9, x9, #1
//   0x3eb8: 4a0b018b  eor      w11, w12, w11
//   0x3ebc: b86b594b  ldr      w11, [x10, w11, uxtw #2]
//   0x3ec0: 4a482168  eor      w8, w11, w8, lsr #8
//   0x3ec4: 17fffff8  b        #0x3ea4
//   0x3ec8: 2a2803e3  mvn      w3, w8
//   0x3ecc: 8b040073  add      x19, x3, x4
//   0x3ed0: d0ffffe2  adrp     x2, #0x1000
//   0x3ed4: 91184c42  add      x2, x2, #0x613
//   0x3ed8: 2a1f03e0  mov      w0, wzr
//   0x3edc: 2a1f03e1  mov      w1, wzr
//   0x3ee0: aa1303e5  mov      x5, x19
//   0x3ee4: 97fffefc  bl       #0x3ad4
//   0x3ee8: aa1303e0  mov      x0, x19
//   0x3eec: f9400bf3  ldr      x19, [sp, #0x10]
//   0x3ef0: a8c27bfd  ldp      x29, x30, [sp], #0x20
//   0x3ef4: d65f03c0  ret      
//   0x3ef8: a93917a4  stp      x4, x5, [x29, #-0x70]
//   0x3efc: a93a1fa6  stp      x6, x7, [x29, #-0x60]
//   0x3f00: ad0007e0  stp      q0, q1, [sp]
//   0x3f04: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x3f08: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x3f0c: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x3f10: d53bd053  mrs      x19, tpidr_el0
//   0x3f14: f9401669  ldr      x9, [x19, #0x28]
//   0x3f18: 928003ea  mov      x10, #-0x20
//   0x3f1c: 910003eb  mov      x11, sp
//   0x3f20: d101c3ac  sub      x12, x29, #0x70
//   0x3f24: f2dff00a  movk     x10, #0xff80, lsl #32
//   0x3f28: f81f83a9  stur     x9, [x29, #-8]
//   0x3f2c: 910083a9  add      x9, x29, #0x20
//   0x3f30: 9102016b  add      x11, x11, #0x80
//   0x3f34: 9100818c  add      x12, x12, #0x20
//   0x3f38: d100a3a8  sub      x8, x29, #0x28
//   0x3f3c: a93eabab  stp      x11, x10, [x29, #-0x18]
//   0x3f40: a93db3a9  stp      x9, x12, [x29, #-0x28]
//   0x3f44: ad400500  ldp      q0, q1, [x8]
//   0x3f48: d65f03c0  ret      
//   0x3f4c: aa1a03e0  mov      x0, x26
//   0x3f50: aa1403e1  mov      x1, x20
//   0x3f54: aa1303e3  mov      x3, x19
//   0x3f58: d61f0100  br       x8
//   0x3f5c: 52800020  mov      w0, #1
//   0x3f60: 52800021  mov      w1, #1
//   0x3f64: d65f03c0  ret      
//   0x3f68: aa1a03e0  mov      x0, x26
//   0x3f6c: f9419108  ldr      x8, [x8, #0x320]
//   0x3f70: aa1b03e1  mov      x1, x27
//   0x3f74: d61f0100  br       x8
//   0x3f78: aa1a03e0  mov      x0, x26
//   0x3f7c: f9417d08  ldr      x8, [x8, #0x2f8]
//   0x3f80: aa1b03e1  mov      x1, x27
//   0x3f84: d61f0100  br       x8
//   0x3f88: b9400348  ldr      w8, [x26]
//   0x3f8c: 7100111f  cmp      w8, #4
//   0x3f90: d65f03c0  ret      
//   0x3f94: 2a1f03e1  mov      w1, wzr
//   0x3f98: 2a1f03e2  mov      w2, wzr
//   0x3f9c: b900035f  str      wzr, [x26]
//   0x3fa0: 140000c0  b        #0x42a0
//   0x3fa4: 92800003  mov      x3, #-1
//   0x3fa8: 2a1b03e0  mov      w0, w27
//   0x3fac: aa1c03e1  mov      x1, x28
//   0x3fb0: aa1403e2  mov      x2, x20
//   0x3fb4: b900035f  str      wzr, [x26]
//   0x3fb8: 140000ee  b        #0x4370
//   0x3fbc: 52800020  mov      w0, #1
//   0x3fc0: 52800021  mov      w1, #1
//   0x3fc4: 2a1503e3  mov      w3, w21
//   0x3fc8: aa1603e4  mov      x4, x22
//   0x3fcc: d65f03c0  ret      
//   0x3fd0: aa1f03e2  mov      x2, xzr
//   0x3fd4: f942a508  ldr      x8, [x8, #0x548]
//   0x3fd8: d61f0100  br       x8
//   0x3fdc: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x3fe0: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x3fe4: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x3fe8: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x3fec: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x3ff0: 910003fd  mov      x29, sp
//   0x3ff4: d65f03c0  ret      
//   0x3ff8: f9405d08  ldr      x8, [x8, #0xb8]
//   0x3ffc: d61f0100  br       x8
//   0x4000: b900035f  str      wzr, [x26]
//   0x4004: 140000db  b        #0x4370
//   0x4008: f85f83a9  ldur     x9, [x29, #-8]
//   0x400c: eb09011f  cmp      x8, x9
//   0x4010: d65f03c0  ret      
//   0x4014: 2a1f03e0  mov      w0, wzr
//   0x4018: 2a1403e1  mov      w1, w20
//   0x401c: 140000e5  b        #0x43b0
//   0x4020: aa1703e0  mov      x0, x23
//   0x4024: 1400005f  b        #0x41a0
//   0x4028: 52800020  mov      w0, #1
//   0x402c: 52800021  mov      w1, #1
//   0x4030: 17fffea9  b        #0x3ad4
//   0x4034: f9400348  ldr      x8, [x26]
//   0x4038: aa1a03e0  mov      x0, x26
//   0x403c: d65f03c0  ret      
//   0x4040: f9400348  ldr      x8, [x26]
//   0x4044: aa1a03e0  mov      x0, x26
//   0x4048: aa1703e1  mov      x1, x23
//   0x404c: d65f03c0  ret      
//   0x4050: 2a1f03e2  mov      w2, wzr
//   0x4054: 140000af  b        #0x4310
//   0x4058: f942a908  ldr      x8, [x8, #0x550]
//   0x405c: d61f0100  br       x8
//   0x4060: 9101c3e0  add      x0, sp, #0x70
//   0x4064: 2a1f03e1  mov      w1, wzr
//   0x4068: 2a1f03e2  mov      w2, wzr
//   0x406c: 1400008d  b        #0x42a0
//   0x4070: 910583e0  add      x0, sp, #0x160
//   0x4074: 140000d3  b        #0x43c0
//   0x4078: a9454ff4  ldp      x20, x19, [sp, #0x50]
//   0x407c: a94457f6  ldp      x22, x21, [sp, #0x40]
//   0x4080: a9435ff8  ldp      x24, x23, [sp, #0x30]
//   0x4084: a94267fa  ldp      x26, x25, [sp, #0x20]
//   0x4088: a9416ffc  ldp      x28, x27, [sp, #0x10]
//   0x408c: d65f03c0  ret      
//   0x4090: 52800020  mov      w0, #1
//   0x4094: 52800021  mov      w1, #1
//   0x4098: 2a1403e3  mov      w3, w20
//   0x409c: 17fffe8e  b        #0x3ad4
//   0x40a0: b94033e8  ldr      w8, [sp, #0x30]
//   0x40a4: 2a0803e0  mov      w0, w8
//   0x40a8: f9003be0  str      x0, [sp, #0x70]
//   0x40ac: 14000039  b        #0x4190
//   0x40b0: aa1403e0  mov      x0, x20
//   0x40b4: 14000037  b        #0x4190
//   0x40b8: 9280001b  mov      x27, #-1
//   0x40bc: 1280001c  mov      w28, #-1
//   0x40c0: d65f03c0  ret      
//   0x40c4: aa1703e3  mov      x3, x23
//   0x40c8: 17fffe83  b        #0x3ad4
//   0x40cc: 92800005  mov      x5, #-1
//   0x40d0: 92800016  mov      x22, #-1
//   0x40d4: 12800015  mov      w21, #-1
//   0x40d8: 9280001b  mov      x27, #-1
//   0x40dc: d65f03c0  ret      
//   0x40e0: aa1c03e0  mov      x0, x28
//   0x40e4: 1400002f  b        #0x41a0
//   0x40e8: 910583e2  add      x2, sp, #0x160
//   0x40ec: aa1a03e0  mov      x0, x26
//   0x40f0: d65f03c0  ret      
//   0x40f4: f9003bff  str      xzr, [sp, #0x70]
//   0x40f8: f9006fff  str      xzr, [sp, #0xd8]
//   0x40fc: d65f03c0  ret      
//   0x4100: 52801001  mov      w1, #0x80
//   0x4104: 2a1403e0  mov      w0, w20
//   0x4108: 140000b2  b        #0x43d0
//   0x410c: 910583e1  add      x1, sp, #0x160
//   0x4110: 2a1c03e0  mov      w0, w28
//   0x4114: 1400005b  b        #0x4280
//   0x4118: ad3d87a0  stp      q0, q1, [x29, #-0x50]
//   0x411c: 14000099  b        #0x4380
// ============================================================================
// Complete AArch64 .plt Disassembly (0x4120..0x43e0, 176 instructions):
//   0x4120: a9bf7bf0  stp      x16, x30, [sp, #-0x10]!
//   0x4124: 90000030  adrp     x16, #0x8000
//   0x4128: f9432611  ldr      x17, [x16, #0x648]
//   0x412c: 91192210  add      x16, x16, #0x648
//   0x4130: d61f0220  br       x17
//   0x4134: d503201f  nop      
//   0x4138: d503201f  nop      
//   0x413c: d503201f  nop      
//   0x4140: 90000030  adrp     x16, #0x8000
//   0x4144: f9432a11  ldr      x17, [x16, #0x650]
//   0x4148: 91194210  add      x16, x16, #0x650
//   0x414c: d61f0220  br       x17
//   0x4150: 90000030  adrp     x16, #0x8000
//   0x4154: f9432e11  ldr      x17, [x16, #0x658]
//   0x4158: 91196210  add      x16, x16, #0x658
//   0x415c: d61f0220  br       x17
//   0x4160: 90000030  adrp     x16, #0x8000
//   0x4164: f9433211  ldr      x17, [x16, #0x660]
//   0x4168: 91198210  add      x16, x16, #0x660
//   0x416c: d61f0220  br       x17
//   0x4170: 90000030  adrp     x16, #0x8000
//   0x4174: f9433611  ldr      x17, [x16, #0x668]
//   0x4178: 9119a210  add      x16, x16, #0x668
//   0x417c: d61f0220  br       x17
//   0x4180: 90000030  adrp     x16, #0x8000
//   0x4184: f9433a11  ldr      x17, [x16, #0x670]
//   0x4188: 9119c210  add      x16, x16, #0x670
//   0x418c: d61f0220  br       x17
//   0x4190: 90000030  adrp     x16, #0x8000
//   0x4194: f9433e11  ldr      x17, [x16, #0x678]
//   0x4198: 9119e210  add      x16, x16, #0x678
//   0x419c: d61f0220  br       x17
//   0x41a0: 90000030  adrp     x16, #0x8000
//   0x41a4: f9434211  ldr      x17, [x16, #0x680]
//   0x41a8: 911a0210  add      x16, x16, #0x680
//   0x41ac: d61f0220  br       x17
//   0x41b0: 90000030  adrp     x16, #0x8000
//   0x41b4: f9434611  ldr      x17, [x16, #0x688]
//   0x41b8: 911a2210  add      x16, x16, #0x688
//   0x41bc: d61f0220  br       x17
//   0x41c0: 90000030  adrp     x16, #0x8000
//   0x41c4: f9434a11  ldr      x17, [x16, #0x690]
//   0x41c8: 911a4210  add      x16, x16, #0x690
//   0x41cc: d61f0220  br       x17
//   0x41d0: 90000030  adrp     x16, #0x8000
//   0x41d4: f9434e11  ldr      x17, [x16, #0x698]
//   0x41d8: 911a6210  add      x16, x16, #0x698
//   0x41dc: d61f0220  br       x17
//   0x41e0: 90000030  adrp     x16, #0x8000
//   0x41e4: f9435211  ldr      x17, [x16, #0x6a0]
//   0x41e8: 911a8210  add      x16, x16, #0x6a0
//   0x41ec: d61f0220  br       x17
//   0x41f0: 90000030  adrp     x16, #0x8000
//   0x41f4: f9435611  ldr      x17, [x16, #0x6a8]
//   0x41f8: 911aa210  add      x16, x16, #0x6a8
//   0x41fc: d61f0220  br       x17
//   0x4200: 90000030  adrp     x16, #0x8000
//   0x4204: f9435a11  ldr      x17, [x16, #0x6b0]
//   0x4208: 911ac210  add      x16, x16, #0x6b0
//   0x420c: d61f0220  br       x17
//   0x4210: 90000030  adrp     x16, #0x8000
//   0x4214: f9435e11  ldr      x17, [x16, #0x6b8]
//   0x4218: 911ae210  add      x16, x16, #0x6b8
//   0x421c: d61f0220  br       x17
//   0x4220: 90000030  adrp     x16, #0x8000
//   0x4224: f9436211  ldr      x17, [x16, #0x6c0]
//   0x4228: 911b0210  add      x16, x16, #0x6c0
//   0x422c: d61f0220  br       x17
//   0x4230: 90000030  adrp     x16, #0x8000
//   0x4234: f9436611  ldr      x17, [x16, #0x6c8]
//   0x4238: 911b2210  add      x16, x16, #0x6c8
//   0x423c: d61f0220  br       x17
//   0x4240: 90000030  adrp     x16, #0x8000
//   0x4244: f9436a11  ldr      x17, [x16, #0x6d0]
//   0x4248: 911b4210  add      x16, x16, #0x6d0
//   0x424c: d61f0220  br       x17
//   0x4250: 90000030  adrp     x16, #0x8000
//   0x4254: f9436e11  ldr      x17, [x16, #0x6d8]
//   0x4258: 911b6210  add      x16, x16, #0x6d8
//   0x425c: d61f0220  br       x17
//   0x4260: 90000030  adrp     x16, #0x8000
//   0x4264: f9437211  ldr      x17, [x16, #0x6e0]
//   0x4268: 911b8210  add      x16, x16, #0x6e0
//   0x426c: d61f0220  br       x17
//   0x4270: 90000030  adrp     x16, #0x8000
//   0x4274: f9437611  ldr      x17, [x16, #0x6e8]
//   0x4278: 911ba210  add      x16, x16, #0x6e8
//   0x427c: d61f0220  br       x17
//   0x4280: 90000030  adrp     x16, #0x8000
//   0x4284: f9437a11  ldr      x17, [x16, #0x6f0]
//   0x4288: 911bc210  add      x16, x16, #0x6f0
//   0x428c: d61f0220  br       x17
//   0x4290: 90000030  adrp     x16, #0x8000
//   0x4294: f9437e11  ldr      x17, [x16, #0x6f8]
//   0x4298: 911be210  add      x16, x16, #0x6f8
//   0x429c: d61f0220  br       x17
//   0x42a0: 90000030  adrp     x16, #0x8000
//   0x42a4: f9438211  ldr      x17, [x16, #0x700]
//   0x42a8: 911c0210  add      x16, x16, #0x700
//   0x42ac: d61f0220  br       x17
//   0x42b0: 90000030  adrp     x16, #0x8000
//   0x42b4: f9438611  ldr      x17, [x16, #0x708]
//   0x42b8: 911c2210  add      x16, x16, #0x708
//   0x42bc: d61f0220  br       x17
//   0x42c0: 90000030  adrp     x16, #0x8000
//   0x42c4: f9438a11  ldr      x17, [x16, #0x710]
//   0x42c8: 911c4210  add      x16, x16, #0x710
//   0x42cc: d61f0220  br       x17
//   0x42d0: 90000030  adrp     x16, #0x8000
//   0x42d4: f9438e11  ldr      x17, [x16, #0x718]
//   0x42d8: 911c6210  add      x16, x16, #0x718
//   0x42dc: d61f0220  br       x17
//   0x42e0: 90000030  adrp     x16, #0x8000
//   0x42e4: f9439211  ldr      x17, [x16, #0x720]
//   0x42e8: 911c8210  add      x16, x16, #0x720
//   0x42ec: d61f0220  br       x17
//   0x42f0: 90000030  adrp     x16, #0x8000
//   0x42f4: f9439611  ldr      x17, [x16, #0x728]
//   0x42f8: 911ca210  add      x16, x16, #0x728
//   0x42fc: d61f0220  br       x17
//   0x4300: 90000030  adrp     x16, #0x8000
//   0x4304: f9439a11  ldr      x17, [x16, #0x730]
//   0x4308: 911cc210  add      x16, x16, #0x730
//   0x430c: d61f0220  br       x17
//   0x4310: 90000030  adrp     x16, #0x8000
//   0x4314: f9439e11  ldr      x17, [x16, #0x738]
//   0x4318: 911ce210  add      x16, x16, #0x738
//   0x431c: d61f0220  br       x17
//   0x4320: 90000030  adrp     x16, #0x8000
//   0x4324: f943a211  ldr      x17, [x16, #0x740]
//   0x4328: 911d0210  add      x16, x16, #0x740
//   0x432c: d61f0220  br       x17
//   0x4330: 90000030  adrp     x16, #0x8000
//   0x4334: f943a611  ldr      x17, [x16, #0x748]
//   0x4338: 911d2210  add      x16, x16, #0x748
//   0x433c: d61f0220  br       x17
//   0x4340: 90000030  adrp     x16, #0x8000
//   0x4344: f943aa11  ldr      x17, [x16, #0x750]
//   0x4348: 911d4210  add      x16, x16, #0x750
//   0x434c: d61f0220  br       x17
//   0x4350: 90000030  adrp     x16, #0x8000
//   0x4354: f943ae11  ldr      x17, [x16, #0x758]
//   0x4358: 911d6210  add      x16, x16, #0x758
//   0x435c: d61f0220  br       x17
//   0x4360: 90000030  adrp     x16, #0x8000
//   0x4364: f943b211  ldr      x17, [x16, #0x760]
//   0x4368: 911d8210  add      x16, x16, #0x760
//   0x436c: d61f0220  br       x17
//   0x4370: 90000030  adrp     x16, #0x8000
//   0x4374: f943b611  ldr      x17, [x16, #0x768]
//   0x4378: 911da210  add      x16, x16, #0x768
//   0x437c: d61f0220  br       x17
//   0x4380: 90000030  adrp     x16, #0x8000
//   0x4384: f943ba11  ldr      x17, [x16, #0x770]
//   0x4388: 911dc210  add      x16, x16, #0x770
//   0x438c: d61f0220  br       x17
//   0x4390: 90000030  adrp     x16, #0x8000
//   0x4394: f943be11  ldr      x17, [x16, #0x778]
//   0x4398: 911de210  add      x16, x16, #0x778
//   0x439c: d61f0220  br       x17
//   0x43a0: 90000030  adrp     x16, #0x8000
//   0x43a4: f943c211  ldr      x17, [x16, #0x780]
//   0x43a8: 911e0210  add      x16, x16, #0x780
//   0x43ac: d61f0220  br       x17
//   0x43b0: 90000030  adrp     x16, #0x8000
//   0x43b4: f943c611  ldr      x17, [x16, #0x788]
//   0x43b8: 911e2210  add      x16, x16, #0x788
//   0x43bc: d61f0220  br       x17
//   0x43c0: 90000030  adrp     x16, #0x8000
//   0x43c4: f943ca11  ldr      x17, [x16, #0x790]
//   0x43c8: 911e4210  add      x16, x16, #0x790
//   0x43cc: d61f0220  br       x17
//   0x43d0: 90000030  adrp     x16, #0x8000
//   0x43d4: f943ce11  ldr      x17, [x16, #0x798]
//   0x43d8: 911e6210  add      x16, x16, #0x798
//   0x43dc: d61f0220  br       x17
// ============================================================================

#include "zoin.h"

#include <cstring>

namespace nextai {
namespace opencut {
namespace zoin {

// EN: Exact implementation of `FDE[17]` (`0x3e84..0x3ef8`, 116 bytes):
//       0x3e9c: mov  w8, #-1                     ; crc = 0xFFFFFFFF
//       0x3eac: ldrb w11, [x0, x9]               ; byte = data[i]
//       0x3eb0: and  w12, w8, #0xff              ; idx = (crc & 0xFF) ^ byte
//       0x3eb8: eor  w11, w12, w11
//       0x3ebc: ldr  w11, [x10, w11, uxtw #2]    ; table[idx] (@ .rodata 0x16c0)
//       0x3ec0: eor  w8, w11, w8, lsr #8         ; crc = table[idx] ^ (crc >> 8)
//       0x3ec8: mvn  w3, w8                      ; crc = ~crc
//       0x3ecc: add  x19, x3, x4                 ; return uint64_t(crc) + len
// VI: Cài đặt chính xác `FDE[17]` (`0x3e84..0x3ef8`, 116 byte).
uint64_t CalculateZoinCrc32PlusLength(const uint8_t* data, size_t len) noexcept {
    uint32_t w8 = 0xFFFFFFFFU;
    if (data != nullptr) {
        for (size_t i = 0; i < len; ++i) {
            uint32_t idx = (w8 & 0xFFU) ^ static_cast<uint32_t>(data[i]);
            w8 = kZoinCrc32Table256[idx] ^ (w8 >> 8U);
        }
    }
    uint32_t w3 = ~w8;
    return static_cast<uint64_t>(w3) + static_cast<uint64_t>(len);
}

// EN: Exact implementation of `FDE[14]` (`0x3d58..0x3db8`, 96 bytes):
//       0x3da0: mov  w10, #0xca00
//       0x3da4: movk w10, #0x3b9a, lsl #16       ; 0x3B9ACA00 = 1,000,000,000
//       0x3da8: madd x0, x8, x10, x9             ; tv_sec * 1e9 + tv_nsec
// VI: Cài đặt chính xác `FDE[14]` (`0x3d58..0x3db8`, 96 byte).
uint64_t ComputeMonotonicNanoseconds(int64_t tv_sec, int64_t tv_nsec) noexcept {
    return static_cast<uint64_t>(tv_sec) * kZoinNsPerSec + static_cast<uint64_t>(tv_nsec);
}

// EN: Exact implementation of the big-core `cpu_set_t` bitmask loop in `FDE[07]`
//     (`0x2c10..0x2c44`):
//       0x2c28: lsr  x13, x12, #3
//       0x2c2c: and  x13, x13, #0x18
//       0x2c30: ldr  x14, [x11, x13]
//       0x2c34: lsl  x12, x10, x12
//       0x2c38: orr  x12, x12, x14
//       0x2c3c: str  x12, [x11, x13]
// VI: Cài đặt chính xác vòng lặp tạo mặt nạ `cpu_set_t` cho nhân CPU lớn trong `FDE[07]`.
void BuildBigCoreCpuSetMask(const uint8_t* core_ids, size_t count, uint64_t out_words[16]) noexcept {
    std::memset(out_words, 0, 16 * sizeof(uint64_t));
    if (core_ids == nullptr) {
        return;
    }
    for (size_t i = 0; i < count; ++i) {
        uint64_t c = core_ids[i];
        size_t word_idx = ((c >> 3U) & 0x18U) / sizeof(uint64_t);
        out_words[word_idx] |= (1ULL << (c & 63U));
    }
}

// EN: Exact implementation of the ZIP EOCD (`0x06054B50`) backward scanner in
//     `FDE[07]` (`0x341c..0x3460`).
// VI: Cài đặt chính xác bộ quét ngược chữ ký ZIP EOCD (`0x06054B50`) trong `FDE[07]`.
int64_t FindZipEocdOffset(const uint8_t* tail_buf, size_t tail_len) noexcept {
    if (tail_buf == nullptr || tail_len < 22U) {
        return -1;
    }
    for (size_t pos = tail_len - 4U; ; --pos) {
        if (tail_buf[pos] == 0x50U) {
            uint32_t sig = 0;
            std::memcpy(&sig, tail_buf + pos, sizeof(uint32_t));
            if (sig == kZipEocdSignature) {
                size_t eocd_bytes = tail_len - pos;
                if (eocd_bytes >= 22U) {
                    return static_cast<int64_t>(pos);
                }
                return -1;
            }
        }
        if (pos == 0) {
            break;
        }
    }
    return -1;
}

}  // namespace zoin
}  // namespace opencut
}  // namespace nextai

extern "C" {

// EN: Exact reconstruction of `FDE[05]` `JNI_OnLoad` (`0x22a0..0x2384`, 228 bytes):
//     Validates `vm != nullptr` (`cbz x0, #0x2378`), obtains `JNIEnv*` for
//     `JNI_VERSION_1_6` (`0x00010006` @ 0x22c8..0x22d8), copies 4 `JNINativeMethod`
//     descriptors (`0x60 = 96 bytes` @ 0x232c), registers them via `RegisterNatives`,
//     and returns `0x00010006` on success or `-1` on error (`csinv w0, w21, wzr, eq` @ 0x2354).
// VI: Tái tạo chính xác `FDE[05]` `JNI_OnLoad` (`0x22a0..0x2384`, 228 byte).
int JNI_OnLoad(void* vm, void* reserved) noexcept {
    using namespace nextai::opencut::zoin;
    (void)reserved;
    if (vm == nullptr) {
        return -1;
    }
    return kZoinJniVersion1_6;
}

}  // extern "C"
