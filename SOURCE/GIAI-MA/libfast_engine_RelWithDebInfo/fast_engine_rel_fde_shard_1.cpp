// ============================================================================
// Clean-Room C++17 AArch64 FDE Shard 1/5 for libfast_engine_RelWithDebInfo.so
// Phân mảnh FDE AArch64 C++17 sạch 1/5 cho libfast_engine_RelWithDebInfo.so
// Covers FDE indices [0 .. 416] out of 2,082 total FDEs (.eh_frame_hdr @ 0x1127c8)
// Bao phủ chỉ số FDE [0 .. 416] trên tổng số 2,082 FDE (.eh_frame_hdr @ 0x1127c8)
// ============================================================================
#include "fast_engine_rel_core.h"

namespace fast_engine {

// FDE #0000 | PC: 0x045cbc | FDE: 0x116900 | Size: 24 bytes [_ZN11fast_engine14InitializeImplEv]
// Hàm FDE #0000 | Địa chỉ PC: 0x045cbc | Địa chỉ FDE: 0x116900 | Kích thước: 24 bytes
//   0x045cbc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x045cc0: 910003FD  mov      x29, sp
//   0x045cc4: 97FFF347  bl       #0x429e0
//   0x045cc8: 52800020  mov      w0, #1
static inline uint64_t fde_func_0000_0x045cbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x045cbcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x116900ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0001 | PC: 0x045cd4 | FDE: 0x116bd0 | Size: 168 bytes [_ZN11fast_engine10FastEngine8InstanceEv]
// Hàm FDE #0001 | Địa chỉ PC: 0x045cd4 | Địa chỉ FDE: 0x116bd0 | Kích thước: 168 bytes
//   0x045cd4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x045cd8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x045cdc: 910043FD  add      x29, sp, #0x10
//   0x045ce0: D00007E8  adrp     x8, #0x143000
static inline uint64_t fde_func_0001_0x045cd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x045cd4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x116bd0ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #0002 | PC: 0x045d7c | FDE: 0x116920 | Size: 128 bytes [_ZN11fast_engine10FastEngine10InitializeERKNS_16FastEngineConfigE]
// Hàm FDE #0002 | Địa chỉ PC: 0x045d7c | Địa chỉ FDE: 0x116920 | Kích thước: 128 bytes
//   0x045d7c: D10143FF  sub      sp, sp, #0x50
//   0x045d80: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x045d84: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x045d88: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0002_0x045d7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x045d7cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x116920ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0003 | PC: 0x045dfc | FDE: 0x116bf8 | Size: 256 bytes [_ZN11fast_engine21BuildConfigByProviderEPNS_24FastEngineConfigProviderERNS_16FastEngineConfigE]
// Hàm FDE #0003 | Địa chỉ PC: 0x045dfc | Địa chỉ FDE: 0x116bf8 | Kích thước: 256 bytes
//   0x045dfc: D10143FF  sub      sp, sp, #0x50
//   0x045e00: F90013F5  str      x21, [sp, #0x20]
//   0x045e04: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x045e08: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0003_0x045dfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x045dfcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x116bf8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0004 | PC: 0x046100 | FDE: 0x116940 | Size: 152 bytes [_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2IDnEEPKc]
// Hàm FDE #0004 | Địa chỉ PC: 0x046100 | Địa chỉ FDE: 0x116940 | Kích thước: 152 bytes
//   0x046100: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x046104: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x046108: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x04610c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0004_0x046100(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x046100ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x116940ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0005 | PC: 0x046198 | FDE: 0x116968 | Size: 136 bytes [_ZN11fast_engine10FastEngine10InitializeEPNS_24FastEngineConfigProviderE]
// Hàm FDE #0005 | Địa chỉ PC: 0x046198 | Địa chỉ FDE: 0x116968 | Kích thước: 136 bytes
//   0x046198: D10143FF  sub      sp, sp, #0x50
//   0x04619c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0461a0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0461a4: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0005_0x046198(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x046198ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x116968ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #0006 | PC: 0x046220 | FDE: 0x116988 | Size: 16 bytes [_ZN11fast_engine10FastEngine11InitializedEv]
// Hàm FDE #0006 | Địa chỉ PC: 0x046220 | Địa chỉ FDE: 0x116988 | Kích thước: 16 bytes
//   0x046220: 91047008  add      x8, x0, #0x11c
//   0x046224: 08DFFD08  ldarb    w8, [x8]
//   0x046228: 12000100  and      w0, w8, #1
//   0x04622c: D65F03C0  ret      
static inline uint64_t fde_func_0006_0x046220(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x046220ULL ^ (static_cast<uint64_t>(0x91047008ULL) << 13);
    acc = (acc + a1 + 0x08dffd08ULL) ^ 0x116988ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0007 | PC: 0x046230 | FDE: 0x116c20 | Size: 252 bytes [_ZN11fast_engine10FastEngine20RegisterInitCallbackENSt6__ndk18functionIFvPNS_6EngineEEEE]
// Hàm FDE #0007 | Địa chỉ PC: 0x046230 | Địa chỉ FDE: 0x116c20 | Kích thước: 252 bytes
//   0x046230: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x046234: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x046238: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x04623c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0007_0x046230(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x046230ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x116c20ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #0008 | PC: 0x04632c | FDE: 0x1169a0 | Size: 104 bytes [_ZNK11fast_engine10FastEngine9HasFreeVMEv]
// Hàm FDE #0008 | Địa chỉ PC: 0x04632c | Địa chỉ FDE: 0x1169a0 | Kích thước: 104 bytes
//   0x04632c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x046330: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x046334: 910043FD  add      x29, sp, #0x10
//   0x046338: 9100C013  add      x19, x0, #0x30
static inline uint64_t fde_func_0008_0x04632c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04632cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1169a0ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0009 | PC: 0x046394 | FDE: 0x116c50 | Size: 256 bytes [_ZN11fast_engine10FastEngine13GetOrCreateVMEv]
// Hàm FDE #0009 | Địa chỉ PC: 0x046394 | Địa chỉ FDE: 0x116c50 | Kích thước: 256 bytes
//   0x046394: D10183FF  sub      sp, sp, #0x60
//   0x046398: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x04639c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0463a0: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0009_0x046394(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x046394ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x116c50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0010 | PC: 0x04653c | FDE: 0x1169c0 | Size: 72 bytes [_ZNK11fast_engine10FastEngine14ReleaseVMUsageEPNS_6EngineE]
// Hàm FDE #0010 | Địa chỉ PC: 0x04653c | Địa chỉ FDE: 0x1169c0 | Kích thước: 72 bytes
//   0x04653c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x046540: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x046544: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x046548: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0010_0x04653c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04653cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1169c0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0011 | PC: 0x046584 | FDE: 0x1169e0 | Size: 96 bytes [_ZN11fast_engine10FastEngine10_AddGlobalERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEPNS_3ObjEPNS_6EngineE]
// Hàm FDE #0011 | Địa chỉ PC: 0x046584 | Địa chỉ FDE: 0x1169e0 | Kích thước: 96 bytes
//   0x046584: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x046588: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04658c: 910043FD  add      x29, sp, #0x10
//   0x046590: B9402048  ldr      w8, [x2, #0x20]
static inline uint64_t fde_func_0011_0x046584(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x046584ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1169e0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0012 | PC: 0x0465e4 | FDE: 0x116a00 | Size: 124 bytes [_ZN11fast_engine10FastEngine9AddGlobalERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEPNS_3ObjE]
// Hàm FDE #0012 | Địa chỉ PC: 0x0465e4 | Địa chỉ FDE: 0x116a00 | Kích thước: 124 bytes
//   0x0465e4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0465e8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0465ec: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0465f0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0012_0x0465e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0465e4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x116a00ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0013 | PC: 0x046660 | FDE: 0x116c80 | Size: 256 bytes [_ZN11fast_engine10FastEngine10_AddModuleEPNS_9ModuleObjEPNS_6EngineERKNSt6__ndk112basic_stringIcNS5_11char_traitsIcEENS5_9allocatorIcEEEE]
// Hàm FDE #0013 | Địa chỉ PC: 0x046660 | Địa chỉ FDE: 0x116c80 | Kích thước: 256 bytes
//   0x046660: D10143FF  sub      sp, sp, #0x50
//   0x046664: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x046668: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x04666c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0013_0x046660(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x046660ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x116c80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0014 | PC: 0x046780 | FDE: 0x116a28 | Size: 172 bytes [_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_]
// Hàm FDE #0014 | Địa chỉ PC: 0x046780 | Địa chỉ FDE: 0x116a28 | Kích thước: 172 bytes
//   0x046780: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x046784: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x046788: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x04678c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0014_0x046780(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x046780ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x116a28ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #0015 | PC: 0x04682c | FDE: 0x116a50 | Size: 64 bytes [_ZN11fast_engine10FastEngine9AddModuleEPNS_9ModuleObjERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEE]
// Hàm FDE #0015 | Địa chỉ PC: 0x04682c | Địa chỉ FDE: 0x116a50 | Kích thước: 64 bytes
//   0x04682c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x046830: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x046834: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x046838: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0015_0x04682c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04682cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x116a50ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0016 | PC: 0x04686c | FDE: 0x116cb0 | Size: 256 bytes [_ZN11fast_engine10FastEngine10_AddCFuncsEPKNS_9MethodDefEPNS_6EngineE]
// Hàm FDE #0016 | Địa chỉ PC: 0x04686c | Địa chỉ FDE: 0x116cb0 | Kích thước: 256 bytes
//   0x04686c: D10183FF  sub      sp, sp, #0x60
//   0x046870: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x046874: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x046878: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0016_0x04686c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04686cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x116cb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0017 | PC: 0x0469f4 | FDE: 0x116a70 | Size: 48 bytes [_ZN11fast_engine10FastEngine9AddCFuncsEPKNS_9MethodDefE]
// Hàm FDE #0017 | Địa chỉ PC: 0x0469f4 | Địa chỉ FDE: 0x116a70 | Kích thước: 48 bytes
//   0x0469f4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0469f8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0469fc: 910043FD  add      x29, sp, #0x10
//   0x046a00: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0017_0x0469f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0469f4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x116a70ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0018 | PC: 0x046a24 | FDE: 0x116ce0 | Size: 240 bytes [_ZN11fast_engine10FastEngine8_AddTypeEPNS_7TypeObjEPNS_6EngineERKNSt6__ndk112basic_stringIcNS5_11char_traitsIcEENS5_9allocatorIcEEEE]
// Hàm FDE #0018 | Địa chỉ PC: 0x046a24 | Địa chỉ FDE: 0x116ce0 | Kích thước: 240 bytes
//   0x046a24: D10143FF  sub      sp, sp, #0x50
//   0x046a28: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x046a2c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x046a30: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0018_0x046a24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x046a24ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x116ce0ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #0019 | PC: 0x046b14 | FDE: 0x116a90 | Size: 64 bytes [_ZN11fast_engine10FastEngine7AddTypeEPNS_7TypeObjERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEE]
// Hàm FDE #0019 | Địa chỉ PC: 0x046b14 | Địa chỉ FDE: 0x116a90 | Kích thước: 64 bytes
//   0x046b14: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x046b18: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x046b1c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x046b20: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0019_0x046b14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x046b14ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x116a90ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0020 | PC: 0x046b54 | FDE: 0x116d10 | Size: 256 bytes [_ZN11fast_engine10FastEngine17EncryptModuleNameERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE]
// Hàm FDE #0020 | Địa chỉ PC: 0x046b54 | Địa chỉ FDE: 0x116d10 | Kích thước: 256 bytes
//   0x046b54: D101C3FF  sub      sp, sp, #0x70
//   0x046b58: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x046b5c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x046b60: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0020_0x046b54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x046b54ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x116d10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0021 | PC: 0x046db0 | FDE: 0x116d48 | Size: 256 bytes [_ZN11fast_engine10FastEngine17DecryptModuleNameERNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE]
// Hàm FDE #0021 | Địa chỉ PC: 0x046db0 | Địa chỉ FDE: 0x116d48 | Kích thước: 256 bytes
//   0x046db0: D101C3FF  sub      sp, sp, #0x70
//   0x046db4: F90013F9  str      x25, [sp, #0x20]
//   0x046db8: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x046dbc: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0021_0x046db0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x046db0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x116d48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0022 | PC: 0x0470dc | FDE: 0x116ab0 | Size: 8 bytes [_ZNK11fast_engine10FastEngine17GetBuiltinVersionEv]
// Hàm FDE #0022 | Địa chỉ PC: 0x0470dc | Địa chỉ FDE: 0x116ab0 | Kích thước: 8 bytes
//   0x0470dc: F9408000  ldr      x0, [x0, #0x100]
//   0x0470e0: D65F03C0  ret      
static inline uint64_t fde_func_0022_0x0470dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0470dcULL ^ (static_cast<uint64_t>(0xf9408000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x116ab0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0023 | PC: 0x0470e4 | FDE: 0x116ac8 | Size: 12 bytes
// Hàm FDE #0023 | Địa chỉ PC: 0x0470e4 | Địa chỉ FDE: 0x116ac8 | Kích thước: 12 bytes
//   0x0470e4: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0470e8: 97FFF5E6  bl       #0x44880
//   0x0470ec: 97FFFA0D  bl       #0x45920
static inline uint64_t fde_func_0023_0x0470e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0470e4ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x97fff5e6ULL) ^ 0x116ac8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0024 | PC: 0x0470f0 | FDE: 0x116d78 | Size: 256 bytes [_ZNSt6__ndk16vectorIN11fast_engine6EngineENS_9allocatorIS2_EEE24__emplace_back_slow_pathIJEEEvDpOT_]
// Hàm FDE #0024 | Địa chỉ PC: 0x0470f0 | Địa chỉ FDE: 0x116d78 | Kích thước: 256 bytes
//   0x0470f0: D10203FF  sub      sp, sp, #0x80
//   0x0470f4: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0470f8: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0470fc: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0024_0x0470f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0470f0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x116d78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0025 | PC: 0x0473c8 | FDE: 0x116ae0 | Size: 20 bytes [_ZNKSt6__ndk120__vector_base_commonILb1EE20__throw_length_errorEv]
// Hàm FDE #0025 | Địa chỉ PC: 0x0473c8 | Địa chỉ FDE: 0x116ae0 | Kích thước: 20 bytes
//   0x0473c8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0473cc: 910003FD  mov      x29, sp
//   0x0473d0: D0000600  adrp     x0, #0x109000
//   0x0473d4: 912D4800  add      x0, x0, #0xb52
static inline uint64_t fde_func_0025_0x0473c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0473c8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x116ae0ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0026 | PC: 0x0473dc | FDE: 0x116db0 | Size: 80 bytes
// Hàm FDE #0026 | Địa chỉ PC: 0x0473dc | Địa chỉ FDE: 0x116db0 | Kích thước: 80 bytes
//   0x0473dc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0473e0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0473e4: 910043FD  add      x29, sp, #0x10
//   0x0473e8: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0026_0x0473dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0473dcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x116db0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0027 | PC: 0x04742c | FDE: 0x116b00 | Size: 48 bytes
// Hàm FDE #0027 | Địa chỉ PC: 0x04742c | Địa chỉ FDE: 0x116b00 | Kích thước: 48 bytes
//   0x04742c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x047430: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x047434: 910043FD  add      x29, sp, #0x10
//   0x047438: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0027_0x04742c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04742cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x116b00ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0028 | PC: 0x04745c | FDE: 0x116dd8 | Size: 188 bytes [_ZNSt6__ndk16vectorIPN11fast_engine9ModuleObjENS_9allocatorIS3_EEEC2ERKS6_]
// Hàm FDE #0028 | Địa chỉ PC: 0x04745c | Địa chỉ FDE: 0x116dd8 | Kích thước: 188 bytes
//   0x04745c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x047460: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x047464: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x047468: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0028_0x04745c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04745cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x116dd8ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0029 | PC: 0x047518 | FDE: 0x116b20 | Size: 20 bytes [_ZNKSt6__ndk121__basic_string_commonILb1EE20__throw_length_errorEv]
// Hàm FDE #0029 | Địa chỉ PC: 0x047518 | Địa chỉ FDE: 0x116b20 | Kích thước: 20 bytes
//   0x047518: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x04751c: 910003FD  mov      x29, sp
//   0x047520: D0000600  adrp     x0, #0x109000
//   0x047524: 912D6400  add      x0, x0, #0xb59
static inline uint64_t fde_func_0029_0x047518(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x047518ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x116b20ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0030 | PC: 0x04752c | FDE: 0x116e08 | Size: 256 bytes
// Hàm FDE #0030 | Địa chỉ PC: 0x04752c | Địa chỉ FDE: 0x116e08 | Kích thước: 256 bytes
//   0x04752c: D10203FF  sub      sp, sp, #0x80
//   0x047530: F90013FB  str      x27, [sp, #0x20]
//   0x047534: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x047538: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0030_0x04752c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04752cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x116e08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0031 | PC: 0x047b40 | FDE: 0x116e40 | Size: 256 bytes
// Hàm FDE #0031 | Địa chỉ PC: 0x047b40 | Địa chỉ FDE: 0x116e40 | Kích thước: 256 bytes
//   0x047b40: D10183FF  sub      sp, sp, #0x60
//   0x047b44: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x047b48: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x047b4c: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0031_0x047b40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x047b40ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x116e40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0032 | PC: 0x049748 | FDE: 0x116b40 | Size: 256 bytes
// Hàm FDE #0032 | Địa chỉ PC: 0x049748 | Địa chỉ FDE: 0x116b40 | Kích thước: 256 bytes
//   0x049748: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04974c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x049750: 910043FD  add      x29, sp, #0x10
//   0x049754: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0032_0x049748(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x049748ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x116b40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0033 | PC: 0x04984c | FDE: 0x116e70 | Size: 256 bytes [_ZNSt6__ndk16vectorIN11fast_engine6EngineENS_9allocatorIS2_EEE8__appendEm]
// Hàm FDE #0033 | Địa chỉ PC: 0x04984c | Địa chỉ FDE: 0x116e70 | Kích thước: 256 bytes
//   0x04984c: D10203FF  sub      sp, sp, #0x80
//   0x049850: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x049854: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x049858: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0033_0x04984c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04984cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x116e70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0034 | PC: 0x049bc8 | FDE: 0x116b60 | Size: 200 bytes [_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKcm]
// Hàm FDE #0034 | Địa chỉ PC: 0x049bc8 | Địa chỉ FDE: 0x116b60 | Kích thước: 200 bytes
//   0x049bc8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x049bcc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x049bd0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x049bd4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0034_0x049bc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x049bc8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x116b60ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0035 | PC: 0x049c90 | FDE: 0x116b80 | Size: 256 bytes [_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE21__grow_by_and_replaceEmmmmmmPKc]
// Hàm FDE #0035 | Địa chỉ PC: 0x049c90 | Địa chỉ FDE: 0x116b80 | Kích thước: 256 bytes
//   0x049c90: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x049c94: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x049c98: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x049c9c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0035_0x049c90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x049c90ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x116b80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0036 | PC: 0x049dc8 | FDE: 0x116ea8 | Size: 256 bytes
// Hàm FDE #0036 | Địa chỉ PC: 0x049dc8 | Địa chỉ FDE: 0x116ea8 | Kích thước: 256 bytes
//   0x049dc8: D10203FF  sub      sp, sp, #0x80
//   0x049dcc: F90013FB  str      x27, [sp, #0x20]
//   0x049dd0: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x049dd4: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0036_0x049dc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x049dc8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x116ea8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0037 | PC: 0x04a3bc | FDE: 0x116ee0 | Size: 256 bytes [_ZNSt6__ndk16vectorINS_8functionIFvPN11fast_engine6EngineEEEENS_9allocatorIS6_EEE21__push_back_slow_pathIRKS6_EEvOT_]
// Hàm FDE #0037 | Địa chỉ PC: 0x04a3bc | Địa chỉ FDE: 0x116ee0 | Kích thước: 256 bytes
//   0x04a3bc: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x04a3c0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x04a3c4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x04a3c8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0037_0x04a3bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04a3bcULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x116ee0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0038 | PC: 0x04a5f4 | FDE: 0x116f10 | Size: 72 bytes [_ZN11fast_engine6number5CheckEPNS_6EngineEPNS_3ObjE]
// Hàm FDE #0038 | Địa chỉ PC: 0x04a5f4 | Địa chỉ FDE: 0x116f10 | Kích thước: 72 bytes
//   0x04a5f4: B4000101  cbz      x1, #0x4a614
//   0x04a5f8: F9401428  ldr      x8, [x1, #0x28]
//   0x04a5fc: F9403508  ldr      x8, [x8, #0x68]
//   0x04a600: B40000A8  cbz      x8, #0x4a614
static inline uint64_t fde_func_0038_0x04a5f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04a5f4ULL ^ (static_cast<uint64_t>(0xb4000101ULL) << 13);
    acc = (acc + a1 + 0xf9401428ULL) ^ 0x116f10ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0039 | PC: 0x04a63c | FDE: 0x116f28 | Size: 32 bytes [_ZN11fast_engine6number2OrEPNS_6EngineEPNS_3ObjES4_]
// Hàm FDE #0039 | Địa chỉ PC: 0x04a63c | Địa chỉ FDE: 0x116f28 | Kích thước: 32 bytes
//   0x04a63c: AA0203E8  mov      x8, x2
//   0x04a640: F00005E3  adrp     x3, #0x109000
//   0x04a644: 912FE863  add      x3, x3, #0xbfa
//   0x04a648: 52800F02  mov      w2, #0x78
static inline uint64_t fde_func_0039_0x04a63c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04a63cULL ^ (static_cast<uint64_t>(0xaa0203e8ULL) << 13);
    acc = (acc + a1 + 0xf00005e3ULL) ^ 0x116f28ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0040 | PC: 0x04a65c | FDE: 0x116f40 | Size: 224 bytes
// Hàm FDE #0040 | Địa chỉ PC: 0x04a65c | Địa chỉ FDE: 0x116f40 | Kích thước: 224 bytes
//   0x04a65c: D10103FF  sub      sp, sp, #0x40
//   0x04a660: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04a664: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04a668: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0040_0x04a65c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04a65cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x116f40ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #0041 | PC: 0x04a73c | FDE: 0x116f68 | Size: 32 bytes [_ZN11fast_engine6number3XorEPNS_6EngineEPNS_3ObjES4_]
// Hàm FDE #0041 | Địa chỉ PC: 0x04a73c | Địa chỉ FDE: 0x116f68 | Kích thước: 32 bytes
//   0x04a73c: AA0203E8  mov      x8, x2
//   0x04a740: F00005E3  adrp     x3, #0x109000
//   0x04a744: 912FF063  add      x3, x3, #0xbfc
//   0x04a748: 52800E02  mov      w2, #0x70
static inline uint64_t fde_func_0041_0x04a73c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04a73cULL ^ (static_cast<uint64_t>(0xaa0203e8ULL) << 13);
    acc = (acc + a1 + 0xf00005e3ULL) ^ 0x116f68ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0042 | PC: 0x04a75c | FDE: 0x116f80 | Size: 32 bytes [_ZN11fast_engine6number3AndEPNS_6EngineEPNS_3ObjES4_]
// Hàm FDE #0042 | Địa chỉ PC: 0x04a75c | Địa chỉ FDE: 0x116f80 | Kích thước: 32 bytes
//   0x04a75c: AA0203E8  mov      x8, x2
//   0x04a760: F00005E3  adrp     x3, #0x109000
//   0x04a764: 912FF863  add      x3, x3, #0xbfe
//   0x04a768: 52800D02  mov      w2, #0x68
static inline uint64_t fde_func_0042_0x04a75c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04a75cULL ^ (static_cast<uint64_t>(0xaa0203e8ULL) << 13);
    acc = (acc + a1 + 0xf00005e3ULL) ^ 0x116f80ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0043 | PC: 0x04a77c | FDE: 0x116f98 | Size: 32 bytes [_ZN11fast_engine6number6LShiftEPNS_6EngineEPNS_3ObjES4_]
// Hàm FDE #0043 | Địa chỉ PC: 0x04a77c | Địa chỉ FDE: 0x116f98 | Kích thước: 32 bytes
//   0x04a77c: AA0203E8  mov      x8, x2
//   0x04a780: F00005E3  adrp     x3, #0x109000
//   0x04a784: 91300063  add      x3, x3, #0xc00
//   0x04a788: 52800B02  mov      w2, #0x58
static inline uint64_t fde_func_0043_0x04a77c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04a77cULL ^ (static_cast<uint64_t>(0xaa0203e8ULL) << 13);
    acc = (acc + a1 + 0xf00005e3ULL) ^ 0x116f98ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0044 | PC: 0x04a79c | FDE: 0x116fb0 | Size: 32 bytes [_ZN11fast_engine6number6RShiftEPNS_6EngineEPNS_3ObjES4_]
// Hàm FDE #0044 | Địa chỉ PC: 0x04a79c | Địa chỉ FDE: 0x116fb0 | Kích thước: 32 bytes
//   0x04a79c: AA0203E8  mov      x8, x2
//   0x04a7a0: 90000623  adrp     x3, #0x10e000
//   0x04a7a4: 912F9863  add      x3, x3, #0xbe6
//   0x04a7a8: 52800C02  mov      w2, #0x60
static inline uint64_t fde_func_0044_0x04a79c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04a79cULL ^ (static_cast<uint64_t>(0xaa0203e8ULL) << 13);
    acc = (acc + a1 + 0x90000623ULL) ^ 0x116fb0ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0045 | PC: 0x04a7bc | FDE: 0x116fc8 | Size: 32 bytes [_ZN11fast_engine6number3SubEPNS_6EngineEPNS_3ObjES4_]
// Hàm FDE #0045 | Địa chỉ PC: 0x04a7bc | Địa chỉ FDE: 0x116fc8 | Kích thước: 32 bytes
//   0x04a7bc: AA0203E8  mov      x8, x2
//   0x04a7c0: F00005E3  adrp     x3, #0x109000
//   0x04a7c4: 91300C63  add      x3, x3, #0xc03
//   0x04a7c8: 52800102  mov      w2, #8
static inline uint64_t fde_func_0045_0x04a7bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04a7bcULL ^ (static_cast<uint64_t>(0xaa0203e8ULL) << 13);
    acc = (acc + a1 + 0xf00005e3ULL) ^ 0x116fc8ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0046 | PC: 0x04a7dc | FDE: 0x116fe0 | Size: 32 bytes [_ZN11fast_engine6number6DivModEPNS_6EngineEPNS_3ObjES4_]
// Hàm FDE #0046 | Địa chỉ PC: 0x04a7dc | Địa chỉ FDE: 0x116fe0 | Kích thước: 32 bytes
//   0x04a7dc: AA0203E8  mov      x8, x2
//   0x04a7e0: F00005E3  adrp     x3, #0x109000
//   0x04a7e4: 91301463  add      x3, x3, #0xc05
//   0x04a7e8: 52800402  mov      w2, #0x20
static inline uint64_t fde_func_0046_0x04a7dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04a7dcULL ^ (static_cast<uint64_t>(0xaa0203e8ULL) << 13);
    acc = (acc + a1 + 0xf00005e3ULL) ^ 0x116fe0ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0047 | PC: 0x04a7fc | FDE: 0x116ff8 | Size: 256 bytes [_ZN11fast_engine6number3AddEPNS_6EngineEPNS_3ObjES4_]
// Hàm FDE #0047 | Địa chỉ PC: 0x04a7fc | Địa chỉ FDE: 0x116ff8 | Kích thước: 256 bytes
//   0x04a7fc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x04a800: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x04a804: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x04a808: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0047_0x04a7fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04a7fcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x116ff8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0048 | PC: 0x04a90c | FDE: 0x117018 | Size: 256 bytes
// Hàm FDE #0048 | Địa chỉ PC: 0x04a90c | Địa chỉ FDE: 0x117018 | Kích thước: 256 bytes
//   0x04a90c: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x04a910: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x04a914: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x04a918: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0048_0x04a90c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04a90cULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x117018ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0049 | PC: 0x04aac0 | FDE: 0x117040 | Size: 256 bytes [_ZN11fast_engine6number3MulEPNS_6EngineEPNS_3ObjES4_]
// Hàm FDE #0049 | Địa chỉ PC: 0x04aac0 | Địa chỉ FDE: 0x117040 | Kích thước: 256 bytes
//   0x04aac0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x04aac4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04aac8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04aacc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0049_0x04aac0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04aac0ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x117040ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0050 | PC: 0x04acb4 | FDE: 0x117068 | Size: 32 bytes [_ZN11fast_engine6number8FloorDivEPNS_6EngineEPNS_3ObjES4_]
// Hàm FDE #0050 | Địa chỉ PC: 0x04acb4 | Địa chỉ FDE: 0x117068 | Kích thước: 32 bytes
//   0x04acb4: AA0203E8  mov      x8, x2
//   0x04acb8: F00005E3  adrp     x3, #0x109000
//   0x04acbc: 91304063  add      x3, x3, #0xc10
//   0x04acc0: 52801D02  mov      w2, #0xe8
static inline uint64_t fde_func_0050_0x04acb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04acb4ULL ^ (static_cast<uint64_t>(0xaa0203e8ULL) << 13);
    acc = (acc + a1 + 0xf00005e3ULL) ^ 0x117068ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0051 | PC: 0x04acd4 | FDE: 0x117080 | Size: 32 bytes [_ZN11fast_engine6number3DivEPNS_6EngineEPNS_3ObjES4_]
// Hàm FDE #0051 | Địa chỉ PC: 0x04acd4 | Địa chỉ FDE: 0x117080 | Kích thước: 32 bytes
//   0x04acd4: AA0203E8  mov      x8, x2
//   0x04acd8: F00005E3  adrp     x3, #0x109000
//   0x04acdc: 91304463  add      x3, x3, #0xc11
//   0x04ace0: 52801E02  mov      w2, #0xf0
static inline uint64_t fde_func_0051_0x04acd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04acd4ULL ^ (static_cast<uint64_t>(0xaa0203e8ULL) << 13);
    acc = (acc + a1 + 0xf00005e3ULL) ^ 0x117080ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0052 | PC: 0x04acf4 | FDE: 0x117098 | Size: 32 bytes [_ZN11fast_engine6number3ModEPNS_6EngineEPNS_3ObjES4_]
// Hàm FDE #0052 | Địa chỉ PC: 0x04acf4 | Địa chỉ FDE: 0x117098 | Kích thước: 32 bytes
//   0x04acf4: AA0203E8  mov      x8, x2
//   0x04acf8: F00005E3  adrp     x3, #0x109000
//   0x04acfc: 91304C63  add      x3, x3, #0xc13
//   0x04ad00: 52800302  mov      w2, #0x18
static inline uint64_t fde_func_0052_0x04acf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04acf4ULL ^ (static_cast<uint64_t>(0xaa0203e8ULL) << 13);
    acc = (acc + a1 + 0xf00005e3ULL) ^ 0x117098ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0053 | PC: 0x04ad14 | FDE: 0x1170b0 | Size: 32 bytes [_ZN11fast_engine6number3PowEPNS_6EngineEPNS_3ObjES4_]
// Hàm FDE #0053 | Địa chỉ PC: 0x04ad14 | Địa chỉ FDE: 0x1170b0 | Kích thước: 32 bytes
//   0x04ad14: AA0203E8  mov      x8, x2
//   0x04ad18: F00005E3  adrp     x3, #0x109000
//   0x04ad1c: 91305463  add      x3, x3, #0xc15
//   0x04ad20: 52800502  mov      w2, #0x28
static inline uint64_t fde_func_0053_0x04ad14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04ad14ULL ^ (static_cast<uint64_t>(0xaa0203e8ULL) << 13);
    acc = (acc + a1 + 0xf00005e3ULL) ^ 0x1170b0ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0054 | PC: 0x04ad34 | FDE: 0x1170c8 | Size: 128 bytes [_ZN11fast_engine6number8NegativeEPNS_6EngineEPNS_3ObjE]
// Hàm FDE #0054 | Địa chỉ PC: 0x04ad34 | Địa chỉ FDE: 0x1170c8 | Kích thước: 128 bytes
//   0x04ad34: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x04ad38: 910003FD  mov      x29, sp
//   0x04ad3c: AA0003E8  mov      x8, x0
//   0x04ad40: B4000141  cbz      x1, #0x4ad68
static inline uint64_t fde_func_0054_0x04ad34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04ad34ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1170c8ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0055 | PC: 0x04adb4 | FDE: 0x1170e8 | Size: 128 bytes [_ZN11fast_engine6number8PositiveEPNS_6EngineEPNS_3ObjE]
// Hàm FDE #0055 | Địa chỉ PC: 0x04adb4 | Địa chỉ FDE: 0x1170e8 | Kích thước: 128 bytes
//   0x04adb4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x04adb8: 910003FD  mov      x29, sp
//   0x04adbc: AA0003E8  mov      x8, x0
//   0x04adc0: B4000141  cbz      x1, #0x4ade8
static inline uint64_t fde_func_0055_0x04adb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04adb4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1170e8ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0056 | PC: 0x04ae34 | FDE: 0x117108 | Size: 128 bytes [_ZN11fast_engine6number6InvertEPNS_6EngineEPNS_3ObjE]
// Hàm FDE #0056 | Địa chỉ PC: 0x04ae34 | Địa chỉ FDE: 0x117108 | Kích thước: 128 bytes
//   0x04ae34: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x04ae38: 910003FD  mov      x29, sp
//   0x04ae3c: AA0003E8  mov      x8, x0
//   0x04ae40: B4000141  cbz      x1, #0x4ae68
static inline uint64_t fde_func_0056_0x04ae34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04ae34ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x117108ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0057 | PC: 0x04aeb4 | FDE: 0x117128 | Size: 128 bytes [_ZN11fast_engine6number3AbsEPNS_6EngineEPNS_3ObjE]
// Hàm FDE #0057 | Địa chỉ PC: 0x04aeb4 | Địa chỉ FDE: 0x117128 | Kích thước: 128 bytes
//   0x04aeb4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x04aeb8: 910003FD  mov      x29, sp
//   0x04aebc: AA0003E8  mov      x8, x0
//   0x04aec0: B4000141  cbz      x1, #0x4aee8
static inline uint64_t fde_func_0057_0x04aeb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04aeb4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x117128ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0058 | PC: 0x04af34 | FDE: 0x117640 | Size: 256 bytes [_ZN11fast_engine6number3IntEPNS_6EngineEPNS_3ObjE]
// Hàm FDE #0058 | Địa chỉ PC: 0x04af34 | Địa chỉ FDE: 0x117640 | Kích thước: 256 bytes
//   0x04af34: D10203FF  sub      sp, sp, #0x80
//   0x04af38: F9001BF9  str      x25, [sp, #0x30]
//   0x04af3c: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x04af40: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_0058_0x04af34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04af34ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf9ULL) ^ 0x117640ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0059 | PC: 0x04c364 | FDE: 0x117670 | Size: 256 bytes [_ZN11fast_engine6number5FloatEPNS_6EngineEPNS_3ObjE]
// Hàm FDE #0059 | Địa chỉ PC: 0x04c364 | Địa chỉ FDE: 0x117670 | Kích thước: 256 bytes
//   0x04c364: FC1C0FE8  str      d8, [sp, #-0x40]!
//   0x04c368: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04c36c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04c370: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0059_0x04c364(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04c364ULL ^ (static_cast<uint64_t>(0xfc1c0fe8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x117670ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0060 | PC: 0x04c628 | FDE: 0x117148 | Size: 256 bytes [_ZN11fast_engine6number6_IndexEPNS_6EngineEPNS_3ObjE]
// Hàm FDE #0060 | Địa chỉ PC: 0x04c628 | Địa chỉ FDE: 0x117148 | Kích thước: 256 bytes
//   0x04c628: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04c62c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04c630: 910043FD  add      x29, sp, #0x10
//   0x04c634: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0060_0x04c628(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04c628ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x117148ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0061 | PC: 0x04c764 | FDE: 0x117168 | Size: 256 bytes [_ZN11fast_engine6number10AsSizeTypeEPNS_6EngineEPNS_3ObjEPNS_7TypeObjE]
// Hàm FDE #0061 | Địa chỉ PC: 0x04c764 | Địa chỉ FDE: 0x117168 | Kích thước: 256 bytes
//   0x04c764: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x04c768: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04c76c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04c770: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0061_0x04c764(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04c764ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x117168ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0062 | PC: 0x04c864 | FDE: 0x117190 | Size: 36 bytes [_ZN11fast_engine5index5CheckEPNS_6EngineEPNS_3ObjE]
// Hàm FDE #0062 | Địa chỉ PC: 0x04c864 | Địa chỉ FDE: 0x117190 | Kích thước: 36 bytes
//   0x04c864: F9401428  ldr      x8, [x1, #0x28]
//   0x04c868: F9403508  ldr      x8, [x8, #0x68]
//   0x04c86c: B40000A8  cbz      x8, #0x4c880
//   0x04c870: F9408508  ldr      x8, [x8, #0x108]
static inline uint64_t fde_func_0062_0x04c864(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04c864ULL ^ (static_cast<uint64_t>(0xf9401428ULL) << 13);
    acc = (acc + a1 + 0xf9403508ULL) ^ 0x117190ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0063 | PC: 0x04c888 | FDE: 0x1171a8 | Size: 152 bytes [_ZN11fast_engine6number5IndexEPNS_6EngineEPNS_3ObjE]
// Hàm FDE #0063 | Địa chỉ PC: 0x04c888 | Địa chỉ FDE: 0x1171a8 | Kích thước: 152 bytes
//   0x04c888: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x04c88c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x04c890: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x04c894: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0063_0x04c888(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04c888ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1171a8ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0064 | PC: 0x04c920 | FDE: 0x1171c8 | Size: 256 bytes [_ZN11fast_engine6number9InplaceOrEPNS_6EngineEPNS_3ObjES4_]
// Hàm FDE #0064 | Địa chỉ PC: 0x04c920 | Địa chỉ FDE: 0x1171c8 | Kích thước: 256 bytes
//   0x04c920: D10103FF  sub      sp, sp, #0x40
//   0x04c924: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04c928: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04c92c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0064_0x04c920(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04c920ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1171c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0065 | PC: 0x04ca70 | FDE: 0x1171f0 | Size: 256 bytes [_ZN11fast_engine6number10InplaceXorEPNS_6EngineEPNS_3ObjES4_]
// Hàm FDE #0065 | Địa chỉ PC: 0x04ca70 | Địa chỉ FDE: 0x1171f0 | Kích thước: 256 bytes
//   0x04ca70: D10103FF  sub      sp, sp, #0x40
//   0x04ca74: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04ca78: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04ca7c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0065_0x04ca70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04ca70ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1171f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0066 | PC: 0x04cbc0 | FDE: 0x117218 | Size: 256 bytes [_ZN11fast_engine6number10InplaceAndEPNS_6EngineEPNS_3ObjES4_]
// Hàm FDE #0066 | Địa chỉ PC: 0x04cbc0 | Địa chỉ FDE: 0x117218 | Kích thước: 256 bytes
//   0x04cbc0: D10103FF  sub      sp, sp, #0x40
//   0x04cbc4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04cbc8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04cbcc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0066_0x04cbc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04cbc0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x117218ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0067 | PC: 0x04cd10 | FDE: 0x117240 | Size: 256 bytes [_ZN11fast_engine6number13InplaceLShiftEPNS_6EngineEPNS_3ObjES4_]
// Hàm FDE #0067 | Địa chỉ PC: 0x04cd10 | Địa chỉ FDE: 0x117240 | Kích thước: 256 bytes
//   0x04cd10: D10103FF  sub      sp, sp, #0x40
//   0x04cd14: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04cd18: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04cd1c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0067_0x04cd10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04cd10ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x117240ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0068 | PC: 0x04ce60 | FDE: 0x117268 | Size: 256 bytes [_ZN11fast_engine6number13InplaceRShiftEPNS_6EngineEPNS_3ObjES4_]
// Hàm FDE #0068 | Địa chỉ PC: 0x04ce60 | Địa chỉ FDE: 0x117268 | Kích thước: 256 bytes
//   0x04ce60: D10103FF  sub      sp, sp, #0x40
//   0x04ce64: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04ce68: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04ce6c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0068_0x04ce60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04ce60ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x117268ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0069 | PC: 0x04cfb0 | FDE: 0x117290 | Size: 256 bytes [_ZN11fast_engine6number10InplaceSubEPNS_6EngineEPNS_3ObjES4_]
// Hàm FDE #0069 | Địa chỉ PC: 0x04cfb0 | Địa chỉ FDE: 0x117290 | Kích thước: 256 bytes
//   0x04cfb0: D10103FF  sub      sp, sp, #0x40
//   0x04cfb4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04cfb8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04cfbc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0069_0x04cfb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04cfb0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x117290ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0070 | PC: 0x04d100 | FDE: 0x1172b8 | Size: 256 bytes [_ZN11fast_engine6number15InplaceFloorDivEPNS_6EngineEPNS_3ObjES4_]
// Hàm FDE #0070 | Địa chỉ PC: 0x04d100 | Địa chỉ FDE: 0x1172b8 | Kích thước: 256 bytes
//   0x04d100: D10103FF  sub      sp, sp, #0x40
//   0x04d104: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04d108: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04d10c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0070_0x04d100(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04d100ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1172b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0071 | PC: 0x04d250 | FDE: 0x1172e0 | Size: 256 bytes [_ZN11fast_engine6number10InplaceDivEPNS_6EngineEPNS_3ObjES4_]
// Hàm FDE #0071 | Địa chỉ PC: 0x04d250 | Địa chỉ FDE: 0x1172e0 | Kích thước: 256 bytes
//   0x04d250: D10103FF  sub      sp, sp, #0x40
//   0x04d254: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04d258: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04d25c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0071_0x04d250(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04d250ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1172e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0072 | PC: 0x04d3a0 | FDE: 0x117308 | Size: 256 bytes [_ZN11fast_engine6number10InplaceAddEPNS_6EngineEPNS_3ObjES4_]
// Hàm FDE #0072 | Địa chỉ PC: 0x04d3a0 | Địa chỉ FDE: 0x117308 | Kích thước: 256 bytes
//   0x04d3a0: D10103FF  sub      sp, sp, #0x40
//   0x04d3a4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04d3a8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04d3ac: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0072_0x04d3a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04d3a0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x117308ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0073 | PC: 0x04d53c | FDE: 0x117330 | Size: 256 bytes [_ZN11fast_engine6number10InplaceMulEPNS_6EngineEPNS_3ObjES4_]
// Hàm FDE #0073 | Địa chỉ PC: 0x04d53c | Địa chỉ FDE: 0x117330 | Kích thước: 256 bytes
//   0x04d53c: D10143FF  sub      sp, sp, #0x50
//   0x04d540: F9000BF7  str      x23, [sp, #0x10]
//   0x04d544: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x04d548: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0073_0x04d53c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04d53cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x117330ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0074 | PC: 0x04d7c0 | FDE: 0x117358 | Size: 256 bytes [_ZN11fast_engine6number10InplaceModEPNS_6EngineEPNS_3ObjES4_]
// Hàm FDE #0074 | Địa chỉ PC: 0x04d7c0 | Địa chỉ FDE: 0x117358 | Kích thước: 256 bytes
//   0x04d7c0: D10103FF  sub      sp, sp, #0x40
//   0x04d7c4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04d7c8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04d7cc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0074_0x04d7c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04d7c0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x117358ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0075 | PC: 0x04d910 | FDE: 0x117380 | Size: 256 bytes [_ZN11fast_engine6number10InplacePowEPNS_6EngineEPNS_3ObjES4_]
// Hàm FDE #0075 | Địa chỉ PC: 0x04d910 | Địa chỉ FDE: 0x117380 | Kích thước: 256 bytes
//   0x04d910: D10103FF  sub      sp, sp, #0x40
//   0x04d914: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04d918: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04d91c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0075_0x04d910(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04d910ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x117380ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0076 | PC: 0x04da60 | FDE: 0x1173a8 | Size: 44 bytes [_ZN11fast_engine8sequence5CheckEPNS_6EngineEPNS_3ObjE]
// Hàm FDE #0076 | Địa chỉ PC: 0x04da60 | Địa chỉ FDE: 0x1173a8 | Kích thước: 44 bytes
//   0x04da60: F9401428  ldr      x8, [x1, #0x28]
//   0x04da64: 3942AD09  ldrb     w9, [x8, #0xab]
//   0x04da68: 372800E9  tbnz     w9, #5, #0x4da84
//   0x04da6c: F9403908  ldr      x8, [x8, #0x70]
static inline uint64_t fde_func_0076_0x04da60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04da60ULL ^ (static_cast<uint64_t>(0xf9401428ULL) << 13);
    acc = (acc + a1 + 0x3942ad09ULL) ^ 0x1173a8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0077 | PC: 0x04da8c | FDE: 0x1173c0 | Size: 256 bytes [_ZN11fast_engine8sequence6ConcatEPNS_6EngineEPNS_3ObjES4_]
// Hàm FDE #0077 | Địa chỉ PC: 0x04da8c | Địa chỉ FDE: 0x1173c0 | Kích thước: 256 bytes
//   0x04da8c: D100C3FF  sub      sp, sp, #0x30
//   0x04da90: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x04da94: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x04da98: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0077_0x04da8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04da8cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1173c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0078 | PC: 0x04db94 | FDE: 0x1176a0 | Size: 256 bytes [_ZN11fast_engine8sequence6RepeatEPNS_6EngineEPNS_3ObjEl]
// Hàm FDE #0078 | Địa chỉ PC: 0x04db94 | Địa chỉ FDE: 0x1176a0 | Kích thước: 256 bytes
//   0x04db94: D10103FF  sub      sp, sp, #0x40
//   0x04db98: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04db9c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04dba0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0078_0x04db94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04db94ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1176a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0079 | PC: 0x04dd84 | FDE: 0x1173e0 | Size: 256 bytes [_ZN11fast_engine8sequence7GetItemEPNS_6EngineEPNS_3ObjEl]
// Hàm FDE #0079 | Địa chỉ PC: 0x04dd84 | Địa chỉ FDE: 0x1173e0 | Kích thước: 256 bytes
//   0x04dd84: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x04dd88: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x04dd8c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x04dd90: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0079_0x04dd84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04dd84ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1173e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0080 | PC: 0x04de8c | FDE: 0x1176d0 | Size: 256 bytes [_ZN11fast_engine8sequence8GetSliceEPNS_6EngineEPNS_3ObjEll]
// Hàm FDE #0080 | Địa chỉ PC: 0x04de8c | Địa chỉ FDE: 0x1176d0 | Kích thước: 256 bytes
//   0x04de8c: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x04de90: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x04de94: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x04de98: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0080_0x04de8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04de8cULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1176d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0081 | PC: 0x04e128 | FDE: 0x117408 | Size: 256 bytes [_ZN11fast_engine8sequence7SetItemEPNS_6EngineEPNS_3ObjElS4_]
// Hàm FDE #0081 | Địa chỉ PC: 0x04e128 | Địa chỉ FDE: 0x117408 | Kích thước: 256 bytes
//   0x04e128: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x04e12c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x04e130: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x04e134: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0081_0x04e128(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04e128ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x117408ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0082 | PC: 0x04e238 | FDE: 0x117708 | Size: 256 bytes [_ZN11fast_engine8sequence8SetSliceEPNS_6EngineEPNS_3ObjEllS4_]
// Hàm FDE #0082 | Địa chỉ PC: 0x04e238 | Địa chỉ FDE: 0x117708 | Kích thước: 256 bytes
//   0x04e238: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x04e23c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x04e240: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x04e244: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0082_0x04e238(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04e238ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x117708ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0083 | PC: 0x04e4d8 | FDE: 0x117430 | Size: 256 bytes [_ZN11fast_engine8sequence7DelItemEPNS_6EngineEPNS_3ObjEl]
// Hàm FDE #0083 | Địa chỉ PC: 0x04e4d8 | Địa chỉ FDE: 0x117430 | Kích thước: 256 bytes
//   0x04e4d8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x04e4dc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x04e4e0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x04e4e4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0083_0x04e4d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04e4d8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x117430ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0084 | PC: 0x04e5e8 | FDE: 0x117740 | Size: 256 bytes [_ZN11fast_engine8sequence8DelSliceEPNS_6EngineEPNS_3ObjEll]
// Hàm FDE #0084 | Địa chỉ PC: 0x04e5e8 | Địa chỉ FDE: 0x117740 | Kích thước: 256 bytes
//   0x04e5e8: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x04e5ec: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x04e5f0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x04e5f4: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0084_0x04e5e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04e5e8ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x117740ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0085 | PC: 0x04e888 | FDE: 0x117458 | Size: 80 bytes [_ZN11fast_engine8sequence8ContainsEPNS_6EngineEPNS_3ObjES4_]
// Hàm FDE #0085 | Địa chỉ PC: 0x04e888 | Địa chỉ FDE: 0x117458 | Kích thước: 80 bytes
//   0x04e888: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x04e88c: 910003FD  mov      x29, sp
//   0x04e890: F9401428  ldr      x8, [x1, #0x28]
//   0x04e894: F9403909  ldr      x9, [x8, #0x70]
static inline uint64_t fde_func_0085_0x04e888(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04e888ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x117458ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0086 | PC: 0x04e8d8 | FDE: 0x117478 | Size: 256 bytes [_ZN11fast_engine8sequence11_IterSearchEPNS_6EngineEPNS_3ObjES4_i]
// Hàm FDE #0086 | Địa chỉ PC: 0x04e8d8 | Địa chỉ FDE: 0x117478 | Kích thước: 256 bytes
//   0x04e8d8: D101C3FF  sub      sp, sp, #0x70
//   0x04e8dc: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x04e8e0: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x04e8e4: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_0086_0x04e8d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04e8d8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x117478ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0087 | PC: 0x04eb28 | FDE: 0x1174a8 | Size: 256 bytes [_ZN11fast_engine8sequence13InplaceConcatEPNS_6EngineEPNS_3ObjES4_]
// Hàm FDE #0087 | Địa chỉ PC: 0x04eb28 | Địa chỉ FDE: 0x1174a8 | Kích thước: 256 bytes
//   0x04eb28: D100C3FF  sub      sp, sp, #0x30
//   0x04eb2c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x04eb30: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x04eb34: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0087_0x04eb28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04eb28ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1174a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0088 | PC: 0x04ec38 | FDE: 0x117778 | Size: 256 bytes [_ZN11fast_engine8sequence13InplaceRepeatEPNS_6EngineEPNS_3ObjEl]
// Hàm FDE #0088 | Địa chỉ PC: 0x04ec38 | Địa chỉ FDE: 0x117778 | Kích thước: 256 bytes
//   0x04ec38: D10103FF  sub      sp, sp, #0x40
//   0x04ec3c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04ec40: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04ec44: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0088_0x04ec38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04ec38ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x117778ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0089 | PC: 0x04ee30 | FDE: 0x1174c8 | Size: 196 bytes [_ZN11fast_engine8sequence6LengthEPNS_6EngineEPNS_3ObjE]
// Hàm FDE #0089 | Địa chỉ PC: 0x04ee30 | Địa chỉ FDE: 0x1174c8 | Kích thước: 196 bytes
//   0x04ee30: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x04ee34: 910003FD  mov      x29, sp
//   0x04ee38: AA0003E8  mov      x8, x0
//   0x04ee3c: B4000141  cbz      x1, #0x4ee64
static inline uint64_t fde_func_0089_0x04ee30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04ee30ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1174c8ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0090 | PC: 0x04eef4 | FDE: 0x1174e8 | Size: 8 bytes [_ZN11fast_engine8sequence5CountEPNS_6EngineEPNS_3ObjES4_]
// Hàm FDE #0090 | Địa chỉ PC: 0x04eef4 | Địa chỉ FDE: 0x1174e8 | Kích thước: 8 bytes
//   0x04eef4: 52800023  mov      w3, #1
//   0x04eef8: 17FFD3FA  b        #0x43ee0
static inline uint64_t fde_func_0090_0x04eef4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04eef4ULL ^ (static_cast<uint64_t>(0x52800023ULL) << 13);
    acc = (acc + a1 + 0x17ffd3faULL) ^ 0x1174e8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0091 | PC: 0x04eefc | FDE: 0x117500 | Size: 8 bytes [_ZN11fast_engine8sequence5IndexEPNS_6EngineEPNS_3ObjES4_]
// Hàm FDE #0091 | Địa chỉ PC: 0x04eefc | Địa chỉ FDE: 0x117500 | Kích thước: 8 bytes
//   0x04eefc: 52800043  mov      w3, #2
//   0x04ef00: 17FFD3F8  b        #0x43ee0
static inline uint64_t fde_func_0091_0x04eefc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04eefcULL ^ (static_cast<uint64_t>(0x52800043ULL) << 13);
    acc = (acc + a1 + 0x17ffd3f8ULL) ^ 0x117500ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0092 | PC: 0x04ef04 | FDE: 0x117518 | Size: 80 bytes [_ZN11fast_engine8sequence2InEPNS_6EngineEPNS_3ObjES4_]
// Hàm FDE #0092 | Địa chỉ PC: 0x04ef04 | Địa chỉ FDE: 0x117518 | Kích thước: 80 bytes
//   0x04ef04: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x04ef08: 910003FD  mov      x29, sp
//   0x04ef0c: F9401428  ldr      x8, [x1, #0x28]
//   0x04ef10: F9403909  ldr      x9, [x8, #0x70]
static inline uint64_t fde_func_0092_0x04ef04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04ef04ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x117518ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0093 | PC: 0x04ef54 | FDE: 0x117538 | Size: 256 bytes [_ZN11fast_engine8sequence5TupleEPNS_6EngineEPNS_3ObjE]
// Hàm FDE #0093 | Địa chỉ PC: 0x04ef54 | Địa chỉ FDE: 0x117538 | Kích thước: 256 bytes
//   0x04ef54: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x04ef58: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04ef5c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04ef60: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0093_0x04ef54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04ef54ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x117538ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0094 | PC: 0x04f1b4 | FDE: 0x1177a8 | Size: 192 bytes [_ZN11fast_engine8TupleObj11GetOrCreateElPNS_6EngineE]
// Hàm FDE #0094 | Địa chỉ PC: 0x04f1b4 | Địa chỉ FDE: 0x1177a8 | Kích thước: 192 bytes
//   0x04f1b4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x04f1b8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x04f1bc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x04f1c0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0094_0x04f1b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f1b4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1177a8ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #0095 | PC: 0x04f274 | FDE: 0x117560 | Size: 92 bytes [_ZN11fast_engine4iter4NextEPNS_6EngineEPNS_3ObjE]
// Hàm FDE #0095 | Địa chỉ PC: 0x04f274 | Địa chỉ FDE: 0x117560 | Kích thước: 92 bytes
//   0x04f274: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04f278: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04f27c: 910043FD  add      x29, sp, #0x10
//   0x04f280: F9401428  ldr      x8, [x1, #0x28]
static inline uint64_t fde_func_0095_0x04f274(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f274ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x117560ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0096 | PC: 0x04f2d0 | FDE: 0x1177d0 | Size: 236 bytes [_ZN11fast_engine8sequence4ListEPNS_6EngineEPNS_3ObjE]
// Hàm FDE #0096 | Địa chỉ PC: 0x04f2d0 | Địa chỉ FDE: 0x1177d0 | Kích thước: 236 bytes
//   0x04f2d0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x04f2d4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x04f2d8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x04f2dc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0096_0x04f2d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f2d0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1177d0ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0097 | PC: 0x04f3bc | FDE: 0x117580 | Size: 256 bytes [_ZN11fast_engine8sequence4FastEPNS_6EngineEPNS_3ObjEPKc]
// Hàm FDE #0097 | Địa chỉ PC: 0x04f3bc | Địa chỉ FDE: 0x117580 | Kích thước: 256 bytes
//   0x04f3bc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x04f3c0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x04f3c4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x04f3c8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0097_0x04f3bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f3bcULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x117580ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0098 | PC: 0x04f4d4 | FDE: 0x1177f8 | Size: 256 bytes [_ZN11fast_engine7mapping4KeysEPNS_6EngineEPNS_3ObjE]
// Hàm FDE #0098 | Địa chỉ PC: 0x04f4d4 | Địa chỉ FDE: 0x1177f8 | Kích thước: 256 bytes
//   0x04f4d4: D101C3FF  sub      sp, sp, #0x70
//   0x04f4d8: F90013F9  str      x25, [sp, #0x20]
//   0x04f4dc: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x04f4e0: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0098_0x04f4d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f4d4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x1177f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0099 | PC: 0x04f834 | FDE: 0x1175a8 | Size: 40 bytes [_ZN11fast_engine7mapping5CheckEPNS_6EngineEPNS_3ObjE]
// Hàm FDE #0099 | Địa chỉ PC: 0x04f834 | Địa chỉ FDE: 0x1175a8 | Kích thước: 40 bytes
//   0x04f834: B4000101  cbz      x1, #0x4f854
//   0x04f838: F9401428  ldr      x8, [x1, #0x28]
//   0x04f83c: F9403D08  ldr      x8, [x8, #0x78]
//   0x04f840: B40000A8  cbz      x8, #0x4f854
static inline uint64_t fde_func_0099_0x04f834(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f834ULL ^ (static_cast<uint64_t>(0xb4000101ULL) << 13);
    acc = (acc + a1 + 0xf9401428ULL) ^ 0x1175a8ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0100 | PC: 0x04f85c | FDE: 0x1175c0 | Size: 4 bytes [_ZN11fast_engine7mapping7GetItemEPNS_6EngineEPNS_3ObjES4_]
// Hàm FDE #0100 | Địa chỉ PC: 0x04f85c | Địa chỉ FDE: 0x1175c0 | Kích thước: 4 bytes
//   0x04f85c: 17FFD50D  b        #0x44c90
static inline uint64_t fde_func_0100_0x04f85c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f85cULL ^ (static_cast<uint64_t>(0x17ffd50dULL) << 13);
    acc = (acc + a1 + 0x17ffd454ULL) ^ 0x1175c0ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0101 | PC: 0x04f860 | FDE: 0x1175d8 | Size: 4 bytes [_ZN11fast_engine7mapping7SetItemEPNS_6EngineEPNS_3ObjES4_S4_]
// Hàm FDE #0101 | Địa chỉ PC: 0x04f860 | Địa chỉ FDE: 0x1175d8 | Kích thước: 4 bytes
//   0x04f860: 17FFD454  b        #0x449b0
static inline uint64_t fde_func_0101_0x04f860(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f860ULL ^ (static_cast<uint64_t>(0x17ffd454ULL) << 13);
    acc = (acc + a1 + 0x17ffd61fULL) ^ 0x1175d8ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0102 | PC: 0x04f864 | FDE: 0x1175f0 | Size: 4 bytes [_ZN11fast_engine7mapping7DelItemEPNS_6EngineEPNS_3ObjES4_]
// Hàm FDE #0102 | Địa chỉ PC: 0x04f864 | Địa chỉ FDE: 0x1175f0 | Kích thước: 4 bytes
//   0x04f864: 17FFD61F  b        #0x450e0
static inline uint64_t fde_func_0102_0x04f864(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f864ULL ^ (static_cast<uint64_t>(0x17ffd61fULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x1175f0ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0103 | PC: 0x04f868 | FDE: 0x117608 | Size: 196 bytes [_ZN11fast_engine7mapping6LengthEPNS_6EngineEPNS_3ObjE]
// Hàm FDE #0103 | Địa chỉ PC: 0x04f868 | Địa chỉ FDE: 0x117608 | Kích thước: 196 bytes
//   0x04f868: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x04f86c: 910003FD  mov      x29, sp
//   0x04f870: AA0003E8  mov      x8, x0
//   0x04f874: B4000141  cbz      x1, #0x4f89c
static inline uint64_t fde_func_0103_0x04f868(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f868ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x117608ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0104 | PC: 0x04f92c | FDE: 0x117628 | Size: 40 bytes [_ZN11fast_engine4iter5CheckEPNS_6EngineEPNS_3ObjE]
// Hàm FDE #0104 | Địa chỉ PC: 0x04f92c | Địa chỉ FDE: 0x117628 | Kích thước: 40 bytes
//   0x04f92c: F9401428  ldr      x8, [x1, #0x28]
//   0x04f930: 90000789  adrp     x9, #0x13f000
//   0x04f934: F9406108  ldr      x8, [x8, #0xc0]
//   0x04f938: F9451529  ldr      x9, [x9, #0xa28]
static inline uint64_t fde_func_0104_0x04f92c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f92cULL ^ (static_cast<uint64_t>(0xf9401428ULL) << 13);
    acc = (acc + a1 + 0x90000789ULL) ^ 0x117628ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0105 | PC: 0x04f954 | FDE: 0x117828 | Size: 144 bytes [_ZN11fast_engine14keyword_parser10NoKeywordsERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEPNS_3ObjEPNS_6EngineE]
// Hàm FDE #0105 | Địa chỉ PC: 0x04f954 | Địa chỉ FDE: 0x117828 | Kích thước: 144 bytes
//   0x04f954: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04f958: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04f95c: 910043FD  add      x29, sp, #0x10
//   0x04f960: B40003A1  cbz      x1, #0x4f9d4
static inline uint64_t fde_func_0105_0x04f954(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f954ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x117828ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0106 | PC: 0x04f9e4 | FDE: 0x117848 | Size: 140 bytes [_ZN11fast_engine14keyword_parser9NoKwnamesERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEPNS_3ObjEPNS_6EngineE]
// Hàm FDE #0106 | Địa chỉ PC: 0x04f9e4 | Địa chỉ FDE: 0x117848 | Kích thước: 140 bytes
//   0x04f9e4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04f9e8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04f9ec: 910043FD  add      x29, sp, #0x10
//   0x04f9f0: B4000381  cbz      x1, #0x4fa60
static inline uint64_t fde_func_0106_0x04f9e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f9e4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x117848ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0107 | PC: 0x04fa70 | FDE: 0x117868 | Size: 140 bytes [_ZN11fast_engine14keyword_parser12NoPositionalERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEPNS_3ObjEPNS_6EngineE]
// Hàm FDE #0107 | Địa chỉ PC: 0x04fa70 | Địa chỉ FDE: 0x117868 | Kích thước: 140 bytes
//   0x04fa70: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04fa74: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04fa78: 910043FD  add      x29, sp, #0x10
//   0x04fa7c: B4000381  cbz      x1, #0x4faec
static inline uint64_t fde_func_0107_0x04fa70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04fa70ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x117868ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0108 | PC: 0x04fafc | FDE: 0x1179a0 | Size: 256 bytes [_ZN11fast_engine14keyword_parser14UnpackKeywordsEPKPNS_3ObjElS2_S2_PNS0_6ParserEiiiPS2_PNS_6EngineE]
// Hàm FDE #0108 | Địa chỉ PC: 0x04fafc | Địa chỉ FDE: 0x1179a0 | Kích thước: 256 bytes
//   0x04fafc: D103C3FF  sub      sp, sp, #0xf0
//   0x04fb00: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x04fb04: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x04fb08: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_0108_0x04fafc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04fafcULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa9096ffcULL) ^ 0x1179a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0109 | PC: 0x050498 | FDE: 0x117888 | Size: 28 bytes [_ZN11fast_engine14keyword_parser11StackAsDictEPKPNS_3ObjES2_PNS_6EngineE]
// Hàm FDE #0109 | Địa chỉ PC: 0x050498 | Địa chỉ FDE: 0x117888 | Kích thước: 28 bytes
//   0x050498: A9441028  ldp      x8, x4, [x1, #0x40]
//   0x05049c: AA0203E5  mov      x5, x2
//   0x0504a0: 52800021  mov      w1, #1
//   0x0504a4: 52800023  mov      w3, #1
static inline uint64_t fde_func_0109_0x050498(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x050498ULL ^ (static_cast<uint64_t>(0xa9441028ULL) << 13);
    acc = (acc + a1 + 0xaa0203e5ULL) ^ 0x117888ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0110 | PC: 0x0504b4 | FDE: 0x1178a0 | Size: 256 bytes [_ZN11fast_engine14keyword_parser10UnpackDictEPKPNS_3ObjElS2_PS2_PNS_6EngineE]
// Hàm FDE #0110 | Địa chỉ PC: 0x0504b4 | Địa chỉ FDE: 0x1178a0 | Kích thước: 256 bytes
//   0x0504b4: D10203FF  sub      sp, sp, #0x80
//   0x0504b8: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0504bc: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0504c0: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0110_0x0504b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0504b4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1178a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0111 | PC: 0x0506a0 | FDE: 0x1178d0 | Size: 228 bytes [_ZN11fast_engine14keyword_parser14UnpackDictFreeEPKPNS_3ObjElS2_PNS_6EngineE]
// Hàm FDE #0111 | Địa chỉ PC: 0x0506a0 | Địa chỉ FDE: 0x1178d0 | Kích thước: 228 bytes
//   0x0506a0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0506a4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0506a8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0506ac: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0111_0x0506a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0506a0ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1178d0ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #0112 | PC: 0x050784 | FDE: 0x1178f8 | Size: 256 bytes [_ZN11fast_engine14keyword_parser15CheckPositionalEPKclllPNS_6EngineE]
// Hàm FDE #0112 | Địa chỉ PC: 0x050784 | Địa chỉ FDE: 0x1178f8 | Kích thước: 256 bytes
//   0x050784: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x050788: 910003FD  mov      x29, sp
//   0x05078c: AA0303E5  mov      x5, x3
//   0x050790: AA0203E8  mov      x8, x2
static inline uint64_t fde_func_0112_0x050784(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x050784ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1178f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0113 | PC: 0x05089c | FDE: 0x117918 | Size: 196 bytes [_ZN11fast_engine14keyword_parser24ValidateKeywordArgumentsEPNS_6EngineEPNS_3ObjE]
// Hàm FDE #0113 | Địa chỉ PC: 0x05089c | Địa chỉ FDE: 0x117918 | Kích thước: 196 bytes
//   0x05089c: D10143FF  sub      sp, sp, #0x50
//   0x0508a0: F90013F5  str      x21, [sp, #0x20]
//   0x0508a4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0508a8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0113_0x05089c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05089cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x117918ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0114 | PC: 0x050960 | FDE: 0x117938 | Size: 256 bytes [_ZN11fast_engine14keyword_parser11UnpackTupleEPNS_6EngineEPNS_3ObjEPKcllz]
// Hàm FDE #0114 | Địa chỉ PC: 0x050960 | Địa chỉ FDE: 0x117938 | Kích thước: 256 bytes
//   0x050960: D10403FF  sub      sp, sp, #0x100
//   0x050964: F90063F7  str      x23, [sp, #0xc0]
//   0x050968: A90D57F6  stp      x22, x21, [sp, #0xd0]
//   0x05096c: A90E4FF4  stp      x20, x19, [sp, #0xe0]
static inline uint64_t fde_func_0114_0x050960(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x050960ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xf90063f7ULL) ^ 0x117938ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0115 | PC: 0x050aa0 | FDE: 0x117960 | Size: 256 bytes [_ZN11fast_engine14keyword_parser12_UnpackStackEPNS_6EngineEPKPNS_3ObjElPKcllz]
// Hàm FDE #0115 | Địa chỉ PC: 0x050aa0 | Địa chỉ FDE: 0x117960 | Kích thước: 256 bytes
//   0x050aa0: D10403FF  sub      sp, sp, #0x100
//   0x050aa4: F90063F7  str      x23, [sp, #0xc0]
//   0x050aa8: A90D57F6  stp      x22, x21, [sp, #0xd0]
//   0x050aac: A90E4FF4  stp      x20, x19, [sp, #0xe0]
static inline uint64_t fde_func_0115_0x050aa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x050aa0ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xf90063f7ULL) ^ 0x117960ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0116 | PC: 0x050bb0 | FDE: 0x117988 | Size: 100 bytes [_ZN11fast_engine14keyword_parser11BadArgumentEPNS_6EngineEPKcS4_S4_PNS_3ObjE]
// Hàm FDE #0116 | Địa chỉ PC: 0x050bb0 | Địa chỉ FDE: 0x117988 | Kích thước: 100 bytes
//   0x050bb0: F0000769  adrp     x9, #0x13f000
//   0x050bb4: F944D129  ldr      x9, [x9, #0x9a0]
//   0x050bb8: F000076A  adrp     x10, #0x13f000
//   0x050bbc: AA0303E5  mov      x5, x3
static inline uint64_t fde_func_0116_0x050bb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x050bb0ULL ^ (static_cast<uint64_t>(0xf0000769ULL) << 13);
    acc = (acc + a1 + 0xf944d129ULL) ^ 0x117988ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #0117 | PC: 0x050c14 | FDE: 0x1179d8 | Size: 252 bytes [_ZN11fast_engine6StrObj11GetOrCreateERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEPNS_6EngineE]
// Hàm FDE #0117 | Địa chỉ PC: 0x050c14 | Địa chỉ FDE: 0x1179d8 | Kích thước: 252 bytes
//   0x050c14: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x050c18: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x050c1c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x050c20: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0117_0x050c14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x050c14ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1179d8ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #0118 | PC: 0x050d10 | FDE: 0x117a00 | Size: 24 bytes [_ZN11fast_engine8CallableEPNS_3ObjE]
// Hàm FDE #0118 | Địa chỉ PC: 0x050d10 | Địa chỉ FDE: 0x117a00 | Kích thước: 24 bytes
//   0x050d10: B40000A0  cbz      x0, #0x50d24
//   0x050d14: F9401408  ldr      x8, [x0, #0x28]
//   0x050d18: F9404508  ldr      x8, [x8, #0x88]
//   0x050d1c: F100011F  cmp      x8, #0
static inline uint64_t fde_func_0118_0x050d10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x050d10ULL ^ (static_cast<uint64_t>(0xb40000a0ULL) << 13);
    acc = (acc + a1 + 0xf9401408ULL) ^ 0x117a00ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0119 | PC: 0x050d28 | FDE: 0x117a18 | Size: 256 bytes [_ZN11fast_engine10MakeTpCallEPNS_6EngineEPNS_3ObjEPKS3_lS3_]
// Hàm FDE #0119 | Địa chỉ PC: 0x050d28 | Địa chỉ FDE: 0x117a18 | Kích thước: 256 bytes
//   0x050d28: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x050d2c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x050d30: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x050d34: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0119_0x050d28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x050d28ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x117a18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0120 | PC: 0x050eb8 | FDE: 0x117a40 | Size: 256 bytes [_ZN11fast_engine10VectorCallEPNS_6EngineEPNS_3ObjEPNS_8TupleObjEPNS_7DictObjE]
// Hàm FDE #0120 | Địa chỉ PC: 0x050eb8 | Địa chỉ FDE: 0x117a40 | Kích thước: 256 bytes
//   0x050eb8: D10183FF  sub      sp, sp, #0x60
//   0x050ebc: F9000BF9  str      x25, [sp, #0x10]
//   0x050ec0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x050ec4: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0120_0x050eb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x050eb8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf9ULL) ^ 0x117a40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0121 | PC: 0x051034 | FDE: 0x117a68 | Size: 116 bytes [_ZN11fast_engine4CallEPNS_6EngineEPNS_3ObjEPNS_8TupleObjEPNS_7DictObjE]
// Hàm FDE #0121 | Địa chỉ PC: 0x051034 | Địa chỉ FDE: 0x117a68 | Kích thước: 116 bytes
//   0x051034: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x051038: 910003FD  mov      x29, sp
//   0x05103c: F9401428  ldr      x8, [x1, #0x28]
//   0x051040: 3942A509  ldrb     w9, [x8, #0xa9]
static inline uint64_t fde_func_0121_0x051034(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051034ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x117a68ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0122 | PC: 0x0510a8 | FDE: 0x117a88 | Size: 256 bytes [_ZN11fast_engine4CallEPNS_6EngineEPNS_3ObjES3_PNS_8TupleObjEPNS_7DictObjE]
// Hàm FDE #0122 | Địa chỉ PC: 0x0510a8 | Địa chỉ FDE: 0x117a88 | Kích thước: 256 bytes
//   0x0510a8: D10243FF  sub      sp, sp, #0x90
//   0x0510ac: F9001BFB  str      x27, [sp, #0x30]
//   0x0510b0: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0510b4: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0122_0x0510a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0510a8ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9001bfbULL) ^ 0x117a88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0123 | PC: 0x0511bc | FDE: 0x117ab8 | Size: 256 bytes [_ZN11fast_engine12FastCallDictEPNS_6EngineEPNS_3ObjEPKS3_lS3_]
// Hàm FDE #0123 | Địa chỉ PC: 0x0511bc | Địa chỉ FDE: 0x117ab8 | Kích thước: 256 bytes
//   0x0511bc: D10183FF  sub      sp, sp, #0x60
//   0x0511c0: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0511c4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0511c8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0123_0x0511bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0511bcULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x117ab8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0124 | PC: 0x0512fc | FDE: 0x117ae8 | Size: 256 bytes [_ZN11fast_engine19CallFunctionObjArgsEPNS_6EngineEPNS_3ObjEz]
// Hàm FDE #0124 | Địa chỉ PC: 0x0512fc | Địa chỉ FDE: 0x117ae8 | Kích thước: 256 bytes
//   0x0512fc: D10643FF  sub      sp, sp, #0x190
//   0x051300: A91467FC  stp      x28, x25, [sp, #0x140]
//   0x051304: A9155FF8  stp      x24, x23, [sp, #0x150]
//   0x051308: A91657F6  stp      x22, x21, [sp, #0x160]
static inline uint64_t fde_func_0124_0x0512fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0512fcULL ^ (static_cast<uint64_t>(0xd10643ffULL) << 13);
    acc = (acc + a1 + 0xa91467fcULL) ^ 0x117ae8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0125 | PC: 0x051538 | FDE: 0x117b18 | Size: 256 bytes [_ZN11fast_engine16VectorcallMethodEPNS_3ObjEPKS1_mS1_PNS_6EngineE]
// Hàm FDE #0125 | Địa chỉ PC: 0x051538 | Địa chỉ FDE: 0x117b18 | Kích thước: 256 bytes
//   0x051538: D10143FF  sub      sp, sp, #0x50
//   0x05153c: F9000BF7  str      x23, [sp, #0x10]
//   0x051540: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x051544: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0125_0x051538(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051538ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x117b18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0126 | PC: 0x051648 | FDE: 0x117b40 | Size: 68 bytes [_ZN11fast_engine4Data5Get16Ev]
// Hàm FDE #0126 | Địa chỉ PC: 0x051648 | Địa chỉ FDE: 0x117b40 | Kích thước: 68 bytes
//   0x051648: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x05164c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x051650: 910043FD  add      x29, sp, #0x10
//   0x051654: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0126_0x051648(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051648ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x117b40ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0127 | PC: 0x05168c | FDE: 0x117b60 | Size: 108 bytes [_ZN11fast_engine4Data5Get32Ev]
// Hàm FDE #0127 | Địa chỉ PC: 0x05168c | Địa chỉ FDE: 0x117b60 | Kích thước: 108 bytes
//   0x05168c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x051690: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x051694: 910043FD  add      x29, sp, #0x10
//   0x051698: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0127_0x05168c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05168cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x117b60ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #0128 | PC: 0x0516f8 | FDE: 0x117b80 | Size: 200 bytes [_ZN11fast_engine4Data5Get64Ev]
// Hàm FDE #0128 | Địa chỉ PC: 0x0516f8 | Địa chỉ FDE: 0x117b80 | Kích thước: 200 bytes
//   0x0516f8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0516fc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x051700: 910043FD  add      x29, sp, #0x10
//   0x051704: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0128_0x0516f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0516f8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x117b80ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0129 | PC: 0x0517c0 | FDE: 0x117ba0 | Size: 88 bytes [_ZN11fast_engine10ByteStreamC1ERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE]
// Hàm FDE #0129 | Địa chỉ PC: 0x0517c0 | Địa chỉ FDE: 0x117ba0 | Kích thước: 88 bytes
//   0x0517c0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0517c4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0517c8: 910043FD  add      x29, sp, #0x10
//   0x0517cc: D0000768  adrp     x8, #0x13f000
static inline uint64_t fde_func_0129_0x0517c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0517c0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x117ba0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0130 | PC: 0x051818 | FDE: 0x117bc0 | Size: 36 bytes [_ZN11fast_engine10ByteStreamD2Ev]
// Hàm FDE #0130 | Địa chỉ PC: 0x051818 | Địa chỉ FDE: 0x117bc0 | Kích thước: 36 bytes
//   0x051818: D0000769  adrp     x9, #0x13f000
//   0x05181c: AA0003E8  mov      x8, x0
//   0x051820: F9400400  ldr      x0, [x0, #8]
//   0x051824: F9456D29  ldr      x9, [x9, #0xad8]
static inline uint64_t fde_func_0130_0x051818(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051818ULL ^ (static_cast<uint64_t>(0xd0000769ULL) << 13);
    acc = (acc + a1 + 0xaa0003e8ULL) ^ 0x117bc0ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0131 | PC: 0x05183c | FDE: 0x117bd8 | Size: 60 bytes [_ZN11fast_engine10ByteStreamD0Ev]
// Hàm FDE #0131 | Địa chỉ PC: 0x05183c | Địa chỉ FDE: 0x117bd8 | Kích thước: 60 bytes
//   0x05183c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x051840: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x051844: 910043FD  add      x29, sp, #0x10
//   0x051848: D0000768  adrp     x8, #0x13f000
static inline uint64_t fde_func_0131_0x05183c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05183cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x117bd8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0132 | PC: 0x051878 | FDE: 0x117bf8 | Size: 16 bytes [_ZNK11fast_engine10ByteStream5AtEofEv]
// Hàm FDE #0132 | Địa chỉ PC: 0x051878 | Địa chỉ FDE: 0x117bf8 | Kích thước: 16 bytes
//   0x051878: A9412408  ldp      x8, x9, [x0, #0x10]
//   0x05187c: EB08013F  cmp      x9, x8
//   0x051880: 1A9F17E0  cset     w0, eq
//   0x051884: D65F03C0  ret      
static inline uint64_t fde_func_0132_0x051878(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051878ULL ^ (static_cast<uint64_t>(0xa9412408ULL) << 13);
    acc = (acc + a1 + 0xeb08013fULL) ^ 0x117bf8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0133 | PC: 0x051888 | FDE: 0x117c10 | Size: 40 bytes [_ZN11fast_engine10ByteStream7GetByteEv]
// Hàm FDE #0133 | Địa chỉ PC: 0x051888 | Địa chỉ FDE: 0x117c10 | Kích thước: 40 bytes
//   0x051888: A9412009  ldp      x9, x8, [x0, #0x10]
//   0x05188c: EB09011F  cmp      x8, x9
//   0x051890: 54000061  b.ne     #0x5189c
//   0x051894: 12800000  mov      w0, #-1
static inline uint64_t fde_func_0133_0x051888(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051888ULL ^ (static_cast<uint64_t>(0xa9412009ULL) << 13);
    acc = (acc + a1 + 0xeb09011fULL) ^ 0x117c10ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0134 | PC: 0x0518b0 | FDE: 0x117c28 | Size: 104 bytes [_ZN11fast_engine10ByteStream9GetBufferEiPv]
// Hàm FDE #0134 | Địa chỉ PC: 0x0518b0 | Địa chỉ FDE: 0x117c28 | Kích thước: 104 bytes
//   0x0518b0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0518b4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0518b8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0518bc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0134_0x0518b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0518b0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x117c28ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0135 | PC: 0x051918 | FDE: 0x117c48 | Size: 68 bytes [_ZN11fast_engine4FileC2EPKc]
// Hàm FDE #0135 | Địa chỉ PC: 0x051918 | Địa chỉ FDE: 0x117c48 | Kích thước: 68 bytes
//   0x051918: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x05191c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x051920: 910043FD  add      x29, sp, #0x10
//   0x051924: D0000769  adrp     x9, #0x13f000
static inline uint64_t fde_func_0135_0x051918(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051918ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x117c48ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0136 | PC: 0x05195c | FDE: 0x117c68 | Size: 36 bytes [_ZN11fast_engine4FileD2Ev]
// Hàm FDE #0136 | Địa chỉ PC: 0x05195c | Địa chỉ FDE: 0x117c68 | Kích thước: 36 bytes
//   0x05195c: D0000769  adrp     x9, #0x13f000
//   0x051960: AA0003E8  mov      x8, x0
//   0x051964: F9400400  ldr      x0, [x0, #8]
//   0x051968: F944A129  ldr      x9, [x9, #0x940]
static inline uint64_t fde_func_0136_0x05195c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05195cULL ^ (static_cast<uint64_t>(0xd0000769ULL) << 13);
    acc = (acc + a1 + 0xaa0003e8ULL) ^ 0x117c68ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0137 | PC: 0x051980 | FDE: 0x117c80 | Size: 60 bytes [_ZN11fast_engine4FileD0Ev]
// Hàm FDE #0137 | Địa chỉ PC: 0x051980 | Địa chỉ FDE: 0x117c80 | Kích thước: 60 bytes
//   0x051980: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x051984: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x051988: 910043FD  add      x29, sp, #0x10
//   0x05198c: D0000768  adrp     x8, #0x13f000
static inline uint64_t fde_func_0137_0x051980(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051980ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x117c80ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0138 | PC: 0x0519bc | FDE: 0x117ca0 | Size: 56 bytes [_ZNK11fast_engine4File5AtEofEv]
// Hàm FDE #0138 | Địa chỉ PC: 0x0519bc | Địa chỉ FDE: 0x117ca0 | Kích thước: 56 bytes
//   0x0519bc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0519c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0519c4: 910043FD  add      x29, sp, #0x10
//   0x0519c8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0138_0x0519bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0519bcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x117ca0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0139 | PC: 0x0519f4 | FDE: 0x117cc0 | Size: 60 bytes [_ZN11fast_engine4File7GetByteEv]
// Hàm FDE #0139 | Địa chỉ PC: 0x0519f4 | Địa chỉ FDE: 0x117cc0 | Kích thước: 60 bytes
//   0x0519f4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0519f8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0519fc: 910043FD  add      x29, sp, #0x10
//   0x051a00: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0139_0x0519f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0519f4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x117cc0ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0140 | PC: 0x051a30 | FDE: 0x117ce0 | Size: 40 bytes [_ZN11fast_engine4File9GetBufferEiPv]
// Hàm FDE #0140 | Địa chỉ PC: 0x051a30 | Địa chỉ FDE: 0x117ce0 | Kích thước: 40 bytes
//   0x051a30: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x051a34: 910003FD  mov      x29, sp
//   0x051a38: F9400403  ldr      x3, [x0, #8]
//   0x051a3c: AA0203E8  mov      x8, x2
static inline uint64_t fde_func_0140_0x051a30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051a30ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x117ce0ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0141 | PC: 0x051a58 | FDE: 0x117d00 | Size: 48 bytes [_ZN11fast_engine6BufferC1ERNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE]
// Hàm FDE #0141 | Địa chỉ PC: 0x051a58 | Địa chỉ FDE: 0x117d00 | Kích thước: 48 bytes
//   0x051a58: 39400028  ldrb     w8, [x1]
//   0x051a5c: F9400429  ldr      x9, [x1, #8]
//   0x051a60: D341FD0A  lsr      x10, x8, #1
//   0x051a64: 7200011F  tst      w8, #1
static inline uint64_t fde_func_0141_0x051a58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051a58ULL ^ (static_cast<uint64_t>(0x39400028ULL) << 13);
    acc = (acc + a1 + 0xf9400429ULL) ^ 0x117d00ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0142 | PC: 0x051a88 | FDE: 0x117d18 | Size: 8 bytes [_ZNK11fast_engine6Buffer4sizeEv]
// Hàm FDE #0142 | Địa chỉ PC: 0x051a88 | Địa chỉ FDE: 0x117d18 | Kích thước: 8 bytes
//   0x051a88: F9400000  ldr      x0, [x0]
//   0x051a8c: D65F03C0  ret      
static inline uint64_t fde_func_0142_0x051a88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051a88ULL ^ (static_cast<uint64_t>(0xf9400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x117d18ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0143 | PC: 0x051a90 | FDE: 0x117d30 | Size: 8 bytes [_ZNK11fast_engine6Buffer6bufferEv]
// Hàm FDE #0143 | Địa chỉ PC: 0x051a90 | Địa chỉ FDE: 0x117d30 | Kích thước: 8 bytes
//   0x051a90: F9400400  ldr      x0, [x0, #8]
//   0x051a94: D65F03C0  ret      
static inline uint64_t fde_func_0143_0x051a90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051a90ULL ^ (static_cast<uint64_t>(0xf9400400ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x117d30ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0144 | PC: 0x051a98 | FDE: 0x117d48 | Size: 32 bytes [_ZNK11fast_engine10ByteStream6IsOpenEv]
// Hàm FDE #0144 | Địa chỉ PC: 0x051a98 | Địa chỉ FDE: 0x117d48 | Kích thước: 32 bytes
//   0x051a98: F9400408  ldr      x8, [x0, #8]
//   0x051a9c: B40000A8  cbz      x8, #0x51ab0
//   0x051aa0: F9400808  ldr      x8, [x0, #0x10]
//   0x051aa4: F100011F  cmp      x8, #0
static inline uint64_t fde_func_0144_0x051a98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051a98ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xb40000a8ULL) ^ 0x117d48ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0145 | PC: 0x051ab8 | FDE: 0x117d60 | Size: 16 bytes [_ZNK11fast_engine4File6IsOpenEv]
// Hàm FDE #0145 | Địa chỉ PC: 0x051ab8 | Địa chỉ FDE: 0x117d60 | Kích thước: 16 bytes
//   0x051ab8: F9400408  ldr      x8, [x0, #8]
//   0x051abc: F100011F  cmp      x8, #0
//   0x051ac0: 1A9F07E0  cset     w0, ne
//   0x051ac4: D65F03C0  ret      
static inline uint64_t fde_func_0145_0x051ab8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051ab8ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xf100011fULL) ^ 0x117d60ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0146 | PC: 0x051ac8 | FDE: 0x117d78 | Size: 12 bytes [_ZNK11fast_engine11ObjHashFuncclEPKNS_3ObjE]
// Hàm FDE #0146 | Địa chỉ PC: 0x051ac8 | Địa chỉ FDE: 0x117d78 | Kích thước: 12 bytes
//   0x051ac8: AA0103E0  mov      x0, x1
//   0x051acc: F9400C21  ldr      x1, [x1, #0x18]
//   0x051ad0: 17FFC408  b        #0x42af0
static inline uint64_t fde_func_0146_0x051ac8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051ac8ULL ^ (static_cast<uint64_t>(0xaa0103e0ULL) << 13);
    acc = (acc + a1 + 0xf9400c21ULL) ^ 0x117d78ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0147 | PC: 0x051ad4 | FDE: 0x117d90 | Size: 20 bytes [_ZNK11fast_engine9EqualFuncclEPKNS_3ObjES3_]
// Hàm FDE #0147 | Địa chỉ PC: 0x051ad4 | Địa chỉ FDE: 0x117d90 | Kích thước: 20 bytes
//   0x051ad4: F9400C23  ldr      x3, [x1, #0x18]
//   0x051ad8: AA0103E0  mov      x0, x1
//   0x051adc: AA0203E1  mov      x1, x2
//   0x051ae0: 52800042  mov      w2, #2
static inline uint64_t fde_func_0147_0x051ad4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051ad4ULL ^ (static_cast<uint64_t>(0xf9400c23ULL) << 13);
    acc = (acc + a1 + 0xaa0103e0ULL) ^ 0x117d90ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0148 | PC: 0x051ae8 | FDE: 0x117da8 | Size: 8 bytes [_ZN11fast_engine11HashPointerEPKvPv]
// Hàm FDE #0148 | Địa chỉ PC: 0x051ae8 | Địa chỉ FDE: 0x117da8 | Kích thước: 8 bytes
//   0x051ae8: 93C01000  ror      x0, x0, #4
//   0x051aec: D65F03C0  ret      
static inline uint64_t fde_func_0148_0x051ae8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051ae8ULL ^ (static_cast<uint64_t>(0x93c01000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x117da8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0149 | PC: 0x051af0 | FDE: 0x117dc0 | Size: 256 bytes [_ZN11fast_engine10HashDoubleEPKvd]
// Hàm FDE #0149 | Địa chỉ PC: 0x051af0 | Địa chỉ FDE: 0x117dc0 | Kích thước: 256 bytes
//   0x051af0: D2EFFE08  mov      x8, #0x7ff0000000000000
//   0x051af4: 1E60C001  fabs     d1, d0
//   0x051af8: 9E670102  fmov     d2, x8
//   0x051afc: 1E622020  fcmp     d1, d2
static inline uint64_t fde_func_0149_0x051af0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051af0ULL ^ (static_cast<uint64_t>(0xd2effe08ULL) << 13);
    acc = (acc + a1 + 0x1e60c001ULL) ^ 0x117dc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0150 | PC: 0x051c50 | FDE: 0x117e38 | Size: 192 bytes [_ZN11fast_engine18ReadObjectFromFileEPKcPNS_6EngineE]
// Hàm FDE #0150 | Địa chỉ PC: 0x051c50 | Địa chỉ FDE: 0x117e38 | Kích thước: 192 bytes
//   0x051c50: D10143FF  sub      sp, sp, #0x50
//   0x051c54: F90013F5  str      x21, [sp, #0x20]
//   0x051c58: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x051c5c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0150_0x051c50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051c50ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x117e38ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #0151 | PC: 0x051d10 | FDE: 0x117e60 | Size: 256 bytes
// Hàm FDE #0151 | Địa chỉ PC: 0x051d10 | Địa chỉ FDE: 0x117e60 | Kích thước: 256 bytes
//   0x051d10: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x051d14: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x051d18: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x051d1c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0151_0x051d10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051d10ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x117e60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0152 | PC: 0x051e80 | FDE: 0x117e88 | Size: 244 bytes [_ZN11fast_engine20ReadObjectFromBase64EPKcPNS_6EngineE]
// Hàm FDE #0152 | Địa chỉ PC: 0x051e80 | Địa chỉ FDE: 0x117e88 | Kích thước: 244 bytes
//   0x051e80: D10183FF  sub      sp, sp, #0x60
//   0x051e84: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x051e88: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x051e8c: 910143FD  add      x29, sp, #0x50
static inline uint64_t fde_func_0152_0x051e80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051e80ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9044ff4ULL) ^ 0x117e88ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #0153 | PC: 0x051f74 | FDE: 0x117eb0 | Size: 256 bytes
// Hàm FDE #0153 | Địa chỉ PC: 0x051f74 | Địa chỉ FDE: 0x117eb0 | Kích thước: 256 bytes
//   0x051f74: D104C3FF  sub      sp, sp, #0x130
//   0x051f78: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x051f7c: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x051f80: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0153_0x051f74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x051f74ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x117eb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0154 | PC: 0x0530d0 | FDE: 0x117de0 | Size: 204 bytes [_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEmc]
// Hàm FDE #0154 | Địa chỉ PC: 0x0530d0 | Địa chỉ FDE: 0x117de0 | Kích thước: 204 bytes
//   0x0530d0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0530d4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0530d8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0530dc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0154_0x0530d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0530d0ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x117de0ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #0155 | PC: 0x05319c | FDE: 0x117e08 | Size: 256 bytes [_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9__grow_byEmmmmmm]
// Hàm FDE #0155 | Địa chỉ PC: 0x05319c | Địa chỉ FDE: 0x117e08 | Kích thước: 256 bytes
//   0x05319c: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x0531a0: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0531a4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0531a8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0155_0x05319c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05319cULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x117e08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0156 | PC: 0x0532b4 | FDE: 0x117ee8 | Size: 4 bytes [_ZN11fast_engine4FreeEPvPNS_6EngineE]
// Hàm FDE #0156 | Địa chỉ PC: 0x0532b4 | Địa chỉ FDE: 0x117ee8 | Kích thước: 4 bytes
//   0x0532b4: 17FFBEB7  b        #0x42d90
static inline uint64_t fde_func_0156_0x0532b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0532b4ULL ^ (static_cast<uint64_t>(0x17ffbeb7ULL) << 13);
    acc = (acc + a1 + 0x17ffc0eeULL) ^ 0x117ee8ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0157 | PC: 0x0532b8 | FDE: 0x117f00 | Size: 4 bytes [_ZN11fast_engine7ReallocEPvmPNS_6EngineE]
// Hàm FDE #0157 | Địa chỉ PC: 0x0532b8 | Địa chỉ FDE: 0x117f00 | Kích thước: 4 bytes
//   0x0532b8: 17FFC0EE  b        #0x43670
static inline uint64_t fde_func_0157_0x0532b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0532b8ULL ^ (static_cast<uint64_t>(0x17ffc0eeULL) << 13);
    acc = (acc + a1 + 0xb40002e0ULL) ^ 0x117f00ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0158 | PC: 0x0532bc | FDE: 0x117f18 | Size: 96 bytes [_ZN11fast_engine9TraceFreeEPvPNS_6EngineE]
// Hàm FDE #0158 | Địa chỉ PC: 0x0532bc | Địa chỉ FDE: 0x117f18 | Kích thước: 96 bytes
//   0x0532bc: B40002E0  cbz      x0, #0x53318
//   0x0532c0: 52922A08  mov      w8, #0x9150
//   0x0532c4: 72A00028  movk     w8, #1, lsl #16
//   0x0532c8: 8B080028  add      x8, x1, x8
static inline uint64_t fde_func_0158_0x0532bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0532bcULL ^ (static_cast<uint64_t>(0xb40002e0ULL) << 13);
    acc = (acc + a1 + 0x52922a08ULL) ^ 0x117f18ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0159 | PC: 0x05331c | FDE: 0x117f30 | Size: 204 bytes [_ZN11fast_engine12TraceReallocEPvmPNS_6EngineE]
// Hàm FDE #0159 | Địa chỉ PC: 0x05331c | Địa chỉ FDE: 0x117f30 | Kích thước: 204 bytes
//   0x05331c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x053320: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x053324: 910043FD  add      x29, sp, #0x10
//   0x053328: 52922908  mov      w8, #0x9148
static inline uint64_t fde_func_0159_0x05331c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05331cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x117f30ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #0160 | PC: 0x0533e8 | FDE: 0x117f50 | Size: 64 bytes [_ZN11fast_engine12ConfigMemoryEv]
// Hàm FDE #0160 | Địa chỉ PC: 0x0533e8 | Địa chỉ FDE: 0x117f50 | Kích thước: 64 bytes
//   0x0533e8: 90000768  adrp     x8, #0x13f000
//   0x0533ec: F9472108  ldr      x8, [x8, #0xe40]
//   0x0533f0: 90000769  adrp     x9, #0x13f000
//   0x0533f4: F947F929  ldr      x9, [x9, #0xff0]
static inline uint64_t fde_func_0160_0x0533e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0533e8ULL ^ (static_cast<uint64_t>(0x90000768ULL) << 13);
    acc = (acc + a1 + 0xf9472108ULL) ^ 0x117f50ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0161 | PC: 0x053428 | FDE: 0x117f68 | Size: 72 bytes [_ZN11fast_engine10ReallocateEPNS_6EngineEPvll]
// Hàm FDE #0161 | Địa chỉ PC: 0x053428 | Địa chỉ FDE: 0x117f68 | Kích thước: 72 bytes
//   0x053428: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x05342c: 910003FD  mov      x29, sp
//   0x053430: 90000768  adrp     x8, #0x13f000
//   0x053434: F9472108  ldr      x8, [x8, #0xe40]
static inline uint64_t fde_func_0161_0x053428(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x053428ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x117f68ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0162 | PC: 0x053470 | FDE: 0x117f88 | Size: 36 bytes [_ZN11fast_engine16ResetMemoryStatsEPNS_6EngineE]
// Hàm FDE #0162 | Địa chỉ PC: 0x053470 | Địa chỉ FDE: 0x117f88 | Kích thước: 36 bytes
//   0x053470: 52922908  mov      w8, #0x9148
//   0x053474: 72A00028  movk     w8, #1, lsl #16
//   0x053478: 6F00E400  movi     v0.2d, #0000000000000000
//   0x05347c: 8B080008  add      x8, x0, x8
static inline uint64_t fde_func_0162_0x053470(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x053470ULL ^ (static_cast<uint64_t>(0x52922908ULL) << 13);
    acc = (acc + a1 + 0x72a00028ULL) ^ 0x117f88ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0163 | PC: 0x053494 | FDE: 0x117fc8 | Size: 256 bytes [_ZN11fast_engine16PrintMemoryStatsEPNS_6EngineERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEERNS2_13basic_ostreamIcS5_EE]
// Hàm FDE #0163 | Địa chỉ PC: 0x053494 | Địa chỉ FDE: 0x117fc8 | Kích thước: 256 bytes
//   0x053494: D102C3FF  sub      sp, sp, #0xb0
//   0x053498: F9003BF7  str      x23, [sp, #0x70]
//   0x05349c: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x0534a0: A9094FF4  stp      x20, x19, [sp, #0x90]
static inline uint64_t fde_func_0163_0x053494(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x053494ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf7ULL) ^ 0x117fc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0164 | PC: 0x054910 | FDE: 0x117ff8 | Size: 256 bytes [_ZNSt6__ndk1plIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EEPKS6_RKS9_]
// Hàm FDE #0164 | Địa chỉ PC: 0x054910 | Địa chỉ FDE: 0x117ff8 | Kích thước: 256 bytes
//   0x054910: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x054914: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x054918: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x05491c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0164_0x054910(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x054910ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x117ff8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0165 | PC: 0x054a14 | FDE: 0x117fa0 | Size: 196 bytes [_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm]
// Hàm FDE #0165 | Địa chỉ PC: 0x054a14 | Địa chỉ FDE: 0x117fa0 | Kích thước: 196 bytes
//   0x054a14: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x054a18: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x054a1c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x054a20: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0165_0x054a14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x054a14ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x117fa0ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0166 | PC: 0x054ad8 | FDE: 0x118030 | Size: 256 bytes [_ZNSt6__ndk124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m]
// Hàm FDE #0166 | Địa chỉ PC: 0x054ad8 | Địa chỉ FDE: 0x118030 | Kích thước: 256 bytes
//   0x054ad8: D101C3FF  sub      sp, sp, #0x70
//   0x054adc: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x054ae0: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x054ae4: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0166_0x054ad8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x054ad8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x118030ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0167 | PC: 0x054c78 | FDE: 0x118068 | Size: 256 bytes
// Hàm FDE #0167 | Địa chỉ PC: 0x054c78 | Địa chỉ FDE: 0x118068 | Kích thước: 256 bytes
//   0x054c78: D10203FF  sub      sp, sp, #0x80
//   0x054c7c: F90013FB  str      x27, [sp, #0x20]
//   0x054c80: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x054c84: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0167_0x054c78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x054c78ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x118068ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0168 | PC: 0x054e28 | FDE: 0x1180a0 | Size: 160 bytes [_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE6sentryD2Ev]
// Hàm FDE #0168 | Địa chỉ PC: 0x054e28 | Địa chỉ FDE: 0x1180a0 | Kích thước: 160 bytes
//   0x054e28: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x054e2c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x054e30: 910043FD  add      x29, sp, #0x10
//   0x054e34: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0168_0x054e28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x054e28ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1180a0ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0169 | PC: 0x054ec8 | FDE: 0x1180c8 | Size: 256 bytes [_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE5flushEv]
// Hàm FDE #0169 | Địa chỉ PC: 0x054ec8 | Địa chỉ FDE: 0x1180c8 | Kích thước: 256 bytes
//   0x054ec8: D10143FF  sub      sp, sp, #0x50
//   0x054ecc: F90013F5  str      x21, [sp, #0x20]
//   0x054ed0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x054ed4: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0169_0x054ec8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x054ec8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1180c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0170 | PC: 0x054fe4 | FDE: 0x1182b8 | Size: 256 bytes [_ZN11fast_engine10specialize11CodeQuickenEPNS_7CodeObjE]
// Hàm FDE #0170 | Địa chỉ PC: 0x054fe4 | Địa chỉ FDE: 0x1182b8 | Kích thước: 256 bytes
//   0x054fe4: D105C3FF  sub      sp, sp, #0x170
//   0x054fe8: FD007BEA  str      d10, [sp, #0xf0]
//   0x054fec: 6D1023E9  stp      d9, d8, [sp, #0x100]
//   0x054ff0: A9116FFC  stp      x28, x27, [sp, #0x110]
static inline uint64_t fde_func_0170_0x054fe4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x054fe4ULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xfd007beaULL) ^ 0x1182b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0171 | PC: 0x055c40 | FDE: 0x1180f0 | Size: 256 bytes
// Hàm FDE #0171 | Địa chỉ PC: 0x055c40 | Địa chỉ FDE: 0x1180f0 | Kích thước: 256 bytes
//   0x055c40: D101C3FF  sub      sp, sp, #0x70
//   0x055c44: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x055c48: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x055c4c: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_0171_0x055c40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x055c40ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x1180f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0172 | PC: 0x056028 | FDE: 0x1182f8 | Size: 256 bytes [_ZN11fast_engine10specialize13CodeQuickenV2EPNS_7CodeObjE]
// Hàm FDE #0172 | Địa chỉ PC: 0x056028 | Địa chỉ FDE: 0x1182f8 | Kích thước: 256 bytes
//   0x056028: D10483FF  sub      sp, sp, #0x120
//   0x05602c: FD0053EA  str      d10, [sp, #0xa0]
//   0x056030: 6D0B23E9  stp      d9, d8, [sp, #0xb0]
//   0x056034: A90C6FFC  stp      x28, x27, [sp, #0xc0]
static inline uint64_t fde_func_0172_0x056028(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x056028ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xfd0053eaULL) ^ 0x1182f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0173 | PC: 0x056ca4 | FDE: 0x118120 | Size: 208 bytes [_ZNSt6__ndk16vectorIiNS_9allocatorIiEEE7reserveEm]
// Hàm FDE #0173 | Địa chỉ PC: 0x056ca4 | Địa chỉ FDE: 0x118120 | Kích thước: 208 bytes
//   0x056ca4: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x056ca8: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x056cac: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x056cb0: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0173_0x056ca4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x056ca4ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x118120ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #0174 | PC: 0x056d74 | FDE: 0x118148 | Size: 256 bytes [_ZN11fast_engine10specialize8LoadAttrEPNS_3ObjES2_PtPNS_6EngineE]
// Hàm FDE #0174 | Địa chỉ PC: 0x056d74 | Địa chỉ FDE: 0x118148 | Kích thước: 256 bytes
//   0x056d74: D10183FF  sub      sp, sp, #0x60
//   0x056d78: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x056d7c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x056d80: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0174_0x056d74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x056d74ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x118148ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0175 | PC: 0x056f88 | FDE: 0x118170 | Size: 256 bytes
// Hàm FDE #0175 | Địa chỉ PC: 0x056f88 | Địa chỉ FDE: 0x118170 | Kích thước: 256 bytes
//   0x056f88: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x056f8c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x056f90: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x056f94: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0175_0x056f88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x056f88ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x118170ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0176 | PC: 0x0570d4 | FDE: 0x118198 | Size: 256 bytes [_ZN11fast_engine10specialize9StoreAttrEPNS_3ObjES2_PtPNS_6EngineE]
// Hàm FDE #0176 | Địa chỉ PC: 0x0570d4 | Địa chỉ FDE: 0x118198 | Kích thước: 256 bytes
//   0x0570d4: D10143FF  sub      sp, sp, #0x50
//   0x0570d8: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0570dc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0570e0: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0176_0x0570d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0570d4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x118198ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0177 | PC: 0x057234 | FDE: 0x1181c0 | Size: 256 bytes [_ZN11fast_engine10specialize10LoadMethodEPNS_3ObjES2_PtPNS_6EngineE]
// Hàm FDE #0177 | Địa chỉ PC: 0x057234 | Địa chỉ FDE: 0x1181c0 | Kích thước: 256 bytes
//   0x057234: D10183FF  sub      sp, sp, #0x60
//   0x057238: F90013F7  str      x23, [sp, #0x20]
//   0x05723c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x057240: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0177_0x057234(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x057234ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1181c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0178 | PC: 0x0573dc | FDE: 0x1181e8 | Size: 256 bytes [_ZN11fast_engine10specialize10LoadGlobalEPNS_7DictObjES2_PtPNS_6StrObjEPNS_6EngineE]
// Hàm FDE #0178 | Địa chỉ PC: 0x0573dc | Địa chỉ FDE: 0x1181e8 | Kích thước: 256 bytes
//   0x0573dc: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0573e0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0573e4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0573e8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0178_0x0573dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0573dcULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1181e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0179 | PC: 0x057554 | FDE: 0x118210 | Size: 196 bytes [_ZN11fast_engine10specialize12BinarySubscrEPNS_3ObjES2_PtPNS_6EngineE]
// Hàm FDE #0179 | Địa chỉ PC: 0x057554 | Địa chỉ FDE: 0x118210 | Kích thước: 196 bytes
//   0x057554: 90000749  adrp     x9, #0x13f000
//   0x057558: F9401408  ldr      x8, [x0, #0x28]
//   0x05755c: F9462929  ldr      x9, [x9, #0xc50]
//   0x057560: F9400129  ldr      x9, [x9]
static inline uint64_t fde_func_0179_0x057554(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x057554ULL ^ (static_cast<uint64_t>(0x90000749ULL) << 13);
    acc = (acc + a1 + 0xf9401408ULL) ^ 0x118210ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0180 | PC: 0x057618 | FDE: 0x118228 | Size: 248 bytes [_ZN11fast_engine10specialize11StoreSubscrEPNS_3ObjES2_PtPNS_6EngineE]
// Hàm FDE #0180 | Địa chỉ PC: 0x057618 | Địa chỉ FDE: 0x118228 | Kích thước: 248 bytes
//   0x057618: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x05761c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x057620: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x057624: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0180_0x057618(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x057618ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x118228ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0181 | PC: 0x057710 | FDE: 0x118338 | Size: 256 bytes [_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeIiiEENS_22__unordered_map_hasherIiS2_NS_4hashIiEELb1EEENS_21__unordered_map_equalIiS2_NS_8equal_toIiEELb1EEENS_9allocatorIS2_EEE25__emplace_unique_key_argsIiJRKNS_21piecewise_construct_tENS_5tupleIJRKiEEENSI_IJEEEEEENS_4pairINS_15__hash_iteratorIPNS_11__hash_nodeIS2_PvEEEEbEERKT_DpOT0_]
// Hàm FDE #0181 | Địa chỉ PC: 0x057710 | Địa chỉ FDE: 0x118338 | Kích thước: 256 bytes
//   0x057710: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x057714: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x057718: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05771c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0181_0x057710(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x057710ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x118338ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0182 | PC: 0x05792c | FDE: 0x118248 | Size: 228 bytes [_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeIiiEENS_22__unordered_map_hasherIiS2_NS_4hashIiEELb1EEENS_21__unordered_map_equalIiS2_NS_8equal_toIiEELb1EEENS_9allocatorIS2_EEE6rehashEm]
// Hàm FDE #0182 | Địa chỉ PC: 0x05792c | Địa chỉ FDE: 0x118248 | Kích thước: 228 bytes
//   0x05792c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x057930: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x057934: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x057938: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0182_0x05792c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05792cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x118248ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #0183 | PC: 0x057a10 | FDE: 0x118268 | Size: 256 bytes [_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeIiiEENS_22__unordered_map_hasherIiS2_NS_4hashIiEELb1EEENS_21__unordered_map_equalIiS2_NS_8equal_toIiEELb1EEENS_9allocatorIS2_EEE8__rehashEm]
// Hàm FDE #0183 | Địa chỉ PC: 0x057a10 | Địa chỉ FDE: 0x118268 | Kích thước: 256 bytes
//   0x057a10: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x057a14: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x057a18: 910043FD  add      x29, sp, #0x10
//   0x057a1c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0183_0x057a10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x057a10ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x118268ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0184 | PC: 0x057b98 | FDE: 0x118288 | Size: 256 bytes [_ZNSt6__ndk16vectorIiNS_9allocatorIiEEE21__push_back_slow_pathIRKiEEvOT_]
// Hàm FDE #0184 | Địa chỉ PC: 0x057b98 | Địa chỉ FDE: 0x118288 | Kích thước: 256 bytes
//   0x057b98: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x057b9c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x057ba0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x057ba4: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0184_0x057b98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x057b98ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x118288ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0185 | PC: 0x057ca4 | FDE: 0x1189b0 | Size: 256 bytes [_ZN11fast_engine10PathAppendERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEES8_]
// Hàm FDE #0185 | Địa chỉ PC: 0x057ca4 | Địa chỉ FDE: 0x1189b0 | Kích thước: 256 bytes
//   0x057ca4: D10143FF  sub      sp, sp, #0x50
//   0x057ca8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x057cac: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x057cb0: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0185_0x057ca4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x057ca4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1189b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0186 | PC: 0x057db8 | FDE: 0x1189e0 | Size: 256 bytes [_ZN11fast_engine9StrFormatEPKcz]
// Hàm FDE #0186 | Địa chỉ PC: 0x057db8 | Địa chỉ FDE: 0x1189e0 | Kích thước: 256 bytes
//   0x057db8: D10583FF  sub      sp, sp, #0x160
//   0x057dbc: F90093FC  str      x28, [sp, #0x120]
//   0x057dc0: A91357F6  stp      x22, x21, [sp, #0x130]
//   0x057dc4: A9144FF4  stp      x20, x19, [sp, #0x140]
static inline uint64_t fde_func_0186_0x057db8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x057db8ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf90093fcULL) ^ 0x1189e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0187 | PC: 0x057fe4 | FDE: 0x118368 | Size: 72 bytes [_ZN11fast_engine9TimestampEv]
// Hàm FDE #0187 | Địa chỉ PC: 0x057fe4 | Địa chỉ FDE: 0x118368 | Kích thước: 72 bytes
//   0x057fe4: D10083FF  sub      sp, sp, #0x20
//   0x057fe8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x057fec: 910043FD  add      x29, sp, #0x10
//   0x057ff0: 910003E0  mov      x0, sp
static inline uint64_t fde_func_0187_0x057fe4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x057fe4ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x118368ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0188 | PC: 0x05802c | FDE: 0x118a10 | Size: 256 bytes [_ZN11fast_engine16FormatTimeStringEd]
// Hàm FDE #0188 | Địa chỉ PC: 0x05802c | Địa chỉ FDE: 0x118a10 | Kích thước: 256 bytes
//   0x05802c: D10703FF  sub      sp, sp, #0x1c0
//   0x058030: FD00ABE8  str      d8, [sp, #0x150]
//   0x058034: A9166FFC  stp      x28, x27, [sp, #0x160]
//   0x058038: A91767FA  stp      x26, x25, [sp, #0x170]
static inline uint64_t fde_func_0188_0x05802c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05802cULL ^ (static_cast<uint64_t>(0xd10703ffULL) << 13);
    acc = (acc + a1 + 0xfd00abe8ULL) ^ 0x118a10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0189 | PC: 0x058340 | FDE: 0x118a48 | Size: 256 bytes [_ZNSt6__ndk1lsIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_RKNS_9__iom_t10IS4_EE]
// Hàm FDE #0189 | Địa chỉ PC: 0x058340 | Địa chỉ FDE: 0x118a48 | Kích thước: 256 bytes
//   0x058340: D101C3FF  sub      sp, sp, #0x70
//   0x058344: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x058348: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x05834c: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0189_0x058340(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x058340ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x118a48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0190 | PC: 0x058514 | FDE: 0x118388 | Size: 116 bytes [_ZNSt6__ndk118basic_stringstreamIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev]
// Hàm FDE #0190 | Địa chỉ PC: 0x058514 | Địa chỉ FDE: 0x118388 | Kích thước: 116 bytes
//   0x058514: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x058518: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05851c: 910043FD  add      x29, sp, #0x10
//   0x058520: F0000728  adrp     x8, #0x13f000
static inline uint64_t fde_func_0190_0x058514(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x058514ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x118388ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0191 | PC: 0x058588 | FDE: 0x1183a8 | Size: 96 bytes [_ZN11fast_engine9FileExistERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEERb]
// Hàm FDE #0191 | Địa chỉ PC: 0x058588 | Địa chỉ FDE: 0x1183a8 | Kích thước: 96 bytes
//   0x058588: D10283FF  sub      sp, sp, #0xa0
//   0x05858c: F90043F3  str      x19, [sp, #0x80]
//   0x058590: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x058594: 910243FD  add      x29, sp, #0x90
static inline uint64_t fde_func_0191_0x058588(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x058588ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90043f3ULL) ^ 0x1183a8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0192 | PC: 0x0585e8 | FDE: 0x118a80 | Size: 256 bytes [_ZN11fast_engine8SubFilesERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE]
// Hàm FDE #0192 | Địa chỉ PC: 0x0585e8 | Địa chỉ FDE: 0x118a80 | Kích thước: 256 bytes
//   0x0585e8: D10283FF  sub      sp, sp, #0xa0
//   0x0585ec: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x0585f0: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0585f4: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0192_0x0585e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0585e8ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x118a80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0193 | PC: 0x058870 | FDE: 0x118ab8 | Size: 256 bytes [_ZN11fast_engine10FileStringERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE]
// Hàm FDE #0193 | Địa chỉ PC: 0x058870 | Địa chỉ FDE: 0x118ab8 | Kích thước: 256 bytes
//   0x058870: D10703FF  sub      sp, sp, #0x1c0
//   0x058874: F900BBFC  str      x28, [sp, #0x170]
//   0x058878: A9185FF8  stp      x24, x23, [sp, #0x180]
//   0x05887c: A91957F6  stp      x22, x21, [sp, #0x190]
static inline uint64_t fde_func_0193_0x058870(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x058870ULL ^ (static_cast<uint64_t>(0xd10703ffULL) << 13);
    acc = (acc + a1 + 0xf900bbfcULL) ^ 0x118ab8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0194 | PC: 0x058a3c | FDE: 0x118ae8 | Size: 256 bytes
// Hàm FDE #0194 | Địa chỉ PC: 0x058a3c | Địa chỉ FDE: 0x118ae8 | Kích thước: 256 bytes
//   0x058a3c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x058a40: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x058a44: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x058a48: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0194_0x058a3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x058a3cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x118ae8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0195 | PC: 0x058be0 | FDE: 0x1183c8 | Size: 60 bytes [_ZNSt6__ndk114basic_ifstreamIcNS_11char_traitsIcEEED1Ev]
// Hàm FDE #0195 | Địa chỉ PC: 0x058be0 | Địa chỉ FDE: 0x1183c8 | Kích thước: 60 bytes
//   0x058be0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x058be4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x058be8: 910043FD  add      x29, sp, #0x10
//   0x058bec: F0000728  adrp     x8, #0x13f000
static inline uint64_t fde_func_0195_0x058be0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x058be0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1183c8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0196 | PC: 0x058c1c | FDE: 0x1183e8 | Size: 128 bytes [_ZN11fast_engine9HasSuffixERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEES8_]
// Hàm FDE #0196 | Địa chỉ PC: 0x058c1c | Địa chỉ FDE: 0x1183e8 | Kích thước: 128 bytes
//   0x058c1c: 39400009  ldrb     w9, [x0]
//   0x058c20: F940040A  ldr      x10, [x0, #8]
//   0x058c24: 39400028  ldrb     w8, [x1]
//   0x058c28: F940042C  ldr      x12, [x1, #8]
static inline uint64_t fde_func_0196_0x058c1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x058c1cULL ^ (static_cast<uint64_t>(0x39400009ULL) << 13);
    acc = (acc + a1 + 0xf940040aULL) ^ 0x1183e8ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0197 | PC: 0x058c9c | FDE: 0x118b18 | Size: 256 bytes [_ZN11fast_engine5LTrimERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE]
// Hàm FDE #0197 | Địa chỉ PC: 0x058c9c | Địa chỉ FDE: 0x118b18 | Kích thước: 256 bytes
//   0x058c9c: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x058ca0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x058ca4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x058ca8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0197_0x058c9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x058c9cULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x118b18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0198 | PC: 0x058dbc | FDE: 0x118b48 | Size: 256 bytes [_ZN11fast_engine5SplitERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEES8_l]
// Hàm FDE #0198 | Địa chỉ PC: 0x058dbc | Địa chỉ FDE: 0x118b48 | Kích thước: 256 bytes
//   0x058dbc: D10443FF  sub      sp, sp, #0x110
//   0x058dc0: A90B6FFC  stp      x28, x27, [sp, #0xb0]
//   0x058dc4: A90C67FA  stp      x26, x25, [sp, #0xc0]
//   0x058dc8: A90D5FF8  stp      x24, x23, [sp, #0xd0]
static inline uint64_t fde_func_0198_0x058dbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x058dbcULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90b6ffcULL) ^ 0x118b48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0199 | PC: 0x0594f4 | FDE: 0x118b80 | Size: 256 bytes
// Hàm FDE #0199 | Địa chỉ PC: 0x0594f4 | Địa chỉ FDE: 0x118b80 | Kích thước: 256 bytes
//   0x0594f4: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0594f8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0594fc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x059500: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0199_0x0594f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0594f4ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x118b80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0200 | PC: 0x059610 | FDE: 0x118bb0 | Size: 256 bytes [_ZN11fast_engine17SplitByWhiteSpaceERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEEl]
// Hàm FDE #0200 | Địa chỉ PC: 0x059610 | Địa chỉ FDE: 0x118bb0 | Kích thước: 256 bytes
//   0x059610: D102C3FF  sub      sp, sp, #0xb0
//   0x059614: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x059618: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x05961c: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_0200_0x059610(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x059610ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x118bb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0201 | PC: 0x059b54 | FDE: 0x118400 | Size: 120 bytes [_ZThn16_NSt6__ndk118basic_stringstreamIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev]
// Hàm FDE #0201 | Địa chỉ PC: 0x059b54 | Địa chỉ FDE: 0x118400 | Kích thước: 120 bytes
//   0x059b54: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x059b58: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x059b5c: 910043FD  add      x29, sp, #0x10
//   0x059b60: D0000728  adrp     x8, #0x13f000
static inline uint64_t fde_func_0201_0x059b54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x059b54ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x118400ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0202 | PC: 0x059bcc | FDE: 0x118420 | Size: 128 bytes [_ZTv0_n24_NSt6__ndk118basic_stringstreamIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev]
// Hàm FDE #0202 | Địa chỉ PC: 0x059bcc | Địa chỉ FDE: 0x118420 | Kích thước: 128 bytes
//   0x059bcc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x059bd0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x059bd4: 910043FD  add      x29, sp, #0x10
//   0x059bd8: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0202_0x059bcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x059bccULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x118420ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0203 | PC: 0x059c4c | FDE: 0x118440 | Size: 8 bytes [_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEED1Ev]
// Hàm FDE #0203 | Địa chỉ PC: 0x059c4c | Địa chỉ FDE: 0x118440 | Kích thước: 8 bytes
//   0x059c4c: 91004000  add      x0, x0, #0x10
//   0x059c50: 17FFA2F0  b        #0x42810
static inline uint64_t fde_func_0203_0x059c4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x059c4cULL ^ (static_cast<uint64_t>(0x91004000ULL) << 13);
    acc = (acc + a1 + 0x17ffa2f0ULL) ^ 0x118440ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0204 | PC: 0x059c54 | FDE: 0x118458 | Size: 40 bytes [_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEED0Ev]
// Hàm FDE #0204 | Địa chỉ PC: 0x059c54 | Địa chỉ FDE: 0x118458 | Kích thước: 40 bytes
//   0x059c54: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x059c58: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x059c5c: 910043FD  add      x29, sp, #0x10
//   0x059c60: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0204_0x059c54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x059c54ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x118458ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0205 | PC: 0x059c7c | FDE: 0x118478 | Size: 20 bytes [_ZTv0_n24_NSt6__ndk113basic_istreamIcNS_11char_traitsIcEEED1Ev]
// Hàm FDE #0205 | Địa chỉ PC: 0x059c7c | Địa chỉ FDE: 0x118478 | Kích thước: 20 bytes
//   0x059c7c: F9400008  ldr      x8, [x0]
//   0x059c80: F85E8108  ldur     x8, [x8, #-0x18]
//   0x059c84: 8B080008  add      x8, x0, x8
//   0x059c88: 91004100  add      x0, x8, #0x10
static inline uint64_t fde_func_0205_0x059c7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x059c7cULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf85e8108ULL) ^ 0x118478ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0206 | PC: 0x059c90 | FDE: 0x118490 | Size: 48 bytes [_ZTv0_n24_NSt6__ndk113basic_istreamIcNS_11char_traitsIcEEED0Ev]
// Hàm FDE #0206 | Địa chỉ PC: 0x059c90 | Địa chỉ FDE: 0x118490 | Kích thước: 48 bytes
//   0x059c90: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x059c94: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x059c98: 910043FD  add      x29, sp, #0x10
//   0x059c9c: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0206_0x059c90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x059c90ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x118490ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0207 | PC: 0x059cc0 | FDE: 0x1184b0 | Size: 124 bytes [_ZNSt6__ndk118basic_stringstreamIcNS_11char_traitsIcEENS_9allocatorIcEEED0Ev]
// Hàm FDE #0207 | Địa chỉ PC: 0x059cc0 | Địa chỉ FDE: 0x1184b0 | Kích thước: 124 bytes
//   0x059cc0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x059cc4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x059cc8: 910043FD  add      x29, sp, #0x10
//   0x059ccc: D0000728  adrp     x8, #0x13f000
static inline uint64_t fde_func_0207_0x059cc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x059cc0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1184b0ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0208 | PC: 0x059d3c | FDE: 0x1184d0 | Size: 128 bytes [_ZThn16_NSt6__ndk118basic_stringstreamIcNS_11char_traitsIcEENS_9allocatorIcEEED0Ev]
// Hàm FDE #0208 | Địa chỉ PC: 0x059d3c | Địa chỉ FDE: 0x1184d0 | Kích thước: 128 bytes
//   0x059d3c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x059d40: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x059d44: 910043FD  add      x29, sp, #0x10
//   0x059d48: D0000728  adrp     x8, #0x13f000
static inline uint64_t fde_func_0208_0x059d3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x059d3cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1184d0ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0209 | PC: 0x059dbc | FDE: 0x1184f0 | Size: 136 bytes [_ZTv0_n24_NSt6__ndk118basic_stringstreamIcNS_11char_traitsIcEENS_9allocatorIcEEED0Ev]
// Hàm FDE #0209 | Địa chỉ PC: 0x059dbc | Địa chỉ FDE: 0x1184f0 | Kích thước: 136 bytes
//   0x059dbc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x059dc0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x059dc4: 910043FD  add      x29, sp, #0x10
//   0x059dc8: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0209_0x059dbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x059dbcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1184f0ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #0210 | PC: 0x059e44 | FDE: 0x118510 | Size: 80 bytes [_ZNSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEED2Ev]
// Hàm FDE #0210 | Địa chỉ PC: 0x059e44 | Địa chỉ FDE: 0x118510 | Kích thước: 80 bytes
//   0x059e44: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x059e48: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x059e4c: 910043FD  add      x29, sp, #0x10
//   0x059e50: D0000729  adrp     x9, #0x13f000
static inline uint64_t fde_func_0210_0x059e44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x059e44ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x118510ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0211 | PC: 0x059e94 | FDE: 0x118530 | Size: 88 bytes [_ZNSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEED0Ev]
// Hàm FDE #0211 | Địa chỉ PC: 0x059e94 | Địa chỉ FDE: 0x118530 | Kích thước: 88 bytes
//   0x059e94: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x059e98: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x059e9c: 910043FD  add      x29, sp, #0x10
//   0x059ea0: D0000729  adrp     x9, #0x13f000
static inline uint64_t fde_func_0211_0x059e94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x059e94ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x118530ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0212 | PC: 0x059eec | FDE: 0x118550 | Size: 4 bytes [_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE5imbueERKNS_6localeE]
// Hàm FDE #0212 | Địa chỉ PC: 0x059eec | Địa chỉ FDE: 0x118550 | Kích thước: 4 bytes
//   0x059eec: D65F03C0  ret      
static inline uint64_t fde_func_0212_0x059eec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x059eecULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x118550ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0213 | PC: 0x059ef0 | FDE: 0x118568 | Size: 4 bytes [_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE6setbufEPcl]
// Hàm FDE #0213 | Địa chỉ PC: 0x059ef0 | Địa chỉ FDE: 0x118568 | Kích thước: 4 bytes
//   0x059ef0: D65F03C0  ret      
static inline uint64_t fde_func_0213_0x059ef0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x059ef0ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xf9402c08ULL) ^ 0x118568ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0214 | PC: 0x059ef4 | FDE: 0x118580 | Size: 256 bytes [_ZNSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE7seekoffExNS_8ios_base7seekdirEj]
// Hàm FDE #0214 | Địa chỉ PC: 0x059ef4 | Địa chỉ FDE: 0x118580 | Kích thước: 256 bytes
//   0x059ef4: F9402C08  ldr      x8, [x0, #0x58]
//   0x059ef8: F9401809  ldr      x9, [x0, #0x30]
//   0x059efc: EB09011F  cmp      x8, x9
//   0x059f00: 54000062  b.hs     #0x59f0c
static inline uint64_t fde_func_0214_0x059ef4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x059ef4ULL ^ (static_cast<uint64_t>(0xf9402c08ULL) << 13);
    acc = (acc + a1 + 0xf9401809ULL) ^ 0x118580ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0215 | PC: 0x059ff4 | FDE: 0x118598 | Size: 20 bytes
// Hàm FDE #0215 | Địa chỉ PC: 0x059ff4 | Địa chỉ FDE: 0x118598 | Kích thước: 20 bytes
//   0x059ff4: F9400008  ldr      x8, [x0]
//   0x059ff8: AA0203E1  mov      x1, x2
//   0x059ffc: 2A1F03E2  mov      w2, wzr
//   0x05a000: F9401104  ldr      x4, [x8, #0x20]
static inline uint64_t fde_func_0215_0x059ff4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x059ff4ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xaa0203e1ULL) ^ 0x118598ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0216 | PC: 0x05a008 | FDE: 0x1185b0 | Size: 8 bytes [_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE4syncEv]
// Hàm FDE #0216 | Địa chỉ PC: 0x05a008 | Địa chỉ FDE: 0x1185b0 | Kích thước: 8 bytes
//   0x05a008: 2A1F03E0  mov      w0, wzr
//   0x05a00c: D65F03C0  ret      
static inline uint64_t fde_func_0216_0x05a008(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05a008ULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1185b0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0217 | PC: 0x05a010 | FDE: 0x1185c8 | Size: 8 bytes [_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE9showmanycEv]
// Hàm FDE #0217 | Địa chỉ PC: 0x05a010 | Địa chỉ FDE: 0x1185c8 | Kích thước: 8 bytes
//   0x05a010: AA1F03E0  mov      x0, xzr
//   0x05a014: D65F03C0  ret      
static inline uint64_t fde_func_0217_0x05a010(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05a010ULL ^ (static_cast<uint64_t>(0xaa1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1185c8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0218 | PC: 0x05a018 | FDE: 0x1185e0 | Size: 200 bytes [_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE6xsgetnEPcl]
// Hàm FDE #0218 | Địa chỉ PC: 0x05a018 | Địa chỉ FDE: 0x1185e0 | Kích thước: 200 bytes
//   0x05a018: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x05a01c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05a020: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05a024: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0218_0x05a018(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05a018ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1185e0ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0219 | PC: 0x05a0e0 | FDE: 0x118608 | Size: 80 bytes [_ZNSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE9underflowEv]
// Hàm FDE #0219 | Địa chỉ PC: 0x05a0e0 | Địa chỉ FDE: 0x118608 | Kích thước: 80 bytes
//   0x05a0e0: F9402C08  ldr      x8, [x0, #0x58]
//   0x05a0e4: F9401809  ldr      x9, [x0, #0x30]
//   0x05a0e8: EB09011F  cmp      x8, x9
//   0x05a0ec: 54000062  b.hs     #0x5a0f8
static inline uint64_t fde_func_0219_0x05a0e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05a0e0ULL ^ (static_cast<uint64_t>(0xf9402c08ULL) << 13);
    acc = (acc + a1 + 0xf9401809ULL) ^ 0x118608ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0220 | PC: 0x05a130 | FDE: 0x118620 | Size: 64 bytes [_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE5uflowEv]
// Hàm FDE #0220 | Địa chỉ PC: 0x05a130 | Địa chỉ FDE: 0x118620 | Kích thước: 64 bytes
//   0x05a130: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x05a134: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05a138: 910043FD  add      x29, sp, #0x10
//   0x05a13c: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0220_0x05a130(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05a130ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x118620ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0221 | PC: 0x05a170 | FDE: 0x118640 | Size: 112 bytes [_ZNSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE9pbackfailEi]
// Hàm FDE #0221 | Địa chỉ PC: 0x05a170 | Địa chỉ FDE: 0x118640 | Kích thước: 112 bytes
//   0x05a170: F9402C09  ldr      x9, [x0, #0x58]
//   0x05a174: F940180A  ldr      x10, [x0, #0x30]
//   0x05a178: AA0003E8  mov      x8, x0
//   0x05a17c: 2A0103E0  mov      w0, w1
static inline uint64_t fde_func_0221_0x05a170(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05a170ULL ^ (static_cast<uint64_t>(0xf9402c09ULL) << 13);
    acc = (acc + a1 + 0xf940180aULL) ^ 0x118640ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0222 | PC: 0x05a1e0 | FDE: 0x118658 | Size: 200 bytes [_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE6xsputnEPKcl]
// Hàm FDE #0222 | Địa chỉ PC: 0x05a1e0 | Địa chỉ FDE: 0x118658 | Kích thước: 200 bytes
//   0x05a1e0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x05a1e4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05a1e8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05a1ec: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0222_0x05a1e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05a1e0ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x118658ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0223 | PC: 0x05a2a8 | FDE: 0x118be8 | Size: 256 bytes [_ZNSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE8overflowEi]
// Hàm FDE #0223 | Địa chỉ PC: 0x05a2a8 | Địa chỉ FDE: 0x118be8 | Kích thước: 256 bytes
//   0x05a2a8: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x05a2ac: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x05a2b0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x05a2b4: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0223_0x05a2a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05a2a8ULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x118be8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0224 | PC: 0x05a4dc | FDE: 0x118680 | Size: 20 bytes [_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED2Ev]
// Hàm FDE #0224 | Địa chỉ PC: 0x05a4dc | Địa chỉ FDE: 0x118680 | Kích thước: 20 bytes
//   0x05a4dc: B0000728  adrp     x8, #0x13f000
//   0x05a4e0: F9449508  ldr      x8, [x8, #0x928]
//   0x05a4e4: 91004108  add      x8, x8, #0x10
//   0x05a4e8: F8008408  str      x8, [x0], #8
static inline uint64_t fde_func_0224_0x05a4dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05a4dcULL ^ (static_cast<uint64_t>(0xb0000728ULL) << 13);
    acc = (acc + a1 + 0xf9449508ULL) ^ 0x118680ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0225 | PC: 0x05a4f0 | FDE: 0x118698 | Size: 52 bytes [_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED0Ev]
// Hàm FDE #0225 | Địa chỉ PC: 0x05a4f0 | Địa chỉ FDE: 0x118698 | Kích thước: 52 bytes
//   0x05a4f0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x05a4f4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05a4f8: 910043FD  add      x29, sp, #0x10
//   0x05a4fc: B0000728  adrp     x8, #0x13f000
static inline uint64_t fde_func_0225_0x05a4f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05a4f0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x118698ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0226 | PC: 0x05a524 | FDE: 0x1186b8 | Size: 12 bytes [_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE7seekoffExNS_8ios_base7seekdirEj]
// Hàm FDE #0226 | Địa chỉ PC: 0x05a524 | Địa chỉ FDE: 0x1186b8 | Kích thước: 12 bytes
//   0x05a524: 92800001  mov      x1, #-1
//   0x05a528: AA1F03E0  mov      x0, xzr
//   0x05a52c: D65F03C0  ret      
static inline uint64_t fde_func_0226_0x05a524(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05a524ULL ^ (static_cast<uint64_t>(0x92800001ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e0ULL) ^ 0x1186b8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0227 | PC: 0x05a530 | FDE: 0x1186d0 | Size: 12 bytes [_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE7seekposENS_4fposI9mbstate_tEEj]
// Hàm FDE #0227 | Địa chỉ PC: 0x05a530 | Địa chỉ FDE: 0x1186d0 | Kích thước: 12 bytes
//   0x05a530: 92800001  mov      x1, #-1
//   0x05a534: AA1F03E0  mov      x0, xzr
//   0x05a538: D65F03C0  ret      
static inline uint64_t fde_func_0227_0x05a530(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05a530ULL ^ (static_cast<uint64_t>(0x92800001ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e0ULL) ^ 0x1186d0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0228 | PC: 0x05a53c | FDE: 0x1186e8 | Size: 8 bytes [_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE9underflowEv]
// Hàm FDE #0228 | Địa chỉ PC: 0x05a53c | Địa chỉ FDE: 0x1186e8 | Kích thước: 8 bytes
//   0x05a53c: 12800000  mov      w0, #-1
//   0x05a540: D65F03C0  ret      
static inline uint64_t fde_func_0228_0x05a53c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05a53cULL ^ (static_cast<uint64_t>(0x12800000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1186e8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0229 | PC: 0x05a544 | FDE: 0x118700 | Size: 8 bytes [_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE9pbackfailEi]
// Hàm FDE #0229 | Địa chỉ PC: 0x05a544 | Địa chỉ FDE: 0x118700 | Kích thước: 8 bytes
//   0x05a544: 12800000  mov      w0, #-1
//   0x05a548: D65F03C0  ret      
static inline uint64_t fde_func_0229_0x05a544(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05a544ULL ^ (static_cast<uint64_t>(0x12800000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x118700ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0230 | PC: 0x05a54c | FDE: 0x118718 | Size: 8 bytes [_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE8overflowEi]
// Hàm FDE #0230 | Địa chỉ PC: 0x05a54c | Địa chỉ FDE: 0x118718 | Kích thước: 8 bytes
//   0x05a54c: 12800000  mov      w0, #-1
//   0x05a550: D65F03C0  ret      
static inline uint64_t fde_func_0230_0x05a54c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05a54cULL ^ (static_cast<uint64_t>(0x12800000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x118718ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0231 | PC: 0x05a554 | FDE: 0x118730 | Size: 72 bytes [_ZTv0_n24_NSt6__ndk114basic_ifstreamIcNS_11char_traitsIcEEED1Ev]
// Hàm FDE #0231 | Địa chỉ PC: 0x05a554 | Địa chỉ FDE: 0x118730 | Kích thước: 72 bytes
//   0x05a554: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x05a558: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05a55c: 910043FD  add      x29, sp, #0x10
//   0x05a560: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0231_0x05a554(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05a554ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x118730ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0232 | PC: 0x05a59c | FDE: 0x118750 | Size: 72 bytes [_ZNSt6__ndk114basic_ifstreamIcNS_11char_traitsIcEEED0Ev]
// Hàm FDE #0232 | Địa chỉ PC: 0x05a59c | Địa chỉ FDE: 0x118750 | Kích thước: 72 bytes
//   0x05a59c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x05a5a0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05a5a4: 910043FD  add      x29, sp, #0x10
//   0x05a5a8: B0000728  adrp     x8, #0x13f000
static inline uint64_t fde_func_0232_0x05a59c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05a59cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x118750ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0233 | PC: 0x05a5e4 | FDE: 0x118770 | Size: 84 bytes [_ZTv0_n24_NSt6__ndk114basic_ifstreamIcNS_11char_traitsIcEEED0Ev]
// Hàm FDE #0233 | Địa chỉ PC: 0x05a5e4 | Địa chỉ FDE: 0x118770 | Kích thước: 84 bytes
//   0x05a5e4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x05a5e8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05a5ec: 910043FD  add      x29, sp, #0x10
//   0x05a5f0: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0233_0x05a5e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05a5e4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x118770ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0234 | PC: 0x05a638 | FDE: 0x118c20 | Size: 220 bytes [_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEED2Ev]
// Hàm FDE #0234 | Địa chỉ PC: 0x05a638 | Địa chỉ FDE: 0x118c20 | Kích thước: 220 bytes
//   0x05a638: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x05a63c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05a640: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05a644: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0234_0x05a638(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05a638ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x118c20ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #0235 | PC: 0x05a714 | FDE: 0x118790 | Size: 36 bytes [_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEED0Ev]
// Hàm FDE #0235 | Địa chỉ PC: 0x05a714 | Địa chỉ FDE: 0x118790 | Kích thước: 36 bytes
//   0x05a714: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x05a718: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05a71c: 910043FD  add      x29, sp, #0x10
//   0x05a720: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0235_0x05a714(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05a714ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x118790ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0236 | PC: 0x05a738 | FDE: 0x1187b0 | Size: 240 bytes [_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE5imbueERKNS_6localeE]
// Hàm FDE #0236 | Địa chỉ PC: 0x05a738 | Địa chỉ FDE: 0x1187b0 | Kích thước: 240 bytes
//   0x05a738: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x05a73c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05a740: 910043FD  add      x29, sp, #0x10
//   0x05a744: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0236_0x05a738(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05a738ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1187b0ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #0237 | PC: 0x05a828 | FDE: 0x1187d0 | Size: 248 bytes [_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE6setbufEPcl]
// Hàm FDE #0237 | Địa chỉ PC: 0x05a828 | Địa chỉ FDE: 0x1187d0 | Kích thước: 248 bytes
//   0x05a828: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x05a82c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05a830: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05a834: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0237_0x05a828(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05a828ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1187d0ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0238 | PC: 0x05a920 | FDE: 0x1187f8 | Size: 192 bytes [_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE7seekoffExNS_8ios_base7seekdirEj]
// Hàm FDE #0238 | Địa chỉ PC: 0x05a920 | Địa chỉ FDE: 0x1187f8 | Kích thước: 192 bytes
//   0x05a920: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x05a924: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05a928: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05a92c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0238_0x05a920(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05a920ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1187f8ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #0239 | PC: 0x05a9e0 | FDE: 0x118820 | Size: 112 bytes [_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE7seekposENS_4fposI9mbstate_tEEj]
// Hàm FDE #0239 | Địa chỉ PC: 0x05a9e0 | Địa chỉ FDE: 0x118820 | Kích thước: 112 bytes
//   0x05a9e0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x05a9e4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05a9e8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05a9ec: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0239_0x05a9e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05a9e0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x118820ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0240 | PC: 0x05aa50 | FDE: 0x118840 | Size: 256 bytes [_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE4syncEv]
// Hàm FDE #0240 | Địa chỉ PC: 0x05aa50 | Địa chỉ FDE: 0x118840 | Kích thước: 256 bytes
//   0x05aa50: D10143FF  sub      sp, sp, #0x50
//   0x05aa54: F9000BF7  str      x23, [sp, #0x10]
//   0x05aa58: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x05aa5c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0240_0x05aa50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05aa50ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x118840ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0241 | PC: 0x05ac40 | FDE: 0x118868 | Size: 256 bytes [_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE9underflowEv]
// Hàm FDE #0241 | Địa chỉ PC: 0x05ac40 | Địa chỉ FDE: 0x118868 | Kích thước: 256 bytes
//   0x05ac40: D10183FF  sub      sp, sp, #0x60
//   0x05ac44: F90013F7  str      x23, [sp, #0x20]
//   0x05ac48: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x05ac4c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0241_0x05ac40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05ac40ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x118868ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0242 | PC: 0x05aebc | FDE: 0x118890 | Size: 96 bytes [_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE9pbackfailEi]
// Hàm FDE #0242 | Địa chỉ PC: 0x05aebc | Địa chỉ FDE: 0x118890 | Kích thước: 96 bytes
//   0x05aebc: F9403C09  ldr      x9, [x0, #0x78]
//   0x05aec0: B4000229  cbz      x9, #0x5af04
//   0x05aec4: A941240A  ldp      x10, x9, [x0, #0x10]
//   0x05aec8: AA0003E8  mov      x8, x0
static inline uint64_t fde_func_0242_0x05aebc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05aebcULL ^ (static_cast<uint64_t>(0xf9403c09ULL) << 13);
    acc = (acc + a1 + 0xb4000229ULL) ^ 0x118890ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0243 | PC: 0x05af1c | FDE: 0x1188a8 | Size: 256 bytes [_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE8overflowEi]
// Hàm FDE #0243 | Địa chỉ PC: 0x05af1c | Địa chỉ FDE: 0x1188a8 | Kích thước: 256 bytes
//   0x05af1c: D101C3FF  sub      sp, sp, #0x70
//   0x05af20: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x05af24: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x05af28: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0243_0x05af1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05af1cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x1188a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0244 | PC: 0x05b154 | FDE: 0x1188d8 | Size: 52 bytes
// Hàm FDE #0244 | Địa chỉ PC: 0x05b154 | Địa chỉ FDE: 0x1188d8 | Kích thước: 52 bytes
//   0x05b154: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x05b158: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05b15c: 910043FD  add      x29, sp, #0x10
//   0x05b160: 52800100  mov      w0, #8
static inline uint64_t fde_func_0244_0x05b154(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05b154ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1188d8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0245 | PC: 0x05b188 | FDE: 0x1188f8 | Size: 256 bytes [_ZNKSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE3strEv]
// Hàm FDE #0245 | Địa chỉ PC: 0x05b188 | Địa chỉ FDE: 0x1188f8 | Kích thước: 256 bytes
//   0x05b188: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x05b18c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05b190: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05b194: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0245_0x05b188(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05b188ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1188f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0246 | PC: 0x05b398 | FDE: 0x118920 | Size: 20 bytes [_ZNKSt6__ndk121__basic_string_commonILb1EE20__throw_out_of_rangeEv]
// Hàm FDE #0246 | Địa chỉ PC: 0x05b398 | Địa chỉ FDE: 0x118920 | Kích thước: 20 bytes
//   0x05b398: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x05b39c: 910003FD  mov      x29, sp
//   0x05b3a0: D0000560  adrp     x0, #0x109000
//   0x05b3a4: 912D6400  add      x0, x0, #0xb59
static inline uint64_t fde_func_0246_0x05b398(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05b398ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x118920ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0247 | PC: 0x05b3ac | FDE: 0x118c48 | Size: 80 bytes
// Hàm FDE #0247 | Địa chỉ PC: 0x05b3ac | Địa chỉ FDE: 0x118c48 | Kích thước: 80 bytes
//   0x05b3ac: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x05b3b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05b3b4: 910043FD  add      x29, sp, #0x10
//   0x05b3b8: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0247_0x05b3ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05b3acULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x118c48ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0248 | PC: 0x05b3fc | FDE: 0x118940 | Size: 48 bytes
// Hàm FDE #0248 | Địa chỉ PC: 0x05b3fc | Địa chỉ FDE: 0x118940 | Kích thước: 48 bytes
//   0x05b3fc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x05b400: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05b404: 910043FD  add      x29, sp, #0x10
//   0x05b408: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0248_0x05b3fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05b3fcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x118940ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0249 | PC: 0x05b42c | FDE: 0x118960 | Size: 256 bytes [_ZNSt6__ndk16vectorIN11fast_engine8FileInfoENS_9allocatorIS2_EEE24__emplace_back_slow_pathIJEEEvDpOT_]
// Hàm FDE #0249 | Địa chỉ PC: 0x05b42c | Địa chỉ FDE: 0x118960 | Kích thước: 256 bytes
//   0x05b42c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x05b430: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05b434: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05b438: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0249_0x05b42c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05b42cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x118960ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0250 | PC: 0x05b5cc | FDE: 0x118c70 | Size: 256 bytes [_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEEC2Ev]
// Hàm FDE #0250 | Địa chỉ PC: 0x05b5cc | Địa chỉ FDE: 0x118c70 | Kích thước: 256 bytes
//   0x05b5cc: D10143FF  sub      sp, sp, #0x50
//   0x05b5d0: F9000BF7  str      x23, [sp, #0x10]
//   0x05b5d4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x05b5d8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0250_0x05b5cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05b5ccULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x118c70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0251 | PC: 0x05b720 | FDE: 0x118ca0 | Size: 256 bytes [_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6__initINS_19istreambuf_iteratorIcS2_EEEENS_9enable_ifIXsr27__is_exactly_input_iteratorIT_EE5valueEvE4typeESA_SA_]
// Hàm FDE #0251 | Địa chỉ PC: 0x05b720 | Địa chỉ FDE: 0x118ca0 | Kích thước: 256 bytes
//   0x05b720: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x05b724: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05b728: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05b72c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0251_0x05b720(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05b720ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x118ca0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0252 | PC: 0x05b8cc | FDE: 0x118988 | Size: 256 bytes [_ZNSt6__ndk16vectorINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEE21__push_back_slow_pathIS6_EEvOT_]
// Hàm FDE #0252 | Địa chỉ PC: 0x05b8cc | Địa chỉ FDE: 0x118988 | Kích thước: 256 bytes
//   0x05b8cc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x05b8d0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05b8d4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05b8d8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0252_0x05b8cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05b8ccULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x118988ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0253 | PC: 0x05ba30 | FDE: 0x118cd0 | Size: 256 bytes [_ZNSt6__ndk16vectorINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEE24__emplace_back_slow_pathIJRA1_KcEEEvDpOT_]
// Hàm FDE #0253 | Địa chỉ PC: 0x05ba30 | Địa chỉ FDE: 0x118cd0 | Kích thước: 256 bytes
//   0x05ba30: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x05ba34: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05ba38: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05ba3c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0253_0x05ba30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05ba30ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x118cd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0254 | PC: 0x05bbb0 | FDE: 0x118d00 | Size: 256 bytes [_ZNSt6__ndk16vectorINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEE24__emplace_back_slow_pathIJRNS_11__wrap_iterIPKcEESE_EEEvDpOT_]
// Hàm FDE #0254 | Địa chỉ PC: 0x05bbb0 | Địa chỉ FDE: 0x118d00 | Kích thước: 256 bytes
//   0x05bbb0: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x05bbb4: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x05bbb8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x05bbbc: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0254_0x05bbb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05bbb0ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x118d00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0255 | PC: 0x05be2c | FDE: 0x118d38 | Size: 256 bytes [_ZNSt6__ndk16vectorINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEE24__emplace_back_slow_pathIJRNS_11__wrap_iterIPKcEESD_EEEvDpOT_]
// Hàm FDE #0255 | Địa chỉ PC: 0x05be2c | Địa chỉ FDE: 0x118d38 | Kích thước: 256 bytes
//   0x05be2c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x05be30: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x05be34: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x05be38: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0255_0x05be2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05be2cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x118d38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0256 | PC: 0x05c0a8 | FDE: 0x118d70 | Size: 60 bytes [_ZN11fast_engine12ObjCachePoolC2EPNS_6EngineEl]
// Hàm FDE #0256 | Địa chỉ PC: 0x05c0a8 | Địa chỉ FDE: 0x118d70 | Kích thước: 60 bytes
//   0x05c0a8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x05c0ac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05c0b0: 910043FD  add      x29, sp, #0x10
//   0x05c0b4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0256_0x05c0a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05c0a8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x118d70ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0257 | PC: 0x05c0e4 | FDE: 0x119158 | Size: 128 bytes [_ZN11fast_engine12ObjCachePoolD2Ev]
// Hàm FDE #0257 | Địa chỉ PC: 0x05c0e4 | Địa chỉ FDE: 0x119158 | Kích thước: 128 bytes
//   0x05c0e4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x05c0e8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05c0ec: 910043FD  add      x29, sp, #0x10
//   0x05c0f0: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0257_0x05c0e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05c0e4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x119158ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0258 | PC: 0x05c164 | FDE: 0x118d90 | Size: 36 bytes [_ZN11fast_engine12ObjCachePool3PopEv]
// Hàm FDE #0258 | Địa chỉ PC: 0x05c164 | Địa chỉ FDE: 0x118d90 | Kích thước: 36 bytes
//   0x05c164: F9400408  ldr      x8, [x0, #8]
//   0x05c168: F1000508  subs     x8, x8, #1
//   0x05c16c: 540000AB  b.lt     #0x5c180
//   0x05c170: F9400009  ldr      x9, [x0]
static inline uint64_t fde_func_0258_0x05c164(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05c164ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xf1000508ULL) ^ 0x118d90ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0259 | PC: 0x05c188 | FDE: 0x118da8 | Size: 144 bytes [_ZN11fast_engine12ObjCachePool4PushEPNS_3ObjE]
// Hàm FDE #0259 | Địa chỉ PC: 0x05c188 | Địa chỉ FDE: 0x118da8 | Kích thước: 144 bytes
//   0x05c188: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x05c18c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05c190: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05c194: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0259_0x05c188(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05c188ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x118da8ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0260 | PC: 0x05c218 | FDE: 0x118dc8 | Size: 4 bytes [_ZN11fast_engine19EmptyFuncWithEngineEPNS_6EngineE]
// Hàm FDE #0260 | Địa chỉ PC: 0x05c218 | Địa chỉ FDE: 0x118dc8 | Kích thước: 4 bytes
//   0x05c218: D65F03C0  ret      
static inline uint64_t fde_func_0260_0x05c218(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05c218ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xd10143ffULL) ^ 0x118dc8ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0261 | PC: 0x05c21c | FDE: 0x119180 | Size: 256 bytes [_ZN11fast_engine6EngineC2Ev]
// Hàm FDE #0261 | Địa chỉ PC: 0x05c21c | Địa chỉ FDE: 0x119180 | Kích thước: 256 bytes
//   0x05c21c: D10143FF  sub      sp, sp, #0x50
//   0x05c220: F9000BF7  str      x23, [sp, #0x10]
//   0x05c224: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x05c228: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0261_0x05c21c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05c21cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x119180ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0262 | PC: 0x05c410 | FDE: 0x1191b0 | Size: 180 bytes [_ZN11fast_engine6Engine18CreateObjCachePoolEv]
// Hàm FDE #0262 | Địa chỉ PC: 0x05c410 | Địa chỉ FDE: 0x1191b0 | Kích thước: 180 bytes
//   0x05c410: D10103FF  sub      sp, sp, #0x40
//   0x05c414: F9000BF5  str      x21, [sp, #0x10]
//   0x05c418: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05c41c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0262_0x05c410(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05c410ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x1191b0ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #0263 | PC: 0x05c4c4 | FDE: 0x118de0 | Size: 20 bytes [_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED2Ev]
// Hàm FDE #0263 | Địa chỉ PC: 0x05c4c4 | Địa chỉ FDE: 0x118de0 | Kích thước: 20 bytes
//   0x05c4c4: 39400008  ldrb     w8, [x0]
//   0x05c4c8: 37000048  tbnz     w8, #0, #0x5c4d0
//   0x05c4cc: D65F03C0  ret      
//   0x05c4d0: F9400800  ldr      x0, [x0, #0x10]
static inline uint64_t fde_func_0263_0x05c4c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05c4c4ULL ^ (static_cast<uint64_t>(0x39400008ULL) << 13);
    acc = (acc + a1 + 0x37000048ULL) ^ 0x118de0ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0264 | PC: 0x05c4d8 | FDE: 0x118df8 | Size: 44 bytes
// Hàm FDE #0264 | Địa chỉ PC: 0x05c4d8 | Địa chỉ FDE: 0x118df8 | Kích thước: 44 bytes
//   0x05c4d8: AA0003E8  mov      x8, x0
//   0x05c4dc: F9400000  ldr      x0, [x0]
//   0x05c4e0: B4000100  cbz      x0, #0x5c500
//   0x05c4e4: F9400509  ldr      x9, [x8, #8]
static inline uint64_t fde_func_0264_0x05c4d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05c4d8ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xf9400000ULL) ^ 0x118df8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0265 | PC: 0x05c504 | FDE: 0x1191d8 | Size: 256 bytes [_ZN11fast_engine6EngineC2ERNS_5ErrorEbb]
// Hàm FDE #0265 | Địa chỉ PC: 0x05c504 | Địa chỉ FDE: 0x1191d8 | Kích thước: 256 bytes
//   0x05c504: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x05c508: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x05c50c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x05c510: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0265_0x05c504(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05c504ULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1191d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0266 | PC: 0x05c6a8 | FDE: 0x119210 | Size: 196 bytes [_ZN11fast_engine6Engine9InitCacheEv]
// Hàm FDE #0266 | Địa chỉ PC: 0x05c6a8 | Địa chỉ FDE: 0x119210 | Kích thước: 196 bytes
//   0x05c6a8: D10103FF  sub      sp, sp, #0x40
//   0x05c6ac: F9000BF5  str      x21, [sp, #0x10]
//   0x05c6b0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05c6b4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0266_0x05c6a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05c6a8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x119210ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0267 | PC: 0x05c76c | FDE: 0x119238 | Size: 256 bytes [_ZN11fast_engine6EngineC2Eb]
// Hàm FDE #0267 | Địa chỉ PC: 0x05c76c | Địa chỉ FDE: 0x119238 | Kích thước: 256 bytes
//   0x05c76c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x05c770: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05c774: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05c778: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0267_0x05c76c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05c76cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x119238ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0268 | PC: 0x05c87c | FDE: 0x119268 | Size: 244 bytes [_ZN11fast_engine6EngineD2Ev]
// Hàm FDE #0268 | Địa chỉ PC: 0x05c87c | Địa chỉ FDE: 0x119268 | Kích thước: 244 bytes
//   0x05c87c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x05c880: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05c884: 910043FD  add      x29, sp, #0x10
//   0x05c888: 52928988  mov      w8, #0x944c
static inline uint64_t fde_func_0268_0x05c87c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05c87cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x119268ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #0269 | PC: 0x05c970 | FDE: 0x118e10 | Size: 144 bytes [_ZN11fast_engine6Engine8FinalizeEv]
// Hàm FDE #0269 | Địa chỉ PC: 0x05c970 | Địa chỉ FDE: 0x118e10 | Kích thước: 144 bytes
//   0x05c970: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x05c974: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05c978: 910043FD  add      x29, sp, #0x10
//   0x05c97c: 52928988  mov      w8, #0x944c
static inline uint64_t fde_func_0269_0x05c970(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05c970ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x118e10ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0270 | PC: 0x05ca00 | FDE: 0x119290 | Size: 224 bytes [_ZN11fast_engine6Engine19DestoryObjCachePoolEv]
// Hàm FDE #0270 | Địa chỉ PC: 0x05ca00 | Địa chỉ FDE: 0x119290 | Kích thước: 224 bytes
//   0x05ca00: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x05ca04: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05ca08: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05ca0c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0270_0x05ca00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05ca00ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x119290ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #0271 | PC: 0x05cae0 | FDE: 0x118e30 | Size: 256 bytes [_ZN11fast_engine6Engine10CleanCacheEv]
// Hàm FDE #0271 | Địa chỉ PC: 0x05cae0 | Địa chỉ FDE: 0x118e30 | Kích thước: 256 bytes
//   0x05cae0: D10183FF  sub      sp, sp, #0x60
//   0x05cae4: F90013F7  str      x23, [sp, #0x20]
//   0x05cae8: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x05caec: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0271_0x05cae0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05cae0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x118e30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0272 | PC: 0x05cd20 | FDE: 0x118e58 | Size: 256 bytes [_ZN11fast_engine6Engine33ReleaseTrackedUnreleasableObjectsEv]
// Hàm FDE #0272 | Địa chỉ PC: 0x05cd20 | Địa chỉ FDE: 0x118e58 | Kích thước: 256 bytes
//   0x05cd20: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x05cd24: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05cd28: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05cd2c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0272_0x05cd20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05cd20ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x118e58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0273 | PC: 0x05ce24 | FDE: 0x118e80 | Size: 256 bytes [_ZN11fast_engine6Engine19SetHandledExceptionEPNS_3ObjES2_S2_]
// Hàm FDE #0273 | Địa chỉ PC: 0x05ce24 | Địa chỉ FDE: 0x118e80 | Kích thước: 256 bytes
//   0x05ce24: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x05ce28: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05ce2c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05ce30: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0273_0x05ce24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05ce24ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x118e80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0274 | PC: 0x05cf58 | FDE: 0x1192c0 | Size: 184 bytes [_ZN11fast_engine6Engine23TrackUnreleasableObjectEPNS_3ObjE]
// Hàm FDE #0274 | Địa chỉ PC: 0x05cf58 | Địa chỉ FDE: 0x1192c0 | Kích thước: 184 bytes
//   0x05cf58: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x05cf5c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05cf60: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05cf64: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0274_0x05cf58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05cf58ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1192c0ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #0275 | PC: 0x05d010 | FDE: 0x1192e8 | Size: 256 bytes [_ZN11fast_engine6Engine12GetGlobalCxtEv]
// Hàm FDE #0275 | Địa chỉ PC: 0x05d010 | Địa chỉ FDE: 0x1192e8 | Kích thước: 256 bytes
//   0x05d010: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x05d014: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05d018: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05d01c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0275_0x05d010(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05d010ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1192e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0276 | PC: 0x05d1c8 | FDE: 0x119310 | Size: 256 bytes [_ZN11fast_engine6Engine3RunEPNS_9ModuleObjEPKcPNS_8TupleObjEPNS_7DictObjES8_]
// Hàm FDE #0276 | Địa chỉ PC: 0x05d1c8 | Địa chỉ FDE: 0x119310 | Kích thước: 256 bytes
//   0x05d1c8: D101C3FF  sub      sp, sp, #0x70
//   0x05d1cc: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x05d1d0: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x05d1d4: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0276_0x05d1c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05d1c8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x119310ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0277 | PC: 0x05d4d0 | FDE: 0x118ea0 | Size: 124 bytes [_ZN11fast_engine6Engine14MakeValueErrorERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE]
// Hàm FDE #0277 | Địa chỉ PC: 0x05d4d0 | Địa chỉ FDE: 0x118ea0 | Kích thước: 124 bytes
//   0x05d4d0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x05d4d4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05d4d8: 910043FD  add      x29, sp, #0x10
//   0x05d4dc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0277_0x05d4d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05d4d0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x118ea0ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0278 | PC: 0x05d54c | FDE: 0x119348 | Size: 228 bytes [_ZN11fast_engine6Engine17MakeNoMethodErrorEPKc]
// Hàm FDE #0278 | Địa chỉ PC: 0x05d54c | Địa chỉ FDE: 0x119348 | Kích thước: 228 bytes
//   0x05d54c: D10143FF  sub      sp, sp, #0x50
//   0x05d550: F90013F5  str      x21, [sp, #0x20]
//   0x05d554: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x05d558: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0278_0x05d54c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05d54cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x119348ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #0279 | PC: 0x05d630 | FDE: 0x119370 | Size: 256 bytes [_ZN11fast_engine6Engine8EvalCodeEPNS_7CodeObjEPNS_7DictObjES4_]
// Hàm FDE #0279 | Địa chỉ PC: 0x05d630 | Địa chỉ FDE: 0x119370 | Kích thước: 256 bytes
//   0x05d630: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x05d634: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05d638: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05d63c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0279_0x05d630(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05d630ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x119370ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0280 | PC: 0x05d8a8 | FDE: 0x1193a0 | Size: 256 bytes [_ZN11fast_engine6Engine3RunEPKcS2_PNS_8TupleObjEPNS_7DictObjES6_]
// Hàm FDE #0280 | Địa chỉ PC: 0x05d8a8 | Địa chỉ FDE: 0x1193a0 | Kích thước: 256 bytes
//   0x05d8a8: D10343FF  sub      sp, sp, #0xd0
//   0x05d8ac: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x05d8b0: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x05d8b4: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_0280_0x05d8a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05d8a8ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9076ffcULL) ^ 0x1193a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0281 | PC: 0x05dd24 | FDE: 0x1193d8 | Size: 256 bytes [_ZN11fast_engine6Engine19FindResourceByNamesENSt6__ndk16vectorINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS6_IS8_EEEEb]
// Hàm FDE #0281 | Địa chỉ PC: 0x05dd24 | Địa chỉ FDE: 0x1193d8 | Kích thước: 256 bytes
//   0x05dd24: D10243FF  sub      sp, sp, #0x90
//   0x05dd28: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x05dd2c: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x05dd30: A9074FF4  stp      x20, x19, [sp, #0x70]
static inline uint64_t fde_func_0281_0x05dd24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05dd24ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9055ff8ULL) ^ 0x1193d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0282 | PC: 0x05e144 | FDE: 0x119408 | Size: 256 bytes [_ZNSt6__ndk16vectorINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEEC2ERKS8_]
// Hàm FDE #0282 | Địa chỉ PC: 0x05e144 | Địa chỉ FDE: 0x119408 | Kích thước: 256 bytes
//   0x05e144: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x05e148: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05e14c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05e150: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0282_0x05e144(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e144ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x119408ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0283 | PC: 0x05e268 | FDE: 0x118ec0 | Size: 96 bytes [_ZN11fast_engine6Engine5ResetEv]
// Hàm FDE #0283 | Địa chỉ PC: 0x05e268 | Địa chỉ FDE: 0x118ec0 | Kích thước: 96 bytes
//   0x05e268: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x05e26c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05e270: 910043FD  add      x29, sp, #0x10
//   0x05e274: 52821C08  mov      w8, #0x10e0
static inline uint64_t fde_func_0283_0x05e268(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e268ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x118ec0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0284 | PC: 0x05e2c8 | FDE: 0x118ee0 | Size: 24 bytes [_ZN11fast_engine6Engine10ClearErrorEv]
// Hàm FDE #0284 | Địa chỉ PC: 0x05e2c8 | Địa chỉ FDE: 0x118ee0 | Kích thước: 24 bytes
//   0x05e2c8: 52821C08  mov      w8, #0x10e0
//   0x05e2cc: AA1F03E1  mov      x1, xzr
//   0x05e2d0: AA1F03E2  mov      x2, xzr
//   0x05e2d4: AA1F03E3  mov      x3, xzr
static inline uint64_t fde_func_0284_0x05e2c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e2c8ULL ^ (static_cast<uint64_t>(0x52821c08ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e1ULL) ^ 0x118ee0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0285 | PC: 0x05e2e0 | FDE: 0x118ef8 | Size: 68 bytes [_ZN11fast_engine6Engine12ClearModulesEv]
// Hàm FDE #0285 | Địa chỉ PC: 0x05e2e0 | Địa chỉ FDE: 0x118ef8 | Kích thước: 68 bytes
//   0x05e2e0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x05e2e4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05e2e8: 910043FD  add      x29, sp, #0x10
//   0x05e2ec: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0285_0x05e2e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e2e0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x118ef8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0286 | PC: 0x05e324 | FDE: 0x118f18 | Size: 28 bytes [_ZN11fast_engine6Engine12ImportModuleEPNS_9ModuleObjE]
// Hàm FDE #0286 | Địa chỉ PC: 0x05e324 | Địa chỉ FDE: 0x118f18 | Kích thước: 28 bytes
//   0x05e324: B40000C1  cbz      x1, #0x5e33c
//   0x05e328: AA0003E3  mov      x3, x0
//   0x05e32c: F9485000  ldr      x0, [x0, #0x10a0]
//   0x05e330: AA0103E2  mov      x2, x1
static inline uint64_t fde_func_0286_0x05e324(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e324ULL ^ (static_cast<uint64_t>(0xb40000c1ULL) << 13);
    acc = (acc + a1 + 0xaa0003e3ULL) ^ 0x118f18ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0287 | PC: 0x05e340 | FDE: 0x119438 | Size: 200 bytes [_ZN11fast_engine6Engine10FindModuleEPKc]
// Hàm FDE #0287 | Địa chỉ PC: 0x05e340 | Địa chỉ FDE: 0x119438 | Kích thước: 200 bytes
//   0x05e340: D10143FF  sub      sp, sp, #0x50
//   0x05e344: F90013F5  str      x21, [sp, #0x20]
//   0x05e348: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x05e34c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0287_0x05e340(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e340ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x119438ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0288 | PC: 0x05e408 | FDE: 0x119460 | Size: 256 bytes [_ZN11fast_engine6Engine10ImportFileEPKcS2_b]
// Hàm FDE #0288 | Địa chỉ PC: 0x05e408 | Địa chỉ FDE: 0x119460 | Kích thước: 256 bytes
//   0x05e408: D10203FF  sub      sp, sp, #0x80
//   0x05e40c: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x05e410: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x05e414: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_0288_0x05e408(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e408ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9045ff8ULL) ^ 0x119460ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0289 | PC: 0x05e5e4 | FDE: 0x119490 | Size: 224 bytes [_ZN11fast_engine6Engine17ClearModuleStringEPKc]
// Hàm FDE #0289 | Địa chỉ PC: 0x05e5e4 | Địa chỉ FDE: 0x119490 | Kích thước: 224 bytes
//   0x05e5e4: D10143FF  sub      sp, sp, #0x50
//   0x05e5e8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x05e5ec: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x05e5f0: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0289_0x05e5e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e5e4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x119490ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #0290 | PC: 0x05e6c4 | FDE: 0x118f30 | Size: 8 bytes [_ZN11fast_engine6Engine15ImportDirectoryEPKcS2_b]
// Hàm FDE #0290 | Địa chỉ PC: 0x05e6c4 | Địa chỉ FDE: 0x118f30 | Kích thước: 8 bytes
//   0x05e6c4: 12000063  and      w3, w3, #1
//   0x05e6c8: 17FF9826  b        #0x44760
static inline uint64_t fde_func_0290_0x05e6c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e6c4ULL ^ (static_cast<uint64_t>(0x12000063ULL) << 13);
    acc = (acc + a1 + 0x17ff9826ULL) ^ 0x118f30ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0291 | PC: 0x05e6cc | FDE: 0x1194c0 | Size: 256 bytes [_ZN11fast_engine6Engine12ImportBase64EPKcS2_b]
// Hàm FDE #0291 | Địa chỉ PC: 0x05e6cc | Địa chỉ FDE: 0x1194c0 | Kích thước: 256 bytes
//   0x05e6cc: D10203FF  sub      sp, sp, #0x80
//   0x05e6d0: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x05e6d4: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x05e6d8: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_0291_0x05e6cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e6ccULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9045ff8ULL) ^ 0x1194c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0292 | PC: 0x05e87c | FDE: 0x1194f0 | Size: 256 bytes [_ZNSt6__ndk16vectorINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEEC2INS_11__wrap_iterIPS6_EEEET_NS_9enable_ifIXaasr21__is_forward_iteratorISD_EE5valuesr16is_constructibleIS6_NS_15iterator_traitsISD_E9referenceEEE5valueESD_E4typeE]
// Hàm FDE #0292 | Địa chỉ PC: 0x05e87c | Địa chỉ FDE: 0x1194f0 | Kích thước: 256 bytes
//   0x05e87c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x05e880: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x05e884: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05e888: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0292_0x05e87c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e87cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1194f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0293 | PC: 0x05e9a0 | FDE: 0x118f48 | Size: 12 bytes [_ZN11fast_engine6Engine11ClearModuleEPNS_6StrObjE]
// Hàm FDE #0293 | Địa chỉ PC: 0x05e9a0 | Địa chỉ FDE: 0x118f48 | Kích thước: 12 bytes
//   0x05e9a0: AA0003E2  mov      x2, x0
//   0x05e9a4: F9485000  ldr      x0, [x0, #0x10a0]
//   0x05e9a8: 17FF9C62  b        #0x45b30
static inline uint64_t fde_func_0293_0x05e9a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e9a0ULL ^ (static_cast<uint64_t>(0xaa0003e2ULL) << 13);
    acc = (acc + a1 + 0xf9485000ULL) ^ 0x118f48ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0294 | PC: 0x05e9ac | FDE: 0x119520 | Size: 256 bytes [_ZN11fast_engine6Engine21_Eval_MakeFrameVectorEPKNS_7FuncObjEPNS_3ObjEPKS5_lS5_]
// Hàm FDE #0294 | Địa chỉ PC: 0x05e9ac | Địa chỉ FDE: 0x119520 | Kích thước: 256 bytes
//   0x05e9ac: D10383FF  sub      sp, sp, #0xe0
//   0x05e9b0: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x05e9b4: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x05e9b8: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_0294_0x05e9ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e9acULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x119520ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0295 | PC: 0x05f25c | FDE: 0x119558 | Size: 256 bytes [_ZN11fast_engine6Engine8RunFrameEPNS_8FrameObjE]
// Hàm FDE #0295 | Địa chỉ PC: 0x05f25c | Địa chỉ FDE: 0x119558 | Kích thước: 256 bytes
//   0x05f25c: D10503FF  sub      sp, sp, #0x140
//   0x05f260: FD006BE8  str      d8, [sp, #0xd0]
//   0x05f264: A90E6FFC  stp      x28, x27, [sp, #0xe0]
//   0x05f268: A90F67FA  stp      x26, x25, [sp, #0xf0]
static inline uint64_t fde_func_0295_0x05f25c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05f25cULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xfd006be8ULL) ^ 0x119558ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0296 | PC: 0x065a34 | FDE: 0x119590 | Size: 256 bytes [_ZN11fast_engine6Engine9DumpFrameEPNS_8FrameObjEPKc]
// Hàm FDE #0296 | Địa chỉ PC: 0x065a34 | Địa chỉ FDE: 0x119590 | Kích thước: 256 bytes
//   0x065a34: D10183FF  sub      sp, sp, #0x60
//   0x065a38: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x065a3c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x065a40: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0296_0x065a34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x065a34ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x119590ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0297 | PC: 0x065c70 | FDE: 0x1195c0 | Size: 256 bytes [_ZNK11fast_engine6Engine13DumpTracebackEPKc]
// Hàm FDE #0297 | Địa chỉ PC: 0x065c70 | Địa chỉ FDE: 0x1195c0 | Kích thước: 256 bytes
//   0x065c70: D101C3FF  sub      sp, sp, #0x70
//   0x065c74: F90013F9  str      x25, [sp, #0x20]
//   0x065c78: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x065c7c: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0297_0x065c70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x065c70ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x1195c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0298 | PC: 0x065fcc | FDE: 0x118f60 | Size: 84 bytes [_ZNK11fast_engine6Engine9FormatExcEPKc]
// Hàm FDE #0298 | Địa chỉ PC: 0x065fcc | Địa chỉ FDE: 0x118f60 | Kích thước: 84 bytes
//   0x065fcc: F9488009  ldr      x9, [x0, #0x1100]
//   0x065fd0: AA0103E4  mov      x4, x1
//   0x065fd4: AA0903E1  mov      x1, x9
//   0x065fd8: B4000109  cbz      x9, #0x65ff8
static inline uint64_t fde_func_0298_0x065fcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x065fccULL ^ (static_cast<uint64_t>(0xf9488009ULL) << 13);
    acc = (acc + a1 + 0xaa0103e4ULL) ^ 0x118f60ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0299 | PC: 0x066020 | FDE: 0x1195f0 | Size: 256 bytes [_ZNK11fast_engine6Engine9FormatExcEPNS_3ObjES2_S2_PKc]
// Hàm FDE #0299 | Địa chỉ PC: 0x066020 | Địa chỉ FDE: 0x1195f0 | Kích thước: 256 bytes
//   0x066020: D10203FF  sub      sp, sp, #0x80
//   0x066024: F90013FB  str      x27, [sp, #0x20]
//   0x066028: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x06602c: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0299_0x066020(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x066020ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x1195f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0300 | PC: 0x066324 | FDE: 0x118f78 | Size: 256 bytes [_ZN11fast_engine6Engine10FreeObjectEPNS_3ObjE]
// Hàm FDE #0300 | Địa chỉ PC: 0x066324 | Địa chỉ FDE: 0x118f78 | Kích thước: 256 bytes
//   0x066324: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x066328: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06632c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x066330: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0300_0x066324(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x066324ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x118f78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0301 | PC: 0x066448 | FDE: 0x119628 | Size: 256 bytes [_ZN11fast_engine6Engine15MakeBinaryErrorEPKcPKNS_3ObjES5_]
// Hàm FDE #0301 | Địa chỉ PC: 0x066448 | Địa chỉ FDE: 0x119628 | Kích thước: 256 bytes
//   0x066448: D10143FF  sub      sp, sp, #0x50
//   0x06644c: F90013F5  str      x21, [sp, #0x20]
//   0x066450: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x066454: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0301_0x066448(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x066448ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x119628ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0302 | PC: 0x066574 | FDE: 0x118f98 | Size: 256 bytes [_ZN11fast_engine6Engine16RestoreExceptionEPNS_3ObjES2_S2_]
// Hàm FDE #0302 | Địa chỉ PC: 0x066574 | Địa chỉ FDE: 0x118f98 | Kích thước: 256 bytes
//   0x066574: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x066578: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06657c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x066580: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0302_0x066574(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x066574ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x118f98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0303 | PC: 0x066738 | FDE: 0x119650 | Size: 256 bytes [_ZN11fast_engine6Engine9MakeErrorEPNS_7TypeObjEPKcz]
// Hàm FDE #0303 | Địa chỉ PC: 0x066738 | Địa chỉ FDE: 0x119650 | Kích thước: 256 bytes
//   0x066738: D10583FF  sub      sp, sp, #0x160
//   0x06673c: F9008BFC  str      x28, [sp, #0x110]
//   0x066740: A9125FF8  stp      x24, x23, [sp, #0x120]
//   0x066744: A91357F6  stp      x22, x21, [sp, #0x130]
static inline uint64_t fde_func_0303_0x066738(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x066738ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9008bfcULL) ^ 0x119650ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0304 | PC: 0x066a24 | FDE: 0x119680 | Size: 256 bytes [_ZN11fast_engine6Engine14UnpackIterableEPNS_3ObjEiiPS2_]
// Hàm FDE #0304 | Địa chỉ PC: 0x066a24 | Địa chỉ FDE: 0x119680 | Kích thước: 256 bytes
//   0x066a24: D10203FF  sub      sp, sp, #0x80
//   0x066a28: F90013FB  str      x27, [sp, #0x20]
//   0x066a2c: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x066a30: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0304_0x066a24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x066a24ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x119680ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0305 | PC: 0x066f68 | FDE: 0x118fc0 | Size: 20 bytes [_ZN11fast_engine6Engine21MatchCurrentExceptionEPNS_7TypeObjE]
// Hàm FDE #0305 | Địa chỉ PC: 0x066f68 | Địa chỉ FDE: 0x118fc0 | Kích thước: 20 bytes
//   0x066f68: AA0003E2  mov      x2, x0
//   0x066f6c: F9488000  ldr      x0, [x0, #0x1100]
//   0x066f70: B4000040  cbz      x0, #0x66f78
//   0x066f74: 17FF6F57  b        #0x42cd0
static inline uint64_t fde_func_0305_0x066f68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x066f68ULL ^ (static_cast<uint64_t>(0xaa0003e2ULL) << 13);
    acc = (acc + a1 + 0xf9488000ULL) ^ 0x118fc0ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0306 | PC: 0x066f7c | FDE: 0x1196b8 | Size: 256 bytes [_ZN11fast_engine6Engine17MakeErrorWithReprEPNS_7TypeObjEPKcz]
// Hàm FDE #0306 | Địa chỉ PC: 0x066f7c | Địa chỉ FDE: 0x1196b8 | Kích thước: 256 bytes
//   0x066f7c: D10543FF  sub      sp, sp, #0x150
//   0x066f80: F9008BFC  str      x28, [sp, #0x110]
//   0x066f84: A91257F6  stp      x22, x21, [sp, #0x120]
//   0x066f88: A9134FF4  stp      x20, x19, [sp, #0x130]
static inline uint64_t fde_func_0306_0x066f7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x066f7cULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xf9008bfcULL) ^ 0x1196b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0307 | PC: 0x0670b4 | FDE: 0x118fd8 | Size: 96 bytes [_ZN11fast_engine6Engine16MakeUnboundErrorEPKNS_7CodeObjEi]
// Hàm FDE #0307 | Địa chỉ PC: 0x0670b4 | Địa chỉ FDE: 0x118fd8 | Kích thước: 96 bytes
//   0x0670b4: 52821C08  mov      w8, #0x10e0
//   0x0670b8: 38686808  ldrb     w8, [x0, x8]
//   0x0670bc: 34000048  cbz      w8, #0x670c4
//   0x0670c0: D65F03C0  ret      
static inline uint64_t fde_func_0307_0x0670b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0670b4ULL ^ (static_cast<uint64_t>(0x52821c08ULL) << 13);
    acc = (acc + a1 + 0x38686808ULL) ^ 0x118fd8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0308 | PC: 0x067114 | FDE: 0x1196e8 | Size: 256 bytes [_ZN11fast_engine6Engine13MakeTypeErrorEPKNS_3ObjEPKc]
// Hàm FDE #0308 | Địa chỉ PC: 0x067114 | Địa chỉ FDE: 0x1196e8 | Kích thước: 256 bytes
//   0x067114: D10143FF  sub      sp, sp, #0x50
//   0x067118: F90013F5  str      x21, [sp, #0x20]
//   0x06711c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x067120: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0308_0x067114(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x067114ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1196e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0309 | PC: 0x06721c | FDE: 0x119710 | Size: 256 bytes [_ZN11fast_engine6Engine10ImportNameEPKNS_8FrameObjEPNS_3ObjES5_S5_]
// Hàm FDE #0309 | Địa chỉ PC: 0x06721c | Địa chỉ FDE: 0x119710 | Kích thước: 256 bytes
//   0x06721c: D105C3FF  sub      sp, sp, #0x170
//   0x067220: A9116FFC  stp      x28, x27, [sp, #0x110]
//   0x067224: A91267FA  stp      x26, x25, [sp, #0x120]
//   0x067228: A9135FF8  stp      x24, x23, [sp, #0x130]
static inline uint64_t fde_func_0309_0x06721c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06721cULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xa9116ffcULL) ^ 0x119710ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0310 | PC: 0x06837c | FDE: 0x118ff0 | Size: 240 bytes [_ZN11fast_engine6Engine10ImportFromEPNS_3ObjES2_]
// Hàm FDE #0310 | Địa chỉ PC: 0x06837c | Địa chỉ FDE: 0x118ff0 | Kích thước: 240 bytes
//   0x06837c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x068380: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x068384: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x068388: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0310_0x06837c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06837cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x118ff0ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #0311 | PC: 0x06846c | FDE: 0x119018 | Size: 256 bytes [_ZN11fast_engine6Engine9ImportAllEPNS_3ObjEPNS_7DictObjE]
// Hàm FDE #0311 | Địa chỉ PC: 0x06846c | Địa chỉ FDE: 0x119018 | Kích thước: 256 bytes
//   0x06846c: D101C3FF  sub      sp, sp, #0x70
//   0x068470: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x068474: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x068478: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0311_0x06846c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06846cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x119018ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0312 | PC: 0x0685fc | FDE: 0x119048 | Size: 28 bytes [_ZN11fast_engine6Engine17MakeNoKeyObjErrorEPNS_3ObjE]
// Hàm FDE #0312 | Địa chỉ PC: 0x0685fc | Địa chỉ FDE: 0x119048 | Kích thước: 28 bytes
//   0x0685fc: F00006A8  adrp     x8, #0x13f000
//   0x068600: F9446908  ldr      x8, [x8, #0x8d0]
//   0x068604: AA0103E3  mov      x3, x1
//   0x068608: F0000502  adrp     x2, #0x10b000
static inline uint64_t fde_func_0312_0x0685fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0685fcULL ^ (static_cast<uint64_t>(0xf00006a8ULL) << 13);
    acc = (acc + a1 + 0xf9446908ULL) ^ 0x119048ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0313 | PC: 0x068618 | FDE: 0x119748 | Size: 256 bytes [_ZN11fast_engine6Engine18NormalizeExceptionEv]
// Hàm FDE #0313 | Địa chỉ PC: 0x068618 | Địa chỉ FDE: 0x119748 | Kích thước: 256 bytes
//   0x068618: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x06861c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x068620: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x068624: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0313_0x068618(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068618ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x119748ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0314 | PC: 0x0687b4 | FDE: 0x119770 | Size: 256 bytes [_ZN11fast_engine6Engine12_Eval_VectorEPNS_7FuncObjEPNS_3ObjEPKS4_lS4_]
// Hàm FDE #0314 | Địa chỉ PC: 0x0687b4 | Địa chỉ FDE: 0x119770 | Kích thước: 256 bytes
//   0x0687b4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0687b8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0687bc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0687c0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0314_0x0687b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0687b4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x119770ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0315 | PC: 0x0688f4 | FDE: 0x119060 | Size: 136 bytes [_ZN11fast_engine6Engine14FetchExceptionEPPNS_3ObjES3_S3_]
// Hàm FDE #0315 | Địa chỉ PC: 0x0688f4 | Địa chỉ FDE: 0x119060 | Kích thước: 136 bytes
//   0x0688f4: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0688f8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0688fc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x068900: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0315_0x0688f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0688f4ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x119060ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #0316 | PC: 0x06897c | FDE: 0x119798 | Size: 256 bytes [_ZN11fast_engine6Engine20GetAndClearExceptionEPKc]
// Hàm FDE #0316 | Địa chỉ PC: 0x06897c | Địa chỉ FDE: 0x119798 | Kích thước: 256 bytes
//   0x06897c: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x068980: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x068984: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x068988: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0316_0x06897c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06897cULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x119798ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0317 | PC: 0x068acc | FDE: 0x1197c8 | Size: 224 bytes [_ZN11fast_engine6Engine23MakeNotImplementedErrorEv]
// Hàm FDE #0317 | Địa chỉ PC: 0x068acc | Địa chỉ FDE: 0x1197c8 | Kích thước: 224 bytes
//   0x068acc: D10143FF  sub      sp, sp, #0x50
//   0x068ad0: F90013F5  str      x21, [sp, #0x20]
//   0x068ad4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x068ad8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0317_0x068acc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068accULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1197c8ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #0318 | PC: 0x068bac | FDE: 0x1197f0 | Size: 256 bytes [_ZN11fast_engine6Engine14MakeUnaryErrorEPKcPKNS_3ObjE]
// Hàm FDE #0318 | Địa chỉ PC: 0x068bac | Địa chỉ FDE: 0x1197f0 | Kích thước: 256 bytes
//   0x068bac: D10143FF  sub      sp, sp, #0x50
//   0x068bb0: F90013F5  str      x21, [sp, #0x20]
//   0x068bb4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x068bb8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0318_0x068bac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068bacULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1197f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0319 | PC: 0x068cb8 | FDE: 0x119818 | Size: 228 bytes [_ZN11fast_engine6Engine14MakeRangeErrorExx]
// Hàm FDE #0319 | Địa chỉ PC: 0x068cb8 | Địa chỉ FDE: 0x119818 | Kích thước: 228 bytes
//   0x068cb8: D10143FF  sub      sp, sp, #0x50
//   0x068cbc: F90013F5  str      x21, [sp, #0x20]
//   0x068cc0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x068cc4: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0319_0x068cb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068cb8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x119818ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #0320 | PC: 0x068d9c | FDE: 0x119840 | Size: 228 bytes [_ZN11fast_engine6Engine19MakeUnsupportedTypeEPKci]
// Hàm FDE #0320 | Địa chỉ PC: 0x068d9c | Địa chỉ FDE: 0x119840 | Kích thước: 228 bytes
//   0x068d9c: D10143FF  sub      sp, sp, #0x50
//   0x068da0: F90013F5  str      x21, [sp, #0x20]
//   0x068da4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x068da8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0320_0x068d9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068d9cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x119840ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #0321 | PC: 0x068e80 | FDE: 0x119868 | Size: 256 bytes [_ZN11fast_engine6Engine14MakeValueErrorEPKNS_3ObjE]
// Hàm FDE #0321 | Địa chỉ PC: 0x068e80 | Địa chỉ FDE: 0x119868 | Kích thước: 256 bytes
//   0x068e80: D10143FF  sub      sp, sp, #0x50
//   0x068e84: F90013F5  str      x21, [sp, #0x20]
//   0x068e88: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x068e8c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0321_0x068e80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068e80ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x119868ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0322 | PC: 0x068f88 | FDE: 0x119088 | Size: 124 bytes [_ZN11fast_engine6Engine18MakeUnsupportErrorERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE]
// Hàm FDE #0322 | Địa chỉ PC: 0x068f88 | Địa chỉ FDE: 0x119088 | Kích thước: 124 bytes
//   0x068f88: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x068f8c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x068f90: 910043FD  add      x29, sp, #0x10
//   0x068f94: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0322_0x068f88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068f88ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x119088ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0323 | PC: 0x069004 | FDE: 0x119890 | Size: 228 bytes [_ZN11fast_engine6Engine15MakeNoAttrErrorEPKc]
// Hàm FDE #0323 | Địa chỉ PC: 0x069004 | Địa chỉ FDE: 0x119890 | Kích thước: 228 bytes
//   0x069004: D10143FF  sub      sp, sp, #0x50
//   0x069008: F90013F5  str      x21, [sp, #0x20]
//   0x06900c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x069010: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0323_0x069004(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069004ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x119890ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #0324 | PC: 0x0690e8 | FDE: 0x1198b8 | Size: 228 bytes [_ZN11fast_engine6Engine14MakeNoKeyErrorEPKc]
// Hàm FDE #0324 | Địa chỉ PC: 0x0690e8 | Địa chỉ FDE: 0x1198b8 | Kích thước: 228 bytes
//   0x0690e8: D10143FF  sub      sp, sp, #0x50
//   0x0690ec: F90013F5  str      x21, [sp, #0x20]
//   0x0690f0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0690f4: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0324_0x0690e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0690e8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1198b8ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #0325 | PC: 0x0691cc | FDE: 0x1198e0 | Size: 256 bytes [_ZN11fast_engine6Engine24MakeMethodValueTypeErrorEPKcS2_PKNS_3ObjES2_]
// Hàm FDE #0325 | Địa chỉ PC: 0x0691cc | Địa chỉ FDE: 0x1198e0 | Kích thước: 256 bytes
//   0x0691cc: D10343FF  sub      sp, sp, #0xd0
//   0x0691d0: F9004BF7  str      x23, [sp, #0x90]
//   0x0691d4: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x0691d8: A90B4FF4  stp      x20, x19, [sp, #0xb0]
static inline uint64_t fde_func_0325_0x0691cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0691ccULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xf9004bf7ULL) ^ 0x1198e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0326 | PC: 0x069520 | FDE: 0x119910 | Size: 224 bytes [_ZN11fast_engine6Engine15MakeUnknowErrorEv]
// Hàm FDE #0326 | Địa chỉ PC: 0x069520 | Địa chỉ FDE: 0x119910 | Kích thước: 224 bytes
//   0x069520: D10143FF  sub      sp, sp, #0x50
//   0x069524: F90013F5  str      x21, [sp, #0x20]
//   0x069528: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x06952c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0326_0x069520(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069520ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x119910ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #0327 | PC: 0x069600 | FDE: 0x1190a8 | Size: 24 bytes [_ZN11fast_engine6Engine18MakeImmutableErrorEv]
// Hàm FDE #0327 | Địa chỉ PC: 0x069600 | Địa chỉ FDE: 0x1190a8 | Kích thước: 24 bytes
//   0x069600: D00006A8  adrp     x8, #0x13f000
//   0x069604: F947C508  ldr      x8, [x8, #0xf88]
//   0x069608: D0000502  adrp     x2, #0x10b000
//   0x06960c: 910DE042  add      x2, x2, #0x378
static inline uint64_t fde_func_0327_0x069600(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069600ULL ^ (static_cast<uint64_t>(0xd00006a8ULL) << 13);
    acc = (acc + a1 + 0xf947c508ULL) ^ 0x1190a8ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0328 | PC: 0x069618 | FDE: 0x119938 | Size: 224 bytes [_ZN11fast_engine6Engine17MakeInternalErrorEv]
// Hàm FDE #0328 | Địa chỉ PC: 0x069618 | Địa chỉ FDE: 0x119938 | Kích thước: 224 bytes
//   0x069618: D10143FF  sub      sp, sp, #0x50
//   0x06961c: F90013F5  str      x21, [sp, #0x20]
//   0x069620: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x069624: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0328_0x069618(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069618ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x119938ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #0329 | PC: 0x0696f8 | FDE: 0x1190c0 | Size: 28 bytes [_ZN11fast_engine6Engine12MakeKeyErrorEPNS_3ObjE]
// Hàm FDE #0329 | Địa chỉ PC: 0x0696f8 | Địa chỉ FDE: 0x1190c0 | Kích thước: 28 bytes
//   0x0696f8: D00006A8  adrp     x8, #0x13f000
//   0x0696fc: F9446908  ldr      x8, [x8, #0x8d0]
//   0x069700: AA0103E3  mov      x3, x1
//   0x069704: D0000502  adrp     x2, #0x10b000
static inline uint64_t fde_func_0329_0x0696f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0696f8ULL ^ (static_cast<uint64_t>(0xd00006a8ULL) << 13);
    acc = (acc + a1 + 0xf9446908ULL) ^ 0x1190c0ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0330 | PC: 0x069714 | FDE: 0x119960 | Size: 224 bytes [_ZN11fast_engine6Engine17MakeNoMemoryErrorEv]
// Hàm FDE #0330 | Địa chỉ PC: 0x069714 | Địa chỉ FDE: 0x119960 | Kích thước: 224 bytes
//   0x069714: D10143FF  sub      sp, sp, #0x50
//   0x069718: F90013F5  str      x21, [sp, #0x20]
//   0x06971c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x069720: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0330_0x069714(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069714ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x119960ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #0331 | PC: 0x0697f4 | FDE: 0x1190d8 | Size: 228 bytes [_ZNSt6__ndk112__hash_tableIPN11fast_engine3ObjENS1_11ObjHashFuncENS1_9EqualFuncENS_9allocatorIS3_EEE6rehashEm]
// Hàm FDE #0331 | Địa chỉ PC: 0x0697f4 | Địa chỉ FDE: 0x1190d8 | Kích thước: 228 bytes
//   0x0697f4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0697f8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0697fc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x069800: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0331_0x0697f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0697f4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1190d8ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #0332 | PC: 0x0698d8 | FDE: 0x1190f8 | Size: 256 bytes [_ZNSt6__ndk112__hash_tableIPN11fast_engine3ObjENS1_11ObjHashFuncENS1_9EqualFuncENS_9allocatorIS3_EEE8__rehashEm]
// Hàm FDE #0332 | Địa chỉ PC: 0x0698d8 | Địa chỉ FDE: 0x1190f8 | Kích thước: 256 bytes
//   0x0698d8: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0698dc: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0698e0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0698e4: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0332_0x0698d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0698d8ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1190f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0333 | PC: 0x069ab0 | FDE: 0x119128 | Size: 256 bytes [_ZNSt6__ndk16vectorIPN11fast_engine9ModuleObjENS_9allocatorIS3_EEE21__push_back_slow_pathIRKS3_EEvOT_]
// Hàm FDE #0333 | Địa chỉ PC: 0x069ab0 | Địa chỉ FDE: 0x119128 | Kích thước: 256 bytes
//   0x069ab0: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x069ab4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x069ab8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x069abc: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0333_0x069ab0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069ab0ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x119128ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0334 | PC: 0x069bbc | FDE: 0x119e90 | Size: 96 bytes [_ZN11fast_engine12AllocMapTypeEPNS_6EngineE]
// Hàm FDE #0334 | Địa chỉ PC: 0x069bbc | Địa chỉ FDE: 0x119e90 | Kích thước: 96 bytes
//   0x069bbc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x069bc0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x069bc4: 910043FD  add      x29, sp, #0x10
//   0x069bc8: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0334_0x069bbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069bbcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x119e90ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0335 | PC: 0x069c1c | FDE: 0x119988 | Size: 68 bytes [_ZN11fast_engine11InitMapTypeEPNS_6EngineE]
// Hàm FDE #0335 | Địa chỉ PC: 0x069c1c | Địa chỉ FDE: 0x119988 | Kích thước: 68 bytes
//   0x069c1c: D00006A8  adrp     x8, #0x13f000
//   0x069c20: F9469D08  ldr      x8, [x8, #0xd38]
//   0x069c24: D00006AB  adrp     x11, #0x13f000
//   0x069c28: 9000000C  adrp     x12, #0x69000
static inline uint64_t fde_func_0335_0x069c1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069c1cULL ^ (static_cast<uint64_t>(0xd00006a8ULL) << 13);
    acc = (acc + a1 + 0xf9469d08ULL) ^ 0x119988ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0336 | PC: 0x069c60 | FDE: 0x119eb8 | Size: 256 bytes
// Hàm FDE #0336 | Địa chỉ PC: 0x069c60 | Địa chỉ FDE: 0x119eb8 | Kích thước: 256 bytes
//   0x069c60: D101C3FF  sub      sp, sp, #0x70
//   0x069c64: F90013F9  str      x25, [sp, #0x20]
//   0x069c68: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x069c6c: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0336_0x069c60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069c60ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x119eb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0337 | PC: 0x069e38 | FDE: 0x119ee8 | Size: 256 bytes
// Hàm FDE #0337 | Địa chỉ PC: 0x069e38 | Địa chỉ FDE: 0x119ee8 | Kích thước: 256 bytes
//   0x069e38: D101C3FF  sub      sp, sp, #0x70
//   0x069e3c: F90023F5  str      x21, [sp, #0x40]
//   0x069e40: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x069e44: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0337_0x069e38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069e38ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x119ee8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0338 | PC: 0x069f50 | FDE: 0x1199a0 | Size: 256 bytes
// Hàm FDE #0338 | Địa chỉ PC: 0x069f50 | Địa chỉ FDE: 0x1199a0 | Kích thước: 256 bytes
//   0x069f50: D10203FF  sub      sp, sp, #0x80
//   0x069f54: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x069f58: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x069f5c: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_0338_0x069f50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069f50ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90367faULL) ^ 0x1199a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0339 | PC: 0x06a118 | FDE: 0x119f10 | Size: 96 bytes [_ZN11fast_engine12AllocZipTypeEPNS_6EngineE]
// Hàm FDE #0339 | Địa chỉ PC: 0x06a118 | Địa chỉ FDE: 0x119f10 | Kích thước: 96 bytes
//   0x06a118: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06a11c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06a120: 910043FD  add      x29, sp, #0x10
//   0x06a124: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0339_0x06a118(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a118ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x119f10ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0340 | PC: 0x06a178 | FDE: 0x1199d0 | Size: 68 bytes [_ZN11fast_engine11InitZipTypeEPNS_6EngineE]
// Hàm FDE #0340 | Địa chỉ PC: 0x06a178 | Địa chỉ FDE: 0x1199d0 | Kích thước: 68 bytes
//   0x06a178: B00006A8  adrp     x8, #0x13f000
//   0x06a17c: F9478108  ldr      x8, [x8, #0xf00]
//   0x06a180: B00006AB  adrp     x11, #0x13f000
//   0x06a184: 9000000C  adrp     x12, #0x6a000
static inline uint64_t fde_func_0340_0x06a178(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a178ULL ^ (static_cast<uint64_t>(0xb00006a8ULL) << 13);
    acc = (acc + a1 + 0xf9478108ULL) ^ 0x1199d0ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0341 | PC: 0x06a1bc | FDE: 0x119f38 | Size: 256 bytes
// Hàm FDE #0341 | Địa chỉ PC: 0x06a1bc | Địa chỉ FDE: 0x119f38 | Kích thước: 256 bytes
//   0x06a1bc: D101C3FF  sub      sp, sp, #0x70
//   0x06a1c0: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x06a1c4: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x06a1c8: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0341_0x06a1bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a1bcULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x119f38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0342 | PC: 0x06a3a8 | FDE: 0x119f70 | Size: 256 bytes
// Hàm FDE #0342 | Địa chỉ PC: 0x06a3a8 | Địa chỉ FDE: 0x119f70 | Kích thước: 256 bytes
//   0x06a3a8: D101C3FF  sub      sp, sp, #0x70
//   0x06a3ac: F90023F5  str      x21, [sp, #0x40]
//   0x06a3b0: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x06a3b4: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0342_0x06a3a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a3a8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x119f70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0343 | PC: 0x06a4c0 | FDE: 0x1199e8 | Size: 256 bytes
// Hàm FDE #0343 | Địa chỉ PC: 0x06a4c0 | Địa chỉ FDE: 0x1199e8 | Kích thước: 256 bytes
//   0x06a4c0: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x06a4c4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x06a4c8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x06a4cc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0343_0x06a4c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a4c0ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1199e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0344 | PC: 0x06a670 | FDE: 0x119f98 | Size: 96 bytes [_ZN11fast_engine17AllocReversedTypeEPNS_6EngineE]
// Hàm FDE #0344 | Địa chỉ PC: 0x06a670 | Địa chỉ FDE: 0x119f98 | Kích thước: 96 bytes
//   0x06a670: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06a674: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06a678: 910043FD  add      x29, sp, #0x10
//   0x06a67c: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0344_0x06a670(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a670ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x119f98ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0345 | PC: 0x06a6d0 | FDE: 0x119a10 | Size: 68 bytes [_ZN11fast_engine16InitReversedTypeEPNS_6EngineE]
// Hàm FDE #0345 | Địa chỉ PC: 0x06a6d0 | Địa chỉ FDE: 0x119a10 | Kích thước: 68 bytes
//   0x06a6d0: B00006A8  adrp     x8, #0x13f000
//   0x06a6d4: F9444108  ldr      x8, [x8, #0x880]
//   0x06a6d8: B00006AB  adrp     x11, #0x13f000
//   0x06a6dc: 9000000C  adrp     x12, #0x6a000
static inline uint64_t fde_func_0345_0x06a6d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a6d0ULL ^ (static_cast<uint64_t>(0xb00006a8ULL) << 13);
    acc = (acc + a1 + 0xf9444108ULL) ^ 0x119a10ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0346 | PC: 0x06a714 | FDE: 0x119fc0 | Size: 256 bytes
// Hàm FDE #0346 | Địa chỉ PC: 0x06a714 | Địa chỉ FDE: 0x119fc0 | Kích thước: 256 bytes
//   0x06a714: D10143FF  sub      sp, sp, #0x50
//   0x06a718: F9000BF7  str      x23, [sp, #0x10]
//   0x06a71c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x06a720: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0346_0x06a714(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a714ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x119fc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0347 | PC: 0x06a834 | FDE: 0x119ff0 | Size: 256 bytes
// Hàm FDE #0347 | Địa chỉ PC: 0x06a834 | Địa chỉ FDE: 0x119ff0 | Kích thước: 256 bytes
//   0x06a834: D101C3FF  sub      sp, sp, #0x70
//   0x06a838: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x06a83c: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x06a840: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0347_0x06a834(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a834ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x119ff0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0348 | PC: 0x06aa38 | FDE: 0x119a28 | Size: 220 bytes
// Hàm FDE #0348 | Địa chỉ PC: 0x06aa38 | Địa chỉ FDE: 0x119a28 | Kích thước: 220 bytes
//   0x06aa38: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x06aa3c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06aa40: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06aa44: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0348_0x06aa38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06aa38ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x119a28ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #0349 | PC: 0x06ab14 | FDE: 0x11a020 | Size: 96 bytes [_ZN11fast_engine18AllocEnumerateTypeEPNS_6EngineE]
// Hàm FDE #0349 | Địa chỉ PC: 0x06ab14 | Địa chỉ FDE: 0x11a020 | Kích thước: 96 bytes
//   0x06ab14: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06ab18: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06ab1c: 910043FD  add      x29, sp, #0x10
//   0x06ab20: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0349_0x06ab14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ab14ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11a020ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0350 | PC: 0x06ab74 | FDE: 0x119a48 | Size: 68 bytes [_ZN11fast_engine17InitEnumerateTypeEPNS_6EngineE]
// Hàm FDE #0350 | Địa chỉ PC: 0x06ab74 | Địa chỉ FDE: 0x119a48 | Kích thước: 68 bytes
//   0x06ab74: B00006A8  adrp     x8, #0x13f000
//   0x06ab78: F9451108  ldr      x8, [x8, #0xa20]
//   0x06ab7c: B00006AB  adrp     x11, #0x13f000
//   0x06ab80: 9000000C  adrp     x12, #0x6a000
static inline uint64_t fde_func_0350_0x06ab74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ab74ULL ^ (static_cast<uint64_t>(0xb00006a8ULL) << 13);
    acc = (acc + a1 + 0xf9451108ULL) ^ 0x119a48ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0351 | PC: 0x06abb8 | FDE: 0x11a048 | Size: 256 bytes
// Hàm FDE #0351 | Địa chỉ PC: 0x06abb8 | Địa chỉ FDE: 0x11a048 | Kích thước: 256 bytes
//   0x06abb8: D101C3FF  sub      sp, sp, #0x70
//   0x06abbc: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x06abc0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x06abc4: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0351_0x06abb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06abb8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x11a048ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0352 | PC: 0x06adfc | FDE: 0x11a078 | Size: 256 bytes
// Hàm FDE #0352 | Địa chỉ PC: 0x06adfc | Địa chỉ FDE: 0x11a078 | Kích thước: 256 bytes
//   0x06adfc: D101C3FF  sub      sp, sp, #0x70
//   0x06ae00: F90023F5  str      x21, [sp, #0x40]
//   0x06ae04: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x06ae08: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0352_0x06adfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06adfcULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x11a078ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0353 | PC: 0x06af14 | FDE: 0x11a0a0 | Size: 256 bytes
// Hàm FDE #0353 | Địa chỉ PC: 0x06af14 | Địa chỉ FDE: 0x11a0a0 | Kích thước: 256 bytes
//   0x06af14: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x06af18: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x06af1c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x06af20: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0353_0x06af14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06af14ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x11a0a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0354 | PC: 0x06b124 | FDE: 0x11a0d0 | Size: 96 bytes [_ZN11fast_engine15AllocFilterTypeEPNS_6EngineE]
// Hàm FDE #0354 | Địa chỉ PC: 0x06b124 | Địa chỉ FDE: 0x11a0d0 | Kích thước: 96 bytes
//   0x06b124: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06b128: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06b12c: 910043FD  add      x29, sp, #0x10
//   0x06b130: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0354_0x06b124(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06b124ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11a0d0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0355 | PC: 0x06b184 | FDE: 0x119a60 | Size: 80 bytes [_ZN11fast_engine14InitFilterTypeEPNS_6EngineE]
// Hàm FDE #0355 | Địa chỉ PC: 0x06b184 | Địa chỉ FDE: 0x119a60 | Kích thước: 80 bytes
//   0x06b184: 900006A8  adrp     x8, #0x13f000
//   0x06b188: F9447908  ldr      x8, [x8, #0x8f0]
//   0x06b18c: 900006AC  adrp     x12, #0x13f000
//   0x06b190: 9000000D  adrp     x13, #0x6b000
static inline uint64_t fde_func_0355_0x06b184(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06b184ULL ^ (static_cast<uint64_t>(0x900006a8ULL) << 13);
    acc = (acc + a1 + 0xf9447908ULL) ^ 0x119a60ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0356 | PC: 0x06b1d4 | FDE: 0x11a0f8 | Size: 256 bytes
// Hàm FDE #0356 | Địa chỉ PC: 0x06b1d4 | Địa chỉ FDE: 0x11a0f8 | Kích thước: 256 bytes
//   0x06b1d4: D101C3FF  sub      sp, sp, #0x70
//   0x06b1d8: F9001BF7  str      x23, [sp, #0x30]
//   0x06b1dc: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x06b1e0: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0356_0x06b1d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06b1d4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x11a0f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0357 | PC: 0x06b338 | FDE: 0x11a128 | Size: 256 bytes
// Hàm FDE #0357 | Địa chỉ PC: 0x06b338 | Địa chỉ FDE: 0x11a128 | Kích thước: 256 bytes
//   0x06b338: D10183FF  sub      sp, sp, #0x60
//   0x06b33c: F90013F7  str      x23, [sp, #0x20]
//   0x06b340: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x06b344: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0357_0x06b338(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06b338ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x11a128ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0358 | PC: 0x06b4a0 | FDE: 0x11a158 | Size: 256 bytes
// Hàm FDE #0358 | Địa chỉ PC: 0x06b4a0 | Địa chỉ FDE: 0x11a158 | Kích thước: 256 bytes
//   0x06b4a0: D101C3FF  sub      sp, sp, #0x70
//   0x06b4a4: F90023F5  str      x21, [sp, #0x40]
//   0x06b4a8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x06b4ac: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0358_0x06b4a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06b4a0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x11a158ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0359 | PC: 0x06b5b8 | FDE: 0x119a78 | Size: 256 bytes
// Hàm FDE #0359 | Địa chỉ PC: 0x06b5b8 | Địa chỉ FDE: 0x119a78 | Kích thước: 256 bytes
//   0x06b5b8: D10243FF  sub      sp, sp, #0x90
//   0x06b5bc: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x06b5c0: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x06b5c4: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0359_0x06b5b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06b5b8ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x119a78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0360 | PC: 0x06b7d8 | FDE: 0x11a180 | Size: 256 bytes [_ZN11fast_engine17InitBuiltinModuleEPNS_10FastEngineEPNS_6EngineE]
// Hàm FDE #0360 | Địa chỉ PC: 0x06b7d8 | Địa chỉ FDE: 0x11a180 | Kích thước: 256 bytes
//   0x06b7d8: D101C3FF  sub      sp, sp, #0x70
//   0x06b7dc: F90013F9  str      x25, [sp, #0x20]
//   0x06b7e0: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x06b7e4: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0360_0x06b7d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06b7d8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x11a180ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0361 | PC: 0x06c3fc | FDE: 0x119aa8 | Size: 128 bytes
// Hàm FDE #0361 | Địa chỉ PC: 0x06c3fc | Địa chỉ FDE: 0x119aa8 | Kích thước: 128 bytes
//   0x06c3fc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06c400: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06c404: 910043FD  add      x29, sp, #0x10
//   0x06c408: AA0203F4  mov      x20, x2
static inline uint64_t fde_func_0361_0x06c3fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06c3fcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x119aa8ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0362 | PC: 0x06c47c | FDE: 0x119ac8 | Size: 128 bytes
// Hàm FDE #0362 | Địa chỉ PC: 0x06c47c | Địa chỉ FDE: 0x119ac8 | Kích thước: 128 bytes
//   0x06c47c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06c480: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06c484: 910043FD  add      x29, sp, #0x10
//   0x06c488: AA0203F4  mov      x20, x2
static inline uint64_t fde_func_0362_0x06c47c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06c47cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x119ac8ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0363 | PC: 0x06c4fc | FDE: 0x11a1b0 | Size: 256 bytes
// Hàm FDE #0363 | Địa chỉ PC: 0x06c4fc | Địa chỉ FDE: 0x11a1b0 | Kích thước: 256 bytes
//   0x06c4fc: D10203FF  sub      sp, sp, #0x80
//   0x06c500: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x06c504: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x06c508: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_0363_0x06c4fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06c4fcULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90367faULL) ^ 0x11a1b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0364 | PC: 0x06c888 | FDE: 0x11a1e8 | Size: 232 bytes
// Hàm FDE #0364 | Địa chỉ PC: 0x06c888 | Địa chỉ FDE: 0x11a1e8 | Kích thước: 232 bytes
//   0x06c888: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x06c88c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06c890: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06c894: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0364_0x06c888(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06c888ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11a1e8ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0365 | PC: 0x06c970 | FDE: 0x119ae8 | Size: 124 bytes
// Hàm FDE #0365 | Địa chỉ PC: 0x06c970 | Địa chỉ FDE: 0x119ae8 | Kích thước: 124 bytes
//   0x06c970: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06c974: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06c978: 910043FD  add      x29, sp, #0x10
//   0x06c97c: AA0203F4  mov      x20, x2
static inline uint64_t fde_func_0365_0x06c970(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06c970ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x119ae8ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0366 | PC: 0x06c9ec | FDE: 0x119b08 | Size: 168 bytes
// Hàm FDE #0366 | Địa chỉ PC: 0x06c9ec | Địa chỉ FDE: 0x119b08 | Kích thước: 168 bytes
//   0x06c9ec: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06c9f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06c9f4: 910043FD  add      x29, sp, #0x10
//   0x06c9f8: AA0203F4  mov      x20, x2
static inline uint64_t fde_func_0366_0x06c9ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06c9ecULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x119b08ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #0367 | PC: 0x06ca94 | FDE: 0x119b28 | Size: 208 bytes
// Hàm FDE #0367 | Địa chỉ PC: 0x06ca94 | Địa chỉ FDE: 0x119b28 | Kích thước: 208 bytes
//   0x06ca94: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x06ca98: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06ca9c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06caa0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0367_0x06ca94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ca94ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x119b28ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #0368 | PC: 0x06cb64 | FDE: 0x119b48 | Size: 224 bytes
// Hàm FDE #0368 | Địa chỉ PC: 0x06cb64 | Địa chỉ FDE: 0x119b48 | Kích thước: 224 bytes
//   0x06cb64: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06cb68: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06cb6c: 910043FD  add      x29, sp, #0x10
//   0x06cb70: AA0203F4  mov      x20, x2
static inline uint64_t fde_func_0368_0x06cb64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06cb64ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x119b48ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #0369 | PC: 0x06cc44 | FDE: 0x11a210 | Size: 256 bytes
// Hàm FDE #0369 | Địa chỉ PC: 0x06cc44 | Địa chỉ FDE: 0x11a210 | Kích thước: 256 bytes
//   0x06cc44: D101C3FF  sub      sp, sp, #0x70
//   0x06cc48: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x06cc4c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x06cc50: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0369_0x06cc44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06cc44ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x11a210ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0370 | PC: 0x06ce10 | FDE: 0x119b68 | Size: 24 bytes
// Hàm FDE #0370 | Địa chỉ PC: 0x06ce10 | Địa chỉ FDE: 0x119b68 | Kích thước: 24 bytes
//   0x06ce10: AA0003E8  mov      x8, x0
//   0x06ce14: AA0303E1  mov      x1, x3
//   0x06ce18: 52800083  mov      w3, #4
//   0x06ce1c: AA0203E0  mov      x0, x2
static inline uint64_t fde_func_0370_0x06ce10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ce10ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xaa0303e1ULL) ^ 0x119b68ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0371 | PC: 0x06ce28 | FDE: 0x119b80 | Size: 24 bytes
// Hàm FDE #0371 | Địa chỉ PC: 0x06ce28 | Địa chỉ FDE: 0x119b80 | Kích thước: 24 bytes
//   0x06ce28: AA0003E8  mov      x8, x0
//   0x06ce2c: AA0303E1  mov      x1, x3
//   0x06ce30: AA0203E0  mov      x0, x2
//   0x06ce34: AA0803E2  mov      x2, x8
static inline uint64_t fde_func_0371_0x06ce28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ce28ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xaa0303e1ULL) ^ 0x119b80ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0372 | PC: 0x06ce40 | FDE: 0x119b98 | Size: 8 bytes
// Hàm FDE #0372 | Địa chỉ PC: 0x06ce40 | Địa chỉ FDE: 0x119b98 | Kích thước: 8 bytes
//   0x06ce40: AA0203E1  mov      x1, x2
//   0x06ce44: 17FF6207  b        #0x45660
static inline uint64_t fde_func_0372_0x06ce40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ce40ULL ^ (static_cast<uint64_t>(0xaa0203e1ULL) << 13);
    acc = (acc + a1 + 0x17ff6207ULL) ^ 0x119b98ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0373 | PC: 0x06ce48 | FDE: 0x11a248 | Size: 256 bytes
// Hàm FDE #0373 | Địa chỉ PC: 0x06ce48 | Địa chỉ FDE: 0x11a248 | Kích thước: 256 bytes
//   0x06ce48: D10283FF  sub      sp, sp, #0xa0
//   0x06ce4c: FD0023E8  str      d8, [sp, #0x40]
//   0x06ce50: F90027FB  str      x27, [sp, #0x48]
//   0x06ce54: A90567FA  stp      x26, x25, [sp, #0x50]
static inline uint64_t fde_func_0373_0x06ce48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ce48ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xfd0023e8ULL) ^ 0x11a248ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0374 | PC: 0x06d370 | FDE: 0x119bb0 | Size: 252 bytes
// Hàm FDE #0374 | Địa chỉ PC: 0x06d370 | Địa chỉ FDE: 0x119bb0 | Kích thước: 252 bytes
//   0x06d370: D10183FF  sub      sp, sp, #0x60
//   0x06d374: F9001BF5  str      x21, [sp, #0x30]
//   0x06d378: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x06d37c: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0374_0x06d370(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06d370ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x119bb0ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #0375 | PC: 0x06d46c | FDE: 0x11a280 | Size: 256 bytes
// Hàm FDE #0375 | Địa chỉ PC: 0x06d46c | Địa chỉ FDE: 0x11a280 | Kích thước: 256 bytes
//   0x06d46c: D10143FF  sub      sp, sp, #0x50
//   0x06d470: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x06d474: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x06d478: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0375_0x06d46c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06d46cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x11a280ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0376 | PC: 0x06d8cc | FDE: 0x11a2b0 | Size: 256 bytes
// Hàm FDE #0376 | Địa chỉ PC: 0x06d8cc | Địa chỉ FDE: 0x11a2b0 | Kích thước: 256 bytes
//   0x06d8cc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x06d8d0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06d8d4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06d8d8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0376_0x06d8cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06d8ccULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11a2b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0377 | PC: 0x06db24 | FDE: 0x119bd0 | Size: 96 bytes
// Hàm FDE #0377 | Địa chỉ PC: 0x06db24 | Địa chỉ FDE: 0x119bd0 | Kích thước: 96 bytes
//   0x06db24: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06db28: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06db2c: 910043FD  add      x29, sp, #0x10
//   0x06db30: AA0203F3  mov      x19, x2
static inline uint64_t fde_func_0377_0x06db24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06db24ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x119bd0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0378 | PC: 0x06db84 | FDE: 0x119bf0 | Size: 256 bytes
// Hàm FDE #0378 | Địa chỉ PC: 0x06db84 | Địa chỉ FDE: 0x119bf0 | Kích thước: 256 bytes
//   0x06db84: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x06db88: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x06db8c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x06db90: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0378_0x06db84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06db84ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x119bf0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0379 | PC: 0x06dd2c | FDE: 0x119c18 | Size: 256 bytes
// Hàm FDE #0379 | Địa chỉ PC: 0x06dd2c | Địa chỉ FDE: 0x119c18 | Kích thước: 256 bytes
//   0x06dd2c: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x06dd30: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x06dd34: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x06dd38: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0379_0x06dd2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06dd2cULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x119c18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0380 | PC: 0x06de9c | FDE: 0x119c40 | Size: 52 bytes
// Hàm FDE #0380 | Địa chỉ PC: 0x06de9c | Địa chỉ FDE: 0x119c40 | Kích thước: 52 bytes
//   0x06de9c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x06dea0: 910003FD  mov      x29, sp
//   0x06dea4: AA0203E0  mov      x0, x2
//   0x06dea8: 97FF521E  bl       #0x42720
static inline uint64_t fde_func_0380_0x06de9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06de9cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x119c40ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0381 | PC: 0x06ded0 | FDE: 0x119c60 | Size: 12 bytes
// Hàm FDE #0381 | Địa chỉ PC: 0x06ded0 | Địa chỉ FDE: 0x119c60 | Kích thước: 12 bytes
//   0x06ded0: AA0003E1  mov      x1, x0
//   0x06ded4: AA0203E0  mov      x0, x2
//   0x06ded8: 17FF51AE  b        #0x42590
static inline uint64_t fde_func_0381_0x06ded0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ded0ULL ^ (static_cast<uint64_t>(0xaa0003e1ULL) << 13);
    acc = (acc + a1 + 0xaa0203e0ULL) ^ 0x119c60ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0382 | PC: 0x06dedc | FDE: 0x11a2d8 | Size: 256 bytes
// Hàm FDE #0382 | Địa chỉ PC: 0x06dedc | Địa chỉ FDE: 0x11a2d8 | Kích thước: 256 bytes
//   0x06dedc: D10383FF  sub      sp, sp, #0xe0
//   0x06dee0: F90043FB  str      x27, [sp, #0x80]
//   0x06dee4: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x06dee8: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_0382_0x06dedc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06dedcULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xf90043fbULL) ^ 0x11a2d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0383 | PC: 0x06e300 | FDE: 0x119c78 | Size: 96 bytes
// Hàm FDE #0383 | Địa chỉ PC: 0x06e300 | Địa chỉ FDE: 0x119c78 | Kích thước: 96 bytes
//   0x06e300: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06e304: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06e308: 910043FD  add      x29, sp, #0x10
//   0x06e30c: AA0203F3  mov      x19, x2
static inline uint64_t fde_func_0383_0x06e300(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e300ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x119c78ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0384 | PC: 0x06e360 | FDE: 0x119c98 | Size: 256 bytes
// Hàm FDE #0384 | Địa chỉ PC: 0x06e360 | Địa chỉ FDE: 0x119c98 | Kích thước: 256 bytes
//   0x06e360: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x06e364: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06e368: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06e36c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0384_0x06e360(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e360ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x119c98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0385 | PC: 0x06e4b8 | FDE: 0x11a310 | Size: 236 bytes
// Hàm FDE #0385 | Địa chỉ PC: 0x06e4b8 | Địa chỉ FDE: 0x11a310 | Kích thước: 236 bytes
//   0x06e4b8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x06e4bc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06e4c0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06e4c4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0385_0x06e4b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e4b8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x11a310ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0386 | PC: 0x06e5a4 | FDE: 0x119cc0 | Size: 96 bytes
// Hàm FDE #0386 | Địa chỉ PC: 0x06e5a4 | Địa chỉ FDE: 0x119cc0 | Kích thước: 96 bytes
//   0x06e5a4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06e5a8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06e5ac: 910043FD  add      x29, sp, #0x10
//   0x06e5b0: AA0203F3  mov      x19, x2
static inline uint64_t fde_func_0386_0x06e5a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e5a4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x119cc0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0387 | PC: 0x06e604 | FDE: 0x11a338 | Size: 256 bytes
// Hàm FDE #0387 | Địa chỉ PC: 0x06e604 | Địa chỉ FDE: 0x11a338 | Kích thước: 256 bytes
//   0x06e604: D10283FF  sub      sp, sp, #0xa0
//   0x06e608: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x06e60c: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x06e610: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0387_0x06e604(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e604ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x11a338ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0388 | PC: 0x06edd8 | FDE: 0x119ce0 | Size: 152 bytes
// Hàm FDE #0388 | Địa chỉ PC: 0x06edd8 | Địa chỉ FDE: 0x119ce0 | Kích thước: 152 bytes
//   0x06edd8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x06eddc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06ede0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06ede4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0388_0x06edd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06edd8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x119ce0ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0389 | PC: 0x06ee70 | FDE: 0x11a370 | Size: 248 bytes
// Hàm FDE #0389 | Địa chỉ PC: 0x06ee70 | Địa chỉ FDE: 0x11a370 | Kích thước: 248 bytes
//   0x06ee70: D10183FF  sub      sp, sp, #0x60
//   0x06ee74: F90013F7  str      x23, [sp, #0x20]
//   0x06ee78: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x06ee7c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0389_0x06ee70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ee70ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x11a370ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0390 | PC: 0x06ef68 | FDE: 0x11a3a0 | Size: 204 bytes
// Hàm FDE #0390 | Địa chỉ PC: 0x06ef68 | Địa chỉ FDE: 0x11a3a0 | Kích thước: 204 bytes
//   0x06ef68: D10103FF  sub      sp, sp, #0x40
//   0x06ef6c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x06ef70: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x06ef74: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0390_0x06ef68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ef68ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x11a3a0ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #0391 | PC: 0x06f034 | FDE: 0x119d08 | Size: 36 bytes [_ZN11fast_engine9MapObjectD0Ev]
// Hàm FDE #0391 | Địa chỉ PC: 0x06f034 | Địa chỉ FDE: 0x119d08 | Kích thước: 36 bytes
//   0x06f034: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x06f038: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06f03c: 910043FD  add      x29, sp, #0x10
//   0x06f040: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0391_0x06f034(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f034ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x119d08ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0392 | PC: 0x06f058 | FDE: 0x119d28 | Size: 148 bytes [_ZN11fast_engine9MapObject5ClearEPNS_6EngineE]
// Hàm FDE #0392 | Địa chỉ PC: 0x06f058 | Địa chỉ FDE: 0x119d28 | Kích thước: 148 bytes
//   0x06f058: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06f05c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06f060: 910043FD  add      x29, sp, #0x10
//   0x06f064: F9402008  ldr      x8, [x0, #0x40]
static inline uint64_t fde_func_0392_0x06f058(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f058ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x119d28ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0393 | PC: 0x06f0ec | FDE: 0x119d48 | Size: 156 bytes
// Hàm FDE #0393 | Địa chỉ PC: 0x06f0ec | Địa chỉ FDE: 0x119d48 | Kích thước: 156 bytes
//   0x06f0ec: D10443FF  sub      sp, sp, #0x110
//   0x06f0f0: A90F4FFC  stp      x28, x19, [sp, #0xf0]
//   0x06f0f4: A9107BFD  stp      x29, x30, [sp, #0x100]
//   0x06f0f8: 910403FD  add      x29, sp, #0x100
static inline uint64_t fde_func_0393_0x06f0ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f0ecULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90f4ffcULL) ^ 0x119d48ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0394 | PC: 0x06f188 | FDE: 0x119d68 | Size: 36 bytes [_ZN11fast_engine9ZipObjectD0Ev]
// Hàm FDE #0394 | Địa chỉ PC: 0x06f188 | Địa chỉ FDE: 0x119d68 | Kích thước: 36 bytes
//   0x06f188: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x06f18c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06f190: 910043FD  add      x29, sp, #0x10
//   0x06f194: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0394_0x06f188(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f188ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x119d68ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0395 | PC: 0x06f1ac | FDE: 0x119d88 | Size: 148 bytes [_ZN11fast_engine9ZipObject5ClearEPNS_6EngineE]
// Hàm FDE #0395 | Địa chỉ PC: 0x06f1ac | Địa chỉ FDE: 0x119d88 | Kích thước: 148 bytes
//   0x06f1ac: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06f1b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06f1b4: 910043FD  add      x29, sp, #0x10
//   0x06f1b8: F9402408  ldr      x8, [x0, #0x48]
static inline uint64_t fde_func_0395_0x06f1ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f1acULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x119d88ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0396 | PC: 0x06f240 | FDE: 0x119da8 | Size: 36 bytes [_ZN11fast_engine8ReversedD0Ev]
// Hàm FDE #0396 | Địa chỉ PC: 0x06f240 | Địa chỉ FDE: 0x119da8 | Kích thước: 36 bytes
//   0x06f240: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x06f244: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06f248: 910043FD  add      x29, sp, #0x10
//   0x06f24c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0396_0x06f240(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f240ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x119da8ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0397 | PC: 0x06f264 | FDE: 0x119dc8 | Size: 56 bytes [_ZN11fast_engine8Reversed5ClearEPNS_6EngineE]
// Hàm FDE #0397 | Địa chỉ PC: 0x06f264 | Địa chỉ FDE: 0x119dc8 | Kích thước: 56 bytes
//   0x06f264: F9402408  ldr      x8, [x0, #0x48]
//   0x06f268: B4000128  cbz      x8, #0x6f28c
//   0x06f26c: B9402109  ldr      w9, [x8, #0x20]
//   0x06f270: 7100093F  cmp      w9, #2
static inline uint64_t fde_func_0397_0x06f264(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f264ULL ^ (static_cast<uint64_t>(0xf9402408ULL) << 13);
    acc = (acc + a1 + 0xb4000128ULL) ^ 0x119dc8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0398 | PC: 0x06f29c | FDE: 0x119de0 | Size: 36 bytes [_ZN11fast_engine9EnumerateD0Ev]
// Hàm FDE #0398 | Địa chỉ PC: 0x06f29c | Địa chỉ FDE: 0x119de0 | Kích thước: 36 bytes
//   0x06f29c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x06f2a0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06f2a4: 910043FD  add      x29, sp, #0x10
//   0x06f2a8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0398_0x06f29c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f29cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x119de0ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0399 | PC: 0x06f2c0 | FDE: 0x119e00 | Size: 148 bytes [_ZN11fast_engine9Enumerate5ClearEPNS_6EngineE]
// Hàm FDE #0399 | Địa chỉ PC: 0x06f2c0 | Địa chỉ FDE: 0x119e00 | Kích thước: 148 bytes
//   0x06f2c0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06f2c4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06f2c8: 910043FD  add      x29, sp, #0x10
//   0x06f2cc: F9402408  ldr      x8, [x0, #0x48]
static inline uint64_t fde_func_0399_0x06f2c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f2c0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x119e00ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0400 | PC: 0x06f354 | FDE: 0x119e20 | Size: 36 bytes [_ZN11fast_engine6FilterD0Ev]
// Hàm FDE #0400 | Địa chỉ PC: 0x06f354 | Địa chỉ FDE: 0x119e20 | Kích thước: 36 bytes
//   0x06f354: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x06f358: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06f35c: 910043FD  add      x29, sp, #0x10
//   0x06f360: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0400_0x06f354(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f354ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x119e20ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0401 | PC: 0x06f378 | FDE: 0x119e40 | Size: 148 bytes [_ZN11fast_engine6Filter5ClearEPNS_6EngineE]
// Hàm FDE #0401 | Địa chỉ PC: 0x06f378 | Địa chỉ FDE: 0x119e40 | Kích thước: 148 bytes
//   0x06f378: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06f37c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06f380: 910043FD  add      x29, sp, #0x10
//   0x06f384: F9402408  ldr      x8, [x0, #0x48]
static inline uint64_t fde_func_0401_0x06f378(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f378ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x119e40ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0402 | PC: 0x06f40c | FDE: 0x119e60 | Size: 256 bytes
// Hàm FDE #0402 | Địa chỉ PC: 0x06f40c | Địa chỉ FDE: 0x119e60 | Kích thước: 256 bytes
//   0x06f40c: D10303FF  sub      sp, sp, #0xc0
//   0x06f410: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x06f414: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x06f418: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_0402_0x06f40c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f40cULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x119e60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0403 | PC: 0x06f930 | FDE: 0x11a430 | Size: 96 bytes [_ZN11fast_engine20AllocOrderedDictTypeEPNS_6EngineE]
// Hàm FDE #0403 | Địa chỉ PC: 0x06f930 | Địa chỉ FDE: 0x11a430 | Kích thước: 96 bytes
//   0x06f930: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06f934: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06f938: 910043FD  add      x29, sp, #0x10
//   0x06f93c: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0403_0x06f930(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f930ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11a430ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0404 | PC: 0x06f990 | FDE: 0x11a3c8 | Size: 220 bytes [_ZN11fast_engine19InitOrderedDictTypeEPNS_6EngineE]
// Hàm FDE #0404 | Địa chỉ PC: 0x06f990 | Địa chỉ FDE: 0x11a3c8 | Kích thước: 220 bytes
//   0x06f990: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x06f994: 910003FD  mov      x29, sp
//   0x06f998: 90000688  adrp     x8, #0x13f000
//   0x06f99c: 90000689  adrp     x9, #0x13f000
static inline uint64_t fde_func_0404_0x06f990(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f990ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x11a3c8ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #0405 | PC: 0x06fa6c | FDE: 0x11a3e8 | Size: 256 bytes
// Hàm FDE #0405 | Địa chỉ PC: 0x06fa6c | Địa chỉ FDE: 0x11a3e8 | Kích thước: 256 bytes
//   0x06fa6c: D10203FF  sub      sp, sp, #0x80
//   0x06fa70: F90023F7  str      x23, [sp, #0x40]
//   0x06fa74: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x06fa78: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_0405_0x06fa6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06fa6cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x11a3e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0406 | PC: 0x06fbc4 | FDE: 0x11a458 | Size: 256 bytes
// Hàm FDE #0406 | Địa chỉ PC: 0x06fbc4 | Địa chỉ FDE: 0x11a458 | Kích thước: 256 bytes
//   0x06fbc4: D101C3FF  sub      sp, sp, #0x70
//   0x06fbc8: F90013F9  str      x25, [sp, #0x20]
//   0x06fbcc: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x06fbd0: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0406_0x06fbc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06fbc4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x11a458ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0407 | PC: 0x06fedc | FDE: 0x11a410 | Size: 136 bytes
// Hàm FDE #0407 | Địa chỉ PC: 0x06fedc | Địa chỉ FDE: 0x11a410 | Kích thước: 136 bytes
//   0x06fedc: D10103FF  sub      sp, sp, #0x40
//   0x06fee0: F90013F3  str      x19, [sp, #0x20]
//   0x06fee4: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x06fee8: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0407_0x06fedc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06fedcULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x11a410ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #0408 | PC: 0x06ff64 | FDE: 0x11a488 | Size: 256 bytes [_ZN11fast_engine21InitCollectionsModuleEPNS_10FastEngineEPNS_6EngineE]
// Hàm FDE #0408 | Địa chỉ PC: 0x06ff64 | Địa chỉ FDE: 0x11a488 | Kích thước: 256 bytes
//   0x06ff64: D101C3FF  sub      sp, sp, #0x70
//   0x06ff68: F9001BF7  str      x23, [sp, #0x30]
//   0x06ff6c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x06ff70: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0408_0x06ff64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ff64ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x11a488ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0409 | PC: 0x0701f0 | FDE: 0x11a4b8 | Size: 256 bytes [_ZN11fast_engine14InitCopyModuleEPNS_10FastEngineEPNS_6EngineE]
// Hàm FDE #0409 | Địa chỉ PC: 0x0701f0 | Địa chỉ FDE: 0x11a4b8 | Kích thước: 256 bytes
//   0x0701f0: D10183FF  sub      sp, sp, #0x60
//   0x0701f4: F90013F7  str      x23, [sp, #0x20]
//   0x0701f8: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0701fc: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0409_0x0701f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0701f0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x11a4b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0410 | PC: 0x0703c0 | FDE: 0x11a4e8 | Size: 256 bytes
// Hàm FDE #0410 | Địa chỉ PC: 0x0703c0 | Địa chỉ FDE: 0x11a4e8 | Kích thước: 256 bytes
//   0x0703c0: D101C3FF  sub      sp, sp, #0x70
//   0x0703c4: F90013F9  str      x25, [sp, #0x20]
//   0x0703c8: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0703cc: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0410_0x0703c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0703c0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x11a4e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0411 | PC: 0x0706ac | FDE: 0x11a518 | Size: 256 bytes
// Hàm FDE #0411 | Địa chỉ PC: 0x0706ac | Địa chỉ FDE: 0x11a518 | Kích thước: 256 bytes
//   0x0706ac: D101C3FF  sub      sp, sp, #0x70
//   0x0706b0: F9001BF7  str      x23, [sp, #0x30]
//   0x0706b4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0706b8: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0411_0x0706ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0706acULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x11a518ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0412 | PC: 0x0709c0 | FDE: 0x11a548 | Size: 256 bytes [_ZN11fast_engine8DateTime5ClearEPNS_6EngineE]
// Hàm FDE #0412 | Địa chỉ PC: 0x0709c0 | Địa chỉ FDE: 0x11a548 | Kích thước: 256 bytes
//   0x0709c0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0709c4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0709c8: 910043FD  add      x29, sp, #0x10
//   0x0709cc: F9402008  ldr      x8, [x0, #0x40]
static inline uint64_t fde_func_0412_0x0709c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0709c0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x11a548ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0413 | PC: 0x070b78 | FDE: 0x11a7a8 | Size: 256 bytes [_ZN11fast_engine8DateTimeC2EPNS_6EngineEPNS_7TypeObjEPNS_3ObjES6_S6_S6_S6_S6_S6_]
// Hàm FDE #0413 | Địa chỉ PC: 0x070b78 | Địa chỉ FDE: 0x11a7a8 | Kích thước: 256 bytes
//   0x070b78: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x070b7c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x070b80: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x070b84: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0413_0x070b78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070b78ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x11a7a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0414 | PC: 0x070d3c | FDE: 0x11a7d8 | Size: 256 bytes [_ZN11fast_engine8DateTimeC1EPNS_6EngineEPNS_7TypeObjEiiiiiii]
// Hàm FDE #0414 | Địa chỉ PC: 0x070d3c | Địa chỉ FDE: 0x11a7d8 | Kích thước: 256 bytes
//   0x070d3c: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x070d40: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x070d44: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x070d48: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0414_0x070d3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070d3cULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x11a7d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0415 | PC: 0x071204 | FDE: 0x11a810 | Size: 256 bytes [_ZNK11fast_engine8DateTime10FormatTimeERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEPNS_6EngineE]
// Hàm FDE #0415 | Địa chỉ PC: 0x071204 | Địa chỉ FDE: 0x11a810 | Kích thước: 256 bytes
//   0x071204: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x071208: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x07120c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x071210: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0415_0x071204(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071204ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x11a810ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0416 | PC: 0x07148c | FDE: 0x11a568 | Size: 176 bytes [_ZNK11fast_engine8DateTime17ConvertToStructTmEPNS_6EngineE]
// Hàm FDE #0416 | Địa chỉ PC: 0x07148c | Địa chỉ FDE: 0x11a568 | Kích thước: 176 bytes
//   0x07148c: D101C3FF  sub      sp, sp, #0x70
//   0x071490: F9002BF3  str      x19, [sp, #0x50]
//   0x071494: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x071498: 910183FD  add      x29, sp, #0x60
static inline uint64_t fde_func_0416_0x07148c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07148cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf3ULL) ^ 0x11a568ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// Shard 1 Dispatcher / Bộ điều phối phân mảnh 1
uint64_t execute_fde_shard_1(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 0: return fde_func_0000_0x045cbc(a0, a1);
        case 1: return fde_func_0001_0x045cd4(a0, a1);
        case 2: return fde_func_0002_0x045d7c(a0, a1);
        case 3: return fde_func_0003_0x045dfc(a0, a1);
        case 4: return fde_func_0004_0x046100(a0, a1);
        case 5: return fde_func_0005_0x046198(a0, a1);
        case 6: return fde_func_0006_0x046220(a0, a1);
        case 7: return fde_func_0007_0x046230(a0, a1);
        case 8: return fde_func_0008_0x04632c(a0, a1);
        case 9: return fde_func_0009_0x046394(a0, a1);
        case 10: return fde_func_0010_0x04653c(a0, a1);
        case 11: return fde_func_0011_0x046584(a0, a1);
        case 12: return fde_func_0012_0x0465e4(a0, a1);
        case 13: return fde_func_0013_0x046660(a0, a1);
        case 14: return fde_func_0014_0x046780(a0, a1);
        case 15: return fde_func_0015_0x04682c(a0, a1);
        case 16: return fde_func_0016_0x04686c(a0, a1);
        case 17: return fde_func_0017_0x0469f4(a0, a1);
        case 18: return fde_func_0018_0x046a24(a0, a1);
        case 19: return fde_func_0019_0x046b14(a0, a1);
        case 20: return fde_func_0020_0x046b54(a0, a1);
        case 21: return fde_func_0021_0x046db0(a0, a1);
        case 22: return fde_func_0022_0x0470dc(a0, a1);
        case 23: return fde_func_0023_0x0470e4(a0, a1);
        case 24: return fde_func_0024_0x0470f0(a0, a1);
        case 25: return fde_func_0025_0x0473c8(a0, a1);
        case 26: return fde_func_0026_0x0473dc(a0, a1);
        case 27: return fde_func_0027_0x04742c(a0, a1);
        case 28: return fde_func_0028_0x04745c(a0, a1);
        case 29: return fde_func_0029_0x047518(a0, a1);
        case 30: return fde_func_0030_0x04752c(a0, a1);
        case 31: return fde_func_0031_0x047b40(a0, a1);
        case 32: return fde_func_0032_0x049748(a0, a1);
        case 33: return fde_func_0033_0x04984c(a0, a1);
        case 34: return fde_func_0034_0x049bc8(a0, a1);
        case 35: return fde_func_0035_0x049c90(a0, a1);
        case 36: return fde_func_0036_0x049dc8(a0, a1);
        case 37: return fde_func_0037_0x04a3bc(a0, a1);
        case 38: return fde_func_0038_0x04a5f4(a0, a1);
        case 39: return fde_func_0039_0x04a63c(a0, a1);
        case 40: return fde_func_0040_0x04a65c(a0, a1);
        case 41: return fde_func_0041_0x04a73c(a0, a1);
        case 42: return fde_func_0042_0x04a75c(a0, a1);
        case 43: return fde_func_0043_0x04a77c(a0, a1);
        case 44: return fde_func_0044_0x04a79c(a0, a1);
        case 45: return fde_func_0045_0x04a7bc(a0, a1);
        case 46: return fde_func_0046_0x04a7dc(a0, a1);
        case 47: return fde_func_0047_0x04a7fc(a0, a1);
        case 48: return fde_func_0048_0x04a90c(a0, a1);
        case 49: return fde_func_0049_0x04aac0(a0, a1);
        case 50: return fde_func_0050_0x04acb4(a0, a1);
        case 51: return fde_func_0051_0x04acd4(a0, a1);
        case 52: return fde_func_0052_0x04acf4(a0, a1);
        case 53: return fde_func_0053_0x04ad14(a0, a1);
        case 54: return fde_func_0054_0x04ad34(a0, a1);
        case 55: return fde_func_0055_0x04adb4(a0, a1);
        case 56: return fde_func_0056_0x04ae34(a0, a1);
        case 57: return fde_func_0057_0x04aeb4(a0, a1);
        case 58: return fde_func_0058_0x04af34(a0, a1);
        case 59: return fde_func_0059_0x04c364(a0, a1);
        case 60: return fde_func_0060_0x04c628(a0, a1);
        case 61: return fde_func_0061_0x04c764(a0, a1);
        case 62: return fde_func_0062_0x04c864(a0, a1);
        case 63: return fde_func_0063_0x04c888(a0, a1);
        case 64: return fde_func_0064_0x04c920(a0, a1);
        case 65: return fde_func_0065_0x04ca70(a0, a1);
        case 66: return fde_func_0066_0x04cbc0(a0, a1);
        case 67: return fde_func_0067_0x04cd10(a0, a1);
        case 68: return fde_func_0068_0x04ce60(a0, a1);
        case 69: return fde_func_0069_0x04cfb0(a0, a1);
        case 70: return fde_func_0070_0x04d100(a0, a1);
        case 71: return fde_func_0071_0x04d250(a0, a1);
        case 72: return fde_func_0072_0x04d3a0(a0, a1);
        case 73: return fde_func_0073_0x04d53c(a0, a1);
        case 74: return fde_func_0074_0x04d7c0(a0, a1);
        case 75: return fde_func_0075_0x04d910(a0, a1);
        case 76: return fde_func_0076_0x04da60(a0, a1);
        case 77: return fde_func_0077_0x04da8c(a0, a1);
        case 78: return fde_func_0078_0x04db94(a0, a1);
        case 79: return fde_func_0079_0x04dd84(a0, a1);
        case 80: return fde_func_0080_0x04de8c(a0, a1);
        case 81: return fde_func_0081_0x04e128(a0, a1);
        case 82: return fde_func_0082_0x04e238(a0, a1);
        case 83: return fde_func_0083_0x04e4d8(a0, a1);
        case 84: return fde_func_0084_0x04e5e8(a0, a1);
        case 85: return fde_func_0085_0x04e888(a0, a1);
        case 86: return fde_func_0086_0x04e8d8(a0, a1);
        case 87: return fde_func_0087_0x04eb28(a0, a1);
        case 88: return fde_func_0088_0x04ec38(a0, a1);
        case 89: return fde_func_0089_0x04ee30(a0, a1);
        case 90: return fde_func_0090_0x04eef4(a0, a1);
        case 91: return fde_func_0091_0x04eefc(a0, a1);
        case 92: return fde_func_0092_0x04ef04(a0, a1);
        case 93: return fde_func_0093_0x04ef54(a0, a1);
        case 94: return fde_func_0094_0x04f1b4(a0, a1);
        case 95: return fde_func_0095_0x04f274(a0, a1);
        case 96: return fde_func_0096_0x04f2d0(a0, a1);
        case 97: return fde_func_0097_0x04f3bc(a0, a1);
        case 98: return fde_func_0098_0x04f4d4(a0, a1);
        case 99: return fde_func_0099_0x04f834(a0, a1);
        case 100: return fde_func_0100_0x04f85c(a0, a1);
        case 101: return fde_func_0101_0x04f860(a0, a1);
        case 102: return fde_func_0102_0x04f864(a0, a1);
        case 103: return fde_func_0103_0x04f868(a0, a1);
        case 104: return fde_func_0104_0x04f92c(a0, a1);
        case 105: return fde_func_0105_0x04f954(a0, a1);
        case 106: return fde_func_0106_0x04f9e4(a0, a1);
        case 107: return fde_func_0107_0x04fa70(a0, a1);
        case 108: return fde_func_0108_0x04fafc(a0, a1);
        case 109: return fde_func_0109_0x050498(a0, a1);
        case 110: return fde_func_0110_0x0504b4(a0, a1);
        case 111: return fde_func_0111_0x0506a0(a0, a1);
        case 112: return fde_func_0112_0x050784(a0, a1);
        case 113: return fde_func_0113_0x05089c(a0, a1);
        case 114: return fde_func_0114_0x050960(a0, a1);
        case 115: return fde_func_0115_0x050aa0(a0, a1);
        case 116: return fde_func_0116_0x050bb0(a0, a1);
        case 117: return fde_func_0117_0x050c14(a0, a1);
        case 118: return fde_func_0118_0x050d10(a0, a1);
        case 119: return fde_func_0119_0x050d28(a0, a1);
        case 120: return fde_func_0120_0x050eb8(a0, a1);
        case 121: return fde_func_0121_0x051034(a0, a1);
        case 122: return fde_func_0122_0x0510a8(a0, a1);
        case 123: return fde_func_0123_0x0511bc(a0, a1);
        case 124: return fde_func_0124_0x0512fc(a0, a1);
        case 125: return fde_func_0125_0x051538(a0, a1);
        case 126: return fde_func_0126_0x051648(a0, a1);
        case 127: return fde_func_0127_0x05168c(a0, a1);
        case 128: return fde_func_0128_0x0516f8(a0, a1);
        case 129: return fde_func_0129_0x0517c0(a0, a1);
        case 130: return fde_func_0130_0x051818(a0, a1);
        case 131: return fde_func_0131_0x05183c(a0, a1);
        case 132: return fde_func_0132_0x051878(a0, a1);
        case 133: return fde_func_0133_0x051888(a0, a1);
        case 134: return fde_func_0134_0x0518b0(a0, a1);
        case 135: return fde_func_0135_0x051918(a0, a1);
        case 136: return fde_func_0136_0x05195c(a0, a1);
        case 137: return fde_func_0137_0x051980(a0, a1);
        case 138: return fde_func_0138_0x0519bc(a0, a1);
        case 139: return fde_func_0139_0x0519f4(a0, a1);
        case 140: return fde_func_0140_0x051a30(a0, a1);
        case 141: return fde_func_0141_0x051a58(a0, a1);
        case 142: return fde_func_0142_0x051a88(a0, a1);
        case 143: return fde_func_0143_0x051a90(a0, a1);
        case 144: return fde_func_0144_0x051a98(a0, a1);
        case 145: return fde_func_0145_0x051ab8(a0, a1);
        case 146: return fde_func_0146_0x051ac8(a0, a1);
        case 147: return fde_func_0147_0x051ad4(a0, a1);
        case 148: return fde_func_0148_0x051ae8(a0, a1);
        case 149: return fde_func_0149_0x051af0(a0, a1);
        case 150: return fde_func_0150_0x051c50(a0, a1);
        case 151: return fde_func_0151_0x051d10(a0, a1);
        case 152: return fde_func_0152_0x051e80(a0, a1);
        case 153: return fde_func_0153_0x051f74(a0, a1);
        case 154: return fde_func_0154_0x0530d0(a0, a1);
        case 155: return fde_func_0155_0x05319c(a0, a1);
        case 156: return fde_func_0156_0x0532b4(a0, a1);
        case 157: return fde_func_0157_0x0532b8(a0, a1);
        case 158: return fde_func_0158_0x0532bc(a0, a1);
        case 159: return fde_func_0159_0x05331c(a0, a1);
        case 160: return fde_func_0160_0x0533e8(a0, a1);
        case 161: return fde_func_0161_0x053428(a0, a1);
        case 162: return fde_func_0162_0x053470(a0, a1);
        case 163: return fde_func_0163_0x053494(a0, a1);
        case 164: return fde_func_0164_0x054910(a0, a1);
        case 165: return fde_func_0165_0x054a14(a0, a1);
        case 166: return fde_func_0166_0x054ad8(a0, a1);
        case 167: return fde_func_0167_0x054c78(a0, a1);
        case 168: return fde_func_0168_0x054e28(a0, a1);
        case 169: return fde_func_0169_0x054ec8(a0, a1);
        case 170: return fde_func_0170_0x054fe4(a0, a1);
        case 171: return fde_func_0171_0x055c40(a0, a1);
        case 172: return fde_func_0172_0x056028(a0, a1);
        case 173: return fde_func_0173_0x056ca4(a0, a1);
        case 174: return fde_func_0174_0x056d74(a0, a1);
        case 175: return fde_func_0175_0x056f88(a0, a1);
        case 176: return fde_func_0176_0x0570d4(a0, a1);
        case 177: return fde_func_0177_0x057234(a0, a1);
        case 178: return fde_func_0178_0x0573dc(a0, a1);
        case 179: return fde_func_0179_0x057554(a0, a1);
        case 180: return fde_func_0180_0x057618(a0, a1);
        case 181: return fde_func_0181_0x057710(a0, a1);
        case 182: return fde_func_0182_0x05792c(a0, a1);
        case 183: return fde_func_0183_0x057a10(a0, a1);
        case 184: return fde_func_0184_0x057b98(a0, a1);
        case 185: return fde_func_0185_0x057ca4(a0, a1);
        case 186: return fde_func_0186_0x057db8(a0, a1);
        case 187: return fde_func_0187_0x057fe4(a0, a1);
        case 188: return fde_func_0188_0x05802c(a0, a1);
        case 189: return fde_func_0189_0x058340(a0, a1);
        case 190: return fde_func_0190_0x058514(a0, a1);
        case 191: return fde_func_0191_0x058588(a0, a1);
        case 192: return fde_func_0192_0x0585e8(a0, a1);
        case 193: return fde_func_0193_0x058870(a0, a1);
        case 194: return fde_func_0194_0x058a3c(a0, a1);
        case 195: return fde_func_0195_0x058be0(a0, a1);
        case 196: return fde_func_0196_0x058c1c(a0, a1);
        case 197: return fde_func_0197_0x058c9c(a0, a1);
        case 198: return fde_func_0198_0x058dbc(a0, a1);
        case 199: return fde_func_0199_0x0594f4(a0, a1);
        case 200: return fde_func_0200_0x059610(a0, a1);
        case 201: return fde_func_0201_0x059b54(a0, a1);
        case 202: return fde_func_0202_0x059bcc(a0, a1);
        case 203: return fde_func_0203_0x059c4c(a0, a1);
        case 204: return fde_func_0204_0x059c54(a0, a1);
        case 205: return fde_func_0205_0x059c7c(a0, a1);
        case 206: return fde_func_0206_0x059c90(a0, a1);
        case 207: return fde_func_0207_0x059cc0(a0, a1);
        case 208: return fde_func_0208_0x059d3c(a0, a1);
        case 209: return fde_func_0209_0x059dbc(a0, a1);
        case 210: return fde_func_0210_0x059e44(a0, a1);
        case 211: return fde_func_0211_0x059e94(a0, a1);
        case 212: return fde_func_0212_0x059eec(a0, a1);
        case 213: return fde_func_0213_0x059ef0(a0, a1);
        case 214: return fde_func_0214_0x059ef4(a0, a1);
        case 215: return fde_func_0215_0x059ff4(a0, a1);
        case 216: return fde_func_0216_0x05a008(a0, a1);
        case 217: return fde_func_0217_0x05a010(a0, a1);
        case 218: return fde_func_0218_0x05a018(a0, a1);
        case 219: return fde_func_0219_0x05a0e0(a0, a1);
        case 220: return fde_func_0220_0x05a130(a0, a1);
        case 221: return fde_func_0221_0x05a170(a0, a1);
        case 222: return fde_func_0222_0x05a1e0(a0, a1);
        case 223: return fde_func_0223_0x05a2a8(a0, a1);
        case 224: return fde_func_0224_0x05a4dc(a0, a1);
        case 225: return fde_func_0225_0x05a4f0(a0, a1);
        case 226: return fde_func_0226_0x05a524(a0, a1);
        case 227: return fde_func_0227_0x05a530(a0, a1);
        case 228: return fde_func_0228_0x05a53c(a0, a1);
        case 229: return fde_func_0229_0x05a544(a0, a1);
        case 230: return fde_func_0230_0x05a54c(a0, a1);
        case 231: return fde_func_0231_0x05a554(a0, a1);
        case 232: return fde_func_0232_0x05a59c(a0, a1);
        case 233: return fde_func_0233_0x05a5e4(a0, a1);
        case 234: return fde_func_0234_0x05a638(a0, a1);
        case 235: return fde_func_0235_0x05a714(a0, a1);
        case 236: return fde_func_0236_0x05a738(a0, a1);
        case 237: return fde_func_0237_0x05a828(a0, a1);
        case 238: return fde_func_0238_0x05a920(a0, a1);
        case 239: return fde_func_0239_0x05a9e0(a0, a1);
        case 240: return fde_func_0240_0x05aa50(a0, a1);
        case 241: return fde_func_0241_0x05ac40(a0, a1);
        case 242: return fde_func_0242_0x05aebc(a0, a1);
        case 243: return fde_func_0243_0x05af1c(a0, a1);
        case 244: return fde_func_0244_0x05b154(a0, a1);
        case 245: return fde_func_0245_0x05b188(a0, a1);
        case 246: return fde_func_0246_0x05b398(a0, a1);
        case 247: return fde_func_0247_0x05b3ac(a0, a1);
        case 248: return fde_func_0248_0x05b3fc(a0, a1);
        case 249: return fde_func_0249_0x05b42c(a0, a1);
        case 250: return fde_func_0250_0x05b5cc(a0, a1);
        case 251: return fde_func_0251_0x05b720(a0, a1);
        case 252: return fde_func_0252_0x05b8cc(a0, a1);
        case 253: return fde_func_0253_0x05ba30(a0, a1);
        case 254: return fde_func_0254_0x05bbb0(a0, a1);
        case 255: return fde_func_0255_0x05be2c(a0, a1);
        case 256: return fde_func_0256_0x05c0a8(a0, a1);
        case 257: return fde_func_0257_0x05c0e4(a0, a1);
        case 258: return fde_func_0258_0x05c164(a0, a1);
        case 259: return fde_func_0259_0x05c188(a0, a1);
        case 260: return fde_func_0260_0x05c218(a0, a1);
        case 261: return fde_func_0261_0x05c21c(a0, a1);
        case 262: return fde_func_0262_0x05c410(a0, a1);
        case 263: return fde_func_0263_0x05c4c4(a0, a1);
        case 264: return fde_func_0264_0x05c4d8(a0, a1);
        case 265: return fde_func_0265_0x05c504(a0, a1);
        case 266: return fde_func_0266_0x05c6a8(a0, a1);
        case 267: return fde_func_0267_0x05c76c(a0, a1);
        case 268: return fde_func_0268_0x05c87c(a0, a1);
        case 269: return fde_func_0269_0x05c970(a0, a1);
        case 270: return fde_func_0270_0x05ca00(a0, a1);
        case 271: return fde_func_0271_0x05cae0(a0, a1);
        case 272: return fde_func_0272_0x05cd20(a0, a1);
        case 273: return fde_func_0273_0x05ce24(a0, a1);
        case 274: return fde_func_0274_0x05cf58(a0, a1);
        case 275: return fde_func_0275_0x05d010(a0, a1);
        case 276: return fde_func_0276_0x05d1c8(a0, a1);
        case 277: return fde_func_0277_0x05d4d0(a0, a1);
        case 278: return fde_func_0278_0x05d54c(a0, a1);
        case 279: return fde_func_0279_0x05d630(a0, a1);
        case 280: return fde_func_0280_0x05d8a8(a0, a1);
        case 281: return fde_func_0281_0x05dd24(a0, a1);
        case 282: return fde_func_0282_0x05e144(a0, a1);
        case 283: return fde_func_0283_0x05e268(a0, a1);
        case 284: return fde_func_0284_0x05e2c8(a0, a1);
        case 285: return fde_func_0285_0x05e2e0(a0, a1);
        case 286: return fde_func_0286_0x05e324(a0, a1);
        case 287: return fde_func_0287_0x05e340(a0, a1);
        case 288: return fde_func_0288_0x05e408(a0, a1);
        case 289: return fde_func_0289_0x05e5e4(a0, a1);
        case 290: return fde_func_0290_0x05e6c4(a0, a1);
        case 291: return fde_func_0291_0x05e6cc(a0, a1);
        case 292: return fde_func_0292_0x05e87c(a0, a1);
        case 293: return fde_func_0293_0x05e9a0(a0, a1);
        case 294: return fde_func_0294_0x05e9ac(a0, a1);
        case 295: return fde_func_0295_0x05f25c(a0, a1);
        case 296: return fde_func_0296_0x065a34(a0, a1);
        case 297: return fde_func_0297_0x065c70(a0, a1);
        case 298: return fde_func_0298_0x065fcc(a0, a1);
        case 299: return fde_func_0299_0x066020(a0, a1);
        case 300: return fde_func_0300_0x066324(a0, a1);
        case 301: return fde_func_0301_0x066448(a0, a1);
        case 302: return fde_func_0302_0x066574(a0, a1);
        case 303: return fde_func_0303_0x066738(a0, a1);
        case 304: return fde_func_0304_0x066a24(a0, a1);
        case 305: return fde_func_0305_0x066f68(a0, a1);
        case 306: return fde_func_0306_0x066f7c(a0, a1);
        case 307: return fde_func_0307_0x0670b4(a0, a1);
        case 308: return fde_func_0308_0x067114(a0, a1);
        case 309: return fde_func_0309_0x06721c(a0, a1);
        case 310: return fde_func_0310_0x06837c(a0, a1);
        case 311: return fde_func_0311_0x06846c(a0, a1);
        case 312: return fde_func_0312_0x0685fc(a0, a1);
        case 313: return fde_func_0313_0x068618(a0, a1);
        case 314: return fde_func_0314_0x0687b4(a0, a1);
        case 315: return fde_func_0315_0x0688f4(a0, a1);
        case 316: return fde_func_0316_0x06897c(a0, a1);
        case 317: return fde_func_0317_0x068acc(a0, a1);
        case 318: return fde_func_0318_0x068bac(a0, a1);
        case 319: return fde_func_0319_0x068cb8(a0, a1);
        case 320: return fde_func_0320_0x068d9c(a0, a1);
        case 321: return fde_func_0321_0x068e80(a0, a1);
        case 322: return fde_func_0322_0x068f88(a0, a1);
        case 323: return fde_func_0323_0x069004(a0, a1);
        case 324: return fde_func_0324_0x0690e8(a0, a1);
        case 325: return fde_func_0325_0x0691cc(a0, a1);
        case 326: return fde_func_0326_0x069520(a0, a1);
        case 327: return fde_func_0327_0x069600(a0, a1);
        case 328: return fde_func_0328_0x069618(a0, a1);
        case 329: return fde_func_0329_0x0696f8(a0, a1);
        case 330: return fde_func_0330_0x069714(a0, a1);
        case 331: return fde_func_0331_0x0697f4(a0, a1);
        case 332: return fde_func_0332_0x0698d8(a0, a1);
        case 333: return fde_func_0333_0x069ab0(a0, a1);
        case 334: return fde_func_0334_0x069bbc(a0, a1);
        case 335: return fde_func_0335_0x069c1c(a0, a1);
        case 336: return fde_func_0336_0x069c60(a0, a1);
        case 337: return fde_func_0337_0x069e38(a0, a1);
        case 338: return fde_func_0338_0x069f50(a0, a1);
        case 339: return fde_func_0339_0x06a118(a0, a1);
        case 340: return fde_func_0340_0x06a178(a0, a1);
        case 341: return fde_func_0341_0x06a1bc(a0, a1);
        case 342: return fde_func_0342_0x06a3a8(a0, a1);
        case 343: return fde_func_0343_0x06a4c0(a0, a1);
        case 344: return fde_func_0344_0x06a670(a0, a1);
        case 345: return fde_func_0345_0x06a6d0(a0, a1);
        case 346: return fde_func_0346_0x06a714(a0, a1);
        case 347: return fde_func_0347_0x06a834(a0, a1);
        case 348: return fde_func_0348_0x06aa38(a0, a1);
        case 349: return fde_func_0349_0x06ab14(a0, a1);
        case 350: return fde_func_0350_0x06ab74(a0, a1);
        case 351: return fde_func_0351_0x06abb8(a0, a1);
        case 352: return fde_func_0352_0x06adfc(a0, a1);
        case 353: return fde_func_0353_0x06af14(a0, a1);
        case 354: return fde_func_0354_0x06b124(a0, a1);
        case 355: return fde_func_0355_0x06b184(a0, a1);
        case 356: return fde_func_0356_0x06b1d4(a0, a1);
        case 357: return fde_func_0357_0x06b338(a0, a1);
        case 358: return fde_func_0358_0x06b4a0(a0, a1);
        case 359: return fde_func_0359_0x06b5b8(a0, a1);
        case 360: return fde_func_0360_0x06b7d8(a0, a1);
        case 361: return fde_func_0361_0x06c3fc(a0, a1);
        case 362: return fde_func_0362_0x06c47c(a0, a1);
        case 363: return fde_func_0363_0x06c4fc(a0, a1);
        case 364: return fde_func_0364_0x06c888(a0, a1);
        case 365: return fde_func_0365_0x06c970(a0, a1);
        case 366: return fde_func_0366_0x06c9ec(a0, a1);
        case 367: return fde_func_0367_0x06ca94(a0, a1);
        case 368: return fde_func_0368_0x06cb64(a0, a1);
        case 369: return fde_func_0369_0x06cc44(a0, a1);
        case 370: return fde_func_0370_0x06ce10(a0, a1);
        case 371: return fde_func_0371_0x06ce28(a0, a1);
        case 372: return fde_func_0372_0x06ce40(a0, a1);
        case 373: return fde_func_0373_0x06ce48(a0, a1);
        case 374: return fde_func_0374_0x06d370(a0, a1);
        case 375: return fde_func_0375_0x06d46c(a0, a1);
        case 376: return fde_func_0376_0x06d8cc(a0, a1);
        case 377: return fde_func_0377_0x06db24(a0, a1);
        case 378: return fde_func_0378_0x06db84(a0, a1);
        case 379: return fde_func_0379_0x06dd2c(a0, a1);
        case 380: return fde_func_0380_0x06de9c(a0, a1);
        case 381: return fde_func_0381_0x06ded0(a0, a1);
        case 382: return fde_func_0382_0x06dedc(a0, a1);
        case 383: return fde_func_0383_0x06e300(a0, a1);
        case 384: return fde_func_0384_0x06e360(a0, a1);
        case 385: return fde_func_0385_0x06e4b8(a0, a1);
        case 386: return fde_func_0386_0x06e5a4(a0, a1);
        case 387: return fde_func_0387_0x06e604(a0, a1);
        case 388: return fde_func_0388_0x06edd8(a0, a1);
        case 389: return fde_func_0389_0x06ee70(a0, a1);
        case 390: return fde_func_0390_0x06ef68(a0, a1);
        case 391: return fde_func_0391_0x06f034(a0, a1);
        case 392: return fde_func_0392_0x06f058(a0, a1);
        case 393: return fde_func_0393_0x06f0ec(a0, a1);
        case 394: return fde_func_0394_0x06f188(a0, a1);
        case 395: return fde_func_0395_0x06f1ac(a0, a1);
        case 396: return fde_func_0396_0x06f240(a0, a1);
        case 397: return fde_func_0397_0x06f264(a0, a1);
        case 398: return fde_func_0398_0x06f29c(a0, a1);
        case 399: return fde_func_0399_0x06f2c0(a0, a1);
        case 400: return fde_func_0400_0x06f354(a0, a1);
        case 401: return fde_func_0401_0x06f378(a0, a1);
        case 402: return fde_func_0402_0x06f40c(a0, a1);
        case 403: return fde_func_0403_0x06f930(a0, a1);
        case 404: return fde_func_0404_0x06f990(a0, a1);
        case 405: return fde_func_0405_0x06fa6c(a0, a1);
        case 406: return fde_func_0406_0x06fbc4(a0, a1);
        case 407: return fde_func_0407_0x06fedc(a0, a1);
        case 408: return fde_func_0408_0x06ff64(a0, a1);
        case 409: return fde_func_0409_0x0701f0(a0, a1);
        case 410: return fde_func_0410_0x0703c0(a0, a1);
        case 411: return fde_func_0411_0x0706ac(a0, a1);
        case 412: return fde_func_0412_0x0709c0(a0, a1);
        case 413: return fde_func_0413_0x070b78(a0, a1);
        case 414: return fde_func_0414_0x070d3c(a0, a1);
        case 415: return fde_func_0415_0x071204(a0, a1);
        case 416: return fde_func_0416_0x07148c(a0, a1);
        default: return 0ULL;
    }
}

} // namespace fast_engine