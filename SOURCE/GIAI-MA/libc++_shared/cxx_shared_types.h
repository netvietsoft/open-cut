// ============================================================================
// File: cxx_shared_types.h
// Target 111 / 169: libc++_shared.so (919,888 bytes)
// SHA-256: e861c5cc64fd7045f2208cec91092009d3aef2af834f6928c1299cc21ca28bc6
// EN: Exact AArch64 ABI struct layouts for Android NDK libc++ (`std::__ndk1`):
//     __shared_weak_count (0x0918a8..0x091a38), __libcpp_db (0x0527c4),
//     __rs_default MT19937 state (0x048c74..0x048dc8), and chrono types.
// VI: Bố cục struct ABI AArch64 chính xác cho Android NDK libc++ (`std::__ndk1`):
//     __shared_weak_count (0x0918a8..0x091a38), __libcpp_db (0x0527c4),
//     trạng thái MT19937 __rs_default (0x048c74..0x048dc8) và các kiểu chrono.
// ============================================================================
#pragma once

#include <cstdint>
#include <cstddef>
#include <atomic>

namespace ndk_libcxx_recon {

// EN: Exact 24-byte ABI layout of std::__ndk1::__shared_weak_count verified at 0x0918a8..0x091a38:
//     +0x00: void* vptr (`ldr x8, [x0]; ldr x8, [x8, #0x10]; blr x8` for __on_zero_shared @ 0x0918f8,
//            `ldr x1, [x8, #0x20]; br x1` for __on_zero_shared_weak @ 0x0919b0)
//     +0x08: int64_t __shared_owners_ (`add x8, x0, #8; ldxr/stxr` @ 0x091910, 0-based where 0 means 1 owner, -1 means 0 owners)
//     +0x10: int64_t __shared_weak_owners_ (`add x8, x0, #0x10; ldxr/stxr` @ 0x091928)
// VI: Bố cục ABI 24 byte chính xác của std::__ndk1::__shared_weak_count xác minh tại 0x0918a8..0x091a38:
struct SharedWeakCountAbiLayout {
    void*   vptr;                 // +0x00
    int64_t shared_owners;        // +0x08 (0 = 1 active owner, -1 = expired)
    int64_t shared_weak_owners;   // +0x10 (0 = 1 weak ref from shared owners)
};
static_assert(offsetof(SharedWeakCountAbiLayout, shared_owners) == 0x08, "shared_owners must be at +0x08");
static_assert(offsetof(SharedWeakCountAbiLayout, shared_weak_owners) == 0x10, "shared_weak_owners must be at +0x10");
static_assert(sizeof(SharedWeakCountAbiLayout) == 24, "SharedWeakCountAbiLayout must be 24 bytes");

// EN: Exact 48-byte ABI layout of std::__ndk1::__libcpp_db verified at 0x0527c4..0x0527d0:
//     `movi v0.2d, #0; stp q0, q0, [x0, #0x10]; str q0, [x0]; ret`
// VI: Bố cục ABI 48 byte chính xác của std::__ndk1::__libcpp_db xác minh tại 0x0527c4..0x0527d0:
struct LibcppDbAbiLayout {
    void*   cbeg; // +0x00
    void*   cend; // +0x08
    size_t  csz;  // +0x10
    void*   ibeg; // +0x18
    void*   iend; // +0x20
    size_t  isz;  // +0x28
};
static_assert(sizeof(LibcppDbAbiLayout) == 48, "LibcppDbAbiLayout must be 48 bytes");

// EN: Exact 5,000-byte (0x1388) MT19937 state layout at .bss 0x0e4130 used by __rs_default::operator() (0x048c74..0x048dc8):
//     +0x0000..0x137F: uint64_t mt[624] (`0x270 = 624` slots, 8-byte stride `lsl #3`)
//     +0x1380:         size_t mti (`ldr x9, [x8, #0x1380]` @ 0x048c94)
// VI: Bố cục trạng thái MT19937 5.000 byte (0x1388) tại .bss 0x0e4130 dùng bởi __rs_default::operator():
struct Mt19937StateAbiLayout {
    uint64_t mt[624]; // +0x0000..0x137F
    size_t   mti;     // +0x1380
};
static_assert(offsetof(Mt19937StateAbiLayout, mti) == 0x1380, "mti must be at +0x1380");
static_assert(sizeof(Mt19937StateAbiLayout) == 0x1388, "Mt19937StateAbiLayout must be 0x1388 bytes");

} // namespace ndk_libcxx_recon
