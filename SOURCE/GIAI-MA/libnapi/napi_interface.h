/**
 * @file napi_interface.h
 * @brief Master Public Interface Header for Clean-Room Reconstructed libnapi.so
 *        Header giao diện công khai tổng thể cho thư viện tái dựng sạch libnapi.so
 *
 * Includes all 4 clean-room subsystems of ByteDance VMSDK / PrimJS / LepusNG Node-API:
 *   1. napi_types.h           - Binary ABI structs (napi_env__ 0x430 B, qjsimpl::Context 0x450 B)
 *   2. napi_env_runtime.h     - Environment lifecycle, CleanupHookTable, ThreadSafeFunction & CodeCache
 *   3. napi_quickjs_backend.h - 78 QuickJS/LepusNG N-API handlers, NaN-boxing & Module spinlock registry
 *   4. napi_cpp_wrapper.h     - 217 Napi::* C++ object model methods & TypedArray::ElementSize table
 *   5. napi_android_jni.h     - vmsdk::general::android (JavaOnlyArray, JavaOnlyMap, JNIHelper), icu & JNI_OnLoad
 */

#pragma once

#include "napi_types.h"
#include "napi_env_runtime.h"
#include "napi_quickjs_backend.h"
#include "napi_cpp_wrapper.h"
#include "napi_android_jni.h"
