/**
 * @file bach_algorithm_system_jni.h
 * @brief BachAlgorithmSystem JNI Bridge, .init_array[0] Result Type Registry, and Output Packaging for libbach-sdk-jni.so.
 *        Cầu nối JNI BachAlgorithmSystem, bộ đăng ký 39 mã kết quả .init_array[0] và đóng gói đầu ra cho libbach-sdk-jni.so.
 *
 * Target Binary / Nhị phân mục tiêu:
 *   - File: libbach-sdk-jni.so (117,112 bytes)
 *   - SHA-256: 6330cb09b6721ef41639c6ed472b4d60e3b81a9f03c699f5d8c1cbefe5804929
 *   - Disassembly Ranges Covered / Dải mã máy bao phủ:
 *     * 0x003820..0x0038f4: `_GLOBAL__sub_I_BachAlgorithmSystemJNI.cpp` (`.init_array[0]`, 39 result types -> `.bss 0x020010`)
 *     * 0x0039c4..0x003bfb: `Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeCreate`
 *     * 0x003bfc..0x003c8b: `Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeInitGraph`
 *     * 0x003c8c..0x003d77: `Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeSetEnable`
 *     * 0x003d78..0x0044e3: `Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeSetIntParams`
 *     * 0x0044e4..0x004b1b: `Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeSetFloatParams`
 *     * 0x004b1c..0x00515b: `Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeSetStringParams`
 *     * 0x00515c..0x00519b: `Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeDestroy`
 *     * 0x00519c..0x005c13: `Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeExec`
 *     * 0x005c14..0x0061e0: `Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeGetResult`
 */

#ifndef NEXTAI_OPENCUT_BACH_ALGORITHM_SYSTEM_JNI_H_
#define NEXTAI_OPENCUT_BACH_ALGORITHM_SYSTEM_JNI_H_

#include "bach_object_converter.h"
#include "bach_sdk_jni_types.h"

#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace com {
namespace bytedance {
namespace bach_sdk {

// ============================================================================
// 1. .init_array[0] Global Result Type Set (.bss 0x020010, .rodata 0x014f98)
//    Tập hợp 39 mã loại kết quả toàn cục khởi tạo từ .init_array[0] [OBSERVED]
// ============================================================================

/**
 * @brief Initializes and returns the global `std::unordered_set<int32_t>` corresponding to
 *        `.bss 0x020010` populated by `_GLOBAL__sub_I_BachAlgorithmSystemJNI.cpp` (`0x003820..0x0038f4`)
 *        from `.rodata 0x014f98..0x015033` (39 `int32_t` values, `cmp x21, #0x9c`) [OBSERVED].
 *        Khởi tạo và trả về tập hợp 39 mã kết quả toàn cục tương ứng với `.bss 0x020010`.
 */
const std::unordered_set<int32_t>& GetGlobalDirectBufferResultTypes();

/**
 * @brief Checks if `result_type` is present in `.bss 0x020010` (`0x005ca8..0x005d5c`) [OBSERVED].
 *        Kiểm tra xem `result_type` có nằm trong tập hợp `.bss 0x020010` hay không.
 */
bool IsDirectBufferResultType(int32_t result_type);

// ============================================================================
// 2. Java Algorithm Output Hierarchy Mirrors (0x005c14..0x0061e0)
//    Cấu trúc phân cấp đầu ra thuật toán phía Java [OBSERVED]
// ============================================================================

enum class JavaOutputClassKind : int32_t {
    kGenericBachAlgorithmOutput            = 0, // com/bytedance/byted_bach_sdk/output/BachAlgorithmOutput
    kFaceAlgorithmOutput                   = 8, // com/bytedance/byted_bach_sdk/output/BachFaceAlgorithmOutput (type == 8 @ 0x005ff0)
    kExpressionDetectAlgorithmOutput       = 13 // com/bytedance/byted_bach_sdk/output/BachExpressionDetectAlgorithmOutput (type == 13 @ 0x005ff8)
};

/**
 * @brief Mirror of `BachAlgorithmOutput` / `BachFaceAlgorithmOutput` / `BachExpressionDetectAlgorithmOutput`
 *        constructed in `nativeGetResult` (`0x005c14..0x0061e0`) [OBSERVED].
 *        Cấu trúc phản chiếu đầu ra thuật toán được đóng gói tại `nativeGetResult` (`0x005c14..0x0061e0`).
 */
struct JavaAlgorithmOutputPackage {
    int32_t result_type = 0;
    JavaOutputClassKind output_class = JavaOutputClassKind::kGenericBachAlgorithmOutput;
    bool used_direct_buffer = false;
    std::vector<std::unordered_map<std::string, std::shared_ptr<JavaBachObject>>> result_maps;
};

// ============================================================================
// 3. Concrete Reference Implementation of `Bach::BachAlgorithmSystem`
//    Cài đặt tham chiếu đầy đủ của `Bach::BachAlgorithmSystem` [INFERRED]
// ============================================================================

class BachAlgorithmSystemImpl : public Bach::BachAlgorithmSystem {
public:
    BachAlgorithmSystemImpl();
    ~BachAlgorithmSystemImpl() noexcept override;

    int init(const Bach::BachSystemInitConfig& config) override;
    int initGraph(const std::string& config_path) override;
    int exec(Bach::BachAlgorithmInput* input) override;
    int setEnable(const std::string& algorithm_name, bool enable) override;
    int setIntParams(const std::string& algorithm_name,
                     const std::unordered_map<std::string, int64_t>& params) override;
    int setFloatParams(const std::string& algorithm_name,
                       const std::unordered_map<std::string, float>& params) override;
    int setStringParams(const std::string& algorithm_name,
                        const std::unordered_map<std::string, std::string>& params) override;
    Bach::BachAlgorithmOutput* getResult(const std::string& algorithm_name, int32_t index) override;

    // Inspection helpers for verification tests / Hàm kiểm tra phục vụ kiểm thử
    const Bach::BachSystemInitConfig& init_config() const noexcept { return init_config_; }
    const std::string& graph_config_path() const noexcept { return graph_config_path_; }
    bool is_enabled(const std::string& name) const;
    void RegisterMockOutput(const std::string& algorithm_name,
                            int32_t index,
                            Bach::BachAlgorithmOutput* output);

private:
    Bach::BachSystemInitConfig init_config_;
    std::string graph_config_path_;
    std::unordered_map<std::string, bool> enabled_algorithms_;
    std::unordered_map<std::string, std::unordered_map<std::string, int64_t>> int_params_;
    std::unordered_map<std::string, std::unordered_map<std::string, float>> float_params_;
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> string_params_;
    std::unordered_map<std::string, Bach::BachAlgorithmOutput*> outputs_;
    int32_t last_input_width_ = 0;
    int32_t last_input_height_ = 0;
};

// ============================================================================
// 4. Native Bridge Execution Helpers (0x0039c4..0x0061e0)
//    Các hàm thực thi cầu nối Native cho BachAlgorithmSystem [OBSERVED]
// ============================================================================

/**
 * @brief Executes `BachAlgorithmSystem_nativeCreate` (`0x0039c4..0x003bfb`) [OBSERVED].
 *        Thực thi logic tạo hệ thống của `BachAlgorithmSystem_nativeCreate`.
 */
int64_t NativeCreateBachAlgorithmSystem(int32_t finder_type,
                                        int64_t resource_finder_ptr,
                                        const std::string& application_name,
                                        const std::string& device_name);

/**
 * @brief Executes `BachAlgorithmSystem_nativeInitGraph` (`0x003bfc..0x003c8b`) [OBSERVED].
 *        Thực thi logic khởi tạo đồ thị của `BachAlgorithmSystem_nativeInitGraph`.
 */
int32_t NativeInitGraphBachAlgorithmSystem(int64_t system_ptr, const std::string& config_path);

/**
 * @brief Executes `BachAlgorithmSystem_nativeSetEnable` (`0x003c8c..0x003d77`) [OBSERVED].
 *        Thực thi logic bật/tắt thuật toán của `BachAlgorithmSystem_nativeSetEnable`.
 */
int32_t NativeSetEnableBachAlgorithmSystem(int64_t system_ptr,
                                           const std::string& algorithm_name,
                                           bool enable);

/**
 * @brief Executes `BachAlgorithmSystem_nativeSetIntParams` (`0x003d78..0x0044e3`) [OBSERVED].
 *        Thực thi logic thiết lập tham số nguyên của `BachAlgorithmSystem_nativeSetIntParams`.
 */
int32_t NativeSetIntParamsBachAlgorithmSystem(
    int64_t system_ptr,
    const std::string& algorithm_name,
    const std::unordered_map<std::string, int64_t>& params);

/**
 * @brief Executes `BachAlgorithmSystem_nativeSetFloatParams` (`0x0044e4..0x004b1b`) [OBSERVED].
 *        Thực thi logic thiết lập tham số thực của `BachAlgorithmSystem_nativeSetFloatParams`.
 */
int32_t NativeSetFloatParamsBachAlgorithmSystem(
    int64_t system_ptr,
    const std::string& algorithm_name,
    const std::unordered_map<std::string, float>& params);

/**
 * @brief Executes `BachAlgorithmSystem_nativeSetStringParams` (`0x004b1c..0x00515b`) [OBSERVED].
 *        Thực thi logic thiết lập tham số chuỗi của `BachAlgorithmSystem_nativeSetStringParams`.
 */
int32_t NativeSetStringParamsBachAlgorithmSystem(
    int64_t system_ptr,
    const std::string& algorithm_name,
    const std::unordered_map<std::string, std::string>& params);

/**
 * @brief Executes `BachAlgorithmSystem_nativeDestroy` (`0x00515c..0x00519b`) [OBSERVED].
 *        Thực thi logic hủy hệ thống của `BachAlgorithmSystem_nativeDestroy`.
 */
int32_t NativeDestroyBachAlgorithmSystem(int64_t system_ptr);

/**
 * @brief Executes `BachAlgorithmSystem_nativeExec` (`0x00519c..0x005c13`) for `inputType == 1`
 *        (`BachBitmapInput`: `ANDROID_BITMAP_FORMAT_RGBA_8888 = 1` or `ANDROID_BITMAP_FORMAT_A_8 = 8`) [OBSERVED].
 *        Thực thi `BachAlgorithmSystem_nativeExec` cho đầu vào đơn `BachBitmapInput` (`inputType == 1`).
 */
int32_t NativeExecBitmapInput(int64_t system_ptr,
                              int32_t width,
                              int32_t height,
                              int32_t android_bitmap_format,
                              const uint8_t* pixels,
                              size_t pixel_byte_count);

/**
 * @brief Executes `BachAlgorithmSystem_nativeExec` (`0x00519c..0x005c13`) for `inputType == 3`
 *        (`BachMultiInput`: map of named `BachBitmapInput` bitmaps) [OBSERVED].
 *        Thực thi `BachAlgorithmSystem_nativeExec` cho đầu vào đa luồng `BachMultiInput` (`inputType == 3`).
 */
struct NamedBitmapInputSlice {
    std::string name;
    int32_t width = 0;
    int32_t height = 0;
    int32_t android_bitmap_format = 1; // 1 = RGBA_8888, 8 = A_8
    std::vector<uint8_t> pixels;
};

int32_t NativeExecMultiInput(int64_t system_ptr,
                             const std::vector<NamedBitmapInputSlice>& slices);

/**
 * @brief Executes `BachAlgorithmSystem_nativeGetResult` (`0x005c14..0x0061e0`) [OBSERVED].
 *        Thực thi logic trích xuất và đóng gói kết quả của `BachAlgorithmSystem_nativeGetResult`.
 */
std::shared_ptr<JavaAlgorithmOutputPackage> NativeGetResultBachAlgorithmSystem(
    int64_t system_ptr,
    const std::string& algorithm_name,
    int32_t index);

} // namespace bach_sdk
} // namespace bytedance
} // namespace com

#endif // NEXTAI_OPENCUT_BACH_ALGORITHM_SYSTEM_JNI_H_
