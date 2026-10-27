/**
 * @file napi_pseudocode.cpp
 * @brief Clean-Room C++17 End-to-End Integration & Self-Test Harness for libnapi.so
 *        Khung tích hợp và tự kiểm thử đầu-cuối C++17 sạch cho libnapi.so
 */

#include "napi_interface.h"

namespace primjs::napi::selftest {

/**
 * @brief Executes an end-to-end verification of napi_env__, QuickJS N-API, Napi::*, and JavaOnlyMap/Array
 *        Thực thi kiểm증 đầu-cuối cho napi_env__, QuickJS N-API, Napi::* và JavaOnlyMap/Array
 */
bool VerifyLibNapiSelfTest() {
    napi_env env = napi_new_env();
    if (!env || !env->state || !env->state->cleanup_hooks) {
        return false;
    }

    napi_runtime_configuration cfg = napi_create_runtime_configuration();
    napi_runtime_config_worker_stack_size(cfg, 256 * 1024);
    napi_attach_runtime_with_configuration(env, cfg);
    napi_delete_runtime_configuration(cfg);

    napi_attach_quickjs(env, reinterpret_cast<LEPUSContext*>(0x1234));

    Napi::Env cpp_env(env);
    Napi::HandleScope scope(cpp_env);

    Napi::Object obj = Napi::Object::New(env);
    obj.Set("answer", Napi::Number::New(env, 42.0));
    obj.Set("title", Napi::String::New(env, "NextAI OpenCut N-API"));

    Napi::Float64Array f64 = Napi::Float64Array::New(env, 4);
    if (f64.ElementSize() != 8 || f64.ByteLength() != 32) {
        napi_detach_quickjs(env);
        napi_detach_runtime(env);
        napi_free_env(env);
        return false;
    }

    auto jmap = vmsdk::general::android::createJavaOnlyMapFromJsObject(obj, cpp_env);
    bool ok = (jmap && jmap->Size() == 2);

    napi_detach_quickjs(env);
    napi_detach_runtime(env);
    napi_free_env(env);
    return ok;
}

} // namespace primjs::napi::selftest
