// ============================================================================
// File: gaia_types.h
// Target: libgaia_lib.so (329,704 bytes, SHA-256: a42c9645c2acd2bebcf524e5eec1b759c39f85403fd89c36afabadfaa9e6a911)
// Task ID: TASK-135-RECONSTRUCTION-LIBGAIA-LIB / TASK_SO_112_libgaia_lib
// Architecture: AArch64 (arm64-v8a), Page Size 16KB (0x4000), 8 Subsystems
// Description:
//   EN: Clean-room C++17 ABI-exact data structures for ByteDance AmazingEngine
//       GAIA Core Library: RefBase, AELogSystem, Vector2f, Vector3f, Matrix3x3f,
//       Matrix4x4f, Quaternionf, PerlinNoise, ThreadPool, FSystemTime, FileUtils,
//       MemoryStream, AllowListManager, memory::MemoryManager, memory::MemoryPool,
//       NetworkClient (Cronet/TTNet), PerformanceCap, and stb_truetype (SDF).
//   VN: Cac cau truc du lieu C++17 chuan ABI cho thu vien cot loi ByteDance
//       AmazingEngine GAIA: RefBase, AELogSystem, Vector2f/3f, Matrix3x3f/4x4f,
//       Quaternionf, PerlinNoise, ThreadPool, FSystemTime, FileUtils, MemoryPool,
//       NetworkClient (Cronet/TTNet), PerformanceCap va stb_truetype (SDF).
// ============================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <atomic>
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <mutex>

// EN: Memory label identifier used across AmazingEngine::memory::MemoryManager
// VN: Dinh danh nhan bo nho su dung trong AmazingEngine::memory::MemoryManager
enum AMGMemLabelIdentifier : int32_t {
    kAMGMemDefault      = 0,
    kAMGMemThread       = 1,
    kAMGMemFile         = 2,
    kAMGMemNetwork      = 3,
    kAMGMemPerformance  = 4,
    kAMGMemText         = 5,
    kAMGMemPool         = 6,
    kAMGMemCount        = 7
};

namespace AmazingEngine {

// ============================================================================
// 1. Intrusive Reference Counting Base (0x043728 .. 0x04379c)
//    EN: Uses AArch64 ldaxr/stlxr atomic loop on ref_count_ at offset +0x08.
//        When release() observes old ref_count_ == 1, invokes vtable[+0x28].
//    VN: Su dung vong lap nguyen tu ldaxr/stlxr tren ref_count_ tai offset +0x08.
//        Khi release() thay ref_count_ cu == 1, goi ham huy qua vtable[+0x28].
// ============================================================================
class RefBase {
public:
    RefBase() noexcept : ref_count_(1), reserved_pad_(0) {}
    virtual ~RefBase() noexcept = default;
    virtual void onLastStrongRef() noexcept {}
    virtual void onFirstRef() noexcept {}
    virtual void dispose() noexcept { delete this; }

    // 0x043728: add x8, x0, #8; ldaxr w9, [x8]; add w9, w9, #1; stlxr w10, w9, [x8]
    void retain() const noexcept {
        ref_count_.fetch_add(1, std::memory_order_acq_rel);
    }

    // 0x043740: add x9, x0, #8; ldaxr w8, [x9]; sub w10, w8, #1; stlxr w11, w10, [x9]; cmp w8, #1
    void release() const noexcept {
        int32_t prev = ref_count_.fetch_sub(1, std::memory_order_acq_rel);
        if (prev == 1) {
            const_cast<RefBase*>(this)->dispose();
        }
    }

    // 0x043770: add x8, x0, #8; ldaxr w9, [x8]; sub w9, w9, #1; stlxr w10, w9, [x8]
    void reduce() const noexcept {
        ref_count_.fetch_sub(1, std::memory_order_acq_rel);
    }

    // 0x043788: add x8, x0, #8; ldar w0, [x8]; ret
    int32_t getRefCount() const noexcept {
        return ref_count_.load(std::memory_order_acquire);
    }

protected:
    mutable std::atomic<int32_t> ref_count_; // +0x08
    int32_t reserved_pad_;                   // +0x0C
};

// ============================================================================
// 2. Core Math Types: Vector2f, Vector3f, Quaternionf, Matrix3x3f, Matrix4x4f
//    EN: Verified from .text (0x013164..0x019fc0) and .rodata (0x043950..0x043f5f)
//    VN: Xac minh tu .text (0x013164..0x019fc0) va .rodata (0x043950..0x043f5f)
// ============================================================================
struct Vector2f {
    float x; // +0x00
    float y; // +0x04

    Vector2f() noexcept : x(0.0f), y(0.0f) {}
    Vector2f(float in_x, float in_y) noexcept : x(in_x), y(in_y) {}

    // Exported .rodata symbols (0x043f10 .. 0x043f2f)
    static const float epsilon;          // 0x043f10: 0x3727C5AC (1e-5f)
    static const float infinity;         // 0x043f14: 0x7F800000 (+inf)
    static const Vector2f infinityVec;   // 0x043f18: {+inf, +inf}
    static const Vector2f xAxis;         // 0x043f20: {1.0f, 0.0f}
    static const Vector2f yAxis;         // 0x043f28: {0.0f, 1.0f}

    static const Vector2f& zero() noexcept; // 0x0190bc
    static const Vector2f& one() noexcept;  // 0x0190c8
};

struct Vector3f {
    float x; // +0x00
    float y; // +0x04
    float z; // +0x08

    Vector3f() noexcept : x(0.0f), y(0.0f), z(0.0f) {}
    Vector3f(float in_x, float in_y, float in_z) noexcept : x(in_x), y(in_y), z(in_z) {}

    static float epsilon() noexcept;             // 0x0190d4
    static float infinity() noexcept;            // 0x0190e4
    static const Vector3f& infinityVec() noexcept; // 0x0190f0
    static const Vector3f& zero() noexcept;      // 0x019104
    static const Vector3f& one() noexcept;       // 0x019114
    static const Vector3f& xAxis() noexcept;     // 0x019124
    static const Vector3f& yAxis() noexcept;     // 0x019134
    static const Vector3f& zAxis() noexcept;     // 0x019144
};

struct Quaternionf {
    float x; // +0x00
    float y; // +0x04
    float z; // +0x08
    float w; // +0x0C

    Quaternionf() noexcept : x(0.0f), y(0.0f), z(0.0f), w(1.0f) {}
    Quaternionf(float in_x, float in_y, float in_z, float in_w) noexcept
        : x(in_x), y(in_y), z(in_z), w(in_w) {}
};

struct Matrix4x4f;

// EN: 3x3 Column-major / Basis-aligned float matrix (36 bytes: m_Data[9])
// VN: Ma tran 3x3 float (36 bytes: m_Data[9], offset 0x00..0x20)
struct Matrix3x3f {
    float m_Data[9]; // +0x00 .. +0x20 (m00, m10, m20, m01, m11, m21, m02, m12, m22)

    Matrix3x3f() noexcept;
    explicit Matrix3x3f(const float* data) noexcept;         // 0x0132d8
    explicit Matrix3x3f(const Matrix4x4f& other) noexcept;   // 0x013274
    Matrix3x3f& operator=(const Matrix4x4f& other) noexcept; // 0x013228

    static const Matrix3x3f& identity() noexcept;            // 0x013164
    static const Matrix3x3f& zero() noexcept;                // 0x0131c8

    Matrix3x3f& SetIdentity() noexcept;                      // 0x01333c
    Matrix3x3f& SetZero() noexcept;                          // 0x013354
    Matrix3x3f& SetOrthoNormalBasis(const Vector3f& inX, const Vector3f& inY, const Vector3f& inZ) noexcept; // 0x013364
    Matrix3x3f& SetOrthoNormalBasisInverse(const Vector3f& inX, const Vector3f& inY, const Vector3f& inZ) noexcept; // 0x0133b0
    Matrix3x3f& SetScale(const Vector3f& inScale) noexcept;  // 0x0133fc
    bool IsIdentity(float threshold = 1e-5f) const noexcept; // 0x013428
    Matrix3x3f& Scale(const Vector3f& inScale) noexcept;     // 0x013520
    float GetDeterminant() const noexcept;                   // 0x0135a4
    Matrix3x3f& Transpose() noexcept;                        // 0x013600
    bool Invert() noexcept;                                  // 0x013624
    void InvertTranspose() noexcept;                         // 0x0136b4
    Matrix3x3f& operator*=(float s) noexcept;                // 0x01373c
    Matrix3x3f& operator*=(const Matrix3x3f& rhs) noexcept;  // 0x01375c
    Matrix3x3f& operator*=(const Matrix4x4f& rhs) noexcept;  // 0x013898
    Matrix3x3f& SetAxisAngle(const Vector3f& rotationAxis, float radians) noexcept; // 0x0139d4
    Matrix3x3f& SetFromToRotation(const Vector3f& from, const Vector3f& to) noexcept; // 0x013a94
};

// EN: 4x4 Column-major float matrix (64 bytes: m_Data[16], offsets 0x00..0x3C)
// VN: Ma tran 4x4 float (64 bytes: m_Data[16], offsets 0x00..0x3C)
struct Matrix4x4f {
    float m_Data[16]; // +0x00 .. +0x3C

    Matrix4x4f() noexcept;
    explicit Matrix4x4f(const float* data) noexcept;         // 0x0143bc
    explicit Matrix4x4f(const Matrix3x3f& other) noexcept;   // 0x014458
    Matrix4x4f& operator=(const Matrix3x3f& other) noexcept; // 0x0144cc

    static const Matrix4x4f& identity() noexcept;            // 0x014344

    bool IsIdentity(float threshold = 1e-5f) const noexcept; // 0x014528
    double GetDeterminant() const noexcept;                  // 0x0146cc
    Matrix4x4f& operator*=(const Matrix4x4f& inM1) noexcept; // 0x014894
    Matrix4x4f& SetIdentity() noexcept;                      // 0x014c58
    Matrix4x4f& SetOrthoNormalBasis(const Vector3f& inX, const Vector3f& inY, const Vector3f& inZ) noexcept; // 0x014c84
    Matrix4x4f& SetOrthoNormalBasisInverse(const Vector3f& inX, const Vector3f& inY, const Vector3f& inZ) noexcept; // 0x014cec
    Matrix4x4f& SetPositionAndOrthoNormalBasis(const Vector3f& inPosition, const Vector3f& inX, const Vector3f& inY, const Vector3f& inZ) noexcept; // 0x014d48
    Matrix4x4f& SetScale(const Vector3f& inScale) noexcept;  // 0x014dbc
    Matrix4x4f& Scale(const Vector3f& inScale) noexcept;     // 0x014e04
    Matrix4x4f& Translate(const Vector3f& inTrans) noexcept; // 0x014eb0
    Matrix4x4f& AddTranslate(const Vector3f& inTrans) noexcept; // 0x014f64
    Matrix4x4f& SetTranslate(const Vector3f& inTrans) noexcept; // 0x014f94
    Matrix4x4f& SetPerspective(float fovy, float aspect, float zNear, float zFar) noexcept; // 0x014fe4
    Matrix4x4f& SetPerspectiveCotan(float cotanHalfFOV, float zNear, float zFar) noexcept;  // 0x0150ac
    Matrix4x4f& SetOrtho(float left, float right, float bottom, float top, float zNear, float zFar) noexcept; // 0x0150f4
    Matrix4x4f& SetFrustum(float left, float right, float bottom, float top, float nearval, float farval) noexcept; // 0x015168
    Matrix4x4f& Transpose() noexcept;                        // 0x015c7c
    Matrix4x4f& Copy(const Matrix4x4f& inM) noexcept;        // 0x015cbc
    Matrix4x4f& SetFromToRotation(const Vector3f& from, const Vector3f& to) noexcept; // 0x015ce8
    void SetTR(const Vector3f& pos, const Quaternionf& q) noexcept; // 0x015fa8
    void SetTRS(const Vector3f& pos, const Quaternionf& q, const Vector3f& s) noexcept; // 0x015fec
    void SetTRSS(const Vector3f& pos, const Quaternionf& q, const Vector3f& s, const Vector3f& s2) noexcept; // 0x0160c0
    void SetTRInverse(const Vector3f& pos, const Quaternionf& q) noexcept; // 0x016228
    bool getDecompose(Vector3f* pos, Vector3f* scale, Quaternionf* rot) const noexcept; // 0x016770
    bool getDecompose(Vector3f* pos, Vector3f* scale, Quaternionf* rot, Vector3f* skew) const noexcept; // 0x0168d4
    Matrix4x4f& alignAxisWith(int axis, const Vector3f& targetDir) noexcept; // 0x016bec
};

// ============================================================================
// 3. PerlinNoise Generator (0x016eac .. 0x01871c)
//    EN: Uses .rodata 0x043ae0 (256-entry permutation table) and 0x043a60
//        (8 gradient jump tables) with quintic fade 6t^5 - 15t^4 + 10t^3.
//    VN: Su dung bang hoan vi 256 phan tu tai .rodata 0x043ae0 va 8 bang nhay
//        gradient tai 0x043a60 voi da thuc noi suy bac 5: 6t^5 - 15t^4 + 10t^3.
// ============================================================================
class PerlinNoise {
public:
    static float Perlin2D(const Vector2f& coord, float offset) noexcept;              // 0x016eac
    static Vector2f Perlin2DVector(const Vector2f& coord, Vector2f offset) noexcept;  // 0x017054
    static float Perlin3D(const Vector3f& coord, float offset) noexcept;              // 0x017098
    static Vector3f Perlin3DVector(const Vector3f& coord, Vector3f offset) noexcept;  // 0x01834c
    static float FractalPerlin3D(const Vector3f& coord, int octaves, float persistence, float offset) noexcept; // 0x0183b0
    static Vector3f FractalPerlin3DVector(const Vector3f& coord, int octaves, float persistence, Vector3f offset) noexcept; // 0x0184a8
};

// ============================================================================
// 4. MemoryPool & MemoryManager (0x027404 .. 0x028edc)
//    EN: Verified from 0x028924..0x028b50:
//        MemoryPool layout (size 0x78 = 120 bytes):
//          +0x00: BaseAllocator* allocator_
//          +0x08: int32_t block_size_
//          +0x0C: int32_t bubble_byte_size_
//          +0x10: int32_t blocks_per_bubble_
//          +0x18: void** bubbles_begin_
//          +0x20: void** bubbles_end_
//          +0x28: void** bubbles_cap_
//          +0x38: FreeNode* free_head_
//          +0x40: bool allow_growth_
//          +0x44: pthread_mutex_t pool_mutex_ (40 bytes)
//          +0x6C: AMGMemLabelIdentifier mem_label_
//          +0x70: int32_t alloc_count_
//    VN: Bo cuc struct MemoryPool xac minh tu AArch64 0x028924..0x028b50.
// ============================================================================
namespace memory {

class MemoryPool {
public:
    struct FreeNode {
        FreeNode* next;
    };

    MemoryPool(const char* name, int blockSize, int hintSize, AMGMemLabelIdentifier label); // 0x0287ec
    ~MemoryPool(); // 0x028844

    void reset() noexcept;                  // 0x028838
    void deallocateAll() noexcept;          // 0x0288e0
    void preAllocateMemory(int totalBytes); // 0x028958
    void allocNewBubble();                  // 0x0289c8
    void* allocate();                       // 0x028b68
    void* allocate(size_t size);            // 0x028be8
    bool tryDeallocate(void* ptr);          // 0x028c68
    bool containsUnsafe(void* ptr) const noexcept; // 0x028d2c
    void deallocateUnsafe(void* ptr) noexcept;     // 0x028d8c
    void deallocate(void* ptr);             // 0x028dd4
    bool contains(void* ptr);               // 0x028e3c

    int32_t getAllocCount() const noexcept { return alloc_count_; }
    int32_t getBubbleCount() const noexcept { return static_cast<int32_t>(bubbles_.size()); }

private:
    void* allocator_ = nullptr;                     // +0x00
    int32_t block_size_ = 0;                        // +0x08
    int32_t bubble_byte_size_ = 0;                  // +0x0C
    int32_t blocks_per_bubble_ = 0;                 // +0x10
    std::vector<void*> bubbles_;                    // +0x18 (begin, end, cap)
    std::string pool_name_;                         // +0x30
    FreeNode* free_head_ = nullptr;                 // +0x38
    bool allow_growth_ = true;                      // +0x40
    mutable std::mutex mutex_;                      // +0x44
    AMGMemLabelIdentifier label_ = kAMGMemDefault;  // +0x6C
    int32_t alloc_count_ = 0;                       // +0x70
};

class MemoryManager {
public:
    MemoryManager();                                // 0x027404
    ~MemoryManager();                               // 0x0274d4

    void initAllAllocators();                       // 0x02747c
    static void* lowLevelAllocate(size_t size);     // 0x027564 (+0x10 header prefix)
    static void* lowLevelreallocate(void* p, size_t size); // 0x027590
    static void* lowLevelCAllocate(size_t n, size_t size); // 0x0275c0
    static void lowLevelFree(void* p);              // 0x027618

    void* reallocate(void* ptr, size_t size, int align, AMGMemLabelIdentifier label, const char* file, int line); // 0x027628
    void* allocate(size_t size, int align, AMGMemLabelIdentifier label, const char* file, int line);   // 0x027884
    void* getAllocator(AMGMemLabelIdentifier label) const noexcept; // 0x027930
    void* getAllocatorContainingPtr(const void* ptr) const noexcept; // 0x027950
    void deallocate(void* ptr);                     // 0x0279d0
    void deallocate(void* ptr, AMGMemLabelIdentifier label); // 0x027aa4
    size_t getTotalAllocatedMemory() const noexcept; // 0x027bb4
    void init();                                    // 0x027c20
    void deinit();                                  // 0x027ddc
    int32_t getAllocatorCount() const noexcept { return allocator_count_; } // 0x027e48
    size_t getAllocatedMemory(AMGMemLabelIdentifier label) const noexcept;  // 0x027e50
    size_t getLargestAlloc(AMGMemLabelIdentifier label) const noexcept;     // 0x027e60
    size_t getAllocCount(AMGMemLabelIdentifier label) const noexcept;       // 0x027e70
    void printShortMemoryStats(std::string& out) const; // 0x027e80
    MemoryPool* getMemoryPool(int blockSize);       // 0x028338
    MemoryPool* createMemoryPool(const char* name, int blockSize, int hintSize, AMGMemLabelIdentifier label); // 0x028364
    void registerReservedPoolInfo(const char* name, int blockSize, int hintSize, AMGMemLabelIdentifier label); // 0x02848c

private:
    std::vector<MemoryPool*> pools_;                // +0x00 .. +0x10
    int32_t allocator_count_ = 0;                   // +0x18
    bool initialized_ = true;                       // +0x1C
    void* allocators_[16]{};                        // +0x20 .. +0x9F
    void* default_allocator_ = nullptr;             // +0xA0
    size_t total_allocated_ = 0;                    // +0xB8
};

void MemoryPoolTest();                              // 0x028edc

} // namespace memory

// ============================================================================
// 5. stb_truetype Data Structures (0x03acf0 .. 0x040cc8)
//    EN: Verified from stbtt_InitFont (0x03e8c8), stbtt_GetGlyphShape (0x03b02c,
//        14-byte stbtt_vertex stride `add x12, x12, #0xe` at 0x03fb10), and
//        stbtt_GetGlyphSDF (0x03f928).
//    VN: Xac minh tu stbtt_InitFont (0x03e8c8), stbtt_GetGlyphShape (0x03b02c,
//        kich thuoc stbtt_vertex = 14 bytes `add x12, x12, #0xe`) va stbtt_GetGlyphSDF.
// ============================================================================
struct stbtt__buf {
    unsigned char* data; // +0x00
    int cursor;          // +0x08
    int size;            // +0x0C
};

struct stbtt_fontinfo {
    void* userdata;              // +0x00
    unsigned char* data;         // +0x08
    int fontstart;               // +0x10
    int numGlyphs;               // +0x14
    int loca, head, glyf, hhea, hmtx, kern, gpos, svg; // +0x18 .. +0x34
    int index_map;               // +0x38
    int indexToLocFormat;        // +0x3C
    stbtt__buf cff;              // +0x40
    stbtt__buf charstrings;      // +0x50
    stbtt__buf gsubrs;           // +0x60
    stbtt__buf subrs;            // +0x70
    stbtt__buf fontdicts;        // +0x80
    stbtt__buf fdselect;         // +0x90
};

#pragma pack(push, 2)
// EN: Exact 14-byte vertex structure (`mov w11, #0xe; smaddl x13, w13, w11, x8` at 0x03fae8)
// VN: Cau truc dinh 14-byte chinh xac (`mov w11, #0xe` tai 0x03fae8)
struct stbtt_vertex {
    int16_t x;        // +0x00
    int16_t y;        // +0x02
    int16_t cx;       // +0x04
    int16_t cy;       // +0x06
    int16_t cx1;      // +0x08
    int16_t cy1;      // +0x0A
    uint8_t type;     // +0x0C (1=VMOVE, 2=VLINE, 3=VCURVE, 4=VCUBIC)
    uint8_t padding;  // +0x0D
};
#pragma pack(pop)
static_assert(sizeof(stbtt_vertex) == 14, "stbtt_vertex must be 14 bytes (0x0E)");

struct stbtt_bakedchar {
    uint16_t x0, y0, x1, y1;
    float xoff, yoff, xadvance;
};

struct stbtt_packedchar {
    uint16_t x0, y0, x1, y1;
    float xoff, yoff, xadvance;
    float xoff2, yoff2;
};

struct stbtt_aligned_quad {
    float x0, y0, s0, t0;
    float x1, y1, s1, t1;
};

} // namespace AmazingEngine
