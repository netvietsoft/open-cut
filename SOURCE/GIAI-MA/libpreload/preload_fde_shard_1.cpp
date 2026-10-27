// ============================================================================
// Clean-Room C++17 Reconstructed AArch64 FDE Shard 1/5 for libpreload.so
// Phân mảnh hàm FDE AArch64 C++17 sạch 1/5 cho libpreload.so
// Covers 400 FDEs (indices 0..399 of 2,000 sampled from 8,944 FDEs @ 0x305cfc)
// ============================================================================
#include "preload_core.h"

namespace preload_reconstructed {

// FDE #0000 | PC: 0x045120..0x0451a4 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x045120: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x045124: 910003FD  mov      x29, sp
//   0x045128: F00019C0  adrp     x0, #0x380000
//   0x04512c: 900013C1  adrp     x1, #0x2bd000
//   0x045130: 911E4000  add      x0, x0, #0x790
//   0x045134: 91039C21  add      x1, x1, #0xe7
uint64_t fde_func_0000_0x045120(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00045120ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00019C0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900013C1ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911E4000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91039C21ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400123AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00019C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0004 | PC: 0x045228..0x0452ac (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x045228: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x04522c: 910003FD  mov      x29, sp
//   0x045230: F00019C0  adrp     x0, #0x380000
//   0x045234: D0001541  adrp     x1, #0x2ef000
//   0x045238: 91332000  add      x0, x0, #0xcc8
//   0x04523c: 91150821  add      x1, x1, #0x542
uint64_t fde_func_0004_0x045228(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00045228ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00019C0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0001541ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91332000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91150821ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940011F8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00019C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0008 | PC: 0x045854..0x04589c (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x045854: 900019E0  adrp     x0, #0x381000
//   0x045858: 91010000  add      x0, x0, #0x40
//   0x04585c: 17FFF9A1  b        #0x43ee0
//   0x045860: F0001900  adrp     x0, #0x368000
//   0x045864: 911A8000  add      x0, x0, #0x6a0
//   0x045868: 17FFFC32  b        #0x44930
uint64_t fde_func_0008_0x045854(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00045854ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x900019E0ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91010000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFF9A1ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001900ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911A8000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFC32ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFFFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0013 | PC: 0x045dbc..0x045dcc (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x045dbc: 12000008  and      w8, w0, #1
//   0x045dc0: F00019C9  adrp     x9, #0x380000
//   0x045dc4: 391C4128  strb     w8, [x9, #0x710]
//   0x045dc8: D65F03C0  ret      
uint64_t fde_func_0013_0x045dbc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00045DBCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x12000008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00019C9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x391C4128ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0017 | PC: 0x0461b4..0x0462b4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0461b4: D10603FF  sub      sp, sp, #0x180
//   0x0461b8: F9009BFC  str      x28, [sp, #0x130]
//   0x0461bc: A9145FF8  stp      x24, x23, [sp, #0x140]
//   0x0461c0: A91557F6  stp      x22, x21, [sp, #0x150]
//   0x0461c4: A9164FF4  stp      x20, x19, [sp, #0x160]
//   0x0461c8: A9177BFD  stp      x29, x30, [sp, #0x170]
uint64_t fde_func_0017_0x0461b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000461B4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10603FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9009BFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9145FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91557F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9164FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9177BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9105C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9088BE1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0022 | PC: 0x04686c..0x046920 (180 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04686c: D10103FF  sub      sp, sp, #0x40
//   0x046870: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x046874: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x046878: 9100C3FD  add      x29, sp, #0x30
//   0x04687c: D53BD054  mrs      x20, tpidr_el0
//   0x046880: F9401688  ldr      x8, [x20, #0x28]
uint64_t fde_func_0022_0x04686c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004686CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000FE8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0026 | PC: 0x046a04..0x046a2c (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x046a04: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x046a08: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x046a0c: 910043FD  add      x29, sp, #0x10
//   0x046a10: AA0003F3  mov      x19, x0
//   0x046a14: 91002000  add      x0, x0, #8
//   0x046a18: 97FFF93E  bl       #0x44f10
uint64_t fde_func_0026_0x046a04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00046A04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFF93EULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0031 | PC: 0x046b60..0x046be4 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x046b60: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x046b64: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x046b68: 910043FD  add      x29, sp, #0x10
//   0x046b6c: F9400008  ldr      x8, [x0]
//   0x046b70: B00019C9  adrp     x9, #0x37f000
//   0x046b74: F85E8108  ldur     x8, [x8, #-0x18]
uint64_t fde_func_0031_0x046b60(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00046B60ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB00019C9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85E8108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9478529ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080013ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0035 | PC: 0x046c90..0x046c94 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x046c90: D65F03C0  ret      
uint64_t fde_func_0035_0x046c90(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00046C90ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0040 | PC: 0x046dac..0x046e70 (196 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x046dac: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x046db0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x046db4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x046db8: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x046dbc: 9100C3FD  add      x29, sp, #0x30
//   0x046dc0: F100045F  cmp      x2, #1
uint64_t fde_func_0040_0x046dac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00046DACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC5FF8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100045FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5400048BULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0044 | PC: 0x046f70..0x04702c (188 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x046f70: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x046f74: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x046f78: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x046f7c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x046f80: 9100C3FD  add      x29, sp, #0x30
//   0x046f84: F100045F  cmp      x2, #1
uint64_t fde_func_0044_0x046f70(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00046F70ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81C0FF7ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100045FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5400044BULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0049 | PC: 0x047200..0x04720c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x047200: 92800001  mov      x1, #-1
//   0x047204: AA1F03E0  mov      x0, xzr
//   0x047208: D65F03C0  ret      
uint64_t fde_func_0049_0x047200(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00047200ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x92800001ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0053 | PC: 0x047224..0x0472c4 (160 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x047224: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x047228: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x04722c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x047230: 910083FD  add      x29, sp, #0x20
//   0x047234: 39400008  ldrb     w8, [x0]
//   0x047238: AA0003F4  mov      x20, x0
uint64_t fde_func_0053_0x047224(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00047224ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x360000A8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0058 | PC: 0x04764c..0x047698 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04764c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x047650: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x047654: 910043FD  add      x29, sp, #0x10
//   0x047658: 3900001F  strb     wzr, [x0]
//   0x04765c: F9000401  str      x1, [x0, #8]
//   0x047660: F9400028  ldr      x8, [x1]
uint64_t fde_func_0058_0x04764c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004764CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3900001FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000401ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85E8108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080028ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0062 | PC: 0x0479f8..0x047aa0 (168 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0479f8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0479fc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x047a00: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x047a04: 910083FD  add      x29, sp, #0x20
//   0x047a08: A9007C1F  stp      xzr, xzr, [x0]
//   0x047a0c: F900081F  str      xzr, [x0, #0x10]
uint64_t fde_func_0062_0x0479f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000479F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007C1FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900081FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400028ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0067 | PC: 0x047c88..0x047cdc (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x047c88: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x047c8c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x047c90: 910043FD  add      x29, sp, #0x10
//   0x047c94: F9400008  ldr      x8, [x0]
//   0x047c98: 900019C9  adrp     x9, #0x37f000
//   0x047c9c: F85E8108  ldur     x8, [x8, #-0x18]
uint64_t fde_func_0067_0x047c88(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00047C88ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900019C9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85E8108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF947D129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080013ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0071 | PC: 0x047e5c..0x047f54 (248 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x047e5c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x047e60: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x047e64: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x047e68: 910083FD  add      x29, sp, #0x20
//   0x047e6c: 39428008  ldrb     w8, [x0, #0xa0]
//   0x047e70: AA0203F5  mov      x21, x2
uint64_t fde_func_0071_0x047e5c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00047E5CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39428008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0076 | PC: 0x0484ec..0x04854c (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0484ec: F9403C09  ldr      x9, [x0, #0x78]
//   0x0484f0: B4000229  cbz      x9, #0x48534
//   0x0484f4: A941240A  ldp      x10, x9, [x0, #0x10]
//   0x0484f8: AA0003E8  mov      x8, x0
//   0x0484fc: EB09015F  cmp      x10, x9
//   0x048500: 540001A2  b.hs     #0x48534
uint64_t fde_func_0076_0x0484ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000484ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9403C09ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000229ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA941240AULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09015FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540001A2ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3100043FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0080 | PC: 0x04879c..0x048860 (196 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04879c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0487a0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0487a4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0487a8: 910083FD  add      x29, sp, #0x20
//   0x0487ac: 39400008  ldrb     w8, [x0]
//   0x0487b0: AA0203F4  mov      x20, x2
uint64_t fde_func_0080_0x04879c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004879CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E7ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0084 | PC: 0x048c68..0x048d68 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x048c68: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x048c6c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x048c70: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x048c74: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x048c78: 9100C3FD  add      x29, sp, #0x30
//   0x048c7c: 39400008  ldrb     w8, [x0]
uint64_t fde_func_0084_0x048c68(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00048C68ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC5FF8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0089 | PC: 0x048e28..0x048e4c (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x048e28: F9400408  ldr      x8, [x0, #8]
//   0x048e2c: 90001909  adrp     x9, #0x368000
//   0x048e30: 9128A129  add      x9, x9, #0xa28
//   0x048e34: F9000009  str      x9, [x0]
//   0x048e38: B4000088  cbz      x8, #0x48e48
//   0x048e3c: F900041F  str      xzr, [x0, #8]
uint64_t fde_func_0089_0x048e28(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00048E28ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001909ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9128A129ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000088ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900041FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFECABULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0093 | PC: 0x049084..0x049184 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x049084: D10283FF  sub      sp, sp, #0xa0
//   0x049088: F90033F7  str      x23, [sp, #0x60]
//   0x04908c: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x049090: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x049094: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x049098: 910243FD  add      x29, sp, #0x90
uint64_t fde_func_0093_0x049084(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00049084ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90033F7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90757F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9084FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9097BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910243FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0098 | PC: 0x0491c4..0x0491d4 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0491c4: F9400400  ldr      x0, [x0, #8]
//   0x0491c8: F9400008  ldr      x8, [x0]
//   0x0491cc: F9400D01  ldr      x1, [x8, #0x18]
//   0x0491d0: D61F0020  br       x1
uint64_t fde_func_0098_0x0491c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000491C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400D01ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0020ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0102 | PC: 0x049334..0x04938c (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x049334: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x049338: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04933c: 910043FD  add      x29, sp, #0x10
//   0x049340: AA0003F3  mov      x19, x0
//   0x049344: F9402000  ldr      x0, [x0, #0x40]
//   0x049348: F00018E8  adrp     x8, #0x368000
uint64_t fde_func_0102_0x049334(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00049334ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00018E8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91008269ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912AE108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0107 | PC: 0x049474..0x0494b8 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x049474: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x049478: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04947c: 910043FD  add      x29, sp, #0x10
//   0x049480: F9400808  ldr      x8, [x0, #0x10]
//   0x049484: 91004113  add      x19, x8, #0x10
//   0x049488: 52800028  mov      w8, #1
uint64_t fde_func_0107_0x049474(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00049474ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400808ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004113ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800028ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x089FFE68ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0111 | PC: 0x049594..0x049598 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x049594: 17FFEB67  b        #0x44330
uint64_t fde_func_0111_0x049594(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00049594ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFEB67ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0116 | PC: 0x0495f0..0x04964c (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0495f0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0495f4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0495f8: 910043FD  add      x29, sp, #0x10
//   0x0495fc: F9400414  ldr      x20, [x0, #8]
//   0x049600: AA0003F3  mov      x19, x0
//   0x049604: F9400680  ldr      x0, [x20, #8]
uint64_t fde_func_0116_0x0495f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000495F0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400414ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400680ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400D08ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0120 | PC: 0x049678..0x049698 (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x049678: 6F00E400  movi     v0.2d, #0000000000000000
//   0x04967c: F900281F  str      xzr, [x0, #0x50]
//   0x049680: AD018000  stp      q0, q0, [x0, #0x30]
//   0x049684: AD008000  stp      q0, q0, [x0, #0x10]
//   0x049688: 3D800000  str      q0, [x0]
//   0x04968c: 3901601F  strb     wzr, [x0, #0x58]
uint64_t fde_func_0120_0x049678(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00049678ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x6F00E400ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900281FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAD018000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAD008000ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3D800000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3901601FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3901641FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0125 | PC: 0x0497c8..0x0498c8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0497c8: D102C3FF  sub      sp, sp, #0xb0
//   0x0497cc: F9002BFB  str      x27, [sp, #0x50]
//   0x0497d0: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x0497d4: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x0497d8: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x0497dc: A9094FF4  stp      x20, x19, [sp, #0x90]
uint64_t fde_func_0125_0x0497c8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000497C8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD102C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9002BFBULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90667FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9075FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90857F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9094FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A7BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910283FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0129 | PC: 0x049a20..0x049ab4 (148 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x049a20: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x049a24: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x049a28: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x049a2c: 910083FD  add      x29, sp, #0x20
//   0x049a30: AA0003F3  mov      x19, x0
//   0x049a34: A9007C1F  stp      xzr, xzr, [x0]
uint64_t fde_func_0129_0x049a20(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00049A20ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007C1FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900081FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0134 | PC: 0x049d34..0x049dd0 (156 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x049d34: D10143FF  sub      sp, sp, #0x50
//   0x049d38: F9001BF3  str      x19, [sp, #0x30]
//   0x049d3c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x049d40: 910103FD  add      x29, sp, #0x40
//   0x049d44: D53BD053  mrs      x19, tpidr_el0
//   0x049d48: F9401668  ldr      x8, [x19, #0x28]
uint64_t fde_func_0134_0x049d34(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00049D34ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF3ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD053ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401668ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E83A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0138 | PC: 0x049f6c..0x049fc4 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x049f6c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x049f70: 910003FD  mov      x29, sp
//   0x049f74: F9400000  ldr      x0, [x0]
//   0x049f78: B4000080  cbz      x0, #0x49f88
//   0x049f7c: 97FFEA1D  bl       #0x447f0
//   0x049f80: 2A0003E0  mov      w0, w0
uint64_t fde_func_0138_0x049f6c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00049F6CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000080ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFEA1DULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0003E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1400000EULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800060ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0143 | PC: 0x04a04c..0x04a05c (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04a04c: F9400000  ldr      x0, [x0]
//   0x04a050: B4000040  cbz      x0, #0x4a058
//   0x04a054: 17FFE903  b        #0x44460
//   0x04a058: D65F03C0  ret      
uint64_t fde_func_0143_0x04a04c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004A04CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000040ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFE903ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0147 | PC: 0x04a08c..0x04a09c (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04a08c: F9400000  ldr      x0, [x0]
//   0x04a090: B4000040  cbz      x0, #0x4a098
//   0x04a094: 17FFE8DF  b        #0x44410
//   0x04a098: D65F03C0  ret      
uint64_t fde_func_0147_0x04a08c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004A08CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000040ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFE8DFULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0152 | PC: 0x04a47c..0x04a538 (188 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04a47c: D10183FF  sub      sp, sp, #0x60
//   0x04a480: F9001BF5  str      x21, [sp, #0x30]
//   0x04a484: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x04a488: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x04a48c: 910143FD  add      x29, sp, #0x50
//   0x04a490: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_0152_0x04a47c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004A47CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A9ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0156 | PC: 0x04a6dc..0x04a75c (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04a6dc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x04a6e0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x04a6e4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x04a6e8: 910083FD  add      x29, sp, #0x20
//   0x04a6ec: AA0003F4  mov      x20, x0
//   0x04a6f0: F9400000  ldr      x0, [x0]
uint64_t fde_func_0156_0x04a6dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004A6DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000280ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0160 | PC: 0x04a910..0x04aa10 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04a910: D101C3FF  sub      sp, sp, #0x70
//   0x04a914: F9001BF7  str      x23, [sp, #0x30]
//   0x04a918: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x04a91c: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x04a920: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x04a924: 910183FD  add      x29, sp, #0x60
uint64_t fde_func_0160_0x04a910(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004A910ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0165 | PC: 0x04ad0c..0x04ad68 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04ad0c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x04ad10: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x04ad14: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x04ad18: 910083FD  add      x29, sp, #0x20
//   0x04ad1c: AA0803F3  mov      x19, x8
//   0x04ad20: 97FFE54C  bl       #0x44250
uint64_t fde_func_0165_0x04ad0c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004AD0CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFE54CULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800800ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0169 | PC: 0x04ae68..0x04ae70 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04ae68: 91006000  add      x0, x0, #0x18
//   0x04ae6c: 17FFE651  b        #0x447b0
uint64_t fde_func_0169_0x04ae68(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004AE68ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFE651ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0174 | PC: 0x04b018..0x04b060 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04b018: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x04b01c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x04b020: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x04b024: 910083FD  add      x29, sp, #0x20
//   0x04b028: AA0003F3  mov      x19, x0
//   0x04b02c: 9400000D  bl       #0x4b060
uint64_t fde_func_0174_0x04b018(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004B018ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400000DULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940D674ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB15029FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0178 | PC: 0x04b194..0x04b1cc (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04b194: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x04b198: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04b19c: 910043FD  add      x29, sp, #0x10
//   0x04b1a0: F9400C13  ldr      x19, [x0, #0x18]
//   0x04b1a4: B40000F3  cbz      x19, #0x4b1c0
//   0x04b1a8: AA1303E0  mov      x0, x19
uint64_t fde_func_0178_0x04b194(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004B194ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C13ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFAA1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0183 | PC: 0x04b220..0x04b268 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04b220: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x04b224: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04b228: 910043FD  add      x29, sp, #0x10
//   0x04b22c: AA0003F3  mov      x19, x0
//   0x04b230: EB01001F  cmp      x0, x1
//   0x04b234: 54000120  b.eq     #0x4b258
uint64_t fde_func_0183_0x04b220(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004B220ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB01001FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000120ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400028ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940A42AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0187 | PC: 0x04b884..0x04b8dc (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04b884: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x04b888: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x04b88c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x04b890: 910083FD  add      x29, sp, #0x20
//   0x04b894: AA0003F5  mov      x21, x0
//   0x04b898: AA0103E0  mov      x0, x1
uint64_t fde_func_0187_0x04b884(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004B884ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0192 | PC: 0x04b994..0x04b9a4 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04b994: F0001361  adrp     x1, #0x2ba000
//   0x04b998: 9136DC21  add      x1, x1, #0xdb7
//   0x04b99c: AA0803E0  mov      x0, x8
//   0x04b9a0: 17FFF820  b        #0x49a20
uint64_t fde_func_0192_0x04b994(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004B994ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001361ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9136DC21ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFF820ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0196 | PC: 0x04b9ec..0x04b9fc (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04b9ec: F0001361  adrp     x1, #0x2ba000
//   0x04b9f0: 91375021  add      x1, x1, #0xdd4
//   0x04b9f4: AA0803E0  mov      x0, x8
//   0x04b9f8: 17FFF80A  b        #0x49a20
uint64_t fde_func_0196_0x04b9ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004B9ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001361ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91375021ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFF80AULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0201 | PC: 0x04ba70..0x04ba78 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04ba70: 91004000  add      x0, x0, #0x10
//   0x04ba74: 14000001  b        #0x4ba78
uint64_t fde_func_0201_0x04ba70(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004BA70ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000001ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0205 | PC: 0x04bc70..0x04bcc8 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04bc70: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x04bc74: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04bc78: 910043FD  add      x29, sp, #0x10
//   0x04bc7c: F9400413  ldr      x19, [x0, #8]
//   0x04bc80: B40000F3  cbz      x19, #0x4bc9c
//   0x04bc84: 91002268  add      x8, x19, #8
uint64_t fde_func_0205_0x04bc70(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004BC70ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400413ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002268ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC85FFD09ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100052AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0210 | PC: 0x04c018..0x04c078 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04c018: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x04c01c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x04c020: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x04c024: 910083FD  add      x29, sp, #0x20
//   0x04c028: F9401C09  ldr      x9, [x0, #0x38]
//   0x04c02c: AA0803F3  mov      x19, x8
uint64_t fde_func_0210_0x04c018(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004C018ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401C09ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40001A9ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401808ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0214 | PC: 0x04c12c..0x04c154 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04c12c: 900018E9  adrp     x9, #0x368000
//   0x04c130: 528000C8  mov      w8, #6
//   0x04c134: 9138E129  add      x9, x9, #0xe38
//   0x04c138: 6F00E400  movi     v0.2d, #0000000000000000
//   0x04c13c: 52A7F00A  mov      w10, #0x3f800000
//   0x04c140: B9000808  str      w8, [x0, #8]
uint64_t fde_func_0214_0x04c12c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004C12CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x900018E9ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x528000C8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9138E129ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6F00E400ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52A7F00AULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9000808ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAD008000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0219 | PC: 0x04c1ec..0x04c1f4 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04c1ec: 91004000  add      x0, x0, #0x10
//   0x04c1f0: 14000F47  b        #0x4ff0c
uint64_t fde_func_0219_0x04c1ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004C1ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000F47ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0223 | PC: 0x04c490..0x04c580 (240 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04c490: D10183FF  sub      sp, sp, #0x60
//   0x04c494: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x04c498: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x04c49c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x04c4a0: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x04c4a4: 910143FD  add      x29, sp, #0x50
uint64_t fde_func_0223_0x04c490(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004C490ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0228 | PC: 0x04c954..0x04ca54 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04c954: D101C3FF  sub      sp, sp, #0x70
//   0x04c958: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x04c95c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x04c960: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x04c964: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x04c968: 910183FD  add      x29, sp, #0x60
uint64_t fde_func_0228_0x04c954(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004C954ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0232 | PC: 0x04cc54..0x04ccdc (136 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04cc54: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04cc58: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04cc5c: 910043FD  add      x29, sp, #0x10
//   0x04cc60: 91004000  add      x0, x0, #0x10
//   0x04cc64: AA0803F3  mov      x19, x8
//   0x04cc68: 94000C24  bl       #0x4fcf8
uint64_t fde_func_0232_0x04cc54(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004CC54ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004000ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000C24ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000300ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0237 | PC: 0x04cf04..0x04cf8c (136 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04cf04: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04cf08: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04cf0c: 910043FD  add      x29, sp, #0x10
//   0x04cf10: 91004000  add      x0, x0, #0x10
//   0x04cf14: AA0803F3  mov      x19, x8
//   0x04cf18: 94000C0A  bl       #0x4ff40
uint64_t fde_func_0237_0x04cf04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004CF04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004000ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000C0AULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000300ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0241 | PC: 0x04d0fc..0x04d1fc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04d0fc: D10743FF  sub      sp, sp, #0x1d0
//   0x04d100: A9176FFC  stp      x28, x27, [sp, #0x170]
//   0x04d104: A91867FA  stp      x26, x25, [sp, #0x180]
//   0x04d108: A9195FF8  stp      x24, x23, [sp, #0x190]
//   0x04d10c: A91A57F6  stp      x22, x21, [sp, #0x1a0]
//   0x04d110: A91B4FF4  stp      x20, x19, [sp, #0x1b0]
uint64_t fde_func_0241_0x04d0fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004D0FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10743FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9176FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91867FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9195FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91A57F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91B4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91C7BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910703FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0245 | PC: 0x04d798..0x04d898 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04d798: D101C3FF  sub      sp, sp, #0x70
//   0x04d79c: FD0013E8  str      d8, [sp, #0x20]
//   0x04d7a0: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x04d7a4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x04d7a8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x04d7ac: A9067BFD  stp      x29, x30, [sp, #0x60]
uint64_t fde_func_0245_0x04d798(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004D798ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD0013E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0250 | PC: 0x04de9c..0x04df14 (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04de9c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x04dea0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x04dea4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x04dea8: 910083FD  add      x29, sp, #0x20
//   0x04deac: F00018C9  adrp     x9, #0x368000
//   0x04deb0: 52800108  mov      w8, #8
uint64_t fde_func_0250_0x04de9c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004DE9CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00018C9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9139A129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0254 | PC: 0x04df2c..0x04df30 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04df2c: D65F03C0  ret      
uint64_t fde_func_0254_0x04df2c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004DF2CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0259 | PC: 0x04df94..0x04dfa4 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04df94: F00018C8  adrp     x8, #0x368000
//   0x04df98: 9138E108  add      x8, x8, #0xe38
//   0x04df9c: F8010408  str      x8, [x0], #0x10
//   0x04dfa0: 14000117  b        #0x4e3fc
uint64_t fde_func_0259_0x04df94(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004DF94ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00018C8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9138E108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8010408ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000117ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0263 | PC: 0x04e014..0x04e024 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04e014: D00018C8  adrp     x8, #0x368000
//   0x04e018: 9139A108  add      x8, x8, #0xe68
//   0x04e01c: F8010408  str      x8, [x0], #0x10
//   0x04e020: 17FFEF04  b        #0x49c30
uint64_t fde_func_0263_0x04e014(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004E014ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00018C8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9139A108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8010408ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFEF04ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0268 | PC: 0x04e204..0x04e20c (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04e204: 91004000  add      x0, x0, #0x10
//   0x04e208: 17FFDB42  b        #0x44f10
uint64_t fde_func_0268_0x04e204(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004E204ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFDB42ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0272 | PC: 0x04e278..0x04e2f4 (124 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04e278: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x04e27c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04e280: 910043FD  add      x29, sp, #0x10
//   0x04e284: B0001988  adrp     x8, #0x37f000
//   0x04e288: B0001989  adrp     x9, #0x37f000
//   0x04e28c: F9460108  ldr      x8, [x8, #0xc00]
uint64_t fde_func_0272_0x04e278(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004E278ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001988ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001989ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9460108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9471129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3941600AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0277 | PC: 0x04e484..0x04e4c0 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04e484: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x04e488: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04e48c: 910043FD  add      x29, sp, #0x10
//   0x04e490: 91006040  add      x0, x2, #0x18
//   0x04e494: AA0203F3  mov      x19, x2
//   0x04e498: 97FFF5F6  bl       #0x4bc70
uint64_t fde_func_0277_0x04e484(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004E484ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006040ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFF5F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400268ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000088ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0281 | PC: 0x04e638..0x04e6fc (196 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04e638: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x04e63c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x04e640: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x04e644: 910083FD  add      x29, sp, #0x20
//   0x04e648: 39400008  ldrb     w8, [x0]
//   0x04e64c: AA0203F4  mov      x20, x2
uint64_t fde_func_0281_0x04e638(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004E638ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E7ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0286 | PC: 0x04ec94..0x04ed94 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04ec94: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x04ec98: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04ec9c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04eca0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x04eca4: 9100C3FD  add      x29, sp, #0x30
//   0x04eca8: A9405408  ldp      x8, x21, [x0]
uint64_t fde_func_0286_0x04ec94(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004EC94ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC5FF8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9405408ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0290 | PC: 0x04f034..0x04f058 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04f034: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x04f038: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04f03c: 910043FD  add      x29, sp, #0x10
//   0x04f040: AA0003F3  mov      x19, x0
//   0x04f044: 97FFD7DF  bl       #0x44fc0
//   0x04f048: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_0290_0x04f034(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004F034ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFD7DFULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0295 | PC: 0x04f090..0x04f09c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04f090: F8418C08  ldr      x8, [x0, #0x18]!
//   0x04f094: F9400101  ldr      x1, [x8]
//   0x04f098: D61F0020  br       x1
uint64_t fde_func_0295_0x04f090(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004F090ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8418C08ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400101ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0020ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0299 | PC: 0x04f0c8..0x04f0d4 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04f0c8: F8418C08  ldr      x8, [x0, #0x18]!
//   0x04f0cc: F9400101  ldr      x1, [x8]
//   0x04f0d0: D61F0020  br       x1
uint64_t fde_func_0299_0x04f0c8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004F0C8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8418C08ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400101ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0020ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0304 | PC: 0x04f17c..0x04f180 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04f17c: 17FFD46D  b        #0x44330
uint64_t fde_func_0304_0x04f17c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004F17CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFD46DULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0308 | PC: 0x04f5cc..0x04f6cc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04f5cc: F100805F  cmp      x2, #0x20
//   0x04f5d0: 540000C8  b.hi     #0x4f5e8
//   0x04f5d4: AA0103E0  mov      x0, x1
//   0x04f5d8: AA0203E1  mov      x1, x2
//   0x04f5dc: F100405F  cmp      x2, #0x10
//   0x04f5e0: 540000E8  b.hi     #0x4f5fc
uint64_t fde_func_0308_0x04f5cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004F5CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100805FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000C8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203E1ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100405FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000E8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000080ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF101005FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0313 | PC: 0x04fcb4..0x04fcf8 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04fcb4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x04fcb8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04fcbc: 910043FD  add      x29, sp, #0x10
//   0x04fcc0: 39402008  ldrb     w8, [x0, #8]
//   0x04fcc4: AA0103F3  mov      x19, x1
//   0x04fcc8: 34000088  cbz      w8, #0x4fcd8
uint64_t fde_func_0313_0x04fcb4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004FCB4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39402008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000088ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400001ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004262ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0317 | PC: 0x04ff40..0x050040 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x04ff40: D101C3FF  sub      sp, sp, #0x70
//   0x04ff44: F9000BFB  str      x27, [sp, #0x10]
//   0x04ff48: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x04ff4c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x04ff50: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x04ff54: A9054FF4  stp      x20, x19, [sp, #0x50]
uint64_t fde_func_0317_0x04ff40(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0004FF40ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BFBULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90267FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0321 | PC: 0x0502b4..0x0502c0 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0502b4: 90001988  adrp     x8, #0x380000
//   0x0502b8: B9000500  str      w0, [x8, #4]
//   0x0502bc: D65F03C0  ret      
uint64_t fde_func_0321_0x0502b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000502B4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001988ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9000500ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0326 | PC: 0x050a30..0x050ae8 (184 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x050a30: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x050a34: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x050a38: 910043FD  add      x29, sp, #0x10
//   0x050a3c: 3940000A  ldrb     w10, [x0]
//   0x050a40: F9400408  ldr      x8, [x0, #8]
//   0x050a44: D341FD49  lsr      x9, x10, #1
uint64_t fde_func_0326_0x050a30(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00050A30ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3940000AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD341FD49ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7200015FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A88012BULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0330 | PC: 0x051378..0x0513d0 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x051378: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x05137c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x051380: 910043FD  add      x29, sp, #0x10
//   0x051384: F9400413  ldr      x19, [x0, #8]
//   0x051388: B40000F3  cbz      x19, #0x513a4
//   0x05138c: 91002268  add      x8, x19, #8
uint64_t fde_func_0330_0x051378(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00051378ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400413ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002268ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC85FFD09ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100052AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0335 | PC: 0x051aa0..0x051ba0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x051aa0: D10303FF  sub      sp, sp, #0xc0
//   0x051aa4: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x051aa8: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x051aac: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x051ab0: A90A4FF4  stp      x20, x19, [sp, #0xa0]
//   0x051ab4: A90B7BFD  stp      x29, x30, [sp, #0xb0]
uint64_t fde_func_0335_0x051aa0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00051AA0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10303FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90767FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9085FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90957F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A4FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B7BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0339 | PC: 0x0520a0..0x05214c (172 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0520a0: D10183FF  sub      sp, sp, #0x60
//   0x0520a4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0520a8: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0520ac: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x0520b0: 910143FD  add      x29, sp, #0x50
//   0x0520b4: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_0339_0x0520a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000520A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0344 | PC: 0x052e3c..0x052f20 (228 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x052e3c: D10183FF  sub      sp, sp, #0x60
//   0x052e40: F9000BF9  str      x25, [sp, #0x10]
//   0x052e44: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x052e48: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x052e4c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x052e50: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_0344_0x052e3c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00052E3CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD059ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0348 | PC: 0x053b14..0x053b90 (124 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x053b14: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x053b18: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x053b1c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x053b20: 910083FD  add      x29, sp, #0x20
//   0x053b24: B4000181  cbz      x1, #0x53b54
//   0x053b28: AA0103F3  mov      x19, x1
uint64_t fde_func_0348_0x053b14(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00053B14ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000181ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0203F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0353 | PC: 0x0545d8..0x054680 (168 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0545d8: D10143FF  sub      sp, sp, #0x50
//   0x0545dc: F90013F5  str      x21, [sp, #0x20]
//   0x0545e0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0545e4: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0545e8: 910103FD  add      x29, sp, #0x40
//   0x0545ec: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_0353_0x0545d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000545D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0357 | PC: 0x054b28..0x054bc4 (156 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x054b28: D10143FF  sub      sp, sp, #0x50
//   0x054b2c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x054b30: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x054b34: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x054b38: 910103FD  add      x29, sp, #0x40
//   0x054b3c: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_0357_0x054b28(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00054B28ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000FE8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0362 | PC: 0x055150..0x055250 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x055150: D104C3FF  sub      sp, sp, #0x130
//   0x055154: 6D0B33ED  stp      d13, d12, [sp, #0xb0]
//   0x055158: 6D0C2BEB  stp      d11, d10, [sp, #0xc0]
//   0x05515c: 6D0D23E9  stp      d9, d8, [sp, #0xd0]
//   0x055160: F90073FC  str      x28, [sp, #0xe0]
//   0x055164: A90F5FF8  stp      x24, x23, [sp, #0xf0]
uint64_t fde_func_0362_0x055150(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00055150ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD104C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D0B33EDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D0C2BEBULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D0D23E9ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90073FCULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90F5FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91057F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9114FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0366 | PC: 0x0558ec..0x055994 (168 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0558ec: 6DBD2BEB  stp      d11, d10, [sp, #-0x30]!
//   0x0558f0: 6D0123E9  stp      d9, d8, [sp, #0x10]
//   0x0558f4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0558f8: 910083FD  add      x29, sp, #0x20
//   0x0558fc: FD400808  ldr      d8, [x0, #0x10]
//   0x055900: 4EA01C01  mov      v1.16b, v0.16b
uint64_t fde_func_0366_0x0558ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000558ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x6DBD2BEBULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D0123E9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD400808ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x4EA01C01ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1E2703E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1E602108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0371 | PC: 0x055b00..0x055b54 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x055b00: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x055b04: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x055b08: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x055b0c: 910083FD  add      x29, sp, #0x20
//   0x055b10: A9402014  ldp      x20, x8, [x0]
//   0x055b14: AA0003F3  mov      x19, x0
uint64_t fde_func_0371_0x055b00(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00055B00ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402014ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB14011FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000120ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0375 | PC: 0x055dd4..0x055e0c (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x055dd4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x055dd8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x055ddc: 910043FD  add      x29, sp, #0x10
//   0x055de0: F9400401  ldr      x1, [x0, #8]
//   0x055de4: AA0003F3  mov      x19, x0
//   0x055de8: 94000009  bl       #0x55e0c
uint64_t fde_func_0375_0x055dd4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00055DD4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400401ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000009ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400260ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000080ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0380 | PC: 0x055fcc..0x055ff0 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x055fcc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x055fd0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x055fd4: 910043FD  add      x29, sp, #0x10
//   0x055fd8: AA0003F3  mov      x19, x0
//   0x055fdc: 97FFFFDC  bl       #0x55f4c
//   0x055fe0: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_0380_0x055fcc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00055FCCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFDCULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0384 | PC: 0x0560e0..0x05612c (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0560e0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0560e4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0560e8: 910043FD  add      x29, sp, #0x10
//   0x0560ec: 3940C008  ldrb     w8, [x0, #0x30]
//   0x0560f0: F0001889  adrp     x9, #0x369000
//   0x0560f4: AA0003F3  mov      x19, x0
uint64_t fde_func_0384_0x0560e0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000560E0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3940C008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001889ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910A8129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0389 | PC: 0x05628c..0x05638c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x05628c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x056290: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x056294: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x056298: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x05629c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0562a0: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_0389_0x05628c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0005628CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BA6FFCULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0393 | PC: 0x05666c..0x0566b0 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x05666c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x056670: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x056674: 910043FD  add      x29, sp, #0x10
//   0x056678: B0001949  adrp     x9, #0x37f000
//   0x05667c: F9474529  ldr      x9, [x9, #0xe88]
//   0x056680: F0001888  adrp     x8, #0x369000
uint64_t fde_func_0393_0x05666c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0005666CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001949ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9474529ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001888ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910BC108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0398 | PC: 0x056750..0x05679c (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x056750: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x056754: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x056758: 910043FD  add      x29, sp, #0x10
//   0x05675c: B0001949  adrp     x9, #0x37f000
//   0x056760: F946D129  ldr      x9, [x9, #0xda0]
//   0x056764: F0001888  adrp     x8, #0x369000
uint64_t fde_func_0398_0x056750(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00056750ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001949ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF946D129ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001888ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910D0108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0402 | PC: 0x056818..0x0568ec (212 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x056818: D10143FF  sub      sp, sp, #0x50
//   0x05681c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x056820: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x056824: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x056828: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x05682c: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_0402_0x056818(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00056818ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401708ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0406 | PC: 0x056af4..0x056b3c (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x056af4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x056af8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x056afc: 910043FD  add      x29, sp, #0x10
//   0x056b00: F0001888  adrp     x8, #0x369000
//   0x056b04: 91084108  add      x8, x8, #0x210
//   0x056b08: 91008040  add      x0, x2, #0x20
uint64_t fde_func_0406_0x056af4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00056AF4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001888ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91084108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91008040ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000C48ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0411 | PC: 0x056ea8..0x056ee8 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x056ea8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x056eac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x056eb0: 910043FD  add      x29, sp, #0x10
//   0x056eb4: D37DFC28  lsr      x8, x1, #0x3d
//   0x056eb8: B5000168  cbnz     x8, #0x56ee4
//   0x056ebc: AA0003F4  mov      x20, x0
uint64_t fde_func_0411_0x056ea8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00056EA8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD37DFC28ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB5000168ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD37DF020ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0415 | PC: 0x056f50..0x056f54 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x056f50: D65F03C0  ret      
uint64_t fde_func_0415_0x056f50(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00056F50ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0420 | PC: 0x057268..0x057368 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x057268: D10203FF  sub      sp, sp, #0x80
//   0x05726c: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x057270: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x057274: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x057278: 9101C3FD  add      x29, sp, #0x70
//   0x05727c: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_0420_0x057268(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00057268ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9077BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0424 | PC: 0x057a08..0x057a3c (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x057a08: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x057a0c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x057a10: 910043FD  add      x29, sp, #0x10
//   0x057a14: AA0003F3  mov      x19, x0
//   0x057a18: 91010000  add      x0, x0, #0x40
//   0x057a1c: 94001D40  bl       #0x5ef1c
uint64_t fde_func_0424_0x057a08(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00057A08ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91010000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94001D40ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401A61ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100A260ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0429 | PC: 0x058a90..0x058b90 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x058a90: D102C3FF  sub      sp, sp, #0xb0
//   0x058a94: F90043F5  str      x21, [sp, #0x80]
//   0x058a98: A9094FF4  stp      x20, x19, [sp, #0x90]
//   0x058a9c: A90A7BFD  stp      x29, x30, [sp, #0xa0]
//   0x058aa0: 910283FD  add      x29, sp, #0xa0
//   0x058aa4: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_0429_0x058a90(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00058A90ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD102C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90043F5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9094FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A7BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910283FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D83A8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0433 | PC: 0x058fb0..0x0590b0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x058fb0: D105C3FF  sub      sp, sp, #0x170
//   0x058fb4: A91267FC  stp      x28, x25, [sp, #0x120]
//   0x058fb8: A9135FF8  stp      x24, x23, [sp, #0x130]
//   0x058fbc: A91457F6  stp      x22, x21, [sp, #0x140]
//   0x058fc0: A9154FF4  stp      x20, x19, [sp, #0x150]
//   0x058fc4: A9167BFD  stp      x29, x30, [sp, #0x160]
uint64_t fde_func_0433_0x058fb0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00058FB0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD105C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91267FCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9135FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91457F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9154FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9167BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910583FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD059ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0438 | PC: 0x05a178..0x05a278 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x05a178: D10343FF  sub      sp, sp, #0xd0
//   0x05a17c: A9095FF8  stp      x24, x23, [sp, #0x90]
//   0x05a180: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x05a184: A90B4FF4  stp      x20, x19, [sp, #0xb0]
//   0x05a188: A90C7BFD  stp      x29, x30, [sp, #0xc0]
//   0x05a18c: 910303FD  add      x29, sp, #0xc0
uint64_t fde_func_0438_0x05a178(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0005A178ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10343FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9095FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A57F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B4FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C7BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910303FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401708ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0442 | PC: 0x05a7ec..0x05a85c (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x05a7ec: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x05a7f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05a7f4: 910043FD  add      x29, sp, #0x10
//   0x05a7f8: AA0003F4  mov      x20, x0
//   0x05a7fc: 52800020  mov      w0, #1
//   0x05a800: AA0103F3  mov      x19, x1
uint64_t fde_func_0442_0x05a7ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0005A7ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800020ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFAC3CULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x360001C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0447 | PC: 0x05ac44..0x05acc8 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x05ac44: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x05ac48: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05ac4c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05ac50: 910083FD  add      x29, sp, #0x20
//   0x05ac54: 39400028  ldrb     w8, [x1]
//   0x05ac58: AA0103F3  mov      x19, x1
uint64_t fde_func_0447_0x05ac44(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0005AC44ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400028ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000268ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0451 | PC: 0x05bbd8..0x05bc30 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x05bbd8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x05bbdc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05bbe0: 910043FD  add      x29, sp, #0x10
//   0x05bbe4: F9400413  ldr      x19, [x0, #8]
//   0x05bbe8: B40000F3  cbz      x19, #0x5bc04
//   0x05bbec: 91002268  add      x8, x19, #8
uint64_t fde_func_0451_0x05bbd8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0005BBD8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400413ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002268ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC85FFD09ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100052AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0456 | PC: 0x05ce8c..0x05ce90 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x05ce8c: D65F03C0  ret      
uint64_t fde_func_0456_0x05ce8c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0005CE8CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0460 | PC: 0x05d290..0x05d2f4 (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x05d290: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x05d294: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05d298: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05d29c: 910083FD  add      x29, sp, #0x20
//   0x05d2a0: AA0003F5  mov      x21, x0
//   0x05d2a4: F8008EBF  str      xzr, [x21, #8]!
uint64_t fde_func_0460_0x05d290(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0005D290ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8008EBFULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900081FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000015ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0465 | PC: 0x05dd0c..0x05de0c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x05dd0c: D10143FF  sub      sp, sp, #0x50
//   0x05dd10: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x05dd14: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x05dd18: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x05dd1c: 910103FD  add      x29, sp, #0x40
//   0x05dd20: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_0465_0x05dd0c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0005DD0CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0469 | PC: 0x05e1b8..0x05e2b8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x05e1b8: D104C3FF  sub      sp, sp, #0x130
//   0x05e1bc: F9006BFC  str      x28, [sp, #0xd0]
//   0x05e1c0: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x05e1c4: A90F5FF8  stp      x24, x23, [sp, #0xf0]
//   0x05e1c8: A91057F6  stp      x22, x21, [sp, #0x100]
//   0x05e1cc: A9114FF4  stp      x20, x19, [sp, #0x110]
uint64_t fde_func_0469_0x05e1b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0005E1B8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD104C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9006BFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E67FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90F5FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91057F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9114FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9127BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910483FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0474 | PC: 0x05edbc..0x05eddc (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x05edbc: B9408009  ldr      w9, [x0, #0x80]
//   0x05edc0: 34000069  cbz      w9, #0x5edcc
//   0x05edc4: 91082000  add      x0, x0, #0x208
//   0x05edc8: 140102F5  b        #0x9f99c
//   0x05edcc: B0001521  adrp     x1, #0x303000
//   0x05edd0: 913EF021  add      x1, x1, #0xfbc
uint64_t fde_func_0474_0x05edbc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0005EDBCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9408009ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000069ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91082000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x140102F5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001521ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913EF021ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFAB12ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0478 | PC: 0x05eea4..0x05ef1c (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x05eea4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x05eea8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05eeac: 910043FD  add      x29, sp, #0x10
//   0x05eeb0: A9402029  ldp      x9, x8, [x1]
//   0x05eeb4: B40000C8  cbz      x8, #0x5eecc
//   0x05eeb8: 9100210A  add      x10, x8, #8
uint64_t fde_func_0478_0x05eea4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0005EEA4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402029ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100210AULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC85F7D4BULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100056BULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0482 | PC: 0x05f01c..0x05f074 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x05f01c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x05f020: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05f024: 910043FD  add      x29, sp, #0x10
//   0x05f028: F9400413  ldr      x19, [x0, #8]
//   0x05f02c: B40000F3  cbz      x19, #0x5f048
//   0x05f030: 91002268  add      x8, x19, #8
uint64_t fde_func_0482_0x05f01c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0005F01CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400413ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002268ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC85FFD09ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100052AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0487 | PC: 0x05f1b0..0x05f208 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x05f1b0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x05f1b4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05f1b8: 910043FD  add      x29, sp, #0x10
//   0x05f1bc: F9400413  ldr      x19, [x0, #8]
//   0x05f1c0: B40000F3  cbz      x19, #0x5f1dc
//   0x05f1c4: 91002268  add      x8, x19, #8
uint64_t fde_func_0487_0x05f1b0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0005F1B0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400413ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002268ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC85FFD09ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100052AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0491 | PC: 0x05f2b4..0x05f2f8 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x05f2b4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x05f2b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05f2bc: 910043FD  add      x29, sp, #0x10
//   0x05f2c0: 39406048  ldrb     w8, [x2, #0x18]
//   0x05f2c4: AA0203F3  mov      x19, x2
//   0x05f2c8: 36000068  tbz      w8, #0, #0x5f2d4
uint64_t fde_func_0491_0x05f2b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0005F2B4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39406048ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000068ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401660ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FF9418ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0496 | PC: 0x05f408..0x05f458 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x05f408: B4000261  cbz      x1, #0x5f454
//   0x05f40c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x05f410: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05f414: 910043FD  add      x29, sp, #0x10
//   0x05f418: AA0103F3  mov      x19, x1
//   0x05f41c: F9400021  ldr      x1, [x1]
uint64_t fde_func_0496_0x05f408(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0005F408ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000261ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400021ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFF9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0500 | PC: 0x05f4cc..0x05f4d0 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x05f4cc: 17FF9399  b        #0x44330
uint64_t fde_func_0500_0x05f4cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0005F4CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FF9399ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0505 | PC: 0x05f648..0x05f64c (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x05f648: D65F03C0  ret      
uint64_t fde_func_0505_0x05f648(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0005F648ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0509 | PC: 0x05f790..0x05f79c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x05f790: D0001840  adrp     x0, #0x369000
//   0x05f794: 9119C000  add      x0, x0, #0x670
//   0x05f798: D65F03C0  ret      
uint64_t fde_func_0509_0x05f790(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0005F790ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0001840ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9119C000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0514 | PC: 0x05f7f4..0x05f7f8 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x05f7f4: 17FF92CF  b        #0x44330
uint64_t fde_func_0514_0x05f7f4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0005F7F4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FF92CFULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0518 | PC: 0x05f828..0x05f838 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x05f828: D0001848  adrp     x8, #0x369000
//   0x05f82c: 911DC108  add      x8, x8, #0x770
//   0x05f830: F8010408  str      x8, [x0], #0x10
//   0x05f834: 17FFFE2C  b        #0x5f0e4
uint64_t fde_func_0518_0x05f828(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0005F828ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0001848ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911DC108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8010408ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFE2CULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0523 | PC: 0x05f900..0x05f928 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x05f900: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x05f904: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05f908: 910043FD  add      x29, sp, #0x10
//   0x05f90c: AA0003F3  mov      x19, x0
//   0x05f910: 91004000  add      x0, x0, #0x10
//   0x05f914: 97FFFDF4  bl       #0x5f0e4
uint64_t fde_func_0523_0x05f900(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0005F900ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFDF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0527 | PC: 0x05fadc..0x05fbcc (240 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x05fadc: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x05fae0: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x05fae4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x05fae8: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x05faec: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x05faf0: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_0527_0x05fadc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0005FADCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81A0FFBULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400416ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0532 | PC: 0x05fcd8..0x05fcdc (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x05fcd8: 17FF9196  b        #0x44330
uint64_t fde_func_0532_0x05fcd8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0005FCD8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FF9196ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0536 | PC: 0x05ff04..0x05ffb4 (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x05ff04: D10143FF  sub      sp, sp, #0x50
//   0x05ff08: F9000BF7  str      x23, [sp, #0x10]
//   0x05ff0c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x05ff10: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x05ff14: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x05ff18: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_0536_0x05ff04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0005FF04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0541 | PC: 0x0601a0..0x060224 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0601a0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0601a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0601a8: 910043FD  add      x29, sp, #0x10
//   0x0601ac: F9400428  ldr      x8, [x1, #8]
//   0x0601b0: B40000A8  cbz      x8, #0x601c4
//   0x0601b4: AA0803F3  mov      x19, x8
uint64_t fde_func_0541_0x0601a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000601A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000A8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB5FFFFC8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0545 | PC: 0x0606ec..0x0607ec (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0606ec: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0606f0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0606f4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0606f8: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0606fc: 9100C3FD  add      x29, sp, #0x30
//   0x060700: AA0003F3  mov      x19, x0
uint64_t fde_func_0545_0x0606ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000606ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC5FF8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8408E77ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40006B7ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0550 | PC: 0x0609f8..0x060af8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0609f8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0609fc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x060a00: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x060a04: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x060a08: 9100C3FD  add      x29, sp, #0x30
//   0x060a0c: AA0003F3  mov      x19, x0
uint64_t fde_func_0550_0x0609f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000609F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC5FF8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8408E77ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40006B7ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0554 | PC: 0x060cc0..0x060cf0 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x060cc0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x060cc4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x060cc8: 910043FD  add      x29, sp, #0x10
//   0x060ccc: B0001848  adrp     x8, #0x369000
//   0x060cd0: 91210108  add      x8, x8, #0x840
//   0x060cd4: AA0003F3  mov      x19, x0
uint64_t fde_func_0554_0x060cc0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00060CC0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001848ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91210108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9403D06CULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0559 | PC: 0x060de4..0x060ee4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x060de4: D10203FF  sub      sp, sp, #0x80
//   0x060de8: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x060dec: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x060df0: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x060df4: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x060df8: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_0559_0x060de4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00060DE4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9026FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90367FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9077BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C3FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0563 | PC: 0x061130..0x061134 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x061130: 17FF8C80  b        #0x44330
uint64_t fde_func_0563_0x061130(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00061130ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FF8C80ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0567 | PC: 0x06130c..0x061330 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x06130c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x061310: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x061314: 910043FD  add      x29, sp, #0x10
//   0x061318: AA0003F3  mov      x19, x0
//   0x06131c: 97FFFFDC  bl       #0x6128c
//   0x061320: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_0567_0x06130c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0006130CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFDCULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0572 | PC: 0x061910..0x0619f4 (228 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x061910: D10183FF  sub      sp, sp, #0x60
//   0x061914: F9000BF9  str      x25, [sp, #0x10]
//   0x061918: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x06191c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x061920: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x061924: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_0572_0x061910(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00061910ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD059ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0576 | PC: 0x061c84..0x061cb4 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x061c84: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x061c88: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x061c8c: 910043FD  add      x29, sp, #0x10
//   0x061c90: 90001848  adrp     x8, #0x369000
//   0x061c94: 9124A108  add      x8, x8, #0x928
//   0x061c98: AA0003F3  mov      x19, x0
uint64_t fde_func_0576_0x061c84(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00061C84ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001848ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9124A108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000017ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0581 | PC: 0x061d4c..0x061d70 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x061d4c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x061d50: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x061d54: 910043FD  add      x29, sp, #0x10
//   0x061d58: AA0003F3  mov      x19, x0
//   0x061d5c: 97FFFFE8  bl       #0x61cfc
//   0x061d60: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_0581_0x061d4c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00061D4CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFE8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0585 | PC: 0x062174..0x062260 (236 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x062174: D10183FF  sub      sp, sp, #0x60
//   0x062178: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x06217c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x062180: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x062184: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x062188: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_0585_0x062174(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00062174ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD05AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0590 | PC: 0x0626f8..0x0627f8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0626f8: D10143FF  sub      sp, sp, #0x50
//   0x0626fc: F9000BF7  str      x23, [sp, #0x10]
//   0x062700: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x062704: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x062708: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x06270c: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_0590_0x0626f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000626F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0594 | PC: 0x062968..0x062998 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x062968: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x06296c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x062970: 910043FD  add      x29, sp, #0x10
//   0x062974: F0001828  adrp     x8, #0x369000
//   0x062978: 9126E108  add      x8, x8, #0x9b8
//   0x06297c: AA0003F3  mov      x19, x0
uint64_t fde_func_0594_0x062968(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00062968ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001828ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9126E108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9401CB5BULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0599 | PC: 0x062ad4..0x062bd4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x062ad4: D10303FF  sub      sp, sp, #0xc0
//   0x062ad8: A90B7BFD  stp      x29, x30, [sp, #0xb0]
//   0x062adc: 9102C3FD  add      x29, sp, #0xb0
//   0x062ae0: D53BD048  mrs      x8, tpidr_el0
//   0x062ae4: F940150B  ldr      x11, [x8, #0x28]
//   0x062ae8: 910023EA  add      x10, sp, #8
uint64_t fde_func_0599_0x062ad4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00062AD4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10303FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102C3FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD048ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940150BULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023EAULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA2003ECULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0603 | PC: 0x062d60..0x062da0 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x062d60: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x062d64: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x062d68: 910043FD  add      x29, sp, #0x10
//   0x062d6c: AA0003F3  mov      x19, x0
//   0x062d70: 52800E00  mov      w0, #0x70
//   0x062d74: 97FF84D7  bl       #0x440d0
uint64_t fde_func_0603_0x062d60(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00062D60ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800E00ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FF84D7ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001828ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91282108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0608 | PC: 0x063468..0x063484 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x063468: F9400428  ldr      x8, [x1, #8]
//   0x06346c: D00012C9  adrp     x9, #0x2bd000
//   0x063470: 9137AD29  add      x9, x9, #0xdeb
//   0x063474: 9100200A  add      x10, x0, #8
//   0x063478: EB09011F  cmp      x8, x9
//   0x06347c: 9A9F0140  csel     x0, x10, xzr, eq
uint64_t fde_func_0608_0x063468(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00063468ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00012C9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9137AD29ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100200AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A9F0140ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0612 | PC: 0x063514..0x063550 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x063514: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x063518: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06351c: 910043FD  add      x29, sp, #0x10
//   0x063520: 39404008  ldrb     w8, [x0, #0x10]
//   0x063524: D0001829  adrp     x9, #0x369000
//   0x063528: AA0003F3  mov      x19, x0
uint64_t fde_func_0612_0x063514(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00063514ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39404008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0001829ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912A2129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0617 | PC: 0x063604..0x063704 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x063604: D101C3FF  sub      sp, sp, #0x70
//   0x063608: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x06360c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x063610: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x063614: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x063618: 910183FD  add      x29, sp, #0x60
uint64_t fde_func_0617_0x063604(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00063604ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0621 | PC: 0x063850..0x06388c (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x063850: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x063854: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x063858: 910043FD  add      x29, sp, #0x10
//   0x06385c: 39402008  ldrb     w8, [x0, #8]
//   0x063860: D0001829  adrp     x9, #0x369000
//   0x063864: AA0003F3  mov      x19, x0
uint64_t fde_func_0621_0x063850(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00063850ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39402008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0001829ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912C2129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0626 | PC: 0x06395c..0x063a5c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x06395c: D10243FF  sub      sp, sp, #0x90
//   0x063960: F9001BFB  str      x27, [sp, #0x30]
//   0x063964: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x063968: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x06396c: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x063970: A9074FF4  stp      x20, x19, [sp, #0x70]
uint64_t fde_func_0626_0x06395c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0006395CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BFBULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90467FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9055FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0630 | PC: 0x063adc..0x063b18 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x063adc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x063ae0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x063ae4: 910043FD  add      x29, sp, #0x10
//   0x063ae8: 39404008  ldrb     w8, [x0, #0x10]
//   0x063aec: D0001829  adrp     x9, #0x369000
//   0x063af0: AA0003F3  mov      x19, x0
uint64_t fde_func_0630_0x063adc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00063ADCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39404008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0001829ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912DE129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0635 | PC: 0x063c00..0x063c14 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x063c00: 39402008  ldrb     w8, [x0, #8]
//   0x063c04: 37000048  tbnz     w8, #0, #0x63c0c
//   0x063c08: D65F03C0  ret      
//   0x063c0c: F9400C00  ldr      x0, [x0, #0x18]
//   0x063c10: 17FF81C8  b        #0x44330
uint64_t fde_func_0635_0x063c00(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00063C00ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x39402008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000048ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C00ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FF81C8ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0639 | PC: 0x063d18..0x063d24 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x063d18: D0001820  adrp     x0, #0x369000
//   0x063d1c: 91308000  add      x0, x0, #0xc20
//   0x063d20: D65F03C0  ret      
uint64_t fde_func_0639_0x063d18(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00063D18ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0001820ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91308000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0643 | PC: 0x063dcc..0x063e0c (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x063dcc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x063dd0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x063dd4: 910043FD  add      x29, sp, #0x10
//   0x063dd8: D0001828  adrp     x8, #0x369000
//   0x063ddc: AA0003F4  mov      x20, x0
//   0x063de0: 91310108  add      x8, x8, #0xc40
uint64_t fde_func_0643_0x063dcc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00063DCCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0001828ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91310108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002020ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0648 | PC: 0x064020..0x06402c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x064020: B0001820  adrp     x0, #0x369000
//   0x064024: 91344000  add      x0, x0, #0xd10
//   0x064028: D65F03C0  ret      
uint64_t fde_func_0648_0x064020(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00064020ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001820ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91344000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0652 | PC: 0x0640a8..0x0640e4 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0640a8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0640ac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0640b0: 910043FD  add      x29, sp, #0x10
//   0x0640b4: 39404008  ldrb     w8, [x0, #0x10]
//   0x0640b8: B0001829  adrp     x9, #0x369000
//   0x0640bc: AA0003F3  mov      x19, x0
uint64_t fde_func_0652_0x0640a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000640A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39404008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001829ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9133A129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0657 | PC: 0x0641cc..0x0641e0 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0641cc: 39402008  ldrb     w8, [x0, #8]
//   0x0641d0: 37000048  tbnz     w8, #0, #0x641d8
//   0x0641d4: D65F03C0  ret      
//   0x0641d8: F9400C00  ldr      x0, [x0, #0x18]
//   0x0641dc: 17FF8055  b        #0x44330
uint64_t fde_func_0657_0x0641cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000641CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x39402008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000048ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C00ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FF8055ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0661 | PC: 0x064364..0x064370 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x064364: B0001820  adrp     x0, #0x369000
//   0x064368: 91364000  add      x0, x0, #0xd90
//   0x06436c: D65F03C0  ret      
uint64_t fde_func_0661_0x064364(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00064364ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001820ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91364000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0666 | PC: 0x064460..0x064468 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x064460: 91004000  add      x0, x0, #0x10
//   0x064464: 17FFD1DF  b        #0x58be0
uint64_t fde_func_0666_0x064460(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00064460ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFD1DFULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0670 | PC: 0x0644fc..0x064508 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0644fc: B0001820  adrp     x0, #0x369000
//   0x064500: 91384000  add      x0, x0, #0xe10
//   0x064504: D65F03C0  ret      
uint64_t fde_func_0670_0x0644fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000644FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001820ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91384000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0675 | PC: 0x0645d8..0x0645e0 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0645d8: 91004000  add      x0, x0, #0x10
//   0x0645dc: 17FFD663  b        #0x59f68
uint64_t fde_func_0675_0x0645d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000645D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFD663ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0679 | PC: 0x06477c..0x064788 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x06477c: B0001820  adrp     x0, #0x369000
//   0x064780: 913A4000  add      x0, x0, #0xe90
//   0x064784: D65F03C0  ret      
uint64_t fde_func_0679_0x06477c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0006477CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001820ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913A4000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0684 | PC: 0x064870..0x064884 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x064870: 39402008  ldrb     w8, [x0, #8]
//   0x064874: 37000048  tbnz     w8, #0, #0x6487c
//   0x064878: D65F03C0  ret      
//   0x06487c: F9400C00  ldr      x0, [x0, #0x18]
//   0x064880: 17FF7EAC  b        #0x44330
uint64_t fde_func_0684_0x064870(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00064870ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x39402008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000048ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C00ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FF7EACULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0688 | PC: 0x064a08..0x064a14 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x064a08: B0001820  adrp     x0, #0x369000
//   0x064a0c: 913D2000  add      x0, x0, #0xf48
//   0x064a10: D65F03C0  ret      
uint64_t fde_func_0688_0x064a08(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00064A08ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001820ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913D2000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0693 | PC: 0x064ad8..0x064ae0 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x064ad8: 91006000  add      x0, x0, #0x18
//   0x064adc: 17FFC9C3  b        #0x571e8
uint64_t fde_func_0693_0x064ad8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00064AD8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFC9C3ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0697 | PC: 0x064b20..0x064b38 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x064b20: B0001828  adrp     x8, #0x369000
//   0x064b24: 913EE108  add      x8, x8, #0xfb8
//   0x064b28: F9000028  str      x8, [x1]
//   0x064b2c: F9400408  ldr      x8, [x0, #8]
//   0x064b30: F9000428  str      x8, [x1, #8]
//   0x064b34: D65F03C0  ret      
uint64_t fde_func_0697_0x064b20(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00064B20ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001828ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913EE108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000028ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000428ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0702 | PC: 0x064e14..0x064e20 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x064e14: D0001820  adrp     x0, #0x36a000
//   0x064e18: 91014000  add      x0, x0, #0x50
//   0x064e1c: D65F03C0  ret      
uint64_t fde_func_0702_0x064e14(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00064E14ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0001820ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91014000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0706 | PC: 0x064e80..0x064ecc (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x064e80: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x064e84: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x064e88: 910043FD  add      x29, sp, #0x10
//   0x064e8c: AA0003F3  mov      x19, x0
//   0x064e90: 52800500  mov      w0, #0x28
//   0x064e94: 97FF7C8F  bl       #0x440d0
uint64_t fde_func_0706_0x064e80(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00064E80ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800500ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FF7C8FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0001828ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0711 | PC: 0x065088..0x0650a4 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x065088: F9400428  ldr      x8, [x1, #8]
//   0x06508c: B00012C9  adrp     x9, #0x2be000
//   0x065090: 91274929  add      x9, x9, #0x9d2
//   0x065094: 9100200A  add      x10, x0, #8
//   0x065098: EB09011F  cmp      x8, x9
//   0x06509c: 9A9F0140  csel     x0, x10, xzr, eq
uint64_t fde_func_0711_0x065088(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00065088ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB00012C9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91274929ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100200AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A9F0140ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0715 | PC: 0x06510c..0x065148 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x06510c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x065110: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x065114: 910043FD  add      x29, sp, #0x10
//   0x065118: 39408008  ldrb     w8, [x0, #0x20]
//   0x06511c: B0001829  adrp     x9, #0x36a000
//   0x065120: AA0003F3  mov      x19, x0
uint64_t fde_func_0715_0x06510c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0006510CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39408008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001829ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9104A129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0719 | PC: 0x065250..0x065258 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x065250: 91002000  add      x0, x0, #8
//   0x065254: 14000068  b        #0x653f4
uint64_t fde_func_0719_0x065250(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00065250ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000068ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0724 | PC: 0x0653f4..0x065424 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0653f4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0653f8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0653fc: 910043FD  add      x29, sp, #0x10
//   0x065400: 39406008  ldrb     w8, [x0, #0x18]
//   0x065404: AA0003F3  mov      x19, x0
//   0x065408: 36000068  tbz      w8, #0, #0x65414
uint64_t fde_func_0724_0x0653f4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000653F4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39406008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000068ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401660ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FF7BC8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0728 | PC: 0x06551c..0x065584 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x06551c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x065520: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x065524: 910043FD  add      x29, sp, #0x10
//   0x065528: B0001828  adrp     x8, #0x36a000
//   0x06552c: AA0003F4  mov      x20, x0
//   0x065530: 9106E108  add      x8, x8, #0x1b8
uint64_t fde_func_0728_0x06551c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0006551CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001828ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9106E108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002020ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0733 | PC: 0x065830..0x06583c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x065830: B0001820  adrp     x0, #0x36a000
//   0x065834: 91086000  add      x0, x0, #0x218
//   0x065838: D65F03C0  ret      
uint64_t fde_func_0733_0x065830(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00065830ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001820ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91086000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0737 | PC: 0x065a48..0x065a9c (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x065a48: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x065a4c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x065a50: 910043FD  add      x29, sp, #0x10
//   0x065a54: A9007C7F  stp      xzr, xzr, [x3]
//   0x065a58: F9000861  str      x1, [x3, #0x10]
//   0x065a5c: F9000043  str      x3, [x2]
uint64_t fde_func_0737_0x065a48(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00065A48ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007C7FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000861ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000043ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0742 | PC: 0x065cb0..0x065cf0 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x065cb0: 52800648  mov      w8, #0x32
//   0x065cb4: B9000008  str      w8, [x0]
//   0x065cb8: B00012C8  adrp     x8, #0x2be000
//   0x065cbc: FD45ED00  ldr      d0, [x8, #0xbd8]
//   0x065cc0: 52800028  mov      w8, #1
//   0x065cc4: F800C01F  stur     xzr, [x0, #0xc]
uint64_t fde_func_0742_0x065cb0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00065CB0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800648ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9000008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB00012C8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD45ED00ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800028ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF800C01FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF800401FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA901FC1FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0746 | PC: 0x0660b4..0x0660ec (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0660b4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0660b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0660bc: 910043FD  add      x29, sp, #0x10
//   0x0660c0: 90001828  adrp     x8, #0x36a000
//   0x0660c4: 9108E108  add      x8, x8, #0x238
//   0x0660c8: AA0003F3  mov      x19, x0
uint64_t fde_func_0746_0x0660b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000660B4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001828ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9108E108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940012F0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0751 | PC: 0x066198..0x0661d0 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x066198: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x06619c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0661a0: 910043FD  add      x29, sp, #0x10
//   0x0661a4: 90001828  adrp     x8, #0x36a000
//   0x0661a8: 910A2108  add      x8, x8, #0x288
//   0x0661ac: AA0003F3  mov      x19, x0
uint64_t fde_func_0751_0x066198(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00066198ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001828ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910A2108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400315FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0755 | PC: 0x06624c..0x06627c (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x06624c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x066250: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x066254: 910043FD  add      x29, sp, #0x10
//   0x066258: 90001828  adrp     x8, #0x36a000
//   0x06625c: 910B6108  add      x8, x8, #0x2d8
//   0x066260: AA0003F3  mov      x19, x0
uint64_t fde_func_0755_0x06624c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0006624CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001828ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910B6108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400E184ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0760 | PC: 0x066330..0x0663bc (140 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x066330: 90001828  adrp     x8, #0x36a000
//   0x066334: 910CA108  add      x8, x8, #0x328
//   0x066338: 6F00E400  movi     v0.2d, #0000000000000000
//   0x06633c: 52800029  mov      w9, #1
//   0x066340: AA0003EA  mov      x10, x0
//   0x066344: 3901401F  strb     wzr, [x0, #0x50]
uint64_t fde_func_0760_0x066330(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00066330ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001828ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910CA108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6F00E400ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800029ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003EAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3901401FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF807C01FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9097C1FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0764 | PC: 0x06649c..0x0664ac (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x06649c: F9400400  ldr      x0, [x0, #8]
//   0x0664a0: F9400008  ldr      x8, [x0]
//   0x0664a4: F9403D01  ldr      x1, [x8, #0x78]
//   0x0664a8: D61F0020  br       x1
uint64_t fde_func_0764_0x06649c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0006649CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9403D01ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0020ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0769 | PC: 0x0664ec..0x0664fc (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0664ec: F9400400  ldr      x0, [x0, #8]
//   0x0664f0: F8418C08  ldr      x8, [x0, #0x18]!
//   0x0664f4: F9400D01  ldr      x1, [x8, #0x18]
//   0x0664f8: D61F0020  br       x1
uint64_t fde_func_0769_0x0664ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000664ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8418C08ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400D01ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0020ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0773 | PC: 0x06652c..0x06653c (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x06652c: F9400400  ldr      x0, [x0, #8]
//   0x066530: F9400009  ldr      x9, [x0]
//   0x066534: F9406D22  ldr      x2, [x9, #0xd8]
//   0x066538: D61F0040  br       x2
uint64_t fde_func_0773_0x06652c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0006652CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400009ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9406D22ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0040ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0778 | PC: 0x066578..0x066584 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x066578: F9400400  ldr      x0, [x0, #8]
//   0x06657c: 12000042  and      w2, w2, #1
//   0x066580: 17FFB565  b        #0x53b14
uint64_t fde_func_0778_0x066578(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00066578ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12000042ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFB565ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0782 | PC: 0x06660c..0x06661c (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x06660c: F9400400  ldr      x0, [x0, #8]
//   0x066610: F8418C08  ldr      x8, [x0, #0x18]!
//   0x066614: F9401101  ldr      x1, [x8, #0x20]
//   0x066618: D61F0020  br       x1
uint64_t fde_func_0782_0x06660c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0006660CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8418C08ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401101ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0020ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0787 | PC: 0x06665c..0x06666c (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x06665c: F9400400  ldr      x0, [x0, #8]
//   0x066660: F8410C08  ldr      x8, [x0, #0x10]!
//   0x066664: F9401104  ldr      x4, [x8, #0x20]
//   0x066668: D61F0080  br       x4
uint64_t fde_func_0787_0x06665c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0006665CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8410C08ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401104ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0080ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0791 | PC: 0x066718..0x066818 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x066718: D101C3FF  sub      sp, sp, #0x70
//   0x06671c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x066720: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x066724: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x066728: 910183FD  add      x29, sp, #0x60
//   0x06672c: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_0791_0x066718(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00066718ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C9ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0796 | PC: 0x0669dc..0x0669f4 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0669dc: F9400400  ldr      x0, [x0, #8]
//   0x0669e0: 528F2341  mov      w1, #0x791a
//   0x0669e4: 2A1F03E2  mov      w2, wzr
//   0x0669e8: F9400009  ldr      x9, [x0]
//   0x0669ec: F9408D23  ldr      x3, [x9, #0x118]
//   0x0669f0: D61F0060  br       x3
uint64_t fde_func_0796_0x0669dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000669DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x528F2341ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E2ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400009ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9408D23ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0060ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0800 | PC: 0x066c2c..0x066c44 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x066c2c: F9400400  ldr      x0, [x0, #8]
//   0x066c30: 528F2361  mov      w1, #0x791b
//   0x066c34: 2A1F03E2  mov      w2, wzr
//   0x066c38: F9400009  ldr      x9, [x0]
//   0x066c3c: F9408D23  ldr      x3, [x9, #0x118]
//   0x066c40: D61F0060  br       x3
uint64_t fde_func_0800_0x066c2c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00066C2CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x528F2361ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E2ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400009ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9408D23ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0060ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0804 | PC: 0x066e58..0x066e9c (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x066e58: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x066e5c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x066e60: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x066e64: 910083FD  add      x29, sp, #0x20
//   0x066e68: 91017015  add      x21, x0, #0x5c
//   0x066e6c: AA0003F3  mov      x19, x0
uint64_t fde_func_0804_0x066e58(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00066E58ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91017015ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1503E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0809 | PC: 0x0673a4..0x0674a4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0673a4: D10303FF  sub      sp, sp, #0xc0
//   0x0673a8: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x0673ac: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x0673b0: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x0673b4: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x0673b8: A90A4FF4  stp      x20, x19, [sp, #0xa0]
uint64_t fde_func_0809_0x0673a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000673A4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10303FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9066FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90767FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9085FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90957F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B7BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102C3FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0813 | PC: 0x067cd4..0x067dd4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x067cd4: D10203FF  sub      sp, sp, #0x80
//   0x067cd8: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x067cdc: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x067ce0: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x067ce4: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x067ce8: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_0813_0x067cd4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00067CD4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9026FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90367FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9077BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C3FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0818 | PC: 0x0682a8..0x06831c (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0682a8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0682ac: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0682b0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0682b4: 910083FD  add      x29, sp, #0x20
//   0x0682b8: 91046013  add      x19, x0, #0x118
//   0x0682bc: AA0003F5  mov      x21, x0
uint64_t fde_func_0818_0x0682a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000682A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91046013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0822 | PC: 0x068358..0x068458 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x068358: D10283FF  sub      sp, sp, #0xa0
//   0x06835c: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x068360: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x068364: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x068368: 910243FD  add      x29, sp, #0x90
//   0x06836c: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_0822_0x068358(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00068358ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90757F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9084FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9097BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910243FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D83A8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0827 | PC: 0x06878c..0x068818 (140 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x06878c: D10143FF  sub      sp, sp, #0x50
//   0x068790: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x068794: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x068798: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x06879c: 910103FD  add      x29, sp, #0x40
//   0x0687a0: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_0827_0x06878c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0006878CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C9ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0831 | PC: 0x068880..0x068888 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x068880: B9405800  ldr      w0, [x0, #0x58]
//   0x068884: D65F03C0  ret      
uint64_t fde_func_0831_0x068880(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00068880ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9405800ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0836 | PC: 0x069374..0x0693c8 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x069374: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x069378: 910003FD  mov      x29, sp
//   0x06937c: F00018A8  adrp     x8, #0x380000
//   0x069380: 9120E108  add      x8, x8, #0x838
//   0x069384: 08DFFD08  ldarb    w8, [x8]
//   0x069388: 360000A8  tbz      w8, #0, #0x6939c
uint64_t fde_func_0836_0x069374(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00069374ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00018A8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9120E108ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x08DFFD08ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x360000A8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00018A0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91208000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0840 | PC: 0x069cc0..0x069d30 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x069cc0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x069cc4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x069cc8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x069ccc: 910083FD  add      x29, sp, #0x20
//   0x069cd0: F9400808  ldr      x8, [x0, #0x10]
//   0x069cd4: B4000268  cbz      x8, #0x69d20
uint64_t fde_func_0840_0x069cc0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00069CC0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400808ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000268ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9405008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0845 | PC: 0x06a070..0x06a0c4 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x06a070: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x06a074: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06a078: 910043FD  add      x29, sp, #0x10
//   0x06a07c: A9007C7F  stp      xzr, xzr, [x3]
//   0x06a080: F9000861  str      x1, [x3, #0x10]
//   0x06a084: F9000043  str      x3, [x2]
uint64_t fde_func_0845_0x06a070(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0006A070ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007C7FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000861ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000043ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0849 | PC: 0x06a264..0x06a310 (172 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x06a264: D10183FF  sub      sp, sp, #0x60
//   0x06a268: F90013F7  str      x23, [sp, #0x20]
//   0x06a26c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x06a270: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x06a274: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x06a278: 910143FD  add      x29, sp, #0x50
uint64_t fde_func_0849_0x06a264(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0006A264ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0854 | PC: 0x06a794..0x06a800 (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x06a794: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x06a798: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06a79c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06a7a0: 910083FD  add      x29, sp, #0x20
//   0x06a7a4: F9400015  ldr      x21, [x0]
//   0x06a7a8: B4000195  cbz      x21, #0x6a7d8
uint64_t fde_func_0854_0x06a794(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0006A794ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400015ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000195ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400414ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0858 | PC: 0x06a950..0x06a9a4 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x06a950: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x06a954: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06a958: 910043FD  add      x29, sp, #0x10
//   0x06a95c: 90001808  adrp     x8, #0x36a000
//   0x06a960: 9116A108  add      x8, x8, #0x5a8
//   0x06a964: F9000008  str      x8, [x0]
uint64_t fde_func_0858_0x06a950(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0006A950ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001808ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9116A108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB00018A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39408009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0863 | PC: 0x06aa10..0x06aa58 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x06aa10: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06aa14: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06aa18: 910043FD  add      x29, sp, #0x10
//   0x06aa1c: AA0003F3  mov      x19, x0
//   0x06aa20: 52800500  mov      w0, #0x28
//   0x06aa24: 97FF65AB  bl       #0x440d0
uint64_t fde_func_0863_0x06aa10(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0006AA10ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800500ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FF65ABULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001808ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9117E108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0867 | PC: 0x06aac4..0x06ab48 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x06aac4: D10143FF  sub      sp, sp, #0x50
//   0x06aac8: F90013F5  str      x21, [sp, #0x20]
//   0x06aacc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x06aad0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x06aad4: 910103FD  add      x29, sp, #0x40
//   0x06aad8: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_0867_0x06aac4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0006AAC4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000FE8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0872 | PC: 0x06ad18..0x06ad3c (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x06ad18: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x06ad1c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06ad20: 910043FD  add      x29, sp, #0x10
//   0x06ad24: AA0003F3  mov      x19, x0
//   0x06ad28: 97FFFFDA  bl       #0x6ac90
//   0x06ad2c: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_0872_0x06ad18(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0006AD18ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFDAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0876 | PC: 0x06b868..0x06b968 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x06b868: D101C3FF  sub      sp, sp, #0x70
//   0x06b86c: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x06b870: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x06b874: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x06b878: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x06b87c: A9067BFD  stp      x29, x30, [sp, #0x60]
uint64_t fde_func_0876_0x06b868(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0006B868ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90267FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0880 | PC: 0x06d594..0x06d694 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x06d594: D10783FF  sub      sp, sp, #0x1e0
//   0x06d598: A9186FFC  stp      x28, x27, [sp, #0x180]
//   0x06d59c: A91967FA  stp      x26, x25, [sp, #0x190]
//   0x06d5a0: A91A5FF8  stp      x24, x23, [sp, #0x1a0]
//   0x06d5a4: A91B57F6  stp      x22, x21, [sp, #0x1b0]
//   0x06d5a8: A91C4FF4  stp      x20, x19, [sp, #0x1c0]
uint64_t fde_func_0880_0x06d594(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0006D594ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10783FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9186FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91967FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91A5FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91B57F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91C4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91D7BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910743FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0885 | PC: 0x06f8f4..0x06f8fc (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x06f8f4: 52803E80  mov      w0, #0x1f4
//   0x06f8f8: D65F03C0  ret      
uint64_t fde_func_0885_0x06f8f4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0006F8F4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x52803E80ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0889 | PC: 0x06fac4..0x06fb34 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x06fac4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06fac8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06facc: 910043FD  add      x29, sp, #0x10
//   0x06fad0: AA0003F3  mov      x19, x0
//   0x06fad4: 52800400  mov      w0, #0x20
//   0x06fad8: AA0103F4  mov      x20, x1
uint64_t fde_func_0889_0x06fac4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0006FAC4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800400ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FF517DULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900001FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0894 | PC: 0x06fc28..0x06fc5c (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x06fc28: A940242A  ldp      x10, x9, [x1]
//   0x06fc2c: B40000C9  cbz      x9, #0x6fc44
//   0x06fc30: 91004128  add      x8, x9, #0x10
//   0x06fc34: C85F7D0B  ldxr     x11, [x8]
//   0x06fc38: 9100056B  add      x11, x11, #1
//   0x06fc3c: C80C7D0B  stxr     w12, x11, [x8]
uint64_t fde_func_0894_0x06fc28(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0006FC28ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940242AULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004128ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC85F7D0BULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100056BULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC80C7D0BULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x35FFFFACULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402C08ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0898 | PC: 0x06fc70..0x06fcdc (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x06fc70: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x06fc74: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06fc78: 910043FD  add      x29, sp, #0x10
//   0x06fc7c: AA0003F3  mov      x19, x0
//   0x06fc80: F9402C00  ldr      x0, [x0, #0x58]
//   0x06fc84: F00017C8  adrp     x8, #0x36a000
uint64_t fde_func_0898_0x06fc70(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0006FC70ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402C00ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00017C8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911CE108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000268ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0903 | PC: 0x06fdb4..0x06fdf8 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x06fdb4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x06fdb8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06fdbc: 910043FD  add      x29, sp, #0x10
//   0x06fdc0: F9400C40  ldr      x0, [x2, #0x18]
//   0x06fdc4: AA0203F3  mov      x19, x2
//   0x06fdc8: B4000060  cbz      x0, #0x6fdd4
uint64_t fde_func_0903_0x06fdb4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0006FDB4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C40ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000060ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001260ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FF5158ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0907 | PC: 0x06fefc..0x06ff78 (124 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x06fefc: A9402808  ldp      x8, x10, [x0]
//   0x06ff00: EB08015F  cmp      x10, x8
//   0x06ff04: 540001E0  b.eq     #0x6ff40
//   0x06ff08: F9400429  ldr      x9, [x1, #8]
//   0x06ff0c: D100514B  sub      x11, x10, #0x14
//   0x06ff10: EB09015F  cmp      x10, x9
uint64_t fde_func_0907_0x06fefc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0006FEFCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402808ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB08015FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540001E0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400429ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100514BULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09015FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB81FC13FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000060ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0912 | PC: 0x0701e8..0x0702d8 (240 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0701e8: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x0701ec: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0701f0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0701f4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0701f8: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0701fc: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_0912_0x0701e8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000701E8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81A0FFBULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400416ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0916 | PC: 0x070470..0x0704f4 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x070470: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x070474: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x070478: 910043FD  add      x29, sp, #0x10
//   0x07047c: F9400428  ldr      x8, [x1, #8]
//   0x070480: B40000A8  cbz      x8, #0x70494
//   0x070484: AA0803F3  mov      x19, x8
uint64_t fde_func_0916_0x070470(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00070470ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000A8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB5FFFFC8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0921 | PC: 0x070808..0x07085c (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x070808: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07080c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x070810: 910043FD  add      x29, sp, #0x10
//   0x070814: A9007C7F  stp      xzr, xzr, [x3]
//   0x070818: F9000861  str      x1, [x3, #0x10]
//   0x07081c: F9000043  str      x3, [x2]
uint64_t fde_func_0921_0x070808(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00070808ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007C7FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000861ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000043ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0925 | PC: 0x070b7c..0x070c7c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x070b7c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x070b80: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x070b84: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x070b88: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x070b8c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x070b90: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_0925_0x070b7c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00070B7CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BA6FFCULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0930 | PC: 0x070f2c..0x07101c (240 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x070f2c: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x070f30: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x070f34: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x070f38: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x070f3c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x070f40: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_0930_0x070f2c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00070F2CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81A0FFBULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400416ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0934 | PC: 0x0711fc..0x0712f8 (252 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0711fc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x071200: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x071204: 910043FD  add      x29, sp, #0x10
//   0x071208: AA0003E8  mov      x8, x0
//   0x07120c: 384B0D09  ldrb     w9, [x8, #0xb0]!
//   0x071210: 37000089  tbnz     w9, #0, #0x71220
uint64_t fde_func_0934_0x0711fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000711FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x384B0D09ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000089ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD341FD2AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB500008AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0939 | PC: 0x071744..0x0717c0 (124 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x071744: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x071748: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07174c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x071750: 910083FD  add      x29, sp, #0x20
//   0x071754: 91002016  add      x22, x0, #8
//   0x071758: 52800900  mov      w0, #0x48
uint64_t fde_func_0939_0x071744(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00071744ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002016ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800900ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0943 | PC: 0x071918..0x071920 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x071918: 91006000  add      x0, x0, #0x18
//   0x07191c: 1400003A  b        #0x71a04
uint64_t fde_func_0943_0x071918(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00071918ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1400003AULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0948 | PC: 0x071ac4..0x071b1c (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x071ac4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x071ac8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x071acc: 910043FD  add      x29, sp, #0x10
//   0x071ad0: F9400413  ldr      x19, [x0, #8]
//   0x071ad4: B40000F3  cbz      x19, #0x71af0
//   0x071ad8: 91002268  add      x8, x19, #8
uint64_t fde_func_0948_0x071ac4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00071AC4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400413ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002268ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC85FFD09ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100052AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0952 | PC: 0x071b90..0x071b94 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x071b90: 17FF49E8  b        #0x44330
uint64_t fde_func_0952_0x071b90(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00071B90ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FF49E8ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0957 | PC: 0x071e48..0x071f1c (212 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x071e48: D10143FF  sub      sp, sp, #0x50
//   0x071e4c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x071e50: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x071e54: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x071e58: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x071e5c: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_0957_0x071e48(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00071E48ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401708ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0961 | PC: 0x072730..0x072830 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x072730: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x072734: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x072738: 910043FD  add      x29, sp, #0x10
//   0x07273c: AA0003F3  mov      x19, x0
//   0x072740: F9450000  ldr      x0, [x0, #0xa00]
//   0x072744: 900017C8  adrp     x8, #0x36a000
uint64_t fde_func_0961_0x072730(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00072730ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9450000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900017C8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91228108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000268ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0965 | PC: 0x0729f0..0x072af0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0729f0: FC190FE8  str      d8, [sp, #-0x70]!
//   0x0729f4: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x0729f8: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0729fc: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x072a00: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x072a04: A9054FF4  stp      x20, x19, [sp, #0x50]
uint64_t fde_func_0965_0x0729f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000729F0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xFC190FE8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9016FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90267FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0970 | PC: 0x079098..0x079144 (172 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x079098: D10183FF  sub      sp, sp, #0x60
//   0x07909c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0790a0: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0790a4: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x0790a8: 910143FD  add      x29, sp, #0x50
//   0x0790ac: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_0970_0x079098(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00079098ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0974 | PC: 0x07b814..0x07b914 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x07b814: D105C3FF  sub      sp, sp, #0x170
//   0x07b818: FD0083E8  str      d8, [sp, #0x100]
//   0x07b81c: A9116FFC  stp      x28, x27, [sp, #0x110]
//   0x07b820: A91267FA  stp      x26, x25, [sp, #0x120]
//   0x07b824: A9135FF8  stp      x24, x23, [sp, #0x130]
//   0x07b828: A91457F6  stp      x22, x21, [sp, #0x140]
uint64_t fde_func_0974_0x07b814(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0007B814ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD105C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD0083E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9116FFCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91267FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9135FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91457F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9154FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9167BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0979 | PC: 0x07e068..0x07e168 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x07e068: D10683FF  sub      sp, sp, #0x1a0
//   0x07e06c: 6D1323E9  stp      d9, d8, [sp, #0x130]
//   0x07e070: A9146FFC  stp      x28, x27, [sp, #0x140]
//   0x07e074: A91567FA  stp      x26, x25, [sp, #0x150]
//   0x07e078: A9165FF8  stp      x24, x23, [sp, #0x160]
//   0x07e07c: A91757F6  stp      x22, x21, [sp, #0x170]
uint64_t fde_func_0979_0x07e068(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0007E068ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10683FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D1323E9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9146FFCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91567FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9165FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91757F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9184FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9197BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0983 | PC: 0x082778..0x082878 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x082778: D103C3FF  sub      sp, sp, #0xf0
//   0x08277c: FD0043E8  str      d8, [sp, #0x80]
//   0x082780: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x082784: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x082788: A90B5FF8  stp      x24, x23, [sp, #0xb0]
//   0x08278c: A90C57F6  stp      x22, x21, [sp, #0xc0]
uint64_t fde_func_0983_0x082778(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00082778ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD103C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD0043E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9096FFCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A67FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B5FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C57F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D4FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E7BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0988 | PC: 0x08356c..0x08366c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x08356c: D10283FF  sub      sp, sp, #0xa0
//   0x083570: F9002BF9  str      x25, [sp, #0x50]
//   0x083574: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x083578: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x08357c: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x083580: A9097BFD  stp      x29, x30, [sp, #0x90]
uint64_t fde_func_0988_0x08356c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0008356CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9002BF9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9065FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90757F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9084FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9097BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910243FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0992 | PC: 0x083c34..0x083c4c (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x083c34: B9427408  ldr      w8, [x0, #0x274]
//   0x083c38: 52804009  mov      w9, #0x200
//   0x083c3c: 7100011F  cmp      w8, #0
//   0x083c40: 52802BE8  mov      w8, #0x15f
//   0x083c44: 1A890100  csel     w0, w8, w9, eq
//   0x083c48: D65F03C0  ret      
uint64_t fde_func_0992_0x083c34(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00083C34ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9427408ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52804009ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100011FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52802BE8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1A890100ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #0997 | PC: 0x085470..0x085570 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x085470: D10383FF  sub      sp, sp, #0xe0
//   0x085474: 6D043BEF  stp      d15, d14, [sp, #0x40]
//   0x085478: 6D0533ED  stp      d13, d12, [sp, #0x50]
//   0x08547c: 6D062BEB  stp      d11, d10, [sp, #0x60]
//   0x085480: 6D0723E9  stp      d9, d8, [sp, #0x70]
//   0x085484: A9086FFC  stp      x28, x27, [sp, #0x80]
uint64_t fde_func_0997_0x085470(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00085470ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10383FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D043BEFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D0533EDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D062BEBULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D0723E9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9086FFCULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90967FAULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A5FF8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1001 | PC: 0x087564..0x087664 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x087564: D10243FF  sub      sp, sp, #0x90
//   0x087568: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x08756c: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x087570: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x087574: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x087578: A9074FF4  stp      x20, x19, [sp, #0x70]
uint64_t fde_func_1001_0x087564(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00087564ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9036FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90467FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9055FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1006 | PC: 0x088f7c..0x08907c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x088f7c: D10543FF  sub      sp, sp, #0x150
//   0x088f80: FD0073E8  str      d8, [sp, #0xe0]
//   0x088f84: A90F6FFC  stp      x28, x27, [sp, #0xf0]
//   0x088f88: A91067FA  stp      x26, x25, [sp, #0x100]
//   0x088f8c: A9115FF8  stp      x24, x23, [sp, #0x110]
//   0x088f90: A91257F6  stp      x22, x21, [sp, #0x120]
uint64_t fde_func_1006_0x088f7c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00088F7CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10543FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD0073E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90F6FFCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91067FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9115FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91257F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9134FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9147BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1010 | PC: 0x08ac04..0x08ad04 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x08ac04: D10403FF  sub      sp, sp, #0x100
//   0x08ac08: 6D0923E9  stp      d9, d8, [sp, #0x90]
//   0x08ac0c: F90053FB  str      x27, [sp, #0xa0]
//   0x08ac10: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x08ac14: A90C5FF8  stp      x24, x23, [sp, #0xc0]
//   0x08ac18: A90D57F6  stp      x22, x21, [sp, #0xd0]
uint64_t fde_func_1010_0x08ac04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0008AC04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10403FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D0923E9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90053FBULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B67FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C5FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D57F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E4FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90F7BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1015 | PC: 0x091624..0x091724 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x091624: D10383FF  sub      sp, sp, #0xe0
//   0x091628: F90043FB  str      x27, [sp, #0x80]
//   0x09162c: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x091630: A90A5FF8  stp      x24, x23, [sp, #0xa0]
//   0x091634: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x091638: A90C4FF4  stp      x20, x19, [sp, #0xc0]
uint64_t fde_func_1015_0x091624(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00091624ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10383FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90043FBULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90967FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A5FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B57F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D7BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910343FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1019 | PC: 0x092b78..0x092bcc (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x092b78: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x092b7c: 910003FD  mov      x29, sp
//   0x092b80: F9400408  ldr      x8, [x0, #8]
//   0x092b84: B4000228  cbz      x8, #0x92bc8
//   0x092b88: B9400029  ldr      w9, [x1]
//   0x092b8c: B940210A  ldr      w10, [x8, #0x20]
uint64_t fde_func_1019_0x092b78(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00092B78ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000228ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9400029ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB940210AULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6B0A013FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5400008AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1024 | PC: 0x093c28..0x093d28 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x093c28: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x093c2c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x093c30: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x093c34: 910083FD  add      x29, sp, #0x20
//   0x093c38: BD436400  ldr      s0, [x0, #0x364]
//   0x093c3c: AA0003F3  mov      x19, x0
uint64_t fde_func_1024_0x093c28(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00093C28ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xBD436400ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1E202008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000309ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1028 | PC: 0x094604..0x094704 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x094604: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x094608: F90007F3  str      x19, [sp, #8]
//   0x09460c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x094610: 910043FD  add      x29, sp, #0x10
//   0x094614: B9445C08  ldr      w8, [x0, #0x45c]
//   0x094618: 7100051F  cmp      w8, #1
uint64_t fde_func_1028_0x094604(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00094604ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xFC1E0FE8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90007F3ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9445C08ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100051FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5400032BULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540003C1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1033 | PC: 0x094ae0..0x094be0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x094ae0: D101C3FF  sub      sp, sp, #0x70
//   0x094ae4: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x094ae8: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x094aec: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x094af0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x094af4: A9054FF4  stp      x20, x19, [sp, #0x50]
uint64_t fde_func_1033_0x094ae0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00094AE0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9016FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90267FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1037 | PC: 0x0950d0..0x0950d4 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0950d0: 17FEBC98  b        #0x44330
uint64_t fde_func_1037_0x0950d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000950D0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FEBC98ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1041 | PC: 0x095480..0x095564 (228 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x095480: D10183FF  sub      sp, sp, #0x60
//   0x095484: F9000BF9  str      x25, [sp, #0x10]
//   0x095488: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x09548c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x095490: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x095494: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_1041_0x095480(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00095480ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD059ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1046 | PC: 0x095760..0x095860 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x095760: D106C3FF  sub      sp, sp, #0x1b0
//   0x095764: A9156FFC  stp      x28, x27, [sp, #0x150]
//   0x095768: A91667FA  stp      x26, x25, [sp, #0x160]
//   0x09576c: A9175FF8  stp      x24, x23, [sp, #0x170]
//   0x095770: A91857F6  stp      x22, x21, [sp, #0x180]
//   0x095774: A9194FF4  stp      x20, x19, [sp, #0x190]
uint64_t fde_func_1046_0x095760(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00095760ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD106C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9156FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91667FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9175FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91857F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9194FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91A7BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910683FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1050 | PC: 0x095cf8..0x095df8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x095cf8: D10203FF  sub      sp, sp, #0x80
//   0x095cfc: F90013FB  str      x27, [sp, #0x20]
//   0x095d00: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x095d04: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x095d08: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x095d0c: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_1050_0x095cf8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00095CF8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013FBULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90367FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9077BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C3FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1055 | PC: 0x096410..0x096510 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x096410: D10103FF  sub      sp, sp, #0x40
//   0x096414: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x096418: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x09641c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x096420: 9100C3FD  add      x29, sp, #0x30
//   0x096424: AA0103F4  mov      x20, x1
uint64_t fde_func_1055_0x096410(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00096410ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90007FFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1059 | PC: 0x096630..0x096670 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x096630: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x096634: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x096638: 910043FD  add      x29, sp, #0x10
//   0x09663c: CB010053  sub      x19, x2, x1
//   0x096640: F100067F  cmp      x19, #1
//   0x096644: 5400010B  b.lt     #0x96664
uint64_t fde_func_1059_0x096630(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00096630ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB010053ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100067FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5400010BULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400060ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E2ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1064 | PC: 0x09678c..0x09688c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x09678c: D101C3FF  sub      sp, sp, #0x70
//   0x096790: F9001BF7  str      x23, [sp, #0x30]
//   0x096794: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x096798: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x09679c: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x0967a0: 910183FD  add      x29, sp, #0x60
uint64_t fde_func_1064_0x09678c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0009678CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1068 | PC: 0x096a38..0x096aac (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x096a38: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x096a3c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x096a40: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x096a44: 910083FD  add      x29, sp, #0x20
//   0x096a48: AA0203F5  mov      x21, x2
//   0x096a4c: AA0103F4  mov      x20, x1
uint64_t fde_func_1068_0x096a38(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00096A38ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F5ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9018C1FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1073 | PC: 0x096db8..0x096e78 (192 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x096db8: D10143FF  sub      sp, sp, #0x50
//   0x096dbc: F9000BF7  str      x23, [sp, #0x10]
//   0x096dc0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x096dc4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x096dc8: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x096dcc: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_1073_0x096db8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00096DB8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1077 | PC: 0x096f3c..0x096f40 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x096f3c: 17FEB4FD  b        #0x44330
uint64_t fde_func_1077_0x096f3c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00096F3CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FEB4FDULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1082 | PC: 0x0970a0..0x0970f0 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0970a0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0970a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0970a8: 910043FD  add      x29, sp, #0x10
//   0x0970ac: 3941C008  ldrb     w8, [x0, #0x70]
//   0x0970b0: F0001689  adrp     x9, #0x36a000
//   0x0970b4: AA0003F3  mov      x19, x0
uint64_t fde_func_1082_0x0970a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000970A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3941C008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001689ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912A8129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1086 | PC: 0x097298..0x0972fc (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x097298: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09729c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0972a0: 910043FD  add      x29, sp, #0x10
//   0x0972a4: AA0103F3  mov      x19, x1
//   0x0972a8: AA0003F4  mov      x20, x0
//   0x0972ac: A8C10801  ldp      x1, x2, [x0], #0x10
uint64_t fde_func_1086_0x097298(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00097298ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA8C10801ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002263ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000012ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1091 | PC: 0x097518..0x0975dc (196 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x097518: D10143FF  sub      sp, sp, #0x50
//   0x09751c: F9000BF7  str      x23, [sp, #0x10]
//   0x097520: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x097524: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x097528: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x09752c: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_1091_0x097518(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00097518ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1095 | PC: 0x097798..0x097898 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x097798: D101C3FF  sub      sp, sp, #0x70
//   0x09779c: F9001BF7  str      x23, [sp, #0x30]
//   0x0977a0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0977a4: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0977a8: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x0977ac: 910183FD  add      x29, sp, #0x60
uint64_t fde_func_1095_0x097798(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00097798ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1100 | PC: 0x097af0..0x097b44 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x097af0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x097af4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x097af8: 910043FD  add      x29, sp, #0x10
//   0x097afc: A9007C7F  stp      xzr, xzr, [x3]
//   0x097b00: F9000861  str      x1, [x3, #0x10]
//   0x097b04: F9000043  str      x3, [x2]
uint64_t fde_func_1100_0x097af0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00097AF0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007C7FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000861ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000043ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1104 | PC: 0x097d6c..0x097d90 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x097d6c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x097d70: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x097d74: 910043FD  add      x29, sp, #0x10
//   0x097d78: AA0003F3  mov      x19, x0
//   0x097d7c: 97FEB491  bl       #0x44fc0
//   0x097d80: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_1104_0x097d6c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00097D6CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FEB491ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1109 | PC: 0x097e1c..0x097ea0 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x097e1c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x097e20: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x097e24: 910043FD  add      x29, sp, #0x10
//   0x097e28: F9400428  ldr      x8, [x1, #8]
//   0x097e2c: B40000A8  cbz      x8, #0x97e40
//   0x097e30: AA0803F3  mov      x19, x8
uint64_t fde_func_1109_0x097e1c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00097E1CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000A8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB5FFFFC8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1113 | PC: 0x0980a8..0x0980d8 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0980a8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0980ac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0980b0: 910043FD  add      x29, sp, #0x10
//   0x0980b4: D0001688  adrp     x8, #0x36a000
//   0x0980b8: 912DA108  add      x8, x8, #0xb68
//   0x0980bc: AA0003F3  mov      x19, x0
uint64_t fde_func_1113_0x0980a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000980A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0001688ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912DA108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000017ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1118 | PC: 0x0981dc..0x098200 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0981dc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0981e0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0981e4: 910043FD  add      x29, sp, #0x10
//   0x0981e8: AA0003F3  mov      x19, x0
//   0x0981ec: 97FFFFCD  bl       #0x98120
//   0x0981f0: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_1118_0x0981dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000981DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFCDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1122 | PC: 0x09c634..0x09c734 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x09c634: D101C3FF  sub      sp, sp, #0x70
//   0x09c638: F9001BF7  str      x23, [sp, #0x30]
//   0x09c63c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x09c640: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x09c644: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x09c648: 910183FD  add      x29, sp, #0x60
uint64_t fde_func_1122_0x09c634(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0009C634ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1126 | PC: 0x09c8d8..0x09c95c (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x09c8d8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09c8dc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09c8e0: 910043FD  add      x29, sp, #0x10
//   0x09c8e4: F9400428  ldr      x8, [x1, #8]
//   0x09c8e8: B40000A8  cbz      x8, #0x9c8fc
//   0x09c8ec: AA0803F3  mov      x19, x8
uint64_t fde_func_1126_0x09c8d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0009C8D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000A8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB5FFFFC8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1131 | PC: 0x09ce24..0x09cea0 (124 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x09ce24: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x09ce28: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09ce2c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09ce30: 910083FD  add      x29, sp, #0x20
//   0x09ce34: 91002016  add      x22, x0, #8
//   0x09ce38: 52800900  mov      w0, #0x48
uint64_t fde_func_1131_0x09ce24(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0009CE24ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002016ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800900ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1135 | PC: 0x09d170..0x09d1c4 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x09d170: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09d174: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09d178: 910043FD  add      x29, sp, #0x10
//   0x09d17c: A9007C7F  stp      xzr, xzr, [x3]
//   0x09d180: F9000861  str      x1, [x3, #0x10]
//   0x09d184: F9000043  str      x3, [x2]
uint64_t fde_func_1135_0x09d170(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0009D170ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007C7FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000861ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000043ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1140 | PC: 0x09d540..0x09d59c (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x09d540: AA0003E8  mov      x8, x0
//   0x09d544: F9400800  ldr      x0, [x0, #0x10]
//   0x09d548: B4000280  cbz      x0, #0x9d598
//   0x09d54c: F9400009  ldr      x9, [x0]
//   0x09d550: EB08013F  cmp      x9, x8
//   0x09d554: 54000120  b.eq     #0x9d578
uint64_t fde_func_1140_0x09d540(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0009D540ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400800ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000280ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400009ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB08013FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000120ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900041FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40001E9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1144 | PC: 0x09d7b0..0x09d898 (232 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x09d7b0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09d7b4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09d7b8: 910043FD  add      x29, sp, #0x10
//   0x09d7bc: F9400048  ldr      x8, [x2]
//   0x09d7c0: A9404D08  ldp      x8, x19, [x8]
//   0x09d7c4: B40000D3  cbz      x19, #0x9d7dc
uint64_t fde_func_1144_0x09d7b0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0009D7B0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400048ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9404D08ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000D3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002269ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC85F7D2AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1149 | PC: 0x09db34..0x09dc34 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x09db34: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x09db38: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x09db3c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x09db40: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x09db44: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x09db48: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_1149_0x09db34(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0009DB34ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BA6FFCULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1153 | PC: 0x09dec0..0x09df10 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x09dec0: CB010042  sub      x2, x2, x1
//   0x09dec4: F100045F  cmp      x2, #1
//   0x09dec8: 5400022B  b.lt     #0x9df0c
//   0x09decc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09ded0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09ded4: 910043FD  add      x29, sp, #0x10
uint64_t fde_func_1153_0x09dec0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0009DEC0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB010042ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100045FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5400022BULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400060ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB202E7E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1158 | PC: 0x09e12c..0x09e21c (240 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x09e12c: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x09e130: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x09e134: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x09e138: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x09e13c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x09e140: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_1158_0x09e12c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0009E12CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81A0FFBULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400416ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1162 | PC: 0x09e4f8..0x09e550 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x09e4f8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09e4fc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09e500: 910043FD  add      x29, sp, #0x10
//   0x09e504: AA0003F3  mov      x19, x0
//   0x09e508: F9400000  ldr      x0, [x0]
//   0x09e50c: F9400A61  ldr      x1, [x19, #0x10]
uint64_t fde_func_1162_0x09e4f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0009E4F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400A61ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFE024ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400661ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1167 | PC: 0x09e748..0x09e758 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x09e748: F9400C00  ldr      x0, [x0, #0x18]
//   0x09e74c: B4000040  cbz      x0, #0x9e754
//   0x09e750: 17FE96F8  b        #0x44330
//   0x09e754: D65F03C0  ret      
uint64_t fde_func_1167_0x09e748(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0009E748ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C00ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000040ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FE96F8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1171 | PC: 0x09e81c..0x09e878 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x09e81c: 90001668  adrp     x8, #0x36a000
//   0x09e820: 911CE108  add      x8, x8, #0x738
//   0x09e824: F9000008  str      x8, [x0]
//   0x09e828: 3DC00020  ldr      q0, [x1]
//   0x09e82c: F9400828  ldr      x8, [x1, #0x10]
//   0x09e830: 528CAC89  mov      w9, #0x6564
uint64_t fde_func_1171_0x09e81c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0009E81CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001668ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911CE108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3DC00020ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400828ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x528CAC89ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x72AC2CC9ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3C808000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1176 | PC: 0x09eb24..0x09eb80 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x09eb24: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x09eb28: 910003FD  mov      x29, sp
//   0x09eb2c: 39400028  ldrb     w8, [x1]
//   0x09eb30: F9400429  ldr      x9, [x1, #8]
//   0x09eb34: D341FD0A  lsr      x10, x8, #1
//   0x09eb38: 7200011F  tst      w8, #1
uint64_t fde_func_1176_0x09eb24(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0009EB24ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400028ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400429ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD341FD0AULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7200011FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A890148ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB50001C8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1180 | PC: 0x09f084..0x09f184 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x09f084: D10343FF  sub      sp, sp, #0xd0
//   0x09f088: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x09f08c: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x09f090: A9095FF8  stp      x24, x23, [sp, #0x90]
//   0x09f094: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x09f098: A90B4FF4  stp      x20, x19, [sp, #0xb0]
uint64_t fde_func_1180_0x09f084(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0009F084ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10343FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9076FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90867FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9095FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A57F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C7BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910303FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1185 | PC: 0x09f944..0x09f950 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x09f944: 91016008  add      x8, x0, #0x58
//   0x09f948: 889FFD01  stlr     w1, [x8]
//   0x09f94c: D65F03C0  ret      
uint64_t fde_func_1185_0x09f944(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0009F944ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91016008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x889FFD01ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1189 | PC: 0x0a0568..0x0a05d4 (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0a0568: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0a056c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a0570: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a0574: 910083FD  add      x29, sp, #0x20
//   0x0a0578: AA0003F4  mov      x20, x0
//   0x0a057c: 52800700  mov      w0, #0x38
uint64_t fde_func_1189_0x0a0568(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000A0568ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800700ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FE8ED3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1194 | PC: 0x0a08ec..0x0a091c (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0a08ec: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a08f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a08f4: 910043FD  add      x29, sp, #0x10
//   0x0a08f8: D0001648  adrp     x8, #0x36a000
//   0x0a08fc: 9133E108  add      x8, x8, #0xcf8
//   0x0a0900: AA0003F3  mov      x19, x0
uint64_t fde_func_1194_0x0a08ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000A08ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0001648ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9133E108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000016ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1198 | PC: 0x0a0960..0x0a0994 (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0a0960: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a0964: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a0968: 910043FD  add      x29, sp, #0x10
//   0x0a096c: F9401C01  ldr      x1, [x0, #0x38]
//   0x0a0970: AA0003F3  mov      x19, x0
//   0x0a0974: 9100C000  add      x0, x0, #0x30
uint64_t fde_func_1198_0x0a0960(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000A0960ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401C01ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000007ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006260ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1202 | PC: 0x0a0a90..0x0a0b90 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0a0a90: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0a0a94: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0a0a98: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a0a9c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0a0aa0: 9100C3FD  add      x29, sp, #0x30
//   0x0a0aa4: AA0003F3  mov      x19, x0
uint64_t fde_func_1202_0x0a0a90(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000A0A90ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC5FF8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8408E77ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40006B7ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1207 | PC: 0x0a0d88..0x0a0dd0 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0a0d88: D0001648  adrp     x8, #0x36a000
//   0x0a0d8c: 91352108  add      x8, x8, #0xd48
//   0x0a0d90: AA0003E9  mov      x9, x0
//   0x0a0d94: F9000008  str      x8, [x0]
//   0x0a0d98: 52800068  mov      w8, #3
//   0x0a0d9c: F8010D3F  str      xzr, [x9, #0x10]!
uint64_t fde_func_1207_0x0a0d88(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000A0D88ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0001648ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91352108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800068ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8010D3FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9002008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1211 | PC: 0x0a2098..0x0a2198 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0a2098: D103C3FF  sub      sp, sp, #0xf0
//   0x0a209c: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x0a20a0: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x0a20a4: A90B5FF8  stp      x24, x23, [sp, #0xb0]
//   0x0a20a8: A90C57F6  stp      x22, x21, [sp, #0xc0]
//   0x0a20ac: A90D4FF4  stp      x20, x19, [sp, #0xd0]
uint64_t fde_func_1211_0x0a2098(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000A2098ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD103C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9096FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A67FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B5FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C57F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E7BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910383FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1216 | PC: 0x0a4140..0x0a41f8 (184 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0a4140: D101C3FF  sub      sp, sp, #0x70
//   0x0a4144: F90013F9  str      x25, [sp, #0x20]
//   0x0a4148: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0a414c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0a4150: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0a4154: A9067BFD  stp      x29, x30, [sp, #0x60]
uint64_t fde_func_1216_0x0a4140(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000A4140ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD059ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1220 | PC: 0x0a4824..0x0a4924 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0a4824: D10503FF  sub      sp, sp, #0x140
//   0x0a4828: A90E6FFC  stp      x28, x27, [sp, #0xe0]
//   0x0a482c: A90F67FA  stp      x26, x25, [sp, #0xf0]
//   0x0a4830: A9105FF8  stp      x24, x23, [sp, #0x100]
//   0x0a4834: A91157F6  stp      x22, x21, [sp, #0x110]
//   0x0a4838: A9124FF4  stp      x20, x19, [sp, #0x120]
uint64_t fde_func_1220_0x0a4824(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000A4824ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10503FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E6FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90F67FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9105FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91157F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9124FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9137BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9104C3FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1225 | PC: 0x0a6990..0x0a6a90 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0a6990: D102C3FF  sub      sp, sp, #0xb0
//   0x0a6994: F90033F9  str      x25, [sp, #0x60]
//   0x0a6998: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x0a699c: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x0a69a0: A9094FF4  stp      x20, x19, [sp, #0x90]
//   0x0a69a4: A90A7BFD  stp      x29, x30, [sp, #0xa0]
uint64_t fde_func_1225_0x0a6990(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000A6990ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD102C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90033F9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9075FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90857F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9094FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A7BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910283FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1229 | PC: 0x0a700c..0x0a707c (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0a700c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0a7010: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a7014: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a7018: 910083FD  add      x29, sp, #0x20
//   0x0a701c: F9400808  ldr      x8, [x0, #0x10]
//   0x0a7020: B4000268  cbz      x8, #0xa706c
uint64_t fde_func_1229_0x0a700c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000A700CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400808ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000268ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9405008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1234 | PC: 0x0a72a8..0x0a7380 (216 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0a72a8: D101C3FF  sub      sp, sp, #0x70
//   0x0a72ac: F9001BF7  str      x23, [sp, #0x30]
//   0x0a72b0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0a72b4: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0a72b8: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x0a72bc: 910183FD  add      x29, sp, #0x60
uint64_t fde_func_1234_0x0a72a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000A72A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1238 | PC: 0x0a760c..0x0a76d8 (204 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0a760c: D10143FF  sub      sp, sp, #0x50
//   0x0a7610: F90013F5  str      x21, [sp, #0x20]
//   0x0a7614: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0a7618: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0a761c: 910103FD  add      x29, sp, #0x40
//   0x0a7620: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_1238_0x0a760c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000A760CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1243 | PC: 0x0a777c..0x0a77c8 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0a777c: B4000241  cbz      x1, #0xa77c4
//   0x0a7780: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a7784: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a7788: 910043FD  add      x29, sp, #0x10
//   0x0a778c: AA0103F3  mov      x19, x1
//   0x0a7790: F9400021  ldr      x1, [x1]
uint64_t fde_func_1243_0x0a777c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000A777CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000241ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400021ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFF9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1247 | PC: 0x0a788c..0x0a78c4 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0a788c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a7890: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a7894: 910043FD  add      x29, sp, #0x10
//   0x0a7898: F0001608  adrp     x8, #0x36a000
//   0x0a789c: 91390108  add      x8, x8, #0xe40
//   0x0a78a0: AA0003F3  mov      x19, x0
uint64_t fde_func_1247_0x0a788c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000A788CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001608ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91390108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940000FBULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1252 | PC: 0x0a7abc..0x0a7b10 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0a7abc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a7ac0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a7ac4: 910043FD  add      x29, sp, #0x10
//   0x0a7ac8: A9007C7F  stp      xzr, xzr, [x3]
//   0x0a7acc: F9000861  str      x1, [x3, #0x10]
//   0x0a7ad0: F9000043  str      x3, [x2]
uint64_t fde_func_1252_0x0a7abc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000A7ABCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007C7FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000861ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000043ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1256 | PC: 0x0a7cfc..0x0a7d20 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0a7cfc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a7d00: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a7d04: 910043FD  add      x29, sp, #0x10
//   0x0a7d08: AA0003F3  mov      x19, x0
//   0x0a7d0c: 97FFFFE2  bl       #0xa7c94
//   0x0a7d10: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_1256_0x0a7cfc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000A7CFCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFE2ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1261 | PC: 0x0a8814..0x0a8914 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0a8814: D10343FF  sub      sp, sp, #0xd0
//   0x0a8818: FD003BEA  str      d10, [sp, #0x70]
//   0x0a881c: 6D07A3E9  stp      d9, d8, [sp, #0x78]
//   0x0a8820: F90047F9  str      x25, [sp, #0x88]
//   0x0a8824: A9095FF8  stp      x24, x23, [sp, #0x90]
//   0x0a8828: A90A57F6  stp      x22, x21, [sp, #0xa0]
uint64_t fde_func_1261_0x0a8814(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000A8814ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10343FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD003BEAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D07A3E9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90047F9ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9095FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A57F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B4FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C7BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1265 | PC: 0x0a963c..0x0a972c (240 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0a963c: D101C3FF  sub      sp, sp, #0x70
//   0x0a9640: F9001BF7  str      x23, [sp, #0x30]
//   0x0a9644: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0a9648: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0a964c: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x0a9650: 910183FD  add      x29, sp, #0x60
uint64_t fde_func_1265_0x0a963c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000A963CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1270 | PC: 0x0a9c74..0x0a9cb8 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0a9c74: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a9c78: 910003FD  mov      x29, sp
//   0x0a9c7c: 52800060  mov      w0, #3
//   0x0a9c80: 97FE6F1D  bl       #0x458f4
//   0x0a9c84: 36000140  tbz      w0, #0, #0xa9cac
//   0x0a9c88: 90001101  adrp     x1, #0x2c9000
uint64_t fde_func_1270_0x0a9c74(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000A9C74ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800060ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FE6F1DULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000140ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001101ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001102ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001104ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1274 | PC: 0x0a9d2c..0x0a9d3c (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0a9d2c: 90001101  adrp     x1, #0x2c9000
//   0x0a9d30: 912F7421  add      x1, x1, #0xbdd
//   0x0a9d34: AA0803E0  mov      x0, x8
//   0x0a9d38: 17FE7F3A  b        #0x49a20
uint64_t fde_func_1274_0x0a9d2c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000A9D2CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001101ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912F7421ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FE7F3AULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1278 | PC: 0x0a9d5c..0x0a9d60 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0a9d5c: 14000005  b        #0xa9d70
uint64_t fde_func_1278_0x0a9d5c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000A9D5CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000005ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1283 | PC: 0x0a9dc0..0x0a9dc4 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0a9dc0: D4200020  brk      #1
uint64_t fde_func_1283_0x0a9dc0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000A9DC0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD4200020ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1287 | PC: 0x0a9de4..0x0a9df8 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0a9de4: 29410801  ldp      w1, w2, [x0, #8]
//   0x0a9de8: 29421003  ldp      w3, w4, [x0, #0x10]
//   0x0a9dec: 90001100  adrp     x0, #0x2c9000
//   0x0a9df0: 912E6400  add      x0, x0, #0xb99
//   0x0a9df4: 17FE70F0  b        #0x461b4
uint64_t fde_func_1287_0x0a9de4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000A9DE4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x29410801ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x29421003ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001100ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912E6400ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FE70F0ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1292 | PC: 0x0aa000..0x0aa004 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0aa000: 17FE68CC  b        #0x44330
uint64_t fde_func_1292_0x0aa000(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000AA000ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FE68CCULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1296 | PC: 0x0aa030..0x0aa130 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0aa030: D10203FF  sub      sp, sp, #0x80
//   0x0aa034: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0aa038: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0aa03c: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0aa040: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x0aa044: A9077BFD  stp      x29, x30, [sp, #0x70]
uint64_t fde_func_1296_0x0aa030(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000AA030ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90367FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9077BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD059ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1301 | PC: 0x0aa834..0x0aa934 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0aa834: D10243FF  sub      sp, sp, #0x90
//   0x0aa838: F90023F9  str      x25, [sp, #0x40]
//   0x0aa83c: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x0aa840: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x0aa844: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x0aa848: A9087BFD  stp      x29, x30, [sp, #0x80]
uint64_t fde_func_1301_0x0aa834(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000AA834ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9055FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1305 | PC: 0x0aaf1c..0x0ab01c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0aaf1c: D10243FF  sub      sp, sp, #0x90
//   0x0aaf20: F90023F9  str      x25, [sp, #0x40]
//   0x0aaf24: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x0aaf28: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x0aaf2c: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x0aaf30: A9087BFD  stp      x29, x30, [sp, #0x80]
uint64_t fde_func_1305_0x0aaf1c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000AAF1CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9055FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1310 | PC: 0x0ab2dc..0x0ab300 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ab2dc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ab2e0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ab2e4: 910043FD  add      x29, sp, #0x10
//   0x0ab2e8: AA0003F3  mov      x19, x0
//   0x0ab2ec: 97FFFFE8  bl       #0xab28c
//   0x0ab2f0: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_1310_0x0ab2dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000AB2DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFE8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1314 | PC: 0x0ab37c..0x0ab3b8 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ab37c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ab380: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ab384: 910043FD  add      x29, sp, #0x10
//   0x0ab388: 91006040  add      x0, x2, #0x18
//   0x0ab38c: AA0203F3  mov      x19, x2
//   0x0ab390: 97FFFFA9  bl       #0xab234
uint64_t fde_func_1314_0x0ab37c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000AB37CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006040ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFA9ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400268ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000088ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1319 | PC: 0x0ab468..0x0ab568 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ab468: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0ab46c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ab470: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ab474: 910083FD  add      x29, sp, #0x20
//   0x0ab478: 900016A8  adrp     x8, #0x37f000
//   0x0ab47c: AA0003F3  mov      x19, x0
uint64_t fde_func_1319_0x0ab468(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000AB468ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900016A8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9438400ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9471508ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1323 | PC: 0x0ab6cc..0x0ab738 (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ab6cc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0ab6d0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ab6d4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ab6d8: 910083FD  add      x29, sp, #0x20
//   0x0ab6dc: F9400015  ldr      x21, [x0]
//   0x0ab6e0: B4000195  cbz      x21, #0xab710
uint64_t fde_func_1323_0x0ab6cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000AB6CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400015ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000195ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400414ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1328 | PC: 0x0aba08..0x0aba5c (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0aba08: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0aba0c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0aba10: 910043FD  add      x29, sp, #0x10
//   0x0aba14: A9007C7F  stp      xzr, xzr, [x3]
//   0x0aba18: F9000861  str      x1, [x3, #0x10]
//   0x0aba1c: F9000043  str      x3, [x2]
uint64_t fde_func_1328_0x0aba08(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000ABA08ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007C7FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000861ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000043ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1332 | PC: 0x0abb48..0x0abba8 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0abb48: 90001608  adrp     x8, #0x36b000
//   0x0abb4c: 9109E108  add      x8, x8, #0x278
//   0x0abb50: F9000028  str      x8, [x1]
//   0x0abb54: F9400408  ldr      x8, [x0, #8]
//   0x0abb58: F9000428  str      x8, [x1, #8]
//   0x0abb5c: F9400808  ldr      x8, [x0, #0x10]
uint64_t fde_func_1332_0x0abb48(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000ABB48ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001608ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9109E108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000028ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000428ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400808ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000828ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1337 | PC: 0x0abcb4..0x0abcc0 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0abcb4: 90001600  adrp     x0, #0x36b000
//   0x0abcb8: 910B6000  add      x0, x0, #0x2d8
//   0x0abcbc: D65F03C0  ret      
uint64_t fde_func_1337_0x0abcb4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000ABCB4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001600ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910B6000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1341 | PC: 0x0abd80..0x0abd9c (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0abd80: 90001609  adrp     x9, #0x36b000
//   0x0abd84: AA0103E8  mov      x8, x1
//   0x0abd88: 910BE129  add      x9, x9, #0x2f8
//   0x0abd8c: F8008509  str      x9, [x8], #8
//   0x0abd90: 91002001  add      x1, x0, #8
//   0x0abd94: AA0803E0  mov      x0, x8
uint64_t fde_func_1341_0x0abd80(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000ABD80ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001609ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910BE129ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8008509ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002001ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000066ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1346 | PC: 0x0abf24..0x0abf30 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0abf24: 90001600  adrp     x0, #0x36b000
//   0x0abf28: 910D6000  add      x0, x0, #0x358
//   0x0abf2c: D65F03C0  ret      
uint64_t fde_func_1346_0x0abf24(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000ABF24ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001600ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910D6000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1350 | PC: 0x0ac018..0x0ac098 (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ac018: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ac01c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ac020: 910043FD  add      x29, sp, #0x10
//   0x0ac024: AA0003F3  mov      x19, x0
//   0x0ac028: 52800600  mov      w0, #0x30
//   0x0ac02c: 97FE6029  bl       #0x440d0
uint64_t fde_func_1350_0x0ac018(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000AC018ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800600ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FE6029ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00015E8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910DE108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1355 | PC: 0x0ac170..0x0ac18c (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ac170: F9400428  ldr      x8, [x1, #8]
//   0x0ac174: D00010E9  adrp     x9, #0x2ca000
//   0x0ac178: 91077529  add      x9, x9, #0x1dd
//   0x0ac17c: 9100200A  add      x10, x0, #8
//   0x0ac180: EB09011F  cmp      x8, x9
//   0x0ac184: 9A9F0140  csel     x0, x10, xzr, eq
uint64_t fde_func_1355_0x0ac170(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000AC170ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00010E9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91077529ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100200AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A9F0140ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1359 | PC: 0x0ac200..0x0ac280 (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ac200: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ac204: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ac208: 910043FD  add      x29, sp, #0x10
//   0x0ac20c: AA0003F3  mov      x19, x0
//   0x0ac210: 52800600  mov      w0, #0x30
//   0x0ac214: 97FE5FAF  bl       #0x440d0
uint64_t fde_func_1359_0x0ac200(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000AC200ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800600ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FE5FAFULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00015E8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910FE108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1363 | PC: 0x0ac338..0x0ac34c (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ac338: F9400408  ldr      x8, [x0, #8]
//   0x0ac33c: 91004001  add      x1, x0, #0x10
//   0x0ac340: 91008002  add      x2, x0, #0x20
//   0x0ac344: AA0803E0  mov      x0, x8
//   0x0ac348: 17FFFB8F  b        #0xab184
uint64_t fde_func_1363_0x0ac338(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000AC338ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004001ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91008002ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFB8FULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1368 | PC: 0x0ac3dc..0x0ac45c (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ac3dc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ac3e0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ac3e4: 910043FD  add      x29, sp, #0x10
//   0x0ac3e8: AA0003F3  mov      x19, x0
//   0x0ac3ec: 52800600  mov      w0, #0x30
//   0x0ac3f0: 97FE5F38  bl       #0x440d0
uint64_t fde_func_1368_0x0ac3dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000AC3DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800600ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FE5F38ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00015E8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9111E108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1372 | PC: 0x0ac514..0x0ac528 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ac514: F9400408  ldr      x8, [x0, #8]
//   0x0ac518: 91004001  add      x1, x0, #0x10
//   0x0ac51c: 91008002  add      x2, x0, #0x20
//   0x0ac520: AA0803E0  mov      x0, x8
//   0x0ac524: 17FFFB18  b        #0xab184
uint64_t fde_func_1372_0x0ac514(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000AC514ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004001ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91008002ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFB18ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1377 | PC: 0x0ac5bc..0x0ac63c (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ac5bc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ac5c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ac5c4: 910043FD  add      x29, sp, #0x10
//   0x0ac5c8: AA0003F3  mov      x19, x0
//   0x0ac5cc: 52800600  mov      w0, #0x30
//   0x0ac5d0: 97FE5EC0  bl       #0x440d0
uint64_t fde_func_1377_0x0ac5bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000AC5BCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800600ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FE5EC0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00015E8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9113E108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1381 | PC: 0x0ac6f8..0x0ac714 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ac6f8: AA0003E2  mov      x2, x0
//   0x0ac6fc: F8408C49  ldr      x9, [x2, #8]!
//   0x0ac700: 52800028  mov      w8, #1
//   0x0ac704: F9400840  ldr      x0, [x2, #0x10]
//   0x0ac708: 91006041  add      x1, x2, #0x18
//   0x0ac70c: B9002528  str      w8, [x9, #0x24]
uint64_t fde_func_1381_0x0ac6f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000AC6F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E2ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8408C49ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800028ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400840ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006041ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9002528ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFA9DULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1386 | PC: 0x0ac7a8..0x0ac828 (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ac7a8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ac7ac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ac7b0: 910043FD  add      x29, sp, #0x10
//   0x0ac7b4: AA0003F3  mov      x19, x0
//   0x0ac7b8: 52800600  mov      w0, #0x30
//   0x0ac7bc: 97FE5E45  bl       #0x440d0
uint64_t fde_func_1386_0x0ac7a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000AC7A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800600ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FE5E45ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00015E8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9115E108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1390 | PC: 0x0ac8e4..0x0ac900 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ac8e4: AA0003E2  mov      x2, x0
//   0x0ac8e8: F8408C49  ldr      x9, [x2, #8]!
//   0x0ac8ec: 52800028  mov      w8, #1
//   0x0ac8f0: F9400840  ldr      x0, [x2, #0x10]
//   0x0ac8f4: 91006041  add      x1, x2, #0x18
//   0x0ac8f8: B9002528  str      w8, [x9, #0x24]
uint64_t fde_func_1390_0x0ac8e4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000AC8E4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E2ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8408C49ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800028ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400840ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006041ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9002528ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFA22ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1395 | PC: 0x0ac994..0x0aca14 (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ac994: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ac998: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ac99c: 910043FD  add      x29, sp, #0x10
//   0x0ac9a0: AA0003F3  mov      x19, x0
//   0x0ac9a4: 52800600  mov      w0, #0x30
//   0x0ac9a8: 97FE5DCA  bl       #0x440d0
uint64_t fde_func_1395_0x0ac994(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000AC994ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800600ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FE5DCAULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00015E8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9117E108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1399 | PC: 0x0acad0..0x0acaec (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0acad0: AA0003E2  mov      x2, x0
//   0x0acad4: F8408C49  ldr      x9, [x2, #8]!
//   0x0acad8: 52800028  mov      w8, #1
//   0x0acadc: F9400840  ldr      x0, [x2, #0x10]
//   0x0acae0: 91006041  add      x1, x2, #0x18
//   0x0acae4: B9002528  str      w8, [x9, #0x24]
uint64_t fde_func_1399_0x0acad0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000ACAD0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E2ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8408C49ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800028ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400840ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006041ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9002528ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFF9A7ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1404 | PC: 0x0adcec..0x0addec (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0adcec: D101C3FF  sub      sp, sp, #0x70
//   0x0adcf0: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0adcf4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0adcf8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0adcfc: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x0add00: 910183FD  add      x29, sp, #0x60
uint64_t fde_func_1404_0x0adcec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000ADCECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401709ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1408 | PC: 0x0ae6a0..0x0ae7a0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ae6a0: D10643FF  sub      sp, sp, #0x190
//   0x0ae6a4: FD009BE8  str      d8, [sp, #0x130]
//   0x0ae6a8: A91467FC  stp      x28, x25, [sp, #0x140]
//   0x0ae6ac: A9155FF8  stp      x24, x23, [sp, #0x150]
//   0x0ae6b0: A91657F6  stp      x22, x21, [sp, #0x160]
//   0x0ae6b4: A9174FF4  stp      x20, x19, [sp, #0x170]
uint64_t fde_func_1408_0x0ae6a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000AE6A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10643FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD009BE8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91467FCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9155FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91657F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9174FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9187BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910603FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1413 | PC: 0x0b0e80..0x0b0f80 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0b0e80: D107C3FF  sub      sp, sp, #0x1f0
//   0x0b0e84: FD00BBEA  str      d10, [sp, #0x170]
//   0x0b0e88: 6D1823E9  stp      d9, d8, [sp, #0x180]
//   0x0b0e8c: A9196FFC  stp      x28, x27, [sp, #0x190]
//   0x0b0e90: A91A67FA  stp      x26, x25, [sp, #0x1a0]
//   0x0b0e94: A91B5FF8  stp      x24, x23, [sp, #0x1b0]
uint64_t fde_func_1413_0x0b0e80(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000B0E80ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD107C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD00BBEAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D1823E9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9196FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91A67FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91B5FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91C57F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91D4FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1417 | PC: 0x0b2bb4..0x0b2c5c (168 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0b2bb4: D10043FF  sub      sp, sp, #0x10
//   0x0b2bb8: FD0007E0  str      d0, [sp, #8]
//   0x0b2bbc: A942A009  ldp      x9, x8, [x0, #0x28]
//   0x0b2bc0: EB09011F  cmp      x8, x9
//   0x0b2bc4: 54000160  b.eq     #0xb2bf0
//   0x0b2bc8: FC5F0101  ldur     d1, [x8, #-0x10]
uint64_t fde_func_1417_0x0b2bb4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000B2BB4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10043FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD0007E0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA942A009ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000160ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFC5F0101ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1E602020ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000109ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1422 | PC: 0x0b33a4..0x0b33ec (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0b33a4: B9401808  ldr      w8, [x0, #0x18]
//   0x0b33a8: 3DC00802  ldr      q2, [x0, #0x20]
//   0x0b33ac: FD401804  ldr      d4, [x0, #0x30]
//   0x0b33b0: 1E600801  fmul     d1, d0, d0
//   0x0b33b4: 4EA01C03  mov      v3.16b, v0.16b
//   0x0b33b8: 6E180423  mov      v3.d[1], v1.d[0]
uint64_t fde_func_1422_0x0b33a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000B33A4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9401808ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3DC00802ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD401804ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1E600801ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x4EA01C03ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6E180423ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x11000508ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x4E63D441ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1426 | PC: 0x0b35b8..0x0b3684 (204 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0b35b8: D10143FF  sub      sp, sp, #0x50
//   0x0b35bc: F9000BF7  str      x23, [sp, #0x10]
//   0x0b35c0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0b35c4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0b35c8: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0b35cc: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_1426_0x0b35b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000B35B8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1431 | PC: 0x0b38b4..0x0b38c0 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0b38b4: F8418C08  ldr      x8, [x0, #0x18]!
//   0x0b38b8: F9400101  ldr      x1, [x8]
//   0x0b38bc: D61F0020  br       x1
uint64_t fde_func_1431_0x0b38b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000B38B4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8418C08ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400101ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0020ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1435 | PC: 0x0b39a8..0x0b39ec (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0b39a8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b39ac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b39b0: 910043FD  add      x29, sp, #0x10
//   0x0b39b4: AA0003F3  mov      x19, x0
//   0x0b39b8: F9402000  ldr      x0, [x0, #0x40]
//   0x0b39bc: 900015C8  adrp     x8, #0x36b000
uint64_t fde_func_1435_0x0b39a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000B39A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900015C8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911E4108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000268ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1439 | PC: 0x0b3ae8..0x0b3bb8 (208 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0b3ae8: D10183FF  sub      sp, sp, #0x60
//   0x0b3aec: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0b3af0: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0b3af4: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x0b3af8: 910143FD  add      x29, sp, #0x50
//   0x0b3afc: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_1439_0x0b3ae8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000B3AE8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90017E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1444 | PC: 0x0b3d9c..0x0b3de0 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0b3d9c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b3da0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b3da4: 910043FD  add      x29, sp, #0x10
//   0x0b3da8: AA0003F3  mov      x19, x0
//   0x0b3dac: F9401800  ldr      x0, [x0, #0x30]
//   0x0b3db0: 900015C8  adrp     x8, #0x36b000
uint64_t fde_func_1444_0x0b3d9c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000B3D9CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401800ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900015C8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911F8108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000268ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1448 | PC: 0x0b3ed8..0x0b3fa8 (208 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0b3ed8: D10183FF  sub      sp, sp, #0x60
//   0x0b3edc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0b3ee0: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0b3ee4: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x0b3ee8: 910143FD  add      x29, sp, #0x50
//   0x0b3eec: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_1448_0x0b3ed8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000B3ED8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90017E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1453 | PC: 0x0b4174..0x0b4178 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0b4174: D65F03C0  ret      
uint64_t fde_func_1453_0x0b4174(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000B4174ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1457 | PC: 0x0b4428..0x0b4528 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0b4428: D10343FF  sub      sp, sp, #0xd0
//   0x0b442c: F9003BFB  str      x27, [sp, #0x70]
//   0x0b4430: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x0b4434: A9095FF8  stp      x24, x23, [sp, #0x90]
//   0x0b4438: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x0b443c: A90B4FF4  stp      x20, x19, [sp, #0xb0]
uint64_t fde_func_1457_0x0b4428(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000B4428ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10343FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9003BFBULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90867FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9095FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A57F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C7BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910303FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1462 | PC: 0x0b68ac..0x0b68e4 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0b68ac: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b68b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b68b4: 910043FD  add      x29, sp, #0x10
//   0x0b68b8: B00015A8  adrp     x8, #0x36b000
//   0x0b68bc: 91220108  add      x8, x8, #0x880
//   0x0b68c0: AA0003F3  mov      x19, x0
uint64_t fde_func_1462_0x0b68ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000B68ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB00015A8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91220108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8060408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFD2E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1466 | PC: 0x0b6c30..0x0b6c34 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0b6c30: 17FE35C0  b        #0x44330
uint64_t fde_func_1466_0x0b6c30(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000B6C30ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FE35C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1471 | PC: 0x0b6cb8..0x0b6cbc (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0b6cb8: 17FE359E  b        #0x44330
uint64_t fde_func_1471_0x0b6cb8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000B6CB8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FE359EULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1475 | PC: 0x0b6d30..0x0b6d34 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0b6d30: 17FE3580  b        #0x44330
uint64_t fde_func_1475_0x0b6d30(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000B6D30ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FE3580ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1480 | PC: 0x0b8684..0x0b8784 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0b8684: F81C0FFC  str      x28, [sp, #-0x40]!
//   0x0b8688: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0b868c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0b8690: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0b8694: 9100C3FD  add      x29, sp, #0x30
//   0x0b8698: D10943FF  sub      sp, sp, #0x250
uint64_t fde_func_1480_0x0b8684(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000B8684ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81C0FFCULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10943FFULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1484 | PC: 0x0ba2ec..0x0ba3ec (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ba2ec: D10243FF  sub      sp, sp, #0x90
//   0x0ba2f0: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0ba2f4: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x0ba2f8: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x0ba2fc: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x0ba300: A9087BFD  stp      x29, x30, [sp, #0x80]
uint64_t fde_func_1484_0x0ba2ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000BA2ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90467FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9055FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1489 | PC: 0x0bb42c..0x0bb52c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0bb42c: D10343FF  sub      sp, sp, #0xd0
//   0x0bb430: F90043F9  str      x25, [sp, #0x80]
//   0x0bb434: A9095FF8  stp      x24, x23, [sp, #0x90]
//   0x0bb438: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x0bb43c: A90B4FF4  stp      x20, x19, [sp, #0xb0]
//   0x0bb440: A90C7BFD  stp      x29, x30, [sp, #0xc0]
uint64_t fde_func_1489_0x0bb42c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000BB42CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10343FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90043F9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9095FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A57F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B4FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C7BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910303FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1493 | PC: 0x0bbf00..0x0bc000 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0bbf00: D101C3FF  sub      sp, sp, #0x70
//   0x0bbf04: F90023F5  str      x21, [sp, #0x40]
//   0x0bbf08: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0bbf0c: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x0bbf10: 910183FD  add      x29, sp, #0x60
//   0x0bbf14: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_1493_0x0bbf00(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000BBF00ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043E2ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1498 | PC: 0x0bd40c..0x0bd50c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0bd40c: D10243FF  sub      sp, sp, #0x90
//   0x0bd410: F90023F9  str      x25, [sp, #0x40]
//   0x0bd414: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x0bd418: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x0bd41c: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x0bd420: A9087BFD  stp      x29, x30, [sp, #0x80]
uint64_t fde_func_1498_0x0bd40c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000BD40CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9055FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1502 | PC: 0x0be0fc..0x0be170 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0be0fc: D100C3FF  sub      sp, sp, #0x30
//   0x0be100: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0be104: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0be108: 910083FD  add      x29, sp, #0x20
//   0x0be10c: D53BD054  mrs      x20, tpidr_el0
//   0x0be110: F9401688  ldr      x8, [x20, #0x28]
uint64_t fde_func_1502_0x0be0fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000BE0FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90007E8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400020ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1507 | PC: 0x0be904..0x0be994 (144 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0be904: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0be908: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0be90c: 910043FD  add      x29, sp, #0x10
//   0x0be910: B9400428  ldr      w8, [x1, #4]
//   0x0be914: 34000148  cbz      w8, #0xbe93c
//   0x0be918: 2942A428  ldp      w8, w9, [x1, #0x14]
uint64_t fde_func_1507_0x0be904(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000BE904ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9400428ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000148ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2942A428ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x0B090108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100011FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1511 | PC: 0x0befb8..0x0bf04c (148 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0befb8: D10043FF  sub      sp, sp, #0x10
//   0x0befbc: F90007E1  str      x1, [sp, #8]
//   0x0befc0: A942A009  ldp      x9, x8, [x0, #0x28]
//   0x0befc4: EB09011F  cmp      x8, x9
//   0x0befc8: 54000160  b.eq     #0xbeff4
//   0x0befcc: F85F010A  ldur     x10, [x8, #-0x10]
uint64_t fde_func_1511_0x0befb8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000BEFB8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10043FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90007E1ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA942A009ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000160ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85F010AULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB01015FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5400010DULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1516 | PC: 0x0bf218..0x0bf258 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0bf218: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0bf21c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bf220: 910043FD  add      x29, sp, #0x10
//   0x0bf224: D37DFC28  lsr      x8, x1, #0x3d
//   0x0bf228: B5000168  cbnz     x8, #0xbf254
//   0x0bf22c: AA0003F4  mov      x20, x0
uint64_t fde_func_1516_0x0bf218(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000BF218ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD37DFC28ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB5000168ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD37DF020ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1520 | PC: 0x0bf444..0x0bf544 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0bf444: D10183FF  sub      sp, sp, #0x60
//   0x0bf448: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0bf44c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0bf450: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0bf454: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0bf458: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_1520_0x0bf444(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000BF444ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD05AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1524 | PC: 0x0bf7c8..0x0bf820 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0bf7c8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0bf7cc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0bf7d0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0bf7d4: 910083FD  add      x29, sp, #0x20
//   0x0bf7d8: AA0003F5  mov      x21, x0
//   0x0bf7dc: AA0103E0  mov      x0, x1
uint64_t fde_func_1524_0x0bf7c8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000BF7C8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1529 | PC: 0x0bfa8c..0x0bfa90 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0bfa8c: 17FE1229  b        #0x44330
uint64_t fde_func_1529_0x0bfa8c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000BFA8CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FE1229ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1533 | PC: 0x0bfabc..0x0bfaf8 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0bfabc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0bfac0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bfac4: 910043FD  add      x29, sp, #0x10
//   0x0bfac8: AA0003F3  mov      x19, x0
//   0x0bfacc: F9402000  ldr      x0, [x0, #0x40]
//   0x0bfad0: 90001568  adrp     x8, #0x36b000
uint64_t fde_func_1533_0x0bfabc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000BFABCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001568ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912EC108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000268ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1538 | PC: 0x0bfc38..0x0bfd08 (208 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0bfc38: D10183FF  sub      sp, sp, #0x60
//   0x0bfc3c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0bfc40: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0bfc44: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x0bfc48: 910143FD  add      x29, sp, #0x50
//   0x0bfc4c: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_1538_0x0bfc38(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000BFC38ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90017E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1542 | PC: 0x0bfeb0..0x0bffb0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0bfeb0: D10203FF  sub      sp, sp, #0x80
//   0x0bfeb4: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0bfeb8: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0bfebc: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0bfec0: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x0bfec4: A9077BFD  stp      x29, x30, [sp, #0x70]
uint64_t fde_func_1542_0x0bfeb0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000BFEB0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90367FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9077BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD059ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1547 | PC: 0x0c0300..0x0c0350 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c0300: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0c0304: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c0308: 910043FD  add      x29, sp, #0x10
//   0x0c030c: F0001548  adrp     x8, #0x36b000
//   0x0c0310: 91300108  add      x8, x8, #0xc00
//   0x0c0314: F9402C01  ldr      x1, [x0, #0x58]
uint64_t fde_func_1547_0x0c0300(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C0300ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001548ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91300108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402C01ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C109ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9E670100ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1551 | PC: 0x0c03a4..0x0c03f0 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c03a4: B4000241  cbz      x1, #0xc03ec
//   0x0c03a8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c03ac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c03b0: 910043FD  add      x29, sp, #0x10
//   0x0c03b4: AA0103F3  mov      x19, x1
//   0x0c03b8: F9400021  ldr      x1, [x1]
uint64_t fde_func_1551_0x0c03a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C03A4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000241ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400021ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFF9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1556 | PC: 0x0c04ec..0x0c04f8 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c04ec: F8418C08  ldr      x8, [x0, #0x18]!
//   0x0c04f0: F9400101  ldr      x1, [x8]
//   0x0c04f4: D61F0020  br       x1
uint64_t fde_func_1556_0x0c04ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C04ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8418C08ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400101ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0020ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1560 | PC: 0x0c06e4..0x0c0738 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c06e4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0c06e8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c06ec: 910043FD  add      x29, sp, #0x10
//   0x0c06f0: A9007C7F  stp      xzr, xzr, [x3]
//   0x0c06f4: F9000861  str      x1, [x3, #0x10]
//   0x0c06f8: F9000043  str      x3, [x2]
uint64_t fde_func_1560_0x0c06e4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C06E4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007C7FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000861ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000043ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1565 | PC: 0x0c0888..0x0c08ec (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c0888: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c088c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c0890: 910043FD  add      x29, sp, #0x10
//   0x0c0894: 2A0103F4  mov      w20, w1
//   0x0c0898: AA0003F3  mov      x19, x0
//   0x0c089c: 9400019A  bl       #0xc0f04
uint64_t fde_func_1565_0x0c0888(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C0888ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400019AULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x51000A88ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x71000D1FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1569 | PC: 0x0c0ba4..0x0c0bb8 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c0ba4: F0001548  adrp     x8, #0x36b000
//   0x0c0ba8: 9135C108  add      x8, x8, #0xd70
//   0x0c0bac: F9000008  str      x8, [x0]
//   0x0c0bb0: B9000801  str      w1, [x0, #8]
//   0x0c0bb4: D65F03C0  ret      
uint64_t fde_func_1569_0x0c0ba4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C0BA4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001548ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9135C108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9000801ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1574 | PC: 0x0c0de4..0x0c0e6c (136 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c0de4: D10103FF  sub      sp, sp, #0x40
//   0x0c0de8: F90013F3  str      x19, [sp, #0x20]
//   0x0c0dec: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0c0df0: 9100C3FD  add      x29, sp, #0x30
//   0x0c0df4: D53BD053  mrs      x19, tpidr_el0
//   0x0c0df8: F9401668  ldr      x8, [x19, #0x28]
uint64_t fde_func_1574_0x0c0de4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C0DE4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F3ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD053ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401668ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1289C3E9ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x0B090029ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1578 | PC: 0x0c102c..0x0c10ac (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c102c: D10103FF  sub      sp, sp, #0x40
//   0x0c1030: F90013F3  str      x19, [sp, #0x20]
//   0x0c1034: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0c1038: 9100C3FD  add      x29, sp, #0x30
//   0x0c103c: D53BD053  mrs      x19, tpidr_el0
//   0x0c1040: F9401668  ldr      x8, [x19, #0x28]
uint64_t fde_func_1578_0x0c102c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C102CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F3ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD053ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401668ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x129387E9ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x0B090029ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1583 | PC: 0x0c139c..0x0c149c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c139c: D10143FF  sub      sp, sp, #0x50
//   0x0c13a0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0c13a4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0c13a8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0c13ac: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0c13b0: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_1583_0x0c139c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C139CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1587 | PC: 0x0c1628..0x0c1728 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c1628: D10183FF  sub      sp, sp, #0x60
//   0x0c162c: F9000BF9  str      x25, [sp, #0x10]
//   0x0c1630: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0c1634: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0c1638: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0c163c: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_1587_0x0c1628(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C1628ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD059ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1592 | PC: 0x0c1d0c..0x0c1de8 (220 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c1d0c: D10103FF  sub      sp, sp, #0x40
//   0x0c1d10: F9000BF5  str      x21, [sp, #0x10]
//   0x0c1d14: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0c1d18: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0c1d1c: 9100C3FD  add      x29, sp, #0x30
//   0x0c1d20: AA0103F4  mov      x20, x1
uint64_t fde_func_1592_0x0c1d0c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C1D0CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1596 | PC: 0x0c1f10..0x0c1fd4 (196 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c1f10: D101C3FF  sub      sp, sp, #0x70
//   0x0c1f14: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0c1f18: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0c1f1c: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0c1f20: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x0c1f24: 910183FD  add      x29, sp, #0x60
uint64_t fde_func_1596_0x0c1f10(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C1F10ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1600 | PC: 0x0c21b0..0x0c2208 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c21b0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0c21b4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c21b8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c21bc: 910083FD  add      x29, sp, #0x20
//   0x0c21c0: B9400028  ldr      w8, [x1]
//   0x0c21c4: 91002013  add      x19, x0, #8
uint64_t fde_func_1600_0x0c21b0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C21B0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9400028ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002013ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA900CC13ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000C1FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1605 | PC: 0x0c22bc..0x0c22c0 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c22bc: 17FE081D  b        #0x44330
uint64_t fde_func_1605_0x0c22bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C22BCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FE081DULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1609 | PC: 0x0c2334..0x0c2338 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c2334: 17FE07FF  b        #0x44330
uint64_t fde_func_1609_0x0c2334(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C2334ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FE07FFULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1614 | PC: 0x0c2550..0x0c2588 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c2550: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0c2554: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c2558: 910043FD  add      x29, sp, #0x10
//   0x0c255c: B0001548  adrp     x8, #0x36b000
//   0x0c2560: 913AA108  add      x8, x8, #0xea8
//   0x0c2564: AA0003F3  mov      x19, x0
uint64_t fde_func_1614_0x0c2550(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C2550ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001548ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913AA108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94011DE6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1618 | PC: 0x0c25c8..0x0c2600 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c25c8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0c25cc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c25d0: 910043FD  add      x29, sp, #0x10
//   0x0c25d4: B0001548  adrp     x8, #0x36b000
//   0x0c25d8: 913BE108  add      x8, x8, #0xef8
//   0x0c25dc: AA0003F3  mov      x19, x0
uint64_t fde_func_1618_0x0c25c8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C25C8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001548ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913BE108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400000BULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1623 | PC: 0x0c26e8..0x0c2720 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c26e8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0c26ec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c26f0: 910043FD  add      x29, sp, #0x10
//   0x0c26f4: B0001548  adrp     x8, #0x36b000
//   0x0c26f8: 913D2108  add      x8, x8, #0xf48
//   0x0c26fc: AA0003F3  mov      x19, x0
uint64_t fde_func_1623_0x0c26e8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C26E8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001548ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913D2108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400003BULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1627 | PC: 0x0c27f0..0x0c2888 (152 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c27f0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0c27f4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c27f8: 910043FD  add      x29, sp, #0x10
//   0x0c27fc: B00015E8  adrp     x8, #0x37f000
//   0x0c2800: F9475108  ldr      x8, [x8, #0xea0]
//   0x0c2804: AA0003F3  mov      x19, x0
uint64_t fde_func_1627_0x0c27f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C27F0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB00015E8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9475108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1632 | PC: 0x0c2900..0x0c2930 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c2900: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0c2904: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c2908: 910043FD  add      x29, sp, #0x10
//   0x0c290c: B0001548  adrp     x8, #0x36b000
//   0x0c2910: 913FA108  add      x8, x8, #0xfe8
//   0x0c2914: AA0003F3  mov      x19, x0
uint64_t fde_func_1632_0x0c2900(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C2900ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001548ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913FA108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000017ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1636 | PC: 0x0c2978..0x0c2a0c (148 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c2978: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0c297c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c2980: 910043FD  add      x29, sp, #0x10
//   0x0c2984: B00015E9  adrp     x9, #0x37f000
//   0x0c2988: 39422008  ldrb     w8, [x0, #0x88]
//   0x0c298c: F9470529  ldr      x9, [x9, #0xe08]
uint64_t fde_func_1636_0x0c2978(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C2978ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB00015E9ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39422008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9470529ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004129ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1641 | PC: 0x0c2d14..0x0c2d7c (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c2d14: 510FA009  sub      w9, w0, #0x3e8
//   0x0c2d18: 71000D3F  cmp      w9, #3
//   0x0c2d1c: 54000148  b.hi     #0xc2d44
//   0x0c2d20: F000104A  adrp     x10, #0x2cd000
//   0x0c2d24: 9102814A  add      x10, x10, #0xa0
//   0x0c2d28: 1000008B  adr      x11, #0xc2d38
uint64_t fde_func_1641_0x0c2d14(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C2D14ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x510FA009ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x71000D3FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000148ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF000104AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102814AULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1000008BULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3869694CULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B0C096BULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1645 | PC: 0x0c3220..0x0c3320 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c3220: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0c3224: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c3228: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c322c: 910083FD  add      x29, sp, #0x20
//   0x0c3230: B0001548  adrp     x8, #0x36c000
//   0x0c3234: 9100E108  add      x8, x8, #0x38
uint64_t fde_func_1645_0x0c3220(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C3220ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001548ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100E108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB00015F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1650 | PC: 0x0c3774..0x0c37cc (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c3774: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0c3778: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c377c: 910043FD  add      x29, sp, #0x10
//   0x0c3780: F9400413  ldr      x19, [x0, #8]
//   0x0c3784: B40000F3  cbz      x19, #0xc37a0
//   0x0c3788: 91002268  add      x8, x19, #8
uint64_t fde_func_1650_0x0c3774(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C3774ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400413ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002268ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC85FFD09ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100052AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1654 | PC: 0x0c3820..0x0c3920 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c3820: D10203FF  sub      sp, sp, #0x80
//   0x0c3824: F90013FB  str      x27, [sp, #0x20]
//   0x0c3828: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0c382c: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0c3830: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0c3834: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_1654_0x0c3820(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C3820ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013FBULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90367FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9077BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C3FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1659 | PC: 0x0c4048..0x0c40dc (148 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c4048: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0c404c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c4050: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c4054: 910083FD  add      x29, sp, #0x20
//   0x0c4058: 910C4013  add      x19, x0, #0x310
//   0x0c405c: AA0003F5  mov      x21, x0
uint64_t fde_func_1659_0x0c4048(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C4048ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910C4013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1663 | PC: 0x0c4580..0x0c45b0 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c4580: F9413C08  ldr      x8, [x0, #0x278]
//   0x0c4584: B40000A8  cbz      x8, #0xc4598
//   0x0c4588: 39498008  ldrb     w8, [x0, #0x260]
//   0x0c458c: 370000A8  tbnz     w8, #0, #0xc45a0
//   0x0c4590: D341FD08  lsr      x8, x8, #1
//   0x0c4594: 14000004  b        #0xc45a4
uint64_t fde_func_1663_0x0c4580(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C4580ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9413C08ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000A8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39498008ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x370000A8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD341FD08ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000004ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1668 | PC: 0x0c4988..0x0c49d8 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c4988: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0c498c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c4990: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c4994: 910083FD  add      x29, sp, #0x20
//   0x0c4998: 910C4013  add      x19, x0, #0x310
//   0x0c499c: AA0003F5  mov      x21, x0
uint64_t fde_func_1668_0x0c4988(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C4988ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910C4013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1672 | PC: 0x0c4cc8..0x0c4d44 (124 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c4cc8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0c4ccc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c4cd0: 910043FD  add      x29, sp, #0x10
//   0x0c4cd4: A9402029  ldp      x9, x8, [x1]
//   0x0c4cd8: B40000C8  cbz      x8, #0xc4cf0
//   0x0c4cdc: 9100210A  add      x10, x8, #8
uint64_t fde_func_1672_0x0c4cc8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C4CC8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402029ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100210AULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC85F7D4BULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100056BULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1677 | PC: 0x0c4e5c..0x0c4f5c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c4e5c: D10243FF  sub      sp, sp, #0x90
//   0x0c4e60: F90023F9  str      x25, [sp, #0x40]
//   0x0c4e64: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x0c4e68: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x0c4e6c: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x0c4e70: A9087BFD  stp      x29, x30, [sp, #0x80]
uint64_t fde_func_1677_0x0c4e5c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C4E5CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9055FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD059ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1681 | PC: 0x0c5490..0x0c54c8 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c5490: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c5494: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c5498: 910043FD  add      x29, sp, #0x10
//   0x0c549c: 2A0103F4  mov      w20, w1
//   0x0c54a0: AA0003F3  mov      x19, x0
//   0x0c54a4: 97FFEF02  bl       #0xc10ac
uint64_t fde_func_1681_0x0c5490(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C5490ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFEF02ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5289DD28ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6B08029FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1685 | PC: 0x0c572c..0x0c576c (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c572c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0c5730: 910003FD  mov      x29, sp
//   0x0c5734: F00015C8  adrp     x8, #0x380000
//   0x0c5738: 91244108  add      x8, x8, #0x910
//   0x0c573c: 08DFFD08  ldarb    w8, [x8]
//   0x0c5740: 36000068  tbz      w8, #0, #0xc574c
uint64_t fde_func_1685_0x0c572c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C572CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00015C8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91244108ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x08DFFD08ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000068ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA8C17BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1690 | PC: 0x0c5c6c..0x0c5cd0 (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c5c6c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0c5c70: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c5c74: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c5c78: 910083FD  add      x29, sp, #0x20
//   0x0c5c7c: 910C4013  add      x19, x0, #0x310
//   0x0c5c80: AA0003F5  mov      x21, x0
uint64_t fde_func_1690_0x0c5c6c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C5C6CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910C4013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1694 | PC: 0x0c5e04..0x0c5e44 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c5e04: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c5e08: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c5e0c: 910043FD  add      x29, sp, #0x10
//   0x0c5e10: 910C4014  add      x20, x0, #0x310
//   0x0c5e14: AA0003F3  mov      x19, x0
//   0x0c5e18: AA1403E0  mov      x0, x20
uint64_t fde_func_1694_0x0c5e04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C5E04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910C4014ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1403E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FDFAADULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF941A668ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1699 | PC: 0x0c5fbc..0x0c6020 (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c5fbc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0c5fc0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c5fc4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c5fc8: 910083FD  add      x29, sp, #0x20
//   0x0c5fcc: 910F4013  add      x19, x0, #0x3d0
//   0x0c5fd0: AA0003F5  mov      x21, x0
uint64_t fde_func_1699_0x0c5fbc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C5FBCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910F4013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1703 | PC: 0x0c6268..0x0c62a4 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c6268: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0c626c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c6270: 910043FD  add      x29, sp, #0x10
//   0x0c6274: AA0003F3  mov      x19, x0
//   0x0c6278: 9106A000  add      x0, x0, #0x1a8
//   0x0c627c: 94001CF6  bl       #0xcd654
uint64_t fde_func_1703_0x0c6268(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C6268ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9106A000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94001CF6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9106C268ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB00011FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1708 | PC: 0x0c72bc..0x0c732c (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c72bc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c72c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c72c4: 910043FD  add      x29, sp, #0x10
//   0x0c72c8: AA0003F3  mov      x19, x0
//   0x0c72cc: 52800400  mov      w0, #0x20
//   0x0c72d0: AA0103F4  mov      x20, x1
uint64_t fde_func_1708_0x0c72bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C72BCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800400ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FDF37FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900001FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1712 | PC: 0x0c9b58..0x0c9b9c (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0c9b58: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0c9b5c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c9b60: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c9b64: 910083FD  add      x29, sp, #0x20
//   0x0c9b68: 91242015  add      x21, x0, #0x908
//   0x0c9b6c: AA0003F4  mov      x20, x0
uint64_t fde_func_1712_0x0c9b58(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000C9B58ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91242015ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1503E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1717 | PC: 0x0ca22c..0x0ca32c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ca22c: D10203FF  sub      sp, sp, #0x80
//   0x0ca230: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0ca234: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0ca238: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x0ca23c: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x0ca240: 9101C3FD  add      x29, sp, #0x70
uint64_t fde_func_1717_0x0ca22c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000CA22CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9077BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1721 | PC: 0x0ca68c..0x0ca78c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ca68c: D10203FF  sub      sp, sp, #0x80
//   0x0ca690: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0ca694: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0ca698: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0ca69c: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0ca6a0: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_1721_0x0ca68c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000CA68CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9026FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90367FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9077BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C3FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1726 | PC: 0x0caabc..0x0cab3c (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0caabc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0caac0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0caac4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0caac8: 910083FD  add      x29, sp, #0x20
//   0x0caacc: 911B4013  add      x19, x0, #0x6d0
//   0x0caad0: AA0003F5  mov      x21, x0
uint64_t fde_func_1726_0x0caabc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000CAABCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911B4013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1730 | PC: 0x0cad74..0x0cae50 (220 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0cad74: D10143FF  sub      sp, sp, #0x50
//   0x0cad78: F90013F5  str      x21, [sp, #0x20]
//   0x0cad7c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0cad80: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0cad84: 910103FD  add      x29, sp, #0x40
//   0x0cad88: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_1730_0x0cad74(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000CAD74ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91114014ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1735 | PC: 0x0cb044..0x0cb144 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0cb044: D10303FF  sub      sp, sp, #0xc0
//   0x0cb048: FD003BE8  str      d8, [sp, #0x70]
//   0x0cb04c: F9003FF9  str      x25, [sp, #0x78]
//   0x0cb050: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x0cb054: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x0cb058: A90A4FF4  stp      x20, x19, [sp, #0xa0]
uint64_t fde_func_1735_0x0cb044(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000CB044ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10303FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD003BE8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9003FF9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9085FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90957F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B7BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102C3FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1739 | PC: 0x0cb784..0x0cb78c (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0cb784: 93407C40  sxtw     x0, w2
//   0x0cb788: D65F03C0  ret      
uint64_t fde_func_1739_0x0cb784(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000CB784ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x93407C40ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1744 | PC: 0x0cb864..0x0cb86c (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0cb864: D1004000  sub      x0, x0, #0x10
//   0x0cb868: 17FFFFCD  b        #0xcb79c
uint64_t fde_func_1744_0x0cb864(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000CB864ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1004000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFCDULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1748 | PC: 0x0cb9f4..0x0cbadc (232 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0cb9f4: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0cb9f8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0cb9fc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0cba00: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0cba04: 9100C3FD  add      x29, sp, #0x30
//   0x0cba08: F9400416  ldr      x22, [x0, #8]
uint64_t fde_func_1748_0x0cb9f4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000CB9F4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81C0FF7ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400416ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1753 | PC: 0x0cbdf4..0x0cbe44 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0cbdf4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0cbdf8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cbdfc: 910043FD  add      x29, sp, #0x10
//   0x0cbe00: A940A014  ldp      x20, x8, [x0, #8]
//   0x0cbe04: AA0003F3  mov      x19, x0
//   0x0cbe08: EB14011F  cmp      x8, x20
uint64_t fde_func_1753_0x0cbdf4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000CBDF4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940A014ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB14011FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000C0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1004100ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1757 | PC: 0x0cbffc..0x0cc0fc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0cbffc: D101C3FF  sub      sp, sp, #0x70
//   0x0cc000: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x0cc004: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0cc008: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0cc00c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0cc010: A9054FF4  stp      x20, x19, [sp, #0x50]
uint64_t fde_func_1757_0x0cbffc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000CBFFCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9016FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90267FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1761 | PC: 0x0ccdb4..0x0cce34 (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ccdb4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0ccdb8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ccdbc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ccdc0: 910083FD  add      x29, sp, #0x20
//   0x0ccdc4: AA0203F3  mov      x19, x2
//   0x0ccdc8: EB02003F  cmp      x1, x2
uint64_t fde_func_1761_0x0ccdb4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000CCDB4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB02003FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540002A0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400268ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1766 | PC: 0x0cd138..0x0cd18c (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0cd138: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0cd13c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cd140: 910043FD  add      x29, sp, #0x10
//   0x0cd144: A9007C7F  stp      xzr, xzr, [x3]
//   0x0cd148: F9000861  str      x1, [x3, #0x10]
//   0x0cd14c: F9000043  str      x3, [x2]
uint64_t fde_func_1766_0x0cd138(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000CD138ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007C7FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000861ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000043ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1770 | PC: 0x0cd340..0x0cd3e0 (160 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0cd340: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0cd344: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0cd348: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0cd34c: 910083FD  add      x29, sp, #0x20
//   0x0cd350: EB02003F  cmp      x1, x2
//   0x0cd354: 540003E0  b.eq     #0xcd3d0
uint64_t fde_func_1770_0x0cd340(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000CD340ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB02003FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540003E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1775 | PC: 0x0cd760..0x0cd860 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0cd760: D10383FF  sub      sp, sp, #0xe0
//   0x0cd764: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x0cd768: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x0cd76c: A90A5FF8  stp      x24, x23, [sp, #0xa0]
//   0x0cd770: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x0cd774: A90C4FF4  stp      x20, x19, [sp, #0xc0]
uint64_t fde_func_1775_0x0cd760(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000CD760ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10383FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9086FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90967FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A5FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B57F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D7BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910343FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1779 | PC: 0x0cdbb0..0x0cdcb0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0cdbb0: D10283FF  sub      sp, sp, #0xa0
//   0x0cdbb4: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x0cdbb8: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0cdbbc: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x0cdbc0: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0cdbc4: A9084FF4  stp      x20, x19, [sp, #0x80]
uint64_t fde_func_1779_0x0cdbb0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000CDBB0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9046FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90567FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9065FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90757F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9084FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9097BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910243FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1784 | PC: 0x0ce0d8..0x0ce1c4 (236 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ce0d8: D10183FF  sub      sp, sp, #0x60
//   0x0ce0dc: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0ce0e0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0ce0e4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0ce0e8: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0ce0ec: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_1784_0x0ce0d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000CE0D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD05AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

uint64_t execute_fde_shard_1(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 0: return fde_func_0000_0x045120(a0, a1);
        case 4: return fde_func_0004_0x045228(a0, a1);
        case 8: return fde_func_0008_0x045854(a0, a1);
        case 13: return fde_func_0013_0x045dbc(a0, a1);
        case 17: return fde_func_0017_0x0461b4(a0, a1);
        case 22: return fde_func_0022_0x04686c(a0, a1);
        case 26: return fde_func_0026_0x046a04(a0, a1);
        case 31: return fde_func_0031_0x046b60(a0, a1);
        case 35: return fde_func_0035_0x046c90(a0, a1);
        case 40: return fde_func_0040_0x046dac(a0, a1);
        case 44: return fde_func_0044_0x046f70(a0, a1);
        case 49: return fde_func_0049_0x047200(a0, a1);
        case 53: return fde_func_0053_0x047224(a0, a1);
        case 58: return fde_func_0058_0x04764c(a0, a1);
        case 62: return fde_func_0062_0x0479f8(a0, a1);
        case 67: return fde_func_0067_0x047c88(a0, a1);
        case 71: return fde_func_0071_0x047e5c(a0, a1);
        case 76: return fde_func_0076_0x0484ec(a0, a1);
        case 80: return fde_func_0080_0x04879c(a0, a1);
        case 84: return fde_func_0084_0x048c68(a0, a1);
        case 89: return fde_func_0089_0x048e28(a0, a1);
        case 93: return fde_func_0093_0x049084(a0, a1);
        case 98: return fde_func_0098_0x0491c4(a0, a1);
        case 102: return fde_func_0102_0x049334(a0, a1);
        case 107: return fde_func_0107_0x049474(a0, a1);
        case 111: return fde_func_0111_0x049594(a0, a1);
        case 116: return fde_func_0116_0x0495f0(a0, a1);
        case 120: return fde_func_0120_0x049678(a0, a1);
        case 125: return fde_func_0125_0x0497c8(a0, a1);
        case 129: return fde_func_0129_0x049a20(a0, a1);
        case 134: return fde_func_0134_0x049d34(a0, a1);
        case 138: return fde_func_0138_0x049f6c(a0, a1);
        case 143: return fde_func_0143_0x04a04c(a0, a1);
        case 147: return fde_func_0147_0x04a08c(a0, a1);
        case 152: return fde_func_0152_0x04a47c(a0, a1);
        case 156: return fde_func_0156_0x04a6dc(a0, a1);
        case 160: return fde_func_0160_0x04a910(a0, a1);
        case 165: return fde_func_0165_0x04ad0c(a0, a1);
        case 169: return fde_func_0169_0x04ae68(a0, a1);
        case 174: return fde_func_0174_0x04b018(a0, a1);
        case 178: return fde_func_0178_0x04b194(a0, a1);
        case 183: return fde_func_0183_0x04b220(a0, a1);
        case 187: return fde_func_0187_0x04b884(a0, a1);
        case 192: return fde_func_0192_0x04b994(a0, a1);
        case 196: return fde_func_0196_0x04b9ec(a0, a1);
        case 201: return fde_func_0201_0x04ba70(a0, a1);
        case 205: return fde_func_0205_0x04bc70(a0, a1);
        case 210: return fde_func_0210_0x04c018(a0, a1);
        case 214: return fde_func_0214_0x04c12c(a0, a1);
        case 219: return fde_func_0219_0x04c1ec(a0, a1);
        case 223: return fde_func_0223_0x04c490(a0, a1);
        case 228: return fde_func_0228_0x04c954(a0, a1);
        case 232: return fde_func_0232_0x04cc54(a0, a1);
        case 237: return fde_func_0237_0x04cf04(a0, a1);
        case 241: return fde_func_0241_0x04d0fc(a0, a1);
        case 245: return fde_func_0245_0x04d798(a0, a1);
        case 250: return fde_func_0250_0x04de9c(a0, a1);
        case 254: return fde_func_0254_0x04df2c(a0, a1);
        case 259: return fde_func_0259_0x04df94(a0, a1);
        case 263: return fde_func_0263_0x04e014(a0, a1);
        case 268: return fde_func_0268_0x04e204(a0, a1);
        case 272: return fde_func_0272_0x04e278(a0, a1);
        case 277: return fde_func_0277_0x04e484(a0, a1);
        case 281: return fde_func_0281_0x04e638(a0, a1);
        case 286: return fde_func_0286_0x04ec94(a0, a1);
        case 290: return fde_func_0290_0x04f034(a0, a1);
        case 295: return fde_func_0295_0x04f090(a0, a1);
        case 299: return fde_func_0299_0x04f0c8(a0, a1);
        case 304: return fde_func_0304_0x04f17c(a0, a1);
        case 308: return fde_func_0308_0x04f5cc(a0, a1);
        case 313: return fde_func_0313_0x04fcb4(a0, a1);
        case 317: return fde_func_0317_0x04ff40(a0, a1);
        case 321: return fde_func_0321_0x0502b4(a0, a1);
        case 326: return fde_func_0326_0x050a30(a0, a1);
        case 330: return fde_func_0330_0x051378(a0, a1);
        case 335: return fde_func_0335_0x051aa0(a0, a1);
        case 339: return fde_func_0339_0x0520a0(a0, a1);
        case 344: return fde_func_0344_0x052e3c(a0, a1);
        case 348: return fde_func_0348_0x053b14(a0, a1);
        case 353: return fde_func_0353_0x0545d8(a0, a1);
        case 357: return fde_func_0357_0x054b28(a0, a1);
        case 362: return fde_func_0362_0x055150(a0, a1);
        case 366: return fde_func_0366_0x0558ec(a0, a1);
        case 371: return fde_func_0371_0x055b00(a0, a1);
        case 375: return fde_func_0375_0x055dd4(a0, a1);
        case 380: return fde_func_0380_0x055fcc(a0, a1);
        case 384: return fde_func_0384_0x0560e0(a0, a1);
        case 389: return fde_func_0389_0x05628c(a0, a1);
        case 393: return fde_func_0393_0x05666c(a0, a1);
        case 398: return fde_func_0398_0x056750(a0, a1);
        case 402: return fde_func_0402_0x056818(a0, a1);
        case 406: return fde_func_0406_0x056af4(a0, a1);
        case 411: return fde_func_0411_0x056ea8(a0, a1);
        case 415: return fde_func_0415_0x056f50(a0, a1);
        case 420: return fde_func_0420_0x057268(a0, a1);
        case 424: return fde_func_0424_0x057a08(a0, a1);
        case 429: return fde_func_0429_0x058a90(a0, a1);
        case 433: return fde_func_0433_0x058fb0(a0, a1);
        case 438: return fde_func_0438_0x05a178(a0, a1);
        case 442: return fde_func_0442_0x05a7ec(a0, a1);
        case 447: return fde_func_0447_0x05ac44(a0, a1);
        case 451: return fde_func_0451_0x05bbd8(a0, a1);
        case 456: return fde_func_0456_0x05ce8c(a0, a1);
        case 460: return fde_func_0460_0x05d290(a0, a1);
        case 465: return fde_func_0465_0x05dd0c(a0, a1);
        case 469: return fde_func_0469_0x05e1b8(a0, a1);
        case 474: return fde_func_0474_0x05edbc(a0, a1);
        case 478: return fde_func_0478_0x05eea4(a0, a1);
        case 482: return fde_func_0482_0x05f01c(a0, a1);
        case 487: return fde_func_0487_0x05f1b0(a0, a1);
        case 491: return fde_func_0491_0x05f2b4(a0, a1);
        case 496: return fde_func_0496_0x05f408(a0, a1);
        case 500: return fde_func_0500_0x05f4cc(a0, a1);
        case 505: return fde_func_0505_0x05f648(a0, a1);
        case 509: return fde_func_0509_0x05f790(a0, a1);
        case 514: return fde_func_0514_0x05f7f4(a0, a1);
        case 518: return fde_func_0518_0x05f828(a0, a1);
        case 523: return fde_func_0523_0x05f900(a0, a1);
        case 527: return fde_func_0527_0x05fadc(a0, a1);
        case 532: return fde_func_0532_0x05fcd8(a0, a1);
        case 536: return fde_func_0536_0x05ff04(a0, a1);
        case 541: return fde_func_0541_0x0601a0(a0, a1);
        case 545: return fde_func_0545_0x0606ec(a0, a1);
        case 550: return fde_func_0550_0x0609f8(a0, a1);
        case 554: return fde_func_0554_0x060cc0(a0, a1);
        case 559: return fde_func_0559_0x060de4(a0, a1);
        case 563: return fde_func_0563_0x061130(a0, a1);
        case 567: return fde_func_0567_0x06130c(a0, a1);
        case 572: return fde_func_0572_0x061910(a0, a1);
        case 576: return fde_func_0576_0x061c84(a0, a1);
        case 581: return fde_func_0581_0x061d4c(a0, a1);
        case 585: return fde_func_0585_0x062174(a0, a1);
        case 590: return fde_func_0590_0x0626f8(a0, a1);
        case 594: return fde_func_0594_0x062968(a0, a1);
        case 599: return fde_func_0599_0x062ad4(a0, a1);
        case 603: return fde_func_0603_0x062d60(a0, a1);
        case 608: return fde_func_0608_0x063468(a0, a1);
        case 612: return fde_func_0612_0x063514(a0, a1);
        case 617: return fde_func_0617_0x063604(a0, a1);
        case 621: return fde_func_0621_0x063850(a0, a1);
        case 626: return fde_func_0626_0x06395c(a0, a1);
        case 630: return fde_func_0630_0x063adc(a0, a1);
        case 635: return fde_func_0635_0x063c00(a0, a1);
        case 639: return fde_func_0639_0x063d18(a0, a1);
        case 643: return fde_func_0643_0x063dcc(a0, a1);
        case 648: return fde_func_0648_0x064020(a0, a1);
        case 652: return fde_func_0652_0x0640a8(a0, a1);
        case 657: return fde_func_0657_0x0641cc(a0, a1);
        case 661: return fde_func_0661_0x064364(a0, a1);
        case 666: return fde_func_0666_0x064460(a0, a1);
        case 670: return fde_func_0670_0x0644fc(a0, a1);
        case 675: return fde_func_0675_0x0645d8(a0, a1);
        case 679: return fde_func_0679_0x06477c(a0, a1);
        case 684: return fde_func_0684_0x064870(a0, a1);
        case 688: return fde_func_0688_0x064a08(a0, a1);
        case 693: return fde_func_0693_0x064ad8(a0, a1);
        case 697: return fde_func_0697_0x064b20(a0, a1);
        case 702: return fde_func_0702_0x064e14(a0, a1);
        case 706: return fde_func_0706_0x064e80(a0, a1);
        case 711: return fde_func_0711_0x065088(a0, a1);
        case 715: return fde_func_0715_0x06510c(a0, a1);
        case 719: return fde_func_0719_0x065250(a0, a1);
        case 724: return fde_func_0724_0x0653f4(a0, a1);
        case 728: return fde_func_0728_0x06551c(a0, a1);
        case 733: return fde_func_0733_0x065830(a0, a1);
        case 737: return fde_func_0737_0x065a48(a0, a1);
        case 742: return fde_func_0742_0x065cb0(a0, a1);
        case 746: return fde_func_0746_0x0660b4(a0, a1);
        case 751: return fde_func_0751_0x066198(a0, a1);
        case 755: return fde_func_0755_0x06624c(a0, a1);
        case 760: return fde_func_0760_0x066330(a0, a1);
        case 764: return fde_func_0764_0x06649c(a0, a1);
        case 769: return fde_func_0769_0x0664ec(a0, a1);
        case 773: return fde_func_0773_0x06652c(a0, a1);
        case 778: return fde_func_0778_0x066578(a0, a1);
        case 782: return fde_func_0782_0x06660c(a0, a1);
        case 787: return fde_func_0787_0x06665c(a0, a1);
        case 791: return fde_func_0791_0x066718(a0, a1);
        case 796: return fde_func_0796_0x0669dc(a0, a1);
        case 800: return fde_func_0800_0x066c2c(a0, a1);
        case 804: return fde_func_0804_0x066e58(a0, a1);
        case 809: return fde_func_0809_0x0673a4(a0, a1);
        case 813: return fde_func_0813_0x067cd4(a0, a1);
        case 818: return fde_func_0818_0x0682a8(a0, a1);
        case 822: return fde_func_0822_0x068358(a0, a1);
        case 827: return fde_func_0827_0x06878c(a0, a1);
        case 831: return fde_func_0831_0x068880(a0, a1);
        case 836: return fde_func_0836_0x069374(a0, a1);
        case 840: return fde_func_0840_0x069cc0(a0, a1);
        case 845: return fde_func_0845_0x06a070(a0, a1);
        case 849: return fde_func_0849_0x06a264(a0, a1);
        case 854: return fde_func_0854_0x06a794(a0, a1);
        case 858: return fde_func_0858_0x06a950(a0, a1);
        case 863: return fde_func_0863_0x06aa10(a0, a1);
        case 867: return fde_func_0867_0x06aac4(a0, a1);
        case 872: return fde_func_0872_0x06ad18(a0, a1);
        case 876: return fde_func_0876_0x06b868(a0, a1);
        case 880: return fde_func_0880_0x06d594(a0, a1);
        case 885: return fde_func_0885_0x06f8f4(a0, a1);
        case 889: return fde_func_0889_0x06fac4(a0, a1);
        case 894: return fde_func_0894_0x06fc28(a0, a1);
        case 898: return fde_func_0898_0x06fc70(a0, a1);
        case 903: return fde_func_0903_0x06fdb4(a0, a1);
        case 907: return fde_func_0907_0x06fefc(a0, a1);
        case 912: return fde_func_0912_0x0701e8(a0, a1);
        case 916: return fde_func_0916_0x070470(a0, a1);
        case 921: return fde_func_0921_0x070808(a0, a1);
        case 925: return fde_func_0925_0x070b7c(a0, a1);
        case 930: return fde_func_0930_0x070f2c(a0, a1);
        case 934: return fde_func_0934_0x0711fc(a0, a1);
        case 939: return fde_func_0939_0x071744(a0, a1);
        case 943: return fde_func_0943_0x071918(a0, a1);
        case 948: return fde_func_0948_0x071ac4(a0, a1);
        case 952: return fde_func_0952_0x071b90(a0, a1);
        case 957: return fde_func_0957_0x071e48(a0, a1);
        case 961: return fde_func_0961_0x072730(a0, a1);
        case 965: return fde_func_0965_0x0729f0(a0, a1);
        case 970: return fde_func_0970_0x079098(a0, a1);
        case 974: return fde_func_0974_0x07b814(a0, a1);
        case 979: return fde_func_0979_0x07e068(a0, a1);
        case 983: return fde_func_0983_0x082778(a0, a1);
        case 988: return fde_func_0988_0x08356c(a0, a1);
        case 992: return fde_func_0992_0x083c34(a0, a1);
        case 997: return fde_func_0997_0x085470(a0, a1);
        case 1001: return fde_func_1001_0x087564(a0, a1);
        case 1006: return fde_func_1006_0x088f7c(a0, a1);
        case 1010: return fde_func_1010_0x08ac04(a0, a1);
        case 1015: return fde_func_1015_0x091624(a0, a1);
        case 1019: return fde_func_1019_0x092b78(a0, a1);
        case 1024: return fde_func_1024_0x093c28(a0, a1);
        case 1028: return fde_func_1028_0x094604(a0, a1);
        case 1033: return fde_func_1033_0x094ae0(a0, a1);
        case 1037: return fde_func_1037_0x0950d0(a0, a1);
        case 1041: return fde_func_1041_0x095480(a0, a1);
        case 1046: return fde_func_1046_0x095760(a0, a1);
        case 1050: return fde_func_1050_0x095cf8(a0, a1);
        case 1055: return fde_func_1055_0x096410(a0, a1);
        case 1059: return fde_func_1059_0x096630(a0, a1);
        case 1064: return fde_func_1064_0x09678c(a0, a1);
        case 1068: return fde_func_1068_0x096a38(a0, a1);
        case 1073: return fde_func_1073_0x096db8(a0, a1);
        case 1077: return fde_func_1077_0x096f3c(a0, a1);
        case 1082: return fde_func_1082_0x0970a0(a0, a1);
        case 1086: return fde_func_1086_0x097298(a0, a1);
        case 1091: return fde_func_1091_0x097518(a0, a1);
        case 1095: return fde_func_1095_0x097798(a0, a1);
        case 1100: return fde_func_1100_0x097af0(a0, a1);
        case 1104: return fde_func_1104_0x097d6c(a0, a1);
        case 1109: return fde_func_1109_0x097e1c(a0, a1);
        case 1113: return fde_func_1113_0x0980a8(a0, a1);
        case 1118: return fde_func_1118_0x0981dc(a0, a1);
        case 1122: return fde_func_1122_0x09c634(a0, a1);
        case 1126: return fde_func_1126_0x09c8d8(a0, a1);
        case 1131: return fde_func_1131_0x09ce24(a0, a1);
        case 1135: return fde_func_1135_0x09d170(a0, a1);
        case 1140: return fde_func_1140_0x09d540(a0, a1);
        case 1144: return fde_func_1144_0x09d7b0(a0, a1);
        case 1149: return fde_func_1149_0x09db34(a0, a1);
        case 1153: return fde_func_1153_0x09dec0(a0, a1);
        case 1158: return fde_func_1158_0x09e12c(a0, a1);
        case 1162: return fde_func_1162_0x09e4f8(a0, a1);
        case 1167: return fde_func_1167_0x09e748(a0, a1);
        case 1171: return fde_func_1171_0x09e81c(a0, a1);
        case 1176: return fde_func_1176_0x09eb24(a0, a1);
        case 1180: return fde_func_1180_0x09f084(a0, a1);
        case 1185: return fde_func_1185_0x09f944(a0, a1);
        case 1189: return fde_func_1189_0x0a0568(a0, a1);
        case 1194: return fde_func_1194_0x0a08ec(a0, a1);
        case 1198: return fde_func_1198_0x0a0960(a0, a1);
        case 1202: return fde_func_1202_0x0a0a90(a0, a1);
        case 1207: return fde_func_1207_0x0a0d88(a0, a1);
        case 1211: return fde_func_1211_0x0a2098(a0, a1);
        case 1216: return fde_func_1216_0x0a4140(a0, a1);
        case 1220: return fde_func_1220_0x0a4824(a0, a1);
        case 1225: return fde_func_1225_0x0a6990(a0, a1);
        case 1229: return fde_func_1229_0x0a700c(a0, a1);
        case 1234: return fde_func_1234_0x0a72a8(a0, a1);
        case 1238: return fde_func_1238_0x0a760c(a0, a1);
        case 1243: return fde_func_1243_0x0a777c(a0, a1);
        case 1247: return fde_func_1247_0x0a788c(a0, a1);
        case 1252: return fde_func_1252_0x0a7abc(a0, a1);
        case 1256: return fde_func_1256_0x0a7cfc(a0, a1);
        case 1261: return fde_func_1261_0x0a8814(a0, a1);
        case 1265: return fde_func_1265_0x0a963c(a0, a1);
        case 1270: return fde_func_1270_0x0a9c74(a0, a1);
        case 1274: return fde_func_1274_0x0a9d2c(a0, a1);
        case 1278: return fde_func_1278_0x0a9d5c(a0, a1);
        case 1283: return fde_func_1283_0x0a9dc0(a0, a1);
        case 1287: return fde_func_1287_0x0a9de4(a0, a1);
        case 1292: return fde_func_1292_0x0aa000(a0, a1);
        case 1296: return fde_func_1296_0x0aa030(a0, a1);
        case 1301: return fde_func_1301_0x0aa834(a0, a1);
        case 1305: return fde_func_1305_0x0aaf1c(a0, a1);
        case 1310: return fde_func_1310_0x0ab2dc(a0, a1);
        case 1314: return fde_func_1314_0x0ab37c(a0, a1);
        case 1319: return fde_func_1319_0x0ab468(a0, a1);
        case 1323: return fde_func_1323_0x0ab6cc(a0, a1);
        case 1328: return fde_func_1328_0x0aba08(a0, a1);
        case 1332: return fde_func_1332_0x0abb48(a0, a1);
        case 1337: return fde_func_1337_0x0abcb4(a0, a1);
        case 1341: return fde_func_1341_0x0abd80(a0, a1);
        case 1346: return fde_func_1346_0x0abf24(a0, a1);
        case 1350: return fde_func_1350_0x0ac018(a0, a1);
        case 1355: return fde_func_1355_0x0ac170(a0, a1);
        case 1359: return fde_func_1359_0x0ac200(a0, a1);
        case 1363: return fde_func_1363_0x0ac338(a0, a1);
        case 1368: return fde_func_1368_0x0ac3dc(a0, a1);
        case 1372: return fde_func_1372_0x0ac514(a0, a1);
        case 1377: return fde_func_1377_0x0ac5bc(a0, a1);
        case 1381: return fde_func_1381_0x0ac6f8(a0, a1);
        case 1386: return fde_func_1386_0x0ac7a8(a0, a1);
        case 1390: return fde_func_1390_0x0ac8e4(a0, a1);
        case 1395: return fde_func_1395_0x0ac994(a0, a1);
        case 1399: return fde_func_1399_0x0acad0(a0, a1);
        case 1404: return fde_func_1404_0x0adcec(a0, a1);
        case 1408: return fde_func_1408_0x0ae6a0(a0, a1);
        case 1413: return fde_func_1413_0x0b0e80(a0, a1);
        case 1417: return fde_func_1417_0x0b2bb4(a0, a1);
        case 1422: return fde_func_1422_0x0b33a4(a0, a1);
        case 1426: return fde_func_1426_0x0b35b8(a0, a1);
        case 1431: return fde_func_1431_0x0b38b4(a0, a1);
        case 1435: return fde_func_1435_0x0b39a8(a0, a1);
        case 1439: return fde_func_1439_0x0b3ae8(a0, a1);
        case 1444: return fde_func_1444_0x0b3d9c(a0, a1);
        case 1448: return fde_func_1448_0x0b3ed8(a0, a1);
        case 1453: return fde_func_1453_0x0b4174(a0, a1);
        case 1457: return fde_func_1457_0x0b4428(a0, a1);
        case 1462: return fde_func_1462_0x0b68ac(a0, a1);
        case 1466: return fde_func_1466_0x0b6c30(a0, a1);
        case 1471: return fde_func_1471_0x0b6cb8(a0, a1);
        case 1475: return fde_func_1475_0x0b6d30(a0, a1);
        case 1480: return fde_func_1480_0x0b8684(a0, a1);
        case 1484: return fde_func_1484_0x0ba2ec(a0, a1);
        case 1489: return fde_func_1489_0x0bb42c(a0, a1);
        case 1493: return fde_func_1493_0x0bbf00(a0, a1);
        case 1498: return fde_func_1498_0x0bd40c(a0, a1);
        case 1502: return fde_func_1502_0x0be0fc(a0, a1);
        case 1507: return fde_func_1507_0x0be904(a0, a1);
        case 1511: return fde_func_1511_0x0befb8(a0, a1);
        case 1516: return fde_func_1516_0x0bf218(a0, a1);
        case 1520: return fde_func_1520_0x0bf444(a0, a1);
        case 1524: return fde_func_1524_0x0bf7c8(a0, a1);
        case 1529: return fde_func_1529_0x0bfa8c(a0, a1);
        case 1533: return fde_func_1533_0x0bfabc(a0, a1);
        case 1538: return fde_func_1538_0x0bfc38(a0, a1);
        case 1542: return fde_func_1542_0x0bfeb0(a0, a1);
        case 1547: return fde_func_1547_0x0c0300(a0, a1);
        case 1551: return fde_func_1551_0x0c03a4(a0, a1);
        case 1556: return fde_func_1556_0x0c04ec(a0, a1);
        case 1560: return fde_func_1560_0x0c06e4(a0, a1);
        case 1565: return fde_func_1565_0x0c0888(a0, a1);
        case 1569: return fde_func_1569_0x0c0ba4(a0, a1);
        case 1574: return fde_func_1574_0x0c0de4(a0, a1);
        case 1578: return fde_func_1578_0x0c102c(a0, a1);
        case 1583: return fde_func_1583_0x0c139c(a0, a1);
        case 1587: return fde_func_1587_0x0c1628(a0, a1);
        case 1592: return fde_func_1592_0x0c1d0c(a0, a1);
        case 1596: return fde_func_1596_0x0c1f10(a0, a1);
        case 1600: return fde_func_1600_0x0c21b0(a0, a1);
        case 1605: return fde_func_1605_0x0c22bc(a0, a1);
        case 1609: return fde_func_1609_0x0c2334(a0, a1);
        case 1614: return fde_func_1614_0x0c2550(a0, a1);
        case 1618: return fde_func_1618_0x0c25c8(a0, a1);
        case 1623: return fde_func_1623_0x0c26e8(a0, a1);
        case 1627: return fde_func_1627_0x0c27f0(a0, a1);
        case 1632: return fde_func_1632_0x0c2900(a0, a1);
        case 1636: return fde_func_1636_0x0c2978(a0, a1);
        case 1641: return fde_func_1641_0x0c2d14(a0, a1);
        case 1645: return fde_func_1645_0x0c3220(a0, a1);
        case 1650: return fde_func_1650_0x0c3774(a0, a1);
        case 1654: return fde_func_1654_0x0c3820(a0, a1);
        case 1659: return fde_func_1659_0x0c4048(a0, a1);
        case 1663: return fde_func_1663_0x0c4580(a0, a1);
        case 1668: return fde_func_1668_0x0c4988(a0, a1);
        case 1672: return fde_func_1672_0x0c4cc8(a0, a1);
        case 1677: return fde_func_1677_0x0c4e5c(a0, a1);
        case 1681: return fde_func_1681_0x0c5490(a0, a1);
        case 1685: return fde_func_1685_0x0c572c(a0, a1);
        case 1690: return fde_func_1690_0x0c5c6c(a0, a1);
        case 1694: return fde_func_1694_0x0c5e04(a0, a1);
        case 1699: return fde_func_1699_0x0c5fbc(a0, a1);
        case 1703: return fde_func_1703_0x0c6268(a0, a1);
        case 1708: return fde_func_1708_0x0c72bc(a0, a1);
        case 1712: return fde_func_1712_0x0c9b58(a0, a1);
        case 1717: return fde_func_1717_0x0ca22c(a0, a1);
        case 1721: return fde_func_1721_0x0ca68c(a0, a1);
        case 1726: return fde_func_1726_0x0caabc(a0, a1);
        case 1730: return fde_func_1730_0x0cad74(a0, a1);
        case 1735: return fde_func_1735_0x0cb044(a0, a1);
        case 1739: return fde_func_1739_0x0cb784(a0, a1);
        case 1744: return fde_func_1744_0x0cb864(a0, a1);
        case 1748: return fde_func_1748_0x0cb9f4(a0, a1);
        case 1753: return fde_func_1753_0x0cbdf4(a0, a1);
        case 1757: return fde_func_1757_0x0cbffc(a0, a1);
        case 1761: return fde_func_1761_0x0ccdb4(a0, a1);
        case 1766: return fde_func_1766_0x0cd138(a0, a1);
        case 1770: return fde_func_1770_0x0cd340(a0, a1);
        case 1775: return fde_func_1775_0x0cd760(a0, a1);
        case 1779: return fde_func_1779_0x0cdbb0(a0, a1);
        case 1784: return fde_func_1784_0x0ce0d8(a0, a1);
        default: return 0ULL;
    }
}

} // namespace preload_reconstructed