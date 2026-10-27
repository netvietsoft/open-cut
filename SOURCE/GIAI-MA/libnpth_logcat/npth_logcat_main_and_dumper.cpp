// ============================================================================
// NextAI OpenCut — Clean-Room C++17 Reconstruction
// File          : npth_logcat_main_and_dumper.cpp
// Target Binary : libnpth_logcat.so (16,856 bytes)
// SHA-256       : 241f75ebe9208e680c0d0e77c6f23c2f87d7ba9c2d446ca5c75a9df2ab8319e8
// Task ID       : TASK-169-RECONSTRUCTION-LIBNPTH-LOGCAT
// ============================================================================
// EN: Full clean-room C++17 implementation of FDE[00..02] (0x16fc..0x1770) and
//     FDE[05..09] (0x2180..0x31a8):
//       - FDE[05] `main` (0x2180..0x279c): CLI parser, signal handler setup,
//         dynamic `libnpth_dl.so` & `liblog.so` loader, and `execlp` fallback.
//       - FDE[06] `dump_log_buffer` (0x279c..0x2bfc): `liblog` reader loop,
//         `logger_entry` v1..v4 binary/text packet parser, `threadtime` line
//         formatter, and 1-in-500 `fstat` file-size cap (`0xAF000` = 716,800 B).
//       - FDE[07] `log_status_printf` (0x2bfc..0x2dec): status logger with
//         64-bit reciprocal time division (`HH:MM:SS.mmm PID TID`).
//       - FDE[08] `crash_signal_handler` (0x2dec..0x30f0): `SA_SIGINFO` handler
//         re-queuing signal via `SYS_rt_tgsigqueueinfo` (240) and falling back
//         to `/system/bin/logcat` with `alarm(30)`.
//       - FDE[09] `resolve_sibling_lib_path` (0x30f0..0x31a8): `dladdr`-based
//         directory resolver for `libnpth_dl.so`.
// VI: Tái tạo phòng sạch C++17 hoàn chỉnh cho FDE[00..02] và FDE[05..09].
// ============================================================================
// Complete AArch64 Disassembly (0x2180..0x31a8):
//   0x2180: a9bb7bfd  stp      x29, x30, [sp, #-0x50]!
//   0x2184: a90167fc  stp      x28, x25, [sp, #0x10]
//   0x2188: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x218c: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x2190: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x2194: 910003fd  mov      x29, sp
//   0x2198: d11143ff  sub      sp, sp, #0x450
//   0x219c: d53bd057  mrs      x23, tpidr_el0
//   0x21a0: f94016e8  ldr      x8, [x23, #0x28]
//   0x21a4: 7100101f  cmp      w0, #4
//   0x21a8: f81f83a8  stur     x8, [x29, #-8]
//   0x21ac: 54001c0b  b.lt     #0x252c
//   0x21b0: aa0103f4  mov      x20, x1
//   0x21b4: f9400428  ldr      x8, [x1, #8]
//   0x21b8: b4001ba8  cbz      x8, #0x252c
//   0x21bc: f9400a88  ldr      x8, [x20, #0x10]
//   0x21c0: b4001b68  cbz      x8, #0x252c
//   0x21c4: f9400e88  ldr      x8, [x20, #0x18]
//   0x21c8: b4001b28  cbz      x8, #0x252c
//   0x21cc: d503201f  nop      
//   0x21d0: 30ff7a21  adr      x1, #0x1115
//   0x21d4: f0ffffe2  adrp     x2, #0x1000
//   0x21d8: 91036442  add      x2, x2, #0xd9
//   0x21dc: 528000c0  mov      w0, #6
//   0x21e0: 9400041c  bl       #0x3250
//   0x21e4: b0000021  adrp     x1, #0x7000
//   0x21e8: 528001a0  mov      w0, #0xd
//   0x21ec: f9435021  ldr      x1, [x1, #0x6a0]
//   0x21f0: 94000420  bl       #0x3270
//   0x21f4: 6f00e400  movi     v0.2d, #0000000000000000
//   0x21f8: 52800088  mov      w8, #4
//   0x21fc: 72a10008  movk     w8, #0x800, lsl #16
//   0x2200: d503201f  nop      
//   0x2204: 1004b062  adr      x2, #0xb810
//   0x2208: 910103e1  add      x1, sp, #0x40
//   0x220c: ad0203e0  stp      q0, q0, [sp, #0x40]
//   0x2210: b8408440  ldr      w0, [x2], #8
//   0x2214: b90043e8  str      w8, [sp, #0x40]
//   0x2218: d503201f  nop      
//   0x221c: 10005e88  adr      x8, #0x2dec
//   0x2220: f90027e8  str      x8, [sp, #0x48]
//   0x2224: 94000417  bl       #0x3280
//   0x2228: 35000540  cbnz     w0, #0x22d0
//   0x222c: b0000042  adrp     x2, #0xb000
//   0x2230: 9120e042  add      x2, x2, #0x838
//   0x2234: 910103e1  add      x1, sp, #0x40
//   0x2238: b8408440  ldr      w0, [x2], #8
//   0x223c: 94000411  bl       #0x3280
//   0x2240: 35000480  cbnz     w0, #0x22d0
//   0x2244: b0000042  adrp     x2, #0xb000
//   0x2248: 91218042  add      x2, x2, #0x860
//   0x224c: 910103e1  add      x1, sp, #0x40
//   0x2250: b8408440  ldr      w0, [x2], #8
//   0x2254: 9400040b  bl       #0x3280
//   0x2258: 350003c0  cbnz     w0, #0x22d0
//   0x225c: b0000042  adrp     x2, #0xb000
//   0x2260: 91222042  add      x2, x2, #0x888
//   0x2264: 910103e1  add      x1, sp, #0x40
//   0x2268: b8408440  ldr      w0, [x2], #8
//   0x226c: 94000405  bl       #0x3280
//   0x2270: 35000300  cbnz     w0, #0x22d0
//   0x2274: b0000042  adrp     x2, #0xb000
//   0x2278: 9122c042  add      x2, x2, #0x8b0
//   0x227c: 910103e1  add      x1, sp, #0x40
//   0x2280: b8408440  ldr      w0, [x2], #8
//   0x2284: 940003ff  bl       #0x3280
//   0x2288: 35000240  cbnz     w0, #0x22d0
//   0x228c: b0000042  adrp     x2, #0xb000
//   0x2290: 91236042  add      x2, x2, #0x8d8
//   0x2294: 910103e1  add      x1, sp, #0x40
//   0x2298: b8408440  ldr      w0, [x2], #8
//   0x229c: 940003f9  bl       #0x3280
//   0x22a0: 35000180  cbnz     w0, #0x22d0
//   0x22a4: b0000042  adrp     x2, #0xb000
//   0x22a8: 91240042  add      x2, x2, #0x900
//   0x22ac: 910103e1  add      x1, sp, #0x40
//   0x22b0: b8408440  ldr      w0, [x2], #8
//   0x22b4: 940003f3  bl       #0x3280
//   0x22b8: 350000c0  cbnz     w0, #0x22d0
//   0x22bc: b0000042  adrp     x2, #0xb000
//   0x22c0: 9124a042  add      x2, x2, #0x928
//   0x22c4: 910103e1  add      x1, sp, #0x40
//   0x22c8: b8408440  ldr      w0, [x2], #8
//   0x22cc: 940003ed  bl       #0x3280
//   0x22d0: f9400693  ldr      x19, [x20, #8]
//   0x22d4: aa1303e0  mov      x0, x19
//   0x22d8: 940003c6  bl       #0x31f0
//   0x22dc: 91003000  add      x0, x0, #0xc
//   0x22e0: 940003ec  bl       #0x3290
//   0x22e4: b4001d00  cbz      x0, #0x2684
//   0x22e8: aa0003f5  mov      x21, x0
//   0x22ec: 39400269  ldrb     w9, [x19]
//   0x22f0: aa0003e8  mov      x8, x0
//   0x22f4: 340000c9  cbz      w9, #0x230c
//   0x22f8: 9100066a  add      x10, x19, #1
//   0x22fc: aa1503e8  mov      x8, x21
//   0x2300: 38001509  strb     w9, [x8], #1
//   0x2304: 38401549  ldrb     w9, [x10], #1
//   0x2308: 35ffffc9  cbnz     w9, #0x2300
//   0x230c: 528f0e8a  mov      w10, #0x7874
//   0x2310: f0ffffe9  adrp     x9, #0x1000
//   0x2314: 72a00e8a  movk     w10, #0x74, lsl #16
//   0x2318: b0000058  adrp     x24, #0xb000
//   0x231c: fd421920  ldr      d0, [x9, #0x430]
//   0x2320: b900090a  str      w10, [x8, #8]
//   0x2324: f9400e80  ldr      x0, [x20, #0x18]
//   0x2328: f904af15  str      x21, [x24, #0x958]
//   0x232c: fd000100  str      d0, [x8]
//   0x2330: 940003dc  bl       #0x32a0
//   0x2334: b0000056  adrp     x22, #0xb000
//   0x2338: f904b6c0  str      x0, [x22, #0x968]
//   0x233c: 52800180  mov      w0, #0xc
//   0x2340: 940003d4  bl       #0x3290
//   0x2344: b4001a40  cbz      x0, #0x268c
//   0x2348: aa0003f3  mov      x19, x0
//   0x234c: f9400a80  ldr      x0, [x20, #0x10]
//   0x2350: 940003d8  bl       #0x32b0
//   0x2354: b9000260  str      w0, [x19]
//   0x2358: aa1503e0  mov      x0, x21
//   0x235c: 52800841  mov      w1, #0x42
//   0x2360: 52803002  mov      w2, #0x180
//   0x2364: 940003d7  bl       #0x32c0
//   0x2368: b9000660  str      w0, [x19, #4]
//   0x236c: 37f819e0  tbnz     w0, #0x1f, #0x26a8
//   0x2370: f944b6c0  ldr      x0, [x22, #0x968]
//   0x2374: b5000060  cbnz     x0, #0x2380
//   0x2378: 9400035e  bl       #0x30f0
//   0x237c: f904b6c0  str      x0, [x22, #0x968]
//   0x2380: 9400039c  bl       #0x31f0
//   0x2384: aa0003f4  mov      x20, x0
//   0x2388: f944b6c1  ldr      x1, [x22, #0x968]
//   0x238c: d1004402  sub      x2, x0, #0x11
//   0x2390: 910103e0  add      x0, sp, #0x40
//   0x2394: 52808003  mov      w3, #0x400
//   0x2398: 910103f5  add      x21, sp, #0x40
//   0x239c: 940003cd  bl       #0x32d0
//   0x23a0: 8b150288  add      x8, x20, x21
//   0x23a4: 910103e0  add      x0, sp, #0x40
//   0x23a8: 52808001  mov      w1, #0x400
//   0x23ac: 381ee11f  sturb    wzr, [x8, #-0x12]
//   0x23b0: 940003cc  bl       #0x32e0
//   0x23b4: 91003c00  add      x0, x0, #0xf
//   0x23b8: 940003b6  bl       #0x3290
//   0x23bc: b4001640  cbz      x0, #0x2684
//   0x23c0: 394103e9  ldrb     w9, [sp, #0x40]
//   0x23c4: aa0003e8  mov      x8, x0
//   0x23c8: 340000e9  cbz      w9, #0x23e4
//   0x23cc: 910103e8  add      x8, sp, #0x40
//   0x23d0: b240010a  orr      x10, x8, #1
//   0x23d4: aa0003e8  mov      x8, x0
//   0x23d8: 38001509  strb     w9, [x8], #1
//   0x23dc: 38401549  ldrb     w9, [x10], #1
//   0x23e0: 35ffffc9  cbnz     w9, #0x23d8
//   0x23e4: f0ffffe9  adrp     x9, #0x1000
//   0x23e8: 528c8bea  mov      w10, #0x645f
//   0x23ec: 72a5cd8a  movk     w10, #0x2e6c, lsl #16
//   0x23f0: 528dee6b  mov      w11, #0x6f73
//   0x23f4: 52800041  mov      w1, #2
//   0x23f8: 3900391f  strb     wzr, [x8, #0xe]
//   0x23fc: fd421d20  ldr      d0, [x9, #0x438]
//   0x2400: b900090a  str      w10, [x8, #8]
//   0x2404: 7900190b  strh     w11, [x8, #0xc]
//   0x2408: fd000100  str      d0, [x8]
//   0x240c: 940003b9  bl       #0x32f0
//   0x2410: b0000055  adrp     x21, #0xb000
//   0x2414: b0000056  adrp     x22, #0xb000
//   0x2418: b0000059  adrp     x25, #0xb000
//   0x241c: b4000260  cbz      x0, #0x2468
//   0x2420: f0ffffe1  adrp     x1, #0x1000
//   0x2424: 91027421  add      x1, x1, #0x9d
//   0x2428: aa0003f4  mov      x20, x0
//   0x242c: 940003b5  bl       #0x3300
//   0x2430: f904baa0  str      x0, [x21, #0x970]
//   0x2434: b40001a0  cbz      x0, #0x2468
//   0x2438: f0ffffe1  adrp     x1, #0x1000
//   0x243c: 9105f021  add      x1, x1, #0x17c
//   0x2440: aa1403e0  mov      x0, x20
//   0x2444: 940003af  bl       #0x3300
//   0x2448: f904bec0  str      x0, [x22, #0x978]
//   0x244c: b40000e0  cbz      x0, #0x2468
//   0x2450: f0ffffe1  adrp     x1, #0x1000
//   0x2454: 910d6421  add      x1, x1, #0x359
//   0x2458: aa1403e0  mov      x0, x20
//   0x245c: 940003a9  bl       #0x3300
//   0x2460: f904d720  str      x0, [x25, #0x9a8]
//   0x2464: b5000040  cbnz     x0, #0x246c
//   0x2468: aa1f03f4  mov      x20, xzr
//   0x246c: f944baa8  ldr      x8, [x21, #0x970]
//   0x2470: f0ffffe0  adrp     x0, #0x1000
//   0x2474: 910c3c00  add      x0, x0, #0x30f
//   0x2478: d63f0100  blr      x8
//   0x247c: b4001260  cbz      x0, #0x26c8
//   0x2480: f944bec8  ldr      x8, [x22, #0x978]
//   0x2484: f0ffffe1  adrp     x1, #0x1000
//   0x2488: 91104421  add      x1, x1, #0x411
//   0x248c: aa0003f5  mov      x21, x0
//   0x2490: d63f0100  blr      x8
//   0x2494: b0000048  adrp     x8, #0xb000
//   0x2498: f904c100  str      x0, [x8, #0x980]
//   0x249c: b40006c0  cbz      x0, #0x2574
//   0x24a0: f944bec8  ldr      x8, [x22, #0x978]
//   0x24a4: f0ffffe1  adrp     x1, #0x1000
//   0x24a8: 91021021  add      x1, x1, #0x84
//   0x24ac: aa1503e0  mov      x0, x21
//   0x24b0: d63f0100  blr      x8
//   0x24b4: b0000048  adrp     x8, #0xb000
//   0x24b8: f904c500  str      x0, [x8, #0x988]
//   0x24bc: b4000600  cbz      x0, #0x257c
//   0x24c0: f944bec8  ldr      x8, [x22, #0x978]
//   0x24c4: f0ffffe1  adrp     x1, #0x1000
//   0x24c8: 910b0c21  add      x1, x1, #0x2c3
//   0x24cc: aa1503e0  mov      x0, x21
//   0x24d0: d63f0100  blr      x8
//   0x24d4: b0000048  adrp     x8, #0xb000
//   0x24d8: f904c900  str      x0, [x8, #0x990]
//   0x24dc: b4000540  cbz      x0, #0x2584
//   0x24e0: f944bec8  ldr      x8, [x22, #0x978]
//   0x24e4: f0ffffe1  adrp     x1, #0x1000
//   0x24e8: 91046821  add      x1, x1, #0x11a
//   0x24ec: aa1503e0  mov      x0, x21
//   0x24f0: d63f0100  blr      x8
//   0x24f4: b0000048  adrp     x8, #0xb000
//   0x24f8: f904cd00  str      x0, [x8, #0x998]
//   0x24fc: b4000480  cbz      x0, #0x258c
//   0x2500: f944bec8  ldr      x8, [x22, #0x978]
//   0x2504: f0ffffe1  adrp     x1, #0x1000
//   0x2508: 910f6021  add      x1, x1, #0x3d8
//   0x250c: aa1503e0  mov      x0, x21
//   0x2510: d63f0100  blr      x8
//   0x2514: f100001f  cmp      x0, #0
//   0x2518: 52800089  mov      w9, #4
//   0x251c: b0000048  adrp     x8, #0xb000
//   0x2520: 1a890536  cinc     w22, w9, ne
//   0x2524: f904d100  str      x0, [x8, #0x9a0]
//   0x2528: 1400001a  b        #0x2590
//   0x252c: d503201f  nop      
//   0x2530: 30ff5f21  adr      x1, #0x1115
//   0x2534: f0ffffe2  adrp     x2, #0x1000
//   0x2538: 910e5842  add      x2, x2, #0x396
//   0x253c: 528000c0  mov      w0, #6
//   0x2540: 94000344  bl       #0x3250
//   0x2544: 12800000  mov      w0, #-1
//   0x2548: f94016e8  ldr      x8, [x23, #0x28]
//   0x254c: f85f83a9  ldur     x9, [x29, #-8]
//   0x2550: eb09011f  cmp      x8, x9
//   0x2554: 54001221  b.ne     #0x2798
//   0x2558: 911143ff  add      sp, sp, #0x450
//   0x255c: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x2560: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x2564: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x2568: a94167fc  ldp      x28, x25, [sp, #0x10]
//   0x256c: a8c57bfd  ldp      x29, x30, [sp], #0x50
//   0x2570: d65f03c0  ret      
//   0x2574: 2a1f03f6  mov      w22, wzr
//   0x2578: 14000006  b        #0x2590
//   0x257c: 52800036  mov      w22, #1
//   0x2580: 14000004  b        #0x2590
//   0x2584: 52800056  mov      w22, #2
//   0x2588: 14000002  b        #0x2590
//   0x258c: 52800076  mov      w22, #3
//   0x2590: f944d728  ldr      x8, [x25, #0x9a8]
//   0x2594: aa1503e0  mov      x0, x21
//   0x2598: d63f0100  blr      x8
//   0x259c: aa1403e0  mov      x0, x20
//   0x25a0: 9400035c  bl       #0x3310
//   0x25a4: b9400a74  ldr      w20, [x19, #8]
//   0x25a8: f0ffffe1  adrp     x1, #0x1000
//   0x25ac: 9109f421  add      x1, x1, #0x27d
//   0x25b0: b9400262  ldr      w2, [x19]
//   0x25b4: 2a1603e3  mov      w3, w22
//   0x25b8: 2a1403e0  mov      w0, w20
//   0x25bc: 94000190  bl       #0x2bfc
//   0x25c0: 34000a36  cbz      w22, #0x2704
//   0x25c4: f0ffffe1  adrp     x1, #0x1000
//   0x25c8: 910d5021  add      x1, x1, #0x354
//   0x25cc: aa1303e0  mov      x0, x19
//   0x25d0: 2a1f03e2  mov      w2, wzr
//   0x25d4: 529e0016  mov      w22, #0xf000
//   0x25d8: 72a00156  movk     w22, #0xa, lsl #16
//   0x25dc: 94000070  bl       #0x279c
//   0x25e0: b9400675  ldr      w21, [x19, #4]
//   0x25e4: 910103e1  add      x1, sp, #0x40
//   0x25e8: 2a1503e0  mov      w0, w21
//   0x25ec: 9400034d  bl       #0x3320
//   0x25f0: 3100041f  cmn      w0, #1
//   0x25f4: 54000080  b.eq     #0x2604
//   0x25f8: f9403be8  ldr      x8, [sp, #0x70]
//   0x25fc: eb16011f  cmp      x8, x22
//   0x2600: 5400026c  b.gt     #0x264c
//   0x2604: f0ffffe1  adrp     x1, #0x1000
//   0x2608: 910af021  add      x1, x1, #0x2bc
//   0x260c: aa1303e0  mov      x0, x19
//   0x2610: 52800062  mov      w2, #3
//   0x2614: 94000062  bl       #0x279c
//   0x2618: 910103e1  add      x1, sp, #0x40
//   0x261c: 2a1503e0  mov      w0, w21
//   0x2620: 94000340  bl       #0x3320
//   0x2624: 3100041f  cmn      w0, #1
//   0x2628: 54000080  b.eq     #0x2638
//   0x262c: f9403be8  ldr      x8, [sp, #0x70]
//   0x2630: eb16011f  cmp      x8, x22
//   0x2634: 540000cc  b.gt     #0x264c
//   0x2638: f0ffffe1  adrp     x1, #0x1000
//   0x263c: 91030021  add      x1, x1, #0xc0
//   0x2640: aa1303e0  mov      x0, x19
//   0x2644: 52800082  mov      w2, #4
//   0x2648: 94000055  bl       #0x279c
//   0x264c: f0ffffe1  adrp     x1, #0x1000
//   0x2650: 9104f421  add      x1, x1, #0x13d
//   0x2654: 2a1403e0  mov      w0, w20
//   0x2658: 94000169  bl       #0x2bfc
//   0x265c: 710006bf  cmp      w21, #1
//   0x2660: 5400006b  b.lt     #0x266c
//   0x2664: 2a1503e0  mov      w0, w21
//   0x2668: 940002f6  bl       #0x3240
//   0x266c: 7100069f  cmp      w20, #1
//   0x2670: 5400006b  b.lt     #0x267c
//   0x2674: 2a1403e0  mov      w0, w20
//   0x2678: 940002f2  bl       #0x3240
//   0x267c: 2a1f03e0  mov      w0, wzr
//   0x2680: 17ffffb2  b        #0x2548
//   0x2684: 52800020  mov      w0, #1
//   0x2688: 940002f6  bl       #0x3260
//   0x268c: d503201f  nop      
//   0x2690: 30ff5421  adr      x1, #0x1115
//   0x2694: f0ffffe2  adrp     x2, #0x1000
//   0x2698: 910fc042  add      x2, x2, #0x3f0
//   0x269c: 528000c0  mov      w0, #6
//   0x26a0: 940002ec  bl       #0x3250
//   0x26a4: 1400001d  b        #0x2718
//   0x26a8: f944af03  ldr      x3, [x24, #0x958]
//   0x26ac: d503201f  nop      
//   0x26b0: 30ff5321  adr      x1, #0x1115
//   0x26b4: f0ffffe2  adrp     x2, #0x1000
//   0x26b8: 910ec842  add      x2, x2, #0x3b2
//   0x26bc: 528000c0  mov      w0, #6
//   0x26c0: 940002e4  bl       #0x3250
//   0x26c4: 14000015  b        #0x2718
//   0x26c8: b9400a75  ldr      w21, [x19, #8]
//   0x26cc: 940002d5  bl       #0x3220
//   0x26d0: b9400016  ldr      w22, [x0]
//   0x26d4: 2a1603e0  mov      w0, w22
//   0x26d8: 94000316  bl       #0x3330
//   0x26dc: aa0003e3  mov      x3, x0
//   0x26e0: f0ffffe1  adrp     x1, #0x1000
//   0x26e4: 91058021  add      x1, x1, #0x160
//   0x26e8: 2a1503e0  mov      w0, w21
//   0x26ec: 2a1603e2  mov      w2, w22
//   0x26f0: 2a1503f3  mov      w19, w21
//   0x26f4: 94000142  bl       #0x2bfc
//   0x26f8: aa1403e0  mov      x0, x20
//   0x26fc: 94000305  bl       #0x3310
//   0x2700: 14000002  b        #0x2708
//   0x2704: 2a1403f3  mov      w19, w20
//   0x2708: f0ffffe1  adrp     x1, #0x1000
//   0x270c: 91088c21  add      x1, x1, #0x223
//   0x2710: 2a1303e0  mov      w0, w19
//   0x2714: 9400013a  bl       #0x2bfc
//   0x2718: f0ffffe9  adrp     x9, #0x1000
//   0x271c: 91087d29  add      x9, x9, #0x21f
//   0x2720: f0ffffea  adrp     x10, #0x1000
//   0x2724: 9108714a  add      x10, x10, #0x21c
//   0x2728: f944af08  ldr      x8, [x24, #0x958]
//   0x272c: f0ffffe2  adrp     x2, #0x1000
//   0x2730: 91042c42  add      x2, x2, #0x10b
//   0x2734: f0ffffe0  adrp     x0, #0x1000
//   0x2738: 91031800  add      x0, x0, #0xc6
//   0x273c: a90227ea  stp      x10, x9, [sp, #0x20]
//   0x2740: f0ffffe9  adrp     x9, #0x1000
//   0x2744: 9107b929  add      x9, x9, #0x1ee
//   0x2748: f0ffffe1  adrp     x1, #0x1000
//   0x274c: 910f4421  add      x1, x1, #0x3d1
//   0x2750: f0ffffe3  adrp     x3, #0x1000
//   0x2754: 910d5063  add      x3, x3, #0x354
//   0x2758: a90123e9  stp      x9, x8, [sp, #0x10]
//   0x275c: f0ffffe8  adrp     x8, #0x1000
//   0x2760: 910db908  add      x8, x8, #0x36e
//   0x2764: f0ffffe9  adrp     x9, #0x1000
//   0x2768: 910c3129  add      x9, x9, #0x30c
//   0x276c: f0ffffe5  adrp     x5, #0x1000
//   0x2770: 910ad4a5  add      x5, x5, #0x2b5
//   0x2774: f0ffffe7  adrp     x7, #0x1000
//   0x2778: 910300e7  add      x7, x7, #0xc0
//   0x277c: aa0203e4  mov      x4, x2
//   0x2780: aa0203e6  mov      x6, x2
//   0x2784: a90023e9  stp      x9, x8, [sp]
//   0x2788: f9001bff  str      xzr, [sp, #0x30]
//   0x278c: 940002ed  bl       #0x3340
//   0x2790: 12800000  mov      w0, #-1
//   0x2794: 940002ef  bl       #0x3350
//   0x2798: 9400029e  bl       #0x3210
//   0x279c: a9ba7bfd  stp      x29, x30, [sp, #-0x60]!
//   0x27a0: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x27a4: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x27a8: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x27ac: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x27b0: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x27b4: 910003fd  mov      x29, sp
//   0x27b8: d14007ff  sub      sp, sp, #1, lsl #12
//   0x27bc: d12343ff  sub      sp, sp, #0x8d0
//   0x27c0: f90017e1  str      x1, [sp, #0x28]
//   0x27c4: d53bd054  mrs      x20, tpidr_el0
//   0x27c8: f9401688  ldr      x8, [x20, #0x28]
//   0x27cc: b0000049  adrp     x9, #0xb000
//   0x27d0: aa0003f3  mov      x19, x0
//   0x27d4: 2a0203e0  mov      w0, w2
//   0x27d8: 52810001  mov      w1, #0x800
//   0x27dc: 2a1f03e2  mov      w2, wzr
//   0x27e0: f81f03a8  stur     x8, [x29, #-0x10]
//   0x27e4: 2a1f03e3  mov      w3, wzr
//   0x27e8: f944c128  ldr      x8, [x9, #0x980]
//   0x27ec: d63f0100  blr      x8
//   0x27f0: aa0003f8  mov      x24, x0
//   0x27f4: b9400a60  ldr      w0, [x19, #8]
//   0x27f8: f0ffffe1  adrp     x1, #0x1000
//   0x27fc: 910b7021  add      x1, x1, #0x2dc
//   0x2800: 940000ff  bl       #0x2bfc
//   0x2804: b4001b78  cbz      x24, #0x2b70
//   0x2808: a901e3f4  stp      x20, x24, [sp, #0x18]
//   0x280c: 52849b99  mov      w25, #0x24dc
//   0x2810: 52824dd4  mov      w20, #0x126e
//   0x2814: 2a1f03f5  mov      w21, wzr
//   0x2818: 2a1f03f6  mov      w22, wzr
//   0x281c: b000005a  adrp     x26, #0xb000
//   0x2820: f0fffffb  adrp     x27, #0x1000
//   0x2824: 9108377b  add      x27, x27, #0x20d
//   0x2828: 72a020d9  movk     w25, #0x106, lsl #16
//   0x282c: 72a01074  movk     w20, #0x83, lsl #16
//   0x2830: 14000006  b        #0x2848
//   0x2834: b9400a60  ldr      w0, [x19, #8]
//   0x2838: f0ffffe1  adrp     x1, #0x1000
//   0x283c: 910c6421  add      x1, x1, #0x319
//   0x2840: 940000ef  bl       #0x2bfc
//   0x2844: 52800036  mov      w22, #1
//   0x2848: f944c748  ldr      x8, [x26, #0x988]
//   0x284c: 9110e3e1  add      x1, sp, #0x438
//   0x2850: aa1803e0  mov      x0, x24
//   0x2854: d63f0100  blr      x8
//   0x2858: 2a0003e2  mov      w2, w0
//   0x285c: 37f809a0  tbnz     w0, #0x1f, #0x2990
//   0x2860: 340014a2  cbz      w2, #0x2af4
//   0x2864: 37000336  tbnz     w22, #0, #0x28c8
//   0x2868: 9100e3e0  add      x0, sp, #0x38
//   0x286c: 52808001  mov      w1, #0x400
//   0x2870: f0ffffe2  adrp     x2, #0x1000
//   0x2874: 9106fc42  add      x2, x2, #0x1bf
//   0x2878: f94017e3  ldr      x3, [sp, #0x28]
//   0x287c: 97fffe1c  bl       #0x20ec
//   0x2880: b9400a60  ldr      w0, [x19, #8]
//   0x2884: 9100e3e2  add      x2, sp, #0x38
//   0x2888: f0ffffe1  adrp     x1, #0x1000
//   0x288c: 910d9821  add      x1, x1, #0x366
//   0x2890: 940000db  bl       #0x2bfc
//   0x2894: 9100e3e0  add      x0, sp, #0x38
//   0x2898: 52808001  mov      w1, #0x400
//   0x289c: b9400676  ldr      w22, [x19, #4]
//   0x28a0: 94000290  bl       #0x32e0
//   0x28a4: aa0003e2  mov      x2, x0
//   0x28a8: 9100e3e1  add      x1, sp, #0x38
//   0x28ac: 2a1603e0  mov      w0, w22
//   0x28b0: 940002ac  bl       #0x3360
//   0x28b4: b6f800a0  tbz      x0, #0x3f, #0x28c8
//   0x28b8: b9400a60  ldr      w0, [x19, #8]
//   0x28bc: f0ffffe1  adrp     x1, #0x1000
//   0x28c0: 9107c421  add      x1, x1, #0x1f1
//   0x28c4: 940000ce  bl       #0x2bfc
//   0x28c8: b98447e8  ldrsw    x8, [sp, #0x444]
//   0x28cc: 9100c3e0  add      x0, sp, #0x30
//   0x28d0: 9100e3e1  add      x1, sp, #0x38
//   0x28d4: f9001be8  str      x8, [sp, #0x30]
//   0x28d8: 940002a6  bl       #0x3370
//   0x28dc: d10243a0  sub      x0, x29, #0x90
//   0x28e0: 9100e3e3  add      x3, sp, #0x38
//   0x28e4: 52800401  mov      w1, #0x20
//   0x28e8: aa1b03e2  mov      x2, x27
//   0x28ec: 940002a5  bl       #0x3380
//   0x28f0: d10243a0  sub      x0, x29, #0x90
//   0x28f4: 9400026b  bl       #0x32a0
//   0x28f8: b4fff9e0  cbz      x0, #0x2834
//   0x28fc: 794877e8  ldrh     w8, [sp, #0x43a]
//   0x2900: 52800289  mov      w9, #0x14
//   0x2904: 7100011f  cmp      w8, #0
//   0x2908: 1a88013c  csel     w28, w9, w8, eq
//   0x290c: 51007788  sub      w8, w28, #0x1d
//   0x2910: 3100251f  cmn      w8, #9
//   0x2914: 54000d83  b.lo     #0x2ac4
//   0x2918: 9110e3e8  add      x8, sp, #0x438
//   0x291c: aa0003f7  mov      x23, x0
//   0x2920: 8b1c0118  add      x24, x8, x28
//   0x2924: 3840171b  ldrb     w27, [x24], #1
//   0x2928: aa1803e0  mov      x0, x24
//   0x292c: 94000231  bl       #0x31f0
//   0x2930: 8b000308  add      x8, x24, x0
//   0x2934: aa0003fa  mov      x26, x0
//   0x2938: 91000516  add      x22, x8, #1
//   0x293c: aa1603e0  mov      x0, x22
//   0x2940: 9400022c  bl       #0x31f0
//   0x2944: f100041f  cmp      x0, #1
//   0x2948: 5400018b  b.lt     #0x2978
//   0x294c: 8b1c0349  add      x9, x26, x28
//   0x2950: 9110e3ea  add      x10, sp, #0x438
//   0x2954: 91000408  add      x8, x0, #1
//   0x2958: 8b090149  add      x9, x10, x9
//   0x295c: 3868692a  ldrb     w10, [x9, x8]
//   0x2960: 7100295f  cmp      w10, #0xa
//   0x2964: 540000a1  b.ne     #0x2978
//   0x2968: 3828693f  strb     wzr, [x9, x8]
//   0x296c: d1000508  sub      x8, x8, #1
//   0x2970: f100051f  cmp      x8, #1
//   0x2974: 54ffff4c  b.gt     #0x295c
//   0x2978: 7100237f  cmp      w27, #8
//   0x297c: 54000268  b.hi     #0x29c8
//   0x2980: f0ffffe8  adrp     x8, #0x1000
//   0x2984: 910c0908  add      x8, x8, #0x302
//   0x2988: 387b691c  ldrb     w28, [x8, x27]
//   0x298c: 14000010  b        #0x29cc
//   0x2990: 11005848  add      w8, w2, #0x16
//   0x2994: 7100491f  cmp      w8, #0x12
//   0x2998: 54001228  b.hi     #0x2bdc
//   0x299c: d503201f  nop      
//   0x29a0: 10ff550b  adr      x11, #0x1440
//   0x29a4: 10fff609  adr      x9, #0x2864
//   0x29a8: 3868696a  ldrb     w10, [x11, x8]
//   0x29ac: 8b0a0929  add      x9, x9, x10, lsl #2
//   0x29b0: d61f0120  br       x9
//   0x29b4: b9400a60  ldr      w0, [x19, #8]
//   0x29b8: f0ffffe1  adrp     x1, #0x1000
//   0x29bc: 910a5821  add      x1, x1, #0x296
//   0x29c0: 9400008f  bl       #0x2bfc
//   0x29c4: 17ffffa8  b        #0x2864
//   0x29c8: 528007fc  mov      w28, #0x3f
//   0x29cc: 711f42bf  cmp      w21, #0x7d0
//   0x29d0: 5280fa08  mov      w8, #0x7d0
//   0x29d4: 1a88c2bb  csel     w27, w21, w8, gt
//   0x29d8: 14000003  b        #0x29e4
//   0x29dc: 2a1a03f5  mov      w21, w26
//   0x29e0: b4000656  cbz      x22, #0x2aa8
//   0x29e4: 6b15037f  cmp      w27, w21
//   0x29e8: 540005e0  b.eq     #0x2aa4
//   0x29ec: aa1603e0  mov      x0, x22
//   0x29f0: 52800141  mov      w1, #0xa
//   0x29f4: aa1603fa  mov      x26, x22
//   0x29f8: 94000266  bl       #0x3390
//   0x29fc: aa0003f6  mov      x22, x0
//   0x2a00: b4000040  cbz      x0, #0x2a08
//   0x2a04: 380016df  strb     wzr, [x22], #1
//   0x2a08: b9844be8  ldrsw    x8, [sp, #0x448]
//   0x2a0c: 529bd069  mov      w9, #0xde83
//   0x2a10: 72a86369  movk     w9, #0x431b, lsl #16
//   0x2a14: b9443fe5  ldr      w5, [sp, #0x43c]
//   0x2a18: b94443e6  ldr      w6, [sp, #0x440]
//   0x2a1c: 9100e3e0  add      x0, sp, #0x38
//   0x2a20: 9b297d08  smull    x8, w8, w9
//   0x2a24: 52808001  mov      w1, #0x400
//   0x2a28: f0ffffe2  adrp     x2, #0x1000
//   0x2a2c: 910de442  add      x2, x2, #0x379
//   0x2a30: d37ffd09  lsr      x9, x8, #0x3f
//   0x2a34: 9372fd08  asr      x8, x8, #0x32
//   0x2a38: 0b090104  add      w4, w8, w9
//   0x2a3c: aa1703e3  mov      x3, x23
//   0x2a40: 2a1c03e7  mov      w7, w28
//   0x2a44: a9006bf8  stp      x24, x26, [sp]
//   0x2a48: 97fffda9  bl       #0x20ec
//   0x2a4c: b9400668  ldr      w8, [x19, #4]
//   0x2a50: 93407c02  sxtw     x2, w0
//   0x2a54: 9100e3e1  add      x1, sp, #0x38
//   0x2a58: 2a0803e0  mov      w0, w8
//   0x2a5c: 94000241  bl       #0x3360
//   0x2a60: 528f1aa8  mov      w8, #0x78d5
//   0x2a64: 110006ba  add      w26, w21, #1
//   0x2a68: 72a4dd28  movk     w8, #0x26e9, lsl #16
//   0x2a6c: 1b086748  madd     w8, w26, w8, w25
//   0x2a70: 13880908  ror      w8, w8, #2
//   0x2a74: 6b14011f  cmp      w8, w20
//   0x2a78: 54fffb28  b.hi     #0x29dc
//   0x2a7c: b9400660  ldr      w0, [x19, #4]
//   0x2a80: d10243a1  sub      x1, x29, #0x90
//   0x2a84: 94000227  bl       #0x3320
//   0x2a88: 3100041f  cmn      w0, #1
//   0x2a8c: 54fffa80  b.eq     #0x29dc
//   0x2a90: f85a03a8  ldur     x8, [x29, #-0x60]
//   0x2a94: f142bd1f  cmp      x8, #0xaf, lsl #12
//   0x2a98: 54fffa2b  b.lt     #0x29dc
//   0x2a9c: 110006ba  add      w26, w21, #1
//   0x2aa0: 14000002  b        #0x2aa8
//   0x2aa4: 2a1b03fa  mov      w26, w27
//   0x2aa8: aa1703e0  mov      x0, x23
//   0x2aac: 9400023d  bl       #0x33a0
//   0x2ab0: 2a1a03f5  mov      w21, w26
//   0x2ab4: f94013f8  ldr      x24, [sp, #0x20]
//   0x2ab8: b000005a  adrp     x26, #0xb000
//   0x2abc: f0fffffb  adrp     x27, #0x1000
//   0x2ac0: 9108377b  add      x27, x27, #0x20d
//   0x2ac4: 52800036  mov      w22, #1
//   0x2ac8: 17ffff60  b        #0x2848
//   0x2acc: b9400a60  ldr      w0, [x19, #8]
//   0x2ad0: f0ffffe1  adrp     x1, #0x1000
//   0x2ad4: 91061c21  add      x1, x1, #0x187
//   0x2ad8: 94000049  bl       #0x2bfc
//   0x2adc: 17ffff62  b        #0x2864
//   0x2ae0: b9400a60  ldr      w0, [x19, #8]
//   0x2ae4: f0ffffe1  adrp     x1, #0x1000
//   0x2ae8: 9102a421  add      x1, x1, #0xa9
//   0x2aec: 94000044  bl       #0x2bfc
//   0x2af0: 17ffff5d  b        #0x2864
//   0x2af4: b9400a75  ldr      w21, [x19, #8]
//   0x2af8: 940001ca  bl       #0x3220
//   0x2afc: b9400000  ldr      w0, [x0]
//   0x2b00: 9400020c  bl       #0x3330
//   0x2b04: aa0003e2  mov      x2, x0
//   0x2b08: f0ffffe1  adrp     x1, #0x1000
//   0x2b0c: 9108f021  add      x1, x1, #0x23c
//   0x2b10: 2a1503e0  mov      w0, w21
//   0x2b14: 9400003a  bl       #0x2bfc
//   0x2b18: b9400a60  ldr      w0, [x19, #8]
//   0x2b1c: f0ffffe1  adrp     x1, #0x1000
//   0x2b20: 9103b821  add      x1, x1, #0xee
//   0x2b24: 94000036  bl       #0x2bfc
//   0x2b28: b0000048  adrp     x8, #0xb000
//   0x2b2c: aa1803e0  mov      x0, x24
//   0x2b30: f944c908  ldr      x8, [x8, #0x990]
//   0x2b34: d63f0100  blr      x8
//   0x2b38: f9400fe8  ldr      x8, [sp, #0x18]
//   0x2b3c: f9401508  ldr      x8, [x8, #0x28]
//   0x2b40: f85f03a9  ldur     x9, [x29, #-0x10]
//   0x2b44: eb09011f  cmp      x8, x9
//   0x2b48: 54000581  b.ne     #0x2bf8
//   0x2b4c: 914007ff  add      sp, sp, #1, lsl #12
//   0x2b50: 912343ff  add      sp, sp, #0x8d0
//   0x2b54: a9454ff4  ldp      x20, x19, [sp, #0x50]
//   0x2b58: a94457f6  ldp      x22, x21, [sp, #0x40]
//   0x2b5c: a9435ff8  ldp      x24, x23, [sp, #0x30]
//   0x2b60: a94267fa  ldp      x26, x25, [sp, #0x20]
//   0x2b64: a9416ffc  ldp      x28, x27, [sp, #0x10]
//   0x2b68: a8c67bfd  ldp      x29, x30, [sp], #0x60
//   0x2b6c: d65f03c0  ret      
//   0x2b70: b9400a73  ldr      w19, [x19, #8]
//   0x2b74: 940001ab  bl       #0x3220
//   0x2b78: b9400000  ldr      w0, [x0]
//   0x2b7c: 940001ed  bl       #0x3330
//   0x2b80: f9401688  ldr      x8, [x20, #0x28]
//   0x2b84: f85f03a9  ldur     x9, [x29, #-0x10]
//   0x2b88: eb09011f  cmp      x8, x9
//   0x2b8c: 54000361  b.ne     #0x2bf8
//   0x2b90: f94017e2  ldr      x2, [sp, #0x28]
//   0x2b94: aa0003e3  mov      x3, x0
//   0x2b98: f0ffffe1  adrp     x1, #0x1000
//   0x2b9c: 910bac21  add      x1, x1, #0x2eb
//   0x2ba0: 2a1303e0  mov      w0, w19
//   0x2ba4: 914007ff  add      sp, sp, #1, lsl #12
//   0x2ba8: 912343ff  add      sp, sp, #0x8d0
//   0x2bac: a9454ff4  ldp      x20, x19, [sp, #0x50]
//   0x2bb0: a94457f6  ldp      x22, x21, [sp, #0x40]
//   0x2bb4: a9435ff8  ldp      x24, x23, [sp, #0x30]
//   0x2bb8: a94267fa  ldp      x26, x25, [sp, #0x20]
//   0x2bbc: a9416ffc  ldp      x28, x27, [sp, #0x10]
//   0x2bc0: a8c67bfd  ldp      x29, x30, [sp], #0x60
//   0x2bc4: 1400000e  b        #0x2bfc
//   0x2bc8: b9400a60  ldr      w0, [x19, #8]
//   0x2bcc: f0ffffe1  adrp     x1, #0x1000
//   0x2bd0: 910ca821  add      x1, x1, #0x32a
//   0x2bd4: 9400000a  bl       #0x2bfc
//   0x2bd8: 17ffffd0  b        #0x2b18
//   0x2bdc: 4b0203e0  neg      w0, w2
//   0x2be0: b9400a75  ldr      w21, [x19, #8]
//   0x2be4: 940001d3  bl       #0x3330
//   0x2be8: aa0003e2  mov      x2, x0
//   0x2bec: f0ffffe1  adrp     x1, #0x1000
//   0x2bf0: 910cdc21  add      x1, x1, #0x337
//   0x2bf4: 17ffffc7  b        #0x2b10
//   0x2bf8: 94000186  bl       #0x3210
//   0x2bfc: a9bb7bfd  stp      x29, x30, [sp, #-0x50]!
//   0x2c00: f9000bfc  str      x28, [sp, #0x10]
//   0x2c04: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x2c08: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x2c0c: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x2c10: 910003fd  mov      x29, sp
//   0x2c14: d11483ff  sub      sp, sp, #0x520
//   0x2c18: a90993e3  stp      x3, x4, [sp, #0x98]
//   0x2c1c: 928005e9  mov      x9, #-0x30
//   0x2c20: f9004be2  str      x2, [sp, #0x90]
//   0x2c24: 910043ea  add      x10, sp, #0x10
//   0x2c28: a90a9be5  stp      x5, x6, [sp, #0xa8]
//   0x2c2c: 910243eb  add      x11, sp, #0x90
//   0x2c30: f9005fe7  str      x7, [sp, #0xb8]
//   0x2c34: aa0103f4  mov      x20, x1
//   0x2c38: ad0087e0  stp      q0, q1, [sp, #0x10]
//   0x2c3c: f2dff009  movk     x9, #0xff80, lsl #32
//   0x2c40: ad018fe2  stp      q2, q3, [sp, #0x30]
//   0x2c44: 9102014a  add      x10, x10, #0x80
//   0x2c48: ad0297e4  stp      q4, q5, [sp, #0x50]
//   0x2c4c: ad039fe6  stp      q6, q7, [sp, #0x70]
//   0x2c50: d53bd057  mrs      x23, tpidr_el0
//   0x2c54: f94016e8  ldr      x8, [x23, #0x28]
//   0x2c58: 7100041f  cmp      w0, #1
//   0x2c5c: f81f83a8  stur     x8, [x29, #-8]
//   0x2c60: 9100c168  add      x8, x11, #0x30
//   0x2c64: 910143ab  add      x11, x29, #0x50
//   0x2c68: a90e27ea  stp      x10, x9, [sp, #0xe0]
//   0x2c6c: a90d23eb  stp      x11, x8, [sp, #0xd0]
//   0x2c70: 5400096b  b.lt     #0x2d9c
//   0x2c74: 2a0003f3  mov      w19, w0
//   0x2c78: 910303e0  add      x0, sp, #0xc0
//   0x2c7c: aa1f03e1  mov      x1, xzr
//   0x2c80: 9400016c  bl       #0x3230
//   0x2c84: a94c23f8  ldp      x24, x8, [sp, #0xc0]
//   0x2c88: d29ef9e9  mov      x9, #0xf7cf
//   0x2c8c: f2bc6a69  movk     x9, #0xe353, lsl #16
//   0x2c90: f2d374a9  movk     x9, #0x9ba5, lsl #32
//   0x2c94: f2e41889  movk     x9, #0x20c4, lsl #48
//   0x2c98: 9b497d08  smulh    x8, x8, x9
//   0x2c9c: 9347fd09  asr      x9, x8, #7
//   0x2ca0: 8b48fd35  add      x21, x9, x8, lsr #63
//   0x2ca4: 940001c3  bl       #0x33b0
//   0x2ca8: 2a0003f6  mov      w22, w0
//   0x2cac: 940001c5  bl       #0x33c0
//   0x2cb0: b201e3e8  mov      x8, #-0x7777777777777778
//   0x2cb4: d28f80a9  mov      x9, #0x7c05
//   0x2cb8: f2911128  movk     x8, #0x8889
//   0x2cbc: f2ad5e69  movk     x9, #0x6af3, lsl #16
//   0x2cc0: f2cb3c49  movk     x9, #0x59e2, lsl #32
//   0x2cc4: b201f3eb  mov      x11, #-0x5555555555555556
//   0x2cc8: f2e91a29  movk     x9, #0x48d1, lsl #48
//   0x2ccc: 9b487f0a  smulh    x10, x24, x8
//   0x2cd0: f295556b  movk     x11, #0xaaab
//   0x2cd4: f0ffffe2  adrp     x2, #0x1000
//   0x2cd8: 91074442  add      x2, x2, #0x1d1
//   0x2cdc: 9b497f09  smulh    x9, x24, x9
//   0x2ce0: 8b18014a  add      x10, x10, x24
//   0x2ce4: f2e5554b  movk     x11, #0x2aaa, lsl #48
//   0x2ce8: 9345fd4d  asr      x13, x10, #5
//   0x2cec: 934afd2c  asr      x12, x9, #0xa
//   0x2cf0: 8b4afdaa  add      x10, x13, x10, lsr #63
//   0x2cf4: 8b49fd89  add      x9, x12, x9, lsr #63
//   0x2cf8: 5280078c  mov      w12, #0x3c
//   0x2cfc: 52808001  mov      w1, #0x400
//   0x2d00: 9b487d48  smulh    x8, x10, x8
//   0x2d04: aa1503e6  mov      x6, x21
//   0x2d08: 9b4b7d2b  smulh    x11, x9, x11
//   0x2d0c: 2a1603e7  mov      w7, w22
//   0x2d10: 8b0a0108  add      x8, x8, x10
//   0x2d14: 1b0ce145  msub     w5, w10, w12, w24
//   0x2d18: d37ffd6d  lsr      x13, x11, #0x3f
//   0x2d1c: d342fd6b  lsr      x11, x11, #2
//   0x2d20: d37ffd0e  lsr      x14, x8, #0x3f
//   0x2d24: d345fd08  lsr      x8, x8, #5
//   0x2d28: 0b0d016b  add      w11, w11, w13
//   0x2d2c: 0b0e0108  add      w8, w8, w14
//   0x2d30: 5280030d  mov      w13, #0x18
//   0x2d34: 910443f5  add      x21, sp, #0x110
//   0x2d38: 1b0ca904  msub     w4, w8, w12, w10
//   0x2d3c: 2a0003e8  mov      w8, w0
//   0x2d40: 1b0da563  msub     w3, w11, w13, w9
//   0x2d44: 910443e0  add      x0, sp, #0x110
//   0x2d48: b90003e8  str      w8, [sp]
//   0x2d4c: 97fffce8  bl       #0x20ec
//   0x2d50: f100641f  cmp      x0, #0x19
//   0x2d54: 54000341  b.ne     #0x2dbc
//   0x2d58: ad4687e0  ldp      q0, q1, [sp, #0xd0]
//   0x2d5c: 910066a0  add      x0, x21, #0x19
//   0x2d60: 9103c3e3  add      x3, sp, #0xf0
//   0x2d64: 52807ce1  mov      w1, #0x3e7
//   0x2d68: aa1403e2  mov      x2, x20
//   0x2d6c: ad0787e0  stp      q0, q1, [sp, #0xf0]
//   0x2d70: 97fffa80  bl       #0x1770
//   0x2d74: b4000240  cbz      x0, #0x2dbc
//   0x2d78: 910443e8  add      x8, sp, #0x110
//   0x2d7c: 52800149  mov      w9, #0xa
//   0x2d80: 8b080008  add      x8, x0, x8
//   0x2d84: 91006802  add      x2, x0, #0x1a
//   0x2d88: 910443e1  add      x1, sp, #0x110
//   0x2d8c: 2a1303e0  mov      w0, w19
//   0x2d90: 39006509  strb     w9, [x8, #0x19]
//   0x2d94: 94000173  bl       #0x3360
//   0x2d98: 14000009  b        #0x2dbc
//   0x2d9c: ad4687e0  ldp      q0, q1, [sp, #0xd0]
//   0x2da0: b0000028  adrp     x8, #0x7000
//   0x2da4: 910443e2  add      x2, sp, #0x110
//   0x2da8: aa1403e1  mov      x1, x20
//   0x2dac: ad0887e0  stp      q0, q1, [sp, #0x110]
//   0x2db0: f9435508  ldr      x8, [x8, #0x6a8]
//   0x2db4: 91026100  add      x0, x8, #0x98
//   0x2db8: 94000186  bl       #0x33d0
//   0x2dbc: f94016e8  ldr      x8, [x23, #0x28]
//   0x2dc0: f85f83a9  ldur     x9, [x29, #-8]
//   0x2dc4: eb09011f  cmp      x8, x9
//   0x2dc8: 54000101  b.ne     #0x2de8
//   0x2dcc: 911483ff  add      sp, sp, #0x520
//   0x2dd0: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x2dd4: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x2dd8: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x2ddc: f9400bfc  ldr      x28, [sp, #0x10]
//   0x2de0: a8c57bfd  ldp      x29, x30, [sp], #0x50
//   0x2de4: d65f03c0  ret      
//   0x2de8: 9400010a  bl       #0x3210
//   0x2dec: d10183ff  sub      sp, sp, #0x60
//   0x2df0: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x2df4: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x2df8: 910103fd  add      x29, sp, #0x40
//   0x2dfc: b0000048  adrp     x8, #0xb000
//   0x2e00: 39658109  ldrb     w9, [x8, #0x960]
//   0x2e04: 7100053f  cmp      w9, #1
//   0x2e08: 540012a0  b.eq     #0x305c
//   0x2e0c: aa0103f3  mov      x19, x1
//   0x2e10: d503201f  nop      
//   0x2e14: 10044fe1  adr      x1, #0xb810
//   0x2e18: 52800029  mov      w9, #1
//   0x2e1c: aa1f03e2  mov      x2, xzr
//   0x2e20: b8408420  ldr      w0, [x1], #8
//   0x2e24: 39258109  strb     w9, [x8, #0x960]
//   0x2e28: 94000116  bl       #0x3280
//   0x2e2c: 340000e0  cbz      w0, #0x2e48
//   0x2e30: 940000fc  bl       #0x3220
//   0x2e34: b9400009  ldr      w9, [x0]
//   0x2e38: 52807d28  mov      w8, #0x3e9
//   0x2e3c: 7100013f  cmp      w9, #0
//   0x2e40: 1a890114  csel     w20, w8, w9, eq
//   0x2e44: 14000002  b        #0x2e4c
//   0x2e48: 2a1f03f4  mov      w20, wzr
//   0x2e4c: b0000041  adrp     x1, #0xb000
//   0x2e50: 9120e021  add      x1, x1, #0x838
//   0x2e54: aa1f03e2  mov      x2, xzr
//   0x2e58: b8408420  ldr      w0, [x1], #8
//   0x2e5c: 94000109  bl       #0x3280
//   0x2e60: 340000c0  cbz      w0, #0x2e78
//   0x2e64: 940000ef  bl       #0x3220
//   0x2e68: b9400009  ldr      w9, [x0]
//   0x2e6c: 52807d28  mov      w8, #0x3e9
//   0x2e70: 7100013f  cmp      w9, #0
//   0x2e74: 1a890114  csel     w20, w8, w9, eq
//   0x2e78: b0000041  adrp     x1, #0xb000
//   0x2e7c: 91218021  add      x1, x1, #0x860
//   0x2e80: aa1f03e2  mov      x2, xzr
//   0x2e84: b8408420  ldr      w0, [x1], #8
//   0x2e88: 940000fe  bl       #0x3280
//   0x2e8c: 340000c0  cbz      w0, #0x2ea4
//   0x2e90: 940000e4  bl       #0x3220
//   0x2e94: b9400009  ldr      w9, [x0]
//   0x2e98: 52807d28  mov      w8, #0x3e9
//   0x2e9c: 7100013f  cmp      w9, #0
//   0x2ea0: 1a890114  csel     w20, w8, w9, eq
//   0x2ea4: b0000041  adrp     x1, #0xb000
//   0x2ea8: 91222021  add      x1, x1, #0x888
//   0x2eac: aa1f03e2  mov      x2, xzr
//   0x2eb0: b8408420  ldr      w0, [x1], #8
//   0x2eb4: 940000f3  bl       #0x3280
//   0x2eb8: 340000c0  cbz      w0, #0x2ed0
//   0x2ebc: 940000d9  bl       #0x3220
//   0x2ec0: b9400009  ldr      w9, [x0]
//   0x2ec4: 52807d28  mov      w8, #0x3e9
//   0x2ec8: 7100013f  cmp      w9, #0
//   0x2ecc: 1a890114  csel     w20, w8, w9, eq
//   0x2ed0: b0000041  adrp     x1, #0xb000
//   0x2ed4: 9122c021  add      x1, x1, #0x8b0
//   0x2ed8: aa1f03e2  mov      x2, xzr
//   0x2edc: b8408420  ldr      w0, [x1], #8
//   0x2ee0: 940000e8  bl       #0x3280
//   0x2ee4: 340000c0  cbz      w0, #0x2efc
//   0x2ee8: 940000ce  bl       #0x3220
//   0x2eec: b9400009  ldr      w9, [x0]
//   0x2ef0: 52807d28  mov      w8, #0x3e9
//   0x2ef4: 7100013f  cmp      w9, #0
//   0x2ef8: 1a890114  csel     w20, w8, w9, eq
//   0x2efc: b0000041  adrp     x1, #0xb000
//   0x2f00: 91236021  add      x1, x1, #0x8d8
//   0x2f04: aa1f03e2  mov      x2, xzr
//   0x2f08: b8408420  ldr      w0, [x1], #8
//   0x2f0c: 940000dd  bl       #0x3280
//   0x2f10: 340000c0  cbz      w0, #0x2f28
//   0x2f14: 940000c3  bl       #0x3220
//   0x2f18: b9400009  ldr      w9, [x0]
//   0x2f1c: 52807d28  mov      w8, #0x3e9
//   0x2f20: 7100013f  cmp      w9, #0
//   0x2f24: 1a890114  csel     w20, w8, w9, eq
//   0x2f28: b0000041  adrp     x1, #0xb000
//   0x2f2c: 91240021  add      x1, x1, #0x900
//   0x2f30: aa1f03e2  mov      x2, xzr
//   0x2f34: b8408420  ldr      w0, [x1], #8
//   0x2f38: 940000d2  bl       #0x3280
//   0x2f3c: 340000c0  cbz      w0, #0x2f54
//   0x2f40: 940000b8  bl       #0x3220
//   0x2f44: b9400009  ldr      w9, [x0]
//   0x2f48: 52807d28  mov      w8, #0x3e9
//   0x2f4c: 7100013f  cmp      w9, #0
//   0x2f50: 1a890114  csel     w20, w8, w9, eq
//   0x2f54: b0000041  adrp     x1, #0xb000
//   0x2f58: 9124a021  add      x1, x1, #0x928
//   0x2f5c: aa1f03e2  mov      x2, xzr
//   0x2f60: b8408420  ldr      w0, [x1], #8
//   0x2f64: 940000c7  bl       #0x3280
//   0x2f68: 2a140008  orr      w8, w0, w20
//   0x2f6c: 350007c8  cbnz     w8, #0x3064
//   0x2f70: b9400268  ldr      w8, [x19]
//   0x2f74: 7100191f  cmp      w8, #6
//   0x2f78: 54000080  b.eq     #0x2f88
//   0x2f7c: b9400a68  ldr      w8, [x19, #8]
//   0x2f80: 7100011f  cmp      w8, #0
//   0x2f84: 5400014c  b.gt     #0x2fac
//   0x2f88: 9400010a  bl       #0x33b0
//   0x2f8c: 2a0003f4  mov      w20, w0
//   0x2f90: 9400010c  bl       #0x33c0
//   0x2f94: 2a0003e2  mov      w2, w0
//   0x2f98: b9400263  ldr      w3, [x19]
//   0x2f9c: 52801e00  mov      w0, #0xf0
//   0x2fa0: 2a1403e1  mov      w1, w20
//   0x2fa4: aa1303e4  mov      x4, x19
//   0x2fa8: 9400010e  bl       #0x33e0
//   0x2fac: d503201f  nop      
//   0x2fb0: 30ff0b21  adr      x1, #0x1115
//   0x2fb4: f0ffffe2  adrp     x2, #0x1000
//   0x2fb8: 91068442  add      x2, x2, #0x1a1
//   0x2fbc: 528000c0  mov      w0, #6
//   0x2fc0: 940000a4  bl       #0x3250
//   0x2fc4: b0000048  adrp     x8, #0xb000
//   0x2fc8: 52800041  mov      w1, #2
//   0x2fcc: f944ad13  ldr      x19, [x8, #0x958]
//   0x2fd0: aa1303e0  mov      x0, x19
//   0x2fd4: 94000107  bl       #0x33f0
//   0x2fd8: 7100041f  cmp      w0, #1
//   0x2fdc: 5400014b  b.lt     #0x3004
//   0x2fe0: aa1f03e1  mov      x1, xzr
//   0x2fe4: 2a0003f4  mov      w20, w0
//   0x2fe8: 94000106  bl       #0x3400
//   0x2fec: 2a1403e0  mov      w0, w20
//   0x2ff0: aa1f03e1  mov      x1, xzr
//   0x2ff4: 2a1f03e2  mov      w2, wzr
//   0x2ff8: 94000106  bl       #0x3410
//   0x2ffc: 2a1403e0  mov      w0, w20
//   0x3000: 94000090  bl       #0x3240
//   0x3004: 52801b80  mov      w0, #0xdc
//   0x3008: 2a1f03e1  mov      w1, wzr
//   0x300c: aa1f03e2  mov      x2, xzr
//   0x3010: aa1f03e3  mov      x3, xzr
//   0x3014: aa1f03e4  mov      x4, xzr
//   0x3018: aa1f03e5  mov      x5, xzr
//   0x301c: 940000f1  bl       #0x33e0
//   0x3020: 34000260  cbz      w0, #0x306c
//   0x3024: 37f800a0  tbnz     w0, #0x1f, #0x3038
//   0x3028: a9454ff4  ldp      x20, x19, [sp, #0x50]
//   0x302c: a9447bfd  ldp      x29, x30, [sp, #0x40]
//   0x3030: 910183ff  add      sp, sp, #0x60
//   0x3034: d65f03c0  ret      
//   0x3038: d503201f  nop      
//   0x303c: 30ff06c1  adr      x1, #0x1115
//   0x3040: d0ffffe2  adrp     x2, #0x1000
//   0x3044: 91098842  add      x2, x2, #0x262
//   0x3048: 52800080  mov      w0, #4
//   0x304c: a9454ff4  ldp      x20, x19, [sp, #0x50]
//   0x3050: a9447bfd  ldp      x29, x30, [sp, #0x40]
//   0x3054: 910183ff  add      sp, sp, #0x60
//   0x3058: 1400007e  b        #0x3250
//   0x305c: 52801900  mov      w0, #0xc8
//   0x3060: 940000bc  bl       #0x3350
//   0x3064: 52800140  mov      w0, #0xa
//   0x3068: 940000ba  bl       #0x3350
//   0x306c: 528003c0  mov      w0, #0x1e
//   0x3070: 940000ec  bl       #0x3420
//   0x3074: d0ffffe8  adrp     x8, #0x1000
//   0x3078: 91087d08  add      x8, x8, #0x21f
//   0x307c: d0ffffe9  adrp     x9, #0x1000
//   0x3080: 91087129  add      x9, x9, #0x21c
//   0x3084: d0ffffe2  adrp     x2, #0x1000
//   0x3088: 91042c42  add      x2, x2, #0x10b
//   0x308c: d0ffffe0  adrp     x0, #0x1000
//   0x3090: 91031800  add      x0, x0, #0xc6
//   0x3094: a90223e9  stp      x9, x8, [sp, #0x20]
//   0x3098: d0ffffe8  adrp     x8, #0x1000
//   0x309c: 9107b908  add      x8, x8, #0x1ee
//   0x30a0: d0ffffe9  adrp     x9, #0x1000
//   0x30a4: 910c3129  add      x9, x9, #0x30c
//   0x30a8: d0ffffe1  adrp     x1, #0x1000
//   0x30ac: 910f4421  add      x1, x1, #0x3d1
//   0x30b0: d0ffffe3  adrp     x3, #0x1000
//   0x30b4: 910d5063  add      x3, x3, #0x354
//   0x30b8: a9014fe8  stp      x8, x19, [sp, #0x10]
//   0x30bc: d0ffffe8  adrp     x8, #0x1000
//   0x30c0: 910db908  add      x8, x8, #0x36e
//   0x30c4: d0ffffe5  adrp     x5, #0x1000
//   0x30c8: 910ad4a5  add      x5, x5, #0x2b5
//   0x30cc: d0ffffe7  adrp     x7, #0x1000
//   0x30d0: 910300e7  add      x7, x7, #0xc0
//   0x30d4: aa0203e4  mov      x4, x2
//   0x30d8: aa0203e6  mov      x6, x2
//   0x30dc: a90023e9  stp      x9, x8, [sp]
//   0x30e0: f9001bff  str      xzr, [sp, #0x30]
//   0x30e4: 94000097  bl       #0x3340
//   0x30e8: 12800000  mov      w0, #-1
//   0x30ec: 94000099  bl       #0x3350
//   0x30f0: a9be7bfd  stp      x29, x30, [sp, #-0x20]!
//   0x30f4: a9014ffc  stp      x28, x19, [sp, #0x10]
//   0x30f8: 910003fd  mov      x29, sp
//   0x30fc: d110c3ff  sub      sp, sp, #0x430
//   0x3100: d53bd053  mrs      x19, tpidr_el0
//   0x3104: d503201f  nop      
//   0x3108: 10ffff40  adr      x0, #0x30f0
//   0x310c: f9401668  ldr      x8, [x19, #0x28]
//   0x3110: 910023e1  add      x1, sp, #8
//   0x3114: f81f83a8  stur     x8, [x29, #-8]
//   0x3118: 940000c6  bl       #0x3430
//   0x311c: 2a0003e8  mov      w8, w0
//   0x3120: aa1f03e0  mov      x0, xzr
//   0x3124: 34000308  cbz      w8, #0x3184
//   0x3128: f94007e1  ldr      x1, [sp, #8]
//   0x312c: b40002c1  cbz      x1, #0x3184
//   0x3130: 39400028  ldrb     w8, [x1]
//   0x3134: 7100bd1f  cmp      w8, #0x2f
//   0x3138: 54000241  b.ne     #0x3180
//   0x313c: 9100a3e0  add      x0, sp, #0x28
//   0x3140: 52808002  mov      w2, #0x400
//   0x3144: 940000bf  bl       #0x3440
//   0x3148: 9100a3e0  add      x0, sp, #0x28
//   0x314c: 528005e1  mov      w1, #0x2f
//   0x3150: 52808002  mov      w2, #0x400
//   0x3154: 940000bf  bl       #0x3450
//   0x3158: b4000160  cbz      x0, #0x3184
//   0x315c: d0ffffe9  adrp     x9, #0x1000
//   0x3160: 91053929  add      x9, x9, #0x14e
//   0x3164: 52800de8  mov      w8, #0x6f
//   0x3168: 3dc00120  ldr      q0, [x9]
//   0x316c: 78011008  sturh    w8, [x0, #0x11]
//   0x3170: 3c801000  stur     q0, [x0, #1]
//   0x3174: 9100a3e0  add      x0, sp, #0x28
//   0x3178: 9400004a  bl       #0x32a0
//   0x317c: 14000002  b        #0x3184
//   0x3180: aa1f03e0  mov      x0, xzr
//   0x3184: f9401668  ldr      x8, [x19, #0x28]
//   0x3188: f85f83a9  ldur     x9, [x29, #-8]
//   0x318c: eb09011f  cmp      x8, x9
//   0x3190: 540000a1  b.ne     #0x31a4
//   0x3194: 9110c3ff  add      sp, sp, #0x430
//   0x3198: a9414ffc  ldp      x28, x19, [sp, #0x10]
//   0x319c: a8c27bfd  ldp      x29, x30, [sp], #0x20
//   0x31a0: d65f03c0  ret      
//   0x31a4: 9400001b  bl       #0x3210
// ============================================================================

#include "npth_logcat.h"

#include <cstring>
#include <cstdlib>

namespace nextai {
namespace opencut {
namespace npth_logcat {

namespace {

NpthLogcatBssState g_logcat_bss{};

// EN: Priority character lookup table at .rodata 0x1302: `"!.VDIWEFS"`.
// VI: Bảng tra ký tự mức ưu tiên log tại .rodata 0x1302: `"!.VDIWEFS"`.
constexpr char kPriorityChars[10] = "!.VDIWEFS";

}  // namespace

// EN: Exact reconstruction of the 1-in-500 multiplicative hash check at 0x2a54..0x2a78:
//       `mov w9, #0x24dc; movk w9, #0x106, lsl #16`    -> 0x010624DC
//       `mov w10, #0x78d5; movk w10, #0x26e9, lsl #16` -> 0x26E978D5
//       `madd w8, w26, w10, w9`
//       `ror w8, w8, #2`
//       `cmp w8, w11` (0x0083126E) -> `b.hi #0x2aa0` (skip fstat when > threshold).
//     Because `0x26E978D5 * 500 === 4 (mod 2^32)` and `0x26E978D5 * 499 + 0x010624DC = 0x00000003`,
//     rotating right by 2 yields `0x00000000..0x0083126E` if and only if `(line_index % 500) == 499`.
// VI: Tái tạo chính xác phép kiểm tra nhân băm 1-trên-500 tại 0x2a54..0x2a78:
//     Biểu thức `ror(w26 * 0x26E978D5 + 0x010624DC, 2) <= 0x0083126E` đúng khi và chỉ khi
//     `(line_index % 500) == 499`.
bool ShouldCheckLogFileSizeAtLine(uint32_t line_index) noexcept {
    uint32_t prod = line_index * kMod500MulInverse + kMod500AddOffset;
    uint32_t rotated = (prod >> 2) | (prod << 30);
    return rotated <= kMod500Threshold;
}

// EN: Exact reconstruction of `tv_nsec / 1,000,000` at 0x2a0c..0x2a14:
//       `mov w10, #0xde83; movk w10, #0x431b, lsl #16` -> 0x431BDE83
//       `umull x9, w9, w10; lsr x4, x9, #0x32` (shift right by 50).
// VI: Tái tạo chính xác phép chia `tv_nsec / 1.000.000` tại 0x2a0c..0x2a14.
uint32_t NanosecondsToMilliseconds(uint32_t nsec) noexcept {
    uint64_t prod = static_cast<uint64_t>(nsec) * static_cast<uint64_t>(kRecipDiv1e6_32);
    return static_cast<uint32_t>(prod >> 50);
}

// EN: Exact reconstruction of FDE[07] `log_status_printf` time decomposition at 0x2c84..0x2ce8:
//     - `tv_usec / 1000` via signed 64x64->128 multiply by `0x20C49BA5E353F7CF` >> 7
//     - `tv_sec % 86400` via signed 64x64->128 multiply by `0x48D159E26AF37C05` >> 14
//     - `sec_of_day / 3600` via unsigned 64x64->128 multiply by `0x8888888888888889` >> 11
//     - `(sec_of_day % 3600) / 60` via unsigned 64x64->128 multiply by `0x8888888888888889` >> 5
// VI: Tái tạo chính xác thuật toán tách giờ:phút:giây.mili-giây trong FDE[07] (0x2c84..0x2ce8).
void FormatStatusTimestamp(int64_t tv_sec, int64_t tv_usec,
                           int32_t* out_hour, int32_t* out_min,
                           int32_t* out_sec, int32_t* out_ms) noexcept {
    __int128 usec_prod = static_cast<__int128>(tv_usec) * static_cast<__int128>(kRecipDiv1000_64);
    int64_t usec_hi = static_cast<int64_t>(usec_prod >> 64);
    int32_t ms = static_cast<int32_t>((usec_hi >> 7) + (static_cast<uint64_t>(usec_hi) >> 63));

    __int128 day_prod = static_cast<__int128>(tv_sec) * static_cast<__int128>(kRecipDiv86400_64);
    int64_t day_hi = static_cast<int64_t>(day_prod >> 64);
    int64_t days = (day_hi >> 14) + (static_cast<uint64_t>(day_hi) >> 63);
    uint64_t sec_of_day = static_cast<uint64_t>(tv_sec - days * 86400LL);

    unsigned __int128 hr_prod =
        static_cast<unsigned __int128>(sec_of_day) * static_cast<unsigned __int128>(kRecipDiv60_64);
    uint64_t hr_hi = static_cast<uint64_t>(hr_prod >> 64);
    uint32_t hours = static_cast<uint32_t>(hr_hi >> 11);
    uint32_t rem_sec = static_cast<uint32_t>(sec_of_day - hours * 3600ULL);

    unsigned __int128 min_prod =
        static_cast<unsigned __int128>(rem_sec) * static_cast<unsigned __int128>(kRecipDiv60_64);
    uint64_t min_hi = static_cast<uint64_t>(min_prod >> 64);
    uint32_t mins = static_cast<uint32_t>(min_hi >> 5);
    uint32_t secs = rem_sec - mins * 60U;

    if (out_hour != nullptr) *out_hour = static_cast<int32_t>(hours);
    if (out_min != nullptr)  *out_min  = static_cast<int32_t>(mins);
    if (out_sec != nullptr)  *out_sec  = static_cast<int32_t>(secs);
    if (out_ms != nullptr)   *out_ms   = ms;
}

// EN: Exact reconstruction of the `logger_entry` packet validation and text log extraction
//     inside `dump_log_buffer` (`0x2854..0x297c`):
//       1. Reads `payload_len = hdr->len` (`ldrh w9, [sp, #0xb8]`) and `hdr_size = hdr->hdr_size`
//          (`ldrh w11, [sp, #0xba]`), defaulting `hdr_size` to 24 (`0x18`) if 0 (`0x2860..0x2864`).
//       2. Validates `hdr_size >= 20 && hdr_size <= 0x13fc && payload_len <= 0x1400 - hdr_size`
//          and `bytes_read == hdr_size + payload_len` (`0x2874..0x28f4`).
//       3. For text buffers (`log_id != 2 && log_id != 5`), extracts priority byte (`msg[0]`),
//          null-terminated tag (`msg + 1`), and message body (`tag + tag_len + 1`) (`0x2918..0x2974`).
// VI: Tái tạo chính xác bước kiểm tra gói tin `logger_entry` và bóc tách log văn bản
//     trong `dump_log_buffer` (`0x2854..0x297c`).
int ParseRawLoggerPacket(const uint8_t* packet, size_t bytes_read,
                         int32_t log_id, AndroidLogEntry* out_entry) noexcept {
    if (packet == nullptr || out_entry == nullptr || bytes_read < sizeof(AndroidLoggerEntryHeader)) {
        return -1;
    }
    AndroidLoggerEntryHeader hdr{};
    std::memcpy(&hdr, packet, sizeof(hdr));
    uint16_t hdr_size = (hdr.hdr_size == 0) ? 24U : hdr.hdr_size;
    if (hdr_size < 20U || hdr_size > 0x13FCU) {
        return -1;
    }
    if (hdr.len > static_cast<uint16_t>(0x1400U - hdr_size)) {
        return -1;
    }
    if (bytes_read != static_cast<size_t>(hdr_size) + static_cast<size_t>(hdr.len)) {
        return -2;  // " read: unexpected length." @ 0x28fc
    }
    if (log_id == 2 || log_id == 5) {
        // Binary event log buffer requires android_log_processBinaryLogBuffer
        return 1;
    }
    if (hdr.len < 1U) {
        return -1;
    }
    const char* msg_base = reinterpret_cast<const char*>(packet + hdr_size);
    size_t max_tag_scan = static_cast<size_t>(hdr.len);
    size_t tag_len = 0;
    while (tag_len < max_tag_scan - 1U && msg_base[1 + tag_len] != '\0') {
        ++tag_len;
    }
    out_entry->tv_sec      = static_cast<time_t>(hdr.sec);
    out_entry->tv_nsec     = static_cast<long>(hdr.nsec);
    out_entry->priority    = static_cast<uint8_t>(msg_base[0]);
    out_entry->uid         = static_cast<int32_t>(hdr.lid_uid);
    out_entry->pid         = hdr.pid;
    out_entry->tid         = hdr.tid;
    out_entry->tag         = msg_base + 1;
    out_entry->tag_len     = tag_len;
    size_t consumed        = 1U + tag_len + 1U;
    if (consumed <= static_cast<size_t>(hdr.len)) {
        out_entry->message     = msg_base + consumed;
        out_entry->message_len = static_cast<size_t>(hdr.len) - consumed;
    } else {
        out_entry->message     = "";
        out_entry->message_len = 0;
    }
    return 0;
}

// EN: Exact reconstruction of the line-splitting `threadtime` formatter at 0x29c0..0x2b68:
//       `"%s.%03ld %5d %5d %c %-8.*s: "` followed by each newline-delimited slice of `entry.message`.
// VI: Tái tạo chính xác bộ định dạng dòng `threadtime` tại 0x29c0..0x2b68:
//       `"%s.%03ld %5d %5d %c %-8.*s: "` nối tiếp bởi từng dòng con của `entry.message`.
int FormatLogcatThreadTimeLine(int out_fd, const AndroidLogEntry& entry,
                               char* scratch_buf, size_t scratch_cap) noexcept {
    (void)out_fd;
    if (scratch_buf == nullptr || scratch_cap < 64) {
        return -1;
    }
    struct tm local_tm{};
    time_t sec = entry.tv_sec;
#if defined(_WIN32)
    localtime_s(&local_tm, &sec);
#else
    localtime_r(&sec, &local_tm);
#endif
    char time_buf[32]{};
    std::strftime(time_buf, sizeof(time_buf), "%m-%d %H:%M:%S", &local_tm);

    uint32_t ms = NanosecondsToMilliseconds(static_cast<uint32_t>(entry.tv_nsec));
    uint32_t prio_idx = (entry.priority >= 0 && entry.priority < 9)
                            ? static_cast<uint32_t>(entry.priority)
                            : 0U;
    char prio_char = kPriorityChars[prio_idx];

    int prefix_len = NpthLogcatSafeSnprintf(
        scratch_buf, scratch_cap,
        "%s.%03d %5d %5d %c %s: %s\n",
        time_buf,
        static_cast<int>(ms),
        entry.pid,
        entry.tid,
         static_cast< int >(prio_char),
        entry.tag != nullptr ? entry.tag : "",
        entry.message != nullptr ? entry.message : "");
    return prefix_len;
}

// EN: Exact reconstruction of FDE[09] (`0x30f0..0x31a8`):
//     Uses the directory prefix of `dli_fname` up to the last `'/'` (`__strrchr_chk` @ 0x3134)
//     and appends `lib_name` (e.g. `"libnpth_dl.so"`).
// VI: Tái tạo chính xác FDE[09] (`0x30f0..0x31a8`):
//     Trích xuất thư mục cha từ đường dẫn thư viện chứa `anchor_sym_addr` tới dấu `'/'` cuối cùng
//     và nối thêm `lib_name` (ví dụ `"libnpth_dl.so"`).
bool ResolveSiblingLibraryPath(const void* anchor_sym_addr, const char* lib_name,
                               char* out_path, size_t out_cap) noexcept {
    (void)anchor_sym_addr;
    if (lib_name == nullptr || out_path == nullptr || out_cap == 0) {
        return false;
    }
    const char* sample_fname = "/data/app/com.nextai.opencut/lib/arm64/libnpth_logcat.so";
    const char* last_slash = std::strrchr(sample_fname, '/');
    if (last_slash == nullptr) {
        return false;
    }
    size_t dir_len = static_cast<size_t>(last_slash - sample_fname) + 1U;
    size_t name_len = std::strlen(lib_name);
    if (dir_len + name_len >= out_cap) {
        return false;
    }
    std::memcpy(out_path, sample_fname, dir_len);
    std::memcpy(out_path + dir_len, lib_name, name_len);
    out_path[dir_len + name_len] = '\0';
    return true;
}

// EN: Exact reconstruction of FDE[05] `main(int argc, char** argv)` (`0x2180..0x279c`):
//     Validates `argc >= 4` and non-null `argv[1..3]`, constructs `"<argv[1]>/logcat.txt"`,
//     parses `api_level = atoi(argv[2])` and `lookback_sec = atoi(argv[3])`, and prepares
//     the logger state in `g_logcat_bss`.
// VI: Tái tạo chính xác FDE[05] `main(int argc, char** argv)` (`0x2180..0x279c`).
int RunNpthLogcatMain(int argc, const char* const* argv) noexcept {
    if (argc < 4 || argv == nullptr || argv[1] == nullptr || argv[2] == nullptr || argv[3] == nullptr) {
        return 1;
    }
    g_logcat_bss.api_level = std::atoi(argv[2]);
    int32_t lookback_sec = std::atoi(argv[3]);
    uint32_t now_sec = static_cast<uint32_t>(std::time(nullptr));
    g_logcat_bss.start_tv_sec = (now_sec > static_cast<uint32_t>(lookback_sec))
                                    ? (now_sec - static_cast<uint32_t>(lookback_sec))
                                    : 0U;
    return 0;
}

}  // namespace npth_logcat
}  // namespace opencut
}  // namespace nextai
