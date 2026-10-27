/**
 * @file imagepipeline_interface.h
 * @brief Unified Clean-Room C++17 Public Interface for `libimagepipeline.so` (`264,328 bytes`)
 *        Giao diện công khai hợp nhất C++17 tái dựng sạch cho `libimagepipeline.so` (`264,328 byte`).
 *
 * Binary Telemetry / Thông số Nhị phân (`OBSERVED`):
 *   - Library Name  : `libimagepipeline.so` (Facebook Fresco ImagePipeline + Embedded `libjpeg-turbo 1.5.3`)
 *   - Exact Size    : `264,328 bytes` (`0x40888`)
 *   - SHA-256       : `38fed18184707429505cfabd7540d22f5560965d310b6501ae05a67a0f7d2266`
 *   - Architecture  : AArch64 (`EM_AARCH64`), Android NDK `r16b` (`4691159`), Clang `5.0.300080`
 *   - `.text`       : `0x001fc0 .. 0x037814` (`219,220 bytes`, 393 FDE functions in `.eh_frame_hdr` @ `0x03a8cc`)
 *   - `.rodata`     : `0x037820 .. 0x03a8ca` (`12,458 bytes`)
 *   - `.data.rel.ro`: vaddr `0x043768` (file `0x03f768`, `1,032 bytes`, 129 `jpeg_std_message_table` pointers)
 *   - `.data`       : vaddr `0x044000` (file `0x040000`, `240 bytes`, 10 `JNINativeMethod` descriptors across 4 Java classes)
 *   - `.bss`        : vaddr `0x0440f0` (`56 bytes`, 4 stream `jmethodID`s + 3 `RuntimeException` GlobalRefs)
 */

#ifndef NEXTAI_OPENCUT_IMAGEPIPELINE_INTERFACE_H_
#define NEXTAI_OPENCUT_IMAGEPIPELINE_INTERFACE_H_

#include "imagepipeline_types.h"
#include "imagepipeline_rodata_tables.h"
#include "imagepipeline_fresco_jni.h"
#include "imagepipeline_jpeg_turbo_engine.h"

namespace nextai {
namespace opencut {
namespace imagepipeline {

/**
 * @brief Static binary metadata descriptor for `libimagepipeline.so` (`OBSERVED`).
 *        Bộ mô tả siêu dữ liệu tĩnh của file nhị phân `libimagepipeline.so` (`OBSERVED`).
 */
struct ImagePipelineBinaryDescriptor {
    const char* library_name;
    uint32_t    file_size_bytes;
    const char* sha256_hex;
    uint32_t    text_vaddr;
    uint32_t    text_size;
    uint32_t    rodata_vaddr;
    uint32_t    rodata_size;
    uint32_t    data_rel_ro_vaddr;
    uint32_t    data_rel_ro_size;
    uint32_t    data_vaddr;
    uint32_t    data_size;
    uint32_t    bss_vaddr;
    uint32_t    bss_size;
    uint32_t    eh_frame_fde_count;
    uint32_t    jni_class_count;
    uint32_t    jni_method_count;
};

/**
 * @brief Returns the immutable binary metadata descriptor for `libimagepipeline.so`.
 *        Trả về bộ mô tả siêu dữ liệu nhị phân bất biến của `libimagepipeline.so`.
 */
const ImagePipelineBinaryDescriptor& GetImagePipelineBinaryDescriptor() noexcept;

/**
 * @brief Runs the deterministic mathematical and ABI self-verification suite for `libimagepipeline.so`.
 *        Chạy bộ kiểm thử tự xác minh toán học và ABI tất định cho `libimagepipeline.so`:
 *          1. Validates EXIF orientation (`1..8`) -> `FrescoRotationType` (`.rodata 0x037c00`) and
 *             `FrescoRotationType` (`1..7`) -> `JXFORM_CODE` (`.rodata 0x037b28`).
 *          2. Validates all 10 `JNINativeMethod` entries at `.data 0x044000..0x0440f0` across the 4 Java classes.
 *          3. Validates `jpeg_compress_struct` (`0x248` = 584 B), `jpeg_decompress_struct` (`0x290` = 656 B),
 *             and `jpeg_transform_info` (`0x60` = 96 B) initialization and IJG quality scaling (`5000/q` vs `200-2q`).
 *          4. Validates Dihedral group $D_4$ lossless 8x8 DCT transformations (`JXFORM_FLIP_H` .. `JXFORM_ROT_270`)
 *             including involutions ($T^2 = I$) and 4-fold rotation cycle ($R_{90}^4 = I$).
 *          5. Validates `NativeMemoryChunk` allocation, bounds-checked byte array copy, `memcpy`, and single-byte read.
 *
 * @return `true` if all mathematical, ABI, and `.rodata`/`.data` invariants pass 100%; `false` otherwise.
 */
bool RunImagePipelineSelfTest() noexcept;

} // namespace imagepipeline
} // namespace opencut
} // namespace nextai

#endif // NEXTAI_OPENCUT_IMAGEPIPELINE_INTERFACE_H_
