/**
 * @file napi_quickjs_backend.h
 * @brief QuickJS / LepusNG Node-API Backend (js_native_api_QuickJS.cc)
 *        Backend Node-API cho QuickJS / LepusNG (js_native_api_QuickJS.cc)
 *
 * Binary Source Path (.rodata 0x00dbe1):
 *   "/ws/228/bytebus/repositories/64f55d36a1934e8a59474a720b2d591d/"
 *   "b01c65cec201ce6e47a1f549784d4463/oss/src/napi/quickjs/js_native_api_QuickJS.cc"
 *
 * Binary Addresses in libnapi.so (.text 0x01c1a0..0x027600):
 *   - napi_attach_quickjs            : 0x01c1a0 (1,812 bytes)
 *   - qjsimpl N-API 78 handlers      : 0x01c8b4..0x02741c
 *   - napi_detach_quickjs            : 0x027420 (60 bytes)
 *   - napi_get_env_context_quickjs   : 0x02745c (12 bytes)
 *   - napi_js_value_to_quickjs_value : 0x027468 (172 bytes)
 *   - napi_quickjs_value_to_js_value : 0x027514 (84 bytes)
 *   - napi_module_register_xx        : 0x027568 (56 bytes)
 *   - napi_find_module               : 0x0275a0 (100 bytes)
 */

#pragma once

#include "napi_types.h"

extern "C" {

void napi_attach_quickjs(napi_env env, LEPUSContext* ctx);
void napi_detach_quickjs(napi_env env);
LEPUSContext* napi_get_env_context_quickjs(napi_env env);
LEPUSValue napi_js_value_to_quickjs_value(napi_env env, napi_value val);
napi_value napi_quickjs_value_to_js_value(napi_env env, LEPUSValue val);
void napi_module_register_xx(napi_module_qjs* mod);
napi_module_qjs* napi_find_module(const char* name);

} // extern "C"
