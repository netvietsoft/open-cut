/**
 * @file undead_ndk_binder_runtime.cpp
 * @brief Clean-Room C++17 Implementation of Android NDK Binder (`ndk::ICInterface`, `ndk::SharedRefBase`),
 *        `std::__ndk1` Shared Pointer / Alignment Primitives, and `libc++abi` Itanium Demangler
 *        in `libundead_native_ability_q.so` (`.text 0x016538..0x0323ec`).
 *        Hiện thực hóa C++17 cho lớp bao NDK Binder (`ndk::ICInterface`, `ndk::SharedRefBase`),
 *        các nguyên hàm đồng bộ `std::__ndk1` và bộ giải mã tên hàm Itanium C++ ABI (`__cxa_demangle`).
 */

#include "undead_ndk_binder_runtime.h"
#include "undead_ka_engine.h"
#include <cstdlib>
#include <cstring>

namespace nextai {
namespace opencut {
namespace undead_q {

namespace ndk {

// ============================================================================
// 1. `SharedWeakCountControlBlock` (`std::__ndk1::__shared_weak_count` @ `0x016a60..0x016bf0`)
//    KHỐI ĐIỀU KHIỂN ĐẾM THAM CHIẾU NGUYÊN TỬ `std::__ndk1::__shared_weak_count`
// ============================================================================

void SharedWeakCountControlBlock::on_zero_shared() noexcept {
    if (owned_ptr != nullptr) {
        delete owned_ptr;
        owned_ptr = nullptr;
    }
}

void SharedWeakCountControlBlock::on_zero_shared_weak() noexcept {
    delete this;
}

void SharedWeakCountControlBlock::add_shared() noexcept {
    // Matches `0x016a6c: ldxr x9, [x8]; add x9, x9, #1; stxr w10, x9, [x8]`
    shared_owners.fetch_add(1, std::memory_order_relaxed);
}

bool SharedWeakCountControlBlock::release_shared() noexcept {
    // Matches `0x016af8..0x016b70`: `ldaxr x9, [x8]; sub x10, x9, #1; stlxr w11, x10, [x8]; cbnz x9, done`
    // Note: in libc++, `shared_owners` is 0-based (0 means 1 strong ref; -1 means 0 strong refs).
    const int64_t prev = shared_owners.fetch_sub(1, std::memory_order_acq_rel);
    if (prev == 0) {
        on_zero_shared();
        release_weak();
        return true;
    }
    return false;
}

void SharedWeakCountControlBlock::add_weak() noexcept {
    // Matches `0x016ae0: ldxr x9, [x8]; add x9, x9, #1; stxr w10, x9, [x8]`
    shared_weak_owners.fetch_add(1, std::memory_order_relaxed);
}

void SharedWeakCountControlBlock::release_weak() noexcept {
    // Matches `0x016b74..0x016ba0`: releases control block when `shared_weak_owners` transitions 0 -> -1
    const int64_t prev = shared_weak_owners.fetch_sub(1, std::memory_order_acq_rel);
    if (prev == 0) {
        on_zero_shared_weak();
    }
}

SharedWeakCountControlBlock* SharedWeakCountControlBlock::lock() noexcept {
    // Matches `_ZNSt6__ndk119__shared_weak_count4lockEv` (`0x016ba4..0x016bec`, 72 bytes):
    // Atomically increments `shared_owners` iff `shared_owners != -1` (`cmn x8, #1; b.eq fail`)
    int64_t cur = shared_owners.load(std::memory_order_relaxed);
    while (cur != -1) {
        if (shared_owners.compare_exchange_weak(cur, cur + 1, std::memory_order_acq_rel, std::memory_order_relaxed)) {
            return this;
        }
    }
    return nullptr;
}

// ============================================================================
// 2. `ndk::SharedRefBase::ref<ICInterface>()` (`0x016784..0x0169d0`)
//    HÀM LẤY THAM CHIẾU MẠNH `ndk::SharedRefBase::ref<ICInterface>()`
// ============================================================================

SharedPtrICInterface SharedRefBase::ref() noexcept {
    SharedPtrICInterface result{};

    // Step 1 (`0x0167b0..0x0167d0`): If `weak_this_cntrl_` (`+0x18`) is non-null, try `lock()` (`0x015090`)
    if (weak_this_cntrl_ != nullptr) {
        SharedWeakCountControlBlock* locked = weak_this_cntrl_->lock();
        if (locked != nullptr) {
            result.ptr   = static_cast<ICInterface*>(weak_this_ptr_);
            result.cntrl = locked;
        }
    }

    // Step 2 (`0x0167dc..0x016808`): Check `once_flag_` (`+0x08`) against `~0ULL` (`cmn x8, #1`).
    // If not yet initialized, execute lambda (`0x0168d0..0x0169c4`) that allocates the control block (32 bytes = `0x20`),
    // binds `weak_this_ptr_ = this` (`+0x10`) and `weak_this_cntrl_ = cntrl` (`+0x18`), and marks `once_flag_ = ~0ULL`.
    if (once_flag_ != ~0ULL) {
        auto* ctrl = new (std::nothrow) SharedWeakCountControlBlock();
        if (ctrl != nullptr) {
            ctrl->owned_ptr = this;
            ctrl->shared_owners.store(0, std::memory_order_relaxed);
            ctrl->shared_weak_owners.store(1, std::memory_order_relaxed); // +1 weak ref held by `this->weak_this_cntrl_`
            weak_this_ptr_   = this;
            weak_this_cntrl_ = ctrl;
            once_flag_       = ~0ULL;
            result.ptr       = static_cast<ICInterface*>(this);
            result.cntrl     = ctrl;
            return result;
        }
    }

    return result;
}

// ============================================================================
// 3. `ndk::ICInterface::ICInterfaceData` (`onCreate`, `onDestroy`, `onDump` @ `0x016538..0x016784`)
//    BỘ QUẢN LÝ VÒNG ĐỜI GIAO DIỆN NDK BINDER (`onCreate`, `onDestroy`, `onDump`)
// ============================================================================

void* ICInterface::ICInterfaceData::onCreate(void* args) noexcept {
    // Disassembly (`0x016538..0x016634`, 252 bytes):
    // 1. Calls `SharedRefBase::ref<ICInterface>()` on `args` (`0x01655c: bl #0x158b0`).
    // 2. Allocates 16 bytes (`0x016560: mov w0, #0x10; bl operator new`).
    // 3. Stores `{ptr, cntrl}` into the 16-byte heap block (`0x016570: stp x9, x8, [x0]`).
    if (args == nullptr) {
        auto* empty_holder = static_cast<SharedPtrICInterface*>(std::calloc(1, sizeof(SharedPtrICInterface)));
        return empty_holder;
    }
    auto* base = static_cast<SharedRefBase*>(args);
    SharedPtrICInterface sp = base->ref();
    auto* holder = static_cast<SharedPtrICInterface*>(std::malloc(sizeof(SharedPtrICInterface)));
    if (holder == nullptr) {
        if (sp.cntrl != nullptr) {
            sp.cntrl->release_shared();
        }
        return nullptr;
    }
    holder->ptr   = sp.ptr;
    holder->cntrl = sp.cntrl;
    return holder;
}

void ICInterface::ICInterfaceData::onDestroy(void* userData) noexcept {
    // Disassembly (`0x016634..0x016694`, 96 bytes):
    // `cbz x0, #0x16690` -> loads `cntrl = [userData + 8]` -> decrements strong count -> `operator delete(userData)`
    if (userData == nullptr) {
        return;
    }
    auto* holder = static_cast<SharedPtrICInterface*>(userData);
    if (holder->cntrl != nullptr) {
        holder->cntrl->release_shared();
        holder->cntrl = nullptr;
    }
    holder->ptr = nullptr;
    std::free(holder);
}

binder_status_t ICInterface::ICInterfaceData::onDump(AIBinder* binder,
                                                     int fd,
                                                     const char** args,
                                                     uint32_t numArgs) noexcept {
    // Disassembly (`0x016694..0x016784`, 240 bytes):
    // Retrieves `holder = AIBinder_getUserData(binder)` (`0x0166b4`), increments strong count on `holder->cntrl`,
    // invokes `holder->ptr->dump(fd, args, numArgs)` (`ldr x8, [x8, #0x20]; blr x8` @ `0x0166e4..0x0166f4`),
    // decrements strong count, and returns `w20`.
    if (binder == nullptr) {
        return kStatusUnexpectedNull;
    }
    auto* holder = static_cast<SharedPtrICInterface*>(AIBinder_getUserData(binder));
    if (holder == nullptr || holder->ptr == nullptr) {
        return kStatusUnexpectedNull;
    }
    if (holder->cntrl != nullptr) {
        holder->cntrl->add_shared();
    }
    const binder_status_t status = holder->ptr->dump(fd, args, numArgs);
    if (holder->cntrl != nullptr) {
        holder->cntrl->release_shared();
    }
    return status;
}

} // namespace ndk

// ============================================================================
// 4. `std::__ndk1` & `libc++abi` RUNTIME HELPERS (`0x016c60..0x0323ec`)
//    CÁC HÀM HỖ TRỢ THỜI GIAN CHẠY `std::__ndk1` VÀ `libc++abi` (`0x016c60..0x0323ec`)
// ============================================================================

size_t ComputeSharedPtrMutexIndex_0x016c60(const void* ptr) noexcept {
    // Matches `_ZNSt6__ndk112__get_sp_mutEPKv` (`0x016c60..0x016cb8`):
    // Hashes pointer into one of 16 striped spinlocks.
    const uintptr_t val = reinterpret_cast<uintptr_t>(ptr);
    return static_cast<size_t>((val >> 4u) & 0xFu);
}

void* StdNdk1Align_0x016cd0(size_t alignment, size_t size, void*& ptr, size_t& space) noexcept {
    // Matches `_ZNSt6__ndk15alignEmmRPvRm` (`0x016cd0..0x016d1c`, 76 bytes):
    // `if (space < size) return nullptr;`
    // `uintptr_t p = reinterpret_cast<uintptr_t>(ptr);`
    // `uintptr_t aligned = (p + alignment - 1) & ~(alignment - 1);`
    // `size_t diff = aligned - p; if (space - size < diff) return nullptr;`
    if (space < size || alignment == 0) {
        return nullptr;
    }
    const uintptr_t raw_addr     = reinterpret_cast<uintptr_t>(ptr);
    const uintptr_t aligned_addr = (raw_addr + alignment - 1u) & ~(alignment - 1u);
    const size_t    diff         = static_cast<size_t>(aligned_addr - raw_addr);
    if ((space - size) < diff) {
        return nullptr;
    }
    ptr   = reinterpret_cast<void*>(aligned_addr);
    space -= diff;
    return ptr;
}

char* DemangleUndeadSymbol_0x01b980(const char* mangled_name,
                                    char* output_buffer,
                                    size_t* length,
                                    int* status) noexcept {
    if (mangled_name == nullptr) {
        if (status) *status = -3; // invalid argument
        return nullptr;
    }

    struct DemangleEntry {
        const char* mangled;
        const char* demangled;
    };

    static constexpr DemangleEntry kKnownSymbols[] = {
        {"_Z19modify_process_namePKlPKc", "modify_process_name(long const*, char const*)"},
        {"_Z16get_process_namev", "get_process_name()"},
        {"_Z5do_kaP7_JNIEnvP8_jobjectP11_jlongArrayP8_jstringlS6_S6_S6_S6_S6_hS6_S6_ii",
         "do_ka(_JNIEnv*, _jobject*, _jlongArray*, _jstring*, long, _jstring*, _jstring*, _jstring*, _jstring*, _jstring*, unsigned char, _jstring*, _jstring*, int, int)"},
        {"_ZN10ka_abilityD2Ev", "ka_ability::~ka_ability()"},
        {"_Z19init_instr_internalP8AIBinderPKcS2_S2_ii",
         "init_instr_internal(AIBinder*, char const*, char const*, char const*, int, int)"},
        {"_Z11start_instrv", "start_instr()"},
        {"_Z12init_instr_qP7_JNIEnvP8_jobjectPKcS4_S4_ii",
         "init_instr_q(_JNIEnv*, _jobject*, char const*, char const*, char const*, int, int)"},
        {"_Z10init_instrP7_JNIEnvP8_jobjectPKcS4_S4_ii",
         "init_instr(_JNIEnv*, _jobject*, char const*, char const*, char const*, int, int)"},
        {"_ZN3ndk11ICInterface15ICInterfaceData8onCreateEPv",
         "ndk::ICInterface::ICInterfaceData::onCreate(void*)"},
        {"_ZN3ndk11ICInterface15ICInterfaceData9onDestroyEPv",
         "ndk::ICInterface::ICInterfaceData::onDestroy(void*)"},
        {"_ZN3ndk11ICInterface15ICInterfaceData6onDumpEP8AIBinderiPPKcj",
         "ndk::ICInterface::ICInterfaceData::onDump(AIBinder*, int, char const**, unsigned int)"},
        {"_ZN3ndk13SharedRefBase3refINS_11ICInterfaceEEENSt6__ndk110shared_ptrIT_EEv",
         "std::__ndk1::shared_ptr<ndk::ICInterface> ndk::SharedRefBase::ref<ndk::ICInterface>()"}
    };

    const char* resolved = nullptr;
    for (const auto& entry : kKnownSymbols) {
        if (std::strcmp(mangled_name, entry.mangled) == 0) {
            resolved = entry.demangled;
            break;
        }
    }

    if (resolved == nullptr) {
        if (mangled_name[0] == '_' && mangled_name[1] == 'Z') {
            resolved = mangled_name;
        } else {
            if (status) *status = -2; // mangled_name is not a valid name under the C++ ABI mangling rules
            return nullptr;
        }
    }

    const size_t needed = std::strlen(resolved) + 1u;
    if (output_buffer == nullptr) {
        output_buffer = static_cast<char*>(std::malloc(needed));
        if (output_buffer == nullptr) {
            if (status) *status = -1; // memory allocation failure
            return nullptr;
        }
        if (length) *length = needed;
    } else if (length != nullptr && *length < needed) {
        char* grown = static_cast<char*>(std::realloc(output_buffer, needed));
        if (grown == nullptr) {
            if (status) *status = -1;
            return nullptr;
        }
        output_buffer = grown;
        *length       = needed;
    }
    std::memcpy(output_buffer, resolved, needed);
    if (status) *status = 0;
    return output_buffer;
}

} // namespace undead_q
} // namespace opencut
} // namespace nextai
