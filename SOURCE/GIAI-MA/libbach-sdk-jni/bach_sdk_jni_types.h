/**
 * @file bach_sdk_jni_types.h
 * @brief Exact ELF64, ABI Structs, AmazingEngine Math Primitives, and Bach Object Types for libbach-sdk-jni.so.
 *        Định nghĩa chuẩn xác cấu trúc ELF64, Struct ABI, kiểu toán học AmazingEngine và đối tượng Bach cho libbach-sdk-jni.so.
 *
 * Target Binary / Nhị phân mục tiêu:
 *   - File: libbach-sdk-jni.so (117,112 bytes)
 *   - SHA-256: 6330cb09b6721ef41639c6ed472b4d60e3b81a9f03c699f5d8c1cbefe5804929
 *   - Architecture: AArch64 (ARM64-v8a), Little-Endian, Android NDK r21d (Clang 9.0.8)
 *   - Package: com.bytedance.byted_bach_sdk (ByteDance Bach Algorithm System & Resource Finder JNI)
 *
 * Evidence Classification / Phân loại bằng chứng (Rule 20 AGENTS.md):
 *   - [OBSERVED]: ELF64 section headers, .dynsym (113 symbols: 92 imported, 17 exported JNI functions),
 *     .rodata jump tables (0x014f5c..0x014f97, 0x015a01..0x015a05), 39-element result type table
 *     (0x014f98..0x015033), .data.rel.ro vtables (0x01f8a8..0x01fa2f), and .bss globals (0x020010..0x0202bf).
 */

#ifndef NEXTAI_OPENCUT_BACH_SDK_JNI_TYPES_H_
#define NEXTAI_OPENCUT_BACH_SDK_JNI_TYPES_H_

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace com {
namespace bytedance {
namespace bach_sdk {

// ============================================================================
// 1. ELF64 Binary Geometry & Section Constants
//    Thông số hình học nhị phân ELF64 & Hằng số phân đoạn [OBSERVED]
// ============================================================================

struct BachSdkJniElfGeometry {
    static constexpr uint64_t kBinarySizeBytes          = 117112ULL;
    static constexpr const char* kBinarySha256          = "6330cb09b6721ef41639c6ed472b4d60e3b81a9f03c699f5d8c1cbefe5804929";
    static constexpr uint32_t kSectionCount             = 29U;
    static constexpr uint32_t kDynsymTotalEntries       = 113U;
    static constexpr uint32_t kImportedSymbolCount      = 92U;
    static constexpr uint32_t kExportedJniFunctionCount = 17U;

    // Section Virtual Addresses & Sizes / Địa chỉ ảo và kích thước các phân đoạn [OBSERVED]
    static constexpr uint64_t kDynsymVa                 = 0x0002c0ULL;
    static constexpr uint64_t kDynsymSize               = 2712ULL;
    static constexpr uint64_t kDynstrVa                 = 0x000d58ULL;
    static constexpr uint64_t kDynstrSize               = 5181ULL;
    static constexpr uint64_t kRelaDynVa                = 0x0025d8ULL;
    static constexpr uint64_t kRelaDynSize              = 1248ULL; // 52 relocations
    static constexpr uint64_t kRelaPltVa                = 0x002ab8ULL;
    static constexpr uint64_t kRelaPltSize              = 2040ULL; // 85 PLT relocations
    static constexpr uint64_t kPltVa                    = 0x0032b0ULL;
    static constexpr uint64_t kPltSize                  = 1392ULL;
    static constexpr uint64_t kTextVa                   = 0x003820ULL;
    static constexpr uint64_t kTextSize                 = 67520ULL; // 0x003820..0x013fdf
    static constexpr uint64_t kGccExceptTableVa         = 0x013fe0ULL;
    static constexpr uint64_t kGccExceptTableSize       = 3964ULL;
    static constexpr uint64_t kRodataVa                 = 0x014f5cULL;
    static constexpr uint64_t kRodataSize               = 2961ULL; // 0x014f5c..0x015aec
    static constexpr uint64_t kEhFrameVa                = 0x015af0ULL;
    static constexpr uint64_t kEhFrameSize              = 7184ULL;
    static constexpr uint64_t kEhFrameHdrVa             = 0x017700ULL;
    static constexpr uint64_t kEhFrameHdrSize           = 1204ULL;
    static constexpr uint64_t kDataRelRoVa              = 0x01f8a8ULL;
    static constexpr uint64_t kDataRelRoFileOff         = 0x01b8a8ULL;
    static constexpr uint64_t kDataRelRoSize            = 392ULL;
    static constexpr uint64_t kFiniArrayVa              = 0x01fa30ULL; // [0x00394c, 0x00393c]
    static constexpr uint64_t kInitArrayVa              = 0x01fa40ULL; // [0x003820]
    static constexpr uint64_t kDataVa                   = 0x020000ULL;
    static constexpr uint64_t kBssVa                    = 0x020010ULL;
    static constexpr uint64_t kBssSize                  = 688ULL;

    // Exported JNI Function Entry Points in .text / Địa chỉ hàm JNI xuất khẩu trong .text [OBSERVED]
    static constexpr uint64_t kVaInitArray0             = 0x003820ULL; // _GLOBAL__sub_I_BachAlgorithmSystemJNI.cpp
    static constexpr uint64_t kVaNativeCreate           = 0x0039c4ULL; // BachAlgorithmSystem.nativeCreate
    static constexpr uint64_t kVaNativeInitGraph        = 0x003bfcULL; // BachAlgorithmSystem.nativeInitGraph
    static constexpr uint64_t kVaNativeSetEnable        = 0x003c8cULL; // BachAlgorithmSystem.nativeSetEnable
    static constexpr uint64_t kVaNativeSetIntParams     = 0x003d78ULL; // BachAlgorithmSystem.nativeSetIntParams
    static constexpr uint64_t kVaNativeSetFloatParams   = 0x0044e4ULL; // BachAlgorithmSystem.nativeSetFloatParams
    static constexpr uint64_t kVaNativeSetStringParams  = 0x004b1cULL; // BachAlgorithmSystem.nativeSetStringParams
    static constexpr uint64_t kVaNativeDestroy          = 0x00515cULL; // BachAlgorithmSystem.nativeDestroy
    static constexpr uint64_t kVaNativeExec             = 0x00519cULL; // BachAlgorithmSystem.nativeExec
    static constexpr uint64_t kVaNativeGetResult        = 0x005c14ULL; // BachAlgorithmSystem.nativeGetResult
    static constexpr uint64_t kVaCityHash64             = 0x006be0ULL; // std::__ndk1::__murmur2_or_cityhash<uint64_t, 64>
    static constexpr uint64_t kVaConvertBachObject      = 0x00702cULL; // convertBachObjectToJava
    static constexpr uint64_t kVaBitmapHandleNativeGet  = 0x00eb38ULL; // BachBitmapHandle.nativeGet
    static constexpr uint64_t kVaDownloadFinderCreate   = 0x00edd0ULL; // DownloadableResourceFinder.nativeCreate
    static constexpr uint64_t kVaFinderNativeDestroy    = 0x00f224ULL; // Downloadable/EPResourceFinder.nativeDestroy
    static constexpr uint64_t kVaDownloadModels         = 0x00f22cULL; // DownloadableResourceFinder.nativeDownloadModels
    static constexpr uint64_t kVaDeleteListener         = 0x00f55cULL; // ModelDownloadListener.deleteNativeObject
    static constexpr uint64_t kVaEPFinderCreate         = 0x00f61cULL; // EPResourceFinder.nativeCreate
    static constexpr uint64_t kVaJniOnLoad              = 0x0102b0ULL; // JNI_OnLoad
    static constexpr uint64_t kVaStdStringToJString     = 0x010338ULL; // stdStringToJString
    static constexpr uint64_t kVaJstringToStdString     = 0x010464ULL; // jstringToStdString
};

// ============================================================================
// 2. .rodata Tables: 39 Special Result Type IDs & 30-Way BachObject Jump Table
//    Bảng dữ liệu .rodata: 39 mã kết quả đặc biệt & Bảng nhảy 30 nhánh [OBSERVED]
// ============================================================================

/**
 * @brief 39 Algorithm Result Type IDs inserted into global std::unordered_set<int> at .bss 0x020010
 *        during .init_array[0] (0x003820..0x0038f4) from .rodata 0x014f98..0x015033 (156 bytes).
 *        39 mã loại kết quả thuật toán được nạp vào std::unordered_set<int> toàn cục tại .bss 0x020010.
 */
static constexpr int32_t kBachDirectBufferResultTypes[39] = {
    0x30, // 48
    0x73, // 115
    0x80, // 128
    0x0d, // 13  (ExpressionDetectAlgorithmOutput)
    0x10, // 16
    0x0b, // 11
    0x22, // 34
    0x08, // 8   (FaceAlgorithmOutput)
    0x5e, // 94
    0x14, // 20
    0x34, // 52
    0x70, // 112
    0x72, // 114
    0x74, // 116
    0x97, // 151
    0x37, // 55
    0x0f, // 15
    0x7b, // 123
    0x65, // 101
    0x61, // 97
    0x23, // 35
    0x62, // 98
    0x46, // 70
    0x7e, // 126
    0x15, // 21
    0x41, // 65
    0x51, // 81
    0x68, // 104
    0x36, // 54
    0x19, // 25
    0x3a, // 58
    0x18, // 24
    0x31, // 49
    0x32, // 50
    0x39, // 57
    0x0c, // 12
    0x0e, // 14
    0x2f, // 47
    0x6a  // 106
};

/**
 * @brief 30-entry unsigned 16-bit displacement table at .rodata 0x014f5c..0x014f97 used by
 *        convertBachObjectToJava (0x00702c) at 0x007078..0x007080:
 *        `adr x10, #0x7090; ldrh w11, [x9, x8, lsl #1]; add x10, x10, x11, lsl #2; br x10`
 *        target_va = 0x007090 + kConvertBachObjectJumpOffsets[type - 1] * 4.
 *        Bảng 30 độ lệch 16-bit tại .rodata 0x014f5c..0x014f97 cho hàm convertBachObjectToJava.
 */
static constexpr uint16_t kConvertBachObjectJumpOffsets[30] = {
    0x0000, // [0]  -> 0x007090 (Int64)
    0x0604, // [1]  -> 0x0088a0 (ImageBuffer)
    0x0458, // [2]  -> 0x0081f0 (String)
    0x05a8, // [3]  -> 0x008730 (Vec2f)
    0x02bd, // [4]  -> 0x007b84 (Vec3f)
    0x078f, // [5]  -> 0x008ecc (Quatf)
    0x085b, // [6]  -> 0x0091fc (Mat3x3f)
    0x05bd, // [7]  -> 0x008784 (Mat4x4f)
    0x095d, // [8]  -> 0x009604 (Color)
    0x02f5, // [9]  -> 0x007c64 (Vec4f)
    0x095a, // [10] -> 0x0095f8 (Rect)
    0x0202, // [11] -> 0x007898 (Double)
    0x02d5, // [12] -> 0x007be4 (Int16Vec)
    0x083b, // [13] -> 0x00917c (Int32Vec)
    0x0138, // [14] -> 0x007570 (Int64Vec)
    0x04e8, // [15] -> 0x008430 (Int8Vec)
    0x0118, // [16] -> 0x0074f0 (Uint16Vec)
    0x0691, // [17] -> 0x008ad4 (Uint32Vec)
    0x093a, // [18] -> 0x009578 (FloatVec)
    0x0ac2, // [19] -> 0x009b98 (DoubleVec)
    0x06b1, // [20] -> 0x008b54 (StringVec)
    0x0792, // [21] -> 0x008ed8 (Vec2fVec)
    0x0a0d, // [22] -> 0x0098c4 (Vec3fVec)
    0x0b8c, // [23] -> 0x009ec0 (Vec4fVec)
    0x03ad, // [24] -> 0x007f44 (QuatfVec)
    0x02f8, // [25] -> 0x007c70 (Mat3x3fVec)
    0x0d8e, // [26] -> 0x00a6c8 (Mat4x4fVec)
    0x0061, // [27] -> 0x007214 (Uint8Vec)
    0x0c37, // [28] -> 0x00a16c (BachMap)
    0x0ce2  // [29] -> 0x00a418 (BachVec)
};

/**
 * @brief 5-entry pixel format jump table at .rodata 0x015a01..0x015a05 used by
 *        BachBitmapHandle_nativeGet (0x00eb38) at 0x00ec40:
 *        target_va = 0x00ec50 + kBitmapFormatJumpOffsets[format] * 4.
 *        Bảng nhảy 5 định dạng pixel tại .rodata 0x015a01..0x015a05 cho BachBitmapHandle_nativeGet.
 */
static constexpr uint8_t kBitmapFormatJumpOffsets[5] = {
    0x0b, // Format 0 (GRAY8)    -> 0x00ec7c -> ConvertGray8ToRGBA8888 (0x00ff4c)
    0x1b, // Format 1 (RGB888)   -> 0x00ecbc -> ConvertRGB888ToRGBA8888 (0x01000c)
    0x13, // Format 2 (BGR888)   -> 0x00ec9c -> ConvertBGR888ToRGBA8888 (0x0100dc)
    0x00, // Format 3 (RGBA8888) -> 0x00ec50 -> memcpy (0x00ec74)
    0x23  // Format 4 (BGRA8888) -> 0x00ecdc -> ConvertBGRA8888ToRGBA8888 (0x0101c8)
};

// ============================================================================
// 3. AmazingEngine Math & RefBase Primitives
//    Kiểu toán học & cơ sở tham chiếu AmazingEngine [OBSERVED]
// ============================================================================

namespace AmazingEngine {

/**
 * @brief Reference-counted base class (`AmazingEngine::RefBase`) imported from libiesapplogger.so / Bach SDK.
 *        Lớp cơ sở đếm tham chiếu (`AmazingEngine::RefBase`) nhập khẩu từ SDK Bach.
 *
 * Vtable layout [OBSERVED at .data.rel.ro 0x01f8a8, 0x01f8f0, 0x01f928, 0x01f960, 0x01f988]:
 *   +0x00: void retain()      (_ZN13AmazingEngine7RefBase6retainEv)
 *   +0x08: void release()     (_ZN13AmazingEngine7RefBase7releaseEv)
 *   +0x10: int  retainCount() (_ZNK13AmazingEngine7RefBase11retainCountEv)
 *   +0x18: ~RefBase() D1      (_ZN13AmazingEngine7RefBaseD2Ev)
 *   +0x20: ~RefBase() D0      (_ZN13AmazingEngine7RefBaseD0Ev)
 */
class RefBase {
public:
    RefBase() noexcept : ref_count_(1), weak_flag_(0) {}
    virtual ~RefBase() noexcept = default;

    virtual void retain() noexcept {
        ++ref_count_;
    }

    virtual void release() noexcept {
        if (--ref_count_ <= 0) {
            delete this;
        }
    }

    virtual int retainCount() const noexcept {
        return ref_count_;
    }

protected:
    int32_t ref_count_; // +0x08 [OBSERVED: str wzr, [x22, #8] at 0x0053f0]
    int32_t weak_flag_; // +0x0c
};

struct Vector2f {
    float x;
    float y;
};
static_assert(sizeof(Vector2f) == 8, "Vector2f ABI size must be 8 bytes");

struct Vector3f {
    float x;
    float y;
    float z;
};
static_assert(sizeof(Vector3f) == 12, "Vector3f ABI size must be 12 bytes");

struct Vector4f {
    float x;
    float y;
    float z;
    float w;
};
static_assert(sizeof(Vector4f) == 16, "Vector4f ABI size must be 16 bytes");

struct Quaternionf {
    float x;
    float y;
    float z;
    float w;
};
static_assert(sizeof(Quaternionf) == 16, "Quaternionf ABI size must be 16 bytes");

struct Matrix3x3f {
    float m[3][3]; // 9 floats = 36 bytes (0x24) [OBSERVED at 0x007d1c: mov w0, #0x24]
};
static_assert(sizeof(Matrix3x3f) == 36, "Matrix3x3f ABI size must be 36 bytes");

struct Matrix4x4f {
    float m[4][4]; // 16 floats = 64 bytes (0x40) [OBSERVED at 0x00a75c: mov w0, #0x40]
};
static_assert(sizeof(Matrix4x4f) == 64, "Matrix4x4f ABI size must be 64 bytes");

struct Rect {
    float x;
    float y;
    float width;
    float height;
};
static_assert(sizeof(Rect) == 16, "Rect ABI size must be 16 bytes");

struct Color {
    float r;
    float g;
    float b;
    float a;
};
static_assert(sizeof(Color) == 16, "Color ABI size must be 16 bytes");

/**
 * @brief `AmazingEngine::PrimitiveVector<T>` ABI layout [OBSERVED at 0x005478, 0x0072a0..0x009fd0]:
 *   +0x00: vtable pointer (RefBase)
 *   +0x08: int32_t ref_count_
 *   +0x10: T* begin_ (or std::vector<T> begin_)
 *   +0x18: T* end_
 *   +0x20: T* cap_
 *   Total allocation size: 40 bytes (0x28) [OBSERVED: mov w0, #0x28 at 0x005468]
 */
template <typename T>
class PrimitiveVector : public RefBase {
public:
    PrimitiveVector() = default;
    explicit PrimitiveVector(const std::vector<T>& vec) : data_(vec) {}
    explicit PrimitiveVector(std::vector<T>&& vec) noexcept : data_(std::move(vec)) {}
    ~PrimitiveVector() noexcept override = default;

    const T* begin_ptr() const noexcept { return data_.empty() ? nullptr : data_.data(); }
    const T* end_ptr() const noexcept { return data_.empty() ? nullptr : data_.data() + data_.size(); }
    size_t size() const noexcept { return data_.size(); }
    const std::vector<T>& vector() const noexcept { return data_; }
    std::vector<T>& vector() noexcept { return data_; }

private:
    std::vector<T> data_; // +0x10..+0x27 (24 bytes on AArch64)
};

} // namespace AmazingEngine

// ============================================================================
// 4. Bach Namespace Object & Algorithm System Types
//    Các kiểu đối tượng & hệ thống thuật toán trong không gian tên Bach [OBSERVED]
// ============================================================================

namespace Bach {

/**
 * @brief 30 `BachObject::ValueType` enumerators matching the 30-way jump table at 0x007060..0x00708c.
 *        30 mã kiểu giá trị của `BachObject` khớp với bảng nhảy 30 nhánh tại 0x007060..0x00708c.
 */
enum class BachObjectType : int32_t {
    kNone        = 0,
    kInt64       = 1,
    kInt64Vec    = 2,
    kDouble      = 3,
    kDoubleVec   = 4,
    kVec2f       = 5,
    kVec3f       = 6,
    kVec4f       = 7,
    kQuatf       = 8,
    kMat3x3f     = 9,
    kMat4x4f     = 10,
    kString      = 11,
    kImageBuffer = 12,
    kRect        = 13,
    kColor       = 14,
    kInt8Vec     = 15,
    kUint8Vec    = 16,
    kInt16Vec    = 17,
    kUint16Vec   = 18,
    kInt32Vec    = 19,
    kUint32Vec   = 20,
    kFloatVec    = 21,
    kStringVec   = 22,
    kVec2fVec    = 23,
    kVec3fVec    = 24,
    kVec4fVec    = 25,
    kQuatfVec    = 26,
    kMat3x3fVec  = 27,
    kMat4x4fVec  = 28,
    kBachVec     = 29,
    kBachMap     = 30
};

/**
 * @brief Internal sub-type tag stored at `BachObject + 0x80` (`[sp + 0x98]` relative to `sp + 0x18`)
 *        when constructing temporary `BachObject` elements from vector slices [OBSERVED at 0x007d10,
 *        0x007fcc, 0x008f5c, 0x009964, 0x009f48, 0x00a750].
 *        Nhãn kiểu con nội bộ tại `BachObject + 0x80` khi tạo phần tử tạm từ mảng vector.
 */
enum class BachInternalUnionTag : int32_t {
    kVec2f   = 4, // 0x008f5c: mov w23, #4; str w23, [sp, #0x98] (8 bytes)
    kVec3f   = 5, // 0x009964: mov w25, #5; str w25, [sp, #0x98] (12 bytes)
    kVec4f   = 6, // 0x009f48: mov w24, #6; str w24, [sp, #0x98] (16 bytes)
    kMat3x3f = 7, // 0x007d10: mov w25, #7; str w25, [sp, #0x98] (36 bytes)
    kMat4x4f = 8, // 0x00a750: mov w24, #8; str w24, [sp, #0x98] (64 bytes)
    kQuatf   = 9  // 0x007fcc: mov w24, #9; str w24, [sp, #0x98] (16 bytes)
};

/**
 * @brief Pixel format enum for `BachImageBuffer` (`+0x68`) [OBSERVED at 0x005458 & 0x00ec2c].
 *        Định dạng điểm ảnh cho `BachImageBuffer` tại độ lệch +0x68.
 */
enum class BachPixelFormat : int32_t {
    kGray8    = 0, // 1 byte/pixel (ANDROID_BITMAP_FORMAT_A_8 = 8)
    kRGB888   = 1, // 3 bytes/pixel (R, G, B)
    kBGR888   = 2, // 3 bytes/pixel (B, G, R)
    kRGBA8888 = 3, // 4 bytes/pixel (ANDROID_BITMAP_FORMAT_RGBA_8888 = 1)
    kBGRA8888 = 4  // 4 bytes/pixel (B, G, R, A)
};

class BachImageBuffer;
class BachVector;
class BachMap;

/**
 * @brief `Bach::BachObject` (136 bytes = 0x88) ABI layout [OBSERVED at 0x00a508, 0x00bf1c, 0x00e3c0].
 *        Đối tượng đa kiểu `Bach::BachObject` kích thước chuẩn 136 byte (0x88).
 */
class BachObject {
public:
    BachObject() noexcept;
    BachObject(const BachObject& other);
    BachObject(BachObject&& other) noexcept;
    BachObject& operator=(const BachObject& other);
    BachObject& operator=(BachObject&& other) noexcept;
    ~BachObject() noexcept;

    // Factory helpers / Hàm khởi tạo tiện ích
    static BachObject FromInt64(int64_t val) noexcept;
    static BachObject FromDouble(double val) noexcept;
    static BachObject FromString(const std::string& val);
    static BachObject FromVec2f(const AmazingEngine::Vector2f& v) noexcept;
    static BachObject FromVec3f(const AmazingEngine::Vector3f& v) noexcept;
    static BachObject FromVec4f(const AmazingEngine::Vector4f& v) noexcept;
    static BachObject FromQuatf(const AmazingEngine::Quaternionf& q) noexcept;
    static BachObject FromMat3x3f(const AmazingEngine::Matrix3x3f& m) noexcept;
    static BachObject FromMat4x4f(const AmazingEngine::Matrix4x4f& m) noexcept;
    static BachObject FromRect(const AmazingEngine::Rect& r) noexcept;
    static BachObject FromColor(const AmazingEngine::Color& c) noexcept;
    static BachObject FromImageBuffer(BachImageBuffer* img) noexcept;

    // Imported getters in .dynsym [043]..[072] / Các hàm truy xuất nhập khẩu trong .dynsym [OBSERVED]
    BachObjectType GetType() const noexcept { return type_; }
    int64_t GetInt64() const noexcept { return int64_val_; }
    double GetDouble() const noexcept { return double_val_; }
    std::string GetString() const { return string_val_; }
    AmazingEngine::Vector2f GetVec2f() const noexcept { return vec2f_val_; }
    AmazingEngine::Vector3f GetVec3f() const noexcept { return vec3f_val_; }
    AmazingEngine::Vector4f GetVec4f() const noexcept { return vec4f_val_; }
    AmazingEngine::Quaternionf GetQuatf() const noexcept { return quatf_val_; }
    AmazingEngine::Matrix3x3f GetMat3x3f() const noexcept { return mat3x3f_val_; }
    AmazingEngine::Matrix4x4f GetMat4x4f() const noexcept { return mat4x4f_val_; }
    AmazingEngine::Rect GetRect() const noexcept { return rect_val_; }
    AmazingEngine::Color GetColor() const noexcept { return color_val_; }
    BachImageBuffer* GetImageBuffer() const noexcept { return image_buffer_val_; }

    std::shared_ptr<AmazingEngine::PrimitiveVector<int8_t>> GetInt8Vec() const noexcept { return int8_vec_; }
    std::shared_ptr<AmazingEngine::PrimitiveVector<uint8_t>> GetUint8Vec() const noexcept { return uint8_vec_; }
    std::shared_ptr<AmazingEngine::PrimitiveVector<int16_t>> GetInt16Vec() const noexcept { return int16_vec_; }
    std::shared_ptr<AmazingEngine::PrimitiveVector<uint16_t>> GetUint16Vec() const noexcept { return uint16_vec_; }
    std::shared_ptr<AmazingEngine::PrimitiveVector<int32_t>> GetInt32Vec() const noexcept { return int32_vec_; }
    std::shared_ptr<AmazingEngine::PrimitiveVector<uint32_t>> GetUint32Vec() const noexcept { return uint32_vec_; }
    std::shared_ptr<AmazingEngine::PrimitiveVector<int64_t>> GetInt64Vec() const noexcept { return int64_vec_; }
    std::shared_ptr<AmazingEngine::PrimitiveVector<float>> GetFloatVec() const noexcept { return float_vec_; }
    std::shared_ptr<AmazingEngine::PrimitiveVector<double>> GetDoubleVec() const noexcept { return double_vec_; }
    std::shared_ptr<AmazingEngine::PrimitiveVector<std::string>> GetStringVec() const noexcept { return string_vec_; }
    std::shared_ptr<AmazingEngine::PrimitiveVector<AmazingEngine::Vector2f>> GetVec2fVec() const noexcept { return vec2f_vec_; }
    std::shared_ptr<AmazingEngine::PrimitiveVector<AmazingEngine::Vector3f>> GetVec3fVec() const noexcept { return vec3f_vec_; }
    std::shared_ptr<AmazingEngine::PrimitiveVector<AmazingEngine::Vector4f>> GetVec4fVec() const noexcept { return vec4f_vec_; }
    std::shared_ptr<AmazingEngine::PrimitiveVector<AmazingEngine::Quaternionf>> GetQuatfVec() const noexcept { return quatf_vec_; }
    std::shared_ptr<AmazingEngine::PrimitiveVector<AmazingEngine::Matrix3x3f>> GetMat3x3fVec() const noexcept { return mat3x3f_vec_; }
    std::shared_ptr<AmazingEngine::PrimitiveVector<AmazingEngine::Matrix4x4f>> GetMat4x4fVec() const noexcept { return mat4x4f_vec_; }

    const BachVector* GetBachVec() const noexcept { return bach_vec_.get(); }
    const BachMap* GetBachMap() const noexcept { return bach_map_.get(); }

    // Setters for vector/map types / Các hàm gán dữ liệu vector và map
    void SetInt8Vec(std::shared_ptr<AmazingEngine::PrimitiveVector<int8_t>> v) noexcept { type_ = BachObjectType::kInt8Vec; int8_vec_ = std::move(v); }
    void SetUint8Vec(std::shared_ptr<AmazingEngine::PrimitiveVector<uint8_t>> v) noexcept { type_ = BachObjectType::kUint8Vec; uint8_vec_ = std::move(v); }
    void SetInt16Vec(std::shared_ptr<AmazingEngine::PrimitiveVector<int16_t>> v) noexcept { type_ = BachObjectType::kInt16Vec; int16_vec_ = std::move(v); }
    void SetUint16Vec(std::shared_ptr<AmazingEngine::PrimitiveVector<uint16_t>> v) noexcept { type_ = BachObjectType::kUint16Vec; uint16_vec_ = std::move(v); }
    void SetInt32Vec(std::shared_ptr<AmazingEngine::PrimitiveVector<int32_t>> v) noexcept { type_ = BachObjectType::kInt32Vec; int32_vec_ = std::move(v); }
    void SetUint32Vec(std::shared_ptr<AmazingEngine::PrimitiveVector<uint32_t>> v) noexcept { type_ = BachObjectType::kUint32Vec; uint32_vec_ = std::move(v); }
    void SetInt64Vec(std::shared_ptr<AmazingEngine::PrimitiveVector<int64_t>> v) noexcept { type_ = BachObjectType::kInt64Vec; int64_vec_ = std::move(v); }
    void SetFloatVec(std::shared_ptr<AmazingEngine::PrimitiveVector<float>> v) noexcept { type_ = BachObjectType::kFloatVec; float_vec_ = std::move(v); }
    void SetDoubleVec(std::shared_ptr<AmazingEngine::PrimitiveVector<double>> v) noexcept { type_ = BachObjectType::kDoubleVec; double_vec_ = std::move(v); }
    void SetStringVec(std::shared_ptr<AmazingEngine::PrimitiveVector<std::string>> v) noexcept { type_ = BachObjectType::kStringVec; string_vec_ = std::move(v); }
    void SetVec2fVec(std::shared_ptr<AmazingEngine::PrimitiveVector<AmazingEngine::Vector2f>> v) noexcept { type_ = BachObjectType::kVec2fVec; vec2f_vec_ = std::move(v); }
    void SetVec3fVec(std::shared_ptr<AmazingEngine::PrimitiveVector<AmazingEngine::Vector3f>> v) noexcept { type_ = BachObjectType::kVec3fVec; vec3f_vec_ = std::move(v); }
    void SetVec4fVec(std::shared_ptr<AmazingEngine::PrimitiveVector<AmazingEngine::Vector4f>> v) noexcept { type_ = BachObjectType::kVec4fVec; vec4f_vec_ = std::move(v); }
    void SetQuatfVec(std::shared_ptr<AmazingEngine::PrimitiveVector<AmazingEngine::Quaternionf>> v) noexcept { type_ = BachObjectType::kQuatfVec; quatf_vec_ = std::move(v); }
    void SetMat3x3fVec(std::shared_ptr<AmazingEngine::PrimitiveVector<AmazingEngine::Matrix3x3f>> v) noexcept { type_ = BachObjectType::kMat3x3fVec; mat3x3f_vec_ = std::move(v); }
    void SetMat4x4fVec(std::shared_ptr<AmazingEngine::PrimitiveVector<AmazingEngine::Matrix4x4f>> v) noexcept { type_ = BachObjectType::kMat4x4fVec; mat4x4f_vec_ = std::move(v); }
    void SetBachVec(std::shared_ptr<BachVector> v) noexcept { type_ = BachObjectType::kBachVec; bach_vec_ = std::move(v); }
    void SetBachMap(std::shared_ptr<BachMap> m) noexcept { type_ = BachObjectType::kBachMap; bach_map_ = std::move(m); }

    void SetInternalUnionTag(BachInternalUnionTag tag, void* heap_ptr) noexcept {
        internal_tag_ = static_cast<int32_t>(tag);
        heap_union_ptr_ = heap_ptr;
        switch (tag) {
            case BachInternalUnionTag::kVec2f:
                type_ = BachObjectType::kVec2f;
                if (heap_ptr) std::memcpy(&vec2f_val_, heap_ptr, sizeof(vec2f_val_));
                break;
            case BachInternalUnionTag::kVec3f:
                type_ = BachObjectType::kVec3f;
                if (heap_ptr) std::memcpy(&vec3f_val_, heap_ptr, sizeof(vec3f_val_));
                break;
            case BachInternalUnionTag::kVec4f:
                type_ = BachObjectType::kVec4f;
                if (heap_ptr) std::memcpy(&vec4f_val_, heap_ptr, sizeof(vec4f_val_));
                break;
            case BachInternalUnionTag::kMat3x3f:
                type_ = BachObjectType::kMat3x3f;
                if (heap_ptr) std::memcpy(&mat3x3f_val_, heap_ptr, sizeof(mat3x3f_val_));
                break;
            case BachInternalUnionTag::kMat4x4f:
                type_ = BachObjectType::kMat4x4f;
                if (heap_ptr) std::memcpy(&mat4x4f_val_, heap_ptr, sizeof(mat4x4f_val_));
                break;
            case BachInternalUnionTag::kQuatf:
                type_ = BachObjectType::kQuatf;
                if (heap_ptr) std::memcpy(&quatf_val_, heap_ptr, sizeof(quatf_val_));
                break;
        }
    }

private:
    BachObjectType type_ = BachObjectType::kNone;
    int32_t internal_tag_ = 0; // +0x80 in raw ABI ([sp + 0x98] relative to sp + 0x18)
    void* heap_union_ptr_ = nullptr; // +0x00 in raw ABI ([sp + 0x18])
    int64_t int64_val_ = 0;
    double double_val_ = 0.0;
    std::string string_val_;
    AmazingEngine::Vector2f vec2f_val_{0.0f, 0.0f};
    AmazingEngine::Vector3f vec3f_val_{0.0f, 0.0f, 0.0f};
    AmazingEngine::Vector4f vec4f_val_{0.0f, 0.0f, 0.0f, 0.0f};
    AmazingEngine::Quaternionf quatf_val_{0.0f, 0.0f, 0.0f, 1.0f};
    AmazingEngine::Matrix3x3f mat3x3f_val_{};
    AmazingEngine::Matrix4x4f mat4x4f_val_{};
    AmazingEngine::Rect rect_val_{0.0f, 0.0f, 0.0f, 0.0f};
    AmazingEngine::Color color_val_{0.0f, 0.0f, 0.0f, 1.0f};
    BachImageBuffer* image_buffer_val_ = nullptr;

    std::shared_ptr<AmazingEngine::PrimitiveVector<int8_t>> int8_vec_;
    std::shared_ptr<AmazingEngine::PrimitiveVector<uint8_t>> uint8_vec_;
    std::shared_ptr<AmazingEngine::PrimitiveVector<int16_t>> int16_vec_;
    std::shared_ptr<AmazingEngine::PrimitiveVector<uint16_t>> uint16_vec_;
    std::shared_ptr<AmazingEngine::PrimitiveVector<int32_t>> int32_vec_;
    std::shared_ptr<AmazingEngine::PrimitiveVector<uint32_t>> uint32_vec_;
    std::shared_ptr<AmazingEngine::PrimitiveVector<int64_t>> int64_vec_;
    std::shared_ptr<AmazingEngine::PrimitiveVector<float>> float_vec_;
    std::shared_ptr<AmazingEngine::PrimitiveVector<double>> double_vec_;
    std::shared_ptr<AmazingEngine::PrimitiveVector<std::string>> string_vec_;
    std::shared_ptr<AmazingEngine::PrimitiveVector<AmazingEngine::Vector2f>> vec2f_vec_;
    std::shared_ptr<AmazingEngine::PrimitiveVector<AmazingEngine::Vector3f>> vec3f_vec_;
    std::shared_ptr<AmazingEngine::PrimitiveVector<AmazingEngine::Vector4f>> vec4f_vec_;
    std::shared_ptr<AmazingEngine::PrimitiveVector<AmazingEngine::Quaternionf>> quatf_vec_;
    std::shared_ptr<AmazingEngine::PrimitiveVector<AmazingEngine::Matrix3x3f>> mat3x3f_vec_;
    std::shared_ptr<AmazingEngine::PrimitiveVector<AmazingEngine::Matrix4x4f>> mat4x4f_vec_;
    std::shared_ptr<BachVector> bach_vec_;
    std::shared_ptr<BachMap> bach_map_;
};

/**
 * @brief `Bach::BachVector` wrapper around `std::vector<BachObject>` (`+0x10..+0x27`)
 *        [OBSERVED at 0x00a420: add x1, x0, #0x10; bl #0xbec8].
 *        Lớp bao `Bach::BachVector` chứa `std::vector<BachObject>` tại độ lệch +0x10.
 */
class BachVector : public AmazingEngine::RefBase {
public:
    BachVector() = default;
    explicit BachVector(std::vector<BachObject> items) : items_(std::move(items)) {}
    ~BachVector() noexcept override = default;

    const std::vector<BachObject>& items() const noexcept { return items_; }
    std::vector<BachObject>& items() noexcept { return items_; }

private:
    std::vector<BachObject> items_; // +0x10..+0x27
};

/**
 * @brief `Bach::BachMap` (56 bytes = 0x38) with vtable at .data.rel.ro 0x01f988 (+0x10 = 0x01f998)
 *        and destructors at 0x00e13c (D1) and 0x00e16c (D0) [OBSERVED at 0x00df88..0x00e1a0].
 *        Cấu trúc `Bach::BachMap` (56 byte = 0x38) lưu trữ bảng băm `std::unordered_map<std::string, BachObject>`.
 *
 * Layout [OBSERVED]:
 *   +0x00: vtable pointer (0x01f998)
 *   +0x08: int32_t ref_count_ (0)
 *   +0x10: std::unordered_map<std::string, BachObject> map_ (40 bytes: +0x10..+0x37, max_load_factor = 1.0f at +0x30)
 */
class BachMap : public AmazingEngine::RefBase {
public:
    BachMap() {
        map_.max_load_factor(1.0f); // [OBSERVED at 0x00df68: mov w25, #0x3f800000; str w25, [x0, #0x30]]
    }
    ~BachMap() noexcept override = default;

    const std::unordered_map<std::string, BachObject>& map() const noexcept { return map_; }
    std::unordered_map<std::string, BachObject>& map() noexcept { return map_; }

private:
    std::unordered_map<std::string, BachObject> map_; // +0x10..+0x37
};

/**
 * @brief `Bach::BachBuffer` (56 bytes = 0x38) with vtable at .data.rel.ro 0x01f928 (+0x18 = 0x01f940)
 *        and destructors at 0x00dd3c (D1), 0x00dddc (D0), and clone() at 0x00de84 [OBSERVED].
 *        Bộ đệm kết quả thuật toán `Bach::BachBuffer` (56 byte = 0x38).
 *
 * Layout [OBSERVED at 0x005c84..0x005c9c & 0x00dd3c..0x00e040]:
 *   +0x00: vtable pointer (0x01f940)
 *   +0x08: int32_t ref_count_ (0)
 *   +0x10: int32_t type_ (and int32_t reserved_ at +0x14)
 *   +0x18: std::vector<BachMap*> maps_ (+0x18: begin, +0x20: end, +0x28: cap)
 *   +0x30: int64_t extra_meta_
 */
class BachBuffer : public AmazingEngine::RefBase {
public:
    BachBuffer() noexcept : type_(0), reserved_(0), extra_meta_(0) {}

    ~BachBuffer() noexcept override {
        // [OBSERVED at 0x00dd4c..0x00ddc4]: Iterates backwards from end_ to begin_,
        // calling map->~RefBase() (+0x18) and map->release() (+0x08) on each non-null BachMap*.
        for (auto it = maps_.rbegin(); it != maps_.rend(); ++it) {
            if (*it != nullptr) {
                (*it)->release();
            }
        }
        maps_.clear();
    }

    /**
     * @brief Virtual clone method (`BachBuffer::clone` @ 0x00de84..0x00e040) [OBSERVED].
     *        Phương thức nhân bản sâu `BachBuffer::clone()` tại địa chỉ 0x00de84..0x00e040.
     */
    virtual BachBuffer* clone() const {
        auto* copy = new BachBuffer();
        copy->type_ = type_;
        copy->reserved_ = reserved_;
        copy->extra_meta_ = extra_meta_;
        copy->maps_.resize(maps_.size(), nullptr);
        for (size_t i = 0; i < maps_.size(); ++i) {
            auto* new_map = new BachMap();
            if (maps_[i] != nullptr) {
                new_map->map() = maps_[i]->map();
                if (copy->maps_[i] != nullptr && copy->maps_[i] != new_map) {
                    copy->maps_[i]->release();
                }
                copy->maps_[i] = new_map;
            } else {
                delete new_map;
                copy->maps_[i] = nullptr;
            }
        }
        return copy;
    }

    int32_t type() const noexcept { return type_; }
    void set_type(int32_t t) noexcept { type_ = t; }

    const std::vector<BachMap*>& maps() const noexcept { return maps_; }
    std::vector<BachMap*>& maps() noexcept { return maps_; }

private:
    int32_t type_;               // +0x10
    int32_t reserved_;           // +0x14
    std::vector<BachMap*> maps_; // +0x18..+0x2f
    int64_t extra_meta_;         // +0x30
};

/**
 * @brief Base class for algorithm execution inputs (`Bach::BachAlgorithmInput`).
 *        Lớp cơ sở cho đầu vào thực thi thuật toán (`Bach::BachAlgorithmInput`).
 */
class BachAlgorithmInput : public AmazingEngine::RefBase {
public:
    BachAlgorithmInput() noexcept = default;
    ~BachAlgorithmInput() noexcept override = default;
};

/**
 * @brief `Bach::BachImageBuffer` (112 bytes in full SDK; 56-byte input header in nativeExec
 *        with vtable at .data.rel.ro 0x01f8a8 + 0x18 = 0x01f8c0) [OBSERVED at 0x0053e0..0x005478 & 0x00ebfc..0x00ecdc].
 *        Bộ đệm ảnh `Bach::BachImageBuffer` hỗ trợ truyền ảnh đầu vào và đọc kết quả `BachBitmapHandle`.
 *
 * Layout [OBSERVED]:
 *   +0x00: vtable pointer (0x01f8c0)
 *   +0x08: int32_t ref_count_
 *   +0x10: int32_t input_type_ (1 = BitmapInput)
 *   +0x14: int32_t width_      ([x21 + 0x14] in nativeGet @ 0x00ebfc & [x22 + 0x14] in nativeExec @ 0x00541c)
 *   +0x18: int32_t height_     ([x21 + 0x18] in nativeGet @ 0x00ebfc & [x22 + 0x18] in nativeExec @ 0x005404)
 *   +0x1c: int32_t channels_   ([x22 + 0x1c] = 4 for RGBA8888, 1 for A8 @ 0x00545c)
 *   +0x20: int32_t stride_     ([x22 + 0x20] = width * channels @ 0x005460)
 *   +0x24: int32_t rotation_   ([x22 + 0x24] = 0)
 *   +0x28: PrimitiveVector<uint8_t>* input_data_ ([x22 + 0x28] in nativeExec @ 0x00547c)
 *   +0x30: int32_t input_format_ ([x22 + 0x30] = 3 for RGBA8888, 0 for GRAY8 @ 0x005458)
 *   --- Extended fields for output BachBitmapHandle (0x00eb38..0x00ecdc) ---
 *   +0x60: AmazingEngine::PrimitiveVector<uint8_t>* output_data_ ([x21 + 0x60] @ 0x00ec50)
 *   +0x68: BachPixelFormat output_format_ ([x21 + 0x68] @ 0x00ec2c)
 */
class BachImageBuffer : public BachAlgorithmInput {
public:
    BachImageBuffer() noexcept
        : input_type_(1),
          width_(0),
          height_(0),
          channels_(4),
          stride_(0),
          rotation_(0),
          input_data_(nullptr),
          input_format_(BachPixelFormat::kRGBA8888),
          output_data_(nullptr),
          output_format_(BachPixelFormat::kRGBA8888) {
        std::memset(reserved_pad_, 0, sizeof(reserved_pad_));
    }

    ~BachImageBuffer() noexcept override {
        if (input_data_ != nullptr) {
            input_data_->release();
            input_data_ = nullptr;
        }
        if (output_data_ != nullptr) {
            output_data_->release();
            output_data_ = nullptr;
        }
    }

    int32_t input_type() const noexcept { return input_type_; }
    void set_input_type(int32_t t) noexcept { input_type_ = t; }

    int32_t width() const noexcept { return width_; }
    void set_width(int32_t w) noexcept { width_ = w; }

    int32_t height() const noexcept { return height_; }
    void set_height(int32_t h) noexcept { height_ = h; }

    int32_t channels() const noexcept { return channels_; }
    void set_channels(int32_t c) noexcept { channels_ = c; }

    int32_t stride() const noexcept { return stride_; }
    void set_stride(int32_t s) noexcept { stride_ = s; }

    AmazingEngine::PrimitiveVector<uint8_t>* input_data() const noexcept { return input_data_; }
    void set_input_data(AmazingEngine::PrimitiveVector<uint8_t>* d) noexcept { input_data_ = d; }

    BachPixelFormat input_format() const noexcept { return input_format_; }
    void set_input_format(BachPixelFormat f) noexcept { input_format_ = f; }

    AmazingEngine::PrimitiveVector<uint8_t>* output_data() const noexcept { return output_data_; }
    void set_output_data(AmazingEngine::PrimitiveVector<uint8_t>* d) noexcept { output_data_ = d; }

    BachPixelFormat output_format() const noexcept { return output_format_; }
    void set_output_format(BachPixelFormat f) noexcept { output_format_ = f; }

private:
    int32_t input_type_;                                     // +0x10
    int32_t width_;                                          // +0x14
    int32_t height_;                                         // +0x18
    int32_t channels_;                                       // +0x1c
    int32_t stride_;                                         // +0x20
    int32_t rotation_;                                       // +0x24
    AmazingEngine::PrimitiveVector<uint8_t>* input_data_;    // +0x28
    BachPixelFormat input_format_;                           // +0x30
    uint8_t reserved_pad_[0x60 - 0x34];                      // +0x34..+0x5f
    AmazingEngine::PrimitiveVector<uint8_t>* output_data_;   // +0x60
    BachPixelFormat output_format_;                          // +0x68
};

/**
 * @brief `Bach::BachMultiInput` (64 bytes = 0x40 on stack at sp+0x58 in nativeExec)
 *        with vtable at .data.rel.ro 0x01f8f0 (+0x18 = 0x01f908) [OBSERVED at 0x0059d8..0x005a28].
 *        Đầu vào đa luồng ảnh `Bach::BachMultiInput` chứa bảng băm `unordered_map<string, BachImageBuffer*>`.
 */
class BachMultiInput : public BachAlgorithmInput {
public:
    BachMultiInput() {
        inputs_.max_load_factor(1.0f);
    }

    ~BachMultiInput() noexcept override {
        for (auto& kv : inputs_) {
            if (kv.second != nullptr) {
                kv.second->release();
            }
        }
        inputs_.clear();
    }

    const std::unordered_map<std::string, BachImageBuffer*>& inputs() const noexcept { return inputs_; }
    std::unordered_map<std::string, BachImageBuffer*>& inputs() noexcept { return inputs_; }

private:
    int32_t input_type_ = 3; // +0x10 (3 = BachMultiInput)
    std::unordered_map<std::string, BachImageBuffer*> inputs_; // +0x18..+0x3f
};

/**
 * @brief `Bach::BachAlgorithmOutput` returned by `BachAlgorithmSystem::getResult` (vtable +0x78)
 *        [OBSERVED at 0x005c60..0x005cf8].
 *        Kết quả đầu ra thuật toán `Bach::BachAlgorithmOutput`.
 *
 * Vtable layout [OBSERVED]:
 *   +0x00..+0x20: RefBase methods
 *   +0x28: int32_t getResultType() const (called at 0x005ca0: ldr x8, [x8, #0x28])
 *   +0x30: const BachBuffer* getDirectBuffer() const
 */
class BachAlgorithmOutput : public AmazingEngine::RefBase {
public:
    explicit BachAlgorithmOutput(int32_t result_type = 0) noexcept : result_type_(result_type) {}
    ~BachAlgorithmOutput() noexcept override = default;

    virtual int32_t getResultType() const noexcept { return result_type_; }
    const BachBuffer& buffer() const noexcept { return buffer_; }
    BachBuffer& buffer() noexcept { return buffer_; }

private:
    int32_t result_type_;
    BachBuffer buffer_;
};

/**
 * @brief Initialization config passed to `BachAlgorithmSystem::init` (vtable +0x10)
 *        [OBSERVED at 0x003af4..0x003b8c: 64 bytes on stack sp+0x50..sp+0x8f].
 *        Cấu hình khởi tạo truyền vào `BachAlgorithmSystem::init`.
 */
struct BachSystemInitConfig {
    int32_t struct_type = 1;       // +0x00 [OBSERVED at 0x003afc: mov w8, #1; str w8, [sp, #0x50]]
    int32_t reserved = 0;          // +0x04
    int64_t resource_finder = 0;   // +0x08 [OBSERVED at 0x003b04: str x23, [sp, #0x58]]
    std::string application_name;  // +0x10..+0x27 [OBSERVED at 0x003b14: add x8, sp, #0x60]
    std::string device_name;       // +0x28..+0x3f [OBSERVED at 0x003b28: add x8, sp, #0x78]
};

/**
 * @brief `Bach::BachAlgorithmSystem` virtual interface [OBSERVED across 0x0039c4..0x0061e0].
 *        Giao diện ảo của hệ thống thuật toán `Bach::BachAlgorithmSystem`.
 *
 * Vtable Offsets [OBSERVED]:
 *   +0x00: retain()
 *   +0x08: release()
 *   +0x10: int init(const BachSystemInitConfig&)         (@ 0x003b30: ldr x8, [x8, #0x10])
 *   +0x18: int initGraph(const std::string& configPath)  (@ 0x003c38: ldr x8, [x8, #0x18])
 *   +0x20: int initGraphWithConfig(...)
 *   +0x28: int exec(BachAlgorithmInput* input)           (@ 0x005484 & 0x005a30: ldr x8, [x8, #0x28])
 *   +0x30..+0x38: reserved exec overloads
 *   +0x40: int setEnable(const std::string& name, bool)  (@ 0x003cfd: ldr x8, [x8, #0x40])
 *   +0x48..+0x58: single parameter setters
 *   +0x60: int setIntParams(const std::string&, const std::unordered_map<std::string, int64_t>&)    (@ 0x004194)
 *   +0x68: int setFloatParams(const std::string&, const std::unordered_map<std::string, float>&)    (@ 0x004900)
 *   +0x70: int setStringParams(const std::string&, const std::unordered_map<std::string, std::string>&) (@ 0x004f8c)
 *   +0x78: BachAlgorithmOutput* getResult(const std::string& name, int index) (@ 0x005c60: ldr x8, [x8, #0x78])
 */
class BachAlgorithmSystem : public AmazingEngine::RefBase {
public:
    ~BachAlgorithmSystem() noexcept override = default;

    virtual int init(const BachSystemInitConfig& config) = 0;                                                         // +0x10
    virtual int initGraph(const std::string& config_path) = 0;                                                        // +0x18
    virtual int initGraphReserved() { return 0; }                                                                     // +0x20
    virtual int exec(BachAlgorithmInput* input) = 0;                                                                  // +0x28
    virtual int execReserved1() { return 0; }                                                                         // +0x30
    virtual int execReserved2() { return 0; }                                                                         // +0x38
    virtual int setEnable(const std::string& algorithm_name, bool enable) = 0;                                        // +0x40
    virtual int setParamReserved1() { return 0; }                                                                     // +0x48
    virtual int setParamReserved2() { return 0; }                                                                     // +0x50
    virtual int setParamReserved3() { return 0; }                                                                     // +0x58
    virtual int setIntParams(const std::string& algorithm_name,
                             const std::unordered_map<std::string, int64_t>& params) = 0;                             // +0x60
    virtual int setFloatParams(const std::string& algorithm_name,
                               const std::unordered_map<std::string, float>& params) = 0;                             // +0x68
    virtual int setStringParams(const std::string& algorithm_name,
                                const std::unordered_map<std::string, std::string>& params) = 0;                      // +0x70
    virtual BachAlgorithmOutput* getResult(const std::string& algorithm_name, int32_t index) = 0;                     // +0x78
};

/**
 * @brief Imported `Bach::BachAlgorithmFactory` methods (`.dynsym` [040] & [041]) [OBSERVED].
 *        Nhà máy khởi tạo và hủy `BachAlgorithmSystem` nhập khẩu từ `libbach-sdk.so`.
 */
class BachAlgorithmFactory {
public:
    static BachAlgorithmSystem* CreateAlgorithmSystem();
    static int DestroyAlgorithmSystem(BachAlgorithmSystem* system);
};

/**
 * @brief Imported `Bach::ToGeneralBuffer(const BachAlgorithmOutput*, BachBuffer*)` (`.dynsym` [042]) [OBSERVED].
 *        Hàm chuyển đổi `BachAlgorithmOutput` sang `BachBuffer` tổng quát.
 */
void ToGeneralBuffer(const BachAlgorithmOutput* output, BachBuffer* out_buffer);

} // namespace Bach
} // namespace bach_sdk
} // namespace bytedance
} // namespace com

#endif // NEXTAI_OPENCUT_BACH_SDK_JNI_TYPES_H_
