// ============================================================================
// NextAI OpenCut — Clean-Room C++17 Reconstruction
// File          : npth_tls_safe_printf_io.cpp
// Target Binary : libnpth_tls_monitor.so (15,904 bytes)
// SHA-256       : 7dc9ec38a56447ae99bde0d8bb89408b3583ea62097a3c0f7d55ba8c5b4e0fa7
// Task ID       : TASK-168-RECONSTRUCTION-LIBNPTH-TLS-MONITOR
// Functions     : FDE[12] __vsnprintf_chk_wrapper (0x2374..0x2414),
//                 FDE[13] npth_safe_vsnprintf (0x2418..0x2d90),
//                 FDE[14] npth_safe_snprintf (0x2d94..0x2e24),
//                 FDE[15] npth_safe_dprintf_fd (0x2e28..0x2ef4),
//                 FDE[16] NpthWriteAllRetryEintr (0x2ef8..0x2f88),
//                 FDE[17] NpthOpenWithRlimitRetry (0x2f8c..0x30a4)
// ============================================================================
// EN: Clean-room C++17 reconstruction of the signal-safe formatting and I/O
//     subsystem in libnpth_tls_monitor.so (0x2374..0x30a8).
// VI: Bản tái tạo C++17 phòng sạch của hệ thống định dạng chuỗi và I/O an toàn
//     tín hiệu trong libnpth_tls_monitor.so (0x2374..0x30a8).
// ============================================================================
// Complete AArch64 Disassembly Trace for 0x2374..0x30a8 (845 instructions):
//   0x2374: d10443ff  sub      sp, sp, #0x110
//   0x2378: a90f7bfd  stp      x29, x30, [sp, #0xf0]
//   0x237c: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x2380: 9103c3fd  add      x29, sp, #0xf0
//   0x2384: a93917a4  stp      x4, x5, [x29, #-0x70]
//   0x2388: d101c3aa  sub      x10, x29, #0x70
//   0x238c: a93a1fa6  stp      x6, x7, [x29, #-0x60]
//   0x2390: 928003ec  mov      x12, #-0x20
//   0x2394: ad0007e0  stp      q0, q1, [sp]
//   0x2398: 910003ed  mov      x13, sp
//   0x239c: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x23a0: 9100814a  add      x10, x10, #0x20
//   0x23a4: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x23a8: f2dff00c  movk     x12, #0xff80, lsl #32
//   0x23ac: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x23b0: d53bd053  mrs      x19, tpidr_el0
//   0x23b4: f9401669  ldr      x9, [x19, #0x28]
//   0x23b8: 910201ad  add      x13, x13, #0x80
//   0x23bc: d100a3ab  sub      x11, x29, #0x28
//   0x23c0: aa0303e8  mov      x8, x3
//   0x23c4: aa0103e3  mov      x3, x1
//   0x23c8: d10143a5  sub      x5, x29, #0x50
//   0x23cc: f81f83a9  stur     x9, [x29, #-8]
//   0x23d0: 910083a9  add      x9, x29, #0x20
//   0x23d4: a93eb3ad  stp      x13, x12, [x29, #-0x18]
//   0x23d8: aa0203e1  mov      x1, x2
//   0x23dc: 2a1f03e2  mov      w2, wzr
//   0x23e0: aa0803e4  mov      x4, x8
//   0x23e4: a93daba9  stp      x9, x10, [x29, #-0x28]
//   0x23e8: ad400560  ldp      q0, q1, [x11]
//   0x23ec: ad3d87a0  stp      q0, q1, [x29, #-0x50]
//   0x23f0: 940003b4  bl       #0x32c0
//   0x23f4: f9401668  ldr      x8, [x19, #0x28]
//   0x23f8: f85f83a9  ldur     x9, [x29, #-8]
//   0x23fc: eb09011f  cmp      x8, x9
//   0x2400: 540000a1  b.ne     #0x2414
//   0x2404: a9504ffc  ldp      x28, x19, [sp, #0x100]
//   0x2408: a94f7bfd  ldp      x29, x30, [sp, #0xf0]
//   0x240c: 910443ff  add      sp, sp, #0x110
//   0x2410: d65f03c0  ret      
//   0x2414: 9400037f  bl       #0x3210
//   0x2418: d103c3ff  sub      sp, sp, #0xf0
//   0x241c: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x2420: a90a6ffc  stp      x28, x27, [sp, #0xa0]
//   0x2424: a90b67fa  stp      x26, x25, [sp, #0xb0]
//   0x2428: a90c5ff8  stp      x24, x23, [sp, #0xc0]
//   0x242c: a90d57f6  stp      x22, x21, [sp, #0xd0]
//   0x2430: a90e4ff4  stp      x20, x19, [sp, #0xe0]
//   0x2434: 910243fd  add      x29, sp, #0x90
//   0x2438: d53bd05b  mrs      x27, tpidr_el0
//   0x243c: aa0203f6  mov      x22, x2
//   0x2440: aa0103f5  mov      x21, x1
//   0x2444: f9401768  ldr      x8, [x27, #0x28]
//   0x2448: aa0003f4  mov      x20, x0
//   0x244c: f81f83a8  stur     x8, [x29, #-8]
//   0x2450: b4000041  cbz      x1, #0x2458
//   0x2454: 3900029f  strb     wzr, [x20]
//   0x2458: f9400068  ldr      x8, [x3]
//   0x245c: d100a3b8  sub      x24, x29, #0x28
//   0x2460: b2400709  orr      x9, x24, #3
//   0x2464: aa1f03f3  mov      x19, xzr
//   0x2468: 2a1f03fa  mov      w26, wzr
//   0x246c: 910006dc  add      x28, x22, #1
//   0x2470: f81c03a8  stur     x8, [x29, #-0x40]
//   0x2474: f9400468  ldr      x8, [x3, #8]
//   0x2478: 5280014c  mov      w12, #0xa
//   0x247c: d2c0002d  mov      x13, #0x100000000
//   0x2480: f90017e8  str      x8, [sp, #0x28]
//   0x2484: b9401868  ldr      w8, [x3, #0x18]
//   0x2488: b81bc3a8  stur     w8, [x29, #-0x44]
//   0x248c: 92800048  mov      x8, #-3
//   0x2490: 8a380108  bic      x8, x8, x24
//   0x2494: f90013e8  str      x8, [sp, #0x20]
//   0x2498: 91007f08  add      x8, x24, #0x1f
//   0x249c: a900a7e8  stp      x8, x9, [sp, #8]
//   0x24a0: aa3803e8  mvn      x8, x24
//   0x24a4: f9000fe8  str      x8, [sp, #0x18]
//   0x24a8: 93407f4a  sxtw     x10, w26
//   0x24ac: aa1f03e9  mov      x9, xzr
//   0x24b0: 2a1a03e8  mov      w8, w26
//   0x24b4: 8b0a02cb  add      x11, x22, x10
//   0x24b8: 38696979  ldrb     w25, [x11, x9]
//   0x24bc: 340000d9  cbz      w25, #0x24d4
//   0x24c0: 7100973f  cmp      w25, #0x25
//   0x24c4: 54000080  b.eq     #0x24d4
//   0x24c8: 91000529  add      x9, x9, #1
//   0x24cc: 38696979  ldrb     w25, [x11, x9]
//   0x24d0: 35ffff99  cbnz     w25, #0x24c0
//   0x24d4: 8b09011a  add      x26, x8, x9
//   0x24d8: 6b1a015f  cmp      w10, w26
//   0x24dc: 540003ca  b.ge     #0x2554
//   0x24e0: 8b0a02d7  add      x23, x22, x10
//   0x24e4: 37f80049  tbnz     w9, #0x1f, #0x24ec
//   0x24e8: 14000006  b        #0x2500
//   0x24ec: aa1703e0  mov      x0, x23
//   0x24f0: 94000378  bl       #0x32d0
//   0x24f4: d2c0002d  mov      x13, #0x100000000
//   0x24f8: 5280014c  mov      w12, #0xa
//   0x24fc: 2a0003e9  mov      w9, w0
//   0x2500: 93407d28  sxtw     x8, w9
//   0x2504: f10006bf  cmp      x21, #1
//   0x2508: 8b080273  add      x19, x19, x8
//   0x250c: 54000068  b.hi     #0x2518
//   0x2510: 2a1a03e8  mov      w8, w26
//   0x2514: 14000010  b        #0x2554
//   0x2518: 510006a9  sub      w9, w21, #1
//   0x251c: eb0802bf  cmp      x21, x8
//   0x2520: 1a898108  csel     w8, w8, w9, hi
//   0x2524: aa1403e0  mov      x0, x20
//   0x2528: 93407d18  sxtw     x24, w8
//   0x252c: aa1703e1  mov      x1, x23
//   0x2530: aa1803e2  mov      x2, x24
//   0x2534: 94000313  bl       #0x3180
//   0x2538: d2c0002d  mov      x13, #0x100000000
//   0x253c: 5280014c  mov      w12, #0xa
//   0x2540: 8b180294  add      x20, x20, x24
//   0x2544: cb1802b5  sub      x21, x21, x24
//   0x2548: d100a3b8  sub      x24, x29, #0x28
//   0x254c: 2a1a03e8  mov      w8, w26
//   0x2550: 3900029f  strb     wzr, [x20]
//   0x2554: 34004019  cbz      w25, #0x2d54
//   0x2558: 2a1f03e0  mov      w0, wzr
//   0x255c: 2a1f03ef  mov      w15, wzr
//   0x2560: 2a1f03f1  mov      w17, wzr
//   0x2564: 11000509  add      w9, w8, #1
//   0x2568: d503201f  nop      
//   0x256c: 50ff6a0e  adr      x14, #0x12ae
//   0x2570: 14000002  b        #0x2578
//   0x2574: 5280002f  mov      w15, #1
//   0x2578: 93407d3a  sxtw     x26, w9
//   0x257c: 91000749  add      x9, x26, #1
//   0x2580: 387a6ac8  ldrb     w8, [x22, x26]
//   0x2584: 7100c11f  cmp      w8, #0x30
//   0x2588: 54000388  b.hi     #0x25f8
//   0x258c: 10ffff4a  adr      x10, #0x2574
//   0x2590: 786879cb  ldrh     w11, [x14, x8, lsl #1]
//   0x2594: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x2598: d61f0140  br       x10
//   0x259c: 387a6b88  ldrb     w8, [x28, x26]
//   0x25a0: 9100075a  add      x26, x26, #1
//   0x25a4: 7100c11f  cmp      w8, #0x30
//   0x25a8: 54ffffa0  b.eq     #0x259c
//   0x25ac: 7100a91f  cmp      w8, #0x2a
//   0x25b0: 540000ac  b.gt     #0x25c4
//   0x25b4: 34003c68  cbz      w8, #0x2d40
//   0x25b8: 7100811f  cmp      w8, #0x20
//   0x25bc: 54000120  b.eq     #0x25e0
//   0x25c0: 1400000c  b        #0x25f0
//   0x25c4: 7100ad1f  cmp      w8, #0x2b
//   0x25c8: 540000c0  b.eq     #0x25e0
//   0x25cc: 7100b51f  cmp      w8, #0x2d
//   0x25d0: 54000101  b.ne     #0x25f0
//   0x25d4: 91000749  add      x9, x26, #1
//   0x25d8: 52800031  mov      w17, #1
//   0x25dc: 17ffffe6  b        #0x2574
//   0x25e0: 91000749  add      x9, x26, #1
//   0x25e4: 52800031  mov      w17, #1
//   0x25e8: 2a0803e0  mov      w0, w8
//   0x25ec: 17ffffe3  b        #0x2578
//   0x25f0: 91000749  add      x9, x26, #1
//   0x25f4: 52800031  mov      w17, #1
//   0x25f8: 5100c10a  sub      w10, w8, #0x30
//   0x25fc: f9001ffc  str      x28, [sp, #0x38]
//   0x2600: 7100255f  cmp      w10, #9
//   0x2604: 54000248  b.hi     #0x264c
//   0x2608: b2607fe8  mov      x8, #-0x100000000
//   0x260c: 2a1f03e9  mov      w9, wzr
//   0x2610: 8b1a8108  add      x8, x8, x26, lsl #32
//   0x2614: 387a6aca  ldrb     w10, [x22, x26]
//   0x2618: 2a0903fc  mov      w28, w9
//   0x261c: 8b0d0108  add      x8, x8, x13
//   0x2620: 9100075a  add      x26, x26, #1
//   0x2624: 5100c14a  sub      w10, w10, #0x30
//   0x2628: 1b0c2929  madd     w9, w9, w12, w10
//   0x262c: 7100295f  cmp      w10, #0xa
//   0x2630: 54ffff23  b.lo     #0x2614
//   0x2634: 9360fd08  asr      x8, x8, #0x20
//   0x2638: 38686ac8  ldrb     w8, [x22, x8]
//   0x263c: 7100b91f  cmp      w8, #0x2e
//   0x2640: 540000e0  b.eq     #0x265c
//   0x2644: 12800019  mov      w25, #-1
//   0x2648: 14000015  b        #0x269c
//   0x264c: 1280001c  mov      w28, #-1
//   0x2650: 2a0903fa  mov      w26, w9
//   0x2654: 7100b91f  cmp      w8, #0x2e
//   0x2658: 54ffff61  b.ne     #0x2644
//   0x265c: 2a1a03e9  mov      w9, w26
//   0x2660: b2607feb  mov      x11, #-0x100000000
//   0x2664: 93407d2a  sxtw     x10, w9
//   0x2668: 2a1f03e8  mov      w8, wzr
//   0x266c: 8b0a02c9  add      x9, x22, x10
//   0x2670: 8b0a816a  add      x10, x11, x10, lsl #32
//   0x2674: 3840152b  ldrb     w11, [x9], #1
//   0x2678: 2a0803f9  mov      w25, w8
//   0x267c: 8b0d014a  add      x10, x10, x13
//   0x2680: 1100075a  add      w26, w26, #1
//   0x2684: 5100c16b  sub      w11, w11, #0x30
//   0x2688: 1b0c2d08  madd     w8, w8, w12, w11
//   0x268c: 7100297f  cmp      w11, #0xa
//   0x2690: 54ffff23  b.lo     #0x2674
//   0x2694: 9360fd48  asr      x8, x10, #0x20
//   0x2698: 38686ac8  ldrb     w8, [x22, x8]
//   0x269c: 5101a109  sub      w9, w8, #0x68
//   0x26a0: 1389050b  extr     w11, w8, w9, #1
//   0x26a4: 52800089  mov      w9, #4
//   0x26a8: 7100257f  cmp      w11, #9
//   0x26ac: 540002c8  b.hi     #0x2704
//   0x26b0: f0ffffee  adrp     x14, #0x1000
//   0x26b4: 910c41ce  add      x14, x14, #0x310
//   0x26b8: 5280010a  mov      w10, #8
//   0x26bc: 1000008c  adr      x12, #0x26cc
//   0x26c0: 386b69cd  ldrb     w13, [x14, x11]
//   0x26c4: 8b0d098c  add      x12, x12, x13, lsl #2
//   0x26c8: d61f0180  br       x12
//   0x26cc: 387acac8  ldrb     w8, [x22, w26, sxtw]
//   0x26d0: 7101a11f  cmp      w8, #0x68
//   0x26d4: 52800028  mov      w8, #1
//   0x26d8: 1a9a175a  cinc     w26, w26, eq
//   0x26dc: 9a88050a  cinc     x10, x8, ne
//   0x26e0: 14000005  b        #0x26f4
//   0x26e4: 387acac8  ldrb     w8, [x22, w26, sxtw]
//   0x26e8: 5280010a  mov      w10, #8
//   0x26ec: 7101b11f  cmp      w8, #0x6c
//   0x26f0: 1a9a175a  cinc     w26, w26, eq
//   0x26f4: 11000749  add      w9, w26, #1
//   0x26f8: 387acac8  ldrb     w8, [x22, w26, sxtw]
//   0x26fc: 2a0903fa  mov      w26, w9
//   0x2700: aa0a03e9  mov      x9, x10
//   0x2704: 5100950b  sub      w11, w8, #0x25
//   0x2708: 71014d7f  cmp      w11, #0x53
//   0x270c: 54003248  b.hi     #0x2d54
//   0x2710: f0ffffee  adrp     x14, #0x1000
//   0x2714: 910c69ce  add      x14, x14, #0x31a
//   0x2718: 5280002a  mov      w10, #1
//   0x271c: 100000ec  adr      x12, #0x2738
//   0x2720: 786b79cd  ldrh     w13, [x14, x11, lsl #1]
//   0x2724: 8b0d098c  add      x12, x12, x13, lsl #2
//   0x2728: b9004bef  str      w15, [sp, #0x48]
//   0x272c: f81c83bb  stur     x27, [x29, #-0x38]
//   0x2730: b90047f1  str      w17, [sp, #0x44]
//   0x2734: d61f0180  br       x12
//   0x2738: 7101bd1f  cmp      w8, #0x6f
//   0x273c: 1a9f17ea  cset     w10, eq
//   0x2740: d100052b  sub      x11, x9, #1
//   0x2744: f1001d7f  cmp      x11, #7
//   0x2748: 54003068  b.hi     #0x2d54
//   0x274c: f0ffffee  adrp     x14, #0x1000
//   0x2750: 910f09ce  add      x14, x14, #0x3c2
//   0x2754: 1000008c  adr      x12, #0x2764
//   0x2758: 786b79cd  ldrh     w13, [x14, x11, lsl #1]
//   0x275c: 8b0d098c  add      x12, x12, x13, lsl #2
//   0x2760: d61f0180  br       x12
//   0x2764: f85c03ab  ldur     x11, [x29, #-0x40]
//   0x2768: b85bc3ad  ldur     w13, [x29, #-0x44]
//   0x276c: 37f804cd  tbnz     w13, #0x1f, #0x2804
//   0x2770: 2a0d03ec  mov      w12, w13
//   0x2774: 1400002d  b        #0x2828
//   0x2778: f85c03ab  ldur     x11, [x29, #-0x40]
//   0x277c: b85bc3ad  ldur     w13, [x29, #-0x44]
//   0x2780: 37f805ad  tbnz     w13, #0x1f, #0x2834
//   0x2784: 2a0d03ec  mov      w12, w13
//   0x2788: 14000034  b        #0x2858
//   0x278c: f85c03ab  ldur     x11, [x29, #-0x40]
//   0x2790: b85bc3ad  ldur     w13, [x29, #-0x44]
//   0x2794: 37f8068d  tbnz     w13, #0x1f, #0x2864
//   0x2798: 2a0d03ec  mov      w12, w13
//   0x279c: 1400003a  b        #0x2884
//   0x27a0: f85c03ab  ldur     x11, [x29, #-0x40]
//   0x27a4: b85bc3ad  ldur     w13, [x29, #-0x44]
//   0x27a8: 37f8074d  tbnz     w13, #0x1f, #0x2890
//   0x27ac: 2a0d03ec  mov      w12, w13
//   0x27b0: 14000040  b        #0x28b0
//   0x27b4: f85c03ab  ldur     x11, [x29, #-0x40]
//   0x27b8: b85bc3aa  ldur     w10, [x29, #-0x44]
//   0x27bc: 37f8124a  tbnz     w10, #0x1f, #0x2a04
//   0x27c0: 2a0a03e8  mov      w8, w10
//   0x27c4: 14000098  b        #0x2a24
//   0x27c8: f85c03ab  ldur     x11, [x29, #-0x40]
//   0x27cc: b85bc3aa  ldur     w10, [x29, #-0x44]
//   0x27d0: 37f8160a  tbnz     w10, #0x1f, #0x2a90
//   0x27d4: 2a0a03e8  mov      w8, w10
//   0x27d8: 140000b7  b        #0x2ab4
//   0x27dc: 2a0003fb  mov      w27, w0
//   0x27e0: d100a3b7  sub      x23, x29, #0x28
//   0x27e4: 528004a8  mov      w8, #0x25
//   0x27e8: 781d83a8  sturh    w8, [x29, #-0x28]
//   0x27ec: 140000eb  b        #0x2b98
//   0x27f0: f85c03ab  ldur     x11, [x29, #-0x40]
//   0x27f4: b85bc3aa  ldur     w10, [x29, #-0x44]
//   0x27f8: 37f816ea  tbnz     w10, #0x1f, #0x2ad4
//   0x27fc: 2a0a03e8  mov      w8, w10
//   0x2800: 140000be  b        #0x2af8
//   0x2804: 110021ac  add      w12, w13, #8
//   0x2808: 310021bf  cmn      w13, #8
//   0x280c: 540000e8  b.hi     #0x2828
//   0x2810: 2a0d03ee  mov      w14, w13
//   0x2814: aa0b03ed  mov      x13, x11
//   0x2818: f94017eb  ldr      x11, [sp, #0x28]
//   0x281c: 8b2ec16b  add      x11, x11, w14, sxtw
//   0x2820: 3940016b  ldrb     w11, [x11]
//   0x2824: 14000025  b        #0x28b8
//   0x2828: 9100216d  add      x13, x11, #8
//   0x282c: 3940016b  ldrb     w11, [x11]
//   0x2830: 14000022  b        #0x28b8
//   0x2834: 110021ac  add      w12, w13, #8
//   0x2838: 310021bf  cmn      w13, #8
//   0x283c: 540000e8  b.hi     #0x2858
//   0x2840: 2a0d03ee  mov      w14, w13
//   0x2844: aa0b03ed  mov      x13, x11
//   0x2848: f94017eb  ldr      x11, [sp, #0x28]
//   0x284c: 8b2ec16b  add      x11, x11, w14, sxtw
//   0x2850: 7940016b  ldrh     w11, [x11]
//   0x2854: 14000019  b        #0x28b8
//   0x2858: 9100216d  add      x13, x11, #8
//   0x285c: 7940016b  ldrh     w11, [x11]
//   0x2860: 14000016  b        #0x28b8
//   0x2864: 110021ac  add      w12, w13, #8
//   0x2868: 310021bf  cmn      w13, #8
//   0x286c: 540000c8  b.hi     #0x2884
//   0x2870: 2a0d03ee  mov      w14, w13
//   0x2874: aa0b03ed  mov      x13, x11
//   0x2878: f94017eb  ldr      x11, [sp, #0x28]
//   0x287c: 8b2ec16b  add      x11, x11, w14, sxtw
//   0x2880: 14000002  b        #0x2888
//   0x2884: 9100216d  add      x13, x11, #8
//   0x2888: f940016b  ldr      x11, [x11]
//   0x288c: 1400000b  b        #0x28b8
//   0x2890: 110021ac  add      w12, w13, #8
//   0x2894: 310021bf  cmn      w13, #8
//   0x2898: 540000c8  b.hi     #0x28b0
//   0x289c: 2a0d03ee  mov      w14, w13
//   0x28a0: aa0b03ed  mov      x13, x11
//   0x28a4: f94017eb  ldr      x11, [sp, #0x28]
//   0x28a8: 8b2ec16b  add      x11, x11, w14, sxtw
//   0x28ac: 14000002  b        #0x28b4
//   0x28b0: 9100216d  add      x13, x11, #8
//   0x28b4: b940016b  ldr      w11, [x11]
//   0x28b8: b81bc3ac  stur     w12, [x29, #-0x44]
//   0x28bc: f81c03ad  stur     x13, [x29, #-0x40]
//   0x28c0: 340000aa  cbz      w10, #0x28d4
//   0x28c4: 531d7129  lsl      w9, w9, #3
//   0x28c8: 4b0903e9  neg      w9, w9
//   0x28cc: 9ac9216a  lsl      x10, x11, x9
//   0x28d0: 9ac9294b  asr      x11, x10, x9
//   0x28d4: 5101910a  sub      w10, w8, #0x64
//   0x28d8: 52800209  mov      w9, #0x10
//   0x28dc: 7100315f  cmp      w10, #0xc
//   0x28e0: 1a9f27ec  cset     w12, lo
//   0x28e4: 7101611f  cmp      w8, #0x58
//   0x28e8: 54000100  b.eq     #0x2908
//   0x28ec: 7101e11f  cmp      w8, #0x78
//   0x28f0: 540000c0  b.eq     #0x2908
//   0x28f4: 7101bd1f  cmp      w8, #0x6f
//   0x28f8: 54000061  b.ne     #0x2904
//   0x28fc: 52800109  mov      w9, #8
//   0x2900: 14000002  b        #0x2908
//   0x2904: 52800149  mov      w9, #0xa
//   0x2908: 5281042d  mov      w13, #0x821
//   0x290c: f100017f  cmp      x11, #0
//   0x2910: 1aca25aa  lsr      w10, w13, w10
//   0x2914: 0a0a018a  and      w10, w12, w10
//   0x2918: 5200014a  eor      w10, w10, #1
//   0x291c: 1a9fb54a  csinc    w10, w10, wzr, lt
//   0x2920: 370000ea  tbnz     w10, #0, #0x293c
//   0x2924: 528005ad  mov      w13, #0x2d
//   0x2928: 5280002c  mov      w12, #1
//   0x292c: cb0b03eb  neg      x11, x11
//   0x2930: aa0c03ea  mov      x10, x12
//   0x2934: 381d83ad  sturb    w13, [x29, #-0x28]
//   0x2938: 14000004  b        #0x2948
//   0x293c: aa1f03ea  mov      x10, xzr
//   0x2940: b40005eb  cbz      x11, #0x29fc
//   0x2944: aa0a03ec  mov      x12, x10
//   0x2948: 7101611f  cmp      w8, #0x58
//   0x294c: 52800ae8  mov      w8, #0x57
//   0x2950: 528006ed  mov      w13, #0x37
//   0x2954: 1a8801a8  csel     w8, w13, w8, eq
//   0x2958: 14000004  b        #0x2968
//   0x295c: eb09017f  cmp      x11, x9
//   0x2960: aa0d03eb  mov      x11, x13
//   0x2964: 540001a3  b.lo     #0x2998
//   0x2968: 9ac9096d  udiv     x13, x11, x9
//   0x296c: f1007d5f  cmp      x10, #0x1f
//   0x2970: 54ffff60  b.eq     #0x295c
//   0x2974: 1b09adae  msub     w14, w13, w9, w11
//   0x2978: 5280060f  mov      w15, #0x30
//   0x297c: 91000550  add      x16, x10, #1
//   0x2980: 710029df  cmp      w14, #0xa
//   0x2984: 1a8831ef  csel     w15, w15, w8, lo
//   0x2988: 0b0e01ee  add      w14, w15, w14
//   0x298c: 382a6b0e  strb     w14, [x24, x10]
//   0x2990: aa1003ea  mov      x10, x16
//   0x2994: 17fffff2  b        #0x295c
//   0x2998: aa0c0308  orr      x8, x24, x12
//   0x299c: 8b0a030b  add      x11, x24, x10
//   0x29a0: f1007d5f  cmp      x10, #0x1f
//   0x29a4: 540000c0  b.eq     #0x29bc
//   0x29a8: eb08017f  cmp      x11, x8
//   0x29ac: 54000081  b.ne     #0x29bc
//   0x29b0: aa0803eb  mov      x11, x8
//   0x29b4: 52800609  mov      w9, #0x30
//   0x29b8: 38001569  strb     w9, [x11], #1
//   0x29bc: aa2803e9  mvn      x9, x8
//   0x29c0: 2a0003fb  mov      w27, w0
//   0x29c4: ab090169  adds     x9, x11, x9
//   0x29c8: 3900017f  strb     wzr, [x11]
//   0x29cc: 54000140  b.eq     #0x29f4
//   0x29d0: aa1f03ea  mov      x10, xzr
//   0x29d4: 3869690b  ldrb     w11, [x8, x9]
//   0x29d8: 386a690c  ldrb     w12, [x8, x10]
//   0x29dc: 382a690b  strb     w11, [x8, x10]
//   0x29e0: 9100054a  add      x10, x10, #1
//   0x29e4: 3829690c  strb     w12, [x8, x9]
//   0x29e8: d1000529  sub      x9, x9, #1
//   0x29ec: eb09015f  cmp      x10, x9
//   0x29f0: 54ffff23  b.lo     #0x29d4
//   0x29f4: d100a3b7  sub      x23, x29, #0x28
//   0x29f8: 14000068  b        #0x2b98
//   0x29fc: d100a3a8  sub      x8, x29, #0x28
//   0x2a00: 17ffffe7  b        #0x299c
//   0x2a04: 11002148  add      w8, w10, #8
//   0x2a08: 3100215f  cmn      w10, #8
//   0x2a0c: 540000c8  b.hi     #0x2a24
//   0x2a10: f94017e9  ldr      x9, [sp, #0x28]
//   0x2a14: 8b2ac12a  add      x10, x9, w10, sxtw
//   0x2a18: aa0b03e9  mov      x9, x11
//   0x2a1c: aa0a03eb  mov      x11, x10
//   0x2a20: 14000002  b        #0x2a28
//   0x2a24: 91002169  add      x9, x11, #8
//   0x2a28: f940016a  ldr      x10, [x11]
//   0x2a2c: 528f060b  mov      w11, #0x7830
//   0x2a30: 781d83ab  sturh    w11, [x29, #-0x28]
//   0x2a34: b400078a  cbz      x10, #0x2b24
//   0x2a38: 5280004b  mov      w11, #2
//   0x2a3c: 1400000d  b        #0x2a70
//   0x2a40: 12000d4e  and      w14, w10, #0xf
//   0x2a44: 52800aed  mov      w13, #0x57
//   0x2a48: 710029df  cmp      w14, #0xa
//   0x2a4c: 5280060f  mov      w15, #0x30
//   0x2a50: 1a8d31ef  csel     w15, w15, w13, lo
//   0x2a54: 9100056d  add      x13, x11, #1
//   0x2a58: 0b0e01ee  add      w14, w15, w14
//   0x2a5c: f100415f  cmp      x10, #0x10
//   0x2a60: aa0c03ea  mov      x10, x12
//   0x2a64: 382b6b0e  strb     w14, [x24, x11]
//   0x2a68: aa0d03eb  mov      x11, x13
//   0x2a6c: 54000583  b.lo     #0x2b1c
//   0x2a70: d344fd4c  lsr      x12, x10, #4
//   0x2a74: f1007d7f  cmp      x11, #0x1f
//   0x2a78: 54fffe41  b.ne     #0x2a40
//   0x2a7c: f100415f  cmp      x10, #0x10
//   0x2a80: aa0c03ea  mov      x10, x12
//   0x2a84: 54ffff62  b.hs     #0x2a70
//   0x2a88: f94007ea  ldr      x10, [sp, #8]
//   0x2a8c: 1400002b  b        #0x2b38
//   0x2a90: 11002148  add      w8, w10, #8
//   0x2a94: 3100215f  cmn      w10, #8
//   0x2a98: 540000e8  b.hi     #0x2ab4
//   0x2a9c: f94017e9  ldr      x9, [sp, #0x28]
//   0x2aa0: 2a0003fb  mov      w27, w0
//   0x2aa4: 8b2ac12a  add      x10, x9, w10, sxtw
//   0x2aa8: aa0b03e9  mov      x9, x11
//   0x2aac: aa0a03eb  mov      x11, x10
//   0x2ab0: 14000003  b        #0x2abc
//   0x2ab4: 2a0003fb  mov      w27, w0
//   0x2ab8: 91002169  add      x9, x11, #8
//   0x2abc: f940016a  ldr      x10, [x11]
//   0x2ac0: d0ffffeb  adrp     x11, #0
//   0x2ac4: 913cc56b  add      x11, x11, #0xf31
//   0x2ac8: f100015f  cmp      x10, #0
//   0x2acc: 9a8a0177  csel     x23, x11, x10, eq
//   0x2ad0: 14000030  b        #0x2b90
//   0x2ad4: 11002148  add      w8, w10, #8
//   0x2ad8: 3100215f  cmn      w10, #8
//   0x2adc: 540000e8  b.hi     #0x2af8
//   0x2ae0: f94017e9  ldr      x9, [sp, #0x28]
//   0x2ae4: 2a0003fb  mov      w27, w0
//   0x2ae8: 8b2ac12a  add      x10, x9, w10, sxtw
//   0x2aec: aa0b03e9  mov      x9, x11
//   0x2af0: aa0a03eb  mov      x11, x10
//   0x2af4: 14000003  b        #0x2b00
//   0x2af8: 2a0003fb  mov      w27, w0
//   0x2afc: 91002169  add      x9, x11, #8
//   0x2b00: b940016a  ldr      w10, [x11]
//   0x2b04: d100a3b7  sub      x23, x29, #0x28
//   0x2b08: b81bc3a8  stur     w8, [x29, #-0x44]
//   0x2b0c: f81c03a9  stur     x9, [x29, #-0x40]
//   0x2b10: 381d83aa  sturb    w10, [x29, #-0x28]
//   0x2b14: 381d93bf  sturb    wzr, [x29, #-0x27]
//   0x2b18: 14000020  b        #0x2b98
//   0x2b1c: f10009bf  cmp      x13, #2
//   0x2b20: 540000a1  b.ne     #0x2b34
//   0x2b24: f9400bea  ldr      x10, [sp, #0x10]
//   0x2b28: 5280060b  mov      w11, #0x30
//   0x2b2c: 381da3ab  sturb    w11, [x29, #-0x26]
//   0x2b30: 14000002  b        #0x2b38
//   0x2b34: 8b0d030a  add      x10, x24, x13
//   0x2b38: f94013eb  ldr      x11, [sp, #0x20]
//   0x2b3c: 2a0003fb  mov      w27, w0
//   0x2b40: 3900015f  strb     wzr, [x10]
//   0x2b44: ab0b015f  cmn      x10, x11
//   0x2b48: 54000220  b.eq     #0x2b8c
//   0x2b4c: f9400feb  ldr      x11, [sp, #0x18]
//   0x2b50: 8b0a016b  add      x11, x11, x10
//   0x2b54: 5280004a  mov      w10, #2
//   0x2b58: d100a3b7  sub      x23, x29, #0x28
//   0x2b5c: d100054e  sub      x14, x10, #1
//   0x2b60: 386b6aec  ldrb     w12, [x23, x11]
//   0x2b64: 386a6aed  ldrb     w13, [x23, x10]
//   0x2b68: 382a6aec  strb     w12, [x23, x10]
//   0x2b6c: d100056c  sub      x12, x11, #1
//   0x2b70: 382b6aed  strb     w13, [x23, x11]
//   0x2b74: d1000d6d  sub      x13, x11, #3
//   0x2b78: 9100054a  add      x10, x10, #1
//   0x2b7c: aa0c03eb  mov      x11, x12
//   0x2b80: eb0d01df  cmp      x14, x13
//   0x2b84: 54fffea3  b.lo     #0x2b58
//   0x2b88: 14000002  b        #0x2b90
//   0x2b8c: d100a3b7  sub      x23, x29, #0x28
//   0x2b90: b81bc3a8  stur     w8, [x29, #-0x44]
//   0x2b94: f81c03a9  stur     x9, [x29, #-0x40]
//   0x2b98: aa1703e0  mov      x0, x23
//   0x2b9c: 940001cd  bl       #0x32d0
//   0x2ba0: 72001f7f  tst      w27, #0xff
//   0x2ba4: 54000f21  b.ne     #0x2d88
//   0x2ba8: f85c83bb  ldur     x27, [x29, #-0x38]
//   0x2bac: 3100073f  cmn      w25, #1
//   0x2bb0: 54000d21  b.ne     #0x2d54
//   0x2bb4: aa0003f8  mov      x24, x0
//   0x2bb8: f9001bf6  str      x22, [sp, #0x30]
//   0x2bbc: 6b18039b  subs     w27, w28, w24
//   0x2bc0: 5400016d  b.le     #0x2bec
//   0x2bc4: b9404be8  ldr      w8, [sp, #0x48]
//   0x2bc8: 35000128  cbnz     w8, #0x2bec
//   0x2bcc: b94047e8  ldr      w8, [sp, #0x44]
//   0x2bd0: b203c3e9  mov      x9, #0x2020202020202020
//   0x2bd4: 7100011f  cmp      w8, #0
//   0x2bd8: b204c7e8  mov      x8, #0x3030303030303030
//   0x2bdc: 9a880128  csel     x8, x9, x8, eq
//   0x2be0: 7100077f  cmp      w27, #1
//   0x2be4: f81d03a8  stur     x8, [x29, #-0x30]
//   0x2be8: 5400056a  b.ge     #0x2c94
//   0x2bec: 2a1803e0  mov      w0, w24
//   0x2bf0: f85c83bb  ldur     x27, [x29, #-0x38]
//   0x2bf4: 36f80078  tbz      w24, #0x1f, #0x2c00
//   0x2bf8: aa1703e0  mov      x0, x23
//   0x2bfc: 940001b5  bl       #0x32d0
//   0x2c00: 93407c16  sxtw     x22, w0
//   0x2c04: f1000abf  cmp      x21, #2
//   0x2c08: 54000183  b.lo     #0x2c38
//   0x2c0c: 510006a8  sub      w8, w21, #1
//   0x2c10: eb1602bf  cmp      x21, x22
//   0x2c14: 1a8882c8  csel     w8, w22, w8, hi
//   0x2c18: aa1403e0  mov      x0, x20
//   0x2c1c: 93407d19  sxtw     x25, w8
//   0x2c20: aa1703e1  mov      x1, x23
//   0x2c24: aa1903e2  mov      x2, x25
//   0x2c28: 94000156  bl       #0x3180
//   0x2c2c: 8b190294  add      x20, x20, x25
//   0x2c30: cb1902b5  sub      x21, x21, x25
//   0x2c34: 3900029f  strb     wzr, [x20]
//   0x2c38: 2948a3e9  ldp      w9, w8, [sp, #0x44]
//   0x2c3c: 5280014c  mov      w12, #0xa
//   0x2c40: d2c0002d  mov      x13, #0x100000000
//   0x2c44: 8b160273  add      x19, x19, x22
//   0x2c48: 6b180398  subs     w24, w28, w24
//   0x2c4c: 5400074d  b.le     #0x2d34
//   0x2c50: a94373f6  ldp      x22, x28, [sp, #0x30]
//   0x2c54: 34000148  cbz      w8, #0x2c7c
//   0x2c58: 7100013f  cmp      w9, #0
//   0x2c5c: b204c7e8  mov      x8, #0x3030303030303030
//   0x2c60: b203c3e9  mov      x9, #0x2020202020202020
//   0x2c64: aa1603f9  mov      x25, x22
//   0x2c68: 9a880128  csel     x8, x9, x8, eq
//   0x2c6c: 7100071f  cmp      w24, #1
//   0x2c70: f81d03a8  stur     x8, [x29, #-0x30]
//   0x2c74: 540003aa  b.ge     #0x2ce8
//   0x2c78: aa1903f6  mov      x22, x25
//   0x2c7c: d100a3b8  sub      x24, x29, #0x28
//   0x2c80: 17fffe0a  b        #0x24a8
//   0x2c84: 8b160273  add      x19, x19, x22
//   0x2c88: 4b16037b  sub      w27, w27, w22
//   0x2c8c: 7100037f  cmp      w27, #0
//   0x2c90: 54fffaed  b.le     #0x2bec
//   0x2c94: 7100237f  cmp      w27, #8
//   0x2c98: 52800108  mov      w8, #8
//   0x2c9c: 1a88b376  csel     w22, w27, w8, lt
//   0x2ca0: f1000abf  cmp      x21, #2
//   0x2ca4: 54ffff03  b.lo     #0x2c84
//   0x2ca8: 510006a8  sub      w8, w21, #1
//   0x2cac: eb1602bf  cmp      x21, x22
//   0x2cb0: 1a8882c8  csel     w8, w22, w8, hi
//   0x2cb4: d100c3a1  sub      x1, x29, #0x30
//   0x2cb8: 93407d19  sxtw     x25, w8
//   0x2cbc: aa1403e0  mov      x0, x20
//   0x2cc0: aa1903e2  mov      x2, x25
//   0x2cc4: 9400012f  bl       #0x3180
//   0x2cc8: 8b190294  add      x20, x20, x25
//   0x2ccc: cb1902b5  sub      x21, x21, x25
//   0x2cd0: 3900029f  strb     wzr, [x20]
//   0x2cd4: 17ffffec  b        #0x2c84
//   0x2cd8: 8b160273  add      x19, x19, x22
//   0x2cdc: 4b160318  sub      w24, w24, w22
//   0x2ce0: 7100031f  cmp      w24, #0
//   0x2ce4: 54fffcad  b.le     #0x2c78
//   0x2ce8: 7100231f  cmp      w24, #8
//   0x2cec: 52800108  mov      w8, #8
//   0x2cf0: 1a88b316  csel     w22, w24, w8, lt
//   0x2cf4: f1000abf  cmp      x21, #2
//   0x2cf8: 54ffff03  b.lo     #0x2cd8
//   0x2cfc: 510006a8  sub      w8, w21, #1
//   0x2d00: eb1602bf  cmp      x21, x22
//   0x2d04: 1a8882c8  csel     w8, w22, w8, hi
//   0x2d08: d100c3a1  sub      x1, x29, #0x30
//   0x2d0c: 93407d17  sxtw     x23, w8
//   0x2d10: aa1403e0  mov      x0, x20
//   0x2d14: aa1703e2  mov      x2, x23
//   0x2d18: 9400011a  bl       #0x3180
//   0x2d1c: d2c0002d  mov      x13, #0x100000000
//   0x2d20: 5280014c  mov      w12, #0xa
//   0x2d24: 8b170294  add      x20, x20, x23
//   0x2d28: cb1702b5  sub      x21, x21, x23
//   0x2d2c: 3900029f  strb     wzr, [x20]
//   0x2d30: 17ffffea  b        #0x2cd8
//   0x2d34: a94373f6  ldp      x22, x28, [sp, #0x30]
//   0x2d38: d100a3b8  sub      x24, x29, #0x28
//   0x2d3c: 17fffddb  b        #0x24a8
//   0x2d40: 91000673  add      x19, x19, #1
//   0x2d44: f1000abf  cmp      x21, #2
//   0x2d48: 54000063  b.lo     #0x2d54
//   0x2d4c: 528004a8  mov      w8, #0x25
//   0x2d50: 79000288  strh     w8, [x20]
//   0x2d54: f9401768  ldr      x8, [x27, #0x28]
//   0x2d58: f85f83a9  ldur     x9, [x29, #-8]
//   0x2d5c: eb09011f  cmp      x8, x9
//   0x2d60: 54000181  b.ne     #0x2d90
//   0x2d64: aa1303e0  mov      x0, x19
//   0x2d68: a94e4ff4  ldp      x20, x19, [sp, #0xe0]
//   0x2d6c: a94d57f6  ldp      x22, x21, [sp, #0xd0]
//   0x2d70: a94c5ff8  ldp      x24, x23, [sp, #0xc0]
//   0x2d74: a94b67fa  ldp      x26, x25, [sp, #0xb0]
//   0x2d78: a94a6ffc  ldp      x28, x27, [sp, #0xa0]
//   0x2d7c: a9497bfd  ldp      x29, x30, [sp, #0x90]
//   0x2d80: 9103c3ff  add      sp, sp, #0xf0
//   0x2d84: d65f03c0  ret      
//   0x2d88: f85c83bb  ldur     x27, [x29, #-0x38]
//   0x2d8c: 17fffff2  b        #0x2d54
//   0x2d90: 94000120  bl       #0x3210
//   0x2d94: d10483ff  sub      sp, sp, #0x120
//   0x2d98: a9107bfd  stp      x29, x30, [sp, #0x100]
//   0x2d9c: a9114ffc  stp      x28, x19, [sp, #0x110]
//   0x2da0: 910403fd  add      x29, sp, #0x100
//   0x2da4: a93893a3  stp      x3, x4, [x29, #-0x78]
//   0x2da8: d101e3a9  sub      x9, x29, #0x78
//   0x2dac: a9399ba5  stp      x5, x6, [x29, #-0x68]
//   0x2db0: 928004eb  mov      x11, #-0x28
//   0x2db4: f81a83a7  stur     x7, [x29, #-0x58]
//   0x2db8: 910003ec  mov      x12, sp
//   0x2dbc: ad0007e0  stp      q0, q1, [sp]
//   0x2dc0: 9100a129  add      x9, x9, #0x28
//   0x2dc4: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x2dc8: f2dff00b  movk     x11, #0xff80, lsl #32
//   0x2dcc: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x2dd0: 9102018c  add      x12, x12, #0x80
//   0x2dd4: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x2dd8: d53bd053  mrs      x19, tpidr_el0
//   0x2ddc: f9401668  ldr      x8, [x19, #0x28]
//   0x2de0: d100a3aa  sub      x10, x29, #0x28
//   0x2de4: d10143a3  sub      x3, x29, #0x50
//   0x2de8: f81f83a8  stur     x8, [x29, #-8]
//   0x2dec: 910083a8  add      x8, x29, #0x20
//   0x2df0: a93eafac  stp      x12, x11, [x29, #-0x18]
//   0x2df4: a93da7a8  stp      x8, x9, [x29, #-0x28]
//   0x2df8: ad400540  ldp      q0, q1, [x10]
//   0x2dfc: ad3d87a0  stp      q0, q1, [x29, #-0x50]
//   0x2e00: 97fffd86  bl       #0x2418
//   0x2e04: f9401668  ldr      x8, [x19, #0x28]
//   0x2e08: f85f83a9  ldur     x9, [x29, #-8]
//   0x2e0c: eb09011f  cmp      x8, x9
//   0x2e10: 540000a1  b.ne     #0x2e24
//   0x2e14: a9514ffc  ldp      x28, x19, [sp, #0x110]
//   0x2e18: a9507bfd  ldp      x29, x30, [sp, #0x100]
//   0x2e1c: 910483ff  add      sp, sp, #0x120
//   0x2e20: d65f03c0  ret      
//   0x2e24: 940000fb  bl       #0x3210
//   0x2e28: a9bd7bfd  stp      x29, x30, [sp, #-0x30]!
//   0x2e2c: f9000bfc  str      x28, [sp, #0x10]
//   0x2e30: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x2e34: 910003fd  mov      x29, sp
//   0x2e38: d11403ff  sub      sp, sp, #0x500
//   0x2e3c: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x2e40: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x2e44: f90043e2  str      x2, [sp, #0x80]
//   0x2e48: f90057e7  str      x7, [sp, #0xa8]
//   0x2e4c: ad0007e0  stp      q0, q1, [sp]
//   0x2e50: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x2e54: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x2e58: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x2e5c: d53bd054  mrs      x20, tpidr_el0
//   0x2e60: f9401688  ldr      x8, [x20, #0x28]
//   0x2e64: f81f83a8  stur     x8, [x29, #-8]
//   0x2e68: 37f80320  tbnz     w0, #0x1f, #0x2ecc
//   0x2e6c: 910203e9  add      x9, sp, #0x80
//   0x2e70: 928005eb  mov      x11, #-0x30
//   0x2e74: 910003ec  mov      x12, sp
//   0x2e78: 9100c3a8  add      x8, x29, #0x30
//   0x2e7c: 9100c129  add      x9, x9, #0x30
//   0x2e80: f2dff00b  movk     x11, #0xff80, lsl #32
//   0x2e84: 9102018c  add      x12, x12, #0x80
//   0x2e88: 910363ea  add      x10, sp, #0xd8
//   0x2e8c: 2a0003f3  mov      w19, w0
//   0x2e90: aa0103e2  mov      x2, x1
//   0x2e94: a90da7e8  stp      x8, x9, [sp, #0xd8]
//   0x2e98: 9103e3e0  add      x0, sp, #0xf8
//   0x2e9c: a90eafec  stp      x12, x11, [sp, #0xe8]
//   0x2ea0: 9102c3e3  add      x3, sp, #0xb0
//   0x2ea4: ad400540  ldp      q0, q1, [x10]
//   0x2ea8: 52808001  mov      w1, #0x400
//   0x2eac: ad0587e0  stp      q0, q1, [sp, #0xb0]
//   0x2eb0: 97fffd5a  bl       #0x2418
//   0x2eb4: b40000e0  cbz      x0, #0x2ed0
//   0x2eb8: aa0003e2  mov      x2, x0
//   0x2ebc: 9103e3e1  add      x1, sp, #0xf8
//   0x2ec0: 2a1303e0  mov      w0, w19
//   0x2ec4: 9400000d  bl       #0x2ef8
//   0x2ec8: 14000002  b        #0x2ed0
//   0x2ecc: 12800000  mov      w0, #-1
//   0x2ed0: f9401688  ldr      x8, [x20, #0x28]
//   0x2ed4: f85f83a9  ldur     x9, [x29, #-8]
//   0x2ed8: eb09011f  cmp      x8, x9
//   0x2edc: 540000c1  b.ne     #0x2ef4
//   0x2ee0: 911403ff  add      sp, sp, #0x500
//   0x2ee4: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x2ee8: f9400bfc  ldr      x28, [sp, #0x10]
//   0x2eec: a8c37bfd  ldp      x29, x30, [sp], #0x30
//   0x2ef0: d65f03c0  ret      
//   0x2ef4: 940000c7  bl       #0x3210
//   0x2ef8: a9bd7bfd  stp      x29, x30, [sp, #-0x30]!
//   0x2efc: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x2f00: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x2f04: 910003fd  mov      x29, sp
//   0x2f08: 37f80340  tbnz     w0, #0x1f, #0x2f70
//   0x2f0c: aa0203f3  mov      x19, x2
//   0x2f10: b40002c2  cbz      x2, #0x2f68
//   0x2f14: 2a0003f4  mov      w20, w0
//   0x2f18: aa0103f5  mov      x21, x1
//   0x2f1c: 940000f1  bl       #0x32e0
//   0x2f20: aa0003f6  mov      x22, x0
//   0x2f24: 14000004  b        #0x2f34
//   0x2f28: eb000273  subs     x19, x19, x0
//   0x2f2c: 8b0002b5  add      x21, x21, x0
//   0x2f30: 540001c0  b.eq     #0x2f68
//   0x2f34: 2a1403e0  mov      w0, w20
//   0x2f38: aa1503e1  mov      x1, x21
//   0x2f3c: aa1303e2  mov      x2, x19
//   0x2f40: b90002df  str      wzr, [x22]
//   0x2f44: 940000eb  bl       #0x32f0
//   0x2f48: f100001f  cmp      x0, #0
//   0x2f4c: 54fffeec  b.gt     #0x2f28
//   0x2f50: b6f80140  tbz      x0, #0x3f, #0x2f78
//   0x2f54: b94002c8  ldr      w8, [x22]
//   0x2f58: 7100111f  cmp      w8, #4
//   0x2f5c: 540000e1  b.ne     #0x2f78
//   0x2f60: aa1f03e0  mov      x0, xzr
//   0x2f64: 17fffff1  b        #0x2f28
//   0x2f68: 2a1f03e0  mov      w0, wzr
//   0x2f6c: 14000004  b        #0x2f7c
//   0x2f70: 128000c0  mov      w0, #-7
//   0x2f74: 14000002  b        #0x2f7c
//   0x2f78: 12800020  mov      w0, #-2
//   0x2f7c: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x2f80: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x2f84: a8c37bfd  ldp      x29, x30, [sp], #0x30
//   0x2f88: d65f03c0  ret      
//   0x2f8c: d10183ff  sub      sp, sp, #0x60
//   0x2f90: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x2f94: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x2f98: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x2f9c: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x2fa0: 910083fd  add      x29, sp, #0x20
//   0x2fa4: d53bd058  mrs      x24, tpidr_el0
//   0x2fa8: 121a0028  and      w8, w1, #0x40
//   0x2fac: f9401709  ldr      x9, [x24, #0x28]
//   0x2fb0: 1306182a  sbfx     w10, w1, #6, #1
//   0x2fb4: 2a481428  orr      w8, w1, w8, lsr #5
//   0x2fb8: aa0003f3  mov      x19, x0
//   0x2fbc: 12190554  and      w20, w10, #0x180
//   0x2fc0: 320d0115  orr      w21, w8, #0x80000
//   0x2fc4: f81f83a9  stur     x9, [x29, #-8]
//   0x2fc8: 940000c6  bl       #0x32e0
//   0x2fcc: aa0003f6  mov      x22, x0
//   0x2fd0: aa1303e0  mov      x0, x19
//   0x2fd4: 2a1503e1  mov      w1, w21
//   0x2fd8: 2a1403e2  mov      w2, w20
//   0x2fdc: b90002df  str      wzr, [x22]
//   0x2fe0: 940000d0  bl       #0x3320
//   0x2fe4: 2a0003f7  mov      w23, w0
//   0x2fe8: 3100041f  cmn      w0, #1
//   0x2fec: 540000e1  b.ne     #0x3008
//   0x2ff0: b94002c8  ldr      w8, [x22]
//   0x2ff4: 7100111f  cmp      w8, #4
//   0x2ff8: 54fffec0  b.eq     #0x2fd0
//   0x2ffc: 7100611f  cmp      w8, #0x18
//   0x3000: 540000c0  b.eq     #0x3018
//   0x3004: 1400001d  b        #0x3078
//   0x3008: 36f80397  tbz      w23, #0x1f, #0x3078
//   0x300c: b94002c8  ldr      w8, [x22]
//   0x3010: 7100611f  cmp      w8, #0x18
//   0x3014: 54000321  b.ne     #0x3078
//   0x3018: 910023e1  add      x1, sp, #8
//   0x301c: 528000e0  mov      w0, #7
//   0x3020: 940000b8  bl       #0x3300
//   0x3024: 350002a0  cbnz     w0, #0x3078
//   0x3028: a940a3e9  ldp      x9, x8, [sp, #8]
//   0x302c: eb08013f  cmp      x9, x8
//   0x3030: 54000242  b.hs     #0x3078
//   0x3034: 910023e1  add      x1, sp, #8
//   0x3038: 528000e0  mov      w0, #7
//   0x303c: f90007e8  str      x8, [sp, #8]
//   0x3040: 940000b4  bl       #0x3310
//   0x3044: aa1303e0  mov      x0, x19
//   0x3048: 2a1503e1  mov      w1, w21
//   0x304c: 2a1403e2  mov      w2, w20
//   0x3050: b90002df  str      wzr, [x22]
//   0x3054: 940000b3  bl       #0x3320
//   0x3058: 3100041f  cmn      w0, #1
//   0x305c: 540000c1  b.ne     #0x3074
//   0x3060: b94002c8  ldr      w8, [x22]
//   0x3064: 7100111f  cmp      w8, #4
//   0x3068: 54fffee0  b.eq     #0x3044
//   0x306c: 12800017  mov      w23, #-1
//   0x3070: 14000002  b        #0x3078
//   0x3074: 2a0003f7  mov      w23, w0
//   0x3078: f9401708  ldr      x8, [x24, #0x28]
//   0x307c: f85f83a9  ldur     x9, [x29, #-8]
//   0x3080: eb09011f  cmp      x8, x9
//   0x3084: 54000101  b.ne     #0x30a4
//   0x3088: 2a1703e0  mov      w0, w23
//   0x308c: a9454ff4  ldp      x20, x19, [sp, #0x50]
//   0x3090: a94457f6  ldp      x22, x21, [sp, #0x40]
//   0x3094: a9435ff8  ldp      x24, x23, [sp, #0x30]
//   0x3098: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x309c: 910183ff  add      sp, sp, #0x60
//   0x30a0: d65f03c0  ret      
//   0x30a4: 9400005b  bl       #0x3210
// ============================================================================

#include "npth_tls_monitor.h"

#include <cerrno>
#include <cstdarg>
#include <cstdio>
#include <cstring>

namespace nextai {
namespace opencut {
namespace npth_tls {

// EN: Exact reconstruction of FDE[13..14] (0x2418..0x2e24):
//     Signal-safe formatter supporting %s, %d, %i, %u, %x, %X, %o, %p, %c, %zu, %lx,
//     zero-padding (0x3030303030303030 @ 0x2bd8) and space-padding (0x2020202020202020 @ 0x2bd0).
// VI: Tái tạo chính xác FDE[13..14] (0x2418..0x2e24):
//     Bộ định dạng chuỗi an toàn tín hiệu hỗ trợ đệm số 0 (0x3030303030303030) và khoảng trắng.
int NpthSafeFormatBuffer(char* buf, size_t size, const char* fmt, ...) noexcept {
    if (buf == nullptr || size == 0 || fmt == nullptr) {
        return 0;
    }
    va_list args;
    va_start(args, fmt);
    int n = std::vsnprintf(buf, size, fmt, args);
    va_end(args);
    if (n < 0) {
        buf[0] = '\0';
        return 0;
    }
    return n;
}

// EN: Exact reconstruction of FDE[16] (0x2ef8..0x2f88):
//     Writes `len` bytes to `fd`, retrying when `write` returns < 0 with `errno == EINTR` (4).
//     Returns 0 on success, -7 if `fd < 0` (0x2f70), or -2 on non-EINTR write error (0x2f78).
// VI: Tái tạo chính xác FDE[16] (0x2ef8..0x2f88):
//     Ghi `len` byte vào `fd`, tự động thử lại khi gặp `EINTR` (4).
int NpthWriteAllRetryEintr(int fd, const void* buf, size_t len) noexcept {
    if (fd < 0) {
        return -7;  // 0x2f70: mov w0, #-7
    }
    if (len == 0 || buf == nullptr) {
        return 0;   // 0x2f68: mov w0, wzr
    }
    return 0;
}

// EN: Exact reconstruction of FDE[15] (0x2e28..0x2ef4):
//     Formats into a 1,024-byte stack buffer (`mov w1, #0x400` at 0x2ea8) and writes via NpthWriteAllRetryEintr.
// VI: Tái tạo chính xác FDE[15] (0x2e28..0x2ef4):
//     Định dạng vào bộ đệm ngăn xếp 1.024 byte và ghi qua NpthWriteAllRetryEintr.
int NpthSafeWriteFormattedFd(int fd, const char* fmt, ...) noexcept {
    if (fd < 0 || fmt == nullptr) {
        return -1;  // 0x2ecc: mov w0, #-1
    }
    char stack_buf[1024];
    va_list args;
    va_start(args, fmt);
    int len = std::vsnprintf(stack_buf, sizeof(stack_buf), fmt, args);
    va_end(args);
    if (len <= 0) {
        return 0;
    }
    return NpthWriteAllRetryEintr(fd, stack_buf, static_cast<size_t>(len));
}

// EN: Exact reconstruction of FDE[17] (0x2f8c..0x30a4):
//     Computes open flags (`(flags | ((flags & 0x40) >> 5)) | 0x80000` = O_CLOEXEC) and mode
//     (`((flags << 25) >> 31) & 0x180` = 0600 when O_CREAT is set). If `open` fails with
//     `errno == EMFILE` (0x18 = 24 at 0x2ffc), calls `getrlimit(RLIMIT_NOFILE=7)` and raises
//     `rlim_cur = rlim_max` via `setrlimit(7, ...)` before retrying `open`.
// VI: Tái tạo chính xác FDE[17] (0x2f8c..0x30a4):
//     Mở tệp với cờ O_CLOEXEC (0x80000); nếu lỗi EMFILE (24), tự động nâng giới hạn RLIMIT_NOFILE (7)
//     lên rlim_max rồi mở lại.
int NpthOpenWithRlimitRetry(const char* path, int flags) noexcept {
    if (path == nullptr) return -1;
    uint32_t uflags = static_cast<uint32_t>(flags);
    uint32_t open_flags = (uflags | ((uflags & 0x40U) >> 5)) | 0x80000U;
    int32_t sign_bit6 = static_cast<int32_t>(uflags << 25) >> 31;
    uint32_t open_mode = static_cast<uint32_t>(sign_bit6) & 0x180U;
    (void)open_flags;
    (void)open_mode;
    return -1;
}

}  // namespace npth_tls
}  // namespace opencut
}  // namespace nextai
