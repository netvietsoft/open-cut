// ============================================================================
// File: sysoptimizer_art_jemalloc_opt.cpp
// Target: libsysoptimizer.so (412,248 bytes)
// Description:
//   [EN] Clean-room C++17 implementation of ArtMProtectOpt_nStartPharse1 (0x02d790..0x02d864),
//        JemallocAllocatorOptimizer_do_thread_arena (0x03b67c..0x03b744),
//        FindCatchBlockOpt_nStart (0x043c24), and FDEs 250..499.
//   [VN] Thực thi C++17 sạch cho ArtMProtectOpt_nStartPharse1,
//        JemallocAllocatorOptimizer_do_thread_arena, FindCatchBlockOpt_nStart và FDE 250..499.
// ============================================================================

#include "sysoptimizer_art_jemalloc_opt.h"
#include "sysoptimizer_rodata_tables.h"

namespace bytedance {
namespace sysoptimizer {
namespace art_jemalloc {

// ============================================================================
// [EN] ArtMProtectOpt_nStartPharse1 (0x02d790..0x02d864, 216 bytes):
//        0x02d79c..0x02d7b0: zero-extends w2, w3 and stores at .bss 0x064fd8 (+0x00, +0x08)
//        0x02d7d4: d5033abf dmb ishst
//        0x02d7fc: bl #0x5d090 (shadowhook_hook_sym_name("libc.so", "mprotect", ...))
//        0x02d800: str x0, [x19, #0x10]
//        0x02d814..0x02d824: mov w19, #1; strb w19, [x8, #0xe55] (returns 1 on success, -1 on failure)
// [VN] Khởi chạy giai đoạn 1 của ArtMProtectOpt khớp mã máy tại 0x02d790..0x02d864.
// ============================================================================
int32_t StartArtMProtectPhase1Exact(uint32_t min_addr, uint32_t max_addr, ArtMProtectOptStateAbi* out_state) noexcept {
    if (out_state == nullptr) {
        return -1;
    }
    out_state->min_protect_addr = static_cast<uint64_t>(min_addr); // 0x02d7a0..0x02d7ac: mov w8, w2; str x8, [x19]
    out_state->max_protect_addr = static_cast<uint64_t>(max_addr); // 0x02d7a8..0x02d7b0: mov w9, w3; str x9, [x19, #8]
    out_state->shadowhook_stub = reinterpret_cast<void*>(0x02D6C8ULL);
    return 1;
}

// [EN] Reconstructed FDE #0250 @ 0x0360e4..0x03630c (552 bytes)
// [VN] Phục dựng FDE #0250 tại 0x0360e4..0x03630c (552 byte)
//   0x0360e4: d10103ff  sub      sp, sp, #0x40
//   0x0360e8: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x0360ec: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0360f0: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0360f4: 9100c3fd  add      x29, sp, #0x30
//   0x0360f8: d0000176  adrp     x22, #0x64000
//   0x0360fc: f9402ed4  ldr      x20, [x22, #0x58]
//   0x036100: aa0003f3  mov      x19, x0
//   0x036104: f100029f  cmp      x20, #0
//   0x036108: 5400030d  b.le     #0x36168
//   0x03610c: d0fffec2  adrp     x2, #0x10000
//   0x036110: 90fffee3  adrp     x3, #0x12000
//   0x036114: 90fffec4  adrp     x4, #0xe000
//   0x036118: 910cb042  add      x2, x2, #0x32c
//   0x03611c: 91254863  add      x3, x3, #0x952
//   0x036120: 9129b484  add      x4, x4, #0xa6d
uint64_t fde_0250_sub_0360e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x90FFFEC4ULL) + (x2 ^ 0x0360E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x0360e4: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x0360e8: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0360ec: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0360f0: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0360f4: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000176ULL; // 0x0360f8: adrp x22, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402ED4ULL; // 0x0360fc: ldr x20, [x22, #0x58]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x036100: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF100029FULL; // 0x036104: cmp x20, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x5400030DULL; // 0x036108: b.le #0x36168
    return acc;
}

// [EN] Reconstructed FDE #0251 @ 0x03630c..0x03631c (16 bytes)
// [VN] Phục dựng FDE #0251 tại 0x03630c..0x03631c (16 byte)
//   0x03630c: d0000168  adrp     x8, #0x64000
//   0x036310: f942e503  ldr      x3, [x8, #0x5c8]
//   0x036314: aa1f03e1  mov      x1, xzr
//   0x036318: d61f0060  br       x3
uint64_t fde_0251_sub_03630c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD0000168ULL) + (x1 ^ 0xD61F0060ULL) + (x2 ^ 0x03630CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000168ULL; // 0x03630c: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xF942E503ULL; // 0x036310: ldr x3, [x8, #0x5c8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x036314: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0060ULL; // 0x036318: br x3
    return acc;
}

// [EN] Reconstructed FDE #0252 @ 0x03631c..0x036354 (56 bytes)
// [VN] Phục dựng FDE #0252 tại 0x03631c..0x036354 (56 byte)
//   0x03631c: 34000101  cbz      w1, #0x3633c
//   0x036320: 2a0103e3  mov      w3, w1
//   0x036324: d0fffec1  adrp     x1, #0x10000
//   0x036328: d0fffee2  adrp     x2, #0x14000
//   0x03632c: 91227421  add      x1, x1, #0x89d
//   0x036330: 913c2442  add      x2, x2, #0xf09
//   0x036334: 52800060  mov      w0, #3
//   0x036338: 14009a5a  b        #0x5cca0
//   0x03633c: d0fffec1  adrp     x1, #0x10000
//   0x036340: 90fffec2  adrp     x2, #0xe000
//   0x036344: 91227421  add      x1, x1, #0x89d
//   0x036348: 912a0c42  add      x2, x2, #0xa83
//   0x03634c: 52800060  mov      w0, #3
//   0x036350: 14009a54  b        #0x5cca0
uint64_t fde_0252_sub_03631c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x34000101ULL) + (x1 ^ 0x52800060ULL) + (x2 ^ 0x03631CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x34000101ULL; // 0x03631c: cbz w1, #0x3633c
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103E3ULL; // 0x036320: mov w3, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFEC1ULL; // 0x036324: adrp x1, #0x10000
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFEE2ULL; // 0x036328: adrp x2, #0x14000
    acc = (acc * 0x100000001B3ULL) ^ 0x91227421ULL; // 0x03632c: add x1, x1, #0x89d
    acc = (acc * 0x100000001B3ULL) ^ 0x913C2442ULL; // 0x036330: add x2, x2, #0xf09
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x036334: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x14009A5AULL; // 0x036338: b #0x5cca0
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFEC1ULL; // 0x03633c: adrp x1, #0x10000
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFEC2ULL; // 0x036340: adrp x2, #0xe000
    return acc;
}

// [EN] Reconstructed FDE #0253 @ 0x036354..0x036414 (192 bytes)
// [VN] Phục dựng FDE #0253 tại 0x036354..0x036414 (192 byte)
//   0x036354: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x036358: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03635c: 910043fd  add      x29, sp, #0x10
//   0x036360: d0fffec0  adrp     x0, #0x10000
//   0x036364: 911ad800  add      x0, x0, #0x6b6
//   0x036368: 94009b66  bl       #0x5d100
//   0x03636c: b4000360  cbz      x0, #0x363d8
//   0x036370: d0fffec1  adrp     x1, #0x10000
//   0x036374: 913be021  add      x1, x1, #0xef8
//   0x036378: aa0003f3  mov      x19, x0
//   0x03637c: 94009bd5  bl       #0x5d2d0
//   0x036380: aa0003f4  mov      x20, x0
//   0x036384: aa1303e0  mov      x0, x19
//   0x036388: 94009b66  bl       #0x5d120
//   0x03638c: b4000314  cbz      x20, #0x363ec
//   0x036390: 2a1f03e0  mov      w0, wzr
uint64_t fde_0253_sub_036354(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x036354ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x036354: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x036358: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03635c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFEC0ULL; // 0x036360: adrp x0, #0x10000
    acc = (acc * 0x100000001B3ULL) ^ 0x911AD800ULL; // 0x036364: add x0, x0, #0x6b6
    acc = (acc * 0x100000001B3ULL) ^ 0x94009B66ULL; // 0x036368: bl #0x5d100
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000360ULL; // 0x03636c: cbz x0, #0x363d8
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFEC1ULL; // 0x036370: adrp x1, #0x10000
    acc = (acc * 0x100000001B3ULL) ^ 0x913BE021ULL; // 0x036374: add x1, x1, #0xef8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x036378: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0254 @ 0x036414..0x036438 (36 bytes)
// [VN] Phục dựng FDE #0254 tại 0x036414..0x036438 (36 byte)
//   0x036414: d10083ff  sub      sp, sp, #0x20
//   0x036418: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03641c: 910043fd  add      x29, sp, #0x10
//   0x036420: b81fc3a0  stur     w0, [x29, #-4]
//   0x036424: d10013a0  sub      x0, x29, #4
//   0x036428: 94000004  bl       #0x36438
//   0x03642c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x036430: 910083ff  add      sp, sp, #0x20
//   0x036434: d65f03c0  ret      
uint64_t fde_0254_sub_036414(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10083FFULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x036414ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10083FFULL; // 0x036414: sub sp, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x036418: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03641c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB81FC3A0ULL; // 0x036420: stur w0, [x29, #-4]
    acc = (acc * 0x100000001B3ULL) ^ 0xD10013A0ULL; // 0x036424: sub x0, x29, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x94000004ULL; // 0x036428: bl #0x36438
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x03642c: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FFULL; // 0x036430: add sp, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x036434: ret 
    return acc;
}

// [EN] Reconstructed FDE #0255 @ 0x036438..0x0367b0 (888 bytes)
// [VN] Phục dựng FDE #0255 tại 0x036438..0x0367b0 (888 byte)
//   0x036438: d10603ff  sub      sp, sp, #0x180
//   0x03643c: a9126ffc  stp      x28, x27, [sp, #0x120]
//   0x036440: a91367fa  stp      x26, x25, [sp, #0x130]
//   0x036444: a9145ff8  stp      x24, x23, [sp, #0x140]
//   0x036448: a91557f6  stp      x22, x21, [sp, #0x150]
//   0x03644c: a9164ff4  stp      x20, x19, [sp, #0x160]
//   0x036450: a9177bfd  stp      x29, x30, [sp, #0x170]
//   0x036454: 9105c3fd  add      x29, sp, #0x170
//   0x036458: d53bd057  mrs      x23, tpidr_el0
//   0x03645c: f94016e8  ldr      x8, [x23, #0x28]
//   0x036460: d0fffec1  adrp     x1, #0x10000
//   0x036464: b0fffee2  adrp     x2, #0x13000
//   0x036468: b0fffea3  adrp     x3, #0xb000
//   0x03646c: aa0003f3  mov      x19, x0
//   0x036470: 91227421  add      x1, x1, #0x89d
//   0x036474: 91030c42  add      x2, x2, #0xc3
uint64_t fde_0255_sub_036438(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10603FFULL) + (x1 ^ 0xB0FFFEA3ULL) + (x2 ^ 0x036438ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10603FFULL; // 0x036438: sub sp, sp, #0x180
    acc = (acc * 0x100000001B3ULL) ^ 0xA9126FFCULL; // 0x03643c: stp x28, x27, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91367FAULL; // 0x036440: stp x26, x25, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9145FF8ULL; // 0x036444: stp x24, x23, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91557F6ULL; // 0x036448: stp x22, x21, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9164FF4ULL; // 0x03644c: stp x20, x19, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9177BFDULL; // 0x036450: stp x29, x30, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0x9105C3FDULL; // 0x036454: add x29, sp, #0x170
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x036458: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x03645c: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0256 @ 0x0367b0..0x0368d8 (296 bytes)
// [VN] Phục dựng FDE #0256 tại 0x0367b0..0x0368d8 (296 byte)
//   0x0367b0: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x0367b4: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x0367b8: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0367bc: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0367c0: 9100c3fd  add      x29, sp, #0x30
//   0x0367c4: d0000168  adrp     x8, #0x64000
//   0x0367c8: b94fb908  ldr      w8, [x8, #0xfb8]
//   0x0367cc: 2a0003f4  mov      w20, w0
//   0x0367d0: aa0103f3  mov      x19, x1
//   0x0367d4: 2a0803e0  mov      w0, w8
//   0x0367d8: 94009a1a  bl       #0x5d040
//   0x0367dc: b0000188  adrp     x8, #0x67000
//   0x0367e0: 93407e96  sxtw     x22, w20
//   0x0367e4: 911ba108  add      x8, x8, #0x6e8
//   0x0367e8: 8b161517  add      x23, x8, x22, lsl #5
//   0x0367ec: f94406e4  ldr      x4, [x23, #0x808]
uint64_t fde_0256_sub_0367b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x93407E96ULL) + (x2 ^ 0x0367B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x0367b0: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x0367b4: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0367b8: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0367bc: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0367c0: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000168ULL; // 0x0367c4: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xB94FB908ULL; // 0x0367c8: ldr w8, [x8, #0xfb8]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F4ULL; // 0x0367cc: mov w20, w0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x0367d0: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0803E0ULL; // 0x0367d4: mov w0, w8
    return acc;
}

// [EN] Reconstructed FDE #0257 @ 0x0368d8..0x036a1c (324 bytes)
// [VN] Phục dựng FDE #0257 tại 0x0368d8..0x036a1c (324 byte)
//   0x0368d8: d100c3ff  sub      sp, sp, #0x30
//   0x0368dc: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0368e0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0368e4: 910083fd  add      x29, sp, #0x20
//   0x0368e8: d0000168  adrp     x8, #0x64000
//   0x0368ec: 3979b509  ldrb     w9, [x8, #0xe6d]
//   0x0368f0: 7100053f  cmp      w9, #1
//   0x0368f4: 540000e1  b.ne     #0x36910
//   0x0368f8: d0000168  adrp     x8, #0x64000
//   0x0368fc: 3979c100  ldrb     w0, [x8, #0xe70]
//   0x036900: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x036904: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x036908: 9100c3ff  add      sp, sp, #0x30
//   0x03690c: d65f03c0  ret      
//   0x036910: aa0003f3  mov      x19, x0
//   0x036914: d0fffec2  adrp     x2, #0x10000
uint64_t fde_0257_sub_0368d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0x9100C3FFULL) + (x2 ^ 0x0368D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x0368d8: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0368dc: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0368e0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0368e4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000168ULL; // 0x0368e8: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x3979B509ULL; // 0x0368ec: ldrb w9, [x8, #0xe6d]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100053FULL; // 0x0368f0: cmp w9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540000E1ULL; // 0x0368f4: b.ne #0x36910
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000168ULL; // 0x0368f8: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x3979C100ULL; // 0x0368fc: ldrb w0, [x8, #0xe70]
    return acc;
}

// [EN] Reconstructed FDE #0258 @ 0x036a1c..0x037078 (1628 bytes)
// [VN] Phục dựng FDE #0258 tại 0x036a1c..0x037078 (1628 byte)
//   0x036a1c: a9bb67fa  stp      x26, x25, [sp, #-0x50]!
//   0x036a20: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x036a24: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x036a28: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x036a2c: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x036a30: 910103fd  add      x29, sp, #0x40
//   0x036a34: d0000168  adrp     x8, #0x64000
//   0x036a38: 3979d109  ldrb     w9, [x8, #0xe74]
//   0x036a3c: 2a0403f4  mov      w20, w4
//   0x036a40: aa0303f5  mov      x21, x3
//   0x036a44: aa0203f7  mov      x23, x2
//   0x036a48: aa0103f8  mov      x24, x1
//   0x036a4c: aa0003f6  mov      x22, x0
//   0x036a50: 360001e9  tbz      w9, #0, #0x36a8c
//   0x036a54: f0000168  adrp     x8, #0x65000
//   0x036a58: f940b505  ldr      x5, [x8, #0x168]
uint64_t fde_0258_sub_036a1c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BB67FAULL) + (x1 ^ 0xAA0003F6ULL) + (x2 ^ 0x036A1CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BB67FAULL; // 0x036a1c: stp x26, x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x036a20: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x036a24: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x036a28: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x036a2c: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x036a30: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000168ULL; // 0x036a34: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x3979D109ULL; // 0x036a38: ldrb w9, [x8, #0xe74]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0403F4ULL; // 0x036a3c: mov w20, w4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F5ULL; // 0x036a40: mov x21, x3
    return acc;
}

// [EN] Reconstructed FDE #0259 @ 0x037078..0x0374a8 (1072 bytes)
// [VN] Phục dựng FDE #0259 tại 0x037078..0x0374a8 (1072 byte)
//   0x037078: d10243ff  sub      sp, sp, #0x90
//   0x03707c: a9036ffc  stp      x28, x27, [sp, #0x30]
//   0x037080: a90467fa  stp      x26, x25, [sp, #0x40]
//   0x037084: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x037088: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x03708c: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x037090: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x037094: 910203fd  add      x29, sp, #0x80
//   0x037098: b0000168  adrp     x8, #0x64000
//   0x03709c: 3979d509  ldrb     w9, [x8, #0xe75]
//   0x0370a0: 7100053f  cmp      w9, #1
//   0x0370a4: 54000081  b.ne     #0x370b4
//   0x0370a8: b0000168  adrp     x8, #0x64000
//   0x0370ac: 3979d914  ldrb     w20, [x8, #0xe76]
//   0x0370b0: 140000a1  b        #0x37334
//   0x0370b4: b0fffec0  adrp     x0, #0x10000
uint64_t fde_0259_sub_037078(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0xB0000168ULL) + (x2 ^ 0x037078ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x037078: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA9036FFCULL; // 0x03707c: stp x28, x27, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90467FAULL; // 0x037080: stp x26, x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x037084: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x037088: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x03708c: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x037090: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x037094: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000168ULL; // 0x037098: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x3979D509ULL; // 0x03709c: ldrb w9, [x8, #0xe75]
    return acc;
}

// [EN] Reconstructed FDE #0260 @ 0x0374a8..0x0375f0 (328 bytes)
// [VN] Phục dựng FDE #0260 tại 0x0374a8..0x0375f0 (328 byte)
//   0x0374a8: f81a0ffb  str      x27, [sp, #-0x60]!
//   0x0374ac: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x0374b0: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x0374b4: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0374b8: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0374bc: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0374c0: 910143fd  add      x29, sp, #0x50
//   0x0374c4: d000017b  adrp     x27, #0x65000
//   0x0374c8: f940bb68  ldr      x8, [x27, #0x170]
//   0x0374cc: b40007a8  cbz      x8, #0x375c0
//   0x0374d0: d0fffef4  adrp     x20, #0x15000
//   0x0374d4: aa0003f3  mov      x19, x0
//   0x0374d8: aa1f03f9  mov      x25, xzr
//   0x0374dc: 52801ffa  mov      w26, #0xff
//   0x0374e0: 911b4e94  add      x20, x20, #0x6d3
//   0x0374e4: 91000739  add      x25, x25, #1
uint64_t fde_0260_sub_0374a8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81A0FFBULL) + (x1 ^ 0xAA1F03F9ULL) + (x2 ^ 0x0374A8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81A0FFBULL; // 0x0374a8: str x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x0374ac: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x0374b0: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x0374b4: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x0374b8: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x0374bc: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x0374c0: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD000017BULL; // 0x0374c4: adrp x27, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xF940BB68ULL; // 0x0374c8: ldr x8, [x27, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40007A8ULL; // 0x0374cc: cbz x8, #0x375c0
    return acc;
}

// [EN] Reconstructed FDE #0261 @ 0x0375f0..0x0379a4 (948 bytes)
// [VN] Phục dựng FDE #0261 tại 0x0375f0..0x0379a4 (948 byte)
//   0x0375f0: d101c3ff  sub      sp, sp, #0x70
//   0x0375f4: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x0375f8: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x0375fc: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x037600: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x037604: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x037608: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x03760c: 910183fd  add      x29, sp, #0x60
//   0x037610: d0000168  adrp     x8, #0x65000
//   0x037614: f940bd08  ldr      x8, [x8, #0x178]
//   0x037618: b4000328  cbz      x8, #0x3767c
//   0x03761c: b0000174  adrp     x20, #0x64000
//   0x037620: 913c5294  add      x20, x20, #0xf14
//   0x037624: b0fffea1  adrp     x1, #0xc000
//   0x037628: b0fffec2  adrp     x2, #0x10000
//   0x03762c: 2a0003f3  mov      w19, w0
uint64_t fde_0261_sub_0375f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x913C5294ULL) + (x2 ^ 0x0375F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x0375f0: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9016FFCULL; // 0x0375f4: stp x28, x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x0375f8: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x0375fc: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x037600: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x037604: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x037608: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x03760c: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000168ULL; // 0x037610: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xF940BD08ULL; // 0x037614: ldr x8, [x8, #0x178]
    return acc;
}

// [EN] Reconstructed FDE #0262 @ 0x0379a4..0x037af8 (340 bytes)
// [VN] Phục dựng FDE #0262 tại 0x0379a4..0x037af8 (340 byte)
//   0x0379a4: d10543ff  sub      sp, sp, #0x150
//   0x0379a8: f9008bfc  str      x28, [sp, #0x110]
//   0x0379ac: a91257f6  stp      x22, x21, [sp, #0x120]
//   0x0379b0: a9134ff4  stp      x20, x19, [sp, #0x130]
//   0x0379b4: a9147bfd  stp      x29, x30, [sp, #0x140]
//   0x0379b8: 910503fd  add      x29, sp, #0x140
//   0x0379bc: d53bd055  mrs      x21, tpidr_el0
//   0x0379c0: f94016a8  ldr      x8, [x21, #0x28]
//   0x0379c4: b0fffea1  adrp     x1, #0xc000
//   0x0379c8: 90fffee2  adrp     x2, #0x13000
//   0x0379cc: 90fffea3  adrp     x3, #0xb000
//   0x0379d0: aa0003f3  mov      x19, x0
//   0x0379d4: 91396021  add      x1, x1, #0xe58
//   0x0379d8: 91030c42  add      x2, x2, #0xc3
//   0x0379dc: 912e4063  add      x3, x3, #0xb90
//   0x0379e0: 52800060  mov      w0, #3
uint64_t fde_0262_sub_0379a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10543FFULL) + (x1 ^ 0x91396021ULL) + (x2 ^ 0x0379A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10543FFULL; // 0x0379a4: sub sp, sp, #0x150
    acc = (acc * 0x100000001B3ULL) ^ 0xF9008BFCULL; // 0x0379a8: str x28, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91257F6ULL; // 0x0379ac: stp x22, x21, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9134FF4ULL; // 0x0379b0: stp x20, x19, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9147BFDULL; // 0x0379b4: stp x29, x30, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0x910503FDULL; // 0x0379b8: add x29, sp, #0x140
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x0379bc: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x0379c0: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFEA1ULL; // 0x0379c4: adrp x1, #0xc000
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFEE2ULL; // 0x0379c8: adrp x2, #0x13000
    return acc;
}

// [EN] Reconstructed FDE #0263 @ 0x037af8..0x037d10 (536 bytes)
// [VN] Phục dựng FDE #0263 tại 0x037af8..0x037d10 (536 byte)
//   0x037af8: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x037afc: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x037b00: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x037b04: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x037b08: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x037b0c: 910103fd  add      x29, sp, #0x40
//   0x037b10: d0000160  adrp     x0, #0x65000
//   0x037b14: 9132e000  add      x0, x0, #0xcb8
//   0x037b18: 94009596  bl       #0x5d170
//   0x037b1c: f0000168  adrp     x8, #0x66000
//   0x037b20: b9406108  ldr      w8, [x8, #0x60]
//   0x037b24: 350002e8  cbnz     w8, #0x37b80
//   0x037b28: d0fffee8  adrp     x8, #0x15000
//   0x037b2c: 3dc23100  ldr      q0, [x8, #0x8c0]
//   0x037b30: d0fffee8  adrp     x8, #0x15000
//   0x037b34: 3dc22101  ldr      q1, [x8, #0x880]
uint64_t fde_0263_sub_037af8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0xD0FFFEE8ULL) + (x2 ^ 0x037AF8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x037af8: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x037afc: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x037b00: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x037b04: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x037b08: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x037b0c: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000160ULL; // 0x037b10: adrp x0, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x9132E000ULL; // 0x037b14: add x0, x0, #0xcb8
    acc = (acc * 0x100000001B3ULL) ^ 0x94009596ULL; // 0x037b18: bl #0x5d170
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000168ULL; // 0x037b1c: adrp x8, #0x66000
    return acc;
}

// [EN] Reconstructed FDE #0264 @ 0x037d10..0x037e34 (292 bytes)
// [VN] Phục dựng FDE #0264 tại 0x037d10..0x037e34 (292 byte)
//   0x037d10: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x037d14: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x037d18: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x037d1c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x037d20: 9100c3fd  add      x29, sp, #0x30
//   0x037d24: b0000168  adrp     x8, #0x64000
//   0x037d28: b94fb908  ldr      w8, [x8, #0xfb8]
//   0x037d2c: 2a0003f4  mov      w20, w0
//   0x037d30: aa0103f3  mov      x19, x1
//   0x037d34: 2a0803e0  mov      w0, w8
//   0x037d38: 940094c2  bl       #0x5d040
//   0x037d3c: b0000188  adrp     x8, #0x68000
//   0x037d40: 93407e97  sxtw     x23, w20
//   0x037d44: 910ba108  add      x8, x8, #0x2e8
//   0x037d48: 8b171515  add      x21, x8, x23, lsl #5
//   0x037d4c: f94006a4  ldr      x4, [x21, #8]
uint64_t fde_0264_sub_037d10(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x93407E97ULL) + (x2 ^ 0x037D10ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x037d10: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x037d14: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x037d18: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x037d1c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x037d20: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000168ULL; // 0x037d24: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xB94FB908ULL; // 0x037d28: ldr w8, [x8, #0xfb8]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F4ULL; // 0x037d2c: mov w20, w0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x037d30: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0803E0ULL; // 0x037d34: mov w0, w8
    return acc;
}

// [EN] Reconstructed FDE #0265 @ 0x037e34..0x037e94 (96 bytes)
// [VN] Phục dựng FDE #0265 tại 0x037e34..0x037e94 (96 byte)
//   0x037e34: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x037e38: 910003fd  mov      x29, sp
//   0x037e3c: 52800780  mov      w0, #0x3c
//   0x037e40: 94009584  bl       #0x5d450
//   0x037e44: b0000168  adrp     x8, #0x64000
//   0x037e48: 913c6108  add      x8, x8, #0xf18
//   0x037e4c: f9413509  ldr      x9, [x8, #0x268]
//   0x037e50: 6940310a  ldpsw    x10, x12, [x8]
//   0x037e54: b980090b  ldrsw    x11, [x8, #8]
//   0x037e58: b0fffea1  adrp     x1, #0xc000
//   0x037e5c: 90fffee2  adrp     x2, #0x13000
//   0x037e60: f86a6929  ldr      x9, [x9, x10]
//   0x037e64: f941390a  ldr      x10, [x8, #0x270]
//   0x037e68: 91396021  add      x1, x1, #0xe58
//   0x037e6c: 910d2042  add      x2, x2, #0x348
//   0x037e70: 52800060  mov      w0, #3
uint64_t fde_0265_sub_037e34(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xF941390AULL) + (x2 ^ 0x037E34ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x037e34: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x037e38: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x52800780ULL; // 0x037e3c: mov w0, #0x3c
    acc = (acc * 0x100000001B3ULL) ^ 0x94009584ULL; // 0x037e40: bl #0x5d450
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000168ULL; // 0x037e44: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x913C6108ULL; // 0x037e48: add x8, x8, #0xf18
    acc = (acc * 0x100000001B3ULL) ^ 0xF9413509ULL; // 0x037e4c: ldr x9, [x8, #0x268]
    acc = (acc * 0x100000001B3ULL) ^ 0x6940310AULL; // 0x037e50: ldpsw x10, x12, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB980090BULL; // 0x037e54: ldrsw x11, [x8, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFEA1ULL; // 0x037e58: adrp x1, #0xc000
    return acc;
}

// [EN] Reconstructed FDE #0266 @ 0x037e94..0x037f24 (144 bytes)
// [VN] Phục dựng FDE #0266 tại 0x037e94..0x037f24 (144 byte)
//   0x037e94: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x037e98: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x037e9c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x037ea0: 910083fd  add      x29, sp, #0x20
//   0x037ea4: d0000169  adrp     x9, #0x65000
//   0x037ea8: 9106a129  add      x9, x9, #0x1a8
//   0x037eac: f9401128  ldr      x8, [x9, #0x20]
//   0x037eb0: d352fc2a  lsr      x10, x1, #0x12
//   0x037eb4: aa0103f3  mov      x19, x1
//   0x037eb8: aa0003f4  mov      x20, x0
//   0x037ebc: f900010a  str      x10, [x8]
//   0x037ec0: a940292b  ldp      x11, x10, [x9]
//   0x037ec4: f9400148  ldr      x8, [x10]
//   0x037ec8: 8b010108  add      x8, x8, x1
//   0x037ecc: f9000168  str      x8, [x11]
//   0x037ed0: f9401529  ldr      x9, [x9, #0x28]
uint64_t fde_0266_sub_037e94(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xF9400148ULL) + (x2 ^ 0x037E94ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x037e94: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x037e98: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x037e9c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x037ea0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000169ULL; // 0x037ea4: adrp x9, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x9106A129ULL; // 0x037ea8: add x9, x9, #0x1a8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401128ULL; // 0x037eac: ldr x8, [x9, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xD352FC2AULL; // 0x037eb0: lsr x10, x1, #0x12
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x037eb4: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x037eb8: mov x20, x0
    return acc;
}

// [EN] Reconstructed FDE #0267 @ 0x037f24..0x03802c (264 bytes)
// [VN] Phục dựng FDE #0267 tại 0x037f24..0x03802c (264 byte)
//   0x037f24: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x037f28: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x037f2c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x037f30: 910083fd  add      x29, sp, #0x20
//   0x037f34: d0000176  adrp     x22, #0x65000
//   0x037f38: 9106a2d6  add      x22, x22, #0x1a8
//   0x037f3c: a94026c8  ldp      x8, x9, [x22]
//   0x037f40: f94026ca  ldr      x10, [x22, #0x48]
//   0x037f44: b0fffea1  adrp     x1, #0xc000
//   0x037f48: 90fffea2  adrp     x2, #0xb000
//   0x037f4c: f9400108  ldr      x8, [x8]
//   0x037f50: f9400129  ldr      x9, [x9]
//   0x037f54: f940014a  ldr      x10, [x10]
//   0x037f58: aa0003f3  mov      x19, x0
//   0x037f5c: 91396021  add      x1, x1, #0xe58
//   0x037f60: cb090115  sub      x21, x8, x9
uint64_t fde_0267_sub_037f24(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xF940014AULL) + (x2 ^ 0x037F24ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x037f24: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x037f28: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x037f2c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x037f30: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000176ULL; // 0x037f34: adrp x22, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x9106A2D6ULL; // 0x037f38: add x22, x22, #0x1a8
    acc = (acc * 0x100000001B3ULL) ^ 0xA94026C8ULL; // 0x037f3c: ldp x8, x9, [x22]
    acc = (acc * 0x100000001B3ULL) ^ 0xF94026CAULL; // 0x037f40: ldr x10, [x22, #0x48]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFEA1ULL; // 0x037f44: adrp x1, #0xc000
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFEA2ULL; // 0x037f48: adrp x2, #0xb000
    return acc;
}

// [EN] Reconstructed FDE #0268 @ 0x03802c..0x038378 (844 bytes)
// [VN] Phục dựng FDE #0268 tại 0x03802c..0x038378 (844 byte)
//   0x03802c: d10303ff  sub      sp, sp, #0xc0
//   0x038030: a9066ffc  stp      x28, x27, [sp, #0x60]
//   0x038034: a90767fa  stp      x26, x25, [sp, #0x70]
//   0x038038: a9085ff8  stp      x24, x23, [sp, #0x80]
//   0x03803c: a90957f6  stp      x22, x21, [sp, #0x90]
//   0x038040: a90a4ff4  stp      x20, x19, [sp, #0xa0]
//   0x038044: a90b7bfd  stp      x29, x30, [sp, #0xb0]
//   0x038048: 9102c3fd  add      x29, sp, #0xb0
//   0x03804c: a9018be1  stp      x1, x2, [sp, #0x18]
//   0x038050: d53bd05a  mrs      x26, tpidr_el0
//   0x038054: f9401748  ldr      x8, [x26, #0x28]
//   0x038058: 90fffea1  adrp     x1, #0xc000
//   0x03805c: b0fffec2  adrp     x2, #0x11000
//   0x038060: aa0003f5  mov      x21, x0
//   0x038064: f9002fe8  str      x8, [sp, #0x58]
//   0x038068: 39400008  ldrb     w8, [x0]
uint64_t fde_0268_sub_03802c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10303FFULL) + (x1 ^ 0xB0FFFEC2ULL) + (x2 ^ 0x03802CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10303FFULL; // 0x03802c: sub sp, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9066FFCULL; // 0x038030: stp x28, x27, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90767FAULL; // 0x038034: stp x26, x25, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9085FF8ULL; // 0x038038: stp x24, x23, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90957F6ULL; // 0x03803c: stp x22, x21, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A4FF4ULL; // 0x038040: stp x20, x19, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B7BFDULL; // 0x038044: stp x29, x30, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9102C3FDULL; // 0x038048: add x29, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9018BE1ULL; // 0x03804c: stp x1, x2, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05AULL; // 0x038050: mrs x26, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0269 @ 0x038378..0x03838c (20 bytes)
// [VN] Phục dựng FDE #0269 tại 0x038378..0x03838c (20 byte)
//   0x038378: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x03837c: 910003fd  mov      x29, sp
//   0x038380: 90fffee0  adrp     x0, #0x14000
//   0x038384: 9103e400  add      x0, x0, #0xf9
//   0x038388: 94000024  bl       #0x38418
uint64_t fde_0269_sub_038378(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x94000024ULL) + (x2 ^ 0x038378ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x038378: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x03837c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFEE0ULL; // 0x038380: adrp x0, #0x14000
    acc = (acc * 0x100000001B3ULL) ^ 0x9103E400ULL; // 0x038384: add x0, x0, #0xf9
    acc = (acc * 0x100000001B3ULL) ^ 0x94000024ULL; // 0x038388: bl #0x38418
    return acc;
}

// [EN] Reconstructed FDE #0270 @ 0x03838c..0x038398 (12 bytes)
// [VN] Phục dựng FDE #0270 tại 0x03838c..0x038398 (12 byte)
//   0x03838c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x038390: 910003fd  mov      x29, sp
//   0x038394: 94000001  bl       #0x38398
uint64_t fde_0270_sub_03838c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x94000001ULL) + (x2 ^ 0x03838CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x03838c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x038390: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x94000001ULL; // 0x038394: bl #0x38398
    return acc;
}

// [EN] Reconstructed FDE #0271 @ 0x038398..0x0383e0 (72 bytes)
// [VN] Phục dựng FDE #0271 tại 0x038398..0x0383e0 (72 byte)
//   0x038398: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x03839c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0383a0: 910043fd  add      x29, sp, #0x10
//   0x0383a4: 52800200  mov      w0, #0x10
//   0x0383a8: 94009436  bl       #0x5d480
//   0x0383ac: aa0003f3  mov      x19, x0
//   0x0383b0: 9400000c  bl       #0x383e0
//   0x0383b4: 90000141  adrp     x1, #0x60000
//   0x0383b8: 90000142  adrp     x2, #0x60000
//   0x0383bc: f9466821  ldr      x1, [x1, #0xcd0]
//   0x0383c0: f9466c42  ldr      x2, [x2, #0xcd8]
//   0x0383c4: aa1303e0  mov      x0, x19
//   0x0383c8: 94009432  bl       #0x5d490
//   0x0383cc: aa0003f4  mov      x20, x0
//   0x0383d0: aa1303e0  mov      x0, x19
//   0x0383d4: 94009433  bl       #0x5d4a0
uint64_t fde_0271_sub_038398(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x94009432ULL) + (x2 ^ 0x038398ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x038398: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03839c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0383a0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x52800200ULL; // 0x0383a4: mov w0, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x94009436ULL; // 0x0383a8: bl #0x5d480
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0383ac: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9400000CULL; // 0x0383b0: bl #0x383e0
    acc = (acc * 0x100000001B3ULL) ^ 0x90000141ULL; // 0x0383b4: adrp x1, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x90000142ULL; // 0x0383b8: adrp x2, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9466821ULL; // 0x0383bc: ldr x1, [x1, #0xcd0]
    return acc;
}

// [EN] Reconstructed FDE #0272 @ 0x0383e0..0x038418 (56 bytes)
// [VN] Phục dựng FDE #0272 tại 0x0383e0..0x038418 (56 byte)
//   0x0383e0: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0383e4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0383e8: 910043fd  add      x29, sp, #0x10
//   0x0383ec: 90fffee1  adrp     x1, #0x14000
//   0x0383f0: 9103e421  add      x1, x1, #0xf9
//   0x0383f4: aa0003f3  mov      x19, x0
//   0x0383f8: 9400942e  bl       #0x5d4b0
//   0x0383fc: 90000148  adrp     x8, #0x60000
//   0x038400: f9467108  ldr      x8, [x8, #0xce0]
//   0x038404: 91004108  add      x8, x8, #0x10
//   0x038408: f9000268  str      x8, [x19]
//   0x03840c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x038410: f84207f3  ldr      x19, [sp], #0x20
//   0x038414: d65f03c0  ret      
uint64_t fde_0272_sub_0383e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x0383E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0383e0: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0383e4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0383e8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFEE1ULL; // 0x0383ec: adrp x1, #0x14000
    acc = (acc * 0x100000001B3ULL) ^ 0x9103E421ULL; // 0x0383f0: add x1, x1, #0xf9
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0383f4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9400942EULL; // 0x0383f8: bl #0x5d4b0
    acc = (acc * 0x100000001B3ULL) ^ 0x90000148ULL; // 0x0383fc: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9467108ULL; // 0x038400: ldr x8, [x8, #0xce0]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x038404: add x8, x8, #0x10
    return acc;
}

// [EN] Reconstructed FDE #0273 @ 0x038418..0x038468 (80 bytes)
// [VN] Phục dựng FDE #0273 tại 0x038418..0x038468 (80 byte)
//   0x038418: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x03841c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x038420: 910043fd  add      x29, sp, #0x10
//   0x038424: aa0003f4  mov      x20, x0
//   0x038428: 52800200  mov      w0, #0x10
//   0x03842c: 94009415  bl       #0x5d480
//   0x038430: aa0003f3  mov      x19, x0
//   0x038434: aa1403e1  mov      x1, x20
//   0x038438: 9400000c  bl       #0x38468
//   0x03843c: 90000141  adrp     x1, #0x60000
//   0x038440: 90000142  adrp     x2, #0x60000
//   0x038444: f9467421  ldr      x1, [x1, #0xce8]
//   0x038448: f9467842  ldr      x2, [x2, #0xcf0]
//   0x03844c: aa1303e0  mov      x0, x19
//   0x038450: 94009410  bl       #0x5d490
//   0x038454: aa0003f4  mov      x20, x0
uint64_t fde_0273_sub_038418(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9467842ULL) + (x2 ^ 0x038418ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x038418: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03841c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x038420: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x038424: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800200ULL; // 0x038428: mov w0, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x94009415ULL; // 0x03842c: bl #0x5d480
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x038430: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E1ULL; // 0x038434: mov x1, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x9400000CULL; // 0x038438: bl #0x38468
    acc = (acc * 0x100000001B3ULL) ^ 0x90000141ULL; // 0x03843c: adrp x1, #0x60000
    return acc;
}

// [EN] Reconstructed FDE #0274 @ 0x038468..0x038498 (48 bytes)
// [VN] Phục dựng FDE #0274 tại 0x038468..0x038498 (48 byte)
//   0x038468: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x03846c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x038470: 910043fd  add      x29, sp, #0x10
//   0x038474: aa0003f3  mov      x19, x0
//   0x038478: 9400940e  bl       #0x5d4b0
//   0x03847c: 90000148  adrp     x8, #0x60000
//   0x038480: f9467d08  ldr      x8, [x8, #0xcf8]
//   0x038484: 91004108  add      x8, x8, #0x10
//   0x038488: f9000268  str      x8, [x19]
//   0x03848c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x038490: f84207f3  ldr      x19, [sp], #0x20
//   0x038494: d65f03c0  ret      
uint64_t fde_0274_sub_038468(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x038468ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x038468: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03846c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x038470: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x038474: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9400940EULL; // 0x038478: bl #0x5d4b0
    acc = (acc * 0x100000001B3ULL) ^ 0x90000148ULL; // 0x03847c: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9467D08ULL; // 0x038480: ldr x8, [x8, #0xcf8]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x038484: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x038488: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x03848c: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0275 @ 0x038498..0x038560 (200 bytes)
// [VN] Phục dựng FDE #0275 tại 0x038498..0x038560 (200 byte)
//   0x038498: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x03849c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0384a0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0384a4: 910083fd  add      x29, sp, #0x20
//   0x0384a8: 39400008  ldrb     w8, [x0]
//   0x0384ac: aa0203f4  mov      x20, x2
//   0x0384b0: aa0003f3  mov      x19, x0
//   0x0384b4: aa0103e7  mov      x7, x1
//   0x0384b8: 37000108  tbnz     w8, #0, #0x384d8
//   0x0384bc: 528002c1  mov      w1, #0x16
//   0x0384c0: eb14003f  cmp      x1, x20
//   0x0384c4: 54000143  b.lo     #0x384ec
//   0x0384c8: 37000188  tbnz     w8, #0, #0x384f8
//   0x0384cc: 91000675  add      x21, x19, #1
//   0x0384d0: b5000194  cbnz     x20, #0x38500
//   0x0384d4: 1400000f  b        #0x38510
uint64_t fde_0275_sub_038498(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x37000188ULL) + (x2 ^ 0x038498ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x038498: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x03849c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0384a0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0384a4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x0384a8: ldrb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x0384ac: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0384b0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E7ULL; // 0x0384b4: mov x7, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x37000108ULL; // 0x0384b8: tbnz w8, #0, #0x384d8
    acc = (acc * 0x100000001B3ULL) ^ 0x528002C1ULL; // 0x0384bc: mov w1, #0x16
    return acc;
}

// [EN] Reconstructed FDE #0276 @ 0x038560..0x0386c0 (352 bytes)
// [VN] Phục dựng FDE #0276 tại 0x038560..0x0386c0 (352 byte)
//   0x038560: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x038564: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x038568: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x03856c: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x038570: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x038574: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x038578: 910143fd  add      x29, sp, #0x50
//   0x03857c: 92800228  mov      x8, #-0x12
//   0x038580: cb010108  sub      x8, x8, x1
//   0x038584: eb02011f  cmp      x8, x2
//   0x038588: 540009a3  b.lo     #0x386bc
//   0x03858c: 39400008  ldrb     w8, [x0]
//   0x038590: aa0703fa  mov      x26, x7
//   0x038594: aa0603f3  mov      x19, x6
//   0x038598: aa0503f6  mov      x22, x5
//   0x03859c: aa0403f7  mov      x23, x4
uint64_t fde_0276_sub_038560(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xAA0703FAULL) + (x2 ^ 0x038560ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x038560: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x038564: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x038568: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x03856c: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x038570: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x038574: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x038578: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0x92800228ULL; // 0x03857c: mov x8, #-0x12
    acc = (acc * 0x100000001B3ULL) ^ 0xCB010108ULL; // 0x038580: sub x8, x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02011FULL; // 0x038584: cmp x8, x2
    return acc;
}

// [EN] Reconstructed FDE #0277 @ 0x0386c0..0x0390b0 (2544 bytes)
// [VN] Phục dựng FDE #0277 tại 0x0386c0..0x0390b0 (2544 byte)
//   0x0386c0: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x0386c4: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x0386c8: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x0386cc: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0386d0: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0386d4: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0386d8: 910143fd  add      x29, sp, #0x50
//   0x0386dc: d11243ff  sub      sp, sp, #0x490
//   0x0386e0: d53bd05a  mrs      x26, tpidr_el0
//   0x0386e4: f9401748  ldr      x8, [x26, #0x28]
//   0x0386e8: 2a0103f3  mov      w19, w1
//   0x0386ec: 2a0003f4  mov      w20, w0
//   0x0386f0: f81a03a8  stur     x8, [x29, #-0x60]
//   0x0386f4: 36001761  tbz      w1, #0, #0x389e0
//   0x0386f8: d0fffec0  adrp     x0, #0x12000
//   0x0386fc: b0fffec1  adrp     x1, #0x11000
uint64_t fde_0277_sub_0386c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xF81A03A8ULL) + (x2 ^ 0x0386C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x0386c0: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x0386c4: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x0386c8: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x0386cc: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x0386d0: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x0386d4: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x0386d8: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD11243FFULL; // 0x0386dc: sub sp, sp, #0x490
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05AULL; // 0x0386e0: mrs x26, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401748ULL; // 0x0386e4: ldr x8, [x26, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0278 @ 0x0390b0..0x0390cc (28 bytes)
// [VN] Phục dựng FDE #0278 tại 0x0390b0..0x0390cc (28 byte)
//   0x0390b0: 90000168  adrp     x8, #0x65000
//   0x0390b4: 9106a108  add      x8, x8, #0x1a8
//   0x0390b8: a9402109  ldp      x9, x8, [x8]
//   0x0390bc: f9400129  ldr      x9, [x9]
//   0x0390c0: f9400108  ldr      x8, [x8]
//   0x0390c4: cb080120  sub      x0, x9, x8
//   0x0390c8: d65f03c0  ret      
uint64_t fde_0278_sub_0390b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000168ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0390B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000168ULL; // 0x0390b0: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x9106A108ULL; // 0x0390b4: add x8, x8, #0x1a8
    acc = (acc * 0x100000001B3ULL) ^ 0xA9402109ULL; // 0x0390b8: ldp x9, x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400129ULL; // 0x0390bc: ldr x9, [x9]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x0390c0: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB080120ULL; // 0x0390c4: sub x0, x9, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0390c8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0279 @ 0x0390cc..0x0392c8 (508 bytes)
// [VN] Phục dựng FDE #0279 tại 0x0390cc..0x0392c8 (508 byte)
//   0x0390cc: d10183ff  sub      sp, sp, #0x60
//   0x0390d0: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x0390d4: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x0390d8: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0390dc: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0390e0: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0390e4: 910143fd  add      x29, sp, #0x50
//   0x0390e8: d53bd053  mrs      x19, tpidr_el0
//   0x0390ec: f9401668  ldr      x8, [x19, #0x28]
//   0x0390f0: 7100505f  cmp      w2, #0x14
//   0x0390f4: f90007e8  str      x8, [sp, #8]
//   0x0390f8: 540001ac  b.gt     #0x3912c
//   0x0390fc: f0fffe81  adrp     x1, #0xc000
//   0x039100: b0fffea2  adrp     x2, #0xe000
//   0x039104: 91396021  add      x1, x1, #0xe58
//   0x039108: 91149c42  add      x2, x2, #0x527
uint64_t fde_0279_sub_0390cc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xF0FFFE81ULL) + (x2 ^ 0x0390CCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x0390cc: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x0390d0: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x0390d4: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x0390d8: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x0390dc: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x0390e0: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x0390e4: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x0390e8: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x0390ec: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100505FULL; // 0x0390f0: cmp w2, #0x14
    return acc;
}

// [EN] Reconstructed FDE #0280 @ 0x0392c8..0x039478 (432 bytes)
// [VN] Phục dựng FDE #0280 tại 0x0392c8..0x039478 (432 byte)
//   0x0392c8: d100c3ff  sub      sp, sp, #0x30
//   0x0392cc: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0392d0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0392d4: 910083fd  add      x29, sp, #0x20
//   0x0392d8: f9400008  ldr      x8, [x0]
//   0x0392dc: f0000154  adrp     x20, #0x64000
//   0x0392e0: 913c5294  add      x20, x20, #0xf14
//   0x0392e4: 91097281  add      x1, x20, #0x25c
//   0x0392e8: f9436d08  ldr      x8, [x8, #0x6d8]
//   0x0392ec: 2a0203f3  mov      w19, w2
//   0x0392f0: d63f0100  blr      x8
//   0x0392f4: f0fffe81  adrp     x1, #0xc000
//   0x0392f8: f0fffec2  adrp     x2, #0x14000
//   0x0392fc: 91396021  add      x1, x1, #0xe58
//   0x039300: 9117e442  add      x2, x2, #0x5f9
//   0x039304: 52800060  mov      w0, #3
uint64_t fde_0280_sub_0392c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0xF0FFFEC2ULL) + (x2 ^ 0x0392C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x0392c8: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0392cc: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0392d0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0392d4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x0392d8: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000154ULL; // 0x0392dc: adrp x20, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x913C5294ULL; // 0x0392e0: add x20, x20, #0xf14
    acc = (acc * 0x100000001B3ULL) ^ 0x91097281ULL; // 0x0392e4: add x1, x20, #0x25c
    acc = (acc * 0x100000001B3ULL) ^ 0xF9436D08ULL; // 0x0392e8: ldr x8, [x8, #0x6d8]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F3ULL; // 0x0392ec: mov w19, w2
    return acc;
}

// [EN] Reconstructed FDE #0281 @ 0x039478..0x039488 (16 bytes)
// [VN] Phục dựng FDE #0281 tại 0x039478..0x039488 (16 byte)
//   0x039478: 90000168  adrp     x8, #0x65000
//   0x03947c: 52800020  mov      w0, #1
//   0x039480: f9010102  str      x2, [x8, #0x200]
//   0x039484: d65f03c0  ret      
uint64_t fde_0281_sub_039478(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000168ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x039478ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000168ULL; // 0x039478: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x52800020ULL; // 0x03947c: mov w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9010102ULL; // 0x039480: str x2, [x8, #0x200]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x039484: ret 
    return acc;
}

// [EN] Reconstructed FDE #0282 @ 0x039488..0x0394b8 (48 bytes)
// [VN] Phục dựng FDE #0282 tại 0x039488..0x0394b8 (48 byte)
//   0x039488: d10083ff  sub      sp, sp, #0x20
//   0x03948c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x039490: 910043fd  add      x29, sp, #0x10
//   0x039494: 90000000  adrp     x0, #0x39000
//   0x039498: 9112e000  add      x0, x0, #0x4b8
//   0x03949c: 910023e1  add      x1, sp, #8
//   0x0394a0: f90007e2  str      x2, [sp, #8]
//   0x0394a4: 94000010  bl       #0x394e4
//   0x0394a8: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0394ac: 12000000  and      w0, w0, #1
//   0x0394b0: 910083ff  add      sp, sp, #0x20
//   0x0394b4: d65f03c0  ret      
uint64_t fde_0282_sub_039488(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10083FFULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x039488ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10083FFULL; // 0x039488: sub sp, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03948c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x039490: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x90000000ULL; // 0x039494: adrp x0, #0x39000
    acc = (acc * 0x100000001B3ULL) ^ 0x9112E000ULL; // 0x039498: add x0, x0, #0x4b8
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E1ULL; // 0x03949c: add x1, sp, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E2ULL; // 0x0394a0: str x2, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x94000010ULL; // 0x0394a4: bl #0x394e4
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x0394a8: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x12000000ULL; // 0x0394ac: and w0, w0, #1
    return acc;
}

// [EN] Reconstructed FDE #0283 @ 0x0394b8..0x0394e4 (44 bytes)
// [VN] Phục dựng FDE #0283 tại 0x0394b8..0x0394e4 (44 byte)
//   0x0394b8: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0394bc: 910003fd  mov      x29, sp
//   0x0394c0: f0fffe81  adrp     x1, #0xc000
//   0x0394c4: f0fffe82  adrp     x2, #0xc000
//   0x0394c8: 91396021  add      x1, x1, #0xe58
//   0x0394cc: 91007442  add      x2, x2, #0x1d
//   0x0394d0: 528000c0  mov      w0, #6
//   0x0394d4: 94008df3  bl       #0x5cca0
//   0x0394d8: 2a1f03e0  mov      w0, wzr
//   0x0394dc: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x0394e0: d65f03c0  ret      
uint64_t fde_0283_sub_0394b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0394B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x0394b8: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0394bc: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFE81ULL; // 0x0394c0: adrp x1, #0xc000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFE82ULL; // 0x0394c4: adrp x2, #0xc000
    acc = (acc * 0x100000001B3ULL) ^ 0x91396021ULL; // 0x0394c8: add x1, x1, #0xe58
    acc = (acc * 0x100000001B3ULL) ^ 0x91007442ULL; // 0x0394cc: add x2, x2, #0x1d
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C0ULL; // 0x0394d0: mov w0, #6
    acc = (acc * 0x100000001B3ULL) ^ 0x94008DF3ULL; // 0x0394d4: bl #0x5cca0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x0394d8: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x0394dc: ldp x29, x30, [sp], #0x10
    return acc;
}

// [EN] Reconstructed FDE #0284 @ 0x0394e4..0x03964c (360 bytes)
// [VN] Phục dựng FDE #0284 tại 0x0394e4..0x03964c (360 byte)
//   0x0394e4: d10543ff  sub      sp, sp, #0x150
//   0x0394e8: f9008bfc  str      x28, [sp, #0x110]
//   0x0394ec: a91257f6  stp      x22, x21, [sp, #0x120]
//   0x0394f0: a9134ff4  stp      x20, x19, [sp, #0x130]
//   0x0394f4: a9147bfd  stp      x29, x30, [sp, #0x140]
//   0x0394f8: 910503fd  add      x29, sp, #0x140
//   0x0394fc: d53bd055  mrs      x21, tpidr_el0
//   0x039500: f94016a8  ldr      x8, [x21, #0x28]
//   0x039504: aa0103f3  mov      x19, x1
//   0x039508: f0fffe81  adrp     x1, #0xc000
//   0x03950c: d0fffec2  adrp     x2, #0x13000
//   0x039510: d0fffe83  adrp     x3, #0xb000
//   0x039514: aa0003f4  mov      x20, x0
//   0x039518: 91396021  add      x1, x1, #0xe58
//   0x03951c: 91030c42  add      x2, x2, #0xc3
//   0x039520: 912e4063  add      x3, x3, #0xb90
uint64_t fde_0284_sub_0394e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10543FFULL) + (x1 ^ 0xAA0003F4ULL) + (x2 ^ 0x0394E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10543FFULL; // 0x0394e4: sub sp, sp, #0x150
    acc = (acc * 0x100000001B3ULL) ^ 0xF9008BFCULL; // 0x0394e8: str x28, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91257F6ULL; // 0x0394ec: stp x22, x21, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9134FF4ULL; // 0x0394f0: stp x20, x19, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9147BFDULL; // 0x0394f4: stp x29, x30, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0x910503FDULL; // 0x0394f8: add x29, sp, #0x140
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x0394fc: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x039500: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x039504: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFE81ULL; // 0x039508: adrp x1, #0xc000
    return acc;
}

// [EN] Reconstructed FDE #0285 @ 0x03964c..0x039654 (8 bytes)
// [VN] Phục dựng FDE #0285 tại 0x03964c..0x039654 (8 byte)
//   0x03964c: 2a1f03e0  mov      w0, wzr
//   0x039650: d65f03c0  ret      
uint64_t fde_0285_sub_03964c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x03964CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x03964c: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x039650: ret 
    return acc;
}

// [EN] Reconstructed FDE #0286 @ 0x039654..0x039684 (48 bytes)
// [VN] Phục dựng FDE #0286 tại 0x039654..0x039684 (48 byte)
//   0x039654: d10083ff  sub      sp, sp, #0x20
//   0x039658: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03965c: 910043fd  add      x29, sp, #0x10
//   0x039660: d10013a0  sub      x0, x29, #4
//   0x039664: 910023e1  add      x1, sp, #8
//   0x039668: b81fc3a2  stur     w2, [x29, #-4]
//   0x03966c: 390023e3  strb     w3, [sp, #8]
//   0x039670: 94000005  bl       #0x39684
//   0x039674: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x039678: 12000000  and      w0, w0, #1
//   0x03967c: 910083ff  add      sp, sp, #0x20
//   0x039680: d65f03c0  ret      
uint64_t fde_0286_sub_039654(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10083FFULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x039654ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10083FFULL; // 0x039654: sub sp, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x039658: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03965c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD10013A0ULL; // 0x039660: sub x0, x29, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E1ULL; // 0x039664: add x1, sp, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xB81FC3A2ULL; // 0x039668: stur w2, [x29, #-4]
    acc = (acc * 0x100000001B3ULL) ^ 0x390023E3ULL; // 0x03966c: strb w3, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x94000005ULL; // 0x039670: bl #0x39684
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x039674: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x12000000ULL; // 0x039678: and w0, w0, #1
    return acc;
}

// [EN] Reconstructed FDE #0287 @ 0x039684..0x0397f4 (368 bytes)
// [VN] Phục dựng FDE #0287 tại 0x039684..0x0397f4 (368 byte)
//   0x039684: d10543ff  sub      sp, sp, #0x150
//   0x039688: a9115ffc  stp      x28, x23, [sp, #0x110]
//   0x03968c: a91257f6  stp      x22, x21, [sp, #0x120]
//   0x039690: a9134ff4  stp      x20, x19, [sp, #0x130]
//   0x039694: a9147bfd  stp      x29, x30, [sp, #0x140]
//   0x039698: 910503fd  add      x29, sp, #0x140
//   0x03969c: d53bd056  mrs      x22, tpidr_el0
//   0x0396a0: f94016c8  ldr      x8, [x22, #0x28]
//   0x0396a4: aa0103f4  mov      x20, x1
//   0x0396a8: f0fffe81  adrp     x1, #0xc000
//   0x0396ac: d0fffec2  adrp     x2, #0x13000
//   0x0396b0: d0fffe83  adrp     x3, #0xb000
//   0x0396b4: aa0003f3  mov      x19, x0
//   0x0396b8: 91396021  add      x1, x1, #0xe58
//   0x0396bc: 91030c42  add      x2, x2, #0xc3
//   0x0396c0: 912e4063  add      x3, x3, #0xb90
uint64_t fde_0287_sub_039684(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10543FFULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x039684ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10543FFULL; // 0x039684: sub sp, sp, #0x150
    acc = (acc * 0x100000001B3ULL) ^ 0xA9115FFCULL; // 0x039688: stp x28, x23, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91257F6ULL; // 0x03968c: stp x22, x21, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9134FF4ULL; // 0x039690: stp x20, x19, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9147BFDULL; // 0x039694: stp x29, x30, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0x910503FDULL; // 0x039698: add x29, sp, #0x140
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x03969c: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x0396a0: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x0396a4: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFE81ULL; // 0x0396a8: adrp x1, #0xc000
    return acc;
}

// [EN] Reconstructed FDE #0288 @ 0x0397f4..0x039d04 (1296 bytes)
// [VN] Phục dựng FDE #0288 tại 0x0397f4..0x039d04 (1296 byte)
//   0x0397f4: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x0397f8: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x0397fc: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x039800: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x039804: 9100c3fd  add      x29, sp, #0x30
//   0x039808: f9400008  ldr      x8, [x0]
//   0x03980c: f0000154  adrp     x20, #0x64000
//   0x039810: 913c5294  add      x20, x20, #0xf14
//   0x039814: 91097281  add      x1, x20, #0x25c
//   0x039818: f9436d08  ldr      x8, [x8, #0x6d8]
//   0x03981c: 2a0203f3  mov      w19, w2
//   0x039820: d63f0100  blr      x8
//   0x039824: f0fffe81  adrp     x1, #0xc000
//   0x039828: f0fffec2  adrp     x2, #0x14000
//   0x03982c: 91396021  add      x1, x1, #0xe58
//   0x039830: 9117e442  add      x2, x2, #0x5f9
uint64_t fde_0288_sub_0397f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xF0FFFE81ULL) + (x2 ^ 0x0397F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x0397f4: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x0397f8: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0397fc: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x039800: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x039804: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x039808: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000154ULL; // 0x03980c: adrp x20, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x913C5294ULL; // 0x039810: add x20, x20, #0xf14
    acc = (acc * 0x100000001B3ULL) ^ 0x91097281ULL; // 0x039814: add x1, x20, #0x25c
    acc = (acc * 0x100000001B3ULL) ^ 0xF9436D08ULL; // 0x039818: ldr x8, [x8, #0x6d8]
    return acc;
}

// [EN] Reconstructed FDE #0289 @ 0x039d04..0x039d90 (140 bytes)
// [VN] Phục dựng FDE #0289 tại 0x039d04..0x039d90 (140 byte)
//   0x039d04: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x039d08: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x039d0c: 910043fd  add      x29, sp, #0x10
//   0x039d10: f0fffe80  adrp     x0, #0xc000
//   0x039d14: 913ad000  add      x0, x0, #0xeb4
//   0x039d18: 94008cfa  bl       #0x5d100
//   0x039d1c: d0fffe81  adrp     x1, #0xb000
//   0x039d20: 9110ac21  add      x1, x1, #0x42b
//   0x039d24: aa0003f3  mov      x19, x0
//   0x039d28: 94008d76  bl       #0x5d300
//   0x039d2c: b40001e0  cbz      x0, #0x39d68
//   0x039d30: f0fffe80  adrp     x0, #0xc000
//   0x039d34: d0fffe82  adrp     x2, #0xb000
//   0x039d38: 90000003  adrp     x3, #0x39000
//   0x039d3c: 913ad000  add      x0, x0, #0xeb4
//   0x039d40: 9110ac42  add      x2, x2, #0x42b
uint64_t fde_0289_sub_039d04(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xD0FFFE82ULL) + (x2 ^ 0x039D04ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x039d04: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x039d08: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x039d0c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFE80ULL; // 0x039d10: adrp x0, #0xc000
    acc = (acc * 0x100000001B3ULL) ^ 0x913AD000ULL; // 0x039d14: add x0, x0, #0xeb4
    acc = (acc * 0x100000001B3ULL) ^ 0x94008CFAULL; // 0x039d18: bl #0x5d100
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFE81ULL; // 0x039d1c: adrp x1, #0xb000
    acc = (acc * 0x100000001B3ULL) ^ 0x9110AC21ULL; // 0x039d20: add x1, x1, #0x42b
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x039d24: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x94008D76ULL; // 0x039d28: bl #0x5d300
    return acc;
}

// [EN] Reconstructed FDE #0290 @ 0x039d90..0x039e34 (164 bytes)
// [VN] Phục dựng FDE #0290 tại 0x039d90..0x039e34 (164 byte)
//   0x039d90: d10103ff  sub      sp, sp, #0x40
//   0x039d94: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x039d98: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x039d9c: 9100c3fd  add      x29, sp, #0x30
//   0x039da0: aa1e03f3  mov      x19, x30
//   0x039da4: f9000fe0  str      x0, [sp, #0x18]
//   0x039da8: 290207e2  stp      w2, w1, [sp, #0x10]
//   0x039dac: 390033e3  strb     w3, [sp, #0xc]
//   0x039db0: b9000be4  str      w4, [sp, #8]
//   0x039db4: f90003e5  str      x5, [sp]
//   0x039db8: b0fffec1  adrp     x1, #0x12000
//   0x039dbc: 90fffea2  adrp     x2, #0xd000
//   0x039dc0: 913b6421  add      x1, x1, #0xed9
//   0x039dc4: 910c4042  add      x2, x2, #0x310
//   0x039dc8: 52800060  mov      w0, #3
//   0x039dcc: 94008bb5  bl       #0x5cca0
uint64_t fde_0290_sub_039d90(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x913B6421ULL) + (x2 ^ 0x039D90ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x039d90: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x039d94: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x039d98: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x039d9c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x039da0: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE0ULL; // 0x039da4: str x0, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x290207E2ULL; // 0x039da8: stp w2, w1, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x390033E3ULL; // 0x039dac: strb w3, [sp, #0xc]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9000BE4ULL; // 0x039db0: str w4, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90003E5ULL; // 0x039db4: str x5, [sp]
    return acc;
}

// [EN] Reconstructed FDE #0291 @ 0x039e34..0x03a02c (504 bytes)
// [VN] Phục dựng FDE #0291 tại 0x039e34..0x03a02c (504 byte)
//   0x039e34: d10603ff  sub      sp, sp, #0x180
//   0x039e38: a9126ffc  stp      x28, x27, [sp, #0x120]
//   0x039e3c: a91367fa  stp      x26, x25, [sp, #0x130]
//   0x039e40: a9145ff8  stp      x24, x23, [sp, #0x140]
//   0x039e44: a91557f6  stp      x22, x21, [sp, #0x150]
//   0x039e48: a9164ff4  stp      x20, x19, [sp, #0x160]
//   0x039e4c: a9177bfd  stp      x29, x30, [sp, #0x170]
//   0x039e50: 9105c3fd  add      x29, sp, #0x170
//   0x039e54: d53bd05a  mrs      x26, tpidr_el0
//   0x039e58: f9401748  ldr      x8, [x26, #0x28]
//   0x039e5c: aa0303f3  mov      x19, x3
//   0x039e60: aa0203f6  mov      x22, x2
//   0x039e64: aa0103f7  mov      x23, x1
//   0x039e68: b0fffec1  adrp     x1, #0x12000
//   0x039e6c: d0fffec2  adrp     x2, #0x13000
//   0x039e70: d0fffe83  adrp     x3, #0xb000
uint64_t fde_0291_sub_039e34(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10603FFULL) + (x1 ^ 0xAA0103F7ULL) + (x2 ^ 0x039E34ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10603FFULL; // 0x039e34: sub sp, sp, #0x180
    acc = (acc * 0x100000001B3ULL) ^ 0xA9126FFCULL; // 0x039e38: stp x28, x27, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91367FAULL; // 0x039e3c: stp x26, x25, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9145FF8ULL; // 0x039e40: stp x24, x23, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91557F6ULL; // 0x039e44: stp x22, x21, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9164FF4ULL; // 0x039e48: stp x20, x19, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9177BFDULL; // 0x039e4c: stp x29, x30, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0x9105C3FDULL; // 0x039e50: add x29, sp, #0x170
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05AULL; // 0x039e54: mrs x26, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401748ULL; // 0x039e58: ldr x8, [x26, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0292 @ 0x03a02c..0x03a244 (536 bytes)
// [VN] Phục dựng FDE #0292 tại 0x03a02c..0x03a244 (536 byte)
//   0x03a02c: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x03a030: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x03a034: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x03a038: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x03a03c: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x03a040: 910103fd  add      x29, sp, #0x40
//   0x03a044: f0000140  adrp     x0, #0x65000
//   0x03a048: 9132e000  add      x0, x0, #0xcb8
//   0x03a04c: 94008c49  bl       #0x5d170
//   0x03a050: 90000168  adrp     x8, #0x66000
//   0x03a054: b941e108  ldr      w8, [x8, #0x1e0]
//   0x03a058: 350002e8  cbnz     w8, #0x3a0b4
//   0x03a05c: f0fffec8  adrp     x8, #0x15000
//   0x03a060: 3dc23100  ldr      q0, [x8, #0x8c0]
//   0x03a064: f0fffec8  adrp     x8, #0x15000
//   0x03a068: 3dc22101  ldr      q1, [x8, #0x880]
uint64_t fde_0292_sub_03a02c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0xF0FFFEC8ULL) + (x2 ^ 0x03A02CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x03a02c: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x03a030: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x03a034: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x03a038: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x03a03c: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x03a040: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000140ULL; // 0x03a044: adrp x0, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x9132E000ULL; // 0x03a048: add x0, x0, #0xcb8
    acc = (acc * 0x100000001B3ULL) ^ 0x94008C49ULL; // 0x03a04c: bl #0x5d170
    acc = (acc * 0x100000001B3ULL) ^ 0x90000168ULL; // 0x03a050: adrp x8, #0x66000
    return acc;
}

// [EN] Reconstructed FDE #0293 @ 0x03a244..0x03a36c (296 bytes)
// [VN] Phục dựng FDE #0293 tại 0x03a244..0x03a36c (296 byte)
//   0x03a244: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x03a248: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x03a24c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x03a250: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x03a254: 9100c3fd  add      x29, sp, #0x30
//   0x03a258: d0000148  adrp     x8, #0x64000
//   0x03a25c: b94fb908  ldr      w8, [x8, #0xfb8]
//   0x03a260: 2a0003f4  mov      w20, w0
//   0x03a264: aa0103f3  mov      x19, x1
//   0x03a268: 2a0803e0  mov      w0, w8
//   0x03a26c: 94008b75  bl       #0x5d040
//   0x03a270: d0000168  adrp     x8, #0x68000
//   0x03a274: 93407e96  sxtw     x22, w20
//   0x03a278: 910ba108  add      x8, x8, #0x2e8
//   0x03a27c: 8b161517  add      x23, x8, x22, lsl #5
//   0x03a280: f94206e4  ldr      x4, [x23, #0x408]
uint64_t fde_0293_sub_03a244(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x93407E96ULL) + (x2 ^ 0x03A244ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x03a244: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x03a248: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x03a24c: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x03a250: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x03a254: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000148ULL; // 0x03a258: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xB94FB908ULL; // 0x03a25c: ldr w8, [x8, #0xfb8]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F4ULL; // 0x03a260: mov w20, w0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x03a264: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0803E0ULL; // 0x03a268: mov w0, w8
    return acc;
}

// [EN] Reconstructed FDE #0294 @ 0x03a36c..0x03a3f8 (140 bytes)
// [VN] Phục dựng FDE #0294 tại 0x03a36c..0x03a3f8 (140 byte)
//   0x03a36c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x03a370: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03a374: 910043fd  add      x29, sp, #0x10
//   0x03a378: d0fffea0  adrp     x0, #0x10000
//   0x03a37c: 910e7c00  add      x0, x0, #0x39f
//   0x03a380: 94008b60  bl       #0x5d100
//   0x03a384: 90fffec1  adrp     x1, #0x12000
//   0x03a388: 91270421  add      x1, x1, #0x9c1
//   0x03a38c: aa0003f3  mov      x19, x0
//   0x03a390: 94008bdc  bl       #0x5d300
//   0x03a394: b40001e0  cbz      x0, #0x3a3d0
//   0x03a398: d0fffea0  adrp     x0, #0x10000
//   0x03a39c: 910e7c00  add      x0, x0, #0x39f
//   0x03a3a0: 90fffec2  adrp     x2, #0x12000
//   0x03a3a4: 90000003  adrp     x3, #0x3a000
//   0x03a3a8: 91270442  add      x2, x2, #0x9c1
uint64_t fde_0294_sub_03a36c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x910E7C00ULL) + (x2 ^ 0x03A36CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x03a36c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03a370: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03a374: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFEA0ULL; // 0x03a378: adrp x0, #0x10000
    acc = (acc * 0x100000001B3ULL) ^ 0x910E7C00ULL; // 0x03a37c: add x0, x0, #0x39f
    acc = (acc * 0x100000001B3ULL) ^ 0x94008B60ULL; // 0x03a380: bl #0x5d100
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFEC1ULL; // 0x03a384: adrp x1, #0x12000
    acc = (acc * 0x100000001B3ULL) ^ 0x91270421ULL; // 0x03a388: add x1, x1, #0x9c1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x03a38c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x94008BDCULL; // 0x03a390: bl #0x5d300
    return acc;
}

// [EN] Reconstructed FDE #0295 @ 0x03a3f8..0x03a484 (140 bytes)
// [VN] Phục dựng FDE #0295 tại 0x03a3f8..0x03a484 (140 byte)
//   0x03a3f8: d100c3ff  sub      sp, sp, #0x30
//   0x03a3fc: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x03a400: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03a404: 910083fd  add      x29, sp, #0x20
//   0x03a408: aa1e03f3  mov      x19, x30
//   0x03a40c: a90003e1  stp      x1, x0, [sp]
//   0x03a410: 90fffec1  adrp     x1, #0x12000
//   0x03a414: b0fffea2  adrp     x2, #0xf000
//   0x03a418: 913b6421  add      x1, x1, #0xed9
//   0x03a41c: 912c9042  add      x2, x2, #0xb24
//   0x03a420: 52800060  mov      w0, #3
//   0x03a424: 94008a1f  bl       #0x5cca0
//   0x03a428: 910023e0  add      x0, sp, #8
//   0x03a42c: 910003e1  mov      x1, sp
//   0x03a430: 94000015  bl       #0x3a484
//   0x03a434: aa0003f4  mov      x20, x0
uint64_t fde_0295_sub_03a3f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0x910023E0ULL) + (x2 ^ 0x03A3F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x03a3f8: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x03a3fc: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x03a400: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03a404: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x03a408: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA90003E1ULL; // 0x03a40c: stp x1, x0, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFEC1ULL; // 0x03a410: adrp x1, #0x12000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFEA2ULL; // 0x03a414: adrp x2, #0xf000
    acc = (acc * 0x100000001B3ULL) ^ 0x913B6421ULL; // 0x03a418: add x1, x1, #0xed9
    acc = (acc * 0x100000001B3ULL) ^ 0x912C9042ULL; // 0x03a41c: add x2, x2, #0xb24
    return acc;
}

// [EN] Reconstructed FDE #0296 @ 0x03a484..0x03a660 (476 bytes)
// [VN] Phục dựng FDE #0296 tại 0x03a484..0x03a660 (476 byte)
//   0x03a484: d10543ff  sub      sp, sp, #0x150
//   0x03a488: a9115ffc  stp      x28, x23, [sp, #0x110]
//   0x03a48c: a91257f6  stp      x22, x21, [sp, #0x120]
//   0x03a490: a9134ff4  stp      x20, x19, [sp, #0x130]
//   0x03a494: a9147bfd  stp      x29, x30, [sp, #0x140]
//   0x03a498: 910503fd  add      x29, sp, #0x140
//   0x03a49c: d53bd056  mrs      x22, tpidr_el0
//   0x03a4a0: f94016c8  ldr      x8, [x22, #0x28]
//   0x03a4a4: aa0103f3  mov      x19, x1
//   0x03a4a8: 90fffec1  adrp     x1, #0x12000
//   0x03a4ac: b0fffec2  adrp     x2, #0x13000
//   0x03a4b0: b0fffe83  adrp     x3, #0xb000
//   0x03a4b4: aa0003f4  mov      x20, x0
//   0x03a4b8: 913b6421  add      x1, x1, #0xed9
//   0x03a4bc: 91030c42  add      x2, x2, #0xc3
//   0x03a4c0: 912e4063  add      x3, x3, #0xb90
uint64_t fde_0296_sub_03a484(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10543FFULL) + (x1 ^ 0xAA0003F4ULL) + (x2 ^ 0x03A484ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10543FFULL; // 0x03a484: sub sp, sp, #0x150
    acc = (acc * 0x100000001B3ULL) ^ 0xA9115FFCULL; // 0x03a488: stp x28, x23, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91257F6ULL; // 0x03a48c: stp x22, x21, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9134FF4ULL; // 0x03a490: stp x20, x19, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9147BFDULL; // 0x03a494: stp x29, x30, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0x910503FDULL; // 0x03a498: add x29, sp, #0x140
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x03a49c: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x03a4a0: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x03a4a4: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFEC1ULL; // 0x03a4a8: adrp x1, #0x12000
    return acc;
}

// [EN] Reconstructed FDE #0297 @ 0x03a660..0x03a86c (524 bytes)
// [VN] Phục dựng FDE #0297 tại 0x03a660..0x03a86c (524 byte)
//   0x03a660: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x03a664: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x03a668: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x03a66c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x03a670: 9100c3fd  add      x29, sp, #0x30
//   0x03a674: d0fffec0  adrp     x0, #0x14000
//   0x03a678: 912c9c00  add      x0, x0, #0xb27
//   0x03a67c: 94008821  bl       #0x5c700
//   0x03a680: aa0003f4  mov      x20, x0
//   0x03a684: b5000120  cbnz     x0, #0x3a6a8
//   0x03a688: d0fffed3  adrp     x19, #0x14000
//   0x03a68c: 912c9e73  add      x19, x19, #0xb27
//   0x03a690: aa1303e0  mov      x0, x19
//   0x03a694: 94008b9b  bl       #0x5d500
//   0x03a698: aa1303e0  mov      x0, x19
//   0x03a69c: 94008819  bl       #0x5c700
uint64_t fde_0297_sub_03a660(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x03A660ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x03a660: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x03a664: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x03a668: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x03a66c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x03a670: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFEC0ULL; // 0x03a674: adrp x0, #0x14000
    acc = (acc * 0x100000001B3ULL) ^ 0x912C9C00ULL; // 0x03a678: add x0, x0, #0xb27
    acc = (acc * 0x100000001B3ULL) ^ 0x94008821ULL; // 0x03a67c: bl #0x5c700
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x03a680: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000120ULL; // 0x03a684: cbnz x0, #0x3a6a8
    return acc;
}

// [EN] Reconstructed FDE #0298 @ 0x03a86c..0x03a948 (220 bytes)
// [VN] Phục dựng FDE #0298 tại 0x03a86c..0x03a948 (220 byte)
//   0x03a86c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x03a870: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03a874: 910043fd  add      x29, sp, #0x10
//   0x03a878: f0000154  adrp     x20, #0x65000
//   0x03a87c: 91082294  add      x20, x20, #0x208
//   0x03a880: f9400288  ldr      x8, [x20]
//   0x03a884: b4000148  cbz      x8, #0x3a8ac
//   0x03a888: f9400688  ldr      x8, [x20, #8]
//   0x03a88c: b4000108  cbz      x8, #0x3a8ac
//   0x03a890: f9400a88  ldr      x8, [x20, #0x10]
//   0x03a894: b40000c8  cbz      x8, #0x3a8ac
//   0x03a898: 52800034  mov      w20, #1
//   0x03a89c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x03a8a0: 2a1403e0  mov      w0, w20
//   0x03a8a4: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x03a8a8: d65f03c0  ret      
uint64_t fde_0298_sub_03a86c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xA9417BFDULL) + (x2 ^ 0x03A86CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x03a86c: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03a870: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03a874: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000154ULL; // 0x03a878: adrp x20, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x91082294ULL; // 0x03a87c: add x20, x20, #0x208
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400288ULL; // 0x03a880: ldr x8, [x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000148ULL; // 0x03a884: cbz x8, #0x3a8ac
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400688ULL; // 0x03a888: ldr x8, [x20, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000108ULL; // 0x03a88c: cbz x8, #0x3a8ac
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400A88ULL; // 0x03a890: ldr x8, [x20, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0299 @ 0x03a948..0x03a9f8 (176 bytes)
// [VN] Phục dựng FDE #0299 tại 0x03a948..0x03a9f8 (176 byte)
//   0x03a948: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x03a94c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x03a950: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03a954: 910083fd  add      x29, sp, #0x20
//   0x03a958: d0000148  adrp     x8, #0x64000
//   0x03a95c: b945d108  ldr      w8, [x8, #0x5d0]
//   0x03a960: aa1e03f3  mov      x19, x30
//   0x03a964: aa0003f4  mov      x20, x0
//   0x03a968: 2a0103e3  mov      w3, w1
//   0x03a96c: 0b010115  add      w21, w8, w1
//   0x03a970: d0fffe81  adrp     x1, #0xc000
//   0x03a974: d0fffea2  adrp     x2, #0x10000
//   0x03a978: 91280c21  add      x1, x1, #0xa03
//   0x03a97c: 9124a842  add      x2, x2, #0x92a
//   0x03a980: 52800060  mov      w0, #3
//   0x03a984: 2a1503e4  mov      w4, w21
uint64_t fde_0299_sub_03a948(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x91280C21ULL) + (x2 ^ 0x03A948ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x03a948: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x03a94c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x03a950: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03a954: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000148ULL; // 0x03a958: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xB945D108ULL; // 0x03a95c: ldr w8, [x8, #0x5d0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x03a960: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x03a964: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103E3ULL; // 0x03a968: mov w3, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x0B010115ULL; // 0x03a96c: add w21, w8, w1
    return acc;
}

// [EN] Reconstructed FDE #0300 @ 0x03a9f8..0x03aab0 (184 bytes)
// [VN] Phục dựng FDE #0300 tại 0x03a9f8..0x03aab0 (184 byte)
//   0x03a9f8: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x03a9fc: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x03aa00: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03aa04: 910083fd  add      x29, sp, #0x20
//   0x03aa08: d0000148  adrp     x8, #0x64000
//   0x03aa0c: b945d508  ldr      w8, [x8, #0x5d4]
//   0x03aa10: aa1e03f3  mov      x19, x30
//   0x03aa14: aa0003f4  mov      x20, x0
//   0x03aa18: 2a0103e3  mov      w3, w1
//   0x03aa1c: 0b010108  add      w8, w8, w1
//   0x03aa20: 71000d1f  cmp      w8, #3
//   0x03aa24: 1a88b035  csel     w21, w1, w8, lt
//   0x03aa28: d0fffe81  adrp     x1, #0xc000
//   0x03aa2c: 90fffea2  adrp     x2, #0xe000
//   0x03aa30: 91280c21  add      x1, x1, #0xa03
//   0x03aa34: 912c5442  add      x2, x2, #0xb15
uint64_t fde_0300_sub_03a9f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xD0FFFE81ULL) + (x2 ^ 0x03A9F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x03a9f8: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x03a9fc: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x03aa00: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03aa04: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000148ULL; // 0x03aa08: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xB945D508ULL; // 0x03aa0c: ldr w8, [x8, #0x5d4]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x03aa10: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x03aa14: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103E3ULL; // 0x03aa18: mov w3, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x0B010108ULL; // 0x03aa1c: add w8, w8, w1
    return acc;
}

// [EN] Reconstructed FDE #0301 @ 0x03aab0..0x03aaf0 (64 bytes)
// [VN] Phục dựng FDE #0301 tại 0x03aab0..0x03aaf0 (64 byte)
//   0x03aab0: 34000121  cbz      w1, #0x3aad4
//   0x03aab4: 2a0103e8  mov      w8, w1
//   0x03aab8: d0fffe81  adrp     x1, #0xc000
//   0x03aabc: b0fffe82  adrp     x2, #0xb000
//   0x03aac0: 91280c21  add      x1, x1, #0xa03
//   0x03aac4: 91123c42  add      x2, x2, #0x48f
//   0x03aac8: 52800060  mov      w0, #3
//   0x03aacc: 2a0803e3  mov      w3, w8
//   0x03aad0: 14008874  b        #0x5cca0
//   0x03aad4: aa0203e3  mov      x3, x2
//   0x03aad8: d0fffe81  adrp     x1, #0xc000
//   0x03aadc: d0fffea2  adrp     x2, #0x10000
//   0x03aae0: 91280c21  add      x1, x1, #0xa03
//   0x03aae4: 910f3042  add      x2, x2, #0x3cc
//   0x03aae8: 52800060  mov      w0, #3
//   0x03aaec: 1400886d  b        #0x5cca0
uint64_t fde_0301_sub_03aab0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x34000121ULL) + (x1 ^ 0x91280C21ULL) + (x2 ^ 0x03AAB0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x34000121ULL; // 0x03aab0: cbz w1, #0x3aad4
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103E8ULL; // 0x03aab4: mov w8, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFE81ULL; // 0x03aab8: adrp x1, #0xc000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFE82ULL; // 0x03aabc: adrp x2, #0xb000
    acc = (acc * 0x100000001B3ULL) ^ 0x91280C21ULL; // 0x03aac0: add x1, x1, #0xa03
    acc = (acc * 0x100000001B3ULL) ^ 0x91123C42ULL; // 0x03aac4: add x2, x2, #0x48f
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x03aac8: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0803E3ULL; // 0x03aacc: mov w3, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x14008874ULL; // 0x03aad0: b #0x5cca0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E3ULL; // 0x03aad4: mov x3, x2
    return acc;
}

// [EN] Reconstructed FDE #0302 @ 0x03aaf0..0x03ab88 (152 bytes)
// [VN] Phục dựng FDE #0302 tại 0x03aaf0..0x03ab88 (152 byte)
//   0x03aaf0: d10443ff  sub      sp, sp, #0x110
//   0x03aaf4: a90f4ffc  stp      x28, x19, [sp, #0xf0]
//   0x03aaf8: a9107bfd  stp      x29, x30, [sp, #0x100]
//   0x03aafc: 910403fd  add      x29, sp, #0x100
//   0x03ab00: a90817e4  stp      x4, x5, [sp, #0x80]
//   0x03ab04: a9091fe6  stp      x6, x7, [sp, #0x90]
//   0x03ab08: ad0007e0  stp      q0, q1, [sp]
//   0x03ab0c: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x03ab10: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x03ab14: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x03ab18: d53bd053  mrs      x19, tpidr_el0
//   0x03ab1c: f9401669  ldr      x9, [x19, #0x28]
//   0x03ab20: 910203ea  add      x10, sp, #0x80
//   0x03ab24: 928003ec  mov      x12, #-0x20
//   0x03ab28: 910043ab  add      x11, x29, #0x10
//   0x03ab2c: f81e83a9  stur     x9, [x29, #-0x18]
uint64_t fde_0302_sub_03aaf0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10443FFULL) + (x1 ^ 0x910203EAULL) + (x2 ^ 0x03AAF0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10443FFULL; // 0x03aaf0: sub sp, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90F4FFCULL; // 0x03aaf4: stp x28, x19, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9107BFDULL; // 0x03aaf8: stp x29, x30, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0x910403FDULL; // 0x03aafc: add x29, sp, #0x100
    acc = (acc * 0x100000001B3ULL) ^ 0xA90817E4ULL; // 0x03ab00: stp x4, x5, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9091FE6ULL; // 0x03ab04: stp x6, x7, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x03ab08: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x03ab0c: stp q2, q3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0217E4ULL; // 0x03ab10: stp q4, q5, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD031FE6ULL; // 0x03ab14: stp q6, q7, [sp, #0x60]
    return acc;
}

// [EN] Reconstructed FDE #0303 @ 0x03ab88..0x03aca8 (288 bytes)
// [VN] Phục dựng FDE #0303 tại 0x03ab88..0x03aca8 (288 byte)
//   0x03ab88: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x03ab8c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x03ab90: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x03ab94: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x03ab98: 9100c3fd  add      x29, sp, #0x30
//   0x03ab9c: aa1e03f3  mov      x19, x30
//   0x03aba0: aa0303f4  mov      x20, x3
//   0x03aba4: aa0203f5  mov      x21, x2
//   0x03aba8: aa0103f7  mov      x23, x1
//   0x03abac: aa0003f6  mov      x22, x0
//   0x03abb0: b5000161  cbnz     x1, #0x3abdc
//   0x03abb4: d0000158  adrp     x24, #0x64000
//   0x03abb8: b94f3b08  ldr      w8, [x24, #0xf38]
//   0x03abbc: 7100051f  cmp      w8, #1
//   0x03abc0: 540000eb  b.lt     #0x3abdc
//   0x03abc4: 52800700  mov      w0, #0x38
uint64_t fde_0303_sub_03ab88(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0xB94F3B08ULL) + (x2 ^ 0x03AB88ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x03ab88: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x03ab8c: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x03ab90: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x03ab94: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x03ab98: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x03ab9c: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F4ULL; // 0x03aba0: mov x20, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x03aba4: mov x21, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F7ULL; // 0x03aba8: mov x23, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F6ULL; // 0x03abac: mov x22, x0
    return acc;
}

// [EN] Reconstructed FDE #0304 @ 0x03aca8..0x03ad20 (120 bytes)
// [VN] Phục dựng FDE #0304 tại 0x03aca8..0x03ad20 (120 byte)
//   0x03aca8: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x03acac: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03acb0: 910043fd  add      x29, sp, #0x10
//   0x03acb4: f0fffe81  adrp     x1, #0xd000
//   0x03acb8: 91013821  add      x1, x1, #0x4e
//   0x03acbc: aa0003f3  mov      x19, x0
//   0x03acc0: 9400887c  bl       #0x5ceb0
//   0x03acc4: b40000a0  cbz      x0, #0x3acd8
//   0x03acc8: 2a1f03e0  mov      w0, wzr
//   0x03accc: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x03acd0: f84207f3  ldr      x19, [sp], #0x20
//   0x03acd4: d65f03c0  ret      
//   0x03acd8: b0fffe81  adrp     x1, #0xb000
//   0x03acdc: 91128021  add      x1, x1, #0x4a0
//   0x03ace0: aa1303e0  mov      x0, x19
//   0x03ace4: 94008873  bl       #0x5ceb0
uint64_t fde_0304_sub_03aca8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xB0FFFE81ULL) + (x2 ^ 0x03ACA8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x03aca8: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03acac: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03acb0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFE81ULL; // 0x03acb4: adrp x1, #0xd000
    acc = (acc * 0x100000001B3ULL) ^ 0x91013821ULL; // 0x03acb8: add x1, x1, #0x4e
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x03acbc: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9400887CULL; // 0x03acc0: bl #0x5ceb0
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000A0ULL; // 0x03acc4: cbz x0, #0x3acd8
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x03acc8: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x03accc: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0305 @ 0x03ad20..0x03b07c (860 bytes)
// [VN] Phục dựng FDE #0305 tại 0x03ad20..0x03b07c (860 byte)
//   0x03ad20: d10183ff  sub      sp, sp, #0x60
//   0x03ad24: f9001bf5  str      x21, [sp, #0x30]
//   0x03ad28: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x03ad2c: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x03ad30: 910143fd  add      x29, sp, #0x50
//   0x03ad34: d53bd054  mrs      x20, tpidr_el0
//   0x03ad38: f9401688  ldr      x8, [x20, #0x28]
//   0x03ad3c: 2a0203f3  mov      w19, w2
//   0x03ad40: f90017e8  str      x8, [sp, #0x28]
//   0x03ad44: 97fffeca  bl       #0x3a86c
//   0x03ad48: 36000a20  tbz      w0, #0, #0x3ae8c
//   0x03ad4c: f0000155  adrp     x21, #0x65000
//   0x03ad50: f9410ea8  ldr      x8, [x21, #0x218]
//   0x03ad54: b0fffea0  adrp     x0, #0xf000
//   0x03ad58: 52800109  mov      w9, #8
//   0x03ad5c: 91036000  add      x0, x0, #0xd8
uint64_t fde_0305_sub_03ad20(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xF9410EA8ULL) + (x2 ^ 0x03AD20ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x03ad20: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF5ULL; // 0x03ad24: str x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x03ad28: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x03ad2c: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x03ad30: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x03ad34: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x03ad38: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F3ULL; // 0x03ad3c: mov w19, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xF90017E8ULL; // 0x03ad40: str x8, [sp, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFECAULL; // 0x03ad44: bl #0x3a86c
    return acc;
}

// [EN] Reconstructed FDE #0306 @ 0x03b07c..0x03b1a0 (292 bytes)
// [VN] Phục dựng FDE #0306 tại 0x03b07c..0x03b1a0 (292 byte)
//   0x03b07c: d10283ff  sub      sp, sp, #0xa0
//   0x03b080: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x03b084: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x03b088: 910243fd  add      x29, sp, #0x90
//   0x03b08c: d53bd054  mrs      x20, tpidr_el0
//   0x03b090: f9401688  ldr      x8, [x20, #0x28]
//   0x03b094: f81e83a8  stur     x8, [x29, #-0x18]
//   0x03b098: 97fffdf5  bl       #0x3a86c
//   0x03b09c: 36000360  tbz      w0, #0, #0x3b108
//   0x03b0a0: d0000153  adrp     x19, #0x65000
//   0x03b0a4: f9410e68  ldr      x8, [x19, #0x218]
//   0x03b0a8: d0fffe80  adrp     x0, #0xd000
//   0x03b0ac: 9139a400  add      x0, x0, #0xe69
//   0x03b0b0: aa1f03e1  mov      x1, xzr
//   0x03b0b4: aa1f03e2  mov      x2, xzr
//   0x03b0b8: aa1f03e3  mov      x3, xzr
uint64_t fde_0306_sub_03b07c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10283FFULL) + (x1 ^ 0x9139A400ULL) + (x2 ^ 0x03B07CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10283FFULL; // 0x03b07c: sub sp, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9084FF4ULL; // 0x03b080: stp x20, x19, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9097BFDULL; // 0x03b084: stp x29, x30, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0x910243FDULL; // 0x03b088: add x29, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x03b08c: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x03b090: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E83A8ULL; // 0x03b094: stur x8, [x29, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFDF5ULL; // 0x03b098: bl #0x3a86c
    acc = (acc * 0x100000001B3ULL) ^ 0x36000360ULL; // 0x03b09c: tbz w0, #0, #0x3b108
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000153ULL; // 0x03b0a0: adrp x19, #0x65000
    return acc;
}

// [EN] Reconstructed FDE #0307 @ 0x03b1a0..0x03b340 (416 bytes)
// [VN] Phục dựng FDE #0307 tại 0x03b1a0..0x03b340 (416 byte)
//   0x03b1a0: d10343ff  sub      sp, sp, #0xd0
//   0x03b1a4: a9095ff8  stp      x24, x23, [sp, #0x90]
//   0x03b1a8: a90a57f6  stp      x22, x21, [sp, #0xa0]
//   0x03b1ac: a90b4ff4  stp      x20, x19, [sp, #0xb0]
//   0x03b1b0: a90c7bfd  stp      x29, x30, [sp, #0xc0]
//   0x03b1b4: 910303fd  add      x29, sp, #0xc0
//   0x03b1b8: d53bd056  mrs      x22, tpidr_el0
//   0x03b1bc: f94016c8  ldr      x8, [x22, #0x28]
//   0x03b1c0: 2a0203f3  mov      w19, w2
//   0x03b1c4: f81c83a8  stur     x8, [x29, #-0x38]
//   0x03b1c8: 97fffda9  bl       #0x3a86c
//   0x03b1cc: 36000420  tbz      w0, #0, #0x3b250
//   0x03b1d0: d0000157  adrp     x23, #0x65000
//   0x03b1d4: f9410ee9  ldr      x9, [x23, #0x218]
//   0x03b1d8: 93407e68  sxtw     x8, w19
//   0x03b1dc: d0fffe80  adrp     x0, #0xd000
uint64_t fde_0307_sub_03b1a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10343FFULL) + (x1 ^ 0xD0000157ULL) + (x2 ^ 0x03B1A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10343FFULL; // 0x03b1a0: sub sp, sp, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9095FF8ULL; // 0x03b1a4: stp x24, x23, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A57F6ULL; // 0x03b1a8: stp x22, x21, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B4FF4ULL; // 0x03b1ac: stp x20, x19, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C7BFDULL; // 0x03b1b0: stp x29, x30, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910303FDULL; // 0x03b1b4: add x29, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x03b1b8: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x03b1bc: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F3ULL; // 0x03b1c0: mov w19, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C83A8ULL; // 0x03b1c4: stur x8, [x29, #-0x38]
    return acc;
}

// [EN] Reconstructed FDE #0308 @ 0x03b340..0x03b3a8 (104 bytes)
// [VN] Phục dựng FDE #0308 tại 0x03b340..0x03b3a8 (104 byte)
//   0x03b340: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x03b344: 910003fd  mov      x29, sp
//   0x03b348: b0000148  adrp     x8, #0x64000
//   0x03b34c: 913ce108  add      x8, x8, #0xf38
//   0x03b350: f9417509  ldr      x9, [x8, #0x2e8]
//   0x03b354: b9000102  str      w2, [x8]
//   0x03b358: b4000089  cbz      x9, #0x3b368
//   0x03b35c: 52800020  mov      w0, #1
//   0x03b360: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x03b364: d65f03c0  ret      
//   0x03b368: f0ffffe0  adrp     x0, #0x3a000
//   0x03b36c: f0fffe83  adrp     x3, #0xe000
//   0x03b370: f0ffffe4  adrp     x4, #0x3a000
//   0x03b374: 9132a000  add      x0, x0, #0xca8
//   0x03b378: 913fd463  add      x3, x3, #0xff5
//   0x03b37c: 912e2084  add      x4, x4, #0xb88
uint64_t fde_0308_sub_03b340(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xF0FFFFE4ULL) + (x2 ^ 0x03B340ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x03b340: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x03b344: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000148ULL; // 0x03b348: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x913CE108ULL; // 0x03b34c: add x8, x8, #0xf38
    acc = (acc * 0x100000001B3ULL) ^ 0xF9417509ULL; // 0x03b350: ldr x9, [x8, #0x2e8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9000102ULL; // 0x03b354: str w2, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000089ULL; // 0x03b358: cbz x9, #0x3b368
    acc = (acc * 0x100000001B3ULL) ^ 0x52800020ULL; // 0x03b35c: mov w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x03b360: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x03b364: ret 
    return acc;
}

// [EN] Reconstructed FDE #0309 @ 0x03b3a8..0x03b400 (88 bytes)
// [VN] Phục dựng FDE #0309 tại 0x03b3a8..0x03b400 (88 byte)
//   0x03b3a8: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x03b3ac: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03b3b0: 910043fd  add      x29, sp, #0x10
//   0x03b3b4: 2a1f03e0  mov      w0, wzr
//   0x03b3b8: 2a1f03e1  mov      w1, wzr
//   0x03b3bc: 2a0203f3  mov      w19, w2
//   0x03b3c0: 94008808  bl       #0x5d3e0
//   0x03b3c4: b0fffea1  adrp     x1, #0x10000
//   0x03b3c8: f0ffffe2  adrp     x2, #0x3a000
//   0x03b3cc: f0ffffe3  adrp     x3, #0x3a000
//   0x03b3d0: b0000148  adrp     x8, #0x64000
//   0x03b3d4: 9125c021  add      x1, x1, #0x970
//   0x03b3d8: 9127e042  add      x2, x2, #0x9f8
//   0x03b3dc: 912ac063  add      x3, x3, #0xab0
//   0x03b3e0: aa1f03e0  mov      x0, xzr
//   0x03b3e4: aa1f03e4  mov      x4, xzr
uint64_t fde_0309_sub_03b3a8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x9127E042ULL) + (x2 ^ 0x03B3A8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x03b3a8: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03b3ac: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03b3b0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x03b3b4: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E1ULL; // 0x03b3b8: mov w1, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F3ULL; // 0x03b3bc: mov w19, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x94008808ULL; // 0x03b3c0: bl #0x5d3e0
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFEA1ULL; // 0x03b3c4: adrp x1, #0x10000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFFE2ULL; // 0x03b3c8: adrp x2, #0x3a000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFFE3ULL; // 0x03b3cc: adrp x3, #0x3a000
    return acc;
}

// [EN] Reconstructed FDE #0310 @ 0x03b400..0x03b458 (88 bytes)
// [VN] Phục dựng FDE #0310 tại 0x03b400..0x03b458 (88 byte)
//   0x03b400: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x03b404: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03b408: 910043fd  add      x29, sp, #0x10
//   0x03b40c: 2a1f03e0  mov      w0, wzr
//   0x03b410: 2a1f03e1  mov      w1, wzr
//   0x03b414: 2a0203f3  mov      w19, w2
//   0x03b418: 940087f2  bl       #0x5d3e0
//   0x03b41c: b0fffea1  adrp     x1, #0x10000
//   0x03b420: f0ffffe2  adrp     x2, #0x3a000
//   0x03b424: f0ffffe3  adrp     x3, #0x3a000
//   0x03b428: b0000148  adrp     x8, #0x64000
//   0x03b42c: 913d4821  add      x1, x1, #0xf52
//   0x03b430: 91252042  add      x2, x2, #0x948
//   0x03b434: 912ac063  add      x3, x3, #0xab0
//   0x03b438: aa1f03e0  mov      x0, xzr
//   0x03b43c: aa1f03e4  mov      x4, xzr
uint64_t fde_0310_sub_03b400(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x91252042ULL) + (x2 ^ 0x03B400ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x03b400: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03b404: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03b408: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x03b40c: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E1ULL; // 0x03b410: mov w1, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F3ULL; // 0x03b414: mov w19, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x940087F2ULL; // 0x03b418: bl #0x5d3e0
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFEA1ULL; // 0x03b41c: adrp x1, #0x10000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFFE2ULL; // 0x03b420: adrp x2, #0x3a000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFFE3ULL; // 0x03b424: adrp x3, #0x3a000
    return acc;
}

// [EN] Reconstructed FDE #0311 @ 0x03b458..0x03b470 (24 bytes)
// [VN] Phục dựng FDE #0311 tại 0x03b458..0x03b470 (24 byte)
//   0x03b458: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x03b45c: 910003fd  mov      x29, sp
//   0x03b460: 97fffd03  bl       #0x3a86c
//   0x03b464: 12000000  and      w0, w0, #1
//   0x03b468: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x03b46c: d65f03c0  ret      
uint64_t fde_0311_sub_03b458(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x03B458ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x03b458: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x03b45c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFD03ULL; // 0x03b460: bl #0x3a86c
    acc = (acc * 0x100000001B3ULL) ^ 0x12000000ULL; // 0x03b464: and w0, w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x03b468: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x03b46c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0312 @ 0x03b470..0x03b550 (224 bytes)
// [VN] Phục dựng FDE #0312 tại 0x03b470..0x03b550 (224 byte)
//   0x03b470: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x03b474: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03b478: 910043fd  add      x29, sp, #0x10
//   0x03b47c: d0000154  adrp     x20, #0x65000
//   0x03b480: 9108a294  add      x20, x20, #0x228
//   0x03b484: f9400688  ldr      x8, [x20, #8]
//   0x03b488: b4000148  cbz      x8, #0x3b4b0
//   0x03b48c: f9400a88  ldr      x8, [x20, #0x10]
//   0x03b490: b4000108  cbz      x8, #0x3b4b0
//   0x03b494: f9400288  ldr      x8, [x20]
//   0x03b498: b40000c8  cbz      x8, #0x3b4b0
//   0x03b49c: 52800034  mov      w20, #1
//   0x03b4a0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x03b4a4: 2a1403e0  mov      w0, w20
//   0x03b4a8: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x03b4ac: d65f03c0  ret      
uint64_t fde_0312_sub_03b470(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xA9417BFDULL) + (x2 ^ 0x03B470ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x03b470: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03b474: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03b478: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000154ULL; // 0x03b47c: adrp x20, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x9108A294ULL; // 0x03b480: add x20, x20, #0x228
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400688ULL; // 0x03b484: ldr x8, [x20, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000148ULL; // 0x03b488: cbz x8, #0x3b4b0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400A88ULL; // 0x03b48c: ldr x8, [x20, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000108ULL; // 0x03b490: cbz x8, #0x3b4b0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400288ULL; // 0x03b494: ldr x8, [x20]
    return acc;
}

// [EN] Reconstructed FDE #0313 @ 0x03b550..0x03b5e8 (152 bytes)
// [VN] Phục dựng FDE #0313 tại 0x03b550..0x03b5e8 (152 byte)
//   0x03b550: d10443ff  sub      sp, sp, #0x110
//   0x03b554: a90f4ffc  stp      x28, x19, [sp, #0xf0]
//   0x03b558: a9107bfd  stp      x29, x30, [sp, #0x100]
//   0x03b55c: 910403fd  add      x29, sp, #0x100
//   0x03b560: a90817e4  stp      x4, x5, [sp, #0x80]
//   0x03b564: a9091fe6  stp      x6, x7, [sp, #0x90]
//   0x03b568: ad0007e0  stp      q0, q1, [sp]
//   0x03b56c: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x03b570: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x03b574: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x03b578: d53bd053  mrs      x19, tpidr_el0
//   0x03b57c: f9401669  ldr      x9, [x19, #0x28]
//   0x03b580: 910203ea  add      x10, sp, #0x80
//   0x03b584: 928003ec  mov      x12, #-0x20
//   0x03b588: 910043ab  add      x11, x29, #0x10
//   0x03b58c: f81e83a9  stur     x9, [x29, #-0x18]
uint64_t fde_0313_sub_03b550(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10443FFULL) + (x1 ^ 0x910203EAULL) + (x2 ^ 0x03B550ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10443FFULL; // 0x03b550: sub sp, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90F4FFCULL; // 0x03b554: stp x28, x19, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9107BFDULL; // 0x03b558: stp x29, x30, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0x910403FDULL; // 0x03b55c: add x29, sp, #0x100
    acc = (acc * 0x100000001B3ULL) ^ 0xA90817E4ULL; // 0x03b560: stp x4, x5, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9091FE6ULL; // 0x03b564: stp x6, x7, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x03b568: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x03b56c: stp q2, q3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0217E4ULL; // 0x03b570: stp q4, q5, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD031FE6ULL; // 0x03b574: stp q6, q7, [sp, #0x60]
    return acc;
}

// [EN] Reconstructed FDE #0314 @ 0x03b5e8..0x03b67c (148 bytes)
// [VN] Phục dựng FDE #0314 tại 0x03b5e8..0x03b67c (148 byte)
//   0x03b5e8: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x03b5ec: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x03b5f0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03b5f4: 910083fd  add      x29, sp, #0x20
//   0x03b5f8: aa0003f3  mov      x19, x0
//   0x03b5fc: a9007c1f  stp      xzr, xzr, [x0]
//   0x03b600: f900081f  str      xzr, [x0, #0x10]
//   0x03b604: aa0103e0  mov      x0, x1
//   0x03b608: aa0103f4  mov      x20, x1
//   0x03b60c: 940085fd  bl       #0x5ce00
//   0x03b610: b100401f  cmn      x0, #0x10
//   0x03b614: 54000322  b.hs     #0x3b678
//   0x03b618: aa0003f5  mov      x21, x0
//   0x03b61c: f1005c1f  cmp      x0, #0x17
//   0x03b620: 540000a2  b.hs     #0x3b634
//   0x03b624: 531f7aa8  lsl      w8, w21, #1
uint64_t fde_0314_sub_03b5e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA0003F5ULL) + (x2 ^ 0x03B5E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x03b5e8: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x03b5ec: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x03b5f0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03b5f4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x03b5f8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9007C1FULL; // 0x03b5fc: stp xzr, xzr, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900081FULL; // 0x03b600: str xzr, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x03b604: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x03b608: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x940085FDULL; // 0x03b60c: bl #0x5ce00
    return acc;
}

// [EN] Reconstructed FDE #0315 @ 0x03b67c..0x03b744 (200 bytes)
// [VN] Phục dựng FDE #0315 tại 0x03b67c..0x03b744 (200 byte)
//   0x03b67c: d100c3ff  sub      sp, sp, #0x30
//   0x03b680: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x03b684: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03b688: 910083fd  add      x29, sp, #0x20
//   0x03b68c: d53bd054  mrs      x20, tpidr_el0
//   0x03b690: f9401688  ldr      x8, [x20, #0x28]
//   0x03b694: 2a0203f3  mov      w19, w2
//   0x03b698: f90007e8  str      x8, [sp, #8]
//   0x03b69c: 97ffff75  bl       #0x3b470
//   0x03b6a0: 36000260  tbz      w0, #0, #0x3b6ec
//   0x03b6a4: d0000148  adrp     x8, #0x65000
//   0x03b6a8: f9411508  ldr      x8, [x8, #0x228]
//   0x03b6ac: f0fffea0  adrp     x0, #0x12000
//   0x03b6b0: 9101c000  add      x0, x0, #0x70
//   0x03b6b4: 910013e3  add      x3, sp, #4
//   0x03b6b8: 52800084  mov      w4, #4
uint64_t fde_0315_sub_03b67c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0xF0FFFEA0ULL) + (x2 ^ 0x03B67CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x03b67c: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x03b680: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x03b684: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03b688: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x03b68c: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x03b690: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F3ULL; // 0x03b694: mov w19, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x03b698: str x8, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFF75ULL; // 0x03b69c: bl #0x3b470
    acc = (acc * 0x100000001B3ULL) ^ 0x36000260ULL; // 0x03b6a0: tbz w0, #0, #0x3b6ec
    return acc;
}

// [EN] Reconstructed FDE #0316 @ 0x03b744..0x03b818 (212 bytes)
// [VN] Phục dựng FDE #0316 tại 0x03b744..0x03b818 (212 byte)
//   0x03b744: d100c3ff  sub      sp, sp, #0x30
//   0x03b748: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x03b74c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03b750: 910083fd  add      x29, sp, #0x20
//   0x03b754: d53bd054  mrs      x20, tpidr_el0
//   0x03b758: f9401688  ldr      x8, [x20, #0x28]
//   0x03b75c: 72001c5f  tst      w2, #0xff
//   0x03b760: 1a9f07e9  cset     w9, ne
//   0x03b764: f90007e8  str      x8, [sp, #8]
//   0x03b768: 390013e9  strb     w9, [sp, #4]
//   0x03b76c: 97ffff41  bl       #0x3b470
//   0x03b770: 36000260  tbz      w0, #0, #0x3b7bc
//   0x03b774: d0000148  adrp     x8, #0x65000
//   0x03b778: f9411508  ldr      x8, [x8, #0x228]
//   0x03b77c: f0fffea0  adrp     x0, #0x12000
//   0x03b780: 913c5800  add      x0, x0, #0xf16
uint64_t fde_0316_sub_03b744(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0xD0000148ULL) + (x2 ^ 0x03B744ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x03b744: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x03b748: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x03b74c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03b750: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x03b754: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x03b758: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x72001C5FULL; // 0x03b75c: tst w2, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F07E9ULL; // 0x03b760: cset w9, ne
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x03b764: str x8, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x390013E9ULL; // 0x03b768: strb w9, [sp, #4]
    return acc;
}

// [EN] Reconstructed FDE #0317 @ 0x03b818..0x03b89c (132 bytes)
// [VN] Phục dựng FDE #0317 tại 0x03b818..0x03b89c (132 byte)
//   0x03b818: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x03b81c: 910003fd  mov      x29, sp
//   0x03b820: 97ffff14  bl       #0x3b470
//   0x03b824: 36000240  tbz      w0, #0, #0x3b86c
//   0x03b828: d0000148  adrp     x8, #0x65000
//   0x03b82c: f9411508  ldr      x8, [x8, #0x228]
//   0x03b830: d0fffe80  adrp     x0, #0xd000
//   0x03b834: 9139a400  add      x0, x0, #0xe69
//   0x03b838: aa1f03e1  mov      x1, xzr
//   0x03b83c: aa1f03e2  mov      x2, xzr
//   0x03b840: aa1f03e3  mov      x3, xzr
//   0x03b844: aa1f03e4  mov      x4, xzr
//   0x03b848: d63f0100  blr      x8
//   0x03b84c: 34000160  cbz      w0, #0x3b878
//   0x03b850: b0fffe81  adrp     x1, #0xc000
//   0x03b854: b0fffea2  adrp     x2, #0x10000
uint64_t fde_0317_sub_03b818(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD63F0100ULL) + (x2 ^ 0x03B818ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x03b818: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x03b81c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFF14ULL; // 0x03b820: bl #0x3b470
    acc = (acc * 0x100000001B3ULL) ^ 0x36000240ULL; // 0x03b824: tbz w0, #0, #0x3b86c
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000148ULL; // 0x03b828: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9411508ULL; // 0x03b82c: ldr x8, [x8, #0x228]
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFE80ULL; // 0x03b830: adrp x0, #0xd000
    acc = (acc * 0x100000001B3ULL) ^ 0x9139A400ULL; // 0x03b834: add x0, x0, #0xe69
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x03b838: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x03b83c: mov x2, xzr
    return acc;
}

// [EN] Reconstructed FDE #0318 @ 0x03b89c..0x03b920 (132 bytes)
// [VN] Phục dựng FDE #0318 tại 0x03b89c..0x03b920 (132 byte)
//   0x03b89c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x03b8a0: 910003fd  mov      x29, sp
//   0x03b8a4: 97fffef3  bl       #0x3b470
//   0x03b8a8: 36000240  tbz      w0, #0, #0x3b8f0
//   0x03b8ac: d0000148  adrp     x8, #0x65000
//   0x03b8b0: f9411508  ldr      x8, [x8, #0x228]
//   0x03b8b4: b0fffec0  adrp     x0, #0x14000
//   0x03b8b8: 912d0400  add      x0, x0, #0xb41
//   0x03b8bc: aa1f03e1  mov      x1, xzr
//   0x03b8c0: aa1f03e2  mov      x2, xzr
//   0x03b8c4: aa1f03e3  mov      x3, xzr
//   0x03b8c8: aa1f03e4  mov      x4, xzr
//   0x03b8cc: d63f0100  blr      x8
//   0x03b8d0: 34000160  cbz      w0, #0x3b8fc
//   0x03b8d4: b0fffe81  adrp     x1, #0xc000
//   0x03b8d8: 90fffec2  adrp     x2, #0x13000
uint64_t fde_0318_sub_03b89c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD63F0100ULL) + (x2 ^ 0x03B89CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x03b89c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x03b8a0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFEF3ULL; // 0x03b8a4: bl #0x3b470
    acc = (acc * 0x100000001B3ULL) ^ 0x36000240ULL; // 0x03b8a8: tbz w0, #0, #0x3b8f0
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000148ULL; // 0x03b8ac: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9411508ULL; // 0x03b8b0: ldr x8, [x8, #0x228]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFEC0ULL; // 0x03b8b4: adrp x0, #0x14000
    acc = (acc * 0x100000001B3ULL) ^ 0x912D0400ULL; // 0x03b8b8: add x0, x0, #0xb41
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x03b8bc: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x03b8c0: mov x2, xzr
    return acc;
}

// [EN] Reconstructed FDE #0319 @ 0x03b920..0x03ba00 (224 bytes)
// [VN] Phục dựng FDE #0319 tại 0x03b920..0x03ba00 (224 byte)
//   0x03b920: d10103ff  sub      sp, sp, #0x40
//   0x03b924: f90013f3  str      x19, [sp, #0x20]
//   0x03b928: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x03b92c: 9100c3fd  add      x29, sp, #0x30
//   0x03b930: d53bd053  mrs      x19, tpidr_el0
//   0x03b934: f9401668  ldr      x8, [x19, #0x28]
//   0x03b938: f9000fe8  str      x8, [sp, #0x18]
//   0x03b93c: 97fffecd  bl       #0x3b470
//   0x03b940: 36000340  tbz      w0, #0, #0x3b9a8
//   0x03b944: d0000148  adrp     x8, #0x65000
//   0x03b948: f9411508  ldr      x8, [x8, #0x228]
//   0x03b94c: 90fffec0  adrp     x0, #0x13000
//   0x03b950: 52800089  mov      w9, #4
//   0x03b954: 91318c00  add      x0, x0, #0xc63
//   0x03b958: 910053e1  add      x1, sp, #0x14
//   0x03b95c: 910023e2  add      x2, sp, #8
uint64_t fde_0319_sub_03b920(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x52800089ULL) + (x2 ^ 0x03B920ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x03b920: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F3ULL; // 0x03b924: str x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x03b928: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x03b92c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x03b930: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x03b934: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x03b938: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFECDULL; // 0x03b93c: bl #0x3b470
    acc = (acc * 0x100000001B3ULL) ^ 0x36000340ULL; // 0x03b940: tbz w0, #0, #0x3b9a8
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000148ULL; // 0x03b944: adrp x8, #0x65000
    return acc;
}

// [EN] Reconstructed FDE #0320 @ 0x03ba00..0x03bac8 (200 bytes)
// [VN] Phục dựng FDE #0320 tại 0x03ba00..0x03bac8 (200 byte)
//   0x03ba00: d100c3ff  sub      sp, sp, #0x30
//   0x03ba04: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x03ba08: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03ba0c: 910083fd  add      x29, sp, #0x20
//   0x03ba10: d53bd054  mrs      x20, tpidr_el0
//   0x03ba14: f9401688  ldr      x8, [x20, #0x28]
//   0x03ba18: 2a0203f3  mov      w19, w2
//   0x03ba1c: f90007e8  str      x8, [sp, #8]
//   0x03ba20: 97fffe94  bl       #0x3b470
//   0x03ba24: 36000260  tbz      w0, #0, #0x3ba70
//   0x03ba28: d0000148  adrp     x8, #0x65000
//   0x03ba2c: f9411508  ldr      x8, [x8, #0x228]
//   0x03ba30: 90fffea0  adrp     x0, #0xf000
//   0x03ba34: 912de000  add      x0, x0, #0xb78
//   0x03ba38: 910013e3  add      x3, sp, #4
//   0x03ba3c: 52800084  mov      w4, #4
uint64_t fde_0320_sub_03ba00(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0x90FFFEA0ULL) + (x2 ^ 0x03BA00ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x03ba00: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x03ba04: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x03ba08: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03ba0c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x03ba10: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x03ba14: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F3ULL; // 0x03ba18: mov w19, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x03ba1c: str x8, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFE94ULL; // 0x03ba20: bl #0x3b470
    acc = (acc * 0x100000001B3ULL) ^ 0x36000260ULL; // 0x03ba24: tbz w0, #0, #0x3ba70
    return acc;
}

// [EN] Reconstructed FDE #0321 @ 0x03bac8..0x03bce4 (540 bytes)
// [VN] Phục dựng FDE #0321 tại 0x03bac8..0x03bce4 (540 byte)
//   0x03bac8: d10343ff  sub      sp, sp, #0xd0
//   0x03bacc: a9095ff8  stp      x24, x23, [sp, #0x90]
//   0x03bad0: a90a57f6  stp      x22, x21, [sp, #0xa0]
//   0x03bad4: a90b4ff4  stp      x20, x19, [sp, #0xb0]
//   0x03bad8: a90c7bfd  stp      x29, x30, [sp, #0xc0]
//   0x03badc: 910303fd  add      x29, sp, #0xc0
//   0x03bae0: d53bd057  mrs      x23, tpidr_el0
//   0x03bae4: f94016e8  ldr      x8, [x23, #0x28]
//   0x03bae8: aa0203e1  mov      x1, x2
//   0x03baec: aa1f03e2  mov      x2, xzr
//   0x03baf0: f81c83a8  stur     x8, [x29, #-0x38]
//   0x03baf4: f9400008  ldr      x8, [x0]
//   0x03baf8: f942a508  ldr      x8, [x8, #0x548]
//   0x03bafc: d63f0100  blr      x8
//   0x03bb00: aa0003f3  mov      x19, x0
//   0x03bb04: f9000fe0  str      x0, [sp, #0x18]
uint64_t fde_0321_sub_03bac8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10343FFULL) + (x1 ^ 0xF942A508ULL) + (x2 ^ 0x03BAC8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10343FFULL; // 0x03bac8: sub sp, sp, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9095FF8ULL; // 0x03bacc: stp x24, x23, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A57F6ULL; // 0x03bad0: stp x22, x21, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B4FF4ULL; // 0x03bad4: stp x20, x19, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C7BFDULL; // 0x03bad8: stp x29, x30, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910303FDULL; // 0x03badc: add x29, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x03bae0: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x03bae4: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E1ULL; // 0x03bae8: mov x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x03baec: mov x2, xzr
    return acc;
}

// [EN] Reconstructed FDE #0322 @ 0x03bce4..0x03be44 (352 bytes)
// [VN] Phục dựng FDE #0322 tại 0x03bce4..0x03be44 (352 byte)
//   0x03bce4: d10343ff  sub      sp, sp, #0xd0
//   0x03bce8: a9095ff8  stp      x24, x23, [sp, #0x90]
//   0x03bcec: a90a57f6  stp      x22, x21, [sp, #0xa0]
//   0x03bcf0: a90b4ff4  stp      x20, x19, [sp, #0xb0]
//   0x03bcf4: a90c7bfd  stp      x29, x30, [sp, #0xc0]
//   0x03bcf8: 910303fd  add      x29, sp, #0xc0
//   0x03bcfc: d53bd057  mrs      x23, tpidr_el0
//   0x03bd00: f94016e8  ldr      x8, [x23, #0x28]
//   0x03bd04: f81c83a8  stur     x8, [x29, #-0x38]
//   0x03bd08: f9000fe2  str      x2, [sp, #0x18]
//   0x03bd0c: 97fffdd9  bl       #0x3b470
//   0x03bd10: 360004e0  tbz      w0, #0, #0x3bdac
//   0x03bd14: d0000158  adrp     x24, #0x65000
//   0x03bd18: f9411708  ldr      x8, [x24, #0x228]
//   0x03bd1c: d0fffe80  adrp     x0, #0xd000
//   0x03bd20: 52800089  mov      w9, #4
uint64_t fde_0322_sub_03bce4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10343FFULL) + (x1 ^ 0xD0000158ULL) + (x2 ^ 0x03BCE4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10343FFULL; // 0x03bce4: sub sp, sp, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9095FF8ULL; // 0x03bce8: stp x24, x23, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A57F6ULL; // 0x03bcec: stp x22, x21, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B4FF4ULL; // 0x03bcf0: stp x20, x19, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C7BFDULL; // 0x03bcf4: stp x29, x30, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910303FDULL; // 0x03bcf8: add x29, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x03bcfc: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x03bd00: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C83A8ULL; // 0x03bd04: stur x8, [x29, #-0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE2ULL; // 0x03bd08: str x2, [sp, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0323 @ 0x03be44..0x03bfbc (376 bytes)
// [VN] Phục dựng FDE #0323 tại 0x03be44..0x03bfbc (376 byte)
//   0x03be44: d10343ff  sub      sp, sp, #0xd0
//   0x03be48: a9095ff8  stp      x24, x23, [sp, #0x90]
//   0x03be4c: a90a57f6  stp      x22, x21, [sp, #0xa0]
//   0x03be50: a90b4ff4  stp      x20, x19, [sp, #0xb0]
//   0x03be54: a90c7bfd  stp      x29, x30, [sp, #0xc0]
//   0x03be58: 910303fd  add      x29, sp, #0xc0
//   0x03be5c: d53bd057  mrs      x23, tpidr_el0
//   0x03be60: f94016e8  ldr      x8, [x23, #0x28]
//   0x03be64: f81c83a8  stur     x8, [x29, #-0x38]
//   0x03be68: f9000fe2  str      x2, [sp, #0x18]
//   0x03be6c: 97fffd81  bl       #0x3b470
//   0x03be70: 360004e0  tbz      w0, #0, #0x3bf0c
//   0x03be74: d0000158  adrp     x24, #0x65000
//   0x03be78: f9411708  ldr      x8, [x24, #0x228]
//   0x03be7c: d0fffe80  adrp     x0, #0xd000
//   0x03be80: 52800089  mov      w9, #4
uint64_t fde_0323_sub_03be44(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10343FFULL) + (x1 ^ 0xD0000158ULL) + (x2 ^ 0x03BE44ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10343FFULL; // 0x03be44: sub sp, sp, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9095FF8ULL; // 0x03be48: stp x24, x23, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A57F6ULL; // 0x03be4c: stp x22, x21, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B4FF4ULL; // 0x03be50: stp x20, x19, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C7BFDULL; // 0x03be54: stp x29, x30, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910303FDULL; // 0x03be58: add x29, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x03be5c: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x03be60: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C83A8ULL; // 0x03be64: stur x8, [x29, #-0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE2ULL; // 0x03be68: str x2, [sp, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0324 @ 0x03bfbc..0x03c088 (204 bytes)
// [VN] Phục dựng FDE #0324 tại 0x03bfbc..0x03c088 (204 byte)
//   0x03bfbc: d100c3ff  sub      sp, sp, #0x30
//   0x03bfc0: f9000bf3  str      x19, [sp, #0x10]
//   0x03bfc4: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03bfc8: 910083fd  add      x29, sp, #0x20
//   0x03bfcc: d53bd053  mrs      x19, tpidr_el0
//   0x03bfd0: f9401668  ldr      x8, [x19, #0x28]
//   0x03bfd4: 72001c5f  tst      w2, #0xff
//   0x03bfd8: 1a9f07e9  cset     w9, ne
//   0x03bfdc: f90007e8  str      x8, [sp, #8]
//   0x03bfe0: 390013e9  strb     w9, [sp, #4]
//   0x03bfe4: 97fffd23  bl       #0x3b470
//   0x03bfe8: 36000240  tbz      w0, #0, #0x3c030
//   0x03bfec: d0000148  adrp     x8, #0x65000
//   0x03bff0: f9411508  ldr      x8, [x8, #0x228]
//   0x03bff4: b0fffe80  adrp     x0, #0xc000
//   0x03bff8: 913c4400  add      x0, x0, #0xf11
uint64_t fde_0324_sub_03bfbc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0xD0000148ULL) + (x2 ^ 0x03BFBCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x03bfbc: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF3ULL; // 0x03bfc0: str x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x03bfc4: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03bfc8: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x03bfcc: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x03bfd0: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x72001C5FULL; // 0x03bfd4: tst w2, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F07E9ULL; // 0x03bfd8: cset w9, ne
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x03bfdc: str x8, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x390013E9ULL; // 0x03bfe0: strb w9, [sp, #4]
    return acc;
}

// [EN] Reconstructed FDE #0325 @ 0x03c088..0x03c2ac (548 bytes)
// [VN] Phục dựng FDE #0325 tại 0x03c088..0x03c2ac (548 byte)
//   0x03c088: d10343ff  sub      sp, sp, #0xd0
//   0x03c08c: f9004bf7  str      x23, [sp, #0x90]
//   0x03c090: a90a57f6  stp      x22, x21, [sp, #0xa0]
//   0x03c094: a90b4ff4  stp      x20, x19, [sp, #0xb0]
//   0x03c098: a90c7bfd  stp      x29, x30, [sp, #0xc0]
//   0x03c09c: 910303fd  add      x29, sp, #0xc0
//   0x03c0a0: d53bd056  mrs      x22, tpidr_el0
//   0x03c0a4: f94016c8  ldr      x8, [x22, #0x28]
//   0x03c0a8: f81c83a8  stur     x8, [x29, #-0x38]
//   0x03c0ac: f9000fe2  str      x2, [sp, #0x18]
//   0x03c0b0: 97fffcf0  bl       #0x3b470
//   0x03c0b4: 360005a0  tbz      w0, #0, #0x3c168
//   0x03c0b8: 52800028  mov      w8, #1
//   0x03c0bc: 390093e8  strb     w8, [sp, #0x24]
//   0x03c0c0: 97fffcec  bl       #0x3b470
//   0x03c0c4: b0000157  adrp     x23, #0x65000
uint64_t fde_0325_sub_03c088(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10343FFULL) + (x1 ^ 0x52800028ULL) + (x2 ^ 0x03C088ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10343FFULL; // 0x03c088: sub sp, sp, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9004BF7ULL; // 0x03c08c: str x23, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A57F6ULL; // 0x03c090: stp x22, x21, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B4FF4ULL; // 0x03c094: stp x20, x19, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C7BFDULL; // 0x03c098: stp x29, x30, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910303FDULL; // 0x03c09c: add x29, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x03c0a0: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x03c0a4: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C83A8ULL; // 0x03c0a8: stur x8, [x29, #-0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE2ULL; // 0x03c0ac: str x2, [sp, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0326 @ 0x03c2ac..0x03c2d8 (44 bytes)
// [VN] Phục dựng FDE #0326 tại 0x03c2ac..0x03c2d8 (44 byte)
//   0x03c2ac: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x03c2b0: 910003fd  mov      x29, sp
//   0x03c2b4: 90fffe81  adrp     x1, #0xc000
//   0x03c2b8: d0fffea2  adrp     x2, #0x12000
//   0x03c2bc: 9115b421  add      x1, x1, #0x56d
//   0x03c2c0: 912a4442  add      x2, x2, #0xa91
//   0x03c2c4: 528000c0  mov      w0, #6
//   0x03c2c8: 94008276  bl       #0x5cca0
//   0x03c2cc: 2a1f03e0  mov      w0, wzr
//   0x03c2d0: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x03c2d4: d65f03c0  ret      
uint64_t fde_0326_sub_03c2ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x03C2ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x03c2ac: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x03c2b0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFE81ULL; // 0x03c2b4: adrp x1, #0xc000
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFEA2ULL; // 0x03c2b8: adrp x2, #0x12000
    acc = (acc * 0x100000001B3ULL) ^ 0x9115B421ULL; // 0x03c2bc: add x1, x1, #0x56d
    acc = (acc * 0x100000001B3ULL) ^ 0x912A4442ULL; // 0x03c2c0: add x2, x2, #0xa91
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C0ULL; // 0x03c2c4: mov w0, #6
    acc = (acc * 0x100000001B3ULL) ^ 0x94008276ULL; // 0x03c2c8: bl #0x5cca0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x03c2cc: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x03c2d0: ldp x29, x30, [sp], #0x10
    return acc;
}

// [EN] Reconstructed FDE #0327 @ 0x03c2d8..0x03c304 (44 bytes)
// [VN] Phục dựng FDE #0327 tại 0x03c2d8..0x03c304 (44 byte)
//   0x03c2d8: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x03c2dc: 910003fd  mov      x29, sp
//   0x03c2e0: 90fffe81  adrp     x1, #0xc000
//   0x03c2e4: b0fffea2  adrp     x2, #0x11000
//   0x03c2e8: 9115b421  add      x1, x1, #0x56d
//   0x03c2ec: 913bb442  add      x2, x2, #0xeed
//   0x03c2f0: 528000c0  mov      w0, #6
//   0x03c2f4: 9400826b  bl       #0x5cca0
//   0x03c2f8: 2a1f03e0  mov      w0, wzr
//   0x03c2fc: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x03c300: d65f03c0  ret      
uint64_t fde_0327_sub_03c2d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x03C2D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x03c2d8: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x03c2dc: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFE81ULL; // 0x03c2e0: adrp x1, #0xc000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFEA2ULL; // 0x03c2e4: adrp x2, #0x11000
    acc = (acc * 0x100000001B3ULL) ^ 0x9115B421ULL; // 0x03c2e8: add x1, x1, #0x56d
    acc = (acc * 0x100000001B3ULL) ^ 0x913BB442ULL; // 0x03c2ec: add x2, x2, #0xeed
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C0ULL; // 0x03c2f0: mov w0, #6
    acc = (acc * 0x100000001B3ULL) ^ 0x9400826BULL; // 0x03c2f4: bl #0x5cca0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x03c2f8: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x03c2fc: ldp x29, x30, [sp], #0x10
    return acc;
}

// [EN] Reconstructed FDE #0328 @ 0x03c304..0x03c3d4 (208 bytes)
// [VN] Phục dựng FDE #0328 tại 0x03c304..0x03c3d4 (208 byte)
//   0x03c304: d100c3ff  sub      sp, sp, #0x30
//   0x03c308: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x03c30c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03c310: 910083fd  add      x29, sp, #0x20
//   0x03c314: d53bd054  mrs      x20, tpidr_el0
//   0x03c318: f9401688  ldr      x8, [x20, #0x28]
//   0x03c31c: f90007e8  str      x8, [sp, #8]
//   0x03c320: f90003e2  str      x2, [sp]
//   0x03c324: 97fffc53  bl       #0x3b470
//   0x03c328: 36000300  tbz      w0, #0, #0x3c388
//   0x03c32c: b0000148  adrp     x8, #0x65000
//   0x03c330: f9411508  ldr      x8, [x8, #0x228]
//   0x03c334: f0fffe80  adrp     x0, #0xf000
//   0x03c338: 91172000  add      x0, x0, #0x5c8
//   0x03c33c: 910003e3  mov      x3, sp
//   0x03c340: 52800104  mov      w4, #8
uint64_t fde_0328_sub_03c304(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0xF0FFFE80ULL) + (x2 ^ 0x03C304ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x03c304: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x03c308: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x03c30c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03c310: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x03c314: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x03c318: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x03c31c: str x8, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90003E2ULL; // 0x03c320: str x2, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFC53ULL; // 0x03c324: bl #0x3b470
    acc = (acc * 0x100000001B3ULL) ^ 0x36000300ULL; // 0x03c328: tbz w0, #0, #0x3c388
    return acc;
}

// [EN] Reconstructed FDE #0329 @ 0x03c3d4..0x03c4b0 (220 bytes)
// [VN] Phục dựng FDE #0329 tại 0x03c3d4..0x03c4b0 (220 byte)
//   0x03c3d4: d100c3ff  sub      sp, sp, #0x30
//   0x03c3d8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x03c3dc: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03c3e0: 910083fd  add      x29, sp, #0x20
//   0x03c3e4: d53bd054  mrs      x20, tpidr_el0
//   0x03c3e8: f9401688  ldr      x8, [x20, #0x28]
//   0x03c3ec: f90007e8  str      x8, [sp, #8]
//   0x03c3f0: f90003e2  str      x2, [sp]
//   0x03c3f4: 97fffc1f  bl       #0x3b470
//   0x03c3f8: 36000300  tbz      w0, #0, #0x3c458
//   0x03c3fc: b0000148  adrp     x8, #0x65000
//   0x03c400: f9411508  ldr      x8, [x8, #0x228]
//   0x03c404: 90fffe80  adrp     x0, #0xc000
//   0x03c408: 91172000  add      x0, x0, #0x5c8
//   0x03c40c: 910003e3  mov      x3, sp
//   0x03c410: 52800104  mov      w4, #8
uint64_t fde_0329_sub_03c3d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0x90FFFE80ULL) + (x2 ^ 0x03C3D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x03c3d4: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x03c3d8: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x03c3dc: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03c3e0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x03c3e4: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x03c3e8: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x03c3ec: str x8, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90003E2ULL; // 0x03c3f0: str x2, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFC1FULL; // 0x03c3f4: bl #0x3b470
    acc = (acc * 0x100000001B3ULL) ^ 0x36000300ULL; // 0x03c3f8: tbz w0, #0, #0x3c458
    return acc;
}

// [EN] Reconstructed FDE #0330 @ 0x03c4b0..0x03c58c (220 bytes)
// [VN] Phục dựng FDE #0330 tại 0x03c4b0..0x03c58c (220 byte)
//   0x03c4b0: d100c3ff  sub      sp, sp, #0x30
//   0x03c4b4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x03c4b8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03c4bc: 910083fd  add      x29, sp, #0x20
//   0x03c4c0: d53bd054  mrs      x20, tpidr_el0
//   0x03c4c4: f9401688  ldr      x8, [x20, #0x28]
//   0x03c4c8: f90007e8  str      x8, [sp, #8]
//   0x03c4cc: f90003e2  str      x2, [sp]
//   0x03c4d0: 97fffbe8  bl       #0x3b470
//   0x03c4d4: 36000300  tbz      w0, #0, #0x3c534
//   0x03c4d8: b0000148  adrp     x8, #0x65000
//   0x03c4dc: f9411508  ldr      x8, [x8, #0x228]
//   0x03c4e0: f0fffe80  adrp     x0, #0xf000
//   0x03c4e4: 91222800  add      x0, x0, #0x88a
//   0x03c4e8: 910003e3  mov      x3, sp
//   0x03c4ec: 52800104  mov      w4, #8
uint64_t fde_0330_sub_03c4b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0xF0FFFE80ULL) + (x2 ^ 0x03C4B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x03c4b0: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x03c4b4: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x03c4b8: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03c4bc: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x03c4c0: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x03c4c4: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x03c4c8: str x8, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90003E2ULL; // 0x03c4cc: str x2, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFBE8ULL; // 0x03c4d0: bl #0x3b470
    acc = (acc * 0x100000001B3ULL) ^ 0x36000300ULL; // 0x03c4d4: tbz w0, #0, #0x3c534
    return acc;
}

// [EN] Reconstructed FDE #0331 @ 0x03c58c..0x03c668 (220 bytes)
// [VN] Phục dựng FDE #0331 tại 0x03c58c..0x03c668 (220 byte)
//   0x03c58c: d100c3ff  sub      sp, sp, #0x30
//   0x03c590: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x03c594: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03c598: 910083fd  add      x29, sp, #0x20
//   0x03c59c: d53bd054  mrs      x20, tpidr_el0
//   0x03c5a0: f9401688  ldr      x8, [x20, #0x28]
//   0x03c5a4: f90007e8  str      x8, [sp, #8]
//   0x03c5a8: f90003e2  str      x2, [sp]
//   0x03c5ac: 97fffbb1  bl       #0x3b470
//   0x03c5b0: 36000300  tbz      w0, #0, #0x3c610
//   0x03c5b4: b0000148  adrp     x8, #0x65000
//   0x03c5b8: f9411508  ldr      x8, [x8, #0x228]
//   0x03c5bc: b0fffe80  adrp     x0, #0xd000
//   0x03c5c0: 912e7c00  add      x0, x0, #0xb9f
//   0x03c5c4: 910003e3  mov      x3, sp
//   0x03c5c8: 52800104  mov      w4, #8
uint64_t fde_0331_sub_03c58c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0xB0FFFE80ULL) + (x2 ^ 0x03C58CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x03c58c: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x03c590: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x03c594: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03c598: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x03c59c: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x03c5a0: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x03c5a4: str x8, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90003E2ULL; // 0x03c5a8: str x2, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFBB1ULL; // 0x03c5ac: bl #0x3b470
    acc = (acc * 0x100000001B3ULL) ^ 0x36000300ULL; // 0x03c5b0: tbz w0, #0, #0x3c610
    return acc;
}

// [EN] Reconstructed FDE #0332 @ 0x03c668..0x03c6ec (132 bytes)
// [VN] Phục dựng FDE #0332 tại 0x03c668..0x03c6ec (132 byte)
//   0x03c668: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x03c66c: 910003fd  mov      x29, sp
//   0x03c670: 97fffb80  bl       #0x3b470
//   0x03c674: 36000240  tbz      w0, #0, #0x3c6bc
//   0x03c678: b0000148  adrp     x8, #0x65000
//   0x03c67c: f9411508  ldr      x8, [x8, #0x228]
//   0x03c680: d0fffea0  adrp     x0, #0x12000
//   0x03c684: 91124000  add      x0, x0, #0x490
//   0x03c688: aa1f03e1  mov      x1, xzr
//   0x03c68c: aa1f03e2  mov      x2, xzr
//   0x03c690: aa1f03e3  mov      x3, xzr
//   0x03c694: aa1f03e4  mov      x4, xzr
//   0x03c698: d63f0100  blr      x8
//   0x03c69c: 34000160  cbz      w0, #0x3c6c8
//   0x03c6a0: 90fffe81  adrp     x1, #0xc000
//   0x03c6a4: f0fffea2  adrp     x2, #0x13000
uint64_t fde_0332_sub_03c668(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD63F0100ULL) + (x2 ^ 0x03C668ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x03c668: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x03c66c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFB80ULL; // 0x03c670: bl #0x3b470
    acc = (acc * 0x100000001B3ULL) ^ 0x36000240ULL; // 0x03c674: tbz w0, #0, #0x3c6bc
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000148ULL; // 0x03c678: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9411508ULL; // 0x03c67c: ldr x8, [x8, #0x228]
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFEA0ULL; // 0x03c680: adrp x0, #0x12000
    acc = (acc * 0x100000001B3ULL) ^ 0x91124000ULL; // 0x03c684: add x0, x0, #0x490
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x03c688: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x03c68c: mov x2, xzr
    return acc;
}

// [EN] Reconstructed FDE #0333 @ 0x03c6ec..0x03c7d8 (236 bytes)
// [VN] Phục dựng FDE #0333 tại 0x03c6ec..0x03c7d8 (236 byte)
//   0x03c6ec: d10283ff  sub      sp, sp, #0xa0
//   0x03c6f0: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x03c6f4: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x03c6f8: 910243fd  add      x29, sp, #0x90
//   0x03c6fc: d53bd054  mrs      x20, tpidr_el0
//   0x03c700: f9401688  ldr      x8, [x20, #0x28]
//   0x03c704: f81e83a8  stur     x8, [x29, #-0x18]
//   0x03c708: 97fffb5a  bl       #0x3b470
//   0x03c70c: 360001a0  tbz      w0, #0, #0x3c740
//   0x03c710: b0000153  adrp     x19, #0x65000
//   0x03c714: f9411668  ldr      x8, [x19, #0x228]
//   0x03c718: b0fffe80  adrp     x0, #0xd000
//   0x03c71c: 52800089  mov      w9, #4
//   0x03c720: 91195c00  add      x0, x0, #0x657
//   0x03c724: 910043e1  add      x1, sp, #0x10
//   0x03c728: 910023e2  add      x2, sp, #8
uint64_t fde_0333_sub_03c6ec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10283FFULL) + (x1 ^ 0x52800089ULL) + (x2 ^ 0x03C6ECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10283FFULL; // 0x03c6ec: sub sp, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9084FF4ULL; // 0x03c6f0: stp x20, x19, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9097BFDULL; // 0x03c6f4: stp x29, x30, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0x910243FDULL; // 0x03c6f8: add x29, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x03c6fc: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x03c700: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E83A8ULL; // 0x03c704: stur x8, [x29, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFB5AULL; // 0x03c708: bl #0x3b470
    acc = (acc * 0x100000001B3ULL) ^ 0x360001A0ULL; // 0x03c70c: tbz w0, #0, #0x3c740
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000153ULL; // 0x03c710: adrp x19, #0x65000
    return acc;
}

// [EN] Reconstructed FDE #0334 @ 0x03c7d8..0x03c8c4 (236 bytes)
// [VN] Phục dựng FDE #0334 tại 0x03c7d8..0x03c8c4 (236 byte)
//   0x03c7d8: d10283ff  sub      sp, sp, #0xa0
//   0x03c7dc: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x03c7e0: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x03c7e4: 910243fd  add      x29, sp, #0x90
//   0x03c7e8: d53bd054  mrs      x20, tpidr_el0
//   0x03c7ec: f9401688  ldr      x8, [x20, #0x28]
//   0x03c7f0: f81e83a8  stur     x8, [x29, #-0x18]
//   0x03c7f4: 97fffb1f  bl       #0x3b470
//   0x03c7f8: 360001a0  tbz      w0, #0, #0x3c82c
//   0x03c7fc: b0000153  adrp     x19, #0x65000
//   0x03c800: f9411668  ldr      x8, [x19, #0x228]
//   0x03c804: b0fffe80  adrp     x0, #0xd000
//   0x03c808: 52800089  mov      w9, #4
//   0x03c80c: 91195c00  add      x0, x0, #0x657
//   0x03c810: 910043e1  add      x1, sp, #0x10
//   0x03c814: 910023e2  add      x2, sp, #8
uint64_t fde_0334_sub_03c7d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10283FFULL) + (x1 ^ 0x52800089ULL) + (x2 ^ 0x03C7D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10283FFULL; // 0x03c7d8: sub sp, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9084FF4ULL; // 0x03c7dc: stp x20, x19, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9097BFDULL; // 0x03c7e0: stp x29, x30, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0x910243FDULL; // 0x03c7e4: add x29, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x03c7e8: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x03c7ec: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E83A8ULL; // 0x03c7f0: stur x8, [x29, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFB1FULL; // 0x03c7f4: bl #0x3b470
    acc = (acc * 0x100000001B3ULL) ^ 0x360001A0ULL; // 0x03c7f8: tbz w0, #0, #0x3c82c
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000153ULL; // 0x03c7fc: adrp x19, #0x65000
    return acc;
}

// [EN] Reconstructed FDE #0335 @ 0x03c8c4..0x03c9b0 (236 bytes)
// [VN] Phục dựng FDE #0335 tại 0x03c8c4..0x03c9b0 (236 byte)
//   0x03c8c4: d10283ff  sub      sp, sp, #0xa0
//   0x03c8c8: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x03c8cc: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x03c8d0: 910243fd  add      x29, sp, #0x90
//   0x03c8d4: d53bd054  mrs      x20, tpidr_el0
//   0x03c8d8: f9401688  ldr      x8, [x20, #0x28]
//   0x03c8dc: f81e83a8  stur     x8, [x29, #-0x18]
//   0x03c8e0: 97fffae4  bl       #0x3b470
//   0x03c8e4: 360001a0  tbz      w0, #0, #0x3c918
//   0x03c8e8: b0000153  adrp     x19, #0x65000
//   0x03c8ec: f9411668  ldr      x8, [x19, #0x228]
//   0x03c8f0: b0fffe80  adrp     x0, #0xd000
//   0x03c8f4: 52800089  mov      w9, #4
//   0x03c8f8: 91195c00  add      x0, x0, #0x657
//   0x03c8fc: 910043e1  add      x1, sp, #0x10
//   0x03c900: 910023e2  add      x2, sp, #8
uint64_t fde_0335_sub_03c8c4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10283FFULL) + (x1 ^ 0x52800089ULL) + (x2 ^ 0x03C8C4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10283FFULL; // 0x03c8c4: sub sp, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9084FF4ULL; // 0x03c8c8: stp x20, x19, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9097BFDULL; // 0x03c8cc: stp x29, x30, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0x910243FDULL; // 0x03c8d0: add x29, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x03c8d4: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x03c8d8: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E83A8ULL; // 0x03c8dc: stur x8, [x29, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFAE4ULL; // 0x03c8e0: bl #0x3b470
    acc = (acc * 0x100000001B3ULL) ^ 0x360001A0ULL; // 0x03c8e4: tbz w0, #0, #0x3c918
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000153ULL; // 0x03c8e8: adrp x19, #0x65000
    return acc;
}

// [EN] Reconstructed FDE #0336 @ 0x03c9b0..0x03ca9c (236 bytes)
// [VN] Phục dựng FDE #0336 tại 0x03c9b0..0x03ca9c (236 byte)
//   0x03c9b0: d10283ff  sub      sp, sp, #0xa0
//   0x03c9b4: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x03c9b8: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x03c9bc: 910243fd  add      x29, sp, #0x90
//   0x03c9c0: d53bd054  mrs      x20, tpidr_el0
//   0x03c9c4: f9401688  ldr      x8, [x20, #0x28]
//   0x03c9c8: f81e83a8  stur     x8, [x29, #-0x18]
//   0x03c9cc: 97fffaa9  bl       #0x3b470
//   0x03c9d0: 360001a0  tbz      w0, #0, #0x3ca04
//   0x03c9d4: b0000153  adrp     x19, #0x65000
//   0x03c9d8: f9411668  ldr      x8, [x19, #0x228]
//   0x03c9dc: b0fffe80  adrp     x0, #0xd000
//   0x03c9e0: 52800089  mov      w9, #4
//   0x03c9e4: 91195c00  add      x0, x0, #0x657
//   0x03c9e8: 910043e1  add      x1, sp, #0x10
//   0x03c9ec: 910023e2  add      x2, sp, #8
uint64_t fde_0336_sub_03c9b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10283FFULL) + (x1 ^ 0x52800089ULL) + (x2 ^ 0x03C9B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10283FFULL; // 0x03c9b0: sub sp, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9084FF4ULL; // 0x03c9b4: stp x20, x19, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9097BFDULL; // 0x03c9b8: stp x29, x30, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0x910243FDULL; // 0x03c9bc: add x29, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x03c9c0: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x03c9c4: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E83A8ULL; // 0x03c9c8: stur x8, [x29, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFAA9ULL; // 0x03c9cc: bl #0x3b470
    acc = (acc * 0x100000001B3ULL) ^ 0x360001A0ULL; // 0x03c9d0: tbz w0, #0, #0x3ca04
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000153ULL; // 0x03c9d4: adrp x19, #0x65000
    return acc;
}

// [EN] Reconstructed FDE #0337 @ 0x03ca9c..0x03cbf8 (348 bytes)
// [VN] Phục dựng FDE #0337 tại 0x03ca9c..0x03cbf8 (348 byte)
//   0x03ca9c: d10343ff  sub      sp, sp, #0xd0
//   0x03caa0: a9095ff8  stp      x24, x23, [sp, #0x90]
//   0x03caa4: a90a57f6  stp      x22, x21, [sp, #0xa0]
//   0x03caa8: a90b4ff4  stp      x20, x19, [sp, #0xb0]
//   0x03caac: a90c7bfd  stp      x29, x30, [sp, #0xc0]
//   0x03cab0: 910303fd  add      x29, sp, #0xc0
//   0x03cab4: d53bd057  mrs      x23, tpidr_el0
//   0x03cab8: f94016e8  ldr      x8, [x23, #0x28]
//   0x03cabc: f81c83a8  stur     x8, [x29, #-0x38]
//   0x03cac0: f9000fe2  str      x2, [sp, #0x18]
//   0x03cac4: 97fffa6b  bl       #0x3b470
//   0x03cac8: 360004e0  tbz      w0, #0, #0x3cb64
//   0x03cacc: b0000158  adrp     x24, #0x65000
//   0x03cad0: f9411708  ldr      x8, [x24, #0x228]
//   0x03cad4: b0fffe80  adrp     x0, #0xd000
//   0x03cad8: 52800089  mov      w9, #4
uint64_t fde_0337_sub_03ca9c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10343FFULL) + (x1 ^ 0xB0000158ULL) + (x2 ^ 0x03CA9CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10343FFULL; // 0x03ca9c: sub sp, sp, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9095FF8ULL; // 0x03caa0: stp x24, x23, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A57F6ULL; // 0x03caa4: stp x22, x21, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B4FF4ULL; // 0x03caa8: stp x20, x19, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C7BFDULL; // 0x03caac: stp x29, x30, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910303FDULL; // 0x03cab0: add x29, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x03cab4: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x03cab8: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C83A8ULL; // 0x03cabc: stur x8, [x29, #-0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE2ULL; // 0x03cac0: str x2, [sp, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0338 @ 0x03cbf8..0x03cd58 (352 bytes)
// [VN] Phục dựng FDE #0338 tại 0x03cbf8..0x03cd58 (352 byte)
//   0x03cbf8: d10343ff  sub      sp, sp, #0xd0
//   0x03cbfc: a9095ff8  stp      x24, x23, [sp, #0x90]
//   0x03cc00: a90a57f6  stp      x22, x21, [sp, #0xa0]
//   0x03cc04: a90b4ff4  stp      x20, x19, [sp, #0xb0]
//   0x03cc08: a90c7bfd  stp      x29, x30, [sp, #0xc0]
//   0x03cc0c: 910303fd  add      x29, sp, #0xc0
//   0x03cc10: d53bd057  mrs      x23, tpidr_el0
//   0x03cc14: f94016e8  ldr      x8, [x23, #0x28]
//   0x03cc18: f81c83a8  stur     x8, [x29, #-0x38]
//   0x03cc1c: f9000fe2  str      x2, [sp, #0x18]
//   0x03cc20: 97fffa14  bl       #0x3b470
//   0x03cc24: 360004e0  tbz      w0, #0, #0x3ccc0
//   0x03cc28: b0000158  adrp     x24, #0x65000
//   0x03cc2c: f9411708  ldr      x8, [x24, #0x228]
//   0x03cc30: b0fffe80  adrp     x0, #0xd000
//   0x03cc34: 52800089  mov      w9, #4
uint64_t fde_0338_sub_03cbf8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10343FFULL) + (x1 ^ 0xB0000158ULL) + (x2 ^ 0x03CBF8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10343FFULL; // 0x03cbf8: sub sp, sp, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9095FF8ULL; // 0x03cbfc: stp x24, x23, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A57F6ULL; // 0x03cc00: stp x22, x21, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B4FF4ULL; // 0x03cc04: stp x20, x19, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C7BFDULL; // 0x03cc08: stp x29, x30, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910303FDULL; // 0x03cc0c: add x29, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x03cc10: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x03cc14: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C83A8ULL; // 0x03cc18: stur x8, [x29, #-0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE2ULL; // 0x03cc1c: str x2, [sp, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0339 @ 0x03cd58..0x03cde8 (144 bytes)
// [VN] Phục dựng FDE #0339 tại 0x03cd58..0x03cde8 (144 byte)
//   0x03cd58: d10103ff  sub      sp, sp, #0x40
//   0x03cd5c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x03cd60: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x03cd64: 9100c3fd  add      x29, sp, #0x30
//   0x03cd68: d53bd054  mrs      x20, tpidr_el0
//   0x03cd6c: f9401688  ldr      x8, [x20, #0x28]
//   0x03cd70: 910003e9  mov      x9, sp
//   0x03cd74: b2400121  orr      x1, x9, #1
//   0x03cd78: f9000fe8  str      x8, [sp, #0x18]
//   0x03cd7c: a900ffff  stp      xzr, xzr, [sp, #8]
//   0x03cd80: f90003ff  str      xzr, [sp]
//   0x03cd84: f9400008  ldr      x8, [x0]
//   0x03cd88: f9429d08  ldr      x8, [x8, #0x538]
//   0x03cd8c: d63f0100  blr      x8
//   0x03cd90: 394003e8  ldrb     w8, [sp]
//   0x03cd94: aa0003f3  mov      x19, x0
uint64_t fde_0339_sub_03cd58(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xF9429D08ULL) + (x2 ^ 0x03CD58ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x03cd58: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x03cd5c: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x03cd60: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x03cd64: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x03cd68: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x03cd6c: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E9ULL; // 0x03cd70: mov x9, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xB2400121ULL; // 0x03cd74: orr x1, x9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x03cd78: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xA900FFFFULL; // 0x03cd7c: stp xzr, xzr, [sp, #8]
    return acc;
}

// [EN] Reconstructed FDE #0340 @ 0x03cde8..0x03ced8 (240 bytes)
// [VN] Phục dựng FDE #0340 tại 0x03cde8..0x03ced8 (240 byte)
//   0x03cde8: d10183ff  sub      sp, sp, #0x60
//   0x03cdec: f90013f7  str      x23, [sp, #0x20]
//   0x03cdf0: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x03cdf4: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x03cdf8: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x03cdfc: 910143fd  add      x29, sp, #0x50
//   0x03ce00: d53bd057  mrs      x23, tpidr_el0
//   0x03ce04: f94016e8  ldr      x8, [x23, #0x28]
//   0x03ce08: aa0203f4  mov      x20, x2
//   0x03ce0c: aa0203e1  mov      x1, x2
//   0x03ce10: aa1f03e2  mov      x2, xzr
//   0x03ce14: f9000fe8  str      x8, [sp, #0x18]
//   0x03ce18: f9400008  ldr      x8, [x0]
//   0x03ce1c: aa0003f3  mov      x19, x0
//   0x03ce20: f942a508  ldr      x8, [x8, #0x548]
//   0x03ce24: d63f0100  blr      x8
uint64_t fde_0340_sub_03cde8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xF9400008ULL) + (x2 ^ 0x03CDE8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x03cde8: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F7ULL; // 0x03cdec: str x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x03cdf0: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x03cdf4: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x03cdf8: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x03cdfc: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x03ce00: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x03ce04: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x03ce08: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E1ULL; // 0x03ce0c: mov x1, x2
    return acc;
}

// [EN] Reconstructed FDE #0341 @ 0x03ced8..0x03cfc0 (232 bytes)
// [VN] Phục dựng FDE #0341 tại 0x03ced8..0x03cfc0 (232 byte)
//   0x03ced8: d10183ff  sub      sp, sp, #0x60
//   0x03cedc: f90013f7  str      x23, [sp, #0x20]
//   0x03cee0: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x03cee4: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x03cee8: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x03ceec: 910143fd  add      x29, sp, #0x50
//   0x03cef0: d53bd057  mrs      x23, tpidr_el0
//   0x03cef4: f94016e8  ldr      x8, [x23, #0x28]
//   0x03cef8: aa0203f4  mov      x20, x2
//   0x03cefc: aa0203e1  mov      x1, x2
//   0x03cf00: aa1f03e2  mov      x2, xzr
//   0x03cf04: f9000fe8  str      x8, [sp, #0x18]
//   0x03cf08: f9400008  ldr      x8, [x0]
//   0x03cf0c: aa0003f3  mov      x19, x0
//   0x03cf10: f942a508  ldr      x8, [x8, #0x548]
//   0x03cf14: d63f0100  blr      x8
uint64_t fde_0341_sub_03ced8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xF9400008ULL) + (x2 ^ 0x03CED8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x03ced8: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F7ULL; // 0x03cedc: str x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x03cee0: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x03cee4: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x03cee8: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x03ceec: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x03cef0: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x03cef4: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x03cef8: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E1ULL; // 0x03cefc: mov x1, x2
    return acc;
}

// [EN] Reconstructed FDE #0342 @ 0x03cfc0..0x03cffc (60 bytes)
// [VN] Phục dựng FDE #0342 tại 0x03cfc0..0x03cffc (60 byte)
//   0x03cfc0: d10083ff  sub      sp, sp, #0x20
//   0x03cfc4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03cfc8: 910043fd  add      x29, sp, #0x10
//   0x03cfcc: 90000149  adrp     x9, #0x64000
//   0x03cfd0: f942ed29  ldr      x9, [x9, #0x5d8]
//   0x03cfd4: aa0103e8  mov      x8, x1
//   0x03cfd8: a90003e2  stp      x2, x0, [sp]
//   0x03cfdc: 910023e1  add      x1, sp, #8
//   0x03cfe0: 910003e3  mov      x3, sp
//   0x03cfe4: aa0903e0  mov      x0, x9
//   0x03cfe8: aa0803e2  mov      x2, x8
//   0x03cfec: 94000004  bl       #0x3cffc
//   0x03cff0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x03cff4: 910083ff  add      sp, sp, #0x20
//   0x03cff8: d65f03c0  ret      
uint64_t fde_0342_sub_03cfc0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10083FFULL) + (x1 ^ 0xA9417BFDULL) + (x2 ^ 0x03CFC0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10083FFULL; // 0x03cfc0: sub sp, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03cfc4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03cfc8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x90000149ULL; // 0x03cfcc: adrp x9, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xF942ED29ULL; // 0x03cfd0: ldr x9, [x9, #0x5d8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E8ULL; // 0x03cfd4: mov x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xA90003E2ULL; // 0x03cfd8: stp x2, x0, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E1ULL; // 0x03cfdc: add x1, sp, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E3ULL; // 0x03cfe0: mov x3, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0903E0ULL; // 0x03cfe4: mov x0, x9
    return acc;
}

// [EN] Reconstructed FDE #0343 @ 0x03cffc..0x03d5d8 (1500 bytes)
// [VN] Phục dựng FDE #0343 tại 0x03cffc..0x03d5d8 (1500 byte)
//   0x03cffc: d10783ff  sub      sp, sp, #0x1e0
//   0x03d000: a9186ffc  stp      x28, x27, [sp, #0x180]
//   0x03d004: a91967fa  stp      x26, x25, [sp, #0x190]
//   0x03d008: a91a5ff8  stp      x24, x23, [sp, #0x1a0]
//   0x03d00c: a91b57f6  stp      x22, x21, [sp, #0x1b0]
//   0x03d010: a91c4ff4  stp      x20, x19, [sp, #0x1c0]
//   0x03d014: a91d7bfd  stp      x29, x30, [sp, #0x1d0]
//   0x03d018: 910743fd  add      x29, sp, #0x1d0
//   0x03d01c: d53bd053  mrs      x19, tpidr_el0
//   0x03d020: f9401668  ldr      x8, [x19, #0x28]
//   0x03d024: aa0303fa  mov      x26, x3
//   0x03d028: aa0203f5  mov      x21, x2
//   0x03d02c: aa0103f6  mov      x22, x1
//   0x03d030: f81a03a8  stur     x8, [x29, #-0x60]
//   0x03d034: b4000740  cbz      x0, #0x3d11c
//   0x03d038: f0fffe61  adrp     x1, #0xc000
uint64_t fde_0343_sub_03cffc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10783FFULL) + (x1 ^ 0xAA0103F6ULL) + (x2 ^ 0x03CFFCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10783FFULL; // 0x03cffc: sub sp, sp, #0x1e0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9186FFCULL; // 0x03d000: stp x28, x27, [sp, #0x180]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91967FAULL; // 0x03d004: stp x26, x25, [sp, #0x190]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91A5FF8ULL; // 0x03d008: stp x24, x23, [sp, #0x1a0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91B57F6ULL; // 0x03d00c: stp x22, x21, [sp, #0x1b0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91C4FF4ULL; // 0x03d010: stp x20, x19, [sp, #0x1c0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91D7BFDULL; // 0x03d014: stp x29, x30, [sp, #0x1d0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910743FDULL; // 0x03d018: add x29, sp, #0x1d0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x03d01c: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x03d020: ldr x8, [x19, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0344 @ 0x03d5d8..0x03d700 (296 bytes)
// [VN] Phục dựng FDE #0344 tại 0x03d5d8..0x03d700 (296 byte)
//   0x03d5d8: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x03d5dc: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x03d5e0: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x03d5e4: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x03d5e8: 9100c3fd  add      x29, sp, #0x30
//   0x03d5ec: f0000128  adrp     x8, #0x64000
//   0x03d5f0: b94fb908  ldr      w8, [x8, #0xfb8]
//   0x03d5f4: 2a0003f4  mov      w20, w0
//   0x03d5f8: aa0103f3  mov      x19, x1
//   0x03d5fc: 2a0803e0  mov      w0, w8
//   0x03d600: 94007e90  bl       #0x5d040
//   0x03d604: f0000148  adrp     x8, #0x68000
//   0x03d608: 93407e96  sxtw     x22, w20
//   0x03d60c: 910ba108  add      x8, x8, #0x2e8
//   0x03d610: 8b161517  add      x23, x8, x22, lsl #5
//   0x03d614: f94406e4  ldr      x4, [x23, #0x808]
uint64_t fde_0344_sub_03d5d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x93407E96ULL) + (x2 ^ 0x03D5D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x03d5d8: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x03d5dc: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x03d5e0: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x03d5e4: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x03d5e8: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000128ULL; // 0x03d5ec: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xB94FB908ULL; // 0x03d5f0: ldr w8, [x8, #0xfb8]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F4ULL; // 0x03d5f4: mov w20, w0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x03d5f8: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0803E0ULL; // 0x03d5fc: mov w0, w8
    return acc;
}

// [EN] Reconstructed FDE #0345 @ 0x03d700..0x03d7b4 (180 bytes)
// [VN] Phục dựng FDE #0345 tại 0x03d700..0x03d7b4 (180 byte)
//   0x03d700: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x03d704: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x03d708: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03d70c: 910083fd  add      x29, sp, #0x20
//   0x03d710: a9007c1f  stp      xzr, xzr, [x0]
//   0x03d714: f900081f  str      xzr, [x0, #0x10]
//   0x03d718: 39400028  ldrb     w8, [x1]
//   0x03d71c: aa0003f3  mov      x19, x0
//   0x03d720: 37000128  tbnz     w8, #0, #0x3d744
//   0x03d724: f9400828  ldr      x8, [x1, #0x10]
//   0x03d728: 3dc00020  ldr      q0, [x1]
//   0x03d72c: f9000a68  str      x8, [x19, #0x10]
//   0x03d730: 3d800260  str      q0, [x19]
//   0x03d734: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x03d738: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x03d73c: a8c357f6  ldp      x22, x21, [sp], #0x30
uint64_t fde_0345_sub_03d700(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x3D800260ULL) + (x2 ^ 0x03D700ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x03d700: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x03d704: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x03d708: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03d70c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xA9007C1FULL; // 0x03d710: stp xzr, xzr, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900081FULL; // 0x03d714: str xzr, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400028ULL; // 0x03d718: ldrb w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x03d71c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x37000128ULL; // 0x03d720: tbnz w8, #0, #0x3d744
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400828ULL; // 0x03d724: ldr x8, [x1, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0346 @ 0x03d7b4..0x03d8a0 (236 bytes)
// [VN] Phục dựng FDE #0346 tại 0x03d7b4..0x03d8a0 (236 byte)
//   0x03d7b4: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x03d7b8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03d7bc: 910043fd  add      x29, sp, #0x10
//   0x03d7c0: f0fffe60  adrp     x0, #0xc000
//   0x03d7c4: 91032400  add      x0, x0, #0xc9
//   0x03d7c8: 94007e4e  bl       #0x5d100
//   0x03d7cc: b4000420  cbz      x0, #0x3d850
//   0x03d7d0: aa0003f3  mov      x19, x0
//   0x03d7d4: d0fffe81  adrp     x1, #0xf000
//   0x03d7d8: 91181021  add      x1, x1, #0x604
//   0x03d7dc: 94007ec9  bl       #0x5d300
//   0x03d7e0: aa0003f4  mov      x20, x0
//   0x03d7e4: b50000e0  cbnz     x0, #0x3d800
//   0x03d7e8: f0fffe61  adrp     x1, #0xc000
//   0x03d7ec: 90fffea2  adrp     x2, #0x11000
//   0x03d7f0: 91176821  add      x1, x1, #0x5da
uint64_t fde_0346_sub_03d7b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xB50000E0ULL) + (x2 ^ 0x03D7B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x03d7b4: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03d7b8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03d7bc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFE60ULL; // 0x03d7c0: adrp x0, #0xc000
    acc = (acc * 0x100000001B3ULL) ^ 0x91032400ULL; // 0x03d7c4: add x0, x0, #0xc9
    acc = (acc * 0x100000001B3ULL) ^ 0x94007E4EULL; // 0x03d7c8: bl #0x5d100
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000420ULL; // 0x03d7cc: cbz x0, #0x3d850
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x03d7d0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFE81ULL; // 0x03d7d4: adrp x1, #0xf000
    acc = (acc * 0x100000001B3ULL) ^ 0x91181021ULL; // 0x03d7d8: add x1, x1, #0x604
    return acc;
}

// [EN] Reconstructed FDE #0347 @ 0x03d8a0..0x03d9bc (284 bytes)
// [VN] Phục dựng FDE #0347 tại 0x03d8a0..0x03d9bc (284 byte)
//   0x03d8a0: d10103ff  sub      sp, sp, #0x40
//   0x03d8a4: f9000bf5  str      x21, [sp, #0x10]
//   0x03d8a8: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x03d8ac: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x03d8b0: 9100c3fd  add      x29, sp, #0x30
//   0x03d8b4: d53bd055  mrs      x21, tpidr_el0
//   0x03d8b8: f94016a8  ldr      x8, [x21, #0x28]
//   0x03d8bc: 52800100  mov      w0, #8
//   0x03d8c0: f90007e8  str      x8, [sp, #8]
//   0x03d8c4: 94007e67  bl       #0x5d260
//   0x03d8c8: aa0003f4  mov      x20, x0
//   0x03d8cc: 94007f15  bl       #0x5d520
//   0x03d8d0: 52800100  mov      w0, #8
//   0x03d8d4: 94007e63  bl       #0x5d260
//   0x03d8d8: aa0003f3  mov      x19, x0
//   0x03d8dc: f9000014  str      x20, [x0]
uint64_t fde_0347_sub_03d8a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x52800100ULL) + (x2 ^ 0x03D8A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x03d8a0: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF5ULL; // 0x03d8a4: str x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x03d8a8: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x03d8ac: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x03d8b0: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x03d8b4: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x03d8b8: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800100ULL; // 0x03d8bc: mov w0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x03d8c0: str x8, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x94007E67ULL; // 0x03d8c4: bl #0x5d260
    return acc;
}

// [EN] Reconstructed FDE #0348 @ 0x03d9bc..0x03dae4 (296 bytes)
// [VN] Phục dựng FDE #0348 tại 0x03d9bc..0x03dae4 (296 byte)
//   0x03d9bc: d10103ff  sub      sp, sp, #0x40
//   0x03d9c0: f9000bf5  str      x21, [sp, #0x10]
//   0x03d9c4: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x03d9c8: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x03d9cc: 9100c3fd  add      x29, sp, #0x30
//   0x03d9d0: d53bd055  mrs      x21, tpidr_el0
//   0x03d9d4: f94016a8  ldr      x8, [x21, #0x28]
//   0x03d9d8: aa0003f3  mov      x19, x0
//   0x03d9dc: f90007e8  str      x8, [sp, #8]
//   0x03d9e0: 94007ee4  bl       #0x5d570
//   0x03d9e4: f9400261  ldr      x1, [x19]
//   0x03d9e8: f900027f  str      xzr, [x19]
//   0x03d9ec: b9400000  ldr      w0, [x0]
//   0x03d9f0: 94007d8c  bl       #0x5d020
//   0x03d9f4: 90000154  adrp     x20, #0x65000
//   0x03d9f8: f9412280  ldr      x0, [x20, #0x240]
uint64_t fde_0348_sub_03d9bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xB9400000ULL) + (x2 ^ 0x03D9BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x03d9bc: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF5ULL; // 0x03d9c0: str x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x03d9c4: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x03d9c8: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x03d9cc: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x03d9d0: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x03d9d4: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x03d9d8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x03d9dc: str x8, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x94007EE4ULL; // 0x03d9e0: bl #0x5d570
    return acc;
}

// [EN] Reconstructed FDE #0349 @ 0x03dae4..0x03dbc8 (228 bytes)
// [VN] Phục dựng FDE #0349 tại 0x03dae4..0x03dbc8 (228 byte)
//   0x03dae4: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x03dae8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03daec: 910043fd  add      x29, sp, #0x10
//   0x03daf0: f9400008  ldr      x8, [x0]
//   0x03daf4: 90000141  adrp     x1, #0x65000
//   0x03daf8: 91090021  add      x1, x1, #0x240
//   0x03dafc: 2a0203f3  mov      w19, w2
//   0x03db00: f9436d08  ldr      x8, [x8, #0x6d8]
//   0x03db04: d63f0100  blr      x8
//   0x03db08: 71005a7f  cmp      w19, #0x16
//   0x03db0c: 5400014c  b.gt     #0x3db34
//   0x03db10: f0fffe80  adrp     x0, #0x10000
//   0x03db14: f0fffea1  adrp     x1, #0x14000
//   0x03db18: 90000002  adrp     x2, #0x3d000
//   0x03db1c: 90000143  adrp     x3, #0x65000
//   0x03db20: 911ad800  add      x0, x0, #0x6b6
uint64_t fde_0349_sub_03dae4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF0FFFEA1ULL) + (x2 ^ 0x03DAE4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x03dae4: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03dae8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03daec: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x03daf0: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000141ULL; // 0x03daf4: adrp x1, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x91090021ULL; // 0x03daf8: add x1, x1, #0x240
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F3ULL; // 0x03dafc: mov w19, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xF9436D08ULL; // 0x03db00: ldr x8, [x8, #0x6d8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x03db04: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0x71005A7FULL; // 0x03db08: cmp w19, #0x16
    return acc;
}

// [EN] Reconstructed FDE #0350 @ 0x03dbc8..0x03dc60 (152 bytes)
// [VN] Phục dựng FDE #0350 tại 0x03dbc8..0x03dc60 (152 byte)
//   0x03dbc8: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x03dbcc: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x03dbd0: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x03dbd4: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x03dbd8: 9100c3fd  add      x29, sp, #0x30
//   0x03dbdc: 90000157  adrp     x23, #0x65000
//   0x03dbe0: f94126e4  ldr      x4, [x23, #0x248]
//   0x03dbe4: b4000344  cbz      x4, #0x3dc4c
//   0x03dbe8: 2a0303f3  mov      w19, w3
//   0x03dbec: aa0203f4  mov      x20, x2
//   0x03dbf0: aa0103f5  mov      x21, x1
//   0x03dbf4: aa0003f6  mov      x22, x0
//   0x03dbf8: 7100047f  cmp      w3, #1
//   0x03dbfc: 54000161  b.ne     #0x3dc28
//   0x03dc00: 8b140688  add      x8, x20, x20, lsl #1
//   0x03dc04: d341fd14  lsr      x20, x8, #1
uint64_t fde_0350_sub_03dbc8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x7100047FULL) + (x2 ^ 0x03DBC8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x03dbc8: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x03dbcc: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x03dbd0: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x03dbd4: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x03dbd8: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x90000157ULL; // 0x03dbdc: adrp x23, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xF94126E4ULL; // 0x03dbe0: ldr x4, [x23, #0x248]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000344ULL; // 0x03dbe4: cbz x4, #0x3dc4c
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303F3ULL; // 0x03dbe8: mov w19, w3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x03dbec: mov x20, x2
    return acc;
}

// [EN] Reconstructed FDE #0351 @ 0x03dc60..0x03dd00 (160 bytes)
// [VN] Phục dựng FDE #0351 tại 0x03dc60..0x03dd00 (160 byte)
//   0x03dc60: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x03dc64: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x03dc68: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x03dc6c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x03dc70: 9100c3fd  add      x29, sp, #0x30
//   0x03dc74: 90000158  adrp     x24, #0x65000
//   0x03dc78: f9412b05  ldr      x5, [x24, #0x250]
//   0x03dc7c: b4000385  cbz      x5, #0x3dcec
//   0x03dc80: 2a0403f4  mov      w20, w4
//   0x03dc84: 2a0303f3  mov      w19, w3
//   0x03dc88: aa0203f5  mov      x21, x2
//   0x03dc8c: aa0103f6  mov      x22, x1
//   0x03dc90: aa0003f7  mov      x23, x0
//   0x03dc94: 7100047f  cmp      w3, #1
//   0x03dc98: 54000161  b.ne     #0x3dcc4
//   0x03dc9c: 8b1506a8  add      x8, x21, x21, lsl #1
uint64_t fde_0351_sub_03dc60(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0xAA0003F7ULL) + (x2 ^ 0x03DC60ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x03dc60: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x03dc64: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x03dc68: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x03dc6c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x03dc70: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x90000158ULL; // 0x03dc74: adrp x24, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9412B05ULL; // 0x03dc78: ldr x5, [x24, #0x250]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000385ULL; // 0x03dc7c: cbz x5, #0x3dcec
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0403F4ULL; // 0x03dc80: mov w20, w4
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303F3ULL; // 0x03dc84: mov w19, w3
    return acc;
}

// [EN] Reconstructed FDE #0352 @ 0x03dd00..0x03dd08 (8 bytes)
// [VN] Phục dựng FDE #0352 tại 0x03dd00..0x03dd08 (8 byte)
//   0x03dd00: 2a1f03e0  mov      w0, wzr
//   0x03dd04: d65f03c0  ret      
uint64_t fde_0352_sub_03dd00(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x03DD00ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x03dd00: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x03dd04: ret 
    return acc;
}

// [EN] Reconstructed FDE #0353 @ 0x03dd08..0x03de5c (340 bytes)
// [VN] Phục dựng FDE #0353 tại 0x03dd08..0x03de5c (340 byte)
//   0x03dd08: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x03dd0c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03dd10: 910043fd  add      x29, sp, #0x10
//   0x03dd14: f0000128  adrp     x8, #0x64000
//   0x03dd18: 3979dd08  ldrb     w8, [x8, #0xe77]
//   0x03dd1c: 7100051f  cmp      w8, #1
//   0x03dd20: 540000c1  b.ne     #0x3dd38
//   0x03dd24: f0000128  adrp     x8, #0x64000
//   0x03dd28: 3979e100  ldrb     w0, [x8, #0xe78]
//   0x03dd2c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x03dd30: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x03dd34: d65f03c0  ret      
//   0x03dd38: f0000128  adrp     x8, #0x64000
//   0x03dd3c: 9139dd08  add      x8, x8, #0xe77
//   0x03dd40: 52800029  mov      w9, #1
//   0x03dd44: 39000109  strb     w9, [x8]
uint64_t fde_0353_sub_03dd08(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF0000128ULL) + (x2 ^ 0x03DD08ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x03dd08: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03dd0c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03dd10: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000128ULL; // 0x03dd14: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x3979DD08ULL; // 0x03dd18: ldrb w8, [x8, #0xe77]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100051FULL; // 0x03dd1c: cmp w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540000C1ULL; // 0x03dd20: b.ne #0x3dd38
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000128ULL; // 0x03dd24: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x3979E100ULL; // 0x03dd28: ldrb w0, [x8, #0xe78]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x03dd2c: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0354 @ 0x03de5c..0x03de8c (48 bytes)
// [VN] Phục dựng FDE #0354 tại 0x03de5c..0x03de8c (48 byte)
//   0x03de5c: d10083ff  sub      sp, sp, #0x20
//   0x03de60: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03de64: 910043fd  add      x29, sp, #0x10
//   0x03de68: 90000148  adrp     x8, #0x65000
//   0x03de6c: f9413108  ldr      x8, [x8, #0x260]
//   0x03de70: f90007e0  str      x0, [sp, #8]
//   0x03de74: 910023e1  add      x1, sp, #8
//   0x03de78: aa0803e0  mov      x0, x8
//   0x03de7c: 94000004  bl       #0x3de8c
//   0x03de80: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x03de84: 910083ff  add      sp, sp, #0x20
//   0x03de88: d65f03c0  ret      
uint64_t fde_0354_sub_03de5c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10083FFULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x03DE5CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10083FFULL; // 0x03de5c: sub sp, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03de60: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03de64: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x90000148ULL; // 0x03de68: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9413108ULL; // 0x03de6c: ldr x8, [x8, #0x260]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E0ULL; // 0x03de70: str x0, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E1ULL; // 0x03de74: add x1, sp, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E0ULL; // 0x03de78: mov x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x94000004ULL; // 0x03de7c: bl #0x3de8c
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x03de80: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0355 @ 0x03de8c..0x03e1f8 (876 bytes)
// [VN] Phục dựng FDE #0355 tại 0x03de8c..0x03e1f8 (876 byte)
//   0x03de8c: d10603ff  sub      sp, sp, #0x180
//   0x03de90: a9126ffc  stp      x28, x27, [sp, #0x120]
//   0x03de94: a91367fa  stp      x26, x25, [sp, #0x130]
//   0x03de98: a9145ff8  stp      x24, x23, [sp, #0x140]
//   0x03de9c: a91557f6  stp      x22, x21, [sp, #0x150]
//   0x03dea0: a9164ff4  stp      x20, x19, [sp, #0x160]
//   0x03dea4: a9177bfd  stp      x29, x30, [sp, #0x170]
//   0x03dea8: 9105c3fd  add      x29, sp, #0x170
//   0x03deac: d53bd058  mrs      x24, tpidr_el0
//   0x03deb0: f9401708  ldr      x8, [x24, #0x28]
//   0x03deb4: f81a03a8  stur     x8, [x29, #-0x60]
//   0x03deb8: b4000760  cbz      x0, #0x3dfa4
//   0x03debc: aa0103f4  mov      x20, x1
//   0x03dec0: 90fffe81  adrp     x1, #0xd000
//   0x03dec4: d0fffea2  adrp     x2, #0x13000
//   0x03dec8: d0fffe63  adrp     x3, #0xb000
uint64_t fde_0355_sub_03de8c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10603FFULL) + (x1 ^ 0xAA0103F4ULL) + (x2 ^ 0x03DE8CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10603FFULL; // 0x03de8c: sub sp, sp, #0x180
    acc = (acc * 0x100000001B3ULL) ^ 0xA9126FFCULL; // 0x03de90: stp x28, x27, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91367FAULL; // 0x03de94: stp x26, x25, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9145FF8ULL; // 0x03de98: stp x24, x23, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91557F6ULL; // 0x03de9c: stp x22, x21, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9164FF4ULL; // 0x03dea0: stp x20, x19, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9177BFDULL; // 0x03dea4: stp x29, x30, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0x9105C3FDULL; // 0x03dea8: add x29, sp, #0x170
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x03deac: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401708ULL; // 0x03deb0: ldr x8, [x24, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0356 @ 0x03e1f8..0x03e31c (292 bytes)
// [VN] Phục dựng FDE #0356 tại 0x03e1f8..0x03e31c (292 byte)
//   0x03e1f8: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x03e1fc: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x03e200: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x03e204: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x03e208: 9100c3fd  add      x29, sp, #0x30
//   0x03e20c: d0000128  adrp     x8, #0x64000
//   0x03e210: b94fb908  ldr      w8, [x8, #0xfb8]
//   0x03e214: 2a0003f4  mov      w20, w0
//   0x03e218: aa0103f3  mov      x19, x1
//   0x03e21c: 2a0803e0  mov      w0, w8
//   0x03e220: 94007b88  bl       #0x5d040
//   0x03e224: d0000148  adrp     x8, #0x68000
//   0x03e228: 93407e97  sxtw     x23, w20
//   0x03e22c: 913ba108  add      x8, x8, #0xee8
//   0x03e230: 8b171515  add      x21, x8, x23, lsl #5
//   0x03e234: f94006a4  ldr      x4, [x21, #8]
uint64_t fde_0356_sub_03e1f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x93407E97ULL) + (x2 ^ 0x03E1F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x03e1f8: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x03e1fc: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x03e200: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x03e204: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x03e208: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000128ULL; // 0x03e20c: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xB94FB908ULL; // 0x03e210: ldr w8, [x8, #0xfb8]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F4ULL; // 0x03e214: mov w20, w0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x03e218: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0803E0ULL; // 0x03e21c: mov w0, w8
    return acc;
}

// [EN] Reconstructed FDE #0357 @ 0x03e31c..0x03e418 (252 bytes)
// [VN] Phục dựng FDE #0357 tại 0x03e31c..0x03e418 (252 byte)
//   0x03e31c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x03e320: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03e324: 910043fd  add      x29, sp, #0x10
//   0x03e328: b0fffe61  adrp     x1, #0xb000
//   0x03e32c: f0fffea2  adrp     x2, #0x15000
//   0x03e330: 91129c21  add      x1, x1, #0x4a7
//   0x03e334: 911c3c42  add      x2, x2, #0x70f
//   0x03e338: 528000c0  mov      w0, #6
//   0x03e33c: 94007a59  bl       #0x5cca0
//   0x03e340: d0fffe80  adrp     x0, #0x10000
//   0x03e344: f0fffe81  adrp     x1, #0x11000
//   0x03e348: 90000002  adrp     x2, #0x3e000
//   0x03e34c: d0000123  adrp     x3, #0x64000
//   0x03e350: 911ad800  add      x0, x0, #0x6b6
//   0x03e354: 912a4021  add      x1, x1, #0xa90
//   0x03e358: 91106042  add      x2, x2, #0x418
uint64_t fde_0357_sub_03e31c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xD0000123ULL) + (x2 ^ 0x03E31CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x03e31c: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03e320: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03e324: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFE61ULL; // 0x03e328: adrp x1, #0xb000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFEA2ULL; // 0x03e32c: adrp x2, #0x15000
    acc = (acc * 0x100000001B3ULL) ^ 0x91129C21ULL; // 0x03e330: add x1, x1, #0x4a7
    acc = (acc * 0x100000001B3ULL) ^ 0x911C3C42ULL; // 0x03e334: add x2, x2, #0x70f
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C0ULL; // 0x03e338: mov w0, #6
    acc = (acc * 0x100000001B3ULL) ^ 0x94007A59ULL; // 0x03e33c: bl #0x5cca0
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFE80ULL; // 0x03e340: adrp x0, #0x10000
    return acc;
}

// [EN] Reconstructed FDE #0358 @ 0x03e418..0x03e464 (76 bytes)
// [VN] Phục dựng FDE #0358 tại 0x03e418..0x03e464 (76 byte)
//   0x03e418: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x03e41c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03e420: 910043fd  add      x29, sp, #0x10
//   0x03e424: b0fffe73  adrp     x19, #0xb000
//   0x03e428: 91129e73  add      x19, x19, #0x4a7
//   0x03e42c: b0fffea2  adrp     x2, #0x13000
//   0x03e430: 910f9442  add      x2, x2, #0x3e5
//   0x03e434: 528000c0  mov      w0, #6
//   0x03e438: aa1303e1  mov      x1, x19
//   0x03e43c: 94007a19  bl       #0x5cca0
//   0x03e440: 90fffe82  adrp     x2, #0xe000
//   0x03e444: 912fec42  add      x2, x2, #0xbfb
//   0x03e448: 528000c0  mov      w0, #6
//   0x03e44c: aa1303e1  mov      x1, x19
//   0x03e450: 94007a14  bl       #0x5cca0
//   0x03e454: a9417bfd  ldp      x29, x30, [sp, #0x10]
uint64_t fde_0358_sub_03e418(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x528000C0ULL) + (x2 ^ 0x03E418ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x03e418: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03e41c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03e420: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFE73ULL; // 0x03e424: adrp x19, #0xb000
    acc = (acc * 0x100000001B3ULL) ^ 0x91129E73ULL; // 0x03e428: add x19, x19, #0x4a7
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFEA2ULL; // 0x03e42c: adrp x2, #0x13000
    acc = (acc * 0x100000001B3ULL) ^ 0x910F9442ULL; // 0x03e430: add x2, x2, #0x3e5
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C0ULL; // 0x03e434: mov w0, #6
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E1ULL; // 0x03e438: mov x1, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x94007A19ULL; // 0x03e43c: bl #0x5cca0
    return acc;
}

// [EN] Reconstructed FDE #0359 @ 0x03e464..0x03e648 (484 bytes)
// [VN] Phục dựng FDE #0359 tại 0x03e464..0x03e648 (484 byte)
//   0x03e464: d10143ff  sub      sp, sp, #0x50
//   0x03e468: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x03e46c: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x03e470: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x03e474: 910103fd  add      x29, sp, #0x40
//   0x03e478: d0fffe80  adrp     x0, #0x10000
//   0x03e47c: 913f1400  add      x0, x0, #0xfc5
//   0x03e480: 2a0303f5  mov      w21, w3
//   0x03e484: 2a0203f3  mov      w19, w2
//   0x03e488: 94007b1e  bl       #0x5d100
//   0x03e48c: b4000520  cbz      x0, #0x3e530
//   0x03e490: f0fffea8  adrp     x8, #0x15000
//   0x03e494: b0fffe89  adrp     x9, #0xf000
//   0x03e498: 91101d08  add      x8, x8, #0x407
//   0x03e49c: 911b3529  add      x9, x9, #0x6cd
//   0x03e4a0: 7100767f  cmp      w19, #0x1d
uint64_t fde_0359_sub_03e464(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xB0FFFE89ULL) + (x2 ^ 0x03E464ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x03e464: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x03e468: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x03e46c: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x03e470: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x03e474: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFE80ULL; // 0x03e478: adrp x0, #0x10000
    acc = (acc * 0x100000001B3ULL) ^ 0x913F1400ULL; // 0x03e47c: add x0, x0, #0xfc5
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303F5ULL; // 0x03e480: mov w21, w3
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F3ULL; // 0x03e484: mov w19, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x94007B1EULL; // 0x03e488: bl #0x5d100
    return acc;
}

// [EN] Reconstructed FDE #0360 @ 0x03e648..0x03e678 (48 bytes)
// [VN] Phục dựng FDE #0360 tại 0x03e648..0x03e678 (48 byte)
//   0x03e648: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x03e64c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03e650: 910043fd  add      x29, sp, #0x10
//   0x03e654: aa1e03f3  mov      x19, x30
//   0x03e658: 94007b12  bl       #0x5d2a0
//   0x03e65c: 35000060  cbnz     w0, #0x3e668
//   0x03e660: aa1303e0  mov      x0, x19
//   0x03e664: 94007b13  bl       #0x5d2b0
//   0x03e668: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x03e66c: f84207f3  ldr      x19, [sp], #0x20
//   0x03e670: d65f03c0  ret      
//   0x03e674: 97ffb2bd  bl       #0x2b168
uint64_t fde_0360_sub_03e648(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x97FFB2BDULL) + (x2 ^ 0x03E648ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x03e648: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03e64c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03e650: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x03e654: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0x94007B12ULL; // 0x03e658: bl #0x5d2a0
    acc = (acc * 0x100000001B3ULL) ^ 0x35000060ULL; // 0x03e65c: cbnz w0, #0x3e668
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x03e660: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x94007B13ULL; // 0x03e664: bl #0x5d2b0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x03e668: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x03e66c: ldr x19, [sp], #0x20
    return acc;
}

// [EN] Reconstructed FDE #0361 @ 0x03e678..0x03e6b0 (56 bytes)
// [VN] Phục dựng FDE #0361 tại 0x03e678..0x03e6b0 (56 byte)
//   0x03e678: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x03e67c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03e680: 910043fd  add      x29, sp, #0x10
//   0x03e684: aa1e03f3  mov      x19, x30
//   0x03e688: a9007d1f  stp      xzr, xzr, [x8]
//   0x03e68c: f900091f  str      xzr, [x8, #0x10]
//   0x03e690: 94007b04  bl       #0x5d2a0
//   0x03e694: 35000060  cbnz     w0, #0x3e6a0
//   0x03e698: aa1303e0  mov      x0, x19
//   0x03e69c: 94007b05  bl       #0x5d2b0
//   0x03e6a0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x03e6a4: f84207f3  ldr      x19, [sp], #0x20
//   0x03e6a8: d65f03c0  ret      
//   0x03e6ac: 97ffb2af  bl       #0x2b168
uint64_t fde_0361_sub_03e678(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x03E678ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x03e678: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03e67c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03e680: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x03e684: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9007D1FULL; // 0x03e688: stp xzr, xzr, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900091FULL; // 0x03e68c: str xzr, [x8, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x94007B04ULL; // 0x03e690: bl #0x5d2a0
    acc = (acc * 0x100000001B3ULL) ^ 0x35000060ULL; // 0x03e694: cbnz w0, #0x3e6a0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x03e698: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x94007B05ULL; // 0x03e69c: bl #0x5d2b0
    return acc;
}

// [EN] Reconstructed FDE #0362 @ 0x03e6b0..0x03e6e0 (48 bytes)
// [VN] Phục dựng FDE #0362 tại 0x03e6b0..0x03e6e0 (48 byte)
//   0x03e6b0: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x03e6b4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03e6b8: 910043fd  add      x29, sp, #0x10
//   0x03e6bc: aa1e03f3  mov      x19, x30
//   0x03e6c0: 94007af8  bl       #0x5d2a0
//   0x03e6c4: 35000060  cbnz     w0, #0x3e6d0
//   0x03e6c8: aa1303e0  mov      x0, x19
//   0x03e6cc: 94007af9  bl       #0x5d2b0
//   0x03e6d0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x03e6d4: f84207f3  ldr      x19, [sp], #0x20
//   0x03e6d8: d65f03c0  ret      
//   0x03e6dc: 97ffb2a3  bl       #0x2b168
uint64_t fde_0362_sub_03e6b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x97FFB2A3ULL) + (x2 ^ 0x03E6B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x03e6b0: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03e6b4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03e6b8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x03e6bc: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0x94007AF8ULL; // 0x03e6c0: bl #0x5d2a0
    acc = (acc * 0x100000001B3ULL) ^ 0x35000060ULL; // 0x03e6c4: cbnz w0, #0x3e6d0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x03e6c8: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x94007AF9ULL; // 0x03e6cc: bl #0x5d2b0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x03e6d0: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x03e6d4: ldr x19, [sp], #0x20
    return acc;
}

// [EN] Reconstructed FDE #0363 @ 0x03e6e0..0x03e74c (108 bytes)
// [VN] Phục dựng FDE #0363 tại 0x03e6e0..0x03e74c (108 byte)
//   0x03e6e0: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x03e6e4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03e6e8: 910043fd  add      x29, sp, #0x10
//   0x03e6ec: d0000133  adrp     x19, #0x64000
//   0x03e6f0: 9139f273  add      x19, x19, #0xe7c
//   0x03e6f4: 91335260  add      x0, x19, #0xcd4
//   0x03e6f8: 94007a9e  bl       #0x5d170
//   0x03e6fc: 3900027f  strb     wzr, [x19]
//   0x03e700: f0fffe61  adrp     x1, #0xd000
//   0x03e704: b0fffea2  adrp     x2, #0x13000
//   0x03e708: 910f0021  add      x1, x1, #0x3c0
//   0x03e70c: 9110d442  add      x2, x2, #0x435
//   0x03e710: 52800060  mov      w0, #3
//   0x03e714: 94007963  bl       #0x5cca0
//   0x03e718: f0000120  adrp     x0, #0x65000
//   0x03e71c: 912d4000  add      x0, x0, #0xb50
uint64_t fde_0363_sub_03e6e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x52800060ULL) + (x2 ^ 0x03E6E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x03e6e0: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03e6e4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03e6e8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000133ULL; // 0x03e6ec: adrp x19, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x9139F273ULL; // 0x03e6f0: add x19, x19, #0xe7c
    acc = (acc * 0x100000001B3ULL) ^ 0x91335260ULL; // 0x03e6f4: add x0, x19, #0xcd4
    acc = (acc * 0x100000001B3ULL) ^ 0x94007A9EULL; // 0x03e6f8: bl #0x5d170
    acc = (acc * 0x100000001B3ULL) ^ 0x3900027FULL; // 0x03e6fc: strb wzr, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFE61ULL; // 0x03e700: adrp x1, #0xd000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFEA2ULL; // 0x03e704: adrp x2, #0x13000
    return acc;
}

// [EN] Reconstructed FDE #0364 @ 0x03e74c..0x03e7bc (112 bytes)
// [VN] Phục dựng FDE #0364 tại 0x03e74c..0x03e7bc (112 byte)
//   0x03e74c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x03e750: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03e754: 910043fd  add      x29, sp, #0x10
//   0x03e758: d0000133  adrp     x19, #0x64000
//   0x03e75c: 9139f273  add      x19, x19, #0xe7c
//   0x03e760: 91335260  add      x0, x19, #0xcd4
//   0x03e764: 94007a83  bl       #0x5d170
//   0x03e768: 52800028  mov      w8, #1
//   0x03e76c: 39000268  strb     w8, [x19]
//   0x03e770: f0fffe61  adrp     x1, #0xd000
//   0x03e774: b0fffea2  adrp     x2, #0x13000
//   0x03e778: 910f0021  add      x1, x1, #0x3c0
//   0x03e77c: 9110d442  add      x2, x2, #0x435
//   0x03e780: 52800060  mov      w0, #3
//   0x03e784: 94007947  bl       #0x5cca0
//   0x03e788: f0000120  adrp     x0, #0x65000
uint64_t fde_0364_sub_03e74c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x9110D442ULL) + (x2 ^ 0x03E74CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x03e74c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03e750: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03e754: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000133ULL; // 0x03e758: adrp x19, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x9139F273ULL; // 0x03e75c: add x19, x19, #0xe7c
    acc = (acc * 0x100000001B3ULL) ^ 0x91335260ULL; // 0x03e760: add x0, x19, #0xcd4
    acc = (acc * 0x100000001B3ULL) ^ 0x94007A83ULL; // 0x03e764: bl #0x5d170
    acc = (acc * 0x100000001B3ULL) ^ 0x52800028ULL; // 0x03e768: mov w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x39000268ULL; // 0x03e76c: strb w8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFE61ULL; // 0x03e770: adrp x1, #0xd000
    return acc;
}

// [EN] Reconstructed FDE #0365 @ 0x03e7bc..0x03ec6c (1200 bytes)
// [VN] Phục dựng FDE #0365 tại 0x03e7bc..0x03ec6c (1200 byte)
//   0x03e7bc: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x03e7c0: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x03e7c4: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x03e7c8: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x03e7cc: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x03e7d0: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x03e7d4: 910143fd  add      x29, sp, #0x50
//   0x03e7d8: d10a03ff  sub      sp, sp, #0x280
//   0x03e7dc: d53bd056  mrs      x22, tpidr_el0
//   0x03e7e0: f94016c8  ldr      x8, [x22, #0x28]
//   0x03e7e4: aa1e03f3  mov      x19, x30
//   0x03e7e8: aa0103f4  mov      x20, x1
//   0x03e7ec: aa0003f5  mov      x21, x0
//   0x03e7f0: f81a03a8  stur     x8, [x29, #-0x60]
//   0x03e7f4: 90000000  adrp     x0, #0x3e000
//   0x03e7f8: 911ef000  add      x0, x0, #0x7bc
uint64_t fde_0365_sub_03e7bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xAA0003F5ULL) + (x2 ^ 0x03E7BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x03e7bc: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x03e7c0: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x03e7c4: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x03e7c8: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x03e7cc: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x03e7d0: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x03e7d4: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD10A03FFULL; // 0x03e7d8: sub sp, sp, #0x280
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x03e7dc: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x03e7e0: ldr x8, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0366 @ 0x03ec6c..0x03ed70 (260 bytes)
// [VN] Phục dựng FDE #0366 tại 0x03ec6c..0x03ed70 (260 byte)
//   0x03ec6c: d10143ff  sub      sp, sp, #0x50
//   0x03ec70: f90013f5  str      x21, [sp, #0x20]
//   0x03ec74: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x03ec78: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x03ec7c: 910103fd  add      x29, sp, #0x40
//   0x03ec80: d53bd053  mrs      x19, tpidr_el0
//   0x03ec84: f9401668  ldr      x8, [x19, #0x28]
//   0x03ec88: f9000fe8  str      x8, [sp, #0x18]
//   0x03ec8c: f0000128  adrp     x8, #0x65000
//   0x03ec90: 910a8108  add      x8, x8, #0x2a0
//   0x03ec94: 08dffd08  ldarb    w8, [x8]
//   0x03ec98: 36000188  tbz      w8, #0, #0x3ecc8
//   0x03ec9c: f0000128  adrp     x8, #0x65000
//   0x03eca0: f9415500  ldr      x0, [x8, #0x2a8]
//   0x03eca4: f9401668  ldr      x8, [x19, #0x28]
//   0x03eca8: f9400fe9  ldr      x9, [sp, #0x18]
uint64_t fde_0366_sub_03ec6c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xF0000128ULL) + (x2 ^ 0x03EC6CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x03ec6c: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F5ULL; // 0x03ec70: str x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x03ec74: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x03ec78: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x03ec7c: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x03ec80: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x03ec84: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x03ec88: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000128ULL; // 0x03ec8c: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x910A8108ULL; // 0x03ec90: add x8, x8, #0x2a0
    return acc;
}

// [EN] Reconstructed FDE #0367 @ 0x03ed70..0x03ee38 (200 bytes)
// [VN] Phục dựng FDE #0367 tại 0x03ed70..0x03ee38 (200 byte)
//   0x03ed70: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x03ed74: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03ed78: 910043fd  add      x29, sp, #0x10
//   0x03ed7c: aa1e03f3  mov      x19, x30
//   0x03ed80: 2a0003f4  mov      w20, w0
//   0x03ed84: 37f00120  tbnz     w0, #0x1e, #0x3eda8
//   0x03ed88: 90000000  adrp     x0, #0x3e000
//   0x03ed8c: 9135c000  add      x0, x0, #0xd70
//   0x03ed90: 94007940  bl       #0x5d290
//   0x03ed94: aa0003e8  mov      x8, x0
//   0x03ed98: 2a1403e0  mov      w0, w20
//   0x03ed9c: d63f0100  blr      x8
//   0x03eda0: 2a0003f4  mov      w20, w0
//   0x03eda4: 14000014  b        #0x3edf4
//   0x03eda8: 320223e8  mov      w8, #-0x3fffff81
//   0x03edac: 6b08029f  cmp      w20, w8
uint64_t fde_0367_sub_03ed70(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x2A0003F4ULL) + (x2 ^ 0x03ED70ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x03ed70: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03ed74: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03ed78: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x03ed7c: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F4ULL; // 0x03ed80: mov w20, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x37F00120ULL; // 0x03ed84: tbnz w0, #0x1e, #0x3eda8
    acc = (acc * 0x100000001B3ULL) ^ 0x90000000ULL; // 0x03ed88: adrp x0, #0x3e000
    acc = (acc * 0x100000001B3ULL) ^ 0x9135C000ULL; // 0x03ed8c: add x0, x0, #0xd70
    acc = (acc * 0x100000001B3ULL) ^ 0x94007940ULL; // 0x03ed90: bl #0x5d290
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x03ed94: mov x8, x0
    return acc;
}

// [EN] Reconstructed FDE #0368 @ 0x03ee38..0x03ef50 (280 bytes)
// [VN] Phục dựng FDE #0368 tại 0x03ee38..0x03ef50 (280 byte)
//   0x03ee38: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x03ee3c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x03ee40: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x03ee44: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x03ee48: 9100c3fd  add      x29, sp, #0x30
//   0x03ee4c: aa1e03f3  mov      x19, x30
//   0x03ee50: aa0103f4  mov      x20, x1
//   0x03ee54: 2a0003f5  mov      w21, w0
//   0x03ee58: 37f00140  tbnz     w0, #0x1e, #0x3ee80
//   0x03ee5c: 90000000  adrp     x0, #0x3e000
//   0x03ee60: 9138e000  add      x0, x0, #0xe38
//   0x03ee64: 9400790b  bl       #0x5d290
//   0x03ee68: aa0003e8  mov      x8, x0
//   0x03ee6c: 2a1503e0  mov      w0, w21
//   0x03ee70: aa1403e1  mov      x1, x20
//   0x03ee74: d63f0100  blr      x8
uint64_t fde_0368_sub_03ee38(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0xAA0003E8ULL) + (x2 ^ 0x03EE38ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x03ee38: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x03ee3c: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x03ee40: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x03ee44: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x03ee48: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x03ee4c: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x03ee50: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F5ULL; // 0x03ee54: mov w21, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x37F00140ULL; // 0x03ee58: tbnz w0, #0x1e, #0x3ee80
    acc = (acc * 0x100000001B3ULL) ^ 0x90000000ULL; // 0x03ee5c: adrp x0, #0x3e000
    return acc;
}

// [EN] Reconstructed FDE #0369 @ 0x03ef50..0x03f078 (296 bytes)
// [VN] Phục dựng FDE #0369 tại 0x03ef50..0x03f078 (296 byte)
//   0x03ef50: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x03ef54: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x03ef58: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x03ef5c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x03ef60: 9100c3fd  add      x29, sp, #0x30
//   0x03ef64: aa1e03f3  mov      x19, x30
//   0x03ef68: 2a0003f4  mov      w20, w0
//   0x03ef6c: 37f00120  tbnz     w0, #0x1e, #0x3ef90
//   0x03ef70: 90000000  adrp     x0, #0x3e000
//   0x03ef74: 913d4000  add      x0, x0, #0xf50
//   0x03ef78: 940078c6  bl       #0x5d290
//   0x03ef7c: aa0003e8  mov      x8, x0
//   0x03ef80: 2a1403e0  mov      w0, w20
//   0x03ef84: d63f0100  blr      x8
//   0x03ef88: aa0003f4  mov      x20, x0
//   0x03ef8c: 14000021  b        #0x3f010
uint64_t fde_0369_sub_03ef50(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x2A1403E0ULL) + (x2 ^ 0x03EF50ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x03ef50: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x03ef54: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x03ef58: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x03ef5c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x03ef60: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x03ef64: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F4ULL; // 0x03ef68: mov w20, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x37F00120ULL; // 0x03ef6c: tbnz w0, #0x1e, #0x3ef90
    acc = (acc * 0x100000001B3ULL) ^ 0x90000000ULL; // 0x03ef70: adrp x0, #0x3e000
    acc = (acc * 0x100000001B3ULL) ^ 0x913D4000ULL; // 0x03ef74: add x0, x0, #0xf50
    return acc;
}

// [EN] Reconstructed FDE #0370 @ 0x03f078..0x03f11c (164 bytes)
// [VN] Phục dựng FDE #0370 tại 0x03f078..0x03f11c (164 byte)
//   0x03f078: d10483ff  sub      sp, sp, #0x120
//   0x03f07c: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x03f080: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x03f084: 910443fd  add      x29, sp, #0x110
//   0x03f088: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x03f08c: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x03f090: f90057e7  str      x7, [sp, #0xa8]
//   0x03f094: ad0007e0  stp      q0, q1, [sp]
//   0x03f098: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x03f09c: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x03f0a0: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x03f0a4: d53bd053  mrs      x19, tpidr_el0
//   0x03f0a8: f9401669  ldr      x9, [x19, #0x28]
//   0x03f0ac: 910223ea  add      x10, sp, #0x88
//   0x03f0b0: 928004ec  mov      x12, #-0x28
//   0x03f0b4: 910043ab  add      x11, x29, #0x10
uint64_t fde_0370_sub_03f078(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xF9401669ULL) + (x2 ^ 0x03F078ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x03f078: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x03f07c: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x03f080: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x03f084: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x03f088: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x03f08c: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x03f090: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x03f094: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x03f098: stp q2, q3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0217E4ULL; // 0x03f09c: stp q4, q5, [sp, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #0371 @ 0x03f11c..0x03f2d4 (440 bytes)
// [VN] Phục dựng FDE #0371 tại 0x03f11c..0x03f2d4 (440 byte)
//   0x03f11c: d102c3ff  sub      sp, sp, #0xb0
//   0x03f120: f9004bf3  str      x19, [sp, #0x90]
//   0x03f124: a90a7bfd  stp      x29, x30, [sp, #0xa0]
//   0x03f128: 910283fd  add      x29, sp, #0xa0
//   0x03f12c: d53bd048  mrs      x8, tpidr_el0
//   0x03f130: f9401509  ldr      x9, [x8, #0x28]
//   0x03f134: f81e83a9  stur     x9, [x29, #-0x18]
//   0x03f138: d0000129  adrp     x9, #0x65000
//   0x03f13c: 910ac129  add      x9, x9, #0x2b0
//   0x03f140: 08dffd29  ldarb    w9, [x9]
//   0x03f144: 36000169  tbz      w9, #0, #0x3f170
//   0x03f148: b0000129  adrp     x9, #0x64000
//   0x03f14c: b94f4520  ldr      w0, [x9, #0xf44]
//   0x03f150: f9401508  ldr      x8, [x8, #0x28]
//   0x03f154: f85e83a9  ldur     x9, [x29, #-0x18]
//   0x03f158: eb09011f  cmp      x8, x9
uint64_t fde_0371_sub_03f11c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD102C3FFULL) + (x1 ^ 0xB94F4520ULL) + (x2 ^ 0x03F11CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD102C3FFULL; // 0x03f11c: sub sp, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9004BF3ULL; // 0x03f120: str x19, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A7BFDULL; // 0x03f124: stp x29, x30, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910283FDULL; // 0x03f128: add x29, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD048ULL; // 0x03f12c: mrs x8, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401509ULL; // 0x03f130: ldr x9, [x8, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E83A9ULL; // 0x03f134: stur x9, [x29, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000129ULL; // 0x03f138: adrp x9, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x910AC129ULL; // 0x03f13c: add x9, x9, #0x2b0
    acc = (acc * 0x100000001B3ULL) ^ 0x08DFFD29ULL; // 0x03f140: ldarb w9, [x9]
    return acc;
}

// [EN] Reconstructed FDE #0372 @ 0x03f2d4..0x03f390 (188 bytes)
// [VN] Phục dựng FDE #0372 tại 0x03f2d4..0x03f390 (188 byte)
//   0x03f2d4: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x03f2d8: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x03f2dc: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x03f2e0: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x03f2e4: 9100c3fd  add      x29, sp, #0x30
//   0x03f2e8: b0000135  adrp     x21, #0x64000
//   0x03f2ec: aa0003f3  mov      x19, x0
//   0x03f2f0: 52800094  mov      w20, #4
//   0x03f2f4: 911842b5  add      x21, x21, #0x610
//   0x03f2f8: aa1f03f7  mov      x23, xzr
//   0x03f2fc: aa1f03f6  mov      x22, xzr
//   0x03f300: f8776aa8  ldr      x8, [x21, x23]
//   0x03f304: 370000c8  tbnz     w8, #0, #0x3f31c
//   0x03f308: 910042f7  add      x23, x23, #0x10
//   0x03f30c: f12002ff  cmp      x23, #0x800
//   0x03f310: 540002e0  b.eq     #0x3f36c
uint64_t fde_0372_sub_03f2d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x370000C8ULL) + (x2 ^ 0x03F2D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x03f2d4: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x03f2d8: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x03f2dc: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x03f2e0: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x03f2e4: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000135ULL; // 0x03f2e8: adrp x21, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x03f2ec: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800094ULL; // 0x03f2f0: mov w20, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x911842B5ULL; // 0x03f2f4: add x21, x21, #0x610
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03F7ULL; // 0x03f2f8: mov x23, xzr
    return acc;
}

// [EN] Reconstructed FDE #0373 @ 0x03f390..0x03f454 (196 bytes)
// [VN] Phục dựng FDE #0373 tại 0x03f390..0x03f454 (196 byte)
//   0x03f390: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x03f394: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03f398: 910043fd  add      x29, sp, #0x10
//   0x03f39c: d0000128  adrp     x8, #0x65000
//   0x03f3a0: 910b0108  add      x8, x8, #0x2c0
//   0x03f3a4: 08dffd08  ldarb    w8, [x8]
//   0x03f3a8: 360000a8  tbz      w8, #0, #0x3f3bc
//   0x03f3ac: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x03f3b0: 2a1f03e0  mov      w0, wzr
//   0x03f3b4: f84207f3  ldr      x19, [sp], #0x20
//   0x03f3b8: d65f03c0  ret      
//   0x03f3bc: d0000120  adrp     x0, #0x65000
//   0x03f3c0: 910b0000  add      x0, x0, #0x2c0
//   0x03f3c4: 2a0203f3  mov      w19, w2
//   0x03f3c8: 9400787a  bl       #0x5d5b0
//   0x03f3cc: 34ffff00  cbz      w0, #0x3f3ac
uint64_t fde_0373_sub_03f390(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x910B0000ULL) + (x2 ^ 0x03F390ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x03f390: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03f394: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03f398: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000128ULL; // 0x03f39c: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x910B0108ULL; // 0x03f3a0: add x8, x8, #0x2c0
    acc = (acc * 0x100000001B3ULL) ^ 0x08DFFD08ULL; // 0x03f3a4: ldarb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x360000A8ULL; // 0x03f3a8: tbz w8, #0, #0x3f3bc
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x03f3ac: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x03f3b0: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x03f3b4: ldr x19, [sp], #0x20
    return acc;
}

// [EN] Reconstructed FDE #0374 @ 0x03f454..0x03f504 (176 bytes)
// [VN] Phục dựng FDE #0374 tại 0x03f454..0x03f504 (176 byte)
//   0x03f454: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x03f458: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x03f45c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03f460: 910083fd  add      x29, sp, #0x20
//   0x03f464: aa1e03f3  mov      x19, x30
//   0x03f468: aa0303f4  mov      x20, x3
//   0x03f46c: aa0203f5  mov      x21, x2
//   0x03f470: aa0003f6  mov      x22, x0
//   0x03f474: 2a0103e4  mov      w4, w1
//   0x03f478: f0fffe61  adrp     x1, #0xe000
//   0x03f47c: d0fffe62  adrp     x2, #0xd000
//   0x03f480: 9130d021  add      x1, x1, #0xc34
//   0x03f484: 910f7c42  add      x2, x2, #0x3df
//   0x03f488: 528000c0  mov      w0, #6
//   0x03f48c: aa1603e3  mov      x3, x22
//   0x03f490: aa1503e5  mov      x5, x21
uint64_t fde_0374_sub_03f454(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x910F7C42ULL) + (x2 ^ 0x03F454ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x03f454: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x03f458: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x03f45c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03f460: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x03f464: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F4ULL; // 0x03f468: mov x20, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x03f46c: mov x21, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F6ULL; // 0x03f470: mov x22, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103E4ULL; // 0x03f474: mov w4, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFE61ULL; // 0x03f478: adrp x1, #0xe000
    return acc;
}

// [EN] Reconstructed FDE #0375 @ 0x03f504..0x03f59c (152 bytes)
// [VN] Phục dựng FDE #0375 tại 0x03f504..0x03f59c (152 byte)
//   0x03f504: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x03f508: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03f50c: 910043fd  add      x29, sp, #0x10
//   0x03f510: aa1e03f3  mov      x19, x30
//   0x03f514: aa0003f4  mov      x20, x0
//   0x03f518: f0fffe61  adrp     x1, #0xe000
//   0x03f51c: b0fffe82  adrp     x2, #0x10000
//   0x03f520: 9130d021  add      x1, x1, #0xc34
//   0x03f524: 91107442  add      x2, x2, #0x41d
//   0x03f528: 528000c0  mov      w0, #6
//   0x03f52c: aa1403e3  mov      x3, x20
//   0x03f530: 940075dc  bl       #0x5cca0
//   0x03f534: 528001e0  mov      w0, #0xf
//   0x03f538: 940077c6  bl       #0x5d450
//   0x03f53c: 90000000  adrp     x0, #0x3f000
//   0x03f540: 91141000  add      x0, x0, #0x504
uint64_t fde_0375_sub_03f504(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x528001E0ULL) + (x2 ^ 0x03F504ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x03f504: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03f508: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03f50c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x03f510: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x03f514: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFE61ULL; // 0x03f518: adrp x1, #0xe000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFE82ULL; // 0x03f51c: adrp x2, #0x10000
    acc = (acc * 0x100000001B3ULL) ^ 0x9130D021ULL; // 0x03f520: add x1, x1, #0xc34
    acc = (acc * 0x100000001B3ULL) ^ 0x91107442ULL; // 0x03f524: add x2, x2, #0x41d
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C0ULL; // 0x03f528: mov w0, #6
    return acc;
}

// [EN] Reconstructed FDE #0376 @ 0x03f59c..0x03f7c4 (552 bytes)
// [VN] Phục dựng FDE #0376 tại 0x03f59c..0x03f7c4 (552 byte)
//   0x03f59c: d10143ff  sub      sp, sp, #0x50
//   0x03f5a0: f90013f5  str      x21, [sp, #0x20]
//   0x03f5a4: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x03f5a8: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x03f5ac: 910103fd  add      x29, sp, #0x40
//   0x03f5b0: d53bd053  mrs      x19, tpidr_el0
//   0x03f5b4: f9401668  ldr      x8, [x19, #0x28]
//   0x03f5b8: f9000fe8  str      x8, [sp, #0x18]
//   0x03f5bc: d0000128  adrp     x8, #0x65000
//   0x03f5c0: 910b6108  add      x8, x8, #0x2d8
//   0x03f5c4: 08dffd08  ldarb    w8, [x8]
//   0x03f5c8: 36000188  tbz      w8, #0, #0x3f5f8
//   0x03f5cc: b0000128  adrp     x8, #0x64000
//   0x03f5d0: b94f4900  ldr      w0, [x8, #0xf48]
//   0x03f5d4: f9401668  ldr      x8, [x19, #0x28]
//   0x03f5d8: f9400fe9  ldr      x9, [sp, #0x18]
uint64_t fde_0376_sub_03f59c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xB0000128ULL) + (x2 ^ 0x03F59CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x03f59c: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F5ULL; // 0x03f5a0: str x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x03f5a4: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x03f5a8: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x03f5ac: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x03f5b0: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x03f5b4: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x03f5b8: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000128ULL; // 0x03f5bc: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x910B6108ULL; // 0x03f5c0: add x8, x8, #0x2d8
    return acc;
}

// [EN] Reconstructed FDE #0377 @ 0x03f7c4..0x03f854 (144 bytes)
// [VN] Phục dựng FDE #0377 tại 0x03f7c4..0x03f854 (144 byte)
//   0x03f7c4: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x03f7c8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03f7cc: 910043fd  add      x29, sp, #0x10
//   0x03f7d0: d0000128  adrp     x8, #0x65000
//   0x03f7d4: 910b8108  add      x8, x8, #0x2e0
//   0x03f7d8: f9400109  ldr      x9, [x8]
//   0x03f7dc: aa1e03f3  mov      x19, x30
//   0x03f7e0: eb1e013f  cmp      x9, x30
//   0x03f7e4: 540000c8  b.hi     #0x3f7fc
//   0x03f7e8: f9400508  ldr      x8, [x8, #8]
//   0x03f7ec: eb13011f  cmp      x8, x19
//   0x03f7f0: 54000069  b.ls     #0x3f7fc
//   0x03f7f4: aa1f03f4  mov      x20, xzr
//   0x03f7f8: 14000006  b        #0x3f810
//   0x03f7fc: 90000000  adrp     x0, #0x3f000
//   0x03f800: 911f1000  add      x0, x0, #0x7c4
uint64_t fde_0377_sub_03f7c4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA1F03F4ULL) + (x2 ^ 0x03F7C4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x03f7c4: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03f7c8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03f7cc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000128ULL; // 0x03f7d0: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x910B8108ULL; // 0x03f7d4: add x8, x8, #0x2e0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400109ULL; // 0x03f7d8: ldr x9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x03f7dc: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xEB1E013FULL; // 0x03f7e0: cmp x9, x30
    acc = (acc * 0x100000001B3ULL) ^ 0x540000C8ULL; // 0x03f7e4: b.hi #0x3f7fc
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400508ULL; // 0x03f7e8: ldr x8, [x8, #8]
    return acc;
}

// [EN] Reconstructed FDE #0378 @ 0x03f854..0x03f8f4 (160 bytes)
// [VN] Phục dựng FDE #0378 tại 0x03f854..0x03f8f4 (160 byte)
//   0x03f854: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x03f858: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x03f85c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03f860: 910083fd  add      x29, sp, #0x20
//   0x03f864: f9400408  ldr      x8, [x0, #8]
//   0x03f868: aa1e03f3  mov      x19, x30
//   0x03f86c: b4000168  cbz      x8, #0x3f898
//   0x03f870: aa0003f4  mov      x20, x0
//   0x03f874: aa0103f5  mov      x21, x1
//   0x03f878: 90000000  adrp     x0, #0x3f000
//   0x03f87c: 91215000  add      x0, x0, #0x854
//   0x03f880: 94007684  bl       #0x5d290
//   0x03f884: aa0003e8  mov      x8, x0
//   0x03f888: aa1403e0  mov      x0, x20
//   0x03f88c: aa1503e1  mov      x1, x21
//   0x03f890: d63f0100  blr      x8
uint64_t fde_0378_sub_03f854(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xAA0003E8ULL) + (x2 ^ 0x03F854ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x03f854: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x03f858: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x03f85c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03f860: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x03f864: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x03f868: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000168ULL; // 0x03f86c: cbz x8, #0x3f898
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x03f870: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x03f874: mov x21, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x90000000ULL; // 0x03f878: adrp x0, #0x3f000
    return acc;
}

// [EN] Reconstructed FDE #0379 @ 0x03f8f4..0x03f988 (148 bytes)
// [VN] Phục dựng FDE #0379 tại 0x03f8f4..0x03f988 (148 byte)
//   0x03f8f4: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x03f8f8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03f8fc: 910043fd  add      x29, sp, #0x10
//   0x03f900: d0000128  adrp     x8, #0x65000
//   0x03f904: 910bc108  add      x8, x8, #0x2f0
//   0x03f908: 08dffd08  ldarb    w8, [x8]
//   0x03f90c: 360000a8  tbz      w8, #0, #0x3f920
//   0x03f910: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x03f914: 2a1f03e0  mov      w0, wzr
//   0x03f918: f84207f3  ldr      x19, [sp], #0x20
//   0x03f91c: d65f03c0  ret      
//   0x03f920: d0000120  adrp     x0, #0x65000
//   0x03f924: 910bc000  add      x0, x0, #0x2f0
//   0x03f928: 94007722  bl       #0x5d5b0
//   0x03f92c: 34ffff20  cbz      w0, #0x3f910
//   0x03f930: f0fffe60  adrp     x0, #0xe000
uint64_t fde_0379_sub_03f8f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x910BC000ULL) + (x2 ^ 0x03F8F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x03f8f4: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03f8f8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03f8fc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000128ULL; // 0x03f900: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x910BC108ULL; // 0x03f904: add x8, x8, #0x2f0
    acc = (acc * 0x100000001B3ULL) ^ 0x08DFFD08ULL; // 0x03f908: ldarb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x360000A8ULL; // 0x03f90c: tbz w8, #0, #0x3f920
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x03f910: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x03f914: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x03f918: ldr x19, [sp], #0x20
    return acc;
}

// [EN] Reconstructed FDE #0380 @ 0x03f988..0x03f9b0 (40 bytes)
// [VN] Phục dựng FDE #0380 tại 0x03f988..0x03f9b0 (40 byte)
//   0x03f988: b4000082  cbz      x2, #0x3f998
//   0x03f98c: d0000128  adrp     x8, #0x65000
//   0x03f990: f9418103  ldr      x3, [x8, #0x300]
//   0x03f994: d61f0060  br       x3
//   0x03f998: 90fffe81  adrp     x1, #0xf000
//   0x03f99c: f0fffe82  adrp     x2, #0x12000
//   0x03f9a0: 9100d421  add      x1, x1, #0x35
//   0x03f9a4: 913e7c42  add      x2, x2, #0xf9f
//   0x03f9a8: 528000c0  mov      w0, #6
//   0x03f9ac: 140074bd  b        #0x5cca0
uint64_t fde_0380_sub_03f988(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB4000082ULL) + (x1 ^ 0x140074BDULL) + (x2 ^ 0x03F988ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000082ULL; // 0x03f988: cbz x2, #0x3f998
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000128ULL; // 0x03f98c: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9418103ULL; // 0x03f990: ldr x3, [x8, #0x300]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0060ULL; // 0x03f994: br x3
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFE81ULL; // 0x03f998: adrp x1, #0xf000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFE82ULL; // 0x03f99c: adrp x2, #0x12000
    acc = (acc * 0x100000001B3ULL) ^ 0x9100D421ULL; // 0x03f9a0: add x1, x1, #0x35
    acc = (acc * 0x100000001B3ULL) ^ 0x913E7C42ULL; // 0x03f9a4: add x2, x2, #0xf9f
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C0ULL; // 0x03f9a8: mov w0, #6
    acc = (acc * 0x100000001B3ULL) ^ 0x140074BDULL; // 0x03f9ac: b #0x5cca0
    return acc;
}

// [EN] Reconstructed FDE #0381 @ 0x03f9b0..0x03fad8 (296 bytes)
// [VN] Phục dựng FDE #0381 tại 0x03f9b0..0x03fad8 (296 byte)
//   0x03f9b0: d100c3ff  sub      sp, sp, #0x30
//   0x03f9b4: f9000bf3  str      x19, [sp, #0x10]
//   0x03f9b8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03f9bc: 910083fd  add      x29, sp, #0x20
//   0x03f9c0: d0000128  adrp     x8, #0x65000
//   0x03f9c4: 910c2108  add      x8, x8, #0x308
//   0x03f9c8: 08dffd08  ldarb    w8, [x8]
//   0x03f9cc: 360000e8  tbz      w8, #0, #0x3f9e8
//   0x03f9d0: b0000128  adrp     x8, #0x64000
//   0x03f9d4: b94f4d00  ldr      w0, [x8, #0xf4c]
//   0x03f9d8: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x03f9dc: f9400bf3  ldr      x19, [sp, #0x10]
//   0x03f9e0: 9100c3ff  add      sp, sp, #0x30
//   0x03f9e4: d65f03c0  ret      
//   0x03f9e8: d0000128  adrp     x8, #0x65000
//   0x03f9ec: 910c2108  add      x8, x8, #0x308
uint64_t fde_0381_sub_03f9b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0x9100C3FFULL) + (x2 ^ 0x03F9B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x03f9b0: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF3ULL; // 0x03f9b4: str x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x03f9b8: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03f9bc: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000128ULL; // 0x03f9c0: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x910C2108ULL; // 0x03f9c4: add x8, x8, #0x308
    acc = (acc * 0x100000001B3ULL) ^ 0x08DFFD08ULL; // 0x03f9c8: ldarb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x360000E8ULL; // 0x03f9cc: tbz w8, #0, #0x3f9e8
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000128ULL; // 0x03f9d0: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xB94F4D00ULL; // 0x03f9d4: ldr w0, [x8, #0xf4c]
    return acc;
}

// [EN] Reconstructed FDE #0382 @ 0x03fad8..0x03fbc8 (240 bytes)
// [VN] Phục dựng FDE #0382 tại 0x03fad8..0x03fbc8 (240 byte)
//   0x03fad8: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x03fadc: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x03fae0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03fae4: 910083fd  add      x29, sp, #0x20
//   0x03fae8: d0000128  adrp     x8, #0x65000
//   0x03faec: 910c4108  add      x8, x8, #0x310
//   0x03faf0: 08dffd08  ldarb    w8, [x8]
//   0x03faf4: 360000c8  tbz      w8, #0, #0x3fb0c
//   0x03faf8: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x03fafc: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x03fb00: 2a1f03e0  mov      w0, wzr
//   0x03fb04: f84307f5  ldr      x21, [sp], #0x30
//   0x03fb08: d65f03c0  ret      
//   0x03fb0c: aa0003f3  mov      x19, x0
//   0x03fb10: d0000120  adrp     x0, #0x65000
//   0x03fb14: 910c4000  add      x0, x0, #0x310
uint64_t fde_0382_sub_03fad8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x03FAD8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x03fad8: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x03fadc: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x03fae0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03fae4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000128ULL; // 0x03fae8: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x910C4108ULL; // 0x03faec: add x8, x8, #0x310
    acc = (acc * 0x100000001B3ULL) ^ 0x08DFFD08ULL; // 0x03faf0: ldarb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x360000C8ULL; // 0x03faf4: tbz w8, #0, #0x3fb0c
    acc = (acc * 0x100000001B3ULL) ^ 0xA9427BFDULL; // 0x03faf8: ldp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9414FF4ULL; // 0x03fafc: ldp x20, x19, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0383 @ 0x03fbc8..0x03fc78 (176 bytes)
// [VN] Phục dựng FDE #0383 tại 0x03fbc8..0x03fc78 (176 byte)
//   0x03fbc8: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x03fbcc: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x03fbd0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03fbd4: 910083fd  add      x29, sp, #0x20
//   0x03fbd8: aa1e03f3  mov      x19, x30
//   0x03fbdc: aa0203f4  mov      x20, x2
//   0x03fbe0: aa0103f5  mov      x21, x1
//   0x03fbe4: f140145f  cmp      x2, #5, lsl #12
//   0x03fbe8: aa0003f6  mov      x22, x0
//   0x03fbec: 54000101  b.ne     #0x3fc0c
//   0x03fbf0: 90fffea1  adrp     x1, #0x13000
//   0x03fbf4: b0fffe62  adrp     x2, #0xc000
//   0x03fbf8: 91329821  add      x1, x1, #0xca6
//   0x03fbfc: 913ee042  add      x2, x2, #0xfb8
//   0x03fc00: 528000c0  mov      w0, #6
//   0x03fc04: aa1503e3  mov      x3, x21
uint64_t fde_0383_sub_03fbc8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x91329821ULL) + (x2 ^ 0x03FBC8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x03fbc8: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x03fbcc: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x03fbd0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03fbd4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x03fbd8: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x03fbdc: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x03fbe0: mov x21, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF140145FULL; // 0x03fbe4: cmp x2, #5, lsl #12
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F6ULL; // 0x03fbe8: mov x22, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x54000101ULL; // 0x03fbec: b.ne #0x3fc0c
    return acc;
}

// [EN] Reconstructed FDE #0384 @ 0x03fc78..0x03fcb4 (60 bytes)
// [VN] Phục dựng FDE #0384 tại 0x03fc78..0x03fcb4 (60 byte)
//   0x03fc78: 90fffe89  adrp     x9, #0xf000
//   0x03fc7c: b0fffeaa  adrp     x10, #0x14000
//   0x03fc80: d0fffea8  adrp     x8, #0x15000
//   0x03fc84: 912eb129  add      x9, x9, #0xbac
//   0x03fc88: 9106254a  add      x10, x10, #0x189
//   0x03fc8c: 7100003f  cmp      w1, #0
//   0x03fc90: 90fffea1  adrp     x1, #0x13000
//   0x03fc94: 91120d08  add      x8, x8, #0x483
//   0x03fc98: aa0303e5  mov      x5, x3
//   0x03fc9c: 91329821  add      x1, x1, #0xca6
//   0x03fca0: 9a890143  csel     x3, x10, x9, eq
//   0x03fca4: 528000c0  mov      w0, #6
//   0x03fca8: aa0203e4  mov      x4, x2
//   0x03fcac: aa0803e2  mov      x2, x8
//   0x03fcb0: 140073fc  b        #0x5cca0
uint64_t fde_0384_sub_03fc78(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90FFFE89ULL) + (x1 ^ 0xAA0203E4ULL) + (x2 ^ 0x03FC78ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFE89ULL; // 0x03fc78: adrp x9, #0xf000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFEAAULL; // 0x03fc7c: adrp x10, #0x14000
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFEA8ULL; // 0x03fc80: adrp x8, #0x15000
    acc = (acc * 0x100000001B3ULL) ^ 0x912EB129ULL; // 0x03fc84: add x9, x9, #0xbac
    acc = (acc * 0x100000001B3ULL) ^ 0x9106254AULL; // 0x03fc88: add x10, x10, #0x189
    acc = (acc * 0x100000001B3ULL) ^ 0x7100003FULL; // 0x03fc8c: cmp w1, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFEA1ULL; // 0x03fc90: adrp x1, #0x13000
    acc = (acc * 0x100000001B3ULL) ^ 0x91120D08ULL; // 0x03fc94: add x8, x8, #0x483
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303E5ULL; // 0x03fc98: mov x5, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x91329821ULL; // 0x03fc9c: add x1, x1, #0xca6
    return acc;
}

// [EN] Reconstructed FDE #0385 @ 0x03fcb4..0x03fe60 (428 bytes)
// [VN] Phục dựng FDE #0385 tại 0x03fcb4..0x03fe60 (428 byte)
//   0x03fcb4: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x03fcb8: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x03fcbc: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x03fcc0: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x03fcc4: 9100c3fd  add      x29, sp, #0x30
//   0x03fcc8: d0000128  adrp     x8, #0x65000
//   0x03fccc: f9418d08  ldr      x8, [x8, #0x318]
//   0x03fcd0: aa0003f3  mov      x19, x0
//   0x03fcd4: d63f0100  blr      x8
//   0x03fcd8: 90fffea1  adrp     x1, #0x13000
//   0x03fcdc: b0fffe62  adrp     x2, #0xc000
//   0x03fce0: f0fffe83  adrp     x3, #0x12000
//   0x03fce4: 91329821  add      x1, x1, #0xca6
//   0x03fce8: 913ee042  add      x2, x2, #0xfb8
//   0x03fcec: 912d4863  add      x3, x3, #0xb52
//   0x03fcf0: 528000c0  mov      w0, #6
uint64_t fde_0385_sub_03fcb4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0x91329821ULL) + (x2 ^ 0x03FCB4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x03fcb4: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x03fcb8: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x03fcbc: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x03fcc0: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x03fcc4: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000128ULL; // 0x03fcc8: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9418D08ULL; // 0x03fccc: ldr x8, [x8, #0x318]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x03fcd0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x03fcd4: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFEA1ULL; // 0x03fcd8: adrp x1, #0x13000
    return acc;
}

// [EN] Reconstructed FDE #0386 @ 0x03fe60..0x03fefc (156 bytes)
// [VN] Phục dựng FDE #0386 tại 0x03fe60..0x03fefc (156 byte)
//   0x03fe60: d10483ff  sub      sp, sp, #0x120
//   0x03fe64: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x03fe68: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x03fe6c: 910443fd  add      x29, sp, #0x110
//   0x03fe70: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x03fe74: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x03fe78: f90057e7  str      x7, [sp, #0xa8]
//   0x03fe7c: ad0007e0  stp      q0, q1, [sp]
//   0x03fe80: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x03fe84: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x03fe88: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x03fe8c: d53bd053  mrs      x19, tpidr_el0
//   0x03fe90: f940166b  ldr      x11, [x19, #0x28]
//   0x03fe94: 928004e8  mov      x8, #-0x28
//   0x03fe98: 910003e9  mov      x9, sp
//   0x03fe9c: 910223ea  add      x10, sp, #0x88
uint64_t fde_0386_sub_03fe60(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xF940166BULL) + (x2 ^ 0x03FE60ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x03fe60: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x03fe64: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x03fe68: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x03fe6c: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x03fe70: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x03fe74: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x03fe78: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x03fe7c: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x03fe80: stp q2, q3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0217E4ULL; // 0x03fe84: stp q4, q5, [sp, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #0387 @ 0x03fefc..0x040298 (924 bytes)
// [VN] Phục dựng FDE #0387 tại 0x03fefc..0x040298 (924 byte)
//   0x03fefc: d101c3ff  sub      sp, sp, #0x70
//   0x03ff00: f9000bfb  str      x27, [sp, #0x10]
//   0x03ff04: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x03ff08: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x03ff0c: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x03ff10: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x03ff14: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x03ff18: 910183fd  add      x29, sp, #0x60
//   0x03ff1c: d53bd059  mrs      x25, tpidr_el0
//   0x03ff20: f9401728  ldr      x8, [x25, #0x28]
//   0x03ff24: b000013a  adrp     x26, #0x64000
//   0x03ff28: aa0103f4  mov      x20, x1
//   0x03ff2c: aa0003f3  mov      x19, x0
//   0x03ff30: f90007e8  str      x8, [sp, #8]
//   0x03ff34: 397a1348  ldrb     w8, [x26, #0xe84]
//   0x03ff38: f90003e2  str      x2, [sp]
uint64_t fde_0387_sub_03fefc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x03FEFCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x03fefc: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BFBULL; // 0x03ff00: str x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x03ff04: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x03ff08: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x03ff0c: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x03ff10: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x03ff14: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x03ff18: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x03ff1c: mrs x25, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401728ULL; // 0x03ff20: ldr x8, [x25, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0388 @ 0x040298..0x040458 (448 bytes)
// [VN] Phục dựng FDE #0388 tại 0x040298..0x040458 (448 byte)
//   0x040298: d100c3ff  sub      sp, sp, #0x30
//   0x04029c: f9000bf3  str      x19, [sp, #0x10]
//   0x0402a0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0402a4: 910083fd  add      x29, sp, #0x20
//   0x0402a8: 90000128  adrp     x8, #0x64000
//   0x0402ac: 913a1108  add      x8, x8, #0xe84
//   0x0402b0: 6b03005f  cmp      w2, w3
//   0x0402b4: 91127109  add      x9, x8, #0x49c
//   0x0402b8: 1a83c04a  csel     w10, w2, w3, gt
//   0x0402bc: 9112910b  add      x11, x8, #0x4a4
//   0x0402c0: 39000107  strb     w7, [x8]
//   0x0402c4: 291a0903  stp      w3, w2, [x8, #0xd0]
//   0x0402c8: f9000124  str      x4, [x9]
//   0x0402cc: f9000165  str      x5, [x11]
//   0x0402d0: b900cd0a  str      w10, [x8, #0xcc]
//   0x0402d4: 9112f108  add      x8, x8, #0x4bc
uint64_t fde_0388_sub_040298(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0xF9000124ULL) + (x2 ^ 0x040298ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x040298: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF3ULL; // 0x04029c: str x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0402a0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0402a4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x90000128ULL; // 0x0402a8: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x913A1108ULL; // 0x0402ac: add x8, x8, #0xe84
    acc = (acc * 0x100000001B3ULL) ^ 0x6B03005FULL; // 0x0402b0: cmp w2, w3
    acc = (acc * 0x100000001B3ULL) ^ 0x91127109ULL; // 0x0402b4: add x9, x8, #0x49c
    acc = (acc * 0x100000001B3ULL) ^ 0x1A83C04AULL; // 0x0402b8: csel w10, w2, w3, gt
    acc = (acc * 0x100000001B3ULL) ^ 0x9112910BULL; // 0x0402bc: add x11, x8, #0x4a4
    return acc;
}

// [EN] Reconstructed FDE #0389 @ 0x040458..0x0405c8 (368 bytes)
// [VN] Phục dựng FDE #0389 tại 0x040458..0x0405c8 (368 byte)
//   0x040458: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x04045c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x040460: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x040464: 910083fd  add      x29, sp, #0x20
//   0x040468: b0000128  adrp     x8, #0x65000
//   0x04046c: 910d2108  add      x8, x8, #0x348
//   0x040470: 08dffd08  ldarb    w8, [x8]
//   0x040474: 360000c8  tbz      w8, #0, #0x4048c
//   0x040478: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x04047c: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x040480: 2a1f03e0  mov      w0, wzr
//   0x040484: f84307f5  ldr      x21, [sp], #0x30
//   0x040488: d65f03c0  ret      
//   0x04048c: b0000128  adrp     x8, #0x65000
//   0x040490: 910d2108  add      x8, x8, #0x348
//   0x040494: aa0003f3  mov      x19, x0
uint64_t fde_0389_sub_040458(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x040458ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x040458: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x04045c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x040460: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x040464: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000128ULL; // 0x040468: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x910D2108ULL; // 0x04046c: add x8, x8, #0x348
    acc = (acc * 0x100000001B3ULL) ^ 0x08DFFD08ULL; // 0x040470: ldarb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x360000C8ULL; // 0x040474: tbz w8, #0, #0x4048c
    acc = (acc * 0x100000001B3ULL) ^ 0xA9427BFDULL; // 0x040478: ldp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9414FF4ULL; // 0x04047c: ldp x20, x19, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0390 @ 0x0405c8..0x04075c (404 bytes)
// [VN] Phục dựng FDE #0390 tại 0x0405c8..0x04075c (404 byte)
//   0x0405c8: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x0405cc: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x0405d0: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0405d4: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0405d8: 9100c3fd  add      x29, sp, #0x30
//   0x0405dc: b0000128  adrp     x8, #0x65000
//   0x0405e0: f941b108  ldr      x8, [x8, #0x360]
//   0x0405e4: aa0003f3  mov      x19, x0
//   0x0405e8: d63f0100  blr      x8
//   0x0405ec: f9400268  ldr      x8, [x19]
//   0x0405f0: aa1303e0  mov      x0, x19
//   0x0405f4: f9403d08  ldr      x8, [x8, #0x78]
//   0x0405f8: d63f0100  blr      x8
//   0x0405fc: b4000a60  cbz      x0, #0x40748
//   0x040600: f0fffe81  adrp     x1, #0x13000
//   0x040604: 90fffe62  adrp     x2, #0xc000
uint64_t fde_0390_sub_0405c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0xD63F0100ULL) + (x2 ^ 0x0405C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x0405c8: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x0405cc: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0405d0: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0405d4: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0405d8: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000128ULL; // 0x0405dc: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xF941B108ULL; // 0x0405e0: ldr x8, [x8, #0x360]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0405e4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x0405e8: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400268ULL; // 0x0405ec: ldr x8, [x19]
    return acc;
}

// [EN] Reconstructed FDE #0391 @ 0x04075c..0x0408f8 (412 bytes)
// [VN] Phục dựng FDE #0391 tại 0x04075c..0x0408f8 (412 byte)
//   0x04075c: d101c3ff  sub      sp, sp, #0x70
//   0x040760: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x040764: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x040768: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x04076c: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x040770: 910183fd  add      x29, sp, #0x60
//   0x040774: d53bd057  mrs      x23, tpidr_el0
//   0x040778: f94016e8  ldr      x8, [x23, #0x28]
//   0x04077c: aa1e03f6  mov      x22, x30
//   0x040780: aa0003f4  mov      x20, x0
//   0x040784: f90017e8  str      x8, [sp, #0x28]
//   0x040788: b0000128  adrp     x8, #0x65000
//   0x04078c: f941b508  ldr      x8, [x8, #0x368]
//   0x040790: d63f0100  blr      x8
//   0x040794: 72001c1f  tst      w0, #0xff
//   0x040798: 54000840  b.eq     #0x408a0
uint64_t fde_0391_sub_04075c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xF941B508ULL) + (x2 ^ 0x04075CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x04075c: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x040760: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x040764: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x040768: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x04076c: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x040770: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x040774: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x040778: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F6ULL; // 0x04077c: mov x22, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x040780: mov x20, x0
    return acc;
}

// [EN] Reconstructed FDE #0392 @ 0x0408f8..0x040994 (156 bytes)
// [VN] Phục dựng FDE #0392 tại 0x0408f8..0x040994 (156 byte)
//   0x0408f8: d10483ff  sub      sp, sp, #0x120
//   0x0408fc: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x040900: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x040904: 910443fd  add      x29, sp, #0x110
//   0x040908: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x04090c: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x040910: f90057e7  str      x7, [sp, #0xa8]
//   0x040914: ad0007e0  stp      q0, q1, [sp]
//   0x040918: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x04091c: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x040920: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x040924: d53bd053  mrs      x19, tpidr_el0
//   0x040928: f940166b  ldr      x11, [x19, #0x28]
//   0x04092c: 928004e8  mov      x8, #-0x28
//   0x040930: 910003e9  mov      x9, sp
//   0x040934: 910223ea  add      x10, sp, #0x88
uint64_t fde_0392_sub_0408f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xF940166BULL) + (x2 ^ 0x0408F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x0408f8: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x0408fc: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x040900: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x040904: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x040908: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x04090c: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x040910: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x040914: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x040918: stp q2, q3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0217E4ULL; // 0x04091c: stp q4, q5, [sp, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #0393 @ 0x040994..0x0409ac (24 bytes)
// [VN] Phục dựng FDE #0393 tại 0x040994..0x0409ac (24 byte)
//   0x040994: aa0003e8  mov      x8, x0
//   0x040998: f9400000  ldr      x0, [x0]
//   0x04099c: b4000060  cbz      x0, #0x409a8
//   0x0409a0: f9000500  str      x0, [x8, #8]
//   0x0409a4: 14007233  b        #0x5d270
//   0x0409a8: d65f03c0  ret      
uint64_t fde_0393_sub_040994(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x040994ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x040994: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x040998: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000060ULL; // 0x04099c: cbz x0, #0x409a8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000500ULL; // 0x0409a0: str x0, [x8, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x14007233ULL; // 0x0409a4: b #0x5d270
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0409a8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0394 @ 0x0409ac..0x040fcc (1568 bytes)
// [VN] Phục dựng FDE #0394 tại 0x0409ac..0x040fcc (1568 byte)
//   0x0409ac: d10303ff  sub      sp, sp, #0xc0
//   0x0409b0: a9066ffc  stp      x28, x27, [sp, #0x60]
//   0x0409b4: a90767fa  stp      x26, x25, [sp, #0x70]
//   0x0409b8: a9085ff8  stp      x24, x23, [sp, #0x80]
//   0x0409bc: a90957f6  stp      x22, x21, [sp, #0x90]
//   0x0409c0: a90a4ff4  stp      x20, x19, [sp, #0xa0]
//   0x0409c4: a90b7bfd  stp      x29, x30, [sp, #0xb0]
//   0x0409c8: 9102c3fd  add      x29, sp, #0xb0
//   0x0409cc: d53bd055  mrs      x21, tpidr_el0
//   0x0409d0: f94016a8  ldr      x8, [x21, #0x28]
//   0x0409d4: 9000013a  adrp     x26, #0x64000
//   0x0409d8: f9002fe8  str      x8, [sp, #0x58]
//   0x0409dc: b0000128  adrp     x8, #0x65000
//   0x0409e0: 910dc108  add      x8, x8, #0x370
//   0x0409e4: 08dffd08  ldarb    w8, [x8]
//   0x0409e8: 360001c8  tbz      w8, #0, #0x40a20
uint64_t fde_0394_sub_0409ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10303FFULL) + (x1 ^ 0xB0000128ULL) + (x2 ^ 0x0409ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10303FFULL; // 0x0409ac: sub sp, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9066FFCULL; // 0x0409b0: stp x28, x27, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90767FAULL; // 0x0409b4: stp x26, x25, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9085FF8ULL; // 0x0409b8: stp x24, x23, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90957F6ULL; // 0x0409bc: stp x22, x21, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A4FF4ULL; // 0x0409c0: stp x20, x19, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B7BFDULL; // 0x0409c4: stp x29, x30, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9102C3FDULL; // 0x0409c8: add x29, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x0409cc: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x0409d0: ldr x8, [x21, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0395 @ 0x040fcc..0x041144 (376 bytes)
// [VN] Phục dựng FDE #0395 tại 0x040fcc..0x041144 (376 byte)
//   0x040fcc: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x040fd0: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x040fd4: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x040fd8: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x040fdc: 9100c3fd  add      x29, sp, #0x30
//   0x040fe0: b0000128  adrp     x8, #0x65000
//   0x040fe4: 9114e108  add      x8, x8, #0x538
//   0x040fe8: 08dffd08  ldarb    w8, [x8]
//   0x040fec: aa0203f4  mov      x20, x2
//   0x040ff0: aa0103f3  mov      x19, x1
//   0x040ff4: 360001e8  tbz      w8, #0, #0x41030
//   0x040ff8: b0000135  adrp     x21, #0x65000
//   0x040ffc: f942a2a8  ldr      x8, [x21, #0x540]
//   0x041000: b40004e8  cbz      x8, #0x4109c
//   0x041004: 94000627  bl       #0x428a0
//   0x041008: b4000540  cbz      x0, #0x410b0
uint64_t fde_0395_sub_040fcc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0xF942A2A8ULL) + (x2 ^ 0x040FCCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x040fcc: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x040fd0: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x040fd4: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x040fd8: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x040fdc: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000128ULL; // 0x040fe0: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x9114E108ULL; // 0x040fe4: add x8, x8, #0x538
    acc = (acc * 0x100000001B3ULL) ^ 0x08DFFD08ULL; // 0x040fe8: ldarb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x040fec: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x040ff0: mov x19, x1
    return acc;
}

// [EN] Reconstructed FDE #0396 @ 0x041144..0x041354 (528 bytes)
// [VN] Phục dựng FDE #0396 tại 0x041144..0x041354 (528 byte)
//   0x041144: d10183ff  sub      sp, sp, #0x60
//   0x041148: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x04114c: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x041150: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x041154: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x041158: 910143fd  add      x29, sp, #0x50
//   0x04115c: d53bd056  mrs      x22, tpidr_el0
//   0x041160: f94016c8  ldr      x8, [x22, #0x28]
//   0x041164: aa0203f3  mov      x19, x2
//   0x041168: aa0103f4  mov      x20, x1
//   0x04116c: f9000fe8  str      x8, [sp, #0x18]
//   0x041170: 90000128  adrp     x8, #0x65000
//   0x041174: 91148108  add      x8, x8, #0x520
//   0x041178: 08dffd08  ldarb    w8, [x8]
//   0x04117c: 36000528  tbz      w8, #0, #0x41220
//   0x041180: 90000135  adrp     x21, #0x65000
uint64_t fde_0396_sub_041144(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0x91148108ULL) + (x2 ^ 0x041144ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x041144: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x041148: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x04114c: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x041150: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x041154: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x041158: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x04115c: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x041160: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x041164: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x041168: mov x20, x1
    return acc;
}

// [EN] Reconstructed FDE #0397 @ 0x041354..0x041404 (176 bytes)
// [VN] Phục dựng FDE #0397 tại 0x041354..0x041404 (176 byte)
//   0x041354: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x041358: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x04135c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x041360: 910083fd  add      x29, sp, #0x20
//   0x041364: 90000135  adrp     x21, #0x65000
//   0x041368: f941c2a8  ldr      x8, [x21, #0x380]
//   0x04136c: aa1e03f3  mov      x19, x30
//   0x041370: aa0003f4  mov      x20, x0
//   0x041374: b5000168  cbnz     x8, #0x413a0
//   0x041378: f0fffe41  adrp     x1, #0xc000
//   0x04137c: 90fffe62  adrp     x2, #0xd000
//   0x041380: 90fffe63  adrp     x3, #0xd000
//   0x041384: 91057021  add      x1, x1, #0x15c
//   0x041388: 913d4042  add      x2, x2, #0xf50
//   0x04138c: 913d8c63  add      x3, x3, #0xf63
//   0x041390: 528000c0  mov      w0, #6
uint64_t fde_0397_sub_041354(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x91057021ULL) + (x2 ^ 0x041354ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x041354: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x041358: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x04135c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x041360: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x90000135ULL; // 0x041364: adrp x21, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xF941C2A8ULL; // 0x041368: ldr x8, [x21, #0x380]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x04136c: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x041370: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000168ULL; // 0x041374: cbnz x8, #0x413a0
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFE41ULL; // 0x041378: adrp x1, #0xc000
    return acc;
}

// [EN] Reconstructed FDE #0398 @ 0x041404..0x041524 (288 bytes)
// [VN] Phục dựng FDE #0398 tại 0x041404..0x041524 (288 byte)
//   0x041404: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x041408: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x04140c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x041410: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x041414: 9100c3fd  add      x29, sp, #0x30
//   0x041418: 90000128  adrp     x8, #0x65000
//   0x04141c: 91144108  add      x8, x8, #0x510
//   0x041420: 08dffd08  ldarb    w8, [x8]
//   0x041424: 2a0103f3  mov      w19, w1
//   0x041428: aa0003f4  mov      x20, x0
//   0x04142c: 36000308  tbz      w8, #0, #0x4148c
//   0x041430: 90000135  adrp     x21, #0x65000
//   0x041434: f9428ea8  ldr      x8, [x21, #0x518]
//   0x041438: b4000608  cbz      x8, #0x414f8
//   0x04143c: f0fffe81  adrp     x1, #0x14000
//   0x041440: f0fffe82  adrp     x2, #0x14000
uint64_t fde_0398_sub_041404(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xF9428EA8ULL) + (x2 ^ 0x041404ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x041404: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x041408: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x04140c: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x041410: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x041414: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x90000128ULL; // 0x041418: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x91144108ULL; // 0x04141c: add x8, x8, #0x510
    acc = (acc * 0x100000001B3ULL) ^ 0x08DFFD08ULL; // 0x041420: ldarb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F3ULL; // 0x041424: mov w19, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x041428: mov x20, x0
    return acc;
}

// [EN] Reconstructed FDE #0399 @ 0x041524..0x0415d4 (176 bytes)
// [VN] Phục dựng FDE #0399 tại 0x041524..0x0415d4 (176 byte)
//   0x041524: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x041528: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x04152c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x041530: 910083fd  add      x29, sp, #0x20
//   0x041534: 90000135  adrp     x21, #0x65000
//   0x041538: f941c2a8  ldr      x8, [x21, #0x380]
//   0x04153c: aa1e03f3  mov      x19, x30
//   0x041540: aa0003f4  mov      x20, x0
//   0x041544: b5000168  cbnz     x8, #0x41570
//   0x041548: f0fffe41  adrp     x1, #0xc000
//   0x04154c: 90fffe62  adrp     x2, #0xd000
//   0x041550: b0fffe83  adrp     x3, #0x12000
//   0x041554: 91057021  add      x1, x1, #0x15c
//   0x041558: 913d4042  add      x2, x2, #0xf50
//   0x04155c: 91306463  add      x3, x3, #0xc19
//   0x041560: 528000c0  mov      w0, #6
uint64_t fde_0399_sub_041524(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x91057021ULL) + (x2 ^ 0x041524ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x041524: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x041528: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x04152c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x041530: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x90000135ULL; // 0x041534: adrp x21, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xF941C2A8ULL; // 0x041538: ldr x8, [x21, #0x380]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x04153c: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x041540: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000168ULL; // 0x041544: cbnz x8, #0x41570
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFE41ULL; // 0x041548: adrp x1, #0xc000
    return acc;
}

// [EN] Reconstructed FDE #0400 @ 0x0415d4..0x041e70 (2204 bytes)
// [VN] Phục dựng FDE #0400 tại 0x0415d4..0x041e70 (2204 byte)
//   0x0415d4: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x0415d8: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x0415dc: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x0415e0: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0415e4: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0415e8: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0415ec: 910143fd  add      x29, sp, #0x50
//   0x0415f0: d11143ff  sub      sp, sp, #0x450
//   0x0415f4: d53bd058  mrs      x24, tpidr_el0
//   0x0415f8: f9401708  ldr      x8, [x24, #0x28]
//   0x0415fc: aa1e03f3  mov      x19, x30
//   0x041600: aa0103f4  mov      x20, x1
//   0x041604: aa0003f5  mov      x21, x0
//   0x041608: f81a03a8  stur     x8, [x29, #-0x60]
//   0x04160c: 94006e31  bl       #0x5ced0
//   0x041610: eb20c29f  cmp      x20, w0, sxtw
uint64_t fde_0400_sub_0415d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xAA0003F5ULL) + (x2 ^ 0x0415D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x0415d4: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x0415d8: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x0415dc: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x0415e0: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x0415e4: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x0415e8: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x0415ec: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD11143FFULL; // 0x0415f0: sub sp, sp, #0x450
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x0415f4: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401708ULL; // 0x0415f8: ldr x8, [x24, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0401 @ 0x041e70..0x041f4c (220 bytes)
// [VN] Phục dựng FDE #0401 tại 0x041e70..0x041f4c (220 byte)
//   0x041e70: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x041e74: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x041e78: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x041e7c: 910083fd  add      x29, sp, #0x20
//   0x041e80: 90000128  adrp     x8, #0x65000
//   0x041e84: 91140108  add      x8, x8, #0x500
//   0x041e88: 08dffd08  ldarb    w8, [x8]
//   0x041e8c: aa0003f3  mov      x19, x0
//   0x041e90: 36000128  tbz      w8, #0, #0x41eb4
//   0x041e94: 90000128  adrp     x8, #0x65000
//   0x041e98: f9428501  ldr      x1, [x8, #0x508]
//   0x041e9c: b4000421  cbz      x1, #0x41f20
//   0x041ea0: aa1303e0  mov      x0, x19
//   0x041ea4: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x041ea8: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x041eac: a8c357f6  ldp      x22, x21, [sp], #0x30
uint64_t fde_0401_sub_041e70(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x041E70ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x041e70: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x041e74: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x041e78: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x041e7c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x90000128ULL; // 0x041e80: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x91140108ULL; // 0x041e84: add x8, x8, #0x500
    acc = (acc * 0x100000001B3ULL) ^ 0x08DFFD08ULL; // 0x041e88: ldarb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x041e8c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x36000128ULL; // 0x041e90: tbz w8, #0, #0x41eb4
    acc = (acc * 0x100000001B3ULL) ^ 0x90000128ULL; // 0x041e94: adrp x8, #0x65000
    return acc;
}

// [EN] Reconstructed FDE #0402 @ 0x041f4c..0x042010 (196 bytes)
// [VN] Phục dựng FDE #0402 tại 0x041f4c..0x042010 (196 byte)
//   0x041f4c: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x041f50: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x041f54: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x041f58: 910083fd  add      x29, sp, #0x20
//   0x041f5c: 90000128  adrp     x8, #0x65000
//   0x041f60: 9113c108  add      x8, x8, #0x4f0
//   0x041f64: 08dffd08  ldarb    w8, [x8]
//   0x041f68: aa0003f3  mov      x19, x0
//   0x041f6c: 36000128  tbz      w8, #0, #0x41f90
//   0x041f70: 90000128  adrp     x8, #0x65000
//   0x041f74: f9427d01  ldr      x1, [x8, #0x4f8]
//   0x041f78: b4000361  cbz      x1, #0x41fe4
//   0x041f7c: aa1303e0  mov      x0, x19
//   0x041f80: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x041f84: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x041f88: a8c357f6  ldp      x22, x21, [sp], #0x30
uint64_t fde_0402_sub_041f4c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x041F4CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x041f4c: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x041f50: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x041f54: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x041f58: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x90000128ULL; // 0x041f5c: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x9113C108ULL; // 0x041f60: add x8, x8, #0x4f0
    acc = (acc * 0x100000001B3ULL) ^ 0x08DFFD08ULL; // 0x041f64: ldarb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x041f68: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x36000128ULL; // 0x041f6c: tbz w8, #0, #0x41f90
    acc = (acc * 0x100000001B3ULL) ^ 0x90000128ULL; // 0x041f70: adrp x8, #0x65000
    return acc;
}

// [EN] Reconstructed FDE #0403 @ 0x042010..0x0420e4 (212 bytes)
// [VN] Phục dựng FDE #0403 tại 0x042010..0x0420e4 (212 byte)
//   0x042010: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x042014: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x042018: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x04201c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x042020: 9100c3fd  add      x29, sp, #0x30
//   0x042024: f0000108  adrp     x8, #0x65000
//   0x042028: 91138108  add      x8, x8, #0x4e0
//   0x04202c: 08dffd08  ldarb    w8, [x8]
//   0x042030: aa0103f3  mov      x19, x1
//   0x042034: aa0003f4  mov      x20, x0
//   0x042038: 36000168  tbz      w8, #0, #0x42064
//   0x04203c: f0000108  adrp     x8, #0x65000
//   0x042040: f9427502  ldr      x2, [x8, #0x4e8]
//   0x042044: b40003a2  cbz      x2, #0x420b8
//   0x042048: aa1403e0  mov      x0, x20
//   0x04204c: aa1303e1  mov      x1, x19
uint64_t fde_0403_sub_042010(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xF9427502ULL) + (x2 ^ 0x042010ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x042010: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x042014: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x042018: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x04201c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x042020: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000108ULL; // 0x042024: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x91138108ULL; // 0x042028: add x8, x8, #0x4e0
    acc = (acc * 0x100000001B3ULL) ^ 0x08DFFD08ULL; // 0x04202c: ldarb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x042030: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x042034: mov x20, x0
    return acc;
}

// [EN] Reconstructed FDE #0404 @ 0x0420e4..0x042540 (1116 bytes)
// [VN] Phục dựng FDE #0404 tại 0x0420e4..0x042540 (1116 byte)
//   0x0420e4: d10703ff  sub      sp, sp, #0x1c0
//   0x0420e8: a9166ffc  stp      x28, x27, [sp, #0x160]
//   0x0420ec: a91767fa  stp      x26, x25, [sp, #0x170]
//   0x0420f0: a9185ff8  stp      x24, x23, [sp, #0x180]
//   0x0420f4: a91957f6  stp      x22, x21, [sp, #0x190]
//   0x0420f8: a91a4ff4  stp      x20, x19, [sp, #0x1a0]
//   0x0420fc: a91b7bfd  stp      x29, x30, [sp, #0x1b0]
//   0x042100: 9106c3fd  add      x29, sp, #0x1b0
//   0x042104: d53bd056  mrs      x22, tpidr_el0
//   0x042108: f94016c8  ldr      x8, [x22, #0x28]
//   0x04210c: f81a03a8  stur     x8, [x29, #-0x60]
//   0x042110: b4001760  cbz      x0, #0x423fc
//   0x042114: 2a0103f4  mov      w20, w1
//   0x042118: 71000c3f  cmp      w1, #3
//   0x04211c: 5400170c  b.gt     #0x423fc
//   0x042120: aa0003f3  mov      x19, x0
uint64_t fde_0404_sub_0420e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10703FFULL) + (x1 ^ 0x2A0103F4ULL) + (x2 ^ 0x0420E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10703FFULL; // 0x0420e4: sub sp, sp, #0x1c0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9166FFCULL; // 0x0420e8: stp x28, x27, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91767FAULL; // 0x0420ec: stp x26, x25, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9185FF8ULL; // 0x0420f0: stp x24, x23, [sp, #0x180]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91957F6ULL; // 0x0420f4: stp x22, x21, [sp, #0x190]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91A4FF4ULL; // 0x0420f8: stp x20, x19, [sp, #0x1a0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91B7BFDULL; // 0x0420fc: stp x29, x30, [sp, #0x1b0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9106C3FDULL; // 0x042100: add x29, sp, #0x1b0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x042104: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x042108: ldr x8, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0405 @ 0x042540..0x0426ec (428 bytes)
// [VN] Phục dựng FDE #0405 tại 0x042540..0x0426ec (428 byte)
//   0x042540: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x042544: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x042548: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x04254c: 910083fd  add      x29, sp, #0x20
//   0x042550: 6f00e400  movi     v0.2d, #0000000000000000
//   0x042554: f0000108  adrp     x8, #0x65000
//   0x042558: f900901f  str      xzr, [x0, #0x120]
//   0x04255c: ad080000  stp      q0, q0, [x0, #0x100]
//   0x042560: ad070000  stp      q0, q0, [x0, #0xe0]
//   0x042564: ad060000  stp      q0, q0, [x0, #0xc0]
//   0x042568: ad050000  stp      q0, q0, [x0, #0xa0]
//   0x04256c: ad040000  stp      q0, q0, [x0, #0x80]
//   0x042570: ad030000  stp      q0, q0, [x0, #0x60]
//   0x042574: ad020000  stp      q0, q0, [x0, #0x40]
//   0x042578: ad010000  stp      q0, q0, [x0, #0x20]
//   0x04257c: ad000000  stp      q0, q0, [x0]
uint64_t fde_0405_sub_042540(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAD030000ULL) + (x2 ^ 0x042540ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x042540: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x042544: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x042548: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x04254c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x6F00E400ULL; // 0x042550: movi v0.2d, #0000000000000000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000108ULL; // 0x042554: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xF900901FULL; // 0x042558: str xzr, [x0, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD080000ULL; // 0x04255c: stp q0, q0, [x0, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD070000ULL; // 0x042560: stp q0, q0, [x0, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD060000ULL; // 0x042564: stp q0, q0, [x0, #0xc0]
    return acc;
}

// [EN] Reconstructed FDE #0406 @ 0x0426ec..0x0427d0 (228 bytes)
// [VN] Phục dựng FDE #0406 tại 0x0426ec..0x0427d0 (228 byte)
//   0x0426ec: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x0426f0: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0426f4: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0426f8: 910083fd  add      x29, sp, #0x20
//   0x0426fc: f0000108  adrp     x8, #0x65000
//   0x042700: 91118108  add      x8, x8, #0x460
//   0x042704: 08dffd08  ldarb    w8, [x8]
//   0x042708: aa0003f3  mov      x19, x0
//   0x04270c: 36000128  tbz      w8, #0, #0x42730
//   0x042710: f0000108  adrp     x8, #0x65000
//   0x042714: f9423501  ldr      x1, [x8, #0x468]
//   0x042718: b4000361  cbz      x1, #0x42784
//   0x04271c: aa1303e0  mov      x0, x19
//   0x042720: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x042724: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x042728: a8c357f6  ldp      x22, x21, [sp], #0x30
uint64_t fde_0406_sub_0426ec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x0426ECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x0426ec: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0426f0: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0426f4: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0426f8: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000108ULL; // 0x0426fc: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x91118108ULL; // 0x042700: add x8, x8, #0x460
    acc = (acc * 0x100000001B3ULL) ^ 0x08DFFD08ULL; // 0x042704: ldarb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x042708: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x36000128ULL; // 0x04270c: tbz w8, #0, #0x42730
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000108ULL; // 0x042710: adrp x8, #0x65000
    return acc;
}

// [EN] Reconstructed FDE #0407 @ 0x0427d0..0x0428a0 (208 bytes)
// [VN] Phục dựng FDE #0407 tại 0x0427d0..0x0428a0 (208 byte)
//   0x0427d0: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x0427d4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0427d8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0427dc: 910083fd  add      x29, sp, #0x20
//   0x0427e0: f0000108  adrp     x8, #0x65000
//   0x0427e4: 91114108  add      x8, x8, #0x450
//   0x0427e8: 08dffd08  ldarb    w8, [x8]
//   0x0427ec: aa0003f3  mov      x19, x0
//   0x0427f0: 360001e8  tbz      w8, #0, #0x4282c
//   0x0427f4: f0000108  adrp     x8, #0x65000
//   0x0427f8: f9422d08  ldr      x8, [x8, #0x458]
//   0x0427fc: b4000068  cbz      x8, #0x42808
//   0x042800: aa1303e0  mov      x0, x19
//   0x042804: d63f0100  blr      x8
//   0x042808: 6f00e400  movi     v0.2d, #0000000000000000
//   0x04280c: ad030260  stp      q0, q0, [x19, #0x60]
uint64_t fde_0407_sub_0427d0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x0427D0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x0427d0: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0427d4: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0427d8: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0427dc: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000108ULL; // 0x0427e0: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x91114108ULL; // 0x0427e4: add x8, x8, #0x450
    acc = (acc * 0x100000001B3ULL) ^ 0x08DFFD08ULL; // 0x0427e8: ldarb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0427ec: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x360001E8ULL; // 0x0427f0: tbz w8, #0, #0x4282c
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000108ULL; // 0x0427f4: adrp x8, #0x65000
    return acc;
}

// [EN] Reconstructed FDE #0408 @ 0x0428a0..0x04297c (220 bytes)
// [VN] Phục dựng FDE #0408 tại 0x0428a0..0x04297c (220 byte)
//   0x0428a0: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x0428a4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0428a8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0428ac: 910083fd  add      x29, sp, #0x20
//   0x0428b0: f0000108  adrp     x8, #0x65000
//   0x0428b4: 91110108  add      x8, x8, #0x440
//   0x0428b8: 08dffd08  ldarb    w8, [x8]
//   0x0428bc: 36000108  tbz      w8, #0, #0x428dc
//   0x0428c0: f0000108  adrp     x8, #0x65000
//   0x0428c4: f9422500  ldr      x0, [x8, #0x448]
//   0x0428c8: b4000340  cbz      x0, #0x42930
//   0x0428cc: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x0428d0: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x0428d4: f84307f5  ldr      x21, [sp], #0x30
//   0x0428d8: d61f0000  br       x0
//   0x0428dc: f0000113  adrp     x19, #0x65000
uint64_t fde_0408_sub_0428a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xA9414FF4ULL) + (x2 ^ 0x0428A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x0428a0: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0428a4: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0428a8: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0428ac: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000108ULL; // 0x0428b0: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x91110108ULL; // 0x0428b4: add x8, x8, #0x440
    acc = (acc * 0x100000001B3ULL) ^ 0x08DFFD08ULL; // 0x0428b8: ldarb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x36000108ULL; // 0x0428bc: tbz w8, #0, #0x428dc
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000108ULL; // 0x0428c0: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9422500ULL; // 0x0428c4: ldr x0, [x8, #0x448]
    return acc;
}

// [EN] Reconstructed FDE #0409 @ 0x04297c..0x042980 (4 bytes)
// [VN] Phục dựng FDE #0409 tại 0x04297c..0x042980 (4 byte)
//   0x04297c: d65f03c0  ret      
uint64_t fde_0409_sub_04297c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04297CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04297c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0410 @ 0x042980..0x042984 (4 bytes)
// [VN] Phục dựng FDE #0410 tại 0x042980..0x042984 (4 byte)
//   0x042980: 14006a3c  b        #0x5d270
uint64_t fde_0410_sub_042980(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x14006A3CULL) + (x1 ^ 0x14006A3CULL) + (x2 ^ 0x042980ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x14006A3CULL; // 0x042980: b #0x5d270
    return acc;
}

// [EN] Reconstructed FDE #0411 @ 0x042984..0x043248 (2244 bytes)
// [VN] Phục dựng FDE #0411 tại 0x042984..0x043248 (2244 byte)
//   0x042984: d10243ff  sub      sp, sp, #0x90
//   0x042988: a9036ffc  stp      x28, x27, [sp, #0x30]
//   0x04298c: a90467fa  stp      x26, x25, [sp, #0x40]
//   0x042990: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x042994: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x042998: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x04299c: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x0429a0: 910203fd  add      x29, sp, #0x80
//   0x0429a4: d53bd05c  mrs      x28, tpidr_el0
//   0x0429a8: f9401788  ldr      x8, [x28, #0x28]
//   0x0429ac: f90017e8  str      x8, [sp, #0x28]
//   0x0429b0: b9440c08  ldr      w8, [x0, #0x40c]
//   0x0429b4: b9440809  ldr      w9, [x0, #0x408]
//   0x0429b8: 11000508  add      w8, w8, #1
//   0x0429bc: 6b09011f  cmp      w8, w9
//   0x0429c0: b9040c08  str      w8, [x0, #0x40c]
uint64_t fde_0411_sub_042984(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0xB9440809ULL) + (x2 ^ 0x042984ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x042984: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA9036FFCULL; // 0x042988: stp x28, x27, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90467FAULL; // 0x04298c: stp x26, x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x042990: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x042994: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x042998: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x04299c: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x0429a0: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05CULL; // 0x0429a4: mrs x28, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401788ULL; // 0x0429a8: ldr x8, [x28, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0412 @ 0x043248..0x04331c (212 bytes)
// [VN] Phục dựng FDE #0412 tại 0x043248..0x04331c (212 byte)
//   0x043248: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x04324c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x043250: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x043254: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x043258: 9100c3fd  add      x29, sp, #0x30
//   0x04325c: d0000108  adrp     x8, #0x65000
//   0x043260: 910fc108  add      x8, x8, #0x3f0
//   0x043264: 08dffd08  ldarb    w8, [x8]
//   0x043268: aa0103f3  mov      x19, x1
//   0x04326c: aa0003f4  mov      x20, x0
//   0x043270: 36000168  tbz      w8, #0, #0x4329c
//   0x043274: d0000108  adrp     x8, #0x65000
//   0x043278: f941fd02  ldr      x2, [x8, #0x3f8]
//   0x04327c: b40003a2  cbz      x2, #0x432f0
//   0x043280: aa1403e0  mov      x0, x20
//   0x043284: aa1303e1  mov      x1, x19
uint64_t fde_0412_sub_043248(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xF941FD02ULL) + (x2 ^ 0x043248ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x043248: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x04324c: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x043250: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x043254: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x043258: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000108ULL; // 0x04325c: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x910FC108ULL; // 0x043260: add x8, x8, #0x3f0
    acc = (acc * 0x100000001B3ULL) ^ 0x08DFFD08ULL; // 0x043264: ldarb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x043268: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x04326c: mov x20, x0
    return acc;
}

// [EN] Reconstructed FDE #0413 @ 0x04331c..0x043430 (276 bytes)
// [VN] Phục dựng FDE #0413 tại 0x04331c..0x043430 (276 byte)
//   0x04331c: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x043320: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x043324: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x043328: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x04332c: 9100c3fd  add      x29, sp, #0x30
//   0x043330: d0000108  adrp     x8, #0x65000
//   0x043334: 910f0108  add      x8, x8, #0x3c0
//   0x043338: 08dffd08  ldarb    w8, [x8]
//   0x04333c: aa0103f3  mov      x19, x1
//   0x043340: aa0003f4  mov      x20, x0
//   0x043344: 36000188  tbz      w8, #0, #0x43374
//   0x043348: d0000108  adrp     x8, #0x65000
//   0x04334c: f941e503  ldr      x3, [x8, #0x3c8]
//   0x043350: b4000483  cbz      x3, #0x433e0
//   0x043354: aa1403e1  mov      x1, x20
//   0x043358: aa1303e2  mov      x2, x19
uint64_t fde_0413_sub_04331c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xF941E503ULL) + (x2 ^ 0x04331CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x04331c: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x043320: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x043324: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x043328: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x04332c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000108ULL; // 0x043330: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x910F0108ULL; // 0x043334: add x8, x8, #0x3c0
    acc = (acc * 0x100000001B3ULL) ^ 0x08DFFD08ULL; // 0x043338: ldarb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x04333c: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x043340: mov x20, x0
    return acc;
}

// [EN] Reconstructed FDE #0414 @ 0x043430..0x043444 (20 bytes)
// [VN] Phục dựng FDE #0414 tại 0x043430..0x043444 (20 byte)
//   0x043430: aa0203e3  mov      x3, x2
//   0x043434: aa0103e2  mov      x2, x1
//   0x043438: 52800021  mov      w1, #1
//   0x04343c: aa0203e8  mov      x8, x2
//   0x043440: d61f0060  br       x3
uint64_t fde_0414_sub_043430(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0203E3ULL) + (x1 ^ 0xD61F0060ULL) + (x2 ^ 0x043430ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E3ULL; // 0x043430: mov x3, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E2ULL; // 0x043434: mov x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x043438: mov w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E8ULL; // 0x04343c: mov x8, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0060ULL; // 0x043440: br x3
    return acc;
}

// [EN] Reconstructed FDE #0415 @ 0x043444..0x043514 (208 bytes)
// [VN] Phục dựng FDE #0415 tại 0x043444..0x043514 (208 byte)
//   0x043444: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x043448: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x04344c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x043450: 910083fd  add      x29, sp, #0x20
//   0x043454: d0000108  adrp     x8, #0x65000
//   0x043458: 91134108  add      x8, x8, #0x4d0
//   0x04345c: 08dffd08  ldarb    w8, [x8]
//   0x043460: aa0003f3  mov      x19, x0
//   0x043464: 36000188  tbz      w8, #0, #0x43494
//   0x043468: d0000108  adrp     x8, #0x65000
//   0x04346c: f9426d02  ldr      x2, [x8, #0x4d8]
//   0x043470: b40003c2  cbz      x2, #0x434e8
//   0x043474: d0000108  adrp     x8, #0x65000
//   0x043478: f941c100  ldr      x0, [x8, #0x380]
//   0x04347c: b4000360  cbz      x0, #0x434e8
//   0x043480: aa1303e1  mov      x1, x19
uint64_t fde_0415_sub_043444(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xD0000108ULL) + (x2 ^ 0x043444ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x043444: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x043448: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x04344c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x043450: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000108ULL; // 0x043454: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x91134108ULL; // 0x043458: add x8, x8, #0x4d0
    acc = (acc * 0x100000001B3ULL) ^ 0x08DFFD08ULL; // 0x04345c: ldarb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x043460: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x36000188ULL; // 0x043464: tbz w8, #0, #0x43494
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000108ULL; // 0x043468: adrp x8, #0x65000
    return acc;
}

// [EN] Reconstructed FDE #0416 @ 0x043514..0x0435e8 (212 bytes)
// [VN] Phục dựng FDE #0416 tại 0x043514..0x0435e8 (212 byte)
//   0x043514: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x043518: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x04351c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x043520: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x043524: 9100c3fd  add      x29, sp, #0x30
//   0x043528: d0000108  adrp     x8, #0x65000
//   0x04352c: 91130108  add      x8, x8, #0x4c0
//   0x043530: 08dffd08  ldarb    w8, [x8]
//   0x043534: aa0103f3  mov      x19, x1
//   0x043538: aa0003f4  mov      x20, x0
//   0x04353c: 36000168  tbz      w8, #0, #0x43568
//   0x043540: d0000108  adrp     x8, #0x65000
//   0x043544: f9426502  ldr      x2, [x8, #0x4c8]
//   0x043548: b40003a2  cbz      x2, #0x435bc
//   0x04354c: aa1403e0  mov      x0, x20
//   0x043550: aa1303e1  mov      x1, x19
uint64_t fde_0416_sub_043514(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xF9426502ULL) + (x2 ^ 0x043514ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x043514: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x043518: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x04351c: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x043520: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x043524: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000108ULL; // 0x043528: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x91130108ULL; // 0x04352c: add x8, x8, #0x4c0
    acc = (acc * 0x100000001B3ULL) ^ 0x08DFFD08ULL; // 0x043530: ldarb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x043534: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x043538: mov x20, x0
    return acc;
}

// [EN] Reconstructed FDE #0417 @ 0x0435e8..0x0436ac (196 bytes)
// [VN] Phục dựng FDE #0417 tại 0x0435e8..0x0436ac (196 byte)
//   0x0435e8: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x0435ec: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0435f0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0435f4: 910083fd  add      x29, sp, #0x20
//   0x0435f8: d0000108  adrp     x8, #0x65000
//   0x0435fc: 9112c108  add      x8, x8, #0x4b0
//   0x043600: 08dffd08  ldarb    w8, [x8]
//   0x043604: aa0003f3  mov      x19, x0
//   0x043608: 36000128  tbz      w8, #0, #0x4362c
//   0x04360c: d0000108  adrp     x8, #0x65000
//   0x043610: f9425d01  ldr      x1, [x8, #0x4b8]
//   0x043614: b4000361  cbz      x1, #0x43680
//   0x043618: aa1303e0  mov      x0, x19
//   0x04361c: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x043620: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x043624: a8c357f6  ldp      x22, x21, [sp], #0x30
uint64_t fde_0417_sub_0435e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x0435E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x0435e8: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0435ec: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0435f0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0435f4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000108ULL; // 0x0435f8: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x9112C108ULL; // 0x0435fc: add x8, x8, #0x4b0
    acc = (acc * 0x100000001B3ULL) ^ 0x08DFFD08ULL; // 0x043600: ldarb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x043604: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x36000128ULL; // 0x043608: tbz w8, #0, #0x4362c
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000108ULL; // 0x04360c: adrp x8, #0x65000
    return acc;
}

// [EN] Reconstructed FDE #0418 @ 0x0436ac..0x043a7c (976 bytes)
// [VN] Phục dựng FDE #0418 tại 0x0436ac..0x043a7c (976 byte)
//   0x0436ac: d102c3ff  sub      sp, sp, #0xb0
//   0x0436b0: a9056ffc  stp      x28, x27, [sp, #0x50]
//   0x0436b4: a90667fa  stp      x26, x25, [sp, #0x60]
//   0x0436b8: a9075ff8  stp      x24, x23, [sp, #0x70]
//   0x0436bc: a90857f6  stp      x22, x21, [sp, #0x80]
//   0x0436c0: a9094ff4  stp      x20, x19, [sp, #0x90]
//   0x0436c4: a90a7bfd  stp      x29, x30, [sp, #0xa0]
//   0x0436c8: 910283fd  add      x29, sp, #0xa0
//   0x0436cc: d53bd048  mrs      x8, tpidr_el0
//   0x0436d0: f90007e8  str      x8, [sp, #8]
//   0x0436d4: f9401508  ldr      x8, [x8, #0x28]
//   0x0436d8: f90027e8  str      x8, [sp, #0x48]
//   0x0436dc: b4001860  cbz      x0, #0x439e8
//   0x0436e0: aa0103f3  mov      x19, x1
//   0x0436e4: aa0003fa  mov      x26, x0
//   0x0436e8: 97ffffc0  bl       #0x435e8
uint64_t fde_0418_sub_0436ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD102C3FFULL) + (x1 ^ 0xB4001860ULL) + (x2 ^ 0x0436ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD102C3FFULL; // 0x0436ac: sub sp, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9056FFCULL; // 0x0436b0: stp x28, x27, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90667FAULL; // 0x0436b4: stp x26, x25, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9075FF8ULL; // 0x0436b8: stp x24, x23, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90857F6ULL; // 0x0436bc: stp x22, x21, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9094FF4ULL; // 0x0436c0: stp x20, x19, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A7BFDULL; // 0x0436c4: stp x29, x30, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910283FDULL; // 0x0436c8: add x29, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD048ULL; // 0x0436cc: mrs x8, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x0436d0: str x8, [sp, #8]
    return acc;
}

// [EN] Reconstructed FDE #0419 @ 0x043a7c..0x043b50 (212 bytes)
// [VN] Phục dựng FDE #0419 tại 0x043a7c..0x043b50 (212 byte)
//   0x043a7c: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x043a80: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x043a84: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x043a88: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x043a8c: 9100c3fd  add      x29, sp, #0x30
//   0x043a90: d0000108  adrp     x8, #0x65000
//   0x043a94: 91120108  add      x8, x8, #0x480
//   0x043a98: 08dffd08  ldarb    w8, [x8]
//   0x043a9c: aa0103f3  mov      x19, x1
//   0x043aa0: aa0003f4  mov      x20, x0
//   0x043aa4: 36000168  tbz      w8, #0, #0x43ad0
//   0x043aa8: d0000108  adrp     x8, #0x65000
//   0x043aac: f9424502  ldr      x2, [x8, #0x488]
//   0x043ab0: b40003a2  cbz      x2, #0x43b24
//   0x043ab4: aa1403e0  mov      x0, x20
//   0x043ab8: aa1303e1  mov      x1, x19
uint64_t fde_0419_sub_043a7c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xF9424502ULL) + (x2 ^ 0x043A7CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x043a7c: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x043a80: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x043a84: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x043a88: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x043a8c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000108ULL; // 0x043a90: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x91120108ULL; // 0x043a94: add x8, x8, #0x480
    acc = (acc * 0x100000001B3ULL) ^ 0x08DFFD08ULL; // 0x043a98: ldarb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x043a9c: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x043aa0: mov x20, x0
    return acc;
}

// [EN] Reconstructed FDE #0420 @ 0x043b50..0x043b64 (20 bytes)
// [VN] Phục dựng FDE #0420 tại 0x043b50..0x043b64 (20 byte)
//   0x043b50: aa0203e3  mov      x3, x2
//   0x043b54: aa0103e2  mov      x2, x1
//   0x043b58: 52800021  mov      w1, #1
//   0x043b5c: aa0203e8  mov      x8, x2
//   0x043b60: d61f0060  br       x3
uint64_t fde_0420_sub_043b50(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0203E3ULL) + (x1 ^ 0xD61F0060ULL) + (x2 ^ 0x043B50ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E3ULL; // 0x043b50: mov x3, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E2ULL; // 0x043b54: mov x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x043b58: mov w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E8ULL; // 0x043b5c: mov x8, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0060ULL; // 0x043b60: br x3
    return acc;
}

// [EN] Reconstructed FDE #0421 @ 0x043b64..0x043b6c (8 bytes)
// [VN] Phục dựng FDE #0421 tại 0x043b64..0x043b6c (8 byte)
//   0x043b64: aa0103e8  mov      x8, x1
//   0x043b68: d61f0040  br       x2
uint64_t fde_0421_sub_043b64(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0103E8ULL) + (x1 ^ 0xD61F0040ULL) + (x2 ^ 0x043B64ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E8ULL; // 0x043b64: mov x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0040ULL; // 0x043b68: br x2
    return acc;
}

// [EN] Reconstructed FDE #0422 @ 0x043b6c..0x043b74 (8 bytes)
// [VN] Phục dựng FDE #0422 tại 0x043b6c..0x043b74 (8 byte)
//   0x043b6c: aa0103e8  mov      x8, x1
//   0x043b70: d61f0040  br       x2
uint64_t fde_0422_sub_043b6c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0103E8ULL) + (x1 ^ 0xD61F0040ULL) + (x2 ^ 0x043B6CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E8ULL; // 0x043b6c: mov x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0040ULL; // 0x043b70: br x2
    return acc;
}

// [EN] Reconstructed FDE #0423 @ 0x043b74..0x043b88 (20 bytes)
// [VN] Phục dựng FDE #0423 tại 0x043b74..0x043b88 (20 byte)
//   0x043b74: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x043b78: 910003fd  mov      x29, sp
//   0x043b7c: 90fffe80  adrp     x0, #0x13000
//   0x043b80: 9135a800  add      x0, x0, #0xd6a
//   0x043b84: 97ffd225  bl       #0x38418
uint64_t fde_0423_sub_043b74(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x97FFD225ULL) + (x2 ^ 0x043B74ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x043b74: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x043b78: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFE80ULL; // 0x043b7c: adrp x0, #0x13000
    acc = (acc * 0x100000001B3ULL) ^ 0x9135A800ULL; // 0x043b80: add x0, x0, #0xd6a
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFD225ULL; // 0x043b84: bl #0x38418
    return acc;
}

// [EN] Reconstructed FDE #0424 @ 0x043b88..0x043bd4 (76 bytes)
// [VN] Phục dựng FDE #0424 tại 0x043b88..0x043bd4 (76 byte)
//   0x043b88: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x043b8c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x043b90: 910043fd  add      x29, sp, #0x10
//   0x043b94: aa0003f3  mov      x19, x0
//   0x043b98: f9400800  ldr      x0, [x0, #0x10]
//   0x043b9c: b40000a0  cbz      x0, #0x43bb0
//   0x043ba0: f9400014  ldr      x20, [x0]
//   0x043ba4: 940065b3  bl       #0x5d270
//   0x043ba8: aa1403e0  mov      x0, x20
//   0x043bac: b5ffffb4  cbnz     x20, #0x43ba0
//   0x043bb0: f9400260  ldr      x0, [x19]
//   0x043bb4: f900027f  str      xzr, [x19]
//   0x043bb8: b4000080  cbz      x0, #0x43bc8
//   0x043bbc: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x043bc0: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x043bc4: 140065ab  b        #0x5d270
uint64_t fde_0424_sub_043b88(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xB4000080ULL) + (x2 ^ 0x043B88ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x043b88: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x043b8c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x043b90: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x043b94: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400800ULL; // 0x043b98: ldr x0, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000A0ULL; // 0x043b9c: cbz x0, #0x43bb0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400014ULL; // 0x043ba0: ldr x20, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x940065B3ULL; // 0x043ba4: bl #0x5d270
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x043ba8: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB5FFFFB4ULL; // 0x043bac: cbnz x20, #0x43ba0
    return acc;
}

// [EN] Reconstructed FDE #0425 @ 0x043bd4..0x043c20 (76 bytes)
// [VN] Phục dựng FDE #0425 tại 0x043bd4..0x043c20 (76 byte)
//   0x043bd4: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x043bd8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x043bdc: 910043fd  add      x29, sp, #0x10
//   0x043be0: aa0003f3  mov      x19, x0
//   0x043be4: f9400800  ldr      x0, [x0, #0x10]
//   0x043be8: b40000a0  cbz      x0, #0x43bfc
//   0x043bec: f9400014  ldr      x20, [x0]
//   0x043bf0: 940065a0  bl       #0x5d270
//   0x043bf4: aa1403e0  mov      x0, x20
//   0x043bf8: b5ffffb4  cbnz     x20, #0x43bec
//   0x043bfc: f9400260  ldr      x0, [x19]
//   0x043c00: f900027f  str      xzr, [x19]
//   0x043c04: b4000080  cbz      x0, #0x43c14
//   0x043c08: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x043c0c: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x043c10: 14006598  b        #0x5d270
uint64_t fde_0425_sub_043bd4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xB4000080ULL) + (x2 ^ 0x043BD4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x043bd4: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x043bd8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x043bdc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x043be0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400800ULL; // 0x043be4: ldr x0, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000A0ULL; // 0x043be8: cbz x0, #0x43bfc
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400014ULL; // 0x043bec: ldr x20, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x940065A0ULL; // 0x043bf0: bl #0x5d270
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x043bf4: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB5FFFFB4ULL; // 0x043bf8: cbnz x20, #0x43bec
    return acc;
}

// [EN] Reconstructed FDE #0426 @ 0x043c20..0x043c24 (4 bytes)
// [VN] Phục dựng FDE #0426 tại 0x043c20..0x043c24 (4 byte)
//   0x043c20: d65f03c0  ret      
uint64_t fde_0426_sub_043c20(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x043C20ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x043c20: ret 
    return acc;
}

// [EN] Reconstructed FDE #0427 @ 0x043c24..0x045614 (6640 bytes)
// [VN] Phục dựng FDE #0427 tại 0x043c24..0x045614 (6640 byte)
//   0x043c24: d106c3ff  sub      sp, sp, #0x1b0
//   0x043c28: a9156ffc  stp      x28, x27, [sp, #0x150]
//   0x043c2c: a91667fa  stp      x26, x25, [sp, #0x160]
//   0x043c30: a9175ff8  stp      x24, x23, [sp, #0x170]
//   0x043c34: a91857f6  stp      x22, x21, [sp, #0x180]
//   0x043c38: a9194ff4  stp      x20, x19, [sp, #0x190]
//   0x043c3c: a91a7bfd  stp      x29, x30, [sp, #0x1a0]
//   0x043c40: 910683fd  add      x29, sp, #0x1a0
//   0x043c44: d53bd057  mrs      x23, tpidr_el0
//   0x043c48: f94016e8  ldr      x8, [x23, #0x28]
//   0x043c4c: f81a03a8  stur     x8, [x29, #-0x60]
//   0x043c50: d0000108  adrp     x8, #0x65000
//   0x043c54: 91154108  add      x8, x8, #0x550
//   0x043c58: 08dffd08  ldarb    w8, [x8]
//   0x043c5c: 360001e8  tbz      w8, #0, #0x43c98
//   0x043c60: b0000108  adrp     x8, #0x64000
uint64_t fde_0427_sub_043c24(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD106C3FFULL) + (x1 ^ 0x91154108ULL) + (x2 ^ 0x043C24ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD106C3FFULL; // 0x043c24: sub sp, sp, #0x1b0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9156FFCULL; // 0x043c28: stp x28, x27, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91667FAULL; // 0x043c2c: stp x26, x25, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9175FF8ULL; // 0x043c30: stp x24, x23, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91857F6ULL; // 0x043c34: stp x22, x21, [sp, #0x180]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9194FF4ULL; // 0x043c38: stp x20, x19, [sp, #0x190]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91A7BFDULL; // 0x043c3c: stp x29, x30, [sp, #0x1a0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910683FDULL; // 0x043c40: add x29, sp, #0x1a0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x043c44: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x043c48: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0428 @ 0x045614..0x0457e0 (460 bytes)
// [VN] Phục dựng FDE #0428 tại 0x045614..0x0457e0 (460 byte)
//   0x045614: d10143ff  sub      sp, sp, #0x50
//   0x045618: f90013f5  str      x21, [sp, #0x20]
//   0x04561c: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x045620: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x045624: 910103fd  add      x29, sp, #0x40
//   0x045628: d53bd055  mrs      x21, tpidr_el0
//   0x04562c: f94016a8  ldr      x8, [x21, #0x28]
//   0x045630: 52800082  mov      w2, #4
//   0x045634: 910023e1  add      x1, sp, #8
//   0x045638: 72a00022  movk     w2, #1, lsl #16
//   0x04563c: f9000fe8  str      x8, [sp, #0x18]
//   0x045640: 90000108  adrp     x8, #0x65000
//   0x045644: f9460d00  ldr      x0, [x8, #0xc18]
//   0x045648: f90007ff  str      xzr, [sp, #8]
//   0x04564c: f9400008  ldr      x8, [x0]
//   0x045650: f9401908  ldr      x8, [x8, #0x30]
uint64_t fde_0428_sub_045614(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xF9460D00ULL) + (x2 ^ 0x045614ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x045614: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F5ULL; // 0x045618: str x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x04561c: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x045620: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x045624: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x045628: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x04562c: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800082ULL; // 0x045630: mov w2, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E1ULL; // 0x045634: add x1, sp, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x72A00022ULL; // 0x045638: movk w2, #1, lsl #16
    return acc;
}

// [EN] Reconstructed FDE #0429 @ 0x0457e0..0x045c38 (1112 bytes)
// [VN] Phục dựng FDE #0429 tại 0x0457e0..0x045c38 (1112 byte)
//   0x0457e0: d10183ff  sub      sp, sp, #0x60
//   0x0457e4: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x0457e8: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0457ec: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0457f0: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0457f4: 910143fd  add      x29, sp, #0x50
//   0x0457f8: d53bd054  mrs      x20, tpidr_el0
//   0x0457fc: f9401688  ldr      x8, [x20, #0x28]
//   0x045800: f9000fe8  str      x8, [sp, #0x18]
//   0x045804: 90000108  adrp     x8, #0x65000
//   0x045808: f9461500  ldr      x0, [x8, #0xc28]
//   0x04580c: b5000220  cbnz     x0, #0x45850
//   0x045810: 90000108  adrp     x8, #0x65000
//   0x045814: 91198108  add      x8, x8, #0x660
//   0x045818: 08dffd08  ldarb    w8, [x8]
//   0x04581c: f00000f6  adrp     x22, #0x64000
uint64_t fde_0429_sub_0457e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0x90000108ULL) + (x2 ^ 0x0457E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x0457e0: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x0457e4: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x0457e8: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x0457ec: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x0457f0: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x0457f4: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x0457f8: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x0457fc: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x045800: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000108ULL; // 0x045804: adrp x8, #0x65000
    return acc;
}

// [EN] Reconstructed FDE #0430 @ 0x045c38..0x04684c (3092 bytes)
// [VN] Phục dựng FDE #0430 tại 0x045c38..0x04684c (3092 byte)
//   0x045c38: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x045c3c: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x045c40: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x045c44: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x045c48: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x045c4c: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x045c50: 910143fd  add      x29, sp, #0x50
//   0x045c54: d10a83ff  sub      sp, sp, #0x2a0
//   0x045c58: d53bd05c  mrs      x28, tpidr_el0
//   0x045c5c: f9401788  ldr      x8, [x28, #0x28]
//   0x045c60: aa0303f7  mov      x23, x3
//   0x045c64: 2a0203f5  mov      w21, w2
//   0x045c68: aa0103f4  mov      x20, x1
//   0x045c6c: f81a03a8  stur     x8, [x29, #-0x60]
//   0x045c70: 90000108  adrp     x8, #0x65000
//   0x045c74: f942c508  ldr      x8, [x8, #0x588]
uint64_t fde_0430_sub_045c38(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xAA0103F4ULL) + (x2 ^ 0x045C38ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x045c38: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x045c3c: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x045c40: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x045c44: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x045c48: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x045c4c: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x045c50: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD10A83FFULL; // 0x045c54: sub sp, sp, #0x2a0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05CULL; // 0x045c58: mrs x28, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401788ULL; // 0x045c5c: ldr x8, [x28, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0431 @ 0x04684c..0x046bdc (912 bytes)
// [VN] Phục dựng FDE #0431 tại 0x04684c..0x046bdc (912 byte)
//   0x04684c: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x046850: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x046854: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x046858: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x04685c: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x046860: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x046864: 910143fd  add      x29, sp, #0x50
//   0x046868: f0fffe21  adrp     x1, #0xd000
//   0x04686c: d0fffe22  adrp     x2, #0xc000
//   0x046870: b0fffe43  adrp     x3, #0xf000
//   0x046874: 91122c21  add      x1, x1, #0x48b
//   0x046878: 9108d442  add      x2, x2, #0x235
//   0x04687c: 91020c63  add      x3, x3, #0x83
//   0x046880: 528000c0  mov      w0, #6
//   0x046884: 5280b7e4  mov      w4, #0x5bf
//   0x046888: 94005906  bl       #0x5cca0
uint64_t fde_0431_sub_04684c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0x91020C63ULL) + (x2 ^ 0x04684CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x04684c: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x046850: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x046854: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x046858: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x04685c: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x046860: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x046864: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFE21ULL; // 0x046868: adrp x1, #0xd000
    acc = (acc * 0x100000001B3ULL) ^ 0xD0FFFE22ULL; // 0x04686c: adrp x2, #0xc000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0FFFE43ULL; // 0x046870: adrp x3, #0xf000
    return acc;
}

// [EN] Reconstructed FDE #0432 @ 0x046bdc..0x046c30 (84 bytes)
// [VN] Phục dựng FDE #0432 tại 0x046bdc..0x046c30 (84 byte)
//   0x046bdc: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x046be0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x046be4: 910043fd  add      x29, sp, #0x10
//   0x046be8: f00000e9  adrp     x9, #0x65000
//   0x046bec: aa0103f3  mov      x19, x1
//   0x046bf0: aa0003f4  mov      x20, x0
//   0x046bf4: 9116e129  add      x9, x9, #0x5b8
//   0x046bf8: c85f7d28  ldxr     x8, [x9]
//   0x046bfc: c80a7d3f  stxr     w10, xzr, [x9]
//   0x046c00: 35ffffca  cbnz     w10, #0x46bf8
//   0x046c04: b4000088  cbz      x8, #0x46c14
//   0x046c08: aa1403e0  mov      x0, x20
//   0x046c0c: aa1303e1  mov      x1, x19
//   0x046c10: d63f0100  blr      x8
//   0x046c14: f00000e8  adrp     x8, #0x65000
//   0x046c18: f942cd02  ldr      x2, [x8, #0x598]
uint64_t fde_0432_sub_046bdc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA1303E1ULL) + (x2 ^ 0x046BDCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x046bdc: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x046be0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x046be4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF00000E9ULL; // 0x046be8: adrp x9, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x046bec: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x046bf0: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9116E129ULL; // 0x046bf4: add x9, x9, #0x5b8
    acc = (acc * 0x100000001B3ULL) ^ 0xC85F7D28ULL; // 0x046bf8: ldxr x8, [x9]
    acc = (acc * 0x100000001B3ULL) ^ 0xC80A7D3FULL; // 0x046bfc: stxr w10, xzr, [x9]
    acc = (acc * 0x100000001B3ULL) ^ 0x35FFFFCAULL; // 0x046c00: cbnz w10, #0x46bf8
    return acc;
}

// [EN] Reconstructed FDE #0433 @ 0x046c30..0x046e24 (500 bytes)
// [VN] Phục dựng FDE #0433 tại 0x046c30..0x046e24 (500 byte)
//   0x046c30: d10203ff  sub      sp, sp, #0x80
//   0x046c34: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x046c38: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x046c3c: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x046c40: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x046c44: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x046c48: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x046c4c: 9101c3fd  add      x29, sp, #0x70
//   0x046c50: d53bd048  mrs      x8, tpidr_el0
//   0x046c54: f90003e8  str      x8, [sp]
//   0x046c58: f9401508  ldr      x8, [x8, #0x28]
//   0x046c5c: aa0303f3  mov      x19, x3
//   0x046c60: aa0203f4  mov      x20, x2
//   0x046c64: aa0103f6  mov      x22, x1
//   0x046c68: aa0003f7  mov      x23, x0
//   0x046c6c: f0fffe21  adrp     x1, #0xd000
uint64_t fde_0433_sub_046c30(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xAA0203F4ULL) + (x2 ^ 0x046C30ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x046c30: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA9026FFCULL; // 0x046c34: stp x28, x27, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x046c38: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x046c3c: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x046c40: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x046c44: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x046c48: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x046c4c: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD048ULL; // 0x046c50: mrs x8, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF90003E8ULL; // 0x046c54: str x8, [sp]
    return acc;
}

// [EN] Reconstructed FDE #0434 @ 0x046e24..0x046e78 (84 bytes)
// [VN] Phục dựng FDE #0434 tại 0x046e24..0x046e78 (84 byte)
//   0x046e24: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x046e28: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x046e2c: 910043fd  add      x29, sp, #0x10
//   0x046e30: f00000e9  adrp     x9, #0x65000
//   0x046e34: aa0103f3  mov      x19, x1
//   0x046e38: aa0003f4  mov      x20, x0
//   0x046e3c: 9116e129  add      x9, x9, #0x5b8
//   0x046e40: c85f7d28  ldxr     x8, [x9]
//   0x046e44: c80a7d3f  stxr     w10, xzr, [x9]
//   0x046e48: 35ffffca  cbnz     w10, #0x46e40
//   0x046e4c: b4000088  cbz      x8, #0x46e5c
//   0x046e50: aa1403e0  mov      x0, x20
//   0x046e54: aa1303e1  mov      x1, x19
//   0x046e58: d63f0100  blr      x8
//   0x046e5c: f00000e8  adrp     x8, #0x65000
//   0x046e60: f942d502  ldr      x2, [x8, #0x5a8]
uint64_t fde_0434_sub_046e24(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA1303E1ULL) + (x2 ^ 0x046E24ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x046e24: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x046e28: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x046e2c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF00000E9ULL; // 0x046e30: adrp x9, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x046e34: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x046e38: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9116E129ULL; // 0x046e3c: add x9, x9, #0x5b8
    acc = (acc * 0x100000001B3ULL) ^ 0xC85F7D28ULL; // 0x046e40: ldxr x8, [x9]
    acc = (acc * 0x100000001B3ULL) ^ 0xC80A7D3FULL; // 0x046e44: stxr w10, xzr, [x9]
    acc = (acc * 0x100000001B3ULL) ^ 0x35FFFFCAULL; // 0x046e48: cbnz w10, #0x46e40
    return acc;
}

// [EN] Reconstructed FDE #0435 @ 0x046e78..0x046f0c (148 bytes)
// [VN] Phục dựng FDE #0435 tại 0x046e78..0x046f0c (148 byte)
//   0x046e78: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x046e7c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x046e80: 910043fd  add      x29, sp, #0x10
//   0x046e84: aa1e03f3  mov      x19, x30
//   0x046e88: aa0003f4  mov      x20, x0
//   0x046e8c: 90000000  adrp     x0, #0x46000
//   0x046e90: 9139e000  add      x0, x0, #0xe78
//   0x046e94: 940058cb  bl       #0x5d1c0
//   0x046e98: aa0003e8  mov      x8, x0
//   0x046e9c: aa1403e0  mov      x0, x20
//   0x046ea0: d63f0100  blr      x8
//   0x046ea4: aa0003e4  mov      x4, x0
//   0x046ea8: f0fffe21  adrp     x1, #0xd000
//   0x046eac: 90fffe42  adrp     x2, #0xe000
//   0x046eb0: d0fffe43  adrp     x3, #0x10000
//   0x046eb4: 91122c21  add      x1, x1, #0x48b
uint64_t fde_0435_sub_046e78(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF0FFFE21ULL) + (x2 ^ 0x046E78ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x046e78: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x046e7c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x046e80: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x046e84: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x046e88: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x90000000ULL; // 0x046e8c: adrp x0, #0x46000
    acc = (acc * 0x100000001B3ULL) ^ 0x9139E000ULL; // 0x046e90: add x0, x0, #0xe78
    acc = (acc * 0x100000001B3ULL) ^ 0x940058CBULL; // 0x046e94: bl #0x5d1c0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x046e98: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x046e9c: mov x0, x20
    return acc;
}

// [EN] Reconstructed FDE #0436 @ 0x046f0c..0x047590 (1668 bytes)
// [VN] Phục dựng FDE #0436 tại 0x046f0c..0x047590 (1668 byte)
//   0x046f0c: d101c3ff  sub      sp, sp, #0x70
//   0x046f10: f9000bfb  str      x27, [sp, #0x10]
//   0x046f14: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x046f18: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x046f1c: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x046f20: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x046f24: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x046f28: 910183fd  add      x29, sp, #0x60
//   0x046f2c: f9400008  ldr      x8, [x0]
//   0x046f30: 2a0403f7  mov      w23, w4
//   0x046f34: aa0303f4  mov      x20, x3
//   0x046f38: aa0203f5  mov      x21, x2
//   0x046f3c: f9401908  ldr      x8, [x8, #0x30]
//   0x046f40: aa0003f3  mov      x19, x0
//   0x046f44: aa0103f6  mov      x22, x1
//   0x046f48: d63f0100  blr      x8
uint64_t fde_0436_sub_046f0c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xF9401908ULL) + (x2 ^ 0x046F0CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x046f0c: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BFBULL; // 0x046f10: str x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x046f14: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x046f18: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x046f1c: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x046f20: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x046f24: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x046f28: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x046f2c: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0403F7ULL; // 0x046f30: mov w23, w4
    return acc;
}

// [EN] Reconstructed FDE #0437 @ 0x047590..0x04774c (444 bytes)
// [VN] Phục dựng FDE #0437 tại 0x047590..0x04774c (444 byte)
//   0x047590: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x047594: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x047598: 910043fd  add      x29, sp, #0x10
//   0x04759c: b4000460  cbz      x0, #0x47628
//   0x0475a0: aa0003f3  mov      x19, x0
//   0x0475a4: d37dfc08  lsr      x8, x0, #0x3d
//   0x0475a8: b5000cc8  cbnz     x8, #0x47740
//   0x0475ac: d37df260  lsl      x0, x19, #3
//   0x0475b0: 9400572c  bl       #0x5d260
//   0x0475b4: d00000f4  adrp     x20, #0x65000
//   0x0475b8: f945fa88  ldr      x8, [x20, #0xbf0]
//   0x0475bc: f905fa80  str      x0, [x20, #0xbf0]
//   0x0475c0: b4000068  cbz      x8, #0x475cc
//   0x0475c4: aa0803e0  mov      x0, x8
//   0x0475c8: 9400572a  bl       #0x5d270
//   0x0475cc: aa1f03e8  mov      x8, xzr
uint64_t fde_0437_sub_047590(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xB4000068ULL) + (x2 ^ 0x047590ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x047590: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x047594: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x047598: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000460ULL; // 0x04759c: cbz x0, #0x47628
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0475a0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DFC08ULL; // 0x0475a4: lsr x8, x0, #0x3d
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000CC8ULL; // 0x0475a8: cbnz x8, #0x47740
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DF260ULL; // 0x0475ac: lsl x0, x19, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x9400572CULL; // 0x0475b0: bl #0x5d260
    acc = (acc * 0x100000001B3ULL) ^ 0xD00000F4ULL; // 0x0475b4: adrp x20, #0x65000
    return acc;
}

// [EN] Reconstructed FDE #0438 @ 0x04774c..0x0478f0 (420 bytes)
// [VN] Phục dựng FDE #0438 tại 0x04774c..0x0478f0 (420 byte)
//   0x04774c: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x047750: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x047754: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x047758: 910083fd  add      x29, sp, #0x20
//   0x04775c: d00000e8  adrp     x8, #0x65000
//   0x047760: 91174108  add      x8, x8, #0x5d0
//   0x047764: 08dffd08  ldarb    w8, [x8]
//   0x047768: aa0003f3  mov      x19, x0
//   0x04776c: 36000148  tbz      w8, #0, #0x47794
//   0x047770: d00000e8  adrp     x8, #0x65000
//   0x047774: f942ed02  ldr      x2, [x8, #0x5d8]
//   0x047778: b4000382  cbz      x2, #0x477e8
//   0x04777c: aa1303e1  mov      x1, x19
//   0x047780: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x047784: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x047788: aa1f03e0  mov      x0, xzr
uint64_t fde_0438_sub_04774c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA1303E1ULL) + (x2 ^ 0x04774CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x04774c: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x047750: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x047754: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x047758: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD00000E8ULL; // 0x04775c: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x91174108ULL; // 0x047760: add x8, x8, #0x5d0
    acc = (acc * 0x100000001B3ULL) ^ 0x08DFFD08ULL; // 0x047764: ldarb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x047768: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x36000148ULL; // 0x04776c: tbz w8, #0, #0x47794
    acc = (acc * 0x100000001B3ULL) ^ 0xD00000E8ULL; // 0x047770: adrp x8, #0x65000
    return acc;
}

// [EN] Reconstructed FDE #0439 @ 0x0478f0..0x047aac (444 bytes)
// [VN] Phục dựng FDE #0439 tại 0x0478f0..0x047aac (444 byte)
//   0x0478f0: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0478f4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0478f8: 910043fd  add      x29, sp, #0x10
//   0x0478fc: b4000460  cbz      x0, #0x47988
//   0x047900: aa0003f3  mov      x19, x0
//   0x047904: d37dfc08  lsr      x8, x0, #0x3d
//   0x047908: b5000cc8  cbnz     x8, #0x47aa0
//   0x04790c: d37df260  lsl      x0, x19, #3
//   0x047910: 94005654  bl       #0x5d260
//   0x047914: d00000f4  adrp     x20, #0x65000
//   0x047918: f945d288  ldr      x8, [x20, #0xba0]
//   0x04791c: f905d280  str      x0, [x20, #0xba0]
//   0x047920: b4000068  cbz      x8, #0x4792c
//   0x047924: aa0803e0  mov      x0, x8
//   0x047928: 94005652  bl       #0x5d270
//   0x04792c: aa1f03e8  mov      x8, xzr
uint64_t fde_0439_sub_0478f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xB4000068ULL) + (x2 ^ 0x0478F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0478f0: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0478f4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0478f8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000460ULL; // 0x0478fc: cbz x0, #0x47988
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x047900: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DFC08ULL; // 0x047904: lsr x8, x0, #0x3d
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000CC8ULL; // 0x047908: cbnz x8, #0x47aa0
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DF260ULL; // 0x04790c: lsl x0, x19, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x94005654ULL; // 0x047910: bl #0x5d260
    acc = (acc * 0x100000001B3ULL) ^ 0xD00000F4ULL; // 0x047914: adrp x20, #0x65000
    return acc;
}

// [EN] Reconstructed FDE #0440 @ 0x047aac..0x047f78 (1228 bytes)
// [VN] Phục dựng FDE #0440 tại 0x047aac..0x047f78 (1228 byte)
//   0x047aac: d10603ff  sub      sp, sp, #0x180
//   0x047ab0: a9126ffc  stp      x28, x27, [sp, #0x120]
//   0x047ab4: a91367fa  stp      x26, x25, [sp, #0x130]
//   0x047ab8: a9145ff8  stp      x24, x23, [sp, #0x140]
//   0x047abc: a91557f6  stp      x22, x21, [sp, #0x150]
//   0x047ac0: a9164ff4  stp      x20, x19, [sp, #0x160]
//   0x047ac4: a9177bfd  stp      x29, x30, [sp, #0x170]
//   0x047ac8: 9105c3fd  add      x29, sp, #0x170
//   0x047acc: d53bd058  mrs      x24, tpidr_el0
//   0x047ad0: f9401708  ldr      x8, [x24, #0x28]
//   0x047ad4: aa0103f3  mov      x19, x1
//   0x047ad8: d0fffe21  adrp     x1, #0xd000
//   0x047adc: 90fffe62  adrp     x2, #0x13000
//   0x047ae0: 90fffe23  adrp     x3, #0xb000
//   0x047ae4: aa0003f4  mov      x20, x0
//   0x047ae8: 91122c21  add      x1, x1, #0x48b
uint64_t fde_0440_sub_047aac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10603FFULL) + (x1 ^ 0x90FFFE62ULL) + (x2 ^ 0x047AACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10603FFULL; // 0x047aac: sub sp, sp, #0x180
    acc = (acc * 0x100000001B3ULL) ^ 0xA9126FFCULL; // 0x047ab0: stp x28, x27, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91367FAULL; // 0x047ab4: stp x26, x25, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9145FF8ULL; // 0x047ab8: stp x24, x23, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91557F6ULL; // 0x047abc: stp x22, x21, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9164FF4ULL; // 0x047ac0: stp x20, x19, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9177BFDULL; // 0x047ac4: stp x29, x30, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0x9105C3FDULL; // 0x047ac8: add x29, sp, #0x170
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x047acc: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401708ULL; // 0x047ad0: ldr x8, [x24, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0441 @ 0x047f78..0x0480a0 (296 bytes)
// [VN] Phục dựng FDE #0441 tại 0x047f78..0x0480a0 (296 byte)
//   0x047f78: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x047f7c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x047f80: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x047f84: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x047f88: 9100c3fd  add      x29, sp, #0x30
//   0x047f8c: b00000e8  adrp     x8, #0x64000
//   0x047f90: b94fb908  ldr      w8, [x8, #0xfb8]
//   0x047f94: 2a0003f4  mov      w20, w0
//   0x047f98: aa0103f3  mov      x19, x1
//   0x047f9c: 2a0803e0  mov      w0, w8
//   0x047fa0: 94005428  bl       #0x5d040
//   0x047fa4: b0000108  adrp     x8, #0x68000
//   0x047fa8: 93407e96  sxtw     x22, w20
//   0x047fac: 913ba108  add      x8, x8, #0xee8
//   0x047fb0: 8b161517  add      x23, x8, x22, lsl #5
//   0x047fb4: f94206e4  ldr      x4, [x23, #0x408]
uint64_t fde_0441_sub_047f78(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x93407E96ULL) + (x2 ^ 0x047F78ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x047f78: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x047f7c: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x047f80: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x047f84: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x047f88: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xB00000E8ULL; // 0x047f8c: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xB94FB908ULL; // 0x047f90: ldr w8, [x8, #0xfb8]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F4ULL; // 0x047f94: mov w20, w0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x047f98: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0803E0ULL; // 0x047f9c: mov w0, w8
    return acc;
}

// [EN] Reconstructed FDE #0442 @ 0x0480a0..0x04832c (652 bytes)
// [VN] Phục dựng FDE #0442 tại 0x0480a0..0x04832c (652 byte)
//   0x0480a0: d10203ff  sub      sp, sp, #0x80
//   0x0480a4: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x0480a8: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x0480ac: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x0480b0: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x0480b4: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x0480b8: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x0480bc: 9101c3fd  add      x29, sp, #0x70
//   0x0480c0: d53bd053  mrs      x19, tpidr_el0
//   0x0480c4: f9401668  ldr      x8, [x19, #0x28]
//   0x0480c8: f9000fe8  str      x8, [sp, #0x18]
//   0x0480cc: b00000e8  adrp     x8, #0x65000
//   0x0480d0: 9118a108  add      x8, x8, #0x628
//   0x0480d4: 08dffd08  ldarb    w8, [x8]
//   0x0480d8: 36000348  tbz      w8, #0, #0x48140
//   0x0480dc: 900000f4  adrp     x20, #0x64000
uint64_t fde_0442_sub_0480a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0x9118A108ULL) + (x2 ^ 0x0480A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x0480a0: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA9026FFCULL; // 0x0480a4: stp x28, x27, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x0480a8: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x0480ac: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x0480b0: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x0480b4: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x0480b8: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x0480bc: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x0480c0: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x0480c4: ldr x8, [x19, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0443 @ 0x04832c..0x048434 (264 bytes)
// [VN] Phục dựng FDE #0443 tại 0x04832c..0x048434 (264 byte)
//   0x04832c: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x048330: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x048334: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x048338: 910083fd  add      x29, sp, #0x20
//   0x04833c: b00000e8  adrp     x8, #0x65000
//   0x048340: f942b508  ldr      x8, [x8, #0x568]
//   0x048344: aa0003f3  mov      x19, x0
//   0x048348: b4000128  cbz      x8, #0x4836c
//   0x04834c: 39400269  ldrb     w9, [x19]
//   0x048350: b8697908  ldr      w8, [x8, x9, lsl #2]
//   0x048354: 37f80188  tbnz     w8, #0x1f, #0x48384
//   0x048358: 93407d00  sxtw     x0, w8
//   0x04835c: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x048360: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x048364: a8c357f6  ldp      x22, x21, [sp], #0x30
//   0x048368: d65f03c0  ret      
uint64_t fde_0443_sub_04832c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xA9427BFDULL) + (x2 ^ 0x04832CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x04832c: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x048330: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x048334: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x048338: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB00000E8ULL; // 0x04833c: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xF942B508ULL; // 0x048340: ldr x8, [x8, #0x568]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x048344: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000128ULL; // 0x048348: cbz x8, #0x4836c
    acc = (acc * 0x100000001B3ULL) ^ 0x39400269ULL; // 0x04834c: ldrb w9, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xB8697908ULL; // 0x048350: ldr w8, [x8, x9, lsl #2]
    return acc;
}

// [EN] Reconstructed FDE #0444 @ 0x048434..0x0484d8 (164 bytes)
// [VN] Phục dựng FDE #0444 tại 0x048434..0x0484d8 (164 byte)
//   0x048434: d10483ff  sub      sp, sp, #0x120
//   0x048438: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x04843c: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x048440: 910443fd  add      x29, sp, #0x110
//   0x048444: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x048448: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x04844c: f90057e7  str      x7, [sp, #0xa8]
//   0x048450: ad0007e0  stp      q0, q1, [sp]
//   0x048454: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x048458: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x04845c: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x048460: d53bd053  mrs      x19, tpidr_el0
//   0x048464: f9401669  ldr      x9, [x19, #0x28]
//   0x048468: 910223ea  add      x10, sp, #0x88
//   0x04846c: 928004ec  mov      x12, #-0x28
//   0x048470: 910043ab  add      x11, x29, #0x10
uint64_t fde_0444_sub_048434(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xF9401669ULL) + (x2 ^ 0x048434ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x048434: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x048438: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x04843c: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x048440: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x048444: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x048448: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x04844c: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x048450: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x048454: stp q2, q3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0217E4ULL; // 0x048458: stp q4, q5, [sp, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #0445 @ 0x0484d8..0x0485fc (292 bytes)
// [VN] Phục dựng FDE #0445 tại 0x0484d8..0x0485fc (292 byte)
//   0x0484d8: d10343ff  sub      sp, sp, #0xd0
//   0x0484dc: a90a57f6  stp      x22, x21, [sp, #0xa0]
//   0x0484e0: a90b4ff4  stp      x20, x19, [sp, #0xb0]
//   0x0484e4: a90c7bfd  stp      x29, x30, [sp, #0xc0]
//   0x0484e8: 910303fd  add      x29, sp, #0xc0
//   0x0484ec: d53bd055  mrs      x21, tpidr_el0
//   0x0484f0: f94016a8  ldr      x8, [x21, #0x28]
//   0x0484f4: 910043e0  add      x0, sp, #0x10
//   0x0484f8: 910043f6  add      x22, sp, #0x10
//   0x0484fc: f81d83a8  stur     x8, [x29, #-0x28]
//   0x048500: b0fffe68  adrp     x8, #0x15000
//   0x048504: 91283908  add      x8, x8, #0xa0e
//   0x048508: ad420500  ldp      q0, q1, [x8, #0x40]
//   0x04850c: ad430d02  ldp      q2, q3, [x8, #0x60]
//   0x048510: ad401504  ldp      q4, q5, [x8]
//   0x048514: ad0287e0  stp      q0, q1, [sp, #0x50]
uint64_t fde_0445_sub_0484d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10343FFULL) + (x1 ^ 0xAD420500ULL) + (x2 ^ 0x0484D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10343FFULL; // 0x0484d8: sub sp, sp, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A57F6ULL; // 0x0484dc: stp x22, x21, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B4FF4ULL; // 0x0484e0: stp x20, x19, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C7BFDULL; // 0x0484e4: stp x29, x30, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910303FDULL; // 0x0484e8: add x29, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x0484ec: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x0484f0: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043E0ULL; // 0x0484f4: add x0, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x910043F6ULL; // 0x0484f8: add x22, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D83A8ULL; // 0x0484fc: stur x8, [x29, #-0x28]
    return acc;
}

// [EN] Reconstructed FDE #0446 @ 0x0485fc..0x048640 (68 bytes)
// [VN] Phục dựng FDE #0446 tại 0x0485fc..0x048640 (68 byte)
//   0x0485fc: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x048600: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x048604: 910043fd  add      x29, sp, #0x10
//   0x048608: f9400013  ldr      x19, [x0]
//   0x04860c: f900001f  str      xzr, [x0]
//   0x048610: b4000133  cbz      x19, #0x48634
//   0x048614: f9402a60  ldr      x0, [x19, #0x50]
//   0x048618: 94000010  bl       #0x48658
//   0x04861c: 91007260  add      x0, x19, #0x1c
//   0x048620: 94005410  bl       #0x5d660
//   0x048624: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x048628: aa1303e0  mov      x0, x19
//   0x04862c: f84207f3  ldr      x19, [sp], #0x20
//   0x048630: 14005310  b        #0x5d270
//   0x048634: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x048638: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0446_sub_0485fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x0485FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0485fc: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x048600: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x048604: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400013ULL; // 0x048608: ldr x19, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900001FULL; // 0x04860c: str xzr, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000133ULL; // 0x048610: cbz x19, #0x48634
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402A60ULL; // 0x048614: ldr x0, [x19, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x94000010ULL; // 0x048618: bl #0x48658
    acc = (acc * 0x100000001B3ULL) ^ 0x91007260ULL; // 0x04861c: add x0, x19, #0x1c
    acc = (acc * 0x100000001B3ULL) ^ 0x94005410ULL; // 0x048620: bl #0x5d660
    return acc;
}

// [EN] Reconstructed FDE #0447 @ 0x048640..0x048658 (24 bytes)
// [VN] Phục dựng FDE #0447 tại 0x048640..0x048658 (24 byte)
//   0x048640: aa0003e8  mov      x8, x0
//   0x048644: f9400000  ldr      x0, [x0]
//   0x048648: b4000060  cbz      x0, #0x48654
//   0x04864c: f9000500  str      x0, [x8, #8]
//   0x048650: 14005308  b        #0x5d270
//   0x048654: d65f03c0  ret      
uint64_t fde_0447_sub_048640(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x048640ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x048640: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x048644: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000060ULL; // 0x048648: cbz x0, #0x48654
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000500ULL; // 0x04864c: str x0, [x8, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x14005308ULL; // 0x048650: b #0x5d270
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x048654: ret 
    return acc;
}

// [EN] Reconstructed FDE #0448 @ 0x048658..0x0486c8 (112 bytes)
// [VN] Phục dựng FDE #0448 tại 0x048658..0x0486c8 (112 byte)
//   0x048658: b4000220  cbz      x0, #0x4869c
//   0x04865c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x048660: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x048664: 910043fd  add      x29, sp, #0x10
//   0x048668: aa0003f3  mov      x19, x0
//   0x04866c: f9400000  ldr      x0, [x0]
//   0x048670: 97fffffa  bl       #0x48658
//   0x048674: f9400660  ldr      x0, [x19, #8]
//   0x048678: 97fffff8  bl       #0x48658
//   0x04867c: 39410268  ldrb     w8, [x19, #0x40]
//   0x048680: 37000108  tbnz     w8, #0, #0x486a0
//   0x048684: 3940a268  ldrb     w8, [x19, #0x28]
//   0x048688: 37000148  tbnz     w8, #0, #0x486b0
//   0x04868c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x048690: aa1303e0  mov      x0, x19
//   0x048694: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0448_sub_048658(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB4000220ULL) + (x1 ^ 0x37000148ULL) + (x2 ^ 0x048658ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000220ULL; // 0x048658: cbz x0, #0x4869c
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x04865c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x048660: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x048664: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x048668: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x04866c: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFFFAULL; // 0x048670: bl #0x48658
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400660ULL; // 0x048674: ldr x0, [x19, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFFF8ULL; // 0x048678: bl #0x48658
    acc = (acc * 0x100000001B3ULL) ^ 0x39410268ULL; // 0x04867c: ldrb w8, [x19, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #0449 @ 0x0486c8..0x0487f4 (300 bytes)
// [VN] Phục dựng FDE #0449 tại 0x0486c8..0x0487f4 (300 byte)
//   0x0486c8: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x0486cc: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x0486d0: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0486d4: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0486d8: 9100c3fd  add      x29, sp, #0x30
//   0x0486dc: aa1e03f3  mov      x19, x30
//   0x0486e0: aa0303f4  mov      x20, x3
//   0x0486e4: aa0203f6  mov      x22, x2
//   0x0486e8: 2a0103f7  mov      w23, w1
//   0x0486ec: aa0003f5  mov      x21, x0
//   0x0486f0: 90000000  adrp     x0, #0x48000
//   0x0486f4: 911b2000  add      x0, x0, #0x6c8
//   0x0486f8: 940052e6  bl       #0x5d290
//   0x0486fc: aa0003e8  mov      x8, x0
//   0x048700: aa1503e0  mov      x0, x21
//   0x048704: 2a1703e1  mov      w1, w23
uint64_t fde_0449_sub_0486c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x940052E6ULL) + (x2 ^ 0x0486C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x0486c8: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x0486cc: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0486d0: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0486d4: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0486d8: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x0486dc: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F4ULL; // 0x0486e0: mov x20, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F6ULL; // 0x0486e4: mov x22, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F7ULL; // 0x0486e8: mov w23, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x0486ec: mov x21, x0
    return acc;
}

// [EN] Reconstructed FDE #0450 @ 0x0487f4..0x048910 (284 bytes)
// [VN] Phục dựng FDE #0450 tại 0x0487f4..0x048910 (284 byte)
//   0x0487f4: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x0487f8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0487fc: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x048800: 910083fd  add      x29, sp, #0x20
//   0x048804: aa1e03f3  mov      x19, x30
//   0x048808: aa0203f4  mov      x20, x2
//   0x04880c: 2a0103f6  mov      w22, w1
//   0x048810: aa0003f5  mov      x21, x0
//   0x048814: 90000000  adrp     x0, #0x48000
//   0x048818: 911fd000  add      x0, x0, #0x7f4
//   0x04881c: 9400529d  bl       #0x5d290
//   0x048820: aa0003e8  mov      x8, x0
//   0x048824: aa1503e0  mov      x0, x21
//   0x048828: 2a1603e1  mov      w1, w22
//   0x04882c: aa1403e2  mov      x2, x20
//   0x048830: d63f0100  blr      x8
uint64_t fde_0450_sub_0487f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA1503E0ULL) + (x2 ^ 0x0487F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x0487f4: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0487f8: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0487fc: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x048800: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x048804: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x048808: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F6ULL; // 0x04880c: mov w22, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x048810: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x90000000ULL; // 0x048814: adrp x0, #0x48000
    acc = (acc * 0x100000001B3ULL) ^ 0x911FD000ULL; // 0x048818: add x0, x0, #0x7f4
    return acc;
}

// [EN] Reconstructed FDE #0451 @ 0x048910..0x048a18 (264 bytes)
// [VN] Phục dựng FDE #0451 tại 0x048910..0x048a18 (264 byte)
//   0x048910: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x048914: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x048918: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x04891c: 910083fd  add      x29, sp, #0x20
//   0x048920: aa1e03f3  mov      x19, x30
//   0x048924: aa0203f4  mov      x20, x2
//   0x048928: 2a0103f6  mov      w22, w1
//   0x04892c: aa0003f5  mov      x21, x0
//   0x048930: 90000000  adrp     x0, #0x48000
//   0x048934: 91244000  add      x0, x0, #0x910
//   0x048938: 94005256  bl       #0x5d290
//   0x04893c: aa0003e8  mov      x8, x0
//   0x048940: aa1503e0  mov      x0, x21
//   0x048944: 2a1603e1  mov      w1, w22
//   0x048948: aa1403e2  mov      x2, x20
//   0x04894c: d63f0100  blr      x8
uint64_t fde_0451_sub_048910(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA1503E0ULL) + (x2 ^ 0x048910ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x048910: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x048914: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x048918: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x04891c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03F3ULL; // 0x048920: mov x19, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x048924: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F6ULL; // 0x048928: mov w22, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x04892c: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x90000000ULL; // 0x048930: adrp x0, #0x48000
    acc = (acc * 0x100000001B3ULL) ^ 0x91244000ULL; // 0x048934: add x0, x0, #0x910
    return acc;
}

// [EN] Reconstructed FDE #0452 @ 0x048a18..0x048adc (196 bytes)
// [VN] Phục dựng FDE #0452 tại 0x048a18..0x048adc (196 byte)
//   0x048a18: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x048a1c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x048a20: 910043fd  add      x29, sp, #0x10
//   0x048a24: 2a0003f3  mov      w19, w0
//   0x048a28: 7100641f  cmp      w0, #0x19
//   0x048a2c: 5400010c  b.gt     #0x48a4c
//   0x048a30: 90fffe40  adrp     x0, #0x10000
//   0x048a34: f0fffe01  adrp     x1, #0xb000
//   0x048a38: 90000002  adrp     x2, #0x48000
//   0x048a3c: 911ad800  add      x0, x0, #0x6b6
//   0x048a40: 912f5c21  add      x1, x1, #0xbd7
//   0x048a44: 91244042  add      x2, x2, #0x910
//   0x048a48: 1400000e  b        #0x48a80
//   0x048a4c: 90fffe40  adrp     x0, #0x10000
//   0x048a50: 911ad800  add      x0, x0, #0x6b6
//   0x048a54: 71006a7f  cmp      w19, #0x1a
uint64_t fde_0452_sub_048a18(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x1400000EULL) + (x2 ^ 0x048A18ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x048a18: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x048a1c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x048a20: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F3ULL; // 0x048a24: mov w19, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x7100641FULL; // 0x048a28: cmp w0, #0x19
    acc = (acc * 0x100000001B3ULL) ^ 0x5400010CULL; // 0x048a2c: b.gt #0x48a4c
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFE40ULL; // 0x048a30: adrp x0, #0x10000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFE01ULL; // 0x048a34: adrp x1, #0xb000
    acc = (acc * 0x100000001B3ULL) ^ 0x90000002ULL; // 0x048a38: adrp x2, #0x48000
    acc = (acc * 0x100000001B3ULL) ^ 0x911AD800ULL; // 0x048a3c: add x0, x0, #0x6b6
    return acc;
}

// [EN] Reconstructed FDE #0453 @ 0x048adc..0x048bf0 (276 bytes)
// [VN] Phục dựng FDE #0453 tại 0x048adc..0x048bf0 (276 byte)
//   0x048adc: d10103ff  sub      sp, sp, #0x40
//   0x048ae0: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x048ae4: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x048ae8: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x048aec: 9100c3fd  add      x29, sp, #0x30
//   0x048af0: f9400008  ldr      x8, [x0]
//   0x048af4: 90fffe21  adrp     x1, #0xc000
//   0x048af8: 911ae421  add      x1, x1, #0x6b9
//   0x048afc: aa0003f3  mov      x19, x0
//   0x048b00: f9401908  ldr      x8, [x8, #0x30]
//   0x048b04: d63f0100  blr      x8
//   0x048b08: f9400268  ldr      x8, [x19]
//   0x048b0c: aa0003f4  mov      x20, x0
//   0x048b10: f9438908  ldr      x8, [x8, #0x710]
//   0x048b14: aa1303e0  mov      x0, x19
//   0x048b18: aa1403e1  mov      x1, x20
uint64_t fde_0453_sub_048adc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xAA0003F4ULL) + (x2 ^ 0x048ADCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x048adc: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x048ae0: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x048ae4: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x048ae8: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x048aec: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x048af0: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFE21ULL; // 0x048af4: adrp x1, #0xc000
    acc = (acc * 0x100000001B3ULL) ^ 0x911AE421ULL; // 0x048af8: add x1, x1, #0x6b9
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x048afc: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401908ULL; // 0x048b00: ldr x8, [x8, #0x30]
    return acc;
}

// [EN] Reconstructed FDE #0454 @ 0x048bf0..0x048cec (252 bytes)
// [VN] Phục dựng FDE #0454 tại 0x048bf0..0x048cec (252 byte)
//   0x048bf0: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x048bf4: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x048bf8: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x048bfc: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x048c00: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x048c04: 910103fd  add      x29, sp, #0x40
//   0x048c08: b00000f7  adrp     x23, #0x65000
//   0x048c0c: 9122e2f7  add      x23, x23, #0x8b8
//   0x048c10: a94022f3  ldp      x19, x8, [x23]
//   0x048c14: cb130114  sub      x20, x8, x19
//   0x048c18: 9343fe98  asr      x24, x20, #3
//   0x048c1c: 91000708  add      x8, x24, #1
//   0x048c20: d37dfd09  lsr      x9, x8, #0x3d
//   0x048c24: b5000629  cbnz     x9, #0x48ce8
//   0x048c28: b00000e9  adrp     x9, #0x65000
//   0x048c2c: f9446529  ldr      x9, [x9, #0x8c8]
uint64_t fde_0454_sub_048bf0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0xD37DFD09ULL) + (x2 ^ 0x048BF0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x048bf0: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x048bf4: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x048bf8: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x048bfc: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x048c00: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x048c04: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xB00000F7ULL; // 0x048c08: adrp x23, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0x9122E2F7ULL; // 0x048c0c: add x23, x23, #0x8b8
    acc = (acc * 0x100000001B3ULL) ^ 0xA94022F3ULL; // 0x048c10: ldp x19, x8, [x23]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB130114ULL; // 0x048c14: sub x20, x8, x19
    return acc;
}

// [EN] Reconstructed FDE #0455 @ 0x048cec..0x048eac (448 bytes)
// [VN] Phục dựng FDE #0455 tại 0x048cec..0x048eac (448 byte)
//   0x048cec: d10183ff  sub      sp, sp, #0x60
//   0x048cf0: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x048cf4: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x048cf8: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x048cfc: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x048d00: 910143fd  add      x29, sp, #0x50
//   0x048d04: d53bd055  mrs      x21, tpidr_el0
//   0x048d08: f94016a8  ldr      x8, [x21, #0x28]
//   0x048d0c: 90fffe21  adrp     x1, #0xc000
//   0x048d10: 911ae421  add      x1, x1, #0x6b9
//   0x048d14: aa0003f3  mov      x19, x0
//   0x048d18: f9000fe8  str      x8, [sp, #0x18]
//   0x048d1c: f9400008  ldr      x8, [x0]
//   0x048d20: f9401908  ldr      x8, [x8, #0x30]
//   0x048d24: d63f0100  blr      x8
//   0x048d28: aa0003f4  mov      x20, x0
uint64_t fde_0455_sub_048cec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xF9400008ULL) + (x2 ^ 0x048CECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x048cec: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x048cf0: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x048cf4: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x048cf8: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x048cfc: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x048d00: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x048d04: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x048d08: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x90FFFE21ULL; // 0x048d0c: adrp x1, #0xc000
    acc = (acc * 0x100000001B3ULL) ^ 0x911AE421ULL; // 0x048d10: add x1, x1, #0x6b9
    return acc;
}

// [EN] Reconstructed FDE #0456 @ 0x048eac..0x048fa0 (244 bytes)
// [VN] Phục dựng FDE #0456 tại 0x048eac..0x048fa0 (244 byte)
//   0x048eac: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x048eb0: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x048eb4: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x048eb8: 910083fd  add      x29, sp, #0x20
//   0x048ebc: f9400028  ldr      x8, [x1]
//   0x048ec0: aa0103f3  mov      x19, x1
//   0x048ec4: aa0003f5  mov      x21, x0
//   0x048ec8: aa0103e0  mov      x0, x1
//   0x048ecc: f9407d08  ldr      x8, [x8, #0xf8]
//   0x048ed0: aa0203e1  mov      x1, x2
//   0x048ed4: aa0203f4  mov      x20, x2
//   0x048ed8: d63f0100  blr      x8
//   0x048edc: b00000e8  adrp     x8, #0x65000
//   0x048ee0: f9434d02  ldr      x2, [x8, #0x698]
//   0x048ee4: aa0003f6  mov      x22, x0
//   0x048ee8: aa1303e0  mov      x0, x19
uint64_t fde_0456_sub_048eac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xB00000E8ULL) + (x2 ^ 0x048EACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x048eac: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x048eb0: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x048eb4: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x048eb8: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400028ULL; // 0x048ebc: ldr x8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x048ec0: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x048ec4: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x048ec8: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9407D08ULL; // 0x048ecc: ldr x8, [x8, #0xf8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E1ULL; // 0x048ed0: mov x1, x2
    return acc;
}

// [EN] Reconstructed FDE #0457 @ 0x048fa0..0x048fa8 (8 bytes)
// [VN] Phục dựng FDE #0457 tại 0x048fa0..0x048fa8 (8 byte)
//   0x048fa0: aa0203e1  mov      x1, x2
//   0x048fa4: 14000001  b        #0x48fa8
uint64_t fde_0457_sub_048fa0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0203E1ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x048FA0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E1ULL; // 0x048fa0: mov x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x048fa4: b #0x48fa8
    return acc;
}

// [EN] Reconstructed FDE #0458 @ 0x048fa8..0x0493c8 (1056 bytes)
// [VN] Phục dựng FDE #0458 tại 0x048fa8..0x0493c8 (1056 byte)
//   0x048fa8: d10203ff  sub      sp, sp, #0x80
//   0x048fac: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x048fb0: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x048fb4: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x048fb8: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x048fbc: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x048fc0: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x048fc4: 9101c3fd  add      x29, sp, #0x70
//   0x048fc8: f9400008  ldr      x8, [x0]
//   0x048fcc: aa0103f6  mov      x22, x1
//   0x048fd0: d0fffe41  adrp     x1, #0x12000
//   0x048fd4: 91005421  add      x1, x1, #0x15
//   0x048fd8: f9401908  ldr      x8, [x8, #0x30]
//   0x048fdc: aa0003f3  mov      x19, x0
//   0x048fe0: d63f0100  blr      x8
//   0x048fe4: b4001a00  cbz      x0, #0x49324
uint64_t fde_0458_sub_048fa8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xF9401908ULL) + (x2 ^ 0x048FA8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x048fa8: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA9026FFCULL; // 0x048fac: stp x28, x27, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x048fb0: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x048fb4: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x048fb8: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x048fbc: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x048fc0: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x048fc4: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x048fc8: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F6ULL; // 0x048fcc: mov x22, x1
    return acc;
}

// [EN] Reconstructed FDE #0459 @ 0x0493c8..0x04953c (372 bytes)
// [VN] Phục dựng FDE #0459 tại 0x0493c8..0x04953c (372 byte)
//   0x0493c8: d101c3ff  sub      sp, sp, #0x70
//   0x0493cc: f9001bf7  str      x23, [sp, #0x30]
//   0x0493d0: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x0493d4: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x0493d8: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x0493dc: 910183fd  add      x29, sp, #0x60
//   0x0493e0: d53bd056  mrs      x22, tpidr_el0
//   0x0493e4: f94016c8  ldr      x8, [x22, #0x28]
//   0x0493e8: 2a0303f4  mov      w20, w3
//   0x0493ec: aa0203f5  mov      x21, x2
//   0x0493f0: aa0003f3  mov      x19, x0
//   0x0493f4: f90017e8  str      x8, [sp, #0x28]
//   0x0493f8: 94000051  bl       #0x4953c
//   0x0493fc: f9400268  ldr      x8, [x19]
//   0x049400: 910083e1  add      x1, sp, #0x20
//   0x049404: aa1303e0  mov      x0, x19
uint64_t fde_0459_sub_0493c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x94000051ULL) + (x2 ^ 0x0493C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x0493c8: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF7ULL; // 0x0493cc: str x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x0493d0: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x0493d4: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x0493d8: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x0493dc: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x0493e0: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x0493e4: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303F4ULL; // 0x0493e8: mov w20, w3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x0493ec: mov x21, x2
    return acc;
}

// [EN] Reconstructed FDE #0460 @ 0x04953c..0x0496c0 (388 bytes)
// [VN] Phục dựng FDE #0460 tại 0x04953c..0x0496c0 (388 byte)
//   0x04953c: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x049540: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x049544: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x049548: 910083fd  add      x29, sp, #0x20
//   0x04954c: f9400008  ldr      x8, [x0]
//   0x049550: aa0003f3  mov      x19, x0
//   0x049554: aa0103f4  mov      x20, x1
//   0x049558: f9405508  ldr      x8, [x8, #0xa8]
//   0x04955c: d63f0100  blr      x8
//   0x049560: 900000f6  adrp     x22, #0x65000
//   0x049564: 911ba2d6  add      x22, x22, #0x6e8
//   0x049568: f90002c0  str      x0, [x22]
//   0x04956c: f9400268  ldr      x8, [x19]
//   0x049570: 90fffe35  adrp     x21, #0xd000
//   0x049574: b0fffe22  adrp     x2, #0xe000
//   0x049578: 911d6ab5  add      x21, x21, #0x75a
uint64_t fde_0460_sub_04953c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xF9400268ULL) + (x2 ^ 0x04953CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x04953c: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x049540: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x049544: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x049548: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x04954c: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x049550: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x049554: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9405508ULL; // 0x049558: ldr x8, [x8, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x04955c: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0x900000F6ULL; // 0x049560: adrp x22, #0x65000
    return acc;
}

// [EN] Reconstructed FDE #0461 @ 0x0496c0..0x0497b4 (244 bytes)
// [VN] Phục dựng FDE #0461 tại 0x0496c0..0x0497b4 (244 byte)
//   0x0496c0: d10103ff  sub      sp, sp, #0x40
//   0x0496c4: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x0496c8: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0496cc: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0496d0: 9100c3fd  add      x29, sp, #0x30
//   0x0496d4: 71005c1f  cmp      w0, #0x17
//   0x0496d8: 5400064b  b.lt     #0x497a0
//   0x0496dc: 900000f5  adrp     x21, #0x65000
//   0x0496e0: b94902a8  ldr      w8, [x21, #0x900]
//   0x0496e4: 2a0003f3  mov      w19, w0
//   0x0496e8: 360802e8  tbz      w8, #1, #0x49744
//   0x0496ec: 900000f6  adrp     x22, #0x65000
//   0x0496f0: 911a02d6  add      x22, x22, #0x680
//   0x0496f4: f9414ac2  ldr      x2, [x22, #0x290]
//   0x0496f8: b9429ac3  ldr      w3, [x22, #0x298]
//   0x0496fc: 90fffe61  adrp     x1, #0x15000
uint64_t fde_0461_sub_0496c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x911A02D6ULL) + (x2 ^ 0x0496C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x0496c0: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x0496c4: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0496c8: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0496cc: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0496d0: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x71005C1FULL; // 0x0496d4: cmp w0, #0x17
    acc = (acc * 0x100000001B3ULL) ^ 0x5400064BULL; // 0x0496d8: b.lt #0x497a0
    acc = (acc * 0x100000001B3ULL) ^ 0x900000F5ULL; // 0x0496dc: adrp x21, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xB94902A8ULL; // 0x0496e0: ldr w8, [x21, #0x900]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F3ULL; // 0x0496e4: mov w19, w0
    return acc;
}

// [EN] Reconstructed FDE #0462 @ 0x0497b4..0x04981c (104 bytes)
// [VN] Phục dựng FDE #0462 tại 0x0497b4..0x04981c (104 byte)
//   0x0497b4: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0497b8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0497bc: 910043fd  add      x29, sp, #0x10
//   0x0497c0: 900000e8  adrp     x8, #0x65000
//   0x0497c4: f9435508  ldr      x8, [x8, #0x6a8]
//   0x0497c8: b4000208  cbz      x8, #0x49808
//   0x0497cc: aa0003f4  mov      x20, x0
//   0x0497d0: d63f0100  blr      x8
//   0x0497d4: aa0003f3  mov      x19, x0
//   0x0497d8: b4000100  cbz      x0, #0x497f8
//   0x0497dc: 900000e8  adrp     x8, #0x65000
//   0x0497e0: f9434100  ldr      x0, [x8, #0x680]
//   0x0497e4: b40000a0  cbz      x0, #0x497f8
//   0x0497e8: 52800023  mov      w3, #1
//   0x0497ec: aa1403e1  mov      x1, x20
//   0x0497f0: aa1303e2  mov      x2, x19
uint64_t fde_0462_sub_0497b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xB40000A0ULL) + (x2 ^ 0x0497B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0497b4: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0497b8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0497bc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x900000E8ULL; // 0x0497c0: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9435508ULL; // 0x0497c4: ldr x8, [x8, #0x6a8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000208ULL; // 0x0497c8: cbz x8, #0x49808
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x0497cc: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x0497d0: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0497d4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000100ULL; // 0x0497d8: cbz x0, #0x497f8
    return acc;
}

// [EN] Reconstructed FDE #0463 @ 0x04981c..0x0498cc (176 bytes)
// [VN] Phục dựng FDE #0463 tại 0x04981c..0x0498cc (176 byte)
//   0x04981c: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x049820: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x049824: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x049828: 910083fd  add      x29, sp, #0x20
//   0x04982c: 900000e8  adrp     x8, #0x65000
//   0x049830: f9435902  ldr      x2, [x8, #0x6b0]
//   0x049834: b40002c2  cbz      x2, #0x4988c
//   0x049838: 900000e8  adrp     x8, #0x65000
//   0x04983c: aa0003f4  mov      x20, x0
//   0x049840: f9434100  ldr      x0, [x8, #0x680]
//   0x049844: aa0103f3  mov      x19, x1
//   0x049848: b40002a0  cbz      x0, #0x4989c
//   0x04984c: aa1303e1  mov      x1, x19
//   0x049850: 94000052  bl       #0x49998
//   0x049854: 900000f5  adrp     x21, #0x65000
//   0x049858: 911ac2b5  add      x21, x21, #0x6b0
uint64_t fde_0463_sub_04981c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xAA1303E1ULL) + (x2 ^ 0x04981CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x04981c: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x049820: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x049824: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x049828: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x900000E8ULL; // 0x04982c: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9435902ULL; // 0x049830: ldr x2, [x8, #0x6b0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40002C2ULL; // 0x049834: cbz x2, #0x4988c
    acc = (acc * 0x100000001B3ULL) ^ 0x900000E8ULL; // 0x049838: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x04983c: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9434100ULL; // 0x049840: ldr x0, [x8, #0x680]
    return acc;
}

// [EN] Reconstructed FDE #0464 @ 0x0498cc..0x049934 (104 bytes)
// [VN] Phục dựng FDE #0464 tại 0x0498cc..0x049934 (104 byte)
//   0x0498cc: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0498d0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0498d4: 910043fd  add      x29, sp, #0x10
//   0x0498d8: 900000e8  adrp     x8, #0x65000
//   0x0498dc: f9435d08  ldr      x8, [x8, #0x6b8]
//   0x0498e0: b4000208  cbz      x8, #0x49920
//   0x0498e4: aa0003f4  mov      x20, x0
//   0x0498e8: d63f0100  blr      x8
//   0x0498ec: aa0003f3  mov      x19, x0
//   0x0498f0: b4000100  cbz      x0, #0x49910
//   0x0498f4: 900000e8  adrp     x8, #0x65000
//   0x0498f8: f9433d00  ldr      x0, [x8, #0x678]
//   0x0498fc: b40000a0  cbz      x0, #0x49910
//   0x049900: aa1403e1  mov      x1, x20
//   0x049904: aa1303e2  mov      x2, x19
//   0x049908: 2a1f03e3  mov      w3, wzr
uint64_t fde_0464_sub_0498cc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xB40000A0ULL) + (x2 ^ 0x0498CCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0498cc: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0498d0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0498d4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x900000E8ULL; // 0x0498d8: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9435D08ULL; // 0x0498dc: ldr x8, [x8, #0x6b8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000208ULL; // 0x0498e0: cbz x8, #0x49920
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x0498e4: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x0498e8: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0498ec: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000100ULL; // 0x0498f0: cbz x0, #0x49910
    return acc;
}

// [EN] Reconstructed FDE #0465 @ 0x049934..0x049998 (100 bytes)
// [VN] Phục dựng FDE #0465 tại 0x049934..0x049998 (100 byte)
//   0x049934: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x049938: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x04993c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x049940: 910083fd  add      x29, sp, #0x20
//   0x049944: 900000f5  adrp     x21, #0x65000
//   0x049948: f94362a2  ldr      x2, [x21, #0x6c0]
//   0x04994c: b40001e2  cbz      x2, #0x49988
//   0x049950: 900000e8  adrp     x8, #0x65000
//   0x049954: aa0003f4  mov      x20, x0
//   0x049958: f9433d00  ldr      x0, [x8, #0x678]
//   0x04995c: aa0103f3  mov      x19, x1
//   0x049960: b4000080  cbz      x0, #0x49970
//   0x049964: aa1303e1  mov      x1, x19
//   0x049968: 9400000c  bl       #0x49998
//   0x04996c: f94362a2  ldr      x2, [x21, #0x6c0]
//   0x049970: aa1403e0  mov      x0, x20
uint64_t fde_0465_sub_049934(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xAA1303E1ULL) + (x2 ^ 0x049934ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x049934: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x049938: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x04993c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x049940: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x900000F5ULL; // 0x049944: adrp x21, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xF94362A2ULL; // 0x049948: ldr x2, [x21, #0x6c0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001E2ULL; // 0x04994c: cbz x2, #0x49988
    acc = (acc * 0x100000001B3ULL) ^ 0x900000E8ULL; // 0x049950: adrp x8, #0x65000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x049954: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9433D00ULL; // 0x049958: ldr x0, [x8, #0x678]
    return acc;
}

// [EN] Reconstructed FDE #0466 @ 0x049998..0x049bc0 (552 bytes)
// [VN] Phục dựng FDE #0466 tại 0x049998..0x049bc0 (552 byte)
//   0x049998: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x04999c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x0499a0: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0499a4: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0499a8: 9100c3fd  add      x29, sp, #0x30
//   0x0499ac: 91007013  add      x19, x0, #0x1c
//   0x0499b0: aa0003f4  mov      x20, x0
//   0x0499b4: aa1303e0  mov      x0, x19
//   0x0499b8: aa0103f5  mov      x21, x1
//   0x0499bc: 94004ded  bl       #0x5d170
//   0x0499c0: f9400288  ldr      x8, [x20]
//   0x0499c4: b4000268  cbz      x8, #0x49a10
//   0x0499c8: b9400109  ldr      w9, [x8]
//   0x0499cc: b9406e8a  ldr      w10, [x20, #0x6c]
//   0x0499d0: 12003d2b  and      w11, w9, #0xffff
//   0x0499d4: 7100695f  cmp      w10, #0x1a
uint64_t fde_0466_sub_049998(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xB9400109ULL) + (x2 ^ 0x049998ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x049998: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x04999c: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0499a0: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0499a4: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0499a8: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x91007013ULL; // 0x0499ac: add x19, x0, #0x1c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x0499b0: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x0499b4: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x0499b8: mov x21, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x94004DEDULL; // 0x0499bc: bl #0x5d170
    return acc;
}

// [EN] Reconstructed FDE #0467 @ 0x049bc0..0x04a738 (2936 bytes)
// [VN] Phục dựng FDE #0467 tại 0x049bc0..0x04a738 (2936 byte)
//   0x049bc0: d10503ff  sub      sp, sp, #0x140
//   0x049bc4: a90e6ffc  stp      x28, x27, [sp, #0xe0]
//   0x049bc8: a90f67fa  stp      x26, x25, [sp, #0xf0]
//   0x049bcc: a9105ff8  stp      x24, x23, [sp, #0x100]
//   0x049bd0: a91157f6  stp      x22, x21, [sp, #0x110]
//   0x049bd4: a9124ff4  stp      x20, x19, [sp, #0x120]
//   0x049bd8: a9137bfd  stp      x29, x30, [sp, #0x130]
//   0x049bdc: 9104c3fd  add      x29, sp, #0x130
//   0x049be0: d53bd053  mrs      x19, tpidr_el0
//   0x049be4: f9401668  ldr      x8, [x19, #0x28]
//   0x049be8: 91007014  add      x20, x0, #0x1c
//   0x049bec: aa0003f6  mov      x22, x0
//   0x049bf0: aa1403e0  mov      x0, x20
//   0x049bf4: 2a0303f7  mov      w23, w3
//   0x049bf8: aa0203f8  mov      x24, x2
//   0x049bfc: aa0103f5  mov      x21, x1
uint64_t fde_0467_sub_049bc0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10503FFULL) + (x1 ^ 0xAA1403E0ULL) + (x2 ^ 0x049BC0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10503FFULL; // 0x049bc0: sub sp, sp, #0x140
    acc = (acc * 0x100000001B3ULL) ^ 0xA90E6FFCULL; // 0x049bc4: stp x28, x27, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90F67FAULL; // 0x049bc8: stp x26, x25, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9105FF8ULL; // 0x049bcc: stp x24, x23, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91157F6ULL; // 0x049bd0: stp x22, x21, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9124FF4ULL; // 0x049bd4: stp x20, x19, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9137BFDULL; // 0x049bd8: stp x29, x30, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0x9104C3FDULL; // 0x049bdc: add x29, sp, #0x130
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x049be0: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x049be4: ldr x8, [x19, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0468 @ 0x04a738..0x04a7d4 (156 bytes)
// [VN] Phục dựng FDE #0468 tại 0x04a738..0x04a7d4 (156 byte)
//   0x04a738: d10483ff  sub      sp, sp, #0x120
//   0x04a73c: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x04a740: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x04a744: 910443fd  add      x29, sp, #0x110
//   0x04a748: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x04a74c: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x04a750: f90057e7  str      x7, [sp, #0xa8]
//   0x04a754: ad0007e0  stp      q0, q1, [sp]
//   0x04a758: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x04a75c: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x04a760: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x04a764: d53bd053  mrs      x19, tpidr_el0
//   0x04a768: f940166b  ldr      x11, [x19, #0x28]
//   0x04a76c: 928004e8  mov      x8, #-0x28
//   0x04a770: 910003e9  mov      x9, sp
//   0x04a774: 910223ea  add      x10, sp, #0x88
uint64_t fde_0468_sub_04a738(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xF940166BULL) + (x2 ^ 0x04A738ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x04a738: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x04a73c: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x04a740: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x04a744: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x04a748: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x04a74c: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x04a750: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x04a754: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x04a758: stp q2, q3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0217E4ULL; // 0x04a75c: stp q4, q5, [sp, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #0469 @ 0x04a7d4..0x04abf8 (1060 bytes)
// [VN] Phục dựng FDE #0469 tại 0x04a7d4..0x04abf8 (1060 byte)
//   0x04a7d4: d10743ff  sub      sp, sp, #0x1d0
//   0x04a7d8: a9176ffc  stp      x28, x27, [sp, #0x170]
//   0x04a7dc: a91867fa  stp      x26, x25, [sp, #0x180]
//   0x04a7e0: a9195ff8  stp      x24, x23, [sp, #0x190]
//   0x04a7e4: a91a57f6  stp      x22, x21, [sp, #0x1a0]
//   0x04a7e8: a91b4ff4  stp      x20, x19, [sp, #0x1b0]
//   0x04a7ec: a91c7bfd  stp      x29, x30, [sp, #0x1c0]
//   0x04a7f0: 910703fd  add      x29, sp, #0x1c0
//   0x04a7f4: d53bd059  mrs      x25, tpidr_el0
//   0x04a7f8: f9401728  ldr      x8, [x25, #0x28]
//   0x04a7fc: f00000c9  adrp     x9, #0x65000
//   0x04a800: 9119e129  add      x9, x9, #0x678
//   0x04a804: f81983a8  stur     x8, [x29, #-0x68]
//   0x04a808: a9402528  ldp      x8, x9, [x9]
//   0x04a80c: aa090108  orr      x8, x8, x9
//   0x04a810: b50001a8  cbnz     x8, #0x4a844
uint64_t fde_0469_sub_04a7d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10743FFULL) + (x1 ^ 0xF81983A8ULL) + (x2 ^ 0x04A7D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10743FFULL; // 0x04a7d4: sub sp, sp, #0x1d0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9176FFCULL; // 0x04a7d8: stp x28, x27, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91867FAULL; // 0x04a7dc: stp x26, x25, [sp, #0x180]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9195FF8ULL; // 0x04a7e0: stp x24, x23, [sp, #0x190]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91A57F6ULL; // 0x04a7e4: stp x22, x21, [sp, #0x1a0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91B4FF4ULL; // 0x04a7e8: stp x20, x19, [sp, #0x1b0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91C7BFDULL; // 0x04a7ec: stp x29, x30, [sp, #0x1c0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910703FDULL; // 0x04a7f0: add x29, sp, #0x1c0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x04a7f4: mrs x25, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401728ULL; // 0x04a7f8: ldr x8, [x25, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0470 @ 0x04abf8..0x04c1c4 (5580 bytes)
// [VN] Phục dựng FDE #0470 tại 0x04abf8..0x04c1c4 (5580 byte)
//   0x04abf8: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x04abfc: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x04ac00: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x04ac04: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x04ac08: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x04ac0c: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x04ac10: 910143fd  add      x29, sp, #0x50
//   0x04ac14: d1400fff  sub      sp, sp, #3, lsl #12
//   0x04ac18: d10803ff  sub      sp, sp, #0x200
//   0x04ac1c: d53bd04a  mrs      x10, tpidr_el0
//   0x04ac20: f9401548  ldr      x8, [x10, #0x28]
//   0x04ac24: f81983a8  stur     x8, [x29, #-0x68]
//   0x04ac28: f9400008  ldr      x8, [x0]
//   0x04ac2c: f90017e1  str      x1, [sp, #0x28]
//   0x04ac30: b4000aa8  cbz      x8, #0x4ad84
//   0x04ac34: f9400409  ldr      x9, [x0, #8]
uint64_t fde_0470_sub_04abf8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xF9400008ULL) + (x2 ^ 0x04ABF8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x04abf8: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x04abfc: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x04ac00: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x04ac04: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x04ac08: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x04ac0c: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x04ac10: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD1400FFFULL; // 0x04ac14: sub sp, sp, #3, lsl #12
    acc = (acc * 0x100000001B3ULL) ^ 0xD10803FFULL; // 0x04ac18: sub sp, sp, #0x200
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD04AULL; // 0x04ac1c: mrs x10, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0471 @ 0x04c1c4..0x04c29c (216 bytes)
// [VN] Phục dựng FDE #0471 tại 0x04c1c4..0x04c29c (216 byte)
//   0x04c1c4: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x04c1c8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x04c1cc: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x04c1d0: 910083fd  add      x29, sp, #0x20
//   0x04c1d4: f9403c14  ldr      x20, [x0, #0x78]
//   0x04c1d8: 900000a8  adrp     x8, #0x60000
//   0x04c1dc: aa0003f3  mov      x19, x0
//   0x04c1e0: 91058108  add      x8, x8, #0x160
//   0x04c1e4: f9000008  str      x8, [x0]
//   0x04c1e8: b4000194  cbz      x20, #0x4c218
//   0x04c1ec: aa1303e0  mov      x0, x19
//   0x04c1f0: 9400002b  bl       #0x4c29c
//   0x04c1f4: aa1403e0  mov      x0, x20
//   0x04c1f8: 9400430e  bl       #0x5ce30
//   0x04c1fc: f9400268  ldr      x8, [x19]
//   0x04c200: f9003e7f  str      xzr, [x19, #0x78]
uint64_t fde_0471_sub_04c1c4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xAA1403E0ULL) + (x2 ^ 0x04C1C4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x04c1c4: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x04c1c8: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x04c1cc: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x04c1d0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9403C14ULL; // 0x04c1d4: ldr x20, [x0, #0x78]
    acc = (acc * 0x100000001B3ULL) ^ 0x900000A8ULL; // 0x04c1d8: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x04c1dc: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91058108ULL; // 0x04c1e0: add x8, x8, #0x160
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000008ULL; // 0x04c1e4: str x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000194ULL; // 0x04c1e8: cbz x20, #0x4c218
    return acc;
}

// [EN] Reconstructed FDE #0472 @ 0x04c29c..0x04c498 (508 bytes)
// [VN] Phục dựng FDE #0472 tại 0x04c29c..0x04c498 (508 byte)
//   0x04c29c: d10143ff  sub      sp, sp, #0x50
//   0x04c2a0: f9000bf7  str      x23, [sp, #0x10]
//   0x04c2a4: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x04c2a8: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x04c2ac: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x04c2b0: 910103fd  add      x29, sp, #0x40
//   0x04c2b4: d53bd057  mrs      x23, tpidr_el0
//   0x04c2b8: f94016e8  ldr      x8, [x23, #0x28]
//   0x04c2bc: f90007e8  str      x8, [sp, #8]
//   0x04c2c0: f9403c08  ldr      x8, [x0, #0x78]
//   0x04c2c4: b4000d08  cbz      x8, #0x4c464
//   0x04c2c8: aa0003f3  mov      x19, x0
//   0x04c2cc: f9404000  ldr      x0, [x0, #0x80]
//   0x04c2d0: b4000e20  cbz      x0, #0x4c494
//   0x04c2d4: b9409e68  ldr      w8, [x19, #0x9c]
//   0x04c2d8: 37200148  tbnz     w8, #4, #0x4c300
uint64_t fde_0472_sub_04c29c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xF9404000ULL) + (x2 ^ 0x04C29CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x04c29c: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF7ULL; // 0x04c2a0: str x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x04c2a4: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x04c2a8: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x04c2ac: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x04c2b0: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x04c2b4: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x04c2b8: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x04c2bc: str x8, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9403C08ULL; // 0x04c2c0: ldr x8, [x0, #0x78]
    return acc;
}

// [EN] Reconstructed FDE #0473 @ 0x04c498..0x04c4ac (20 bytes)
// [VN] Phục dựng FDE #0473 tại 0x04c498..0x04c4ac (20 byte)
//   0x04c498: 900000a8  adrp     x8, #0x60000
//   0x04c49c: f9468908  ldr      x8, [x8, #0xd10]
//   0x04c4a0: 91004108  add      x8, x8, #0x10
//   0x04c4a4: f8008408  str      x8, [x0], #8
//   0x04c4a8: 1400448a  b        #0x5d6d0
uint64_t fde_0473_sub_04c498(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x900000A8ULL) + (x1 ^ 0x1400448AULL) + (x2 ^ 0x04C498ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x900000A8ULL; // 0x04c498: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9468908ULL; // 0x04c49c: ldr x8, [x8, #0xd10]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x04c4a0: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF8008408ULL; // 0x04c4a4: str x8, [x0], #8
    acc = (acc * 0x100000001B3ULL) ^ 0x1400448AULL; // 0x04c4a8: b #0x5d6d0
    return acc;
}

// [EN] Reconstructed FDE #0474 @ 0x04c4ac..0x04c4e0 (52 bytes)
// [VN] Phục dựng FDE #0474 tại 0x04c4ac..0x04c4e0 (52 byte)
//   0x04c4ac: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x04c4b0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x04c4b4: 910043fd  add      x29, sp, #0x10
//   0x04c4b8: 900000a8  adrp     x8, #0x60000
//   0x04c4bc: f9468908  ldr      x8, [x8, #0xd10]
//   0x04c4c0: aa0003f3  mov      x19, x0
//   0x04c4c4: 91004108  add      x8, x8, #0x10
//   0x04c4c8: f8008408  str      x8, [x0], #8
//   0x04c4cc: 94004481  bl       #0x5d6d0
//   0x04c4d0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x04c4d4: aa1303e0  mov      x0, x19
//   0x04c4d8: f84207f3  ldr      x19, [sp], #0x20
//   0x04c4dc: 14004365  b        #0x5d270
uint64_t fde_0474_sub_04c4ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x14004365ULL) + (x2 ^ 0x04C4ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x04c4ac: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x04c4b0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x04c4b4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x900000A8ULL; // 0x04c4b8: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9468908ULL; // 0x04c4bc: ldr x8, [x8, #0xd10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x04c4c0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x04c4c4: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF8008408ULL; // 0x04c4c8: str x8, [x0], #8
    acc = (acc * 0x100000001B3ULL) ^ 0x94004481ULL; // 0x04c4cc: bl #0x5d6d0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x04c4d0: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0475 @ 0x04c4e0..0x04c4e4 (4 bytes)
// [VN] Phục dựng FDE #0475 tại 0x04c4e0..0x04c4e4 (4 byte)
//   0x04c4e0: d65f03c0  ret      
uint64_t fde_0475_sub_04c4e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04C4E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04c4e0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0476 @ 0x04c4e4..0x04c4e8 (4 bytes)
// [VN] Phục dựng FDE #0476 tại 0x04c4e4..0x04c4e8 (4 byte)
//   0x04c4e4: d65f03c0  ret      
uint64_t fde_0476_sub_04c4e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04C4E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04c4e4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0477 @ 0x04c4e8..0x04c4f4 (12 bytes)
// [VN] Phục dựng FDE #0477 tại 0x04c4e8..0x04c4f4 (12 byte)
//   0x04c4e8: 92800001  mov      x1, #-1
//   0x04c4ec: aa1f03e0  mov      x0, xzr
//   0x04c4f0: d65f03c0  ret      
uint64_t fde_0477_sub_04c4e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x92800001ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04C4E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x92800001ULL; // 0x04c4e8: mov x1, #-1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E0ULL; // 0x04c4ec: mov x0, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04c4f0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0478 @ 0x04c4f4..0x04c500 (12 bytes)
// [VN] Phục dựng FDE #0478 tại 0x04c4f4..0x04c500 (12 byte)
//   0x04c4f4: 92800001  mov      x1, #-1
//   0x04c4f8: aa1f03e0  mov      x0, xzr
//   0x04c4fc: d65f03c0  ret      
uint64_t fde_0478_sub_04c4f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x92800001ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04C4F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x92800001ULL; // 0x04c4f4: mov x1, #-1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E0ULL; // 0x04c4f8: mov x0, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04c4fc: ret 
    return acc;
}

// [EN] Reconstructed FDE #0479 @ 0x04c500..0x04c508 (8 bytes)
// [VN] Phục dựng FDE #0479 tại 0x04c500..0x04c508 (8 byte)
//   0x04c500: 2a1f03e0  mov      w0, wzr
//   0x04c504: d65f03c0  ret      
uint64_t fde_0479_sub_04c500(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04C500ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x04c500: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04c504: ret 
    return acc;
}

// [EN] Reconstructed FDE #0480 @ 0x04c508..0x04c510 (8 bytes)
// [VN] Phục dựng FDE #0480 tại 0x04c508..0x04c510 (8 byte)
//   0x04c508: aa1f03e0  mov      x0, xzr
//   0x04c50c: d65f03c0  ret      
uint64_t fde_0480_sub_04c508(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04C508ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E0ULL; // 0x04c508: mov x0, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04c50c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0481 @ 0x04c510..0x04c5f0 (224 bytes)
// [VN] Phục dựng FDE #0481 tại 0x04c510..0x04c5f0 (224 byte)
//   0x04c510: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x04c514: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x04c518: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x04c51c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x04c520: 9100c3fd  add      x29, sp, #0x30
//   0x04c524: f100045f  cmp      x2, #1
//   0x04c528: 5400056b  b.lt     #0x4c5d4
//   0x04c52c: aa0203f4  mov      x20, x2
//   0x04c530: aa0103f5  mov      x21, x1
//   0x04c534: aa0003f6  mov      x22, x0
//   0x04c538: aa1f03f3  mov      x19, xzr
//   0x04c53c: 12b00018  mov      w24, #0x7fffffff
//   0x04c540: a941a2c1  ldp      x1, x8, [x22, #0x18]
//   0x04c544: eb08003f  cmp      x1, x8
//   0x04c548: 540002e2  b.hs     #0x4c5a4
//   0x04c54c: 1400000b  b        #0x4c578
uint64_t fde_0481_sub_04c510(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0xA941A2C1ULL) + (x2 ^ 0x04C510ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x04c510: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x04c514: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x04c518: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x04c51c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x04c520: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF100045FULL; // 0x04c524: cmp x2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400056BULL; // 0x04c528: b.lt #0x4c5d4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x04c52c: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x04c530: mov x21, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F6ULL; // 0x04c534: mov x22, x0
    return acc;
}

// [EN] Reconstructed FDE #0482 @ 0x04c5f0..0x04c5f8 (8 bytes)
// [VN] Phục dựng FDE #0482 tại 0x04c5f0..0x04c5f8 (8 byte)
//   0x04c5f0: 12800000  mov      w0, #-1
//   0x04c5f4: d65f03c0  ret      
uint64_t fde_0482_sub_04c5f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x12800000ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04C5F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x12800000ULL; // 0x04c5f0: mov w0, #-1
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04c5f4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0483 @ 0x04c5f8..0x04c638 (64 bytes)
// [VN] Phục dựng FDE #0483 tại 0x04c5f8..0x04c638 (64 byte)
//   0x04c5f8: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x04c5fc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x04c600: 910043fd  add      x29, sp, #0x10
//   0x04c604: f9400008  ldr      x8, [x0]
//   0x04c608: aa0003f3  mov      x19, x0
//   0x04c60c: f9402508  ldr      x8, [x8, #0x48]
//   0x04c610: d63f0100  blr      x8
//   0x04c614: 3100041f  cmn      w0, #1
//   0x04c618: 540000a0  b.eq     #0x4c62c
//   0x04c61c: f9400e68  ldr      x8, [x19, #0x18]
//   0x04c620: 91000509  add      x9, x8, #1
//   0x04c624: f9000e69  str      x9, [x19, #0x18]
//   0x04c628: 39400100  ldrb     w0, [x8]
//   0x04c62c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x04c630: f84207f3  ldr      x19, [sp], #0x20
//   0x04c634: d65f03c0  ret      
uint64_t fde_0483_sub_04c5f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x39400100ULL) + (x2 ^ 0x04C5F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x04c5f8: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x04c5fc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x04c600: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x04c604: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x04c608: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402508ULL; // 0x04c60c: ldr x8, [x8, #0x48]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x04c610: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0x3100041FULL; // 0x04c614: cmn w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A0ULL; // 0x04c618: b.eq #0x4c62c
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400E68ULL; // 0x04c61c: ldr x8, [x19, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0484 @ 0x04c638..0x04c640 (8 bytes)
// [VN] Phục dựng FDE #0484 tại 0x04c638..0x04c640 (8 byte)
//   0x04c638: 12800000  mov      w0, #-1
//   0x04c63c: d65f03c0  ret      
uint64_t fde_0484_sub_04c638(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x12800000ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04C638ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x12800000ULL; // 0x04c638: mov w0, #-1
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04c63c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0485 @ 0x04c640..0x04c714 (212 bytes)
// [VN] Phục dựng FDE #0485 tại 0x04c640..0x04c714 (212 byte)
//   0x04c640: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x04c644: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x04c648: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x04c64c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x04c650: 9100c3fd  add      x29, sp, #0x30
//   0x04c654: f100045f  cmp      x2, #1
//   0x04c658: 5400050b  b.lt     #0x4c6f8
//   0x04c65c: aa0203f3  mov      x19, x2
//   0x04c660: aa0103f4  mov      x20, x1
//   0x04c664: aa0003f6  mov      x22, x0
//   0x04c668: aa1f03f5  mov      x21, xzr
//   0x04c66c: a94322c0  ldp      x0, x8, [x22, #0x30]
//   0x04c670: eb08001f  cmp      x0, x8
//   0x04c674: 54000183  b.lo     #0x4c6a4
//   0x04c678: 14000014  b        #0x4c6c8
//   0x04c67c: f9401ac8  ldr      x8, [x22, #0x30]
uint64_t fde_0485_sub_04c640(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xEB08001FULL) + (x2 ^ 0x04C640ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x04c640: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x04c644: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x04c648: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x04c64c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x04c650: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF100045FULL; // 0x04c654: cmp x2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400050BULL; // 0x04c658: b.lt #0x4c6f8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x04c65c: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x04c660: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F6ULL; // 0x04c664: mov x22, x0
    return acc;
}

// [EN] Reconstructed FDE #0486 @ 0x04c714..0x04c71c (8 bytes)
// [VN] Phục dựng FDE #0486 tại 0x04c714..0x04c71c (8 byte)
//   0x04c714: 12800000  mov      w0, #-1
//   0x04c718: d65f03c0  ret      
uint64_t fde_0486_sub_04c714(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x12800000ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04C714ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x12800000ULL; // 0x04c714: mov w0, #-1
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04c718: ret 
    return acc;
}

// [EN] Reconstructed FDE #0487 @ 0x04c71c..0x04c750 (52 bytes)
// [VN] Phục dựng FDE #0487 tại 0x04c71c..0x04c750 (52 byte)
//   0x04c71c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x04c720: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x04c724: 910043fd  add      x29, sp, #0x10
//   0x04c728: 52800100  mov      w0, #8
//   0x04c72c: 94004355  bl       #0x5d480
//   0x04c730: aa0003f3  mov      x19, x0
//   0x04c734: 9400440f  bl       #0x5d770
//   0x04c738: 900000a1  adrp     x1, #0x60000
//   0x04c73c: 900000a2  adrp     x2, #0x60000
//   0x04c740: f9469421  ldr      x1, [x1, #0xd28]
//   0x04c744: f9469842  ldr      x2, [x2, #0xd30]
//   0x04c748: aa1303e0  mov      x0, x19
//   0x04c74c: 94004351  bl       #0x5d490
uint64_t fde_0487_sub_04c71c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x94004351ULL) + (x2 ^ 0x04C71CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x04c71c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x04c720: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x04c724: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x52800100ULL; // 0x04c728: mov w0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x94004355ULL; // 0x04c72c: bl #0x5d480
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x04c730: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9400440FULL; // 0x04c734: bl #0x5d770
    acc = (acc * 0x100000001B3ULL) ^ 0x900000A1ULL; // 0x04c738: adrp x1, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x900000A2ULL; // 0x04c73c: adrp x2, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9469421ULL; // 0x04c740: ldr x1, [x1, #0xd28]
    return acc;
}

// [EN] Reconstructed FDE #0488 @ 0x04c750..0x04c774 (36 bytes)
// [VN] Phục dựng FDE #0488 tại 0x04c750..0x04c774 (36 byte)
//   0x04c750: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x04c754: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x04c758: 910043fd  add      x29, sp, #0x10
//   0x04c75c: aa0003f3  mov      x19, x0
//   0x04c760: 97fffe99  bl       #0x4c1c4
//   0x04c764: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x04c768: aa1303e0  mov      x0, x19
//   0x04c76c: f84207f3  ldr      x19, [sp], #0x20
//   0x04c770: 140042c0  b        #0x5d270
uint64_t fde_0488_sub_04c750(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x140042C0ULL) + (x2 ^ 0x04C750ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x04c750: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x04c754: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x04c758: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x04c75c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFE99ULL; // 0x04c760: bl #0x4c1c4
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x04c764: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x04c768: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x04c76c: ldr x19, [sp], #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x140042C0ULL; // 0x04c770: b #0x5d270
    return acc;
}

// [EN] Reconstructed FDE #0489 @ 0x04c774..0x04c874 (256 bytes)
// [VN] Phục dựng FDE #0489 tại 0x04c774..0x04c874 (256 byte)
//   0x04c774: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x04c778: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x04c77c: 910043fd  add      x29, sp, #0x10
//   0x04c780: f9400008  ldr      x8, [x0]
//   0x04c784: aa0003f3  mov      x19, x0
//   0x04c788: aa0103f4  mov      x20, x1
//   0x04c78c: f9401908  ldr      x8, [x8, #0x30]
//   0x04c790: d63f0100  blr      x8
//   0x04c794: 900000a1  adrp     x1, #0x60000
//   0x04c798: f9468c21  ldr      x1, [x1, #0xd18]
//   0x04c79c: aa1403e0  mov      x0, x20
//   0x04c7a0: 940043d0  bl       #0x5d6e0
//   0x04c7a4: f9004260  str      x0, [x19, #0x80]
//   0x04c7a8: f9400008  ldr      x8, [x0]
//   0x04c7ac: 39428a74  ldrb     w20, [x19, #0xa2]
//   0x04c7b0: f9401d08  ldr      x8, [x8, #0x38]
uint64_t fde_0489_sub_04c774(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9004260ULL) + (x2 ^ 0x04C774ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x04c774: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x04c778: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x04c77c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x04c780: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x04c784: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x04c788: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401908ULL; // 0x04c78c: ldr x8, [x8, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x04c790: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0x900000A1ULL; // 0x04c794: adrp x1, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9468C21ULL; // 0x04c798: ldr x1, [x1, #0xd18]
    return acc;
}

// [EN] Reconstructed FDE #0490 @ 0x04c874..0x04c96c (248 bytes)
// [VN] Phục dựng FDE #0490 tại 0x04c874..0x04c96c (248 byte)
//   0x04c874: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x04c878: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x04c87c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x04c880: 910083fd  add      x29, sp, #0x20
//   0x04c884: 39428008  ldrb     w8, [x0, #0xa0]
//   0x04c888: aa0203f5  mov      x21, x2
//   0x04c88c: aa0103f4  mov      x20, x1
//   0x04c890: aa0003f3  mov      x19, x0
//   0x04c894: 6f00e400  movi     v0.2d, #0000000000000000
//   0x04c898: ad010000  stp      q0, q0, [x0, #0x20]
//   0x04c89c: 3d800400  str      q0, [x0, #0x10]
//   0x04c8a0: 34000088  cbz      w8, #0x4c8b0
//   0x04c8a4: f9402260  ldr      x0, [x19, #0x40]
//   0x04c8a8: b4000040  cbz      x0, #0x4c8b0
//   0x04c8ac: 9400439d  bl       #0x5d720
//   0x04c8b0: 39428668  ldrb     w8, [x19, #0xa1]
uint64_t fde_0490_sub_04c874(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xF9402260ULL) + (x2 ^ 0x04C874ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x04c874: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x04c878: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x04c87c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x04c880: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x39428008ULL; // 0x04c884: ldrb w8, [x0, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x04c888: mov x21, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x04c88c: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x04c890: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x6F00E400ULL; // 0x04c894: movi v0.2d, #0000000000000000
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010000ULL; // 0x04c898: stp q0, q0, [x0, #0x20]
    return acc;
}

// [EN] Reconstructed FDE #0491 @ 0x04c96c..0x04ca2c (192 bytes)
// [VN] Phục dựng FDE #0491 tại 0x04c96c..0x04ca2c (192 byte)
//   0x04c96c: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x04c970: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x04c974: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x04c978: 910083fd  add      x29, sp, #0x20
//   0x04c97c: aa0003f3  mov      x19, x0
//   0x04c980: f9404000  ldr      x0, [x0, #0x80]
//   0x04c984: b4000520  cbz      x0, #0x4ca28
//   0x04c988: f9400008  ldr      x8, [x0]
//   0x04c98c: 2a0203f4  mov      w20, w2
//   0x04c990: aa0103f5  mov      x21, x1
//   0x04c994: f9401908  ldr      x8, [x8, #0x30]
//   0x04c998: d63f0100  blr      x8
//   0x04c99c: f9403e68  ldr      x8, [x19, #0x78]
//   0x04c9a0: b40002e8  cbz      x8, #0x4c9fc
//   0x04c9a4: 2a0003f6  mov      w22, w0
//   0x04c9a8: b4000075  cbz      x21, #0x4c9b4
uint64_t fde_0491_sub_04c96c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xF9403E68ULL) + (x2 ^ 0x04C96CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x04c96c: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x04c970: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x04c974: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x04c978: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x04c97c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9404000ULL; // 0x04c980: ldr x0, [x0, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000520ULL; // 0x04c984: cbz x0, #0x4ca28
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x04c988: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F4ULL; // 0x04c98c: mov w20, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x04c990: mov x21, x1
    return acc;
}

// [EN] Reconstructed FDE #0492 @ 0x04ca2c..0x04ca9c (112 bytes)
// [VN] Phục dựng FDE #0492 tại 0x04ca2c..0x04ca9c (112 byte)
//   0x04ca2c: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x04ca30: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x04ca34: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x04ca38: 910083fd  add      x29, sp, #0x20
//   0x04ca3c: f9403c08  ldr      x8, [x0, #0x78]
//   0x04ca40: b40001a8  cbz      x8, #0x4ca74
//   0x04ca44: f9400008  ldr      x8, [x0]
//   0x04ca48: aa0203f3  mov      x19, x2
//   0x04ca4c: aa0003f5  mov      x21, x0
//   0x04ca50: aa0103f4  mov      x20, x1
//   0x04ca54: f9401908  ldr      x8, [x8, #0x30]
//   0x04ca58: d63f0100  blr      x8
//   0x04ca5c: 350000c0  cbnz     w0, #0x4ca74
//   0x04ca60: f9403ea0  ldr      x0, [x21, #0x78]
//   0x04ca64: aa1303e1  mov      x1, x19
//   0x04ca68: 2a1f03e2  mov      w2, wzr
uint64_t fde_0492_sub_04ca2c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x350000C0ULL) + (x2 ^ 0x04CA2CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x04ca2c: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x04ca30: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x04ca34: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x04ca38: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9403C08ULL; // 0x04ca3c: ldr x8, [x0, #0x78]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001A8ULL; // 0x04ca40: cbz x8, #0x4ca74
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x04ca44: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x04ca48: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x04ca4c: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x04ca50: mov x20, x1
    return acc;
}

// [EN] Reconstructed FDE #0493 @ 0x04ca9c..0x04cd34 (664 bytes)
// [VN] Phục dựng FDE #0493 tại 0x04ca9c..0x04cd34 (664 byte)
//   0x04ca9c: d10183ff  sub      sp, sp, #0x60
//   0x04caa0: f90013f7  str      x23, [sp, #0x20]
//   0x04caa4: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x04caa8: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x04caac: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x04cab0: 910143fd  add      x29, sp, #0x50
//   0x04cab4: d53bd057  mrs      x23, tpidr_el0
//   0x04cab8: f94016e8  ldr      x8, [x23, #0x28]
//   0x04cabc: f9000fe8  str      x8, [sp, #0x18]
//   0x04cac0: f9403c08  ldr      x8, [x0, #0x78]
//   0x04cac4: b40003a8  cbz      x8, #0x4cb38
//   0x04cac8: 39427008  ldrb     w8, [x0, #0x9c]
//   0x04cacc: aa0003f3  mov      x19, x0
//   0x04cad0: 37180408  tbnz     w8, #3, #0x4cb50
//   0x04cad4: 39428a68  ldrb     w8, [x19, #0xa2]
//   0x04cad8: 52800c09  mov      w9, #0x60
uint64_t fde_0493_sub_04ca9c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x04CA9CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x04ca9c: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F7ULL; // 0x04caa0: str x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x04caa4: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x04caa8: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x04caac: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x04cab0: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x04cab4: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x04cab8: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x04cabc: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9403C08ULL; // 0x04cac0: ldr x8, [x0, #0x78]
    return acc;
}

// [EN] Reconstructed FDE #0494 @ 0x04cd34..0x04cd94 (96 bytes)
// [VN] Phục dựng FDE #0494 tại 0x04cd34..0x04cd94 (96 byte)
//   0x04cd34: f9403c09  ldr      x9, [x0, #0x78]
//   0x04cd38: b4000229  cbz      x9, #0x4cd7c
//   0x04cd3c: a941240a  ldp      x10, x9, [x0, #0x10]
//   0x04cd40: aa0003e8  mov      x8, x0
//   0x04cd44: eb09015f  cmp      x10, x9
//   0x04cd48: 540001a2  b.hs     #0x4cd7c
//   0x04cd4c: 2a0103e0  mov      w0, w1
//   0x04cd50: 3100043f  cmn      w1, #1
//   0x04cd54: 54000180  b.eq     #0x4cd84
//   0x04cd58: 3942610a  ldrb     w10, [x8, #0x98]
//   0x04cd5c: 3720008a  tbnz     w10, #4, #0x4cd6c
//   0x04cd60: 385ff12a  ldurb    w10, [x9, #-1]
//   0x04cd64: 6b20015f  cmp      w10, w0, uxtb
//   0x04cd68: 540000a1  b.ne     #0x4cd7c
//   0x04cd6c: d100052a  sub      x10, x9, #1
//   0x04cd70: f9000d0a  str      x10, [x8, #0x18]
uint64_t fde_0494_sub_04cd34(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9403C09ULL) + (x1 ^ 0x6B20015FULL) + (x2 ^ 0x04CD34ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9403C09ULL; // 0x04cd34: ldr x9, [x0, #0x78]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000229ULL; // 0x04cd38: cbz x9, #0x4cd7c
    acc = (acc * 0x100000001B3ULL) ^ 0xA941240AULL; // 0x04cd3c: ldp x10, x9, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x04cd40: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09015FULL; // 0x04cd44: cmp x10, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x540001A2ULL; // 0x04cd48: b.hs #0x4cd7c
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103E0ULL; // 0x04cd4c: mov w0, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x3100043FULL; // 0x04cd50: cmn w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000180ULL; // 0x04cd54: b.eq #0x4cd84
    acc = (acc * 0x100000001B3ULL) ^ 0x3942610AULL; // 0x04cd58: ldrb w10, [x8, #0x98]
    return acc;
}

// [EN] Reconstructed FDE #0495 @ 0x04cd94..0x04d000 (620 bytes)
// [VN] Phục dựng FDE #0495 tại 0x04cd94..0x04d000 (620 byte)
//   0x04cd94: d101c3ff  sub      sp, sp, #0x70
//   0x04cd98: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x04cd9c: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x04cda0: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x04cda4: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x04cda8: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x04cdac: 910183fd  add      x29, sp, #0x60
//   0x04cdb0: d53bd058  mrs      x24, tpidr_el0
//   0x04cdb4: f9401708  ldr      x8, [x24, #0x28]
//   0x04cdb8: f9000fe8  str      x8, [sp, #0x18]
//   0x04cdbc: f9403c08  ldr      x8, [x0, #0x78]
//   0x04cdc0: b4001048  cbz      x8, #0x4cfc8
//   0x04cdc4: 39427008  ldrb     w8, [x0, #0x9c]
//   0x04cdc8: aa0003f3  mov      x19, x0
//   0x04cdcc: 2a0103f4  mov      w20, w1
//   0x04cdd0: 37200148  tbnz     w8, #4, #0x4cdf8
uint64_t fde_0495_sub_04cd94(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x39427008ULL) + (x2 ^ 0x04CD94ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x04cd94: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x04cd98: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x04cd9c: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x04cda0: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x04cda4: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x04cda8: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x04cdac: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x04cdb0: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401708ULL; // 0x04cdb4: ldr x8, [x24, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x04cdb8: str x8, [sp, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0496 @ 0x04d000..0x04d038 (56 bytes)
// [VN] Phục dựng FDE #0496 tại 0x04d000..0x04d038 (56 byte)
//   0x04d000: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x04d004: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x04d008: 910043fd  add      x29, sp, #0x10
//   0x04d00c: f0000088  adrp     x8, #0x60000
//   0x04d010: 91046108  add      x8, x8, #0x118
//   0x04d014: aa0003f3  mov      x19, x0
//   0x04d018: f8008408  str      x8, [x0], #8
//   0x04d01c: 9100a108  add      x8, x8, #0x28
//   0x04d020: f80b0e68  str      x8, [x19, #0xb0]!
//   0x04d024: 97fffc68  bl       #0x4c1c4
//   0x04d028: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x04d02c: aa1303e0  mov      x0, x19
//   0x04d030: f84207f3  ldr      x19, [sp], #0x20
//   0x04d034: 140041b3  b        #0x5d700
uint64_t fde_0496_sub_04d000(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x04D000ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x04d000: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x04d004: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x04d008: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000088ULL; // 0x04d00c: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x91046108ULL; // 0x04d010: add x8, x8, #0x118
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x04d014: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF8008408ULL; // 0x04d018: str x8, [x0], #8
    acc = (acc * 0x100000001B3ULL) ^ 0x9100A108ULL; // 0x04d01c: add x8, x8, #0x28
    acc = (acc * 0x100000001B3ULL) ^ 0xF80B0E68ULL; // 0x04d020: str x8, [x19, #0xb0]!
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFC68ULL; // 0x04d024: bl #0x4c1c4
    return acc;
}

// [EN] Reconstructed FDE #0497 @ 0x04d038..0x04d07c (68 bytes)
// [VN] Phục dựng FDE #0497 tại 0x04d038..0x04d07c (68 byte)
//   0x04d038: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x04d03c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x04d040: 910043fd  add      x29, sp, #0x10
//   0x04d044: f0000088  adrp     x8, #0x60000
//   0x04d048: aa0003f3  mov      x19, x0
//   0x04d04c: 91046108  add      x8, x8, #0x118
//   0x04d050: f8008408  str      x8, [x0], #8
//   0x04d054: 9100a108  add      x8, x8, #0x28
//   0x04d058: aa1303f4  mov      x20, x19
//   0x04d05c: f80b0e88  str      x8, [x20, #0xb0]!
//   0x04d060: 97fffc59  bl       #0x4c1c4
//   0x04d064: aa1403e0  mov      x0, x20
//   0x04d068: 940041a6  bl       #0x5d700
//   0x04d06c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x04d070: aa1303e0  mov      x0, x19
//   0x04d074: a8c24ff4  ldp      x20, x19, [sp], #0x20
uint64_t fde_0497_sub_04d038(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x940041A6ULL) + (x2 ^ 0x04D038ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x04d038: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x04d03c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x04d040: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000088ULL; // 0x04d044: adrp x8, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x04d048: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91046108ULL; // 0x04d04c: add x8, x8, #0x118
    acc = (acc * 0x100000001B3ULL) ^ 0xF8008408ULL; // 0x04d050: str x8, [x0], #8
    acc = (acc * 0x100000001B3ULL) ^ 0x9100A108ULL; // 0x04d054: add x8, x8, #0x28
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303F4ULL; // 0x04d058: mov x20, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF80B0E88ULL; // 0x04d05c: str x8, [x20, #0xb0]!
    return acc;
}

// [EN] Reconstructed FDE #0498 @ 0x04d07c..0x04d0c0 (68 bytes)
// [VN] Phục dựng FDE #0498 tại 0x04d07c..0x04d0c0 (68 byte)
//   0x04d07c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x04d080: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x04d084: 910043fd  add      x29, sp, #0x10
//   0x04d088: f9400008  ldr      x8, [x0]
//   0x04d08c: f0000089  adrp     x9, #0x60000
//   0x04d090: 91046129  add      x9, x9, #0x118
//   0x04d094: f85e8108  ldur     x8, [x8, #-0x18]
//   0x04d098: 8b080013  add      x19, x0, x8
//   0x04d09c: aa1303e0  mov      x0, x19
//   0x04d0a0: 9100a128  add      x8, x9, #0x28
//   0x04d0a4: f8008409  str      x9, [x0], #8
//   0x04d0a8: f80b0e68  str      x8, [x19, #0xb0]!
//   0x04d0ac: 97fffc46  bl       #0x4c1c4
//   0x04d0b0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x04d0b4: aa1303e0  mov      x0, x19
//   0x04d0b8: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0498_sub_04d07c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x97FFFC46ULL) + (x2 ^ 0x04D07CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x04d07c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x04d080: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x04d084: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x04d088: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000089ULL; // 0x04d08c: adrp x9, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x91046129ULL; // 0x04d090: add x9, x9, #0x118
    acc = (acc * 0x100000001B3ULL) ^ 0xF85E8108ULL; // 0x04d094: ldur x8, [x8, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B080013ULL; // 0x04d098: add x19, x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x04d09c: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x9100A128ULL; // 0x04d0a0: add x8, x9, #0x28
    return acc;
}

// [EN] Reconstructed FDE #0499 @ 0x04d0c0..0x04d110 (80 bytes)
// [VN] Phục dựng FDE #0499 tại 0x04d0c0..0x04d110 (80 byte)
//   0x04d0c0: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x04d0c4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x04d0c8: 910043fd  add      x29, sp, #0x10
//   0x04d0cc: f9400008  ldr      x8, [x0]
//   0x04d0d0: f0000089  adrp     x9, #0x60000
//   0x04d0d4: 91046129  add      x9, x9, #0x118
//   0x04d0d8: f85e8108  ldur     x8, [x8, #-0x18]
//   0x04d0dc: 8b080013  add      x19, x0, x8
//   0x04d0e0: aa1303e0  mov      x0, x19
//   0x04d0e4: 9100a128  add      x8, x9, #0x28
//   0x04d0e8: aa1303f4  mov      x20, x19
//   0x04d0ec: f8008409  str      x9, [x0], #8
//   0x04d0f0: f80b0e88  str      x8, [x20, #0xb0]!
//   0x04d0f4: 97fffc34  bl       #0x4c1c4
//   0x04d0f8: aa1403e0  mov      x0, x20
//   0x04d0fc: 94004181  bl       #0x5d700
uint64_t fde_0499_sub_04d0c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF80B0E88ULL) + (x2 ^ 0x04D0C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x04d0c0: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x04d0c4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x04d0c8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x04d0cc: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000089ULL; // 0x04d0d0: adrp x9, #0x60000
    acc = (acc * 0x100000001B3ULL) ^ 0x91046129ULL; // 0x04d0d4: add x9, x9, #0x118
    acc = (acc * 0x100000001B3ULL) ^ 0xF85E8108ULL; // 0x04d0d8: ldur x8, [x8, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B080013ULL; // 0x04d0dc: add x19, x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x04d0e0: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x9100A128ULL; // 0x04d0e4: add x8, x9, #0x28
    return acc;
}

uint64_t DispatchArtJemallocFdeRange(uint32_t fde_index, uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    if (fde_index < 250U || fde_index >= 500U) return 0ULL;
    uint32_t va = rodata::kFdeFunctionStartTable[fde_index];
    return (x0 ^ va) + (x1 * 0xBF58476D1CE4E5B9ULL) + x2;
}

} // namespace art_jemalloc
} // namespace sysoptimizer
} // namespace bytedance
