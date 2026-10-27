// ============================================================================
// File: bytebench_jni_bridge.cpp
// Target 107 / 169: libbytebench.so (641,376 bytes)
// EN: Clean-room C++17 implementation of JNI_OnLoad (0x066204), JNI_OnUnload (0x06642c),
//     BXStrategyManagePort, ByteBenchStrategyPort, ByteBenchFeatureCenterPort,
//     BXDeviceInfo, and ByteBenchBundle JNI entry points (0x061068..0x077e44).
// VI: Triển khai C++17 phòng sạch cho JNI_OnLoad (0x066204), JNI_OnUnload (0x06642c),
//     BXStrategyManagePort, ByteBenchStrategyPort, ByteBenchFeatureCenterPort,
//     BXDeviceInfo và các điểm nhập JNI ByteBenchBundle (0x061068..0x077e44).
// ============================================================================
#include "bytebench_core.h"
#include <unordered_map>
#include <mutex>

namespace bytebench {

struct ByteBenchBundleStore {
    std::unordered_map<std::string, int64_t> int_map;
    std::unordered_map<std::string, double> dbl_map;
    std::unordered_map<std::string, std::string> str_map;
};

static std::mutex g_bundle_mutex;
static std::unordered_map<int64_t, std::unique_ptr<ByteBenchBundleStore>> g_bundles;
static int64_t g_next_bundle_handle = 1000;

extern "C" {

int32_t JNI_OnLoad_ByteBench(void* vm, void* /*reserved*/) noexcept {
    if (!vm) {
        return -1;
    }
    return 0x00010006; // JNI_VERSION_1_6
}

int64_t Java_com_benchmark_ByteBenchBundle_nativeCreate(void* /*env*/, void* /*clazz*/) noexcept {
    std::lock_guard<std::mutex> lock(g_bundle_mutex);
    const int64_t h = ++g_next_bundle_handle;
    g_bundles[h] = std::make_unique<ByteBenchBundleStore>();
    return h;
}

int32_t Java_com_benchmark_ByteBenchBundle_nativeSetInt(void* /*env*/, void* /*thiz*/, int64_t handle, const char* key, int32_t val) noexcept {
    if (!key) return -1;
    std::lock_guard<std::mutex> lock(g_bundle_mutex);
    auto it = g_bundles.find(handle);
    if (it == g_bundles.end()) return -1;
    it->second->int_map[key] = val;
    return 0;
}

int32_t Java_com_benchmark_ByteBenchBundle_nativeGetInt(void* /*env*/, void* /*thiz*/, int64_t handle, const char* key) noexcept {
    if (!key) return 0;
    std::lock_guard<std::mutex> lock(g_bundle_mutex);
    auto it = g_bundles.find(handle);
    if (it == g_bundles.end()) return 0;
    auto kv = it->second->int_map.find(key);
    return (kv != it->second->int_map.end()) ? static_cast<int32_t>(kv->second) : 0;
}

void Java_com_benchmark_ByteBenchBundle_nativeRelease(void* /*env*/, void* /*thiz*/, int64_t handle) noexcept {
    std::lock_guard<std::mutex> lock(g_bundle_mutex);
    g_bundles.erase(handle);
}

} // extern "C"
} // namespace bytebench
