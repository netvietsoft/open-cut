/**
 * @file keva_bitmap.h
 * @brief ByteDance Keva MarkBitmap Allocation & Free Space Management Header.
 *        Cấu trúc dữ liệu MarkBitmap quản lý cấp phát và dải không gian trống Keva.
 */

#ifndef GECKOX_KEVA_BITMAP_H
#define GECKOX_KEVA_BITMAP_H

#include "keva_types.h"
#include <vector>
#include <cstdint>

namespace nextai {
namespace opencut {
namespace keva {

/**
 * @brief MarkBitmap manages allocation bits for Keva chunk storage
 *        Bộ quản lý bitmap theo dõi trạng thái sử dụng của từng chunk trong file
 */
class MarkBitmap {
public:
    MarkBitmap(uint32_t totalBits = 1024, uint64_t* externalBuffer = nullptr);
    virtual ~MarkBitmap() = default;

    void Mark(uint32_t start, uint32_t count);
    void Clear(uint32_t start, uint32_t count);
    void Clear();
    bool IsMarked(uint32_t start, uint32_t count) const;

    int32_t FindContinuousBitsIndex(uint64_t minBits, uint32_t maxBits, bool exact);
    uint32_t GetFreeBitsNum() const;

    void Enlarge(uint32_t newTotalBits);
    void Require(uint32_t requiredBits);
    void Require();
    void Dump() const;

    uint32_t getTotalBits() const { return m_totalBits; }
    const std::vector<uint64_t>& getWords() const { return m_words; }

private:
    uint32_t m_totalBits;
    std::vector<uint64_t> m_words;
};

} // namespace keva
} // namespace opencut
} // namespace nextai

#endif // GECKOX_KEVA_BITMAP_H
