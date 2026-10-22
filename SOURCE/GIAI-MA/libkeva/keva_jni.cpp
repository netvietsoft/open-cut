/**
 * @file keva_jni.cpp
 * @brief ByteDance Keva Native JNI Implementation.
 *        Hiện thực mã nguồn C++ JNI lưu trữ Keva cho ByteDance.
 *
 * Cleanroom reverse-engineered from libkeva.so (ARM64-v8a).
 * Matches RegisterNatives table at 0x38000 and JNI_OnLoad at 0x13c50.
 */

#include "keva_jni.h"
#include "keva_repo.h"
#include <string>
#include <vector>

using namespace nextai::opencut::keva;

namespace {

std::string jstringToString(JNIEnv* env, jstring jstr) {
    if (!env || !jstr) return "";
    const char* utf = env->GetStringUTFChars(jstr, nullptr);
    if (!utf) return "";
    std::string res(utf);
    env->ReleaseStringUTFChars(jstr, utf);
    return res;
}

jstring stringToJstring(JNIEnv* env, const std::string& str) {
    if (!env) return nullptr;
    return env->NewStringUTF(str.c_str());
}

} // namespace

extern "C" {

JNIEXPORT jlong JNICALL Java_com_bytedance_keva_KevaImpl_loadRepo(
    JNIEnv* env, jclass clazz, jstring name, jint mode, jboolean multiProcess
) {
    std::string repoName = jstringToString(env, name);
    auto repo = std::make_shared<KevaRepo>(repoName, "", mode, multiProcess != 0);
    repo->initialize();
    return KevaRepoManager::getInstance().registerRepo(repo);
}

JNIEXPORT jlong JNICALL Java_com_bytedance_keva_KevaImpl_loadRepoWithPath(
    JNIEnv* env, jclass clazz, jstring name, jstring path, jint mode
) {
    std::string repoName = jstringToString(env, name);
    std::string repoPath = jstringToString(env, path);
    auto repo = std::make_shared<KevaRepo>(repoName, repoPath, mode, false);
    repo->initialize();
    return KevaRepoManager::getInstance().registerRepo(repo);
}

JNIEXPORT void JNICALL Java_com_bytedance_keva_KevaImpl_initialize(
    JNIEnv* env, jclass clazz, jstring path
) {
    // Global Keva initialization
}

JNIEXPORT jboolean JNICALL Java_com_bytedance_keva_KevaImpl_delete(
    JNIEnv* env, jclass clazz, jstring name
) {
    std::string repoName = jstringToString(env, name);
    KevaRepoManager::getInstance().deleteRepo(repoName);
    return JNI_TRUE;
}

JNIEXPORT void JNICALL Java_com_bytedance_keva_KevaImpl_clear(
    JNIEnv* env, jclass clazz, jlong handle
) {
    auto repo = KevaRepoManager::getInstance().getRepo(handle);
    if (repo) {
        repo->clear();
    }
}

JNIEXPORT void JNICALL Java_com_bytedance_keva_KevaImpl_dump(
    JNIEnv* env, jclass clazz, jlong handle
) {
    auto repo = KevaRepoManager::getInstance().getRepo(handle);
    if (repo) {
        repo->dump();
    }
}

JNIEXPORT void JNICALL Java_com_bytedance_keva_KevaImpl_checkReportException(
    JNIEnv* env, jclass clazz, jlong handle
) {
    // Exception check
}

JNIEXPORT jlong JNICALL Java_com_bytedance_keva_KevaImpl_storeInt(
    JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset, jint val
) {
    auto repo = KevaRepoManager::getInstance().getRepo(handle);
    if (repo) {
        return repo->storeInt(jstringToString(env, key), val);
    }
    return 0;
}

JNIEXPORT jlong JNICALL Java_com_bytedance_keva_KevaImpl_storeBoolean(
    JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset, jboolean val
) {
    auto repo = KevaRepoManager::getInstance().getRepo(handle);
    if (repo) {
        return repo->storeBoolean(jstringToString(env, key), val != 0);
    }
    return 0;
}

JNIEXPORT jlong JNICALL Java_com_bytedance_keva_KevaImpl_storeString(
    JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset, jstring val
) {
    auto repo = KevaRepoManager::getInstance().getRepo(handle);
    if (repo) {
        return repo->storeString(jstringToString(env, key), jstringToString(env, val));
    }
    return 0;
}

JNIEXPORT jlong JNICALL Java_com_bytedance_keva_KevaImpl_storeFloat(
    JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset, jfloat val
) {
    auto repo = KevaRepoManager::getInstance().getRepo(handle);
    if (repo) {
        return repo->storeFloat(jstringToString(env, key), val);
    }
    return 0;
}

JNIEXPORT jlong JNICALL Java_com_bytedance_keva_KevaImpl_storeLong(
    JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset, jlong val
) {
    auto repo = KevaRepoManager::getInstance().getRepo(handle);
    if (repo) {
        return repo->storeLong(jstringToString(env, key), val);
    }
    return 0;
}

JNIEXPORT jlong JNICALL Java_com_bytedance_keva_KevaImpl_storeDouble(
    JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset, jdouble val
) {
    auto repo = KevaRepoManager::getInstance().getRepo(handle);
    if (repo) {
        return repo->storeDouble(jstringToString(env, key), val);
    }
    return 0;
}

JNIEXPORT jlong JNICALL Java_com_bytedance_keva_KevaImpl_storeBytes(
    JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset, jbyteArray bytes, jint len
) {
    auto repo = KevaRepoManager::getInstance().getRepo(handle);
    if (repo && bytes && len > 0) {
        std::vector<uint8_t> buf(len);
#if defined(__ANDROID__) || defined(__linux__)
        env->GetByteArrayRegion(bytes, 0, len, reinterpret_cast<jbyte*>(buf.data()));
#endif
        return repo->storeBytes(jstringToString(env, key), buf.data(), buf.size());
    }
    return 0;
}

JNIEXPORT jlong JNICALL Java_com_bytedance_keva_KevaImpl_storeStringArray(
    JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset, jobjectArray array, jint len
) {
    auto repo = KevaRepoManager::getInstance().getRepo(handle);
    if (repo && array && len > 0) {
        std::vector<std::string> strArr;
        strArr.reserve(len);
#if defined(__ANDROID__) || defined(__linux__)
        for (jsize i = 0; i < len; ++i) {
            jstring js = static_cast<jstring>(env->GetObjectArrayElement(array, i));
            strArr.push_back(jstringToString(env, js));
        }
#endif
        return repo->storeStringArray(jstringToString(env, key), strArr);
    }
    return 0;
}

JNIEXPORT jint JNICALL Java_com_bytedance_keva_KevaImpl_fetchInt(
    JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset, jint defaultVal
) {
    auto repo = KevaRepoManager::getInstance().getRepo(handle);
    if (repo) {
        return repo->fetchInt(jstringToString(env, key), defaultVal);
    }
    return defaultVal;
}

JNIEXPORT jboolean JNICALL Java_com_bytedance_keva_KevaImpl_fetchBoolean(
    JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset, jboolean defaultVal
) {
    auto repo = KevaRepoManager::getInstance().getRepo(handle);
    if (repo) {
        return repo->fetchBoolean(jstringToString(env, key), defaultVal != 0) ? JNI_TRUE : JNI_FALSE;
    }
    return defaultVal;
}

JNIEXPORT jlong JNICALL Java_com_bytedance_keva_KevaImpl_fetchLong(
    JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset, jlong defaultVal
) {
    auto repo = KevaRepoManager::getInstance().getRepo(handle);
    if (repo) {
        return repo->fetchLong(jstringToString(env, key), defaultVal);
    }
    return defaultVal;
}

JNIEXPORT jfloat JNICALL Java_com_bytedance_keva_KevaImpl_fetchFloat(
    JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset, jfloat defaultVal
) {
    auto repo = KevaRepoManager::getInstance().getRepo(handle);
    if (repo) {
        return repo->fetchFloat(jstringToString(env, key), defaultVal);
    }
    return defaultVal;
}

JNIEXPORT jdouble JNICALL Java_com_bytedance_keva_KevaImpl_fetchDouble(
    JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset, jdouble defaultVal
) {
    auto repo = KevaRepoManager::getInstance().getRepo(handle);
    if (repo) {
        return repo->fetchDouble(jstringToString(env, key), defaultVal);
    }
    return defaultVal;
}

JNIEXPORT jstring JNICALL Java_com_bytedance_keva_KevaImpl_fetchString(
    JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset, jstring defaultVal
) {
    auto repo = KevaRepoManager::getInstance().getRepo(handle);
    std::string defStr = jstringToString(env, defaultVal);
    if (repo) {
        std::string res = repo->fetchString(jstringToString(env, key), defStr);
        return stringToJstring(env, res);
    }
    return defaultVal;
}

JNIEXPORT jbyteArray JNICALL Java_com_bytedance_keva_KevaImpl_fetchBytes(
    JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset, jbyteArray defaultBytes, jint len
) {
    auto repo = KevaRepoManager::getInstance().getRepo(handle);
    if (repo) {
        std::vector<uint8_t> bytes = repo->fetchBytes(jstringToString(env, key), nullptr, 0);
        if (!bytes.empty()) {
#if defined(__ANDROID__) || defined(__linux__)
            jbyteArray res = env->NewByteArray(static_cast<jsize>(bytes.size()));
            env->SetByteArrayRegion(res, 0, static_cast<jsize>(bytes.size()), reinterpret_cast<const jbyte*>(bytes.data()));
            return res;
#endif
        }
    }
    return defaultBytes;
}

JNIEXPORT jobjectArray JNICALL Java_com_bytedance_keva_KevaImpl_fetchStringArray(
    JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset, jobjectArray defaultArray, jint len
) {
    auto repo = KevaRepoManager::getInstance().getRepo(handle);
    if (repo) {
        std::vector<std::string> arr = repo->fetchStringArray(jstringToString(env, key), {});
        if (!arr.empty()) {
#if defined(__ANDROID__) || defined(__linux__)
            jclass stringClass = env->FindClass("java/lang/String");
            jobjectArray res = env->NewObjectArray(static_cast<jsize>(arr.size()), stringClass, nullptr);
            for (size_t i = 0; i < arr.size(); ++i) {
                jstring js = env->NewStringUTF(arr[i].c_str());
                env->SetObjectArrayElement(res, static_cast<jsize>(i), js);
            }
            return res;
#endif
        }
    }
    return defaultArray;
}

JNIEXPORT void JNICALL Java_com_bytedance_keva_KevaImpl_erase(
    JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset
) {
    auto repo = KevaRepoManager::getInstance().getRepo(handle);
    if (repo) {
        repo->erase(jstringToString(env, key));
    }
}

JNIEXPORT void JNICALL Java_com_bytedance_keva_KevaImpl_rebuildValueMap(
    JNIEnv* env, jclass clazz, jlong handle
) {
    auto repo = KevaRepoManager::getInstance().getRepo(handle);
    if (repo) {
        repo->rebuildValueMap();
    }
}

JNIEXPORT jboolean JNICALL Java_com_bytedance_keva_KevaImpl_contains(
    JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset
) {
    auto repo = KevaRepoManager::getInstance().getRepo(handle);
    if (repo) {
        return repo->contains(jstringToString(env, key)) ? JNI_TRUE : JNI_FALSE;
    }
    return JNI_FALSE;
}

JNIEXPORT void JNICALL Java_com_bytedance_keva_KevaImpl_eraseUnusedChunk(
    JNIEnv* env, jclass clazz, jlong handle, jlong offset
) {
    auto repo = KevaRepoManager::getInstance().getRepo(handle);
    if (repo) {
        repo->eraseUnusedChunk();
    }
}

JNIEXPORT jint JNICALL Java_com_bytedance_keva_KevaImpl_protectPortingInterProcess(
    JNIEnv* env, jclass clazz, jstring path, jboolean enable, jint flag
) {
    return 0;
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM vm, void* reserved) {
    return JNI_VERSION_1_6;
}

} // extern "C"
