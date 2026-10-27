/**
 * @file napi_env_runtime.h
 * @brief Node-API Environment Lifecycle, Cleanup Hooks, Runtime Config, ThreadSafeFunction & CodeCache
 *        Vòng đời môi trường Node-API, Hook dọn dẹp, Cấu hình Runtime, Hàm an toàn luồng & Bộ nhớ đệm mã
 *
 * Binary Addresses in libnapi.so (.text 0x014000..0x01c19f):
 *   - napi_get_last_error_info_impl              : 0x01403c
 *   - napi_get_instance_data_impl                : 0x01405c
 *   - napi_add_env_cleanup_hook_impl             : 0x0144c0
 *   - napi_set_instance_data_impl                : 0x0146dc
 *   - napi_remove_env_cleanup_hook_impl          : 0x014704
 *   - napi_new_env                               : 0x015e28 (164 bytes)
 *   - napi_free_env                              : 0x015ecc (516 bytes)
 *   - napi_setup_loader                          : 0x017250 (260 bytes)
 *   - napi_runtime_get_threadsafe_function_context: 0x017354 (16 bytes)
 *   - napi_runtime_call_threadsafe_function      : 0x017364 (1,460 bytes)
 *   - napi_runtime_delete_threadsafe_function    : 0x018050 (148 bytes)
 *   - napi_create_runtime_configuration          : 0x018368 (36 bytes)
 *   - napi_delete_runtime_configuration          : 0x01838c (12 bytes)
 *   - napi_runtime_config_foreground_handler     : 0x018398 (8 bytes)
 *   - napi_runtime_config_uncaught_handler       : 0x0183a0 (8 bytes)
 *   - napi_runtime_config_worker_handler         : 0x0183a8 (12 bytes)
 *   - napi_runtime_config_worker_stack_size      : 0x0183b4 (8 bytes)
 *   - napi_attach_runtime_with_configuration     : 0x0183bc (300 bytes)
 *   - napi_attach_runtime                        : 0x01b48c (308 bytes)
 *   - napi_detach_runtime                        : 0x01b5c0 (232 bytes)
 */

#pragma once

#include "napi_types.h"
#include <condition_variable>
#include <deque>
#include <future>
#include <thread>

extern "C" {

// Exported C APIs / Các API C xuất khẩu
napi_env napi_new_env();
void napi_free_env(napi_env env);
void napi_setup_loader(napi_env env, const char* name);

napi_status napi_runtime_get_threadsafe_function_context(napi_threadsafe_function func, void** result);
napi_status napi_runtime_call_threadsafe_function(
    napi_threadsafe_function func,
    void* data,
    napi_threadsafe_function_call_mode is_blocking);
void napi_runtime_delete_threadsafe_function(napi_threadsafe_function func);

napi_runtime_configuration napi_create_runtime_configuration();
void napi_delete_runtime_configuration(napi_runtime_configuration config);
void napi_runtime_config_foreground_handler(napi_runtime_configuration config, void* fn, void* ctx);
void napi_runtime_config_uncaught_handler(napi_runtime_configuration config, void* fn, void* ctx);
void napi_runtime_config_worker_handler(
    napi_runtime_configuration config,
    void* fn,
    void* ctx,
    void* aux1,
    void* aux2);
void napi_runtime_config_worker_stack_size(napi_runtime_configuration config, size_t stack_size);
void napi_attach_runtime_with_configuration(napi_env env, napi_runtime_configuration config);
void napi_attach_runtime(
    napi_env env,
    void* foreground_fn,
    void* foreground_ctx,
    void* uncaught_fn,
    void* uncaught_ctx);
void napi_detach_runtime(napi_env env);

} // extern "C"

namespace primjs::napi::runtime {

/**
 * @brief Error status checking helper (sub_27670 @ 0x027670..0x0278d0)
 *        Hàm phụ trợ kiểm tra mã trạng thái lỗi (sub_27670 @ 0x027670..0x0278d0)
 */
void CheckNapiStatus(napi_env env, napi_status status, const char* call_site_msg);

} // namespace primjs::napi::runtime
