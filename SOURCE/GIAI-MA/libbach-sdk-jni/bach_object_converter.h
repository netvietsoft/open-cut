/**
 * @file bach_object_converter.h
 * @brief CityHash64, 30-Way BachObject-to-Java Converter, NEON Widening Loops, and Pixel Converters for libbach-sdk-jni.so.
 *        Hàm băm CityHash64, bộ chuyển đổi 30 nhánh BachObject sang Java, vòng lặp mở rộng NEON và chuyển đổi pixel cho libbach-sdk-jni.so.
 *
 * Target Binary / Nhị phân mục tiêu:
 *   - File: libbach-sdk-jni.so (117,112 bytes)
 *   - SHA-256: 6330cb09b6721ef41639c6ed472b4d60e3b81a9f03c699f5d8c1cbefe5804929
 *   - Disassembly Ranges Covered / Dải mã máy bao phủ:
 *     * 0x005cc0..0x005d5c: Power-of-two bucket mask & NEON popcount lookup (`cnt v0.8b, v0.8b; uaddlv h0, v0.8b`)
 *     * 0x006be0..0x007028: `std::__ndk1::__murmur2_or_cityhash<uint64_t, 64>::operator()` (CityHash64)
 *     * 0x00702c..0x00a980: `convertBachObjectToJava` (30-way jump table @ `.rodata 0x014f5c..0x014f97`)
 *     * 0x00a994..0x00b80c: 6 NEON SIMD widening & 32-byte vector copy loops
 *     * 0x00eb38..0x00edcf: `Java_com_bytedance_byted_1bach_1sdk_buffer_BachBitmapHandle_nativeGet`
 *     * 0x00ff4c..0x0102ac: 4 NEON pixel format converters (`GRAY8/RGB888/BGR888/BGRA8888 -> RGBA8888`)
 */

#ifndef NEXTAI_OPENCUT_BACH_OBJECT_CONVERTER_H_
#define NEXTAI_OPENCUT_BACH_OBJECT_CONVERTER_H_

#include "bach_sdk_jni_types.h"

#include <cstddef>
#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace com {
namespace bytedance {
namespace bach_sdk {

// ============================================================================
// 1. CityHash64 & NEON Popcount Hash Bucket Indexing (0x005cc0..0x007028)
//    Hàm băm CityHash64 & Định vị thùng băm bằng NEON Popcount [OBSERVED]
// ============================================================================

/**
 * @brief Exact constants and implementation of `std::__ndk1::__murmur2_or_cityhash<uint64_t, 64>`
 *        disassembled at `0x006be0..0x007028` [OBSERVED].
 *        Hằng số và cài đặt chuẩn xác của `CityHash64` giải mã tại `0x006be0..0x007028`.
 */
struct BachCityHash64 {
    static constexpr uint64_t k0   = 0xc3a5c85c97cb3127ULL; // [OBSERVED at 0x006ce0..0x006cec]
    static constexpr uint64_t k1   = 0xb492b66fbe98f273ULL; // [OBSERVED at 0x006bf8..0x006c04]
    static constexpr uint64_t k2   = 0x9ae16a3b2f90404fULL; // [OBSERVED at 0x006c20..0x006c2c]
    static constexpr uint64_t k3   = 0xc949d7c7509e6557ULL; // [OBSERVED at 0x006cc8..0x006cd4]
    static constexpr uint64_t kMul = 0x9ddfea08eb382d69ULL; // [OBSERVED at 0x006c80..0x006c8c]

    static uint64_t RotateRight64(uint64_t val, unsigned shift) noexcept;
    static uint64_t ShiftMix(uint64_t val) noexcept;
    static uint64_t HashLen16(uint64_t u, uint64_t v, uint64_t mul = kMul) noexcept;
    static uint64_t HashLen0to16(const uint8_t* s, size_t len) noexcept;
    static uint64_t HashLen17to32(const uint8_t* s, size_t len) noexcept;
    static uint64_t HashLen33to64(const uint8_t* s, size_t len) noexcept;
    static std::pair<uint64_t, uint64_t> WeakHashLen32WithSeeds(
        uint64_t w, uint64_t x, uint64_t y, uint64_t z, uint64_t a, uint64_t b) noexcept;
    static std::pair<uint64_t, uint64_t> WeakHashLen32WithSeeds(
        const uint8_t* s, uint64_t a, uint64_t b) noexcept;

    /**
     * @brief Entry point matching `0x006be0..0x007028` (`_ZNKSt6__ndk121__murmur2_or_cityhashImLm64EEclEPKvm`).
     *        Điểm vào khớp chuẩn xác hàm `0x006be0..0x007028`.
     */
    static uint64_t Hash(const void* key, size_t len) noexcept;
};

/**
 * @brief Computes bucket index in `std::__ndk1::__hash_table` using the exact AArch64 NEON
 *        popcount idiom observed at `0x005cc0..0x005cde` and `0x0062e0..0x0062fc` [OBSERVED]:
 *          `fmov d0, x8; cnt v0.8b, v0.8b; uaddlv h0, v0.8b; fmov w10, s0; cmp w10, #1`
 *        Tính chỉ số thùng băm theo đúng cụm lệnh NEON popcount tại `0x005cc0..0x005cde`.
 */
size_t ComputeLibcxxHashBucketIndex(uint64_t hash, size_t bucket_count) noexcept;

// ============================================================================
// 2. Java Value Representation for `convertBachObjectToJava` (0x00702c..0x00a980)
//    Biểu diễn đối tượng Java cho hàm `convertBachObjectToJava` [OBSERVED]
// ============================================================================

struct JavaBachObject;

/**
 * @brief Mirror of `com/bytedance/byted_bach_sdk/buffer/AlgorithmResultUnion` constructed across
 *        all 30 cases of `convertBachObjectToJava` (`0x00702c..0x00a980`) [OBSERVED].
 *        Cấu trúc phản chiếu lớp Java `com/bytedance/byted_bach_sdk/buffer/AlgorithmResultUnion`.
 */
struct JavaAlgorithmResultUnion {
    int64_t int64_val = 0;                                    // J (Case 1)
    std::vector<int64_t> int64_vec;                           // [J (Cases 2, 15..20)
    double double_val = 0.0;                                  // D (Case 3)
    std::vector<double> double_vec;                           // [D (Cases 4, 21)
    AmazingEngine::Vector2f vec2f_val{0.0f, 0.0f};            // Vec2f (Case 5)
    AmazingEngine::Vector3f vec3f_val{0.0f, 0.0f, 0.0f};      // Vec3f (Case 6)
    AmazingEngine::Vector4f vec4f_val{0.0f, 0.0f, 0.0f, 0.0f};// Vec4f (Case 7)
    AmazingEngine::Quaternionf quatf_val{0.0f, 0.0f, 0.0f, 1.0f}; // Quatf (Case 8)
    AmazingEngine::Matrix3x3f mat3x3f_val{};                  // Mat3x3f (Case 9)
    AmazingEngine::Matrix4x4f mat4x4f_val{};                  // Mat4x4f (Case 10)
    std::string string_val;                                   // String (Case 11)
    int64_t bitmap_handle_ptr = 0;                            // BachBitmapHandle.m_pointer (Case 12)
    AmazingEngine::Rect rect_val{0.0f, 0.0f, 0.0f, 0.0f};     // RectF (Case 13)
    AmazingEngine::Color color_val{0.0f, 0.0f, 0.0f, 1.0f};   // Color (Case 14)
    std::vector<std::string> string_vec;                      // ArrayList<String> (Case 22)
    std::vector<std::shared_ptr<JavaBachObject>> vec_val;     // BachObject[] (Cases 23..29)
    std::unordered_map<std::string, std::shared_ptr<JavaBachObject>> map_val; // HashMap<String, BachObject> (Case 30)
};

/**
 * @brief Mirror of `com/bytedance/byted_bach_sdk/buffer/BachObject` constructed at the tail
 *        of `convertBachObjectToJava` (`0x009824..0x0098b8`) [OBSERVED].
 *        Cấu trúc phản chiếu lớp Java `com/bytedance/byted_bach_sdk/buffer/BachObject`.
 *
 * Constructor signature at `.rodata 0x01514d` [OBSERVED]:
 *   `(Lcom/bytedance/byted_bach_sdk/buffer/AlgorithmResultValueType;Lcom/bytedance/byted_bach_sdk/buffer/AlgorithmResultUnion;)V`
 */
struct JavaBachObject {
    Bach::BachObjectType value_type = Bach::BachObjectType::kNone;
    JavaAlgorithmResultUnion value_union;
};

/**
 * @brief Converts a native `Bach::BachObject` into its Java representation following the exact
 *        30-way jump table at `0x00702c..0x00a980` (`.rodata 0x014f5c..0x014f97`) [OBSERVED].
 *        Chuyển đổi đối tượng `Bach::BachObject` sang cấu trúc Java theo đúng bảng nhảy 30 nhánh.
 */
std::shared_ptr<JavaBachObject> ConvertBachObjectToJava(const Bach::BachObject& obj);

/**
 * @brief Computes the exact AArch64 branch target VA for a given `BachObjectType` (`1..30`)
 *        using the `.rodata 0x014f5c` displacement table (`0x007084 + (int16_t)offset * 4`) [OBSERVED].
 *        Tính địa chỉ nhảy AArch64 chuẩn xác cho từng mã `BachObjectType` (`1..30`).
 */
uint64_t ComputeConvertBachObjectBranchTargetVa(Bach::BachObjectType type) noexcept;

// ============================================================================
// 3. 6 NEON SIMD Vector Widening & Copy Routines (0x00a994..0x00b80c)
//    6 hàm mở rộng kiểu dữ liệu & sao chép vector bằng NEON SIMD [OBSERVED]
// ============================================================================

/**
 * @brief Widens `uint16_t` array to `int64_t` vector (`0x00a994..0x00aad0`, `ushll v0.4s, v0.4h, #0`) [OBSERVED].
 *        Mở rộng mảng `uint16_t` sang `int64_t` khớp vòng lặp NEON tại `0x00a994..0x00aad0`.
 */
std::vector<int64_t> WidenUint16ToInt64Vector(const uint16_t* begin, const uint16_t* end);

/**
 * @brief Widens `int16_t` array to `int64_t` vector (`0x00ac64..0x00ada0`, `sshll v0.4s, v0.4h, #0`) [OBSERVED].
 *        Mở rộng mảng `int16_t` sang `int64_t` khớp vòng lặp NEON tại `0x00ac64..0x00ada0`.
 */
std::vector<int64_t> WidenInt16ToInt64Vector(const int16_t* begin, const int16_t* end);

/**
 * @brief Widens `uint32_t` array to `int64_t` vector (`0x00af34..0x00b05c`, `ushll v0.2d, v0.2s, #0`) [OBSERVED].
 *        Mở rộng mảng `uint32_t` sang `int64_t` khớp vòng lặp NEON tại `0x00af34..0x00b05c`.
 */
std::vector<int64_t> WidenUint32ToInt64Vector(const uint32_t* begin, const uint32_t* end);

/**
 * @brief Widens `int32_t` array to `int64_t` vector (`0x00b1f0..0x00b318`, `sshll v0.2d, v0.2s, #0`) [OBSERVED].
 *        Mở rộng mảng `int32_t` sang `int64_t` khớp vòng lặp NEON tại `0x00b1f0..0x00b318`.
 */
std::vector<int64_t> WidenInt32ToInt64Vector(const int32_t* begin, const int32_t* end);

/**
 * @brief Widens `float` array to `double` vector (`0x00b4ac..0x00b5d4`, `fcvtl v0.2d, v0.2s`) [OBSERVED].
 *        Mở rộng mảng `float` sang `double` khớp vòng lặp NEON tại `0x00b4ac..0x00b5d4`.
 */
std::vector<double> WidenFloatToDoubleVector(const float* begin, const float* end);

/**
 * @brief Copies 64-bit elements in 32-byte blocks (`0x00b768..0x00b80c`, `ldp q0, q1` / `stp q0, q1`) [OBSERVED].
 *        Sao chép mảng phần tử 64-bit theo khối 32-byte khớp vòng lặp NEON tại `0x00b768..0x00b80c`.
 */
template <typename T64>
std::vector<T64> CopyAligned64BitVector(const T64* begin, const T64* end);

// ============================================================================
// 4. BachBitmapHandle_nativeGet & 4 NEON Pixel Converters (0x00eb38..0x0102ac)
//    Hàm BachBitmapHandle_nativeGet & 4 bộ chuyển đổi điểm ảnh NEON [OBSERVED]
// ============================================================================

/**
 * @brief Converts `GRAY8` (1 byte/pixel) to `RGBA8888` (4 bytes/pixel, `R=G=B=Y, A=0xFF`)
 *        matching `0x00ff4c..0x010008` (`ldp q0, q4; movi v3.16b, #0xff; st4 {v0..v3}`) [OBSERVED].
 *        Chuyển đổi định dạng `GRAY8` sang `RGBA8888` khớp hàm NEON tại `0x00ff4c..0x010008`.
 */
void ConvertGray8ToRGBA8888(const uint8_t* src, uint8_t* dst, int32_t pixel_count) noexcept;

/**
 * @brief Converts `RGB888` (3 bytes/pixel) to `RGBA8888` (4 bytes/pixel, `A=0xFF`)
 *        matching `0x01000c..0x0100d8` (`ld3 {v0.16b..v2.16b}; movi v3.16b, #0xff; st4 {v0..v3}`) [OBSERVED].
 *        Chuyển đổi định dạng `RGB888` sang `RGBA8888` khớp hàm NEON tại `0x01000c..0x0100d8`.
 */
void ConvertRGB888ToRGBA8888(const uint8_t* src, uint8_t* dst, int32_t pixel_count) noexcept;

/**
 * @brief Converts `BGR888` (3 bytes/pixel) to `RGBA8888` (4 bytes/pixel, swapping B & R, `A=0xFF`)
 *        matching `0x0100dc..0x0101c4` (`ld3 {v3.16b, v1.16b, v2.16b}; mov v0.16b, v2.16b; st4`) [OBSERVED].
 *        Chuyển đổi định dạng `BGR888` sang `RGBA8888` khớp hàm NEON tại `0x0100dc..0x0101c4`.
 */
void ConvertBGR888ToRGBA8888(const uint8_t* src, uint8_t* dst, int32_t pixel_count) noexcept;

/**
 * @brief Converts `BGRA8888` (4 bytes/pixel) to `RGBA8888` (4 bytes/pixel, swapping B & R, keeping G & A)
 *        matching `0x0101c8..0x0102ac` (`ld4 {v0.16b..v3.16b}; mov v4.16b, v0.16b; mov v0.16b, v2.16b; st4`) [OBSERVED].
 *        Chuyển đổi định dạng `BGRA8888` sang `RGBA8888` khớp hàm NEON tại `0x0101c8..0x0102ac`.
 */
void ConvertBGRA8888ToRGBA8888(const uint8_t* src, uint8_t* dst, int32_t pixel_count) noexcept;

/**
 * @brief Executes the pixel extraction logic of `BachBitmapHandle.nativeGet` (`0x00eb38..0x00edcf`)
 *        converting `handle->output_data()` (`+0x60`) according to `handle->output_format()` (`+0x68`)
 *        into an `RGBA8888` output buffer (`width * height * 4` bytes) [OBSERVED].
 *        Thực thi logic trích xuất ảnh của `BachBitmapHandle.nativeGet` (`0x00eb38..0x00edcf`).
 */
bool ExtractBachBitmapHandleToRGBA8888(const Bach::BachImageBuffer* handle,
                                       std::vector<uint8_t>* out_rgba_pixels,
                                       int32_t* out_width,
                                       int32_t* out_height);

} // namespace bach_sdk
} // namespace bytedance
} // namespace com

#endif // NEXTAI_OPENCUT_BACH_OBJECT_CONVERTER_H_
