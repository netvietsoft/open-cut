/**
 * @file ttmplayer_value_parcel.h
 * @brief Cleanroom C++17 Header for VString, Value, and Parcel Serialization Engine
 *        Header C++17 Tái cấu trúc Sạch cho Bộ Tuần tự hóa VString, Value và Parcel
 *
 * Binary Ground Truth / Tham chiếu Nhị phân Gốc (libttmplayer.so):
 * - com::ss::ttm::player::VString::ctor()            @ 0x16b464 (12 bytes)
 * - com::ss::ttm::player::VString::ctor(const char*) @ 0x16b490 (68 bytes)
 * - com::ss::ttm::player::VString::c_str()           @ 0x16b6a8 (24 bytes)
 * - com::ss::ttm::player::Value::ctor(int const&)    @ 0x16b6cc (24 bytes)
 * - com::ss::ttm::player::Value::ctor(long const&)   @ 0x16b6e4 (24 bytes)
 * - com::ss::ttm::player::Value::ctor(float const&)  @ 0x16b6fc (24 bytes)
 * - com::ss::ttm::player::Value::ctor(double const&) @ 0x16b714 (24 bytes)
 * - com::ss::ttm::player::Value::clear()             @ 0x16b890 (72 bytes)
 * - com::ss::ttm::player::Value::type()              @ 0x16bbbc ( 8 bytes)
 * - com::ss::ttm::player::Parcel::ctor(ulong)        @ 0x16bc04 (16 bytes)
 * - com::ss::ttm::player::Parcel::put(int const&)    @ 0x16bd40 (312 bytes)
 * - com::ss::ttm::player::Parcel::isFull()           @ 0x16be78 (24 bytes)
 * - com::ss::ttm::player::Parcel::size()             @ 0x16c988 ( 8 bytes)
 * - com::ss::ttm::player::Parcel::get(ulong)         @ 0x16c990 (36 bytes)
 */

#ifndef NEXTAI_OPENCUT_TTMPLAYER_VALUE_PARCEL_H_
#define NEXTAI_OPENCUT_TTMPLAYER_VALUE_PARCEL_H_

#include "ttmplayer_types.h"

namespace com {
namespace ss {
namespace ttm {
namespace player {

/**
 * @brief Variadic helper matching `Parcel::init<T, Args...>` symbols at 0x0b4fc8, 0x104de0, 0x159988, 0x159ae0, 0x159c28.
 *        Hàm mẫu đa tham số khớp các ký hiệu `Parcel::init<T, Args...>` tại 0x0b4fc8..0x159c28.
 */
template <typename First, typename... Rest>
void ParcelInitVariadic(Parcel& parcel, First&& first, Rest&&... rest) {
    parcel.put(std::forward<First>(first));
    if constexpr (sizeof...(Rest) > 0) {
        ParcelInitVariadic(parcel, std::forward<Rest>(rest)...);
    }
}

}  // namespace player
}  // namespace ttm
}  // namespace ss
}  // namespace com

extern "C" {

// C-ABI verification entry points for VString, Value, and Parcel
int32_t ttmplayer_verify_vstring_sso_and_heap(const char* short_str, const char* long_str);
int32_t ttmplayer_verify_value_polymorphism(int32_t i32_in,
                                            int64_t i64_in,
                                            float f32_in,
                                            double f64_in,
                                            const char* str_in);
int32_t ttmplayer_verify_parcel_container(uint64_t capacity);

}  // extern "C"

#endif  // NEXTAI_OPENCUT_TTMPLAYER_VALUE_PARCEL_H_
