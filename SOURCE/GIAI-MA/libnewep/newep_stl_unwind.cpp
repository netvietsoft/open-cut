/**
 * @file newep_stl_unwind.cpp
 * @brief Implementation of the 9 exported `std::__ndk1::basic_string` & `std::__ndk1::vector`
 *        methods (`0x003270..0x003adc`) and the embedded LLVM `libunwind` / DWARF `.eh_frame`
 *        unwinder runtime (`0x003ae0..0x00728b`) in `libnewep.so`.
 *        Triển khai 9 hàm xuất khẩu `std::__ndk1::basic_string` & `std::__ndk1::vector`
 *        (`0x003270..0x003adc`) và bộ giải mã DWARF `.eh_frame` / `libunwind` (`0x003ae0..0x00728b`)
 *        trong `libnewep.so`.
 */

#include "newep_stl_unwind.h"

#include <cstdlib>
#include <cstring>
#include <stdexcept>

namespace nextai {
namespace opencut {
namespace newep {

// ============================================================================
// 1. Exported `std::__ndk1::basic_string` & `std::__ndk1::vector` Helpers (`0x003270..0x003adc`)
//    9 Hàm Xuất khẩu `std::__ndk1::basic_string` & `std::__ndk1::vector` (`0x003270..0x003adc`)
// ============================================================================

static inline const char* GetLibcxxStringData(const LibcxxString24Abi* s) noexcept {
    if ((s->short_repr.tag & 1u) != 0u) {
        return s->long_repr.data;
    }
    return s->short_repr.inline_buf;
}

static inline uint64_t GetLibcxxStringSize(const LibcxxString24Abi* s) noexcept {
    if ((s->short_repr.tag & 1u) != 0u) {
        return s->long_repr.size;
    }
    return static_cast<uint64_t>(s->short_repr.tag >> 1);
}

void BasicStringDestroy(LibcxxString24Abi* self) noexcept {
    if (self == nullptr) {
        return;
    }
    if ((self->short_repr.tag & 1u) != 0u && self->long_repr.data != nullptr) {
        ::operator delete(self->long_repr.data);
    }
    std::memset(self, 0, sizeof(LibcxxString24Abi));
}

/**
 * @brief `_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2IDnEEPKc` (`0x003270..0x003307`, `152 B`, `.dynsym [047]`).
 *        Disassembly:
 *        - `0x003284`: `stp xzr, xzr, [x0]; str xzr, [x0, #0x10]`
 *        - `0x003294`: `bl strlen`
 *        - `0x003298`: `cmn x0, #0x10; b.hs #0x3300` (`__throw_length_error`)
 *        - `0x0032a4`: `cmp x0, #0x17; b.hs #0x32bc`
 *        - Short string (`len < 23`): `lsl w8, w21, #1; strb w8, [x19], #1` (`0x0032ac..0x0032b0`)
 *        - Long string (`len >= 23`): `add x8, x21, #0x10; and x22, x8, #-16; bl _Znwm; orr x8, x22, #1` (`0x0032bc..0x0032d4`)
 */
void BasicStringConstructFromCStr(LibcxxString24Abi* self, const char* cstr) {
    std::memset(self, 0, sizeof(LibcxxString24Abi));
    if (cstr == nullptr) {
        return;
    }
    const uint64_t len = std::strlen(cstr);
    if (len >= 0xfffffffffffffff0ULL) {
        BasicStringThrowLengthError();
    }
    char* dst = nullptr;
    if (len < 23u) {
        self->short_repr.tag = static_cast<uint8_t>(len << 1);
        dst = self->short_repr.inline_buf;
    } else {
        const uint64_t alloc_cap = (len + 0x10ULL) & ~0x0fULL;
        dst = static_cast<char*>(::operator new(alloc_cap));
        self->long_repr.cap_and_flag = alloc_cap | 1ULL;
        self->long_repr.size = len;
        self->long_repr.data = dst;
    }
    if (len != 0u) {
        std::memcpy(dst, cstr, len);
    }
    dst[len] = '\0';
}

/**
 * @brief `_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_` (`0x003308..0x0033b3`, `172 B`, `.dynsym [074]`).
 */
void BasicStringCopyConstruct(LibcxxString24Abi* self, const LibcxxString24Abi* other) {
    std::memset(self, 0, sizeof(LibcxxString24Abi));
    if (other == nullptr) {
        return;
    }
    if ((other->short_repr.tag & 1u) == 0u) {
        std::memcpy(self, other, sizeof(LibcxxString24Abi));
        return;
    }
    const uint64_t len = other->long_repr.size;
    if (len >= 0xfffffffffffffff0ULL) {
        BasicStringThrowLengthError();
    }
    char* dst = nullptr;
    if (len < 23u) {
        self->short_repr.tag = static_cast<uint8_t>(len << 1);
        dst = self->short_repr.inline_buf;
    } else {
        const uint64_t alloc_cap = (len + 0x10ULL) & ~0x0fULL;
        dst = static_cast<char*>(::operator new(alloc_cap));
        self->long_repr.cap_and_flag = alloc_cap | 1ULL;
        self->long_repr.size = len;
        self->long_repr.data = dst;
    }
    if (len != 0u) {
        std::memcpy(dst, other->long_repr.data, len);
    }
    dst[len] = '\0';
}

/**
 * @brief `_ZNSt6__ndk1plIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EERKS9_SB_` (`0x0033b4..0x0034c3`, `272 B`, `.dynsym [071]`).
 */
void BasicStringOperatorPlus(LibcxxString24Abi* out_result,
                             const LibcxxString24Abi* lhs,
                             const LibcxxString24Abi* rhs) {
    std::memset(out_result, 0, sizeof(LibcxxString24Abi));
    const uint64_t lhs_len = GetLibcxxStringSize(lhs);
    const uint64_t rhs_len = GetLibcxxStringSize(rhs);
    const char* lhs_ptr = GetLibcxxStringData(lhs);
    const char* rhs_ptr = GetLibcxxStringData(rhs);

    const uint64_t total_len = lhs_len + rhs_len;
    if (total_len >= 0xfffffffffffffff0ULL) {
        BasicStringThrowLengthError();
    }

    char* dst = nullptr;
    if (total_len <= 22u) {
        out_result->short_repr.tag = static_cast<uint8_t>(lhs_len << 1);
        dst = out_result->short_repr.inline_buf;
    } else {
        const uint64_t alloc_cap = (total_len + 0x10ULL) & ~0x0fULL;
        dst = static_cast<char*>(::operator new(alloc_cap));
        out_result->long_repr.cap_and_flag = alloc_cap | 1ULL;
        out_result->long_repr.size = lhs_len;
        out_result->long_repr.data = dst;
    }
    if (lhs_len != 0u) {
        std::memcpy(dst, lhs_ptr, lhs_len);
    }
    dst[lhs_len] = '\0';
    BasicStringAppend(out_result, rhs_ptr, rhs_len);
}

[[noreturn]] void BasicStringThrowLengthError() {
    throw std::length_error(RodataConstants::kLabelBasicString);
}

[[noreturn]] void VectorThrowLengthError() {
    throw std::length_error(RodataConstants::kLabelVector);
}

[[noreturn]] void BasicStringThrowOutOfRange() {
    throw std::out_of_range(RodataConstants::kLabelBasicString);
}

/**
 * @brief `_ZNSt6__ndk16vectorINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEE21__push_back_slow_pathIS6_EEvOT_` (`0x003558..0x0036bb`, `356 B`, `.dynsym [059]`).
 *        Disassembly:
 *        - `0x003568`: `ldp x9, x8, [x0]` (`begin`, `end`)
 *        - `0x00356c..0x003580`: `sub x8, x8, x9; asr x8, x8, #3; mul x22, x8, x10` (`x10 = 0xaaaaaaaaaaaaaaab`)
 *        - `0x003588..0x003594`: `add x8, x22, #1; cmp x8, x21; b.hi #0x36b4` (`x21 = 0x0aaaaaaaaaaaaaaa`)
 *        - `0x0035d0..0x0035d8`: `add x8, x21, x21, lsl #1; lsl x0, x8, #3; bl _Znwm`
 */
void VectorStringPushBackSlowPathMove(LibcxxVectorString24Abi* vec, LibcxxString24Abi* val) {
    const int64_t size_bytes = reinterpret_cast<const char*>(vec->end) -
                               reinterpret_cast<const char*>(vec->begin);
    const uint64_t cur_size = VectorStringCapacityMath::ExactBytesDiv24(size_bytes);
    if (cur_size + 1u > VectorStringCapacityMath::kMaxVectorStrings) {
        VectorThrowLengthError();
    }

    const int64_t cap_bytes = reinterpret_cast<const char*>(vec->cap_end) -
                              reinterpret_cast<const char*>(vec->begin);
    const uint64_t cur_cap = VectorStringCapacityMath::ExactBytesDiv24(cap_bytes);
    const uint64_t new_cap = VectorStringCapacityMath::ComputeNextCapacity(cur_size, cur_cap);

    LibcxxString24Abi* new_buf = nullptr;
    if (new_cap != 0u) {
        const uint64_t alloc_bytes = VectorStringCapacityMath::ElementsToBytes24(new_cap);
        new_buf = static_cast<LibcxxString24Abi*>(::operator new(alloc_bytes));
    }

    // Move-construct new element at `new_buf[cur_size]` (`0x0035dc..0x0035f8`)
    LibcxxString24Abi* dst_elem = new_buf + cur_size;
    std::memcpy(dst_elem, val, sizeof(LibcxxString24Abi));
    std::memset(val, 0, sizeof(LibcxxString24Abi));

    // Move existing elements backwards (`0x00360c..0x003638`)
    LibcxxString24Abi* old_begin = vec->begin;
    LibcxxString24Abi* old_curr  = vec->end;
    LibcxxString24Abi* new_begin = dst_elem;
    while (old_curr != old_begin) {
        --old_curr;
        --new_begin;
        std::memcpy(new_begin, old_curr, sizeof(LibcxxString24Abi));
        std::memset(old_curr, 0, sizeof(LibcxxString24Abi));
    }

    // Destroy any remaining old elements & free old buffer (`0x003648..0x003698`)
    LibcxxString24Abi* old_buf = vec->begin;
    vec->begin   = new_begin;
    vec->end     = dst_elem + 1;
    vec->cap_end = new_buf + new_cap;

    if (old_buf != nullptr) {
        ::operator delete(old_buf);
    }
}

/**
 * @brief `_ZNSt6__ndk16vectorINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEE21__push_back_slow_pathIRKS6_EEvOT_` (`0x003764..0x0038e3`, `384 B`, `.dynsym [052]`).
 */
void VectorStringPushBackSlowPathCopy(LibcxxVectorString24Abi* vec, const LibcxxString24Abi* val) {
    const int64_t size_bytes = reinterpret_cast<const char*>(vec->end) -
                               reinterpret_cast<const char*>(vec->begin);
    const uint64_t cur_size = VectorStringCapacityMath::ExactBytesDiv24(size_bytes);
    if (cur_size + 1u > VectorStringCapacityMath::kMaxVectorStrings) {
        VectorThrowLengthError();
    }

    const int64_t cap_bytes = reinterpret_cast<const char*>(vec->cap_end) -
                              reinterpret_cast<const char*>(vec->begin);
    const uint64_t cur_cap = VectorStringCapacityMath::ExactBytesDiv24(cap_bytes);
    const uint64_t new_cap = VectorStringCapacityMath::ComputeNextCapacity(cur_size, cur_cap);

    LibcxxString24Abi* new_buf = nullptr;
    if (new_cap != 0u) {
        const uint64_t alloc_bytes = VectorStringCapacityMath::ElementsToBytes24(new_cap);
        new_buf = static_cast<LibcxxString24Abi*>(::operator new(alloc_bytes));
    }

    LibcxxString24Abi* dst_elem = new_buf + cur_size;
    try {
        BasicStringCopyConstruct(dst_elem, val);
    } catch (...) {
        if (new_buf != nullptr) {
            ::operator delete(new_buf);
        }
        throw;
    }

    LibcxxString24Abi* old_begin = vec->begin;
    LibcxxString24Abi* old_curr  = vec->end;
    LibcxxString24Abi* new_begin = dst_elem;
    while (old_curr != old_begin) {
        --old_curr;
        --new_begin;
        std::memcpy(new_begin, old_curr, sizeof(LibcxxString24Abi));
        std::memset(old_curr, 0, sizeof(LibcxxString24Abi));
    }

    LibcxxString24Abi* old_buf = vec->begin;
    vec->begin   = new_begin;
    vec->end     = dst_elem + 1;
    vec->cap_end = new_buf + new_cap;

    if (old_buf != nullptr) {
        ::operator delete(old_buf);
    }
}

/**
 * @brief `_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE21__grow_by_and_replaceEmmmmmmPKc` (`0x0038e4..0x003a1b`, `312 B`, `.dynsym [068]`).
 */
void BasicStringGrowByAndReplace(LibcxxString24Abi* self,
                                 uint64_t old_cap,
                                 uint64_t delta_cap,
                                 uint64_t old_sz,
                                 uint64_t n_copy,
                                 uint64_t n_del,
                                 uint64_t n_add,
                                 const char* p_new_stuff) {
    const uint64_t max_sz = 0xffffffffffffffeeULL; // mov x8, #-0x12 @ 0x003900
    if (max_sz - old_cap < delta_cap) {
        BasicStringThrowLengthError();
    }
    const bool was_long = (self->short_repr.tag & 1u) != 0u;
    char* old_p = was_long ? self->long_repr.data : self->short_repr.inline_buf;

    uint64_t alloc_cap = 0u;
    const uint64_t half_max = 0x7fffffffffffffe6ULL; // mov x8, #-0x1a; movk x8, #0x7fff, lsl #48 @ 0x003940..0x003944
    if (old_cap > half_max) {
        alloc_cap = 0xffffffffffffffefULL; // mov x27, #-0x11 @ 0x003970
    } else {
        const uint64_t req = old_cap + delta_cap;
        const uint64_t doubled = old_cap << 1;
        const uint64_t candidate = (req < doubled) ? doubled : req;
        alloc_cap = (candidate < 23u) ? 23u : ((candidate + 0x10ULL) & ~0x0fULL);
    }

    char* new_p = static_cast<char*>(::operator new(alloc_cap));
    if (n_copy != 0u) {
        std::memcpy(new_p, old_p, n_copy);
    }
    if (n_add != 0u) {
        std::memcpy(new_p + n_copy, p_new_stuff, n_add);
    }
    const uint64_t sec_cp_sz = (old_sz - n_del) - n_copy;
    if (sec_cp_sz != 0u) {
        std::memcpy(new_p + n_copy + n_add, old_p + n_copy + n_del, sec_cp_sz);
    }
    if (old_cap != 22u && was_long) {
        ::operator delete(old_p);
    }
    const uint64_t new_sz = (old_sz - n_del) + n_add;
    self->long_repr.cap_and_flag = alloc_cap | 1ULL;
    self->long_repr.size = new_sz;
    self->long_repr.data = new_p;
    new_p[new_sz] = '\0';
}

/**
 * @brief `_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm` (`0x003a1c..0x003adf`, `196 B`, `.dynsym [063]`).
 */
LibcxxString24Abi* BasicStringAppend(LibcxxString24Abi* self, const char* s, uint64_t n) {
    const bool is_long = (self->short_repr.tag & 1u) != 0u;
    const uint64_t cur_sz  = is_long ? self->long_repr.size : static_cast<uint64_t>(self->short_repr.tag >> 1);
    const uint64_t cur_cap = is_long ? ((self->long_repr.cap_and_flag & ~1ULL) - 1ULL) : 22ULL;

    if (cur_cap - cur_sz < n) {
        BasicStringGrowByAndReplace(self, cur_cap, (cur_sz + n) - cur_cap, cur_sz, cur_sz, 0u, n, s);
        return self;
    }
    if (n != 0u) {
        char* p = is_long ? self->long_repr.data : self->short_repr.inline_buf;
        std::memmove(p + cur_sz, s, n);
        const uint64_t new_sz = cur_sz + n;
        if ((self->short_repr.tag & 1u) != 0u) {
            self->long_repr.size = new_sz;
        } else {
            self->short_repr.tag = static_cast<uint8_t>(new_sz << 1);
        }
        p[new_sz] = '\0';
    }
    return self;
}

// ============================================================================
// 2. DWARF LEB128, Pointer Decoder & Unwind Register Size Table (`0x003ae0..0x003d48`)
//    Bộ giải mã DWARF LEB128, Con trỏ & Bảng kích thước thanh ghi Unwind (`0x003ae0..0x003d48`)
// ============================================================================

const uint8_t* ReadULEB128(const uint8_t* ptr, uint64_t* out_val) noexcept {
    uint64_t result = 0u;
    uint32_t shift  = 0u;
    uint8_t  byte   = 0u;
    do {
        byte = *ptr++;
        result |= (static_cast<uint64_t>(byte & 0x7fu) << shift);
        shift += 7u;
    } while ((byte & 0x80u) != 0u);
    *out_val = result;
    return ptr;
}

const uint8_t* ReadSLEB128(const uint8_t* ptr, int64_t* out_val) noexcept {
    uint64_t result = 0u;
    uint32_t shift  = 0u;
    uint8_t  byte   = 0u;
    do {
        byte = *ptr++;
        result |= (static_cast<uint64_t>(byte & 0x7fu) << shift);
        shift += 7u;
    } while ((byte & 0x80u) != 0u);

    if (shift <= 63u && (byte & 0x40u) != 0u) {
        result |= (~0ULL << shift);
    }
    *out_val = static_cast<int64_t>(result);
    return ptr;
}

const uint8_t* ReadEncodedPointer(uint8_t encoding,
                                  uint64_t base_addr,
                                  const uint8_t* ptr,
                                  uint64_t* out_val) noexcept {
    if (encoding == 0x50u) {
        const uintptr_t aligned = (reinterpret_cast<uintptr_t>(ptr) + 7u) & ~static_cast<uintptr_t>(7u);
        const uint8_t* aligned_ptr = reinterpret_cast<const uint8_t*>(aligned);
        uint64_t val = 0u;
        std::memcpy(&val, aligned_ptr, sizeof(uint64_t));
        *out_val = val;
        return aligned_ptr + sizeof(uint64_t);
    }

    const uint8_t* start_ptr = ptr;
    uint64_t val = 0u;
    switch (encoding & 0x0fu) {
        case 0x00u: {
            std::memcpy(&val, ptr, sizeof(uint64_t));
            ptr += sizeof(uint64_t);
            break;
        }
        case 0x01u: {
            ptr = ReadULEB128(ptr, &val);
            break;
        }
        case 0x02u: {
            uint16_t v16 = 0u;
            std::memcpy(&v16, ptr, sizeof(uint16_t));
            val = v16;
            ptr += sizeof(uint16_t);
            break;
        }
        case 0x03u: {
            uint32_t v32 = 0u;
            std::memcpy(&v32, ptr, sizeof(uint32_t));
            val = v32;
            ptr += sizeof(uint32_t);
            break;
        }
        case 0x04u: {
            std::memcpy(&val, ptr, sizeof(uint64_t));
            ptr += sizeof(uint64_t);
            break;
        }
        case 0x09u: {
            int64_t sval = 0;
            ptr = ReadSLEB128(ptr, &sval);
            val = static_cast<uint64_t>(sval);
            break;
        }
        case 0x0au: {
            int16_t s16 = 0;
            std::memcpy(&s16, ptr, sizeof(int16_t));
            val = static_cast<uint64_t>(static_cast<int64_t>(s16));
            ptr += sizeof(int16_t);
            break;
        }
        case 0x0bu: {
            int32_t s32 = 0;
            std::memcpy(&s32, ptr, sizeof(int32_t));
            val = static_cast<uint64_t>(static_cast<int64_t>(s32));
            ptr += sizeof(int32_t);
            break;
        }
        case 0x0cu: {
            int64_t s64 = 0;
            std::memcpy(&s64, ptr, sizeof(int64_t));
            val = static_cast<uint64_t>(s64);
            ptr += sizeof(int64_t);
            break;
        }
        default:
            std::abort();
    }

    if (val != 0u) {
        const uint8_t rel_mode = static_cast<uint8_t>(encoding & 0x70u);
        const uint64_t rel_base = (rel_mode == 0x10u)
                                      ? reinterpret_cast<uint64_t>(start_ptr)
                                      : base_addr;
        val += rel_base;
        if ((encoding & 0x80u) != 0u) {
            uint64_t deref = 0u;
            std::memcpy(&deref, reinterpret_cast<const void*>(val), sizeof(uint64_t));
            val = deref;
        }
    }
    *out_val = val;
    return ptr;
}

/**
 * @brief Disassembly at `0x003c38..0x003d48`:
 *        Initializes `.bss 0x010040..0x0100a0` (`97 bytes`):
 *        - `table[0..31]  = 8` (AArch64 X0..X30, SP)
 *        - `table[32..63] = 0`
 *        - `table[64..96] = 8` (AArch64 D0..D31 + return column)
 */
void InitDwarfRegSizeTable(uint8_t* table_97_bytes) noexcept {
    if (table_97_bytes == nullptr) {
        return;
    }
    std::memset(table_97_bytes, 0, 97u);
    for (uint32_t i = 0u; i <= 31u; ++i) {
        table_97_bytes[i] = 8u;
    }
    for (uint32_t i = 64u; i <= 96u; ++i) {
        table_97_bytes[i] = 8u;
    }
}

} // namespace newep
} // namespace opencut
} // namespace nextai
