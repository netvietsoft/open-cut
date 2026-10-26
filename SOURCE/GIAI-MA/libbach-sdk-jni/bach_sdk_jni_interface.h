/**
 * @file bach_sdk_jni_interface.h
 * @brief Master Public Interface & All 17 Exported JNI Symbols for libbach-sdk-jni.so.
 *        Giao diện công khai tổng hợp & Toàn bộ 17 biểu tượng JNI xuất khẩu của libbach-sdk-jni.so.
 *
 * Target Binary / Nhị phân mục tiêu:
 *   - File: libbach-sdk-jni.so (117,112 bytes)
 *   - SHA-256: 6330cb09b6721ef41639c6ed472b4d60e3b81a9f03c699f5d8c1cbefe5804929
 *   - Exported Symbols in .dynsym: 17 FUNC symbols ([093]..[112]) + 3 ABS symbols (_edata, __bss_start, _end)
 */

#ifndef NEXTAI_OPENCUT_BACH_SDK_JNI_INTERFACE_H_
#define NEXTAI_OPENCUT_BACH_SDK_JNI_INTERFACE_H_

#include "bach_algorithm_system_jni.h"
#include "bach_object_converter.h"
#include "bach_resource_finder_jni.h"
#include "bach_sdk_jni_types.h"

extern "C" {

// [093] 0x003c8c (SZ=236): BachAlgorithmSystem.nativeSetEnable
int32_t Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeSetEnable(
    void* env, void* thiz, int64_t system_ptr, const char* algorithm_name, uint8_t enable);

// [094] 0x00f61c (SZ=144): EPResourceFinder.nativeCreate
int64_t Java_com_bytedance_byted_1bach_1sdk_finder_EPResourceFinder_nativeCreate(
    void* env, void* thiz, int64_t bef_effect_resource_finder_handle);

// [095] 0x0039c4 (SZ=568): BachAlgorithmSystem.nativeCreate
int64_t Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeCreate(
    void* env,
    void* thiz,
    int32_t finder_type,
    int64_t resource_finder_ptr,
    const char* application_name,
    const char* device_name);

// [096] 0x005c14 (SZ=1528): BachAlgorithmSystem.nativeGetResult
void* Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeGetResult(
    void* env, void* thiz, int64_t system_ptr, const char* algorithm_name, int32_t index);

// [097] 0x004b1c (SZ=1600): BachAlgorithmSystem.nativeSetStringParams
int32_t Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeSetStringParams(
    void* env,
    void* thiz,
    int64_t system_ptr,
    const char* algorithm_name,
    const std::unordered_map<std::string, std::string>* params);

// [099] 0x00519c (SZ=2552): BachAlgorithmSystem.nativeExec
int32_t Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeExec(
    void* env,
    void* thiz,
    int64_t system_ptr,
    int32_t input_type,
    int32_t width,
    int32_t height,
    int32_t android_bitmap_format,
    const uint8_t* pixels,
    size_t pixel_byte_count);

// [100] 0x00f224 (SZ=8): DownloadableResourceFinder.nativeDestroy (alias with [102])
void Java_com_bytedance_byted_1bach_1sdk_finder_DownloadableResourceFinder_nativeDestroy(
    void* env, void* thiz, int64_t finder_ptr);

// [102] 0x00f224 (SZ=8): EPResourceFinder.nativeDestroy (alias with [100])
void Java_com_bytedance_byted_1bach_1sdk_finder_EPResourceFinder_nativeDestroy(
    void* env, void* thiz, int64_t finder_ptr);

// [103] 0x0102b0 (SZ=136): JNI_OnLoad
int32_t JNI_OnLoad(void* vm, void* reserved);

// [104] 0x00515c (SZ=64): BachAlgorithmSystem.nativeDestroy
int32_t Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeDestroy(
    void* env, void* thiz, int64_t system_ptr);

// [105] 0x0044e4 (SZ=1436): BachAlgorithmSystem.nativeSetFloatParams
int32_t Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeSetFloatParams(
    void* env,
    void* thiz,
    int64_t system_ptr,
    const char* algorithm_name,
    const std::unordered_map<std::string, float>* params);

// [106] 0x003d78 (SZ=1432): BachAlgorithmSystem.nativeSetIntParams
int32_t Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeSetIntParams(
    void* env,
    void* thiz,
    int64_t system_ptr,
    const char* algorithm_name,
    const std::unordered_map<std::string, int64_t>* params);

// [108] 0x00edd0 (SZ=956): DownloadableResourceFinder.nativeCreate
int64_t Java_com_bytedance_byted_1bach_1sdk_finder_DownloadableResourceFinder_nativeCreate(
    void* env,
    void* thiz,
    const com::bytedance::bach_sdk::Bach::DownloadableResourceFinderConfig* config,
    const char* model_dir);

// [109] 0x003bfc (SZ=144): BachAlgorithmSystem.nativeInitGraph
int32_t Java_com_bytedance_byted_1bach_1sdk_BachAlgorithmSystem_nativeInitGraph(
    void* env, void* thiz, int64_t system_ptr, const char* config_path);

// [110] 0x00eb38 (SZ=508): BachBitmapHandle.nativeGet
void* Java_com_bytedance_byted_1bach_1sdk_buffer_BachBitmapHandle_nativeGet(
    void* env, void* thiz, int64_t bitmap_handle_ptr);

// [111] 0x00f22c (SZ=660): DownloadableResourceFinder.nativeDownloadModels
void Java_com_bytedance_byted_1bach_1sdk_finder_DownloadableResourceFinder_nativeDownloadModels(
    void* env,
    void* thiz,
    int64_t finder_ptr,
    const std::unordered_map<std::string, std::vector<std::string>>* requirements,
    com::bytedance::bach_sdk::Bach::ModelDownloadListener* listener);

// [112] 0x00f55c (SZ=192): ModelDownloadListener.deleteNativeObject
void Java_com_bytedance_byted_1bach_1sdk_finder_ModelDownloadListener_deleteNativeObject(
    void* env, void* thiz, int64_t listener_ptr);

} // extern "C"

#endif // NEXTAI_OPENCUT_BACH_SDK_JNI_INTERFACE_H_
