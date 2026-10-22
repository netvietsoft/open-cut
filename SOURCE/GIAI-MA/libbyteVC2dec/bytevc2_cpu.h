/**
 * @file bytevc2_cpu.h
 * @brief CPU Architecture and SIMD Instruction Capability Detection for ByteVC2
 *        Phát hiện kiến trúc CPU và năng lực tập lệnh SIMD cho ByteVC2
 *
 * Implements cleanroom detection of ARMv8 NEON, ASIMD, Dot Product, I8MM, SVE, SVE2.
 * Thực thi phát hiện phòng sạch cho tập lệnh ARMv8 NEON, ASIMD, Dot Product, I8MM, SVE, SVE2.
 */

#ifndef BYTEVC2_CPU_H
#define BYTEVC2_CPU_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// CPU Feature Bit Flags / Cờ bit tính năng phần cứng CPU
#define BYTEVC2_CPU_ARMV7      (1U << 0)   ///< 32-bit ARMv7-A architecture
#define BYTEVC2_CPU_ARMV8      (1U << 1)   ///< 64-bit ARMv8-A architecture
#define BYTEVC2_CPU_FP         (1U << 2)   ///< Floating point hardware
#define BYTEVC2_CPU_NEON       (1U << 3)   ///< Advanced SIMD (NEON) vector registers
#define BYTEVC2_CPU_AES        (1U << 4)   ///< Hardware AES acceleration
#define BYTEVC2_CPU_CRC32      (1U << 5)   ///< Hardware CRC32 instructions
#define BYTEVC2_CPU_SHA1       (1U << 6)   ///< Hardware SHA-1 hashing
#define BYTEVC2_CPU_SHA2       (1U << 7)   ///< Hardware SHA-256 hashing
#define BYTEVC2_CPU_SHA3       (1U << 8)   ///< Hardware SHA-3/SHA-512 hashing
#define BYTEVC2_CPU_PMULL      (1U << 9)   ///< Polynomial multiplication 64-bit
#define BYTEVC2_CPU_FPHP       (1U << 10)  ///< Half-precision floating point
#define BYTEVC2_CPU_ASIMDHP    (1U << 11)  ///< Half-precision vector SIMD
#define BYTEVC2_CPU_ASIMDRDM   (1U << 12)  ///< Rounding Doubling Multiply Accumulate
#define BYTEVC2_CPU_ASIMDFHM   (1U << 13)  ///< Fast Half-precision Multiply
#define BYTEVC2_CPU_ASIMDDP    (1U << 14)  ///< Dot Product 8-bit vector arithmetic
#define BYTEVC2_CPU_I8MM       (1U << 15)  ///< 8-bit Integer Matrix Multiplication
#define BYTEVC2_CPU_SVE        (1U << 16)  ///< Scalable Vector Extension
#define BYTEVC2_CPU_SVE2       (1U << 17)  ///< Scalable Vector Extension 2

/**
 * @struct ByteVC2CpuCaps
 * @brief Detected CPU capabilities and cache parameters
 *        Thông số năng lực vi xử lý và bộ đệm đã phát hiện
 */
typedef struct ByteVC2CpuCaps {
    uint32_t features;             ///< Bitmask of BYTEVC2_CPU_* flags / Mặt nạ bit tính năng CPU
    uint32_t num_cores;            ///< Detected online core count / Số nhân CPU trực tuyến
    uint32_t l1d_cache_line_size;  ///< L1 Data cache line size in bytes / Kích thước dòng đệm L1D
    char cpu_brand[128];           ///< Processor model description string / Mô tả mẫu vi xử lý
} ByteVC2CpuCaps;

/**
 * @brief Detect available CPU features from system environment
 *        Phát hiện tính năng CPU khả dụng từ môi trường hệ thống
 * @param caps Pointer to structure receiving detected capabilities / Con trỏ nhận kết quả
 * @return Bitmask of detected features / Mặt nạ bit tính năng phát hiện được
 */
uint32_t bytevc2_detect_cpu_features(ByteVC2CpuCaps* caps);

/**
 * @brief Get global cached CPU capabilities
 *        Lấy thông số tính năng CPU lưu trong bộ đệm toàn cục
 * @return Read-only pointer to global CPU caps / Con trỏ chỉ đọc tới thông số CPU toàn cục
 */
const ByteVC2CpuCaps* bytevc2_get_cpu_caps(void);

#ifdef __cplusplus
}
#endif

#endif // BYTEVC2_CPU_H
