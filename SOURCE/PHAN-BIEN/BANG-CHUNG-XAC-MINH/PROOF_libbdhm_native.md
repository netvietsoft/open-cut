# BẰNG CHỨNG XÁC MINH ĐỐI KHÁNG (ADVERSARIAL PROOF): `libbdhm_native.so` (`TASK-091-RECONSTRUCTION-LIBBDHM_NATIVE` / `TASK_SO_102`)

- **Thư viện gốc**: `SOURCE/apktool-res/lib/arm64-v8a/libbdhm_native.so` (`599,968 bytes`, 78 dynamic symbols: 27 exported + 51 imported)
- **Trạng thái Kiểm định 6 Cổng Agent 13**: `VERIFIED_AND_ACCEPTED`
- **Bố cục Struct ABI (`SparkTracingNative`)**: `[self+0x00]` `Box<dyn NativeClient>` fat pointer, `[self+0x18]` `Arc<RwLock<DeclaredManifest>>`, `[self+0x20]` `Arc<ContextPropsRepo>` (`+0xa0` SwissTable control mask `0x8080808080808080` = `-0x7f7f7f7f7f7f7f80` @ `0x043abc`), `[self+0x28]` `u8 is_enabled` (`ldrb w8, [x20, #0x28]`)
- **Chứng minh Toán học & Đồ thị**: `factorial(n)`, `abs(x)`, `$if/$then/$else`, `$gte/$lte/$eq/$neq/$like/$in`, và phát hiện chu trình đồ thị DAG (`update_link failed add parent: ... from ..., ring exist!` @ `.rodata 0x00c060`)

## Trích xuất Opcode AArch64 Thực tế từ `.text` (`0x03e820..0x046a80`)
```assembly
0x03e820: c0035fd6  ret
0x03e824: c0035fd6  ret
0x03e828: c0035fd6  ret
0x03e82c: c0035fd6  ret
0x03e830: c0035fd6  ret
0x03e834: c0035fd6  ret
0x03e838: c0035fd6  ret
0x03e83c: c0035fd6  ret
0x03e840: ff4303d1  sub      sp, sp, #0xd0
0x03e844: fe6f08a9  stp      x30, x27, [sp, #0x80]
0x03e848: fa6709a9  stp      x26, x25, [sp, #0x90]
0x03e84c: f85f0aa9  stp      x24, x23, [sp, #0xa0]
0x03e850: f6570ba9  stp      x22, x21, [sp, #0xb0]
0x03e854: f44f0ca9  stp      x20, x19, [sp, #0xc0]
0x03e858: f70300aa  mov      x23, x0
0x03e85c: f603012a  mov      w22, w1
0x03e860: e0230091  add      x0, sp, #8
0x03e864: e10317aa  mov      x1, x23
0x03e868: f40303aa  mov      x20, x3
0x03e86c: f30302aa  mov      x19, x2
0x03e870: 54feff97  bl       #0x3e1c0
0x03e874: e80740f9  ldr      x8, [sp, #8]
0x03e878: 280700b4  cbz      x8, #0x3e95c
0x03e87c: f50b40f9  ldr      x21, [sp, #0x10]
0x03e880: 608640a9  ldp      x0, x1, [x19, #8]
0x03e884: e20315aa  mov      x2, x21
0x03e888: 2effff97  bl       #0x3e540
0x03e88c: f80300aa  mov      x24, x0
0x03e890: e20315aa  mov      x2, x21
0x03e894: 808640a9  ldp      x0, x1, [x20, #8]
0x03e898: 2affff97  bl       #0x3e540
0x03e89c: a80240f9  ldr      x8, [x21]
0x03e8a0: f90300aa  mov      x25, x0
0x03e8a4: a10200d0  adrp     x1, #0x94000
0x03e8a8: 21e00091  add      x1, x1, #0x38
0x03e8ac: 1af540f9  ldr      x26, [x8, #0x1e8]
0x03e8b0: e0031aaa  mov      x0, x26
0x03e8b4: f5dbff97  bl       #0x35888
0x03e8b8: e08641a9  ldp      x0, x1, [x23, #0x18]
0x03e8bc: a30200d0  adrp     x3, #0x94000
0x03e8c0: 63400191  add      x3, x3, #0x50
0x03e8c4: e2031faa  mov      x2, xzr
0x03e8c8: fb0640f9  ldr      x27, [x23, #8]
0x03e8cc: 18e2ff97  bl       #0x3712c
0x03e8d0: 020040f9  ldr      x2, [x0]
0x03e8d4: e00315aa  mov      x0, x21
0x03e8d8: e1031baa  mov      x1, x27
0x03e8dc: e303162a  mov      w3, w22
0x03e8e0: e40318aa  mov      x4, x24
0x03e8e4: e50319aa  mov      x5, x25
0x03e8e8: 40033fd6  blr      x26
0x03e8ec: a80240f9  ldr      x8, [x21]
0x03e8f0: a10200d0  adrp     x1, #0x94000
0x03e8f4: 21a00191  add      x1, x1, #0x68
0x03e8f8: 169143f9  ldr      x22, [x8, #0x720]
0x03e8fc: 30240194  bl       #0x879bc
0x03e900: 1a2a0194  bl       #0x89168
0x03e904: 1f1c0072  tst      w0, #0xff
0x03e908: a0020054  b.eq     #0x3e95c
0x03e90c: 55240194  bl       #0x87a60
0x03e910: e80000b4  cbz      x8, #0x3e92c
0x03e914: a80200d0  adrp     x8, #0x94000
0x03e918: 08010291  add      x8, x8, #0x80
0x03e91c: f1230194  bl       #0x878e0
0x03e920: a80200d0  adrp     x8, #0x94000
0x03e924: 08410291  add      x8, x8, #0x90
0x03e928: b02d0194  bl       #0x89fe8
0x03e92c: a80240f9  ldr      x8, [x21]
0x03e930: a10200d0  adrp     x1, #0x94000
0x03e934: 21a00291  add      x1, x1, #0xa8
0x03e938: 164140f9  ldr      x22, [x8, #0x80]
0x03e93c: 20240194  bl       #0x879bc
0x03e940: 36260194  bl       #0x88218
0x03e944: a80240f9  ldr      x8, [x21]
0x03e948: a10200d0  adrp     x1, #0x94000
0x03e94c: 21000391  add      x1, x1, #0xc0
0x03e950: 164540f9  ldr      x22, [x8, #0x88]
0x03e954: 1a240194  bl       #0x879bc
0x03e958: 30260194  bl       #0x88218
0x03e95c: 8e2a0194  bl       #0x89394
0x03e960: 800640a9  ldp      x0, x1, [x20]
0x03e964: 2a8a0094  bl       #0x6120c
0x03e968: 600640a9  ldp      x0, x1, [x19]
0x03e96c: e2260194  bl       #0x884f4
0x03e970: fe6f48a9  ldp      x30, x27, [sp, #0x80]
0x03e974: ff430391  add      sp, sp, #0xd0
0x03e978: 258a0014  b        #0x6120c
0x03e97c: ff8303d1  sub      sp, sp, #0xe0
0x03e980: fe4300f9  str      x30, [sp, #0x80]
0x03e984: fc6f09a9  stp      x28, x27, [sp, #0x90]
0x03e988: fa670aa9  stp      x26, x25, [sp, #0xa0]
0x03e98c: f85f0ba9  stp      x24, x23, [sp, #0xb0]
0x03e990: f6570ca9  stp      x22, x21, [sp, #0xc0]
0x03e994: f44f0da9  stp      x20, x19, [sp, #0xd0]
0x03e998: f70300aa  mov      x23, x0
0x03e99c: f30301aa  mov      x19, x1
0x03e9a0: e0230091  add      x0, sp, #8
0x03e9a4: e10317aa  mov      x1, x23
0x03e9a8: f50303aa  mov      x21, x3
0x03e9ac: f40302aa  mov      x20, x2
0x03e9b0: 04feff97  bl       #0x3e1c0
0x03e9b4: e80740f9  ldr      x8, [sp, #8]
0x03e9b8: 080800b4  cbz      x8, #0x3eab8
0x03e9bc: f60b40f9  ldr      x22, [sp, #0x10]
0x03e9c0: 608640a9  ldp      x0, x1, [x19, #8]
0x03e9c4: e20316aa  mov      x2, x22
0x03e9c8: defeff97  bl       #0x3e540
0x03e9cc: f80300aa  mov      x24, x0
0x03e9d0: e20316aa  mov      x2, x22
0x03e9d4: 808640a9  ldp      x0, x1, [x20, #8]
0x03e9d8: dafeff97  bl       #0x3e540
0x03e9dc: f90300aa  mov      x25, x0
0x03e9e0: e20316aa  mov      x2, x22
0x03e9e4: a08640a9  ldp      x0, x1, [x21, #8]
0x03e9e8: d6feff97  bl       #0x3e540
0x03e9ec: c80240f9  ldr      x8, [x22]
0x03e9f0: fa0300aa  mov      x26, x0
0x03e9f4: a10200d0  adrp     x1, #0x94000
0x03e9f8: 21600391  add      x1, x1, #0xd8
0x03e9fc: 1bf540f9  ldr      x27, [x8, #0x1e8]
0x03ea00: e0031baa  mov      x0, x27
0x03ea04: a1dbff97  bl       #0x35888
0x03ea08: e08641a9  ldp      x0, x1, [x23, #0x18]
0x03ea0c: a30200d0  adrp     x3, #0x94000
0x03ea10: 63c00391  add      x3, x3, #0xf0
0x03ea14: 22008052  mov      w2, #1
0x03ea18: fc0640f9  ldr      x28, [x23, #8]
0x03ea1c: c4e1ff97  bl       #0x3712c
0x03ea20: 020040f9  ldr      x2, [x0]
0x03ea24: e00316aa  mov      x0, x22
0x03ea28: e1031caa  mov      x1, x28
0x03ea2c: e30318aa  mov      x3, x24
0x03ea30: e40319aa  mov      x4, x25
0x03ea34: e5031aaa  mov      x5, x26
0x03ea38: 60033fd6  blr      x27
0x03ea3c: c80240f9  ldr      x8, [x22]
0x03ea40: a10200d0  adrp     x1, #0x94000
0x03ea44: 21200491  add      x1, x1, #0x108
0x03ea48: 179143f9  ldr      x23, [x8, #0x720]
0x03ea4c: 13250194  bl       #0x87e98
0x03ea50: e00316aa  mov      x0, x22
0x03ea54: e0023fd6  blr      x23
0x03ea58: 1f1c0072  tst      w0, #0xff
0x03ea5c: e0020054  b.eq     #0x3eab8
0x03ea60: 00240194  bl       #0x87a60
0x03ea64: e80000b4  cbz      x8, #0x3ea80
0x03ea68: a80200d0  adrp     x8, #0x94000
0x03ea6c: 08810491  add      x8, x8, #0x120
0x03ea70: 9c230194  bl       #0x878e0
0x03ea74: a80200d0  adrp     x8, #0x94000
0x03ea78: 08c10491  add      x8, x8, #0x130
0x03ea7c: 5b2d0194  bl       #0x89fe8
0x03ea80: c80240f9  ldr      x8, [x22]
0x03ea84: a10200d0  adrp     x1, #0x94000
0x03ea88: 21200591  add      x1, x1, #0x148
0x03ea8c: 174140f9  ldr      x23, [x8, #0x80]
0x03ea90: 02250194  bl       #0x87e98
0x03ea94: e00316aa  mov      x0, x22
0x03ea98: e0023fd6  blr      x23
0x03ea9c: c80240f9  ldr      x8, [x22]
0x03eaa0: a10200d0  adrp     x1, #0x94000
0x03eaa4: 21800591  add      x1, x1, #0x160
0x03eaa8: 174540f9  ldr      x23, [x8, #0x88]
0x03eaac: fb240194  bl       #0x87e98
0x03eab0: e00316aa  mov      x0, x22
0x03eab4: e0023fd6  blr      x23
0x03eab8: 372a0194  bl       #0x89394
0x03eabc: a00640a9  ldp      x0, x1, [x21]
0x03eac0: d3890094  bl       #0x6120c
0x03eac4: 800640a9  ldp      x0, x1, [x20]
0x03eac8: d1890094  bl       #0x6120c
0x03eacc: 600640a9  ldp      x0, x1, [x19]
0x03ead0: e8270194  bl       #0x88a70
0x03ead4: fe4340f9  ldr      x30, [sp, #0x80]
0x03ead8: ff830391  add      sp, sp, #0xe0
0x03eadc: cc890014  b        #0x6120c
0x03eae0: fd7bbaa9  stp      x29, x30, [sp, #-0x60]!
0x03eae4: fc6f01a9  stp      x28, x27, [sp, #0x10]
0x03eae8: fa6702a9  stp      x26, x25, [sp, #0x20]
0x03eaec: f85f03a9  stp      x24, x23, [sp, #0x30]
0x03eaf0: f65704a9  stp      x22, x21, [sp, #0x40]
0x03eaf4: f44f05a9  stp      x20, x19, [sp, #0x50]
0x03eaf8: ff0320d1  sub      sp, sp, #0x800
0x03eafc: f40300aa  mov      x20, x0
0x03eb00: e10302aa  mov      x1, x2
0x03eb04: e0030f91  add      x0, sp, #0x3c0
0x03eb08: e20314aa  mov      x2, x20
0x03eb0c: f50303aa  mov      x21, x3
0x03eb10: f3030f91  add      x19, sp, #0x3c0
0x03eb14: 74fdff97  bl       #0x3e0e4
0x03eb18: 73420091  add      x19, x19, #0x10
0x03eb1c: 21018052  mov      w1, #9
0x03eb20: e00313aa  mov      x0, x19
0x03eb24: c1dcff97  bl       #0x35e28
0x03eb28: 880240f9  ldr      x8, [x20]
0x03eb2c: a10200d0  adrp     x1, #0x94000
0x03eb30: 21a01d91  add      x1, x1, #0x768
0x03eb34: 167d40f9  ldr      x22, [x8, #0xf8]
0x03eb38: a1230194  bl       #0x879bc
0x03eb3c: d42c0194  bl       #0x89e8c
0x03eb40: c03001b4  cbz      x0, #0x41158
0x03eb44: 880240f9  ldr      x8, [x20]
0x03eb48: f60300aa  mov      x22, x0
0x03eb4c: a10200d0  adrp     x1, #0x94000
0x03eb50: 21a01e91  add      x1, x1, #0x7a8
0x03eb54: c0230194  bl       #0x87a54
0x03eb58: 62feffd0  adrp     x2, #0xc000
0x03eb5c: 423c2591  add      x2, x2, #0x94f
0x03eb60: 63feffd0  adrp     x3, #0xc000
0x03eb64: 63202791  add      x3, x3, #0x9c8
0x03eb68: c1230194  bl       #0x87a6c
0x03eb6c: 803001b4  cbz      x0, #0x4117c
0x03eb70: 40240194  bl       #0x87c70
0x03eb74: 880240f9  ldr      x8, [x20]
0x03eb78: a10200d0  adrp     x1, #0x94000
0x03eb7c: 21a01f91  add      x1, x1, #0x7e8
0x03eb80: b5230194  bl       #0x87a54
0x03eb84: 62feffd0  adrp     x2, #0xc000
0x03eb88: 427c2891  add      x2, x2, #0xa1f
0x03eb8c: 63feffd0  adrp     x3, #0xc000
0x03eb90: 63202791  add      x3, x3, #0x9c8
0x03eb94: b6230194  bl       #0x87a6c
0x03eb98: e02f01b4  cbz      x0, #0x41194
0x03eb9c: 35240194  bl       #0x87c70
0x03eba0: 880240f9  ldr      x8, [x20]
0x03eba4: a10200d0  adrp     x1, #0x94000
0x03eba8: 21a02091  add      x1, x1, #0x828
0x03ebac: aa230194  bl       #0x87a54
0x03ebb0: 62feffd0  adrp     x2, #0xc000
0x03ebb4: 42802991  add      x2, x2, #0xa60
0x03ebb8: 63feffd0  adrp     x3, #0xc000
0x03ebbc: 63202791  add      x3, x3, #0x9c8
0x03ebc0: ab230194  bl       #0x87a6c
0x03ebc4: 402f01b4  cbz      x0, #0x411ac
0x03ebc8: 2a240194  bl       #0x87c70
0x03ebcc: 880240f9  ldr      x8, [x20]
0x03ebd0: a10200d0  adrp     x1, #0x94000
0x03ebd4: 21a02191  add      x1, x1, #0x868
0x03ebd8: 9f230194  bl       #0x87a54
0x03ebdc: 62feffd0  adrp     x2, #0xc000
0x03ebe0: 428c2a91  add      x2, x2, #0xaa3
0x03ebe4: 63feffd0  adrp     x3, #0xc000
0x03ebe8: 63c82a91  add      x3, x3, #0xab2
0x03ebec: a0230194  bl       #0x87a6c
0x03ebf0: a02e01b4  cbz      x0, #0x411c4
0x03ebf4: 1f240194  bl       #0x87c70
0x03ebf8: 880240f9  ldr      x8, [x20]
0x03ebfc: a10200d0  adrp     x1, #0x94000
0x03ec00: 21a02291  add      x1, x1, #0x8a8
0x03ec04: 94230194  bl       #0x87a54
0x03ec08: 62feffd0  adrp     x2, #0xc000
0x03ec0c: 42942b91  add      x2, x2, #0xae5
0x03ec10: 63feffd0  adrp     x3, #0xc000
0x03ec14: 63c82a91  add      x3, x3, #0xab2
0x03ec18: 95230194  bl       #0x87a6c
0x03ec1c: 002e01b4  cbz      x0, #0x411dc
0x03ec20: 14240194  bl       #0x87c70
0x03ec24: 880240f9  ldr      x8, [x20]
0x03ec28: a10200d0  adrp     x1, #0x94000
0x03ec2c: 21a02391  add      x1, x1, #0x8e8
0x03ec30: 89230194  bl       #0x87a54
0x03ec34: 62feffd0  adrp     x2, #0xc000
0x03ec38: 42682c91  add      x2, x2, #0xb1a
0x03ec3c: 63feffd0  adrp     x3, #0xc000
0x03ec40: 63c82a91  add      x3, x3, #0xab2
0x03ec44: 8a230194  bl       #0x87a6c
0x03ec48: 602d01b4  cbz      x0, #0x411f4
0x03ec4c: 09240194  bl       #0x87c70
0x03ec50: 880240f9  ldr      x8, [x20]
0x041410: 5f1c0072  tst      w2, #0xff
0x041414: e0079f1a  cset     w0, ne
0x041418: 4e280014  b        #0x4b550
0x04141c: fd7bbaa9  stp      x29, x30, [sp, #-0x60]!
0x041420: fc6f01a9  stp      x28, x27, [sp, #0x10]
0x041424: fa6702a9  stp      x26, x25, [sp, #0x20]
0x041428: f85f03a9  stp      x24, x23, [sp, #0x30]
0x04142c: f65704a9  stp      x22, x21, [sp, #0x40]
0x041430: f44f05a9  stp      x20, x19, [sp, #0x50]
0x041434: ff430ed1  sub      sp, sp, #0x390
0x041438: e01f00f9  str      x0, [sp, #0x38]
0x04143c: 810200f0  adrp     x1, #0x94000
0x041440: 21402b91  add      x1, x1, #0xad0
0x041444: e00302aa  mov      x0, x2
0x041448: f40302aa  mov      x20, x2
0x04144c: f9430891  add      x25, sp, #0x210
0x041450: fbe30391  add      x27, sp, #0xf8
0x041454: 15d1ff97  bl       #0x358a8
0x041458: a0018052  mov      w0, #0xd
0x04145c: b3018052  mov      w19, #0xd
0x041460: ac7f0094  bl       #0x61310
0x041464: 68feff90  adrp     x8, #0xd000
0x041468: 080d3491  add      x8, x8, #0xd03
0x04146c: e08707a9  stp      x0, x1, [sp, #0x78]
0x041470: 00108052  mov      w0, #0x80
0x041474: 095140f8  ldur     x9, [x8, #5]
0x041478: 080140f9  ldr      x8, [x8]
0x04147c: 295000f8  stur     x9, [x1, #5]
0x041480: 280000f9  str      x8, [x1]
0x041484: 950e40f9  ldr      x21, [x20, #0x18]
0x041488: f34700f9  str      x19, [sp, #0x88]
0x04148c: a17f0094  bl       #0x61310
0x041490: a2feffd0  adrp     x2, #0x17000
0x041494: 425c2691  add      x2, x2, #0x997
0x041498: e8e30991  add      x8, sp, #0x278
0x04149c: e03f01f9  str      x0, [sp, #0x278]
0x0414a0: e14301f9  str      x1, [sp, #0x280]
0x0414a4: 41040091  add      x1, x2, #1
0x0414a8: e0e30991  add      x0, sp, #0x278
0x0414ac: ff4701f9  str      xzr, [sp, #0x288]
0x0414b0: e88f01f9  str      x8, [sp, #0x318]
0x0414b4: 1f9b0094  bl       #0x68130
0x0414b8: e8630c91  add      x8, sp, #0x318
0x0414bc: 29008052  mov      w9, #1
0x0414c0: 61feff90  adrp     x1, #0xd000
0x0414c4: 21503691  add      x1, x1, #0xd94
0x0414c8: e0430591  add      x0, sp, #0x150
0x0414cc: c2008052  mov      w2, #6
0x0414d0: e8ab00f9  str      x8, [sp, #0x150]
0x0414d4: e9630539  strb     w9, [sp, #0x158]
0x0414d8: c4e1ff97  bl       #0x39be8
0x0414dc: f3ab40f9  ldr      x19, [sp, #0x150]
0x0414e0: b01f0194  bl       #0x893a0
0x0414e4: a83e40f9  ldr      x8, [x21, #0x78]
0x0414e8: 080300b4  cbz      x8, #0x41548
0x0414ec: ea0308aa  mov      x10, x8
0x0414f0: a93240f9  ldr      x9, [x21, #0x60]
0x0414f4: ecc301b2  mov      x12, #-0x7f7f7f7f7f7f7f80
0x0414f8: a23a40f9  ldr      x2, [x21, #0x70]
0x0414fc: e0830d91  add      x0, sp, #0x360
0x041500: e10313aa  mov      x1, x19
0x041504: 4b8540f8  ldr      x11, [x10], #8
0x041508: 2901088b  add      x9, x9, x8
0x04150c: e8a701f9  str      x8, [sp, #0x348]
0x041510: 29050091  add      x9, x9, #1
0x041514: ea9f01f9  str      x10, [sp, #0x338]
0x041518: 8b012b8a  bic      x11, x12, x11
0x04151c: e2ab01f9  str      x2, [sp, #0x350]
0x041520: f3830d91  add      x19, sp, #0x360
0x041524: e9a301f9  str      x9, [sp, #0x340]
0x041528: eb9b01f9  str      x11, [sp, #0x330]
0x04152c: 46e8ff97  bl       #0x3b644
0x041530: e8a34d39  ldrb     w8, [sp, #0x368]
0x041534: e9b341f9  ldr      x9, [sp, #0x360]
0x041538: 1f0d0071  cmp      w8, #3
0x04153c: c1050054  b.ne     #0x415f4
0x041540: f50309aa  mov      x21, x9
0x041544: e5020014  b        #0x420d8
0x041548: a6200194  bl       #0x897e0
0x04154c: a3224339  ldrb     w3, [x21, #0xc8]
0x041550: 61feff90  adrp     x1, #0xd000
0x0429a0: ffc303d1  sub      sp, sp, #0xf0
0x0429a4: fe6300f9  str      x30, [sp, #0xc0]
0x0429a8: f6570da9  stp      x22, x21, [sp, #0xd0]
0x0429ac: f44f0ea9  stp      x20, x19, [sp, #0xe0]
0x0429b0: 2f1d0194  bl       #0x89e6c
0x0429b4: e0230091  add      x0, sp, #8
0x0429b8: e20313aa  mov      x2, x19
0x0429bc: f6430291  add      x22, sp, #0x90
0x0429c0: 5eeeff97  bl       #0x3e338
0x0429c4: 810200d0  adrp     x1, #0x94000
0x0429c8: 21a02b91  add      x1, x1, #0xae8
0x0429cc: 5b1e0194  bl       #0x8a338
0x0429d0: e0830091  add      x0, sp, #0x20
0x0429d4: e1230091  add      x1, sp, #8
0x0429d8: 4f180094  bl       #0x48b14
0x0429dc: e0430291  add      x0, sp, #0x90
0x0429e0: e1830091  add      x1, sp, #0x20
0x0429e4: c2170094  bl       #0x488ec
0x0429e8: 880e40f9  ldr      x8, [x20, #0x18]
0x0429ec: 15810191  add      x21, x8, #0x60
0x0429f0: e00315aa  mov      x0, x21
0x0429f4: 6dc8ff97  bl       #0x34ba8
0x0429f8: e1830091  add      x1, sp, #0x20
0x0429fc: e00315aa  mov      x0, x21
0x042a00: c51e0194  bl       #0x8a514
0x042a04: 941240f9  ldr      x20, [x20, #0x20]
0x042a08: 80020491  add      x0, x20, #0x100
0x042a0c: ffc8ff97  bl       #0x34e08
0x042a10: c00640ad  ldp      q0, q1, [x22]
0x042a14: e08740a9  ldp      x0, x1, [sp, #8]
0x042a18: 800608ad  stp      q0, q1, [x20, #0x100]
0x042a1c: c20ac03d  ldr      q2, [x22, #0x20]
0x042a20: 824a803d  str      q2, [x20, #0x120]
0x042a24: ac180194  bl       #0x88cd4
0x042a28: 21008052  mov      w1, #1
0x042a2c: 38efff97  bl       #0x3e70c
0x042a30: f44f4ea9  ldp      x20, x19, [sp, #0xe0]
0x042a34: f6574da9  ldp      x22, x21, [sp, #0xd0]
0x042a38: fe6340f9  ldr      x30, [sp, #0xc0]
0x042a3c: 7d1d0114  b        #0x8a030
0x042a40: ff4307d1  sub      sp, sp, #0x1d0
0x042a44: fdd300f9  str      x29, [sp, #0x1a0]
0x042a48: fe571ba9  stp      x30, x21, [sp, #0x1b0]
0x042a4c: f44f1ca9  stp      x20, x19, [sp, #0x1c0]
0x042a50: 071d0194  bl       #0x89e6c
0x042a54: e0030091  mov      x0, sp
0x042a58: b7180194  bl       #0x88d34
0x042a5c: 810200d0  adrp     x1, #0x94000
0x042a60: 21002c91  add      x1, x1, #0xb00
0x042a64: 351e0194  bl       #0x8a338
0x042a68: 88a24039  ldrb     w8, [x20, #0x28]
0x042a6c: 480a0034  cbz      w8, #0x42bb4
0x042a70: 811240f9  ldr      x1, [x20, #0x20]
0x042a74: e0630091  add      x0, sp, #0x18
0x042a78: e2030091  mov      x2, sp
0x042a7c: e6eaff97  bl       #0x3d614
0x042a80: e80f40f9  ldr      x8, [sp, #0x18]
0x042a84: 880900b4  cbz      x8, #0x42bb4
0x042a88: e00741ad  ldp      q0, q1, [sp, #0x20]
0x042a8c: e203c43c  ldur     q2, [sp, #0x40]
0x042a90: e08702ad  stp      q0, q1, [sp, #0x50]
0x042a94: e21f803d  str      q2, [sp, #0x70]
0x042a98: aa790094  bl       #0x61140
0x042a9c: cb140194  bl       #0x87dc8
0x042aa0: e0870aa9  stp      x0, x1, [sp, #0xa8]
0x042aa4: e0e30291  add      x0, sp, #0xb8
0x042aa8: e1430191  add      x1, sp, #0x50
0x042aac: ffff08a9  stp      xzr, xzr, [sp, #0x88]
0x042ab0: ffa309a9  stp      xzr, x8, [sp, #0x98]
0x042ab4: 60c2ff97  bl       #0x33434
0x042ab8: e8e30391  add      x8, sp, #0xf8
0x042abc: 14610091  add      x20, x8, #0x18
0x042ac0: e0e30391  add      x0, sp, #0xf8
0x042ac4: e1e30291  add      x1, sp, #0xb8
0x042ac8: f4baff97  bl       #0x31698
0x042acc: e8434439  ldrb     w8, [sp, #0x110]
0x042ad0: 1f110071  cmp      w8, #4
0x042ad4: 80020054  b.eq     #0x42b24
0x042ad8: 810a40ad  ldp      q1, q2, [x20]
0x042adc: e0230691  add      x0, sp, #0x188
0x042ae0: e1430591  add      x1, sp, #0x150
0x042ae4: e083cf3c  ldur     q0, [sp, #0xf8]
0x042ae8: e18b0aad  stp      q1, q2, [sp, #0x150]
0x042aec: e88740f9  ldr      x8, [sp, #0x108]
0x042af0: e04f803d  str      q0, [sp, #0x130]
0x042af4: e8a300f9  str      x8, [sp, #0x140]
0x042af8: 13e9ff97  bl       #0x3cf44
0x042afc: e0c30591  add      x0, sp, #0x170
0x042b00: e1230291  add      x1, sp, #0x88
0x042b04: e2c30491  add      x2, sp, #0x130
0x042b08: e3230691  add      x3, sp, #0x188
0x042b0c: 80690094  bl       #0x5d10c
0x042b10: e0c30591  add      x0, sp, #0x170
0x042b14: 3bc8ff97  bl       #0x34c00
0x042b18: e0430591  add      x0, sp, #0x150
0x042b1c: 34c8ff97  bl       #0x34bec
0x042b20: e8ffff17  b        #0x42ac0
0x042b24: e0e30291  add      x0, sp, #0xb8
0x042b28: f4e30291  add      x20, sp, #0xb8
0x042b2c: 5ac6ff97  bl       #0x34494
0x042b30: 431c0194  bl       #0x89c3c
0x042b34: e17f0ca9  stp      x1, xzr, [sp, #0xc0]
0x042b38: e1e30391  add      x1, sp, #0xf8
0x042b3c: e05f00f9  str      x0, [sp, #0xb8]
0x042b40: e0230291  add      x0, sp, #0x88
0x042b44: f47f00f9  str      x20, [sp, #0xf8]
0x042b48: 52cfff97  bl       #0x36890
0x042b4c: e16340f9  ldr      x1, [sp, #0xc0]
0x042b50: c00000b4  cbz      x0, #0x42b68
0x042b54: f40300aa  mov      x20, x0
0x042b58: e05f40f9  ldr      x0, [sp, #0xb8]
0x042b5c: ac790094  bl       #0x6120c
0x042b60: f4ff0ba9  stp      x20, xzr, [sp, #0xb8]
0x042b64: 06000014  b        #0x42b7c
0x042b68: f45f40f9  ldr      x20, [sp, #0xb8]
0x042b6c: a1ffffb4  cbz      x1, #0x42b60
0x042b70: e86740f9  ldr      x8, [sp, #0xc8]
0x042b74: f4870ba9  stp      x20, x1, [sp, #0xb8]
0x042b78: e86700f9  str      x8, [sp, #0xc8]
0x042b7c: e0e30391  add      x0, sp, #0xf8
0x042b80: e1e30291  add      x1, sp, #0xb8
0x042b84: 83cbff97  bl       #0x35990
0x042b88: e0230291  add      x0, sp, #0x88
0x042b8c: d8650094  bl       #0x5c2ec
0x042b90: f48340f9  ldr      x20, [sp, #0x100]
0x042b94: 140100b4  cbz      x20, #0x42bb4
0x042b98: e18740f9  ldr      x1, [sp, #0x108]
0x042b9c: 851b0194  bl       #0x899b0
0x042ba0: f57f40f9  ldr      x21, [sp, #0xf8]
0x042ba4: 67eeff97  bl       #0x3e540
0x042ba8: f30300aa  mov      x19, x0
0x042bac: 4f180194  bl       #0x88ce8
0x042bb0: 02000014  b        #0x42bb8
0x042bb4: f3031faa  mov      x19, xzr
0x042bb8: e00740a9  ldp      x0, x1, [sp]
0x042bbc: 46180194  bl       #0x88cd4
0x042bc0: fdd340f9  ldr      x29, [sp, #0x1a0]
0x042bc4: f44f5ca9  ldp      x20, x19, [sp, #0x1c0]
0x042bc8: fe575ba9  ldp      x30, x21, [sp, #0x1b0]
0x042bcc: ff430791  add      sp, sp, #0x1d0
0x042bd0: c0035fd6  ret
0x042bd4: ff0303d1  sub      sp, sp, #0xc0
0x042bd8: fe4b00f9  str      x30, [sp, #0x90]
0x042bdc: f6570aa9  stp      x22, x21, [sp, #0xa0]
0x042be0: f44f0ba9  stp      x20, x19, [sp, #0xb0]
0x042be4: f30300aa  mov      x19, x0
0x042be8: e10303aa  mov      x1, x3
0x042bec: f50302aa  mov      x21, x2
0x042bf0: e0230091  add      x0, sp, #8
0x042bf4: e20313aa  mov      x2, x19
0x042bf8: f403052a  mov      w20, w5
0x042bfc: f60304aa  mov      x22, x4
0x042c00: ceedff97  bl       #0x3e338
0x042c04: e0830091  add      x0, sp, #0x20
0x042c08: e10316aa  mov      x1, x22
0x042c0c: 4a180194  bl       #0x88d34
0x042c10: 810200d0  adrp     x1, #0x94000
0x042c14: 21602c91  add      x1, x1, #0xb18
0x042c18: 6d1e0194  bl       #0x8a5cc
0x042c1c: a8a24039  ldrb     w8, [x21, #0x28]
0x042c20: 68030034  cbz      w8, #0x42c8c
0x042c24: 9f1e0072  tst      w20, #0xff
0x042c28: a11240f9  ldr      x1, [x21, #0x20]
0x042c2c: e4079f1a  cset     w4, ne
0x042c30: e0430191  add      x0, sp, #0x50
0x042c34: e2230091  add      x2, sp, #8
0x042c38: e3830091  add      x3, sp, #0x20
0x042c3c: 32ebff97  bl       #0x3d904
0x042c40: e8434139  ldrb     w8, [sp, #0x50]
0x042c44: 1f110071  cmp      w8, #4
```
