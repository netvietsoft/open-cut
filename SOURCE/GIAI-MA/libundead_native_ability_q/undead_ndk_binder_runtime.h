/**
 * @file undead_ndk_binder_runtime.h
 * @brief Clean-Room C++17 Declarations for Android NDK Binder (`ndk::ICInterface`, `ndk::SharedRefBase`),
 *        `std::__ndk1` Synchronization & Shared Pointer Runtime, and `libc++abi` Itanium Demangler / Unwinder
 *        in `libundead_native_ability_q.so` (`.text 0x016538..0x0323ec`).
 *        Khai báo C++17 cho lớp bao NDK Binder (`ndk::ICInterface`, `ndk::SharedRefBase`),
 *        thư viện chuẩn `std::__ndk1` và `libc++abi` nhúng tĩnh trong `libundead_native_ability_q.so`.
 */

#ifndef NEXTAI_OPENCUT_UNDEAD_NDK_BINDER_RUNTIME_H_
#define NEXTAI_OPENCUT_UNDEAD_NDK_BINDER_RUNTIME_H_

#include "undead_types.h"
#include <atomic>
#include <memory>

namespace nextai {
namespace opencut {
namespace undead_q {

namespace ndk {

class SharedRefBase;

/**
 * @brief Control block matching `std::__ndk1::__shared_weak_count` (`0x016a60..0x016bf0`):
 *        - `+0x00`: `vtable`
 *        - `+0x08`: `std::atomic<int64_t> shared_owners_` (0-based: `0` means 1 owner; `-1` means released)
 *        - `+0x10`: `std::atomic<int64_t> shared_weak_owners_` (0-based)
 */
struct SharedWeakCountControlBlock {
    std::atomic<int64_t> shared_owners{0};      ///< +0x08 in binary (`add x8, x20, #8; ldaxr/stlxr` @ 0x016594)
    std::atomic<int64_t> shared_weak_owners{0}; ///< +0x10 in binary
    SharedRefBase*       owned_ptr{nullptr};    ///< +0x18

    virtual ~SharedWeakCountControlBlock() = default;
    virtual void on_zero_shared() noexcept;
    virtual void on_zero_shared_weak() noexcept;

    void add_shared() noexcept;
    bool release_shared() noexcept;
    void add_weak() noexcept;
    void release_weak() noexcept;
    SharedWeakCountControlBlock* lock() noexcept;
};

struct SharedPtrICInterface {
    class ICInterface*           ptr{nullptr};  ///< +0x00
    SharedWeakCountControlBlock* cntrl{nullptr};///< +0x08
};

/**
 * @brief Clean-room reconstruction of `ndk::SharedRefBase` (`0x016784..0x0169d0`).
 *        Lớp cơ sở đếm tham chiếu nguyên tử `ndk::SharedRefBase` (`0x016784..0x0169d0`).
 */
class SharedRefBase {
public:
    SharedRefBase() noexcept = default;
    virtual ~SharedRefBase() = default;

    /**
     * @brief Reconstructs `_ZN3ndk13SharedRefBase3refINS_11ICInterfaceEEENSt6__ndk110shared_ptrIT_EEv`
     *        (`0x016784..0x0168cc`, 328 bytes):
     *        Checks `this_weak_.cntrl` at `+0x18`, initializes via `__call_once` (`0x0168d0`) if `once_flag_` (`+0x08`)
     *        is not `-1` (`~0ULL`), and increments the shared reference count.
     */
    SharedPtrICInterface ref() noexcept;

    uint64_t                     once_flag_{0};           ///< +0x08 (`ldar x8, [x0]; cmn x8, #1` @ 0x0167e0..0x0167e4)
    SharedRefBase*               weak_this_ptr_{nullptr}; ///< +0x10 (`ldr x8, [x20, #0x10]` @ 0x0167c4)
    SharedWeakCountControlBlock* weak_this_cntrl_{nullptr}; ///< +0x18 (`ldr x0, [x0, #0x18]` @ 0x0167b0)
};

/**
 * @brief Clean-room reconstruction of `ndk::ICInterface` & `ndk::ICInterface::ICInterfaceData` (`0x016538..0x016784`).
 *        Giao diện NDK Binder `ndk::ICInterface` và `ICInterfaceData` (`0x016538..0x016784`).
 */
class ICInterface : public SharedRefBase {
public:
    ~ICInterface() override = default;

    virtual binder_status_t dump(int fd, const char** args, uint32_t numArgs) noexcept {
        (void)fd;
        (void)args;
        (void)numArgs;
        return kStatusOk;
    }

    struct ICInterfaceData {
        /**
         * @brief `_ZN3ndk11ICInterface15ICInterfaceData8onCreateEPv` (`0x016538..0x016634`, 252 bytes).
         *        Takes `void* args` (`ICInterface*`), calls `SharedRefBase::ref<ICInterface>()` (`0x0158b0`),
         *        allocates a 16-byte (`mov w0, #0x10; bl operator new` @ `0x016560..0x016564`) `shared_ptr<ICInterface>`
         *        holder on the heap, increments its strong count, and returns it as `userData`.
         */
        static void* onCreate(void* args) noexcept;

        /**
         * @brief `_ZN3ndk11ICInterface15ICInterfaceData9onDestroyEPv` (`0x016634..0x016694`, 96 bytes).
         *        Decrements the strong reference count on the 16-byte `shared_ptr<ICInterface>` holder
         *        and calls `operator delete(userData)` (`b #0x157f0` @ `0x01668c`).
         */
        static void onDestroy(void* userData) noexcept;

        /**
         * @brief `_ZN3ndk11ICInterface15ICInterfaceData6onDumpEP8AIBinderiPPKcj` (`0x016694..0x016784`, 240 bytes).
         *        Retrieves `userData` via `AIBinder_getUserData(binder)` (`0x0166b4`), increments strong refcount,
         *        invokes virtual `ICInterface::dump(fd, args, numArgs)` at vtable offset `+0x20` (`ldr x8, [x8, #0x20]; blr x8`
         *        @ `0x0166e4..0x0166f4`), decrements strong refcount, and returns the status code.
         */
        static binder_status_t onDump(AIBinder* binder, int fd, const char** args, uint32_t numArgs) noexcept;
    };
};

} // namespace ndk

// ============================================================================
// 2. EMBEDDED `std::__ndk1` & `libc++abi` RUNTIME HELPERS (`0x016bf4..0x0323ec`)
//    CÁC HÀM HỖ TRỢ THỜI GIAN CHẠY `std::__ndk1` VÀ `libc++abi` (`0x016bf4..0x0323ec`)
// ============================================================================

/**
 * @brief Computes the striped spinlock index for `std::__ndk1::__get_sp_mut(const void* p)` (`0x016c60..0x016cb8`, 88 bytes).
 *        Exact hash formula in binary: `((uintptr_t(p) >> 4) & 0xF)` indexing 16 `__sp_mut` mutexes.
 */
size_t ComputeSharedPtrMutexIndex_0x016c60(const void* ptr) noexcept;

/**
 * @brief Clean-room implementation of `std::__ndk1::align(size_t alignment, size_t size, void*& ptr, size_t& space)`
 *        (`_ZNSt6__ndk15alignEmmRPvRm` @ `0x016cd0..0x016d1c`, 76 bytes).
 *        Căn chỉnh con trỏ bộ nhớ theo lũy thừa của 2 (`alignment`) trong vùng đệm kích thước `space`.
 */
void* StdNdk1Align_0x016cd0(size_t alignment, size_t size, void*& ptr, size_t& space) noexcept;

/**
 * @brief Clean-room Itanium C++ ABI symbol demangler subset (`__cxa_demangle` @ `0x01b980..0x02dc00`)
 *        capable of demangling all exported symbols in `libundead_native_ability_q.so`.
 */
char* DemangleUndeadSymbol_0x01b980(const char* mangled_name,
                                    char* output_buffer,
                                    size_t* length,
                                    int* status) noexcept;

} // namespace undead_q
} // namespace opencut
} // namespace nextai

#endif // NEXTAI_OPENCUT_UNDEAD_NDK_BINDER_RUNTIME_H_
