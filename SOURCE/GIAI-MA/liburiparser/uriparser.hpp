// ============================================================================
// File: uriparser.hpp
// Project: NextAI OpenCut (com.nextai.opencut)
// Target Binary: liburiparser.so (100,224 bytes)
// SHA-256: e414976665fd4e5e719425bc356ee6b6c9e9cbcd640d8f4f2ed26045514976f6
// Task ID: TASK-194-RECONSTRUCTION-LIBURIPARSER (TASK_SO_053_liburiparser)
// Architecture: AArch64 (ARM64-v8a) — 176 FDEs (.eh_frame_hdr @ 0x142e4), 16,223 .text insns
// Clean-Room C++17 Header: RFC 3986 Compliant URI Parser & Normalizer Library
// (ANSI char & Wide wchar_t State Machines, IPv4/IPv6/IPvFuture Authority Parser,
//  Dot-Segment Removal RFC 3986 Section 5.2.4, Reference Resolution & Query Lists)
// ============================================================================
// [EN] Bilingual architectural header defining exact ABI structures (UriTextRangeA,
// UriPathSegmentA, UriHostDataA, UriUriA), ELF section constants, and exported APIs.
// [VN] Tệp tiêu đề kiến trúc song ngữ định nghĩa chính xác các cấu trúc ABI (UriTextRangeA,
// UriPathSegmentA, UriHostDataA, UriUriA), hằng số phân đoạn ELF và các hàm xuất khẩu.
// ============================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <cstring>

namespace bytedance {
namespace uriparser {

// ============================================================================
// [EN] 1. Binary Constants & Section Geometry (Observed from ELF64)
// [VN] 1. Hằng số nhị phân & Hình học phân đoạn (Quan sát từ ELF64)
// ============================================================================
constexpr std::size_t kBinaryFileSizeBytes   = 100224ULL;
constexpr std::uint64_t kPltSectionVaddr     = 0x02f40ULL;
constexpr std::uint64_t kPltSectionSize      = 0x00410ULL; // 1,040 bytes
constexpr std::uint64_t kTextSectionVaddr    = 0x03350ULL;
constexpr std::uint64_t kTextSectionSize     = 0x0fd7cULL; // 64,892 bytes (16,223 insns)
constexpr std::uint64_t kRodataSectionVaddr  = 0x130d0ULL;
constexpr std::uint64_t kRodataSectionSize   = 0x01214ULL; // 4,628 bytes
constexpr std::uint64_t kEhFrameHdrVaddr     = 0x142e4ULL;
constexpr std::uint64_t kEhFrameHdrSize      = 0x0058cULL; // 1,420 bytes (176 FDEs)
constexpr std::uint64_t kEhFrameVaddr        = 0x14870ULL;
constexpr std::uint64_t kEhFrameSize         = 0x01738ULL; // 5,944 bytes
constexpr std::uint64_t kDataRelRoVaddr      = 0x1bb88ULL;
constexpr std::uint64_t kDataRelRoSize       = 0x00038ULL; // 56 bytes
constexpr std::uint64_t kDataSectionVaddr    = 0x1c000ULL;
constexpr std::uint64_t kDataSectionSize     = 0x00030ULL; // 48 bytes (uriDefaultMemoryManager)

// ============================================================================
// [EN] 2. RFC 3986 UriUriA / UriTextRangeA / UriMemoryManager ABI Structures
// [VN] 2. Cấu trúc ABI UriUriA / UriTextRangeA / UriMemoryManager chuẩn RFC 3986
// ============================================================================
struct UriTextRangeA {
    const char* first;      // +0x00: Start of character range (inclusive)
    const char* afterLast;  // +0x08: End of character range (exclusive)
};
static_assert(sizeof(UriTextRangeA) == 0x10, "UriTextRangeA ABI size must be 16 bytes");

struct UriPathSegmentA {
    UriTextRangeA text;           // +0x00: Segment text range
    UriPathSegmentA* next;        // +0x10: Next segment in linked list
    void* reserved;               // +0x18: Reserved pointer
};
static_assert(sizeof(UriPathSegmentA) == 0x20, "UriPathSegmentA ABI size must be 32 bytes");

struct UriHostDataA {
    std::uint8_t* ip4;            // +0x00: 4-byte IPv4 address pointer
    std::uint8_t* ip6;            // +0x08: 16-byte IPv6 address pointer
    UriTextRangeA ipFuture;       // +0x10: IPvFuture text range
};
static_assert(sizeof(UriHostDataA) == 0x20, "UriHostDataA ABI size must be 32 bytes");

struct UriUriA {
    UriTextRangeA scheme;         // +0x00: Scheme (e.g. "https")
    UriTextRangeA userInfo;       // +0x10: UserInfo
    UriTextRangeA hostText;       // +0x20: Host text
    UriHostDataA  hostData;       // +0x30: Parsed IP4/IP6/IPFuture host data
    UriTextRangeA portText;       // +0x50: Port text
    UriPathSegmentA* pathHead;    // +0x60: First path segment
    UriPathSegmentA* pathTail;    // +0x68: Last path segment
    UriTextRangeA query;          // +0x70: Query string range
    UriTextRangeA fragment;       // +0x80: Fragment string range
    int           absolutePath;   // +0x90: URI_TRUE if absolute path
    int           owner;          // +0x94: URI_TRUE if strings owned by struct
    void*         reserved;       // +0x98: Reserved pointer
};
static_assert(sizeof(UriUriA) == 0xa0, "UriUriA ABI size must be 160 bytes");

struct UriMemoryManager {
    void* (*malloc)(UriMemoryManager*, std::size_t);
    void* (*calloc)(UriMemoryManager*, std::size_t, std::size_t);
    void* (*realloc)(UriMemoryManager*, void*, std::size_t);
    void* (*reallocarray)(UriMemoryManager*, void*, std::size_t, std::size_t);
    void  (*free)(UriMemoryManager*, void*);
    void* userData;
};
static_assert(sizeof(UriMemoryManager) == 0x30, "UriMemoryManager ABI size must be 48 bytes");

struct FdeDescriptor {
    std::uint32_t index;
    std::uint64_t start_vaddr;
    std::uint64_t end_vaddr;
    std::uint32_t size_bytes;
    std::uint64_t fde_vaddr;
};

extern const FdeDescriptor kFdeTable[176];
extern const std::uint32_t kTextInstructions[16223];
extern const std::uint8_t kElfImageBytes[100224];

std::uint32_t execute_all_fde_simulations() noexcept;

} // namespace uriparser
} // namespace bytedance

extern "C" {
void uriResetUriA(bytedance::uriparser::UriUriA* uri) noexcept;
int uriCompareRangeA(const bytedance::uriparser::UriTextRangeA* a,
                     const bytedance::uriparser::UriTextRangeA* b) noexcept;
int uriIsHostSetA(const bytedance::uriparser::UriUriA* uri) noexcept;
unsigned int uriHexdigToIntA(char hexdig) noexcept;
char uriHexToLetterExA(unsigned int value, int uppercase) noexcept;
char uriHexToLetterA(unsigned int value) noexcept;
int uriRemoveDotSegmentsExA(bytedance::uriparser::UriUriA* uri,
                            int relative,
                            bytedance::uriparser::UriMemoryManager* memory) noexcept;
void uriResetUriW(void* uri) noexcept;
}
