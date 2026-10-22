/**
 * @file bytevc2_cpu.cpp
 * @brief CPU Architecture and SIMD Instruction Capability Detection Implementation
 *        Thực thi phát hiện kiến trúc CPU và năng lực tập lệnh SIMD
 *
 * Implements CPU instruction probes matching ByteDance's libbyteVC2dec.so.
 * Thực thi kiểm tra tập lệnh CPU tương ứng với libbyteVC2dec.so của ByteDance.
 */

#include "bytevc2_cpu.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if defined(__linux__) || defined(__ANDROID__)
#include <sys/auxv.h>
#include <unistd.h>
#endif

static ByteVC2CpuCaps g_cached_cpu_caps = {0, 1, 64, "Generic Processor"};
static bool g_cpu_caps_initialized = false;

static void parse_proc_cpuinfo(ByteVC2CpuCaps* caps) {
    FILE* fp = fopen("/proc/cpuinfo", "r");
    if (!fp) {
        return;
    }

    char line[512];
    while (fgets(line, sizeof(line), fp)) {
        if (strncmp(line, "Features", 8) == 0 || strncmp(line, "flags", 5) == 0) {
            char* sep = strchr(line, ':');
            if (sep) {
                sep++; // Skip ':'
                if (strstr(sep, "neon") || strstr(sep, "asimd")) {
                    caps->features |= BYTEVC2_CPU_NEON;
                }
                if (strstr(sep, "fp") || strstr(sep, "fpu")) {
                    caps->features |= BYTEVC2_CPU_FP;
                }
                if (strstr(sep, "aes")) {
                    caps->features |= BYTEVC2_CPU_AES;
                }
                if (strstr(sep, "crc32")) {
                    caps->features |= BYTEVC2_CPU_CRC32;
                }
                if (strstr(sep, "sha1")) {
                    caps->features |= BYTEVC2_CPU_SHA1;
                }
                if (strstr(sep, "sha2")) {
                    caps->features |= BYTEVC2_CPU_SHA2;
                }
                if (strstr(sep, "sha3")) {
                    caps->features |= BYTEVC2_CPU_SHA3;
                }
                if (strstr(sep, "pmull")) {
                    caps->features |= BYTEVC2_CPU_PMULL;
                }
                if (strstr(sep, "fphp")) {
                    caps->features |= BYTEVC2_CPU_FPHP;
                }
                if (strstr(sep, "asimdhp")) {
                    caps->features |= BYTEVC2_CPU_ASIMDHP;
                }
                if (strstr(sep, "asimdrdm")) {
                    caps->features |= BYTEVC2_CPU_ASIMDRDM;
                }
                if (strstr(sep, "asimdfhm")) {
                    caps->features |= BYTEVC2_CPU_ASIMDFHM;
                }
                if (strstr(sep, "asimddp") || strstr(sep, "dotprod")) {
                    caps->features |= BYTEVC2_CPU_ASIMDDP;
                }
                if (strstr(sep, "i8mm")) {
                    caps->features |= BYTEVC2_CPU_I8MM;
                }
                if (strstr(sep, "sve")) {
                    caps->features |= BYTEVC2_CPU_SVE;
                }
                if (strstr(sep, "sve2")) {
                    caps->features |= BYTEVC2_CPU_SVE2;
                }
            }
        } else if (strncmp(line, "Processor", 9) == 0 || strncmp(line, "model name", 10) == 0) {
            char* sep = strchr(line, ':');
            if (sep) {
                sep++;
                while (*sep == ' ' || *sep == '\t') sep++;
                size_t len = strlen(sep);
                while (len > 0 && (sep[len - 1] == '\r' || sep[len - 1] == '\n')) {
                    sep[--len] = '\0';
                }
                if (len > 0) {
                    snprintf(caps->cpu_brand, sizeof(caps->cpu_brand), "%s", sep);
                }
            }
        }
    }
    fclose(fp);
}

uint32_t bytevc2_detect_cpu_features(ByteVC2CpuCaps* caps) {
    if (!caps) {
        return 0;
    }

    memset(caps, 0, sizeof(ByteVC2CpuCaps));
    caps->num_cores = 4;             // Default assumption
    caps->l1d_cache_line_size = 64;  // Standard ARM64 cache line
    snprintf(caps->cpu_brand, sizeof(caps->cpu_brand), "ByteVC2 Accelerated CPU");

#if defined(__aarch64__) || defined(_M_ARM64)
    caps->features |= BYTEVC2_CPU_ARMV8 | BYTEVC2_CPU_FP | BYTEVC2_CPU_NEON | BYTEVC2_CPU_CRC32;
#endif

    // Attempt to probe /proc/cpuinfo
    parse_proc_cpuinfo(caps);

    // If on ARM64 and NEON wasn't explicitly cleared, ensure standard baseline
#if defined(__aarch64__) || defined(_M_ARM64)
    caps->features |= BYTEVC2_CPU_NEON | BYTEVC2_CPU_FP;
#else
    // Host fallback simulation for desktop test runners
    caps->features |= BYTEVC2_CPU_ARMV8 | BYTEVC2_CPU_NEON | BYTEVC2_CPU_FP | BYTEVC2_CPU_CRC32 | BYTEVC2_CPU_ASIMDDP;
#endif

    return caps->features;
}

const ByteVC2CpuCaps* bytevc2_get_cpu_caps(void) {
    if (!g_cpu_caps_initialized) {
        bytevc2_detect_cpu_features(&g_cached_cpu_caps);
        g_cpu_caps_initialized = true;
    }
    return &g_cached_cpu_caps;
}
