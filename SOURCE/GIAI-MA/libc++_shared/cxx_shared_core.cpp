// ============================================================================
// File: cxx_shared_core.cpp
// Target 111 / 169: libc++_shared.so (919,888 bytes)
// SHA-256: e861c5cc64fd7045f2208cec91092009d3aef2af834f6928c1299cc21ca28bc6
// EN: Clean-room C++17 implementation of std::__ndk1::__rs_default (0x048bf8..0x048dc8)
//     Mersenne Twister MT19937 PRNG with exact AArch64 opcode parity.
// VI: Triển khai C++17 phòng sạch cho bộ sinh số giả ngẫu nhiên Mersenne Twister
//     MT19937 std::__ndk1::__rs_default (0x048bf8..0x048dc8) khớp 1:1 opcode AArch64.
// ============================================================================
#include "cxx_shared_core.h"
#include <mutex>

namespace ndk_libcxx_recon {

static std::mutex g_rs_mutex_0e4104;
static uint32_t g_rs_lock_depth_0e3f30 = 0u;
static bool g_mt_inited_0e54b8 = false;
static Mt19937StateAbiLayout g_mt_state_0e4130{};

// ============================================================================
// 1. __rs_default Ctor / Copy Ctor / Dtor (0x048bf8 .. 0x048c70)
// Disassembly @ 0x048bf8..0x048c6c:
//   Ctor (`0x048bf8`): locks `0x0e4104` and sets `__c_ = 1`
//   Copy (`0x048c24`): increments `__c_` (`add w9, w9, #1`)
//   Dtor (`0x048c3c`): decrements `__c_` (`subs w9, w9, #1`) and unlocks when 0
// ============================================================================
RsDefaultPrng::RsDefaultPrng() noexcept {
    g_rs_mutex_0e4104.lock();
    g_rs_lock_depth_0e3f30 = 1u;
}

RsDefaultPrng::RsDefaultPrng(const RsDefaultPrng&) noexcept {
    ++g_rs_lock_depth_0e3f30;
}

RsDefaultPrng::~RsDefaultPrng() noexcept {
    if (--g_rs_lock_depth_0e3f30 == 0u) {
        g_rs_mutex_0e4104.unlock();
    }
}

void RsDefaultPrng::ResetStateForTest() noexcept {
    g_mt_inited_0e54b8 = false;
}

// ============================================================================
// 2. __rs_default::operator() (0x048c74 .. 0x048dc4)
// Disassembly @ 0x048d6c..0x048da4 (MT19937 seeding):
//   0x048d70: 5282AE28 mov  w8, #0x1571 (5489u)
//   0x048d78: 52912CAA mov  w10, #0x8965
//   0x048d80: 72AD80EA movk w10, #0x6c07, lsl #16 (1812433253u = 0x6c078965u)
//   0x048d84: D35EFD0B lsr  x11, x8, #0x1e
//   0x048d88: 4A080168 eor  w8, w11, w8
//   0x048d90: 1B0A2508 madd w8, w8, w10, w9
// Disassembly @ 0x048c94..0x048d50 (MT19937 step & tempering):
//   0x048cb4: 91063529 add  x9, x9, #0x18d (M = 397)
//   0x048cbc: 52804E0B mov  w11, #0x270    (N = 624)
//   0x048ce8: 52961BEC mov  w12, #0xb0df
//   0x048cec: 72B3210C movk w12, #0x9908, lsl #16 (0x9908b0dfu)
//   0x048d14: 528AD00A mov  w10, #0x5680
//   0x048d18: 72B3A58A movk w10, #0x9d2c, lsl #16 (0x9d2c5680u)
//   0x048d3c: 52BDF8CB mov  w11, #-0x103a0000     (0xefc60000u)
// ============================================================================
uint32_t RsDefaultPrng::operator()() noexcept {
    if (!g_mt_inited_0e54b8) {
        uint32_t x = 0x1571u; // 5489u
        g_mt_state_0e4130.mt[0] = x;
        for (size_t i = 1; i < 624; ++i) {
            x ^= (x >> 30);
            x = x * 0x6C078965u + static_cast<uint32_t>(i);
            g_mt_state_0e4130.mt[i] = x;
        }
        g_mt_state_0e4130.mti = 0;
        g_mt_inited_0e54b8 = true;
    }

    const size_t i = g_mt_state_0e4130.mti;
    const size_t j = (i + 1u) % 624u;
    const size_t k = (i + 397u) % 624u;

    const uint32_t y = static_cast<uint32_t>(
        (g_mt_state_0e4130.mt[i] & 0x80000000ULL) |
        (g_mt_state_0e4130.mt[j] & 0x7FFFFFFFULL));
    const uint32_t mag = (y & 1u) * 0x9908B0DFu;
    g_mt_state_0e4130.mt[i] = g_mt_state_0e4130.mt[k] ^ (y >> 1) ^ mag;

    uint32_t z = static_cast<uint32_t>(g_mt_state_0e4130.mt[i]);
    g_mt_state_0e4130.mti = j;

    z ^= (z >> 11);
    z ^= (z << 7) & 0x9D2C5680u;
    z ^= (z << 15) & 0xEFC60000u;
    z ^= (z >> 18);
    return z;
}

} // namespace ndk_libcxx_recon
