/**
 * @file keva_bitmap.cpp
 * @brief ByteDance Keva MarkBitmap Implementation.
 *        Hiện thực mã nguồn C++ cấu trúc quản lý bit cấp phát Keva.
 */

#include "keva_bitmap.h"
#include <algorithm>
#include <iostream>

namespace nextai {
namespace opencut {
namespace keva {

MarkBitmap::MarkBitmap(uint32_t totalBits, uint64_t* externalBuffer)
    : m_totalBits(totalBits) {
    size_t numWords = (m_totalBits + 63) / 64;
    m_words.resize(numWords, 0);
    if (externalBuffer) {
        for (size_t i = 0; i < numWords; ++i) {
            m_words[i] = externalBuffer[i];
        }
    }
}

void MarkBitmap::Mark(uint32_t start, uint32_t count) {
    if (start >= m_totalBits || count == 0) return;
    uint32_t end = std::min(start + count, m_totalBits);

    for (uint32_t i = start; i < end; ++i) {
        uint32_t wordIdx = i / 64;
        uint32_t bitIdx = i % 64;
        m_words[wordIdx] |= (1ULL << bitIdx);
    }
}

void MarkBitmap::Clear(uint32_t start, uint32_t count) {
    if (start >= m_totalBits || count == 0) return;
    uint32_t end = std::min(start + count, m_totalBits);

    for (uint32_t i = start; i < end; ++i) {
        uint32_t wordIdx = i / 64;
        uint32_t bitIdx = i % 64;
        m_words[wordIdx] &= ~(1ULL << bitIdx);
    }
}

void MarkBitmap::Clear() {
    std::fill(m_words.begin(), m_words.end(), 0ULL);
}

bool MarkBitmap::IsMarked(uint32_t start, uint32_t count) const {
    if (start >= m_totalBits || count == 0) return false;
    uint32_t end = std::min(start + count, m_totalBits);

    for (uint32_t i = start; i < end; ++i) {
        uint32_t wordIdx = i / 64;
        uint32_t bitIdx = i % 64;
        if ((m_words[wordIdx] & (1ULL << bitIdx)) == 0) {
            return false;
        }
    }
    return true;
}

int32_t MarkBitmap::FindContinuousBitsIndex(uint64_t minBits, uint32_t maxBits, bool exact) {
    if (minBits == 0 || minBits > m_totalBits) return -1;
    uint32_t targetBits = static_cast<uint32_t>(minBits);

    uint32_t consecutive = 0;
    int32_t startIndex = -1;

    for (uint32_t i = 0; i < m_totalBits; ++i) {
        uint32_t wordIdx = i / 64;
        uint32_t bitIdx = i % 64;
        bool isUsed = (m_words[wordIdx] & (1ULL << bitIdx)) != 0;

        if (!isUsed) {
            if (consecutive == 0) {
                startIndex = static_cast<int32_t>(i);
            }
            consecutive++;
            if (consecutive >= targetBits) {
                if (!exact || consecutive == targetBits) {
                    return startIndex;
                }
            }
        } else {
            consecutive = 0;
            startIndex = -1;
        }
    }

    return -1;
}

uint32_t MarkBitmap::GetFreeBitsNum() const {
    uint32_t usedBits = 0;
    for (uint64_t w : m_words) {
#if defined(__GNUC__) || defined(__clang__)
        usedBits += __builtin_popcountll(w);
#else
        uint64_t v = w;
        v = v - ((v >> 1) & 0x5555555555555555ULL);
        v = (v & 0x3333333333333333ULL) + ((v >> 2) & 0x3333333333333333ULL);
        usedBits += (uint32_t)((((v + (v >> 4)) & 0xF0F0F0F0F0F0F0FULL) * 0x101010101010101ULL) >> 56);
#endif
    }
    return (m_totalBits > usedBits) ? (m_totalBits - usedBits) : 0;
}

void MarkBitmap::Enlarge(uint32_t newTotalBits) {
    if (newTotalBits <= m_totalBits) return;
    m_totalBits = newTotalBits;
    size_t numWords = (m_totalBits + 63) / 64;
    m_words.resize(numWords, 0);
}

void MarkBitmap::Require(uint32_t requiredBits) {
    if (GetFreeBitsNum() < requiredBits) {
        Enlarge(m_totalBits + requiredBits * 2);
    }
}

void MarkBitmap::Require() {
    Require(64);
}

void MarkBitmap::Dump() const {
    // Debug print
}

} // namespace keva
} // namespace opencut
} // namespace nextai
