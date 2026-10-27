// ============================================================================
// File: cxx_shared_chrono_memory.cpp
// Target 111 / 169: libc++_shared.so (919,888 bytes)
// EN: Clean-room C++17 implementation of chrono::system_clock (0x0520d4..0x052198),
//     chrono::steady_clock (0x05219c..0x0521f4), and __shared_weak_count
//     (0x0918a8..0x091a38) with exact AArch64 reciprocal division & LL/SC parity.
// VI: Triển khai C++17 phòng sạch cho chrono::system_clock (0x0520d4..0x052198),
//     chrono::steady_clock (0x05219c..0x0521f4) và __shared_weak_count
//     (0x0918a8..0x091a38) khớp 1:1 phép chia nghịch đảo và LL/SC AArch64.
// ============================================================================
#include "cxx_shared_core.h"

namespace ndk_libcxx_recon {

// ============================================================================
// 1. chrono::system_clock & steady_clock (0x0520d4 .. 0x0521f4)
// Disassembly @ 0x052114..0x052148 (system_clock::now):
//   0x052114..0x052120: x10 = 0x20c49ba5e353f7cf (ceil(2^71 / 1000))
//   0x052124: 9B4A7D29 smulh x9, x9, x10
//   0x052128: 9347FD2A asr   x10, x9, #7
//   0x052134: 8B49FD49 add   x9, x10, x9, lsr #63
//   0x052138: 5288480A mov   w10, #0x4240
//   0x05213c: 72A001EA movk  w10, #0xf, lsl #16 (1,000,000 = 0x000f4240)
//   0x052140: 9B0A2500 madd  x0, x8, x10, x9
// ============================================================================
int64_t SystemClockRecon::ConvertTimespecToMicros(int64_t tv_sec, int64_t tv_nsec) noexcept {
    constexpr __int128 kMagicDiv1000 = static_cast<__int128>(0x20C49BA5E353F7CFULL);
    const int64_t high = static_cast<int64_t>((static_cast<__int128>(tv_nsec) * kMagicDiv1000) >> 64);
    const int64_t nsec_to_usec = (high >> 7) + (high < 0 ? 1 : 0);
    return tv_sec * 1000000LL + nsec_to_usec;
}

// Disassembly @ 0x052168..0x052188 (system_clock::to_time_t):
//   0x05216c..0x052178: x9 = 0x431bde82d7b634db (ceil(2^82 / 1000000))
//   0x05217c: 9B497D08 smulh x8, x8, x9
//   0x052180: 9352FD09 asr   x9, x8, #0x12 (18)
//   0x052184: 8B48FD20 add   x0, x9, x8, lsr #63
//   0x052188: D65F03C0 ret
int64_t SystemClockRecon::ToTimeT(int64_t time_point_micros) noexcept {
    constexpr __int128 kMagicDiv1M = static_cast<__int128>(0x431BDE82D7B634DBULL);
    const int64_t high = static_cast<int64_t>((static_cast<__int128>(time_point_micros) * kMagicDiv1M) >> 64);
    return (high >> 18) + (high < 0 ? 1 : 0);
}

// Disassembly @ 0x05218c..0x052198 (system_clock::from_time_t):
//   0x05218c: 52884808 mov  w8, #0x4240
//   0x052190: 72A001E8 movk w8, #0xf, lsl #16 (1,000,000)
//   0x052194: 9B087C00 mul  x0, x0, x8
//   0x052198: D65F03C0 ret
int64_t SystemClockRecon::FromTimeT(int64_t sec) noexcept {
    return sec * 0x000F4240LL;
}

// Disassembly @ 0x0521e4..0x0521f4 (steady_clock::now):
//   0x0521e4: 5299400A mov  w10, #0xca00
//   0x0521e8: 72A7734A movk w10, #0x3b9a, lsl #16 (1,000,000,000 = 0x3b9aca00)
//   0x0521ec: 9B0A2120 madd x0, x9, x10, x8
int64_t SystemClockRecon::ConvertMonotonicToNanos(int64_t tv_sec, int64_t tv_nsec) noexcept {
    return tv_sec * 0x3B9ACA00LL + tv_nsec;
}

// ============================================================================
// 2. __shared_weak_count (0x0918a8 .. 0x091a38)
// Disassembly @ 0x091910..0x091a30:
//   __add_shared (0x091910): `add x8, x0, #8; ldxr x9, [x8]; add x9, x9, #1; stxr w10, x9, [x8]; cbnz w10`
//   __add_weak   (0x091928): `add x8, x0, #0x10; ldxr x9, [x8]; add x9, x9, #1; stxr w10, x9, [x8]; cbnz w10`
//   __release_shared (0x091940): `ldaxr/stlxr sub #1` on +0x08; when old == 0 (`cbz x9, #0x91974`),
//     calls `__on_zero_shared()` (vtable +0x10) and then `__release_weak()`.
//   lock (0x0919ec): `ldar x9, [x8]; cmn x9, #1` -> CAS loop incrementing `shared_owners_` if `!= -1`.
// ============================================================================
void SharedWeakCountRecon::__add_shared() noexcept {
    shared_owners_.fetch_add(1, std::memory_order_relaxed);
}

void SharedWeakCountRecon::__add_weak() noexcept {
    shared_weak_owners_.fetch_add(1, std::memory_order_relaxed);
}

void SharedWeakCountRecon::__release_shared() noexcept {
    if (shared_owners_.fetch_sub(1, std::memory_order_acq_rel) == 0) {
        __on_zero_shared();
        __release_weak();
    }
}

void SharedWeakCountRecon::__release_weak() noexcept {
    if (shared_weak_owners_.load(std::memory_order_acquire) == 0) {
        __on_zero_shared_weak();
    } else if (shared_weak_owners_.fetch_sub(1, std::memory_order_acq_rel) == 0) {
        __on_zero_shared_weak();
    }
}

SharedWeakCountRecon* SharedWeakCountRecon::lock() noexcept {
    int64_t owners = shared_owners_.load(std::memory_order_acquire);
    while (owners != -1) {
        if (shared_owners_.compare_exchange_weak(
                owners, owners + 1, std::memory_order_acq_rel, std::memory_order_acquire)) {
            return this;
        }
    }
    return nullptr;
}

} // namespace ndk_libcxx_recon
