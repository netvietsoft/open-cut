/**
 * @file newep_stl_unwind.h
 * @brief Declarations for the 9 exported `std::__ndk1::basic_string` & `std::__ndk1::vector`
 *        methods (`0x003270..0x003adc`) and the embedded LLVM `libunwind` / DWARF `.eh_frame`
 *        unwinder runtime (`0x003ae0..0x00728b`) in `libnewep.so`.
 *        Khai báo 9 hàm xuất khẩu `std::__ndk1::basic_string` & `std::__ndk1::vector`
 *        (`0x003270..0x003adc`) và bộ giải mã DWARF `.eh_frame` / `libunwind` (`0x003ae0..0x00728b`)
 *        trong `libnewep.so`.
 */

#ifndef NEXTAI_OPENCUT_NEWEP_STL_UNWIND_H_
#define NEXTAI_OPENCUT_NEWEP_STL_UNWIND_H_

#include "newep_types.h"

namespace nextai {
namespace opencut {
namespace newep {

// ============================================================================
// 1. Exported `std::__ndk1::basic_string` & `std::__ndk1::vector` Helpers (`0x003270..0x003adc`)
//    9 Hàm Xuất khẩu `std::__ndk1::basic_string` & `std::__ndk1::vector` (`0x003270..0x003adc`)
// ============================================================================

/**
 * @brief `_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2IDnEEPKc` (`0x003270..0x003307`, `152 B`, `.dynsym [047]`).
 *        Constructs a 24-byte `LibcxxString24Abi` from a C-string `cstr`.
 *        Khởi tạo chuỗi 24-byte `LibcxxString24Abi` từ chuỗi C `cstr`.
 */
void BasicStringConstructFromCStr(LibcxxString24Abi* self, const char* cstr);

/**
 * @brief `_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_` (`0x003308..0x0033b3`, `172 B`, `.dynsym [074]`).
 *        Copy-constructs a 24-byte `LibcxxString24Abi` from `other`.
 *        Sao chép khởi tạo chuỗi 24-byte `LibcxxString24Abi` từ `other`.
 */
void BasicStringCopyConstruct(LibcxxString24Abi* self, const LibcxxString24Abi* other);

/**
 * @brief `_ZNSt6__ndk1plIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EERKS9_SB_` (`0x0033b4..0x0034c3`, `272 B`, `.dynsym [071]`).
 *        Concatenates `lhs` + `rhs` into `out_result` (passed in `x8` indirect result register).
 *        Nối hai chuỗi `lhs` + `rhs` vào `out_result` (truyền qua thanh ghi kết quả gián tiếp `x8`).
 */
void BasicStringOperatorPlus(LibcxxString24Abi* out_result,
                             const LibcxxString24Abi* lhs,
                             const LibcxxString24Abi* rhs);

/**
 * @brief `_ZNKSt6__ndk121__basic_string_commonILb1EE20__throw_length_errorEv` (`0x0034c4..0x0034d7`, `20 B`, `.dynsym [065]`).
 */
[[noreturn]] void BasicStringThrowLengthError();

/**
 * @brief `_ZNSt6__ndk16vectorINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEE21__push_back_slow_pathIS6_EEvOT_` (`0x003558..0x0036bb`, `356 B`, `.dynsym [059]`).
 *        Reallocates `vec` using division-by-24 modular inverse `0xaaaaaaaaaaaaaaab` and move-pushes `val`.
 *        Cấp phát lại `vec` bằng nghịch đảo modular chia 24 (`0xaaaaaaaaaaaaaaab`) và đẩy `val` (move).
 */
void VectorStringPushBackSlowPathMove(LibcxxVectorString24Abi* vec, LibcxxString24Abi* val);

/**
 * @brief `_ZNKSt6__ndk120__vector_base_commonILb1EE20__throw_length_errorEv` (`0x0036bc..0x0036cf`, `20 B`, `.dynsym [067]`).
 */
[[noreturn]] void VectorThrowLengthError();

/**
 * @brief `_ZNKSt6__ndk121__basic_string_commonILb1EE20__throw_out_of_rangeEv` (`0x0036d0..0x0036e3`, `20 B`, `.dynsym [056]`).
 */
[[noreturn]] void BasicStringThrowOutOfRange();

/**
 * @brief `_ZNSt6__ndk16vectorINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEE21__push_back_slow_pathIRKS6_EEvOT_` (`0x003764..0x0038e3`, `384 B`, `.dynsym [052]`).
 *        Reallocates `vec` using division-by-24 modular inverse `0xaaaaaaaaaaaaaaab` and copy-pushes `val`.
 *        Cấp phát lại `vec` bằng nghịch đảo modular chia 24 (`0xaaaaaaaaaaaaaaab`) và đẩy bản sao `val`.
 */
void VectorStringPushBackSlowPathCopy(LibcxxVectorString24Abi* vec, const LibcxxString24Abi* val);

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
                                 const char* p_new_stuff);

/**
 * @brief `_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm` (`0x003a1c..0x003adf`, `196 B`, `.dynsym [063]`).
 */
LibcxxString24Abi* BasicStringAppend(LibcxxString24Abi* self, const char* s, uint64_t n);

/**
 * @brief Releases heap buffer if `self` is in long-string mode (`byte[0] & 1 != 0`).
 *        Giải phóng bộ đệm heap nếu `self` ở chế độ chuỗi dài (`byte[0] & 1 != 0`).
 */
void BasicStringDestroy(LibcxxString24Abi* self) noexcept;

// ============================================================================
// 2. DWARF LEB128, Pointer Decoder & Unwind Register Size Table (`0x003ae0..0x003d48`)
//    Bộ giải mã DWARF LEB128, Con trỏ & Bảng kích thước thanh ghi Unwind (`0x003ae0..0x003d48`)
// ============================================================================

const uint8_t* ReadULEB128(const uint8_t* ptr, uint64_t* out_val) noexcept;
const uint8_t* ReadSLEB128(const uint8_t* ptr, int64_t* out_val) noexcept;
const uint8_t* ReadEncodedPointer(uint8_t encoding,
                                  uint64_t base_addr,
                                  const uint8_t* ptr,
                                  uint64_t* out_val) noexcept;
void InitDwarfRegSizeTable(uint8_t* table_97_bytes) noexcept;

} // namespace newep
} // namespace opencut
} // namespace nextai

#endif // NEXTAI_OPENCUT_NEWEP_STL_UNWIND_H_
