// ============================================================================
// File: cxx_shared_core.h
// Target 111 / 169: libc++_shared.so (919,888 bytes)
// EN: Clean-room C++17 declarations for __rs_default (0x048bf8..0x048dc8),
//     chrono::system_clock / steady_clock (0x0520d4..0x052210),
//     __shared_weak_count (0x0918a8..0x091a38), and FDE dispatcher.
// VI: Khai báo C++17 phòng sạch cho __rs_default (0x048bf8..0x048dc8),
//     chrono::system_clock / steady_clock (0x0520d4..0x052210),
//     __shared_weak_count (0x0918a8..0x091a38) và bộ điều phối FDE.
// ============================================================================
#pragma once

#include "cxx_shared_types.h"

namespace ndk_libcxx_recon {

class RsDefaultPrng {
public:
    // 0x048bf8..0x048c70
    RsDefaultPrng() noexcept;
    RsDefaultPrng(const RsDefaultPrng&) noexcept;
    ~RsDefaultPrng() noexcept;

    // 0x048c74..0x048dc4: MT19937 step & tempering
    uint32_t operator()() noexcept;

    static void ResetStateForTest() noexcept;
};

class SystemClockRecon {
public:
    // 0x0520d4..0x052148: tv_sec * 1,000,000 + (tv_nsec * 0x20c49ba5e353f7cf >> 71)
    static int64_t ConvertTimespecToMicros(int64_t tv_sec, int64_t tv_nsec) noexcept;

    // 0x052168..0x052188: (micros * 0x431bde82d7b634db) >> 82
    static int64_t ToTimeT(int64_t time_point_micros) noexcept;

    // 0x05218c..0x052198: sec * 1,000,000 (0x000f4240)
    static int64_t FromTimeT(int64_t sec) noexcept;

    // 0x05219c..0x0521f4: tv_sec * 1,000,000,000 (0x3b9aca00) + tv_nsec
    static int64_t ConvertMonotonicToNanos(int64_t tv_sec, int64_t tv_nsec) noexcept;
};

class SharedWeakCountRecon {
public:
    SharedWeakCountRecon() noexcept = default;
    virtual ~SharedWeakCountRecon() noexcept = default;

    // 0x091910..0x091924
    void __add_shared() noexcept;
    // 0x091928..0x09193c
    void __add_weak() noexcept;
    // 0x091940..0x0919b8
    void __release_shared() noexcept;
    // 0x0919bc..0x0919e8
    void __release_weak() noexcept;
    // 0x0919ec..0x091a30
    SharedWeakCountRecon* lock() noexcept;

    int64_t use_count() const noexcept { return shared_owners_.load(std::memory_order_relaxed) + 1; }

protected:
    virtual void __on_zero_shared() noexcept {}
    virtual void __on_zero_shared_weak() noexcept {}

private:
    std::atomic<int64_t> shared_owners_{0};      // +0x08
    std::atomic<int64_t> shared_weak_owners_{0}; // +0x10
};

uint64_t ExecuteCxxSharedFdeByAddress(uint64_t fde_pc_begin, uint64_t arg0, uint64_t arg1, uint64_t arg2) noexcept;

} // namespace ndk_libcxx_recon
