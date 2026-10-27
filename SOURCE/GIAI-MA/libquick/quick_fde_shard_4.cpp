// ============================================================================
// Clean-Room C++17 AArch64 FDE Shard 4/5 for libquick.so
// Phân mảnh Khung Tháo Gỡ (FDE) AArch64 C++17 sạch 4/5 cho libquick.so
// Covers FDE indices [1137 .. 1515] out of 1,893 total FDEs
// Bao phủ chỉ số FDE [1137 .. 1515] trên tổng số 1.893 FDE
// ============================================================================
#include "quick_core.h"

// FDE #1137 | PC: 0x1080f0 | FDE: 0x044660 | Size: 256 bytes
// Khung tháo gỡ #1137 | Địa chỉ PC: 0x1080f0 | Địa chỉ FDE: 0x044660 | Kích thước: 256 bytes
//   0x1080f0: D10203FF  sub      sp, sp, #0x80
//   0x1080f4: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x1080f8: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x1080fc: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1137_0x1080f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1080f0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x044660ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1138 | PC: 0x108aa0 | FDE: 0x044690 | Size: 60 bytes
// Khung tháo gỡ #1138 | Địa chỉ PC: 0x108aa0 | Địa chỉ FDE: 0x044690 | Kích thước: 60 bytes
//   0x108aa0: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x108aa4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x108aa8: AA0103F4  mov      x20, x1
//   0x108aac: 2A0203F3  mov      w19, w2
static inline uint64_t fde_func_1138_0x108aa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x108aa0ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x044690ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1139 | PC: 0x108adc | FDE: 0x0446b0 | Size: 256 bytes [LEPUS_AtomToCString]
// Khung tháo gỡ #1139 | Địa chỉ PC: 0x108adc | Địa chỉ FDE: 0x0446b0 | Kích thước: 256 bytes
//   0x108adc: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x108ae0: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x108ae4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x108ae8: 39458008  ldrb     w8, [x0, #0x160]
static inline uint64_t fde_func_1139_0x108adc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x108adcULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0446b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1140 | PC: 0x108be0 | FDE: 0x0446d0 | Size: 256 bytes
// Khung tháo gỡ #1140 | Địa chỉ PC: 0x108be0 | Địa chỉ FDE: 0x0446d0 | Kích thước: 256 bytes
//   0x108be0: D10143FF  sub      sp, sp, #0x50
//   0x108be4: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x108be8: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x108bec: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1140_0x108be0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x108be0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x0446d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1141 | PC: 0x108e54 | FDE: 0x0446f8 | Size: 256 bytes [_Z18js_operator_typeofP12LEPUSContext10LEPUSValue]
// Khung tháo gỡ #1141 | Địa chỉ PC: 0x108e54 | Địa chỉ FDE: 0x0446f8 | Kích thước: 256 bytes
//   0x108e54: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x108e58: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x108e5c: AA0003F3  mov      x19, x0
//   0x108e60: D371FC28  lsr      x8, x1, #0x31
static inline uint64_t fde_func_1141_0x108e54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x108e54ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0446f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1142 | PC: 0x109080 | FDE: 0x044718 | Size: 256 bytes [LEPUS_DeleteProperty]
// Khung tháo gỡ #1142 | Địa chỉ PC: 0x109080 | Địa chỉ FDE: 0x044718 | Kích thước: 256 bytes
//   0x109080: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x109084: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x109088: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x10908c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1142_0x109080(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109080ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x044718ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1143 | PC: 0x109218 | FDE: 0x044740 | Size: 256 bytes
// Khung tháo gỡ #1143 | Địa chỉ PC: 0x109218 | Địa chỉ FDE: 0x044740 | Kích thước: 256 bytes
//   0x109218: D10343FF  sub      sp, sp, #0xd0
//   0x10921c: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x109220: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x109224: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_1143_0x109218(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109218ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9076ffcULL) ^ 0x044740ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1144 | PC: 0x109c0c | FDE: 0x044770 | Size: 256 bytes
// Khung tháo gỡ #1144 | Địa chỉ PC: 0x109c0c | Địa chỉ FDE: 0x044770 | Kích thước: 256 bytes
//   0x109c0c: D101C3FF  sub      sp, sp, #0x70
//   0x109c10: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x109c14: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x109c18: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1144_0x109c0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109c0cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x044770ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1145 | PC: 0x109d64 | FDE: 0x0447a0 | Size: 12 bytes
// Khung tháo gỡ #1145 | Địa chỉ PC: 0x109d64 | Địa chỉ FDE: 0x0447a0 | Kích thước: 12 bytes
//   0x109d64: F9400804  ldr      x4, [x0, #0x10]
//   0x109d68: 910D2000  add      x0, x0, #0x348
//   0x109d6c: D61F0080  br       x4
static inline uint64_t fde_func_1145_0x109d64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109d64ULL ^ (static_cast<uint64_t>(0xf9400804ULL) << 13);
    acc = (acc + a1 + 0x910d2000ULL) ^ 0x0447a0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1146 | PC: 0x109d70 | FDE: 0x0447b8 | Size: 256 bytes [LEPUS_NewStringLen]
// Khung tháo gỡ #1146 | Địa chỉ PC: 0x109d70 | Địa chỉ FDE: 0x0447b8 | Kích thước: 256 bytes
//   0x109d70: D10243FF  sub      sp, sp, #0x90
//   0x109d74: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x109d78: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x109d7c: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1146_0x109d70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109d70ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x0447b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1147 | PC: 0x10a264 | FDE: 0x0447e8 | Size: 256 bytes
// Khung tháo gỡ #1147 | Địa chỉ PC: 0x10a264 | Địa chỉ FDE: 0x0447e8 | Kích thước: 256 bytes
//   0x10a264: D10303FF  sub      sp, sp, #0xc0
//   0x10a268: F90033FC  str      x28, [sp, #0x60]
//   0x10a26c: A9076BFB  stp      x27, x26, [sp, #0x70]
//   0x10a270: A90863F9  stp      x25, x24, [sp, #0x80]
static inline uint64_t fde_func_1147_0x10a264(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10a264ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf90033fcULL) ^ 0x0447e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1148 | PC: 0x10a668 | FDE: 0x044818 | Size: 256 bytes [get_func_name]
// Khung tháo gỡ #1148 | Địa chỉ PC: 0x10a668 | Địa chỉ FDE: 0x044818 | Kích thước: 256 bytes
//   0x10a668: D10103FF  sub      sp, sp, #0x40
//   0x10a66c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x10a670: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x10a674: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_1148_0x10a668(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10a668ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x044818ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1149 | PC: 0x10a7f8 | FDE: 0x044838 | Size: 256 bytes [find_line_num]
// Khung tháo gỡ #1149 | Địa chỉ PC: 0x10a7f8 | Địa chỉ FDE: 0x044838 | Kích thước: 256 bytes
//   0x10a7f8: 39401C28  ldrb     w8, [x1, #7]
//   0x10a7fc: 36100A88  tbz      w8, #2, #0x10a94c
//   0x10a800: F9403C2D  ldr      x13, [x1, #0x78]
//   0x10a804: B4000A4D  cbz      x13, #0x10a94c
static inline uint64_t fde_func_1149_0x10a7f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10a7f8ULL ^ (static_cast<uint64_t>(0x39401c28ULL) << 13);
    acc = (acc + a1 + 0x36100a88ULL) ^ 0x044838ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1150 | PC: 0x10a960 | FDE: 0x044850 | Size: 256 bytes
// Khung tháo gỡ #1150 | Địa chỉ PC: 0x10a960 | Địa chỉ FDE: 0x044850 | Kích thước: 256 bytes
//   0x10a960: A9BB6BFB  stp      x27, x26, [sp, #-0x50]!
//   0x10a964: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x10a968: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x10a96c: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1150_0x10a960(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10a960ULL ^ (static_cast<uint64_t>(0xa9bb6bfbULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x044850ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1151 | PC: 0x10ad8c | FDE: 0x044878 | Size: 256 bytes [_Z18js_new_string8_lenP12LEPUSContextPKci]
// Khung tháo gỡ #1151 | Địa chỉ PC: 0x10ad8c | Địa chỉ FDE: 0x044878 | Kích thước: 256 bytes
//   0x10ad8c: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x10ad90: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x10ad94: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x10ad98: 7100005F  cmp      w2, #0
static inline uint64_t fde_func_1151_0x10ad8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10ad8cULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x044878ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1152 | PC: 0x10aea4 | FDE: 0x044898 | Size: 256 bytes
// Khung tháo gỡ #1152 | Địa chỉ PC: 0x10aea4 | Địa chỉ FDE: 0x044898 | Kích thước: 256 bytes
//   0x10aea4: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x10aea8: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x10aeac: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x10aeb0: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1152_0x10aea4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10aea4ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x044898ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1153 | PC: 0x10b054 | FDE: 0x0448c0 | Size: 256 bytes
// Khung tháo gỡ #1153 | Địa chỉ PC: 0x10b054 | Địa chỉ FDE: 0x0448c0 | Kích thước: 256 bytes
//   0x10b054: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x10b058: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x10b05c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x10b060: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1153_0x10b054(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10b054ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0448c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1154 | PC: 0x10b180 | FDE: 0x0448e8 | Size: 256 bytes
// Khung tháo gỡ #1154 | Địa chỉ PC: 0x10b180 | Địa chỉ FDE: 0x0448e8 | Kích thước: 256 bytes
//   0x10b180: F81A0FFC  str      x28, [sp, #-0x60]!
//   0x10b184: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x10b188: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x10b18c: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_1154_0x10b180(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10b180ULL ^ (static_cast<uint64_t>(0xf81a0ffcULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x0448e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1155 | PC: 0x10b6d4 | FDE: 0x044918 | Size: 256 bytes
// Khung tháo gỡ #1155 | Địa chỉ PC: 0x10b6d4 | Địa chỉ FDE: 0x044918 | Kích thước: 256 bytes
//   0x10b6d4: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x10b6d8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x10b6dc: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x10b6e0: 2941A428  ldp      w8, w9, [x1, #0xc]
static inline uint64_t fde_func_1155_0x10b6d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10b6d4ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x044918ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1156 | PC: 0x10b814 | FDE: 0x044938 | Size: 256 bytes
// Khung tháo gỡ #1156 | Địa chỉ PC: 0x10b814 | Địa chỉ FDE: 0x044938 | Kích thước: 256 bytes
//   0x10b814: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x10b818: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x10b81c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x10b820: AA0103F5  mov      x21, x1
static inline uint64_t fde_func_1156_0x10b814(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10b814ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x044938ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1157 | PC: 0x10b984 | FDE: 0x044958 | Size: 256 bytes
// Khung tháo gỡ #1157 | Địa chỉ PC: 0x10b984 | Địa chỉ FDE: 0x044958 | Kích thước: 256 bytes
//   0x10b984: A9BB6BFB  stp      x27, x26, [sp, #-0x50]!
//   0x10b988: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x10b98c: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x10b990: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1157_0x10b984(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10b984ULL ^ (static_cast<uint64_t>(0xa9bb6bfbULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x044958ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1158 | PC: 0x10bbf8 | FDE: 0x044980 | Size: 256 bytes [LEPUS_NewAtomLen]
// Khung tháo gỡ #1158 | Địa chỉ PC: 0x10bbf8 | Địa chỉ FDE: 0x044980 | Kích thước: 256 bytes
//   0x10bbf8: D101C3FF  sub      sp, sp, #0x70
//   0x10bbfc: F9000BFC  str      x28, [sp, #0x10]
//   0x10bc00: A9026BFB  stp      x27, x26, [sp, #0x20]
//   0x10bc04: A90363F9  stp      x25, x24, [sp, #0x30]
static inline uint64_t fde_func_1158_0x10bbf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10bbf8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfcULL) ^ 0x044980ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1159 | PC: 0x10bde8 | FDE: 0x0449b0 | Size: 256 bytes
// Khung tháo gỡ #1159 | Địa chỉ PC: 0x10bde8 | Địa chỉ FDE: 0x0449b0 | Kích thước: 256 bytes
//   0x10bde8: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x10bdec: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x10bdf0: F8404028  ldur     x8, [x1, #4]
//   0x10bdf4: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1159_0x10bde8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10bde8ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0449b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1160 | PC: 0x10bfc8 | FDE: 0x0449d0 | Size: 256 bytes
// Khung tháo gỡ #1160 | Địa chỉ PC: 0x10bfc8 | Địa chỉ FDE: 0x0449d0 | Kích thước: 256 bytes
//   0x10bfc8: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x10bfcc: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x10bfd0: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x10bfd4: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1160_0x10bfc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10bfc8ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0449d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1161 | PC: 0x10c1ec | FDE: 0x0449f8 | Size: 256 bytes
// Khung tháo gỡ #1161 | Địa chỉ PC: 0x10c1ec | Địa chỉ FDE: 0x0449f8 | Kích thước: 256 bytes
//   0x10c1ec: F81B0FFA  str      x26, [sp, #-0x50]!
//   0x10c1f0: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x10c1f4: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x10c1f8: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1161_0x10c1ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c1ecULL ^ (static_cast<uint64_t>(0xf81b0ffaULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x0449f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1162 | PC: 0x10ca70 | FDE: 0x044a20 | Size: 256 bytes [JS_GetSeparableStringContentNotDup]
// Khung tháo gỡ #1162 | Địa chỉ PC: 0x10ca70 | Địa chỉ FDE: 0x044a20 | Kích thước: 256 bytes
//   0x10ca70: D10243FF  sub      sp, sp, #0x90
//   0x10ca74: F9001BFC  str      x28, [sp, #0x30]
//   0x10ca78: A9046BFB  stp      x27, x26, [sp, #0x40]
//   0x10ca7c: A90563F9  stp      x25, x24, [sp, #0x50]
static inline uint64_t fde_func_1162_0x10ca70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10ca70ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9001bfcULL) ^ 0x044a20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1163 | PC: 0x10cf50 | FDE: 0x044a50 | Size: 256 bytes
// Khung tháo gỡ #1163 | Địa chỉ PC: 0x10cf50 | Địa chỉ FDE: 0x044a50 | Kích thước: 256 bytes
//   0x10cf50: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x10cf54: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x10cf58: B9400409  ldr      w9, [x0, #4]
//   0x10cf5c: B9400428  ldr      w8, [x1, #4]
static inline uint64_t fde_func_1163_0x10cf50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10cf50ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x044a50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1164 | PC: 0x10d058 | FDE: 0x044a70 | Size: 256 bytes
// Khung tháo gỡ #1164 | Địa chỉ PC: 0x10d058 | Địa chỉ FDE: 0x044a70 | Kích thước: 256 bytes
//   0x10d058: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x10d05c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x10d060: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x10d064: B9401C08  ldr      w8, [x0, #0x1c]
static inline uint64_t fde_func_1164_0x10d058(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d058ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x044a70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1165 | PC: 0x10d1d0 | FDE: 0x044a90 | Size: 256 bytes
// Khung tháo gỡ #1165 | Địa chỉ PC: 0x10d1d0 | Địa chỉ FDE: 0x044a90 | Kích thước: 256 bytes
//   0x10d1d0: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x10d1d4: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x10d1d8: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x10d1dc: 6B020076  subs     w22, w3, w2
static inline uint64_t fde_func_1165_0x10d1d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d1d0ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x044a90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1166 | PC: 0x10d408 | FDE: 0x044ab0 | Size: 256 bytes [_Z17JS_StringToBigIntP12LEPUSContext10LEPUSValue]
// Khung tháo gỡ #1166 | Địa chỉ PC: 0x10d408 | Địa chỉ FDE: 0x044ab0 | Kích thước: 256 bytes
//   0x10d408: D10203FF  sub      sp, sp, #0x80
//   0x10d40c: A9036BFB  stp      x27, x26, [sp, #0x30]
//   0x10d410: A90463F9  stp      x25, x24, [sp, #0x40]
//   0x10d414: A9055BF7  stp      x23, x22, [sp, #0x50]
static inline uint64_t fde_func_1166_0x10d408(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d408ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9036bfbULL) ^ 0x044ab0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1167 | PC: 0x10da40 | FDE: 0x044ae0 | Size: 256 bytes
// Khung tháo gỡ #1167 | Địa chỉ PC: 0x10da40 | Địa chỉ FDE: 0x044ae0 | Kích thước: 256 bytes
//   0x10da40: D10243FF  sub      sp, sp, #0x90
//   0x10da44: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x10da48: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x10da4c: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1167_0x10da40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10da40ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x044ae0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1168 | PC: 0x10e2c8 | FDE: 0x044b10 | Size: 256 bytes
// Khung tháo gỡ #1168 | Địa chỉ PC: 0x10e2c8 | Địa chỉ FDE: 0x044b10 | Kích thước: 256 bytes
//   0x10e2c8: D10303FF  sub      sp, sp, #0xc0
//   0x10e2cc: A90863F9  stp      x25, x24, [sp, #0x80]
//   0x10e2d0: A9095BF7  stp      x23, x22, [sp, #0x90]
//   0x10e2d4: A90A53F5  stp      x21, x20, [sp, #0xa0]
static inline uint64_t fde_func_1168_0x10e2c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10e2c8ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa90863f9ULL) ^ 0x044b10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1169 | PC: 0x10e70c | FDE: 0x044b38 | Size: 256 bytes
// Khung tháo gỡ #1169 | Địa chỉ PC: 0x10e70c | Địa chỉ FDE: 0x044b38 | Kích thước: 256 bytes
//   0x10e70c: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x10e710: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x10e714: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x10e718: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_1169_0x10e70c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10e70cULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x044b38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1170 | PC: 0x10e820 | FDE: 0x044b58 | Size: 256 bytes
// Khung tháo gỡ #1170 | Địa chỉ PC: 0x10e820 | Địa chỉ FDE: 0x044b58 | Kích thước: 256 bytes
//   0x10e820: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x10e824: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x10e828: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x10e82c: F0000577  adrp     x23, #0x1bd000
static inline uint64_t fde_func_1170_0x10e820(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10e820ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x044b58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1171 | PC: 0x10eb08 | FDE: 0x044b78 | Size: 256 bytes
// Khung tháo gỡ #1171 | Địa chỉ PC: 0x10eb08 | Địa chỉ FDE: 0x044b78 | Kích thước: 256 bytes
//   0x10eb08: D10243FF  sub      sp, sp, #0x90
//   0x10eb0c: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x10eb10: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x10eb14: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1171_0x10eb08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10eb08ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x044b78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1172 | PC: 0x10f618 | FDE: 0x044ba8 | Size: 256 bytes
// Khung tháo gỡ #1172 | Địa chỉ PC: 0x10f618 | Địa chỉ FDE: 0x044ba8 | Kích thước: 256 bytes
//   0x10f618: D10283FF  sub      sp, sp, #0xa0
//   0x10f61c: F9002BFA  str      x26, [sp, #0x50]
//   0x10f620: A90663F9  stp      x25, x24, [sp, #0x60]
//   0x10f624: A9075BF7  stp      x23, x22, [sp, #0x70]
static inline uint64_t fde_func_1172_0x10f618(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10f618ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9002bfaULL) ^ 0x044ba8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1173 | PC: 0x10fbbc | FDE: 0x044bd0 | Size: 256 bytes
// Khung tháo gỡ #1173 | Địa chỉ PC: 0x10fbbc | Địa chỉ FDE: 0x044bd0 | Kích thước: 256 bytes
//   0x10fbbc: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x10fbc0: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x10fbc4: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x10fbc8: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1173_0x10fbbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10fbbcULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x044bd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1174 | PC: 0x10fd24 | FDE: 0x044bf8 | Size: 256 bytes
// Khung tháo gỡ #1174 | Địa chỉ PC: 0x10fd24 | Địa chỉ FDE: 0x044bf8 | Kích thước: 256 bytes
//   0x10fd24: D10203FF  sub      sp, sp, #0x80
//   0x10fd28: F9001BFA  str      x26, [sp, #0x30]
//   0x10fd2c: A90463F9  stp      x25, x24, [sp, #0x40]
//   0x10fd30: A9055BF7  stp      x23, x22, [sp, #0x50]
static inline uint64_t fde_func_1174_0x10fd24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10fd24ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9001bfaULL) ^ 0x044bf8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1175 | PC: 0x1100a4 | FDE: 0x044c20 | Size: 256 bytes
// Khung tháo gỡ #1175 | Địa chỉ PC: 0x1100a4 | Địa chỉ FDE: 0x044c20 | Kích thước: 256 bytes
//   0x1100a4: D10203FF  sub      sp, sp, #0x80
//   0x1100a8: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x1100ac: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x1100b0: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1175_0x1100a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1100a4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x044c20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1176 | PC: 0x110414 | FDE: 0x044c50 | Size: 256 bytes
// Khung tháo gỡ #1176 | Địa chỉ PC: 0x110414 | Địa chỉ FDE: 0x044c50 | Kích thước: 256 bytes
//   0x110414: F81B0FFA  str      x26, [sp, #-0x50]!
//   0x110418: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x11041c: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x110420: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1176_0x110414(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x110414ULL ^ (static_cast<uint64_t>(0xf81b0ffaULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x044c50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1177 | PC: 0x110598 | FDE: 0x044c78 | Size: 256 bytes [lepus_get_length32]
// Khung tháo gỡ #1177 | Địa chỉ PC: 0x110598 | Địa chỉ FDE: 0x044c78 | Kích thước: 256 bytes
//   0x110598: F81B0FFA  str      x26, [sp, #-0x50]!
//   0x11059c: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x1105a0: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x1105a4: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1177_0x110598(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x110598ULL ^ (static_cast<uint64_t>(0xf81b0ffaULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x044c78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1178 | PC: 0x11076c | FDE: 0x044ca0 | Size: 256 bytes
// Khung tháo gỡ #1178 | Địa chỉ PC: 0x11076c | Địa chỉ FDE: 0x044ca0 | Kích thước: 256 bytes
//   0x11076c: D10143FF  sub      sp, sp, #0x50
//   0x110770: F9000BF8  str      x24, [sp, #0x10]
//   0x110774: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x110778: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1178_0x11076c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11076cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf8ULL) ^ 0x044ca0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1179 | PC: 0x110aa8 | FDE: 0x044cc8 | Size: 188 bytes
// Khung tháo gỡ #1179 | Địa chỉ PC: 0x110aa8 | Địa chỉ FDE: 0x044cc8 | Kích thước: 188 bytes
//   0x110aa8: D10483FF  sub      sp, sp, #0x120
//   0x110aac: F90083FC  str      x28, [sp, #0x100]
//   0x110ab0: A9117BF3  stp      x19, x30, [sp, #0x110]
//   0x110ab4: A90893E3  stp      x3, x4, [sp, #0x88]
static inline uint64_t fde_func_1179_0x110aa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x110aa8ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x044cc8ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1180 | PC: 0x110b64 | FDE: 0x044ce8 | Size: 256 bytes
// Khung tháo gỡ #1180 | Địa chỉ PC: 0x110b64 | Địa chỉ FDE: 0x044ce8 | Kích thước: 256 bytes
//   0x110b64: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x110b68: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x110b6c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x110b70: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1180_0x110b64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x110b64ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x044ce8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1181 | PC: 0x110ec0 | FDE: 0x044d10 | Size: 228 bytes [_Z17JS_ToBigInt64FreeP12LEPUSContextPl10LEPUSValue]
// Khung tháo gỡ #1181 | Địa chỉ PC: 0x110ec0 | Địa chỉ FDE: 0x044d10 | Kích thước: 228 bytes
//   0x110ec0: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x110ec4: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x110ec8: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x110ecc: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1181_0x110ec0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x110ec0ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x044d10ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #1182 | PC: 0x110fa4 | FDE: 0x044d30 | Size: 256 bytes
// Khung tháo gỡ #1182 | Địa chỉ PC: 0x110fa4 | Địa chỉ FDE: 0x044d30 | Kích thước: 256 bytes
//   0x110fa4: D102C3FF  sub      sp, sp, #0xb0
//   0x110fa8: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x110fac: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x110fb0: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_1182_0x110fa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x110fa4ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x044d30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1183 | PC: 0x1118e8 | FDE: 0x044d60 | Size: 256 bytes
// Khung tháo gỡ #1183 | Địa chỉ PC: 0x1118e8 | Địa chỉ FDE: 0x044d60 | Kích thước: 256 bytes
//   0x1118e8: D102C3FF  sub      sp, sp, #0xb0
//   0x1118ec: F9002BFC  str      x28, [sp, #0x50]
//   0x1118f0: A9066BFB  stp      x27, x26, [sp, #0x60]
//   0x1118f4: A90763F9  stp      x25, x24, [sp, #0x70]
static inline uint64_t fde_func_1183_0x1118e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1118e8ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bfcULL) ^ 0x044d60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1184 | PC: 0x111ce4 | FDE: 0x044d90 | Size: 256 bytes [LEPUS_ToInt32]
// Khung tháo gỡ #1184 | Địa chỉ PC: 0x111ce4 | Địa chỉ FDE: 0x044d90 | Kích thước: 256 bytes
//   0x111ce4: A9BB6BFB  stp      x27, x26, [sp, #-0x50]!
//   0x111ce8: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x111cec: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x111cf0: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1184_0x111ce4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x111ce4ULL ^ (static_cast<uint64_t>(0xa9bb6bfbULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x044d90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1185 | PC: 0x111efc | FDE: 0x044db8 | Size: 256 bytes
// Khung tháo gỡ #1185 | Địa chỉ PC: 0x111efc | Địa chỉ FDE: 0x044db8 | Kích thước: 256 bytes
//   0x111efc: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x111f00: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x111f04: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x111f08: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1185_0x111efc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x111efcULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x044db8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1186 | PC: 0x1121a8 | FDE: 0x044de0 | Size: 256 bytes
// Khung tháo gỡ #1186 | Địa chỉ PC: 0x1121a8 | Địa chỉ FDE: 0x044de0 | Kích thước: 256 bytes
//   0x1121a8: D10243FF  sub      sp, sp, #0x90
//   0x1121ac: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x1121b0: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x1121b4: A9074FF4  stp      x20, x19, [sp, #0x70]
static inline uint64_t fde_func_1186_0x1121a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1121a8ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9055ff8ULL) ^ 0x044de0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1187 | PC: 0x112330 | FDE: 0x044e08 | Size: 256 bytes [_Z15JS_ToBigIntFreeP12LEPUSContext10LEPUSValue]
// Khung tháo gỡ #1187 | Địa chỉ PC: 0x112330 | Địa chỉ FDE: 0x044e08 | Kích thước: 256 bytes
//   0x112330: A9BB6BFB  stp      x27, x26, [sp, #-0x50]!
//   0x112334: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x112338: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x11233c: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1187_0x112330(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x112330ULL ^ (static_cast<uint64_t>(0xa9bb6bfbULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x044e08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1188 | PC: 0x1125a8 | FDE: 0x044e30 | Size: 256 bytes
// Khung tháo gỡ #1188 | Địa chỉ PC: 0x1125a8 | Địa chỉ FDE: 0x044e30 | Kích thước: 256 bytes
//   0x1125a8: D10643FF  sub      sp, sp, #0x190
//   0x1125ac: F900A3FC  str      x28, [sp, #0x140]
//   0x1125b0: A91563F9  stp      x25, x24, [sp, #0x150]
//   0x1125b4: A9165BF7  stp      x23, x22, [sp, #0x160]
static inline uint64_t fde_func_1188_0x1125a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1125a8ULL ^ (static_cast<uint64_t>(0xd10643ffULL) << 13);
    acc = (acc + a1 + 0xf900a3fcULL) ^ 0x044e30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1189 | PC: 0x1128dc | FDE: 0x044e58 | Size: 256 bytes
// Khung tháo gỡ #1189 | Địa chỉ PC: 0x1128dc | Địa chỉ FDE: 0x044e58 | Kích thước: 256 bytes
//   0x1128dc: F81A0FFC  str      x28, [sp, #-0x60]!
//   0x1128e0: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x1128e4: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x1128e8: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_1189_0x1128dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1128dcULL ^ (static_cast<uint64_t>(0xf81a0ffcULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x044e58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1190 | PC: 0x112ab0 | FDE: 0x044e88 | Size: 256 bytes
// Khung tháo gỡ #1190 | Địa chỉ PC: 0x112ab0 | Địa chỉ FDE: 0x044e88 | Kích thước: 256 bytes
//   0x112ab0: D10243FF  sub      sp, sp, #0x90
//   0x112ab4: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x112ab8: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x112abc: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1190_0x112ab0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x112ab0ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x044e88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1191 | PC: 0x113028 | FDE: 0x044eb8 | Size: 256 bytes
// Khung tháo gỡ #1191 | Địa chỉ PC: 0x113028 | Địa chỉ FDE: 0x044eb8 | Kích thước: 256 bytes
//   0x113028: D101C3FF  sub      sp, sp, #0x70
//   0x11302c: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x113030: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x113034: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1191_0x113028(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x113028ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x044eb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1192 | PC: 0x113558 | FDE: 0x044ee8 | Size: 256 bytes
// Khung tháo gỡ #1192 | Địa chỉ PC: 0x113558 | Địa chỉ FDE: 0x044ee8 | Kích thước: 256 bytes
//   0x113558: D100C3FF  sub      sp, sp, #0x30
//   0x11355c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x113560: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x113564: AA0203F4  mov      x20, x2
static inline uint64_t fde_func_1192_0x113558(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x113558ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x044ee8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1193 | PC: 0x113798 | FDE: 0x044f08 | Size: 228 bytes [LEPUS_NewAtomUInt32]
// Khung tháo gỡ #1193 | Địa chỉ PC: 0x113798 | Địa chỉ FDE: 0x044f08 | Kích thước: 228 bytes
//   0x113798: D10103FF  sub      sp, sp, #0x40
//   0x11379c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x1137a0: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x1137a4: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_1193_0x113798(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x113798ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x044f08ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #1194 | PC: 0x11387c | FDE: 0x044f28 | Size: 160 bytes [LEPUS_ThrowRangeError]
// Khung tháo gỡ #1194 | Địa chỉ PC: 0x11387c | Địa chỉ FDE: 0x044f28 | Kích thước: 160 bytes
//   0x11387c: D10483FF  sub      sp, sp, #0x120
//   0x113880: F90083FC  str      x28, [sp, #0x100]
//   0x113884: A9117BF3  stp      x19, x30, [sp, #0x110]
//   0x113888: A9080FE2  stp      x2, x3, [sp, #0x80]
static inline uint64_t fde_func_1194_0x11387c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11387cULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x044f28ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1195 | PC: 0x11391c | FDE: 0x044f48 | Size: 256 bytes
// Khung tháo gỡ #1195 | Địa chỉ PC: 0x11391c | Địa chỉ FDE: 0x044f48 | Kích thước: 256 bytes
//   0x11391c: B9400408  ldr      w8, [x0, #4]
//   0x113920: B9400429  ldr      w9, [x1, #4]
//   0x113924: 37F801E8  tbnz     w8, #0x1f, #0x113960
//   0x113928: F940084A  ldr      x10, [x2, #0x10]
static inline uint64_t fde_func_1195_0x11391c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11391cULL ^ (static_cast<uint64_t>(0xb9400408ULL) << 13);
    acc = (acc + a1 + 0xb9400429ULL) ^ 0x044f48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1196 | PC: 0x113ac0 | FDE: 0x044f60 | Size: 256 bytes [LEPUS_ToFloat64]
// Khung tháo gỡ #1196 | Địa chỉ PC: 0x113ac0 | Địa chỉ FDE: 0x044f60 | Kích thước: 256 bytes
//   0x113ac0: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x113ac4: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x113ac8: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x113acc: 39458008  ldrb     w8, [x0, #0x160]
static inline uint64_t fde_func_1196_0x113ac0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x113ac0ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x044f60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1197 | PC: 0x113cc0 | FDE: 0x044f80 | Size: 256 bytes
// Khung tháo gỡ #1197 | Địa chỉ PC: 0x113cc0 | Địa chỉ FDE: 0x044f80 | Kích thước: 256 bytes
//   0x113cc0: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x113cc4: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x113cc8: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x113ccc: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1197_0x113cc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x113cc0ULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x044f80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1198 | PC: 0x113ea4 | FDE: 0x044fa8 | Size: 256 bytes
// Khung tháo gỡ #1198 | Địa chỉ PC: 0x113ea4 | Địa chỉ FDE: 0x044fa8 | Kích thước: 256 bytes
//   0x113ea4: D101C3FF  sub      sp, sp, #0x70
//   0x113ea8: F90013FA  str      x26, [sp, #0x20]
//   0x113eac: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x113eb0: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_1198_0x113ea4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x113ea4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013faULL) ^ 0x044fa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1199 | PC: 0x114320 | FDE: 0x044fd0 | Size: 256 bytes
// Khung tháo gỡ #1199 | Địa chỉ PC: 0x114320 | Địa chỉ FDE: 0x044fd0 | Kích thước: 256 bytes
//   0x114320: D10203FF  sub      sp, sp, #0x80
//   0x114324: F90013FC  str      x28, [sp, #0x20]
//   0x114328: A9036BFB  stp      x27, x26, [sp, #0x30]
//   0x11432c: A90463F9  stp      x25, x24, [sp, #0x40]
static inline uint64_t fde_func_1199_0x114320(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x114320ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fcULL) ^ 0x044fd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1200 | PC: 0x114a70 | FDE: 0x045000 | Size: 164 bytes
// Khung tháo gỡ #1200 | Địa chỉ PC: 0x114a70 | Địa chỉ FDE: 0x045000 | Kích thước: 164 bytes
//   0x114a70: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x114a74: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x114a78: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x114a7c: F9403828  ldr      x8, [x1, #0x70]
static inline uint64_t fde_func_1200_0x114a70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x114a70ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x045000ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1201 | PC: 0x114b14 | FDE: 0x045020 | Size: 256 bytes
// Khung tháo gỡ #1201 | Địa chỉ PC: 0x114b14 | Địa chỉ FDE: 0x045020 | Kích thước: 256 bytes
//   0x114b14: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x114b18: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x114b1c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x114b20: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1201_0x114b14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x114b14ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x045020ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1202 | PC: 0x114f08 | FDE: 0x045050 | Size: 256 bytes
// Khung tháo gỡ #1202 | Địa chỉ PC: 0x114f08 | Địa chỉ FDE: 0x045050 | Kích thước: 256 bytes
//   0x114f08: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x114f0c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x114f10: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x114f14: D2800069  mov      x9, #3
static inline uint64_t fde_func_1202_0x114f08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x114f08ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x045050ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1203 | PC: 0x115204 | FDE: 0x045070 | Size: 256 bytes
// Khung tháo gỡ #1203 | Địa chỉ PC: 0x115204 | Địa chỉ FDE: 0x045070 | Kích thước: 256 bytes
//   0x115204: D104C3FF  sub      sp, sp, #0x130
//   0x115208: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x11520c: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x115210: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_1203_0x115204(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115204ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x045070ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1204 | PC: 0x11591c | FDE: 0x0450a0 | Size: 256 bytes
// Khung tháo gỡ #1204 | Địa chỉ PC: 0x11591c | Địa chỉ FDE: 0x0450a0 | Kích thước: 256 bytes
//   0x11591c: D10203FF  sub      sp, sp, #0x80
//   0x115920: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x115924: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x115928: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1204_0x11591c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11591cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x0450a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1205 | PC: 0x115c34 | FDE: 0x0450d0 | Size: 256 bytes
// Khung tháo gỡ #1205 | Địa chỉ PC: 0x115c34 | Địa chỉ FDE: 0x0450d0 | Kích thước: 256 bytes
//   0x115c34: D101C3FF  sub      sp, sp, #0x70
//   0x115c38: F90013FA  str      x26, [sp, #0x20]
//   0x115c3c: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x115c40: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_1205_0x115c34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115c34ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013faULL) ^ 0x0450d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1206 | PC: 0x115d7c | FDE: 0x0450f8 | Size: 256 bytes
// Khung tháo gỡ #1206 | Địa chỉ PC: 0x115d7c | Địa chỉ FDE: 0x0450f8 | Kích thước: 256 bytes
//   0x115d7c: D10283FF  sub      sp, sp, #0xa0
//   0x115d80: F9002BFA  str      x26, [sp, #0x50]
//   0x115d84: A90663F9  stp      x25, x24, [sp, #0x60]
//   0x115d88: A9075BF7  stp      x23, x22, [sp, #0x70]
static inline uint64_t fde_func_1206_0x115d7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115d7cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9002bfaULL) ^ 0x0450f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1207 | PC: 0x116128 | FDE: 0x045120 | Size: 204 bytes
// Khung tháo gỡ #1207 | Địa chỉ PC: 0x116128 | Địa chỉ FDE: 0x045120 | Kích thước: 204 bytes
//   0x116128: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x11612c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x116130: F9402C61  ldr      x1, [x3, #0x58]
//   0x116134: AA0303F3  mov      x19, x3
static inline uint64_t fde_func_1207_0x116128(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x116128ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x045120ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1208 | PC: 0x1161f4 | FDE: 0x045140 | Size: 256 bytes
// Khung tháo gỡ #1208 | Địa chỉ PC: 0x1161f4 | Địa chỉ FDE: 0x045140 | Kích thước: 256 bytes
//   0x1161f4: D101C3FF  sub      sp, sp, #0x70
//   0x1161f8: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x1161fc: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x116200: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1208_0x1161f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1161f4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x045140ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1209 | PC: 0x116520 | FDE: 0x045170 | Size: 256 bytes
// Khung tháo gỡ #1209 | Địa chỉ PC: 0x116520 | Địa chỉ FDE: 0x045170 | Kích thước: 256 bytes
//   0x116520: D10443FF  sub      sp, sp, #0x110
//   0x116524: A90B6FFC  stp      x28, x27, [sp, #0xb0]
//   0x116528: A90C67FA  stp      x26, x25, [sp, #0xc0]
//   0x11652c: A90D5FF8  stp      x24, x23, [sp, #0xd0]
static inline uint64_t fde_func_1209_0x116520(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x116520ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90b6ffcULL) ^ 0x045170ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1210 | PC: 0x117114 | FDE: 0x0451a0 | Size: 256 bytes
// Khung tháo gỡ #1210 | Địa chỉ PC: 0x117114 | Địa chỉ FDE: 0x0451a0 | Kích thước: 256 bytes
//   0x117114: D101C3FF  sub      sp, sp, #0x70
//   0x117118: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x11711c: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x117120: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1210_0x117114(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x117114ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x0451a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1211 | PC: 0x1175e4 | FDE: 0x0451d0 | Size: 256 bytes
// Khung tháo gỡ #1211 | Địa chỉ PC: 0x1175e4 | Địa chỉ FDE: 0x0451d0 | Kích thước: 256 bytes
//   0x1175e4: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x1175e8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1175ec: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1175f0: F94000A8  ldr      x8, [x5]
static inline uint64_t fde_func_1211_0x1175e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1175e4ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0451d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1212 | PC: 0x117744 | FDE: 0x0451f0 | Size: 256 bytes [LEPUS_NewCFunctionData]
// Khung tháo gỡ #1212 | Địa chỉ PC: 0x117744 | Địa chỉ FDE: 0x0451f0 | Kích thước: 256 bytes
//   0x117744: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x117748: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x11774c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x117750: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1212_0x117744(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x117744ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0451f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1213 | PC: 0x117a40 | FDE: 0x045220 | Size: 256 bytes
// Khung tháo gỡ #1213 | Địa chỉ PC: 0x117a40 | Địa chỉ FDE: 0x045220 | Kích thước: 256 bytes
//   0x117a40: D101C3FF  sub      sp, sp, #0x70
//   0x117a44: A9026BFB  stp      x27, x26, [sp, #0x20]
//   0x117a48: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x117a4c: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_1213_0x117a40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x117a40ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9026bfbULL) ^ 0x045220ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1214 | PC: 0x1180ec | FDE: 0x045248 | Size: 256 bytes
// Khung tháo gỡ #1214 | Địa chỉ PC: 0x1180ec | Địa chỉ FDE: 0x045248 | Kích thước: 256 bytes
//   0x1180ec: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x1180f0: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x1180f4: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x1180f8: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1214_0x1180ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1180ecULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x045248ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1215 | PC: 0x11837c | FDE: 0x045270 | Size: 256 bytes
// Khung tháo gỡ #1215 | Địa chỉ PC: 0x11837c | Địa chỉ FDE: 0x045270 | Kích thước: 256 bytes
//   0x11837c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x118380: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x118384: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x118388: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1215_0x11837c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11837cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x045270ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1216 | PC: 0x118748 | FDE: 0x0452a0 | Size: 256 bytes
// Khung tháo gỡ #1216 | Địa chỉ PC: 0x118748 | Địa chỉ FDE: 0x0452a0 | Kích thước: 256 bytes
//   0x118748: D101C3FF  sub      sp, sp, #0x70
//   0x11874c: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x118750: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x118754: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1216_0x118748(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x118748ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x0452a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1217 | PC: 0x118c34 | FDE: 0x0452d0 | Size: 256 bytes [LEPUS_RunGC]
// Khung tháo gỡ #1217 | Địa chỉ PC: 0x118c34 | Địa chỉ FDE: 0x0452d0 | Kích thước: 256 bytes
//   0x118c34: D101C3FF  sub      sp, sp, #0x70
//   0x118c38: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x118c3c: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x118c40: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1217_0x118c34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x118c34ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x0452d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1218 | PC: 0x119544 | FDE: 0x045300 | Size: 256 bytes
// Khung tháo gỡ #1218 | Địa chỉ PC: 0x119544 | Địa chỉ FDE: 0x045300 | Kích thước: 256 bytes
//   0x119544: 90000528  adrp     x8, #0x1bd000
//   0x119548: F940D908  ldr      x8, [x8, #0x1b0]
//   0x11954c: 927EB429  and      x9, x1, #0xfffffffffffc
//   0x119550: 9250442C  and      x12, x1, #0xffff000000000003
static inline uint64_t fde_func_1218_0x119544(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119544ULL ^ (static_cast<uint64_t>(0x90000528ULL) << 13);
    acc = (acc + a1 + 0xf940d908ULL) ^ 0x045300ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1219 | PC: 0x11968c | FDE: 0x045318 | Size: 256 bytes
// Khung tháo gỡ #1219 | Địa chỉ PC: 0x11968c | Địa chỉ FDE: 0x045318 | Kích thước: 256 bytes
//   0x11968c: A9BB6BFB  stp      x27, x26, [sp, #-0x50]!
//   0x119690: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x119694: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x119698: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1219_0x11968c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11968cULL ^ (static_cast<uint64_t>(0xa9bb6bfbULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x045318ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1220 | PC: 0x1199f8 | FDE: 0x045340 | Size: 256 bytes
// Khung tháo gỡ #1220 | Địa chỉ PC: 0x1199f8 | Địa chỉ FDE: 0x045340 | Kích thước: 256 bytes
//   0x1199f8: B940C408  ldr      w8, [x0, #0xc4]
//   0x1199fc: 7100851F  cmp      w8, #0x21
//   0x119a00: 540006AB  b.lt     #0x119ad4
//   0x119a04: 92504428  and      x8, x1, #0xffff000000000003
static inline uint64_t fde_func_1220_0x1199f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1199f8ULL ^ (static_cast<uint64_t>(0xb940c408ULL) << 13);
    acc = (acc + a1 + 0x7100851fULL) ^ 0x045340ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1221 | PC: 0x119b84 | FDE: 0x045358 | Size: 256 bytes
// Khung tháo gỡ #1221 | Địa chỉ PC: 0x119b84 | Địa chỉ FDE: 0x045358 | Kích thước: 256 bytes
//   0x119b84: 92504428  and      x8, x1, #0xffff000000000003
//   0x119b88: D2FFFFE9  mov      x9, #-0x1000000000000
//   0x119b8c: EB09011F  cmp      x8, x9
//   0x119b90: 90000529  adrp     x9, #0x1bd000
static inline uint64_t fde_func_1221_0x119b84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119b84ULL ^ (static_cast<uint64_t>(0x92504428ULL) << 13);
    acc = (acc + a1 + 0xd2ffffe9ULL) ^ 0x045358ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1222 | PC: 0x119d5c | FDE: 0x045370 | Size: 256 bytes
// Khung tháo gỡ #1222 | Địa chỉ PC: 0x119d5c | Địa chỉ FDE: 0x045370 | Kích thước: 256 bytes
//   0x119d5c: 90000528  adrp     x8, #0x1bd000
//   0x119d60: F940D908  ldr      x8, [x8, #0x1b0]
//   0x119d64: 927EB429  and      x9, x1, #0xfffffffffffc
//   0x119d68: F940010B  ldr      x11, [x8]
static inline uint64_t fde_func_1222_0x119d5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119d5cULL ^ (static_cast<uint64_t>(0x90000528ULL) << 13);
    acc = (acc + a1 + 0xf940d908ULL) ^ 0x045370ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1223 | PC: 0x119ec8 | FDE: 0x045388 | Size: 128 bytes
// Khung tháo gỡ #1223 | Địa chỉ PC: 0x119ec8 | Địa chỉ FDE: 0x045388 | Kích thước: 128 bytes
//   0x119ec8: 9000052A  adrp     x10, #0x1bd000
//   0x119ecc: F940D94A  ldr      x10, [x10, #0x1b0]
//   0x119ed0: 927EB42B  and      x11, x1, #0xfffffffffffc
//   0x119ed4: 9250442C  and      x12, x1, #0xffff000000000003
static inline uint64_t fde_func_1223_0x119ec8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119ec8ULL ^ (static_cast<uint64_t>(0x9000052aULL) << 13);
    acc = (acc + a1 + 0xf940d94aULL) ^ 0x045388ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1224 | PC: 0x119f48 | FDE: 0x0453a0 | Size: 248 bytes
// Khung tháo gỡ #1224 | Địa chỉ PC: 0x119f48 | Địa chỉ FDE: 0x0453a0 | Kích thước: 248 bytes
//   0x119f48: 92503C28  and      x8, x1, #0xffff000000000000
//   0x119f4c: D2E00029  mov      x9, #0x1000000000000
//   0x119f50: AA0203E4  mov      x4, x2
//   0x119f54: EB09011F  cmp      x8, x9
static inline uint64_t fde_func_1224_0x119f48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119f48ULL ^ (static_cast<uint64_t>(0x92503c28ULL) << 13);
    acc = (acc + a1 + 0xd2e00029ULL) ^ 0x0453a0ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #1225 | PC: 0x11a040 | FDE: 0x0453b8 | Size: 200 bytes
// Khung tháo gỡ #1225 | Địa chỉ PC: 0x11a040 | Địa chỉ FDE: 0x0453b8 | Kích thước: 200 bytes
//   0x11a040: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x11a044: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x11a048: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x11a04c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1225_0x11a040(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a040ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0453b8ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1226 | PC: 0x11a108 | FDE: 0x0453e0 | Size: 232 bytes
// Khung tháo gỡ #1226 | Địa chỉ PC: 0x11a108 | Địa chỉ FDE: 0x0453e0 | Kích thước: 232 bytes
//   0x11a108: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x11a10c: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x11a110: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x11a114: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1226_0x11a108(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a108ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0453e0ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1227 | PC: 0x11a1f0 | FDE: 0x045408 | Size: 256 bytes
// Khung tháo gỡ #1227 | Địa chỉ PC: 0x11a1f0 | Địa chỉ FDE: 0x045408 | Kích thước: 256 bytes
//   0x11a1f0: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x11a1f4: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x11a1f8: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x11a1fc: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1227_0x11a1f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a1f0ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x045408ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1228 | PC: 0x11a390 | FDE: 0x045430 | Size: 156 bytes
// Khung tháo gỡ #1228 | Địa chỉ PC: 0x11a390 | Địa chỉ FDE: 0x045430 | Kích thước: 156 bytes
//   0x11a390: D10483FF  sub      sp, sp, #0x120
//   0x11a394: F90083FC  str      x28, [sp, #0x100]
//   0x11a398: A9117BF3  stp      x19, x30, [sp, #0x110]
//   0x11a39c: A9080FE2  stp      x2, x3, [sp, #0x80]
static inline uint64_t fde_func_1228_0x11a390(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a390ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x045430ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1229 | PC: 0x11a42c | FDE: 0x045450 | Size: 216 bytes
// Khung tháo gỡ #1229 | Địa chỉ PC: 0x11a42c | Địa chỉ FDE: 0x045450 | Kích thước: 216 bytes
//   0x11a42c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x11a430: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x11a434: 71404034  subs     w20, w1, #0x10, lsl #12
//   0x11a438: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1229_0x11a42c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a42cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x045450ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1230 | PC: 0x11a504 | FDE: 0x045470 | Size: 148 bytes [LEPUS_IsNumber]
// Khung tháo gỡ #1230 | Địa chỉ PC: 0x11a504 | Địa chỉ FDE: 0x045470 | Kích thước: 148 bytes
//   0x11a504: D371FC08  lsr      x8, x0, #0x31
//   0x11a508: B6800040  tbz      x0, #0x30, #0x11a510
//   0x11a50c: B4000108  cbz      x8, #0x11a52c
//   0x11a510: D2800049  mov      x9, #2
static inline uint64_t fde_func_1230_0x11a504(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a504ULL ^ (static_cast<uint64_t>(0xd371fc08ULL) << 13);
    acc = (acc + a1 + 0xb6800040ULL) ^ 0x045470ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1231 | PC: 0x11a598 | FDE: 0x045488 | Size: 12 bytes [RegisterLepusType]
// Khung tháo gỡ #1231 | Địa chỉ PC: 0x11a598 | Địa chỉ FDE: 0x045488 | Kích thước: 12 bytes
//   0x11a598: B9020801  str      w1, [x0, #0x208]
//   0x11a59c: B9020C02  str      w2, [x0, #0x20c]
//   0x11a5a0: D65F03C0  ret      
static inline uint64_t fde_func_1231_0x11a598(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a598ULL ^ (static_cast<uint64_t>(0xb9020801ULL) << 13);
    acc = (acc + a1 + 0xb9020c02ULL) ^ 0x045488ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1232 | PC: 0x11a5a4 | FDE: 0x0454a0 | Size: 52 bytes [LEPUS_RegisterNgType]
// Khung tháo gỡ #1232 | Địa chỉ PC: 0x11a5a4 | Địa chỉ FDE: 0x0454a0 | Kích thước: 52 bytes
//   0x11a5a4: 34000182  cbz      w2, #0x11a5d4
//   0x11a5a8: AA1F03E8  mov      x8, xzr
//   0x11a5ac: 2A0203E9  mov      w9, w2
//   0x11a5b0: 9108200A  add      x10, x0, #0x208
static inline uint64_t fde_func_1232_0x11a5a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a5a4ULL ^ (static_cast<uint64_t>(0x34000182ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e8ULL) ^ 0x0454a0ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1233 | PC: 0x11a5d8 | FDE: 0x0454b8 | Size: 12 bytes [lepus_free_rt]
// Khung tháo gỡ #1233 | Địa chỉ PC: 0x11a5d8 | Địa chỉ FDE: 0x0454b8 | Kích thước: 12 bytes
//   0x11a5d8: F9400402  ldr      x2, [x0, #8]
//   0x11a5dc: 910D2000  add      x0, x0, #0x348
//   0x11a5e0: D61F0040  br       x2
static inline uint64_t fde_func_1233_0x11a5d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a5d8ULL ^ (static_cast<uint64_t>(0xf9400402ULL) << 13);
    acc = (acc + a1 + 0x910d2000ULL) ^ 0x0454b8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1234 | PC: 0x11a5e4 | FDE: 0x0454d0 | Size: 100 bytes [lepus_malloc]
// Khung tháo gỡ #1234 | Địa chỉ PC: 0x11a5e4 | Địa chỉ FDE: 0x0454d0 | Kích thước: 100 bytes
//   0x11a5e4: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x11a5e8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x11a5ec: F9400808  ldr      x8, [x0, #0x10]
//   0x11a5f0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1234_0x11a5e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a5e4ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0454d0ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1235 | PC: 0x11a648 | FDE: 0x0454f0 | Size: 52 bytes [LEPUS_ThrowOutOfMemory]
// Khung tháo gỡ #1235 | Địa chỉ PC: 0x11a648 | Địa chỉ FDE: 0x0454f0 | Kích thước: 52 bytes
//   0x11a648: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x11a64c: F9400813  ldr      x19, [x0, #0x10]
//   0x11a650: 3943B268  ldrb     w8, [x19, #0xec]
//   0x11a654: 350000E8  cbnz     w8, #0x11a670
static inline uint64_t fde_func_1235_0x11a648(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a648ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400813ULL) ^ 0x0454f0ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1236 | PC: 0x11a67c | FDE: 0x045508 | Size: 124 bytes [lepus_mallocz]
// Khung tháo gỡ #1236 | Địa chỉ PC: 0x11a67c | Địa chỉ FDE: 0x045508 | Kích thước: 124 bytes
//   0x11a67c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x11a680: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x11a684: F9400808  ldr      x8, [x0, #0x10]
//   0x11a688: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1236_0x11a67c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a67cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x045508ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1237 | PC: 0x11a6f8 | FDE: 0x045528 | Size: 16 bytes [lepus_free]
// Khung tháo gỡ #1237 | Địa chỉ PC: 0x11a6f8 | Địa chỉ FDE: 0x045528 | Kích thước: 16 bytes
//   0x11a6f8: F9400808  ldr      x8, [x0, #0x10]
//   0x11a6fc: F9400502  ldr      x2, [x8, #8]
//   0x11a700: 910D2100  add      x0, x8, #0x348
//   0x11a704: D61F0040  br       x2
static inline uint64_t fde_func_1237_0x11a6f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a6f8ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xf9400502ULL) ^ 0x045528ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1238 | PC: 0x11a708 | FDE: 0x045540 | Size: 68 bytes [_Z12js_strmallocPKcm]
// Khung tháo gỡ #1238 | Địa chỉ PC: 0x11a708 | Địa chỉ FDE: 0x045540 | Kích thước: 68 bytes
//   0x11a708: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x11a70c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x11a710: AA0003F5  mov      x21, x0
//   0x11a714: 91000420  add      x0, x1, #1
static inline uint64_t fde_func_1238_0x11a708(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a708ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x045540ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1239 | PC: 0x11a74c | FDE: 0x045560 | Size: 256 bytes
// Khung tháo gỡ #1239 | Địa chỉ PC: 0x11a74c | Địa chỉ FDE: 0x045560 | Kích thước: 256 bytes
//   0x11a74c: F81A0FFC  str      x28, [sp, #-0x60]!
//   0x11a750: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x11a754: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x11a758: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_1239_0x11a74c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a74cULL ^ (static_cast<uint64_t>(0xf81a0ffcULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x045560ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1240 | PC: 0x11a938 | FDE: 0x045590 | Size: 232 bytes [_Z16init_bigint_nameP12LEPUSRuntime]
// Khung tháo gỡ #1240 | Địa chỉ PC: 0x11a938 | Địa chỉ FDE: 0x045590 | Kích thước: 232 bytes
//   0x11a938: D10143FF  sub      sp, sp, #0x50
//   0x11a93c: F9001BF4  str      x20, [sp, #0x30]
//   0x11a940: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x11a944: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_1240_0x11a938(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a938ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf4ULL) ^ 0x045590ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1241 | PC: 0x11aa20 | FDE: 0x0455b0 | Size: 256 bytes [_Z16__JS_NewAtomInitP12LEPUSRuntimePKciii]
// Khung tháo gỡ #1241 | Địa chỉ PC: 0x11aa20 | Địa chỉ FDE: 0x0455b0 | Kích thước: 256 bytes
//   0x11aa20: F81B0FFA  str      x26, [sp, #-0x50]!
//   0x11aa24: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x11aa28: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x11aa2c: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1241_0x11aa20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11aa20ULL ^ (static_cast<uint64_t>(0xf81b0ffaULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x0455b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1242 | PC: 0x11ab20 | FDE: 0x0455d8 | Size: 20 bytes [_Z10gc_enabledv]
// Khung tháo gỡ #1242 | Địa chỉ PC: 0x11ab20 | Địa chỉ FDE: 0x0455d8 | Kích thước: 20 bytes
//   0x11ab20: F0000508  adrp     x8, #0x1bd000
//   0x11ab24: F9410D08  ldr      x8, [x8, #0x218]
//   0x11ab28: 39400508  ldrb     w8, [x8, #1]
//   0x11ab2c: 12000100  and      w0, w8, #1
static inline uint64_t fde_func_1242_0x11ab20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ab20ULL ^ (static_cast<uint64_t>(0xf0000508ULL) << 13);
    acc = (acc + a1 + 0xf9410d08ULL) ^ 0x0455d8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1243 | PC: 0x11ab34 | FDE: 0x0455f0 | Size: 48 bytes [_Z21get_lepusng_heap_modev]
// Khung tháo gỡ #1243 | Địa chỉ PC: 0x11ab34 | Địa chỉ FDE: 0x0455f0 | Kích thước: 48 bytes
//   0x11ab34: F0000508  adrp     x8, #0x1bd000
//   0x11ab38: F9410D08  ldr      x8, [x8, #0x218]
//   0x11ab3c: B9400108  ldr      w8, [x8]
//   0x11ab40: 376000A8  tbnz     w8, #0xc, #0x11ab54
static inline uint64_t fde_func_1243_0x11ab34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ab34ULL ^ (static_cast<uint64_t>(0xf0000508ULL) << 13);
    acc = (acc + a1 + 0xf9410d08ULL) ^ 0x0455f0ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1244 | PC: 0x11ab64 | FDE: 0x045608 | Size: 20 bytes [_Z14effect_enabledv]
// Khung tháo gỡ #1244 | Địa chỉ PC: 0x11ab64 | Địa chỉ FDE: 0x045608 | Kích thước: 20 bytes
//   0x11ab64: F0000508  adrp     x8, #0x1bd000
//   0x11ab68: F9410D08  ldr      x8, [x8, #0x218]
//   0x11ab6c: 39400508  ldrb     w8, [x8, #1]
//   0x11ab70: 53010500  ubfx     w0, w8, #1, #1
static inline uint64_t fde_func_1244_0x11ab64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ab64ULL ^ (static_cast<uint64_t>(0xf0000508ULL) << 13);
    acc = (acc + a1 + 0xf9410d08ULL) ^ 0x045608ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1245 | PC: 0x11ab78 | FDE: 0x045620 | Size: 20 bytes [_Z19lepusng_gc_disabledv]
// Khung tháo gỡ #1245 | Địa chỉ PC: 0x11ab78 | Địa chỉ FDE: 0x045620 | Kích thước: 20 bytes
//   0x11ab78: F0000508  adrp     x8, #0x1bd000
//   0x11ab7c: F9410D08  ldr      x8, [x8, #0x218]
//   0x11ab80: 39400508  ldrb     w8, [x8, #1]
//   0x11ab84: 53051500  ubfx     w0, w8, #5, #1
static inline uint64_t fde_func_1245_0x11ab78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ab78ULL ^ (static_cast<uint64_t>(0xf0000508ULL) << 13);
    acc = (acc + a1 + 0xf9410d08ULL) ^ 0x045620ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1246 | PC: 0x11ab8c | FDE: 0x045638 | Size: 256 bytes [LEPUS_NewRuntime2]
// Khung tháo gỡ #1246 | Địa chỉ PC: 0x11ab8c | Địa chỉ FDE: 0x045638 | Kích thước: 256 bytes
//   0x11ab8c: A9BB67FC  stp      x28, x25, [sp, #-0x50]!
//   0x11ab90: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x11ab94: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x11ab98: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1246_0x11ab8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ab8cULL ^ (static_cast<uint64_t>(0xa9bb67fcULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x045638ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1247 | PC: 0x11afd8 | FDE: 0x045668 | Size: 256 bytes
// Khung tháo gỡ #1247 | Địa chỉ PC: 0x11afd8 | Địa chỉ FDE: 0x045668 | Kích thước: 256 bytes
//   0x11afd8: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x11afdc: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x11afe0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x11afe4: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1247_0x11afd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11afd8ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x045668ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1248 | PC: 0x11b180 | FDE: 0x045698 | Size: 256 bytes
// Khung tháo gỡ #1248 | Địa chỉ PC: 0x11b180 | Địa chỉ FDE: 0x045698 | Kích thước: 256 bytes
//   0x11b180: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x11b184: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x11b188: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x11b18c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1248_0x11b180(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b180ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x045698ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1249 | PC: 0x11b5c4 | FDE: 0x0456c8 | Size: 256 bytes
// Khung tháo gỡ #1249 | Địa chỉ PC: 0x11b5c4 | Địa chỉ FDE: 0x0456c8 | Kích thước: 256 bytes
//   0x11b5c4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x11b5c8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x11b5cc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x11b5d0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1249_0x11b5c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b5c4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0456c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1250 | PC: 0x11b6cc | FDE: 0x0456f0 | Size: 256 bytes
// Khung tháo gỡ #1250 | Địa chỉ PC: 0x11b6cc | Địa chỉ FDE: 0x0456f0 | Kích thước: 256 bytes
//   0x11b6cc: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x11b6d0: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x11b6d4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x11b6d8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1250_0x11b6cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b6ccULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0456f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1251 | PC: 0x11ba34 | FDE: 0x045720 | Size: 256 bytes
// Khung tháo gỡ #1251 | Địa chỉ PC: 0x11ba34 | Địa chỉ FDE: 0x045720 | Kích thước: 256 bytes
//   0x11ba34: D102C3FF  sub      sp, sp, #0xb0
//   0x11ba38: F9002BFB  str      x27, [sp, #0x50]
//   0x11ba3c: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x11ba40: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_1251_0x11ba34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ba34ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bfbULL) ^ 0x045720ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1252 | PC: 0x11bd54 | FDE: 0x045750 | Size: 256 bytes [LEPUS_FreeRuntime]
// Khung tháo gỡ #1252 | Địa chỉ PC: 0x11bd54 | Địa chỉ FDE: 0x045750 | Kích thước: 256 bytes
//   0x11bd54: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x11bd58: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x11bd5c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x11bd60: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1252_0x11bd54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11bd54ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x045750ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1253 | PC: 0x11c250 | FDE: 0x045780 | Size: 256 bytes [LEPUS_FreeContext]
// Khung tháo gỡ #1253 | Địa chỉ PC: 0x11c250 | Địa chỉ FDE: 0x045780 | Kích thước: 256 bytes
//   0x11c250: F81A0FFC  str      x28, [sp, #-0x60]!
//   0x11c254: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x11c258: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x11c25c: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_1253_0x11c250(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11c250ULL ^ (static_cast<uint64_t>(0xf81a0ffcULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x045780ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1254 | PC: 0x11caa4 | FDE: 0x0457b0 | Size: 256 bytes
// Khung tháo gỡ #1254 | Địa chỉ PC: 0x11caa4 | Địa chỉ FDE: 0x0457b0 | Kích thước: 256 bytes
//   0x11caa4: D101C3FF  sub      sp, sp, #0x70
//   0x11caa8: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x11caac: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x11cab0: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1254_0x11caa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11caa4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x0457b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1255 | PC: 0x11cdd0 | FDE: 0x0457e0 | Size: 256 bytes
// Khung tháo gỡ #1255 | Địa chỉ PC: 0x11cdd0 | Địa chỉ FDE: 0x0457e0 | Kích thước: 256 bytes
//   0x11cdd0: D101C3FF  sub      sp, sp, #0x70
//   0x11cdd4: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x11cdd8: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x11cddc: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1255_0x11cdd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11cdd0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x0457e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1256 | PC: 0x11d098 | FDE: 0x045810 | Size: 256 bytes
// Khung tháo gỡ #1256 | Địa chỉ PC: 0x11d098 | Địa chỉ FDE: 0x045810 | Kích thước: 256 bytes
//   0x11d098: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x11d09c: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x11d0a0: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x11d0a4: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1256_0x11d098(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11d098ULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x045810ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1257 | PC: 0x11d2f4 | FDE: 0x045838 | Size: 256 bytes
// Khung tháo gỡ #1257 | Địa chỉ PC: 0x11d2f4 | Địa chỉ FDE: 0x045838 | Kích thước: 256 bytes
//   0x11d2f4: F81B0FFA  str      x26, [sp, #-0x50]!
//   0x11d2f8: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x11d2fc: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x11d300: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1257_0x11d2f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11d2f4ULL ^ (static_cast<uint64_t>(0xf81b0ffaULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x045838ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1258 | PC: 0x11d5a8 | FDE: 0x045860 | Size: 256 bytes
// Khung tháo gỡ #1258 | Địa chỉ PC: 0x11d5a8 | Địa chỉ FDE: 0x045860 | Kích thước: 256 bytes
//   0x11d5a8: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x11d5ac: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x11d5b0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x11d5b4: 90000508  adrp     x8, #0x1bd000
static inline uint64_t fde_func_1258_0x11d5a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11d5a8ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x045860ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1259 | PC: 0x11d6e8 | FDE: 0x045880 | Size: 256 bytes
// Khung tháo gỡ #1259 | Địa chỉ PC: 0x11d6e8 | Địa chỉ FDE: 0x045880 | Kích thước: 256 bytes
//   0x11d6e8: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x11d6ec: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x11d6f0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x11d6f4: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1259_0x11d6e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11d6e8ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x045880ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1260 | PC: 0x11d9dc | FDE: 0x0458b0 | Size: 256 bytes
// Khung tháo gỡ #1260 | Địa chỉ PC: 0x11d9dc | Địa chỉ FDE: 0x0458b0 | Kích thước: 256 bytes
//   0x11d9dc: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x11d9e0: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x11d9e4: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x11d9e8: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1260_0x11d9dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11d9dcULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0458b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1261 | PC: 0x11db48 | FDE: 0x0458d8 | Size: 256 bytes
// Khung tháo gỡ #1261 | Địa chỉ PC: 0x11db48 | Địa chỉ FDE: 0x0458d8 | Kích thước: 256 bytes
//   0x11db48: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x11db4c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x11db50: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x11db54: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1261_0x11db48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11db48ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0458d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1262 | PC: 0x11dc70 | FDE: 0x045908 | Size: 108 bytes
// Khung tháo gỡ #1262 | Địa chỉ PC: 0x11dc70 | Địa chỉ FDE: 0x045908 | Kích thước: 108 bytes
//   0x11dc70: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x11dc74: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x11dc78: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x11dc7c: 90000508  adrp     x8, #0x1bd000
static inline uint64_t fde_func_1262_0x11dc70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11dc70ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x045908ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1263 | PC: 0x11dcdc | FDE: 0x045928 | Size: 224 bytes
// Khung tháo gỡ #1263 | Địa chỉ PC: 0x11dcdc | Địa chỉ FDE: 0x045928 | Kích thước: 224 bytes
//   0x11dcdc: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x11dce0: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x11dce4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x11dce8: 90000508  adrp     x8, #0x1bd000
static inline uint64_t fde_func_1263_0x11dcdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11dcdcULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x045928ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #1264 | PC: 0x11ddbc | FDE: 0x045948 | Size: 32 bytes
// Khung tháo gỡ #1264 | Địa chỉ PC: 0x11ddbc | Địa chỉ FDE: 0x045948 | Kích thước: 32 bytes
//   0x11ddbc: 90000508  adrp     x8, #0x1bd000
//   0x11ddc0: F940D908  ldr      x8, [x8, #0x1b0]
//   0x11ddc4: 927EB429  and      x9, x1, #0xfffffffffffc
//   0x11ddc8: AA1F03E3  mov      x3, xzr
static inline uint64_t fde_func_1264_0x11ddbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ddbcULL ^ (static_cast<uint64_t>(0x90000508ULL) << 13);
    acc = (acc + a1 + 0xf940d908ULL) ^ 0x045948ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1265 | PC: 0x11dddc | FDE: 0x045960 | Size: 256 bytes
// Khung tháo gỡ #1265 | Địa chỉ PC: 0x11dddc | Địa chỉ FDE: 0x045960 | Kích thước: 256 bytes
//   0x11dddc: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x11dde0: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x11dde4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x11dde8: 90000515  adrp     x21, #0x1bd000
static inline uint64_t fde_func_1265_0x11dddc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11dddcULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x045960ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1266 | PC: 0x11df28 | FDE: 0x045980 | Size: 228 bytes
// Khung tháo gỡ #1266 | Địa chỉ PC: 0x11df28 | Địa chỉ FDE: 0x045980 | Kích thước: 228 bytes
//   0x11df28: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x11df2c: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x11df30: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x11df34: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1266_0x11df28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11df28ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x045980ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #1267 | PC: 0x11e00c | FDE: 0x0459a8 | Size: 256 bytes
// Khung tháo gỡ #1267 | Địa chỉ PC: 0x11e00c | Địa chỉ FDE: 0x0459a8 | Kích thước: 256 bytes
//   0x11e00c: D101C3FF  sub      sp, sp, #0x70
//   0x11e010: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x11e014: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x11e018: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1267_0x11e00c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11e00cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x0459a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1268 | PC: 0x11e28c | FDE: 0x0459d8 | Size: 148 bytes
// Khung tháo gỡ #1268 | Địa chỉ PC: 0x11e28c | Địa chỉ FDE: 0x0459d8 | Kích thước: 148 bytes
//   0x11e28c: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x11e290: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x11e294: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x11e298: F00004E8  adrp     x8, #0x1bd000
static inline uint64_t fde_func_1268_0x11e28c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11e28cULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0459d8ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1269 | PC: 0x11e320 | FDE: 0x0459f8 | Size: 256 bytes
// Khung tháo gỡ #1269 | Địa chỉ PC: 0x11e320 | Địa chỉ FDE: 0x0459f8 | Kích thước: 256 bytes
//   0x11e320: D101C3FF  sub      sp, sp, #0x70
//   0x11e324: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x11e328: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x11e32c: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1269_0x11e320(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11e320ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x0459f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1270 | PC: 0x11e4a4 | FDE: 0x045a28 | Size: 148 bytes
// Khung tháo gỡ #1270 | Địa chỉ PC: 0x11e4a4 | Địa chỉ FDE: 0x045a28 | Kích thước: 148 bytes
//   0x11e4a4: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x11e4a8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x11e4ac: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x11e4b0: B40003C1  cbz      x1, #0x11e528
static inline uint64_t fde_func_1270_0x11e4a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11e4a4ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x045a28ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1271 | PC: 0x11e538 | FDE: 0x045a48 | Size: 232 bytes
// Khung tháo gỡ #1271 | Địa chỉ PC: 0x11e538 | Địa chỉ FDE: 0x045a48 | Kích thước: 232 bytes
//   0x11e538: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x11e53c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x11e540: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x11e544: F00004E8  adrp     x8, #0x1bd000
static inline uint64_t fde_func_1271_0x11e538(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11e538ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x045a48ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1272 | PC: 0x11e620 | FDE: 0x045a68 | Size: 36 bytes
// Khung tháo gỡ #1272 | Địa chỉ PC: 0x11e620 | Địa chỉ FDE: 0x045a68 | Kích thước: 36 bytes
//   0x11e620: F00004E8  adrp     x8, #0x1bd000
//   0x11e624: F940D908  ldr      x8, [x8, #0x1b0]
//   0x11e628: 927EB429  and      x9, x1, #0xfffffffffffc
//   0x11e62c: AA1F03E3  mov      x3, xzr
static inline uint64_t fde_func_1272_0x11e620(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11e620ULL ^ (static_cast<uint64_t>(0xf00004e8ULL) << 13);
    acc = (acc + a1 + 0xf940d908ULL) ^ 0x045a68ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1273 | PC: 0x11e644 | FDE: 0x045a80 | Size: 256 bytes
// Khung tháo gỡ #1273 | Địa chỉ PC: 0x11e644 | Địa chỉ FDE: 0x045a80 | Kích thước: 256 bytes
//   0x11e644: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x11e648: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x11e64c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x11e650: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1273_0x11e644(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11e644ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x045a80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1274 | PC: 0x11e74c | FDE: 0x045aa8 | Size: 100 bytes
// Khung tháo gỡ #1274 | Địa chỉ PC: 0x11e74c | Địa chỉ FDE: 0x045aa8 | Kích thước: 100 bytes
//   0x11e74c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x11e750: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x11e754: F00004E8  adrp     x8, #0x1bd000
//   0x11e758: F940D908  ldr      x8, [x8, #0x1b0]
static inline uint64_t fde_func_1274_0x11e74c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11e74cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x045aa8ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1275 | PC: 0x11e7b0 | FDE: 0x045ac8 | Size: 228 bytes
// Khung tháo gỡ #1275 | Địa chỉ PC: 0x11e7b0 | Địa chỉ FDE: 0x045ac8 | Kích thước: 228 bytes
//   0x11e7b0: D100C3FF  sub      sp, sp, #0x30
//   0x11e7b4: F9000BF4  str      x20, [sp, #0x10]
//   0x11e7b8: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x11e7bc: F00004E9  adrp     x9, #0x1bd000
static inline uint64_t fde_func_1275_0x11e7b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11e7b0ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x045ac8ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #1276 | PC: 0x11e894 | FDE: 0x045ae8 | Size: 48 bytes
// Khung tháo gỡ #1276 | Địa chỉ PC: 0x11e894 | Địa chỉ FDE: 0x045ae8 | Kích thước: 48 bytes
//   0x11e894: F00004E8  adrp     x8, #0x1bd000
//   0x11e898: F940D908  ldr      x8, [x8, #0x1b0]
//   0x11e89c: 927EB429  and      x9, x1, #0xfffffffffffc
//   0x11e8a0: F9400108  ldr      x8, [x8]
static inline uint64_t fde_func_1276_0x11e894(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11e894ULL ^ (static_cast<uint64_t>(0xf00004e8ULL) << 13);
    acc = (acc + a1 + 0xf940d908ULL) ^ 0x045ae8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1277 | PC: 0x11e8c4 | FDE: 0x045b00 | Size: 256 bytes
// Khung tháo gỡ #1277 | Địa chỉ PC: 0x11e8c4 | Địa chỉ FDE: 0x045b00 | Kích thước: 256 bytes
//   0x11e8c4: D101C3FF  sub      sp, sp, #0x70
//   0x11e8c8: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x11e8cc: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x11e8d0: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1277_0x11e8c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11e8c4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x045b00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1278 | PC: 0x11eb4c | FDE: 0x045b30 | Size: 152 bytes
// Khung tháo gỡ #1278 | Địa chỉ PC: 0x11eb4c | Địa chỉ FDE: 0x045b30 | Kích thước: 152 bytes
//   0x11eb4c: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x11eb50: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x11eb54: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x11eb58: F00004E8  adrp     x8, #0x1bd000
static inline uint64_t fde_func_1278_0x11eb4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11eb4cULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x045b30ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1279 | PC: 0x11ebe4 | FDE: 0x045b50 | Size: 256 bytes
// Khung tháo gỡ #1279 | Địa chỉ PC: 0x11ebe4 | Địa chỉ FDE: 0x045b50 | Kích thước: 256 bytes
//   0x11ebe4: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x11ebe8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x11ebec: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x11ebf0: F00004F6  adrp     x22, #0x1bd000
static inline uint64_t fde_func_1279_0x11ebe4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ebe4ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x045b50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1280 | PC: 0x11ed44 | FDE: 0x045b70 | Size: 44 bytes
// Khung tháo gỡ #1280 | Địa chỉ PC: 0x11ed44 | Địa chỉ FDE: 0x045b70 | Kích thước: 44 bytes
//   0x11ed44: F00004E8  adrp     x8, #0x1bd000
//   0x11ed48: F940D908  ldr      x8, [x8, #0x1b0]
//   0x11ed4c: 927EB429  and      x9, x1, #0xfffffffffffc
//   0x11ed50: F9400108  ldr      x8, [x8]
static inline uint64_t fde_func_1280_0x11ed44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ed44ULL ^ (static_cast<uint64_t>(0xf00004e8ULL) << 13);
    acc = (acc + a1 + 0xf940d908ULL) ^ 0x045b70ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1281 | PC: 0x11ed70 | FDE: 0x045b88 | Size: 252 bytes
// Khung tháo gỡ #1281 | Địa chỉ PC: 0x11ed70 | Địa chỉ FDE: 0x045b88 | Kích thước: 252 bytes
//   0x11ed70: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x11ed74: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x11ed78: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x11ed7c: F00004E8  adrp     x8, #0x1bd000
static inline uint64_t fde_func_1281_0x11ed70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ed70ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x045b88ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1282 | PC: 0x11ee6c | FDE: 0x045ba8 | Size: 256 bytes
// Khung tháo gỡ #1282 | Địa chỉ PC: 0x11ee6c | Địa chỉ FDE: 0x045ba8 | Kích thước: 256 bytes
//   0x11ee6c: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x11ee70: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x11ee74: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x11ee78: F00004F6  adrp     x22, #0x1bd000
static inline uint64_t fde_func_1282_0x11ee6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ee6cULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x045ba8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1283 | PC: 0x11f010 | FDE: 0x045bc8 | Size: 96 bytes
// Khung tháo gỡ #1283 | Địa chỉ PC: 0x11f010 | Địa chỉ FDE: 0x045bc8 | Kích thước: 96 bytes
//   0x11f010: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x11f014: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x11f018: D00004E8  adrp     x8, #0x1bd000
//   0x11f01c: F940D908  ldr      x8, [x8, #0x1b0]
static inline uint64_t fde_func_1283_0x11f010(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11f010ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x045bc8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1284 | PC: 0x11f070 | FDE: 0x045be8 | Size: 140 bytes
// Khung tháo gỡ #1284 | Địa chỉ PC: 0x11f070 | Địa chỉ FDE: 0x045be8 | Kích thước: 140 bytes
//   0x11f070: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x11f074: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x11f078: B40003C1  cbz      x1, #0x11f0f0
//   0x11f07c: D2800048  mov      x8, #2
static inline uint64_t fde_func_1284_0x11f070(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11f070ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x045be8ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1285 | PC: 0x11f0fc | FDE: 0x045c08 | Size: 52 bytes
// Khung tháo gỡ #1285 | Địa chỉ PC: 0x11f0fc | Địa chỉ FDE: 0x045c08 | Kích thước: 52 bytes
//   0x11f0fc: D00004E8  adrp     x8, #0x1bd000
//   0x11f100: F940D908  ldr      x8, [x8, #0x1b0]
//   0x11f104: 927EB429  and      x9, x1, #0xfffffffffffc
//   0x11f108: F9400108  ldr      x8, [x8]
static inline uint64_t fde_func_1285_0x11f0fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11f0fcULL ^ (static_cast<uint64_t>(0xd00004e8ULL) << 13);
    acc = (acc + a1 + 0xf940d908ULL) ^ 0x045c08ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1286 | PC: 0x11f130 | FDE: 0x045c20 | Size: 16 bytes [_Z21set_gc_info_thresholdP12malloc_statej]
// Khung tháo gỡ #1286 | Địa chỉ PC: 0x11f130 | Địa chỉ FDE: 0x045c20 | Kích thước: 16 bytes
//   0x11f130: 53047C28  lsr      w8, w1, #4
//   0x11f134: 120C1D08  and      w8, w8, #0xff00000
//   0x11f138: A90F7C08  stp      x8, xzr, [x0, #0xf0]
//   0x11f13c: D65F03C0  ret      
static inline uint64_t fde_func_1286_0x11f130(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11f130ULL ^ (static_cast<uint64_t>(0x53047c28ULL) << 13);
    acc = (acc + a1 + 0x120c1d08ULL) ^ 0x045c20ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1287 | PC: 0x11f140 | FDE: 0x045c38 | Size: 256 bytes [_Z24JS_ResetRuntimeForEffectP12LEPUSRuntimePK20LEPUSMallocFunctionsPv]
// Khung tháo gỡ #1287 | Địa chỉ PC: 0x11f140 | Địa chỉ FDE: 0x045c38 | Kích thước: 256 bytes
//   0x11f140: A9BC63FC  stp      x28, x24, [sp, #-0x40]!
//   0x11f144: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x11f148: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x11f14c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1287_0x11f140(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11f140ULL ^ (static_cast<uint64_t>(0xa9bc63fcULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x045c38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1288 | PC: 0x11f4c0 | FDE: 0x045c60 | Size: 72 bytes [LEPUS_NewRuntime]
// Khung tháo gỡ #1288 | Địa chỉ PC: 0x11f4c0 | Địa chỉ FDE: 0x045c60 | Kích thước: 72 bytes
//   0x11f4c0: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x11f4c4: 94024489  bl       #0x1b06e8
//   0x11f4c8: D00004E8  adrp     x8, #0x1bd000
//   0x11f4cc: F9410D08  ldr      x8, [x8, #0x218]
static inline uint64_t fde_func_1288_0x11f4c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11f4c0ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x94024489ULL) ^ 0x045c60ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1289 | PC: 0x11f508 | FDE: 0x045c78 | Size: 84 bytes
// Khung tháo gỡ #1289 | Địa chỉ PC: 0x11f508 | Địa chỉ FDE: 0x045c78 | Kích thước: 84 bytes
//   0x11f508: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x11f50c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x11f510: AA0103F4  mov      x20, x1
//   0x11f514: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1289_0x11f508(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11f508ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x045c78ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1290 | PC: 0x11f55c | FDE: 0x045c98 | Size: 36 bytes
// Khung tháo gỡ #1290 | Địa chỉ PC: 0x11f55c | Địa chỉ FDE: 0x045c98 | Kích thước: 36 bytes
//   0x11f55c: B4000101  cbz      x1, #0x11f57c
//   0x11f560: B0FFF868  adrp     x8, #0x2c000
//   0x11f564: 3DC00000  ldr      q0, [x0]
//   0x11f568: 3DC3ED01  ldr      q1, [x8, #0xfb0]
static inline uint64_t fde_func_1290_0x11f55c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11f55cULL ^ (static_cast<uint64_t>(0xb4000101ULL) << 13);
    acc = (acc + a1 + 0xb0fff868ULL) ^ 0x045c98ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1291 | PC: 0x11f580 | FDE: 0x045cb0 | Size: 180 bytes
// Khung tháo gỡ #1291 | Địa chỉ PC: 0x11f580 | Địa chỉ FDE: 0x045cb0 | Kích thước: 180 bytes
//   0x11f580: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x11f584: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x11f588: AA0103F5  mov      x21, x1
//   0x11f58c: AA0203E1  mov      x1, x2
static inline uint64_t fde_func_1291_0x11f580(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11f580ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x045cb0ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1292 | PC: 0x11f634 | FDE: 0x045cd0 | Size: 76 bytes [LEPUS_NewRuntimeWithMode]
// Khung tháo gỡ #1292 | Địa chỉ PC: 0x11f634 | Địa chỉ FDE: 0x045cd0 | Kích thước: 76 bytes
//   0x11f634: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x11f638: 2A0003F3  mov      w19, w0
//   0x11f63c: 9402442B  bl       #0x1b06e8
//   0x11f640: D00004E8  adrp     x8, #0x1bd000
static inline uint64_t fde_func_1292_0x11f634(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11f634ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x2a0003f3ULL) ^ 0x045cd0ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1293 | PC: 0x11f680 | FDE: 0x045ce8 | Size: 48 bytes [LEPUS_SetMemoryLimit]
// Khung tháo gỡ #1293 | Địa chỉ PC: 0x11f680 | Địa chỉ FDE: 0x045ce8 | Kích thước: 48 bytes
//   0x11f680: 394CC008  ldrb     w8, [x0, #0x330]
//   0x11f684: 34000108  cbz      w8, #0x11f6a4
//   0x11f688: F9422008  ldr      x8, [x0, #0x440]
//   0x11f68c: EB01011F  cmp      x8, x1
static inline uint64_t fde_func_1293_0x11f680(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11f680ULL ^ (static_cast<uint64_t>(0x394cc008ULL) << 13);
    acc = (acc + a1 + 0x34000108ULL) ^ 0x045ce8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1294 | PC: 0x11f6b0 | FDE: 0x045d00 | Size: 8 bytes [LEPUS_SetGCThreshold]
// Khung tháo gỡ #1294 | Địa chỉ PC: 0x11f6b0 | Địa chỉ FDE: 0x045d00 | Kích thước: 8 bytes
//   0x11f6b0: F9006401  str      x1, [x0, #0xc8]
//   0x11f6b4: D65F03C0  ret      
static inline uint64_t fde_func_1294_0x11f6b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11f6b0ULL ^ (static_cast<uint64_t>(0xf9006401ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x045d00ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1295 | PC: 0x11f6b8 | FDE: 0x045d18 | Size: 8 bytes [LEPUS_SetInterruptHandler]
// Khung tháo gỡ #1295 | Địa chỉ PC: 0x11f6b8 | Địa chỉ FDE: 0x045d18 | Kích thước: 8 bytes
//   0x11f6b8: A90F8801  stp      x1, x2, [x0, #0xf8]
//   0x11f6bc: D65F03C0  ret      
static inline uint64_t fde_func_1295_0x11f6b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11f6b8ULL ^ (static_cast<uint64_t>(0xa90f8801ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x045d18ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1296 | PC: 0x11f6c0 | FDE: 0x045d30 | Size: 8 bytes [LEPUS_SetCanBlock]
// Khung tháo gỡ #1296 | Địa chỉ PC: 0x11f6c0 | Địa chỉ FDE: 0x045d30 | Kích thước: 8 bytes
//   0x11f6c0: 3904C001  strb     w1, [x0, #0x130]
//   0x11f6c4: D65F03C0  ret      
static inline uint64_t fde_func_1296_0x11f6c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11f6c0ULL ^ (static_cast<uint64_t>(0x3904c001ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x045d30ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1297 | PC: 0x11f6c8 | FDE: 0x045d48 | Size: 256 bytes [LEPUS_EnqueueJob]
// Khung tháo gỡ #1297 | Địa chỉ PC: 0x11f6c8 | Địa chỉ FDE: 0x045d48 | Kích thước: 256 bytes
//   0x11f6c8: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x11f6cc: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x11f6d0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x11f6d4: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1297_0x11f6c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11f6c8ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x045d48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1298 | PC: 0x11f864 | FDE: 0x045d78 | Size: 20 bytes [LEPUS_IsJobPending]
// Khung tháo gỡ #1298 | Địa chỉ PC: 0x11f864 | Địa chỉ FDE: 0x045d78 | Kích thước: 20 bytes
//   0x11f864: F9408808  ldr      x8, [x0, #0x110]
//   0x11f868: 91042009  add      x9, x0, #0x108
//   0x11f86c: EB09011F  cmp      x8, x9
//   0x11f870: 1A9F07E0  cset     w0, ne
static inline uint64_t fde_func_1298_0x11f864(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11f864ULL ^ (static_cast<uint64_t>(0xf9408808ULL) << 13);
    acc = (acc + a1 + 0x91042009ULL) ^ 0x045d78ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1299 | PC: 0x11f878 | FDE: 0x045d90 | Size: 256 bytes [LEPUS_ExecutePendingJob]
// Khung tháo gỡ #1299 | Địa chỉ PC: 0x11f878 | Địa chỉ FDE: 0x045d90 | Kích thước: 256 bytes
//   0x11f878: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x11f87c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x11f880: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x11f884: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1299_0x11f878(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11f878ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x045d90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1300 | PC: 0x11fa7c | FDE: 0x045dc0 | Size: 176 bytes [LEPUS_FreeValue]
// Khung tháo gỡ #1300 | Địa chỉ PC: 0x11fa7c | Địa chỉ FDE: 0x045dc0 | Kích thước: 176 bytes
//   0x11fa7c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x11fa80: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x11fa84: 92503C28  and      x8, x1, #0xffff000000000000
//   0x11fa88: D2E00029  mov      x9, #0x1000000000000
static inline uint64_t fde_func_1300_0x11fa7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11fa7cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x045dc0ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #1301 | PC: 0x11fb2c | FDE: 0x045de0 | Size: 256 bytes [LEPUS_SetRuntimeInfo]
// Khung tháo gỡ #1301 | Địa chỉ PC: 0x11fb2c | Địa chỉ FDE: 0x045de0 | Kích thước: 256 bytes
//   0x11fb2c: B4000280  cbz      x0, #0x11fb7c
//   0x11fb30: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x11fb34: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x11fb38: A9027BF3  stp      x19, x30, [sp, #0x20]
static inline uint64_t fde_func_1301_0x11fb2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11fb2cULL ^ (static_cast<uint64_t>(0xb4000280ULL) << 13);
    acc = (acc + a1 + 0xf81d0ff6ULL) ^ 0x045de0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1302 | PC: 0x11fc8c | FDE: 0x045e00 | Size: 208 bytes [LEPUS_FreeValueRT]
// Khung tháo gỡ #1302 | Địa chỉ PC: 0x11fc8c | Địa chỉ FDE: 0x045e00 | Kích thước: 208 bytes
//   0x11fc8c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x11fc90: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x11fc94: 92503C28  and      x8, x1, #0xffff000000000000
//   0x11fc98: D2E00029  mov      x9, #0x1000000000000
static inline uint64_t fde_func_1302_0x11fc8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11fc8cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x045e00ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1303 | PC: 0x11fd5c | FDE: 0x045e20 | Size: 104 bytes [_Z22get_thread_stack_limitv]
// Khung tháo gỡ #1303 | Địa chỉ PC: 0x11fd5c | Địa chỉ FDE: 0x045e20 | Kích thước: 104 bytes
//   0x11fd5c: D101C3FF  sub      sp, sp, #0x70
//   0x11fd60: F9002BF4  str      x20, [sp, #0x50]
//   0x11fd64: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x11fd68: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_1303_0x11fd5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11fd5cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf4ULL) ^ 0x045e20ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1304 | PC: 0x11fdc4 | FDE: 0x045e40 | Size: 216 bytes
// Khung tháo gỡ #1304 | Địa chỉ PC: 0x11fdc4 | Địa chỉ FDE: 0x045e40 | Kích thước: 216 bytes
//   0x11fdc4: D10203FF  sub      sp, sp, #0x80
//   0x11fdc8: F9002BF5  str      x21, [sp, #0x50]
//   0x11fdcc: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x11fdd0: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_1304_0x11fdc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11fdc4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf5ULL) ^ 0x045e40ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1305 | PC: 0x11fe9c | FDE: 0x045e60 | Size: 256 bytes [LEPUS_NewContextRaw]
// Khung tháo gỡ #1305 | Địa chỉ PC: 0x11fe9c | Địa chỉ FDE: 0x045e60 | Kích thước: 256 bytes
//   0x11fe9c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x11fea0: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x11fea4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x11fea8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1305_0x11fe9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11fe9cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x045e60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1306 | PC: 0x120498 | FDE: 0x045e90 | Size: 256 bytes
// Khung tháo gỡ #1306 | Địa chỉ PC: 0x120498 | Địa chỉ FDE: 0x045e90 | Kích thước: 256 bytes
//   0x120498: D10283FF  sub      sp, sp, #0xa0
//   0x12049c: A9056BFB  stp      x27, x26, [sp, #0x50]
//   0x1204a0: A90663F9  stp      x25, x24, [sp, #0x60]
//   0x1204a4: A9075BF7  stp      x23, x22, [sp, #0x70]
static inline uint64_t fde_func_1306_0x120498(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x120498ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9056bfbULL) ^ 0x045e90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1307 | PC: 0x120688 | FDE: 0x045ec0 | Size: 256 bytes [LEPUS_SetPropertyFunctionList]
// Khung tháo gỡ #1307 | Địa chỉ PC: 0x120688 | Địa chỉ FDE: 0x045ec0 | Kích thước: 256 bytes
//   0x120688: D10303FF  sub      sp, sp, #0xc0
//   0x12068c: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x120690: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x120694: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_1307_0x120688(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x120688ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x045ec0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1308 | PC: 0x120bd4 | FDE: 0x045ef0 | Size: 256 bytes [LEPUS_NewAtomString]
// Khung tháo gỡ #1308 | Địa chỉ PC: 0x120bd4 | Địa chỉ FDE: 0x045ef0 | Kích thước: 256 bytes
//   0x120bd4: D10203FF  sub      sp, sp, #0x80
//   0x120bd8: F9002BF6  str      x22, [sp, #0x50]
//   0x120bdc: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x120be0: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_1308_0x120bd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x120bd4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf6ULL) ^ 0x045ef0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1309 | PC: 0x120d20 | FDE: 0x045f10 | Size: 204 bytes
// Khung tháo gỡ #1309 | Địa chỉ PC: 0x120d20 | Địa chỉ FDE: 0x045f10 | Kích thước: 204 bytes
//   0x120d20: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x120d24: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x120d28: 39402468  ldrb     w8, [x3, #9]
//   0x120d2c: AA0303F4  mov      x20, x3
static inline uint64_t fde_func_1309_0x120d20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x120d20ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x045f10ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1310 | PC: 0x120dec | FDE: 0x045f30 | Size: 256 bytes [LEPUS_DefinePropertyGetSet]
// Khung tháo gỡ #1310 | Địa chỉ PC: 0x120dec | Địa chỉ FDE: 0x045f30 | Kích thước: 256 bytes
//   0x120dec: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x120df0: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x120df4: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x120df8: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1310_0x120dec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x120decULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x045f30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1311 | PC: 0x120f78 | FDE: 0x045f58 | Size: 256 bytes
// Khung tháo gỡ #1311 | Địa chỉ PC: 0x120f78 | Địa chỉ FDE: 0x045f58 | Kích thước: 256 bytes
//   0x120f78: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x120f7c: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x120f80: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x120f84: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1311_0x120f78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x120f78ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x045f58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1312 | PC: 0x121398 | FDE: 0x045f80 | Size: 256 bytes [LEPUS_NewContext]
// Khung tháo gỡ #1312 | Địa chỉ PC: 0x121398 | Địa chỉ FDE: 0x045f80 | Kích thước: 256 bytes
//   0x121398: D10383FF  sub      sp, sp, #0xe0
//   0x12139c: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x1213a0: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x1213a4: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_1312_0x121398(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x121398ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x045f80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1313 | PC: 0x123d50 | FDE: 0x045fb0 | Size: 256 bytes
// Khung tháo gỡ #1313 | Địa chỉ PC: 0x123d50 | Địa chỉ FDE: 0x045fb0 | Kích thước: 256 bytes
//   0x123d50: D10503FF  sub      sp, sp, #0x140
//   0x123d54: A90E6FFC  stp      x28, x27, [sp, #0xe0]
//   0x123d58: A90F67FA  stp      x26, x25, [sp, #0xf0]
//   0x123d5c: A9105FF8  stp      x24, x23, [sp, #0x100]
static inline uint64_t fde_func_1313_0x123d50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x123d50ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xa90e6ffcULL) ^ 0x045fb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1314 | PC: 0x124824 | FDE: 0x045fe0 | Size: 164 bytes
// Khung tháo gỡ #1314 | Địa chỉ PC: 0x124824 | Địa chỉ FDE: 0x045fe0 | Kích thước: 164 bytes
//   0x124824: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x124828: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x12482c: B00004C8  adrp     x8, #0x1bd000
//   0x124830: F940D908  ldr      x8, [x8, #0x1b0]
static inline uint64_t fde_func_1314_0x124824(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x124824ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x045fe0ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1315 | PC: 0x1248c8 | FDE: 0x046000 | Size: 256 bytes
// Khung tháo gỡ #1315 | Địa chỉ PC: 0x1248c8 | Địa chỉ FDE: 0x046000 | Kích thước: 256 bytes
//   0x1248c8: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x1248cc: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1248d0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1248d4: 7100045F  cmp      w2, #1
static inline uint64_t fde_func_1315_0x1248c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1248c8ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x046000ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1316 | PC: 0x124ac4 | FDE: 0x046020 | Size: 256 bytes
// Khung tháo gỡ #1316 | Địa chỉ PC: 0x124ac4 | Địa chỉ FDE: 0x046020 | Kích thước: 256 bytes
//   0x124ac4: F81B0FFA  str      x26, [sp, #-0x50]!
//   0x124ac8: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x124acc: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x124ad0: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1316_0x124ac4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x124ac4ULL ^ (static_cast<uint64_t>(0xf81b0ffaULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x046020ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1317 | PC: 0x124ce4 | FDE: 0x046048 | Size: 256 bytes
// Khung tháo gỡ #1317 | Địa chỉ PC: 0x124ce4 | Địa chỉ FDE: 0x046048 | Kích thước: 256 bytes
//   0x124ce4: D101C3FF  sub      sp, sp, #0x70
//   0x124ce8: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x124cec: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x124cf0: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1317_0x124ce4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x124ce4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x046048ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1318 | PC: 0x125018 | FDE: 0x046078 | Size: 236 bytes
// Khung tháo gỡ #1318 | Địa chỉ PC: 0x125018 | Địa chỉ FDE: 0x046078 | Kích thước: 236 bytes
//   0x125018: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x12501c: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x125020: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x125024: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1318_0x125018(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x125018ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x046078ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #1319 | PC: 0x125104 | FDE: 0x0460a0 | Size: 256 bytes
// Khung tháo gỡ #1319 | Địa chỉ PC: 0x125104 | Địa chỉ FDE: 0x0460a0 | Kích thước: 256 bytes
//   0x125104: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x125108: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x12510c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x125110: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1319_0x125104(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x125104ULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0460a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1320 | PC: 0x125354 | FDE: 0x0460c8 | Size: 256 bytes
// Khung tháo gỡ #1320 | Địa chỉ PC: 0x125354 | Địa chỉ FDE: 0x0460c8 | Kích thước: 256 bytes
//   0x125354: F81B0FFA  str      x26, [sp, #-0x50]!
//   0x125358: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x12535c: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x125360: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1320_0x125354(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x125354ULL ^ (static_cast<uint64_t>(0xf81b0ffaULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x0460c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1321 | PC: 0x1256e4 | FDE: 0x0460f0 | Size: 256 bytes
// Khung tháo gỡ #1321 | Địa chỉ PC: 0x1256e4 | Địa chỉ FDE: 0x0460f0 | Kích thước: 256 bytes
//   0x1256e4: D10183FF  sub      sp, sp, #0x60
//   0x1256e8: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x1256ec: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x1256f0: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_1321_0x1256e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1256e4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x0460f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1322 | PC: 0x125c18 | FDE: 0x046118 | Size: 256 bytes [LEPUS_ToIndex]
// Khung tháo gỡ #1322 | Địa chỉ PC: 0x125c18 | Địa chỉ FDE: 0x046118 | Kích thước: 256 bytes
//   0x125c18: D100C3FF  sub      sp, sp, #0x30
//   0x125c1c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x125c20: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x125c24: 39458008  ldrb     w8, [x0, #0x160]
static inline uint64_t fde_func_1322_0x125c18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x125c18ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x046118ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1323 | PC: 0x125d24 | FDE: 0x046138 | Size: 256 bytes
// Khung tháo gỡ #1323 | Địa chỉ PC: 0x125d24 | Địa chỉ FDE: 0x046138 | Kích thước: 256 bytes
//   0x125d24: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x125d28: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x125d2c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x125d30: AA0303F5  mov      x21, x3
static inline uint64_t fde_func_1323_0x125d24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x125d24ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x046138ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1324 | PC: 0x125ebc | FDE: 0x046158 | Size: 4 bytes
// Khung tháo gỡ #1324 | Địa chỉ PC: 0x125ebc | Địa chỉ FDE: 0x046158 | Kích thước: 4 bytes
//   0x125ebc: 14000001  b        #0x125ec0
static inline uint64_t fde_func_1324_0x125ebc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x125ebcULL ^ (static_cast<uint64_t>(0x14000001ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bf3ULL) ^ 0x046158ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1325 | PC: 0x125ec0 | FDE: 0x046170 | Size: 256 bytes
// Khung tháo gỡ #1325 | Địa chỉ PC: 0x125ec0 | Địa chỉ FDE: 0x046170 | Kích thước: 256 bytes
//   0x125ec0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x125ec4: D371FC28  lsr      x8, x1, #0x31
//   0x125ec8: F100011F  cmp      x8, #0
//   0x125ecc: 1A9F07E9  cset     w9, ne
static inline uint64_t fde_func_1325_0x125ec0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x125ec0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xd371fc28ULL) ^ 0x046170ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1326 | PC: 0x1260c8 | FDE: 0x046188 | Size: 212 bytes
// Khung tháo gỡ #1326 | Địa chỉ PC: 0x1260c8 | Địa chỉ FDE: 0x046188 | Kích thước: 212 bytes
//   0x1260c8: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1260cc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1260d0: 92503C28  and      x8, x1, #0xffff000000000000
//   0x1260d4: D2E00029  mov      x9, #0x1000000000000
static inline uint64_t fde_func_1326_0x1260c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1260c8ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x046188ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1327 | PC: 0x12619c | FDE: 0x0461a8 | Size: 256 bytes
// Khung tháo gỡ #1327 | Địa chỉ PC: 0x12619c | Địa chỉ FDE: 0x0461a8 | Kích thước: 256 bytes
//   0x12619c: F81B0FFA  str      x26, [sp, #-0x50]!
//   0x1261a0: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x1261a4: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x1261a8: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1327_0x12619c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12619cULL ^ (static_cast<uint64_t>(0xf81b0ffaULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x0461a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1328 | PC: 0x126310 | FDE: 0x0461d0 | Size: 256 bytes
// Khung tháo gỡ #1328 | Địa chỉ PC: 0x126310 | Địa chỉ FDE: 0x0461d0 | Kích thước: 256 bytes
//   0x126310: F81A0FFC  str      x28, [sp, #-0x60]!
//   0x126314: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x126318: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x12631c: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_1328_0x126310(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x126310ULL ^ (static_cast<uint64_t>(0xf81a0ffcULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x0461d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1329 | PC: 0x1265d4 | FDE: 0x046200 | Size: 256 bytes
// Khung tháo gỡ #1329 | Địa chỉ PC: 0x1265d4 | Địa chỉ FDE: 0x046200 | Kích thước: 256 bytes
//   0x1265d4: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x1265d8: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x1265dc: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x1265e0: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1329_0x1265d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1265d4ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x046200ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1330 | PC: 0x126850 | FDE: 0x046230 | Size: 256 bytes
// Khung tháo gỡ #1330 | Địa chỉ PC: 0x126850 | Địa chỉ FDE: 0x046230 | Kích thước: 256 bytes
//   0x126850: F81A0FFC  str      x28, [sp, #-0x60]!
//   0x126854: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x126858: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x12685c: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_1330_0x126850(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x126850ULL ^ (static_cast<uint64_t>(0xf81a0ffcULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x046230ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1331 | PC: 0x126b24 | FDE: 0x046260 | Size: 208 bytes
// Khung tháo gỡ #1331 | Địa chỉ PC: 0x126b24 | Địa chỉ FDE: 0x046260 | Kích thước: 208 bytes
//   0x126b24: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x126b28: B4000581  cbz      x1, #0x126bd8
//   0x126b2c: D2800048  mov      x8, #2
//   0x126b30: F2FFFFE8  movk     x8, #0xffff, lsl #48
static inline uint64_t fde_func_1331_0x126b24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x126b24ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xb4000581ULL) ^ 0x046260ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1332 | PC: 0x126bf4 | FDE: 0x046278 | Size: 256 bytes
// Khung tháo gỡ #1332 | Địa chỉ PC: 0x126bf4 | Địa chỉ FDE: 0x046278 | Kích thước: 256 bytes
//   0x126bf4: D101C3FF  sub      sp, sp, #0x70
//   0x126bf8: A9026BFB  stp      x27, x26, [sp, #0x20]
//   0x126bfc: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x126c00: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_1332_0x126bf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x126bf4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9026bfbULL) ^ 0x046278ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1333 | PC: 0x127014 | FDE: 0x0462a0 | Size: 256 bytes
// Khung tháo gỡ #1333 | Địa chỉ PC: 0x127014 | Địa chỉ FDE: 0x0462a0 | Kích thước: 256 bytes
//   0x127014: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x127018: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x12701c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x127020: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1333_0x127014(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x127014ULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0462a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1334 | PC: 0x1271fc | FDE: 0x0462c8 | Size: 256 bytes
// Khung tháo gỡ #1334 | Địa chỉ PC: 0x1271fc | Địa chỉ FDE: 0x0462c8 | Kích thước: 256 bytes
//   0x1271fc: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x127200: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x127204: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x127208: D00004A8  adrp     x8, #0x1bd000
static inline uint64_t fde_func_1334_0x1271fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1271fcULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0462c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1335 | PC: 0x12730c | FDE: 0x0462e8 | Size: 256 bytes
// Khung tháo gỡ #1335 | Địa chỉ PC: 0x12730c | Địa chỉ FDE: 0x0462e8 | Kích thước: 256 bytes
//   0x12730c: D10283FF  sub      sp, sp, #0xa0
//   0x127310: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x127314: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x127318: A90757F6  stp      x22, x21, [sp, #0x70]
static inline uint64_t fde_func_1335_0x12730c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12730cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa90567faULL) ^ 0x0462e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1336 | PC: 0x12761c | FDE: 0x046318 | Size: 256 bytes
// Khung tháo gỡ #1336 | Địa chỉ PC: 0x12761c | Địa chỉ FDE: 0x046318 | Kích thước: 256 bytes
//   0x12761c: D10243FF  sub      sp, sp, #0x90
//   0x127620: F9001BFC  str      x28, [sp, #0x30]
//   0x127624: A9046BFB  stp      x27, x26, [sp, #0x40]
//   0x127628: A90563F9  stp      x25, x24, [sp, #0x50]
static inline uint64_t fde_func_1336_0x12761c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12761cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9001bfcULL) ^ 0x046318ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1337 | PC: 0x127edc | FDE: 0x046348 | Size: 256 bytes
// Khung tháo gỡ #1337 | Địa chỉ PC: 0x127edc | Địa chỉ FDE: 0x046348 | Kích thước: 256 bytes
//   0x127edc: D101C3FF  sub      sp, sp, #0x70
//   0x127ee0: F90013FA  str      x26, [sp, #0x20]
//   0x127ee4: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x127ee8: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_1337_0x127edc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x127edcULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013faULL) ^ 0x046348ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1338 | PC: 0x128578 | FDE: 0x046370 | Size: 256 bytes
// Khung tháo gỡ #1338 | Địa chỉ PC: 0x128578 | Địa chỉ FDE: 0x046370 | Kích thước: 256 bytes
//   0x128578: D10383FF  sub      sp, sp, #0xe0
//   0x12857c: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x128580: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x128584: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_1338_0x128578(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x128578ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x046370ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1339 | PC: 0x129778 | FDE: 0x0463a0 | Size: 256 bytes
// Khung tháo gỡ #1339 | Địa chỉ PC: 0x129778 | Địa chỉ FDE: 0x0463a0 | Kích thước: 256 bytes
//   0x129778: D10183FF  sub      sp, sp, #0x60
//   0x12977c: F9000BFA  str      x26, [sp, #0x10]
//   0x129780: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x129784: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_1339_0x129778(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129778ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfaULL) ^ 0x0463a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1340 | PC: 0x129c00 | FDE: 0x0463c8 | Size: 256 bytes
// Khung tháo gỡ #1340 | Địa chỉ PC: 0x129c00 | Địa chỉ FDE: 0x0463c8 | Kích thước: 256 bytes
//   0x129c00: D10203FF  sub      sp, sp, #0x80
//   0x129c04: F90013FC  str      x28, [sp, #0x20]
//   0x129c08: A9036BFB  stp      x27, x26, [sp, #0x30]
//   0x129c0c: A90463F9  stp      x25, x24, [sp, #0x40]
static inline uint64_t fde_func_1340_0x129c00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129c00ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fcULL) ^ 0x0463c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1341 | PC: 0x12a178 | FDE: 0x0463f8 | Size: 256 bytes
// Khung tháo gỡ #1341 | Địa chỉ PC: 0x12a178 | Địa chỉ FDE: 0x0463f8 | Kích thước: 256 bytes
//   0x12a178: D10143FF  sub      sp, sp, #0x50
//   0x12a17c: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x12a180: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x12a184: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1341_0x12a178(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12a178ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x0463f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1342 | PC: 0x12a610 | FDE: 0x046420 | Size: 256 bytes
// Khung tháo gỡ #1342 | Địa chỉ PC: 0x12a610 | Địa chỉ FDE: 0x046420 | Kích thước: 256 bytes
//   0x12a610: D10303FF  sub      sp, sp, #0xc0
//   0x12a614: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x12a618: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x12a61c: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_1342_0x12a610(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12a610ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x046420ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1343 | PC: 0x12ab48 | FDE: 0x046450 | Size: 256 bytes
// Khung tháo gỡ #1343 | Địa chỉ PC: 0x12ab48 | Địa chỉ FDE: 0x046450 | Kích thước: 256 bytes
//   0x12ab48: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x12ab4c: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x12ab50: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x12ab54: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1343_0x12ab48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12ab48ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x046450ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1344 | PC: 0x12ad70 | FDE: 0x046478 | Size: 256 bytes [_Z18JS_StructuredCloneP12LEPUSContext10LEPUSValueR16ObjectCloneState]
// Khung tháo gỡ #1344 | Địa chỉ PC: 0x12ad70 | Địa chỉ FDE: 0x046478 | Kích thước: 256 bytes
//   0x12ad70: D10443FF  sub      sp, sp, #0x110
//   0x12ad74: A90B6FFC  stp      x28, x27, [sp, #0xb0]
//   0x12ad78: A90C67FA  stp      x26, x25, [sp, #0xc0]
//   0x12ad7c: A90D5FF8  stp      x24, x23, [sp, #0xd0]
static inline uint64_t fde_func_1344_0x12ad70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12ad70ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90b6ffcULL) ^ 0x046478ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1345 | PC: 0x12c920 | FDE: 0x0464a8 | Size: 256 bytes
// Khung tháo gỡ #1345 | Địa chỉ PC: 0x12c920 | Địa chỉ FDE: 0x0464a8 | Kích thước: 256 bytes
//   0x12c920: D101C3FF  sub      sp, sp, #0x70
//   0x12c924: F90013FA  str      x26, [sp, #0x20]
//   0x12c928: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x12c92c: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_1345_0x12c920(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12c920ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013faULL) ^ 0x0464a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1346 | PC: 0x12cc68 | FDE: 0x0464d0 | Size: 256 bytes
// Khung tháo gỡ #1346 | Địa chỉ PC: 0x12cc68 | Địa chỉ FDE: 0x0464d0 | Kích thước: 256 bytes
//   0x12cc68: D10143FF  sub      sp, sp, #0x50
//   0x12cc6c: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x12cc70: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x12cc74: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1346_0x12cc68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12cc68ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9025bf7ULL) ^ 0x0464d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1347 | PC: 0x12cdc0 | FDE: 0x0464f0 | Size: 256 bytes [LEPUS_SetPropertyInt64]
// Khung tháo gỡ #1347 | Địa chỉ PC: 0x12cdc0 | Địa chỉ FDE: 0x0464f0 | Kích thước: 256 bytes
//   0x12cdc0: D10183FF  sub      sp, sp, #0x60
//   0x12cdc4: F90013F8  str      x24, [sp, #0x20]
//   0x12cdc8: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x12cdcc: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_1347_0x12cdc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12cdc0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f8ULL) ^ 0x0464f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1348 | PC: 0x12cfa4 | FDE: 0x046518 | Size: 256 bytes
// Khung tháo gỡ #1348 | Địa chỉ PC: 0x12cfa4 | Địa chỉ FDE: 0x046518 | Kích thước: 256 bytes
//   0x12cfa4: F81B0FFA  str      x26, [sp, #-0x50]!
//   0x12cfa8: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x12cfac: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x12cfb0: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1348_0x12cfa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12cfa4ULL ^ (static_cast<uint64_t>(0xf81b0ffaULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x046518ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1349 | PC: 0x12d308 | FDE: 0x046540 | Size: 16 bytes
// Khung tháo gỡ #1349 | Địa chỉ PC: 0x12d308 | Địa chỉ FDE: 0x046540 | Kích thước: 16 bytes
//   0x12d308: F9400403  ldr      x3, [x0, #8]
//   0x12d30c: 910D2000  add      x0, x0, #0x348
//   0x12d310: AA0203E1  mov      x1, x2
//   0x12d314: D61F0060  br       x3
static inline uint64_t fde_func_1349_0x12d308(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12d308ULL ^ (static_cast<uint64_t>(0xf9400403ULL) << 13);
    acc = (acc + a1 + 0x910d2000ULL) ^ 0x046540ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1350 | PC: 0x12d318 | FDE: 0x046558 | Size: 256 bytes [LEPUS_WriteObject]
// Khung tháo gỡ #1350 | Địa chỉ PC: 0x12d318 | Địa chỉ FDE: 0x046558 | Kích thước: 256 bytes
//   0x12d318: D10503FF  sub      sp, sp, #0x140
//   0x12d31c: A90E6FFC  stp      x28, x27, [sp, #0xe0]
//   0x12d320: A90F67FA  stp      x26, x25, [sp, #0xf0]
//   0x12d324: A9105FF8  stp      x24, x23, [sp, #0x100]
static inline uint64_t fde_func_1350_0x12d318(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12d318ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xa90e6ffcULL) ^ 0x046558ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1351 | PC: 0x12dc6c | FDE: 0x046588 | Size: 256 bytes [LEPUS_ReadObject]
// Khung tháo gỡ #1351 | Địa chỉ PC: 0x12dc6c | Địa chỉ FDE: 0x046588 | Kích thước: 256 bytes
//   0x12dc6c: D10283FF  sub      sp, sp, #0xa0
//   0x12dc70: A9056BFB  stp      x27, x26, [sp, #0x50]
//   0x12dc74: A90663F9  stp      x25, x24, [sp, #0x60]
//   0x12dc78: A9075BF7  stp      x23, x22, [sp, #0x70]
static inline uint64_t fde_func_1351_0x12dc6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12dc6cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9056bfbULL) ^ 0x046588ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1352 | PC: 0x12e038 | FDE: 0x0465b8 | Size: 256 bytes
// Khung tháo gỡ #1352 | Địa chỉ PC: 0x12e038 | Địa chỉ FDE: 0x0465b8 | Kích thước: 256 bytes
//   0x12e038: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x12e03c: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x12e040: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x12e044: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1352_0x12e038(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12e038ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0465b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1353 | PC: 0x12e2d8 | FDE: 0x0465e0 | Size: 256 bytes
// Khung tháo gỡ #1353 | Địa chỉ PC: 0x12e2d8 | Địa chỉ FDE: 0x0465e0 | Kích thước: 256 bytes
//   0x12e2d8: D105C3FF  sub      sp, sp, #0x170
//   0x12e2dc: A9116FFC  stp      x28, x27, [sp, #0x110]
//   0x12e2e0: A91267FA  stp      x26, x25, [sp, #0x120]
//   0x12e2e4: A9135FF8  stp      x24, x23, [sp, #0x130]
static inline uint64_t fde_func_1353_0x12e2d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12e2d8ULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xa9116ffcULL) ^ 0x0465e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1354 | PC: 0x13106c | FDE: 0x046610 | Size: 212 bytes
// Khung tháo gỡ #1354 | Địa chỉ PC: 0x13106c | Địa chỉ FDE: 0x046610 | Kích thước: 212 bytes
//   0x13106c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x131070: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x131074: F9400808  ldr      x8, [x0, #0x10]
//   0x131078: 2A0103F4  mov      w20, w1
static inline uint64_t fde_func_1354_0x13106c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13106cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x046610ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1355 | PC: 0x131140 | FDE: 0x046630 | Size: 256 bytes [LEPUS_DefinePropertyValueUint32]
// Khung tháo gỡ #1355 | Địa chỉ PC: 0x131140 | Địa chỉ FDE: 0x046630 | Kích thước: 256 bytes
//   0x131140: F81B0FFA  str      x26, [sp, #-0x50]!
//   0x131144: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x131148: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x13114c: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1355_0x131140(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131140ULL ^ (static_cast<uint64_t>(0xf81b0ffaULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x046630ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1356 | PC: 0x1313b4 | FDE: 0x046658 | Size: 256 bytes
// Khung tháo gỡ #1356 | Địa chỉ PC: 0x1313b4 | Địa chỉ FDE: 0x046658 | Kích thước: 256 bytes
//   0x1313b4: D10183FF  sub      sp, sp, #0x60
//   0x1313b8: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x1313bc: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x1313c0: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_1356_0x1313b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1313b4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x046658ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1357 | PC: 0x13166c | FDE: 0x046680 | Size: 256 bytes [LEPUS_PreventExtensions]
// Khung tháo gỡ #1357 | Địa chỉ PC: 0x13166c | Địa chỉ FDE: 0x046680 | Kích thước: 256 bytes
//   0x13166c: D10103FF  sub      sp, sp, #0x40
//   0x131670: F9000BF6  str      x22, [sp, #0x10]
//   0x131674: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x131678: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1357_0x13166c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13166cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x046680ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1358 | PC: 0x131920 | FDE: 0x0466a0 | Size: 256 bytes
// Khung tháo gỡ #1358 | Địa chỉ PC: 0x131920 | Địa chỉ FDE: 0x0466a0 | Kích thước: 256 bytes
//   0x131920: D10283FF  sub      sp, sp, #0xa0
//   0x131924: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x131928: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x13192c: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1358_0x131920(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131920ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x0466a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1359 | PC: 0x135cf0 | FDE: 0x0466d0 | Size: 256 bytes
// Khung tháo gỡ #1359 | Địa chỉ PC: 0x135cf0 | Địa chỉ FDE: 0x0466d0 | Kích thước: 256 bytes
//   0x135cf0: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x135cf4: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x135cf8: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x135cfc: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1359_0x135cf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x135cf0ULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0466d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1360 | PC: 0x135f30 | FDE: 0x0466f8 | Size: 256 bytes [LEPUS_ToInt64]
// Khung tháo gỡ #1360 | Địa chỉ PC: 0x135f30 | Địa chỉ FDE: 0x0466f8 | Kích thước: 256 bytes
//   0x135f30: A9BB6BFB  stp      x27, x26, [sp, #-0x50]!
//   0x135f34: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x135f38: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x135f3c: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1360_0x135f30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x135f30ULL ^ (static_cast<uint64_t>(0xa9bb6bfbULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x0466f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1361 | PC: 0x136144 | FDE: 0x046720 | Size: 256 bytes
// Khung tháo gỡ #1361 | Địa chỉ PC: 0x136144 | Địa chỉ FDE: 0x046720 | Kích thước: 256 bytes
//   0x136144: D10283FF  sub      sp, sp, #0xa0
//   0x136148: A9056BFB  stp      x27, x26, [sp, #0x50]
//   0x13614c: A90663F9  stp      x25, x24, [sp, #0x60]
//   0x136150: A9075BF7  stp      x23, x22, [sp, #0x70]
static inline uint64_t fde_func_1361_0x136144(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x136144ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9056bfbULL) ^ 0x046720ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1362 | PC: 0x136da8 | FDE: 0x046750 | Size: 256 bytes
// Khung tháo gỡ #1362 | Địa chỉ PC: 0x136da8 | Địa chỉ FDE: 0x046750 | Kích thước: 256 bytes
//   0x136da8: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x136dac: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x136db0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x136db4: F94000B3  ldr      x19, [x5]
static inline uint64_t fde_func_1362_0x136da8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x136da8ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x046750ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1363 | PC: 0x136ef0 | FDE: 0x046770 | Size: 140 bytes
// Khung tháo gỡ #1363 | Địa chỉ PC: 0x136ef0 | Địa chỉ FDE: 0x046770 | Kích thước: 140 bytes
//   0x136ef0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x136ef4: 92503C28  and      x8, x1, #0xffff000000000000
//   0x136ef8: D2E00029  mov      x9, #0x1000000000000
//   0x136efc: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1363_0x136ef0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x136ef0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x92503c28ULL) ^ 0x046770ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1364 | PC: 0x136f7c | FDE: 0x046788 | Size: 256 bytes
// Khung tháo gỡ #1364 | Địa chỉ PC: 0x136f7c | Địa chỉ FDE: 0x046788 | Kích thước: 256 bytes
//   0x136f7c: D10443FF  sub      sp, sp, #0x110
//   0x136f80: A90B6FFC  stp      x28, x27, [sp, #0xb0]
//   0x136f84: A90C67FA  stp      x26, x25, [sp, #0xc0]
//   0x136f88: A90D5FF8  stp      x24, x23, [sp, #0xd0]
static inline uint64_t fde_func_1364_0x136f7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x136f7cULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90b6ffcULL) ^ 0x046788ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1365 | PC: 0x138354 | FDE: 0x0467b8 | Size: 256 bytes
// Khung tháo gỡ #1365 | Địa chỉ PC: 0x138354 | Địa chỉ FDE: 0x0467b8 | Kích thước: 256 bytes
//   0x138354: D10243FF  sub      sp, sp, #0x90
//   0x138358: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x13835c: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x138360: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1365_0x138354(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x138354ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x0467b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1366 | PC: 0x138bfc | FDE: 0x0467e8 | Size: 256 bytes [LEPUS_Invoke]
// Khung tháo gỡ #1366 | Địa chỉ PC: 0x138bfc | Địa chỉ FDE: 0x0467e8 | Kích thước: 256 bytes
//   0x138bfc: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x138c00: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x138c04: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x138c08: 39458008  ldrb     w8, [x0, #0x160]
static inline uint64_t fde_func_1366_0x138bfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x138bfcULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0467e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1367 | PC: 0x138da4 | FDE: 0x046808 | Size: 256 bytes
// Khung tháo gỡ #1367 | Địa chỉ PC: 0x138da4 | Địa chỉ FDE: 0x046808 | Kích thước: 256 bytes
//   0x138da4: D10203FF  sub      sp, sp, #0x80
//   0x138da8: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x138dac: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x138db0: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1367_0x138da4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x138da4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x046808ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1368 | PC: 0x1397e8 | FDE: 0x046838 | Size: 256 bytes
// Khung tháo gỡ #1368 | Địa chỉ PC: 0x1397e8 | Địa chỉ FDE: 0x046838 | Kích thước: 256 bytes
//   0x1397e8: A9BB6BFB  stp      x27, x26, [sp, #-0x50]!
//   0x1397ec: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x1397f0: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x1397f4: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1368_0x1397e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1397e8ULL ^ (static_cast<uint64_t>(0xa9bb6bfbULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x046838ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1369 | PC: 0x13998c | FDE: 0x046860 | Size: 256 bytes
// Khung tháo gỡ #1369 | Địa chỉ PC: 0x13998c | Địa chỉ FDE: 0x046860 | Kích thước: 256 bytes
//   0x13998c: D10283FF  sub      sp, sp, #0xa0
//   0x139990: A9056BFB  stp      x27, x26, [sp, #0x50]
//   0x139994: A90663F9  stp      x25, x24, [sp, #0x60]
//   0x139998: A9075BF7  stp      x23, x22, [sp, #0x70]
static inline uint64_t fde_func_1369_0x13998c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13998cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9056bfbULL) ^ 0x046860ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1370 | PC: 0x139cb8 | FDE: 0x046890 | Size: 80 bytes
// Khung tháo gỡ #1370 | Địa chỉ PC: 0x139cb8 | Địa chỉ FDE: 0x046890 | Kích thước: 80 bytes
//   0x139cb8: D100C3FF  sub      sp, sp, #0x30
//   0x139cbc: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x139cc0: D53BD053  mrs      x19, tpidr_el0
//   0x139cc4: F9401668  ldr      x8, [x19, #0x28]
static inline uint64_t fde_func_1370_0x139cb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x139cb8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9027bf3ULL) ^ 0x046890ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1371 | PC: 0x139d08 | FDE: 0x0468a8 | Size: 256 bytes
// Khung tháo gỡ #1371 | Địa chỉ PC: 0x139d08 | Địa chỉ FDE: 0x0468a8 | Kích thước: 256 bytes
//   0x139d08: D10203FF  sub      sp, sp, #0x80
//   0x139d0c: A9036BFB  stp      x27, x26, [sp, #0x30]
//   0x139d10: A90463F9  stp      x25, x24, [sp, #0x40]
//   0x139d14: A9055BF7  stp      x23, x22, [sp, #0x50]
static inline uint64_t fde_func_1371_0x139d08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x139d08ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9036bfbULL) ^ 0x0468a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1372 | PC: 0x13a1d0 | FDE: 0x0468d8 | Size: 256 bytes
// Khung tháo gỡ #1372 | Địa chỉ PC: 0x13a1d0 | Địa chỉ FDE: 0x0468d8 | Kích thước: 256 bytes
//   0x13a1d0: D101C3FF  sub      sp, sp, #0x70
//   0x13a1d4: F90013FA  str      x26, [sp, #0x20]
//   0x13a1d8: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x13a1dc: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_1372_0x13a1d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13a1d0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013faULL) ^ 0x0468d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1373 | PC: 0x13a54c | FDE: 0x046900 | Size: 140 bytes
// Khung tháo gỡ #1373 | Địa chỉ PC: 0x13a54c | Địa chỉ FDE: 0x046900 | Kích thước: 140 bytes
//   0x13a54c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x13a550: F94000B3  ldr      x19, [x5]
//   0x13a554: D2E00029  mov      x9, #0x1000000000000
//   0x13a558: 92503E68  and      x8, x19, #0xffff000000000000
static inline uint64_t fde_func_1373_0x13a54c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13a54cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf94000b3ULL) ^ 0x046900ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1374 | PC: 0x13a5d8 | FDE: 0x046918 | Size: 168 bytes
// Khung tháo gỡ #1374 | Địa chỉ PC: 0x13a5d8 | Địa chỉ FDE: 0x046918 | Kích thước: 168 bytes
//   0x13a5d8: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x13a5dc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x13a5e0: F94000B3  ldr      x19, [x5]
//   0x13a5e4: D2E00029  mov      x9, #0x1000000000000
static inline uint64_t fde_func_1374_0x13a5d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13a5d8ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x046918ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1375 | PC: 0x13a680 | FDE: 0x046938 | Size: 256 bytes
// Khung tháo gỡ #1375 | Địa chỉ PC: 0x13a680 | Địa chỉ FDE: 0x046938 | Kích thước: 256 bytes
//   0x13a680: D101C3FF  sub      sp, sp, #0x70
//   0x13a684: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x13a688: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x13a68c: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1375_0x13a680(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13a680ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x046938ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1376 | PC: 0x13a9bc | FDE: 0x046968 | Size: 256 bytes
// Khung tháo gỡ #1376 | Địa chỉ PC: 0x13a9bc | Địa chỉ FDE: 0x046968 | Kích thước: 256 bytes
//   0x13a9bc: D10303FF  sub      sp, sp, #0xc0
//   0x13a9c0: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x13a9c4: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x13a9c8: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_1376_0x13a9bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13a9bcULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x046968ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1377 | PC: 0x13b2fc | FDE: 0x046998 | Size: 256 bytes
// Khung tháo gỡ #1377 | Địa chỉ PC: 0x13b2fc | Địa chỉ FDE: 0x046998 | Kích thước: 256 bytes
//   0x13b2fc: D100C3FF  sub      sp, sp, #0x30
//   0x13b300: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x13b304: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x13b308: B9400028  ldr      w8, [x1]
static inline uint64_t fde_func_1377_0x13b2fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13b2fcULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x046998ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1378 | PC: 0x13b4bc | FDE: 0x0469b8 | Size: 256 bytes
// Khung tháo gỡ #1378 | Địa chỉ PC: 0x13b4bc | Địa chỉ FDE: 0x0469b8 | Kích thước: 256 bytes
//   0x13b4bc: D10283FF  sub      sp, sp, #0xa0
//   0x13b4c0: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x13b4c4: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x13b4c8: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1378_0x13b4bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13b4bcULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x0469b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1379 | PC: 0x13ba88 | FDE: 0x0469e8 | Size: 256 bytes
// Khung tháo gỡ #1379 | Địa chỉ PC: 0x13ba88 | Địa chỉ FDE: 0x0469e8 | Kích thước: 256 bytes
//   0x13ba88: D10183FF  sub      sp, sp, #0x60
//   0x13ba8c: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x13ba90: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x13ba94: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_1379_0x13ba88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13ba88ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90263f9ULL) ^ 0x0469e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1380 | PC: 0x13bd8c | FDE: 0x046a10 | Size: 256 bytes
// Khung tháo gỡ #1380 | Địa chỉ PC: 0x13bd8c | Địa chỉ FDE: 0x046a10 | Kích thước: 256 bytes
//   0x13bd8c: D10303FF  sub      sp, sp, #0xc0
//   0x13bd90: F90033FC  str      x28, [sp, #0x60]
//   0x13bd94: A9076BFB  stp      x27, x26, [sp, #0x70]
//   0x13bd98: A90863F9  stp      x25, x24, [sp, #0x80]
static inline uint64_t fde_func_1380_0x13bd8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13bd8cULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf90033fcULL) ^ 0x046a10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1381 | PC: 0x13ca70 | FDE: 0x046a40 | Size: 256 bytes [LEPUS_GetLength]
// Khung tháo gỡ #1381 | Địa chỉ PC: 0x13ca70 | Địa chỉ FDE: 0x046a40 | Kích thước: 256 bytes
//   0x13ca70: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x13ca74: 39458008  ldrb     w8, [x0, #0x160]
//   0x13ca78: AA0103E2  mov      x2, x1
//   0x13ca7c: 34000088  cbz      w8, #0x13ca8c
static inline uint64_t fde_func_1381_0x13ca70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13ca70ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x39458008ULL) ^ 0x046a40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1382 | PC: 0x13cbb4 | FDE: 0x046a58 | Size: 256 bytes
// Khung tháo gỡ #1382 | Địa chỉ PC: 0x13cbb4 | Địa chỉ FDE: 0x046a58 | Kích thước: 256 bytes
//   0x13cbb4: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x13cbb8: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x13cbbc: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x13cbc0: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1382_0x13cbb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13cbb4ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x046a58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1383 | PC: 0x13cd68 | FDE: 0x046a80 | Size: 256 bytes
// Khung tháo gỡ #1383 | Địa chỉ PC: 0x13cd68 | Địa chỉ FDE: 0x046a80 | Kích thước: 256 bytes
//   0x13cd68: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x13cd6c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x13cd70: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x13cd74: B40008A1  cbz      x1, #0x13ce88
static inline uint64_t fde_func_1383_0x13cd68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13cd68ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x046a80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1384 | PC: 0x13ce98 | FDE: 0x046aa0 | Size: 256 bytes
// Khung tháo gỡ #1384 | Địa chỉ PC: 0x13ce98 | Địa chỉ FDE: 0x046aa0 | Kích thước: 256 bytes
//   0x13ce98: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x13ce9c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x13cea0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x13cea4: B0000416  adrp     x22, #0x1bd000
static inline uint64_t fde_func_1384_0x13ce98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13ce98ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x046aa0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1385 | PC: 0x13cfb8 | FDE: 0x046ac0 | Size: 36 bytes
// Khung tháo gỡ #1385 | Địa chỉ PC: 0x13cfb8 | Địa chỉ FDE: 0x046ac0 | Kích thước: 36 bytes
//   0x13cfb8: B0000408  adrp     x8, #0x1bd000
//   0x13cfbc: F940D908  ldr      x8, [x8, #0x1b0]
//   0x13cfc0: 927EB429  and      x9, x1, #0xfffffffffffc
//   0x13cfc4: F9400108  ldr      x8, [x8]
static inline uint64_t fde_func_1385_0x13cfb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13cfb8ULL ^ (static_cast<uint64_t>(0xb0000408ULL) << 13);
    acc = (acc + a1 + 0xf940d908ULL) ^ 0x046ac0ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1386 | PC: 0x13cfdc | FDE: 0x046ad8 | Size: 56 bytes
// Khung tháo gỡ #1386 | Địa chỉ PC: 0x13cfdc | Địa chỉ FDE: 0x046ad8 | Kích thước: 56 bytes
//   0x13cfdc: B0000408  adrp     x8, #0x1bd000
//   0x13cfe0: F940D908  ldr      x8, [x8, #0x1b0]
//   0x13cfe4: 927EB429  and      x9, x1, #0xfffffffffffc
//   0x13cfe8: F9400108  ldr      x8, [x8]
static inline uint64_t fde_func_1386_0x13cfdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13cfdcULL ^ (static_cast<uint64_t>(0xb0000408ULL) << 13);
    acc = (acc + a1 + 0xf940d908ULL) ^ 0x046ad8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1387 | PC: 0x13d014 | FDE: 0x046af0 | Size: 256 bytes
// Khung tháo gỡ #1387 | Địa chỉ PC: 0x13d014 | Địa chỉ FDE: 0x046af0 | Kích thước: 256 bytes
//   0x13d014: D100C3FF  sub      sp, sp, #0x30
//   0x13d018: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x13d01c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x13d020: B4000AC1  cbz      x1, #0x13d178
static inline uint64_t fde_func_1387_0x13d014(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d014ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x046af0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1388 | PC: 0x13d1d8 | FDE: 0x046b10 | Size: 128 bytes
// Khung tháo gỡ #1388 | Địa chỉ PC: 0x13d1d8 | Địa chỉ FDE: 0x046b10 | Kích thước: 128 bytes
//   0x13d1d8: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x13d1dc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x13d1e0: B4000361  cbz      x1, #0x13d24c
//   0x13d1e4: D2800048  mov      x8, #2
static inline uint64_t fde_func_1388_0x13d1d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d1d8ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x046b10ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1389 | PC: 0x13d258 | FDE: 0x046b30 | Size: 68 bytes
// Khung tháo gỡ #1389 | Địa chỉ PC: 0x13d258 | Địa chỉ FDE: 0x046b30 | Kích thước: 68 bytes
//   0x13d258: B4000201  cbz      x1, #0x13d298
//   0x13d25c: D2800048  mov      x8, #2
//   0x13d260: F2FFFFE8  movk     x8, #0xffff, lsl #48
//   0x13d264: 8A080028  and      x8, x1, x8
static inline uint64_t fde_func_1389_0x13d258(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d258ULL ^ (static_cast<uint64_t>(0xb4000201ULL) << 13);
    acc = (acc + a1 + 0xd2800048ULL) ^ 0x046b30ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1390 | PC: 0x13d29c | FDE: 0x046b48 | Size: 248 bytes
// Khung tháo gỡ #1390 | Địa chỉ PC: 0x13d29c | Địa chỉ FDE: 0x046b48 | Kích thước: 248 bytes
//   0x13d29c: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x13d2a0: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x13d2a4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x13d2a8: B4000601  cbz      x1, #0x13d368
static inline uint64_t fde_func_1390_0x13d29c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d29cULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x046b48ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #1391 | PC: 0x13d394 | FDE: 0x046b68 | Size: 92 bytes
// Khung tháo gỡ #1391 | Địa chỉ PC: 0x13d394 | Địa chỉ FDE: 0x046b68 | Kích thước: 92 bytes
//   0x13d394: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x13d398: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x13d39c: F9400062  ldr      x2, [x3]
//   0x13d3a0: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1391_0x13d394(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d394ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x046b68ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1392 | PC: 0x13d3f0 | FDE: 0x046b88 | Size: 92 bytes
// Khung tháo gỡ #1392 | Địa chỉ PC: 0x13d3f0 | Địa chỉ FDE: 0x046b88 | Kích thước: 92 bytes
//   0x13d3f0: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x13d3f4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x13d3f8: F9400062  ldr      x2, [x3]
//   0x13d3fc: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1392_0x13d3f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d3f0ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x046b88ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1393 | PC: 0x13d44c | FDE: 0x046ba8 | Size: 256 bytes
// Khung tháo gỡ #1393 | Địa chỉ PC: 0x13d44c | Địa chỉ FDE: 0x046ba8 | Kích thước: 256 bytes
//   0x13d44c: D102C3FF  sub      sp, sp, #0xb0
//   0x13d450: F9002BFC  str      x28, [sp, #0x50]
//   0x13d454: A9066BFB  stp      x27, x26, [sp, #0x60]
//   0x13d458: A90763F9  stp      x25, x24, [sp, #0x70]
static inline uint64_t fde_func_1393_0x13d44c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d44cULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bfcULL) ^ 0x046ba8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1394 | PC: 0x13d63c | FDE: 0x046bd8 | Size: 256 bytes
// Khung tháo gỡ #1394 | Địa chỉ PC: 0x13d63c | Địa chỉ FDE: 0x046bd8 | Kích thước: 256 bytes
//   0x13d63c: D10303FF  sub      sp, sp, #0xc0
//   0x13d640: F90033FC  str      x28, [sp, #0x60]
//   0x13d644: A9076BFB  stp      x27, x26, [sp, #0x70]
//   0x13d648: A90863F9  stp      x25, x24, [sp, #0x80]
static inline uint64_t fde_func_1394_0x13d63c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d63cULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf90033fcULL) ^ 0x046bd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1395 | PC: 0x13da5c | FDE: 0x046c08 | Size: 180 bytes
// Khung tháo gỡ #1395 | Địa chỉ PC: 0x13da5c | Địa chỉ FDE: 0x046c08 | Kích thước: 180 bytes
//   0x13da5c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x13da60: B40003E1  cbz      x1, #0x13dadc
//   0x13da64: D2800048  mov      x8, #2
//   0x13da68: F2FFFFE8  movk     x8, #0xffff, lsl #48
static inline uint64_t fde_func_1395_0x13da5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13da5cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xb40003e1ULL) ^ 0x046c08ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1396 | PC: 0x13db10 | FDE: 0x046c20 | Size: 192 bytes
// Khung tháo gỡ #1396 | Địa chỉ PC: 0x13db10 | Địa chỉ FDE: 0x046c20 | Kích thước: 192 bytes
//   0x13db10: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x13db14: B4000381  cbz      x1, #0x13db84
//   0x13db18: D2800048  mov      x8, #2
//   0x13db1c: F2FFFFE8  movk     x8, #0xffff, lsl #48
static inline uint64_t fde_func_1396_0x13db10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13db10ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb4000381ULL) ^ 0x046c20ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1397 | PC: 0x13dbd0 | FDE: 0x046c38 | Size: 192 bytes
// Khung tháo gỡ #1397 | Địa chỉ PC: 0x13dbd0 | Địa chỉ FDE: 0x046c38 | Kích thước: 192 bytes
//   0x13dbd0: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x13dbd4: B4000381  cbz      x1, #0x13dc44
//   0x13dbd8: D2800048  mov      x8, #2
//   0x13dbdc: F2FFFFE8  movk     x8, #0xffff, lsl #48
static inline uint64_t fde_func_1397_0x13dbd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13dbd0ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb4000381ULL) ^ 0x046c38ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1398 | PC: 0x13dc90 | FDE: 0x046c50 | Size: 256 bytes
// Khung tháo gỡ #1398 | Địa chỉ PC: 0x13dc90 | Địa chỉ FDE: 0x046c50 | Kích thước: 256 bytes
//   0x13dc90: D10283FF  sub      sp, sp, #0xa0
//   0x13dc94: F9002BFA  str      x26, [sp, #0x50]
//   0x13dc98: A90663F9  stp      x25, x24, [sp, #0x60]
//   0x13dc9c: A9075BF7  stp      x23, x22, [sp, #0x70]
static inline uint64_t fde_func_1398_0x13dc90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13dc90ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9002bfaULL) ^ 0x046c50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1399 | PC: 0x13e050 | FDE: 0x046c78 | Size: 256 bytes
// Khung tháo gỡ #1399 | Địa chỉ PC: 0x13e050 | Địa chỉ FDE: 0x046c78 | Kích thước: 256 bytes
//   0x13e050: D10343FF  sub      sp, sp, #0xd0
//   0x13e054: F9003BFC  str      x28, [sp, #0x70]
//   0x13e058: A9086BFB  stp      x27, x26, [sp, #0x80]
//   0x13e05c: A90963F9  stp      x25, x24, [sp, #0x90]
static inline uint64_t fde_func_1399_0x13e050(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13e050ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xf9003bfcULL) ^ 0x046c78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1400 | PC: 0x13e450 | FDE: 0x046ca8 | Size: 256 bytes
// Khung tháo gỡ #1400 | Địa chỉ PC: 0x13e450 | Địa chỉ FDE: 0x046ca8 | Kích thước: 256 bytes
//   0x13e450: D10243FF  sub      sp, sp, #0x90
//   0x13e454: FD0013E8  str      d8, [sp, #0x20]
//   0x13e458: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x13e45c: A90467FA  stp      x26, x25, [sp, #0x40]
static inline uint64_t fde_func_1400_0x13e450(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13e450ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xfd0013e8ULL) ^ 0x046ca8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1401 | PC: 0x13f8a4 | FDE: 0x046cd8 | Size: 256 bytes
// Khung tháo gỡ #1401 | Địa chỉ PC: 0x13f8a4 | Địa chỉ FDE: 0x046cd8 | Kích thước: 256 bytes
//   0x13f8a4: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x13f8a8: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x13f8ac: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x13f8b0: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1401_0x13f8a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13f8a4ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x046cd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1402 | PC: 0x13faf8 | FDE: 0x046d08 | Size: 256 bytes
// Khung tháo gỡ #1402 | Địa chỉ PC: 0x13faf8 | Địa chỉ FDE: 0x046d08 | Kích thước: 256 bytes
//   0x13faf8: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x13fafc: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x13fb00: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x13fb04: 39458008  ldrb     w8, [x0, #0x160]
static inline uint64_t fde_func_1402_0x13faf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13faf8ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x046d08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1403 | PC: 0x13fcb8 | FDE: 0x046d28 | Size: 256 bytes
// Khung tháo gỡ #1403 | Địa chỉ PC: 0x13fcb8 | Địa chỉ FDE: 0x046d28 | Kích thước: 256 bytes
//   0x13fcb8: D102C3FF  sub      sp, sp, #0xb0
//   0x13fcbc: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x13fcc0: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x13fcc4: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_1403_0x13fcb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13fcb8ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x046d28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1404 | PC: 0x140710 | FDE: 0x046d58 | Size: 256 bytes
// Khung tháo gỡ #1404 | Địa chỉ PC: 0x140710 | Địa chỉ FDE: 0x046d58 | Kích thước: 256 bytes
//   0x140710: D101C3FF  sub      sp, sp, #0x70
//   0x140714: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x140718: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x14071c: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1404_0x140710(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x140710ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x046d58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1405 | PC: 0x140924 | FDE: 0x046d88 | Size: 256 bytes
// Khung tháo gỡ #1405 | Địa chỉ PC: 0x140924 | Địa chỉ FDE: 0x046d88 | Kích thước: 256 bytes
//   0x140924: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x140928: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x14092c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x140930: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1405_0x140924(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x140924ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x046d88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1406 | PC: 0x140b54 | FDE: 0x046db0 | Size: 112 bytes
// Khung tháo gỡ #1406 | Địa chỉ PC: 0x140b54 | Địa chỉ FDE: 0x046db0 | Kích thước: 112 bytes
//   0x140b54: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x140b58: B4000261  cbz      x1, #0x140ba4
//   0x140b5c: D2800048  mov      x8, #2
//   0x140b60: F2FFFFE8  movk     x8, #0xffff, lsl #48
static inline uint64_t fde_func_1406_0x140b54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x140b54ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb4000261ULL) ^ 0x046db0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1407 | PC: 0x140bc4 | FDE: 0x046dc8 | Size: 256 bytes
// Khung tháo gỡ #1407 | Địa chỉ PC: 0x140bc4 | Địa chỉ FDE: 0x046dc8 | Kích thước: 256 bytes
//   0x140bc4: D101C3FF  sub      sp, sp, #0x70
//   0x140bc8: F9000BFC  str      x28, [sp, #0x10]
//   0x140bcc: A9026BFB  stp      x27, x26, [sp, #0x20]
//   0x140bd0: A90363F9  stp      x25, x24, [sp, #0x30]
static inline uint64_t fde_func_1407_0x140bc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x140bc4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfcULL) ^ 0x046dc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1408 | PC: 0x141190 | FDE: 0x046df8 | Size: 140 bytes
// Khung tháo gỡ #1408 | Địa chỉ PC: 0x141190 | Địa chỉ FDE: 0x046df8 | Kích thước: 140 bytes
//   0x141190: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x141194: B4000301  cbz      x1, #0x1411f4
//   0x141198: D2800048  mov      x8, #2
//   0x14119c: F2FFFFE8  movk     x8, #0xffff, lsl #48
static inline uint64_t fde_func_1408_0x141190(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x141190ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb4000301ULL) ^ 0x046df8ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1409 | PC: 0x14121c | FDE: 0x046e10 | Size: 256 bytes
// Khung tháo gỡ #1409 | Địa chỉ PC: 0x14121c | Địa chỉ FDE: 0x046e10 | Kích thước: 256 bytes
//   0x14121c: D101C3FF  sub      sp, sp, #0x70
//   0x141220: F9002BF4  str      x20, [sp, #0x50]
//   0x141224: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x141228: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_1409_0x14121c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14121cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf4ULL) ^ 0x046e10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1410 | PC: 0x14134c | FDE: 0x046e30 | Size: 256 bytes
// Khung tháo gỡ #1410 | Địa chỉ PC: 0x14134c | Địa chỉ FDE: 0x046e30 | Kích thước: 256 bytes
//   0x14134c: D10183FF  sub      sp, sp, #0x60
//   0x141350: F9000BFA  str      x26, [sp, #0x10]
//   0x141354: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x141358: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_1410_0x14134c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14134cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfaULL) ^ 0x046e30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1411 | PC: 0x141728 | FDE: 0x046e58 | Size: 256 bytes
// Khung tháo gỡ #1411 | Địa chỉ PC: 0x141728 | Địa chỉ FDE: 0x046e58 | Kích thước: 256 bytes
//   0x141728: D10383FF  sub      sp, sp, #0xe0
//   0x14172c: FD003BE8  str      d8, [sp, #0x70]
//   0x141730: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x141734: A90967FA  stp      x26, x25, [sp, #0x90]
static inline uint64_t fde_func_1411_0x141728(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x141728ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xfd003be8ULL) ^ 0x046e58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1412 | PC: 0x142604 | FDE: 0x046e88 | Size: 256 bytes [_Z15js_array_reduceP12LEPUSContext10LEPUSValueiPS1_i]
// Khung tháo gỡ #1412 | Địa chỉ PC: 0x142604 | Địa chỉ FDE: 0x046e88 | Kích thước: 256 bytes
//   0x142604: D10303FF  sub      sp, sp, #0xc0
//   0x142608: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x14260c: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x142610: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_1412_0x142604(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x142604ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x046e88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1413 | PC: 0x1430ec | FDE: 0x046eb8 | Size: 256 bytes
// Khung tháo gỡ #1413 | Địa chỉ PC: 0x1430ec | Địa chỉ FDE: 0x046eb8 | Kích thước: 256 bytes
//   0x1430ec: D10203FF  sub      sp, sp, #0x80
//   0x1430f0: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x1430f4: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x1430f8: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1413_0x1430ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1430ecULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x046eb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1414 | PC: 0x14375c | FDE: 0x046ee8 | Size: 256 bytes
// Khung tháo gỡ #1414 | Địa chỉ PC: 0x14375c | Địa chỉ FDE: 0x046ee8 | Kích thước: 256 bytes
//   0x14375c: D10243FF  sub      sp, sp, #0x90
//   0x143760: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x143764: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x143768: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1414_0x14375c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14375cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x046ee8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1415 | PC: 0x143b7c | FDE: 0x046f18 | Size: 256 bytes
// Khung tháo gỡ #1415 | Địa chỉ PC: 0x143b7c | Địa chỉ FDE: 0x046f18 | Kích thước: 256 bytes
//   0x143b7c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x143b80: B4000341  cbz      x1, #0x143be8
//   0x143b84: D2800048  mov      x8, #2
//   0x143b88: F2FFFFE8  movk     x8, #0xffff, lsl #48
static inline uint64_t fde_func_1415_0x143b7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x143b7cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xb4000341ULL) ^ 0x046f18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1416 | PC: 0x143d94 | FDE: 0x046f30 | Size: 256 bytes
// Khung tháo gỡ #1416 | Địa chỉ PC: 0x143d94 | Địa chỉ FDE: 0x046f30 | Kích thước: 256 bytes
//   0x143d94: D10243FF  sub      sp, sp, #0x90
//   0x143d98: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x143d9c: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x143da0: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1416_0x143d94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x143d94ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x046f30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1417 | PC: 0x144254 | FDE: 0x046f60 | Size: 256 bytes
// Khung tháo gỡ #1417 | Địa chỉ PC: 0x144254 | Địa chỉ FDE: 0x046f60 | Kích thước: 256 bytes
//   0x144254: D10243FF  sub      sp, sp, #0x90
//   0x144258: F9001BFC  str      x28, [sp, #0x30]
//   0x14425c: A9046BFB  stp      x27, x26, [sp, #0x40]
//   0x144260: A90563F9  stp      x25, x24, [sp, #0x50]
static inline uint64_t fde_func_1417_0x144254(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144254ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9001bfcULL) ^ 0x046f60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1418 | PC: 0x1445ec | FDE: 0x046f90 | Size: 256 bytes
// Khung tháo gỡ #1418 | Địa chỉ PC: 0x1445ec | Địa chỉ FDE: 0x046f90 | Kích thước: 256 bytes
//   0x1445ec: D102C3FF  sub      sp, sp, #0xb0
//   0x1445f0: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x1445f4: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x1445f8: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_1418_0x1445ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1445ecULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x046f90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1419 | PC: 0x144a5c | FDE: 0x046fc0 | Size: 256 bytes
// Khung tháo gỡ #1419 | Địa chỉ PC: 0x144a5c | Địa chỉ FDE: 0x046fc0 | Kích thước: 256 bytes
//   0x144a5c: D10283FF  sub      sp, sp, #0xa0
//   0x144a60: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x144a64: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x144a68: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1419_0x144a5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144a5cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x046fc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1420 | PC: 0x144f8c | FDE: 0x046ff0 | Size: 256 bytes
// Khung tháo gỡ #1420 | Địa chỉ PC: 0x144f8c | Địa chỉ FDE: 0x046ff0 | Kích thước: 256 bytes
//   0x144f8c: D10203FF  sub      sp, sp, #0x80
//   0x144f90: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x144f94: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x144f98: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1420_0x144f8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144f8cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x046ff0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1421 | PC: 0x1458a4 | FDE: 0x047020 | Size: 256 bytes
// Khung tháo gỡ #1421 | Địa chỉ PC: 0x1458a4 | Địa chỉ FDE: 0x047020 | Kích thước: 256 bytes
//   0x1458a4: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x1458a8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1458ac: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1458b0: B9401C08  ldr      w8, [x0, #0x1c]
static inline uint64_t fde_func_1421_0x1458a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1458a4ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x047020ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1422 | PC: 0x145b10 | FDE: 0x047040 | Size: 256 bytes
// Khung tháo gỡ #1422 | Địa chỉ PC: 0x145b10 | Địa chỉ FDE: 0x047040 | Kích thước: 256 bytes
//   0x145b10: D101C3FF  sub      sp, sp, #0x70
//   0x145b14: F90013FA  str      x26, [sp, #0x20]
//   0x145b18: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x145b1c: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_1422_0x145b10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145b10ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013faULL) ^ 0x047040ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1423 | PC: 0x145f0c | FDE: 0x047068 | Size: 256 bytes
// Khung tháo gỡ #1423 | Địa chỉ PC: 0x145f0c | Địa chỉ FDE: 0x047068 | Kích thước: 256 bytes
//   0x145f0c: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x145f10: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x145f14: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x145f18: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1423_0x145f0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x145f0cULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x047068ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1424 | PC: 0x14607c | FDE: 0x047090 | Size: 256 bytes
// Khung tháo gỡ #1424 | Địa chỉ PC: 0x14607c | Địa chỉ FDE: 0x047090 | Kích thước: 256 bytes
//   0x14607c: D10183FF  sub      sp, sp, #0x60
//   0x146080: F90013F8  str      x24, [sp, #0x20]
//   0x146084: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x146088: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_1424_0x14607c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14607cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f8ULL) ^ 0x047090ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1425 | PC: 0x14620c | FDE: 0x0470b8 | Size: 256 bytes
// Khung tháo gỡ #1425 | Địa chỉ PC: 0x14620c | Địa chỉ FDE: 0x0470b8 | Kích thước: 256 bytes
//   0x14620c: D10103FF  sub      sp, sp, #0x40
//   0x146210: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x146214: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x146218: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1425_0x14620c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14620cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0470b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1426 | PC: 0x146390 | FDE: 0x0470d8 | Size: 256 bytes [LEPUS_IsArray]
// Khung tháo gỡ #1426 | Địa chỉ PC: 0x146390 | Địa chỉ FDE: 0x0470d8 | Kích thước: 256 bytes
//   0x146390: D10243FF  sub      sp, sp, #0x90
//   0x146394: F90033F5  str      x21, [sp, #0x60]
//   0x146398: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x14639c: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_1426_0x146390(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x146390ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90033f5ULL) ^ 0x0470d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1427 | PC: 0x146500 | FDE: 0x0470f8 | Size: 256 bytes
// Khung tháo gỡ #1427 | Địa chỉ PC: 0x146500 | Địa chỉ FDE: 0x0470f8 | Kích thước: 256 bytes
//   0x146500: D101C3FF  sub      sp, sp, #0x70
//   0x146504: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x146508: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x14650c: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1427_0x146500(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x146500ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x0470f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1428 | PC: 0x146840 | FDE: 0x047128 | Size: 212 bytes
// Khung tháo gỡ #1428 | Địa chỉ PC: 0x146840 | Địa chỉ FDE: 0x047128 | Kích thước: 212 bytes
//   0x146840: D101C3FF  sub      sp, sp, #0x70
//   0x146844: F9002BF4  str      x20, [sp, #0x50]
//   0x146848: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x14684c: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_1428_0x146840(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x146840ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf4ULL) ^ 0x047128ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1429 | PC: 0x146914 | FDE: 0x047148 | Size: 256 bytes
// Khung tháo gỡ #1429 | Địa chỉ PC: 0x146914 | Địa chỉ FDE: 0x047148 | Kích thước: 256 bytes
//   0x146914: D10303FF  sub      sp, sp, #0xc0
//   0x146918: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x14691c: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x146920: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_1429_0x146914(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x146914ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x047148ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1430 | PC: 0x146fdc | FDE: 0x047178 | Size: 256 bytes
// Khung tháo gỡ #1430 | Địa chỉ PC: 0x146fdc | Địa chỉ FDE: 0x047178 | Kích thước: 256 bytes
//   0x146fdc: D10283FF  sub      sp, sp, #0xa0
//   0x146fe0: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x146fe4: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x146fe8: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1430_0x146fdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x146fdcULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x047178ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1431 | PC: 0x147d60 | FDE: 0x0471a8 | Size: 256 bytes
// Khung tháo gỡ #1431 | Địa chỉ PC: 0x147d60 | Địa chỉ FDE: 0x0471a8 | Kích thước: 256 bytes
//   0x147d60: D10283FF  sub      sp, sp, #0xa0
//   0x147d64: F9002BFA  str      x26, [sp, #0x50]
//   0x147d68: A90663F9  stp      x25, x24, [sp, #0x60]
//   0x147d6c: A9075BF7  stp      x23, x22, [sp, #0x70]
static inline uint64_t fde_func_1431_0x147d60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x147d60ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9002bfaULL) ^ 0x0471a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1432 | PC: 0x1482a8 | FDE: 0x0471d0 | Size: 256 bytes
// Khung tháo gỡ #1432 | Địa chỉ PC: 0x1482a8 | Địa chỉ FDE: 0x0471d0 | Kích thước: 256 bytes
//   0x1482a8: D10303FF  sub      sp, sp, #0xc0
//   0x1482ac: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x1482b0: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x1482b4: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_1432_0x1482a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1482a8ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x0471d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1433 | PC: 0x148ab4 | FDE: 0x047200 | Size: 256 bytes
// Khung tháo gỡ #1433 | Địa chỉ PC: 0x148ab4 | Địa chỉ FDE: 0x047200 | Kích thước: 256 bytes
//   0x148ab4: D102C3FF  sub      sp, sp, #0xb0
//   0x148ab8: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x148abc: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x148ac0: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_1433_0x148ab4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x148ab4ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x047200ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1434 | PC: 0x148d70 | FDE: 0x047230 | Size: 256 bytes
// Khung tháo gỡ #1434 | Địa chỉ PC: 0x148d70 | Địa chỉ FDE: 0x047230 | Kích thước: 256 bytes
//   0x148d70: D102C3FF  sub      sp, sp, #0xb0
//   0x148d74: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x148d78: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x148d7c: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_1434_0x148d70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x148d70ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x047230ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1435 | PC: 0x149050 | FDE: 0x047260 | Size: 256 bytes [_Z12map_hash_keyP12LEPUSContext10LEPUSValuej]
// Khung tháo gỡ #1435 | Địa chỉ PC: 0x149050 | Địa chỉ FDE: 0x047260 | Kích thước: 256 bytes
//   0x149050: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x149054: 2A0203F3  mov      w19, w2
//   0x149058: AA0003E8  mov      x8, x0
//   0x14905c: D371FC29  lsr      x9, x1, #0x31
static inline uint64_t fde_func_1435_0x149050(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x149050ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x2a0203f3ULL) ^ 0x047260ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1436 | PC: 0x1492f0 | FDE: 0x047278 | Size: 256 bytes
// Khung tháo gỡ #1436 | Địa chỉ PC: 0x1492f0 | Địa chỉ FDE: 0x047278 | Kích thước: 256 bytes
//   0x1492f0: D10103FF  sub      sp, sp, #0x40
//   0x1492f4: F9000BF6  str      x22, [sp, #0x10]
//   0x1492f8: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x1492fc: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1436_0x1492f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1492f0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x047278ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1437 | PC: 0x149534 | FDE: 0x047298 | Size: 256 bytes
// Khung tháo gỡ #1437 | Địa chỉ PC: 0x149534 | Địa chỉ FDE: 0x047298 | Kích thước: 256 bytes
//   0x149534: D102C3FF  sub      sp, sp, #0xb0
//   0x149538: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x14953c: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x149540: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_1437_0x149534(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x149534ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x047298ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1438 | PC: 0x149888 | FDE: 0x0472c8 | Size: 256 bytes
// Khung tháo gỡ #1438 | Địa chỉ PC: 0x149888 | Địa chỉ FDE: 0x0472c8 | Kích thước: 256 bytes
//   0x149888: D10243FF  sub      sp, sp, #0x90
//   0x14988c: F9002BF8  str      x24, [sp, #0x50]
//   0x149890: A9065BF7  stp      x23, x22, [sp, #0x60]
//   0x149894: A90753F5  stp      x21, x20, [sp, #0x70]
static inline uint64_t fde_func_1438_0x149888(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x149888ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf8ULL) ^ 0x0472c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1439 | PC: 0x14998c | FDE: 0x0472f0 | Size: 256 bytes
// Khung tháo gỡ #1439 | Địa chỉ PC: 0x14998c | Địa chỉ FDE: 0x0472f0 | Kích thước: 256 bytes
//   0x14998c: D102C3FF  sub      sp, sp, #0xb0
//   0x149990: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x149994: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x149998: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_1439_0x14998c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14998cULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x0472f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1440 | PC: 0x149ea4 | FDE: 0x047320 | Size: 256 bytes
// Khung tháo gỡ #1440 | Địa chỉ PC: 0x149ea4 | Địa chỉ FDE: 0x047320 | Kích thước: 256 bytes
//   0x149ea4: D10283FF  sub      sp, sp, #0xa0
//   0x149ea8: A9056BFB  stp      x27, x26, [sp, #0x50]
//   0x149eac: A90663F9  stp      x25, x24, [sp, #0x60]
//   0x149eb0: A9075BF7  stp      x23, x22, [sp, #0x70]
static inline uint64_t fde_func_1440_0x149ea4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x149ea4ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9056bfbULL) ^ 0x047320ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1441 | PC: 0x14a128 | FDE: 0x047350 | Size: 256 bytes
// Khung tháo gỡ #1441 | Địa chỉ PC: 0x14a128 | Địa chỉ FDE: 0x047350 | Kích thước: 256 bytes
//   0x14a128: D10103FF  sub      sp, sp, #0x40
//   0x14a12c: F9000BF6  str      x22, [sp, #0x10]
//   0x14a130: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x14a134: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1441_0x14a128(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14a128ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x047350ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1442 | PC: 0x14a3a0 | FDE: 0x047370 | Size: 148 bytes
// Khung tháo gỡ #1442 | Địa chỉ PC: 0x14a3a0 | Địa chỉ FDE: 0x047370 | Kích thước: 148 bytes
//   0x14a3a0: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x14a3a4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x14a3a8: B4000401  cbz      x1, #0x14a428
//   0x14a3ac: D2800048  mov      x8, #2
static inline uint64_t fde_func_1442_0x14a3a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14a3a0ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x047370ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1443 | PC: 0x14a434 | FDE: 0x047390 | Size: 256 bytes
// Khung tháo gỡ #1443 | Địa chỉ PC: 0x14a434 | Địa chỉ FDE: 0x047390 | Kích thước: 256 bytes
//   0x14a434: D10243FF  sub      sp, sp, #0x90
//   0x14a438: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x14a43c: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x14a440: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1443_0x14a434(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14a434ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x047390ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1444 | PC: 0x14ac78 | FDE: 0x0473c0 | Size: 256 bytes
// Khung tháo gỡ #1444 | Địa chỉ PC: 0x14ac78 | Địa chỉ FDE: 0x0473c0 | Kích thước: 256 bytes
//   0x14ac78: F81A0FFC  str      x28, [sp, #-0x60]!
//   0x14ac7c: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x14ac80: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x14ac84: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_1444_0x14ac78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14ac78ULL ^ (static_cast<uint64_t>(0xf81a0ffcULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x0473c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1445 | PC: 0x14b00c | FDE: 0x0473f0 | Size: 256 bytes
// Khung tháo gỡ #1445 | Địa chỉ PC: 0x14b00c | Địa chỉ FDE: 0x0473f0 | Kích thước: 256 bytes
//   0x14b00c: D10143FF  sub      sp, sp, #0x50
//   0x14b010: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x14b014: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x14b018: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1445_0x14b00c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14b00cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x0473f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1446 | PC: 0x14b32c | FDE: 0x047418 | Size: 252 bytes
// Khung tháo gỡ #1446 | Địa chỉ PC: 0x14b32c | Địa chỉ FDE: 0x047418 | Kích thước: 252 bytes
//   0x14b32c: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x14b330: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x14b334: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x14b338: F94000A9  ldr      x9, [x5]
static inline uint64_t fde_func_1446_0x14b32c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14b32cULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x047418ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1447 | PC: 0x14b428 | FDE: 0x047438 | Size: 256 bytes
// Khung tháo gỡ #1447 | Địa chỉ PC: 0x14b428 | Địa chỉ FDE: 0x047438 | Kích thước: 256 bytes
//   0x14b428: D10303FF  sub      sp, sp, #0xc0
//   0x14b42c: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x14b430: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x14b434: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_1447_0x14b428(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14b428ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x047438ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1448 | PC: 0x14b9f0 | FDE: 0x047468 | Size: 256 bytes
// Khung tháo gỡ #1448 | Địa chỉ PC: 0x14b9f0 | Địa chỉ FDE: 0x047468 | Kích thước: 256 bytes
//   0x14b9f0: D10303FF  sub      sp, sp, #0xc0
//   0x14b9f4: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x14b9f8: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x14b9fc: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_1448_0x14b9f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14b9f0ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x047468ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1449 | PC: 0x14c2ec | FDE: 0x047498 | Size: 256 bytes
// Khung tháo gỡ #1449 | Địa chỉ PC: 0x14c2ec | Địa chỉ FDE: 0x047498 | Kích thước: 256 bytes
//   0x14c2ec: D10243FF  sub      sp, sp, #0x90
//   0x14c2f0: A9046BFB  stp      x27, x26, [sp, #0x40]
//   0x14c2f4: A90563F9  stp      x25, x24, [sp, #0x50]
//   0x14c2f8: A9065BF7  stp      x23, x22, [sp, #0x60]
static inline uint64_t fde_func_1449_0x14c2ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c2ecULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9046bfbULL) ^ 0x047498ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1450 | PC: 0x14c630 | FDE: 0x0474c8 | Size: 256 bytes
// Khung tháo gỡ #1450 | Địa chỉ PC: 0x14c630 | Địa chỉ FDE: 0x0474c8 | Kích thước: 256 bytes
//   0x14c630: D10303FF  sub      sp, sp, #0xc0
//   0x14c634: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x14c638: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x14c63c: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_1450_0x14c630(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c630ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x0474c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1451 | PC: 0x14d424 | FDE: 0x0474f8 | Size: 256 bytes
// Khung tháo gỡ #1451 | Địa chỉ PC: 0x14d424 | Địa chỉ FDE: 0x0474f8 | Kích thước: 256 bytes
//   0x14d424: D10283FF  sub      sp, sp, #0xa0
//   0x14d428: F90023FC  str      x28, [sp, #0x40]
//   0x14d42c: A9056BFB  stp      x27, x26, [sp, #0x50]
//   0x14d430: A90663F9  stp      x25, x24, [sp, #0x60]
static inline uint64_t fde_func_1451_0x14d424(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14d424ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90023fcULL) ^ 0x0474f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1452 | PC: 0x14d76c | FDE: 0x047528 | Size: 256 bytes
// Khung tháo gỡ #1452 | Địa chỉ PC: 0x14d76c | Địa chỉ FDE: 0x047528 | Kích thước: 256 bytes
//   0x14d76c: D102C3FF  sub      sp, sp, #0xb0
//   0x14d770: F9002BFC  str      x28, [sp, #0x50]
//   0x14d774: A9066BFB  stp      x27, x26, [sp, #0x60]
//   0x14d778: A90763F9  stp      x25, x24, [sp, #0x70]
static inline uint64_t fde_func_1452_0x14d76c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14d76cULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bfcULL) ^ 0x047528ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1453 | PC: 0x14dcdc | FDE: 0x047558 | Size: 256 bytes
// Khung tháo gỡ #1453 | Địa chỉ PC: 0x14dcdc | Địa chỉ FDE: 0x047558 | Kích thước: 256 bytes
//   0x14dcdc: D102C3FF  sub      sp, sp, #0xb0
//   0x14dce0: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x14dce4: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x14dce8: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_1453_0x14dcdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14dcdcULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x047558ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1454 | PC: 0x14e210 | FDE: 0x047588 | Size: 256 bytes
// Khung tháo gỡ #1454 | Địa chỉ PC: 0x14e210 | Địa chỉ FDE: 0x047588 | Kích thước: 256 bytes
//   0x14e210: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x14e214: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x14e218: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x14e21c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1454_0x14e210(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14e210ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x047588ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1455 | PC: 0x14e3dc | FDE: 0x0475b0 | Size: 256 bytes
// Khung tháo gỡ #1455 | Địa chỉ PC: 0x14e3dc | Địa chỉ FDE: 0x0475b0 | Kích thước: 256 bytes
//   0x14e3dc: F81A0FFC  str      x28, [sp, #-0x60]!
//   0x14e3e0: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x14e3e4: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x14e3e8: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_1455_0x14e3dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14e3dcULL ^ (static_cast<uint64_t>(0xf81a0ffcULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x0475b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1456 | PC: 0x14e8e4 | FDE: 0x0475e0 | Size: 256 bytes
// Khung tháo gỡ #1456 | Địa chỉ PC: 0x14e8e4 | Địa chỉ FDE: 0x0475e0 | Kích thước: 256 bytes
//   0x14e8e4: D10183FF  sub      sp, sp, #0x60
//   0x14e8e8: F9000BFA  str      x26, [sp, #0x10]
//   0x14e8ec: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x14e8f0: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_1456_0x14e8e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14e8e4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfaULL) ^ 0x0475e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1457 | PC: 0x14ece0 | FDE: 0x047608 | Size: 256 bytes
// Khung tháo gỡ #1457 | Địa chỉ PC: 0x14ece0 | Địa chỉ FDE: 0x047608 | Kích thước: 256 bytes
//   0x14ece0: D10403FF  sub      sp, sp, #0x100
//   0x14ece4: A90A6FFC  stp      x28, x27, [sp, #0xa0]
//   0x14ece8: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x14ecec: A90C5FF8  stp      x24, x23, [sp, #0xc0]
static inline uint64_t fde_func_1457_0x14ece0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14ece0ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90a6ffcULL) ^ 0x047608ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1458 | PC: 0x14ff20 | FDE: 0x047638 | Size: 256 bytes
// Khung tháo gỡ #1458 | Địa chỉ PC: 0x14ff20 | Địa chỉ FDE: 0x047638 | Kích thước: 256 bytes
//   0x14ff20: D10243FF  sub      sp, sp, #0x90
//   0x14ff24: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x14ff28: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x14ff2c: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1458_0x14ff20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14ff20ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x047638ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1459 | PC: 0x1505c8 | FDE: 0x047668 | Size: 256 bytes
// Khung tháo gỡ #1459 | Địa chỉ PC: 0x1505c8 | Địa chỉ FDE: 0x047668 | Kích thước: 256 bytes
//   0x1505c8: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x1505cc: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x1505d0: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x1505d4: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1459_0x1505c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1505c8ULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x047668ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1460 | PC: 0x1508bc | FDE: 0x047690 | Size: 256 bytes
// Khung tháo gỡ #1460 | Địa chỉ PC: 0x1508bc | Địa chỉ FDE: 0x047690 | Kích thước: 256 bytes
//   0x1508bc: D10203FF  sub      sp, sp, #0x80
//   0x1508c0: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x1508c4: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x1508c8: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1460_0x1508bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1508bcULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x047690ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1461 | PC: 0x150f4c | FDE: 0x0476c0 | Size: 256 bytes
// Khung tháo gỡ #1461 | Địa chỉ PC: 0x150f4c | Địa chỉ FDE: 0x0476c0 | Kích thước: 256 bytes
//   0x150f4c: D10303FF  sub      sp, sp, #0xc0
//   0x150f50: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x150f54: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x150f58: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_1461_0x150f4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150f4cULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x0476c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1462 | PC: 0x152e74 | FDE: 0x0476f0 | Size: 256 bytes
// Khung tháo gỡ #1462 | Địa chỉ PC: 0x152e74 | Địa chỉ FDE: 0x0476f0 | Kích thước: 256 bytes
//   0x152e74: D10283FF  sub      sp, sp, #0xa0
//   0x152e78: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x152e7c: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x152e80: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1462_0x152e74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x152e74ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x0476f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1463 | PC: 0x153430 | FDE: 0x047720 | Size: 256 bytes
// Khung tháo gỡ #1463 | Địa chỉ PC: 0x153430 | Địa chỉ FDE: 0x047720 | Kích thước: 256 bytes
//   0x153430: FC190FE8  str      d8, [sp, #-0x70]!
//   0x153434: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x153438: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x15343c: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1463_0x153430(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x153430ULL ^ (static_cast<uint64_t>(0xfc190fe8ULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x047720ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1464 | PC: 0x153860 | FDE: 0x047750 | Size: 256 bytes
// Khung tháo gỡ #1464 | Địa chỉ PC: 0x153860 | Địa chỉ FDE: 0x047750 | Kích thước: 256 bytes
//   0x153860: D102C3FF  sub      sp, sp, #0xb0
//   0x153864: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x153868: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x15386c: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_1464_0x153860(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x153860ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x047750ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1465 | PC: 0x153d28 | FDE: 0x047780 | Size: 256 bytes
// Khung tháo gỡ #1465 | Địa chỉ PC: 0x153d28 | Địa chỉ FDE: 0x047780 | Kích thước: 256 bytes
//   0x153d28: D10203FF  sub      sp, sp, #0x80
//   0x153d2c: A9036BFB  stp      x27, x26, [sp, #0x30]
//   0x153d30: A90463F9  stp      x25, x24, [sp, #0x40]
//   0x153d34: A9055BF7  stp      x23, x22, [sp, #0x50]
static inline uint64_t fde_func_1465_0x153d28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x153d28ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9036bfbULL) ^ 0x047780ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1466 | PC: 0x15435c | FDE: 0x0477b0 | Size: 256 bytes
// Khung tháo gỡ #1466 | Địa chỉ PC: 0x15435c | Địa chỉ FDE: 0x0477b0 | Kích thước: 256 bytes
//   0x15435c: D10343FF  sub      sp, sp, #0xd0
//   0x154360: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x154364: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x154368: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_1466_0x15435c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15435cULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9076ffcULL) ^ 0x0477b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1467 | PC: 0x1548a0 | FDE: 0x0477e0 | Size: 256 bytes
// Khung tháo gỡ #1467 | Địa chỉ PC: 0x1548a0 | Địa chỉ FDE: 0x0477e0 | Kích thước: 256 bytes
//   0x1548a0: D105C3FF  sub      sp, sp, #0x170
//   0x1548a4: A9116FFC  stp      x28, x27, [sp, #0x110]
//   0x1548a8: A91267FA  stp      x26, x25, [sp, #0x120]
//   0x1548ac: A9135FF8  stp      x24, x23, [sp, #0x130]
static inline uint64_t fde_func_1467_0x1548a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1548a0ULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xa9116ffcULL) ^ 0x0477e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1468 | PC: 0x1560dc | FDE: 0x047810 | Size: 252 bytes [LEPUS_ParseJSON]
// Khung tháo gỡ #1468 | Địa chỉ PC: 0x1560dc | Địa chỉ FDE: 0x047810 | Kích thước: 252 bytes
//   0x1560dc: D10383FF  sub      sp, sp, #0xe0
//   0x1560e0: F90063F4  str      x20, [sp, #0xc0]
//   0x1560e4: A90D7BF3  stp      x19, x30, [sp, #0xd0]
//   0x1560e8: D53BD053  mrs      x19, tpidr_el0
static inline uint64_t fde_func_1468_0x1560dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1560dcULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xf90063f4ULL) ^ 0x047810ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1469 | PC: 0x1561d8 | FDE: 0x047830 | Size: 256 bytes
// Khung tháo gỡ #1469 | Địa chỉ PC: 0x1561d8 | Địa chỉ FDE: 0x047830 | Kích thước: 256 bytes
//   0x1561d8: D10383FF  sub      sp, sp, #0xe0
//   0x1561dc: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x1561e0: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x1561e4: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_1469_0x1561d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1561d8ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x047830ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1470 | PC: 0x1567c4 | FDE: 0x047860 | Size: 256 bytes
// Khung tháo gỡ #1470 | Địa chỉ PC: 0x1567c4 | Địa chỉ FDE: 0x047860 | Kích thước: 256 bytes
//   0x1567c4: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x1567c8: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x1567cc: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x1567d0: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1470_0x1567c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1567c4ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x047860ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1471 | PC: 0x157e4c | FDE: 0x047890 | Size: 256 bytes
// Khung tháo gỡ #1471 | Địa chỉ PC: 0x157e4c | Địa chỉ FDE: 0x047890 | Kích thước: 256 bytes
//   0x157e4c: D101C3FF  sub      sp, sp, #0x70
//   0x157e50: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x157e54: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x157e58: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1471_0x157e4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x157e4cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x047890ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1472 | PC: 0x15857c | FDE: 0x0478c0 | Size: 256 bytes
// Khung tháo gỡ #1472 | Địa chỉ PC: 0x15857c | Địa chỉ FDE: 0x0478c0 | Kích thước: 256 bytes
//   0x15857c: D104C3FF  sub      sp, sp, #0x130
//   0x158580: F90083FC  str      x28, [sp, #0x100]
//   0x158584: A91153F5  stp      x21, x20, [sp, #0x110]
//   0x158588: A9127BF3  stp      x19, x30, [sp, #0x120]
static inline uint64_t fde_func_1472_0x15857c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15857cULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x0478c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1473 | PC: 0x158694 | FDE: 0x0478e0 | Size: 256 bytes
// Khung tháo gỡ #1473 | Địa chỉ PC: 0x158694 | Địa chỉ FDE: 0x0478e0 | Kích thước: 256 bytes
//   0x158694: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x158698: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x15869c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x1586a0: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1473_0x158694(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x158694ULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0478e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1474 | PC: 0x1588a0 | FDE: 0x047908 | Size: 256 bytes
// Khung tháo gỡ #1474 | Địa chỉ PC: 0x1588a0 | Địa chỉ FDE: 0x047908 | Kích thước: 256 bytes
//   0x1588a0: D10243FF  sub      sp, sp, #0x90
//   0x1588a4: FD001BE8  str      d8, [sp, #0x30]
//   0x1588a8: F9001FFC  str      x28, [sp, #0x38]
//   0x1588ac: A9046BFB  stp      x27, x26, [sp, #0x40]
static inline uint64_t fde_func_1474_0x1588a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1588a0ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xfd001be8ULL) ^ 0x047908ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1475 | PC: 0x158c20 | FDE: 0x047938 | Size: 256 bytes
// Khung tháo gỡ #1475 | Địa chỉ PC: 0x158c20 | Địa chỉ FDE: 0x047938 | Kích thước: 256 bytes
//   0x158c20: D102C3FF  sub      sp, sp, #0xb0
//   0x158c24: FD0023E8  str      d8, [sp, #0x40]
//   0x158c28: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x158c2c: A90667FA  stp      x26, x25, [sp, #0x60]
static inline uint64_t fde_func_1475_0x158c20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x158c20ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xfd0023e8ULL) ^ 0x047938ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1476 | PC: 0x15921c | FDE: 0x047968 | Size: 256 bytes [_Z16make_json_objectP12LEPUSContextP8json_val]
// Khung tháo gỡ #1476 | Địa chỉ PC: 0x15921c | Địa chỉ FDE: 0x047968 | Kích thước: 256 bytes
//   0x15921c: D101C3FF  sub      sp, sp, #0x70
//   0x159220: F90013FA  str      x26, [sp, #0x20]
//   0x159224: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x159228: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_1476_0x15921c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15921cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013faULL) ^ 0x047968ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1477 | PC: 0x15958c | FDE: 0x047990 | Size: 256 bytes [LEPUS_DefinePropertyValueStr]
// Khung tháo gỡ #1477 | Địa chỉ PC: 0x15958c | Địa chỉ FDE: 0x047990 | Kích thước: 256 bytes
//   0x15958c: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x159590: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x159594: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x159598: 39458008  ldrb     w8, [x0, #0x160]
static inline uint64_t fde_func_1477_0x15958c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15958cULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x047990ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1478 | PC: 0x1596c8 | FDE: 0x0479b0 | Size: 256 bytes
// Khung tháo gỡ #1478 | Địa chỉ PC: 0x1596c8 | Địa chỉ FDE: 0x0479b0 | Kích thước: 256 bytes
//   0x1596c8: D101C3FF  sub      sp, sp, #0x70
//   0x1596cc: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x1596d0: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x1596d4: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1478_0x1596c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1596c8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x0479b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1479 | PC: 0x15a354 | FDE: 0x0479e0 | Size: 256 bytes
// Khung tháo gỡ #1479 | Địa chỉ PC: 0x15a354 | Địa chỉ FDE: 0x0479e0 | Kích thước: 256 bytes
//   0x15a354: D10483FF  sub      sp, sp, #0x120
//   0x15a358: A90C6FFC  stp      x28, x27, [sp, #0xc0]
//   0x15a35c: A90D67FA  stp      x26, x25, [sp, #0xd0]
//   0x15a360: A90E5FF8  stp      x24, x23, [sp, #0xe0]
static inline uint64_t fde_func_1479_0x15a354(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15a354ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa90c6ffcULL) ^ 0x0479e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1480 | PC: 0x15b7e4 | FDE: 0x047a10 | Size: 256 bytes
// Khung tháo gỡ #1480 | Địa chỉ PC: 0x15b7e4 | Địa chỉ FDE: 0x047a10 | Kích thước: 256 bytes
//   0x15b7e4: D103C3FF  sub      sp, sp, #0xf0
//   0x15b7e8: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x15b7ec: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x15b7f0: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_1480_0x15b7e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15b7e4ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa9096ffcULL) ^ 0x047a10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1481 | PC: 0x15d874 | FDE: 0x047a40 | Size: 256 bytes
// Khung tháo gỡ #1481 | Địa chỉ PC: 0x15d874 | Địa chỉ FDE: 0x047a40 | Kích thước: 256 bytes
//   0x15d874: D10783FF  sub      sp, sp, #0x1e0
//   0x15d878: A9186FFC  stp      x28, x27, [sp, #0x180]
//   0x15d87c: A91967FA  stp      x26, x25, [sp, #0x190]
//   0x15d880: A91A5FF8  stp      x24, x23, [sp, #0x1a0]
static inline uint64_t fde_func_1481_0x15d874(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15d874ULL ^ (static_cast<uint64_t>(0xd10783ffULL) << 13);
    acc = (acc + a1 + 0xa9186ffcULL) ^ 0x047a40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1482 | PC: 0x15e164 | FDE: 0x047a70 | Size: 256 bytes
// Khung tháo gỡ #1482 | Địa chỉ PC: 0x15e164 | Địa chỉ FDE: 0x047a70 | Kích thước: 256 bytes
//   0x15e164: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x15e168: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x15e16c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x15e170: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1482_0x15e164(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15e164ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x047a70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1483 | PC: 0x15eebc | FDE: 0x047aa0 | Size: 256 bytes [_Z12write_stringPhPKhmS1_]
// Khung tháo gỡ #1483 | Địa chỉ PC: 0x15eebc | Địa chỉ FDE: 0x047aa0 | Kích thước: 256 bytes
//   0x15eebc: D10203FF  sub      sp, sp, #0x80
//   0x15eec0: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x15eec4: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x15eec8: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1483_0x15eebc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15eebcULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x047aa0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1484 | PC: 0x15f4d8 | FDE: 0x047ad0 | Size: 256 bytes
// Khung tháo gỡ #1484 | Địa chỉ PC: 0x15f4d8 | Địa chỉ FDE: 0x047ad0 | Kích thước: 256 bytes
//   0x15f4d8: D10603FF  sub      sp, sp, #0x180
//   0x15f4dc: F900A3FC  str      x28, [sp, #0x140]
//   0x15f4e0: A9155BF7  stp      x23, x22, [sp, #0x150]
//   0x15f4e4: A91653F5  stp      x21, x20, [sp, #0x160]
static inline uint64_t fde_func_1484_0x15f4d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15f4d8ULL ^ (static_cast<uint64_t>(0xd10603ffULL) << 13);
    acc = (acc + a1 + 0xf900a3fcULL) ^ 0x047ad0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1485 | PC: 0x15f7a4 | FDE: 0x047af8 | Size: 256 bytes
// Khung tháo gỡ #1485 | Địa chỉ PC: 0x15f7a4 | Địa chỉ FDE: 0x047af8 | Kích thước: 256 bytes
//   0x15f7a4: D101C3FF  sub      sp, sp, #0x70
//   0x15f7a8: A9026BFB  stp      x27, x26, [sp, #0x20]
//   0x15f7ac: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x15f7b0: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_1485_0x15f7a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15f7a4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9026bfbULL) ^ 0x047af8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1486 | PC: 0x15fa0c | FDE: 0x047b20 | Size: 256 bytes
// Khung tháo gỡ #1486 | Địa chỉ PC: 0x15fa0c | Địa chỉ FDE: 0x047b20 | Kích thước: 256 bytes
//   0x15fa0c: D10283FF  sub      sp, sp, #0xa0
//   0x15fa10: F90033F8  str      x24, [sp, #0x60]
//   0x15fa14: A9075BF7  stp      x23, x22, [sp, #0x70]
//   0x15fa18: A90853F5  stp      x21, x20, [sp, #0x80]
static inline uint64_t fde_func_1486_0x15fa0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15fa0cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90033f8ULL) ^ 0x047b20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1487 | PC: 0x15fc50 | FDE: 0x047b48 | Size: 256 bytes
// Khung tháo gỡ #1487 | Địa chỉ PC: 0x15fc50 | Địa chỉ FDE: 0x047b48 | Kích thước: 256 bytes
//   0x15fc50: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x15fc54: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x15fc58: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x15fc5c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1487_0x15fc50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15fc50ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x047b48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1488 | PC: 0x160488 | FDE: 0x047b78 | Size: 256 bytes
// Khung tháo gỡ #1488 | Địa chỉ PC: 0x160488 | Địa chỉ FDE: 0x047b78 | Kích thước: 256 bytes
//   0x160488: D102C3FF  sub      sp, sp, #0xb0
//   0x16048c: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x160490: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x160494: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_1488_0x160488(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x160488ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x047b78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1489 | PC: 0x160920 | FDE: 0x047ba8 | Size: 256 bytes
// Khung tháo gỡ #1489 | Địa chỉ PC: 0x160920 | Địa chỉ FDE: 0x047ba8 | Kích thước: 256 bytes
//   0x160920: D10183FF  sub      sp, sp, #0x60
//   0x160924: F9000BFA  str      x26, [sp, #0x10]
//   0x160928: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x16092c: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_1489_0x160920(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x160920ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfaULL) ^ 0x047ba8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1490 | PC: 0x160c58 | FDE: 0x047bd0 | Size: 256 bytes
// Khung tháo gỡ #1490 | Địa chỉ PC: 0x160c58 | Địa chỉ FDE: 0x047bd0 | Kích thước: 256 bytes
//   0x160c58: D10403FF  sub      sp, sp, #0x100
//   0x160c5c: A90A6FFC  stp      x28, x27, [sp, #0xa0]
//   0x160c60: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x160c64: A90C5FF8  stp      x24, x23, [sp, #0xc0]
static inline uint64_t fde_func_1490_0x160c58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x160c58ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90a6ffcULL) ^ 0x047bd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1491 | PC: 0x1618f4 | FDE: 0x047c00 | Size: 256 bytes
// Khung tháo gỡ #1491 | Địa chỉ PC: 0x1618f4 | Địa chỉ FDE: 0x047c00 | Kích thước: 256 bytes
//   0x1618f4: D10103FF  sub      sp, sp, #0x40
//   0x1618f8: F9000BF6  str      x22, [sp, #0x10]
//   0x1618fc: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x161900: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1491_0x1618f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1618f4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x047c00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1492 | PC: 0x161ab0 | FDE: 0x047c20 | Size: 256 bytes
// Khung tháo gỡ #1492 | Địa chỉ PC: 0x161ab0 | Địa chỉ FDE: 0x047c20 | Kích thước: 256 bytes
//   0x161ab0: D10283FF  sub      sp, sp, #0xa0
//   0x161ab4: A9056BFB  stp      x27, x26, [sp, #0x50]
//   0x161ab8: A90663F9  stp      x25, x24, [sp, #0x60]
//   0x161abc: A9075BF7  stp      x23, x22, [sp, #0x70]
static inline uint64_t fde_func_1492_0x161ab0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x161ab0ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9056bfbULL) ^ 0x047c20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1493 | PC: 0x161f8c | FDE: 0x047c50 | Size: 256 bytes
// Khung tháo gỡ #1493 | Địa chỉ PC: 0x161f8c | Địa chỉ FDE: 0x047c50 | Kích thước: 256 bytes
//   0x161f8c: D10243FF  sub      sp, sp, #0x90
//   0x161f90: A90563F9  stp      x25, x24, [sp, #0x50]
//   0x161f94: A9065BF7  stp      x23, x22, [sp, #0x60]
//   0x161f98: A90753F5  stp      x21, x20, [sp, #0x70]
static inline uint64_t fde_func_1493_0x161f8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x161f8cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90563f9ULL) ^ 0x047c50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1494 | PC: 0x162174 | FDE: 0x047c78 | Size: 256 bytes
// Khung tháo gỡ #1494 | Địa chỉ PC: 0x162174 | Địa chỉ FDE: 0x047c78 | Kích thước: 256 bytes
//   0x162174: D102C3FF  sub      sp, sp, #0xb0
//   0x162178: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x16217c: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x162180: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_1494_0x162174(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x162174ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x047c78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1495 | PC: 0x162510 | FDE: 0x047ca8 | Size: 196 bytes
// Khung tháo gỡ #1495 | Địa chỉ PC: 0x162510 | Địa chỉ FDE: 0x047ca8 | Kích thước: 196 bytes
//   0x162510: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x162514: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x162518: F9400062  ldr      x2, [x3]
//   0x16251c: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1495_0x162510(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x162510ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x047ca8ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1496 | PC: 0x1625d4 | FDE: 0x047cc8 | Size: 256 bytes
// Khung tháo gỡ #1496 | Địa chỉ PC: 0x1625d4 | Địa chỉ FDE: 0x047cc8 | Kích thước: 256 bytes
//   0x1625d4: D10183FF  sub      sp, sp, #0x60
//   0x1625d8: F9001BF6  str      x22, [sp, #0x30]
//   0x1625dc: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x1625e0: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_1496_0x1625d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1625d4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf6ULL) ^ 0x047cc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1497 | PC: 0x1627f4 | FDE: 0x047ce8 | Size: 256 bytes
// Khung tháo gỡ #1497 | Địa chỉ PC: 0x1627f4 | Địa chỉ FDE: 0x047ce8 | Kích thước: 256 bytes
//   0x1627f4: D10643FF  sub      sp, sp, #0x190
//   0x1627f8: A9136FFC  stp      x28, x27, [sp, #0x130]
//   0x1627fc: A91467FA  stp      x26, x25, [sp, #0x140]
//   0x162800: A9155FF8  stp      x24, x23, [sp, #0x150]
static inline uint64_t fde_func_1497_0x1627f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1627f4ULL ^ (static_cast<uint64_t>(0xd10643ffULL) << 13);
    acc = (acc + a1 + 0xa9136ffcULL) ^ 0x047ce8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1498 | PC: 0x1645d4 | FDE: 0x047d18 | Size: 256 bytes
// Khung tháo gỡ #1498 | Địa chỉ PC: 0x1645d4 | Địa chỉ FDE: 0x047d18 | Kích thước: 256 bytes
//   0x1645d4: D101C3FF  sub      sp, sp, #0x70
//   0x1645d8: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x1645dc: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x1645e0: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1498_0x1645d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1645d4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x047d18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1499 | PC: 0x164cc8 | FDE: 0x047d48 | Size: 256 bytes
// Khung tháo gỡ #1499 | Địa chỉ PC: 0x164cc8 | Địa chỉ FDE: 0x047d48 | Kích thước: 256 bytes
//   0x164cc8: D10203FF  sub      sp, sp, #0x80
//   0x164ccc: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x164cd0: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x164cd4: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1499_0x164cc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x164cc8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x047d48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1500 | PC: 0x165408 | FDE: 0x047d78 | Size: 256 bytes
// Khung tháo gỡ #1500 | Địa chỉ PC: 0x165408 | Địa chỉ FDE: 0x047d78 | Kích thước: 256 bytes
//   0x165408: F81A0FFC  str      x28, [sp, #-0x60]!
//   0x16540c: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x165410: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x165414: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_1500_0x165408(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x165408ULL ^ (static_cast<uint64_t>(0xf81a0ffcULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x047d78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1501 | PC: 0x165b08 | FDE: 0x047da8 | Size: 256 bytes
// Khung tháo gỡ #1501 | Địa chỉ PC: 0x165b08 | Địa chỉ FDE: 0x047da8 | Kích thước: 256 bytes
//   0x165b08: D103C3FF  sub      sp, sp, #0xf0
//   0x165b0c: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x165b10: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x165b14: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_1501_0x165b08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x165b08ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa9096ffcULL) ^ 0x047da8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1502 | PC: 0x1667ac | FDE: 0x047dd8 | Size: 256 bytes
// Khung tháo gỡ #1502 | Địa chỉ PC: 0x1667ac | Địa chỉ FDE: 0x047dd8 | Kích thước: 256 bytes
//   0x1667ac: D10283FF  sub      sp, sp, #0xa0
//   0x1667b0: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x1667b4: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x1667b8: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1502_0x1667ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1667acULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x047dd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1503 | PC: 0x166cc4 | FDE: 0x047e08 | Size: 136 bytes [LEPUS_GetPropertyStr]
// Khung tháo gỡ #1503 | Địa chỉ PC: 0x166cc4 | Địa chỉ FDE: 0x047e08 | Kích thước: 136 bytes
//   0x166cc4: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x166cc8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x166ccc: 39458008  ldrb     w8, [x0, #0x160]
//   0x166cd0: AA0203F5  mov      x21, x2
static inline uint64_t fde_func_1503_0x166cc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x166cc4ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x047e08ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1504 | PC: 0x166d4c | FDE: 0x047e28 | Size: 256 bytes
// Khung tháo gỡ #1504 | Địa chỉ PC: 0x166d4c | Địa chỉ FDE: 0x047e28 | Kích thước: 256 bytes
//   0x166d4c: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x166d50: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x166d54: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x166d58: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1504_0x166d4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x166d4cULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x047e28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1505 | PC: 0x166ecc | FDE: 0x047e50 | Size: 256 bytes
// Khung tháo gỡ #1505 | Địa chỉ PC: 0x166ecc | Địa chỉ FDE: 0x047e50 | Kích thước: 256 bytes
//   0x166ecc: A9BB6BFB  stp      x27, x26, [sp, #-0x50]!
//   0x166ed0: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x166ed4: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x166ed8: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1505_0x166ecc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x166eccULL ^ (static_cast<uint64_t>(0xa9bb6bfbULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x047e50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1506 | PC: 0x1674e0 | FDE: 0x047e78 | Size: 256 bytes
// Khung tháo gỡ #1506 | Địa chỉ PC: 0x1674e0 | Địa chỉ FDE: 0x047e78 | Kích thước: 256 bytes
//   0x1674e0: D10143FF  sub      sp, sp, #0x50
//   0x1674e4: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x1674e8: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x1674ec: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1506_0x1674e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1674e0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x047e78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1507 | PC: 0x167738 | FDE: 0x047ea0 | Size: 256 bytes
// Khung tháo gỡ #1507 | Địa chỉ PC: 0x167738 | Địa chỉ FDE: 0x047ea0 | Kích thước: 256 bytes
//   0x167738: D10243FF  sub      sp, sp, #0x90
//   0x16773c: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x167740: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x167744: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1507_0x167738(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x167738ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x047ea0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1508 | PC: 0x167920 | FDE: 0x047ed0 | Size: 256 bytes
// Khung tháo gỡ #1508 | Địa chỉ PC: 0x167920 | Địa chỉ FDE: 0x047ed0 | Kích thước: 256 bytes
//   0x167920: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x167924: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x167928: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x16792c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1508_0x167920(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x167920ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x047ed0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1509 | PC: 0x167aa4 | FDE: 0x047ef8 | Size: 252 bytes
// Khung tháo gỡ #1509 | Địa chỉ PC: 0x167aa4 | Địa chỉ FDE: 0x047ef8 | Kích thước: 252 bytes
//   0x167aa4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x167aa8: B9401808  ldr      w8, [x0, #0x18]
//   0x167aac: AA0003F3  mov      x19, x0
//   0x167ab0: 3100D51F  cmn      w8, #0x35
static inline uint64_t fde_func_1509_0x167aa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x167aa4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xb9401808ULL) ^ 0x047ef8ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1510 | PC: 0x167ba0 | FDE: 0x047f10 | Size: 256 bytes
// Khung tháo gỡ #1510 | Địa chỉ PC: 0x167ba0 | Địa chỉ FDE: 0x047f10 | Kích thước: 256 bytes
//   0x167ba0: F81A0FFC  str      x28, [sp, #-0x60]!
//   0x167ba4: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x167ba8: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x167bac: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_1510_0x167ba0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x167ba0ULL ^ (static_cast<uint64_t>(0xf81a0ffcULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x047f10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1511 | PC: 0x167fc8 | FDE: 0x047f40 | Size: 232 bytes [_Z17get_caller_stringP13JSFunctionDef]
// Khung tháo gỡ #1511 | Địa chỉ PC: 0x167fc8 | Địa chỉ FDE: 0x047f40 | Kích thước: 232 bytes
//   0x167fc8: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x167fcc: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x167fd0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x167fd4: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1511_0x167fc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x167fc8ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x047f40ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1512 | PC: 0x1680b0 | FDE: 0x047f70 | Size: 256 bytes
// Khung tháo gỡ #1512 | Địa chỉ PC: 0x1680b0 | Địa chỉ FDE: 0x047f70 | Kích thước: 256 bytes
//   0x1680b0: D10343FF  sub      sp, sp, #0xd0
//   0x1680b4: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x1680b8: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x1680bc: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_1512_0x1680b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1680b0ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9076ffcULL) ^ 0x047f70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1513 | PC: 0x169294 | FDE: 0x047fa0 | Size: 256 bytes
// Khung tháo gỡ #1513 | Địa chỉ PC: 0x169294 | Địa chỉ FDE: 0x047fa0 | Kích thước: 256 bytes
//   0x169294: D10143FF  sub      sp, sp, #0x50
//   0x169298: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x16929c: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x1692a0: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1513_0x169294(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x169294ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x047fa0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1514 | PC: 0x1693a8 | FDE: 0x047fc8 | Size: 256 bytes
// Khung tháo gỡ #1514 | Địa chỉ PC: 0x1693a8 | Địa chỉ FDE: 0x047fc8 | Kích thước: 256 bytes
//   0x1693a8: D101C3FF  sub      sp, sp, #0x70
//   0x1693ac: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x1693b0: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x1693b4: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1514_0x1693a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1693a8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x047fc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1515 | PC: 0x169560 | FDE: 0x047ff8 | Size: 256 bytes
// Khung tháo gỡ #1515 | Địa chỉ PC: 0x169560 | Địa chỉ FDE: 0x047ff8 | Kích thước: 256 bytes
//   0x169560: D10543FF  sub      sp, sp, #0x150
//   0x169564: A90F6FFC  stp      x28, x27, [sp, #0xf0]
//   0x169568: A91067FA  stp      x26, x25, [sp, #0x100]
//   0x16956c: A9115FF8  stp      x24, x23, [sp, #0x110]
static inline uint64_t fde_func_1515_0x169560(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x169560ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa90f6ffcULL) ^ 0x047ff8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Shard 4 Dispatcher / Bộ điều phối phân mảnh 4
uint64_t execute_fde_shard_4(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 1137: return fde_func_1137_0x1080f0(a0, a1);
        case 1138: return fde_func_1138_0x108aa0(a0, a1);
        case 1139: return fde_func_1139_0x108adc(a0, a1);
        case 1140: return fde_func_1140_0x108be0(a0, a1);
        case 1141: return fde_func_1141_0x108e54(a0, a1);
        case 1142: return fde_func_1142_0x109080(a0, a1);
        case 1143: return fde_func_1143_0x109218(a0, a1);
        case 1144: return fde_func_1144_0x109c0c(a0, a1);
        case 1145: return fde_func_1145_0x109d64(a0, a1);
        case 1146: return fde_func_1146_0x109d70(a0, a1);
        case 1147: return fde_func_1147_0x10a264(a0, a1);
        case 1148: return fde_func_1148_0x10a668(a0, a1);
        case 1149: return fde_func_1149_0x10a7f8(a0, a1);
        case 1150: return fde_func_1150_0x10a960(a0, a1);
        case 1151: return fde_func_1151_0x10ad8c(a0, a1);
        case 1152: return fde_func_1152_0x10aea4(a0, a1);
        case 1153: return fde_func_1153_0x10b054(a0, a1);
        case 1154: return fde_func_1154_0x10b180(a0, a1);
        case 1155: return fde_func_1155_0x10b6d4(a0, a1);
        case 1156: return fde_func_1156_0x10b814(a0, a1);
        case 1157: return fde_func_1157_0x10b984(a0, a1);
        case 1158: return fde_func_1158_0x10bbf8(a0, a1);
        case 1159: return fde_func_1159_0x10bde8(a0, a1);
        case 1160: return fde_func_1160_0x10bfc8(a0, a1);
        case 1161: return fde_func_1161_0x10c1ec(a0, a1);
        case 1162: return fde_func_1162_0x10ca70(a0, a1);
        case 1163: return fde_func_1163_0x10cf50(a0, a1);
        case 1164: return fde_func_1164_0x10d058(a0, a1);
        case 1165: return fde_func_1165_0x10d1d0(a0, a1);
        case 1166: return fde_func_1166_0x10d408(a0, a1);
        case 1167: return fde_func_1167_0x10da40(a0, a1);
        case 1168: return fde_func_1168_0x10e2c8(a0, a1);
        case 1169: return fde_func_1169_0x10e70c(a0, a1);
        case 1170: return fde_func_1170_0x10e820(a0, a1);
        case 1171: return fde_func_1171_0x10eb08(a0, a1);
        case 1172: return fde_func_1172_0x10f618(a0, a1);
        case 1173: return fde_func_1173_0x10fbbc(a0, a1);
        case 1174: return fde_func_1174_0x10fd24(a0, a1);
        case 1175: return fde_func_1175_0x1100a4(a0, a1);
        case 1176: return fde_func_1176_0x110414(a0, a1);
        case 1177: return fde_func_1177_0x110598(a0, a1);
        case 1178: return fde_func_1178_0x11076c(a0, a1);
        case 1179: return fde_func_1179_0x110aa8(a0, a1);
        case 1180: return fde_func_1180_0x110b64(a0, a1);
        case 1181: return fde_func_1181_0x110ec0(a0, a1);
        case 1182: return fde_func_1182_0x110fa4(a0, a1);
        case 1183: return fde_func_1183_0x1118e8(a0, a1);
        case 1184: return fde_func_1184_0x111ce4(a0, a1);
        case 1185: return fde_func_1185_0x111efc(a0, a1);
        case 1186: return fde_func_1186_0x1121a8(a0, a1);
        case 1187: return fde_func_1187_0x112330(a0, a1);
        case 1188: return fde_func_1188_0x1125a8(a0, a1);
        case 1189: return fde_func_1189_0x1128dc(a0, a1);
        case 1190: return fde_func_1190_0x112ab0(a0, a1);
        case 1191: return fde_func_1191_0x113028(a0, a1);
        case 1192: return fde_func_1192_0x113558(a0, a1);
        case 1193: return fde_func_1193_0x113798(a0, a1);
        case 1194: return fde_func_1194_0x11387c(a0, a1);
        case 1195: return fde_func_1195_0x11391c(a0, a1);
        case 1196: return fde_func_1196_0x113ac0(a0, a1);
        case 1197: return fde_func_1197_0x113cc0(a0, a1);
        case 1198: return fde_func_1198_0x113ea4(a0, a1);
        case 1199: return fde_func_1199_0x114320(a0, a1);
        case 1200: return fde_func_1200_0x114a70(a0, a1);
        case 1201: return fde_func_1201_0x114b14(a0, a1);
        case 1202: return fde_func_1202_0x114f08(a0, a1);
        case 1203: return fde_func_1203_0x115204(a0, a1);
        case 1204: return fde_func_1204_0x11591c(a0, a1);
        case 1205: return fde_func_1205_0x115c34(a0, a1);
        case 1206: return fde_func_1206_0x115d7c(a0, a1);
        case 1207: return fde_func_1207_0x116128(a0, a1);
        case 1208: return fde_func_1208_0x1161f4(a0, a1);
        case 1209: return fde_func_1209_0x116520(a0, a1);
        case 1210: return fde_func_1210_0x117114(a0, a1);
        case 1211: return fde_func_1211_0x1175e4(a0, a1);
        case 1212: return fde_func_1212_0x117744(a0, a1);
        case 1213: return fde_func_1213_0x117a40(a0, a1);
        case 1214: return fde_func_1214_0x1180ec(a0, a1);
        case 1215: return fde_func_1215_0x11837c(a0, a1);
        case 1216: return fde_func_1216_0x118748(a0, a1);
        case 1217: return fde_func_1217_0x118c34(a0, a1);
        case 1218: return fde_func_1218_0x119544(a0, a1);
        case 1219: return fde_func_1219_0x11968c(a0, a1);
        case 1220: return fde_func_1220_0x1199f8(a0, a1);
        case 1221: return fde_func_1221_0x119b84(a0, a1);
        case 1222: return fde_func_1222_0x119d5c(a0, a1);
        case 1223: return fde_func_1223_0x119ec8(a0, a1);
        case 1224: return fde_func_1224_0x119f48(a0, a1);
        case 1225: return fde_func_1225_0x11a040(a0, a1);
        case 1226: return fde_func_1226_0x11a108(a0, a1);
        case 1227: return fde_func_1227_0x11a1f0(a0, a1);
        case 1228: return fde_func_1228_0x11a390(a0, a1);
        case 1229: return fde_func_1229_0x11a42c(a0, a1);
        case 1230: return fde_func_1230_0x11a504(a0, a1);
        case 1231: return fde_func_1231_0x11a598(a0, a1);
        case 1232: return fde_func_1232_0x11a5a4(a0, a1);
        case 1233: return fde_func_1233_0x11a5d8(a0, a1);
        case 1234: return fde_func_1234_0x11a5e4(a0, a1);
        case 1235: return fde_func_1235_0x11a648(a0, a1);
        case 1236: return fde_func_1236_0x11a67c(a0, a1);
        case 1237: return fde_func_1237_0x11a6f8(a0, a1);
        case 1238: return fde_func_1238_0x11a708(a0, a1);
        case 1239: return fde_func_1239_0x11a74c(a0, a1);
        case 1240: return fde_func_1240_0x11a938(a0, a1);
        case 1241: return fde_func_1241_0x11aa20(a0, a1);
        case 1242: return fde_func_1242_0x11ab20(a0, a1);
        case 1243: return fde_func_1243_0x11ab34(a0, a1);
        case 1244: return fde_func_1244_0x11ab64(a0, a1);
        case 1245: return fde_func_1245_0x11ab78(a0, a1);
        case 1246: return fde_func_1246_0x11ab8c(a0, a1);
        case 1247: return fde_func_1247_0x11afd8(a0, a1);
        case 1248: return fde_func_1248_0x11b180(a0, a1);
        case 1249: return fde_func_1249_0x11b5c4(a0, a1);
        case 1250: return fde_func_1250_0x11b6cc(a0, a1);
        case 1251: return fde_func_1251_0x11ba34(a0, a1);
        case 1252: return fde_func_1252_0x11bd54(a0, a1);
        case 1253: return fde_func_1253_0x11c250(a0, a1);
        case 1254: return fde_func_1254_0x11caa4(a0, a1);
        case 1255: return fde_func_1255_0x11cdd0(a0, a1);
        case 1256: return fde_func_1256_0x11d098(a0, a1);
        case 1257: return fde_func_1257_0x11d2f4(a0, a1);
        case 1258: return fde_func_1258_0x11d5a8(a0, a1);
        case 1259: return fde_func_1259_0x11d6e8(a0, a1);
        case 1260: return fde_func_1260_0x11d9dc(a0, a1);
        case 1261: return fde_func_1261_0x11db48(a0, a1);
        case 1262: return fde_func_1262_0x11dc70(a0, a1);
        case 1263: return fde_func_1263_0x11dcdc(a0, a1);
        case 1264: return fde_func_1264_0x11ddbc(a0, a1);
        case 1265: return fde_func_1265_0x11dddc(a0, a1);
        case 1266: return fde_func_1266_0x11df28(a0, a1);
        case 1267: return fde_func_1267_0x11e00c(a0, a1);
        case 1268: return fde_func_1268_0x11e28c(a0, a1);
        case 1269: return fde_func_1269_0x11e320(a0, a1);
        case 1270: return fde_func_1270_0x11e4a4(a0, a1);
        case 1271: return fde_func_1271_0x11e538(a0, a1);
        case 1272: return fde_func_1272_0x11e620(a0, a1);
        case 1273: return fde_func_1273_0x11e644(a0, a1);
        case 1274: return fde_func_1274_0x11e74c(a0, a1);
        case 1275: return fde_func_1275_0x11e7b0(a0, a1);
        case 1276: return fde_func_1276_0x11e894(a0, a1);
        case 1277: return fde_func_1277_0x11e8c4(a0, a1);
        case 1278: return fde_func_1278_0x11eb4c(a0, a1);
        case 1279: return fde_func_1279_0x11ebe4(a0, a1);
        case 1280: return fde_func_1280_0x11ed44(a0, a1);
        case 1281: return fde_func_1281_0x11ed70(a0, a1);
        case 1282: return fde_func_1282_0x11ee6c(a0, a1);
        case 1283: return fde_func_1283_0x11f010(a0, a1);
        case 1284: return fde_func_1284_0x11f070(a0, a1);
        case 1285: return fde_func_1285_0x11f0fc(a0, a1);
        case 1286: return fde_func_1286_0x11f130(a0, a1);
        case 1287: return fde_func_1287_0x11f140(a0, a1);
        case 1288: return fde_func_1288_0x11f4c0(a0, a1);
        case 1289: return fde_func_1289_0x11f508(a0, a1);
        case 1290: return fde_func_1290_0x11f55c(a0, a1);
        case 1291: return fde_func_1291_0x11f580(a0, a1);
        case 1292: return fde_func_1292_0x11f634(a0, a1);
        case 1293: return fde_func_1293_0x11f680(a0, a1);
        case 1294: return fde_func_1294_0x11f6b0(a0, a1);
        case 1295: return fde_func_1295_0x11f6b8(a0, a1);
        case 1296: return fde_func_1296_0x11f6c0(a0, a1);
        case 1297: return fde_func_1297_0x11f6c8(a0, a1);
        case 1298: return fde_func_1298_0x11f864(a0, a1);
        case 1299: return fde_func_1299_0x11f878(a0, a1);
        case 1300: return fde_func_1300_0x11fa7c(a0, a1);
        case 1301: return fde_func_1301_0x11fb2c(a0, a1);
        case 1302: return fde_func_1302_0x11fc8c(a0, a1);
        case 1303: return fde_func_1303_0x11fd5c(a0, a1);
        case 1304: return fde_func_1304_0x11fdc4(a0, a1);
        case 1305: return fde_func_1305_0x11fe9c(a0, a1);
        case 1306: return fde_func_1306_0x120498(a0, a1);
        case 1307: return fde_func_1307_0x120688(a0, a1);
        case 1308: return fde_func_1308_0x120bd4(a0, a1);
        case 1309: return fde_func_1309_0x120d20(a0, a1);
        case 1310: return fde_func_1310_0x120dec(a0, a1);
        case 1311: return fde_func_1311_0x120f78(a0, a1);
        case 1312: return fde_func_1312_0x121398(a0, a1);
        case 1313: return fde_func_1313_0x123d50(a0, a1);
        case 1314: return fde_func_1314_0x124824(a0, a1);
        case 1315: return fde_func_1315_0x1248c8(a0, a1);
        case 1316: return fde_func_1316_0x124ac4(a0, a1);
        case 1317: return fde_func_1317_0x124ce4(a0, a1);
        case 1318: return fde_func_1318_0x125018(a0, a1);
        case 1319: return fde_func_1319_0x125104(a0, a1);
        case 1320: return fde_func_1320_0x125354(a0, a1);
        case 1321: return fde_func_1321_0x1256e4(a0, a1);
        case 1322: return fde_func_1322_0x125c18(a0, a1);
        case 1323: return fde_func_1323_0x125d24(a0, a1);
        case 1324: return fde_func_1324_0x125ebc(a0, a1);
        case 1325: return fde_func_1325_0x125ec0(a0, a1);
        case 1326: return fde_func_1326_0x1260c8(a0, a1);
        case 1327: return fde_func_1327_0x12619c(a0, a1);
        case 1328: return fde_func_1328_0x126310(a0, a1);
        case 1329: return fde_func_1329_0x1265d4(a0, a1);
        case 1330: return fde_func_1330_0x126850(a0, a1);
        case 1331: return fde_func_1331_0x126b24(a0, a1);
        case 1332: return fde_func_1332_0x126bf4(a0, a1);
        case 1333: return fde_func_1333_0x127014(a0, a1);
        case 1334: return fde_func_1334_0x1271fc(a0, a1);
        case 1335: return fde_func_1335_0x12730c(a0, a1);
        case 1336: return fde_func_1336_0x12761c(a0, a1);
        case 1337: return fde_func_1337_0x127edc(a0, a1);
        case 1338: return fde_func_1338_0x128578(a0, a1);
        case 1339: return fde_func_1339_0x129778(a0, a1);
        case 1340: return fde_func_1340_0x129c00(a0, a1);
        case 1341: return fde_func_1341_0x12a178(a0, a1);
        case 1342: return fde_func_1342_0x12a610(a0, a1);
        case 1343: return fde_func_1343_0x12ab48(a0, a1);
        case 1344: return fde_func_1344_0x12ad70(a0, a1);
        case 1345: return fde_func_1345_0x12c920(a0, a1);
        case 1346: return fde_func_1346_0x12cc68(a0, a1);
        case 1347: return fde_func_1347_0x12cdc0(a0, a1);
        case 1348: return fde_func_1348_0x12cfa4(a0, a1);
        case 1349: return fde_func_1349_0x12d308(a0, a1);
        case 1350: return fde_func_1350_0x12d318(a0, a1);
        case 1351: return fde_func_1351_0x12dc6c(a0, a1);
        case 1352: return fde_func_1352_0x12e038(a0, a1);
        case 1353: return fde_func_1353_0x12e2d8(a0, a1);
        case 1354: return fde_func_1354_0x13106c(a0, a1);
        case 1355: return fde_func_1355_0x131140(a0, a1);
        case 1356: return fde_func_1356_0x1313b4(a0, a1);
        case 1357: return fde_func_1357_0x13166c(a0, a1);
        case 1358: return fde_func_1358_0x131920(a0, a1);
        case 1359: return fde_func_1359_0x135cf0(a0, a1);
        case 1360: return fde_func_1360_0x135f30(a0, a1);
        case 1361: return fde_func_1361_0x136144(a0, a1);
        case 1362: return fde_func_1362_0x136da8(a0, a1);
        case 1363: return fde_func_1363_0x136ef0(a0, a1);
        case 1364: return fde_func_1364_0x136f7c(a0, a1);
        case 1365: return fde_func_1365_0x138354(a0, a1);
        case 1366: return fde_func_1366_0x138bfc(a0, a1);
        case 1367: return fde_func_1367_0x138da4(a0, a1);
        case 1368: return fde_func_1368_0x1397e8(a0, a1);
        case 1369: return fde_func_1369_0x13998c(a0, a1);
        case 1370: return fde_func_1370_0x139cb8(a0, a1);
        case 1371: return fde_func_1371_0x139d08(a0, a1);
        case 1372: return fde_func_1372_0x13a1d0(a0, a1);
        case 1373: return fde_func_1373_0x13a54c(a0, a1);
        case 1374: return fde_func_1374_0x13a5d8(a0, a1);
        case 1375: return fde_func_1375_0x13a680(a0, a1);
        case 1376: return fde_func_1376_0x13a9bc(a0, a1);
        case 1377: return fde_func_1377_0x13b2fc(a0, a1);
        case 1378: return fde_func_1378_0x13b4bc(a0, a1);
        case 1379: return fde_func_1379_0x13ba88(a0, a1);
        case 1380: return fde_func_1380_0x13bd8c(a0, a1);
        case 1381: return fde_func_1381_0x13ca70(a0, a1);
        case 1382: return fde_func_1382_0x13cbb4(a0, a1);
        case 1383: return fde_func_1383_0x13cd68(a0, a1);
        case 1384: return fde_func_1384_0x13ce98(a0, a1);
        case 1385: return fde_func_1385_0x13cfb8(a0, a1);
        case 1386: return fde_func_1386_0x13cfdc(a0, a1);
        case 1387: return fde_func_1387_0x13d014(a0, a1);
        case 1388: return fde_func_1388_0x13d1d8(a0, a1);
        case 1389: return fde_func_1389_0x13d258(a0, a1);
        case 1390: return fde_func_1390_0x13d29c(a0, a1);
        case 1391: return fde_func_1391_0x13d394(a0, a1);
        case 1392: return fde_func_1392_0x13d3f0(a0, a1);
        case 1393: return fde_func_1393_0x13d44c(a0, a1);
        case 1394: return fde_func_1394_0x13d63c(a0, a1);
        case 1395: return fde_func_1395_0x13da5c(a0, a1);
        case 1396: return fde_func_1396_0x13db10(a0, a1);
        case 1397: return fde_func_1397_0x13dbd0(a0, a1);
        case 1398: return fde_func_1398_0x13dc90(a0, a1);
        case 1399: return fde_func_1399_0x13e050(a0, a1);
        case 1400: return fde_func_1400_0x13e450(a0, a1);
        case 1401: return fde_func_1401_0x13f8a4(a0, a1);
        case 1402: return fde_func_1402_0x13faf8(a0, a1);
        case 1403: return fde_func_1403_0x13fcb8(a0, a1);
        case 1404: return fde_func_1404_0x140710(a0, a1);
        case 1405: return fde_func_1405_0x140924(a0, a1);
        case 1406: return fde_func_1406_0x140b54(a0, a1);
        case 1407: return fde_func_1407_0x140bc4(a0, a1);
        case 1408: return fde_func_1408_0x141190(a0, a1);
        case 1409: return fde_func_1409_0x14121c(a0, a1);
        case 1410: return fde_func_1410_0x14134c(a0, a1);
        case 1411: return fde_func_1411_0x141728(a0, a1);
        case 1412: return fde_func_1412_0x142604(a0, a1);
        case 1413: return fde_func_1413_0x1430ec(a0, a1);
        case 1414: return fde_func_1414_0x14375c(a0, a1);
        case 1415: return fde_func_1415_0x143b7c(a0, a1);
        case 1416: return fde_func_1416_0x143d94(a0, a1);
        case 1417: return fde_func_1417_0x144254(a0, a1);
        case 1418: return fde_func_1418_0x1445ec(a0, a1);
        case 1419: return fde_func_1419_0x144a5c(a0, a1);
        case 1420: return fde_func_1420_0x144f8c(a0, a1);
        case 1421: return fde_func_1421_0x1458a4(a0, a1);
        case 1422: return fde_func_1422_0x145b10(a0, a1);
        case 1423: return fde_func_1423_0x145f0c(a0, a1);
        case 1424: return fde_func_1424_0x14607c(a0, a1);
        case 1425: return fde_func_1425_0x14620c(a0, a1);
        case 1426: return fde_func_1426_0x146390(a0, a1);
        case 1427: return fde_func_1427_0x146500(a0, a1);
        case 1428: return fde_func_1428_0x146840(a0, a1);
        case 1429: return fde_func_1429_0x146914(a0, a1);
        case 1430: return fde_func_1430_0x146fdc(a0, a1);
        case 1431: return fde_func_1431_0x147d60(a0, a1);
        case 1432: return fde_func_1432_0x1482a8(a0, a1);
        case 1433: return fde_func_1433_0x148ab4(a0, a1);
        case 1434: return fde_func_1434_0x148d70(a0, a1);
        case 1435: return fde_func_1435_0x149050(a0, a1);
        case 1436: return fde_func_1436_0x1492f0(a0, a1);
        case 1437: return fde_func_1437_0x149534(a0, a1);
        case 1438: return fde_func_1438_0x149888(a0, a1);
        case 1439: return fde_func_1439_0x14998c(a0, a1);
        case 1440: return fde_func_1440_0x149ea4(a0, a1);
        case 1441: return fde_func_1441_0x14a128(a0, a1);
        case 1442: return fde_func_1442_0x14a3a0(a0, a1);
        case 1443: return fde_func_1443_0x14a434(a0, a1);
        case 1444: return fde_func_1444_0x14ac78(a0, a1);
        case 1445: return fde_func_1445_0x14b00c(a0, a1);
        case 1446: return fde_func_1446_0x14b32c(a0, a1);
        case 1447: return fde_func_1447_0x14b428(a0, a1);
        case 1448: return fde_func_1448_0x14b9f0(a0, a1);
        case 1449: return fde_func_1449_0x14c2ec(a0, a1);
        case 1450: return fde_func_1450_0x14c630(a0, a1);
        case 1451: return fde_func_1451_0x14d424(a0, a1);
        case 1452: return fde_func_1452_0x14d76c(a0, a1);
        case 1453: return fde_func_1453_0x14dcdc(a0, a1);
        case 1454: return fde_func_1454_0x14e210(a0, a1);
        case 1455: return fde_func_1455_0x14e3dc(a0, a1);
        case 1456: return fde_func_1456_0x14e8e4(a0, a1);
        case 1457: return fde_func_1457_0x14ece0(a0, a1);
        case 1458: return fde_func_1458_0x14ff20(a0, a1);
        case 1459: return fde_func_1459_0x1505c8(a0, a1);
        case 1460: return fde_func_1460_0x1508bc(a0, a1);
        case 1461: return fde_func_1461_0x150f4c(a0, a1);
        case 1462: return fde_func_1462_0x152e74(a0, a1);
        case 1463: return fde_func_1463_0x153430(a0, a1);
        case 1464: return fde_func_1464_0x153860(a0, a1);
        case 1465: return fde_func_1465_0x153d28(a0, a1);
        case 1466: return fde_func_1466_0x15435c(a0, a1);
        case 1467: return fde_func_1467_0x1548a0(a0, a1);
        case 1468: return fde_func_1468_0x1560dc(a0, a1);
        case 1469: return fde_func_1469_0x1561d8(a0, a1);
        case 1470: return fde_func_1470_0x1567c4(a0, a1);
        case 1471: return fde_func_1471_0x157e4c(a0, a1);
        case 1472: return fde_func_1472_0x15857c(a0, a1);
        case 1473: return fde_func_1473_0x158694(a0, a1);
        case 1474: return fde_func_1474_0x1588a0(a0, a1);
        case 1475: return fde_func_1475_0x158c20(a0, a1);
        case 1476: return fde_func_1476_0x15921c(a0, a1);
        case 1477: return fde_func_1477_0x15958c(a0, a1);
        case 1478: return fde_func_1478_0x1596c8(a0, a1);
        case 1479: return fde_func_1479_0x15a354(a0, a1);
        case 1480: return fde_func_1480_0x15b7e4(a0, a1);
        case 1481: return fde_func_1481_0x15d874(a0, a1);
        case 1482: return fde_func_1482_0x15e164(a0, a1);
        case 1483: return fde_func_1483_0x15eebc(a0, a1);
        case 1484: return fde_func_1484_0x15f4d8(a0, a1);
        case 1485: return fde_func_1485_0x15f7a4(a0, a1);
        case 1486: return fde_func_1486_0x15fa0c(a0, a1);
        case 1487: return fde_func_1487_0x15fc50(a0, a1);
        case 1488: return fde_func_1488_0x160488(a0, a1);
        case 1489: return fde_func_1489_0x160920(a0, a1);
        case 1490: return fde_func_1490_0x160c58(a0, a1);
        case 1491: return fde_func_1491_0x1618f4(a0, a1);
        case 1492: return fde_func_1492_0x161ab0(a0, a1);
        case 1493: return fde_func_1493_0x161f8c(a0, a1);
        case 1494: return fde_func_1494_0x162174(a0, a1);
        case 1495: return fde_func_1495_0x162510(a0, a1);
        case 1496: return fde_func_1496_0x1625d4(a0, a1);
        case 1497: return fde_func_1497_0x1627f4(a0, a1);
        case 1498: return fde_func_1498_0x1645d4(a0, a1);
        case 1499: return fde_func_1499_0x164cc8(a0, a1);
        case 1500: return fde_func_1500_0x165408(a0, a1);
        case 1501: return fde_func_1501_0x165b08(a0, a1);
        case 1502: return fde_func_1502_0x1667ac(a0, a1);
        case 1503: return fde_func_1503_0x166cc4(a0, a1);
        case 1504: return fde_func_1504_0x166d4c(a0, a1);
        case 1505: return fde_func_1505_0x166ecc(a0, a1);
        case 1506: return fde_func_1506_0x1674e0(a0, a1);
        case 1507: return fde_func_1507_0x167738(a0, a1);
        case 1508: return fde_func_1508_0x167920(a0, a1);
        case 1509: return fde_func_1509_0x167aa4(a0, a1);
        case 1510: return fde_func_1510_0x167ba0(a0, a1);
        case 1511: return fde_func_1511_0x167fc8(a0, a1);
        case 1512: return fde_func_1512_0x1680b0(a0, a1);
        case 1513: return fde_func_1513_0x169294(a0, a1);
        case 1514: return fde_func_1514_0x1693a8(a0, a1);
        case 1515: return fde_func_1515_0x169560(a0, a1);
        default: return 0ULL;
    }
}